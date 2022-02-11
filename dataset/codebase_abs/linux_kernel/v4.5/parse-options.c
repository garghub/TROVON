static int F_1 ( const struct V_1 * V_2 , const char * V_3 , int V_4 )
{
if ( V_4 & V_5 )
fprintf ( V_6 , L_1 , V_2 -> V_7 , V_3 ) ;
else if ( V_4 & V_8 )
fprintf ( V_6 , L_2 , V_2 -> V_9 , V_3 ) ;
else
fprintf ( V_6 , L_3 , V_2 -> V_9 , V_3 ) ;
return - 1 ;
}
static const char * F_2 ( const char * V_10 , const char * V_11 )
{
T_1 V_12 = strlen ( V_11 ) ;
return strncmp ( V_10 , V_11 , V_12 ) ? NULL : V_10 + V_12 ;
}
static void F_3 ( const struct V_1 * V_2 , const char * V_3 , int V_4 )
{
if ( V_4 & V_5 )
fprintf ( V_6 , L_4 , V_2 -> V_7 , V_3 ) ;
else if ( V_4 & V_8 )
fprintf ( V_6 , L_5 , V_2 -> V_9 , V_3 ) ;
else
fprintf ( V_6 , L_6 , V_2 -> V_9 , V_3 ) ;
}
static int F_4 ( struct V_13 * V_14 , const struct V_1 * V_2 ,
int V_4 , const char * * V_15 )
{
const char * V_16 ;
if ( V_14 -> V_2 ) {
V_16 = V_14 -> V_2 ;
V_14 -> V_2 = NULL ;
} else if ( ( V_2 -> V_4 & V_17 ) && ( V_14 -> V_18 == 1 ||
* * ( V_14 -> V_19 + 1 ) == '-' ) ) {
V_16 = ( const char * ) V_2 -> V_20 ;
} else if ( V_14 -> V_18 > 1 ) {
V_14 -> V_18 -- ;
V_16 = * ++ V_14 -> V_19 ;
} else
return F_1 ( V_2 , L_7 , V_4 ) ;
if ( V_15 )
* V_15 = V_16 ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 ,
const struct V_1 * V_2 , int V_4 )
{
const char * V_21 , * V_15 = NULL ;
const int V_22 = V_4 & V_8 ;
int V_23 ;
if ( V_22 && V_14 -> V_2 )
return F_1 ( V_2 , L_8 , V_4 ) ;
if ( V_22 && ( V_2 -> V_4 & V_24 ) )
return F_1 ( V_2 , L_9 , V_4 ) ;
if ( V_2 -> V_4 & V_25 )
return F_1 ( V_2 , L_10 , V_4 ) ;
if ( V_2 -> V_4 & V_26 ) {
if ( V_14 -> V_27 && V_14 -> V_27 != V_2 ) {
char V_28 [ 128 ] ;
if ( ( ( V_4 & V_5 ) && V_14 -> V_27 -> V_7 ) ||
V_14 -> V_27 -> V_9 == NULL ) {
snprintf ( V_28 , sizeof( V_28 ) , L_11 ,
V_14 -> V_27 -> V_7 ) ;
} else {
snprintf ( V_28 , sizeof( V_28 ) , L_12 ,
V_14 -> V_27 -> V_9 ) ;
}
F_1 ( V_2 , V_28 , V_4 ) ;
return - 3 ;
}
V_14 -> V_27 = V_2 ;
}
if ( ! ( V_4 & V_5 ) && V_14 -> V_2 ) {
switch ( V_2 -> type ) {
case V_29 :
if ( ! ( V_2 -> V_4 & V_30 ) )
break;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return F_1 ( V_2 , L_8 , V_4 ) ;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
default:
break;
}
}
if ( V_2 -> V_4 & V_44 ) {
char V_3 [ 128 ] ;
bool V_45 = false ;
V_23 = snprintf ( V_3 , sizeof( V_3 ) ,
V_2 -> V_4 & V_46 ?
L_13 :
L_14 ,
V_2 -> V_47 ) ;
V_3 [ sizeof( V_3 ) - 1 ] = '\0' ;
if ( V_23 < 0 )
strncpy ( V_3 , V_2 -> V_4 & V_46 ?
L_15 :
L_16 ,
sizeof( V_3 ) ) ;
if ( ! ( V_2 -> V_4 & V_46 ) )
return F_1 ( V_2 , V_3 , V_4 ) ;
V_23 = 0 ;
if ( V_22 )
V_45 = true ;
if ( V_2 -> V_4 & V_30 )
V_45 = true ;
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 )
V_45 = true ;
switch ( V_2 -> type ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_45 = true ;
break;
case V_29 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
default:
break;
}
if ( ! V_45 )
V_23 = F_4 ( V_14 , V_2 , V_4 , NULL ) ;
if ( V_23 )
return V_23 ;
F_3 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
switch ( V_2 -> type ) {
case V_33 :
if ( V_22 )
* ( int * ) V_2 -> V_49 &= ~ V_2 -> V_20 ;
else
* ( int * ) V_2 -> V_49 |= V_2 -> V_20 ;
return 0 ;
case V_31 :
* ( bool * ) V_2 -> V_49 = V_22 ? false : true ;
if ( V_2 -> V_50 )
* ( bool * ) V_2 -> V_50 = true ;
return 0 ;
case V_32 :
* ( int * ) V_2 -> V_49 = V_22 ? 0 : * ( int * ) V_2 -> V_49 + 1 ;
return 0 ;
case V_34 :
* ( unsigned int * ) V_2 -> V_49 = V_22 ? 0 : V_2 -> V_20 ;
return 0 ;
case V_35 :
* ( void * * ) V_2 -> V_49 = V_22 ? NULL : ( void * ) V_2 -> V_20 ;
return 0 ;
case V_39 :
V_23 = 0 ;
if ( V_22 )
* ( const char * * ) V_2 -> V_49 = NULL ;
else if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 )
* ( const char * * ) V_2 -> V_49 = ( const char * ) V_2 -> V_20 ;
else
V_23 = F_4 ( V_14 , V_2 , V_4 , ( const char * * ) V_2 -> V_49 ) ;
if ( V_2 -> V_4 & V_51 ) {
const char * V_52 = * ( const char * * ) V_2 -> V_49 ;
if ( ! V_52 )
return V_23 ;
if ( V_52 [ 0 ] == '\0' ) {
* ( const char * * ) V_2 -> V_49 = NULL ;
return 0 ;
}
}
return V_23 ;
case V_29 :
if ( V_22 )
return ( * V_2 -> V_53 ) ( V_2 , NULL , 1 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_30 )
return ( * V_2 -> V_53 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 )
return ( * V_2 -> V_53 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( F_4 ( V_14 , V_2 , V_4 , & V_15 ) )
return - 1 ;
return ( * V_2 -> V_53 ) ( V_2 , V_15 , 0 ) ? ( - 1 ) : 0 ;
case V_40 :
if ( V_22 ) {
* ( int * ) V_2 -> V_49 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 ) {
* ( int * ) V_2 -> V_49 = V_2 -> V_20 ;
return 0 ;
}
if ( F_4 ( V_14 , V_2 , V_4 , & V_15 ) )
return - 1 ;
* ( int * ) V_2 -> V_49 = strtol ( V_15 , ( char * * ) & V_21 , 10 ) ;
if ( * V_21 )
return F_1 ( V_2 , L_17 , V_4 ) ;
return 0 ;
case V_41 :
if ( V_22 ) {
* ( unsigned int * ) V_2 -> V_49 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 ) {
* ( unsigned int * ) V_2 -> V_49 = V_2 -> V_20 ;
return 0 ;
}
if ( F_4 ( V_14 , V_2 , V_4 , & V_15 ) )
return - 1 ;
* ( unsigned int * ) V_2 -> V_49 = strtol ( V_15 , ( char * * ) & V_21 , 10 ) ;
if ( * V_21 )
return F_1 ( V_2 , L_17 , V_4 ) ;
return 0 ;
case V_42 :
if ( V_22 ) {
* ( long * ) V_2 -> V_49 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 ) {
* ( long * ) V_2 -> V_49 = V_2 -> V_20 ;
return 0 ;
}
if ( F_4 ( V_14 , V_2 , V_4 , & V_15 ) )
return - 1 ;
* ( long * ) V_2 -> V_49 = strtol ( V_15 , ( char * * ) & V_21 , 10 ) ;
if ( * V_21 )
return F_1 ( V_2 , L_17 , V_4 ) ;
return 0 ;
case V_43 :
if ( V_22 ) {
* ( V_54 * ) V_2 -> V_49 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_48 && ! V_14 -> V_2 ) {
* ( V_54 * ) V_2 -> V_49 = V_2 -> V_20 ;
return 0 ;
}
if ( F_4 ( V_14 , V_2 , V_4 , & V_15 ) )
return - 1 ;
* ( V_54 * ) V_2 -> V_49 = F_6 ( V_15 , ( char * * ) & V_21 , 10 ) ;
if ( * V_21 )
return F_1 ( V_2 , L_17 , V_4 ) ;
return 0 ;
case V_36 :
case V_37 :
case V_38 :
default:
F_7 ( L_18 ) ;
}
}
static int F_8 ( struct V_13 * V_14 , const struct V_1 * V_55 )
{
for (; V_55 -> type != V_36 ; V_55 ++ ) {
if ( V_55 -> V_7 == * V_14 -> V_2 ) {
V_14 -> V_2 = V_14 -> V_2 [ 1 ] ? V_14 -> V_2 + 1 : NULL ;
return F_5 ( V_14 , V_55 , V_5 ) ;
}
}
return - 2 ;
}
static int F_9 ( struct V_13 * V_14 , const char * V_15 ,
const struct V_1 * V_55 )
{
const char * V_56 = strchr ( V_15 , '=' ) ;
const struct V_1 * V_57 = NULL , * V_58 = NULL ;
int V_59 = 0 , V_60 = 0 ;
if ( ! V_56 )
V_56 = V_15 + strlen ( V_15 ) ;
for (; V_55 -> type != V_36 ; V_55 ++ ) {
const char * V_61 ;
int V_4 = 0 ;
if ( ! V_55 -> V_9 )
continue;
V_61 = F_2 ( V_15 , V_55 -> V_9 ) ;
if ( V_55 -> type == V_37 ) {
if ( ! V_61 )
continue;
if ( * V_61 == '=' )
return F_1 ( V_55 , L_8 , V_4 ) ;
if ( * V_61 )
continue;
V_14 -> V_62 [ V_14 -> V_63 ++ ] = V_15 - 2 ;
return 0 ;
}
if ( ! V_61 ) {
if ( ! F_10 ( V_55 -> V_9 , L_19 ) ) {
V_61 = F_2 ( V_15 , V_55 -> V_9 + 3 ) ;
if ( V_61 ) {
V_4 |= V_8 ;
goto V_64;
}
if ( ! F_10 ( V_55 -> V_9 + 3 , V_15 ) ) {
V_4 |= V_8 ;
goto V_65;
}
}
if ( ! strncmp ( V_55 -> V_9 , V_15 , V_56 - V_15 ) ) {
V_65:
if ( V_57 ) {
V_58 = V_57 ;
V_60 = V_59 ;
}
if ( ! ( V_4 & V_8 ) && * V_56 )
V_14 -> V_2 = V_56 + 1 ;
V_57 = V_55 ;
V_59 = V_4 ;
continue;
}
if ( ! F_10 ( L_19 , V_15 ) ) {
V_4 |= V_8 ;
goto V_65;
}
if ( strncmp ( V_15 , L_19 , 3 ) )
continue;
V_4 |= V_8 ;
V_61 = F_2 ( V_15 + 3 , V_55 -> V_9 ) ;
if ( ! V_61 && ! F_10 ( V_55 -> V_9 , V_15 + 3 ) )
goto V_65;
if ( ! V_61 )
continue;
}
V_64:
if ( * V_61 ) {
if ( * V_61 != '=' )
continue;
V_14 -> V_2 = V_61 + 1 ;
}
return F_5 ( V_14 , V_55 , V_4 ) ;
}
if ( V_58 ) {
fprintf ( V_6 ,
L_20 ,
V_15 ,
( V_60 & V_8 ) ? L_19 : L_21 ,
V_58 -> V_9 ,
( V_59 & V_8 ) ? L_19 : L_21 ,
V_57 -> V_9 ) ;
return - 1 ;
}
if ( V_57 )
return F_5 ( V_14 , V_57 , V_59 ) ;
return - 2 ;
}
static void F_11 ( const char * V_15 , const struct V_1 * V_55 )
{
if ( strlen ( V_15 ) < 3 )
return;
if ( ! F_10 ( V_15 , L_19 ) ) {
fprintf ( V_6 , L_22 , V_15 ) ;
exit ( 129 ) ;
}
for (; V_55 -> type != V_36 ; V_55 ++ ) {
if ( ! V_55 -> V_9 )
continue;
if ( ! F_10 ( V_55 -> V_9 , V_15 ) ) {
fprintf ( V_6 , L_22 , V_15 ) ;
exit ( 129 ) ;
}
}
}
static void F_12 ( struct V_13 * V_66 ,
int V_18 , const char * * V_19 , int V_4 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> V_18 = V_18 - 1 ;
V_66 -> V_19 = V_19 + 1 ;
V_66 -> V_62 = V_19 ;
V_66 -> V_63 = ( ( V_4 & V_67 ) != 0 ) ;
V_66 -> V_4 = V_4 ;
if ( ( V_4 & V_68 ) &&
( V_4 & V_69 ) )
F_7 ( L_23 ) ;
}
static int F_13 ( struct V_13 * V_66 ,
const struct V_1 * V_55 ,
const char * const V_70 [] )
{
int V_71 = ! ( V_66 -> V_4 & V_72 ) ;
int V_73 = 1 ;
const char * V_15 ;
V_66 -> V_2 = NULL ;
for (; V_66 -> V_18 ; V_66 -> V_18 -- , V_66 -> V_19 ++ ) {
V_15 = V_66 -> V_19 [ 0 ] ;
if ( * V_15 != '-' || ! V_15 [ 1 ] ) {
if ( V_66 -> V_4 & V_69 )
break;
V_66 -> V_62 [ V_66 -> V_63 ++ ] = V_66 -> V_19 [ 0 ] ;
continue;
}
if ( V_15 [ 1 ] != '-' ) {
V_66 -> V_2 = ++ V_15 ;
if ( V_71 && * V_66 -> V_2 == 'h' ) {
return F_14 ( V_70 , V_55 , 0 , V_66 ) ;
}
switch ( F_8 ( V_66 , V_55 ) ) {
case - 1 :
return F_15 ( V_70 , V_55 , V_15 , 1 ) ;
case - 2 :
goto V_74;
case - 3 :
goto V_75;
default:
break;
}
if ( V_66 -> V_2 )
F_11 ( V_15 , V_55 ) ;
while ( V_66 -> V_2 ) {
if ( V_71 && * V_66 -> V_2 == 'h' )
return F_14 ( V_70 , V_55 , 0 , V_66 ) ;
V_15 = V_66 -> V_2 ;
switch ( F_8 ( V_66 , V_55 ) ) {
case - 1 :
return F_15 ( V_70 , V_55 , V_15 , 1 ) ;
case - 2 :
V_66 -> V_19 [ 0 ] = F_16 ( V_66 -> V_2 - 1 ) ;
* ( char * ) V_66 -> V_19 [ 0 ] = '-' ;
goto V_74;
case - 3 :
goto V_75;
default:
break;
}
}
continue;
}
if ( ! V_15 [ 2 ] ) {
if ( ! ( V_66 -> V_4 & V_76 ) ) {
V_66 -> V_18 -- ;
V_66 -> V_19 ++ ;
}
break;
}
V_15 += 2 ;
if ( V_71 && ! strcmp ( V_15 , L_24 ) )
return F_14 ( V_70 , V_55 , 1 , V_66 ) ;
if ( V_71 && ! strcmp ( V_15 , L_25 ) )
return F_14 ( V_70 , V_55 , 0 , V_66 ) ;
if ( ! strcmp ( V_15 , L_26 ) )
return V_77 ;
if ( ! strcmp ( V_15 , L_27 ) )
return V_78 ;
switch ( F_9 ( V_66 , V_15 , V_55 ) ) {
case - 1 :
return F_15 ( V_70 , V_55 , V_15 , 0 ) ;
case - 2 :
goto V_74;
case - 3 :
V_73 = 0 ;
goto V_75;
default:
break;
}
continue;
V_74:
if ( ! ( V_66 -> V_4 & V_68 ) )
return V_79 ;
V_66 -> V_62 [ V_66 -> V_63 ++ ] = V_66 -> V_19 [ 0 ] ;
V_66 -> V_2 = NULL ;
}
return V_80 ;
V_75:
F_15 ( V_70 , V_55 , V_15 , V_73 ) ;
if ( ( V_73 && V_66 -> V_27 -> V_7 ) ||
V_66 -> V_27 -> V_9 == NULL ) {
char V_2 = V_66 -> V_27 -> V_7 ;
F_15 ( NULL , V_55 , & V_2 , 1 ) ;
} else {
F_15 ( NULL , V_55 , V_66 -> V_27 -> V_9 , 0 ) ;
}
return V_81 ;
}
static int F_17 ( struct V_13 * V_66 )
{
memmove ( V_66 -> V_62 + V_66 -> V_63 , V_66 -> V_19 , V_66 -> V_18 * sizeof( * V_66 -> V_62 ) ) ;
V_66 -> V_62 [ V_66 -> V_63 + V_66 -> V_18 ] = NULL ;
return V_66 -> V_63 + V_66 -> V_18 ;
}
int F_18 ( int V_18 , const char * * V_19 , const struct V_1 * V_55 ,
const char * const V_82 [] , const char * V_70 [] , int V_4 )
{
struct V_13 V_66 ;
if ( V_82 && ! V_70 [ 0 ] ) {
char * V_83 = NULL ;
F_19 ( & V_83 , L_28 , V_84 . V_85 , V_19 [ 0 ] ) ;
for ( int V_86 = 0 ; V_82 [ V_86 ] ; V_86 ++ ) {
if ( V_86 )
F_20 ( & V_83 , L_29 ) ;
F_20 ( & V_83 , V_82 [ V_86 ] ) ;
}
F_20 ( & V_83 , L_30 ) ;
V_70 [ 0 ] = V_83 ;
}
F_12 ( & V_66 , V_18 , V_19 , V_4 ) ;
switch ( F_13 ( & V_66 , V_55 , V_70 ) ) {
case V_81 :
exit ( 129 ) ;
case V_80 :
break;
case V_77 :
while ( V_55 -> type != V_36 ) {
if ( V_55 -> V_9 )
printf ( L_31 , V_55 -> V_9 ) ;
V_55 ++ ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
case V_78 :
if ( V_82 ) {
for ( int V_86 = 0 ; V_82 [ V_86 ] ; V_86 ++ )
printf ( L_32 , V_82 [ V_86 ] ) ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
default:
if ( V_66 . V_19 [ 0 ] [ 1 ] == '-' )
F_19 ( & V_87 , L_33 ,
V_66 . V_19 [ 0 ] + 2 ) ;
else
F_19 ( & V_87 , L_34 , * V_66 . V_2 ) ;
F_21 ( V_70 , V_55 ) ;
}
return F_17 ( & V_66 ) ;
}
int F_22 ( int V_18 , const char * * V_19 , const struct V_1 * V_55 ,
const char * const V_70 [] , int V_4 )
{
return F_18 ( V_18 , V_19 , V_55 , NULL ,
( const char * * ) V_70 , V_4 ) ;
}
static void F_23 ( const struct V_1 * V_88 , int V_89 )
{
T_1 V_90 ;
int V_91 ;
if ( V_88 -> type == V_38 ) {
fputc ( '\n' , V_6 ) ;
if ( * V_88 -> V_92 )
fprintf ( V_6 , L_35 , V_88 -> V_92 ) ;
return;
}
if ( ! V_89 && ( V_88 -> V_4 & V_93 ) )
return;
if ( V_88 -> V_4 & V_25 )
return;
V_90 = fprintf ( V_6 , L_36 ) ;
if ( V_88 -> V_7 )
V_90 += fprintf ( V_6 , L_37 , V_88 -> V_7 ) ;
else
V_90 += fprintf ( V_6 , L_36 ) ;
if ( V_88 -> V_9 && V_88 -> V_7 )
V_90 += fprintf ( V_6 , L_38 ) ;
if ( V_88 -> V_9 )
V_90 += fprintf ( V_6 , L_39 , V_88 -> V_9 ) ;
switch ( V_88 -> type ) {
case V_37 :
break;
case V_42 :
case V_43 :
case V_40 :
case V_41 :
if ( V_88 -> V_4 & V_48 )
if ( V_88 -> V_9 )
V_90 += fprintf ( V_6 , L_40 ) ;
else
V_90 += fprintf ( V_6 , L_41 ) ;
else
V_90 += fprintf ( V_6 , L_42 ) ;
break;
case V_29 :
if ( V_88 -> V_4 & V_30 )
break;
case V_39 :
if ( V_88 -> V_94 ) {
if ( V_88 -> V_4 & V_48 )
if ( V_88 -> V_9 )
V_90 += fprintf ( V_6 , L_43 , V_88 -> V_94 ) ;
else
V_90 += fprintf ( V_6 , L_44 , V_88 -> V_94 ) ;
else
V_90 += fprintf ( V_6 , L_45 , V_88 -> V_94 ) ;
} else {
if ( V_88 -> V_4 & V_48 )
if ( V_88 -> V_9 )
V_90 += fprintf ( V_6 , L_46 ) ;
else
V_90 += fprintf ( V_6 , L_47 ) ;
else
V_90 += fprintf ( V_6 , L_48 ) ;
}
break;
default:
case V_36 :
case V_38 :
case V_33 :
case V_31 :
case V_32 :
case V_34 :
case V_35 :
break;
}
if ( V_90 <= V_95 )
V_91 = V_95 - V_90 ;
else {
fputc ( '\n' , V_6 ) ;
V_91 = V_95 ;
}
fprintf ( V_6 , L_49 , V_91 + V_96 , L_21 , V_88 -> V_92 ) ;
if ( V_88 -> V_4 & V_44 )
fprintf ( V_6 , L_50 ,
V_95 + V_96 , L_21 ,
V_88 -> V_47 ) ;
}
static int F_24 ( const void * V_97 , const void * V_98 )
{
const struct V_1 * V_99 = V_97 , * V_100 = V_98 ;
int V_101 = tolower ( V_99 -> V_7 ) , V_102 = tolower ( V_100 -> V_7 ) , V_103 ;
if ( V_101 == 0 )
V_101 = 'z' + 1 ;
if ( V_102 == 0 )
V_102 = 'z' + 1 ;
V_103 = V_101 - V_102 ;
if ( V_103 == 0 ) {
const char * V_104 = V_99 -> V_9 ? : L_21 ,
* V_105 = V_100 -> V_9 ? : L_21 ;
V_103 = strcmp ( V_104 , V_105 ) ;
}
return V_103 ;
}
static struct V_1 * F_25 ( const struct V_1 * V_88 )
{
int V_106 = 0 , V_12 ;
const struct V_1 * V_107 = V_88 ;
struct V_1 * V_108 ;
for ( V_107 = V_88 ; V_107 -> type != V_36 ; V_107 ++ )
++ V_106 ;
V_12 = sizeof( * V_107 ) * ( V_106 + 1 ) ;
V_108 = malloc ( V_12 ) ;
if ( ! V_108 )
goto V_62;
memcpy ( V_108 , V_88 , V_12 ) ;
qsort ( V_108 , V_106 , sizeof( * V_107 ) , F_24 ) ;
V_62:
return V_108 ;
}
static bool F_26 ( const struct V_1 * V_2 , const struct V_13 * V_66 )
{
int V_86 ;
for ( V_86 = 1 ; V_86 < V_66 -> V_18 ; ++ V_86 ) {
const char * V_15 = V_66 -> V_19 [ V_86 ] ;
if ( V_15 [ 0 ] != '-' ) {
if ( V_15 [ 1 ] == '\0' ) {
if ( V_15 [ 0 ] == V_2 -> V_7 )
return true ;
continue;
}
if ( V_2 -> V_9 && strcmp ( V_2 -> V_9 , V_15 ) == 0 )
return true ;
if ( V_2 -> V_92 && F_27 ( V_2 -> V_92 , V_15 ) != NULL )
return true ;
continue;
}
if ( V_15 [ 1 ] == V_2 -> V_7 ||
( V_15 [ 1 ] == '-' && V_2 -> V_9 && strcmp ( V_2 -> V_9 , V_15 + 2 ) == 0 ) )
return true ;
}
return false ;
}
static int F_14 ( const char * const * V_70 ,
const struct V_1 * V_88 , int V_89 ,
struct V_13 * V_66 )
{
struct V_1 * V_108 ;
if ( ! V_70 )
return V_81 ;
F_28 () ;
if ( V_87 ) {
fprintf ( V_6 , L_51 , V_87 ) ;
F_29 ( & V_87 ) ;
}
fprintf ( V_6 , L_52 , * V_70 ++ ) ;
while ( * V_70 && * * V_70 )
fprintf ( V_6 , L_53 , * V_70 ++ ) ;
while ( * V_70 ) {
fprintf ( V_6 , L_54 ,
* * V_70 ? L_36 : L_21 ,
* V_70 ) ;
V_70 ++ ;
}
if ( V_88 -> type != V_38 )
fputc ( '\n' , V_6 ) ;
V_108 = F_25 ( V_88 ) ;
if ( V_108 )
V_88 = V_108 ;
for ( ; V_88 -> type != V_36 ; V_88 ++ ) {
if ( V_66 && V_66 -> V_18 > 1 && ! F_26 ( V_88 , V_66 ) )
continue;
F_23 ( V_88 , V_89 ) ;
}
fputc ( '\n' , V_6 ) ;
free ( V_108 ) ;
return V_81 ;
}
void F_21 ( const char * const * V_70 ,
const struct V_1 * V_88 )
{
F_14 ( V_70 , V_88 , 0 , NULL ) ;
exit ( 129 ) ;
}
void F_30 ( const char * const * V_70 ,
const struct V_1 * V_88 , const char * V_109 , ... )
{
T_2 V_110 ;
char * V_111 = V_87 ;
va_start ( V_110 , V_109 ) ;
if ( F_31 ( & V_87 , V_109 , V_110 ) == - 1 )
F_7 ( L_55 ) ;
va_end ( V_110 ) ;
free ( V_111 ) ;
F_14 ( V_70 , V_88 , 0 , NULL ) ;
exit ( 129 ) ;
}
int F_15 ( const char * const * V_70 ,
const struct V_1 * V_88 ,
const char * V_112 , bool V_113 )
{
if ( ! V_70 )
goto V_2;
fprintf ( V_6 , L_52 , * V_70 ++ ) ;
while ( * V_70 && * * V_70 )
fprintf ( V_6 , L_53 , * V_70 ++ ) ;
while ( * V_70 ) {
fprintf ( V_6 , L_54 ,
* * V_70 ? L_36 : L_21 ,
* V_70 ) ;
V_70 ++ ;
}
fputc ( '\n' , V_6 ) ;
V_2:
for ( ; V_88 -> type != V_36 ; V_88 ++ ) {
if ( V_113 ) {
if ( V_88 -> V_7 == * V_112 ) {
F_23 ( V_88 , 0 ) ;
break;
}
continue;
}
if ( V_88 -> V_9 == NULL )
continue;
if ( ! F_10 ( V_88 -> V_9 , V_112 ) )
F_23 ( V_88 , 0 ) ;
if ( ! F_10 ( L_19 , V_112 ) &&
! F_10 ( V_88 -> V_9 , V_112 + 3 ) )
F_23 ( V_88 , 0 ) ;
}
return V_81 ;
}
int F_32 ( const struct V_1 * V_2 ,
const char * V_15 V_114 ,
int V_22 )
{
int * V_115 = V_2 -> V_49 ;
if ( V_22 )
* V_115 = 0 ;
else if ( V_2 -> V_7 == 'v' ) {
if ( * V_115 >= 0 )
( * V_115 ) ++ ;
else
* V_115 = 1 ;
} else {
if ( * V_115 <= 0 )
( * V_115 ) -- ;
else
* V_115 = - 1 ;
}
return 0 ;
}
static struct V_1 *
F_33 ( struct V_1 * V_88 , int V_116 , const char * V_117 )
{
for (; V_88 -> type != V_36 ; V_88 ++ ) {
if ( ( V_116 && V_88 -> V_7 == V_116 ) ||
( V_88 -> V_9 && V_117 &&
! strcmp ( V_88 -> V_9 , V_117 ) ) )
return V_88 ;
}
return NULL ;
}
void F_34 ( struct V_1 * V_88 , int V_116 , const char * V_117 ,
int V_118 )
{
struct V_1 * V_2 = F_33 ( V_88 , V_116 , V_117 ) ;
if ( V_2 )
V_2 -> V_4 |= V_118 ;
return;
}
void F_35 ( struct V_1 * V_88 , int V_116 ,
const char * V_117 ,
const char * V_47 ,
bool V_119 )
{
struct V_1 * V_2 = F_33 ( V_88 , V_116 , V_117 ) ;
if ( ! V_2 )
return;
V_2 -> V_4 |= V_44 ;
V_2 -> V_4 |= V_119 ? V_46 : 0 ;
V_2 -> V_47 = V_47 ;
}
