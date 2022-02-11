void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 -> V_7 , 0 , V_8 ,
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
F_9 ( & V_2 -> V_27 ) ;
if ( ! F_10 ( V_2 ) ) {
F_11 ( & V_2 -> V_27 ) ;
return - V_28 ;
}
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_29 = V_30 ;
V_24 . V_31 = V_32 ;
sprintf ( V_25 , L_1 , V_2 -> V_10 ) ;
V_22 = F_12 ( V_2 , V_25 , 32 ,
1 , & V_24 ) ;
if ( V_22 == NULL ) {
F_13 ( V_33 L_2 ) ;
F_14 ( V_2 ) ;
F_11 ( & V_2 -> V_27 ) ;
return - V_34 ;
}
V_4 -> V_18 = V_22 ;
V_4 -> V_35 . V_36 = V_22 -> V_37 . V_36 ;
V_4 -> V_35 . V_38 = V_22 -> V_37 . V_38 ;
V_22 -> V_39 = V_4 ;
F_15 ( V_22 , V_4 -> V_40 ) ;
F_16 ( V_22 ) ;
F_11 ( & V_2 -> V_27 ) ;
return 0 ;
}
static void
F_15 ( struct V_21 * V_38 , int V_41 )
{
if ( V_41 ) {
V_38 -> V_42 = V_43 ;
V_38 -> V_44 = V_45 ;
V_38 -> V_46 = 0 ;
V_38 -> V_39 -> V_47 = V_48 ;
} else {
V_38 -> V_42 = V_49 ;
V_38 -> V_44 = 0 ;
V_38 -> V_46 = 32 ;
V_38 -> V_39 -> V_47 = V_50 ;
}
}
static int
F_17 ( struct V_19 * V_4 )
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
F_9 ( & V_2 -> V_27 ) ;
F_18 ( V_22 ) ;
F_19 ( V_2 -> V_51 , F_20 ( V_22 -> V_37 . V_38 ) ) ;
F_21 ( V_22 -> V_37 . V_36 , V_22 -> V_37 . V_38 ) ;
F_14 ( V_2 ) ;
F_11 ( & V_2 -> V_27 ) ;
return 0 ;
}
static int
F_22 ( struct V_19 * V_4 , int V_52 ,
const char T_1 * V_53 , int V_54 , int V_55 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_56 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_26 ;
if ( V_52 == V_57 )
V_56 = F_23 ( V_2 -> V_51 , V_53 , V_55 ,
F_20 ( V_22 -> V_37 . V_38 ) ) ;
else if ( V_52 == V_58 ) {
struct V_59 V_60 ;
if ( V_55 < ( int ) sizeof( V_60 ) )
V_56 = - V_61 ;
if ( F_24 ( & V_60 , V_53 , sizeof( V_60 ) ) )
V_56 = - V_28 ;
if ( V_60 . type >= V_62 &&
V_60 . type <= V_63 )
V_56 = F_25 ( V_2 -> V_51 , V_53 , V_55 , F_20 ( V_22 -> V_37 . V_38 ) ) ;
else {
if ( V_2 -> V_64 . V_65 )
V_56 = V_2 -> V_64 . V_65 ( V_2 , V_60 . type , V_60 . V_66 , V_53 , V_55 ) ;
else
V_56 = - V_61 ;
}
} else
V_56 = 0 ;
return V_56 ;
}
static int
F_26 ( struct V_19 * V_4 , unsigned int V_67 , unsigned long V_68 )
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
switch ( V_67 ) {
case V_69 :
F_27 ( V_2 -> V_51 ) ;
return 0 ;
case V_70 :
if ( V_2 -> V_71 )
return F_28 ( V_2 -> V_71 ) ;
return 0 ;
}
return 0 ;
}
static int
F_29 ( struct V_19 * V_4 )
{
struct V_21 * V_22 ;
if ( F_8 ( ! V_4 ) )
return - V_26 ;
V_22 = V_4 -> V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_26 ;
F_16 ( V_22 ) ;
return 0 ;
}
static int
V_32 ( struct V_72 * V_73 , int V_74 , void * V_18 ,
int V_75 , int V_76 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
unsigned char V_67 , * V_77 ;
V_22 = V_18 ;
if ( F_8 ( ! V_22 ) )
return - V_61 ;
V_2 = V_22 -> V_2 ;
if ( F_8 ( ! V_2 ) )
return - V_61 ;
if ( V_73 -> type != V_78 )
return F_30 ( V_73 , V_74 , V_18 , V_75 , V_76 ) ;
V_77 = V_73 -> V_77 . V_79 . V_80 ;
if ( V_77 [ 0 ] != 0xfe )
return 0 ;
V_67 = V_77 [ 2 ] & V_81 ;
if ( V_77 [ 2 ] & V_82 )
F_31 ( V_2 , V_22 , V_67 , V_77 , V_75 , V_76 ) ;
else
F_32 ( V_2 , V_22 , V_67 , V_77 , V_75 , V_76 ) ;
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_21 * V_38 , int V_67 ,
unsigned char * V_83 , int V_75 , int V_76 )
{
int V_84 ;
unsigned short V_85 ;
short V_86 ;
int V_87 ;
struct V_88 * V_89 ;
V_84 = V_83 [ 3 ] ;
if ( V_84 < 0 || V_84 >= V_38 -> V_37 . V_90 )
V_89 = NULL ;
else
V_89 = & V_38 -> V_37 . V_91 [ V_84 ] ;
V_85 = * ( unsigned short * ) & V_83 [ 4 ] ;
V_86 = * ( short * ) & V_83 [ 6 ] ;
switch ( V_67 ) {
#if 0
case _EMUX_OSS_REMOVE_LAST_SAMPLES:
snd_soundfont_remove_unlocked(emu->sflist);
break;
#endif
case V_92 :
if ( V_89 )
F_33 ( V_38 , V_89 , V_85 , V_86 ) ;
break;
case V_93 :
F_34 ( V_2 ) ;
break;
case V_94 :
break;
case V_95 :
break;
case V_96 :
F_35 ( V_2 , V_38 , V_84 , V_97 , 0 , V_75 , V_76 ) ;
break;
case V_98 :
F_35 ( V_2 , V_38 , V_84 , V_99 , 0 , V_75 , V_76 ) ;
break;
case V_100 :
if ( V_86 ) {
V_38 -> V_46 = ( short ) V_85 ;
F_36 ( V_38 , V_101 ) ;
}
break;
case V_102 :
if ( V_89 ) {
V_89 -> V_103 = V_85 ;
F_37 ( V_38 , V_89 , V_104 | V_105 ) ;
}
break;
case V_106 :
F_15 ( V_38 , V_85 ) ;
F_16 ( V_38 ) ;
break;
case V_107 :
V_38 -> V_44 = * ( unsigned int * ) & V_83 [ 4 ] ;
for ( V_87 = 0 ; V_87 < V_38 -> V_37 . V_90 ; V_87 ++ ) {
V_89 = & V_38 -> V_37 . V_91 [ V_87 ] ;
V_89 -> V_108 = ( ( V_38 -> V_44 >> V_87 ) & 1 ) ? 1 : 0 ;
}
break;
case V_109 :
if ( V_85 < V_110 )
V_38 -> V_111 [ V_85 ] = V_86 ;
break;
case V_112 :
break;
default:
if ( V_2 -> V_64 . V_113 )
V_2 -> V_64 . V_113 ( V_2 , V_67 , V_85 , V_86 ) ;
break;
}
}
static void
F_32 ( struct V_1 * V_2 , struct V_21 * V_38 , int V_67 ,
unsigned char * V_83 , int V_75 , int V_76 )
{
int V_84 ;
unsigned short V_85 ;
short V_86 ;
int V_114 ;
struct V_88 * V_89 ;
if ( V_38 -> V_42 != V_49 )
return;
if ( V_67 == V_115 )
return;
V_84 = V_83 [ 3 ] ;
if ( V_84 < 0 || V_84 >= V_38 -> V_37 . V_90 )
return;
V_89 = & V_38 -> V_37 . V_91 [ V_84 ] ;
V_85 = * ( unsigned short * ) & V_83 [ 4 ] ;
V_86 = * ( short * ) & V_83 [ 6 ] ;
V_114 = * ( int * ) & V_83 [ 4 ] ;
switch ( V_67 ) {
case V_116 :
V_89 -> V_117 = V_85 ;
return;
case V_118 :
V_89 -> V_119 [ V_120 ] = ( int ) V_85 << 3 ;
F_37 ( V_38 , V_89 , V_121 ) ;
return;
case V_122 :
case V_123 :
return;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
return;
case V_129 :
return;
case V_130 :
#ifdef F_38
F_39 ( V_38 , V_89 , V_131 ,
( short ) ( V_114 & 0x7fff ) ,
V_132 ) ;
F_39 ( V_38 , V_89 , V_133 ,
( V_114 >> 15 ) & 0xffff ,
V_132 ) ;
#endif
return;
}
}
static void
F_35 ( struct V_1 * V_2 , struct V_21 * V_38 , int V_134 , int V_135 , int V_136 , int V_75 , int V_76 )
{
struct V_72 V_73 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . type = V_137 ;
V_73 . V_77 . V_119 . V_138 = V_134 ;
V_73 . V_77 . V_119 . V_135 = V_135 ;
V_73 . V_77 . V_119 . V_139 = V_136 ;
F_30 ( & V_73 , 0 , V_38 , V_75 , V_76 ) ;
}
