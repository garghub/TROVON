static inline void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_2 -> V_3 . V_4 = F_3 ( V_2 ) ;
V_2 -> V_3 . V_5 = F_4 ( V_2 ) - 1 ;
V_2 -> V_3 . V_6 = F_5 ( V_2 -> V_3 . V_4 ) ;
V_2 -> V_3 . V_7 = V_2 -> V_3 . V_4 -> V_8 ;
} else {
V_2 -> V_3 . V_4 = NULL ;
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_6 = NULL ;
V_2 -> V_3 . V_7 = 0 ;
}
V_2 -> V_3 . V_9 = 0 ;
V_2 -> V_3 . V_10 = 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
unsigned int V_13 , T_1 V_14 , T_1 V_15 ,
unsigned int V_16 , T_1 V_17 , T_1 V_18 ,
unsigned long V_19 )
{
unsigned long V_20 = V_12 -> V_21 ;
unsigned long V_22 = V_23 + V_19 ;
do {
if ( ( F_7 ( V_13 ) & V_14 ) == V_15 )
return 0 ;
if ( ( F_7 ( V_16 ) & V_17 ) == V_18 )
return 0 ;
F_8 () ;
} while ( V_20 -- );
if ( F_9 () || F_10 () )
return - V_24 ;
while ( F_11 ( V_22 ) ) {
F_12 ( 1 ) ;
if ( ( F_7 ( V_13 ) & V_14 ) == V_15 )
return 0 ;
if ( ( F_7 ( V_16 ) & V_17 ) == V_18 )
return 0 ;
}
return - V_24 ;
}
static void F_13 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned char V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
V_28 = F_7 ( V_33 ) ;
V_27 = F_7 ( V_34 ) ;
V_30 = F_7 ( V_35 ) ;
V_31 = F_7 ( V_36 ) ;
V_29 = F_7 ( V_37 ) ;
F_15 ( V_38 L_1 , V_27 ) ;
for ( V_32 = 0 ; V_39 [ V_32 ] . V_40 ; ++ V_32 )
if ( V_27 & V_39 [ V_32 ] . V_40 )
F_15 ( V_41 L_2 , V_39 [ V_32 ] . V_42 ) ;
F_15 ( V_41 L_3 , V_29 ) ;
for ( V_32 = 0 ; V_43 [ V_32 ] . V_40 ; ++ V_32 )
if ( V_29 & V_43 [ V_32 ] . V_40 )
F_15 ( V_41 L_2 , V_43 [ V_32 ] . V_42 ) ;
F_15 ( V_41 L_4 , V_31 ) ;
for ( V_32 = 0 ; V_44 [ V_32 ] . V_40 ; ++ V_32 )
if ( V_31 & V_44 [ V_32 ] . V_40 )
F_15 ( V_41 L_2 , V_44 [ V_32 ] . V_42 ) ;
F_15 ( V_41 L_5 , V_30 ) ;
for ( V_32 = 0 ; V_45 [ V_32 ] . V_40 ; ++ V_32 )
if ( V_30 & V_45 [ V_32 ] . V_40 )
F_15 ( V_41 L_2 , V_45 [ V_32 ] . V_42 ) ;
F_15 ( V_41 L_6 ) ;
}
static void F_16 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned char V_27 ;
int V_32 ;
V_27 = F_7 ( V_34 ) ;
if ( ! ( V_27 & V_46 ) )
F_17 ( V_38 , V_26 , L_7 ) ;
else {
for ( V_32 = 0 ; ( V_47 [ V_32 ] . V_48 != V_49 ) &&
( V_47 [ V_32 ] . V_48 != ( V_27 & V_50 ) ) ; ++ V_32 )
;
F_17 ( V_38 , V_26 , L_8 , V_47 [ V_32 ] . V_42 ) ;
}
}
static const char * F_18 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
return V_12 -> V_51 ;
}
static int F_19 ( struct V_25 * V_26 , int V_52 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_32 ;
unsigned long V_22 ;
unsigned long V_53 ;
V_26 -> V_54 = 7 ;
V_12 -> V_55 = V_26 ;
V_12 -> V_56 = 1 << V_26 -> V_57 ;
V_12 -> V_58 = 0 ;
for ( V_32 = V_12 -> V_56 ; V_32 <= 0x80 ; V_32 <<= 1 )
if ( V_32 > V_12 -> V_56 )
V_12 -> V_58 |= V_32 ;
for ( V_32 = 0 ; V_32 < 8 ; ++ V_32 )
V_12 -> V_59 [ V_32 ] = 0 ;
V_12 -> V_60 = 0 ;
F_20 ( & V_12 -> V_61 ) ;
V_12 -> V_62 = NULL ;
V_12 -> V_63 = NULL ;
F_21 ( & V_12 -> V_64 ) ;
F_21 ( & V_12 -> V_65 ) ;
F_21 ( & V_12 -> V_66 ) ;
V_12 -> V_52 = V_52 ;
F_22 ( & V_12 -> V_67 , V_68 ) ;
V_12 -> V_69 = F_23 ( L_9 ,
V_70 | V_71 ,
1 , V_26 -> V_72 ) ;
if ( ! V_12 -> V_69 )
return - V_73 ;
snprintf ( V_12 -> V_51 , sizeof( V_12 -> V_51 ) ,
L_10 ,
V_26 -> V_74 -> V_42 , V_26 -> V_75 , V_12 -> V_76 ,
V_12 -> V_77 , V_26 -> V_78 , V_26 -> V_79 ,
V_26 -> V_80 , V_26 -> V_57 ,
V_12 -> V_52 & V_81 ? L_11 : L_12 ,
V_12 -> V_52 & V_82 ? L_13 : L_12 ,
V_12 -> V_52 & V_83 ? L_14 : L_12 ) ;
F_24 ( V_36 , V_84 ) ;
F_24 ( V_35 , V_85 ) ;
F_24 ( V_86 , 0 ) ;
F_24 ( V_87 , 0 ) ;
V_32 = 0 ;
V_22 = V_23 + 1 ;
do {
F_8 () ;
} while ( F_11 ( V_22 ) );
V_22 += F_25 ( 256 ) ;
do {
F_7 ( V_34 ) ;
++ V_32 ;
F_8 () ;
} while ( F_11 ( V_22 ) );
V_53 = V_32 / 256 ;
V_12 -> V_21 = V_88 * V_53 / 2 ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_89 ;
for ( V_89 = 1 ; ( F_7 ( V_34 ) & V_90 ) && V_89 <= 6 ; ++ V_89 ) {
switch ( V_89 ) {
case 1 :
case 3 :
case 5 :
F_17 ( V_91 , V_26 , L_15 ) ;
F_27 ( V_12 ,
V_34 , V_90 , 0 , 5 * V_92 ) ;
break;
case 2 :
F_17 ( V_91 , V_26 , L_16 ) ;
F_28 ( V_26 ) ;
break;
case 4 :
F_17 ( V_91 , V_26 , L_17 ) ;
F_29 ( V_26 ) ;
if ( V_12 -> V_52 & V_83 )
F_30 ( 2500 ) ;
else
F_30 ( 500 ) ;
break;
case 6 :
F_17 ( V_91 , V_26 , L_18 ) ;
return - V_93 ;
}
}
return 0 ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
F_32 ( & V_12 -> V_67 ) ;
F_33 ( V_12 -> V_69 ) ;
}
static void F_34 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
F_35 ( V_94 , V_26 , L_19 , V_2 ) ;
if ( V_12 -> V_63 == V_2 ) {
if ( ( V_2 -> V_95 & 0xff ) != V_96 ) {
F_36 ( V_2 , & V_12 -> V_97 ) ;
F_37 ( V_2 , V_98 ) ;
} else
F_36 ( V_2 , & V_12 -> V_97 ) ;
V_12 -> V_63 = NULL ;
}
V_12 -> V_59 [ F_38 ( V_2 ) ] &= ~ ( 1 << V_2 -> V_99 -> V_100 ) ;
V_2 -> V_101 ( V_2 ) ;
}
static int F_39 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
struct V_102 * V_103 = F_40 ( V_2 ) ;
unsigned long V_52 ;
#if ( V_104 & V_105 )
switch ( V_2 -> V_106 [ 0 ] ) {
case V_107 :
case V_108 :
F_17 ( V_38 , V_26 , L_20 ) ;
V_2 -> V_95 = ( V_98 << 16 ) ;
V_2 -> V_101 ( V_2 ) ;
return 0 ;
}
#endif
V_2 -> V_95 = 0 ;
if ( ! F_41 ( V_26 ) )
return V_109 ;
F_42 ( & V_12 -> V_61 , V_52 ) ;
if ( V_2 -> V_106 [ 0 ] == V_110 )
F_43 ( & V_103 -> V_111 , & V_12 -> V_65 ) ;
else
F_44 ( & V_103 -> V_111 , & V_12 -> V_65 ) ;
F_45 ( & V_12 -> V_61 , V_52 ) ;
F_35 ( V_94 , V_26 , L_21 ,
V_2 , ( V_2 -> V_106 [ 0 ] == V_110 ) ? L_22 : L_23 ) ;
F_46 ( V_12 -> V_69 , & V_12 -> V_67 ) ;
return 0 ;
}
static inline void F_47 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
if ( F_48 ( & V_12 -> V_66 ) &&
F_48 ( & V_12 -> V_65 ) &&
F_48 ( & V_12 -> V_64 ) &&
! V_12 -> V_62 &&
! V_12 -> V_112 ) {
F_49 ( V_26 ) ;
}
}
static struct V_1 * F_50 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
struct V_102 * V_103 ;
struct V_1 * V_2 ;
if ( V_12 -> V_63 || F_48 ( & V_12 -> V_64 ) ) {
F_51 (ncmd, &hostdata->unissued, list) {
V_2 = F_52 ( V_103 ) ;
F_35 ( V_94 , V_26 , L_24 ,
V_2 , F_38 ( V_2 ) , V_12 -> V_59 [ F_38 ( V_2 ) ] , V_2 -> V_99 -> V_100 ) ;
if ( ! ( V_12 -> V_59 [ F_38 ( V_2 ) ] & ( 1 << V_2 -> V_99 -> V_100 ) ) ) {
F_53 ( & V_103 -> V_111 ) ;
F_35 ( V_94 , V_26 ,
L_25 , V_2 ) ;
return V_2 ;
}
}
} else {
V_103 = F_54 ( & V_12 -> V_64 ,
struct V_102 , V_111 ) ;
F_53 ( & V_103 -> V_111 ) ;
V_2 = F_52 ( V_103 ) ;
F_35 ( V_94 , V_26 ,
L_26 , V_2 ) ;
F_55 ( V_2 , & V_12 -> V_97 , NULL , 0 , ~ 0 ) ;
V_12 -> V_63 = V_2 ;
return V_2 ;
}
return NULL ;
}
static void F_56 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
struct V_102 * V_103 = F_40 ( V_2 ) ;
if ( V_12 -> V_63 == V_2 ) {
F_36 ( V_2 , & V_12 -> V_97 ) ;
F_43 ( & V_103 -> V_111 , & V_12 -> V_64 ) ;
V_12 -> V_63 = NULL ;
} else
F_43 ( & V_103 -> V_111 , & V_12 -> V_65 ) ;
}
static void V_68 ( struct V_113 * V_114 )
{
struct V_11 * V_12 =
F_57 ( V_114 , struct V_11 , V_67 ) ;
struct V_25 * V_26 = V_12 -> V_55 ;
int V_115 ;
do {
V_115 = 1 ;
F_58 ( & V_12 -> V_61 ) ;
while ( ! V_12 -> V_62 && ! V_12 -> V_112 ) {
struct V_1 * V_2 = F_50 ( V_26 ) ;
if ( ! V_2 )
break;
F_35 ( V_116 , V_26 , L_27 , V_2 ) ;
if ( ! F_59 ( V_26 , V_2 ) ) {
F_35 ( V_116 , V_26 , L_28 ) ;
F_47 ( V_26 ) ;
} else {
F_35 ( V_116 | V_94 , V_26 ,
L_29 , V_2 ) ;
F_56 ( V_26 , V_2 ) ;
}
}
if ( V_12 -> V_62 && ! V_12 -> V_60 ) {
F_35 ( V_116 , V_26 , L_30 ) ;
F_60 ( V_26 ) ;
V_115 = 0 ;
}
F_61 ( & V_12 -> V_61 ) ;
if ( ! V_115 )
F_62 () ;
} while ( ! V_115 );
}
static void F_63 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_117 ;
unsigned char * * V_28 ;
int * V_118 ;
int V_119 = 0 , V_120 = 0 ;
unsigned char V_121 ;
if ( V_12 -> V_122 ) {
V_121 = V_12 -> V_62 -> V_3 . V_123 ;
if ( V_121 & V_124 ) {
F_64 ( 10 ) ;
if ( ( F_7 ( V_37 ) &
( V_125 | V_126 ) ) ==
( V_125 | V_126 ) ) {
V_119 = F_7 ( V_127 ) ;
V_120 = 1 ;
F_35 ( V_128 , V_26 , L_31 ) ;
}
}
}
#ifdef F_65
if ( ( F_66 ( F_67 ( V_12 -> V_62 -> V_129 ) ) ) ) {
F_68 ( L_32 ,
V_26 -> V_72 ) ;
F_69 () ;
}
if ( ( F_7 ( V_37 ) & ( V_125 | V_126 ) ) ==
( V_125 | V_126 ) ) {
F_68 ( L_33 , V_26 -> V_72 ,
F_7 ( V_37 ) ) ;
F_68 ( L_34 ,
V_26 -> V_72 ) ;
F_69 () ;
}
#endif
F_24 ( V_35 , V_85 ) ;
F_24 ( V_36 , V_84 ) ;
F_7 ( V_130 ) ;
V_117 = V_12 -> V_60 - F_70 ( V_12 ) ;
V_12 -> V_60 = 0 ;
V_28 = ( unsigned char * * ) & V_12 -> V_62 -> V_3 . V_6 ;
V_118 = & V_12 -> V_62 -> V_3 . V_7 ;
* V_28 += V_117 ;
* V_118 -= V_117 ;
if ( V_12 -> V_122 ) {
int V_131 , V_132 ;
if ( ( F_7 ( V_34 ) & V_50 ) == V_121 && ( V_121 & V_124 ) ) {
V_131 = V_132 = V_12 -> V_122 ;
if ( V_120 ) {
F_35 ( V_128 , V_26 ,
L_35 ) ;
* ( * V_28 ) ++ = V_119 ;
( * V_118 ) -- ;
V_131 -- ;
V_132 -- ;
}
if ( V_132 > 0 ) {
F_35 ( V_128 , V_26 ,
L_36 , V_131 , * V_28 ) ;
F_71 ( V_26 , & V_121 , & V_131 , V_28 ) ;
* V_118 -= V_132 - V_131 ;
}
}
}
}
static T_2 T_3 F_72 ( int V_75 , void * V_133 )
{
struct V_25 * V_26 = V_133 ;
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_134 = 0 ;
unsigned char V_29 ;
unsigned long V_52 ;
F_42 ( & V_12 -> V_61 , V_52 ) ;
V_29 = F_7 ( V_37 ) ;
if ( V_29 & V_135 ) {
unsigned char V_30 = F_7 ( V_35 ) ;
unsigned char V_136 = F_7 ( V_34 ) ;
F_35 ( V_137 , V_26 , L_37 ,
V_75 , V_29 , V_136 , V_30 ) ;
if ( ( V_30 & V_138 ) || ( V_30 & V_139 ) ) {
F_35 ( V_137 , V_26 , L_38 ) ;
if ( V_12 -> V_62 ) {
F_63 ( V_26 ) ;
F_46 ( V_12 -> V_69 , & V_12 -> V_67 ) ;
} else {
F_24 ( V_35 , V_85 ) ;
F_7 ( V_130 ) ;
}
} else if ( ( F_7 ( V_33 ) & V_12 -> V_56 ) &&
( V_136 & ( V_140 | V_124 | V_90 | V_141 ) ) == ( V_140 | V_124 ) ) {
F_24 ( V_87 , 0 ) ;
F_7 ( V_130 ) ;
F_35 ( V_137 , V_26 , L_39 ) ;
if ( ! V_12 -> V_62 ) {
F_73 ( V_26 ) ;
F_46 ( V_12 -> V_69 , & V_12 -> V_67 ) ;
}
if ( ! V_12 -> V_62 )
F_24 ( V_87 , V_12 -> V_56 ) ;
} else {
F_7 ( V_130 ) ;
F_35 ( V_137 , V_26 , L_40 ) ;
#ifdef F_74
V_142 -> V_143 |= V_144 ;
#endif
}
V_134 = 1 ;
} else {
F_35 ( V_137 , V_26 , L_41 ) ;
#ifdef F_74
V_142 -> V_143 |= V_144 ;
#endif
}
F_45 ( & V_12 -> V_61 , V_52 ) ;
return F_75 ( V_134 ) ;
}
static struct V_1 * F_59 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
__releases( &hostdata->lock
static int F_71 ( struct V_25 * V_26 ,
unsigned char * V_123 , int * V_118 ,
unsigned char * * V_28 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned char V_121 = * V_123 , V_145 ;
int V_146 = * V_118 ;
unsigned char * V_147 = * V_28 ;
F_24 ( V_86 , F_76 ( V_121 ) ) ;
do {
if ( F_27 ( V_12 , V_34 , V_46 , V_46 , V_92 ) < 0 )
break;
F_35 ( V_148 , V_26 , L_42 ) ;
if ( ( F_7 ( V_34 ) & V_50 ) != V_121 ) {
F_35 ( V_149 , V_26 , L_43 ) ;
F_77 ( V_149 , V_26 ) ;
break;
}
if ( ! ( V_121 & V_124 ) )
F_24 ( V_150 , * V_147 ) ;
else
* V_147 = F_7 ( V_33 ) ;
++ V_147 ;
if ( ! ( V_121 & V_124 ) ) {
if ( ! ( ( V_121 & V_151 ) && V_146 > 1 ) ) {
F_24 ( V_36 , V_84 | V_152 ) ;
F_78 ( V_149 , V_26 ) ;
F_24 ( V_36 , V_84 |
V_152 | V_153 ) ;
} else {
F_24 ( V_36 , V_84 |
V_152 | V_154 ) ;
F_78 ( V_149 , V_26 ) ;
F_24 ( V_36 , V_84 |
V_152 | V_154 | V_153 ) ;
}
} else {
F_78 ( V_149 , V_26 ) ;
F_24 ( V_36 , V_84 | V_153 ) ;
}
if ( F_27 ( V_12 ,
V_34 , V_46 , 0 , 5 * V_92 ) < 0 )
break;
F_35 ( V_148 , V_26 , L_44 ) ;
if ( ! ( V_121 == V_155 && V_146 == 1 ) ) {
if ( V_121 == V_156 && V_146 > 1 )
F_24 ( V_36 , V_84 | V_154 ) ;
else
F_24 ( V_36 , V_84 ) ;
}
} while ( -- V_146 );
F_35 ( V_149 , V_26 , L_45 , V_146 ) ;
* V_118 = V_146 ;
* V_28 = V_147 ;
V_145 = F_7 ( V_34 ) ;
if ( ( V_145 & V_46 ) || ( ( V_145 & V_124 ) && V_146 == 0 ) )
* V_123 = V_145 & V_50 ;
else
* V_123 = V_49 ;
if ( ! V_146 || ( * V_123 == V_121 ) )
return 0 ;
else
return - 1 ;
}
static void F_29 ( struct V_25 * V_26 )
{
struct V_11 T_3 * V_12 = F_14 ( V_26 ) ;
unsigned long V_52 ;
F_79 ( V_52 ) ;
F_24 ( V_86 ,
F_76 ( F_7 ( V_34 ) & V_50 ) ) ;
F_24 ( V_36 , V_84 | V_157 ) ;
F_64 ( 50 ) ;
F_24 ( V_36 , V_84 ) ;
( void ) F_7 ( V_130 ) ;
F_80 ( V_52 ) ;
}
static int F_28 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned char * V_158 , V_123 , V_145 ;
int V_159 ;
int V_160 ;
F_24 ( V_36 , V_84 | V_154 ) ;
V_160 = F_27 ( V_12 , V_34 , V_46 , V_46 , 10 * V_92 ) ;
if ( V_160 < 0 )
goto V_161;
V_145 = F_7 ( V_34 ) & V_50 ;
F_24 ( V_86 , F_76 ( V_145 ) ) ;
if ( V_145 != V_156 ) {
F_24 ( V_36 ,
V_84 | V_154 | V_153 ) ;
V_160 = F_27 ( V_12 , V_34 , V_46 , 0 , 3 * V_92 ) ;
if ( V_160 < 0 )
goto V_161;
F_24 ( V_36 , V_84 | V_154 ) ;
}
V_145 = ABORT ;
V_158 = & V_145 ;
V_159 = 1 ;
V_123 = V_156 ;
F_71 ( V_26 , & V_123 , & V_159 , & V_158 ) ;
return V_159 ? - 1 : 0 ;
V_161:
F_24 ( V_36 , V_84 ) ;
return - 1 ;
}
static int F_81 ( struct V_25 * V_26 ,
unsigned char * V_123 , int * V_118 ,
unsigned char * * V_28 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_146 = * V_118 ;
unsigned char V_121 = * V_123 ;
unsigned char * V_147 = * V_28 ;
unsigned char V_145 ;
int V_95 = 0 ;
if ( ( V_145 = ( F_7 ( V_34 ) & V_50 ) ) != V_121 ) {
* V_123 = V_145 ;
return - 1 ;
}
V_12 -> V_62 -> V_3 . V_123 = V_121 ;
if ( V_121 & V_124 ) {
if ( V_12 -> V_122 )
V_146 -= V_12 -> V_122 ;
else if ( V_12 -> V_52 & V_81 )
-- V_146 ;
}
F_35 ( V_128 , V_26 , L_46 ,
( V_121 & V_124 ) ? L_47 : L_48 , V_146 , V_147 ) ;
#ifdef F_65
F_82 ( V_146 , * V_28 ) ;
#endif
F_24 ( V_86 , F_76 ( V_121 ) ) ;
F_24 ( V_35 , V_85 | V_138 | V_139 |
V_162 ) ;
if ( ! ( V_12 -> V_52 & V_163 ) ) {
if ( V_121 & V_124 )
V_95 = F_83 ( V_12 , V_147 , V_146 ) ;
else
V_95 = F_84 ( V_12 , V_147 , V_146 ) ;
}
if ( V_121 & V_124 ) {
F_24 ( V_36 , V_84 ) ;
F_85 ( 1 ) ;
F_24 ( V_164 , 0 ) ;
} else {
F_85 ( 1 ) ;
F_24 ( V_36 , V_84 | V_152 ) ;
F_85 ( 1 ) ;
F_24 ( V_165 , 0 ) ;
F_85 ( 1 ) ;
}
#ifdef F_65
#ifdef F_74
V_142 -> V_143 |= V_144 ;
#endif
V_166 = 1 ;
#endif
if ( V_12 -> V_52 & V_163 ) {
if ( V_121 & V_124 )
V_95 = F_83 ( V_12 , V_147 , V_146 ) ;
else
V_95 = F_84 ( V_12 , V_147 , V_146 ) ;
}
if ( V_95 < 0 )
return V_95 ;
if ( V_95 > 0 ) {
V_12 -> V_60 = V_95 ;
return 0 ;
}
V_12 -> V_60 = V_146 ;
if ( V_12 -> V_52 & V_81 ) {
if ( V_121 & V_124 ) {
if ( F_27 ( V_12 , V_37 ,
V_167 , V_167 , V_92 ) < 0 ) {
V_95 = - 1 ;
F_17 ( V_91 , V_26 , L_49 ) ;
}
if ( F_27 ( V_12 , V_34 ,
V_46 , 0 , V_92 ) < 0 ) {
V_95 = - 1 ;
F_17 ( V_91 , V_26 , L_50 ) ;
}
V_147 [ * V_118 - 1 ] = F_7 ( V_127 ) ;
} else {
if ( F_6 ( V_12 ,
V_37 , V_167 , V_167 ,
V_37 , V_125 , 0 , V_92 ) < 0 ) {
V_95 = - 1 ;
F_17 ( V_91 , V_26 , L_51 ) ;
}
}
}
F_63 ( V_26 ) ;
return V_95 ;
}
static void F_60 ( struct V_25 * V_26 )
__releases( &hostdata->lock
static void F_73 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned char V_168 ;
unsigned char V_100 ;
unsigned char V_169 [ 3 ] ;
struct V_102 * V_103 ;
struct V_1 * V_145 ;
F_24 ( V_35 , V_85 ) ;
V_168 = F_7 ( V_33 ) & ~ ( V_12 -> V_56 ) ;
F_35 ( V_170 , V_26 , L_52 ) ;
F_24 ( V_36 , V_84 | V_171 ) ;
if ( F_27 ( V_12 ,
V_34 , V_140 , 0 , 2 * V_92 ) < 0 ) {
F_24 ( V_36 , V_84 ) ;
return;
}
F_24 ( V_36 , V_84 ) ;
if ( F_27 ( V_12 ,
V_34 , V_46 , V_46 , 2 * V_92 ) < 0 ) {
F_28 ( V_26 ) ;
return;
}
#ifdef F_65
F_24 ( V_86 , F_76 ( V_155 ) ) ;
V_169 [ 0 ] = F_7 ( V_33 ) ;
#else
{
int V_159 = 1 ;
unsigned char * V_28 = V_169 ;
unsigned char V_123 = V_155 ;
F_71 ( V_26 , & V_123 , & V_159 , & V_28 ) ;
if ( V_159 ) {
F_28 ( V_26 ) ;
return;
}
}
#endif
if ( ! ( V_169 [ 0 ] & 0x80 ) ) {
F_17 ( V_91 , V_26 , L_53 ) ;
F_86 ( V_169 ) ;
F_15 ( L_6 ) ;
F_28 ( V_26 ) ;
return;
}
V_100 = V_169 [ 0 ] & 0x07 ;
V_145 = NULL ;
F_51 (ncmd, &hostdata->disconnected, list) {
struct V_1 * V_2 = F_52 ( V_103 ) ;
if ( V_168 == ( 1 << F_38 ( V_2 ) ) &&
V_100 == ( T_1 ) V_2 -> V_99 -> V_100 ) {
F_53 ( & V_103 -> V_111 ) ;
V_145 = V_2 ;
break;
}
}
if ( V_145 ) {
F_35 ( V_170 | V_94 , V_26 ,
L_54 , V_145 ) ;
} else {
F_17 ( V_91 , V_26 , L_55 ,
V_168 , V_100 ) ;
F_28 ( V_26 ) ;
return;
}
#ifdef F_65
if ( V_172 != V_145 ) {
int V_118 ;
if ( ! V_145 -> V_3 . V_7 && V_145 -> V_3 . V_5 ) {
++ V_145 -> V_3 . V_4 ;
-- V_145 -> V_3 . V_5 ;
V_145 -> V_3 . V_7 = V_145 -> V_3 . V_4 -> V_8 ;
V_145 -> V_3 . V_6 = F_5 ( V_145 -> V_3 . V_4 ) ;
}
V_118 = F_87 ( V_12 , V_145 ) ;
if ( V_118 > 0 ) {
if ( F_67 ( V_145 -> V_129 ) )
F_88 ( V_12 ,
V_145 -> V_3 . V_6 , V_118 ) ;
else
F_89 ( V_12 ,
V_145 -> V_3 . V_6 , V_118 ) ;
V_172 = V_145 ;
}
}
F_24 ( V_36 , V_84 | V_153 ) ;
#endif
F_24 ( V_36 , V_84 ) ;
V_12 -> V_62 = V_145 ;
F_35 ( V_170 , V_26 , L_56 ,
F_38 ( V_145 ) , V_145 -> V_99 -> V_100 ) ;
}
static bool F_90 ( struct V_173 * V_174 ,
struct V_1 * V_175 )
{
struct V_102 * V_103 ;
F_51 (ncmd, haystack, list)
if ( F_52 ( V_103 ) == V_175 )
return true ;
return false ;
}
static bool F_91 ( struct V_173 * V_174 ,
struct V_1 * V_175 )
{
if ( F_90 ( V_174 , V_175 ) ) {
struct V_102 * V_103 = F_40 ( V_175 ) ;
F_53 ( & V_103 -> V_111 ) ;
return true ;
}
return false ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_99 -> V_55 ;
struct V_11 * V_12 = F_14 ( V_26 ) ;
unsigned long V_52 ;
int V_95 = V_176 ;
F_42 ( & V_12 -> V_61 , V_52 ) ;
#if ( V_104 & V_177 )
F_93 ( V_178 , V_2 , V_179 ) ;
#endif
F_78 ( V_177 , V_26 ) ;
F_77 ( V_177 , V_26 ) ;
if ( F_91 ( & V_12 -> V_65 , V_2 ) ) {
F_35 ( V_180 , V_26 ,
L_57 , V_2 ) ;
V_2 -> V_95 = V_181 << 16 ;
V_2 -> V_101 ( V_2 ) ;
goto V_182;
}
if ( V_12 -> V_112 == V_2 ) {
F_35 ( V_180 , V_26 ,
L_58 , V_2 ) ;
V_12 -> V_112 = NULL ;
V_2 -> V_95 = V_181 << 16 ;
F_34 ( V_26 , V_2 ) ;
goto V_182;
}
if ( F_91 ( & V_12 -> V_66 , V_2 ) ) {
F_35 ( V_180 , V_26 ,
L_59 , V_2 ) ;
F_37 ( V_2 , V_98 ) ;
F_34 ( V_26 , V_2 ) ;
V_95 = V_183 ;
goto V_182;
}
if ( V_12 -> V_62 == V_2 ) {
F_35 ( V_180 , V_26 , L_60 , V_2 ) ;
V_12 -> V_62 = NULL ;
V_12 -> V_60 = 0 ;
if ( F_28 ( V_26 ) ) {
F_37 ( V_2 , V_98 ) ;
F_34 ( V_26 , V_2 ) ;
V_95 = V_183 ;
goto V_182;
}
F_37 ( V_2 , V_181 ) ;
F_34 ( V_26 , V_2 ) ;
goto V_182;
}
if ( F_91 ( & V_12 -> V_64 , V_2 ) ) {
F_35 ( V_180 , V_26 ,
L_61 , V_2 ) ;
F_37 ( V_2 , V_98 ) ;
F_34 ( V_26 , V_2 ) ;
}
V_182:
if ( V_95 == V_183 )
F_35 ( V_180 , V_26 , L_62 , V_2 ) ;
else
F_35 ( V_180 , V_26 , L_63 , V_2 ) ;
F_46 ( V_12 -> V_69 , & V_12 -> V_67 ) ;
F_47 ( V_26 ) ;
F_45 ( & V_12 -> V_61 , V_52 ) ;
return V_95 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_99 -> V_55 ;
struct V_11 * V_12 = F_14 ( V_26 ) ;
int V_32 ;
unsigned long V_52 ;
struct V_102 * V_103 ;
F_42 ( & V_12 -> V_61 , V_52 ) ;
#if ( V_104 & V_177 )
F_93 ( V_178 , V_2 , V_179 ) ;
#endif
F_78 ( V_177 , V_26 ) ;
F_77 ( V_177 , V_26 ) ;
F_29 ( V_26 ) ;
F_24 ( V_35 , V_85 ) ;
F_24 ( V_86 , 0 ) ;
F_24 ( V_87 , 0 ) ;
if ( F_91 ( & V_12 -> V_65 , V_2 ) ) {
V_2 -> V_95 = V_184 << 16 ;
V_2 -> V_101 ( V_2 ) ;
}
if ( V_12 -> V_112 ) {
V_12 -> V_112 -> V_95 = V_184 << 16 ;
F_34 ( V_26 , V_12 -> V_112 ) ;
V_12 -> V_112 = NULL ;
}
F_51 (ncmd, &hostdata->disconnected, list) {
struct V_1 * V_2 = F_52 ( V_103 ) ;
F_37 ( V_2 , V_184 ) ;
F_34 ( V_26 , V_2 ) ;
}
F_21 ( & V_12 -> V_66 ) ;
F_51 (ncmd, &hostdata->autosense, list) {
struct V_1 * V_2 = F_52 ( V_103 ) ;
F_37 ( V_2 , V_184 ) ;
V_2 -> V_101 ( V_2 ) ;
}
F_21 ( & V_12 -> V_64 ) ;
if ( V_12 -> V_62 ) {
F_37 ( V_12 -> V_62 , V_184 ) ;
F_34 ( V_26 , V_12 -> V_62 ) ;
V_12 -> V_62 = NULL ;
}
for ( V_32 = 0 ; V_32 < 8 ; ++ V_32 )
V_12 -> V_59 [ V_32 ] = 0 ;
V_12 -> V_60 = 0 ;
F_46 ( V_12 -> V_69 , & V_12 -> V_67 ) ;
F_47 ( V_26 ) ;
F_45 ( & V_12 -> V_61 , V_52 ) ;
return V_176 ;
}
