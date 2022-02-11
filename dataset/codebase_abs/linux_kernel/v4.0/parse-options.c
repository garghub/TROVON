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
if ( V_17 && V_10 -> V_2 )
return F_1 ( V_2 , L_5 , V_4 ) ;
if ( V_17 && ( V_2 -> V_4 & V_18 ) )
return F_1 ( V_2 , L_6 , V_4 ) ;
if ( V_2 -> V_4 & V_19 )
return F_1 ( V_2 , L_7 , V_4 ) ;
if ( V_2 -> V_4 & V_20 ) {
if ( V_10 -> V_21 && V_10 -> V_21 != V_2 ) {
char V_22 [ 128 ] ;
if ( ( ( V_4 & V_5 ) && V_10 -> V_21 -> V_6 ) ||
V_10 -> V_21 -> V_8 == NULL ) {
F_4 ( V_22 , sizeof( V_22 ) , L_8 ,
V_10 -> V_21 -> V_6 ) ;
} else {
F_4 ( V_22 , sizeof( V_22 ) , L_9 ,
V_10 -> V_21 -> V_8 ) ;
}
F_1 ( V_2 , V_22 , V_4 ) ;
return - 3 ;
}
V_10 -> V_21 = V_2 ;
}
if ( ! ( V_4 & V_5 ) && V_10 -> V_2 ) {
switch ( V_2 -> type ) {
case V_23 :
if ( ! ( V_2 -> V_4 & V_24 ) )
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return F_1 ( V_2 , L_5 , V_4 ) ;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
default:
break;
}
}
switch ( V_2 -> type ) {
case V_27 :
if ( V_17 )
* ( int * ) V_2 -> V_38 &= ~ V_2 -> V_15 ;
else
* ( int * ) V_2 -> V_38 |= V_2 -> V_15 ;
return 0 ;
case V_25 :
* ( bool * ) V_2 -> V_38 = V_17 ? false : true ;
if ( V_2 -> V_39 )
* ( bool * ) V_2 -> V_39 = true ;
return 0 ;
case V_26 :
* ( int * ) V_2 -> V_38 = V_17 ? 0 : * ( int * ) V_2 -> V_38 + 1 ;
return 0 ;
case V_28 :
* ( unsigned int * ) V_2 -> V_38 = V_17 ? 0 : V_2 -> V_15 ;
return 0 ;
case V_29 :
* ( void * * ) V_2 -> V_38 = V_17 ? NULL : ( void * ) V_2 -> V_15 ;
return 0 ;
case V_33 :
if ( V_17 )
* ( const char * * ) V_2 -> V_38 = NULL ;
else if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 )
* ( const char * * ) V_2 -> V_38 = ( const char * ) V_2 -> V_15 ;
else
return F_2 ( V_10 , V_2 , V_4 , ( const char * * ) V_2 -> V_38 ) ;
return 0 ;
case V_23 :
if ( V_17 )
return ( * V_2 -> V_41 ) ( V_2 , NULL , 1 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_24 )
return ( * V_2 -> V_41 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 )
return ( * V_2 -> V_41 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
return ( * V_2 -> V_41 ) ( V_2 , V_11 , 0 ) ? ( - 1 ) : 0 ;
case V_34 :
if ( V_17 ) {
* ( int * ) V_2 -> V_38 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 ) {
* ( int * ) V_2 -> V_38 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( int * ) V_2 -> V_38 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_35 :
if ( V_17 ) {
* ( unsigned int * ) V_2 -> V_38 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 ) {
* ( unsigned int * ) V_2 -> V_38 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( unsigned int * ) V_2 -> V_38 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_36 :
if ( V_17 ) {
* ( long * ) V_2 -> V_38 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 ) {
* ( long * ) V_2 -> V_38 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( long * ) V_2 -> V_38 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_37 :
if ( V_17 ) {
* ( V_42 * ) V_2 -> V_38 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_40 && ! V_10 -> V_2 ) {
* ( V_42 * ) V_2 -> V_38 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( V_42 * ) V_2 -> V_38 = F_5 ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_10 , V_4 ) ;
return 0 ;
case V_30 :
case V_31 :
case V_32 :
default:
F_6 ( L_11 ) ;
}
}
static int F_7 ( struct V_9 * V_10 , const struct V_1 * V_43 )
{
for (; V_43 -> type != V_30 ; V_43 ++ ) {
if ( V_43 -> V_6 == * V_10 -> V_2 ) {
V_10 -> V_2 = V_10 -> V_2 [ 1 ] ? V_10 -> V_2 + 1 : NULL ;
return F_3 ( V_10 , V_43 , V_5 ) ;
}
}
return - 2 ;
}
static int F_8 ( struct V_9 * V_10 , const char * V_11 ,
const struct V_1 * V_43 )
{
const char * V_44 = strchr ( V_11 , '=' ) ;
const struct V_1 * V_45 = NULL , * V_46 = NULL ;
int V_47 = 0 , V_48 = 0 ;
if ( ! V_44 )
V_44 = V_11 + strlen ( V_11 ) ;
for (; V_43 -> type != V_30 ; V_43 ++ ) {
const char * V_49 ;
int V_4 = 0 ;
if ( ! V_43 -> V_8 )
continue;
V_49 = F_9 ( V_11 , V_43 -> V_8 ) ;
if ( V_43 -> type == V_31 ) {
if ( ! V_49 )
continue;
if ( * V_49 == '=' )
return F_1 ( V_43 , L_5 , V_4 ) ;
if ( * V_49 )
continue;
V_10 -> V_50 [ V_10 -> V_51 ++ ] = V_11 - 2 ;
return 0 ;
}
if ( ! V_49 ) {
if ( ! F_10 ( V_43 -> V_8 , L_12 ) ) {
V_49 = F_9 ( V_11 , V_43 -> V_8 + 3 ) ;
if ( V_49 ) {
V_4 |= V_7 ;
goto V_52;
}
if ( ! F_10 ( V_43 -> V_8 + 3 , V_11 ) ) {
V_4 |= V_7 ;
goto V_53;
}
}
if ( ! strncmp ( V_43 -> V_8 , V_11 , V_44 - V_11 ) ) {
V_53:
if ( V_45 ) {
V_46 = V_45 ;
V_48 = V_47 ;
}
if ( ! ( V_4 & V_7 ) && * V_44 )
V_10 -> V_2 = V_44 + 1 ;
V_45 = V_43 ;
V_47 = V_4 ;
continue;
}
if ( ! F_10 ( L_12 , V_11 ) ) {
V_4 |= V_7 ;
goto V_53;
}
if ( strncmp ( V_11 , L_12 , 3 ) )
continue;
V_4 |= V_7 ;
V_49 = F_9 ( V_11 + 3 , V_43 -> V_8 ) ;
if ( ! V_49 && ! F_10 ( V_43 -> V_8 , V_11 + 3 ) )
goto V_53;
if ( ! V_49 )
continue;
}
V_52:
if ( * V_49 ) {
if ( * V_49 != '=' )
continue;
V_10 -> V_2 = V_49 + 1 ;
}
return F_3 ( V_10 , V_43 , V_4 ) ;
}
if ( V_46 )
return error ( L_13
L_14 ,
V_11 ,
( V_48 & V_7 ) ? L_12 : L_15 ,
V_46 -> V_8 ,
( V_47 & V_7 ) ? L_12 : L_15 ,
V_45 -> V_8 ) ;
if ( V_45 )
return F_3 ( V_10 , V_45 , V_47 ) ;
return - 2 ;
}
static void F_11 ( const char * V_11 , const struct V_1 * V_43 )
{
if ( strlen ( V_11 ) < 3 )
return;
if ( ! F_10 ( V_11 , L_12 ) ) {
error ( L_16 , V_11 ) ;
exit ( 129 ) ;
}
for (; V_43 -> type != V_30 ; V_43 ++ ) {
if ( ! V_43 -> V_8 )
continue;
if ( ! F_10 ( V_43 -> V_8 , V_11 ) ) {
error ( L_16 , V_11 ) ;
exit ( 129 ) ;
}
}
}
void F_12 ( struct V_9 * V_54 ,
int V_13 , const char * * V_14 , int V_4 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_13 = V_13 - 1 ;
V_54 -> V_14 = V_14 + 1 ;
V_54 -> V_50 = V_14 ;
V_54 -> V_51 = ( ( V_4 & V_55 ) != 0 ) ;
V_54 -> V_4 = V_4 ;
if ( ( V_4 & V_56 ) &&
( V_4 & V_57 ) )
F_6 ( L_17 ) ;
}
int F_13 ( struct V_9 * V_54 ,
const struct V_1 * V_43 ,
const char * const V_58 [] )
{
int V_59 = ! ( V_54 -> V_4 & V_60 ) ;
int V_61 = 1 ;
const char * V_11 ;
V_54 -> V_2 = NULL ;
for (; V_54 -> V_13 ; V_54 -> V_13 -- , V_54 -> V_14 ++ ) {
V_11 = V_54 -> V_14 [ 0 ] ;
if ( * V_11 != '-' || ! V_11 [ 1 ] ) {
if ( V_54 -> V_4 & V_57 )
break;
V_54 -> V_50 [ V_54 -> V_51 ++ ] = V_54 -> V_14 [ 0 ] ;
continue;
}
if ( V_11 [ 1 ] != '-' ) {
V_54 -> V_2 = ++ V_11 ;
if ( V_59 && * V_54 -> V_2 == 'h' )
return F_14 ( V_58 , V_43 , 0 ) ;
switch ( F_7 ( V_54 , V_43 ) ) {
case - 1 :
return F_15 ( V_58 , V_43 , V_11 , 1 ) ;
case - 2 :
goto V_62;
case - 3 :
goto V_63;
default:
break;
}
if ( V_54 -> V_2 )
F_11 ( V_11 , V_43 ) ;
while ( V_54 -> V_2 ) {
if ( V_59 && * V_54 -> V_2 == 'h' )
return F_14 ( V_58 , V_43 , 0 ) ;
V_11 = V_54 -> V_2 ;
switch ( F_7 ( V_54 , V_43 ) ) {
case - 1 :
return F_15 ( V_58 , V_43 , V_11 , 1 ) ;
case - 2 :
V_54 -> V_14 [ 0 ] = F_16 ( V_54 -> V_2 - 1 ) ;
* ( char * ) V_54 -> V_14 [ 0 ] = '-' ;
goto V_62;
case - 3 :
goto V_63;
default:
break;
}
}
continue;
}
if ( ! V_11 [ 2 ] ) {
if ( ! ( V_54 -> V_4 & V_64 ) ) {
V_54 -> V_13 -- ;
V_54 -> V_14 ++ ;
}
break;
}
V_11 += 2 ;
if ( V_59 && ! strcmp ( V_11 , L_18 ) )
return F_14 ( V_58 , V_43 , 1 ) ;
if ( V_59 && ! strcmp ( V_11 , L_19 ) )
return F_14 ( V_58 , V_43 , 0 ) ;
if ( ! strcmp ( V_11 , L_20 ) )
return V_65 ;
if ( ! strcmp ( V_11 , L_21 ) )
return V_66 ;
switch ( F_8 ( V_54 , V_11 , V_43 ) ) {
case - 1 :
return F_15 ( V_58 , V_43 , V_11 , 0 ) ;
case - 2 :
goto V_62;
case - 3 :
V_61 = 0 ;
goto V_63;
default:
break;
}
continue;
V_62:
if ( ! ( V_54 -> V_4 & V_56 ) )
return V_67 ;
V_54 -> V_50 [ V_54 -> V_51 ++ ] = V_54 -> V_14 [ 0 ] ;
V_54 -> V_2 = NULL ;
}
return V_68 ;
V_63:
F_15 ( V_58 , V_43 , V_11 , V_61 ) ;
if ( ( V_61 && V_54 -> V_21 -> V_6 ) ||
V_54 -> V_21 -> V_8 == NULL ) {
char V_2 = V_54 -> V_21 -> V_6 ;
F_15 ( NULL , V_43 , & V_2 , 1 ) ;
} else {
F_15 ( NULL , V_43 , V_54 -> V_21 -> V_8 , 0 ) ;
}
return V_69 ;
}
int F_17 ( struct V_9 * V_54 )
{
memmove ( V_54 -> V_50 + V_54 -> V_51 , V_54 -> V_14 , V_54 -> V_13 * sizeof( * V_54 -> V_50 ) ) ;
V_54 -> V_50 [ V_54 -> V_51 + V_54 -> V_13 ] = NULL ;
return V_54 -> V_51 + V_54 -> V_13 ;
}
int F_18 ( int V_13 , const char * * V_14 , const struct V_1 * V_43 ,
const char * const V_70 [] , const char * V_58 [] , int V_4 )
{
struct V_9 V_54 ;
F_19 ( V_13 , V_14 ) ;
if ( V_70 && ! V_58 [ 0 ] ) {
struct V_71 V_72 = V_73 ;
F_20 ( & V_72 , L_22 , V_14 [ 0 ] ) ;
for ( int V_74 = 0 ; V_70 [ V_74 ] ; V_74 ++ ) {
if ( V_74 )
F_21 ( & V_72 , L_23 ) ;
F_21 ( & V_72 , V_70 [ V_74 ] ) ;
}
F_21 ( & V_72 , L_24 ) ;
V_58 [ 0 ] = F_16 ( V_72 . V_72 ) ;
F_22 ( & V_72 ) ;
}
F_12 ( & V_54 , V_13 , V_14 , V_4 ) ;
switch ( F_13 ( & V_54 , V_43 , V_58 ) ) {
case V_69 :
exit ( 129 ) ;
case V_68 :
break;
case V_65 :
while ( V_43 -> type != V_30 ) {
printf ( L_25 , V_43 -> V_8 ) ;
V_43 ++ ;
}
exit ( 130 ) ;
case V_66 :
for ( int V_74 = 0 ; V_70 [ V_74 ] ; V_74 ++ )
printf ( L_26 , V_70 [ V_74 ] ) ;
exit ( 130 ) ;
default:
if ( V_54 . V_14 [ 0 ] [ 1 ] == '-' ) {
error ( L_27 , V_54 . V_14 [ 0 ] + 2 ) ;
} else {
error ( L_28 , * V_54 . V_2 ) ;
}
F_23 ( V_58 , V_43 ) ;
}
return F_17 ( & V_54 ) ;
}
int F_24 ( int V_13 , const char * * V_14 , const struct V_1 * V_43 ,
const char * const V_58 [] , int V_4 )
{
return F_18 ( V_13 , V_14 , V_43 , NULL ,
( const char * * ) V_58 , V_4 ) ;
}
static void F_25 ( const struct V_1 * V_75 , int V_76 )
{
T_1 V_77 ;
int V_78 ;
if ( V_75 -> type == V_32 ) {
fputc ( '\n' , V_79 ) ;
if ( * V_75 -> V_80 )
fprintf ( V_79 , L_29 , V_75 -> V_80 ) ;
return;
}
if ( ! V_76 && ( V_75 -> V_4 & V_81 ) )
return;
if ( V_75 -> V_4 & V_19 )
return;
V_77 = fprintf ( V_79 , L_30 ) ;
if ( V_75 -> V_6 )
V_77 += fprintf ( V_79 , L_31 , V_75 -> V_6 ) ;
else
V_77 += fprintf ( V_79 , L_30 ) ;
if ( V_75 -> V_8 && V_75 -> V_6 )
V_77 += fprintf ( V_79 , L_32 ) ;
if ( V_75 -> V_8 )
V_77 += fprintf ( V_79 , L_33 , V_75 -> V_8 ) ;
switch ( V_75 -> type ) {
case V_31 :
break;
case V_36 :
case V_37 :
case V_34 :
case V_35 :
if ( V_75 -> V_4 & V_40 )
if ( V_75 -> V_8 )
V_77 += fprintf ( V_79 , L_34 ) ;
else
V_77 += fprintf ( V_79 , L_35 ) ;
else
V_77 += fprintf ( V_79 , L_36 ) ;
break;
case V_23 :
if ( V_75 -> V_4 & V_24 )
break;
case V_33 :
if ( V_75 -> V_82 ) {
if ( V_75 -> V_4 & V_40 )
if ( V_75 -> V_8 )
V_77 += fprintf ( V_79 , L_37 , V_75 -> V_82 ) ;
else
V_77 += fprintf ( V_79 , L_38 , V_75 -> V_82 ) ;
else
V_77 += fprintf ( V_79 , L_39 , V_75 -> V_82 ) ;
} else {
if ( V_75 -> V_4 & V_40 )
if ( V_75 -> V_8 )
V_77 += fprintf ( V_79 , L_40 ) ;
else
V_77 += fprintf ( V_79 , L_41 ) ;
else
V_77 += fprintf ( V_79 , L_42 ) ;
}
break;
default:
case V_30 :
case V_32 :
case V_27 :
case V_25 :
case V_26 :
case V_28 :
case V_29 :
break;
}
if ( V_77 <= V_83 )
V_78 = V_83 - V_77 ;
else {
fputc ( '\n' , V_79 ) ;
V_78 = V_83 ;
}
fprintf ( V_79 , L_43 , V_78 + V_84 , L_15 , V_75 -> V_80 ) ;
}
int F_14 ( const char * const * V_58 ,
const struct V_1 * V_75 , int V_76 )
{
if ( ! V_58 )
return V_69 ;
fprintf ( V_79 , L_44 , * V_58 ++ ) ;
while ( * V_58 && * * V_58 )
fprintf ( V_79 , L_45 , * V_58 ++ ) ;
while ( * V_58 ) {
fprintf ( V_79 , L_46 ,
* * V_58 ? L_30 : L_15 ,
* V_58 ) ;
V_58 ++ ;
}
if ( V_75 -> type != V_32 )
fputc ( '\n' , V_79 ) ;
for ( ; V_75 -> type != V_30 ; V_75 ++ )
F_25 ( V_75 , V_76 ) ;
fputc ( '\n' , V_79 ) ;
return V_69 ;
}
void F_23 ( const char * const * V_58 ,
const struct V_1 * V_75 )
{
F_26 ( false ) ;
F_14 ( V_58 , V_75 , 0 ) ;
exit ( 129 ) ;
}
int F_15 ( const char * const * V_58 ,
const struct V_1 * V_75 ,
const char * V_85 , bool V_86 )
{
if ( ! V_58 )
goto V_2;
fprintf ( V_79 , L_44 , * V_58 ++ ) ;
while ( * V_58 && * * V_58 )
fprintf ( V_79 , L_45 , * V_58 ++ ) ;
while ( * V_58 ) {
fprintf ( V_79 , L_46 ,
* * V_58 ? L_30 : L_15 ,
* V_58 ) ;
V_58 ++ ;
}
fputc ( '\n' , V_79 ) ;
V_2:
for ( ; V_75 -> type != V_30 ; V_75 ++ ) {
if ( V_86 ) {
if ( V_75 -> V_6 == * V_85 )
break;
continue;
}
if ( V_75 -> V_8 == NULL )
continue;
if ( ! F_10 ( V_85 , V_75 -> V_8 ) )
break;
if ( ! F_10 ( V_85 , L_12 ) &&
! F_10 ( V_85 + 3 , V_75 -> V_8 ) )
break;
}
if ( V_75 -> type != V_30 )
F_25 ( V_75 , 0 ) ;
return V_69 ;
}
int F_27 ( const struct V_1 * V_2 ,
const char * V_11 V_87 ,
int V_17 )
{
int * V_88 = V_2 -> V_38 ;
if ( V_17 )
* V_88 = 0 ;
else if ( V_2 -> V_6 == 'v' ) {
if ( * V_88 >= 0 )
( * V_88 ) ++ ;
else
* V_88 = 1 ;
} else {
if ( * V_88 <= 0 )
( * V_88 ) -- ;
else
* V_88 = - 1 ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_75 , int V_89 , const char * V_90 ,
int V_91 )
{
for (; V_75 -> type != V_30 ; V_75 ++ ) {
if ( ( V_89 && V_75 -> V_6 == V_89 ) ||
( V_75 -> V_8 && V_90 &&
! strcmp ( V_75 -> V_8 , V_90 ) ) ) {
V_75 -> V_4 |= V_91 ;
break;
}
}
}
