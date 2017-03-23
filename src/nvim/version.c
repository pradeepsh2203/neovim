/// @file version.c
///
/// Nvim was forked from Vim 7.4.160.
/// Vim originated from Stevie version 3.6 (Fish disk 217) by GRWalter (Fred).

#include <inttypes.h>
#include <assert.h>
#include <limits.h>

#include "nvim/api/private/helpers.h"
#include "nvim/vim.h"
#include "nvim/ascii.h"
#include "nvim/iconv.h"
#include "nvim/version.h"
#include "nvim/charset.h"
#include "nvim/macros.h"
#include "nvim/memline.h"
#include "nvim/memory.h"
#include "nvim/message.h"
#include "nvim/screen.h"
#include "nvim/strings.h"

// version info generated by the build system
#include "auto/versiondef.h"

// for ":version", ":intro", and "nvim --version"
#ifndef NVIM_VERSION_MEDIUM
#define NVIM_VERSION_MEDIUM "v" STR(NVIM_VERSION_MAJOR)\
  "." STR(NVIM_VERSION_MINOR) "." STR(NVIM_VERSION_PATCH)\
  NVIM_VERSION_PRERELEASE
#endif
#define NVIM_VERSION_LONG "NVIM " NVIM_VERSION_MEDIUM


char *Version = VIM_VERSION_SHORT;
char *longVersion = NVIM_VERSION_LONG;
char *version_buildtype = "Build type: " NVIM_VERSION_BUILD_TYPE;
char *version_cflags = "Compilation: " NVIM_VERSION_CFLAGS;

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "version.c.generated.h"
#endif

static char *features[] = {
#ifdef HAVE_ACL
  "+acl",
#else
  "-acl",
#endif

#if (defined(HAVE_ICONV_H) && defined(USE_ICONV)) || defined(DYNAMIC_ICONV)
# ifdef DYNAMIC_ICONV
  "+iconv/dyn",
# else
  "+iconv",
# endif
#else
  "-iconv",
#endif

#ifdef HAVE_JEMALLOC
  "+jemalloc",
#else
  "-jemalloc",
#endif

#ifdef FEAT_TUI
  "+tui",
#else
  "-tui",
#endif
  NULL
};

