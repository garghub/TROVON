static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! V_4 -> V_9 )
return 0 ;
V_6 = V_4 -> V_9 -> V_6 ;
V_8 = V_2 -> V_8 ;
V_4 -> V_10 = V_8 -> V_11 ( V_8 , V_4 -> V_9 , V_6 -> V_12 ) ;
if ( ! V_4 -> V_10 )
return - V_13 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! V_4 -> V_10 )
return;
V_8 = V_2 -> V_8 ;
V_8 -> V_14 ( V_8 , V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
static unsigned long F_3 ( struct V_1 * V_2 , int V_15 )
{
return V_2 -> V_8 -> V_16 ( V_2 -> V_8 , V_15 ) ;
}
static unsigned int F_4 ( T_1 V_17 ,
struct V_18 * V_19 )
{
switch ( V_17 ) {
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
F_5 ( V_19 -> V_30 , L_1 ,
V_17 ) ;
return V_23 ;
}
}
static unsigned int
F_6 ( unsigned int V_31 , unsigned int V_32 )
{
unsigned int V_33 ;
int V_34 ;
V_33 = ( V_31 / V_32 ) << 24 ;
V_31 %= V_32 ;
V_31 /= 100 ;
V_32 /= 100 ;
for ( V_34 = 31 ; ( ( V_34 >= 0 ) && ! ( V_31 >> V_34 ) ) ; )
V_34 -- ;
if ( V_34 >= 0 ) {
V_31 <<= ( 31 - V_34 ) ;
V_31 /= V_32 ;
V_34 = 24 - ( 31 - V_34 ) ;
if ( V_34 >= 0 )
V_31 <<= V_34 ;
else
V_31 >>= - V_34 ;
V_33 |= V_31 ;
}
return V_33 ;
}
static int F_7 ( unsigned int V_33 )
{
if ( V_33 > 0x00428f5c && V_33 < 0x01b851ec ) {
return 1 ;
} else if ( V_33 == 0x01d66666 || V_33 == 0x01d66667 ) {
return 2 ;
} else if ( V_33 == 0x02000000 ) {
return 3 ;
} else if ( V_33 <= 0x08000000 ) {
return 0 ;
} else {
return - V_13 ;
}
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_35 = V_2 -> V_36 [ V_37 ] ;
struct V_38 * V_38 = V_2 -> V_36 [ V_39 ] ;
struct V_40 V_41 = { 0 } ;
struct V_42 V_43 = { 0 } ;
struct V_44 * V_44 ;
struct V_45 * V_45 ;
int V_46 ;
int V_47 = V_4 -> V_9 -> V_6 -> V_48 , V_49 = 0 ;
int V_50 = V_4 -> V_9 -> V_51 -> V_50 ;
unsigned int V_33 ;
F_9 ( V_2 , V_4 ) ;
V_41 . V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
V_41 . V_53 = V_2 -> V_53 ;
V_41 . V_54 = V_55 ;
V_46 = V_35 -> V_56 ( V_35 , & V_41 , (struct V_44 * * ) & V_4 -> V_44 ) ;
if ( V_46 )
goto V_57;
V_33 = F_6 ( V_4 -> V_9 -> V_6 -> V_58 ,
( V_2 -> V_59 * V_2 -> V_53 ) ) ;
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_61 ( V_44 , V_33 ) ;
V_44 -> V_60 -> V_62 ( V_44 , F_7 ( V_33 ) ) ;
V_44 -> V_60 -> V_63 ( V_44 , F_4 ( V_4 -> V_9 -> V_6 -> V_64 ,
V_2 -> V_19 ) ) ;
V_44 -> V_60 -> V_65 ( V_44 , ( V_44 -> V_60 -> V_66 ( V_44 ) != NULL ) ) ;
V_47 = ( V_47 < 2 ) ? 2 : V_47 ;
V_4 -> V_67 = F_10 ( sizeof( void * ) * V_47 , V_68 ) ;
if ( ! V_4 -> V_67 ) {
V_46 = - V_69 ;
goto V_57;
}
V_43 . V_53 = V_2 -> V_53 ;
for ( V_49 = 0 , V_4 -> V_47 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_46 = V_38 -> V_70 ( V_38 , & V_43 ,
(struct V_45 * * ) & V_4 -> V_67 [ V_49 ] ) ;
if ( V_46 )
goto V_57;
V_4 -> V_47 ++ ;
}
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 < 0 )
goto V_57;
V_44 = V_4 -> V_44 ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_45 = V_4 -> V_67 [ V_49 ] ;
F_11 ( & V_2 -> V_71 ) ;
V_45 -> V_60 -> V_72 ( V_45 , & V_44 -> V_73 ,
V_74 , V_2 -> V_51 [ V_49 + V_50 * 2 ] ) ;
F_12 ( & V_2 -> V_71 ) ;
V_44 = V_44 -> V_60 -> V_66 ( V_44 ) ;
if ( ! V_44 )
V_44 = V_4 -> V_44 ;
}
F_13 ( V_4 -> V_75 ) ;
return 0 ;
V_57:
F_9 ( V_2 , V_4 ) ;
return V_46 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_35 = V_2 -> V_36 [ V_37 ] ;
struct V_76 * V_76 = V_2 -> V_36 [ V_77 ] ;
struct V_38 * V_38 = V_2 -> V_36 [ V_39 ] ;
struct V_78 * V_78 = V_2 -> V_36 [ V_79 ] ;
struct V_80 * V_80 ;
int V_49 ;
if ( V_4 -> V_81 ) {
for ( V_49 = 0 ; V_49 < V_4 -> V_82 ; V_49 ++ ) {
V_80 = V_4 -> V_81 [ V_49 ] ;
V_80 -> V_60 -> V_14 ( V_80 ) ;
V_76 -> V_83 ( V_76 , V_80 ) ;
V_4 -> V_81 [ V_49 ] = NULL ;
}
F_14 ( V_4 -> V_81 ) ;
V_4 -> V_81 = NULL ;
}
if ( V_4 -> V_84 ) {
for ( V_49 = 0 ; V_49 < V_4 -> V_85 ; V_49 ++ ) {
V_35 -> V_86 ( V_35 , V_4 -> V_84 [ V_49 ] ) ;
V_4 -> V_84 [ V_49 ] = NULL ;
}
F_14 ( V_4 -> V_84 ) ;
V_4 -> V_84 = NULL ;
}
if ( V_4 -> V_67 ) {
for ( V_49 = 0 ; V_49 < V_4 -> V_47 ; V_49 ++ ) {
V_38 -> V_87 ( V_38 , V_4 -> V_67 [ V_49 ] ) ;
V_4 -> V_67 [ V_49 ] = NULL ;
}
F_14 ( V_4 -> V_67 ) ;
V_4 -> V_67 = NULL ;
}
if ( V_4 -> V_88 ) {
V_78 -> V_89 ( V_78 , V_4 -> V_88 ) ;
V_4 -> V_88 = NULL ;
}
if ( V_4 -> V_44 ) {
V_35 -> V_86 ( V_35 , V_4 -> V_44 ) ;
V_4 -> V_44 = NULL ;
}
if ( V_4 -> V_10 ) {
F_2 ( V_2 , V_4 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_90 ;
struct V_44 * V_44 = V_4 -> V_44 ;
if ( V_4 -> V_91 )
return 0 ;
V_4 -> V_91 = 1 ;
V_90 = V_44 -> V_52 * V_44 -> V_73 . V_53 ;
V_90 = 0x80 * ( V_90 < 8 ? V_90 : 8 ) ;
V_44 -> V_60 -> V_92 ( V_44 , V_4 -> V_10 -> V_93 ) ;
V_44 -> V_60 -> V_94 ( V_44 , V_4 -> V_10 -> V_93 + V_4 -> V_10 -> V_95 ) ;
V_44 -> V_60 -> V_96 ( V_44 , V_4 -> V_10 -> V_93 + V_90 ) ;
V_44 -> V_60 -> V_97 ( V_44 , V_90 ) ;
V_44 -> V_60 -> V_98 ( V_44 , 1 ) ;
V_44 -> V_60 -> V_99 ( V_44 , V_100 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
F_16 ( V_4 -> V_75 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 ;
int V_49 ;
F_18 ( V_4 -> V_75 ) ;
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_98 ( V_44 , 0 ) ;
V_44 -> V_60 -> V_99 ( V_44 , V_102 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
if ( V_4 -> V_84 ) {
for ( V_49 = 0 ; V_49 < V_4 -> V_85 ; V_49 ++ ) {
V_44 = V_4 -> V_84 [ V_49 ] ;
V_44 -> V_60 -> V_98 ( V_44 , 0 ) ;
V_44 -> V_60 -> V_99 ( V_44 , V_102 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
}
}
V_4 -> V_91 = 0 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 = V_4 -> V_44 ;
T_2 V_95 , V_90 ;
int V_103 ;
if ( ! V_44 )
return 0 ;
V_103 = V_44 -> V_60 -> V_104 ( V_44 ) ;
if ( V_103 < V_4 -> V_10 -> V_93 ) {
F_20 ( V_2 -> V_19 -> V_30 ,
L_2 ,
V_103 , V_4 -> V_10 -> V_93 , V_4 -> V_10 -> V_95 ) ;
V_103 = V_4 -> V_10 -> V_93 ;
}
V_95 = V_4 -> V_10 -> V_95 ;
V_90 = V_44 -> V_52 * V_44 -> V_73 . V_53 ;
V_90 = 128 * ( V_90 < 8 ? V_90 : 8 ) ;
return ( V_103 + V_95 - V_90 - V_4 -> V_10 -> V_93 ) % V_95 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_105 * V_106 , int * V_85 )
{
unsigned int V_33 ;
V_33 = F_6 ( ( V_2 -> V_59 * V_2 -> V_53 ) ,
V_4 -> V_9 -> V_6 -> V_58 ) ;
* V_85 = 0 ;
if ( 1 == V_2 -> V_53 ) {
* V_85 = V_4 -> V_9 -> V_6 -> V_48 ;
V_106 [ 0 ] . V_33 = V_33 ;
V_106 [ 0 ] . V_107 = V_106 [ 0 ] . V_108 = V_106 [ 0 ] . V_53 = 1 ;
V_106 [ 0 ] . V_109 = 1 ;
} else if ( 2 <= V_2 -> V_53 ) {
if ( 0x8000000 < V_33 ) {
V_106 [ 0 ] . V_33 = ( V_2 -> V_53 << 24 ) ;
V_106 [ 0 ] . V_53 = V_106 [ 0 ] . V_107 = 1 ;
V_106 [ 0 ] . V_108 = V_2 -> V_53 ;
V_106 [ 0 ] . V_109 = 0 ;
V_106 [ 1 ] . V_33 = F_6 ( V_2 -> V_59 ,
V_4 -> V_9 -> V_6 -> V_58 ) ;
V_106 [ 1 ] . V_53 = V_106 [ 1 ] . V_107 = V_106 [ 1 ] . V_108 = 1 ;
V_106 [ 1 ] . V_109 = 1 ;
* V_85 = V_4 -> V_9 -> V_6 -> V_48 * 2 ;
} else if ( 0x1000000 < V_33 ) {
V_106 [ 0 ] . V_33 = V_33 ;
V_106 [ 0 ] . V_53 = V_106 [ 0 ] . V_107
= V_106 [ 0 ] . V_108 = V_2 -> V_53 ;
V_106 [ 0 ] . V_109 = 1 ;
* V_85 = V_4 -> V_9 -> V_6 -> V_48 ;
}
}
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_35 = V_2 -> V_36 [ V_37 ] ;
struct V_76 * V_76 = V_2 -> V_36 [ V_77 ] ;
struct V_38 * V_38 = V_2 -> V_36 [ V_39 ] ;
struct V_78 * V_78 = V_2 -> V_36 [ V_79 ] ;
struct V_40 V_110 = { 0 } ;
struct V_44 * V_44 ;
struct V_111 V_112 = { 0 } ;
struct V_80 * V_80 ;
struct V_42 V_43 = { 0 } ;
struct V_113 V_114 = { 0 } ;
unsigned int V_33 ;
int V_52 , V_46 , V_49 ;
int V_82 , V_47 , V_85 , V_115 ;
struct V_105 V_116 [ 2 ] = { { 0 } } ;
F_9 ( V_2 , V_4 ) ;
V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
V_33 = F_6 ( ( V_2 -> V_59 * V_2 -> V_53 ) ,
V_4 -> V_9 -> V_6 -> V_58 ) ;
F_21 ( V_2 , V_4 , V_116 , & V_85 ) ;
V_115 = ( 1 == V_52 ) ? 1 : 0 ;
V_47 = V_115 * 2 + V_85 ;
V_82 = V_85 ;
if ( ( V_52 > 1 ) && ( 0x8000000 >= V_33 ) ) {
V_47 += V_52 * V_2 -> V_53 ;
V_82 += V_52 * V_2 -> V_53 ;
} else {
V_82 += V_52 ;
}
if ( V_85 ) {
V_4 -> V_84 = F_10 ( sizeof( void * ) * V_85 , V_68 ) ;
if ( ! V_4 -> V_84 )
return - V_69 ;
}
if ( V_47 ) {
V_4 -> V_67 = F_10 ( sizeof( void * ) * V_47 , V_68 ) ;
if ( ! V_4 -> V_67 ) {
V_46 = - V_69 ;
goto V_57;
}
}
V_4 -> V_81 = F_10 ( sizeof( void * ) * V_82 , V_68 ) ;
if ( ! V_4 -> V_81 ) {
V_46 = - V_69 ;
goto V_57;
}
V_110 . V_52 = 1 ;
V_110 . V_54 = V_117 ;
for ( V_49 = 0 , V_4 -> V_85 = 0 ; V_49 < V_85 ; V_49 ++ ) {
V_110 . V_53 = V_116 [ V_49 / V_52 ] . V_53 ;
V_46 = V_35 -> V_56 ( V_35 , & V_110 ,
(struct V_44 * * ) & V_4 -> V_84 [ V_49 ] ) ;
if ( V_46 )
goto V_57;
V_44 = V_4 -> V_84 [ V_49 ] ;
V_33 = V_116 [ V_49 / V_52 ] . V_33 ;
V_44 -> V_60 -> V_61 ( V_44 , V_33 ) ;
V_44 -> V_60 -> V_62 ( V_44 , F_7 ( V_33 ) ) ;
V_44 -> V_60 -> V_118 ( V_44 , V_116 [ V_49 / V_52 ] . V_109 ) ;
V_4 -> V_85 ++ ;
}
for ( V_49 = 0 , V_4 -> V_47 = 0 ; V_49 < V_47 ; V_49 ++ ) {
if ( V_49 < ( V_115 * 2 ) )
V_43 . V_53 = V_2 -> V_53 ;
else if ( V_49 < ( V_115 * 2 + V_85 ) )
V_43 . V_53 = V_116 [ ( V_49 - V_115 * 2 ) / V_52 ] . V_107 ;
else
V_43 . V_53 = 1 ;
V_46 = V_38 -> V_70 ( V_38 , & V_43 ,
(struct V_45 * * ) & V_4 -> V_67 [ V_49 ] ) ;
if ( V_46 )
goto V_57;
V_4 -> V_47 ++ ;
}
V_114 . V_53 = V_2 -> V_53 ;
V_46 = V_78 -> V_119 ( V_78 , & V_114 , (struct V_120 * * ) & V_4 -> V_88 ) ;
if ( V_46 )
goto V_57;
V_33 = F_6 ( ( V_2 -> V_59 * V_2 -> V_53 ) ,
V_4 -> V_9 -> V_6 -> V_58 ) ;
for ( V_49 = 0 , V_4 -> V_82 = 0 ; V_49 < V_82 ; V_49 ++ ) {
if ( V_49 < ( V_85 ) )
V_112 . V_53 = V_116 [ V_49 / V_52 ] . V_108 ;
else if ( 1 == V_52 )
V_112 . V_53 = ( V_33 <= 0x8000000 ) ? V_2 -> V_53 : 1 ;
else
V_112 . V_53 = 1 ;
V_46 = V_76 -> V_121 ( V_76 , & V_112 , & V_80 ) ;
if ( V_46 )
goto V_57;
V_4 -> V_81 [ V_49 ] = V_80 ;
V_4 -> V_82 ++ ;
}
V_110 . V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
V_110 . V_53 = 1 ;
V_110 . V_54 = V_122 ;
V_46 = V_35 -> V_56 ( V_35 , & V_110 , (struct V_44 * * ) & V_4 -> V_44 ) ;
if ( V_46 )
goto V_57;
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_61 ( V_44 , V_33 ) ;
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 < 0 )
goto V_57;
return 0 ;
V_57:
F_9 ( V_2 , V_4 ) ;
return V_46 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 ;
struct V_45 * V_45 ;
struct V_80 * V_80 ;
struct V_123 * V_124 = V_2 -> V_124 ;
struct V_120 * V_88 ;
struct V_73 * V_125 [ 8 ] = { NULL } ;
int V_46 , V_49 , V_126 , V_115 , V_52 ;
unsigned int V_33 ;
int V_127 = 0 , V_128 = 0 ;
F_9 ( V_2 , V_4 ) ;
V_46 = F_22 ( V_2 , V_4 ) ;
if ( V_46 )
return V_46 ;
V_124 -> V_129 ( V_124 , V_130 ,
& V_125 [ 0 ] , & V_125 [ 1 ] ) ;
V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
if ( 1 == V_52 ) {
V_88 = V_4 -> V_88 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_45 = V_4 -> V_67 [ V_49 ] ;
V_45 -> V_60 -> V_72 ( V_45 , V_125 [ V_49 ] ,
V_131 , V_88 ) ;
}
V_125 [ 0 ] = & V_88 -> V_73 ;
V_115 = 1 ;
V_127 = V_115 * 2 ;
}
for ( V_49 = 0 ; V_49 < V_4 -> V_85 ; V_49 ++ ) {
V_44 = V_4 -> V_84 [ V_49 ] ;
V_80 = V_4 -> V_81 [ V_128 + V_49 ] ;
V_45 = V_4 -> V_67 [ V_127 + V_49 ] ;
V_80 -> V_60 -> V_11 ( V_80 , V_44 , V_125 [ V_49 % V_52 ] ) ;
V_45 -> V_60 -> V_72 ( V_45 , & V_44 -> V_73 , V_74 , NULL ) ;
V_125 [ V_49 % V_52 ] = & V_45 -> V_73 ;
}
V_33 = F_6 ( ( V_2 -> V_59 * V_2 -> V_53 ) ,
V_4 -> V_9 -> V_6 -> V_58 ) ;
if ( ( V_52 > 1 ) && ( V_33 <= 0x8000000 ) ) {
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_125 [ V_49 ] -> V_60 -> V_132 ( V_125 [ V_49 ] ) ;
for ( V_126 = 0 ; V_126 < V_2 -> V_53 ; V_126 ++ ) {
V_45 = V_4 -> V_67 [ V_4 -> V_85 + V_126 * V_52 + V_49 ] ;
V_45 -> V_60 -> V_133 ( V_45 , V_125 [ V_49 ] ) ;
V_45 -> V_60 -> V_134 ( V_45 , V_74 ) ;
V_45 -> V_60 -> V_135 ( V_45 , NULL ) ;
V_45 -> V_60 -> V_136 ( V_45 ) ;
V_125 [ V_49 ] -> V_60 -> V_137 ( V_125 [ V_49 ] ) ;
V_80 = V_4 -> V_81 [ V_4 -> V_85 + V_126 * V_52 + V_49 ] ;
V_80 -> V_60 -> V_11 ( V_80 , V_4 -> V_44 ,
& V_45 -> V_73 ) ;
}
}
} else {
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_80 = V_4 -> V_81 [ V_4 -> V_85 + V_49 ] ;
V_80 -> V_60 -> V_11 ( V_80 , V_4 -> V_44 , V_125 [ V_49 ] ) ;
}
}
F_13 ( V_4 -> V_75 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 ;
struct V_35 * V_35 = V_2 -> V_36 [ V_37 ] ;
int V_49 , V_52 ;
if ( V_4 -> V_91 )
return 0 ;
V_4 -> V_91 = 1 ;
V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_85 ; V_49 ++ ) {
V_44 = V_4 -> V_84 [ V_49 ] ;
V_44 -> V_60 -> V_65 ( V_44 , ( ( V_49 % V_52 ) != ( V_52 - 1 ) ) ) ;
V_35 -> V_138 ( V_35 , V_44 ) ;
}
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_63 ( V_44 , F_4 ( V_4 -> V_9 -> V_6 -> V_64 ,
V_2 -> V_19 ) ) ;
V_44 -> V_60 -> V_92 ( V_44 , V_4 -> V_10 -> V_93 ) ;
V_44 -> V_60 -> V_94 ( V_44 , V_4 -> V_10 -> V_93 + V_4 -> V_10 -> V_95 ) ;
V_44 -> V_60 -> V_96 ( V_44 , V_4 -> V_10 -> V_93 ) ;
V_35 -> V_138 ( V_35 , V_44 ) ;
V_35 -> V_101 ( V_35 ) ;
for ( V_49 = 0 ; V_49 < V_4 -> V_85 ; V_49 ++ ) {
V_44 = V_4 -> V_84 [ V_49 ] ;
V_44 -> V_60 -> V_99 ( V_44 , V_139 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
V_35 -> V_140 ( V_35 , V_44 ) ;
}
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_98 ( V_44 , 1 ) ;
V_44 -> V_60 -> V_99 ( V_44 , V_139 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
V_35 -> V_140 ( V_35 , V_44 ) ;
V_35 -> V_101 ( V_35 ) ;
F_16 ( V_4 -> V_75 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 = V_4 -> V_44 ;
if ( ! V_44 )
return 0 ;
return V_44 -> V_60 -> V_104 ( V_44 ) - V_4 -> V_10 -> V_93 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_35 * V_35 = V_2 -> V_36 [ V_37 ] ;
struct V_38 * V_38 = V_2 -> V_36 [ V_39 ] ;
struct V_40 V_41 = { 0 } ;
struct V_42 V_43 = { 0 } ;
struct V_44 * V_44 ;
int V_46 ;
int V_47 = V_4 -> V_9 -> V_6 -> V_48 , V_49 ;
unsigned int V_33 , V_59 = V_2 -> V_141 ;
F_9 ( V_2 , V_4 ) ;
V_41 . V_52 = V_4 -> V_9 -> V_6 -> V_48 ;
V_41 . V_53 = 1 ;
while ( V_4 -> V_9 -> V_6 -> V_58 > ( V_59 * V_41 . V_53 ) )
V_41 . V_53 <<= 1 ;
V_41 . V_54 = V_55 ;
V_46 = V_35 -> V_56 ( V_35 , & V_41 , (struct V_44 * * ) & V_4 -> V_44 ) ;
if ( V_46 )
goto V_57;
V_33 = F_6 ( V_4 -> V_9 -> V_6 -> V_58 , ( V_59 * V_41 . V_53 ) ) ;
V_44 = V_4 -> V_44 ;
V_44 -> V_60 -> V_61 ( V_44 , V_33 ) ;
V_44 -> V_60 -> V_62 ( V_44 , F_7 ( V_33 ) ) ;
V_44 -> V_60 -> V_63 ( V_44 , F_4 ( V_4 -> V_9 -> V_6 -> V_64 ,
V_2 -> V_19 ) ) ;
V_44 -> V_60 -> V_65 ( V_44 , ( V_44 -> V_60 -> V_66 ( V_44 ) != NULL ) ) ;
V_44 -> V_60 -> V_142 ( V_44 , 1 ) ;
V_47 = ( V_47 < 2 ) ? 2 : V_47 ;
V_4 -> V_67 = F_10 ( sizeof( void * ) * V_47 , V_68 ) ;
if ( ! V_4 -> V_67 ) {
V_46 = - V_69 ;
goto V_57;
}
V_43 . V_53 = V_41 . V_53 ;
for ( V_49 = 0 , V_4 -> V_47 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_46 = V_38 -> V_70 ( V_38 , & V_43 ,
(struct V_45 * * ) & V_4 -> V_67 [ V_49 ] ) ;
if ( V_46 )
goto V_57;
V_4 -> V_47 ++ ;
}
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 < 0 )
goto V_57;
return 0 ;
V_57:
F_9 ( V_2 , V_4 ) ;
return V_46 ;
}
static int F_27 ( struct V_1 * V_2 , int V_58 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
int V_46 ;
V_46 = V_143 -> V_144 ( V_143 , V_58 ) ;
V_2 -> V_141 = V_46 ? 0 : V_58 ;
return V_46 ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_145 * V_145 = F_29 ( V_2 -> V_146 [ V_147 ] , struct V_145 , V_148 ) ;
unsigned int V_58 = V_4 -> V_9 -> V_6 -> V_58 ;
unsigned int V_149 ;
int V_46 = 0 ;
unsigned char V_150 ;
switch ( V_58 ) {
case 48000 :
V_150 = V_151 ;
break;
case 44100 :
V_150 = V_152 ;
break;
case 32000 :
V_150 = V_153 ;
break;
default:
return - V_13 ;
}
F_11 ( & V_2 -> V_71 ) ;
V_145 -> V_60 -> V_154 ( V_145 , & V_149 ) ;
if ( ( ( V_149 >> 24 ) & V_155 ) != V_150 ) {
V_149 &= ~ ( V_155 << 24 ) ;
V_149 |= ( V_150 << 24 ) ;
V_145 -> V_60 -> V_156 ( V_145 , V_149 ) ;
V_145 -> V_60 -> V_101 ( V_145 ) ;
}
if ( ( V_58 != V_2 -> V_141 ) && ( 32000 != V_58 ) )
V_46 = F_27 ( V_2 , V_58 ) ;
F_12 ( & V_2 -> V_71 ) ;
return V_46 ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_44 * V_44 ;
struct V_45 * V_45 ;
struct V_145 * V_145 ;
int V_46 ;
int V_49 ;
F_9 ( V_2 , V_4 ) ;
V_46 = F_28 ( V_2 , V_4 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_26 ( V_2 , V_4 ) ;
if ( V_46 )
return V_46 ;
V_44 = V_4 -> V_44 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_47 ; V_49 ++ ) {
V_45 = V_4 -> V_67 [ V_49 ] ;
V_45 -> V_60 -> V_72 ( V_45 , & V_44 -> V_73 , V_74 , NULL ) ;
V_44 = V_44 -> V_60 -> V_66 ( V_44 ) ;
if ( ! V_44 )
V_44 = V_4 -> V_44 ;
}
F_11 ( & V_2 -> V_71 ) ;
V_145 = F_29 ( V_2 -> V_146 [ V_147 ] , struct V_145 , V_148 ) ;
V_45 = V_4 -> V_67 [ 0 ] ;
V_145 -> V_60 -> V_157 ( V_145 , & V_45 -> V_73 ) ;
V_45 = V_4 -> V_67 [ 1 ] ;
V_145 -> V_60 -> V_158 ( V_145 , & V_45 -> V_73 ) ;
F_12 ( & V_2 -> V_71 ) ;
F_13 ( V_4 -> V_75 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
struct V_123 * V_124 = V_2 -> V_124 ;
struct V_44 * V_44 ;
if ( V_143 -> V_159 ( V_143 , V_160 ) )
return 0 ;
V_124 -> V_161 ( V_124 , V_162 , NULL ) ;
V_124 -> V_163 ( V_124 , V_162 , NULL ) ;
V_143 -> V_164 ( V_143 , V_160 ) ;
V_44 = V_2 -> V_165 [ 2 ] ;
V_124 -> V_161 ( V_124 , V_166 , & V_44 -> V_73 ) ;
V_44 = V_2 -> V_165 [ 3 ] ;
V_124 -> V_163 ( V_124 , V_166 , & V_44 -> V_73 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
struct V_123 * V_124 = V_2 -> V_124 ;
struct V_44 * V_44 ;
if ( V_143 -> V_159 ( V_143 , V_167 ) )
return 0 ;
V_124 -> V_161 ( V_124 , V_166 , NULL ) ;
V_124 -> V_163 ( V_124 , V_166 , NULL ) ;
V_143 -> V_164 ( V_143 , V_167 ) ;
V_44 = V_2 -> V_165 [ 2 ] ;
V_124 -> V_161 ( V_124 , V_162 , & V_44 -> V_73 ) ;
V_44 = V_2 -> V_165 [ 3 ] ;
V_124 -> V_163 ( V_124 , V_162 , & V_44 -> V_73 ) ;
return 0 ;
}
static struct V_168 F_33 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
return V_143 -> V_168 ( V_143 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
return V_143 -> V_169 ( V_143 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_103 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
return V_143 -> V_170 ( V_143 , V_103 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
return V_143 -> V_171 ( V_143 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_103 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
return V_143 -> V_172 ( V_143 , V_103 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
if ( V_143 -> V_159 ( V_143 , V_173 ) )
return 0 ;
V_143 -> V_164 ( V_143 , V_173 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned char V_174 , int type )
{
struct V_175 * V_175 = V_2 -> V_36 [ V_176 ] ;
if ( V_174 )
V_175 -> V_177 ( V_175 , V_2 -> V_146 [ type ] ) ;
else
V_175 -> V_178 ( V_175 , V_2 -> V_146 [ type ] ) ;
V_175 -> V_101 ( V_175 ) ;
return 0 ;
}
static int
F_40 ( struct V_1 * V_2 , unsigned int * V_149 , int type )
{
struct V_145 * V_145 = F_29 ( V_2 -> V_146 [ type ] , struct V_145 , V_148 ) ;
return V_145 -> V_60 -> V_154 ( V_145 , V_149 ) ;
}
static int
F_41 ( struct V_1 * V_2 , unsigned int V_149 , int type )
{
struct V_145 * V_145 = F_29 ( V_2 -> V_146 [ type ] , struct V_145 , V_148 ) ;
V_145 -> V_60 -> V_156 ( V_145 , V_149 ) ;
V_145 -> V_60 -> V_101 ( V_145 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_179 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_180 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_181 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_182 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_183 ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_184 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_147 ) ;
}
static int F_49 ( struct V_1 * V_2 , unsigned char V_174 )
{
return F_39 ( V_2 , V_174 , V_185 ) ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int * V_149 )
{
return F_40 ( V_2 , V_149 , V_147 ) ;
}
static int F_51 ( struct V_1 * V_2 , unsigned int V_149 )
{
return F_41 ( V_2 , V_149 , V_147 ) ;
}
static int F_52 ( struct V_1 * V_2 , unsigned char V_174 )
{
struct V_186 V_187 = { 0 } ;
struct V_145 * V_145 ;
int V_46 ;
struct V_123 * V_124 = V_2 -> V_124 ;
struct V_73 * V_188 [ 2 ] = { NULL } ;
unsigned int V_189 = 0 ;
F_11 ( & V_2 -> V_71 ) ;
V_145 = F_29 ( V_2 -> V_146 [ V_147 ] , struct V_145 , V_148 ) ;
V_187 . V_53 = V_174 ? 1 : V_2 -> V_53 ;
V_187 . V_190 = V_174 ? 1 : 0 ;
V_46 = V_145 -> V_60 -> V_191 ( V_145 , & V_187 ) ;
if ( V_174 ) {
V_189 = V_192 ;
} else {
V_124 -> V_129 ( V_124 , V_193 ,
& V_188 [ 0 ] , & V_188 [ 1 ] ) ;
V_145 -> V_60 -> V_157 ( V_145 , V_188 [ 0 ] ) ;
V_145 -> V_60 -> V_158 ( V_145 , V_188 [ 1 ] ) ;
if ( V_2 -> V_141 != V_2 -> V_59 )
V_46 = F_27 ( V_2 , V_2 -> V_59 ) ;
}
V_145 -> V_60 -> V_156 ( V_145 , V_189 ) ;
V_145 -> V_60 -> V_101 ( V_145 ) ;
F_12 ( & V_2 -> V_71 ) ;
return V_46 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_175 * V_175 = NULL ;
struct V_145 * V_145 = NULL ;
struct V_148 * V_148 = NULL ;
struct V_78 * V_78 = NULL ;
struct V_35 * V_35 = NULL ;
struct V_76 * V_76 = NULL ;
struct V_80 * V_80 = NULL ;
struct V_123 * V_124 = NULL ;
if ( V_2 -> V_124 ) {
V_124 = V_2 -> V_124 ;
V_124 -> V_161 ( V_124 , V_166 , NULL ) ;
V_124 -> V_163 ( V_124 , V_166 , NULL ) ;
V_124 -> V_161 ( V_124 , V_162 , NULL ) ;
V_124 -> V_163 ( V_124 , V_162 , NULL ) ;
V_124 -> V_161 ( V_124 , V_194 , NULL ) ;
V_124 -> V_163 ( V_124 , V_194 , NULL ) ;
}
if ( V_2 -> V_146 ) {
V_175 = (struct V_175 * ) V_2 -> V_36 [ V_176 ] ;
for ( V_49 = 0 ; V_49 < V_2 -> V_195 ; V_49 ++ ) {
V_148 = V_2 -> V_146 [ V_49 ] ;
if ( V_148 -> type < V_183 ) {
V_145 = F_29 ( V_148 , struct V_145 , V_148 ) ;
V_145 -> V_60 -> V_196 ( V_145 ) ;
V_145 -> V_60 -> V_197 ( V_145 ) ;
}
V_175 -> V_198 ( V_175 , V_148 ) ;
}
F_14 ( V_2 -> V_146 ) ;
V_2 -> V_146 = NULL ;
}
if ( V_2 -> V_51 ) {
V_78 = V_2 -> V_36 [ V_79 ] ;
for ( V_49 = 0 ; V_49 < V_2 -> V_199 ; V_49 ++ )
V_78 -> V_89 ( V_78 , V_2 -> V_51 [ V_49 ] ) ;
F_14 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
}
if ( V_2 -> V_165 ) {
V_35 = V_2 -> V_36 [ V_37 ] ;
for ( V_49 = 0 ; V_49 < V_2 -> V_200 ; V_49 ++ )
V_35 -> V_86 ( V_35 , V_2 -> V_165 [ V_49 ] ) ;
F_14 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
}
if ( V_2 -> V_81 ) {
V_76 = V_2 -> V_36 [ V_77 ] ;
for ( V_49 = 0 ; V_49 < V_2 -> V_82 ; V_49 ++ ) {
V_80 = V_2 -> V_81 [ V_49 ] ;
V_80 -> V_60 -> V_14 ( V_80 ) ;
V_76 -> V_83 ( V_76 , V_2 -> V_81 [ V_49 ] ) ;
}
F_14 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_49 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_75 ) {
F_55 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
F_53 ( V_2 ) ;
if ( V_2 -> V_124 )
F_56 ( V_2 -> V_124 ) ;
for ( V_49 = 0 ; V_49 < V_201 ; V_49 ++ ) {
if ( V_202 [ V_49 ] . V_203 && V_2 -> V_36 [ V_49 ] )
V_202 [ V_49 ] . V_203 ( V_2 -> V_36 [ V_49 ] ) ;
}
if ( V_2 -> V_143 )
F_57 ( V_2 -> V_143 ) ;
if ( V_2 -> V_8 ) {
F_58 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_204 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_205 ;
return F_54 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_206 )
{
const struct V_207 * V_208 ;
const struct V_207 * V_209 ;
T_3 V_210 , V_211 ;
switch ( V_2 -> V_212 ) {
case V_213 :
V_2 -> V_214 = L_3 ;
V_209 = V_215 ;
break;
case V_216 :
V_2 -> V_214 = L_4 ;
V_209 = V_217 ;
break;
default:
return - V_13 ;
}
if ( V_206 ) {
V_210 = V_206 >> 16 ;
V_211 = V_206 & 0xffff ;
} else {
V_210 = V_2 -> V_218 -> V_219 ;
V_211 = V_2 -> V_218 -> V_220 ;
}
V_208 = F_61 ( V_210 , V_211 , V_209 ) ;
if ( V_208 ) {
if ( V_208 -> V_221 < 0 ) {
F_5 ( V_2 -> V_19 -> V_30 ,
L_5 ,
V_210 , V_211 ) ;
return - V_13 ;
}
V_2 -> V_222 = V_208 -> V_221 ;
} else {
if ( V_2 -> V_212 == V_213 )
V_2 -> V_222 = V_223 ;
else
V_2 -> V_222 = V_224 ;
}
V_2 -> V_225 = V_226 [ V_2 -> V_222 ] ;
F_62 ( V_2 -> V_19 -> V_30 , L_6 ,
V_2 -> V_214 , V_2 -> V_225 ,
V_210 , V_211 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
enum V_227 V_49 ;
int V_46 ;
V_228 [ V_229 ] . V_230 = V_2 -> V_214 ;
for ( V_49 = 0 ; V_49 < V_231 ; V_49 ++ ) {
if ( ! V_228 [ V_49 ] . V_232 )
continue;
V_46 = V_228 [ V_49 ] . V_232 ( V_2 , V_49 ,
V_228 [ V_49 ] . V_230 ) ;
if ( V_46 ) {
F_5 ( V_2 -> V_19 -> V_30 ,
L_7 , V_49 ) ;
return V_46 ;
}
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_143 * V_143 ;
struct V_233 V_234 = { 0 } ;
int V_49 , V_46 ;
V_46 = F_65 ( V_2 -> V_218 , V_2 -> V_212 , V_2 -> V_222 , & V_143 ) ;
if ( V_46 ) {
F_5 ( V_2 -> V_19 -> V_30 , L_8 ) ;
return V_46 ;
}
V_143 -> V_19 = V_2 -> V_19 ;
V_2 -> V_143 = V_143 ;
V_234 . V_59 = V_2 -> V_59 ;
V_234 . V_53 = V_2 -> V_53 ;
V_234 . V_235 = F_3 ( V_2 , 0 ) ;
V_46 = V_143 -> V_236 ( V_143 , & V_234 ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_49 = 0 ; V_49 < V_201 ; V_49 ++ ) {
if ( ! V_202 [ V_49 ] . V_232 )
continue;
V_46 = V_202 [ V_49 ] . V_232 ( V_2 -> V_143 , & V_2 -> V_36 [ V_49 ] ) ;
if ( V_46 ) {
F_5 ( V_2 -> V_19 -> V_30 ,
L_9 , V_49 ) ;
return V_46 ;
}
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_237 V_238 = { 0 } ;
struct V_175 * V_175 ;
struct V_40 V_110 = { 0 } ;
struct V_35 * V_35 ;
struct V_111 V_112 = { 0 } ;
struct V_76 * V_76 ;
struct V_113 V_114 = { 0 } ;
struct V_78 * V_78 ;
int V_46 , V_49 , V_239 , V_240 ;
V_240 = ( ( V_2 -> V_222 == V_241 ) ? 8 : 7 ) ;
V_239 = ( ( V_2 -> V_222 == V_241 ) ? 6 : 4 ) ;
V_2 -> V_146 = F_10 ( sizeof( void * ) * V_240 , V_68 ) ;
if ( ! V_2 -> V_146 )
return - V_69 ;
V_2 -> V_165 = F_10 ( sizeof( void * ) * V_239 , V_68 ) ;
if ( ! V_2 -> V_165 )
return - V_69 ;
V_2 -> V_81 = F_10 ( sizeof( void * ) * V_239 , V_68 ) ;
if ( ! V_2 -> V_81 )
return - V_69 ;
V_2 -> V_51 = F_10 ( sizeof( void * ) * ( 2 * 4 ) , V_68 ) ;
if ( ! V_2 -> V_51 )
return - V_69 ;
V_175 = (struct V_175 * ) V_2 -> V_36 [ V_176 ] ;
V_238 . V_53 = V_2 -> V_53 ;
for ( V_49 = 0 , V_2 -> V_195 = 0 ; V_49 < V_240 ; V_49 ++ ) {
V_238 . type = ( V_2 -> V_222 != V_242 ) ? V_49 :
( ( V_49 == V_185 ) ? V_243 : V_49 ) ;
V_46 = V_175 -> V_244 ( V_175 , & V_238 ,
(struct V_148 * * ) & V_2 -> V_146 [ V_49 ] ) ;
if ( V_46 ) {
F_5 ( V_2 -> V_19 -> V_30 ,
L_10 ,
V_49 ) ;
return V_46 ;
}
V_2 -> V_195 ++ ;
}
V_35 = V_2 -> V_36 [ V_37 ] ;
V_110 . V_52 = 1 ;
V_110 . V_53 = V_2 -> V_53 ;
V_110 . V_54 = V_117 ;
for ( V_49 = 0 , V_2 -> V_200 = 0 ; V_49 < V_239 ; V_49 ++ ) {
V_46 = V_35 -> V_56 ( V_35 , & V_110 ,
(struct V_44 * * ) & V_2 -> V_165 [ V_49 ] ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_200 ++ ;
}
V_76 = V_2 -> V_36 [ V_77 ] ;
V_112 . V_53 = 8 ;
for ( V_49 = 0 , V_2 -> V_82 = 0 ; V_49 < V_239 ; V_49 ++ ) {
V_46 = V_76 -> V_121 ( V_76 , & V_112 ,
(struct V_80 * * ) & V_2 -> V_81 [ V_49 ] ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_82 ++ ;
}
V_78 = V_2 -> V_36 [ V_79 ] ;
V_114 . V_53 = V_2 -> V_53 ;
for ( V_49 = 0 , V_2 -> V_199 = 0 ; V_49 < ( 2 * 4 ) ; V_49 ++ ) {
V_46 = V_78 -> V_119 ( V_78 , & V_114 ,
(struct V_120 * * ) & V_2 -> V_51 [ V_49 ] ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_199 ++ ;
}
return 0 ;
}
static void
F_67 ( struct V_35 * V_35 , struct V_245 * V_245 ,
struct V_44 * * V_165 , struct V_80 * * V_81 )
{
struct V_73 * V_188 [ 2 ] = { NULL } ;
struct V_44 * V_44 ;
struct V_80 * V_80 ;
int V_49 = 0 ;
V_188 [ 0 ] = & V_245 -> V_148 . V_246 ;
V_188 [ 1 ] = & V_245 -> V_148 . V_247 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_44 = V_165 [ V_49 ] ;
V_80 = V_81 [ V_49 ] ;
V_80 -> V_60 -> V_11 ( V_80 , V_44 , V_188 [ V_49 ] ) ;
V_35 -> V_138 ( V_35 , V_44 ) ;
}
V_35 -> V_101 ( V_35 ) ;
V_44 = V_165 [ 0 ] ;
V_44 -> V_60 -> V_65 ( V_44 , 1 ) ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_44 = V_165 [ V_49 ] ;
V_44 -> V_60 -> V_99 ( V_44 , V_139 ) ;
V_44 -> V_60 -> V_101 ( V_44 ) ;
V_35 -> V_140 ( V_35 , V_44 ) ;
}
V_245 -> V_60 -> V_248 ( V_245 , & ( V_165 [ 0 ] -> V_73 ) ) ;
V_245 -> V_60 -> V_249 ( V_245 , & ( V_165 [ 1 ] -> V_73 ) ) ;
V_245 -> V_60 -> V_250 ( V_245 , 1 ) ;
V_245 -> V_60 -> V_251 ( V_245 , 1 ) ;
V_245 -> V_60 -> V_101 ( V_245 ) ;
V_35 -> V_101 ( V_35 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_245 * V_245 ;
struct V_145 * V_145 ;
struct V_44 * V_44 ;
struct V_120 * V_120 ;
struct V_123 * V_124 ;
struct V_73 * V_188 [ 2 ] = { NULL } ;
int V_49 , V_126 ;
V_124 = V_2 -> V_124 ;
for ( V_49 = V_252 , V_126 = V_179 ; V_49 <= V_193 ; V_49 ++ , V_126 ++ ) {
V_124 -> V_129 ( V_124 , V_49 , & V_188 [ 0 ] , & V_188 [ 1 ] ) ;
V_145 = F_29 ( V_2 -> V_146 [ V_126 ] , struct V_145 , V_148 ) ;
V_145 -> V_60 -> V_157 ( V_145 , V_188 [ 0 ] ) ;
V_145 -> V_60 -> V_158 ( V_145 , V_188 [ 1 ] ) ;
}
V_245 = F_29 ( V_2 -> V_146 [ V_183 ] , struct V_245 , V_148 ) ;
F_67 ( V_2 -> V_36 [ V_37 ] , V_245 ,
(struct V_44 * * ) & V_2 -> V_165 [ 2 ] ,
(struct V_80 * * ) & V_2 -> V_81 [ 2 ] ) ;
V_44 = V_2 -> V_165 [ 2 ] ;
V_124 -> V_161 ( V_124 , V_166 , & V_44 -> V_73 ) ;
V_44 = V_2 -> V_165 [ 3 ] ;
V_124 -> V_163 ( V_124 , V_166 , & V_44 -> V_73 ) ;
if ( V_2 -> V_222 == V_241 ) {
V_245 = F_29 ( V_2 -> V_146 [ V_184 ] , struct V_245 , V_148 ) ;
F_67 ( V_2 -> V_36 [ V_37 ] , V_245 ,
(struct V_44 * * ) & V_2 -> V_165 [ 4 ] ,
(struct V_80 * * ) & V_2 -> V_81 [ 4 ] ) ;
V_44 = V_2 -> V_165 [ 4 ] ;
V_124 -> V_161 ( V_124 , V_162 , & V_44 -> V_73 ) ;
V_44 = V_2 -> V_165 [ 5 ] ;
V_124 -> V_163 ( V_124 , V_162 , & V_44 -> V_73 ) ;
}
V_245 = F_29 ( V_2 -> V_146 [ V_185 ] , struct V_245 , V_148 ) ;
F_67 ( V_2 -> V_36 [ V_37 ] , V_245 ,
(struct V_44 * * ) & V_2 -> V_165 [ 0 ] ,
(struct V_80 * * ) & V_2 -> V_81 [ 0 ] ) ;
V_44 = V_2 -> V_165 [ 0 ] ;
V_124 -> V_161 ( V_124 , V_194 , & V_44 -> V_73 ) ;
V_44 = V_2 -> V_165 [ 1 ] ;
V_124 -> V_163 ( V_124 , V_194 , & V_44 -> V_73 ) ;
for ( V_49 = V_253 , V_126 = 0 ; V_49 <= V_254 ; V_49 ++ , V_126 += 2 ) {
V_120 = V_2 -> V_51 [ V_126 ] ;
V_124 -> V_161 ( V_124 , V_49 , & V_120 -> V_73 ) ;
V_120 = V_2 -> V_51 [ V_126 + 1 ] ;
V_124 -> V_163 ( V_124 , V_49 , & V_120 -> V_73 ) ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_143 * V_143 = V_2 -> V_143 ;
F_70 ( V_2 -> V_19 , V_255 ) ;
for ( V_49 = V_256 ; V_49 < V_257 ; V_49 ++ ) {
if ( ! V_2 -> V_258 [ V_49 ] )
continue;
F_71 ( V_2 -> V_258 [ V_49 ] ) ;
}
F_53 ( V_2 ) ;
V_143 -> V_259 ( V_143 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_143 * V_143 = V_2 -> V_143 ;
struct V_233 V_234 = { 0 } ;
V_234 . V_59 = V_2 -> V_59 ;
V_234 . V_53 = V_2 -> V_53 ;
V_234 . V_235 = F_3 ( V_2 , 0 ) ;
return V_143 -> V_260 ( V_143 , & V_234 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_123 * V_124 ;
int V_46 = 0 ;
V_46 = F_66 ( V_2 ) ;
if ( V_46 < 0 ) {
F_53 ( V_2 ) ;
return V_46 ;
}
F_68 ( V_2 ) ;
V_124 = V_2 -> V_124 ;
V_124 -> V_260 ( V_124 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
V_46 = F_72 ( V_2 ) ;
if ( V_46 < 0 ) {
F_5 ( V_2 -> V_19 -> V_30 ,
L_11 ) ;
F_75 ( V_2 -> V_19 ) ;
return V_46 ;
}
V_46 = F_73 ( V_2 ) ;
if ( V_46 < 0 )
return V_46 ;
F_70 ( V_2 -> V_19 , V_261 ) ;
return 0 ;
}
int F_76 ( struct V_18 * V_19 , struct V_262 * V_218 ,
unsigned int V_59 , unsigned int V_53 ,
int V_212 , unsigned int V_206 ,
struct V_1 * * V_263 )
{
struct V_1 * V_2 ;
static struct V_264 V_60 = {
. V_265 = F_59 ,
} ;
int V_46 ;
* V_263 = NULL ;
V_2 = F_10 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
* V_2 = V_266 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_218 = V_218 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_212 = V_212 ;
F_77 ( & V_2 -> V_71 ) ;
V_46 = F_60 ( V_2 , V_206 ) ;
if ( V_46 < 0 ) {
F_5 ( V_19 -> V_30 , L_12 ) ;
goto V_57;
}
V_46 = F_78 ( & V_2 -> V_8 , V_218 ) ;
if ( V_46 < 0 )
goto V_57;
V_46 = F_64 ( V_2 ) ;
if ( V_46 < 0 )
goto V_57;
V_46 = F_79 ( V_2 , (struct V_123 * * ) & V_2 -> V_124 ) ;
if ( V_46 ) {
F_5 ( V_19 -> V_30 , L_13 ) ;
goto V_57;
}
V_46 = F_66 ( V_2 ) ;
if ( V_46 < 0 )
goto V_57;
F_68 ( V_2 ) ;
V_2 -> V_75 = F_80 ( V_2 ) ;
if ( ! V_2 -> V_75 ) {
V_46 = - V_69 ;
goto V_57;
}
V_46 = F_81 ( V_19 , V_267 , V_2 , & V_60 ) ;
if ( V_46 < 0 )
goto V_57;
* V_263 = V_2 ;
return 0 ;
V_57:
F_54 ( V_2 ) ;
F_5 ( V_19 -> V_30 , L_14 ) ;
return V_46 ;
}
