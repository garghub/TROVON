T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
#ifdef F_2
struct V_2 * V_3 ;
struct V_2 * V_4 ;
int V_5 ;
char V_6 [ V_7 ] ;
if ( F_3 ( & V_3 ) ) {
goto V_8;
}
for ( V_4 = V_3 ; V_4 != NULL ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_10 == NULL )
continue;
V_5 = V_4 -> V_10 -> V_11 ;
memset ( V_6 , 0x0 , V_7 ) ;
switch ( V_5 ) {
case V_12 :
{
struct V_13 * V_14 = (struct V_13 * ) V_4 -> V_10 ;
F_4 ( & V_14 -> V_15 , V_6 , sizeof( V_6 ) ) ;
break;
}
case V_16 :
{
struct V_17 * V_18 = (struct V_17 * ) V_4 -> V_10 ;
F_5 ( & V_18 -> V_19 , V_6 , sizeof( V_6 ) ) ;
break;
}
default:
break;
}
if ( ! F_6 ( V_6 , L_1 ) || ! F_6 ( V_6 , L_2 ) )
continue;
if ( * V_6 ) {
V_1 = F_7 ( V_1 , F_8 ( V_6 ) ) ;
}
}
F_9 ( V_3 ) ;
V_8:
#endif
return V_1 ;
}
