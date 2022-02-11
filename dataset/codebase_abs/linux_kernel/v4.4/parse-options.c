static int F_1 ( const struct V_1 * V_2 , const char * V_3 , int V_4 )
{
if ( V_4 & V_5 )
return error ( L_1 , V_2 -> V_6 , V_3 ) ;
if ( V_4 & V_7 )
return error ( L_2 , V_2 -> V_8 , V_3 ) ;
return error ( L_3 , V_2 -> V_8 , V_3 ) ;
}
static int F_2 ( struct V_9 * V_10 , const struct V_1 * V_2 ,
int V_4 , const char * * V_11 )
{
if ( V_10 -> V_2 ) {
* V_11 = V_10 -> V_2 ;
V_10 -> V_2 = NULL ;
} else if ( ( V_2 -> V_4 & V_12 ) && ( V_10 -> V_13 == 1 ||
* * ( V_10 -> V_14 + 1 ) == '-' ) ) {
* V_11 = ( const char * ) V_2 -> V_15 ;
} else if ( V_10 -> V_13 > 1 ) {
V_10 -> V_13 -- ;
* V_11 = * ++ V_10 -> V_14 ;
} else
return F_1 ( V_2 , L_4 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 ,
const struct V_1 * V_2 , int V_4 )
{
const char * V_16 , * V_11 = NULL ;
const int V_17 = V_4 & V_7 ;
int V_18 ;
if ( V_17 && V_10 -> V_2 )
return F_1 ( V_2 , L_5 , V_4 ) ;
if ( V_17 && ( V_2 -> V_4 & V_19 ) )
return F_1 ( V_2 , L_6 , V_4 ) ;
if ( V_2 -> V_4 & V_20 )
return F_1 ( V_2 , L_7 , V_4 ) ;
if ( V_2 -> V_4 & V_21 ) {
if ( V_10 -> V_22 && V_10 -> V_22 != V_2 ) {
char V_23 [ 128 ] ;
if ( ( ( V_4 & V_5 ) && V_10 -> V_22 -> V_6 ) ||
V_10 -> V_22 -> V_8 == NULL ) {
F_4 ( V_23 , sizeof( V_23 ) , L_8 ,
V_10 -> V_22 -> V_6 ) ;
} else {
F_4 ( V_23 , sizeof( V_23 ) , L_9 ,
V_10 -> V_22 -> V_8 ) ;
}
F_1 ( V_2 , V_23 , V_4 ) ;
return - 3 ;
}
V_10 -> V_22 = V_2 ;
}
if ( ! ( V_4 & V_5 ) && V_10 -> V_2 ) {
switch ( V_2 -> type ) {
case V_24 :
if ( ! ( V_2 -> V_4 & V_25 ) )
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return F_1 ( V_2 , L_5 , V_4 ) ;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
default:
break;
}
}
switch ( V_2 -> type ) {
case V_28 :
if ( V_17 )
* ( int * ) V_2 -> V_39 &= ~ V_2 -> V_15 ;
else
* ( int * ) V_2 -> V_39 |= V_2 -> V_15 ;
return 0 ;
case V_26 :
* ( bool * ) V_2 -> V_39 = V_17 ? false : true ;
if ( V_2 -> V_40 )
* ( bool * ) V_2 -> V_40 = true ;
return 0 ;
case V_27 :
* ( int * ) V_2 -> V_39 = V_17 ? 0 : * ( int * ) V_2 -> V_39 + 1 ;
return 0 ;
case V_29 :
* ( unsigned int * ) V_2 -> V_39 = V_17 ? 0 : V_2 -> V_15 ;
return 0 ;
case V_30 :
* ( void * * ) V_2 -> V_39 = V_17 ? NULL : ( void * ) V_2 -> V_15 ;
return 0 ;
case V_34 :
V_18 = 0 ;
if ( V_17 )
* ( const char * * ) V_2 -> V_39 = NULL ;
else if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 )
* ( const char * * ) V_2 -> V_39 = ( const char * ) V_2 -> V_15 ;
else
V_18 = F_2 ( V_10 , V_2 , V_4 , ( const char * * ) V_2 -> V_39 ) ;
if ( V_2 -> V_4 & V_42 ) {
const char * V_43 = * ( const char * * ) V_2 -> V_39 ;
if ( ! V_43 )
return V_18 ;
if ( V_43 [ 0 ] == '\0' ) {
* ( const char * * ) V_2 -> V_39 = NULL ;
return 0 ;
}
}
return V_18 ;
case V_24 :
if ( V_17 )
return ( * V_2 -> V_44 ) ( V_2 , NULL , 1 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_25 )
return ( * V_2 -> V_44 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 )
return ( * V_2 -> V_44 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
return ( * V_2 -> V_44 ) ( V_2 , V_11 , 0 ) ? ( - 1 ) : 0 ;
case V_35 :
if ( V_17 ) {
* ( int * ) V_2 -> V_39 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 ) {
* ( int * ) V_2 -> V_39 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( int * ) V_2 -> V_39 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_36 :
if ( V_17 ) {
* ( unsigned int * ) V_2 -> V_39 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 ) {
* ( unsigned int * ) V_2 -> V_39 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( unsigned int * ) V_2 -> V_39 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_37 :
if ( V_17 ) {
* ( long * ) V_2 -> V_39 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 ) {
* ( long * ) V_2 -> V_39 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( long * ) V_2 -> V_39 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_38 :
if ( V_17 ) {
* ( V_45 * ) V_2 -> V_39 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_41 && ! V_10 -> V_2 ) {
* ( V_45 * ) V_2 -> V_39 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( V_45 * ) V_2 -> V_39 = F_5 ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_31 :
case V_32 :
case V_33 :
default:
F_6 ( L_11 ) ;
}
}
static int F_7 ( struct V_9 * V_10 , const struct V_1 * V_46 )
{
for (; V_46 -> type != V_31 ; V_46 ++ ) {
if ( V_46 -> V_6 == * V_10 -> V_2 ) {
V_10 -> V_2 = V_10 -> V_2 [ 1 ] ? V_10 -> V_2 + 1 : NULL ;
return F_3 ( V_10 , V_46 , V_5 ) ;
}
}
return - 2 ;
}
static int F_8 ( struct V_9 * V_10 , const char * V_11 ,
const struct V_1 * V_46 )
{
const char * V_47 = strchr ( V_11 , '=' ) ;
const struct V_1 * V_48 = NULL , * V_49 = NULL ;
int V_50 = 0 , V_51 = 0 ;
if ( ! V_47 )
V_47 = V_11 + strlen ( V_11 ) ;
for (; V_46 -> type != V_31 ; V_46 ++ ) {
const char * V_52 ;
int V_4 = 0 ;
if ( ! V_46 -> V_8 )
continue;
V_52 = F_9 ( V_11 , V_46 -> V_8 ) ;
if ( V_46 -> type == V_32 ) {
if ( ! V_52 )
continue;
if ( * V_52 == '=' )
return F_1 ( V_46 , L_5 , V_4 ) ;
if ( * V_52 )
continue;
V_10 -> V_53 [ V_10 -> V_54 ++ ] = V_11 - 2 ;
return 0 ;
}
if ( ! V_52 ) {
if ( ! F_10 ( V_46 -> V_8 , L_12 ) ) {
V_52 = F_9 ( V_11 , V_46 -> V_8 + 3 ) ;
if ( V_52 ) {
V_4 |= V_7 ;
goto V_55;
}
if ( ! F_10 ( V_46 -> V_8 + 3 , V_11 ) ) {
V_4 |= V_7 ;
goto V_56;
}
}
if ( ! strncmp ( V_46 -> V_8 , V_11 , V_47 - V_11 ) ) {
V_56:
if ( V_48 ) {
V_49 = V_48 ;
V_51 = V_50 ;
}
if ( ! ( V_4 & V_7 ) && * V_47 )
V_10 -> V_2 = V_47 + 1 ;
V_48 = V_46 ;
V_50 = V_4 ;
continue;
}
if ( ! F_10 ( L_12 , V_11 ) ) {
V_4 |= V_7 ;
goto V_56;
}
if ( strncmp ( V_11 , L_12 , 3 ) )
continue;
V_4 |= V_7 ;
V_52 = F_9 ( V_11 + 3 , V_46 -> V_8 ) ;
if ( ! V_52 && ! F_10 ( V_46 -> V_8 , V_11 + 3 ) )
goto V_56;
if ( ! V_52 )
continue;
}
V_55:
if ( * V_52 ) {
if ( * V_52 != '=' )
continue;
V_10 -> V_2 = V_52 + 1 ;
}
return F_3 ( V_10 , V_46 , V_4 ) ;
}
if ( V_49 )
return error ( L_13
L_14 ,
V_11 ,
( V_51 & V_7 ) ? L_12 : L_15 ,
V_49 -> V_8 ,
( V_50 & V_7 ) ? L_12 : L_15 ,
V_48 -> V_8 ) ;
if ( V_48 )
return F_3 ( V_10 , V_48 , V_50 ) ;
return - 2 ;
}
static void F_11 ( const char * V_11 , const struct V_1 * V_46 )
{
if ( strlen ( V_11 ) < 3 )
return;
if ( ! F_10 ( V_11 , L_12 ) ) {
error ( L_16 , V_11 ) ;
exit ( 129 ) ;
}
for (; V_46 -> type != V_31 ; V_46 ++ ) {
if ( ! V_46 -> V_8 )
continue;
if ( ! F_10 ( V_46 -> V_8 , V_11 ) ) {
error ( L_16 , V_11 ) ;
exit ( 129 ) ;
}
}
}
void F_12 ( struct V_9 * V_57 ,
int V_13 , const char * * V_14 , int V_4 )
{
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_13 = V_13 - 1 ;
V_57 -> V_14 = V_14 + 1 ;
V_57 -> V_53 = V_14 ;
V_57 -> V_54 = ( ( V_4 & V_58 ) != 0 ) ;
V_57 -> V_4 = V_4 ;
if ( ( V_4 & V_59 ) &&
( V_4 & V_60 ) )
F_6 ( L_17 ) ;
}
int F_13 ( struct V_9 * V_57 ,
const struct V_1 * V_46 ,
const char * const V_61 [] )
{
int V_62 = ! ( V_57 -> V_4 & V_63 ) ;
int V_64 = 1 ;
const char * V_11 ;
V_57 -> V_2 = NULL ;
for (; V_57 -> V_13 ; V_57 -> V_13 -- , V_57 -> V_14 ++ ) {
V_11 = V_57 -> V_14 [ 0 ] ;
if ( * V_11 != '-' || ! V_11 [ 1 ] ) {
if ( V_57 -> V_4 & V_60 )
break;
V_57 -> V_53 [ V_57 -> V_54 ++ ] = V_57 -> V_14 [ 0 ] ;
continue;
}
if ( V_11 [ 1 ] != '-' ) {
V_57 -> V_2 = ++ V_11 ;
if ( V_62 && * V_57 -> V_2 == 'h' ) {
return F_14 ( V_61 , V_46 , 0 , V_57 ) ;
}
switch ( F_7 ( V_57 , V_46 ) ) {
case - 1 :
return F_15 ( V_61 , V_46 , V_11 , 1 ) ;
case - 2 :
goto V_65;
case - 3 :
goto V_66;
default:
break;
}
if ( V_57 -> V_2 )
F_11 ( V_11 , V_46 ) ;
while ( V_57 -> V_2 ) {
if ( V_62 && * V_57 -> V_2 == 'h' )
return F_14 ( V_61 , V_46 , 0 , V_57 ) ;
V_11 = V_57 -> V_2 ;
switch ( F_7 ( V_57 , V_46 ) ) {
case - 1 :
return F_15 ( V_61 , V_46 , V_11 , 1 ) ;
case - 2 :
V_57 -> V_14 [ 0 ] = F_16 ( V_57 -> V_2 - 1 ) ;
* ( char * ) V_57 -> V_14 [ 0 ] = '-' ;
goto V_65;
case - 3 :
goto V_66;
default:
break;
}
}
continue;
}
if ( ! V_11 [ 2 ] ) {
if ( ! ( V_57 -> V_4 & V_67 ) ) {
V_57 -> V_13 -- ;
V_57 -> V_14 ++ ;
}
break;
}
V_11 += 2 ;
if ( V_62 && ! strcmp ( V_11 , L_18 ) )
return F_14 ( V_61 , V_46 , 1 , V_57 ) ;
if ( V_62 && ! strcmp ( V_11 , L_19 ) )
return F_14 ( V_61 , V_46 , 0 , V_57 ) ;
if ( ! strcmp ( V_11 , L_20 ) )
return V_68 ;
if ( ! strcmp ( V_11 , L_21 ) )
return V_69 ;
switch ( F_8 ( V_57 , V_11 , V_46 ) ) {
case - 1 :
return F_15 ( V_61 , V_46 , V_11 , 0 ) ;
case - 2 :
goto V_65;
case - 3 :
V_64 = 0 ;
goto V_66;
default:
break;
}
continue;
V_65:
if ( ! ( V_57 -> V_4 & V_59 ) )
return V_70 ;
V_57 -> V_53 [ V_57 -> V_54 ++ ] = V_57 -> V_14 [ 0 ] ;
V_57 -> V_2 = NULL ;
}
return V_71 ;
V_66:
F_15 ( V_61 , V_46 , V_11 , V_64 ) ;
if ( ( V_64 && V_57 -> V_22 -> V_6 ) ||
V_57 -> V_22 -> V_8 == NULL ) {
char V_2 = V_57 -> V_22 -> V_6 ;
F_15 ( NULL , V_46 , & V_2 , 1 ) ;
} else {
F_15 ( NULL , V_46 , V_57 -> V_22 -> V_8 , 0 ) ;
}
return V_72 ;
}
int F_17 ( struct V_9 * V_57 )
{
memmove ( V_57 -> V_53 + V_57 -> V_54 , V_57 -> V_14 , V_57 -> V_13 * sizeof( * V_57 -> V_53 ) ) ;
V_57 -> V_53 [ V_57 -> V_54 + V_57 -> V_13 ] = NULL ;
return V_57 -> V_54 + V_57 -> V_13 ;
}
int F_18 ( int V_13 , const char * * V_14 , const struct V_1 * V_46 ,
const char * const V_73 [] , const char * V_61 [] , int V_4 )
{
struct V_9 V_57 ;
F_19 ( & V_74 , V_13 , V_14 ) ;
if ( V_73 && ! V_61 [ 0 ] ) {
struct V_75 V_76 = V_77 ;
F_20 ( & V_76 , L_22 , V_14 [ 0 ] ) ;
for ( int V_78 = 0 ; V_73 [ V_78 ] ; V_78 ++ ) {
if ( V_78 )
F_21 ( & V_76 , L_23 ) ;
F_21 ( & V_76 , V_73 [ V_78 ] ) ;
}
F_21 ( & V_76 , L_24 ) ;
V_61 [ 0 ] = F_16 ( V_76 . V_76 ) ;
F_22 ( & V_76 ) ;
}
F_12 ( & V_57 , V_13 , V_14 , V_4 ) ;
switch ( F_13 ( & V_57 , V_46 , V_61 ) ) {
case V_72 :
exit ( 129 ) ;
case V_71 :
break;
case V_68 :
while ( V_46 -> type != V_31 ) {
if ( V_46 -> V_8 )
printf ( L_25 , V_46 -> V_8 ) ;
V_46 ++ ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
case V_69 :
if ( V_73 ) {
for ( int V_78 = 0 ; V_73 [ V_78 ] ; V_78 ++ )
printf ( L_26 , V_73 [ V_78 ] ) ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
default:
if ( V_57 . V_14 [ 0 ] [ 1 ] == '-' ) {
F_20 ( & V_79 , L_27 ,
V_57 . V_14 [ 0 ] + 2 ) ;
} else {
F_20 ( & V_79 , L_28 ,
* V_57 . V_2 ) ;
}
F_23 ( V_61 , V_46 ) ;
}
return F_17 ( & V_57 ) ;
}
int F_24 ( int V_13 , const char * * V_14 , const struct V_1 * V_46 ,
const char * const V_61 [] , int V_4 )
{
return F_18 ( V_13 , V_14 , V_46 , NULL ,
( const char * * ) V_61 , V_4 ) ;
}
static void F_25 ( const struct V_1 * V_80 , int V_81 )
{
T_1 V_82 ;
int V_83 ;
if ( V_80 -> type == V_33 ) {
fputc ( '\n' , V_84 ) ;
if ( * V_80 -> V_85 )
fprintf ( V_84 , L_29 , V_80 -> V_85 ) ;
return;
}
if ( ! V_81 && ( V_80 -> V_4 & V_86 ) )
return;
if ( V_80 -> V_4 & V_20 )
return;
V_82 = fprintf ( V_84 , L_30 ) ;
if ( V_80 -> V_6 )
V_82 += fprintf ( V_84 , L_31 , V_80 -> V_6 ) ;
else
V_82 += fprintf ( V_84 , L_30 ) ;
if ( V_80 -> V_8 && V_80 -> V_6 )
V_82 += fprintf ( V_84 , L_32 ) ;
if ( V_80 -> V_8 )
V_82 += fprintf ( V_84 , L_33 , V_80 -> V_8 ) ;
switch ( V_80 -> type ) {
case V_32 :
break;
case V_37 :
case V_38 :
case V_35 :
case V_36 :
if ( V_80 -> V_4 & V_41 )
if ( V_80 -> V_8 )
V_82 += fprintf ( V_84 , L_34 ) ;
else
V_82 += fprintf ( V_84 , L_35 ) ;
else
V_82 += fprintf ( V_84 , L_36 ) ;
break;
case V_24 :
if ( V_80 -> V_4 & V_25 )
break;
case V_34 :
if ( V_80 -> V_87 ) {
if ( V_80 -> V_4 & V_41 )
if ( V_80 -> V_8 )
V_82 += fprintf ( V_84 , L_37 , V_80 -> V_87 ) ;
else
V_82 += fprintf ( V_84 , L_38 , V_80 -> V_87 ) ;
else
V_82 += fprintf ( V_84 , L_39 , V_80 -> V_87 ) ;
} else {
if ( V_80 -> V_4 & V_41 )
if ( V_80 -> V_8 )
V_82 += fprintf ( V_84 , L_40 ) ;
else
V_82 += fprintf ( V_84 , L_41 ) ;
else
V_82 += fprintf ( V_84 , L_42 ) ;
}
break;
default:
case V_31 :
case V_33 :
case V_28 :
case V_26 :
case V_27 :
case V_29 :
case V_30 :
break;
}
if ( V_82 <= V_88 )
V_83 = V_88 - V_82 ;
else {
fputc ( '\n' , V_84 ) ;
V_83 = V_88 ;
}
fprintf ( V_84 , L_43 , V_83 + V_89 , L_15 , V_80 -> V_85 ) ;
}
static int F_26 ( const void * V_90 , const void * V_91 )
{
const struct V_1 * V_92 = V_90 , * V_93 = V_91 ;
int V_94 = tolower ( V_92 -> V_6 ) , V_95 = tolower ( V_93 -> V_6 ) , V_96 ;
if ( V_94 == 0 )
V_94 = 'z' + 1 ;
if ( V_95 == 0 )
V_95 = 'z' + 1 ;
V_96 = V_94 - V_95 ;
if ( V_96 == 0 ) {
const char * V_97 = V_92 -> V_8 ? : L_15 ,
* V_98 = V_93 -> V_8 ? : L_15 ;
V_96 = strcmp ( V_97 , V_98 ) ;
}
return V_96 ;
}
static struct V_1 * F_27 ( const struct V_1 * V_80 )
{
int V_99 = 0 ;
const struct V_1 * V_100 = V_80 ;
struct V_1 * V_101 ;
for ( V_100 = V_80 ; V_100 -> type != V_31 ; V_100 ++ )
++ V_99 ;
V_101 = F_28 ( V_80 , sizeof( * V_100 ) * ( V_99 + 1 ) ) ;
if ( V_101 == NULL )
goto V_53;
qsort ( V_101 , V_99 , sizeof( * V_100 ) , F_26 ) ;
V_53:
return V_101 ;
}
static bool F_29 ( const struct V_1 * V_2 , const struct V_9 * V_57 )
{
int V_78 ;
for ( V_78 = 1 ; V_78 < V_57 -> V_13 ; ++ V_78 ) {
const char * V_11 = V_57 -> V_14 [ V_78 ] ;
if ( V_11 [ 0 ] != '-' ) {
if ( V_11 [ 1 ] == '\0' ) {
if ( V_11 [ 0 ] == V_2 -> V_6 )
return true ;
continue;
}
if ( V_2 -> V_8 && strcmp ( V_2 -> V_8 , V_11 ) == 0 )
return true ;
if ( V_2 -> V_85 && F_30 ( V_2 -> V_85 , V_11 ) != NULL )
return true ;
continue;
}
if ( V_11 [ 1 ] == V_2 -> V_6 ||
( V_11 [ 1 ] == '-' && V_2 -> V_8 && strcmp ( V_2 -> V_8 , V_11 + 2 ) == 0 ) )
return true ;
}
return false ;
}
int F_14 ( const char * const * V_61 ,
const struct V_1 * V_80 , int V_81 ,
struct V_9 * V_57 )
{
struct V_1 * V_101 ;
if ( ! V_61 )
return V_72 ;
F_31 () ;
if ( F_32 ( & V_79 ) ) {
fprintf ( V_84 , L_44 , V_79 . V_76 ) ;
F_22 ( & V_79 ) ;
}
fprintf ( V_84 , L_45 , * V_61 ++ ) ;
while ( * V_61 && * * V_61 )
fprintf ( V_84 , L_46 , * V_61 ++ ) ;
while ( * V_61 ) {
fprintf ( V_84 , L_47 ,
* * V_61 ? L_30 : L_15 ,
* V_61 ) ;
V_61 ++ ;
}
if ( V_80 -> type != V_33 )
fputc ( '\n' , V_84 ) ;
V_101 = F_27 ( V_80 ) ;
if ( V_101 )
V_80 = V_101 ;
for ( ; V_80 -> type != V_31 ; V_80 ++ ) {
if ( V_57 && V_57 -> V_13 > 1 && ! F_29 ( V_80 , V_57 ) )
continue;
F_25 ( V_80 , V_81 ) ;
}
fputc ( '\n' , V_84 ) ;
free ( V_101 ) ;
return V_72 ;
}
void F_23 ( const char * const * V_61 ,
const struct V_1 * V_80 )
{
F_33 ( false ) ;
F_14 ( V_61 , V_80 , 0 , NULL ) ;
exit ( 129 ) ;
}
void F_34 ( const char * const * V_61 ,
const struct V_1 * V_80 , const char * V_102 , ... )
{
T_2 V_103 ;
F_33 ( false ) ;
va_start ( V_103 , V_102 ) ;
F_35 ( & V_79 , V_102 , V_103 ) ;
va_end ( V_103 ) ;
F_14 ( V_61 , V_80 , 0 , NULL ) ;
exit ( 129 ) ;
}
int F_15 ( const char * const * V_61 ,
const struct V_1 * V_80 ,
const char * V_104 , bool V_105 )
{
if ( ! V_61 )
goto V_2;
fprintf ( V_84 , L_45 , * V_61 ++ ) ;
while ( * V_61 && * * V_61 )
fprintf ( V_84 , L_46 , * V_61 ++ ) ;
while ( * V_61 ) {
fprintf ( V_84 , L_47 ,
* * V_61 ? L_30 : L_15 ,
* V_61 ) ;
V_61 ++ ;
}
fputc ( '\n' , V_84 ) ;
V_2:
for ( ; V_80 -> type != V_31 ; V_80 ++ ) {
if ( V_105 ) {
if ( V_80 -> V_6 == * V_104 ) {
F_25 ( V_80 , 0 ) ;
break;
}
continue;
}
if ( V_80 -> V_8 == NULL )
continue;
if ( ! F_10 ( V_80 -> V_8 , V_104 ) )
F_25 ( V_80 , 0 ) ;
if ( ! F_10 ( L_12 , V_104 ) &&
! F_10 ( V_80 -> V_8 , V_104 + 3 ) )
F_25 ( V_80 , 0 ) ;
}
return V_72 ;
}
int F_36 ( const struct V_1 * V_2 ,
const char * V_11 V_106 ,
int V_17 )
{
int * V_107 = V_2 -> V_39 ;
if ( V_17 )
* V_107 = 0 ;
else if ( V_2 -> V_6 == 'v' ) {
if ( * V_107 >= 0 )
( * V_107 ) ++ ;
else
* V_107 = 1 ;
} else {
if ( * V_107 <= 0 )
( * V_107 ) -- ;
else
* V_107 = - 1 ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_80 , int V_108 , const char * V_109 ,
int V_110 )
{
for (; V_80 -> type != V_31 ; V_80 ++ ) {
if ( ( V_108 && V_80 -> V_6 == V_108 ) ||
( V_80 -> V_8 && V_109 &&
! strcmp ( V_80 -> V_8 , V_109 ) ) ) {
V_80 -> V_4 |= V_110 ;
break;
}
}
}
