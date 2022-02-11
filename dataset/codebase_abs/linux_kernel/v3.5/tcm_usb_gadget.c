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
T_1 * V_25 ;
unsigned int V_26 ;
V_26 = V_6 -> V_27 ;
V_25 = V_6 -> V_28 . V_25 ;
V_23 -> V_29 = V_6 -> V_30 ;
V_23 -> V_31 = V_26 ;
V_9 -> V_24 . V_14 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_32 , V_9 -> V_24 . V_14 , V_15 ) ;
if ( V_10 )
F_8 ( L_2 , V_21 , __LINE__ , V_10 ) ;
}
static void F_10 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_14 -> V_20 < 0 )
F_8 ( L_1 , V_21 , __LINE__ ) ;
if ( V_6 -> V_33 ) {
if ( V_6 -> V_33 > V_17 -> V_34 ) {
V_14 -> V_35 = V_17 -> V_34 ;
V_6 -> V_33 -= V_17 -> V_34 ;
} else {
V_14 -> V_35 = V_6 -> V_33 ;
V_6 -> V_33 = 0 ;
}
F_6 ( V_17 , V_14 , V_15 ) ;
return ;
}
F_9 ( V_9 , V_6 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_22 * V_23 = & V_9 -> V_24 . V_23 ;
struct V_18 * V_14 ;
struct V_16 * V_17 ;
V_23 -> V_36 = F_12 ( V_6 -> V_33 ) ;
if ( V_6 -> V_33 ) {
if ( V_6 -> V_37 ) {
V_17 = V_9 -> V_32 ;
V_14 = V_9 -> V_38 ;
} else {
V_17 = V_9 -> V_13 ;
V_14 = V_9 -> V_39 ;
}
if ( V_6 -> V_33 > V_9 -> V_32 -> V_34 ) {
V_14 -> V_35 = V_17 -> V_34 ;
V_6 -> V_33 -= V_17 -> V_34 ;
} else {
V_14 -> V_35 = V_6 -> V_33 ;
V_6 -> V_33 = 0 ;
}
V_14 -> V_40 = F_10 ;
V_14 -> V_19 = V_6 ;
V_14 -> V_41 = V_9 -> V_6 . V_41 ;
F_6 ( V_17 , V_14 , V_42 ) ;
} else {
F_9 ( V_9 , V_6 ) ;
}
}
static int F_13 ( struct V_5 * V_6 , bool V_43 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_22 * V_23 = & V_9 -> V_24 . V_23 ;
int V_10 ;
if ( V_6 -> V_44 . V_45 == V_46 ) {
if ( ! V_43 && V_6 -> V_33 ) {
V_6 -> V_27 = V_47 ;
F_11 ( V_6 ) ;
return 0 ;
}
V_23 -> V_29 = V_6 -> V_30 ;
V_23 -> V_36 = F_12 ( 0 ) ;
V_23 -> V_31 = V_47 ;
V_9 -> V_24 . V_14 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_32 , V_9 -> V_24 . V_14 , V_42 ) ;
if ( V_10 )
F_8 ( L_2 , V_21 , __LINE__ , V_10 ) ;
} else {
V_6 -> V_27 = V_48 ;
F_11 ( V_6 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
bool V_43 = false ;
if ( ! V_6 -> V_37 )
V_43 = true ;
return F_13 ( V_6 , V_43 ) ;
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
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_49 * V_50 = F_17 ( V_9 ) ;
int V_10 ;
if ( ! V_6 -> V_33 ) {
V_6 -> V_27 = V_51 ;
F_11 ( V_6 ) ;
return 0 ;
}
if ( ! V_50 -> V_52 ) {
V_6 -> V_53 = F_18 ( V_44 -> V_54 , V_15 ) ;
if ( ! V_6 -> V_53 )
return - V_55 ;
F_19 ( V_44 -> V_56 ,
V_44 -> V_57 ,
V_6 -> V_53 ,
V_44 -> V_54 ) ;
V_9 -> V_38 -> V_41 = V_6 -> V_53 ;
} else {
V_9 -> V_38 -> V_41 = NULL ;
V_9 -> V_38 -> V_58 = V_44 -> V_57 ;
V_9 -> V_38 -> V_59 = V_44 -> V_56 ;
}
V_9 -> V_38 -> V_40 = F_15 ;
V_9 -> V_38 -> V_35 = V_44 -> V_54 ;
V_9 -> V_38 -> V_19 = V_6 ;
V_10 = F_6 ( V_9 -> V_32 , V_9 -> V_38 , V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_49 * V_50 = F_17 ( V_9 ) ;
int V_10 ;
F_21 ( & V_6 -> V_60 ) ;
V_6 -> V_9 = V_9 ;
if ( ! V_6 -> V_33 ) {
V_6 -> V_27 = V_51 ;
return - V_61 ;
}
if ( ! V_50 -> V_52 ) {
V_6 -> V_53 = F_18 ( V_44 -> V_54 , V_42 ) ;
if ( ! V_6 -> V_53 )
return - V_55 ;
V_9 -> V_39 -> V_41 = V_6 -> V_53 ;
} else {
V_9 -> V_39 -> V_41 = NULL ;
V_9 -> V_39 -> V_58 = V_44 -> V_57 ;
V_9 -> V_39 -> V_59 = V_44 -> V_56 ;
}
V_9 -> V_39 -> V_40 = V_62 ;
V_9 -> V_39 -> V_35 = V_44 -> V_54 ;
V_9 -> V_39 -> V_19 = V_6 ;
V_10 = F_22 ( V_6 , V_9 -> V_39 ) ;
if ( V_10 )
goto V_63;
V_10 = F_6 ( V_9 -> V_13 , V_9 -> V_39 , V_42 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
F_23 ( & V_6 -> V_60 ) ;
F_24 ( V_44 ) ;
V_63:
return V_10 ;
}
static void F_25 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_19 ;
int V_10 ;
V_9 -> V_11 &= ~ V_12 ;
if ( V_14 -> V_20 < 0 )
return;
V_10 = F_26 ( V_9 , V_14 -> V_41 , V_14 -> V_64 ) ;
if ( V_10 )
F_8 ( L_4 , V_21 , __LINE__ , V_10 ) ;
}
static int F_27 ( struct V_1 * V_9 )
{
int V_10 ;
V_9 -> V_38 = F_28 ( V_9 -> V_32 , V_42 ) ;
if ( ! V_9 -> V_38 )
goto V_65;
V_9 -> V_39 = F_28 ( V_9 -> V_13 , V_42 ) ;
if ( ! V_9 -> V_39 )
goto V_66;
V_9 -> V_6 . V_14 = F_28 ( V_9 -> V_13 , V_42 ) ;
if ( ! V_9 -> V_6 . V_14 )
goto V_67;
V_9 -> V_24 . V_14 = F_28 ( V_9 -> V_32 , V_42 ) ;
if ( ! V_9 -> V_24 . V_14 )
goto V_68;
V_9 -> V_24 . V_14 -> V_41 = & V_9 -> V_24 . V_23 ;
V_9 -> V_24 . V_14 -> V_35 = V_69 ;
V_9 -> V_24 . V_14 -> V_40 = F_7 ;
V_9 -> V_24 . V_23 . V_70 = F_12 ( V_71 ) ;
V_9 -> V_6 . V_41 = F_18 ( V_9 -> V_13 -> V_34 , V_42 ) ;
if ( ! V_9 -> V_6 . V_41 )
goto V_72;
V_9 -> V_6 . V_14 -> V_40 = F_25 ;
V_9 -> V_6 . V_14 -> V_41 = V_9 -> V_6 . V_41 ;
V_9 -> V_6 . V_14 -> V_35 = V_9 -> V_13 -> V_34 ;
V_9 -> V_6 . V_14 -> V_19 = V_9 ;
V_10 = F_5 ( V_9 ) ;
if ( V_10 )
goto V_73;
return 0 ;
V_73:
F_29 ( V_9 -> V_6 . V_41 ) ;
V_9 -> V_6 . V_41 = NULL ;
V_72:
F_30 ( V_9 -> V_32 , V_9 -> V_24 . V_14 ) ;
V_68:
F_30 ( V_9 -> V_13 , V_9 -> V_6 . V_14 ) ;
V_9 -> V_6 . V_14 = NULL ;
V_67:
F_30 ( V_9 -> V_13 , V_9 -> V_39 ) ;
V_9 -> V_39 = NULL ;
V_66:
F_30 ( V_9 -> V_32 , V_9 -> V_38 ) ;
V_9 -> V_38 = NULL ;
V_65:
F_8 ( L_5 ) ;
return - V_55 ;
}
void F_31 ( struct V_1 * V_9 )
{
if ( ! ( V_9 -> V_11 & V_74 ) )
return;
F_32 ( V_9 -> V_32 ) ;
F_32 ( V_9 -> V_13 ) ;
if ( ! V_9 -> V_38 )
return;
F_30 ( V_9 -> V_32 , V_9 -> V_38 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_39 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_6 . V_14 ) ;
F_30 ( V_9 -> V_13 , V_9 -> V_24 . V_14 ) ;
F_29 ( V_9 -> V_6 . V_41 ) ;
V_9 -> V_38 = NULL ;
V_9 -> V_39 = NULL ;
V_9 -> V_6 . V_14 = NULL ;
V_9 -> V_24 . V_14 = NULL ;
V_9 -> V_6 . V_41 = NULL ;
}
static void F_33 ( struct V_1 * V_9 )
{
struct V_2 * V_3 = & V_9 -> V_4 ;
struct V_49 * V_50 = V_3 -> V_75 -> V_76 -> V_50 ;
int V_10 ;
V_9 -> V_11 = V_77 ;
F_34 ( V_50 , V_3 , V_9 -> V_32 ) ;
V_10 = F_35 ( V_9 -> V_32 ) ;
if ( V_10 )
goto V_78;
F_34 ( V_50 , V_3 , V_9 -> V_13 ) ;
V_10 = F_35 ( V_9 -> V_13 ) ;
if ( V_10 )
goto V_79;
V_10 = F_27 ( V_9 ) ;
if ( V_10 )
goto V_80;
V_9 -> V_11 |= V_74 ;
F_36 ( L_6 ) ;
return;
V_80:
F_32 ( V_9 -> V_13 ) ;
V_79:
F_32 ( V_9 -> V_32 ) ;
V_78:
V_9 -> V_11 = V_77 ;
}
static int F_37 ( struct V_2 * V_3 ,
const struct V_81 * V_82 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_83 * V_76 = V_3 -> V_75 -> V_76 ;
T_2 V_84 = F_38 ( V_82 -> V_85 ) ;
T_2 V_86 = F_38 ( V_82 -> V_87 ) ;
int V_88 ;
T_1 * V_89 ;
switch ( V_82 -> V_90 ) {
case V_91 :
if ( V_82 -> V_92 != ( V_93 | V_94 |
V_95 ) )
return - V_96 ;
if ( V_86 < 1 )
return - V_61 ;
if ( V_84 != 0 )
return - V_61 ;
V_88 = F_39 ( & V_9 -> V_97 -> V_98 ) ;
if ( ! V_88 ) {
F_8 ( L_7 ) ;
return - V_61 ;
}
V_88 -- ;
if ( V_88 > 0xf ) {
F_40 ( L_8 ) ;
V_88 = 0xf ;
}
V_89 = V_76 -> V_14 -> V_41 ;
* V_89 = V_88 ;
V_76 -> V_14 -> V_35 = 1 ;
return F_6 ( V_76 -> V_50 -> V_99 , V_76 -> V_14 , V_15 ) ;
break;
case V_100 :
F_5 ( V_9 ) ;
return 0 ;
break;
} ;
return - V_96 ;
}
static void F_41 ( struct V_1 * V_9 , struct V_101 * V_102 )
{
if ( ! V_102 -> V_103 )
return;
F_30 ( V_9 -> V_32 , V_102 -> V_103 ) ;
F_30 ( V_9 -> V_13 , V_102 -> V_104 ) ;
F_30 ( V_9 -> V_105 , V_102 -> V_106 ) ;
V_102 -> V_103 = NULL ;
V_102 -> V_104 = NULL ;
V_102 -> V_106 = NULL ;
}
static void F_42 ( struct V_1 * V_9 )
{
F_30 ( V_9 -> V_107 , V_9 -> V_6 . V_14 ) ;
F_29 ( V_9 -> V_6 . V_41 ) ;
V_9 -> V_6 . V_14 = NULL ;
V_9 -> V_6 . V_41 = NULL ;
}
static void F_43 ( struct V_1 * V_9 )
{
int V_108 ;
if ( ! ( V_9 -> V_11 & V_74 ) )
return;
F_32 ( V_9 -> V_32 ) ;
F_32 ( V_9 -> V_13 ) ;
F_32 ( V_9 -> V_105 ) ;
F_32 ( V_9 -> V_107 ) ;
for ( V_108 = 0 ; V_108 < V_109 ; V_108 ++ )
F_41 ( V_9 , & V_9 -> V_102 [ V_108 ] ) ;
F_42 ( V_9 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_49 * V_50 = F_17 ( V_9 ) ;
struct V_101 * V_102 = V_6 -> V_102 ;
if ( ! V_50 -> V_52 ) {
V_6 -> V_53 = F_18 ( V_44 -> V_54 , V_15 ) ;
if ( ! V_6 -> V_53 )
return - V_55 ;
F_19 ( V_44 -> V_56 ,
V_44 -> V_57 ,
V_6 -> V_53 ,
V_44 -> V_54 ) ;
V_102 -> V_103 -> V_41 = V_6 -> V_53 ;
} else {
V_102 -> V_103 -> V_41 = NULL ;
V_102 -> V_103 -> V_58 = V_44 -> V_57 ;
V_102 -> V_103 -> V_59 = V_44 -> V_56 ;
}
V_102 -> V_103 -> V_40 = V_110 ;
V_102 -> V_103 -> V_35 = V_44 -> V_54 ;
V_102 -> V_103 -> V_19 = V_6 ;
V_6 -> V_111 = V_112 ;
return 0 ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_28 * V_113 = & V_6 -> V_28 ;
struct V_101 * V_102 = V_6 -> V_102 ;
V_6 -> V_111 = V_114 ;
V_113 -> V_115 = V_116 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
V_113 -> V_118 = F_46 ( V_44 -> V_119 ) ;
V_113 -> V_20 = V_44 -> V_45 ;
V_102 -> V_106 -> V_19 = V_6 ;
V_102 -> V_106 -> V_35 = V_44 -> V_119 + 16 ;
V_102 -> V_106 -> V_41 = V_113 ;
V_102 -> V_106 -> V_40 = V_110 ;
}
static void V_110 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_101 * V_102 = V_6 -> V_102 ;
struct V_1 * V_9 = V_6 -> V_9 ;
int V_10 ;
if ( V_14 -> V_20 < 0 )
goto V_63;
switch ( V_6 -> V_111 ) {
case V_120 :
V_10 = F_44 ( V_6 ) ;
if ( V_10 )
goto V_63;
V_10 = F_6 ( V_9 -> V_32 , V_102 -> V_103 , V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_121 :
V_10 = F_22 ( V_6 , V_102 -> V_104 ) ;
if ( V_10 )
goto V_63;
V_10 = F_6 ( V_9 -> V_13 , V_102 -> V_104 , V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_112 :
F_45 ( V_6 ) ;
V_10 = F_6 ( V_9 -> V_105 , V_102 -> V_106 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
break;
case V_114 :
F_3 ( V_6 ) ;
F_6 ( V_9 -> V_107 , V_9 -> V_6 . V_14 , V_15 ) ;
break;
default:
F_47 () ;
} ;
return;
V_63:
F_3 ( V_6 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_101 * V_102 = V_6 -> V_102 ;
struct V_28 * V_113 = & V_6 -> V_28 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
V_102 -> V_106 -> V_40 = V_110 ;
V_102 -> V_106 -> V_19 = V_6 ;
V_6 -> V_9 = V_9 ;
F_45 ( V_6 ) ;
return F_6 ( V_9 -> V_105 , V_102 -> V_106 , V_15 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_101 * V_102 = V_6 -> V_102 ;
struct V_28 * V_113 = & V_6 -> V_28 ;
int V_10 ;
V_6 -> V_9 = V_9 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
if ( V_9 -> V_11 & V_122 ) {
V_10 = F_44 ( V_6 ) ;
if ( V_10 )
goto V_123;
V_10 = F_6 ( V_9 -> V_32 , V_102 -> V_103 , V_15 ) ;
if ( V_10 ) {
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
F_29 ( V_6 -> V_53 ) ;
V_6 -> V_53 = NULL ;
}
} else {
V_113 -> V_115 = V_124 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
V_102 -> V_106 -> V_40 = V_110 ;
V_102 -> V_106 -> V_19 = V_6 ;
V_6 -> V_111 = V_120 ;
V_102 -> V_106 -> V_41 = V_113 ;
V_102 -> V_106 -> V_35 = sizeof( struct V_113 ) ;
V_10 = F_6 ( V_9 -> V_105 , V_102 -> V_106 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_9 , V_21 , __LINE__ , V_10 ) ;
}
V_123:
return V_10 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_101 * V_102 = V_6 -> V_102 ;
struct V_28 * V_113 = & V_6 -> V_28 ;
int V_10 ;
F_21 ( & V_6 -> V_60 ) ;
V_6 -> V_9 = V_9 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
if ( V_9 -> V_11 & V_122 ) {
V_10 = F_22 ( V_6 , V_102 -> V_104 ) ;
if ( V_10 )
goto V_63;
V_10 = F_6 ( V_9 -> V_13 , V_102 -> V_104 , V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
} else {
V_113 -> V_115 = V_125 ;
V_113 -> V_117 = F_46 ( V_6 -> V_117 ) ;
V_102 -> V_106 -> V_40 = V_110 ;
V_102 -> V_106 -> V_19 = V_6 ;
V_6 -> V_111 = V_121 ;
V_102 -> V_106 -> V_41 = V_113 ;
V_102 -> V_106 -> V_35 = sizeof( struct V_113 ) ;
V_10 = F_6 ( V_9 -> V_105 , V_102 -> V_106 ,
V_15 ) ;
if ( V_10 )
F_8 ( L_3 , V_21 , __LINE__ ) ;
}
F_23 ( & V_6 -> V_60 ) ;
F_24 ( V_44 ) ;
V_63:
return V_10 ;
}
static void F_51 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_19 ;
int V_10 ;
if ( V_14 -> V_20 < 0 )
return;
V_10 = F_52 ( V_9 , V_14 -> V_41 , V_14 -> V_64 ) ;
if ( ! V_10 )
return;
F_6 ( V_9 -> V_107 , V_9 -> V_6 . V_14 , V_15 ) ;
}
static int F_53 ( struct V_1 * V_9 , struct V_101 * V_102 )
{
V_102 -> V_103 = F_28 ( V_9 -> V_32 , V_42 ) ;
if ( ! V_102 -> V_103 )
goto V_123;
V_102 -> V_104 = F_28 ( V_9 -> V_13 , V_42 ) ;
if ( ! V_102 -> V_104 )
goto V_66;
V_102 -> V_106 = F_28 ( V_9 -> V_105 , V_42 ) ;
if ( ! V_102 -> V_106 )
goto V_68;
return 0 ;
V_68:
F_30 ( V_9 -> V_105 , V_102 -> V_106 ) ;
V_102 -> V_106 = NULL ;
V_66:
F_30 ( V_9 -> V_13 , V_102 -> V_104 ) ;
V_102 -> V_104 = NULL ;
V_123:
return - V_55 ;
}
static int F_54 ( struct V_1 * V_9 )
{
V_9 -> V_6 . V_14 = F_28 ( V_9 -> V_107 , V_42 ) ;
if ( ! V_9 -> V_6 . V_14 )
goto V_65;
V_9 -> V_6 . V_41 = F_18 ( V_9 -> V_107 -> V_34 , V_42 ) ;
if ( ! V_9 -> V_6 . V_41 )
goto V_72;
V_9 -> V_6 . V_14 -> V_40 = F_51 ;
V_9 -> V_6 . V_14 -> V_41 = V_9 -> V_6 . V_41 ;
V_9 -> V_6 . V_14 -> V_35 = V_9 -> V_107 -> V_34 ;
V_9 -> V_6 . V_14 -> V_19 = V_9 ;
return 0 ;
V_72:
F_30 ( V_9 -> V_107 , V_9 -> V_6 . V_14 ) ;
V_65:
return - V_55 ;
}
static void F_55 ( struct V_1 * V_9 , int V_126 )
{
int V_108 ;
for ( V_108 = 0 ; V_108 < V_126 ; V_108 ++ ) {
struct V_101 * V_127 = & V_9 -> V_102 [ V_108 ] ;
V_127 -> V_103 -> V_128 = V_108 + 1 ;
V_127 -> V_104 -> V_128 = V_108 + 1 ;
V_127 -> V_106 -> V_128 = V_108 + 1 ;
}
}
static int F_56 ( struct V_1 * V_9 )
{
int V_10 ;
int V_108 ;
int V_126 ;
if ( V_9 -> V_11 & V_122 )
V_126 = V_109 ;
else
V_126 = 1 ;
for ( V_108 = 0 ; V_108 < V_126 ; V_108 ++ ) {
V_10 = F_53 ( V_9 , & V_9 -> V_102 [ V_108 ] ) ;
if ( V_10 )
goto V_129;
}
V_10 = F_54 ( V_9 ) ;
if ( V_10 )
goto V_130;
F_55 ( V_9 , V_126 ) ;
V_10 = F_6 ( V_9 -> V_107 , V_9 -> V_6 . V_14 , V_15 ) ;
if ( V_10 )
goto V_130;
return 0 ;
V_130:
F_42 ( V_9 ) ;
V_129:
if ( V_108 ) {
do {
F_41 ( V_9 , & V_9 -> V_102 [ V_108 - 1 ] ) ;
V_108 -- ;
} while ( V_108 );
}
F_8 ( L_10 ) ;
return V_10 ;
}
static void F_57 ( struct V_1 * V_9 )
{
struct V_2 * V_3 = & V_9 -> V_4 ;
struct V_49 * V_50 = V_3 -> V_75 -> V_76 -> V_50 ;
int V_10 ;
V_9 -> V_11 = V_131 ;
if ( V_50 -> V_132 == V_133 )
V_9 -> V_11 |= V_122 ;
F_34 ( V_50 , V_3 , V_9 -> V_32 ) ;
V_10 = F_35 ( V_9 -> V_32 ) ;
if ( V_10 )
goto V_78;
F_34 ( V_50 , V_3 , V_9 -> V_13 ) ;
V_10 = F_35 ( V_9 -> V_13 ) ;
if ( V_10 )
goto V_79;
F_34 ( V_50 , V_3 , V_9 -> V_107 ) ;
V_10 = F_35 ( V_9 -> V_107 ) ;
if ( V_10 )
goto V_67;
F_34 ( V_50 , V_3 , V_9 -> V_105 ) ;
V_10 = F_35 ( V_9 -> V_105 ) ;
if ( V_10 )
goto V_134;
V_10 = F_56 ( V_9 ) ;
if ( V_10 )
goto V_80;
V_9 -> V_11 |= V_74 ;
F_36 ( L_11 ) ;
return;
V_80:
F_32 ( V_9 -> V_105 ) ;
V_134:
F_32 ( V_9 -> V_107 ) ;
V_67:
F_32 ( V_9 -> V_13 ) ;
V_79:
F_32 ( V_9 -> V_32 ) ;
V_78:
V_9 -> V_11 = 0 ;
}
static int F_58 ( const unsigned char * V_135 )
{
int V_10 ;
switch ( V_135 [ 0 ] ) {
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
case V_154 :
V_10 = V_155 ;
break;
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
case V_167 :
V_10 = V_168 ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_10 = V_179 ;
break;
default:
F_59 ( L_12
L_13 , V_135 [ 0 ] ) ;
V_10 = - V_61 ;
}
return V_10 ;
}
static void V_62 ( struct V_16 * V_17 , struct V_18 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_19 ;
struct V_44 * V_44 = & V_6 -> V_44 ;
if ( V_14 -> V_20 < 0 ) {
F_8 ( L_14 , V_21 , V_6 -> V_111 ) ;
goto V_63;
}
if ( V_14 -> V_58 == 0 ) {
F_60 ( V_44 -> V_56 ,
V_44 -> V_57 ,
V_6 -> V_53 ,
V_44 -> V_54 ) ;
}
V_40 ( & V_6 -> V_60 ) ;
return;
V_63:
F_3 ( V_6 ) ;
}
static int F_22 ( struct V_5 * V_6 , struct V_18 * V_14 )
{
struct V_44 * V_44 = & V_6 -> V_44 ;
struct V_1 * V_9 = V_6 -> V_9 ;
struct V_49 * V_50 = F_17 ( V_9 ) ;
if ( ! V_50 -> V_52 ) {
V_6 -> V_53 = F_18 ( V_44 -> V_54 , V_15 ) ;
if ( ! V_6 -> V_53 )
return - V_55 ;
V_14 -> V_41 = V_6 -> V_53 ;
} else {
V_14 -> V_41 = NULL ;
V_14 -> V_58 = V_44 -> V_57 ;
V_14 -> V_59 = V_44 -> V_56 ;
}
V_14 -> V_40 = V_62 ;
V_14 -> V_35 = V_44 -> V_54 ;
V_14 -> V_19 = V_6 ;
return 0 ;
}
static int F_61 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_77 )
return F_14 ( V_6 ) ;
else
return F_48 ( V_6 ) ;
}
static int F_62 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_77 )
return F_20 ( V_6 ) ;
else
return F_50 ( V_6 ) ;
}
static int F_63 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_77 )
return F_16 ( V_6 ) ;
else
return F_49 ( V_6 ) ;
}
static void F_64 ( struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_181 , struct V_5 , V_181 ) ;
struct V_44 * V_44 ;
struct V_182 * V_183 ;
struct V_184 * V_97 ;
int V_185 ;
V_44 = & V_6 -> V_44 ;
V_97 = V_6 -> V_9 -> V_97 ;
V_183 = V_97 -> V_186 ;
V_185 = F_58 ( V_6 -> V_187 ) ;
if ( V_185 < 0 ) {
F_65 ( V_44 ,
V_183 -> V_188 -> V_189 -> V_190 ,
V_183 -> V_188 , V_6 -> V_33 , V_179 ,
V_6 -> V_191 , V_6 -> V_28 . V_25 ) ;
F_66 ( V_44 ,
V_192 , 1 ) ;
F_3 ( V_6 ) ;
return;
}
F_67 ( V_44 , V_183 -> V_188 ,
V_6 -> V_187 , V_6 -> V_28 . V_25 , V_6 -> V_193 ,
0 , V_6 -> V_191 , V_185 , V_194 ) ;
}
static int F_52 ( struct V_1 * V_9 ,
void * V_195 , unsigned int V_118 )
{
struct V_196 * V_197 = V_195 ;
struct V_5 * V_6 ;
struct V_184 * V_97 ;
struct V_44 * V_44 ;
struct V_182 * V_183 ;
T_3 V_198 ;
int V_10 ;
if ( V_197 -> V_115 != V_199 ) {
F_8 ( L_15 , V_197 -> V_115 ) ;
return - V_61 ;
}
V_6 = F_68 ( sizeof *V_6 , V_15 ) ;
if ( ! V_6 )
return - V_55 ;
V_6 -> V_9 = V_9 ;
F_69 ( & V_6 -> V_7 ) ;
F_70 ( & V_6 -> V_7 ) ;
V_97 = V_9 -> V_97 ;
V_198 = ( V_197 -> V_118 & ~ 0x3 ) + 16 ;
if ( V_198 > V_200 )
goto V_65;
memcpy ( V_6 -> V_187 , V_197 -> V_135 , V_198 ) ;
V_6 -> V_117 = F_71 ( & V_197 -> V_117 ) ;
if ( V_9 -> V_11 & V_122 ) {
if ( V_6 -> V_117 > V_109 )
goto V_65;
if ( ! V_6 -> V_117 )
V_6 -> V_102 = & V_9 -> V_102 [ 0 ] ;
else
V_6 -> V_102 = & V_9 -> V_102 [ V_6 -> V_117 - 1 ] ;
} else {
V_6 -> V_102 = & V_9 -> V_102 [ 0 ] ;
}
V_183 = V_97 -> V_186 ;
if ( ! V_183 ) {
F_8 ( L_16 ) ;
goto V_65;
}
switch ( V_197 -> V_191 & 0x7 ) {
case V_201 :
V_6 -> V_191 = V_202 ;
break;
case V_203 :
V_6 -> V_191 = V_204 ;
break;
case V_205 :
V_6 -> V_191 = V_206 ;
break;
default:
F_72 ( L_17 ,
V_197 -> V_191 ) ;
case V_207 :
V_6 -> V_191 = V_208 ;
break;
}
V_44 = & V_6 -> V_44 ;
V_6 -> V_193 = F_73 ( & V_197 -> V_209 ) ;
F_74 ( & V_6 -> V_181 , F_64 ) ;
V_10 = F_75 ( V_97 -> V_210 , & V_6 -> V_181 ) ;
if ( V_10 < 0 )
goto V_65;
return 0 ;
V_65:
F_29 ( V_6 ) ;
return - V_61 ;
}
static void F_76 ( struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_181 , struct V_5 , V_181 ) ;
struct V_44 * V_44 ;
struct V_182 * V_183 ;
struct V_184 * V_97 ;
int V_185 ;
V_44 = & V_6 -> V_44 ;
V_97 = V_6 -> V_9 -> V_97 ;
V_183 = V_97 -> V_186 ;
V_185 = F_58 ( V_6 -> V_187 ) ;
if ( V_185 < 0 ) {
F_65 ( V_44 ,
V_183 -> V_188 -> V_189 -> V_190 ,
V_183 -> V_188 , V_6 -> V_33 , V_179 ,
V_6 -> V_191 , V_6 -> V_28 . V_25 ) ;
F_66 ( V_44 ,
V_192 , 1 ) ;
F_3 ( V_6 ) ;
return;
}
F_67 ( V_44 , V_183 -> V_188 ,
V_6 -> V_187 , V_6 -> V_28 . V_25 , V_6 -> V_193 ,
V_6 -> V_33 , V_6 -> V_191 , V_185 , 0 ) ;
}
static int F_26 ( struct V_1 * V_9 ,
void * V_195 , unsigned int V_118 )
{
struct V_211 * V_212 = V_195 ;
struct V_5 * V_6 ;
struct V_184 * V_97 ;
struct V_44 * V_44 ;
struct V_182 * V_183 ;
T_3 V_198 ;
int V_10 ;
if ( V_212 -> V_70 != F_12 ( V_213 ) ) {
F_8 ( L_18 ) ;
return - V_61 ;
}
if ( V_118 != 31 ) {
F_8 ( L_19 ) ;
return - V_61 ;
}
V_198 = V_212 -> V_214 ;
if ( V_198 < 1 || V_198 > 16 )
return - V_61 ;
V_6 = F_68 ( sizeof *V_6 , V_15 ) ;
if ( ! V_6 )
return - V_55 ;
V_6 -> V_9 = V_9 ;
F_69 ( & V_6 -> V_7 ) ;
F_70 ( & V_6 -> V_7 ) ;
V_97 = V_9 -> V_97 ;
memcpy ( V_6 -> V_187 , V_212 -> V_215 , V_198 ) ;
V_6 -> V_30 = V_212 -> V_29 ;
V_183 = V_97 -> V_186 ;
if ( ! V_183 ) {
F_8 ( L_16 ) ;
goto V_65;
}
V_6 -> V_191 = V_208 ;
V_44 = & V_6 -> V_44 ;
V_6 -> V_193 = V_212 -> V_216 ;
V_6 -> V_37 = V_212 -> V_217 & V_218 ? 1 : 0 ;
V_6 -> V_33 = F_77 ( V_212 -> V_219 ) ;
F_74 ( & V_6 -> V_181 , F_76 ) ;
V_10 = F_75 ( V_97 -> V_210 , & V_6 -> V_181 ) ;
if ( V_10 < 0 )
goto V_65;
return 0 ;
V_65:
F_29 ( V_6 ) ;
return - V_61 ;
}
static int F_78 ( struct V_220 * V_189 )
{
return 1 ;
}
static int F_79 ( struct V_220 * V_189 )
{
return 0 ;
}
static char * F_80 ( void )
{
return L_20 ;
}
static T_1 F_81 ( struct V_220 * V_189 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
struct V_221 * V_222 = V_97 -> V_222 ;
T_1 V_223 ;
switch ( V_222 -> V_224 ) {
case V_225 :
default:
V_223 = F_82 ( V_189 ) ;
break;
}
return V_223 ;
}
static char * F_83 ( struct V_220 * V_189 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
struct V_221 * V_222 = V_97 -> V_222 ;
return & V_222 -> V_226 [ 0 ] ;
}
static T_2 F_84 ( struct V_220 * V_189 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
return V_97 -> V_227 ;
}
static T_3 F_85 ( struct V_220 * V_189 )
{
return 1 ;
}
static T_3 F_86 (
struct V_220 * V_189 ,
struct V_228 * V_229 ,
struct V_230 * V_231 ,
int * V_232 ,
unsigned char * V_41 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
struct V_221 * V_222 = V_97 -> V_222 ;
int V_10 = 0 ;
switch ( V_222 -> V_224 ) {
case V_225 :
default:
V_10 = F_87 ( V_189 , V_229 , V_231 ,
V_232 , V_41 ) ;
break;
}
return V_10 ;
}
static T_3 F_88 (
struct V_220 * V_189 ,
struct V_228 * V_229 ,
struct V_230 * V_231 ,
int * V_232 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
struct V_221 * V_222 = V_97 -> V_222 ;
int V_10 = 0 ;
switch ( V_222 -> V_224 ) {
case V_225 :
default:
V_10 = F_89 ( V_189 , V_229 , V_231 ,
V_232 ) ;
break;
}
return V_10 ;
}
static char * F_90 (
struct V_220 * V_189 ,
const char * V_41 ,
T_3 * V_233 ,
char * * V_234 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
struct V_221 * V_222 = V_97 -> V_222 ;
char * V_235 = NULL ;
switch ( V_222 -> V_224 ) {
case V_225 :
default:
V_235 = F_91 ( V_189 , V_41 , V_233 ,
V_234 ) ;
}
return V_235 ;
}
static struct V_228 * F_92 ( struct V_220 * V_189 )
{
struct V_236 * V_237 ;
V_237 = F_68 ( sizeof( struct V_236 ) , V_42 ) ;
if ( ! V_237 ) {
F_93 ( V_238 L_21 ) ;
return NULL ;
}
return & V_237 -> V_228 ;
}
static void F_94 (
struct V_220 * V_189 ,
struct V_228 * V_229 )
{
struct V_236 * V_237 = F_2 ( V_229 ,
struct V_236 , V_228 ) ;
F_29 ( V_237 ) ;
}
static T_3 F_95 ( struct V_220 * V_189 )
{
return 1 ;
}
static int F_96 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
int V_10 ;
V_10 = F_97 ( V_44 , V_6 -> V_187 ) ;
if ( V_10 )
return V_10 ;
return F_98 ( V_44 , NULL , 0 , NULL , 0 ) ;
}
static void V_8 ( struct V_239 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 , struct V_5 ,
V_7 ) ;
F_99 ( & V_6 -> V_44 , 0 ) ;
}
static void F_100 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
F_29 ( V_6 -> V_53 ) ;
F_29 ( V_6 ) ;
return;
}
static int F_101 ( struct V_240 * V_241 )
{
return 0 ;
}
static void F_102 ( struct V_240 * V_241 )
{
return;
}
static T_3 F_103 ( struct V_240 * V_241 )
{
return 0 ;
}
static int F_104 ( struct V_44 * V_44 )
{
return 0 ;
}
static void F_105 ( struct V_228 * V_237 )
{
return;
}
static T_3 F_106 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
struct V_1 * V_9 = V_6 -> V_9 ;
if ( V_9 -> V_11 & V_77 )
return F_77 ( V_6 -> V_30 ) ;
else
return V_6 -> V_117 ;
}
static int F_107 ( struct V_44 * V_44 )
{
return 0 ;
}
static int F_108 ( struct V_44 * V_44 )
{
return 0 ;
}
static T_2 F_109 ( struct V_44 * V_44 , T_3 V_242 )
{
return 0 ;
}
static T_2 F_110 ( void )
{
return 0 ;
}
static const char * F_111 ( const char * V_243 )
{
const char * V_244 ;
unsigned int V_118 ;
V_244 = strstr ( V_243 , L_22 ) ;
if ( ! V_244 )
return NULL ;
V_244 += 4 ;
V_118 = strlen ( V_244 ) ;
if ( V_118 == 0 || V_118 > V_245 - 1 )
return NULL ;
return V_244 ;
}
static struct V_228 * F_112 (
struct V_220 * V_189 ,
struct V_246 * V_247 ,
const char * V_243 )
{
struct V_228 * V_229 , * V_248 ;
struct V_236 * V_237 ;
T_4 V_249 = 0 ;
T_3 V_250 ;
const char * V_251 ;
V_251 = F_111 ( V_243 ) ;
if ( ! V_251 )
return F_113 ( - V_61 ) ;
V_248 = F_92 ( V_189 ) ;
if ( ! ( V_248 ) )
return F_113 ( - V_55 ) ;
V_250 = 1 ;
V_229 = F_114 ( V_189 , V_248 ,
V_243 , V_250 ) ;
if ( F_115 ( V_229 ) ) {
F_94 ( V_189 , V_248 ) ;
return V_229 ;
}
V_237 = F_2 ( V_229 , struct V_236 , V_228 ) ;
V_237 -> V_252 = V_249 ;
snprintf ( V_237 -> V_253 , sizeof( V_237 -> V_253 ) , L_23 , V_243 ) ;
return V_229 ;
}
static void F_116 ( struct V_228 * V_254 )
{
struct V_236 * V_237 = F_2 ( V_254 ,
struct V_236 , V_228 ) ;
F_117 ( V_254 -> V_189 , V_254 , 1 ) ;
F_29 ( V_237 ) ;
}
static struct V_220 * F_118 (
struct V_255 * V_256 ,
struct V_246 * V_247 ,
const char * V_243 )
{
struct V_221 * V_222 = F_2 ( V_256 , struct V_221 ,
V_257 ) ;
struct V_184 * V_97 ;
unsigned long V_258 ;
int V_10 ;
if ( strstr ( V_243 , L_24 ) != V_243 )
return F_113 ( - V_61 ) ;
if ( F_119 ( V_243 + 5 , 0 , & V_258 ) || V_258 > V_259 )
return F_113 ( - V_61 ) ;
if ( V_260 ) {
F_8 ( L_25 ) ;
F_8 ( L_26 ) ;
return F_113 ( - V_261 ) ;
}
V_97 = F_68 ( sizeof( struct V_184 ) , V_42 ) ;
if ( ! V_97 ) {
F_93 ( V_238 L_27 ) ;
return F_113 ( - V_55 ) ;
}
F_120 ( & V_97 -> V_262 ) ;
F_121 ( & V_97 -> V_98 , 0 ) ;
V_97 -> V_210 = F_122 ( L_28 , 0 , 1 ) ;
if ( ! V_97 -> V_210 ) {
F_29 ( V_97 ) ;
return NULL ;
}
V_97 -> V_222 = V_222 ;
V_97 -> V_227 = V_258 ;
V_10 = F_123 ( & V_263 -> V_264 , V_256 ,
& V_97 -> V_189 , V_97 ,
V_265 ) ;
if ( V_10 < 0 ) {
F_124 ( V_97 -> V_210 ) ;
F_29 ( V_97 ) ;
return NULL ;
}
V_260 = V_97 ;
return & V_97 -> V_189 ;
}
static void F_125 ( struct V_220 * V_189 )
{
struct V_184 * V_97 = F_2 ( V_189 ,
struct V_184 , V_189 ) ;
F_126 ( V_189 ) ;
F_124 ( V_97 -> V_210 ) ;
F_29 ( V_97 ) ;
V_260 = NULL ;
}
static struct V_255 * F_127 (
struct V_266 * V_267 ,
struct V_246 * V_247 ,
const char * V_243 )
{
struct V_221 * V_222 ;
const char * V_251 ;
T_4 V_249 = 0 ;
V_251 = F_111 ( V_243 ) ;
if ( ! V_251 )
return F_113 ( - V_61 ) ;
V_222 = F_68 ( sizeof( struct V_221 ) , V_42 ) ;
if ( ! ( V_222 ) ) {
F_93 ( V_238 L_29 ) ;
return F_113 ( - V_55 ) ;
}
V_222 -> V_268 = V_249 ;
snprintf ( V_222 -> V_226 , sizeof( V_222 -> V_226 ) , V_251 ) ;
return & V_222 -> V_257 ;
}
static void F_128 ( struct V_255 * V_256 )
{
struct V_221 * V_222 = F_2 ( V_256 ,
struct V_221 , V_257 ) ;
F_29 ( V_222 ) ;
}
static T_5 F_129 (
struct V_266 * V_267 ,
char * V_269 )
{
return sprintf ( V_269 , L_30 ) ;
}
static T_5 F_130 (
struct V_220 * V_189 ,
char * V_269 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
return snprintf ( V_269 , V_270 , L_31 , V_97 -> V_271 ) ;
}
static T_5 F_131 (
struct V_220 * V_189 ,
const char * V_269 ,
T_6 V_272 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
unsigned long V_273 ;
T_5 V_10 ;
V_10 = F_119 ( V_269 , 0 , & V_273 ) ;
if ( V_10 < 0 )
return - V_61 ;
if ( V_273 > 1 )
return - V_61 ;
if ( V_273 && V_97 -> V_271 )
goto V_123;
if ( ! V_273 && ! V_97 -> V_271 )
goto V_123;
if ( V_273 ) {
V_10 = F_132 ( V_97 ) ;
if ( V_10 )
goto V_123;
} else {
F_133 ( V_97 ) ;
}
V_97 -> V_271 = V_273 ;
V_123:
return V_272 ;
}
static T_5 F_134 (
struct V_220 * V_189 ,
char * V_269 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
struct V_182 * V_183 ;
T_5 V_10 ;
F_135 ( & V_97 -> V_262 ) ;
V_183 = V_97 -> V_186 ;
if ( ! V_183 ) {
V_10 = - V_274 ;
goto V_123;
}
V_10 = snprintf ( V_269 , V_270 , L_32 ,
V_183 -> V_188 -> V_228 -> V_275 ) ;
V_123:
F_136 ( & V_97 -> V_262 ) ;
return V_10 ;
}
static int F_137 ( struct V_184 * V_97 , char * V_243 )
{
struct V_220 * V_189 ;
struct V_182 * V_183 ;
int V_10 ;
F_135 ( & V_97 -> V_262 ) ;
if ( V_97 -> V_186 ) {
V_10 = - V_276 ;
F_138 ( L_33 ) ;
goto V_277;
}
V_189 = & V_97 -> V_189 ;
V_10 = - V_55 ;
V_183 = F_68 ( sizeof( * V_183 ) , V_42 ) ;
if ( ! V_183 ) {
F_8 ( L_34 ) ;
goto V_277;
}
V_183 -> V_188 = F_139 () ;
if ( F_115 ( V_183 -> V_188 ) )
goto V_278;
V_183 -> V_188 -> V_228 = F_140 (
V_189 , V_243 ) ;
if ( ! V_183 -> V_188 -> V_228 ) {
F_138 ( L_35
L_36 , V_243 ) ;
goto V_279;
}
F_141 ( V_189 , V_183 -> V_188 -> V_228 ,
V_183 -> V_188 , V_183 ) ;
V_97 -> V_186 = V_183 ;
F_136 ( & V_97 -> V_262 ) ;
return 0 ;
V_279:
F_142 ( V_183 -> V_188 ) ;
V_278:
F_29 ( V_183 ) ;
V_277:
F_136 ( & V_97 -> V_262 ) ;
return V_10 ;
}
static int F_143 ( struct V_184 * V_97 )
{
struct V_240 * V_241 ;
struct V_182 * V_183 ;
int V_10 = - V_274 ;
F_135 ( & V_97 -> V_262 ) ;
V_183 = V_97 -> V_186 ;
if ( ! V_183 )
goto V_123;
V_241 = V_183 -> V_188 ;
if ( ! V_241 )
goto V_123;
if ( F_39 ( & V_97 -> V_98 ) ) {
V_10 = - V_280 ;
F_8 ( L_37
L_38 ,
F_39 ( & V_97 -> V_98 ) ) ;
goto V_123;
}
F_138 ( L_39 ,
V_183 -> V_188 -> V_228 -> V_275 ) ;
F_144 ( V_183 -> V_188 ) ;
V_97 -> V_186 = NULL ;
F_29 ( V_183 ) ;
V_123:
F_136 ( & V_97 -> V_262 ) ;
return 0 ;
}
static T_5 F_145 (
struct V_220 * V_189 ,
const char * V_269 ,
T_6 V_272 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
unsigned char V_281 [ V_245 ] , * V_282 ;
int V_10 ;
if ( ! strncmp ( V_269 , L_40 , 4 ) ) {
V_10 = F_143 ( V_97 ) ;
return ( ! V_10 ) ? V_272 : V_10 ;
}
if ( strlen ( V_269 ) > V_245 ) {
F_8 ( L_41
L_42 , V_269 , V_245 ) ;
return - V_61 ;
}
snprintf ( V_281 , V_245 , L_23 , V_269 ) ;
V_282 = strstr ( V_281 , L_22 ) ;
if ( ! V_282 ) {
F_8 ( L_43 ) ;
return - V_61 ;
}
if ( V_281 [ strlen ( V_281 ) - 1 ] == '\n' )
V_281 [ strlen ( V_281 ) - 1 ] = '\0' ;
V_10 = F_137 ( V_97 , & V_281 [ 4 ] ) ;
if ( V_10 < 0 )
return V_10 ;
return V_272 ;
}
static int F_146 ( struct V_220 * V_189 , struct V_283 * V_209 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
F_147 ( & V_97 -> V_98 ) ;
F_148 () ;
return 0 ;
}
static void F_149 ( struct V_220 * V_189 ,
struct V_283 * V_283 )
{
struct V_184 * V_97 = F_2 ( V_189 , struct V_184 , V_189 ) ;
F_150 ( & V_97 -> V_98 ) ;
F_151 () ;
}
static int F_152 ( struct V_44 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 , struct V_5 ,
V_44 ) ;
F_4 ( & V_6 -> V_7 , V_8 ) ;
return 1 ;
}
static int F_153 ( void )
{
struct V_266 * V_284 ;
int V_10 ;
V_284 = F_154 ( V_285 , L_20 ) ;
if ( F_115 ( V_284 ) ) {
F_93 ( V_238 L_44 ) ;
return F_155 ( V_284 ) ;
}
V_284 -> V_264 = V_286 ;
F_156 ( V_284 ) -> V_287 . V_288 = V_289 ;
F_156 ( V_284 ) -> V_290 . V_288 = V_291 ;
F_156 ( V_284 ) -> V_292 . V_288 = NULL ;
F_156 ( V_284 ) -> V_293 . V_288 = NULL ;
F_156 ( V_284 ) -> V_294 . V_288 = NULL ;
F_156 ( V_284 ) -> V_295 . V_288 = NULL ;
F_156 ( V_284 ) -> V_296 . V_288 = NULL ;
F_156 ( V_284 ) -> V_297 . V_288 = NULL ;
F_156 ( V_284 ) -> V_298 . V_288 = NULL ;
V_10 = F_157 ( V_284 ) ;
if ( V_10 < 0 ) {
F_93 ( V_238 L_45
L_46 ) ;
return V_10 ;
}
V_263 = V_284 ;
return 0 ;
}
static void F_158 ( void )
{
if ( ! ( V_263 ) )
return;
F_159 ( V_263 ) ;
V_263 = NULL ;
}
static int F_160 ( struct V_83 * V_76 )
{
return 0 ;
}
static void F_161 ( struct V_16 * * V_299 )
{
struct V_16 * V_17 = * V_299 ;
if ( ! V_17 )
return;
V_17 -> V_300 = NULL ;
}
static int F_162 ( struct V_301 * V_302 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_49 * V_50 = V_302 -> V_76 -> V_50 ;
struct V_16 * V_17 ;
int V_303 ;
V_303 = F_163 ( V_302 , V_3 ) ;
if ( V_303 < 0 )
return V_303 ;
V_304 . V_305 = V_303 ;
V_306 . V_305 = V_303 ;
V_9 -> V_303 = V_303 ;
V_17 = F_164 ( V_50 , & V_307 ,
& V_308 ) ;
if ( ! V_17 )
goto V_309;
V_17 -> V_300 = V_9 ;
V_9 -> V_32 = V_17 ;
V_17 = F_164 ( V_50 , & V_310 ,
& V_311 ) ;
if ( ! V_17 )
goto V_309;
V_17 -> V_300 = V_9 ;
V_9 -> V_13 = V_17 ;
V_17 = F_164 ( V_50 , & V_312 ,
& V_313 ) ;
if ( ! V_17 )
goto V_309;
V_17 -> V_300 = V_9 ;
V_9 -> V_105 = V_17 ;
V_17 = F_164 ( V_50 , & V_314 ,
& V_315 ) ;
if ( ! V_17 )
goto V_309;
V_17 -> V_300 = V_9 ;
V_9 -> V_107 = V_17 ;
V_316 . V_317 = V_307 . V_317 ;
V_318 . V_317 = V_310 . V_317 ;
V_319 . V_317 =
V_312 . V_317 ;
V_320 . V_317 = V_314 . V_317 ;
V_321 . V_317 = V_307 . V_317 ;
V_322 . V_317 = V_310 . V_317 ;
V_323 . V_317 =
V_312 . V_317 ;
V_324 . V_317 = V_314 . V_317 ;
return 0 ;
V_309:
F_8 ( L_47 ) ;
F_161 ( & V_9 -> V_32 ) ;
F_161 ( & V_9 -> V_13 ) ;
F_161 ( & V_9 -> V_105 ) ;
F_161 ( & V_9 -> V_107 ) ;
return - V_96 ;
}
static void F_165 ( struct V_301 * V_302 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_29 ( V_9 ) ;
}
static void F_166 ( struct V_180 * V_325 )
{
struct V_326 * V_181 = F_2 ( V_325 , struct V_326 ,
V_181 ) ;
struct V_1 * V_9 = V_181 -> V_9 ;
int V_327 = V_181 -> V_327 ;
F_29 ( V_181 ) ;
if ( V_9 -> V_11 & V_77 )
F_31 ( V_9 ) ;
if ( V_9 -> V_11 & V_131 )
F_43 ( V_9 ) ;
if ( V_327 == V_328 )
F_33 ( V_9 ) ;
else if ( V_327 == V_329 )
F_57 ( V_9 ) ;
F_167 ( V_9 -> V_4 . V_75 -> V_76 ) ;
}
static int F_168 ( struct V_2 * V_3 , unsigned V_330 , unsigned V_327 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ( V_327 == V_328 ) || ( V_327 == V_329 ) ) {
struct V_326 * V_181 ;
V_181 = F_18 ( sizeof( * V_181 ) , V_15 ) ;
if ( ! V_181 )
return - V_55 ;
F_74 ( & V_181 -> V_181 , F_166 ) ;
V_181 -> V_9 = V_9 ;
V_181 -> V_327 = V_327 ;
F_169 ( & V_181 -> V_181 ) ;
return V_331 ;
}
return - V_332 ;
}
static void F_170 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( V_9 -> V_11 & V_131 )
F_43 ( V_9 ) ;
else if ( V_9 -> V_11 & V_77 )
F_31 ( V_9 ) ;
V_9 -> V_11 = 0 ;
}
static int F_171 ( struct V_2 * V_3 ,
const struct V_81 * V_82 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! ( V_9 -> V_11 & V_77 ) )
return - V_332 ;
return F_37 ( V_3 , V_82 ) ;
}
static int F_172 ( struct V_301 * V_302 )
{
struct V_1 * V_9 ;
int V_10 ;
V_9 = F_68 ( sizeof( * V_9 ) , V_42 ) ;
if ( ! V_9 )
return - V_55 ;
V_9 -> V_4 . V_243 = L_48 ;
V_9 -> V_4 . V_333 = V_334 ;
V_9 -> V_4 . V_335 = V_336 ;
V_9 -> V_4 . V_337 = V_338 ;
V_9 -> V_4 . V_339 = F_162 ;
V_9 -> V_4 . V_340 = F_165 ;
V_9 -> V_4 . V_341 = F_168 ;
V_9 -> V_4 . V_342 = F_171 ;
V_9 -> V_4 . V_343 = F_170 ;
V_9 -> V_97 = V_260 ;
V_10 = F_173 ( V_302 , & V_9 -> V_4 ) ;
if ( V_10 )
goto V_65;
return 0 ;
V_65:
F_29 ( V_9 ) ;
return V_10 ;
}
static int F_174 ( struct V_83 * V_76 )
{
int V_10 ;
V_10 = F_175 ( V_76 , & V_344 ,
F_172 ) ;
return 0 ;
}
static int F_132 ( struct V_184 * V_97 )
{
return F_176 ( & V_345 , F_174 ) ;
}
static void F_133 ( struct V_184 * V_97 )
{
F_177 ( & V_345 ) ;
}
static int T_7 F_178 ( void )
{
int V_10 ;
V_10 = F_153 () ;
return V_10 ;
}
static void T_8 F_179 ( void )
{
F_158 () ;
}
