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
else if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 )
* ( const char * * ) V_2 -> V_34 = ( const char * ) V_2 -> V_15 ;
else
return F_2 ( V_10 , V_2 , V_4 , ( const char * * ) V_2 -> V_34 ) ;
return 0 ;
case V_19 :
if ( V_17 )
return ( * V_2 -> V_36 ) ( V_2 , NULL , 1 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_20 )
return ( * V_2 -> V_36 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 )
return ( * V_2 -> V_36 ) ( V_2 , NULL , 0 ) ? ( - 1 ) : 0 ;
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
return ( * V_2 -> V_36 ) ( V_2 , V_11 , 0 ) ? ( - 1 ) : 0 ;
case V_30 :
if ( V_17 ) {
* ( int * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 ) {
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
if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 ) {
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
if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 ) {
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
* ( V_37 * ) V_2 -> V_34 = 0 ;
return 0 ;
}
if ( V_2 -> V_4 & V_35 && ! V_10 -> V_2 ) {
* ( V_37 * ) V_2 -> V_34 = V_2 -> V_15 ;
return 0 ;
}
if ( F_2 ( V_10 , V_2 , V_4 , & V_11 ) )
return - 1 ;
* ( V_37 * ) V_2 -> V_34 = F_4 ( V_11 , ( char * * ) & V_16 , 10 ) ;
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
static int F_6 ( struct V_9 * V_10 , const struct V_1 * V_38 )
{
for (; V_38 -> type != V_26 ; V_38 ++ ) {
if ( V_38 -> V_6 == * V_10 -> V_2 ) {
V_10 -> V_2 = V_10 -> V_2 [ 1 ] ? V_10 -> V_2 + 1 : NULL ;
return F_3 ( V_10 , V_38 , V_5 ) ;
}
}
return - 2 ;
}
static int F_7 ( struct V_9 * V_10 , const char * V_11 ,
const struct V_1 * V_38 )
{
const char * V_39 = strchr ( V_11 , '=' ) ;
const struct V_1 * V_40 = NULL , * V_41 = NULL ;
int V_42 = 0 , V_43 = 0 ;
if ( ! V_39 )
V_39 = V_11 + strlen ( V_11 ) ;
for (; V_38 -> type != V_26 ; V_38 ++ ) {
const char * V_44 ;
int V_4 = 0 ;
if ( ! V_38 -> V_8 )
continue;
V_44 = F_8 ( V_11 , V_38 -> V_8 ) ;
if ( V_38 -> type == V_27 ) {
if ( ! V_44 )
continue;
if ( * V_44 == '=' )
return F_1 ( V_38 , L_5 , V_4 ) ;
if ( * V_44 )
continue;
V_10 -> V_45 [ V_10 -> V_46 ++ ] = V_11 - 2 ;
return 0 ;
}
if ( ! V_44 ) {
if ( ! strncmp ( V_38 -> V_8 , V_11 , V_39 - V_11 ) ) {
V_47:
if ( V_40 ) {
V_41 = V_40 ;
V_43 = V_42 ;
}
if ( ! ( V_4 & V_7 ) && * V_39 )
V_10 -> V_2 = V_39 + 1 ;
V_40 = V_38 ;
V_42 = V_4 ;
continue;
}
if ( ! F_9 ( L_9 , V_11 ) ) {
V_4 |= V_7 ;
goto V_47;
}
if ( strncmp ( V_11 , L_9 , 3 ) )
continue;
V_4 |= V_7 ;
V_44 = F_8 ( V_11 + 3 , V_38 -> V_8 ) ;
if ( ! V_44 && ! F_9 ( V_38 -> V_8 , V_11 + 3 ) )
goto V_47;
if ( ! V_44 )
continue;
}
if ( * V_44 ) {
if ( * V_44 != '=' )
continue;
V_10 -> V_2 = V_44 + 1 ;
}
return F_3 ( V_10 , V_38 , V_4 ) ;
}
if ( V_41 )
return error ( L_10
L_11 ,
V_11 ,
( V_43 & V_7 ) ? L_9 : L_12 ,
V_41 -> V_8 ,
( V_42 & V_7 ) ? L_9 : L_12 ,
V_40 -> V_8 ) ;
if ( V_40 )
return F_3 ( V_10 , V_40 , V_42 ) ;
return - 2 ;
}
static void F_10 ( const char * V_11 , const struct V_1 * V_38 )
{
if ( strlen ( V_11 ) < 3 )
return;
if ( ! F_9 ( V_11 , L_9 ) ) {
error ( L_13 , V_11 ) ;
exit ( 129 ) ;
}
for (; V_38 -> type != V_26 ; V_38 ++ ) {
if ( ! V_38 -> V_8 )
continue;
if ( ! F_9 ( V_38 -> V_8 , V_11 ) ) {
error ( L_13 , V_11 ) ;
exit ( 129 ) ;
}
}
}
void F_11 ( struct V_9 * V_48 ,
int V_13 , const char * * V_14 , int V_4 )
{
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_13 = V_13 - 1 ;
V_48 -> V_14 = V_14 + 1 ;
V_48 -> V_45 = V_14 ;
V_48 -> V_46 = ( ( V_4 & V_49 ) != 0 ) ;
V_48 -> V_4 = V_4 ;
if ( ( V_4 & V_50 ) &&
( V_4 & V_51 ) )
F_5 ( L_14 ) ;
}
int F_12 ( struct V_9 * V_48 ,
const struct V_1 * V_38 ,
const char * const V_52 [] )
{
int V_53 = ! ( V_48 -> V_4 & V_54 ) ;
V_48 -> V_2 = NULL ;
for (; V_48 -> V_13 ; V_48 -> V_13 -- , V_48 -> V_14 ++ ) {
const char * V_11 = V_48 -> V_14 [ 0 ] ;
if ( * V_11 != '-' || ! V_11 [ 1 ] ) {
if ( V_48 -> V_4 & V_51 )
break;
V_48 -> V_45 [ V_48 -> V_46 ++ ] = V_48 -> V_14 [ 0 ] ;
continue;
}
if ( V_11 [ 1 ] != '-' ) {
V_48 -> V_2 = V_11 + 1 ;
if ( V_53 && * V_48 -> V_2 == 'h' )
return F_13 ( V_52 , V_38 , 0 ) ;
switch ( F_6 ( V_48 , V_38 ) ) {
case - 1 :
return F_14 ( V_52 , V_38 , V_11 + 1 , 1 ) ;
case - 2 :
goto V_55;
default:
break;
}
if ( V_48 -> V_2 )
F_10 ( V_11 + 1 , V_38 ) ;
while ( V_48 -> V_2 ) {
if ( V_53 && * V_48 -> V_2 == 'h' )
return F_13 ( V_52 , V_38 , 0 ) ;
V_11 = V_48 -> V_2 ;
switch ( F_6 ( V_48 , V_38 ) ) {
case - 1 :
return F_14 ( V_52 , V_38 , V_11 , 1 ) ;
case - 2 :
V_48 -> V_14 [ 0 ] = F_15 ( V_48 -> V_2 - 1 ) ;
* ( char * ) V_48 -> V_14 [ 0 ] = '-' ;
goto V_55;
default:
break;
}
}
continue;
}
if ( ! V_11 [ 2 ] ) {
if ( ! ( V_48 -> V_4 & V_56 ) ) {
V_48 -> V_13 -- ;
V_48 -> V_14 ++ ;
}
break;
}
if ( V_53 && ! strcmp ( V_11 + 2 , L_15 ) )
return F_13 ( V_52 , V_38 , 1 ) ;
if ( V_53 && ! strcmp ( V_11 + 2 , L_16 ) )
return F_13 ( V_52 , V_38 , 0 ) ;
if ( ! strcmp ( V_11 + 2 , L_17 ) )
return V_57 ;
switch ( F_7 ( V_48 , V_11 + 2 , V_38 ) ) {
case - 1 :
return F_14 ( V_52 , V_38 , V_11 + 2 , 0 ) ;
case - 2 :
goto V_55;
default:
break;
}
continue;
V_55:
if ( ! ( V_48 -> V_4 & V_50 ) )
return V_58 ;
V_48 -> V_45 [ V_48 -> V_46 ++ ] = V_48 -> V_14 [ 0 ] ;
V_48 -> V_2 = NULL ;
}
return V_59 ;
}
int F_16 ( struct V_9 * V_48 )
{
memmove ( V_48 -> V_45 + V_48 -> V_46 , V_48 -> V_14 , V_48 -> V_13 * sizeof( * V_48 -> V_45 ) ) ;
V_48 -> V_45 [ V_48 -> V_46 + V_48 -> V_13 ] = NULL ;
return V_48 -> V_46 + V_48 -> V_13 ;
}
int F_17 ( int V_13 , const char * * V_14 , const struct V_1 * V_38 ,
const char * const V_52 [] , int V_4 )
{
struct V_9 V_48 ;
F_18 ( V_13 , V_14 ) ;
F_11 ( & V_48 , V_13 , V_14 , V_4 ) ;
switch ( F_12 ( & V_48 , V_38 , V_52 ) ) {
case V_60 :
exit ( 129 ) ;
case V_59 :
break;
case V_57 :
while ( V_38 -> type != V_26 ) {
printf ( L_18 , V_38 -> V_8 ) ;
V_38 ++ ;
}
exit ( 130 ) ;
default:
if ( V_48 . V_14 [ 0 ] [ 1 ] == '-' ) {
error ( L_19 , V_48 . V_14 [ 0 ] + 2 ) ;
} else {
error ( L_20 , * V_48 . V_2 ) ;
}
F_19 ( V_52 , V_38 ) ;
}
return F_16 ( & V_48 ) ;
}
static void F_20 ( const struct V_1 * V_61 , int V_62 )
{
T_1 V_63 ;
int V_64 ;
if ( V_61 -> type == V_28 ) {
fputc ( '\n' , V_65 ) ;
if ( * V_61 -> V_66 )
fprintf ( V_65 , L_21 , V_61 -> V_66 ) ;
return;
}
if ( ! V_62 && ( V_61 -> V_4 & V_67 ) )
return;
V_63 = fprintf ( V_65 , L_22 ) ;
if ( V_61 -> V_6 )
V_63 += fprintf ( V_65 , L_23 , V_61 -> V_6 ) ;
else
V_63 += fprintf ( V_65 , L_22 ) ;
if ( V_61 -> V_8 && V_61 -> V_6 )
V_63 += fprintf ( V_65 , L_24 ) ;
if ( V_61 -> V_8 )
V_63 += fprintf ( V_65 , L_25 , V_61 -> V_8 ) ;
switch ( V_61 -> type ) {
case V_27 :
break;
case V_32 :
case V_33 :
case V_30 :
case V_31 :
if ( V_61 -> V_4 & V_35 )
if ( V_61 -> V_8 )
V_63 += fprintf ( V_65 , L_26 ) ;
else
V_63 += fprintf ( V_65 , L_27 ) ;
else
V_63 += fprintf ( V_65 , L_28 ) ;
break;
case V_19 :
if ( V_61 -> V_4 & V_20 )
break;
case V_29 :
if ( V_61 -> V_68 ) {
if ( V_61 -> V_4 & V_35 )
if ( V_61 -> V_8 )
V_63 += fprintf ( V_65 , L_29 , V_61 -> V_68 ) ;
else
V_63 += fprintf ( V_65 , L_30 , V_61 -> V_68 ) ;
else
V_63 += fprintf ( V_65 , L_31 , V_61 -> V_68 ) ;
} else {
if ( V_61 -> V_4 & V_35 )
if ( V_61 -> V_8 )
V_63 += fprintf ( V_65 , L_32 ) ;
else
V_63 += fprintf ( V_65 , L_33 ) ;
else
V_63 += fprintf ( V_65 , L_34 ) ;
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
if ( V_63 <= V_69 )
V_64 = V_69 - V_63 ;
else {
fputc ( '\n' , V_65 ) ;
V_64 = V_69 ;
}
fprintf ( V_65 , L_35 , V_64 + V_70 , L_12 , V_61 -> V_66 ) ;
}
int F_13 ( const char * const * V_52 ,
const struct V_1 * V_61 , int V_62 )
{
if ( ! V_52 )
return V_60 ;
fprintf ( V_65 , L_36 , * V_52 ++ ) ;
while ( * V_52 && * * V_52 )
fprintf ( V_65 , L_37 , * V_52 ++ ) ;
while ( * V_52 ) {
fprintf ( V_65 , L_38 ,
* * V_52 ? L_22 : L_12 ,
* V_52 ) ;
V_52 ++ ;
}
if ( V_61 -> type != V_28 )
fputc ( '\n' , V_65 ) ;
for ( ; V_61 -> type != V_26 ; V_61 ++ )
F_20 ( V_61 , V_62 ) ;
fputc ( '\n' , V_65 ) ;
return V_60 ;
}
void F_19 ( const char * const * V_52 ,
const struct V_1 * V_61 )
{
F_21 ( false ) ;
F_13 ( V_52 , V_61 , 0 ) ;
exit ( 129 ) ;
}
int F_14 ( const char * const * V_52 ,
const struct V_1 * V_61 ,
const char * V_71 , bool V_72 )
{
if ( ! V_52 )
goto V_2;
fprintf ( V_65 , L_36 , * V_52 ++ ) ;
while ( * V_52 && * * V_52 )
fprintf ( V_65 , L_37 , * V_52 ++ ) ;
while ( * V_52 ) {
fprintf ( V_65 , L_38 ,
* * V_52 ? L_22 : L_12 ,
* V_52 ) ;
V_52 ++ ;
}
fputc ( '\n' , V_65 ) ;
V_2:
for ( ; V_61 -> type != V_26 ; V_61 ++ ) {
if ( V_72 ) {
if ( V_61 -> V_6 == * V_71 )
break;
continue;
}
if ( V_61 -> V_8 == NULL )
continue;
if ( ! F_9 ( V_71 , V_61 -> V_8 ) )
break;
if ( ! F_9 ( V_71 , L_9 ) &&
! F_9 ( V_71 + 3 , V_61 -> V_8 ) )
break;
}
if ( V_61 -> type != V_26 )
F_20 ( V_61 , 0 ) ;
return V_60 ;
}
int F_22 ( const struct V_1 * V_2 ,
const char * V_11 V_73 ,
int V_17 )
{
int * V_74 = V_2 -> V_34 ;
if ( V_17 )
* V_74 = 0 ;
else if ( V_2 -> V_6 == 'v' ) {
if ( * V_74 >= 0 )
( * V_74 ) ++ ;
else
* V_74 = 1 ;
} else {
if ( * V_74 <= 0 )
( * V_74 ) -- ;
else
* V_74 = - 1 ;
}
return 0 ;
}
