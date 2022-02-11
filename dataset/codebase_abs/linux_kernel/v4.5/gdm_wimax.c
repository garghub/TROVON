static inline int F_1 ( struct V_1 * * V_2 )
{
T_1 V_3 [ V_4 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
struct V_1 * V_7 = * V_2 ;
if ( F_2 ( F_3 ( V_7 ) < V_4 ) ) {
struct V_1 * V_8 ;
V_8 = F_4 ( V_7 , V_4 ) ;
if ( ! V_8 )
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
static struct V_16 * F_11 ( void )
{
struct V_16 * V_18 ;
if ( F_12 ( & V_19 . V_20 ) ) {
V_18 = F_9 () ;
} else {
V_18 = F_13 ( V_19 . V_20 . V_21 , struct V_16 , V_22 ) ;
F_14 ( & V_18 -> V_22 ) ;
}
return V_18 ;
}
static void F_15 ( struct V_16 * V_18 )
{
F_16 ( ! V_18 ) ;
F_17 ( & V_18 -> V_22 , & V_19 . V_20 ) ;
}
static void F_18 ( struct V_23 * V_24 , T_1 type , void * V_25 ,
int V_14 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
T_2 * V_3 = V_25 ;
T_1 V_27 = ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ;
T_1 V_28 = ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ;
F_20 ( V_24 , L_1 , V_27 , V_28 ) ;
F_21 ( V_26 , V_25 , V_14 ) ;
}
static void F_22 ( struct V_29 * V_30 )
{
int V_31 ;
unsigned long V_32 ;
struct V_16 * V_18 ;
struct V_16 * V_33 ;
F_23 ( & V_19 . V_34 , V_32 ) ;
F_24 (e, tmp, &wm_event.evtq, list) {
F_25 ( & V_19 . V_34 , V_32 ) ;
if ( sscanf ( V_18 -> V_24 -> V_35 , L_2 , & V_31 ) == 1 )
F_26 ( V_19 . V_36 , V_31 , 0 , V_18 -> V_37 ,
V_18 -> V_38 ) ;
F_23 ( & V_19 . V_34 , V_32 ) ;
F_14 ( & V_18 -> V_22 ) ;
F_15 ( V_18 ) ;
}
F_25 ( & V_19 . V_34 , V_32 ) ;
}
static int F_27 ( void )
{
if ( ! V_19 . V_39 ) {
V_19 . V_36 = F_28 ( V_40 ,
F_18 ) ;
if ( V_19 . V_36 ) {
F_29 ( & V_19 . V_41 ) ;
F_29 ( & V_19 . V_20 ) ;
F_30 ( & V_19 . V_42 , F_22 ) ;
F_31 ( & V_19 . V_34 ) ;
}
}
if ( V_19 . V_36 ) {
V_19 . V_39 ++ ;
return 0 ;
}
F_32 ( L_3 ) ;
return - 1 ;
}
static void F_33 ( void )
{
if ( V_19 . V_36 && -- V_19 . V_39 == 0 ) {
struct V_16 * V_18 , * V_43 ;
unsigned long V_32 ;
F_23 ( & V_19 . V_34 , V_32 ) ;
F_24 (e, temp, &wm_event.evtq, list) {
F_14 ( & V_18 -> V_22 ) ;
F_34 ( V_18 ) ;
}
F_24 (e, temp, &wm_event.freeq, list) {
F_14 ( & V_18 -> V_22 ) ;
F_34 ( V_18 ) ;
}
F_25 ( & V_19 . V_34 , V_32 ) ;
F_35 ( V_19 . V_36 ) ;
V_19 . V_36 = NULL ;
}
}
static int F_36 ( struct V_23 * V_24 , char * V_3 , int V_38 )
{
struct V_16 * V_18 ;
unsigned long V_32 ;
T_1 V_27 = ( ( T_2 ) V_3 [ 0 ] << 8 ) | ( T_2 ) V_3 [ 1 ] ;
T_1 V_28 = ( ( T_2 ) V_3 [ 2 ] << 8 ) | ( T_2 ) V_3 [ 3 ] ;
F_20 ( V_24 , L_4 , V_27 , V_28 ) ;
F_23 ( & V_19 . V_34 , V_32 ) ;
V_18 = F_11 () ;
if ( ! V_18 ) {
F_37 ( V_24 , L_5 , V_44 ) ;
F_25 ( & V_19 . V_34 , V_32 ) ;
return - V_9 ;
}
V_18 -> V_24 = V_24 ;
V_18 -> V_38 = V_38 ;
memcpy ( V_18 -> V_37 , V_3 , V_38 ) ;
F_17 ( & V_18 -> V_22 , & V_19 . V_41 ) ;
F_25 ( & V_19 . V_34 , V_32 ) ;
F_38 ( & V_19 . V_42 ) ;
return 0 ;
}
static void F_39 ( void * V_45 )
{
struct V_26 * V_26 = V_45 ;
if ( F_40 ( V_26 -> V_46 ) )
F_41 ( V_26 -> V_46 ) ;
}
int F_42 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_47 = 0 ;
struct V_26 * V_26 = F_19 ( V_24 ) ;
V_47 = F_43 ( V_26 , V_7 -> V_15 , V_7 -> V_14 , F_39 ,
V_26 ) ;
if ( V_47 == - V_48 ) {
F_44 ( V_24 ) ;
V_47 = 0 ;
}
if ( V_47 ) {
F_45 ( V_7 , V_4 ) ;
return V_47 ;
}
V_24 -> V_49 . V_50 ++ ;
V_24 -> V_49 . V_51 += V_7 -> V_14 - V_4 ;
F_6 ( V_7 ) ;
return V_47 ;
}
static int F_46 ( struct V_1 * V_7 , struct V_23 * V_24 )
{
int V_47 = 0 ;
V_47 = F_1 ( & V_7 ) ;
if ( V_47 < 0 ) {
F_45 ( V_7 , V_4 ) ;
return V_47 ;
}
#if F_47 ( V_52 )
V_47 = F_48 ( V_7 , V_24 ) ;
#else
V_47 = F_42 ( V_7 , V_24 ) ;
#endif
return V_47 ;
}
static int F_49 ( struct V_23 * V_24 , struct V_53 * V_54 )
{
if ( V_24 -> V_32 & V_55 )
return - V_56 ;
return 0 ;
}
static void F_50 ( struct V_23 * V_24 , char * V_57 )
{
T_1 V_58 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_58 ;
struct V_26 * V_26 = F_19 ( V_24 ) ;
memcpy ( V_24 -> V_59 , V_57 , V_24 -> V_60 ) ;
V_6 -> V_11 = F_8 ( V_61 ) ;
V_6 -> V_13 = F_8 ( 8 ) ;
V_6 -> V_15 [ 0 ] = 0 ;
V_6 -> V_15 [ 1 ] = 6 ;
memcpy ( & V_6 -> V_15 [ 2 ] , V_57 , V_24 -> V_60 ) ;
F_21 ( V_26 , V_6 , V_4 + 8 ) ;
}
static int F_51 ( struct V_23 * V_24 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
if ( F_52 ( V_24 ) )
return - V_56 ;
if ( ! F_53 ( V_64 -> V_65 ) )
return - V_66 ;
F_50 ( V_24 , V_64 -> V_65 ) ;
return 0 ;
}
static void F_54 ( struct V_23 * V_24 , int V_67 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
unsigned char V_68 ;
V_68 = V_67 ? V_69 : V_70 ;
V_6 -> V_11 = F_8 ( V_71 ) ;
V_6 -> V_13 = F_8 ( sizeof( V_68 ) ) ;
V_6 -> V_15 [ 0 ] = V_68 ;
F_36 ( V_24 , ( char * ) V_6 , V_4 + sizeof( V_68 ) ) ;
}
static int F_55 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
struct V_72 * V_73 = V_26 -> V_74 [ V_75 ] . V_3 ;
F_56 ( V_24 ) ;
if ( V_73 && V_73 -> V_76 != V_77 )
F_54 ( V_24 , 1 ) ;
return 0 ;
}
static int F_57 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
struct V_72 * V_73 = V_26 -> V_74 [ V_75 ] . V_3 ;
F_44 ( V_24 ) ;
if ( V_73 && V_73 -> V_76 != V_77 )
F_54 ( V_24 , 0 ) ;
return 0 ;
}
static void F_58 ( void * * V_3 )
{
if ( V_3 && * V_3 ) {
F_34 ( * V_3 ) ;
* V_3 = NULL ;
}
}
static int F_59 ( struct V_78 * V_79 , struct V_80 * V_81 )
{
int V_38 ;
V_38 = V_79 -> V_38 < V_81 -> V_38 ? V_79 -> V_38 : V_81 -> V_38 ;
V_79 -> V_38 = V_38 ;
if ( V_81 -> V_38 ) {
if ( ! V_79 -> V_3 )
return - V_82 ;
if ( F_60 ( V_79 -> V_3 , V_81 -> V_3 , V_38 ) )
return - V_83 ;
}
return 0 ;
}
static int F_61 ( struct V_80 * V_79 , struct V_78 * V_81 )
{
if ( ! V_81 -> V_38 ) {
V_79 -> V_38 = 0 ;
return 0 ;
}
if ( ! V_81 -> V_3 )
return - V_82 ;
if ( ! ( V_79 -> V_3 && V_79 -> V_38 == V_81 -> V_38 ) ) {
F_58 ( & V_79 -> V_3 ) ;
V_79 -> V_3 = F_10 ( V_81 -> V_38 , V_84 ) ;
if ( ! V_79 -> V_3 )
return - V_9 ;
}
if ( F_62 ( V_79 -> V_3 , V_81 -> V_3 , V_81 -> V_38 ) ) {
F_58 ( & V_79 -> V_3 ) ;
return - V_83 ;
}
V_79 -> V_38 = V_81 -> V_38 ;
return 0 ;
}
static void F_63 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_58 ( & V_26 -> V_74 [ V_85 ] . V_3 ) ;
}
static void F_64 ( struct V_23 * V_24 , struct V_72 * V_73 )
{
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
V_6 -> V_11 = F_8 ( V_87 ) ;
V_6 -> V_13 = F_8 ( sizeof( struct V_72 ) ) ;
memcpy ( & V_6 -> V_15 [ 0 ] , V_73 , sizeof( struct V_72 ) ) ;
F_36 ( V_24 , ( char * ) V_6 ,
V_4 + sizeof( struct V_72 ) ) ;
}
static void F_65 ( struct V_23 * V_24 , struct V_72 * V_88 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
struct V_72 * V_89 =
V_26 -> V_74 [ V_75 ] . V_3 ;
if ( ! V_89 )
return;
if ( V_89 -> V_76 != V_88 -> V_76 ||
V_89 -> V_90 != V_88 -> V_90 ) {
if ( V_88 -> V_76 == V_91 ) {
F_66 ( V_24 ) ;
} else if ( V_89 -> V_76 == V_91 ) {
F_67 ( V_24 ) ;
#if F_47 ( V_52 )
F_68 ( V_26 ) ;
#endif
}
F_64 ( V_24 , V_88 ) ;
}
}
static int F_69 ( struct V_23 * V_24 , struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_93 ;
struct V_26 * V_26 = F_19 ( V_24 ) ;
int V_47 ;
struct V_72 V_97 ;
if ( V_94 != V_98 )
return - V_99 ;
switch ( V_96 -> V_94 ) {
case V_100 :
case V_101 :
if ( V_96 -> V_102 >= V_86 ) {
F_37 ( V_24 , L_6 ,
V_44 , V_96 -> V_102 ) ;
return - V_99 ;
}
if ( V_96 -> V_94 == V_100 ) {
V_47 = F_59 (
& V_96 -> V_15 , & V_26 -> V_74 [ V_96 -> V_102 ] ) ;
if ( V_47 < 0 )
return V_47 ;
} else if ( V_96 -> V_94 == V_101 ) {
if ( V_96 -> V_102 == V_75 ) {
if ( F_62 ( & V_97 , V_96 -> V_15 . V_3 ,
sizeof( struct V_72 ) ) )
return - V_83 ;
F_65 ( V_24 , & V_97 ) ;
}
V_47 = F_61 (
& V_26 -> V_74 [ V_96 -> V_102 ] , & V_96 -> V_15 ) ;
if ( V_47 < 0 )
return V_47 ;
}
break;
default:
F_37 ( V_24 , L_7 , V_44 , V_94 ) ;
return - V_99 ;
}
return 0 ;
}
static void F_70 ( struct V_23 * V_24 )
{
struct V_26 * V_26 = F_19 ( V_24 ) ;
T_1 V_3 [ 32 / sizeof( T_1 ) ] ;
struct V_5 * V_6 = (struct V_5 * ) V_3 ;
T_1 V_14 = 0 ;
T_3 V_103 = 0 ;
T_4 V_104 ;
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_105 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_71 ( V_106 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_21 ( V_26 , V_6 , V_4 + V_14 ) ;
V_103 = V_107 | V_108 ;
#if F_47 ( V_52 )
V_103 |= V_109 ;
#endif
#if F_47 ( V_110 )
V_103 |= V_111 ;
#endif
V_14 = 0 ;
V_6 -> V_11 = F_8 ( V_61 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_71 ( V_112 ) ;
V_6 -> V_15 [ V_14 ++ ] = F_72 ( V_112 ) ;
V_104 = F_73 ( V_103 ) ;
memcpy ( & V_6 -> V_15 [ V_14 ] , & V_104 , F_72 ( V_112 ) ) ;
V_14 += F_72 ( V_112 ) ;
V_6 -> V_13 = F_8 ( V_14 ) ;
F_21 ( V_26 , V_6 , V_4 + V_14 ) ;
F_74 ( V_24 , L_8 , V_103 ) ;
}
static int F_75 ( T_2 * V_3 , T_2 * V_113 , T_1 * V_114 , T_2 * * V_115 )
{
#define F_76 ( T_5 ) ((u16)((u8 *)(b))[0] | ((u16)((u8 *)(b))[1] << 8))
int V_116 ;
* V_113 = V_3 [ 0 ] ;
if ( V_3 [ 1 ] == 0x82 ) {
* V_114 = F_77 ( F_76 ( & V_3 [ 2 ] ) ) ;
V_116 = 1 + 3 ;
} else {
* V_114 = V_3 [ 1 ] ;
V_116 = 1 + 1 ;
}
* V_115 = & V_3 [ V_116 ] ;
V_116 += * V_114 ;
return V_116 ;
}
static int F_78 ( struct V_23 * V_24 , char * V_3 ,
int V_14 )
{
T_2 V_113 , * V_115 ;
T_1 V_114 ;
T_1 V_11 , V_117 ;
int V_118 = V_4 ;
V_11 = F_79 ( ( const V_119 * ) & V_3 [ 0 ] ) ;
V_117 = F_79 ( ( const V_119 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_117 + V_4 ) {
F_37 ( V_24 , L_9 , V_44 ,
V_117 + V_4 , V_14 ) ;
return - 1 ;
}
if ( V_11 == V_120 ) {
if ( V_117 < 2 ) {
F_37 ( V_24 , L_10 ,
V_44 , V_11 , V_14 ) ;
return - 1 ;
}
V_118 += F_75 ( & V_3 [ V_118 ] , & V_113 , & V_114 , & V_115 ) ;
if ( F_71 ( V_106 ) == V_113 ) {
if ( V_24 -> V_60 != V_114 ) {
F_37 ( V_24 ,
L_11 ,
V_44 , V_113 , V_114 ) ;
return - 1 ;
}
F_74 ( V_24 , L_12 ,
V_24 -> V_59 , V_115 ) ;
memcpy ( V_24 -> V_59 , V_115 , V_24 -> V_60 ) ;
return 1 ;
}
}
F_36 ( V_24 , V_3 , V_14 ) ;
return 0 ;
}
static void F_80 ( struct V_23 * V_24 , char * V_3 , int V_14 )
{
struct V_1 * V_7 ;
int V_47 ;
V_7 = F_81 ( V_14 + 2 ) ;
if ( ! V_7 )
return;
F_82 ( V_7 , 2 ) ;
V_24 -> V_49 . V_121 ++ ;
V_24 -> V_49 . V_122 += V_14 ;
memcpy ( F_83 ( V_7 , V_14 ) , V_3 , V_14 ) ;
V_7 -> V_24 = V_24 ;
V_7 -> V_123 = F_84 ( V_7 , V_24 ) ;
V_47 = F_85 () ? F_86 ( V_7 ) : F_87 ( V_7 ) ;
if ( V_47 == V_124 )
F_37 ( V_24 , L_13 , V_44 ) ;
}
static void F_88 ( struct V_23 * V_24 , char * V_3 ,
int V_14 )
{
#define F_89 4
#define F_90 4
struct V_5 * V_6 ;
int V_13 ;
while ( V_14 > 0 ) {
V_6 = (struct V_5 * ) V_3 ;
if ( V_6 -> V_11 != F_8 ( V_125 ) ) {
F_37 ( V_24 , L_14 ,
F_77 ( V_6 -> V_11 ) ) ;
break;
}
V_13 = F_77 ( V_6 -> V_13 ) ;
F_80 ( V_24 , V_6 -> V_15 , V_13 ) ;
if ( V_13 & 0x3 ) {
V_13 += F_89 - ( V_13 & 0x3 ) ;
}
V_13 += V_4 + F_90 ;
V_14 -= V_13 ;
V_3 += V_13 ;
}
}
static void F_91 ( struct V_23 * V_24 , char * V_3 , int V_14 )
{
#if F_47 ( V_52 )
struct V_26 * V_26 = F_19 ( V_24 ) ;
#endif
T_1 V_11 , V_117 ;
if ( V_14 == 0 )
return;
V_11 = F_79 ( ( const V_119 * ) & V_3 [ 0 ] ) ;
V_117 = F_79 ( ( const V_119 * ) & V_3 [ 2 ] ) ;
if ( V_14 < V_117 + V_4 ) {
if ( V_14 )
F_37 ( V_24 , L_9 ,
V_44 , V_117 + V_4 , V_14 ) ;
return;
}
switch ( V_11 ) {
case V_126 :
F_88 ( V_24 , & V_3 [ V_4 ] ,
V_117 ) ;
break;
case V_125 :
F_80 ( V_24 , & V_3 [ V_4 ] , V_117 ) ;
break;
#if F_47 ( V_52 )
case V_127 :
F_92 ( V_26 , V_3 , V_14 ) ;
break;
#endif
case V_128 :
if ( V_3 [ 4 ] == 0 ) {
if ( ! F_40 ( V_24 ) )
F_44 ( V_24 ) ;
} else if ( V_3 [ 4 ] == 1 ) {
if ( F_40 ( V_24 ) )
F_41 ( V_24 ) ;
}
break;
default:
F_36 ( V_24 , V_3 , V_14 ) ;
break;
}
}
static void F_93 ( void * V_45 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_45 ;
F_91 ( V_26 -> V_46 , V_15 , V_14 ) ;
F_94 ( V_26 , F_93 , V_26 ) ;
}
static void F_95 ( void * V_45 , void * V_15 , int V_14 )
{
struct V_26 * V_26 = V_45 ;
int V_47 ;
V_47 = F_78 ( V_26 -> V_46 , V_15 , V_14 ) ;
if ( V_47 == 1 ) {
F_94 ( V_26 , F_93 , V_26 ) ;
} else {
if ( V_47 < 0 )
F_37 ( V_26 -> V_46 ,
L_15 , V_47 ) ;
F_94 ( V_26 , F_95 , V_26 ) ;
}
}
static void F_96 ( struct V_26 * V_26 )
{
F_94 ( V_26 , F_95 , V_26 ) ;
}
int F_97 ( struct V_129 * V_129 , struct V_130 * V_131 )
{
struct V_26 * V_26 = NULL ;
struct V_23 * V_24 ;
int V_47 ;
V_24 = F_98 ( sizeof( * V_26 ) , L_2 , V_132 ,
V_133 ) ;
if ( ! V_24 ) {
F_32 ( L_16 ) ;
return - V_9 ;
}
F_99 ( V_24 , V_131 ) ;
V_24 -> V_134 = 1400 ;
V_24 -> V_135 = & V_136 ;
V_24 -> V_32 &= ~ V_137 ;
memcpy ( V_24 -> V_59 , V_138 , sizeof( V_138 ) ) ;
V_26 = F_19 ( V_24 ) ;
V_26 -> V_46 = V_24 ;
V_26 -> V_129 = V_129 ;
V_129 -> V_46 = V_24 ;
V_47 = F_27 () ;
if ( V_47 < 0 ) {
F_32 ( L_17 ) ;
goto V_139;
}
V_47 = F_100 ( V_24 ) ;
if ( V_47 )
goto V_139;
F_67 ( V_24 ) ;
#ifdef V_52
F_101 ( V_26 ) ;
#endif
F_96 ( V_26 ) ;
F_70 ( V_24 ) ;
return 0 ;
V_139:
F_32 ( L_18 ) ;
F_102 ( V_24 ) ;
return V_47 ;
}
void F_103 ( struct V_129 * V_129 )
{
struct V_26 * V_26 = F_19 ( V_129 -> V_46 ) ;
struct V_72 * V_73 = V_26 -> V_74 [ V_75 ] . V_3 ;
if ( V_73 )
V_73 -> V_76 = V_77 ;
F_104 ( V_26 -> V_46 ) ;
F_33 () ;
#if F_47 ( V_52 )
F_68 ( V_26 ) ;
#endif
F_63 ( V_129 -> V_46 ) ;
F_102 ( V_26 -> V_46 ) ;
}
