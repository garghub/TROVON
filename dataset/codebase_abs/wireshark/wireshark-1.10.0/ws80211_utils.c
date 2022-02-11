static inline struct V_1 * F_1 ( void )
{
return F_2 () ;
}
static inline void F_3 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) ;
}
int F_5 ( void )
{
int V_4 ;
struct V_5 * V_6 = & V_7 ;
V_6 -> V_2 = F_1 () ;
if ( ! V_6 -> V_2 ) {
fprintf ( V_8 , L_1 ) ;
return - V_9 ;
}
if ( F_6 ( V_6 -> V_2 ) ) {
fprintf ( V_8 , L_2 ) ;
V_4 = - V_10 ;
goto V_11;
}
V_6 -> V_12 = F_7 ( V_6 -> V_2 , L_3 ) ;
if ( V_6 -> V_12 < 0 ) {
fprintf ( V_8 , L_4 ) ;
V_4 = - V_13 ;
goto V_11;
}
return 0 ;
V_11:
F_3 ( V_6 -> V_2 ) ;
V_6 -> V_2 = 0 ;
return V_4 ;
}
static int F_8 ( struct V_14 * T_1 V_15 , struct V_16 * V_4 ,
void * V_17 )
{
int * V_18 = ( int * ) V_17 ;
* V_18 = V_4 -> error ;
return V_19 ;
}
static int F_9 ( struct V_20 * T_2 V_15 , void * V_17 )
{
int * V_18 = ( int * ) V_17 ;
* V_18 = 0 ;
return V_21 ;
}
static int F_10 ( struct V_20 * T_2 V_15 , void * V_17 )
{
int * V_18 = ( int * ) V_17 ;
* V_18 = 0 ;
return V_19 ;
}
static int F_11 ( struct V_20 * T_2 , struct V_22 * V_23 )
{
int V_4 ;
if ( ! V_7 . V_2 )
return - V_10 ;
V_4 = F_12 ( V_7 . V_2 , T_2 ) ;
if ( V_4 < 0 )
goto V_24;
V_4 = 1 ;
F_13 ( V_23 , V_25 , F_8 , & V_4 ) ;
F_14 ( V_23 , V_26 , V_25 , F_9 , & V_4 ) ;
F_14 ( V_23 , V_27 , V_25 , F_10 , & V_4 ) ;
while ( V_4 > 0 )
F_15 ( V_7 . V_2 , V_23 ) ;
V_24:
F_16 ( V_23 ) ;
return V_4 ;
}
static int F_17 ( struct V_20 * T_2 , void * V_17 )
{
struct V_28 * V_29 [ V_30 + 1 ] ;
struct V_31 * V_32 = (struct V_31 * ) F_18 ( F_19 ( T_2 ) ) ;
struct V_33 * V_34 = (struct V_33 * ) V_17 ;
struct V_28 * V_35 [ V_36 + 1 ] ;
struct V_28 * V_37 [ V_38 + 1 ] ;
static struct V_39 V_40 [ V_38 + 1 ] = {
[ V_41 ] = { . type = V_42 } ,
[ V_43 ] = { . type = V_44 } ,
[ V_45 ] = { . type = V_44 } ,
[ V_46 ] = { . type = V_44 } ,
[ V_47 ] = { . type = V_44 } ,
[ V_48 ] = { . type = V_42 } ,
} ;
struct V_28 * V_49 ;
struct V_28 * V_50 ;
struct V_28 * V_51 ;
int V_52 = 1 ;
int V_53 , V_54 , V_55 ;
struct V_56 * V_57 ;
int V_58 = 0 ;
F_20 ( V_29 , V_30 , F_21 ( V_32 , 0 ) ,
F_22 ( V_32 , 0 ) , NULL ) ;
if ( ! V_29 [ V_59 ] )
return V_21 ;
if ( V_29 [ V_60 ] ) {
F_23 (nl_mode, tb_msg[NL80211_ATTR_SUPPORTED_IFTYPES], rem_mode) {
if ( F_24 ( V_51 ) == V_61 )
V_58 = 1 ;
}
}
if ( ! V_58 )
return V_21 ;
V_57 = (struct V_56 * ) F_25 ( sizeof( * V_57 ) ) ;
if ( ! V_57 )
return V_21 ;
V_57 -> V_62 = F_26 ( FALSE , FALSE , sizeof( int ) ) ;
V_57 -> V_63 = 1 << V_64 ;
if ( V_29 [ V_65 ] ) {
V_57 -> V_66 = F_27 ( L_5 ,
F_28 ( V_29 [ V_65 ] ) ) ;
}
F_23 (nl_band, tb_msg[NL80211_ATTR_WIPHY_BANDS], rem_band) {
V_52 ++ ;
F_20 ( V_35 , V_36 ,
(struct V_28 * ) F_29 ( V_49 ) ,
F_30 ( V_49 ) , NULL ) ;
#ifdef F_31
if ( V_35 [ F_31 ] ) {
T_3 V_67 ;
V_57 -> V_63 |= 1 << V_68 ;
V_67 = ! ! ( F_32 ( V_35 [ F_31 ] ) & 0x02 ) ;
if ( V_67 ) {
V_57 -> V_63 |= 1 << V_69 ;
V_57 -> V_63 |= 1 << V_70 ;
}
}
#endif
F_23 (nl_freq, tb_band[NL80211_BAND_ATTR_FREQS], rem_freq) {
T_4 V_71 ;
F_20 ( V_37 , V_38 ,
(struct V_28 * ) F_29 ( V_50 ) ,
F_30 ( V_50 ) , V_40 ) ;
if ( ! V_37 [ V_41 ] )
continue;
if ( V_37 [ V_43 ] )
continue;
V_71 = F_33 ( V_37 [ V_41 ] ) ;
F_34 ( V_57 -> V_62 , V_71 ) ;
}
}
#ifdef F_35
if ( V_29 [ V_72 ] ) {
int V_73 ;
struct V_28 * V_74 ;
F_23 (nl_cmd, tb_msg[NL80211_ATTR_SUPPORTED_COMMANDS], cmd) {
if( F_33 ( V_74 ) == V_75 )
V_57 -> V_76 = TRUE ;
}
}
#else
V_57 -> V_76 = TRUE ;
#endif
F_34 ( V_34 -> V_77 , V_57 ) ;
return V_21 ;
}
static int F_36 ( T_5 * V_77 )
{
struct V_33 V_34 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_78 ) ;
V_34 . V_77 = V_77 ;
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
V_79 , V_80 , 0 ) ;
F_14 ( V_23 , V_81 , V_25 , F_17 , & V_34 ) ;
return F_11 ( T_2 , V_23 ) ;
}
static int F_40 ( const char * V_66 )
{
int V_82 ;
int V_18 = - 1 ;
struct {
char V_83 [ V_84 ] ;
T_6 V_85 ;
T_7 V_86 ;
T_8 V_87 ;
T_8 V_88 ;
} V_89 ;
V_82 = F_41 ( V_90 , V_91 , 0 ) ;
if ( V_82 == - 1 )
return - 1 ;
F_42 ( V_89 . V_83 , V_66 , V_84 ) ;
if ( F_43 ( V_82 , 0x8B05 , & V_89 ) == 0 ) {
if ( V_89 . V_86 == 6 )
V_18 = V_89 . V_85 ;
}
F_44 ( V_82 ) ;
return V_18 ;
}
static int F_45 ( struct V_20 * T_2 , void * V_17 )
{
struct V_31 * V_32 = (struct V_31 * ) F_18 ( F_19 ( T_2 ) ) ;
struct V_28 * V_29 [ V_30 + 1 ] ;
struct V_92 * V_93 = (struct V_92 * ) V_17 ;
F_20 ( V_29 , V_30 , F_21 ( V_32 , 0 ) ,
F_22 ( V_32 , 0 ) , NULL ) ;
if ( V_29 [ V_94 ] ) {
V_93 -> type = F_33 ( V_29 [ V_94 ] ) ;
}
if ( V_29 [ V_95 ] ) {
V_93 -> V_96 = F_33 ( V_29 [ V_95 ] ) ;
}
if ( V_29 [ V_97 ] ) {
V_93 -> V_98 -> V_99 = F_33 ( V_29 [ V_97 ] ) ;
V_93 -> V_98 -> V_100 = V_64 ;
if ( V_29 [ V_101 ] ) {
switch ( F_33 ( V_29 [ V_101 ] ) ) {
case V_102 :
V_93 -> V_98 -> V_100 = V_64 ;
break;
case V_103 :
V_93 -> V_98 -> V_100 = V_68 ;
break;
case V_104 :
V_93 -> V_98 -> V_100 = V_69 ;
break;
case V_105 :
V_93 -> V_98 -> V_100 = V_70 ;
break;
}
}
}
return V_21 ;
}
static int F_46 ( const char * V_106 , struct V_92 * V_93 )
{
int V_107 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_78 ) ;
V_107 = F_47 ( V_106 ) ;
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_108 , 0 ) ;
F_48 ( T_2 , V_109 , V_107 ) ;
F_14 ( V_23 , V_81 , V_25 , F_45 , V_93 ) ;
if ( F_11 ( T_2 , V_23 ) )
return - 1 ;
if ( V_93 -> V_98 -> V_99 == - 1 )
V_93 -> V_98 -> V_99 = F_40 ( V_106 ) ;
return 0 ;
V_110:
fprintf ( V_8 , L_7 ) ;
return - 1 ;
}
int F_49 ( const char * V_106 , struct V_111 * V_93 )
{
struct V_92 V_92 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_92 . V_98 = V_93 ;
V_92 . type = - 1 ;
V_92 . V_96 = - 1 ;
V_92 . V_98 -> V_99 = - 1 ;
V_92 . V_98 -> V_100 = V_64 ;
return F_46 ( V_106 , & V_92 ) ;
}
static int F_50 ( T_5 * V_77 )
{
T_9 * V_112 ;
char line [ 200 ] ;
char * V_113 ;
T_10 * V_114 ;
char * V_18 ;
int V_87 ;
unsigned int V_115 ;
struct V_111 V_98 ;
struct V_92 V_93 ;
struct V_56 * V_57 ;
F_36 ( V_77 ) ;
V_112 = F_51 ( L_8 , L_9 ) ;
if( ! V_112 ) {
fprintf ( V_8 , L_10 ) ;
return - V_13 ;
}
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
V_18 = fgets ( line , sizeof( line ) , V_112 ) ;
if ( V_18 == NULL ) {
fprintf ( V_8 , L_11 ) ;
fclose ( V_112 ) ;
return - 1 ;
}
}
while( fgets ( line , sizeof( line ) , V_112 ) ) {
V_113 = F_52 ( line , ':' ) ;
if ( ! V_113 )
continue;
* V_113 = 0 ;
V_113 = line ;
while ( * V_113 && * V_113 == ' ' )
V_113 ++ ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_98 = & V_98 ;
F_46 ( V_113 , & V_93 ) ;
if ( V_93 . type == V_61 ) {
for ( V_115 = 0 ; V_115 < V_77 -> V_116 ; V_115 ++ ) {
V_57 = F_53 ( V_77 , struct V_56 * , V_115 ) ;
V_114 = F_27 ( L_12 , V_93 . V_96 ) ;
if ( V_114 ) {
if ( ! strcmp ( V_114 , V_57 -> V_66 ) ) {
F_54 ( V_57 -> V_66 ) ;
V_57 -> V_66 = F_55 ( V_113 ) ;
}
F_54 ( V_114 ) ;
}
}
}
}
fclose ( V_112 ) ;
return 0 ;
}
static int F_56 ( const char * V_66 )
{
int V_117 ;
struct V_118 V_118 ;
V_117 = F_41 ( V_119 , V_120 , 0 ) ;
if ( V_117 == - 1 )
return - 1 ;
F_42 ( V_118 . V_121 , V_66 , sizeof( V_118 . V_121 ) ) ;
if ( F_43 ( V_117 , V_122 , & V_118 ) )
goto V_123;
V_118 . V_124 |= V_125 ;
if ( F_43 ( V_117 , V_126 , & V_118 ) )
goto V_123;
F_44 ( V_117 ) ;
return 0 ;
V_123:
F_44 ( V_117 ) ;
return - 1 ;
}
static int F_57 ( const char * V_106 )
{
int V_107 , V_96 , V_4 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
V_107 = F_47 ( V_106 ) ;
if ( V_107 )
return F_56 ( V_106 ) ;
if ( sscanf ( V_106 , L_12 , & V_96 ) != 1 )
return - V_127 ;
V_23 = F_38 ( V_78 ) ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_128 , 0 ) ;
F_48 ( T_2 , V_95 , V_96 ) ;
F_58 ( T_2 , V_129 , V_106 ) ;
F_48 ( T_2 , V_94 , V_61 ) ;
V_4 = F_11 ( T_2 , V_23 ) ;
if ( V_4 )
return V_4 ;
return F_56 ( V_106 ) ;
V_110:
fprintf ( V_8 , L_7 ) ;
return 2 ;
}
int F_59 ( const char * V_106 , int V_71 , int V_130 )
{
int V_107 , V_4 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
V_4 = F_57 ( V_106 ) ;
if ( V_4 )
return V_4 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_78 ) ;
V_107 = F_47 ( V_106 ) ;
#ifdef F_35
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_75 , 0 ) ;
#else
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_131 , 0 ) ;
#endif
F_48 ( T_2 , V_109 , V_107 ) ;
F_48 ( T_2 , V_97 , V_71 ) ;
switch ( V_130 ) {
#ifdef F_31
case V_64 :
F_48 ( T_2 , V_101 , V_102 ) ;
break;
case V_68 :
F_48 ( T_2 , V_101 , V_103 ) ;
break;
case V_69 :
F_48 ( T_2 , V_101 , V_104 ) ;
break;
case V_70 :
F_48 ( T_2 , V_101 , V_105 ) ;
break;
#endif
default:
break;
}
V_4 = F_11 ( T_2 , V_23 ) ;
return V_4 ;
V_110:
fprintf ( V_8 , L_7 ) ;
return 2 ;
}
void F_60 ( T_5 * V_77 )
{
struct V_56 * V_57 ;
if ( ! V_77 )
return;
while ( V_77 -> V_116 ) {
V_57 = F_53 ( V_77 , struct V_56 * , 0 ) ;
F_61 ( V_77 , 0 ) ;
F_62 ( V_57 -> V_62 , TRUE ) ;
F_54 ( V_57 -> V_66 ) ;
F_54 ( V_57 ) ;
}
F_62 ( V_77 , TRUE ) ;
}
T_5 * F_63 ( void )
{
T_5 * V_77 ;
if ( ! V_7 . V_2 )
return NULL ;
V_77 = F_26 ( FALSE , FALSE , sizeof( struct V_56 * ) ) ;
if ( ! V_77 )
return NULL ;
if ( F_50 ( V_77 ) ) {
F_60 ( V_77 ) ;
return NULL ;
}
return V_77 ;
}
int F_64 ( int V_71 )
{
if ( V_71 == 2484 )
return 14 ;
if ( V_71 < 2484 )
return ( V_71 - 2407 ) / 5 ;
return V_71 / 5 - 1000 ;
}
int
F_65 ( const T_10 * V_132 )
{
int V_18 = - 1 ;
if ( ! V_132 )
return - 1 ;
if ( ! strcmp ( V_132 , V_133 ) )
V_18 = V_64 ;
if ( ! strcmp ( V_132 , V_134 ) )
V_18 = V_68 ;
if ( ! strcmp ( V_132 , V_135 ) )
V_18 = V_69 ;
if ( ! strcmp ( V_132 , V_136 ) )
V_18 = V_70 ;
return V_18 ;
}
const T_10
* F_66 ( int type )
{
switch ( type ) {
case V_64 :
return V_133 ;
case V_68 :
return V_134 ;
case V_69 :
return V_135 ;
case V_70 :
return V_136 ;
}
return NULL ;
}
int F_5 ( void )
{
return - 1 ;
}
T_5 * F_63 ( void )
{
return NULL ;
}
int F_49 ( const char * V_106 V_15 , struct V_111 * V_93 V_15 )
{
return - 1 ;
}
void F_60 ( T_5 * V_77 V_15 )
{
}
int F_64 ( int V_71 V_15 )
{
return - 1 ;
}
int F_59 ( const char * V_106 V_15 , int V_71 V_15 , int V_130 V_15 )
{
return - 1 ;
}
int F_65 ( const T_10 * V_132 V_15 )
{
return - 1 ;
}
const T_10 * F_66 ( int type V_15 )
{
return NULL ;
}
