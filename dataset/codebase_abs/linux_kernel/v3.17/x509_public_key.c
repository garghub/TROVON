static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = V_1 ;
else if ( strcmp ( V_1 , L_2 ) == 0 )
V_3 = true ;
return 1 ;
}
struct V_4 * F_2 ( struct V_4 * V_5 ,
const char * V_6 ,
const char * V_7 )
{
T_2 V_4 ;
T_3 V_8 = strlen ( V_6 ) , V_9 = strlen ( V_7 ) ;
char * V_10 ;
V_10 = F_3 ( V_8 + 2 + V_9 + 1 , V_11 ) ;
if ( ! V_10 )
return F_4 ( - V_12 ) ;
memcpy ( V_10 , V_6 , V_8 ) ;
V_10 [ V_8 + 0 ] = ':' ;
V_10 [ V_8 + 1 ] = ' ' ;
memcpy ( V_10 + V_8 + 2 , V_7 , V_9 ) ;
V_10 [ V_8 + 2 + V_9 ] = 0 ;
F_5 ( L_3 , V_10 ) ;
V_4 = F_6 ( F_7 ( V_5 , 1 ) ,
& V_13 , V_10 ) ;
if ( F_8 ( V_4 ) )
F_5 ( L_4 , V_10 , F_9 ( V_4 ) ) ;
F_10 ( V_10 ) ;
if ( F_8 ( V_4 ) ) {
switch ( F_9 ( V_4 ) ) {
case - V_14 :
case - V_15 :
case - V_16 :
return F_4 ( - V_17 ) ;
default:
return F_11 ( V_4 ) ;
}
}
F_12 ( L_5 , V_18 ,
F_13 ( F_14 ( V_4 ) ) ) ;
return F_14 ( V_4 ) ;
}
int F_15 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
T_3 V_25 , V_26 ;
void * V_27 ;
int V_28 ;
F_12 ( L_6 , V_18 ) ;
if ( V_20 -> V_29 . V_30 . V_31 )
return 0 ;
V_20 -> V_29 . V_30 . V_31 = F_16 ( V_20 -> V_32 , V_20 -> V_33 ) ;
if ( ! V_20 -> V_29 . V_30 . V_31 )
return - V_12 ;
V_20 -> V_29 . V_34 = 1 ;
V_22 = F_17 ( V_35 [ V_20 -> V_29 . V_36 ] , 0 , 0 ) ;
if ( F_8 ( V_22 ) )
return ( F_9 ( V_22 ) == - V_37 ) ? - V_38 : F_9 ( V_22 ) ;
V_26 = F_18 ( V_22 ) + sizeof( * V_24 ) ;
V_25 = F_19 ( V_22 ) ;
V_28 = - V_12 ;
V_27 = F_20 ( V_25 + V_26 , V_11 ) ;
if ( ! V_27 )
goto error;
V_20 -> V_29 . V_27 = V_27 ;
V_20 -> V_29 . V_25 = V_25 ;
V_24 = V_27 + V_25 ;
V_24 -> V_22 = V_22 ;
V_24 -> V_39 = V_40 ;
V_28 = F_21 ( V_24 ) ;
if ( V_28 < 0 )
goto error;
F_22 () ;
V_28 = F_23 ( V_24 , V_20 -> V_41 , V_20 -> V_42 , V_27 ) ;
error:
F_24 ( V_22 ) ;
F_12 ( L_7 , V_18 , V_28 ) ;
return V_28 ;
}
int F_25 ( const struct V_43 * V_44 ,
struct V_19 * V_20 )
{
int V_28 ;
F_12 ( L_6 , V_18 ) ;
V_28 = F_15 ( V_20 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_26 ( V_44 , & V_20 -> V_29 ) ;
F_5 ( L_8 , V_28 ) ;
return V_28 ;
}
static int F_27 ( struct V_19 * V_20 ,
struct V_4 * V_45 )
{
struct V_4 * V_4 ;
int V_28 = 1 ;
if ( ! V_45 )
return - V_46 ;
if ( V_2 && ! F_28 ( V_20 -> V_47 , V_2 ) )
return - V_48 ;
V_4 = F_2 ( V_45 ,
V_20 -> V_49 , V_20 -> V_47 ) ;
if ( ! F_8 ( V_4 ) ) {
if ( ! V_3
|| F_29 ( V_50 , & V_4 -> V_39 ) )
V_28 = F_25 ( V_4 -> V_51 . V_52 , V_20 ) ;
F_30 ( V_4 ) ;
}
return V_28 ;
}
static int F_31 ( struct V_53 * V_54 )
{
struct V_19 * V_20 ;
T_3 V_55 , V_56 ;
char * V_24 = NULL ;
int V_28 ;
V_20 = F_32 ( V_54 -> V_52 , V_54 -> V_57 ) ;
if ( F_8 ( V_20 ) )
return F_9 ( V_20 ) ;
F_12 ( L_9 , V_20 -> V_49 ) ;
F_12 ( L_10 , V_20 -> V_6 ) ;
if ( V_20 -> V_44 -> V_58 >= V_59 ||
V_20 -> V_29 . V_58 >= V_59 ||
V_20 -> V_29 . V_36 >= V_60 ||
! V_58 [ V_20 -> V_44 -> V_58 ] ||
! V_58 [ V_20 -> V_29 . V_58 ] ||
! V_35 [ V_20 -> V_29 . V_36 ] ) {
V_28 = - V_38 ;
goto V_61;
}
F_12 ( L_11 , V_62 [ V_20 -> V_44 -> V_58 ] ) ;
F_12 ( L_12 ,
V_20 -> V_63 . V_64 + 1900 , V_20 -> V_63 . V_65 + 1 ,
V_20 -> V_63 . V_66 , V_20 -> V_63 . V_67 ,
V_20 -> V_63 . V_68 , V_20 -> V_63 . V_69 ) ;
F_12 ( L_13 ,
V_20 -> V_70 . V_64 + 1900 , V_20 -> V_70 . V_65 + 1 ,
V_20 -> V_70 . V_66 , V_20 -> V_70 . V_67 ,
V_20 -> V_70 . V_68 , V_20 -> V_70 . V_69 ) ;
F_12 ( L_14 ,
V_62 [ V_20 -> V_29 . V_58 ] ,
V_35 [ V_20 -> V_29 . V_36 ] ) ;
if ( ! V_20 -> V_71 ) {
F_33 ( L_15 ,
V_20 -> V_6 ) ;
V_28 = - V_72 ;
goto V_61;
}
V_20 -> V_44 -> V_73 = V_58 [ V_20 -> V_44 -> V_58 ] ;
V_20 -> V_44 -> V_74 = V_75 ;
if ( ! V_20 -> V_47 ||
strcmp ( V_20 -> V_71 , V_20 -> V_47 ) == 0 ) {
V_28 = F_25 ( V_20 -> V_44 , V_20 ) ;
if ( V_28 < 0 )
goto V_61;
} else if ( ! V_54 -> V_76 ) {
V_28 = F_27 ( V_20 , F_34 () ) ;
if ( ! V_28 )
V_54 -> V_76 = 1 ;
}
V_56 = strlen ( V_20 -> V_6 ) ;
V_55 = strlen ( V_20 -> V_71 ) ;
V_28 = - V_12 ;
V_24 = F_3 ( V_56 + 2 + V_55 + 1 , V_11 ) ;
if ( ! V_24 )
goto V_61;
memcpy ( V_24 , V_20 -> V_6 , V_56 ) ;
V_24 [ V_56 ] = ':' ;
V_24 [ V_56 + 1 ] = ' ' ;
memcpy ( V_24 + V_56 + 2 , V_20 -> V_71 , V_55 ) ;
V_24 [ V_56 + 2 + V_55 ] = 0 ;
F_35 ( V_77 . V_78 ) ;
V_54 -> V_79 [ 0 ] = & V_77 ;
V_54 -> V_79 [ 1 ] = V_20 -> V_71 ;
V_54 -> V_51 [ 0 ] = V_20 -> V_44 ;
V_54 -> V_80 = V_24 ;
V_54 -> V_81 = 100 ;
V_20 -> V_44 = NULL ;
V_20 -> V_71 = NULL ;
V_24 = NULL ;
V_28 = 0 ;
V_61:
F_36 ( V_20 ) ;
return V_28 ;
}
static int T_1 F_37 ( void )
{
return F_38 ( & V_82 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_82 ) ;
}
