void F_1 ( char * V_1 , char * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
sprintf ( & V_1 [ V_4 * 2 ] , L_1 , ( unsigned char ) V_2 [ V_4 ] ) ;
}
void F_2 ( char * V_1 , char * V_2 , int V_5 )
{
int V_4 ;
char V_6 [ 3 ] = { 0 , } ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_6 [ 0 ] = V_2 [ V_4 * 2 ] ;
V_6 [ 1 ] = V_2 [ V_4 * 2 + 1 ] ;
V_1 [ V_4 ] = ( unsigned char ) F_3 ( V_6 , NULL , 16 ) ;
}
}
static int F_4 ( char * V_1 ,
struct V_7 * V_8 ,
char * V_2 , int V_9 )
{
struct V_10 V_11 ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_15 ,
. V_16 = V_17
} ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_19 ) ;
F_6 ( & V_11 , ( V_20 * ) V_2 , V_9 ) ;
if ( ! V_13 . V_14 ) {
V_13 . V_14 = F_7 ( V_21 , 0 ,
V_22 ) ;
if ( F_8 ( V_13 . V_14 ) ) {
V_18 = F_9 ( V_13 . V_14 ) ;
F_10 ( V_23 , L_2
L_3 ,
V_18 ) ;
goto V_24;
}
V_8 -> V_15 = V_13 . V_14 ;
}
V_18 = F_11 ( & V_13 ) ;
if ( V_18 ) {
F_12 ( V_23
L_4 ,
V_25 , V_18 ) ;
goto V_24;
}
V_18 = F_13 ( & V_13 , & V_11 , V_9 ) ;
if ( V_18 ) {
F_12 ( V_23
L_5 ,
V_25 , V_18 ) ;
goto V_24;
}
V_18 = F_14 ( & V_13 , V_1 ) ;
if ( V_18 ) {
F_12 ( V_23
L_6 ,
V_25 , V_18 ) ;
goto V_24;
}
V_24:
F_15 ( & V_8 -> V_19 ) ;
return V_18 ;
}
static int F_16 ( char * * V_26 ,
char * V_27 ,
char * V_28 )
{
int V_29 = strlen ( V_27 ) ;
int V_30 = strlen ( V_28 ) ;
int V_31 ;
int V_18 ;
V_31 = ( V_30 + V_29 + 3 ) ;
( * V_26 ) = F_17 ( V_31 , V_32 ) ;
if ( ! ( * V_26 ) ) {
V_18 = - V_33 ;
goto V_24;
}
snprintf ( ( * V_26 ) , V_31 , L_7 ,
V_28 , V_27 ) ;
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_18 ( char * V_34 , struct V_7 * V_8 ,
T_2 V_35 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
char V_2 [ V_37 + 16 ] ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_8 ) ;
F_20 ( V_8 -> V_40 , V_8 -> V_41 ) ;
}
memcpy ( V_2 , V_8 -> V_40 , V_8 -> V_41 ) ;
memset ( ( V_2 + V_8 -> V_41 ) , 0 , 16 ) ;
snprintf ( ( V_2 + V_8 -> V_41 ) , 16 , L_9 , V_35 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_10 ) ;
F_20 ( V_2 , ( V_8 -> V_41 + 16 ) ) ;
}
V_18 = F_4 ( V_1 , V_8 , V_2 ,
( V_8 -> V_41 + 16 ) ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_12 ) ;
goto V_24;
}
memcpy ( V_34 , V_1 , V_8 -> V_41 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_13 ) ;
F_20 ( V_34 , V_8 -> V_41 ) ;
}
V_24:
return V_18 ;
}
void
F_21 ( struct V_7 * V_8 )
{
memset ( ( void * ) V_8 , 0 , sizeof( struct V_7 ) ) ;
F_22 ( & V_8 -> V_43 ) ;
F_23 ( & V_8 -> V_44 ) ;
F_23 ( & V_8 -> V_45 ) ;
F_23 ( & V_8 -> V_46 ) ;
F_23 ( & V_8 -> V_19 ) ;
V_8 -> V_16 |= V_47 ;
}
void F_24 ( struct V_7 * V_8 )
{
struct V_48 * V_49 , * V_50 ;
if ( V_8 -> V_14 )
F_25 ( V_8 -> V_14 ) ;
if ( V_8 -> V_15 )
F_26 ( V_8 -> V_15 ) ;
F_27 (key_sig, key_sig_tmp,
&crypt_stat->keysig_list, crypt_stat_list) {
F_28 ( & V_49 -> V_51 ) ;
F_29 ( V_52 , V_49 ) ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
}
void F_30 (
struct V_53 * V_54 )
{
struct V_55 * V_56 , * V_57 ;
if ( ! ( V_54 -> V_16 & V_58 ) )
return;
F_5 ( & V_54 -> V_59 ) ;
F_27 (auth_tok, auth_tok_tmp,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
F_28 ( & V_56 -> V_60 ) ;
if ( V_56 -> V_61
&& ! ( V_56 -> V_16 & V_62 ) )
F_31 ( V_56 -> V_61 ) ;
F_29 ( V_63 , V_56 ) ;
}
F_15 ( & V_54 -> V_59 ) ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
}
int F_32 ( const void * V_64 , int V_65 , struct V_10 * V_11 ,
int V_66 )
{
int V_67 = 0 ;
struct V_68 * V_69 ;
int V_35 ;
int V_70 ;
F_33 ( V_11 , V_66 ) ;
while ( V_65 > 0 && V_67 < V_66 ) {
V_69 = F_34 ( V_64 ) ;
V_35 = F_35 ( V_64 ) ;
F_36 ( & V_11 [ V_67 ] , V_69 , 0 , V_35 ) ;
V_70 = V_71 - V_35 ;
if ( V_65 >= V_70 ) {
V_11 [ V_67 ] . V_72 = V_70 ;
V_64 += V_70 ;
V_65 -= V_70 ;
} else {
V_11 [ V_67 ] . V_72 = V_65 ;
V_64 += V_65 ;
V_65 = 0 ;
}
V_67 ++ ;
}
if ( V_65 > 0 )
return - V_33 ;
return V_67 ;
}
static void F_37 ( struct V_73 * V_74 , int V_18 )
{
struct V_75 * V_76 = V_74 -> V_77 ;
if ( V_18 == - V_78 )
return;
V_76 -> V_18 = V_18 ;
F_38 ( & V_76 -> V_79 ) ;
}
static int F_39 ( struct V_7 * V_8 ,
struct V_10 * V_80 ,
struct V_10 * V_81 , int V_65 ,
unsigned char * V_34 , int V_82 )
{
struct V_83 * V_74 = NULL ;
struct V_75 V_76 ;
int V_18 = 0 ;
F_40 ( ! V_8 || ! V_8 -> V_14
|| ! ( V_8 -> V_16 & V_47 ) ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_14 ,
V_8 -> V_84 ) ;
F_20 ( V_8 -> V_85 ,
V_8 -> V_84 ) ;
}
F_41 ( & V_76 . V_79 ) ;
F_5 ( & V_8 -> V_46 ) ;
V_74 = F_42 ( V_8 -> V_14 , V_86 ) ;
if ( ! V_74 ) {
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_43 ( V_74 ,
V_87 | V_17 ,
F_37 , & V_76 ) ;
if ( ! ( V_8 -> V_16 & V_88 ) ) {
V_18 = F_44 ( V_8 -> V_14 , V_8 -> V_85 ,
V_8 -> V_84 ) ;
if ( V_18 ) {
F_10 ( V_23 ,
L_15 ,
V_18 ) ;
F_15 ( & V_8 -> V_46 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_8 -> V_16 |= V_88 ;
}
F_15 ( & V_8 -> V_46 ) ;
F_45 ( V_74 , V_81 , V_80 , V_65 , V_34 ) ;
V_18 = V_82 == V_90 ? F_46 ( V_74 ) :
F_47 ( V_74 ) ;
if ( V_18 == - V_78 || V_18 == - V_91 ) {
struct V_75 * V_76 = V_74 -> V_92 . V_77 ;
F_48 ( & V_76 -> V_79 ) ;
V_18 = V_76 -> V_18 ;
F_49 ( & V_76 -> V_79 ) ;
}
V_24:
F_50 ( V_74 ) ;
return V_18 ;
}
static T_2 F_51 ( struct V_7 * V_8 ,
struct V_68 * V_68 )
{
return F_52 ( V_8 ) +
( ( T_2 ) V_68 -> V_93 << V_94 ) ;
}
static int F_53 ( struct V_7 * V_8 ,
struct V_68 * V_95 ,
struct V_68 * V_96 ,
unsigned long V_97 , int V_82 )
{
T_3 V_98 = V_82 == V_90 ? V_96 -> V_93 : V_95 -> V_93 ;
T_2 V_99 ;
char V_100 [ V_37 ] ;
struct V_10 V_81 , V_80 ;
T_1 V_101 = V_8 -> V_101 ;
int V_18 ;
V_99 = ( ( ( T_2 ) V_98 ) * ( V_71 / V_101 ) ) ;
V_18 = F_18 ( V_100 , V_8 ,
( V_99 + V_97 ) ) ;
if ( V_18 ) {
F_10 ( V_23 , L_16
L_17 ,
( unsigned long long ) ( V_99 + V_97 ) , V_18 ) ;
goto V_24;
}
F_33 ( & V_81 , 1 ) ;
F_33 ( & V_80 , 1 ) ;
F_36 ( & V_81 , V_96 , V_101 ,
V_97 * V_101 ) ;
F_36 ( & V_80 , V_95 , V_101 ,
V_97 * V_101 ) ;
V_18 = F_39 ( V_8 , & V_80 , & V_81 , V_101 ,
V_100 , V_82 ) ;
if ( V_18 < 0 ) {
F_12 ( V_23 L_18
L_19
L_20 , V_25 , V_98 , V_97 , V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
return V_18 ;
}
int F_54 ( struct V_68 * V_68 )
{
struct V_102 * V_103 ;
struct V_7 * V_8 ;
char * V_104 ;
struct V_68 * V_105 = NULL ;
T_2 V_97 ;
T_2 V_106 ;
int V_18 = 0 ;
V_103 = V_68 -> V_107 -> V_108 ;
V_8 =
& ( F_55 ( V_103 ) -> V_8 ) ;
F_40 ( ! ( V_8 -> V_16 & V_109 ) ) ;
V_105 = F_56 ( V_110 ) ;
if ( ! V_105 ) {
V_18 = - V_33 ;
F_10 ( V_23 , L_21
L_22 ) ;
goto V_24;
}
for ( V_97 = 0 ;
V_97 < ( V_71 / V_8 -> V_101 ) ;
V_97 ++ ) {
V_18 = F_53 ( V_8 , V_105 , V_68 ,
V_97 , V_90 ) ;
if ( V_18 ) {
F_12 ( V_23 L_23
L_20 , V_25 , V_18 ) ;
goto V_24;
}
}
V_106 = F_51 ( V_8 , V_68 ) ;
V_104 = F_57 ( V_105 ) ;
V_18 = F_58 ( V_103 , V_104 , V_106 ,
V_71 ) ;
F_59 ( V_105 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 ,
L_24 ,
V_18 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
if ( V_105 ) {
F_60 ( V_105 ) ;
}
return V_18 ;
}
int F_61 ( struct V_68 * V_68 )
{
struct V_102 * V_103 ;
struct V_7 * V_8 ;
char * V_111 ;
unsigned long V_97 ;
T_2 V_106 ;
int V_18 = 0 ;
V_103 = V_68 -> V_107 -> V_108 ;
V_8 =
& ( F_55 ( V_103 ) -> V_8 ) ;
F_40 ( ! ( V_8 -> V_16 & V_109 ) ) ;
V_106 = F_51 ( V_8 , V_68 ) ;
V_111 = F_57 ( V_68 ) ;
V_18 = F_62 ( V_111 , V_106 , V_71 ,
V_103 ) ;
F_59 ( V_68 ) ;
if ( V_18 < 0 ) {
F_10 ( V_23 ,
L_25 ,
V_18 ) ;
goto V_24;
}
for ( V_97 = 0 ;
V_97 < ( V_71 / V_8 -> V_101 ) ;
V_97 ++ ) {
V_18 = F_53 ( V_8 , V_68 , V_68 ,
V_97 , V_112 ) ;
if ( V_18 ) {
F_12 ( V_23 L_23
L_20 , V_25 , V_18 ) ;
goto V_24;
}
}
V_24:
return V_18 ;
}
int F_63 ( struct V_7 * V_8 )
{
char * V_113 ;
int V_18 = - V_89 ;
F_10 ( V_39 ,
L_26
L_27 ,
V_8 -> V_114 , ( int ) strlen ( V_8 -> V_114 ) ,
V_8 -> V_84 << 3 ) ;
F_5 ( & V_8 -> V_46 ) ;
if ( V_8 -> V_14 ) {
V_18 = 0 ;
goto V_115;
}
V_18 = F_16 ( & V_113 ,
V_8 -> V_114 , L_28 ) ;
if ( V_18 )
goto V_115;
V_8 -> V_14 = F_64 ( V_113 , 0 , 0 ) ;
if ( F_8 ( V_8 -> V_14 ) ) {
V_18 = F_9 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
F_10 ( V_23 , L_29
L_30 ,
V_113 ) ;
goto V_116;
}
F_65 ( V_8 -> V_14 , V_117 ) ;
V_18 = 0 ;
V_116:
F_66 ( V_113 ) ;
V_115:
F_15 ( & V_8 -> V_46 ) ;
return V_18 ;
}
static void F_67 ( struct V_7 * V_8 )
{
int V_118 ;
V_8 -> V_119 = 0xFFFFFFFF ;
V_8 -> V_120 = 0 ;
if ( V_8 -> V_101 == 0 )
return;
V_118 = V_8 -> V_101 ;
while ( ( V_118 & 0x01 ) == 0 ) {
V_118 >>= 1 ;
V_8 -> V_119 <<= 1 ;
V_8 -> V_120 ++ ;
}
}
void F_68 ( struct V_7 * V_8 )
{
V_8 -> V_101 = V_121 ;
F_67 ( V_8 ) ;
V_8 -> V_41 = V_122 ;
if ( V_8 -> V_16 & V_123 )
V_8 -> V_124 = V_125 ;
else {
if ( V_71 <= V_125 )
V_8 -> V_124 =
V_125 ;
else
V_8 -> V_124 = V_71 ;
}
}
int F_69 ( struct V_7 * V_8 )
{
int V_18 = 0 ;
char V_1 [ V_36 ] ;
F_40 ( V_8 -> V_41 > V_36 ) ;
F_40 ( V_8 -> V_41 <= 0 ) ;
if ( ! ( V_8 -> V_16 & V_126 ) ) {
V_18 = - V_89 ;
F_10 ( V_42 , L_31
L_32 ) ;
goto V_24;
}
V_18 = F_4 ( V_1 , V_8 , V_8 -> V_85 ,
V_8 -> V_84 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_11
L_33 ) ;
goto V_24;
}
memcpy ( V_8 -> V_40 , V_1 , V_8 -> V_41 ) ;
V_24:
if ( V_18 ) {
memset ( V_8 -> V_40 , 0 , V_8 -> V_41 ) ;
V_8 -> V_16 |= V_127 ;
}
return V_18 ;
}
static void F_70 ( struct V_7 * V_8 )
{
F_71 ( V_8 -> V_85 , V_8 -> V_84 ) ;
V_8 -> V_16 |= V_126 ;
F_69 ( V_8 ) ;
if ( F_19 ( V_38 > 0 ) ) {
F_10 ( V_39 , L_34 ) ;
F_20 ( V_8 -> V_85 ,
V_8 -> V_84 ) ;
}
}
static void F_72 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_16 & V_128 )
V_8 -> V_16 |= V_123 ;
if ( V_54 -> V_16 & V_129 )
V_8 -> V_16 |= V_130 ;
if ( V_54 -> V_16 & V_131 ) {
V_8 -> V_16 |= V_132 ;
if ( V_54 -> V_16
& V_133 )
V_8 -> V_16 |= V_134 ;
else if ( V_54 -> V_16
& V_135 )
V_8 -> V_16 |= V_136 ;
}
}
static int F_73 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_55 * V_137 ;
int V_18 = 0 ;
F_5 ( & V_8 -> V_44 ) ;
F_5 ( & V_54 -> V_59 ) ;
F_74 (global_auth_tok,
&mount_crypt_stat->global_auth_tok_list,
mount_crypt_stat_list) {
if ( V_137 -> V_16 & V_138 )
continue;
V_18 = F_75 ( V_8 , V_137 -> V_139 ) ;
if ( V_18 ) {
F_12 ( V_23 L_35 , V_18 ) ;
goto V_24;
}
}
V_24:
F_15 ( & V_54 -> V_59 ) ;
F_15 ( & V_8 -> V_44 ) ;
return V_18 ;
}
static void F_76 (
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
F_72 ( V_8 ,
V_54 ) ;
F_68 ( V_8 ) ;
strcpy ( V_8 -> V_114 , V_140 ) ;
V_8 -> V_84 = V_141 ;
V_8 -> V_16 &= ~ ( V_126 ) ;
V_8 -> V_142 = V_143 ;
V_8 -> V_54 = V_54 ;
}
int F_77 ( struct V_102 * V_103 )
{
struct V_7 * V_8 =
& F_55 ( V_103 ) -> V_8 ;
struct V_53 * V_54 =
& F_78 (
V_103 -> V_144 ) -> V_54 ;
int V_29 ;
int V_18 = 0 ;
F_76 ( V_8 , V_54 ) ;
V_8 -> V_16 |= ( V_109 | V_126 ) ;
F_72 ( V_8 ,
V_54 ) ;
V_18 = F_73 ( V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_36
L_37 , V_18 ) ;
goto V_24;
}
V_29 =
strlen ( V_54 -> V_145 ) ;
memcpy ( V_8 -> V_114 ,
V_54 -> V_145 ,
V_29 ) ;
V_8 -> V_114 [ V_29 ] = '\0' ;
V_8 -> V_84 =
V_54 -> V_146 ;
F_70 ( V_8 ) ;
V_18 = F_63 ( V_8 ) ;
if ( V_18 )
F_10 ( V_23 , L_38
L_39 ,
V_8 -> V_114 , V_18 ) ;
V_24:
return V_18 ;
}
static int F_79 ( char * V_77 )
{
T_4 V_147 , V_148 ;
V_147 = F_80 ( V_77 ) ;
V_148 = F_80 ( V_77 + 4 ) ;
if ( ( V_147 ^ V_149 ) == V_148 )
return 0 ;
F_10 ( V_39 , L_40
L_41 , V_147 , V_148 ,
V_149 ) ;
F_10 ( V_39 , L_42
L_43 , ( V_147 ^ V_149 ) ) ;
return - V_89 ;
}
static int F_81 ( struct V_7 * V_8 ,
char * V_111 , int * V_150 )
{
int V_18 = 0 ;
int V_67 ;
T_4 V_16 ;
V_16 = F_80 ( V_111 ) ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_151 )
/ sizeof( struct V_152 ) ) ) ; V_67 ++ )
if ( V_16 & V_151 [ V_67 ] . V_153 ) {
V_8 -> V_16 |= V_151 [ V_67 ] . V_154 ;
} else
V_8 -> V_16 &= ~ ( V_151 [ V_67 ] . V_154 ) ;
V_8 -> V_142 = ( ( V_16 >> 24 ) & 0xFF ) ;
( * V_150 ) = 4 ;
return V_18 ;
}
static void F_82 ( char * V_111 , T_1 * V_155 )
{
T_4 V_147 , V_148 ;
F_71 ( & V_147 , ( V_156 / 2 ) ) ;
V_148 = ( V_147 ^ V_149 ) ;
F_83 ( V_147 , V_111 ) ;
V_111 += ( V_156 / 2 ) ;
F_83 ( V_148 , V_111 ) ;
( * V_155 ) = V_156 ;
}
void F_84 ( char * V_111 ,
struct V_7 * V_8 ,
T_1 * V_155 )
{
T_4 V_16 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < ( ( sizeof( V_151 )
/ sizeof( struct V_152 ) ) ) ; V_67 ++ )
if ( V_8 -> V_16 & V_151 [ V_67 ] . V_154 )
V_16 |= V_151 [ V_67 ] . V_153 ;
V_16 |= ( ( ( ( V_20 ) V_8 -> V_142 ) << 24 ) & 0xFF000000 ) ;
F_83 ( V_16 , V_111 ) ;
( * V_155 ) = 4 ;
}
V_20 F_85 ( char * V_27 , T_1 V_157 )
{
int V_67 ;
V_20 V_158 = 0 ;
struct V_159 * V_160 =
V_161 ;
if ( strcmp ( V_27 , L_44 ) == 0 ) {
switch ( V_157 ) {
case 16 :
V_158 = V_162 ;
break;
case 24 :
V_158 = V_163 ;
break;
case 32 :
V_158 = V_164 ;
}
} else {
for ( V_67 = 0 ; V_67 < F_86 ( V_161 ) ; V_67 ++ )
if ( strcmp ( V_27 , V_160 [ V_67 ] . V_165 ) == 0 ) {
V_158 = V_160 [ V_67 ] . V_166 ;
break;
}
}
return V_158 ;
}
int F_87 ( char * V_167 , V_20 V_166 )
{
int V_18 = 0 ;
int V_67 ;
V_167 [ 0 ] = '\0' ;
for ( V_67 = 0 ; V_67 < F_86 ( V_161 ) ; V_67 ++ )
if ( V_166 == V_161 [ V_67 ] . V_166 )
strcpy ( V_167 , V_161 [ V_67 ] . V_165 ) ;
if ( V_167 [ 0 ] == '\0' ) {
F_10 ( V_42 , L_45
L_46 , V_166 ) ;
V_18 = - V_89 ;
}
return V_18 ;
}
int F_88 ( struct V_102 * V_102 )
{
V_20 V_168 [ V_169 ] ;
V_20 * V_170 = V_168 + V_171 ;
int V_18 ;
V_18 = F_62 ( V_168 , 0 , V_169 ,
V_102 ) ;
if ( V_18 < V_169 )
return V_18 >= 0 ? - V_89 : V_18 ;
V_18 = F_79 ( V_170 ) ;
if ( ! V_18 )
F_89 ( V_168 , V_102 ) ;
return V_18 ;
}
void
F_90 ( char * V_172 ,
struct V_7 * V_8 ,
T_1 * V_155 )
{
T_4 V_173 ;
T_5 V_174 ;
V_173 = ( T_4 ) V_8 -> V_101 ;
V_174 =
( T_5 ) ( V_8 -> V_124 / V_8 -> V_101 ) ;
F_83 ( V_173 , V_172 ) ;
V_172 += 4 ;
F_91 ( V_174 , V_172 ) ;
( * V_155 ) = 6 ;
}
static int F_92 ( char * V_111 , T_1 V_175 ,
T_1 * V_65 ,
struct V_7 * V_8 ,
struct V_176 * V_177 )
{
int V_18 ;
T_1 V_155 ;
T_1 V_35 ;
V_35 = V_171 ;
F_82 ( ( V_111 + V_35 ) , & V_155 ) ;
V_35 += V_155 ;
F_84 ( ( V_111 + V_35 ) , V_8 ,
& V_155 ) ;
V_35 += V_155 ;
F_90 ( ( V_111 + V_35 ) , V_8 ,
& V_155 ) ;
V_35 += V_155 ;
V_18 = F_93 ( ( V_111 + V_35 ) , V_8 ,
V_177 , & V_155 ,
V_175 - V_35 ) ;
if ( V_18 )
F_10 ( V_42 , L_47
L_48 , V_18 ) ;
if ( V_65 ) {
V_35 += V_155 ;
* V_65 = V_35 ;
}
return V_18 ;
}
static int
F_94 ( struct V_102 * V_103 ,
char * V_172 , T_1 V_178 )
{
int V_18 ;
V_18 = F_58 ( V_103 , V_172 ,
0 , V_178 ) ;
if ( V_18 < 0 )
F_12 ( V_23 L_49
L_50 , V_25 , V_18 ) ;
else
V_18 = 0 ;
return V_18 ;
}
static int
F_95 ( struct V_176 * V_177 ,
char * V_111 , T_1 V_65 )
{
int V_18 ;
V_18 = F_96 ( V_177 , V_179 , V_111 ,
V_65 , 0 ) ;
return V_18 ;
}
static unsigned long F_97 ( T_6 V_180 ,
unsigned int V_181 )
{
struct V_68 * V_68 ;
V_68 = F_98 ( V_180 | V_182 , V_181 ) ;
if ( V_68 )
return ( unsigned long ) F_99 ( V_68 ) ;
return 0 ;
}
int F_100 ( struct V_176 * V_177 ,
struct V_102 * V_103 )
{
struct V_7 * V_8 =
& F_55 ( V_103 ) -> V_8 ;
unsigned int V_181 ;
char * V_172 ;
T_1 V_178 ;
T_1 V_65 = 0 ;
int V_18 = 0 ;
if ( F_101 ( V_8 -> V_16 & V_109 ) ) {
if ( ! ( V_8 -> V_16 & V_126 ) ) {
F_12 ( V_23 L_51 ) ;
V_18 = - V_89 ;
goto V_24;
}
} else {
F_12 ( V_42 L_52 ,
V_25 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_178 = V_8 -> V_124 ;
V_181 = F_102 ( V_178 ) ;
V_172 = ( char * ) F_97 ( V_32 , V_181 ) ;
if ( ! V_172 ) {
F_12 ( V_23 L_53 , V_25 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_18 = F_92 ( V_172 , V_178 , & V_65 , V_8 ,
V_177 ) ;
if ( F_19 ( V_18 ) ) {
F_12 ( V_23 L_54 ,
V_25 , V_18 ) ;
goto V_116;
}
if ( V_8 -> V_16 & V_123 )
V_18 = F_95 ( V_177 , V_172 ,
V_65 ) ;
else
V_18 = F_94 ( V_103 , V_172 ,
V_178 ) ;
if ( V_18 ) {
F_12 ( V_23 L_55
L_20 , V_25 , V_18 ) ;
goto V_116;
}
V_116:
F_103 ( ( unsigned long ) V_172 , V_181 ) ;
V_24:
return V_18 ;
}
static int F_104 ( struct V_7 * V_8 ,
char * V_172 , int * V_150 ,
int V_183 )
{
int V_18 = 0 ;
T_4 V_173 ;
T_5 V_174 ;
V_173 = F_80 ( V_172 ) ;
V_172 += sizeof( V_184 ) ;
V_174 = F_105 ( V_172 ) ;
V_8 -> V_124 = ( ( ( T_1 ) V_174
* ( T_1 ) V_173 ) ) ;
( * V_150 ) = ( sizeof( V_184 ) + sizeof( V_185 ) ) ;
if ( ( V_183 == V_186 )
&& ( V_8 -> V_124
< V_125 ) ) {
V_18 = - V_89 ;
F_12 ( V_42 L_56 ,
V_8 -> V_124 ) ;
}
return V_18 ;
}
static void F_106 ( struct V_7 * V_8 )
{
V_8 -> V_124 = V_125 ;
}
void F_89 ( const char * V_111 , struct V_102 * V_102 )
{
struct V_53 * V_54 ;
struct V_7 * V_8 ;
T_7 V_168 ;
V_8 = & F_55 ( V_102 ) -> V_8 ;
V_54 =
& F_78 ( V_102 -> V_144 ) -> V_54 ;
if ( V_54 -> V_16 & V_129 ) {
V_168 = F_107 ( F_108 ( V_102 ) ) ;
if ( V_8 -> V_16 & V_123 )
V_168 += V_8 -> V_124 ;
} else
V_168 = F_109 ( V_111 ) ;
F_110 ( V_102 , ( T_2 ) V_168 ) ;
V_8 -> V_16 |= V_187 ;
}
static int F_111 ( char * V_111 ,
struct V_7 * V_8 ,
struct V_176 * V_177 ,
int V_183 )
{
int V_18 = 0 ;
int V_35 ;
int V_150 ;
F_68 ( V_8 ) ;
V_8 -> V_54 = & F_78 (
V_177 -> V_188 ) -> V_54 ;
V_35 = V_171 ;
V_18 = F_79 ( V_111 + V_35 ) ;
if ( V_18 )
goto V_24;
if ( ! ( V_8 -> V_16 & V_187 ) )
F_89 ( V_111 , F_112 ( V_177 ) ) ;
V_35 += V_156 ;
V_18 = F_81 ( V_8 , ( V_111 + V_35 ) ,
& V_150 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_57 ) ;
goto V_24;
}
if ( V_8 -> V_142 > V_189 ) {
F_10 ( V_42 , L_58
L_59
L_60 ,
V_8 -> V_142 ,
V_189 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_35 += V_150 ;
if ( V_8 -> V_142 >= 1 ) {
V_18 = F_104 ( V_8 , ( V_111 + V_35 ) ,
& V_150 , V_183 ) ;
if ( V_18 ) {
F_10 ( V_42 , L_61
L_62 , V_18 ) ;
}
V_35 += V_150 ;
} else
F_106 ( V_8 ) ;
V_18 = F_113 ( V_8 , ( V_111 + V_35 ) ,
V_177 ) ;
V_24:
return V_18 ;
}
int F_114 ( char * V_111 , struct V_102 * V_103 )
{
struct V_176 * V_190 =
F_55 ( V_103 ) -> V_191 -> V_192 . V_176 ;
T_8 V_65 ;
int V_18 = 0 ;
V_65 = F_115 ( V_190 , V_179 ,
V_111 , V_121 ) ;
if ( V_65 < 0 ) {
if ( F_19 ( V_38 > 0 ) )
F_12 ( V_193 L_63
L_64
L_65 , V_179 , V_65 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_24:
return V_18 ;
}
int F_116 ( struct V_176 * V_176 ,
struct V_102 * V_102 )
{
V_20 V_168 [ V_169 ] ;
V_20 * V_170 = V_168 + V_171 ;
int V_18 ;
V_18 = F_115 ( F_117 ( V_176 ) ,
V_179 , V_168 ,
V_169 ) ;
if ( V_18 < V_169 )
return V_18 >= 0 ? - V_89 : V_18 ;
V_18 = F_79 ( V_170 ) ;
if ( ! V_18 )
F_89 ( V_168 , V_102 ) ;
return V_18 ;
}
int F_118 ( struct V_176 * V_177 )
{
int V_18 ;
char * V_111 ;
struct V_102 * V_103 = F_112 ( V_177 ) ;
struct V_7 * V_8 =
& F_55 ( V_103 ) -> V_8 ;
struct V_53 * V_54 =
& F_78 (
V_177 -> V_188 ) -> V_54 ;
F_72 ( V_8 ,
V_54 ) ;
V_111 = F_119 ( V_194 , V_110 ) ;
if ( ! V_111 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_66 ,
V_25 ) ;
goto V_24;
}
V_18 = F_62 ( V_111 , 0 , V_8 -> V_101 ,
V_103 ) ;
if ( V_18 >= 0 )
V_18 = F_111 ( V_111 , V_8 ,
V_177 ,
V_186 ) ;
if ( V_18 ) {
memset ( V_111 , 0 , V_71 ) ;
V_18 = F_114 ( V_111 , V_103 ) ;
if ( V_18 ) {
F_12 ( V_39 L_67
L_68 ,
V_103 -> V_195 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_18 = F_111 ( V_111 , V_8 ,
V_177 ,
V_196 ) ;
if ( V_18 ) {
F_12 ( V_39 L_67
L_69 ,
V_103 -> V_195 ) ;
V_18 = - V_89 ;
}
if ( V_8 -> V_54 -> V_16
& V_128 ) {
V_8 -> V_16 |= V_123 ;
} else {
F_12 ( V_42 L_70
L_71
L_72
L_73
L_74 ,
V_103 -> V_195 ) ;
V_18 = - V_89 ;
}
}
V_24:
if ( V_111 ) {
memset ( V_111 , 0 , V_71 ) ;
F_29 ( V_194 , V_111 ) ;
}
return V_18 ;
}
static int
F_120 ( struct V_197 * V_198 ,
struct V_7 * V_8 ,
struct V_53 * V_54 )
{
int V_18 = 0 ;
V_198 -> V_199 = NULL ;
V_198 -> V_200 = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_134 ) )
|| ( V_54 && ( V_54 -> V_16
& V_133 ) ) ) {
T_1 V_201 ;
T_1 V_202 ;
V_18 = F_121 (
NULL , NULL ,
& V_198 -> V_200 ,
V_54 , NULL ,
V_198 -> V_203 ) ;
if ( V_18 ) {
F_12 ( V_23 L_75
L_76 , V_25 ,
V_18 ) ;
V_198 -> V_200 = 0 ;
goto V_24;
}
V_198 -> V_199 =
F_17 ( V_198 -> V_200 , V_32 ) ;
if ( ! V_198 -> V_199 ) {
F_12 ( V_23 L_77
L_78 , V_25 ,
V_198 -> V_200 ) ;
V_18 = - V_33 ;
goto V_24;
}
V_202 = V_198 -> V_200 ;
V_18 = F_121 ( V_198 -> V_199 ,
& V_202 ,
& V_201 ,
V_54 ,
V_198 -> V_198 ,
V_198 -> V_203 ) ;
if ( V_18 ) {
F_12 ( V_23 L_79
L_80 , V_25 ,
V_18 ) ;
F_66 ( V_198 -> V_199 ) ;
V_198 -> V_199 = NULL ;
V_198 -> V_200 = 0 ;
goto V_24;
}
V_198 -> V_200 = V_201 ;
} else {
F_12 ( V_23 L_81
L_82 , V_25 ) ;
V_18 = - V_204 ;
goto V_24;
}
V_24:
return V_18 ;
}
static int F_122 ( char * * V_205 , T_1 * V_206 ,
const char * V_207 , T_1 V_208 )
{
int V_18 = 0 ;
( * V_205 ) = F_17 ( ( V_208 + 1 ) , V_32 ) ;
if ( ! ( * V_205 ) ) {
V_18 = - V_33 ;
goto V_24;
}
memcpy ( ( void * ) ( * V_205 ) , ( void * ) V_207 , V_208 ) ;
( * V_205 ) [ ( V_208 ) ] = '\0' ;
( * V_206 ) = V_208 ;
V_24:
return V_18 ;
}
static int
F_123 ( struct V_209 * * V_210 ,
char * V_27 , T_1 * V_84 )
{
char V_211 [ V_212 ] ;
char * V_113 = NULL ;
int V_18 ;
* V_210 = NULL ;
if ( * V_84 > V_212 ) {
V_18 = - V_89 ;
F_12 ( V_23 L_83
L_84 , * V_84 , V_212 ) ;
goto V_24;
}
V_18 = F_16 ( & V_113 , V_27 ,
L_85 ) ;
if ( V_18 )
goto V_24;
* V_210 = F_124 ( V_113 , 0 , V_22 ) ;
if ( F_8 ( * V_210 ) ) {
V_18 = F_9 ( * V_210 ) ;
F_12 ( V_23 L_86
L_87 , V_113 , V_18 ) ;
goto V_24;
}
F_125 ( * V_210 , V_117 ) ;
if ( * V_84 == 0 ) {
struct V_213 * V_214 = F_126 ( * V_210 ) ;
* V_84 = V_214 -> V_215 ;
}
F_71 ( V_211 , * V_84 ) ;
V_18 = F_127 ( * V_210 , V_211 , * V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_88
L_89 , * V_84 , V_113 ,
V_18 ) ;
V_18 = - V_89 ;
goto V_24;
}
V_24:
F_66 ( V_113 ) ;
return V_18 ;
}
int T_9 F_128 ( void )
{
F_23 ( & V_216 ) ;
F_22 ( & V_217 ) ;
return 0 ;
}
int F_129 ( void )
{
struct V_218 * V_210 , * V_219 ;
F_5 ( & V_216 ) ;
F_27 (key_tfm, key_tfm_tmp, &key_tfm_list,
key_tfm_list) {
F_28 ( & V_210 -> V_217 ) ;
if ( V_210 -> V_210 )
F_130 ( V_210 -> V_210 ) ;
F_29 ( V_220 , V_210 ) ;
}
F_15 ( & V_216 ) ;
return 0 ;
}
int
F_131 ( struct V_218 * * V_210 , char * V_27 ,
T_1 V_84 )
{
struct V_218 * V_221 ;
int V_18 = 0 ;
F_40 ( ! F_132 ( & V_216 ) ) ;
V_221 = F_119 ( V_220 , V_32 ) ;
if ( V_210 != NULL )
( * V_210 ) = V_221 ;
if ( ! V_221 ) {
V_18 = - V_33 ;
F_12 ( V_23 L_90
L_91 ) ;
goto V_24;
}
F_23 ( & V_221 -> V_222 ) ;
strncpy ( V_221 -> V_27 , V_27 ,
V_223 ) ;
V_221 -> V_27 [ V_223 ] = '\0' ;
V_221 -> V_84 = V_84 ;
V_18 = F_123 ( & V_221 -> V_210 ,
V_221 -> V_27 ,
& V_221 -> V_84 ) ;
if ( V_18 ) {
F_12 ( V_23 L_92
L_93 ,
V_221 -> V_27 , V_18 ) ;
F_29 ( V_220 , V_221 ) ;
if ( V_210 != NULL )
( * V_210 ) = NULL ;
goto V_24;
}
F_133 ( & V_221 -> V_217 , & V_217 ) ;
V_24:
return V_18 ;
}
int F_134 ( char * V_27 , struct V_218 * * V_210 )
{
struct V_218 * V_224 ;
F_40 ( ! F_132 ( & V_216 ) ) ;
F_74 (tmp_key_tfm, &key_tfm_list, key_tfm_list) {
if ( strcmp ( V_224 -> V_27 , V_27 ) == 0 ) {
if ( V_210 )
( * V_210 ) = V_224 ;
return 1 ;
}
}
if ( V_210 )
( * V_210 ) = NULL ;
return 0 ;
}
int F_135 ( struct V_209 * * V_14 ,
struct V_225 * * V_226 ,
char * V_27 )
{
struct V_218 * V_210 ;
int V_18 = 0 ;
( * V_14 ) = NULL ;
( * V_226 ) = NULL ;
F_5 ( & V_216 ) ;
if ( ! F_134 ( V_27 , & V_210 ) ) {
V_18 = F_131 ( & V_210 , V_27 , 0 ) ;
if ( V_18 ) {
F_12 ( V_23 L_94
L_20 , V_18 ) ;
goto V_24;
}
}
( * V_14 ) = V_210 -> V_210 ;
( * V_226 ) = & V_210 -> V_222 ;
V_24:
F_15 ( & V_216 ) ;
return V_18 ;
}
static void F_136 ( unsigned char * V_1 , T_1 * V_5 ,
unsigned char * V_2 , T_1 V_3 )
{
T_1 V_227 ;
T_1 V_228 = 0 ;
T_1 V_229 = 0 ;
unsigned char V_230 [ 3 ] ;
if ( V_3 == 0 ) {
( * V_5 ) = 0 ;
goto V_24;
}
V_227 = ( V_3 / 3 ) ;
if ( ( V_3 % 3 ) == 0 ) {
memcpy ( V_230 , ( & V_2 [ V_3 - 3 ] ) , 3 ) ;
} else {
V_227 ++ ;
V_230 [ 2 ] = 0x00 ;
switch ( V_3 % 3 ) {
case 1 :
V_230 [ 0 ] = V_2 [ V_3 - 1 ] ;
V_230 [ 1 ] = 0x00 ;
break;
case 2 :
V_230 [ 0 ] = V_2 [ V_3 - 2 ] ;
V_230 [ 1 ] = V_2 [ V_3 - 1 ] ;
}
}
( * V_5 ) = ( V_227 * 4 ) ;
if ( ! V_1 )
goto V_24;
while ( V_228 < V_227 ) {
unsigned char * V_231 ;
unsigned char V_232 [ 4 ] ;
if ( V_228 == ( V_227 - 1 ) )
V_231 = V_230 ;
else
V_231 = & V_2 [ V_228 * 3 ] ;
V_232 [ 0 ] = ( ( V_231 [ 0 ] >> 2 ) & 0x3F ) ;
V_232 [ 1 ] = ( ( ( V_231 [ 0 ] << 4 ) & 0x30 )
| ( ( V_231 [ 1 ] >> 4 ) & 0x0F ) ) ;
V_232 [ 2 ] = ( ( ( V_231 [ 1 ] << 2 ) & 0x3C )
| ( ( V_231 [ 2 ] >> 6 ) & 0x03 ) ) ;
V_232 [ 3 ] = ( V_231 [ 2 ] & 0x3F ) ;
V_1 [ V_229 ++ ] = V_233 [ V_232 [ 0 ] ] ;
V_1 [ V_229 ++ ] = V_233 [ V_232 [ 1 ] ] ;
V_1 [ V_229 ++ ] = V_233 [ V_232 [ 2 ] ] ;
V_1 [ V_229 ++ ] = V_233 [ V_232 [ 3 ] ] ;
V_228 ++ ;
}
V_24:
return;
}
static T_1 F_137 ( T_1 V_234 )
{
return ( ( V_234 + 1 ) * 3 ) / 4 ;
}
static void
F_138 ( unsigned char * V_1 , T_1 * V_5 ,
const unsigned char * V_2 , T_1 V_3 )
{
V_20 V_235 = 0 ;
T_1 V_236 = 0 ;
T_1 V_237 = 0 ;
if ( V_1 == NULL ) {
( * V_5 ) = F_137 ( V_3 ) ;
goto V_24;
}
while ( V_236 < V_3 ) {
unsigned char V_238 =
V_239 [ ( int ) V_2 [ V_236 ] ] ;
switch ( V_235 ) {
case 0 :
V_1 [ V_237 ] = ( V_238 << 2 ) ;
V_235 = 6 ;
break;
case 6 :
V_1 [ V_237 ++ ] |= ( V_238 >> 4 ) ;
V_1 [ V_237 ] = ( ( V_238 & 0xF )
<< 4 ) ;
V_235 = 4 ;
break;
case 4 :
V_1 [ V_237 ++ ] |= ( V_238 >> 2 ) ;
V_1 [ V_237 ] = ( V_238 << 6 ) ;
V_235 = 2 ;
break;
case 2 :
V_1 [ V_237 ++ ] |= ( V_238 ) ;
V_235 = 0 ;
break;
}
V_236 ++ ;
}
( * V_5 ) = V_237 ;
V_24:
return;
}
int F_139 (
char * * V_240 ,
T_1 * V_241 ,
struct V_7 * V_8 ,
struct V_53 * V_54 ,
const char * V_207 , T_1 V_208 )
{
T_1 V_242 ;
int V_18 = 0 ;
( * V_240 ) = NULL ;
( * V_241 ) = 0 ;
if ( ( V_8 && ( V_8 -> V_16 & V_132 ) )
|| ( V_54 && ( V_54 -> V_16
& V_131 ) ) ) {
struct V_197 * V_198 ;
V_198 = F_140 ( sizeof( * V_198 ) , V_32 ) ;
if ( ! V_198 ) {
F_12 ( V_23 L_77
L_95 , V_25 ,
sizeof( * V_198 ) ) ;
V_18 = - V_33 ;
goto V_24;
}
V_198 -> V_198 = ( char * ) V_207 ;
V_198 -> V_203 = V_208 ;
V_18 = F_120 ( V_198 , V_8 ,
V_54 ) ;
if ( V_18 ) {
F_12 ( V_23 L_96
L_97 , V_25 , V_18 ) ;
F_66 ( V_198 ) ;
goto V_24;
}
F_136 (
NULL , & V_242 ,
V_198 -> V_199 ,
V_198 -> V_200 ) ;
if ( ( V_8 && ( V_8 -> V_16
& V_134 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_133 ) ) )
( * V_241 ) =
( V_243
+ V_242 ) ;
else
( * V_241 ) =
( V_244
+ V_242 ) ;
( * V_240 ) = F_17 ( ( * V_241 ) + 1 , V_32 ) ;
if ( ! ( * V_240 ) ) {
F_12 ( V_23 L_77
L_95 , V_25 ,
( * V_241 ) ) ;
V_18 = - V_33 ;
F_66 ( V_198 -> V_199 ) ;
F_66 ( V_198 ) ;
goto V_24;
}
if ( ( V_8 && ( V_8 -> V_16
& V_134 ) )
|| ( V_54
&& ( V_54 -> V_16
& V_133 ) ) ) {
memcpy ( ( * V_240 ) ,
V_245 ,
V_243 ) ;
F_136 (
( ( * V_240 )
+ V_243 ) ,
& V_242 ,
V_198 -> V_199 ,
V_198 -> V_200 ) ;
( * V_241 ) =
( V_243
+ V_242 ) ;
( * V_240 ) [ ( * V_241 ) ] = '\0' ;
} else {
V_18 = - V_204 ;
}
if ( V_18 ) {
F_12 ( V_23 L_98
L_99 , V_25 ,
V_18 ) ;
F_66 ( ( * V_240 ) ) ;
( * V_240 ) = NULL ;
( * V_241 ) = 0 ;
}
F_66 ( V_198 -> V_199 ) ;
F_66 ( V_198 ) ;
} else {
V_18 = F_122 ( V_240 ,
V_241 ,
V_207 , V_208 ) ;
}
V_24:
return V_18 ;
}
int F_141 ( char * * V_246 ,
T_1 * V_247 ,
struct V_248 * V_249 ,
const char * V_207 , T_1 V_208 )
{
struct V_53 * V_54 =
& F_78 ( V_249 ) -> V_54 ;
char * V_250 ;
T_1 V_251 ;
T_1 V_201 ;
int V_18 = 0 ;
if ( ( V_54 -> V_16 & V_131 )
&& ! ( V_54 -> V_16 & V_129 )
&& ( V_208 > V_243 )
&& ( strncmp ( V_207 , V_245 ,
V_243 ) == 0 ) ) {
const char * V_252 = V_207 ;
T_1 V_253 = V_208 ;
V_207 += V_243 ;
V_208 -= V_243 ;
F_138 ( NULL , & V_251 ,
V_207 , V_208 ) ;
V_250 = F_17 ( V_251 , V_32 ) ;
if ( ! V_250 ) {
F_12 ( V_23 L_77
L_78 , V_25 ,
V_251 ) ;
V_18 = - V_33 ;
goto V_24;
}
F_138 ( V_250 , & V_251 ,
V_207 , V_208 ) ;
V_18 = F_142 ( V_246 ,
V_247 ,
& V_201 ,
V_54 ,
V_250 ,
V_251 ) ;
if ( V_18 ) {
F_12 ( V_193 L_100
L_101
L_102 , V_25 ) ;
V_18 = F_122 ( V_246 ,
V_247 ,
V_252 , V_253 ) ;
goto V_116;
}
} else {
V_18 = F_122 ( V_246 ,
V_247 ,
V_207 , V_208 ) ;
goto V_24;
}
V_116:
F_66 ( V_250 ) ;
V_24:
return V_18 ;
}
int F_143 ( long * V_254 , long V_255 ,
struct V_53 * V_54 )
{
struct V_256 V_13 ;
struct V_225 * V_226 ;
T_1 V_257 ;
int V_18 ;
if ( ! ( V_54 -> V_16 & V_131 ) ) {
( * V_254 ) = V_255 ;
return 0 ;
}
V_18 = F_135 ( & V_13 . V_14 , & V_226 ,
V_54 -> V_258 ) ;
if ( F_19 ( V_18 ) ) {
( * V_254 ) = 0 ;
return V_18 ;
}
F_5 ( V_226 ) ;
V_257 = F_144 ( V_13 . V_14 ) ;
F_15 ( V_226 ) ;
if ( V_255 == V_259
&& ( V_257 == 8 || V_257 == 16 ) ) {
( * V_254 ) = V_260 ;
return 0 ;
}
( * V_254 ) = V_255 ;
( * V_254 ) -= V_243 ;
( * V_254 ) = F_137 ( * V_254 ) - 3 ;
( * V_254 ) -= V_261 ;
( * V_254 ) -= V_262 ;
( * V_254 ) -= V_257 - 1 ;
if ( ( * V_254 ) < 0 )
( * V_254 ) = 0 ;
return 0 ;
}
