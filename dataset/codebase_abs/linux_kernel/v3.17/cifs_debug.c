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
void F_3 ( const char * V_10 , ... )
{
struct V_11 V_12 ;
T_1 args ;
va_start ( args , V_10 ) ;
V_12 . V_10 = V_10 ;
V_12 . V_13 = & args ;
F_2 ( V_14 L_4 , & V_12 ) ;
va_end ( args ) ;
}
void F_4 ( void * V_8 )
{
#ifdef F_5
struct V_15 * V_16 = (struct V_15 * ) V_8 ;
F_6 ( V_17 , L_5 ,
V_16 -> V_18 , V_16 -> V_19 . V_20 ,
V_16 -> V_21 , V_16 -> V_22 , V_16 -> V_23 , V_16 -> V_24 ) ;
F_6 ( V_17 , L_6 , V_16 , F_7 ( V_16 ) ) ;
#endif
}
void F_8 ( struct V_25 * V_26 )
{
#ifdef F_5
struct V_27 * V_28 ;
struct V_29 * V_30 ;
if ( V_26 == NULL )
return;
F_6 ( V_17 , L_7 ) ;
F_9 ( & V_31 ) ;
F_10 (tmp, &server->pending_mid_q) {
V_30 = F_11 ( V_28 , struct V_29 , V_32 ) ;
F_6 ( V_17 , L_8 ,
V_30 -> V_33 ,
F_12 ( V_30 -> V_34 ) ,
V_30 -> V_35 ,
V_30 -> V_36 ,
V_30 -> V_37 ) ;
#ifdef F_13
F_6 ( V_17 , L_9 ,
V_30 -> V_38 ,
V_30 -> V_39 ,
V_30 -> V_40 ,
V_41 ) ;
#endif
F_6 ( V_17 , L_10 ,
V_30 -> V_42 , V_30 -> V_43 ) ;
if ( V_30 -> V_39 ) {
F_4 ( V_30 -> V_39 ) ;
F_1 ( L_11 ,
V_30 -> V_39 , 62 ) ;
}
}
F_14 ( & V_31 ) ;
#endif
}
static int F_15 ( struct V_44 * V_45 , void * V_46 )
{
struct V_27 * V_47 , * V_48 , * V_49 ;
struct V_29 * V_30 ;
struct V_25 * V_26 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_4 , V_5 ;
T_2 V_54 ;
F_16 ( V_45 ,
L_12
L_13 ) ;
F_17 ( V_45 , L_14 , V_55 ) ;
F_17 ( V_45 , L_15 ) ;
#ifdef F_18
F_17 ( V_45 , L_16 ) ;
#endif
#ifdef F_19
F_17 ( V_45 , L_17 ) ;
#endif
#ifdef F_20
F_17 ( V_45 , L_18 ) ;
#endif
#ifdef F_21
F_17 ( V_45 , L_19 ) ;
#endif
#ifdef F_22
F_17 ( V_45 , L_20 ) ;
#endif
#ifdef F_23
F_17 ( V_45 , L_21 ) ;
#endif
#ifdef F_24
F_17 ( V_45 , L_22 ) ;
#endif
F_25 ( V_45 , '\n' ) ;
F_17 ( V_45 , L_23 , V_56 ) ;
F_17 ( V_45 , L_24 ) ;
V_4 = 0 ;
F_9 ( & V_57 ) ;
F_10 (tmp1, &cifs_tcp_ses_list) {
V_26 = F_11 ( V_47 , struct V_25 ,
V_58 ) ;
V_4 ++ ;
F_10 (tmp2, &server->smb_ses_list) {
V_51 = F_11 ( V_48 , struct V_50 ,
V_59 ) ;
if ( ( V_51 -> V_60 == NULL ) ||
( V_51 -> V_61 == NULL ) ||
( V_51 -> V_62 == NULL ) ) {
F_17 ( V_45 , L_25
L_26 , V_4 , V_51 -> V_63 ) ;
} else {
F_17 ( V_45 ,
L_27
L_28
L_29 ,
V_4 , V_51 -> V_63 , V_51 -> V_60 ,
V_51 -> V_64 , V_51 -> V_61 , V_51 -> V_62 ,
V_51 -> V_65 , V_51 -> V_66 ) ;
}
F_17 ( V_45 , L_30
L_31 ,
V_26 -> V_67 , V_26 -> V_68 ,
V_26 -> V_69 , F_26 ( V_26 ) ) ;
#ifdef F_13
F_17 ( V_45 , L_32 ,
F_27 ( & V_26 -> V_70 ) ,
F_27 ( & V_26 -> V_71 ) ) ;
#endif
F_16 ( V_45 , L_33 ) ;
V_5 = 0 ;
F_10 (tmp3, &ses->tcon_list) {
V_53 = F_11 ( V_49 , struct V_52 ,
V_72 ) ;
++ V_5 ;
V_54 = F_28 ( V_53 -> V_73 . V_74 ) ;
F_17 ( V_45 , L_34 , V_5 ,
V_53 -> V_75 , V_53 -> V_76 ) ;
if ( V_53 -> V_77 ) {
F_17 ( V_45 , L_35 ,
V_53 -> V_77 ) ;
}
F_17 ( V_45 , L_36
L_37 ,
F_28 ( V_53 -> V_73 . V_78 ) ,
F_28 ( V_53 -> V_79 . V_80 ) ,
F_28 ( V_53 -> V_79 . V_81 ) ,
V_53 -> V_82 ) ;
if ( V_54 == V_83 )
F_16 ( V_45 , L_38 ) ;
else if ( V_54 == V_84 )
F_16 ( V_45 , L_39 ) ;
else
F_17 ( V_45 , L_40 , V_54 ) ;
if ( V_26 -> V_85 -> V_86 )
V_26 -> V_85 -> V_86 ( V_45 , V_53 ) ;
if ( V_53 -> V_87 )
F_16 ( V_45 , L_41 ) ;
F_25 ( V_45 , '\n' ) ;
}
F_16 ( V_45 , L_42 ) ;
F_9 ( & V_31 ) ;
F_10 (tmp3, &server->pending_mid_q) {
V_30 = F_11 ( V_49 , struct V_29 ,
V_32 ) ;
F_17 ( V_45 , L_43
L_44 ,
V_30 -> V_33 ,
F_12 ( V_30 -> V_34 ) ,
V_30 -> V_35 ,
V_30 -> V_36 ,
V_30 -> V_37 ) ;
}
F_14 ( & V_31 ) ;
}
}
F_14 ( & V_57 ) ;
F_25 ( V_45 , '\n' ) ;
return 0 ;
}
static int F_29 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_15 , NULL ) ;
}
static T_3 F_31 ( struct V_89 * V_89 ,
const char T_4 * V_90 , T_5 V_91 , T_6 * V_92 )
{
char V_93 ;
int V_94 ;
struct V_27 * V_47 , * V_48 , * V_49 ;
struct V_25 * V_26 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_94 = F_32 ( V_93 , V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' || V_93 == '0' ) {
#ifdef F_13
F_33 ( & V_95 , 0 ) ;
F_33 ( & V_96 , 0 ) ;
#endif
F_9 ( & V_57 ) ;
F_10 (tmp1, &cifs_tcp_ses_list) {
V_26 = F_11 ( V_47 , struct V_25 ,
V_58 ) ;
F_10 (tmp2, &server->smb_ses_list) {
V_51 = F_11 ( V_48 , struct V_50 ,
V_59 ) ;
F_10 (tmp3, &ses->tcon_list) {
V_53 = F_11 ( V_49 ,
struct V_52 ,
V_72 ) ;
F_33 ( & V_53 -> V_97 , 0 ) ;
if ( V_26 -> V_85 -> V_98 )
V_26 -> V_85 -> V_98 ( V_53 ) ;
}
}
}
F_14 ( & V_57 ) ;
}
return V_91 ;
}
static int F_34 ( struct V_44 * V_45 , void * V_46 )
{
int V_4 ;
struct V_27 * V_47 , * V_48 , * V_49 ;
struct V_25 * V_26 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
F_17 ( V_45 ,
L_45 ,
V_99 . V_100 ) ;
F_17 ( V_45 , L_46 ,
V_101 . V_100 ) ;
F_17 ( V_45 , L_47 ,
V_102 . V_100 ,
V_103 + V_104 . V_100 ) ;
F_17 ( V_45 , L_48 ,
V_105 . V_100 , V_106 ) ;
#ifdef F_13
F_17 ( V_45 , L_49 ,
F_27 ( & V_95 ) ,
F_27 ( & V_96 ) ) ;
#endif
F_17 ( V_45 , L_50 , F_27 ( & V_107 ) ) ;
F_17 ( V_45 ,
L_51 ,
V_108 . V_100 , V_109 . V_100 ) ;
F_17 ( V_45 ,
L_52 ,
V_110 , V_111 ) ;
V_4 = 0 ;
F_9 ( & V_57 ) ;
F_10 (tmp1, &cifs_tcp_ses_list) {
V_26 = F_11 ( V_47 , struct V_25 ,
V_58 ) ;
F_10 (tmp2, &server->smb_ses_list) {
V_51 = F_11 ( V_48 , struct V_50 ,
V_59 ) ;
F_10 (tmp3, &ses->tcon_list) {
V_53 = F_11 ( V_49 ,
struct V_52 ,
V_72 ) ;
V_4 ++ ;
F_17 ( V_45 , L_53 , V_4 , V_53 -> V_75 ) ;
if ( V_53 -> V_87 )
F_16 ( V_45 , L_41 ) ;
F_17 ( V_45 , L_54 ,
F_27 ( & V_53 -> V_97 ) ) ;
if ( V_26 -> V_85 -> V_112 )
V_26 -> V_85 -> V_112 ( V_45 , V_53 ) ;
}
}
}
F_14 ( & V_57 ) ;
F_25 ( V_45 , '\n' ) ;
return 0 ;
}
static int F_35 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_34 , NULL ) ;
}
void
F_36 ( void )
{
V_113 = F_37 ( L_55 , NULL ) ;
if ( V_113 == NULL )
return;
F_38 ( L_56 , 0 , V_113 , & V_114 ) ;
#ifdef F_39
F_38 ( L_57 , 0 , V_113 , & V_115 ) ;
#endif
F_38 ( L_58 , 0 , V_113 , & V_116 ) ;
F_38 ( L_59 , 0 , V_113 , & V_117 ) ;
F_38 ( L_60 , 0 , V_113 ,
& V_118 ) ;
F_38 ( L_61 , 0 , V_113 ,
& V_119 ) ;
F_38 ( L_62 , 0 , V_113 ,
& V_120 ) ;
}
void
F_40 ( void )
{
if ( V_113 == NULL )
return;
F_41 ( L_56 , V_113 ) ;
F_41 ( L_58 , V_113 ) ;
F_41 ( L_59 , V_113 ) ;
#ifdef F_39
F_41 ( L_57 , V_113 ) ;
#endif
F_41 ( L_61 , V_113 ) ;
F_41 ( L_60 , V_113 ) ;
F_41 ( L_62 , V_113 ) ;
F_41 ( L_55 , NULL ) ;
}
static int F_42 ( struct V_44 * V_45 , void * V_46 )
{
F_17 ( V_45 , L_63 , V_121 ) ;
return 0 ;
}
static int F_43 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_42 , NULL ) ;
}
static T_3 F_44 ( struct V_89 * V_89 , const char T_4 * V_90 ,
T_5 V_91 , T_6 * V_92 )
{
char V_93 ;
int V_94 ;
V_94 = F_32 ( V_93 , V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_93 == '0' || V_93 == 'n' || V_93 == 'N' )
V_121 = 0 ;
else if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' )
V_121 = 1 ;
else if ( ( V_93 > '1' ) && ( V_93 <= '9' ) )
V_121 = ( int ) ( V_93 - '0' ) ;
return V_91 ;
}
static int F_45 ( struct V_44 * V_45 , void * V_46 )
{
F_17 ( V_45 , L_63 , V_122 ) ;
return 0 ;
}
static int F_46 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_45 , NULL ) ;
}
static T_3 F_47 ( struct V_89 * V_89 ,
const char T_4 * V_90 , T_5 V_91 , T_6 * V_92 )
{
char V_93 ;
int V_94 ;
V_94 = F_32 ( V_93 , V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_93 == '0' || V_93 == 'n' || V_93 == 'N' )
V_122 = 0 ;
else if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' )
V_122 = 1 ;
return V_91 ;
}
static int F_48 ( struct V_44 * V_45 , void * V_46 )
{
F_17 ( V_45 , L_63 , V_123 ) ;
return 0 ;
}
static int F_49 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_48 , NULL ) ;
}
static T_3 F_50 ( struct V_89 * V_89 ,
const char T_4 * V_90 , T_5 V_91 , T_6 * V_92 )
{
char V_93 ;
int V_94 ;
V_94 = F_32 ( V_93 , V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_93 == '0' || V_93 == 'n' || V_93 == 'N' )
V_123 = 0 ;
else if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' )
V_123 = 1 ;
return V_91 ;
}
static int F_51 ( struct V_44 * V_45 , void * V_46 )
{
F_17 ( V_45 , L_63 , V_124 ) ;
return 0 ;
}
static int F_52 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_51 , NULL ) ;
}
static T_3 F_53 ( struct V_89 * V_89 , const char T_4 * V_90 ,
T_5 V_91 , T_6 * V_92 )
{
char V_93 ;
int V_94 ;
V_94 = F_32 ( V_93 , V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_93 == '0' || V_93 == 'n' || V_93 == 'N' )
V_124 = 0 ;
else if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' )
V_124 = 1 ;
return V_91 ;
}
static int F_54 ( struct V_44 * V_45 , void * V_46 )
{
F_17 ( V_45 , L_64 , V_125 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_88 , struct V_89 * V_89 )
{
return F_30 ( V_89 , F_54 , NULL ) ;
}
static void
F_56 ( unsigned int * V_126 )
{
unsigned int V_127 = * V_126 & V_128 ;
if ( ( * V_126 & V_129 ) == V_129 )
* V_126 = V_129 ;
else if ( ( * V_126 & V_130 ) == V_130 )
* V_126 = V_130 ;
else if ( ( * V_126 & V_131 ) == V_131 )
* V_126 = V_131 ;
else if ( ( * V_126 & V_132 ) == V_132 )
* V_126 = V_132 ;
else if ( ( * V_126 & V_133 ) == V_133 )
* V_126 = V_133 ;
else if ( ( * V_126 & V_134 ) == V_134 )
* V_126 = V_134 ;
* V_126 |= V_127 ;
}
static T_3 F_57 ( struct V_89 * V_89 ,
const char T_4 * V_90 , T_5 V_91 , T_6 * V_92 )
{
int V_94 ;
unsigned int V_126 ;
char V_135 [ 12 ] ;
char V_93 ;
if ( ( V_91 < 1 ) || ( V_91 > 11 ) )
return - V_136 ;
memset ( V_135 , 0 , 12 ) ;
if ( F_58 ( V_135 , V_90 , V_91 ) )
return - V_137 ;
if ( V_91 < 3 ) {
V_93 = V_135 [ 0 ] ;
if ( V_93 == '0' || V_93 == 'n' || V_93 == 'N' ) {
V_125 = V_138 ;
return V_91 ;
} else if ( V_93 == '1' || V_93 == 'y' || V_93 == 'Y' ) {
V_125 = V_139 ;
return V_91 ;
} else if ( ! isdigit ( V_93 ) ) {
F_6 ( V_17 , L_65 ,
V_135 ) ;
return - V_136 ;
}
}
V_94 = F_59 ( V_135 , 0 , & V_126 ) ;
if ( V_94 ) {
F_6 ( V_17 , L_65 ,
V_135 ) ;
return V_94 ;
}
F_6 ( V_140 , L_66 , V_126 ) ;
if ( V_126 == 0 ) {
F_6 ( V_17 , L_65 , V_135 ) ;
return - V_136 ;
}
if ( V_126 & ~ V_141 ) {
F_6 ( V_17 , L_67 ,
V_126 & ~ V_141 ) ;
return - V_136 ;
}
F_56 ( & V_126 ) ;
V_125 = V_126 ;
if ( V_125 & V_128 ) {
V_125 |= V_142 ;
F_6 ( V_140 , L_68 ) ;
} else if ( ( V_125 & V_142 ) == 0 ) {
F_6 ( V_140 , L_69 ) ;
}
return V_91 ;
}
inline void F_36 ( void )
{
}
inline void F_40 ( void )
{
}
