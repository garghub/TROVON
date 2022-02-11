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
F_6 ( L_6 , V_2 -> V_3 . V_12 ,
V_2 -> V_3 . V_15 , V_2 -> V_3 . V_14 ) ;
F_9 ( & V_2 -> V_9 ) ;
F_10 ( V_2 -> V_3 . V_16 ) ;
F_11 ( V_2 -> V_3 . V_16 , V_17 ) ;
F_12 ( V_2 -> V_3 . V_16 ) ;
return;
}
V_7 = ( V_2 -> V_3 . V_4 + 2 ) % V_2 -> V_3 . V_14 ;
F_13 ( V_8 , V_7 * V_2 -> V_3 . V_13 ) ;
if ( V_18 > 2 )
F_6 ( L_7 ,
( V_6 & 0x10000000 ) ? L_4 : L_8 , V_7 ,
V_7 * V_2 -> V_3 . V_13 , V_2 -> V_3 . V_14 , V_2 -> V_3 . V_13 , V_2 -> V_3 . V_12 ) ;
V_2 -> V_3 . V_4 = ( V_2 -> V_3 . V_4 + 1 ) % V_2 -> V_3 . V_14 ;
V_2 -> V_3 . V_12 += V_2 -> V_3 . V_13 ;
V_2 -> V_3 . V_19 = V_8 ;
if ( V_2 -> V_3 . V_12 >= F_14 ( V_2 -> V_3 . V_16 ) ) {
F_9 ( & V_2 -> V_9 ) ;
F_15 ( V_2 -> V_3 . V_16 ) ;
F_5 ( & V_2 -> V_9 ) ;
}
V_11:
F_9 ( & V_2 -> V_9 ) ;
}
static T_1 F_16 ( int V_20 , void * V_21 )
{
struct V_22 * V_3 = V_21 ;
struct V_1 * V_2 = V_3 -> V_23 ;
unsigned long V_24 , V_6 ;
int V_25 , V_26 = 0 ;
for ( V_25 = 0 ; V_25 < 10 ; V_25 ++ ) {
V_24 = F_17 ( V_27 ) ;
V_6 = F_17 ( V_28 ) ;
if ( V_24 & V_29 ) {
V_26 = 1 ;
F_13 ( V_27 ,
V_29 ) ;
F_4 ( V_2 , V_6 ) ;
} else {
goto V_30;
}
}
if ( V_25 == 10 ) {
F_6 ( L_9 ) ;
}
V_30:
return F_18 ( V_26 ) ;
}
static int F_19 ( struct V_31 * V_16 ,
int V_32 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
T_2 * V_35 = V_34 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
int V_37 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
if ( V_32 == V_38 ) {
F_3 ( V_2 ) ;
} else if ( V_32 == V_39 ) {
F_1 ( V_2 ) ;
} else {
V_37 = - V_40 ;
}
F_9 ( & V_2 -> V_9 ) ;
return V_37 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_37 ;
F_21 ( ! V_2 -> V_3 . V_15 ) ;
F_22 ( & V_2 -> V_3 . V_41 ) ;
V_37 = F_23 ( & V_2 -> V_3 . V_41 , V_42 ,
( V_2 -> V_3 . V_15 + V_43 ) >> V_44 ) ;
if ( 0 != V_37 )
return V_37 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_21 ( ! V_2 -> V_3 . V_13 ) ;
F_25 ( & V_2 -> V_3 . V_41 ) ;
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 ,
int V_47 , int V_48 , bool V_49 )
{
T_3 * V_50 = F_27 ( V_46 ) ;
int V_51 = 0 , V_52 = V_46 -> V_53 ;
int V_54 , V_55 ;
T_4 V_56 , V_57 ;
int V_58 , V_59 ;
struct V_1 * V_2 ;
V_2 = V_50 -> V_2 ;
F_28 ( & V_50 -> V_60 ) ;
V_54 = V_47 != 0 || V_48 != 0 ;
V_55 = V_50 -> V_61 ;
if ( V_54 ) {
V_51 = V_55 != V_52 ||
V_50 -> V_62 [ 0 ] != V_47 ||
V_50 -> V_62 [ 1 ] != V_48 ;
V_50 -> V_62 [ 0 ] = V_47 ;
V_50 -> V_62 [ 1 ] = V_48 ;
V_50 -> V_61 = V_52 ;
V_2 -> V_3 . V_63 = V_52 ;
}
F_29 ( & V_50 -> V_60 ) ;
if ( V_51 ) {
switch ( V_2 -> V_64 -> V_65 ) {
case V_66 :
switch ( V_52 ) {
case V_67 :
F_30 ( V_68 ,
0xc0 , 0xc0 ) ;
F_30 ( V_69 ,
0x03 , 0x00 ) ;
break;
case V_70 :
case V_71 :
V_58 = ( V_70 == V_52 ) ?
0x00 : 0x08 ;
V_59 = ( 32000 == V_2 -> V_3 . V_59 ) ?
0x01 : 0x03 ;
F_30 ( V_72 ,
0x08 , V_58 ) ;
F_30 ( V_68 ,
0xc0 , 0x80 ) ;
F_30 ( V_69 ,
0x03 , V_59 ) ;
break;
}
break;
case V_73 :
case V_74 :
V_57 = 0x03 ;
V_56 = 0 ;
switch ( V_52 ) {
case V_67 :
V_57 = 0 ;
V_56 = 2 ;
break;
case V_70 :
V_56 = 0 ;
break;
case V_71 :
V_56 = 9 ;
break;
}
F_31 ( V_2 , V_75 ,
0xbbbb10 ) ;
if ( V_47 || V_48 ) {
F_31 ( V_2 , V_76 ,
V_57 ) ;
F_13 ( V_77 , V_56 ) ;
} else {
F_31 ( V_2 , V_76 ,
0 ) ;
F_13 ( V_77 , 0 ) ;
}
break;
}
}
if ( V_51 ) {
if ( V_49 )
F_32 ( V_50 -> V_78 ,
V_79 ,
& V_50 -> V_80 [ V_52 ] -> V_81 ) ;
if ( V_55 != V_82 && V_55 != V_52 )
F_32 ( V_50 -> V_78 ,
V_79 ,
& V_50 -> V_80 [ V_55 ] -> V_81 ) ;
}
return V_51 ;
}
static int F_33 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
int V_83 , V_84 ;
T_4 V_85 , V_86 ;
T_3 * V_87 = F_34 ( V_16 ) ;
struct V_1 * V_2 ;
T_2 * V_35 = V_34 -> V_36 ;
V_35 -> V_2 -> V_3 . V_16 = V_16 ;
V_2 = V_87 -> V_2 ;
if ( F_35 ( V_34 -> V_88 ) == 8 )
V_85 = 0x00 ;
else
V_85 = 0x01 ;
if ( F_36 ( V_34 -> V_88 ) )
V_84 = 1 ;
else
V_84 = 0 ;
if ( F_37 ( V_34 -> V_88 ) )
V_83 = 1 ;
else
V_83 = 0 ;
switch ( V_2 -> V_64 -> V_65 ) {
case V_66 :
if ( 1 == V_34 -> V_89 )
V_85 |= ( 1 << 3 ) ;
if ( 2 == V_34 -> V_89 )
V_85 |= ( 3 << 3 ) ;
if ( V_84 )
V_85 |= 0x04 ;
V_85 |= ( V_67 == V_2 -> V_3 . V_63 ) ? 0xc0 : 0x80 ;
F_38 ( V_90 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x0000ff ) ) ;
F_38 ( V_91 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x00ff00 ) >> 8 ) ;
F_38 ( V_92 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0xff0000 ) >> 16 ) ;
F_38 ( V_68 , V_85 ) ;
break;
case V_73 :
case V_74 :
if ( 1 == V_34 -> V_89 )
V_85 |= ( 1 << 4 ) ;
if ( 2 == V_34 -> V_89 )
V_85 |= ( 2 << 4 ) ;
if ( ! V_84 )
V_85 |= 0x04 ;
F_13 ( V_93 , V_2 -> V_3 . V_13 - 1 ) ;
F_13 ( V_94 , 0x543210 | ( V_85 << 24 ) ) ;
break;
}
F_6 ( L_10 ,
V_34 -> V_88 , V_34 -> V_89 , V_85 ,
V_83 ? 'b' : '-' ) ;
V_86 = V_95 |
V_96 |
( V_2 -> V_3 . V_97 . V_41 >> 12 ) ;
if ( V_83 )
V_86 |= V_98 ;
F_13 ( F_7 ( 6 ) , 0 ) ;
F_13 ( F_8 ( 6 ) , V_2 -> V_3 . V_13 ) ;
F_13 ( F_39 ( 6 ) , 0 ) ;
F_13 ( F_40 ( 6 ) , V_86 ) ;
V_2 -> V_3 . V_59 = V_34 -> V_59 ;
F_26 ( V_87 -> V_80 [ V_2 -> V_3 . V_63 ] , 1 , 1 ,
true ) ;
return 0 ;
}
static T_5
F_41 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
T_2 * V_35 = V_34 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_2 -> V_3 . V_12 ) {
V_2 -> V_3 . V_12 -= F_14 ( V_16 ) ;
V_2 -> V_3 . V_99 += F_14 ( V_16 ) ;
if ( V_2 -> V_3 . V_99 == V_2 -> V_3 . V_15 )
V_2 -> V_3 . V_99 = 0 ;
}
return F_42 ( V_34 , V_2 -> V_3 . V_99 ) ;
}
static void F_43 ( struct V_33 * V_34 )
{
T_2 * V_35 = V_34 -> V_36 ;
F_44 ( V_35 ) ;
}
static int F_45 ( struct V_31 * V_16 ,
struct V_100 * V_101 )
{
T_3 * V_87 = F_34 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned int V_102 , V_103 ;
int V_37 ;
V_102 = F_46 ( V_101 ) ;
V_103 = F_47 ( V_101 ) ;
if ( V_102 < 0x100 || V_102 > 0x10000 )
return - V_40 ;
if ( V_103 < 4 )
return - V_40 ;
if ( V_102 * V_103 > 1024 * 1024 )
return - V_40 ;
V_2 = V_87 -> V_2 ;
if ( V_2 -> V_3 . V_14 == V_103 &&
V_2 -> V_3 . V_13 == V_102 )
return 0 ;
if ( V_16 -> V_34 -> V_104 ) {
F_48 ( V_2 -> V_64 , & V_2 -> V_3 . V_97 ) ;
F_49 ( & V_2 -> V_64 -> V_2 , & V_2 -> V_3 . V_41 ) ;
F_24 ( V_2 ) ;
V_16 -> V_34 -> V_104 = NULL ;
}
V_2 -> V_3 . V_14 = V_103 ;
V_2 -> V_3 . V_13 = V_102 ;
V_2 -> V_3 . V_15 = V_102 * V_103 ;
V_37 = F_20 ( V_2 ) ;
if ( 0 != V_37 ) {
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return V_37 ;
}
if ( 0 != ( V_37 = F_50 ( & V_2 -> V_64 -> V_2 , & V_2 -> V_3 . V_41 ) ) ) {
F_24 ( V_2 ) ;
return V_37 ;
}
if ( 0 != ( V_37 = F_51 ( V_2 -> V_64 , & V_2 -> V_3 . V_97 ) ) ) {
F_49 ( & V_2 -> V_64 -> V_2 , & V_2 -> V_3 . V_41 ) ;
F_24 ( V_2 ) ;
return V_37 ;
}
if ( 0 != ( V_37 = F_52 ( V_2 -> V_64 , & V_2 -> V_3 . V_97 ,
V_2 -> V_3 . V_41 . V_105 ,
V_2 -> V_3 . V_41 . V_106 ,
0 ) ) ) {
F_48 ( V_2 -> V_64 , & V_2 -> V_3 . V_97 ) ;
F_49 ( & V_2 -> V_64 -> V_2 , & V_2 -> V_3 . V_41 ) ;
F_24 ( V_2 ) ;
return V_37 ;
}
V_16 -> V_34 -> V_104 = V_2 -> V_3 . V_41 . V_107 ;
V_16 -> V_34 -> V_108 = V_2 -> V_3 . V_15 ;
V_16 -> V_34 -> V_109 = 0 ;
return 0 ;
}
static int F_53 ( struct V_31 * V_16 )
{
T_3 * V_87 = F_34 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = V_87 -> V_2 ;
if ( V_16 -> V_34 -> V_104 ) {
F_48 ( V_2 -> V_64 , & V_2 -> V_3 . V_97 ) ;
F_49 ( & V_2 -> V_64 -> V_2 , & V_2 -> V_3 . V_41 ) ;
F_24 ( V_2 ) ;
V_16 -> V_34 -> V_104 = NULL ;
}
return 0 ;
}
static int F_54 ( struct V_31 * V_16 )
{
T_3 * V_87 = F_34 ( V_16 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
if ( V_87 -> V_110 ) {
V_2 -> V_111 = 1 ;
F_55 ( V_2 ) ;
}
return 0 ;
}
static int F_56 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
T_2 * V_35 ;
T_3 * V_87 = F_34 ( V_16 ) ;
struct V_1 * V_2 ;
int V_112 , V_37 ;
if ( ! V_87 ) {
F_57 ( V_113 L_11
L_12 ) ;
return - V_114 ;
}
V_2 = V_87 -> V_2 ;
F_58 ( & V_2 -> V_3 . V_115 ) ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_99 = 0 ;
V_112 = V_2 -> V_63 -> V_112 ;
if ( ( V_112 < 1 ) || ( V_112 > 3 ) )
V_112 = 1 ;
V_2 -> V_3 . V_63 = V_112 - 1 ;
F_59 ( & V_2 -> V_3 . V_115 ) ;
V_35 = F_60 ( sizeof( * V_35 ) , V_116 ) ;
if ( V_35 == NULL )
return - V_117 ;
V_35 -> V_2 = V_87 -> V_2 ;
F_61 ( & V_35 -> V_115 ) ;
V_35 -> V_16 = V_16 ;
V_34 -> V_36 = V_35 ;
V_34 -> V_118 = F_43 ;
V_34 -> V_119 = V_120 ;
if ( V_2 -> V_111 != 0 ) {
V_87 -> V_110 = 1 ;
V_2 -> V_111 = 0 ;
F_55 ( V_2 ) ;
}
V_37 = F_62 ( V_34 ,
V_121 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_63 ( V_34 , 0 ,
V_121 , 2 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static struct V_122 * F_64 ( struct V_31 * V_16 ,
unsigned long V_123 )
{
void * V_124 = V_16 -> V_34 -> V_104 + V_123 ;
return F_65 ( V_124 ) ;
}
static int F_66 ( T_3 * V_87 , int V_65 )
{
struct V_125 * V_35 ;
int V_37 ;
if ( ( V_37 = F_67 ( V_87 -> V_78 , L_13 , V_65 , 0 , 1 , & V_35 ) ) < 0 )
return V_37 ;
F_68 ( V_35 , V_126 , & V_127 ) ;
V_35 -> V_36 = V_87 ;
V_35 -> V_128 = 0 ;
strcpy ( V_35 -> V_129 , L_13 ) ;
return 0 ;
}
static int F_69 ( struct V_45 * V_46 ,
struct V_130 * V_131 )
{
V_131 -> type = V_132 ;
V_131 -> V_133 = 2 ;
V_131 -> V_134 . integer . V_135 = 0 ;
V_131 -> V_134 . integer . V_136 = 20 ;
return 0 ;
}
static int F_70 ( struct V_45 * V_46 ,
struct V_137 * V_138 )
{
T_3 * V_50 = F_27 ( V_46 ) ;
int V_52 = V_46 -> V_53 ;
V_138 -> V_134 . integer . V_134 [ 0 ] = V_50 -> V_139 [ V_52 ] [ 0 ] ;
V_138 -> V_134 . integer . V_134 [ 1 ] = V_50 -> V_139 [ V_52 ] [ 1 ] ;
return 0 ;
}
static int F_71 ( struct V_45 * V_46 ,
struct V_137 * V_138 )
{
T_3 * V_50 = F_27 ( V_46 ) ;
struct V_1 * V_2 = V_50 -> V_2 ;
int V_51 , V_52 = V_46 -> V_53 ;
int V_47 , V_48 ;
V_47 = V_138 -> V_134 . integer . V_134 [ 0 ] ;
if ( V_47 < 0 )
V_47 = 0 ;
if ( V_47 > 20 )
V_47 = 20 ;
V_48 = V_138 -> V_134 . integer . V_134 [ 1 ] ;
if ( V_48 < 0 )
V_48 = 0 ;
if ( V_48 > 20 )
V_48 = 20 ;
F_28 ( & V_50 -> V_60 ) ;
V_51 = 0 ;
if ( V_50 -> V_139 [ V_52 ] [ 0 ] != V_47 ) {
V_51 = 1 ;
V_48 = V_47 ;
}
if ( V_50 -> V_139 [ V_52 ] [ 1 ] != V_48 ) {
V_51 = 1 ;
V_47 = V_48 ;
}
if ( V_51 ) {
switch ( V_2 -> V_64 -> V_65 ) {
case V_66 :
switch ( V_52 ) {
case V_67 :
V_47 = 20 ;
break;
case V_70 :
F_30 ( V_72 , 0x10 ,
( V_47 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_71 :
F_30 ( V_72 , 0x20 ,
( V_47 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
case V_73 :
case V_74 :
switch ( V_52 ) {
case V_67 :
V_47 = 20 ;
break;
case V_70 :
F_30 ( 0x0594 , 0x10 ,
( V_47 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_71 :
F_30 ( 0x0594 , 0x20 ,
( V_47 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
}
V_50 -> V_139 [ V_52 ] [ 0 ] = V_47 ;
V_50 -> V_139 [ V_52 ] [ 1 ] = V_48 ;
}
F_29 ( & V_50 -> V_60 ) ;
return V_51 ;
}
static int F_72 ( struct V_45 * V_46 ,
struct V_130 * V_131 )
{
V_131 -> type = V_140 ;
V_131 -> V_133 = 2 ;
V_131 -> V_134 . integer . V_135 = 0 ;
V_131 -> V_134 . integer . V_136 = 1 ;
return 0 ;
}
static int F_73 ( struct V_45 * V_46 ,
struct V_137 * V_138 )
{
T_3 * V_50 = F_27 ( V_46 ) ;
int V_52 = V_46 -> V_53 ;
F_28 ( & V_50 -> V_60 ) ;
if ( V_50 -> V_61 == V_52 ) {
V_138 -> V_134 . integer . V_134 [ 0 ] = V_50 -> V_62 [ 0 ] ;
V_138 -> V_134 . integer . V_134 [ 1 ] = V_50 -> V_62 [ 1 ] ;
} else {
V_138 -> V_134 . integer . V_134 [ 0 ] = 0 ;
V_138 -> V_134 . integer . V_134 [ 1 ] = 0 ;
}
F_29 ( & V_50 -> V_60 ) ;
return 0 ;
}
static int F_74 ( struct V_45 * V_46 ,
struct V_137 * V_138 )
{
int V_47 , V_48 ;
V_47 = V_138 -> V_134 . integer . V_134 [ 0 ] & 1 ;
V_48 = V_138 -> V_134 . integer . V_134 [ 1 ] & 1 ;
return F_26 ( V_46 , V_47 , V_48 , false ) ;
}
static int F_75 ( T_3 * V_50 )
{
struct V_141 * V_78 = V_50 -> V_78 ;
struct V_45 * V_46 ;
unsigned int V_142 ;
int V_37 , V_52 ;
strcpy ( V_78 -> V_143 , L_14 ) ;
for ( V_142 = 0 ; V_142 < F_76 ( V_144 ) ; V_142 ++ ) {
V_46 = F_77 ( & V_144 [ V_142 ] ,
V_50 ) ;
V_37 = F_78 ( V_78 , V_46 ) ;
if ( V_37 < 0 )
return V_37 ;
}
for ( V_142 = 0 ; V_142 < F_76 ( V_145 ) ; V_142 ++ ) {
V_46 = F_77 ( & V_145 [ V_142 ] ,
V_50 ) ;
V_52 = V_145 [ V_142 ] . V_53 ;
V_50 -> V_80 [ V_52 ] = V_46 ;
V_37 = F_78 ( V_78 , V_46 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_50 -> V_61 = V_82 ;
return 0 ;
}
static void F_79 ( struct V_141 * V_78 )
{
T_3 * V_50 = V_78 -> V_36 ;
if ( V_50 -> V_2 -> V_3 . V_23 == NULL )
return;
if ( V_50 -> V_20 >= 0 )
F_80 ( V_50 -> V_20 , & V_50 -> V_2 -> V_3 ) ;
V_50 -> V_2 -> V_3 . V_23 = NULL ;
}
static int F_81 ( struct V_1 * V_2 , int V_146 )
{
struct V_141 * V_78 ;
T_3 * V_50 ;
int V_37 ;
if ( V_146 >= V_147 )
return - V_114 ;
if ( ! V_148 [ V_146 ] )
return - V_114 ;
V_37 = F_82 ( & V_2 -> V_64 -> V_2 , V_149 [ V_146 ] , V_81 [ V_146 ] ,
V_150 , sizeof( T_3 ) , & V_78 ) ;
if ( V_37 < 0 )
return V_37 ;
strcpy ( V_78 -> V_151 , L_15 ) ;
V_78 -> V_118 = F_79 ;
V_50 = V_78 -> V_36 ;
F_61 ( & V_50 -> V_115 ) ;
F_61 ( & V_50 -> V_60 ) ;
V_50 -> V_2 = V_2 ;
V_50 -> V_78 = V_78 ;
V_50 -> V_64 = V_2 -> V_64 ;
V_50 -> V_152 = F_83 ( V_2 -> V_64 , 0 ) ;
V_37 = F_84 ( V_2 -> V_64 -> V_20 , F_16 ,
V_153 , V_2 -> V_129 ,
( void * ) & V_2 -> V_3 ) ;
if ( V_37 < 0 ) {
F_57 ( V_113 L_16 ,
V_2 -> V_129 , V_2 -> V_64 -> V_20 ) ;
goto V_154;
}
V_50 -> V_20 = V_2 -> V_64 -> V_20 ;
F_85 ( & V_2 -> V_3 . V_115 ) ;
if ( ( V_37 = F_75 ( V_50 ) ) < 0 )
goto V_154;
if ( ( V_37 = F_66 ( V_50 , 0 ) ) < 0 )
goto V_154;
strcpy ( V_78 -> V_155 , L_15 ) ;
sprintf ( V_78 -> V_156 , L_17 ,
V_50 -> V_2 -> V_129 , V_50 -> V_152 , V_50 -> V_20 ) ;
F_57 ( V_157 L_18 , V_2 -> V_129 , V_78 -> V_156 , V_149 [ V_146 ] ) ;
if ( ( V_37 = F_86 ( V_78 ) ) == 0 ) {
V_158 [ V_146 ] = V_78 ;
return 0 ;
}
V_154:
F_87 ( V_78 ) ;
return V_37 ;
}
static int F_88 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_23 = V_2 ;
F_81 ( V_2 , V_2 -> V_159 ) ;
return 1 ;
}
static int F_89 ( struct V_1 * V_2 )
{
F_87 ( V_158 [ V_2 -> V_159 ] ) ;
V_158 [ V_2 -> V_159 ] = NULL ;
return 1 ;
}
static int F_90 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_160 * V_161 ;
V_162 = F_88 ;
V_163 = F_89 ;
F_57 ( V_157 L_19 ) ;
F_91 (list,&saa7134_devlist) {
V_2 = F_92 ( V_161 , struct V_1 , V_164 ) ;
if ( V_2 -> V_64 -> V_65 == V_165 )
F_57 ( V_157 L_20 ,
V_2 -> V_129 , V_166 [ V_2 -> V_167 ] . V_129 ) ;
else
F_88 ( V_2 ) ;
}
if ( V_2 == NULL )
F_57 ( V_157 L_21 ) ;
return 0 ;
}
static void F_93 ( void )
{
int V_142 ;
for ( V_142 = 0 ; V_142 < V_147 ; V_142 ++ ) {
F_87 ( V_158 [ V_142 ] ) ;
}
V_162 = NULL ;
V_163 = NULL ;
F_57 ( V_157 L_22 ) ;
return;
}
