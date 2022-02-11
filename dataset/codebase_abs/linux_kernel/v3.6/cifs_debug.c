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
void F_3 ( void * V_8 )
{
#ifdef F_4
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
F_5 ( 1 , L_4 ,
V_11 -> V_12 , V_11 -> V_13 . V_14 ,
V_11 -> V_15 , V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ) ;
F_5 ( 1 , L_5 , V_11 , F_6 ( V_11 ) ) ;
#endif
}
void F_7 ( struct V_19 * V_20 )
{
#ifdef F_4
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( V_20 == NULL )
return;
F_5 ( 1 , L_6 ) ;
F_8 ( & V_25 ) ;
F_9 (tmp, &server->pending_mid_q) {
V_24 = F_10 ( V_22 , struct V_23 , V_26 ) ;
F_5 ( 1 , L_7 ,
V_24 -> V_27 ,
F_11 ( V_24 -> V_28 ) ,
V_24 -> V_29 ,
V_24 -> V_30 ,
V_24 -> V_31 ) ;
#ifdef F_12
F_5 ( 1 , L_8 ,
V_24 -> V_32 ,
V_24 -> V_33 ,
V_24 -> V_34 ,
V_35 ) ;
#endif
F_5 ( 1 , L_9 , V_24 -> V_36 ,
V_24 -> V_37 ) ;
if ( V_24 -> V_33 ) {
F_3 ( V_24 -> V_33 ) ;
F_1 ( L_10 ,
V_24 -> V_33 , 62 ) ;
}
}
F_13 ( & V_25 ) ;
#endif
}
static int F_14 ( struct V_38 * V_39 , void * V_40 )
{
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_23 * V_24 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_4 , V_5 ;
T_1 V_48 ;
F_15 ( V_39 ,
L_11
L_12 ) ;
F_16 ( V_39 , L_13 , V_49 ) ;
F_16 ( V_39 , L_14 ) ;
#ifdef F_17
F_16 ( V_39 , L_15 ) ;
#endif
#ifdef F_18
F_16 ( V_39 , L_16 ) ;
#endif
#ifdef F_19
F_16 ( V_39 , L_17 ) ;
#endif
#ifdef F_20
F_16 ( V_39 , L_18 ) ;
#endif
#ifdef F_21
F_16 ( V_39 , L_19 ) ;
#endif
#ifdef F_22
F_16 ( V_39 , L_20 ) ;
#endif
#ifdef F_23
F_16 ( V_39 , L_21 ) ;
#endif
F_24 ( V_39 , '\n' ) ;
F_16 ( V_39 , L_22 , V_50 ) ;
F_16 ( V_39 , L_23 ) ;
V_4 = 0 ;
F_8 ( & V_51 ) ;
F_9 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_10 ( V_41 , struct V_19 ,
V_52 ) ;
V_4 ++ ;
F_9 (tmp2, &server->smb_ses_list) {
V_45 = F_10 ( V_42 , struct V_44 ,
V_53 ) ;
if ( ( V_45 -> V_54 == NULL ) ||
( V_45 -> V_55 == NULL ) ||
( V_45 -> V_56 == NULL ) ) {
F_16 ( V_39 , L_24
L_25 , V_4 , V_45 -> V_57 ) ;
} else {
F_16 ( V_39 ,
L_26
L_27
L_28 ,
V_4 , V_45 -> V_57 , V_45 -> V_54 ,
V_45 -> V_58 , V_45 -> V_55 , V_45 -> V_56 ,
V_45 -> V_59 , V_45 -> V_60 ) ;
}
F_16 ( V_39 , L_29
L_30 ,
V_20 -> V_61 , V_20 -> V_62 ,
V_20 -> V_63 , F_25 ( V_20 ) ) ;
#ifdef F_12
F_16 ( V_39 , L_31 ,
F_26 ( & V_20 -> V_64 ) ,
F_26 ( & V_20 -> V_65 ) ) ;
#endif
F_15 ( V_39 , L_32 ) ;
V_5 = 0 ;
F_9 (tmp3, &ses->tcon_list) {
V_47 = F_10 ( V_43 , struct V_46 ,
V_66 ) ;
++ V_5 ;
V_48 = F_27 ( V_47 -> V_67 . V_68 ) ;
F_16 ( V_39 , L_33 , V_5 ,
V_47 -> V_69 , V_47 -> V_70 ) ;
if ( V_47 -> V_71 ) {
F_16 ( V_39 , L_34 ,
V_47 -> V_71 ) ;
}
F_16 ( V_39 , L_35
L_36 ,
F_27 ( V_47 -> V_67 . V_72 ) ,
F_27 ( V_47 -> V_73 . V_74 ) ,
F_27 ( V_47 -> V_73 . V_75 ) ,
V_47 -> V_76 ) ;
if ( V_48 == V_77 )
F_15 ( V_39 , L_37 ) ;
else if ( V_48 == V_78 )
F_15 ( V_39 , L_38 ) ;
else
F_16 ( V_39 , L_39 , V_48 ) ;
if ( V_47 -> V_79 )
F_15 ( V_39 , L_40 ) ;
F_24 ( V_39 , '\n' ) ;
}
F_15 ( V_39 , L_41 ) ;
F_8 ( & V_25 ) ;
F_9 (tmp3, &server->pending_mid_q) {
V_24 = F_10 ( V_43 , struct V_23 ,
V_26 ) ;
F_16 ( V_39 , L_42
L_43 ,
V_24 -> V_27 ,
F_11 ( V_24 -> V_28 ) ,
V_24 -> V_29 ,
V_24 -> V_30 ,
V_24 -> V_31 ) ;
}
F_13 ( & V_25 ) ;
}
}
F_13 ( & V_51 ) ;
F_24 ( V_39 , '\n' ) ;
return 0 ;
}
static int F_28 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_14 , NULL ) ;
}
static T_2 F_30 ( struct V_81 * V_81 ,
const char T_3 * V_82 , T_4 V_83 , T_5 * V_84 )
{
char V_85 ;
int V_86 ;
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_86 = F_31 ( V_85 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' || V_85 == '0' ) {
#ifdef F_12
F_32 ( & V_87 , 0 ) ;
F_32 ( & V_88 , 0 ) ;
#endif
F_8 ( & V_51 ) ;
F_9 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_10 ( V_41 , struct V_19 ,
V_52 ) ;
F_9 (tmp2, &server->smb_ses_list) {
V_45 = F_10 ( V_42 , struct V_44 ,
V_53 ) ;
F_9 (tmp3, &ses->tcon_list) {
V_47 = F_10 ( V_43 ,
struct V_46 ,
V_66 ) ;
F_32 ( & V_47 -> V_89 , 0 ) ;
if ( V_20 -> V_90 -> V_91 )
V_20 -> V_90 -> V_91 ( V_47 ) ;
}
}
}
F_13 ( & V_51 ) ;
}
return V_83 ;
}
static int F_33 ( struct V_38 * V_39 , void * V_40 )
{
int V_4 ;
struct V_21 * V_41 , * V_42 , * V_43 ;
struct V_19 * V_20 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
F_16 ( V_39 ,
L_44 ,
V_92 . V_93 ) ;
F_16 ( V_39 , L_45 ,
V_94 . V_93 ) ;
F_16 ( V_39 , L_46 ,
V_95 . V_93 ,
V_96 + V_97 . V_93 ) ;
F_16 ( V_39 , L_47 ,
V_98 . V_93 , V_99 ) ;
#ifdef F_12
F_16 ( V_39 , L_48 ,
F_26 ( & V_87 ) ,
F_26 ( & V_88 ) ) ;
#endif
F_16 ( V_39 , L_49 , F_26 ( & V_100 ) ) ;
F_16 ( V_39 ,
L_50 ,
V_101 . V_93 , V_102 . V_93 ) ;
F_16 ( V_39 ,
L_51 ,
V_103 , V_104 ) ;
V_4 = 0 ;
F_8 ( & V_51 ) ;
F_9 (tmp1, &cifs_tcp_ses_list) {
V_20 = F_10 ( V_41 , struct V_19 ,
V_52 ) ;
F_9 (tmp2, &server->smb_ses_list) {
V_45 = F_10 ( V_42 , struct V_44 ,
V_53 ) ;
F_9 (tmp3, &ses->tcon_list) {
V_47 = F_10 ( V_43 ,
struct V_46 ,
V_66 ) ;
V_4 ++ ;
F_16 ( V_39 , L_52 , V_4 , V_47 -> V_69 ) ;
if ( V_47 -> V_79 )
F_15 ( V_39 , L_40 ) ;
F_16 ( V_39 , L_53 ,
F_26 ( & V_47 -> V_89 ) ) ;
if ( V_20 -> V_90 -> V_105 )
V_20 -> V_90 -> V_105 ( V_39 , V_47 ) ;
}
}
}
F_13 ( & V_51 ) ;
F_24 ( V_39 , '\n' ) ;
return 0 ;
}
static int F_34 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_33 , NULL ) ;
}
void
F_35 ( void )
{
V_106 = F_36 ( L_54 , NULL ) ;
if ( V_106 == NULL )
return;
F_37 ( L_55 , 0 , V_106 , & V_107 ) ;
#ifdef F_38
F_37 ( L_56 , 0 , V_106 , & V_108 ) ;
#endif
F_37 ( L_57 , 0 , V_106 , & V_109 ) ;
F_37 ( L_58 , 0 , V_106 , & V_110 ) ;
F_37 ( L_59 , 0 , V_106 ,
& V_111 ) ;
F_37 ( L_60 , 0 , V_106 ,
& V_112 ) ;
F_37 ( L_61 , 0 , V_106 ,
& V_113 ) ;
}
void
F_39 ( void )
{
if ( V_106 == NULL )
return;
F_40 ( L_55 , V_106 ) ;
F_40 ( L_57 , V_106 ) ;
F_40 ( L_58 , V_106 ) ;
#ifdef F_38
F_40 ( L_56 , V_106 ) ;
#endif
F_40 ( L_60 , V_106 ) ;
F_40 ( L_59 , V_106 ) ;
F_40 ( L_61 , V_106 ) ;
F_40 ( L_54 , NULL ) ;
}
static int F_41 ( struct V_38 * V_39 , void * V_40 )
{
F_16 ( V_39 , L_62 , V_114 ) ;
return 0 ;
}
static int F_42 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_41 , NULL ) ;
}
static T_2 F_43 ( struct V_81 * V_81 , const char T_3 * V_82 ,
T_4 V_83 , T_5 * V_84 )
{
char V_85 ;
int V_86 ;
V_86 = F_31 ( V_85 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_85 == '0' || V_85 == 'n' || V_85 == 'N' )
V_114 = 0 ;
else if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' )
V_114 = 1 ;
else if ( ( V_85 > '1' ) && ( V_85 <= '9' ) )
V_114 = ( int ) ( V_85 - '0' ) ;
return V_83 ;
}
static int F_44 ( struct V_38 * V_39 , void * V_40 )
{
F_16 ( V_39 , L_62 , V_115 ) ;
return 0 ;
}
static int F_45 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_44 , NULL ) ;
}
static T_2 F_46 ( struct V_81 * V_81 ,
const char T_3 * V_82 , T_4 V_83 , T_5 * V_84 )
{
char V_85 ;
int V_86 ;
V_86 = F_31 ( V_85 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_85 == '0' || V_85 == 'n' || V_85 == 'N' )
V_115 = 0 ;
else if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' )
V_115 = 1 ;
return V_83 ;
}
static int F_47 ( struct V_38 * V_39 , void * V_40 )
{
F_16 ( V_39 , L_62 , V_116 ) ;
return 0 ;
}
static int F_48 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_47 , NULL ) ;
}
static T_2 F_49 ( struct V_81 * V_81 ,
const char T_3 * V_82 , T_4 V_83 , T_5 * V_84 )
{
char V_85 ;
int V_86 ;
V_86 = F_31 ( V_85 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_85 == '0' || V_85 == 'n' || V_85 == 'N' )
V_116 = 0 ;
else if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' )
V_116 = 1 ;
return V_83 ;
}
static int F_50 ( struct V_38 * V_39 , void * V_40 )
{
F_16 ( V_39 , L_62 , V_117 ) ;
return 0 ;
}
static int F_51 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_50 , NULL ) ;
}
static T_2 F_52 ( struct V_81 * V_81 , const char T_3 * V_82 ,
T_4 V_83 , T_5 * V_84 )
{
char V_85 ;
int V_86 ;
V_86 = F_31 ( V_85 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_85 == '0' || V_85 == 'n' || V_85 == 'N' )
V_117 = 0 ;
else if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' )
V_117 = 1 ;
return V_83 ;
}
static int F_53 ( struct V_38 * V_39 , void * V_40 )
{
F_16 ( V_39 , L_63 , V_118 ) ;
return 0 ;
}
static int F_54 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_29 ( V_81 , F_53 , NULL ) ;
}
static T_2 F_55 ( struct V_81 * V_81 ,
const char T_3 * V_82 , T_4 V_83 , T_5 * V_84 )
{
unsigned int V_119 ;
char V_120 [ 12 ] ;
char V_85 ;
if ( ( V_83 < 1 ) || ( V_83 > 11 ) )
return - V_121 ;
memset ( V_120 , 0 , 12 ) ;
if ( F_56 ( V_120 , V_82 , V_83 ) )
return - V_122 ;
if ( V_83 < 3 ) {
V_85 = V_120 [ 0 ] ;
if ( V_85 == '0' || V_85 == 'n' || V_85 == 'N' ) {
V_118 = V_123 ;
return V_83 ;
} else if ( V_85 == '1' || V_85 == 'y' || V_85 == 'Y' ) {
V_118 = V_124 ;
return V_83 ;
} else if ( ! isdigit ( V_85 ) ) {
F_5 ( 1 , L_64 , V_85 ) ;
return - V_121 ;
}
}
V_119 = F_57 ( V_120 , NULL , 0 ) ;
F_58 ( 1 , L_65 , V_119 ) ;
if ( V_119 <= 0 ) {
F_5 ( 1 , L_66 , V_120 ) ;
return - V_121 ;
}
if ( V_119 & ~ V_125 ) {
F_5 ( 1 , L_67 ,
V_119 & ~ V_125 ) ;
return - V_121 ;
}
V_118 = V_119 ;
if ( V_118 & V_126 ) {
V_118 |= V_127 ;
F_58 ( 1 , L_68 ) ;
} else if ( ( V_118 & V_127 ) == 0 ) {
F_58 ( 1 , L_69 ) ;
}
return V_83 ;
}
inline void F_35 ( void )
{
}
inline void F_39 ( void )
{
}
