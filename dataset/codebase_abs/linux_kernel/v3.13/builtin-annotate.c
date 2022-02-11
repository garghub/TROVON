static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
if ( V_8 -> V_12 != NULL &&
( V_6 -> V_13 == NULL ||
strcmp ( V_8 -> V_12 , V_6 -> V_13 -> V_14 ) != 0 ) ) {
if ( V_6 -> V_13 != NULL ) {
F_2 ( & V_6 -> V_13 -> V_15 ,
& V_6 -> V_16 -> V_17 -> V_18 [ V_6 -> V_16 -> type ] ) ;
F_3 ( V_6 -> V_13 ) ;
}
return 0 ;
}
V_10 = F_4 ( & V_2 -> V_19 , V_6 , NULL , NULL , NULL , 1 , 1 , 0 ) ;
if ( V_10 == NULL )
return - V_20 ;
V_11 = 0 ;
if ( V_10 -> V_21 . V_13 != NULL ) {
struct V_22 * V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL && F_6 ( V_10 -> V_21 . V_13 ) < 0 )
return - V_20 ;
V_11 = F_7 ( V_10 , V_2 -> V_25 , V_6 -> V_26 ) ;
}
V_2 -> V_19 . V_27 . V_28 += V_4 -> V_29 ;
F_8 ( & V_2 -> V_19 , V_30 ) ;
return V_11 ;
}
static int F_9 ( struct V_31 * V_32 ,
union V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_35 * V_35 )
{
struct V_7 * V_8 = F_10 ( V_32 , struct V_7 , V_32 ) ;
struct V_5 V_6 ;
if ( F_11 ( V_34 , V_35 , & V_6 , V_4 ) < 0 ) {
F_12 ( L_1 ,
V_34 -> V_36 . type ) ;
return - 1 ;
}
if ( V_8 -> V_37 && ! F_13 ( V_4 -> V_38 , V_8 -> V_39 ) )
return 0 ;
if ( ! V_6 . V_40 && F_1 ( V_2 , V_4 , & V_6 , V_8 ) ) {
F_12 ( L_2
L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_15 ( V_10 -> V_21 . V_13 , V_10 -> V_21 . V_16 , V_2 ,
V_8 -> V_41 , V_8 -> V_42 , 0 , 0 ) ;
}
static void F_16 ( struct V_19 * V_19 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_15 * V_43 = F_17 ( & V_19 -> V_44 ) , * V_45 ;
int V_46 = V_47 ;
while ( V_43 ) {
struct V_9 * V_10 = F_18 ( V_43 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_48 )
goto V_49;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_49:
if ( V_46 == V_50 )
V_43 = F_19 ( V_43 ) ;
else
V_43 = F_20 ( V_43 ) ;
continue;
}
if ( V_51 == 2 ) {
int V_11 ;
int (* F_21)( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_52 * V_53 );
F_21 = F_22 ( V_54 ,
L_4 ) ;
if ( F_21 == NULL ) {
F_23 ( L_5 ) ;
return;
}
V_11 = F_21 ( V_10 , V_2 , NULL ) ;
if ( ! V_11 || ! V_8 -> V_55 )
return;
V_43 = F_20 ( V_43 ) ;
} else if ( V_51 == 1 ) {
V_46 = F_24 ( V_10 , V_2 , NULL ) ;
switch ( V_46 ) {
case - 1 :
if ( ! V_8 -> V_55 )
return;
case V_47 :
V_45 = F_20 ( V_43 ) ;
break;
case V_50 :
V_45 = F_19 ( V_43 ) ;
break;
default:
return;
}
if ( V_45 != NULL )
V_43 = V_45 ;
} else {
F_14 ( V_10 , V_2 , V_8 ) ;
V_43 = F_20 ( V_43 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_25 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_56 * V_57 ;
struct V_1 * V_58 ;
T_1 V_59 ;
struct V_60 V_61 = {
. V_62 = V_63 ,
. V_64 = V_65 ,
. V_66 = V_8 -> V_66 ,
} ;
V_57 = F_26 ( & V_61 , false , & V_8 -> V_32 ) ;
if ( V_57 == NULL )
return - V_20 ;
F_27 ( & V_57 -> V_67 , V_68 ) ;
if ( V_8 -> V_37 ) {
V_11 = F_28 ( V_57 , V_8 -> V_37 ,
V_8 -> V_39 ) ;
if ( V_11 )
goto V_69;
}
if ( ! V_70 ) {
V_11 = F_29 ( & V_57 -> V_36 . V_71 ) ;
if ( V_11 )
goto V_69;
}
V_11 = F_30 ( V_57 , & V_8 -> V_32 ) ;
if ( V_11 )
goto V_69;
if ( V_72 ) {
F_31 ( V_57 , stdout ) ;
goto V_69;
}
if ( V_73 > 3 )
F_32 ( V_57 , stdout ) ;
if ( V_73 > 2 )
F_33 ( V_57 , stdout ) ;
V_59 = 0 ;
F_34 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_58 -> V_19 ;
T_2 V_74 = V_19 -> V_27 . V_75 [ V_30 ] ;
if ( V_74 > 0 ) {
V_59 += V_74 ;
F_35 ( V_19 , NULL ) ;
F_36 ( V_19 ) ;
if ( V_76 . V_77 &&
! F_37 ( V_58 ) )
continue;
F_16 ( V_19 , V_58 , V_8 ) ;
}
}
if ( V_59 == 0 ) {
F_23 ( L_6 , V_61 . V_62 ) ;
goto V_69;
}
if ( V_51 == 2 ) {
void (* F_38)( void );
F_38 = F_22 ( V_54 ,
L_7 ) ;
if ( F_38 == NULL ) {
F_23 ( L_5 ) ;
goto V_69;
}
F_38 () ;
}
V_69:
return V_11 ;
}
int F_39 ( int V_78 , const char * * V_79 , const char * T_3 V_80 )
{
struct V_7 F_21 = {
. V_32 = {
. V_4 = F_9 ,
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = V_86 ,
. exit = V_87 ,
. V_88 = V_89 ,
. V_90 = true ,
. V_91 = true ,
} ,
} ;
const struct V_92 V_93 [] = {
F_40 ( 'i' , L_8 , & V_63 , L_9 ,
L_10 ) ,
F_40 ( 'd' , L_11 , & V_76 . V_94 , L_12 ,
L_13 ) ,
F_40 ( 's' , L_14 , & F_21 . V_12 , L_14 ,
L_15 ) ,
F_41 ( 'f' , L_16 , & F_21 . V_66 , L_17 ) ,
F_42 ( 'v' , L_18 , & V_73 ,
L_19 ) ,
F_41 ( 'D' , L_20 , & V_72 ,
L_21 ) ,
F_41 ( 0 , L_22 , & F_21 . V_95 , L_23 ) ,
F_41 ( 0 , L_24 , & F_21 . V_96 , L_25 ) ,
F_41 ( 0 , L_26 , & F_21 . V_97 , L_27 ) ,
F_40 ( 'k' , L_28 , & V_76 . V_98 ,
L_9 , L_29 ) ,
F_41 ( 'm' , L_30 , & V_76 . V_99 ,
L_31 ) ,
F_41 ( 'l' , L_32 , & F_21 . V_41 ,
L_33 ) ,
F_41 ( 'P' , L_34 , & F_21 . V_42 ,
L_35 ) ,
F_41 ( 0 , L_36 , & F_21 . V_55 ,
L_37 ) ,
F_40 ( 'C' , L_38 , & F_21 . V_37 , L_38 , L_39 ) ,
F_40 ( 0 , L_40 , & V_76 . V_100 , L_41 ,
L_42 ) ,
F_41 ( 0 , L_43 , & V_76 . V_101 ,
L_44 ) ,
F_41 ( 0 , L_45 , & V_76 . V_102 ,
L_46 ) ,
F_40 ( 'M' , L_47 , & V_103 , L_48 ,
L_49 ) ,
F_40 ( 0 , L_50 , & V_70 , L_51 ,
L_52 ) ,
F_41 ( 0 , L_53 , & V_76 . V_77 ,
L_54 ) ,
F_43 ()
} ;
V_78 = F_44 ( V_78 , V_79 , V_93 , V_104 , 0 ) ;
if ( F_21 . V_97 )
V_51 = 0 ;
else if ( F_21 . V_96 )
V_51 = 1 ;
else if ( F_21 . V_95 )
V_51 = 2 ;
F_45 ( true ) ;
V_76 . V_105 = sizeof( struct V_22 ) ;
V_76 . V_106 = true ;
if ( F_46 () < 0 )
return - 1 ;
if ( F_47 () < 0 )
F_48 ( V_104 , V_93 ) ;
if ( V_78 ) {
if ( V_78 > 1 )
F_48 ( V_104 , V_93 ) ;
F_21 . V_12 = V_79 [ 0 ] ;
}
return F_25 ( & F_21 ) ;
}
