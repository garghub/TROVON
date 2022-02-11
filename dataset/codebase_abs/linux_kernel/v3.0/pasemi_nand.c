static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
while ( V_4 > 0x800 ) {
F_2 ( V_3 , V_6 -> V_8 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_2 ( V_3 , V_6 -> V_8 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
while ( V_4 > 0x800 ) {
F_4 ( V_6 -> V_8 , V_3 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_4 ( V_6 -> V_8 , V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_9 ,
unsigned int V_10 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_9 == V_11 )
return;
if ( V_10 & V_12 )
F_6 ( V_6 -> V_13 + ( 1 << V_14 ) , V_9 ) ;
else
F_6 ( V_6 -> V_13 + ( 1 << V_15 ) , V_9 ) ;
F_7 () ;
F_8 ( V_16 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
return ! ! ( F_8 ( V_16 ) & V_17 ) ;
}
static int T_2 F_10 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 = V_19 -> V_24 . V_25 ;
struct V_26 V_27 ;
struct V_5 * V_6 ;
int V_28 = 0 ;
V_28 = F_11 ( V_23 , 0 , & V_27 ) ;
if ( V_28 )
return - V_29 ;
if ( V_30 )
return - V_31 ;
F_12 ( L_1 , & V_27 ) ;
V_30 = F_13 ( sizeof( struct V_1 ) +
sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_30 ) {
F_14 ( V_33
L_2 ) ;
V_28 = - V_34 ;
goto V_35;
}
V_6 = (struct V_5 * ) & V_30 [ 1 ] ;
V_30 -> V_7 = V_6 ;
V_30 -> V_36 = V_37 ;
V_6 -> V_8 = F_15 ( V_23 , 0 ) ;
V_6 -> V_13 = V_6 -> V_8 ;
if ( ! V_6 -> V_8 ) {
V_28 = - V_38 ;
goto V_39;
}
V_21 = F_16 ( V_40 , 0xa008 , NULL ) ;
if ( ! V_21 ) {
V_28 = - V_31 ;
goto V_41;
}
V_16 = F_17 ( V_21 , 0 ) ;
F_18 ( V_21 ) ;
if ( ! F_19 ( V_16 , 4 , V_42 ) ) {
V_28 = - V_43 ;
goto V_41;
}
V_6 -> V_44 = F_5 ;
V_6 -> V_45 = F_9 ;
V_6 -> V_46 = F_1 ;
V_6 -> V_47 = F_3 ;
V_6 -> V_48 = 0 ;
V_6 -> V_49 . V_50 = V_51 ;
V_6 -> V_52 = V_53 | V_54 ;
if ( F_20 ( V_30 , 1 ) ) {
V_28 = - V_55 ;
goto V_56;
}
if ( F_21 ( V_30 , NULL , 0 ) ) {
F_14 ( V_57 L_3 ) ;
V_28 = - V_31 ;
goto V_56;
}
F_14 ( V_58 L_4 ,
V_27 . V_59 , V_16 ) ;
return 0 ;
V_56:
F_22 ( V_16 , 4 ) ;
V_41:
F_23 ( V_6 -> V_8 ) ;
V_39:
F_24 ( V_30 ) ;
V_35:
return V_28 ;
}
static int T_3 F_25 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
if ( ! V_30 )
return 0 ;
V_6 = V_30 -> V_7 ;
F_26 ( V_30 ) ;
F_22 ( V_16 , 4 ) ;
F_23 ( V_6 -> V_8 ) ;
F_24 ( V_30 ) ;
V_30 = NULL ;
return 0 ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_60 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_60 ) ;
}
