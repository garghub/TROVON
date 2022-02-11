static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (rawmidi, &snd_rawmidi_devices, list)
if ( V_5 -> V_3 == V_3 && V_5 -> V_4 == V_4 )
return V_5 ;
return NULL ;
}
static inline unsigned short F_3 ( struct V_6 * V_6 )
{
switch ( V_6 -> V_7 & ( V_8 | V_9 ) ) {
case V_9 :
return V_10 ;
case V_8 :
return V_11 ;
default:
return V_12 ;
}
}
static inline int F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
return V_16 -> V_17 >= V_16 -> V_18 ;
}
static inline int F_5 ( struct V_13 * V_14 ,
T_1 V_19 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
return V_16 -> V_17 >= V_16 -> V_18 &&
( ! V_14 -> V_20 || V_16 -> V_17 >= V_19 ) ;
}
static void F_6 ( struct V_21 * V_22 )
{
struct V_15 * V_16 =
F_7 ( V_22 , struct V_15 , V_23 ) ;
if ( V_16 -> V_24 )
V_16 -> V_24 ( V_16 -> V_14 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
if ( ( V_16 = F_9 ( sizeof( * V_16 ) , V_25 ) ) == NULL )
return - V_26 ;
V_16 -> V_14 = V_14 ;
F_10 ( & V_16 -> V_27 ) ;
F_11 ( & V_16 -> V_28 ) ;
F_12 ( & V_16 -> V_23 , F_6 ) ;
V_16 -> V_24 = NULL ;
V_16 -> V_29 = V_30 ;
V_16 -> V_18 = 1 ;
if ( V_14 -> V_31 == V_32 )
V_16 -> V_17 = 0 ;
else
V_16 -> V_17 = V_16 -> V_29 ;
if ( ( V_16 -> V_33 = F_13 ( V_16 -> V_29 , V_25 ) ) == NULL ) {
F_14 ( V_16 ) ;
return - V_26 ;
}
V_16 -> V_34 = V_16 -> V_35 = 0 ;
V_14 -> V_16 = V_16 ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
F_14 ( V_16 -> V_33 ) ;
F_14 ( V_16 ) ;
V_14 -> V_16 = NULL ;
return 0 ;
}
static inline void F_16 ( struct V_13 * V_14 , int V_36 )
{
if ( ! V_14 -> V_37 )
return;
V_14 -> V_38 -> V_39 ( V_14 , V_36 ) ;
}
static void F_17 ( struct V_13 * V_14 , int V_36 )
{
if ( ! V_14 -> V_37 )
return;
V_14 -> V_38 -> V_39 ( V_14 , V_36 ) ;
if ( ! V_36 )
F_18 ( & V_14 -> V_16 -> V_23 ) ;
}
int F_19 ( struct V_13 * V_14 )
{
unsigned long V_40 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_16 ( V_14 , 0 ) ;
V_16 -> V_41 = 0 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_16 -> V_34 = V_16 -> V_35 = 0 ;
V_16 -> V_17 = V_16 -> V_29 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return 0 ;
}
int F_22 ( struct V_13 * V_14 )
{
int V_42 ;
long V_43 ;
struct V_15 * V_16 = V_14 -> V_16 ;
V_42 = 0 ;
V_16 -> V_41 = 1 ;
V_43 = F_23 ( V_16 -> V_28 ,
( V_16 -> V_17 >= V_16 -> V_29 ) ,
10 * V_44 ) ;
if ( F_24 ( V_45 ) )
V_42 = - V_46 ;
if ( V_16 -> V_17 < V_16 -> V_29 && ! V_43 ) {
F_25 ( V_14 -> V_47 ,
L_1 ,
( long ) V_16 -> V_17 , ( long ) V_16 -> V_29 ) ;
V_42 = - V_48 ;
}
V_16 -> V_41 = 0 ;
if ( V_42 != - V_46 ) {
if ( V_14 -> V_38 -> V_41 )
V_14 -> V_38 -> V_41 ( V_14 ) ;
else
F_26 ( 50 ) ;
F_19 ( V_14 ) ;
}
return V_42 ;
}
int F_27 ( struct V_13 * V_14 )
{
unsigned long V_40 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_17 ( V_14 , 0 ) ;
V_16 -> V_41 = 0 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_16 -> V_34 = V_16 -> V_35 = 0 ;
V_16 -> V_17 = 0 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_47 , int V_49 ,
int V_31 , int V_50 ,
struct V_13 * * V_51 )
{
struct V_13 * V_14 ;
struct V_52 * V_53 = & V_47 -> V_54 [ V_31 ] ;
static unsigned int V_55 [ 2 ] = {
[ V_56 ] = V_57 ,
[ V_32 ] = V_58 ,
} ;
if ( ! ( V_47 -> V_55 & V_55 [ V_31 ] ) )
return - V_59 ;
if ( V_49 >= 0 && V_49 >= V_53 -> V_60 )
return - V_61 ;
F_2 (substream, &s->substreams, list) {
if ( V_14 -> V_37 ) {
if ( V_31 == V_32 ||
! ( V_50 & V_62 ) ||
! V_14 -> V_20 )
continue;
}
if ( V_49 < 0 || V_49 == V_14 -> V_63 ) {
* V_51 = V_14 ;
return 0 ;
}
}
return - V_64 ;
}
static int F_29 ( struct V_1 * V_47 ,
struct V_13 * V_14 ,
int V_50 )
{
int V_42 ;
if ( V_14 -> V_65 == 0 ) {
V_42 = F_8 ( V_14 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = V_14 -> V_38 -> V_66 ( V_14 ) ;
if ( V_42 < 0 ) {
F_15 ( V_14 ) ;
return V_42 ;
}
V_14 -> V_37 = 1 ;
V_14 -> V_67 = 0 ;
if ( V_50 & V_62 )
V_14 -> V_20 = 1 ;
V_14 -> V_68 = F_30 ( F_31 ( V_45 ) ) ;
V_47 -> V_54 [ V_14 -> V_31 ] . V_69 ++ ;
}
V_14 -> V_65 ++ ;
return 0 ;
}
static int F_32 ( struct V_1 * V_47 , int V_49 , int V_50 ,
struct V_70 * V_71 )
{
struct V_13 * V_72 = NULL , * V_73 = NULL ;
int V_42 ;
V_71 -> V_74 = V_71 -> V_75 = NULL ;
if ( V_50 & V_11 ) {
V_42 = F_28 ( V_47 , V_49 ,
V_32 ,
V_50 , & V_72 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_50 & V_10 ) {
V_42 = F_28 ( V_47 , V_49 ,
V_56 ,
V_50 , & V_73 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_72 ) {
V_42 = F_29 ( V_47 , V_72 , V_50 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_73 ) {
V_42 = F_29 ( V_47 , V_73 , V_50 ) ;
if ( V_42 < 0 ) {
if ( V_72 )
F_33 ( V_47 , V_72 , 0 ) ;
return V_42 ;
}
}
V_71 -> V_47 = V_47 ;
V_71 -> V_74 = V_72 ;
V_71 -> V_75 = V_73 ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 , int V_4 , int V_49 ,
int V_50 , struct V_70 * V_71 )
{
struct V_1 * V_47 ;
int V_42 ;
if ( F_35 ( ! V_71 ) )
return - V_76 ;
F_36 ( & V_77 ) ;
V_47 = F_1 ( V_3 , V_4 ) ;
if ( V_47 == NULL ) {
F_37 ( & V_77 ) ;
return - V_61 ;
}
if ( ! F_38 ( V_47 -> V_3 -> V_78 ) ) {
F_37 ( & V_77 ) ;
return - V_59 ;
}
F_37 ( & V_77 ) ;
F_36 ( & V_47 -> V_79 ) ;
V_42 = F_32 ( V_47 , V_49 , V_50 , V_71 ) ;
F_37 ( & V_47 -> V_79 ) ;
if ( V_42 < 0 )
F_39 ( V_47 -> V_3 -> V_78 ) ;
return V_42 ;
}
static int F_40 ( struct V_80 * V_80 , struct V_6 * V_6 )
{
int V_81 = F_41 ( V_80 ) ;
struct V_2 * V_3 ;
int V_49 ;
unsigned short V_82 ;
int V_42 ;
struct V_1 * V_47 ;
struct V_70 * V_83 = NULL ;
T_2 V_84 ;
if ( ( V_6 -> V_85 & V_86 ) && ! ( V_6 -> V_85 & V_87 ) )
return - V_76 ;
V_42 = F_42 ( V_80 , V_6 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_81 == V_88 ) {
V_47 = F_43 ( F_44 ( V_80 ) ,
V_89 ) ;
#ifdef F_45
} else if ( V_81 == V_90 ) {
V_47 = F_46 ( F_44 ( V_80 ) ,
V_91 ) ;
#endif
} else
return - V_59 ;
if ( V_47 == NULL )
return - V_61 ;
if ( ! F_38 ( V_47 -> V_3 -> V_78 ) ) {
F_47 ( V_47 -> V_3 ) ;
return - V_59 ;
}
F_36 ( & V_47 -> V_79 ) ;
V_3 = V_47 -> V_3 ;
V_42 = F_48 ( V_3 , V_6 ) ;
if ( V_42 < 0 )
goto V_92;
V_82 = F_3 ( V_6 ) ;
if ( ( V_6 -> V_85 & V_86 ) || V_81 == V_90 )
V_82 |= V_62 ;
V_83 = F_13 ( sizeof( * V_83 ) , V_25 ) ;
if ( V_83 == NULL ) {
V_42 = - V_26 ;
goto V_93;
}
F_49 ( & V_84 , V_45 ) ;
F_50 ( & V_47 -> V_94 , & V_84 ) ;
while ( 1 ) {
V_49 = F_51 ( V_3 , V_95 ) ;
V_42 = F_32 ( V_47 , V_49 , V_82 , V_83 ) ;
if ( V_42 >= 0 )
break;
if ( V_42 == - V_64 ) {
if ( V_6 -> V_85 & V_87 ) {
V_42 = - V_96 ;
break;
}
} else
break;
F_52 ( V_97 ) ;
F_37 ( & V_47 -> V_79 ) ;
F_53 () ;
F_36 ( & V_47 -> V_79 ) ;
if ( V_47 -> V_3 -> V_98 ) {
V_42 = - V_61 ;
break;
}
if ( F_24 ( V_45 ) ) {
V_42 = - V_46 ;
break;
}
}
F_54 ( & V_47 -> V_94 , & V_84 ) ;
if ( V_42 < 0 ) {
F_14 ( V_83 ) ;
goto V_93;
}
#ifdef F_45
if ( V_83 -> V_74 && V_83 -> V_74 -> V_16 )
V_83 -> V_74 -> V_16 -> V_99 = ( V_81 == V_90 ) ;
if ( V_83 -> V_75 && V_83 -> V_75 -> V_16 )
V_83 -> V_75 -> V_16 -> V_99 = ( V_81 == V_90 ) ;
#endif
V_6 -> V_100 = V_83 ;
F_37 ( & V_47 -> V_79 ) ;
F_47 ( V_47 -> V_3 ) ;
return 0 ;
V_93:
F_55 ( V_3 , V_6 ) ;
V_92:
F_37 ( & V_47 -> V_79 ) ;
F_39 ( V_47 -> V_3 -> V_78 ) ;
F_47 ( V_47 -> V_3 ) ;
return V_42 ;
}
static void F_33 ( struct V_1 * V_47 ,
struct V_13 * V_14 ,
int V_101 )
{
if ( -- V_14 -> V_65 )
return;
if ( V_101 ) {
if ( V_14 -> V_31 == V_32 )
F_17 ( V_14 , 0 ) ;
else {
if ( V_14 -> V_67 ) {
unsigned char V_102 = 0xfe ;
F_56 ( V_14 , & V_102 , 1 ) ;
}
if ( F_22 ( V_14 ) == - V_46 )
F_16 ( V_14 , 0 ) ;
}
}
V_14 -> V_38 -> V_103 ( V_14 ) ;
if ( V_14 -> V_16 -> V_104 )
V_14 -> V_16 -> V_104 ( V_14 ) ;
F_15 ( V_14 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_20 = 0 ;
F_57 ( V_14 -> V_68 ) ;
V_14 -> V_68 = NULL ;
V_47 -> V_54 [ V_14 -> V_31 ] . V_69 -- ;
}
static void F_58 ( struct V_70 * V_71 )
{
struct V_1 * V_47 ;
V_47 = V_71 -> V_47 ;
F_36 ( & V_47 -> V_79 ) ;
if ( V_71 -> V_74 ) {
F_33 ( V_47 , V_71 -> V_74 , 1 ) ;
V_71 -> V_74 = NULL ;
}
if ( V_71 -> V_75 ) {
F_33 ( V_47 , V_71 -> V_75 , 1 ) ;
V_71 -> V_75 = NULL ;
}
V_71 -> V_47 = NULL ;
F_37 ( & V_47 -> V_79 ) ;
F_59 ( & V_47 -> V_94 ) ;
}
int F_60 ( struct V_70 * V_71 )
{
struct V_1 * V_47 ;
if ( F_35 ( ! V_71 ) )
return - V_59 ;
V_47 = V_71 -> V_47 ;
F_58 ( V_71 ) ;
F_39 ( V_47 -> V_3 -> V_78 ) ;
return 0 ;
}
static int F_61 ( struct V_80 * V_80 , struct V_6 * V_6 )
{
struct V_70 * V_71 ;
struct V_1 * V_47 ;
struct V_78 * V_78 ;
V_71 = V_6 -> V_100 ;
V_47 = V_71 -> V_47 ;
F_58 ( V_71 ) ;
F_14 ( V_71 ) ;
V_78 = V_47 -> V_3 -> V_78 ;
F_55 ( V_47 -> V_3 , V_6 ) ;
F_39 ( V_78 ) ;
return 0 ;
}
static int F_62 ( struct V_13 * V_14 ,
struct F_62 * V_105 )
{
struct V_1 * V_47 ;
if ( V_14 == NULL )
return - V_61 ;
V_47 = V_14 -> V_47 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_3 = V_47 -> V_3 -> V_63 ;
V_105 -> V_4 = V_47 -> V_4 ;
V_105 -> V_49 = V_14 -> V_63 ;
V_105 -> V_31 = V_14 -> V_31 ;
V_105 -> V_40 = V_47 -> V_55 ;
strcpy ( V_105 -> V_106 , V_47 -> V_106 ) ;
strcpy ( V_105 -> V_107 , V_47 -> V_107 ) ;
strcpy ( V_105 -> V_108 , V_14 -> V_107 ) ;
V_105 -> V_109 = V_14 -> V_110 -> V_60 ;
V_105 -> V_111 = ( V_14 -> V_110 -> V_60 -
V_14 -> V_110 -> V_69 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 ,
struct F_62 T_3 * V_112 )
{
struct F_62 V_105 ;
int V_42 ;
if ( ( V_42 = F_62 ( V_14 , & V_105 ) ) < 0 )
return V_42 ;
if ( F_64 ( V_112 , & V_105 , sizeof( struct F_62 ) ) )
return - V_113 ;
return 0 ;
}
int F_65 ( struct V_2 * V_3 , struct F_62 * V_105 )
{
struct V_1 * V_47 ;
struct V_52 * V_110 ;
struct V_13 * V_14 ;
F_36 ( & V_77 ) ;
V_47 = F_1 ( V_3 , V_105 -> V_4 ) ;
F_37 ( & V_77 ) ;
if ( ! V_47 )
return - V_59 ;
if ( V_105 -> V_31 < 0 || V_105 -> V_31 > 1 )
return - V_76 ;
V_110 = & V_47 -> V_54 [ V_105 -> V_31 ] ;
if ( V_110 -> V_60 == 0 )
return - V_114 ;
if ( V_105 -> V_49 >= V_110 -> V_60 )
return - V_59 ;
F_2 (substream, &pstr->substreams, list) {
if ( ( unsigned int ) V_14 -> V_63 == V_105 -> V_49 )
return F_62 ( V_14 , V_105 ) ;
}
return - V_59 ;
}
static int F_66 ( struct V_2 * V_3 ,
struct F_62 T_3 * V_112 )
{
int V_42 ;
struct F_62 V_105 ;
if ( F_67 ( V_105 . V_4 , & V_112 -> V_4 ) )
return - V_113 ;
if ( F_67 ( V_105 . V_31 , & V_112 -> V_31 ) )
return - V_113 ;
if ( F_67 ( V_105 . V_49 , & V_112 -> V_49 ) )
return - V_113 ;
if ( ( V_42 = F_65 ( V_3 , & V_105 ) ) < 0 )
return V_42 ;
if ( F_64 ( V_112 , & V_105 , sizeof( struct F_62 ) ) )
return - V_113 ;
return 0 ;
}
int F_68 ( struct V_13 * V_14 ,
struct V_115 * V_116 )
{
char * V_117 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_14 -> V_65 > 1 )
return - V_96 ;
F_22 ( V_14 ) ;
if ( V_116 -> V_29 < 32 || V_116 -> V_29 > 1024L * 1024L ) {
return - V_76 ;
}
if ( V_116 -> V_18 < 1 || V_116 -> V_18 > V_116 -> V_29 ) {
return - V_76 ;
}
if ( V_116 -> V_29 != V_16 -> V_29 ) {
V_117 = F_69 ( V_16 -> V_33 , V_116 -> V_29 ,
V_25 ) ;
if ( ! V_117 )
return - V_26 ;
V_16 -> V_33 = V_117 ;
V_16 -> V_29 = V_116 -> V_29 ;
V_16 -> V_17 = V_16 -> V_29 ;
}
V_16 -> V_18 = V_116 -> V_18 ;
V_14 -> V_67 = ! V_116 -> V_118 ;
return 0 ;
}
int F_70 ( struct V_13 * V_14 ,
struct V_115 * V_116 )
{
char * V_117 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_27 ( V_14 ) ;
if ( V_116 -> V_29 < 32 || V_116 -> V_29 > 1024L * 1024L ) {
return - V_76 ;
}
if ( V_116 -> V_18 < 1 || V_116 -> V_18 > V_116 -> V_29 ) {
return - V_76 ;
}
if ( V_116 -> V_29 != V_16 -> V_29 ) {
V_117 = F_69 ( V_16 -> V_33 , V_116 -> V_29 ,
V_25 ) ;
if ( ! V_117 )
return - V_26 ;
V_16 -> V_33 = V_117 ;
V_16 -> V_29 = V_116 -> V_29 ;
}
V_16 -> V_18 = V_116 -> V_18 ;
return 0 ;
}
static int F_71 ( struct V_13 * V_14 ,
struct V_119 * V_120 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_31 = V_56 ;
F_72 ( & V_16 -> V_27 ) ;
V_120 -> V_17 = V_16 -> V_17 ;
F_73 ( & V_16 -> V_27 ) ;
return 0 ;
}
static int F_74 ( struct V_13 * V_14 ,
struct V_119 * V_120 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_31 = V_32 ;
F_72 ( & V_16 -> V_27 ) ;
V_120 -> V_17 = V_16 -> V_17 ;
V_120 -> V_121 = V_16 -> V_121 ;
V_16 -> V_121 = 0 ;
F_73 ( & V_16 -> V_27 ) ;
return 0 ;
}
static long F_75 ( struct V_6 * V_6 , unsigned int V_122 , unsigned long V_123 )
{
struct V_70 * V_71 ;
void T_3 * V_124 = ( void T_3 * ) V_123 ;
V_71 = V_6 -> V_100 ;
if ( ( ( V_122 >> 8 ) & 0xff ) != 'W' )
return - V_125 ;
switch ( V_122 ) {
case V_126 :
return F_76 ( V_127 , ( int T_3 * ) V_124 ) ? - V_113 : 0 ;
case V_128 :
{
int V_31 ;
struct F_62 T_3 * V_105 = V_124 ;
if ( F_67 ( V_31 , & V_105 -> V_31 ) )
return - V_113 ;
switch ( V_31 ) {
case V_32 :
return F_63 ( V_71 -> V_74 , V_105 ) ;
case V_56 :
return F_63 ( V_71 -> V_75 , V_105 ) ;
default:
return - V_76 ;
}
}
case V_129 :
{
struct V_115 V_116 ;
if ( F_77 ( & V_116 , V_124 , sizeof( struct V_115 ) ) )
return - V_113 ;
switch ( V_116 . V_31 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_68 ( V_71 -> V_75 , & V_116 ) ;
case V_32 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
return F_70 ( V_71 -> V_74 , & V_116 ) ;
default:
return - V_76 ;
}
}
case V_130 :
{
int V_42 = 0 ;
struct V_119 V_120 ;
if ( F_77 ( & V_120 , V_124 , sizeof( struct V_119 ) ) )
return - V_113 ;
switch ( V_120 . V_31 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
V_42 = F_71 ( V_71 -> V_75 , & V_120 ) ;
break;
case V_32 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
V_42 = F_74 ( V_71 -> V_74 , & V_120 ) ;
break;
default:
return - V_76 ;
}
if ( V_42 < 0 )
return V_42 ;
if ( F_64 ( V_124 , & V_120 , sizeof( struct V_119 ) ) )
return - V_113 ;
return 0 ;
}
case V_131 :
{
int V_132 ;
if ( F_67 ( V_132 , ( int T_3 * ) V_124 ) )
return - V_113 ;
switch ( V_132 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_19 ( V_71 -> V_75 ) ;
default:
return - V_76 ;
}
}
case V_133 :
{
int V_132 ;
if ( F_67 ( V_132 , ( int T_3 * ) V_124 ) )
return - V_113 ;
switch ( V_132 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_22 ( V_71 -> V_75 ) ;
case V_32 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
return F_27 ( V_71 -> V_74 ) ;
default:
return - V_76 ;
}
}
default:
F_78 ( V_71 -> V_47 ,
L_2 , V_122 ) ;
}
return - V_125 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_134 * V_135 ,
unsigned int V_122 ,
unsigned long V_123 )
{
void T_3 * V_124 = ( void T_3 * ) V_123 ;
switch ( V_122 ) {
case V_136 :
{
int V_4 ;
if ( F_67 ( V_4 , ( int T_3 * ) V_124 ) )
return - V_113 ;
if ( V_4 >= V_137 )
V_4 = V_137 - 1 ;
F_36 ( & V_77 ) ;
V_4 = V_4 < 0 ? 0 : V_4 + 1 ;
while ( V_4 < V_137 ) {
if ( F_1 ( V_3 , V_4 ) )
break;
V_4 ++ ;
}
if ( V_4 == V_137 )
V_4 = - 1 ;
F_37 ( & V_77 ) ;
if ( F_76 ( V_4 , ( int T_3 * ) V_124 ) )
return - V_113 ;
return 0 ;
}
case V_138 :
{
int V_132 ;
if ( F_67 ( V_132 , ( int T_3 * ) V_124 ) )
return - V_113 ;
V_135 -> V_139 [ V_95 ] = V_132 ;
return 0 ;
}
case V_140 :
return F_66 ( V_3 , V_124 ) ;
}
return - V_141 ;
}
int F_80 ( struct V_13 * V_14 ,
const unsigned char * V_33 , int V_19 )
{
unsigned long V_40 ;
int V_142 = 0 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_37 )
return - V_144 ;
if ( V_16 -> V_33 == NULL ) {
F_78 ( V_14 -> V_47 ,
L_3 ) ;
return - V_76 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_19 == 1 ) {
V_14 -> V_145 ++ ;
if ( V_16 -> V_17 < V_16 -> V_29 ) {
V_16 -> V_33 [ V_16 -> V_35 ++ ] = V_33 [ 0 ] ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 ++ ;
V_142 ++ ;
} else {
V_16 -> V_121 ++ ;
}
} else {
V_14 -> V_145 += V_19 ;
V_143 = V_16 -> V_29 - V_16 -> V_35 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) )
V_143 = V_16 -> V_29 - V_16 -> V_17 ;
memcpy ( V_16 -> V_33 + V_16 -> V_35 , V_33 , V_143 ) ;
V_16 -> V_35 += V_143 ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 += V_143 ;
V_19 -= V_143 ;
V_142 += V_143 ;
if ( V_19 > 0 ) {
V_33 += V_143 ;
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) ) {
V_143 = V_16 -> V_29 - V_16 -> V_17 ;
V_16 -> V_121 += V_19 - V_143 ;
}
if ( V_143 > 0 ) {
memcpy ( V_16 -> V_33 , V_33 , V_143 ) ;
V_16 -> V_35 = V_143 ;
V_16 -> V_17 += V_143 ;
V_142 += V_143 ;
}
}
}
if ( V_142 > 0 ) {
if ( V_16 -> V_24 )
F_81 ( & V_16 -> V_23 ) ;
else if ( F_4 ( V_14 ) )
F_59 ( & V_16 -> V_28 ) ;
}
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
static long F_82 ( struct V_13 * V_14 ,
unsigned char T_3 * V_146 ,
unsigned char * V_147 , long V_19 )
{
unsigned long V_40 ;
long V_142 = 0 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
unsigned long V_34 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
while ( V_19 > 0 && V_16 -> V_17 ) {
V_143 = V_16 -> V_29 - V_16 -> V_34 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( int ) V_16 -> V_17 )
V_143 = V_16 -> V_17 ;
V_34 = V_16 -> V_34 ;
V_16 -> V_34 += V_143 ;
V_16 -> V_34 %= V_16 -> V_29 ;
V_16 -> V_17 -= V_143 ;
if ( V_147 )
memcpy ( V_147 + V_142 , V_16 -> V_33 + V_34 , V_143 ) ;
if ( V_146 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( F_64 ( V_146 + V_142 ,
V_16 -> V_33 + V_34 , V_143 ) ) {
return V_142 > 0 ? V_142 : - V_113 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
}
V_142 += V_143 ;
V_19 -= V_143 ;
}
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
long F_83 ( struct V_13 * V_14 ,
unsigned char * V_102 , long V_19 )
{
F_17 ( V_14 , 1 ) ;
return F_82 ( V_14 , NULL , V_102 , V_19 ) ;
}
static T_4 F_84 ( struct V_6 * V_6 , char T_3 * V_102 , T_1 V_19 ,
T_5 * V_148 )
{
long V_142 ;
int V_143 ;
struct V_70 * V_71 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_71 = V_6 -> V_100 ;
V_14 = V_71 -> V_74 ;
if ( V_14 == NULL )
return - V_48 ;
V_16 = V_14 -> V_16 ;
F_17 ( V_14 , 1 ) ;
V_142 = 0 ;
while ( V_19 > 0 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( ! F_4 ( V_14 ) ) {
T_2 V_84 ;
if ( ( V_6 -> V_85 & V_87 ) != 0 || V_142 > 0 ) {
F_73 ( & V_16 -> V_27 ) ;
return V_142 > 0 ? V_142 : - V_64 ;
}
F_49 ( & V_84 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_52 ( V_97 ) ;
F_73 ( & V_16 -> V_27 ) ;
F_53 () ;
F_54 ( & V_16 -> V_28 , & V_84 ) ;
if ( V_71 -> V_47 -> V_3 -> V_98 )
return - V_61 ;
if ( F_24 ( V_45 ) )
return V_142 > 0 ? V_142 : - V_46 ;
if ( ! V_16 -> V_17 )
return V_142 > 0 ? V_142 : - V_48 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
V_143 = F_82 ( V_14 ,
( unsigned char T_3 * ) V_102 ,
NULL ,
V_19 ) ;
if ( V_143 < 0 )
return V_142 > 0 ? V_142 : V_143 ;
V_142 += V_143 ;
V_102 += V_143 ;
V_19 -= V_143 ;
}
return V_142 ;
}
int F_85 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_142 ;
unsigned long V_40 ;
if ( V_16 -> V_33 == NULL ) {
F_78 ( V_14 -> V_47 ,
L_4 ) ;
return 1 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_142 = V_16 -> V_17 >= V_16 -> V_29 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
int F_86 ( struct V_13 * V_14 ,
unsigned char * V_33 , int V_19 )
{
int V_142 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_33 == NULL ) {
F_78 ( V_14 -> V_47 ,
L_5 ) ;
return - V_76 ;
}
V_142 = 0 ;
if ( V_16 -> V_17 >= V_16 -> V_29 ) {
goto V_149;
}
if ( V_19 == 1 ) {
* V_33 = V_16 -> V_33 [ V_16 -> V_35 ] ;
V_142 ++ ;
} else {
V_143 = V_16 -> V_29 - V_16 -> V_35 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) )
V_143 = V_16 -> V_29 - V_16 -> V_17 ;
memcpy ( V_33 , V_16 -> V_33 + V_16 -> V_35 , V_143 ) ;
V_19 -= V_143 ;
V_142 += V_143 ;
if ( V_19 > 0 ) {
if ( V_19 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 - V_143 ) )
V_19 = V_16 -> V_29 - V_16 -> V_17 - V_143 ;
memcpy ( V_33 + V_143 , V_16 -> V_33 , V_19 ) ;
V_142 += V_19 ;
}
}
V_149:
return V_142 ;
}
int F_87 ( struct V_13 * V_14 ,
unsigned char * V_33 , int V_19 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_142 ;
unsigned long V_40 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_142 = F_86 ( V_14 , V_33 , V_19 ) ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
int F_88 ( struct V_13 * V_14 , int V_19 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_33 == NULL ) {
F_78 ( V_14 -> V_47 ,
L_6 ) ;
return - V_76 ;
}
F_35 ( V_16 -> V_17 + V_19 > V_16 -> V_29 ) ;
V_16 -> V_35 += V_19 ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 += V_19 ;
V_14 -> V_145 += V_19 ;
if ( V_19 > 0 ) {
if ( V_16 -> V_41 || F_4 ( V_14 ) )
F_59 ( & V_16 -> V_28 ) ;
}
return V_19 ;
}
int F_89 ( struct V_13 * V_14 , int V_19 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_142 ;
unsigned long V_40 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_142 = F_88 ( V_14 , V_19 ) ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
int F_90 ( struct V_13 * V_14 ,
unsigned char * V_33 , int V_19 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_142 ;
unsigned long V_40 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( ! V_14 -> V_37 )
V_142 = - V_144 ;
else {
V_19 = F_86 ( V_14 , V_33 , V_19 ) ;
if ( V_19 <= 0 )
V_142 = V_19 ;
else
V_142 = F_88 ( V_14 , V_19 ) ;
}
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_142 ;
}
static long F_91 ( struct V_13 * V_14 ,
const unsigned char T_3 * V_146 ,
const unsigned char * V_147 ,
long V_19 )
{
unsigned long V_40 ;
long V_143 , V_142 ;
struct V_15 * V_16 = V_14 -> V_16 ;
unsigned long V_34 ;
if ( ! V_147 && ! V_146 )
return - V_76 ;
if ( F_35 ( ! V_16 -> V_33 ) )
return - V_76 ;
V_142 = 0 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_14 -> V_20 ) {
if ( ( long ) V_16 -> V_17 < V_19 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
return - V_64 ;
}
}
while ( V_19 > 0 && V_16 -> V_17 > 0 ) {
V_143 = V_16 -> V_29 - V_16 -> V_34 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( long ) V_16 -> V_17 )
V_143 = V_16 -> V_17 ;
V_34 = V_16 -> V_34 ;
V_16 -> V_34 += V_143 ;
V_16 -> V_34 %= V_16 -> V_29 ;
V_16 -> V_17 -= V_143 ;
if ( V_147 )
memcpy ( V_16 -> V_33 + V_34 ,
V_147 + V_142 , V_143 ) ;
else if ( V_146 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( F_77 ( V_16 -> V_33 + V_34 ,
V_146 + V_142 , V_143 ) ) {
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_142 = V_142 > 0 ? V_142 : - V_113 ;
goto V_150;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
}
V_142 += V_143 ;
V_19 -= V_143 ;
}
V_150:
V_143 = V_16 -> V_17 < V_16 -> V_29 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( V_143 )
F_16 ( V_14 , 1 ) ;
return V_142 ;
}
long F_56 ( struct V_13 * V_14 ,
const unsigned char * V_102 , long V_19 )
{
return F_91 ( V_14 , NULL , V_102 , V_19 ) ;
}
static T_4 F_92 ( struct V_6 * V_6 , const char T_3 * V_102 ,
T_1 V_19 , T_5 * V_148 )
{
long V_142 , V_43 ;
int V_143 ;
struct V_70 * V_71 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
V_71 = V_6 -> V_100 ;
V_14 = V_71 -> V_75 ;
V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_19 > V_16 -> V_29 )
return - V_48 ;
V_142 = 0 ;
while ( V_19 > 0 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( ! F_5 ( V_14 , V_19 ) ) {
T_2 V_84 ;
if ( V_6 -> V_85 & V_87 ) {
F_73 ( & V_16 -> V_27 ) ;
return V_142 > 0 ? V_142 : - V_64 ;
}
F_49 ( & V_84 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_52 ( V_97 ) ;
F_73 ( & V_16 -> V_27 ) ;
V_43 = F_93 ( 30 * V_44 ) ;
F_54 ( & V_16 -> V_28 , & V_84 ) ;
if ( V_71 -> V_47 -> V_3 -> V_98 )
return - V_61 ;
if ( F_24 ( V_45 ) )
return V_142 > 0 ? V_142 : - V_46 ;
if ( ! V_16 -> V_17 && ! V_43 )
return V_142 > 0 ? V_142 : - V_48 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
V_143 = F_91 ( V_14 , V_102 , NULL , V_19 ) ;
if ( V_143 < 0 )
return V_142 > 0 ? V_142 : V_143 ;
V_142 += V_143 ;
V_102 += V_143 ;
if ( ( T_1 ) V_143 < V_19 && ( V_6 -> V_85 & V_87 ) )
break;
V_19 -= V_143 ;
}
if ( V_6 -> V_85 & V_151 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( V_16 -> V_17 != V_16 -> V_29 ) {
T_2 V_84 ;
unsigned int V_152 = V_16 -> V_17 ;
F_49 ( & V_84 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_52 ( V_97 ) ;
F_73 ( & V_16 -> V_27 ) ;
V_43 = F_93 ( 30 * V_44 ) ;
F_54 ( & V_16 -> V_28 , & V_84 ) ;
if ( F_24 ( V_45 ) )
return V_142 > 0 ? V_142 : - V_46 ;
if ( V_16 -> V_17 == V_152 && ! V_43 )
return V_142 > 0 ? V_142 : - V_48 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
}
return V_142 ;
}
static unsigned int F_94 ( struct V_6 * V_6 , T_6 * V_84 )
{
struct V_70 * V_71 ;
struct V_15 * V_16 ;
unsigned int V_153 ;
V_71 = V_6 -> V_100 ;
if ( V_71 -> V_74 != NULL ) {
V_16 = V_71 -> V_74 -> V_16 ;
F_17 ( V_71 -> V_74 , 1 ) ;
F_95 ( V_6 , & V_16 -> V_28 , V_84 ) ;
}
if ( V_71 -> V_75 != NULL ) {
V_16 = V_71 -> V_75 -> V_16 ;
F_95 ( V_6 , & V_16 -> V_28 , V_84 ) ;
}
V_153 = 0 ;
if ( V_71 -> V_74 != NULL ) {
if ( F_4 ( V_71 -> V_74 ) )
V_153 |= V_154 | V_155 ;
}
if ( V_71 -> V_75 != NULL ) {
if ( F_4 ( V_71 -> V_75 ) )
V_153 |= V_156 | V_157 ;
}
return V_153 ;
}
static void F_96 ( struct V_158 * V_159 ,
struct V_160 * V_33 )
{
struct V_1 * V_47 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_47 = V_159 -> V_100 ;
F_97 ( V_33 , L_7 , V_47 -> V_107 ) ;
F_36 ( & V_47 -> V_79 ) ;
if ( V_47 -> V_55 & V_57 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams,
list) {
F_97 ( V_33 ,
L_8
L_9 ,
V_14 -> V_63 ,
( unsigned long ) V_14 -> V_145 ) ;
if ( V_14 -> V_37 ) {
F_97 ( V_33 ,
L_10 ,
F_98 ( V_14 -> V_68 ) ) ;
V_16 = V_14 -> V_16 ;
F_97 ( V_33 ,
L_11
L_12
L_13 ,
V_16 -> V_99 ? L_14 : L_15 ,
( unsigned long ) V_16 -> V_29 ,
( unsigned long ) V_16 -> V_17 ) ;
}
}
}
if ( V_47 -> V_55 & V_58 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams,
list) {
F_97 ( V_33 ,
L_16
L_17 ,
V_14 -> V_63 ,
( unsigned long ) V_14 -> V_145 ) ;
if ( V_14 -> V_37 ) {
F_97 ( V_33 ,
L_10 ,
F_98 ( V_14 -> V_68 ) ) ;
V_16 = V_14 -> V_16 ;
F_97 ( V_33 ,
L_12
L_13
L_18 ,
( unsigned long ) V_16 -> V_29 ,
( unsigned long ) V_16 -> V_17 ,
( unsigned long ) V_16 -> V_121 ) ;
}
}
}
F_37 ( & V_47 -> V_79 ) ;
}
static int F_99 ( struct V_1 * V_47 ,
struct V_52 * V_31 ,
int V_161 ,
int V_19 )
{
struct V_13 * V_14 ;
int V_162 ;
for ( V_162 = 0 ; V_162 < V_19 ; V_162 ++ ) {
V_14 = F_9 ( sizeof( * V_14 ) , V_25 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_31 = V_161 ;
V_14 -> V_63 = V_162 ;
V_14 -> V_47 = V_47 ;
V_14 -> V_110 = V_31 ;
F_100 ( & V_14 -> V_163 , & V_31 -> V_164 ) ;
V_31 -> V_60 ++ ;
}
return 0 ;
}
static void F_101 ( struct V_4 * V_165 )
{
F_14 ( F_7 ( V_165 , struct V_1 , V_165 ) ) ;
}
int F_102 ( struct V_2 * V_3 , char * V_106 , int V_4 ,
int V_166 , int V_167 ,
struct V_1 * * V_168 )
{
struct V_1 * V_47 ;
int V_42 ;
static struct V_169 V_38 = {
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
} ;
if ( F_35 ( ! V_3 ) )
return - V_59 ;
if ( V_168 )
* V_168 = NULL ;
V_47 = F_9 ( sizeof( * V_47 ) , V_25 ) ;
if ( ! V_47 )
return - V_26 ;
V_47 -> V_3 = V_3 ;
V_47 -> V_4 = V_4 ;
F_103 ( & V_47 -> V_79 ) ;
F_11 ( & V_47 -> V_94 ) ;
F_104 ( & V_47 -> V_54 [ V_32 ] . V_164 ) ;
F_104 ( & V_47 -> V_54 [ V_56 ] . V_164 ) ;
if ( V_106 != NULL )
F_105 ( V_47 -> V_106 , V_106 , sizeof( V_47 -> V_106 ) ) ;
F_106 ( & V_47 -> V_165 , V_3 ) ;
V_47 -> V_165 . V_176 = F_101 ;
F_107 ( & V_47 -> V_165 , L_19 , V_3 -> V_63 , V_4 ) ;
if ( ( V_42 = F_99 ( V_47 ,
& V_47 -> V_54 [ V_32 ] ,
V_32 ,
V_167 ) ) < 0 ) {
F_108 ( V_47 ) ;
return V_42 ;
}
if ( ( V_42 = F_99 ( V_47 ,
& V_47 -> V_54 [ V_56 ] ,
V_56 ,
V_166 ) ) < 0 ) {
F_108 ( V_47 ) ;
return V_42 ;
}
if ( ( V_42 = F_109 ( V_3 , V_177 , V_47 , & V_38 ) ) < 0 ) {
F_108 ( V_47 ) ;
return V_42 ;
}
if ( V_168 )
* V_168 = V_47 ;
return 0 ;
}
static void F_110 ( struct V_52 * V_31 )
{
struct V_13 * V_14 ;
while ( ! F_111 ( & V_31 -> V_164 ) ) {
V_14 = F_112 ( V_31 -> V_164 . V_178 , struct V_13 , V_163 ) ;
F_113 ( & V_14 -> V_163 ) ;
F_14 ( V_14 ) ;
}
}
static int F_108 ( struct V_1 * V_47 )
{
if ( ! V_47 )
return 0 ;
F_114 ( V_47 -> V_179 ) ;
V_47 -> V_179 = NULL ;
F_36 ( & V_77 ) ;
if ( V_47 -> V_38 && V_47 -> V_38 -> V_180 )
V_47 -> V_38 -> V_180 ( V_47 ) ;
F_37 ( & V_77 ) ;
F_110 ( & V_47 -> V_54 [ V_32 ] ) ;
F_110 ( & V_47 -> V_54 [ V_56 ] ) ;
if ( V_47 -> V_104 )
V_47 -> V_104 ( V_47 ) ;
F_115 ( & V_47 -> V_165 ) ;
return 0 ;
}
static int V_171 ( struct V_181 * V_4 )
{
struct V_1 * V_47 = V_4 -> V_182 ;
return F_108 ( V_47 ) ;
}
static void F_116 ( struct V_183 * V_4 )
{
struct V_1 * V_47 = V_4 -> V_100 ;
V_47 -> V_184 = NULL ;
}
static int V_173 ( struct V_181 * V_4 )
{
int V_42 ;
struct V_158 * V_159 ;
char V_107 [ 16 ] ;
struct V_1 * V_47 = V_4 -> V_182 ;
if ( V_47 -> V_4 >= V_137 )
return - V_26 ;
F_36 ( & V_77 ) ;
if ( F_1 ( V_47 -> V_3 , V_47 -> V_4 ) ) {
F_37 ( & V_77 ) ;
return - V_96 ;
}
F_100 ( & V_47 -> V_163 , & V_185 ) ;
F_37 ( & V_77 ) ;
V_42 = F_117 ( V_89 ,
V_47 -> V_3 , V_47 -> V_4 ,
& V_186 , V_47 , & V_47 -> V_165 ) ;
if ( V_42 < 0 ) {
F_118 ( V_47 , L_20 ) ;
F_36 ( & V_77 ) ;
F_113 ( & V_47 -> V_163 ) ;
F_37 ( & V_77 ) ;
return V_42 ;
}
if ( V_47 -> V_38 && V_47 -> V_38 -> V_172 &&
( V_42 = V_47 -> V_38 -> V_172 ( V_47 ) ) < 0 ) {
F_119 ( & V_47 -> V_165 ) ;
F_36 ( & V_77 ) ;
F_113 ( & V_47 -> V_163 ) ;
F_37 ( & V_77 ) ;
return V_42 ;
}
#ifdef F_45
V_47 -> V_187 = 0 ;
if ( ( int ) V_47 -> V_4 == V_188 [ V_47 -> V_3 -> V_63 ] ) {
if ( F_120 ( V_91 ,
V_47 -> V_3 , 0 , & V_186 ,
V_47 ) < 0 ) {
F_118 ( V_47 ,
L_21 ,
V_47 -> V_3 -> V_63 , 0 ) ;
} else {
V_47 -> V_187 ++ ;
#ifdef F_121
F_122 ( F_121 , V_47 -> V_3 -> V_63 , V_47 -> V_107 ) ;
#endif
}
}
if ( ( int ) V_47 -> V_4 == V_189 [ V_47 -> V_3 -> V_63 ] ) {
if ( F_120 ( V_91 ,
V_47 -> V_3 , 1 , & V_186 ,
V_47 ) < 0 ) {
F_118 ( V_47 ,
L_21 ,
V_47 -> V_3 -> V_63 , 1 ) ;
} else {
V_47 -> V_187 ++ ;
}
}
#endif
sprintf ( V_107 , L_22 , V_47 -> V_4 ) ;
V_159 = F_123 ( V_47 -> V_3 , V_107 , V_47 -> V_3 -> V_190 ) ;
if ( V_159 ) {
V_159 -> V_100 = V_47 ;
V_159 -> V_191 . V_192 . V_193 = F_96 ;
if ( F_124 ( V_159 ) < 0 ) {
F_114 ( V_159 ) ;
V_159 = NULL ;
}
}
V_47 -> V_179 = V_159 ;
#if F_125 ( V_194 ) || ( F_125 ( V_195 ) && F_125 ( V_196 ) )
if ( ! V_47 -> V_38 || ! V_47 -> V_38 -> V_172 ) {
if ( F_126 ( V_47 -> V_3 , V_47 -> V_4 , V_197 , 0 , & V_47 -> V_184 ) >= 0 ) {
V_47 -> V_184 -> V_100 = V_47 ;
V_47 -> V_184 -> V_104 = F_116 ;
sprintf ( V_47 -> V_184 -> V_107 , L_23 , V_47 -> V_3 -> V_63 , V_47 -> V_4 ) ;
F_127 ( V_47 -> V_3 , V_47 -> V_184 ) ;
}
}
#endif
return 0 ;
}
static int V_175 ( struct V_181 * V_4 )
{
struct V_1 * V_47 = V_4 -> V_182 ;
int V_198 ;
F_36 ( & V_77 ) ;
F_36 ( & V_47 -> V_79 ) ;
F_59 ( & V_47 -> V_94 ) ;
F_128 ( & V_47 -> V_163 ) ;
for ( V_198 = 0 ; V_198 < 2 ; V_198 ++ ) {
struct V_13 * V_53 ;
F_2 (s, &rmidi->streams[dir].substreams, list) {
if ( V_53 -> V_16 )
F_59 ( & V_53 -> V_16 -> V_28 ) ;
}
}
#ifdef F_45
if ( V_47 -> V_187 ) {
if ( ( int ) V_47 -> V_4 == V_188 [ V_47 -> V_3 -> V_63 ] ) {
F_129 ( V_91 , V_47 -> V_3 , 0 ) ;
#ifdef F_121
F_130 ( F_121 , V_47 -> V_3 -> V_63 ) ;
#endif
}
if ( ( int ) V_47 -> V_4 == V_189 [ V_47 -> V_3 -> V_63 ] )
F_129 ( V_91 , V_47 -> V_3 , 1 ) ;
V_47 -> V_187 = 0 ;
}
#endif
F_119 ( & V_47 -> V_165 ) ;
F_37 ( & V_47 -> V_79 ) ;
F_37 ( & V_77 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_47 , int V_31 ,
struct V_199 * V_38 )
{
struct V_13 * V_14 ;
F_2 (substream, &rmidi->streams[stream].substreams, list)
V_14 -> V_38 = V_38 ;
}
static int T_7 F_132 ( void )
{
F_133 ( F_79 ) ;
F_134 ( F_79 ) ;
#ifdef F_45
{ int V_200 ;
for ( V_200 = 0 ; V_200 < V_201 ; V_200 ++ ) {
if ( V_188 [ V_200 ] < 0 || V_188 [ V_200 ] >= V_137 ) {
F_135 ( L_24 ,
V_200 , V_188 [ V_200 ] ) ;
V_188 [ V_200 ] = 0 ;
}
if ( V_189 [ V_200 ] < 0 || V_189 [ V_200 ] >= V_137 ) {
F_135 ( L_25 ,
V_200 , V_189 [ V_200 ] ) ;
V_189 [ V_200 ] = 1 ;
}
}
}
#endif
return 0 ;
}
static void T_8 F_136 ( void )
{
F_137 ( F_79 ) ;
F_138 ( F_79 ) ;
}
