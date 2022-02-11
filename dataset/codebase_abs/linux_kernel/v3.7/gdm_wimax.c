static void F_1 ( T_1 * V_1 , T_2 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_3 && V_3 % 16 == 0 )
F_2 ( V_4 L_1 , * V_1 ++ ) ;
else
F_2 ( V_4 L_2 , * V_1 ++ ) ;
}
F_2 ( V_4 L_3 ) ;
}
static const char * F_3 ( T_3 V_5 )
{
static char V_1 [ 32 ] ;
const char * V_6 = L_4 ;
switch ( V_5 ) {
case V_7 :
V_6 = L_5 ;
break;
case V_8 :
V_6 = L_6 ;
break;
case V_9 :
V_6 = L_7 ;
break;
}
sprintf ( V_1 , L_8 , V_5 , V_6 ) ;
return V_1 ;
}
static const char * F_4 ( T_1 V_10 )
{
static char V_1 [ 32 ] ;
const char * V_6 = L_4 ;
switch ( V_10 ) {
case V_11 :
V_6 = L_9 ;
break;
case V_12 :
V_6 = L_10 ;
break;
case V_13 :
V_6 = L_11 ;
break;
}
sprintf ( V_1 , L_12 , V_10 , V_6 ) ;
return V_1 ;
}
static const char * F_5 ( T_3 V_14 )
{
static char V_1 [ 32 ] ;
const char * V_6 = L_4 ;
switch ( V_14 ) {
case 67 :
V_6 = L_13 ;
break;
case 68 :
V_6 = L_14 ;
break;
case 69 :
V_6 = L_15 ;
break;
}
sprintf ( V_1 , L_12 , V_14 , V_6 ) ;
return V_1 ;
}
static void F_6 ( const char * V_15 , T_1 * V_16 , int V_17 )
{
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
T_3 V_5 = 0 ;
T_1 V_10 = 0 ;
T_3 V_14 = 0 ;
V_5 = ( V_16 [ 12 ] << 8 ) | V_16 [ 13 ] ;
V_19 = (struct V_18 * ) ( V_16 + V_22 ) ;
if ( V_5 == V_8 ) {
V_21 = (struct V_20 * ) ( ( char * ) V_19 + sizeof( struct V_18 ) ) ;
V_10 = V_19 -> V_5 ;
V_14 = F_7 ( V_21 -> V_23 ) ;
} else if ( V_5 == V_9 ) {
struct V_24 * V_25 = (struct V_24 * ) V_16 ;
V_21 = (struct V_20 * ) ( ( char * ) V_25 + sizeof( struct V_24 ) ) ;
V_10 = V_25 -> V_26 ;
V_14 = F_7 ( V_21 -> V_23 ) ;
}
F_2 ( V_4 L_16 ,
V_15 , V_17 ,
F_3 ( V_5 ) ,
F_4 ( V_10 ) ,
F_5 ( V_14 ) ) ;
#if 1
if ( ! ( V_16 [ 0 ] == 0xff && V_16 [ 1 ] == 0xff ) ) {
if ( V_5 == V_8 ) {
F_2 ( V_4 L_17 ,
F_8 ( V_19 -> V_27 ) ) ;
} else if ( V_5 == V_9 ) {
#ifdef F_9
F_2 ( V_4 L_18 ,
F_9 ( V_19 -> V_27 ) ) ;
#else
F_2 ( V_4 L_19 , & V_19 -> V_27 ) ;
#endif
}
}
#endif
#if ( V_28 & V_29 )
F_1 ( V_16 , V_17 ) ;
#else
#if ( V_28 & V_30 )
if ( V_5 == V_7 )
F_1 ( V_16 , V_17 ) ;
#endif
#if ( V_28 & V_31 )
if ( V_5 == V_8 || V_5 == V_9 )
F_1 ( V_16 , V_17 ) ;
#else
#if ( V_28 & V_32 )
if ( V_10 == V_11 )
F_1 ( V_16 , V_17 ) ;
#endif
#if ( V_28 & V_33 )
if ( V_10 == V_12 )
F_1 ( V_16 , V_17 ) ;
#endif
#if ( V_28 & V_34 )
if ( V_10 == V_13 )
F_1 ( V_16 , V_17 ) ;
#endif
#endif
#endif
}
static inline int F_10 ( struct V_35 * * V_36 )
{
T_3 V_1 [ V_37 / sizeof( T_3 ) ] ;
struct V_35 * V_38 = * V_36 ;
int V_39 = 0 ;
if ( F_11 ( F_12 ( V_38 ) < V_37 ) ) {
struct V_35 * V_40 ;
V_40 = F_13 ( V_38 , V_37 ) ;
if ( V_40 == NULL )
return - V_41 ;
if ( V_38 -> V_42 )
F_14 ( V_40 , V_38 -> V_42 ) ;
F_15 ( V_38 ) ;
V_38 = V_40 ;
}
F_16 ( V_38 , V_37 ) ;
V_1 [ 0 ] = F_17 ( V_43 ) ;
V_1 [ 1 ] = F_17 ( V_38 -> V_17 - V_37 ) ;
memcpy ( V_38 -> V_16 , V_1 , V_37 ) ;
* V_36 = V_38 ;
return V_39 ;
}
static void F_18 ( struct V_44 * V_45 , T_3 type , void * V_46 ,
int V_17 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
#if F_20 ( V_48 )
T_1 * V_1 = ( T_1 * ) V_46 ;
T_3 V_49 = ( V_1 [ 0 ] << 8 ) | V_1 [ 1 ] ;
T_3 V_50 = ( V_1 [ 2 ] << 8 ) | V_1 [ 3 ] ;
F_2 ( V_4 L_20 , V_49 , V_50 ) ;
#endif
F_21 ( V_47 , V_46 , V_17 ) ;
}
static int F_22 ( void )
{
if ( ! V_51 . V_52 ) {
V_51 . V_53 = F_23 ( V_54 ,
F_18 ) ;
if ( V_51 . V_53 ) {
F_24 ( & V_51 . V_55 ) ;
F_24 ( & V_51 . V_56 ) ;
F_25 ( & V_51 . V_57 , V_58 ) ;
F_26 ( & V_51 . V_59 ) ;
}
}
if ( V_51 . V_53 ) {
V_51 . V_52 ++ ;
return 0 ;
}
F_2 ( V_60 L_21 ) ;
return - 1 ;
}
static void F_27 ( void )
{
if ( V_51 . V_53 && -- V_51 . V_52 == 0 ) {
struct V_61 * V_62 , * V_63 ;
unsigned long V_64 ;
F_28 ( & V_51 . V_59 , V_64 ) ;
F_29 (e, temp, &wm_event.evtq, list) {
F_30 ( & V_62 -> V_65 ) ;
F_31 ( V_62 ) ;
}
F_29 (e, temp, &wm_event.freeq, list) {
F_30 ( & V_62 -> V_65 ) ;
F_31 ( V_62 ) ;
}
F_32 ( & V_51 . V_59 , V_64 ) ;
F_33 ( V_51 . V_53 ) ;
V_51 . V_53 = NULL ;
}
}
static inline struct V_61 * F_34 ( void )
{
return F_35 ( sizeof( struct V_61 ) , V_66 ) ;
}
static inline void F_31 ( struct V_61 * V_62 )
{
F_36 ( V_62 ) ;
}
static struct V_61 * F_37 ( void )
{
struct V_61 * V_62 ;
if ( F_38 ( & V_51 . V_56 ) )
V_62 = F_34 () ;
else {
V_62 = F_39 ( V_51 . V_56 . V_67 , struct V_61 , V_65 ) ;
F_30 ( & V_62 -> V_65 ) ;
}
return V_62 ;
}
static void F_40 ( struct V_61 * V_62 )
{
F_41 ( ! V_62 ) ;
F_42 ( & V_62 -> V_65 , & V_51 . V_56 ) ;
}
static void V_58 ( struct V_68 * V_69 )
{
int V_70 ;
unsigned long V_64 ;
struct V_61 * V_62 ;
F_28 ( & V_51 . V_59 , V_64 ) ;
while ( ! F_38 ( & V_51 . V_55 ) ) {
V_62 = F_39 ( V_51 . V_55 . V_67 , struct V_61 , V_65 ) ;
F_32 ( & V_51 . V_59 , V_64 ) ;
sscanf ( V_62 -> V_45 -> V_6 , L_22 , & V_70 ) ;
F_43 ( V_51 . V_53 , V_70 , 0 , V_62 -> V_71 , V_62 -> V_2 ) ;
F_28 ( & V_51 . V_59 , V_64 ) ;
F_30 ( & V_62 -> V_65 ) ;
F_40 ( V_62 ) ;
}
F_32 ( & V_51 . V_59 , V_64 ) ;
}
static int F_44 ( struct V_44 * V_45 , char * V_1 , int V_2 )
{
struct V_61 * V_62 ;
unsigned long V_64 ;
#if F_20 ( V_48 )
T_3 V_49 = ( ( T_1 ) V_1 [ 0 ] << 8 ) | ( T_1 ) V_1 [ 1 ] ;
T_3 V_50 = ( ( T_1 ) V_1 [ 2 ] << 8 ) | ( T_1 ) V_1 [ 3 ] ;
F_2 ( V_4 L_23 , V_49 , V_50 ) ;
#endif
F_28 ( & V_51 . V_59 , V_64 ) ;
V_62 = F_37 () ;
if ( ! V_62 ) {
F_2 ( V_60 L_24 , V_72 ) ;
F_32 ( & V_51 . V_59 , V_64 ) ;
return - V_41 ;
}
V_62 -> V_45 = V_45 ;
V_62 -> V_2 = V_2 ;
memcpy ( V_62 -> V_71 , V_1 , V_2 ) ;
F_42 ( & V_62 -> V_65 , & V_51 . V_55 ) ;
F_32 ( & V_51 . V_59 , V_64 ) ;
F_45 ( & V_51 . V_57 ) ;
return 0 ;
}
static void F_46 ( void * V_73 )
{
struct V_47 * V_47 = V_73 ;
if ( F_47 ( V_47 -> V_74 ) )
F_48 ( V_47 -> V_74 ) ;
}
int F_49 ( struct V_35 * V_38 , struct V_44 * V_45 )
{
int V_39 = 0 ;
struct V_47 * V_47 = F_19 ( V_45 ) ;
V_39 = F_50 ( V_47 , V_38 -> V_16 , V_38 -> V_17 , F_46 ,
V_47 ) ;
if ( V_39 == - V_75 ) {
F_51 ( V_45 ) ;
V_39 = 0 ;
}
if ( V_39 ) {
F_52 ( V_38 , V_37 ) ;
return V_39 ;
}
V_47 -> V_76 . V_77 ++ ;
V_47 -> V_76 . V_78 += V_38 -> V_17 - V_37 ;
F_15 ( V_38 ) ;
return V_39 ;
}
static int F_53 ( struct V_35 * V_38 , struct V_44 * V_45 )
{
int V_39 = 0 ;
struct V_47 * V_47 = F_19 ( V_45 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_47 -> V_81 [ V_82 ] . V_1 ;
#if F_20 ( V_83 )
F_6 ( L_25 , V_38 -> V_16 , V_38 -> V_17 ) ;
#endif
V_39 = F_10 ( & V_38 ) ;
if ( V_39 < 0 ) {
F_52 ( V_38 , V_37 ) ;
return V_39 ;
}
#if ! F_20 ( V_84 )
if ( ! V_80 )
F_2 ( V_60 L_26 ) ;
else if ( V_80 -> V_85 != V_86 ) {
F_2 ( V_87 L_27 ,
V_80 -> V_85 ) ;
F_15 ( V_38 ) ;
return 0 ;
}
#endif
#if F_20 ( V_88 )
V_39 = F_54 ( V_38 , V_45 ) ;
#else
V_39 = F_49 ( V_38 , V_45 ) ;
#endif
return V_39 ;
}
static int F_55 ( struct V_44 * V_45 , struct V_89 * V_90 )
{
if ( V_45 -> V_64 & V_91 )
return - V_92 ;
return 0 ;
}
static void F_56 ( struct V_44 * V_45 , char * V_93 )
{
T_3 V_94 [ 32 / sizeof( T_3 ) ] ;
T_1 * V_95 = ( T_1 * ) & V_94 [ 0 ] ;
struct V_47 * V_47 = F_19 ( V_45 ) ;
memcpy ( V_45 -> V_96 , V_93 , V_45 -> V_97 ) ;
V_94 [ 0 ] = F_17 ( V_98 ) ;
V_94 [ 1 ] = F_17 ( 8 ) ;
V_95 [ 4 ] = 0 ;
V_95 [ 5 ] = 6 ;
memcpy ( V_95 + 6 , V_93 , V_45 -> V_97 ) ;
F_21 ( V_47 , V_95 , V_37 + 8 ) ;
}
static int F_57 ( struct V_44 * V_45 , void * V_99 )
{
struct V_100 * V_101 = V_99 ;
if ( F_58 ( V_45 ) )
return - V_92 ;
if ( ! F_59 ( V_101 -> V_102 ) )
return - V_103 ;
F_56 ( V_45 , V_101 -> V_102 ) ;
return 0 ;
}
static struct V_104 * F_60 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
return & V_47 -> V_76 ;
}
static int F_61 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_47 -> V_81 [ V_82 ] . V_1 ;
F_62 ( V_45 ) ;
if ( V_80 && V_80 -> V_85 != V_105 )
F_63 ( V_45 , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_47 -> V_81 [ V_82 ] . V_1 ;
F_51 ( V_45 ) ;
if ( V_80 && V_80 -> V_85 != V_105 )
F_63 ( V_45 , 0 ) ;
return 0 ;
}
static void F_65 ( void * * V_1 )
{
if ( V_1 && * V_1 ) {
F_36 ( * V_1 ) ;
* V_1 = NULL ;
}
}
static int F_66 ( struct V_106 * V_107 , struct V_106 * V_108 )
{
int V_2 ;
V_2 = V_107 -> V_2 < V_108 -> V_2 ? V_107 -> V_2 : V_108 -> V_2 ;
V_107 -> V_2 = V_2 ;
if ( V_108 -> V_2 ) {
if ( ! V_107 -> V_1 )
return - V_109 ;
if ( F_67 ( V_107 -> V_1 , V_108 -> V_1 , V_2 ) )
return - V_110 ;
}
return 0 ;
}
static int F_68 ( struct V_106 * V_107 , struct V_106 * V_108 )
{
if ( ! V_108 -> V_2 ) {
V_107 -> V_2 = 0 ;
return 0 ;
}
if ( ! V_108 -> V_1 )
return - V_109 ;
if ( ! ( V_107 -> V_1 && V_107 -> V_2 == V_108 -> V_2 ) ) {
F_65 ( & V_107 -> V_1 ) ;
V_107 -> V_1 = F_35 ( V_108 -> V_2 , V_111 ) ;
if ( V_107 -> V_1 == NULL )
return - V_41 ;
}
if ( F_69 ( V_107 -> V_1 , V_108 -> V_1 , V_108 -> V_2 ) ) {
F_65 ( & V_107 -> V_1 ) ;
return - V_110 ;
}
V_107 -> V_2 = V_108 -> V_2 ;
return 0 ;
}
static void F_70 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_112 ; V_3 ++ )
F_65 ( & V_47 -> V_81 [ V_3 ] . V_1 ) ;
}
static void F_71 ( struct V_44 * V_45 , struct V_79 * V_113 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
struct V_79 * V_114 =
(struct V_79 * ) V_47 -> V_81 [ V_82 ] . V_1 ;
if ( ! V_114 )
return;
if ( V_114 -> V_85 != V_113 -> V_85 ||
V_114 -> V_115 != V_113 -> V_115 ) {
if ( V_113 -> V_85 == V_86 )
F_72 ( V_45 ) ;
else if ( V_114 -> V_85 == V_86 ) {
F_73 ( V_45 ) ;
#if F_20 ( V_88 )
F_74 ( V_47 ) ;
#endif
}
F_75 ( V_45 , V_113 ) ;
}
}
static int F_76 ( struct V_44 * V_45 , struct V_116 * V_117 , int V_118 )
{
struct V_119 * V_120 = (struct V_119 * ) V_117 ;
struct V_47 * V_47 = F_19 ( V_45 ) ;
int V_39 ;
if ( V_118 != V_121 )
return - V_122 ;
switch ( V_120 -> V_118 ) {
case V_123 :
case V_124 :
if ( V_120 -> V_125 >= V_112 ) {
F_2 ( V_60
L_28 ,
V_72 , V_120 -> V_125 ) ;
return - V_122 ;
}
if ( V_120 -> V_118 == V_123 ) {
V_39 = F_66 ( & V_120 -> V_16 ,
& V_47 -> V_81 [ V_120 -> V_125 ] ) ;
if ( V_39 < 0 )
return V_39 ;
} else if ( V_120 -> V_118 == V_124 ) {
if ( V_120 -> V_125 == V_82 ) {
F_71 ( V_45 ,
(struct V_79 * ) V_120 -> V_16 . V_1 ) ;
}
V_39 = F_68 (
& V_47 -> V_81 [ V_120 -> V_125 ] , & V_120 -> V_16 ) ;
if ( V_39 < 0 )
return V_39 ;
}
break;
default:
F_2 ( V_60 L_29 , V_72 , V_118 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_77 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
struct V_126 * V_127 = (struct V_126 * ) V_1 ;
T_3 V_17 = 0 ;
T_2 V_128 = 0 ;
#define F_78 0
#define F_79 1
#define F_80 2
#define F_81 3
V_17 = 0 ;
V_127 -> V_129 = F_17 ( V_130 ) ;
V_127 -> V_16 [ V_17 ++ ] = F_82 ( V_131 ) ;
V_127 -> V_132 = F_17 ( V_17 ) ;
F_21 ( V_47 , V_127 , V_37 + V_17 ) ;
V_128 = ( 1 << F_79 ) | ( 1 << F_78 ) ;
#if F_20 ( V_88 )
V_128 |= ( 1 << F_80 ) ;
#endif
#if F_20 ( V_133 )
V_128 |= ( 1 << F_81 ) ;
#endif
V_17 = 0 ;
V_127 -> V_129 = F_17 ( V_98 ) ;
V_127 -> V_16 [ V_17 ++ ] = F_82 ( V_134 ) ;
V_127 -> V_16 [ V_17 ++ ] = F_83 ( V_134 ) ;
V_128 = F_84 ( V_128 ) ;
memcpy ( & V_127 -> V_16 [ V_17 ] , & V_128 , F_83 ( V_134 ) ) ;
V_17 += F_83 ( V_134 ) ;
V_127 -> V_132 = F_17 ( V_17 ) ;
F_21 ( V_47 , V_127 , V_37 + V_17 ) ;
F_2 ( V_135 L_30 , F_85 ( V_128 ) ) ;
}
static int F_86 ( T_1 * V_1 , T_1 * V_136 , T_3 * V_137 , T_1 * * V_138 )
{
#define F_87 ( T_4 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_139 ;
* V_136 = V_1 [ 0 ] ;
if ( V_1 [ 1 ] == 0x82 ) {
* V_137 = F_88 ( F_87 ( & V_1 [ 2 ] ) ) ;
V_139 = 1 + 3 ;
} else {
* V_137 = V_1 [ 1 ] ;
V_139 = 1 + 1 ;
}
* V_138 = & V_1 [ V_139 ] ;
V_139 += * V_137 ;
return V_139 ;
}
static int F_89 ( struct V_44 * V_45 , char * V_1 ,
int V_17 )
{
T_1 V_136 , * V_138 ;
T_3 V_137 ;
T_3 V_129 , V_140 ;
int V_141 = V_37 ;
V_129 = F_88 ( * ( T_3 * ) & V_1 [ 0 ] ) ;
V_140 = F_88 ( * ( T_3 * ) & V_1 [ 2 ] ) ;
if ( V_17 < V_140 + V_37 ) {
F_2 ( V_60 L_31 , V_72 ,
V_140 + V_37 , V_17 ) ;
return - 1 ;
}
if ( V_129 == V_142 ) {
if ( V_140 < 2 ) {
F_2 ( V_60 L_32 ,
V_72 , V_129 , V_17 ) ;
return - 1 ;
}
V_141 += F_86 ( & V_1 [ V_141 ] , & V_136 , & V_137 , & V_138 ) ;
if ( V_136 == F_82 ( V_131 ) ) {
if ( V_137 != V_45 -> V_97 ) {
F_2 ( V_60
L_33
L_34 , V_72 , V_136 , V_137 ) ;
return - 1 ;
}
F_2 ( V_135 L_35 ,
V_45 -> V_96 , V_138 ) ;
memcpy ( V_45 -> V_96 , V_138 , V_45 -> V_97 ) ;
return 1 ;
}
}
F_44 ( V_45 , V_1 , V_17 ) ;
return 0 ;
}
static void F_90 ( struct V_44 * V_45 , char * V_1 , int V_17 )
{
struct V_47 * V_47 = F_19 ( V_45 ) ;
struct V_35 * V_38 ;
int V_39 ;
#if F_20 ( V_83 )
F_6 ( L_36 , V_1 , V_17 ) ;
#endif
V_38 = F_91 ( V_17 + 2 ) ;
if ( ! V_38 ) {
F_2 ( V_60 L_37 , V_72 ) ;
return;
}
F_92 ( V_38 , 2 ) ;
V_47 -> V_76 . V_143 ++ ;
V_47 -> V_76 . V_144 += V_17 ;
memcpy ( F_93 ( V_38 , V_17 ) , V_1 , V_17 ) ;
V_38 -> V_45 = V_45 ;
V_38 -> V_5 = F_94 ( V_38 , V_45 ) ;
V_39 = F_95 () ? F_96 ( V_38 ) : F_97 ( V_38 ) ;
if ( V_39 == V_145 )
F_2 ( V_60 L_38 , V_72 ) ;
}
static void F_98 ( struct V_44 * V_45 , char * V_1 ,
int V_17 )
{
#define F_99 4
#define F_100 4
struct V_126 * V_127 ;
int V_132 ;
while ( V_17 > 0 ) {
V_127 = (struct V_126 * ) V_1 ;
if ( F_88 ( V_127 -> V_129 ) != V_146 ) {
F_2 ( V_60 L_39 ,
F_88 ( V_127 -> V_129 ) ) ;
break;
}
V_132 = F_88 ( V_127 -> V_132 ) ;
F_90 ( V_45 , V_127 -> V_16 , V_132 ) ;
if ( V_132 & 0x3 ) {
V_132 += F_99 - ( V_132 & 0x3 ) ;
}
V_132 += V_37 + F_100 ;
V_17 -= V_132 ;
V_1 += V_132 ;
}
}
static void F_101 ( struct V_44 * V_45 , char * V_1 , int V_17 )
{
#if F_20 ( V_88 )
struct V_47 * V_47 = F_19 ( V_45 ) ;
#endif
T_3 V_129 , V_140 ;
if ( V_17 == 0 )
return;
V_129 = F_88 ( * ( T_3 * ) & V_1 [ 0 ] ) ;
V_140 = F_88 ( * ( T_3 * ) & V_1 [ 2 ] ) ;
if ( V_17 < V_140 + V_37 ) {
if ( V_17 )
F_2 ( V_60 L_31 ,
V_72 , V_140 + V_37 , V_17 ) ;
return;
}
switch ( V_129 ) {
case V_147 :
F_98 ( V_45 , & V_1 [ V_37 ] ,
V_140 ) ;
break;
case V_146 :
F_90 ( V_45 , & V_1 [ V_37 ] , V_140 ) ;
break;
#if F_20 ( V_88 )
case V_148 :
F_102 ( V_47 , V_1 , V_17 ) ;
break;
#endif
case V_149 :
if ( V_1 [ 4 ] == 0 ) {
if ( ! F_47 ( V_45 ) )
F_51 ( V_45 ) ;
} else if ( V_1 [ 4 ] == 1 ) {
if ( F_47 ( V_45 ) )
F_48 ( V_45 ) ;
}
break;
default:
F_44 ( V_45 , V_1 , V_17 ) ;
break;
}
}
static void F_75 ( struct V_44 * V_45 , struct V_79 * V_80 )
{
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
T_1 * V_94 = ( T_1 * ) & V_1 [ 0 ] ;
V_1 [ 0 ] = F_17 ( V_150 ) ;
V_1 [ 1 ] = F_17 ( sizeof( struct V_79 ) ) ;
memcpy ( & V_94 [ V_37 ] , V_80 , sizeof( struct V_79 ) ) ;
F_44 ( V_45 , V_94 ,
V_37 + sizeof( struct V_79 ) ) ;
}
static void F_63 ( struct V_44 * V_45 , int V_151 )
{
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
struct V_126 * V_127 = (struct V_126 * ) V_1 ;
unsigned char V_152 ;
V_152 = V_151 ? V_153 : V_154 ;
V_127 -> V_129 = F_17 ( V_155 ) ;
V_127 -> V_132 = F_17 ( sizeof( V_152 ) ) ;
V_127 -> V_16 [ 0 ] = V_152 ;
F_44 ( V_45 , ( char * ) V_127 , V_37 + sizeof( V_152 ) ) ;
}
static void F_103 ( void * V_73 , void * V_16 , int V_17 )
{
struct V_47 * V_47 = V_73 ;
F_101 ( V_47 -> V_74 , V_16 , V_17 ) ;
F_104 ( V_47 , F_103 , V_47 ) ;
}
static void F_105 ( void * V_73 , void * V_16 , int V_17 )
{
struct V_47 * V_47 = V_73 ;
int V_39 ;
V_39 = F_89 ( V_47 -> V_74 , V_16 , V_17 ) ;
if ( V_39 == 1 )
F_104 ( V_47 , F_103 , V_47 ) ;
else {
if ( V_39 < 0 )
F_2 ( V_60 L_40 , V_39 ) ;
F_104 ( V_47 , F_105 , V_47 ) ;
#if 0
gdm_wimax_prepare_device(nic->netdev);
#endif
}
}
static void F_106 ( struct V_47 * V_47 )
{
F_104 ( V_47 , F_105 , V_47 ) ;
}
int F_107 ( struct V_156 * V_156 , struct V_157 * V_158 )
{
struct V_47 * V_47 = NULL ;
struct V_44 * V_45 ;
int V_39 ;
V_45 = (struct V_44 * ) F_108 ( sizeof( * V_47 ) ,
L_22 , V_159 ) ;
if ( V_45 == NULL ) {
F_2 ( V_60 L_41 ) ;
return - V_41 ;
}
F_109 ( V_45 , V_158 ) ;
V_45 -> V_160 = 1400 ;
V_45 -> V_161 = & V_162 ;
V_45 -> V_64 &= ~ V_163 ;
memcpy ( V_45 -> V_96 , V_164 , sizeof( V_164 ) ) ;
V_47 = F_19 ( V_45 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_74 = V_45 ;
V_47 -> V_156 = V_156 ;
V_156 -> V_74 = V_45 ;
V_39 = F_22 () ;
if ( V_39 < 0 ) {
F_2 ( V_60 L_42 ) ;
goto V_165;
}
V_39 = F_110 ( V_45 ) ;
if ( V_39 )
goto V_165;
#if F_20 ( V_84 )
F_62 ( V_45 ) ;
F_72 ( V_45 ) ;
#else
F_73 ( V_45 ) ;
#endif
#ifdef V_88
F_111 ( V_47 ) ;
#endif
F_106 ( V_47 ) ;
F_77 ( V_45 ) ;
return 0 ;
V_165:
F_2 ( V_60 L_43 ) ;
F_112 ( V_45 ) ;
return V_39 ;
}
void F_113 ( struct V_156 * V_156 )
{
struct V_47 * V_47 = F_19 ( V_156 -> V_74 ) ;
struct V_79 * V_80 = (struct V_79 * ) V_47 -> V_81 [ V_82 ] . V_1 ;
if ( V_80 )
V_80 -> V_85 = V_105 ;
F_114 ( V_47 -> V_74 ) ;
F_27 () ;
#if F_20 ( V_88 )
F_74 ( V_47 ) ;
#endif
F_70 ( V_156 -> V_74 ) ;
F_112 ( V_47 -> V_74 ) ;
}
