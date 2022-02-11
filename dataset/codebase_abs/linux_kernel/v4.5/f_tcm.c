static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_7 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_9 )
{
int V_10 ;
if ( V_9 -> V_11 & V_12 )
return 0 ;
V_10 = F_6 ( V_9 -> V_13 , V_9 -> V_6 . V_14 , V_15 ) ;
if ( ! V_10 )
V_9 -> V_11 |= V_12 ;
return V_10 ;
}
static void F_7 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_1 * V_9 = V_6 -> V_9 ;
F_3 ( V_6 ) ;
if ( V_14 -> V_20 < 0 ) {
F_8 ( L_1 , V_21 , __LINE__ ) ;
return;
}
F_5 ( V_9 ) ;
}
static void F_9 ( struct V_1 * V_9 , struct V_5 * V_6 )
{
struct V_22 * V_23 = & V_9 -> V_24 . V_23 ;
int V_10 ;
unsigned int V_25 ;
V_25 = V_6 -> V_26 ;
V_23 -> V_27 = V_6 -> V_28 ;
V_23 -> V_29 = V_25 ;
V_9 -> V_24 . V_14 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_30 , V_9 -> V_24 . V_14 , V_15 ) ;
if ( V_10 )
F_8 ( L_2 , V_21 , __LINE__ , V_10 ) ;
}
static void F_10 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_14 -> V_20 < 0 )
F_8 ( L_1 , V_21 , __LINE__ ) ;
if ( V_6 -> V_31 ) {
if ( V_6 -> V_31 > V_17 -> V_32 ) {
V_14 -> V_33 = V_17 -> V_32 ;
V_6 -> V_31 -= V_17 -> V_32 ;
} else {
V_14 -> V_33 = V_6 -> V_31 ;
V_6 -> V_31 = 0 ;
}
F_6 ( V_17 , V_14 , V_15 ) ;
return;
}
F_9 ( V_9 , V_6 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_22 * V_23 = & V_9 -> V_24 . V_23 ;
struct V_18 * V_14 ;
struct V_16 * V_17 ;
V_23 -> V_34 = F_12 ( V_6 -> V_31 ) ;
if ( V_6 -> V_31 ) {
if ( V_6 -> V_35 ) {
V_17 = V_9 -> V_30 ;
V_14 = V_9 -> V_36 ;
} else {
V_17 = V_9 -> V_13 ;
V_14 = V_9 -> V_37 ;
}
if ( V_6 -> V_31 > V_9 -> V_30 -> V_32 ) {
V_14 -> V_33 = V_17 -> V_32 ;
V_6 -> V_31 -= V_17 -> V_32 ;
} else {
V_14 -> V_33 = V_6 -> V_31 ;
V_6 -> V_31 = 0 ;
}
V_14 -> V_38 = F_10 ;
V_14 -> V_19 = V_6 ;
V_14 -> V_39 = V_9 -> V_6 . V_39 ;
F_6 ( V_17 , V_14 , V_40 ) ;
} else {
F_9 ( V_9 , V_6 ) ;
}
}
static int F_13 ( struct V_5 * V_6 , bool V_41 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_22 * V_23 = & V_9 -> V_24 . V_23 ;
int V_10 ;
if ( V_6 -> V_42 . V_43 == V_44 ) {
if ( ! V_41 && V_6 -> V_31 ) {
V_6 -> V_26 = V_45 ;
F_11 ( V_6 ) ;
return 0 ;
}
V_23 -> V_27 = V_6 -> V_28 ;
V_23 -> V_34 = F_12 ( 0 ) ;
V_23 -> V_29 = V_45 ;
V_9 -> V_24 . V_14 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_30 , V_9 -> V_24 . V_14 , V_40 ) ;
if ( V_10 )
F_8 ( L_2 , V_21 , __LINE__ , V_10 ) ;
} else {
V_6 -> V_26 = V_46 ;
F_11 ( V_6 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
bool V_41 = false ;
if ( ! V_6 -> V_35 )
V_41 = true ;
return F_13 ( V_6 , V_41 ) ;
}
static void F_15 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
if ( V_14 -> V_20 < 0 )
F_8 ( L_1 , V_21 , __LINE__ ) ;
F_13 ( V_6 , true ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_47 * V_48 = F_17 ( V_9 ) ;
int V_10 ;
if ( ! V_6 -> V_31 ) {
V_6 -> V_26 = V_49 ;
F_11 ( V_6 ) ;
return 0 ;
}
if ( ! V_48 -> V_50 ) {
V_6 -> V_51 = F_18 ( V_42 -> V_52 , V_15 ) ;
if ( ! V_6 -> V_51 )
return - V_53 ;
F_19 ( V_42 -> V_54 ,
V_42 -> V_55 ,
V_6 -> V_51 ,
V_42 -> V_52 ) ;
V_9 -> V_36 -> V_39 = V_6 -> V_51 ;
} else {
V_9 -> V_36 -> V_39 = NULL ;
V_9 -> V_36 -> V_56 = V_42 -> V_55 ;
V_9 -> V_36 -> V_57 = V_42 -> V_54 ;
}
V_9 -> V_36 -> V_38 = F_15 ;
V_9 -> V_36 -> V_33 = V_42 -> V_52 ;
V_9 -> V_36 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_30 , V_9 -> V_36 , V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_47 * V_48 = F_17 ( V_9 ) ;
int V_10 ;
F_21 ( & V_6 -> V_58 ) ;
V_6 -> V_9 = V_9 ;
if ( ! V_6 -> V_31 ) {
V_6 -> V_26 = V_49 ;
return - V_59 ;
}
if ( ! V_48 -> V_50 ) {
V_6 -> V_51 = F_18 ( V_42 -> V_52 , V_40 ) ;
if ( ! V_6 -> V_51 )
return - V_53 ;
V_9 -> V_37 -> V_39 = V_6 -> V_51 ;
} else {
V_9 -> V_37 -> V_39 = NULL ;
V_9 -> V_37 -> V_56 = V_42 -> V_55 ;
V_9 -> V_37 -> V_57 = V_42 -> V_54 ;
}
V_9 -> V_37 -> V_38 = V_60 ;
V_9 -> V_37 -> V_33 = V_42 -> V_52 ;
V_9 -> V_37 -> V_19 = V_6 ;
V_10 = F_22 ( V_6 , V_9 -> V_37 ) ;
if ( V_10 )
goto V_61;
V_10 = F_6 ( V_9 -> V_13 , V_9 -> V_37 , V_40 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
F_23 ( & V_6 -> V_58 ) ;
F_24 ( V_42 ) ;
V_61:
return V_10 ;
}
static void F_25 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_19 ;
int V_10 ;
V_9 -> V_11 &= ~ V_12 ;
if ( V_14 -> V_20 < 0 )
return;
V_10 = F_26 ( V_9 , V_14 -> V_39 , V_14 -> V_62 ) ;
if ( V_10 )
F_8 ( L_4 , V_21 , __LINE__ , V_10 ) ;
}
static int F_27 ( struct V_1 * V_9 )
{
int V_10 ;
V_9 -> V_36 = F_28 ( V_9 -> V_30 , V_40 ) ;
if ( ! V_9 -> V_36 )
goto V_63;
V_9 -> V_37 = F_28 ( V_9 -> V_13 , V_40 ) ;
if ( ! V_9 -> V_37 )
goto V_64;
V_9 -> V_6 . V_14 = F_28 ( V_9 -> V_13 , V_40 ) ;
if ( ! V_9 -> V_6 . V_14 )
goto V_65;
V_9 -> V_24 . V_14 = F_28 ( V_9 -> V_30 , V_40 ) ;
if ( ! V_9 -> V_24 . V_14 )
goto V_66;
V_9 -> V_24 . V_14 -> V_39 = & V_9 -> V_24 . V_23 ;
V_9 -> V_24 . V_14 -> V_33 = V_67 ;
V_9 -> V_24 . V_14 -> V_38 = F_7 ;
V_9 -> V_24 . V_23 . V_68 = F_12 ( V_69 ) ;
V_9 -> V_6 . V_39 = F_18 ( V_9 -> V_13 -> V_32 , V_40 ) ;
if ( ! V_9 -> V_6 . V_39 )
goto V_70;
V_9 -> V_6 . V_14 -> V_38 = F_25 ;
V_9 -> V_6 . V_14 -> V_39 = V_9 -> V_6 . V_39 ;
V_9 -> V_6 . V_14 -> V_33 = V_9 -> V_13 -> V_32 ;
V_9 -> V_6 . V_14 -> V_19 = V_9 ;
V_10 = F_5 ( V_9 ) ;
if ( V_10 )
goto V_71;
return 0 ;
V_71:
F_29 ( V_9 -> V_6 . V_39 ) ;
V_9 -> V_6 . V_39 = NULL ;
V_70:
F_30 ( V_9 -> V_30 , V_9 -> V_24 . V_14 ) ;
V_66:
F_30 ( V_9 -> V_13 , V_9 -> V_6 . V_14 ) ;
V_9 -> V_6 . V_14 = NULL ;
V_65:
F_30 ( V_9 -> V_13 , V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
V_64:
F_30 ( V_9 -> V_30 , V_9 -> V_36 ) ;
V_9 -> V_36 = NULL ;
V_63:
F_8 ( L_5 ) ;
return - V_53 ;
}
static void F_31 ( struct V_1 * V_9 )
{
if ( ! ( V_9 -> V_11 & V_72 ) )
return;
F_32 ( V_9 -> V_30 ) ;
F_32 ( V_9 -> V_13 ) ;
if ( ! V_9 -> V_36 )
return;
F_30 ( V_9 -> V_30 , V_9 -> V_36 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_37 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_6 . V_14 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_24 . V_14 ) ;
F_29 ( V_9 -> V_6 . V_39 ) ;
V_9 -> V_36 = NULL ;
V_9 -> V_37 = NULL ;
V_9 -> V_6 . V_14 = NULL ;
V_9 -> V_24 . V_14 = NULL ;
V_9 -> V_6 . V_39 = NULL ;
}
static void F_33 ( struct V_1 * V_9 )
{
struct V_2 * V_3 = & V_9 -> V_4 ;
struct V_47 * V_48 = V_3 -> V_73 -> V_74 -> V_48 ;
int V_10 ;
V_9 -> V_11 = V_75 ;
F_34 ( V_48 , V_3 , V_9 -> V_30 ) ;
V_10 = F_35 ( V_9 -> V_30 ) ;
if ( V_10 )
goto V_76;
F_34 ( V_48 , V_3 , V_9 -> V_13 ) ;
V_10 = F_35 ( V_9 -> V_13 ) ;
if ( V_10 )
goto V_77;
V_10 = F_27 ( V_9 ) ;
if ( V_10 )
goto V_78;
V_9 -> V_11 |= V_72 ;
F_36 ( L_6 ) ;
return;
V_78:
F_32 ( V_9 -> V_13 ) ;
V_77:
F_32 ( V_9 -> V_30 ) ;
V_76:
V_9 -> V_11 = V_75 ;
}
static int F_37 ( struct V_2 * V_3 ,
const struct V_79 * V_80 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_81 * V_74 = V_3 -> V_73 -> V_74 ;
T_1 V_82 = F_38 ( V_80 -> V_83 ) ;
T_1 V_84 = F_38 ( V_80 -> V_85 ) ;
int V_86 ;
T_2 * V_87 ;
switch ( V_80 -> V_88 ) {
case V_89 :
if ( V_80 -> V_90 != ( V_91 | V_92 |
V_93 ) )
return - V_94 ;
if ( V_84 < 1 )
return - V_59 ;
if ( V_82 != 0 )
return - V_59 ;
V_86 = F_39 ( & V_9 -> V_95 -> V_96 ) ;
if ( ! V_86 ) {
F_8 ( L_7 ) ;
return - V_59 ;
}
V_86 -- ;
if ( V_86 > 0xf ) {
F_40 ( L_8 ) ;
V_86 = 0xf ;
}
V_87 = V_74 -> V_14 -> V_39 ;
* V_87 = V_86 ;
V_74 -> V_14 -> V_33 = 1 ;
return F_6 ( V_74 -> V_48 -> V_97 , V_74 -> V_14 , V_15 ) ;
case V_98 :
F_5 ( V_9 ) ;
return 0 ;
}
return - V_94 ;
}
static void F_41 ( struct V_1 * V_9 , struct V_99 * V_100 )
{
if ( ! V_100 -> V_101 )
return;
F_30 ( V_9 -> V_30 , V_100 -> V_101 ) ;
F_30 ( V_9 -> V_13 , V_100 -> V_102 ) ;
F_30 ( V_9 -> V_103 , V_100 -> V_104 ) ;
V_100 -> V_101 = NULL ;
V_100 -> V_102 = NULL ;
V_100 -> V_104 = NULL ;
}
static void F_42 ( struct V_1 * V_9 )
{
F_30 ( V_9 -> V_105 , V_9 -> V_6 . V_14 ) ;
F_29 ( V_9 -> V_6 . V_39 ) ;
V_9 -> V_6 . V_14 = NULL ;
V_9 -> V_6 . V_39 = NULL ;
}
static void F_43 ( struct V_1 * V_9 )
{
int V_106 ;
if ( ! ( V_9 -> V_11 & V_72 ) )
return;
F_32 ( V_9 -> V_30 ) ;
F_32 ( V_9 -> V_13 ) ;
F_32 ( V_9 -> V_103 ) ;
F_32 ( V_9 -> V_105 ) ;
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ )
F_41 ( V_9 , & V_9 -> V_100 [ V_106 ] ) ;
F_42 ( V_9 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_47 * V_48 = F_17 ( V_9 ) ;
struct V_99 * V_100 = V_6 -> V_100 ;
if ( ! V_48 -> V_50 ) {
V_6 -> V_51 = F_18 ( V_42 -> V_52 , V_15 ) ;
if ( ! V_6 -> V_51 )
return - V_53 ;
F_19 ( V_42 -> V_54 ,
V_42 -> V_55 ,
V_6 -> V_51 ,
V_42 -> V_52 ) ;
V_100 -> V_101 -> V_39 = V_6 -> V_51 ;
} else {
V_100 -> V_101 -> V_39 = NULL ;
V_100 -> V_101 -> V_56 = V_42 -> V_55 ;
V_100 -> V_101 -> V_57 = V_42 -> V_54 ;
}
V_100 -> V_101 -> V_38 = V_108 ;
V_100 -> V_101 -> V_33 = V_42 -> V_52 ;
V_100 -> V_101 -> V_19 = V_6 ;
V_6 -> V_109 = V_110 ;
return 0 ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_111 * V_112 = & V_6 -> V_111 ;
struct V_99 * V_100 = V_6 -> V_100 ;
V_6 -> V_109 = V_113 ;
V_112 -> V_114 = V_115 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
V_112 -> V_117 = F_46 ( V_42 -> V_118 ) ;
V_112 -> V_20 = V_42 -> V_43 ;
V_100 -> V_104 -> V_19 = V_6 ;
V_100 -> V_104 -> V_33 = V_42 -> V_118 + 16 ;
V_100 -> V_104 -> V_39 = V_112 ;
V_100 -> V_104 -> V_38 = V_108 ;
}
static void V_108 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_99 * V_100 = V_6 -> V_100 ;
struct V_1 * V_9 = V_6 -> V_9 ;
int V_10 ;
if ( V_14 -> V_20 < 0 )
goto V_61;
switch ( V_6 -> V_109 ) {
case V_119 :
V_10 = F_44 ( V_6 ) ;
if ( V_10 )
goto V_61;
V_10 = F_6 ( V_9 -> V_30 , V_100 -> V_101 , V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_120 :
V_10 = F_22 ( V_6 , V_100 -> V_102 ) ;
if ( V_10 )
goto V_61;
V_10 = F_6 ( V_9 -> V_13 , V_100 -> V_102 , V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_110 :
F_45 ( V_6 ) ;
V_10 = F_6 ( V_9 -> V_103 , V_100 -> V_104 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_113 :
F_3 ( V_6 ) ;
F_6 ( V_9 -> V_105 , V_9 -> V_6 . V_14 , V_15 ) ;
break;
default:
F_47 () ;
}
return;
V_61:
F_3 ( V_6 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_99 * V_100 = V_6 -> V_100 ;
struct V_111 * V_112 = & V_6 -> V_111 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
V_100 -> V_104 -> V_38 = V_108 ;
V_100 -> V_104 -> V_19 = V_6 ;
V_6 -> V_9 = V_9 ;
F_45 ( V_6 ) ;
return F_6 ( V_9 -> V_103 , V_100 -> V_104 , V_15 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_99 * V_100 = V_6 -> V_100 ;
struct V_111 * V_112 = & V_6 -> V_111 ;
int V_10 ;
V_6 -> V_9 = V_9 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
if ( V_9 -> V_11 & V_121 ) {
V_10 = F_44 ( V_6 ) ;
if ( V_10 )
goto V_122;
V_10 = F_6 ( V_9 -> V_30 , V_100 -> V_101 , V_15 ) ;
if ( V_10 ) {
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
F_29 ( V_6 -> V_51 ) ;
V_6 -> V_51 = NULL ;
}
} else {
V_112 -> V_114 = V_123 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
V_100 -> V_104 -> V_38 = V_108 ;
V_100 -> V_104 -> V_19 = V_6 ;
V_6 -> V_109 = V_119 ;
V_100 -> V_104 -> V_39 = V_112 ;
V_100 -> V_104 -> V_33 = sizeof( struct V_112 ) ;
V_10 = F_6 ( V_9 -> V_103 , V_100 -> V_104 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
}
V_122:
return V_10 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_99 * V_100 = V_6 -> V_100 ;
struct V_111 * V_112 = & V_6 -> V_111 ;
int V_10 ;
F_21 ( & V_6 -> V_58 ) ;
V_6 -> V_9 = V_9 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
if ( V_9 -> V_11 & V_121 ) {
V_10 = F_22 ( V_6 , V_100 -> V_102 ) ;
if ( V_10 )
goto V_61;
V_10 = F_6 ( V_9 -> V_13 , V_100 -> V_102 , V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
} else {
V_112 -> V_114 = V_124 ;
V_112 -> V_116 = F_46 ( V_6 -> V_116 ) ;
V_100 -> V_104 -> V_38 = V_108 ;
V_100 -> V_104 -> V_19 = V_6 ;
V_6 -> V_109 = V_120 ;
V_100 -> V_104 -> V_39 = V_112 ;
V_100 -> V_104 -> V_33 = sizeof( struct V_112 ) ;
V_10 = F_6 ( V_9 -> V_103 , V_100 -> V_104 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
}
F_23 ( & V_6 -> V_58 ) ;
F_24 ( V_42 ) ;
V_61:
return V_10 ;
}
static void F_51 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_19 ;
int V_10 ;
if ( V_14 -> V_20 < 0 )
return;
V_10 = F_52 ( V_9 , V_14 -> V_39 , V_14 -> V_62 ) ;
if ( ! V_10 )
return;
F_6 ( V_9 -> V_105 , V_9 -> V_6 . V_14 , V_15 ) ;
}
static int F_53 ( struct V_1 * V_9 , struct V_99 * V_100 )
{
V_100 -> V_101 = F_28 ( V_9 -> V_30 , V_40 ) ;
if ( ! V_100 -> V_101 )
goto V_122;
V_100 -> V_102 = F_28 ( V_9 -> V_13 , V_40 ) ;
if ( ! V_100 -> V_102 )
goto V_64;
V_100 -> V_104 = F_28 ( V_9 -> V_103 , V_40 ) ;
if ( ! V_100 -> V_104 )
goto V_66;
return 0 ;
V_66:
F_30 ( V_9 -> V_103 , V_100 -> V_104 ) ;
V_100 -> V_104 = NULL ;
V_64:
F_30 ( V_9 -> V_13 , V_100 -> V_102 ) ;
V_100 -> V_102 = NULL ;
V_122:
return - V_53 ;
}
static int F_54 ( struct V_1 * V_9 )
{
V_9 -> V_6 . V_14 = F_28 ( V_9 -> V_105 , V_40 ) ;
if ( ! V_9 -> V_6 . V_14 )
goto V_63;
V_9 -> V_6 . V_39 = F_18 ( V_9 -> V_105 -> V_32 , V_40 ) ;
if ( ! V_9 -> V_6 . V_39 )
goto V_70;
V_9 -> V_6 . V_14 -> V_38 = F_51 ;
V_9 -> V_6 . V_14 -> V_39 = V_9 -> V_6 . V_39 ;
V_9 -> V_6 . V_14 -> V_33 = V_9 -> V_105 -> V_32 ;
V_9 -> V_6 . V_14 -> V_19 = V_9 ;
return 0 ;
V_70:
F_30 ( V_9 -> V_105 , V_9 -> V_6 . V_14 ) ;
V_63:
return - V_53 ;
}
static void F_55 ( struct V_1 * V_9 , int V_125 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_125 ; V_106 ++ ) {
struct V_99 * V_126 = & V_9 -> V_100 [ V_106 ] ;
V_126 -> V_101 -> V_127 = V_106 + 1 ;
V_126 -> V_102 -> V_127 = V_106 + 1 ;
V_126 -> V_104 -> V_127 = V_106 + 1 ;
}
}
static int F_56 ( struct V_1 * V_9 )
{
int V_10 ;
int V_106 ;
int V_125 ;
if ( V_9 -> V_11 & V_121 )
V_125 = V_107 ;
else
V_125 = 1 ;
for ( V_106 = 0 ; V_106 < V_125 ; V_106 ++ ) {
V_10 = F_53 ( V_9 , & V_9 -> V_100 [ V_106 ] ) ;
if ( V_10 )
goto V_128;
}
V_10 = F_54 ( V_9 ) ;
if ( V_10 )
goto V_129;
F_55 ( V_9 , V_125 ) ;
V_10 = F_6 ( V_9 -> V_105 , V_9 -> V_6 . V_14 , V_15 ) ;
if ( V_10 )
goto V_129;
return 0 ;
V_129:
F_42 ( V_9 ) ;
V_128:
if ( V_106 ) {
do {
F_41 ( V_9 , & V_9 -> V_100 [ V_106 - 1 ] ) ;
V_106 -- ;
} while ( V_106 );
}
F_8 ( L_10 ) ;
return V_10 ;
}
static void F_57 ( struct V_1 * V_9 )
{
struct V_2 * V_3 = & V_9 -> V_4 ;
struct V_47 * V_48 = V_3 -> V_73 -> V_74 -> V_48 ;
int V_10 ;
V_9 -> V_11 = V_130 ;
if ( V_48 -> V_131 == V_132 )
V_9 -> V_11 |= V_121 ;
F_34 ( V_48 , V_3 , V_9 -> V_30 ) ;
V_10 = F_35 ( V_9 -> V_30 ) ;
if ( V_10 )
goto V_76;
F_34 ( V_48 , V_3 , V_9 -> V_13 ) ;
V_10 = F_35 ( V_9 -> V_13 ) ;
if ( V_10 )
goto V_77;
F_34 ( V_48 , V_3 , V_9 -> V_105 ) ;
V_10 = F_35 ( V_9 -> V_105 ) ;
if ( V_10 )
goto V_65;
F_34 ( V_48 , V_3 , V_9 -> V_103 ) ;
V_10 = F_35 ( V_9 -> V_103 ) ;
if ( V_10 )
goto V_133;
V_10 = F_56 ( V_9 ) ;
if ( V_10 )
goto V_78;
V_9 -> V_11 |= V_72 ;
F_36 ( L_11 ) ;
return;
V_78:
F_32 ( V_9 -> V_103 ) ;
V_133:
F_32 ( V_9 -> V_105 ) ;
V_65:
F_32 ( V_9 -> V_13 ) ;
V_77:
F_32 ( V_9 -> V_30 ) ;
V_76:
V_9 -> V_11 = 0 ;
}
static int F_58 ( const unsigned char * V_134 )
{
int V_10 ;
switch ( V_134 [ 0 ] ) {
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
case V_152 :
case V_153 :
V_10 = V_154 ;
break;
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
case V_165 :
case V_166 :
V_10 = V_167 ;
break;
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_10 = V_178 ;
break;
default:
#define F_59 "target: Unknown data direction for SCSI Opcode 0x%02x\n"
F_60 ( F_59 , V_134 [ 0 ] ) ;
#undef F_59
V_10 = - V_59 ;
}
return V_10 ;
}
static void V_60 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_42 * V_42 = & V_6 -> V_42 ;
if ( V_14 -> V_20 < 0 ) {
F_8 ( L_12 , V_21 , V_6 -> V_109 ) ;
goto V_61;
}
if ( V_14 -> V_56 == 0 ) {
F_61 ( V_42 -> V_54 ,
V_42 -> V_55 ,
V_6 -> V_51 ,
V_42 -> V_52 ) ;
}
V_38 ( & V_6 -> V_58 ) ;
return;
V_61:
F_3 ( V_6 ) ;
}
static int F_22 ( struct V_5 * V_6 , struct V_18 * V_14 )
{
struct V_42 * V_42 = & V_6 -> V_42 ;
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_47 * V_48 = F_17 ( V_9 ) ;
if ( ! V_48 -> V_50 ) {
V_6 -> V_51 = F_18 ( V_42 -> V_52 , V_15 ) ;
if ( ! V_6 -> V_51 )
return - V_53 ;
V_14 -> V_39 = V_6 -> V_51 ;
} else {
V_14 -> V_39 = NULL ;
V_14 -> V_56 = V_42 -> V_55 ;
V_14 -> V_57 = V_42 -> V_54 ;
}
V_14 -> V_38 = V_60 ;
V_14 -> V_33 = V_42 -> V_52 ;
V_14 -> V_19 = V_6 ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_42 , struct V_5 ,
V_42 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_75 )
return F_14 ( V_6 ) ;
else
return F_48 ( V_6 ) ;
}
static int F_63 ( struct V_42 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_42 , struct V_5 ,
V_42 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_75 )
return F_20 ( V_6 ) ;
else
return F_50 ( V_6 ) ;
}
static int F_64 ( struct V_42 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_42 , struct V_5 ,
V_42 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_75 )
return F_16 ( V_6 ) ;
else
return F_49 ( V_6 ) ;
}
static void F_65 ( struct V_179 * V_180 )
{
struct V_5 * V_6 = F_2 ( V_180 , struct V_5 , V_180 ) ;
struct V_42 * V_42 ;
struct V_181 * V_182 ;
struct V_183 * V_95 ;
int V_184 ;
V_42 = & V_6 -> V_42 ;
V_95 = V_6 -> V_9 -> V_95 ;
V_182 = V_95 -> V_185 ;
V_184 = F_58 ( V_6 -> V_186 ) ;
if ( V_184 < 0 ) {
F_66 ( V_42 ,
V_182 -> V_187 -> V_188 -> V_189 ,
V_182 -> V_187 , V_6 -> V_31 , V_178 ,
V_6 -> V_190 , V_6 -> V_111 . V_191 ) ;
goto V_122;
}
if ( F_67 ( V_42 , V_182 -> V_187 ,
V_6 -> V_186 , V_6 -> V_111 . V_191 , V_6 -> V_192 ,
0 , V_6 -> V_190 , V_184 , V_193 ) < 0 )
goto V_122;
return;
V_122:
F_68 ( V_42 ,
V_194 , 1 ) ;
F_3 ( V_6 ) ;
}
static int F_52 ( struct V_1 * V_9 ,
void * V_195 , unsigned int V_117 )
{
struct V_196 * V_197 = V_195 ;
struct V_5 * V_6 ;
struct V_183 * V_95 ;
struct V_181 * V_182 ;
T_3 V_198 ;
if ( V_197 -> V_114 != V_199 ) {
F_8 ( L_13 , V_197 -> V_114 ) ;
return - V_59 ;
}
V_6 = F_69 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_9 = V_9 ;
F_70 ( & V_6 -> V_7 ) ;
F_71 ( & V_6 -> V_7 ) ;
V_95 = V_9 -> V_95 ;
V_198 = ( V_197 -> V_117 & ~ 0x3 ) + 16 ;
if ( V_198 > V_200 )
goto V_63;
memcpy ( V_6 -> V_186 , V_197 -> V_134 , V_198 ) ;
V_6 -> V_116 = F_72 ( & V_197 -> V_116 ) ;
V_6 -> V_42 . V_116 = V_6 -> V_116 ;
if ( V_9 -> V_11 & V_121 ) {
if ( V_6 -> V_116 > V_107 )
goto V_63;
if ( ! V_6 -> V_116 )
V_6 -> V_100 = & V_9 -> V_100 [ 0 ] ;
else
V_6 -> V_100 = & V_9 -> V_100 [ V_6 -> V_116 - 1 ] ;
} else {
V_6 -> V_100 = & V_9 -> V_100 [ 0 ] ;
}
V_182 = V_95 -> V_185 ;
if ( ! V_182 ) {
F_8 ( L_14 ) ;
goto V_63;
}
switch ( V_197 -> V_190 & 0x7 ) {
case V_201 :
V_6 -> V_190 = V_202 ;
break;
case V_203 :
V_6 -> V_190 = V_204 ;
break;
case V_205 :
V_6 -> V_190 = V_206 ;
break;
default:
F_73 ( L_15 ,
V_197 -> V_190 ) ;
case V_207 :
V_6 -> V_190 = V_208 ;
break;
}
V_6 -> V_192 = F_74 ( & V_197 -> V_209 ) ;
F_75 ( & V_6 -> V_180 , F_65 ) ;
F_76 ( V_95 -> V_210 , & V_6 -> V_180 ) ;
return 0 ;
V_63:
F_29 ( V_6 ) ;
return - V_59 ;
}
static void F_77 ( struct V_179 * V_180 )
{
struct V_5 * V_6 = F_2 ( V_180 , struct V_5 , V_180 ) ;
struct V_42 * V_42 ;
struct V_181 * V_182 ;
struct V_183 * V_95 ;
int V_184 ;
V_42 = & V_6 -> V_42 ;
V_95 = V_6 -> V_9 -> V_95 ;
V_182 = V_95 -> V_185 ;
V_184 = F_58 ( V_6 -> V_186 ) ;
if ( V_184 < 0 ) {
F_66 ( V_42 ,
V_182 -> V_187 -> V_188 -> V_189 ,
V_182 -> V_187 , V_6 -> V_31 , V_178 ,
V_6 -> V_190 , V_6 -> V_111 . V_191 ) ;
goto V_122;
}
if ( F_67 ( V_42 , V_182 -> V_187 ,
V_6 -> V_186 , V_6 -> V_111 . V_191 , V_6 -> V_192 ,
V_6 -> V_31 , V_6 -> V_190 , V_184 , 0 ) < 0 )
goto V_122;
return;
V_122:
F_68 ( V_42 ,
V_194 , 1 ) ;
F_3 ( V_6 ) ;
}
static int F_26 ( struct V_1 * V_9 ,
void * V_195 , unsigned int V_117 )
{
struct V_211 * V_212 = V_195 ;
struct V_5 * V_6 ;
struct V_183 * V_95 ;
struct V_181 * V_182 ;
T_3 V_198 ;
if ( V_212 -> V_68 != F_12 ( V_213 ) ) {
F_8 ( L_16 ) ;
return - V_59 ;
}
if ( V_117 != 31 ) {
F_8 ( L_17 ) ;
return - V_59 ;
}
V_198 = V_212 -> V_214 ;
if ( V_198 < 1 || V_198 > 16 )
return - V_59 ;
V_6 = F_69 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_9 = V_9 ;
F_70 ( & V_6 -> V_7 ) ;
F_71 ( & V_6 -> V_7 ) ;
V_95 = V_9 -> V_95 ;
memcpy ( V_6 -> V_186 , V_212 -> V_215 , V_198 ) ;
V_6 -> V_28 = V_212 -> V_27 ;
V_182 = V_95 -> V_185 ;
if ( ! V_182 ) {
F_8 ( L_14 ) ;
goto V_63;
}
V_6 -> V_190 = V_208 ;
V_6 -> V_192 = V_212 -> V_216 ;
V_6 -> V_35 = V_212 -> V_217 & V_218 ? 1 : 0 ;
V_6 -> V_31 = F_78 ( V_212 -> V_219 ) ;
V_6 -> V_42 . V_116 = F_78 ( V_6 -> V_28 ) ;
F_75 ( & V_6 -> V_180 , F_77 ) ;
F_76 ( V_95 -> V_210 , & V_6 -> V_180 ) ;
return 0 ;
V_63:
F_29 ( V_6 ) ;
return - V_59 ;
}
static int F_79 ( struct V_220 * V_188 )
{
return 1 ;
}
static int F_80 ( struct V_220 * V_188 )
{
return 0 ;
}
static char * F_81 ( void )
{
return L_18 ;
}
static char * F_82 ( struct V_220 * V_188 )
{
struct V_183 * V_95 = F_2 ( V_188 ,
struct V_183 , V_188 ) ;
struct V_221 * V_222 = V_95 -> V_222 ;
return & V_222 -> V_223 [ 0 ] ;
}
static T_1 F_83 ( struct V_220 * V_188 )
{
struct V_183 * V_95 = F_2 ( V_188 ,
struct V_183 , V_188 ) ;
return V_95 -> V_224 ;
}
static T_3 F_84 ( struct V_220 * V_188 )
{
return 1 ;
}
static void V_8 ( struct V_225 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 , struct V_5 ,
V_7 ) ;
F_85 ( & V_6 -> V_42 , 0 ) ;
}
static void F_86 ( struct V_42 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_42 , struct V_5 ,
V_42 ) ;
F_29 ( V_6 -> V_51 ) ;
F_29 ( V_6 ) ;
}
static int F_87 ( struct V_226 * V_227 )
{
return 0 ;
}
static void F_88 ( struct V_226 * V_227 )
{
}
static T_3 F_89 ( struct V_226 * V_227 )
{
return 0 ;
}
static int F_90 ( struct V_42 * V_42 )
{
return 0 ;
}
static void F_91 ( struct V_228 * V_229 )
{
}
static int F_92 ( struct V_42 * V_42 )
{
return 0 ;
}
static void F_93 ( struct V_42 * V_42 )
{
}
static void F_94 ( struct V_42 * V_42 )
{
}
static const char * F_95 ( const char * V_230 )
{
const char * V_231 ;
unsigned int V_117 ;
V_231 = strstr ( V_230 , L_19 ) ;
if ( ! V_231 )
return NULL ;
V_231 += 4 ;
V_117 = strlen ( V_231 ) ;
if ( V_117 == 0 || V_117 > V_232 - 1 )
return NULL ;
return V_231 ;
}
static int F_96 ( struct V_228 * V_233 , const char * V_230 )
{
if ( ! F_95 ( V_230 ) )
return - V_59 ;
return 0 ;
}
static struct V_220 * F_97 (
struct V_234 * V_235 ,
struct V_236 * V_237 ,
const char * V_230 )
{
struct V_221 * V_222 = F_2 ( V_235 , struct V_221 ,
V_238 ) ;
struct V_183 * V_95 ;
unsigned long V_239 ;
int V_10 ;
struct V_240 * V_241 ;
unsigned V_106 ;
if ( strstr ( V_230 , L_20 ) != V_230 )
return F_98 ( - V_59 ) ;
if ( F_99 ( V_230 + 5 , 0 , & V_239 ) || V_239 > V_242 )
return F_98 ( - V_59 ) ;
V_10 = - V_243 ;
F_100 ( & V_244 ) ;
for ( V_106 = 0 ; V_106 < V_245 ; ++ V_106 )
if ( V_246 [ V_106 ] . V_247 && ! V_246 [ V_106 ] . V_95 )
break;
if ( V_106 == V_245 )
goto V_248;
V_241 = F_2 ( V_246 [ V_106 ] . V_247 , struct V_240 ,
V_247 ) ;
F_100 ( & V_241 -> V_249 ) ;
if ( ! V_241 -> V_250 )
goto V_251;
if ( V_241 -> V_252 ) {
if ( ! F_101 ( V_241 -> V_253 ) )
goto V_251;
} else {
V_10 = F_102 (
V_237 -> V_254 ,
& V_241 -> V_247 . V_237 . V_255 ) ;
if ( V_10 )
goto V_251;
}
V_95 = F_69 ( sizeof( struct V_183 ) , V_40 ) ;
V_10 = - V_53 ;
if ( ! V_95 )
goto V_256;
F_103 ( & V_95 -> V_257 ) ;
F_104 ( & V_95 -> V_96 , 0 ) ;
V_95 -> V_210 = F_105 ( L_21 , 0 , 1 ) ;
if ( ! V_95 -> V_210 )
goto V_258;
V_95 -> V_222 = V_222 ;
V_95 -> V_224 = V_239 ;
V_10 = F_106 ( V_235 , & V_95 -> V_188 , V_259 ) ;
if ( V_10 < 0 )
goto V_260;
V_246 [ V_106 ] . V_95 = V_95 ;
V_95 -> V_261 = V_246 [ V_106 ] . V_247 ;
F_107 ( & V_241 -> V_249 ) ;
F_107 ( & V_244 ) ;
return & V_95 -> V_188 ;
V_260:
F_108 ( V_95 -> V_210 ) ;
V_258:
F_29 ( V_95 ) ;
V_256:
if ( V_241 -> V_252 )
F_109 ( V_241 -> V_253 ) ;
else
F_110 ( & V_241 -> V_247 . V_237 . V_255 ) ;
V_251:
F_107 ( & V_241 -> V_249 ) ;
V_248:
F_107 ( & V_244 ) ;
return F_98 ( V_10 ) ;
}
static void F_111 ( struct V_220 * V_188 )
{
struct V_183 * V_95 = F_2 ( V_188 ,
struct V_183 , V_188 ) ;
unsigned V_106 ;
struct V_240 * V_241 ;
F_112 ( V_95 ) ;
F_113 ( V_188 ) ;
F_108 ( V_95 -> V_210 ) ;
F_100 ( & V_244 ) ;
for ( V_106 = 0 ; V_106 < V_245 ; ++ V_106 )
if ( V_246 [ V_106 ] . V_95 == V_95 )
break;
if ( V_106 < V_245 )
V_246 [ V_106 ] . V_95 = NULL ;
V_241 = F_2 ( V_246 [ V_106 ] . V_247 ,
struct V_240 , V_247 ) ;
F_100 ( & V_241 -> V_249 ) ;
if ( V_241 -> V_252 )
F_109 ( V_241 -> V_253 ) ;
else
F_110 ( & V_241 -> V_247 . V_237 . V_255 ) ;
F_107 ( & V_241 -> V_249 ) ;
F_107 ( & V_244 ) ;
F_29 ( V_95 ) ;
}
static struct V_234 * F_114 (
struct V_262 * V_263 ,
struct V_236 * V_237 ,
const char * V_230 )
{
struct V_221 * V_222 ;
const char * V_264 ;
T_4 V_265 = 0 ;
V_264 = F_95 ( V_230 ) ;
if ( ! V_264 )
return F_98 ( - V_59 ) ;
V_222 = F_69 ( sizeof( struct V_221 ) , V_40 ) ;
if ( ! ( V_222 ) )
return F_98 ( - V_53 ) ;
V_222 -> V_266 = V_265 ;
snprintf ( V_222 -> V_223 , sizeof( V_222 -> V_223 ) , L_22 , V_264 ) ;
return & V_222 -> V_238 ;
}
static void F_115 ( struct V_234 * V_235 )
{
struct V_221 * V_222 = F_2 ( V_235 ,
struct V_221 , V_238 ) ;
F_29 ( V_222 ) ;
}
static T_5 F_116 ( struct V_267 * V_268 , char * V_269 )
{
return sprintf ( V_269 , L_23 ) ;
}
static T_5 F_117 ( struct V_267 * V_268 , char * V_269 )
{
struct V_220 * V_188 = F_118 ( V_268 ) ;
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
return snprintf ( V_269 , V_270 , L_24 , V_95 -> V_271 ) ;
}
static T_5 F_119 ( struct V_267 * V_268 ,
const char * V_269 , T_6 V_272 )
{
struct V_220 * V_188 = F_118 ( V_268 ) ;
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
bool V_273 ;
T_5 V_10 ;
V_10 = F_120 ( V_269 , & V_273 ) ;
if ( V_10 )
return V_10 ;
if ( ( V_273 && V_95 -> V_271 ) || ( ! V_273 && ! V_95 -> V_271 ) )
return - V_59 ;
if ( V_273 )
V_10 = F_121 ( V_95 ) ;
else
F_122 ( V_95 ) ;
if ( V_10 )
return V_10 ;
V_95 -> V_271 = V_273 ;
return V_272 ;
}
static T_5 F_123 ( struct V_267 * V_268 , char * V_269 )
{
struct V_220 * V_188 = F_118 ( V_268 ) ;
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
struct V_181 * V_182 ;
T_5 V_10 ;
F_100 ( & V_95 -> V_257 ) ;
V_182 = V_95 -> V_185 ;
if ( ! V_182 ) {
V_10 = - V_243 ;
goto V_122;
}
V_10 = snprintf ( V_269 , V_270 , L_25 ,
V_182 -> V_187 -> V_228 -> V_274 ) ;
V_122:
F_107 ( & V_95 -> V_257 ) ;
return V_10 ;
}
static int F_124 ( struct V_183 * V_95 , char * V_230 )
{
struct V_220 * V_188 ;
struct V_181 * V_182 ;
int V_10 ;
F_100 ( & V_95 -> V_257 ) ;
if ( V_95 -> V_185 ) {
V_10 = - V_275 ;
F_125 ( L_26 ) ;
goto V_276;
}
V_188 = & V_95 -> V_188 ;
V_10 = - V_53 ;
V_182 = F_69 ( sizeof( * V_182 ) , V_40 ) ;
if ( ! V_182 )
goto V_276;
V_182 -> V_187 = F_126 ( V_277 ) ;
if ( F_127 ( V_182 -> V_187 ) )
goto V_278;
V_182 -> V_187 -> V_228 = F_128 (
V_188 , V_230 ) ;
if ( ! V_182 -> V_187 -> V_228 ) {
#define F_129 "core_tpg_check_initiator_node_acl() failed for %s\n"
F_125 ( F_129 , V_230 ) ;
#undef F_129
goto V_279;
}
F_130 ( V_188 , V_182 -> V_187 -> V_228 ,
V_182 -> V_187 , V_182 ) ;
V_95 -> V_185 = V_182 ;
F_107 ( & V_95 -> V_257 ) ;
return 0 ;
V_279:
F_131 ( V_182 -> V_187 ) ;
V_278:
F_29 ( V_182 ) ;
V_276:
F_107 ( & V_95 -> V_257 ) ;
return V_10 ;
}
static int F_112 ( struct V_183 * V_95 )
{
struct V_226 * V_227 ;
struct V_181 * V_182 ;
int V_10 = - V_243 ;
F_100 ( & V_95 -> V_257 ) ;
V_182 = V_95 -> V_185 ;
if ( ! V_182 )
goto V_122;
V_227 = V_182 -> V_187 ;
if ( ! V_227 )
goto V_122;
if ( F_39 ( & V_95 -> V_96 ) ) {
V_10 = - V_280 ;
#define F_132 "Unable to remove Host I_T Nexus with active TPG port count: %d\n"
F_8 ( F_132 , F_39 ( & V_95 -> V_96 ) ) ;
#undef F_132
goto V_122;
}
F_125 ( L_27 ,
V_182 -> V_187 -> V_228 -> V_274 ) ;
F_133 ( V_182 -> V_187 ) ;
V_95 -> V_185 = NULL ;
F_29 ( V_182 ) ;
V_10 = 0 ;
V_122:
F_107 ( & V_95 -> V_257 ) ;
return V_10 ;
}
static T_5 F_134 ( struct V_267 * V_268 ,
const char * V_269 , T_6 V_272 )
{
struct V_220 * V_188 = F_118 ( V_268 ) ;
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
unsigned char V_281 [ V_232 ] , * V_282 ;
int V_10 ;
if ( ! strncmp ( V_269 , L_28 , 4 ) ) {
V_10 = F_112 ( V_95 ) ;
return ( ! V_10 ) ? V_272 : V_10 ;
}
if ( strlen ( V_269 ) >= V_232 ) {
#define F_135 "Emulated NAA Sas Address: %s, exceeds max: %d\n"
F_8 ( F_135 , V_269 , V_232 ) ;
#undef F_135
return - V_59 ;
}
snprintf ( V_281 , V_232 , L_22 , V_269 ) ;
V_282 = strstr ( V_281 , L_19 ) ;
if ( ! V_282 ) {
F_8 ( L_29 ) ;
return - V_59 ;
}
if ( V_281 [ strlen ( V_281 ) - 1 ] == '\n' )
V_281 [ strlen ( V_281 ) - 1 ] = '\0' ;
V_10 = F_124 ( V_95 , & V_281 [ 0 ] ) ;
if ( V_10 < 0 )
return V_10 ;
return V_272 ;
}
static int F_136 ( struct V_220 * V_188 , struct V_283 * V_209 )
{
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
F_137 ( & V_95 -> V_96 ) ;
F_138 () ;
return 0 ;
}
static void F_139 ( struct V_220 * V_188 ,
struct V_283 * V_283 )
{
struct V_183 * V_95 = F_2 ( V_188 , struct V_183 , V_188 ) ;
F_140 ( & V_95 -> V_96 ) ;
F_138 () ;
}
static int F_141 ( struct V_42 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_42 , struct V_5 ,
V_42 ) ;
F_4 ( & V_6 -> V_7 , V_8 ) ;
return 1 ;
}
static int F_142 ( struct V_284 * V_285 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_286 * V_287 ;
struct V_47 * V_48 = V_285 -> V_74 -> V_48 ;
struct V_16 * V_17 ;
struct V_240 * V_241 ;
int V_288 ;
int V_10 ;
V_241 = F_2 ( V_3 -> V_261 , struct V_240 , V_247 ) ;
F_100 ( & V_241 -> V_249 ) ;
if ( ! V_241 -> V_289 ) {
F_107 ( & V_241 -> V_249 ) ;
return - V_243 ;
}
F_107 ( & V_241 -> V_249 ) ;
V_287 = F_143 ( V_285 -> V_74 , V_290 ,
F_144 ( V_291 ) ) ;
if ( F_127 ( V_287 ) )
return F_145 ( V_287 ) ;
V_292 . V_293 = V_287 [ V_294 ] . V_295 ;
V_296 . V_293 = V_287 [ V_297 ] . V_295 ;
V_288 = F_146 ( V_285 , V_3 ) ;
if ( V_288 < 0 )
return V_288 ;
V_292 . V_298 = V_288 ;
V_296 . V_298 = V_288 ;
V_9 -> V_288 = V_288 ;
V_17 = F_147 ( V_48 , & V_299 ,
& V_300 ) ;
if ( ! V_17 )
goto V_301;
V_9 -> V_30 = V_17 ;
V_17 = F_147 ( V_48 , & V_302 ,
& V_303 ) ;
if ( ! V_17 )
goto V_301;
V_9 -> V_13 = V_17 ;
V_17 = F_147 ( V_48 , & V_304 ,
& V_305 ) ;
if ( ! V_17 )
goto V_301;
V_9 -> V_103 = V_17 ;
V_17 = F_147 ( V_48 , & V_306 ,
& V_307 ) ;
if ( ! V_17 )
goto V_301;
V_9 -> V_105 = V_17 ;
V_308 . V_309 = V_299 . V_309 ;
V_310 . V_309 = V_302 . V_309 ;
V_311 . V_309 =
V_304 . V_309 ;
V_312 . V_309 = V_306 . V_309 ;
V_313 . V_309 = V_299 . V_309 ;
V_314 . V_309 = V_302 . V_309 ;
V_315 . V_309 =
V_304 . V_309 ;
V_316 . V_309 = V_306 . V_309 ;
V_10 = F_148 ( V_3 , V_317 ,
V_318 , V_319 ) ;
if ( V_10 )
goto V_301;
return 0 ;
V_301:
F_8 ( L_30 ) ;
return - V_94 ;
}
static void F_149 ( struct V_179 * V_320 )
{
struct V_321 * V_180 = F_2 ( V_320 , struct V_321 ,
V_180 ) ;
struct V_1 * V_9 = V_180 -> V_9 ;
int V_322 = V_180 -> V_322 ;
F_29 ( V_180 ) ;
if ( V_9 -> V_11 & V_75 )
F_31 ( V_9 ) ;
if ( V_9 -> V_11 & V_130 )
F_43 ( V_9 ) ;
if ( V_322 == V_323 )
F_33 ( V_9 ) ;
else if ( V_322 == V_324 )
F_57 ( V_9 ) ;
F_150 ( V_9 -> V_4 . V_73 -> V_74 ) ;
}
static int F_151 ( struct V_2 * V_3 , unsigned V_325 , unsigned V_322 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ( V_322 == V_323 ) || ( V_322 == V_324 ) ) {
struct V_321 * V_180 ;
V_180 = F_18 ( sizeof( * V_180 ) , V_15 ) ;
if ( ! V_180 )
return - V_53 ;
F_75 ( & V_180 -> V_180 , F_149 ) ;
V_180 -> V_9 = V_9 ;
V_180 -> V_322 = V_322 ;
F_152 ( & V_180 -> V_180 ) ;
return V_326 ;
}
return - V_327 ;
}
static void F_153 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( V_9 -> V_11 & V_130 )
F_43 ( V_9 ) ;
else if ( V_9 -> V_11 & V_75 )
F_31 ( V_9 ) ;
V_9 -> V_11 = 0 ;
}
static int F_154 ( struct V_2 * V_3 ,
const struct V_79 * V_80 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! ( V_9 -> V_11 & V_75 ) )
return - V_327 ;
return F_37 ( V_3 , V_80 ) ;
}
static inline struct V_240 * F_155 ( struct V_267 * V_268 )
{
return F_2 ( F_156 ( V_268 ) , struct V_240 ,
V_247 . V_237 ) ;
}
static void F_157 ( struct V_267 * V_268 )
{
struct V_240 * V_241 = F_155 ( V_268 ) ;
F_158 ( & V_241 -> V_247 ) ;
}
static void F_159 ( struct V_328 * V_3 )
{
struct V_240 * V_241 ;
unsigned V_106 ;
V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
F_100 ( & V_244 ) ;
for ( V_106 = 0 ; V_106 < V_245 ; ++ V_106 )
if ( V_246 [ V_106 ] . V_247 == V_3 )
break;
if ( V_106 < V_245 )
V_246 [ V_106 ] . V_247 = NULL ;
F_107 ( & V_244 ) ;
F_29 ( V_241 ) ;
}
static int F_160 ( struct V_328 * V_3 )
{
struct V_240 * V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
F_100 ( & V_241 -> V_249 ) ;
V_241 -> V_289 = true ;
F_107 ( & V_241 -> V_249 ) ;
return 0 ;
}
static void F_161 ( struct V_328 * V_3 )
{
struct V_240 * V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
F_100 ( & V_241 -> V_249 ) ;
F_162 ( V_241 ->
V_247 . V_237 . V_255 . V_329 -> V_329 ) ;
V_241 -> V_289 = false ;
F_107 ( & V_241 -> V_249 ) ;
}
static int F_121 ( struct V_183 * V_95 )
{
struct V_328 * V_3 = V_95 -> V_261 ;
struct V_240 * V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
if ( V_241 -> F_160 )
return V_241 -> F_160 ( V_3 ) ;
return 0 ;
}
static void F_122 ( struct V_183 * V_95 )
{
struct V_328 * V_3 = V_95 -> V_261 ;
struct V_240 * V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
if ( V_241 -> F_161 )
V_241 -> F_161 ( V_3 ) ;
}
static int F_163 ( struct V_328 * V_3 , const char * V_230 )
{
struct V_240 * V_241 = F_2 ( V_3 , struct V_240 , V_247 ) ;
F_125 ( L_31 , V_230 ) ;
F_100 ( & V_241 -> V_249 ) ;
V_241 -> V_250 = true ;
F_107 ( & V_241 -> V_249 ) ;
return 0 ;
}
static struct V_328 * F_164 ( void )
{
struct V_240 * V_241 ;
int V_106 ;
V_241 = F_69 ( sizeof( * V_241 ) , V_40 ) ;
if ( ! V_241 )
return F_98 ( - V_53 ) ;
F_100 ( & V_244 ) ;
for ( V_106 = 0 ; V_106 < V_245 ; ++ V_106 )
if ( ! V_246 [ V_106 ] . V_247 )
break;
if ( V_106 == V_245 ) {
F_107 ( & V_244 ) ;
F_29 ( V_241 ) ;
return F_98 ( - V_330 ) ;
}
V_246 [ V_106 ] . V_247 = & V_241 -> V_247 ;
F_107 ( & V_244 ) ;
F_103 ( & V_241 -> V_249 ) ;
V_241 -> V_247 . V_331 = F_163 ;
V_241 -> V_247 . V_332 = F_159 ;
V_241 -> F_160 = F_160 ;
V_241 -> F_161 = F_161 ;
F_165 ( & V_241 -> V_247 . V_237 , L_32 ,
& V_333 ) ;
return & V_241 -> V_247 ;
}
static void F_166 ( struct V_2 * V_3 )
{
struct V_1 * V_334 = F_1 ( V_3 ) ;
F_29 ( V_334 ) ;
}
static void F_167 ( struct V_284 * V_285 , struct V_2 * V_3 )
{
F_168 ( V_3 ) ;
}
static struct V_2 * F_169 ( struct V_328 * V_261 )
{
struct V_1 * V_9 ;
unsigned V_106 ;
F_100 ( & V_244 ) ;
for ( V_106 = 0 ; V_106 < V_245 ; ++ V_106 )
if ( V_246 [ V_106 ] . V_247 == V_261 )
break;
if ( V_106 == V_245 ) {
F_107 ( & V_244 ) ;
return F_98 ( - V_243 ) ;
}
V_9 = F_69 ( sizeof( * V_9 ) , V_40 ) ;
if ( ! V_9 ) {
F_107 ( & V_244 ) ;
return F_98 ( - V_53 ) ;
}
V_9 -> V_4 . V_230 = L_33 ;
V_9 -> V_4 . V_335 = F_142 ;
V_9 -> V_4 . V_336 = F_167 ;
V_9 -> V_4 . V_337 = F_151 ;
V_9 -> V_4 . V_338 = F_154 ;
V_9 -> V_4 . V_339 = F_153 ;
V_9 -> V_4 . V_340 = F_166 ;
V_9 -> V_95 = V_246 [ V_106 ] . V_95 ;
F_107 ( & V_244 ) ;
return & V_9 -> V_4 ;
}
static int F_170 ( void )
{
int V_10 ;
V_10 = F_171 ( & V_341 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_172 ( & V_342 ) ;
if ( V_10 )
F_173 ( & V_341 ) ;
return V_10 ;
}
static void F_174 ( void )
{
F_175 ( & V_342 ) ;
F_173 ( & V_341 ) ;
}
