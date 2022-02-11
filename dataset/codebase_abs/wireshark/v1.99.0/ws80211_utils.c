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
volatile int V_4 ;
if ( ! V_7 . V_2 )
return - V_10 ;
V_4 = F_12 ( V_7 . V_2 , T_2 ) ;
if ( V_4 < 0 )
goto V_24;
V_4 = 1 ;
F_13 ( V_23 , V_25 , F_8 , ( void * ) & V_4 ) ;
F_14 ( V_23 , V_26 , V_25 , F_9 , ( void * ) & V_4 ) ;
F_14 ( V_23 , V_27 , V_25 , F_10 , ( void * ) & V_4 ) ;
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
{ V_41 , 0 , 0 } ,
{ V_42 , 0 , 0 } ,
{ V_43 , 0 , 0 } ,
{ V_43 , 0 , 0 } ,
{ V_43 , 0 , 0 } ,
{ V_43 , 0 , 0 } ,
{ V_42 , 0 , 0 }
} ;
struct V_28 * V_44 ;
struct V_28 * V_45 ;
struct V_28 * V_46 ;
int V_47 = 1 ;
int V_48 , V_49 , V_50 ;
struct V_51 * V_52 ;
int V_53 = 0 ;
F_20 ( V_29 , V_30 , F_21 ( V_32 , 0 ) ,
F_22 ( V_32 , 0 ) , NULL ) ;
if ( ! V_29 [ V_54 ] )
return V_21 ;
if ( V_29 [ V_55 ] ) {
F_23 (nl_mode, tb_msg[NL80211_ATTR_SUPPORTED_IFTYPES], rem_mode) {
if ( F_24 ( V_46 ) == V_56 )
V_53 = 1 ;
}
}
if ( ! V_53 )
return V_21 ;
V_52 = (struct V_51 * ) F_25 ( sizeof( * V_52 ) ) ;
if ( ! V_52 )
return V_21 ;
V_52 -> V_57 = F_26 ( FALSE , FALSE , sizeof( int ) ) ;
V_52 -> V_58 = 1 << V_59 ;
if ( V_29 [ V_60 ] ) {
V_52 -> V_61 = F_27 ( L_5 ,
F_28 ( V_29 [ V_60 ] ) ) ;
}
F_23 (nl_band, tb_msg[NL80211_ATTR_WIPHY_BANDS], rem_band) {
V_47 ++ ;
F_20 ( V_35 , V_36 ,
(struct V_28 * ) F_29 ( V_44 ) ,
F_30 ( V_44 ) , NULL ) ;
#ifdef F_31
if ( V_35 [ F_31 ] ) {
T_3 V_62 ;
V_52 -> V_58 |= 1 << V_63 ;
V_62 = ! ! ( F_32 ( V_35 [ F_31 ] ) & 0x02 ) ;
if ( V_62 ) {
V_52 -> V_58 |= 1 << V_64 ;
V_52 -> V_58 |= 1 << V_65 ;
}
}
#endif
F_23 (nl_freq, tb_band[NL80211_BAND_ATTR_FREQS], rem_freq) {
T_4 V_66 ;
F_20 ( V_37 , V_38 ,
(struct V_28 * ) F_29 ( V_45 ) ,
F_30 ( V_45 ) , V_40 ) ;
if ( ! V_37 [ V_67 ] )
continue;
if ( V_37 [ V_68 ] )
continue;
V_66 = F_33 ( V_37 [ V_67 ] ) ;
F_34 ( V_52 -> V_57 , V_66 ) ;
}
}
#ifdef F_35
if ( V_29 [ V_69 ] ) {
int V_70 ;
struct V_28 * V_71 ;
F_23 (nl_cmd, tb_msg[NL80211_ATTR_SUPPORTED_COMMANDS], cmd) {
if( F_33 ( V_71 ) == V_72 )
V_52 -> V_73 = TRUE ;
}
}
#else
V_52 -> V_73 = TRUE ;
#endif
F_34 ( V_34 -> V_74 , V_52 ) ;
return V_21 ;
}
static int F_36 ( T_5 * V_74 )
{
struct V_33 V_34 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_75 ) ;
V_34 . V_74 = V_74 ;
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
V_76 , V_77 , 0 ) ;
F_14 ( V_23 , V_78 , V_25 , F_17 , & V_34 ) ;
return F_11 ( T_2 , V_23 ) ;
}
static int F_40 ( const char * V_61 )
{
int V_79 ;
int V_18 = - 1 ;
struct {
char V_80 [ V_81 ] ;
T_6 V_82 ;
T_7 V_83 ;
T_8 V_84 ;
T_8 V_85 ;
} V_86 ;
V_79 = F_41 ( V_87 , V_88 , 0 ) ;
if ( V_79 == - 1 )
return - 1 ;
F_42 ( V_86 . V_80 , V_61 , V_81 ) ;
if ( F_43 ( V_79 , 0x8B05 , & V_86 ) == 0 ) {
if ( V_86 . V_83 == 6 )
V_18 = V_86 . V_82 ;
}
F_44 ( V_79 ) ;
return V_18 ;
}
static int F_45 ( struct V_20 * T_2 , void * V_17 )
{
struct V_31 * V_32 = (struct V_31 * ) F_18 ( F_19 ( T_2 ) ) ;
struct V_28 * V_29 [ V_30 + 1 ] ;
struct V_89 * V_90 = (struct V_89 * ) V_17 ;
F_20 ( V_29 , V_30 , F_21 ( V_32 , 0 ) ,
F_22 ( V_32 , 0 ) , NULL ) ;
if ( V_29 [ V_91 ] ) {
V_90 -> type = F_33 ( V_29 [ V_91 ] ) ;
}
if ( V_29 [ V_92 ] ) {
V_90 -> V_93 = F_33 ( V_29 [ V_92 ] ) ;
}
if ( V_29 [ V_94 ] ) {
V_90 -> V_95 -> V_96 = F_33 ( V_29 [ V_94 ] ) ;
V_90 -> V_95 -> V_97 = V_59 ;
if ( V_29 [ V_98 ] ) {
switch ( F_33 ( V_29 [ V_98 ] ) ) {
case V_99 :
V_90 -> V_95 -> V_97 = V_59 ;
break;
case V_100 :
V_90 -> V_95 -> V_97 = V_63 ;
break;
case V_101 :
V_90 -> V_95 -> V_97 = V_64 ;
break;
case V_102 :
V_90 -> V_95 -> V_97 = V_65 ;
break;
}
}
}
return V_21 ;
}
static int F_46 ( const char * V_103 , struct V_89 * V_90 )
{
int V_104 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_75 ) ;
V_104 = F_47 ( V_103 ) ;
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_105 , 0 ) ;
F_48 ( T_2 , V_106 , V_104 ) ;
F_14 ( V_23 , V_78 , V_25 , F_45 , V_90 ) ;
if ( F_11 ( T_2 , V_23 ) )
return - 1 ;
if ( V_90 -> V_95 -> V_96 == - 1 )
V_90 -> V_95 -> V_96 = F_40 ( V_103 ) ;
return 0 ;
V_107:
fprintf ( V_8 , L_7 ) ;
return - 1 ;
}
int F_49 ( const char * V_103 , struct V_108 * V_90 )
{
struct V_89 V_89 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_89 . V_95 = V_90 ;
V_89 . type = - 1 ;
V_89 . V_93 = - 1 ;
V_89 . V_95 -> V_96 = - 1 ;
V_89 . V_95 -> V_97 = V_59 ;
return F_46 ( V_103 , & V_89 ) ;
}
static int F_50 ( T_5 * V_74 )
{
T_9 * V_109 ;
char line [ 200 ] ;
char * V_110 ;
T_10 * V_111 ;
char * V_18 ;
int V_84 ;
unsigned int V_112 ;
struct V_108 V_95 = { - 1 , V_59 } ;
struct V_89 V_90 ;
struct V_51 * V_52 ;
F_36 ( V_74 ) ;
V_109 = F_51 ( L_8 , L_9 ) ;
if( ! V_109 ) {
fprintf ( V_8 , L_10 ) ;
return - V_13 ;
}
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
V_18 = fgets ( line , sizeof( line ) , V_109 ) ;
if ( V_18 == NULL ) {
fprintf ( V_8 , L_11 ) ;
fclose ( V_109 ) ;
return - 1 ;
}
}
while( fgets ( line , sizeof( line ) , V_109 ) ) {
V_110 = F_52 ( line , ':' ) ;
if ( ! V_110 )
continue;
* V_110 = 0 ;
V_110 = line ;
while ( * V_110 && * V_110 == ' ' )
V_110 ++ ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_95 = & V_95 ;
F_46 ( V_110 , & V_90 ) ;
if ( V_90 . type == V_56 ) {
for ( V_112 = 0 ; V_112 < V_74 -> V_113 ; V_112 ++ ) {
V_52 = F_53 ( V_74 , struct V_51 * , V_112 ) ;
V_111 = F_27 ( L_12 , V_90 . V_93 ) ;
if ( V_111 ) {
if ( ! strcmp ( V_111 , V_52 -> V_61 ) ) {
F_54 ( V_52 -> V_61 ) ;
V_52 -> V_61 = F_55 ( V_110 ) ;
}
F_54 ( V_111 ) ;
}
}
}
}
fclose ( V_109 ) ;
return 0 ;
}
static int F_56 ( const char * V_61 )
{
int V_114 ;
struct V_115 V_115 ;
V_114 = F_41 ( V_116 , V_117 , 0 ) ;
if ( V_114 == - 1 )
return - 1 ;
F_42 ( V_115 . V_118 , V_61 , sizeof( V_115 . V_118 ) ) ;
if ( F_43 ( V_114 , V_119 , & V_115 ) )
goto V_120;
V_115 . V_121 |= V_122 ;
if ( F_43 ( V_114 , V_123 , & V_115 ) )
goto V_120;
F_44 ( V_114 ) ;
return 0 ;
V_120:
F_44 ( V_114 ) ;
return - 1 ;
}
static int F_57 ( const char * V_103 )
{
int V_104 , V_93 , V_4 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
V_104 = F_47 ( V_103 ) ;
if ( V_104 )
return F_56 ( V_103 ) ;
if ( sscanf ( V_103 , L_12 , & V_93 ) != 1 )
return - V_124 ;
V_23 = F_38 ( V_75 ) ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_125 , 0 ) ;
F_48 ( T_2 , V_92 , V_93 ) ;
F_58 ( T_2 , V_126 , V_103 ) ;
F_48 ( T_2 , V_91 , V_56 ) ;
V_4 = F_11 ( T_2 , V_23 ) ;
if ( V_4 )
return V_4 ;
return F_56 ( V_103 ) ;
V_107:
fprintf ( V_8 , L_7 ) ;
return 2 ;
}
int F_59 ( const char * V_103 , int V_66 , int V_127 )
{
int V_104 , V_4 ;
struct V_20 * T_2 ;
struct V_22 * V_23 ;
V_4 = F_57 ( V_103 ) ;
if ( V_4 )
return V_4 ;
T_2 = F_37 () ;
if ( ! T_2 ) {
fprintf ( V_8 , L_6 ) ;
return 2 ;
}
V_23 = F_38 ( V_75 ) ;
V_104 = F_47 ( V_103 ) ;
#ifdef F_35
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_72 , 0 ) ;
#else
F_39 ( T_2 , 0 , 0 , V_7 . V_12 , 0 ,
0 , V_128 , 0 ) ;
#endif
F_48 ( T_2 , V_106 , V_104 ) ;
F_48 ( T_2 , V_94 , V_66 ) ;
switch ( V_127 ) {
#ifdef F_31
case V_59 :
F_48 ( T_2 , V_98 , V_99 ) ;
break;
case V_63 :
F_48 ( T_2 , V_98 , V_100 ) ;
break;
case V_64 :
F_48 ( T_2 , V_98 , V_101 ) ;
break;
case V_65 :
F_48 ( T_2 , V_98 , V_102 ) ;
break;
#endif
default:
break;
}
V_4 = F_11 ( T_2 , V_23 ) ;
return V_4 ;
V_107:
fprintf ( V_8 , L_7 ) ;
return 2 ;
}
void F_60 ( T_5 * V_74 )
{
struct V_51 * V_52 ;
if ( ! V_74 )
return;
while ( V_74 -> V_113 ) {
V_52 = F_53 ( V_74 , struct V_51 * , 0 ) ;
F_61 ( V_74 , 0 ) ;
F_62 ( V_52 -> V_57 , TRUE ) ;
F_54 ( V_52 -> V_61 ) ;
F_54 ( V_52 ) ;
}
F_62 ( V_74 , TRUE ) ;
}
T_5 * F_63 ( void )
{
T_5 * V_74 ;
if ( ! V_7 . V_2 )
return NULL ;
V_74 = F_26 ( FALSE , FALSE , sizeof( struct V_51 * ) ) ;
if ( ! V_74 )
return NULL ;
if ( F_50 ( V_74 ) ) {
F_60 ( V_74 ) ;
return NULL ;
}
return V_74 ;
}
int F_64 ( int V_66 )
{
if ( V_66 == 2484 )
return 14 ;
if ( V_66 < 2484 )
return ( V_66 - 2407 ) / 5 ;
return V_66 / 5 - 1000 ;
}
int
F_65 ( const T_10 * V_129 )
{
int V_18 = - 1 ;
if ( ! V_129 )
return - 1 ;
if ( ! strcmp ( V_129 , V_130 ) )
V_18 = V_59 ;
if ( ! strcmp ( V_129 , V_131 ) )
V_18 = V_63 ;
if ( ! strcmp ( V_129 , V_132 ) )
V_18 = V_64 ;
if ( ! strcmp ( V_129 , V_133 ) )
V_18 = V_65 ;
return V_18 ;
}
const T_10
* F_66 ( int type )
{
switch ( type ) {
case V_59 :
return V_130 ;
case V_63 :
return V_131 ;
case V_64 :
return V_132 ;
case V_65 :
return V_133 ;
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
int F_49 ( const char * V_103 V_15 , struct V_108 * V_90 V_15 )
{
return - 1 ;
}
void F_60 ( T_5 * V_74 V_15 )
{
}
int F_64 ( int V_66 V_15 )
{
return - 1 ;
}
int F_59 ( const char * V_103 V_15 , int V_66 V_15 , int V_127 V_15 )
{
return - 1 ;
}
int F_65 ( const T_10 * V_129 V_15 )
{
return - 1 ;
}
const T_10 * F_66 ( int type V_15 )
{
return NULL ;
}
