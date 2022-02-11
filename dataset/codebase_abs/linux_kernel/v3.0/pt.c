static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , 1 , 6 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , 0 , V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_5 ( V_2 , 0 , V_3 , V_4 ) ;
}
static inline T_1 F_6 ( struct V_5 * V_6 )
{
return 0xa0 + 0x10 * V_6 -> V_7 ;
}
static int F_7 ( struct V_5 * V_6 , int V_8 , int V_9 , char * V_10 , char * V_11 )
{
int V_12 , V_13 , V_14 , V_15 , V_16 ;
struct V_1 * V_2 = V_6 -> V_2 ;
V_12 = 0 ;
while ( ( ( ( V_13 = F_1 ( V_2 ) ) & V_8 ) || ( V_9 && ( ! ( V_13 & V_9 ) ) ) )
&& ( V_12 ++ < V_17 ) )
F_8 ( V_18 ) ;
if ( ( V_13 & ( V_19 & V_9 ) ) || ( V_12 > V_17 ) ) {
V_15 = F_3 ( V_2 , 7 ) ;
V_14 = F_3 ( V_2 , 1 ) ;
V_16 = F_3 ( V_2 , 2 ) ;
if ( V_12 > V_17 )
V_14 |= 0x100 ;
if ( V_10 )
F_9 ( L_1
L_2 ,
V_6 -> V_20 , V_10 , V_11 , V_13 , V_15 , V_14 , V_12 , V_16 ) ;
return ( V_14 << 8 ) + V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , char * V_21 , int V_22 , char * V_10 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
F_11 ( V_2 ) ;
F_4 ( V_2 , 6 , F_6 ( V_6 ) ) ;
if ( F_7 ( V_6 , V_23 | V_24 , 0 , V_10 , L_3 ) ) {
F_12 ( V_2 ) ;
return - 1 ;
}
F_4 ( V_2 , 4 , V_22 % 256 ) ;
F_4 ( V_2 , 5 , V_22 / 256 ) ;
F_4 ( V_2 , 7 , 0xa0 ) ;
if ( F_7 ( V_6 , V_23 , V_24 , V_10 , L_4 ) ) {
F_12 ( V_2 ) ;
return - 1 ;
}
if ( F_3 ( V_2 , 2 ) != 1 ) {
F_9 ( L_5 , V_6 -> V_20 , V_10 ) ;
F_12 ( V_2 ) ;
return - 1 ;
}
F_13 ( V_2 , V_21 , 12 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , char * V_25 , char * V_10 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_13 , V_15 , V_26 , V_16 ;
V_13 = F_7 ( V_6 , V_23 , V_24 | V_27 | V_19 ,
V_10 , L_6 ) ;
if ( F_3 ( V_2 , 7 ) & V_24 ) {
V_26 = ( ( ( F_3 ( V_2 , 4 ) + 256 * F_3 ( V_2 , 5 ) ) +
3 ) & 0xfffc ) ;
V_16 = F_3 ( V_2 , 2 ) & 3 ;
if ( V_16 == 0 )
F_13 ( V_2 , V_25 , V_26 ) ;
if ( V_16 == 2 )
F_15 ( V_2 , V_25 , V_26 ) ;
}
V_15 = F_7 ( V_6 , V_23 , V_27 | V_19 , V_10 , L_7 ) ;
F_12 ( V_2 ) ;
return ( V_13 ? V_13 : V_15 ) ;
}
static void F_16 ( struct V_5 * V_6 , int V_28 )
{
char V_29 [ 12 ] = { V_30 , 0 , 0 , 0 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_25 [ 16 ] ;
int V_13 ;
V_13 = F_10 ( V_6 , V_29 , 16 , L_8 ) ;
F_17 ( 1 ) ;
if ( ! V_13 )
F_14 ( V_6 , V_25 , L_8 ) ;
V_6 -> V_31 = - 1 ;
if ( ! V_13 ) {
if ( ! V_28 )
F_9 ( L_9 ,
V_6 -> V_20 , V_25 [ 2 ] & 0xf , V_25 [ 12 ] , V_25 [ 13 ] ) ;
V_6 -> V_31 = ( V_25 [ 2 ] & 0xf ) | ( ( V_25 [ 12 ] & 0xff ) << 8 )
| ( ( V_25 [ 13 ] & 0xff ) << 16 ) ;
}
}
static int F_18 ( struct V_5 * V_6 , char * V_21 , int V_22 , char * V_25 , char * V_10 )
{
int V_13 ;
V_13 = F_10 ( V_6 , V_21 , V_22 , V_10 ) ;
F_17 ( 1 ) ;
if ( ! V_13 )
V_13 = F_14 ( V_6 , V_25 , V_10 ) ;
if ( V_13 )
F_16 ( V_6 , ! V_10 ) ;
return V_13 ;
}
static void F_19 ( int V_32 )
{
F_20 ( V_32 ) ;
}
static int F_21 ( struct V_5 * V_6 , int V_33 , int V_34 , char * V_11 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_35 , V_14 , V_15 ;
V_35 = 0 ;
V_14 = 0 ;
V_15 = 0 ;
while ( V_35 < V_34 ) {
F_19 ( V_33 ) ;
V_35 ++ ;
F_11 ( V_2 ) ;
F_4 ( V_2 , 6 , F_6 ( V_6 ) ) ;
V_15 = F_3 ( V_2 , 7 ) ;
V_14 = F_3 ( V_2 , 1 ) ;
F_12 ( V_2 ) ;
if ( V_15 & ( V_19 | V_36 ) )
break;
}
if ( ( V_35 >= V_34 ) || ( V_15 & V_19 ) ) {
if ( V_35 >= V_34 )
F_9 ( L_10 , V_6 -> V_20 , V_11 ) ;
else
F_9 ( L_11 , V_6 -> V_20 , V_11 , V_15 ,
V_14 ) ;
F_16 ( V_6 , 0 ) ;
return 0 ;
}
return 1 ;
}
static void F_22 ( struct V_5 * V_6 , int V_34 , char * V_21 , char * V_10 )
{
if ( F_10 ( V_6 , V_21 , 0 , V_10 ) ) {
F_16 ( V_6 , 0 ) ;
return;
}
F_12 ( V_6 -> V_2 ) ;
F_21 ( V_6 , V_37 , V_34 , V_10 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
char V_38 [ 12 ] = { V_39 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_22 ( V_6 , V_40 , V_38 , L_12 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
char V_41 [ 12 ] = { V_42 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_22 ( V_6 , V_43 , V_41 , L_13 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_44 , V_35 , V_45 ;
int V_46 [ 5 ] = { 1 , 1 , 1 , 0x14 , 0xeb } ;
F_11 ( V_2 ) ;
F_4 ( V_2 , 6 , F_6 ( V_6 ) ) ;
F_4 ( V_2 , 7 , 8 ) ;
F_19 ( 20 * V_37 / 1000 ) ;
V_35 = 0 ;
while ( ( V_35 ++ < V_47 ) && ( F_1 ( V_2 ) & V_23 ) )
F_19 ( V_37 / 10 ) ;
V_45 = 1 ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ )
V_45 &= ( F_3 ( V_2 , V_44 + 1 ) == V_46 [ V_44 ] ) ;
if ( V_48 ) {
F_9 ( L_14 , V_6 -> V_20 , V_35 ) ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ )
F_9 ( L_15 , F_3 ( V_2 , V_44 + 1 ) ) ;
if ( ! V_45 )
F_9 ( L_16 ) ;
F_9 ( L_17 ) ;
}
F_12 ( V_2 ) ;
return V_45 - 1 ;
}
static int F_26 ( struct V_5 * V_6 , int V_34 )
{
char V_49 [ 12 ] = { V_50 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_35 , V_16 ;
V_35 = 0 ;
while ( V_35 < V_34 ) {
V_6 -> V_31 = 0 ;
F_18 ( V_6 , V_49 , 0 , NULL , F_27 ( L_18 ) ) ;
V_16 = V_6 -> V_31 ;
if ( ! V_16 )
return 0 ;
if ( ! ( ( ( V_16 & 0xffff ) == 0x0402 ) || ( ( V_16 & 0xff ) == 6 ) ) )
return V_16 ;
V_35 ++ ;
F_19 ( V_37 ) ;
}
return 0x000020 ;
}
static void F_28 ( char * V_25 , char * V_51 , int V_52 , int V_53 )
{
int V_12 , V_35 , V_54 ;
V_12 = 0 ;
V_54 = 0 ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ )
if ( ( V_25 [ V_35 + V_52 ] != 0x20 ) || ( V_25 [ V_35 + V_52 ] != V_54 ) )
V_54 = V_51 [ V_12 ++ ] = V_25 [ V_35 + V_52 ] ;
if ( V_54 == 0x20 )
V_12 -- ;
V_51 [ V_12 ] = 0 ;
}
static int F_29 ( char * V_25 , int V_52 , int V_55 )
{
int V_56 , V_35 ;
V_56 = 0 ;
for ( V_35 = 0 ; V_35 < V_55 ; V_35 ++ )
V_56 = V_56 * 256 + ( V_25 [ V_35 + V_52 ] & 0xff ) ;
return V_56 ;
}
static int F_30 ( struct V_5 * V_6 )
{
int V_57 , V_15 ;
char * V_58 [ 2 ] = { L_19 , L_20 } ;
char V_59 [ 10 ] , V_60 [ 18 ] ;
char V_61 [ 12 ] = { V_62 , 0 , 0 , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_63 [ 12 ] =
{ V_64 , 0 , 0x2a , 0 , 36 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
char V_65 [ 12 ] =
{ V_66 , 0 , 0x71 , 0 , 0 , 0 , 0 , 0 , 36 , 0 , 0 , 0 } ;
char V_25 [ 36 ] ;
V_15 = F_18 ( V_6 , V_61 , 36 , V_25 , L_21 ) ;
if ( V_15 )
return - 1 ;
V_57 = V_25 [ 0 ] & 0x1f ;
if ( V_57 != 1 ) {
if ( V_48 )
F_9 ( L_22 ,
V_6 -> V_20 , V_6 -> V_7 , V_57 ) ;
return - 1 ;
}
F_28 ( V_25 , V_59 , 8 , 8 ) ;
F_28 ( V_25 , V_60 , 16 , 16 ) ;
V_6 -> V_67 = 0 ;
V_6 -> V_68 = 0 ;
V_6 -> V_69 = 0 ;
if ( ! F_26 ( V_6 , V_70 ) )
V_6 -> V_67 |= V_71 ;
if ( ! F_18 ( V_6 , V_63 , 36 , V_25 , L_23 ) ) {
if ( ! ( V_25 [ 2 ] & 0x80 ) )
V_6 -> V_67 |= V_72 ;
V_6 -> V_69 = F_29 ( V_25 , 10 , 2 ) ;
}
if ( ! F_18 ( V_6 , V_65 , 36 , V_25 , L_24 ) )
V_6 -> V_68 = F_29 ( V_25 , 24 , 4 ) ;
F_9 ( L_25 , V_6 -> V_20 , V_59 , V_60 , V_58 [ V_6 -> V_7 ] ) ;
if ( ! ( V_6 -> V_67 & V_71 ) )
F_9 ( L_26 ) ;
else {
if ( ! ( V_6 -> V_67 & V_72 ) )
F_9 ( L_27 ) ;
F_9 ( L_28 , V_6 -> V_69 , V_6 -> V_68 / 1024 ) ;
}
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
if ( V_6 -> V_7 == - 1 ) {
for ( V_6 -> V_7 = 0 ; V_6 -> V_7 <= 1 ; V_6 -> V_7 ++ )
if ( ! F_25 ( V_6 ) )
return F_30 ( V_6 ) ;
} else {
if ( ! F_25 ( V_6 ) )
return F_30 ( V_6 ) ;
}
return - 1 ;
}
static int F_32 ( void )
{
struct V_5 * V_6 ;
int V_73 = 0 , V_74 = 0 ;
int V_75 ;
F_9 ( L_29 , V_20 , V_20 , V_76 , V_77 ) ;
V_73 = 0 ;
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ ) {
struct V_5 * V_6 = & V_79 [ V_75 ] ;
V_6 -> V_2 = & V_6 -> V_80 ;
F_33 ( & V_6 -> V_81 , 1 ) ;
V_6 -> V_67 = 0 ;
V_6 -> V_31 = 0 ;
V_6 -> V_82 = 0 ;
V_6 -> V_83 = NULL ;
V_6 -> V_7 = V_84 [ V_85 ] ;
snprintf ( V_6 -> V_20 , V_86 , L_30 , V_20 , V_75 ) ;
if ( ! V_84 [ V_87 ] )
continue;
V_73 ++ ;
if ( F_34 ( V_6 -> V_2 , 0 , V_84 [ V_87 ] , V_84 [ V_88 ] , V_84 [ V_89 ] ,
V_84 [ V_90 ] , V_84 [ V_91 ] , V_92 , V_93 ,
V_48 , V_6 -> V_20 ) ) {
if ( ! F_31 ( V_6 ) ) {
V_6 -> V_82 = 1 ;
V_74 ++ ;
} else
F_35 ( V_6 -> V_2 ) ;
}
}
if ( V_73 == 0 ) {
V_6 = V_79 ;
if ( F_34 ( V_6 -> V_2 , 1 , - 1 , - 1 , - 1 , - 1 , - 1 , V_92 ,
V_93 , V_48 , V_6 -> V_20 ) ) {
if ( ! F_31 ( V_6 ) ) {
V_6 -> V_82 = 1 ;
V_74 ++ ;
} else
F_35 ( V_6 -> V_2 ) ;
}
}
if ( V_74 )
return 0 ;
F_9 ( L_31 , V_20 ) ;
return - 1 ;
}
static int F_36 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
int V_75 = F_37 ( V_94 ) & 0x7F ;
struct V_5 * V_6 = V_79 + V_75 ;
int V_96 ;
F_38 ( & V_97 ) ;
if ( V_75 >= V_78 || ( ! V_6 -> V_82 ) ) {
F_39 ( & V_97 ) ;
return - V_98 ;
}
V_96 = - V_99 ;
if ( ! F_40 ( & V_6 -> V_81 ) )
goto V_100;
F_30 ( V_6 ) ;
V_96 = - V_98 ;
if ( ! ( V_6 -> V_67 & V_71 ) )
goto V_100;
V_96 = - V_101 ;
if ( ( ! ( V_6 -> V_67 & V_72 ) ) && ( V_95 -> V_102 & V_103 ) )
goto V_100;
if ( ! ( F_37 ( V_94 ) & 128 ) )
V_6 -> V_67 |= V_104 ;
V_96 = - V_105 ;
V_6 -> V_83 = F_41 ( V_106 , V_107 ) ;
if ( V_6 -> V_83 == NULL ) {
F_9 ( L_32 , V_6 -> V_20 ) ;
goto V_100;
}
V_95 -> V_108 = V_6 ;
F_39 ( & V_97 ) ;
return 0 ;
V_100:
F_42 ( & V_6 -> V_81 ) ;
F_39 ( & V_97 ) ;
return V_96 ;
}
static long F_43 ( struct V_95 * V_95 , unsigned int V_21 , unsigned long V_109 )
{
struct V_5 * V_6 = V_95 -> V_108 ;
struct V_110 T_2 * V_16 = ( void T_2 * ) V_109 ;
struct V_110 V_110 ;
switch ( V_21 ) {
case V_111 :
if ( F_44 ( & V_110 , V_16 , sizeof( struct V_110 ) ) )
return - V_112 ;
switch ( V_110 . V_113 ) {
case V_114 :
F_38 ( & V_97 ) ;
F_23 ( V_6 ) ;
F_39 ( & V_97 ) ;
return 0 ;
case V_115 :
F_38 ( & V_97 ) ;
F_24 ( V_6 ) ;
F_39 ( & V_97 ) ;
return 0 ;
default:
F_9 ( V_116 L_33 , V_6 -> V_20 ,
V_110 . V_113 ) ;
return - V_117 ;
}
default:
return - V_118 ;
}
}
static int
F_45 ( struct V_94 * V_94 , struct V_95 * V_95 )
{
struct V_5 * V_6 = V_95 -> V_108 ;
if ( F_46 ( & V_6 -> V_81 ) > 1 )
return - V_117 ;
if ( V_6 -> V_67 & V_119 )
F_24 ( V_6 ) ;
if ( V_6 -> V_67 & V_104 )
F_23 ( V_6 ) ;
F_47 ( V_6 -> V_83 ) ;
V_6 -> V_83 = NULL ;
F_42 ( & V_6 -> V_81 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_95 * V_120 , char T_2 * V_25 , T_4 V_121 , T_5 * V_122 )
{
struct V_5 * V_6 = V_120 -> V_108 ;
struct V_1 * V_2 = V_6 -> V_2 ;
char V_123 [ 12 ] = { V_124 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_35 , V_26 , V_13 , V_16 , V_15 , V_125 , V_126 ;
if ( ! ( V_6 -> V_67 & ( V_127 | V_119 ) ) ) {
V_6 -> V_67 |= V_127 ;
if ( F_18 ( V_6 , V_123 , 0 , NULL , L_34 ) )
return - V_128 ;
} else if ( V_6 -> V_67 & V_119 )
return - V_128 ;
if ( V_6 -> V_67 & V_129 )
return 0 ;
V_125 = 0 ;
while ( V_121 > 0 ) {
if ( ! F_21 ( V_6 , V_37 / 100 , V_43 , L_35 ) )
return - V_128 ;
V_26 = V_121 ;
if ( V_26 > 32768 )
V_26 = 32768 ;
V_126 = ( V_26 - 1 + V_6 -> V_69 ) / V_6 -> V_69 ;
V_26 = V_126 * V_6 -> V_69 ;
V_123 [ 4 ] = V_126 ;
V_13 = F_10 ( V_6 , V_123 , V_26 , L_35 ) ;
F_17 ( 1 ) ;
if ( V_13 ) {
F_16 ( V_6 , 0 ) ;
return - V_128 ;
}
while ( 1 ) {
V_13 = F_7 ( V_6 , V_23 ,
V_24 | V_19 | V_27 ,
F_27 ( L_36 ) , L_37 ) ;
if ( V_13 & V_130 ) {
F_12 ( V_2 ) ;
F_16 ( V_6 , 0 ) ;
return - V_128 ;
}
if ( V_13 )
V_6 -> V_67 |= V_129 ;
V_15 = F_3 ( V_2 , 7 ) ;
if ( ! ( V_15 & V_24 ) )
break;
V_26 = ( F_3 ( V_2 , 4 ) + 256 * F_3 ( V_2 , 5 ) ) ;
V_16 = ( F_3 ( V_2 , 2 ) & 3 ) ;
if ( V_16 != 2 ) {
F_12 ( V_2 ) ;
F_9 ( L_38 , V_6 -> V_20 ,
V_16 ) ;
return - V_128 ;
}
while ( V_26 > 0 ) {
V_35 = V_26 ;
if ( V_35 > V_106 )
V_35 = V_106 ;
F_15 ( V_2 , V_6 -> V_83 , V_35 ) ;
V_26 -= V_35 ;
V_126 = V_35 ;
if ( V_126 > V_121 )
V_126 = V_121 ;
if ( F_49 ( V_25 + V_125 , V_6 -> V_83 , V_126 ) ) {
F_12 ( V_2 ) ;
return - V_112 ;
}
V_125 += V_126 ;
V_121 -= V_126 ;
}
}
F_12 ( V_2 ) ;
if ( V_6 -> V_67 & V_129 )
break;
}
return V_125 ;
}
static T_3 F_50 ( struct V_95 * V_120 , const char T_2 * V_25 , T_4 V_121 , T_5 * V_122 )
{
struct V_5 * V_6 = V_120 -> V_108 ;
struct V_1 * V_2 = V_6 -> V_2 ;
char V_131 [ 12 ] = { V_132 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_35 , V_26 , V_13 , V_16 , V_15 , V_125 , V_126 ;
if ( ! ( V_6 -> V_67 & V_72 ) )
return - V_101 ;
if ( ! ( V_6 -> V_67 & ( V_127 | V_119 ) ) ) {
V_6 -> V_67 |= V_119 ;
if ( F_18
( V_6 , V_131 , 0 , NULL , L_39 ) )
return - V_128 ;
} else if ( V_6 -> V_67 & V_127 )
return - V_128 ;
if ( V_6 -> V_67 & V_129 )
return - V_133 ;
V_125 = 0 ;
while ( V_121 > 0 ) {
if ( ! F_21 ( V_6 , V_37 / 100 , V_43 , L_40 ) )
return - V_128 ;
V_26 = V_121 ;
if ( V_26 > 32768 )
V_26 = 32768 ;
V_126 = ( V_26 - 1 + V_6 -> V_69 ) / V_6 -> V_69 ;
V_26 = V_126 * V_6 -> V_69 ;
V_131 [ 4 ] = V_126 ;
V_13 = F_10 ( V_6 , V_131 , V_26 , L_40 ) ;
F_17 ( 1 ) ;
if ( V_13 ) {
F_16 ( V_6 , 0 ) ;
return - V_128 ;
}
while ( 1 ) {
V_13 = F_7 ( V_6 , V_23 ,
V_24 | V_19 | V_27 ,
F_27 ( L_41 ) , NULL ) ;
if ( V_13 & V_130 ) {
F_12 ( V_2 ) ;
F_16 ( V_6 , 0 ) ;
return - V_128 ;
}
if ( V_13 )
V_6 -> V_67 |= V_129 ;
V_15 = F_3 ( V_2 , 7 ) ;
if ( ! ( V_15 & V_24 ) )
break;
V_26 = ( F_3 ( V_2 , 4 ) + 256 * F_3 ( V_2 , 5 ) ) ;
V_16 = ( F_3 ( V_2 , 2 ) & 3 ) ;
if ( V_16 != 0 ) {
F_12 ( V_2 ) ;
F_9 ( L_42 ,
V_6 -> V_20 , V_16 ) ;
return - V_128 ;
}
while ( V_26 > 0 ) {
V_35 = V_26 ;
if ( V_35 > V_106 )
V_35 = V_106 ;
V_126 = V_35 ;
if ( V_126 > V_121 )
V_126 = V_121 ;
if ( F_44 ( V_6 -> V_83 , V_25 + V_125 , V_126 ) ) {
F_12 ( V_2 ) ;
return - V_112 ;
}
F_13 ( V_2 , V_6 -> V_83 , V_35 ) ;
V_125 += V_126 ;
V_121 -= V_126 ;
V_26 -= V_35 ;
}
}
F_12 ( V_2 ) ;
if ( V_6 -> V_67 & V_129 )
break;
}
return V_125 ;
}
static int T_6 F_51 ( void )
{
int V_75 ;
int V_96 ;
if ( V_134 ) {
V_96 = - V_117 ;
goto V_100;
}
if ( F_32 () ) {
V_96 = - V_98 ;
goto V_100;
}
V_96 = F_52 ( V_77 , V_20 , & V_135 ) ;
if ( V_96 < 0 ) {
F_9 ( L_43 , V_77 ) ;
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ )
if ( V_79 [ V_75 ] . V_82 )
F_35 ( V_79 [ V_75 ] . V_2 ) ;
goto V_100;
}
V_77 = V_96 ;
V_136 = F_53 ( V_137 , L_44 ) ;
if ( F_54 ( V_136 ) ) {
V_96 = F_55 ( V_136 ) ;
goto V_138;
}
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ )
if ( V_79 [ V_75 ] . V_82 ) {
F_56 ( V_136 , NULL , F_57 ( V_77 , V_75 ) , NULL ,
L_45 , V_75 ) ;
F_56 ( V_136 , NULL , F_57 ( V_77 , V_75 + 128 ) ,
NULL , L_46 , V_75 ) ;
}
goto V_100;
V_138:
F_58 ( V_77 , L_44 ) ;
V_100:
return V_96 ;
}
static void T_7 F_59 ( void )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ )
if ( V_79 [ V_75 ] . V_82 ) {
F_60 ( V_136 , F_57 ( V_77 , V_75 ) ) ;
F_60 ( V_136 , F_57 ( V_77 , V_75 + 128 ) ) ;
}
F_61 ( V_136 ) ;
F_58 ( V_77 , V_20 ) ;
for ( V_75 = 0 ; V_75 < V_78 ; V_75 ++ )
if ( V_79 [ V_75 ] . V_82 )
F_35 ( V_79 [ V_75 ] . V_2 ) ;
}
