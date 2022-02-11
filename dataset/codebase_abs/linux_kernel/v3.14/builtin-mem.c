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
struct V_16 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_12 , struct V_17 , V_12 ) ;
struct V_19 V_20 ;
const char * V_21 ;
if ( F_6 ( V_7 , V_16 , & V_20 , V_15 ) < 0 ) {
fprintf ( V_22 , L_7 ,
V_7 -> V_23 . type ) ;
return - 1 ;
}
if ( V_20 . V_24 || ( V_18 -> V_25 && V_20 . V_26 == NULL ) )
return 0 ;
if ( V_20 . V_27 != NULL )
V_20 . V_27 -> V_28 -> V_29 = 1 ;
if ( V_30 . V_31 ) {
V_21 = L_8 V_32 L_9 V_32 L_10 V_33
L_9 V_32 L_11 ;
} else {
V_21 = L_12 V_32 L_13 V_32
L_14 V_33 L_15 V_32 L_11 ;
V_30 . V_31 = L_16 ;
}
printf ( V_21 ,
V_15 -> V_34 ,
V_30 . V_31 ,
V_15 -> V_35 ,
V_30 . V_31 ,
V_15 -> V_36 ,
V_30 . V_31 ,
V_15 -> V_37 ,
V_30 . V_31 ,
V_15 -> V_38 ,
V_30 . V_31 ,
V_15 -> V_39 ,
V_30 . V_31 ,
V_20 . V_27 ? ( V_20 . V_27 -> V_28 ? V_20 . V_27 -> V_28 -> V_40 : L_17 ) : L_17 ,
V_20 . V_26 ? V_20 . V_26 -> V_41 : L_17 ) ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
union V_13 * V_7 ,
struct V_14 * V_15 ,
struct V_42 * T_1 V_43 ,
struct V_16 * V_16 )
{
return F_4 ( V_12 , V_7 , V_15 , V_16 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_44 V_45 = {
. V_46 = V_47 ,
. V_48 = V_49 ,
} ;
int V_50 = - V_51 ;
int V_8 ;
struct V_52 * V_53 = F_9 ( & V_45 , false ,
& V_18 -> V_12 ) ;
if ( V_53 == NULL )
return - V_54 ;
if ( V_18 -> V_55 ) {
V_8 = F_10 ( V_53 , V_18 -> V_55 ,
V_18 -> V_56 ) ;
if ( V_8 )
goto V_57;
}
if ( F_11 () < 0 )
return - 1 ;
printf ( L_18 ) ;
V_50 = F_12 ( V_53 , & V_18 -> V_12 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
V_57:
F_13 ( V_53 ) ;
return V_50 ;
}
static int F_14 ( int V_1 , const char * * V_2 , struct V_17 * V_18 )
{
const char * * V_58 ;
int V_8 , V_4 = 0 , V_5 , V_59 ;
if ( V_18 -> V_60 )
return F_8 ( V_18 ) ;
V_59 = V_1 + 3 ;
V_58 = calloc ( V_59 + 1 , sizeof( char * ) ) ;
if ( ! V_58 )
return - 1 ;
V_58 [ V_4 ++ ] = F_2 ( L_19 ) ;
V_58 [ V_4 ++ ] = F_2 ( L_20 ) ;
V_58 [ V_4 ++ ] = F_2 ( L_21 ) ;
if ( strcmp ( V_9 , V_10 ) )
V_58 [ V_4 ++ ] = F_2 ( L_22
L_23 ) ;
for ( V_5 = 1 ; V_5 < V_1 ; V_5 ++ , V_4 ++ )
V_58 [ V_4 ] = V_2 [ V_5 ] ;
V_8 = F_15 ( V_4 , V_58 , NULL ) ;
free ( V_58 ) ;
return V_8 ;
}
int F_16 ( int V_1 , const char * * V_2 , const char * T_2 V_43 )
{
struct V_61 V_62 ;
struct V_17 V_18 = {
. V_12 = {
. V_15 = F_7 ,
. V_63 = V_64 ,
. V_65 = V_66 ,
. V_67 = V_68 ,
. V_69 = V_70 ,
. V_71 = V_72 ,
. V_73 = V_74 ,
. V_75 = true ,
} ,
. V_47 = L_24 ,
} ;
const struct V_76 V_77 [] = {
F_17 ( 't' , L_25 , & V_9 ,
L_25 , L_26 ) ,
F_18 ( 'D' , L_27 , & V_18 . V_60 ,
L_28 ) ,
F_18 ( 'U' , L_29 , & V_18 . V_25 ,
L_30 ) ,
F_17 ( 'i' , L_31 , & V_47 , L_32 ,
L_33 ) ,
F_17 ( 'C' , L_34 , & V_18 . V_55 , L_34 ,
L_35 ) ,
F_17 ( 'x' , L_36 , & V_30 . V_31 ,
L_37 ,
L_38
L_39 ) ,
F_19 ()
} ;
V_1 = F_20 ( V_1 , V_2 , V_77 , V_78 ,
V_79 ) ;
if ( ! V_1 || ! ( strncmp ( V_2 [ 0 ] , L_40 , 3 ) || V_9 ) )
F_21 ( V_78 , V_77 ) ;
if ( ! V_18 . V_47 || ! strlen ( V_18 . V_47 ) ) {
if ( ! F_22 ( V_80 , & V_62 ) && F_23 ( V_62 . V_81 ) )
V_18 . V_47 = L_41 ;
else
V_18 . V_47 = L_24 ;
}
if ( ! strncmp ( V_2 [ 0 ] , L_40 , 3 ) )
return F_1 ( V_1 , V_2 ) ;
else if ( ! strncmp ( V_2 [ 0 ] , L_42 , 3 ) )
return F_14 ( V_1 , V_2 , & V_18 ) ;
else
F_21 ( V_78 , V_77 ) ;
return 0 ;
}
