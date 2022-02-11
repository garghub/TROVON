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
V_65 = F_21 ( V_65 ) ;
if ( V_4 -> V_67 ) {
if ( V_65 < V_68 )
V_65 = V_69 ;
}
if ( ( V_4 -> V_66 == V_65 ) ) {
F_22 ( V_70 , V_71 ,
( L_9 , V_41 , V_4 -> V_66 , V_65 ) ) ;
return;
}
if ( ( V_2 -> V_72 ) ||
( ! V_2 -> V_73 ) ) {
F_22 ( V_70 , V_71 ,
( L_10 ,
V_41 , V_2 -> V_72 , V_2 -> V_73 ) ) ;
V_4 -> V_74 = V_68 ;
return;
}
if ( V_2 -> V_75 ) {
F_22 ( V_70 , V_71 ,
( L_11 , V_41 , V_65 ) ) ;
if ( V_65 < V_76 ) {
F_22 ( V_70 , V_71 ,
( L_12 , V_41 , V_65 ) ) ;
return;
}
}
V_66 = V_65 | V_4 -> V_77 ;
F_22 ( V_70 , V_78 ,
( L_13 , V_66 , V_4 -> V_74 ) ) ;
V_4 -> V_66 = V_65 ;
F_23 ( V_2 , V_79 , ( T_1 * ) ( & V_66 ) ) ;
V_4 -> V_77 += 0x80 ;
V_4 -> V_74 = V_65 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_2 V_80 , V_81 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & ( V_2 -> V_32 ) ;
V_80 = V_55 ;
V_81 = V_80 - V_4 -> V_82 ;
if ( V_81 < V_83 )
return false ;
if ( ( F_15 ( V_31 , V_84 ) == false ) ||
( F_15 ( V_31 , V_85 ) ) ||
( F_15 ( V_31 , V_60 ) ) ||
( F_15 ( V_31 , V_61 ) ) ||
( F_15 ( V_31 , V_62 ) ) )
return false ;
if ( V_4 -> V_86 )
return false ;
if ( ( V_2 -> V_29 . V_87 == V_88 ) && ( V_2 -> V_29 . V_89 == false ) ) {
F_4 ( L_14 ) ;
return false ;
}
return true ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_90 , T_1 V_91 , T_1 V_92 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
#ifdef F_14
struct V_50 * V_51 = & ( V_2 -> V_52 ) ;
#endif
F_22 ( V_70 , V_78 ,
( L_15 ,
V_41 , V_90 , V_91 ) ) ;
if ( V_90 > V_93 ) {
F_22 ( V_70 , V_71 , ( L_16 , V_90 ) ) ;
return;
}
if ( V_4 -> V_94 == V_90 ) {
if ( V_95 == V_90 )
return;
if ( ( V_4 -> V_91 == V_91 ) &&
( V_4 -> V_92 == V_92 ) )
return;
}
if ( V_90 == V_95 ) {
#ifdef F_14
if ( V_51 -> V_96 == 0 ) {
F_4 ( L_17 ) ;
V_4 -> V_94 = V_90 ;
F_20 ( V_2 , V_68 ) ;
F_23 ( V_2 , V_97 , ( T_1 * ) ( & V_90 ) ) ;
V_4 -> V_98 = false ;
}
} else {
#endif
if ( F_24 ( V_2 ) ) {
F_4 ( L_18 , V_41 ) ;
V_4 -> V_98 = true ;
V_4 -> V_94 = V_90 ;
V_4 -> V_91 = V_91 ;
V_4 -> V_92 = V_92 ;
F_23 ( V_2 , V_97 , ( T_1 * ) ( & V_90 ) ) ;
#ifdef F_14
if ( V_51 -> V_96 == 1 )
F_26 ( V_2 , V_99 , 0 ) ;
#endif
F_20 ( V_2 , V_76 ) ;
}
}
}
T_3 F_27 ( struct V_1 * V_2 , T_2 V_100 )
{
T_2 V_101 ;
T_1 V_102 = false ;
T_3 V_103 = 0 ;
V_101 = V_55 ;
while ( 1 ) {
F_28 ( V_2 , V_104 , & V_102 ) ;
if ( V_102 )
break;
if ( V_2 -> V_72 ) {
V_103 = - 2 ;
F_4 ( L_19 , V_41 ) ;
break;
}
if ( F_29 ( V_101 ) > V_100 ) {
V_103 = - 1 ;
F_4 ( L_20 , V_41 , V_100 ) ;
break;
}
F_30 ( 1 ) ;
}
return V_103 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_24 ( V_2 ) == false )
return;
if ( V_4 -> V_105 ) {
if ( V_4 -> V_106 >= 2 ) {
if ( V_4 -> V_94 == V_95 ) {
V_4 -> V_23 = true ;
F_4 ( L_21 , V_41 , V_4 -> V_91 ) ;
F_25 ( V_2 , V_4 -> V_107 , V_4 -> V_91 , 0 ) ;
}
} else {
V_4 -> V_106 ++ ;
}
}
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( V_4 -> V_105 ) {
if ( V_4 -> V_94 != V_95 ) {
F_25 ( V_2 , V_95 , 0 , 0 ) ;
if ( V_4 -> V_94 == V_95 )
F_27 ( V_2 , V_108 ) ;
}
}
V_4 -> V_23 = false ;
}
void F_33 ( struct V_1 * V_109 )
{
struct V_30 * V_31 = & ( V_109 -> V_32 ) ;
T_1 V_110 = 0 ;
if ( F_15 ( V_31 , V_84 ) ) {
F_26 ( V_109 , V_111 , V_110 ) ;
F_34 ( V_109 , V_112 , V_110 ) ;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
F_36 ( & V_5 -> V_16 ) ;
V_5 -> V_26 = V_36 ;
V_5 -> V_20 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_17 = false ;
V_5 -> V_18 = V_2 -> V_9 . V_18 ;
V_5 -> V_19 = V_2 -> V_9 . V_18 ;
V_5 -> V_113 = V_114 ;
V_5 -> V_115 = 0 ;
V_5 -> V_116 = false ;
V_5 -> V_86 = false ;
V_5 -> V_25 = false ;
V_5 -> V_106 = 0 ;
if ( V_2 -> V_9 . V_10 == 1 )
V_5 -> V_107 = V_95 ;
else
V_5 -> V_107 = V_2 -> V_9 . V_107 ;
V_5 -> V_105 = ( V_95 != V_5 -> V_107 ) ? true : false ;
V_5 -> V_98 = false ;
V_5 -> V_66 = 0 ;
V_5 -> V_74 = V_68 ;
V_5 -> V_94 = V_95 ;
V_5 -> V_91 = V_2 -> V_9 . V_91 ;
V_5 -> V_92 = 0 ;
V_5 -> V_77 = 0x80 ;
V_5 -> V_67 = false ;
F_37 ( & ( V_5 -> V_117 ) , V_2 -> V_118 , F_18 , ( T_1 * ) V_2 ) ;
}
T_1 F_38 ( struct V_1 * V_2 , enum V_119 V_120 , T_1 * V_121 )
{
T_1 V_122 = true ;
F_39 ( V_2 , V_120 , V_121 ) ;
return V_122 ;
}
inline void F_40 ( struct V_1 * V_2 , T_2 V_123 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_4 -> V_54 = V_55 + F_41 ( V_123 ) ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_124 , const char * V_125 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_30 * V_31 = & V_2 -> V_32 ;
int V_53 = V_34 ;
if ( V_4 -> V_54 < V_55 + F_41 ( V_124 ) )
V_4 -> V_54 = V_55 + F_41 ( V_124 ) ;
{
T_2 V_126 = V_55 ;
if ( V_4 -> V_127 ) {
F_4 ( L_22 , V_41 ) ;
while ( V_4 -> V_127 && F_29 ( V_126 ) <= 3000 )
F_30 ( 10 ) ;
if ( V_4 -> V_127 )
F_4 ( L_23 , V_41 ) ;
else
F_4 ( L_24 , V_41 ) ;
}
}
if ( ( ! V_4 -> V_116 ) && ( V_4 -> V_86 ) ) {
V_53 = V_128 ;
goto exit;
}
if ( ( V_4 -> V_116 ) && ( V_2 -> V_129 ) ) {
V_53 = V_128 ;
goto exit;
}
if ( F_15 ( V_31 , V_84 ) ) {
V_53 = V_34 ;
goto exit;
}
if ( V_21 == V_4 -> V_26 ) {
F_4 ( L_25 , V_41 ) ;
if ( V_128 == F_7 ( V_2 ) ) {
F_4 ( L_26 ) ;
V_53 = V_128 ;
goto exit;
}
}
if ( V_2 -> V_75 || ! V_2 -> V_130 ||
! V_2 -> V_73 ) {
F_4 ( L_27
, V_125
, V_2 -> V_75
, V_2 -> V_130
, V_2 -> V_73 ) ;
V_53 = false ;
goto exit;
}
exit:
if ( V_4 -> V_54 < V_55 + F_41 ( V_124 ) )
V_4 -> V_54 = V_55 + F_41 ( V_124 ) ;
return V_53 ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_131 )
{
int V_53 = 0 ;
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_131 < V_132 ) {
if ( V_5 -> V_107 != V_131 ) {
if ( V_95 == V_131 )
F_33 ( V_2 ) ;
else
V_5 -> V_106 = 2 ;
V_5 -> V_107 = V_131 ;
V_5 -> V_105 = ( V_95 != V_5 -> V_107 ) ? true : false ;
}
} else {
V_53 = - V_133 ;
}
return V_53 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_131 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_131 == V_134 || V_131 == V_24 ) {
F_45 ( V_5 , V_131 ) ;
F_4 ( L_28 , V_41 , V_131 == V_134 ? L_29 : L_30 ) ;
return 0 ;
} else if ( V_131 == V_135 ) {
F_45 ( V_5 , V_131 ) ;
F_4 ( L_28 , V_41 , L_31 ) ;
if ( ( V_2 -> V_72 == 0 ) && ( V_128 == F_46 ( V_2 ) ) )
return - V_136 ;
} else {
return - V_133 ;
}
return 0 ;
}
