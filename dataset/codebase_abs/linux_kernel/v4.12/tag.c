void
F_1 ( int V_1 ,
unsigned int V_2 ,
int V_3 ,
unsigned int V_4 ,
struct V_5 * V_6 )
{
assert ( V_6 != NULL ) ;
V_6 -> V_1 = V_1 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
}
unsigned int
F_2 ( struct V_5 * V_7 )
{
int V_1 ;
unsigned int V_8 ;
unsigned int V_2 ;
int V_3 ;
unsigned int V_9 ;
unsigned int V_4 ;
unsigned int V_10 ;
assert ( V_7 != NULL ) ;
if ( V_7 -> V_1 < 0 ) {
V_1 = - V_7 -> V_1 ;
V_8 = 1 ;
} else {
V_1 = V_7 -> V_1 ;
V_8 = 0 ;
}
V_2 = V_7 -> V_2 ;
if ( V_7 -> V_3 < 0 ) {
V_3 = - V_7 -> V_3 ;
V_9 = 1 ;
} else {
V_3 = V_7 -> V_3 ;
V_9 = 0 ;
}
V_4 = V_7 -> V_4 ;
if ( V_4 != 0 )
{
assert ( ( V_1 == 0 ) && ( V_2 == 0 ) && ( V_3 == 0 ) ) ;
V_10 = V_11 | ( V_4 & 0xFF ) << V_12 ;
}
else
{
V_10 = V_13
| ( ( V_8 & 0x00000001 ) << V_14 )
| ( ( V_9 & 0x00000001 ) << V_15 )
| ( ( V_1 & 0x000000FF ) << V_16 )
| ( ( V_2 & 0x000000FF ) << V_17 )
| ( ( V_3 & 0x000000FF ) << V_18 ) ;
}
return V_10 ;
}
