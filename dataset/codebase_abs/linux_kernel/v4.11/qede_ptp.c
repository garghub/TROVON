static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
int V_9 ;
F_3 ( V_8 ) ;
if ( V_8 -> V_10 == V_11 ) {
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_14 ( V_8 -> V_15 , V_3 ) ;
F_5 ( & V_5 -> V_12 ) ;
} else {
F_6 ( V_8 , L_1 ) ;
V_9 = - V_16 ;
}
F_7 ( V_8 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_9 ( V_8 , V_18 , L_2 ,
V_17 ) ;
F_4 ( & V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_19 , V_17 ) ;
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_22 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_4 ( & V_5 -> V_12 ) ;
V_22 = F_12 ( & V_5 -> V_19 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_9 ( V_8 , V_18 , L_3 , V_22 ) ;
* V_21 = F_13 ( V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_22 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
V_22 = F_15 ( V_21 ) ;
F_9 ( V_8 , V_18 , L_4 , V_22 ) ;
F_4 ( & V_5 -> V_12 ) ;
F_16 ( & V_5 -> V_19 , & V_5 -> V_23 , V_22 ) ;
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
int V_26 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
V_8 = V_5 -> V_8 ;
F_6 ( V_8 , L_5 ) ;
return - V_27 ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_32 , V_22 ;
int V_9 ;
V_5 = F_2 ( V_29 , struct V_4 , V_29 ) ;
V_8 = V_5 -> V_8 ;
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_33 ( V_8 -> V_15 , & V_32 ) ;
F_5 ( & V_5 -> V_12 ) ;
if ( V_9 ) {
F_19 ( & V_5 -> V_29 ) ;
return;
}
V_22 = F_20 ( & V_5 -> V_19 , V_32 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = F_21 ( V_22 ) ;
F_22 ( V_5 -> V_35 , & V_31 ) ;
F_23 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
F_9 ( V_8 , V_18 ,
L_6 ,
V_32 , V_22 ) ;
}
static T_3 F_24 ( const struct V_36 * V_23 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
T_3 V_37 ;
int V_9 ;
V_5 = F_2 ( V_23 , struct V_4 , V_23 ) ;
V_8 = V_5 -> V_8 ;
V_9 = V_5 -> V_13 -> V_38 ( V_8 -> V_15 , & V_37 ) ;
if ( V_9 )
F_25 ( 1 , L_7 , V_9 ) ;
F_9 ( V_8 , V_18 , L_8 , V_37 ) ;
return V_37 ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
memset ( & V_5 -> V_23 , 0 , sizeof( V_5 -> V_23 ) ) ;
V_5 -> V_23 . V_39 = F_24 ;
V_5 -> V_23 . V_40 = F_27 ( 64 ) ;
V_5 -> V_23 . V_41 = 0 ;
V_5 -> V_23 . V_42 = 1 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_43 ;
if ( ! V_5 -> V_44 ) {
F_29 ( V_8 , L_9 ) ;
return 0 ;
}
switch ( V_5 -> V_45 ) {
case V_46 :
V_8 -> V_47 |= V_48 ;
V_5 -> V_13 -> V_49 ( V_8 -> V_15 ) ;
break;
case V_50 :
F_6 ( V_8 , L_10 ) ;
return - V_51 ;
}
F_4 ( & V_5 -> V_12 ) ;
switch ( V_5 -> V_52 ) {
case V_53 :
break;
case V_54 :
case V_55 :
V_5 -> V_52 = V_53 ;
break;
case V_56 :
case V_57 :
case V_58 :
V_5 -> V_52 = V_56 ;
V_5 -> V_13 -> V_59 ( V_8 -> V_15 , V_60 ) ;
break;
case V_61 :
case V_62 :
case V_63 :
V_5 -> V_52 = V_61 ;
V_5 -> V_13 -> V_59 ( V_8 -> V_15 , V_64 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
V_5 -> V_52 = V_65 ;
V_5 -> V_13 -> V_59 ( V_8 -> V_15 , V_68 ) ;
break;
case V_69 :
case V_70 :
case V_71 :
V_5 -> V_52 = V_69 ;
V_5 -> V_13 -> V_59 ( V_8 -> V_15 ,
V_72 ) ;
break;
}
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
int F_30 ( struct V_7 * V_8 , struct V_73 * V_74 )
{
struct V_75 V_76 ;
struct V_4 * V_5 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_43 ;
if ( F_31 ( & V_76 , V_74 -> V_77 , sizeof( V_76 ) ) )
return - V_16 ;
F_9 ( V_8 , V_18 ,
L_11 ,
V_76 . V_45 , V_76 . V_52 ) ;
if ( V_76 . V_47 ) {
F_6 ( V_8 , L_12 ) ;
return - V_78 ;
}
V_5 -> V_44 = 1 ;
V_5 -> V_45 = V_76 . V_45 ;
V_5 -> V_52 = V_76 . V_52 ;
V_9 = F_28 ( V_8 ) ;
if ( V_9 )
return V_9 ;
V_76 . V_52 = V_5 -> V_52 ;
return F_32 ( V_74 -> V_77 , & V_76 ,
sizeof( V_76 ) ) ? - V_16 : 0 ;
}
static void F_33 ( struct V_7 * V_8 , bool V_79 )
{
struct V_4 * V_5 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
F_34 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_80 ( V_8 -> V_15 ) ;
if ( V_9 ) {
F_6 ( V_8 , L_13 ) ;
return;
}
F_35 ( & V_5 -> V_29 , F_18 ) ;
if ( V_79 ) {
F_26 ( V_8 ) ;
F_16 ( & V_5 -> V_19 , & V_5 -> V_23 ,
F_36 ( F_37 () ) ) ;
}
F_9 ( V_8 , V_18 , L_14 ) ;
}
void F_38 ( struct V_7 * V_8 , bool V_79 )
{
F_33 ( V_8 , V_79 ) ;
F_28 ( V_8 ) ;
}
void F_39 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( V_5 && V_5 -> clock ) {
F_40 ( V_5 -> clock ) ;
V_5 -> clock = NULL ;
}
F_41 ( V_5 ) ;
V_8 -> V_5 = NULL ;
}
int F_42 ( struct V_7 * V_8 , struct V_81 * V_2 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return - V_43 ;
V_2 -> V_82 = V_83 |
V_84 |
V_85 |
V_86 |
V_87 |
V_88 ;
if ( V_5 -> clock )
V_2 -> V_89 = F_43 ( V_5 -> clock ) ;
else
V_2 -> V_89 = - 1 ;
V_2 -> V_90 = F_44 ( V_53 ) |
F_44 ( V_56 ) |
F_44 ( V_57 ) |
F_44 ( V_58 ) |
F_44 ( V_61 ) |
F_44 ( V_62 ) |
F_44 ( V_63 ) |
F_44 ( V_65 ) |
F_44 ( V_66 ) |
F_44 ( V_67 ) |
F_44 ( V_69 ) |
F_44 ( V_70 ) |
F_44 ( V_71 ) ;
V_2 -> V_91 = F_44 ( V_92 ) | F_44 ( V_46 ) ;
return 0 ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
F_46 ( & V_5 -> V_29 ) ;
if ( V_5 -> V_35 ) {
F_23 ( V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
}
F_4 ( & V_5 -> V_12 ) ;
V_5 -> V_13 -> V_93 ( V_8 -> V_15 ) ;
F_5 ( & V_5 -> V_12 ) ;
}
int F_47 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_48 ( sizeof( * V_5 ) , V_94 ) ;
if ( ! V_5 ) {
F_29 ( V_8 , L_15 ) ;
return - V_95 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_13 = V_8 -> V_13 -> V_5 ;
if ( ! V_5 -> V_13 ) {
F_41 ( V_5 ) ;
V_8 -> V_5 = NULL ;
F_6 ( V_8 , L_16 ) ;
return - V_43 ;
}
V_8 -> V_5 = V_5 ;
V_5 -> V_6 . V_96 = V_97 ;
snprintf ( V_5 -> V_6 . V_98 , 16 , L_17 , V_8 -> V_99 -> V_98 ) ;
V_5 -> V_6 . V_100 = V_101 ;
V_5 -> V_6 . V_102 = 0 ;
V_5 -> V_6 . V_103 = 0 ;
V_5 -> V_6 . V_104 = 0 ;
V_5 -> V_6 . V_105 = 0 ;
V_5 -> V_6 . V_14 = F_1 ;
V_5 -> V_6 . V_106 = F_8 ;
V_5 -> V_6 . V_107 = F_11 ;
V_5 -> V_6 . V_108 = F_14 ;
V_5 -> V_6 . V_80 = F_17 ;
V_5 -> clock = F_49 ( & V_5 -> V_6 , & V_8 -> V_109 -> V_110 ) ;
if ( F_50 ( V_5 -> clock ) ) {
V_5 -> clock = NULL ;
F_41 ( V_5 ) ;
V_8 -> V_5 = NULL ;
F_6 ( V_8 , L_16 ) ;
}
return 0 ;
}
void F_51 ( struct V_7 * V_8 , struct V_111 * V_112 )
{
struct V_4 * V_5 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
if ( F_52 ( ! ( V_8 -> V_47 & V_48 ) ) ) {
F_53 ( V_8 ,
L_18 ) ;
} else if ( F_52 ( V_5 -> V_35 ) ) {
F_53 ( V_8 ,
L_19 ) ;
} else {
F_54 ( V_112 ) -> V_113 |= V_114 ;
V_5 -> V_35 = F_55 ( V_112 ) ;
F_19 ( & V_5 -> V_29 ) ;
}
}
void F_56 ( struct V_7 * V_8 , struct V_111 * V_112 )
{
struct V_4 * V_5 ;
T_3 V_32 , V_22 ;
int V_9 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 )
return;
F_4 ( & V_5 -> V_12 ) ;
V_9 = V_5 -> V_13 -> V_115 ( V_8 -> V_15 , & V_32 ) ;
if ( V_9 ) {
F_5 ( & V_5 -> V_12 ) ;
F_29 ( V_8 , L_20 ) ;
return;
}
V_22 = F_20 ( & V_5 -> V_19 , V_32 ) ;
F_5 ( & V_5 -> V_12 ) ;
F_57 ( V_112 ) -> V_34 = F_21 ( V_22 ) ;
F_9 ( V_8 , V_18 ,
L_21 ,
V_32 , V_22 ) ;
}
