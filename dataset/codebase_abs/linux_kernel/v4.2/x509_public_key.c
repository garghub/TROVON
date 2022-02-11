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
const struct V_2 * V_13 ,
bool V_14 )
{
T_3 V_11 ;
char * V_5 , * V_3 ;
V_3 = V_5 = F_5 ( 2 + 1 + V_13 -> V_15 * 2 + 1 , V_16 ) ;
if ( ! V_5 )
return F_6 ( - V_17 ) ;
if ( V_14 ) {
* V_3 ++ = 'i' ;
* V_3 ++ = 'd' ;
} else {
* V_3 ++ = 'e' ;
* V_3 ++ = 'x' ;
}
* V_3 ++ = ':' ;
V_3 = F_7 ( V_3 , V_13 -> V_8 , V_13 -> V_15 ) ;
* V_3 = 0 ;
F_8 ( L_5 , V_5 ) ;
V_11 = F_9 ( F_10 ( V_12 , 1 ) ,
& V_18 , V_5 ) ;
if ( F_11 ( V_11 ) )
F_8 ( L_6 , V_5 , F_12 ( V_11 ) ) ;
F_13 ( V_5 ) ;
if ( F_11 ( V_11 ) ) {
switch ( F_12 ( V_11 ) ) {
case - V_19 :
case - V_20 :
case - V_21 :
return F_6 ( - V_22 ) ;
default:
return F_14 ( V_11 ) ;
}
}
F_15 ( L_7 , V_23 ,
F_16 ( F_17 ( V_11 ) ) ) ;
return F_17 ( V_11 ) ;
}
int F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_2 V_30 , V_31 ;
void * V_32 ;
int V_7 ;
F_15 ( L_8 , V_23 ) ;
if ( V_25 -> V_33 )
return - V_34 ;
if ( V_25 -> V_35 . V_36 . V_37 )
return 0 ;
V_25 -> V_35 . V_36 . V_37 = F_19 ( V_25 -> V_38 , V_25 -> V_39 ) ;
if ( ! V_25 -> V_35 . V_36 . V_37 )
return - V_17 ;
V_25 -> V_35 . V_40 = 1 ;
V_27 = F_20 ( V_41 [ V_25 -> V_35 . V_42 ] , 0 , 0 ) ;
if ( F_11 ( V_27 ) ) {
if ( F_12 ( V_27 ) == - V_43 ) {
V_25 -> V_33 = true ;
return - V_34 ;
}
return F_12 ( V_27 ) ;
}
V_31 = F_21 ( V_27 ) + sizeof( * V_29 ) ;
V_30 = F_22 ( V_27 ) ;
V_7 = - V_17 ;
V_32 = F_23 ( V_30 + V_31 , V_16 ) ;
if ( ! V_32 )
goto error;
V_25 -> V_35 . V_32 = V_32 ;
V_25 -> V_35 . V_30 = V_30 ;
V_29 = V_32 + V_30 ;
V_29 -> V_27 = V_27 ;
V_29 -> V_44 = V_45 ;
V_7 = F_24 ( V_29 ) ;
if ( V_7 < 0 )
goto error;
F_25 () ;
V_7 = F_26 ( V_29 , V_25 -> V_46 , V_25 -> V_47 , V_32 ) ;
error:
F_27 ( V_27 ) ;
F_15 ( L_9 , V_23 , V_7 ) ;
return V_7 ;
}
int F_28 ( const struct V_48 * V_49 ,
struct V_24 * V_25 )
{
int V_7 ;
F_15 ( L_8 , V_23 ) ;
V_7 = F_18 ( V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_29 ( V_49 , & V_25 -> V_35 ) ;
if ( V_7 == - V_34 )
V_25 -> V_33 = true ;
F_8 ( L_10 , V_7 ) ;
return V_7 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_11 * V_50 )
{
struct V_11 * V_11 ;
int V_7 = 1 ;
if ( ! V_50 )
return - V_51 ;
if ( V_9 && ! F_31 ( V_25 -> V_52 , V_9 ) )
return - V_53 ;
V_11 = F_4 ( V_50 , V_25 -> V_52 ,
false ) ;
if ( ! F_11 ( V_11 ) ) {
if ( ! V_10
|| F_32 ( V_54 , & V_11 -> V_44 ) )
V_7 = F_28 ( V_11 -> V_55 . V_8 , V_25 ) ;
F_33 ( V_11 ) ;
}
return V_7 ;
}
static int F_34 ( struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_24 * V_25 ;
const char * V_60 ;
T_2 V_61 , V_62 ;
char * V_29 = NULL , * V_3 ;
int V_7 ;
V_25 = F_35 ( V_57 -> V_8 , V_57 -> V_63 ) ;
if ( F_11 ( V_25 ) )
return F_12 ( V_25 ) ;
F_15 ( L_11 , V_25 -> V_64 ) ;
F_15 ( L_12 , V_25 -> V_65 ) ;
if ( V_25 -> V_49 -> V_66 >= V_67 ||
V_25 -> V_35 . V_66 >= V_67 ||
V_25 -> V_35 . V_42 >= V_68 ||
! V_66 [ V_25 -> V_49 -> V_66 ] ||
! V_66 [ V_25 -> V_35 . V_66 ] ||
! V_41 [ V_25 -> V_35 . V_42 ] ) {
V_7 = - V_34 ;
goto V_69;
}
F_15 ( L_13 , V_70 [ V_25 -> V_49 -> V_66 ] ) ;
F_15 ( L_14 ,
V_25 -> V_71 . V_72 + 1900 , V_25 -> V_71 . V_73 + 1 ,
V_25 -> V_71 . V_74 , V_25 -> V_71 . V_75 ,
V_25 -> V_71 . V_76 , V_25 -> V_71 . V_77 ) ;
F_15 ( L_15 ,
V_25 -> V_78 . V_72 + 1900 , V_25 -> V_78 . V_73 + 1 ,
V_25 -> V_78 . V_74 , V_25 -> V_78 . V_75 ,
V_25 -> V_78 . V_76 , V_25 -> V_78 . V_77 ) ;
F_15 ( L_16 ,
V_70 [ V_25 -> V_35 . V_66 ] ,
V_41 [ V_25 -> V_35 . V_42 ] ) ;
V_25 -> V_49 -> V_79 = V_66 [ V_25 -> V_49 -> V_66 ] ;
V_25 -> V_49 -> V_80 = V_81 ;
if ( ! V_25 -> V_52 ||
F_36 ( V_25 -> V_82 , V_25 -> V_52 ) ) {
V_7 = F_28 ( V_25 -> V_49 , V_25 ) ;
if ( V_7 < 0 )
goto V_69;
} else if ( ! V_57 -> V_83 ) {
V_7 = F_30 ( V_25 , F_37 () ) ;
if ( ! V_7 )
V_57 -> V_83 = 1 ;
}
V_62 = strlen ( V_25 -> V_65 ) ;
if ( V_25 -> V_84 ) {
V_61 = V_25 -> V_85 ;
V_60 = V_25 -> V_84 ;
} else {
V_61 = V_25 -> V_86 ;
V_60 = V_25 -> V_87 ;
}
if ( V_61 > 1 && * V_60 == 0 ) {
V_61 -- ;
V_60 ++ ;
}
V_7 = - V_17 ;
V_29 = F_5 ( V_62 + 2 + V_61 * 2 + 1 , V_16 ) ;
if ( ! V_29 )
goto V_69;
V_3 = memcpy ( V_29 , V_25 -> V_65 , V_62 ) ;
V_3 += V_62 ;
* V_3 ++ = ':' ;
* V_3 ++ = ' ' ;
V_3 = F_7 ( V_3 , V_60 , V_61 ) ;
* V_3 = 0 ;
V_59 = F_5 ( sizeof( struct V_58 ) , V_16 ) ;
if ( ! V_59 )
goto V_88;
V_59 -> V_5 [ 0 ] = V_25 -> V_5 ;
V_59 -> V_5 [ 1 ] = V_25 -> V_82 ;
F_38 ( V_89 . V_90 ) ;
V_57 -> V_91 [ 0 ] = & V_89 ;
V_57 -> V_91 [ 1 ] = V_59 ;
V_57 -> V_55 [ 0 ] = V_25 -> V_49 ;
V_57 -> V_92 = V_29 ;
V_57 -> V_93 = 100 ;
V_25 -> V_49 = NULL ;
V_25 -> V_5 = NULL ;
V_25 -> V_82 = NULL ;
V_29 = NULL ;
V_7 = 0 ;
V_88:
F_13 ( V_29 ) ;
V_69:
F_39 ( V_25 ) ;
return V_7 ;
}
static int T_1 F_40 ( void )
{
return F_41 ( & V_94 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_94 ) ;
}
