static const char * F_1 ( T_1 V_1 )
{
static char V_2 [ 32 ] ;
const char * V_3 = L_1 ;
switch ( V_1 ) {
case V_4 :
V_3 = L_2 ;
break;
case V_5 :
V_3 = L_3 ;
break;
case V_6 :
V_3 = L_4 ;
break;
}
sprintf ( V_2 , L_5 , V_1 , V_3 ) ;
return V_2 ;
}
static const char * F_2 ( T_2 V_7 )
{
static char V_2 [ 32 ] ;
const char * V_3 = L_1 ;
switch ( V_7 ) {
case V_8 :
V_3 = L_6 ;
break;
case V_9 :
V_3 = L_7 ;
break;
case V_10 :
V_3 = L_8 ;
break;
}
sprintf ( V_2 , L_9 , V_7 , V_3 ) ;
return V_2 ;
}
static const char * F_3 ( T_1 V_11 )
{
static char V_2 [ 32 ] ;
const char * V_3 = L_1 ;
switch ( V_11 ) {
case 67 :
V_3 = L_10 ;
break;
case 68 :
V_3 = L_11 ;
break;
case 69 :
V_3 = L_12 ;
break;
}
sprintf ( V_2 , L_9 , V_11 , V_3 ) ;
return V_2 ;
}
static void F_4 ( struct V_12 * V_13 , const char * V_14 ,
T_2 * V_15 , int V_16 )
{
struct V_17 * V_18 = NULL ;
struct V_19 * V_20 = NULL ;
T_1 V_1 = 0 ;
T_2 V_7 = 0 ;
T_1 V_11 = 0 ;
V_1 = ( V_15 [ 12 ] << 8 ) | V_15 [ 13 ] ;
V_18 = (struct V_17 * ) ( V_15 + V_21 ) ;
if ( V_1 == V_5 ) {
V_20 = (struct V_19 * ) ( ( char * ) V_18 + sizeof( struct V_17 ) ) ;
V_7 = V_18 -> V_1 ;
V_11 = F_5 ( V_20 -> V_22 ) ;
} else if ( V_1 == V_6 ) {
struct V_23 * V_24 = (struct V_23 * ) V_15 ;
V_20 = (struct V_19 * ) ( ( char * ) V_24 + sizeof( struct V_23 ) ) ;
V_7 = V_24 -> V_25 ;
V_11 = F_5 ( V_20 -> V_22 ) ;
}
F_6 ( V_13 , L_13 , V_14 , V_16 ,
F_1 ( V_1 ) ,
F_2 ( V_7 ) ,
F_3 ( V_11 ) ) ;
if ( ! ( V_15 [ 0 ] == 0xff && V_15 [ 1 ] == 0xff ) ) {
if ( V_1 == V_5 )
F_6 ( V_13 , L_14 , & V_18 -> V_26 ) ;
else if ( V_1 == V_6 )
F_6 ( V_13 , L_15 , & V_18 -> V_26 ) ;
}
F_7 ( L_16 , V_27 , 16 , 1 , V_15 , V_16 , false ) ;
}
static inline int F_8 ( struct V_28 * * V_29 )
{
T_1 V_2 [ V_30 / sizeof( T_1 ) ] ;
struct V_28 * V_31 = * V_29 ;
if ( F_9 ( F_10 ( V_31 ) < V_30 ) ) {
struct V_28 * V_32 ;
V_32 = F_11 ( V_31 , V_30 ) ;
if ( V_32 == NULL )
return - V_33 ;
if ( V_31 -> V_34 )
F_12 ( V_32 , V_31 -> V_34 ) ;
F_13 ( V_31 ) ;
V_31 = V_32 ;
}
F_14 ( V_31 , V_30 ) ;
V_2 [ 0 ] = F_15 ( V_35 ) ;
V_2 [ 1 ] = F_15 ( V_31 -> V_16 - V_30 ) ;
memcpy ( V_31 -> V_15 , V_2 , V_30 ) ;
* V_29 = V_31 ;
return 0 ;
}
static void F_16 ( struct V_12 * V_13 , T_1 type , void * V_36 ,
int V_16 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
T_2 * V_2 = ( T_2 * ) V_36 ;
T_1 V_38 = ( V_2 [ 0 ] << 8 ) | V_2 [ 1 ] ;
T_1 V_39 = ( V_2 [ 2 ] << 8 ) | V_2 [ 3 ] ;
F_6 ( V_13 , L_17 , V_38 , V_39 ) ;
F_18 ( V_37 , V_36 , V_16 ) ;
}
static int F_19 ( void )
{
if ( ! V_40 . V_41 ) {
V_40 . V_42 = F_20 ( V_43 ,
F_16 ) ;
if ( V_40 . V_42 ) {
F_21 ( & V_40 . V_44 ) ;
F_21 ( & V_40 . V_45 ) ;
F_22 ( & V_40 . V_46 , V_47 ) ;
F_23 ( & V_40 . V_48 ) ;
}
}
if ( V_40 . V_42 ) {
V_40 . V_41 ++ ;
return 0 ;
}
F_24 ( L_18 ) ;
return - 1 ;
}
static void F_25 ( void )
{
if ( V_40 . V_42 && -- V_40 . V_41 == 0 ) {
struct V_49 * V_50 , * V_51 ;
unsigned long V_52 ;
F_26 ( & V_40 . V_48 , V_52 ) ;
F_27 (e, temp, &wm_event.evtq, list) {
F_28 ( & V_50 -> V_53 ) ;
F_29 ( V_50 ) ;
}
F_27 (e, temp, &wm_event.freeq, list) {
F_28 ( & V_50 -> V_53 ) ;
F_29 ( V_50 ) ;
}
F_30 ( & V_40 . V_48 , V_52 ) ;
F_31 ( V_40 . V_42 ) ;
V_40 . V_42 = NULL ;
}
}
static inline struct V_49 * F_32 ( void )
{
return F_33 ( sizeof( struct V_49 ) , V_54 ) ;
}
static inline void F_29 ( struct V_49 * V_50 )
{
F_34 ( V_50 ) ;
}
static struct V_49 * F_35 ( void )
{
struct V_49 * V_50 ;
if ( F_36 ( & V_40 . V_45 ) ) {
V_50 = F_32 () ;
} else {
V_50 = F_37 ( V_40 . V_45 . V_55 , struct V_49 , V_53 ) ;
F_28 ( & V_50 -> V_53 ) ;
}
return V_50 ;
}
static void F_38 ( struct V_49 * V_50 )
{
F_39 ( ! V_50 ) ;
F_40 ( & V_50 -> V_53 , & V_40 . V_45 ) ;
}
static void V_47 ( struct V_56 * V_57 )
{
int V_58 ;
unsigned long V_52 ;
struct V_49 * V_50 ;
F_26 ( & V_40 . V_48 , V_52 ) ;
while ( ! F_36 ( & V_40 . V_44 ) ) {
V_50 = F_37 ( V_40 . V_44 . V_55 , struct V_49 , V_53 ) ;
F_30 ( & V_40 . V_48 , V_52 ) ;
sscanf ( V_50 -> V_13 -> V_3 , L_19 , & V_58 ) ;
F_41 ( V_40 . V_42 , V_58 , 0 , V_50 -> V_59 , V_50 -> V_60 ) ;
F_26 ( & V_40 . V_48 , V_52 ) ;
F_28 ( & V_50 -> V_53 ) ;
F_38 ( V_50 ) ;
}
F_30 ( & V_40 . V_48 , V_52 ) ;
}
static int F_42 ( struct V_12 * V_13 , char * V_2 , int V_60 )
{
struct V_49 * V_50 ;
unsigned long V_52 ;
T_1 V_38 = ( ( T_2 ) V_2 [ 0 ] << 8 ) | ( T_2 ) V_2 [ 1 ] ;
T_1 V_39 = ( ( T_2 ) V_2 [ 2 ] << 8 ) | ( T_2 ) V_2 [ 3 ] ;
F_6 ( V_13 , L_20 , V_38 , V_39 ) ;
F_26 ( & V_40 . V_48 , V_52 ) ;
V_50 = F_35 () ;
if ( ! V_50 ) {
F_43 ( V_13 , L_21 , V_61 ) ;
F_30 ( & V_40 . V_48 , V_52 ) ;
return - V_33 ;
}
V_50 -> V_13 = V_13 ;
V_50 -> V_60 = V_60 ;
memcpy ( V_50 -> V_59 , V_2 , V_60 ) ;
F_40 ( & V_50 -> V_53 , & V_40 . V_44 ) ;
F_30 ( & V_40 . V_48 , V_52 ) ;
F_44 ( & V_40 . V_46 ) ;
return 0 ;
}
static void F_45 ( void * V_62 )
{
struct V_37 * V_37 = V_62 ;
if ( F_46 ( V_37 -> V_63 ) )
F_47 ( V_37 -> V_63 ) ;
}
int F_48 ( struct V_28 * V_31 , struct V_12 * V_13 )
{
int V_64 = 0 ;
struct V_37 * V_37 = F_17 ( V_13 ) ;
V_64 = F_49 ( V_37 , V_31 -> V_15 , V_31 -> V_16 , F_45 ,
V_37 ) ;
if ( V_64 == - V_65 ) {
F_50 ( V_13 ) ;
V_64 = 0 ;
}
if ( V_64 ) {
F_51 ( V_31 , V_30 ) ;
return V_64 ;
}
V_37 -> V_66 . V_67 ++ ;
V_37 -> V_66 . V_68 += V_31 -> V_16 - V_30 ;
F_13 ( V_31 ) ;
return V_64 ;
}
static int F_52 ( struct V_28 * V_31 , struct V_12 * V_13 )
{
int V_64 = 0 ;
struct V_37 * V_37 = F_17 ( V_13 ) ;
struct V_69 * V_70 = (struct V_69 * ) V_37 -> V_71 [ V_72 ] . V_2 ;
F_4 ( V_13 , L_22 , V_31 -> V_15 , V_31 -> V_16 ) ;
V_64 = F_8 ( & V_31 ) ;
if ( V_64 < 0 ) {
F_51 ( V_31 , V_30 ) ;
return V_64 ;
}
#if ! F_53 ( V_73 )
if ( ! V_70 ) {
F_43 ( V_13 , L_23 ) ;
} else if ( V_70 -> V_74 != V_75 ) {
F_54 ( V_13 , L_24 ,
V_70 -> V_74 ) ;
F_13 ( V_31 ) ;
return 0 ;
}
#endif
#if F_53 ( V_76 )
V_64 = F_55 ( V_31 , V_13 ) ;
#else
V_64 = F_48 ( V_31 , V_13 ) ;
#endif
return V_64 ;
}
static int F_56 ( struct V_12 * V_13 , struct V_77 * V_78 )
{
if ( V_13 -> V_52 & V_79 )
return - V_80 ;
return 0 ;
}
static void F_57 ( struct V_12 * V_13 , char * V_81 )
{
T_1 V_82 [ 32 / sizeof( T_1 ) ] ;
T_2 * V_83 = ( T_2 * ) & V_82 [ 0 ] ;
struct V_37 * V_37 = F_17 ( V_13 ) ;
memcpy ( V_13 -> V_84 , V_81 , V_13 -> V_85 ) ;
V_82 [ 0 ] = F_15 ( V_86 ) ;
V_82 [ 1 ] = F_15 ( 8 ) ;
V_83 [ 4 ] = 0 ;
V_83 [ 5 ] = 6 ;
memcpy ( V_83 + 6 , V_81 , V_13 -> V_85 ) ;
F_18 ( V_37 , V_83 , V_30 + 8 ) ;
}
static int F_58 ( struct V_12 * V_13 , void * V_87 )
{
struct V_88 * V_89 = V_87 ;
if ( F_59 ( V_13 ) )
return - V_80 ;
if ( ! F_60 ( V_89 -> V_90 ) )
return - V_91 ;
F_57 ( V_13 , V_89 -> V_90 ) ;
return 0 ;
}
static struct V_92 * F_61 ( struct V_12 * V_13 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
return & V_37 -> V_66 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
struct V_69 * V_70 = (struct V_69 * ) V_37 -> V_71 [ V_72 ] . V_2 ;
F_63 ( V_13 ) ;
if ( V_70 && V_70 -> V_74 != V_93 )
F_64 ( V_13 , 1 ) ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
struct V_69 * V_70 = (struct V_69 * ) V_37 -> V_71 [ V_72 ] . V_2 ;
F_50 ( V_13 ) ;
if ( V_70 && V_70 -> V_74 != V_93 )
F_64 ( V_13 , 0 ) ;
return 0 ;
}
static void F_66 ( void * * V_2 )
{
if ( V_2 && * V_2 ) {
F_34 ( * V_2 ) ;
* V_2 = NULL ;
}
}
static int F_67 ( struct V_94 * V_95 , struct V_94 * V_96 )
{
int V_60 ;
V_60 = V_95 -> V_60 < V_96 -> V_60 ? V_95 -> V_60 : V_96 -> V_60 ;
V_95 -> V_60 = V_60 ;
if ( V_96 -> V_60 ) {
if ( ! V_95 -> V_2 )
return - V_97 ;
if ( F_68 ( ( void V_98 * ) V_95 -> V_2 , V_96 -> V_2 , V_60 ) )
return - V_99 ;
}
return 0 ;
}
static int F_69 ( struct V_94 * V_95 , struct V_94 * V_96 )
{
if ( ! V_96 -> V_60 ) {
V_95 -> V_60 = 0 ;
return 0 ;
}
if ( ! V_96 -> V_2 )
return - V_97 ;
if ( ! ( V_95 -> V_2 && V_95 -> V_60 == V_96 -> V_60 ) ) {
F_66 ( & V_95 -> V_2 ) ;
V_95 -> V_2 = F_33 ( V_96 -> V_60 , V_100 ) ;
if ( V_95 -> V_2 == NULL )
return - V_33 ;
}
if ( F_70 ( V_95 -> V_2 , ( void V_98 * ) V_96 -> V_2 , V_96 -> V_60 ) ) {
F_66 ( & V_95 -> V_2 ) ;
return - V_99 ;
}
V_95 -> V_60 = V_96 -> V_60 ;
return 0 ;
}
static void F_71 ( struct V_12 * V_13 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ )
F_66 ( & V_37 -> V_71 [ V_101 ] . V_2 ) ;
}
static void F_72 ( struct V_12 * V_13 , struct V_69 * V_103 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
struct V_69 * V_104 = (struct V_69 * )
V_37 -> V_71 [ V_72 ] . V_2 ;
if ( ! V_104 )
return;
if ( V_104 -> V_74 != V_103 -> V_74 ||
V_104 -> V_105 != V_103 -> V_105 ) {
if ( V_103 -> V_74 == V_75 ) {
F_73 ( V_13 ) ;
} else if ( V_104 -> V_74 == V_75 ) {
F_74 ( V_13 ) ;
#if F_53 ( V_76 )
F_75 ( V_37 ) ;
#endif
}
F_76 ( V_13 , V_103 ) ;
}
}
static int F_77 ( struct V_12 * V_13 , struct V_106 * V_107 , int V_108 )
{
struct V_109 * V_110 = (struct V_109 * ) V_107 ;
struct V_37 * V_37 = F_17 ( V_13 ) ;
int V_64 ;
if ( V_108 != V_111 )
return - V_112 ;
switch ( V_110 -> V_108 ) {
case V_113 :
case V_114 :
if ( V_110 -> V_115 >= V_102 ) {
F_43 ( V_13 , L_25 ,
V_61 , V_110 -> V_115 ) ;
return - V_112 ;
}
if ( V_110 -> V_108 == V_113 ) {
V_64 = F_67 (
& V_110 -> V_15 , & V_37 -> V_71 [ V_110 -> V_115 ] ) ;
if ( V_64 < 0 )
return V_64 ;
} else if ( V_110 -> V_108 == V_114 ) {
if ( V_110 -> V_115 == V_72 ) {
F_72 ( V_13 ,
(struct V_69 * ) V_110 -> V_15 . V_2 ) ;
}
V_64 = F_69 (
& V_37 -> V_71 [ V_110 -> V_115 ] , & V_110 -> V_15 ) ;
if ( V_64 < 0 )
return V_64 ;
}
break;
default:
F_43 ( V_13 , L_26 , V_61 , V_108 ) ;
return - V_112 ;
}
return 0 ;
}
static void F_78 ( struct V_12 * V_13 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
T_1 V_2 [ 32 / sizeof( T_1 ) ] ;
struct V_116 * V_117 = (struct V_116 * ) V_2 ;
T_1 V_16 = 0 ;
T_3 V_118 = 0 ;
#define F_79 0
#define F_80 1
#define F_81 2
#define F_82 3
V_16 = 0 ;
V_117 -> V_119 = F_15 ( V_120 ) ;
V_117 -> V_15 [ V_16 ++ ] = F_83 ( V_121 ) ;
V_117 -> V_122 = F_15 ( V_16 ) ;
F_18 ( V_37 , V_117 , V_30 + V_16 ) ;
V_118 = ( 1 << F_80 ) | ( 1 << F_79 ) ;
#if F_53 ( V_76 )
V_118 |= ( 1 << F_81 ) ;
#endif
#if F_53 ( V_123 )
V_118 |= ( 1 << F_82 ) ;
#endif
V_16 = 0 ;
V_117 -> V_119 = F_15 ( V_86 ) ;
V_117 -> V_15 [ V_16 ++ ] = F_83 ( V_124 ) ;
V_117 -> V_15 [ V_16 ++ ] = F_84 ( V_124 ) ;
V_118 = F_85 ( V_118 ) ;
memcpy ( & V_117 -> V_15 [ V_16 ] , & V_118 , F_84 ( V_124 ) ) ;
V_16 += F_84 ( V_124 ) ;
V_117 -> V_122 = F_15 ( V_16 ) ;
F_18 ( V_37 , V_117 , V_30 + V_16 ) ;
F_86 ( V_13 , L_27 , F_87 ( V_118 ) ) ;
}
static int F_88 ( T_2 * V_2 , T_2 * V_125 , T_1 * V_126 , T_2 * * V_127 )
{
#define F_89 ( T_4 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_128 ;
* V_125 = V_2 [ 0 ] ;
if ( V_2 [ 1 ] == 0x82 ) {
* V_126 = F_90 ( F_89 ( & V_2 [ 2 ] ) ) ;
V_128 = 1 + 3 ;
} else {
* V_126 = V_2 [ 1 ] ;
V_128 = 1 + 1 ;
}
* V_127 = & V_2 [ V_128 ] ;
V_128 += * V_126 ;
return V_128 ;
}
static int F_91 ( struct V_12 * V_13 , char * V_2 ,
int V_16 )
{
T_2 V_125 , * V_127 ;
T_1 V_126 ;
T_1 V_119 , V_129 ;
int V_130 = V_30 ;
V_119 = F_90 ( * ( T_1 * ) & V_2 [ 0 ] ) ;
V_129 = F_90 ( * ( T_1 * ) & V_2 [ 2 ] ) ;
if ( V_16 < V_129 + V_30 ) {
F_43 ( V_13 , L_28 , V_61 ,
V_129 + V_30 , V_16 ) ;
return - 1 ;
}
if ( V_119 == V_131 ) {
if ( V_129 < 2 ) {
F_43 ( V_13 , L_29 ,
V_61 , V_119 , V_16 ) ;
return - 1 ;
}
V_130 += F_88 ( & V_2 [ V_130 ] , & V_125 , & V_126 , & V_127 ) ;
if ( V_125 == F_83 ( V_121 ) ) {
if ( V_126 != V_13 -> V_85 ) {
F_43 ( V_13 ,
L_30 ,
V_61 , V_125 , V_126 ) ;
return - 1 ;
}
F_86 ( V_13 , L_31 ,
V_13 -> V_84 , V_127 ) ;
memcpy ( V_13 -> V_84 , V_127 , V_13 -> V_85 ) ;
return 1 ;
}
}
F_42 ( V_13 , V_2 , V_16 ) ;
return 0 ;
}
static void F_92 ( struct V_12 * V_13 , char * V_2 , int V_16 )
{
struct V_37 * V_37 = F_17 ( V_13 ) ;
struct V_28 * V_31 ;
int V_64 ;
F_4 ( V_13 , L_32 , V_2 , V_16 ) ;
V_31 = F_93 ( V_16 + 2 ) ;
if ( ! V_31 ) {
F_43 ( V_13 , L_33 , V_61 ) ;
return;
}
F_94 ( V_31 , 2 ) ;
V_37 -> V_66 . V_132 ++ ;
V_37 -> V_66 . V_133 += V_16 ;
memcpy ( F_95 ( V_31 , V_16 ) , V_2 , V_16 ) ;
V_31 -> V_13 = V_13 ;
V_31 -> V_1 = F_96 ( V_31 , V_13 ) ;
V_64 = F_97 () ? F_98 ( V_31 ) : F_99 ( V_31 ) ;
if ( V_64 == V_134 )
F_43 ( V_13 , L_34 , V_61 ) ;
}
static void F_100 ( struct V_12 * V_13 , char * V_2 ,
int V_16 )
{
#define F_101 4
#define F_102 4
struct V_116 * V_117 ;
int V_122 ;
while ( V_16 > 0 ) {
V_117 = (struct V_116 * ) V_2 ;
if ( F_90 ( V_117 -> V_119 ) != V_135 ) {
F_43 ( V_13 , L_35 ,
F_90 ( V_117 -> V_119 ) ) ;
break;
}
V_122 = F_90 ( V_117 -> V_122 ) ;
F_92 ( V_13 , V_117 -> V_15 , V_122 ) ;
if ( V_122 & 0x3 ) {
V_122 += F_101 - ( V_122 & 0x3 ) ;
}
V_122 += V_30 + F_102 ;
V_16 -= V_122 ;
V_2 += V_122 ;
}
}
static void F_103 ( struct V_12 * V_13 , char * V_2 , int V_16 )
{
#if F_53 ( V_76 )
struct V_37 * V_37 = F_17 ( V_13 ) ;
#endif
T_1 V_119 , V_129 ;
if ( V_16 == 0 )
return;
V_119 = F_90 ( * ( T_1 * ) & V_2 [ 0 ] ) ;
V_129 = F_90 ( * ( T_1 * ) & V_2 [ 2 ] ) ;
if ( V_16 < V_129 + V_30 ) {
if ( V_16 )
F_43 ( V_13 , L_28 ,
V_61 , V_129 + V_30 , V_16 ) ;
return;
}
switch ( V_119 ) {
case V_136 :
F_100 ( V_13 , & V_2 [ V_30 ] ,
V_129 ) ;
break;
case V_135 :
F_92 ( V_13 , & V_2 [ V_30 ] , V_129 ) ;
break;
#if F_53 ( V_76 )
case V_137 :
F_104 ( V_37 , V_2 , V_16 ) ;
break;
#endif
case V_138 :
if ( V_2 [ 4 ] == 0 ) {
if ( ! F_46 ( V_13 ) )
F_50 ( V_13 ) ;
} else if ( V_2 [ 4 ] == 1 ) {
if ( F_46 ( V_13 ) )
F_47 ( V_13 ) ;
}
break;
default:
F_42 ( V_13 , V_2 , V_16 ) ;
break;
}
}
static void F_76 ( struct V_12 * V_13 , struct V_69 * V_70 )
{
T_1 V_2 [ 32 / sizeof( T_1 ) ] ;
T_2 * V_82 = ( T_2 * ) & V_2 [ 0 ] ;
V_2 [ 0 ] = F_15 ( V_139 ) ;
V_2 [ 1 ] = F_15 ( sizeof( struct V_69 ) ) ;
memcpy ( & V_82 [ V_30 ] , V_70 , sizeof( struct V_69 ) ) ;
F_42 ( V_13 , V_82 ,
V_30 + sizeof( struct V_69 ) ) ;
}
static void F_64 ( struct V_12 * V_13 , int V_140 )
{
T_1 V_2 [ 32 / sizeof( T_1 ) ] ;
struct V_116 * V_117 = (struct V_116 * ) V_2 ;
unsigned char V_141 ;
V_141 = V_140 ? V_142 : V_143 ;
V_117 -> V_119 = F_15 ( V_144 ) ;
V_117 -> V_122 = F_15 ( sizeof( V_141 ) ) ;
V_117 -> V_15 [ 0 ] = V_141 ;
F_42 ( V_13 , ( char * ) V_117 , V_30 + sizeof( V_141 ) ) ;
}
static void F_105 ( void * V_62 , void * V_15 , int V_16 )
{
struct V_37 * V_37 = V_62 ;
F_103 ( V_37 -> V_63 , V_15 , V_16 ) ;
F_106 ( V_37 , F_105 , V_37 ) ;
}
static void F_107 ( void * V_62 , void * V_15 , int V_16 )
{
struct V_37 * V_37 = V_62 ;
int V_64 ;
V_64 = F_91 ( V_37 -> V_63 , V_15 , V_16 ) ;
if ( V_64 == 1 ) {
F_106 ( V_37 , F_105 , V_37 ) ;
} else {
if ( V_64 < 0 )
F_43 ( V_37 -> V_63 ,
L_36 , V_64 ) ;
F_106 ( V_37 , F_107 , V_37 ) ;
}
}
static void F_108 ( struct V_37 * V_37 )
{
F_106 ( V_37 , F_107 , V_37 ) ;
}
int F_109 ( struct V_145 * V_145 , struct V_146 * V_147 )
{
struct V_37 * V_37 = NULL ;
struct V_12 * V_13 ;
int V_64 ;
V_13 = F_110 ( sizeof( * V_37 ) , L_19 , V_148 ) ;
if ( V_13 == NULL ) {
F_24 ( L_37 ) ;
return - V_33 ;
}
F_111 ( V_13 , V_147 ) ;
V_13 -> V_149 = 1400 ;
V_13 -> V_150 = & V_151 ;
V_13 -> V_52 &= ~ V_152 ;
memcpy ( V_13 -> V_84 , V_153 , sizeof( V_153 ) ) ;
V_37 = F_17 ( V_13 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_63 = V_13 ;
V_37 -> V_145 = V_145 ;
V_145 -> V_63 = V_13 ;
V_64 = F_19 () ;
if ( V_64 < 0 ) {
F_24 ( L_38 ) ;
goto V_154;
}
V_64 = F_112 ( V_13 ) ;
if ( V_64 )
goto V_154;
#if F_53 ( V_73 )
F_63 ( V_13 ) ;
F_73 ( V_13 ) ;
#else
F_74 ( V_13 ) ;
#endif
#ifdef V_76
F_113 ( V_37 ) ;
#endif
F_108 ( V_37 ) ;
F_78 ( V_13 ) ;
return 0 ;
V_154:
F_24 ( L_39 ) ;
F_114 ( V_13 ) ;
return V_64 ;
}
void F_115 ( struct V_145 * V_145 )
{
struct V_37 * V_37 = F_17 ( V_145 -> V_63 ) ;
struct V_69 * V_70 = (struct V_69 * ) V_37 -> V_71 [ V_72 ] . V_2 ;
if ( V_70 )
V_70 -> V_74 = V_93 ;
F_116 ( V_37 -> V_63 ) ;
F_25 () ;
#if F_53 ( V_76 )
F_75 ( V_37 ) ;
#endif
F_71 ( V_145 -> V_63 ) ;
F_114 ( V_37 -> V_63 ) ;
}
