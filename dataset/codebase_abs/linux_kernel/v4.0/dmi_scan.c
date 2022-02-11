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
static void F_4 ( T_2 * V_10 , T_4 V_6 , int V_11 ,
void (* F_5)( const struct V_1 * , void * ) ,
void * V_12 )
{
T_2 * V_13 = V_10 ;
int V_14 = 0 ;
while ( ( ! V_11 || V_14 < V_11 ) &&
( V_13 - V_10 + sizeof( struct V_1 ) ) <= V_6 ) {
const struct V_1 * V_2 = ( const struct V_1 * ) V_13 ;
V_13 += V_2 -> V_5 ;
while ( ( V_13 - V_10 < V_6 - 1 ) && ( V_13 [ 0 ] || V_13 [ 1 ] ) )
V_13 ++ ;
if ( V_13 - V_10 < V_6 - 1 )
F_5 ( V_2 , V_12 ) ;
if ( V_2 -> type == V_15 )
break;
V_13 += 2 ;
V_14 ++ ;
}
}
static int T_1 F_6 ( void (* F_5)( const struct V_1 * ,
void * ) )
{
T_2 * V_10 ;
V_10 = F_7 ( V_16 , V_17 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , V_17 , V_18 , F_5 , NULL ) ;
F_8 ( V_10 , V_17 ) ;
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
int V_26 = 1 , V_27 = 1 , V_14 ;
if ( V_24 [ V_21 ] )
return;
for ( V_14 = 0 ; V_14 < 16 && ( V_26 || V_27 ) ; V_14 ++ ) {
if ( V_22 [ V_14 ] != 0x00 )
V_27 = 0 ;
if ( V_22 [ V_14 ] != 0xFF )
V_26 = 0 ;
}
if ( V_26 || V_27 )
return;
V_3 = F_3 ( 16 * 2 + 4 + 1 ) ;
if ( ! V_3 )
return;
if ( V_28 >= 0x0206 )
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
int V_14 , V_35 = ( V_2 -> V_5 - sizeof( struct V_1 ) ) / 2 ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
const char * V_22 = ( char * ) ( V_2 + 1 ) + ( V_14 * 2 ) ;
if ( ( * V_22 & 0x80 ) == 0 )
continue;
F_14 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 + 1 ) ) ) ;
}
}
static void T_1 F_18 ( const struct V_1 * V_2 )
{
int V_14 , V_35 = * ( T_2 * ) ( V_2 + 1 ) ;
struct V_30 * V_31 ;
for ( V_14 = 1 ; V_14 <= V_35 ; V_14 ++ ) {
const char * V_36 = F_2 ( V_2 , V_14 ) ;
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
void * V_13 ;
V_13 = F_3 ( V_2 -> V_5 ) ;
if ( V_13 == NULL )
return;
memcpy ( V_13 , V_2 , V_2 -> V_5 ) ;
V_31 = F_3 ( sizeof( * V_31 ) ) ;
if ( ! V_31 )
return;
V_31 -> type = V_38 ;
V_31 -> V_29 = L_5 ;
V_31 -> V_32 = V_13 ;
F_20 ( & V_31 -> V_33 , & V_34 ) ;
}
static void T_1 F_21 ( int V_39 , int V_40 , int V_41 ,
int V_42 , const char * V_29 )
{
struct V_43 * V_44 ;
V_44 = F_3 ( sizeof( * V_44 ) + strlen ( V_29 ) + 1 ) ;
if ( ! V_44 )
return;
V_44 -> V_39 = V_39 ;
V_44 -> V_40 = V_40 ;
V_44 -> V_41 = V_41 ;
V_44 -> V_42 = V_42 ;
strcpy ( ( char * ) & V_44 [ 1 ] , V_29 ) ;
V_44 -> V_31 . type = V_45 ;
V_44 -> V_31 . V_29 = ( char * ) & V_44 [ 1 ] ;
V_44 -> V_31 . V_32 = V_44 ;
F_16 ( & V_44 -> V_31 . V_33 , & V_34 ) ;
}
static void T_1 F_22 ( const struct V_1 * V_2 )
{
const T_2 * V_22 = ( T_2 * ) V_2 + 5 ;
if ( ( * V_22 & 0x80 ) == 0 )
return;
F_21 ( * ( V_22 + 1 ) , * ( V_46 * ) ( V_22 + 2 ) , * ( V_22 + 4 ) , * ( V_22 + 5 ) ,
F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
F_14 ( * V_22 & 0x7f , F_1 ( V_2 , * ( V_22 - 1 ) ) ) ;
}
static void T_1 F_23 ( const struct V_1 * V_2 , void * V_47 )
{
if ( V_2 -> type != V_48 )
return;
V_49 ++ ;
}
static void T_1 F_24 ( const struct V_1 * V_2 , void * V_47 )
{
const char * V_22 = ( const char * ) V_2 ;
static int V_50 ;
if ( V_2 -> type != V_48 )
return;
if ( V_50 >= V_49 ) {
F_25 ( V_51 L_6 ) ;
return;
}
V_52 [ V_50 ] . V_53 = F_26 ( & V_2 -> V_53 ) ;
V_52 [ V_50 ] . V_54 = F_2 ( V_2 , V_22 [ 0x10 ] ) ;
V_52 [ V_50 ] . V_55 = F_2 ( V_2 , V_22 [ 0x11 ] ) ;
V_50 ++ ;
}
void T_1 F_27 ( void )
{
if ( ! V_56 )
return;
if ( F_6 ( F_23 ) == 0 && V_49 ) {
V_52 = F_3 ( sizeof( * V_52 ) * V_49 ) ;
if ( V_52 )
F_6 ( F_24 ) ;
}
}
static void T_1 F_28 ( const struct V_1 * V_2 , void * V_57 )
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
static int T_1 F_29 ( char * V_10 , T_3 V_6 , const char * V_76 )
{
int V_77 = 0 ;
const char * V_23 ;
if ( ! V_76 )
return V_77 ;
for ( V_23 = V_76 ; * V_23 ; V_23 ++ )
if ( isprint ( * V_23 ) )
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_7 , * V_23 ) ;
else
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_8 , * V_23 & 0xff ) ;
return V_77 ;
}
static void T_1 F_31 ( char * V_10 , T_3 V_6 )
{
int V_77 = 0 ;
const char * V_78 ;
V_77 += F_29 ( V_10 + V_77 , V_6 - V_77 ,
F_32 ( V_61 ) ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_9 ) ;
V_77 += F_29 ( V_10 + V_77 , V_6 - V_77 ,
F_32 ( V_62 ) ) ;
V_78 = F_32 ( V_67 ) ;
if ( V_78 ) {
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_10 ) ;
V_77 += F_29 ( V_10 + V_77 , V_6 - V_77 , V_78 ) ;
}
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_11 ) ;
V_77 += F_29 ( V_10 + V_77 , V_6 - V_77 ,
F_32 ( V_59 ) ) ;
V_77 += F_30 ( V_10 + V_77 , V_6 - V_77 , L_9 ) ;
V_77 += F_29 ( V_10 + V_77 , V_6 - V_77 ,
F_32 ( V_60 ) ) ;
}
static int T_1 F_33 ( const T_2 * V_10 )
{
int V_79 ;
if ( memcmp ( V_10 , L_12 , 4 ) == 0 &&
V_10 [ 5 ] < 32 && F_10 ( V_10 , V_10 [ 5 ] ) ) {
V_79 = F_34 ( V_10 + 6 ) ;
switch ( V_79 ) {
case 0x021F :
case 0x0221 :
F_35 ( L_13 ,
V_79 & 0xFF , 3 ) ;
V_79 = 0x0203 ;
break;
case 0x0233 :
F_35 ( L_13 , 51 , 6 ) ;
V_79 = 0x0206 ;
break;
}
} else {
V_79 = 0 ;
}
V_10 += 16 ;
if ( memcmp ( V_10 , L_14 , 5 ) == 0 && F_10 ( V_10 , 15 ) ) {
V_18 = F_36 ( V_10 + 12 ) ;
V_17 = F_36 ( V_10 + 6 ) ;
V_16 = F_37 ( V_10 + 8 ) ;
if ( F_6 ( F_28 ) == 0 ) {
if ( V_79 ) {
V_28 = V_79 ;
F_38 ( L_15 ,
V_28 >> 8 , V_28 & 0xFF ) ;
} else {
V_28 = ( V_10 [ 14 ] & 0xF0 ) << 4 |
( V_10 [ 14 ] & 0x0F ) ;
F_38 ( L_16 ,
V_28 >> 8 , V_28 & 0xFF ) ;
}
F_31 ( V_80 , sizeof( V_80 ) ) ;
F_39 ( V_81 L_17 , V_80 ) ;
return 0 ;
}
}
return 1 ;
}
static int T_1 F_40 ( const T_2 * V_10 )
{
if ( memcmp ( V_10 , L_18 , 5 ) == 0 &&
V_10 [ 6 ] < 32 && F_10 ( V_10 , V_10 [ 6 ] ) ) {
V_28 = F_34 ( V_10 + 7 ) ;
V_18 = 0 ;
V_17 = F_37 ( V_10 + 12 ) ;
V_16 = F_41 ( V_10 + 16 ) ;
if ( F_6 ( F_28 ) == 0 ) {
F_38 ( L_15 ,
V_28 >> 8 , V_28 & 0xFF ) ;
F_31 ( V_80 , sizeof( V_80 ) ) ;
F_35 ( L_17 , V_80 ) ;
return 0 ;
}
}
return 1 ;
}
void T_1 F_42 ( void )
{
char T_5 * V_23 , * V_82 ;
char V_10 [ 32 ] ;
if ( F_43 ( V_83 ) ) {
if ( V_84 . V_85 != V_86 ) {
V_23 = F_7 ( V_84 . V_85 , 32 ) ;
if ( V_23 == NULL )
goto error;
F_44 ( V_10 , V_23 , 32 ) ;
F_9 ( V_23 , 32 ) ;
if ( ! F_40 ( V_10 ) ) {
V_56 = 1 ;
goto V_87;
}
}
if ( V_84 . V_88 == V_86 )
goto error;
V_23 = F_7 ( V_84 . V_88 , 32 ) ;
if ( V_23 == NULL )
goto error;
F_44 ( V_10 , V_23 , 32 ) ;
F_9 ( V_23 , 32 ) ;
if ( ! F_33 ( V_10 ) ) {
V_56 = 1 ;
goto V_87;
}
} else if ( F_45 ( V_89 ) ) {
V_23 = F_7 ( 0xF0000 , 0x10000 ) ;
if ( V_23 == NULL )
goto error;
memset ( V_10 , 0 , 16 ) ;
for ( V_82 = V_23 ; V_82 < V_23 + 0x10000 ; V_82 += 16 ) {
F_44 ( V_10 + 16 , V_82 , 16 ) ;
if ( ! F_40 ( V_10 ) || ! F_33 ( V_10 ) ) {
V_56 = 1 ;
F_9 ( V_23 , 0x10000 ) ;
goto V_87;
}
memcpy ( V_10 , V_10 + 16 , 16 ) ;
}
F_9 ( V_23 , 0x10000 ) ;
}
error:
F_38 ( L_19 ) ;
V_87:
V_90 = 1 ;
}
void T_1 F_46 ( void )
{
F_47 ( L_20 , V_80 ) ;
}
static bool F_48 ( const struct V_91 * V_92 )
{
int V_14 ;
F_49 ( ! V_90 , V_93 L_21 ) ;
for ( V_14 = 0 ; V_14 < F_50 ( V_92 -> V_94 ) ; V_14 ++ ) {
int V_3 = V_92 -> V_94 [ V_14 ] . V_21 ;
if ( V_3 == V_95 )
break;
if ( V_24 [ V_3 ] ) {
if ( ! V_92 -> V_94 [ V_14 ] . V_96 &&
strstr ( V_24 [ V_3 ] , V_92 -> V_94 [ V_14 ] . V_97 ) )
continue;
else if ( V_92 -> V_94 [ V_14 ] . V_96 &&
! strcmp ( V_24 [ V_3 ] , V_92 -> V_94 [ V_14 ] . V_97 ) )
continue;
}
return false ;
}
return true ;
}
static bool F_51 ( const struct V_91 * V_92 )
{
return V_92 -> V_94 [ 0 ] . V_21 == V_95 ;
}
int F_52 ( const struct V_91 * V_33 )
{
int V_35 = 0 ;
const struct V_91 * V_22 ;
for ( V_22 = V_33 ; ! F_51 ( V_22 ) ; V_22 ++ )
if ( F_48 ( V_22 ) ) {
V_35 ++ ;
if ( V_22 -> V_98 && V_22 -> V_98 ( V_22 ) )
break;
}
return V_35 ;
}
const struct V_91 * F_53 ( const struct V_91 * V_33 )
{
const struct V_91 * V_22 ;
for ( V_22 = V_33 ; ! F_51 ( V_22 ) ; V_22 ++ )
if ( F_48 ( V_22 ) )
return V_22 ;
return NULL ;
}
const char * F_32 ( int V_99 )
{
return V_24 [ V_99 ] ;
}
int F_54 ( const char * V_9 )
{
int V_100 = V_64 ;
if ( V_24 [ V_100 ] && strstr ( V_24 [ V_100 ] , V_9 ) )
return 1 ;
return 0 ;
}
int F_55 ( const char * V_9 )
{
static int V_101 [] = { V_61 , V_66 , V_95 } ;
int V_14 ;
for ( V_14 = 0 ; V_101 [ V_14 ] != V_95 ; V_14 ++ ) {
int V_100 = V_101 [ V_14 ] ;
if ( V_24 [ V_100 ] && strstr ( V_24 [ V_100 ] , V_9 ) )
return 1 ;
}
return 0 ;
}
const struct V_30 * F_15 ( int type , const char * V_29 ,
const struct V_30 * V_102 )
{
const struct V_103 * V_104 = V_102 ? & V_102 -> V_33 : & V_34 ;
struct V_103 * V_22 ;
for ( V_22 = V_104 -> V_105 ; V_22 != & V_34 ; V_22 = V_22 -> V_105 ) {
const struct V_30 * V_31 =
F_56 ( V_22 , struct V_30 , V_33 ) ;
if ( ( ( type == V_106 ) || ( V_31 -> type == type ) ) &&
( ( V_29 == NULL ) || ( strcmp ( V_31 -> V_29 , V_29 ) == 0 ) ) )
return V_31 ;
}
return NULL ;
}
bool F_57 ( int V_99 , int * V_107 , int * V_108 , int * V_109 )
{
int V_110 = 0 , V_111 = 0 , V_112 = 0 ;
bool V_113 ;
const char * V_3 , * V_114 ;
char * V_115 ;
V_3 = F_32 ( V_99 ) ;
V_113 = V_3 ;
if ( ! V_113 )
goto V_87;
V_114 = strrchr ( V_3 , '/' ) ;
if ( ! V_114 )
goto V_87;
V_114 ++ ;
V_110 = F_58 ( V_114 , & V_115 , 10 ) ;
if ( V_114 != V_115 && V_110 < 100 ) {
V_110 += 1900 ;
if ( V_110 < 1996 )
V_110 += 100 ;
}
if ( V_110 > 9999 )
V_110 = 0 ;
V_111 = F_58 ( V_3 , & V_115 , 10 ) ;
if ( V_3 == V_115 || * V_115 != '/' || ! V_111 || V_111 > 12 ) {
V_111 = 0 ;
goto V_87;
}
V_3 = V_115 + 1 ;
V_112 = F_58 ( V_3 , & V_115 , 10 ) ;
if ( V_3 == V_114 || V_3 == V_115 || * V_115 != '/' || V_112 > 31 )
V_112 = 0 ;
V_87:
if ( V_107 )
* V_107 = V_110 ;
if ( V_108 )
* V_108 = V_111 ;
if ( V_109 )
* V_109 = V_112 ;
return V_113 ;
}
int F_59 ( void (* F_5)( const struct V_1 * , void * ) ,
void * V_12 )
{
T_2 * V_10 ;
if ( ! V_56 )
return - 1 ;
V_10 = F_60 ( V_16 , V_17 ) ;
if ( V_10 == NULL )
return - 1 ;
F_4 ( V_10 , V_17 , V_18 , F_5 , V_12 ) ;
F_61 ( V_10 ) ;
return 0 ;
}
bool F_62 ( enum V_116 V_100 , const char * V_9 )
{
const char * V_76 = F_32 ( V_100 ) ;
if ( V_76 == NULL || V_9 == NULL )
return V_76 == V_9 ;
return ! strcmp ( V_76 , V_9 ) ;
}
void F_63 ( V_46 V_53 , const char * * V_55 , const char * * V_54 )
{
int V_117 ;
if ( V_52 == NULL )
return;
for ( V_117 = 0 ; V_117 < V_49 ; V_117 ++ ) {
if ( V_53 == V_52 [ V_117 ] . V_53 ) {
* V_55 = V_52 [ V_117 ] . V_55 ;
* V_54 = V_52 [ V_117 ] . V_54 ;
break;
}
}
}
