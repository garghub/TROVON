void
F_1 ( char * V_1 , void * V_2 , int V_3 )
{
F_2 ( L_1 , V_1 , V_3 , V_2 ) ;
F_3 ( V_4 , L_2 , V_5 , 16 , 4 ,
V_2 , V_3 , true ) ;
}
void F_4 ( const char * V_6 , ... )
{
struct V_7 V_8 ;
T_1 args ;
va_start ( args , V_6 ) ;
V_8 . V_6 = V_6 ;
V_8 . V_9 = & args ;
F_5 ( L_3 , & V_8 ) ;
va_end ( args ) ;
}
void F_6 ( void * V_10 )
{
#ifdef F_7
struct V_11 * V_12 = (struct V_11 * ) V_10 ;
F_8 ( V_13 , L_4 ,
V_12 -> V_14 , V_12 -> V_15 . V_16 ,
V_12 -> V_17 , V_12 -> V_18 , V_12 -> V_19 , V_12 -> V_20 ) ;
F_8 ( V_13 , L_5 , V_12 , F_9 ( V_12 ) ) ;
#endif
}
void F_10 ( struct V_21 * V_22 )
{
#ifdef F_7
struct V_23 * V_24 ;
struct V_25 * V_26 ;
if ( V_22 == NULL )
return;
F_8 ( V_13 , L_6 ) ;
F_11 ( & V_27 ) ;
F_12 (tmp, &server->pending_mid_q) {
V_26 = F_13 ( V_24 , struct V_25 , V_28 ) ;
F_8 ( V_13 , L_7 ,
V_26 -> V_29 ,
F_14 ( V_26 -> V_30 ) ,
V_26 -> V_31 ,
V_26 -> V_32 ,
V_26 -> V_33 ) ;
#ifdef F_15
F_8 ( V_13 , L_8 ,
V_26 -> V_34 ,
V_26 -> V_35 ,
V_26 -> V_36 ,
V_37 ) ;
#endif
F_8 ( V_13 , L_9 ,
V_26 -> V_38 , V_26 -> V_39 ) ;
if ( V_26 -> V_35 ) {
F_6 ( V_26 -> V_35 ) ;
F_1 ( L_10 ,
V_26 -> V_35 , 62 ) ;
}
}
F_16 ( & V_27 ) ;
#endif
}
static int F_17 ( struct V_40 * V_41 , void * V_42 )
{
struct V_23 * V_43 , * V_44 , * V_45 ;
struct V_25 * V_26 ;
struct V_21 * V_22 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 , V_51 ;
T_2 V_52 ;
F_18 ( V_41 ,
L_11
L_12 ) ;
F_19 ( V_41 , L_13 , V_53 ) ;
F_19 ( V_41 , L_14 ) ;
#ifdef F_20
F_19 ( V_41 , L_15 ) ;
#endif
#ifdef F_21
F_19 ( V_41 , L_16 ) ;
#endif
#ifdef F_22
F_19 ( V_41 , L_17 ) ;
#endif
#ifdef F_23
F_19 ( V_41 , L_18 ) ;
#endif
#ifdef F_24
F_19 ( V_41 , L_19 ) ;
#endif
#ifdef F_25
F_19 ( V_41 , L_20 ) ;
#endif
#ifdef F_26
F_19 ( V_41 , L_21 ) ;
#endif
F_27 ( V_41 , '\n' ) ;
F_19 ( V_41 , L_22 , V_54 ) ;
F_19 ( V_41 , L_23 ) ;
V_50 = 0 ;
F_11 ( & V_55 ) ;
F_12 (tmp1, &cifs_tcp_ses_list) {
V_22 = F_13 ( V_43 , struct V_21 ,
V_56 ) ;
F_19 ( V_41 , L_24 , V_22 -> V_57 ) ;
V_50 ++ ;
F_12 (tmp2, &server->smb_ses_list) {
V_47 = F_13 ( V_44 , struct V_46 ,
V_58 ) ;
if ( ( V_47 -> V_59 == NULL ) ||
( V_47 -> V_60 == NULL ) ||
( V_47 -> V_61 == NULL ) ) {
F_19 ( V_41 , L_25
L_26 , V_50 , V_47 -> V_62 ) ;
} else {
F_19 ( V_41 ,
L_27
L_28
L_29 ,
V_50 , V_47 -> V_62 , V_47 -> V_59 ,
V_47 -> V_63 , V_47 -> V_60 , V_47 -> V_61 ,
V_47 -> V_64 , V_47 -> V_65 ) ;
}
F_19 ( V_41 , L_30
L_31 ,
V_22 -> V_66 , V_22 -> V_67 ,
V_22 -> V_68 , F_28 ( V_22 ) ) ;
#ifdef F_15
F_19 ( V_41 , L_32 ,
F_29 ( & V_22 -> V_69 ) ,
F_29 ( & V_22 -> V_70 ) ) ;
#endif
F_18 ( V_41 , L_33 ) ;
V_51 = 0 ;
F_12 (tmp3, &ses->tcon_list) {
V_49 = F_13 ( V_45 , struct V_48 ,
V_71 ) ;
++ V_51 ;
V_52 = F_30 ( V_49 -> V_72 . V_73 ) ;
F_19 ( V_41 , L_34 , V_51 ,
V_49 -> V_74 , V_49 -> V_75 ) ;
if ( V_49 -> V_76 ) {
F_19 ( V_41 , L_35 ,
V_49 -> V_76 ) ;
}
F_19 ( V_41 , L_36
L_37 ,
F_30 ( V_49 -> V_72 . V_77 ) ,
F_30 ( V_49 -> V_78 . V_79 ) ,
F_30 ( V_49 -> V_78 . V_80 ) ,
V_49 -> V_81 ) ;
if ( V_52 == V_82 )
F_18 ( V_41 , L_38 ) ;
else if ( V_52 == V_83 )
F_18 ( V_41 , L_39 ) ;
else
F_19 ( V_41 , L_40 , V_52 ) ;
if ( V_22 -> V_84 -> V_85 )
V_22 -> V_84 -> V_85 ( V_41 , V_49 ) ;
if ( V_49 -> V_86 )
F_18 ( V_41 , L_41 ) ;
F_27 ( V_41 , '\n' ) ;
}
F_18 ( V_41 , L_42 ) ;
F_11 ( & V_27 ) ;
F_12 (tmp3, &server->pending_mid_q) {
V_26 = F_13 ( V_45 , struct V_25 ,
V_28 ) ;
F_19 ( V_41 , L_43
L_44 ,
V_26 -> V_29 ,
F_14 ( V_26 -> V_30 ) ,
V_26 -> V_31 ,
V_26 -> V_32 ,
V_26 -> V_33 ) ;
}
F_16 ( & V_27 ) ;
}
}
F_16 ( & V_55 ) ;
F_27 ( V_41 , '\n' ) ;
return 0 ;
}
static int F_31 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_17 , NULL ) ;
}
static T_3 F_33 ( struct V_88 * V_88 ,
const char T_4 * V_89 , T_5 V_90 , T_6 * V_91 )
{
bool V_92 ;
int V_93 ;
struct V_23 * V_43 , * V_44 , * V_45 ;
struct V_21 * V_22 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
V_93 = F_34 ( V_89 , V_90 , & V_92 ) ;
if ( V_93 == 0 ) {
#ifdef F_15
F_35 ( & V_94 , 0 ) ;
F_35 ( & V_95 , 0 ) ;
#endif
F_11 ( & V_55 ) ;
F_12 (tmp1, &cifs_tcp_ses_list) {
V_22 = F_13 ( V_43 , struct V_21 ,
V_56 ) ;
F_12 (tmp2, &server->smb_ses_list) {
V_47 = F_13 ( V_44 , struct V_46 ,
V_58 ) ;
F_12 (tmp3, &ses->tcon_list) {
V_49 = F_13 ( V_45 ,
struct V_48 ,
V_71 ) ;
F_35 ( & V_49 -> V_96 , 0 ) ;
if ( V_22 -> V_84 -> V_97 )
V_22 -> V_84 -> V_97 ( V_49 ) ;
}
}
}
F_16 ( & V_55 ) ;
} else {
return V_93 ;
}
return V_90 ;
}
static int F_36 ( struct V_40 * V_41 , void * V_42 )
{
int V_50 ;
struct V_23 * V_43 , * V_44 , * V_45 ;
struct V_21 * V_22 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
F_19 ( V_41 ,
L_45 ,
V_98 . V_99 ) ;
F_19 ( V_41 , L_46 ,
V_100 . V_99 ) ;
F_19 ( V_41 , L_47 ,
V_101 . V_99 ,
V_102 + V_103 . V_99 ) ;
F_19 ( V_41 , L_48 ,
V_104 . V_99 , V_105 ) ;
#ifdef F_15
F_19 ( V_41 , L_49 ,
F_29 ( & V_94 ) ,
F_29 ( & V_95 ) ) ;
#endif
F_19 ( V_41 , L_50 , F_29 ( & V_106 ) ) ;
F_19 ( V_41 ,
L_51 ,
V_107 . V_99 , V_108 . V_99 ) ;
F_19 ( V_41 ,
L_52 ,
V_109 , V_110 ) ;
V_50 = 0 ;
F_11 ( & V_55 ) ;
F_12 (tmp1, &cifs_tcp_ses_list) {
V_22 = F_13 ( V_43 , struct V_21 ,
V_56 ) ;
F_12 (tmp2, &server->smb_ses_list) {
V_47 = F_13 ( V_44 , struct V_46 ,
V_58 ) ;
F_12 (tmp3, &ses->tcon_list) {
V_49 = F_13 ( V_45 ,
struct V_48 ,
V_71 ) ;
V_50 ++ ;
F_19 ( V_41 , L_53 , V_50 , V_49 -> V_74 ) ;
if ( V_49 -> V_86 )
F_18 ( V_41 , L_41 ) ;
F_19 ( V_41 , L_54 ,
F_29 ( & V_49 -> V_96 ) ) ;
if ( V_22 -> V_84 -> V_111 )
V_22 -> V_84 -> V_111 ( V_41 , V_49 ) ;
}
}
}
F_16 ( & V_55 ) ;
F_27 ( V_41 , '\n' ) ;
return 0 ;
}
static int F_37 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_36 , NULL ) ;
}
void
F_38 ( void )
{
V_112 = F_39 ( L_55 , NULL ) ;
if ( V_112 == NULL )
return;
F_40 ( L_56 , 0 , V_112 , & V_113 ) ;
#ifdef F_41
F_40 ( L_57 , 0 , V_112 , & V_114 ) ;
#endif
F_40 ( L_58 , 0 , V_112 , & V_115 ) ;
F_40 ( L_59 , 0 , V_112 , & V_116 ) ;
F_40 ( L_60 , 0 , V_112 ,
& V_117 ) ;
F_40 ( L_61 , 0 , V_112 ,
& V_118 ) ;
F_40 ( L_62 , 0 , V_112 ,
& V_119 ) ;
}
void
F_42 ( void )
{
if ( V_112 == NULL )
return;
F_43 ( L_56 , V_112 ) ;
F_43 ( L_58 , V_112 ) ;
F_43 ( L_59 , V_112 ) ;
#ifdef F_41
F_43 ( L_57 , V_112 ) ;
#endif
F_43 ( L_61 , V_112 ) ;
F_43 ( L_60 , V_112 ) ;
F_43 ( L_62 , V_112 ) ;
F_43 ( L_55 , NULL ) ;
}
static int F_44 ( struct V_40 * V_41 , void * V_42 )
{
F_19 ( V_41 , L_63 , V_120 ) ;
return 0 ;
}
static int F_45 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_44 , NULL ) ;
}
static T_3 F_46 ( struct V_88 * V_88 , const char T_4 * V_89 ,
T_5 V_90 , T_6 * V_91 )
{
char V_121 [ 2 ] = { '\0' } ;
bool V_92 ;
int V_93 ;
V_93 = F_47 ( V_121 [ 0 ] , V_89 ) ;
if ( V_93 )
return V_93 ;
if ( F_48 ( V_121 , & V_92 ) == 0 )
V_120 = V_92 ;
else if ( ( V_121 [ 0 ] > '1' ) && ( V_121 [ 0 ] <= '9' ) )
V_120 = ( int ) ( V_121 [ 0 ] - '0' ) ;
return V_90 ;
}
static int F_49 ( struct V_40 * V_41 , void * V_42 )
{
F_19 ( V_41 , L_63 , V_122 ) ;
return 0 ;
}
static int F_50 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_49 , NULL ) ;
}
static T_3 F_51 ( struct V_88 * V_88 ,
const char T_4 * V_89 , T_5 V_90 , T_6 * V_91 )
{
int V_93 ;
V_93 = F_34 ( V_89 , V_90 , & V_122 ) ;
if ( V_93 )
return V_93 ;
return V_90 ;
}
static int F_52 ( struct V_40 * V_41 , void * V_42 )
{
F_19 ( V_41 , L_63 , V_123 ) ;
return 0 ;
}
static int F_53 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_52 , NULL ) ;
}
static T_3 F_54 ( struct V_88 * V_88 ,
const char T_4 * V_89 , T_5 V_90 , T_6 * V_91 )
{
int V_93 ;
V_93 = F_34 ( V_89 , V_90 , & V_123 ) ;
if ( V_93 )
return V_93 ;
return V_90 ;
}
static int F_55 ( struct V_40 * V_41 , void * V_42 )
{
F_19 ( V_41 , L_63 , V_124 ) ;
return 0 ;
}
static int F_56 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_55 , NULL ) ;
}
static T_3 F_57 ( struct V_88 * V_88 , const char T_4 * V_89 ,
T_5 V_90 , T_6 * V_91 )
{
int V_93 ;
V_93 = F_34 ( V_89 , V_90 , & V_124 ) ;
if ( V_93 )
return V_93 ;
return V_90 ;
}
static int F_58 ( struct V_40 * V_41 , void * V_42 )
{
F_19 ( V_41 , L_64 , V_125 ) ;
return 0 ;
}
static int F_59 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_32 ( V_88 , F_58 , NULL ) ;
}
static void
F_60 ( unsigned int * V_126 )
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
else if ( V_133 &&
( * V_126 & V_133 ) == V_133 )
* V_126 = V_133 ;
else if ( V_134 &&
( * V_126 & V_134 ) == V_134 )
* V_126 = V_134 ;
* V_126 |= V_127 ;
}
static T_3 F_61 ( struct V_88 * V_88 ,
const char T_4 * V_89 , T_5 V_90 , T_6 * V_91 )
{
int V_93 ;
unsigned int V_126 ;
char V_135 [ 12 ] ;
bool V_92 ;
if ( ( V_90 < 1 ) || ( V_90 > 11 ) )
return - V_136 ;
memset ( V_135 , 0 , 12 ) ;
if ( F_62 ( V_135 , V_89 , V_90 ) )
return - V_137 ;
if ( V_90 < 3 ) {
if ( F_48 ( V_135 , & V_92 ) == 0 ) {
V_125 = V_92 ? V_138 : V_139 ;
return V_90 ;
} else if ( ! isdigit ( V_135 [ 0 ] ) ) {
F_8 ( V_13 , L_65 ,
V_135 ) ;
return - V_136 ;
}
}
V_93 = F_63 ( V_135 , 0 , & V_126 ) ;
if ( V_93 ) {
F_8 ( V_13 , L_65 ,
V_135 ) ;
return V_93 ;
}
F_8 ( V_140 , L_66 , V_126 ) ;
if ( V_126 == 0 ) {
F_8 ( V_13 , L_65 , V_135 ) ;
return - V_136 ;
}
if ( V_126 & ~ V_141 ) {
F_8 ( V_13 , L_67 ,
V_126 & ~ V_141 ) ;
return - V_136 ;
}
F_60 ( & V_126 ) ;
V_125 = V_126 ;
if ( V_125 & V_128 ) {
V_125 |= V_142 ;
F_8 ( V_140 , L_68 ) ;
} else if ( ( V_125 & V_142 ) == 0 ) {
F_8 ( V_140 , L_69 ) ;
}
return V_90 ;
}
inline void F_38 ( void )
{
}
inline void F_42 ( void )
{
}
