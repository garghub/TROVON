static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( ( unsigned long ) V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , ( unsigned long ) V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned long V_11 , V_12 ;
int V_13 , V_14 ;
V_11 = V_15 + V_8 * V_16 ;
if ( ! F_6 ( V_11 , V_16 , F_7 ( V_7 ) ) )
return - V_17 ;
if ( F_2 ( V_11 + V_18 ) != V_19 ||
F_2 ( V_11 + V_20 ) != V_21 ) {
F_8 ( V_11 , V_16 ) ;
return - V_22 ;
}
switch ( F_2 ( V_11 + V_23 ) & ( V_24 | V_25 ) ) {
case V_24 :
V_13 = 6 ;
break;
case V_25 :
V_13 = 7 ;
break;
case V_24 | V_25 :
V_13 = 5 ;
break;
default:
F_9 ( V_7 , L_1 ) ;
F_8 ( V_11 , V_16 ) ;
return - V_26 ;
}
V_10 = F_10 ( 0 ) ;
if ( ! V_10 ) {
F_8 ( V_11 , V_16 ) ;
return - V_27 ;
}
F_11 ( V_7 , V_10 ) ;
F_12 ( V_10 , V_7 ) ;
V_10 -> V_28 = V_11 ;
V_10 -> V_13 = V_13 ;
V_2 = F_13 ( V_10 ) ;
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_3 ;
V_2 -> V_31 . clock . V_32 = V_33 / 2 ;
V_2 -> V_34 = V_35 | V_36 ;
V_2 -> V_37 = V_38 ;
for ( V_14 = 0 ; V_14 < F_14 ( V_39 ) ; V_14 ++ ) {
V_12 = V_39 [ V_14 ] ;
if ( ! F_6 ( V_12 , V_40 ,
F_7 ( V_7 ) ) )
continue;
F_4 ( V_41 | V_14 , V_11 + V_42 ) ;
V_2 -> V_4 = ( void V_43 * ) V_12 ;
if ( ! F_15 ( V_10 ) ) {
F_4 ( 0 , V_11 + V_44 ) ;
F_16 ( V_10 , L_2 ,
V_11 , V_12 , V_13 ) ;
return 0 ;
}
F_4 ( 0 , V_11 + V_42 ) ;
F_8 ( V_12 , V_40 ) ;
}
F_9 ( V_7 , L_3 ) ;
F_11 ( V_7 , NULL ) ;
F_17 ( V_10 ) ;
F_8 ( V_11 , V_16 ) ;
return - V_45 ;
}
static int F_18 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
unsigned long V_11 , V_12 ;
V_10 = F_19 ( V_7 ) ;
F_20 ( V_10 ) ;
F_11 ( V_7 , NULL ) ;
V_2 = F_13 ( V_10 ) ;
V_11 = V_10 -> V_28 ;
V_12 = ( unsigned long ) V_2 -> V_4 ;
F_4 ( 0 , V_11 + V_42 ) ;
F_8 ( V_12 , V_40 ) ;
F_8 ( V_11 , V_16 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_46 , V_47 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_46 ) ;
}
