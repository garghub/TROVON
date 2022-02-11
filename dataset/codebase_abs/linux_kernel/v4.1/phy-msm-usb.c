static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_2 -> V_6 [ V_7 ] ,
V_2 -> V_6 [ V_8 ] ) ;
if ( V_4 ) {
F_3 ( V_2 -> V_9 . V_10 , L_1 ) ;
return V_4 ;
}
V_4 = F_4 ( V_2 -> V_5 ) ;
if ( V_4 )
F_3 ( V_2 -> V_9 . V_10 , L_2 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , 0 ,
V_2 -> V_6 [ V_8 ] ) ;
if ( V_4 )
F_3 ( V_2 -> V_9 . V_10 , L_1 ) ;
V_4 = F_5 ( V_2 -> V_5 ) ;
if ( V_4 )
F_3 ( V_2 -> V_9 . V_10 , L_3 ) ;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 )
{
int V_11 = 0 ;
if ( V_3 ) {
V_11 = F_2 ( V_2 -> V_12 , V_13 ,
V_14 ) ;
if ( V_11 ) {
F_3 ( V_2 -> V_9 . V_10 , L_4 ) ;
goto exit;
}
V_11 = F_4 ( V_2 -> V_12 ) ;
if ( V_11 ) {
F_3 ( V_2 -> V_9 . V_10 , L_5 ) ;
goto exit;
}
V_11 = F_2 ( V_2 -> V_15 , V_16 ,
V_17 ) ;
if ( V_11 ) {
F_3 ( V_2 -> V_9 . V_10 , L_6 ) ;
goto V_18;
}
V_11 = F_4 ( V_2 -> V_15 ) ;
if ( V_11 ) {
F_3 ( V_2 -> V_9 . V_10 , L_7 ) ;
goto V_18;
}
return 0 ;
}
F_5 ( V_2 -> V_15 ) ;
V_18:
F_5 ( V_2 -> V_12 ) ;
exit:
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , int V_19 )
{
int V_4 = 0 ;
if ( V_19 ) {
V_4 = F_8 ( V_2 -> V_15 , V_20 ) ;
if ( V_4 < 0 ) {
F_9 ( L_8 ) ;
return V_4 ;
}
V_4 = F_8 ( V_2 -> V_12 , V_21 ) ;
if ( V_4 < 0 ) {
F_9 ( L_9 ) ;
F_8 ( V_2 -> V_15 , V_22 ) ;
return V_4 ;
}
} else {
V_4 = F_8 ( V_2 -> V_15 , V_22 ) ;
if ( V_4 < 0 )
F_9 ( L_10 ) ;
V_4 = F_8 ( V_2 -> V_12 , V_23 ) ;
if ( V_4 < 0 )
F_9 ( L_11 ) ;
}
F_10 ( L_12 , V_19 ? L_13 : L_14 ) ;
return V_4 < 0 ? V_4 : 0 ;
}
static int F_11 ( struct V_24 * V_9 , T_1 V_25 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
int V_26 = 0 ;
F_13 ( V_27 | V_28 | F_14 ( V_25 ) ,
V_29 ) ;
while ( V_26 < V_30 ) {
if ( ! ( F_15 ( V_29 ) & V_27 ) )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_30 ) {
F_3 ( V_9 -> V_10 , L_15 ,
F_15 ( V_29 ) ) ;
return - V_31 ;
}
return F_17 ( F_15 ( V_29 ) ) ;
}
static int F_18 ( struct V_24 * V_9 , T_1 V_32 , T_1 V_25 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
int V_26 = 0 ;
F_13 ( V_27 | V_33 |
F_14 ( V_25 ) | F_19 ( V_32 ) ,
V_29 ) ;
while ( V_26 < V_30 ) {
if ( ! ( F_15 ( V_29 ) & V_27 ) )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_30 ) {
F_3 ( V_9 -> V_10 , L_16 ) ;
return - V_31 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
int * V_36 = V_35 -> V_37 , V_38 ;
T_1 V_39 = V_40 ;
for ( V_38 = 0 ; V_38 < V_35 -> V_41 ; V_38 ++ ) {
if ( V_36 [ V_38 ] == - 1 )
continue;
F_21 ( V_2 -> V_9 . V_10 , L_17 ,
V_36 [ V_38 ] , V_39 + V_38 ) ;
F_18 ( & V_2 -> V_9 , V_36 [ V_38 ] , V_39 + V_38 ) ;
}
}
static int F_22 ( struct V_24 * V_9 ,
enum V_42 V_43 )
{
int V_32 ;
V_32 = F_11 ( V_9 , V_44 ) ;
V_32 &= ~ V_45 ;
V_32 |= V_46 ;
F_18 ( V_9 , V_32 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , bool assert )
{
int V_4 ;
if ( assert )
V_4 = F_24 ( V_2 -> V_47 ) ;
else
V_4 = F_25 ( V_2 -> V_47 ) ;
if ( V_4 )
F_3 ( V_2 -> V_9 . V_10 , L_18 ,
assert ? L_19 : L_20 ) ;
return V_4 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_48 )
V_4 = F_27 ( V_2 -> V_48 ) ;
if ( V_4 )
F_3 ( V_2 -> V_9 . V_10 , L_21 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_32 ;
int V_4 ;
V_4 = F_23 ( V_2 , 1 ) ;
if ( V_4 )
return V_4 ;
F_29 ( 1000 , 1200 ) ;
V_4 = F_23 ( V_2 , 0 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_49 )
F_13 ( F_15 ( V_50 ) | F_30 ( 16 ) , V_50 ) ;
V_32 = F_15 ( V_51 ) & ~ V_52 ;
F_13 ( V_32 | V_53 , V_51 ) ;
return 0 ;
}
static int F_31 ( struct V_24 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
int V_26 = 0 ;
F_13 ( V_54 , V_55 ) ;
while ( V_26 < V_56 ) {
if ( ! ( F_15 ( V_55 ) & V_54 ) )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_56 )
return - V_31 ;
F_13 ( V_57 , V_51 ) ;
F_13 ( 0x0 , V_58 ) ;
F_13 ( 0x08 , V_59 ) ;
if ( V_2 -> V_49 )
F_13 ( F_15 ( V_50 ) | F_30 ( 16 ) , V_50 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
void T_2 * V_39 ;
if ( V_2 -> V_35 -> V_60 != V_61 ) {
F_26 ( V_2 ) ;
return;
}
V_39 = V_62 ;
if ( V_2 -> V_49 )
V_39 = V_50 ;
F_13 ( F_15 ( V_39 ) | V_63 , V_39 ) ;
F_16 ( 12 ) ;
F_13 ( F_15 ( V_39 ) & ~ V_63 , V_39 ) ;
}
static int F_33 ( struct V_24 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
int V_4 ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_35 ( V_2 -> V_64 ) ;
V_4 = F_28 ( V_2 ) ;
if ( V_4 ) {
F_3 ( V_9 -> V_10 , L_22 ) ;
return V_4 ;
}
V_4 = F_31 ( & V_2 -> V_9 ) ;
if ( V_4 ) {
F_3 ( V_9 -> V_10 , L_23 ) ;
return V_4 ;
}
F_36 ( 100 ) ;
F_32 ( V_2 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_37 ( V_2 -> V_64 ) ;
return 0 ;
}
static int F_38 ( struct V_24 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_32 , V_65 = 0 ;
F_20 ( V_2 ) ;
F_32 ( V_2 ) ;
if ( V_35 -> V_66 == V_67 ) {
V_32 = F_15 ( V_68 ) ;
if ( V_35 -> V_69 == V_70 ) {
V_65 = V_71 | V_72 ;
V_32 |= V_73 | V_74 ;
} else if ( V_35 -> V_69 == V_75 ) {
V_65 = V_72 ;
V_32 |= V_74 ;
}
F_13 ( V_32 , V_68 ) ;
F_18 ( V_9 , V_65 , V_76 ) ;
F_18 ( V_9 , V_65 , V_77 ) ;
}
if ( V_2 -> V_49 )
F_13 ( F_15 ( V_50 ) | F_30 ( 16 ) , V_50 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_78 )
{
int V_79 = V_2 -> V_6 [ V_8 ] ;
int V_80 ;
int V_4 ;
if ( V_78 )
V_80 = V_2 -> V_6 [ V_7 ] ;
else
V_80 = V_2 -> V_6 [ V_81 ] ;
V_4 = F_2 ( V_2 -> V_5 , V_80 , V_79 ) ;
if ( V_4 ) {
F_9 ( L_1 ) ;
return V_4 ;
}
F_10 ( L_24 , V_82 , V_80 , V_79 ) ;
return V_4 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
struct V_83 * V_84 = V_9 -> V_85 -> V_86 ;
struct V_34 * V_35 = V_2 -> V_35 ;
void T_2 * V_39 ;
int V_26 = 0 ;
if ( F_41 ( & V_2 -> V_87 ) )
return 0 ;
F_42 ( V_2 -> V_88 ) ;
if ( V_2 -> V_35 -> V_60 == V_89 ) {
F_11 ( V_9 , 0x14 ) ;
if ( V_35 -> V_66 == V_67 )
F_18 ( V_9 , 0x01 , 0x30 ) ;
F_18 ( V_9 , 0x08 , 0x09 ) ;
}
F_13 ( F_15 ( V_51 ) | V_90 , V_51 ) ;
while ( V_26 < V_91 ) {
if ( F_15 ( V_51 ) & V_90 )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_91 ) {
F_3 ( V_9 -> V_10 , L_25 ) ;
F_31 ( V_9 ) ;
F_43 ( V_2 -> V_88 ) ;
return - V_31 ;
}
F_13 ( F_15 ( V_55 ) | V_92 | V_93 , V_55 ) ;
V_39 = V_62 ;
if ( V_2 -> V_49 )
V_39 = V_50 ;
if ( V_2 -> V_35 -> V_60 == V_61 &&
V_2 -> V_35 -> V_66 == V_94 )
F_13 ( F_15 ( V_39 ) | V_95 , V_39 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_97 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_37 ( V_2 -> V_64 ) ;
if ( V_2 -> V_35 -> V_60 == V_61 &&
V_2 -> V_35 -> V_66 == V_94 ) {
F_7 ( V_2 , 0 ) ;
F_39 ( V_2 , 0 ) ;
}
if ( F_44 ( V_9 -> V_10 ) )
F_45 ( V_2 -> V_88 ) ;
if ( V_84 )
F_46 ( V_98 , & ( F_47 ( V_84 ) ) -> V_99 ) ;
F_48 ( & V_2 -> V_87 , 1 ) ;
F_43 ( V_2 -> V_88 ) ;
F_49 ( V_9 -> V_10 , L_26 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
struct V_83 * V_84 = V_9 -> V_85 -> V_86 ;
void T_2 * V_39 ;
int V_26 = 0 ;
unsigned V_100 ;
if ( ! F_41 ( & V_2 -> V_87 ) )
return 0 ;
F_35 ( V_2 -> V_96 ) ;
F_35 ( V_2 -> V_97 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_35 ( V_2 -> V_64 ) ;
if ( V_2 -> V_35 -> V_60 == V_61 &&
V_2 -> V_35 -> V_66 == V_94 ) {
V_39 = V_62 ;
if ( V_2 -> V_49 )
V_39 = V_50 ;
F_7 ( V_2 , 1 ) ;
F_39 ( V_2 , 1 ) ;
F_13 ( F_15 ( V_39 ) & ~ V_95 , V_39 ) ;
}
V_100 = F_15 ( V_55 ) ;
V_100 &= ~ V_92 ;
V_100 &= ~ V_93 ;
F_13 ( V_100 , V_55 ) ;
if ( ! ( F_15 ( V_51 ) & V_90 ) )
goto V_101;
F_13 ( F_15 ( V_51 ) & ~ V_90 , V_51 ) ;
while ( V_26 < V_102 ) {
if ( ! ( F_15 ( V_51 ) & V_90 ) )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_102 ) {
F_3 ( V_9 -> V_10 , L_27 ) ;
F_31 ( V_9 ) ;
}
V_101:
if ( F_44 ( V_9 -> V_10 ) )
F_51 ( V_2 -> V_88 ) ;
if ( V_84 )
F_52 ( V_98 , & ( F_47 ( V_84 ) ) -> V_99 ) ;
F_48 ( & V_2 -> V_87 , 0 ) ;
if ( V_2 -> V_103 ) {
V_2 -> V_103 = 0 ;
F_53 ( V_9 -> V_10 ) ;
F_43 ( V_2 -> V_88 ) ;
}
F_49 ( V_9 -> V_10 , L_28 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , unsigned V_104 )
{
if ( V_2 -> V_105 == V_104 )
return;
F_49 ( V_2 -> V_9 . V_10 , L_29 , V_104 ) ;
V_2 -> V_105 = V_104 ;
}
static int F_55 ( struct V_24 * V_9 , unsigned V_104 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
if ( V_2 -> V_106 == V_107 )
F_54 ( V_2 , V_104 ) ;
return 0 ;
}
static void F_56 ( struct V_24 * V_9 , int V_19 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_108 * V_109 ;
if ( ! V_9 -> V_85 -> V_86 )
return;
V_109 = F_47 ( V_9 -> V_85 -> V_86 ) ;
if ( V_19 ) {
F_57 ( V_9 -> V_10 , L_30 ) ;
if ( V_35 -> V_110 )
V_35 -> V_110 ( 1 ) ;
if ( V_35 -> V_111 )
V_35 -> V_111 ( V_112 ) ;
#ifdef F_58
F_59 ( V_109 , V_109 -> V_88 , V_113 ) ;
F_60 ( V_109 -> V_114 . V_115 ) ;
#endif
} else {
F_57 ( V_9 -> V_10 , L_31 ) ;
#ifdef F_58
F_61 ( V_109 ) ;
#endif
if ( V_35 -> V_111 )
V_35 -> V_111 ( V_116 ) ;
if ( V_35 -> V_110 )
V_35 -> V_110 ( 0 ) ;
}
}
static int F_62 ( struct V_117 * V_85 , struct V_83 * V_86 )
{
struct V_1 * V_2 = F_12 ( V_85 -> V_24 , struct V_1 , V_9 ) ;
struct V_108 * V_109 ;
if ( V_2 -> V_35 -> V_69 == V_75 ) {
F_49 ( V_85 -> V_24 -> V_10 , L_32 ) ;
return - V_118 ;
}
if ( ! V_86 ) {
if ( V_85 -> V_119 == V_112 ) {
F_63 ( V_85 -> V_24 -> V_10 ) ;
F_56 ( V_85 -> V_24 , 0 ) ;
V_85 -> V_86 = NULL ;
V_85 -> V_119 = V_116 ;
F_64 ( & V_2 -> V_120 ) ;
} else {
V_85 -> V_86 = NULL ;
}
return 0 ;
}
V_109 = F_47 ( V_86 ) ;
V_109 -> V_121 = V_2 -> V_35 -> V_121 ;
V_85 -> V_86 = V_86 ;
F_57 ( V_85 -> V_24 -> V_10 , L_33 ) ;
if ( V_2 -> V_35 -> V_69 == V_122 || V_85 -> V_123 ) {
F_63 ( V_85 -> V_24 -> V_10 ) ;
F_64 ( & V_2 -> V_120 ) ;
}
return 0 ;
}
static void F_65 ( struct V_24 * V_9 , int V_19 )
{
struct V_1 * V_2 = F_12 ( V_9 , struct V_1 , V_9 ) ;
struct V_34 * V_35 = V_2 -> V_35 ;
if ( ! V_9 -> V_85 -> V_123 )
return;
if ( V_19 ) {
F_57 ( V_9 -> V_10 , L_34 ) ;
if ( V_35 -> V_111 )
V_35 -> V_111 ( V_124 ) ;
F_66 ( V_9 -> V_85 -> V_123 ) ;
} else {
F_57 ( V_9 -> V_10 , L_35 ) ;
F_67 ( V_9 -> V_85 -> V_123 ) ;
if ( V_35 -> V_111 )
V_35 -> V_111 ( V_116 ) ;
}
}
static int F_68 ( struct V_117 * V_85 ,
struct V_125 * V_123 )
{
struct V_1 * V_2 = F_12 ( V_85 -> V_24 , struct V_1 , V_9 ) ;
if ( V_2 -> V_35 -> V_69 == V_122 ) {
F_49 ( V_85 -> V_24 -> V_10 , L_36 ) ;
return - V_118 ;
}
if ( ! V_123 ) {
if ( V_85 -> V_119 == V_124 ) {
F_63 ( V_85 -> V_24 -> V_10 ) ;
F_65 ( V_85 -> V_24 , 0 ) ;
V_85 -> V_123 = NULL ;
V_85 -> V_119 = V_116 ;
F_64 ( & V_2 -> V_120 ) ;
} else {
V_85 -> V_123 = NULL ;
}
return 0 ;
}
V_85 -> V_123 = V_123 ;
F_57 ( V_85 -> V_24 -> V_10 ,
L_37 ) ;
if ( V_2 -> V_35 -> V_69 == V_75 || V_85 -> V_86 ) {
F_63 ( V_85 -> V_24 -> V_10 ) ;
F_64 ( & V_2 -> V_120 ) ;
}
return 0 ;
}
static bool F_69 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
bool V_4 = false ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_4 = V_126 & ( 1 << 4 ) ;
break;
case V_61 :
V_126 = F_11 ( V_9 , 0x87 ) ;
V_4 = V_126 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 |= ~ ( 1 << 1 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
F_16 ( 20 ) ;
V_126 &= ~ ( 1 << 3 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
V_126 &= ~ ( 1 << 2 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
V_126 &= ~ ( 1 << 1 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
F_16 ( 20 ) ;
V_126 &= ~ ( 1 << 0 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x8 , 0x85 ) ;
F_18 ( V_9 , 0x2 , 0x85 ) ;
F_18 ( V_9 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_71 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
bool V_4 = false ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_4 = V_126 & ( 1 << 4 ) ;
break;
case V_61 :
V_126 = F_11 ( V_9 , 0x87 ) ;
V_4 = V_126 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 &= ~ ( 1 << 0 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x2 , 0x85 ) ;
F_18 ( V_9 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_73 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_127 ;
bool V_4 = false ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_127 = F_11 ( V_9 , 0x15 ) ;
V_4 = ! ( V_127 & 1 ) ;
break;
case V_61 :
V_127 = F_11 ( V_9 , 0x87 ) ;
V_4 = V_127 & 2 ;
break;
default:
break;
}
return V_4 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 &= ~ ( 1 << 5 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x10 , 0x86 ) ;
break;
default:
break;
}
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_126 ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 |= ( 1 << 5 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x10 , 0x85 ) ;
break;
default:
break;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_128 , V_126 ;
V_128 = F_11 ( V_9 , V_44 ) ;
V_128 &= ~ V_45 ;
V_128 |= V_46 ;
F_18 ( V_9 , V_128 , V_44 ) ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 &= ~ ( 1 << 3 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
V_126 &= ~ ( 1 << 1 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
F_16 ( 20 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x3F , 0x86 ) ;
F_18 ( V_9 , 0x1F , 0x92 ) ;
F_18 ( V_9 , 0x1F , 0x95 ) ;
F_16 ( 100 ) ;
break;
default:
break;
}
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_128 , V_126 ;
switch ( V_2 -> V_35 -> V_60 ) {
case V_89 :
V_126 = F_11 ( V_9 , 0x34 ) ;
V_126 |= ~ ( 1 << 1 ) ;
F_18 ( V_9 , V_126 , 0x34 ) ;
break;
case V_61 :
F_18 ( V_9 , 0x3F , 0x86 ) ;
F_18 ( V_9 , 0x1F , 0x92 ) ;
F_18 ( V_9 , 0x1F , 0x95 ) ;
break;
default:
break;
}
V_128 = F_11 ( V_9 , V_44 ) ;
V_128 &= ~ V_45 ;
V_128 |= V_129 ;
F_18 ( V_9 , V_128 , V_44 ) ;
}
static void F_78 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_12 ( V_131 , struct V_1 , V_132 . V_133 ) ;
struct V_24 * V_9 = & V_2 -> V_9 ;
bool V_134 , V_135 , V_136 ;
unsigned long V_137 ;
F_57 ( V_9 -> V_10 , L_38 ) ;
switch ( V_2 -> V_138 ) {
case V_139 :
F_63 ( V_9 -> V_10 ) ;
F_76 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_138 = V_140 ;
V_2 -> V_141 = 0 ;
V_137 = V_142 ;
break;
case V_140 :
V_134 = F_73 ( V_2 ) ;
V_135 = ++ V_2 -> V_141 == V_143 ;
if ( V_134 || V_135 ) {
F_74 ( V_2 ) ;
F_72 ( V_2 ) ;
V_137 = V_144 ;
V_2 -> V_138 = V_145 ;
} else {
V_137 = V_142 ;
}
break;
case V_145 :
V_136 = F_71 ( V_2 ) ;
if ( V_136 ) {
F_70 ( V_2 ) ;
V_137 = V_146 ;
V_2 -> V_138 = V_147 ;
} else {
V_2 -> V_106 = V_107 ;
V_2 -> V_138 = V_148 ;
V_137 = 0 ;
}
break;
case V_147 :
V_136 = F_69 ( V_2 ) ;
if ( V_136 )
V_2 -> V_106 = V_149 ;
else
V_2 -> V_106 = V_150 ;
V_2 -> V_138 = V_151 ;
case V_151 :
V_2 -> V_138 = V_148 ;
case V_148 :
F_77 ( V_2 ) ;
F_57 ( V_9 -> V_10 , L_39 , V_2 -> V_106 ) ;
F_64 ( & V_2 -> V_120 ) ;
return;
default:
return;
}
F_79 ( & V_2 -> V_132 , V_137 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_35 ;
T_1 V_152 = F_15 ( V_68 ) ;
switch ( V_35 -> V_69 ) {
case V_70 :
if ( V_35 -> V_66 == V_67 ) {
if ( V_152 & V_153 )
F_52 ( V_154 , & V_2 -> V_155 ) ;
else
F_46 ( V_154 , & V_2 -> V_155 ) ;
if ( V_152 & V_156 )
F_52 ( V_157 , & V_2 -> V_155 ) ;
else
F_46 ( V_157 , & V_2 -> V_155 ) ;
} else if ( V_35 -> V_66 == V_158 ) {
F_52 ( V_154 , & V_2 -> V_155 ) ;
F_46 ( V_157 , & V_2 -> V_155 ) ;
}
break;
case V_122 :
F_46 ( V_154 , & V_2 -> V_155 ) ;
break;
case V_75 :
F_52 ( V_154 , & V_2 -> V_155 ) ;
if ( V_152 & V_156 )
F_52 ( V_157 , & V_2 -> V_155 ) ;
else
F_46 ( V_157 , & V_2 -> V_155 ) ;
break;
default:
break;
}
}
static void F_81 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_12 ( V_131 , struct V_1 , V_120 ) ;
struct V_117 * V_85 = V_2 -> V_9 . V_85 ;
switch ( V_85 -> V_119 ) {
case V_116 :
F_57 ( V_85 -> V_24 -> V_10 , L_40 ) ;
F_31 ( V_85 -> V_24 ) ;
F_80 ( V_2 ) ;
V_85 -> V_119 = V_159 ;
case V_159 :
F_57 ( V_85 -> V_24 -> V_10 , L_41 ) ;
if ( ! F_82 ( V_154 , & V_2 -> V_155 ) && V_85 -> V_86 ) {
F_13 ( F_15 ( V_68 ) & ~ V_74 , V_68 ) ;
F_56 ( V_85 -> V_24 , 1 ) ;
V_85 -> V_119 = V_112 ;
} else if ( F_82 ( V_157 , & V_2 -> V_155 ) ) {
switch ( V_2 -> V_138 ) {
case V_139 :
F_78 ( & V_2 -> V_132 . V_133 ) ;
break;
case V_148 :
switch ( V_2 -> V_106 ) {
case V_149 :
F_54 ( V_2 ,
V_160 ) ;
break;
case V_150 :
F_54 ( V_2 ,
V_160 ) ;
F_65 ( V_85 -> V_24 ,
1 ) ;
V_85 -> V_119
= V_124 ;
break;
case V_107 :
F_54 ( V_2 , V_161 ) ;
F_65 ( V_85 -> V_24 ,
1 ) ;
V_85 -> V_119
= V_124 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
if ( F_83 ( & V_2 -> V_132 ) ) {
F_84 ( V_85 -> V_24 -> V_10 ) ;
F_31 ( V_85 -> V_24 ) ;
}
F_54 ( V_2 , 0 ) ;
V_2 -> V_138 = V_139 ;
V_2 -> V_106 = V_162 ;
}
if ( V_85 -> V_119 == V_159 )
F_84 ( V_85 -> V_24 -> V_10 ) ;
break;
case V_124 :
F_57 ( V_85 -> V_24 -> V_10 , L_42 ) ;
if ( ! F_82 ( V_157 , & V_2 -> V_155 ) ||
! F_82 ( V_154 , & V_2 -> V_155 ) ) {
F_54 ( V_2 , 0 ) ;
F_65 ( V_85 -> V_24 , 0 ) ;
V_2 -> V_138 = V_139 ;
V_2 -> V_106 = V_162 ;
V_85 -> V_119 = V_159 ;
F_31 ( V_85 -> V_24 ) ;
F_64 ( V_131 ) ;
}
break;
case V_112 :
F_57 ( V_85 -> V_24 -> V_10 , L_43 ) ;
if ( F_82 ( V_154 , & V_2 -> V_155 ) ) {
F_56 ( V_85 -> V_24 , 0 ) ;
V_85 -> V_119 = V_159 ;
F_31 ( V_85 -> V_24 ) ;
F_64 ( V_131 ) ;
}
break;
default:
break;
}
}
static T_3 F_85 ( int V_88 , void * V_163 )
{
struct V_1 * V_2 = V_163 ;
struct V_24 * V_9 = & V_2 -> V_9 ;
T_1 V_152 = 0 ;
if ( F_41 ( & V_2 -> V_87 ) ) {
F_86 ( V_88 ) ;
V_2 -> V_103 = 1 ;
F_87 ( V_9 -> V_10 ) ;
return V_164 ;
}
V_152 = F_15 ( V_68 ) ;
if ( ! ( V_152 & ( V_165 | V_166 ) ) )
return V_167 ;
if ( ( V_152 & V_165 ) && ( V_152 & V_73 ) ) {
if ( V_152 & V_153 )
F_52 ( V_154 , & V_2 -> V_155 ) ;
else
F_46 ( V_154 , & V_2 -> V_155 ) ;
F_57 ( V_9 -> V_10 , L_44 ) ;
F_88 ( V_9 -> V_10 ) ;
} else if ( ( V_152 & V_166 ) && ( V_152 & V_74 ) ) {
if ( V_152 & V_156 )
F_52 ( V_157 , & V_2 -> V_155 ) ;
else
F_46 ( V_157 , & V_2 -> V_155 ) ;
F_57 ( V_9 -> V_10 , L_45 ) ;
F_88 ( V_9 -> V_10 ) ;
}
F_13 ( V_152 , V_68 ) ;
F_64 ( & V_2 -> V_120 ) ;
return V_164 ;
}
static int F_89 ( struct V_168 * V_169 , void * V_170 )
{
struct V_1 * V_2 = V_169 -> V_171 ;
struct V_117 * V_85 = V_2 -> V_9 . V_85 ;
switch ( V_85 -> V_119 ) {
case V_112 :
F_90 ( V_169 , L_46 ) ;
break;
case V_124 :
F_90 ( V_169 , L_47 ) ;
break;
default:
F_90 ( V_169 , L_48 ) ;
break;
}
return 0 ;
}
static int F_91 ( struct V_172 * V_172 , struct V_173 * V_173 )
{
return F_92 ( V_173 , F_89 , V_172 -> V_174 ) ;
}
static T_4 F_93 ( struct V_173 * V_173 , const char T_5 * V_175 ,
T_6 V_176 , T_7 * V_177 )
{
struct V_168 * V_169 = V_173 -> V_178 ;
struct V_1 * V_2 = V_169 -> V_171 ;
char V_179 [ 16 ] ;
struct V_117 * V_85 = V_2 -> V_9 . V_85 ;
int V_180 = V_176 ;
enum V_181 V_182 ;
memset ( V_179 , 0x00 , sizeof( V_179 ) ) ;
if ( F_94 ( & V_179 , V_175 , F_95 ( T_6 , sizeof( V_179 ) - 1 , V_176 ) ) ) {
V_180 = - V_183 ;
goto V_184;
}
if ( ! strncmp ( V_179 , L_49 , 4 ) ) {
V_182 = V_122 ;
} else if ( ! strncmp ( V_179 , L_50 , 10 ) ) {
V_182 = V_75 ;
} else if ( ! strncmp ( V_179 , L_51 , 4 ) ) {
V_182 = V_185 ;
} else {
V_180 = - V_186 ;
goto V_184;
}
switch ( V_182 ) {
case V_185 :
switch ( V_85 -> V_119 ) {
case V_112 :
case V_124 :
F_52 ( V_154 , & V_2 -> V_155 ) ;
F_46 ( V_157 , & V_2 -> V_155 ) ;
break;
default:
goto V_184;
}
break;
case V_75 :
switch ( V_85 -> V_119 ) {
case V_159 :
case V_112 :
F_52 ( V_154 , & V_2 -> V_155 ) ;
F_52 ( V_157 , & V_2 -> V_155 ) ;
break;
default:
goto V_184;
}
break;
case V_122 :
switch ( V_85 -> V_119 ) {
case V_159 :
case V_124 :
F_46 ( V_154 , & V_2 -> V_155 ) ;
break;
default:
goto V_184;
}
break;
default:
goto V_184;
}
F_63 ( V_85 -> V_24 -> V_10 ) ;
F_64 ( & V_2 -> V_120 ) ;
V_184:
return V_180 ;
}
static int F_96 ( struct V_1 * V_2 )
{
V_187 = F_97 ( L_52 , NULL ) ;
if ( ! V_187 || F_34 ( V_187 ) )
return - V_118 ;
V_188 = F_98 ( L_53 , V_189 | V_190 ,
V_187 , V_2 , & V_191 ) ;
if ( ! V_188 ) {
F_99 ( V_187 ) ;
V_187 = NULL ;
return - V_118 ;
}
return 0 ;
}
static void F_100 ( void )
{
F_99 ( V_188 ) ;
F_99 ( V_187 ) ;
}
static int F_101 ( struct V_192 * V_193 , struct V_1 * V_2 )
{
struct V_34 * V_35 ;
const struct V_194 * V_195 ;
struct V_196 * V_197 = V_193 -> V_10 . V_198 ;
struct V_199 * V_200 ;
int V_201 , V_4 , V_202 ;
T_1 V_32 , V_203 [ 3 ] ;
V_35 = F_102 ( & V_193 -> V_10 , sizeof( * V_35 ) , V_204 ) ;
if ( ! V_35 )
return - V_205 ;
V_2 -> V_35 = V_35 ;
V_195 = F_103 ( V_206 , & V_193 -> V_10 ) ;
V_35 -> V_60 = (enum V_207 ) V_195 -> V_163 ;
V_2 -> V_47 = F_104 ( & V_193 -> V_10 , L_54 ) ;
if ( F_34 ( V_2 -> V_47 ) )
return F_105 ( V_2 -> V_47 ) ;
V_2 -> V_48 = F_104 ( & V_193 -> V_10 , L_55 ) ;
if ( F_34 ( V_2 -> V_48 ) )
V_2 -> V_48 = NULL ;
V_35 -> V_69 = F_106 ( V_197 ) ;
if ( V_35 -> V_69 == V_185 )
V_35 -> V_69 = V_70 ;
V_35 -> V_66 = V_67 ;
if ( ! F_107 ( V_197 , L_56 , & V_32 ) )
if ( V_32 == V_94 )
V_35 -> V_66 = V_32 ;
if ( ! F_107 ( V_197 , L_57 , & V_32 ) && V_32 < 2 )
V_2 -> V_49 = V_32 ;
V_2 -> V_6 [ V_81 ] = V_208 ;
V_2 -> V_6 [ V_7 ] = V_209 ;
V_2 -> V_6 [ V_8 ] = V_210 ;
if ( F_108 ( V_197 , L_58 , & V_201 ) &&
V_201 == sizeof( V_203 ) ) {
F_109 ( V_197 , L_58 ,
V_203 , V_201 / sizeof( * V_203 ) ) ;
V_2 -> V_6 [ V_81 ] = V_203 [ V_81 ] ;
V_2 -> V_6 [ V_7 ] = V_203 [ V_7 ] ;
V_2 -> V_6 [ V_8 ] = V_203 [ V_8 ] ;
}
V_200 = F_110 ( V_197 , L_59 , & V_201 ) ;
if ( ! V_200 || ! V_201 )
return 0 ;
V_202 = V_201 / sizeof( T_1 ) ;
if ( V_202 >= V_40 ) {
F_111 ( & V_193 -> V_10 , L_60 , V_202 ) ;
return 0 ;
}
V_35 -> V_37 = F_102 ( & V_193 -> V_10 , V_201 , V_204 ) ;
if ( ! V_35 -> V_37 )
return 0 ;
V_4 = F_109 ( V_197 , L_59 ,
V_35 -> V_37 , V_202 ) ;
if ( ! V_4 )
V_35 -> V_41 = V_202 ;
return 0 ;
}
static int F_112 ( struct V_192 * V_193 )
{
struct V_211 V_212 [ 3 ] ;
int V_4 = 0 ;
struct V_196 * V_213 = V_193 -> V_10 . V_198 ;
struct V_34 * V_35 ;
struct V_214 * V_215 ;
struct V_1 * V_2 ;
struct V_24 * V_9 ;
void T_2 * V_216 ;
V_2 = F_102 ( & V_193 -> V_10 , sizeof( struct V_1 ) , V_204 ) ;
if ( ! V_2 )
return - V_205 ;
V_35 = F_113 ( & V_193 -> V_10 ) ;
if ( ! V_35 ) {
if ( ! V_213 )
return - V_217 ;
V_4 = F_101 ( V_193 , V_2 ) ;
if ( V_4 )
return V_4 ;
}
V_2 -> V_9 . V_85 = F_102 ( & V_193 -> V_10 , sizeof( struct V_117 ) ,
V_204 ) ;
if ( ! V_2 -> V_9 . V_85 )
return - V_205 ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_10 = & V_193 -> V_10 ;
V_2 -> V_97 = F_114 ( & V_193 -> V_10 , V_213 ? L_61 : L_62 ) ;
if ( F_34 ( V_2 -> V_97 ) ) {
F_3 ( & V_193 -> V_10 , L_63 ) ;
return F_105 ( V_2 -> V_97 ) ;
}
V_2 -> V_96 = F_114 ( & V_193 -> V_10 , V_213 ? L_64 : L_65 ) ;
if ( F_34 ( V_2 -> V_96 ) ) {
F_3 ( & V_193 -> V_10 , L_66 ) ;
return F_105 ( V_2 -> V_96 ) ;
}
V_2 -> V_64 = F_114 ( & V_193 -> V_10 ,
V_213 ? L_67 : L_68 ) ;
V_215 = F_115 ( V_193 , V_218 , 0 ) ;
if ( ! V_215 )
return - V_186 ;
V_2 -> V_212 = F_116 ( & V_193 -> V_10 , V_215 -> V_219 , F_117 ( V_215 ) ) ;
if ( ! V_2 -> V_212 )
return - V_205 ;
if ( V_2 -> V_49 ) {
V_216 = F_118 ( & V_193 -> V_10 , V_220 , 4 ) ;
if ( ! V_216 )
return - V_205 ;
F_13 ( 0x1 , V_216 ) ;
}
F_49 ( & V_193 -> V_10 , L_69 , V_2 -> V_212 ) ;
V_2 -> V_88 = F_119 ( V_193 , 0 ) ;
if ( V_2 -> V_88 < 0 ) {
F_3 ( & V_193 -> V_10 , L_70 ) ;
return V_2 -> V_88 ;
}
V_212 [ 0 ] . V_221 = L_71 ;
V_212 [ 1 ] . V_221 = L_72 ;
V_212 [ 2 ] . V_221 = L_73 ;
V_4 = F_120 ( V_2 -> V_9 . V_10 , F_121 ( V_212 ) , V_212 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_5 = V_212 [ 0 ] . V_222 ;
V_2 -> V_12 = V_212 [ 1 ] . V_222 ;
V_2 -> V_15 = V_212 [ 2 ] . V_222 ;
F_122 ( V_2 -> V_97 , 60000000 ) ;
F_35 ( V_2 -> V_97 ) ;
F_35 ( V_2 -> V_96 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_35 ( V_2 -> V_64 ) ;
V_4 = F_1 ( V_2 , 1 ) ;
if ( V_4 ) {
F_3 ( & V_193 -> V_10 , L_74 ) ;
goto V_223;
}
V_4 = F_6 ( V_2 , 1 ) ;
if ( V_4 ) {
F_3 ( & V_193 -> V_10 , L_75 ) ;
goto V_224;
}
V_4 = F_7 ( V_2 , 1 ) ;
if ( V_4 ) {
F_3 ( & V_193 -> V_10 , L_76 ) ;
goto V_225;
}
F_13 ( 0 , V_226 ) ;
F_13 ( 0 , V_68 ) ;
F_123 ( & V_2 -> V_120 , F_81 ) ;
F_124 ( & V_2 -> V_132 , F_78 ) ;
V_4 = F_125 ( & V_193 -> V_10 , V_2 -> V_88 , F_85 , V_113 ,
L_52 , V_2 ) ;
if ( V_4 ) {
F_3 ( & V_193 -> V_10 , L_77 ) ;
goto V_225;
}
V_9 -> V_3 = F_38 ;
V_9 -> V_227 = F_55 ;
V_9 -> V_228 = F_22 ;
V_9 -> type = V_229 ;
V_9 -> V_230 = & V_231 ;
V_9 -> V_85 -> V_24 = & V_2 -> V_9 ;
V_9 -> V_85 -> V_232 = F_62 ;
V_9 -> V_85 -> V_233 = F_68 ;
F_33 ( V_9 ) ;
V_4 = F_126 ( & V_2 -> V_9 ) ;
if ( V_4 ) {
F_3 ( & V_193 -> V_10 , L_78 ) ;
goto V_225;
}
F_127 ( V_193 , V_2 ) ;
F_128 ( & V_193 -> V_10 , 1 ) ;
if ( V_2 -> V_35 -> V_69 == V_70 &&
V_2 -> V_35 -> V_66 == V_158 ) {
V_4 = F_96 ( V_2 ) ;
if ( V_4 )
F_57 ( & V_193 -> V_10 , L_79 ) ;
}
F_129 ( & V_193 -> V_10 ) ;
F_130 ( & V_193 -> V_10 ) ;
return 0 ;
V_225:
F_6 ( V_2 , 0 ) ;
V_224:
F_1 ( V_2 , 0 ) ;
V_223:
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_97 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_37 ( V_2 -> V_64 ) ;
return V_4 ;
}
static int F_131 ( struct V_192 * V_193 )
{
struct V_1 * V_2 = F_132 ( V_193 ) ;
struct V_24 * V_9 = & V_2 -> V_9 ;
int V_26 = 0 ;
if ( V_9 -> V_85 -> V_86 || V_9 -> V_85 -> V_123 )
return - V_234 ;
F_100 () ;
F_83 ( & V_2 -> V_132 ) ;
F_133 ( & V_2 -> V_120 ) ;
F_134 ( & V_193 -> V_10 ) ;
F_128 ( & V_193 -> V_10 , 0 ) ;
F_135 ( & V_193 -> V_10 ) ;
F_136 ( V_9 ) ;
F_42 ( V_2 -> V_88 ) ;
F_11 ( V_9 , 0x14 ) ;
F_18 ( V_9 , 0x08 , 0x09 ) ;
F_13 ( F_15 ( V_51 ) | V_90 , V_51 ) ;
while ( V_26 < V_91 ) {
if ( F_15 ( V_51 ) & V_90 )
break;
F_16 ( 1 ) ;
V_26 ++ ;
}
if ( V_26 >= V_91 )
F_3 ( V_9 -> V_10 , L_25 ) ;
F_37 ( V_2 -> V_96 ) ;
F_37 ( V_2 -> V_97 ) ;
if ( ! F_34 ( V_2 -> V_64 ) )
F_37 ( V_2 -> V_64 ) ;
F_6 ( V_2 , 0 ) ;
F_137 ( & V_193 -> V_10 ) ;
return 0 ;
}
static int F_138 ( struct V_235 * V_10 )
{
struct V_1 * V_2 = F_139 ( V_10 ) ;
struct V_117 * V_85 = V_2 -> V_9 . V_85 ;
F_57 ( V_10 , L_80 ) ;
if ( V_85 -> V_119 != V_116 )
F_140 ( V_10 , 1000 ) ;
return - V_236 ;
}
static int F_141 ( struct V_235 * V_10 )
{
struct V_1 * V_2 = F_139 ( V_10 ) ;
F_57 ( V_10 , L_81 ) ;
return F_40 ( V_2 ) ;
}
static int F_142 ( struct V_235 * V_10 )
{
struct V_1 * V_2 = F_139 ( V_10 ) ;
F_57 ( V_10 , L_82 ) ;
return F_50 ( V_2 ) ;
}
static int F_143 ( struct V_235 * V_10 )
{
struct V_1 * V_2 = F_139 ( V_10 ) ;
F_57 ( V_10 , L_83 ) ;
return F_40 ( V_2 ) ;
}
static int F_144 ( struct V_235 * V_10 )
{
struct V_1 * V_2 = F_139 ( V_10 ) ;
int V_4 ;
F_57 ( V_10 , L_84 ) ;
V_4 = F_50 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_135 ( V_10 ) ;
F_129 ( V_10 ) ;
F_130 ( V_10 ) ;
return 0 ;
}
