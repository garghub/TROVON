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
F_29 ( V_5 -> V_9 , V_5 -> V_23 . V_11 ) ;
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
V_114 = F_69 ( & V_196 -> V_197 , V_12 ) ;
if ( V_114 < 0 )
return F_70 ( - V_51 ) ;
V_10 = & ( (struct V_16 * ) V_196 -> V_198 ) [ V_114 ] ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_18 . V_199 = V_114 ;
V_10 -> V_18 . V_114 = V_10 -> V_114 = V_194 ;
V_10 -> V_5 = V_5 ;
return V_10 ;
}
static int F_51 ( struct V_1 * V_5 ,
void * V_200 , unsigned int V_115 )
{
struct V_201 * V_202 = V_200 ;
struct V_16 * V_10 ;
struct V_181 * V_93 = V_5 -> V_93 ;
struct V_179 * V_180 = V_93 -> V_185 ;
T_3 V_203 ;
T_1 V_194 ;
if ( V_202 -> V_112 != V_204 ) {
F_7 ( L_13 , V_202 -> V_112 ) ;
return - V_57 ;
}
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
F_7 ( L_14 ) ;
return - V_57 ;
}
V_203 = ( V_202 -> V_115 & ~ 0x3 ) + 16 ;
if ( V_203 > V_205 )
return - V_57 ;
V_194 = F_71 ( & V_202 -> V_114 ) ;
V_10 = F_68 ( V_5 , V_180 , V_194 ) ;
if ( F_72 ( V_10 ) ) {
F_7 ( L_15 ) ;
return - V_51 ;
}
memcpy ( V_10 -> V_186 , V_202 -> V_132 , V_203 ) ;
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
switch ( V_202 -> V_190 & 0x7 ) {
case V_206 :
V_10 -> V_190 = V_207 ;
break;
case V_208 :
V_10 -> V_190 = V_209 ;
break;
case V_210 :
V_10 -> V_190 = V_211 ;
break;
default:
F_73 ( L_16 ,
V_202 -> V_190 ) ;
case V_212 :
V_10 -> V_190 = V_213 ;
break;
}
V_10 -> V_192 = F_74 ( & V_202 -> V_214 ) ;
F_75 ( & V_10 -> V_178 , F_64 ) ;
F_76 ( V_93 -> V_215 , & V_10 -> V_178 ) ;
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
void * V_200 , unsigned int V_115 )
{
struct V_216 * V_217 = V_200 ;
struct V_16 * V_10 ;
struct V_181 * V_93 = V_5 -> V_93 ;
struct V_179 * V_180 ;
T_3 V_203 ;
if ( V_217 -> V_66 != F_11 ( V_218 ) ) {
F_7 ( L_17 ) ;
return - V_57 ;
}
if ( V_115 != 31 ) {
F_7 ( L_18 ) ;
return - V_57 ;
}
V_203 = V_217 -> V_219 ;
if ( V_203 < 1 || V_203 > 16 )
return - V_57 ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
F_7 ( L_14 ) ;
return - V_220 ;
}
V_10 = F_68 ( V_5 , V_180 , V_217 -> V_26 ) ;
if ( F_72 ( V_10 ) ) {
F_7 ( L_15 ) ;
return - V_51 ;
}
memcpy ( V_10 -> V_186 , V_217 -> V_221 , V_203 ) ;
V_10 -> V_27 = V_217 -> V_26 ;
V_10 -> V_190 = V_213 ;
V_10 -> V_192 = V_217 -> V_222 ;
V_10 -> V_34 = V_217 -> V_223 & V_224 ? 1 : 0 ;
V_10 -> V_30 = F_79 ( V_217 -> V_225 ) ;
V_10 -> V_18 . V_114 = F_79 ( V_10 -> V_27 ) ;
F_75 ( & V_10 -> V_178 , F_78 ) ;
F_76 ( V_93 -> V_215 , & V_10 -> V_178 ) ;
return 0 ;
}
static int F_80 ( struct V_226 * V_188 )
{
return 1 ;
}
static int F_81 ( struct V_226 * V_188 )
{
return 0 ;
}
static char * F_82 ( void )
{
return L_19 ;
}
static char * F_83 ( struct V_226 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
struct V_227 * V_228 = V_93 -> V_228 ;
return & V_228 -> V_229 [ 0 ] ;
}
static T_1 F_84 ( struct V_226 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
return V_93 -> V_230 ;
}
static T_3 F_85 ( struct V_226 * V_188 )
{
return 1 ;
}
static void F_77 ( struct V_18 * V_18 )
{
struct V_16 * V_10 = F_2 ( V_18 , struct V_16 ,
V_18 ) ;
struct V_195 * V_196 = V_18 -> V_196 ;
F_28 ( V_10 -> V_49 ) ;
F_86 ( & V_196 -> V_197 , V_18 -> V_199 ) ;
}
static int F_87 ( struct V_195 * V_196 )
{
return 0 ;
}
static void F_88 ( struct V_195 * V_196 )
{
}
static T_3 F_89 ( struct V_195 * V_196 )
{
return 0 ;
}
static int F_90 ( struct V_18 * V_18 )
{
return 0 ;
}
static void F_91 ( struct V_231 * V_232 )
{
}
static int F_92 ( struct V_18 * V_18 )
{
return 0 ;
}
static void F_93 ( struct V_18 * V_18 )
{
}
static void F_94 ( struct V_18 * V_18 )
{
}
static const char * F_95 ( const char * V_233 )
{
const char * V_234 ;
unsigned int V_115 ;
V_234 = strstr ( V_233 , L_20 ) ;
if ( ! V_234 )
return NULL ;
V_234 += 4 ;
V_115 = strlen ( V_234 ) ;
if ( V_115 == 0 || V_115 > V_235 - 1 )
return NULL ;
return V_234 ;
}
static int F_96 ( struct V_231 * V_236 , const char * V_233 )
{
if ( ! F_95 ( V_233 ) )
return - V_57 ;
return 0 ;
}
static struct V_226 * F_97 (
struct V_237 * V_238 ,
struct V_239 * V_240 ,
const char * V_233 )
{
struct V_227 * V_228 = F_2 ( V_238 , struct V_227 ,
V_241 ) ;
struct V_181 * V_93 ;
unsigned long V_242 ;
int V_6 ;
struct V_243 * V_244 ;
unsigned V_104 ;
if ( strstr ( V_233 , L_21 ) != V_233 )
return F_70 ( - V_57 ) ;
if ( F_98 ( V_233 + 5 , 0 , & V_242 ) || V_242 > V_245 )
return F_70 ( - V_57 ) ;
V_6 = - V_220 ;
F_99 ( & V_246 ) ;
for ( V_104 = 0 ; V_104 < V_247 ; ++ V_104 )
if ( V_248 [ V_104 ] . V_249 && ! V_248 [ V_104 ] . V_93 )
break;
if ( V_104 == V_247 )
goto V_250;
V_244 = F_2 ( V_248 [ V_104 ] . V_249 , struct V_243 ,
V_249 ) ;
F_99 ( & V_244 -> V_251 ) ;
if ( ! V_244 -> V_252 )
goto V_253;
if ( V_244 -> V_254 ) {
if ( ! F_100 ( V_244 -> V_255 ) )
goto V_253;
} else {
V_6 = F_101 (
V_240 -> V_256 ,
& V_244 -> V_249 . V_240 . V_257 ) ;
if ( V_6 )
goto V_253;
}
V_93 = F_102 ( sizeof( struct V_181 ) , V_39 ) ;
V_6 = - V_51 ;
if ( ! V_93 )
goto V_258;
F_103 ( & V_93 -> V_259 ) ;
F_104 ( & V_93 -> V_94 , 0 ) ;
V_93 -> V_215 = F_105 ( L_22 , 0 , 1 ) ;
if ( ! V_93 -> V_215 )
goto V_260;
V_93 -> V_228 = V_228 ;
V_93 -> V_230 = V_242 ;
V_6 = F_106 ( V_238 , & V_93 -> V_188 , V_261 ) ;
if ( V_6 < 0 )
goto V_262;
V_248 [ V_104 ] . V_93 = V_93 ;
V_93 -> V_263 = V_248 [ V_104 ] . V_249 ;
F_107 ( & V_244 -> V_251 ) ;
F_107 ( & V_246 ) ;
return & V_93 -> V_188 ;
V_262:
F_108 ( V_93 -> V_215 ) ;
V_260:
F_28 ( V_93 ) ;
V_258:
if ( V_244 -> V_254 )
F_109 ( V_244 -> V_255 ) ;
else
F_110 ( & V_244 -> V_249 . V_240 . V_257 ) ;
V_253:
F_107 ( & V_244 -> V_251 ) ;
V_250:
F_107 ( & V_246 ) ;
return F_70 ( V_6 ) ;
}
static void F_111 ( struct V_226 * V_188 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
unsigned V_104 ;
struct V_243 * V_244 ;
F_112 ( V_93 ) ;
F_113 ( V_188 ) ;
F_108 ( V_93 -> V_215 ) ;
F_99 ( & V_246 ) ;
for ( V_104 = 0 ; V_104 < V_247 ; ++ V_104 )
if ( V_248 [ V_104 ] . V_93 == V_93 )
break;
if ( V_104 < V_247 )
V_248 [ V_104 ] . V_93 = NULL ;
V_244 = F_2 ( V_248 [ V_104 ] . V_249 ,
struct V_243 , V_249 ) ;
F_99 ( & V_244 -> V_251 ) ;
if ( V_244 -> V_254 )
F_109 ( V_244 -> V_255 ) ;
else
F_110 ( & V_244 -> V_249 . V_240 . V_257 ) ;
F_107 ( & V_244 -> V_251 ) ;
F_107 ( & V_246 ) ;
F_28 ( V_93 ) ;
}
static struct V_237 * F_114 (
struct V_264 * V_265 ,
struct V_239 * V_240 ,
const char * V_233 )
{
struct V_227 * V_228 ;
const char * V_266 ;
T_4 V_267 = 0 ;
V_266 = F_95 ( V_233 ) ;
if ( ! V_266 )
return F_70 ( - V_57 ) ;
V_228 = F_102 ( sizeof( struct V_227 ) , V_39 ) ;
if ( ! ( V_228 ) )
return F_70 ( - V_51 ) ;
V_228 -> V_268 = V_267 ;
snprintf ( V_228 -> V_229 , sizeof( V_228 -> V_229 ) , L_23 , V_266 ) ;
return & V_228 -> V_241 ;
}
static void F_115 ( struct V_237 * V_238 )
{
struct V_227 * V_228 = F_2 ( V_238 ,
struct V_227 , V_241 ) ;
F_28 ( V_228 ) ;
}
static T_5 F_116 ( struct V_269 * V_270 , char * V_271 )
{
return sprintf ( V_271 , L_24 ) ;
}
static T_5 F_117 ( struct V_269 * V_270 , char * V_271 )
{
struct V_226 * V_188 = F_118 ( V_270 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
return snprintf ( V_271 , V_272 , L_25 , V_93 -> V_273 ) ;
}
static T_5 F_119 ( struct V_269 * V_270 ,
const char * V_271 , T_6 V_274 )
{
struct V_226 * V_188 = F_118 ( V_270 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
bool V_275 ;
T_5 V_6 ;
V_6 = F_120 ( V_271 , & V_275 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_275 && V_93 -> V_273 ) || ( ! V_275 && ! V_93 -> V_273 ) )
return - V_57 ;
if ( V_275 )
V_6 = F_121 ( V_93 ) ;
else
F_122 ( V_93 ) ;
if ( V_6 )
return V_6 ;
V_93 -> V_273 = V_275 ;
return V_274 ;
}
static T_5 F_123 ( struct V_269 * V_270 , char * V_271 )
{
struct V_226 * V_188 = F_118 ( V_270 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
struct V_179 * V_180 ;
T_5 V_6 ;
F_99 ( & V_93 -> V_259 ) ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 ) {
V_6 = - V_220 ;
goto V_120;
}
V_6 = snprintf ( V_271 , V_272 , L_26 ,
V_180 -> V_187 -> V_231 -> V_276 ) ;
V_120:
F_107 ( & V_93 -> V_259 ) ;
return V_6 ;
}
static int F_124 ( struct V_226 * V_188 ,
struct V_195 * V_196 , void * V_277 )
{
struct V_181 * V_93 = F_2 ( V_188 ,
struct V_181 , V_188 ) ;
V_93 -> V_185 = V_277 ;
return 0 ;
}
static int F_125 ( struct V_181 * V_93 , char * V_233 )
{
struct V_179 * V_180 ;
int V_6 = 0 ;
F_99 ( & V_93 -> V_259 ) ;
if ( V_93 -> V_185 ) {
V_6 = - V_278 ;
F_126 ( L_27 ) ;
goto V_279;
}
V_180 = F_102 ( sizeof( * V_180 ) , V_39 ) ;
if ( ! V_180 ) {
V_6 = - V_51 ;
goto V_279;
}
V_180 -> V_187 = F_127 ( & V_93 -> V_188 ,
V_280 ,
sizeof( struct V_16 ) ,
V_281 , V_233 ,
V_180 , F_124 ) ;
if ( F_72 ( V_180 -> V_187 ) ) {
#define F_128 "core_tpg_check_initiator_node_acl() failed for %s\n"
F_126 ( F_128 , V_233 ) ;
#undef F_128
V_6 = F_129 ( V_180 -> V_187 ) ;
F_28 ( V_180 ) ;
}
V_279:
F_107 ( & V_93 -> V_259 ) ;
return V_6 ;
}
static int F_112 ( struct V_181 * V_93 )
{
struct V_195 * V_196 ;
struct V_179 * V_180 ;
int V_6 = - V_220 ;
F_99 ( & V_93 -> V_259 ) ;
V_180 = V_93 -> V_185 ;
if ( ! V_180 )
goto V_120;
V_196 = V_180 -> V_187 ;
if ( ! V_196 )
goto V_120;
if ( F_38 ( & V_93 -> V_94 ) ) {
V_6 = - V_282 ;
#define F_130 "Unable to remove Host I_T Nexus with active TPG port count: %d\n"
F_7 ( F_130 , F_38 ( & V_93 -> V_94 ) ) ;
#undef F_130
goto V_120;
}
F_126 ( L_28 ,
V_180 -> V_187 -> V_231 -> V_276 ) ;
F_131 ( V_180 -> V_187 ) ;
V_93 -> V_185 = NULL ;
F_28 ( V_180 ) ;
V_6 = 0 ;
V_120:
F_107 ( & V_93 -> V_259 ) ;
return V_6 ;
}
static T_5 F_132 ( struct V_269 * V_270 ,
const char * V_271 , T_6 V_274 )
{
struct V_226 * V_188 = F_118 ( V_270 ) ;
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
unsigned char V_283 [ V_235 ] , * V_284 ;
int V_6 ;
if ( ! strncmp ( V_271 , L_29 , 4 ) ) {
V_6 = F_112 ( V_93 ) ;
return ( ! V_6 ) ? V_274 : V_6 ;
}
if ( strlen ( V_271 ) >= V_235 ) {
#define F_133 "Emulated NAA Sas Address: %s, exceeds max: %d\n"
F_7 ( F_133 , V_271 , V_235 ) ;
#undef F_133
return - V_57 ;
}
snprintf ( V_283 , V_235 , L_23 , V_271 ) ;
V_284 = strstr ( V_283 , L_20 ) ;
if ( ! V_284 ) {
F_7 ( L_30 ) ;
return - V_57 ;
}
if ( V_283 [ strlen ( V_283 ) - 1 ] == '\n' )
V_283 [ strlen ( V_283 ) - 1 ] = '\0' ;
V_6 = F_125 ( V_93 , & V_283 [ 0 ] ) ;
if ( V_6 < 0 )
return V_6 ;
return V_274 ;
}
static int F_134 ( struct V_226 * V_188 , struct V_285 * V_214 )
{
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
F_135 ( & V_93 -> V_94 ) ;
F_136 () ;
return 0 ;
}
static void F_137 ( struct V_226 * V_188 ,
struct V_285 * V_285 )
{
struct V_181 * V_93 = F_2 ( V_188 , struct V_181 , V_188 ) ;
F_138 ( & V_93 -> V_94 ) ;
F_136 () ;
}
static int F_139 ( struct V_18 * V_18 )
{
return F_140 ( V_18 ) ;
}
static int F_141 ( struct V_286 * V_287 , struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_288 * V_289 ;
struct V_45 * V_46 = V_287 -> V_72 -> V_46 ;
struct V_13 * V_14 ;
struct V_243 * V_244 ;
int V_290 ;
int V_6 ;
V_244 = F_2 ( V_3 -> V_263 , struct V_243 , V_249 ) ;
F_99 ( & V_244 -> V_251 ) ;
if ( ! V_244 -> V_291 ) {
F_107 ( & V_244 -> V_251 ) ;
return - V_220 ;
}
F_107 ( & V_244 -> V_251 ) ;
V_289 = F_142 ( V_287 -> V_72 , V_292 ,
F_143 ( V_293 ) ) ;
if ( F_72 ( V_289 ) )
return F_129 ( V_289 ) ;
V_294 . V_295 = V_289 [ V_296 ] . V_297 ;
V_298 . V_295 = V_289 [ V_299 ] . V_297 ;
V_290 = F_144 ( V_287 , V_3 ) ;
if ( V_290 < 0 )
return V_290 ;
V_294 . V_300 = V_290 ;
V_298 . V_300 = V_290 ;
V_5 -> V_290 = V_290 ;
V_14 = F_145 ( V_46 , & V_301 ,
& V_302 ) ;
if ( ! V_14 )
goto V_303;
V_5 -> V_29 = V_14 ;
V_14 = F_145 ( V_46 , & V_304 ,
& V_305 ) ;
if ( ! V_14 )
goto V_303;
V_5 -> V_9 = V_14 ;
V_14 = F_145 ( V_46 , & V_306 ,
& V_307 ) ;
if ( ! V_14 )
goto V_303;
V_5 -> V_101 = V_14 ;
V_14 = F_145 ( V_46 , & V_308 ,
& V_309 ) ;
if ( ! V_14 )
goto V_303;
V_5 -> V_103 = V_14 ;
V_310 . V_311 = V_301 . V_311 ;
V_312 . V_311 = V_304 . V_311 ;
V_313 . V_311 =
V_306 . V_311 ;
V_314 . V_311 = V_308 . V_311 ;
V_315 . V_311 = V_301 . V_311 ;
V_316 . V_311 = V_304 . V_311 ;
V_317 . V_311 =
V_306 . V_311 ;
V_318 . V_311 = V_308 . V_311 ;
V_6 = F_146 ( V_3 , V_319 ,
V_320 , V_321 , NULL ) ;
if ( V_6 )
goto V_303;
return 0 ;
V_303:
F_7 ( L_31 ) ;
return - V_92 ;
}
static void F_147 ( struct V_177 * V_322 )
{
struct V_323 * V_178 = F_2 ( V_322 , struct V_323 ,
V_178 ) ;
struct V_1 * V_5 = V_178 -> V_5 ;
int V_324 = V_178 -> V_324 ;
F_28 ( V_178 ) ;
if ( V_5 -> V_7 & V_73 )
F_30 ( V_5 ) ;
if ( V_5 -> V_7 & V_128 )
F_42 ( V_5 ) ;
if ( V_324 == V_325 )
F_32 ( V_5 ) ;
else if ( V_324 == V_326 )
F_56 ( V_5 ) ;
F_148 ( V_5 -> V_4 . V_71 -> V_72 ) ;
}
static int F_149 ( struct V_2 * V_3 , unsigned V_327 , unsigned V_324 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ( V_324 == V_325 ) || ( V_324 == V_326 ) ) {
struct V_323 * V_178 ;
V_178 = F_17 ( sizeof( * V_178 ) , V_12 ) ;
if ( ! V_178 )
return - V_51 ;
F_75 ( & V_178 -> V_178 , F_147 ) ;
V_178 -> V_5 = V_5 ;
V_178 -> V_324 = V_324 ;
F_150 ( & V_178 -> V_178 ) ;
return V_328 ;
}
return - V_329 ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_7 & V_128 )
F_42 ( V_5 ) ;
else if ( V_5 -> V_7 & V_73 )
F_30 ( V_5 ) ;
V_5 -> V_7 = 0 ;
}
static int F_152 ( struct V_2 * V_3 ,
const struct V_77 * V_78 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! ( V_5 -> V_7 & V_73 ) )
return - V_329 ;
return F_36 ( V_3 , V_78 ) ;
}
static inline struct V_243 * F_153 ( struct V_269 * V_270 )
{
return F_2 ( F_154 ( V_270 ) , struct V_243 ,
V_249 . V_240 ) ;
}
static void F_155 ( struct V_269 * V_270 )
{
struct V_243 * V_244 = F_153 ( V_270 ) ;
F_156 ( & V_244 -> V_249 ) ;
}
static void F_157 ( struct V_330 * V_3 )
{
struct V_243 * V_244 ;
unsigned V_104 ;
V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
F_99 ( & V_246 ) ;
for ( V_104 = 0 ; V_104 < V_247 ; ++ V_104 )
if ( V_248 [ V_104 ] . V_249 == V_3 )
break;
if ( V_104 < V_247 )
V_248 [ V_104 ] . V_249 = NULL ;
F_107 ( & V_246 ) ;
F_28 ( V_244 ) ;
}
static int F_158 ( struct V_330 * V_3 )
{
struct V_243 * V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
F_99 ( & V_244 -> V_251 ) ;
V_244 -> V_291 = true ;
F_107 ( & V_244 -> V_251 ) ;
return 0 ;
}
static void F_159 ( struct V_330 * V_3 )
{
struct V_243 * V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
F_99 ( & V_244 -> V_251 ) ;
F_160 ( V_244 ->
V_249 . V_240 . V_257 . V_331 -> V_331 ) ;
V_244 -> V_291 = false ;
F_107 ( & V_244 -> V_251 ) ;
}
static int F_121 ( struct V_181 * V_93 )
{
struct V_330 * V_3 = V_93 -> V_263 ;
struct V_243 * V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
if ( V_244 -> F_158 )
return V_244 -> F_158 ( V_3 ) ;
return 0 ;
}
static void F_122 ( struct V_181 * V_93 )
{
struct V_330 * V_3 = V_93 -> V_263 ;
struct V_243 * V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
if ( V_244 -> F_159 )
V_244 -> F_159 ( V_3 ) ;
}
static int F_161 ( struct V_330 * V_3 , const char * V_233 )
{
struct V_243 * V_244 = F_2 ( V_3 , struct V_243 , V_249 ) ;
F_126 ( L_32 , V_233 ) ;
F_99 ( & V_244 -> V_251 ) ;
V_244 -> V_252 = true ;
F_107 ( & V_244 -> V_251 ) ;
return 0 ;
}
static struct V_330 * F_162 ( void )
{
struct V_243 * V_244 ;
int V_104 ;
V_244 = F_102 ( sizeof( * V_244 ) , V_39 ) ;
if ( ! V_244 )
return F_70 ( - V_51 ) ;
F_99 ( & V_246 ) ;
for ( V_104 = 0 ; V_104 < V_247 ; ++ V_104 )
if ( ! V_248 [ V_104 ] . V_249 )
break;
if ( V_104 == V_247 ) {
F_107 ( & V_246 ) ;
F_28 ( V_244 ) ;
return F_70 ( - V_332 ) ;
}
V_248 [ V_104 ] . V_249 = & V_244 -> V_249 ;
F_107 ( & V_246 ) ;
F_103 ( & V_244 -> V_251 ) ;
V_244 -> V_249 . V_333 = F_161 ;
V_244 -> V_249 . V_334 = F_157 ;
V_244 -> F_158 = F_158 ;
V_244 -> F_159 = F_159 ;
F_163 ( & V_244 -> V_249 . V_240 , L_33 ,
& V_335 ) ;
return & V_244 -> V_249 ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_336 = F_1 ( V_3 ) ;
F_28 ( V_336 ) ;
}
static void F_165 ( struct V_286 * V_287 , struct V_2 * V_3 )
{
F_166 ( V_3 ) ;
}
static struct V_2 * F_167 ( struct V_330 * V_263 )
{
struct V_1 * V_5 ;
unsigned V_104 ;
F_99 ( & V_246 ) ;
for ( V_104 = 0 ; V_104 < V_247 ; ++ V_104 )
if ( V_248 [ V_104 ] . V_249 == V_263 )
break;
if ( V_104 == V_247 ) {
F_107 ( & V_246 ) ;
return F_70 ( - V_220 ) ;
}
V_5 = F_102 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 ) {
F_107 ( & V_246 ) ;
return F_70 ( - V_51 ) ;
}
V_5 -> V_4 . V_233 = L_34 ;
V_5 -> V_4 . V_337 = F_141 ;
V_5 -> V_4 . V_338 = F_165 ;
V_5 -> V_4 . V_339 = F_149 ;
V_5 -> V_4 . V_340 = F_152 ;
V_5 -> V_4 . V_341 = F_151 ;
V_5 -> V_4 . V_342 = F_164 ;
V_5 -> V_93 = V_248 [ V_104 ] . V_93 ;
F_107 ( & V_246 ) ;
return & V_5 -> V_4 ;
}
static int F_168 ( void )
{
int V_6 ;
V_6 = F_169 ( & V_343 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_170 ( & V_344 ) ;
if ( V_6 )
F_171 ( & V_343 ) ;
return V_6 ;
}
static void F_172 ( void )
{
F_173 ( & V_344 ) ;
F_171 ( & V_343 ) ;
}
