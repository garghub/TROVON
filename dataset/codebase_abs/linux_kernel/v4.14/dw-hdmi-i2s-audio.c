static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_2 -> V_7 ( V_6 , V_3 , V_4 ) ;
}
static inline T_1 F_2 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return V_2 -> V_8 ( V_6 , V_4 ) ;
}
static int F_3 ( struct V_9 * V_10 , void * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = V_11 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
if ( ( V_13 -> V_13 != V_19 ) ||
( V_13 -> V_20 | V_13 -> V_21 ) ) {
F_4 ( V_10 , L_1 ) ;
return - V_22 ;
}
V_18 = V_23 ;
V_16 = V_24 ;
switch ( V_15 -> V_25 ) {
case 16 :
V_17 = V_26 ;
break;
case 24 :
case 32 :
V_17 = V_27 ;
break;
}
F_5 ( V_6 , V_15 -> V_28 ) ;
F_1 ( V_2 , V_18 , V_29 ) ;
F_1 ( V_2 , V_16 , V_30 ) ;
F_1 ( V_2 , V_17 , V_31 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_9 * V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_8 ( V_6 ) ;
F_1 ( V_2 , V_32 , V_30 ) ;
}
static int F_9 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 V_38 ;
int V_39 ;
V_39 = F_10 ( V_36 , & V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_38 . V_40 == 2 )
return 0 ;
return - V_22 ;
}
static int F_11 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_10 . V_43 ;
struct V_44 V_45 ;
struct V_46 V_47 ;
struct V_41 * V_48 ;
V_47 . V_49 = & V_50 ;
V_47 . V_51 = 1 ;
V_47 . V_52 = 6 ;
V_47 . V_11 = V_2 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_53 = V_42 -> V_10 . V_53 ;
V_45 . V_54 = V_55 ;
V_45 . V_56 = V_57 ;
V_45 . V_11 = & V_47 ;
V_45 . V_58 = sizeof( V_47 ) ;
V_45 . V_59 = F_12 ( 32 ) ;
V_48 = F_13 ( & V_45 ) ;
if ( F_14 ( V_48 ) )
return F_15 ( V_48 ) ;
F_16 ( & V_42 -> V_10 , V_48 ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_41 * V_48 = F_18 ( & V_42 -> V_10 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
