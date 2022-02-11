static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_3 ( & V_4 -> V_5 -> V_6 ) ;
}
static T_2 T_3 F_4 ( void )
{
return F_3 ( & V_3 . V_5 -> V_6 ) ;
}
void T_4 F_5 ( unsigned long V_7 ,
unsigned int V_8 )
{
struct V_9 T_5 * V_5 ;
F_6 ( & V_3 . V_2 , F_7 ( V_8 ) ) ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_9 ( V_10 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( V_15 , & V_5 -> V_16 ) ;
F_9 ( 1 << V_17 , & V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
V_3 . V_5 = V_5 ;
F_10 ( F_4 , V_17 ,
F_7 ( V_8 ) ) ;
}
static void F_11 ( struct V_9 T_5 * V_5 )
{
F_9 ( V_10 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
}
static void F_12 ( enum V_20 V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
F_2 ( V_23 , struct V_24 , V_26 ) ;
struct V_9 T_5 * V_5 = V_25 -> V_5 ;
F_11 ( V_5 ) ;
switch ( V_21 ) {
case V_27 :
F_9 ( V_28 | V_15 ,
& V_5 -> V_16 ) ;
F_9 ( ( ( T_2 ) ( V_29 / V_30 ) * V_23 -> V_31 ) >>
V_23 -> V_32 ,
& V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
break;
case V_33 :
case V_34 :
F_9 ( 0 , & V_5 -> V_16 ) ;
break;
case V_35 :
F_9 ( V_28 , & V_5 -> V_16 ) ;
break;
case V_36 :
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
break;
}
}
static int F_13 ( unsigned long V_37 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
F_2 ( V_23 , struct V_24 , V_26 ) ;
struct V_9 T_5 * V_5 = V_25 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( V_37 , & V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
return 0 ;
}
static T_6 F_14 ( int V_38 , void * V_39 )
{
struct V_24 * V_25 = V_39 ;
struct V_22 * V_26 = & V_25 -> V_26 ;
struct V_9 T_5 * V_5 = V_25 -> V_5 ;
F_9 ( 0 , & V_5 -> V_12 ) ;
V_26 -> V_40 ( V_26 ) ;
return V_41 ;
}
void T_4 F_15 ( unsigned long V_7 , int V_38 ,
unsigned int V_8 )
{
struct V_22 * V_26 = & V_24 . V_26 ;
struct V_9 T_5 * V_5 ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_11 ( V_5 ) ;
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
V_24 . V_5 = V_5 ;
F_16 ( V_26 , F_7 ( V_8 ) ) ;
V_26 -> V_42 =
F_17 ( 0xffffffff >> ( 32 - V_43 ) , V_26 ) ;
V_26 -> V_44 = F_17 ( 0xf , V_26 ) ;
V_26 -> V_38 = V_38 ;
V_26 -> V_45 = F_18 ( 0 ) ,
F_19 ( V_26 ) ;
F_20 ( V_38 , & V_46 ) ;
F_21 ( V_47 L_1 ,
V_7 , V_38 ) ;
}
void T_4 F_22 ( unsigned long V_7 )
{
struct V_9 T_5 * V_5 ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_9 ( V_48 | V_19 , & V_5 -> V_11 ) ;
F_9 ( V_48 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
F_9 ( 0xffffffff , & V_5 -> V_18 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
F_9 ( 0 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_49 ) ;
F_23 ( V_5 ) ;
}
