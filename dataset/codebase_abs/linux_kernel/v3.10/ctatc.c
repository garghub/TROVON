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
static unsigned int F_4 ( T_1 V_17 )
{
switch ( V_17 ) {
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
default:
F_5 ( V_28 L_1 ,
V_17 ) ;
return V_21 ;
}
}
static unsigned int
F_6 ( unsigned int V_29 , unsigned int V_30 )
{
unsigned int V_31 ;
int V_32 ;
V_31 = ( V_29 / V_30 ) << 24 ;
V_29 %= V_30 ;
V_29 /= 100 ;
V_30 /= 100 ;
for ( V_32 = 31 ; ( ( V_32 >= 0 ) && ! ( V_29 >> V_32 ) ) ; )
V_32 -- ;
if ( V_32 >= 0 ) {
V_29 <<= ( 31 - V_32 ) ;
V_29 /= V_30 ;
V_32 = 24 - ( 31 - V_32 ) ;
if ( V_32 >= 0 )
V_29 <<= V_32 ;
else
V_29 >>= - V_32 ;
V_31 |= V_29 ;
}
return V_31 ;
}
static int F_7 ( unsigned int V_31 )
{
if ( V_31 > 0x00428f5c && V_31 < 0x01b851ec ) {
return 1 ;
} else if ( V_31 == 0x01d66666 || V_31 == 0x01d66667 ) {
return 2 ;
} else if ( V_31 == 0x02000000 ) {
return 3 ;
} else if ( V_31 <= 0x08000000 ) {
return 0 ;
} else {
return - V_13 ;
}
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_33 * V_33 = V_2 -> V_34 [ V_35 ] ;
struct V_36 * V_36 = V_2 -> V_34 [ V_37 ] ;
struct V_38 V_39 = { 0 } ;
struct V_40 V_41 = { 0 } ;
struct V_42 * V_42 ;
struct V_43 * V_43 ;
int V_44 ;
int V_45 = V_4 -> V_9 -> V_6 -> V_46 , V_47 = 0 ;
int V_48 = V_4 -> V_9 -> V_49 -> V_48 ;
unsigned int V_31 ;
F_9 ( V_2 , V_4 ) ;
V_39 . V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
V_39 . V_51 = V_2 -> V_51 ;
V_39 . V_52 = V_53 ;
V_44 = V_33 -> V_54 ( V_33 , & V_39 , (struct V_42 * * ) & V_4 -> V_42 ) ;
if ( V_44 )
goto V_55;
V_31 = F_6 ( V_4 -> V_9 -> V_6 -> V_56 ,
( V_2 -> V_57 * V_2 -> V_51 ) ) ;
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_59 ( V_42 , V_31 ) ;
V_42 -> V_58 -> V_60 ( V_42 , F_7 ( V_31 ) ) ;
V_42 -> V_58 -> V_61 ( V_42 , F_4 ( V_4 -> V_9 -> V_6 -> V_62 ) ) ;
V_42 -> V_58 -> V_63 ( V_42 , ( V_42 -> V_58 -> V_64 ( V_42 ) != NULL ) ) ;
V_45 = ( V_45 < 2 ) ? 2 : V_45 ;
V_4 -> V_65 = F_10 ( sizeof( void * ) * V_45 , V_66 ) ;
if ( ! V_4 -> V_65 ) {
V_44 = - V_67 ;
goto V_55;
}
V_41 . V_51 = V_2 -> V_51 ;
for ( V_47 = 0 , V_4 -> V_45 = 0 ; V_47 < V_45 ; V_47 ++ ) {
V_44 = V_36 -> V_68 ( V_36 , & V_41 ,
(struct V_43 * * ) & V_4 -> V_65 [ V_47 ] ) ;
if ( V_44 )
goto V_55;
V_4 -> V_45 ++ ;
}
V_44 = F_1 ( V_2 , V_4 ) ;
if ( V_44 < 0 )
goto V_55;
V_42 = V_4 -> V_42 ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
V_43 = V_4 -> V_65 [ V_47 ] ;
F_11 ( & V_2 -> V_69 ) ;
V_43 -> V_58 -> V_70 ( V_43 , & V_42 -> V_71 ,
V_72 , V_2 -> V_49 [ V_47 + V_48 * 2 ] ) ;
F_12 ( & V_2 -> V_69 ) ;
V_42 = V_42 -> V_58 -> V_64 ( V_42 ) ;
if ( ! V_42 )
V_42 = V_4 -> V_42 ;
}
F_13 ( V_4 -> V_73 ) ;
return 0 ;
V_55:
F_9 ( V_2 , V_4 ) ;
return V_44 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_33 * V_33 = V_2 -> V_34 [ V_35 ] ;
struct V_74 * V_74 = V_2 -> V_34 [ V_75 ] ;
struct V_36 * V_36 = V_2 -> V_34 [ V_37 ] ;
struct V_76 * V_76 = V_2 -> V_34 [ V_77 ] ;
struct V_78 * V_78 ;
int V_47 ;
if ( V_4 -> V_79 ) {
for ( V_47 = 0 ; V_47 < V_4 -> V_80 ; V_47 ++ ) {
V_78 = V_4 -> V_79 [ V_47 ] ;
V_78 -> V_58 -> V_14 ( V_78 ) ;
V_74 -> V_81 ( V_74 , V_78 ) ;
V_4 -> V_79 [ V_47 ] = NULL ;
}
F_14 ( V_4 -> V_79 ) ;
V_4 -> V_79 = NULL ;
}
if ( V_4 -> V_82 ) {
for ( V_47 = 0 ; V_47 < V_4 -> V_83 ; V_47 ++ ) {
V_33 -> V_84 ( V_33 , V_4 -> V_82 [ V_47 ] ) ;
V_4 -> V_82 [ V_47 ] = NULL ;
}
F_14 ( V_4 -> V_82 ) ;
V_4 -> V_82 = NULL ;
}
if ( V_4 -> V_65 ) {
for ( V_47 = 0 ; V_47 < V_4 -> V_45 ; V_47 ++ ) {
V_36 -> V_85 ( V_36 , V_4 -> V_65 [ V_47 ] ) ;
V_4 -> V_65 [ V_47 ] = NULL ;
}
F_14 ( V_4 -> V_65 ) ;
V_4 -> V_65 = NULL ;
}
if ( V_4 -> V_86 ) {
V_76 -> V_87 ( V_76 , V_4 -> V_86 ) ;
V_4 -> V_86 = NULL ;
}
if ( V_4 -> V_42 ) {
V_33 -> V_84 ( V_33 , V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
if ( V_4 -> V_10 ) {
F_2 ( V_2 , V_4 ) ;
V_4 -> V_10 = NULL ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_88 ;
struct V_42 * V_42 = V_4 -> V_42 ;
if ( V_4 -> V_89 )
return 0 ;
V_4 -> V_89 = 1 ;
V_88 = V_42 -> V_50 * V_42 -> V_71 . V_51 ;
V_88 = 0x80 * ( V_88 < 8 ? V_88 : 8 ) ;
V_42 -> V_58 -> V_90 ( V_42 , V_4 -> V_10 -> V_91 ) ;
V_42 -> V_58 -> V_92 ( V_42 , V_4 -> V_10 -> V_91 + V_4 -> V_10 -> V_93 ) ;
V_42 -> V_58 -> V_94 ( V_42 , V_4 -> V_10 -> V_91 + V_88 ) ;
V_42 -> V_58 -> V_95 ( V_42 , V_88 ) ;
V_42 -> V_58 -> V_96 ( V_42 , 1 ) ;
V_42 -> V_58 -> V_97 ( V_42 , V_98 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
F_16 ( V_4 -> V_73 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 ;
int V_47 ;
F_18 ( V_4 -> V_73 ) ;
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_96 ( V_42 , 0 ) ;
V_42 -> V_58 -> V_97 ( V_42 , V_100 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
if ( V_4 -> V_82 ) {
for ( V_47 = 0 ; V_47 < V_4 -> V_83 ; V_47 ++ ) {
V_42 = V_4 -> V_82 [ V_47 ] ;
V_42 -> V_58 -> V_96 ( V_42 , 0 ) ;
V_42 -> V_58 -> V_97 ( V_42 , V_100 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
}
}
V_4 -> V_89 = 0 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 = V_4 -> V_42 ;
T_2 V_93 , V_88 ;
int V_101 ;
if ( ! V_42 )
return 0 ;
V_101 = V_42 -> V_58 -> V_102 ( V_42 ) ;
V_93 = V_4 -> V_10 -> V_93 ;
V_88 = V_42 -> V_50 * V_42 -> V_71 . V_51 ;
V_88 = 128 * ( V_88 < 8 ? V_88 : 8 ) ;
return ( V_101 + V_93 - V_88 - V_4 -> V_10 -> V_91 ) % V_93 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_103 * V_104 , int * V_83 )
{
unsigned int V_31 ;
V_31 = F_6 ( ( V_2 -> V_57 * V_2 -> V_51 ) ,
V_4 -> V_9 -> V_6 -> V_56 ) ;
* V_83 = 0 ;
if ( 1 == V_2 -> V_51 ) {
* V_83 = V_4 -> V_9 -> V_6 -> V_46 ;
V_104 [ 0 ] . V_31 = V_31 ;
V_104 [ 0 ] . V_105 = V_104 [ 0 ] . V_106 = V_104 [ 0 ] . V_51 = 1 ;
V_104 [ 0 ] . V_107 = 1 ;
} else if ( 2 <= V_2 -> V_51 ) {
if ( 0x8000000 < V_31 ) {
V_104 [ 0 ] . V_31 = ( V_2 -> V_51 << 24 ) ;
V_104 [ 0 ] . V_51 = V_104 [ 0 ] . V_105 = 1 ;
V_104 [ 0 ] . V_106 = V_2 -> V_51 ;
V_104 [ 0 ] . V_107 = 0 ;
V_104 [ 1 ] . V_31 = F_6 ( V_2 -> V_57 ,
V_4 -> V_9 -> V_6 -> V_56 ) ;
V_104 [ 1 ] . V_51 = V_104 [ 1 ] . V_105 = V_104 [ 1 ] . V_106 = 1 ;
V_104 [ 1 ] . V_107 = 1 ;
* V_83 = V_4 -> V_9 -> V_6 -> V_46 * 2 ;
} else if ( 0x1000000 < V_31 ) {
V_104 [ 0 ] . V_31 = V_31 ;
V_104 [ 0 ] . V_51 = V_104 [ 0 ] . V_105
= V_104 [ 0 ] . V_106 = V_2 -> V_51 ;
V_104 [ 0 ] . V_107 = 1 ;
* V_83 = V_4 -> V_9 -> V_6 -> V_46 ;
}
}
}
static int
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_33 * V_33 = V_2 -> V_34 [ V_35 ] ;
struct V_74 * V_74 = V_2 -> V_34 [ V_75 ] ;
struct V_36 * V_36 = V_2 -> V_34 [ V_37 ] ;
struct V_76 * V_76 = V_2 -> V_34 [ V_77 ] ;
struct V_38 V_108 = { 0 } ;
struct V_42 * V_42 ;
struct V_109 V_110 = { 0 } ;
struct V_78 * V_78 ;
struct V_40 V_41 = { 0 } ;
struct V_111 V_112 = { 0 } ;
unsigned int V_31 ;
int V_50 , V_44 , V_47 ;
int V_80 , V_45 , V_83 , V_113 ;
struct V_103 V_114 [ 2 ] = { { 0 } } ;
F_9 ( V_2 , V_4 ) ;
V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
V_31 = F_6 ( ( V_2 -> V_57 * V_2 -> V_51 ) ,
V_4 -> V_9 -> V_6 -> V_56 ) ;
F_20 ( V_2 , V_4 , V_114 , & V_83 ) ;
V_113 = ( 1 == V_50 ) ? 1 : 0 ;
V_45 = V_113 * 2 + V_83 ;
V_80 = V_83 ;
if ( ( V_50 > 1 ) && ( 0x8000000 >= V_31 ) ) {
V_45 += V_50 * V_2 -> V_51 ;
V_80 += V_50 * V_2 -> V_51 ;
} else {
V_80 += V_50 ;
}
if ( V_83 ) {
V_4 -> V_82 = F_10 ( sizeof( void * ) * V_83 , V_66 ) ;
if ( ! V_4 -> V_82 )
return - V_67 ;
}
if ( V_45 ) {
V_4 -> V_65 = F_10 ( sizeof( void * ) * V_45 , V_66 ) ;
if ( ! V_4 -> V_65 ) {
V_44 = - V_67 ;
goto V_55;
}
}
V_4 -> V_79 = F_10 ( sizeof( void * ) * V_80 , V_66 ) ;
if ( ! V_4 -> V_79 ) {
V_44 = - V_67 ;
goto V_55;
}
V_108 . V_50 = 1 ;
V_108 . V_52 = V_115 ;
for ( V_47 = 0 , V_4 -> V_83 = 0 ; V_47 < V_83 ; V_47 ++ ) {
V_108 . V_51 = V_114 [ V_47 / V_50 ] . V_51 ;
V_44 = V_33 -> V_54 ( V_33 , & V_108 ,
(struct V_42 * * ) & V_4 -> V_82 [ V_47 ] ) ;
if ( V_44 )
goto V_55;
V_42 = V_4 -> V_82 [ V_47 ] ;
V_31 = V_114 [ V_47 / V_50 ] . V_31 ;
V_42 -> V_58 -> V_59 ( V_42 , V_31 ) ;
V_42 -> V_58 -> V_60 ( V_42 , F_7 ( V_31 ) ) ;
V_42 -> V_58 -> V_116 ( V_42 , V_114 [ V_47 / V_50 ] . V_107 ) ;
V_4 -> V_83 ++ ;
}
for ( V_47 = 0 , V_4 -> V_45 = 0 ; V_47 < V_45 ; V_47 ++ ) {
if ( V_47 < ( V_113 * 2 ) )
V_41 . V_51 = V_2 -> V_51 ;
else if ( V_47 < ( V_113 * 2 + V_83 ) )
V_41 . V_51 = V_114 [ ( V_47 - V_113 * 2 ) / V_50 ] . V_105 ;
else
V_41 . V_51 = 1 ;
V_44 = V_36 -> V_68 ( V_36 , & V_41 ,
(struct V_43 * * ) & V_4 -> V_65 [ V_47 ] ) ;
if ( V_44 )
goto V_55;
V_4 -> V_45 ++ ;
}
V_112 . V_51 = V_2 -> V_51 ;
V_44 = V_76 -> V_117 ( V_76 , & V_112 , (struct V_118 * * ) & V_4 -> V_86 ) ;
if ( V_44 )
goto V_55;
V_31 = F_6 ( ( V_2 -> V_57 * V_2 -> V_51 ) ,
V_4 -> V_9 -> V_6 -> V_56 ) ;
for ( V_47 = 0 , V_4 -> V_80 = 0 ; V_47 < V_80 ; V_47 ++ ) {
if ( V_47 < ( V_83 ) )
V_110 . V_51 = V_114 [ V_47 / V_50 ] . V_106 ;
else if ( 1 == V_50 )
V_110 . V_51 = ( V_31 <= 0x8000000 ) ? V_2 -> V_51 : 1 ;
else
V_110 . V_51 = 1 ;
V_44 = V_74 -> V_119 ( V_74 , & V_110 , & V_78 ) ;
if ( V_44 )
goto V_55;
V_4 -> V_79 [ V_47 ] = V_78 ;
V_4 -> V_80 ++ ;
}
V_108 . V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
V_108 . V_51 = 1 ;
V_108 . V_52 = V_120 ;
V_44 = V_33 -> V_54 ( V_33 , & V_108 , (struct V_42 * * ) & V_4 -> V_42 ) ;
if ( V_44 )
goto V_55;
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_59 ( V_42 , V_31 ) ;
V_44 = F_1 ( V_2 , V_4 ) ;
if ( V_44 < 0 )
goto V_55;
return 0 ;
V_55:
F_9 ( V_2 , V_4 ) ;
return V_44 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 ;
struct V_43 * V_43 ;
struct V_78 * V_78 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_118 * V_86 ;
struct V_71 * V_123 [ 8 ] = { NULL } ;
int V_44 , V_47 , V_124 , V_113 , V_50 ;
unsigned int V_31 ;
int V_125 = 0 , V_126 = 0 ;
F_9 ( V_2 , V_4 ) ;
V_44 = F_21 ( V_2 , V_4 ) ;
if ( V_44 )
return V_44 ;
V_122 -> V_127 ( V_122 , V_128 ,
& V_123 [ 0 ] , & V_123 [ 1 ] ) ;
V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
if ( 1 == V_50 ) {
V_86 = V_4 -> V_86 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
V_43 = V_4 -> V_65 [ V_47 ] ;
V_43 -> V_58 -> V_70 ( V_43 , V_123 [ V_47 ] ,
V_129 , V_86 ) ;
}
V_123 [ 0 ] = & V_86 -> V_71 ;
V_113 = 1 ;
V_125 = V_113 * 2 ;
}
for ( V_47 = 0 ; V_47 < V_4 -> V_83 ; V_47 ++ ) {
V_42 = V_4 -> V_82 [ V_47 ] ;
V_78 = V_4 -> V_79 [ V_126 + V_47 ] ;
V_43 = V_4 -> V_65 [ V_125 + V_47 ] ;
V_78 -> V_58 -> V_11 ( V_78 , V_42 , V_123 [ V_47 % V_50 ] ) ;
V_43 -> V_58 -> V_70 ( V_43 , & V_42 -> V_71 , V_72 , NULL ) ;
V_123 [ V_47 % V_50 ] = & V_43 -> V_71 ;
}
V_31 = F_6 ( ( V_2 -> V_57 * V_2 -> V_51 ) ,
V_4 -> V_9 -> V_6 -> V_56 ) ;
if ( ( V_50 > 1 ) && ( V_31 <= 0x8000000 ) ) {
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_123 [ V_47 ] -> V_58 -> V_130 ( V_123 [ V_47 ] ) ;
for ( V_124 = 0 ; V_124 < V_2 -> V_51 ; V_124 ++ ) {
V_43 = V_4 -> V_65 [ V_4 -> V_83 + V_124 * V_50 + V_47 ] ;
V_43 -> V_58 -> V_131 ( V_43 , V_123 [ V_47 ] ) ;
V_43 -> V_58 -> V_132 ( V_43 , V_72 ) ;
V_43 -> V_58 -> V_133 ( V_43 , NULL ) ;
V_43 -> V_58 -> V_134 ( V_43 ) ;
V_123 [ V_47 ] -> V_58 -> V_135 ( V_123 [ V_47 ] ) ;
V_78 = V_4 -> V_79 [ V_4 -> V_83 + V_124 * V_50 + V_47 ] ;
V_78 -> V_58 -> V_11 ( V_78 , V_4 -> V_42 ,
& V_43 -> V_71 ) ;
}
}
} else {
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_78 = V_4 -> V_79 [ V_4 -> V_83 + V_47 ] ;
V_78 -> V_58 -> V_11 ( V_78 , V_4 -> V_42 , V_123 [ V_47 ] ) ;
}
}
F_13 ( V_4 -> V_73 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 ;
struct V_33 * V_33 = V_2 -> V_34 [ V_35 ] ;
int V_47 , V_50 ;
if ( V_4 -> V_89 )
return 0 ;
V_4 -> V_89 = 1 ;
V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
for ( V_47 = 0 ; V_47 < V_4 -> V_83 ; V_47 ++ ) {
V_42 = V_4 -> V_82 [ V_47 ] ;
V_42 -> V_58 -> V_63 ( V_42 , ( ( V_47 % V_50 ) != ( V_50 - 1 ) ) ) ;
V_33 -> V_136 ( V_33 , V_42 ) ;
}
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_61 ( V_42 , F_4 ( V_4 -> V_9 -> V_6 -> V_62 ) ) ;
V_42 -> V_58 -> V_90 ( V_42 , V_4 -> V_10 -> V_91 ) ;
V_42 -> V_58 -> V_92 ( V_42 , V_4 -> V_10 -> V_91 + V_4 -> V_10 -> V_93 ) ;
V_42 -> V_58 -> V_94 ( V_42 , V_4 -> V_10 -> V_91 ) ;
V_33 -> V_136 ( V_33 , V_42 ) ;
V_33 -> V_99 ( V_33 ) ;
for ( V_47 = 0 ; V_47 < V_4 -> V_83 ; V_47 ++ ) {
V_42 = V_4 -> V_82 [ V_47 ] ;
V_42 -> V_58 -> V_97 ( V_42 , V_137 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
V_33 -> V_138 ( V_33 , V_42 ) ;
}
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_96 ( V_42 , 1 ) ;
V_42 -> V_58 -> V_97 ( V_42 , V_137 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
V_33 -> V_138 ( V_33 , V_42 ) ;
V_33 -> V_99 ( V_33 ) ;
F_16 ( V_4 -> V_73 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 = V_4 -> V_42 ;
if ( ! V_42 )
return 0 ;
return V_42 -> V_58 -> V_102 ( V_42 ) - V_4 -> V_10 -> V_91 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_33 * V_33 = V_2 -> V_34 [ V_35 ] ;
struct V_36 * V_36 = V_2 -> V_34 [ V_37 ] ;
struct V_38 V_39 = { 0 } ;
struct V_40 V_41 = { 0 } ;
struct V_42 * V_42 ;
int V_44 ;
int V_45 = V_4 -> V_9 -> V_6 -> V_46 , V_47 ;
unsigned int V_31 , V_57 = V_2 -> V_139 ;
F_9 ( V_2 , V_4 ) ;
V_39 . V_50 = V_4 -> V_9 -> V_6 -> V_46 ;
V_39 . V_51 = 1 ;
while ( V_4 -> V_9 -> V_6 -> V_56 > ( V_57 * V_39 . V_51 ) )
V_39 . V_51 <<= 1 ;
V_39 . V_52 = V_53 ;
V_44 = V_33 -> V_54 ( V_33 , & V_39 , (struct V_42 * * ) & V_4 -> V_42 ) ;
if ( V_44 )
goto V_55;
V_31 = F_6 ( V_4 -> V_9 -> V_6 -> V_56 , ( V_57 * V_39 . V_51 ) ) ;
V_42 = V_4 -> V_42 ;
V_42 -> V_58 -> V_59 ( V_42 , V_31 ) ;
V_42 -> V_58 -> V_60 ( V_42 , F_7 ( V_31 ) ) ;
V_42 -> V_58 -> V_61 ( V_42 , F_4 ( V_4 -> V_9 -> V_6 -> V_62 ) ) ;
V_42 -> V_58 -> V_63 ( V_42 , ( V_42 -> V_58 -> V_64 ( V_42 ) != NULL ) ) ;
V_42 -> V_58 -> V_140 ( V_42 , 1 ) ;
V_45 = ( V_45 < 2 ) ? 2 : V_45 ;
V_4 -> V_65 = F_10 ( sizeof( void * ) * V_45 , V_66 ) ;
if ( ! V_4 -> V_65 ) {
V_44 = - V_67 ;
goto V_55;
}
V_41 . V_51 = V_39 . V_51 ;
for ( V_47 = 0 , V_4 -> V_45 = 0 ; V_47 < V_45 ; V_47 ++ ) {
V_44 = V_36 -> V_68 ( V_36 , & V_41 ,
(struct V_43 * * ) & V_4 -> V_65 [ V_47 ] ) ;
if ( V_44 )
goto V_55;
V_4 -> V_45 ++ ;
}
V_44 = F_1 ( V_2 , V_4 ) ;
if ( V_44 < 0 )
goto V_55;
return 0 ;
V_55:
F_9 ( V_2 , V_4 ) ;
return V_44 ;
}
static int F_26 ( struct V_1 * V_2 , int V_56 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
int V_44 ;
V_44 = V_141 -> V_142 ( V_141 , V_56 ) ;
V_2 -> V_139 = V_44 ? 0 : V_56 ;
return V_44 ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_143 * V_143 = F_28 ( V_2 -> V_144 [ V_145 ] , struct V_143 , V_146 ) ;
unsigned int V_56 = V_4 -> V_9 -> V_6 -> V_56 ;
unsigned int V_147 ;
int V_44 = 0 ;
unsigned char V_148 ;
switch ( V_56 ) {
case 48000 :
V_148 = V_149 ;
break;
case 44100 :
V_148 = V_150 ;
break;
case 32000 :
V_148 = V_151 ;
break;
default:
return - V_13 ;
}
F_11 ( & V_2 -> V_69 ) ;
V_143 -> V_58 -> V_152 ( V_143 , & V_147 ) ;
if ( ( ( V_147 >> 24 ) & V_153 ) != V_148 ) {
V_147 &= ~ ( V_153 << 24 ) ;
V_147 |= ( V_148 << 24 ) ;
V_143 -> V_58 -> V_154 ( V_143 , V_147 ) ;
V_143 -> V_58 -> V_99 ( V_143 ) ;
}
if ( ( V_56 != V_2 -> V_139 ) && ( 32000 != V_56 ) )
V_44 = F_26 ( V_2 , V_56 ) ;
F_12 ( & V_2 -> V_69 ) ;
return V_44 ;
}
static int
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_42 * V_42 ;
struct V_43 * V_43 ;
struct V_143 * V_143 ;
int V_44 ;
int V_47 ;
F_9 ( V_2 , V_4 ) ;
V_44 = F_27 ( V_2 , V_4 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_25 ( V_2 , V_4 ) ;
if ( V_44 )
return V_44 ;
V_42 = V_4 -> V_42 ;
for ( V_47 = 0 ; V_47 < V_4 -> V_45 ; V_47 ++ ) {
V_43 = V_4 -> V_65 [ V_47 ] ;
V_43 -> V_58 -> V_70 ( V_43 , & V_42 -> V_71 , V_72 , NULL ) ;
V_42 = V_42 -> V_58 -> V_64 ( V_42 ) ;
if ( ! V_42 )
V_42 = V_4 -> V_42 ;
}
F_11 ( & V_2 -> V_69 ) ;
V_143 = F_28 ( V_2 -> V_144 [ V_145 ] , struct V_143 , V_146 ) ;
V_43 = V_4 -> V_65 [ 0 ] ;
V_143 -> V_58 -> V_155 ( V_143 , & V_43 -> V_71 ) ;
V_43 = V_4 -> V_65 [ 1 ] ;
V_143 -> V_58 -> V_156 ( V_143 , & V_43 -> V_71 ) ;
F_12 ( & V_2 -> V_69 ) ;
F_13 ( V_4 -> V_73 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_42 * V_42 ;
if ( V_141 -> V_157 ( V_141 , V_158 ) )
return 0 ;
V_122 -> V_159 ( V_122 , V_160 , NULL ) ;
V_122 -> V_161 ( V_122 , V_160 , NULL ) ;
V_141 -> V_162 ( V_141 , V_158 ) ;
V_42 = V_2 -> V_163 [ 2 ] ;
V_122 -> V_159 ( V_122 , V_164 , & V_42 -> V_71 ) ;
V_42 = V_2 -> V_163 [ 3 ] ;
V_122 -> V_161 ( V_122 , V_164 , & V_42 -> V_71 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_42 * V_42 ;
if ( V_141 -> V_157 ( V_141 , V_165 ) )
return 0 ;
V_122 -> V_159 ( V_122 , V_164 , NULL ) ;
V_122 -> V_161 ( V_122 , V_164 , NULL ) ;
V_141 -> V_162 ( V_141 , V_165 ) ;
V_42 = V_2 -> V_163 [ 2 ] ;
V_122 -> V_159 ( V_122 , V_160 , & V_42 -> V_71 ) ;
V_42 = V_2 -> V_163 [ 3 ] ;
V_122 -> V_161 ( V_122 , V_160 , & V_42 -> V_71 ) ;
return 0 ;
}
static struct V_166 F_32 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
return V_141 -> V_166 ( V_141 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
return V_141 -> V_167 ( V_141 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_101 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
return V_141 -> V_168 ( V_141 , V_101 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
return V_141 -> V_169 ( V_141 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_101 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
return V_141 -> V_170 ( V_141 , V_101 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
if ( V_141 -> V_157 ( V_141 , V_171 ) )
return 0 ;
V_141 -> V_162 ( V_141 , V_171 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned char V_172 , int type )
{
struct V_173 * V_173 = V_2 -> V_34 [ V_174 ] ;
if ( V_172 )
V_173 -> V_175 ( V_173 , V_2 -> V_144 [ type ] ) ;
else
V_173 -> V_176 ( V_173 , V_2 -> V_144 [ type ] ) ;
V_173 -> V_99 ( V_173 ) ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , unsigned int * V_147 , int type )
{
struct V_143 * V_143 = F_28 ( V_2 -> V_144 [ type ] , struct V_143 , V_146 ) ;
return V_143 -> V_58 -> V_152 ( V_143 , V_147 ) ;
}
static int
F_40 ( struct V_1 * V_2 , unsigned int V_147 , int type )
{
struct V_143 * V_143 = F_28 ( V_2 -> V_144 [ type ] , struct V_143 , V_146 ) ;
V_143 -> V_58 -> V_154 ( V_143 , V_147 ) ;
V_143 -> V_58 -> V_99 ( V_143 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_177 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_178 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_179 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_180 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_181 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_182 ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_145 ) ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_172 )
{
return F_38 ( V_2 , V_172 , V_183 ) ;
}
static int F_49 ( struct V_1 * V_2 , unsigned int * V_147 )
{
return F_39 ( V_2 , V_147 , V_145 ) ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_147 )
{
return F_40 ( V_2 , V_147 , V_145 ) ;
}
static int F_51 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_184 V_185 = { 0 } ;
struct V_143 * V_143 ;
int V_44 ;
struct V_121 * V_122 = V_2 -> V_122 ;
struct V_71 * V_186 [ 2 ] = { NULL } ;
unsigned int V_187 = 0 ;
F_11 ( & V_2 -> V_69 ) ;
V_143 = F_28 ( V_2 -> V_144 [ V_145 ] , struct V_143 , V_146 ) ;
V_185 . V_51 = V_172 ? 1 : V_2 -> V_51 ;
V_185 . V_188 = V_172 ? 1 : 0 ;
V_44 = V_143 -> V_58 -> V_189 ( V_143 , & V_185 ) ;
if ( V_172 ) {
V_187 = V_190 ;
} else {
V_122 -> V_127 ( V_122 , V_191 ,
& V_186 [ 0 ] , & V_186 [ 1 ] ) ;
V_143 -> V_58 -> V_155 ( V_143 , V_186 [ 0 ] ) ;
V_143 -> V_58 -> V_156 ( V_143 , V_186 [ 1 ] ) ;
if ( V_2 -> V_139 != V_2 -> V_57 )
V_44 = F_26 ( V_2 , V_2 -> V_57 ) ;
}
V_143 -> V_58 -> V_154 ( V_143 , V_187 ) ;
V_143 -> V_58 -> V_99 ( V_143 ) ;
F_12 ( & V_2 -> V_69 ) ;
return V_44 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_173 * V_173 = NULL ;
struct V_143 * V_143 = NULL ;
struct V_192 * V_192 = NULL ;
struct V_146 * V_146 = NULL ;
struct V_76 * V_76 = NULL ;
struct V_33 * V_33 = NULL ;
struct V_74 * V_74 = NULL ;
struct V_78 * V_78 = NULL ;
struct V_121 * V_122 = NULL ;
if ( V_2 -> V_122 ) {
V_122 = V_2 -> V_122 ;
V_122 -> V_159 ( V_122 , V_164 , NULL ) ;
V_122 -> V_161 ( V_122 , V_164 , NULL ) ;
V_122 -> V_159 ( V_122 , V_160 , NULL ) ;
V_122 -> V_161 ( V_122 , V_160 , NULL ) ;
V_122 -> V_159 ( V_122 , V_193 , NULL ) ;
V_122 -> V_161 ( V_122 , V_193 , NULL ) ;
}
if ( V_2 -> V_144 ) {
V_173 = (struct V_173 * ) V_2 -> V_34 [ V_174 ] ;
for ( V_47 = 0 ; V_47 < V_2 -> V_194 ; V_47 ++ ) {
V_146 = V_2 -> V_144 [ V_47 ] ;
if ( V_146 -> type < V_181 ) {
V_143 = F_28 ( V_146 , struct V_143 , V_146 ) ;
V_143 -> V_58 -> V_195 ( V_143 ) ;
V_143 -> V_58 -> V_196 ( V_143 ) ;
} else {
V_192 = F_28 ( V_146 , struct V_192 , V_146 ) ;
}
V_173 -> V_197 ( V_173 , V_146 ) ;
}
F_14 ( V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
}
if ( V_2 -> V_49 ) {
V_76 = V_2 -> V_34 [ V_77 ] ;
for ( V_47 = 0 ; V_47 < V_2 -> V_198 ; V_47 ++ )
V_76 -> V_87 ( V_76 , V_2 -> V_49 [ V_47 ] ) ;
F_14 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
if ( V_2 -> V_163 ) {
V_33 = V_2 -> V_34 [ V_35 ] ;
for ( V_47 = 0 ; V_47 < V_2 -> V_199 ; V_47 ++ )
V_33 -> V_84 ( V_33 , V_2 -> V_163 [ V_47 ] ) ;
F_14 ( V_2 -> V_163 ) ;
V_2 -> V_163 = NULL ;
}
if ( V_2 -> V_79 ) {
V_74 = V_2 -> V_34 [ V_75 ] ;
for ( V_47 = 0 ; V_47 < V_2 -> V_80 ; V_47 ++ ) {
V_78 = V_2 -> V_79 [ V_47 ] ;
V_78 -> V_58 -> V_14 ( V_78 ) ;
V_74 -> V_81 ( V_74 , V_2 -> V_79 [ V_47 ] ) ;
}
F_14 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_47 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_73 ) {
F_54 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
}
F_52 ( V_2 ) ;
if ( V_2 -> V_122 )
F_55 ( V_2 -> V_122 ) ;
for ( V_47 = 0 ; V_47 < V_200 ; V_47 ++ ) {
if ( V_201 [ V_47 ] . V_202 && V_2 -> V_34 [ V_47 ] )
V_201 [ V_47 ] . V_202 ( V_2 -> V_34 [ V_47 ] ) ;
}
if ( V_2 -> V_141 )
F_56 ( (struct V_141 * ) V_2 -> V_141 ) ;
if ( V_2 -> V_8 ) {
F_57 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static int F_58 ( struct V_203 * V_204 )
{
struct V_1 * V_2 = V_204 -> V_205 ;
return F_53 ( V_2 ) ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_206 )
{
const struct V_207 * V_208 ;
const struct V_207 * V_209 ;
T_3 V_210 , V_211 ;
switch ( V_2 -> V_212 ) {
case V_213 :
V_2 -> V_214 = L_2 ;
V_209 = V_215 ;
break;
case V_216 :
V_2 -> V_214 = L_3 ;
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
V_208 = F_60 ( V_210 , V_211 , V_209 ) ;
if ( V_208 ) {
if ( V_208 -> V_221 < 0 ) {
F_5 ( V_28 L_4
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
F_61 ( L_6 ,
V_2 -> V_214 , V_2 -> V_225 ,
V_210 , V_211 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 )
{
enum V_227 V_47 ;
int V_44 ;
V_228 [ V_229 ] . V_230 = V_2 -> V_214 ;
for ( V_47 = 0 ; V_47 < V_231 ; V_47 ++ ) {
if ( ! V_228 [ V_47 ] . V_232 )
continue;
V_44 = V_228 [ V_47 ] . V_232 ( V_2 , V_47 ,
V_228 [ V_47 ] . V_230 ) ;
if ( V_44 ) {
F_5 ( V_28 L_4
L_7 , V_47 ) ;
return V_44 ;
}
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_141 * V_141 ;
struct V_233 V_234 = { 0 } ;
int V_47 , V_44 ;
V_44 = F_64 ( V_2 -> V_218 , V_2 -> V_212 , V_2 -> V_222 , & V_141 ) ;
if ( V_44 ) {
F_5 ( V_28 L_8 ) ;
return V_44 ;
}
V_2 -> V_141 = V_141 ;
V_234 . V_57 = V_2 -> V_57 ;
V_234 . V_51 = V_2 -> V_51 ;
V_234 . V_235 = F_3 ( V_2 , 0 ) ;
V_44 = V_141 -> V_236 ( V_141 , & V_234 ) ;
if ( V_44 < 0 )
return V_44 ;
for ( V_47 = 0 ; V_47 < V_200 ; V_47 ++ ) {
if ( ! V_201 [ V_47 ] . V_232 )
continue;
V_44 = V_201 [ V_47 ] . V_232 ( V_2 -> V_141 , & V_2 -> V_34 [ V_47 ] ) ;
if ( V_44 ) {
F_5 ( V_28 L_4
L_9 , V_47 ) ;
return V_44 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_237 V_238 = { 0 } ;
struct V_173 * V_173 ;
struct V_38 V_108 = { 0 } ;
struct V_33 * V_33 ;
struct V_109 V_110 = { 0 } ;
struct V_74 * V_74 ;
struct V_111 V_112 = { 0 } ;
struct V_76 * V_76 ;
int V_44 , V_47 , V_239 , V_240 ;
V_240 = ( ( V_2 -> V_222 == V_241 ) ? 8 : 7 ) ;
V_239 = ( ( V_2 -> V_222 == V_241 ) ? 6 : 4 ) ;
V_2 -> V_144 = F_10 ( sizeof( void * ) * V_240 , V_66 ) ;
if ( ! V_2 -> V_144 )
return - V_67 ;
V_2 -> V_163 = F_10 ( sizeof( void * ) * V_239 , V_66 ) ;
if ( ! V_2 -> V_163 )
return - V_67 ;
V_2 -> V_79 = F_10 ( sizeof( void * ) * V_239 , V_66 ) ;
if ( ! V_2 -> V_79 )
return - V_67 ;
V_2 -> V_49 = F_10 ( sizeof( void * ) * ( 2 * 4 ) , V_66 ) ;
if ( ! V_2 -> V_49 )
return - V_67 ;
V_173 = (struct V_173 * ) V_2 -> V_34 [ V_174 ] ;
V_238 . V_51 = V_2 -> V_51 ;
for ( V_47 = 0 , V_2 -> V_194 = 0 ; V_47 < V_240 ; V_47 ++ ) {
V_238 . type = ( V_2 -> V_222 != V_242 ) ? V_47 :
( ( V_47 == V_183 ) ? V_243 : V_47 ) ;
V_44 = V_173 -> V_244 ( V_173 , & V_238 ,
(struct V_146 * * ) & V_2 -> V_144 [ V_47 ] ) ;
if ( V_44 ) {
F_5 ( V_28 L_10
L_11 , V_47 ) ;
return V_44 ;
}
V_2 -> V_194 ++ ;
}
V_33 = V_2 -> V_34 [ V_35 ] ;
V_108 . V_50 = 1 ;
V_108 . V_51 = V_2 -> V_51 ;
V_108 . V_52 = V_115 ;
for ( V_47 = 0 , V_2 -> V_199 = 0 ; V_47 < V_239 ; V_47 ++ ) {
V_44 = V_33 -> V_54 ( V_33 , & V_108 ,
(struct V_42 * * ) & V_2 -> V_163 [ V_47 ] ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_199 ++ ;
}
V_74 = V_2 -> V_34 [ V_75 ] ;
V_110 . V_51 = 8 ;
for ( V_47 = 0 , V_2 -> V_80 = 0 ; V_47 < V_239 ; V_47 ++ ) {
V_44 = V_74 -> V_119 ( V_74 , & V_110 ,
(struct V_78 * * ) & V_2 -> V_79 [ V_47 ] ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_80 ++ ;
}
V_76 = V_2 -> V_34 [ V_77 ] ;
V_112 . V_51 = V_2 -> V_51 ;
for ( V_47 = 0 , V_2 -> V_198 = 0 ; V_47 < ( 2 * 4 ) ; V_47 ++ ) {
V_44 = V_76 -> V_117 ( V_76 , & V_112 ,
(struct V_118 * * ) & V_2 -> V_49 [ V_47 ] ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_198 ++ ;
}
return 0 ;
}
static void
F_66 ( struct V_33 * V_33 , struct V_192 * V_192 ,
struct V_42 * * V_163 , struct V_78 * * V_79 )
{
struct V_71 * V_186 [ 2 ] = { NULL } ;
struct V_42 * V_42 ;
struct V_78 * V_78 ;
int V_47 = 0 ;
V_186 [ 0 ] = & V_192 -> V_146 . V_245 ;
V_186 [ 1 ] = & V_192 -> V_146 . V_246 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
V_42 = V_163 [ V_47 ] ;
V_78 = V_79 [ V_47 ] ;
V_78 -> V_58 -> V_11 ( V_78 , V_42 , V_186 [ V_47 ] ) ;
V_33 -> V_136 ( V_33 , V_42 ) ;
}
V_33 -> V_99 ( V_33 ) ;
V_42 = V_163 [ 0 ] ;
V_42 -> V_58 -> V_63 ( V_42 , 1 ) ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
V_42 = V_163 [ V_47 ] ;
V_42 -> V_58 -> V_97 ( V_42 , V_137 ) ;
V_42 -> V_58 -> V_99 ( V_42 ) ;
V_33 -> V_138 ( V_33 , V_42 ) ;
}
V_192 -> V_58 -> V_247 ( V_192 , & ( V_163 [ 0 ] -> V_71 ) ) ;
V_192 -> V_58 -> V_248 ( V_192 , & ( V_163 [ 1 ] -> V_71 ) ) ;
V_192 -> V_58 -> V_249 ( V_192 , 1 ) ;
V_192 -> V_58 -> V_250 ( V_192 , 1 ) ;
V_192 -> V_58 -> V_99 ( V_192 ) ;
V_33 -> V_99 ( V_33 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_192 * V_192 ;
struct V_143 * V_143 ;
struct V_42 * V_42 ;
struct V_118 * V_118 ;
struct V_121 * V_122 ;
struct V_71 * V_186 [ 2 ] = { NULL } ;
int V_47 , V_124 ;
V_122 = V_2 -> V_122 ;
for ( V_47 = V_251 , V_124 = V_177 ; V_47 <= V_191 ; V_47 ++ , V_124 ++ ) {
V_122 -> V_127 ( V_122 , V_47 , & V_186 [ 0 ] , & V_186 [ 1 ] ) ;
V_143 = F_28 ( V_2 -> V_144 [ V_124 ] , struct V_143 , V_146 ) ;
V_143 -> V_58 -> V_155 ( V_143 , V_186 [ 0 ] ) ;
V_143 -> V_58 -> V_156 ( V_143 , V_186 [ 1 ] ) ;
}
V_192 = F_28 ( V_2 -> V_144 [ V_181 ] , struct V_192 , V_146 ) ;
F_66 ( V_2 -> V_34 [ V_35 ] , V_192 ,
(struct V_42 * * ) & V_2 -> V_163 [ 2 ] ,
(struct V_78 * * ) & V_2 -> V_79 [ 2 ] ) ;
V_42 = V_2 -> V_163 [ 2 ] ;
V_122 -> V_159 ( V_122 , V_164 , & V_42 -> V_71 ) ;
V_42 = V_2 -> V_163 [ 3 ] ;
V_122 -> V_161 ( V_122 , V_164 , & V_42 -> V_71 ) ;
if ( V_2 -> V_222 == V_241 ) {
V_192 = F_28 ( V_2 -> V_144 [ V_182 ] , struct V_192 , V_146 ) ;
F_66 ( V_2 -> V_34 [ V_35 ] , V_192 ,
(struct V_42 * * ) & V_2 -> V_163 [ 4 ] ,
(struct V_78 * * ) & V_2 -> V_79 [ 4 ] ) ;
V_42 = V_2 -> V_163 [ 4 ] ;
V_122 -> V_159 ( V_122 , V_160 , & V_42 -> V_71 ) ;
V_42 = V_2 -> V_163 [ 5 ] ;
V_122 -> V_161 ( V_122 , V_160 , & V_42 -> V_71 ) ;
}
V_192 = F_28 ( V_2 -> V_144 [ V_183 ] , struct V_192 , V_146 ) ;
F_66 ( V_2 -> V_34 [ V_35 ] , V_192 ,
(struct V_42 * * ) & V_2 -> V_163 [ 0 ] ,
(struct V_78 * * ) & V_2 -> V_79 [ 0 ] ) ;
V_42 = V_2 -> V_163 [ 0 ] ;
V_122 -> V_159 ( V_122 , V_193 , & V_42 -> V_71 ) ;
V_42 = V_2 -> V_163 [ 1 ] ;
V_122 -> V_161 ( V_122 , V_193 , & V_42 -> V_71 ) ;
for ( V_47 = V_252 , V_124 = 0 ; V_47 <= V_253 ; V_47 ++ , V_124 += 2 ) {
V_118 = V_2 -> V_49 [ V_124 ] ;
V_122 -> V_159 ( V_122 , V_47 , & V_118 -> V_71 ) ;
V_118 = V_2 -> V_49 [ V_124 + 1 ] ;
V_122 -> V_161 ( V_122 , V_47 , & V_118 -> V_71 ) ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
int V_47 ;
struct V_141 * V_141 = V_2 -> V_141 ;
F_69 ( V_2 -> V_254 , V_255 ) ;
for ( V_47 = V_256 ; V_47 < V_257 ; V_47 ++ ) {
if ( ! V_2 -> V_258 [ V_47 ] )
continue;
F_70 ( V_2 -> V_258 [ V_47 ] ) ;
}
F_52 ( V_2 ) ;
V_141 -> V_259 ( V_141 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_141 * V_141 = V_2 -> V_141 ;
struct V_233 V_234 = { 0 } ;
V_234 . V_57 = V_2 -> V_57 ;
V_234 . V_51 = V_2 -> V_51 ;
V_234 . V_235 = F_3 ( V_2 , 0 ) ;
return V_141 -> V_260 ( V_141 , & V_234 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
int V_44 = 0 ;
V_44 = F_65 ( V_2 ) ;
if ( V_44 < 0 ) {
F_52 ( V_2 ) ;
return V_44 ;
}
F_67 ( V_2 ) ;
V_122 = V_2 -> V_122 ;
V_122 -> V_260 ( V_122 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_44 = 0 ;
V_44 = F_71 ( V_2 ) ;
if ( V_44 < 0 ) {
F_5 ( V_28 L_12
L_13 ) ;
F_74 ( V_2 -> V_254 ) ;
return V_44 ;
}
V_44 = F_72 ( V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
F_69 ( V_2 -> V_254 , V_261 ) ;
return 0 ;
}
int F_75 ( struct V_262 * V_254 , struct V_263 * V_218 ,
unsigned int V_57 , unsigned int V_51 ,
int V_212 , unsigned int V_206 ,
struct V_1 * * V_264 )
{
struct V_1 * V_2 ;
static struct V_265 V_58 = {
. V_266 = F_58 ,
} ;
int V_44 ;
* V_264 = NULL ;
V_2 = F_10 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
* V_2 = V_267 ;
V_2 -> V_254 = V_254 ;
V_2 -> V_218 = V_218 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_212 = V_212 ;
F_76 ( & V_2 -> V_69 ) ;
V_44 = F_59 ( V_2 , V_206 ) ;
if ( V_44 < 0 ) {
F_5 ( V_28 L_14 ) ;
goto V_55;
}
V_44 = F_77 ( & V_2 -> V_8 , V_218 ) ;
if ( V_44 < 0 )
goto V_55;
V_44 = F_63 ( V_2 ) ;
if ( V_44 < 0 )
goto V_55;
V_44 = F_78 ( V_2 , (struct V_121 * * ) & V_2 -> V_122 ) ;
if ( V_44 ) {
F_5 ( V_28 L_15 ) ;
goto V_55;
}
V_44 = F_65 ( V_2 ) ;
if ( V_44 < 0 )
goto V_55;
F_67 ( V_2 ) ;
V_2 -> V_73 = F_79 ( V_2 ) ;
if ( ! V_2 -> V_73 ) {
V_44 = - V_67 ;
goto V_55;
}
V_44 = F_80 ( V_254 , V_268 , V_2 , & V_58 ) ;
if ( V_44 < 0 )
goto V_55;
F_81 ( V_254 , & V_218 -> V_204 ) ;
* V_264 = V_2 ;
return 0 ;
V_55:
F_53 ( V_2 ) ;
F_5 ( V_28 L_16 ) ;
return V_44 ;
}
