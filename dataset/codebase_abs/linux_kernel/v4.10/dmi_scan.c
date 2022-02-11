static const char * T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 )
{
const T_2 * V_4 = ( ( T_2 * ) V_2 ) + V_2 -> V_5 ;
if ( V_3 ) {
V_3 -- ;
while ( V_3 > 0 && * V_4 ) {
V_4 += strlen ( V_4 ) + 1 ;
V_3 -- ;
}
if ( * V_4 != 0 ) {
T_3 V_6 = strlen ( V_4 ) + 1 ;
T_3 V_7 = V_6 > 8 ? 8 : V_6 ;
if ( ! memcmp ( V_4 , V_8 , V_7 ) )
return V_8 ;
return V_4 ;
}
}
return L_1 ;
}
static const char * T_1 F_2 ( const struct V_1 * V_2 , T_2 V_3 )
{
const char * V_4 = F_1 ( V_2 , V_3 ) ;
char * V_9 ;
T_3 V_6 ;
if ( V_4 == V_8 )
return V_8 ;
V_6 = strlen ( V_4 ) + 1 ;
V_9 = F_3 ( V_6 ) ;
if ( V_9 != NULL )
strcpy ( V_9 , V_4 ) ;
return V_9 ;
}
static void F_4 ( T_2 * V_10 ,
void (* F_5)( const struct V_1 * , void * ) ,
void * V_11 )
{
T_2 * V_12 = V_10 ;
int V_13 = 0 ;
while ( ( ! V_14 || V_13 < V_14 ) &&
( V_12 - V_10 + sizeof( struct V_1 ) ) <= V_15 ) {
const struct V_1 * V_2 = ( const struct V_1 * ) V_12 ;
V_12 += V_2 -> V_5 ;
while ( ( V_12 - V_10 < V_15 - 1 ) && ( V_12 [ 0 ] || V_12 [ 1 ] ) )
V_12 ++ ;
if ( V_12 - V_10 < V_15 - 1 )
F_5 ( V_2 , V_11 ) ;
V_12 += 2 ;
V_13 ++ ;
if ( ! V_14 && V_2 -> type == V_16 )
break;
}
if ( V_15 > V_12 - V_10 )
V_15 = V_12 - V_10 ;
}
static int T_1 F_6 ( void (* F_5)( const struct V_1 * ,
void * ) )
{
T_2 * V_10 ;
T_4 V_17 = V_15 ;
V_10 = F_7 ( V_18 , V_17 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , F_5 , NULL ) ;
F_8 ( V_10 , V_15 ) ;
F_9 ( V_10 , V_17 ) ;
return 0 ;
}
static int T_1 F_10 ( const T_2 * V_10 , T_2 V_6 )
{
T_2 V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ )
V_19 += V_10 [ V_20 ] ;
return V_19 == 0 ;
}
static void T_1 F_11 ( const struct V_1 * V_2 , int V_21 ,
int string )
{
const char * V_22 = ( const char * ) V_2 ;
const char * V_23 ;
if ( V_24 [ V_21 ] )
return;
V_23 = F_2 ( V_2 , V_22 [ string ] ) ;
if ( V_23 == NULL )
return;
V_24 [ V_21 ] = V_23 ;
}
static void T_1 F_12 ( const struct V_1 * V_2 , int V_21 ,
int V_25 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + V_25 ;
char * V_3 ;
int V_26 = 1 , V_27 = 1 , V_13 ;
if ( V_24 [ V_21 ] )
return;
for ( V_13 = 0 ; V_13 < 16 && ( V_26 || V_27 ) ; V_13 ++ ) {
if ( V_22 [ V_13 ] != 0x00 )
V_27 = 0 ;
if ( V_22 [ V_13 ] != 0xFF )
V_26 = 0 ;
}
if ( V_26 || V_27 )
return;
V_3 = F_3 ( 16 * 2 + 4 + 1 ) ;
if ( ! V_3 )
return;
if ( V_28 >= 0x020600 )
sprintf ( V_3 , L_2 , V_22 ) ;
else
sprintf ( V_3 , L_3 , V_22 ) ;
V_24 [ V_21 ] = V_3 ;
}
static void T_1 F_13 ( const struct V_1 * V_2 , int V_21 ,
int V_25 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + V_25 ;
char * V_3 ;
if ( V_24 [ V_21 ] )
return;
V_3 = F_3 ( 4 ) ;
if ( ! V_3 )
return;
sprintf ( V_3 , L_4 , * V_22 & 0x7F ) ;
V_24 [ V_21 ] = V_3 ;
}
static void T_1 F_14 ( int type , const char * V_29 )
{
struct V_30 * V_31 ;
if ( F_15 ( type , V_29 , NULL ) )
return;
V_31 = F_3 ( sizeof( * V_31 ) + strlen ( V_29 ) + 1 ) ;
if ( ! V_31 )
return;
V_31 -> type = type ;
strcpy ( ( char * ) ( V_31 + 1 ) , V_29 ) ;
V_31 -> V_29 = ( char * ) ( V_31 + 1 ) ;
V_31 -> V_32 = NULL ;
F_16 ( & V_31 -> V_33 , & V_34 ) ;
}
static void T_1 F_17 ( const struct V_1 * V_2 )
{
int V_13 , V_35 = ( V_2 -> V_5 - sizeof( struct V_1 ) ) / 2 ;
for ( V_13 = 0 ; V_13 < V_35 ; V_13 ++ ) {
const char * V_22 = ( char * ) ( V_2 + 1 ) + ( V_13 * 2 ) ;
if ( ( * V_22 & 0x80 ) == 0 )
continue;
F_14 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 + 1 ) ) ) ;
}
}
static void T_1 F_18 ( const struct V_1 * V_2 )
{
int V_13 , V_35 = * ( T_2 * ) ( V_2 + 1 ) ;
struct V_30 * V_31 ;
for ( V_13 = 1 ; V_13 <= V_35 ; V_13 ++ ) {
const char * V_36 = F_2 ( V_2 , V_13 ) ;
if ( V_36 == V_8 )
continue;
V_31 = F_3 ( sizeof( * V_31 ) ) ;
if ( ! V_31 )
break;
V_31 -> type = V_37 ;
V_31 -> V_29 = V_36 ;
V_31 -> V_32 = NULL ;
F_16 ( & V_31 -> V_33 , & V_34 ) ;
}
}
static void T_1 F_19 ( const struct V_1 * V_2 )
{
struct V_30 * V_31 ;
void * V_12 ;
V_12 = F_3 ( V_2 -> V_5 ) ;
if ( V_12 == NULL )
return;
memcpy ( V_12 , V_2 , V_2 -> V_5 ) ;
V_31 = F_3 ( sizeof( * V_31 ) ) ;
if ( ! V_31 )
return;
V_31 -> type = V_38 ;
V_31 -> V_29 = L_5 ;
V_31 -> V_32 = V_12 ;
F_20 ( & V_31 -> V_33 , & V_34 ) ;
}
static void T_1 F_21 ( int V_39 , int V_40 , int V_41 ,
int V_42 , const char * V_29 , int type )
{
struct V_43 * V_31 ;
if ( type == V_44 &&
V_40 == 0xFFFF && V_41 == 0xFF && V_42 == 0xFF )
return;
V_31 = F_3 ( sizeof( * V_31 ) + strlen ( V_29 ) + 1 ) ;
if ( ! V_31 )
return;
V_31 -> V_39 = V_39 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_41 = V_41 ;
V_31 -> V_42 = V_42 ;
strcpy ( ( char * ) & V_31 [ 1 ] , V_29 ) ;
V_31 -> V_31 . type = type ;
V_31 -> V_31 . V_29 = ( char * ) & V_31 [ 1 ] ;
V_31 -> V_31 . V_32 = V_31 ;
F_16 ( & V_31 -> V_31 . V_33 , & V_34 ) ;
}
static void T_1 F_22 ( const struct V_1 * V_2 )
{
const char * V_29 ;
const T_2 * V_22 = ( T_2 * ) V_2 ;
if ( ( V_22 [ 0x5 ] & 0x80 ) == 0 )
return;
V_29 = F_1 ( V_2 , V_22 [ 0x4 ] ) ;
F_21 ( V_22 [ 0x6 ] , * ( V_45 * ) ( V_22 + 0x7 ) , V_22 [ 0x9 ] , V_22 [ 0xA ] , V_29 ,
V_46 ) ;
F_14 ( V_22 [ 0x5 ] & 0x7f , V_29 ) ;
}
static void T_1 F_23 ( const struct V_1 * V_2 )
{
const T_2 * V_22 = ( T_2 * ) V_2 ;
if ( V_2 -> V_5 < 0x11 )
return;
F_21 ( * ( V_45 * ) ( V_22 + 0x9 ) , * ( V_45 * ) ( V_22 + 0xD ) , V_22 [ 0xF ] ,
V_22 [ 0x10 ] , F_1 ( V_2 , V_22 [ 0x4 ] ) ,
V_44 ) ;
}
static void T_1 F_24 ( const struct V_1 * V_2 , void * V_47 )
{
if ( V_2 -> type != V_48 )
return;
V_49 ++ ;
}
static void T_1 F_25 ( const struct V_1 * V_2 , void * V_47 )
{
const char * V_22 = ( const char * ) V_2 ;
static int V_50 ;
if ( V_2 -> type != V_48 )
return;
if ( V_50 >= V_49 ) {
F_26 ( V_51 L_6 ) ;
return;
}
V_52 [ V_50 ] . V_53 = F_27 ( & V_2 -> V_53 ) ;
V_52 [ V_50 ] . V_54 = F_2 ( V_2 , V_22 [ 0x10 ] ) ;
V_52 [ V_50 ] . V_55 = F_2 ( V_2 , V_22 [ 0x11 ] ) ;
V_50 ++ ;
}
void T_1 F_28 ( void )
{
if ( ! V_56 )
return;
if ( F_6 ( F_24 ) == 0 && V_49 ) {
V_52 = F_3 ( sizeof( * V_52 ) * V_49 ) ;
if ( V_52 )
F_6 ( F_25 ) ;
}
}
static void T_1 F_29 ( const struct V_1 * V_2 , void * V_57 )
{
switch ( V_2 -> type ) {
case 0 :
F_11 ( V_2 , V_58 , 4 ) ;
F_11 ( V_2 , V_59 , 5 ) ;
F_11 ( V_2 , V_60 , 8 ) ;
break;
case 1 :
F_11 ( V_2 , V_61 , 4 ) ;
F_11 ( V_2 , V_62 , 5 ) ;
F_11 ( V_2 , V_63 , 6 ) ;
F_11 ( V_2 , V_64 , 7 ) ;
F_12 ( V_2 , V_65 , 8 ) ;
break;
case 2 :
F_11 ( V_2 , V_66 , 4 ) ;
F_11 ( V_2 , V_67 , 5 ) ;
F_11 ( V_2 , V_68 , 6 ) ;
F_11 ( V_2 , V_69 , 7 ) ;
F_11 ( V_2 , V_70 , 8 ) ;
break;
case 3 :
F_11 ( V_2 , V_71 , 4 ) ;
F_13 ( V_2 , V_72 , 5 ) ;
F_11 ( V_2 , V_73 , 6 ) ;
F_11 ( V_2 , V_74 , 7 ) ;
F_11 ( V_2 , V_75 , 8 ) ;
break;
case 9 :
F_23 ( V_2 ) ;
break;
case 10 :
F_17 ( V_2 ) ;
break;
case 11 :
F_18 ( V_2 ) ;
break;
case 38 :
F_19 ( V_2 ) ;
break;
case 41 :
F_22 ( V_2 ) ;
}
}
static int T_1 F_30 ( char * V_10 , T_3 V_6 , const char * V_76 )
{
int V_77 = 0 ;
const char * V_23 ;
if ( ! V_76 )
return V_77 ;
for ( V_23 = V_76 ; * V_23 ; V_23 ++ )
if ( isprint ( * V_23 ) )
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_7 , * V_23 ) ;
else
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_8 , * V_23 & 0xff ) ;
return V_77 ;
}
static void T_1 F_32 ( char * V_10 , T_3 V_6 )
{
int V_77 = 0 ;
const char * V_78 ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 ,
F_33 ( V_61 ) ) ;
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_9 ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 ,
F_33 ( V_62 ) ) ;
V_78 = F_33 ( V_67 ) ;
if ( V_78 ) {
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_10 ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , V_78 ) ;
}
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_11 ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 ,
F_33 ( V_59 ) ) ;
V_77 += F_31 ( V_10 + V_77 , V_6 - V_77 , L_9 ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 ,
F_33 ( V_60 ) ) ;
}
static int T_1 F_34 ( const T_2 * V_10 )
{
T_4 V_79 ;
if ( memcmp ( V_10 , L_12 , 4 ) == 0 &&
V_10 [ 5 ] < 32 && F_10 ( V_10 , V_10 [ 5 ] ) ) {
V_79 = F_35 ( V_10 + 6 ) ;
V_80 = V_10 [ 5 ] ;
memcpy ( V_81 , V_10 , V_80 ) ;
switch ( V_79 ) {
case 0x021F :
case 0x0221 :
F_36 ( L_13 ,
V_79 & 0xFF , 3 ) ;
V_79 = 0x0203 ;
break;
case 0x0233 :
F_36 ( L_13 , 51 , 6 ) ;
V_79 = 0x0206 ;
break;
}
} else {
V_79 = 0 ;
}
V_10 += 16 ;
if ( memcmp ( V_10 , L_14 , 5 ) == 0 && F_10 ( V_10 , 15 ) ) {
if ( V_79 )
V_28 = V_79 ;
else
V_28 = ( V_10 [ 14 ] & 0xF0 ) << 4 | ( V_10 [ 14 ] & 0x0F ) ;
V_28 <<= 8 ;
V_14 = F_37 ( V_10 + 12 ) ;
V_15 = F_37 ( V_10 + 6 ) ;
V_18 = F_38 ( V_10 + 8 ) ;
if ( F_6 ( F_29 ) == 0 ) {
if ( V_79 ) {
F_39 ( L_15 ,
V_28 >> 16 , ( V_28 >> 8 ) & 0xFF ) ;
} else {
V_80 = 15 ;
memcpy ( V_81 , V_10 ,
V_80 ) ;
F_39 ( L_16 ,
V_28 >> 16 , ( V_28 >> 8 ) & 0xFF ) ;
}
F_32 ( V_82 , sizeof( V_82 ) ) ;
F_39 ( L_17 , V_82 ) ;
return 0 ;
}
}
return 1 ;
}
static int T_1 F_40 ( const T_2 * V_10 )
{
if ( memcmp ( V_10 , L_18 , 5 ) == 0 &&
V_10 [ 6 ] < 32 && F_10 ( V_10 , V_10 [ 6 ] ) ) {
V_28 = F_41 ( V_10 + 6 ) & 0xFFFFFF ;
V_14 = 0 ;
V_15 = F_38 ( V_10 + 12 ) ;
V_18 = F_42 ( V_10 + 16 ) ;
V_80 = V_10 [ 6 ] ;
memcpy ( V_81 , V_10 , V_80 ) ;
if ( F_6 ( F_29 ) == 0 ) {
F_39 ( L_19 ,
V_28 >> 16 , ( V_28 >> 8 ) & 0xFF ,
V_28 & 0xFF ) ;
F_32 ( V_82 , sizeof( V_82 ) ) ;
F_39 ( L_17 , V_82 ) ;
return 0 ;
}
}
return 1 ;
}
void T_1 F_43 ( void )
{
char T_5 * V_23 , * V_83 ;
char V_10 [ 32 ] ;
if ( F_44 ( V_84 ) ) {
if ( V_85 . V_86 != V_87 ) {
V_23 = F_7 ( V_85 . V_86 , 32 ) ;
if ( V_23 == NULL )
goto error;
F_45 ( V_10 , V_23 , 32 ) ;
F_9 ( V_23 , 32 ) ;
if ( ! F_40 ( V_10 ) ) {
V_56 = 1 ;
goto V_88;
}
}
if ( V_85 . V_89 == V_87 )
goto error;
V_23 = F_7 ( V_85 . V_89 , 32 ) ;
if ( V_23 == NULL )
goto error;
F_45 ( V_10 , V_23 , 32 ) ;
F_9 ( V_23 , 32 ) ;
if ( ! F_34 ( V_10 ) ) {
V_56 = 1 ;
goto V_88;
}
} else if ( F_46 ( V_90 ) ) {
V_23 = F_7 ( 0xF0000 , 0x10000 ) ;
if ( V_23 == NULL )
goto error;
memset ( V_10 , 0 , 16 ) ;
for ( V_83 = V_23 ; V_83 < V_23 + 0x10000 ; V_83 += 16 ) {
F_45 ( V_10 + 16 , V_83 , 16 ) ;
if ( ! F_40 ( V_10 ) || ! F_34 ( V_10 ) ) {
V_56 = 1 ;
F_9 ( V_23 , 0x10000 ) ;
goto V_88;
}
memcpy ( V_10 , V_10 + 16 , 16 ) ;
}
F_9 ( V_23 , 0x10000 ) ;
}
error:
F_39 ( L_20 ) ;
V_88:
V_91 = 1 ;
}
static T_6 F_47 ( struct V_92 * V_92 , struct V_93 * V_94 ,
struct V_95 * V_96 , char * V_10 ,
T_7 V_97 , T_3 V_35 )
{
memcpy ( V_10 , V_96 -> V_98 + V_97 , V_35 ) ;
return V_35 ;
}
static int T_1 F_48 ( void )
{
struct V_93 * V_99 ;
T_2 * V_100 ;
int V_101 = - V_102 ;
if ( ! V_56 ) {
V_101 = - V_103 ;
goto V_104;
}
V_105 = F_49 ( L_21 , V_106 ) ;
if ( ! V_105 )
goto V_104;
V_99 = F_49 ( L_22 , V_105 ) ;
if ( ! V_99 )
goto V_104;
V_100 = F_50 ( V_18 , V_15 ) ;
if ( ! V_100 )
goto V_107;
V_108 . V_109 = V_80 ;
V_108 . V_98 = V_81 ;
V_101 = F_51 ( V_99 , & V_108 ) ;
if ( V_101 )
goto V_110;
V_111 . V_109 = V_15 ;
V_111 . V_98 = V_100 ;
V_101 = F_51 ( V_99 , & V_111 ) ;
if ( ! V_101 )
return 0 ;
F_52 ( V_99 ,
& V_108 ) ;
V_110:
F_53 ( V_100 ) ;
V_107:
F_54 ( V_99 ) ;
F_55 ( V_99 ) ;
V_104:
F_56 ( L_23 ) ;
return V_101 ;
}
void T_1 F_57 ( void )
{
F_58 ( L_24 , V_82 ) ;
}
static bool F_59 ( const struct V_112 * V_113 )
{
int V_13 ;
F_60 ( ! V_91 , V_114 L_25 ) ;
for ( V_13 = 0 ; V_13 < F_61 ( V_113 -> V_115 ) ; V_13 ++ ) {
int V_3 = V_113 -> V_115 [ V_13 ] . V_21 ;
if ( V_3 == V_116 )
break;
if ( V_24 [ V_3 ] ) {
if ( ! V_113 -> V_115 [ V_13 ] . V_117 &&
strstr ( V_24 [ V_3 ] , V_113 -> V_115 [ V_13 ] . V_118 ) )
continue;
else if ( V_113 -> V_115 [ V_13 ] . V_117 &&
! strcmp ( V_24 [ V_3 ] , V_113 -> V_115 [ V_13 ] . V_118 ) )
continue;
}
return false ;
}
return true ;
}
static bool F_62 ( const struct V_112 * V_113 )
{
return V_113 -> V_115 [ 0 ] . V_21 == V_116 ;
}
int F_63 ( const struct V_112 * V_33 )
{
int V_35 = 0 ;
const struct V_112 * V_22 ;
for ( V_22 = V_33 ; ! F_62 ( V_22 ) ; V_22 ++ )
if ( F_59 ( V_22 ) ) {
V_35 ++ ;
if ( V_22 -> V_119 && V_22 -> V_119 ( V_22 ) )
break;
}
return V_35 ;
}
const struct V_112 * F_64 ( const struct V_112 * V_33 )
{
const struct V_112 * V_22 ;
for ( V_22 = V_33 ; ! F_62 ( V_22 ) ; V_22 ++ )
if ( F_59 ( V_22 ) )
return V_22 ;
return NULL ;
}
const char * F_33 ( int V_120 )
{
return V_24 [ V_120 ] ;
}
int F_65 ( const char * V_9 )
{
int V_121 = V_64 ;
if ( V_24 [ V_121 ] && strstr ( V_24 [ V_121 ] , V_9 ) )
return 1 ;
return 0 ;
}
int F_66 ( const char * V_9 )
{
static int V_122 [] = { V_61 , V_66 , V_116 } ;
int V_13 ;
for ( V_13 = 0 ; V_122 [ V_13 ] != V_116 ; V_13 ++ ) {
int V_121 = V_122 [ V_13 ] ;
if ( V_24 [ V_121 ] && strstr ( V_24 [ V_121 ] , V_9 ) )
return 1 ;
}
return 0 ;
}
const struct V_30 * F_15 ( int type , const char * V_29 ,
const struct V_30 * V_123 )
{
const struct V_124 * V_125 = V_123 ? & V_123 -> V_33 : & V_34 ;
struct V_124 * V_22 ;
for ( V_22 = V_125 -> V_126 ; V_22 != & V_34 ; V_22 = V_22 -> V_126 ) {
const struct V_30 * V_31 =
F_67 ( V_22 , struct V_30 , V_33 ) ;
if ( ( ( type == V_127 ) || ( V_31 -> type == type ) ) &&
( ( V_29 == NULL ) || ( strcmp ( V_31 -> V_29 , V_29 ) == 0 ) ) )
return V_31 ;
}
return NULL ;
}
bool F_68 ( int V_120 , int * V_128 , int * V_129 , int * V_130 )
{
int V_131 = 0 , V_132 = 0 , V_133 = 0 ;
bool V_134 ;
const char * V_3 , * V_135 ;
char * V_136 ;
V_3 = F_33 ( V_120 ) ;
V_134 = V_3 ;
if ( ! V_134 )
goto V_88;
V_135 = strrchr ( V_3 , '/' ) ;
if ( ! V_135 )
goto V_88;
V_135 ++ ;
V_131 = F_69 ( V_135 , & V_136 , 10 ) ;
if ( V_135 != V_136 && V_131 < 100 ) {
V_131 += 1900 ;
if ( V_131 < 1996 )
V_131 += 100 ;
}
if ( V_131 > 9999 )
V_131 = 0 ;
V_132 = F_69 ( V_3 , & V_136 , 10 ) ;
if ( V_3 == V_136 || * V_136 != '/' || ! V_132 || V_132 > 12 ) {
V_132 = 0 ;
goto V_88;
}
V_3 = V_136 + 1 ;
V_133 = F_69 ( V_3 , & V_136 , 10 ) ;
if ( V_3 == V_135 || V_3 == V_136 || * V_136 != '/' || V_133 > 31 )
V_133 = 0 ;
V_88:
if ( V_128 )
* V_128 = V_131 ;
if ( V_129 )
* V_129 = V_132 ;
if ( V_130 )
* V_130 = V_133 ;
return V_134 ;
}
int F_70 ( void (* F_5)( const struct V_1 * , void * ) ,
void * V_11 )
{
T_2 * V_10 ;
if ( ! V_56 )
return - 1 ;
V_10 = F_50 ( V_18 , V_15 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , F_5 , V_11 ) ;
F_53 ( V_10 ) ;
return 0 ;
}
bool F_71 ( enum V_137 V_121 , const char * V_9 )
{
const char * V_76 = F_33 ( V_121 ) ;
if ( V_76 == NULL || V_9 == NULL )
return V_76 == V_9 ;
return ! strcmp ( V_76 , V_9 ) ;
}
void F_72 ( V_45 V_53 , const char * * V_55 , const char * * V_54 )
{
int V_138 ;
if ( V_52 == NULL )
return;
for ( V_138 = 0 ; V_138 < V_49 ; V_138 ++ ) {
if ( V_53 == V_52 [ V_138 ] . V_53 ) {
* V_55 = V_52 [ V_138 ] . V_55 ;
* V_54 = V_52 [ V_138 ] . V_54 ;
break;
}
}
}
