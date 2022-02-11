static
int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( 4 , L_1 , F_3 () ) ;
if ( V_2 -> V_5 < V_6 )
return - V_7 ;
if ( F_4 ( & V_8 ) )
return - V_9 ;
V_4 -> V_10 = V_2 -> V_11 . V_12 ;
F_5 ( V_2 , V_13 ) ;
if ( ! F_6
( & V_2 -> V_14 , V_15 / 2 ) ) {
F_2 ( 1 , L_2 ) ;
}
F_7 ( & V_8 ) ;
V_16 . V_17 = V_18 + V_15 ;
F_8 ( & V_16 ) ;
return 0 ;
}
static
void F_9 ( unsigned long V_19 )
{
F_2 ( 4 , L_1 , F_3 () ) ;
F_10 ( & V_8 , 0 ) ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
F_2 ( 2 , L_3 ) ;
F_5 ( V_2 , V_21 ) ;
if ( V_20 & V_22 )
F_5 ( V_2 , V_23 ) ;
if ( V_20 & V_24 )
F_5 ( V_2 , V_25 ) ;
if ( V_20 & V_26 )
F_5 ( V_2 , V_27 ) ;
if ( V_20 & V_28 )
F_5 ( V_2 , V_29 ) ;
if ( V_20 & V_30 )
F_5 ( V_2 , V_31 ) ;
if ( V_20 & V_32 )
F_5 ( V_2 , V_33 ) ;
if ( V_20 & V_34 )
F_5 ( V_2 , V_35 ) ;
if ( V_20 & V_36 )
F_5 ( V_2 , V_37 ) ;
if ( V_20 & V_38 ) {
F_5 ( V_2 , V_39 ) ;
F_5 ( V_2 , V_40 ) ;
}
if ( V_20 & V_41 )
F_5 ( V_2 , V_42 ) ;
if ( V_20 & V_43 )
F_5 ( V_2 , V_44 ) ;
if ( V_20 & V_45 )
F_5 ( V_2 , V_46 ) ;
F_5 ( V_2 , V_47 ) ;
F_5 ( V_2 , V_48 ) ;
return 0 ;
}
static int F_12 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_5 < V_6 )
strcpy ( V_53 , L_4 ) ;
else if ( V_2 -> V_11 . V_57 == V_58 )
strcpy ( V_53 , L_5 ) ;
else if ( V_2 -> V_11 . V_57 == V_59 )
strcpy ( V_53 , L_6 ) ;
else
strcpy ( V_53 , L_7 ) ;
return 0 ;
}
static int F_14 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_60 * V_61 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_62 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ( V_61 -> V_63 == 1 ) &&
( V_61 -> V_64 >= ( int ) 2.412e8 ) && ( V_61 -> V_64 <= ( int ) 2.487e8 ) ) {
int V_65 = V_61 -> V_64 / 100000 ;
int V_66 = 0 ;
while ( ( V_66 < 14 ) && ( V_65 != V_67 [ V_66 ] ) )
V_66 ++ ;
V_61 -> V_63 = 0 ;
V_61 -> V_64 = V_66 + 1 ;
}
if ( ( V_61 -> V_64 > 1000 ) || ( V_61 -> V_63 > 0 ) )
return - V_68 ;
V_62 = V_61 -> V_64 ;
if ( ( V_62 < 1 ) || ( V_62 > 14 ) ) {
F_15 ( V_50 , L_8 ,
V_50 -> V_69 , V_61 -> V_64 ) ;
return - V_70 ;
}
V_2 -> V_11 . V_62 = ( V_71 ) ( V_62 ) ;
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
static int F_16 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_60 * V_61 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_65 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( F_17 ( V_2 -> V_75 ) )
V_65 = ( int ) V_2 -> V_76 . V_62 ;
else
V_65 = ( int ) V_2 -> V_11 . V_62 ;
V_61 -> V_64 = V_67 [ V_65 - 1 ] * 100000 ;
V_61 -> V_63 = 1 ;
return 0 ;
}
static int F_18 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
T_1 V_79 ;
F_2 ( 2 , L_9 , V_78 -> V_80 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ! V_78 -> V_80 ) {
memset ( V_2 -> V_11 . V_81 . V_82 , 0 , sizeof( V_2 -> V_11 . V_81 . V_82 ) ) ;
V_2 -> V_11 . V_81 . V_83 = 0 ;
} else {
#if 1
V_79 = V_78 -> V_84 ;
if ( V_79 > 0 && V_54 [ V_79 - 1 ] == '\0' )
V_79 -- ;
if ( V_79 > V_85 )
return - V_70 ;
#else
if ( V_78 -> V_84 > V_85 + 1 )
return - V_86 ;
#endif
memset ( V_2 -> V_11 . V_81 . V_82 , 0 , sizeof( V_2 -> V_11 . V_81 . V_82 ) ) ;
#if 1
memcpy ( V_2 -> V_11 . V_81 . V_82 , V_54 , V_79 ) ;
V_2 -> V_11 . V_81 . V_83 = V_79 ;
#else
memcpy ( V_2 -> V_11 . V_81 . V_82 , V_54 , V_78 -> V_84 ) ;
V_2 -> V_11 . V_81 . V_83 = V_78 -> V_84 ;
#endif
}
V_2 -> V_72 |= V_73 ;
F_11 ( V_2 , V_2 -> V_72 ) ;
V_2 -> V_72 = 0 ;
return 0 ;
}
static int F_19 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_11 . V_81 . V_83 != 0 ) {
memcpy ( V_54 , V_2 -> V_11 . V_81 . V_82 , V_2 -> V_11 . V_81 . V_83 ) ;
V_78 -> V_84 = V_2 -> V_11 . V_81 . V_83 ;
V_78 -> V_80 = 1 ;
} else {
V_78 -> V_84 = 0 ;
V_78 -> V_80 = 0 ;
}
return 0 ;
}
static int F_20 ( struct V_49 * V_50 , struct V_51 * V_52 ,
struct V_87 * V_88 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_11 . V_12 == V_89 ||
V_2 -> V_11 . V_12 == V_90 ) {
memcpy ( V_2 -> V_11 . V_91 , & V_88 -> V_92 , V_93 ) ;
if ( F_21 ( ( V_71 * ) V_2 -> V_11 . V_91 ) )
V_2 -> V_72 |= V_73 ;
} else {
F_22 ( V_2 -> V_11 . V_91 ) ;
return - V_68 ;
}
F_2 ( 2 , L_10 , V_2 -> V_11 . V_91 ) ;
if ( V_2 -> V_72 ) {
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
return 0 ;
}
static int F_23 ( struct V_49 * V_50 , struct V_51 * V_52 ,
struct V_87 * V_94 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( F_17 ( V_2 -> V_75 ) )
memcpy ( V_94 -> V_92 , V_2 -> V_76 . V_91 , V_93 ) ;
else
F_22 ( V_94 -> V_92 ) ;
V_94 -> V_95 = V_96 ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_77 * V_78 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_78 -> V_84 > 16 + 1 )
return - V_86 ;
memset ( V_2 -> V_97 , 0 , sizeof( V_2 -> V_97 ) ) ;
memcpy ( V_2 -> V_97 , V_54 , V_78 -> V_84 ) ;
return - V_74 ;
}
static int F_25 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_77 * V_78 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
strncpy ( V_54 , V_2 -> V_97 , 16 ) ;
V_54 [ 16 ] = '\0' ;
V_78 -> V_84 = strlen ( V_54 ) + 1 ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_100 = 0 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_11 . V_57 == V_58 ) {
if ( V_99 -> V_101 == 1 ) {
switch ( V_99 -> V_102 ) {
case 11000000 :
case 5500000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
( V_104 ) ( V_99 -> V_102 / 500000 ) ;
break;
case 2000000 :
case 1000000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
( ( V_104 ) ( V_99 -> V_102 / 500000 ) ) |
V_105 ;
break;
default:
return - V_70 ;
}
V_2 -> V_11 . V_106 = V_107 ;
V_2 -> V_11 . V_103 . V_83 = 1 ;
} else {
if ( V_99 -> V_102 > 0 ) {
switch ( V_99 -> V_102 ) {
case 11000000 :
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 ;
V_100 ++ ;
case 5500000 :
V_2 -> V_11 . V_103 . V_82 [ 2 ] = V_109 ;
V_100 ++ ;
case 2000000 :
V_2 -> V_11 . V_103 . V_82 [ 1 ] =
V_110 | V_105 ;
V_100 ++ ;
case 1000000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
V_111 | V_105 ;
V_100 ++ ;
break;
default:
return - V_70 ;
}
V_2 -> V_11 . V_106 = V_112 ;
V_2 -> V_11 . V_103 . V_83 = V_100 ;
} else {
V_2 -> V_11 . V_103 . V_82 [ 3 ] = V_108 ;
V_2 -> V_11 . V_103 . V_82 [ 2 ] = V_109 ;
V_2 -> V_11 . V_103 . V_82 [ 1 ] =
V_110 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
V_111 | V_105 ;
V_2 -> V_11 . V_106 = V_113 ;
V_2 -> V_11 . V_103 . V_83 = 4 ;
}
}
} else {
if ( V_99 -> V_101 == 1 ) {
switch ( V_99 -> V_102 ) {
case 54000000 :
case 48000000 :
case 36000000 :
case 18000000 :
case 9000000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
( V_104 ) ( V_99 -> V_102 / 500000 ) ;
break;
case 24000000 :
case 12000000 :
case 11000000 :
case 6000000 :
case 5500000 :
case 2000000 :
case 1000000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
( ( V_104 ) ( V_99 -> V_102 / 500000 ) ) |
V_105 ;
break;
default:
return - V_70 ;
}
V_2 -> V_11 . V_106 = V_107 ;
V_2 -> V_11 . V_103 . V_83 = 1 ;
} else {
if ( V_99 -> V_102 > 0 ) {
switch ( V_99 -> V_102 ) {
case 54000000 :
V_2 -> V_11 . V_103 . V_82 [ 11 ] =
V_114 ;
V_100 ++ ;
case 48000000 :
V_2 -> V_11 . V_103 . V_82 [ 10 ] =
V_115 ;
V_100 ++ ;
case 36000000 :
V_2 -> V_11 . V_103 . V_82 [ 9 ] =
V_116 ;
V_100 ++ ;
case 24000000 :
case 18000000 :
case 12000000 :
case 11000000 :
case 9000000 :
case 6000000 :
if ( V_99 -> V_102 == 24000000 ) {
V_2 -> V_11 . V_103 . V_82 [ 8 ] =
V_117 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 7 ] =
V_118 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 6 ] =
V_119 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 5 ] =
V_120 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_121 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 | V_105 ;
V_100 ++ ;
} else if ( V_99 -> V_102 == 18000000 ) {
V_2 -> V_11 . V_103 . V_82 [ 7 ] =
V_117 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 6 ] =
V_118 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 5 ] =
V_120 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_121 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 | V_105 ;
V_100 ++ ;
} else if ( V_99 -> V_102 == 12000000 ) {
V_2 -> V_11 . V_103 . V_82 [ 6 ] =
V_118 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 5 ] =
V_120 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_121 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 | V_105 ;
V_100 ++ ;
} else if ( V_99 -> V_102 == 11000000 ) {
V_2 -> V_11 . V_103 . V_82 [ 5 ] =
V_118 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_121 | V_105 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 | V_105 ;
V_100 ++ ;
} else if ( V_99 -> V_102 == 9000000 ) {
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_118 ;
V_100 ++ ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_121 | V_105 ;
V_100 ++ ;
} else {
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_121 | V_105 ;
V_100 ++ ;
}
case 5500000 :
V_2 -> V_11 . V_103 . V_82 [ 2 ] =
V_109 | V_105 ;
V_100 ++ ;
case 2000000 :
V_2 -> V_11 . V_103 . V_82 [ 1 ] =
V_110 | V_105 ;
V_100 ++ ;
case 1000000 :
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
V_111 | V_105 ;
V_100 ++ ;
break;
default:
return - V_70 ;
}
V_2 -> V_11 . V_106 = V_112 ;
V_2 -> V_11 . V_103 . V_83 = V_100 ;
} else {
V_2 -> V_11 . V_103 . V_82 [ 11 ] = V_114 ;
V_2 -> V_11 . V_103 . V_82 [ 10 ] = V_115 ;
V_2 -> V_11 . V_103 . V_82 [ 9 ] = V_116 ;
V_2 -> V_11 . V_103 . V_82 [ 8 ] = V_117 ;
V_2 -> V_11 . V_103 . V_82 [ 7 ] = V_118 ;
V_2 -> V_11 . V_103 . V_82 [ 6 ] =
V_119 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 5 ] =
V_120 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 4 ] =
V_121 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 3 ] =
V_108 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 2 ] =
V_109 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 1 ] =
V_110 | V_105 ;
V_2 -> V_11 . V_103 . V_82 [ 0 ] =
V_111 | V_105 ;
V_2 -> V_11 . V_106 = V_113 ;
V_2 -> V_11 . V_103 . V_83 = 12 ;
}
}
}
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
static int F_27 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_11 ,
F_3 () , F_4 ( & V_8 ) ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ! F_4 ( & V_8 ) )
F_1 ( V_2 ) ;
V_99 -> V_102 = ( ( V_2 -> V_122 ) & V_123 ) * 500000 ;
if ( V_2 -> V_11 . V_106 == V_107 )
V_99 -> V_101 = 1 ;
else
V_99 -> V_101 = 0 ;
return 0 ;
}
static int F_28 ( struct V_49 * V_50 , struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_124 = V_99 -> V_102 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_99 -> V_125 )
V_124 = 2347 ;
if ( ( V_124 < 0 ) || ( V_124 > 2347 ) )
return - V_70 ;
V_2 -> V_11 . V_126 = V_124 ;
V_2 -> V_72 |= V_22 ;
return - V_74 ;
}
static int F_29 ( struct V_49 * V_50 , struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_99 -> V_102 = V_2 -> V_11 . V_126 ;
V_99 -> V_125 = ( V_99 -> V_102 >= 2347 ) ;
V_99 -> V_101 = 1 ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_127 = V_99 -> V_102 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_99 -> V_125 )
V_127 = 2346 ;
if ( ( V_127 < 256 ) || ( V_127 > 2346 ) )
return - V_70 ;
V_127 &= ~ 0x1 ;
V_2 -> V_11 . V_128 = V_127 ;
V_2 -> V_72 |= V_24 ;
return - V_74 ;
}
static int F_31 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_99 -> V_102 = V_2 -> V_11 . V_128 ;
V_99 -> V_125 = ( V_99 -> V_102 >= 2346 ) ;
V_99 -> V_101 = 1 ;
return 0 ;
}
static int F_32 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_12 , * V_129 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
switch ( * V_129 ) {
case V_130 :
V_2 -> V_11 . V_12 = V_89 ;
V_2 -> V_72 |= V_73 ;
break;
case V_131 :
V_2 -> V_11 . V_12 = V_90 ;
V_2 -> V_72 |= V_73 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
default:
return - V_70 ;
}
return - V_74 ;
}
static int F_33 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
switch ( V_2 -> V_11 . V_12 ) {
case V_90 :
* V_129 = V_131 ;
break;
case V_89 :
* V_129 = V_130 ;
break;
default:
* V_129 = V_130 ;
}
return 0 ;
}
static int F_34 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_137 V_138 ;
int V_139 = ( V_78 -> V_80 & V_140 ) ;
int V_141 = V_2 -> V_11 . V_142 ;
int V_100 ;
F_2 ( 2 , L_13 , V_78 -> V_80 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ( V_139 < 0 ) || ( V_139 > 4 ) )
return - V_70 ;
else if ( V_139 == 0 )
V_139 = V_141 ;
else
V_139 -- ;
if ( V_78 -> V_84 > 0 ) {
if ( V_78 -> V_84 > V_143 ) {
return - V_70 ;
}
if ( V_78 -> V_84 > V_144 ) {
V_138 . V_79 = V_143 ;
V_2 -> V_11 . V_145 = 0x01 ;
V_2 -> V_72 |= V_36 ;
V_146 = V_147 ;
} else {
if ( V_78 -> V_84 > 0 ) {
V_138 . V_79 = V_144 ;
V_2 -> V_11 . V_145 = 0x01 ;
V_2 -> V_72 |= V_36 ;
V_146 = V_148 ;
} else {
V_138 . V_79 = 0 ;
}
}
if ( ! ( V_78 -> V_80 & V_149 ) ) {
memset ( V_138 . V_138 , 0 , V_143 ) ;
if ( F_35
( V_138 . V_138 , V_78 -> V_150 , V_78 -> V_84 ) ) {
V_138 . V_79 = 0 ;
return - V_151 ;
}
V_2 -> V_11 . V_137 [ V_139 ] . V_83 = V_138 . V_79 ;
for ( V_100 = 0 ; V_100 < ( V_2 -> V_11 . V_137 [ V_139 ] . V_83 ) ; V_100 ++ )
V_2 -> V_11 . V_137 [ V_139 ] . V_152 [ V_100 ] = V_138 . V_138 [ V_100 ] ;
V_2 -> V_72 |= ( V_28 << V_139 ) ;
V_2 -> V_11 . V_142 = V_139 ;
V_2 -> V_72 |= V_26 ;
}
} else {
if ( V_78 -> V_80 & V_153 ) {
V_2 -> V_11 . V_137 [ 0 ] . V_83 = 0 ;
V_2 -> V_11 . V_137 [ 1 ] . V_83 = 0 ;
V_2 -> V_11 . V_137 [ 2 ] . V_83 = 0 ;
V_2 -> V_11 . V_137 [ 3 ] . V_83 = 0 ;
V_2 -> V_11 . V_145 = 0x00 ;
if ( V_2 -> V_11 . V_154 == V_155 )
V_2 -> V_72 |= V_73 ;
V_2 -> V_11 . V_154 = V_156 ;
V_146 = V_157 ;
V_2 -> V_72 |= V_36 ;
} else {
if ( ( V_139 >= 0 ) && ( V_139 < 4 ) ) {
if ( V_2 -> V_11 . V_137 [ V_139 ] . V_83 != 0 ) {
V_2 -> V_11 . V_142 = V_139 ;
V_2 -> V_72 |= V_26 ;
} else {
return - V_70 ;
}
}
}
}
if ( V_78 -> V_80 & V_158 )
V_2 -> V_72 |= V_36 ;
if ( V_78 -> V_80 & V_159 ) {
if ( V_2 -> V_11 . V_154 == V_155 )
V_2 -> V_72 |= V_73 ;
V_2 -> V_11 . V_154 = V_156 ;
} else if ( V_78 -> V_80 & V_160 ) {
if ( V_2 -> V_11 . V_154 == V_156 )
V_2 -> V_72 |= V_73 ;
V_2 -> V_11 . V_154 = V_155 ;
}
if ( V_2 -> V_72 ) {
F_11 ( V_2 , V_2 -> V_72 ) ;
V_2 -> V_72 = 0 ;
}
return 0 ;
}
static int F_36 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
char V_161 [ 16 ] ;
int V_139 = ( V_78 -> V_80 & V_140 ) - 1 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_78 -> V_80 = V_153 ;
switch ( V_2 -> V_11 . V_154 ) {
case V_156 :
V_78 -> V_80 = V_159 ;
break;
case V_155 :
V_78 -> V_80 = V_160 ;
break;
}
memset ( V_161 , 0 , sizeof( V_161 ) ) ;
if ( ( V_139 < 0 ) || ( V_139 >= 4 ) )
V_139 = V_2 -> V_11 . V_142 ;
if ( V_2 -> V_11 . V_145 ) {
V_78 -> V_80 &= ~ V_153 ;
}
V_78 -> V_80 |= V_139 + 1 ;
F_2 ( 2 , L_14 , V_78 -> V_80 ) ;
if ( ( V_139 >= 0 ) && ( V_139 < 4 ) )
V_78 -> V_84 = V_2 -> V_11 . V_137 [ V_139 ] . V_83 ;
if ( V_78 -> V_84 > 16 )
V_78 -> V_84 = 0 ;
#if 1
if ( V_78 -> V_84 ) {
if ( ( V_139 >= 0 ) && ( V_139 < 4 ) )
memcpy ( V_54 , V_2 -> V_11 . V_137 [ V_139 ] . V_152 ,
V_78 -> V_84 ) ;
} else {
memcpy ( V_54 , V_161 , V_78 -> V_84 ) ;
}
#endif
return 0 ;
}
static int F_37 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
return - V_68 ;
}
static int F_38 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_99 -> V_102 = 0 ;
V_99 -> V_125 = ( V_99 -> V_102 == 0 ) ;
V_99 -> V_101 = 1 ;
return 0 ;
}
static int F_39 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
return - V_68 ;
}
static int F_40 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_99 -> V_102 = 0 ;
V_99 -> V_125 = ( V_99 -> V_102 == 0 ) ;
V_99 -> V_101 = 1 ;
return 0 ;
}
static int F_41 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_162 * V_163 = (struct V_162 * ) V_54 ;
int V_100 , V_164 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_78 -> V_84 = sizeof( struct V_162 ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_163 -> V_165 = 0x0000 ;
V_163 -> V_166 = 0x0000 ;
V_163 -> V_167 = 14 ;
V_164 = 0 ;
for ( V_100 = 0 ; V_100 < 13 ; V_100 ++ ) {
V_163 -> V_168 [ V_164 ] . V_100 = V_100 + 1 ;
V_163 -> V_168 [ V_164 ] . V_64 = V_67 [ V_100 ] * 100000 ;
V_163 -> V_168 [ V_164 ++ ] . V_63 = 1 ;
}
V_163 -> V_169 = V_164 ;
if ( V_2 -> V_11 . V_57 == V_58 || V_2 -> V_11 . V_57 == V_170 ) {
V_163 -> V_168 [ 13 ] . V_100 = 14 ;
V_163 -> V_168 [ 13 ] . V_64 = V_67 [ 13 ] * 100000 ;
V_163 -> V_168 [ 13 ] . V_63 = 1 ;
V_163 -> V_169 = 14 ;
}
V_163 -> V_171 . V_172 = 100 ;
V_163 -> V_171 . V_173 = 256 - 128 ;
V_163 -> V_171 . V_174 = 256 - 128 ;
V_163 -> V_175 = 1 ;
if ( V_2 -> V_11 . V_57 == V_58 ) {
V_163 -> V_176 [ 0 ] = 1e6 ;
V_163 -> V_176 [ 1 ] = 2e6 ;
V_163 -> V_176 [ 2 ] = 5.5e6 ;
V_163 -> V_176 [ 3 ] = 11e6 ;
V_163 -> V_177 = 4 ;
} else {
V_163 -> V_176 [ 0 ] = 1e6 ;
V_163 -> V_176 [ 1 ] = 2e6 ;
V_163 -> V_176 [ 2 ] = 5.5e6 ;
V_163 -> V_176 [ 3 ] = 11e6 ;
V_163 -> V_176 [ 4 ] = 6e6 ;
V_163 -> V_176 [ 5 ] = 9e6 ;
V_163 -> V_176 [ 6 ] = 12e6 ;
if ( V_178 < 9 ) {
V_163 -> V_176 [ 7 ] = 54e6 ;
V_163 -> V_177 = 8 ;
} else {
V_163 -> V_176 [ 7 ] = 18e6 ;
V_163 -> V_176 [ 8 ] = 24e6 ;
V_163 -> V_176 [ 9 ] = 36e6 ;
V_163 -> V_176 [ 10 ] = 48e6 ;
V_163 -> V_176 [ 11 ] = 54e6 ;
V_163 -> V_177 = 12 ;
}
}
if ( V_100 > 2 )
V_163 -> V_179 = 5000 * 1000 ;
else
V_163 -> V_179 = 1500 * 1000 ;
V_163 -> V_180 = 0 ;
V_163 -> V_181 = 2347 ;
V_163 -> V_182 = 256 ;
V_163 -> V_183 = 2346 ;
V_163 -> V_184 [ 0 ] = 5 ;
V_163 -> V_184 [ 1 ] = 13 ;
V_163 -> V_185 = 2 ;
V_163 -> V_186 = 4 ;
V_163 -> V_187 = V_188 ;
V_163 -> V_189 = V_188 ;
V_163 -> V_190 = 0 ;
V_163 -> V_191 [ 0 ] = - 256 ;
V_163 -> V_192 = 1 ;
V_163 -> V_193 = V_194 ;
V_163 -> V_195 = 21 ;
V_163 -> V_196 = V_197 ;
V_163 -> V_198 = V_199 ;
V_163 -> V_200 = V_199 ;
V_163 -> V_201 = V_199 ;
V_163 -> V_202 . V_172 = 50 ;
V_163 -> V_202 . V_173 = 186 ;
V_163 -> V_202 . V_174 = 0 ;
V_163 -> V_203 [ 0 ] = ( V_204 |
F_42 ( V_205 ) |
F_42 ( V_206 ) ) ;
V_163 -> V_203 [ 1 ] = V_207 ;
V_163 -> V_203 [ 4 ] = ( F_42 ( V_208 ) |
F_42 ( V_209 ) ) ;
V_163 -> V_210 = ( V_211 |
V_212 |
V_213 | V_214 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_99 -> V_125 ) {
V_2 -> V_11 . V_215 = V_216 ;
} else {
if ( V_2 -> V_11 . V_12 == V_90 )
V_2 -> V_11 . V_215 = V_217 ;
else
return - V_70 ;
}
F_5 ( V_2 , V_218 ) ;
return 0 ;
}
static int F_44 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_11 . V_215 > 0 )
V_99 -> V_125 = 0 ;
else
V_99 -> V_125 = 1 ;
return 0 ;
}
static int F_45 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_219 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
V_99 -> V_172 = 0 ;
V_99 -> V_173 = V_2 -> V_4 . V_172 . V_173 ;
V_99 -> V_174 = 0 ;
V_99 -> V_220 = 0 ;
return 0 ;
}
static int F_46 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
return - V_68 ;
}
static int F_47 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_98 * V_99 ,
char * V_54 )
{
V_99 -> V_102 = 0 ;
V_99 -> V_125 = ( V_99 -> V_102 == 0 ) ;
V_99 -> V_101 = 1 ;
return 0 ;
}
static int F_48 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_87 * V_221 = (struct V_87 * ) V_54 ;
struct V_219 V_172 [ V_222 ] ;
int V_100 ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_223 . V_83 ; V_100 ++ ) {
memcpy ( V_221 [ V_100 ] . V_92 , & ( V_2 -> V_223 . V_224 [ V_100 ] . V_91 [ 0 ] ) ,
V_93 ) ;
V_221 [ V_100 ] . V_95 = V_96 ;
V_172 [ V_100 ] . V_173 = 256 - V_2 -> V_223 . V_224 [ V_100 ] . V_225 ;
V_172 [ V_100 ] . V_172 = V_2 -> V_223 . V_224 [ V_100 ] . V_226 ;
V_172 [ V_100 ] . V_174 = 0 ;
V_172 [ V_100 ] . V_220 = 7 ;
}
if ( V_100 ) {
V_78 -> V_80 = 1 ;
memcpy ( V_54 + sizeof( struct V_87 ) * V_100 ,
& V_172 , sizeof( struct V_219 ) * V_100 ) ;
}
V_78 -> V_84 = V_100 ;
return 0 ;
}
static int F_49 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
union V_227 * V_228 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_229 * V_230 = NULL ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_228 -> V_231 . V_84 == sizeof( struct V_229 ) &&
V_228 -> V_231 . V_80 & V_232 ) {
V_230 = (struct V_229 * ) V_54 ;
V_2 -> V_233 = V_230 -> V_234 ;
memcpy ( V_2 -> V_235 , V_230 -> V_236 , V_2 -> V_233 ) ;
} else {
V_2 -> V_233 = 0 ;
}
V_2 -> V_237 . V_238 |= V_239 ;
F_5 ( V_2 , V_240 ) ;
return 0 ;
}
static inline char * F_50 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
char * V_241 , char * V_242 ,
struct V_243 * V_224 )
{
struct V_244 V_245 ;
T_3 V_246 ;
char * V_247 ;
int V_100 ;
static const char V_248 [] = L_15 ;
static const char V_249 [] = L_16 ;
char V_250 [ V_251 * 2 + 30 ] ;
char V_252 [ V_251 * 2 + 30 ] ;
char * V_253 ;
V_245 . V_254 = V_205 ;
V_245 . V_255 . V_88 . V_95 = V_96 ;
memcpy ( V_245 . V_255 . V_88 . V_92 , V_224 -> V_91 , V_93 ) ;
V_241 =
F_51 ( V_52 , V_241 , V_242 , & V_245 ,
V_256 ) ;
V_245 . V_255 . V_231 . V_84 = V_224 -> V_81 . V_83 ;
if ( V_245 . V_255 . V_231 . V_84 > 32 )
V_245 . V_255 . V_231 . V_84 = 32 ;
V_245 . V_254 = V_257 ;
V_245 . V_255 . V_231 . V_80 = 1 ;
V_241 =
F_52 ( V_52 , V_241 , V_242 , & V_245 ,
V_224 -> V_81 . V_82 ) ;
V_245 . V_254 = V_258 ;
V_246 = V_224 -> V_259 ;
if ( V_246 & ( V_260 | V_261 ) ) {
if ( V_246 & V_260 )
V_245 . V_255 . V_262 = V_131 ;
else
V_245 . V_255 . V_262 = V_130 ;
V_241 =
F_51 ( V_52 , V_241 , V_242 , & V_245 ,
V_263 ) ;
}
V_245 . V_254 = V_264 ;
V_245 . V_255 . V_168 . V_64 = V_224 -> V_62 ;
V_245 . V_255 . V_168 . V_64 = V_67 [ V_245 . V_255 . V_168 . V_64 - 1 ] * 100000 ;
V_245 . V_255 . V_168 . V_63 = 1 ;
V_241 =
F_51 ( V_52 , V_241 , V_242 , & V_245 ,
V_265 ) ;
V_245 . V_254 = V_266 ;
V_245 . V_255 . V_172 . V_173 = 256 - V_224 -> V_225 ;
V_245 . V_255 . V_172 . V_172 = V_224 -> V_226 ;
V_245 . V_255 . V_172 . V_174 = 0 ;
V_241 =
F_51 ( V_52 , V_241 , V_242 , & V_245 ,
V_267 ) ;
V_245 . V_254 = V_268 ;
if ( V_246 & V_269 )
V_245 . V_255 . V_231 . V_80 = V_270 | V_149 ;
else
V_245 . V_255 . V_231 . V_80 = V_153 ;
V_245 . V_255 . V_231 . V_84 = 0 ;
V_241 =
F_52 ( V_52 , V_241 , V_242 , & V_245 ,
V_224 -> V_81 . V_82 ) ;
V_247 = V_241 + V_271 ;
V_245 . V_254 = V_272 ;
V_245 . V_255 . V_176 . V_101 = 0 ;
V_245 . V_255 . V_176 . V_125 = 0 ;
for ( V_100 = 0 ; V_100 < 16 ; V_100 ++ ) {
if ( V_100 >= V_224 -> V_103 . V_83 )
break;
V_245 . V_255 . V_176 . V_102 = ( ( V_224 -> V_103 . V_82 [ V_100 ] & 0x7f ) * 500000 ) ;
V_247 =
F_53 ( V_52 , V_241 , V_247 , V_242 ,
& V_245 , V_273 ) ;
}
if ( ( V_247 - V_241 ) > V_271 )
V_241 = V_247 ;
#define F_54 0xdd
#define F_55 0x30
if ( V_224 -> V_274 . V_275 == F_55 && V_224 -> V_274 . V_83 != 0 ) {
V_253 = & V_250 [ 0 ] ;
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_245 . V_254 = V_208 ;
memcpy ( V_250 , V_248 , sizeof( V_248 ) - 1 ) ;
V_245 . V_255 . V_231 . V_84 += sizeof( V_248 ) - 1 ;
V_253 += sizeof( V_248 ) - 1 ;
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_274 . V_275 ) ;
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_274 . V_83 ) ;
V_245 . V_255 . V_231 . V_84 += 4 ;
for ( V_100 = 0 ; V_100 < V_224 -> V_274 . V_83 ; V_100 ++ )
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_274 . V_82 [ V_100 ] ) ;
V_245 . V_255 . V_231 . V_84 += ( V_224 -> V_274 . V_83 ) * 2 ;
F_2 ( 4 , L_18 , V_224 -> V_274 . V_83 ) ;
V_241 =
F_52 ( V_52 , V_241 , V_242 , & V_245 ,
& V_250 [ 0 ] ) ;
}
if ( V_224 -> V_276 . V_275 == F_54 && V_224 -> V_276 . V_83 != 0 ) {
V_253 = & V_252 [ 0 ] ;
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_245 . V_254 = V_208 ;
memcpy ( V_252 , V_249 , sizeof( V_249 ) - 1 ) ;
V_245 . V_255 . V_231 . V_84 += sizeof( V_249 ) - 1 ;
V_253 += sizeof( V_249 ) - 1 ;
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_276 . V_275 ) ;
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_276 . V_83 ) ;
V_245 . V_255 . V_231 . V_84 += 4 ;
for ( V_100 = 0 ; V_100 < V_224 -> V_276 . V_83 ; V_100 ++ )
V_253 += sprintf ( V_253 , L_17 , V_224 -> V_276 . V_82 [ V_100 ] ) ;
V_245 . V_255 . V_231 . V_84 += ( V_224 -> V_276 . V_83 ) * 2 ;
F_2 ( 4 , L_18 , V_224 -> V_276 . V_83 ) ;
F_2 ( 4 , L_19 , V_245 . V_255 . V_231 . V_84 ) ;
V_241 =
F_52 ( V_52 , V_241 , V_242 , & V_245 ,
& V_252 [ 0 ] ) ;
}
return V_241 ;
}
static int F_56 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_77 * V_78 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_100 ;
char * V_241 = V_54 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_2 -> V_237 . V_238 & V_239 ) {
F_2 ( 2 , L_20 ) ;
return - V_277 ;
}
if ( V_2 -> V_223 . V_83 == 0 ) {
F_2 ( 2 , L_21 ) ;
return - V_278 ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_223 . V_83 ; V_100 ++ ) {
if ( ( V_54 + V_78 -> V_84 ) - V_241 <= V_256 ) {
V_78 -> V_84 = 0 ;
return - V_86 ;
}
V_241 = F_50 ( V_50 , V_52 , V_241 ,
V_54 + V_78 -> V_84 ,
& V_2 -> V_223 . V_224 [ V_100 ] ) ;
}
V_78 -> V_84 = ( V_241 - V_54 ) ;
V_78 -> V_80 = 0 ;
return 0 ;
}
static int F_57 ( struct V_49 * V_50 ,
struct V_51 * V_52 , void * V_279 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( ! V_2 -> V_72 )
return 0 ;
F_11 ( V_2 , V_2 -> V_72 ) ;
V_2 -> V_72 = 0 ;
return 0 ;
}
static int F_58 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
return 0 ;
}
static int F_59 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_139 = ( V_99 -> V_80 & V_280 ) ;
int V_102 = V_99 -> V_102 ;
F_2 ( 2 , L_22 , V_139 , V_102 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
switch ( V_139 ) {
case V_281 :
switch ( V_102 ) {
case V_282 :
V_2 -> V_283 . V_284 = V_102 ;
if ( V_2 -> V_283 . V_285 )
V_2 -> V_283 . V_285 = 0 ;
V_2 -> V_72 |= V_38 ;
break;
case V_286 :
case V_287 :
V_2 -> V_283 . V_284 = V_102 ;
if ( ! ( V_2 -> V_283 . V_285 ) )
V_2 -> V_283 . V_285 = 1 ;
V_2 -> V_72 |= V_38 ;
break;
default:
return - V_68 ;
}
break;
case V_288 :
switch ( V_102 ) {
case V_289 :
if ( V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x00 ;
V_2 -> V_72 |= V_36 ;
}
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
if ( ! V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x01 ;
V_2 -> V_72 |= V_36 ;
}
V_2 -> V_283 . V_294 = V_102 ;
V_2 -> V_72 |= V_43 ;
break;
default:
return - V_68 ;
}
break;
case V_295 :
switch ( V_102 ) {
case V_289 :
if ( V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x00 ;
V_2 -> V_72 |= V_36 ;
}
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
if ( ! V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x01 ;
V_2 -> V_72 |= V_36 ;
}
V_2 -> V_283 . V_296 = V_102 ;
V_2 -> V_72 |= V_41 ;
break;
default:
return - V_68 ;
}
break;
case V_297 :
switch ( V_102 ) {
case V_298 :
case V_299 :
case 0 :
case 4 :
V_2 -> V_283 . V_300 = V_102 ;
V_2 -> V_72 |= V_45 ;
break;
default:
return - V_68 ;
}
break;
case V_301 :
switch ( V_102 ) {
case V_302 :
V_2 -> V_283 . V_303 = V_102 ;
V_2 -> V_11 . V_154 = V_156 ;
break;
case V_304 :
V_2 -> V_283 . V_303 = V_102 ;
V_2 -> V_11 . V_154 = V_155 ;
break;
case V_305 :
default:
return - V_68 ;
}
V_2 -> V_72 |= V_73 ;
break;
case V_306 :
V_2 -> V_283 . V_307 = V_102 ;
break;
case V_308 :
if ( ( V_102 && ! V_2 -> V_11 . V_145 ) ||
( ! V_102 && V_2 -> V_11 . V_145 ) ) {
V_2 -> V_11 . V_145 = V_102 ? 0x01 : 0x00 ;
V_2 -> V_72 |= V_36 ;
}
break;
case V_309 :
case V_310 :
case V_311 :
case V_312 :
default:
break;
}
if ( V_2 -> V_72 ) {
F_11 ( V_2 , V_2 -> V_72 ) ;
V_2 -> V_72 = 0 ;
}
return 0 ;
}
static int F_60 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_98 * V_99 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_139 = ( V_99 -> V_80 & V_280 ) ;
F_2 ( 2 , L_23 , V_139 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
switch ( V_139 ) {
case V_281 :
V_99 -> V_102 = V_2 -> V_283 . V_284 ;
break;
case V_288 :
V_99 -> V_102 = V_2 -> V_283 . V_294 ;
break;
case V_295 :
V_99 -> V_102 = V_2 -> V_283 . V_296 ;
break;
case V_297 :
V_99 -> V_102 = V_2 -> V_283 . V_300 ;
break;
case V_301 :
V_99 -> V_102 = V_2 -> V_283 . V_303 ;
break;
case V_306 :
V_99 -> V_102 = V_2 -> V_283 . V_285 ;
break;
case V_309 :
case V_310 :
case V_311 :
default:
break;
}
return 0 ;
}
static int F_61 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_313 * V_314 ;
int V_139 = V_78 -> V_80 & V_140 ;
unsigned int V_315 = 0 ;
struct V_316 * V_138 ;
V_314 = (struct V_313 * ) V_54 ;
if ( ! V_314 )
return - V_70 ;
F_2 ( 2 , L_24 , V_78 -> V_80 ,
V_314 -> V_317 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( V_139 < 1 || V_139 > 4 )
return - V_70 ;
V_139 -- ;
V_138 = & V_2 -> V_283 . V_138 [ V_139 ] ;
if ( V_78 -> V_80 & V_153 )
V_138 -> V_318 = 0 ;
V_138 -> V_317 = V_314 -> V_317 ;
if ( V_314 -> V_317 & V_319 ) {
V_2 -> V_283 . V_320 = V_139 ;
V_315 |= V_26 ;
} else if ( V_314 -> V_317 & V_321 ) {
memcpy ( & V_138 -> V_322 [ 0 ] , & V_314 -> V_322 [ 0 ] , V_323 ) ;
}
memcpy ( & V_138 -> V_324 . V_92 [ 0 ] , & V_314 -> V_324 . V_92 [ 0 ] , V_93 ) ;
switch ( V_314 -> V_325 ) {
case V_326 :
if ( V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x00 ;
V_315 |= V_36 ;
}
V_138 -> V_318 = 0 ;
break;
case V_327 :
case V_328 :
if ( ! V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x01 ;
V_315 |= V_36 ;
}
if ( V_314 -> V_318 ) {
memcpy ( & V_138 -> V_329 [ 0 ] , & V_314 -> V_138 [ 0 ] , V_314 -> V_318 ) ;
V_138 -> V_318 = V_314 -> V_318 ;
V_315 |= ( V_28 << V_139 ) ;
}
break;
case V_330 :
if ( ! V_2 -> V_11 . V_145 ) {
V_2 -> V_11 . V_145 = 0x01 ;
V_315 |= V_36 ;
}
if ( V_314 -> V_318 == 32 ) {
memcpy ( & V_138 -> V_329 [ 0 ] , & V_314 -> V_138 [ 0 ] , V_314 -> V_318 - 16 ) ;
V_138 -> V_318 = V_314 -> V_318 - 16 ;
if ( V_2 -> V_283 . V_300 == 4 ) {
memcpy ( & V_138 -> V_331 [ 0 ] , & V_314 -> V_138 [ 16 ] , 8 ) ;
memcpy ( & V_138 -> V_332 [ 0 ] , & V_314 -> V_138 [ 16 ] , 8 ) ;
} else {
memcpy ( & V_138 -> V_331 [ 0 ] , & V_314 -> V_138 [ 16 ] , 8 ) ;
memcpy ( & V_138 -> V_332 [ 0 ] , & V_314 -> V_138 [ 24 ] , 8 ) ;
}
V_315 |= ( V_28 << V_139 ) ;
}
break;
default:
return - V_70 ;
}
V_138 -> V_325 = V_314 -> V_325 ;
if ( V_315 ) {
if ( V_315 & V_26 )
F_5 ( V_2 , V_333 ) ;
if ( V_315 & V_334 )
F_5 ( V_2 , V_335 + V_139 ) ;
if ( V_315 & V_36 )
F_5 ( V_2 , V_37 ) ;
}
return 0 ;
}
static int F_62 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
return 0 ;
}
static int F_63 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_336 * V_337 ;
int V_100 ;
struct V_338 * V_339 ;
struct V_340 * V_19 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ! V_54 )
return - V_70 ;
V_337 = (struct V_336 * ) V_54 ;
F_2 ( 2 , L_25 , V_337 -> V_254 ) ;
switch ( V_337 -> V_254 ) {
case V_341 :
if ( F_64 ( & V_2 -> V_342 . V_343 ) ) {
for ( V_100 = 0 ; V_100 < V_344 ; V_100 ++ ) {
V_339 = & V_2 -> V_342 . V_339 [ V_100 ] ;
if ( memcmp ( L_26 ,
V_339 -> V_91 , V_93 ) == 0 )
break;
}
memcpy ( V_339 -> V_91 , V_337 -> V_91 . V_92 , V_93 ) ;
memcpy ( V_339 -> V_345 , V_337 -> V_345 , V_346 ) ;
F_65 ( & V_339 -> V_347 , & V_2 -> V_342 . V_343 ) ;
V_2 -> V_342 . V_83 ++ ;
break;
}
F_66 (ptr, &priv->pmklist.head) {
V_339 = F_67 ( V_19 , struct V_338 , V_347 ) ;
if ( memcmp ( V_337 -> V_91 . V_92 , V_339 -> V_91 , V_93 ) == 0 ) {
memcpy ( V_339 -> V_345 , V_337 -> V_345 , V_346 ) ;
F_68 ( & V_339 -> V_347 , & V_2 -> V_342 . V_343 ) ;
break;
}
}
if ( V_19 != & V_2 -> V_342 . V_343 )
break;
if ( V_2 -> V_342 . V_83 < V_344 ) {
for ( V_100 = 0 ; V_100 < V_344 ; V_100 ++ ) {
V_339 = & V_2 -> V_342 . V_339 [ V_100 ] ;
if ( memcmp ( L_26 ,
V_339 -> V_91 , V_93 ) == 0 )
break;
}
memcpy ( V_339 -> V_91 , V_337 -> V_91 . V_92 , V_93 ) ;
memcpy ( V_339 -> V_345 , V_337 -> V_345 , V_346 ) ;
F_65 ( & V_339 -> V_347 , & V_2 -> V_342 . V_343 ) ;
V_2 -> V_342 . V_83 ++ ;
} else {
V_339 = F_67 ( V_2 -> V_342 . V_343 . V_348 , struct V_338 ,
V_347 ) ;
memcpy ( V_339 -> V_91 , V_337 -> V_91 . V_92 , V_93 ) ;
memcpy ( V_339 -> V_345 , V_337 -> V_345 , V_346 ) ;
F_68 ( & V_339 -> V_347 , & V_2 -> V_342 . V_343 ) ;
}
break;
case V_349 :
if ( F_64 ( & V_2 -> V_342 . V_343 ) ) {
return - V_70 ;
}
F_66 (ptr, &priv->pmklist.head) {
V_339 = F_67 ( V_19 , struct V_338 , V_347 ) ;
if ( memcmp ( V_337 -> V_91 . V_92 , V_339 -> V_91 , V_93 ) == 0 ) {
F_22 ( V_339 -> V_91 ) ;
memset ( V_339 -> V_345 , 0 , V_346 ) ;
F_69 ( & V_339 -> V_347 ) ;
break;
}
}
if ( V_19 == & V_2 -> V_342 . V_343 ) {
return 0 ;
}
break;
case V_350 :
memset ( & V_2 -> V_342 , 0 , sizeof( V_2 -> V_342 ) ) ;
F_70 ( & V_2 -> V_342 . V_343 ) ;
for ( V_100 = 0 ; V_100 < V_344 ; V_100 ++ )
F_70 ( & V_2 -> V_342 . V_339 [ V_100 ] . V_347 ) ;
break;
default:
return - V_70 ;
}
F_5 ( V_2 , V_351 ) ;
return 0 ;
}
static struct V_3 * F_71 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ! F_4 ( & V_8 ) ) {
if ( V_2 -> V_5 < V_6 )
return NULL ;
else
return V_4 ;
}
V_4 -> V_352 . V_353 = 0 ;
V_4 -> V_352 . V_354 = 0 ;
V_4 -> V_352 . V_128 = 0 ;
V_4 -> V_352 . V_355 = 0 ;
V_4 -> V_352 . V_356 = 0 ;
V_4 -> V_357 . V_358 = 0 ;
return V_4 ;
}
static int F_72 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( ! ( * V_129 ) )
return - V_70 ;
F_5 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_73 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_77 * V_78 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_359 * V_360 = (struct V_359 * ) V_54 ;
T_2 V_262 ;
F_2 ( 2 , L_27 , V_360 -> V_254 , V_360 -> V_361 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
switch ( V_360 -> V_254 ) {
case V_362 :
if ( V_360 -> V_361 == V_363 )
return 0 ;
case V_364 :
V_262 = 1 ;
return F_72 ( V_50 , NULL , & V_262 , NULL ) ;
default:
return - V_68 ;
}
}
static int F_74 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
strcpy ( V_54 , V_2 -> V_365 ) ;
V_78 -> V_84 = V_2 -> V_366 + 1 ;
return 0 ;
}
static int F_75 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == V_367 ) {
V_2 -> V_11 . V_368 = V_367 ;
} else if ( * V_129 == V_369 ) {
V_2 -> V_11 . V_368 = V_369 ;
} else {
return - V_70 ;
}
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
static int F_76 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_368 ;
return 0 ;
}
static int F_77 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == V_216 ) {
V_2 -> V_11 . V_215 = V_216 ;
} else if ( * V_129 == V_217 ) {
if ( V_2 -> V_11 . V_12 == V_90 )
V_2 -> V_11 . V_215 = V_217 ;
else
return - V_70 ;
} else if ( * V_129 == V_370 ) {
if ( V_2 -> V_11 . V_12 == V_90 )
V_2 -> V_11 . V_215 = V_370 ;
else
return - V_70 ;
} else {
return - V_70 ;
}
F_5 ( V_2 , V_218 ) ;
return 0 ;
}
static int F_78 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_215 ;
return 0 ;
}
static int F_79 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == V_371 ) {
V_2 -> V_11 . V_372 = V_371 ;
} else if ( * V_129 == V_373 ) {
V_2 -> V_11 . V_372 = V_373 ;
} else {
return - V_70 ;
}
return 0 ;
}
static int F_80 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_372 ;
return 0 ;
}
static int F_81 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 >= V_374 && * V_129 <= V_375 )
V_2 -> V_11 . V_376 = * V_129 ;
else
return - V_70 ;
if ( V_2 -> V_11 . V_12 == V_90 ) {
V_2 -> V_72 |= V_73 ;
return - V_74 ;
} else {
return 0 ;
}
}
static int F_82 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_376 ;
return 0 ;
}
static int F_83 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == V_58 ) {
V_2 -> V_11 . V_57 = V_58 ;
} else if ( * V_129 == V_59 ) {
V_2 -> V_11 . V_57 = V_59 ;
} else if ( * V_129 == V_170 ) {
V_2 -> V_11 . V_57 = V_170 ;
} else {
return - V_70 ;
}
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
static int F_84 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_57 ;
return 0 ;
}
static int F_85 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == V_377 ) {
V_2 -> V_11 . V_378 = V_377 ;
} else if ( * V_129 == V_379 ) {
if ( V_2 -> V_11 . V_57 == V_59 ||
V_2 -> V_11 . V_57 == V_170 ) {
V_2 -> V_11 . V_378 = V_379 ;
} else {
V_2 -> V_11 . V_378 = V_377 ;
}
} else {
return - V_70 ;
}
V_2 -> V_72 |= V_73 ;
return - V_74 ;
}
static int F_86 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_11 . V_378 ;
return 0 ;
}
static int F_87 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
T_2 * V_129 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( * V_129 == V_56 ) {
V_2 -> V_55 = * V_129 ;
F_88 ( V_50 , L_28 , V_2 -> V_55 ) ;
F_5 ( V_2 , V_21 ) ;
F_5 ( V_2 , V_380 ) ;
} else if ( * V_129 == V_381 ) {
V_2 -> V_55 = * V_129 ;
F_88 ( V_50 , L_28 , V_2 -> V_55 ) ;
F_5 ( V_2 , V_380 ) ;
} else {
F_89 ( V_50 , L_29 , * V_129 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_90 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
T_2 * V_129 , char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_30 , V_2 -> V_55 ) ;
* V_129 = V_2 -> V_55 ;
return 0 ;
}
static int F_91 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 == 0 || * V_129 == 1 )
V_2 -> V_382 . V_383 = * V_129 ;
else
return - V_70 ;
F_5 ( V_2 , V_384 ) ;
return 0 ;
}
static int F_92 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_382 . V_383 ;
F_88 ( V_50 , L_31 , * V_129 ) ;
return 0 ;
}
static int F_93 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_77 * V_78 , char * V_54 )
{
V_71 * V_385 = V_54 ;
unsigned char V_79 ;
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
F_2 ( 2 , L_32 , V_78 -> V_84 ) ;
if ( V_385 [ 1 ] + 2 != V_78 -> V_84 || V_78 -> V_84 > 256 )
return - V_70 ;
V_2 -> V_382 . V_386 = V_385 [ 1 ] + 2 + 1 ;
V_79 = V_385 [ 1 ] + 2 ;
memcpy ( V_2 -> V_382 . V_387 , & V_79 , sizeof( V_79 ) ) ;
V_385 = memcpy ( V_2 -> V_382 . V_387 + 1 , V_385 , V_79 ) ;
F_2 ( 2 , L_33 ,
V_2 -> V_382 . V_386 , V_2 -> V_382 . V_386 , V_385 [ 0 ] , V_385 [ 1 ] , V_385 [ 2 ] , V_385 [ 3 ] ,
V_385 [ V_2 -> V_382 . V_386 - 3 ] , V_385 [ V_2 -> V_382 . V_386 - 2 ] ,
V_385 [ V_2 -> V_382 . V_386 - 1 ] ) ;
F_5 ( V_2 , V_388 ) ;
return 0 ;
}
static int F_94 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 >= 0 && * V_129 <= 0xFF )
V_2 -> V_389 . V_390 = ( V_104 ) * V_129 ;
else
return - V_70 ;
if ( V_2 -> V_389 . V_390 < 0xFF )
V_2 -> V_389 . V_391 = 1 ;
else
V_2 -> V_389 . V_391 = 0 ;
F_5 ( V_2 , V_392 ) ;
return 0 ;
}
static int F_95 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_389 . V_390 ;
F_5 ( V_2 , V_393 ) ;
return 0 ;
}
static int F_96 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
if ( * V_129 >= 0 && * V_129 <= 0xFF )
V_2 -> V_389 . V_394 = ( V_104 ) * V_129 ;
else
return - V_70 ;
if ( V_2 -> V_389 . V_394 < 0xFF )
V_2 -> V_389 . V_395 = 1 ;
else
V_2 -> V_389 . V_395 = 0 ;
F_5 ( V_2 , V_392 ) ;
return 0 ;
}
static int F_97 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_55 == V_56 )
return - V_9 ;
* V_129 = V_2 -> V_389 . V_394 ;
F_5 ( V_2 , V_393 ) ;
return 0 ;
}
static int F_98 ( struct V_49 * V_50 ,
struct V_51 * V_52 , T_2 * V_129 ,
char * V_54 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
* V_129 = V_2 -> V_396 ;
return 0 ;
}
static void F_99 ( struct V_49 * V_50 , int V_397 )
{
switch ( V_397 ) {
case V_398 :
F_88 ( V_50 , L_34 ) ;
break;
case V_399 :
F_88 ( V_50 , L_35 ) ;
break;
case V_400 :
F_88 ( V_50 , L_36 ) ;
break;
case V_401 :
F_88 ( V_50 , L_37 ) ;
break;
case V_402 :
F_88 ( V_50 , L_38 ) ;
break;
case V_403 :
F_88 ( V_50 , L_39 ) ;
break;
case V_404 :
F_88 ( V_50 , L_40 ) ;
break;
case V_405 :
F_88 ( V_50 , L_41 ) ;
break;
case V_406 :
F_88 ( V_50 , L_42 ) ;
break;
case V_407 :
F_88 ( V_50 , L_43 ) ;
break;
case V_408 :
F_88 ( V_50 , L_44 ) ;
break;
case V_409 :
F_88 ( V_50 , L_45 ) ;
break;
case V_410 :
F_88 ( V_50 , L_46 ) ;
break;
case V_411 :
F_88 ( V_50 , L_47 ) ;
break;
case V_412 :
F_88 ( V_50 , L_48 ) ;
break;
case V_413 :
F_88 ( V_50 , L_49 ) ;
break;
case V_414 :
F_88 ( V_50 , L_50 ) ;
break;
case V_415 :
F_88 ( V_50 , L_51 ) ;
break;
case V_416 :
F_88 ( V_50 , L_52 ) ;
break;
case V_417 :
F_88 ( V_50 , L_53 ) ;
break;
case V_418 :
F_88 ( V_50 , L_54 ) ;
break;
case V_419 :
F_88 ( V_50 , L_55 ) ;
break;
case V_420 :
F_88 ( V_50 , L_56 ) ;
break;
case V_421 :
F_88 ( V_50 , L_57 ) ;
break;
case V_422 :
F_88 ( V_50 , L_58 ) ;
break;
case V_423 :
F_88 ( V_50 , L_59 ) ;
break;
case V_424 :
F_88 ( V_50 , L_60 ) ;
break;
case V_425 :
F_88 ( V_50 , L_61 ) ;
break;
case V_426 :
F_88 ( V_50 , L_62 ) ;
break;
case V_427 :
F_88 ( V_50 , L_63 ) ;
break;
case V_428 :
F_88 ( V_50 , L_64 ) ;
break;
case V_429 :
F_88 ( V_50 , L_65 ) ;
break;
case V_430 :
F_88 ( V_50 , L_66 ) ;
break;
case V_431 :
F_88 ( V_50 , L_67 ) ;
break;
case V_432 :
F_88 ( V_50 , L_68 ) ;
break;
case V_433 :
F_88 ( V_50 , L_69 ) ;
}
}
static int F_100 ( struct V_49 * V_50 , struct V_51 * V_52 ,
T_2 * V_129 , char * V_54 )
{
int V_100 , V_397 ;
struct V_1 * V_2 = F_13 ( V_50 ) ;
for ( V_100 = 63 ; V_100 >= 0 ; V_100 -- ) {
V_397 =
V_2 -> V_434 . V_435 [ ( V_2 -> V_434 . V_436 - 1 - V_100 ) %
V_437 ] ;
F_99 ( V_50 , V_397 ) ;
}
return 0 ;
}
static int F_101 ( struct V_49 * V_50 , struct V_438 * V_439 ,
int V_254 )
{
int V_440 ;
struct V_441 * V_442 = (struct V_441 * ) V_439 ;
switch ( V_254 ) {
case V_443 + 20 :
V_440 = F_72 ( V_50 , NULL , & V_442 -> V_255 . V_262 , NULL ) ;
break;
default:
V_440 = - V_68 ;
}
F_2 ( 5 , L_31 , V_440 ) ;
return V_440 ;
}
static
struct V_444 * F_102 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
if ( V_2 -> V_5 < V_6 )
return NULL ;
return & V_2 -> V_445 ;
}
static
int F_103 ( struct V_49 * V_50 , void * V_324 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_87 * V_446 = (struct V_87 * ) V_324 ;
if ( F_104 ( V_50 ) )
return - V_7 ;
memcpy ( V_50 -> V_447 , V_446 -> V_92 , V_50 -> V_448 ) ;
memcpy ( V_2 -> V_449 , V_446 -> V_92 , V_93 ) ;
V_2 -> V_450 = 0 ;
F_5 ( V_2 , V_451 ) ;
F_88 ( V_50 , L_70 , V_2 -> V_449 ) ;
return 0 ;
}
static
void F_105 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 1 , L_71 , V_2 -> V_452 . V_453 ,
V_2 -> V_452 . V_436 ) ;
if ( ! F_106 ( V_50 ) )
F_107 ( V_50 ) ;
V_2 -> V_445 . V_454 ++ ;
F_108 ( V_50 ) ;
}
static
int F_109 ( struct V_455 * V_456 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
int V_440 ;
F_2 ( 3 , L_72 , F_3 () ) ;
if ( ! V_456 ) {
F_89 ( V_50 , L_73 ) ;
return 0 ;
}
if ( V_2 -> V_5 < V_6 ) {
F_110 ( V_456 ) ;
return 0 ;
}
if ( F_104 ( V_50 ) )
F_107 ( V_50 ) ;
V_440 = F_111 ( V_2 , V_456 ) ;
F_112 ( V_50 ) ;
if ( V_440 )
F_2 ( 4 , L_74 , V_440 ) ;
return 0 ;
}
void F_113 ( struct V_1 * V_2 , struct V_455 * V_456 )
{
F_2 ( 3 , L_3 ) ;
V_2 -> V_445 . V_457 ++ ;
if ( F_106 ( V_2 -> V_458 ) )
F_108 ( V_2 -> V_458 ) ;
if ( V_456 ) {
V_2 -> V_445 . V_459 += V_456 -> V_79 ;
F_110 ( V_456 ) ;
}
}
static
void F_114 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
F_2 ( 4 , L_3 ) ;
if ( V_2 -> V_5 < V_6 )
return;
F_5 ( V_2 , V_460 ) ;
}
static
int F_115 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
V_2 -> V_461 = 0 ;
if ( ! V_2 -> V_450 ) {
F_89 ( V_50 , L_75 , V_50 -> V_69 ) ;
return - V_7 ;
}
F_116 ( V_50 ) ;
return 0 ;
}
static
int F_117 ( struct V_49 * V_50 )
{
F_107 ( V_50 ) ;
F_2 ( 4 , L_76 ,
V_50 -> V_69 , 0x00 ) ;
return 0 ;
}
int F_118 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_50 ) ;
V_2 -> V_450 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_462 = 1 ;
F_10 ( & V_8 , 0 ) ;
F_119 ( & V_16 , F_9 ,
( unsigned long ) V_2 ) ;
memcpy ( V_2 -> V_449 , V_463 , V_93 ) ;
V_50 -> V_447 [ 0 ] = V_2 -> V_449 [ 0 ] ;
V_50 -> V_447 [ 1 ] = V_2 -> V_449 [ 1 ] ;
V_50 -> V_447 [ 2 ] = V_2 -> V_449 [ 2 ] ;
V_50 -> V_447 [ 3 ] = V_2 -> V_449 [ 3 ] ;
V_50 -> V_447 [ 4 ] = V_2 -> V_449 [ 4 ] ;
V_50 -> V_447 [ 5 ] = V_2 -> V_449 [ 5 ] ;
V_50 -> V_447 [ 6 ] = 0x00 ;
V_50 -> V_447 [ 7 ] = 0x00 ;
V_50 -> V_464 = & V_465 ;
V_50 -> V_466 = (struct V_467 * ) & V_468 ;
V_50 -> V_469 = V_470 ;
F_120 ( V_50 ) ;
return 0 ;
}
int F_121 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
V_2 -> V_462 = 0 ;
F_122 ( & V_16 ) ;
if ( F_104 ( V_50 ) )
F_107 ( V_50 ) ;
return 0 ;
}
bool F_17 ( T_4 V_10 )
{
return ( V_10 & V_471 ) == V_472 ;
}
bool F_123 ( T_4 V_10 )
{
return ( V_10 & V_471 ) == V_473 ;
}
