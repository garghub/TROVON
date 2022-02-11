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
if ( ! V_8 )
exit ( V_10 ) ;
V_8 -> V_11 = V_6 [ V_7 / 4 - 1 ] ;
V_8 -> V_7 = V_7 ;
memcpy ( & V_8 -> V_9 , V_6 , V_7 ) ;
return V_8 ;
}
static void
F_3 ( struct V_5 * V_8 )
{
free ( V_8 ) ;
}
static struct V_12 *
F_4 ( int V_13 , int V_14 , int V_15 )
{
struct V_12 * V_16 ;
F_5 (t, &pending_transaction_list, link) {
if ( V_16 -> V_13 == V_13 &&
V_16 -> V_14 == V_14 &&
V_16 -> V_15 == V_15 )
return V_16 ;
}
V_16 = malloc ( sizeof *V_16 ) ;
if ( ! V_16 )
exit ( V_10 ) ;
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_15 = V_15 ;
F_6 ( & V_16 -> V_17 ) ;
F_6 ( & V_16 -> V_18 ) ;
F_7 ( & V_19 , & V_16 -> V_20 ) ;
return V_16 ;
}
static void
F_8 ( struct V_12 * V_16 )
{
struct V_5 * V_8 ;
while ( ! F_9 ( & V_16 -> V_17 ) ) {
V_8 = F_10 ( & V_16 -> V_17 , struct V_5 , V_20 ) ;
F_11 ( & V_8 -> V_20 ) ;
F_3 ( V_8 ) ;
}
while ( ! F_9 ( & V_16 -> V_18 ) ) {
V_8 = F_10 ( & V_16 -> V_18 , struct V_5 , V_20 ) ;
F_11 ( & V_8 -> V_20 ) ;
F_3 ( V_8 ) ;
}
free ( V_16 ) ;
}
static void
F_12 ( struct V_12 * V_16 )
{
struct V_5 * V_8 ;
int V_21 ;
if ( ! V_16 -> V_22 ) {
printf ( L_1 ) ;
return;
}
for ( V_21 = 0 ; V_21 < F_13 ( V_23 ) ; V_21 ++ )
if ( V_23 [ V_21 ] . F_14 ( V_16 ) )
break;
return;
F_15 ( & V_16 -> V_22 -> V_9 , V_16 -> V_22 -> V_7 ,
V_24 , 0 ) ;
if ( V_16 -> V_25 )
F_15 ( & V_16 -> V_25 -> V_9 , V_16 -> V_22 -> V_7 ,
V_24 , 0 ) ;
else
printf ( L_2 ) ;
if ( V_26 ) {
F_5 (sa, &t->request_list, link)
F_16 ( ( T_1 * ) & V_8 -> V_9 , V_8 -> V_7 ) ;
F_5 (sa, &t->response_list, link)
F_16 ( ( T_1 * ) & V_8 -> V_9 , V_8 -> V_7 ) ;
}
printf ( L_3 ) ;
F_8 ( V_16 ) ;
}
static void
F_17 ( void )
{
struct V_12 * V_16 ;
while ( ! F_9 ( & V_19 ) ) {
V_16 = F_10 ( & V_19 ,
struct V_12 , V_20 ) ;
F_11 ( & V_16 -> V_20 ) ;
F_8 ( V_16 ) ;
}
}
static int
F_18 ( T_1 * V_6 , T_2 V_7 )
{
struct V_27 * V_28 = (struct V_27 * ) V_6 ;
struct V_5 * V_8 , * V_29 ;
struct V_12 * V_16 ;
V_16 = F_4 ( V_28 -> V_30 . V_31 , V_28 -> V_30 . V_32 ,
V_28 -> V_30 . V_15 ) ;
V_8 = F_2 ( V_6 , V_7 ) ;
V_16 -> V_22 = V_8 ;
if ( ! F_9 ( & V_16 -> V_17 ) ) {
V_29 = F_19 ( & V_16 -> V_17 ,
struct V_5 , V_20 ) ;
if ( ! F_20 ( V_29 -> V_11 ) ) {
}
if ( V_29 -> V_9 . V_30 . V_33 != V_8 -> V_9 . V_30 . V_33 ||
V_29 -> V_9 . V_30 . V_15 != V_8 -> V_9 . V_30 . V_15 ) {
}
}
F_7 ( & V_16 -> V_17 , & V_8 -> V_20 ) ;
switch ( V_8 -> V_11 ) {
case V_34 :
if ( V_28 -> V_30 . V_33 != V_35 &&
V_28 -> V_30 . V_33 != V_36 )
;
F_11 ( & V_16 -> V_20 ) ;
F_12 ( V_16 ) ;
break;
case V_37 :
case V_38 :
case V_39 :
F_11 ( & V_16 -> V_20 ) ;
F_12 ( V_16 ) ;
break;
case V_40 :
break;
case V_41 :
case V_42 :
case V_43 :
break;
}
return 1 ;
}
static int
F_21 ( T_1 * V_6 , T_2 V_7 )
{
struct V_27 * V_28 = (struct V_27 * ) V_6 ;
struct V_5 * V_8 , * V_29 ;
struct V_12 * V_16 ;
V_16 = F_4 ( V_28 -> V_30 . V_32 , V_28 -> V_30 . V_31 ,
V_28 -> V_30 . V_15 ) ;
if ( F_9 ( & V_16 -> V_17 ) ) {
}
V_8 = F_2 ( V_6 , V_7 ) ;
V_16 -> V_25 = V_8 ;
if ( ! F_9 ( & V_16 -> V_18 ) ) {
V_29 = F_19 ( & V_16 -> V_18 , struct V_5 , V_20 ) ;
if ( ! F_20 ( V_29 -> V_11 ) ) {
}
if ( V_29 -> V_9 . V_30 . V_33 != V_8 -> V_9 . V_30 . V_33 ||
V_29 -> V_9 . V_30 . V_15 != V_8 -> V_9 . V_30 . V_15 ) {
}
} else {
V_29 = F_19 ( & V_16 -> V_17 , struct V_5 , V_20 ) ;
if ( V_29 -> V_11 != V_40 ) {
}
if ( V_44 [ V_29 -> V_9 . V_30 . V_33 ] . V_45 !=
V_8 -> V_9 . V_30 . V_33 ) {
}
}
F_7 ( & V_16 -> V_18 , & V_8 -> V_20 ) ;
switch ( V_8 -> V_11 ) {
case V_34 :
case V_37 :
case V_38 :
case V_39 :
F_11 ( & V_16 -> V_20 ) ;
F_12 ( V_16 ) ;
break;
case V_40 :
break;
case V_41 :
case V_42 :
case V_43 :
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
} else if ( V_7 > sizeof( struct V_46 ) ) {
struct V_27 * V_28 = (struct V_27 * ) V_6 ;
switch ( V_44 [ V_28 -> V_30 . V_33 ] . type ) {
case V_47 :
return F_18 ( V_6 , V_7 ) ;
case V_48 :
return F_21 ( V_6 , V_7 ) ;
case V_49 :
case V_50 :
return 0 ;
}
}
return 1 ;
}
static unsigned int
F_23 ( struct V_27 * V_9 , int V_51 , int V_52 )
{
T_1 * V_6 = ( T_1 * ) V_9 ;
T_1 V_53 , V_54 , V_55 ;
V_53 = V_51 / 32 + 1 ;
V_54 = 32 - ( V_51 & 31 ) - V_52 ;
V_55 = V_52 == 32 ? ~ 0 : ( 1 << V_52 ) - 1 ;
return ( V_6 [ V_53 ] >> V_54 ) & V_55 ;
}
static void
F_24 ( unsigned char * V_6 , int V_7 )
{
int V_21 , V_56 ;
if ( V_7 > 128 )
V_56 = 128 ;
else
V_56 = V_7 ;
for ( V_21 = 0 ; V_21 < V_56 ; V_21 ++ )
printf ( L_5 ,
( V_21 % 4 == 0 && V_21 != 0 ) ? L_6 : L_7 ,
V_6 [ F_25 ( V_21 ) ] ) ;
if ( V_56 < V_7 )
printf ( L_8 , V_7 - V_56 ) ;
}
static void
F_15 ( struct V_27 * V_9 , T_2 V_7 ,
int V_57 , int V_58 )
{
const struct V_44 * V_59 ;
int V_60 = 0 ;
int V_21 ;
V_59 = & V_44 [ V_9 -> V_30 . V_33 ] ;
for ( V_21 = 0 ; V_21 < V_59 -> V_61 ; V_21 ++ ) {
const struct V_62 * V_63 = & V_59 -> V_64 [ V_21 ] ;
int V_51 ;
if ( V_63 -> V_65 & V_58 )
continue;
if ( V_57 && ! ( V_63 -> V_65 & V_57 ) )
continue;
if ( V_63 -> V_51 < 0 )
V_51 = V_7 * 8 + V_63 -> V_51 - 32 ;
else
V_51 = V_63 -> V_51 ;
if ( V_63 -> V_66 != NULL ) {
T_1 V_67 ;
V_67 = F_23 ( V_9 , V_51 , V_63 -> V_52 ) ;
printf ( L_9 , V_63 -> V_66 [ V_67 ] ) ;
} else if ( V_63 -> V_52 == 0 ) {
printf ( L_10 , V_63 -> V_68 ) ;
F_24 ( ( unsigned char * ) V_9 + ( V_51 / 8 + 4 ) , V_60 ) ;
printf ( L_11 ) ;
} else {
unsigned long long V_67 ;
int V_69 , V_70 ;
if ( ( V_51 & ~ 31 ) != ( ( V_51 + V_63 -> V_52 - 1 ) & ~ 31 ) ) {
V_69 = ( ( V_51 + 31 ) & ~ 31 ) - V_51 ;
V_70 = V_63 -> V_52 - V_69 ;
V_67 = F_23 ( V_9 , V_51 , V_69 ) ;
V_67 = ( V_67 << V_70 ) |
F_23 ( V_9 , V_51 + V_69 , V_70 ) ;
} else {
V_67 = F_23 ( V_9 , V_51 , V_63 -> V_52 ) ;
}
printf ( L_12 , V_63 -> V_68 , ( V_63 -> V_52 + 3 ) / 4 , V_67 ) ;
if ( V_63 -> V_65 & V_71 )
V_60 = V_67 ;
}
if ( V_21 < V_59 -> V_61 - 1 )
printf ( L_13 ) ;
}
}
static void
F_16 ( T_1 * V_6 , T_2 V_7 )
{
int V_21 ;
printf ( L_14 , V_6 [ 0 ] ) ;
if ( V_7 == 4 ) {
printf ( L_15 ) ;
} else if ( V_7 < sizeof( struct V_46 ) ) {
printf ( L_16 ) ;
for ( V_21 = 1 ; V_21 < V_7 / 4 ; V_21 ++ )
printf ( L_17 , V_21 == 0 ? L_18 : L_6 , V_6 [ V_21 ] ) ;
printf ( L_11 ) ;
} else if ( V_7 == sizeof( struct V_46 ) && V_6 [ 1 ] == ~ V_6 [ 2 ] ) {
struct V_46 * V_72 = (struct V_46 * ) V_6 ;
switch ( V_72 -> V_30 . V_73 ) {
case V_74 :
if ( ! V_72 -> V_75 . V_76 && ! V_72 -> V_75 . V_77 ) {
printf ( L_19 , V_72 -> V_75 . V_78 ) ;
} else {
printf ( L_20 ) ;
if ( V_72 -> V_75 . V_76 )
printf ( L_21 , V_72 -> V_75 . V_78 ) ;
if ( V_72 -> V_75 . V_77 )
printf ( L_22 , V_72 -> V_75 . V_79 ) ;
}
break;
case V_80 :
printf ( L_23 , V_72 -> V_81 . V_82 ) ;
break;
case V_83 :
if ( V_72 -> V_84 . V_85 ) {
printf ( L_24 ,
V_72 -> V_86 . V_82 , V_72 -> V_86 . V_87 ) ;
} else {
static const char * const V_88 [] = {
L_25 , L_26 , L_27 , L_28
} ;
printf ( L_29 ,
V_72 -> V_84 . V_82 ,
( V_72 -> V_84 . V_89 ? L_30 : L_31 ) ,
V_72 -> V_84 . V_79 ,
V_88 [ V_72 -> V_84 . V_90 ] ,
( V_72 -> V_84 . V_91 ? L_32 : L_7 ) ,
( V_72 -> V_84 . V_92 ? L_33 : L_7 ) ) ;
}
break;
default:
printf ( L_34 ) ;
for ( V_21 = 1 ; V_21 < V_7 / 4 ; V_21 ++ )
printf ( L_17 , V_21 == 0 ? L_18 : L_6 , V_6 [ V_21 ] ) ;
printf ( L_11 ) ;
break;
}
} else {
struct V_27 * V_9 = (struct V_27 * ) V_6 ;
F_15 ( V_9 , V_7 , 0 ,
V_26 ? 0 : V_93 ) ;
}
if ( V_94 ) {
printf ( L_35 ) ;
F_24 ( ( unsigned char * ) V_6 + 4 , V_7 - 4 ) ;
printf ( L_11 ) ;
}
printf ( L_3 ) ;
}
static void
F_26 ( T_1 * V_6 , T_2 V_7 )
{
static int V_95 , V_96 , V_97 ;
static int V_98 [ 16 ] ;
static struct V_99 V_100 ;
struct V_99 V_101 ;
int V_21 ;
if ( V_7 == 0 )
V_95 ++ ;
else if ( V_7 < sizeof( struct V_46 ) )
V_96 ++ ;
else if ( V_7 == sizeof( struct V_46 ) && V_6 [ 1 ] == ~ V_6 [ 2 ] )
V_97 ++ ;
else {
struct V_27 * V_9 = (struct V_27 * ) V_6 ;
V_98 [ V_9 -> V_30 . V_33 ] ++ ;
}
F_27 ( & V_101 , NULL ) ;
if ( V_101 . V_102 <= V_100 . V_102 &&
V_101 . V_103 < V_100 . V_103 + 500000 )
return;
V_100 = V_101 ;
printf (CLEAR HIDE_CURSOR
L_36
L_37
L_38 ,
bus_reset_count, short_packet_count, phy_packet_count) ;
for ( V_21 = 0 ; V_21 < F_13 ( V_44 ) ; V_21 ++ )
if ( V_44 [ V_21 ] . type != V_50 )
printf ( L_39 , V_44 [ V_21 ] . V_68 , V_98 [ V_21 ] ) ;
printf ( V_104 L_40 ) ;
}
static void
F_28 ( void )
{
F_29 ( V_105 , V_106 , & V_107 ) ;
}
static void
F_30 ( void )
{
struct V_108 V_109 ;
if ( ! F_31 ( V_105 ) ) {
fprintf ( V_110 , L_41 ) ;
exit ( V_10 ) ;
}
F_32 ( V_105 , & V_107 ) ;
atexit ( F_28 ) ;
F_32 ( V_105 , & V_109 ) ;
V_109 . V_111 &= ~ ( V_112 | V_113 ) ;
V_109 . V_114 [ V_115 ] = 1 ;
V_109 . V_114 [ V_116 ] = 0 ;
F_29 ( V_105 , V_117 , & V_109 ) ;
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
fprintf ( V_110 , L_43
L_44 ) ;
if ( V_137 != NULL ) {
V_126 = fopen ( V_137 , L_45 ) ;
if ( V_126 == NULL ) {
fprintf ( V_110 , L_46 , V_137 ) ;
return - 1 ;
}
} else {
V_124 = F_36 ( V_138 , V_139 ) ;
if ( V_124 < 0 ) {
fprintf ( V_110 , L_46 , V_138 ) ;
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
fprintf ( V_110 , L_46 , V_144 ) ;
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
V_130 [ 1 ] . V_124 = V_105 ;
V_130 [ 1 ] . V_153 = V_154 ;
while ( V_2 ) {
if ( V_126 != NULL ) {
if ( fread ( & V_7 , sizeof V_7 , 1 , V_126 ) != 1 )
return 0 ;
fread ( V_120 , 1 , V_7 , V_126 ) ;
} else {
F_38 ( V_130 , 2 , - 1 ) ;
if ( V_130 [ 1 ] . V_155 ) {
F_39 ( V_105 , & V_128 , sizeof V_128 ) ;
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
