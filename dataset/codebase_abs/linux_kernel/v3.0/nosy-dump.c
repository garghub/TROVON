static void
F_1 ( int V_1 )
{
if ( V_2 == 1 ) {
V_2 = 0 ;
signal ( V_3 , V_4 ) ;
}
}
static struct V_5 *
F_2 ( T_1 * V_6 , T_2 V_7 )
{
struct V_5 * V_8 ;
V_8 = malloc ( sizeof *V_8 - sizeof V_8 -> V_9 + V_7 ) ;
V_8 -> V_10 = V_6 [ V_7 / 4 - 1 ] ;
V_8 -> V_7 = V_7 ;
memcpy ( & V_8 -> V_9 , V_6 , V_7 ) ;
return V_8 ;
}
static void
F_3 ( struct V_5 * V_8 )
{
free ( V_8 ) ;
}
static struct V_11 *
F_4 ( int V_12 , int V_13 , int V_14 )
{
struct V_11 * V_15 ;
F_5 (t, &pending_transaction_list, link) {
if ( V_15 -> V_12 == V_12 &&
V_15 -> V_13 == V_13 &&
V_15 -> V_14 == V_14 )
return V_15 ;
}
V_15 = malloc ( sizeof *V_15 ) ;
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
V_15 -> V_14 = V_14 ;
F_6 ( & V_15 -> V_16 ) ;
F_6 ( & V_15 -> V_17 ) ;
F_7 ( & V_18 , & V_15 -> V_19 ) ;
return V_15 ;
}
static void
F_8 ( struct V_11 * V_15 )
{
struct V_5 * V_8 ;
while ( ! F_9 ( & V_15 -> V_16 ) ) {
V_8 = F_10 ( & V_15 -> V_16 , struct V_5 , V_19 ) ;
F_11 ( & V_8 -> V_19 ) ;
F_3 ( V_8 ) ;
}
while ( ! F_9 ( & V_15 -> V_17 ) ) {
V_8 = F_10 ( & V_15 -> V_17 , struct V_5 , V_19 ) ;
F_11 ( & V_8 -> V_19 ) ;
F_3 ( V_8 ) ;
}
free ( V_15 ) ;
}
static void
F_12 ( struct V_11 * V_15 )
{
struct V_5 * V_8 ;
int V_20 ;
if ( ! V_15 -> V_21 ) {
printf ( L_1 ) ;
return;
}
for ( V_20 = 0 ; V_20 < F_13 ( V_22 ) ; V_20 ++ )
if ( V_22 [ V_20 ] . F_14 ( V_15 ) )
break;
return;
F_15 ( & V_15 -> V_21 -> V_9 , V_15 -> V_21 -> V_7 ,
V_23 , 0 ) ;
if ( V_15 -> V_24 )
F_15 ( & V_15 -> V_24 -> V_9 , V_15 -> V_21 -> V_7 ,
V_23 , 0 ) ;
else
printf ( L_2 ) ;
if ( V_25 ) {
F_5 (sa, &t->request_list, link)
F_16 ( ( T_1 * ) & V_8 -> V_9 , V_8 -> V_7 ) ;
F_5 (sa, &t->response_list, link)
F_16 ( ( T_1 * ) & V_8 -> V_9 , V_8 -> V_7 ) ;
}
printf ( L_3 ) ;
F_8 ( V_15 ) ;
}
static void
F_17 ( void )
{
struct V_11 * V_15 ;
while ( ! F_9 ( & V_18 ) ) {
V_15 = F_10 ( & V_18 ,
struct V_11 , V_19 ) ;
F_11 ( & V_15 -> V_19 ) ;
F_8 ( V_15 ) ;
}
}
static int
F_18 ( T_1 * V_6 , T_2 V_7 )
{
struct V_26 * V_27 = (struct V_26 * ) V_6 ;
struct V_5 * V_8 , * V_28 ;
struct V_11 * V_15 ;
V_15 = F_4 ( V_27 -> V_29 . V_30 , V_27 -> V_29 . V_31 ,
V_27 -> V_29 . V_14 ) ;
V_8 = F_2 ( V_6 , V_7 ) ;
V_15 -> V_21 = V_8 ;
if ( ! F_9 ( & V_15 -> V_16 ) ) {
V_28 = F_19 ( & V_15 -> V_16 ,
struct V_5 , V_19 ) ;
if ( ! F_20 ( V_28 -> V_10 ) ) {
}
if ( V_28 -> V_9 . V_29 . V_32 != V_8 -> V_9 . V_29 . V_32 ||
V_28 -> V_9 . V_29 . V_14 != V_8 -> V_9 . V_29 . V_14 ) {
}
}
F_7 ( & V_15 -> V_16 , & V_8 -> V_19 ) ;
switch ( V_8 -> V_10 ) {
case V_33 :
if ( V_27 -> V_29 . V_32 != V_34 &&
V_27 -> V_29 . V_32 != V_35 )
;
F_11 ( & V_15 -> V_19 ) ;
F_12 ( V_15 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_11 ( & V_15 -> V_19 ) ;
F_12 ( V_15 ) ;
break;
case V_39 :
break;
case V_40 :
case V_41 :
case V_42 :
break;
}
return 1 ;
}
static int
F_21 ( T_1 * V_6 , T_2 V_7 )
{
struct V_26 * V_27 = (struct V_26 * ) V_6 ;
struct V_5 * V_8 , * V_28 ;
struct V_11 * V_15 ;
V_15 = F_4 ( V_27 -> V_29 . V_31 , V_27 -> V_29 . V_30 ,
V_27 -> V_29 . V_14 ) ;
if ( F_9 ( & V_15 -> V_16 ) ) {
}
V_8 = F_2 ( V_6 , V_7 ) ;
V_15 -> V_24 = V_8 ;
if ( ! F_9 ( & V_15 -> V_17 ) ) {
V_28 = F_19 ( & V_15 -> V_17 , struct V_5 , V_19 ) ;
if ( ! F_20 ( V_28 -> V_10 ) ) {
}
if ( V_28 -> V_9 . V_29 . V_32 != V_8 -> V_9 . V_29 . V_32 ||
V_28 -> V_9 . V_29 . V_14 != V_8 -> V_9 . V_29 . V_14 ) {
}
} else {
V_28 = F_19 ( & V_15 -> V_16 , struct V_5 , V_19 ) ;
if ( V_28 -> V_10 != V_39 ) {
}
if ( V_43 [ V_28 -> V_9 . V_29 . V_32 ] . V_44 !=
V_8 -> V_9 . V_29 . V_32 ) {
}
}
F_7 ( & V_15 -> V_17 , & V_8 -> V_19 ) ;
switch ( V_8 -> V_10 ) {
case V_33 :
case V_36 :
case V_37 :
case V_38 :
F_11 ( & V_15 -> V_19 ) ;
F_12 ( V_15 ) ;
break;
case V_39 :
break;
case V_40 :
case V_41 :
case V_42 :
break;
}
return 1 ;
}
static int
F_22 ( T_1 * V_6 , T_2 V_7 )
{
if ( V_7 == 0 ) {
printf ( L_4 ) ;
F_17 () ;
} else if ( V_7 > sizeof( struct V_45 ) ) {
struct V_26 * V_27 = (struct V_26 * ) V_6 ;
switch ( V_43 [ V_27 -> V_29 . V_32 ] . type ) {
case V_46 :
return F_18 ( V_6 , V_7 ) ;
case V_47 :
return F_21 ( V_6 , V_7 ) ;
case V_48 :
case V_49 :
return 0 ;
}
}
return 1 ;
}
static unsigned int
F_23 ( struct V_26 * V_9 , int V_50 , int V_51 )
{
T_1 * V_6 = ( T_1 * ) V_9 ;
T_1 V_52 , V_53 , V_54 ;
V_52 = V_50 / 32 + 1 ;
V_53 = 32 - ( V_50 & 31 ) - V_51 ;
V_54 = V_51 == 32 ? ~ 0 : ( 1 << V_51 ) - 1 ;
return ( V_6 [ V_52 ] >> V_53 ) & V_54 ;
}
static void
F_24 ( unsigned char * V_6 , int V_7 )
{
int V_20 , V_55 ;
if ( V_7 > 128 )
V_55 = 128 ;
else
V_55 = V_7 ;
for ( V_20 = 0 ; V_20 < V_55 ; V_20 ++ )
printf ( L_5 ,
( V_20 % 4 == 0 && V_20 != 0 ) ? L_6 : L_7 ,
V_6 [ F_25 ( V_20 ) ] ) ;
if ( V_55 < V_7 )
printf ( L_8 , V_7 - V_55 ) ;
}
static void
F_15 ( struct V_26 * V_9 , T_2 V_7 ,
int V_56 , int V_57 )
{
const struct V_43 * V_58 ;
int V_59 = 0 ;
int V_20 ;
V_58 = & V_43 [ V_9 -> V_29 . V_32 ] ;
for ( V_20 = 0 ; V_20 < V_58 -> V_60 ; V_20 ++ ) {
const struct V_61 * V_62 = & V_58 -> V_63 [ V_20 ] ;
int V_50 ;
if ( V_62 -> V_64 & V_57 )
continue;
if ( V_56 && ! ( V_62 -> V_64 & V_56 ) )
continue;
if ( V_62 -> V_50 < 0 )
V_50 = V_7 * 8 + V_62 -> V_50 - 32 ;
else
V_50 = V_62 -> V_50 ;
if ( V_62 -> V_65 != NULL ) {
T_1 V_66 ;
V_66 = F_23 ( V_9 , V_50 , V_62 -> V_51 ) ;
printf ( L_9 , V_62 -> V_65 [ V_66 ] ) ;
} else if ( V_62 -> V_51 == 0 ) {
printf ( L_10 , V_62 -> V_67 ) ;
F_24 ( ( unsigned char * ) V_9 + ( V_50 / 8 + 4 ) , V_59 ) ;
printf ( L_11 ) ;
} else {
unsigned long long V_66 ;
int V_68 , V_69 ;
if ( ( V_50 & ~ 31 ) != ( ( V_50 + V_62 -> V_51 - 1 ) & ~ 31 ) ) {
V_68 = ( ( V_50 + 31 ) & ~ 31 ) - V_50 ;
V_69 = V_62 -> V_51 - V_68 ;
V_66 = F_23 ( V_9 , V_50 , V_68 ) ;
V_66 = ( V_66 << V_69 ) |
F_23 ( V_9 , V_50 + V_68 , V_69 ) ;
} else {
V_66 = F_23 ( V_9 , V_50 , V_62 -> V_51 ) ;
}
printf ( L_12 , V_62 -> V_67 , ( V_62 -> V_51 + 3 ) / 4 , V_66 ) ;
if ( V_62 -> V_64 & V_70 )
V_59 = V_66 ;
}
if ( V_20 < V_58 -> V_60 - 1 )
printf ( L_13 ) ;
}
}
static void
F_16 ( T_1 * V_6 , T_2 V_7 )
{
int V_20 ;
printf ( L_14 , V_6 [ 0 ] ) ;
if ( V_7 == 4 ) {
printf ( L_15 ) ;
} else if ( V_7 < sizeof( struct V_45 ) ) {
printf ( L_16 ) ;
for ( V_20 = 1 ; V_20 < V_7 / 4 ; V_20 ++ )
printf ( L_17 , V_20 == 0 ? L_18 : L_6 , V_6 [ V_20 ] ) ;
printf ( L_11 ) ;
} else if ( V_7 == sizeof( struct V_45 ) && V_6 [ 1 ] == ~ V_6 [ 2 ] ) {
struct V_45 * V_71 = (struct V_45 * ) V_6 ;
switch ( V_71 -> V_29 . V_72 ) {
case V_73 :
if ( ! V_71 -> V_74 . V_75 && ! V_71 -> V_74 . V_76 ) {
printf ( L_19 , V_71 -> V_74 . V_77 ) ;
} else {
printf ( L_20 ) ;
if ( V_71 -> V_74 . V_75 )
printf ( L_21 , V_71 -> V_74 . V_77 ) ;
if ( V_71 -> V_74 . V_76 )
printf ( L_22 , V_71 -> V_74 . V_78 ) ;
}
break;
case V_79 :
printf ( L_23 , V_71 -> V_80 . V_81 ) ;
break;
case V_82 :
if ( V_71 -> V_83 . V_84 ) {
printf ( L_24 ,
V_71 -> V_85 . V_81 , V_71 -> V_85 . V_86 ) ;
} else {
static const char * const V_87 [] = {
L_25 , L_26 , L_27 , L_28
} ;
printf ( L_29 ,
V_71 -> V_83 . V_81 ,
( V_71 -> V_83 . V_88 ? L_30 : L_31 ) ,
V_71 -> V_83 . V_78 ,
V_87 [ V_71 -> V_83 . V_89 ] ,
( V_71 -> V_83 . V_90 ? L_32 : L_7 ) ,
( V_71 -> V_83 . V_91 ? L_33 : L_7 ) ) ;
}
break;
default:
printf ( L_34 ) ;
for ( V_20 = 1 ; V_20 < V_7 / 4 ; V_20 ++ )
printf ( L_17 , V_20 == 0 ? L_18 : L_6 , V_6 [ V_20 ] ) ;
printf ( L_11 ) ;
break;
}
} else {
struct V_26 * V_9 = (struct V_26 * ) V_6 ;
F_15 ( V_9 , V_7 , 0 ,
V_25 ? 0 : V_92 ) ;
}
if ( V_93 ) {
printf ( L_35 ) ;
F_24 ( ( unsigned char * ) V_6 + 4 , V_7 - 4 ) ;
printf ( L_11 ) ;
}
printf ( L_3 ) ;
}
static void
F_26 ( T_1 * V_6 , T_2 V_7 )
{
static int V_94 , V_95 , V_96 ;
static int V_97 [ 16 ] ;
static struct V_98 V_99 ;
struct V_98 V_100 ;
int V_20 ;
if ( V_7 == 0 )
V_94 ++ ;
else if ( V_7 < sizeof( struct V_45 ) )
V_95 ++ ;
else if ( V_7 == sizeof( struct V_45 ) && V_6 [ 1 ] == ~ V_6 [ 2 ] )
V_96 ++ ;
else {
struct V_26 * V_9 = (struct V_26 * ) V_6 ;
V_97 [ V_9 -> V_29 . V_32 ] ++ ;
}
F_27 ( & V_100 , NULL ) ;
if ( V_100 . V_101 <= V_99 . V_101 &&
V_100 . V_102 < V_99 . V_102 + 500000 )
return;
V_99 = V_100 ;
printf (CLEAR HIDE_CURSOR
L_36
L_37
L_38 ,
bus_reset_count, short_packet_count, phy_packet_count) ;
for ( V_20 = 0 ; V_20 < F_13 ( V_43 ) ; V_20 ++ )
if ( V_43 [ V_20 ] . type != V_49 )
printf ( L_39 , V_43 [ V_20 ] . V_67 , V_97 [ V_20 ] ) ;
printf ( V_103 L_40 ) ;
}
static void
F_28 ( void )
{
F_29 ( V_104 , V_105 , & V_106 ) ;
}
static void
F_30 ( void )
{
struct V_107 V_108 ;
if ( ! F_31 ( V_104 ) ) {
fprintf ( V_109 , L_41 ) ;
exit ( V_110 ) ;
}
F_32 ( V_104 , & V_106 ) ;
atexit ( F_28 ) ;
F_32 ( V_104 , & V_108 ) ;
V_108 . V_111 &= ~ ( V_112 | V_113 ) ;
V_108 . V_114 [ V_115 ] = 1 ;
V_108 . V_114 [ V_116 ] = 0 ;
F_29 ( V_104 , V_117 , & V_108 ) ;
}
int main ( int V_118 , const char * V_119 [] )
{
T_1 V_120 [ 128 * 1024 ] ;
T_1 V_121 ;
int V_7 , V_122 , V_123 ;
int V_124 = - 1 ;
T_3 * V_125 = NULL , * V_126 = NULL ;
T_4 V_127 ;
char V_128 ;
struct V_129 V_130 [ 2 ] ;
V_131 = signal ( V_3 , F_1 ) ;
V_127 = F_33 ( NULL , V_118 , V_119 , V_132 , 0 ) ;
V_122 = F_34 ( V_127 ) ;
if ( V_122 < - 1 ) {
F_35 ( V_127 , stdout , 0 ) ;
return - 1 ;
}
if ( V_133 ) {
printf ( L_42 , V_134 ) ;
return 0 ;
}
if ( V_135 != V_136 )
fprintf ( V_109 , L_43
L_44 ) ;
if ( V_137 != NULL ) {
V_126 = fopen ( V_137 , L_45 ) ;
if ( V_126 == NULL ) {
fprintf ( V_109 , L_46 , V_137 ) ;
return - 1 ;
}
} else {
V_124 = F_36 ( V_138 , V_139 ) ;
if ( V_124 < 0 ) {
fprintf ( V_109 , L_46 , V_138 ) ;
return - 1 ;
}
F_30 () ;
}
if ( strcmp ( V_140 , L_47 ) == 0 )
V_123 = V_141 ;
else if ( strcmp ( V_140 , L_48 ) == 0 )
V_123 = V_142 ;
else
V_123 = V_143 ;
if ( V_144 ) {
V_125 = fopen ( V_144 , L_49 ) ;
if ( V_125 == NULL ) {
fprintf ( V_109 , L_46 , V_144 ) ;
return - 1 ;
}
}
setvbuf ( stdout , NULL , V_145 , V_146 ) ;
V_121 = ~ 0 ;
if ( ! V_147 )
V_121 &= ~ ( 1 << V_148 ) ;
if ( ! V_149 )
V_121 &= ~ ( 1 << V_150 ) ;
if ( V_123 == V_142 )
V_121 = ~ ( 1 << V_150 ) ;
F_37 ( V_124 , V_151 , V_121 ) ;
F_37 ( V_124 , V_152 ) ;
V_130 [ 0 ] . V_124 = V_124 ;
V_130 [ 0 ] . V_153 = V_154 ;
V_130 [ 1 ] . V_124 = V_104 ;
V_130 [ 1 ] . V_153 = V_154 ;
while ( V_2 ) {
if ( V_126 != NULL ) {
if ( fread ( & V_7 , sizeof V_7 , 1 , V_126 ) != 1 )
return 0 ;
fread ( V_120 , 1 , V_7 , V_126 ) ;
} else {
F_38 ( V_130 , 2 , - 1 ) ;
if ( V_130 [ 1 ] . V_155 ) {
F_39 ( V_104 , & V_128 , sizeof V_128 ) ;
switch ( V_128 ) {
case 'q' :
if ( V_125 != NULL )
fclose ( V_125 ) ;
return 0 ;
}
}
if ( V_130 [ 0 ] . V_155 )
V_7 = F_39 ( V_124 , V_120 , sizeof V_120 ) ;
else
continue;
}
if ( V_125 != NULL ) {
fwrite ( & V_7 , sizeof V_7 , 1 , V_125 ) ;
fwrite ( V_120 , 1 , V_7 , V_125 ) ;
}
switch ( V_123 ) {
case V_141 :
F_22 ( V_120 , V_7 ) ;
break;
case V_143 :
F_16 ( V_120 , V_7 ) ;
break;
case V_142 :
F_26 ( V_120 , V_7 ) ;
break;
}
}
if ( V_125 != NULL )
fclose ( V_125 ) ;
F_40 ( V_124 ) ;
F_41 ( V_127 ) ;
return 0 ;
}
