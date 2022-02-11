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
if ( V_6 -> V_35 )
V_22 [ V_21 ++ ] = L_18 ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ! V_13 [ V_8 ] . V_32 )
continue;
if ( ! V_13 [ V_8 ] . V_17 ) {
F_11 ( L_19 ,
F_3 ( V_8 ) ) ;
return - 1 ;
}
V_22 [ V_21 ++ ] = L_20 ;
V_22 [ V_21 ++ ] = F_3 ( V_8 ) ;
} ;
if ( V_24 )
V_22 [ V_21 ++ ] = L_21 ;
if ( V_25 )
V_22 [ V_21 ++ ] = L_22 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_22 [ V_21 ] = V_19 [ V_8 ] ;
if ( V_16 > 0 ) {
F_12 ( L_23 ) ;
while ( V_22 [ V_8 ] ) {
F_12 ( L_24 , V_22 [ V_8 ] ) ;
V_8 ++ ;
}
F_12 ( L_25 ) ;
}
V_23 = F_13 ( V_21 , V_22 ) ;
free ( V_22 ) ;
return V_23 ;
}
static int
F_14 ( struct V_36 * V_37 ,
union V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_42 * V_42 )
{
struct V_5 * V_6 = F_15 ( V_37 , struct V_5 , V_37 ) ;
struct V_43 V_44 ;
const char * V_45 ;
if ( F_16 ( V_42 , & V_44 , V_41 ) < 0 ) {
fprintf ( V_14 , L_26 ,
V_39 -> V_46 . type ) ;
return - 1 ;
}
if ( V_44 . V_47 || ( V_6 -> V_48 && V_44 . V_49 == NULL ) )
goto V_50;
if ( V_44 . V_51 != NULL )
V_44 . V_51 -> V_52 -> V_53 = 1 ;
if ( V_6 -> V_35 ) {
if ( V_54 . V_55 ) {
V_45 = L_27 V_56 L_28 V_56 L_29 V_56
L_30 V_57 L_28 V_56 L_31 ;
} else {
V_45 = L_32 V_56 L_33 V_56
L_29 V_56 L_34 V_57 L_35 V_56
L_31 ;
V_54 . V_55 = L_36 ;
}
printf ( V_45 ,
V_41 -> V_58 ,
V_54 . V_55 ,
V_41 -> V_59 ,
V_54 . V_55 ,
V_41 -> V_60 ,
V_54 . V_55 ,
V_41 -> V_61 ,
V_54 . V_55 ,
V_41 -> V_35 ,
V_54 . V_55 ,
V_41 -> V_62 ,
V_54 . V_55 ,
V_41 -> V_63 ,
V_54 . V_55 ,
V_44 . V_51 ? ( V_44 . V_51 -> V_52 ? V_44 . V_51 -> V_52 -> V_64 : L_37 ) : L_37 ,
V_44 . V_49 ? V_44 . V_49 -> V_65 : L_37 ) ;
} else {
if ( V_54 . V_55 ) {
V_45 = L_27 V_56 L_28 V_56 L_30 V_57
L_28 V_56 L_31 ;
} else {
V_45 = L_32 V_56 L_33 V_56
L_34 V_57 L_35 V_56 L_31 ;
V_54 . V_55 = L_36 ;
}
printf ( V_45 ,
V_41 -> V_58 ,
V_54 . V_55 ,
V_41 -> V_59 ,
V_54 . V_55 ,
V_41 -> V_60 ,
V_54 . V_55 ,
V_41 -> V_61 ,
V_54 . V_55 ,
V_41 -> V_62 ,
V_54 . V_55 ,
V_41 -> V_63 ,
V_54 . V_55 ,
V_44 . V_51 ? ( V_44 . V_51 -> V_52 ? V_44 . V_51 -> V_52 -> V_64 : L_37 ) : L_37 ,
V_44 . V_49 ? V_44 . V_49 -> V_65 : L_37 ) ;
}
V_50:
F_17 ( & V_44 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_37 ,
union V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_66 * T_2 V_4 ,
struct V_42 * V_42 )
{
return F_14 ( V_37 , V_39 , V_41 , V_42 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_67 V_68 = {
. V_69 = V_70 ,
. V_71 = V_72 ,
. V_73 = V_6 -> V_73 ,
} ;
int V_23 ;
struct V_74 * V_75 = F_20 ( & V_68 , false ,
& V_6 -> V_37 ) ;
if ( V_75 == NULL )
return - 1 ;
if ( V_6 -> V_76 ) {
V_23 = F_21 ( V_75 , V_6 -> V_76 ,
V_6 -> V_77 ) ;
if ( V_23 < 0 )
goto V_78;
}
V_23 = F_22 ( & V_75 -> V_46 . V_79 ) ;
if ( V_23 < 0 )
goto V_78;
if ( V_6 -> V_35 )
printf ( L_38 ) ;
else
printf ( L_39 ) ;
V_23 = F_23 ( V_75 ) ;
V_78:
F_24 ( V_75 ) ;
return V_23 ;
}
static int F_25 ( int V_18 , const char * * V_19 , struct V_5 * V_6 )
{
const char * * V_80 ;
int V_23 , V_21 = 0 , V_8 , V_81 ;
if ( V_6 -> V_82 )
return F_19 ( V_6 ) ;
V_81 = V_18 + 3 ;
V_80 = calloc ( V_81 + 1 , sizeof( char * ) ) ;
if ( ! V_80 )
return - 1 ;
V_80 [ V_21 ++ ] = L_40 ;
V_80 [ V_21 ++ ] = L_41 ;
V_80 [ V_21 ++ ] = L_42 ;
if ( ! ( V_6 -> V_9 & V_30 ) ) {
if ( V_6 -> V_35 )
V_80 [ V_21 ++ ] = L_43
L_44 ;
else
V_80 [ V_21 ++ ] = L_43
L_45 ;
} else if ( V_6 -> V_35 )
V_80 [ V_21 ++ ] = L_46
L_47 ;
for ( V_8 = 1 ; V_8 < V_18 ; V_8 ++ , V_21 ++ )
V_80 [ V_21 ] = V_19 [ V_8 ] ;
V_23 = F_26 ( V_21 , V_80 ) ;
free ( V_80 ) ;
return V_23 ;
}
static int
F_27 ( const struct V_1 * V_2 , const char * V_3 , int T_1 )
{
int * V_71 = ( int * ) V_2 -> V_7 ;
const struct V_83 * V_84 ;
char * V_85 , * V_86 = NULL , * V_87 ;
int V_23 = - 1 ;
if ( T_1 )
return 0 ;
if ( V_3 ) {
V_85 = V_86 = F_28 ( V_3 ) ;
if ( ! V_85 )
return - 1 ;
* V_71 = 0 ;
for (; ; ) {
V_87 = strchr ( V_85 , ',' ) ;
if ( V_87 )
* V_87 = '\0' ;
for ( V_84 = V_88 ; V_84 -> V_65 ; V_84 ++ ) {
if ( ! strcasecmp ( V_85 , V_84 -> V_65 ) )
break;
}
if ( ! V_84 -> V_65 ) {
fprintf ( V_14 , L_48
L_49 , V_85 ) ;
goto error;
}
* V_71 |= V_84 -> V_71 ;
if ( ! V_87 )
break;
V_85 = V_87 + 1 ;
}
}
V_23 = 0 ;
if ( * V_71 == 0 )
* V_71 = V_30 ;
error:
free ( V_86 ) ;
return V_23 ;
}
int F_29 ( int V_18 , const char * * V_19 )
{
struct V_89 V_90 ;
struct V_5 V_6 = {
. V_37 = {
. V_41 = F_18 ,
. V_91 = V_92 ,
. V_93 = V_94 ,
. V_95 = V_96 ,
. V_97 = V_98 ,
. V_99 = V_100 ,
. V_101 = V_102 ,
. V_103 = V_104 ,
. V_105 = true ,
} ,
. V_70 = L_50 ,
. V_9 = V_30 | V_33 ,
} ;
const struct V_1 V_106 [] = {
F_5 ( 't' , L_51 , & V_6 . V_9 ,
L_51 , L_52 ,
F_27 ) ,
F_8 ( 'D' , L_53 , & V_6 . V_82 ,
L_54 ) ,
F_8 ( 'U' , L_55 , & V_6 . V_48 ,
L_56 ) ,
F_30 ( 'i' , L_57 , & V_70 , L_58 ,
L_59 ) ,
F_30 ( 'C' , L_60 , & V_6 . V_76 , L_60 ,
L_61 ) ,
F_31 ( 'x' , L_62 , & V_54 . V_55 ,
L_63 ,
L_64
L_65 ) ,
F_8 ( 'f' , L_66 , & V_6 . V_73 , L_67 ) ,
F_8 ( 'p' , L_68 , & V_6 . V_35 , L_69 ) ,
F_9 ()
} ;
const char * const V_107 [] = { L_15 , L_40 , NULL } ;
const char * V_108 [] = {
NULL ,
NULL
} ;
if ( F_32 () ) {
F_11 ( L_70 ) ;
return - 1 ;
}
V_18 = F_33 ( V_18 , V_19 , V_106 , V_107 ,
V_108 , V_29 ) ;
if ( ! V_18 || ! ( strncmp ( V_19 [ 0 ] , L_71 , 3 ) || V_6 . V_9 ) )
F_34 ( V_108 , V_106 ) ;
if ( ! V_6 . V_70 || ! strlen ( V_6 . V_70 ) ) {
if ( ! F_35 ( V_109 , & V_90 ) && F_36 ( V_90 . V_110 ) )
V_6 . V_70 = L_72 ;
else
V_6 . V_70 = L_50 ;
}
if ( ! strncmp ( V_19 [ 0 ] , L_71 , 3 ) )
return F_4 ( V_18 , V_19 , & V_6 ) ;
else if ( ! strncmp ( V_19 [ 0 ] , L_73 , 3 ) )
return F_25 ( V_18 , V_19 , & V_6 ) ;
else
F_34 ( V_108 , V_106 ) ;
return 0 ;
}
