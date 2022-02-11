void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = true ;
V_4 -> V_6 = V_4 -> V_7 ;
V_4 -> V_8 ++ ;
F_3 ( L_1 , V_4 -> V_8 ) ;
if ( V_9 == V_4 -> V_10 ) {
V_4 -> V_11 = true ;
F_4 ( V_12 , L_2 ) ;
if ( V_4 -> V_6 == V_13 )
V_4 -> V_14 = true ;
F_5 ( V_2 ) ;
V_4 -> V_15 = V_9 ;
}
V_4 -> V_5 = false ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_2 , V_4 -> V_7 ) ;
F_8 ( & V_4 -> V_16 ) ;
F_1 ( V_2 ) ;
F_9 ( & V_4 -> V_16 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = V_18 ;
if ( ( V_4 -> V_15 == V_9 ) && ( ! V_4 -> V_5 ) ) {
V_4 -> V_5 = true ;
V_4 -> V_10 = V_19 ;
V_4 -> V_20 ++ ;
F_3 ( L_3 , V_4 -> V_20 ) ;
V_17 = F_11 ( V_2 ) ;
if ( V_17 == V_18 ) {
V_4 -> V_15 = V_19 ;
}
F_4 ( V_12 , L_4 ) ;
F_3 ( L_5 , F_12 ( V_2 , 0x4c ) ) ;
V_4 -> V_5 = false ;
V_4 -> V_14 = false ;
V_4 -> V_11 = false ;
}
return V_17 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_21 ;
if ( ! F_14 ( V_2 ) )
return V_18 ;
F_8 ( & V_4 -> V_16 ) ;
V_21 = F_10 ( V_2 ) ;
F_9 ( & V_4 -> V_16 ) ;
if ( V_18 == V_21 )
F_7 ( V_2 , V_22 ) ;
return V_21 ;
}
static bool F_15 ( struct V_1 * V_1 )
{
struct V_1 * V_23 = V_1 -> V_24 ;
struct V_25 * V_26 = & ( V_1 -> V_27 ) ;
struct V_28 * V_29 = & V_1 -> V_30 ;
bool V_21 = false ;
if ( F_2 ( V_1 ) -> V_11 == true ) {
goto exit;
}
if ( F_16 ( V_31 , F_2 ( V_1 ) -> V_32 ) ) {
goto exit;
}
if ( F_17 ( V_26 , V_33 | V_34 )
|| F_17 ( V_26 , V_35 | V_36 )
|| F_17 ( V_26 , V_37 )
|| F_17 ( V_26 , V_38 | V_39 )
)
goto exit;
if ( V_23 ) {
struct V_25 * V_40 = & ( V_23 -> V_27 ) ;
if ( F_17 ( V_40 , V_33 | V_34 )
|| F_17 ( V_40 , V_35 | V_36 )
|| F_17 ( V_40 , V_37 )
|| F_17 ( V_40 , V_38 | V_39 )
)
goto exit;
}
if ( V_29 -> V_41 != V_42 ||
V_29 -> V_43 != V_44 ) {
F_4 ( V_12 , L_6 ) ;
F_4 ( V_12 , L_7 ,
V_29 -> V_41 , V_29 -> V_43 ) ;
goto exit;
}
V_21 = true ;
exit:
return V_21 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_48 * V_49 = & V_46 -> V_50 ;
T_1 V_51 = 0 ;
F_8 ( & F_2 ( V_2 ) -> V_16 ) ;
V_51 = F_19 ( V_2 ) ;
F_9 ( & F_2 ( V_2 ) -> V_16 ) ;
if ( V_51 != 0 ) {
F_3 ( V_52 L_8 ,
F_20 ( V_2 ) , V_51 ) ;
goto exit;
}
if ( V_4 -> V_53 == true ) {
V_49 -> V_54 ++ ;
F_3 ( L_9 , V_55 ) ;
return;
}
V_4 -> V_56 = true ;
if ( V_4 -> V_7 == V_22 )
goto exit;
if ( F_15 ( V_2 ) == false )
goto exit;
if ( ( V_4 -> V_15 == V_19 ) && ( ( V_4 -> V_57 % 4 ) == 0 ) ) {
F_3 ( L_10 , V_55 ) ;
V_4 -> V_10 = V_9 ;
{
F_6 ( V_2 ) ;
}
}
exit:
V_4 -> V_56 = false ;
return;
}
void F_21 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_22 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 , T_3 V_59 , T_1 V_60 )
{
static unsigned long V_61 ;
static T_1 V_62 ;
T_3 V_63 = false ;
struct V_25 * V_26 = & V_2 -> V_27 ;
if ( V_59 ) {
V_62 += V_60 ;
if ( V_61 == 0 )
V_61 = V_31 ;
if ( F_24 ( V_31 - V_61 ) > 2000 ) {
if ( V_62 > 8 ) {
if ( ( F_2 ( V_2 ) -> V_64 )
&& ( F_2 ( V_2 ) -> V_65 != V_66 )
&& ( F_25 ( V_2 ) == false )
) {
F_3 ( L_11 , V_62 ) ;
V_63 = true ;
}
}
V_61 = V_31 ;
V_62 = 0 ;
}
} else {
if ( V_26 -> V_67 . V_68 > 4 ) {
if ( ( F_2 ( V_2 ) -> V_64 )
&& ( F_2 ( V_2 ) -> V_65 != V_66 )
&& ( F_25 ( V_2 ) == false )
) {
F_3 ( L_12 , V_26 -> V_67 . V_68 ) ;
V_63 = true ;
}
}
}
if ( V_63 )
F_26 ( V_2 , V_69 , V_59 ? 0 : 1 ) ;
}
void F_27 ( struct V_1 * V_2 , T_3 V_70 )
{
T_3 V_71 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_72 ;
V_70 = F_28 ( V_70 ) ;
if ( V_4 -> V_73 == true ) {
F_3 ( L_13 , V_55 , V_70 ) ;
} else{
if ( ( V_4 -> V_71 == V_70 )
|| ( ( V_4 -> V_71 >= V_74 ) && ( V_70 >= V_74 ) ) ) {
F_29 ( V_75 , V_76 ,
( L_14 , V_55 , V_4 -> V_71 , V_70 ) ) ;
return;
}
}
if ( ( V_2 -> V_77 == true ) ||
( V_2 -> V_78 == false ) ) {
F_29 ( V_75 , V_76 ,
( L_15 ,
V_55 , V_2 -> V_77 , V_2 -> V_78 ) ) ;
V_4 -> V_79 = V_80 ;
return;
}
if ( V_2 -> V_81 == true ) {
F_29 ( V_75 , V_76 ,
( L_16 , V_55 , V_70 ) ) ;
if ( V_70 < V_74 ) {
F_29 ( V_75 , V_76 ,
( L_17 , V_55 , V_70 ) ) ;
return;
}
}
V_71 = V_70 | V_4 -> V_82 ;
if ( ( V_4 -> V_79 < V_74 ) && ( V_70 >= V_74 ) )
V_71 |= V_83 ;
F_29 ( V_75 , V_84 ,
( L_18 , V_71 , V_4 -> V_79 ) ) ;
V_4 -> V_71 = V_70 ;
V_72 = 0 ;
if ( V_71 & V_83 )
F_30 ( V_2 , V_85 , & V_72 ) ;
if ( V_71 & V_83 )
F_31 ( & V_4 -> V_86 , V_87 ) ;
F_32 ( V_2 , V_88 , ( T_3 * ) ( & V_71 ) ) ;
V_4 -> V_82 += 0x80 ;
if ( V_71 & V_83 ) {
unsigned long V_61 ;
T_3 V_89 ;
T_3 V_90 = 0 ;
V_61 = V_31 ;
do {
F_33 ( 1 ) ;
V_90 ++ ;
F_30 ( V_2 , V_85 , & V_89 ) ;
if ( ( V_72 ^ V_89 ) & 0x80 ) {
V_4 -> V_79 = V_80 ;
V_4 -> V_91 = V_89 & V_92 ;
break;
}
if ( F_24 ( V_31 - V_61 ) > V_87 ) {
F_3 ( L_19 , V_55 , V_90 , V_72 , V_89 ) ;
F_31 ( & V_4 -> V_86 , 1 ) ;
break;
}
} while ( 1 );
} else
V_4 -> V_79 = V_70 ;
}
static T_3 F_34 ( struct V_1 * V_2 )
{
unsigned long V_93 , V_94 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & ( V_2 -> V_27 ) ;
#if F_35 ( V_95 ) || F_35 ( V_96 )
if ( true == V_4 -> V_53 && V_4 -> V_97 )
return true ;
else if ( true == V_4 -> V_53 && V_4 -> V_98 )
return true ;
else if ( true == V_4 -> V_53 )
return false ;
#else
if ( true == V_4 -> V_53 )
return false ;
#endif
V_93 = V_31 ;
V_94 = V_93 - V_4 -> V_99 ;
if ( V_94 < V_100 )
return false ;
if ( F_17 ( V_26 , V_34 )
|| F_17 ( V_26 , V_35 | V_36 )
|| F_17 ( V_26 , V_37 )
|| F_17 ( V_26 , V_38 | V_39 )
|| F_36 ( V_2 )
)
return false ;
if ( ( V_2 -> V_101 . V_102 == V_103 ) && ( V_2 -> V_101 . V_104 == false ) ) {
F_3 ( L_20 ) ;
return false ;
}
if ( ! F_37 ( V_2 ) )
return false ;
return true ;
}
void F_38 ( struct V_1 * V_2 , T_3 V_105 , T_3 V_106 , T_3 V_107 , const char * V_108 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
#if F_35 ( V_95 ) || F_35 ( V_96 )
struct V_48 * V_49 = & V_2 -> V_47 -> V_50 ;
#endif
F_29 ( V_75 , V_84 ,
( L_21 ,
V_55 , V_105 , V_106 ) ) ;
if ( V_105 > V_109 ) {
F_29 ( V_75 , V_76 , ( L_22 , V_105 ) ) ;
return;
}
if ( V_4 -> V_65 == V_105 )
if ( V_66 == V_105 )
return;
F_8 ( & V_4 -> V_16 ) ;
if ( V_105 == V_66 ) {
if ( 1
&& ( ( ( F_25 ( V_2 ) == false )
)
|| ( ( F_25 ( V_2 ) == true )
&& ( F_39 ( V_2 ) == false ) )
)
) {
F_3 ( V_52 L_23 ,
F_20 ( V_2 ) , V_108 ) ;
V_4 -> V_65 = V_105 ;
F_27 ( V_2 , V_80 ) ;
#if F_35 ( V_95 ) || F_35 ( V_96 )
if ( V_4 -> V_97 == true ||
V_4 -> V_98 == true ) {
unsigned long V_61 ;
T_1 V_110 ;
T_3 V_111 ;
V_110 = 20 ;
V_61 = V_31 ;
do {
F_30 ( V_2 , V_112 , & V_111 ) ;
if ( ! ( V_111 & F_40 ( 4 ) ) ) {
V_4 -> V_79 = V_80 ;
break;
}
if ( F_24 ( V_31 - V_61 ) > V_110 ) {
F_3 ( L_24 ,
V_55 , V_110 ) ;
V_49 -> V_113 ++ ;
break;
}
F_41 ( 1 ) ;
} while ( 1 );
}
#endif
F_32 ( V_2 , V_114 , ( T_3 * ) ( & V_105 ) ) ;
V_4 -> V_115 = false ;
F_42 ( V_2 , V_105 ) ;
}
} else{
if ( ( F_34 ( V_2 ) && F_17 ( & V_2 -> V_27 , V_33 ) )
|| ( ( F_25 ( V_2 ) == true )
&& ( F_39 ( V_2 ) == true ) )
) {
T_3 V_70 ;
F_3 ( V_52 L_25 ,
F_20 ( V_2 ) , V_108 ) ;
F_42 ( V_2 , V_105 ) ;
V_4 -> V_115 = true ;
V_4 -> V_65 = V_105 ;
V_4 -> V_106 = V_106 ;
V_4 -> V_107 = V_107 ;
F_32 ( V_2 , V_114 , ( T_3 * ) ( & V_105 ) ) ;
V_70 = V_74 ;
if ( V_4 -> V_116 == 0 )
V_70 = V_117 ;
if ( ( F_43 ( V_2 ) == false )
&& ( F_25 ( V_2 ) == true ) ) {
T_3 V_111 ;
V_111 = F_44 ( V_2 ) ;
if ( V_111 & F_40 ( 4 ) )
V_70 = V_74 ;
}
F_27 ( V_2 , V_70 ) ;
}
}
F_9 ( & V_4 -> V_16 ) ;
}
T_4 F_45 ( struct V_1 * V_2 , T_1 V_110 )
{
unsigned long V_61 ;
T_3 V_118 = false ;
T_4 V_119 = 0 ;
V_61 = V_31 ;
while ( 1 ) {
F_30 ( V_2 , V_120 , & V_118 ) ;
if ( true == V_118 )
break;
if ( true == V_2 -> V_77 ) {
V_119 = - 2 ;
F_3 ( L_26 , V_55 ) ;
break;
}
if ( F_24 ( V_31 - V_61 ) > V_110 ) {
V_119 = - 1 ;
F_3 ( L_27 , V_55 , V_110 ) ;
break;
}
F_41 ( 1 ) ;
}
return V_119 ;
}
void F_46 ( struct V_1 * V_2 , const char * V_108 )
{
struct V_45 * V_47 = F_47 ( V_2 ) ;
struct V_3 * V_4 = F_48 ( V_47 ) ;
int V_121 = 0 ;
char V_122 [ 32 ] = { 0 } ;
if ( F_25 ( V_2 ) == true )
return;
if ( F_17 ( & ( V_47 -> V_123 -> V_27 ) , V_33 ) )
V_121 ++ ;
if ( V_121 != 1 )
return;
if ( F_49 ( V_2 ) != V_124 )
return;
if ( F_34 ( V_47 -> V_123 ) == false )
return;
if ( V_4 -> V_64 ) {
if ( V_4 -> V_125 >= 2 ) {
if ( V_4 -> V_65 == V_66 ) {
sprintf ( V_122 , L_28 , V_108 ) ;
V_4 -> V_11 = true ;
F_38 ( V_2 , V_4 -> V_126 , V_2 -> V_127 . V_106 , 0 , V_122 ) ;
}
} else
V_4 -> V_125 ++ ;
}
}
void F_50 ( struct V_1 * V_2 , const char * V_108 )
{
#define F_51 100
struct V_45 * V_47 = F_47 ( V_2 ) ;
struct V_3 * V_4 = F_48 ( V_47 ) ;
char V_122 [ 32 ] = { 0 } ;
if ( F_25 ( V_2 ) == true )
return;
if ( V_4 -> V_64 ) {
if ( V_4 -> V_65 != V_66 ) {
sprintf ( V_122 , L_28 , V_108 ) ;
F_38 ( V_2 , V_66 , 0 , 0 , V_122 ) ;
if ( V_4 -> V_65 == V_66 )
F_45 ( V_2 , F_51 ) ;
}
}
V_4 -> V_11 = false ;
}
void F_52 ( struct V_1 * V_128 )
{
struct V_1 * V_129 = F_53 ( V_128 ) ;
struct V_25 * V_26 = & ( V_128 -> V_27 ) ;
struct V_3 * V_4 = F_2 ( V_128 ) ;
F_3 ( L_29 , V_55 ) ;
if ( true == V_128 -> V_77 ) {
F_3 ( V_52 L_30 ,
F_20 ( V_128 ) , V_128 -> V_77 ) ;
return;
}
if ( ( F_17 ( V_26 , V_130 ) == true ) ) {
if ( V_4 -> V_65 == V_66 ) {
F_3 ( L_31 , V_55 ) ;
return;
}
F_8 ( & V_4 -> V_16 ) ;
F_27 ( V_128 , V_80 ) ;
F_9 ( & V_4 -> V_16 ) ;
F_26 ( V_129 , V_69 , 0 ) ;
} else{
if ( V_4 -> V_15 == V_9 )
if ( false == F_13 ( V_129 ) )
F_3 ( L_32 ) ;
}
}
void F_54 ( struct V_1 * V_128 )
{
struct V_45 * V_47 = F_47 ( V_128 ) ;
T_3 V_131 = 0 ;
int V_121 = 0 ;
if ( ! V_128 -> V_132 ) {
F_3 ( V_52 L_33 ,
F_20 ( V_128 ) , V_128 -> V_132 ) ;
return;
}
if ( V_128 -> V_77 ) {
F_3 ( V_52 L_30 ,
F_20 ( V_128 ) , V_128 -> V_77 ) ;
return;
}
if ( F_17 ( & ( V_47 -> V_123 -> V_27 ) , V_33 ) )
V_121 ++ ;
if ( V_121 ) {
V_131 = 1 ;
F_26 ( V_128 , V_69 , V_131 ) ;
F_55 ( V_128 ) ;
} else {
if ( F_2 ( V_128 ) -> V_15 == V_9 ) {
if ( false == F_13 ( V_128 ) )
F_3 ( L_32 ) ;
}
}
}
void F_55 (
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_61 ;
T_3 V_133 ;
V_4 = F_2 ( V_2 ) ;
V_133 = false ;
V_61 = V_31 ;
F_56 () ;
while ( 1 ) {
F_8 ( & V_4 -> V_16 ) ;
if ( ( V_2 -> V_77 == true )
|| ( V_2 -> V_78 == false )
|| ( V_4 -> V_65 == V_66 )
)
V_133 = true ;
F_9 ( & V_4 -> V_16 ) ;
if ( true == V_133 )
break;
if ( F_24 ( V_31 - V_61 ) > 100 ) {
F_3 ( L_34 ) ;
break;
}
F_41 ( 1 ) ;
}
}
void F_57 (
struct V_1 * V_2 ,
struct V_134 * V_135 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_71 < V_74 ) {
F_3 ( L_35 , V_55 , V_4 -> V_71 , V_4 -> V_79 ) ;
F_9 ( & V_4 -> V_16 ) ;
goto exit;
}
V_4 -> V_79 = F_28 ( V_135 -> V_136 ) ;
V_4 -> V_91 = V_135 -> V_136 & V_92 ;
if ( V_4 -> V_79 >= V_74 ) {
if ( V_4 -> V_116 & V_137 )
F_9 ( & V_2 -> V_138 . V_139 ) ;
if ( V_4 -> V_116 & V_140 )
F_9 ( & V_2 -> V_30 . V_141 ) ;
}
F_9 ( & V_4 -> V_16 ) ;
exit:
F_29 ( V_75 , V_84 ,
( L_36 , V_4 -> V_79 ) ) ;
}
static void F_58 ( struct V_142 * V_143 )
{
struct V_3 * V_4 = F_59 ( V_143 , struct V_3 , V_144 ) ;
struct V_45 * V_47 = F_60 ( V_4 ) ;
struct V_1 * V_1 = V_47 -> V_145 ;
struct V_134 V_146 ;
V_146 . V_136 = V_74 ;
F_57 ( V_1 , & V_146 ) ;
}
static void F_61 ( struct V_142 * V_143 )
{
struct V_1 * V_2 ;
struct V_45 * V_47 ;
struct V_3 * V_4 ;
V_4 = F_59 ( V_143 , struct V_3 , V_147 ) ;
V_47 = F_60 ( V_4 ) ;
V_2 = V_47 -> V_145 ;
F_8 ( & V_4 -> V_16 ) ;
if ( ( V_4 -> V_71 == V_4 -> V_79 ) || ( V_4 -> V_79 >= V_74 ) ) {
F_3 ( L_37 , V_55 , V_4 -> V_71 , V_4 -> V_79 ) ;
goto exit;
}
F_9 ( & V_4 -> V_16 ) ;
if ( F_62 ( V_2 , 0x100 ) != 0xEA ) {
struct V_134 V_146 ;
V_146 . V_136 = V_74 ;
F_3 ( L_38 , V_55 ) ;
F_57 ( V_2 , & V_146 ) ;
return;
}
F_8 ( & V_4 -> V_16 ) ;
if ( ( V_4 -> V_71 == V_4 -> V_79 ) || ( V_4 -> V_79 >= V_74 ) ) {
F_3 ( L_39 , V_55 , V_4 -> V_79 ) ;
goto exit;
}
V_4 -> V_73 = true ;
F_27 ( V_2 , V_4 -> V_71 ) ;
V_4 -> V_73 = false ;
exit:
F_9 ( & V_4 -> V_16 ) ;
}
static void F_63 ( void * V_58 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = V_58 ;
V_4 = F_2 ( V_2 ) ;
F_3 ( L_40 , V_55 , V_4 -> V_71 , V_4 -> V_79 ) ;
if ( ( V_4 -> V_71 == V_4 -> V_79 ) || ( V_4 -> V_79 >= V_74 ) ) {
F_3 ( L_41 , V_55 , V_4 -> V_79 ) ;
return;
}
F_64 ( & V_4 -> V_147 ) ;
}
static T_5 void F_65 ( struct V_3 * V_148 , T_1 V_149 )
{
V_148 -> V_116 |= V_149 ;
}
static T_5 void F_66 ( struct V_3 * V_148 , T_1 V_149 )
{
V_148 -> V_116 &= ~ V_149 ;
}
T_4 F_67 ( struct V_1 * V_2 , T_1 V_150 )
{
T_4 V_151 ;
struct V_3 * V_148 ;
T_3 V_70 ;
V_151 = V_18 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_74 ;
F_8 ( & V_148 -> V_16 ) ;
F_65 ( V_148 , V_150 ) ;
if ( V_148 -> V_115 == true ) {
F_29 ( V_75 , V_84 ,
( L_42 ,
V_55 , V_150 , V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 < V_70 ) {
if ( V_148 -> V_79 < V_74 )
V_151 = V_152 ;
if ( V_148 -> V_71 < V_70 )
F_27 ( V_2 , V_70 ) ;
}
}
F_9 ( & V_148 -> V_16 ) ;
if ( V_152 == V_151 )
if ( V_148 -> V_79 >= V_74 )
V_151 = V_18 ;
return V_151 ;
}
void F_68 ( struct V_1 * V_2 , T_1 V_150 )
{
struct V_3 * V_148 ;
T_3 V_70 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_117 ;
if ( ( F_43 ( V_2 ) == false )
&& ( F_25 ( V_2 ) == true ) ) {
T_3 V_111 ;
V_111 = F_44 ( V_2 ) ;
if ( V_111 & F_40 ( 4 ) )
V_70 = V_74 ;
}
F_8 ( & V_148 -> V_16 ) ;
F_66 ( V_148 , V_150 ) ;
if ( ( V_148 -> V_65 != V_66 )
&& ( V_148 -> V_115 == true ) ) {
F_29 ( V_75 , V_84 ,
( L_43 ,
V_55 , V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 > V_70 )
if ( ( V_70 >= V_74 ) || ( V_148 -> V_116 == 0 ) )
F_27 ( V_2 , V_70 ) ;
}
F_9 ( & V_148 -> V_16 ) ;
}
T_4 F_69 ( struct V_1 * V_2 )
{
T_4 V_151 ;
struct V_3 * V_148 ;
T_3 V_70 ;
V_151 = V_18 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_74 ;
F_8 ( & V_148 -> V_16 ) ;
F_65 ( V_148 , V_140 ) ;
if ( V_148 -> V_115 == true ) {
F_29 ( V_75 , V_84 ,
( L_44 ,
V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 < V_70 ) {
if ( V_148 -> V_79 < V_74 )
V_151 = V_152 ;
if ( V_148 -> V_71 < V_70 )
F_27 ( V_2 , V_70 ) ;
}
}
F_9 ( & V_148 -> V_16 ) ;
if ( V_152 == V_151 )
if ( V_148 -> V_79 >= V_74 )
V_151 = V_18 ;
return V_151 ;
}
T_4 F_70 ( struct V_1 * V_2 )
{
T_4 V_151 ;
struct V_3 * V_148 ;
T_3 V_70 ;
V_151 = V_18 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_74 ;
F_8 ( & V_148 -> V_16 ) ;
F_65 ( V_148 , V_137 ) ;
if ( V_148 -> V_115 == true ) {
F_29 ( V_75 , V_153 ,
( L_45 ,
V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 < V_70 ) {
if ( V_148 -> V_79 < V_74 )
V_151 = V_152 ;
if ( V_148 -> V_71 < V_70 )
F_27 ( V_2 , V_70 ) ;
}
}
F_9 ( & V_148 -> V_16 ) ;
if ( V_152 == V_151 )
if ( V_148 -> V_79 >= V_74 )
V_151 = V_18 ;
return V_151 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_148 ;
T_3 V_70 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_117 ;
if ( ( F_43 ( V_2 ) == false )
&& ( F_25 ( V_2 ) == true ) ) {
T_3 V_111 ;
V_111 = F_44 ( V_2 ) ;
if ( V_111 & F_40 ( 4 ) )
V_70 = V_74 ;
}
F_8 ( & V_148 -> V_16 ) ;
F_66 ( V_148 , V_140 ) ;
if ( ( V_148 -> V_65 != V_66 )
&& ( V_148 -> V_115 == true ) ) {
F_29 ( V_75 , V_84 ,
( L_43 ,
V_55 , V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 > V_70 )
if ( ( V_70 >= V_74 ) || ( V_148 -> V_116 == 0 ) )
F_27 ( V_2 , V_70 ) ;
}
F_9 ( & V_148 -> V_16 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_148 ;
T_3 V_70 ;
V_148 = F_2 ( V_2 ) ;
V_70 = V_117 ;
if ( ( F_43 ( V_2 ) == false )
&& ( F_25 ( V_2 ) == true ) ) {
T_3 V_111 ;
V_111 = F_44 ( V_2 ) ;
if ( V_111 & F_40 ( 4 ) )
V_70 = V_74 ;
}
F_8 ( & V_148 -> V_16 ) ;
F_66 ( V_148 , V_137 ) ;
if ( ( V_148 -> V_65 != V_66 )
&& ( V_148 -> V_115 == true ) ) {
F_29 ( V_75 , V_153 ,
( L_43 ,
V_55 , V_148 -> V_79 , V_148 -> V_116 ) ) ;
if ( V_148 -> V_79 > V_70 ) {
if ( ( V_70 >= V_74 ) || ( V_148 -> V_116 == 0 ) )
F_27 ( V_2 , V_70 ) ;
}
}
F_9 ( & V_148 -> V_16 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_154 = F_2 ( V_2 ) ;
F_74 ( & V_154 -> V_16 , 1 ) ;
F_74 ( & V_154 -> V_155 , 1 ) ;
V_154 -> V_15 = V_19 ;
V_154 -> V_8 = 0 ;
V_154 -> V_20 = 0 ;
V_154 -> V_5 = false ;
V_154 -> V_6 = V_2 -> V_127 . V_6 ;
V_154 -> V_7 = V_2 -> V_127 . V_6 ;
V_154 -> V_156 = V_157 ;
V_154 -> V_57 = 0 ;
V_154 -> V_158 = false ;
V_154 -> V_53 = false ;
V_154 -> V_14 = false ;
V_154 -> V_125 = 0 ;
V_154 -> V_126 = V_2 -> V_127 . V_126 ;
V_154 -> V_64 = ( V_66 != V_154 -> V_126 ) ? true : false ;
V_154 -> V_115 = false ;
V_154 -> V_71 = 0 ;
V_154 -> V_79 = V_80 ;
V_154 -> V_65 = V_66 ;
V_154 -> V_106 = V_2 -> V_127 . V_106 ;
V_154 -> V_107 = 0 ;
V_154 -> V_159 = 0 ;
V_154 -> V_82 = 0x80 ;
F_32 ( V_2 , V_88 , ( T_3 * ) ( & V_154 -> V_71 ) ) ;
F_75 ( & V_154 -> V_144 , F_58 , NULL ) ;
V_154 -> V_73 = false ;
F_75 ( & V_154 -> V_147 , F_61 , NULL ) ;
F_76 ( & V_154 -> V_86 , V_2 -> V_160 , F_63 , V_2 ) ;
F_77 ( & V_154 -> V_161 , V_2 , F_21 ) ;
V_154 -> V_97 = false ;
V_154 -> V_98 = false ;
#ifdef F_78
V_154 -> V_162 = false ;
V_154 -> V_163 = NULL ;
V_154 -> V_164 = NULL ;
V_154 -> V_165 = NULL ;
V_154 -> V_166 = true ;
#endif
}
void F_79 ( struct V_1 * V_1 )
{
#ifdef F_78
if ( V_154 -> V_163 != NULL )
F_80 ( L_46 ) ;
if ( V_154 -> V_164 != NULL )
F_80 ( L_47 ) ;
if ( V_154 -> V_165 != NULL )
F_80 ( L_48 ) ;
#endif
}
inline void F_81 ( struct V_1 * V_2 , T_1 V_167 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_32 = V_31 + F_82 ( V_167 ) ;
}
int F_83 ( struct V_1 * V_2 , T_1 V_168 , const char * V_169 )
{
struct V_45 * V_47 = F_47 ( V_2 ) ;
struct V_3 * V_4 = F_48 ( V_47 ) ;
struct V_25 * V_26 ;
int V_21 = V_18 ;
unsigned long V_170 = V_31 ;
unsigned long V_171 = V_31 + F_82 ( V_168 ) ;
F_54 ( V_2 ) ;
V_2 = F_53 ( V_2 ) ;
V_26 = & V_2 -> V_27 ;
if ( F_16 ( V_4 -> V_32 , V_171 ) )
V_4 -> V_32 = V_171 ;
if ( V_4 -> V_56 ) {
F_3 ( L_49 , V_55 ) ;
while ( V_4 -> V_56 && F_24 ( V_31 - V_170 ) <= 3000 )
F_41 ( 10 ) ;
if ( V_4 -> V_56 )
F_3 ( L_50 , V_55 ) ;
else
F_3 ( L_51 , V_55 ) ;
}
if ( V_4 -> V_158 == false && V_4 -> V_53 ) {
F_3 ( L_52 , V_55 ) ;
while ( V_4 -> V_53
&& F_24 ( V_31 - V_170 ) <= 3000
) {
F_41 ( 10 ) ;
}
if ( V_4 -> V_53 )
F_3 ( L_53 , V_55 ) ;
else
F_3 ( L_54 , V_55 ) ;
}
if ( ( V_4 -> V_158 == false ) && ( true == V_4 -> V_53 ) ) {
V_21 = V_152 ;
goto exit;
}
if ( ( V_4 -> V_158 == true ) && ( V_2 -> V_172 == true ) ) {
V_21 = V_152 ;
goto exit;
}
if ( F_17 ( V_26 , V_130 ) == true ) {
V_21 = V_18 ;
goto exit;
}
if ( V_9 == V_4 -> V_15 ) {
{
F_84 ( L_55 , V_55 ) ;
if ( V_152 == F_13 ( V_2 ) ) {
F_84 ( L_32 ) ;
V_21 = V_152 ;
goto exit;
}
}
}
if ( V_2 -> V_81
|| ! V_2 -> V_132
|| ! V_2 -> V_78
) {
F_84 ( L_56
, V_169
, V_2 -> V_81
, V_2 -> V_132
, V_2 -> V_78 ) ;
V_21 = false ;
goto exit;
}
exit:
V_171 = V_31 + F_82 ( V_168 ) ;
if ( F_16 ( V_4 -> V_32 , V_171 ) )
V_4 -> V_32 = V_171 ;
return V_21 ;
}
int F_85 ( struct V_1 * V_2 , T_3 V_173 )
{
int V_21 = 0 ;
struct V_3 * V_154 = F_2 ( V_2 ) ;
if ( V_173 < V_174 ) {
if ( V_154 -> V_126 != V_173 ) {
if ( V_66 == V_173 )
F_54 ( V_2 ) ;
else
V_154 -> V_125 = 2 ;
V_154 -> V_126 = V_173 ;
V_154 -> V_64 = ( V_66 != V_154 -> V_126 ) ? true : false ;
}
} else
V_21 = - V_175 ;
return V_21 ;
}
int F_86 ( struct V_1 * V_2 , T_3 V_173 )
{
struct V_3 * V_154 = F_2 ( V_2 ) ;
if ( V_173 == V_176 || V_173 == V_13 ) {
F_87 ( V_154 , V_173 ) ;
F_3 ( L_57 , V_55 , V_173 == V_176 ? L_58 : L_59 ) ;
return 0 ;
} else if ( V_173 == V_22 ) {
F_87 ( V_154 , V_173 ) ;
F_3 ( L_57 , V_55 , L_60 ) ;
if ( ( V_2 -> V_77 == 0 ) && ( V_152 == F_88 ( V_2 ) ) )
return - V_177 ;
} else
return - V_175 ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 , enum V_178 V_179 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_51 & F_40 ( V_179 ) ) {
F_3 ( V_52 L_61 ,
F_20 ( V_2 ) , V_179 ) ;
}
V_4 -> V_51 |= F_40 ( V_179 ) ;
F_9 ( & V_4 -> V_16 ) ;
}
void F_90 ( struct V_1 * V_2 , enum V_178 V_179 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_8 ( & V_4 -> V_16 ) ;
if ( ( V_4 -> V_51 & F_40 ( V_179 ) ) == 0 ) {
F_3 ( V_52 L_62 ,
F_20 ( V_2 ) , V_179 ) ;
}
V_4 -> V_51 &= ~ F_40 ( V_179 ) ;
F_9 ( & V_4 -> V_16 ) ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_180 ;
V_180 = F_2 ( V_2 ) -> V_51 ;
return V_180 ;
}