// clang-format off
static int included_patches[] = {
  // 2367,
  // 2366 NA
  // 2365 NA
  // 2364,
  // 2363 NA
  2362,
  // 2361 NA
  // 2360,
  // 2359 NA
  // 2358 NA
  2357,
  // 2356,
  2355,
  // 2354,
  2353,
  // 2352 NA
  // 2351 NA
  // 2350,
  2349,
  2348,
  2347,
  2346,
  // 2345 NA
  // 2344 NA
  // 2343,
  // 2342 NA
  2341,
  // 2340 NA
  2339,
  // 2338 NA
  2337,
  2336,
  2335,
  // 2334,
  2333,
  // 2332 NA
  2331,
  // 2330,
  2329,
  2328,
  // 2327 NA
  2326,
  // 2325 NA
  2324,
  2323,
  2322,
  2321,
  // 2320,
  // 2319 NA
  // 2318,
  2317,
  // 2316 NA
  2315,
  2314,
  2313,
  2312,
  // 2311 NA
  // 2310 NA
  2309,
  // 2308 NA
  2307,
  // 2306,
  2305,
  // 2304 NA
  2303,
  // 2302 NA
  // 2301 NA
  2300,
  2299,
  // 2298 NA
  // 2297 NA
  2296,
  2295,
  2294,
  2293,
  2292,
  2291,
  // 2290 NA
  // 2289 NA
  // 2288 NA
  // 2287 NA
  // 2286 NA
  // 2285 NA
  2284,
  2283,
  // 2282 NA
  // 2281 NA
  2280,
  2279,
  // 2278 NA
  2277,
  // 2276,
  2275,
  2274,
  2273,
  2272,
  // 2271 NA
  // 2270 NA
  // 2269,
  // 2268,
  // 2267 NA
  2266,
  2265,
  2264,
  // 2263,
  // 2262 NA
  // 2261 NA
  // 2260 NA
  // 2259,
  // 2258 NA
  // 2257 NA
  2256,
  2255,
  // 2254 NA
  // 2253 NA
  // 2252 NA
  2251,
  // 2250,
  2249,
  2248,
  // 2247 NA
  // 2246,
  // 2245,
  // 2244,
  // 2243 NA
  // 2242,
  // 2241,
  // 2240,
  // 2239,
  // 2238 NA
  2237,
  // 2236,
  2235,
  // 2234 NA
  2233,
  // 2232 NA
  // 2231,
  2230,
  // 2229,
  2228,
  2227,
  2226,
  2225,
  // 2224,
  2223,
  2222,
  2221,
  2220,
  2219,
  // 2218 NA
  2217,
  // 2216 NA
  2215,
  // 2214 NA
  2213,
  2212,
  // 2211 NA
  // 2210 NA
  // 2209,
  2208,
  // 2207 NA
  // 2206 NA
  2205,
  2204,
  // 2203 NA
  // 2202 NA
  2201,
  2200,
  // 2199 NA
  // 2198 NA
  2197,
  2196,
  // 2195 NA
  2194,
  // 2193 NA
  // 2192 NA
  // 2191 NA
  // 2190,
  // 2189,
  2188,
  2187,
  // 2186 NA
  2185,
  2184,
  2183,
  // 2182 NA
  // 2181,
  // 2180,
  // 2179,
  2178,
  2177,
  // 2176 NA
  2175,
  2174,
  // 2173,
  2172,
  // 2171,
  // 2170,
  2169,
  // 2168 NA
  // 2167 NA
  // 2166 NA
  // 2165,
  2164,
  2163,
  2162,
  2161,
  2160,
  2159,
  2158,
  // 2157 NA
  // 2156 NA
  // 2155 NA
  // 2154 NA
  // 2153 NA
  // 2152,
  2151,
  // 2150 NA
  2149,
  2148,
  2147,
  2146,
  // 2145 NA
  2144,
  2143,
  2142,
  2141,
  // 2140 NA
  2139,
  // 2138 NA
  2137,
  2136,
  2135,
  2134,
  // 2133 NA
  // 2132 NA
  // 2131 NA
  // 2130 NA
  // 2129 NA
  2128,
  2127,
  2126,
  // 2125 NA
  2124,
  2123,
  // 2122 NA
  2121,
  2120,
  2119,
  // 2118 NA
  2117,
  // 2116 NA
  // 2115 NA
  // 2114 NA
  2113,
  2112,
  // 2111 NA
  2110,
  2109,
  // 2108 NA
  2107,
  2106,
  // 2105 NA
  // 2104,
  2103,
  // 2102 NA
  2101,
  2100,
  2099,
  2098,
  2097,
  2096,
  2095,
  // 2094 NA
  // 2093 NA
  // 2092 NA
  // 2091 NA
  2090,
  // 2089 NA
  2088,
  2087,
  2086,
  2085,
  2084,
  // 2083 NA
  2082,
  2081,
  // 2080 NA
  // 2079 NA
  // 2078 NA
  2077,
  2076,
  2075,
  2074,
  // 2073 NA
  2072,
  2071,
  // 2070 NA
  2069,
  2068,
  2067,
  2066,
  2065,
  2064,
  // 2063 NA
  2062,
  2061,
  // 2060 NA
  // 2059 NA
  // 2058 NA
  // 2057 NA
  // 2056 NA
  // 2055 NA
  // 2054 NA
  // 2053 NA
  // 2052 NA
  2051,
  2050,
  2049,
  // 2048 NA
  2047,
  2046,
  // 2045 NA
  2044,
  2043,
  // 2042 NA
  // 2041 NA
  // 2040 NA
  // 2039 NA
  // 2038 NA
  // 2037 NA
  2036,
  // 2035 NA
  // 2034 NA
  2033,
  // 2032 NA
  2031,
  // 2030 NA
  // 2029,
  2028,
  // 2027 NA
  // 2026 NA
  // 2025 NA
  2024,
  2023,
  2022,
  2021,
  // 2020 NA
  2019,
  2018,
  2017,
  // 2016 NA
  2015,
  2014,
  2013,
  2012,
  2011,
  2010,
  2009,
  2008,
  2007,
  2006,
  2005,
  // 2004 NA
  // 2003 NA
  2002,
  // 2001 NA
  2000,
  1999,
  // 1998 NA
  1997,
  1996,
  // 1995 NA
  1994,
  1993,
  1992,
  1991,
  1990,
  1989,
  // 1988 NA
  // 1987 NA
  // 1986,
  // 1985 NA
  1984,
  // 1983 NA
  // 1982 NA
  1981,
  1980,
  // 1979,
  // 1978,
  // 1977,
  // 1976,
  // 1975,
  // 1974 NA
  1973,
  // 1972 NA
  1971,
  1970,
  // 1969 NA
  1968,
  1967,
  1966,
  // 1965 NA
  1964,
  // 1963 NA
  1962,
  1961,
  1960,
  // 1959 NA
  // 1958 NA
  // 1957 NA
  1956,
  // 1955 NA
  1954,
  1953,
  1952,
  // 1951 NA
  1950,
  1949,
  1948,
  // 1947 NA
  // 1946 NA
  // 1945 NA
  // 1944 NA
  // 1943 NA
  // 1942 NA
  1941,
  1940,
  // 1939 NA
  // 1938 NA
  1937,
  // 1936 NA
  // 1935 NA
  // 1934 NA
  // 1933 NA
  // 1932 NA
  // 1931 NA
  // 1930 NA
  // 1929 NA
  1928,
  // 1927 NA
  // 1926 NA
  1925,
  // 1924 NA
  1923,
  // 1922 NA
  // 1921 NA
  // 1920 NA
  // 1919 NA
  // 1918 NA
  // 1917 NA
  // 1916 NA
  // 1915 NA
  // 1914 NA
  1913,
  1912,
  // 1911 NA
  1910,
  1909,
  // 1908 NA
  // 1907 NA
  // 1906 NA
  // 1905 NA
  // 1904 NA
  // 1903 NA
  // 1902 NA
  // 1901 NA
  1900,
  // 1899 NA
  1898,
  1897,
  1896,
  1895,
  1894,
  1893,
  1892,
  // 1891 NA
  // 1890 NA
  1889,
  // 1888 NA
  // 1887 NA
  // 1886 NA
  // 1885 NA
  1884,
  // 1883 NA
  1882,
  1881,
  // 1880 NA
  // 1879 NA
  // 1878 NA
  // 1877 NA
  1876,
  1875,
  // 1874 NA
  // 1873 NA
  // 1872 NA
  1871,
  // 1870 NA
  // 1869 NA
  1868,
  1867,
  1866,
  // 1865 NA
  // 1864 NA
  // 1863 NA
  // 1862 NA
  1861,
  1860,
  // 1859 NA
  // 1858 NA
  // 1857 NA
  // 1856 NA
  // 1855 NA
  // 1854 NA
  // 1853 NA
  // 1852 NA
  1851,
  // 1850 NA
  // 1849 NA
  // 1848 NA
  1847,
  // 1846 NA
  // 1845 NA
  // 1844 NA
  // 1843 NA
  1842,
  1841,
  1840,
  1839,
  1838,
  1837,
  1836,
  1835,
  1834,
  1833,
  1832,
  1831,
  // 1830 NA
  // 1829 NA
  // 1828 NA
  // 1827 NA
  // 1826 NA
  // 1825 NA
  // 1824 NA
  1823,
  // 1822 NA
  1821,
  1820,
  // 1819 NA
  1818,
  // 1817 NA
  1816,
  1815,
  // 1814 NA
  1813,
  // 1812 NA
  // 1811 NA
  // 1810 NA
  1809,
  1808,
  // 1807 NA
  1806,
  // 1805 NA
  // 1804 NA
  // 1803 NA
  1802,
  // 1801 NA
  // 1800 NA
  1799,
  // 1798 NA
  // 1797 NA
  // 1796 NA
  // 1795 NA
  // 1794 NA
  1793,
  // 1792 NA
  // 1791 NA
  // 1790 NA
  // 1789 NA
  // 1789 NA
  // 1788 NA
  // 1787 NA
  // 1786 NA
  1785,
  // 1784 NA
  1783,
  1782,
  1781,
  1780,
  1779,
  // 1778 NA
  // 1777 NA
  // 1776 NA
  // 1775 NA
  // 1774 NA
  // 1773 NA
  // 1772 NA
  // 1771 NA
  // 1770 NA
  // 1769 NA
  1768,
  // 1767 NA
  // 1766 NA
  1765,
  // 1764 NA
  1763,
  // 1762 NA
  // 1761 NA
  // 1760 NA
  1759,
  1758,
  1757,
  // 1756 NA
  1755,
  1754,
  1753,
  1752,
  1751,
  // 1750 NA
  // 1749 NA
  1748,
  // 1747 NA
  // 1746 NA
  // 1745 NA
  // 1744 NA
  // 1743 NA
  1742,
  1741,
  1740,
  1739,
  1738,
  // 1737 NA
  // 1736 NA
  1735,
  1734,
  // 1733 NA
  1732,
  // 1731 NA
  1730,
  // 1729 NA
  1728,
  1727,
  // 1726 NA
  // 1725 NA
  // 1724 NA
  1723,
  // 1722 NA
  // 1721 NA
  // 1720 NA
  1719,
  1718,
  // 1717 NA
  1716,
  1715,
  1714,
  // 1713 NA
  1712,
  1711,
  // 1710 NA
  // 1709 NA
  1708,
  1707,
  // 1706 NA
  // 1705 NA
  1704,
  1703,
  1702,
  1701,
  1700,
  1699,
  // 1698 NA
  1697,
  1696,
  1695,
  // 1694 NA
  // 1693 NA
  1692,
  1691,
  // 1690 NA
  // 1689 NA
  // 1688 NA
  // 1687 NA
  1686,
  1685,
  // 1684 NA
  // 1683 NA
  1682,
  1681,
  // 1680 NA
  1679,
  // 1678 NA
  // 1677 NA
  1676,
  1675,
  // 1674 NA
  1673,
  // 1672 NA
  1671,
  1670,
  // 1669 NA
  // 1668 NA
  // 1667 NA
  // 1666 NA
  // 1665 NA
  1664,
  1663,
  // 1662 NA
  // 1661 NA
  1660,
  // 1659 NA
  1658,
  // 1657 NA
  1656,
  // 1655 NA
  1654,
  // 1653 NA
  1652,
  // 1651 NA
  1650,
  1649,
  1648,
  1647,
  // 1646 NA
  1645,
  // 1644 NA
  1643,
  1642,
  1641,
  1640,
  1639,
  1638,
  // 1637 NA
  // 1636 NA
  // 1635 NA
  1634,
  // 1633 NA
  // 1632 NA
  // 1631 NA
  1630,
  1629,
  // 1628 NA
  // 1627 NA
  // 1626 NA
  // 1625 NA
  // 1624 NA
  // 1623 NA
  // 1622 NA
  // 1621 NA
  1620,
  1619,
  // 1618 NA
  // 1617 NA
  // 1616 NA
  // 1615 NA
  1614,
  // 1613 NA
  // 1612 NA
  // 1611 NA
  // 1610 NA
  // 1609 NA
  1608,
  1607,
  1606,
  1605,
  1604,
  1603,
  // 1602 NA
  // 1601 NA
  // 1600 NA
  // 1599 NA
  // 1598 NA
  // 1597 NA
  1596,
  // 1595 NA
  // 1594 NA
  // 1593 NA
  1592,
  1591,
  1590,
  1589,
  1588,
  // 1587 NA
  1586,
  1585,
  // 1584 NA
  // 1583 NA
  1582,
  1581,
  1580,
  // 1579 NA
  1578,
  1577,
  1576,
  // 1575 NA
  1574,
  // 1573 NA
  // 1572 NA
  1571,
  1570,
  1569,
  1568,
  1567,
  // 1566 NA
  1565,
  1564,
  1563,
  // 1562 NA
  // 1561 NA
  // 1560 NA
  1559,
  1558,
  1557,
  // 1556 NA
  // 1555 NA
  1554,
  1553,
  1552,
  1551,
  1550,
  1549,
  1548,
  1547,
  1546,
  // 1545 NA
  // 1544 NA
  // 1543 NA
  // 1542 NA
  // 1541 NA
  // 1540 NA
  // 1539 NA
  // 1538 NA
  // 1537 NA
  // 1536 NA
  1535,
  // 1534 NA
  1533,
  // 1532 NA
  // 1531 NA
  // 1530 NA
  // 1529 NA
  1528,
  // 1527 NA
  // 1526 NA
  // 1525 NA
  // 1524 NA
  // 1523 NA
  // 1522 NA
  1521,
  // 1520 NA
  // 1519 NA
  // 1518 NA
  // 1517 NA
  1516,
  // 1515 NA
  // 1514 NA
  1513,
  // 1512 NA
  1511,
  // 1510 NA
  // 1509 NA
  // 1508 NA
  // 1507 NA
  // 1506 NA
  // 1505 NA
  // 1504 NA
  // 1503 NA
  // 1502 NA
  // 1501 NA
  1500,
  1499,
  // 1498 NA
  // 1497 NA
  // 1496 NA
  // 1495 NA
  1494,
  // 1493 NA
  1492,
  1491,
  // 1490 NA
  // 1489 NA
  // 1488 NA
  // 1487 NA
  1486,
  // 1485 NA
  // 1484 NA
  // 1483 NA
  // 1482 NA
  // 1481 NA
  1480,
  1479,
  1478,
  1477,
  // 1476 NA
  // 1475 NA
  // 1474 NA
  // 1473 NA
  // 1472 NA
  // 1471 NA
  // 1470 NA
  // 1469 NA
  1468,
  // 1467 NA
  // 1466 NA
  // 1465 NA
  1464,
  // 1463 NA
  // 1462 NA
  // 1461 NA
  // 1460 NA
  // 1459 NA
  // 1458 NA
  // 1457 NA
  // 1456 NA
  // 1455 NA
  // 1454 NA
  // 1453 NA
  // 1452 NA
  // 1451 NA
  // 1450 NA
  // 1449 NA
  // 1448 NA
  // 1447 NA
  // 1446 NA
  // 1445 NA
  // 1444 NA
  // 1443 NA
  // 1442 NA
  // 1441 NA
  // 1440 NA
  // 1439 NA
  // 1438 NA
  // 1437 NA
  // 1436 NA
  // 1435 NA
  // 1434 NA
  // 1433 NA
  // 1432 NA
  // 1431 NA
  // 1430 NA
  // 1429 NA
  // 1428 NA
  // 1427 NA
  // 1426 NA
  1425,
  // 1424 NA
  // 1423 NA
  // 1422 NA
  // 1421 NA
  // 1420 NA
  // 1419 NA
  // 1418 NA
  // 1417 NA
  // 1416 NA
  // 1415 NA
  // 1414 NA
  // 1413 NA
  // 1412 NA
  // 1411 NA
  1410,
  // 1409 NA
  // 1408 NA
  // 1407 NA
  1406,
  1405,
  // 1404 NA
  // 1403 NA
  // 1402 NA
  1401,
  // 1400 NA
  // 1399 NA
  // 1398 NA
  1397,
  1396,
  // 1395 NA
  1394,
  // 1393 NA
  // 1392 NA
  // 1391 NA
  // 1390 NA
  // 1389 NA
  1388,
  // 1387 NA
  // 1386 NA
  // 1385 NA
  1384,
  // 1383 NA
  // 1382 NA
  // 1381 NA
  // 1380 NA
  // 1379 NA
  // 1378 NA
  // 1377 NA
  // 1376 NA
  // 1375 NA
  // 1374 NA
  // 1373 NA
  // 1372 NA
  // 1371 NA
  // 1370 NA
  // 1369 NA
  // 1368 NA
  // 1367 NA
  1366,
  1365,
  // 1364 NA
  // 1363 NA
  // 1362 NA
  // 1361 NA
  // 1360 NA
  // 1359 NA
  // 1358 NA
  // 1357 NA
  // 1356 NA
  // 1355 NA
  // 1354 NA
  // 1353 NA
  1352,
  // 1351 NA
  // 1350 NA
  // 1349 NA
  // 1348 NA
  1347,
  1346,
  // 1345 NA
  // 1344 NA
  // 1343 NA
  // 1342 NA
  // 1341 NA
  // 1340 NA
  // 1339 NA
  // 1338 NA
  // 1337 NA
  // 1336 NA
  // 1335 NA
  // 1334 NA
  // 1333 NA
  // 1332 NA
  // 1331 NA
  // 1330 NA
  // 1329 NA
  // 1328 NA
  // 1327 NA
  // 1326 NA
  // 1325 NA
  // 1324 NA
  // 1323 NA
  // 1322 NA
  // 1321 NA
  // 1320 NA
  // 1319 NA
  // 1318 NA
  // 1317 NA
  // 1316 NA
  // 1315 NA
  // 1314 NA
  // 1313 NA
  // 1312 NA
  // 1311 NA
  // 1310 NA
  1309,
  // 1308 NA
  // 1307 NA
  // 1306 NA
  1305,
  1304,
  // 1303 NA
  // 1302 NA
  // 1301 NA
  // 1300 NA
  // 1299 NA
  // 1298 NA
  // 1297 NA
  1296,
  // 1295 NA
  // 1294 NA
  // 1293 NA
  1292,
  // 1291 NA
  // 1290 NA
  // 1289 NA
  // 1288 NA
  // 1287 NA
  // 1286 NA
  1285,
  1284,
  // 1283 NA
  1282,
  1281,
  // 1280 NA
  // 1279 NA
  // 1278 NA
  // 1277 NA
  1276,
  // 1275 NA
  // 1274 NA
  // 1273 NA
  // 1272 NA
  1271,
  // 1270 NA
  1269,
  // 1268 NA
  1267,
  1266,
  // 1265 NA
  // 1264 NA
  // 1263 NA
  // 1262 NA
  // 1261 NA
  // 1260 NA
  1259,
  // 1258 NA
  // 1257 NA
  // 1256 NA
  // 1255 NA
  // 1254 NA
  // 1253 NA
  // 1252 NA
  // 1251 NA
  // 1250 NA
  // 1249 NA
  // 1248 NA
  // 1247 NA
  // 1246 NA
  // 1245 NA
  // 1244 NA
  // 1243 NA
  // 1242 NA
  // 1241 NA
  // 1240 NA
  // 1239 NA
  // 1238 NA
  1237,
  1236,
  // 1235 NA
  // 1234 NA
  // 1233 NA
  // 1232 NA
  // 1231 NA
  // 1230 NA
  // 1229 NA
  1228,
  // 1227 NA
  // 1226 NA
  // 1225 NA
  // 1224 NA
  1223,
  // 1222 NA
  // 1221 NA
  // 1220 NA
  // 1219 NA
  // 1218 NA
  // 1217 NA
  // 1216 NA
  // 1215 NA
  // 1214 NA
  // 1213 NA
  // 1212 NA
  // 1211 NA
  // 1210 NA
  // 1209 NA
  // 1208 NA
  // 1207 NA
  // 1206 NA
  // 1205 NA
  // 1204 NA
  // 1203 NA
  // 1202 NA
  // 1201 NA
  // 1200 NA
  // 1199 NA
  // 1198 NA
  // 1197 NA
  // 1196 NA
  // 1195 NA
  // 1194 NA
  // 1193 NA
  // 1192 NA
  // 1191 NA
  // 1190 NA
  // 1189 NA
  // 1188 NA
  // 1187 NA
  // 1186 NA
  // 1185 NA
  // 1184 NA
  // 1183 NA
  // 1182 NA
  1181,
  1180,
  1179,
  1178,
  // 1177 NA
  // 1176 NA
  // 1175 NA
  // 1174 NA
  1173,
  // 1172 NA
  // 1171 NA
  // 1170 NA
  // 1169 NA
  1168,
  1167,
  1166,
  // 1165 NA
  1164,
  1163,
  // 1162 NA
  1161,
  1160,
  // 1159 NA
  // 1158 NA
  1157,
  // 1156 NA
  // 1155 NA
  // 1154 NA
  1153,
  // 1152 NA
  1151,
  1150,
  1149,
  // 1148 NA
  1147,
  // 1146 NA
  // 1145 NA
  1144,
  1143,
  1142,
  1141,
  1140,
  // 1139 NA
  // 1138 NA
  1137,
  1136,
  // 1135 NA
  // 1134 NA
  // 1133 NA
  1132,
  // 1131 NA
  // 1130 NA
  // 1129 NA
  // 1128 NA
  // 1127 NA
  1126,
  // 1125 NA
  // 1124 NA
  1123,
  // 1122 NA
  1121,
  1120,
  1119,
  1118,
  1117,
  1116,
  // 1115 NA
  1114,
  1113,
  1112,
  1111,
  1110,
  // 1109 NA
  1108,
  1107,
  // 1106 NA
  1105,
  // 1104 NA
  // 1103 NA
  1102,
  1101,
  // 1100 NA
  // 1099 NA
  // 1098 NA
  // 1097 NA
  1096,
  // 1095 NA
  1094,
  1093,
  1092,
  1091,
  1090,
  1089,
  1088,
  1087,
  1086,
  1085,
  1084,
  // 1083 NA
  // 1082 NA
  1081,
  // 1080 NA
  // 1079 NA
  // 1078 NA
  // 1077 NA
  1076,
  1075,
  // 1074 NA
  // 1073 NA
  1072,
  1071,
  // 1070 NA
  // 1069 NA
  1068,
  // 1067 NA
  // 1066 NA
  1065,
  1064,
  // 1063 NA
  // 1062 NA
  1061,
  // 1060 NA
  1059,
  // 1058 NA
  1057,
  1056,
  1055,
  1054,
  1053,
  1052,
  1051,
  1050,
  1049,
  1048,
  1047,
  1046,
  // 1045 NA
  // 1044 NA
  // 1043 NA
  1042,
  1041,
  // 1040 NA
  // 1039 NA
  // 1038 NA
  1037,
  1036,
  1035,
  1034,
  // 1033 NA
  1032,
  // 1031 NA
  1030,
  1029,
  // 1028 NA
  1027,
  // 1026 NA
  // 1025 NA
  // 1024 NA
  // 1023 NA
  // 1022 NA
  // 1021 NA
  // 1020 NA
  // 1019 NA
  1018,
  1017,
  // 1016 NA
  1015,
  // 1014 NA
  1013,
  // 1012 NA
  // 1011 NA
  // 1010 NA
  // 1009 NA
  // 1008 NA
  1007,
  1006,
  // 1005 NA
  // 1004 NA
  // 1003 NA
  // 1002 NA
  1001,
  1000,
  // 999 NA
  998,
  // 997 NA
  // 996 NA
  // 995 NA
  // 994 NA
  // 993 NA
  // 992 NA
  991,
  // 990 NA
  989,
  // 988 NA
  // 987 NA
  // 986 NA
  // 985 NA
  984,
  // 983 NA
  // 982 NA
  981,
  980,
  // 979 NA
  978,
  977,
  // 976 NA
  975,
  974,
  973,
  972,
  // 971 NA
  // 970 NA
  // 969 NA
  // 968 NA
  // 967 NA
  // 966 NA
  // 965 NA
  // 964 NA
  963,
  // 962 NA
  961,
  // 960 NA
  // 959 NA
  958,
  957,
  // 956 NA
  955,
  // 954 NA
  953,
  952,
  951,
  950,
  949,
  // 948 NA
  // 947 NA
  946,
  945,
  944,
  // 943 NA
  942,
  941,
  // 940 NA
  939,
  // 938 NA
  937,
  936,
  // 935 NA
  // 934 NA
  933,
  932,
  // 931 NA
  // 930 NA
  929,
  // 928 NA
  // 927 NA
  926,
  925,
  // 924 NA
  // 923 NA
  922,
  // 921 NA
  // 920 NA
  // 919 NA
  // 918 NA
  // 917 NA
  916,
  915,
  // 914 NA
  // 913 NA
  912,
  // 911 NA
  // 910 NA
  // 909 NA
  // 908 NA
  // 907 NA
  // 906 NA
  // 905 NA
  904,
  903,
  // 902 NA
  901,
  // 900 NA
  // 899 NA
  898,
  // 897 NA
  896,
  895,
  // 894 NA
  893,
  // 892 NA
  891,
  // 890 NA
  889,
  888,
  887,
  // 886 NA
  885,
  // 884 NA
  883,
  882,
  881,
  // 880 NA
  879,
  878,
  877,
  // 876 NA
  // 875 NA
  // 874 NA
  // 873 NA
  // 872 NA
  871,
  870,
  // 869 NA
  868,
  // 867 NA
  // 866 NA
  // 865 NA
  // 864 NA
  // 863 NA
  // 862 NA
  // 861 NA
  // 860 NA
  859,
  858,
  857,
  856,
  // 855 NA
  // 854 NA
  853,
  // 852 NA
  // 851 NA
  // 850 NA
  849,
  848,
  847,
  // 846 NA
  845,
  844,
  843,
  // 842 NA
  // 841 NA
  // 840 NA
  // 839 NA
  // 838 NA
  // 837 NA
  836,
  835,
  834,
  833,
  832,
  831,
  830,
  // 829 NA
  828,
  // 827 NA
  826,
  825,
  // 824 NA
  823,
  822,
  // 821 NA
  820,
  819,
  818,
  817,
  816,
  815,
  814,
  813,
  // 812 NA
  811,
  810,
  809,
  // 808 NA
  807,
  806,
  805,
  // 804 NA
  803,
  802,
  801,
  800,
  799,
  798,
  // 797 NA
  // 796 NA
  795,
  // 794 NA
  793,
  792,
  791,
  790,
  789,
  // 788 NA
  787,
  786,
  785,
  784,
  // 783 NA
  782,
  781,
  780,
  779,
  778,
  // 777 NA
  776,
  775,
  774,
  773,
  // 772 NA
  771,
  // 770 NA
  769,
  768,
  // 767 NA
  // 766 NA
  765,
  764,
  // 763 NA
  // 762 NA
  // 761 NA
  760,
  // 759 NA
  758,
  // 757 NA
  // 756 NA
  755,
  754,
  753,
  // 752 NA
  // 751 NA
  // 750 NA
  749,
  748,
  747,
  746,
  745,
  // 744 NA
  743,
  742,
  741,
  740,
  739,
  // 738 NA
  737,
  736,
  // 735 NA
  734,
  // 733 NA
  732,
  // 731 NA
  // 730 NA
  729,
  // 728 NA
  // 727 NA
  // 726 NA
  // 725 NA
  // 724 NA
  723,
  722,
  721,
  // 720 NA
  719,
  718,
  717,
  716,
  715,
  714,
  713,
  712,
  711,
  710,
  709,
  708,
  707,
  706,
  // 705 NA
  704,
  // 703 NA
  702,
  // 701 NA
  700,
  699,
  698,
  697,
  696,
  695,
  694,
  693,
  // 692 NA
  // 691 NA
  690,
  689,
  688,
  // 687 NA
  686,
  685,
  // 684 NA
  // 683 NA
  682,
  // 681 NA
  680,
  // 679 NA
  // 678 NA
  // 677 NA
  // 676 NA
  675,
  // 674 NA
  673,
  672,
  671,
  670,
  // 669 NA
  668,
  667,
  // 666 NA
  665,
  // 664 NA
  // 663 NA
  662,
  // 661 NA
  660,
  659,
  658,
  // 657 NA
  656,
  655,
  654,
  653,
  // 652 NA
  651,
  // 650 NA
  649,
  // 648 NA
  // 647 NA
  646,
  645,
  // 644 NA
  643,
  642,
  // 641 NA
  640,
  639,
  // 638 NA
  637,
  636,
  635,
  634,
  633,
  // 632 NA
  631,
  630,
  629,
  // 628 NA
  // 627 NA
  // 626 NA
  // 625 NA
  // 624 NA
  623,
  // 622 NA
  // 621 NA
  // 620 NA
  // 619 NA
  // 618 NA
  617,
  616,
  615,
  614,
  613,
  612,
  // 611 NA
  // 610 NA
  609,
  608,
  // 607 NA
  606,
  605,
  604,
  603,
  602,
  601,
  600,
  599,
  598,
  597,
  // 596 NA
  595,
  594,
  593,
  // 592 NA
  // 591 NA
  590,
  // 589 NA
  588,
  587,
  // 586 NA
  585,
  // 584 NA
  // 583 NA
  582,
  // 581 NA
  580,
  579,
  578,
  577,
  576,
  575,
  574,
  573,
  572,
  // 571 NA
  // 570 NA
  569,
  568,
  567,
  566,
  565,
  // 564 NA
  563,
  562,
  561,
  // 560 NA
  559,
  // 558 NA
  // 557 NA
  // 556 NA
  // 555 NA
  554,
  553,
  552,
  551,
  550,
  549,
  // 548 NA
  547,
  546,
  545,
  // 544 NA
  543,
  542,
  541,
  // 540 NA
  539,
  538,
  537,
  536,
  535,
  // 534 NA
  533,
  532,
  531,
  530,
  529,
  528,
  527,
  526,
  525,
  524,
  // 523 NA
  // 522 NA
  521,
  520,
  519,
  518,
  517,
  516,
  515,
  514,
  513,
  // 512 NA
  // 511 NA
  // 510 NA
  // 509 NA
  508,
  // 507 NA
  // 506 NA
  // 505 NA
  // 504 NA
  503,
  502,
  // 501 NA
  500,
  499,
  // 498 NA
  497,
  // 496 NA
  // 495 NA
  494,
  493,
  492,
  491,
  490,
  489,
  488,
  487,
  486,
  485,
  // 484 NA
  483,
  // 482 NA
  // 481 NA
  // 480 NA
  // 479 NA
  478,
  477,
  // 476 NA
  // 475 NA
  474,
  473,
  472,
  // 471 NA
  470,
  // 469 NA
  468,
  467,
  466,
  // 465 NA
  // 464 NA
  463,
  462,
  // 461 NA
  // 460 NA
  // 459 NA
  458,
  457,
  456,
  455,
  454,
  // 453 NA
  452,
  // 451 NA
  450,
  449,
  // 448 NA
  447,
  446,
  445,
  444,
  // 443 NA
  442,
  441,
  440,
  439,
  438,
  437,
  436,
  435,
  434,
  433,
  // 432 NA
  // 431 NA
  // 430 NA
  // 429 NA
  // 428 NA
  427,
  // 426 NA
  425,
  // 424 NA
  423,
  422,
  421,
  // 420 NA
  419,
  418,
  417,
  416,
  415,
  414,
  // 413 NA
  // 412 NA
  411,
  410,
  // 409 NA
  408,
  407,
  406,
  405,
  // 404 NA
  // 403 NA
  // 402 NA
  // 401 NA
  // 400 NA
  // 399 NA
  // 398 NA
  397,
  396,
  395,
  // 394 NA
  // 393 NA
  392,
  391,
  390,
  389,
  388,
  387,
  386,
  // 385 NA
  // 384 NA
  383,
  382,
  381,
  // 380 NA
  379,
  378,
  377,
  376,
  375,
  374,
  373,
  372,
  371,
  370,
  369,
  368,
  367,
  // 366 NA
  365,
  364,
  // 363 NA
  362,
  361,
  360,
  359,
  358,
  357,
  // 356 NA
  355,
  // 354 NA
  353,
  352,
  351,
  350,
  349,
  348,
  347,
  346,
  345,
  344,
  343,
  // 342 NA
  341,
  // 340 NA
  339,
  338,
  337,
  336,
  335,
  334,
  // 333 NA
  // 332 NA
  331,
  330,
  329,
  328,
  327,
  // 326 NA
  325,
  324,
  323,
  // 322 NA
  // 321 NA
  320,
  // 319 NA
  318,
  317,
  // 316 NA
  315,
  314,
  313,
  312,
  311,
  310,
  309,
  308,
  // 307 NA
  306,
  305,
  // 304 NA
  303,
  302,
  301,
  // 300 NA
  // 299 NA
  298,
  297,
  296,
  295,
  294,
  293,
  292,
  291,
  290,
  289,
  288,
  // 287 NA
  286,
  285,
  284,
  // 283 NA
  282,
  281,
  280,
  279,
  278,
  277,
  276,
  275,
  274,
  // 273 NA
  272,
  // 271 NA
  // 270 NA
  269,
  268,
  267,
  266,
  265,
  264,
  // 263 NA
  262,
  261,
  260,
  // 259 NA
  // 258 NA
  // 257 NA
  256,
  // 255 NA
  // 254 NA
  253,
  // 252 NA
  251,
  // 250 NA
  249,
  248,
  247,
  // 246 NA
  245,
  // 244 NA
  243,
  242,
  241,
  240,
  239,
  // 238 NA
  237,
  236,
  235,
  234,
  233,
  232,
  231,
  230,
  229,
  // 228 NA
  // 227 NA
  226,
  // 225 NA
  // 224 NA
  // 223 NA
  // 222 NA
  221,
  220,
  219,
  218,
  // 217 NA
  // 216 NA
  215,
  // 214 NA
  213,
  // 212 NA
  211,
  210,
  209,
  // 208 NA
  207,
  // 206 NA
  205,
  204,
  203,
  // 202 NA
  201,
  // 200 NA
  199,
  // 198 NA
  // 197 NA
  // 196 NA
  // 195 NA
  // 194 NA
  193,
  192,
  191,
  // 190 NA
  // 189 NA
  // 188 NA
  187,
  186,
  // 185 NA
  184,
  // 183 NA
  // 182 NA
  181,
  // 180 NA
  // 179 NA
  178,
  // 177 NA
  // 176 NA
  // 175 NA
  // 174 NA
  173,
  172,
  171,
  170,
  169,
  // 168 NA
  167,
  166,
  165,
  // 164 NA
  // 163 NA
  // 162 NA
  // 161 NA
  160,
  159,
  158,
  157,
  156,
  155,
  154,
  153,
  152,
  151,
  150,
  149,
  148,
  147,
  146,
  145,
  144,
  143,
  142,
  141,
  140,
  139,
  138,
  137,
  136,
  135,
  134,
  133,
  132,
  131,
  130,
  129,
  128,
  127,
  126,
  125,
  124,
  123,
  122,
  121,
  120,
  119,
  118,
  117,
  116,
  115,
  114,
  113,
  112,
  111,
  110,
  109,
  108,
  107,
  106,
  105,
  104,
  103,
  102,
  101,
  100,
  99,
  98,
  97,
  96,
  95,
  94,
  93,
  92,
  91,
  90,
  89,
  88,
  87,
  86,
  85,
  84,
  83,
  82,
  81,
  80,
  79,
  78,
  77,
  76,
  75,
  74,
  73,
  72,
  71,
  70,
  69,
  68,
  67,
  66,
  65,
  64,
  63,
  62,
  61,
  60,
  59,
  58,
  57,
  56,
  55,
  54,
  53,
  52,
  51,
  50,
  49,
  48,
  47,
  46,
  45,
  44,
  43,
  42,
  41,
  40,
  39,
  38,
  37,
  36,
  35,
  34,
  33,
  32,
  31,
  30,
  29,
  28,
  27,
  26,
  25,
  24,
  23,
  22,
  21,
  20,
  19,
  18,
  17,
  16,
  15,
  14,
  13,
  12,
  11,
  10,
  9,
  8,
  7,
  6,
  5,
  4,
  3,
  2,
  1,
  0
};
// clang-format on

