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
static int F_20 ( struct V_1 * V_2 , int V_41 )
{
struct V_22 * V_42 = & V_2 -> V_3 ;
struct V_43 * V_44 ;
int V_45 ;
V_42 -> V_46 = F_21 ( V_41 << V_47 ) ;
if ( NULL == V_42 -> V_46 ) {
F_6 ( L_10 , V_41 ) ;
return - V_48 ;
}
F_6 ( L_11 ,
( unsigned long ) V_42 -> V_46 ,
V_41 << V_47 ) ;
memset ( V_42 -> V_46 , 0 , V_41 << V_47 ) ;
V_42 -> V_41 = V_41 ;
V_42 -> V_49 = F_22 ( V_42 -> V_41 * sizeof( * V_42 -> V_49 ) ) ;
if ( NULL == V_42 -> V_49 )
goto V_50;
F_23 ( V_42 -> V_49 , V_42 -> V_41 ) ;
for ( V_45 = 0 ; V_45 < V_42 -> V_41 ; V_45 ++ ) {
V_44 = F_24 ( V_42 -> V_46 + V_45 * V_51 ) ;
if ( NULL == V_44 )
goto V_52;
F_25 ( & V_42 -> V_49 [ V_45 ] , V_44 , V_51 , 0 ) ;
}
return 0 ;
V_52:
F_26 ( V_42 -> V_49 ) ;
V_42 -> V_49 = NULL ;
V_50:
F_26 ( V_42 -> V_46 ) ;
V_42 -> V_46 = NULL ;
return - V_48 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_22 * V_42 = & V_2 -> V_3 ;
V_42 -> V_53 = F_28 ( & V_2 -> V_54 -> V_2 , V_42 -> V_49 ,
V_42 -> V_41 , V_55 ) ;
if ( 0 == V_42 -> V_53 ) {
F_29 ( L_12 , V_56 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_22 * V_42 = & V_2 -> V_3 ;
if ( ! V_42 -> V_53 )
return 0 ;
F_31 ( & V_2 -> V_54 -> V_2 , V_42 -> V_49 , V_42 -> V_53 , V_55 ) ;
V_42 -> V_53 = 0 ;
return 0 ;
}
static int F_32 ( struct V_22 * V_42 )
{
F_26 ( V_42 -> V_49 ) ;
V_42 -> V_49 = NULL ;
F_26 ( V_42 -> V_46 ) ;
V_42 -> V_46 = NULL ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_37 ;
F_34 ( ! V_2 -> V_3 . V_15 ) ;
V_37 = F_20 ( V_2 ,
( V_2 -> V_3 . V_15 + V_51 ) >> V_47 ) ;
if ( 0 != V_37 )
return V_37 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_34 ( ! V_2 -> V_3 . V_13 ) ;
F_32 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return 0 ;
}
static int F_36 ( struct V_57 * V_58 ,
int V_59 , int V_60 , bool V_61 )
{
T_3 * V_62 = F_37 ( V_58 ) ;
int V_63 = 0 , V_64 = V_58 -> V_65 ;
int V_66 , V_67 ;
T_4 V_68 , V_69 ;
int V_70 , V_71 ;
struct V_1 * V_2 ;
V_2 = V_62 -> V_2 ;
F_38 ( & V_62 -> V_72 ) ;
V_66 = V_59 != 0 || V_60 != 0 ;
V_67 = V_62 -> V_73 ;
if ( V_66 ) {
V_63 = V_67 != V_64 ||
V_62 -> V_74 [ 0 ] != V_59 ||
V_62 -> V_74 [ 1 ] != V_60 ;
V_62 -> V_74 [ 0 ] = V_59 ;
V_62 -> V_74 [ 1 ] = V_60 ;
V_62 -> V_73 = V_64 ;
V_2 -> V_3 . V_75 = V_64 ;
}
F_39 ( & V_62 -> V_72 ) ;
if ( V_63 ) {
switch ( V_2 -> V_54 -> V_76 ) {
case V_77 :
switch ( V_64 ) {
case V_78 :
F_40 ( V_79 ,
0xc0 , 0xc0 ) ;
F_40 ( V_80 ,
0x03 , 0x00 ) ;
break;
case V_81 :
case V_82 :
V_70 = ( V_81 == V_64 ) ?
0x00 : 0x08 ;
V_71 = ( 32000 == V_2 -> V_3 . V_71 ) ?
0x01 : 0x03 ;
F_40 ( V_83 ,
0x08 , V_70 ) ;
F_40 ( V_79 ,
0xc0 , 0x80 ) ;
F_40 ( V_80 ,
0x03 , V_71 ) ;
break;
}
break;
case V_84 :
case V_85 :
V_69 = 0x03 ;
V_68 = 0 ;
switch ( V_64 ) {
case V_78 :
V_69 = 0 ;
V_68 = 2 ;
break;
case V_81 :
V_68 = 0 ;
break;
case V_82 :
V_68 = 9 ;
break;
}
F_41 ( V_2 , V_86 ,
0xbbbb10 ) ;
if ( V_59 || V_60 ) {
F_41 ( V_2 , V_87 ,
V_69 ) ;
F_13 ( V_88 , V_68 ) ;
} else {
F_41 ( V_2 , V_87 ,
0 ) ;
F_13 ( V_88 , 0 ) ;
}
break;
}
}
if ( V_63 ) {
if ( V_61 )
F_42 ( V_62 -> V_89 ,
V_90 ,
& V_62 -> V_91 [ V_64 ] -> V_92 ) ;
if ( V_67 != V_93 && V_67 != V_64 )
F_42 ( V_62 -> V_89 ,
V_90 ,
& V_62 -> V_91 [ V_67 ] -> V_92 ) ;
}
return V_63 ;
}
static int F_43 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
int V_94 , V_95 ;
T_4 V_96 , V_97 ;
T_3 * V_98 = F_44 ( V_16 ) ;
struct V_1 * V_2 ;
T_2 * V_35 = V_34 -> V_36 ;
V_35 -> V_2 -> V_3 . V_16 = V_16 ;
V_2 = V_98 -> V_2 ;
if ( F_45 ( V_34 -> V_99 ) == 8 )
V_96 = 0x00 ;
else
V_96 = 0x01 ;
if ( F_46 ( V_34 -> V_99 ) )
V_95 = 1 ;
else
V_95 = 0 ;
if ( F_47 ( V_34 -> V_99 ) )
V_94 = 1 ;
else
V_94 = 0 ;
switch ( V_2 -> V_54 -> V_76 ) {
case V_77 :
if ( 1 == V_34 -> V_100 )
V_96 |= ( 1 << 3 ) ;
if ( 2 == V_34 -> V_100 )
V_96 |= ( 3 << 3 ) ;
if ( V_95 )
V_96 |= 0x04 ;
V_96 |= ( V_78 == V_2 -> V_3 . V_75 ) ? 0xc0 : 0x80 ;
F_48 ( V_101 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x0000ff ) ) ;
F_48 ( V_102 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x00ff00 ) >> 8 ) ;
F_48 ( V_103 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0xff0000 ) >> 16 ) ;
F_48 ( V_79 , V_96 ) ;
break;
case V_84 :
case V_85 :
if ( 1 == V_34 -> V_100 )
V_96 |= ( 1 << 4 ) ;
if ( 2 == V_34 -> V_100 )
V_96 |= ( 2 << 4 ) ;
if ( ! V_95 )
V_96 |= 0x04 ;
F_13 ( V_104 , V_2 -> V_3 . V_13 - 1 ) ;
F_13 ( V_105 , 0x543210 | ( V_96 << 24 ) ) ;
break;
}
F_6 ( L_13 ,
V_34 -> V_99 , V_34 -> V_100 , V_96 ,
V_94 ? 'b' : '-' ) ;
V_97 = V_106 |
V_107 |
( V_2 -> V_3 . V_108 . V_42 >> 12 ) ;
if ( V_94 )
V_97 |= V_109 ;
F_13 ( F_7 ( 6 ) , 0 ) ;
F_13 ( F_8 ( 6 ) , V_2 -> V_3 . V_13 ) ;
F_13 ( F_49 ( 6 ) , 0 ) ;
F_13 ( F_50 ( 6 ) , V_97 ) ;
V_2 -> V_3 . V_71 = V_34 -> V_71 ;
F_36 ( V_98 -> V_91 [ V_2 -> V_3 . V_75 ] , 1 , 1 ,
true ) ;
return 0 ;
}
static T_5
F_51 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
T_2 * V_35 = V_34 -> V_36 ;
struct V_1 * V_2 = V_35 -> V_2 ;
if ( V_2 -> V_3 . V_12 ) {
V_2 -> V_3 . V_12 -= F_14 ( V_16 ) ;
V_2 -> V_3 . V_110 += F_14 ( V_16 ) ;
if ( V_2 -> V_3 . V_110 == V_2 -> V_3 . V_15 )
V_2 -> V_3 . V_110 = 0 ;
}
return F_52 ( V_34 , V_2 -> V_3 . V_110 ) ;
}
static void F_53 ( struct V_33 * V_34 )
{
T_2 * V_35 = V_34 -> V_36 ;
F_54 ( V_35 ) ;
}
static int F_55 ( struct V_31 * V_16 ,
struct V_111 * V_112 )
{
T_3 * V_98 = F_44 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned int V_113 , V_114 ;
int V_37 ;
V_113 = F_56 ( V_112 ) ;
V_114 = F_57 ( V_112 ) ;
if ( V_113 < 0x100 || V_113 > 0x10000 )
return - V_40 ;
if ( V_114 < 4 )
return - V_40 ;
if ( V_113 * V_114 > 1024 * 1024 )
return - V_40 ;
V_2 = V_98 -> V_2 ;
if ( V_2 -> V_3 . V_14 == V_114 &&
V_2 -> V_3 . V_13 == V_113 )
return 0 ;
if ( V_16 -> V_34 -> V_115 ) {
F_58 ( V_2 -> V_54 , & V_2 -> V_3 . V_108 ) ;
F_30 ( V_2 ) ;
F_35 ( V_2 ) ;
V_16 -> V_34 -> V_115 = NULL ;
}
V_2 -> V_3 . V_14 = V_114 ;
V_2 -> V_3 . V_13 = V_113 ;
V_2 -> V_3 . V_15 = V_113 * V_114 ;
V_37 = F_33 ( V_2 ) ;
if ( 0 != V_37 ) {
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return V_37 ;
}
V_37 = F_27 ( V_2 ) ;
if ( V_37 ) {
F_35 ( V_2 ) ;
return V_37 ;
}
V_37 = F_59 ( V_2 -> V_54 , & V_2 -> V_3 . V_108 ) ;
if ( V_37 ) {
F_30 ( V_2 ) ;
F_35 ( V_2 ) ;
return V_37 ;
}
V_37 = F_60 ( V_2 -> V_54 , & V_2 -> V_3 . V_108 ,
V_2 -> V_3 . V_49 , V_2 -> V_3 . V_53 , 0 ) ;
if ( V_37 ) {
F_58 ( V_2 -> V_54 , & V_2 -> V_3 . V_108 ) ;
F_30 ( V_2 ) ;
F_35 ( V_2 ) ;
return V_37 ;
}
V_16 -> V_34 -> V_115 = V_2 -> V_3 . V_46 ;
V_16 -> V_34 -> V_116 = V_2 -> V_3 . V_15 ;
V_16 -> V_34 -> V_117 = 0 ;
return 0 ;
}
static int F_61 ( struct V_31 * V_16 )
{
T_3 * V_98 = F_44 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = V_98 -> V_2 ;
if ( V_16 -> V_34 -> V_115 ) {
F_58 ( V_2 -> V_54 , & V_2 -> V_3 . V_108 ) ;
F_30 ( V_2 ) ;
F_35 ( V_2 ) ;
V_16 -> V_34 -> V_115 = NULL ;
}
return 0 ;
}
static int F_62 ( struct V_31 * V_16 )
{
T_3 * V_98 = F_44 ( V_16 ) ;
struct V_1 * V_2 = V_98 -> V_2 ;
if ( V_98 -> V_118 ) {
V_2 -> V_119 = 1 ;
F_63 ( V_2 ) ;
}
return 0 ;
}
static int F_64 ( struct V_31 * V_16 )
{
struct V_33 * V_34 = V_16 -> V_34 ;
T_2 * V_35 ;
T_3 * V_98 = F_44 ( V_16 ) ;
struct V_1 * V_2 ;
int V_120 , V_37 ;
if ( ! V_98 ) {
F_65 ( V_121 L_14
L_15 ) ;
return - V_122 ;
}
V_2 = V_98 -> V_2 ;
F_66 ( & V_2 -> V_3 . V_123 ) ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_110 = 0 ;
V_120 = V_2 -> V_75 -> V_120 ;
if ( ( V_120 < 1 ) || ( V_120 > 3 ) )
V_120 = 1 ;
V_2 -> V_3 . V_75 = V_120 - 1 ;
F_67 ( & V_2 -> V_3 . V_123 ) ;
V_35 = F_68 ( sizeof( * V_35 ) , V_124 ) ;
if ( V_35 == NULL )
return - V_48 ;
V_35 -> V_2 = V_98 -> V_2 ;
F_69 ( & V_35 -> V_123 ) ;
V_35 -> V_16 = V_16 ;
V_34 -> V_36 = V_35 ;
V_34 -> V_125 = F_53 ;
V_34 -> V_126 = V_127 ;
if ( V_2 -> V_119 != 0 ) {
V_98 -> V_118 = 1 ;
V_2 -> V_119 = 0 ;
F_63 ( V_2 ) ;
}
V_37 = F_70 ( V_34 ,
V_128 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_71 ( V_34 , 0 ,
V_128 , 2 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static struct V_43 * F_72 ( struct V_31 * V_16 ,
unsigned long V_129 )
{
void * V_130 = V_16 -> V_34 -> V_115 + V_129 ;
return F_24 ( V_130 ) ;
}
static int F_73 ( T_3 * V_98 , int V_76 )
{
struct V_131 * V_35 ;
int V_37 ;
if ( ( V_37 = F_74 ( V_98 -> V_89 , L_16 , V_76 , 0 , 1 , & V_35 ) ) < 0 )
return V_37 ;
F_75 ( V_35 , V_132 , & V_133 ) ;
V_35 -> V_36 = V_98 ;
V_35 -> V_134 = 0 ;
strcpy ( V_35 -> V_135 , L_16 ) ;
return 0 ;
}
static int F_76 ( struct V_57 * V_58 ,
struct V_136 * V_137 )
{
V_137 -> type = V_138 ;
V_137 -> V_139 = 2 ;
V_137 -> V_140 . integer . V_141 = 0 ;
V_137 -> V_140 . integer . V_142 = 20 ;
return 0 ;
}
static int F_77 ( struct V_57 * V_58 ,
struct V_143 * V_144 )
{
T_3 * V_62 = F_37 ( V_58 ) ;
int V_64 = V_58 -> V_65 ;
V_144 -> V_140 . integer . V_140 [ 0 ] = V_62 -> V_145 [ V_64 ] [ 0 ] ;
V_144 -> V_140 . integer . V_140 [ 1 ] = V_62 -> V_145 [ V_64 ] [ 1 ] ;
return 0 ;
}
static int F_78 ( struct V_57 * V_58 ,
struct V_143 * V_144 )
{
T_3 * V_62 = F_37 ( V_58 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
int V_63 , V_64 = V_58 -> V_65 ;
int V_59 , V_60 ;
V_59 = V_144 -> V_140 . integer . V_140 [ 0 ] ;
if ( V_59 < 0 )
V_59 = 0 ;
if ( V_59 > 20 )
V_59 = 20 ;
V_60 = V_144 -> V_140 . integer . V_140 [ 1 ] ;
if ( V_60 < 0 )
V_60 = 0 ;
if ( V_60 > 20 )
V_60 = 20 ;
F_38 ( & V_62 -> V_72 ) ;
V_63 = 0 ;
if ( V_62 -> V_145 [ V_64 ] [ 0 ] != V_59 ) {
V_63 = 1 ;
V_60 = V_59 ;
}
if ( V_62 -> V_145 [ V_64 ] [ 1 ] != V_60 ) {
V_63 = 1 ;
V_59 = V_60 ;
}
if ( V_63 ) {
switch ( V_2 -> V_54 -> V_76 ) {
case V_77 :
switch ( V_64 ) {
case V_78 :
V_59 = 20 ;
break;
case V_81 :
F_40 ( V_83 , 0x10 ,
( V_59 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_82 :
F_40 ( V_83 , 0x20 ,
( V_59 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
case V_84 :
case V_85 :
switch ( V_64 ) {
case V_78 :
V_59 = 20 ;
break;
case V_81 :
F_40 ( 0x0594 , 0x10 ,
( V_59 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_82 :
F_40 ( 0x0594 , 0x20 ,
( V_59 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
}
V_62 -> V_145 [ V_64 ] [ 0 ] = V_59 ;
V_62 -> V_145 [ V_64 ] [ 1 ] = V_60 ;
}
F_39 ( & V_62 -> V_72 ) ;
return V_63 ;
}
static int F_79 ( struct V_57 * V_58 ,
struct V_136 * V_137 )
{
V_137 -> type = V_146 ;
V_137 -> V_139 = 2 ;
V_137 -> V_140 . integer . V_141 = 0 ;
V_137 -> V_140 . integer . V_142 = 1 ;
return 0 ;
}
static int F_80 ( struct V_57 * V_58 ,
struct V_143 * V_144 )
{
T_3 * V_62 = F_37 ( V_58 ) ;
int V_64 = V_58 -> V_65 ;
F_38 ( & V_62 -> V_72 ) ;
if ( V_62 -> V_73 == V_64 ) {
V_144 -> V_140 . integer . V_140 [ 0 ] = V_62 -> V_74 [ 0 ] ;
V_144 -> V_140 . integer . V_140 [ 1 ] = V_62 -> V_74 [ 1 ] ;
} else {
V_144 -> V_140 . integer . V_140 [ 0 ] = 0 ;
V_144 -> V_140 . integer . V_140 [ 1 ] = 0 ;
}
F_39 ( & V_62 -> V_72 ) ;
return 0 ;
}
static int F_81 ( struct V_57 * V_58 ,
struct V_143 * V_144 )
{
int V_59 , V_60 ;
V_59 = V_144 -> V_140 . integer . V_140 [ 0 ] & 1 ;
V_60 = V_144 -> V_140 . integer . V_140 [ 1 ] & 1 ;
return F_36 ( V_58 , V_59 , V_60 , false ) ;
}
static int F_82 ( T_3 * V_62 )
{
struct V_147 * V_89 = V_62 -> V_89 ;
struct V_57 * V_58 ;
unsigned int V_148 ;
int V_37 , V_64 ;
strcpy ( V_89 -> V_149 , L_17 ) ;
for ( V_148 = 0 ; V_148 < F_83 ( V_150 ) ; V_148 ++ ) {
V_58 = F_84 ( & V_150 [ V_148 ] ,
V_62 ) ;
V_37 = F_85 ( V_89 , V_58 ) ;
if ( V_37 < 0 )
return V_37 ;
}
for ( V_148 = 0 ; V_148 < F_83 ( V_151 ) ; V_148 ++ ) {
V_58 = F_84 ( & V_151 [ V_148 ] ,
V_62 ) ;
V_64 = V_151 [ V_148 ] . V_65 ;
V_62 -> V_91 [ V_64 ] = V_58 ;
V_37 = F_85 ( V_89 , V_58 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_62 -> V_73 = V_93 ;
return 0 ;
}
static void F_86 ( struct V_147 * V_89 )
{
T_3 * V_62 = V_89 -> V_36 ;
if ( V_62 -> V_2 -> V_3 . V_23 == NULL )
return;
if ( V_62 -> V_20 >= 0 )
F_87 ( V_62 -> V_20 , & V_62 -> V_2 -> V_3 ) ;
V_62 -> V_2 -> V_3 . V_23 = NULL ;
}
static int F_88 ( struct V_1 * V_2 , int V_152 )
{
struct V_147 * V_89 ;
T_3 * V_62 ;
int V_37 ;
if ( V_152 >= V_153 )
return - V_122 ;
if ( ! V_154 [ V_152 ] )
return - V_122 ;
V_37 = F_89 ( & V_2 -> V_54 -> V_2 , V_155 [ V_152 ] , V_92 [ V_152 ] ,
V_156 , sizeof( T_3 ) , & V_89 ) ;
if ( V_37 < 0 )
return V_37 ;
strcpy ( V_89 -> V_157 , L_18 ) ;
V_89 -> V_125 = F_86 ;
V_62 = V_89 -> V_36 ;
F_69 ( & V_62 -> V_123 ) ;
F_69 ( & V_62 -> V_72 ) ;
V_62 -> V_2 = V_2 ;
V_62 -> V_89 = V_89 ;
V_62 -> V_54 = V_2 -> V_54 ;
V_62 -> V_158 = F_90 ( V_2 -> V_54 , 0 ) ;
V_37 = F_91 ( V_2 -> V_54 -> V_20 , F_16 ,
V_159 , V_2 -> V_135 ,
( void * ) & V_2 -> V_3 ) ;
if ( V_37 < 0 ) {
F_65 ( V_121 L_19 ,
V_2 -> V_135 , V_2 -> V_54 -> V_20 ) ;
goto V_160;
}
V_62 -> V_20 = V_2 -> V_54 -> V_20 ;
F_92 ( & V_2 -> V_3 . V_123 ) ;
if ( ( V_37 = F_82 ( V_62 ) ) < 0 )
goto V_160;
if ( ( V_37 = F_73 ( V_62 , 0 ) ) < 0 )
goto V_160;
strcpy ( V_89 -> V_161 , L_18 ) ;
sprintf ( V_89 -> V_162 , L_20 ,
V_62 -> V_2 -> V_135 , V_62 -> V_158 , V_62 -> V_20 ) ;
F_65 ( V_163 L_21 , V_2 -> V_135 , V_89 -> V_162 , V_155 [ V_152 ] ) ;
if ( ( V_37 = F_93 ( V_89 ) ) == 0 ) {
V_164 [ V_152 ] = V_89 ;
return 0 ;
}
V_160:
F_94 ( V_89 ) ;
return V_37 ;
}
static int F_95 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_23 = V_2 ;
F_88 ( V_2 , V_2 -> V_165 ) ;
return 1 ;
}
static int F_96 ( struct V_1 * V_2 )
{
F_94 ( V_164 [ V_2 -> V_165 ] ) ;
V_164 [ V_2 -> V_165 ] = NULL ;
return 1 ;
}
static int F_97 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_166 * V_167 ;
V_168 = F_95 ;
V_169 = F_96 ;
F_65 ( V_163 L_22 ) ;
F_98 (list,&saa7134_devlist) {
V_2 = F_99 ( V_167 , struct V_1 , V_170 ) ;
if ( V_2 -> V_54 -> V_76 == V_171 )
F_65 ( V_163 L_23 ,
V_2 -> V_135 , V_172 [ V_2 -> V_173 ] . V_135 ) ;
else
F_95 ( V_2 ) ;
}
if ( V_2 == NULL )
F_65 ( V_163 L_24 ) ;
return 0 ;
}
static void F_100 ( void )
{
int V_148 ;
for ( V_148 = 0 ; V_148 < V_153 ; V_148 ++ ) {
F_94 ( V_164 [ V_148 ] ) ;
}
V_168 = NULL ;
V_169 = NULL ;
F_65 ( V_163 L_25 ) ;
return;
}
