static inline int F_1 ( struct V_1 * * V_2 )
{
T_1 V_3 [ V_4 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
struct V_1 * V_7 = * V_2 ;
if ( F_2 ( F_3 ( V_7 ) < V_4 ) ) {
struct V_1 * V_8 ;
V_8 = F_4 ( V_7 , V_4 ) ;
if ( V_8 == NULL )
return - V_9 ;
if ( V_7 -> V_10 )
F_5 ( V_8 , V_7 -> V_10 ) ;
F_6 ( V_7 ) ;
V_7 = V_8 ;
}
F_7 ( V_7 , V_4 ) ;
V_6 -> V_11 = F_8 ( V_12 ) ;
V_6 -> V_13 = F_8 ( V_7 -> V_14 - V_4 ) ;
memcpy ( V_7 -> V_15 , V_3 , V_4 ) ;
* V_2 = V_7 ;
return 0 ;
}
static inline struct V_16 * F_9 ( void )
{
return F_10 ( sizeof( struct V_16 ) , V_17 ) ;
}
static inline void F_11 ( struct V_16 * V_18 )
{
F_12 ( V_18 ) ;
}
static struct V_16 * F_13 ( void )
{
struct V_16 * V_18 ;
if ( F_14 ( & V_19 . V_20 ) ) {
V_18 = F_9 () ;
} else {
V_18 = F_15 ( V_19 . V_20 . V_21 , struct V_16 , V_22 ) ;
F_16 ( & V_18 -> V_22 ) ;
}
return V_18 ;
}
static void F_17 ( struct V_16 * V_18 )
{
F_18 ( ! V_18 ) ;
F_19 ( & V_18 -> V_22 , & V_19 . V_20 ) ;
}
static void F_20 ( struct V_23 * V_24 , T_1 type , void * V_25 ,
int V_14 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
T_2 * V_3 = V_25 ;
T_1 V_27 = ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ;
T_1 V_28 = ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ;
F_22 ( V_24 , L_1 , V_27 , V_28 ) ;
F_23 ( V_26 , V_25 , V_14 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
int V_31 ;
unsigned long V_32 ;
struct V_16 * V_18 ;
struct V_16 * V_33 ;
F_25 ( & V_19 . V_34 , V_32 ) ;
F_26 (e, tmp, &wm_event.evtq, list) {
F_27 ( & V_19 . V_34 , V_32 ) ;
if ( sscanf ( V_18 -> V_24 -> V_35 , L_2 , & V_31 ) == 1 )
F_28 ( V_19 . V_36 , V_31 , 0 , V_18 -> V_37 ,
V_18 -> V_38 ) ;
F_25 ( & V_19 . V_34 , V_32 ) ;
F_16 ( & V_18 -> V_22 ) ;
F_17 ( V_18 ) ;
}
F_27 ( & V_19 . V_34 , V_32 ) ;
}
static int F_29 ( void )
{
if ( ! V_19 . V_39 ) {
V_19 . V_36 = F_30 ( V_40 ,
F_20 ) ;
if ( V_19 . V_36 ) {
F_31 ( & V_19 . V_41 ) ;
F_31 ( & V_19 . V_20 ) ;
F_32 ( & V_19 . V_42 , F_24 ) ;
F_33 ( & V_19 . V_34 ) ;
}
}
if ( V_19 . V_36 ) {
V_19 . V_39 ++ ;
return 0 ;
}
F_34 ( L_3 ) ;
return - 1 ;
}
static void F_35 ( void )
{
if ( V_19 . V_36 && -- V_19 . V_39 == 0 ) {
struct V_16 * V_18 , * V_43 ;
unsigned long V_32 ;
F_25 ( & V_19 . V_34 , V_32 ) ;
F_26 (e, temp, &wm_event.evtq, list) {
F_16 ( & V_18 -> V_22 ) ;
F_11 ( V_18 ) ;
}
F_26 (e, temp, &wm_event.freeq, list) {
F_16 ( & V_18 -> V_22 ) ;
F_11 ( V_18 ) ;
}
F_27 ( & V_19 . V_34 , V_32 ) ;
F_36 ( V_19 . V_36 ) ;
V_19 . V_36 = NULL ;
}
}
static int F_37 ( struct V_23 * V_24 , char * V_3 , int V_38 )
{
struct V_16 * V_18 ;
unsigned long V_32 ;
T_1 V_27 = ( ( T_2 ) V_3 [ 0 ] << 8 ) | ( T_2 ) V_3 [ 1 ] ;
T_1 V_28 = ( ( T_2 ) V_3 [ 2 ] << 8 ) | ( T_2 ) V_3 [ 3 ] ;
F_22 ( V_24 , L_4 , V_27 , V_28 ) ;
F_25 ( & V_19 . V_34 , V_32 ) ;
V_18 = F_13 () ;
if ( ! V_18 ) {
F_38 ( V_24 , L_5 , V_44 ) ;
F_27 ( & V_19 . V_34 , V_32 ) ;
return - V_9 ;
}
V_18 -> V_24 = V_24 ;
V_18 -> V_38 = V_38 ;
memcpy ( V_18 -> V_37 , V_3 , V_38 ) ;
F_19 ( & V_18 -> V_22 , & V_19 . V_41 ) ;
F_27 ( & V_19 . V_34 , V_32 ) ;
F_39 ( & V_19 . V_42 ) ;
return 0 ;
}
static void F_40 ( void * V_45 )
{
struct V_26 * V_26 = V_45 ;
if ( F_41 ( V_26 -> V_46 ) )
F_42 ( V_26 -> V_46 ) ;
}
int F_43 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_47 = 0 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
V_47 = F_44 ( V_26 , V_7 -> V_15 , V_7 -> V_14 , F_40 ,
V_26 ) ;
if ( V_47 == - V_48 ) {
F_45 ( V_24 ) ;
V_47 = 0 ;
}
if ( V_47 ) {
F_46 ( V_7 , V_4 ) ;
return V_47 ;
}
V_24 -> V_49 . V_50 ++ ;
V_24 -> V_49 . V_51 += V_7 -> V_14 - V_4 ;
F_6 ( V_7 ) ;
return V_47 ;
}
static int F_47 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_47 = 0 ;
V_47 = F_1 ( & V_7 ) ;
if ( V_47 < 0 ) {
F_46 ( V_7 , V_4 ) ;
return V_47 ;
}
#if F_48 ( V_52 )
V_47 = F_49 ( V_7 , V_24 ) ;
#else
V_47 = F_43 ( V_7 , V_24 ) ;
#endif
return V_47 ;
}
static int F_50 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
if ( V_24 -> V_32 & V_55 )
return - V_56 ;
return 0 ;
}
static void F_51 ( struct V_23 * V_24 , char * V_57 )
{
T_1 V_58 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_58 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
memcpy ( V_24 -> V_59 , V_57 , V_24 -> V_60 ) ;
V_6 -> V_11 = F_8 ( V_61 ) ;
V_6 -> V_13 = F_8 ( 8 ) ;
V_6 -> V_15 [ 0 ] = 0 ;
V_6 -> V_15 [ 1 ] = 6 ;
memcpy ( & V_6 -> V_15 [ 2 ] , V_57 , V_24 -> V_60 ) ;
F_23 ( V_26 , V_6 , V_4 + 8 ) ;
}
static int F_52 ( struct V_23 * V_24 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
if ( F_53 ( V_24 ) )
return - V_56 ;
if ( ! F_54 ( V_64 -> V_65 ) )
return - V_66 ;
F_51 ( V_24 , V_64 -> V_65 ) ;
return 0 ;
}
static void F_55 ( struct V_23 * V_24 , int V_67 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
unsigned char V_68 ;
V_68 = V_67 ? V_69 : V_70 ;
V_6 -> V_11 = F_8 ( V_71 ) ;
V_6 -> V_13 = F_8 ( sizeof( V_68 ) ) ;
V_6 -> V_15 [ 0 ] = V_68 ;
F_37 ( V_24 , ( char * ) V_6 , V_4 + sizeof( V_68 ) ) ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_72 * V_73 = (struct V_72 * ) V_26 -> V_74 [ V_75 ] . V_3 ;
F_57 ( V_24 ) ;
if ( V_73 && V_73 -> V_76 != V_77 )
F_55 ( V_24 , 1 ) ;
return 0 ;
}
static int F_58 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_72 * V_73 = (struct V_72 * ) V_26 -> V_74 [ V_75 ] . V_3 ;
F_45 ( V_24 ) ;
if ( V_73 && V_73 -> V_76 != V_77 )
F_55 ( V_24 , 0 ) ;
return 0 ;
}
static void F_59 ( void * * V_3 )
{
if ( V_3 && * V_3 ) {
F_12 ( * V_3 ) ;
* V_3 = NULL ;
}
}
static int F_60 ( struct V_78 * V_79 , struct V_78 * V_80 )
{
int V_38 ;
V_38 = V_79 -> V_38 < V_80 -> V_38 ? V_79 -> V_38 : V_80 -> V_38 ;
V_79 -> V_38 = V_38 ;
if ( V_80 -> V_38 ) {
if ( ! V_79 -> V_3 )
return - V_81 ;
if ( F_61 ( ( void V_82 * ) V_79 -> V_3 , V_80 -> V_3 , V_38 ) )
return - V_83 ;
}
return 0 ;
}
static int F_62 ( struct V_78 * V_79 , struct V_78 * V_80 )
{
if ( ! V_80 -> V_38 ) {
V_79 -> V_38 = 0 ;
return 0 ;
}
if ( ! V_80 -> V_3 )
return - V_81 ;
if ( ! ( V_79 -> V_3 && V_79 -> V_38 == V_80 -> V_38 ) ) {
F_59 ( & V_79 -> V_3 ) ;
V_79 -> V_3 = F_10 ( V_80 -> V_38 , V_84 ) ;
if ( V_79 -> V_3 == NULL )
return - V_9 ;
}
if ( F_63 ( V_79 -> V_3 , ( void V_82 * ) V_80 -> V_3 , V_80 -> V_38 ) ) {
F_59 ( & V_79 -> V_3 ) ;
return - V_83 ;
}
V_79 -> V_38 = V_80 -> V_38 ;
return 0 ;
}
static void F_64 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_59 ( & V_26 -> V_74 [ V_85 ] . V_3 ) ;
}
static void F_65 ( struct V_23 * V_24 , struct V_72 * V_73 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
V_6 -> V_11 = F_8 ( V_87 ) ;
V_6 -> V_13 = F_8 ( sizeof( struct V_72 ) ) ;
memcpy ( & V_6 -> V_15 [ 0 ] , V_73 , sizeof( struct V_72 ) ) ;
F_37 ( V_24 , ( char * ) V_6 ,
V_4 + sizeof( struct V_72 ) ) ;
}
static void F_66 ( struct V_23 * V_24 , struct V_72 * V_88 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_72 * V_89 = (struct V_72 * )
V_26 -> V_74 [ V_75 ] . V_3 ;
if ( ! V_89 )
return;
if ( V_89 -> V_76 != V_88 -> V_76 ||
V_89 -> V_90 != V_88 -> V_90 ) {
if ( V_88 -> V_76 == V_91 ) {
F_67 ( V_24 ) ;
} else if ( V_89 -> V_76 == V_91 ) {
F_68 ( V_24 ) ;
#if F_48 ( V_52 )
F_69 ( V_26 ) ;
#endif
}
F_65 ( V_24 , V_88 ) ;
}
}
static int F_70 ( struct V_23 * V_24 , struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_93 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
int V_47 ;
if ( V_94 != V_97 )
return - V_98 ;
switch ( V_96 -> V_94 ) {
case V_99 :
case V_100 :
if ( V_96 -> V_101 >= V_86 ) {
F_38 ( V_24 , L_6 ,
V_44 , V_96 -> V_101 ) ;
return - V_98 ;
}
if ( V_96 -> V_94 == V_99 ) {
V_47 = F_60 (
& V_96 -> V_15 , & V_26 -> V_74 [ V_96 -> V_101 ] ) ;
if ( V_47 < 0 )
return V_47 ;
} else if ( V_96 -> V_94 == V_100 ) {
if ( V_96 -> V_101 == V_75 ) {
F_66 ( V_24 ,
(struct V_72 * ) V_96 -> V_15 . V_3 ) ;
}
V_47 = F_62 (
& V_26 -> V_74 [ V_96 -> V_101 ] , & V_96 -> V_15 ) ;
if ( V_47 < 0 )
return V_47 ;
}
break;
default:
F_38 ( V_24 , L_7 , V_44 , V_94 ) ;
return - V_98 ;
}
return 0 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
T_1 V_14 = 0 ;
T_3 V_102 = 0 ;
T_4 V_103 ;
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_104 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_72 ( V_105 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_23 ( V_26 , V_6 , V_4 + V_14 ) ;
V_102 = V_106 | V_107 ;
#if F_48 ( V_52 )
V_102 |= V_108 ;
#endif
#if F_48 ( V_109 )
V_102 |= V_110 ;
#endif
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_61 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_72 ( V_111 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_73 ( V_111 ) ;
V_103 = F_74 ( V_102 ) ;
memcpy ( & V_6 -> V_15 [ V_14 ] , & V_103 , F_73 ( V_111 ) ) ;
V_14 += F_73 ( V_111 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_23 ( V_26 , V_6 , V_4 + V_14 ) ;
F_75 ( V_24 , L_8 , V_102 ) ;
}
static int F_76 ( T_2 * V_3 , T_2 * V_112 , T_1 * V_113 , T_2 * * V_114 )
{
#define F_77 ( T_5 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_115 ;
* V_112 = V_3 [ 0 ] ;
if ( V_3 [ 1 ] == 0x82 ) {
* V_113 = F_78 ( F_77 ( & V_3 [ 2 ] ) ) ;
V_115 = 1 + 3 ;
} else {
* V_113 = V_3 [ 1 ] ;
V_115 = 1 + 1 ;
}
* V_114 = & V_3 [ V_115 ] ;
V_115 += * V_113 ;
return V_115 ;
}
static int F_79 ( struct V_23 * V_24 , char * V_3 ,
int V_14 )
{
T_2 V_112 , * V_114 ;
T_1 V_113 ;
T_1 V_11 , V_116 ;
int V_117 = V_4 ;
V_11 = F_80 ( ( const V_118 * ) & V_3 [ 0 ] ) ;
V_116 = F_80 ( ( const V_118 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_116 + V_4 ) {
F_38 ( V_24 , L_9 , V_44 ,
V_116 + V_4 , V_14 ) ;
return - 1 ;
}
if ( V_11 == V_119 ) {
if ( V_116 < 2 ) {
F_38 ( V_24 , L_10 ,
V_44 , V_11 , V_14 ) ;
return - 1 ;
}
V_117 += F_76 ( & V_3 [ V_117 ] , & V_112 , & V_113 , & V_114 ) ;
if ( V_112 == F_72 ( V_105 ) ) {
if ( V_113 != V_24 -> V_60 ) {
F_38 ( V_24 ,
L_11 ,
V_44 , V_112 , V_113 ) ;
return - 1 ;
}
F_75 ( V_24 , L_12 ,
V_24 -> V_59 , V_114 ) ;
memcpy ( V_24 -> V_59 , V_114 , V_24 -> V_60 ) ;
return 1 ;
}
}
F_37 ( V_24 , V_3 , V_14 ) ;
return 0 ;
}
static void F_81 ( struct V_23 * V_24 , char * V_3 , int V_14 )
{
struct V_1 * V_7 ;
int V_47 ;
V_7 = F_82 ( V_14 + 2 ) ;
if ( ! V_7 )
return;
F_83 ( V_7 , 2 ) ;
V_24 -> V_49 . V_120 ++ ;
V_24 -> V_49 . V_121 += V_14 ;
memcpy ( F_84 ( V_7 , V_14 ) , V_3 , V_14 ) ;
V_7 -> V_24 = V_24 ;
V_7 -> V_122 = F_85 ( V_7 , V_24 ) ;
V_47 = F_86 () ? F_87 ( V_7 ) : F_88 ( V_7 ) ;
if ( V_47 == V_123 )
F_38 ( V_24 , L_13 , V_44 ) ;
}
static void F_89 ( struct V_23 * V_24 , char * V_3 ,
int V_14 )
{
#define F_90 4
#define F_91 4
struct V_5 * V_6 ;
int V_13 ;
while ( V_14 > 0 ) {
V_6 = (struct V_5 * ) V_3 ;
if ( V_6 -> V_11 != F_8 ( V_124 ) ) {
F_38 ( V_24 , L_14 ,
F_78 ( V_6 -> V_11 ) ) ;
break;
}
V_13 = F_78 ( V_6 -> V_13 ) ;
F_81 ( V_24 , V_6 -> V_15 , V_13 ) ;
if ( V_13 & 0x3 ) {
V_13 += F_90 - ( V_13 & 0x3 ) ;
}
V_13 += V_4 + F_91 ;
V_14 -= V_13 ;
V_3 += V_13 ;
}
}
static void F_92 ( struct V_23 * V_24 , char * V_3 , int V_14 )
{
#if F_48 ( V_52 )
struct V_26 * V_26 = F_21 ( V_24 ) ;
#endif
T_1 V_11 , V_116 ;
if ( V_14 == 0 )
return;
V_11 = F_80 ( ( const V_118 * ) & V_3 [ 0 ] ) ;
V_116 = F_80 ( ( const V_118 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_116 + V_4 ) {
if ( V_14 )
F_38 ( V_24 , L_9 ,
V_44 , V_116 + V_4 , V_14 ) ;
return;
}
switch ( V_11 ) {
case V_125 :
F_89 ( V_24 , & V_3 [ V_4 ] ,
V_116 ) ;
break;
case V_124 :
F_81 ( V_24 , & V_3 [ V_4 ] , V_116 ) ;
break;
#if F_48 ( V_52 )
case V_126 :
F_93 ( V_26 , V_3 , V_14 ) ;
break;
#endif
case V_127 :
if ( V_3 [ 4 ] == 0 ) {
if ( ! F_41 ( V_24 ) )
F_45 ( V_24 ) ;
} else if ( V_3 [ 4 ] == 1 ) {
if ( F_41 ( V_24 ) )
F_42 ( V_24 ) ;
}
break;
default:
F_37 ( V_24 , V_3 , V_14 ) ;
break;
}
}
static void F_94 ( void * V_45 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_45 ;
F_92 ( V_26 -> V_46 , V_15 , V_14 ) ;
F_95 ( V_26 , F_94 , V_26 ) ;
}
static void F_96 ( void * V_45 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_45 ;
int V_47 ;
V_47 = F_79 ( V_26 -> V_46 , V_15 , V_14 ) ;
if ( V_47 == 1 ) {
F_95 ( V_26 , F_94 , V_26 ) ;
} else {
if ( V_47 < 0 )
F_38 ( V_26 -> V_46 ,
L_15 , V_47 ) ;
F_95 ( V_26 , F_96 , V_26 ) ;
}
}
static void F_97 ( struct V_26 * V_26 )
{
F_95 ( V_26 , F_96 , V_26 ) ;
}
int F_98 ( struct V_128 * V_128 , struct V_129 * V_130 )
{
struct V_26 * V_26 = NULL ;
struct V_23 * V_24 ;
int V_47 ;
V_24 = F_99 ( sizeof( * V_26 ) , L_2 , V_131 ,
V_132 ) ;
if ( ! V_24 ) {
F_34 ( L_16 ) ;
return - V_9 ;
}
F_100 ( V_24 , V_130 ) ;
V_24 -> V_133 = 1400 ;
V_24 -> V_134 = & V_135 ;
V_24 -> V_32 &= ~ V_136 ;
memcpy ( V_24 -> V_59 , V_137 , sizeof( V_137 ) ) ;
V_26 = F_21 ( V_24 ) ;
V_26 -> V_46 = V_24 ;
V_26 -> V_128 = V_128 ;
V_128 -> V_46 = V_24 ;
V_47 = F_29 () ;
if ( V_47 < 0 ) {
F_34 ( L_17 ) ;
goto V_138;
}
V_47 = F_101 ( V_24 ) ;
if ( V_47 )
goto V_138;
F_68 ( V_24 ) ;
#ifdef V_52
F_102 ( V_26 ) ;
#endif
F_97 ( V_26 ) ;
F_71 ( V_24 ) ;
return 0 ;
V_138:
F_34 ( L_18 ) ;
F_103 ( V_24 ) ;
return V_47 ;
}
void F_104 ( struct V_128 * V_128 )
{
struct V_26 * V_26 = F_21 ( V_128 -> V_46 ) ;
struct V_72 * V_73 = (struct V_72 * ) V_26 -> V_74 [ V_75 ] . V_3 ;
if ( V_73 )
V_73 -> V_76 = V_77 ;
F_105 ( V_26 -> V_46 ) ;
F_35 () ;
#if F_48 ( V_52 )
F_69 ( V_26 ) ;
#endif
F_64 ( V_128 -> V_46 ) ;
F_103 ( V_26 -> V_46 ) ;
}
