static int F_1 ( const struct V_1 * V_2 ,
const char * V_3 , int T_1 V_4 )
{
struct V_5 * V_6 = * (struct V_5 * * ) V_2 -> V_7 ;
int V_8 ;
if ( strcmp ( V_3 , L_1 ) ) {
if ( ! F_2 ( V_3 ) ) {
V_6 -> V_9 = 0 ;
return 0 ;
}
exit ( - 1 ) ;
}
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
struct V_11 * V_12 = & V_13 [ V_8 ] ;
fprintf ( V_14 , L_2 ,
V_12 -> V_15 ,
V_16 ? 25 : 0 ,
V_16 ? F_3 ( V_8 ) : L_3 ,
V_12 -> V_17 ? L_4 : L_3 ) ;
}
exit ( 0 ) ;
}
static int F_4 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
int V_20 , V_21 = 0 , V_8 ;
const char * * V_22 ;
int V_23 ;
struct V_1 V_24 [] = {
F_5 ( 'e' , L_5 , & V_6 , L_5 ,
L_6 ,
F_1 ) ,
F_6 ( 'v' , L_7 , & V_16 ,
L_8 ) ,
F_7 ()
} ;
V_18 = F_8 ( V_18 , V_19 , V_24 , V_25 ,
V_26 ) ;
V_20 = V_18 + 7 ;
V_22 = calloc ( V_20 + 1 , sizeof( char * ) ) ;
if ( ! V_22 )
return - 1 ;
V_22 [ V_21 ++ ] = L_9 ;
if ( V_6 -> V_9 & V_27 )
V_13 [ V_28 ] . V_29 = true ;
if ( V_13 [ V_28 ] . V_29 )
V_22 [ V_21 ++ ] = L_10 ;
V_22 [ V_21 ++ ] = L_11 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ! V_13 [ V_8 ] . V_29 )
continue;
if ( ! V_13 [ V_8 ] . V_17 ) {
F_9 ( L_12 ,
F_3 ( V_8 ) ) ;
return - 1 ;
}
V_22 [ V_21 ++ ] = L_13 ;
V_22 [ V_21 ++ ] = F_3 ( V_8 ) ;
} ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_22 [ V_21 ] = V_19 [ V_8 ] ;
if ( V_16 > 0 ) {
F_10 ( L_14 ) ;
while ( V_22 [ V_8 ] ) {
F_10 ( L_15 , V_22 [ V_8 ] ) ;
V_8 ++ ;
}
F_10 ( L_16 ) ;
}
V_23 = F_11 ( V_21 , V_22 , NULL ) ;
free ( V_22 ) ;
return V_23 ;
}
static int
F_12 ( struct V_30 * V_31 ,
union V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_36 * V_36 )
{
struct V_5 * V_6 = F_13 ( V_31 , struct V_5 , V_31 ) ;
struct V_37 V_38 ;
const char * V_39 ;
if ( F_14 ( V_36 , & V_38 , V_35 ) < 0 ) {
fprintf ( V_14 , L_17 ,
V_33 -> V_40 . type ) ;
return - 1 ;
}
if ( V_38 . V_41 || ( V_6 -> V_42 && V_38 . V_43 == NULL ) )
goto V_44;
if ( V_38 . V_45 != NULL )
V_38 . V_45 -> V_46 -> V_47 = 1 ;
if ( V_48 . V_49 ) {
V_39 = L_18 V_50 L_19 V_50 L_20 V_51
L_19 V_50 L_21 ;
} else {
V_39 = L_22 V_50 L_23 V_50
L_24 V_51 L_25 V_50 L_21 ;
V_48 . V_49 = L_26 ;
}
printf ( V_39 ,
V_35 -> V_52 ,
V_48 . V_49 ,
V_35 -> V_53 ,
V_48 . V_49 ,
V_35 -> V_54 ,
V_48 . V_49 ,
V_35 -> V_55 ,
V_48 . V_49 ,
V_35 -> V_56 ,
V_48 . V_49 ,
V_35 -> V_57 ,
V_48 . V_49 ,
V_38 . V_45 ? ( V_38 . V_45 -> V_46 ? V_38 . V_45 -> V_46 -> V_58 : L_27 ) : L_27 ,
V_38 . V_43 ? V_38 . V_43 -> V_59 : L_27 ) ;
V_44:
F_15 ( & V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 ,
union V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_60 * T_2 V_4 ,
struct V_36 * V_36 )
{
return F_12 ( V_31 , V_33 , V_35 , V_36 ) ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_61 V_62 = {
. V_63 = V_64 ,
. V_65 = V_66 ,
. V_67 = V_6 -> V_67 ,
} ;
int V_23 ;
struct V_68 * V_69 = F_18 ( & V_62 , false ,
& V_6 -> V_31 ) ;
if ( V_69 == NULL )
return - 1 ;
if ( V_6 -> V_70 ) {
V_23 = F_19 ( V_69 , V_6 -> V_70 ,
V_6 -> V_71 ) ;
if ( V_23 < 0 )
goto V_72;
}
V_23 = F_20 ( & V_69 -> V_40 . V_73 ) ;
if ( V_23 < 0 )
goto V_72;
printf ( L_28 ) ;
V_23 = F_21 ( V_69 ) ;
V_72:
F_22 ( V_69 ) ;
return V_23 ;
}
static int F_23 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
const char * * V_74 ;
int V_23 , V_21 = 0 , V_8 , V_75 ;
if ( V_6 -> V_76 )
return F_17 ( V_6 ) ;
V_75 = V_18 + 3 ;
V_74 = calloc ( V_75 + 1 , sizeof( char * ) ) ;
if ( ! V_74 )
return - 1 ;
V_74 [ V_21 ++ ] = L_29 ;
V_74 [ V_21 ++ ] = L_30 ;
V_74 [ V_21 ++ ] = L_31 ;
if ( ! ( V_6 -> V_9 & V_27 ) )
V_74 [ V_21 ++ ] = L_32
L_33 ;
for ( V_8 = 1 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_74 [ V_21 ] = V_19 [ V_8 ] ;
V_23 = F_24 ( V_21 , V_74 , NULL ) ;
free ( V_74 ) ;
return V_23 ;
}
static int
F_25 ( const struct V_1 * V_2 , const char * V_3 , int T_1 )
{
int * V_65 = ( int * ) V_2 -> V_7 ;
const struct V_77 * V_78 ;
char * V_79 , * V_80 = NULL , * V_81 ;
int V_23 = - 1 ;
if ( T_1 )
return 0 ;
if ( V_3 ) {
V_79 = V_80 = F_26 ( V_3 ) ;
if ( ! V_79 )
return - 1 ;
* V_65 = 0 ;
for (; ; ) {
V_81 = strchr ( V_79 , ',' ) ;
if ( V_81 )
* V_81 = '\0' ;
for ( V_78 = V_82 ; V_78 -> V_59 ; V_78 ++ ) {
if ( ! strcasecmp ( V_79 , V_78 -> V_59 ) )
break;
}
if ( ! V_78 -> V_59 ) {
fprintf ( V_14 , L_34
L_35 , V_79 ) ;
goto error;
}
* V_65 |= V_78 -> V_65 ;
if ( ! V_81 )
break;
V_79 = V_81 + 1 ;
}
}
V_23 = 0 ;
if ( * V_65 == 0 )
* V_65 = V_27 ;
error:
free ( V_80 ) ;
return V_23 ;
}
int F_27 ( int V_18 , const char * * V_19 , const char * T_3 V_4 )
{
struct V_83 V_84 ;
struct V_5 V_6 = {
. V_31 = {
. V_35 = F_16 ,
. V_85 = V_86 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
. V_91 = V_92 ,
. V_93 = V_94 ,
. V_95 = V_96 ,
. V_97 = true ,
} ,
. V_64 = L_36 ,
. V_9 = V_27 | V_98 ,
} ;
const struct V_1 V_99 [] = {
F_5 ( 't' , L_37 , & V_6 . V_9 ,
L_37 , L_38 ,
F_25 ) ,
F_28 ( 'D' , L_39 , & V_6 . V_76 ,
L_40 ) ,
F_28 ( 'U' , L_41 , & V_6 . V_42 ,
L_42 ) ,
F_29 ( 'i' , L_43 , & V_64 , L_44 ,
L_45 ) ,
F_29 ( 'C' , L_46 , & V_6 . V_70 , L_46 ,
L_47 ) ,
F_30 ( 'x' , L_48 , & V_48 . V_49 ,
L_49 ,
L_50
L_51 ) ,
F_28 ( 'f' , L_52 , & V_6 . V_67 , L_53 ) ,
F_7 ()
} ;
const char * const V_100 [] = { L_9 , L_29 , NULL } ;
const char * V_101 [] = {
NULL ,
NULL
} ;
if ( F_31 () ) {
F_9 ( L_54 ) ;
return - 1 ;
}
V_18 = F_32 ( V_18 , V_19 , V_99 , V_100 ,
V_101 , V_26 ) ;
if ( ! V_18 || ! ( strncmp ( V_19 [ 0 ] , L_55 , 3 ) || V_6 . V_9 ) )
F_33 ( V_101 , V_99 ) ;
if ( ! V_6 . V_64 || ! strlen ( V_6 . V_64 ) ) {
if ( ! F_34 ( V_102 , & V_84 ) && F_35 ( V_84 . V_103 ) )
V_6 . V_64 = L_56 ;
else
V_6 . V_64 = L_36 ;
}
if ( ! strncmp ( V_19 [ 0 ] , L_55 , 3 ) )
return F_4 ( V_18 , V_19 , & V_6 ) ;
else if ( ! strncmp ( V_19 [ 0 ] , L_57 , 3 ) )
return F_23 ( V_18 , V_19 , & V_6 ) ;
else
F_33 ( V_101 , V_99 ) ;
return 0 ;
}
