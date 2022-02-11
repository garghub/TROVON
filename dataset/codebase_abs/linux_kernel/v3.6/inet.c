static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
struct V_8 * V_9 ;
T_2 * V_10 = ( T_2 * ) NULL ;
if ( ! V_4 || ! ( (struct V_8 * ) V_4 ) -> V_11 ) {
F_2 ( NULL , V_12 , L_1 , V_3 , V_4 ) ;
return V_13 ;
}
V_6 = ( (struct V_8 * ) V_4 ) -> V_11 -> V_14 ;
V_10 = ( T_2 * ) F_3 ( V_6 ) ;
if ( F_4 ( V_10 ) == - 1 ) {
F_2 ( NULL , V_12 , L_2 ,
V_3 , V_6 , V_10 ) ;
return V_13 ;
}
if ( ! V_10 -> V_15 ) {
F_5 ( NULL , L_3 ,
V_3 , V_6 , V_10 ) ;
return V_13 ;
}
V_7 = V_10 -> V_15 ;
V_9 = (struct V_8 * ) V_4 ;
if ( F_6 ( V_7 ) != - 1 ) {
switch ( V_3 ) {
case V_16 :
F_7 ( V_7 , L_4 , V_7 -> V_17 [ V_10 -> V_18 ] -> V_19 ) ;
V_7 -> V_20 = V_9 -> V_21 ;
#ifdef F_8
F_9 ( V_7 ) ;
#endif
break;
case V_22 :
F_7 ( V_7 , L_5 , V_7 -> V_17 [ V_10 -> V_18 ] -> V_19 ) ;
V_7 -> V_20 = 0xFFFFFFFF ;
#ifdef F_8
F_9 ( V_7 ) ;
#endif
break;
}
}
return V_13 ;
}
void F_10 ( void )
{
if ( F_11 ( & V_23 ) == 1 ) {
F_12 ( & V_24 ) ;
}
}
void F_13 ( void )
{
if ( F_14 ( & V_23 ) == 0 ) {
F_15 ( & V_24 ) ;
}
}
