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
if ( V_1 -> V_5 . V_54 >= F_15 () )
goto exit;
if ( F_16 ( V_31 , V_55 | V_56 ) ||
F_16 ( V_31 , V_57 | V_58 ) ||
F_16 ( V_31 , V_59 ) ||
F_16 ( V_31 , V_60 | V_61 ) ||
#if F_17 ( F_14 )
! F_18 ( V_51 , V_62 ) )
#else
0 )
#endif
goto exit;
static void F_19 ( void * V_63 )
{
struct V_1 * V_2 = (struct V_1 * ) V_63 ;
F_20 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 , T_1 V_64 )
{
T_1 V_65 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
V_66 ;
V_64 = F_22 ( V_64 ) ;
if ( V_4 -> V_67 ) {
if ( V_64 < V_68 )
V_64 = V_69 ;
}
if ( ( V_4 -> V_65 == V_64 ) ) {
F_23 ( V_70 , V_71 ,
( L_9 , V_41 , V_4 -> V_65 , V_64 ) ) ;
return;
}
if ( ( V_2 -> V_72 ) ||
( ! V_2 -> V_73 ) ) {
F_23 ( V_70 , V_71 ,
( L_10 ,
V_41 , V_2 -> V_72 , V_2 -> V_73 ) ) ;
V_4 -> V_74 = V_68 ;
return;
}
if ( V_2 -> V_75 ) {
F_23 ( V_70 , V_71 ,
( L_11 , V_41 , V_64 ) ) ;
if ( V_64 < V_76 ) {
F_23 ( V_70 , V_71 ,
( L_12 , V_41 , V_64 ) ) ;
return;
}
}
V_65 = V_64 | V_4 -> V_77 ;
F_23 ( V_70 , V_78 ,
( L_13 , V_65 , V_4 -> V_74 ) ) ;
V_4 -> V_65 = V_64 ;
F_24 ( V_2 , V_79 , ( T_1 * ) ( & V_65 ) ) ;
V_4 -> V_77 += 0x80 ;
V_4 -> V_74 = V_64 ;
V_80 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_2 V_81 , V_82 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & ( V_2 -> V_32 ) ;
V_81 = F_15 () ;
V_82 = V_81 - V_4 -> V_83 ;
if ( V_82 < V_84 )
return false ;
if ( ( F_16 ( V_31 , V_85 ) == false ) ||
( F_16 ( V_31 , V_86 ) ) ||
( F_16 ( V_31 , V_59 ) ) ||
( F_16 ( V_31 , V_60 ) ) ||
( F_16 ( V_31 , V_61 ) ) )
return false ;
if ( V_4 -> V_87 )
return false ;
if ( ( V_2 -> V_29 . V_88 == V_89 ) && ( V_2 -> V_29 . V_90 == false ) ) {
F_4 ( L_14 ) ;
return false ;
}
return true ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_91 , T_1 V_92 , T_1 V_93 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
#ifdef F_14
struct V_50 * V_51 = & ( V_2 -> V_52 ) ;
#endif
V_66 ;
F_23 ( V_70 , V_78 ,
( L_15 ,
V_41 , V_91 , V_92 ) ) ;
if ( V_91 > V_94 ) {
F_23 ( V_70 , V_71 , ( L_16 , V_91 ) ) ;
return;
}
if ( V_4 -> V_95 == V_91 ) {
if ( V_96 == V_91 )
return;
if ( ( V_4 -> V_92 == V_92 ) &&
( V_4 -> V_93 == V_93 ) )
return;
}
if ( V_91 == V_96 ) {
#ifdef F_14
if ( V_51 -> V_97 == 0 ) {
F_4 ( L_17 ) ;
V_4 -> V_95 = V_91 ;
F_21 ( V_2 , V_68 ) ;
F_24 ( V_2 , V_98 , ( T_1 * ) ( & V_91 ) ) ;
V_4 -> V_99 = false ;
}
} else {
#endif
if ( F_25 ( V_2 ) ) {
F_4 ( L_18 , V_41 ) ;
V_4 -> V_99 = true ;
V_4 -> V_95 = V_91 ;
V_4 -> V_92 = V_92 ;
V_4 -> V_93 = V_93 ;
F_24 ( V_2 , V_98 , ( T_1 * ) ( & V_91 ) ) ;
#ifdef F_14
if ( V_51 -> V_97 == 1 )
F_27 ( V_2 , V_100 , 0 ) ;
#endif
F_21 ( V_2 , V_76 ) ;
}
}
V_80 ;
}
T_3 F_28 ( struct V_1 * V_2 , T_2 V_101 )
{
T_2 V_102 ;
T_1 V_103 = false ;
T_3 V_104 = 0 ;
V_102 = F_15 () ;
while ( 1 ) {
F_29 ( V_2 , V_105 , & V_103 ) ;
if ( V_103 )
break;
if ( V_2 -> V_72 ) {
V_104 = - 2 ;
F_4 ( L_19 , V_41 ) ;
break;
}
if ( F_30 ( V_102 ) > V_101 ) {
V_104 = - 1 ;
F_4 ( L_20 , V_41 , V_101 ) ;
break;
}
F_31 ( 100 ) ;
}
return V_104 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_66 ;
if ( F_25 ( V_2 ) == false )
return;
if ( V_4 -> V_106 ) {
if ( V_4 -> V_107 >= 2 ) {
if ( V_4 -> V_95 == V_96 ) {
V_4 -> V_23 = true ;
F_4 ( L_21 , V_41 , V_4 -> V_92 ) ;
F_26 ( V_2 , V_4 -> V_108 , V_4 -> V_92 , 0 ) ;
}
} else {
V_4 -> V_107 ++ ;
}
}
V_80 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_66 ;
if ( V_4 -> V_106 ) {
if ( V_4 -> V_95 != V_96 ) {
F_26 ( V_2 , V_96 , 0 , 0 ) ;
if ( V_4 -> V_95 == V_96 )
F_28 ( V_2 , V_109 ) ;
}
}
V_4 -> V_23 = false ;
V_80 ;
}
void F_34 ( struct V_1 * V_110 )
{
struct V_30 * V_31 = & ( V_110 -> V_32 ) ;
T_1 V_111 = 0 ;
V_66 ;
if ( F_16 ( V_31 , V_85 ) ) {
F_27 ( V_110 , V_112 , V_111 ) ;
F_35 ( V_110 , V_113 , V_111 ) ;
}
V_80 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
V_66 ;
F_37 ( & V_5 -> V_16 ) ;
V_5 -> V_26 = V_36 ;
V_5 -> V_20 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_17 = false ;
V_5 -> V_18 = V_2 -> V_9 . V_18 ;
V_5 -> V_19 = V_2 -> V_9 . V_18 ;
V_5 -> V_114 = V_115 ;
V_5 -> V_116 = 0 ;
V_5 -> V_117 = false ;
V_5 -> V_87 = false ;
V_5 -> V_25 = false ;
V_5 -> V_107 = 0 ;
if ( V_2 -> V_9 . V_10 == 1 )
V_5 -> V_108 = V_96 ;
else
V_5 -> V_108 = V_2 -> V_9 . V_108 ;
V_5 -> V_106 = ( V_96 != V_5 -> V_108 ) ? true : false ;
V_5 -> V_99 = false ;
V_5 -> V_65 = 0 ;
V_5 -> V_74 = V_68 ;
V_5 -> V_95 = V_96 ;
V_5 -> V_92 = V_2 -> V_9 . V_92 ;
V_5 -> V_93 = 0 ;
V_5 -> V_77 = 0x80 ;
V_5 -> V_67 = false ;
F_38 ( & ( V_5 -> V_118 ) , V_2 -> V_119 , F_19 , ( T_1 * ) V_2 ) ;
V_80 ;
}
void F_39 ( struct V_1 * V_1 )
{
struct V_3 * V_5 = & V_1 -> V_5 ;
V_66 ;
F_40 ( & V_5 -> V_16 ) ;
V_80 ;
}
T_1 F_41 ( struct V_1 * V_2 , enum V_120 V_121 , T_1 * V_122 )
{
T_1 V_123 = true ;
F_42 ( V_2 , V_121 , V_122 ) ;
return V_123 ;
}
inline void F_43 ( struct V_1 * V_2 , T_2 V_124 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_4 -> V_54 = F_15 () + F_44 ( V_124 ) ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_125 , const char * V_126 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & V_2 -> V_32 ;
int V_53 = V_34 ;
if ( V_4 -> V_54 < F_15 () + F_44 ( V_125 ) )
V_4 -> V_54 = F_15 () + F_44 ( V_125 ) ;
{
T_2 V_127 = F_15 () ;
if ( V_4 -> V_128 ) {
F_4 ( L_22 , V_41 ) ;
while ( V_4 -> V_128 && F_30 ( V_127 ) <= 3000 )
F_46 ( 10 ) ;
if ( V_4 -> V_128 )
F_4 ( L_23 , V_41 ) ;
else
F_4 ( L_24 , V_41 ) ;
}
}
if ( ( ! V_4 -> V_117 ) && ( V_4 -> V_87 ) ) {
V_53 = V_129 ;
goto exit;
}
if ( ( V_4 -> V_117 ) && ( V_2 -> V_130 ) ) {
V_53 = V_129 ;
goto exit;
}
if ( F_16 ( V_31 , V_85 ) ) {
V_53 = V_34 ;
goto exit;
}
if ( V_21 == V_4 -> V_26 ) {
F_4 ( L_25 , V_41 ) ;
if ( V_129 == F_7 ( V_2 ) ) {
F_4 ( L_26 ) ;
V_53 = V_129 ;
goto exit;
}
}
if ( V_2 -> V_75 || ! V_2 -> V_131 ||
! V_2 -> V_73 ) {
F_4 ( L_27
, V_126
, V_2 -> V_75
, V_2 -> V_131
, V_2 -> V_73 ) ;
V_53 = false ;
goto exit;
}
exit:
if ( V_4 -> V_54 < F_15 () + F_44 ( V_125 ) )
V_4 -> V_54 = F_15 () + F_44 ( V_125 ) ;
return V_53 ;
}
int F_47 ( struct V_1 * V_2 , T_1 V_132 )
{
int V_53 = 0 ;
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_132 < V_133 ) {
if ( V_5 -> V_108 != V_132 ) {
if ( V_96 == V_132 )
F_34 ( V_2 ) ;
else
V_5 -> V_107 = 2 ;
V_5 -> V_108 = V_132 ;
V_5 -> V_106 = ( V_96 != V_5 -> V_108 ) ? true : false ;
}
} else {
V_53 = - V_134 ;
}
return V_53 ;
}
int F_48 ( struct V_1 * V_2 , T_1 V_132 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_132 == V_135 || V_132 == V_24 ) {
F_49 ( V_5 , V_132 ) ;
F_4 ( L_28 , V_41 , V_132 == V_135 ? L_29 : L_30 ) ;
return 0 ;
} else if ( V_132 == V_136 ) {
F_49 ( V_5 , V_132 ) ;
F_4 ( L_28 , V_41 , L_31 ) ;
if ( ( V_2 -> V_72 == 0 ) && ( V_129 == F_50 ( V_2 ) ) )
return - V_137 ;
} else {
return - V_134 ;
}
return 0 ;
}
