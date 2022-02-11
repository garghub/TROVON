int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_2 -> V_6 ;
if ( V_6 -> V_8 >= V_9 )
return - V_10 ;
V_4 = F_2 ( 1 << V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_6 -> V_8 << V_11 ;
V_4 -> V_16 = & V_17 ;
V_4 -> V_18 = & V_6 -> V_19 -> V_20 ;
V_7 = sprintf ( V_4 -> V_21 , L_1 ) ;
if ( V_6 -> V_8 > 25 ) {
if ( V_6 -> V_8 > 701 ) {
if ( V_6 -> V_8 > 18277 )
V_7 += sprintf ( V_4 -> V_21 + V_7 , L_2 ,
'a' + ( ( ( V_6 -> V_8 - 18278 )
/ 17576 ) % 26 ) ) ;
V_7 += sprintf ( V_4 -> V_21 + V_7 , L_2 ,
'a' + ( ( ( V_6 -> V_8 - 702 ) / 676 ) % 26 ) ) ;
}
V_7 += sprintf ( V_4 -> V_21 + V_7 , L_2 ,
'a' + ( ( ( V_6 -> V_8 - 26 ) / 26 ) % 26 ) ) ;
}
V_7 += sprintf ( V_4 -> V_21 + V_7 , L_2 , 'a' + ( V_6 -> V_8 % 26 ) ) ;
if ( V_6 -> V_22 & V_23 ||
F_3 ( V_24 , & V_6 -> V_25 ) )
F_4 ( V_4 , 1 ) ;
F_5 ( V_4 , V_6 ) ;
V_4 -> V_26 = V_2 -> V_27 ;
V_2 -> V_4 = V_4 ;
F_6 ( V_2 -> V_4 , 0 ) ;
F_7 ( V_2 -> V_4 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
F_9 ( V_2 -> V_4 ) ;
V_2 -> V_4 -> V_26 = NULL ;
V_2 -> V_4 -> V_28 = NULL ;
F_10 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
V_30 = F_12 ( V_2 -> V_4 , 0 ) ;
if ( ! V_30 || F_13 ( V_30 , V_31 , NULL ) < 0 )
return - V_32 ;
F_14 ( V_30 , V_33 , 0 ) ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_34 V_35 ;
struct V_36 V_37 ;
struct V_29 * V_30 ;
V_30 = V_2 -> V_30 ;
V_2 -> V_30 = NULL ;
memset ( & V_35 , 0 , sizeof( struct V_34 ) ) ;
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 . V_38 = ( void V_39 V_40 * ) & V_35 ;
V_37 . V_41 = V_42 ;
for ( V_35 . V_43 = V_2 -> V_4 -> V_44 - 1 ; V_35 . V_43 > 0 ; V_35 . V_43 -- )
F_14 ( V_30 , V_45 , ( unsigned long ) & V_37 ) ;
F_16 ( V_2 -> V_4 , 0 ) ;
F_17 ( V_30 , V_31 ) ;
F_6 ( V_2 -> V_4 , 0 ) ;
}
int F_18 ( void )
{
int V_46 ;
V_46 = F_19 ( V_14 , L_1 ) ;
if ( V_46 != 0 ) {
F_20 ( L_3
L_4 , V_14 ) ;
return V_46 ;
}
return 0 ;
}
void F_21 ( void )
{
F_22 ( V_14 , L_1 ) ;
}
