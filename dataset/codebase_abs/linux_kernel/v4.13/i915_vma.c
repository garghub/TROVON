static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const unsigned int V_5 = V_4 -> V_6 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_2 , struct V_8 , V_10 [ V_5 ] ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_3 ( ! F_4 ( V_9 , V_5 ) ) ;
F_5 ( V_9 , V_5 ) ;
if ( F_6 ( V_9 ) )
return;
F_3 ( ! F_7 ( & V_9 -> V_13 ) ) ;
F_8 ( & V_9 -> V_14 , & V_9 -> V_15 -> V_16 ) ;
if ( F_9 ( F_10 ( V_9 ) && ! F_11 ( V_9 ) ) )
F_12 ( F_13 ( V_9 ) ) ;
F_3 ( ! F_14 ( V_12 ) ) ;
if ( -- V_12 -> V_17 )
return;
if ( V_12 -> V_18 )
F_8 ( & V_12 -> V_19 , & V_4 -> V_20 -> V_21 . V_22 ) ;
V_12 -> V_21 . V_23 = true ;
if ( F_15 ( V_12 ) ) {
F_16 ( V_12 ) ;
F_17 ( V_12 ) ;
}
}
static struct V_8 *
F_18 ( struct V_11 * V_12 ,
struct V_24 * V_15 ,
const struct V_25 * V_26 )
{
struct V_8 * V_9 ;
struct V_27 * V_28 , * * V_29 ;
int V_30 ;
F_3 ( V_15 == & V_15 -> V_20 -> V_21 . V_31 -> V_32 ) ;
V_9 = F_19 ( V_15 -> V_20 -> V_33 , V_34 ) ;
if ( V_9 == NULL )
return F_20 ( - V_35 ) ;
for ( V_30 = 0 ; V_30 < F_21 ( V_9 -> V_10 ) ; V_30 ++ )
F_22 ( & V_9 -> V_10 [ V_30 ] , F_1 ) ;
F_22 ( & V_9 -> V_36 , NULL ) ;
V_9 -> V_15 = V_15 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_37 = V_12 -> V_37 ;
V_9 -> V_38 = V_12 -> V_32 . V_38 ;
V_9 -> V_39 = V_40 ;
if ( V_26 && V_26 -> type != V_41 ) {
V_9 -> V_42 = * V_26 ;
if ( V_26 -> type == V_43 ) {
F_3 ( F_23 ( V_44 ,
V_26 -> V_45 . V_46 ,
V_26 -> V_45 . V_38 ,
V_12 -> V_32 . V_38 >> V_47 ) ) ;
V_9 -> V_38 = V_26 -> V_45 . V_38 ;
V_9 -> V_38 <<= V_47 ;
F_3 ( V_9 -> V_38 >= V_12 -> V_32 . V_38 ) ;
} else if ( V_26 -> type == V_48 ) {
V_9 -> V_38 = F_24 ( & V_26 -> V_49 ) ;
V_9 -> V_38 <<= V_47 ;
}
}
if ( F_9 ( V_9 -> V_38 > V_15 -> V_50 ) )
goto V_51;
F_3 ( ! F_25 ( V_9 -> V_38 , V_52 ) ) ;
if ( F_26 ( V_15 ) ) {
if ( F_9 ( F_27 ( V_9 -> V_38 , V_53 ) ) )
goto V_51;
V_9 -> V_54 = F_28 ( V_15 -> V_20 , V_9 -> V_38 ,
F_29 ( V_12 ) ,
F_30 ( V_12 ) ) ;
if ( F_9 ( V_9 -> V_54 < V_9 -> V_38 ||
V_9 -> V_54 > V_15 -> V_50 ) )
goto V_51;
F_3 ( ! F_25 ( V_9 -> V_54 , V_40 ) ) ;
V_9 -> V_55 = F_31 ( V_15 -> V_20 , V_9 -> V_38 ,
F_29 ( V_12 ) ,
F_30 ( V_12 ) ) ;
F_3 ( ! F_32 ( V_9 -> V_55 ) ) ;
V_9 -> V_56 |= V_57 ;
F_33 ( & V_9 -> V_58 , & V_12 -> V_59 ) ;
} else {
F_34 ( F_35 ( V_15 ) ) ;
F_36 ( & V_9 -> V_58 , & V_12 -> V_59 ) ;
}
V_28 = NULL ;
V_29 = & V_12 -> V_60 . V_27 ;
while ( * V_29 ) {
struct V_8 * V_61 ;
V_28 = * V_29 ;
V_61 = F_37 ( V_28 , struct V_8 , V_62 ) ;
if ( F_38 ( V_61 , V_15 , V_26 ) < 0 )
V_29 = & V_28 -> V_63 ;
else
V_29 = & V_28 -> V_64 ;
}
F_39 ( & V_9 -> V_62 , V_28 , V_29 ) ;
F_40 ( & V_9 -> V_62 , & V_12 -> V_60 ) ;
F_33 ( & V_9 -> V_14 , & V_15 -> V_65 ) ;
return V_9 ;
V_51:
F_41 ( V_15 -> V_20 -> V_33 , V_9 ) ;
return F_20 ( - V_66 ) ;
}
static struct V_8 *
F_42 ( struct V_11 * V_12 ,
struct V_24 * V_15 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = V_12 -> V_60 . V_27 ;
while ( V_28 ) {
struct V_8 * V_9 = F_37 ( V_28 , struct V_8 , V_62 ) ;
long V_67 ;
V_67 = F_38 ( V_9 , V_15 , V_26 ) ;
if ( V_67 == 0 )
return V_9 ;
if ( V_67 < 0 )
V_28 = V_28 -> V_63 ;
else
V_28 = V_28 -> V_64 ;
}
return NULL ;
}
struct V_8 *
F_43 ( struct V_11 * V_12 ,
struct V_24 * V_15 ,
const struct V_25 * V_26 )
{
struct V_8 * V_9 ;
F_44 ( & V_12 -> V_32 . V_68 -> V_69 ) ;
F_3 ( V_26 && ! F_26 ( V_15 ) ) ;
F_3 ( V_15 -> V_70 ) ;
V_9 = F_42 ( V_12 , V_15 , V_26 ) ;
if ( ! V_9 )
V_9 = F_18 ( V_12 , V_15 , V_26 ) ;
F_3 ( ! F_45 ( V_9 ) && F_10 ( V_9 ) ) ;
F_3 ( ! F_45 ( V_9 ) && F_38 ( V_9 , V_15 , V_26 ) ) ;
F_3 ( ! F_45 ( V_9 ) && F_42 ( V_12 , V_15 , V_26 ) != V_9 ) ;
return V_9 ;
}
int F_46 ( struct V_8 * V_9 , enum V_71 V_72 ,
V_53 V_56 )
{
V_53 V_73 ;
V_53 V_74 ;
int V_75 ;
F_3 ( ! F_7 ( & V_9 -> V_13 ) ) ;
F_3 ( V_9 -> V_38 > V_9 -> V_13 . V_38 ) ;
if ( F_47 ( F_48 ( V_9 -> V_13 . V_76 ,
V_9 -> V_13 . V_38 ,
V_9 -> V_15 -> V_50 ) ) )
return - V_77 ;
if ( F_47 ( ! V_56 ) )
return - V_78 ;
V_73 = 0 ;
if ( V_56 & V_79 )
V_73 |= V_80 ;
if ( V_56 & V_81 )
V_73 |= V_82 ;
V_74 = V_9 -> V_56 & ( V_80 | V_82 ) ;
if ( V_56 & V_83 )
V_73 |= V_74 ;
else
V_73 &= ~ V_74 ;
if ( V_73 == 0 )
return 0 ;
F_49 ( V_9 , V_73 ) ;
V_75 = V_9 -> V_15 -> V_84 ( V_9 , V_72 , V_73 ) ;
if ( V_75 )
return V_75 ;
V_9 -> V_56 |= V_73 ;
return 0 ;
}
void T_1 * F_50 ( struct V_8 * V_9 )
{
void T_1 * V_85 ;
F_51 ( V_9 -> V_15 -> V_20 ) ;
F_44 ( & V_9 -> V_15 -> V_20 -> V_86 . V_69 ) ;
if ( F_12 ( ! F_52 ( V_9 ) ) )
return F_53 ( - V_77 ) ;
F_3 ( ! F_54 ( V_9 ) ) ;
F_3 ( ( V_9 -> V_56 & V_80 ) == 0 ) ;
V_85 = V_9 -> V_87 ;
if ( V_85 == NULL ) {
V_85 = F_55 ( & F_56 ( V_9 -> V_15 ) -> V_88 ,
V_9 -> V_13 . V_76 ,
V_9 -> V_13 . V_38 ) ;
if ( V_85 == NULL )
return F_53 ( - V_35 ) ;
V_9 -> V_87 = V_85 ;
}
F_57 ( V_9 ) ;
return V_85 ;
}
void F_58 ( struct V_8 * * V_89 )
{
struct V_8 * V_9 ;
struct V_11 * V_12 ;
V_9 = F_59 ( V_89 ) ;
if ( ! V_9 )
return;
V_12 = V_9 -> V_12 ;
F_60 ( V_9 ) ;
F_61 ( V_9 ) ;
F_62 ( V_12 ) ;
}
bool F_63 ( const struct V_8 * V_9 ,
V_44 V_38 , V_44 V_90 , V_44 V_56 )
{
if ( ! F_7 ( & V_9 -> V_13 ) )
return false ;
if ( V_9 -> V_13 . V_38 < V_38 )
return true ;
F_3 ( V_90 && ! F_32 ( V_90 ) ) ;
if ( V_90 && ! F_25 ( V_9 -> V_13 . V_76 , V_90 ) )
return true ;
if ( V_56 & V_91 && ! F_52 ( V_9 ) )
return true ;
if ( V_56 & V_92 &&
V_9 -> V_13 . V_76 < ( V_56 & V_93 ) )
return true ;
if ( V_56 & V_94 &&
V_9 -> V_13 . V_76 != ( V_56 & V_93 ) )
return true ;
return false ;
}
void F_64 ( struct V_8 * V_9 )
{
bool V_88 , V_95 ;
F_3 ( ! F_54 ( V_9 ) ) ;
F_3 ( ! V_9 -> V_54 ) ;
if ( V_9 -> V_42 . type == V_48 )
return;
V_95 = ( V_9 -> V_13 . V_38 >= V_9 -> V_54 &&
F_25 ( V_9 -> V_13 . V_76 , V_9 -> V_55 ) ) ;
V_88 = V_9 -> V_13 . V_76 + V_9 -> V_54 <= F_56 ( V_9 -> V_15 ) -> V_96 ;
if ( V_88 && V_95 )
V_9 -> V_56 |= V_97 ;
else
V_9 -> V_56 &= ~ V_97 ;
}
static bool F_65 ( struct V_98 * V_13 , unsigned long V_99 )
{
return V_13 -> V_100 && V_13 -> V_99 != V_99 ;
}
bool F_66 ( struct V_8 * V_9 , unsigned long V_72 )
{
struct V_98 * V_13 = & V_9 -> V_13 ;
struct V_98 * V_101 ;
if ( V_9 -> V_15 -> V_21 . V_102 == NULL )
return true ;
F_3 ( ! F_7 ( V_13 ) ) ;
F_3 ( F_67 ( & V_13 -> V_103 ) ) ;
V_101 = F_68 ( V_13 , V_103 ) ;
if ( F_65 ( V_101 , V_72 ) && ! F_69 ( V_101 ) )
return false ;
V_101 = F_70 ( V_13 , V_103 ) ;
if ( F_65 ( V_101 , V_72 ) && ! F_69 ( V_13 ) )
return false ;
return true ;
}
static int
F_71 ( struct V_8 * V_9 , V_44 V_38 , V_44 V_90 , V_44 V_56 )
{
struct V_104 * V_105 = V_9 -> V_15 -> V_20 ;
struct V_11 * V_12 = V_9 -> V_12 ;
V_44 V_76 , V_106 ;
int V_75 ;
F_3 ( V_9 -> V_56 & ( V_80 | V_82 ) ) ;
F_3 ( F_7 ( & V_9 -> V_13 ) ) ;
V_38 = F_72 ( V_38 , V_9 -> V_38 ) ;
V_90 = F_72 ( V_90 , V_9 -> V_39 ) ;
if ( V_56 & V_91 ) {
V_38 = F_73 ( F_74 ( V_38 ) , V_38 , V_9 -> V_54 ) ;
V_90 = F_73 ( F_74 ( V_90 ) ,
V_90 , V_9 -> V_55 ) ;
}
F_3 ( ! F_25 ( V_38 , V_52 ) ) ;
F_3 ( ! F_25 ( V_90 , V_40 ) ) ;
F_3 ( ! F_32 ( V_90 ) ) ;
V_76 = V_56 & V_92 ? V_56 & V_93 : 0 ;
F_3 ( ! F_25 ( V_76 , V_52 ) ) ;
V_106 = V_9 -> V_15 -> V_50 ;
if ( V_56 & V_91 )
V_106 = F_75 ( V_44 , V_106 , V_105 -> V_107 . V_96 ) ;
if ( V_56 & V_108 )
V_106 = F_75 ( V_44 , V_106 , ( 1ULL << 32 ) - V_52 ) ;
F_3 ( ! F_25 ( V_106 , V_52 ) ) ;
if ( V_38 > V_106 ) {
F_76 ( L_1 ,
V_38 , V_12 -> V_32 . V_38 ,
V_56 & V_91 ? L_2 : L_3 ,
V_106 ) ;
return - V_109 ;
}
V_75 = F_77 ( V_12 ) ;
if ( V_75 )
return V_75 ;
if ( V_56 & V_94 ) {
V_44 V_46 = V_56 & V_93 ;
if ( ! F_25 ( V_46 , V_90 ) ||
F_48 ( V_46 , V_38 , V_106 ) ) {
V_75 = - V_78 ;
goto V_110;
}
V_75 = F_78 ( V_9 -> V_15 , & V_9 -> V_13 ,
V_38 , V_46 , V_12 -> V_72 ,
V_56 ) ;
if ( V_75 )
goto V_110;
} else {
V_75 = F_79 ( V_9 -> V_15 , & V_9 -> V_13 ,
V_38 , V_90 , V_12 -> V_72 ,
V_76 , V_106 , V_56 ) ;
if ( V_75 )
goto V_110;
F_3 ( V_9 -> V_13 . V_76 < V_76 ) ;
F_3 ( V_9 -> V_13 . V_76 + V_9 -> V_13 . V_38 > V_106 ) ;
}
F_3 ( ! F_7 ( & V_9 -> V_13 ) ) ;
F_3 ( ! F_66 ( V_9 , V_12 -> V_72 ) ) ;
F_8 ( & V_12 -> V_19 , & V_105 -> V_21 . V_22 ) ;
F_8 ( & V_9 -> V_14 , & V_9 -> V_15 -> V_16 ) ;
V_12 -> V_18 ++ ;
F_3 ( F_80 ( & V_12 -> V_21 . V_111 ) < V_12 -> V_18 ) ;
return 0 ;
V_110:
F_81 ( V_12 ) ;
return V_75 ;
}
static void
F_82 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_3 ( ! F_7 ( & V_9 -> V_13 ) ) ;
F_3 ( V_9 -> V_56 & ( V_80 | V_82 ) ) ;
F_83 ( & V_9 -> V_13 ) ;
F_8 ( & V_9 -> V_14 , & V_9 -> V_15 -> V_65 ) ;
if ( -- V_12 -> V_18 == 0 )
F_8 ( & V_12 -> V_19 ,
& F_84 ( V_12 -> V_32 . V_68 ) -> V_21 . V_65 ) ;
F_81 ( V_12 ) ;
F_3 ( F_80 ( & V_12 -> V_21 . V_111 ) < V_12 -> V_18 ) ;
}
int F_85 ( struct V_8 * V_9 ,
V_44 V_38 , V_44 V_90 , V_44 V_56 )
{
const unsigned int V_112 = V_9 -> V_56 ;
int V_75 ;
F_44 ( & V_9 -> V_15 -> V_20 -> V_86 . V_69 ) ;
F_3 ( ( V_56 & ( V_79 | V_81 ) ) == 0 ) ;
F_3 ( ( V_56 & V_79 ) && ! F_54 ( V_9 ) ) ;
if ( F_12 ( V_112 & V_113 ) ) {
V_75 = - V_114 ;
goto V_110;
}
if ( ( V_112 & V_115 ) == 0 ) {
V_75 = F_71 ( V_9 , V_38 , V_90 , V_56 ) ;
if ( V_75 )
goto V_110;
}
V_75 = F_46 ( V_9 , V_9 -> V_12 -> V_72 , V_56 ) ;
if ( V_75 )
goto V_116;
if ( ( V_112 ^ V_9 -> V_56 ) & V_80 )
F_64 ( V_9 ) ;
F_3 ( ! F_7 ( & V_9 -> V_13 ) ) ;
F_3 ( F_63 ( V_9 , V_38 , V_90 , V_56 ) ) ;
return 0 ;
V_116:
if ( ( V_112 & V_115 ) == 0 ) {
F_3 ( V_9 -> V_117 ) ;
F_82 ( V_9 ) ;
}
V_110:
F_86 ( V_9 ) ;
return V_75 ;
}
static void F_87 ( struct V_8 * V_9 )
{
F_3 ( V_9 -> V_13 . V_100 ) ;
F_3 ( F_6 ( V_9 ) ) ;
F_3 ( ! F_10 ( V_9 ) ) ;
F_3 ( V_9 -> V_118 ) ;
F_88 ( & V_9 -> V_14 ) ;
if ( ! F_54 ( V_9 ) )
F_89 ( F_35 ( V_9 -> V_15 ) ) ;
F_41 ( F_84 ( V_9 -> V_12 -> V_32 . V_68 ) -> V_33 , V_9 ) ;
}
void F_90 ( struct V_8 * V_9 )
{
struct V_119 * V_120 = V_9 -> V_120 ;
if ( V_120 -> V_121 . V_122 & V_123 ) {
F_91 ( & V_120 -> V_121 . V_124 ) ;
V_120 -> V_121 . V_122 &= ~ V_123 ;
}
F_92 ( & V_9 -> V_125 ) ;
V_120 -> V_121 . V_126 -- ;
if ( F_54 ( V_9 ) )
V_9 -> V_12 -> V_127 = NULL ;
V_9 -> V_120 = NULL ;
F_93 ( V_9 ) ;
}
void F_61 ( struct V_8 * V_9 )
{
F_3 ( F_10 ( V_9 ) ) ;
V_9 -> V_56 |= V_128 ;
if ( V_9 -> V_120 )
F_90 ( V_9 ) ;
F_88 ( & V_9 -> V_58 ) ;
F_94 ( & V_9 -> V_62 , & V_9 -> V_12 -> V_60 ) ;
if ( ! F_6 ( V_9 ) && ! F_11 ( V_9 ) )
F_12 ( F_13 ( V_9 ) ) ;
}
static void F_95 ( struct V_8 * V_9 )
{
F_3 ( F_11 ( V_9 ) ) ;
if ( V_9 -> V_87 == NULL )
return;
F_96 ( V_9 -> V_87 ) ;
V_9 -> V_87 = NULL ;
}
int F_13 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
unsigned long V_2 ;
int V_75 ;
F_44 ( & V_12 -> V_32 . V_68 -> V_69 ) ;
V_2 = F_97 ( V_9 ) ;
if ( V_2 ) {
int V_5 ;
F_57 ( V_9 ) ;
F_98 (active, idx) {
V_75 = F_99 ( & V_9 -> V_10 [ V_5 ] ,
& V_9 -> V_15 -> V_20 -> V_86 . V_69 ) ;
if ( V_75 )
break;
}
if ( ! V_75 ) {
V_75 = F_99 ( & V_9 -> V_36 ,
& V_9 -> V_15 -> V_20 -> V_86 . V_69 ) ;
}
F_86 ( V_9 ) ;
if ( V_75 )
return V_75 ;
F_3 ( F_6 ( V_9 ) ) ;
}
if ( F_11 ( V_9 ) )
return - V_114 ;
if ( ! F_7 ( & V_9 -> V_13 ) )
goto V_129;
F_3 ( V_12 -> V_18 == 0 ) ;
F_3 ( ! F_100 ( V_12 ) ) ;
if ( F_52 ( V_9 ) ) {
V_75 = F_101 ( V_9 ) ;
if ( V_75 )
return V_75 ;
F_102 ( V_12 ) ;
F_95 ( V_9 ) ;
V_9 -> V_56 &= ~ V_97 ;
}
if ( F_103 ( ! V_9 -> V_15 -> V_70 ) ) {
F_104 ( V_9 ) ;
V_9 -> V_15 -> V_130 ( V_9 ) ;
}
V_9 -> V_56 &= ~ ( V_80 | V_82 ) ;
if ( V_9 -> V_117 != V_12 -> V_21 . V_117 ) {
F_3 ( ! V_9 -> V_117 ) ;
F_105 ( V_9 -> V_117 ) ;
F_106 ( V_9 -> V_117 ) ;
}
V_9 -> V_117 = NULL ;
F_82 ( V_9 ) ;
V_129:
if ( F_9 ( F_10 ( V_9 ) ) )
F_87 ( V_9 ) ;
return 0 ;
}
