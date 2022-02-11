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
bool V_24 = false , V_25 = false ;
struct V_1 V_26 [] = {
F_5 ( 'e' , L_5 , & V_6 , L_5 ,
L_6 ,
F_1 ) ,
F_6 ( 'v' , L_7 , & V_16 ,
L_8 ) ,
F_7 ( 'U' , L_9 , & V_24 , L_10 ) ,
F_7 ( 'K' , L_11 , & V_25 , L_12 ) ,
F_8 ()
} ;
V_18 = F_9 ( V_18 , V_19 , V_26 , V_27 ,
V_28 ) ;
V_20 = V_18 + 9 ;
V_22 = calloc ( V_20 + 1 , sizeof( char * ) ) ;
if ( ! V_22 )
return - 1 ;
V_22 [ V_21 ++ ] = L_13 ;
if ( V_6 -> V_9 & V_29 )
V_13 [ V_30 ] . V_31 = true ;
if ( V_13 [ V_30 ] . V_31 )
V_22 [ V_21 ++ ] = L_14 ;
V_22 [ V_21 ++ ] = L_15 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ! V_13 [ V_8 ] . V_31 )
continue;
if ( ! V_13 [ V_8 ] . V_17 ) {
F_10 ( L_16 ,
F_3 ( V_8 ) ) ;
return - 1 ;
}
V_22 [ V_21 ++ ] = L_17 ;
V_22 [ V_21 ++ ] = F_3 ( V_8 ) ;
} ;
if ( V_24 )
V_22 [ V_21 ++ ] = L_9 ;
if ( V_25 )
V_22 [ V_21 ++ ] = L_11 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_22 [ V_21 ] = V_19 [ V_8 ] ;
if ( V_16 > 0 ) {
F_11 ( L_18 ) ;
while ( V_22 [ V_8 ] ) {
F_11 ( L_19 , V_22 [ V_8 ] ) ;
V_8 ++ ;
}
F_11 ( L_20 ) ;
}
V_23 = F_12 ( V_21 , V_22 , NULL ) ;
free ( V_22 ) ;
return V_23 ;
}
static int
F_13 ( struct V_32 * V_33 ,
union V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_38 )
{
struct V_5 * V_6 = F_14 ( V_33 , struct V_5 , V_33 ) ;
struct V_39 V_40 ;
const char * V_41 ;
if ( F_15 ( V_38 , & V_40 , V_37 ) < 0 ) {
fprintf ( V_14 , L_21 ,
V_35 -> V_42 . type ) ;
return - 1 ;
}
if ( V_40 . V_43 || ( V_6 -> V_44 && V_40 . V_45 == NULL ) )
goto V_46;
if ( V_40 . V_47 != NULL )
V_40 . V_47 -> V_48 -> V_49 = 1 ;
if ( V_50 . V_51 ) {
V_41 = L_22 V_52 L_23 V_52 L_24 V_53
L_23 V_52 L_25 ;
} else {
V_41 = L_26 V_52 L_27 V_52
L_28 V_53 L_29 V_52 L_25 ;
V_50 . V_51 = L_30 ;
}
printf ( V_41 ,
V_37 -> V_54 ,
V_50 . V_51 ,
V_37 -> V_55 ,
V_50 . V_51 ,
V_37 -> V_56 ,
V_50 . V_51 ,
V_37 -> V_57 ,
V_50 . V_51 ,
V_37 -> V_58 ,
V_50 . V_51 ,
V_37 -> V_59 ,
V_50 . V_51 ,
V_40 . V_47 ? ( V_40 . V_47 -> V_48 ? V_40 . V_47 -> V_48 -> V_60 : L_31 ) : L_31 ,
V_40 . V_45 ? V_40 . V_45 -> V_61 : L_31 ) ;
V_46:
F_16 ( & V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 ,
union V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_62 * T_2 V_4 ,
struct V_38 * V_38 )
{
return F_13 ( V_33 , V_35 , V_37 , V_38 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_63 V_64 = {
. V_65 = V_66 ,
. V_67 = V_68 ,
. V_69 = V_6 -> V_69 ,
} ;
int V_23 ;
struct V_70 * V_71 = F_19 ( & V_64 , false ,
& V_6 -> V_33 ) ;
if ( V_71 == NULL )
return - 1 ;
if ( V_6 -> V_72 ) {
V_23 = F_20 ( V_71 , V_6 -> V_72 ,
V_6 -> V_73 ) ;
if ( V_23 < 0 )
goto V_74;
}
V_23 = F_21 ( & V_71 -> V_42 . V_75 ) ;
if ( V_23 < 0 )
goto V_74;
printf ( L_32 ) ;
V_23 = F_22 ( V_71 ) ;
V_74:
F_23 ( V_71 ) ;
return V_23 ;
}
static int F_24 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
const char * * V_76 ;
int V_23 , V_21 = 0 , V_8 , V_77 ;
if ( V_6 -> V_78 )
return F_18 ( V_6 ) ;
V_77 = V_18 + 3 ;
V_76 = calloc ( V_77 + 1 , sizeof( char * ) ) ;
if ( ! V_76 )
return - 1 ;
V_76 [ V_21 ++ ] = L_33 ;
V_76 [ V_21 ++ ] = L_34 ;
V_76 [ V_21 ++ ] = L_35 ;
if ( ! ( V_6 -> V_9 & V_29 ) )
V_76 [ V_21 ++ ] = L_36
L_37 ;
for ( V_8 = 1 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_76 [ V_21 ] = V_19 [ V_8 ] ;
V_23 = F_25 ( V_21 , V_76 , NULL ) ;
free ( V_76 ) ;
return V_23 ;
}
static int
F_26 ( const struct V_1 * V_2 , const char * V_3 , int T_1 )
{
int * V_67 = ( int * ) V_2 -> V_7 ;
const struct V_79 * V_80 ;
char * V_81 , * V_82 = NULL , * V_83 ;
int V_23 = - 1 ;
if ( T_1 )
return 0 ;
if ( V_3 ) {
V_81 = V_82 = F_27 ( V_3 ) ;
if ( ! V_81 )
return - 1 ;
* V_67 = 0 ;
for (; ; ) {
V_83 = strchr ( V_81 , ',' ) ;
if ( V_83 )
* V_83 = '\0' ;
for ( V_80 = V_84 ; V_80 -> V_61 ; V_80 ++ ) {
if ( ! strcasecmp ( V_81 , V_80 -> V_61 ) )
break;
}
if ( ! V_80 -> V_61 ) {
fprintf ( V_14 , L_38
L_39 , V_81 ) ;
goto error;
}
* V_67 |= V_80 -> V_67 ;
if ( ! V_83 )
break;
V_81 = V_83 + 1 ;
}
}
V_23 = 0 ;
if ( * V_67 == 0 )
* V_67 = V_29 ;
error:
free ( V_82 ) ;
return V_23 ;
}
int F_28 ( int V_18 , const char * * V_19 , const char * T_3 V_4 )
{
struct V_85 V_86 ;
struct V_5 V_6 = {
. V_33 = {
. V_37 = F_17 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
. V_91 = V_92 ,
. V_93 = V_94 ,
. V_95 = V_96 ,
. V_97 = V_98 ,
. V_99 = true ,
} ,
. V_66 = L_40 ,
. V_9 = V_29 | V_100 ,
} ;
const struct V_1 V_101 [] = {
F_5 ( 't' , L_41 , & V_6 . V_9 ,
L_41 , L_42 ,
F_26 ) ,
F_7 ( 'D' , L_43 , & V_6 . V_78 ,
L_44 ) ,
F_7 ( 'U' , L_45 , & V_6 . V_44 ,
L_46 ) ,
F_29 ( 'i' , L_47 , & V_66 , L_48 ,
L_49 ) ,
F_29 ( 'C' , L_50 , & V_6 . V_72 , L_50 ,
L_51 ) ,
F_30 ( 'x' , L_52 , & V_50 . V_51 ,
L_53 ,
L_54
L_55 ) ,
F_7 ( 'f' , L_56 , & V_6 . V_69 , L_57 ) ,
F_8 ()
} ;
const char * const V_102 [] = { L_13 , L_33 , NULL } ;
const char * V_103 [] = {
NULL ,
NULL
} ;
if ( F_31 () ) {
F_10 ( L_58 ) ;
return - 1 ;
}
V_18 = F_32 ( V_18 , V_19 , V_101 , V_102 ,
V_103 , V_28 ) ;
if ( ! V_18 || ! ( strncmp ( V_19 [ 0 ] , L_59 , 3 ) || V_6 . V_9 ) )
F_33 ( V_103 , V_101 ) ;
if ( ! V_6 . V_66 || ! strlen ( V_6 . V_66 ) ) {
if ( ! F_34 ( V_104 , & V_86 ) && F_35 ( V_86 . V_105 ) )
V_6 . V_66 = L_60 ;
else
V_6 . V_66 = L_40 ;
}
if ( ! strncmp ( V_19 [ 0 ] , L_59 , 3 ) )
return F_4 ( V_18 , V_19 , & V_6 ) ;
else if ( ! strncmp ( V_19 [ 0 ] , L_61 , 3 ) )
return F_24 ( V_18 , V_19 , & V_6 ) ;
else
F_33 ( V_103 , V_101 ) ;
return 0 ;
}