/// Place to put a short description when adding a feature with a patch.
/// Keep it short, e.g.,: "relative numbers", "persistent undo".
/// Also add a comment marker to separate the lines.
/// See the official Vim patches for the diff format: It must use a context of
/// one line only.  Create it by hand or use "diff -C2" and edit the patch.
static char *(extra_patches[]) = {
  // Add your patch description below this line
  NULL
};

/// Compares a version string to the current Nvim version.
///
/// @param version Version string like "1.3.42"
///
/// @return true if Nvim is at or above the version.
bool has_nvim_version(char *version_str)
  FUNC_ATTR_NONNULL_ALL
{
  char *p   = version_str;
  int major = 0;
  int minor = 0;
  int patch = 0;

  if (!ascii_isdigit(*p)) {
    return false;
  }
  major = atoi(p);
  p     = strchr(p, '.');  // Find the next dot.

  if (p) {
    p++;  // Advance past the dot.
    if (!ascii_isdigit(*p)) {
      return false;
    }
    minor = atoi(p);
    p     = strchr(p, '.');
    if (p) {
      p++;
      if (!ascii_isdigit(*p)) {
        return false;
      }
      patch = atoi(p);
    }
  }

  return (major < NVIM_VERSION_MAJOR
          || (major == NVIM_VERSION_MAJOR
              && (minor < NVIM_VERSION_MINOR
                  || (minor == NVIM_VERSION_MINOR
                      && patch <= NVIM_VERSION_PATCH))));
}

