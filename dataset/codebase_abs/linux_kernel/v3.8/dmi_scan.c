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
F_10 ( V_11 , V_17 ) ;
return 0 ;
}
static int T_1 F_11 ( const T_2 * V_11 , T_2 V_6 )
{
T_2 V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 ; V_20 ++ )
V_19 += V_11 [ V_20 ] ;
return V_19 == 0 ;
}
static void T_1 F_12 ( const struct V_1 * V_2 , int V_21 , int string )
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
static void T_1 F_13 ( const struct V_1 * V_2 , int V_21 , int V_25 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + V_25 ;
char * V_3 ;
int V_26 = 1 , V_27 = 1 , V_15 ;
if ( V_24 [ V_21 ] )
return;
for ( V_15 = 0 ; V_15 < 16 && ( V_26 || V_27 ) ; V_15 ++ ) {
if ( V_22 [ V_15 ] != 0x00 )
V_27 = 0 ;
if ( V_22 [ V_15 ] != 0xFF )
V_26 = 0 ;
}
if ( V_26 || V_27 )
return;
V_3 = F_3 ( 16 * 2 + 4 + 1 ) ;
if ( ! V_3 )
return;
if ( V_28 >= 0x0206 )
sprintf ( V_3 , L_3 , V_22 ) ;
else
sprintf ( V_3 , L_4 , V_22 ) ;
V_24 [ V_21 ] = V_3 ;
}
static void T_1 F_14 ( const struct V_1 * V_2 , int V_21 , int V_25 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + V_25 ;
char * V_3 ;
if ( V_24 [ V_21 ] )
return;
V_3 = F_3 ( 4 ) ;
if ( ! V_3 )
return;
sprintf ( V_3 , L_5 , * V_22 & 0x7F ) ;
V_24 [ V_21 ] = V_3 ;
}
static void T_1 F_15 ( int type , const char * V_29 )
{
struct V_30 * V_31 ;
if ( F_16 ( type , V_29 , NULL ) )
return;
V_31 = F_3 ( sizeof( * V_31 ) + strlen ( V_29 ) + 1 ) ;
if ( ! V_31 ) {
F_4 ( V_10 L_6 ) ;
return;
}
V_31 -> type = type ;
strcpy ( ( char * ) ( V_31 + 1 ) , V_29 ) ;
V_31 -> V_29 = ( char * ) ( V_31 + 1 ) ;
V_31 -> V_32 = NULL ;
F_17 ( & V_31 -> V_33 , & V_34 ) ;
}
static void T_1 F_18 ( const struct V_1 * V_2 )
{
int V_15 , V_35 = ( V_2 -> V_5 - sizeof( struct V_1 ) ) / 2 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
const char * V_22 = ( char * ) ( V_2 + 1 ) + ( V_15 * 2 ) ;
if ( ( * V_22 & 0x80 ) == 0 )
continue;
F_15 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 + 1 ) ) ) ;
}
}
static void T_1 F_19 ( const struct V_1 * V_2 )
{
int V_15 , V_35 = * ( T_2 * ) ( V_2 + 1 ) ;
struct V_30 * V_31 ;
for ( V_15 = 1 ; V_15 <= V_35 ; V_15 ++ ) {
char * V_36 = F_2 ( V_2 , V_15 ) ;
if ( V_36 == V_8 )
continue;
V_31 = F_3 ( sizeof( * V_31 ) ) ;
if ( ! V_31 ) {
F_4 ( V_10
L_7 ) ;
break;
}
V_31 -> type = V_37 ;
V_31 -> V_29 = V_36 ;
V_31 -> V_32 = NULL ;
F_17 ( & V_31 -> V_33 , & V_34 ) ;
}
}
static void T_1 F_20 ( const struct V_1 * V_2 )
{
struct V_30 * V_31 ;
void * V_14 ;
V_14 = F_3 ( V_2 -> V_5 ) ;
if ( V_14 == NULL ) {
F_4 ( V_10 L_8 ) ;
return;
}
memcpy ( V_14 , V_2 , V_2 -> V_5 ) ;
V_31 = F_3 ( sizeof( * V_31 ) ) ;
if ( ! V_31 ) {
F_4 ( V_10 L_8 ) ;
return;
}
V_31 -> type = V_38 ;
V_31 -> V_29 = L_9 ;
V_31 -> V_32 = V_14 ;
F_21 ( & V_31 -> V_33 , & V_34 ) ;
}
static void T_1 F_22 ( int V_39 , int V_40 , int V_41 ,
int V_42 , const char * V_29 )
{
struct V_43 * V_44 ;
V_44 = F_3 ( sizeof( * V_44 ) + strlen ( V_29 ) + 1 ) ;
if ( ! V_44 ) {
F_4 ( V_10 L_10 ) ;
return;
}
V_44 -> V_39 = V_39 ;
V_44 -> V_40 = V_40 ;
V_44 -> V_41 = V_41 ;
V_44 -> V_42 = V_42 ;
strcpy ( ( char * ) & V_44 [ 1 ] , V_29 ) ;
V_44 -> V_31 . type = V_45 ;
V_44 -> V_31 . V_29 = ( char * ) & V_44 [ 1 ] ;
V_44 -> V_31 . V_32 = V_44 ;
F_17 ( & V_44 -> V_31 . V_33 , & V_34 ) ;
}
static void T_1 F_23 ( const struct V_1 * V_2 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + 5 ;
if ( ( * V_22 & 0x80 ) == 0 )
return;
F_22 ( * ( V_22 + 1 ) , * ( V_46 * ) ( V_22 + 2 ) , * ( V_22 + 4 ) , * ( V_22 + 5 ) ,
F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
F_15 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
}
static void T_1 F_24 ( const struct V_1 * V_2 , void * V_47 )
{
switch( V_2 -> type ) {
case 0 :
F_12 ( V_2 , V_48 , 4 ) ;
F_12 ( V_2 , V_49 , 5 ) ;
F_12 ( V_2 , V_50 , 8 ) ;
break;
case 1 :
F_12 ( V_2 , V_51 , 4 ) ;
F_12 ( V_2 , V_52 , 5 ) ;
F_12 ( V_2 , V_53 , 6 ) ;
F_12 ( V_2 , V_54 , 7 ) ;
F_13 ( V_2 , V_55 , 8 ) ;
break;
case 2 :
F_12 ( V_2 , V_56 , 4 ) ;
F_12 ( V_2 , V_57 , 5 ) ;
F_12 ( V_2 , V_58 , 6 ) ;
F_12 ( V_2 , V_59 , 7 ) ;
F_12 ( V_2 , V_60 , 8 ) ;
break;
case 3 :
F_12 ( V_2 , V_61 , 4 ) ;
F_14 ( V_2 , V_62 , 5 ) ;
F_12 ( V_2 , V_63 , 6 ) ;
F_12 ( V_2 , V_64 , 7 ) ;
F_12 ( V_2 , V_65 , 8 ) ;
break;
case 10 :
F_18 ( V_2 ) ;
break;
case 11 :
F_19 ( V_2 ) ;
break;
case 38 :
F_20 ( V_2 ) ;
break;
case 41 :
F_23 ( V_2 ) ;
}
}
static void T_1 F_25 ( const char * V_66 )
{
const char * V_23 ;
if ( ! V_66 )
return;
for ( V_23 = V_66 ; * V_23 ; V_23 ++ )
if ( isprint ( * V_23 ) )
F_4 ( V_67 L_11 , * V_23 ) ;
else
F_4 ( V_67 L_12 , * V_23 & 0xff ) ;
}
static void T_1 F_26 ( void )
{
const char * V_68 ;
F_4 ( V_69 L_13 ) ;
F_25 ( F_27 ( V_51 ) ) ;
F_4 ( V_67 L_14 ) ;
F_25 ( F_27 ( V_52 ) ) ;
V_68 = F_27 ( V_57 ) ;
if ( V_68 ) {
F_4 ( V_67 L_15 ) ;
F_25 ( V_68 ) ;
}
F_4 ( V_67 L_16 ) ;
F_25 ( F_27 ( V_49 ) ) ;
F_4 ( V_67 L_14 ) ;
F_25 ( F_27 ( V_50 ) ) ;
F_4 ( V_67 L_17 ) ;
}
static int T_1 F_28 ( const char T_4 * V_23 )
{
T_2 V_11 [ 15 ] ;
F_29 ( V_11 , V_23 , 15 ) ;
if ( F_11 ( V_11 , 15 ) ) {
V_18 = ( V_11 [ 13 ] << 8 ) | V_11 [ 12 ] ;
V_17 = ( V_11 [ 7 ] << 8 ) | V_11 [ 6 ] ;
V_16 = ( V_11 [ 11 ] << 24 ) | ( V_11 [ 10 ] << 16 ) |
( V_11 [ 9 ] << 8 ) | V_11 [ 8 ] ;
if ( F_7 ( F_24 ) == 0 ) {
if ( V_28 )
F_30 ( L_18 ,
V_28 >> 8 , V_28 & 0xFF ) ;
else {
V_28 = ( V_11 [ 14 ] & 0xF0 ) << 4 |
( V_11 [ 14 ] & 0x0F ) ;
F_30 ( L_19 ,
V_28 >> 8 , V_28 & 0xFF ) ;
}
F_26 () ;
return 0 ;
}
}
V_28 = 0 ;
return 1 ;
}
static int T_1 F_31 ( const char T_4 * V_23 )
{
T_2 V_11 [ 32 ] ;
int V_70 = 0 ;
F_29 ( V_11 , V_23 , 32 ) ;
if ( ( V_11 [ 5 ] < 32 ) && F_11 ( V_11 , V_11 [ 5 ] ) ) {
V_28 = ( V_11 [ 6 ] << 8 ) + V_11 [ 7 ] ;
switch ( V_28 ) {
case 0x021F :
case 0x0221 :
F_32 ( L_20 ,
V_28 & 0xFF , 3 ) ;
V_28 = 0x0203 ;
break;
case 0x0233 :
F_32 ( L_20 , 51 , 6 ) ;
V_28 = 0x0206 ;
break;
}
V_70 = 16 ;
}
return F_28 ( V_11 + V_70 ) ;
}
void T_1 F_33 ( void )
{
char T_4 * V_23 , * V_71 ;
int V_72 ;
if ( F_34 ( V_73 ) ) {
if ( V_74 . V_75 == V_76 )
goto error;
V_23 = F_8 ( V_74 . V_75 , 32 ) ;
if ( V_23 == NULL )
goto error;
V_72 = F_31 ( V_23 ) ;
F_10 ( V_23 , 32 ) ;
if ( ! V_72 ) {
V_77 = 1 ;
goto V_78;
}
}
else {
V_23 = F_8 ( 0xF0000 , 0x10000 ) ;
if ( V_23 == NULL )
goto error;
for ( V_71 = V_23 ; V_71 < V_23 + 0x10000 ; V_71 += 16 ) {
if ( memcmp ( V_71 , L_21 , 4 ) == 0 && V_71 - V_23 <= 0xFFE0 )
V_72 = F_31 ( V_71 ) ;
else if ( memcmp ( V_71 , L_22 , 5 ) == 0 )
V_72 = F_28 ( V_71 ) ;
else
continue;
if ( ! V_72 ) {
V_77 = 1 ;
F_10 ( V_23 , 0x10000 ) ;
goto V_78;
}
}
F_10 ( V_23 , 0x10000 ) ;
}
error:
F_4 ( V_79 L_23 ) ;
V_78:
V_80 = 1 ;
}
static bool F_35 ( const struct V_81 * V_82 )
{
int V_15 ;
F_36 ( ! V_80 , V_10 L_24 ) ;
for ( V_15 = 0 ; V_15 < F_37 ( V_82 -> V_83 ) ; V_15 ++ ) {
int V_3 = V_82 -> V_83 [ V_15 ] . V_21 ;
if ( V_3 == V_84 )
break;
if ( V_24 [ V_3 ]
&& strstr ( V_24 [ V_3 ] , V_82 -> V_83 [ V_15 ] . V_85 ) )
continue;
return false ;
}
return true ;
}
static bool F_38 ( const struct V_81 * V_82 )
{
return V_82 -> V_83 [ 0 ] . V_21 == V_84 ;
}
int F_39 ( const struct V_81 * V_33 )
{
int V_35 = 0 ;
const struct V_81 * V_22 ;
for ( V_22 = V_33 ; ! F_38 ( V_22 ) ; V_22 ++ )
if ( F_35 ( V_22 ) ) {
V_35 ++ ;
if ( V_22 -> V_86 && V_22 -> V_86 ( V_22 ) )
break;
}
return V_35 ;
}
const struct V_81 * F_40 ( const struct V_81 * V_33 )
{
const struct V_81 * V_22 ;
for ( V_22 = V_33 ; ! F_38 ( V_22 ) ; V_22 ++ )
if ( F_35 ( V_22 ) )
return V_22 ;
return NULL ;
}
const char * F_27 ( int V_87 )
{
return V_24 [ V_87 ] ;
}
int F_41 ( const char * V_9 )
{
int V_88 = V_54 ;
if ( V_24 [ V_88 ] && strstr ( V_24 [ V_88 ] , V_9 ) )
return 1 ;
return 0 ;
}
int F_42 ( const char * V_9 )
{
static int V_89 [] = { V_51 , V_56 , V_84 } ;
int V_15 ;
for ( V_15 = 0 ; V_89 [ V_15 ] != V_84 ; V_15 ++ ) {
int V_88 = V_89 [ V_15 ] ;
if ( V_24 [ V_88 ] && strstr ( V_24 [ V_88 ] , V_9 ) )
return 1 ;
}
return 0 ;
}
const struct V_30 * F_16 ( int type , const char * V_29 ,
const struct V_30 * V_90 )
{
const struct V_91 * V_92 = V_90 ? & V_90 -> V_33 : & V_34 ;
struct V_91 * V_22 ;
for( V_22 = V_92 -> V_93 ; V_22 != & V_34 ; V_22 = V_22 -> V_93 ) {
const struct V_30 * V_31 =
F_43 ( V_22 , struct V_30 , V_33 ) ;
if ( ( ( type == V_94 ) || ( V_31 -> type == type ) ) &&
( ( V_29 == NULL ) || ( strcmp ( V_31 -> V_29 , V_29 ) == 0 ) ) )
return V_31 ;
}
return NULL ;
}
bool F_44 ( int V_87 , int * V_95 , int * V_96 , int * V_97 )
{
int V_98 = 0 , V_99 = 0 , V_100 = 0 ;
bool V_101 ;
const char * V_3 , * V_102 ;
char * V_103 ;
V_3 = F_27 ( V_87 ) ;
V_101 = V_3 ;
if ( ! V_101 )
goto V_78;
V_102 = strrchr ( V_3 , '/' ) ;
if ( ! V_102 )
goto V_78;
V_102 ++ ;
V_98 = F_45 ( V_102 , & V_103 , 10 ) ;
if ( V_102 != V_103 && V_98 < 100 ) {
V_98 += 1900 ;
if ( V_98 < 1996 )
V_98 += 100 ;
}
if ( V_98 > 9999 )
V_98 = 0 ;
V_99 = F_45 ( V_3 , & V_103 , 10 ) ;
if ( V_3 == V_103 || * V_103 != '/' || ! V_99 || V_99 > 12 ) {
V_99 = 0 ;
goto V_78;
}
V_3 = V_103 + 1 ;
V_100 = F_45 ( V_3 , & V_103 , 10 ) ;
if ( V_3 == V_102 || V_3 == V_103 || * V_103 != '/' || V_100 > 31 )
V_100 = 0 ;
V_78:
if ( V_95 )
* V_95 = V_98 ;
if ( V_96 )
* V_96 = V_99 ;
if ( V_97 )
* V_97 = V_100 ;
return V_101 ;
}
int F_46 ( void (* F_6)( const struct V_1 * , void * ) ,
void * V_13 )
{
T_2 * V_11 ;
if ( ! V_77 )
return - 1 ;
V_11 = F_47 ( V_16 , V_17 ) ;
if ( V_11 == NULL )
return - 1 ;
F_5 ( V_11 , V_17 , V_18 , F_6 , V_13 ) ;
F_48 ( V_11 ) ;
return 0 ;
}
bool F_49 ( enum V_104 V_88 , const char * V_9 )
{
const char * V_66 = F_27 ( V_88 ) ;
if ( V_66 == NULL || V_9 == NULL )
return V_66 == V_9 ;
return ! strcmp ( V_66 , V_9 ) ;
}
