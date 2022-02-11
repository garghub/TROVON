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
V_2 -> V_4 -> V_28 = NULL ;
F_10 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_12 ( V_2 -> V_4 , 0 ) ;
if ( ! V_30 ) {
F_13 ( V_32 , V_2 -> V_6 , L_3 ,
L_4 ) ;
return - V_33 ;
}
V_31 = F_14 ( V_30 , V_34 , NULL ) ;
if ( V_31 < 0 ) {
F_13 ( V_32 , V_2 -> V_6 ,
L_5 ,
V_31 ) ;
return - V_33 ;
}
V_31 = F_15 ( V_30 ) ;
if ( V_31 )
F_13 ( V_32 , V_2 -> V_6 ,
L_6 , V_31 ) ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_35 V_36 ;
struct V_37 V_38 ;
struct V_29 * V_30 ;
V_30 = V_2 -> V_30 ;
V_2 -> V_30 = NULL ;
memset ( & V_36 , 0 , sizeof( struct V_35 ) ) ;
memset ( & V_38 , 0 , sizeof( struct V_37 ) ) ;
V_38 . V_39 = ( void V_40 V_41 * ) & V_36 ;
V_38 . V_42 = V_43 ;
for ( V_36 . V_44 = V_2 -> V_4 -> V_45 - 1 ; V_36 . V_44 > 0 ; V_36 . V_44 -- )
F_17 ( V_30 , V_46 , ( unsigned long ) & V_38 ) ;
F_18 ( V_2 -> V_4 , 0 ) ;
F_19 ( V_30 , V_34 ) ;
F_6 ( V_2 -> V_4 , 0 ) ;
}
int F_20 ( void )
{
int V_31 ;
V_31 = F_21 ( V_14 , L_1 ) ;
if ( V_31 != 0 ) {
F_22 ( L_7
L_8 , V_14 ) ;
return V_31 ;
}
return 0 ;
}
void F_23 ( void )
{
F_24 ( V_14 , L_1 ) ;
}
