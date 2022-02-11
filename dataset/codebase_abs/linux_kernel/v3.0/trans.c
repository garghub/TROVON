int F_1 ( struct V_1 * V_2 , char * V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
struct V_6 * V_8 = F_2 ( V_2 ) -> V_8 ;
const char * V_9 ;
char * V_10 ;
int V_11 , V_12 , V_13 ;
V_9 = V_5 -> V_14 ;
V_11 = V_5 -> V_15 ;
V_10 = V_3 ;
V_12 = V_16 ;
if ( V_8 ) {
T_1 V_17 ;
while ( V_11 > 0 ) {
if ( V_7 ) {
V_13 = V_7 -> V_18 ( V_9 , V_11 , & V_17 ) ;
if ( V_13 <= 0 ) {
V_17 = '?' ;
V_13 = 1 ;
}
V_9 += V_13 ;
V_11 -= V_13 ;
} else {
V_17 = * V_9 ++ ;
V_11 -- ;
}
if ( V_17 == '/' )
V_17 = ':' ;
V_13 = V_8 -> V_19 ( V_17 , V_10 , V_12 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_20 )
goto V_3;
* V_10 = '?' ;
V_13 = 1 ;
}
V_10 += V_13 ;
V_12 -= V_13 ;
}
} else {
char V_17 ;
while ( -- V_11 >= 0 )
* V_10 ++ = ( V_17 = * V_9 ++ ) == '/' ? ':' : V_17 ;
}
V_3:
return V_10 - V_3 ;
}
void F_3 ( struct V_1 * V_2 , struct V_4 * V_3 , struct V_21 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) -> V_7 ;
struct V_6 * V_8 = F_2 ( V_2 ) -> V_8 ;
const char * V_9 ;
char * V_10 ;
int V_11 , V_12 , V_13 ;
V_9 = V_5 -> V_14 ;
V_11 = V_5 -> V_15 ;
V_10 = V_3 -> V_14 ;
V_12 = V_22 ;
if ( V_8 ) {
T_1 V_17 ;
while ( V_11 > 0 ) {
V_13 = V_8 -> V_18 ( V_9 , V_11 , & V_17 ) ;
if ( V_13 < 0 ) {
V_17 = '?' ;
V_13 = 1 ;
}
V_9 += V_13 ;
V_11 -= V_13 ;
if ( V_17 == ':' )
V_17 = '/' ;
if ( V_7 ) {
V_13 = V_7 -> V_19 ( V_17 , V_10 , V_12 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_20 )
goto V_3;
* V_10 = '?' ;
V_13 = 1 ;
}
V_10 += V_13 ;
V_12 -= V_13 ;
} else {
* V_10 ++ = V_17 > 0xff ? '?' : V_17 ;
V_12 -- ;
}
}
} else {
char V_17 ;
if ( V_12 > V_11 )
V_12 = V_11 ;
while ( -- V_12 >= 0 )
* V_10 ++ = ( V_17 = * V_9 ++ ) == ':' ? '/' : V_17 ;
}
V_3:
V_3 -> V_15 = V_10 - ( char * ) V_3 -> V_14 ;
V_12 = V_22 - V_3 -> V_15 ;
while ( -- V_12 >= 0 )
* V_10 ++ = 0 ;
}
