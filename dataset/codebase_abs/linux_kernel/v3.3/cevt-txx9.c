static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_3 ( & V_4 -> V_5 -> V_6 ) ;
}
void T_2 F_4 ( unsigned long V_7 ,
unsigned int V_8 )
{
struct V_9 T_3 * V_5 ;
F_5 ( & V_3 . V_2 , F_6 ( V_8 ) ) ;
V_5 = F_7 ( V_7 , sizeof( struct V_9 ) ) ;
F_8 ( V_10 , & V_5 -> V_11 ) ;
F_8 ( 0 , & V_5 -> V_12 ) ;
F_8 ( V_13 , & V_5 -> V_14 ) ;
F_8 ( V_15 , & V_5 -> V_16 ) ;
F_8 ( 1 << V_17 , & V_5 -> V_18 ) ;
F_8 ( V_10 | V_19 , & V_5 -> V_11 ) ;
V_3 . V_5 = V_5 ;
}
static void F_9 ( struct V_9 T_3 * V_5 )
{
F_8 ( V_10 , & V_5 -> V_11 ) ;
F_8 ( 0 , & V_5 -> V_12 ) ;
}
static void F_10 ( enum V_20 V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
F_2 ( V_23 , struct V_24 , V_26 ) ;
struct V_9 T_3 * V_5 = V_25 -> V_5 ;
F_9 ( V_5 ) ;
switch ( V_21 ) {
case V_27 :
F_8 ( V_28 | V_15 ,
& V_5 -> V_16 ) ;
F_8 ( ( ( V_29 ) ( V_30 / V_31 ) * V_23 -> V_32 ) >>
V_23 -> V_33 ,
& V_5 -> V_18 ) ;
F_8 ( V_10 | V_19 , & V_5 -> V_11 ) ;
break;
case V_34 :
case V_35 :
F_8 ( 0 , & V_5 -> V_16 ) ;
break;
case V_36 :
F_8 ( V_28 , & V_5 -> V_16 ) ;
break;
case V_37 :
F_8 ( V_13 , & V_5 -> V_14 ) ;
F_8 ( 0 , & V_5 -> V_16 ) ;
break;
}
}
static int F_11 ( unsigned long V_38 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
F_2 ( V_23 , struct V_24 , V_26 ) ;
struct V_9 T_3 * V_5 = V_25 -> V_5 ;
F_9 ( V_5 ) ;
F_8 ( V_38 , & V_5 -> V_18 ) ;
F_8 ( V_10 | V_19 , & V_5 -> V_11 ) ;
return 0 ;
}
static T_4 F_12 ( int V_39 , void * V_40 )
{
struct V_24 * V_25 = V_40 ;
struct V_22 * V_26 = & V_25 -> V_26 ;
struct V_9 T_3 * V_5 = V_25 -> V_5 ;
F_8 ( 0 , & V_5 -> V_12 ) ;
V_26 -> V_41 ( V_26 ) ;
return V_42 ;
}
void T_2 F_13 ( unsigned long V_7 , int V_39 ,
unsigned int V_8 )
{
struct V_22 * V_26 = & V_24 . V_26 ;
struct V_9 T_3 * V_5 ;
V_5 = F_7 ( V_7 , sizeof( struct V_9 ) ) ;
F_9 ( V_5 ) ;
F_8 ( V_13 , & V_5 -> V_14 ) ;
F_8 ( 0 , & V_5 -> V_16 ) ;
V_24 . V_5 = V_5 ;
F_14 ( V_26 , F_6 ( V_8 ) ) ;
V_26 -> V_43 =
F_15 ( 0xffffffff >> ( 32 - V_44 ) , V_26 ) ;
V_26 -> V_45 = F_15 ( 0xf , V_26 ) ;
V_26 -> V_39 = V_39 ;
V_26 -> V_46 = F_16 ( 0 ) ,
F_17 ( V_26 ) ;
F_18 ( V_39 , & V_47 ) ;
F_19 ( V_48 L_1 ,
V_7 , V_39 ) ;
}
void T_2 F_20 ( unsigned long V_7 )
{
struct V_9 T_3 * V_5 ;
V_5 = F_7 ( V_7 , sizeof( struct V_9 ) ) ;
F_8 ( V_49 | V_19 , & V_5 -> V_11 ) ;
F_8 ( V_49 , & V_5 -> V_11 ) ;
F_8 ( 0 , & V_5 -> V_12 ) ;
F_8 ( 0xffffffff , & V_5 -> V_18 ) ;
F_8 ( 0 , & V_5 -> V_16 ) ;
F_8 ( 0 , & V_5 -> V_14 ) ;
F_8 ( 0 , & V_5 -> V_50 ) ;
F_21 ( V_5 ) ;
}