/// Checks whether a Vim patch has been included.
///
/// @param n Patch number.
///
/// @return true if patch `n` has been included.
bool has_vim_patch(int n)
{
  for (int i = 0; included_patches[i] != 0; i++) {
    if (included_patches[i] == n) {
      return true;
    }
  }
  return false;
}

Dictionary version_dict(void) {
  Dictionary d = ARRAY_DICT_INIT;
  PUT(d, "major", INTEGER_OBJ(NVIM_VERSION_MAJOR));
  PUT(d, "minor", INTEGER_OBJ(NVIM_VERSION_MINOR));
  PUT(d, "patch", INTEGER_OBJ(NVIM_VERSION_PATCH));
  PUT(d, "api_level", INTEGER_OBJ(NVIM_API_LEVEL));
  PUT(d, "api_compatible", INTEGER_OBJ(NVIM_API_LEVEL_COMPAT));
  PUT(d, "api_prerelease", BOOLEAN_OBJ(NVIM_API_PRERELEASE));
  return d;
}

void ex_version(exarg_T *eap)
{
  // Ignore a ":version 9.99" command.
  if (*eap->arg == NUL) {
    msg_putchar('\n');
    list_version();
  }
}

/// List all features aligned in columns, dictionary style.
static void list_features(void)
{
  int nfeat = 0;
  int width = 0;

  // Find the length of the longest feature name, use that + 1 as the column
  // width
  int i;
  for (i = 0; features[i] != NULL; ++i) {
    int l = (int)STRLEN(features[i]);

    if (l > width) {
      width = l;
    }
    nfeat++;
  }
  width += 1;

  if (Columns < width) {
    // Not enough screen columns - show one per line
    for (i = 0; features[i] != NULL; ++i) {
      version_msg(features[i]);
      if (msg_col > 0) {
        msg_putchar('\n');
      }
    }
    return;
  }

  // The rightmost column doesn't need a separator.
  // Sacrifice it to fit in one more column if possible.
  int ncol = (int)(Columns + 1) / width;
  int nrow = nfeat / ncol + (nfeat % ncol ? 1 : 0);

  // i counts columns then rows.  idx counts rows then columns.
  for (i = 0; !got_int && i < nrow * ncol; ++i) {
    int idx = (i / ncol) + (i % ncol) * nrow;
    if (idx < nfeat) {
      int last_col = (i + 1) % ncol == 0;
      msg_puts(features[idx]);
      if (last_col) {
        if (msg_col > 0) {
          msg_putchar('\n');
        }
      } else {
        while (msg_col % width) {
          int old_msg_col = msg_col;
          msg_putchar(' ');
          if (old_msg_col == msg_col) {
            break;  // XXX: Avoid infinite loop.
          }
        }
      }
    } else {
      if (msg_col > 0) {
        msg_putchar('\n');
      }
    }
  }
  MSG_PUTS("For differences from Vim, see :help vim-differences\n\n");
}

