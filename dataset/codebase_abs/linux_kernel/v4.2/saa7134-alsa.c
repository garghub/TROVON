static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = - 1 ;
V_2 -> V_3 . V_5 = 0 ;
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_5 = 1 ;
F_2 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
int V_7 , V_8 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
if ( V_10 == V_2 -> V_3 . V_4 ) {
F_6 ( L_1 ) ;
goto V_11;
}
if ( 0 != ( V_6 & 0x0f000000 ) )
F_6 ( L_2 , ( V_6 >> 24 ) & 0x0f ) ;
if ( 0 == ( V_6 & 0x10000000 ) ) {
if ( 0 == ( V_2 -> V_3 . V_4 & 0x01 ) )
V_8 = F_7 ( 6 ) ;
} else {
if ( 1 == ( V_2 -> V_3 . V_4 & 0x01 ) )
V_8 = F_8 ( 6 ) ;
}
if ( 0 == V_8 ) {
F_6 ( L_3 ,
( V_6 & 0x10000000 ) ? L_4 : L_5 ) ;
goto V_11;
}
if ( V_2 -> V_3 . V_12 >= V_2 -> V_3 . V_13 * ( V_2 -> V_3 . V_14 - 2 ) ) {
F_6 ( L_6 ,
V_2 -> V_3 . V_12 ,
V_2 -> V_3 . V_15 , V_2 -> V_3 . V_14 ) ;
F_9 ( & V_2 -> V_9 ) ;
F_10 ( V_2 -> V_3 . V_16 ) ;
return;
}
V_7 = ( V_2 -> V_3 . V_4 + 2 ) % V_2 -> V_3 . V_14 ;
F_11 ( V_8 , V_7 * V_2 -> V_3 . V_13 ) ;
F_6 ( L_7 ,
( V_6 & 0x10000000 ) ? L_4 : L_8 , V_7 ,
V_7 * V_2 -> V_3 . V_13 , V_2 -> V_3 . V_14 ,
V_2 -> V_3 . V_13 , V_2 -> V_3 . V_12 ) ;
V_2 -> V_3 . V_4 = ( V_2 -> V_3 . V_4 + 1 ) % V_2 -> V_3 . V_14 ;
V_2 -> V_3 . V_12 += V_2 -> V_3 . V_13 ;
V_2 -> V_3 . V_17 = V_8 ;
if ( V_2 -> V_3 . V_12 >= F_12 ( V_2 -> V_3 . V_16 ) ) {
F_9 ( & V_2 -> V_9 ) ;
F_13 ( V_2 -> V_3 . V_16 ) ;
F_5 ( & V_2 -> V_9 ) ;
}
V_11:
F_9 ( & V_2 -> V_9 ) ;
}
static T_1 F_14 ( int V_18 , void * V_19 )
{
struct V_20 * V_3 = V_19 ;
struct V_1 * V_2 = V_3 -> V_21 ;
unsigned long V_22 , V_6 ;
int V_23 , V_24 = 0 ;
for ( V_23 = 0 ; V_23 < 10 ; V_23 ++ ) {
V_22 = F_15 ( V_25 ) ;
V_6 = F_15 ( V_26 ) ;
if ( V_22 & V_27 ) {
V_24 = 1 ;
F_11 ( V_25 ,
V_27 ) ;
F_4 ( V_2 , V_6 ) ;
} else {
goto V_28;
}
}
if ( V_23 == 10 ) {
F_6 ( L_9 ) ;
}
V_28:
return F_16 ( V_24 ) ;
}
static int F_17 ( struct V_29 * V_16 ,
int V_30 )
{
struct V_31 * V_32 = V_16 -> V_32 ;
T_2 * V_33 = V_32 -> V_34 ;
struct V_1 * V_2 = V_33 -> V_2 ;
int V_35 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
if ( V_30 == V_36 ) {
F_3 ( V_2 ) ;
} else if ( V_30 == V_37 ) {
F_1 ( V_2 ) ;
} else {
V_35 = - V_38 ;
}
F_9 ( & V_2 -> V_9 ) ;
return V_35 ;
}
static int F_18 ( struct V_1 * V_2 , int V_39 )
{
struct V_20 * V_40 = & V_2 -> V_3 ;
struct V_41 * V_42 ;
int V_43 ;
V_40 -> V_44 = F_19 ( V_39 << V_45 ) ;
if ( NULL == V_40 -> V_44 ) {
F_6 ( L_10 , V_39 ) ;
return - V_46 ;
}
F_6 ( L_11 ,
( unsigned long ) V_40 -> V_44 ,
V_39 << V_45 ) ;
memset ( V_40 -> V_44 , 0 , V_39 << V_45 ) ;
V_40 -> V_39 = V_39 ;
V_40 -> V_47 = F_20 ( V_40 -> V_39 * sizeof( * V_40 -> V_47 ) ) ;
if ( NULL == V_40 -> V_47 )
goto V_48;
F_21 ( V_40 -> V_47 , V_40 -> V_39 ) ;
for ( V_43 = 0 ; V_43 < V_40 -> V_39 ; V_43 ++ ) {
V_42 = F_22 ( V_40 -> V_44 + V_43 * V_49 ) ;
if ( NULL == V_42 )
goto V_50;
F_23 ( & V_40 -> V_47 [ V_43 ] , V_42 , V_49 , 0 ) ;
}
return 0 ;
V_50:
F_24 ( V_40 -> V_47 ) ;
V_40 -> V_47 = NULL ;
V_48:
F_24 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
return - V_46 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_20 * V_40 = & V_2 -> V_3 ;
V_40 -> V_51 = F_26 ( & V_2 -> V_52 -> V_2 , V_40 -> V_47 ,
V_40 -> V_39 , V_53 ) ;
if ( 0 == V_40 -> V_51 ) {
F_27 ( L_12 , V_54 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_40 = & V_2 -> V_3 ;
if ( ! V_40 -> V_51 )
return 0 ;
F_29 ( & V_2 -> V_52 -> V_2 , V_40 -> V_47 , V_40 -> V_51 , V_53 ) ;
V_40 -> V_51 = 0 ;
return 0 ;
}
static int F_30 ( struct V_20 * V_40 )
{
F_24 ( V_40 -> V_47 ) ;
V_40 -> V_47 = NULL ;
F_24 ( V_40 -> V_44 ) ;
V_40 -> V_44 = NULL ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_35 ;
F_32 ( ! V_2 -> V_3 . V_15 ) ;
V_35 = F_18 ( V_2 ,
( V_2 -> V_3 . V_15 + V_49 ) >> V_45 ) ;
if ( 0 != V_35 )
return V_35 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_32 ( ! V_2 -> V_3 . V_13 ) ;
F_30 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return 0 ;
}
static int F_34 ( struct V_55 * V_56 ,
int V_57 , int V_58 , bool V_59 )
{
T_3 * V_60 = F_35 ( V_56 ) ;
int V_61 = 0 , V_62 = V_56 -> V_63 ;
int V_64 , V_65 ;
T_4 V_66 , V_67 ;
int V_68 , V_69 ;
struct V_1 * V_2 ;
V_2 = V_60 -> V_2 ;
F_36 ( & V_60 -> V_70 ) ;
V_64 = V_57 != 0 || V_58 != 0 ;
V_65 = V_60 -> V_71 ;
if ( V_64 ) {
V_61 = V_65 != V_62 ||
V_60 -> V_72 [ 0 ] != V_57 ||
V_60 -> V_72 [ 1 ] != V_58 ;
V_60 -> V_72 [ 0 ] = V_57 ;
V_60 -> V_72 [ 1 ] = V_58 ;
V_60 -> V_71 = V_62 ;
V_2 -> V_3 . V_73 = V_62 ;
}
F_37 ( & V_60 -> V_70 ) ;
if ( V_61 ) {
switch ( V_2 -> V_52 -> V_74 ) {
case V_75 :
switch ( V_62 ) {
case V_76 :
F_38 ( V_77 ,
0xc0 , 0xc0 ) ;
F_38 ( V_78 ,
0x03 , 0x00 ) ;
break;
case V_79 :
case V_80 :
V_68 = ( V_79 == V_62 ) ?
0x00 : 0x08 ;
V_69 = ( 32000 == V_2 -> V_3 . V_69 ) ?
0x01 : 0x03 ;
F_38 ( V_81 ,
0x08 , V_68 ) ;
F_38 ( V_77 ,
0xc0 , 0x80 ) ;
F_38 ( V_78 ,
0x03 , V_69 ) ;
break;
}
break;
case V_82 :
case V_83 :
V_67 = 0x03 ;
V_66 = 0 ;
switch ( V_62 ) {
case V_76 :
V_67 = 0 ;
V_66 = 2 ;
break;
case V_79 :
V_66 = 0 ;
break;
case V_80 :
V_66 = 9 ;
break;
}
F_39 ( V_2 , V_84 ,
0xbbbb10 ) ;
if ( V_57 || V_58 ) {
F_39 ( V_2 , V_85 ,
V_67 ) ;
F_11 ( V_86 , V_66 ) ;
} else {
F_39 ( V_2 , V_85 ,
0 ) ;
F_11 ( V_86 , 0 ) ;
}
break;
}
}
if ( V_61 ) {
if ( V_59 )
F_40 ( V_60 -> V_87 ,
V_88 ,
& V_60 -> V_89 [ V_62 ] -> V_90 ) ;
if ( V_65 != V_91 && V_65 != V_62 )
F_40 ( V_60 -> V_87 ,
V_88 ,
& V_60 -> V_89 [ V_65 ] -> V_90 ) ;
}
return V_61 ;
}
static int F_41 ( struct V_29 * V_16 )
{
struct V_31 * V_32 = V_16 -> V_32 ;
int V_92 , V_93 ;
T_4 V_94 , V_95 ;
T_3 * V_96 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
T_2 * V_33 = V_32 -> V_34 ;
V_33 -> V_2 -> V_3 . V_16 = V_16 ;
V_2 = V_96 -> V_2 ;
if ( F_43 ( V_32 -> V_97 ) == 8 )
V_94 = 0x00 ;
else
V_94 = 0x01 ;
if ( F_44 ( V_32 -> V_97 ) )
V_93 = 1 ;
else
V_93 = 0 ;
if ( F_45 ( V_32 -> V_97 ) )
V_92 = 1 ;
else
V_92 = 0 ;
switch ( V_2 -> V_52 -> V_74 ) {
case V_75 :
if ( 1 == V_32 -> V_98 )
V_94 |= ( 1 << 3 ) ;
if ( 2 == V_32 -> V_98 )
V_94 |= ( 3 << 3 ) ;
if ( V_93 )
V_94 |= 0x04 ;
V_94 |= ( V_76 == V_2 -> V_3 . V_73 ) ? 0xc0 : 0x80 ;
F_46 ( V_99 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x0000ff ) ) ;
F_46 ( V_100 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x00ff00 ) >> 8 ) ;
F_46 ( V_101 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0xff0000 ) >> 16 ) ;
F_46 ( V_77 , V_94 ) ;
break;
case V_82 :
case V_83 :
if ( 1 == V_32 -> V_98 )
V_94 |= ( 1 << 4 ) ;
if ( 2 == V_32 -> V_98 )
V_94 |= ( 2 << 4 ) ;
if ( ! V_93 )
V_94 |= 0x04 ;
F_11 ( V_102 , V_2 -> V_3 . V_13 - 1 ) ;
F_11 ( V_103 , 0x543210 | ( V_94 << 24 ) ) ;
break;
}
F_6 ( L_13 ,
V_32 -> V_97 , V_32 -> V_98 , V_94 ,
V_92 ? 'b' : '-' ) ;
V_95 = V_104 |
V_105 |
( V_2 -> V_3 . V_106 . V_40 >> 12 ) ;
if ( V_92 )
V_95 |= V_107 ;
F_11 ( F_7 ( 6 ) , 0 ) ;
F_11 ( F_8 ( 6 ) , V_2 -> V_3 . V_13 ) ;
F_11 ( F_47 ( 6 ) , 0 ) ;
F_11 ( F_48 ( 6 ) , V_95 ) ;
V_2 -> V_3 . V_69 = V_32 -> V_69 ;
F_34 ( V_96 -> V_89 [ V_2 -> V_3 . V_73 ] , 1 , 1 ,
true ) ;
return 0 ;
}
static T_5
F_49 ( struct V_29 * V_16 )
{
struct V_31 * V_32 = V_16 -> V_32 ;
T_2 * V_33 = V_32 -> V_34 ;
struct V_1 * V_2 = V_33 -> V_2 ;
if ( V_2 -> V_3 . V_12 ) {
V_2 -> V_3 . V_12 -= F_12 ( V_16 ) ;
V_2 -> V_3 . V_108 += F_12 ( V_16 ) ;
if ( V_2 -> V_3 . V_108 == V_2 -> V_3 . V_15 )
V_2 -> V_3 . V_108 = 0 ;
}
return F_50 ( V_32 , V_2 -> V_3 . V_108 ) ;
}
static void F_51 ( struct V_31 * V_32 )
{
T_2 * V_33 = V_32 -> V_34 ;
F_52 ( V_33 ) ;
}
static int F_53 ( struct V_29 * V_16 ,
struct V_109 * V_110 )
{
T_3 * V_96 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned int V_111 , V_112 ;
int V_35 ;
V_111 = F_54 ( V_110 ) ;
V_112 = F_55 ( V_110 ) ;
if ( V_111 < 0x100 || V_111 > 0x10000 )
return - V_38 ;
if ( V_112 < 4 )
return - V_38 ;
if ( V_111 * V_112 > 1024 * 1024 )
return - V_38 ;
V_2 = V_96 -> V_2 ;
if ( V_2 -> V_3 . V_14 == V_112 &&
V_2 -> V_3 . V_13 == V_111 )
return 0 ;
if ( V_16 -> V_32 -> V_113 ) {
F_56 ( V_2 -> V_52 , & V_2 -> V_3 . V_106 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
V_16 -> V_32 -> V_113 = NULL ;
}
V_2 -> V_3 . V_14 = V_112 ;
V_2 -> V_3 . V_13 = V_111 ;
V_2 -> V_3 . V_15 = V_111 * V_112 ;
V_35 = F_31 ( V_2 ) ;
if ( 0 != V_35 ) {
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return V_35 ;
}
V_35 = F_25 ( V_2 ) ;
if ( V_35 ) {
F_33 ( V_2 ) ;
return V_35 ;
}
V_35 = F_57 ( V_2 -> V_52 , & V_2 -> V_3 . V_106 ) ;
if ( V_35 ) {
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_35 ;
}
V_35 = F_58 ( V_2 -> V_52 , & V_2 -> V_3 . V_106 ,
V_2 -> V_3 . V_47 , V_2 -> V_3 . V_51 , 0 ) ;
if ( V_35 ) {
F_56 ( V_2 -> V_52 , & V_2 -> V_3 . V_106 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_35 ;
}
V_16 -> V_32 -> V_113 = V_2 -> V_3 . V_44 ;
V_16 -> V_32 -> V_114 = V_2 -> V_3 . V_15 ;
V_16 -> V_32 -> V_115 = 0 ;
return 0 ;
}
static int F_59 ( struct V_29 * V_16 )
{
T_3 * V_96 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = V_96 -> V_2 ;
if ( V_16 -> V_32 -> V_113 ) {
F_56 ( V_2 -> V_52 , & V_2 -> V_3 . V_106 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
V_16 -> V_32 -> V_113 = NULL ;
}
return 0 ;
}
static int F_60 ( struct V_29 * V_16 )
{
T_3 * V_96 = F_42 ( V_16 ) ;
struct V_1 * V_2 = V_96 -> V_2 ;
if ( V_96 -> V_116 ) {
V_2 -> V_117 = 1 ;
F_61 ( V_2 ) ;
}
return 0 ;
}
static int F_62 ( struct V_29 * V_16 )
{
struct V_31 * V_32 = V_16 -> V_32 ;
T_2 * V_33 ;
T_3 * V_96 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
int V_118 , V_35 ;
if ( ! V_96 ) {
F_63 ( L_14
L_15 ) ;
return - V_119 ;
}
V_2 = V_96 -> V_2 ;
F_64 ( & V_2 -> V_3 . V_120 ) ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_108 = 0 ;
V_118 = V_2 -> V_73 -> V_118 ;
if ( ( V_118 < 1 ) || ( V_118 > 3 ) )
V_118 = 1 ;
V_2 -> V_3 . V_73 = V_118 - 1 ;
F_65 ( & V_2 -> V_3 . V_120 ) ;
V_33 = F_66 ( sizeof( * V_33 ) , V_121 ) ;
if ( V_33 == NULL )
return - V_46 ;
V_33 -> V_2 = V_96 -> V_2 ;
F_67 ( & V_33 -> V_120 ) ;
V_33 -> V_16 = V_16 ;
V_32 -> V_34 = V_33 ;
V_32 -> V_122 = F_51 ;
V_32 -> V_123 = V_124 ;
if ( V_2 -> V_117 != 0 ) {
V_96 -> V_116 = 1 ;
V_2 -> V_117 = 0 ;
F_61 ( V_2 ) ;
}
V_35 = F_68 ( V_32 ,
V_125 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_69 ( V_32 , 0 ,
V_125 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static struct V_41 * F_70 ( struct V_29 * V_16 ,
unsigned long V_126 )
{
void * V_127 = V_16 -> V_32 -> V_113 + V_126 ;
return F_22 ( V_127 ) ;
}
static int F_71 ( T_3 * V_96 , int V_74 )
{
struct V_128 * V_33 ;
int V_35 ;
if ( ( V_35 = F_72 ( V_96 -> V_87 , L_16 , V_74 , 0 , 1 , & V_33 ) ) < 0 )
return V_35 ;
F_73 ( V_33 , V_129 , & V_130 ) ;
V_33 -> V_34 = V_96 ;
V_33 -> V_131 = 0 ;
strcpy ( V_33 -> V_132 , L_16 ) ;
return 0 ;
}
static int F_74 ( struct V_55 * V_56 ,
struct V_133 * V_134 )
{
V_134 -> type = V_135 ;
V_134 -> V_136 = 2 ;
V_134 -> V_137 . integer . V_138 = 0 ;
V_134 -> V_137 . integer . V_139 = 20 ;
return 0 ;
}
static int F_75 ( struct V_55 * V_56 ,
struct V_140 * V_141 )
{
T_3 * V_60 = F_35 ( V_56 ) ;
int V_62 = V_56 -> V_63 ;
V_141 -> V_137 . integer . V_137 [ 0 ] = V_60 -> V_142 [ V_62 ] [ 0 ] ;
V_141 -> V_137 . integer . V_137 [ 1 ] = V_60 -> V_142 [ V_62 ] [ 1 ] ;
return 0 ;
}
static int F_76 ( struct V_55 * V_56 ,
struct V_140 * V_141 )
{
T_3 * V_60 = F_35 ( V_56 ) ;
struct V_1 * V_2 = V_60 -> V_2 ;
int V_61 , V_62 = V_56 -> V_63 ;
int V_57 , V_58 ;
V_57 = V_141 -> V_137 . integer . V_137 [ 0 ] ;
if ( V_57 < 0 )
V_57 = 0 ;
if ( V_57 > 20 )
V_57 = 20 ;
V_58 = V_141 -> V_137 . integer . V_137 [ 1 ] ;
if ( V_58 < 0 )
V_58 = 0 ;
if ( V_58 > 20 )
V_58 = 20 ;
F_36 ( & V_60 -> V_70 ) ;
V_61 = 0 ;
if ( V_60 -> V_142 [ V_62 ] [ 0 ] != V_57 ) {
V_61 = 1 ;
V_58 = V_57 ;
}
if ( V_60 -> V_142 [ V_62 ] [ 1 ] != V_58 ) {
V_61 = 1 ;
V_57 = V_58 ;
}
if ( V_61 ) {
switch ( V_2 -> V_52 -> V_74 ) {
case V_75 :
switch ( V_62 ) {
case V_76 :
V_57 = 20 ;
break;
case V_79 :
F_38 ( V_81 , 0x10 ,
( V_57 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_80 :
F_38 ( V_81 , 0x20 ,
( V_57 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
case V_82 :
case V_83 :
switch ( V_62 ) {
case V_76 :
V_57 = 20 ;
break;
case V_79 :
F_38 ( 0x0594 , 0x10 ,
( V_57 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_80 :
F_38 ( 0x0594 , 0x20 ,
( V_57 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
}
V_60 -> V_142 [ V_62 ] [ 0 ] = V_57 ;
V_60 -> V_142 [ V_62 ] [ 1 ] = V_58 ;
}
F_37 ( & V_60 -> V_70 ) ;
return V_61 ;
}
static int F_77 ( struct V_55 * V_56 ,
struct V_133 * V_134 )
{
V_134 -> type = V_143 ;
V_134 -> V_136 = 2 ;
V_134 -> V_137 . integer . V_138 = 0 ;
V_134 -> V_137 . integer . V_139 = 1 ;
return 0 ;
}
static int F_78 ( struct V_55 * V_56 ,
struct V_140 * V_141 )
{
T_3 * V_60 = F_35 ( V_56 ) ;
int V_62 = V_56 -> V_63 ;
F_36 ( & V_60 -> V_70 ) ;
if ( V_60 -> V_71 == V_62 ) {
V_141 -> V_137 . integer . V_137 [ 0 ] = V_60 -> V_72 [ 0 ] ;
V_141 -> V_137 . integer . V_137 [ 1 ] = V_60 -> V_72 [ 1 ] ;
} else {
V_141 -> V_137 . integer . V_137 [ 0 ] = 0 ;
V_141 -> V_137 . integer . V_137 [ 1 ] = 0 ;
}
F_37 ( & V_60 -> V_70 ) ;
return 0 ;
}
static int F_79 ( struct V_55 * V_56 ,
struct V_140 * V_141 )
{
int V_57 , V_58 ;
V_57 = V_141 -> V_137 . integer . V_137 [ 0 ] & 1 ;
V_58 = V_141 -> V_137 . integer . V_137 [ 1 ] & 1 ;
return F_34 ( V_56 , V_57 , V_58 , false ) ;
}
static int F_80 ( T_3 * V_60 )
{
struct V_144 * V_87 = V_60 -> V_87 ;
struct V_55 * V_56 ;
unsigned int V_145 ;
int V_35 , V_62 ;
strcpy ( V_87 -> V_146 , L_17 ) ;
for ( V_145 = 0 ; V_145 < F_81 ( V_147 ) ; V_145 ++ ) {
V_56 = F_82 ( & V_147 [ V_145 ] ,
V_60 ) ;
V_35 = F_83 ( V_87 , V_56 ) ;
if ( V_35 < 0 )
return V_35 ;
}
for ( V_145 = 0 ; V_145 < F_81 ( V_148 ) ; V_145 ++ ) {
V_56 = F_82 ( & V_148 [ V_145 ] ,
V_60 ) ;
V_62 = V_148 [ V_145 ] . V_63 ;
V_60 -> V_89 [ V_62 ] = V_56 ;
V_35 = F_83 ( V_87 , V_56 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_60 -> V_71 = V_91 ;
return 0 ;
}
static void F_84 ( struct V_144 * V_87 )
{
T_3 * V_60 = V_87 -> V_34 ;
if ( V_60 -> V_2 -> V_3 . V_21 == NULL )
return;
if ( V_60 -> V_18 >= 0 )
F_85 ( V_60 -> V_18 , & V_60 -> V_2 -> V_3 ) ;
V_60 -> V_2 -> V_3 . V_21 = NULL ;
}
static int F_86 ( struct V_1 * V_2 , int V_149 )
{
struct V_144 * V_87 ;
T_3 * V_60 ;
int V_35 ;
if ( V_149 >= V_150 )
return - V_119 ;
if ( ! V_151 [ V_149 ] )
return - V_119 ;
V_35 = F_87 ( & V_2 -> V_52 -> V_2 , V_152 [ V_149 ] , V_90 [ V_149 ] ,
V_153 , sizeof( T_3 ) , & V_87 ) ;
if ( V_35 < 0 )
return V_35 ;
strcpy ( V_87 -> V_154 , L_18 ) ;
V_87 -> V_122 = F_84 ;
V_60 = V_87 -> V_34 ;
F_67 ( & V_60 -> V_120 ) ;
F_67 ( & V_60 -> V_70 ) ;
V_60 -> V_2 = V_2 ;
V_60 -> V_87 = V_87 ;
V_60 -> V_52 = V_2 -> V_52 ;
V_60 -> V_155 = F_88 ( V_2 -> V_52 , 0 ) ;
V_35 = F_89 ( V_2 -> V_52 -> V_18 , F_14 ,
V_156 , V_2 -> V_132 ,
( void * ) & V_2 -> V_3 ) ;
if ( V_35 < 0 ) {
F_63 ( L_19 ,
V_2 -> V_132 , V_2 -> V_52 -> V_18 ) ;
goto V_157;
}
V_60 -> V_18 = V_2 -> V_52 -> V_18 ;
F_90 ( & V_2 -> V_3 . V_120 ) ;
if ( ( V_35 = F_80 ( V_60 ) ) < 0 )
goto V_157;
if ( ( V_35 = F_71 ( V_60 , 0 ) ) < 0 )
goto V_157;
strcpy ( V_87 -> V_158 , L_18 ) ;
sprintf ( V_87 -> V_159 , L_20 ,
V_60 -> V_2 -> V_132 , V_60 -> V_155 , V_60 -> V_18 ) ;
F_91 ( L_21 ,
V_2 -> V_132 , V_87 -> V_159 , V_152 [ V_149 ] ) ;
if ( ( V_35 = F_92 ( V_87 ) ) == 0 ) {
V_160 [ V_149 ] = V_87 ;
return 0 ;
}
V_157:
F_93 ( V_87 ) ;
return V_35 ;
}
static int F_94 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_21 = V_2 ;
F_86 ( V_2 , V_2 -> V_161 ) ;
return 1 ;
}
static int F_95 ( struct V_1 * V_2 )
{
F_93 ( V_160 [ V_2 -> V_161 ] ) ;
V_160 [ V_2 -> V_161 ] = NULL ;
return 1 ;
}
static int F_96 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_162 * V_163 ;
V_164 = F_94 ;
V_165 = F_95 ;
F_91 ( L_22 ) ;
F_97 (list,&saa7134_devlist) {
V_2 = F_98 ( V_163 , struct V_1 , V_166 ) ;
if ( V_2 -> V_52 -> V_74 == V_167 )
F_91 ( L_23 ,
V_2 -> V_132 , V_168 [ V_2 -> V_169 ] . V_132 ) ;
else
F_94 ( V_2 ) ;
}
if ( V_2 == NULL )
F_91 ( L_24 ) ;
return 0 ;
}
static void F_99 ( void )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_150 ; V_145 ++ ) {
F_93 ( V_160 [ V_145 ] ) ;
}
V_164 = NULL ;
V_165 = NULL ;
F_91 ( L_25 ) ;
return;
}
