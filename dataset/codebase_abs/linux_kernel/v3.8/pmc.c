static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( F_3 ( V_2 + V_1 ) ) ;
}
static inline void F_4 ( T_1 V_3 , T_1 V_1 )
{
F_5 ( V_3 , F_3 ( V_2 + V_1 ) ) ;
}
void T_2 F_6 ( void )
{
bool V_4 = true ;
T_1 V_3 ;
#ifdef F_7
if ( F_8 () ) {
struct V_5 * V_6 ;
V_4 = false ;
V_6 = F_9 ( NULL , V_7 ) ;
if ( V_6 ) {
if ( F_10 ( V_6 , L_1 ,
NULL ) )
V_4 = true ;
}
}
#endif
V_3 = F_1 ( V_8 ) ;
if ( V_4 )
V_3 |= V_9 ;
else
V_3 &= ~ V_9 ;
F_4 ( V_3 , V_8 ) ;
}
