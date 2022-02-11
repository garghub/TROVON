static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
if ( strncmp ( V_1 , L_1 , 3 ) == 0 ) {
struct V_2 * V_3 = & V_4 . V_5 ;
T_2 V_6 = ( strlen ( V_1 ) - 3 ) / 2 ;
int V_7 ;
if ( V_6 == 0 || V_6 > sizeof( V_4 . V_8 ) ) {
F_2 ( L_2 ) ;
return 1 ;
}
V_7 = F_3 ( V_1 + 3 , V_3 , V_6 ) ;
if ( V_7 < 0 )
F_2 ( L_3 ) ;
else
V_9 = V_3 ;
} else if ( strcmp ( V_1 , L_4 ) == 0 ) {
V_10 = true ;
}
return 1 ;
}
struct V_11 * F_4 ( struct V_11 * V_12 ,
const struct V_2 * V_5 ,
const struct V_2 * V_13 ,
bool V_14 )
{
struct V_11 * V_11 ;
T_3 V_15 ;
const char * V_16 ;
char * V_17 , * V_3 ;
int V_18 ;
if ( V_5 ) {
V_16 = V_5 -> V_8 ;
V_18 = V_5 -> V_18 ;
} else {
V_16 = V_13 -> V_8 ;
V_18 = V_13 -> V_18 ;
}
V_3 = V_17 = F_5 ( 2 + 1 + V_18 * 2 + 1 , V_19 ) ;
if ( ! V_17 )
return F_6 ( - V_20 ) ;
if ( V_14 ) {
* V_3 ++ = 'i' ;
* V_3 ++ = 'd' ;
} else {
* V_3 ++ = 'e' ;
* V_3 ++ = 'x' ;
}
* V_3 ++ = ':' ;
V_3 = F_7 ( V_3 , V_16 , V_18 ) ;
* V_3 = 0 ;
F_8 ( L_5 , V_17 ) ;
V_15 = F_9 ( F_10 ( V_12 , 1 ) ,
& V_21 , V_17 ) ;
if ( F_11 ( V_15 ) )
F_8 ( L_6 , V_17 , F_12 ( V_15 ) ) ;
F_13 ( V_17 ) ;
if ( F_11 ( V_15 ) ) {
switch ( F_12 ( V_15 ) ) {
case - V_22 :
case - V_23 :
case - V_24 :
return F_6 ( - V_25 ) ;
default:
return F_14 ( V_15 ) ;
}
}
V_11 = F_15 ( V_15 ) ;
if ( V_5 && V_13 ) {
const struct V_26 * V_27 = V_26 ( V_11 ) ;
if ( ! V_27 -> V_5 [ 1 ] ) {
F_8 ( L_7 ) ;
goto V_28;
}
if ( ! F_16 ( V_13 , V_27 -> V_5 [ 1 ] ) ) {
F_8 ( L_8 ) ;
goto V_28;
}
}
F_17 ( L_9 , V_29 , F_18 ( V_11 ) ) ;
return V_11 ;
V_28:
F_19 ( V_11 ) ;
return F_6 ( - V_30 ) ;
}
int F_20 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_2 V_37 , V_38 ;
void * V_39 ;
int V_7 ;
F_17 ( L_10 , V_29 ) ;
if ( V_32 -> V_40 )
return - V_41 ;
if ( V_32 -> V_42 . V_43 . V_44 )
return 0 ;
V_32 -> V_42 . V_43 . V_44 = F_21 ( V_32 -> V_45 , V_32 -> V_46 ) ;
if ( ! V_32 -> V_42 . V_43 . V_44 )
return - V_20 ;
V_32 -> V_42 . V_47 = 1 ;
V_34 = F_22 ( V_48 [ V_32 -> V_42 . V_49 ] , 0 , 0 ) ;
if ( F_11 ( V_34 ) ) {
if ( F_12 ( V_34 ) == - V_50 ) {
V_32 -> V_40 = true ;
return - V_41 ;
}
return F_12 ( V_34 ) ;
}
V_38 = F_23 ( V_34 ) + sizeof( * V_36 ) ;
V_37 = F_24 ( V_34 ) ;
V_7 = - V_20 ;
V_39 = F_25 ( F_26 ( V_37 , F_27 ( * V_36 ) ) + V_38 ,
V_19 ) ;
if ( ! V_39 )
goto error;
V_32 -> V_42 . V_39 = V_39 ;
V_32 -> V_42 . V_37 = V_37 ;
V_36 = F_28 ( V_39 + V_37 , F_27 ( * V_36 ) ) ;
V_36 -> V_34 = V_34 ;
V_36 -> V_51 = V_52 ;
V_7 = F_29 ( V_36 ) ;
if ( V_7 < 0 )
goto error;
F_30 () ;
V_7 = F_31 ( V_36 , V_32 -> V_53 , V_32 -> V_54 , V_39 ) ;
error:
F_32 ( V_34 ) ;
F_17 ( L_11 , V_29 , V_7 ) ;
return V_7 ;
}
int F_33 ( const struct V_55 * V_56 ,
struct V_31 * V_32 )
{
int V_7 ;
F_17 ( L_10 , V_29 ) ;
V_7 = F_20 ( V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_34 ( V_56 , & V_32 -> V_42 ) ;
if ( V_7 == - V_41 )
V_32 -> V_40 = true ;
F_8 ( L_12 , V_7 ) ;
return V_7 ;
}
static int F_35 ( struct V_31 * V_32 ,
struct V_11 * V_57 )
{
struct V_11 * V_11 ;
int V_7 = 1 ;
if ( ! V_57 )
return - V_58 ;
if ( V_9 && ! F_36 ( V_32 -> V_59 , V_9 ) )
return - V_60 ;
V_11 = F_4 ( V_57 ,
V_32 -> V_61 , V_32 -> V_59 ,
false ) ;
if ( ! F_11 ( V_11 ) ) {
if ( ! V_10
|| F_37 ( V_62 , & V_11 -> V_51 ) )
V_7 = F_33 ( V_11 -> V_63 . V_8 [ V_64 ] ,
V_32 ) ;
F_19 ( V_11 ) ;
}
return V_7 ;
}
static int F_38 ( struct V_65 * V_66 )
{
struct V_26 * V_27 ;
struct V_31 * V_32 ;
const char * V_67 ;
T_2 V_68 , V_69 ;
char * V_36 = NULL , * V_3 ;
int V_7 ;
V_32 = F_39 ( V_66 -> V_8 , V_66 -> V_70 ) ;
if ( F_11 ( V_32 ) )
return F_12 ( V_32 ) ;
F_17 ( L_13 , V_32 -> V_71 ) ;
F_17 ( L_14 , V_32 -> V_72 ) ;
if ( V_32 -> V_56 -> V_73 >= V_74 ||
V_32 -> V_42 . V_73 >= V_74 ||
V_32 -> V_42 . V_49 >= V_75 ||
! V_73 [ V_32 -> V_56 -> V_73 ] ||
! V_73 [ V_32 -> V_42 . V_73 ] ||
! V_48 [ V_32 -> V_42 . V_49 ] ) {
V_7 = - V_41 ;
goto V_76;
}
F_17 ( L_15 , V_77 [ V_32 -> V_56 -> V_73 ] ) ;
F_17 ( L_16 , V_32 -> V_78 , V_32 -> V_79 ) ;
F_17 ( L_17 ,
V_77 [ V_32 -> V_42 . V_73 ] ,
V_48 [ V_32 -> V_42 . V_49 ] ) ;
V_32 -> V_56 -> V_80 = V_73 [ V_32 -> V_56 -> V_73 ] ;
V_32 -> V_56 -> V_81 = V_82 ;
if ( ( ! V_32 -> V_59 && ! V_32 -> V_61 ) ||
F_16 ( V_32 -> V_13 , V_32 -> V_59 ) ||
F_16 ( V_32 -> V_5 , V_32 -> V_61 ) ) {
V_7 = F_33 ( V_32 -> V_56 , V_32 ) ;
if ( V_7 < 0 )
goto V_76;
} else if ( ! V_66 -> V_83 ) {
V_7 = F_35 ( V_32 , F_40 () ) ;
if ( V_7 )
V_7 = F_35 ( V_32 , F_41 () ) ;
if ( ! V_7 )
V_66 -> V_83 = 1 ;
}
V_69 = strlen ( V_32 -> V_72 ) ;
if ( V_32 -> V_84 ) {
V_68 = V_32 -> V_85 ;
V_67 = V_32 -> V_84 ;
} else {
V_68 = V_32 -> V_86 ;
V_67 = V_32 -> V_87 ;
}
V_7 = - V_20 ;
V_36 = F_5 ( V_69 + 2 + V_68 * 2 + 1 , V_19 ) ;
if ( ! V_36 )
goto V_76;
V_3 = memcpy ( V_36 , V_32 -> V_72 , V_69 ) ;
V_3 += V_69 ;
* V_3 ++ = ':' ;
* V_3 ++ = ' ' ;
V_3 = F_7 ( V_3 , V_67 , V_68 ) ;
* V_3 = 0 ;
V_27 = F_5 ( sizeof( struct V_26 ) , V_19 ) ;
if ( ! V_27 )
goto V_88;
V_27 -> V_5 [ 0 ] = V_32 -> V_5 ;
V_27 -> V_5 [ 1 ] = V_32 -> V_13 ;
F_42 ( V_89 . V_90 ) ;
V_66 -> V_63 . V_8 [ V_91 ] = & V_89 ;
V_66 -> V_63 . V_8 [ V_92 ] = V_27 ;
V_66 -> V_63 . V_8 [ V_64 ] = V_32 -> V_56 ;
V_66 -> V_93 = V_36 ;
V_66 -> V_94 = 100 ;
V_32 -> V_56 = NULL ;
V_32 -> V_5 = NULL ;
V_32 -> V_13 = NULL ;
V_36 = NULL ;
V_7 = 0 ;
V_88:
F_13 ( V_36 ) ;
V_76:
F_43 ( V_32 ) ;
return V_7 ;
}
static int T_1 F_44 ( void )
{
return F_45 ( & V_95 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_95 ) ;
}
