T_1
F_1 ( T_2 * V_1 , T_1 V_2 , T_1 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
T_1 V_6 = 0 ;
T_1 V_7 ;
T_1 V_8 = 0 ;
char V_9 = 1 ;
#ifdef F_2
if ( V_3 != NULL )
{
fprintf ( V_10 , L_1 , V_2 , * V_3 ) ;
}
else
{
fprintf ( V_10 , L_2 , V_2 ) ;
}
#endif
while ( V_9 != 0 )
{
V_6 <<= 7 ;
V_7 = F_3 ( V_1 , V_2 + V_8 ) ;
V_8 += 1 ;
V_6 += ( V_7 & 0x7F ) ;
V_9 = ( V_7 & 0x80 ) ;
#ifdef F_2
fprintf ( V_10 , L_3 ,
V_7 , V_7 , V_8 , V_6 , V_9 ) ;
#endif
}
if ( V_8 > 5 ) {
F_4 ( NULL , V_4 , V_5 , V_1 , V_2 , V_8 ) ;
V_6 = 0 ;
}
if ( V_3 != NULL )
{
* V_3 = V_8 ;
#ifdef F_2
fprintf ( V_10 , L_4 , * V_3 , V_6 ) ;
#endif
}
return ( V_6 ) ;
}
