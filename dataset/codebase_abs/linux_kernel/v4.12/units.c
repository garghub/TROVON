unsigned long F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 = V_3 ;
while ( V_4 -> V_5 ) {
char * V_6 = strchr ( V_1 , V_4 -> V_5 ) ;
if ( V_6 ) {
unsigned long int V_7 ;
char * V_8 ;
V_7 = strtoul ( V_1 , & V_8 , 10 ) ;
if ( V_6 != V_8 )
break;
if ( V_7 > V_9 / V_4 -> V_10 )
break;
V_7 *= V_4 -> V_10 ;
return V_7 ;
}
V_4 ++ ;
}
return ( unsigned long ) - 1 ;
}
unsigned long F_2 ( unsigned long V_7 , char * V_11 )
{
* V_11 = ' ' ;
if ( V_7 > 1000 ) {
V_7 /= 1000 ;
* V_11 = 'K' ;
}
if ( V_7 > 1000 ) {
V_7 /= 1000 ;
* V_11 = 'M' ;
}
if ( V_7 > 1000 ) {
V_7 /= 1000 ;
* V_11 = 'G' ;
}
return V_7 ;
}
int F_3 ( char * V_12 , T_1 V_13 , T_2 V_14 )
{
char V_11 [ 4 ] = L_1 ;
int V_4 = 0 ;
while ( ( ( V_14 / 1024 ) > 1 ) && ( V_4 < 3 ) ) {
V_14 /= 1024 ;
V_4 ++ ;
}
return F_4 ( V_12 , V_13 , L_2 V_15 L_3 , V_14 , V_11 [ V_4 ] ) ;
}
