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
V_16 > 0 ? 25 : 0 ,
V_16 > 0 ? F_3 ( V_8 ) : L_3 ,
V_12 -> V_17 ? L_4 : L_3 ) ;
}
exit ( 0 ) ;
}
static int F_4 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
int V_20 , V_21 = 0 , V_8 ;
const char * * V_22 ;
int V_23 ;
bool V_24 = false , V_25 = false ;
struct V_1 V_26 [] = {
F_5 ( 'e' , L_5 , & V_6 , L_5 ,
L_6 ,
F_1 ) ,
F_6 ( 0 , L_7 , & V_27 , L_8 ) ,
F_7 ( 'v' , L_9 , & V_16 ,
L_10 ) ,
F_8 ( 'U' , L_11 , & V_24 , L_12 ) ,
F_8 ( 'K' , L_13 , & V_25 , L_14 ) ,
F_9 ()
} ;
V_18 = F_10 ( V_18 , V_19 , V_26 , V_28 ,
V_29 ) ;
V_20 = V_18 + 9 ;
V_22 = calloc ( V_20 + 1 , sizeof( char * ) ) ;
if ( ! V_22 )
return - 1 ;
V_22 [ V_21 ++ ] = L_15 ;
if ( V_6 -> V_9 & V_30 )
V_13 [ V_31 ] . V_32 = true ;
if ( V_6 -> V_9 & V_33 )
V_13 [ V_34 ] . V_32 = true ;
if ( V_13 [ V_31 ] . V_32 )
V_22 [ V_21 ++ ] = L_16 ;
V_22 [ V_21 ++ ] = L_17 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ! V_13 [ V_8 ] . V_32 )
continue;
if ( ! V_13 [ V_8 ] . V_17 ) {
F_11 ( L_18 ,
F_3 ( V_8 ) ) ;
return - 1 ;
}
V_22 [ V_21 ++ ] = L_19 ;
V_22 [ V_21 ++ ] = F_3 ( V_8 ) ;
} ;
if ( V_24 )
V_22 [ V_21 ++ ] = L_20 ;
if ( V_25 )
V_22 [ V_21 ++ ] = L_21 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_22 [ V_21 ] = V_19 [ V_8 ] ;
if ( V_16 > 0 ) {
F_12 ( L_22 ) ;
while ( V_22 [ V_8 ] ) {
F_12 ( L_23 , V_22 [ V_8 ] ) ;
V_8 ++ ;
}
F_12 ( L_24 ) ;
}
V_23 = F_13 ( V_21 , V_22 , NULL ) ;
free ( V_22 ) ;
return V_23 ;
}
static int
F_14 ( struct V_35 * V_36 ,
union V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_41 )
{
struct V_5 * V_6 = F_15 ( V_36 , struct V_5 , V_36 ) ;
struct V_42 V_43 ;
const char * V_44 ;
if ( F_16 ( V_41 , & V_43 , V_40 ) < 0 ) {
fprintf ( V_14 , L_25 ,
V_38 -> V_45 . type ) ;
return - 1 ;
}
if ( V_43 . V_46 || ( V_6 -> V_47 && V_43 . V_48 == NULL ) )
goto V_49;
if ( V_43 . V_50 != NULL )
V_43 . V_50 -> V_51 -> V_52 = 1 ;
if ( V_53 . V_54 ) {
V_44 = L_26 V_55 L_27 V_55 L_28 V_56
L_27 V_55 L_29 ;
} else {
V_44 = L_30 V_55 L_31 V_55
L_32 V_56 L_33 V_55 L_29 ;
V_53 . V_54 = L_34 ;
}
printf ( V_44 ,
V_40 -> V_57 ,
V_53 . V_54 ,
V_40 -> V_58 ,
V_53 . V_54 ,
V_40 -> V_59 ,
V_53 . V_54 ,
V_40 -> V_60 ,
V_53 . V_54 ,
V_40 -> V_61 ,
V_53 . V_54 ,
V_40 -> V_62 ,
V_53 . V_54 ,
V_43 . V_50 ? ( V_43 . V_50 -> V_51 ? V_43 . V_50 -> V_51 -> V_63 : L_35 ) : L_35 ,
V_43 . V_48 ? V_43 . V_48 -> V_64 : L_35 ) ;
V_49:
F_17 ( & V_43 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 ,
union V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_65 * T_2 V_4 ,
struct V_41 * V_41 )
{
return F_14 ( V_36 , V_38 , V_40 , V_41 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_66 V_67 = {
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = V_6 -> V_72 ,
} ;
int V_23 ;
struct V_73 * V_74 = F_20 ( & V_67 , false ,
& V_6 -> V_36 ) ;
if ( V_74 == NULL )
return - 1 ;
if ( V_6 -> V_75 ) {
V_23 = F_21 ( V_74 , V_6 -> V_75 ,
V_6 -> V_76 ) ;
if ( V_23 < 0 )
goto V_77;
}
V_23 = F_22 ( & V_74 -> V_45 . V_78 ) ;
if ( V_23 < 0 )
goto V_77;
printf ( L_36 ) ;
V_23 = F_23 ( V_74 ) ;
V_77:
F_24 ( V_74 ) ;
return V_23 ;
}
static int F_25 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
const char * * V_79 ;
int V_23 , V_21 = 0 , V_8 , V_80 ;
if ( V_6 -> V_81 )
return F_19 ( V_6 ) ;
V_80 = V_18 + 3 ;
V_79 = calloc ( V_80 + 1 , sizeof( char * ) ) ;
if ( ! V_79 )
return - 1 ;
V_79 [ V_21 ++ ] = L_37 ;
V_79 [ V_21 ++ ] = L_38 ;
V_79 [ V_21 ++ ] = L_39 ;
if ( ! ( V_6 -> V_9 & V_30 ) )
V_79 [ V_21 ++ ] = L_40
L_41 ;
for ( V_8 = 1 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_79 [ V_21 ] = V_19 [ V_8 ] ;
V_23 = F_26 ( V_21 , V_79 , NULL ) ;
free ( V_79 ) ;
return V_23 ;
}
static int
F_27 ( const struct V_1 * V_2 , const char * V_3 , int T_1 )
{
int * V_70 = ( int * ) V_2 -> V_7 ;
const struct V_82 * V_83 ;
char * V_84 , * V_85 = NULL , * V_86 ;
int V_23 = - 1 ;
if ( T_1 )
return 0 ;
if ( V_3 ) {
V_84 = V_85 = F_28 ( V_3 ) ;
if ( ! V_84 )
return - 1 ;
* V_70 = 0 ;
for (; ; ) {
V_86 = strchr ( V_84 , ',' ) ;
if ( V_86 )
* V_86 = '\0' ;
for ( V_83 = V_87 ; V_83 -> V_64 ; V_83 ++ ) {
if ( ! strcasecmp ( V_84 , V_83 -> V_64 ) )
break;
}
if ( ! V_83 -> V_64 ) {
fprintf ( V_14 , L_42
L_43 , V_84 ) ;
goto error;
}
* V_70 |= V_83 -> V_70 ;
if ( ! V_86 )
break;
V_84 = V_86 + 1 ;
}
}
V_23 = 0 ;
if ( * V_70 == 0 )
* V_70 = V_30 ;
error:
free ( V_85 ) ;
return V_23 ;
}
int F_29 ( int V_18 , const char * * V_19 , const char * T_3 V_4 )
{
struct V_88 V_89 ;
struct V_5 V_6 = {
. V_36 = {
. V_40 = F_18 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
. V_94 = V_95 ,
. V_96 = V_97 ,
. V_98 = V_99 ,
. V_100 = V_101 ,
. V_102 = true ,
} ,
. V_69 = L_44 ,
. V_9 = V_30 | V_33 ,
} ;
const struct V_1 V_103 [] = {
F_5 ( 't' , L_45 , & V_6 . V_9 ,
L_45 , L_46 ,
F_27 ) ,
F_8 ( 'D' , L_47 , & V_6 . V_81 ,
L_48 ) ,
F_8 ( 'U' , L_49 , & V_6 . V_47 ,
L_50 ) ,
F_30 ( 'i' , L_51 , & V_69 , L_52 ,
L_53 ) ,
F_30 ( 'C' , L_54 , & V_6 . V_75 , L_54 ,
L_55 ) ,
F_31 ( 'x' , L_56 , & V_53 . V_54 ,
L_57 ,
L_58
L_59 ) ,
F_8 ( 'f' , L_60 , & V_6 . V_72 , L_61 ) ,
F_9 ()
} ;
const char * const V_104 [] = { L_15 , L_37 , NULL } ;
const char * V_105 [] = {
NULL ,
NULL
} ;
if ( F_32 () ) {
F_11 ( L_62 ) ;
return - 1 ;
}
V_18 = F_33 ( V_18 , V_19 , V_103 , V_104 ,
V_105 , V_29 ) ;
if ( ! V_18 || ! ( strncmp ( V_19 [ 0 ] , L_63 , 3 ) || V_6 . V_9 ) )
F_34 ( V_105 , V_103 ) ;
if ( ! V_6 . V_69 || ! strlen ( V_6 . V_69 ) ) {
if ( ! F_35 ( V_106 , & V_89 ) && F_36 ( V_89 . V_107 ) )
V_6 . V_69 = L_64 ;
else
V_6 . V_69 = L_44 ;
}
if ( ! strncmp ( V_19 [ 0 ] , L_63 , 3 ) )
return F_4 ( V_18 , V_19 , & V_6 ) ;
else if ( ! strncmp ( V_19 [ 0 ] , L_65 , 3 ) )
return F_25 ( V_18 , V_19 , & V_6 ) ;
else
F_34 ( V_105 , V_103 ) ;
return 0 ;
}
