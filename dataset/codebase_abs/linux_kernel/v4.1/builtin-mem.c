static int F_1 ( int V_1 , const char * * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 = 0 , V_7 ;
const char * * V_8 ;
int V_9 ;
V_5 = V_1 + 7 ;
V_8 = calloc ( V_5 + 1 , sizeof( char * ) ) ;
if ( ! V_8 )
return - 1 ;
V_8 [ V_6 ++ ] = L_1 ;
if ( V_4 -> V_10 & V_11 )
V_8 [ V_6 ++ ] = L_2 ;
V_8 [ V_6 ++ ] = L_3 ;
if ( V_4 -> V_10 & V_11 ) {
V_8 [ V_6 ++ ] = L_4 ;
V_8 [ V_6 ++ ] = L_5 ;
}
if ( V_4 -> V_10 & V_12 ) {
V_8 [ V_6 ++ ] = L_4 ;
V_8 [ V_6 ++ ] = L_6 ;
}
for ( V_7 = 1 ; V_7 < V_1 ; V_7 ++ , V_6 ++ )
V_8 [ V_6 ] = V_2 [ V_7 ] ;
V_9 = F_2 ( V_6 , V_8 , NULL ) ;
free ( V_8 ) ;
return V_9 ;
}
static int
F_3 ( struct V_13 * V_14 ,
union V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_19 )
{
struct V_3 * V_4 = F_4 ( V_14 , struct V_3 , V_14 ) ;
struct V_20 V_21 ;
const char * V_22 ;
if ( F_5 ( V_16 , V_19 , & V_21 , V_18 ) < 0 ) {
fprintf ( V_23 , L_7 ,
V_16 -> V_24 . type ) ;
return - 1 ;
}
if ( V_21 . V_25 || ( V_4 -> V_26 && V_21 . V_27 == NULL ) )
return 0 ;
if ( V_21 . V_28 != NULL )
V_21 . V_28 -> V_29 -> V_30 = 1 ;
if ( V_31 . V_32 ) {
V_22 = L_8 V_33 L_9 V_33 L_10 V_34
L_9 V_33 L_11 ;
} else {
V_22 = L_12 V_33 L_13 V_33
L_14 V_34 L_15 V_33 L_11 ;
V_31 . V_32 = L_16 ;
}
printf ( V_22 ,
V_18 -> V_35 ,
V_31 . V_32 ,
V_18 -> V_36 ,
V_31 . V_32 ,
V_18 -> V_37 ,
V_31 . V_32 ,
V_18 -> V_38 ,
V_31 . V_32 ,
V_18 -> V_39 ,
V_31 . V_32 ,
V_18 -> V_40 ,
V_31 . V_32 ,
V_21 . V_28 ? ( V_21 . V_28 -> V_29 ? V_21 . V_28 -> V_29 -> V_41 : L_17 ) : L_17 ,
V_21 . V_27 ? V_21 . V_27 -> V_42 : L_17 ) ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 ,
union V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_43 * T_1 V_44 ,
struct V_19 * V_19 )
{
return F_3 ( V_14 , V_16 , V_18 , V_19 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_45 V_46 = {
. V_47 = V_48 ,
. V_49 = V_50 ,
. V_51 = V_4 -> V_51 ,
} ;
int V_52 = - V_53 ;
int V_9 ;
struct V_54 * V_55 = F_8 ( & V_46 , false ,
& V_4 -> V_14 ) ;
if ( V_55 == NULL )
return - 1 ;
if ( V_4 -> V_56 ) {
V_9 = F_9 ( V_55 , V_4 -> V_56 ,
V_4 -> V_57 ) ;
if ( V_9 )
goto V_58;
}
if ( F_10 ( & V_55 -> V_24 . V_59 ) < 0 )
return - 1 ;
printf ( L_18 ) ;
V_52 = F_11 ( V_55 ) ;
if ( V_52 )
return V_52 ;
return 0 ;
V_58:
F_12 ( V_55 ) ;
return V_52 ;
}
static int F_13 ( int V_1 , const char * * V_2 , struct V_3 * V_4 )
{
const char * * V_60 ;
int V_9 , V_6 = 0 , V_7 , V_61 ;
if ( V_4 -> V_62 )
return F_7 ( V_4 ) ;
V_61 = V_1 + 3 ;
V_60 = calloc ( V_61 + 1 , sizeof( char * ) ) ;
if ( ! V_60 )
return - 1 ;
V_60 [ V_6 ++ ] = L_19 ;
V_60 [ V_6 ++ ] = L_20 ;
V_60 [ V_6 ++ ] = L_21 ;
if ( ! ( V_4 -> V_10 & V_11 ) )
V_60 [ V_6 ++ ] = L_22
L_23 ;
for ( V_7 = 1 ; V_7 < V_1 ; V_7 ++ , V_6 ++ )
V_60 [ V_6 ] = V_2 [ V_7 ] ;
V_9 = F_14 ( V_6 , V_60 , NULL ) ;
free ( V_60 ) ;
return V_9 ;
}
static int
F_15 ( const struct V_63 * V_64 , const char * V_65 , int V_66 )
{
int * V_49 = ( int * ) V_64 -> V_67 ;
const struct V_68 * V_69 ;
char * V_70 , * V_71 = NULL , * V_72 ;
int V_9 = - 1 ;
if ( V_66 )
return 0 ;
if ( V_65 ) {
V_70 = V_71 = F_16 ( V_65 ) ;
if ( ! V_70 )
return - 1 ;
* V_49 = 0 ;
for (; ; ) {
V_72 = strchr ( V_70 , ',' ) ;
if ( V_72 )
* V_72 = '\0' ;
for ( V_69 = V_73 ; V_69 -> V_42 ; V_69 ++ ) {
if ( ! strcasecmp ( V_70 , V_69 -> V_42 ) )
break;
}
if ( ! V_69 -> V_42 ) {
fprintf ( V_23 , L_24
L_25 , V_70 ) ;
goto error;
}
* V_49 |= V_69 -> V_49 ;
if ( ! V_72 )
break;
V_70 = V_72 + 1 ;
}
}
V_9 = 0 ;
if ( * V_49 == 0 )
* V_49 = V_11 ;
error:
free ( V_71 ) ;
return V_9 ;
}
int F_17 ( int V_1 , const char * * V_2 , const char * T_2 V_44 )
{
struct V_74 V_75 ;
struct V_3 V_4 = {
. V_14 = {
. V_18 = F_6 ,
. V_76 = V_77 ,
. V_78 = V_79 ,
. V_80 = V_81 ,
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = true ,
} ,
. V_48 = L_26 ,
. V_10 = V_11 | V_12 ,
} ;
const struct V_63 V_89 [] = {
F_18 ( 't' , L_27 , & V_4 . V_10 ,
L_27 , L_28 ,
F_15 ) ,
F_19 ( 'D' , L_29 , & V_4 . V_62 ,
L_30 ) ,
F_19 ( 'U' , L_31 , & V_4 . V_26 ,
L_32 ) ,
F_20 ( 'i' , L_33 , & V_48 , L_34 ,
L_35 ) ,
F_20 ( 'C' , L_36 , & V_4 . V_56 , L_36 ,
L_37 ) ,
F_21 ( 'x' , L_38 , & V_31 . V_32 ,
L_39 ,
L_40
L_41 ) ,
F_19 ( 'f' , L_42 , & V_4 . V_51 , L_43 ) ,
F_22 ()
} ;
const char * const V_90 [] = { L_1 , L_19 , NULL } ;
const char * V_91 [] = {
NULL ,
NULL
} ;
V_1 = F_23 ( V_1 , V_2 , V_89 , V_90 ,
V_91 , V_92 ) ;
if ( ! V_1 || ! ( strncmp ( V_2 [ 0 ] , L_44 , 3 ) || V_4 . V_10 ) )
F_24 ( V_91 , V_89 ) ;
if ( ! V_4 . V_48 || ! strlen ( V_4 . V_48 ) ) {
if ( ! F_25 ( V_93 , & V_75 ) && F_26 ( V_75 . V_94 ) )
V_4 . V_48 = L_45 ;
else
V_4 . V_48 = L_26 ;
}
if ( ! strncmp ( V_2 [ 0 ] , L_44 , 3 ) )
return F_1 ( V_1 , V_2 , & V_4 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_46 , 3 ) )
return F_13 ( V_1 , V_2 , & V_4 ) ;
else
F_24 ( V_91 , V_89 ) ;
return 0 ;
}
