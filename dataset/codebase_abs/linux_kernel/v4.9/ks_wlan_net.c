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
F_15 ( V_48 ,
L_8 ,
V_48 -> V_70 , V_60 -> V_64 ) ;
V_61 = - V_71 ;
} else {
V_2 -> V_9 . V_69 = ( V_72 ) ( V_69 ) ;
V_2 -> V_73 |= V_74 ;
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
if ( ( V_2 -> V_75 & V_76 ) == V_77 ) {
V_65 = ( int ) V_2 -> V_78 . V_69 ;
} else
V_65 = ( int ) V_2 -> V_9 . V_69 ;
V_60 -> V_64 = V_67 [ V_65 - 1 ] * 100000 ;
V_60 -> V_63 = 1 ;
return 0 ;
}
static int F_17 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
T_1 V_81 ;
F_2 ( 2 , L_9 , V_80 -> V_82 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_80 -> V_82 == 0 ) {
memset ( V_2 -> V_9 . V_83 . V_84 , 0 , sizeof( V_2 -> V_9 . V_83 . V_84 ) ) ;
V_2 -> V_9 . V_83 . V_85 = 0 ;
} else {
#if 1
V_81 = V_80 -> V_86 ;
if ( V_81 > 0 && V_52 [ V_81 - 1 ] == '\0' )
V_81 -- ;
if ( V_81 > V_87 ) {
return - V_71 ;
}
#else
if ( V_80 -> V_86 > V_87 + 1 ) {
return - V_88 ;
}
#endif
memset ( V_2 -> V_9 . V_83 . V_84 , 0 , sizeof( V_2 -> V_9 . V_83 . V_84 ) ) ;
#if 1
memcpy ( V_2 -> V_9 . V_83 . V_84 , V_52 , V_81 ) ;
V_2 -> V_9 . V_83 . V_85 = V_81 ;
#else
memcpy ( V_2 -> V_9 . V_83 . V_84 , V_52 , V_80 -> V_86 ) ;
V_2 -> V_9 . V_83 . V_85 = V_80 -> V_86 ;
#endif
}
V_2 -> V_73 |= V_74 ;
F_11 ( V_2 , V_2 -> V_73 ) ;
V_2 -> V_73 = 0 ;
return 0 ;
}
static int F_18 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_83 . V_85 ) {
memcpy ( V_52 , V_2 -> V_9 . V_83 . V_84 , V_2 -> V_9 . V_83 . V_85 ) ;
#if 0
extra[priv->reg.ssid.size] = '\0';
#endif
#if 1
V_80 -> V_86 = V_2 -> V_9 . V_83 . V_85 ;
#else
V_80 -> V_86 = V_2 -> V_9 . V_83 . V_85 + 1 ;
#endif
V_80 -> V_82 = 1 ;
} else {
#if 1
V_80 -> V_86 = 0 ;
#else
V_52 [ 0 ] = '\0' ;
V_80 -> V_86 = 1 ;
#endif
V_80 -> V_82 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_89 * V_90 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_10 == V_91 ||
V_2 -> V_9 . V_10 == V_92 ) {
memcpy ( V_2 -> V_9 . V_93 , ( V_72 * ) & V_90 -> V_94 , V_95 ) ;
if ( F_20 ( ( V_72 * ) V_2 -> V_9 . V_93 ) ) {
V_2 -> V_73 |= V_74 ;
}
} else {
F_21 ( V_2 -> V_9 . V_93 ) ;
return - V_68 ;
}
F_2 ( 2 , L_10 ,
V_2 -> V_9 . V_93 [ 0 ] , V_2 -> V_9 . V_93 [ 1 ] , V_2 -> V_9 . V_93 [ 2 ] ,
V_2 -> V_9 . V_93 [ 3 ] , V_2 -> V_9 . V_93 [ 4 ] , V_2 -> V_9 . V_93 [ 5 ] ) ;
if ( V_2 -> V_73 ) {
V_2 -> V_73 |= V_74 ;
return - V_62 ;
}
return 0 ;
}
static int F_22 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_89 * V_96 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_2 -> V_75 & V_76 ) == V_77 ) {
memcpy ( V_96 -> V_94 , & ( V_2 -> V_78 . V_93 [ 0 ] ) , V_95 ) ;
} else {
F_21 ( V_96 -> V_94 ) ;
}
V_96 -> V_97 = V_98 ;
return 0 ;
}
static int F_23 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_79 * V_80 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_80 -> V_86 > 16 + 1 ) {
return - V_88 ;
}
memset ( V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
memcpy ( V_2 -> V_99 , V_52 , V_80 -> V_86 ) ;
return - V_62 ;
}
static int F_24 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_79 * V_80 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
strncpy ( V_52 , V_2 -> V_99 , 16 ) ;
V_52 [ 16 ] = '\0' ;
V_80 -> V_86 = strlen ( V_52 ) + 1 ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_102 = 0 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_56 == V_57 ) {
if ( V_101 -> V_103 == 1 ) {
switch ( V_101 -> V_104 ) {
case 11000000 :
case 5500000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
( V_106 ) ( V_101 -> V_104 / 500000 ) ;
break;
case 2000000 :
case 1000000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
( ( V_106 ) ( V_101 -> V_104 / 500000 ) ) |
V_107 ;
break;
default:
return - V_71 ;
}
V_2 -> V_9 . V_108 = V_109 ;
V_2 -> V_9 . V_105 . V_85 = 1 ;
} else {
if ( V_101 -> V_104 > 0 ) {
switch ( V_101 -> V_104 ) {
case 11000000 :
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 ;
V_102 ++ ;
case 5500000 :
V_2 -> V_9 . V_105 . V_84 [ 2 ] = V_111 ;
V_102 ++ ;
case 2000000 :
V_2 -> V_9 . V_105 . V_84 [ 1 ] =
V_112 | V_107 ;
V_102 ++ ;
case 1000000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
V_113 | V_107 ;
V_102 ++ ;
break;
default:
return - V_71 ;
}
V_2 -> V_9 . V_108 = V_114 ;
V_2 -> V_9 . V_105 . V_85 = V_102 ;
} else {
V_2 -> V_9 . V_105 . V_84 [ 3 ] = V_110 ;
V_2 -> V_9 . V_105 . V_84 [ 2 ] = V_111 ;
V_2 -> V_9 . V_105 . V_84 [ 1 ] =
V_112 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
V_113 | V_107 ;
V_2 -> V_9 . V_108 = V_115 ;
V_2 -> V_9 . V_105 . V_85 = 4 ;
}
}
} else {
if ( V_101 -> V_103 == 1 ) {
switch ( V_101 -> V_104 ) {
case 54000000 :
case 48000000 :
case 36000000 :
case 18000000 :
case 9000000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
( V_106 ) ( V_101 -> V_104 / 500000 ) ;
break;
case 24000000 :
case 12000000 :
case 11000000 :
case 6000000 :
case 5500000 :
case 2000000 :
case 1000000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
( ( V_106 ) ( V_101 -> V_104 / 500000 ) ) |
V_107 ;
break;
default:
return - V_71 ;
}
V_2 -> V_9 . V_108 = V_109 ;
V_2 -> V_9 . V_105 . V_85 = 1 ;
} else {
if ( V_101 -> V_104 > 0 ) {
switch ( V_101 -> V_104 ) {
case 54000000 :
V_2 -> V_9 . V_105 . V_84 [ 11 ] =
V_116 ;
V_102 ++ ;
case 48000000 :
V_2 -> V_9 . V_105 . V_84 [ 10 ] =
V_117 ;
V_102 ++ ;
case 36000000 :
V_2 -> V_9 . V_105 . V_84 [ 9 ] =
V_118 ;
V_102 ++ ;
case 24000000 :
case 18000000 :
case 12000000 :
case 11000000 :
case 9000000 :
case 6000000 :
if ( V_101 -> V_104 == 24000000 ) {
V_2 -> V_9 . V_105 . V_84 [ 8 ] =
V_119 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 7 ] =
V_120 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 6 ] =
V_121 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 5 ] =
V_122 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_123 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 | V_107 ;
V_102 ++ ;
} else if ( V_101 -> V_104 == 18000000 ) {
V_2 -> V_9 . V_105 . V_84 [ 7 ] =
V_119 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 6 ] =
V_120 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 5 ] =
V_122 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_123 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 | V_107 ;
V_102 ++ ;
} else if ( V_101 -> V_104 == 12000000 ) {
V_2 -> V_9 . V_105 . V_84 [ 6 ] =
V_120 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 5 ] =
V_122 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_123 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 | V_107 ;
V_102 ++ ;
} else if ( V_101 -> V_104 == 11000000 ) {
V_2 -> V_9 . V_105 . V_84 [ 5 ] =
V_120 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_123 | V_107 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 | V_107 ;
V_102 ++ ;
} else if ( V_101 -> V_104 == 9000000 ) {
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_120 ;
V_102 ++ ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_123 | V_107 ;
V_102 ++ ;
} else {
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_123 | V_107 ;
V_102 ++ ;
}
case 5500000 :
V_2 -> V_9 . V_105 . V_84 [ 2 ] =
V_111 | V_107 ;
V_102 ++ ;
case 2000000 :
V_2 -> V_9 . V_105 . V_84 [ 1 ] =
V_112 | V_107 ;
V_102 ++ ;
case 1000000 :
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
V_113 | V_107 ;
V_102 ++ ;
break;
default:
return - V_71 ;
}
V_2 -> V_9 . V_108 = V_114 ;
V_2 -> V_9 . V_105 . V_85 = V_102 ;
} else {
V_2 -> V_9 . V_105 . V_84 [ 11 ] = V_116 ;
V_2 -> V_9 . V_105 . V_84 [ 10 ] = V_117 ;
V_2 -> V_9 . V_105 . V_84 [ 9 ] = V_118 ;
V_2 -> V_9 . V_105 . V_84 [ 8 ] = V_119 ;
V_2 -> V_9 . V_105 . V_84 [ 7 ] = V_120 ;
V_2 -> V_9 . V_105 . V_84 [ 6 ] =
V_121 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 5 ] =
V_122 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 4 ] =
V_123 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 3 ] =
V_110 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 2 ] =
V_111 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 1 ] =
V_112 | V_107 ;
V_2 -> V_9 . V_105 . V_84 [ 0 ] =
V_113 | V_107 ;
V_2 -> V_9 . V_108 = V_115 ;
V_2 -> V_9 . V_105 . V_85 = 12 ;
}
}
}
V_2 -> V_73 |= V_74 ;
return - V_62 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
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
V_101 -> V_104 = ( ( V_2 -> V_124 ) & V_125 ) * 500000 ;
if ( V_2 -> V_9 . V_108 == V_109 )
V_101 -> V_103 = 1 ;
else
V_101 -> V_103 = 0 ;
return 0 ;
}
static int F_27 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_126 = V_101 -> V_104 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_101 -> V_127 )
V_126 = 2347 ;
if ( ( V_126 < 0 ) || ( V_126 > 2347 ) ) {
return - V_71 ;
}
V_2 -> V_9 . V_128 = V_126 ;
V_2 -> V_73 |= V_20 ;
return - V_62 ;
}
static int F_28 ( struct V_47 * V_48 , struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_101 -> V_104 = V_2 -> V_9 . V_128 ;
V_101 -> V_127 = ( V_101 -> V_104 >= 2347 ) ;
V_101 -> V_103 = 1 ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_129 = V_101 -> V_104 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_101 -> V_127 )
V_129 = 2346 ;
if ( ( V_129 < 256 ) || ( V_129 > 2346 ) ) {
return - V_71 ;
}
V_129 &= ~ 0x1 ;
V_2 -> V_9 . V_130 = V_129 ;
V_2 -> V_73 |= V_22 ;
return - V_62 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_101 -> V_104 = V_2 -> V_9 . V_130 ;
V_101 -> V_127 = ( V_101 -> V_104 >= 2346 ) ;
V_101 -> V_103 = 1 ;
return 0 ;
}
static int F_31 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_12 , * V_131 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( * V_131 ) {
case V_132 :
V_2 -> V_9 . V_10 = V_91 ;
V_2 -> V_73 |= V_74 ;
break;
case V_133 :
V_2 -> V_9 . V_10 = V_92 ;
V_2 -> V_73 |= V_74 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
default:
return - V_71 ;
}
return - V_62 ;
}
static int F_32 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_2 -> V_9 . V_10 ) {
case V_92 :
* V_131 = V_133 ;
break;
case V_91 :
* V_131 = V_132 ;
break;
default:
* V_131 = V_132 ;
}
return 0 ;
}
static int F_33 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
T_3 V_139 ;
int V_140 = ( V_80 -> V_82 & V_141 ) ;
int V_142 = V_2 -> V_9 . V_143 ;
int V_102 ;
F_2 ( 2 , L_13 , V_80 -> V_82 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ( V_140 < 0 ) || ( V_140 > 4 ) )
return - V_71 ;
else if ( V_140 == 0 )
V_140 = V_142 ;
else
V_140 -- ;
if ( V_80 -> V_86 > 0 ) {
if ( V_80 -> V_86 > V_144 ) {
return - V_71 ;
}
if ( V_80 -> V_86 > V_145 ) {
V_139 . V_81 = V_144 ;
V_2 -> V_9 . V_146 = 0x01 ;
V_2 -> V_73 |= V_34 ;
V_147 = V_148 ;
} else {
if ( V_80 -> V_86 > 0 ) {
V_139 . V_81 = V_145 ;
V_2 -> V_9 . V_146 = 0x01 ;
V_2 -> V_73 |= V_34 ;
V_147 = V_149 ;
} else {
V_139 . V_81 = 0 ;
}
}
if ( ! ( V_80 -> V_82 & V_150 ) ) {
memset ( V_139 . V_139 , 0 , V_144 ) ;
if ( F_34
( V_139 . V_139 , V_80 -> V_151 , V_80 -> V_86 ) ) {
V_139 . V_81 = 0 ;
return - V_152 ;
}
V_2 -> V_9 . V_153 [ V_140 ] . V_85 = V_139 . V_81 ;
for ( V_102 = 0 ; V_102 < ( V_2 -> V_9 . V_153 [ V_140 ] . V_85 ) ; V_102 ++ ) {
V_2 -> V_9 . V_153 [ V_140 ] . V_154 [ V_102 ] = V_139 . V_139 [ V_102 ] ;
}
V_2 -> V_73 |= ( V_26 << V_140 ) ;
V_2 -> V_9 . V_143 = V_140 ;
V_2 -> V_73 |= V_24 ;
}
} else {
if ( V_80 -> V_82 & V_155 ) {
V_2 -> V_9 . V_153 [ 0 ] . V_85 = 0 ;
V_2 -> V_9 . V_153 [ 1 ] . V_85 = 0 ;
V_2 -> V_9 . V_153 [ 2 ] . V_85 = 0 ;
V_2 -> V_9 . V_153 [ 3 ] . V_85 = 0 ;
V_2 -> V_9 . V_146 = 0x00 ;
if ( V_2 -> V_9 . V_156 == V_157 ) {
V_2 -> V_73 |= V_74 ;
}
V_2 -> V_9 . V_156 = V_158 ;
V_147 = V_159 ;
V_2 -> V_73 |= V_34 ;
} else {
if ( ( V_140 >= 0 ) && ( V_140 < 4 ) ) {
if ( V_2 -> V_9 . V_153 [ V_140 ] . V_85 ) {
V_2 -> V_9 . V_143 = V_140 ;
V_2 -> V_73 |= V_24 ;
} else
return - V_71 ;
}
}
}
if ( V_80 -> V_82 & V_160 )
V_2 -> V_73 |= V_34 ;
if ( V_80 -> V_82 & V_161 ) {
if ( V_2 -> V_9 . V_156 == V_157 ) {
V_2 -> V_73 |= V_74 ;
}
V_2 -> V_9 . V_156 = V_158 ;
} else if ( V_80 -> V_82 & V_162 ) {
if ( V_2 -> V_9 . V_156 == V_158 ) {
V_2 -> V_73 |= V_74 ;
}
V_2 -> V_9 . V_156 = V_157 ;
}
if ( V_2 -> V_73 ) {
F_11 ( V_2 , V_2 -> V_73 ) ;
V_2 -> V_73 = 0 ;
}
return 0 ;
}
static int F_35 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
char V_163 [ 16 ] ;
int V_140 = ( V_80 -> V_82 & V_141 ) - 1 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_80 -> V_82 = V_155 ;
switch ( V_2 -> V_9 . V_156 ) {
case V_158 :
V_80 -> V_82 = V_161 ;
break;
case V_157 :
V_80 -> V_82 = V_162 ;
break;
}
memset ( V_163 , 0 , sizeof( V_163 ) ) ;
if ( ( V_140 < 0 ) || ( V_140 >= 4 ) )
V_140 = V_2 -> V_9 . V_143 ;
if ( V_2 -> V_9 . V_146 ) {
V_80 -> V_82 &= ~ V_155 ;
}
V_80 -> V_82 |= V_140 + 1 ;
F_2 ( 2 , L_14 , V_80 -> V_82 ) ;
if ( ( V_140 >= 0 ) && ( V_140 < 4 ) )
V_80 -> V_86 = V_2 -> V_9 . V_153 [ V_140 ] . V_85 ;
if ( V_80 -> V_86 > 16 ) {
V_80 -> V_86 = 0 ;
}
#if 1
if ( V_80 -> V_86 ) {
if ( ( V_140 >= 0 ) && ( V_140 < 4 ) )
memcpy ( V_52 , V_2 -> V_9 . V_153 [ V_140 ] . V_154 ,
V_80 -> V_86 ) ;
} else
memcpy ( V_52 , V_163 , V_80 -> V_86 ) ;
#endif
return 0 ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
return - V_68 ;
}
static int F_37 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_101 -> V_104 = 0 ;
V_101 -> V_127 = ( V_101 -> V_104 == 0 ) ;
V_101 -> V_103 = 1 ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
return - V_68 ;
}
static int F_39 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_101 -> V_104 = 0 ;
V_101 -> V_127 = ( V_101 -> V_104 == 0 ) ;
V_101 -> V_103 = 1 ;
return 0 ;
}
static int F_40 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_164 * V_165 = (struct V_164 * ) V_52 ;
int V_102 , V_166 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_80 -> V_86 = sizeof( struct V_164 ) ;
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
V_165 -> V_167 = 0x0000 ;
V_165 -> V_168 = 0x0000 ;
V_165 -> V_169 = 14 ;
V_166 = 0 ;
for ( V_102 = 0 ; V_102 < 13 ; V_102 ++ ) {
V_165 -> V_170 [ V_166 ] . V_102 = V_102 + 1 ;
V_165 -> V_170 [ V_166 ] . V_64 = V_67 [ V_102 ] * 100000 ;
V_165 -> V_170 [ V_166 ++ ] . V_63 = 1 ;
}
V_165 -> V_171 = V_166 ;
if ( V_2 -> V_9 . V_56 == V_57 || V_2 -> V_9 . V_56 == V_172 ) {
V_165 -> V_170 [ 13 ] . V_102 = 14 ;
V_165 -> V_170 [ 13 ] . V_64 = V_67 [ 13 ] * 100000 ;
V_165 -> V_170 [ 13 ] . V_63 = 1 ;
V_165 -> V_171 = 14 ;
}
V_165 -> V_173 . V_174 = 100 ;
V_165 -> V_173 . V_175 = 256 - 128 ;
V_165 -> V_173 . V_176 = 256 - 128 ;
V_165 -> V_177 = 1 ;
if ( V_2 -> V_9 . V_56 == V_57 ) {
V_165 -> V_178 [ 0 ] = 1e6 ;
V_165 -> V_178 [ 1 ] = 2e6 ;
V_165 -> V_178 [ 2 ] = 5.5e6 ;
V_165 -> V_178 [ 3 ] = 11e6 ;
V_165 -> V_179 = 4 ;
} else {
V_165 -> V_178 [ 0 ] = 1e6 ;
V_165 -> V_178 [ 1 ] = 2e6 ;
V_165 -> V_178 [ 2 ] = 5.5e6 ;
V_165 -> V_178 [ 3 ] = 11e6 ;
V_165 -> V_178 [ 4 ] = 6e6 ;
V_165 -> V_178 [ 5 ] = 9e6 ;
V_165 -> V_178 [ 6 ] = 12e6 ;
if ( V_180 < 9 ) {
V_165 -> V_178 [ 7 ] = 54e6 ;
V_165 -> V_179 = 8 ;
} else {
V_165 -> V_178 [ 7 ] = 18e6 ;
V_165 -> V_178 [ 8 ] = 24e6 ;
V_165 -> V_178 [ 9 ] = 36e6 ;
V_165 -> V_178 [ 10 ] = 48e6 ;
V_165 -> V_178 [ 11 ] = 54e6 ;
V_165 -> V_179 = 12 ;
}
}
if ( V_102 > 2 )
V_165 -> V_181 = 5000 * 1000 ;
else
V_165 -> V_181 = 1500 * 1000 ;
V_165 -> V_182 = 0 ;
V_165 -> V_183 = 2347 ;
V_165 -> V_184 = 256 ;
V_165 -> V_185 = 2346 ;
V_165 -> V_186 [ 0 ] = 5 ;
V_165 -> V_186 [ 1 ] = 13 ;
V_165 -> V_187 = 2 ;
V_165 -> V_188 = 4 ;
V_165 -> V_189 = V_190 ;
V_165 -> V_191 = V_190 ;
V_165 -> V_192 = 0 ;
V_165 -> V_193 [ 0 ] = - 256 ;
V_165 -> V_194 = 1 ;
V_165 -> V_195 = V_196 ;
V_165 -> V_197 = 21 ;
V_165 -> V_198 = V_199 ;
V_165 -> V_200 = V_201 ;
V_165 -> V_202 = V_201 ;
V_165 -> V_203 = V_201 ;
V_165 -> V_204 . V_174 = 50 ;
V_165 -> V_204 . V_175 = 186 ;
V_165 -> V_204 . V_176 = 0 ;
V_165 -> V_205 [ 0 ] = ( V_206 |
F_41 ( V_207 ) |
F_41 ( V_208 ) ) ;
V_165 -> V_205 [ 1 ] = V_209 ;
V_165 -> V_205 [ 4 ] = ( F_41 ( V_210 ) |
F_41 ( V_211 ) ) ;
V_165 -> V_212 = ( V_213 |
V_214 |
V_215 | V_216 ) ;
return 0 ;
}
static int F_42 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
short V_217 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_217 = V_101 -> V_127 ? 0 : 1 ;
if ( V_217 == 0 ) {
V_2 -> V_9 . V_218 = V_219 ;
} else if ( V_217 ) {
if ( V_2 -> V_9 . V_10 == V_92 )
V_2 -> V_9 . V_218 = V_220 ;
else
return - V_71 ;
} else if ( V_217 ) {
if ( V_2 -> V_9 . V_10 == V_92 )
V_2 -> V_9 . V_218 = V_221 ;
else
return - V_71 ;
} else
return - V_71 ;
F_5 ( V_2 , V_222 ) ;
return 0 ;
}
static int F_43 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_9 . V_218 > 0 )
V_101 -> V_127 = 0 ;
else
V_101 -> V_127 = 1 ;
return 0 ;
}
static int F_44 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_223 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
V_101 -> V_174 = 0 ;
V_101 -> V_175 = V_2 -> V_4 . V_174 . V_175 ;
V_101 -> V_176 = 0 ;
V_101 -> V_224 = 0 ;
return 0 ;
}
static int F_45 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
char * V_52 )
{
return - V_68 ;
}
static int F_46 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_100 * V_101 ,
char * V_52 )
{
V_101 -> V_104 = 0 ;
V_101 -> V_127 = ( V_101 -> V_104 == 0 ) ;
V_101 -> V_103 = 1 ;
return 0 ;
}
static int F_47 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_89 * V_225 = (struct V_89 * ) V_52 ;
struct V_223 V_174 [ V_226 ] ;
int V_102 ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
for ( V_102 = 0 ; V_102 < V_2 -> V_227 . V_85 ; V_102 ++ ) {
memcpy ( V_225 [ V_102 ] . V_94 , & ( V_2 -> V_227 . V_228 [ V_102 ] . V_93 [ 0 ] ) ,
V_95 ) ;
V_225 [ V_102 ] . V_97 = V_98 ;
V_174 [ V_102 ] . V_175 = 256 - V_2 -> V_227 . V_228 [ V_102 ] . V_229 ;
V_174 [ V_102 ] . V_174 = V_2 -> V_227 . V_228 [ V_102 ] . V_230 ;
V_174 [ V_102 ] . V_176 = 0 ;
V_174 [ V_102 ] . V_224 = 7 ;
}
if ( V_102 ) {
V_80 -> V_82 = 1 ;
memcpy ( V_52 + sizeof( struct V_89 ) * V_102 ,
& V_174 , sizeof( struct V_223 ) * V_102 ) ;
}
V_80 -> V_86 = V_102 ;
return 0 ;
}
static int F_48 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
union V_231 * V_232 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_233 * V_234 = NULL ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_232 -> V_235 . V_86 == sizeof( struct V_233 )
&& V_232 -> V_235 . V_82 & V_236 ) {
V_234 = (struct V_233 * ) V_52 ;
V_2 -> V_237 = V_234 -> V_238 ;
memcpy ( V_2 -> V_239 , V_234 -> V_240 , V_2 -> V_237 ) ;
} else {
V_2 -> V_237 = 0 ;
}
V_2 -> V_241 . V_242 |= V_243 ;
F_5 ( V_2 , V_244 ) ;
return 0 ;
}
static inline char * F_49 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_245 , char * V_246 ,
struct V_247 * V_228 )
{
struct V_248 V_249 ;
T_4 V_250 ;
char * V_251 ;
int V_102 ;
static const char V_252 [] = L_15 ;
static const char V_253 [] = L_16 ;
char V_254 [ V_255 * 2 + 30 ] ;
char V_256 [ V_255 * 2 + 30 ] ;
char * V_257 ;
V_249 . V_258 = V_207 ;
V_249 . V_259 . V_90 . V_97 = V_98 ;
memcpy ( V_249 . V_259 . V_90 . V_94 , V_228 -> V_93 , V_95 ) ;
V_245 =
F_50 ( V_50 , V_245 , V_246 , & V_249 ,
V_260 ) ;
V_249 . V_259 . V_235 . V_86 = V_228 -> V_83 . V_85 ;
if ( V_249 . V_259 . V_235 . V_86 > 32 )
V_249 . V_259 . V_235 . V_86 = 32 ;
V_249 . V_258 = V_261 ;
V_249 . V_259 . V_235 . V_82 = 1 ;
V_245 =
F_51 ( V_50 , V_245 , V_246 , & V_249 ,
& ( V_228 -> V_83 . V_84 [ 0 ] ) ) ;
V_249 . V_258 = V_262 ;
V_250 = F_52 ( V_228 -> V_263 ) ;
if ( V_250 & ( V_264 | V_265 ) ) {
if ( V_250 & V_264 )
V_249 . V_259 . V_266 = V_133 ;
else
V_249 . V_259 . V_266 = V_132 ;
V_245 =
F_50 ( V_50 , V_245 , V_246 , & V_249 ,
V_267 ) ;
}
V_249 . V_258 = V_268 ;
V_249 . V_259 . V_170 . V_64 = V_228 -> V_69 ;
V_249 . V_259 . V_170 . V_64 = V_67 [ V_249 . V_259 . V_170 . V_64 - 1 ] * 100000 ;
V_249 . V_259 . V_170 . V_63 = 1 ;
V_245 =
F_50 ( V_50 , V_245 , V_246 , & V_249 ,
V_269 ) ;
V_249 . V_258 = V_270 ;
V_249 . V_259 . V_174 . V_175 = 256 - V_228 -> V_229 ;
V_249 . V_259 . V_174 . V_174 = V_228 -> V_230 ;
V_249 . V_259 . V_174 . V_176 = 0 ;
V_245 =
F_50 ( V_50 , V_245 , V_246 , & V_249 ,
V_271 ) ;
V_249 . V_258 = V_272 ;
if ( V_250 & V_273 )
V_249 . V_259 . V_235 . V_82 = V_274 | V_150 ;
else
V_249 . V_259 . V_235 . V_82 = V_155 ;
V_249 . V_259 . V_235 . V_86 = 0 ;
V_245 =
F_51 ( V_50 , V_245 , V_246 , & V_249 ,
& ( V_228 -> V_83 . V_84 [ 0 ] ) ) ;
V_251 = V_245 + V_275 ;
V_249 . V_258 = V_276 ;
V_249 . V_259 . V_178 . V_103 = V_249 . V_259 . V_178 . V_127 = 0 ;
for ( V_102 = 0 ; V_102 < 16 ; V_102 ++ ) {
if ( V_102 >= V_228 -> V_105 . V_85 )
break;
V_249 . V_259 . V_178 . V_104 = ( ( V_228 -> V_105 . V_84 [ V_102 ] & 0x7f ) * 500000 ) ;
V_251 =
F_53 ( V_50 , V_245 , V_251 , V_246 ,
& V_249 , V_277 ) ;
}
if ( ( V_251 - V_245 ) > V_275 )
V_245 = V_251 ;
#define F_54 0xdd
#define F_55 0x30
if ( V_228 -> V_278 . V_279 == F_55 && V_228 -> V_278 . V_85 != 0 ) {
V_257 = & V_254 [ 0 ] ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_249 . V_258 = V_210 ;
memcpy ( V_254 , V_252 , sizeof( V_252 ) - 1 ) ;
V_249 . V_259 . V_235 . V_86 += sizeof( V_252 ) - 1 ;
V_257 += sizeof( V_252 ) - 1 ;
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_278 . V_279 ) ;
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_278 . V_85 ) ;
V_249 . V_259 . V_235 . V_86 += 4 ;
for ( V_102 = 0 ; V_102 < V_228 -> V_278 . V_85 ; V_102 ++ )
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_278 . V_84 [ V_102 ] ) ;
V_249 . V_259 . V_235 . V_86 += ( V_228 -> V_278 . V_85 ) * 2 ;
F_2 ( 4 , L_18 , V_228 -> V_278 . V_85 ) ;
V_245 =
F_51 ( V_50 , V_245 , V_246 , & V_249 ,
& V_254 [ 0 ] ) ;
}
if ( V_228 -> V_280 . V_279 == F_54 && V_228 -> V_280 . V_85 != 0 ) {
V_257 = & V_256 [ 0 ] ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_249 . V_258 = V_210 ;
memcpy ( V_256 , V_253 , sizeof( V_253 ) - 1 ) ;
V_249 . V_259 . V_235 . V_86 += sizeof( V_253 ) - 1 ;
V_257 += sizeof( V_253 ) - 1 ;
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_280 . V_279 ) ;
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_280 . V_85 ) ;
V_249 . V_259 . V_235 . V_86 += 4 ;
for ( V_102 = 0 ; V_102 < V_228 -> V_280 . V_85 ; V_102 ++ )
V_257 += sprintf ( V_257 , L_17 , V_228 -> V_280 . V_84 [ V_102 ] ) ;
V_249 . V_259 . V_235 . V_86 += ( V_228 -> V_280 . V_85 ) * 2 ;
F_2 ( 4 , L_18 , V_228 -> V_280 . V_85 ) ;
F_2 ( 4 , L_19 , V_249 . V_259 . V_235 . V_86 ) ;
V_245 =
F_51 ( V_50 , V_245 , V_246 , & V_249 ,
& V_256 [ 0 ] ) ;
}
return V_245 ;
}
static int F_56 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_79 * V_80 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_102 ;
char * V_245 = V_52 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_2 -> V_241 . V_242 & V_243 ) {
F_2 ( 2 , L_20 ) ;
return - V_281 ;
}
if ( V_2 -> V_227 . V_85 == 0 ) {
F_2 ( 2 , L_21 ) ;
return - V_282 ;
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
for ( V_102 = 0 ; V_102 < V_2 -> V_227 . V_85 ; V_102 ++ ) {
if ( ( V_52 + V_80 -> V_86 ) - V_245 <= V_260 ) {
V_80 -> V_86 = 0 ;
return - V_88 ;
}
V_245 = F_49 ( V_48 , V_50 , V_245 ,
V_52 + V_80 -> V_86 ,
& ( V_2 -> V_227 . V_228 [ V_102 ] ) ) ;
}
V_80 -> V_86 = ( V_245 - V_52 ) ;
V_80 -> V_82 = 0 ;
return 0 ;
}
static int F_57 ( struct V_47 * V_48 ,
struct V_49 * V_50 , void * V_283 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( ! V_2 -> V_73 )
return 0 ;
F_11 ( V_2 , V_2 -> V_73 ) ;
V_2 -> V_73 = 0 ;
return 0 ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
return 0 ;
}
static int F_59 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_140 = ( V_101 -> V_82 & V_284 ) ;
int V_104 = V_101 -> V_104 ;
F_2 ( 2 , L_22 , V_140 , V_104 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_140 ) {
case V_285 :
switch ( V_104 ) {
case V_286 :
V_2 -> V_287 . V_288 = V_104 ;
if ( V_2 -> V_287 . V_289 ) {
V_2 -> V_287 . V_289 = 0 ;
}
V_2 -> V_73 |= V_36 ;
break;
case V_290 :
case V_291 :
V_2 -> V_287 . V_288 = V_104 ;
if ( ! ( V_2 -> V_287 . V_289 ) ) {
V_2 -> V_287 . V_289 = 1 ;
}
V_2 -> V_73 |= V_36 ;
break;
default:
return - V_68 ;
}
break;
case V_292 :
switch ( V_104 ) {
case V_293 :
if ( V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x00 ;
V_2 -> V_73 |= V_34 ;
}
break;
case V_294 :
case V_295 :
case V_296 :
case V_297 :
if ( ! V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x01 ;
V_2 -> V_73 |= V_34 ;
}
V_2 -> V_287 . V_298 = V_104 ;
V_2 -> V_73 |= V_41 ;
break;
default:
return - V_68 ;
}
break;
case V_299 :
switch ( V_104 ) {
case V_293 :
if ( V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x00 ;
V_2 -> V_73 |= V_34 ;
}
break;
case V_294 :
case V_295 :
case V_296 :
case V_297 :
if ( ! V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x01 ;
V_2 -> V_73 |= V_34 ;
}
V_2 -> V_287 . V_300 = V_104 ;
V_2 -> V_73 |= V_39 ;
break;
default:
return - V_68 ;
}
break;
case V_301 :
switch ( V_104 ) {
case V_302 :
case V_303 :
case 0 :
case 4 :
V_2 -> V_287 . V_304 = V_104 ;
V_2 -> V_73 |= V_43 ;
break;
default:
return - V_68 ;
}
break;
case V_305 :
switch ( V_104 ) {
case V_306 :
V_2 -> V_287 . V_307 = V_104 ;
V_2 -> V_9 . V_156 = V_158 ;
break;
case V_308 :
V_2 -> V_287 . V_307 = V_104 ;
V_2 -> V_9 . V_156 = V_157 ;
break;
case V_309 :
default:
return - V_68 ;
}
V_2 -> V_73 |= V_74 ;
break;
case V_310 :
V_2 -> V_287 . V_311 = V_104 ;
break;
case V_312 :
if ( ( V_104 && ! V_2 -> V_9 . V_146 ) ||
( ! V_104 && V_2 -> V_9 . V_146 ) ) {
V_2 -> V_9 . V_146 = V_104 ? 0x01 : 0x00 ;
V_2 -> V_73 |= V_34 ;
}
break;
case V_313 :
case V_314 :
case V_315 :
case V_316 :
default:
break;
}
if ( V_2 -> V_73 ) {
F_11 ( V_2 , V_2 -> V_73 ) ;
V_2 -> V_73 = 0 ;
}
return 0 ;
}
static int F_60 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_100 * V_101 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
int V_140 = ( V_101 -> V_82 & V_284 ) ;
F_2 ( 2 , L_23 , V_140 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_140 ) {
case V_285 :
V_101 -> V_104 = V_2 -> V_287 . V_288 ;
break;
case V_292 :
V_101 -> V_104 = V_2 -> V_287 . V_298 ;
break;
case V_299 :
V_101 -> V_104 = V_2 -> V_287 . V_300 ;
break;
case V_301 :
V_101 -> V_104 = V_2 -> V_287 . V_304 ;
break;
case V_305 :
V_101 -> V_104 = V_2 -> V_287 . V_307 ;
break;
case V_310 :
V_101 -> V_104 = V_2 -> V_287 . V_289 ;
break;
case V_313 :
case V_314 :
case V_315 :
default:
break;
}
return 0 ;
}
static int F_61 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_317 * V_318 ;
int V_140 = V_80 -> V_82 & V_141 ;
unsigned int V_319 = 0 ;
V_318 = (struct V_317 * ) V_52 ;
F_2 ( 2 , L_24 , V_80 -> V_82 ,
V_318 -> V_320 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( V_140 < 1 || V_140 > 4 )
return - V_71 ;
else
V_140 -- ;
if ( V_80 -> V_82 & V_155 ) {
V_2 -> V_287 . V_139 [ V_140 ] . V_321 = 0 ;
}
if ( V_318 ) {
V_2 -> V_287 . V_139 [ V_140 ] . V_320 = V_318 -> V_320 ;
if ( V_318 -> V_320 & V_322 ) {
V_2 -> V_287 . V_323 = V_140 ;
V_319 |= V_24 ;
} else if ( V_318 -> V_320 & V_324 ) {
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] . V_325 [ 0 ] ,
V_318 -> V_325 , V_326 ) ;
}
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] . V_327 . V_94 [ 0 ] ,
& V_318 -> V_327 . V_94 [ 0 ] , V_95 ) ;
switch ( V_318 -> V_328 ) {
case V_329 :
if ( V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x00 ;
V_319 |= V_34 ;
}
V_2 -> V_287 . V_139 [ V_140 ] . V_321 = 0 ;
break;
case V_330 :
case V_331 :
if ( ! V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x01 ;
V_319 |= V_34 ;
}
if ( V_318 -> V_321 ) {
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] . V_332 [ 0 ] ,
& V_318 -> V_139 [ 0 ] , V_318 -> V_321 ) ;
V_2 -> V_287 . V_139 [ V_140 ] . V_321 = V_318 -> V_321 ;
V_319 |= ( V_26 << V_140 ) ;
}
break;
case V_333 :
if ( ! V_2 -> V_9 . V_146 ) {
V_2 -> V_9 . V_146 = 0x01 ;
V_319 |= V_34 ;
}
if ( V_318 -> V_321 == 32 ) {
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] . V_332 [ 0 ] ,
& V_318 -> V_139 [ 0 ] , V_318 -> V_321 - 16 ) ;
V_2 -> V_287 . V_139 [ V_140 ] . V_321 =
V_318 -> V_321 - 16 ;
if ( V_2 -> V_287 . V_304 == 4 ) {
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] .
V_334 [ 0 ] , & V_318 -> V_139 [ 16 ] , 8 ) ;
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] .
V_335 [ 0 ] , & V_318 -> V_139 [ 16 ] , 8 ) ;
} else {
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] .
V_334 [ 0 ] , & V_318 -> V_139 [ 16 ] , 8 ) ;
memcpy ( & V_2 -> V_287 . V_139 [ V_140 ] .
V_335 [ 0 ] , & V_318 -> V_139 [ 24 ] , 8 ) ;
}
V_319 |= ( V_26 << V_140 ) ;
}
break;
default:
return - V_71 ;
}
V_2 -> V_287 . V_139 [ V_140 ] . V_328 = V_318 -> V_328 ;
} else
return - V_71 ;
if ( V_319 ) {
if ( V_319 & V_24 )
F_5 ( V_2 , V_336 ) ;
if ( V_319 & V_337 )
F_5 ( V_2 , V_338 + V_140 ) ;
if ( V_319 & V_34 )
F_5 ( V_2 , V_35 ) ;
}
return 0 ;
}
static int F_62 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
return 0 ;
}
static int F_63 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_339 * V_340 ;
int V_102 ;
struct V_341 * V_342 ;
struct V_343 * V_17 ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ! V_52 ) {
return - V_71 ;
}
V_340 = (struct V_339 * ) V_52 ;
F_2 ( 2 , L_25 , V_340 -> V_258 ) ;
switch ( V_340 -> V_258 ) {
case V_344 :
if ( F_64 ( & V_2 -> V_345 . V_346 ) ) {
for ( V_102 = 0 ; V_102 < V_347 ; V_102 ++ ) {
V_342 = & V_2 -> V_345 . V_342 [ V_102 ] ;
if ( ! memcmp
( L_26 , V_342 -> V_93 ,
V_95 ) )
break;
}
memcpy ( V_342 -> V_93 , V_340 -> V_93 . V_94 , V_95 ) ;
memcpy ( V_342 -> V_348 , V_340 -> V_348 , V_349 ) ;
F_65 ( & V_342 -> V_350 , & V_2 -> V_345 . V_346 ) ;
V_2 -> V_345 . V_85 ++ ;
} else {
F_66 (ptr, &priv->pmklist.head) {
V_342 = F_67 ( V_17 , struct V_341 , V_350 ) ;
if ( ! memcmp ( V_340 -> V_93 . V_94 , V_342 -> V_93 , V_95 ) ) {
memcpy ( V_342 -> V_348 , V_340 -> V_348 ,
V_349 ) ;
F_68 ( & V_342 -> V_350 ,
& V_2 -> V_345 . V_346 ) ;
break;
}
}
if ( V_17 == & V_2 -> V_345 . V_346 ) {
if ( V_347 > V_2 -> V_345 . V_85 ) {
for ( V_102 = 0 ; V_102 < V_347 ; V_102 ++ ) {
V_342 = & V_2 -> V_345 . V_342 [ V_102 ] ;
if ( ! memcmp
( L_26 ,
V_342 -> V_93 , V_95 ) )
break;
}
memcpy ( V_342 -> V_93 , V_340 -> V_93 . V_94 ,
V_95 ) ;
memcpy ( V_342 -> V_348 , V_340 -> V_348 ,
V_349 ) ;
F_65 ( & V_342 -> V_350 ,
& V_2 -> V_345 . V_346 ) ;
V_2 -> V_345 . V_85 ++ ;
} else {
V_342 =
F_67 ( V_2 -> V_345 . V_346 . V_351 ,
struct V_341 , V_350 ) ;
memcpy ( V_342 -> V_93 , V_340 -> V_93 . V_94 ,
V_95 ) ;
memcpy ( V_342 -> V_348 , V_340 -> V_348 ,
V_349 ) ;
F_68 ( & V_342 -> V_350 ,
& V_2 -> V_345 . V_346 ) ;
}
}
}
break;
case V_352 :
if ( F_64 ( & V_2 -> V_345 . V_346 ) ) {
return - V_71 ;
} else {
F_66 (ptr, &priv->pmklist.head) {
V_342 = F_67 ( V_17 , struct V_341 , V_350 ) ;
if ( ! memcmp ( V_340 -> V_93 . V_94 , V_342 -> V_93 , V_95 ) ) {
F_21 ( V_342 -> V_93 ) ;
memset ( V_342 -> V_348 , 0 , V_349 ) ;
F_69 ( & V_342 -> V_350 ) ;
break;
}
}
if ( V_17 == & V_2 -> V_345 . V_346 ) {
return 0 ;
}
}
break;
case V_353 :
memset ( & ( V_2 -> V_345 ) , 0 , sizeof( V_2 -> V_345 ) ) ;
F_70 ( & V_2 -> V_345 . V_346 ) ;
for ( V_102 = 0 ; V_102 < V_347 ; V_102 ++ )
F_70 ( & V_2 -> V_345 . V_342 [ V_102 ] . V_350 ) ;
break;
default:
return - V_71 ;
}
F_5 ( V_2 , V_354 ) ;
return 0 ;
}
static struct V_3 * F_71 ( struct V_47 * V_48 )
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
V_4 -> V_355 . V_356 = 0 ;
V_4 -> V_355 . V_357 = 0 ;
V_4 -> V_355 . V_130 = 0 ;
V_4 -> V_355 . V_358 = 0 ;
V_4 -> V_355 . V_359 = 0 ;
V_4 -> V_360 . V_361 = 0 ;
return V_4 ;
}
static int F_72 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( ! ( * V_131 ) )
return - V_71 ;
F_5 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_73 ( struct V_47 * V_48 ,
struct V_49 * V_50 , struct V_79 * V_80 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
struct V_362 * V_363 = (struct V_362 * ) V_52 ;
T_2 V_266 ;
F_2 ( 2 , L_27 , V_363 -> V_258 , V_363 -> V_364 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
switch ( V_363 -> V_258 ) {
case V_365 :
if ( V_363 -> V_364 == V_366 ) {
return 0 ;
}
case V_367 :
V_266 = 1 ;
return F_72 ( V_48 , NULL , & V_266 , NULL ) ;
default:
return - V_68 ;
}
}
static int F_74 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
strcpy ( V_52 , & ( V_2 -> V_368 [ 0 ] ) ) ;
V_80 -> V_86 = V_2 -> V_369 + 1 ;
return 0 ;
}
static int F_75 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == V_370 ) {
V_2 -> V_9 . V_371 = V_370 ;
} else if ( * V_131 == V_372 ) {
V_2 -> V_9 . V_371 = V_372 ;
} else
return - V_71 ;
V_2 -> V_73 |= V_74 ;
return - V_62 ;
}
static int F_76 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_371 ;
return 0 ;
}
static int F_77 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == V_219 ) {
V_2 -> V_9 . V_218 = V_219 ;
} else if ( * V_131 == V_220 ) {
if ( V_2 -> V_9 . V_10 == V_92 )
V_2 -> V_9 . V_218 = V_220 ;
else
return - V_71 ;
} else if ( * V_131 == V_221 ) {
if ( V_2 -> V_9 . V_10 == V_92 )
V_2 -> V_9 . V_218 = V_221 ;
else
return - V_71 ;
} else
return - V_71 ;
F_5 ( V_2 , V_222 ) ;
return 0 ;
}
static int F_78 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_218 ;
return 0 ;
}
static int F_79 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == V_373 ) {
V_2 -> V_9 . V_374 = V_373 ;
} else if ( * V_131 == V_375 ) {
V_2 -> V_9 . V_374 = V_375 ;
} else
return - V_71 ;
return 0 ;
}
static int F_80 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_374 ;
return 0 ;
}
static int F_81 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 >= V_376 && * V_131 <= V_377 ) {
V_2 -> V_9 . V_378 = * V_131 ;
} else
return - V_71 ;
if ( V_2 -> V_9 . V_10 == V_92 ) {
V_2 -> V_73 |= V_74 ;
return - V_62 ;
} else
return 0 ;
}
static int F_82 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_378 ;
return 0 ;
}
static int F_83 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == V_57 ) {
V_2 -> V_9 . V_56 = V_57 ;
} else if ( * V_131 == V_58 ) {
V_2 -> V_9 . V_56 = V_58 ;
} else if ( * V_131 == V_172 ) {
V_2 -> V_9 . V_56 = V_172 ;
} else
return - V_71 ;
V_2 -> V_73 |= V_74 ;
return - V_62 ;
}
static int F_84 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_56 ;
return 0 ;
}
static int F_85 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == V_379 ) {
V_2 -> V_9 . V_380 = V_379 ;
} else if ( * V_131 == V_381 ) {
if ( V_2 -> V_9 . V_56 == V_58 ||
V_2 -> V_9 . V_56 == V_172 )
V_2 -> V_9 . V_380 = V_381 ;
else
V_2 -> V_9 . V_380 = V_379 ;
} else
return - V_71 ;
V_2 -> V_73 |= V_74 ;
return - V_62 ;
}
static int F_86 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_9 . V_380 ;
return 0 ;
}
static int F_87 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
T_2 * V_131 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( * V_131 == V_54 ) {
V_2 -> V_53 = * V_131 ;
F_88 ( V_48 , L_28 , V_2 -> V_53 ) ;
F_5 ( V_2 , V_19 ) ;
F_5 ( V_2 , V_382 ) ;
} else if ( * V_131 == V_383 ) {
V_2 -> V_53 = * V_131 ;
F_88 ( V_48 , L_28 , V_2 -> V_53 ) ;
F_5 ( V_2 , V_382 ) ;
} else {
F_89 ( V_48 , L_29 , * V_131 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_90 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
T_2 * V_131 , char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_30 , V_2 -> V_53 ) ;
* V_131 = V_2 -> V_53 ;
return 0 ;
}
static int F_91 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 == 0 || * V_131 == 1 )
V_2 -> V_384 . V_385 = * V_131 ;
else
return - V_71 ;
F_5 ( V_2 , V_386 ) ;
return 0 ;
}
static int F_92 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_384 . V_385 ;
F_88 ( V_48 , L_31 , * V_131 ) ;
return 0 ;
}
static int F_93 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_79 * V_80 , char * V_52 )
{
V_106 * V_387 = V_52 ;
unsigned char V_81 ;
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
F_2 ( 2 , L_3 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
F_2 ( 2 , L_32 , V_80 -> V_86 ) ;
if ( V_387 [ 1 ] + 2 != V_80 -> V_86 || V_80 -> V_86 > 256 ) {
return - V_71 ;
}
V_2 -> V_384 . V_388 = V_387 [ 1 ] + 2 + 1 ;
V_81 = V_387 [ 1 ] + 2 ;
memcpy ( V_2 -> V_384 . V_389 , & V_81 , sizeof( V_81 ) ) ;
V_387 = memcpy ( V_2 -> V_384 . V_389 + 1 , V_387 , V_81 ) ;
F_2 ( 2 , L_33 ,
V_2 -> V_384 . V_388 , V_2 -> V_384 . V_388 , V_387 [ 0 ] , V_387 [ 1 ] , V_387 [ 2 ] , V_387 [ 3 ] ,
V_387 [ V_2 -> V_384 . V_388 - 3 ] , V_387 [ V_2 -> V_384 . V_388 - 2 ] ,
V_387 [ V_2 -> V_384 . V_388 - 1 ] ) ;
F_5 ( V_2 , V_390 ) ;
return 0 ;
}
static int F_94 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 >= 0 && * V_131 <= 0xFF )
V_2 -> V_391 . V_392 = ( V_106 ) * V_131 ;
else
return - V_71 ;
if ( V_2 -> V_391 . V_392 < 0xFF )
V_2 -> V_391 . V_393 = 1 ;
else
V_2 -> V_391 . V_393 = 0 ;
F_5 ( V_2 , V_394 ) ;
return 0 ;
}
static int F_95 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_391 . V_392 ;
F_5 ( V_2 , V_395 ) ;
return 0 ;
}
static int F_96 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
if ( * V_131 >= 0 && * V_131 <= 0xFF )
V_2 -> V_391 . V_396 = ( V_106 ) * V_131 ;
else
return - V_71 ;
if ( V_2 -> V_391 . V_396 < 0xFF )
V_2 -> V_391 . V_397 = 1 ;
else
V_2 -> V_391 . V_397 = 0 ;
F_5 ( V_2 , V_394 ) ;
return 0 ;
}
static int F_97 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
if ( V_2 -> V_53 == V_54 ) {
return - V_55 ;
}
* V_131 = V_2 -> V_391 . V_396 ;
F_5 ( V_2 , V_395 ) ;
return 0 ;
}
static int F_98 ( struct V_47 * V_48 ,
struct V_49 * V_50 , T_2 * V_131 ,
char * V_52 )
{
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
* V_131 = V_2 -> V_398 ;
return 0 ;
}
static void F_99 ( struct V_47 * V_48 , int V_399 )
{
switch ( V_399 ) {
case V_400 :
F_88 ( V_48 , L_34 ) ;
break;
case V_401 :
F_88 ( V_48 , L_35 ) ;
break;
case V_402 :
F_88 ( V_48 , L_36 ) ;
break;
case V_403 :
F_88 ( V_48 , L_37 ) ;
break;
case V_404 :
F_88 ( V_48 , L_38 ) ;
break;
case V_405 :
F_88 ( V_48 , L_39 ) ;
break;
case V_406 :
F_88 ( V_48 , L_40 ) ;
break;
case V_407 :
F_88 ( V_48 , L_41 ) ;
break;
case V_408 :
F_88 ( V_48 , L_42 ) ;
break;
case V_409 :
F_88 ( V_48 , L_43 ) ;
break;
case V_410 :
F_88 ( V_48 , L_44 ) ;
break;
case V_411 :
F_88 ( V_48 , L_45 ) ;
break;
case V_412 :
F_88 ( V_48 , L_46 ) ;
break;
case V_413 :
F_88 ( V_48 , L_47 ) ;
break;
case V_414 :
F_88 ( V_48 , L_48 ) ;
break;
case V_415 :
F_88 ( V_48 , L_49 ) ;
break;
case V_416 :
F_88 ( V_48 , L_50 ) ;
break;
case V_417 :
F_88 ( V_48 , L_51 ) ;
break;
case V_418 :
F_88 ( V_48 , L_52 ) ;
break;
case V_419 :
F_88 ( V_48 , L_53 ) ;
break;
case V_420 :
F_88 ( V_48 , L_54 ) ;
break;
case V_421 :
F_88 ( V_48 , L_55 ) ;
break;
case V_422 :
F_88 ( V_48 , L_56 ) ;
break;
case V_423 :
F_88 ( V_48 , L_57 ) ;
break;
case V_424 :
F_88 ( V_48 , L_58 ) ;
break;
case V_425 :
F_88 ( V_48 , L_59 ) ;
break;
case V_426 :
F_88 ( V_48 , L_60 ) ;
break;
case V_427 :
F_88 ( V_48 , L_61 ) ;
break;
case V_428 :
F_88 ( V_48 , L_62 ) ;
break;
case V_429 :
F_88 ( V_48 , L_63 ) ;
break;
case V_430 :
F_88 ( V_48 , L_64 ) ;
break;
case V_431 :
F_88 ( V_48 , L_65 ) ;
break;
case V_432 :
F_88 ( V_48 , L_66 ) ;
break;
case V_433 :
F_88 ( V_48 , L_67 ) ;
break;
case V_434 :
F_88 ( V_48 , L_68 ) ;
break;
case V_435 :
F_88 ( V_48 , L_69 ) ;
}
}
static int F_100 ( struct V_47 * V_48 , struct V_49 * V_50 ,
T_2 * V_131 , char * V_52 )
{
int V_102 , V_399 ;
struct V_1 * V_2 =
(struct V_1 * ) F_13 ( V_48 ) ;
for ( V_102 = 63 ; V_102 >= 0 ; V_102 -- ) {
V_399 =
V_2 -> V_436 . V_437 [ ( V_2 -> V_436 . V_438 - 1 - V_102 ) %
V_439 ] ;
F_99 ( V_48 , V_399 ) ;
}
return 0 ;
}
static int F_101 ( struct V_47 * V_48 , struct V_440 * V_441 ,
int V_258 )
{
int V_61 = 0 ;
struct V_442 * V_443 = (struct V_442 * ) V_441 ;
switch ( V_258 ) {
case V_444 + 20 :
V_61 = F_72 ( V_48 , NULL , & ( V_443 -> V_259 . V_266 ) , NULL ) ;
break;
default:
V_61 = - V_68 ;
}
F_2 ( 5 , L_31 , V_61 ) ;
return V_61 ;
}
static
struct V_445 * F_102 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
if ( V_2 -> V_5 < V_6 ) {
return NULL ;
}
return & V_2 -> V_446 ;
}
static
int F_103 ( struct V_47 * V_48 , void * V_327 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
struct V_89 * V_447 = (struct V_89 * ) V_327 ;
if ( F_104 ( V_48 ) )
return - V_448 ;
memcpy ( V_48 -> V_449 , V_447 -> V_94 , V_48 -> V_450 ) ;
memcpy ( V_2 -> V_451 , V_447 -> V_94 , V_95 ) ;
V_2 -> V_452 = 0 ;
F_5 ( V_2 , V_453 ) ;
F_88 ( V_48 ,
L_70 ,
V_2 -> V_451 [ 0 ] , V_2 -> V_451 [ 1 ] , V_2 -> V_451 [ 2 ] ,
V_2 -> V_451 [ 3 ] , V_2 -> V_451 [ 4 ] , V_2 -> V_451 [ 5 ] ) ;
return 0 ;
}
static
void F_105 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
F_2 ( 1 , L_71 , V_2 -> V_454 . V_455 ,
V_2 -> V_454 . V_438 ) ;
if ( ! F_106 ( V_48 ) ) {
F_107 ( V_48 ) ;
}
V_2 -> V_446 . V_456 ++ ;
F_108 ( V_48 ) ;
}
static
int F_109 ( struct V_457 * V_458 , struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
int V_61 = 0 ;
F_2 ( 3 , L_72 , F_3 () ) ;
if ( ! V_458 ) {
F_89 ( V_48 , L_73 ) ;
return 0 ;
}
if ( V_2 -> V_5 < V_6 ) {
F_110 ( V_458 ) ;
return 0 ;
}
if ( F_104 ( V_48 ) )
F_107 ( V_48 ) ;
V_61 = F_111 ( V_2 , V_458 ) ;
F_112 ( V_48 ) ;
F_2 ( 4 , L_74 , V_61 ) ;
if ( V_61 ) {
V_61 = 0 ;
}
return V_61 ;
}
void F_113 ( void * V_459 , void * V_460 )
{
struct V_1 * V_2 = (struct V_1 * ) V_459 ;
struct V_457 * V_461 = (struct V_457 * ) V_460 ;
F_2 ( 3 , L_3 ) ;
V_2 -> V_446 . V_462 ++ ;
if ( F_106 ( V_2 -> V_463 ) )
F_108 ( V_2 -> V_463 ) ;
if ( V_461 ) {
V_2 -> V_446 . V_464 += V_461 -> V_81 ;
F_110 ( V_461 ) ;
V_461 = NULL ;
}
}
static
void F_114 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
F_2 ( 4 , L_3 ) ;
if ( V_2 -> V_5 < V_6 ) {
return;
}
F_5 ( V_2 , V_465 ) ;
}
static
int F_115 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
V_2 -> V_466 = 0 ;
if ( ! V_2 -> V_452 ) {
F_89 ( V_48 , L_75 , V_48 -> V_70 ) ;
return - V_448 ;
} else
F_116 ( V_48 ) ;
return 0 ;
}
static
int F_117 ( struct V_47 * V_48 )
{
F_107 ( V_48 ) ;
F_2 ( 4 , L_76 ,
V_48 -> V_70 , 0x00 ) ;
return 0 ;
}
int F_118 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_48 ) ;
V_2 -> V_452 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_467 = 1 ;
F_10 ( & V_7 , 0 ) ;
F_119 ( & V_14 ) ;
V_14 . V_468 = F_9 ;
V_14 . V_235 = ( unsigned long ) V_2 ;
memcpy ( V_2 -> V_451 , V_469 , V_95 ) ;
V_48 -> V_449 [ 0 ] = V_2 -> V_451 [ 0 ] ;
V_48 -> V_449 [ 1 ] = V_2 -> V_451 [ 1 ] ;
V_48 -> V_449 [ 2 ] = V_2 -> V_451 [ 2 ] ;
V_48 -> V_449 [ 3 ] = V_2 -> V_451 [ 3 ] ;
V_48 -> V_449 [ 4 ] = V_2 -> V_451 [ 4 ] ;
V_48 -> V_449 [ 5 ] = V_2 -> V_451 [ 5 ] ;
V_48 -> V_449 [ 6 ] = 0x00 ;
V_48 -> V_449 [ 7 ] = 0x00 ;
V_48 -> V_470 = & V_471 ;
V_48 -> V_472 = (struct V_473 * ) & V_474 ;
V_48 -> V_475 = V_476 ;
F_120 ( V_48 ) ;
return 0 ;
}
int F_121 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 ) ;
V_2 -> V_467 = 0 ;
F_122 ( & V_14 ) ;
if ( F_104 ( V_48 ) )
F_107 ( V_48 ) ;
return 0 ;
}
