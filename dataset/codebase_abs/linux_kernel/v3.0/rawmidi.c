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
static void F_6 ( unsigned long V_21 )
{
struct V_13 * V_14 = (struct V_13 * ) V_21 ;
V_14 -> V_16 -> V_22 ( V_14 ) ;
}
static void F_7 ( unsigned long V_21 )
{
struct V_13 * V_14 = (struct V_13 * ) V_21 ;
V_14 -> V_23 -> V_24 ( V_14 , 1 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
if ( ( V_16 = F_9 ( sizeof( * V_16 ) , V_25 ) ) == NULL )
return - V_26 ;
F_10 ( & V_16 -> V_27 ) ;
F_11 ( & V_16 -> V_28 ) ;
if ( V_14 -> V_29 == V_30 )
F_12 ( & V_16 -> V_31 ,
F_6 ,
( unsigned long ) V_14 ) ;
else
F_12 ( & V_16 -> V_31 ,
F_7 ,
( unsigned long ) V_14 ) ;
V_16 -> V_22 = NULL ;
V_16 -> V_32 = V_33 ;
V_16 -> V_18 = 1 ;
if ( V_14 -> V_29 == V_30 )
V_16 -> V_17 = 0 ;
else
V_16 -> V_17 = V_16 -> V_32 ;
if ( ( V_16 -> V_34 = F_13 ( V_16 -> V_32 , V_25 ) ) == NULL ) {
F_14 ( V_16 ) ;
return - V_26 ;
}
V_16 -> V_35 = V_16 -> V_36 = 0 ;
V_14 -> V_16 = V_16 ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
F_14 ( V_16 -> V_34 ) ;
F_14 ( V_16 ) ;
V_14 -> V_16 = NULL ;
return 0 ;
}
static inline void F_16 ( struct V_13 * V_14 , int V_37 )
{
if ( ! V_14 -> V_38 )
return;
if ( V_37 ) {
F_17 ( & V_14 -> V_16 -> V_31 ) ;
} else {
F_18 ( & V_14 -> V_16 -> V_31 ) ;
V_14 -> V_23 -> V_24 ( V_14 , 0 ) ;
}
}
static void F_19 ( struct V_13 * V_14 , int V_37 )
{
if ( ! V_14 -> V_38 )
return;
V_14 -> V_23 -> V_24 ( V_14 , V_37 ) ;
if ( ! V_37 && V_14 -> V_16 -> V_22 )
F_18 ( & V_14 -> V_16 -> V_31 ) ;
}
int F_20 ( struct V_13 * V_14 )
{
unsigned long V_39 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_16 ( V_14 , 0 ) ;
V_16 -> V_40 = 0 ;
F_21 ( & V_16 -> V_27 , V_39 ) ;
V_16 -> V_35 = V_16 -> V_36 = 0 ;
V_16 -> V_17 = V_16 -> V_32 ;
F_22 ( & V_16 -> V_27 , V_39 ) ;
return 0 ;
}
int F_23 ( struct V_13 * V_14 )
{
int V_41 ;
long V_42 ;
struct V_15 * V_16 = V_14 -> V_16 ;
V_41 = 0 ;
V_16 -> V_40 = 1 ;
V_42 = F_24 ( V_16 -> V_28 ,
( V_16 -> V_17 >= V_16 -> V_32 ) ,
10 * V_43 ) ;
if ( F_25 ( V_44 ) )
V_41 = - V_45 ;
if ( V_16 -> V_17 < V_16 -> V_32 && ! V_42 ) {
F_26 ( V_46 L_1 , ( long ) V_16 -> V_17 , ( long ) V_16 -> V_32 ) ;
V_41 = - V_47 ;
}
V_16 -> V_40 = 0 ;
if ( V_41 != - V_45 ) {
if ( V_14 -> V_23 -> V_40 )
V_14 -> V_23 -> V_40 ( V_14 ) ;
else
F_27 ( 50 ) ;
F_20 ( V_14 ) ;
}
return V_41 ;
}
int F_28 ( struct V_13 * V_14 )
{
unsigned long V_39 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_19 ( V_14 , 0 ) ;
V_16 -> V_40 = 0 ;
F_21 ( & V_16 -> V_27 , V_39 ) ;
V_16 -> V_35 = V_16 -> V_36 = 0 ;
V_16 -> V_17 = 0 ;
F_22 ( & V_16 -> V_27 , V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_48 , int V_49 ,
int V_29 , int V_50 ,
struct V_13 * * V_51 )
{
struct V_13 * V_14 ;
struct V_52 * V_53 = & V_48 -> V_54 [ V_29 ] ;
static unsigned int V_55 [ 2 ] = {
[ V_56 ] = V_57 ,
[ V_30 ] = V_58 ,
} ;
if ( ! ( V_48 -> V_55 & V_55 [ V_29 ] ) )
return - V_59 ;
if ( V_49 >= 0 && V_49 >= V_53 -> V_60 )
return - V_61 ;
F_2 (substream, &s->substreams, list) {
if ( V_14 -> V_38 ) {
if ( V_29 == V_30 ||
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
static int F_30 ( struct V_1 * V_48 ,
struct V_13 * V_14 ,
int V_50 )
{
int V_41 ;
if ( V_14 -> V_65 == 0 ) {
V_41 = F_8 ( V_14 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = V_14 -> V_23 -> V_66 ( V_14 ) ;
if ( V_41 < 0 ) {
F_15 ( V_14 ) ;
return V_41 ;
}
V_14 -> V_38 = 1 ;
V_14 -> V_67 = 0 ;
if ( V_50 & V_62 )
V_14 -> V_20 = 1 ;
V_14 -> V_68 = F_31 ( F_32 ( V_44 ) ) ;
V_48 -> V_54 [ V_14 -> V_29 ] . V_69 ++ ;
}
V_14 -> V_65 ++ ;
return 0 ;
}
static int F_33 ( struct V_1 * V_48 , int V_49 , int V_50 ,
struct V_70 * V_71 )
{
struct V_13 * V_72 = NULL , * V_73 = NULL ;
int V_41 ;
V_71 -> V_74 = V_71 -> V_75 = NULL ;
if ( V_50 & V_11 ) {
V_41 = F_29 ( V_48 , V_49 ,
V_30 ,
V_50 , & V_72 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_50 & V_10 ) {
V_41 = F_29 ( V_48 , V_49 ,
V_56 ,
V_50 , & V_73 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_72 ) {
V_41 = F_30 ( V_48 , V_72 , V_50 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_73 ) {
V_41 = F_30 ( V_48 , V_73 , V_50 ) ;
if ( V_41 < 0 ) {
if ( V_72 )
F_34 ( V_48 , V_72 , 0 ) ;
return V_41 ;
}
}
V_71 -> V_48 = V_48 ;
V_71 -> V_74 = V_72 ;
V_71 -> V_75 = V_73 ;
return 0 ;
}
int F_35 ( struct V_2 * V_3 , int V_4 , int V_49 ,
int V_50 , struct V_70 * V_71 )
{
struct V_1 * V_48 ;
int V_41 ;
if ( F_36 ( ! V_71 ) )
return - V_76 ;
F_37 ( & V_77 ) ;
V_48 = F_1 ( V_3 , V_4 ) ;
if ( V_48 == NULL ) {
F_38 ( & V_77 ) ;
return - V_61 ;
}
if ( ! F_39 ( V_48 -> V_3 -> V_78 ) ) {
F_38 ( & V_77 ) ;
return - V_59 ;
}
F_38 ( & V_77 ) ;
F_37 ( & V_48 -> V_79 ) ;
V_41 = F_33 ( V_48 , V_49 , V_50 , V_71 ) ;
F_38 ( & V_48 -> V_79 ) ;
if ( V_41 < 0 )
F_40 ( V_48 -> V_3 -> V_78 ) ;
return V_41 ;
}
static int F_41 ( struct V_80 * V_80 , struct V_6 * V_6 )
{
int V_81 = F_42 ( V_80 ) ;
struct V_2 * V_3 ;
int V_49 ;
unsigned short V_82 ;
int V_41 ;
struct V_1 * V_48 ;
struct V_70 * V_83 = NULL ;
T_2 V_84 ;
struct V_85 * V_86 ;
if ( ( V_6 -> V_87 & V_88 ) && ! ( V_6 -> V_87 & V_89 ) )
return - V_76 ;
V_41 = F_43 ( V_80 , V_6 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_81 == V_90 ) {
V_48 = F_44 ( F_45 ( V_80 ) ,
V_91 ) ;
#ifdef F_46
} else if ( V_81 == V_92 ) {
V_48 = F_47 ( F_45 ( V_80 ) ,
V_93 ) ;
#endif
} else
return - V_59 ;
if ( V_48 == NULL )
return - V_61 ;
if ( ! F_39 ( V_48 -> V_3 -> V_78 ) )
return - V_59 ;
F_37 ( & V_48 -> V_79 ) ;
V_3 = V_48 -> V_3 ;
V_41 = F_48 ( V_3 , V_6 ) ;
if ( V_41 < 0 )
goto V_94;
V_82 = F_3 ( V_6 ) ;
if ( ( V_6 -> V_87 & V_88 ) || V_81 == V_92 )
V_82 |= V_62 ;
V_83 = F_13 ( sizeof( * V_83 ) , V_25 ) ;
if ( V_83 == NULL ) {
V_41 = - V_26 ;
goto V_95;
}
F_49 ( & V_84 , V_44 ) ;
F_50 ( & V_48 -> V_96 , & V_84 ) ;
while ( 1 ) {
V_49 = - 1 ;
F_51 ( & V_3 -> V_97 ) ;
F_2 (kctl, &card->ctl_files, list) {
if ( V_86 -> V_68 == F_32 ( V_44 ) ) {
V_49 = V_86 -> V_98 ;
if ( V_49 != - 1 )
break;
}
}
F_52 ( & V_3 -> V_97 ) ;
V_41 = F_33 ( V_48 , V_49 , V_82 , V_83 ) ;
if ( V_41 >= 0 )
break;
if ( V_41 == - V_64 ) {
if ( V_6 -> V_87 & V_89 ) {
V_41 = - V_99 ;
break;
}
} else
break;
F_53 ( V_100 ) ;
F_38 ( & V_48 -> V_79 ) ;
F_54 () ;
F_37 ( & V_48 -> V_79 ) ;
if ( F_25 ( V_44 ) ) {
V_41 = - V_45 ;
break;
}
}
F_55 ( & V_48 -> V_96 , & V_84 ) ;
if ( V_41 < 0 ) {
F_14 ( V_83 ) ;
goto V_95;
}
#ifdef F_46
if ( V_83 -> V_74 && V_83 -> V_74 -> V_16 )
V_83 -> V_74 -> V_16 -> V_101 = ( V_81 == V_92 ) ;
if ( V_83 -> V_75 && V_83 -> V_75 -> V_16 )
V_83 -> V_75 -> V_16 -> V_101 = ( V_81 == V_92 ) ;
#endif
V_6 -> V_102 = V_83 ;
F_38 ( & V_48 -> V_79 ) ;
return 0 ;
V_95:
F_56 ( V_3 , V_6 ) ;
V_94:
F_38 ( & V_48 -> V_79 ) ;
F_40 ( V_48 -> V_3 -> V_78 ) ;
return V_41 ;
}
static void F_34 ( struct V_1 * V_48 ,
struct V_13 * V_14 ,
int V_103 )
{
if ( -- V_14 -> V_65 )
return;
if ( V_103 ) {
if ( V_14 -> V_29 == V_30 )
F_19 ( V_14 , 0 ) ;
else {
if ( V_14 -> V_67 ) {
unsigned char V_104 = 0xfe ;
F_57 ( V_14 , & V_104 , 1 ) ;
}
if ( F_23 ( V_14 ) == - V_45 )
F_16 ( V_14 , 0 ) ;
}
}
V_14 -> V_23 -> V_105 ( V_14 ) ;
if ( V_14 -> V_16 -> V_106 )
V_14 -> V_16 -> V_106 ( V_14 ) ;
F_15 ( V_14 ) ;
V_14 -> V_38 = 0 ;
V_14 -> V_20 = 0 ;
F_58 ( V_14 -> V_68 ) ;
V_14 -> V_68 = NULL ;
V_48 -> V_54 [ V_14 -> V_29 ] . V_69 -- ;
}
static void F_59 ( struct V_70 * V_71 )
{
struct V_1 * V_48 ;
V_48 = V_71 -> V_48 ;
F_37 ( & V_48 -> V_79 ) ;
if ( V_71 -> V_74 ) {
F_34 ( V_48 , V_71 -> V_74 , 1 ) ;
V_71 -> V_74 = NULL ;
}
if ( V_71 -> V_75 ) {
F_34 ( V_48 , V_71 -> V_75 , 1 ) ;
V_71 -> V_75 = NULL ;
}
V_71 -> V_48 = NULL ;
F_38 ( & V_48 -> V_79 ) ;
F_60 ( & V_48 -> V_96 ) ;
}
int F_61 ( struct V_70 * V_71 )
{
struct V_1 * V_48 ;
if ( F_36 ( ! V_71 ) )
return - V_59 ;
V_48 = V_71 -> V_48 ;
F_59 ( V_71 ) ;
F_40 ( V_48 -> V_3 -> V_78 ) ;
return 0 ;
}
static int F_62 ( struct V_80 * V_80 , struct V_6 * V_6 )
{
struct V_70 * V_71 ;
struct V_1 * V_48 ;
struct V_78 * V_78 ;
V_71 = V_6 -> V_102 ;
V_48 = V_71 -> V_48 ;
F_59 ( V_71 ) ;
F_14 ( V_71 ) ;
V_78 = V_48 -> V_3 -> V_78 ;
F_56 ( V_48 -> V_3 , V_6 ) ;
F_40 ( V_78 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 ,
struct F_63 * V_107 )
{
struct V_1 * V_48 ;
if ( V_14 == NULL )
return - V_61 ;
V_48 = V_14 -> V_48 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_3 = V_48 -> V_3 -> V_63 ;
V_107 -> V_4 = V_48 -> V_4 ;
V_107 -> V_49 = V_14 -> V_63 ;
V_107 -> V_29 = V_14 -> V_29 ;
V_107 -> V_39 = V_48 -> V_55 ;
strcpy ( V_107 -> V_108 , V_48 -> V_108 ) ;
strcpy ( V_107 -> V_109 , V_48 -> V_109 ) ;
strcpy ( V_107 -> V_110 , V_14 -> V_109 ) ;
V_107 -> V_111 = V_14 -> V_112 -> V_60 ;
V_107 -> V_113 = ( V_14 -> V_112 -> V_60 -
V_14 -> V_112 -> V_69 ) ;
return 0 ;
}
static int F_64 ( struct V_13 * V_14 ,
struct F_63 T_3 * V_114 )
{
struct F_63 V_107 ;
int V_41 ;
if ( ( V_41 = F_63 ( V_14 , & V_107 ) ) < 0 )
return V_41 ;
if ( F_65 ( V_114 , & V_107 , sizeof( struct F_63 ) ) )
return - V_115 ;
return 0 ;
}
int F_66 ( struct V_2 * V_3 , struct F_63 * V_107 )
{
struct V_1 * V_48 ;
struct V_52 * V_112 ;
struct V_13 * V_14 ;
F_37 ( & V_77 ) ;
V_48 = F_1 ( V_3 , V_107 -> V_4 ) ;
F_38 ( & V_77 ) ;
if ( ! V_48 )
return - V_59 ;
if ( V_107 -> V_29 < 0 || V_107 -> V_29 > 1 )
return - V_76 ;
V_112 = & V_48 -> V_54 [ V_107 -> V_29 ] ;
if ( V_112 -> V_60 == 0 )
return - V_116 ;
if ( V_107 -> V_49 >= V_112 -> V_60 )
return - V_59 ;
F_2 (substream, &pstr->substreams, list) {
if ( ( unsigned int ) V_14 -> V_63 == V_107 -> V_49 )
return F_63 ( V_14 , V_107 ) ;
}
return - V_59 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct F_63 T_3 * V_114 )
{
int V_41 ;
struct F_63 V_107 ;
if ( F_68 ( V_107 . V_4 , & V_114 -> V_4 ) )
return - V_115 ;
if ( F_68 ( V_107 . V_29 , & V_114 -> V_29 ) )
return - V_115 ;
if ( F_68 ( V_107 . V_49 , & V_114 -> V_49 ) )
return - V_115 ;
if ( ( V_41 = F_66 ( V_3 , & V_107 ) ) < 0 )
return V_41 ;
if ( F_65 ( V_114 , & V_107 , sizeof( struct F_63 ) ) )
return - V_115 ;
return 0 ;
}
int F_69 ( struct V_13 * V_14 ,
struct V_117 * V_118 )
{
char * V_119 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_14 -> V_65 > 1 )
return - V_99 ;
F_23 ( V_14 ) ;
if ( V_118 -> V_32 < 32 || V_118 -> V_32 > 1024L * 1024L ) {
return - V_76 ;
}
if ( V_118 -> V_18 < 1 || V_118 -> V_18 > V_118 -> V_32 ) {
return - V_76 ;
}
if ( V_118 -> V_32 != V_16 -> V_32 ) {
V_119 = F_13 ( V_118 -> V_32 , V_25 ) ;
if ( ! V_119 )
return - V_26 ;
F_14 ( V_16 -> V_34 ) ;
V_16 -> V_34 = V_119 ;
V_16 -> V_32 = V_118 -> V_32 ;
V_16 -> V_17 = V_16 -> V_32 ;
}
V_16 -> V_18 = V_118 -> V_18 ;
V_14 -> V_67 = ! V_118 -> V_120 ;
return 0 ;
}
int F_70 ( struct V_13 * V_14 ,
struct V_117 * V_118 )
{
char * V_119 ;
struct V_15 * V_16 = V_14 -> V_16 ;
F_28 ( V_14 ) ;
if ( V_118 -> V_32 < 32 || V_118 -> V_32 > 1024L * 1024L ) {
return - V_76 ;
}
if ( V_118 -> V_18 < 1 || V_118 -> V_18 > V_118 -> V_32 ) {
return - V_76 ;
}
if ( V_118 -> V_32 != V_16 -> V_32 ) {
V_119 = F_13 ( V_118 -> V_32 , V_25 ) ;
if ( ! V_119 )
return - V_26 ;
F_14 ( V_16 -> V_34 ) ;
V_16 -> V_34 = V_119 ;
V_16 -> V_32 = V_118 -> V_32 ;
}
V_16 -> V_18 = V_118 -> V_18 ;
return 0 ;
}
static int F_71 ( struct V_13 * V_14 ,
struct V_121 * V_122 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_29 = V_56 ;
F_72 ( & V_16 -> V_27 ) ;
V_122 -> V_17 = V_16 -> V_17 ;
F_73 ( & V_16 -> V_27 ) ;
return 0 ;
}
static int F_74 ( struct V_13 * V_14 ,
struct V_121 * V_122 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
V_122 -> V_29 = V_30 ;
F_72 ( & V_16 -> V_27 ) ;
V_122 -> V_17 = V_16 -> V_17 ;
V_122 -> V_123 = V_16 -> V_123 ;
V_16 -> V_123 = 0 ;
F_73 ( & V_16 -> V_27 ) ;
return 0 ;
}
static long F_75 ( struct V_6 * V_6 , unsigned int V_124 , unsigned long V_125 )
{
struct V_70 * V_71 ;
void T_3 * V_126 = ( void T_3 * ) V_125 ;
V_71 = V_6 -> V_102 ;
if ( ( ( V_124 >> 8 ) & 0xff ) != 'W' )
return - V_127 ;
switch ( V_124 ) {
case V_128 :
return F_76 ( V_129 , ( int T_3 * ) V_126 ) ? - V_115 : 0 ;
case V_130 :
{
int V_29 ;
struct F_63 T_3 * V_107 = V_126 ;
if ( F_68 ( V_29 , & V_107 -> V_29 ) )
return - V_115 ;
switch ( V_29 ) {
case V_30 :
return F_64 ( V_71 -> V_74 , V_107 ) ;
case V_56 :
return F_64 ( V_71 -> V_75 , V_107 ) ;
default:
return - V_76 ;
}
}
case V_131 :
{
struct V_117 V_118 ;
if ( F_77 ( & V_118 , V_126 , sizeof( struct V_117 ) ) )
return - V_115 ;
switch ( V_118 . V_29 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_69 ( V_71 -> V_75 , & V_118 ) ;
case V_30 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
return F_70 ( V_71 -> V_74 , & V_118 ) ;
default:
return - V_76 ;
}
}
case V_132 :
{
int V_41 = 0 ;
struct V_121 V_122 ;
if ( F_77 ( & V_122 , V_126 , sizeof( struct V_121 ) ) )
return - V_115 ;
switch ( V_122 . V_29 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
V_41 = F_71 ( V_71 -> V_75 , & V_122 ) ;
break;
case V_30 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
V_41 = F_74 ( V_71 -> V_74 , & V_122 ) ;
break;
default:
return - V_76 ;
}
if ( V_41 < 0 )
return V_41 ;
if ( F_65 ( V_126 , & V_122 , sizeof( struct V_121 ) ) )
return - V_115 ;
return 0 ;
}
case V_133 :
{
int V_134 ;
if ( F_68 ( V_134 , ( int T_3 * ) V_126 ) )
return - V_115 ;
switch ( V_134 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_20 ( V_71 -> V_75 ) ;
default:
return - V_76 ;
}
}
case V_135 :
{
int V_134 ;
if ( F_68 ( V_134 , ( int T_3 * ) V_126 ) )
return - V_115 ;
switch ( V_134 ) {
case V_56 :
if ( V_71 -> V_75 == NULL )
return - V_76 ;
return F_23 ( V_71 -> V_75 ) ;
case V_30 :
if ( V_71 -> V_74 == NULL )
return - V_76 ;
return F_28 ( V_71 -> V_74 ) ;
default:
return - V_76 ;
}
}
#ifdef F_78
default:
F_26 ( V_46 L_2 , V_124 ) ;
#endif
}
return - V_127 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_85 * V_136 ,
unsigned int V_124 ,
unsigned long V_125 )
{
void T_3 * V_126 = ( void T_3 * ) V_125 ;
switch ( V_124 ) {
case V_137 :
{
int V_4 ;
if ( F_68 ( V_4 , ( int T_3 * ) V_126 ) )
return - V_115 ;
if ( V_4 >= V_138 )
V_4 = V_138 - 1 ;
F_37 ( & V_77 ) ;
V_4 = V_4 < 0 ? 0 : V_4 + 1 ;
while ( V_4 < V_138 ) {
if ( F_1 ( V_3 , V_4 ) )
break;
V_4 ++ ;
}
if ( V_4 == V_138 )
V_4 = - 1 ;
F_38 ( & V_77 ) ;
if ( F_76 ( V_4 , ( int T_3 * ) V_126 ) )
return - V_115 ;
return 0 ;
}
case V_139 :
{
int V_134 ;
if ( F_68 ( V_134 , ( int T_3 * ) V_126 ) )
return - V_115 ;
V_136 -> V_98 = V_134 ;
return 0 ;
}
case V_140 :
return F_67 ( V_3 , V_126 ) ;
}
return - V_141 ;
}
int F_80 ( struct V_13 * V_14 ,
const unsigned char * V_34 , int V_19 )
{
unsigned long V_39 ;
int V_142 = 0 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_38 )
return - V_144 ;
if ( V_16 -> V_34 == NULL ) {
F_81 ( L_3 ) ;
return - V_76 ;
}
F_21 ( & V_16 -> V_27 , V_39 ) ;
if ( V_19 == 1 ) {
V_14 -> V_145 ++ ;
if ( V_16 -> V_17 < V_16 -> V_32 ) {
V_16 -> V_34 [ V_16 -> V_36 ++ ] = V_34 [ 0 ] ;
V_16 -> V_36 %= V_16 -> V_32 ;
V_16 -> V_17 ++ ;
V_142 ++ ;
} else {
V_16 -> V_123 ++ ;
}
} else {
V_14 -> V_145 += V_19 ;
V_143 = V_16 -> V_32 - V_16 -> V_36 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_32 - V_16 -> V_17 ) )
V_143 = V_16 -> V_32 - V_16 -> V_17 ;
memcpy ( V_16 -> V_34 + V_16 -> V_36 , V_34 , V_143 ) ;
V_16 -> V_36 += V_143 ;
V_16 -> V_36 %= V_16 -> V_32 ;
V_16 -> V_17 += V_143 ;
V_19 -= V_143 ;
V_142 += V_143 ;
if ( V_19 > 0 ) {
V_34 += V_143 ;
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_32 - V_16 -> V_17 ) ) {
V_143 = V_16 -> V_32 - V_16 -> V_17 ;
V_16 -> V_123 += V_19 - V_143 ;
}
if ( V_143 > 0 ) {
memcpy ( V_16 -> V_34 , V_34 , V_143 ) ;
V_16 -> V_36 = V_143 ;
V_16 -> V_17 += V_143 ;
V_142 += V_143 ;
}
}
}
if ( V_142 > 0 ) {
if ( V_16 -> V_22 )
F_17 ( & V_16 -> V_31 ) ;
else if ( F_4 ( V_14 ) )
F_60 ( & V_16 -> V_28 ) ;
}
F_22 ( & V_16 -> V_27 , V_39 ) ;
return V_142 ;
}
static long F_82 ( struct V_13 * V_14 ,
unsigned char T_3 * V_146 ,
unsigned char * V_147 , long V_19 )
{
unsigned long V_39 ;
long V_142 = 0 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
while ( V_19 > 0 && V_16 -> V_17 ) {
V_143 = V_16 -> V_32 - V_16 -> V_35 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
F_21 ( & V_16 -> V_27 , V_39 ) ;
if ( V_143 > ( int ) V_16 -> V_17 )
V_143 = V_16 -> V_17 ;
if ( V_147 )
memcpy ( V_147 + V_142 , V_16 -> V_34 + V_16 -> V_35 , V_143 ) ;
if ( V_146 ) {
F_22 ( & V_16 -> V_27 , V_39 ) ;
if ( F_65 ( V_146 + V_142 ,
V_16 -> V_34 + V_16 -> V_35 , V_143 ) ) {
return V_142 > 0 ? V_142 : - V_115 ;
}
F_21 ( & V_16 -> V_27 , V_39 ) ;
}
V_16 -> V_35 += V_143 ;
V_16 -> V_35 %= V_16 -> V_32 ;
V_16 -> V_17 -= V_143 ;
F_22 ( & V_16 -> V_27 , V_39 ) ;
V_142 += V_143 ;
V_19 -= V_143 ;
}
return V_142 ;
}
long F_83 ( struct V_13 * V_14 ,
unsigned char * V_104 , long V_19 )
{
F_19 ( V_14 , 1 ) ;
return F_82 ( V_14 , NULL , V_104 , V_19 ) ;
}
static T_4 F_84 ( struct V_6 * V_6 , char T_3 * V_104 , T_1 V_19 ,
T_5 * V_148 )
{
long V_142 ;
int V_143 ;
struct V_70 * V_71 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_71 = V_6 -> V_102 ;
V_14 = V_71 -> V_74 ;
if ( V_14 == NULL )
return - V_47 ;
V_16 = V_14 -> V_16 ;
F_19 ( V_14 , 1 ) ;
V_142 = 0 ;
while ( V_19 > 0 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( ! F_4 ( V_14 ) ) {
T_2 V_84 ;
if ( ( V_6 -> V_87 & V_89 ) != 0 || V_142 > 0 ) {
F_73 ( & V_16 -> V_27 ) ;
return V_142 > 0 ? V_142 : - V_64 ;
}
F_49 ( & V_84 , V_44 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_53 ( V_100 ) ;
F_73 ( & V_16 -> V_27 ) ;
F_54 () ;
F_55 ( & V_16 -> V_28 , & V_84 ) ;
if ( F_25 ( V_44 ) )
return V_142 > 0 ? V_142 : - V_45 ;
if ( ! V_16 -> V_17 )
return V_142 > 0 ? V_142 : - V_47 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
V_143 = F_82 ( V_14 ,
( unsigned char T_3 * ) V_104 ,
NULL ,
V_19 ) ;
if ( V_143 < 0 )
return V_142 > 0 ? V_142 : V_143 ;
V_142 += V_143 ;
V_104 += V_143 ;
V_19 -= V_143 ;
}
return V_142 ;
}
int F_85 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_142 ;
unsigned long V_39 ;
if ( V_16 -> V_34 == NULL ) {
F_81 ( L_4 ) ;
return 1 ;
}
F_21 ( & V_16 -> V_27 , V_39 ) ;
V_142 = V_16 -> V_17 >= V_16 -> V_32 ;
F_22 ( & V_16 -> V_27 , V_39 ) ;
return V_142 ;
}
int F_86 ( struct V_13 * V_14 ,
unsigned char * V_34 , int V_19 )
{
unsigned long V_39 ;
int V_142 , V_143 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_34 == NULL ) {
F_81 ( L_5 ) ;
return - V_76 ;
}
V_142 = 0 ;
F_21 ( & V_16 -> V_27 , V_39 ) ;
if ( V_16 -> V_17 >= V_16 -> V_32 ) {
goto V_149;
}
if ( V_19 == 1 ) {
* V_34 = V_16 -> V_34 [ V_16 -> V_36 ] ;
V_142 ++ ;
} else {
V_143 = V_16 -> V_32 - V_16 -> V_36 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( int ) ( V_16 -> V_32 - V_16 -> V_17 ) )
V_143 = V_16 -> V_32 - V_16 -> V_17 ;
memcpy ( V_34 , V_16 -> V_34 + V_16 -> V_36 , V_143 ) ;
V_19 -= V_143 ;
V_142 += V_143 ;
if ( V_19 > 0 ) {
if ( V_19 > ( int ) ( V_16 -> V_32 - V_16 -> V_17 - V_143 ) )
V_19 = V_16 -> V_32 - V_16 -> V_17 - V_143 ;
memcpy ( V_34 + V_143 , V_16 -> V_34 , V_19 ) ;
V_142 += V_19 ;
}
}
V_149:
F_22 ( & V_16 -> V_27 , V_39 ) ;
return V_142 ;
}
int F_87 ( struct V_13 * V_14 , int V_19 )
{
unsigned long V_39 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_16 -> V_34 == NULL ) {
F_81 ( L_6 ) ;
return - V_76 ;
}
F_21 ( & V_16 -> V_27 , V_39 ) ;
F_36 ( V_16 -> V_17 + V_19 > V_16 -> V_32 ) ;
V_16 -> V_36 += V_19 ;
V_16 -> V_36 %= V_16 -> V_32 ;
V_16 -> V_17 += V_19 ;
V_14 -> V_145 += V_19 ;
if ( V_19 > 0 ) {
if ( V_16 -> V_40 || F_4 ( V_14 ) )
F_60 ( & V_16 -> V_28 ) ;
}
F_22 ( & V_16 -> V_27 , V_39 ) ;
return V_19 ;
}
int F_88 ( struct V_13 * V_14 ,
unsigned char * V_34 , int V_19 )
{
if ( ! V_14 -> V_38 )
return - V_144 ;
V_19 = F_86 ( V_14 , V_34 , V_19 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_87 ( V_14 , V_19 ) ;
}
static long F_89 ( struct V_13 * V_14 ,
const unsigned char T_3 * V_146 ,
const unsigned char * V_147 ,
long V_19 )
{
unsigned long V_39 ;
long V_143 , V_142 ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( F_36 ( ! V_147 && ! V_146 ) )
return - V_76 ;
if ( F_36 ( ! V_16 -> V_34 ) )
return - V_76 ;
V_142 = 0 ;
F_21 ( & V_16 -> V_27 , V_39 ) ;
if ( V_14 -> V_20 ) {
if ( ( long ) V_16 -> V_17 < V_19 ) {
F_22 ( & V_16 -> V_27 , V_39 ) ;
return - V_64 ;
}
}
while ( V_19 > 0 && V_16 -> V_17 > 0 ) {
V_143 = V_16 -> V_32 - V_16 -> V_35 ;
if ( V_143 > V_19 )
V_143 = V_19 ;
if ( V_143 > ( long ) V_16 -> V_17 )
V_143 = V_16 -> V_17 ;
if ( V_147 )
memcpy ( V_16 -> V_34 + V_16 -> V_35 ,
V_147 + V_142 , V_143 ) ;
else if ( V_146 ) {
F_22 ( & V_16 -> V_27 , V_39 ) ;
if ( F_77 ( V_16 -> V_34 + V_16 -> V_35 ,
V_146 + V_142 , V_143 ) ) {
F_21 ( & V_16 -> V_27 , V_39 ) ;
V_142 = V_142 > 0 ? V_142 : - V_115 ;
goto V_150;
}
F_21 ( & V_16 -> V_27 , V_39 ) ;
}
V_16 -> V_35 += V_143 ;
V_16 -> V_35 %= V_16 -> V_32 ;
V_16 -> V_17 -= V_143 ;
V_142 += V_143 ;
V_19 -= V_143 ;
}
V_150:
V_143 = V_16 -> V_17 < V_16 -> V_32 ;
F_22 ( & V_16 -> V_27 , V_39 ) ;
if ( V_143 )
F_16 ( V_14 , 1 ) ;
return V_142 ;
}
long F_57 ( struct V_13 * V_14 ,
const unsigned char * V_104 , long V_19 )
{
return F_89 ( V_14 , NULL , V_104 , V_19 ) ;
}
static T_4 F_90 ( struct V_6 * V_6 , const char T_3 * V_104 ,
T_1 V_19 , T_5 * V_148 )
{
long V_142 , V_42 ;
int V_143 ;
struct V_70 * V_71 ;
struct V_15 * V_16 ;
struct V_13 * V_14 ;
V_71 = V_6 -> V_102 ;
V_14 = V_71 -> V_75 ;
V_16 = V_14 -> V_16 ;
if ( V_14 -> V_20 && V_19 > V_16 -> V_32 )
return - V_47 ;
V_142 = 0 ;
while ( V_19 > 0 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( ! F_5 ( V_14 , V_19 ) ) {
T_2 V_84 ;
if ( V_6 -> V_87 & V_89 ) {
F_73 ( & V_16 -> V_27 ) ;
return V_142 > 0 ? V_142 : - V_64 ;
}
F_49 ( & V_84 , V_44 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_53 ( V_100 ) ;
F_73 ( & V_16 -> V_27 ) ;
V_42 = F_91 ( 30 * V_43 ) ;
F_55 ( & V_16 -> V_28 , & V_84 ) ;
if ( F_25 ( V_44 ) )
return V_142 > 0 ? V_142 : - V_45 ;
if ( ! V_16 -> V_17 && ! V_42 )
return V_142 > 0 ? V_142 : - V_47 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
V_143 = F_89 ( V_14 , V_104 , NULL , V_19 ) ;
if ( V_143 < 0 )
return V_142 > 0 ? V_142 : V_143 ;
V_142 += V_143 ;
V_104 += V_143 ;
if ( ( T_1 ) V_143 < V_19 && ( V_6 -> V_87 & V_89 ) )
break;
V_19 -= V_143 ;
}
if ( V_6 -> V_87 & V_151 ) {
F_72 ( & V_16 -> V_27 ) ;
while ( V_16 -> V_17 != V_16 -> V_32 ) {
T_2 V_84 ;
unsigned int V_152 = V_16 -> V_17 ;
F_49 ( & V_84 , V_44 ) ;
F_50 ( & V_16 -> V_28 , & V_84 ) ;
F_53 ( V_100 ) ;
F_73 ( & V_16 -> V_27 ) ;
V_42 = F_91 ( 30 * V_43 ) ;
F_55 ( & V_16 -> V_28 , & V_84 ) ;
if ( F_25 ( V_44 ) )
return V_142 > 0 ? V_142 : - V_45 ;
if ( V_16 -> V_17 == V_152 && ! V_42 )
return V_142 > 0 ? V_142 : - V_47 ;
F_72 ( & V_16 -> V_27 ) ;
}
F_73 ( & V_16 -> V_27 ) ;
}
return V_142 ;
}
static unsigned int F_92 ( struct V_6 * V_6 , T_6 * V_84 )
{
struct V_70 * V_71 ;
struct V_15 * V_16 ;
unsigned int V_153 ;
V_71 = V_6 -> V_102 ;
if ( V_71 -> V_74 != NULL ) {
V_16 = V_71 -> V_74 -> V_16 ;
F_19 ( V_71 -> V_74 , 1 ) ;
F_93 ( V_6 , & V_16 -> V_28 , V_84 ) ;
}
if ( V_71 -> V_75 != NULL ) {
V_16 = V_71 -> V_75 -> V_16 ;
F_93 ( V_6 , & V_16 -> V_28 , V_84 ) ;
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
static void F_94 ( struct V_158 * V_159 ,
struct V_160 * V_34 )
{
struct V_1 * V_48 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_48 = V_159 -> V_102 ;
F_95 ( V_34 , L_7 , V_48 -> V_109 ) ;
F_37 ( & V_48 -> V_79 ) ;
if ( V_48 -> V_55 & V_57 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_OUTPUT].substreams,
list) {
F_95 ( V_34 ,
L_8
L_9 ,
V_14 -> V_63 ,
( unsigned long ) V_14 -> V_145 ) ;
if ( V_14 -> V_38 ) {
F_95 ( V_34 ,
L_10 ,
F_96 ( V_14 -> V_68 ) ) ;
V_16 = V_14 -> V_16 ;
F_95 ( V_34 ,
L_11
L_12
L_13 ,
V_16 -> V_101 ? L_14 : L_15 ,
( unsigned long ) V_16 -> V_32 ,
( unsigned long ) V_16 -> V_17 ) ;
}
}
}
if ( V_48 -> V_55 & V_58 ) {
F_2 (substream,
&rmidi->streams[SNDRV_RAWMIDI_STREAM_INPUT].substreams,
list) {
F_95 ( V_34 ,
L_16
L_17 ,
V_14 -> V_63 ,
( unsigned long ) V_14 -> V_145 ) ;
if ( V_14 -> V_38 ) {
F_95 ( V_34 ,
L_10 ,
F_96 ( V_14 -> V_68 ) ) ;
V_16 = V_14 -> V_16 ;
F_95 ( V_34 ,
L_12
L_13
L_18 ,
( unsigned long ) V_16 -> V_32 ,
( unsigned long ) V_16 -> V_17 ,
( unsigned long ) V_16 -> V_123 ) ;
}
}
}
F_38 ( & V_48 -> V_79 ) ;
}
static int F_97 ( struct V_1 * V_48 ,
struct V_52 * V_29 ,
int V_161 ,
int V_19 )
{
struct V_13 * V_14 ;
int V_162 ;
for ( V_162 = 0 ; V_162 < V_19 ; V_162 ++ ) {
V_14 = F_9 ( sizeof( * V_14 ) , V_25 ) ;
if ( V_14 == NULL ) {
F_26 ( V_163 L_19 ) ;
return - V_26 ;
}
V_14 -> V_29 = V_161 ;
V_14 -> V_63 = V_162 ;
V_14 -> V_48 = V_48 ;
V_14 -> V_112 = V_29 ;
F_98 ( & V_14 -> V_164 , & V_29 -> V_165 ) ;
V_29 -> V_60 ++ ;
}
return 0 ;
}
int F_99 ( struct V_2 * V_3 , char * V_108 , int V_4 ,
int V_166 , int V_167 ,
struct V_1 * * V_168 )
{
struct V_1 * V_48 ;
int V_41 ;
static struct V_169 V_23 = {
. V_170 = V_171 ,
. V_172 = V_173 ,
. V_174 = V_175 ,
} ;
if ( F_36 ( ! V_3 ) )
return - V_59 ;
if ( V_168 )
* V_168 = NULL ;
V_48 = F_9 ( sizeof( * V_48 ) , V_25 ) ;
if ( V_48 == NULL ) {
F_26 ( V_163 L_20 ) ;
return - V_26 ;
}
V_48 -> V_3 = V_3 ;
V_48 -> V_4 = V_4 ;
F_100 ( & V_48 -> V_79 ) ;
F_11 ( & V_48 -> V_96 ) ;
F_101 ( & V_48 -> V_54 [ V_30 ] . V_165 ) ;
F_101 ( & V_48 -> V_54 [ V_56 ] . V_165 ) ;
if ( V_108 != NULL )
F_102 ( V_48 -> V_108 , V_108 , sizeof( V_48 -> V_108 ) ) ;
if ( ( V_41 = F_97 ( V_48 ,
& V_48 -> V_54 [ V_30 ] ,
V_30 ,
V_167 ) ) < 0 ) {
F_103 ( V_48 ) ;
return V_41 ;
}
if ( ( V_41 = F_97 ( V_48 ,
& V_48 -> V_54 [ V_56 ] ,
V_56 ,
V_166 ) ) < 0 ) {
F_103 ( V_48 ) ;
return V_41 ;
}
if ( ( V_41 = F_104 ( V_3 , V_176 , V_48 , & V_23 ) ) < 0 ) {
F_103 ( V_48 ) ;
return V_41 ;
}
if ( V_168 )
* V_168 = V_48 ;
return 0 ;
}
static void F_105 ( struct V_52 * V_29 )
{
struct V_13 * V_14 ;
while ( ! F_106 ( & V_29 -> V_165 ) ) {
V_14 = F_107 ( V_29 -> V_165 . V_177 , struct V_13 , V_164 ) ;
F_108 ( & V_14 -> V_164 ) ;
F_14 ( V_14 ) ;
}
}
static int F_103 ( struct V_1 * V_48 )
{
if ( ! V_48 )
return 0 ;
F_109 ( V_48 -> V_178 ) ;
V_48 -> V_178 = NULL ;
F_37 ( & V_77 ) ;
if ( V_48 -> V_23 && V_48 -> V_23 -> V_179 )
V_48 -> V_23 -> V_179 ( V_48 ) ;
F_38 ( & V_77 ) ;
F_105 ( & V_48 -> V_54 [ V_30 ] ) ;
F_105 ( & V_48 -> V_54 [ V_56 ] ) ;
if ( V_48 -> V_106 )
V_48 -> V_106 ( V_48 ) ;
F_14 ( V_48 ) ;
return 0 ;
}
static int V_171 ( struct V_180 * V_4 )
{
struct V_1 * V_48 = V_4 -> V_181 ;
return F_103 ( V_48 ) ;
}
static void F_110 ( struct V_182 * V_4 )
{
struct V_1 * V_48 = V_4 -> V_102 ;
V_48 -> V_183 = NULL ;
}
static int V_173 ( struct V_180 * V_4 )
{
int V_41 ;
struct V_158 * V_159 ;
char V_109 [ 16 ] ;
struct V_1 * V_48 = V_4 -> V_181 ;
if ( V_48 -> V_4 >= V_138 )
return - V_26 ;
F_37 ( & V_77 ) ;
if ( F_1 ( V_48 -> V_3 , V_48 -> V_4 ) ) {
F_38 ( & V_77 ) ;
return - V_99 ;
}
F_98 ( & V_48 -> V_164 , & V_184 ) ;
sprintf ( V_109 , L_21 , V_48 -> V_3 -> V_63 , V_48 -> V_4 ) ;
if ( ( V_41 = F_111 ( V_91 ,
V_48 -> V_3 , V_48 -> V_4 ,
& V_185 , V_48 , V_109 ) ) < 0 ) {
F_26 ( V_163 L_22 , V_48 -> V_3 -> V_63 , V_48 -> V_4 ) ;
F_108 ( & V_48 -> V_164 ) ;
F_38 ( & V_77 ) ;
return V_41 ;
}
if ( V_48 -> V_23 && V_48 -> V_23 -> V_172 &&
( V_41 = V_48 -> V_23 -> V_172 ( V_48 ) ) < 0 ) {
F_112 ( V_91 , V_48 -> V_3 , V_48 -> V_4 ) ;
F_108 ( & V_48 -> V_164 ) ;
F_38 ( & V_77 ) ;
return V_41 ;
}
#ifdef F_46
V_48 -> V_186 = 0 ;
if ( ( int ) V_48 -> V_4 == V_187 [ V_48 -> V_3 -> V_63 ] ) {
if ( F_113 ( V_93 ,
V_48 -> V_3 , 0 , & V_185 ,
V_48 , V_109 ) < 0 ) {
F_26 ( V_163 L_23 , V_48 -> V_3 -> V_63 , 0 ) ;
} else {
V_48 -> V_186 ++ ;
#ifdef F_114
F_115 ( F_114 , V_48 -> V_3 -> V_63 , V_48 -> V_109 ) ;
#endif
}
}
if ( ( int ) V_48 -> V_4 == V_188 [ V_48 -> V_3 -> V_63 ] ) {
if ( F_113 ( V_93 ,
V_48 -> V_3 , 1 , & V_185 ,
V_48 , V_109 ) < 0 ) {
F_26 ( V_163 L_23 , V_48 -> V_3 -> V_63 , 1 ) ;
} else {
V_48 -> V_186 ++ ;
}
}
#endif
F_38 ( & V_77 ) ;
sprintf ( V_109 , L_24 , V_48 -> V_4 ) ;
V_159 = F_116 ( V_48 -> V_3 , V_109 , V_48 -> V_3 -> V_189 ) ;
if ( V_159 ) {
V_159 -> V_102 = V_48 ;
V_159 -> V_190 . V_191 . V_192 = F_94 ;
if ( F_117 ( V_159 ) < 0 ) {
F_109 ( V_159 ) ;
V_159 = NULL ;
}
}
V_48 -> V_178 = V_159 ;
#if F_118 ( V_193 ) || ( F_118 ( V_194 ) && F_118 ( V_195 ) )
if ( ! V_48 -> V_23 || ! V_48 -> V_23 -> V_172 ) {
if ( F_119 ( V_48 -> V_3 , V_48 -> V_4 , V_196 , 0 , & V_48 -> V_183 ) >= 0 ) {
V_48 -> V_183 -> V_102 = V_48 ;
V_48 -> V_183 -> V_106 = F_110 ;
sprintf ( V_48 -> V_183 -> V_109 , L_25 , V_48 -> V_3 -> V_63 , V_48 -> V_4 ) ;
F_120 ( V_48 -> V_3 , V_48 -> V_183 ) ;
}
}
#endif
return 0 ;
}
static int V_175 ( struct V_180 * V_4 )
{
struct V_1 * V_48 = V_4 -> V_181 ;
F_37 ( & V_77 ) ;
F_121 ( & V_48 -> V_164 ) ;
#ifdef F_46
if ( V_48 -> V_186 ) {
if ( ( int ) V_48 -> V_4 == V_187 [ V_48 -> V_3 -> V_63 ] ) {
F_122 ( V_93 , V_48 -> V_3 , 0 ) ;
#ifdef F_114
F_123 ( F_114 , V_48 -> V_3 -> V_63 ) ;
#endif
}
if ( ( int ) V_48 -> V_4 == V_188 [ V_48 -> V_3 -> V_63 ] )
F_122 ( V_93 , V_48 -> V_3 , 1 ) ;
V_48 -> V_186 = 0 ;
}
#endif
F_112 ( V_91 , V_48 -> V_3 , V_48 -> V_4 ) ;
F_38 ( & V_77 ) ;
return 0 ;
}
void F_124 ( struct V_1 * V_48 , int V_29 ,
struct V_197 * V_23 )
{
struct V_13 * V_14 ;
F_2 (substream, &rmidi->streams[stream].substreams, list)
V_14 -> V_23 = V_23 ;
}
static int T_7 F_125 ( void )
{
F_126 ( F_79 ) ;
F_127 ( F_79 ) ;
#ifdef F_46
{ int V_198 ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ ) {
if ( V_187 [ V_198 ] < 0 || V_187 [ V_198 ] >= V_138 ) {
F_26 ( V_163 L_26 , V_198 , V_187 [ V_198 ] ) ;
V_187 [ V_198 ] = 0 ;
}
if ( V_188 [ V_198 ] < 0 || V_188 [ V_198 ] >= V_138 ) {
F_26 ( V_163 L_27 , V_198 , V_188 [ V_198 ] ) ;
V_188 [ V_198 ] = 1 ;
}
}
}
#endif
return 0 ;
}
static void T_8 F_128 ( void )
{
F_129 ( F_79 ) ;
F_130 ( F_79 ) ;
}
