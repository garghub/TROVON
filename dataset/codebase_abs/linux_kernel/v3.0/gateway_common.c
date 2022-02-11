static void F_1 ( int V_1 , int V_2 , long * V_3 )
{
int V_4 = 0 , V_5 , V_6 , V_7 ;
T_1 V_8 , V_9 ;
* V_3 = 0 ;
V_7 = 0x0FFFFFFF ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
V_5 = 32 * ( V_8 + 2 ) * ( 1 << V_9 ) ;
if ( abs ( V_5 - V_1 ) < V_7 ) {
* V_3 = ( V_8 << 7 ) + ( V_9 << 3 ) ;
V_7 = abs ( V_5 - V_1 ) ;
V_4 = V_5 ;
}
}
}
V_7 = 0x0FFFFFFF ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_6 = ( ( V_9 + 1 ) * ( V_4 ) ) / 8 ;
if ( abs ( V_6 - V_2 ) < V_7 ) {
* V_3 = ( * V_3 & 0xF8 ) | V_9 ;
V_7 = abs ( V_6 - V_2 ) ;
}
}
}
void F_2 ( T_1 V_3 , int * V_1 , int * V_2 )
{
char V_8 = ( V_3 & 0x80 ) >> 7 ;
char V_10 = ( V_3 & 0x78 ) >> 3 ;
char V_11 = ( V_3 & 0x07 ) ;
if ( ! V_3 ) {
* V_1 = 0 ;
* V_2 = 0 ;
return;
}
* V_1 = 32 * ( V_8 + 2 ) * ( 1 << V_10 ) ;
* V_2 = ( ( V_11 + 1 ) * ( * V_1 ) ) / 8 ;
}
static bool F_3 ( struct V_12 * V_13 , char * V_14 ,
long * V_2 , long * V_1 )
{
int V_15 , V_16 = 1 ;
char * V_17 , * V_18 ;
V_17 = strchr ( V_14 , '/' ) ;
if ( V_17 )
* V_17 = 0 ;
if ( strlen ( V_14 ) > 4 ) {
V_18 = V_14 + strlen ( V_14 ) - 4 ;
if ( F_4 ( V_18 , L_1 , 4 ) == 0 )
V_16 = 1024 ;
if ( ( F_4 ( V_18 , L_2 , 4 ) == 0 ) ||
( V_16 > 1 ) )
* V_18 = '\0' ;
}
V_15 = F_5 ( V_14 , 10 , V_1 ) ;
if ( V_15 ) {
F_6 ( V_13 ,
L_3 ,
V_14 ) ;
return false ;
}
* V_1 *= V_16 ;
if ( V_17 ) {
V_16 = 1 ;
if ( strlen ( V_17 + 1 ) > 4 ) {
V_18 = V_17 + 1 - 4 + strlen ( V_17 + 1 ) ;
if ( F_4 ( V_18 , L_1 , 4 ) == 0 )
V_16 = 1024 ;
if ( ( F_4 ( V_18 , L_2 , 4 ) == 0 ) ||
( V_16 > 1 ) )
* V_18 = '\0' ;
}
V_15 = F_5 ( V_17 + 1 , 10 , V_2 ) ;
if ( V_15 ) {
F_6 ( V_13 ,
L_4
L_5 , V_17 + 1 ) ;
return false ;
}
* V_2 *= V_16 ;
}
return true ;
}
T_2 F_7 ( struct V_12 * V_13 , char * V_14 , T_3 V_19 )
{
struct V_20 * V_20 = F_8 ( V_13 ) ;
long V_21 = 0 , V_2 = 0 , V_1 = 0 ;
bool V_15 ;
V_15 = F_3 ( V_13 , V_14 , & V_2 , & V_1 ) ;
if ( ! V_15 )
goto V_22;
if ( ( ! V_1 ) || ( V_1 < 256 ) )
V_1 = 2000 ;
if ( ! V_2 )
V_2 = V_1 / 5 ;
F_1 ( V_1 , V_2 , & V_21 ) ;
F_2 ( ( T_1 ) V_21 ,
( int * ) & V_1 , ( int * ) & V_2 ) ;
F_9 ( V_20 ) ;
F_10 ( V_13 , L_6
L_7 ,
F_11 ( & V_20 -> V_23 ) , V_21 ,
( V_1 > 2048 ? V_1 / 1024 : V_1 ) ,
( V_1 > 2048 ? L_8 : L_9 ) ,
( V_2 > 2048 ? V_2 / 1024 : V_2 ) ,
( V_2 > 2048 ? L_8 : L_9 ) ) ;
F_12 ( & V_20 -> V_23 , V_21 ) ;
V_22:
return V_19 ;
}
