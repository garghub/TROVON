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
return;
}
V_7 = ( V_2 -> V_3 . V_4 + 2 ) % V_2 -> V_3 . V_14 ;
F_11 ( V_8 , V_7 * V_2 -> V_3 . V_13 ) ;
if ( V_17 > 2 )
F_6 ( L_7 ,
( V_6 & 0x10000000 ) ? L_4 : L_8 , V_7 ,
V_7 * V_2 -> V_3 . V_13 , V_2 -> V_3 . V_14 , V_2 -> V_3 . V_13 , V_2 -> V_3 . V_12 ) ;
V_2 -> V_3 . V_4 = ( V_2 -> V_3 . V_4 + 1 ) % V_2 -> V_3 . V_14 ;
V_2 -> V_3 . V_12 += V_2 -> V_3 . V_13 ;
V_2 -> V_3 . V_18 = V_8 ;
if ( V_2 -> V_3 . V_12 >= F_12 ( V_2 -> V_3 . V_16 ) ) {
F_9 ( & V_2 -> V_9 ) ;
F_13 ( V_2 -> V_3 . V_16 ) ;
F_5 ( & V_2 -> V_9 ) ;
}
V_11:
F_9 ( & V_2 -> V_9 ) ;
}
static T_1 F_14 ( int V_19 , void * V_20 )
{
struct V_21 * V_3 = V_20 ;
struct V_1 * V_2 = V_3 -> V_22 ;
unsigned long V_23 , V_6 ;
int V_24 , V_25 = 0 ;
for ( V_24 = 0 ; V_24 < 10 ; V_24 ++ ) {
V_23 = F_15 ( V_26 ) ;
V_6 = F_15 ( V_27 ) ;
if ( V_23 & V_28 ) {
V_25 = 1 ;
F_11 ( V_26 ,
V_28 ) ;
F_4 ( V_2 , V_6 ) ;
} else {
goto V_29;
}
}
if ( V_24 == 10 ) {
F_6 ( L_9 ) ;
}
V_29:
return F_16 ( V_25 ) ;
}
static int F_17 ( struct V_30 * V_16 ,
int V_31 )
{
struct V_32 * V_33 = V_16 -> V_33 ;
T_2 * V_34 = V_33 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
int V_36 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
if ( V_31 == V_37 ) {
F_3 ( V_2 ) ;
} else if ( V_31 == V_38 ) {
F_1 ( V_2 ) ;
} else {
V_36 = - V_39 ;
}
F_9 ( & V_2 -> V_9 ) ;
return V_36 ;
}
static int F_18 ( struct V_1 * V_2 , int V_40 )
{
struct V_21 * V_41 = & V_2 -> V_3 ;
struct V_42 * V_43 ;
int V_44 ;
V_41 -> V_45 = F_19 ( V_40 << V_46 ) ;
if ( NULL == V_41 -> V_45 ) {
F_6 ( L_10 , V_40 ) ;
return - V_47 ;
}
F_6 ( L_11 ,
( unsigned long ) V_41 -> V_45 ,
V_40 << V_46 ) ;
memset ( V_41 -> V_45 , 0 , V_40 << V_46 ) ;
V_41 -> V_40 = V_40 ;
V_41 -> V_48 = F_20 ( V_41 -> V_40 * sizeof( * V_41 -> V_48 ) ) ;
if ( NULL == V_41 -> V_48 )
goto V_49;
F_21 ( V_41 -> V_48 , V_41 -> V_40 ) ;
for ( V_44 = 0 ; V_44 < V_41 -> V_40 ; V_44 ++ ) {
V_43 = F_22 ( V_41 -> V_45 + V_44 * V_50 ) ;
if ( NULL == V_43 )
goto V_51;
F_23 ( & V_41 -> V_48 [ V_44 ] , V_43 , V_50 , 0 ) ;
}
return 0 ;
V_51:
F_24 ( V_41 -> V_48 ) ;
V_41 -> V_48 = NULL ;
V_49:
F_24 ( V_41 -> V_45 ) ;
V_41 -> V_45 = NULL ;
return - V_47 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_21 * V_41 = & V_2 -> V_3 ;
V_41 -> V_52 = F_26 ( & V_2 -> V_53 -> V_2 , V_41 -> V_48 ,
V_41 -> V_40 , V_54 ) ;
if ( 0 == V_41 -> V_52 ) {
F_27 ( L_12 , V_55 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_41 = & V_2 -> V_3 ;
if ( ! V_41 -> V_52 )
return 0 ;
F_29 ( & V_2 -> V_53 -> V_2 , V_41 -> V_48 , V_41 -> V_52 , V_54 ) ;
V_41 -> V_52 = 0 ;
return 0 ;
}
static int F_30 ( struct V_21 * V_41 )
{
F_24 ( V_41 -> V_48 ) ;
V_41 -> V_48 = NULL ;
F_24 ( V_41 -> V_45 ) ;
V_41 -> V_45 = NULL ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_36 ;
F_32 ( ! V_2 -> V_3 . V_15 ) ;
V_36 = F_18 ( V_2 ,
( V_2 -> V_3 . V_15 + V_50 ) >> V_46 ) ;
if ( 0 != V_36 )
return V_36 ;
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
static int F_34 ( struct V_56 * V_57 ,
int V_58 , int V_59 , bool V_60 )
{
T_3 * V_61 = F_35 ( V_57 ) ;
int V_62 = 0 , V_63 = V_57 -> V_64 ;
int V_65 , V_66 ;
T_4 V_67 , V_68 ;
int V_69 , V_70 ;
struct V_1 * V_2 ;
V_2 = V_61 -> V_2 ;
F_36 ( & V_61 -> V_71 ) ;
V_65 = V_58 != 0 || V_59 != 0 ;
V_66 = V_61 -> V_72 ;
if ( V_65 ) {
V_62 = V_66 != V_63 ||
V_61 -> V_73 [ 0 ] != V_58 ||
V_61 -> V_73 [ 1 ] != V_59 ;
V_61 -> V_73 [ 0 ] = V_58 ;
V_61 -> V_73 [ 1 ] = V_59 ;
V_61 -> V_72 = V_63 ;
V_2 -> V_3 . V_74 = V_63 ;
}
F_37 ( & V_61 -> V_71 ) ;
if ( V_62 ) {
switch ( V_2 -> V_53 -> V_75 ) {
case V_76 :
switch ( V_63 ) {
case V_77 :
F_38 ( V_78 ,
0xc0 , 0xc0 ) ;
F_38 ( V_79 ,
0x03 , 0x00 ) ;
break;
case V_80 :
case V_81 :
V_69 = ( V_80 == V_63 ) ?
0x00 : 0x08 ;
V_70 = ( 32000 == V_2 -> V_3 . V_70 ) ?
0x01 : 0x03 ;
F_38 ( V_82 ,
0x08 , V_69 ) ;
F_38 ( V_78 ,
0xc0 , 0x80 ) ;
F_38 ( V_79 ,
0x03 , V_70 ) ;
break;
}
break;
case V_83 :
case V_84 :
V_68 = 0x03 ;
V_67 = 0 ;
switch ( V_63 ) {
case V_77 :
V_68 = 0 ;
V_67 = 2 ;
break;
case V_80 :
V_67 = 0 ;
break;
case V_81 :
V_67 = 9 ;
break;
}
F_39 ( V_2 , V_85 ,
0xbbbb10 ) ;
if ( V_58 || V_59 ) {
F_39 ( V_2 , V_86 ,
V_68 ) ;
F_11 ( V_87 , V_67 ) ;
} else {
F_39 ( V_2 , V_86 ,
0 ) ;
F_11 ( V_87 , 0 ) ;
}
break;
}
}
if ( V_62 ) {
if ( V_60 )
F_40 ( V_61 -> V_88 ,
V_89 ,
& V_61 -> V_90 [ V_63 ] -> V_91 ) ;
if ( V_66 != V_92 && V_66 != V_63 )
F_40 ( V_61 -> V_88 ,
V_89 ,
& V_61 -> V_90 [ V_66 ] -> V_91 ) ;
}
return V_62 ;
}
static int F_41 ( struct V_30 * V_16 )
{
struct V_32 * V_33 = V_16 -> V_33 ;
int V_93 , V_94 ;
T_4 V_95 , V_96 ;
T_3 * V_97 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
T_2 * V_34 = V_33 -> V_35 ;
V_34 -> V_2 -> V_3 . V_16 = V_16 ;
V_2 = V_97 -> V_2 ;
if ( F_43 ( V_33 -> V_98 ) == 8 )
V_95 = 0x00 ;
else
V_95 = 0x01 ;
if ( F_44 ( V_33 -> V_98 ) )
V_94 = 1 ;
else
V_94 = 0 ;
if ( F_45 ( V_33 -> V_98 ) )
V_93 = 1 ;
else
V_93 = 0 ;
switch ( V_2 -> V_53 -> V_75 ) {
case V_76 :
if ( 1 == V_33 -> V_99 )
V_95 |= ( 1 << 3 ) ;
if ( 2 == V_33 -> V_99 )
V_95 |= ( 3 << 3 ) ;
if ( V_94 )
V_95 |= 0x04 ;
V_95 |= ( V_77 == V_2 -> V_3 . V_74 ) ? 0xc0 : 0x80 ;
F_46 ( V_100 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x0000ff ) ) ;
F_46 ( V_101 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0x00ff00 ) >> 8 ) ;
F_46 ( V_102 , ( ( V_2 -> V_3 . V_13 - 1 ) & 0xff0000 ) >> 16 ) ;
F_46 ( V_78 , V_95 ) ;
break;
case V_83 :
case V_84 :
if ( 1 == V_33 -> V_99 )
V_95 |= ( 1 << 4 ) ;
if ( 2 == V_33 -> V_99 )
V_95 |= ( 2 << 4 ) ;
if ( ! V_94 )
V_95 |= 0x04 ;
F_11 ( V_103 , V_2 -> V_3 . V_13 - 1 ) ;
F_11 ( V_104 , 0x543210 | ( V_95 << 24 ) ) ;
break;
}
F_6 ( L_13 ,
V_33 -> V_98 , V_33 -> V_99 , V_95 ,
V_93 ? 'b' : '-' ) ;
V_96 = V_105 |
V_106 |
( V_2 -> V_3 . V_107 . V_41 >> 12 ) ;
if ( V_93 )
V_96 |= V_108 ;
F_11 ( F_7 ( 6 ) , 0 ) ;
F_11 ( F_8 ( 6 ) , V_2 -> V_3 . V_13 ) ;
F_11 ( F_47 ( 6 ) , 0 ) ;
F_11 ( F_48 ( 6 ) , V_96 ) ;
V_2 -> V_3 . V_70 = V_33 -> V_70 ;
F_34 ( V_97 -> V_90 [ V_2 -> V_3 . V_74 ] , 1 , 1 ,
true ) ;
return 0 ;
}
static T_5
F_49 ( struct V_30 * V_16 )
{
struct V_32 * V_33 = V_16 -> V_33 ;
T_2 * V_34 = V_33 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_2 ;
if ( V_2 -> V_3 . V_12 ) {
V_2 -> V_3 . V_12 -= F_12 ( V_16 ) ;
V_2 -> V_3 . V_109 += F_12 ( V_16 ) ;
if ( V_2 -> V_3 . V_109 == V_2 -> V_3 . V_15 )
V_2 -> V_3 . V_109 = 0 ;
}
return F_50 ( V_33 , V_2 -> V_3 . V_109 ) ;
}
static void F_51 ( struct V_32 * V_33 )
{
T_2 * V_34 = V_33 -> V_35 ;
F_52 ( V_34 ) ;
}
static int F_53 ( struct V_30 * V_16 ,
struct V_110 * V_111 )
{
T_3 * V_97 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
unsigned int V_112 , V_113 ;
int V_36 ;
V_112 = F_54 ( V_111 ) ;
V_113 = F_55 ( V_111 ) ;
if ( V_112 < 0x100 || V_112 > 0x10000 )
return - V_39 ;
if ( V_113 < 4 )
return - V_39 ;
if ( V_112 * V_113 > 1024 * 1024 )
return - V_39 ;
V_2 = V_97 -> V_2 ;
if ( V_2 -> V_3 . V_14 == V_113 &&
V_2 -> V_3 . V_13 == V_112 )
return 0 ;
if ( V_16 -> V_33 -> V_114 ) {
F_56 ( V_2 -> V_53 , & V_2 -> V_3 . V_107 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
V_16 -> V_33 -> V_114 = NULL ;
}
V_2 -> V_3 . V_14 = V_113 ;
V_2 -> V_3 . V_13 = V_112 ;
V_2 -> V_3 . V_15 = V_112 * V_113 ;
V_36 = F_31 ( V_2 ) ;
if ( 0 != V_36 ) {
V_2 -> V_3 . V_14 = 0 ;
V_2 -> V_3 . V_13 = 0 ;
V_2 -> V_3 . V_15 = 0 ;
return V_36 ;
}
V_36 = F_25 ( V_2 ) ;
if ( V_36 ) {
F_33 ( V_2 ) ;
return V_36 ;
}
V_36 = F_57 ( V_2 -> V_53 , & V_2 -> V_3 . V_107 ) ;
if ( V_36 ) {
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_36 ;
}
V_36 = F_58 ( V_2 -> V_53 , & V_2 -> V_3 . V_107 ,
V_2 -> V_3 . V_48 , V_2 -> V_3 . V_52 , 0 ) ;
if ( V_36 ) {
F_56 ( V_2 -> V_53 , & V_2 -> V_3 . V_107 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
return V_36 ;
}
V_16 -> V_33 -> V_114 = V_2 -> V_3 . V_45 ;
V_16 -> V_33 -> V_115 = V_2 -> V_3 . V_15 ;
V_16 -> V_33 -> V_116 = 0 ;
return 0 ;
}
static int F_59 ( struct V_30 * V_16 )
{
T_3 * V_97 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = V_97 -> V_2 ;
if ( V_16 -> V_33 -> V_114 ) {
F_56 ( V_2 -> V_53 , & V_2 -> V_3 . V_107 ) ;
F_28 ( V_2 ) ;
F_33 ( V_2 ) ;
V_16 -> V_33 -> V_114 = NULL ;
}
return 0 ;
}
static int F_60 ( struct V_30 * V_16 )
{
T_3 * V_97 = F_42 ( V_16 ) ;
struct V_1 * V_2 = V_97 -> V_2 ;
if ( V_97 -> V_117 ) {
V_2 -> V_118 = 1 ;
F_61 ( V_2 ) ;
}
return 0 ;
}
static int F_62 ( struct V_30 * V_16 )
{
struct V_32 * V_33 = V_16 -> V_33 ;
T_2 * V_34 ;
T_3 * V_97 = F_42 ( V_16 ) ;
struct V_1 * V_2 ;
int V_119 , V_36 ;
if ( ! V_97 ) {
F_63 ( V_120 L_14
L_15 ) ;
return - V_121 ;
}
V_2 = V_97 -> V_2 ;
F_64 ( & V_2 -> V_3 . V_122 ) ;
V_2 -> V_3 . V_12 = 0 ;
V_2 -> V_3 . V_109 = 0 ;
V_119 = V_2 -> V_74 -> V_119 ;
if ( ( V_119 < 1 ) || ( V_119 > 3 ) )
V_119 = 1 ;
V_2 -> V_3 . V_74 = V_119 - 1 ;
F_65 ( & V_2 -> V_3 . V_122 ) ;
V_34 = F_66 ( sizeof( * V_34 ) , V_123 ) ;
if ( V_34 == NULL )
return - V_47 ;
V_34 -> V_2 = V_97 -> V_2 ;
F_67 ( & V_34 -> V_122 ) ;
V_34 -> V_16 = V_16 ;
V_33 -> V_35 = V_34 ;
V_33 -> V_124 = F_51 ;
V_33 -> V_125 = V_126 ;
if ( V_2 -> V_118 != 0 ) {
V_97 -> V_117 = 1 ;
V_2 -> V_118 = 0 ;
F_61 ( V_2 ) ;
}
V_36 = F_68 ( V_33 ,
V_127 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_69 ( V_33 , 0 ,
V_127 , 2 ) ;
if ( V_36 < 0 )
return V_36 ;
return 0 ;
}
static struct V_42 * F_70 ( struct V_30 * V_16 ,
unsigned long V_128 )
{
void * V_129 = V_16 -> V_33 -> V_114 + V_128 ;
return F_22 ( V_129 ) ;
}
static int F_71 ( T_3 * V_97 , int V_75 )
{
struct V_130 * V_34 ;
int V_36 ;
if ( ( V_36 = F_72 ( V_97 -> V_88 , L_16 , V_75 , 0 , 1 , & V_34 ) ) < 0 )
return V_36 ;
F_73 ( V_34 , V_131 , & V_132 ) ;
V_34 -> V_35 = V_97 ;
V_34 -> V_133 = 0 ;
strcpy ( V_34 -> V_134 , L_16 ) ;
return 0 ;
}
static int F_74 ( struct V_56 * V_57 ,
struct V_135 * V_136 )
{
V_136 -> type = V_137 ;
V_136 -> V_138 = 2 ;
V_136 -> V_139 . integer . V_140 = 0 ;
V_136 -> V_139 . integer . V_141 = 20 ;
return 0 ;
}
static int F_75 ( struct V_56 * V_57 ,
struct V_142 * V_143 )
{
T_3 * V_61 = F_35 ( V_57 ) ;
int V_63 = V_57 -> V_64 ;
V_143 -> V_139 . integer . V_139 [ 0 ] = V_61 -> V_144 [ V_63 ] [ 0 ] ;
V_143 -> V_139 . integer . V_139 [ 1 ] = V_61 -> V_144 [ V_63 ] [ 1 ] ;
return 0 ;
}
static int F_76 ( struct V_56 * V_57 ,
struct V_142 * V_143 )
{
T_3 * V_61 = F_35 ( V_57 ) ;
struct V_1 * V_2 = V_61 -> V_2 ;
int V_62 , V_63 = V_57 -> V_64 ;
int V_58 , V_59 ;
V_58 = V_143 -> V_139 . integer . V_139 [ 0 ] ;
if ( V_58 < 0 )
V_58 = 0 ;
if ( V_58 > 20 )
V_58 = 20 ;
V_59 = V_143 -> V_139 . integer . V_139 [ 1 ] ;
if ( V_59 < 0 )
V_59 = 0 ;
if ( V_59 > 20 )
V_59 = 20 ;
F_36 ( & V_61 -> V_71 ) ;
V_62 = 0 ;
if ( V_61 -> V_144 [ V_63 ] [ 0 ] != V_58 ) {
V_62 = 1 ;
V_59 = V_58 ;
}
if ( V_61 -> V_144 [ V_63 ] [ 1 ] != V_59 ) {
V_62 = 1 ;
V_58 = V_59 ;
}
if ( V_62 ) {
switch ( V_2 -> V_53 -> V_75 ) {
case V_76 :
switch ( V_63 ) {
case V_77 :
V_58 = 20 ;
break;
case V_80 :
F_38 ( V_82 , 0x10 ,
( V_58 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_81 :
F_38 ( V_82 , 0x20 ,
( V_58 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
case V_83 :
case V_84 :
switch ( V_63 ) {
case V_77 :
V_58 = 20 ;
break;
case V_80 :
F_38 ( 0x0594 , 0x10 ,
( V_58 > 10 ) ? 0x00 : 0x10 ) ;
break;
case V_81 :
F_38 ( 0x0594 , 0x20 ,
( V_58 > 10 ) ? 0x00 : 0x20 ) ;
break;
}
break;
}
V_61 -> V_144 [ V_63 ] [ 0 ] = V_58 ;
V_61 -> V_144 [ V_63 ] [ 1 ] = V_59 ;
}
F_37 ( & V_61 -> V_71 ) ;
return V_62 ;
}
static int F_77 ( struct V_56 * V_57 ,
struct V_135 * V_136 )
{
V_136 -> type = V_145 ;
V_136 -> V_138 = 2 ;
V_136 -> V_139 . integer . V_140 = 0 ;
V_136 -> V_139 . integer . V_141 = 1 ;
return 0 ;
}
static int F_78 ( struct V_56 * V_57 ,
struct V_142 * V_143 )
{
T_3 * V_61 = F_35 ( V_57 ) ;
int V_63 = V_57 -> V_64 ;
F_36 ( & V_61 -> V_71 ) ;
if ( V_61 -> V_72 == V_63 ) {
V_143 -> V_139 . integer . V_139 [ 0 ] = V_61 -> V_73 [ 0 ] ;
V_143 -> V_139 . integer . V_139 [ 1 ] = V_61 -> V_73 [ 1 ] ;
} else {
V_143 -> V_139 . integer . V_139 [ 0 ] = 0 ;
V_143 -> V_139 . integer . V_139 [ 1 ] = 0 ;
}
F_37 ( & V_61 -> V_71 ) ;
return 0 ;
}
static int F_79 ( struct V_56 * V_57 ,
struct V_142 * V_143 )
{
int V_58 , V_59 ;
V_58 = V_143 -> V_139 . integer . V_139 [ 0 ] & 1 ;
V_59 = V_143 -> V_139 . integer . V_139 [ 1 ] & 1 ;
return F_34 ( V_57 , V_58 , V_59 , false ) ;
}
static int F_80 ( T_3 * V_61 )
{
struct V_146 * V_88 = V_61 -> V_88 ;
struct V_56 * V_57 ;
unsigned int V_147 ;
int V_36 , V_63 ;
strcpy ( V_88 -> V_148 , L_17 ) ;
for ( V_147 = 0 ; V_147 < F_81 ( V_149 ) ; V_147 ++ ) {
V_57 = F_82 ( & V_149 [ V_147 ] ,
V_61 ) ;
V_36 = F_83 ( V_88 , V_57 ) ;
if ( V_36 < 0 )
return V_36 ;
}
for ( V_147 = 0 ; V_147 < F_81 ( V_150 ) ; V_147 ++ ) {
V_57 = F_82 ( & V_150 [ V_147 ] ,
V_61 ) ;
V_63 = V_150 [ V_147 ] . V_64 ;
V_61 -> V_90 [ V_63 ] = V_57 ;
V_36 = F_83 ( V_88 , V_57 ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_61 -> V_72 = V_92 ;
return 0 ;
}
static void F_84 ( struct V_146 * V_88 )
{
T_3 * V_61 = V_88 -> V_35 ;
if ( V_61 -> V_2 -> V_3 . V_22 == NULL )
return;
if ( V_61 -> V_19 >= 0 )
F_85 ( V_61 -> V_19 , & V_61 -> V_2 -> V_3 ) ;
V_61 -> V_2 -> V_3 . V_22 = NULL ;
}
static int F_86 ( struct V_1 * V_2 , int V_151 )
{
struct V_146 * V_88 ;
T_3 * V_61 ;
int V_36 ;
if ( V_151 >= V_152 )
return - V_121 ;
if ( ! V_153 [ V_151 ] )
return - V_121 ;
V_36 = F_87 ( & V_2 -> V_53 -> V_2 , V_154 [ V_151 ] , V_91 [ V_151 ] ,
V_155 , sizeof( T_3 ) , & V_88 ) ;
if ( V_36 < 0 )
return V_36 ;
strcpy ( V_88 -> V_156 , L_18 ) ;
V_88 -> V_124 = F_84 ;
V_61 = V_88 -> V_35 ;
F_67 ( & V_61 -> V_122 ) ;
F_67 ( & V_61 -> V_71 ) ;
V_61 -> V_2 = V_2 ;
V_61 -> V_88 = V_88 ;
V_61 -> V_53 = V_2 -> V_53 ;
V_61 -> V_157 = F_88 ( V_2 -> V_53 , 0 ) ;
V_36 = F_89 ( V_2 -> V_53 -> V_19 , F_14 ,
V_158 , V_2 -> V_134 ,
( void * ) & V_2 -> V_3 ) ;
if ( V_36 < 0 ) {
F_63 ( V_120 L_19 ,
V_2 -> V_134 , V_2 -> V_53 -> V_19 ) ;
goto V_159;
}
V_61 -> V_19 = V_2 -> V_53 -> V_19 ;
F_90 ( & V_2 -> V_3 . V_122 ) ;
if ( ( V_36 = F_80 ( V_61 ) ) < 0 )
goto V_159;
if ( ( V_36 = F_71 ( V_61 , 0 ) ) < 0 )
goto V_159;
strcpy ( V_88 -> V_160 , L_18 ) ;
sprintf ( V_88 -> V_161 , L_20 ,
V_61 -> V_2 -> V_134 , V_61 -> V_157 , V_61 -> V_19 ) ;
F_63 ( V_162 L_21 , V_2 -> V_134 , V_88 -> V_161 , V_154 [ V_151 ] ) ;
if ( ( V_36 = F_91 ( V_88 ) ) == 0 ) {
V_163 [ V_151 ] = V_88 ;
return 0 ;
}
V_159:
F_92 ( V_88 ) ;
return V_36 ;
}
static int F_93 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_22 = V_2 ;
F_86 ( V_2 , V_2 -> V_164 ) ;
return 1 ;
}
static int F_94 ( struct V_1 * V_2 )
{
F_92 ( V_163 [ V_2 -> V_164 ] ) ;
V_163 [ V_2 -> V_164 ] = NULL ;
return 1 ;
}
static int F_95 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_165 * V_166 ;
V_167 = F_93 ;
V_168 = F_94 ;
F_63 ( V_162 L_22 ) ;
F_96 (list,&saa7134_devlist) {
V_2 = F_97 ( V_166 , struct V_1 , V_169 ) ;
if ( V_2 -> V_53 -> V_75 == V_170 )
F_63 ( V_162 L_23 ,
V_2 -> V_134 , V_171 [ V_2 -> V_172 ] . V_134 ) ;
else
F_93 ( V_2 ) ;
}
if ( V_2 == NULL )
F_63 ( V_162 L_24 ) ;
return 0 ;
}
static void F_98 ( void )
{
int V_147 ;
for ( V_147 = 0 ; V_147 < V_152 ; V_147 ++ ) {
F_92 ( V_163 [ V_147 ] ) ;
}
V_167 = NULL ;
V_168 = NULL ;
F_63 ( V_162 L_25 ) ;
return;
}
