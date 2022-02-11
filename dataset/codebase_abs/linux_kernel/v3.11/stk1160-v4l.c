static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
static struct V_4 V_5 [] = {
{ V_6 , 0x0000 } ,
{ V_7 , 0x0000 } ,
{ V_8 , 0x0003 } ,
{ V_9 , 0x0000 } ,
{ V_10 , 0x05a0 } ,
{ V_11 , 0x0005 } ,
{ V_12 , 0x00f3 } ,
{ V_13 , 0x0000 } ,
{ 0xffff , 0xffff }
} ;
static struct V_4 V_14 [] = {
{ V_15 , 0x0000 } ,
{ V_15 + 1 , 0x0000 } ,
{ V_15 + 2 , 0x0001 } ,
{ V_15 + 3 , 0x0000 } ,
{ V_16 , 0x05a0 } ,
{ V_16 + 1 , 0x0005 } ,
{ V_16 + 2 , 0x0121 } ,
{ V_16 + 3 , 0x0001 } ,
{ 0xffff , 0xffff }
} ;
if ( V_2 -> V_17 & V_18 ) {
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_5 [ V_3 ] . V_19 != 0xffff ; V_3 ++ )
F_3 ( V_2 , V_5 [ V_3 ] . V_19 , V_5 [ V_3 ] . V_20 ) ;
} else {
F_2 ( L_2 ) ;
for ( V_3 = 0 ; V_14 [ V_3 ] . V_19 != 0xffff ; V_3 ++ )
F_3 ( V_2 , V_14 [ V_3 ] . V_19 , V_14 [ V_3 ] . V_20 ) ;
}
}
static bool F_4 ( struct V_1 * V_2 )
{
int V_3 , V_21 = V_2 -> V_22 ;
unsigned int V_23 ;
bool V_24 ;
V_23 = V_25 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_26 ; V_3 ++ ) {
if ( V_2 -> V_27 [ V_3 ] >= V_23 ) {
V_2 -> V_22 = V_3 ;
break;
} else if ( V_2 -> V_27 [ V_3 ] >
V_2 -> V_27 [ V_2 -> V_22 ] )
V_2 -> V_22 = V_3 ;
}
F_5 ( L_3 , V_2 -> V_22 ) ;
if ( V_2 -> V_22 != V_21 ) {
F_2 ( L_4 ,
V_23 , V_2 -> V_22 ) ;
F_2 ( L_5 ,
V_2 -> V_22 , V_2 -> V_27 [ V_2 -> V_22 ] ) ;
F_6 ( V_2 -> V_28 , 0 , V_2 -> V_22 ) ;
}
V_24 = V_2 -> V_29 != V_2 -> V_27 [ V_2 -> V_22 ] ;
V_2 -> V_29 = V_2 -> V_27 [ V_2 -> V_22 ] ;
return V_24 ;
}
static int F_7 ( struct V_1 * V_2 )
{
bool V_24 ;
int V_30 = 0 ;
int V_3 ;
if ( ! V_2 -> V_28 )
return - V_31 ;
if ( F_8 ( & V_2 -> V_32 ) )
return - V_33 ;
V_24 = F_4 ( V_2 ) ;
if ( ! V_2 -> V_34 . V_35 || V_24 ) {
V_30 = F_9 ( V_2 ) ;
if ( V_30 < 0 )
goto V_36;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_34 . V_35 ; V_3 ++ ) {
V_30 = F_10 ( V_2 -> V_34 . V_37 [ V_3 ] , V_38 ) ;
if ( V_30 ) {
F_11 ( L_6 , V_3 , V_30 ) ;
goto V_39;
}
}
F_12 ( & V_2 -> V_40 , 0 , V_41 , V_42 , 1 ) ;
F_3 ( V_2 , V_43 , 0xb3 ) ;
F_3 ( V_2 , V_43 + 3 , 0x00 ) ;
F_2 ( L_7 ) ;
F_13 ( & V_2 -> V_32 ) ;
return 0 ;
V_39:
F_14 ( V_2 ) ;
V_36:
F_6 ( V_2 -> V_28 , 0 , 0 ) ;
F_15 ( V_2 ) ;
F_13 ( & V_2 -> V_32 ) ;
return V_30 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_28 )
return;
V_2 -> V_22 = 0 ;
F_5 ( L_3 , V_2 -> V_22 ) ;
F_6 ( V_2 -> V_28 , 0 , 0 ) ;
F_3 ( V_2 , V_43 , 0x00 ) ;
F_3 ( V_2 , V_43 + 3 , 0x00 ) ;
F_12 ( & V_2 -> V_40 , 0 , V_41 , V_42 , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( F_8 ( & V_2 -> V_32 ) )
return - V_33 ;
F_18 ( V_2 ) ;
if ( ! V_44 )
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
F_2 ( L_8 ) ;
F_13 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_45 * V_45 ,
void * V_46 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
strcpy ( V_48 -> V_49 , L_9 ) ;
strcpy ( V_48 -> V_50 , L_9 ) ;
F_22 ( V_2 -> V_28 , V_48 -> V_51 , sizeof( V_48 -> V_51 ) ) ;
V_48 -> V_52 =
V_53 |
V_54 |
V_55 ;
V_48 -> V_56 = V_48 -> V_52 | V_57 ;
return 0 ;
}
static int F_23 ( struct V_45 * V_45 , void * V_46 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_60 != 0 )
return - V_61 ;
F_24 ( V_59 -> V_62 , V_63 [ V_59 -> V_60 ] . V_64 , sizeof( V_59 -> V_62 ) ) ;
V_59 -> V_65 = V_63 [ V_59 -> V_60 ] . V_66 ;
return 0 ;
}
static int F_25 ( struct V_45 * V_45 , void * V_46 ,
struct V_67 * V_59 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
V_59 -> V_68 . V_69 . V_70 = V_2 -> V_70 ;
V_59 -> V_68 . V_69 . V_71 = V_2 -> V_71 ;
V_59 -> V_68 . V_69 . V_72 = V_73 ;
V_59 -> V_68 . V_69 . V_65 = V_2 -> V_68 -> V_66 ;
V_59 -> V_68 . V_69 . V_74 = V_2 -> V_70 * 2 ;
V_59 -> V_68 . V_69 . V_75 = V_2 -> V_71 * V_59 -> V_68 . V_69 . V_74 ;
V_59 -> V_68 . V_69 . V_76 = V_77 ;
return 0 ;
}
static int F_26 ( struct V_45 * V_45 , void * V_46 ,
struct V_67 * V_59 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
V_59 -> V_68 . V_69 . V_65 = V_2 -> V_68 -> V_66 ;
V_59 -> V_68 . V_69 . V_70 = V_2 -> V_70 ;
V_59 -> V_68 . V_69 . V_71 = V_2 -> V_71 ;
V_59 -> V_68 . V_69 . V_72 = V_73 ;
V_59 -> V_68 . V_69 . V_74 = V_2 -> V_70 * 2 ;
V_59 -> V_68 . V_69 . V_75 = V_2 -> V_71 * V_59 -> V_68 . V_69 . V_74 ;
V_59 -> V_68 . V_69 . V_76 = V_77 ;
return 0 ;
}
static int F_27 ( struct V_45 * V_45 , void * V_46 ,
struct V_67 * V_59 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
struct V_78 * V_79 = & V_2 -> V_80 ;
if ( F_28 ( V_79 ) )
return - V_81 ;
F_26 ( V_45 , V_46 , V_59 ) ;
return 0 ;
}
static int F_29 ( struct V_45 * V_45 , void * V_46 , T_1 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
F_12 ( & V_2 -> V_40 , 0 , V_41 , V_82 , V_17 ) ;
return 0 ;
}
static int F_30 ( struct V_45 * V_45 , void * V_46 , T_1 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
* V_17 = V_2 -> V_17 ;
return 0 ;
}
static int F_31 ( struct V_45 * V_45 , void * V_46 , T_1 V_17 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
struct V_78 * V_79 = & V_2 -> V_80 ;
if ( F_28 ( V_79 ) )
return - V_81 ;
if ( ! V_2 -> V_28 )
return - V_31 ;
V_2 -> V_17 = V_17 ;
if ( V_2 -> V_17 & V_18 ) {
V_2 -> V_70 = 720 ;
V_2 -> V_71 = 480 ;
} else if ( V_2 -> V_17 & V_83 ) {
V_2 -> V_70 = 720 ;
V_2 -> V_71 = 576 ;
} else {
F_11 ( L_10 ) ;
return - V_61 ;
}
F_1 ( V_2 ) ;
F_12 ( & V_2 -> V_40 , 0 , V_84 , V_85 ,
V_2 -> V_17 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_45 , void * V_46 ,
struct V_86 * V_3 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
if ( V_3 -> V_60 > V_87 )
return - V_61 ;
if ( V_3 -> V_60 == V_88 )
sprintf ( V_3 -> V_64 , L_11 ) ;
else
sprintf ( V_3 -> V_64 , L_12 , V_3 -> V_60 ) ;
V_3 -> type = V_89 ;
V_3 -> V_90 = V_2 -> V_91 . V_92 ;
return 0 ;
}
static int F_33 ( struct V_45 * V_45 , void * V_46 , unsigned int * V_3 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
* V_3 = V_2 -> V_93 ;
return 0 ;
}
static int F_34 ( struct V_45 * V_45 , void * V_46 , unsigned int V_3 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
if ( F_28 ( & V_2 -> V_80 ) )
return - V_81 ;
if ( V_3 > V_87 )
return - V_61 ;
V_2 -> V_93 = V_3 ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_45 * V_45 , void * V_46 ,
struct V_94 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_30 ;
T_2 V_20 ;
V_30 = F_37 ( V_2 , V_19 -> V_19 , & V_20 ) ;
V_19 -> V_20 = V_20 ;
V_19 -> V_95 = 1 ;
return V_30 ;
}
static int F_38 ( struct V_45 * V_45 , void * V_46 ,
const struct V_94 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
return F_3 ( V_2 , V_19 -> V_19 , F_39 ( V_19 -> V_20 ) ) ;
}
static int F_40 ( struct V_78 * V_96 , const struct V_67 * V_97 ,
unsigned int * V_98 , unsigned int * V_99 ,
unsigned int V_100 [] , void * V_101 [] )
{
struct V_1 * V_2 = F_41 ( V_96 ) ;
unsigned long V_95 ;
V_95 = V_2 -> V_70 * V_2 -> V_71 * 2 ;
* V_98 = F_42 (unsigned int, *nbuffers,
STK1160_MIN_VIDEO_BUFFERS, STK1160_MAX_VIDEO_BUFFERS) ;
* V_99 = 1 ;
V_100 [ 0 ] = V_95 ;
F_5 ( L_13 ,
V_102 , * V_98 , V_95 ) ;
return 0 ;
}
static void F_43 ( struct V_103 * V_104 )
{
unsigned long V_105 ;
struct V_1 * V_2 = F_41 ( V_104 -> V_78 ) ;
struct V_106 * V_107 =
F_44 ( V_104 , struct V_106 , V_104 ) ;
F_45 ( & V_2 -> V_108 , V_105 ) ;
if ( ! V_2 -> V_28 ) {
F_46 ( & V_107 -> V_104 , V_109 ) ;
} else {
V_107 -> V_110 = F_47 ( V_104 , 0 ) ;
V_107 -> V_111 = F_48 ( V_104 , 0 ) ;
V_107 -> V_112 = 0 ;
V_107 -> V_113 = 0 ;
if ( V_107 -> V_111 < V_2 -> V_70 * V_2 -> V_71 * 2 )
F_46 ( & V_107 -> V_104 , V_109 ) ;
else
F_49 ( & V_107 -> V_114 , & V_2 -> V_115 ) ;
}
F_50 ( & V_2 -> V_108 , V_105 ) ;
}
static int F_51 ( struct V_78 * V_96 , unsigned int V_116 )
{
struct V_1 * V_2 = F_41 ( V_96 ) ;
return F_7 ( V_2 ) ;
}
static int F_52 ( struct V_78 * V_96 )
{
struct V_1 * V_2 = F_41 ( V_96 ) ;
return F_17 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_106 * V_107 ;
unsigned long V_105 ;
F_45 ( & V_2 -> V_108 , V_105 ) ;
while ( ! F_53 ( & V_2 -> V_115 ) ) {
V_107 = F_54 ( & V_2 -> V_115 ,
struct V_106 , V_114 ) ;
F_55 ( & V_107 -> V_114 ) ;
F_46 ( & V_107 -> V_104 , V_109 ) ;
F_5 ( L_14 ,
V_107 , V_107 -> V_104 . V_117 . V_60 ) ;
}
V_2 -> V_34 . V_107 = NULL ;
F_50 ( & V_2 -> V_108 , V_105 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_30 ;
struct V_78 * V_79 ;
V_79 = & V_2 -> V_80 ;
V_79 -> type = V_118 ;
V_79 -> V_119 = V_120 | V_121 | V_122 ;
V_79 -> V_123 = V_2 ;
V_79 -> V_124 = sizeof( struct V_106 ) ;
V_79 -> V_125 = & V_126 ;
V_79 -> V_127 = & V_128 ;
V_79 -> V_129 = V_130 ;
V_30 = F_57 ( V_79 ) ;
if ( V_30 < 0 )
return V_30 ;
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_30 ;
V_2 -> V_91 = V_131 ;
V_2 -> V_91 . V_132 = V_133 ;
V_2 -> V_91 . V_134 = & V_2 -> V_80 ;
V_2 -> V_91 . V_135 = & V_2 -> V_32 ;
V_2 -> V_91 . V_134 -> V_135 = & V_2 -> V_136 ;
V_2 -> V_91 . V_40 = & V_2 -> V_40 ;
F_60 ( V_137 , & V_2 -> V_91 . V_105 ) ;
V_2 -> V_17 = V_138 ;
V_2 -> V_70 = 720 ;
V_2 -> V_71 = 480 ;
V_2 -> V_68 = & V_63 [ 0 ] ;
F_1 ( V_2 ) ;
F_12 ( & V_2 -> V_40 , 0 , V_84 , V_85 ,
V_2 -> V_17 ) ;
F_61 ( & V_2 -> V_91 , V_2 ) ;
V_30 = F_62 ( & V_2 -> V_91 , V_139 , - 1 ) ;
if ( V_30 < 0 ) {
F_11 ( L_15 , V_30 ) ;
return V_30 ;
}
F_63 ( & V_2 -> V_40 , L_16 ,
F_64 ( & V_2 -> V_91 ) ) ;
return 0 ;
}
