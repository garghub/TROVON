T_1
F_1 ( T_2 * V_1 , T_1 V_2 , T_1 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_6 = 0 ;
char V_7 = 1 ;
#ifdef F_2
if ( V_3 != NULL )
{
fprintf ( V_8 , L_1 , V_2 , * V_3 ) ;
}
else
{
fprintf ( V_8 , L_2 , V_2 ) ;
}
#endif
while ( V_7 != 0 )
{
V_4 <<= 7 ;
V_5 = F_3 ( V_1 , V_2 + V_6 ) ;
V_6 += 1 ;
V_4 += ( V_5 & 0x7F ) ;
V_7 = ( V_5 & 0x80 ) ;
#ifdef F_2
fprintf ( V_8 , L_3 ,
V_5 , V_5 , V_6 , V_4 , V_7 ) ;
#endif
}
if ( V_3 != NULL )
{
* V_3 = V_6 ;
#ifdef F_2
fprintf ( V_8 , L_4 , * V_3 , V_4 ) ;
#endif
}
return ( V_4 ) ;
}
