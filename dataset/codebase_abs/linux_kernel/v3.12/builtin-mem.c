static int F_1 ( int V_1 , const char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 ;
const char * * V_6 ;
char V_7 [ 64 ] ;
int V_8 ;
V_3 = V_1 + 4 ;
V_6 = calloc ( V_3 + 1 , sizeof( char * ) ) ;
if ( ! V_6 )
return - 1 ;
V_6 [ V_4 ++ ] = F_2 ( L_1 ) ;
if ( ! strcmp ( V_9 , V_10 ) )
V_6 [ V_4 ++ ] = F_2 ( L_2 ) ;
V_6 [ V_4 ++ ] = F_2 ( L_3 ) ;
V_6 [ V_4 ++ ] = F_2 ( L_4 ) ;
if ( strcmp ( V_9 , V_10 ) )
sprintf ( V_7 , L_5 ) ;
else
sprintf ( V_7 , L_6 ) ;
V_6 [ V_4 ++ ] = F_2 ( V_7 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_6 [ V_4 ] = V_2 [ V_5 ] ;
V_8 = F_3 ( V_4 , V_6 , NULL ) ;
free ( V_6 ) ;
return V_8 ;
}
static int
F_4 ( struct V_11 * V_12 ,
union V_13 * V_7 ,
struct V_14 * V_15 ,
struct V_16 * T_1 V_17 ,
struct V_18 * V_18 )
{
struct V_19 * V_20 = F_5 ( V_12 , struct V_19 , V_12 ) ;
struct V_21 V_22 ;
const char * V_23 ;
if ( F_6 ( V_7 , V_18 , & V_22 , V_15 ) < 0 ) {
fprintf ( V_24 , L_7 ,
V_7 -> V_25 . type ) ;
return - 1 ;
}
if ( V_22 . V_26 || ( V_20 -> V_27 && V_22 . V_28 == NULL ) )
return 0 ;
if ( V_22 . V_29 != NULL )
V_22 . V_29 -> V_30 -> V_31 = 1 ;
if ( V_32 . V_33 ) {
V_23 = L_8 V_34 L_9 V_34 L_10 V_35
L_9 V_34 L_11 ;
} else {
V_23 = L_12 V_34 L_13 V_34
L_14 V_35 L_15 V_34 L_11 ;
V_32 . V_33 = L_16 ;
}
printf ( V_23 ,
V_15 -> V_36 ,
V_32 . V_33 ,
V_15 -> V_37 ,
V_32 . V_33 ,
V_15 -> V_38 ,
V_32 . V_33 ,
V_15 -> V_39 ,
V_32 . V_33 ,
V_15 -> V_40 ,
V_32 . V_33 ,
V_15 -> V_41 ,
V_32 . V_33 ,
V_22 . V_29 ? ( V_22 . V_29 -> V_30 ? V_22 . V_29 -> V_30 -> V_42 : L_17 ) : L_17 ,
V_22 . V_28 ? V_22 . V_28 -> V_43 : L_17 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
union V_13 * V_7 ,
struct V_14 * V_15 ,
struct V_16 * T_1 ,
struct V_18 * V_18 )
{
return F_4 ( V_12 , V_7 , V_15 , T_1 , V_18 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
int V_44 = - V_45 ;
int V_8 ;
struct V_46 * V_47 = F_9 ( V_48 , V_49 ,
0 , false , & V_20 -> V_12 ) ;
if ( V_47 == NULL )
return - V_50 ;
if ( V_20 -> V_51 ) {
V_8 = F_10 ( V_47 , V_20 -> V_51 ,
V_20 -> V_52 ) ;
if ( V_8 )
goto V_53;
}
if ( F_11 () < 0 )
return - 1 ;
printf ( L_18 ) ;
V_44 = F_12 ( V_47 , & V_20 -> V_12 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
V_53:
F_13 ( V_47 ) ;
return V_44 ;
}
static int F_14 ( int V_1 , const char * * V_2 , struct V_19 * V_20 )
{
const char * * V_54 ;
int V_8 , V_4 = 0 , V_5 , V_55 ;
if ( V_20 -> V_56 )
return F_8 ( V_20 ) ;
V_55 = V_1 + 3 ;
V_54 = calloc ( V_55 + 1 , sizeof( char * ) ) ;
if ( ! V_54 )
return - 1 ;
V_54 [ V_4 ++ ] = F_2 ( L_19 ) ;
V_54 [ V_4 ++ ] = F_2 ( L_20 ) ;
V_54 [ V_4 ++ ] = F_2 ( L_21 ) ;
if ( strcmp ( V_9 , V_10 ) )
V_54 [ V_4 ++ ] = F_2 ( L_22
L_23 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_54 [ V_4 ] = V_2 [ V_5 ] ;
V_8 = F_15 ( V_4 , V_54 , NULL ) ;
free ( V_54 ) ;
return V_8 ;
}
int F_16 ( int V_1 , const char * * V_2 , const char * T_2 V_17 )
{
struct V_57 V_58 ;
struct V_19 V_20 = {
. V_12 = {
. V_15 = F_7 ,
. V_59 = V_60 ,
. V_61 = V_62 ,
. V_63 = V_64 ,
. V_65 = V_66 ,
. V_67 = V_68 ,
. V_69 = V_70 ,
. V_71 = true ,
} ,
. V_48 = L_24 ,
} ;
const struct V_72 V_73 [] = {
F_17 ( 't' , L_25 , & V_9 ,
L_25 , L_26 ) ,
F_18 ( 'D' , L_27 , & V_20 . V_56 ,
L_28 ) ,
F_18 ( 'U' , L_29 , & V_20 . V_27 ,
L_30 ) ,
F_17 ( 'i' , L_31 , & V_48 , L_32 ,
L_33 ) ,
F_17 ( 'C' , L_34 , & V_20 . V_51 , L_34 ,
L_35 ) ,
F_17 ( 'x' , L_36 , & V_32 . V_33 ,
L_37 ,
L_38
L_39 ) ,
F_19 ()
} ;
V_1 = F_20 ( V_1 , V_2 , V_73 , V_74 ,
V_75 ) ;
if ( ! V_1 || ! ( strncmp ( V_2 [ 0 ] , L_40 , 3 ) || V_9 ) )
F_21 ( V_74 , V_73 ) ;
if ( ! V_20 . V_48 || ! strlen ( V_20 . V_48 ) ) {
if ( ! F_22 ( V_76 , & V_58 ) && F_23 ( V_58 . V_77 ) )
V_20 . V_48 = L_41 ;
else
V_20 . V_48 = L_24 ;
}
if ( ! strncmp ( V_2 [ 0 ] , L_40 , 3 ) )
return F_1 ( V_1 , V_2 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_42 , 3 ) )
return F_14 ( V_1 , V_2 , & V_20 ) ;
else
F_21 ( V_74 , V_73 ) ;
return 0 ;
}
