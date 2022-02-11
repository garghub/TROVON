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
static char * T_1 F_2 ( const struct V_1 * V_2 , T_2 V_3 )
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
else
F_4 ( V_10 L_2 , V_6 ) ;
return V_9 ;
}
static void F_5 ( T_2 * V_11 , int V_6 , int V_12 ,
void (* F_6)( const struct V_1 * , void * ) ,
void * V_13 )
{
T_2 * V_14 = V_11 ;
int V_15 = 0 ;
while ( ( V_15 < V_12 ) && ( V_14 - V_11 + sizeof( struct V_1 ) ) <= V_6 ) {
const struct V_1 * V_2 = ( const struct V_1 * ) V_14 ;
V_14 += V_2 -> V_5 ;
while ( ( V_14 - V_11 < V_6 - 1 ) && ( V_14 [ 0 ] || V_14 [ 1 ] ) )
V_14 ++ ;
if ( V_14 - V_11 < V_6 - 1 )
F_6 ( V_2 , V_13 ) ;
V_14 += 2 ;
V_15 ++ ;
}
}
static int T_1 F_7 ( void (* F_6)( const struct V_1 * ,
void * ) )
{
T_2 * V_11 ;
V_11 = F_8 ( V_16 , V_17 ) ;
if ( V_11 == NULL )
return - 1 ;
F_5 ( V_11 , V_17 , V_18 , F_6 , NULL ) ;
F_9 ( V_11 , V_17 ) ;
return 0 ;
}
static int T_1 F_10 ( const T_2 * V_11 )
{
T_2 V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 15 ; V_20 ++ )
V_19 += V_11 [ V_20 ] ;
return V_19 == 0 ;
}
static void T_1 F_11 ( const struct V_1 * V_2 , int V_21 , int string )
{
const char * V_22 = ( const char * ) V_2 ;
char * V_23 ;
if ( V_24 [ V_21 ] )
return;
V_23 = F_2 ( V_2 , V_22 [ string ] ) ;
if ( V_23 == NULL )
return;
V_24 [ V_21 ] = V_23 ;
}
static void T_1 F_12 ( const struct V_1 * V_2 , int V_21 , int V_25 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + V_25 ;
char * V_3 ;
int V_26 = 1 , V_27 = 1 , V_15 ;
if ( V_24 [ V_21 ] )
return;
for ( V_15 = 0 ; V_15 < 16 && ( V_26 || V_27 ) ; V_15 ++ ) {
if( V_22 [ V_15 ] != 0x00 ) V_26 = 0 ;
if( V_22 [ V_15 ] != 0xFF ) V_27 = 0 ;
}
if ( V_26 || V_27 )
return;
V_3 = F_3 ( 16 * 2 + 4 + 1 ) ;
if ( ! V_3 )
return;
sprintf ( V_3 , L_3 , V_22 ) ;
V_24 [ V_21 ] = V_3 ;
}
static void T_1 F_13 ( const struct V_1 * V_2 , int V_21 , int V_25 )
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
static void T_1 F_14 ( int type , const char * V_28 )
{
struct V_29 * V_30 ;
if ( F_15 ( type , V_28 , NULL ) )
return;
V_30 = F_3 ( sizeof( * V_30 ) + strlen ( V_28 ) + 1 ) ;
if ( ! V_30 ) {
F_4 ( V_10 L_5 ) ;
return;
}
V_30 -> type = type ;
strcpy ( ( char * ) ( V_30 + 1 ) , V_28 ) ;
V_30 -> V_28 = ( char * ) ( V_30 + 1 ) ;
V_30 -> V_31 = NULL ;
F_16 ( & V_30 -> V_32 , & V_33 ) ;
}
static void T_1 F_17 ( const struct V_1 * V_2 )
{
int V_15 , V_34 = ( V_2 -> V_5 - sizeof( struct V_1 ) ) / 2 ;
for ( V_15 = 0 ; V_15 < V_34 ; V_15 ++ ) {
const char * V_22 = ( char * ) ( V_2 + 1 ) + ( V_15 * 2 ) ;
if ( ( * V_22 & 0x80 ) == 0 )
continue;
F_14 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 + 1 ) ) ) ;
}
}
static void T_1 F_18 ( const struct V_1 * V_2 )
{
int V_15 , V_34 = * ( T_2 * ) ( V_2 + 1 ) ;
struct V_29 * V_30 ;
for ( V_15 = 1 ; V_15 <= V_34 ; V_15 ++ ) {
char * V_35 = F_2 ( V_2 , V_15 ) ;
if ( V_35 == V_8 )
continue;
V_30 = F_3 ( sizeof( * V_30 ) ) ;
if ( ! V_30 ) {
F_4 ( V_10
L_6 ) ;
break;
}
V_30 -> type = V_36 ;
V_30 -> V_28 = V_35 ;
V_30 -> V_31 = NULL ;
F_16 ( & V_30 -> V_32 , & V_33 ) ;
}
}
static void T_1 F_19 ( const struct V_1 * V_2 )
{
struct V_29 * V_30 ;
void * V_14 ;
V_14 = F_3 ( V_2 -> V_5 ) ;
if ( V_14 == NULL ) {
F_4 ( V_10 L_7 ) ;
return;
}
memcpy ( V_14 , V_2 , V_2 -> V_5 ) ;
V_30 = F_3 ( sizeof( * V_30 ) ) ;
if ( ! V_30 ) {
F_4 ( V_10 L_7 ) ;
return;
}
V_30 -> type = V_37 ;
V_30 -> V_28 = L_8 ;
V_30 -> V_31 = V_14 ;
F_20 ( & V_30 -> V_32 , & V_33 ) ;
}
static void T_1 F_21 ( int V_38 , int V_39 , int V_40 ,
int V_41 , const char * V_28 )
{
struct V_42 * V_43 ;
V_43 = F_3 ( sizeof( * V_43 ) + strlen ( V_28 ) + 1 ) ;
if ( ! V_43 ) {
F_4 ( V_10 L_9 ) ;
return;
}
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
const T_2 * V_22 = ( T_2 * ) V_2 + 5 ;
if ( ( * V_22 & 0x80 ) == 0 )
return;
F_21 ( * ( V_22 + 1 ) , * ( V_45 * ) ( V_22 + 2 ) , * ( V_22 + 4 ) , * ( V_22 + 5 ) ,
F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
F_14 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
}
static void T_1 F_23 ( const struct V_1 * V_2 , void * V_46 )
{
switch( V_2 -> type ) {
case 0 :
F_11 ( V_2 , V_47 , 4 ) ;
F_11 ( V_2 , V_48 , 5 ) ;
F_11 ( V_2 , V_49 , 8 ) ;
break;
case 1 :
F_11 ( V_2 , V_50 , 4 ) ;
F_11 ( V_2 , V_51 , 5 ) ;
F_11 ( V_2 , V_52 , 6 ) ;
F_11 ( V_2 , V_53 , 7 ) ;
F_12 ( V_2 , V_54 , 8 ) ;
break;
case 2 :
F_11 ( V_2 , V_55 , 4 ) ;
F_11 ( V_2 , V_56 , 5 ) ;
F_11 ( V_2 , V_57 , 6 ) ;
F_11 ( V_2 , V_58 , 7 ) ;
F_11 ( V_2 , V_59 , 8 ) ;
break;
case 3 :
F_11 ( V_2 , V_60 , 4 ) ;
F_13 ( V_2 , V_61 , 5 ) ;
F_11 ( V_2 , V_62 , 6 ) ;
F_11 ( V_2 , V_63 , 7 ) ;
F_11 ( V_2 , V_64 , 8 ) ;
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
static void T_1 F_24 ( const char * V_65 )
{
const char * V_23 ;
if ( ! V_65 )
return;
for ( V_23 = V_65 ; * V_23 ; V_23 ++ )
if ( isprint ( * V_23 ) )
F_4 ( V_66 L_10 , * V_23 ) ;
else
F_4 ( V_66 L_11 , * V_23 & 0xff ) ;
}
static void T_1 F_25 ( void )
{
const char * V_67 ;
F_4 ( V_68 L_12 ) ;
F_24 ( F_26 ( V_50 ) ) ;
F_4 ( V_66 L_13 ) ;
F_24 ( F_26 ( V_51 ) ) ;
V_67 = F_26 ( V_56 ) ;
if ( V_67 ) {
F_4 ( V_66 L_14 ) ;
F_24 ( V_67 ) ;
}
F_4 ( V_66 L_15 ) ;
F_24 ( F_26 ( V_48 ) ) ;
F_4 ( V_66 L_13 ) ;
F_24 ( F_26 ( V_49 ) ) ;
F_4 ( V_66 L_16 ) ;
}
static int T_1 F_27 ( const char T_4 * V_23 )
{
T_2 V_11 [ 15 ] ;
F_28 ( V_11 , V_23 , 15 ) ;
if ( ( memcmp ( V_11 , L_17 , 5 ) == 0 ) && F_10 ( V_11 ) ) {
V_18 = ( V_11 [ 13 ] << 8 ) | V_11 [ 12 ] ;
V_17 = ( V_11 [ 7 ] << 8 ) | V_11 [ 6 ] ;
V_16 = ( V_11 [ 11 ] << 24 ) | ( V_11 [ 10 ] << 16 ) |
( V_11 [ 9 ] << 8 ) | V_11 [ 8 ] ;
if ( V_11 [ 14 ] != 0 )
F_4 ( V_69 L_18 ,
V_11 [ 14 ] >> 4 , V_11 [ 14 ] & 0xF ) ;
else
F_4 ( V_69 L_19 ) ;
if ( F_7 ( F_23 ) == 0 ) {
F_25 () ;
return 0 ;
}
}
return 1 ;
}
void T_1 F_29 ( void )
{
char T_4 * V_23 , * V_70 ;
int V_71 ;
if ( V_72 ) {
if ( V_73 . V_74 == V_75 )
goto error;
V_23 = F_8 ( V_73 . V_74 , 32 ) ;
if ( V_23 == NULL )
goto error;
V_71 = F_27 ( V_23 + 0x10 ) ;
F_9 ( V_23 , 32 ) ;
if ( ! V_71 ) {
V_76 = 1 ;
goto V_77;
}
}
else {
V_23 = F_8 ( 0xF0000 , 0x10000 ) ;
if ( V_23 == NULL )
goto error;
for ( V_70 = V_23 ; V_70 < V_23 + 0x10000 ; V_70 += 16 ) {
V_71 = F_27 ( V_70 ) ;
if ( ! V_71 ) {
V_76 = 1 ;
F_9 ( V_23 , 0x10000 ) ;
goto V_77;
}
}
F_9 ( V_23 , 0x10000 ) ;
}
error:
F_4 ( V_69 L_20 ) ;
V_77:
V_78 = 1 ;
}
static bool F_30 ( const struct V_79 * V_80 )
{
int V_15 ;
F_31 ( ! V_78 , V_10 L_21 ) ;
for ( V_15 = 0 ; V_15 < F_32 ( V_80 -> V_81 ) ; V_15 ++ ) {
int V_3 = V_80 -> V_81 [ V_15 ] . V_21 ;
if ( V_3 == V_82 )
break;
if ( V_24 [ V_3 ]
&& strstr ( V_24 [ V_3 ] , V_80 -> V_81 [ V_15 ] . V_83 ) )
continue;
return false ;
}
return true ;
}
static bool F_33 ( const struct V_79 * V_80 )
{
return V_80 -> V_81 [ 0 ] . V_21 == V_82 ;
}
int F_34 ( const struct V_79 * V_32 )
{
int V_34 = 0 ;
const struct V_79 * V_22 ;
for ( V_22 = V_32 ; ! F_33 ( V_22 ) ; V_22 ++ )
if ( F_30 ( V_22 ) ) {
V_34 ++ ;
if ( V_22 -> V_84 && V_22 -> V_84 ( V_22 ) )
break;
}
return V_34 ;
}
const struct V_79 * F_35 ( const struct V_79 * V_32 )
{
const struct V_79 * V_22 ;
for ( V_22 = V_32 ; ! F_33 ( V_22 ) ; V_22 ++ )
if ( F_30 ( V_22 ) )
return V_22 ;
return NULL ;
}
const char * F_26 ( int V_85 )
{
return V_24 [ V_85 ] ;
}
int F_36 ( const char * V_9 )
{
int V_86 = V_53 ;
if ( V_24 [ V_86 ] && strstr ( V_24 [ V_86 ] , V_9 ) )
return 1 ;
return 0 ;
}
int F_37 ( const char * V_9 )
{
static int V_87 [] = { V_47 , V_48 , V_50 ,
V_51 , V_52 , V_55 ,
V_56 , V_57 , V_82 } ;
int V_15 ;
for ( V_15 = 0 ; V_87 [ V_15 ] != V_82 ; V_15 ++ ) {
int V_86 = V_87 [ V_15 ] ;
if ( V_24 [ V_86 ] && strstr ( V_24 [ V_86 ] , V_9 ) )
return 1 ;
}
return 0 ;
}
const struct V_29 * F_15 ( int type , const char * V_28 ,
const struct V_29 * V_88 )
{
const struct V_89 * V_90 = V_88 ? & V_88 -> V_32 : & V_33 ;
struct V_89 * V_22 ;
for( V_22 = V_90 -> V_91 ; V_22 != & V_33 ; V_22 = V_22 -> V_91 ) {
const struct V_29 * V_30 =
F_38 ( V_22 , struct V_29 , V_32 ) ;
if ( ( ( type == V_92 ) || ( V_30 -> type == type ) ) &&
( ( V_28 == NULL ) || ( strcmp ( V_30 -> V_28 , V_28 ) == 0 ) ) )
return V_30 ;
}
return NULL ;
}
bool F_39 ( int V_85 , int * V_93 , int * V_94 , int * V_95 )
{
int V_96 = 0 , V_97 = 0 , V_98 = 0 ;
bool V_99 ;
const char * V_3 , * V_100 ;
char * V_101 ;
V_3 = F_26 ( V_85 ) ;
V_99 = V_3 ;
if ( ! V_99 )
goto V_77;
V_100 = strrchr ( V_3 , '/' ) ;
if ( ! V_100 )
goto V_77;
V_100 ++ ;
V_96 = F_40 ( V_100 , & V_101 , 10 ) ;
if ( V_100 != V_101 && V_96 < 100 ) {
V_96 += 1900 ;
if ( V_96 < 1996 )
V_96 += 100 ;
}
if ( V_96 > 9999 )
V_96 = 0 ;
V_97 = F_40 ( V_3 , & V_101 , 10 ) ;
if ( V_3 == V_101 || * V_101 != '/' || ! V_97 || V_97 > 12 ) {
V_97 = 0 ;
goto V_77;
}
V_3 = V_101 + 1 ;
V_98 = F_40 ( V_3 , & V_101 , 10 ) ;
if ( V_3 == V_100 || V_3 == V_101 || * V_101 != '/' || V_98 > 31 )
V_98 = 0 ;
V_77:
if ( V_93 )
* V_93 = V_96 ;
if ( V_94 )
* V_94 = V_97 ;
if ( V_95 )
* V_95 = V_98 ;
return V_99 ;
}
int F_41 ( void (* F_6)( const struct V_1 * , void * ) ,
void * V_13 )
{
T_2 * V_11 ;
if ( ! V_76 )
return - 1 ;
V_11 = F_42 ( V_16 , V_17 ) ;
if ( V_11 == NULL )
return - 1 ;
F_5 ( V_11 , V_17 , V_18 , F_6 , V_13 ) ;
F_43 ( V_11 ) ;
return 0 ;
}
bool F_44 ( enum V_102 V_86 , const char * V_9 )
{
const char * V_65 = F_26 ( V_86 ) ;
if ( V_65 == NULL || V_9 == NULL )
return V_65 == V_9 ;
return ! strcmp ( V_65 , V_9 ) ;
}
