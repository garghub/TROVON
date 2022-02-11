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
F_25 ( & V_19 . V_33 , V_32 ) ;
while ( ! F_14 ( & V_19 . V_34 ) ) {
V_18 = F_15 ( V_19 . V_34 . V_21 , struct V_16 , V_22 ) ;
F_26 ( & V_19 . V_33 , V_32 ) ;
if ( sscanf ( V_18 -> V_24 -> V_35 , L_2 , & V_31 ) == 1 )
F_27 ( V_19 . V_36 , V_31 , 0 , V_18 -> V_37 ,
V_18 -> V_38 ) ;
F_25 ( & V_19 . V_33 , V_32 ) ;
F_16 ( & V_18 -> V_22 ) ;
F_17 ( V_18 ) ;
}
F_26 ( & V_19 . V_33 , V_32 ) ;
}
static int F_28 ( void )
{
if ( ! V_19 . V_39 ) {
V_19 . V_36 = F_29 ( V_40 ,
F_20 ) ;
if ( V_19 . V_36 ) {
F_30 ( & V_19 . V_34 ) ;
F_30 ( & V_19 . V_20 ) ;
F_31 ( & V_19 . V_41 , F_24 ) ;
F_32 ( & V_19 . V_33 ) ;
}
}
if ( V_19 . V_36 ) {
V_19 . V_39 ++ ;
return 0 ;
}
F_33 ( L_3 ) ;
return - 1 ;
}
static void F_34 ( void )
{
if ( V_19 . V_36 && -- V_19 . V_39 == 0 ) {
struct V_16 * V_18 , * V_42 ;
unsigned long V_32 ;
F_25 ( & V_19 . V_33 , V_32 ) ;
F_35 (e, temp, &wm_event.evtq, list) {
F_16 ( & V_18 -> V_22 ) ;
F_11 ( V_18 ) ;
}
F_35 (e, temp, &wm_event.freeq, list) {
F_16 ( & V_18 -> V_22 ) ;
F_11 ( V_18 ) ;
}
F_26 ( & V_19 . V_33 , V_32 ) ;
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
F_25 ( & V_19 . V_33 , V_32 ) ;
V_18 = F_13 () ;
if ( ! V_18 ) {
F_38 ( V_24 , L_5 , V_43 ) ;
F_26 ( & V_19 . V_33 , V_32 ) ;
return - V_9 ;
}
V_18 -> V_24 = V_24 ;
V_18 -> V_38 = V_38 ;
memcpy ( V_18 -> V_37 , V_3 , V_38 ) ;
F_19 ( & V_18 -> V_22 , & V_19 . V_34 ) ;
F_26 ( & V_19 . V_33 , V_32 ) ;
F_39 ( & V_19 . V_41 ) ;
return 0 ;
}
static void F_40 ( void * V_44 )
{
struct V_26 * V_26 = V_44 ;
if ( F_41 ( V_26 -> V_45 ) )
F_42 ( V_26 -> V_45 ) ;
}
int F_43 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_46 = 0 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
V_46 = F_44 ( V_26 , V_7 -> V_15 , V_7 -> V_14 , F_40 ,
V_26 ) ;
if ( V_46 == - V_47 ) {
F_45 ( V_24 ) ;
V_46 = 0 ;
}
if ( V_46 ) {
F_46 ( V_7 , V_4 ) ;
return V_46 ;
}
V_24 -> V_48 . V_49 ++ ;
V_24 -> V_48 . V_50 += V_7 -> V_14 - V_4 ;
F_6 ( V_7 ) ;
return V_46 ;
}
static int F_47 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_46 = 0 ;
V_46 = F_1 ( & V_7 ) ;
if ( V_46 < 0 ) {
F_46 ( V_7 , V_4 ) ;
return V_46 ;
}
#if F_48 ( V_51 )
V_46 = F_49 ( V_7 , V_24 ) ;
#else
V_46 = F_43 ( V_7 , V_24 ) ;
#endif
return V_46 ;
}
static int F_50 ( struct V_23 * V_24 , struct V_52 * V_53 )
{
if ( V_24 -> V_32 & V_54 )
return - V_55 ;
return 0 ;
}
static void F_51 ( struct V_23 * V_24 , char * V_56 )
{
T_1 V_57 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
memcpy ( V_24 -> V_58 , V_56 , V_24 -> V_59 ) ;
V_6 -> V_11 = F_8 ( V_60 ) ;
V_6 -> V_13 = F_8 ( 8 ) ;
V_6 -> V_15 [ 0 ] = 0 ;
V_6 -> V_15 [ 1 ] = 6 ;
memcpy ( & V_6 -> V_15 [ 2 ] , V_56 , V_24 -> V_59 ) ;
F_23 ( V_26 , V_6 , V_4 + 8 ) ;
}
static int F_52 ( struct V_23 * V_24 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
if ( F_53 ( V_24 ) )
return - V_55 ;
if ( ! F_54 ( V_63 -> V_64 ) )
return - V_65 ;
F_51 ( V_24 , V_63 -> V_64 ) ;
return 0 ;
}
static void F_55 ( struct V_23 * V_24 , int V_66 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
unsigned char V_67 ;
V_67 = V_66 ? V_68 : V_69 ;
V_6 -> V_11 = F_8 ( V_70 ) ;
V_6 -> V_13 = F_8 ( sizeof( V_67 ) ) ;
V_6 -> V_15 [ 0 ] = V_67 ;
F_37 ( V_24 , ( char * ) V_6 , V_4 + sizeof( V_67 ) ) ;
}
static int F_56 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_71 * V_72 = (struct V_71 * ) V_26 -> V_73 [ V_74 ] . V_3 ;
F_57 ( V_24 ) ;
if ( V_72 && V_72 -> V_75 != V_76 )
F_55 ( V_24 , 1 ) ;
return 0 ;
}
static int F_58 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_71 * V_72 = (struct V_71 * ) V_26 -> V_73 [ V_74 ] . V_3 ;
F_45 ( V_24 ) ;
if ( V_72 && V_72 -> V_75 != V_76 )
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
static int F_60 ( struct V_77 * V_78 , struct V_77 * V_79 )
{
int V_38 ;
V_38 = V_78 -> V_38 < V_79 -> V_38 ? V_78 -> V_38 : V_79 -> V_38 ;
V_78 -> V_38 = V_38 ;
if ( V_79 -> V_38 ) {
if ( ! V_78 -> V_3 )
return - V_80 ;
if ( F_61 ( ( void V_81 * ) V_78 -> V_3 , V_79 -> V_3 , V_38 ) )
return - V_82 ;
}
return 0 ;
}
static int F_62 ( struct V_77 * V_78 , struct V_77 * V_79 )
{
if ( ! V_79 -> V_38 ) {
V_78 -> V_38 = 0 ;
return 0 ;
}
if ( ! V_79 -> V_3 )
return - V_80 ;
if ( ! ( V_78 -> V_3 && V_78 -> V_38 == V_79 -> V_38 ) ) {
F_59 ( & V_78 -> V_3 ) ;
V_78 -> V_3 = F_10 ( V_79 -> V_38 , V_83 ) ;
if ( V_78 -> V_3 == NULL )
return - V_9 ;
}
if ( F_63 ( V_78 -> V_3 , ( void V_81 * ) V_79 -> V_3 , V_79 -> V_38 ) ) {
F_59 ( & V_78 -> V_3 ) ;
return - V_82 ;
}
V_78 -> V_38 = V_79 -> V_38 ;
return 0 ;
}
static void F_64 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ )
F_59 ( & V_26 -> V_73 [ V_84 ] . V_3 ) ;
}
static void F_65 ( struct V_23 * V_24 , struct V_71 * V_72 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
V_6 -> V_11 = F_8 ( V_86 ) ;
V_6 -> V_13 = F_8 ( sizeof( struct V_71 ) ) ;
memcpy ( & V_6 -> V_15 [ 0 ] , V_72 , sizeof( struct V_71 ) ) ;
F_37 ( V_24 , ( char * ) V_6 ,
V_4 + sizeof( struct V_71 ) ) ;
}
static void F_66 ( struct V_23 * V_24 , struct V_71 * V_87 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
struct V_71 * V_88 = (struct V_71 * )
V_26 -> V_73 [ V_74 ] . V_3 ;
if ( ! V_88 )
return;
if ( V_88 -> V_75 != V_87 -> V_75 ||
V_88 -> V_89 != V_87 -> V_89 ) {
if ( V_87 -> V_75 == V_90 ) {
F_67 ( V_24 ) ;
} else if ( V_88 -> V_75 == V_90 ) {
F_68 ( V_24 ) ;
#if F_48 ( V_51 )
F_69 ( V_26 ) ;
#endif
}
F_65 ( V_24 , V_87 ) ;
}
}
static int F_70 ( struct V_23 * V_24 , struct V_91 * V_92 , int V_93 )
{
struct V_94 * V_95 = (struct V_94 * ) V_92 ;
struct V_26 * V_26 = F_21 ( V_24 ) ;
int V_46 ;
if ( V_93 != V_96 )
return - V_97 ;
switch ( V_95 -> V_93 ) {
case V_98 :
case V_99 :
if ( V_95 -> V_100 >= V_85 ) {
F_38 ( V_24 , L_6 ,
V_43 , V_95 -> V_100 ) ;
return - V_97 ;
}
if ( V_95 -> V_93 == V_98 ) {
V_46 = F_60 (
& V_95 -> V_15 , & V_26 -> V_73 [ V_95 -> V_100 ] ) ;
if ( V_46 < 0 )
return V_46 ;
} else if ( V_95 -> V_93 == V_99 ) {
if ( V_95 -> V_100 == V_74 ) {
F_66 ( V_24 ,
(struct V_71 * ) V_95 -> V_15 . V_3 ) ;
}
V_46 = F_62 (
& V_26 -> V_73 [ V_95 -> V_100 ] , & V_95 -> V_15 ) ;
if ( V_46 < 0 )
return V_46 ;
}
break;
default:
F_38 ( V_24 , L_7 , V_43 , V_93 ) ;
return - V_97 ;
}
return 0 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_21 ( V_24 ) ;
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
T_1 V_14 = 0 ;
T_3 V_101 = 0 ;
T_4 V_102 ;
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_103 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_72 ( V_104 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_23 ( V_26 , V_6 , V_4 + V_14 ) ;
V_101 = V_105 | V_106 ;
#if F_48 ( V_51 )
V_101 |= V_107 ;
#endif
#if F_48 ( V_108 )
V_101 |= V_109 ;
#endif
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_60 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_72 ( V_110 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_73 ( V_110 ) ;
V_102 = F_74 ( V_101 ) ;
memcpy ( & V_6 -> V_15 [ V_14 ] , & V_102 , F_73 ( V_110 ) ) ;
V_14 += F_73 ( V_110 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_23 ( V_26 , V_6 , V_4 + V_14 ) ;
F_75 ( V_24 , L_8 , V_101 ) ;
}
static int F_76 ( T_2 * V_3 , T_2 * V_111 , T_1 * V_112 , T_2 * * V_113 )
{
#define F_77 ( T_5 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_114 ;
* V_111 = V_3 [ 0 ] ;
if ( V_3 [ 1 ] == 0x82 ) {
* V_112 = F_78 ( F_77 ( & V_3 [ 2 ] ) ) ;
V_114 = 1 + 3 ;
} else {
* V_112 = V_3 [ 1 ] ;
V_114 = 1 + 1 ;
}
* V_113 = & V_3 [ V_114 ] ;
V_114 += * V_112 ;
return V_114 ;
}
static int F_79 ( struct V_23 * V_24 , char * V_3 ,
int V_14 )
{
T_2 V_111 , * V_113 ;
T_1 V_112 ;
T_1 V_11 , V_115 ;
int V_116 = V_4 ;
V_11 = F_80 ( ( const V_117 * ) & V_3 [ 0 ] ) ;
V_115 = F_80 ( ( const V_117 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_115 + V_4 ) {
F_38 ( V_24 , L_9 , V_43 ,
V_115 + V_4 , V_14 ) ;
return - 1 ;
}
if ( V_11 == V_118 ) {
if ( V_115 < 2 ) {
F_38 ( V_24 , L_10 ,
V_43 , V_11 , V_14 ) ;
return - 1 ;
}
V_116 += F_76 ( & V_3 [ V_116 ] , & V_111 , & V_112 , & V_113 ) ;
if ( V_111 == F_72 ( V_104 ) ) {
if ( V_112 != V_24 -> V_59 ) {
F_38 ( V_24 ,
L_11 ,
V_43 , V_111 , V_112 ) ;
return - 1 ;
}
F_75 ( V_24 , L_12 ,
V_24 -> V_58 , V_113 ) ;
memcpy ( V_24 -> V_58 , V_113 , V_24 -> V_59 ) ;
return 1 ;
}
}
F_37 ( V_24 , V_3 , V_14 ) ;
return 0 ;
}
static void F_81 ( struct V_23 * V_24 , char * V_3 , int V_14 )
{
struct V_1 * V_7 ;
int V_46 ;
V_7 = F_82 ( V_14 + 2 ) ;
if ( ! V_7 )
return;
F_83 ( V_7 , 2 ) ;
V_24 -> V_48 . V_119 ++ ;
V_24 -> V_48 . V_120 += V_14 ;
memcpy ( F_84 ( V_7 , V_14 ) , V_3 , V_14 ) ;
V_7 -> V_24 = V_24 ;
V_7 -> V_121 = F_85 ( V_7 , V_24 ) ;
V_46 = F_86 () ? F_87 ( V_7 ) : F_88 ( V_7 ) ;
if ( V_46 == V_122 )
F_38 ( V_24 , L_13 , V_43 ) ;
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
if ( V_6 -> V_11 != F_8 ( V_123 ) ) {
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
#if F_48 ( V_51 )
struct V_26 * V_26 = F_21 ( V_24 ) ;
#endif
T_1 V_11 , V_115 ;
if ( V_14 == 0 )
return;
V_11 = F_80 ( ( const V_117 * ) & V_3 [ 0 ] ) ;
V_115 = F_80 ( ( const V_117 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_115 + V_4 ) {
if ( V_14 )
F_38 ( V_24 , L_9 ,
V_43 , V_115 + V_4 , V_14 ) ;
return;
}
switch ( V_11 ) {
case V_124 :
F_89 ( V_24 , & V_3 [ V_4 ] ,
V_115 ) ;
break;
case V_123 :
F_81 ( V_24 , & V_3 [ V_4 ] , V_115 ) ;
break;
#if F_48 ( V_51 )
case V_125 :
F_93 ( V_26 , V_3 , V_14 ) ;
break;
#endif
case V_126 :
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
static void F_94 ( void * V_44 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_44 ;
F_92 ( V_26 -> V_45 , V_15 , V_14 ) ;
F_95 ( V_26 , F_94 , V_26 ) ;
}
static void F_96 ( void * V_44 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_44 ;
int V_46 ;
V_46 = F_79 ( V_26 -> V_45 , V_15 , V_14 ) ;
if ( V_46 == 1 ) {
F_95 ( V_26 , F_94 , V_26 ) ;
} else {
if ( V_46 < 0 )
F_38 ( V_26 -> V_45 ,
L_15 , V_46 ) ;
F_95 ( V_26 , F_96 , V_26 ) ;
}
}
static void F_97 ( struct V_26 * V_26 )
{
F_95 ( V_26 , F_96 , V_26 ) ;
}
int F_98 ( struct V_127 * V_127 , struct V_128 * V_129 )
{
struct V_26 * V_26 = NULL ;
struct V_23 * V_24 ;
int V_46 ;
V_24 = F_99 ( sizeof( * V_26 ) , L_2 , V_130 ,
V_131 ) ;
if ( V_24 == NULL ) {
F_33 ( L_16 ) ;
return - V_9 ;
}
F_100 ( V_24 , V_129 ) ;
V_24 -> V_132 = 1400 ;
V_24 -> V_133 = & V_134 ;
V_24 -> V_32 &= ~ V_135 ;
memcpy ( V_24 -> V_58 , V_136 , sizeof( V_136 ) ) ;
V_26 = F_21 ( V_24 ) ;
V_26 -> V_45 = V_24 ;
V_26 -> V_127 = V_127 ;
V_127 -> V_45 = V_24 ;
V_46 = F_28 () ;
if ( V_46 < 0 ) {
F_33 ( L_17 ) ;
goto V_137;
}
V_46 = F_101 ( V_24 ) ;
if ( V_46 )
goto V_137;
F_68 ( V_24 ) ;
#ifdef V_51
F_102 ( V_26 ) ;
#endif
F_97 ( V_26 ) ;
F_71 ( V_24 ) ;
return 0 ;
V_137:
F_33 ( L_18 ) ;
F_103 ( V_24 ) ;
return V_46 ;
}
void F_104 ( struct V_127 * V_127 )
{
struct V_26 * V_26 = F_21 ( V_127 -> V_45 ) ;
struct V_71 * V_72 = (struct V_71 * ) V_26 -> V_73 [ V_74 ] . V_3 ;
if ( V_72 )
V_72 -> V_75 = V_76 ;
F_105 ( V_26 -> V_45 ) ;
F_34 () ;
#if F_48 ( V_51 )
F_69 ( V_26 ) ;
#endif
F_64 ( V_127 -> V_45 ) ;
F_103 ( V_26 -> V_45 ) ;
}
