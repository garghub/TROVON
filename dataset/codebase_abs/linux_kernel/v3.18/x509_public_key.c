static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
if ( strncmp ( V_1 , L_1 , 3 ) == 0 ) {
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 + 3 ) ;
if ( V_3 == F_3 ( - V_4 ) )
F_4 ( L_2 ) ;
else if ( ! F_5 ( V_3 ) )
V_5 = V_3 ;
} else if ( strcmp ( V_1 , L_3 ) == 0 ) {
V_6 = true ;
}
return 1 ;
}
struct V_7 * F_6 ( struct V_7 * V_8 ,
const struct V_2 * V_9 ,
bool V_10 )
{
T_2 V_7 ;
char * V_11 , * V_3 ;
V_3 = V_11 = F_7 ( 2 + 1 + V_9 -> V_12 * 2 + 1 , V_13 ) ;
if ( ! V_11 )
return F_3 ( - V_14 ) ;
if ( V_10 ) {
* V_3 ++ = 'i' ;
* V_3 ++ = 'd' ;
} else {
* V_3 ++ = 'e' ;
* V_3 ++ = 'x' ;
}
* V_3 ++ = ':' ;
V_3 = F_8 ( V_3 , V_9 -> V_15 , V_9 -> V_12 ) ;
* V_3 = 0 ;
F_9 ( L_4 , V_11 ) ;
V_7 = F_10 ( F_11 ( V_8 , 1 ) ,
& V_16 , V_11 ) ;
if ( F_5 ( V_7 ) )
F_9 ( L_5 , V_11 , F_12 ( V_7 ) ) ;
F_13 ( V_11 ) ;
if ( F_5 ( V_7 ) ) {
switch ( F_12 ( V_7 ) ) {
case - V_17 :
case - V_18 :
case - V_19 :
return F_3 ( - V_20 ) ;
default:
return F_14 ( V_7 ) ;
}
}
F_15 ( L_6 , V_21 ,
F_16 ( F_17 ( V_7 ) ) ) ;
return F_17 ( V_7 ) ;
}
int F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
T_3 V_28 , V_29 ;
void * V_30 ;
int V_31 ;
F_15 ( L_7 , V_21 ) ;
if ( V_23 -> V_32 )
return - V_33 ;
if ( V_23 -> V_34 . V_35 . V_36 )
return 0 ;
V_23 -> V_34 . V_35 . V_36 = F_19 ( V_23 -> V_37 , V_23 -> V_38 ) ;
if ( ! V_23 -> V_34 . V_35 . V_36 )
return - V_14 ;
V_23 -> V_34 . V_39 = 1 ;
V_25 = F_20 ( V_40 [ V_23 -> V_34 . V_41 ] , 0 , 0 ) ;
if ( F_5 ( V_25 ) ) {
if ( F_12 ( V_25 ) == - V_42 ) {
V_23 -> V_32 = true ;
return - V_33 ;
}
return F_12 ( V_25 ) ;
}
V_29 = F_21 ( V_25 ) + sizeof( * V_27 ) ;
V_28 = F_22 ( V_25 ) ;
V_31 = - V_14 ;
V_30 = F_23 ( V_28 + V_29 , V_13 ) ;
if ( ! V_30 )
goto error;
V_23 -> V_34 . V_30 = V_30 ;
V_23 -> V_34 . V_28 = V_28 ;
V_27 = V_30 + V_28 ;
V_27 -> V_25 = V_25 ;
V_27 -> V_43 = V_44 ;
V_31 = F_24 ( V_27 ) ;
if ( V_31 < 0 )
goto error;
F_25 () ;
V_31 = F_26 ( V_27 , V_23 -> V_45 , V_23 -> V_46 , V_30 ) ;
error:
F_27 ( V_25 ) ;
F_15 ( L_8 , V_21 , V_31 ) ;
return V_31 ;
}
int F_28 ( const struct V_47 * V_48 ,
struct V_22 * V_23 )
{
int V_31 ;
F_15 ( L_7 , V_21 ) ;
V_31 = F_18 ( V_23 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_29 ( V_48 , & V_23 -> V_34 ) ;
if ( V_31 == - V_33 )
V_23 -> V_32 = true ;
F_9 ( L_9 , V_31 ) ;
return V_31 ;
}
static int F_30 ( struct V_22 * V_23 ,
struct V_7 * V_49 )
{
struct V_7 * V_7 ;
int V_31 = 1 ;
if ( ! V_49 )
return - V_50 ;
if ( V_5 && ! F_31 ( V_23 -> V_51 , V_5 ) )
return - V_52 ;
V_7 = F_6 ( V_49 , V_23 -> V_51 ,
false ) ;
if ( ! F_5 ( V_7 ) ) {
if ( ! V_6
|| F_32 ( V_53 , & V_7 -> V_43 ) )
V_31 = F_28 ( V_7 -> V_54 . V_15 , V_23 ) ;
F_33 ( V_7 ) ;
}
return V_31 ;
}
static int F_34 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_22 * V_23 ;
const char * V_59 ;
T_3 V_60 , V_61 ;
char * V_27 = NULL , * V_3 ;
int V_31 ;
V_23 = F_35 ( V_56 -> V_15 , V_56 -> V_62 ) ;
if ( F_5 ( V_23 ) )
return F_12 ( V_23 ) ;
F_15 ( L_10 , V_23 -> V_63 ) ;
F_15 ( L_11 , V_23 -> V_64 ) ;
if ( V_23 -> V_48 -> V_65 >= V_66 ||
V_23 -> V_34 . V_65 >= V_66 ||
V_23 -> V_34 . V_41 >= V_67 ||
! V_65 [ V_23 -> V_48 -> V_65 ] ||
! V_65 [ V_23 -> V_34 . V_65 ] ||
! V_40 [ V_23 -> V_34 . V_41 ] ) {
V_31 = - V_33 ;
goto V_68;
}
F_15 ( L_12 , V_69 [ V_23 -> V_48 -> V_65 ] ) ;
F_15 ( L_13 ,
V_23 -> V_70 . V_71 + 1900 , V_23 -> V_70 . V_72 + 1 ,
V_23 -> V_70 . V_73 , V_23 -> V_70 . V_74 ,
V_23 -> V_70 . V_75 , V_23 -> V_70 . V_76 ) ;
F_15 ( L_14 ,
V_23 -> V_77 . V_71 + 1900 , V_23 -> V_77 . V_72 + 1 ,
V_23 -> V_77 . V_73 , V_23 -> V_77 . V_74 ,
V_23 -> V_77 . V_75 , V_23 -> V_77 . V_76 ) ;
F_15 ( L_15 ,
V_69 [ V_23 -> V_34 . V_65 ] ,
V_40 [ V_23 -> V_34 . V_41 ] ) ;
V_23 -> V_48 -> V_78 = V_65 [ V_23 -> V_48 -> V_65 ] ;
V_23 -> V_48 -> V_79 = V_80 ;
if ( ! V_23 -> V_51 ||
F_36 ( V_23 -> V_81 , V_23 -> V_51 ) ) {
V_31 = F_28 ( V_23 -> V_48 , V_23 ) ;
if ( V_31 < 0 )
goto V_68;
} else if ( ! V_56 -> V_82 ) {
V_31 = F_30 ( V_23 , F_37 () ) ;
if ( ! V_31 )
V_56 -> V_82 = 1 ;
}
V_61 = strlen ( V_23 -> V_64 ) ;
if ( V_23 -> V_83 ) {
V_60 = V_23 -> V_84 ;
V_59 = V_23 -> V_83 ;
} else {
V_60 = V_23 -> V_85 ;
V_59 = V_23 -> V_86 ;
}
if ( V_60 > 1 && * V_59 == 0 ) {
V_60 -- ;
V_59 ++ ;
}
V_31 = - V_14 ;
V_27 = F_7 ( V_61 + 2 + V_60 * 2 + 1 , V_13 ) ;
if ( ! V_27 )
goto V_68;
V_3 = memcpy ( V_27 , V_23 -> V_64 , V_61 ) ;
V_3 += V_61 ;
* V_3 ++ = ':' ;
* V_3 ++ = ' ' ;
V_3 = F_8 ( V_3 , V_59 , V_60 ) ;
* V_3 = 0 ;
V_58 = F_7 ( sizeof( struct V_57 ) , V_13 ) ;
if ( ! V_58 )
goto V_87;
V_58 -> V_11 [ 0 ] = V_23 -> V_11 ;
V_58 -> V_11 [ 1 ] = V_23 -> V_81 ;
F_38 ( V_88 . V_89 ) ;
V_56 -> V_90 [ 0 ] = & V_88 ;
V_56 -> V_90 [ 1 ] = V_58 ;
V_56 -> V_54 [ 0 ] = V_23 -> V_48 ;
V_56 -> V_91 = V_27 ;
V_56 -> V_92 = 100 ;
V_23 -> V_48 = NULL ;
V_23 -> V_11 = NULL ;
V_23 -> V_81 = NULL ;
V_27 = NULL ;
V_31 = 0 ;
V_87:
F_13 ( V_27 ) ;
V_68:
F_39 ( V_23 ) ;
return V_31 ;
}
static int T_1 F_40 ( void )
{
return F_41 ( & V_93 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_93 ) ;
}
