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
if ( ! ( V_16 [ 0 ] == 0xff && V_16 [ 1 ] == 0xff ) ) {
if ( V_5 == V_8 ) {
F_2 ( V_4 L_17 , & V_19 -> V_27 ) ;
} else if ( V_5 == V_9 ) {
F_2 ( V_4 L_18 , & V_19 -> V_27 ) ;
}
}
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
static inline int F_8 ( struct V_35 * * V_36 )
{
T_3 V_1 [ V_37 / sizeof( T_3 ) ] ;
struct V_35 * V_38 = * V_36 ;
int V_39 = 0 ;
if ( F_9 ( F_10 ( V_38 ) < V_37 ) ) {
struct V_35 * V_40 ;
V_40 = F_11 ( V_38 , V_37 ) ;
if ( V_40 == NULL )
return - V_41 ;
if ( V_38 -> V_42 )
F_12 ( V_40 , V_38 -> V_42 ) ;
F_13 ( V_38 ) ;
V_38 = V_40 ;
}
F_14 ( V_38 , V_37 ) ;
V_1 [ 0 ] = F_15 ( V_43 ) ;
V_1 [ 1 ] = F_15 ( V_38 -> V_17 - V_37 ) ;
memcpy ( V_38 -> V_16 , V_1 , V_37 ) ;
* V_36 = V_38 ;
return V_39 ;
}
static void F_16 ( struct V_44 * V_45 , T_3 type , void * V_46 ,
int V_17 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
#if F_18 ( V_48 )
T_1 * V_1 = ( T_1 * ) V_46 ;
T_3 V_49 = ( V_1 [ 0 ] << 8 ) | V_1 [ 1 ] ;
T_3 V_50 = ( V_1 [ 2 ] << 8 ) | V_1 [ 3 ] ;
F_2 ( V_4 L_19 , V_49 , V_50 ) ;
#endif
F_19 ( V_47 , V_46 , V_17 ) ;
}
static int F_20 ( void )
{
if ( ! V_51 . V_52 ) {
V_51 . V_53 = F_21 ( V_54 ,
F_16 ) ;
if ( V_51 . V_53 ) {
F_22 ( & V_51 . V_55 ) ;
F_22 ( & V_51 . V_56 ) ;
F_23 ( & V_51 . V_57 , V_58 ) ;
F_24 ( & V_51 . V_59 ) ;
}
}
if ( V_51 . V_53 ) {
V_51 . V_52 ++ ;
return 0 ;
}
F_25 ( L_20 ) ;
return - 1 ;
}
static void F_26 ( void )
{
if ( V_51 . V_53 && -- V_51 . V_52 == 0 ) {
struct V_60 * V_61 , * V_62 ;
unsigned long V_63 ;
F_27 ( & V_51 . V_59 , V_63 ) ;
F_28 (e, temp, &wm_event.evtq, list) {
F_29 ( & V_61 -> V_64 ) ;
F_30 ( V_61 ) ;
}
F_28 (e, temp, &wm_event.freeq, list) {
F_29 ( & V_61 -> V_64 ) ;
F_30 ( V_61 ) ;
}
F_31 ( & V_51 . V_59 , V_63 ) ;
F_32 ( V_51 . V_53 ) ;
V_51 . V_53 = NULL ;
}
}
static inline struct V_60 * F_33 ( void )
{
return F_34 ( sizeof( struct V_60 ) , V_65 ) ;
}
static inline void F_30 ( struct V_60 * V_61 )
{
F_35 ( V_61 ) ;
}
static struct V_60 * F_36 ( void )
{
struct V_60 * V_61 ;
if ( F_37 ( & V_51 . V_56 ) )
V_61 = F_33 () ;
else {
V_61 = F_38 ( V_51 . V_56 . V_66 , struct V_60 , V_64 ) ;
F_29 ( & V_61 -> V_64 ) ;
}
return V_61 ;
}
static void F_39 ( struct V_60 * V_61 )
{
F_40 ( ! V_61 ) ;
F_41 ( & V_61 -> V_64 , & V_51 . V_56 ) ;
}
static void V_58 ( struct V_67 * V_68 )
{
int V_69 ;
unsigned long V_63 ;
struct V_60 * V_61 ;
F_27 ( & V_51 . V_59 , V_63 ) ;
while ( ! F_37 ( & V_51 . V_55 ) ) {
V_61 = F_38 ( V_51 . V_55 . V_66 , struct V_60 , V_64 ) ;
F_31 ( & V_51 . V_59 , V_63 ) ;
sscanf ( V_61 -> V_45 -> V_6 , L_21 , & V_69 ) ;
F_42 ( V_51 . V_53 , V_69 , 0 , V_61 -> V_70 , V_61 -> V_2 ) ;
F_27 ( & V_51 . V_59 , V_63 ) ;
F_29 ( & V_61 -> V_64 ) ;
F_39 ( V_61 ) ;
}
F_31 ( & V_51 . V_59 , V_63 ) ;
}
static int F_43 ( struct V_44 * V_45 , char * V_1 , int V_2 )
{
struct V_60 * V_61 ;
unsigned long V_63 ;
#if F_18 ( V_48 )
T_3 V_49 = ( ( T_1 ) V_1 [ 0 ] << 8 ) | ( T_1 ) V_1 [ 1 ] ;
T_3 V_50 = ( ( T_1 ) V_1 [ 2 ] << 8 ) | ( T_1 ) V_1 [ 3 ] ;
F_2 ( V_4 L_22 , V_49 , V_50 ) ;
#endif
F_27 ( & V_51 . V_59 , V_63 ) ;
V_61 = F_36 () ;
if ( ! V_61 ) {
F_44 ( V_45 , L_23 , V_71 ) ;
F_31 ( & V_51 . V_59 , V_63 ) ;
return - V_41 ;
}
V_61 -> V_45 = V_45 ;
V_61 -> V_2 = V_2 ;
memcpy ( V_61 -> V_70 , V_1 , V_2 ) ;
F_41 ( & V_61 -> V_64 , & V_51 . V_55 ) ;
F_31 ( & V_51 . V_59 , V_63 ) ;
F_45 ( & V_51 . V_57 ) ;
return 0 ;
}
static void F_46 ( void * V_72 )
{
struct V_47 * V_47 = V_72 ;
if ( F_47 ( V_47 -> V_73 ) )
F_48 ( V_47 -> V_73 ) ;
}
int F_49 ( struct V_35 * V_38 , struct V_44 * V_45 )
{
int V_39 = 0 ;
struct V_47 * V_47 = F_17 ( V_45 ) ;
V_39 = F_50 ( V_47 , V_38 -> V_16 , V_38 -> V_17 , F_46 ,
V_47 ) ;
if ( V_39 == - V_74 ) {
F_51 ( V_45 ) ;
V_39 = 0 ;
}
if ( V_39 ) {
F_52 ( V_38 , V_37 ) ;
return V_39 ;
}
V_47 -> V_75 . V_76 ++ ;
V_47 -> V_75 . V_77 += V_38 -> V_17 - V_37 ;
F_13 ( V_38 ) ;
return V_39 ;
}
static int F_53 ( struct V_35 * V_38 , struct V_44 * V_45 )
{
int V_39 = 0 ;
struct V_47 * V_47 = F_17 ( V_45 ) ;
struct V_78 * V_79 = (struct V_78 * ) V_47 -> V_80 [ V_81 ] . V_1 ;
#if F_18 ( V_82 )
F_6 ( L_24 , V_38 -> V_16 , V_38 -> V_17 ) ;
#endif
V_39 = F_8 ( & V_38 ) ;
if ( V_39 < 0 ) {
F_52 ( V_38 , V_37 ) ;
return V_39 ;
}
#if ! F_18 ( V_83 )
if ( ! V_79 )
F_44 ( V_45 , L_25 ) ;
else if ( V_79 -> V_84 != V_85 ) {
F_54 ( V_45 , L_26 ,
V_79 -> V_84 ) ;
F_13 ( V_38 ) ;
return 0 ;
}
#endif
#if F_18 ( V_86 )
V_39 = F_55 ( V_38 , V_45 ) ;
#else
V_39 = F_49 ( V_38 , V_45 ) ;
#endif
return V_39 ;
}
static int F_56 ( struct V_44 * V_45 , struct V_87 * V_88 )
{
if ( V_45 -> V_63 & V_89 )
return - V_90 ;
return 0 ;
}
static void F_57 ( struct V_44 * V_45 , char * V_91 )
{
T_3 V_92 [ 32 / sizeof( T_3 ) ] ;
T_1 * V_93 = ( T_1 * ) & V_92 [ 0 ] ;
struct V_47 * V_47 = F_17 ( V_45 ) ;
memcpy ( V_45 -> V_94 , V_91 , V_45 -> V_95 ) ;
V_92 [ 0 ] = F_15 ( V_96 ) ;
V_92 [ 1 ] = F_15 ( 8 ) ;
V_93 [ 4 ] = 0 ;
V_93 [ 5 ] = 6 ;
memcpy ( V_93 + 6 , V_91 , V_45 -> V_95 ) ;
F_19 ( V_47 , V_93 , V_37 + 8 ) ;
}
static int F_58 ( struct V_44 * V_45 , void * V_97 )
{
struct V_98 * V_99 = V_97 ;
if ( F_59 ( V_45 ) )
return - V_90 ;
if ( ! F_60 ( V_99 -> V_100 ) )
return - V_101 ;
F_57 ( V_45 , V_99 -> V_100 ) ;
return 0 ;
}
static struct V_102 * F_61 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
return & V_47 -> V_75 ;
}
static int F_62 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
struct V_78 * V_79 = (struct V_78 * ) V_47 -> V_80 [ V_81 ] . V_1 ;
F_63 ( V_45 ) ;
if ( V_79 && V_79 -> V_84 != V_103 )
F_64 ( V_45 , 1 ) ;
return 0 ;
}
static int F_65 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
struct V_78 * V_79 = (struct V_78 * ) V_47 -> V_80 [ V_81 ] . V_1 ;
F_51 ( V_45 ) ;
if ( V_79 && V_79 -> V_84 != V_103 )
F_64 ( V_45 , 0 ) ;
return 0 ;
}
static void F_66 ( void * * V_1 )
{
if ( V_1 && * V_1 ) {
F_35 ( * V_1 ) ;
* V_1 = NULL ;
}
}
static int F_67 ( struct V_104 * V_105 , struct V_104 * V_106 )
{
int V_2 ;
V_2 = V_105 -> V_2 < V_106 -> V_2 ? V_105 -> V_2 : V_106 -> V_2 ;
V_105 -> V_2 = V_2 ;
if ( V_106 -> V_2 ) {
if ( ! V_105 -> V_1 )
return - V_107 ;
if ( F_68 ( V_105 -> V_1 , V_106 -> V_1 , V_2 ) )
return - V_108 ;
}
return 0 ;
}
static int F_69 ( struct V_104 * V_105 , struct V_104 * V_106 )
{
if ( ! V_106 -> V_2 ) {
V_105 -> V_2 = 0 ;
return 0 ;
}
if ( ! V_106 -> V_1 )
return - V_107 ;
if ( ! ( V_105 -> V_1 && V_105 -> V_2 == V_106 -> V_2 ) ) {
F_66 ( & V_105 -> V_1 ) ;
V_105 -> V_1 = F_34 ( V_106 -> V_2 , V_109 ) ;
if ( V_105 -> V_1 == NULL )
return - V_41 ;
}
if ( F_70 ( V_105 -> V_1 , V_106 -> V_1 , V_106 -> V_2 ) ) {
F_66 ( & V_105 -> V_1 ) ;
return - V_108 ;
}
V_105 -> V_2 = V_106 -> V_2 ;
return 0 ;
}
static void F_71 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_110 ; V_3 ++ )
F_66 ( & V_47 -> V_80 [ V_3 ] . V_1 ) ;
}
static void F_72 ( struct V_44 * V_45 , struct V_78 * V_111 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
struct V_78 * V_112 =
(struct V_78 * ) V_47 -> V_80 [ V_81 ] . V_1 ;
if ( ! V_112 )
return;
if ( V_112 -> V_84 != V_111 -> V_84 ||
V_112 -> V_113 != V_111 -> V_113 ) {
if ( V_111 -> V_84 == V_85 )
F_73 ( V_45 ) ;
else if ( V_112 -> V_84 == V_85 ) {
F_74 ( V_45 ) ;
#if F_18 ( V_86 )
F_75 ( V_47 ) ;
#endif
}
F_76 ( V_45 , V_111 ) ;
}
}
static int F_77 ( struct V_44 * V_45 , struct V_114 * V_115 , int V_116 )
{
struct V_117 * V_118 = (struct V_117 * ) V_115 ;
struct V_47 * V_47 = F_17 ( V_45 ) ;
int V_39 ;
if ( V_116 != V_119 )
return - V_120 ;
switch ( V_118 -> V_116 ) {
case V_121 :
case V_122 :
if ( V_118 -> V_123 >= V_110 ) {
F_44 ( V_45 , L_27 ,
V_71 , V_118 -> V_123 ) ;
return - V_120 ;
}
if ( V_118 -> V_116 == V_121 ) {
V_39 = F_67 ( & V_118 -> V_16 ,
& V_47 -> V_80 [ V_118 -> V_123 ] ) ;
if ( V_39 < 0 )
return V_39 ;
} else if ( V_118 -> V_116 == V_122 ) {
if ( V_118 -> V_123 == V_81 ) {
F_72 ( V_45 ,
(struct V_78 * ) V_118 -> V_16 . V_1 ) ;
}
V_39 = F_69 (
& V_47 -> V_80 [ V_118 -> V_123 ] , & V_118 -> V_16 ) ;
if ( V_39 < 0 )
return V_39 ;
}
break;
default:
F_44 ( V_45 , L_28 , V_71 , V_116 ) ;
return - V_120 ;
}
return 0 ;
}
static void F_78 ( struct V_44 * V_45 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
struct V_124 * V_125 = (struct V_124 * ) V_1 ;
T_3 V_17 = 0 ;
T_2 V_126 = 0 ;
#define F_79 0
#define F_80 1
#define F_81 2
#define F_82 3
V_17 = 0 ;
V_125 -> V_127 = F_15 ( V_128 ) ;
V_125 -> V_16 [ V_17 ++ ] = F_83 ( V_129 ) ;
V_125 -> V_130 = F_15 ( V_17 ) ;
F_19 ( V_47 , V_125 , V_37 + V_17 ) ;
V_126 = ( 1 << F_80 ) | ( 1 << F_79 ) ;
#if F_18 ( V_86 )
V_126 |= ( 1 << F_81 ) ;
#endif
#if F_18 ( V_131 )
V_126 |= ( 1 << F_82 ) ;
#endif
V_17 = 0 ;
V_125 -> V_127 = F_15 ( V_96 ) ;
V_125 -> V_16 [ V_17 ++ ] = F_83 ( V_132 ) ;
V_125 -> V_16 [ V_17 ++ ] = F_84 ( V_132 ) ;
V_126 = F_85 ( V_126 ) ;
memcpy ( & V_125 -> V_16 [ V_17 ] , & V_126 , F_84 ( V_132 ) ) ;
V_17 += F_84 ( V_132 ) ;
V_125 -> V_130 = F_15 ( V_17 ) ;
F_19 ( V_47 , V_125 , V_37 + V_17 ) ;
F_86 ( V_45 , L_29 , F_87 ( V_126 ) ) ;
}
static int F_88 ( T_1 * V_1 , T_1 * V_133 , T_3 * V_134 , T_1 * * V_135 )
{
#define F_89 ( T_4 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_136 ;
* V_133 = V_1 [ 0 ] ;
if ( V_1 [ 1 ] == 0x82 ) {
* V_134 = F_90 ( F_89 ( & V_1 [ 2 ] ) ) ;
V_136 = 1 + 3 ;
} else {
* V_134 = V_1 [ 1 ] ;
V_136 = 1 + 1 ;
}
* V_135 = & V_1 [ V_136 ] ;
V_136 += * V_134 ;
return V_136 ;
}
static int F_91 ( struct V_44 * V_45 , char * V_1 ,
int V_17 )
{
T_1 V_133 , * V_135 ;
T_3 V_134 ;
T_3 V_127 , V_137 ;
int V_138 = V_37 ;
V_127 = F_90 ( * ( T_3 * ) & V_1 [ 0 ] ) ;
V_137 = F_90 ( * ( T_3 * ) & V_1 [ 2 ] ) ;
if ( V_17 < V_137 + V_37 ) {
F_44 ( V_45 , L_30 , V_71 ,
V_137 + V_37 , V_17 ) ;
return - 1 ;
}
if ( V_127 == V_139 ) {
if ( V_137 < 2 ) {
F_44 ( V_45 , L_31 ,
V_71 , V_127 , V_17 ) ;
return - 1 ;
}
V_138 += F_88 ( & V_1 [ V_138 ] , & V_133 , & V_134 , & V_135 ) ;
if ( V_133 == F_83 ( V_129 ) ) {
if ( V_134 != V_45 -> V_95 ) {
F_44 ( V_45 ,
L_32 ,
V_71 , V_133 , V_134 ) ;
return - 1 ;
}
F_86 ( V_45 , L_33 ,
V_45 -> V_94 , V_135 ) ;
memcpy ( V_45 -> V_94 , V_135 , V_45 -> V_95 ) ;
return 1 ;
}
}
F_43 ( V_45 , V_1 , V_17 ) ;
return 0 ;
}
static void F_92 ( struct V_44 * V_45 , char * V_1 , int V_17 )
{
struct V_47 * V_47 = F_17 ( V_45 ) ;
struct V_35 * V_38 ;
int V_39 ;
#if F_18 ( V_82 )
F_6 ( L_34 , V_1 , V_17 ) ;
#endif
V_38 = F_93 ( V_17 + 2 ) ;
if ( ! V_38 ) {
F_44 ( V_45 , L_35 , V_71 ) ;
return;
}
F_94 ( V_38 , 2 ) ;
V_47 -> V_75 . V_140 ++ ;
V_47 -> V_75 . V_141 += V_17 ;
memcpy ( F_95 ( V_38 , V_17 ) , V_1 , V_17 ) ;
V_38 -> V_45 = V_45 ;
V_38 -> V_5 = F_96 ( V_38 , V_45 ) ;
V_39 = F_97 () ? F_98 ( V_38 ) : F_99 ( V_38 ) ;
if ( V_39 == V_142 )
F_44 ( V_45 , L_36 , V_71 ) ;
}
static void F_100 ( struct V_44 * V_45 , char * V_1 ,
int V_17 )
{
#define F_101 4
#define F_102 4
struct V_124 * V_125 ;
int V_130 ;
while ( V_17 > 0 ) {
V_125 = (struct V_124 * ) V_1 ;
if ( F_90 ( V_125 -> V_127 ) != V_143 ) {
F_44 ( V_45 , L_37 ,
F_90 ( V_125 -> V_127 ) ) ;
break;
}
V_130 = F_90 ( V_125 -> V_130 ) ;
F_92 ( V_45 , V_125 -> V_16 , V_130 ) ;
if ( V_130 & 0x3 ) {
V_130 += F_101 - ( V_130 & 0x3 ) ;
}
V_130 += V_37 + F_102 ;
V_17 -= V_130 ;
V_1 += V_130 ;
}
}
static void F_103 ( struct V_44 * V_45 , char * V_1 , int V_17 )
{
#if F_18 ( V_86 )
struct V_47 * V_47 = F_17 ( V_45 ) ;
#endif
T_3 V_127 , V_137 ;
if ( V_17 == 0 )
return;
V_127 = F_90 ( * ( T_3 * ) & V_1 [ 0 ] ) ;
V_137 = F_90 ( * ( T_3 * ) & V_1 [ 2 ] ) ;
if ( V_17 < V_137 + V_37 ) {
if ( V_17 )
F_44 ( V_45 , L_30 ,
V_71 , V_137 + V_37 , V_17 ) ;
return;
}
switch ( V_127 ) {
case V_144 :
F_100 ( V_45 , & V_1 [ V_37 ] ,
V_137 ) ;
break;
case V_143 :
F_92 ( V_45 , & V_1 [ V_37 ] , V_137 ) ;
break;
#if F_18 ( V_86 )
case V_145 :
F_104 ( V_47 , V_1 , V_17 ) ;
break;
#endif
case V_146 :
if ( V_1 [ 4 ] == 0 ) {
if ( ! F_47 ( V_45 ) )
F_51 ( V_45 ) ;
} else if ( V_1 [ 4 ] == 1 ) {
if ( F_47 ( V_45 ) )
F_48 ( V_45 ) ;
}
break;
default:
F_43 ( V_45 , V_1 , V_17 ) ;
break;
}
}
static void F_76 ( struct V_44 * V_45 , struct V_78 * V_79 )
{
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
T_1 * V_92 = ( T_1 * ) & V_1 [ 0 ] ;
V_1 [ 0 ] = F_15 ( V_147 ) ;
V_1 [ 1 ] = F_15 ( sizeof( struct V_78 ) ) ;
memcpy ( & V_92 [ V_37 ] , V_79 , sizeof( struct V_78 ) ) ;
F_43 ( V_45 , V_92 ,
V_37 + sizeof( struct V_78 ) ) ;
}
static void F_64 ( struct V_44 * V_45 , int V_148 )
{
T_3 V_1 [ 32 / sizeof( T_3 ) ] ;
struct V_124 * V_125 = (struct V_124 * ) V_1 ;
unsigned char V_149 ;
V_149 = V_148 ? V_150 : V_151 ;
V_125 -> V_127 = F_15 ( V_152 ) ;
V_125 -> V_130 = F_15 ( sizeof( V_149 ) ) ;
V_125 -> V_16 [ 0 ] = V_149 ;
F_43 ( V_45 , ( char * ) V_125 , V_37 + sizeof( V_149 ) ) ;
}
static void F_105 ( void * V_72 , void * V_16 , int V_17 )
{
struct V_47 * V_47 = V_72 ;
F_103 ( V_47 -> V_73 , V_16 , V_17 ) ;
F_106 ( V_47 , F_105 , V_47 ) ;
}
static void F_107 ( void * V_72 , void * V_16 , int V_17 )
{
struct V_47 * V_47 = V_72 ;
int V_39 ;
V_39 = F_91 ( V_47 -> V_73 , V_16 , V_17 ) ;
if ( V_39 == 1 )
F_106 ( V_47 , F_105 , V_47 ) ;
else {
if ( V_39 < 0 )
F_44 ( V_47 -> V_73 ,
L_38 , V_39 ) ;
F_106 ( V_47 , F_107 , V_47 ) ;
#if 0
gdm_wimax_prepare_device(nic->netdev);
#endif
}
}
static void F_108 ( struct V_47 * V_47 )
{
F_106 ( V_47 , F_107 , V_47 ) ;
}
int F_109 ( struct V_153 * V_153 , struct V_154 * V_155 )
{
struct V_47 * V_47 = NULL ;
struct V_44 * V_45 ;
int V_39 ;
V_45 = (struct V_44 * ) F_110 ( sizeof( * V_47 ) ,
L_21 , V_156 ) ;
if ( V_45 == NULL ) {
F_25 ( L_39 ) ;
return - V_41 ;
}
F_111 ( V_45 , V_155 ) ;
V_45 -> V_157 = 1400 ;
V_45 -> V_158 = & V_159 ;
V_45 -> V_63 &= ~ V_160 ;
memcpy ( V_45 -> V_94 , V_161 , sizeof( V_161 ) ) ;
V_47 = F_17 ( V_45 ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_73 = V_45 ;
V_47 -> V_153 = V_153 ;
V_153 -> V_73 = V_45 ;
V_39 = F_20 () ;
if ( V_39 < 0 ) {
F_25 ( L_40 ) ;
goto V_162;
}
V_39 = F_112 ( V_45 ) ;
if ( V_39 )
goto V_162;
#if F_18 ( V_83 )
F_63 ( V_45 ) ;
F_73 ( V_45 ) ;
#else
F_74 ( V_45 ) ;
#endif
#ifdef V_86
F_113 ( V_47 ) ;
#endif
F_108 ( V_47 ) ;
F_78 ( V_45 ) ;
return 0 ;
V_162:
F_25 ( L_41 ) ;
F_114 ( V_45 ) ;
return V_39 ;
}
void F_115 ( struct V_153 * V_153 )
{
struct V_47 * V_47 = F_17 ( V_153 -> V_73 ) ;
struct V_78 * V_79 = (struct V_78 * ) V_47 -> V_80 [ V_81 ] . V_1 ;
if ( V_79 )
V_79 -> V_84 = V_103 ;
F_116 ( V_47 -> V_73 ) ;
F_26 () ;
#if F_18 ( V_86 )
F_75 ( V_47 ) ;
#endif
F_71 ( V_153 -> V_73 ) ;
F_114 ( V_47 -> V_73 ) ;
}
