void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 -> V_7 , 1 , V_8 ,
sizeof( struct V_3 ) , & V_6 ) < 0 )
return;
V_2 -> V_9 = V_6 ;
strcpy ( V_6 -> V_10 , V_2 -> V_10 ) ;
V_4 = F_3 ( V_6 ) ;
V_4 -> type = V_11 ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_2 -> V_15 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_2 ;
F_4 ( V_2 -> V_7 , V_6 ) ;
}
void
F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 ) {
F_6 ( V_2 -> V_7 , V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
}
static int
F_7 ( struct V_19 * V_4 , void * V_20 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_23 V_24 ;
char V_25 [ 64 ] ;
V_2 = V_20 ;
if ( F_8 ( ! V_4 || ! V_2 ) )
return - V_26 ;
if ( ! F_9 ( V_2 ) )
return - V_27 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_28 = V_29 ;
V_24 . V_30 = V_31 ;
sprintf ( V_25 , L_1 , V_2 -> V_10 ) ;
V_22 = F_10 ( V_2 , V_25 , 32 ,
1 , & V_24 ) ;
if ( V_22 == NULL ) {
F_11 ( V_32 L_2 ) ;
F_12 ( V_2 ) ;
return - V_33 ;
}
V_4 -> V_18 = V_22 ;
V_4 -> V_34 . V_35 = V_22 -> V_36 . V_35 ;
V_4 -> V_34 . V_37 = V_22 -> V_36 . V_37 ;
V_22 -> V_38 = V_4 ;
F_13 ( V_22 , V_4 -> V_39 ) ;
F_14 ( V_22 ) ;
return 0 ;
}
static void
F_13 ( struct V_21 * V_37 , int V_40 )
{
if ( V_40 ) {
V_37 -> V_41 = V_42 ;
V_37 -> V_43 = V_44 ;
V_37 -> V_45 = 0 ;
V_37 -> V_38 -> V_46 = V_47 ;
} else {
V_37 -> V_41 = V_48 ;
V_37 -> V_43 = 0 ;
V_37 -> V_45 = 32 ;
V_37 -> V_38 -> V_46 = V_49 ;
}
}
static int
F_15 ( struct V_19 * V_4 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_26 ;
F_16 ( V_22 ) ;
F_17 ( V_2 -> V_50 , F_18 ( V_22 -> V_36 . V_37 ) ) ;
F_19 ( V_22 -> V_36 . V_35 , V_22 -> V_36 . V_37 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int
F_20 ( struct V_19 * V_4 , int V_51 ,
const char T_1 * V_52 , int V_53 , int V_54 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_55 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_26 ;
if ( V_51 == V_56 )
V_55 = F_21 ( V_2 -> V_50 , V_52 , V_54 ,
F_18 ( V_22 -> V_36 . V_37 ) ) ;
else if ( V_51 == V_57 ) {
struct V_58 V_59 ;
if ( V_54 < ( int ) sizeof( V_59 ) )
return - V_60 ;
if ( F_22 ( & V_59 , V_52 , sizeof( V_59 ) ) )
return - V_27 ;
if ( V_59 . type >= V_61 &&
V_59 . type <= V_62 )
V_55 = F_23 ( V_2 -> V_50 , V_52 , V_54 , F_18 ( V_22 -> V_36 . V_37 ) ) ;
else {
if ( V_2 -> V_63 . V_64 )
V_55 = V_2 -> V_63 . V_64 ( V_2 , V_59 . type , V_59 . V_65 , V_52 , V_54 ) ;
else
V_55 = - V_60 ;
}
} else
V_55 = 0 ;
return V_55 ;
}
static int
F_24 ( struct V_19 * V_4 , unsigned int V_66 , unsigned long V_67 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_26 ;
switch ( V_66 ) {
case V_68 :
F_25 ( V_2 -> V_50 ) ;
return 0 ;
case V_69 :
if ( V_2 -> V_70 )
return F_26 ( V_2 -> V_70 ) ;
return 0 ;
}
return 0 ;
}
static int
F_27 ( struct V_19 * V_4 )
{
struct V_21 * V_22 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
F_14 ( V_22 ) ;
return 0 ;
}
static int
V_31 ( struct V_71 * V_72 , int V_73 , void * V_18 ,
int V_74 , int V_75 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned char V_66 , * V_76 ;
V_22 = V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_60 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_60 ;
if ( V_72 -> type != V_77 )
return F_28 ( V_72 , V_73 , V_18 , V_74 , V_75 ) ;
V_76 = V_72 -> V_76 . V_78 . V_79 ;
if ( V_76 [ 0 ] != 0xfe )
return 0 ;
V_66 = V_76 [ 2 ] & V_80 ;
if ( V_76 [ 2 ] & V_81 )
F_29 ( V_2 , V_22 , V_66 , V_76 , V_74 , V_75 ) ;
else
F_30 ( V_2 , V_22 , V_66 , V_76 , V_74 , V_75 ) ;
return 0 ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_21 * V_37 , int V_66 ,
unsigned char * V_82 , int V_74 , int V_75 )
{
int V_83 ;
unsigned short V_84 ;
short V_85 ;
int V_86 ;
struct V_87 * V_88 ;
V_83 = V_82 [ 3 ] ;
if ( V_83 < 0 || V_83 >= V_37 -> V_36 . V_89 )
V_88 = NULL ;
else
V_88 = & V_37 -> V_36 . V_90 [ V_83 ] ;
V_84 = * ( unsigned short * ) & V_82 [ 4 ] ;
V_85 = * ( short * ) & V_82 [ 6 ] ;
switch ( V_66 ) {
#if 0
case _EMUX_OSS_REMOVE_LAST_SAMPLES:
snd_soundfont_remove_unlocked(emu->sflist);
break;
#endif
case V_91 :
if ( V_88 )
F_31 ( V_37 , V_88 , V_84 , V_85 ) ;
break;
case V_92 :
F_32 ( V_2 ) ;
break;
case V_93 :
break;
case V_94 :
break;
case V_95 :
F_33 ( V_2 , V_37 , V_83 , V_96 , 0 , V_74 , V_75 ) ;
break;
case V_97 :
F_33 ( V_2 , V_37 , V_83 , V_98 , 0 , V_74 , V_75 ) ;
break;
case V_99 :
if ( V_85 ) {
V_37 -> V_45 = ( short ) V_84 ;
F_34 ( V_37 , V_100 ) ;
}
break;
case V_101 :
if ( V_88 ) {
V_88 -> V_102 = V_84 ;
F_35 ( V_37 , V_88 , V_103 | V_104 ) ;
}
break;
case V_105 :
F_13 ( V_37 , V_84 ) ;
F_14 ( V_37 ) ;
break;
case V_106 :
V_37 -> V_43 = * ( unsigned int * ) & V_82 [ 4 ] ;
for ( V_86 = 0 ; V_86 < V_37 -> V_36 . V_89 ; V_86 ++ ) {
V_88 = & V_37 -> V_36 . V_90 [ V_86 ] ;
V_88 -> V_107 = ( ( V_37 -> V_43 >> V_86 ) & 1 ) ? 1 : 0 ;
}
break;
case V_108 :
if ( V_84 < V_109 )
V_37 -> V_110 [ V_84 ] = V_85 ;
break;
case V_111 :
break;
default:
if ( V_2 -> V_63 . V_112 )
V_2 -> V_63 . V_112 ( V_2 , V_66 , V_84 , V_85 ) ;
break;
}
}
static void
F_30 ( struct V_1 * V_2 , struct V_21 * V_37 , int V_66 ,
unsigned char * V_82 , int V_74 , int V_75 )
{
int V_83 ;
unsigned short V_84 ;
short V_85 ;
int V_113 ;
struct V_87 * V_88 ;
if ( V_37 -> V_41 != V_48 )
return;
if ( V_66 == V_114 )
return;
V_83 = V_82 [ 3 ] ;
if ( V_83 < 0 || V_83 >= V_37 -> V_36 . V_89 )
return;
V_88 = & V_37 -> V_36 . V_90 [ V_83 ] ;
V_84 = * ( unsigned short * ) & V_82 [ 4 ] ;
V_85 = * ( short * ) & V_82 [ 6 ] ;
V_113 = * ( int * ) & V_82 [ 4 ] ;
switch ( V_66 ) {
case V_115 :
V_88 -> V_116 = V_84 ;
return;
case V_117 :
V_88 -> V_118 [ V_119 ] = ( int ) V_84 << 3 ;
F_35 ( V_37 , V_88 , V_120 ) ;
return;
case V_121 :
case V_122 :
return;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
return;
case V_128 :
return;
case V_129 :
#ifdef F_36
F_37 ( V_37 , V_88 , V_130 ,
( short ) ( V_113 & 0x7fff ) ,
V_131 ) ;
F_37 ( V_37 , V_88 , V_132 ,
( V_113 >> 15 ) & 0xffff ,
V_131 ) ;
#endif
return;
}
}
static void
F_33 ( struct V_1 * V_2 , struct V_21 * V_37 , int V_133 , int V_134 , int V_135 , int V_74 , int V_75 )
{
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . type = V_136 ;
V_72 . V_76 . V_118 . V_137 = V_133 ;
V_72 . V_76 . V_118 . V_134 = V_134 ;
V_72 . V_76 . V_118 . V_138 = V_135 ;
F_28 ( & V_72 , 0 , V_37 , V_74 , V_75 ) ;
}
