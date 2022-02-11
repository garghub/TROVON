static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned int V_11 ;
V_10 = F_4 ( V_2 -> V_12 . V_13 , 1 + 17 * 17 * 17 ) ;
if ( ! V_10 )
return - V_14 ;
F_5 ( V_10 , V_15 , 0 ) ;
for ( V_11 = 0 ; V_11 < 17 * 17 * 17 ; ++ V_11 )
F_5 ( V_10 , V_16 , V_8 -> V_17 . V_18 [ V_11 ] ) ;
F_6 ( & V_2 -> V_19 ) ;
F_7 ( V_2 -> V_2 , V_10 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_11 ( V_8 -> V_20 , struct V_1 , V_21 ) ;
switch ( V_8 -> V_22 ) {
case V_23 :
F_3 ( V_2 , V_8 ) ;
break;
case V_24 :
V_2 -> V_25 = V_8 -> V_26 ;
break;
}
return 0 ;
}
static int F_12 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
static const unsigned int V_33 [] = {
V_34 ,
V_35 ,
V_36 ,
} ;
return F_13 ( V_28 , V_30 , V_32 , V_33 ,
F_14 ( V_33 ) ) ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_37 * V_38 )
{
return F_16 ( V_28 , V_30 , V_38 , V_39 ,
V_39 , V_40 ,
V_40 ) ;
}
static int F_17 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_29 * V_43 ;
struct V_44 * V_45 ;
V_43 = F_19 ( & V_2 -> V_12 , V_30 , V_42 -> V_46 ) ;
if ( ! V_43 )
return - V_47 ;
if ( V_42 -> V_45 . V_32 != V_34 &&
V_42 -> V_45 . V_32 != V_35 &&
V_42 -> V_45 . V_32 != V_36 )
V_42 -> V_45 . V_32 = V_36 ;
V_45 = F_20 ( & V_2 -> V_12 , V_43 , V_42 -> V_48 ) ;
if ( V_42 -> V_48 == V_49 ) {
V_42 -> V_45 = * V_45 ;
return 0 ;
}
V_45 -> V_32 = V_42 -> V_45 . V_32 ;
V_45 -> V_50 = F_21 (unsigned int, fmt->format.width,
CLU_MIN_SIZE, CLU_MAX_SIZE) ;
V_45 -> V_51 = F_21 (unsigned int, fmt->format.height,
CLU_MIN_SIZE, CLU_MAX_SIZE) ;
V_45 -> V_52 = V_53 ;
V_45 -> V_54 = V_55 ;
V_42 -> V_45 = * V_45 ;
V_45 = F_20 ( & V_2 -> V_12 , V_43 ,
V_49 ) ;
* V_45 = V_42 -> V_45 ;
return 0 ;
}
static void F_22 ( struct V_56 * V_12 ,
struct V_57 * V_58 ,
struct V_3 * V_4 , bool V_59 )
{
struct V_1 * V_2 = F_18 ( & V_12 -> V_28 ) ;
struct V_9 * V_10 ;
unsigned long V_60 ;
T_1 V_8 = V_61 | V_62 | V_63 ;
if ( V_59 ) {
struct V_44 * V_45 ;
V_45 = F_20 ( & V_2 -> V_12 ,
V_2 -> V_12 . V_43 ,
V_64 ) ;
V_2 -> V_65 = V_45 -> V_32 == V_36 ;
return;
}
if ( V_2 -> V_25 == V_66 && V_2 -> V_65 )
V_8 |= V_67 | V_68
| V_69 | V_70
| V_71 | V_72 ;
F_1 ( V_2 , V_4 , V_73 , V_8 ) ;
F_23 ( & V_2 -> V_19 , V_60 ) ;
V_10 = V_2 -> V_2 ;
V_2 -> V_2 = NULL ;
F_24 ( & V_2 -> V_19 , V_60 ) ;
if ( V_10 )
F_25 ( V_4 , V_10 ) ;
}
struct V_1 * F_26 ( struct V_74 * V_13 )
{
struct V_1 * V_2 ;
int V_75 ;
V_2 = F_27 ( V_13 -> V_76 , sizeof( * V_2 ) , V_77 ) ;
if ( V_2 == NULL )
return F_28 ( - V_14 ) ;
F_29 ( & V_2 -> V_19 ) ;
V_2 -> V_12 . V_78 = & V_79 ;
V_2 -> V_12 . type = V_80 ;
V_75 = F_30 ( V_13 , & V_2 -> V_12 , L_1 , 2 , & V_81 ,
V_82 ) ;
if ( V_75 < 0 )
return F_28 ( V_75 ) ;
F_31 ( & V_2 -> V_21 , 2 ) ;
F_32 ( & V_2 -> V_21 , & V_83 , NULL ) ;
F_32 ( & V_2 -> V_21 , & V_84 , NULL ) ;
V_2 -> V_12 . V_28 . V_85 = & V_2 -> V_21 ;
if ( V_2 -> V_21 . error ) {
F_33 ( V_13 -> V_76 , L_2 ) ;
V_75 = V_2 -> V_21 . error ;
F_34 ( & V_2 -> V_12 ) ;
return F_28 ( V_75 ) ;
}
F_35 ( & V_2 -> V_21 ) ;
return V_2 ;
}
