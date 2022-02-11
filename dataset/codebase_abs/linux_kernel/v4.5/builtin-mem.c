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
goto V_28;
if ( V_21 . V_29 != NULL )
V_21 . V_29 -> V_30 -> V_31 = 1 ;
if ( V_32 . V_33 ) {
V_22 = L_8 V_34 L_9 V_34 L_10 V_35
L_9 V_34 L_11 ;
} else {
V_22 = L_12 V_34 L_13 V_34
L_14 V_35 L_15 V_34 L_11 ;
V_32 . V_33 = L_16 ;
}
printf ( V_22 ,
V_18 -> V_36 ,
V_32 . V_33 ,
V_18 -> V_37 ,
V_32 . V_33 ,
V_18 -> V_38 ,
V_32 . V_33 ,
V_18 -> V_39 ,
V_32 . V_33 ,
V_18 -> V_40 ,
V_32 . V_33 ,
V_18 -> V_41 ,
V_32 . V_33 ,
V_21 . V_29 ? ( V_21 . V_29 -> V_30 ? V_21 . V_29 -> V_30 -> V_42 : L_17 ) : L_17 ,
V_21 . V_27 ? V_21 . V_27 -> V_43 : L_17 ) ;
V_28:
F_6 ( & V_21 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
union V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_44 * T_1 V_45 ,
struct V_19 * V_19 )
{
return F_3 ( V_14 , V_16 , V_18 , V_19 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_46 V_47 = {
. V_48 = V_49 ,
. V_50 = V_51 ,
. V_52 = V_4 -> V_52 ,
} ;
int V_9 ;
struct V_53 * V_54 = F_9 ( & V_47 , false ,
& V_4 -> V_14 ) ;
if ( V_54 == NULL )
return - 1 ;
if ( V_4 -> V_55 ) {
V_9 = F_10 ( V_54 , V_4 -> V_55 ,
V_4 -> V_56 ) ;
if ( V_9 < 0 )
goto V_57;
}
V_9 = F_11 ( & V_54 -> V_24 . V_58 ) ;
if ( V_9 < 0 )
goto V_57;
printf ( L_18 ) ;
V_9 = F_12 ( V_54 ) ;
V_57:
F_13 ( V_54 ) ;
return V_9 ;
}
static int F_14 ( int V_1 , const char * * V_2 , struct V_3 * V_4 )
{
const char * * V_59 ;
int V_9 , V_6 = 0 , V_7 , V_60 ;
if ( V_4 -> V_61 )
return F_8 ( V_4 ) ;
V_60 = V_1 + 3 ;
V_59 = calloc ( V_60 + 1 , sizeof( char * ) ) ;
if ( ! V_59 )
return - 1 ;
V_59 [ V_6 ++ ] = L_19 ;
V_59 [ V_6 ++ ] = L_20 ;
V_59 [ V_6 ++ ] = L_21 ;
if ( ! ( V_4 -> V_10 & V_11 ) )
V_59 [ V_6 ++ ] = L_22
L_23 ;
for ( V_7 = 1 ; V_7 < V_1 ; V_7 ++ , V_6 ++ )
V_59 [ V_6 ] = V_2 [ V_7 ] ;
V_9 = F_15 ( V_6 , V_59 , NULL ) ;
free ( V_59 ) ;
return V_9 ;
}
static int
F_16 ( const struct V_62 * V_63 , const char * V_64 , int V_65 )
{
int * V_50 = ( int * ) V_63 -> V_66 ;
const struct V_67 * V_68 ;
char * V_69 , * V_70 = NULL , * V_71 ;
int V_9 = - 1 ;
if ( V_65 )
return 0 ;
if ( V_64 ) {
V_69 = V_70 = F_17 ( V_64 ) ;
if ( ! V_69 )
return - 1 ;
* V_50 = 0 ;
for (; ; ) {
V_71 = strchr ( V_69 , ',' ) ;
if ( V_71 )
* V_71 = '\0' ;
for ( V_68 = V_72 ; V_68 -> V_43 ; V_68 ++ ) {
if ( ! strcasecmp ( V_69 , V_68 -> V_43 ) )
break;
}
if ( ! V_68 -> V_43 ) {
fprintf ( V_23 , L_24
L_25 , V_69 ) ;
goto error;
}
* V_50 |= V_68 -> V_50 ;
if ( ! V_71 )
break;
V_69 = V_71 + 1 ;
}
}
V_9 = 0 ;
if ( * V_50 == 0 )
* V_50 = V_11 ;
error:
free ( V_70 ) ;
return V_9 ;
}
int F_18 ( int V_1 , const char * * V_2 , const char * T_2 V_45 )
{
struct V_73 V_74 ;
struct V_3 V_4 = {
. V_14 = {
. V_18 = F_7 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = V_86 ,
. V_87 = true ,
} ,
. V_49 = L_26 ,
. V_10 = V_11 | V_12 ,
} ;
const struct V_62 V_88 [] = {
F_19 ( 't' , L_27 , & V_4 . V_10 ,
L_27 , L_28 ,
F_16 ) ,
F_20 ( 'D' , L_29 , & V_4 . V_61 ,
L_30 ) ,
F_20 ( 'U' , L_31 , & V_4 . V_26 ,
L_32 ) ,
F_21 ( 'i' , L_33 , & V_49 , L_34 ,
L_35 ) ,
F_21 ( 'C' , L_36 , & V_4 . V_55 , L_36 ,
L_37 ) ,
F_22 ( 'x' , L_38 , & V_32 . V_33 ,
L_39 ,
L_40
L_41 ) ,
F_20 ( 'f' , L_42 , & V_4 . V_52 , L_43 ) ,
F_23 ()
} ;
const char * const V_89 [] = { L_1 , L_19 , NULL } ;
const char * V_90 [] = {
NULL ,
NULL
} ;
V_1 = F_24 ( V_1 , V_2 , V_88 , V_89 ,
V_90 , V_91 ) ;
if ( ! V_1 || ! ( strncmp ( V_2 [ 0 ] , L_44 , 3 ) || V_4 . V_10 ) )
F_25 ( V_90 , V_88 ) ;
if ( ! V_4 . V_49 || ! strlen ( V_4 . V_49 ) ) {
if ( ! F_26 ( V_92 , & V_74 ) && F_27 ( V_74 . V_93 ) )
V_4 . V_49 = L_45 ;
else
V_4 . V_49 = L_26 ;
}
if ( ! strncmp ( V_2 [ 0 ] , L_44 , 3 ) )
return F_1 ( V_1 , V_2 , & V_4 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_46 , 3 ) )
return F_14 ( V_1 , V_2 , & V_4 ) ;
else
F_25 ( V_90 , V_88 ) ;
return 0 ;
}
