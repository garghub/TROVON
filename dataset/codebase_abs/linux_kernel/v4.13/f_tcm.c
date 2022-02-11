static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 )
{
int V_6 ;
if ( V_5 -> V_7 & V_8 )
return 0 ;
V_6 = F_4 ( V_5 -> V_9 , V_5 -> V_10 . V_11 , V_12 ) ;
if ( ! V_6 )
V_5 -> V_7 |= V_8 ;
return V_6 ;
}
static void F_5 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_16 * V_10 = V_11 -> V_17 ;
struct V_1 * V_5 = V_10 -> V_5 ;
F_6 ( & V_10 -> V_18 , 0 ) ;
if ( V_11 -> V_19 < 0 ) {
F_7 ( L_1 , V_20 , __LINE__ ) ;
return;
}
F_3 ( V_5 ) ;
}
static void F_8 ( struct V_1 * V_5 , struct V_16 * V_10 )
{
struct V_21 * V_22 = & V_5 -> V_23 . V_22 ;
int V_6 ;
unsigned int V_24 ;
V_24 = V_10 -> V_25 ;
V_22 -> V_26 = V_10 -> V_27 ;
V_22 -> V_28 = V_24 ;
V_5 -> V_23 . V_11 -> V_17 = V_10 ;
V_6 = F_4 ( V_5 -> V_29 , V_5 -> V_23 . V_11 , V_12 ) ;
if ( V_6 )
F_7 ( L_2 , V_20 , __LINE__ , V_6 ) ;
}
static void F_9 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_16 * V_10 = V_11 -> V_17 ;
struct V_1 * V_5 = V_10 -> V_5 ;
if ( V_11 -> V_19 < 0 )
F_7 ( L_1 , V_20 , __LINE__ ) ;
if ( V_10 -> V_30 ) {
if ( V_10 -> V_30 > V_14 -> V_31 ) {
V_11 -> V_32 = V_14 -> V_31 ;
V_10 -> V_30 -= V_14 -> V_31 ;
} else {
V_11 -> V_32 = V_10 -> V_30 ;
V_10 -> V_30 = 0 ;
}
F_4 ( V_14 , V_11 , V_12 ) ;
return;
}
F_8 ( V_5 , V_10 ) ;
}
static void F_10 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_23 . V_22 ;
struct V_15 * V_11 ;
struct V_13 * V_14 ;
V_22 -> V_33 = F_11 ( V_10 -> V_30 ) ;
if ( V_10 -> V_30 ) {
if ( V_10 -> V_34 ) {
V_14 = V_5 -> V_29 ;
V_11 = V_5 -> V_35 ;
} else {
V_14 = V_5 -> V_9 ;
V_11 = V_5 -> V_36 ;
}
if ( V_10 -> V_30 > V_5 -> V_29 -> V_31 ) {
V_11 -> V_32 = V_14 -> V_31 ;
V_10 -> V_30 -= V_14 -> V_31 ;
} else {
V_11 -> V_32 = V_10 -> V_30 ;
V_10 -> V_30 = 0 ;
}
V_11 -> V_37 = F_9 ;
V_11 -> V_17 = V_10 ;
V_11 -> V_38 = V_5 -> V_10 . V_38 ;
F_4 ( V_14 , V_11 , V_39 ) ;
} else {
F_8 ( V_5 , V_10 ) ;
}
}
static int F_12 ( struct V_16 * V_10 , bool V_40 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_21 * V_22 = & V_5 -> V_23 . V_22 ;
int V_6 ;
if ( V_10 -> V_18 . V_41 == V_42 ) {
if ( ! V_40 && V_10 -> V_30 ) {
V_10 -> V_25 = V_43 ;
F_10 ( V_10 ) ;
return 0 ;
}
V_22 -> V_26 = V_10 -> V_27 ;
V_22 -> V_33 = F_11 ( 0 ) ;
V_22 -> V_28 = V_43 ;
V_5 -> V_23 . V_11 -> V_17 = V_10 ;
V_6 = F_4 ( V_5 -> V_29 , V_5 -> V_23 . V_11 , V_39 ) ;
if ( V_6 )
F_7 ( L_2 , V_20 , __LINE__ , V_6 ) ;
} else {
V_10 -> V_25 = V_44 ;
F_10 ( V_10 ) ;
}
return 0 ;
}
static int F_13 ( struct V_16 * V_10 )
{
bool V_40 = false ;
if ( ! V_10 -> V_34 )
V_40 = true ;
return F_12 ( V_10 , V_40 ) ;
}
static void F_14 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_16 * V_10 = V_11 -> V_17 ;
if ( V_11 -> V_19 < 0 )
F_7 ( L_1 , V_20 , __LINE__ ) ;
F_12 ( V_10 , true ) ;
}
static int F_15 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_45 * V_46 = F_16 ( V_5 ) ;
int V_6 ;
if ( ! V_10 -> V_30 ) {
V_10 -> V_25 = V_47 ;
F_10 ( V_10 ) ;
return 0 ;
}
if ( ! V_46 -> V_48 ) {
V_10 -> V_49 = F_17 ( V_18 -> V_50 , V_12 ) ;
if ( ! V_10 -> V_49 )
return - V_51 ;
F_18 ( V_18 -> V_52 ,
V_18 -> V_53 ,
V_10 -> V_49 ,
V_18 -> V_50 ) ;
V_5 -> V_35 -> V_38 = V_10 -> V_49 ;
} else {
V_5 -> V_35 -> V_38 = NULL ;
V_5 -> V_35 -> V_54 = V_18 -> V_53 ;
V_5 -> V_35 -> V_55 = V_18 -> V_52 ;
}
V_5 -> V_35 -> V_37 = F_14 ;
V_5 -> V_35 -> V_32 = V_18 -> V_50 ;
V_5 -> V_35 -> V_17 = V_10 ;
V_6 = F_4 ( V_5 -> V_29 , V_5 -> V_35 , V_12 ) ;
if ( V_6 )
F_7 ( L_3 , V_20 , __LINE__ ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_45 * V_46 = F_16 ( V_5 ) ;
int V_6 ;
F_20 ( & V_10 -> V_56 ) ;
V_10 -> V_5 = V_5 ;
if ( ! V_10 -> V_30 ) {
V_10 -> V_25 = V_47 ;
return - V_57 ;
}
if ( ! V_46 -> V_48 ) {
V_10 -> V_49 = F_17 ( V_18 -> V_50 , V_39 ) ;
if ( ! V_10 -> V_49 )
return - V_51 ;
V_5 -> V_36 -> V_38 = V_10 -> V_49 ;
} else {
V_5 -> V_36 -> V_38 = NULL ;
V_5 -> V_36 -> V_54 = V_18 -> V_53 ;
V_5 -> V_36 -> V_55 = V_18 -> V_52 ;
}
V_5 -> V_36 -> V_37 = V_58 ;
V_5 -> V_36 -> V_32 = V_18 -> V_50 ;
V_5 -> V_36 -> V_17 = V_10 ;
V_6 = F_21 ( V_10 , V_5 -> V_36 ) ;
if ( V_6 )
goto V_59;
V_6 = F_4 ( V_5 -> V_9 , V_5 -> V_36 , V_39 ) ;
if ( V_6 )
F_7 ( L_3 , V_20 , __LINE__ ) ;
F_22 ( & V_10 -> V_56 ) ;
F_23 ( V_18 ) ;
V_59:
return V_6 ;
}
static void F_24 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_1 * V_5 = V_11 -> V_17 ;
int V_6 ;
V_5 -> V_7 &= ~ V_8 ;
if ( V_11 -> V_19 < 0 )
return;
V_6 = F_25 ( V_5 , V_11 -> V_38 , V_11 -> V_60 ) ;
if ( V_6 )
F_7 ( L_4 , V_20 , __LINE__ , V_6 ) ;
}
static int F_26 ( struct V_1 * V_5 )
{
int V_6 ;
V_5 -> V_35 = F_27 ( V_5 -> V_29 , V_39 ) ;
if ( ! V_5 -> V_35 )
goto V_61;
V_5 -> V_36 = F_27 ( V_5 -> V_9 , V_39 ) ;
if ( ! V_5 -> V_36 )
goto V_62;
V_5 -> V_10 . V_11 = F_27 ( V_5 -> V_9 , V_39 ) ;
if ( ! V_5 -> V_10 . V_11 )
goto V_63;
V_5 -> V_23 . V_11 = F_27 ( V_5 -> V_29 , V_39 ) ;
if ( ! V_5 -> V_23 . V_11 )
goto V_64;
V_5 -> V_23 . V_11 -> V_38 = & V_5 -> V_23 . V_22 ;
V_5 -> V_23 . V_11 -> V_32 = V_65 ;
V_5 -> V_23 . V_11 -> V_37 = F_5 ;
V_5 -> V_23 . V_22 . V_66 = F_11 ( V_67 ) ;
V_5 -> V_10 . V_38 = F_17 ( V_5 -> V_9 -> V_31 , V_39 ) ;
if ( ! V_5 -> V_10 . V_38 )
goto V_68;
V_5 -> V_10 . V_11 -> V_37 = F_24 ;
V_5 -> V_10 . V_11 -> V_38 = V_5 -> V_10 . V_38 ;
V_5 -> V_10 . V_11 -> V_32 = V_5 -> V_9 -> V_31 ;
V_5 -> V_10 . V_11 -> V_17 = V_5 ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 )
goto V_69;
return 0 ;
V_69:
F_28 ( V_5 -> V_10 . V_38 ) ;
V_5 -> V_10 . V_38 = NULL ;
V_68:
F_29 ( V_5 -> V_29 , V_5 -> V_23 . V_11 ) ;
V_64:
F_29 ( V_5 -> V_9 , V_5 -> V_10 . V_11 ) ;
V_5 -> V_10 . V_11 = NULL ;
V_63:
F_29 ( V_5 -> V_9 , V_5 -> V_36 ) ;
V_5 -> V_36 = NULL ;
V_62:
F_29 ( V_5 -> V_29 , V_5 -> V_35 ) ;
V_5 -> V_35 = NULL ;
V_61:
F_7 ( L_5 ) ;
return - V_51 ;
}
static void F_30 ( struct V_1 * V_5 )
{
if ( ! ( V_5 -> V_7 & V_70 ) )
return;
F_31 ( V_5 -> V_29 ) ;
F_31 ( V_5 -> V_9 ) ;
if ( ! V_5 -> V_35 )
return;
F_29 ( V_5 -> V_29 , V_5 -> V_35 ) ;
F_29 ( V_5 -> V_9 , V_5 -> V_36 ) ;
F_29 ( V_5 -> V_9 , V_5 -> V_10 . V_11 ) ;
F_29 ( V_5 -> V_29 , V_5 -> V_23 . V_11 ) ;
F_28 ( V_5 -> V_10 . V_38 ) ;
V_5 -> V_35 = NULL ;
V_5 -> V_36 = NULL ;
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_23 . V_11 = NULL ;
V_5 -> V_10 . V_38 = NULL ;
}
static void F_32 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
struct V_45 * V_46 = V_3 -> V_71 -> V_72 -> V_46 ;
int V_6 ;
V_5 -> V_7 = V_73 ;
F_33 ( V_46 , V_3 , V_5 -> V_29 ) ;
V_6 = F_34 ( V_5 -> V_29 ) ;
if ( V_6 )
goto V_74;
F_33 ( V_46 , V_3 , V_5 -> V_9 ) ;
V_6 = F_34 ( V_5 -> V_9 ) ;
if ( V_6 )
goto V_75;
V_6 = F_26 ( V_5 ) ;
if ( V_6 )
goto V_76;
V_5 -> V_7 |= V_70 ;
F_35 ( L_6 ) ;
return;
V_76:
F_31 ( V_5 -> V_9 ) ;
V_75:
F_31 ( V_5 -> V_29 ) ;
V_74:
V_5 -> V_7 = V_73 ;
}
static int F_36 ( struct V_2 * V_3 ,
const struct V_77 * V_78 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_79 * V_72 = V_3 -> V_71 -> V_72 ;
T_1 V_80 = F_37 ( V_78 -> V_81 ) ;
T_1 V_82 = F_37 ( V_78 -> V_83 ) ;
int V_84 ;
T_2 * V_85 ;
switch ( V_78 -> V_86 ) {
case V_87 :
if ( V_78 -> V_88 != ( V_89 | V_90 |
V_91 ) )
return - V_92 ;
if ( V_82 < 1 )
return - V_57 ;
if ( V_80 != 0 )
return - V_57 ;
V_84 = F_38 ( & V_5 -> V_93 -> V_94 ) ;
if ( ! V_84 ) {
F_7 ( L_7 ) ;
return - V_57 ;
}
V_84 -- ;
if ( V_84 > 0xf ) {
F_39 ( L_8 ) ;
V_84 = 0xf ;
}
V_85 = V_72 -> V_11 -> V_38 ;
* V_85 = V_84 ;
V_72 -> V_11 -> V_32 = 1 ;
return F_4 ( V_72 -> V_46 -> V_95 , V_72 -> V_11 , V_12 ) ;
case V_96 :
F_3 ( V_5 ) ;
return 0 ;
}
return - V_92 ;
}
static void F_40 ( struct V_1 * V_5 , struct V_97 * V_98 )
{
if ( ! V_98 -> V_99 )
return;
F_29 ( V_5 -> V_29 , V_98 -> V_99 ) ;
F_29 ( V_5 -> V_9 , V_98 -> V_100 ) ;
F_29 ( V_5 -> V_101 , V_98 -> V_102 ) ;
V_98 -> V_99 = NULL ;
V_98 -> V_100 = NULL ;
V_98 -> V_102 = NULL ;
}
static void F_41 ( struct V_1 * V_5 )
{
F_29 ( V_5 -> V_103 , V_5 -> V_10 . V_11 ) ;
F_28 ( V_5 -> V_10 . V_38 ) ;
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_10 . V_38 = NULL ;
}
static void F_42 ( struct V_1 * V_5 )
{
int V_104 ;
if ( ! ( V_5 -> V_7 & V_70 ) )
return;
F_31 ( V_5 -> V_29 ) ;
F_31 ( V_5 -> V_9 ) ;
F_31 ( V_5 -> V_101 ) ;
F_31 ( V_5 -> V_103 ) ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ )
F_40 ( V_5 , & V_5 -> V_98 [ V_104 ] ) ;
F_41 ( V_5 ) ;
}
static int F_43 ( struct V_16 * V_10 )
{
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_45 * V_46 = F_16 ( V_5 ) ;
struct V_97 * V_98 = V_10 -> V_98 ;
if ( ! V_46 -> V_48 ) {
V_10 -> V_49 = F_17 ( V_18 -> V_50 , V_12 ) ;
if ( ! V_10 -> V_49 )
return - V_51 ;
F_18 ( V_18 -> V_52 ,
V_18 -> V_53 ,
V_10 -> V_49 ,
V_18 -> V_50 ) ;
V_98 -> V_99 -> V_38 = V_10 -> V_49 ;
} else {
V_98 -> V_99 -> V_38 = NULL ;
V_98 -> V_99 -> V_54 = V_18 -> V_53 ;
V_98 -> V_99 -> V_55 = V_18 -> V_52 ;
}
V_98 -> V_99 -> V_37 = V_106 ;
V_98 -> V_99 -> V_32 = V_18 -> V_50 ;
V_98 -> V_99 -> V_17 = V_10 ;
V_10 -> V_107 = V_108 ;
return 0 ;
}
static void F_44 ( struct V_16 * V_10 )
{
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_109 * V_110 = & V_10 -> V_109 ;
struct V_97 * V_98 = V_10 -> V_98 ;
V_10 -> V_107 = V_111 ;
V_110 -> V_112 = V_113 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
V_110 -> V_115 = F_45 ( V_18 -> V_116 ) ;
V_110 -> V_19 = V_18 -> V_41 ;
V_98 -> V_102 -> V_17 = V_10 ;
V_98 -> V_102 -> V_32 = V_18 -> V_116 + 16 ;
V_98 -> V_102 -> V_38 = V_110 ;
V_98 -> V_102 -> V_37 = V_106 ;
}
static void V_106 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_16 * V_10 = V_11 -> V_17 ;
struct V_97 * V_98 = V_10 -> V_98 ;
struct V_1 * V_5 = V_10 -> V_5 ;
int V_6 ;
if ( V_11 -> V_19 < 0 )
goto V_59;
switch ( V_10 -> V_107 ) {
case V_117 :
V_6 = F_43 ( V_10 ) ;
if ( V_6 )
goto V_59;
V_6 = F_4 ( V_5 -> V_29 , V_98 -> V_99 , V_12 ) ;
if ( V_6 )
F_7 ( L_9 , V_20 , __LINE__ , V_6 ) ;
break;
case V_118 :
V_6 = F_21 ( V_10 , V_98 -> V_100 ) ;
if ( V_6 )
goto V_59;
V_6 = F_4 ( V_5 -> V_9 , V_98 -> V_100 , V_12 ) ;
if ( V_6 )
F_7 ( L_9 , V_20 , __LINE__ , V_6 ) ;
break;
case V_108 :
F_44 ( V_10 ) ;
V_6 = F_4 ( V_5 -> V_101 , V_98 -> V_102 ,
V_12 ) ;
if ( V_6 )
F_7 ( L_9 , V_20 , __LINE__ , V_6 ) ;
break;
case V_111 :
F_6 ( & V_10 -> V_18 , 0 ) ;
F_4 ( V_5 -> V_103 , V_5 -> V_10 . V_11 , V_12 ) ;
break;
default:
F_46 () ;
}
return;
V_59:
F_6 ( & V_10 -> V_18 , 0 ) ;
}
static int F_47 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_97 * V_98 = V_10 -> V_98 ;
struct V_109 * V_110 = & V_10 -> V_109 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
V_98 -> V_102 -> V_37 = V_106 ;
V_98 -> V_102 -> V_17 = V_10 ;
V_10 -> V_5 = V_5 ;
F_44 ( V_10 ) ;
return F_4 ( V_5 -> V_101 , V_98 -> V_102 , V_12 ) ;
}
static int F_48 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_97 * V_98 = V_10 -> V_98 ;
struct V_109 * V_110 = & V_10 -> V_109 ;
int V_6 ;
V_10 -> V_5 = V_5 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
if ( V_5 -> V_7 & V_119 ) {
V_6 = F_43 ( V_10 ) ;
if ( V_6 )
goto V_120;
V_6 = F_4 ( V_5 -> V_29 , V_98 -> V_99 , V_12 ) ;
if ( V_6 ) {
F_7 ( L_9 , V_20 , __LINE__ , V_6 ) ;
F_28 ( V_10 -> V_49 ) ;
V_10 -> V_49 = NULL ;
}
} else {
V_110 -> V_112 = V_121 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
V_98 -> V_102 -> V_37 = V_106 ;
V_98 -> V_102 -> V_17 = V_10 ;
V_10 -> V_107 = V_117 ;
V_98 -> V_102 -> V_38 = V_110 ;
V_98 -> V_102 -> V_32 = sizeof( struct V_110 ) ;
V_6 = F_4 ( V_5 -> V_101 , V_98 -> V_102 ,
V_12 ) ;
if ( V_6 )
F_7 ( L_9 , V_20 , __LINE__ , V_6 ) ;
}
V_120:
return V_6 ;
}
static int F_49 ( struct V_16 * V_10 )
{
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_97 * V_98 = V_10 -> V_98 ;
struct V_109 * V_110 = & V_10 -> V_109 ;
int V_6 ;
F_20 ( & V_10 -> V_56 ) ;
V_10 -> V_5 = V_5 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
if ( V_5 -> V_7 & V_119 ) {
V_6 = F_21 ( V_10 , V_98 -> V_100 ) ;
if ( V_6 )
goto V_59;
V_6 = F_4 ( V_5 -> V_9 , V_98 -> V_100 , V_12 ) ;
if ( V_6 )
F_7 ( L_3 , V_20 , __LINE__ ) ;
} else {
V_110 -> V_112 = V_122 ;
V_110 -> V_114 = F_45 ( V_10 -> V_114 ) ;
V_98 -> V_102 -> V_37 = V_106 ;
V_98 -> V_102 -> V_17 = V_10 ;
V_10 -> V_107 = V_118 ;
V_98 -> V_102 -> V_38 = V_110 ;
V_98 -> V_102 -> V_32 = sizeof( struct V_110 ) ;
V_6 = F_4 ( V_5 -> V_101 , V_98 -> V_102 ,
V_12 ) ;
if ( V_6 )
F_7 ( L_3 , V_20 , __LINE__ ) ;
}
F_22 ( & V_10 -> V_56 ) ;
F_23 ( V_18 ) ;
V_59:
return V_6 ;
}
static void F_50 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_1 * V_5 = V_11 -> V_17 ;
int V_6 ;
if ( V_11 -> V_19 < 0 )
return;
V_6 = F_51 ( V_5 , V_11 -> V_38 , V_11 -> V_60 ) ;
if ( ! V_6 )
return;
F_4 ( V_5 -> V_103 , V_5 -> V_10 . V_11 , V_12 ) ;
}
static int F_52 ( struct V_1 * V_5 , struct V_97 * V_98 )
{
V_98 -> V_99 = F_27 ( V_5 -> V_29 , V_39 ) ;
if ( ! V_98 -> V_99 )
goto V_120;
V_98 -> V_100 = F_27 ( V_5 -> V_9 , V_39 ) ;
if ( ! V_98 -> V_100 )
goto V_62;
V_98 -> V_102 = F_27 ( V_5 -> V_101 , V_39 ) ;
if ( ! V_98 -> V_102 )
goto V_64;
return 0 ;
V_64:
F_29 ( V_5 -> V_101 , V_98 -> V_102 ) ;
V_98 -> V_102 = NULL ;
V_62:
F_29 ( V_5 -> V_9 , V_98 -> V_100 ) ;
V_98 -> V_100 = NULL ;
V_120:
return - V_51 ;
}
static int F_53 ( struct V_1 * V_5 )
{
V_5 -> V_10 . V_11 = F_27 ( V_5 -> V_103 , V_39 ) ;
if ( ! V_5 -> V_10 . V_11 )
goto V_61;
V_5 -> V_10 . V_38 = F_17 ( V_5 -> V_103 -> V_31 , V_39 ) ;
if ( ! V_5 -> V_10 . V_38 )
goto V_68;
V_5 -> V_10 . V_11 -> V_37 = F_50 ;
V_5 -> V_10 . V_11 -> V_38 = V_5 -> V_10 . V_38 ;
V_5 -> V_10 . V_11 -> V_32 = V_5 -> V_103 -> V_31 ;
V_5 -> V_10 . V_11 -> V_17 = V_5 ;
return 0 ;
V_68:
F_29 ( V_5 -> V_103 , V_5 -> V_10 . V_11 ) ;
V_61:
return - V_51 ;
}
static void F_54 ( struct V_1 * V_5 , int V_123 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_123 ; V_104 ++ ) {
struct V_97 * V_124 = & V_5 -> V_98 [ V_104 ] ;
V_124 -> V_99 -> V_125 = V_104 + 1 ;
V_124 -> V_100 -> V_125 = V_104 + 1 ;
V_124 -> V_102 -> V_125 = V_104 + 1 ;
}
}
static int F_55 ( struct V_1 * V_5 )
{
int V_6 ;
int V_104 ;
int V_123 ;
if ( V_5 -> V_7 & V_119 )
V_123 = V_105 ;
else
V_123 = 1 ;
for ( V_104 = 0 ; V_104 < V_123 ; V_104 ++ ) {
V_6 = F_52 ( V_5 , & V_5 -> V_98 [ V_104 ] ) ;
if ( V_6 )
goto V_126;
}
V_6 = F_53 ( V_5 ) ;
if ( V_6 )
goto V_127;
F_54 ( V_5 , V_123 ) ;
V_6 = F_4 ( V_5 -> V_103 , V_5 -> V_10 . V_11 , V_12 ) ;
if ( V_6 )
goto V_127;
return 0 ;
V_127:
F_41 ( V_5 ) ;
V_126:
if ( V_104 ) {
do {
F_40 ( V_5 , & V_5 -> V_98 [ V_104 - 1 ] ) ;
V_104 -- ;
} while ( V_104 );
}
F_7 ( L_10 ) ;
return V_6 ;
}
static void F_56 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
struct V_45 * V_46 = V_3 -> V_71 -> V_72 -> V_46 ;
int V_6 ;
V_5 -> V_7 = V_128 ;
if ( V_46 -> V_129 == V_130 )
V_5 -> V_7 |= V_119 ;
F_33 ( V_46 , V_3 , V_5 -> V_29 ) ;
V_6 = F_34 ( V_5 -> V_29 ) ;
if ( V_6 )
goto V_74;
F_33 ( V_46 , V_3 , V_5 -> V_9 ) ;
V_6 = F_34 ( V_5 -> V_9 ) ;
if ( V_6 )
goto V_75;
F_33 ( V_46 , V_3 , V_5 -> V_103 ) ;
V_6 = F_34 ( V_5 -> V_103 ) ;
if ( V_6 )
goto V_63;
F_33 ( V_46 , V_3 , V_5 -> V_101 ) ;
V_6 = F_34 ( V_5 -> V_101 ) ;
if ( V_6 )
goto V_131;
V_6 = F_55 ( V_5 ) ;
if ( V_6 )
goto V_76;
V_5 -> V_7 |= V_70 ;
F_35 ( L_11 ) ;
return;
V_76:
F_31 ( V_5 -> V_101 ) ;
V_131:
F_31 ( V_5 -> V_103 ) ;
V_63:
F_31 ( V_5 -> V_9 ) ;
V_75:
F_31 ( V_5 -> V_29 ) ;
V_74:
V_5 -> V_7 = 0 ;
}
static int F_57 ( const unsigned char * V_132 )
{
int V_6 ;
switch ( V_132 [ 0 ] ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
V_6 = V_152 ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
V_6 = V_165 ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_6 = V_176 ;
break;
default:
#define F_58 "target: Unknown data direction for SCSI Opcode 0x%02x\n"
F_59 ( F_58 , V_132 [ 0 ] ) ;
#undef F_58
V_6 = - V_57 ;
}
return V_6 ;
}
static void V_58 ( struct V_13 * V_14 , struct V_15 * V_11 )
{
struct V_16 * V_10 = V_11 -> V_17 ;
struct V_18 * V_18 = & V_10 -> V_18 ;
if ( V_11 -> V_19 < 0 ) {
F_7 ( L_12 , V_20 , V_10 -> V_107 ) ;
goto V_59;
}
if ( V_11 -> V_54 == 0 ) {
F_60 ( V_18 -> V_52 ,
V_18 -> V_53 ,
V_10 -> V_49 ,
V_18 -> V_50 ) ;
}
V_37 ( & V_10 -> V_56 ) ;
return;
V_59:
F_6 ( & V_10 -> V_18 , 0 ) ;
}
static int F_21 ( struct V_16 * V_10 , struct V_15 * V_11 )
{
struct V_18 * V_18 = & V_10 -> V_18 ;
struct V_1 * V_5 = V_10 -> V_5 ;
struct V_45 * V_46 = F_16 ( V_5 ) ;
if ( ! V_46 -> V_48 ) {
V_10 -> V_49 = F_17 ( V_18 -> V_50 , V_12 ) ;
if ( ! V_10 -> V_49 )
return - V_51 ;
V_11 -> V_38 = V_10 -> V_49 ;
} else {
V_11 -> V_38 = NULL ;
V_11 -> V_54 = V_18 -> V_53 ;
V_11 -> V_55 = V_18 -> V_52 ;
}
V_11 -> V_37 = V_58 ;
V_11 -> V_32 = V_18 -> V_50 ;
V_11 -> V_17 = V_10 ;
return 0 ;
}
static int F_61 ( struct V_18 * V_18 )
{
struct V_16 * V_10 = F_2 ( V_18 , struct V_16 ,
V_18 ) ;
struct V_1 * V_5 = V_10 -> V_5 ;
if ( V_5 -> V_7 & V_73 )
return F_13 ( V_10 ) ;
else
return F_47 ( V_10 ) ;
}
static int F_62 ( struct V_18 * V_18 )
{
struct V_16 * V_10 = F_2 ( V_18 , struct V_16 ,
V_18 ) ;
struct V_1 * V_5 = V_10 -> V_5 ;
if ( V_5 -> V_7 & V_73 )
return F_19 ( V_10 ) ;
else
return F_49 ( V_10 ) ;
}
static int F_63 ( struct V_18 * V_18 )
{
struct V_16 * V_10 = F_2 ( V_18 , struct V_16 ,
V_18 ) ;
struct V_1 * V_5 = V_10 -> V_5 ;
if ( V_5 -> V_7 & V_73 )
return F_15 ( V_10 ) ;
else
return F_48 ( V_10 ) ;
}
static void F_64 ( struct V_177 * V_178 )
{
struct V_16 * V_10 = F_2 ( V_178 , struct V_16 , V_178 ) ;
struct V_18 * V_18 ;
struct V_179 * V_180 ;
struct V_181 * V_93 ;
int V_182 , V_7 = ( V_183 | V_184 ) ;
V_18 = & V_10 -> V_18 ;
V_93 = V_10 -> V_5 -> V_93 ;
V_180 = V_93 -> V_185 ;
V_182 = F_57 ( V_10 -> V_186 ) ;
if ( V_182 < 0 ) {
F_65 ( V_18 ,
V_180 -> V_187 -> V_188 -> V_189 ,
V_180 -> V_187 , V_10 -> V_30 , V_176 ,
V_10 -> V_190 , V_10 -> V_109 . V_191 ) ;
goto V_120;
}
if ( F_66 ( V_18 , V_180 -> V_187 , V_10 -> V_186 ,
V_10 -> V_109 . V_191 , V_10 -> V_192 , 0 ,
V_10 -> V_190 , V_182 , V_7 ) < 0 )
goto V_120;
return;
V_120:
F_67 ( V_18 ,
V_193 , 1 ) ;
F_6 ( & V_10 -> V_18 , 0 ) ;
}
static struct V_16 * F_68 ( struct V_1 * V_5 ,
struct V_179 * V_180 , T_3 V_194 )
{
struct V_195 * V_196 = V_180 -> V_187 ;
struct V_16 * V_10 ;
int V_114 ;
V_114 = F_69 ( & V_196 -> V_197 , V_198 ) ;
if ( V_114 < 0 )
return F_70 ( - V_51 ) ;
V_10 = & ( (struct V_16 * ) V_196 -> V_199 ) [ V_114 ] ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_18 . V_200 = V_114 ;
V_10 -> V_18 . V_114 = V_10 -> V_114 = V_194 ;
V_10 -> V_5 = V_5 ;
return V_10 ;
}
static int F_51 ( struct V_1 * V_5 ,
void * V_201 , unsigned int V_115 )
{
struct V_202 * V_203 = V_201 ;
struct V_16 * V_10 ;
struct V_181 * V_93 = V_5 -> V_93 ;
struct V_179 * V_180 = V_93 -> V_185 ;
T_3 V_204 ;
T_1 V_194 ;
if ( V_203 -> V_112 != V_205 ) {
F_7 ( L_13 , V_203 -> V_112 ) ;
return - V_57 ;
}
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
F_7 ( L_14 ) ;
return - V_57 ;
}
V_204 = ( V_203 -> V_115 & ~ 0x3 ) + 16 ;
if ( V_204 > V_206 )
return - V_57 ;
V_194 = F_71 ( & V_203 -> V_114 ) ;
V_10 = F_68 ( V_5 , V_180 , V_194 ) ;
if ( F_72 ( V_10 ) ) {
F_7 ( L_15 ) ;
return - V_51 ;
}
memcpy ( V_10 -> V_186 , V_203 -> V_132 , V_204 ) ;
if ( V_5 -> V_7 & V_119 ) {
if ( V_10 -> V_114 > V_105 )
goto V_61;
if ( ! V_10 -> V_114 )
V_10 -> V_98 = & V_5 -> V_98 [ 0 ] ;
else
V_10 -> V_98 = & V_5 -> V_98 [ V_10 -> V_114 - 1 ] ;
} else {
V_10 -> V_98 = & V_5 -> V_98 [ 0 ] ;
}
switch ( V_203 -> V_190 & 0x7 ) {
case V_207 :
V_10 -> V_190 = V_208 ;
break;
case V_209 :
V_10 -> V_190 = V_210 ;
break;
case V_211 :
V_10 -> V_190 = V_212 ;
break;
default:
F_73 ( L_16 ,
V_203 -> V_190 ) ;
case V_213 :
V_10 -> V_190 = V_214 ;
break;
}
V_10 -> V_192 = F_74 ( & V_203 -> V_215 ) ;
F_75 ( & V_10 -> V_178 , F_64 ) ;
F_76 ( V_93 -> V_216 , & V_10 -> V_178 ) ;
return 0 ;
V_61:
F_77 ( & V_10 -> V_18 ) ;
return - V_57 ;
}
static void F_78 ( struct V_177 * V_178 )
{
struct V_16 * V_10 = F_2 ( V_178 , struct V_16 , V_178 ) ;
struct V_18 * V_18 ;
struct V_179 * V_180 ;
struct V_181 * V_93 ;
int V_182 ;
V_18 = & V_10 -> V_18 ;
V_93 = V_10 -> V_5 -> V_93 ;
V_180 = V_93 -> V_185 ;
V_182 = F_57 ( V_10 -> V_186 ) ;
if ( V_182 < 0 ) {
F_65 ( V_18 ,
V_180 -> V_187 -> V_188 -> V_189 ,
V_180 -> V_187 , V_10 -> V_30 , V_176 ,
V_10 -> V_190 , V_10 -> V_109 . V_191 ) ;
goto V_120;
}
if ( F_66 ( V_18 , V_180 -> V_187 ,
V_10 -> V_186 , V_10 -> V_109 . V_191 , V_10 -> V_192 ,
V_10 -> V_30 , V_10 -> V_190 , V_182 , 0 ) < 0 )
goto V_120;
return;
V_120:
F_67 ( V_18 ,
V_193 , 1 ) ;
F_6 ( & V_10 -> V_18 , 0 ) ;
}
static int F_25 ( struct V_1 * V_5 ,
void * V_201 , unsigned int V_115 )
{
struct V_217 * V_218 = V_201 ;
struct V_16 * V_10 ;
struct V_181 * V_93 = V_5 -> V_93 ;
struct V_179 * V_180 ;
T_3 V_204 ;
if ( V_218 -> V_66 != F_11 ( V_219 ) ) {
F_7 ( L_17 ) ;
return - V_57 ;
}
if ( V_115 != 31 ) {
F_7 ( L_18 ) ;
return - V_57 ;
}
V_204 = V_218 -> V_220 ;
if ( V_204 < 1 || V_204 > 16 )
return - V_57 ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
F_7 ( L_14 ) ;
return - V_221 ;
}
V_10 = F_68 ( V_5 , V_180 , V_218 -> V_26 ) ;
if ( F_72 ( V_10 ) ) {
F_7 ( L_15 ) ;
return - V_51 ;
}
memcpy ( V_10 -> V_186 , V_218 -> V_222 , V_204 ) ;
V_10 -> V_27 = V_218 -> V_26 ;
V_10 -> V_190 = V_214 ;
V_10 -> V_192 = V_218 -> V_223 ;
V_10 -> V_34 = V_218 -> V_224 & V_225 ? 1 : 0 ;
V_10 -> V_30 = F_79 ( V_218 -> V_226 ) ;
V_10 -> V_18 . V_114 = F_79 ( V_10 -> V_27 ) ;
F_75 ( & V_10 -> V_178 , F_78 ) ;
F_76 ( V_93 -> V_216 , & V_10 -> V_178 ) ;
return 0 ;
}
static int F_80 ( struct V_227 * V_188 )
{
return 1 ;
}
static int F_81 ( struct V_227 * V_188 )
{
return 0 ;
}
static char * F_82 ( void )
{
return L_19 ;
}
static char * F_83 ( struct V_227 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
struct V_228 * V_229 = V_93 -> V_229 ;
return & V_229 -> V_230 [ 0 ] ;
}
static T_1 F_84 ( struct V_227 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
return V_93 -> V_231 ;
}
static T_3 F_85 ( struct V_227 * V_188 )
{
return 1 ;
}
static void F_77 ( struct V_18 * V_18 )
{
struct V_16 * V_10 = F_2 ( V_18 , struct V_16 ,
V_18 ) ;
struct V_195 * V_196 = V_18 -> V_196 ;
F_28 ( V_10 -> V_49 ) ;
F_86 ( & V_196 -> V_197 , V_18 -> V_200 ) ;
}
static T_3 F_87 ( struct V_195 * V_196 )
{
return 0 ;
}
static int F_88 ( struct V_18 * V_18 )
{
return 0 ;
}
static void F_89 ( struct V_232 * V_233 )
{
}
static int F_90 ( struct V_18 * V_18 )
{
return 0 ;
}
static void F_91 ( struct V_18 * V_18 )
{
}
static void F_92 ( struct V_18 * V_18 )
{
}
static const char * F_93 ( const char * V_234 )
{
const char * V_235 ;
unsigned int V_115 ;
V_235 = strstr ( V_234 , L_20 ) ;
if ( ! V_235 )
return NULL ;
V_235 += 4 ;
V_115 = strlen ( V_235 ) ;
if ( V_115 == 0 || V_115 > V_236 - 1 )
return NULL ;
return V_235 ;
}
static int F_94 ( struct V_232 * V_237 , const char * V_234 )
{
if ( ! F_93 ( V_234 ) )
return - V_57 ;
return 0 ;
}
static struct V_227 * F_95 (
struct V_238 * V_239 ,
struct V_240 * V_241 ,
const char * V_234 )
{
struct V_228 * V_229 = F_2 ( V_239 , struct V_228 ,
V_242 ) ;
struct V_181 * V_93 ;
unsigned long V_243 ;
int V_6 ;
struct V_244 * V_245 ;
unsigned V_104 ;
if ( strstr ( V_234 , L_21 ) != V_234 )
return F_70 ( - V_57 ) ;
if ( F_96 ( V_234 + 5 , 0 , & V_243 ) || V_243 > V_246 )
return F_70 ( - V_57 ) ;
V_6 = - V_221 ;
F_97 ( & V_247 ) ;
for ( V_104 = 0 ; V_104 < V_248 ; ++ V_104 )
if ( V_249 [ V_104 ] . V_250 && ! V_249 [ V_104 ] . V_93 )
break;
if ( V_104 == V_248 )
goto V_251;
V_245 = F_2 ( V_249 [ V_104 ] . V_250 , struct V_244 ,
V_250 ) ;
F_97 ( & V_245 -> V_252 ) ;
if ( ! V_245 -> V_253 )
goto V_254;
if ( V_245 -> V_255 ) {
if ( ! F_98 ( V_245 -> V_256 ) )
goto V_254;
} else {
V_6 = F_99 (
V_241 -> V_257 ,
& V_245 -> V_250 . V_241 . V_258 ) ;
if ( V_6 )
goto V_254;
}
V_93 = F_100 ( sizeof( struct V_181 ) , V_39 ) ;
V_6 = - V_51 ;
if ( ! V_93 )
goto V_259;
F_101 ( & V_93 -> V_260 ) ;
F_102 ( & V_93 -> V_94 , 0 ) ;
V_93 -> V_216 = F_103 ( L_22 , 0 , 1 ) ;
if ( ! V_93 -> V_216 )
goto V_261;
V_93 -> V_229 = V_229 ;
V_93 -> V_231 = V_243 ;
V_6 = F_104 ( V_239 , & V_93 -> V_188 , V_262 ) ;
if ( V_6 < 0 )
goto V_263;
V_249 [ V_104 ] . V_93 = V_93 ;
V_93 -> V_264 = V_249 [ V_104 ] . V_250 ;
F_105 ( & V_245 -> V_252 ) ;
F_105 ( & V_247 ) ;
return & V_93 -> V_188 ;
V_263:
F_106 ( V_93 -> V_216 ) ;
V_261:
F_28 ( V_93 ) ;
V_259:
if ( V_245 -> V_255 )
F_107 ( V_245 -> V_256 ) ;
else
F_108 ( & V_245 -> V_250 . V_241 . V_258 ) ;
V_254:
F_105 ( & V_245 -> V_252 ) ;
V_251:
F_105 ( & V_247 ) ;
return F_70 ( V_6 ) ;
}
static void F_109 ( struct V_227 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
unsigned V_104 ;
struct V_244 * V_245 ;
F_110 ( V_93 ) ;
F_111 ( V_188 ) ;
F_106 ( V_93 -> V_216 ) ;
F_97 ( & V_247 ) ;
for ( V_104 = 0 ; V_104 < V_248 ; ++ V_104 )
if ( V_249 [ V_104 ] . V_93 == V_93 )
break;
if ( V_104 < V_248 ) {
V_249 [ V_104 ] . V_93 = NULL ;
V_245 = F_2 ( V_249 [ V_104 ] . V_250 ,
struct V_244 , V_250 ) ;
F_97 ( & V_245 -> V_252 ) ;
if ( V_245 -> V_255 )
F_107 ( V_245 -> V_256 ) ;
else
F_108 (
& V_245 -> V_250 . V_241 . V_258 ) ;
F_105 ( & V_245 -> V_252 ) ;
}
F_105 ( & V_247 ) ;
F_28 ( V_93 ) ;
}
static struct V_238 * F_112 (
struct V_265 * V_266 ,
struct V_240 * V_241 ,
const char * V_234 )
{
struct V_228 * V_229 ;
const char * V_267 ;
T_4 V_268 = 0 ;
V_267 = F_93 ( V_234 ) ;
if ( ! V_267 )
return F_70 ( - V_57 ) ;
V_229 = F_100 ( sizeof( struct V_228 ) , V_39 ) ;
if ( ! ( V_229 ) )
return F_70 ( - V_51 ) ;
V_229 -> V_269 = V_268 ;
snprintf ( V_229 -> V_230 , sizeof( V_229 -> V_230 ) , L_23 , V_267 ) ;
return & V_229 -> V_242 ;
}
static void F_113 ( struct V_238 * V_239 )
{
struct V_228 * V_229 = F_2 ( V_239 ,
struct V_228 , V_242 ) ;
F_28 ( V_229 ) ;
}
static T_5 F_114 ( struct V_270 * V_271 , char * V_272 )
{
return sprintf ( V_272 , L_24 ) ;
}
static T_5 F_115 ( struct V_270 * V_271 , char * V_272 )
{
struct V_227 * V_188 = F_116 ( V_271 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
return snprintf ( V_272 , V_273 , L_25 , V_93 -> V_274 ) ;
}
static T_5 F_117 ( struct V_270 * V_271 ,
const char * V_272 , T_6 V_275 )
{
struct V_227 * V_188 = F_116 ( V_271 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
bool V_276 ;
T_5 V_6 ;
V_6 = F_118 ( V_272 , & V_276 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_276 && V_93 -> V_274 ) || ( ! V_276 && ! V_93 -> V_274 ) )
return - V_57 ;
if ( V_276 )
V_6 = F_119 ( V_93 ) ;
else
F_120 ( V_93 ) ;
if ( V_6 )
return V_6 ;
V_93 -> V_274 = V_276 ;
return V_275 ;
}
static T_5 F_121 ( struct V_270 * V_271 , char * V_272 )
{
struct V_227 * V_188 = F_116 ( V_271 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
struct V_179 * V_180 ;
T_5 V_6 ;
F_97 ( & V_93 -> V_260 ) ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
V_6 = - V_221 ;
goto V_120;
}
V_6 = snprintf ( V_272 , V_273 , L_26 ,
V_180 -> V_187 -> V_232 -> V_277 ) ;
V_120:
F_105 ( & V_93 -> V_260 ) ;
return V_6 ;
}
static int F_122 ( struct V_227 * V_188 ,
struct V_195 * V_196 , void * V_278 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
V_93 -> V_185 = V_278 ;
return 0 ;
}
static int F_123 ( struct V_181 * V_93 , char * V_234 )
{
struct V_179 * V_180 ;
int V_6 = 0 ;
F_97 ( & V_93 -> V_260 ) ;
if ( V_93 -> V_185 ) {
V_6 = - V_279 ;
F_124 ( L_27 ) ;
goto V_280;
}
V_180 = F_100 ( sizeof( * V_180 ) , V_39 ) ;
if ( ! V_180 ) {
V_6 = - V_51 ;
goto V_280;
}
V_180 -> V_187 = F_125 ( & V_93 -> V_188 ,
V_281 ,
sizeof( struct V_16 ) ,
V_282 , V_234 ,
V_180 , F_122 ) ;
if ( F_72 ( V_180 -> V_187 ) ) {
#define F_126 "core_tpg_check_initiator_node_acl() failed for %s\n"
F_124 ( F_126 , V_234 ) ;
#undef F_126
V_6 = F_127 ( V_180 -> V_187 ) ;
F_28 ( V_180 ) ;
}
V_280:
F_105 ( & V_93 -> V_260 ) ;
return V_6 ;
}
static int F_110 ( struct V_181 * V_93 )
{
struct V_195 * V_196 ;
struct V_179 * V_180 ;
int V_6 = - V_221 ;
F_97 ( & V_93 -> V_260 ) ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 )
goto V_120;
V_196 = V_180 -> V_187 ;
if ( ! V_196 )
goto V_120;
if ( F_38 ( & V_93 -> V_94 ) ) {
V_6 = - V_283 ;
#define F_128 "Unable to remove Host I_T Nexus with active TPG port count: %d\n"
F_7 ( F_128 , F_38 ( & V_93 -> V_94 ) ) ;
#undef F_128
goto V_120;
}
F_124 ( L_28 ,
V_180 -> V_187 -> V_232 -> V_277 ) ;
F_129 ( V_180 -> V_187 ) ;
V_93 -> V_185 = NULL ;
F_28 ( V_180 ) ;
V_6 = 0 ;
V_120:
F_105 ( & V_93 -> V_260 ) ;
return V_6 ;
}
static T_5 F_130 ( struct V_270 * V_271 ,
const char * V_272 , T_6 V_275 )
{
struct V_227 * V_188 = F_116 ( V_271 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
unsigned char V_284 [ V_236 ] , * V_285 ;
int V_6 ;
if ( ! strncmp ( V_272 , L_29 , 4 ) ) {
V_6 = F_110 ( V_93 ) ;
return ( ! V_6 ) ? V_275 : V_6 ;
}
if ( strlen ( V_272 ) >= V_236 ) {
#define F_131 "Emulated NAA Sas Address: %s, exceeds max: %d\n"
F_7 ( F_131 , V_272 , V_236 ) ;
#undef F_131
return - V_57 ;
}
snprintf ( V_284 , V_236 , L_23 , V_272 ) ;
V_285 = strstr ( V_284 , L_20 ) ;
if ( ! V_285 ) {
F_7 ( L_30 ) ;
return - V_57 ;
}
if ( V_284 [ strlen ( V_284 ) - 1 ] == '\n' )
V_284 [ strlen ( V_284 ) - 1 ] = '\0' ;
V_6 = F_123 ( V_93 , & V_284 [ 0 ] ) ;
if ( V_6 < 0 )
return V_6 ;
return V_275 ;
}
static int F_132 ( struct V_227 * V_188 , struct V_286 * V_215 )
{
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
F_133 ( & V_93 -> V_94 ) ;
F_134 () ;
return 0 ;
}
static void F_135 ( struct V_227 * V_188 ,
struct V_286 * V_286 )
{
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
F_136 ( & V_93 -> V_94 ) ;
F_134 () ;
}
static int F_137 ( struct V_18 * V_18 )
{
return F_138 ( V_18 ) ;
}
static int F_139 ( struct V_287 * V_288 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_289 * V_290 ;
struct V_45 * V_46 = V_288 -> V_72 -> V_46 ;
struct V_13 * V_14 ;
struct V_244 * V_245 ;
int V_291 ;
int V_6 ;
V_245 = F_2 ( V_3 -> V_264 , struct V_244 , V_250 ) ;
F_97 ( & V_245 -> V_252 ) ;
if ( ! V_245 -> V_292 ) {
F_105 ( & V_245 -> V_252 ) ;
return - V_221 ;
}
F_105 ( & V_245 -> V_252 ) ;
V_290 = F_140 ( V_288 -> V_72 , V_293 ,
F_141 ( V_294 ) ) ;
if ( F_72 ( V_290 ) )
return F_127 ( V_290 ) ;
V_295 . V_296 = V_290 [ V_297 ] . V_298 ;
V_299 . V_296 = V_290 [ V_300 ] . V_298 ;
V_291 = F_142 ( V_288 , V_3 ) ;
if ( V_291 < 0 )
return V_291 ;
V_295 . V_301 = V_291 ;
V_299 . V_301 = V_291 ;
V_5 -> V_291 = V_291 ;
V_14 = F_143 ( V_46 , & V_302 ,
& V_303 ) ;
if ( ! V_14 )
goto V_304;
V_5 -> V_29 = V_14 ;
V_14 = F_143 ( V_46 , & V_305 ,
& V_306 ) ;
if ( ! V_14 )
goto V_304;
V_5 -> V_9 = V_14 ;
V_14 = F_143 ( V_46 , & V_307 ,
& V_308 ) ;
if ( ! V_14 )
goto V_304;
V_5 -> V_101 = V_14 ;
V_14 = F_143 ( V_46 , & V_309 ,
& V_310 ) ;
if ( ! V_14 )
goto V_304;
V_5 -> V_103 = V_14 ;
V_311 . V_312 = V_302 . V_312 ;
V_313 . V_312 = V_305 . V_312 ;
V_314 . V_312 =
V_307 . V_312 ;
V_315 . V_312 = V_309 . V_312 ;
V_316 . V_312 = V_302 . V_312 ;
V_317 . V_312 = V_305 . V_312 ;
V_318 . V_312 =
V_307 . V_312 ;
V_319 . V_312 = V_309 . V_312 ;
V_6 = F_144 ( V_3 , V_320 ,
V_321 , V_322 , NULL ) ;
if ( V_6 )
goto V_304;
return 0 ;
V_304:
F_7 ( L_31 ) ;
return - V_92 ;
}
static void F_145 ( struct V_177 * V_323 )
{
struct V_324 * V_178 = F_2 ( V_323 , struct V_324 ,
V_178 ) ;
struct V_1 * V_5 = V_178 -> V_5 ;
int V_325 = V_178 -> V_325 ;
F_28 ( V_178 ) ;
if ( V_5 -> V_7 & V_73 )
F_30 ( V_5 ) ;
if ( V_5 -> V_7 & V_128 )
F_42 ( V_5 ) ;
if ( V_325 == V_326 )
F_32 ( V_5 ) ;
else if ( V_325 == V_327 )
F_56 ( V_5 ) ;
F_146 ( V_5 -> V_4 . V_71 -> V_72 ) ;
}
static int F_147 ( struct V_2 * V_3 , unsigned V_328 , unsigned V_325 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ( V_325 == V_326 ) || ( V_325 == V_327 ) ) {
struct V_324 * V_178 ;
V_178 = F_17 ( sizeof( * V_178 ) , V_12 ) ;
if ( ! V_178 )
return - V_51 ;
F_75 ( & V_178 -> V_178 , F_145 ) ;
V_178 -> V_5 = V_5 ;
V_178 -> V_325 = V_325 ;
F_148 ( & V_178 -> V_178 ) ;
return V_329 ;
}
return - V_330 ;
}
static void F_149 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_7 & V_128 )
F_42 ( V_5 ) ;
else if ( V_5 -> V_7 & V_73 )
F_30 ( V_5 ) ;
V_5 -> V_7 = 0 ;
}
static int F_150 ( struct V_2 * V_3 ,
const struct V_77 * V_78 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! ( V_5 -> V_7 & V_73 ) )
return - V_330 ;
return F_36 ( V_3 , V_78 ) ;
}
static inline struct V_244 * F_151 ( struct V_270 * V_271 )
{
return F_2 ( F_152 ( V_271 ) , struct V_244 ,
V_250 . V_241 ) ;
}
static void F_153 ( struct V_270 * V_271 )
{
struct V_244 * V_245 = F_151 ( V_271 ) ;
F_154 ( & V_245 -> V_250 ) ;
}
static void F_155 ( struct V_331 * V_3 )
{
struct V_244 * V_245 ;
unsigned V_104 ;
V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
F_97 ( & V_247 ) ;
for ( V_104 = 0 ; V_104 < V_248 ; ++ V_104 )
if ( V_249 [ V_104 ] . V_250 == V_3 )
break;
if ( V_104 < V_248 )
V_249 [ V_104 ] . V_250 = NULL ;
F_105 ( & V_247 ) ;
F_28 ( V_245 ) ;
}
static int F_156 ( struct V_331 * V_3 )
{
struct V_244 * V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
F_97 ( & V_245 -> V_252 ) ;
V_245 -> V_292 = true ;
F_105 ( & V_245 -> V_252 ) ;
return 0 ;
}
static void F_157 ( struct V_331 * V_3 )
{
struct V_244 * V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
F_97 ( & V_245 -> V_252 ) ;
F_158 ( V_245 ->
V_250 . V_241 . V_258 . V_332 -> V_332 ) ;
V_245 -> V_292 = false ;
F_105 ( & V_245 -> V_252 ) ;
}
static int F_119 ( struct V_181 * V_93 )
{
struct V_331 * V_3 = V_93 -> V_264 ;
struct V_244 * V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
if ( V_245 -> F_156 )
return V_245 -> F_156 ( V_3 ) ;
return 0 ;
}
static void F_120 ( struct V_181 * V_93 )
{
struct V_331 * V_3 = V_93 -> V_264 ;
struct V_244 * V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
if ( V_245 -> F_157 )
V_245 -> F_157 ( V_3 ) ;
}
static int F_159 ( struct V_331 * V_3 , const char * V_234 )
{
struct V_244 * V_245 = F_2 ( V_3 , struct V_244 , V_250 ) ;
F_124 ( L_32 , V_234 ) ;
F_97 ( & V_245 -> V_252 ) ;
V_245 -> V_253 = true ;
F_105 ( & V_245 -> V_252 ) ;
return 0 ;
}
static struct V_331 * F_160 ( void )
{
struct V_244 * V_245 ;
int V_104 ;
V_245 = F_100 ( sizeof( * V_245 ) , V_39 ) ;
if ( ! V_245 )
return F_70 ( - V_51 ) ;
F_97 ( & V_247 ) ;
for ( V_104 = 0 ; V_104 < V_248 ; ++ V_104 )
if ( ! V_249 [ V_104 ] . V_250 )
break;
if ( V_104 == V_248 ) {
F_105 ( & V_247 ) ;
F_28 ( V_245 ) ;
return F_70 ( - V_333 ) ;
}
V_249 [ V_104 ] . V_250 = & V_245 -> V_250 ;
F_105 ( & V_247 ) ;
F_101 ( & V_245 -> V_252 ) ;
V_245 -> V_250 . V_334 = F_159 ;
V_245 -> V_250 . V_335 = F_155 ;
V_245 -> F_156 = F_156 ;
V_245 -> F_157 = F_157 ;
F_161 ( & V_245 -> V_250 . V_241 , L_33 ,
& V_336 ) ;
return & V_245 -> V_250 ;
}
static void F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_337 = F_1 ( V_3 ) ;
F_28 ( V_337 ) ;
}
static void F_163 ( struct V_287 * V_288 , struct V_2 * V_3 )
{
F_164 ( V_3 ) ;
}
static struct V_2 * F_165 ( struct V_331 * V_264 )
{
struct V_1 * V_5 ;
unsigned V_104 ;
F_97 ( & V_247 ) ;
for ( V_104 = 0 ; V_104 < V_248 ; ++ V_104 )
if ( V_249 [ V_104 ] . V_250 == V_264 )
break;
if ( V_104 == V_248 ) {
F_105 ( & V_247 ) ;
return F_70 ( - V_221 ) ;
}
V_5 = F_100 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 ) {
F_105 ( & V_247 ) ;
return F_70 ( - V_51 ) ;
}
V_5 -> V_4 . V_234 = L_34 ;
V_5 -> V_4 . V_338 = F_139 ;
V_5 -> V_4 . V_339 = F_163 ;
V_5 -> V_4 . V_340 = F_147 ;
V_5 -> V_4 . V_341 = F_150 ;
V_5 -> V_4 . V_342 = F_149 ;
V_5 -> V_4 . V_343 = F_162 ;
V_5 -> V_93 = V_249 [ V_104 ] . V_93 ;
F_105 ( & V_247 ) ;
return & V_5 -> V_4 ;
}
static int F_166 ( void )
{
int V_6 ;
V_6 = F_167 ( & V_344 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_168 ( & V_345 ) ;
if ( V_6 )
F_169 ( & V_344 ) ;
return V_6 ;
}
static void F_170 ( void )
{
F_171 ( & V_345 ) ;
F_169 ( & V_344 ) ;
}
