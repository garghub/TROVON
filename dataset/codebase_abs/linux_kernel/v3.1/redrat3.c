static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_3 ) ;
F_2 ( L_2 ,
V_2 -> V_4 , V_2 -> V_5 ) ;
F_2 ( L_3 ,
V_2 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
F_2 ( L_4 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_2 ( L_5 ,
V_2 -> V_11 , V_2 -> V_12 ) ;
F_2 ( L_6 , V_2 -> V_13 ) ;
}
static void F_3 ( char * V_14 , T_1 V_15 )
{
int V_16 , V_17 ;
char * V_18 ;
F_2 ( L_7 , V_3 ) ;
V_16 = V_19 + V_20
+ ( V_21 * sizeof( T_1 ) ) ;
V_18 = V_14 + V_16 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_17 % 10 == 0 )
F_4 ( L_8 ) ;
F_4 ( L_9 , * V_18 ++ ) ;
}
F_4 ( L_10 ) ;
}
static void F_5 ( struct V_22 * V_23 )
{
int V_24 ;
F_6 ( V_23 -> V_25 , L_11 , V_3 ) ;
if ( ! V_23 -> V_26 ) {
F_7 ( V_23 -> V_25 , L_12
L_13 ) ;
return;
}
memset ( V_23 -> V_27 , 0 , V_23 -> V_28 -> V_29 ) ;
V_24 = F_8 ( V_23 -> V_30 , V_31 ) ;
if ( V_24 )
F_9 ( V_23 -> V_25 , L_14
L_15 , V_3 , V_24 ,
V_23 -> V_30 -> V_32 ) ;
}
static void F_10 ( struct V_22 * V_23 , int V_33 )
{
if ( ! V_23 -> V_34 && ( V_33 != 0x40 ) )
F_11 ( V_23 -> V_25 , L_16 , V_33 ) ;
switch ( V_33 ) {
case 0x00 :
F_4 ( L_17 ) ;
break;
case 0x20 :
F_4 ( L_18
L_19 ) ;
break;
case 0x21 :
F_4 ( L_20 ) ;
break;
case 0x22 :
F_4 ( L_21 ) ;
break;
case 0x23 :
F_4 ( L_22 ) ;
break;
case 0x28 :
F_4 ( L_23
L_24 ) ;
break;
case 0x29 :
F_4 ( L_25
L_26 ) ;
break;
case 0x30 :
F_4 ( L_27
L_28 ) ;
break;
case 0x40 :
if ( ! V_23 -> V_34 )
F_4 ( L_29 ) ;
break;
case 0x41 :
F_4 ( L_30
L_31 ) ;
break;
case 0x42 :
F_4 ( L_32 ) ;
break;
default:
F_4 ( L_33 ) ;
break;
}
}
static T_2 F_12 ( struct V_1 * V_35 )
{
T_2 V_36 = 0 ;
if ( V_35 -> V_7 != 0 )
V_36 = ( V_37 * V_35 -> V_8 ) /
( V_35 -> V_7 * V_38 ) ;
return V_36 ;
}
static T_2 F_13 ( T_2 V_4 )
{
T_2 V_39 = V_4 * 1000 ;
T_2 V_40 = ( V_41 ) / 1000 ;
T_2 V_42 = ( T_2 ) ( V_39 / V_40 ) ;
return V_42 ? V_42 : 1 ;
}
static T_2 F_14 ( T_2 V_43 )
{
T_2 V_42 ;
T_2 V_40 ;
V_43 &= V_44 ;
V_40 = ( V_41 / 1000 ) ;
V_42 = ( T_2 ) ( V_43 * V_40 ) / 1000 ;
return V_42 ? V_42 : 1 ;
}
static void F_15 ( unsigned long V_45 )
{
struct V_22 * V_23 = (struct V_22 * ) V_45 ;
F_9 ( V_23 -> V_25 , L_34 ) ;
F_16 ( V_23 -> V_46 ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
F_18 ( V_47 ) ;
struct V_1 V_2 ;
struct V_48 * V_25 ;
int V_17 , V_49 = 0 ;
unsigned long V_50 ;
T_2 V_36 , V_51 ;
T_1 * V_52 ;
T_3 * V_18 ;
T_2 V_53 ;
T_1 V_54 ;
char * V_55 ;
if ( ! V_23 ) {
F_19 ( L_35 , V_3 ) ;
return;
}
F_6 ( V_23 -> V_25 , L_36 , V_3 ) ;
V_25 = V_23 -> V_25 ;
V_55 = V_23 -> V_56 ;
V_2 . V_4 = V_23 -> V_57 ;
V_2 . V_5 = V_23 -> V_58 ;
if ( ! ( V_2 . V_4 >= V_20 ) )
F_7 ( V_25 , L_37 ) ;
V_50 = F_20 ( V_23 -> V_59 ) ;
F_21 ( & V_23 -> V_60 , V_61 + V_50 ) ;
memcpy ( & V_53 , V_55 + V_62 , sizeof( V_53 ) ) ;
V_2 . V_6 = F_22 ( V_53 ) ;
memcpy ( & V_54 , V_55 + V_63 , sizeof( V_54 ) ) ;
V_2 . V_7 = F_23 ( V_54 ) ;
memcpy ( & V_54 , V_55 + V_64 , sizeof( V_54 ) ) ;
V_2 . V_8 = F_23 ( V_54 ) ;
V_2 . V_10 = V_55 [ V_65 ] ;
V_2 . V_9 = V_55 [ V_66 ] ;
memcpy ( & V_54 , V_55 + V_67 , sizeof( V_54 ) ) ;
V_2 . V_12 = F_23 ( V_54 ) ;
memcpy ( & V_54 , V_55 + V_68 , sizeof( V_54 ) ) ;
V_2 . V_11 = F_23 ( V_54 ) ;
V_2 . V_13 = V_55 [ V_69 ] ;
if ( V_70 ) {
F_1 ( & V_2 ) ;
F_3 ( V_55 , V_2 . V_11 ) ;
}
V_36 = F_12 ( & V_2 ) ;
F_9 ( V_25 , L_38 , V_36 ) ;
V_52 = ( T_1 * ) ( V_55 + V_20 ) ;
V_18 = V_55 + V_20 +
( V_2 . V_10 * sizeof( T_1 ) ) ;
for ( V_17 = 0 ; V_17 < V_2 . V_11 ; V_17 ++ ) {
T_1 V_71 = V_52 [ V_18 [ V_17 ] ] ;
V_51 = F_13 ( ( T_2 ) F_23 ( V_71 ) ) ;
if ( V_17 % 2 )
V_47 . V_72 = false ;
else
V_47 . V_72 = true ;
V_47 . V_73 = F_24 ( V_51 ) ;
if ( V_17 == 0 )
V_49 = V_47 . V_73 ;
V_47 . V_73 &= V_44 ;
F_9 ( V_25 , L_39 ,
V_47 . V_72 ? L_40 : L_41 , V_47 . V_73 , V_17 ) ;
F_25 ( V_23 -> V_46 , & V_47 ) ;
}
if ( V_17 % 2 ) {
V_47 . V_72 = false ;
if ( V_49 < F_24 ( 1000 ) )
V_47 . V_73 = F_24 ( 2800 ) ;
else
V_47 . V_73 = V_49 ;
F_9 ( V_25 , L_42 ,
V_47 . V_73 ) ;
F_25 ( V_23 -> V_46 , & V_47 ) ;
}
F_9 ( V_25 , L_43 ) ;
F_26 ( V_23 -> V_46 ) ;
return;
}
static T_3 F_27 ( int V_74 , struct V_22 * V_23 )
{
struct V_75 * V_76 ;
T_3 * V_45 ;
int V_24 ;
V_45 = F_28 ( sizeof( T_3 ) , V_77 ) ;
if ( ! V_45 )
return - V_78 ;
V_76 = V_23 -> V_76 ;
V_24 = F_29 ( V_76 , F_30 ( V_76 , 0 ) , V_74 ,
V_79 | V_80 | V_81 ,
0x0000 , 0x0000 , V_45 , sizeof( T_3 ) , V_82 * 10 ) ;
if ( V_24 < 0 ) {
F_31 ( V_23 -> V_25 , L_44 ,
V_3 , V_24 , * V_45 ) ;
V_24 = - V_83 ;
} else
V_24 = ( T_3 ) V_45 [ 0 ] ;
F_32 ( V_45 ) ;
return V_24 ;
}
static int F_33 ( struct V_22 * V_23 )
{
struct V_48 * V_25 = V_23 -> V_25 ;
T_3 V_84 ;
F_6 ( V_25 , L_11 , V_3 ) ;
V_84 = F_27 ( V_85 , V_23 ) ;
if ( V_84 != 0 )
F_34 ( V_25 , L_45 ,
V_3 , V_84 ) ;
V_84 = F_27 ( V_86 , V_23 ) ;
if ( V_84 != 1 ) {
F_31 ( V_25 , L_46 ,
V_3 , V_84 ) ;
return - V_83 ;
}
V_23 -> V_26 = true ;
F_5 ( V_23 ) ;
return 0 ;
}
static void F_35 ( struct V_22 * V_23 )
{
struct V_48 * V_25 = V_23 -> V_25 ;
T_3 V_84 ;
F_6 ( V_25 , L_11 , V_3 ) ;
V_84 = F_27 ( V_87 , V_23 ) ;
if ( V_84 != 0 )
F_31 ( V_25 , L_47 , V_3 ) ;
V_84 = F_27 ( V_86 , V_23 ) ;
if ( V_84 != 0 )
F_7 ( V_25 , L_48 ,
V_3 , V_84 ) ;
V_23 -> V_26 = false ;
}
static inline void F_36 ( struct V_22 * V_23 ,
struct V_75 * V_76 )
{
F_6 ( V_23 -> V_25 , L_49 , V_3 ) ;
F_37 ( V_23 -> V_30 ) ;
F_37 ( V_23 -> V_88 ) ;
F_38 ( V_23 -> V_30 ) ;
F_38 ( V_23 -> V_88 ) ;
F_39 ( V_76 , V_23 -> V_28 -> V_29 ,
V_23 -> V_27 , V_23 -> V_89 ) ;
F_39 ( V_76 , V_23 -> V_90 -> V_29 ,
V_23 -> V_91 , V_23 -> V_92 ) ;
F_32 ( V_23 ) ;
}
static T_2 F_40 ( struct V_22 * V_23 )
{
T_2 * V_93 ;
T_2 V_94 = F_41 ( 150 ) ;
int V_15 , V_84 , V_95 ;
V_15 = sizeof( * V_93 ) ;
V_93 = F_28 ( V_15 , V_77 ) ;
if ( ! V_93 ) {
F_7 ( V_23 -> V_25 , L_50 ) ;
return V_94 ;
}
V_95 = F_30 ( V_23 -> V_76 , 0 ) ;
V_84 = F_29 ( V_23 -> V_76 , V_95 , V_96 ,
V_79 | V_80 | V_81 ,
V_97 , 0 , V_93 , V_15 , V_82 * 5 ) ;
if ( V_84 != V_15 ) {
F_7 ( V_23 -> V_25 , L_51 ) ;
return V_94 ;
}
V_94 = F_13 ( F_22 ( * V_93 ) ) ;
F_9 ( V_23 -> V_25 , L_52 , V_94 / 1000 ) ;
return V_94 ;
}
static void F_42 ( struct V_22 * V_23 )
{
struct V_75 * V_76 = V_23 -> V_76 ;
struct V_48 * V_25 = V_23 -> V_25 ;
int V_46 , V_98 , V_99 ;
T_3 * V_71 ;
int V_15 = sizeof( T_3 ) ;
F_6 ( V_25 , L_11 , V_3 ) ;
V_98 = F_30 ( V_76 , 0 ) ;
V_99 = F_43 ( V_76 , 0 ) ;
V_71 = F_28 ( V_15 , V_77 ) ;
if ( ! V_71 ) {
F_31 ( V_25 , L_53 ) ;
return;
}
* V_71 = 0x01 ;
V_46 = F_29 ( V_76 , V_98 , V_100 ,
V_79 | V_80 | V_81 ,
V_101 , 0 , V_71 , V_15 , V_82 * 25 ) ;
F_9 ( V_25 , L_54 , V_46 ) ;
* V_71 = 5 ;
V_46 = F_29 ( V_76 , V_99 , V_102 ,
V_79 | V_80 | V_103 ,
V_104 , 0 , V_71 , V_15 , V_82 * 25 ) ;
F_9 ( V_25 , L_55 , * V_71 , V_46 ) ;
* V_71 = V_21 ;
V_46 = F_29 ( V_76 , V_99 , V_102 ,
V_79 | V_80 | V_103 ,
V_105 , 0 , V_71 , V_15 , V_82 * 25 ) ;
F_9 ( V_25 , L_56 , * V_71 , V_46 ) ;
F_32 ( V_71 ) ;
}
static void F_44 ( struct V_22 * V_23 )
{
int V_46 = 0 ;
char * V_14 ;
F_6 ( V_23 -> V_25 , L_11 , V_3 ) ;
V_14 = F_28 ( sizeof( char ) * ( V_106 + 1 ) , V_77 ) ;
if ( ! V_14 ) {
F_31 ( V_23 -> V_25 , L_53 ) ;
return;
}
V_46 = F_29 ( V_23 -> V_76 , F_30 ( V_23 -> V_76 , 0 ) ,
V_107 ,
V_79 | V_80 | V_81 ,
0 , 0 , V_14 , V_106 , V_82 * 5 ) ;
if ( V_46 >= 0 )
F_11 ( V_23 -> V_25 , L_57 , V_14 ) ;
else
F_31 ( V_23 -> V_25 , L_58 ) ;
F_32 ( V_14 ) ;
F_6 ( V_23 -> V_25 , L_59 , V_3 ) ;
}
static void F_45 ( struct V_22 * V_23 , int V_15 )
{
T_1 V_108 ;
T_1 V_109 ;
F_6 ( V_23 -> V_25 , L_11 , V_3 ) ;
memcpy ( & ( V_23 -> V_57 ) , ( unsigned char * ) V_23 -> V_27 ,
sizeof( V_23 -> V_57 ) ) ;
memcpy ( & ( V_23 -> V_58 ) , ( ( unsigned char * ) V_23 -> V_27 +
sizeof( V_23 -> V_57 ) ) ,
sizeof( V_23 -> V_58 ) ) ;
V_23 -> V_57 = F_23 ( V_23 -> V_57 ) ;
V_23 -> V_58 = F_23 ( V_23 -> V_58 ) ;
switch ( V_23 -> V_58 ) {
case V_110 :
memcpy ( & V_108 , ( ( unsigned char * ) V_23 -> V_27
+ ( sizeof( V_23 -> V_57 ) + sizeof( V_23 -> V_58 ) ) ) ,
sizeof( V_108 ) ) ;
V_108 = F_23 ( V_108 ) ;
F_10 ( V_23 , V_108 ) ;
break;
case V_111 :
V_109 = sizeof( V_23 -> V_57 ) + sizeof( V_23 -> V_58 ) ;
V_23 -> V_112 = V_15 ;
V_23 -> V_112 -= V_109 ;
V_23 -> V_113 = & ( V_23 -> V_56 [ 0 ] ) ;
memcpy ( V_23 -> V_113 , ( ( unsigned char * ) V_23 -> V_27 + V_109 ) ,
V_23 -> V_112 ) ;
V_23 -> V_113 += V_23 -> V_112 ;
F_9 ( V_23 -> V_25 , L_60 ,
V_23 -> V_112 , V_23 -> V_57 ) ;
break;
default:
F_9 ( V_23 -> V_25 , L_61
L_62 , V_23 -> V_58 , V_15 , V_23 -> V_57 ) ;
break;
}
}
static void F_46 ( struct V_22 * V_23 , int V_15 )
{
F_6 ( V_23 -> V_25 , L_11 , V_3 ) ;
memcpy ( V_23 -> V_113 , ( unsigned char * ) V_23 -> V_27 , V_15 ) ;
V_23 -> V_113 += V_15 ;
V_23 -> V_112 += V_15 ;
F_9 ( V_23 -> V_25 , L_60 ,
V_23 -> V_112 , V_23 -> V_57 ) ;
}
static int F_47 ( struct V_22 * V_23 , int V_15 )
{
struct V_48 * V_25 = V_23 -> V_25 ;
int V_84 = 0 ;
F_6 ( V_25 , L_11 , V_3 ) ;
if ( V_23 -> V_57 > V_114 ) {
F_31 ( V_23 -> V_25 , L_63 ) ;
V_84 = - V_115 ;
goto V_116;
}
if ( ( V_23 -> V_112 == 0 ) &&
( V_15 >= ( sizeof( V_23 -> V_58 ) + sizeof( V_23 -> V_57 ) ) ) ) {
F_45 ( V_23 , V_15 ) ;
} else if ( V_23 -> V_112 != 0 ) {
F_46 ( V_23 , V_15 ) ;
} else if ( V_23 -> V_112 == 0 ) {
F_31 ( V_25 , L_64 ) ;
V_84 = - V_117 ;
goto V_116;
}
if ( V_23 -> V_112 > V_23 -> V_57 ) {
F_31 ( V_25 , L_65 ,
V_23 -> V_112 , V_23 -> V_57 ) ;
V_84 = - V_115 ;
goto V_116;
} else if ( V_23 -> V_112 < V_23 -> V_57 )
return 0 ;
if ( V_23 -> V_58 == V_111 )
F_17 ( V_23 ) ;
else
F_9 ( V_25 , L_66
L_67 , V_23 -> V_58 ) ;
V_116:
V_23 -> V_112 = 0 ;
V_23 -> V_57 = 0 ;
V_23 -> V_58 = 0 ;
return V_84 ;
}
static void F_48 ( struct V_118 * V_118 , struct V_119 * V_120 )
{
struct V_22 * V_23 ;
if ( ! V_118 )
return;
V_23 = V_118 -> V_121 ;
if ( ! V_23 ) {
F_19 ( L_68 , V_3 ) ;
F_49 ( V_118 ) ;
return;
}
F_6 ( V_23 -> V_25 , L_11 , V_3 ) ;
if ( ! V_23 -> V_26 ) {
F_9 ( V_23 -> V_25 , L_69
L_70 ) ;
return;
}
switch ( V_118 -> V_122 ) {
case 0 :
F_47 ( V_23 , V_118 -> V_123 ) ;
break;
case - V_124 :
case - V_125 :
case - V_126 :
F_49 ( V_118 ) ;
return;
case - V_127 :
default:
F_7 ( V_23 -> V_25 , L_71 , V_118 -> V_122 ) ;
V_23 -> V_112 = 0 ;
V_23 -> V_57 = 0 ;
V_23 -> V_58 = 0 ;
break;
}
if ( ! V_23 -> V_34 )
F_5 ( V_23 ) ;
else
F_9 ( V_23 -> V_25 , L_72 ) ;
}
static void F_50 ( struct V_118 * V_118 , struct V_119 * V_120 )
{
struct V_22 * V_23 ;
int V_15 ;
if ( ! V_118 )
return;
V_23 = V_118 -> V_121 ;
if ( V_23 ) {
V_15 = V_118 -> V_123 ;
F_6 ( V_23 -> V_25 , L_73 ,
V_3 , V_118 -> V_122 , V_15 ) ;
}
}
static T_1 F_51 ( unsigned int V_36 )
{
int V_128 = 6000000 ;
return ( T_1 ) ( 65536 - ( V_128 / V_36 ) ) ;
}
static int F_52 ( struct V_129 * V_25 , T_2 V_130 )
{
struct V_22 * V_23 = V_25 -> V_131 ;
V_23 -> V_130 = V_130 ;
return V_130 ;
}
static int F_53 ( struct V_129 * V_132 , int * V_133 , T_2 V_134 )
{
struct V_22 * V_23 = V_132 -> V_131 ;
struct V_48 * V_25 = V_23 -> V_25 ;
struct V_1 V_2 ;
int V_17 , V_135 , V_136 , V_84 , V_137 , V_16 ;
int V_138 , V_139 , V_95 ;
char * V_14 = NULL , * V_140 = NULL ;
int * V_141 = NULL ;
T_2 V_142 ;
T_1 V_143 ;
T_3 * V_113 ;
T_3 V_144 = 0 ;
T_1 * V_145 ;
int V_146 ;
F_6 ( V_25 , L_11 , V_3 ) ;
if ( V_23 -> V_34 ) {
F_7 ( V_25 , L_74 , V_3 ) ;
return - V_147 ;
}
V_136 = V_134 / sizeof( int ) ;
if ( V_136 > ( V_21 * 2 ) )
return - V_115 ;
V_23 -> V_34 = true ;
F_35 ( V_23 ) ;
if ( V_23 -> V_26 ) {
F_31 ( V_25 , L_75 , V_3 ) ;
V_84 = - V_83 ;
goto V_116;
}
V_141 = F_28 ( sizeof( int ) * V_21 , V_77 ) ;
if ( ! V_141 ) {
V_84 = - V_78 ;
goto V_116;
}
for ( V_17 = 0 ; V_17 < V_136 ; V_17 ++ ) {
for ( V_138 = 0 ; V_138 < V_144 ; V_138 ++ ) {
V_139 = F_14 ( V_133 [ V_17 ] ) ;
if ( V_141 [ V_138 ] == V_139 )
break;
}
if ( V_138 == V_144 ) {
V_139 = F_14 ( V_133 [ V_17 ] ) ;
F_9 ( V_25 , L_76 ,
V_17 , V_133 [ V_17 ] , V_144 , V_139 ) ;
if ( V_144 < 255 ) {
V_141 [ V_144 ] = V_139 ;
V_144 ++ ;
} else {
F_31 ( V_25 , L_77 ) ;
V_84 = - V_115 ;
goto V_116;
}
}
}
V_140 = F_28 ( ( V_136 + V_148 ) , V_77 ) ;
if ( ! V_140 ) {
V_84 = - V_78 ;
goto V_116;
}
V_140 [ V_136 ] = V_149 ;
V_140 [ V_136 + 1 ] = V_149 ;
for ( V_17 = 0 ; V_17 < V_136 ; V_17 ++ ) {
for ( V_135 = 0 ; V_135 < V_144 ; V_135 ++ ) {
if ( V_141 [ V_135 ] == F_14 ( V_133 [ V_17 ] ) )
V_140 [ V_17 ] = V_135 ;
}
}
V_16 = V_19 ;
V_146 = V_20 + ( sizeof( T_1 ) * V_21 )
+ V_136 + V_148 + V_16 ;
V_14 = F_28 ( V_146 , V_77 ) ;
if ( ! V_14 ) {
V_84 = - V_78 ;
goto V_116;
}
V_2 . V_4 = V_146 - V_16 ;
V_2 . V_5 = V_150 ;
V_2 . V_6 = F_13 ( 100 ) ;
V_2 . V_7 = F_51 ( V_23 -> V_130 ) ;
V_2 . V_8 = 0 ;
V_2 . V_10 = V_21 ;
V_2 . V_9 = V_144 ;
V_2 . V_12 = V_151 ;
V_2 . V_11 = V_136 + V_148 ;
V_2 . V_13 = 0 ;
V_143 = F_54 ( V_2 . V_4 ) ;
memcpy ( V_14 , & V_143 , 2 ) ;
V_143 = F_54 ( V_2 . V_5 ) ;
memcpy ( V_14 + 2 , & V_143 , 2 ) ;
V_142 = F_55 ( V_2 . V_6 ) ;
memcpy ( V_14 + V_16 , & V_142 , sizeof( V_142 ) ) ;
V_143 = F_54 ( V_2 . V_7 ) ;
memcpy ( V_14 + V_16 + V_63 , & V_143 , 2 ) ;
V_14 [ V_16 + V_66 ] = V_2 . V_9 ;
V_143 = F_54 ( V_2 . V_11 ) ;
memcpy ( V_14 + V_16 + V_68 , & V_143 , 2 ) ;
V_14 [ V_16 + V_69 ] = V_2 . V_13 ;
V_145 = ( T_1 * ) ( V_14 + V_16 + V_20 ) ;
for ( V_17 = 0 ; V_17 < V_144 ; ++ V_17 )
V_145 [ V_17 ] = F_54 ( V_141 [ V_17 ] ) ;
V_113 = ( T_3 * ) ( V_14 + V_16 + V_20 +
( sizeof( T_1 ) * V_21 ) ) ;
memcpy ( V_113 , V_140 , ( V_136 + V_148 ) ) ;
if ( V_70 ) {
F_1 ( & V_2 ) ;
F_3 ( V_14 , V_2 . V_11 ) ;
}
V_95 = F_56 ( V_23 -> V_76 , V_23 -> V_90 -> V_152 ) ;
V_143 = F_57 ( V_23 -> V_76 , V_95 , V_14 ,
V_146 , & V_137 , 10 * V_82 ) ;
F_9 ( V_25 , L_78 , V_137 , V_143 ) ;
V_95 = F_30 ( V_23 -> V_76 , 0 ) ;
V_84 = F_29 ( V_23 -> V_76 , V_95 , V_153 ,
V_79 | V_80 | V_81 ,
0 , 0 , V_14 , 2 , V_82 * 10 ) ;
if ( V_84 < 0 )
F_31 ( V_25 , L_79 , V_84 ) ;
else
V_84 = V_134 ;
V_116:
F_32 ( V_141 ) ;
F_32 ( V_14 ) ;
F_32 ( V_140 ) ;
V_23 -> V_34 = false ;
F_33 ( V_23 ) ;
return V_84 ;
}
static struct V_129 * F_58 ( struct V_22 * V_23 )
{
struct V_48 * V_25 = V_23 -> V_25 ;
struct V_129 * V_46 ;
int V_84 = - V_154 ;
T_1 V_155 = F_59 ( V_23 -> V_76 -> V_156 . V_157 ) ;
V_46 = F_60 () ;
if ( ! V_46 ) {
F_31 ( V_25 , L_80 ) ;
goto V_116;
}
snprintf ( V_23 -> V_158 , sizeof( V_23 -> V_158 ) , L_81
L_82 ,
V_155 == V_159 ? L_83 : L_84 ,
F_59 ( V_23 -> V_76 -> V_156 . V_160 ) , V_155 ) ;
F_61 ( V_23 -> V_76 , V_23 -> V_161 , sizeof( V_23 -> V_161 ) ) ;
V_46 -> V_162 = V_23 -> V_158 ;
V_46 -> V_163 = V_23 -> V_161 ;
F_62 ( V_23 -> V_76 , & V_46 -> V_164 ) ;
V_46 -> V_25 . V_165 = V_25 ;
V_46 -> V_131 = V_23 ;
V_46 -> V_166 = V_167 ;
V_46 -> V_168 = V_169 ;
V_46 -> V_94 = F_24 ( 2750 ) ;
V_46 -> V_170 = F_53 ;
V_46 -> V_171 = F_52 ;
V_46 -> V_172 = V_173 ;
V_46 -> V_174 = V_175 ;
V_84 = F_63 ( V_46 ) ;
if ( V_84 < 0 ) {
F_31 ( V_25 , L_85 ) ;
goto V_116;
}
return V_46 ;
V_116:
F_64 ( V_46 ) ;
return NULL ;
}
static int T_4 F_65 ( struct V_176 * V_177 ,
const struct V_178 * V_179 )
{
struct V_75 * V_76 = F_66 ( V_177 ) ;
struct V_48 * V_25 = & V_177 -> V_25 ;
struct V_180 * V_181 ;
struct V_22 * V_23 ;
struct V_182 * V_183 ;
struct V_182 * V_28 = NULL ;
struct V_182 * V_90 = NULL ;
T_3 V_184 , V_185 ;
int V_95 , V_17 ;
int V_186 = - V_78 ;
F_6 ( V_25 , L_86 , V_3 ) ;
V_181 = V_177 -> V_187 ;
for ( V_17 = 0 ; V_17 < V_181 -> V_188 . V_189 ; ++ V_17 ) {
V_183 = & V_181 -> V_190 [ V_17 ] . V_188 ;
V_184 = V_183 -> V_152 ;
V_185 = V_183 -> V_191 ;
if ( ( V_28 == NULL ) &&
( ( V_184 & V_192 ) == V_81 ) &&
( ( V_185 & V_193 ) ==
V_194 ) ) {
F_9 ( V_25 , L_87 ,
V_183 -> V_152 ) ;
if ( V_183 -> V_152 == V_195 )
V_28 = V_183 ;
}
if ( ( V_90 == NULL ) &&
( ( V_184 & V_192 ) == V_103 ) &&
( ( V_185 & V_193 ) ==
V_194 ) ) {
F_9 ( V_25 , L_88 ,
V_183 -> V_152 ) ;
V_90 = V_183 ;
}
}
if ( ! V_28 || ! V_90 ) {
F_31 ( V_25 , L_89 ) ;
V_186 = - V_154 ;
goto V_196;
}
V_23 = F_28 ( sizeof( * V_23 ) , V_77 ) ;
if ( V_23 == NULL ) {
F_31 ( V_25 , L_53 ) ;
goto V_196;
}
V_23 -> V_25 = & V_177 -> V_25 ;
V_23 -> V_30 = F_67 ( 0 , V_77 ) ;
if ( ! V_23 -> V_30 ) {
F_31 ( V_25 , L_90 ) ;
goto error;
}
V_23 -> V_28 = V_28 ;
V_23 -> V_27 = F_68 ( V_76 , V_28 -> V_29 ,
V_31 , & V_23 -> V_89 ) ;
if ( ! V_23 -> V_27 ) {
F_31 ( V_25 , L_91 ) ;
goto error;
}
V_95 = F_69 ( V_76 , V_28 -> V_152 ) ;
F_70 ( V_23 -> V_30 , V_76 , V_95 ,
V_23 -> V_27 , V_28 -> V_29 ,
( V_197 ) F_48 , V_23 ) ;
V_23 -> V_88 = F_67 ( 0 , V_77 ) ;
if ( ! V_23 -> V_88 ) {
F_31 ( V_25 , L_92 ) ;
goto error;
}
V_23 -> V_90 = V_90 ;
V_23 -> V_91 = F_68 ( V_76 , V_90 -> V_29 ,
V_31 , & V_23 -> V_92 ) ;
if ( ! V_23 -> V_91 ) {
F_31 ( V_25 , L_93 ) ;
goto error;
}
V_95 = F_56 ( V_76 , V_90 -> V_152 ) ;
F_70 ( V_23 -> V_88 , V_76 , V_95 ,
V_23 -> V_91 , V_90 -> V_29 ,
( V_197 ) F_50 , V_23 ) ;
F_71 ( & V_23 -> V_198 ) ;
V_23 -> V_76 = V_76 ;
F_42 ( V_23 ) ;
F_44 ( V_23 ) ;
V_186 = F_33 ( V_23 ) ;
if ( V_186 < 0 )
goto error;
V_23 -> V_59 = F_40 ( V_23 ) ;
V_23 -> V_130 = 38000 ;
V_23 -> V_46 = F_58 ( V_23 ) ;
if ( ! V_23 -> V_46 )
goto error;
F_72 ( & V_23 -> V_60 , F_15 , ( unsigned long ) V_23 ) ;
F_73 ( V_177 , V_23 ) ;
F_6 ( V_25 , L_59 , V_3 ) ;
return 0 ;
error:
F_36 ( V_23 , V_23 -> V_76 ) ;
V_196:
F_31 ( V_25 , L_94 , V_3 , V_186 ) ;
return V_186 ;
}
static void T_5 F_74 ( struct V_176 * V_177 )
{
struct V_75 * V_76 = F_66 ( V_177 ) ;
struct V_22 * V_23 = F_75 ( V_177 ) ;
F_6 ( & V_177 -> V_25 , L_11 , V_3 ) ;
if ( ! V_23 )
return;
F_35 ( V_23 ) ;
F_73 ( V_177 , NULL ) ;
F_76 ( V_23 -> V_46 ) ;
F_77 ( & V_23 -> V_60 ) ;
F_36 ( V_23 , V_76 ) ;
F_6 ( & V_177 -> V_25 , L_95 ) ;
}
static int F_78 ( struct V_176 * V_177 , T_6 V_199 )
{
struct V_22 * V_23 = F_75 ( V_177 ) ;
F_6 ( V_23 -> V_25 , L_96 ) ;
F_37 ( V_23 -> V_30 ) ;
return 0 ;
}
static int F_79 ( struct V_176 * V_177 )
{
struct V_22 * V_23 = F_75 ( V_177 ) ;
F_6 ( V_23 -> V_25 , L_97 ) ;
if ( F_8 ( V_23 -> V_30 , V_31 ) )
return - V_83 ;
return 0 ;
}
static int T_7 F_80 ( void )
{
int V_84 ;
V_84 = F_81 ( & V_200 ) ;
if ( V_84 < 0 )
F_19 ( V_173
L_98 , V_84 ) ;
return V_84 ;
}
static void T_8 F_82 ( void )
{
F_83 ( & V_200 ) ;
}
