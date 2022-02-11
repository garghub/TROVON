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
if ( V_2 -> V_50 )
* ( bool * ) V_2 -> V_50 = true ;
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
V_56:
for (; V_55 -> type != V_36 ; V_55 ++ ) {
if ( V_55 -> V_7 == * V_14 -> V_2 ) {
V_14 -> V_2 = V_14 -> V_2 [ 1 ] ? V_14 -> V_2 + 1 : NULL ;
return F_5 ( V_14 , V_55 , V_5 ) ;
}
}
if ( V_55 -> V_57 ) {
V_55 = V_55 -> V_57 ;
goto V_56;
}
return - 2 ;
}
static int F_9 ( struct V_13 * V_14 , const char * V_15 ,
const struct V_1 * V_55 )
{
const char * V_58 = strchr ( V_15 , '=' ) ;
const struct V_1 * V_59 = NULL , * V_60 = NULL ;
int V_61 = 0 , V_62 = 0 ;
if ( ! V_58 )
V_58 = V_15 + strlen ( V_15 ) ;
V_56:
for (; V_55 -> type != V_36 ; V_55 ++ ) {
const char * V_63 ;
int V_4 = 0 ;
if ( ! V_55 -> V_9 )
continue;
V_63 = F_2 ( V_15 , V_55 -> V_9 ) ;
if ( V_55 -> type == V_37 ) {
if ( ! V_63 )
continue;
if ( * V_63 == '=' )
return F_1 ( V_55 , L_8 , V_4 ) ;
if ( * V_63 )
continue;
V_14 -> V_64 [ V_14 -> V_65 ++ ] = V_15 - 2 ;
return 0 ;
}
if ( ! V_63 ) {
if ( ! F_10 ( V_55 -> V_9 , L_19 ) ) {
V_63 = F_2 ( V_15 , V_55 -> V_9 + 3 ) ;
if ( V_63 ) {
V_4 |= V_8 ;
goto V_66;
}
if ( ! F_10 ( V_55 -> V_9 + 3 , V_15 ) ) {
V_4 |= V_8 ;
goto V_67;
}
}
if ( ! strncmp ( V_55 -> V_9 , V_15 , V_58 - V_15 ) ) {
V_67:
if ( V_59 ) {
V_60 = V_59 ;
V_62 = V_61 ;
}
if ( ! ( V_4 & V_8 ) && * V_58 )
V_14 -> V_2 = V_58 + 1 ;
V_59 = V_55 ;
V_61 = V_4 ;
continue;
}
if ( ! F_10 ( L_19 , V_15 ) ) {
V_4 |= V_8 ;
goto V_67;
}
if ( strncmp ( V_15 , L_19 , 3 ) )
continue;
V_4 |= V_8 ;
V_63 = F_2 ( V_15 + 3 , V_55 -> V_9 ) ;
if ( ! V_63 && ! F_10 ( V_55 -> V_9 , V_15 + 3 ) )
goto V_67;
if ( ! V_63 )
continue;
}
V_66:
if ( * V_63 ) {
if ( * V_63 != '=' )
continue;
V_14 -> V_2 = V_63 + 1 ;
}
return F_5 ( V_14 , V_55 , V_4 ) ;
}
if ( V_60 ) {
fprintf ( V_6 ,
L_20 ,
V_15 ,
( V_62 & V_8 ) ? L_19 : L_21 ,
V_60 -> V_9 ,
( V_61 & V_8 ) ? L_19 : L_21 ,
V_59 -> V_9 ) ;
return - 1 ;
}
if ( V_59 )
return F_5 ( V_14 , V_59 , V_61 ) ;
if ( V_55 -> V_57 ) {
V_55 = V_55 -> V_57 ;
goto V_56;
}
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
static void F_12 ( struct V_13 * V_68 ,
int V_18 , const char * * V_19 , int V_4 )
{
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_18 = V_18 - 1 ;
V_68 -> V_19 = V_19 + 1 ;
V_68 -> V_64 = V_19 ;
V_68 -> V_65 = ( ( V_4 & V_69 ) != 0 ) ;
V_68 -> V_4 = V_4 ;
if ( ( V_4 & V_70 ) &&
( V_4 & V_71 ) )
F_7 ( L_23 ) ;
}
static int F_13 ( struct V_13 * V_68 ,
const struct V_1 * V_55 ,
const char * const V_72 [] )
{
int V_73 = ! ( V_68 -> V_4 & V_74 ) ;
int V_75 = 1 ;
const char * V_15 ;
V_68 -> V_2 = NULL ;
for (; V_68 -> V_18 ; V_68 -> V_18 -- , V_68 -> V_19 ++ ) {
V_15 = V_68 -> V_19 [ 0 ] ;
if ( * V_15 != '-' || ! V_15 [ 1 ] ) {
if ( V_68 -> V_4 & V_71 )
break;
V_68 -> V_64 [ V_68 -> V_65 ++ ] = V_68 -> V_19 [ 0 ] ;
continue;
}
if ( V_15 [ 1 ] != '-' ) {
V_68 -> V_2 = ++ V_15 ;
if ( V_73 && * V_68 -> V_2 == 'h' ) {
return F_14 ( V_72 , V_55 , 0 , V_68 ) ;
}
switch ( F_8 ( V_68 , V_55 ) ) {
case - 1 :
return F_15 ( V_72 , V_55 , V_15 , 1 ) ;
case - 2 :
goto V_76;
case - 3 :
goto V_77;
default:
break;
}
if ( V_68 -> V_2 )
F_11 ( V_15 , V_55 ) ;
while ( V_68 -> V_2 ) {
if ( V_73 && * V_68 -> V_2 == 'h' )
return F_14 ( V_72 , V_55 , 0 , V_68 ) ;
V_15 = V_68 -> V_2 ;
switch ( F_8 ( V_68 , V_55 ) ) {
case - 1 :
return F_15 ( V_72 , V_55 , V_15 , 1 ) ;
case - 2 :
V_68 -> V_19 [ 0 ] = F_16 ( V_68 -> V_2 - 1 ) ;
* ( char * ) V_68 -> V_19 [ 0 ] = '-' ;
goto V_76;
case - 3 :
goto V_77;
default:
break;
}
}
continue;
}
if ( ! V_15 [ 2 ] ) {
if ( ! ( V_68 -> V_4 & V_78 ) ) {
V_68 -> V_18 -- ;
V_68 -> V_19 ++ ;
}
break;
}
V_15 += 2 ;
if ( V_73 && ! strcmp ( V_15 , L_24 ) )
return F_14 ( V_72 , V_55 , 1 , V_68 ) ;
if ( V_73 && ! strcmp ( V_15 , L_25 ) )
return F_14 ( V_72 , V_55 , 0 , V_68 ) ;
if ( ! strcmp ( V_15 , L_26 ) )
return V_79 ;
if ( ! strcmp ( V_15 , L_27 ) )
return V_80 ;
switch ( F_9 ( V_68 , V_15 , V_55 ) ) {
case - 1 :
return F_15 ( V_72 , V_55 , V_15 , 0 ) ;
case - 2 :
goto V_76;
case - 3 :
V_75 = 0 ;
goto V_77;
default:
break;
}
continue;
V_76:
if ( ! ( V_68 -> V_4 & V_70 ) )
return V_81 ;
V_68 -> V_64 [ V_68 -> V_65 ++ ] = V_68 -> V_19 [ 0 ] ;
V_68 -> V_2 = NULL ;
}
return V_82 ;
V_77:
F_15 ( V_72 , V_55 , V_15 , V_75 ) ;
if ( ( V_75 && V_68 -> V_27 -> V_7 ) ||
V_68 -> V_27 -> V_9 == NULL ) {
char V_2 = V_68 -> V_27 -> V_7 ;
F_15 ( NULL , V_55 , & V_2 , 1 ) ;
} else {
F_15 ( NULL , V_55 , V_68 -> V_27 -> V_9 , 0 ) ;
}
return V_83 ;
}
static int F_17 ( struct V_13 * V_68 )
{
memmove ( V_68 -> V_64 + V_68 -> V_65 , V_68 -> V_19 , V_68 -> V_18 * sizeof( * V_68 -> V_64 ) ) ;
V_68 -> V_64 [ V_68 -> V_65 + V_68 -> V_18 ] = NULL ;
return V_68 -> V_65 + V_68 -> V_18 ;
}
int F_18 ( int V_18 , const char * * V_19 , const struct V_1 * V_55 ,
const char * const V_84 [] , const char * V_72 [] , int V_4 )
{
struct V_13 V_68 ;
if ( V_84 && ! V_72 [ 0 ] ) {
char * V_85 = NULL ;
F_19 ( & V_85 , L_28 , V_86 . V_87 , V_19 [ 0 ] ) ;
for ( int V_88 = 0 ; V_84 [ V_88 ] ; V_88 ++ ) {
if ( V_88 )
F_20 ( & V_85 , L_29 ) ;
F_20 ( & V_85 , V_84 [ V_88 ] ) ;
}
F_20 ( & V_85 , L_30 ) ;
V_72 [ 0 ] = V_85 ;
}
F_12 ( & V_68 , V_18 , V_19 , V_4 ) ;
switch ( F_13 ( & V_68 , V_55 , V_72 ) ) {
case V_83 :
exit ( 129 ) ;
case V_82 :
break;
case V_79 :
while ( V_55 -> type != V_36 ) {
if ( V_55 -> V_9 )
printf ( L_31 , V_55 -> V_9 ) ;
V_55 ++ ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
case V_80 :
if ( V_84 ) {
for ( int V_88 = 0 ; V_84 [ V_88 ] ; V_88 ++ )
printf ( L_32 , V_84 [ V_88 ] ) ;
}
putchar ( '\n' ) ;
exit ( 130 ) ;
default:
if ( V_68 . V_19 [ 0 ] [ 1 ] == '-' )
F_19 ( & V_89 , L_33 ,
V_68 . V_19 [ 0 ] + 2 ) ;
else
F_19 ( & V_89 , L_34 , * V_68 . V_2 ) ;
F_21 ( V_72 , V_55 ) ;
}
return F_17 ( & V_68 ) ;
}
int F_22 ( int V_18 , const char * * V_19 , const struct V_1 * V_55 ,
const char * const V_72 [] , int V_4 )
{
return F_18 ( V_18 , V_19 , V_55 , NULL ,
( const char * * ) V_72 , V_4 ) ;
}
static void F_23 ( const struct V_1 * V_90 , int V_91 )
{
T_1 V_92 ;
int V_93 ;
if ( V_90 -> type == V_38 ) {
fputc ( '\n' , V_6 ) ;
if ( * V_90 -> V_94 )
fprintf ( V_6 , L_35 , V_90 -> V_94 ) ;
return;
}
if ( ! V_91 && ( V_90 -> V_4 & V_95 ) )
return;
if ( V_90 -> V_4 & V_25 )
return;
V_92 = fprintf ( V_6 , L_36 ) ;
if ( V_90 -> V_7 )
V_92 += fprintf ( V_6 , L_37 , V_90 -> V_7 ) ;
else
V_92 += fprintf ( V_6 , L_36 ) ;
if ( V_90 -> V_9 && V_90 -> V_7 )
V_92 += fprintf ( V_6 , L_38 ) ;
if ( V_90 -> V_9 )
V_92 += fprintf ( V_6 , L_39 , V_90 -> V_9 ) ;
switch ( V_90 -> type ) {
case V_37 :
break;
case V_42 :
case V_43 :
case V_40 :
case V_41 :
if ( V_90 -> V_4 & V_48 )
if ( V_90 -> V_9 )
V_92 += fprintf ( V_6 , L_40 ) ;
else
V_92 += fprintf ( V_6 , L_41 ) ;
else
V_92 += fprintf ( V_6 , L_42 ) ;
break;
case V_29 :
if ( V_90 -> V_4 & V_30 )
break;
case V_39 :
if ( V_90 -> V_96 ) {
if ( V_90 -> V_4 & V_48 )
if ( V_90 -> V_9 )
V_92 += fprintf ( V_6 , L_43 , V_90 -> V_96 ) ;
else
V_92 += fprintf ( V_6 , L_44 , V_90 -> V_96 ) ;
else
V_92 += fprintf ( V_6 , L_45 , V_90 -> V_96 ) ;
} else {
if ( V_90 -> V_4 & V_48 )
if ( V_90 -> V_9 )
V_92 += fprintf ( V_6 , L_46 ) ;
else
V_92 += fprintf ( V_6 , L_47 ) ;
else
V_92 += fprintf ( V_6 , L_48 ) ;
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
if ( V_92 <= V_97 )
V_93 = V_97 - V_92 ;
else {
fputc ( '\n' , V_6 ) ;
V_93 = V_97 ;
}
fprintf ( V_6 , L_49 , V_93 + V_98 , L_21 , V_90 -> V_94 ) ;
if ( V_90 -> V_4 & V_44 )
fprintf ( V_6 , L_50 ,
V_97 + V_98 , L_21 ,
V_90 -> V_47 ) ;
}
static int F_24 ( const void * V_99 , const void * V_100 )
{
const struct V_1 * V_101 = V_99 , * V_102 = V_100 ;
int V_103 = tolower ( V_101 -> V_7 ) , V_104 = tolower ( V_102 -> V_7 ) , V_105 ;
if ( V_103 == 0 )
V_103 = 'z' + 1 ;
if ( V_104 == 0 )
V_104 = 'z' + 1 ;
V_105 = V_103 - V_104 ;
if ( V_105 == 0 ) {
const char * V_106 = V_101 -> V_9 ? : L_21 ,
* V_107 = V_102 -> V_9 ? : L_21 ;
V_105 = strcmp ( V_106 , V_107 ) ;
}
return V_105 ;
}
static struct V_1 * F_25 ( const struct V_1 * V_90 )
{
int V_108 = 0 , V_12 ;
const struct V_1 * V_109 = V_90 ;
struct V_1 * V_110 ;
for ( V_109 = V_90 ; V_109 -> type != V_36 ; V_109 ++ )
++ V_108 ;
V_12 = sizeof( * V_109 ) * ( V_108 + 1 ) ;
V_110 = malloc ( V_12 ) ;
if ( ! V_110 )
goto V_64;
memcpy ( V_110 , V_90 , V_12 ) ;
qsort ( V_110 , V_108 , sizeof( * V_109 ) , F_24 ) ;
V_64:
return V_110 ;
}
static bool F_26 ( const struct V_1 * V_2 , const struct V_13 * V_68 )
{
int V_88 ;
for ( V_88 = 1 ; V_88 < V_68 -> V_18 ; ++ V_88 ) {
const char * V_15 = V_68 -> V_19 [ V_88 ] ;
if ( V_15 [ 0 ] != '-' ) {
if ( V_15 [ 1 ] == '\0' ) {
if ( V_15 [ 0 ] == V_2 -> V_7 )
return true ;
continue;
}
if ( V_2 -> V_9 && strcmp ( V_2 -> V_9 , V_15 ) == 0 )
return true ;
if ( V_2 -> V_94 && F_27 ( V_2 -> V_94 , V_15 ) != NULL )
return true ;
continue;
}
if ( V_15 [ 1 ] == V_2 -> V_7 ||
( V_15 [ 1 ] == '-' && V_2 -> V_9 && strcmp ( V_2 -> V_9 , V_15 + 2 ) == 0 ) )
return true ;
}
return false ;
}
static int F_14 ( const char * const * V_72 ,
const struct V_1 * V_90 , int V_91 ,
struct V_13 * V_68 )
{
struct V_1 * V_110 ;
if ( ! V_72 )
return V_83 ;
F_28 () ;
if ( V_89 ) {
fprintf ( V_6 , L_51 , V_89 ) ;
F_29 ( & V_89 ) ;
}
fprintf ( V_6 , L_52 , * V_72 ++ ) ;
while ( * V_72 && * * V_72 )
fprintf ( V_6 , L_53 , * V_72 ++ ) ;
while ( * V_72 ) {
fprintf ( V_6 , L_54 ,
* * V_72 ? L_36 : L_21 ,
* V_72 ) ;
V_72 ++ ;
}
if ( V_90 -> type != V_38 )
fputc ( '\n' , V_6 ) ;
V_110 = F_25 ( V_90 ) ;
if ( V_110 )
V_90 = V_110 ;
for ( ; V_90 -> type != V_36 ; V_90 ++ ) {
if ( V_68 && V_68 -> V_18 > 1 && ! F_26 ( V_90 , V_68 ) )
continue;
F_23 ( V_90 , V_91 ) ;
}
fputc ( '\n' , V_6 ) ;
free ( V_110 ) ;
return V_83 ;
}
void F_21 ( const char * const * V_72 ,
const struct V_1 * V_90 )
{
F_14 ( V_72 , V_90 , 0 , NULL ) ;
exit ( 129 ) ;
}
void F_30 ( const char * const * V_72 ,
const struct V_1 * V_90 , const char * V_111 , ... )
{
T_2 V_112 ;
char * V_113 = V_89 ;
va_start ( V_112 , V_111 ) ;
if ( F_31 ( & V_89 , V_111 , V_112 ) == - 1 )
F_7 ( L_55 ) ;
va_end ( V_112 ) ;
free ( V_113 ) ;
F_14 ( V_72 , V_90 , 0 , NULL ) ;
exit ( 129 ) ;
}
int F_15 ( const char * const * V_72 ,
const struct V_1 * V_90 ,
const char * V_114 , bool V_115 )
{
if ( ! V_72 )
goto V_2;
fprintf ( V_6 , L_52 , * V_72 ++ ) ;
while ( * V_72 && * * V_72 )
fprintf ( V_6 , L_53 , * V_72 ++ ) ;
while ( * V_72 ) {
fprintf ( V_6 , L_54 ,
* * V_72 ? L_36 : L_21 ,
* V_72 ) ;
V_72 ++ ;
}
fputc ( '\n' , V_6 ) ;
V_2:
for ( ; V_90 -> type != V_36 ; V_90 ++ ) {
if ( V_115 ) {
if ( V_90 -> V_7 == * V_114 ) {
F_23 ( V_90 , 0 ) ;
break;
}
continue;
}
if ( V_90 -> V_9 == NULL )
continue;
if ( ! F_10 ( V_90 -> V_9 , V_114 ) )
F_23 ( V_90 , 0 ) ;
if ( ! F_10 ( L_19 , V_114 ) &&
! F_10 ( V_90 -> V_9 , V_114 + 3 ) )
F_23 ( V_90 , 0 ) ;
}
return V_83 ;
}
int F_32 ( const struct V_1 * V_2 ,
const char * V_15 V_116 ,
int V_22 )
{
int * V_117 = V_2 -> V_49 ;
if ( V_22 )
* V_117 = 0 ;
else if ( V_2 -> V_7 == 'v' ) {
if ( * V_117 >= 0 )
( * V_117 ) ++ ;
else
* V_117 = 1 ;
} else {
if ( * V_117 <= 0 )
( * V_117 ) -- ;
else
* V_117 = - 1 ;
}
return 0 ;
}
static struct V_1 *
F_33 ( struct V_1 * V_90 , int V_118 , const char * V_119 )
{
for (; V_90 -> type != V_36 ; V_90 ++ ) {
if ( ( V_118 && V_90 -> V_7 == V_118 ) ||
( V_90 -> V_9 && V_119 &&
! strcmp ( V_90 -> V_9 , V_119 ) ) )
return V_90 ;
}
return NULL ;
}
void F_34 ( struct V_1 * V_90 , int V_118 , const char * V_119 ,
int V_120 )
{
struct V_1 * V_2 = F_33 ( V_90 , V_118 , V_119 ) ;
if ( V_2 )
V_2 -> V_4 |= V_120 ;
return;
}
void F_35 ( struct V_1 * V_90 , int V_118 ,
const char * V_119 ,
const char * V_47 ,
bool V_121 )
{
struct V_1 * V_2 = F_33 ( V_90 , V_118 , V_119 ) ;
if ( ! V_2 )
return;
V_2 -> V_4 |= V_44 ;
V_2 -> V_4 |= V_121 ? V_46 : 0 ;
V_2 -> V_47 = V_47 ;
}
