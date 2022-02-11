void
F_1 ( char * V_1 , void * V_2 , int V_3 )
{
int V_4 , V_5 ;
int * V_6 = V_2 ;
char * V_7 = V_2 ;
char V_8 [ 10 ] , line [ 80 ] ;
F_2 ( V_9 L_1 ,
V_1 , V_3 , V_2 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 += 16 ) {
line [ 0 ] = 0 ;
for ( V_5 = 0 ; ( V_5 < 4 ) && ( V_4 + V_5 * 4 < V_3 ) ; V_5 ++ ) {
sprintf ( V_8 , L_2 , V_6 [ V_4 / 4 + V_5 ] ) ;
strcat ( line , V_8 ) ;
}
V_8 [ 0 ] = ' ' ;
V_8 [ 2 ] = 0 ;
for ( V_5 = 0 ; ( V_5 < 16 ) && ( V_4 + V_5 < V_3 ) ; V_5 ++ ) {
V_8 [ 1 ] = isprint ( V_7 [ V_4 + V_5 ] ) ? V_7 [ V_4 + V_5 ] : '.' ;
strcat ( line , V_8 ) ;
}
F_2 ( V_9 L_3 , line ) ;
}
}
void F_3 ( struct V_10 * V_11 )
{
F_4 ( 1 , L_4 ,
V_11 -> V_12 , V_11 -> V_13 . V_14 ,
V_11 -> V_15 , V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ) ;
F_4 ( 1 , L_5 , V_11 , F_5 ( V_11 ) ) ;
}
void F_6 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( V_20 == NULL )
return;
F_4 ( 1 , L_6 ) ;
F_7 ( & V_25 ) ;
F_8 (tmp, &server->pending_mid_q) {
V_24 = F_9 ( V_22 , struct V_23 , V_26 ) ;
F_4 ( 1 , L_7 ,
V_24 -> V_27 ,
( int ) V_24 -> V_28 ,
V_24 -> V_29 ,
V_24 -> V_30 ,
V_24 -> V_31 ) ;
#ifdef F_10
F_4 ( 1 , L_8 ,
V_24 -> V_32 ,
V_24 -> V_33 ,
V_24 -> V_34 ,
V_35 ) ;
#endif
F_4 ( 1 , L_9 , V_24 -> V_36 ,
V_24 -> V_37 ) ;
if ( V_24 -> V_33 ) {
F_3 ( V_24 -> V_33 ) ;
F_1 ( L_10 ,
V_24 -> V_33 , 62 ) ;
}
}
F_11 ( & V_25 ) ;
}
static int F_12 ( struct V_38 * V_39 , void * V_40 )
{
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_23 * V_24 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_4 , V_5 ;
T_1 V_48 ;
F_13 ( V_39 ,
L_11
L_12 ) ;
F_14 ( V_39 , L_13 , V_49 ) ;
F_14 ( V_39 , L_14 ) ;
#ifdef F_15
F_14 ( V_39 , L_15 ) ;
#endif
#ifdef F_16
F_14 ( V_39 , L_16 ) ;
#endif
#ifdef F_17
F_14 ( V_39 , L_17 ) ;
#endif
#ifdef F_18
F_14 ( V_39 , L_18 ) ;
#endif
#ifdef F_19
F_14 ( V_39 , L_19 ) ;
#endif
#ifdef F_20
F_14 ( V_39 , L_20 ) ;
#endif
#ifdef F_21
F_14 ( V_39 , L_21 ) ;
#endif
F_22 ( V_39 , '\n' ) ;
F_14 ( V_39 , L_22 , V_50 ) ;
F_14 ( V_39 , L_23 ) ;
V_4 = 0 ;
F_7 ( & V_51 ) ;
F_8 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_9 ( V_41 , struct V_19 ,
V_52 ) ;
V_4 ++ ;
F_8 (tmp2, &server->smb_ses_list) {
V_45 = F_9 ( V_42 , struct V_44 ,
V_53 ) ;
if ( ( V_45 -> V_54 == NULL ) ||
( V_45 -> V_55 == NULL ) ||
( V_45 -> V_56 == NULL ) ) {
F_14 ( V_39 , L_24
L_25 , V_4 , V_45 -> V_57 ) ;
} else {
F_14 ( V_39 ,
L_26
L_27
L_28 ,
V_4 , V_45 -> V_57 , V_45 -> V_54 ,
V_45 -> V_58 , V_45 -> V_55 , V_45 -> V_56 ,
V_45 -> V_59 , V_45 -> V_60 ) ;
}
F_14 ( V_39 , L_29
L_30 ,
V_20 -> V_61 , V_20 -> V_62 ,
V_20 -> V_63 ,
F_23 ( & V_20 -> V_64 ) ) ;
#ifdef F_10
F_14 ( V_39 , L_31 ,
F_23 ( & V_20 -> V_65 ) ,
F_23 ( & V_20 -> V_66 ) ) ;
#endif
F_13 ( V_39 , L_32 ) ;
V_5 = 0 ;
F_8 (tmp3, &ses->tcon_list) {
V_47 = F_9 ( V_43 , struct V_46 ,
V_67 ) ;
++ V_5 ;
V_48 = F_24 ( V_47 -> V_68 . V_69 ) ;
F_14 ( V_39 , L_33 , V_5 ,
V_47 -> V_70 , V_47 -> V_71 ) ;
if ( V_47 -> V_72 ) {
F_14 ( V_39 , L_34 ,
V_47 -> V_72 ) ;
}
F_14 ( V_39 , L_35
L_36 ,
F_24 ( V_47 -> V_68 . V_73 ) ,
F_24 ( V_47 -> V_74 . V_75 ) ,
F_24 ( V_47 -> V_74 . V_76 ) ,
V_47 -> V_77 ) ;
if ( V_48 == V_78 )
F_13 ( V_39 , L_37 ) ;
else if ( V_48 == V_79 )
F_13 ( V_39 , L_38 ) ;
else
F_14 ( V_39 , L_39 , V_48 ) ;
if ( V_47 -> V_80 )
F_13 ( V_39 , L_40 ) ;
F_22 ( V_39 , '\n' ) ;
}
F_13 ( V_39 , L_41 ) ;
F_7 ( & V_25 ) ;
F_8 (tmp3, &server->pending_mid_q) {
V_24 = F_9 ( V_43 , struct V_23 ,
V_26 ) ;
F_14 ( V_39 , L_42
L_43 ,
V_24 -> V_27 ,
( int ) V_24 -> V_28 ,
V_24 -> V_29 ,
V_24 -> V_30 ,
V_24 -> V_31 ) ;
}
F_11 ( & V_25 ) ;
}
}
F_11 ( & V_51 ) ;
F_22 ( V_39 , '\n' ) ;
return 0 ;
}
static int F_25 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_12 , NULL ) ;
}
static T_2 F_27 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' || V_86 == '0' ) {
#ifdef F_10
F_29 ( & V_88 , 0 ) ;
F_29 ( & V_89 , 0 ) ;
#endif
F_7 ( & V_51 ) ;
F_8 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_9 ( V_41 , struct V_19 ,
V_52 ) ;
F_8 (tmp2, &server->smb_ses_list) {
V_45 = F_9 ( V_42 , struct V_44 ,
V_53 ) ;
F_8 (tmp3, &ses->tcon_list) {
V_47 = F_9 ( V_43 ,
struct V_46 ,
V_67 ) ;
F_29 ( & V_47 -> V_90 , 0 ) ;
F_29 ( & V_47 -> V_91 , 0 ) ;
F_29 ( & V_47 -> V_92 , 0 ) ;
F_29 ( & V_47 -> V_93 , 0 ) ;
F_29 ( & V_47 -> V_94 , 0 ) ;
F_29 ( & V_47 -> V_95 , 0 ) ;
F_29 ( & V_47 -> V_96 , 0 ) ;
F_29 ( & V_47 -> V_97 , 0 ) ;
F_29 ( & V_47 -> V_98 , 0 ) ;
F_29 ( & V_47 -> V_99 , 0 ) ;
F_29 ( & V_47 -> V_100 , 0 ) ;
F_29 ( & V_47 -> V_101 , 0 ) ;
F_29 ( & V_47 -> V_102 , 0 ) ;
F_29 ( & V_47 -> V_103 , 0 ) ;
F_29 ( & V_47 -> V_104 , 0 ) ;
F_29 ( & V_47 -> V_105 , 0 ) ;
F_29 ( & V_47 -> V_106 , 0 ) ;
F_29 ( & V_47 -> V_107 , 0 ) ;
F_29 ( & V_47 -> V_108 , 0 ) ;
}
}
}
F_11 ( & V_51 ) ;
}
return V_84 ;
}
static int F_30 ( struct V_38 * V_39 , void * V_40 )
{
int V_4 ;
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
F_14 ( V_39 ,
L_44 ,
V_109 . V_110 ) ;
F_14 ( V_39 , L_45 ,
V_111 . V_110 ) ;
F_14 ( V_39 , L_46 ,
V_112 . V_110 ,
V_113 + V_114 . V_110 ) ;
F_14 ( V_39 , L_47 ,
V_115 . V_110 , V_116 ) ;
#ifdef F_10
F_14 ( V_39 , L_48 ,
F_23 ( & V_88 ) ,
F_23 ( & V_89 ) ) ;
#endif
F_14 ( V_39 , L_49 , F_23 ( & V_117 ) ) ;
F_14 ( V_39 ,
L_50 ,
V_118 . V_110 , V_119 . V_110 ) ;
F_14 ( V_39 ,
L_51 ,
V_120 , V_121 ) ;
V_4 = 0 ;
F_7 ( & V_51 ) ;
F_8 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_9 ( V_41 , struct V_19 ,
V_52 ) ;
F_8 (tmp2, &server->smb_ses_list) {
V_45 = F_9 ( V_42 , struct V_44 ,
V_53 ) ;
F_8 (tmp3, &ses->tcon_list) {
V_47 = F_9 ( V_43 ,
struct V_46 ,
V_67 ) ;
V_4 ++ ;
F_14 ( V_39 , L_52 , V_4 , V_47 -> V_70 ) ;
if ( V_47 -> V_80 )
F_13 ( V_39 , L_40 ) ;
F_14 ( V_39 , L_53 ,
F_23 ( & V_47 -> V_90 ) ,
F_23 ( & V_47 -> V_93 ) ) ;
F_14 ( V_39 , L_54 ,
F_23 ( & V_47 -> V_92 ) ,
( long long ) ( V_47 -> V_122 ) ) ;
F_14 ( V_39 , L_55 ,
F_23 ( & V_47 -> V_91 ) ,
( long long ) ( V_47 -> V_123 ) ) ;
F_14 ( V_39 , L_56 ,
F_23 ( & V_47 -> V_124 ) ) ;
F_14 ( V_39 , L_57
L_58 ,
F_23 ( & V_47 -> V_108 ) ,
F_23 ( & V_47 -> V_106 ) ,
F_23 ( & V_47 -> V_107 ) ) ;
F_14 ( V_39 , L_59
L_60 ,
F_23 ( & V_47 -> V_94 ) ,
F_23 ( & V_47 -> V_97 ) ,
F_23 ( & V_47 -> V_98 ) ) ;
F_14 ( V_39 , L_61
L_62 ,
F_23 ( & V_47 -> V_95 ) ,
F_23 ( & V_47 -> V_96 ) ) ;
F_14 ( V_39 , L_63 ,
F_23 ( & V_47 -> V_99 ) ,
F_23 ( & V_47 -> V_100 ) ) ;
F_14 ( V_39 , L_64 ,
F_23 ( & V_47 -> V_101 ) ,
F_23 ( & V_47 -> V_102 ) ) ;
F_14 ( V_39 , L_65
L_66 ,
F_23 ( & V_47 -> V_103 ) ,
F_23 ( & V_47 -> V_104 ) ,
F_23 ( & V_47 -> V_105 ) ) ;
}
}
}
F_11 ( & V_51 ) ;
F_22 ( V_39 , '\n' ) ;
return 0 ;
}
static int F_31 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_30 , NULL ) ;
}
void
F_32 ( void )
{
V_125 = F_33 ( L_67 , NULL ) ;
if ( V_125 == NULL )
return;
F_34 ( L_68 , 0 , V_125 , & V_126 ) ;
#ifdef F_35
F_34 ( L_69 , 0 , V_125 , & V_127 ) ;
#endif
F_34 ( L_70 , 0 , V_125 , & V_128 ) ;
F_34 ( L_71 , 0 , V_125 , & V_129 ) ;
F_34 ( L_72 , 0 , V_125 , & V_130 ) ;
F_34 ( L_73 , 0 , V_125 ,
& V_131 ) ;
F_34 ( L_74 , 0 , V_125 ,
& V_132 ) ;
F_34 ( L_75 , 0 , V_125 ,
& V_133 ) ;
F_34 ( L_76 , 0 , V_125 ,
& V_134 ) ;
}
void
F_36 ( void )
{
if ( V_125 == NULL )
return;
F_37 ( L_68 , V_125 ) ;
F_37 ( L_70 , V_125 ) ;
F_37 ( L_71 , V_125 ) ;
#ifdef F_35
F_37 ( L_69 , V_125 ) ;
#endif
F_37 ( L_74 , V_125 ) ;
F_37 ( L_72 , V_125 ) ;
F_37 ( L_75 , V_125 ) ;
F_37 ( L_73 , V_125 ) ;
F_37 ( L_76 , V_125 ) ;
F_37 ( L_67 , NULL ) ;
}
static int F_38 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_135 ) ;
return 0 ;
}
static int F_39 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_38 , NULL ) ;
}
static T_2 F_40 ( struct V_82 * V_82 , const char T_3 * V_83 ,
T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_135 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_135 = 1 ;
else if ( ( V_86 > '1' ) && ( V_86 <= '9' ) )
V_135 = ( int ) ( V_86 - '0' ) ;
return V_84 ;
}
static int F_41 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_136 ) ;
return 0 ;
}
static int F_42 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_41 , NULL ) ;
}
static T_2 F_43 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_136 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_136 = 1 ;
return V_84 ;
}
static int F_44 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_137 ) ;
return 0 ;
}
static int F_45 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_44 , NULL ) ;
}
static T_2 F_46 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_137 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_137 = 1 ;
return V_84 ;
}
static int F_47 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_138 ) ;
return 0 ;
}
static int F_48 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_47 , NULL ) ;
}
static T_2 F_49 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_138 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_138 = 1 ;
return V_84 ;
}
static int F_50 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_139 ) ;
return 0 ;
}
static int F_51 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_50 , NULL ) ;
}
static T_2 F_52 ( struct V_82 * V_82 , const char T_3 * V_83 ,
T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_139 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_139 = 1 ;
return V_84 ;
}
static int F_53 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_77 , V_140 ) ;
return 0 ;
}
static int F_54 ( struct V_81 * V_81 , struct V_82 * V_141 )
{
return F_26 ( V_141 , F_53 , NULL ) ;
}
static T_2 F_55 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
char V_86 ;
int V_87 ;
V_87 = F_28 ( V_86 , V_83 ) ;
if ( V_87 )
return V_87 ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' )
V_140 = 0 ;
else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' )
V_140 = 1 ;
return V_84 ;
}
static int F_56 ( struct V_38 * V_39 , void * V_40 )
{
F_14 ( V_39 , L_78 , V_142 ) ;
return 0 ;
}
static int F_57 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_26 ( V_82 , F_56 , NULL ) ;
}
static T_2 F_58 ( struct V_82 * V_82 ,
const char T_3 * V_83 , T_4 V_84 , T_5 * V_85 )
{
unsigned int V_143 ;
char V_144 [ 12 ] ;
char V_86 ;
if ( ( V_84 < 1 ) || ( V_84 > 11 ) )
return - V_145 ;
memset ( V_144 , 0 , 12 ) ;
if ( F_59 ( V_144 , V_83 , V_84 ) )
return - V_146 ;
if ( V_84 < 3 ) {
V_86 = V_144 [ 0 ] ;
if ( V_86 == '0' || V_86 == 'n' || V_86 == 'N' ) {
V_142 = V_147 ;
return V_84 ;
} else if ( V_86 == '1' || V_86 == 'y' || V_86 == 'Y' ) {
V_142 = V_148 ;
return V_84 ;
} else if ( ! isdigit ( V_86 ) ) {
F_4 ( 1 , L_79 , V_86 ) ;
return - V_145 ;
}
}
V_143 = F_60 ( V_144 , NULL , 0 ) ;
F_61 ( 1 , L_80 , V_143 ) ;
if ( V_143 <= 0 ) {
F_4 ( 1 , L_81 , V_144 ) ;
return - V_145 ;
}
if ( V_143 & ~ V_149 ) {
F_4 ( 1 , L_82 ,
V_143 & ~ V_149 ) ;
return - V_145 ;
}
V_142 = V_143 ;
if ( V_142 & V_150 ) {
V_142 |= V_151 ;
F_61 ( 1 , L_83 ) ;
} else if ( ( V_142 & V_151 ) == 0 ) {
F_61 ( 1 , L_84 ) ;
}
return V_84 ;
}
inline void F_32 ( void )
{
}
inline void F_36 ( void )
{
}
