static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_5 -> V_8 ) ;
F_4 ( V_2 -> V_5 -> V_8 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 , L_1 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 = V_2 -> V_5 -> V_11 ;
V_10 = F_7 ( V_11 ) ;
if ( V_10 )
F_8 ( & V_2 -> V_12 -> V_4 ,
L_2 ,
V_9 , V_10 ) ;
else
F_9 ( & V_2 -> V_12 -> V_4 ,
L_3 , V_11 ) ;
}
static int F_10 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 = NULL ;
int V_17 ;
int V_10 = 0 ;
F_11 ( & V_18 ) ;
V_17 = F_12 ( V_13 ) ;
V_16 = F_13 ( & V_19 , V_17 ) ;
if ( ! V_16 ) {
F_14 ( L_4 ,
V_9 , V_17 ) ;
V_10 = - V_20 ;
goto exit;
}
V_2 = F_15 ( V_16 ) ;
if ( ! V_2 ) {
F_8 ( & V_16 -> V_4 ,
L_5 ,
V_9 , V_17 ) ;
V_10 = - V_20 ;
goto exit;
}
F_11 ( & V_2 -> V_21 ) ;
if ( ! V_2 -> V_22 ) {
F_8 ( & V_16 -> V_4 ,
L_6 , V_9 ) ;
V_10 = - V_20 ;
} else if ( V_2 -> V_23 ) {
F_8 ( & V_16 -> V_4 ,
L_7 , V_9 ) ;
V_10 = - V_24 ;
} else {
V_2 -> V_23 = 1 ;
V_14 -> V_25 = V_2 ;
F_9 ( V_2 -> V_5 -> V_4 , L_8 ) ;
}
F_16 ( & V_2 -> V_21 ) ;
exit:
F_16 ( & V_18 ) ;
return V_10 ;
}
static int F_17 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_10 = 0 ;
V_2 = V_14 -> V_25 ;
if ( ! V_2 ) {
F_14 ( L_9 , V_9 ) ;
return - V_20 ;
}
F_11 ( & V_2 -> V_21 ) ;
if ( ! V_2 -> V_22 ) {
F_8 ( & V_2 -> V_12 -> V_4 ,
L_6 , V_9 ) ;
V_10 = - V_20 ;
} else if ( ! V_2 -> V_23 ) {
F_8 ( & V_2 -> V_12 -> V_4 ,
L_10 , V_9 ) ;
V_10 = - V_26 ;
} else {
V_2 -> V_23 = 0 ;
F_9 ( V_2 -> V_5 -> V_4 , L_11 ) ;
if ( ! V_2 -> V_27 && ! V_2 -> V_28 ) {
F_16 ( & V_2 -> V_21 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
}
F_16 ( & V_2 -> V_21 ) ;
return V_10 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
int V_30 = 0 ;
int V_10 = 0 ;
V_29 = F_19 ( V_2 -> V_12 ,
V_2 -> V_31 -> V_32 ) ;
V_30 = V_2 -> V_31 -> V_33 ;
F_20 ( V_2 -> V_6 , V_2 -> V_12 , V_29 ,
V_2 -> V_34 ,
sizeof( V_2 -> V_34 ) ,
V_35 , V_2 , V_30 ) ;
V_2 -> V_6 -> V_36 = 0 ;
F_21 ( & V_2 -> V_37 . V_38 ) ;
F_22 ( & ( V_2 -> V_37 . V_39 ) , 1 ) ;
V_10 = F_23 ( V_2 -> V_6 , V_40 ) ;
if ( V_10 ) {
F_22 ( & ( V_2 -> V_37 . V_39 ) , 0 ) ;
F_8 ( & V_2 -> V_12 -> V_4 ,
L_12 , V_9 , V_10 ) ;
} else {
F_16 ( & V_2 -> V_21 ) ;
V_10 = F_24 (
& V_2 -> V_37 . V_38 ) ;
if ( V_10 )
F_8 ( & V_2 -> V_12 -> V_4 ,
L_13 , V_9 ) ;
F_11 ( & V_2 -> V_21 ) ;
V_10 = V_2 -> V_37 . V_41 ;
if ( V_10 )
F_8 ( & V_2 -> V_12 -> V_4 ,
L_14 ,
V_9 , V_10 ) ;
}
return V_10 ;
}
static T_1 F_25 ( struct V_14 * V_14 , const char T_2 * V_42 ,
T_3 V_43 , T_4 * V_44 )
{
int V_45 ;
int V_46 ;
int V_47 ;
int V_10 = 0 ;
struct V_1 * V_2 ;
const unsigned char V_48 [] = {
0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF } ;
int * V_49 = NULL ;
V_2 = V_14 -> V_25 ;
if ( ! V_2 ) {
F_14 ( L_9 , V_9 ) ;
return - V_20 ;
}
F_11 ( & V_2 -> V_21 ) ;
if ( ! V_2 -> V_27 ) {
F_8 ( & V_2 -> V_12 -> V_4 ,
L_15 , V_9 ) ;
V_10 = - V_20 ;
goto exit;
}
if ( V_43 <= 0 || V_43 > V_50 - 3 ) {
F_8 ( & V_2 -> V_12 -> V_4 ,
L_16 , V_9 ) ;
V_10 = - V_51 ;
goto exit;
}
V_49 = F_26 ( V_42 , V_43 ) ;
if ( F_27 ( V_49 ) ) {
V_10 = F_28 ( V_49 ) ;
goto exit;
}
memcpy ( V_2 -> V_37 . V_49 , V_49 , V_43 ) ;
for ( V_45 = V_43 ; V_45 < V_50 - 3 ; ++ V_45 )
V_2 -> V_37 . V_49 [ V_45 ] = ' ' ;
for ( V_45 = V_50 - 3 ; V_45 < V_50 ; ++ V_45 )
V_2 -> V_37 . V_49 [ V_45 ] = 0xFF ;
V_46 = 0 ;
V_47 = 0 ;
do {
memcpy ( V_2 -> V_34 , V_2 -> V_37 . V_49 + V_46 , 7 ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_47 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 ) {
F_8 ( & V_2 -> V_12 -> V_4 ,
L_17 ,
V_9 , V_47 / 2 ) ;
goto exit;
} else {
V_47 += 2 ;
V_46 += 7 ;
}
} while ( V_46 < V_50 );
if ( V_2 -> V_52 ) {
memcpy ( V_2 -> V_34 , & V_48 , sizeof( V_48 ) ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_47 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 )
F_8 ( & V_2 -> V_12 -> V_4 ,
L_17 ,
V_9 , V_47 / 2 ) ;
}
exit:
F_16 ( & V_2 -> V_21 ) ;
F_4 ( V_49 ) ;
return ( ! V_10 ) ? V_43 : V_10 ;
}
static void V_35 ( struct V_53 * V_53 )
{
struct V_1 * V_2 ;
if ( ! V_53 )
return;
V_2 = (struct V_1 * ) V_53 -> V_2 ;
if ( ! V_2 )
return;
V_2 -> V_37 . V_41 = V_53 -> V_41 ;
F_22 ( & V_2 -> V_37 . V_39 , 0 ) ;
F_29 ( & V_2 -> V_37 . V_38 ) ;
return;
}
static int F_30 ( void * V_54 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
F_11 ( & V_18 ) ;
V_2 = (struct V_1 * ) V_54 ;
V_2 -> V_55 . V_56 = 0 ;
V_2 -> V_55 . V_57 = 1 ;
V_2 -> V_55 . V_58 = 0 ;
V_2 -> V_28 = 1 ;
F_9 ( V_2 -> V_5 -> V_4 , L_18 ) ;
F_16 ( & V_18 ) ;
return V_10 ;
}
static void F_31 ( void * V_54 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_54 ;
if ( ! V_2 ) {
F_14 ( L_9 , V_9 ) ;
return;
}
F_11 ( & V_2 -> V_21 ) ;
V_2 -> V_28 = 0 ;
F_9 ( V_2 -> V_5 -> V_4 , L_19 ) ;
if ( ! V_2 -> V_27 ) {
F_6 ( V_2 ) ;
if ( ! V_2 -> V_23 ) {
F_16 ( & V_2 -> V_21 ) ;
F_1 ( V_2 ) ;
return;
}
}
F_16 ( & V_2 -> V_21 ) ;
return;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned char V_42 [ 4 ] ;
int V_59 = V_2 -> V_55 . V_56 ;
int V_45 ;
F_5 ( V_2 -> V_5 -> V_4 , L_20 ) ;
V_59 *= V_60 ;
V_59 &= V_61 ;
if ( V_2 -> V_55 . V_58 )
V_59 |= V_62 ;
for ( V_45 = 0 ; V_45 < 4 ; ++ V_45 )
V_42 [ V_45 ] = V_59 >> ( V_45 * 8 ) ;
F_33 ( V_2 -> V_5 -> V_8 , V_42 ) ;
F_34 ( & V_2 -> V_5 -> V_8 -> V_63 ) ;
return;
}
static inline int F_35 ( const struct V_64 * V_65 , const struct V_64 * V_66 )
{
int V_67 = 0 ;
int V_68 = 0 ;
if ( V_66 -> V_69 > V_65 -> V_69 ) {
V_67 = 1000000 ;
V_68 -- ;
}
V_67 += V_65 -> V_69 - V_66 -> V_69 ;
V_68 += V_65 -> V_70 - V_66 -> V_70 ;
V_68 *= 1000 ;
V_67 /= 1000 ;
V_68 += V_67 ;
if ( V_68 < 0 )
V_68 = 1000 ;
return V_68 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_53 * V_53 , int V_71 )
{
int V_72 = V_53 -> V_36 ;
unsigned char * V_42 = V_53 -> V_73 ;
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_74 , V_75 ;
unsigned char V_76 ;
int V_45 ;
if ( ! V_2 -> V_28 )
return;
if ( V_72 != 8 ) {
F_37 ( V_4 , L_21
L_22 , V_9 , V_72 , V_71 ) ;
return;
}
if ( V_77 ) {
F_9 ( V_4 , L_23 ) ;
for ( V_45 = 0 ; V_45 < V_72 ; ++ V_45 )
F_38 ( L_24 , V_42 [ V_45 ] ) ;
F_38 ( L_25 ) ;
}
if ( V_42 [ 7 ] == 1 && V_2 -> V_55 . V_57 ) {
V_2 -> V_55 . V_58 = 0 ;
V_2 -> V_55 . V_56 = 4 ;
F_32 ( V_2 ) ;
V_2 -> V_55 . V_56 = 0 ;
}
for ( V_74 = 0 ; V_74 < 5 ; ++ V_74 ) {
V_76 = 0x80 ;
for ( V_75 = 0 ; V_75 < 8 ; ++ V_75 ) {
int V_78 = ! ( V_42 [ V_74 ] & V_76 ) ;
if ( V_78 != V_2 -> V_55 . V_58 ) {
if ( V_2 -> V_55 . V_56 ) {
F_32 ( V_2 ) ;
V_2 -> V_55 . V_56 = 0 ;
}
V_2 -> V_55 . V_58 = V_78 ;
}
++ V_2 -> V_55 . V_56 ;
V_76 >>= 1 ;
}
}
if ( V_42 [ 7 ] == 10 ) {
if ( V_2 -> V_55 . V_56 ) {
F_32 ( V_2 ) ;
V_2 -> V_55 . V_56 = 0 ;
}
V_2 -> V_55 . V_57 = V_2 -> V_55 . V_58 ;
}
}
static void F_39 ( struct V_53 * V_53 )
{
struct V_1 * V_2 ;
int V_79 = 0 ;
if ( ! V_53 )
return;
V_2 = (struct V_1 * ) V_53 -> V_2 ;
if ( ! V_2 )
return;
switch ( V_53 -> V_41 ) {
case - V_80 :
return;
case 0 :
F_36 ( V_2 , V_53 , V_79 ) ;
break;
default:
F_37 ( V_2 -> V_5 -> V_4 , L_26 ,
V_9 , V_53 -> V_41 ) ;
break;
}
F_23 ( V_2 -> V_7 , V_81 ) ;
return;
}
static int F_40 ( struct V_15 * V_16 ,
const struct V_82 * V_83 )
{
struct V_84 * V_12 = NULL ;
struct V_85 * V_86 = NULL ;
struct V_87 * V_88 = NULL ;
struct V_87 * V_31 = NULL ;
struct V_53 * V_7 = NULL ;
struct V_53 * V_6 = NULL ;
struct V_89 * V_5 = NULL ;
struct V_90 * V_8 = NULL ;
struct V_3 * V_4 = & V_16 -> V_4 ;
int V_91 ;
int V_92 = 0 ;
int V_93 ;
int V_10 = 0 ;
int V_94 = 0 ;
int V_95 = 0 ;
int V_96 = 0 ;
int V_52 = 0 ;
struct V_1 * V_2 = NULL ;
int V_45 ;
T_5 V_97 , V_98 ;
F_11 ( & V_18 ) ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 ) {
V_96 = 1 ;
goto V_99;
}
if ( F_42 ( V_16 , V_100 ) )
V_2 -> V_22 = 0 ;
else
V_2 -> V_22 = 1 ;
V_12 = F_43 ( F_44 ( V_16 ) ) ;
V_86 = V_16 -> V_101 ;
V_93 = V_86 -> V_102 . V_103 ;
V_91 = V_86 -> V_102 . V_104 ;
V_97 = F_45 ( V_12 -> V_105 . V_106 ) ;
V_98 = F_45 ( V_12 -> V_105 . V_107 ) ;
F_5 ( V_4 , L_27 ,
V_9 , V_97 , V_98 , V_91 ) ;
for ( V_45 = 0 ; V_45 < V_93 && ! ( V_95 && V_94 ) ; ++ V_45 ) {
struct V_87 * V_108 ;
int V_109 ;
int V_110 ;
V_108 = & V_86 -> V_111 [ V_45 ] . V_102 ;
V_109 = V_108 -> V_32 & V_112 ;
V_110 = V_108 -> V_113 & V_114 ;
if ( ! V_95 &&
V_109 == V_115 &&
V_110 == V_116 ) {
V_88 = V_108 ;
V_95 = 1 ;
F_5 ( V_4 , L_28 , V_9 ) ;
} else if ( ! V_94 && V_109 == V_117 &&
V_110 == V_116 ) {
V_31 = V_108 ;
V_94 = 1 ;
F_5 ( V_4 , L_29 , V_9 ) ;
}
}
if ( V_2 -> V_22 == 0 ) {
V_94 = 0 ;
F_5 ( V_4 , L_30 , V_9 ) ;
}
if ( ! V_95 ) {
F_8 ( V_4 , L_31 , V_9 ) ;
V_10 = - V_20 ;
V_96 = 2 ;
goto V_99;
}
if ( V_94 ) {
if ( F_42 ( V_16 , V_118 ) )
V_52 = 1 ;
F_5 ( V_4 , L_32 ,
V_9 , V_52 ) ;
}
V_5 = F_41 ( sizeof( struct V_89 ) , V_40 ) ;
if ( ! V_5 ) {
V_96 = 2 ;
goto V_99;
}
V_8 = F_46 ( sizeof( struct V_90 ) , V_40 ) ;
if ( ! V_8 ) {
V_96 = 3 ;
goto V_99;
}
if ( F_47 ( V_8 , V_119 , V_120 ) ) {
F_8 ( V_4 , L_33 , V_9 ) ;
V_96 = 4 ;
goto V_99;
}
V_7 = F_48 ( 0 , V_40 ) ;
if ( ! V_7 ) {
F_8 ( V_4 , L_34 , V_9 ) ;
V_96 = 5 ;
goto V_99;
}
V_6 = F_48 ( 0 , V_40 ) ;
if ( ! V_6 ) {
F_8 ( V_4 , L_35 ,
V_9 ) ;
V_96 = 6 ;
goto V_99;
}
F_49 ( & V_2 -> V_21 ) ;
V_2 -> V_52 = V_52 ;
strcpy ( V_5 -> V_121 , V_122 ) ;
V_5 -> V_11 = - 1 ;
V_5 -> V_123 = V_119 * 8 ;
V_5 -> V_124 = 0 ;
V_5 -> V_125 = V_126 ;
V_5 -> V_54 = V_2 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_127 = F_30 ;
V_5 -> V_128 = F_31 ;
V_5 -> V_4 = & V_16 -> V_4 ;
V_5 -> V_129 = V_130 ;
F_11 ( & V_2 -> V_21 ) ;
V_2 -> V_5 = V_5 ;
V_92 = F_50 ( V_5 ) ;
if ( V_92 < 0 ) {
F_8 ( V_4 , L_36 , V_9 ) ;
V_96 = 7 ;
goto V_131;
} else
F_9 ( V_4 , L_37
L_38 , V_92 ) ;
V_5 -> V_11 = V_92 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_27 = 1 ;
V_2 -> V_88 = V_88 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_6 = V_6 ;
if ( V_94 )
V_2 -> V_22 = 1 ;
F_20 ( V_2 -> V_7 , V_2 -> V_12 ,
F_51 ( V_2 -> V_12 ,
V_2 -> V_88 -> V_32 ) ,
V_2 -> V_132 , sizeof( V_2 -> V_132 ) ,
F_39 , V_2 ,
V_2 -> V_88 -> V_33 ) ;
V_10 = F_23 ( V_2 -> V_7 , V_40 ) ;
if ( V_10 ) {
F_8 ( V_4 , L_39 ,
V_9 , V_10 ) ;
V_96 = 8 ;
goto V_131;
}
F_52 ( V_16 , V_2 ) ;
if ( V_2 -> V_22 && V_91 == 0 ) {
F_5 ( V_4 , L_40 ,
V_9 ) ;
if ( F_53 ( V_16 , & V_133 ) ) {
F_9 ( V_4 , L_41
L_42 , V_9 ) ;
}
}
F_9 ( V_4 , L_43
L_44 , V_97 , V_98 , V_91 ,
V_12 -> V_134 -> V_135 , V_12 -> V_136 ) ;
V_131:
F_16 ( & V_2 -> V_21 ) ;
V_99:
switch ( V_96 ) {
case 8 :
F_7 ( V_5 -> V_11 ) ;
case 7 :
F_2 ( V_6 ) ;
case 6 :
F_2 ( V_7 ) ;
case 5 :
if ( V_8 )
F_3 ( V_8 ) ;
case 4 :
F_4 ( V_8 ) ;
case 3 :
F_4 ( V_5 ) ;
case 2 :
F_4 ( V_2 ) ;
V_2 = NULL ;
case 1 :
if ( V_10 != - V_20 )
V_10 = - V_137 ;
break;
case 0 :
V_10 = 0 ;
}
F_16 ( & V_18 ) ;
return V_10 ;
}
static void F_54 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_91 ;
F_11 ( & V_18 ) ;
V_2 = F_15 ( V_16 ) ;
V_91 = V_16 -> V_101 -> V_102 . V_104 ;
F_11 ( & V_2 -> V_21 ) ;
F_52 ( V_16 , NULL ) ;
if ( F_55 ( & V_2 -> V_37 . V_39 ) ) {
F_56 ( V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_37 . V_38 ) ;
}
V_2 -> V_27 = 0 ;
F_56 ( V_2 -> V_7 ) ;
if ( V_2 -> V_22 )
F_58 ( V_16 , & V_133 ) ;
if ( ! V_2 -> V_28 && ! V_2 -> V_27 ) {
F_6 ( V_2 ) ;
F_16 ( & V_2 -> V_21 ) ;
if ( ! V_2 -> V_23 )
F_1 ( V_2 ) ;
} else
F_16 ( & V_2 -> V_21 ) ;
F_16 ( & V_18 ) ;
F_9 ( & V_16 -> V_4 , L_45 ,
V_9 , V_91 ) ;
}
static int F_59 ( struct V_15 * V_71 , T_6 V_138 )
{
struct V_1 * V_2 = F_15 ( V_71 ) ;
F_56 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_15 * V_71 )
{
int V_139 = 0 ;
struct V_1 * V_2 = F_15 ( V_71 ) ;
F_20 ( V_2 -> V_7 , V_2 -> V_12 ,
F_51 ( V_2 -> V_12 ,
V_2 -> V_88 -> V_32 ) ,
V_2 -> V_132 , sizeof( V_2 -> V_132 ) ,
F_39 , V_2 ,
V_2 -> V_88 -> V_33 ) ;
V_139 = F_23 ( V_2 -> V_7 , V_81 ) ;
return V_139 ;
}