void list_version(void)
{
  // When adding features here, don't forget to update the list of
  // internal variables in eval.c!
  MSG(longVersion);
  MSG(version_buildtype);
  MSG(version_cflags);

  // Print the list of extra patch descriptions if there is at least one.
  char *s = "";
  if (extra_patches[0] != NULL) {
    MSG_PUTS(_("\nExtra patches: "));
    s = "";

    for (int i = 0; extra_patches[i] != NULL; ++i) {
      MSG_PUTS(s);
      s = ", ";
      MSG_PUTS(extra_patches[i]);
    }
  }

#ifdef HAVE_PATHDEF

  if ((*compiled_user != NUL) || (*compiled_sys != NUL)) {
    MSG_PUTS(_("\nCompiled "));

    if (*compiled_user != NUL) {
      MSG_PUTS(_("by "));
      MSG_PUTS(compiled_user);
    }

    if (*compiled_sys != NUL) {
      MSG_PUTS("@");
      MSG_PUTS(compiled_sys);
    }
  }
#endif  // ifdef HAVE_PATHDEF

  version_msg(_("\n\nOptional features included (+) or not (-): "));

  list_features();

#ifdef SYS_VIMRC_FILE
  version_msg(_("   system vimrc file: \""));
  version_msg(SYS_VIMRC_FILE);
  version_msg("\"\n");
#endif  // ifdef SYS_VIMRC_FILE
#ifdef HAVE_PATHDEF

  if (*default_vim_dir != NUL) {
    version_msg(_("  fall-back for $VIM: \""));
    version_msg(default_vim_dir);
    version_msg("\"\n");
  }

  if (*default_vimruntime_dir != NUL) {
    version_msg(_(" f-b for $VIMRUNTIME: \""));
    version_msg(default_vimruntime_dir);
    version_msg("\"\n");
  }
#endif  // ifdef HAVE_PATHDEF
}

