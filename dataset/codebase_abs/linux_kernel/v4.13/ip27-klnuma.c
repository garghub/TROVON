void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( 0 , & V_1 ) ;
#ifdef F_4
#ifndef F_5
#error Kernel replication works with mapped kernel support. No calias support.
#endif
{
T_2 V_2 ;
F_6 (cnode) {
if ( V_2 == 0 )
continue;
F_3 ( V_2 , & V_1 ) ;
}
}
#endif
V_3 -> V_4 = & V_1 ;
}
static T_1 void F_7 ( T_3 V_5 , T_3 V_6 )
{
T_4 * V_7 ;
V_7 = & F_8 ( V_5 ) -> V_8 ;
F_9 ( V_5 ) = ( unsigned long ) V_7 ;
V_7 -> V_9 = V_10 ;
V_7 -> V_11 = V_6 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_14 = F_10 ( V_6 ) ;
V_7 -> V_15 = F_10 ( V_13 ) ;
F_11 ( L_1 , V_5 , V_6 , V_13 ) ;
}
static T_1 void F_12 ( T_3 V_16 )
{
unsigned long V_17 , V_18 , V_19 , V_20 ;
V_18 = ( unsigned long ) V_21 ;
V_19 = ( unsigned long ) V_22 ;
V_20 = V_19 - V_18 ;
V_17 = F_13 ( F_14 ( V_18 ) ,
V_16 ) ;
memcpy ( ( void * ) V_17 , ( void * ) V_18 , V_20 ) ;
}
void T_1 F_15 ( void )
{
T_2 V_2 ;
T_3 V_5 ;
T_3 V_6 ;
V_6 = V_13 ;
F_7 ( V_13 , V_13 ) ;
F_6 (cnode) {
if ( V_2 == 0 )
continue;
V_5 = F_16 ( V_2 ) ;
if ( F_17 ( V_2 , & V_1 ) ) {
V_6 = V_5 ;
F_12 ( V_6 ) ;
}
F_7 ( V_5 , V_6 ) ;
}
}
unsigned long F_18 ( T_2 V_2 )
{
unsigned long V_23 = V_24 ;
T_3 V_25 = F_16 ( V_2 ) ;
unsigned long V_26 ;
#ifdef F_5
V_23 += 16777216 ;
#endif
V_26 = F_19 ( ( unsigned long ) ( & V_27 ) ) - V_23 ;
if ( ( V_2 == 0 ) || ( F_17 ( V_2 , & V_1 ) ) )
return F_20 ( V_25 , V_26 ) >> V_28 ;
else
return F_21 ( F_19 ( F_22 ( V_25 , 0 ) ) ) >> V_28 ;
}
