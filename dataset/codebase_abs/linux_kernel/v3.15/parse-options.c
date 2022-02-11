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
if ( ! ( V_4 & V_5 ) && V_10 -> V_2 ) {
switch ( V_2 -> type ) {
case V_19 :
if ( ! ( V_2 -> V_4 & V_20 ) )
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return F_1 ( V_2 , L_5 , V_4 ) ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
default:
break;
}
}
switch ( V_2 -> type ) {
case V_23 :
if ( V_17 )
* ( int * ) V_2 -> V_34 &= ~ V_2 -> V_15 ;
else
* ( int * ) V_2 -> V_34 |= V_2 -> V_15 ;
return 0 ;
case V_21 :
* ( bool * ) V_2 -> V_34 = V_17 ? false : true ;
if ( V_2 -> V_35 )
* ( bool * ) V_2 -> V_35 = true ;
return 0 ;
case V_22 :
* ( int * ) V_2 -> V_34 = V_17 ? 0 : * ( int * ) V_2 -> V_34 + 1 ;
return 0 ;
case V_24 :
* ( unsigned int * ) V_2 -> V_34 = V_17 ? 0 : V_2 -> V_15 ;
return 0 ;
case V_25 :
* ( void * * ) V_2 -> V_34 = V_17 ? NULL : ( void * ) V_2 -> V_15 ;
return 0 ;
case V_29 :
if ( V_17 )
* ( const char * * ) V_2 -> V_34 = NULL ;
else if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 )
* ( const char * * ) V_2 -> V_34 = ( const char * ) V_2 -> V_15 ;
else
return F_2 ( V_10 , V_2 , V_4 , ( const char * * ) V_2 -> V_34 ) ;
return 0 ;
case V_19 :
if ( V_17 )
return ( * V_2 -> V_37 ) ( V_2 , NULL , 1 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_20 )
return ( * V_2 -> V_37 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 )
return ( * V_2 -> V_37 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
return ( * V_2 -> V_37 ) ( V_2 , V_11 , 0 ) ? ( - 1 ) : 0 ;
case V_30 :
if ( V_17 ) {
* ( int * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 ) {
* ( int * ) V_2 -> V_34 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( int * ) V_2 -> V_34 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_7 , V_4 ) ;
return 0 ;
case V_31 :
if ( V_17 ) {
* ( unsigned int * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 ) {
* ( unsigned int * ) V_2 -> V_34 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( unsigned int * ) V_2 -> V_34 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_7 , V_4 ) ;
return 0 ;
case V_32 :
if ( V_17 ) {
* ( long * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 ) {
* ( long * ) V_2 -> V_34 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( long * ) V_2 -> V_34 = strtol ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_7 , V_4 ) ;
return 0 ;
case V_33 :
if ( V_17 ) {
* ( V_38 * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_36 && ! V_10 -> V_2 ) {
* ( V_38 * ) V_2 -> V_34 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( V_38 * ) V_2 -> V_34 = F_4 ( V_11 , ( char * * ) & V_16 , 10 ) ;
if ( * V_16 )
return F_1 ( V_2 , L_7 , V_4 ) ;
return 0 ;
case V_26 :
case V_27 :
case V_28 :
default:
F_5 ( L_8 ) ;
}
}
static int F_6 ( struct V_9 * V_10 , const struct V_1 * V_39 )
{
for (; V_39 -> type != V_26 ; V_39 ++ ) {
if ( V_39 -> V_6 == * V_10 -> V_2 ) {
V_10 -> V_2 = V_10 -> V_2 [ 1 ] ? V_10 -> V_2 + 1 : NULL ;
return F_3 ( V_10 , V_39 , V_5 ) ;
}
}
return - 2 ;
}
static int F_7 ( struct V_9 * V_10 , const char * V_11 ,
const struct V_1 * V_39 )
{
const char * V_40 = strchr ( V_11 , '=' ) ;
const struct V_1 * V_41 = NULL , * V_42 = NULL ;
int V_43 = 0 , V_44 = 0 ;
if ( ! V_40 )
V_40 = V_11 + strlen ( V_11 ) ;
for (; V_39 -> type != V_26 ; V_39 ++ ) {
const char * V_45 ;
int V_4 = 0 ;
if ( ! V_39 -> V_8 )
continue;
V_45 = F_8 ( V_11 , V_39 -> V_8 ) ;
if ( V_39 -> type == V_27 ) {
if ( ! V_45 )
continue;
if ( * V_45 == '=' )
return F_1 ( V_39 , L_5 , V_4 ) ;
if ( * V_45 )
continue;
V_10 -> V_46 [ V_10 -> V_47 ++ ] = V_11 - 2 ;
return 0 ;
}
if ( ! V_45 ) {
if ( ! F_9 ( V_39 -> V_8 , L_9 ) ) {
V_45 = F_8 ( V_11 , V_39 -> V_8 + 3 ) ;
if ( V_45 ) {
V_4 |= V_7 ;
goto V_48;
}
if ( ! F_9 ( V_39 -> V_8 + 3 , V_11 ) ) {
V_4 |= V_7 ;
goto V_49;
}
}
if ( ! strncmp ( V_39 -> V_8 , V_11 , V_40 - V_11 ) ) {
V_49:
if ( V_41 ) {
V_42 = V_41 ;
V_44 = V_43 ;
}
if ( ! ( V_4 & V_7 ) && * V_40 )
V_10 -> V_2 = V_40 + 1 ;
V_41 = V_39 ;
V_43 = V_4 ;
continue;
}
if ( ! F_9 ( L_9 , V_11 ) ) {
V_4 |= V_7 ;
goto V_49;
}
if ( strncmp ( V_11 , L_9 , 3 ) )
continue;
V_4 |= V_7 ;
V_45 = F_8 ( V_11 + 3 , V_39 -> V_8 ) ;
if ( ! V_45 && ! F_9 ( V_39 -> V_8 , V_11 + 3 ) )
goto V_49;
if ( ! V_45 )
continue;
}
V_48:
if ( * V_45 ) {
if ( * V_45 != '=' )
continue;
V_10 -> V_2 = V_45 + 1 ;
}
return F_3 ( V_10 , V_39 , V_4 ) ;
}
if ( V_42 )
return error ( L_10
L_11 ,
V_11 ,
( V_44 & V_7 ) ? L_9 : L_12 ,
V_42 -> V_8 ,
( V_43 & V_7 ) ? L_9 : L_12 ,
V_41 -> V_8 ) ;
if ( V_41 )
return F_3 ( V_10 , V_41 , V_43 ) ;
return - 2 ;
}
static void F_10 ( const char * V_11 , const struct V_1 * V_39 )
{
if ( strlen ( V_11 ) < 3 )
return;
if ( ! F_9 ( V_11 , L_9 ) ) {
error ( L_13 , V_11 ) ;
exit ( 129 ) ;
}
for (; V_39 -> type != V_26 ; V_39 ++ ) {
if ( ! V_39 -> V_8 )
continue;
if ( ! F_9 ( V_39 -> V_8 , V_11 ) ) {
error ( L_13 , V_11 ) ;
exit ( 129 ) ;
}
}
}
void F_11 ( struct V_9 * V_50 ,
int V_13 , const char * * V_14 , int V_4 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_13 = V_13 - 1 ;
V_50 -> V_14 = V_14 + 1 ;
V_50 -> V_46 = V_14 ;
V_50 -> V_47 = ( ( V_4 & V_51 ) != 0 ) ;
V_50 -> V_4 = V_4 ;
if ( ( V_4 & V_52 ) &&
( V_4 & V_53 ) )
F_5 ( L_14 ) ;
}
int F_12 ( struct V_9 * V_50 ,
const struct V_1 * V_39 ,
const char * const V_54 [] )
{
int V_55 = ! ( V_50 -> V_4 & V_56 ) ;
V_50 -> V_2 = NULL ;
for (; V_50 -> V_13 ; V_50 -> V_13 -- , V_50 -> V_14 ++ ) {
const char * V_11 = V_50 -> V_14 [ 0 ] ;
if ( * V_11 != '-' || ! V_11 [ 1 ] ) {
if ( V_50 -> V_4 & V_53 )
break;
V_50 -> V_46 [ V_50 -> V_47 ++ ] = V_50 -> V_14 [ 0 ] ;
continue;
}
if ( V_11 [ 1 ] != '-' ) {
V_50 -> V_2 = V_11 + 1 ;
if ( V_55 && * V_50 -> V_2 == 'h' )
return F_13 ( V_54 , V_39 , 0 ) ;
switch ( F_6 ( V_50 , V_39 ) ) {
case - 1 :
return F_14 ( V_54 , V_39 , V_11 + 1 , 1 ) ;
case - 2 :
goto V_57;
default:
break;
}
if ( V_50 -> V_2 )
F_10 ( V_11 + 1 , V_39 ) ;
while ( V_50 -> V_2 ) {
if ( V_55 && * V_50 -> V_2 == 'h' )
return F_13 ( V_54 , V_39 , 0 ) ;
V_11 = V_50 -> V_2 ;
switch ( F_6 ( V_50 , V_39 ) ) {
case - 1 :
return F_14 ( V_54 , V_39 , V_11 , 1 ) ;
case - 2 :
V_50 -> V_14 [ 0 ] = F_15 ( V_50 -> V_2 - 1 ) ;
* ( char * ) V_50 -> V_14 [ 0 ] = '-' ;
goto V_57;
default:
break;
}
}
continue;
}
if ( ! V_11 [ 2 ] ) {
if ( ! ( V_50 -> V_4 & V_58 ) ) {
V_50 -> V_13 -- ;
V_50 -> V_14 ++ ;
}
break;
}
if ( V_55 && ! strcmp ( V_11 + 2 , L_15 ) )
return F_13 ( V_54 , V_39 , 1 ) ;
if ( V_55 && ! strcmp ( V_11 + 2 , L_16 ) )
return F_13 ( V_54 , V_39 , 0 ) ;
if ( ! strcmp ( V_11 + 2 , L_17 ) )
return V_59 ;
if ( ! strcmp ( V_11 + 2 , L_18 ) )
return V_60 ;
switch ( F_7 ( V_50 , V_11 + 2 , V_39 ) ) {
case - 1 :
return F_14 ( V_54 , V_39 , V_11 + 2 , 0 ) ;
case - 2 :
goto V_57;
default:
break;
}
continue;
V_57:
if ( ! ( V_50 -> V_4 & V_52 ) )
return V_61 ;
V_50 -> V_46 [ V_50 -> V_47 ++ ] = V_50 -> V_14 [ 0 ] ;
V_50 -> V_2 = NULL ;
}
return V_62 ;
}
int F_16 ( struct V_9 * V_50 )
{
memmove ( V_50 -> V_46 + V_50 -> V_47 , V_50 -> V_14 , V_50 -> V_13 * sizeof( * V_50 -> V_46 ) ) ;
V_50 -> V_46 [ V_50 -> V_47 + V_50 -> V_13 ] = NULL ;
return V_50 -> V_47 + V_50 -> V_13 ;
}
int F_17 ( int V_13 , const char * * V_14 , const struct V_1 * V_39 ,
const char * const V_63 [] , const char * V_54 [] , int V_4 )
{
struct V_9 V_50 ;
F_18 ( V_13 , V_14 ) ;
if ( V_63 && ! V_54 [ 0 ] ) {
struct V_64 V_65 = V_66 ;
F_19 ( & V_65 , L_19 , V_14 [ 0 ] ) ;
for ( int V_67 = 0 ; V_63 [ V_67 ] ; V_67 ++ ) {
if ( V_67 )
F_20 ( & V_65 , L_20 ) ;
F_20 ( & V_65 , V_63 [ V_67 ] ) ;
}
F_20 ( & V_65 , L_21 ) ;
V_54 [ 0 ] = F_15 ( V_65 . V_65 ) ;
F_21 ( & V_65 ) ;
}
F_11 ( & V_50 , V_13 , V_14 , V_4 ) ;
switch ( F_12 ( & V_50 , V_39 , V_54 ) ) {
case V_68 :
exit ( 129 ) ;
case V_62 :
break;
case V_59 :
while ( V_39 -> type != V_26 ) {
printf ( L_22 , V_39 -> V_8 ) ;
V_39 ++ ;
}
exit ( 130 ) ;
case V_60 :
for ( int V_67 = 0 ; V_63 [ V_67 ] ; V_67 ++ )
printf ( L_23 , V_63 [ V_67 ] ) ;
exit ( 130 ) ;
default:
if ( V_50 . V_14 [ 0 ] [ 1 ] == '-' ) {
error ( L_24 , V_50 . V_14 [ 0 ] + 2 ) ;
} else {
error ( L_25 , * V_50 . V_2 ) ;
}
F_22 ( V_54 , V_39 ) ;
}
return F_16 ( & V_50 ) ;
}
int F_23 ( int V_13 , const char * * V_14 , const struct V_1 * V_39 ,
const char * const V_54 [] , int V_4 )
{
return F_17 ( V_13 , V_14 , V_39 , NULL ,
( const char * * ) V_54 , V_4 ) ;
}
static void F_24 ( const struct V_1 * V_69 , int V_70 )
{
T_1 V_71 ;
int V_72 ;
if ( V_69 -> type == V_28 ) {
fputc ( '\n' , V_73 ) ;
if ( * V_69 -> V_74 )
fprintf ( V_73 , L_26 , V_69 -> V_74 ) ;
return;
}
if ( ! V_70 && ( V_69 -> V_4 & V_75 ) )
return;
V_71 = fprintf ( V_73 , L_27 ) ;
if ( V_69 -> V_6 )
V_71 += fprintf ( V_73 , L_28 , V_69 -> V_6 ) ;
else
V_71 += fprintf ( V_73 , L_27 ) ;
if ( V_69 -> V_8 && V_69 -> V_6 )
V_71 += fprintf ( V_73 , L_29 ) ;
if ( V_69 -> V_8 )
V_71 += fprintf ( V_73 , L_30 , V_69 -> V_8 ) ;
switch ( V_69 -> type ) {
case V_27 :
break;
case V_32 :
case V_33 :
case V_30 :
case V_31 :
if ( V_69 -> V_4 & V_36 )
if ( V_69 -> V_8 )
V_71 += fprintf ( V_73 , L_31 ) ;
else
V_71 += fprintf ( V_73 , L_32 ) ;
else
V_71 += fprintf ( V_73 , L_33 ) ;
break;
case V_19 :
if ( V_69 -> V_4 & V_20 )
break;
case V_29 :
if ( V_69 -> V_76 ) {
if ( V_69 -> V_4 & V_36 )
if ( V_69 -> V_8 )
V_71 += fprintf ( V_73 , L_34 , V_69 -> V_76 ) ;
else
V_71 += fprintf ( V_73 , L_35 , V_69 -> V_76 ) ;
else
V_71 += fprintf ( V_73 , L_36 , V_69 -> V_76 ) ;
} else {
if ( V_69 -> V_4 & V_36 )
if ( V_69 -> V_8 )
V_71 += fprintf ( V_73 , L_37 ) ;
else
V_71 += fprintf ( V_73 , L_38 ) ;
else
V_71 += fprintf ( V_73 , L_39 ) ;
}
break;
default:
case V_26 :
case V_28 :
case V_23 :
case V_21 :
case V_22 :
case V_24 :
case V_25 :
break;
}
if ( V_71 <= V_77 )
V_72 = V_77 - V_71 ;
else {
fputc ( '\n' , V_73 ) ;
V_72 = V_77 ;
}
fprintf ( V_73 , L_40 , V_72 + V_78 , L_12 , V_69 -> V_74 ) ;
}
int F_13 ( const char * const * V_54 ,
const struct V_1 * V_69 , int V_70 )
{
if ( ! V_54 )
return V_68 ;
fprintf ( V_73 , L_41 , * V_54 ++ ) ;
while ( * V_54 && * * V_54 )
fprintf ( V_73 , L_42 , * V_54 ++ ) ;
while ( * V_54 ) {
fprintf ( V_73 , L_43 ,
* * V_54 ? L_27 : L_12 ,
* V_54 ) ;
V_54 ++ ;
}
if ( V_69 -> type != V_28 )
fputc ( '\n' , V_73 ) ;
for ( ; V_69 -> type != V_26 ; V_69 ++ )
F_24 ( V_69 , V_70 ) ;
fputc ( '\n' , V_73 ) ;
return V_68 ;
}
void F_22 ( const char * const * V_54 ,
const struct V_1 * V_69 )
{
F_25 ( false ) ;
F_13 ( V_54 , V_69 , 0 ) ;
exit ( 129 ) ;
}
int F_14 ( const char * const * V_54 ,
const struct V_1 * V_69 ,
const char * V_79 , bool V_80 )
{
if ( ! V_54 )
goto V_2;
fprintf ( V_73 , L_41 , * V_54 ++ ) ;
while ( * V_54 && * * V_54 )
fprintf ( V_73 , L_42 , * V_54 ++ ) ;
while ( * V_54 ) {
fprintf ( V_73 , L_43 ,
* * V_54 ? L_27 : L_12 ,
* V_54 ) ;
V_54 ++ ;
}
fputc ( '\n' , V_73 ) ;
V_2:
for ( ; V_69 -> type != V_26 ; V_69 ++ ) {
if ( V_80 ) {
if ( V_69 -> V_6 == * V_79 )
break;
continue;
}
if ( V_69 -> V_8 == NULL )
continue;
if ( ! F_9 ( V_79 , V_69 -> V_8 ) )
break;
if ( ! F_9 ( V_79 , L_9 ) &&
! F_9 ( V_79 + 3 , V_69 -> V_8 ) )
break;
}
if ( V_69 -> type != V_26 )
F_24 ( V_69 , 0 ) ;
return V_68 ;
}
int F_26 ( const struct V_1 * V_2 ,
const char * V_11 V_81 ,
int V_17 )
{
int * V_82 = V_2 -> V_34 ;
if ( V_17 )
* V_82 = 0 ;
else if ( V_2 -> V_6 == 'v' ) {
if ( * V_82 >= 0 )
( * V_82 ) ++ ;
else
* V_82 = 1 ;
} else {
if ( * V_82 <= 0 )
( * V_82 ) -- ;
else
* V_82 = - 1 ;
}
return 0 ;
}
