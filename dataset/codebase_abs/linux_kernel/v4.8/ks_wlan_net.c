static
int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( 4 , L_1 , F_3 () ) ;
if ( V_2 -> V_5 < V_6 ) {
return - 1 ;
}
if ( F_4 ( & V_7 ) )
return 1 ;
V_4 -> V_8 = V_2 -> V_9 . V_10 ;
F_5 ( V_2 , V_11 ) ;
if ( ! F_6
( & V_2 -> V_12 , V_13 / 2 ) ) {
F_2 ( 1 , L_2 ) ;
}
F_7 ( & V_7 ) ;
V_14 . V_15 = V_16 + V_13 ;
F_8 ( & V_14 ) ;
return 0 ;
}
static
void F_9 ( unsigned long V_17 )
{
F_2 ( 4 , L_1 , F_3 () ) ;
F_10 ( & V_7 , 0 ) ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
F_2 ( 2 , L_3 ) ;
F_5 ( V_2 , V_19 ) ;
if ( V_18 & V_20 )
F_5 ( V_2 , V_21 ) ;
if ( V_18 & V_22 )
F_5 ( V_2 , V_23 ) ;
if ( V_18 & V_24 )
F_5 ( V_2 , V_25 ) ;
if ( V_18 & V_26 )
F_5 ( V_2 , V_27 ) ;
if ( V_18 & V_28 )
F_5 ( V_2 , V_29 ) ;
if ( V_18 & V_30 )
F_5 ( V_2 , V_31 ) ;
if ( V_18 & V_32 )
F_5 ( V_2 , V_33 ) ;
if ( V_18 & V_34 )
F_5 ( V_2 , V_35 ) ;
if ( V_18 & V_36 ) {
F_5 ( V_2 , V_37 ) ;
F_5 ( V_2 , V_38 ) ;
}
if ( V_18 & V_39 )
F_5 ( V_2 , V_40 ) ;
if ( V_18 & V_41 )
F_5 ( V_2 , V_42 ) ;
if ( V_18 & V_43 )
F_5 ( V_2 , V_44 ) ;
F_5 ( V_2 , V_45 ) ;
F_5 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_12 ( struct V_47 * V_48 ,
struct V_49 * V_50 , char * V_51 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_5 < V_6 ) {
strcpy ( V_51 , L_4 ) ;
} else if ( V_2 -> V_9 . V_56 == V_57 ) {
strcpy ( V_51 , L_5 ) ;
} else if ( V_2 -> V_9 . V_56 == V_58 ) {
strcpy ( V_51 , L_6 ) ;
} else {
strcpy ( V_51 , L_7 ) ;
}
return 0 ;
}
static int F_14 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_59 * V_60 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_61 = - V_62 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_60 -> V_63 == 1 ) &&
( V_60 -> V_64 >= ( int ) 2.412e8 ) && ( V_60 -> V_64 <= ( int ) 2.487e8 ) ) {
int V_65 = V_60 -> V_64 / 100000 ;
int V_66 = 0 ;
while ( ( V_66 < 14 ) && ( V_65 != V_67 [ V_66 ] ) )
V_66 ++ ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = V_66 + 1 ;
}
if ( ( V_60 -> V_64 > 1000 ) || ( V_60 -> V_63 > 0 ) )
V_61 = - V_68 ;
else {
int V_69 = V_60 -> V_64 ;
if ( ( V_69 < 1 ) || ( V_69 > 14 ) ) {
F_15 ( V_70
L_8 ,
V_48 -> V_71 , V_60 -> V_64 ) ;
V_61 = - V_72 ;
} else {
V_2 -> V_9 . V_69 = ( V_73 ) ( V_69 ) ;
V_2 -> V_74 |= V_75 ;
}
}
return V_61 ;
}
static int F_16 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_59 * V_60 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_65 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_2 -> V_76 & V_77 ) == V_78 ) {
V_65 = ( int ) V_2 -> V_79 . V_69 ;
} else
V_65 = ( int ) V_2 -> V_9 . V_69 ;
V_60 -> V_64 = V_67 [ V_65 - 1 ] * 100000 ;
V_60 -> V_63 = 1 ;
return 0 ;
}
static int F_17 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
T_1 V_82 ;
F_2 ( 2 , L_9 , V_81 -> V_83 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_81 -> V_83 == 0 ) {
memset ( V_2 -> V_9 . V_84 . V_85 , 0 , sizeof( V_2 -> V_9 . V_84 . V_85 ) ) ;
V_2 -> V_9 . V_84 . V_86 = 0 ;
} else {
#if 1
V_82 = V_81 -> V_87 ;
if ( V_82 > 0 && V_52 [ V_82 - 1 ] == '\0' )
V_82 -- ;
if ( V_82 > V_88 ) {
return - V_72 ;
}
#else
if ( V_81 -> V_87 > V_88 + 1 ) {
return - V_89 ;
}
#endif
memset ( V_2 -> V_9 . V_84 . V_85 , 0 , sizeof( V_2 -> V_9 . V_84 . V_85 ) ) ;
#if 1
memcpy ( V_2 -> V_9 . V_84 . V_85 , V_52 , V_82 ) ;
V_2 -> V_9 . V_84 . V_86 = V_82 ;
#else
memcpy ( V_2 -> V_9 . V_84 . V_85 , V_52 , V_81 -> V_87 ) ;
V_2 -> V_9 . V_84 . V_86 = V_81 -> V_87 ;
#endif
}
V_2 -> V_74 |= V_75 ;
F_11 ( V_2 , V_2 -> V_74 ) ;
V_2 -> V_74 = 0 ;
return 0 ;
}
static int F_18 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_84 . V_86 ) {
memcpy ( V_52 , V_2 -> V_9 . V_84 . V_85 , V_2 -> V_9 . V_84 . V_86 ) ;
#if 0
extra[priv->reg.ssid.size] = '\0';
#endif
#if 1
V_81 -> V_87 = V_2 -> V_9 . V_84 . V_86 ;
#else
V_81 -> V_87 = V_2 -> V_9 . V_84 . V_86 + 1 ;
#endif
V_81 -> V_83 = 1 ;
} else {
#if 1
V_81 -> V_87 = 0 ;
#else
V_52 [ 0 ] = '\0' ;
V_81 -> V_87 = 1 ;
#endif
V_81 -> V_83 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_90 * V_91 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_10 == V_92 ||
V_2 -> V_9 . V_10 == V_93 ) {
memcpy ( V_2 -> V_9 . V_94 , ( V_73 * ) & V_91 -> V_95 , V_96 ) ;
if ( F_20 ( ( V_73 * ) V_2 -> V_9 . V_94 ) ) {
V_2 -> V_74 |= V_75 ;
}
} else {
memset ( V_2 -> V_9 . V_94 , 0x0 , V_96 ) ;
return - V_68 ;
}
F_2 ( 2 , L_10 ,
V_2 -> V_9 . V_94 [ 0 ] , V_2 -> V_9 . V_94 [ 1 ] , V_2 -> V_9 . V_94 [ 2 ] ,
V_2 -> V_9 . V_94 [ 3 ] , V_2 -> V_9 . V_94 [ 4 ] , V_2 -> V_9 . V_94 [ 5 ] ) ;
if ( V_2 -> V_74 ) {
V_2 -> V_74 |= V_75 ;
return - V_62 ;
}
return 0 ;
}
static int F_21 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_90 * V_97 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_2 -> V_76 & V_77 ) == V_78 ) {
memcpy ( V_97 -> V_95 , & ( V_2 -> V_79 . V_94 [ 0 ] ) , V_96 ) ;
} else {
memset ( V_97 -> V_95 , 0 , V_96 ) ;
}
V_97 -> V_98 = V_99 ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_80 * V_81 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_81 -> V_87 > 16 + 1 ) {
return - V_89 ;
}
memset ( V_2 -> V_100 , 0 , sizeof( V_2 -> V_100 ) ) ;
memcpy ( V_2 -> V_100 , V_52 , V_81 -> V_87 ) ;
return - V_62 ;
}
static int F_23 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_80 * V_81 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
strncpy ( V_52 , V_2 -> V_100 , 16 ) ;
V_52 [ 16 ] = '\0' ;
V_81 -> V_87 = strlen ( V_52 ) + 1 ;
return 0 ;
}
static int F_24 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_103 = 0 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_56 == V_57 ) {
if ( V_102 -> V_104 == 1 ) {
switch ( V_102 -> V_105 ) {
case 11000000 :
case 5500000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
( V_107 ) ( V_102 -> V_105 / 500000 ) ;
break;
case 2000000 :
case 1000000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
( ( V_107 ) ( V_102 -> V_105 / 500000 ) ) |
V_108 ;
break;
default:
return - V_72 ;
}
V_2 -> V_9 . V_109 = V_110 ;
V_2 -> V_9 . V_106 . V_86 = 1 ;
} else {
if ( V_102 -> V_105 > 0 ) {
switch ( V_102 -> V_105 ) {
case 11000000 :
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 ;
V_103 ++ ;
case 5500000 :
V_2 -> V_9 . V_106 . V_85 [ 2 ] = V_112 ;
V_103 ++ ;
case 2000000 :
V_2 -> V_9 . V_106 . V_85 [ 1 ] =
V_113 | V_108 ;
V_103 ++ ;
case 1000000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
V_114 | V_108 ;
V_103 ++ ;
break;
default:
return - V_72 ;
}
V_2 -> V_9 . V_109 = V_115 ;
V_2 -> V_9 . V_106 . V_86 = V_103 ;
} else {
V_2 -> V_9 . V_106 . V_85 [ 3 ] = V_111 ;
V_2 -> V_9 . V_106 . V_85 [ 2 ] = V_112 ;
V_2 -> V_9 . V_106 . V_85 [ 1 ] =
V_113 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
V_114 | V_108 ;
V_2 -> V_9 . V_109 = V_116 ;
V_2 -> V_9 . V_106 . V_86 = 4 ;
}
}
} else {
if ( V_102 -> V_104 == 1 ) {
switch ( V_102 -> V_105 ) {
case 54000000 :
case 48000000 :
case 36000000 :
case 18000000 :
case 9000000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
( V_107 ) ( V_102 -> V_105 / 500000 ) ;
break;
case 24000000 :
case 12000000 :
case 11000000 :
case 6000000 :
case 5500000 :
case 2000000 :
case 1000000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
( ( V_107 ) ( V_102 -> V_105 / 500000 ) ) |
V_108 ;
break;
default:
return - V_72 ;
}
V_2 -> V_9 . V_109 = V_110 ;
V_2 -> V_9 . V_106 . V_86 = 1 ;
} else {
if ( V_102 -> V_105 > 0 ) {
switch ( V_102 -> V_105 ) {
case 54000000 :
V_2 -> V_9 . V_106 . V_85 [ 11 ] =
V_117 ;
V_103 ++ ;
case 48000000 :
V_2 -> V_9 . V_106 . V_85 [ 10 ] =
V_118 ;
V_103 ++ ;
case 36000000 :
V_2 -> V_9 . V_106 . V_85 [ 9 ] =
V_119 ;
V_103 ++ ;
case 24000000 :
case 18000000 :
case 12000000 :
case 11000000 :
case 9000000 :
case 6000000 :
if ( V_102 -> V_105 == 24000000 ) {
V_2 -> V_9 . V_106 . V_85 [ 8 ] =
V_120 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 7 ] =
V_121 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 6 ] =
V_122 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 5 ] =
V_123 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_124 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 | V_108 ;
V_103 ++ ;
} else if ( V_102 -> V_105 == 18000000 ) {
V_2 -> V_9 . V_106 . V_85 [ 7 ] =
V_120 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 6 ] =
V_121 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 5 ] =
V_123 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_124 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 | V_108 ;
V_103 ++ ;
} else if ( V_102 -> V_105 == 12000000 ) {
V_2 -> V_9 . V_106 . V_85 [ 6 ] =
V_121 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 5 ] =
V_123 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_124 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 | V_108 ;
V_103 ++ ;
} else if ( V_102 -> V_105 == 11000000 ) {
V_2 -> V_9 . V_106 . V_85 [ 5 ] =
V_121 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_124 | V_108 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 | V_108 ;
V_103 ++ ;
} else if ( V_102 -> V_105 == 9000000 ) {
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_121 ;
V_103 ++ ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_124 | V_108 ;
V_103 ++ ;
} else {
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_124 | V_108 ;
V_103 ++ ;
}
case 5500000 :
V_2 -> V_9 . V_106 . V_85 [ 2 ] =
V_112 | V_108 ;
V_103 ++ ;
case 2000000 :
V_2 -> V_9 . V_106 . V_85 [ 1 ] =
V_113 | V_108 ;
V_103 ++ ;
case 1000000 :
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
V_114 | V_108 ;
V_103 ++ ;
break;
default:
return - V_72 ;
}
V_2 -> V_9 . V_109 = V_115 ;
V_2 -> V_9 . V_106 . V_86 = V_103 ;
} else {
V_2 -> V_9 . V_106 . V_85 [ 11 ] = V_117 ;
V_2 -> V_9 . V_106 . V_85 [ 10 ] = V_118 ;
V_2 -> V_9 . V_106 . V_85 [ 9 ] = V_119 ;
V_2 -> V_9 . V_106 . V_85 [ 8 ] = V_120 ;
V_2 -> V_9 . V_106 . V_85 [ 7 ] = V_121 ;
V_2 -> V_9 . V_106 . V_85 [ 6 ] =
V_122 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 5 ] =
V_123 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 4 ] =
V_124 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 3 ] =
V_111 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 2 ] =
V_112 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 1 ] =
V_113 | V_108 ;
V_2 -> V_9 . V_106 . V_85 [ 0 ] =
V_114 | V_108 ;
V_2 -> V_9 . V_109 = V_116 ;
V_2 -> V_9 . V_106 . V_86 = 12 ;
}
}
}
V_2 -> V_74 |= V_75 ;
return - V_62 ;
}
static int F_25 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_11 ,
F_3 () , F_4 ( & V_7 ) ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ! F_4 ( & V_7 ) ) {
F_1 ( V_2 ) ;
}
V_102 -> V_105 = ( ( V_2 -> V_125 ) & V_126 ) * 500000 ;
if ( V_2 -> V_9 . V_109 == V_110 )
V_102 -> V_104 = 1 ;
else
V_102 -> V_104 = 0 ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_127 = V_102 -> V_105 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_102 -> V_128 )
V_127 = 2347 ;
if ( ( V_127 < 0 ) || ( V_127 > 2347 ) ) {
return - V_72 ;
}
V_2 -> V_9 . V_129 = V_127 ;
V_2 -> V_74 |= V_20 ;
return - V_62 ;
}
static int F_27 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_102 -> V_105 = V_2 -> V_9 . V_129 ;
V_102 -> V_128 = ( V_102 -> V_105 >= 2347 ) ;
V_102 -> V_104 = 1 ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_130 = V_102 -> V_105 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_102 -> V_128 )
V_130 = 2346 ;
if ( ( V_130 < 256 ) || ( V_130 > 2346 ) ) {
return - V_72 ;
}
V_130 &= ~ 0x1 ;
V_2 -> V_9 . V_131 = V_130 ;
V_2 -> V_74 |= V_22 ;
return - V_62 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_102 -> V_105 = V_2 -> V_9 . V_131 ;
V_102 -> V_128 = ( V_102 -> V_105 >= 2346 ) ;
V_102 -> V_104 = 1 ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_12 , * V_132 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( * V_132 ) {
case V_133 :
V_2 -> V_9 . V_10 = V_92 ;
V_2 -> V_74 |= V_75 ;
break;
case V_134 :
V_2 -> V_9 . V_10 = V_93 ;
V_2 -> V_74 |= V_75 ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
default:
return - V_72 ;
}
return - V_62 ;
}
static int F_31 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_2 -> V_9 . V_10 ) {
case V_93 :
* V_132 = V_134 ;
break;
case V_92 :
* V_132 = V_133 ;
break;
default:
* V_132 = V_133 ;
}
return 0 ;
}
static int F_32 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
T_3 V_140 ;
int V_141 = ( V_81 -> V_83 & V_142 ) ;
int V_143 = V_2 -> V_9 . V_144 ;
int V_103 ;
F_2 ( 2 , L_13 , V_81 -> V_83 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_141 < 0 ) || ( V_141 > 4 ) )
return - V_72 ;
else if ( V_141 == 0 )
V_141 = V_143 ;
else
V_141 -- ;
if ( V_81 -> V_87 > 0 ) {
if ( V_81 -> V_87 > V_145 ) {
return - V_72 ;
}
if ( V_81 -> V_87 > V_146 ) {
V_140 . V_82 = V_145 ;
V_2 -> V_9 . V_147 = 0x01 ;
V_2 -> V_74 |= V_34 ;
V_148 = V_149 ;
} else {
if ( V_81 -> V_87 > 0 ) {
V_140 . V_82 = V_146 ;
V_2 -> V_9 . V_147 = 0x01 ;
V_2 -> V_74 |= V_34 ;
V_148 = V_150 ;
} else {
V_140 . V_82 = 0 ;
}
}
if ( ! ( V_81 -> V_83 & V_151 ) ) {
memset ( V_140 . V_140 , 0 , V_145 ) ;
if ( F_33
( V_140 . V_140 , V_81 -> V_152 , V_81 -> V_87 ) ) {
V_140 . V_82 = 0 ;
return - V_153 ;
}
V_2 -> V_9 . V_154 [ V_141 ] . V_86 = V_140 . V_82 ;
for ( V_103 = 0 ; V_103 < ( V_2 -> V_9 . V_154 [ V_141 ] . V_86 ) ; V_103 ++ ) {
V_2 -> V_9 . V_154 [ V_141 ] . V_155 [ V_103 ] = V_140 . V_140 [ V_103 ] ;
}
V_2 -> V_74 |= ( V_26 << V_141 ) ;
V_2 -> V_9 . V_144 = V_141 ;
V_2 -> V_74 |= V_24 ;
}
} else {
if ( V_81 -> V_83 & V_156 ) {
V_2 -> V_9 . V_154 [ 0 ] . V_86 = 0 ;
V_2 -> V_9 . V_154 [ 1 ] . V_86 = 0 ;
V_2 -> V_9 . V_154 [ 2 ] . V_86 = 0 ;
V_2 -> V_9 . V_154 [ 3 ] . V_86 = 0 ;
V_2 -> V_9 . V_147 = 0x00 ;
if ( V_2 -> V_9 . V_157 == V_158 ) {
V_2 -> V_74 |= V_75 ;
}
V_2 -> V_9 . V_157 = V_159 ;
V_148 = V_160 ;
V_2 -> V_74 |= V_34 ;
} else {
if ( ( V_141 >= 0 ) && ( V_141 < 4 ) ) {
if ( V_2 -> V_9 . V_154 [ V_141 ] . V_86 ) {
V_2 -> V_9 . V_144 = V_141 ;
V_2 -> V_74 |= V_24 ;
} else
return - V_72 ;
}
}
}
if ( V_81 -> V_83 & V_161 )
V_2 -> V_74 |= V_34 ;
if ( V_81 -> V_83 & V_162 ) {
if ( V_2 -> V_9 . V_157 == V_158 ) {
V_2 -> V_74 |= V_75 ;
}
V_2 -> V_9 . V_157 = V_159 ;
} else if ( V_81 -> V_83 & V_163 ) {
if ( V_2 -> V_9 . V_157 == V_159 ) {
V_2 -> V_74 |= V_75 ;
}
V_2 -> V_9 . V_157 = V_158 ;
}
if ( V_2 -> V_74 ) {
F_11 ( V_2 , V_2 -> V_74 ) ;
V_2 -> V_74 = 0 ;
}
return 0 ;
}
static int F_34 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
char V_164 [ 16 ] ;
int V_141 = ( V_81 -> V_83 & V_142 ) - 1 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_81 -> V_83 = V_156 ;
switch ( V_2 -> V_9 . V_157 ) {
case V_159 :
V_81 -> V_83 = V_162 ;
break;
case V_158 :
V_81 -> V_83 = V_163 ;
break;
}
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
if ( ( V_141 < 0 ) || ( V_141 >= 4 ) )
V_141 = V_2 -> V_9 . V_144 ;
if ( V_2 -> V_9 . V_147 ) {
V_81 -> V_83 &= ~ V_156 ;
}
V_81 -> V_83 |= V_141 + 1 ;
F_2 ( 2 , L_14 , V_81 -> V_83 ) ;
if ( ( V_141 >= 0 ) && ( V_141 < 4 ) )
V_81 -> V_87 = V_2 -> V_9 . V_154 [ V_141 ] . V_86 ;
if ( V_81 -> V_87 > 16 ) {
V_81 -> V_87 = 0 ;
}
#if 1
if ( V_81 -> V_87 ) {
if ( ( V_141 >= 0 ) && ( V_141 < 4 ) )
memcpy ( V_52 , V_2 -> V_9 . V_154 [ V_141 ] . V_155 ,
V_81 -> V_87 ) ;
} else
memcpy ( V_52 , V_164 , V_81 -> V_87 ) ;
#endif
return 0 ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
return - V_68 ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_102 -> V_105 = 0 ;
V_102 -> V_128 = ( V_102 -> V_105 == 0 ) ;
V_102 -> V_104 = 1 ;
return 0 ;
}
static int F_37 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
return - V_68 ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_102 -> V_105 = 0 ;
V_102 -> V_128 = ( V_102 -> V_105 == 0 ) ;
V_102 -> V_104 = 1 ;
return 0 ;
}
static int F_39 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_165 * V_166 = (struct V_165 * ) V_52 ;
int V_103 , V_167 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_81 -> V_87 = sizeof( struct V_165 ) ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_168 = 0x0000 ;
V_166 -> V_169 = 0x0000 ;
V_166 -> V_170 = 14 ;
V_167 = 0 ;
for ( V_103 = 0 ; V_103 < 13 ; V_103 ++ ) {
V_166 -> V_171 [ V_167 ] . V_103 = V_103 + 1 ;
V_166 -> V_171 [ V_167 ] . V_64 = V_67 [ V_103 ] * 100000 ;
V_166 -> V_171 [ V_167 ++ ] . V_63 = 1 ;
}
V_166 -> V_172 = V_167 ;
if ( V_2 -> V_9 . V_56 == V_57 || V_2 -> V_9 . V_56 == V_173 ) {
V_166 -> V_171 [ 13 ] . V_103 = 14 ;
V_166 -> V_171 [ 13 ] . V_64 = V_67 [ 13 ] * 100000 ;
V_166 -> V_171 [ 13 ] . V_63 = 1 ;
V_166 -> V_172 = 14 ;
}
V_166 -> V_174 . V_175 = 100 ;
V_166 -> V_174 . V_176 = 256 - 128 ;
V_166 -> V_174 . V_177 = 256 - 128 ;
V_166 -> V_178 = 1 ;
if ( V_2 -> V_9 . V_56 == V_57 ) {
V_166 -> V_179 [ 0 ] = 1e6 ;
V_166 -> V_179 [ 1 ] = 2e6 ;
V_166 -> V_179 [ 2 ] = 5.5e6 ;
V_166 -> V_179 [ 3 ] = 11e6 ;
V_166 -> V_180 = 4 ;
} else {
V_166 -> V_179 [ 0 ] = 1e6 ;
V_166 -> V_179 [ 1 ] = 2e6 ;
V_166 -> V_179 [ 2 ] = 5.5e6 ;
V_166 -> V_179 [ 3 ] = 11e6 ;
V_166 -> V_179 [ 4 ] = 6e6 ;
V_166 -> V_179 [ 5 ] = 9e6 ;
V_166 -> V_179 [ 6 ] = 12e6 ;
if ( V_181 < 9 ) {
V_166 -> V_179 [ 7 ] = 54e6 ;
V_166 -> V_180 = 8 ;
} else {
V_166 -> V_179 [ 7 ] = 18e6 ;
V_166 -> V_179 [ 8 ] = 24e6 ;
V_166 -> V_179 [ 9 ] = 36e6 ;
V_166 -> V_179 [ 10 ] = 48e6 ;
V_166 -> V_179 [ 11 ] = 54e6 ;
V_166 -> V_180 = 12 ;
}
}
if ( V_103 > 2 )
V_166 -> V_182 = 5000 * 1000 ;
else
V_166 -> V_182 = 1500 * 1000 ;
V_166 -> V_183 = 0 ;
V_166 -> V_184 = 2347 ;
V_166 -> V_185 = 256 ;
V_166 -> V_186 = 2346 ;
V_166 -> V_187 [ 0 ] = 5 ;
V_166 -> V_187 [ 1 ] = 13 ;
V_166 -> V_188 = 2 ;
V_166 -> V_189 = 4 ;
V_166 -> V_190 = V_191 ;
V_166 -> V_192 = V_191 ;
V_166 -> V_193 = 0 ;
V_166 -> V_194 [ 0 ] = - 256 ;
V_166 -> V_195 = 1 ;
V_166 -> V_196 = V_197 ;
V_166 -> V_198 = 21 ;
V_166 -> V_199 = V_200 ;
V_166 -> V_201 = V_202 ;
V_166 -> V_203 = V_202 ;
V_166 -> V_204 = V_202 ;
V_166 -> V_205 . V_175 = 50 ;
V_166 -> V_205 . V_176 = 186 ;
V_166 -> V_205 . V_177 = 0 ;
V_166 -> V_206 [ 0 ] = ( V_207 |
F_40 ( V_208 ) |
F_40 ( V_209 ) ) ;
V_166 -> V_206 [ 1 ] = V_210 ;
V_166 -> V_206 [ 4 ] = ( F_40 ( V_211 ) |
F_40 ( V_212 ) ) ;
V_166 -> V_213 = ( V_214 |
V_215 |
V_216 | V_217 ) ;
return 0 ;
}
static int F_41 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
short V_218 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_218 = V_102 -> V_128 ? 0 : 1 ;
if ( V_218 == 0 ) {
V_2 -> V_9 . V_219 = V_220 ;
} else if ( V_218 ) {
if ( V_2 -> V_9 . V_10 == V_93 )
V_2 -> V_9 . V_219 = V_221 ;
else
return - V_72 ;
} else if ( V_218 ) {
if ( V_2 -> V_9 . V_10 == V_93 )
V_2 -> V_9 . V_219 = V_222 ;
else
return - V_72 ;
} else
return - V_72 ;
F_5 ( V_2 , V_223 ) ;
return 0 ;
}
static int F_42 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_219 > 0 )
V_102 -> V_128 = 0 ;
else
V_102 -> V_128 = 1 ;
return 0 ;
}
static int F_43 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_224 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_102 -> V_175 = 0 ;
V_102 -> V_176 = V_2 -> V_4 . V_175 . V_176 ;
V_102 -> V_177 = 0 ;
V_102 -> V_225 = 0 ;
return 0 ;
}
static int F_44 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
return - V_68 ;
}
static int F_45 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_101 * V_102 ,
char * V_52 )
{
V_102 -> V_105 = 0 ;
V_102 -> V_128 = ( V_102 -> V_105 == 0 ) ;
V_102 -> V_104 = 1 ;
return 0 ;
}
static int F_46 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_90 * V_226 = (struct V_90 * ) V_52 ;
struct V_224 V_175 [ V_227 ] ;
int V_103 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
for ( V_103 = 0 ; V_103 < V_2 -> V_228 . V_86 ; V_103 ++ ) {
memcpy ( V_226 [ V_103 ] . V_95 , & ( V_2 -> V_228 . V_229 [ V_103 ] . V_94 [ 0 ] ) ,
V_96 ) ;
V_226 [ V_103 ] . V_98 = V_99 ;
V_175 [ V_103 ] . V_176 = 256 - V_2 -> V_228 . V_229 [ V_103 ] . V_230 ;
V_175 [ V_103 ] . V_175 = V_2 -> V_228 . V_229 [ V_103 ] . V_231 ;
V_175 [ V_103 ] . V_177 = 0 ;
V_175 [ V_103 ] . V_225 = 7 ;
}
if ( V_103 ) {
V_81 -> V_83 = 1 ;
memcpy ( V_52 + sizeof( struct V_90 ) * V_103 ,
& V_175 , sizeof( struct V_224 ) * V_103 ) ;
}
V_81 -> V_87 = V_103 ;
return 0 ;
}
static int F_47 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
union V_232 * V_233 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_234 * V_235 = NULL ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_233 -> V_236 . V_87 == sizeof( struct V_234 )
&& V_233 -> V_236 . V_83 & V_237 ) {
V_235 = (struct V_234 * ) V_52 ;
V_2 -> V_238 = V_235 -> V_239 ;
memcpy ( V_2 -> V_240 , V_235 -> V_241 , V_2 -> V_238 ) ;
} else {
V_2 -> V_238 = 0 ;
}
V_2 -> V_242 . V_243 |= V_244 ;
F_5 ( V_2 , V_245 ) ;
return 0 ;
}
static inline char * F_48 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_246 , char * V_247 ,
struct V_248 * V_229 )
{
struct V_249 V_250 ;
T_4 V_251 ;
char * V_252 ;
int V_103 ;
static const char V_253 [] = L_15 ;
static const char V_254 [] = L_16 ;
char V_255 [ V_256 * 2 + 30 ] ;
char V_257 [ V_256 * 2 + 30 ] ;
char * V_258 ;
V_250 . V_259 = V_208 ;
V_250 . V_260 . V_91 . V_98 = V_99 ;
memcpy ( V_250 . V_260 . V_91 . V_95 , V_229 -> V_94 , V_96 ) ;
V_246 =
F_49 ( V_50 , V_246 , V_247 , & V_250 ,
V_261 ) ;
V_250 . V_260 . V_236 . V_87 = V_229 -> V_84 . V_86 ;
if ( V_250 . V_260 . V_236 . V_87 > 32 )
V_250 . V_260 . V_236 . V_87 = 32 ;
V_250 . V_259 = V_262 ;
V_250 . V_260 . V_236 . V_83 = 1 ;
V_246 =
F_50 ( V_50 , V_246 , V_247 , & V_250 ,
& ( V_229 -> V_84 . V_85 [ 0 ] ) ) ;
V_250 . V_259 = V_263 ;
V_251 = F_51 ( V_229 -> V_264 ) ;
if ( V_251 & ( V_265 | V_266 ) ) {
if ( V_251 & V_265 )
V_250 . V_260 . V_267 = V_134 ;
else
V_250 . V_260 . V_267 = V_133 ;
V_246 =
F_49 ( V_50 , V_246 , V_247 , & V_250 ,
V_268 ) ;
}
V_250 . V_259 = V_269 ;
V_250 . V_260 . V_171 . V_64 = V_229 -> V_69 ;
V_250 . V_260 . V_171 . V_64 = V_67 [ V_250 . V_260 . V_171 . V_64 - 1 ] * 100000 ;
V_250 . V_260 . V_171 . V_63 = 1 ;
V_246 =
F_49 ( V_50 , V_246 , V_247 , & V_250 ,
V_270 ) ;
V_250 . V_259 = V_271 ;
V_250 . V_260 . V_175 . V_176 = 256 - V_229 -> V_230 ;
V_250 . V_260 . V_175 . V_175 = V_229 -> V_231 ;
V_250 . V_260 . V_175 . V_177 = 0 ;
V_246 =
F_49 ( V_50 , V_246 , V_247 , & V_250 ,
V_272 ) ;
V_250 . V_259 = V_273 ;
if ( V_251 & V_274 )
V_250 . V_260 . V_236 . V_83 = V_275 | V_151 ;
else
V_250 . V_260 . V_236 . V_83 = V_156 ;
V_250 . V_260 . V_236 . V_87 = 0 ;
V_246 =
F_50 ( V_50 , V_246 , V_247 , & V_250 ,
& ( V_229 -> V_84 . V_85 [ 0 ] ) ) ;
V_252 = V_246 + V_276 ;
V_250 . V_259 = V_277 ;
V_250 . V_260 . V_179 . V_104 = V_250 . V_260 . V_179 . V_128 = 0 ;
for ( V_103 = 0 ; V_103 < 16 ; V_103 ++ ) {
if ( V_103 >= V_229 -> V_106 . V_86 )
break;
V_250 . V_260 . V_179 . V_105 = ( ( V_229 -> V_106 . V_85 [ V_103 ] & 0x7f ) * 500000 ) ;
V_252 =
F_52 ( V_50 , V_246 , V_252 , V_247 ,
& V_250 , V_278 ) ;
}
if ( ( V_252 - V_246 ) > V_276 )
V_246 = V_252 ;
#define F_53 0xdd
#define F_54 0x30
if ( V_229 -> V_279 . V_280 == F_54 && V_229 -> V_279 . V_86 != 0 ) {
V_258 = & V_255 [ 0 ] ;
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . V_259 = V_211 ;
memcpy ( V_255 , V_253 , sizeof( V_253 ) - 1 ) ;
V_250 . V_260 . V_236 . V_87 += sizeof( V_253 ) - 1 ;
V_258 += sizeof( V_253 ) - 1 ;
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_279 . V_280 ) ;
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_279 . V_86 ) ;
V_250 . V_260 . V_236 . V_87 += 4 ;
for ( V_103 = 0 ; V_103 < V_229 -> V_279 . V_86 ; V_103 ++ )
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_279 . V_85 [ V_103 ] ) ;
V_250 . V_260 . V_236 . V_87 += ( V_229 -> V_279 . V_86 ) * 2 ;
F_2 ( 4 , L_18 , V_229 -> V_279 . V_86 ) ;
V_246 =
F_50 ( V_50 , V_246 , V_247 , & V_250 ,
& V_255 [ 0 ] ) ;
}
if ( V_229 -> V_281 . V_280 == F_53 && V_229 -> V_281 . V_86 != 0 ) {
V_258 = & V_257 [ 0 ] ;
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . V_259 = V_211 ;
memcpy ( V_257 , V_254 , sizeof( V_254 ) - 1 ) ;
V_250 . V_260 . V_236 . V_87 += sizeof( V_254 ) - 1 ;
V_258 += sizeof( V_254 ) - 1 ;
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_281 . V_280 ) ;
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_281 . V_86 ) ;
V_250 . V_260 . V_236 . V_87 += 4 ;
for ( V_103 = 0 ; V_103 < V_229 -> V_281 . V_86 ; V_103 ++ )
V_258 += sprintf ( V_258 , L_17 , V_229 -> V_281 . V_85 [ V_103 ] ) ;
V_250 . V_260 . V_236 . V_87 += ( V_229 -> V_281 . V_86 ) * 2 ;
F_2 ( 4 , L_18 , V_229 -> V_281 . V_86 ) ;
F_2 ( 4 , L_19 , V_250 . V_260 . V_236 . V_87 ) ;
V_246 =
F_50 ( V_50 , V_246 , V_247 , & V_250 ,
& V_257 [ 0 ] ) ;
}
return V_246 ;
}
static int F_55 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_80 * V_81 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_103 ;
char * V_246 = V_52 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_242 . V_243 & V_244 ) {
F_2 ( 2 , L_20 ) ;
return - V_282 ;
}
if ( V_2 -> V_228 . V_86 == 0 ) {
F_2 ( 2 , L_21 ) ;
return - V_283 ;
}
#if 0
if ((priv->connect_status & CONNECT_STATUS_MASK) == CONNECT_STATUS) {
if ((extra + dwrq->length) - current_ev <= IW_EV_ADDR_LEN) {
dwrq->length = 0;
return -E2BIG;
}
current_ev = ks_wlan_translate_scan(dev, current_ev,
extra + dwrq->length,
&(priv->current_ap));
}
#endif
for ( V_103 = 0 ; V_103 < V_2 -> V_228 . V_86 ; V_103 ++ ) {
if ( ( V_52 + V_81 -> V_87 ) - V_246 <= V_261 ) {
V_81 -> V_87 = 0 ;
return - V_89 ;
}
V_246 = F_48 ( V_48 , V_50 , V_246 ,
V_52 + V_81 -> V_87 ,
& ( V_2 -> V_228 . V_229 [ V_103 ] ) ) ;
}
V_81 -> V_87 = ( V_246 - V_52 ) ;
V_81 -> V_83 = 0 ;
return 0 ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_49 * V_50 , void * V_284 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( ! V_2 -> V_74 )
return 0 ;
F_11 ( V_2 , V_2 -> V_74 ) ;
V_2 -> V_74 = 0 ;
return 0 ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
return 0 ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_141 = ( V_102 -> V_83 & V_285 ) ;
int V_105 = V_102 -> V_105 ;
F_2 ( 2 , L_22 , V_141 , V_105 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_141 ) {
case V_286 :
switch ( V_105 ) {
case V_287 :
V_2 -> V_288 . V_289 = V_105 ;
if ( V_2 -> V_288 . V_290 ) {
V_2 -> V_288 . V_290 = 0 ;
}
V_2 -> V_74 |= V_36 ;
break;
case V_291 :
case V_292 :
V_2 -> V_288 . V_289 = V_105 ;
if ( ! ( V_2 -> V_288 . V_290 ) ) {
V_2 -> V_288 . V_290 = 1 ;
}
V_2 -> V_74 |= V_36 ;
break;
default:
return - V_68 ;
}
break;
case V_293 :
switch ( V_105 ) {
case V_294 :
if ( V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x00 ;
V_2 -> V_74 |= V_34 ;
}
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
if ( ! V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x01 ;
V_2 -> V_74 |= V_34 ;
}
V_2 -> V_288 . V_299 = V_105 ;
V_2 -> V_74 |= V_41 ;
break;
default:
return - V_68 ;
}
break;
case V_300 :
switch ( V_105 ) {
case V_294 :
if ( V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x00 ;
V_2 -> V_74 |= V_34 ;
}
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
if ( ! V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x01 ;
V_2 -> V_74 |= V_34 ;
}
V_2 -> V_288 . V_301 = V_105 ;
V_2 -> V_74 |= V_39 ;
break;
default:
return - V_68 ;
}
break;
case V_302 :
switch ( V_105 ) {
case V_303 :
case V_304 :
case 0 :
case 4 :
V_2 -> V_288 . V_305 = V_105 ;
V_2 -> V_74 |= V_43 ;
break;
default:
return - V_68 ;
}
break;
case V_306 :
switch ( V_105 ) {
case V_307 :
V_2 -> V_288 . V_308 = V_105 ;
V_2 -> V_9 . V_157 = V_159 ;
break;
case V_309 :
V_2 -> V_288 . V_308 = V_105 ;
V_2 -> V_9 . V_157 = V_158 ;
break;
case V_310 :
default:
return - V_68 ;
}
V_2 -> V_74 |= V_75 ;
break;
case V_311 :
V_2 -> V_288 . V_312 = V_105 ;
break;
case V_313 :
if ( ( V_105 && ! V_2 -> V_9 . V_147 ) ||
( ! V_105 && V_2 -> V_9 . V_147 ) ) {
V_2 -> V_9 . V_147 = V_105 ? 0x01 : 0x00 ;
V_2 -> V_74 |= V_34 ;
}
break;
case V_314 :
case V_315 :
case V_316 :
case V_317 :
default:
break;
}
if ( V_2 -> V_74 ) {
F_11 ( V_2 , V_2 -> V_74 ) ;
V_2 -> V_74 = 0 ;
}
return 0 ;
}
static int F_59 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_101 * V_102 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_141 = ( V_102 -> V_83 & V_285 ) ;
F_2 ( 2 , L_23 , V_141 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_141 ) {
case V_286 :
V_102 -> V_105 = V_2 -> V_288 . V_289 ;
break;
case V_293 :
V_102 -> V_105 = V_2 -> V_288 . V_299 ;
break;
case V_300 :
V_102 -> V_105 = V_2 -> V_288 . V_301 ;
break;
case V_302 :
V_102 -> V_105 = V_2 -> V_288 . V_305 ;
break;
case V_306 :
V_102 -> V_105 = V_2 -> V_288 . V_308 ;
break;
case V_311 :
V_102 -> V_105 = V_2 -> V_288 . V_290 ;
break;
case V_314 :
case V_315 :
case V_316 :
default:
break;
}
return 0 ;
}
static int F_60 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_318 * V_319 ;
int V_141 = V_81 -> V_83 & V_142 ;
unsigned int V_320 = 0 ;
V_319 = (struct V_318 * ) V_52 ;
F_2 ( 2 , L_24 , V_81 -> V_83 ,
V_319 -> V_321 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_141 < 1 || V_141 > 4 )
return - V_72 ;
else
V_141 -- ;
if ( V_81 -> V_83 & V_156 ) {
V_2 -> V_288 . V_140 [ V_141 ] . V_322 = 0 ;
}
if ( V_319 ) {
V_2 -> V_288 . V_140 [ V_141 ] . V_321 = V_319 -> V_321 ;
if ( V_319 -> V_321 & V_323 ) {
V_2 -> V_288 . V_324 = V_141 ;
V_320 |= V_24 ;
} else if ( V_319 -> V_321 & V_325 ) {
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] . V_326 [ 0 ] ,
V_319 -> V_326 , V_327 ) ;
}
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] . V_328 . V_95 [ 0 ] ,
& V_319 -> V_328 . V_95 [ 0 ] , V_96 ) ;
switch ( V_319 -> V_329 ) {
case V_330 :
if ( V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x00 ;
V_320 |= V_34 ;
}
V_2 -> V_288 . V_140 [ V_141 ] . V_322 = 0 ;
break;
case V_331 :
case V_332 :
if ( ! V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x01 ;
V_320 |= V_34 ;
}
if ( V_319 -> V_322 ) {
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] . V_333 [ 0 ] ,
& V_319 -> V_140 [ 0 ] , V_319 -> V_322 ) ;
V_2 -> V_288 . V_140 [ V_141 ] . V_322 = V_319 -> V_322 ;
V_320 |= ( V_26 << V_141 ) ;
}
break;
case V_334 :
if ( ! V_2 -> V_9 . V_147 ) {
V_2 -> V_9 . V_147 = 0x01 ;
V_320 |= V_34 ;
}
if ( V_319 -> V_322 == 32 ) {
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] . V_333 [ 0 ] ,
& V_319 -> V_140 [ 0 ] , V_319 -> V_322 - 16 ) ;
V_2 -> V_288 . V_140 [ V_141 ] . V_322 =
V_319 -> V_322 - 16 ;
if ( V_2 -> V_288 . V_305 == 4 ) {
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] .
V_335 [ 0 ] , & V_319 -> V_140 [ 16 ] , 8 ) ;
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] .
V_336 [ 0 ] , & V_319 -> V_140 [ 16 ] , 8 ) ;
} else {
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] .
V_335 [ 0 ] , & V_319 -> V_140 [ 16 ] , 8 ) ;
memcpy ( & V_2 -> V_288 . V_140 [ V_141 ] .
V_336 [ 0 ] , & V_319 -> V_140 [ 24 ] , 8 ) ;
}
V_320 |= ( V_26 << V_141 ) ;
}
break;
default:
return - V_72 ;
}
V_2 -> V_288 . V_140 [ V_141 ] . V_329 = V_319 -> V_329 ;
} else
return - V_72 ;
if ( V_320 ) {
if ( V_320 & V_24 )
F_5 ( V_2 , V_337 ) ;
if ( V_320 & V_338 )
F_5 ( V_2 , V_339 + V_141 ) ;
if ( V_320 & V_34 )
F_5 ( V_2 , V_35 ) ;
}
return 0 ;
}
static int F_61 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
return 0 ;
}
static int F_62 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_340 * V_341 ;
int V_103 ;
struct V_342 * V_343 ;
struct V_344 * V_17 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ! V_52 ) {
return - V_72 ;
}
V_341 = (struct V_340 * ) V_52 ;
F_2 ( 2 , L_25 , V_341 -> V_259 ) ;
switch ( V_341 -> V_259 ) {
case V_345 :
if ( F_63 ( & V_2 -> V_346 . V_347 ) ) {
for ( V_103 = 0 ; V_103 < V_348 ; V_103 ++ ) {
V_343 = & V_2 -> V_346 . V_343 [ V_103 ] ;
if ( ! memcmp
( L_26 , V_343 -> V_94 ,
V_96 ) )
break;
}
memcpy ( V_343 -> V_94 , V_341 -> V_94 . V_95 , V_96 ) ;
memcpy ( V_343 -> V_349 , V_341 -> V_349 , V_350 ) ;
F_64 ( & V_343 -> V_351 , & V_2 -> V_346 . V_347 ) ;
V_2 -> V_346 . V_86 ++ ;
} else {
F_65 (ptr, &priv->pmklist.head) {
V_343 = F_66 ( V_17 , struct V_342 , V_351 ) ;
if ( ! memcmp ( V_341 -> V_94 . V_95 , V_343 -> V_94 , V_96 ) ) {
memcpy ( V_343 -> V_349 , V_341 -> V_349 ,
V_350 ) ;
F_67 ( & V_343 -> V_351 ,
& V_2 -> V_346 . V_347 ) ;
break;
}
}
if ( V_17 == & V_2 -> V_346 . V_347 ) {
if ( V_348 > V_2 -> V_346 . V_86 ) {
for ( V_103 = 0 ; V_103 < V_348 ; V_103 ++ ) {
V_343 = & V_2 -> V_346 . V_343 [ V_103 ] ;
if ( ! memcmp
( L_26 ,
V_343 -> V_94 , V_96 ) )
break;
}
memcpy ( V_343 -> V_94 , V_341 -> V_94 . V_95 ,
V_96 ) ;
memcpy ( V_343 -> V_349 , V_341 -> V_349 ,
V_350 ) ;
F_64 ( & V_343 -> V_351 ,
& V_2 -> V_346 . V_347 ) ;
V_2 -> V_346 . V_86 ++ ;
} else {
V_343 =
F_66 ( V_2 -> V_346 . V_347 . V_352 ,
struct V_342 , V_351 ) ;
memcpy ( V_343 -> V_94 , V_341 -> V_94 . V_95 ,
V_96 ) ;
memcpy ( V_343 -> V_349 , V_341 -> V_349 ,
V_350 ) ;
F_67 ( & V_343 -> V_351 ,
& V_2 -> V_346 . V_347 ) ;
}
}
}
break;
case V_353 :
if ( F_63 ( & V_2 -> V_346 . V_347 ) ) {
return - V_72 ;
} else {
F_65 (ptr, &priv->pmklist.head) {
V_343 = F_66 ( V_17 , struct V_342 , V_351 ) ;
if ( ! memcmp ( V_341 -> V_94 . V_95 , V_343 -> V_94 , V_96 ) ) {
memset ( V_343 -> V_94 , 0 , V_96 ) ;
memset ( V_343 -> V_349 , 0 , V_350 ) ;
F_68 ( & V_343 -> V_351 ) ;
break;
}
}
if ( V_17 == & V_2 -> V_346 . V_347 ) {
return 0 ;
}
}
break;
case V_354 :
memset ( & ( V_2 -> V_346 ) , 0 , sizeof( V_2 -> V_346 ) ) ;
F_69 ( & V_2 -> V_346 . V_347 ) ;
for ( V_103 = 0 ; V_103 < V_348 ; V_103 ++ )
F_69 ( & V_2 -> V_346 . V_343 [ V_103 ] . V_351 ) ;
break;
default:
return - V_72 ;
}
F_5 ( V_2 , V_355 ) ;
return 0 ;
}
static struct V_3 * F_70 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( ! F_4 ( & V_7 ) ) {
if ( V_2 -> V_5 < V_6 )
return NULL ;
else
return V_4 ;
}
V_4 -> V_356 . V_357 = 0 ;
V_4 -> V_356 . V_358 = 0 ;
V_4 -> V_356 . V_131 = 0 ;
V_4 -> V_356 . V_359 = 0 ;
V_4 -> V_356 . V_360 = 0 ;
V_4 -> V_361 . V_362 = 0 ;
return V_4 ;
}
static int F_71 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ! ( * V_132 ) )
return - V_72 ;
F_5 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_72 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_80 * V_81 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_363 * V_364 = (struct V_363 * ) V_52 ;
T_2 V_267 ;
F_2 ( 2 , L_27 , V_364 -> V_259 , V_364 -> V_365 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_364 -> V_259 ) {
case V_366 :
if ( V_364 -> V_365 == V_367 ) {
return 0 ;
}
case V_368 :
V_267 = 1 ;
return F_71 ( V_48 , NULL , & V_267 , NULL ) ;
default:
return - V_68 ;
}
}
static int F_73 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
strcpy ( V_52 , & ( V_2 -> V_369 [ 0 ] ) ) ;
V_81 -> V_87 = V_2 -> V_370 + 1 ;
return 0 ;
}
static int F_74 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == V_371 ) {
V_2 -> V_9 . V_372 = V_371 ;
} else if ( * V_132 == V_373 ) {
V_2 -> V_9 . V_372 = V_373 ;
} else
return - V_72 ;
V_2 -> V_74 |= V_75 ;
return - V_62 ;
}
static int F_75 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_372 ;
return 0 ;
}
static int F_76 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == V_220 ) {
V_2 -> V_9 . V_219 = V_220 ;
} else if ( * V_132 == V_221 ) {
if ( V_2 -> V_9 . V_10 == V_93 )
V_2 -> V_9 . V_219 = V_221 ;
else
return - V_72 ;
} else if ( * V_132 == V_222 ) {
if ( V_2 -> V_9 . V_10 == V_93 )
V_2 -> V_9 . V_219 = V_222 ;
else
return - V_72 ;
} else
return - V_72 ;
F_5 ( V_2 , V_223 ) ;
return 0 ;
}
static int F_77 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_219 ;
return 0 ;
}
static int F_78 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == V_374 ) {
V_2 -> V_9 . V_375 = V_374 ;
} else if ( * V_132 == V_376 ) {
V_2 -> V_9 . V_375 = V_376 ;
} else
return - V_72 ;
return 0 ;
}
static int F_79 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_375 ;
return 0 ;
}
static int F_80 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 >= V_377 && * V_132 <= V_378 ) {
V_2 -> V_9 . V_379 = * V_132 ;
} else
return - V_72 ;
if ( V_2 -> V_9 . V_10 == V_93 ) {
V_2 -> V_74 |= V_75 ;
return - V_62 ;
} else
return 0 ;
}
static int F_81 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_379 ;
return 0 ;
}
static int F_82 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == V_57 ) {
V_2 -> V_9 . V_56 = V_57 ;
} else if ( * V_132 == V_58 ) {
V_2 -> V_9 . V_56 = V_58 ;
} else if ( * V_132 == V_173 ) {
V_2 -> V_9 . V_56 = V_173 ;
} else
return - V_72 ;
V_2 -> V_74 |= V_75 ;
return - V_62 ;
}
static int F_83 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_56 ;
return 0 ;
}
static int F_84 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == V_380 ) {
V_2 -> V_9 . V_381 = V_380 ;
} else if ( * V_132 == V_382 ) {
if ( V_2 -> V_9 . V_56 == V_58 ||
V_2 -> V_9 . V_56 == V_173 )
V_2 -> V_9 . V_381 = V_382 ;
else
V_2 -> V_9 . V_381 = V_380 ;
} else
return - V_72 ;
V_2 -> V_74 |= V_75 ;
return - V_62 ;
}
static int F_85 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_9 . V_381 ;
return 0 ;
}
static int F_86 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
T_2 * V_132 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( * V_132 == V_54 ) {
V_2 -> V_53 = * V_132 ;
F_15 ( L_28 , V_2 -> V_53 ) ;
F_5 ( V_2 , V_19 ) ;
F_5 ( V_2 , V_383 ) ;
} else if ( * V_132 == V_384 ) {
V_2 -> V_53 = * V_132 ;
F_15 ( L_28 , V_2 -> V_53 ) ;
F_5 ( V_2 , V_383 ) ;
} else {
F_15 ( L_29 , * V_132 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_87 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
T_2 * V_132 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_30 , V_2 -> V_53 ) ;
* V_132 = V_2 -> V_53 ;
return 0 ;
}
static int F_88 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 == 0 || * V_132 == 1 )
V_2 -> V_385 . V_386 = * V_132 ;
else
return - V_72 ;
F_5 ( V_2 , V_387 ) ;
return 0 ;
}
static int F_89 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_385 . V_386 ;
F_15 ( L_31 , * V_132 ) ;
return 0 ;
}
static int F_90 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_80 * V_81 , char * V_52 )
{
V_107 * V_388 = V_52 ;
unsigned char V_82 ;
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
F_2 ( 2 , L_32 , V_81 -> V_87 ) ;
if ( V_388 [ 1 ] + 2 != V_81 -> V_87 || V_81 -> V_87 > 256 ) {
return - V_72 ;
}
V_2 -> V_385 . V_389 = V_388 [ 1 ] + 2 + 1 ;
V_82 = V_388 [ 1 ] + 2 ;
memcpy ( V_2 -> V_385 . V_390 , & V_82 , sizeof( V_82 ) ) ;
V_388 = memcpy ( V_2 -> V_385 . V_390 + 1 , V_388 , V_82 ) ;
F_2 ( 2 , L_33 ,
V_2 -> V_385 . V_389 , V_2 -> V_385 . V_389 , V_388 [ 0 ] , V_388 [ 1 ] , V_388 [ 2 ] , V_388 [ 3 ] ,
V_388 [ V_2 -> V_385 . V_389 - 3 ] , V_388 [ V_2 -> V_385 . V_389 - 2 ] ,
V_388 [ V_2 -> V_385 . V_389 - 1 ] ) ;
F_5 ( V_2 , V_391 ) ;
return 0 ;
}
static int F_91 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 >= 0 && * V_132 <= 0xFF )
V_2 -> V_392 . V_393 = ( V_107 ) * V_132 ;
else
return - V_72 ;
if ( V_2 -> V_392 . V_393 < 0xFF )
V_2 -> V_392 . V_394 = 1 ;
else
V_2 -> V_392 . V_394 = 0 ;
F_5 ( V_2 , V_395 ) ;
return 0 ;
}
static int F_92 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_392 . V_393 ;
F_5 ( V_2 , V_396 ) ;
return 0 ;
}
static int F_93 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_132 >= 0 && * V_132 <= 0xFF )
V_2 -> V_392 . V_397 = ( V_107 ) * V_132 ;
else
return - V_72 ;
if ( V_2 -> V_392 . V_397 < 0xFF )
V_2 -> V_392 . V_398 = 1 ;
else
V_2 -> V_392 . V_398 = 0 ;
F_5 ( V_2 , V_395 ) ;
return 0 ;
}
static int F_94 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_132 = V_2 -> V_392 . V_397 ;
F_5 ( V_2 , V_396 ) ;
return 0 ;
}
static int F_95 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_132 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
* V_132 = V_2 -> V_399 ;
return 0 ;
}
static void F_96 ( int V_400 )
{
switch ( V_400 ) {
case V_401 :
F_15 ( L_34 ) ;
break;
case V_402 :
F_15 ( L_35 ) ;
break;
case V_403 :
F_15 ( L_36 ) ;
break;
case V_404 :
F_15 ( L_37 ) ;
break;
case V_405 :
F_15 ( L_38 ) ;
break;
case V_406 :
F_15 ( L_39 ) ;
break;
case V_407 :
F_15 ( L_40 ) ;
break;
case V_408 :
F_15 ( L_41 ) ;
break;
case V_409 :
F_15 ( L_42 ) ;
break;
case V_410 :
F_15 ( L_43 ) ;
break;
case V_411 :
F_15 ( L_44 ) ;
break;
case V_412 :
F_15 ( L_45 ) ;
break;
case V_413 :
F_15 ( L_46 ) ;
break;
case V_414 :
F_15 ( L_47 ) ;
break;
case V_415 :
F_15 ( L_48 ) ;
break;
case V_416 :
F_15 ( L_49 ) ;
break;
case V_417 :
F_15 ( L_50 ) ;
break;
case V_418 :
F_15 ( L_51 ) ;
break;
case V_419 :
F_15 ( L_52 ) ;
break;
case V_420 :
F_15 ( L_53 ) ;
break;
case V_421 :
F_15 ( L_54 ) ;
break;
case V_422 :
F_15 ( L_55 ) ;
break;
case V_423 :
F_15 ( L_56 ) ;
break;
case V_424 :
F_15 ( L_57 ) ;
break;
case V_425 :
F_15 ( L_58 ) ;
break;
case V_426 :
F_15 ( L_59 ) ;
break;
case V_427 :
F_15 ( L_60 ) ;
break;
case V_428 :
F_15 ( L_61 ) ;
break;
case V_429 :
F_15 ( L_62 ) ;
break;
case V_430 :
F_15 ( L_63 ) ;
break;
case V_431 :
F_15 ( L_64 ) ;
break;
case V_432 :
F_15 ( L_65 ) ;
break;
case V_433 :
F_15 ( L_66 ) ;
break;
case V_434 :
F_15 ( L_67 ) ;
break;
case V_435 :
F_15 ( L_68 ) ;
break;
case V_436 :
F_15 ( L_69 ) ;
}
}
static int F_97 ( struct V_47 * V_48 , struct V_49 * V_50 ,
T_2 * V_132 , char * V_52 )
{
int V_103 , V_400 ;
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
for ( V_103 = 63 ; V_103 >= 0 ; V_103 -- ) {
V_400 =
V_2 -> V_437 . V_438 [ ( V_2 -> V_437 . V_439 - 1 - V_103 ) %
V_440 ] ;
F_96 ( V_400 ) ;
}
return 0 ;
}
static int F_98 ( struct V_47 * V_48 , struct V_441 * V_442 ,
int V_259 )
{
int V_61 = 0 ;
struct V_443 * V_444 = (struct V_443 * ) V_442 ;
switch ( V_259 ) {
case V_445 + 20 :
V_61 = F_71 ( V_48 , NULL , & ( V_444 -> V_260 . V_267 ) , NULL ) ;
break;
default:
V_61 = - V_68 ;
}
F_2 ( 5 , L_31 , V_61 ) ;
return V_61 ;
}
static
struct V_446 * F_99 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
if ( V_2 -> V_5 < V_6 ) {
return NULL ;
}
return & V_2 -> V_447 ;
}
static
int F_100 ( struct V_47 * V_48 , void * V_328 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
struct V_90 * V_448 = (struct V_90 * ) V_328 ;
if ( F_101 ( V_48 ) )
return - V_449 ;
memcpy ( V_48 -> V_450 , V_448 -> V_95 , V_48 -> V_451 ) ;
memcpy ( V_2 -> V_452 , V_448 -> V_95 , V_96 ) ;
V_2 -> V_453 = 0 ;
F_5 ( V_2 , V_454 ) ;
F_15 ( V_455
L_70 ,
V_2 -> V_452 [ 0 ] , V_2 -> V_452 [ 1 ] , V_2 -> V_452 [ 2 ] ,
V_2 -> V_452 [ 3 ] , V_2 -> V_452 [ 4 ] , V_2 -> V_452 [ 5 ] ) ;
return 0 ;
}
static
void F_102 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
F_2 ( 1 , L_71 , V_2 -> V_456 . V_457 ,
V_2 -> V_456 . V_439 ) ;
if ( ! F_103 ( V_48 ) ) {
F_104 ( V_48 ) ;
}
V_2 -> V_447 . V_458 ++ ;
F_105 ( V_48 ) ;
return;
}
static
int F_106 ( struct V_459 * V_460 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
int V_61 = 0 ;
F_2 ( 3 , L_72 , F_3 () ) ;
if ( V_460 == NULL ) {
F_15 ( V_461 L_73 ) ;
return 0 ;
}
if ( V_2 -> V_5 < V_6 ) {
F_107 ( V_460 ) ;
return 0 ;
}
if ( F_101 ( V_48 ) )
F_104 ( V_48 ) ;
V_61 = F_108 ( V_2 , V_460 ) ;
F_109 ( V_48 ) ;
F_2 ( 4 , L_74 , V_61 ) ;
if ( V_61 ) {
V_61 = 0 ;
}
return V_61 ;
}
void F_110 ( void * V_462 , void * V_463 )
{
struct V_1 * V_2 = (struct V_1 * ) V_462 ;
struct V_459 * V_464 = (struct V_459 * ) V_463 ;
F_2 ( 3 , L_3 ) ;
V_2 -> V_447 . V_465 += V_464 -> V_82 ;
V_2 -> V_447 . V_466 ++ ;
if ( F_103 ( V_2 -> V_467 ) )
F_105 ( V_2 -> V_467 ) ;
if ( V_464 ) {
F_107 ( V_464 ) ;
V_464 = NULL ;
}
}
static
void F_111 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
F_2 ( 4 , L_3 ) ;
if ( V_2 -> V_5 < V_6 ) {
return;
}
F_5 ( V_2 , V_468 ) ;
return;
}
static
int F_112 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
V_2 -> V_469 = 0 ;
if ( ! V_2 -> V_453 ) {
F_15 ( V_461 L_75 , V_48 -> V_71 ) ;
return - V_449 ;
} else
F_113 ( V_48 ) ;
return 0 ;
}
static
int F_114 ( struct V_47 * V_48 )
{
F_104 ( V_48 ) ;
F_2 ( 4 , L_76 ,
V_48 -> V_71 , 0x00 ) ;
return 0 ;
}
int F_115 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_48 ) ;
V_2 -> V_453 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_470 = 1 ;
F_10 ( & V_7 , 0 ) ;
F_116 ( & V_14 ) ;
V_14 . V_471 = F_9 ;
V_14 . V_236 = ( unsigned long ) V_2 ;
memcpy ( V_2 -> V_452 , V_472 , V_96 ) ;
V_48 -> V_450 [ 0 ] = V_2 -> V_452 [ 0 ] ;
V_48 -> V_450 [ 1 ] = V_2 -> V_452 [ 1 ] ;
V_48 -> V_450 [ 2 ] = V_2 -> V_452 [ 2 ] ;
V_48 -> V_450 [ 3 ] = V_2 -> V_452 [ 3 ] ;
V_48 -> V_450 [ 4 ] = V_2 -> V_452 [ 4 ] ;
V_48 -> V_450 [ 5 ] = V_2 -> V_452 [ 5 ] ;
V_48 -> V_450 [ 6 ] = 0x00 ;
V_48 -> V_450 [ 7 ] = 0x00 ;
V_48 -> V_473 = & V_474 ;
V_48 -> V_475 = (struct V_476 * ) & V_477 ;
V_48 -> V_478 = V_479 ;
F_117 ( V_48 ) ;
return 0 ;
}
int F_118 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
int V_480 = 0 ;
V_2 -> V_470 = 0 ;
F_119 ( & V_14 ) ;
if ( F_101 ( V_48 ) )
F_104 ( V_48 ) ;
return V_480 ;
}
int F_120 ( struct V_47 * V_48 )
{
return 0 ;
}
