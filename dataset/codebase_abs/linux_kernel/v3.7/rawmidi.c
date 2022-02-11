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
F_25 ( V_47 L_1 , ( long ) V_16 -> V_17 , ( long ) V_16 -> V_29 ) ;
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
static int F_28 ( struct V_1 * V_49 , int V_50 ,
int V_31 , int V_51 ,
struct V_13 * * V_52 )
{
struct V_13 * V_14 ;
struct V_53 * V_54 = & V_49 -> V_55 [ V_31 ] ;
static unsigned int V_56 [ 2 ] = {
[ V_57 ] = V_58 ,
[ V_32 ] = V_59 ,
} ;
if ( ! ( V_49 -> V_56 & V_56 [ V_31 ] ) )
return - V_60 ;
if ( V_50 >= 0 && V_50 >= V_54 -> V_61 )
return - V_62 ;
F_2 (substream, &s->substreams, list) {
if ( V_14 -> V_37 ) {
if ( V_31 == V_32 ||
! ( V_51 & V_63 ) ||
! V_14 -> V_20 )
continue;
}
if ( V_50 < 0 || V_50 == V_14 -> V_64 ) {
* V_52 = V_14 ;
return 0 ;
}
}
return - V_65 ;
}
static int F_29 ( struct V_1 * V_49 ,
struct V_13 * V_14 ,
int V_51 )
{
int V_42 ;
if ( V_14 -> V_66 == 0 ) {
V_42 = F_8 ( V_14 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = V_14 -> V_38 -> V_67 ( V_14 ) ;
if ( V_42 < 0 ) {
F_15 ( V_14 ) ;
return V_42 ;
}
V_14 -> V_37 = 1 ;
V_14 -> V_68 = 0 ;
if ( V_51 & V_63 )
V_14 -> V_20 = 1 ;
V_14 -> V_69 = F_30 ( F_31 ( V_45 ) ) ;
V_49 -> V_55 [ V_14 -> V_31 ] . V_70 ++ ;
}
V_14 -> V_66 ++ ;
return 0 ;
}
static int F_32 ( struct V_1 * V_49 , int V_50 , int V_51 ,
struct V_71 * V_72 )
{
struct V_13 * V_73 = NULL , * V_74 = NULL ;
int V_42 ;
V_72 -> V_75 = V_72 -> V_76 = NULL ;
if ( V_51 & V_11 ) {
V_42 = F_28 ( V_49 , V_50 ,
V_32 ,
V_51 , & V_73 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_51 & V_10 ) {
V_42 = F_28 ( V_49 , V_50 ,
V_57 ,
V_51 , & V_74 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_73 ) {
V_42 = F_29 ( V_49 , V_73 , V_51 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_74 ) {
V_42 = F_29 ( V_49 , V_74 , V_51 ) ;
if ( V_42 < 0 ) {
if ( V_73 )
F_33 ( V_49 , V_73 , 0 ) ;
return V_42 ;
}
}
V_72 -> V_49 = V_49 ;
V_72 -> V_75 = V_73 ;
V_72 -> V_76 = V_74 ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 , int V_4 , int V_50 ,
int V_51 , struct V_71 * V_72 )
{
struct V_1 * V_49 ;
int V_42 ;
if ( F_35 ( ! V_72 ) )
return - V_77 ;
F_36 ( & V_78 ) ;
V_49 = F_1 ( V_3 , V_4 ) ;
if ( V_49 == NULL ) {
F_37 ( & V_78 ) ;
return - V_62 ;
}
if ( ! F_38 ( V_49 -> V_3 -> V_79 ) ) {
F_37 ( & V_78 ) ;
return - V_60 ;
}
F_37 ( & V_78 ) ;
F_36 ( & V_49 -> V_80 ) ;
V_42 = F_32 ( V_49 , V_50 , V_51 , V_72 ) ;
F_37 ( & V_49 -> V_80 ) ;
if ( V_42 < 0 )
F_39 ( V_49 -> V_3 -> V_79 ) ;
return V_42 ;
}
static int F_40 ( struct V_81 * V_81 , struct V_6 * V_6 )
{
int V_82 = F_41 ( V_81 ) ;
struct V_2 * V_3 ;
int V_50 ;
unsigned short V_83 ;
int V_42 ;
struct V_1 * V_49 ;
struct V_71 * V_84 = NULL ;
T_2 V_85 ;
struct V_86 * V_87 ;
if ( ( V_6 -> V_88 & V_89 ) && ! ( V_6 -> V_88 & V_90 ) )
return - V_77 ;
V_42 = F_42 ( V_81 , V_6 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_82 == V_91 ) {
V_49 = F_43 ( F_44 ( V_81 ) ,
V_92 ) ;
#ifdef F_45
} else if ( V_82 == V_93 ) {
V_49 = F_46 ( F_44 ( V_81 ) ,
V_94 ) ;
#endif
} else
return - V_60 ;
if ( V_49 == NULL )
return - V_62 ;
if ( ! F_38 ( V_49 -> V_3 -> V_79 ) ) {
F_47 ( V_49 -> V_3 ) ;
return - V_60 ;
}
F_36 ( & V_49 -> V_80 ) ;
V_3 = V_49 -> V_3 ;
V_42 = F_48 ( V_3 , V_6 ) ;
if ( V_42 < 0 )
goto V_95;
V_83 = F_3 ( V_6 ) ;
if ( ( V_6 -> V_88 & V_89 ) || V_82 == V_93 )
V_83 |= V_63 ;
V_84 = F_13 ( sizeof( * V_84 ) , V_25 ) ;
if ( V_84 == NULL ) {
V_42 = - V_26 ;
goto V_96;
}
F_49 ( & V_85 , V_45 ) ;
F_50 ( & V_49 -> V_97 , & V_85 ) ;
while ( 1 ) {
V_50 = - 1 ;
F_51 ( & V_3 -> V_98 ) ;
F_2 (kctl, &card->ctl_files, list) {
if ( V_87 -> V_69 == F_31 ( V_45 ) ) {
V_50 = V_87 -> V_99 ;
if ( V_50 != - 1 )
break;
}
}
F_52 ( & V_3 -> V_98 ) ;
V_42 = F_32 ( V_49 , V_50 , V_83 , V_84 ) ;
if ( V_42 >= 0 )
break;
if ( V_42 == - V_65 ) {
if ( V_6 -> V_88 & V_90 ) {
V_42 = - V_100 ;
break;
}
} else
break;
F_53 ( V_101 ) ;
F_37 ( & V_49 -> V_80 ) ;
F_54 () ;
F_36 ( & V_49 -> V_80 ) ;
if ( V_49 -> V_3 -> V_102 ) {
V_42 = - V_62 ;
break;
}
if ( F_24 ( V_45 ) ) {
V_42 = - V_46 ;
break;
}
}
F_55 ( & V_49 -> V_97 , & V_85 ) ;
if ( V_42 < 0 ) {
F_14 ( V_84 ) ;
goto V_96;
}
#ifdef F_45
if ( V_84 -> V_75 && V_84 -> V_75 -> V_16 )
V_84 -> V_75 -> V_16 -> V_103 = ( V_82 == V_93 ) ;
if ( V_84 -> V_76 && V_84 -> V_76 -> V_16 )
V_84 -> V_76 -> V_16 -> V_103 = ( V_82 == V_93 ) ;
#endif
V_6 -> V_104 = V_84 ;
F_37 ( & V_49 -> V_80 ) ;
F_47 ( V_49 -> V_3 ) ;
return 0 ;
V_96:
F_56 ( V_3 , V_6 ) ;
V_95:
F_37 ( & V_49 -> V_80 ) ;
F_39 ( V_49 -> V_3 -> V_79 ) ;
F_47 ( V_49 -> V_3 ) ;
return V_42 ;
}
static void F_33 ( struct V_1 * V_49 ,
struct V_13 * V_14 ,
int V_105 )
{
if ( -- V_14 -> V_66 )
return;
if ( V_105 ) {
if ( V_14 -> V_31 == V_32 )
F_17 ( V_14 , 0 ) ;
else {
if ( V_14 -> V_68 ) {
unsigned char V_106 = 0xfe ;
F_57 ( V_14 , & V_106 , 1 ) ;
}
if ( F_22 ( V_14 ) == - V_46 )
F_16 ( V_14 , 0 ) ;
}
}
V_14 -> V_38 -> V_107 ( V_14 ) ;
if ( V_14 -> V_16 -> V_108 )
V_14 -> V_16 -> V_108 ( V_14 ) ;
F_15 ( V_14 ) ;
V_14 -> V_37 = 0 ;
V_14 -> V_20 = 0 ;
F_58 ( V_14 -> V_69 ) ;
V_14 -> V_69 = NULL ;
V_49 -> V_55 [ V_14 -> V_31 ] . V_70 -- ;
}
static void F_59 ( struct V_71 * V_72 )
{
struct V_1 * V_49 ;
V_49 = V_72 -> V_49 ;
F_36 ( & V_49 -> V_80 ) ;
if ( V_72 -> V_75 ) {
F_33 ( V_49 , V_72 -> V_75 , 1 ) ;
V_72 -> V_75 = NULL ;
}
if ( V_72 -> V_76 ) {
F_33 ( V_49 , V_72 -> V_76 , 1 ) ;
V_72 -> V_76 = NULL ;
}
V_72 -> V_49 = NULL ;
F_37 ( & V_49 -> V_80 ) ;
F_60 ( & V_49 -> V_97 ) ;
}
int F_61 ( struct V_71 * V_72 )
{
struct V_1 * V_49 ;
if ( F_35 ( ! V_72 ) )
return - V_60 ;
V_49 = V_72 -> V_49 ;
F_59 ( V_72 ) ;
F_39 ( V_49 -> V_3 -> V_79 ) ;
return 0 ;
}
static int F_62 ( struct V_81 * V_81 , struct V_6 * V_6 )
{
struct V_71 * V_72 ;
struct V_1 * V_49 ;
struct V_79 * V_79 ;
V_72 = V_6 -> V_104 ;
V_49 = V_72 -> V_49 ;
F_59 ( V_72 ) ;
F_14 ( V_72 ) ;
V_79 = V_49 -> V_3 -> V_79 ;
F_56 ( V_49 -> V_3 , V_6 ) ;
F_39 ( V_79 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 ,
struct F_63 * V_109 )
{
struct V_1 * V_49 ;
if ( V_14 == NULL )
return - V_62 ;
V_49 = V_14 -> V_49 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_3 = V_49 -> V_3 -> V_64 ;
V_109 -> V_4 = V_49 -> V_4 ;
V_109 -> V_50 = V_14 -> V_64 ;
V_109 -> V_31 = V_14 -> V_31 ;
V_109 -> V_40 = V_49 -> V_56 ;
strcpy ( V_109 -> V_110 , V_49 -> V_110 ) ;
strcpy ( V_109 -> V_111 , V_49 -> V_111 ) ;
strcpy ( V_109 -> V_112 , V_14 -> V_111 ) ;
V_109 -> V_113 = V_14 -> V_114 -> V_61 ;
V_109 -> V_115 = ( V_14 -> V_114 -> V_61 -
V_14 -> V_114 -> V_70 ) ;
return 0 ;
}
static int F_64 ( struct V_13 * V_14 ,
struct F_63 T_3 * V_116 )
{
struct F_63 V_109 ;
int V_42 ;
if ( ( V_42 = F_63 ( V_14 , & V_109 ) ) < 0 )
return V_42 ;
if ( F_65 ( V_116 , & V_109 , sizeof( struct F_63 ) ) )
return - V_117 ;
return 0 ;
}
int F_66 ( struct V_2 * V_3 , struct F_63 * V_109 )
{
struct V_1 * V_49 ;
struct V_53 * V_114 ;
struct V_13 * V_14 ;
F_36 ( & V_78 ) ;
V_49 = F_1 ( V_3 , V_109 -> V_4 ) ;
F_37 ( & V_78 ) ;
if ( ! V_49 )
return - V_60 ;
if ( V_109 -> V_31 < 0 || V_109 -> V_31 > 1 )
return - V_77 ;
V_114 = & V_49 -> V_55 [ V_109 -> V_31 ] ;
if ( V_114 -> V_61 == 0 )
return - V_118 ;
if ( V_109 -> V_50 >= V_114 -> V_61 )
return - V_60 ;
F_2 (substream, &pstr->substreams, list) {
if ( ( unsigned int ) V_14 -> V_64 == V_109 -> V_50 )
return F_63 ( V_14 , V_109 ) ;
}
return - V_60 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct F_63 T_3 * V_116 )
{
int V_42 ;
struct F_63 V_109 ;
if ( F_68 ( V_109 . V_4 , & V_116 -> V_4 ) )
return - V_117 ;
if ( F_68 ( V_109 . V_31 , & V_116 -> V_31 ) )
return - V_117 ;
if ( F_68 ( V_109 . V_50 , & V_116 -> V_50 ) )
return - V_117 ;
if ( ( V_42 = F_66 ( V_3 , & V_109 ) ) < 0 )
return V_42 ;
if ( F_65 ( V_116 , & V_109 , sizeof( struct F_63 ) ) )
return - V_117 ;
return 0 ;
}
int F_69 ( struct V_13 * V_14 ,
struct V_119 * V_120 )
{
char * V_121 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_14 -> V_66 > 1 )
return - V_100 ;
F_22 ( V_14 ) ;
if ( V_120 -> V_29 < 32 || V_120 -> V_29 > 1024L * 1024L ) {
return - V_77 ;
}
if ( V_120 -> V_18 < 1 || V_120 -> V_18 > V_120 -> V_29 ) {
return - V_77 ;
}
if ( V_120 -> V_29 != V_16 -> V_29 ) {
V_121 = F_70 ( V_16 -> V_33 , V_120 -> V_29 ,
V_25 ) ;
if ( ! V_121 )
return - V_26 ;
V_16 -> V_33 = V_121 ;
V_16 -> V_29 = V_120 -> V_29 ;
V_16 -> V_17 = V_16 -> V_29 ;
}
V_16 -> V_18 = V_120 -> V_18 ;
V_14 -> V_68 = ! V_120 -> V_122 ;
return 0 ;
}
int F_71 ( struct V_13 * V_14 ,
struct V_119 * V_120 )
{
char * V_121 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_27 ( V_14 ) ;
if ( V_120 -> V_29 < 32 || V_120 -> V_29 > 1024L * 1024L ) {
return - V_77 ;
}
if ( V_120 -> V_18 < 1 || V_120 -> V_18 > V_120 -> V_29 ) {
return - V_77 ;
}
if ( V_120 -> V_29 != V_16 -> V_29 ) {
V_121 = F_70 ( V_16 -> V_33 , V_120 -> V_29 ,
V_25 ) ;
if ( ! V_121 )
return - V_26 ;
V_16 -> V_33 = V_121 ;
V_16 -> V_29 = V_120 -> V_29 ;
}
V_16 -> V_18 = V_120 -> V_18 ;
return 0 ;
}
static int F_72 ( struct V_13 * V_14 ,
struct V_123 * V_124 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_31 = V_57 ;
F_73 ( & V_16 -> V_27 ) ;
V_124 -> V_17 = V_16 -> V_17 ;
F_74 ( & V_16 -> V_27 ) ;
return 0 ;
}
static int F_75 ( struct V_13 * V_14 ,
struct V_123 * V_124 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_31 = V_32 ;
F_73 ( & V_16 -> V_27 ) ;
V_124 -> V_17 = V_16 -> V_17 ;
V_124 -> V_125 = V_16 -> V_125 ;
V_16 -> V_125 = 0 ;
F_74 ( & V_16 -> V_27 ) ;
return 0 ;
}
static long F_76 ( struct V_6 * V_6 , unsigned int V_126 , unsigned long V_127 )
{
struct V_71 * V_72 ;
void T_3 * V_128 = ( void T_3 * ) V_127 ;
V_72 = V_6 -> V_104 ;
if ( ( ( V_126 >> 8 ) & 0xff ) != 'W' )
return - V_129 ;
switch ( V_126 ) {
case V_130 :
return F_77 ( V_131 , ( int T_3 * ) V_128 ) ? - V_117 : 0 ;
case V_132 :
{
int V_31 ;
struct F_63 T_3 * V_109 = V_128 ;
if ( F_68 ( V_31 , & V_109 -> V_31 ) )
return - V_117 ;
switch ( V_31 ) {
case V_32 :
return F_64 ( V_72 -> V_75 , V_109 ) ;
case V_57 :
return F_64 ( V_72 -> V_76 , V_109 ) ;
default:
return - V_77 ;
}
}
case V_133 :
{
struct V_119 V_120 ;
if ( F_78 ( & V_120 , V_128 , sizeof( struct V_119 ) ) )
return - V_117 ;
switch ( V_120 . V_31 ) {
case V_57 :
if ( V_72 -> V_76 == NULL )
return - V_77 ;
return F_69 ( V_72 -> V_76 , & V_120 ) ;
case V_32 :
if ( V_72 -> V_75 == NULL )
return - V_77 ;
return F_71 ( V_72 -> V_75 , & V_120 ) ;
default:
return - V_77 ;
}
}
case V_134 :
{
int V_42 = 0 ;
struct V_123 V_124 ;
if ( F_78 ( & V_124 , V_128 , sizeof( struct V_123 ) ) )
return - V_117 ;
switch ( V_124 . V_31 ) {
case V_57 :
if ( V_72 -> V_76 == NULL )
return - V_77 ;
V_42 = F_72 ( V_72 -> V_76 , & V_124 ) ;
break;
case V_32 :
if ( V_72 -> V_75 == NULL )
return - V_77 ;
V_42 = F_75 ( V_72 -> V_75 , & V_124 ) ;
break;
default:
return - V_77 ;
}
if ( V_42 < 0 )
return V_42 ;
if ( F_65 ( V_128 , & V_124 , sizeof( struct V_123 ) ) )
return - V_117 ;
return 0 ;
}
case V_135 :
{
int V_136 ;
if ( F_68 ( V_136 , ( int T_3 * ) V_128 ) )
return - V_117 ;
switch ( V_136 ) {
case V_57 :
if ( V_72 -> V_76 == NULL )
return - V_77 ;
return F_19 ( V_72 -> V_76 ) ;
default:
return - V_77 ;
}
}
case V_137 :
{
int V_136 ;
if ( F_68 ( V_136 , ( int T_3 * ) V_128 ) )
return - V_117 ;
switch ( V_136 ) {
case V_57 :
if ( V_72 -> V_76 == NULL )
return - V_77 ;
return F_22 ( V_72 -> V_76 ) ;
case V_32 :
if ( V_72 -> V_75 == NULL )
return - V_77 ;
return F_27 ( V_72 -> V_75 ) ;
default:
return - V_77 ;
}
}
#ifdef F_79
default:
F_25 ( V_47 L_2 , V_126 ) ;
#endif
}
return - V_129 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_86 * V_138 ,
unsigned int V_126 ,
unsigned long V_127 )
{
void T_3 * V_128 = ( void T_3 * ) V_127 ;
switch ( V_126 ) {
case V_139 :
{
int V_4 ;
if ( F_68 ( V_4 , ( int T_3 * ) V_128 ) )
return - V_117 ;
if ( V_4 >= V_140 )
V_4 = V_140 - 1 ;
F_36 ( & V_78 ) ;
V_4 = V_4 < 0 ? 0 : V_4 + 1 ;
while ( V_4 < V_140 ) {
if ( F_1 ( V_3 , V_4 ) )
break;
V_4 ++ ;
}
if ( V_4 == V_140 )
V_4 = - 1 ;
F_37 ( & V_78 ) ;
if ( F_77 ( V_4 , ( int T_3 * ) V_128 ) )
return - V_117 ;
return 0 ;
}
case V_141 :
{
int V_136 ;
if ( F_68 ( V_136 , ( int T_3 * ) V_128 ) )
return - V_117 ;
V_138 -> V_99 = V_136 ;
return 0 ;
}
case V_142 :
return F_67 ( V_3 , V_128 ) ;
}
return - V_143 ;
}
int F_81 ( struct V_13 * V_14 ,
const unsigned char * V_33 , int V_19 )
{
unsigned long V_40 ;
int V_144 = 0 , V_145 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_37 )
return - V_146 ;
if ( V_16 -> V_33 == NULL ) {
F_82 ( L_3 ) ;
return - V_77 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_19 == 1 ) {
V_14 -> V_147 ++ ;
if ( V_16 -> V_17 < V_16 -> V_29 ) {
V_16 -> V_33 [ V_16 -> V_35 ++ ] = V_33 [ 0 ] ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 ++ ;
V_144 ++ ;
} else {
V_16 -> V_125 ++ ;
}
} else {
V_14 -> V_147 += V_19 ;
V_145 = V_16 -> V_29 - V_16 -> V_35 ;
if ( V_145 > V_19 )
V_145 = V_19 ;
if ( V_145 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) )
V_145 = V_16 -> V_29 - V_16 -> V_17 ;
memcpy ( V_16 -> V_33 + V_16 -> V_35 , V_33 , V_145 ) ;
V_16 -> V_35 += V_145 ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 += V_145 ;
V_19 -= V_145 ;
V_144 += V_145 ;
if ( V_19 > 0 ) {
V_33 += V_145 ;
V_145 = V_19 ;
if ( V_145 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) ) {
V_145 = V_16 -> V_29 - V_16 -> V_17 ;
V_16 -> V_125 += V_19 - V_145 ;
}
if ( V_145 > 0 ) {
memcpy ( V_16 -> V_33 , V_33 , V_145 ) ;
V_16 -> V_35 = V_145 ;
V_16 -> V_17 += V_145 ;
V_144 += V_145 ;
}
}
}
if ( V_144 > 0 ) {
if ( V_16 -> V_24 )
F_83 ( & V_16 -> V_23 ) ;
else if ( F_4 ( V_14 ) )
F_60 ( & V_16 -> V_28 ) ;
}
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_144 ;
}
static long F_84 ( struct V_13 * V_14 ,
unsigned char T_3 * V_148 ,
unsigned char * V_149 , long V_19 )
{
unsigned long V_40 ;
long V_144 = 0 , V_145 ;
struct V_15 * V_16 = V_14 -> V_16 ;
while ( V_19 > 0 && V_16 -> V_17 ) {
V_145 = V_16 -> V_29 - V_16 -> V_34 ;
if ( V_145 > V_19 )
V_145 = V_19 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_145 > ( int ) V_16 -> V_17 )
V_145 = V_16 -> V_17 ;
if ( V_149 )
memcpy ( V_149 + V_144 , V_16 -> V_33 + V_16 -> V_34 , V_145 ) ;
if ( V_148 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( F_65 ( V_148 + V_144 ,
V_16 -> V_33 + V_16 -> V_34 , V_145 ) ) {
return V_144 > 0 ? V_144 : - V_117 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
}
V_16 -> V_34 += V_145 ;
V_16 -> V_34 %= V_16 -> V_29 ;
V_16 -> V_17 -= V_145 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
V_144 += V_145 ;
V_19 -= V_145 ;
}
return V_144 ;
}
long F_85 ( struct V_13 * V_14 ,
unsigned char * V_106 , long V_19 )
{
F_17 ( V_14 , 1 ) ;
return F_84 ( V_14 , NULL , V_106 , V_19 ) ;
}
static T_4 F_86 ( struct V_6 * V_6 , char T_3 * V_106 , T_1 V_19 ,
T_5 * V_150 )
{
long V_144 ;
int V_145 ;
struct V_71 * V_72 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_72 = V_6 -> V_104 ;
V_14 = V_72 -> V_75 ;
if ( V_14 == NULL )
return - V_48 ;
V_16 = V_14 -> V_16 ;
F_17 ( V_14 , 1 ) ;
V_144 = 0 ;
while ( V_19 > 0 ) {
F_73 ( & V_16 -> V_27 ) ;
while ( ! F_4 ( V_14 ) ) {
T_2 V_85 ;
if ( ( V_6 -> V_88 & V_90 ) != 0 || V_144 > 0 ) {
F_74 ( & V_16 -> V_27 ) ;
return V_144 > 0 ? V_144 : - V_65 ;
}
F_49 ( & V_85 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_85 ) ;
F_53 ( V_101 ) ;
F_74 ( & V_16 -> V_27 ) ;
F_54 () ;
F_55 ( & V_16 -> V_28 , & V_85 ) ;
if ( V_72 -> V_49 -> V_3 -> V_102 )
return - V_62 ;
if ( F_24 ( V_45 ) )
return V_144 > 0 ? V_144 : - V_46 ;
if ( ! V_16 -> V_17 )
return V_144 > 0 ? V_144 : - V_48 ;
F_73 ( & V_16 -> V_27 ) ;
}
F_74 ( & V_16 -> V_27 ) ;
V_145 = F_84 ( V_14 ,
( unsigned char T_3 * ) V_106 ,
NULL ,
V_19 ) ;
if ( V_145 < 0 )
return V_144 > 0 ? V_144 : V_145 ;
V_144 += V_145 ;
V_106 += V_145 ;
V_19 -= V_145 ;
}
return V_144 ;
}
int F_87 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_144 ;
unsigned long V_40 ;
if ( V_16 -> V_33 == NULL ) {
F_82 ( L_4 ) ;
return 1 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_144 = V_16 -> V_17 >= V_16 -> V_29 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_144 ;
}
int F_88 ( struct V_13 * V_14 ,
unsigned char * V_33 , int V_19 )
{
unsigned long V_40 ;
int V_144 , V_145 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_33 == NULL ) {
F_82 ( L_5 ) ;
return - V_77 ;
}
V_144 = 0 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_16 -> V_17 >= V_16 -> V_29 ) {
goto V_151;
}
if ( V_19 == 1 ) {
* V_33 = V_16 -> V_33 [ V_16 -> V_35 ] ;
V_144 ++ ;
} else {
V_145 = V_16 -> V_29 - V_16 -> V_35 ;
if ( V_145 > V_19 )
V_145 = V_19 ;
if ( V_145 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 ) )
V_145 = V_16 -> V_29 - V_16 -> V_17 ;
memcpy ( V_33 , V_16 -> V_33 + V_16 -> V_35 , V_145 ) ;
V_19 -= V_145 ;
V_144 += V_145 ;
if ( V_19 > 0 ) {
if ( V_19 > ( int ) ( V_16 -> V_29 - V_16 -> V_17 - V_145 ) )
V_19 = V_16 -> V_29 - V_16 -> V_17 - V_145 ;
memcpy ( V_33 + V_145 , V_16 -> V_33 , V_19 ) ;
V_144 += V_19 ;
}
}
V_151:
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_144 ;
}
int F_89 ( struct V_13 * V_14 , int V_19 )
{
unsigned long V_40 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_33 == NULL ) {
F_82 ( L_6 ) ;
return - V_77 ;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
F_35 ( V_16 -> V_17 + V_19 > V_16 -> V_29 ) ;
V_16 -> V_35 += V_19 ;
V_16 -> V_35 %= V_16 -> V_29 ;
V_16 -> V_17 += V_19 ;
V_14 -> V_147 += V_19 ;
if ( V_19 > 0 ) {
if ( V_16 -> V_41 || F_4 ( V_14 ) )
F_60 ( & V_16 -> V_28 ) ;
}
F_21 ( & V_16 -> V_27 , V_40 ) ;
return V_19 ;
}
int F_90 ( struct V_13 * V_14 ,
unsigned char * V_33 , int V_19 )
{
if ( ! V_14 -> V_37 )
return - V_146 ;
V_19 = F_88 ( V_14 , V_33 , V_19 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_89 ( V_14 , V_19 ) ;
}
static long F_91 ( struct V_13 * V_14 ,
const unsigned char T_3 * V_148 ,
const unsigned char * V_149 ,
long V_19 )
{
unsigned long V_40 ;
long V_145 , V_144 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( F_35 ( ! V_149 && ! V_148 ) )
return - V_77 ;
if ( F_35 ( ! V_16 -> V_33 ) )
return - V_77 ;
V_144 = 0 ;
F_20 ( & V_16 -> V_27 , V_40 ) ;
if ( V_14 -> V_20 ) {
if ( ( long ) V_16 -> V_17 < V_19 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
return - V_65 ;
}
}
while ( V_19 > 0 && V_16 -> V_17 > 0 ) {
V_145 = V_16 -> V_29 - V_16 -> V_34 ;
if ( V_145 > V_19 )
V_145 = V_19 ;
if ( V_145 > ( long ) V_16 -> V_17 )
V_145 = V_16 -> V_17 ;
if ( V_149 )
memcpy ( V_16 -> V_33 + V_16 -> V_34 ,
V_149 + V_144 , V_145 ) ;
else if ( V_148 ) {
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( F_78 ( V_16 -> V_33 + V_16 -> V_34 ,
V_148 + V_144 , V_145 ) ) {
F_20 ( & V_16 -> V_27 , V_40 ) ;
V_144 = V_144 > 0 ? V_144 : - V_117 ;
goto V_152;
}
F_20 ( & V_16 -> V_27 , V_40 ) ;
}
V_16 -> V_34 += V_145 ;
V_16 -> V_34 %= V_16 -> V_29 ;
V_16 -> V_17 -= V_145 ;
V_144 += V_145 ;
V_19 -= V_145 ;
}
V_152:
V_145 = V_16 -> V_17 < V_16 -> V_29 ;
F_21 ( & V_16 -> V_27 , V_40 ) ;
if ( V_145 )
F_16 ( V_14 , 1 ) ;
return V_144 ;
}
long F_57 ( struct V_13 * V_14 ,
const unsigned char * V_106 , long V_19 )
{
return F_91 ( V_14 , NULL , V_106 , V_19 ) ;
}
static T_4 F_92 ( struct V_6 * V_6 , const char T_3 * V_106 ,
T_1 V_19 , T_5 * V_150 )
{
long V_144 , V_43 ;
int V_145 ;
struct V_71 * V_72 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
V_72 = V_6 -> V_104 ;
V_14 = V_72 -> V_76 ;
V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_19 > V_16 -> V_29 )
return - V_48 ;
V_144 = 0 ;
while ( V_19 > 0 ) {
F_73 ( & V_16 -> V_27 ) ;
while ( ! F_5 ( V_14 , V_19 ) ) {
T_2 V_85 ;
if ( V_6 -> V_88 & V_90 ) {
F_74 ( & V_16 -> V_27 ) ;
return V_144 > 0 ? V_144 : - V_65 ;
}
F_49 ( & V_85 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_85 ) ;
F_53 ( V_101 ) ;
F_74 ( & V_16 -> V_27 ) ;
V_43 = F_93 ( 30 * V_44 ) ;
F_55 ( & V_16 -> V_28 , & V_85 ) ;
if ( V_72 -> V_49 -> V_3 -> V_102 )
return - V_62 ;
if ( F_24 ( V_45 ) )
return V_144 > 0 ? V_144 : - V_46 ;
if ( ! V_16 -> V_17 && ! V_43 )
return V_144 > 0 ? V_144 : - V_48 ;
F_73 ( & V_16 -> V_27 ) ;
}
F_74 ( & V_16 -> V_27 ) ;
V_145 = F_91 ( V_14 , V_106 , NULL , V_19 ) ;
if ( V_145 < 0 )
return V_144 > 0 ? V_144 : V_145 ;
V_144 += V_145 ;
V_106 += V_145 ;
if ( ( T_1 ) V_145 < V_19 && ( V_6 -> V_88 & V_90 ) )
break;
V_19 -= V_145 ;
}
if ( V_6 -> V_88 & V_153 ) {
F_73 ( & V_16 -> V_27 ) ;
while ( V_16 -> V_17 != V_16 -> V_29 ) {
T_2 V_85 ;
unsigned int V_154 = V_16 -> V_17 ;
F_49 ( & V_85 , V_45 ) ;
F_50 ( & V_16 -> V_28 , & V_85 ) ;
F_53 ( V_101 ) ;
F_74 ( & V_16 -> V_27 ) ;
V_43 = F_93 ( 30 * V_44 ) ;
F_55 ( & V_16 -> V_28 , & V_85 ) ;
if ( F_24 ( V_45 ) )
return V_144 > 0 ? V_144 : - V_46 ;
if ( V_16 -> V_17 == V_154 && ! V_43 )
return V_144 > 0 ? V_144 : - V_48 ;
F_73 ( & V_16 -> V_27 ) ;
}
F_74 ( & V_16 -> V_27 ) ;
}
return V_144 ;
}
static unsigned int F_94 ( struct V_6 * V_6 , T_6 * V_85 )
{
struct V_71 * V_72 ;
struct V_15 * V_16 ;
unsigned int V_155 ;
V_72 = V_6 -> V_104 ;
if ( V_72 -> V_75 != NULL ) {
V_16 = V_72 -> V_75 -> V_16 ;
F_17 ( V_72 -> V_75 , 1 ) ;
F_95 ( V_6 , & V_16 -> V_28 , V_85 ) ;
}
if ( V_72 -> V_76 != NULL ) {
V_16 = V_72 -> V_76 -> V_16 ;
F_95 ( V_6 , & V_16 -> V_28 , V_85 ) ;
}
V_155 = 0 ;
if ( V_72 -> V_75 != NULL ) {
if ( F_4 ( V_72 -> V_75 ) )
V_155 |= V_156 | V_157 ;
}
if ( V_72 -> V_76 != NULL ) {
if ( F_4 ( V_72 -> V_76 ) )
V_155 |= V_158 | V_159 ;
}
return V_155 ;
}
static void F_96 ( struct V_160 * V_161 ,
struct V_162 * V_33 )
{
struct V_1 * V_49 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_49 = V_161 -> V_104 ;
F_97 ( V_33 , L_7 , V_49 -> V_111 ) ;
F_36 ( & V_49 -> V_80 ) ;
if ( V_49 -> V_56 & V_58 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams,
list) {
F_97 ( V_33 ,
L_8
L_9 ,
V_14 -> V_64 ,
( unsigned long ) V_14 -> V_147 ) ;
if ( V_14 -> V_37 ) {
F_97 ( V_33 ,
L_10 ,
F_98 ( V_14 -> V_69 ) ) ;
V_16 = V_14 -> V_16 ;
F_97 ( V_33 ,
L_11
L_12
L_13 ,
V_16 -> V_103 ? L_14 : L_15 ,
( unsigned long ) V_16 -> V_29 ,
( unsigned long ) V_16 -> V_17 ) ;
}
}
}
if ( V_49 -> V_56 & V_59 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams,
list) {
F_97 ( V_33 ,
L_16
L_17 ,
V_14 -> V_64 ,
( unsigned long ) V_14 -> V_147 ) ;
if ( V_14 -> V_37 ) {
F_97 ( V_33 ,
L_10 ,
F_98 ( V_14 -> V_69 ) ) ;
V_16 = V_14 -> V_16 ;
F_97 ( V_33 ,
L_12
L_13
L_18 ,
( unsigned long ) V_16 -> V_29 ,
( unsigned long ) V_16 -> V_17 ,
( unsigned long ) V_16 -> V_125 ) ;
}
}
}
F_37 ( & V_49 -> V_80 ) ;
}
static int F_99 ( struct V_1 * V_49 ,
struct V_53 * V_31 ,
int V_163 ,
int V_19 )
{
struct V_13 * V_14 ;
int V_164 ;
for ( V_164 = 0 ; V_164 < V_19 ; V_164 ++ ) {
V_14 = F_9 ( sizeof( * V_14 ) , V_25 ) ;
if ( V_14 == NULL ) {
F_25 ( V_165 L_19 ) ;
return - V_26 ;
}
V_14 -> V_31 = V_163 ;
V_14 -> V_64 = V_164 ;
V_14 -> V_49 = V_49 ;
V_14 -> V_114 = V_31 ;
F_100 ( & V_14 -> V_166 , & V_31 -> V_167 ) ;
V_31 -> V_61 ++ ;
}
return 0 ;
}
int F_101 ( struct V_2 * V_3 , char * V_110 , int V_4 ,
int V_168 , int V_169 ,
struct V_1 * * V_170 )
{
struct V_1 * V_49 ;
int V_42 ;
static struct V_171 V_38 = {
. V_172 = V_173 ,
. V_174 = V_175 ,
. V_176 = V_177 ,
} ;
if ( F_35 ( ! V_3 ) )
return - V_60 ;
if ( V_170 )
* V_170 = NULL ;
V_49 = F_9 ( sizeof( * V_49 ) , V_25 ) ;
if ( V_49 == NULL ) {
F_25 ( V_165 L_20 ) ;
return - V_26 ;
}
V_49 -> V_3 = V_3 ;
V_49 -> V_4 = V_4 ;
F_102 ( & V_49 -> V_80 ) ;
F_11 ( & V_49 -> V_97 ) ;
F_103 ( & V_49 -> V_55 [ V_32 ] . V_167 ) ;
F_103 ( & V_49 -> V_55 [ V_57 ] . V_167 ) ;
if ( V_110 != NULL )
F_104 ( V_49 -> V_110 , V_110 , sizeof( V_49 -> V_110 ) ) ;
if ( ( V_42 = F_99 ( V_49 ,
& V_49 -> V_55 [ V_32 ] ,
V_32 ,
V_169 ) ) < 0 ) {
F_105 ( V_49 ) ;
return V_42 ;
}
if ( ( V_42 = F_99 ( V_49 ,
& V_49 -> V_55 [ V_57 ] ,
V_57 ,
V_168 ) ) < 0 ) {
F_105 ( V_49 ) ;
return V_42 ;
}
if ( ( V_42 = F_106 ( V_3 , V_178 , V_49 , & V_38 ) ) < 0 ) {
F_105 ( V_49 ) ;
return V_42 ;
}
if ( V_170 )
* V_170 = V_49 ;
return 0 ;
}
static void F_107 ( struct V_53 * V_31 )
{
struct V_13 * V_14 ;
while ( ! F_108 ( & V_31 -> V_167 ) ) {
V_14 = F_109 ( V_31 -> V_167 . V_179 , struct V_13 , V_166 ) ;
F_110 ( & V_14 -> V_166 ) ;
F_14 ( V_14 ) ;
}
}
static int F_105 ( struct V_1 * V_49 )
{
if ( ! V_49 )
return 0 ;
F_111 ( V_49 -> V_180 ) ;
V_49 -> V_180 = NULL ;
F_36 ( & V_78 ) ;
if ( V_49 -> V_38 && V_49 -> V_38 -> V_181 )
V_49 -> V_38 -> V_181 ( V_49 ) ;
F_37 ( & V_78 ) ;
F_107 ( & V_49 -> V_55 [ V_32 ] ) ;
F_107 ( & V_49 -> V_55 [ V_57 ] ) ;
if ( V_49 -> V_108 )
V_49 -> V_108 ( V_49 ) ;
F_14 ( V_49 ) ;
return 0 ;
}
static int V_173 ( struct V_182 * V_4 )
{
struct V_1 * V_49 = V_4 -> V_183 ;
return F_105 ( V_49 ) ;
}
static void F_112 ( struct V_184 * V_4 )
{
struct V_1 * V_49 = V_4 -> V_104 ;
V_49 -> V_185 = NULL ;
}
static int V_175 ( struct V_182 * V_4 )
{
int V_42 ;
struct V_160 * V_161 ;
char V_111 [ 16 ] ;
struct V_1 * V_49 = V_4 -> V_183 ;
if ( V_49 -> V_4 >= V_140 )
return - V_26 ;
F_36 ( & V_78 ) ;
if ( F_1 ( V_49 -> V_3 , V_49 -> V_4 ) ) {
F_37 ( & V_78 ) ;
return - V_100 ;
}
F_100 ( & V_49 -> V_166 , & V_186 ) ;
sprintf ( V_111 , L_21 , V_49 -> V_3 -> V_64 , V_49 -> V_4 ) ;
if ( ( V_42 = F_113 ( V_92 ,
V_49 -> V_3 , V_49 -> V_4 ,
& V_187 , V_49 , V_111 ) ) < 0 ) {
F_25 ( V_165 L_22 , V_49 -> V_3 -> V_64 , V_49 -> V_4 ) ;
F_110 ( & V_49 -> V_166 ) ;
F_37 ( & V_78 ) ;
return V_42 ;
}
if ( V_49 -> V_38 && V_49 -> V_38 -> V_174 &&
( V_42 = V_49 -> V_38 -> V_174 ( V_49 ) ) < 0 ) {
F_114 ( V_92 , V_49 -> V_3 , V_49 -> V_4 ) ;
F_110 ( & V_49 -> V_166 ) ;
F_37 ( & V_78 ) ;
return V_42 ;
}
#ifdef F_45
V_49 -> V_188 = 0 ;
if ( ( int ) V_49 -> V_4 == V_189 [ V_49 -> V_3 -> V_64 ] ) {
if ( F_115 ( V_94 ,
V_49 -> V_3 , 0 , & V_187 ,
V_49 , V_111 ) < 0 ) {
F_25 ( V_165 L_23 , V_49 -> V_3 -> V_64 , 0 ) ;
} else {
V_49 -> V_188 ++ ;
#ifdef F_116
F_117 ( F_116 , V_49 -> V_3 -> V_64 , V_49 -> V_111 ) ;
#endif
}
}
if ( ( int ) V_49 -> V_4 == V_190 [ V_49 -> V_3 -> V_64 ] ) {
if ( F_115 ( V_94 ,
V_49 -> V_3 , 1 , & V_187 ,
V_49 , V_111 ) < 0 ) {
F_25 ( V_165 L_23 , V_49 -> V_3 -> V_64 , 1 ) ;
} else {
V_49 -> V_188 ++ ;
}
}
#endif
F_37 ( & V_78 ) ;
sprintf ( V_111 , L_24 , V_49 -> V_4 ) ;
V_161 = F_118 ( V_49 -> V_3 , V_111 , V_49 -> V_3 -> V_191 ) ;
if ( V_161 ) {
V_161 -> V_104 = V_49 ;
V_161 -> V_192 . V_193 . V_194 = F_96 ;
if ( F_119 ( V_161 ) < 0 ) {
F_111 ( V_161 ) ;
V_161 = NULL ;
}
}
V_49 -> V_180 = V_161 ;
#if F_120 ( V_195 ) || ( F_120 ( V_196 ) && F_120 ( V_197 ) )
if ( ! V_49 -> V_38 || ! V_49 -> V_38 -> V_174 ) {
if ( F_121 ( V_49 -> V_3 , V_49 -> V_4 , V_198 , 0 , & V_49 -> V_185 ) >= 0 ) {
V_49 -> V_185 -> V_104 = V_49 ;
V_49 -> V_185 -> V_108 = F_112 ;
sprintf ( V_49 -> V_185 -> V_111 , L_25 , V_49 -> V_3 -> V_64 , V_49 -> V_4 ) ;
F_122 ( V_49 -> V_3 , V_49 -> V_185 ) ;
}
}
#endif
return 0 ;
}
static int V_177 ( struct V_182 * V_4 )
{
struct V_1 * V_49 = V_4 -> V_183 ;
int V_199 ;
F_36 ( & V_78 ) ;
F_36 ( & V_49 -> V_80 ) ;
F_60 ( & V_49 -> V_97 ) ;
F_123 ( & V_49 -> V_166 ) ;
for ( V_199 = 0 ; V_199 < 2 ; V_199 ++ ) {
struct V_13 * V_54 ;
F_2 (s, &rmidi->streams[dir].substreams, list) {
if ( V_54 -> V_16 )
F_60 ( & V_54 -> V_16 -> V_28 ) ;
}
}
#ifdef F_45
if ( V_49 -> V_188 ) {
if ( ( int ) V_49 -> V_4 == V_189 [ V_49 -> V_3 -> V_64 ] ) {
F_124 ( V_94 , V_49 -> V_3 , 0 ) ;
#ifdef F_116
F_125 ( F_116 , V_49 -> V_3 -> V_64 ) ;
#endif
}
if ( ( int ) V_49 -> V_4 == V_190 [ V_49 -> V_3 -> V_64 ] )
F_124 ( V_94 , V_49 -> V_3 , 1 ) ;
V_49 -> V_188 = 0 ;
}
#endif
F_114 ( V_92 , V_49 -> V_3 , V_49 -> V_4 ) ;
F_37 ( & V_49 -> V_80 ) ;
F_37 ( & V_78 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_49 , int V_31 ,
struct V_200 * V_38 )
{
struct V_13 * V_14 ;
F_2 (substream, &rmidi->streams[stream].substreams, list)
V_14 -> V_38 = V_38 ;
}
static int T_7 F_127 ( void )
{
F_128 ( F_80 ) ;
F_129 ( F_80 ) ;
#ifdef F_45
{ int V_201 ;
for ( V_201 = 0 ; V_201 < V_202 ; V_201 ++ ) {
if ( V_189 [ V_201 ] < 0 || V_189 [ V_201 ] >= V_140 ) {
F_25 ( V_165 L_26 , V_201 , V_189 [ V_201 ] ) ;
V_189 [ V_201 ] = 0 ;
}
if ( V_190 [ V_201 ] < 0 || V_190 [ V_201 ] >= V_140 ) {
F_25 ( V_165 L_27 , V_201 , V_190 [ V_201 ] ) ;
V_190 [ V_201 ] = 1 ;
}
}
}
#endif
return 0 ;
}
static void T_8 F_130 ( void )
{
F_131 ( F_80 ) ;
F_132 ( F_80 ) ;
}