/// Output a string for the version message.  If it's going to wrap, output a
/// newline, unless the message is too long to fit on the screen anyway.
///
/// @param s
static void version_msg(char *s)
{
  int len = (int)STRLEN(s);

  if (!got_int
      && (len < (int)Columns)
      && (msg_col + len >= (int)Columns)
      && (*s != '\n')) {
    msg_putchar('\n');
  }

  if (!got_int) {
    MSG_PUTS(s);
  }
}


/// Show the intro message when not editing a file.
void maybe_intro_message(void)
{
  if (bufempty()
      && (curbuf->b_fname == NULL)
      && (firstwin->w_next == NULL)
      && (vim_strchr(p_shm, SHM_INTRO) == NULL)) {
    intro_message(FALSE);
  }
}

/// Give an introductory message about Vim.
/// Only used when starting Vim on an empty file, without a file name.
/// Or with the ":intro" command (for Sven :-).
///
/// @param colon TRUE for ":intro"
void intro_message(int colon)
{
  int i;
  long row;
  long blanklines;
  int sponsor;
  char *p;
  static char *(lines[]) = {
    N_(NVIM_VERSION_LONG),
    "",
    N_("by Bram Moolenaar et al."),
    N_("Nvim is open source and freely distributable"),
    N_("https://neovim.io/community"),
    "",
    N_("type  :help nvim<Enter>       if you are new! "),
    N_("type  :CheckHealth<Enter>     to optimize Nvim"),
    N_("type  :q<Enter>               to exit         "),
    N_("type  :help<Enter>            for help        "),
    "",
    N_("Help poor children in Uganda!"),
    N_("type  :help iccf<Enter>       for information "),
  };

  // blanklines = screen height - # message lines
  size_t lines_size = ARRAY_SIZE(lines);
  assert(lines_size <= LONG_MAX);

  blanklines = Rows - ((long)lines_size - 1l);

  // Don't overwrite a statusline.  Depends on 'cmdheight'.
  if (p_ls > 1) {
    blanklines -= Rows - topframe->fr_height;
  }

  if (blanklines < 0) {
    blanklines = 0;
  }

  // Show the sponsor and register message one out of four times, the Uganda
  // message two out of four times.
  sponsor = (int)time(NULL);
  sponsor = ((sponsor & 2) == 0) - ((sponsor & 4) == 0);

  // start displaying the message lines after half of the blank lines
  row = blanklines / 2;

  if (((row >= 2) && (Columns >= 50)) || colon) {
    for (i = 0; i < (int)ARRAY_SIZE(lines); ++i) {
      p = lines[i];

      if (sponsor != 0) {
        if (strstr(p, "children") != NULL) {
          p = sponsor < 0
              ? N_("Sponsor Vim development!")
              : N_("Become a registered Vim user!");
        } else if (strstr(p, "iccf") != NULL) {
          p = sponsor < 0
              ? N_("type  :help sponsor<Enter>    for information ")
              : N_("type  :help register<Enter>   for information ");
        } else if (strstr(p, "Orphans") != NULL) {
          p = N_("menu  Help->Sponsor/Register  for information    ");
        }
      }

      if (*p != NUL) {
        do_intro_line(row, (char_u *)_(p), 0);
      }
      row++;
    }
  }

  // Make the wait-return message appear just below the text.
  if (colon) {
    assert(row <= INT_MAX);
    msg_row = (int)row;
  }
}

static void do_intro_line(long row, char_u *mesg, int attr)
{
  long col;
  char_u *p;
  int l;
  int clen;

  // Center the message horizontally.
  col = vim_strsize(mesg);

  col = (Columns - col) / 2;

  if (col < 0) {
    col = 0;
  }

  // Split up in parts to highlight <> items differently.
  for (p = mesg; *p != NUL; p += l) {
    clen = 0;

    for (l = 0; p[l] != NUL
         && (l == 0 || (p[l] != '<' && p[l - 1] != '>')); ++l) {
      if (has_mbyte) {
        clen += ptr2cells(p + l);
        l += (*mb_ptr2len)(p + l) - 1;
      } else {
        clen += byte2cells(p[l]);
      }
    }
    assert(row <= INT_MAX && col <= INT_MAX);
    screen_puts_len(p, l, (int)row, (int)col, *p == '<' ? hl_attr(HLF_8) : attr);
    col += clen;
  }
}

/// ":intro": clear screen, display intro screen and wait for return.
///
/// @param eap
void ex_intro(exarg_T *eap)
{
  screenclear();
  intro_message(TRUE);
  wait_return(TRUE);
}

