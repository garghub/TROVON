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
F_7 ( & V_9 -> V_13 , & V_9 -> V_14 -> V_15 ) ;
if ( F_8 ( F_9 ( V_9 ) && ! F_10 ( V_9 ) ) )
F_11 ( F_12 ( V_9 ) ) ;
F_3 ( ! F_13 ( V_12 ) ) ;
if ( -- V_12 -> V_16 )
return;
if ( V_12 -> V_17 )
F_7 ( & V_12 -> V_18 , & V_4 -> V_19 -> V_20 . V_21 ) ;
V_12 -> V_20 . V_22 = true ;
if ( F_14 ( V_12 ) ) {
F_15 ( V_12 ) ;
F_16 ( V_12 ) ;
}
}
static struct V_8 *
F_17 ( struct V_11 * V_12 ,
struct V_23 * V_14 ,
const struct V_24 * V_25 )
{
struct V_8 * V_9 ;
struct V_26 * V_27 , * * V_28 ;
int V_29 ;
F_3 ( V_14 -> V_30 ) ;
V_9 = F_18 ( F_19 ( V_12 -> V_31 . V_32 ) -> V_33 , V_34 ) ;
if ( V_9 == NULL )
return F_20 ( - V_35 ) ;
F_21 ( & V_9 -> V_36 ) ;
for ( V_29 = 0 ; V_29 < F_22 ( V_9 -> V_10 ) ; V_29 ++ )
F_23 ( & V_9 -> V_10 [ V_29 ] , F_1 ) ;
F_23 ( & V_9 -> V_37 , NULL ) ;
F_24 ( & V_9 -> V_13 , & V_14 -> V_38 ) ;
V_9 -> V_14 = V_14 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_39 = V_12 -> V_31 . V_39 ;
if ( V_25 ) {
V_9 -> V_40 = * V_25 ;
if ( V_25 -> type == V_41 ) {
V_9 -> V_39 = V_25 -> V_42 . V_43 . V_39 ;
V_9 -> V_39 <<= V_44 ;
} else if ( V_25 -> type == V_45 ) {
V_9 -> V_39 =
F_25 ( & V_25 -> V_42 . V_46 ) ;
V_9 -> V_39 <<= V_44 ;
}
}
if ( F_26 ( V_14 ) ) {
V_9 -> V_47 |= V_48 ;
F_24 ( & V_9 -> V_49 , & V_12 -> V_50 ) ;
} else {
F_27 ( F_28 ( V_14 ) ) ;
F_29 ( & V_9 -> V_49 , & V_12 -> V_50 ) ;
}
V_27 = NULL ;
V_28 = & V_12 -> V_51 . V_26 ;
while ( * V_28 ) {
struct V_8 * V_52 ;
V_27 = * V_28 ;
V_52 = F_30 ( V_27 , struct V_8 , V_53 ) ;
if ( F_31 ( V_52 , V_14 , V_25 ) < 0 )
V_28 = & V_27 -> V_54 ;
else
V_28 = & V_27 -> V_55 ;
}
F_32 ( & V_9 -> V_53 , V_27 , V_28 ) ;
F_33 ( & V_9 -> V_53 , & V_12 -> V_51 ) ;
return V_9 ;
}
struct V_8 *
F_34 ( struct V_11 * V_12 ,
struct V_23 * V_14 ,
const struct V_24 * V_25 )
{
F_35 ( & V_12 -> V_31 . V_32 -> V_56 ) ;
F_3 ( V_25 && ! F_26 ( V_14 ) ) ;
F_3 ( F_36 ( V_12 , V_14 , V_25 ) ) ;
return F_17 ( V_12 , V_14 , V_25 ) ;
}
int F_37 ( struct V_8 * V_9 , enum V_57 V_58 ,
T_1 V_47 )
{
T_1 V_59 ;
T_1 V_60 ;
int V_61 ;
if ( F_11 ( V_47 == 0 ) )
return - V_62 ;
V_59 = 0 ;
if ( V_47 & V_63 )
V_59 |= V_64 ;
if ( V_47 & V_65 )
V_59 |= V_66 ;
V_60 = V_9 -> V_47 & ( V_64 | V_66 ) ;
if ( V_47 & V_67 )
V_59 |= V_60 ;
else
V_59 &= ~ V_60 ;
if ( V_59 == 0 )
return 0 ;
if ( V_60 == 0 && V_9 -> V_14 -> V_68 ) {
F_38 ( V_9 ) ;
V_61 = V_9 -> V_14 -> V_68 ( V_9 -> V_14 ,
V_9 -> V_69 . V_70 ,
V_9 -> V_69 . V_39 ) ;
if ( V_61 )
return V_61 ;
}
F_39 ( V_9 , V_59 ) ;
V_61 = V_9 -> V_14 -> V_71 ( V_9 , V_58 , V_59 ) ;
if ( V_61 )
return V_61 ;
V_9 -> V_47 |= V_59 ;
return 0 ;
}
void T_2 * F_40 ( struct V_8 * V_9 )
{
void T_2 * V_72 ;
F_41 ( F_19 ( V_9 -> V_14 -> V_32 ) ) ;
F_35 ( & V_9 -> V_14 -> V_32 -> V_56 ) ;
if ( F_11 ( ! F_42 ( V_9 ) ) )
return F_43 ( - V_73 ) ;
F_3 ( ! F_44 ( V_9 ) ) ;
F_3 ( ( V_9 -> V_47 & V_64 ) == 0 ) ;
V_72 = V_9 -> V_74 ;
if ( V_72 == NULL ) {
V_72 = F_45 ( & F_46 ( V_9 -> V_14 ) -> V_75 ,
V_9 -> V_69 . V_70 ,
V_9 -> V_69 . V_39 ) ;
if ( V_72 == NULL )
return F_43 ( - V_35 ) ;
V_9 -> V_74 = V_72 ;
}
F_47 ( V_9 ) ;
return V_72 ;
}
void F_48 ( struct V_8 * * V_76 )
{
struct V_8 * V_9 ;
struct V_11 * V_12 ;
V_9 = F_49 ( V_76 ) ;
if ( ! V_9 )
return;
V_12 = V_9 -> V_12 ;
F_50 ( V_9 ) ;
F_51 ( V_9 ) ;
F_52 ( V_12 ) ;
}
bool
F_53 ( struct V_8 * V_9 , T_3 V_39 , T_3 V_77 , T_3 V_47 )
{
if ( ! F_54 ( & V_9 -> V_69 ) )
return false ;
if ( V_9 -> V_69 . V_39 < V_39 )
return true ;
if ( V_77 && V_9 -> V_69 . V_70 & ( V_77 - 1 ) )
return true ;
if ( V_47 & V_78 && ! F_42 ( V_9 ) )
return true ;
if ( V_47 & V_79 &&
V_9 -> V_69 . V_70 < ( V_47 & V_80 ) )
return true ;
if ( V_47 & V_81 &&
V_9 -> V_69 . V_70 != ( V_47 & V_80 ) )
return true ;
return false ;
}
void F_55 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_82 * V_83 = F_19 ( V_12 -> V_31 . V_32 ) ;
bool V_75 , V_84 ;
T_1 V_85 , V_86 ;
V_85 = F_56 ( V_83 ,
V_9 -> V_39 ,
F_57 ( V_12 ) ) ;
V_86 = F_58 ( V_83 ,
V_9 -> V_39 ,
F_57 ( V_12 ) ,
true ) ;
V_84 = ( V_9 -> V_69 . V_39 == V_85 &&
( V_9 -> V_69 . V_70 & ( V_86 - 1 ) ) == 0 ) ;
V_75 = ( V_9 -> V_69 . V_70 + V_85 <=
V_83 -> V_87 . V_88 ) ;
if ( V_75 && V_84 &&
V_9 -> V_40 . type != V_45 )
V_9 -> V_47 |= V_89 ;
else
V_9 -> V_47 &= ~ V_89 ;
}
bool F_59 ( struct V_8 * V_9 ,
unsigned long V_58 )
{
struct V_90 * V_91 = & V_9 -> V_69 ;
struct V_90 * V_92 ;
if ( V_9 -> V_14 -> V_20 . V_93 == NULL )
return true ;
if ( ! F_54 ( V_91 ) )
return true ;
if ( F_60 ( & V_91 -> V_94 ) )
return true ;
V_92 = F_61 ( V_91 -> V_94 . V_95 , struct V_90 , V_94 ) ;
if ( V_92 -> V_96 && ! V_92 -> V_97 && V_92 -> V_98 != V_58 )
return false ;
V_92 = F_61 ( V_91 -> V_94 . V_99 , struct V_90 , V_94 ) ;
if ( V_92 -> V_96 && ! V_91 -> V_97 && V_92 -> V_98 != V_58 )
return false ;
return true ;
}
static int
F_62 ( struct V_8 * V_9 , T_3 V_39 , T_3 V_77 , T_3 V_47 )
{
struct V_82 * V_83 = F_19 ( V_9 -> V_14 -> V_32 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
T_3 V_70 , V_100 ;
int V_61 ;
F_3 ( V_9 -> V_47 & ( V_64 | V_66 ) ) ;
F_3 ( F_54 ( & V_9 -> V_69 ) ) ;
V_39 = F_63 ( V_39 , V_9 -> V_39 ) ;
if ( V_47 & V_78 )
V_39 = F_56 ( V_83 , V_39 ,
F_57 ( V_12 ) ) ;
V_77 = F_63 ( F_63 ( V_77 , V_9 -> V_101 ) ,
F_58 ( V_83 , V_39 ,
F_57 ( V_12 ) ,
V_47 & V_78 ) ) ;
V_70 = V_47 & V_79 ? V_47 & V_80 : 0 ;
V_100 = V_9 -> V_14 -> V_102 ;
if ( V_47 & V_78 )
V_100 = F_64 ( T_3 , V_100 , V_83 -> V_87 . V_88 ) ;
if ( V_47 & V_103 )
V_100 = F_64 ( T_3 , V_100 , ( 1ULL << 32 ) - V_104 ) ;
if ( V_39 > V_100 ) {
F_65 ( L_1 ,
V_39 , V_12 -> V_31 . V_39 ,
V_47 & V_78 ? L_2 : L_3 ,
V_100 ) ;
return - V_105 ;
}
V_61 = F_66 ( V_12 ) ;
if ( V_61 )
return V_61 ;
if ( V_47 & V_81 ) {
T_3 V_106 = V_47 & V_80 ;
if ( V_106 & ( V_77 - 1 ) || V_106 > V_100 - V_39 ) {
V_61 = - V_62 ;
goto V_107;
}
V_9 -> V_69 . V_70 = V_106 ;
V_9 -> V_69 . V_39 = V_39 ;
V_9 -> V_69 . V_98 = V_12 -> V_58 ;
V_61 = F_67 ( & V_9 -> V_14 -> V_20 , & V_9 -> V_69 ) ;
if ( V_61 ) {
V_61 = F_68 ( V_9 ) ;
if ( V_61 == 0 )
V_61 = F_67 ( & V_9 -> V_14 -> V_20 , & V_9 -> V_69 ) ;
if ( V_61 )
goto V_107;
}
} else {
T_1 V_108 , V_109 ;
if ( V_47 & V_110 ) {
V_108 = V_111 ;
V_109 = V_112 ;
} else {
V_108 = V_113 ;
V_109 = V_114 ;
}
if ( V_77 <= 4096 )
V_77 = 0 ;
V_115:
V_61 = F_69 ( & V_9 -> V_14 -> V_20 ,
& V_9 -> V_69 ,
V_39 , V_77 ,
V_12 -> V_58 ,
V_70 , V_100 ,
V_108 ,
V_109 ) ;
if ( V_61 ) {
V_61 = F_70 ( V_9 -> V_14 , V_39 , V_77 ,
V_12 -> V_58 ,
V_70 , V_100 ,
V_47 ) ;
if ( V_61 == 0 )
goto V_115;
goto V_107;
}
F_3 ( V_9 -> V_69 . V_70 < V_70 ) ;
F_3 ( V_9 -> V_69 . V_70 + V_9 -> V_69 . V_39 > V_100 ) ;
}
F_3 ( ! F_59 ( V_9 , V_12 -> V_58 ) ) ;
F_7 ( & V_12 -> V_18 , & V_83 -> V_20 . V_21 ) ;
F_7 ( & V_9 -> V_13 , & V_9 -> V_14 -> V_15 ) ;
V_12 -> V_17 ++ ;
F_3 ( F_71 ( & V_12 -> V_20 . V_116 ) < V_12 -> V_17 ) ;
return 0 ;
V_107:
F_72 ( V_12 ) ;
return V_61 ;
}
int F_73 ( struct V_8 * V_9 ,
T_3 V_39 , T_3 V_77 , T_3 V_47 )
{
unsigned int V_117 = V_9 -> V_47 ;
int V_61 ;
F_35 ( & V_9 -> V_14 -> V_32 -> V_56 ) ;
F_3 ( ( V_47 & ( V_63 | V_65 ) ) == 0 ) ;
F_3 ( ( V_47 & V_63 ) && ! F_44 ( V_9 ) ) ;
if ( F_11 ( V_117 & V_118 ) ) {
V_61 = - V_119 ;
goto V_120;
}
if ( ( V_117 & V_121 ) == 0 ) {
V_61 = F_62 ( V_9 , V_39 , V_77 , V_47 ) ;
if ( V_61 )
goto V_120;
}
V_61 = F_37 ( V_9 , V_9 -> V_12 -> V_58 , V_47 ) ;
if ( V_61 )
goto V_120;
if ( ( V_117 ^ V_9 -> V_47 ) & V_64 )
F_55 ( V_9 ) ;
F_3 ( F_53 ( V_9 , V_39 , V_77 , V_47 ) ) ;
return 0 ;
V_120:
F_74 ( V_9 ) ;
return V_61 ;
}
void F_75 ( struct V_8 * V_9 )
{
F_3 ( V_9 -> V_69 . V_96 ) ;
F_3 ( F_6 ( V_9 ) ) ;
F_3 ( ! F_9 ( V_9 ) ) ;
F_3 ( V_9 -> V_122 ) ;
F_76 ( & V_9 -> V_13 ) ;
if ( ! F_44 ( V_9 ) )
F_77 ( F_28 ( V_9 -> V_14 ) ) ;
F_78 ( F_19 ( V_9 -> V_12 -> V_31 . V_32 ) -> V_33 , V_9 ) ;
}
void F_51 ( struct V_8 * V_9 )
{
F_3 ( F_9 ( V_9 ) ) ;
V_9 -> V_47 |= V_123 ;
F_76 ( & V_9 -> V_49 ) ;
F_79 ( & V_9 -> V_53 , & V_9 -> V_12 -> V_51 ) ;
if ( ! F_6 ( V_9 ) && ! F_10 ( V_9 ) )
F_11 ( F_12 ( V_9 ) ) ;
}
static void F_80 ( struct V_8 * V_9 )
{
F_3 ( F_10 ( V_9 ) ) ;
if ( V_9 -> V_74 == NULL )
return;
F_81 ( V_9 -> V_74 ) ;
V_9 -> V_74 = NULL ;
}
int F_12 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
unsigned long V_2 ;
int V_61 ;
F_35 ( & V_12 -> V_31 . V_32 -> V_56 ) ;
V_2 = F_82 ( V_9 ) ;
if ( V_2 ) {
int V_5 ;
F_47 ( V_9 ) ;
F_83 (active, idx) {
V_61 = F_84 ( & V_9 -> V_10 [ V_5 ] ,
& V_9 -> V_14 -> V_32 -> V_56 ) ;
if ( V_61 )
break;
}
F_74 ( V_9 ) ;
if ( V_61 )
return V_61 ;
F_3 ( F_6 ( V_9 ) ) ;
}
if ( F_10 ( V_9 ) )
return - V_119 ;
if ( ! F_54 ( & V_9 -> V_69 ) )
goto V_124;
F_3 ( V_12 -> V_17 == 0 ) ;
F_3 ( ! F_85 ( V_12 ) ) ;
if ( F_42 ( V_9 ) ) {
V_61 = F_86 ( V_9 ) ;
if ( V_61 )
return V_61 ;
F_87 ( V_12 ) ;
F_80 ( V_9 ) ;
V_9 -> V_47 &= ~ V_89 ;
}
if ( F_88 ( ! V_9 -> V_14 -> V_30 ) ) {
F_89 ( V_9 ) ;
V_9 -> V_14 -> V_125 ( V_9 ) ;
}
V_9 -> V_47 &= ~ ( V_64 | V_66 ) ;
F_90 ( & V_9 -> V_69 ) ;
F_7 ( & V_9 -> V_13 , & V_9 -> V_14 -> V_38 ) ;
if ( V_9 -> V_126 != V_12 -> V_20 . V_126 ) {
F_3 ( ! V_9 -> V_126 ) ;
F_91 ( V_9 -> V_126 ) ;
F_92 ( V_9 -> V_126 ) ;
}
V_9 -> V_126 = NULL ;
if ( -- V_12 -> V_17 == 0 )
F_7 ( & V_12 -> V_18 ,
& F_19 ( V_12 -> V_31 . V_32 ) -> V_20 . V_38 ) ;
F_72 ( V_12 ) ;
V_124:
if ( F_8 ( F_9 ( V_9 ) ) )
F_75 ( V_9 ) ;
return 0 ;
}
