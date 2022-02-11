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
static void F_4 ( T_2 * V_10 , int V_6 , int V_11 ,
void (* F_5)( const struct V_1 * , void * ) ,
void * V_12 )
{
T_2 * V_13 = V_10 ;
int V_14 = 0 ;
while ( ( V_14 < V_11 ) && ( V_13 - V_10 + sizeof( struct V_1 ) ) <= V_6 ) {
const struct V_1 * V_2 = ( const struct V_1 * ) V_13 ;
V_13 += V_2 -> V_5 ;
while ( ( V_13 - V_10 < V_6 - 1 ) && ( V_13 [ 0 ] || V_13 [ 1 ] ) )
V_13 ++ ;
if ( V_13 - V_10 < V_6 - 1 )
F_5 ( V_2 , V_12 ) ;
V_13 += 2 ;
V_14 ++ ;
}
}
static int T_1 F_6 ( void (* F_5)( const struct V_1 * ,
void * ) )
{
T_2 * V_10 ;
V_10 = F_7 ( V_15 , V_16 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , V_16 , V_17 , F_5 , NULL ) ;
F_8 ( V_10 , V_16 ) ;
F_9 ( V_10 , V_16 ) ;
return 0 ;
}
static int T_1 F_10 ( const T_2 * V_10 , T_2 V_6 )
{
T_2 V_18 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 ; V_19 ++ )
V_18 += V_10 [ V_19 ] ;
return V_18 == 0 ;
}
static void T_1 F_11 ( const struct V_1 * V_2 , int V_20 ,
int string )
{
const char * V_21 = ( const char * ) V_2 ;
const char * V_22 ;
if ( V_23 [ V_20 ] )
return;
V_22 = F_2 ( V_2 , V_21 [ string ] ) ;
if ( V_22 == NULL )
return;
V_23 [ V_20 ] = V_22 ;
}
static void T_1 F_12 ( const struct V_1 * V_2 , int V_20 ,
int V_24 )
{
const T_2 * V_21 = ( T_2 * ) V_2 + V_24 ;
char * V_3 ;
int V_25 = 1 , V_26 = 1 , V_14 ;
if ( V_23 [ V_20 ] )
return;
for ( V_14 = 0 ; V_14 < 16 && ( V_25 || V_26 ) ; V_14 ++ ) {
if ( V_21 [ V_14 ] != 0x00 )
V_26 = 0 ;
if ( V_21 [ V_14 ] != 0xFF )
V_25 = 0 ;
}
if ( V_25 || V_26 )
return;
V_3 = F_3 ( 16 * 2 + 4 + 1 ) ;
if ( ! V_3 )
return;
if ( V_27 >= 0x0206 )
sprintf ( V_3 , L_2 , V_21 ) ;
else
sprintf ( V_3 , L_3 , V_21 ) ;
V_23 [ V_20 ] = V_3 ;
}
static void T_1 F_13 ( const struct V_1 * V_2 , int V_20 ,
int V_24 )
{
const T_2 * V_21 = ( T_2 * ) V_2 + V_24 ;
char * V_3 ;
if ( V_23 [ V_20 ] )
return;
V_3 = F_3 ( 4 ) ;
if ( ! V_3 )
return;
sprintf ( V_3 , L_4 , * V_21 & 0x7F ) ;
V_23 [ V_20 ] = V_3 ;
}
static void T_1 F_14 ( int type , const char * V_28 )
{
struct V_29 * V_30 ;
if ( F_15 ( type , V_28 , NULL ) )
return;
V_30 = F_3 ( sizeof( * V_30 ) + strlen ( V_28 ) + 1 ) ;
if ( ! V_30 )
return;
V_30 -> type = type ;
strcpy ( ( char * ) ( V_30 + 1 ) , V_28 ) ;
V_30 -> V_28 = ( char * ) ( V_30 + 1 ) ;
V_30 -> V_31 = NULL ;
F_16 ( & V_30 -> V_32 , & V_33 ) ;
}
static void T_1 F_17 ( const struct V_1 * V_2 )
{
int V_14 , V_34 = ( V_2 -> V_5 - sizeof( struct V_1 ) ) / 2 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
const char * V_21 = ( char * ) ( V_2 + 1 ) + ( V_14 * 2 ) ;
if ( ( * V_21 & 0x80 ) == 0 )
continue;
F_14 ( * V_21 & 0x7f , F_1 ( V_2 , * ( V_21 + 1 ) ) ) ;
}
}
static void T_1 F_18 ( const struct V_1 * V_2 )
{
int V_14 , V_34 = * ( T_2 * ) ( V_2 + 1 ) ;
struct V_29 * V_30 ;
for ( V_14 = 1 ; V_14 <= V_34 ; V_14 ++ ) {
const char * V_35 = F_2 ( V_2 , V_14 ) ;
if ( V_35 == V_8 )
continue;
V_30 = F_3 ( sizeof( * V_30 ) ) ;
if ( ! V_30 )
break;
V_30 -> type = V_36 ;
V_30 -> V_28 = V_35 ;
V_30 -> V_31 = NULL ;
F_16 ( & V_30 -> V_32 , & V_33 ) ;
}
}
static void T_1 F_19 ( const struct V_1 * V_2 )
{
struct V_29 * V_30 ;
void * V_13 ;
V_13 = F_3 ( V_2 -> V_5 ) ;
if ( V_13 == NULL )
return;
memcpy ( V_13 , V_2 , V_2 -> V_5 ) ;
V_30 = F_3 ( sizeof( * V_30 ) ) ;
if ( ! V_30 )
return;
V_30 -> type = V_37 ;
V_30 -> V_28 = L_5 ;
V_30 -> V_31 = V_13 ;
F_20 ( & V_30 -> V_32 , & V_33 ) ;
}
static void T_1 F_21 ( int V_38 , int V_39 , int V_40 ,
int V_41 , const char * V_28 )
{
struct V_42 * V_43 ;
V_43 = F_3 ( sizeof( * V_43 ) + strlen ( V_28 ) + 1 ) ;
if ( ! V_43 )
return;
V_43 -> V_38 = V_38 ;
V_43 -> V_39 = V_39 ;
V_43 -> V_40 = V_40 ;
V_43 -> V_41 = V_41 ;
strcpy ( ( char * ) & V_43 [ 1 ] , V_28 ) ;
V_43 -> V_30 . type = V_44 ;
V_43 -> V_30 . V_28 = ( char * ) & V_43 [ 1 ] ;
V_43 -> V_30 . V_31 = V_43 ;
F_16 ( & V_43 -> V_30 . V_32 , & V_33 ) ;
}
static void T_1 F_22 ( const struct V_1 * V_2 )
{
const T_2 * V_21 = ( T_2 * ) V_2 + 5 ;
if ( ( * V_21 & 0x80 ) == 0 )
return;
F_21 ( * ( V_21 + 1 ) , * ( V_45 * ) ( V_21 + 2 ) , * ( V_21 + 4 ) , * ( V_21 + 5 ) ,
F_1 ( V_2 , * ( V_21 - 1 ) ) ) ;
F_14 ( * V_21 & 0x7f , F_1 ( V_2 , * ( V_21 - 1 ) ) ) ;
}
static void T_1 F_23 ( const struct V_1 * V_2 , void * V_46 )
{
if ( V_2 -> type != V_47 )
return;
V_48 ++ ;
}
static void T_1 F_24 ( const struct V_1 * V_2 , void * V_46 )
{
const char * V_21 = ( const char * ) V_2 ;
static int V_49 ;
if ( V_2 -> type != V_47 )
return;
if ( V_49 >= V_48 ) {
F_25 ( V_50 L_6 ) ;
return;
}
V_51 [ V_49 ] . V_52 = F_26 ( & V_2 -> V_52 ) ;
V_51 [ V_49 ] . V_53 = F_2 ( V_2 , V_21 [ 0x10 ] ) ;
V_51 [ V_49 ] . V_54 = F_2 ( V_2 , V_21 [ 0x11 ] ) ;
V_49 ++ ;
}
void T_1 F_27 ( void )
{
if ( ! V_55 )
return;
if ( F_6 ( F_23 ) == 0 && V_48 ) {
V_51 = F_3 ( sizeof( * V_51 ) * V_48 ) ;
if ( V_51 )
F_6 ( F_24 ) ;
}
}
static void T_1 F_28 ( const struct V_1 * V_2 , void * V_56 )
{
switch ( V_2 -> type ) {
case 0 :
F_11 ( V_2 , V_57 , 4 ) ;
F_11 ( V_2 , V_58 , 5 ) ;
F_11 ( V_2 , V_59 , 8 ) ;
break;
case 1 :
F_11 ( V_2 , V_60 , 4 ) ;
F_11 ( V_2 , V_61 , 5 ) ;
F_11 ( V_2 , V_62 , 6 ) ;
F_11 ( V_2 , V_63 , 7 ) ;
F_12 ( V_2 , V_64 , 8 ) ;
break;
case 2 :
F_11 ( V_2 , V_65 , 4 ) ;
F_11 ( V_2 , V_66 , 5 ) ;
F_11 ( V_2 , V_67 , 6 ) ;
F_11 ( V_2 , V_68 , 7 ) ;
F_11 ( V_2 , V_69 , 8 ) ;
break;
case 3 :
F_11 ( V_2 , V_70 , 4 ) ;
F_13 ( V_2 , V_71 , 5 ) ;
F_11 ( V_2 , V_72 , 6 ) ;
F_11 ( V_2 , V_73 , 7 ) ;
F_11 ( V_2 , V_74 , 8 ) ;
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
static int T_1 F_29 ( char * V_10 , T_3 V_6 , const char * V_75 )
{
int V_76 = 0 ;
const char * V_22 ;
if ( ! V_75 )
return V_76 ;
for ( V_22 = V_75 ; * V_22 ; V_22 ++ )
if ( isprint ( * V_22 ) )
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_7 , * V_22 ) ;
else
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_8 , * V_22 & 0xff ) ;
return V_76 ;
}
static void T_1 F_31 ( char * V_10 , T_3 V_6 )
{
int V_76 = 0 ;
const char * V_77 ;
V_76 += F_29 ( V_10 + V_76 , V_6 - V_76 ,
F_32 ( V_60 ) ) ;
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_9 ) ;
V_76 += F_29 ( V_10 + V_76 , V_6 - V_76 ,
F_32 ( V_61 ) ) ;
V_77 = F_32 ( V_66 ) ;
if ( V_77 ) {
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_10 ) ;
V_76 += F_29 ( V_10 + V_76 , V_6 - V_76 , V_77 ) ;
}
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_11 ) ;
V_76 += F_29 ( V_10 + V_76 , V_6 - V_76 ,
F_32 ( V_58 ) ) ;
V_76 += F_30 ( V_10 + V_76 , V_6 - V_76 , L_9 ) ;
V_76 += F_29 ( V_10 + V_76 , V_6 - V_76 ,
F_32 ( V_59 ) ) ;
}
static int T_1 F_33 ( const T_2 * V_10 )
{
int V_78 ;
if ( memcmp ( V_10 , L_12 , 4 ) == 0 &&
V_10 [ 5 ] < 32 && F_10 ( V_10 , V_10 [ 5 ] ) ) {
V_78 = ( V_10 [ 6 ] << 8 ) + V_10 [ 7 ] ;
switch ( V_78 ) {
case 0x021F :
case 0x0221 :
F_34 ( L_13 ,
V_78 & 0xFF , 3 ) ;
V_78 = 0x0203 ;
break;
case 0x0233 :
F_34 ( L_13 , 51 , 6 ) ;
V_78 = 0x0206 ;
break;
}
} else {
V_78 = 0 ;
}
V_10 += 16 ;
if ( memcmp ( V_10 , L_14 , 5 ) == 0 && F_10 ( V_10 , 15 ) ) {
V_17 = ( V_10 [ 13 ] << 8 ) | V_10 [ 12 ] ;
V_16 = ( V_10 [ 7 ] << 8 ) | V_10 [ 6 ] ;
V_15 = ( V_10 [ 11 ] << 24 ) | ( V_10 [ 10 ] << 16 ) |
( V_10 [ 9 ] << 8 ) | V_10 [ 8 ] ;
if ( F_6 ( F_28 ) == 0 ) {
if ( V_78 ) {
V_27 = V_78 ;
F_35 ( L_15 ,
V_27 >> 8 , V_27 & 0xFF ) ;
} else {
V_27 = ( V_10 [ 14 ] & 0xF0 ) << 4 |
( V_10 [ 14 ] & 0x0F ) ;
F_35 ( L_16 ,
V_27 >> 8 , V_27 & 0xFF ) ;
}
F_31 ( V_79 , sizeof( V_79 ) ) ;
F_36 ( V_80 L_17 , V_79 ) ;
return 0 ;
}
}
return 1 ;
}
void T_1 F_37 ( void )
{
char T_4 * V_22 , * V_81 ;
char V_10 [ 32 ] ;
if ( F_38 ( V_82 ) ) {
if ( V_83 . V_84 == V_85 )
goto error;
V_22 = F_7 ( V_83 . V_84 , 32 ) ;
if ( V_22 == NULL )
goto error;
F_39 ( V_10 , V_22 , 32 ) ;
F_9 ( V_22 , 32 ) ;
if ( ! F_33 ( V_10 ) ) {
V_55 = 1 ;
goto V_86;
}
} else {
V_22 = F_7 ( 0xF0000 , 0x10000 ) ;
if ( V_22 == NULL )
goto error;
memset ( V_10 , 0 , 16 ) ;
for ( V_81 = V_22 ; V_81 < V_22 + 0x10000 ; V_81 += 16 ) {
F_39 ( V_10 + 16 , V_81 , 16 ) ;
if ( ! F_33 ( V_10 ) ) {
V_55 = 1 ;
F_9 ( V_22 , 0x10000 ) ;
goto V_86;
}
memcpy ( V_10 , V_10 + 16 , 16 ) ;
}
F_9 ( V_22 , 0x10000 ) ;
}
error:
F_35 ( L_18 ) ;
V_86:
V_87 = 1 ;
}
void T_1 F_40 ( void )
{
F_41 ( L_19 , V_79 ) ;
}
static bool F_42 ( const struct V_88 * V_89 )
{
int V_14 ;
F_43 ( ! V_87 , V_90 L_20 ) ;
for ( V_14 = 0 ; V_14 < F_44 ( V_89 -> V_91 ) ; V_14 ++ ) {
int V_3 = V_89 -> V_91 [ V_14 ] . V_20 ;
if ( V_3 == V_92 )
break;
if ( V_23 [ V_3 ] ) {
if ( ! V_89 -> V_91 [ V_14 ] . V_93 &&
strstr ( V_23 [ V_3 ] , V_89 -> V_91 [ V_14 ] . V_94 ) )
continue;
else if ( V_89 -> V_91 [ V_14 ] . V_93 &&
! strcmp ( V_23 [ V_3 ] , V_89 -> V_91 [ V_14 ] . V_94 ) )
continue;
}
return false ;
}
return true ;
}
static bool F_45 ( const struct V_88 * V_89 )
{
return V_89 -> V_91 [ 0 ] . V_20 == V_92 ;
}
int F_46 ( const struct V_88 * V_32 )
{
int V_34 = 0 ;
const struct V_88 * V_21 ;
for ( V_21 = V_32 ; ! F_45 ( V_21 ) ; V_21 ++ )
if ( F_42 ( V_21 ) ) {
V_34 ++ ;
if ( V_21 -> V_95 && V_21 -> V_95 ( V_21 ) )
break;
}
return V_34 ;
}
const struct V_88 * F_47 ( const struct V_88 * V_32 )
{
const struct V_88 * V_21 ;
for ( V_21 = V_32 ; ! F_45 ( V_21 ) ; V_21 ++ )
if ( F_42 ( V_21 ) )
return V_21 ;
return NULL ;
}
const char * F_32 ( int V_96 )
{
return V_23 [ V_96 ] ;
}
int F_48 ( const char * V_9 )
{
int V_97 = V_63 ;
if ( V_23 [ V_97 ] && strstr ( V_23 [ V_97 ] , V_9 ) )
return 1 ;
return 0 ;
}
int F_49 ( const char * V_9 )
{
static int V_98 [] = { V_60 , V_65 , V_92 } ;
int V_14 ;
for ( V_14 = 0 ; V_98 [ V_14 ] != V_92 ; V_14 ++ ) {
int V_97 = V_98 [ V_14 ] ;
if ( V_23 [ V_97 ] && strstr ( V_23 [ V_97 ] , V_9 ) )
return 1 ;
}
return 0 ;
}
const struct V_29 * F_15 ( int type , const char * V_28 ,
const struct V_29 * V_99 )
{
const struct V_100 * V_101 = V_99 ? & V_99 -> V_32 : & V_33 ;
struct V_100 * V_21 ;
for ( V_21 = V_101 -> V_102 ; V_21 != & V_33 ; V_21 = V_21 -> V_102 ) {
const struct V_29 * V_30 =
F_50 ( V_21 , struct V_29 , V_32 ) ;
if ( ( ( type == V_103 ) || ( V_30 -> type == type ) ) &&
( ( V_28 == NULL ) || ( strcmp ( V_30 -> V_28 , V_28 ) == 0 ) ) )
return V_30 ;
}
return NULL ;
}
bool F_51 ( int V_96 , int * V_104 , int * V_105 , int * V_106 )
{
int V_107 = 0 , V_108 = 0 , V_109 = 0 ;
bool V_110 ;
const char * V_3 , * V_111 ;
char * V_112 ;
V_3 = F_32 ( V_96 ) ;
V_110 = V_3 ;
if ( ! V_110 )
goto V_86;
V_111 = strrchr ( V_3 , '/' ) ;
if ( ! V_111 )
goto V_86;
V_111 ++ ;
V_107 = F_52 ( V_111 , & V_112 , 10 ) ;
if ( V_111 != V_112 && V_107 < 100 ) {
V_107 += 1900 ;
if ( V_107 < 1996 )
V_107 += 100 ;
}
if ( V_107 > 9999 )
V_107 = 0 ;
V_108 = F_52 ( V_3 , & V_112 , 10 ) ;
if ( V_3 == V_112 || * V_112 != '/' || ! V_108 || V_108 > 12 ) {
V_108 = 0 ;
goto V_86;
}
V_3 = V_112 + 1 ;
V_109 = F_52 ( V_3 , & V_112 , 10 ) ;
if ( V_3 == V_111 || V_3 == V_112 || * V_112 != '/' || V_109 > 31 )
V_109 = 0 ;
V_86:
if ( V_104 )
* V_104 = V_107 ;
if ( V_105 )
* V_105 = V_108 ;
if ( V_106 )
* V_106 = V_109 ;
return V_110 ;
}
int F_53 ( void (* F_5)( const struct V_1 * , void * ) ,
void * V_12 )
{
T_2 * V_10 ;
if ( ! V_55 )
return - 1 ;
V_10 = F_54 ( V_15 , V_16 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , V_16 , V_17 , F_5 , V_12 ) ;
F_55 ( V_10 ) ;
return 0 ;
}
bool F_56 ( enum V_113 V_97 , const char * V_9 )
{
const char * V_75 = F_32 ( V_97 ) ;
if ( V_75 == NULL || V_9 == NULL )
return V_75 == V_9 ;
return ! strcmp ( V_75 , V_9 ) ;
}
void F_57 ( V_45 V_52 , const char * * V_54 , const char * * V_53 )
{
int V_114 ;
if ( V_51 == NULL )
return;
for ( V_114 = 0 ; V_114 < V_48 ; V_114 ++ ) {
if ( V_52 == V_51 [ V_114 ] . V_52 ) {
* V_54 = V_51 [ V_114 ] . V_54 ;
* V_53 = V_51 [ V_114 ] . V_53 ;
break;
}
}
}
