static T_1 F_1 ( T_2 V_1 ,
T_3 V_2 , void * V_3 , void * * V_4 )
{
* V_4 =
( V_2 != V_5 ) ? V_3 : NULL ;
return V_6 ;
}
static T_1 F_2 ( T_3 V_2 ,
T_4 V_7 ,
T_3 V_8 , T_5 * V_9 ,
void * V_3 , void * V_10 )
{
T_1 V_11 ;
if ( V_2 == V_12 ) {
int V_13 = V_7 & 0x0f ;
int V_14 = ! ( V_7 & 0x10 ) ;
F_3 ( V_15 , V_16 , V_17 , V_13 ) ;
F_4 ( V_15 , V_18 [ V_13 ] , V_14 ) ;
F_5 ( V_15 ) ;
V_11 = V_6 ;
} else {
F_6 ( L_1 ,
V_2 , ( unsigned long ) V_7 , ( T_3 ) * V_9 ) ;
V_11 = V_19 ;
}
return V_11 ;
}
static int F_7 ( struct V_20 * V_21 )
{
T_1 V_11 ;
int V_22 ;
int V_23 ;
V_15 = F_8 () ;
if ( ! V_15 ) {
F_9 ( L_2 ) ;
return - V_24 ;
}
V_15 -> V_25 = L_3 ;
V_15 -> V_26 = L_4 ;
V_15 -> V_27 . V_28 = V_29 ;
V_15 -> V_30 = V_18 ;
V_15 -> V_31 = sizeof( unsigned short ) ;
V_15 -> V_32 = F_10 ( V_18 ) ;
F_11 ( V_15 , V_16 , V_17 ) ;
F_12 ( V_33 , V_15 -> V_34 ) ;
for ( V_22 = 0 ; V_22 < F_10 ( V_18 ) ; V_22 ++ ) {
if ( V_22 < 9 ) {
V_18 [ V_22 ] = V_35 + V_22 ;
F_12 ( V_35 + V_22 , V_15 -> V_36 ) ;
} else
V_18 [ V_22 ] = V_37 ;
}
V_23 = F_13 ( V_15 ) ;
if ( V_23 ) {
F_9 ( L_5 ) ;
F_14 ( V_15 ) ;
return V_23 ;
}
V_11 = F_15 ( V_21 -> V_38 ,
0x81 , & F_2 ,
& F_1 , V_21 ) ;
if ( F_16 ( V_11 ) ) {
F_9 ( L_6 ) ;
F_17 ( V_15 ) ;
V_23 = - V_39 ;
}
return V_23 ;
}
static int F_18 ( struct V_20 * V_21 , int type )
{
T_1 V_11 ;
V_11 = F_19 ( V_21 -> V_38 ,
0x81 , & F_2 ) ;
if ( F_16 ( V_11 ) )
F_9 ( L_7 ) ;
F_17 ( V_15 ) ;
return 0 ;
}
static int T_6 F_20 ( void )
{
if ( V_40 )
return - V_41 ;
return F_21 ( & V_42 ) ;
}
static void T_7 F_22 ( void )
{
F_23 ( & V_42 ) ;
}
