static int F_1 ( struct V_1 * V_2 ,
struct V_3 * T_1 V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_12 ;
if ( V_8 -> V_13 != NULL &&
( V_6 -> V_14 == NULL ||
strcmp ( V_8 -> V_13 , V_6 -> V_14 -> V_15 ) != 0 ) ) {
if ( V_6 -> V_14 != NULL ) {
F_3 ( & V_6 -> V_14 -> V_16 ,
& V_6 -> V_17 -> V_18 -> V_19 [ V_6 -> V_17 -> type ] ) ;
F_4 ( V_6 -> V_14 ) ;
F_5 ( V_6 -> V_17 -> V_18 ) ;
}
return 0 ;
}
V_11 = F_6 ( V_9 , V_6 , NULL , NULL , NULL , 1 , 1 , 0 , true ) ;
if ( V_11 == NULL )
return - V_20 ;
V_12 = F_7 ( V_11 , V_2 -> V_21 , V_6 -> V_22 ) ;
F_8 ( V_9 , true ) ;
return V_12 ;
}
static int F_9 ( struct V_23 * V_24 ,
union V_25 * V_26 ,
struct V_3 * T_1 ,
struct V_1 * V_2 ,
struct V_27 * V_27 )
{
struct V_7 * V_8 = F_10 ( V_24 , struct V_7 , V_24 ) ;
struct V_5 V_6 ;
int V_12 = 0 ;
if ( F_11 ( V_26 , V_27 , & V_6 , T_1 ) < 0 ) {
F_12 ( L_1 ,
V_26 -> V_28 . type ) ;
return - 1 ;
}
if ( V_8 -> V_29 && ! F_13 ( T_1 -> V_30 , V_8 -> V_31 ) )
goto V_32;
if ( ! V_6 . V_33 && F_1 ( V_2 , T_1 , & V_6 , V_8 ) ) {
F_12 ( L_2
L_3 ) ;
V_12 = - 1 ;
}
V_32:
F_14 ( & V_6 ) ;
return V_12 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_16 ( V_11 -> V_34 . V_14 , V_11 -> V_34 . V_17 , V_2 ,
V_8 -> V_35 , V_8 -> V_36 , 0 , 0 ) ;
}
static void F_17 ( struct V_9 * V_9 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_16 * V_37 = F_18 ( & V_9 -> V_38 ) , * V_39 ;
int V_40 = V_41 ;
while ( V_37 ) {
struct V_10 * V_11 = F_19 ( V_37 , struct V_10 , V_16 ) ;
struct V_42 * V_43 ;
if ( V_11 -> V_34 . V_14 == NULL || V_11 -> V_34 . V_17 -> V_18 -> V_44 )
goto V_45;
V_43 = F_20 ( V_11 -> V_34 . V_14 ) ;
if ( V_43 -> V_46 == NULL ) {
V_45:
if ( V_40 == V_47 )
V_37 = F_21 ( V_37 ) ;
else
V_37 = F_22 ( V_37 ) ;
continue;
}
if ( V_48 == 2 ) {
int V_12 ;
int (* F_23)( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_49 * V_50 );
F_23 = F_24 ( V_51 ,
L_4 ) ;
if ( F_23 == NULL ) {
F_25 ( L_5 ) ;
return;
}
V_12 = F_23 ( V_11 , V_2 , NULL ) ;
if ( ! V_12 || ! V_8 -> V_52 )
return;
V_37 = F_22 ( V_37 ) ;
} else if ( V_48 == 1 ) {
V_40 = F_26 ( V_11 , V_2 , NULL ) ;
switch ( V_40 ) {
case - 1 :
if ( ! V_8 -> V_52 )
return;
case V_41 :
V_39 = F_22 ( V_37 ) ;
break;
case V_47 :
V_39 = F_21 ( V_37 ) ;
break;
default:
return;
}
if ( V_39 != NULL )
V_37 = V_39 ;
} else {
F_15 ( V_11 , V_2 , V_8 ) ;
V_37 = F_22 ( V_37 ) ;
F_27 ( & V_43 -> V_46 -> V_53 ) ;
F_27 ( & V_43 -> V_46 ) ;
}
}
}
static int F_28 ( struct V_7 * V_8 )
{
int V_12 ;
struct V_54 * V_55 = V_8 -> V_55 ;
struct V_1 * V_56 ;
T_2 V_57 ;
F_29 ( & V_55 -> V_58 , V_59 ) ;
if ( V_8 -> V_29 ) {
V_12 = F_30 ( V_55 , V_8 -> V_29 ,
V_8 -> V_31 ) ;
if ( V_12 )
goto V_60;
}
if ( ! V_61 ) {
V_12 = F_31 ( & V_55 -> V_28 . V_62 ) ;
if ( V_12 )
goto V_60;
}
V_12 = F_32 ( V_55 ) ;
if ( V_12 )
goto V_60;
if ( V_63 ) {
F_33 ( V_55 , stdout ) ;
F_34 ( V_55 -> V_64 , stdout ) ;
goto V_60;
}
if ( V_65 > 3 )
F_35 ( V_55 , stdout ) ;
if ( V_65 > 2 )
F_36 ( V_55 , stdout ) ;
V_57 = 0 ;
F_37 (session->evlist, pos) {
struct V_9 * V_9 = F_2 ( V_56 ) ;
T_3 V_66 = V_9 -> V_67 . V_68 [ V_69 ] ;
if ( V_66 > 0 ) {
V_57 += V_66 ;
F_38 ( V_9 , NULL ) ;
F_39 ( V_56 , V_70 ) ;
F_40 ( V_9 , NULL ) ;
if ( V_71 . V_72 &&
! F_41 ( V_56 ) )
continue;
F_17 ( V_9 , V_56 , V_8 ) ;
}
}
if ( V_57 == 0 ) {
F_25 ( L_6 , V_55 -> V_73 -> V_74 ) ;
goto V_60;
}
if ( V_48 == 2 ) {
void (* F_42)( void );
F_42 = F_24 ( V_51 ,
L_7 ) ;
if ( F_42 == NULL ) {
F_25 ( L_5 ) ;
goto V_60;
}
F_42 () ;
}
V_60:
return V_12 ;
}
int F_43 ( int V_75 , const char * * V_76 , const char * T_4 V_4 )
{
struct V_7 F_23 = {
. V_24 = {
. T_1 = F_9 ,
. V_77 = V_78 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
. exit = V_83 ,
. V_84 = V_85 ,
. V_86 = true ,
. V_87 = true ,
} ,
} ;
struct V_88 V_73 = {
. V_89 = V_90 ,
} ;
const struct V_91 V_92 [] = {
F_44 ( 'i' , L_8 , & V_93 , L_9 ,
L_10 ) ,
F_44 ( 'd' , L_11 , & V_71 . V_94 , L_12 ,
L_13 ) ,
F_44 ( 's' , L_14 , & F_23 . V_13 , L_14 ,
L_15 ) ,
F_45 ( 'f' , L_16 , & V_73 . V_95 , L_17 ) ,
F_46 ( 'v' , L_18 , & V_65 ,
L_19 ) ,
F_45 ( 'D' , L_20 , & V_63 ,
L_21 ) ,
F_45 ( 0 , L_22 , & F_23 . V_96 , L_23 ) ,
F_45 ( 0 , L_24 , & F_23 . V_97 , L_25 ) ,
F_45 ( 0 , L_26 , & F_23 . V_98 , L_27 ) ,
F_44 ( 'k' , L_28 , & V_71 . V_99 ,
L_9 , L_29 ) ,
F_45 ( 'm' , L_30 , & V_71 . V_100 ,
L_31 ) ,
F_45 ( 'l' , L_32 , & F_23 . V_35 ,
L_33 ) ,
F_45 ( 'P' , L_34 , & F_23 . V_36 ,
L_35 ) ,
F_45 ( 0 , L_36 , & F_23 . V_52 ,
L_37 ) ,
F_44 ( 'C' , L_38 , & F_23 . V_29 , L_38 , L_39 ) ,
F_44 ( 0 , L_40 , & V_71 . V_101 , L_41 ,
L_42 ) ,
F_45 ( 0 , L_43 , & V_71 . V_102 ,
L_44 ) ,
F_45 ( 0 , L_45 , & V_71 . V_103 ,
L_46 ) ,
F_44 ( 'M' , L_47 , & V_104 , L_48 ,
L_49 ) ,
F_44 ( 0 , L_50 , & V_61 , L_51 ,
L_52 ) ,
F_45 ( 0 , L_53 , & V_71 . V_72 ,
L_54 ) ,
F_45 ( 0 , L_55 , & V_71 . V_105 ,
L_56 ) ,
F_47 ()
} ;
int V_12 = F_48 () ;
if ( V_12 < 0 )
return V_12 ;
V_75 = F_49 ( V_75 , V_76 , V_92 , V_106 , 0 ) ;
if ( F_23 . V_98 )
V_48 = 0 ;
else if ( F_23 . V_97 )
V_48 = 1 ;
else if ( F_23 . V_96 )
V_48 = 2 ;
V_73 . V_74 = V_93 ;
F_50 ( true ) ;
F_23 . V_55 = F_51 ( & V_73 , false , & F_23 . V_24 ) ;
if ( F_23 . V_55 == NULL )
return - 1 ;
V_71 . V_107 = sizeof( struct V_42 ) ;
V_71 . V_108 = true ;
V_12 = F_52 ( & F_23 . V_55 -> V_28 . V_62 ) ;
if ( V_12 < 0 )
goto V_109;
if ( F_53 () < 0 )
F_54 ( V_106 , V_92 ) ;
if ( V_75 ) {
if ( V_75 > 1 )
F_54 ( V_106 , V_92 ) ;
F_23 . V_13 = V_76 [ 0 ] ;
}
V_12 = F_28 ( & F_23 ) ;
V_109:
return V_12 ;
}
