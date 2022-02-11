void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
if ( V_2 -> V_9 . V_10 == 1 )
return;
if ( V_7 -> V_11 != V_12 ||
V_7 -> V_13 != V_14 ) {
F_2 ( V_15 , L_1 ) ;
F_2 ( V_15 , L_2 ,
V_7 -> V_11 , V_7 -> V_13 ) ;
return;
}
F_3 ( & V_4 -> V_16 ) ;
V_4 -> V_17 = true ;
V_4 -> V_18 = V_4 -> V_19 ;
V_4 -> V_20 ++ ;
F_4 ( L_3 , V_4 -> V_20 ) ;
if ( V_21 == V_4 -> V_22 ) {
V_4 -> V_23 = true ;
F_2 ( V_15 , L_4 ) ;
if ( V_4 -> V_18 == V_24 )
V_4 -> V_25 = true ;
F_5 ( V_2 ) ;
V_4 -> V_26 = V_21 ;
}
V_4 -> V_17 = false ;
F_6 ( & V_4 -> V_16 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_28 = & ( V_2 -> V_29 ) ;
struct V_30 * V_31 = & ( V_2 -> V_32 ) ;
int V_33 = V_34 ;
int V_35 ;
F_3 ( & V_4 -> V_16 ) ;
if ( ( V_4 -> V_26 == V_21 ) && ( ! V_4 -> V_17 ) ) {
V_4 -> V_17 = true ;
V_4 -> V_22 = V_36 ;
V_4 -> V_37 ++ ;
F_4 ( L_5 , V_4 -> V_37 ) ;
V_33 = F_8 ( V_2 ) ;
if ( V_33 == V_34 ) {
V_4 -> V_26 = V_36 ;
}
F_2 ( V_15 , L_6 ) ;
if ( ( V_38 == V_28 -> V_39 ) || ( V_40 == V_28 -> V_39 ) ) {
F_4 ( L_7 , V_41 , V_2 -> V_42 . V_43 , V_4 -> V_17 ) ;
F_9 ( V_2 , V_2 -> V_42 . V_43 , V_44 , V_45 ) ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
if ( V_31 -> V_46 & F_10 ( V_35 ) ) {
if ( V_35 == V_28 -> V_47 )
V_33 = F_11 ( V_2 , V_28 , V_35 , 1 ) ;
else
V_33 = F_11 ( V_2 , V_28 , V_35 , 0 ) ;
}
}
}
F_4 ( L_8 , F_12 ( V_2 , 0x4c ) ) ;
V_4 -> V_17 = false ;
V_4 -> V_25 = false ;
V_4 -> V_23 = false ;
}
F_6 ( & V_4 -> V_16 ) ;
return V_33 ;
}
static bool F_13 ( struct V_1 * V_1 )
{
struct V_1 * V_48 = V_1 -> V_49 ;
struct V_30 * V_31 = & ( V_1 -> V_32 ) ;
#ifdef F_14
struct V_50 * V_51 = & ( V_1 -> V_52 ) ;
#endif
bool V_53 = false ;
if ( V_1 -> V_5 . V_54 >= V_55 )
goto exit;
if ( F_15 ( V_31 , V_56 | V_57 ) ||
F_15 ( V_31 , V_58 | V_59 ) ||
F_15 ( V_31 , V_60 ) ||
F_15 ( V_31 , V_61 | V_62 ) ||
#if F_16 ( F_14 )
! F_17 ( V_51 , V_63 ) )
#else
0 )
#endif
goto exit;
static void F_18 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
F_19 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_65 )
{
T_1 V_66 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
V_67 ;
V_65 = F_21 ( V_65 ) ;
if ( V_4 -> V_68 ) {
if ( V_65 < V_69 )
V_65 = V_70 ;
}
if ( ( V_4 -> V_66 == V_65 ) ) {
F_22 ( V_71 , V_72 ,
( L_9 , V_41 , V_4 -> V_66 , V_65 ) ) ;
return;
}
if ( ( V_2 -> V_73 ) ||
( ! V_2 -> V_74 ) ) {
F_22 ( V_71 , V_72 ,
( L_10 ,
V_41 , V_2 -> V_73 , V_2 -> V_74 ) ) ;
V_4 -> V_75 = V_69 ;
return;
}
if ( V_2 -> V_76 ) {
F_22 ( V_71 , V_72 ,
( L_11 , V_41 , V_65 ) ) ;
if ( V_65 < V_77 ) {
F_22 ( V_71 , V_72 ,
( L_12 , V_41 , V_65 ) ) ;
return;
}
}
V_66 = V_65 | V_4 -> V_78 ;
F_22 ( V_71 , V_79 ,
( L_13 , V_66 , V_4 -> V_75 ) ) ;
V_4 -> V_66 = V_65 ;
F_23 ( V_2 , V_80 , ( T_1 * ) ( & V_66 ) ) ;
V_4 -> V_78 += 0x80 ;
V_4 -> V_75 = V_65 ;
V_81 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_2 V_82 , V_83 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & ( V_2 -> V_32 ) ;
V_82 = V_55 ;
V_83 = V_82 - V_4 -> V_84 ;
if ( V_83 < V_85 )
return false ;
if ( ( F_15 ( V_31 , V_86 ) == false ) ||
( F_15 ( V_31 , V_87 ) ) ||
( F_15 ( V_31 , V_60 ) ) ||
( F_15 ( V_31 , V_61 ) ) ||
( F_15 ( V_31 , V_62 ) ) )
return false ;
if ( V_4 -> V_88 )
return false ;
if ( ( V_2 -> V_29 . V_89 == V_90 ) && ( V_2 -> V_29 . V_91 == false ) ) {
F_4 ( L_14 ) ;
return false ;
}
return true ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_92 , T_1 V_93 , T_1 V_94 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
#ifdef F_14
struct V_50 * V_51 = & ( V_2 -> V_52 ) ;
#endif
V_67 ;
F_22 ( V_71 , V_79 ,
( L_15 ,
V_41 , V_92 , V_93 ) ) ;
if ( V_92 > V_95 ) {
F_22 ( V_71 , V_72 , ( L_16 , V_92 ) ) ;
return;
}
if ( V_4 -> V_96 == V_92 ) {
if ( V_97 == V_92 )
return;
if ( ( V_4 -> V_93 == V_93 ) &&
( V_4 -> V_94 == V_94 ) )
return;
}
if ( V_92 == V_97 ) {
#ifdef F_14
if ( V_51 -> V_98 == 0 ) {
F_4 ( L_17 ) ;
V_4 -> V_96 = V_92 ;
F_20 ( V_2 , V_69 ) ;
F_23 ( V_2 , V_99 , ( T_1 * ) ( & V_92 ) ) ;
V_4 -> V_100 = false ;
}
} else {
#endif
if ( F_24 ( V_2 ) ) {
F_4 ( L_18 , V_41 ) ;
V_4 -> V_100 = true ;
V_4 -> V_96 = V_92 ;
V_4 -> V_93 = V_93 ;
V_4 -> V_94 = V_94 ;
F_23 ( V_2 , V_99 , ( T_1 * ) ( & V_92 ) ) ;
#ifdef F_14
if ( V_51 -> V_98 == 1 )
F_26 ( V_2 , V_101 , 0 ) ;
#endif
F_20 ( V_2 , V_77 ) ;
}
}
V_81 ;
}
T_3 F_27 ( struct V_1 * V_2 , T_2 V_102 )
{
T_2 V_103 ;
T_1 V_104 = false ;
T_3 V_105 = 0 ;
V_103 = V_55 ;
while ( 1 ) {
F_28 ( V_2 , V_106 , & V_104 ) ;
if ( V_104 )
break;
if ( V_2 -> V_73 ) {
V_105 = - 2 ;
F_4 ( L_19 , V_41 ) ;
break;
}
if ( F_29 ( V_103 ) > V_102 ) {
V_105 = - 1 ;
F_4 ( L_20 , V_41 , V_102 ) ;
break;
}
F_30 ( 1 ) ;
}
return V_105 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_67 ;
if ( F_24 ( V_2 ) == false )
return;
if ( V_4 -> V_107 ) {
if ( V_4 -> V_108 >= 2 ) {
if ( V_4 -> V_96 == V_97 ) {
V_4 -> V_23 = true ;
F_4 ( L_21 , V_41 , V_4 -> V_93 ) ;
F_25 ( V_2 , V_4 -> V_109 , V_4 -> V_93 , 0 ) ;
}
} else {
V_4 -> V_108 ++ ;
}
}
V_81 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_67 ;
if ( V_4 -> V_107 ) {
if ( V_4 -> V_96 != V_97 ) {
F_25 ( V_2 , V_97 , 0 , 0 ) ;
if ( V_4 -> V_96 == V_97 )
F_27 ( V_2 , V_110 ) ;
}
}
V_4 -> V_23 = false ;
V_81 ;
}
void F_33 ( struct V_1 * V_111 )
{
struct V_30 * V_31 = & ( V_111 -> V_32 ) ;
T_1 V_112 = 0 ;
V_67 ;
if ( F_15 ( V_31 , V_86 ) ) {
F_26 ( V_111 , V_113 , V_112 ) ;
F_34 ( V_111 , V_114 , V_112 ) ;
}
V_81 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
V_67 ;
F_36 ( & V_5 -> V_16 ) ;
V_5 -> V_26 = V_36 ;
V_5 -> V_20 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_17 = false ;
V_5 -> V_18 = V_2 -> V_9 . V_18 ;
V_5 -> V_19 = V_2 -> V_9 . V_18 ;
V_5 -> V_115 = V_116 ;
V_5 -> V_117 = 0 ;
V_5 -> V_118 = false ;
V_5 -> V_88 = false ;
V_5 -> V_25 = false ;
V_5 -> V_108 = 0 ;
if ( V_2 -> V_9 . V_10 == 1 )
V_5 -> V_109 = V_97 ;
else
V_5 -> V_109 = V_2 -> V_9 . V_109 ;
V_5 -> V_107 = ( V_97 != V_5 -> V_109 ) ? true : false ;
V_5 -> V_100 = false ;
V_5 -> V_66 = 0 ;
V_5 -> V_75 = V_69 ;
V_5 -> V_96 = V_97 ;
V_5 -> V_93 = V_2 -> V_9 . V_93 ;
V_5 -> V_94 = 0 ;
V_5 -> V_78 = 0x80 ;
V_5 -> V_68 = false ;
F_37 ( & ( V_5 -> V_119 ) , V_2 -> V_120 , F_18 , ( T_1 * ) V_2 ) ;
V_81 ;
}
T_1 F_38 ( struct V_1 * V_2 , enum V_121 V_122 , T_1 * V_123 )
{
T_1 V_124 = true ;
F_39 ( V_2 , V_122 , V_123 ) ;
return V_124 ;
}
inline void F_40 ( struct V_1 * V_2 , T_2 V_125 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_4 -> V_54 = V_55 + F_41 ( V_125 ) ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_126 , const char * V_127 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & V_2 -> V_32 ;
int V_53 = V_34 ;
if ( V_4 -> V_54 < V_55 + F_41 ( V_126 ) )
V_4 -> V_54 = V_55 + F_41 ( V_126 ) ;
{
T_2 V_128 = V_55 ;
if ( V_4 -> V_129 ) {
F_4 ( L_22 , V_41 ) ;
while ( V_4 -> V_129 && F_29 ( V_128 ) <= 3000 )
F_30 ( 10 ) ;
if ( V_4 -> V_129 )
F_4 ( L_23 , V_41 ) ;
else
F_4 ( L_24 , V_41 ) ;
}
}
if ( ( ! V_4 -> V_118 ) && ( V_4 -> V_88 ) ) {
V_53 = V_130 ;
goto exit;
}
if ( ( V_4 -> V_118 ) && ( V_2 -> V_131 ) ) {
V_53 = V_130 ;
goto exit;
}
if ( F_15 ( V_31 , V_86 ) ) {
V_53 = V_34 ;
goto exit;
}
if ( V_21 == V_4 -> V_26 ) {
F_4 ( L_25 , V_41 ) ;
if ( V_130 == F_7 ( V_2 ) ) {
F_4 ( L_26 ) ;
V_53 = V_130 ;
goto exit;
}
}
if ( V_2 -> V_76 || ! V_2 -> V_132 ||
! V_2 -> V_74 ) {
F_4 ( L_27
, V_127
, V_2 -> V_76
, V_2 -> V_132
, V_2 -> V_74 ) ;
V_53 = false ;
goto exit;
}
exit:
if ( V_4 -> V_54 < V_55 + F_41 ( V_126 ) )
V_4 -> V_54 = V_55 + F_41 ( V_126 ) ;
return V_53 ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_133 )
{
int V_53 = 0 ;
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_133 < V_134 ) {
if ( V_5 -> V_109 != V_133 ) {
if ( V_97 == V_133 )
F_33 ( V_2 ) ;
else
V_5 -> V_108 = 2 ;
V_5 -> V_109 = V_133 ;
V_5 -> V_107 = ( V_97 != V_5 -> V_109 ) ? true : false ;
}
} else {
V_53 = - V_135 ;
}
return V_53 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_133 == V_136 || V_133 == V_24 ) {
F_45 ( V_5 , V_133 ) ;
F_4 ( L_28 , V_41 , V_133 == V_136 ? L_29 : L_30 ) ;
return 0 ;
} else if ( V_133 == V_137 ) {
F_45 ( V_5 , V_133 ) ;
F_4 ( L_28 , V_41 , L_31 ) ;
if ( ( V_2 -> V_73 == 0 ) && ( V_130 == F_46 ( V_2 ) ) )
return - V_138 ;
} else {
return - V_135 ;
}
return 0 ;
}
