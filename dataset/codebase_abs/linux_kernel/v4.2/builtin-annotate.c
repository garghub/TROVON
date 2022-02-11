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
}
return 0 ;
}
V_11 = F_5 ( V_9 , V_6 , NULL , NULL , NULL , 1 , 1 , 0 , true ) ;
if ( V_11 == NULL )
return - V_20 ;
V_12 = F_6 ( V_11 , V_2 -> V_21 , V_6 -> V_22 ) ;
F_7 ( V_9 , true ) ;
return V_12 ;
}
static int F_8 ( struct V_23 * V_24 ,
union V_25 * V_26 ,
struct V_3 * T_1 ,
struct V_1 * V_2 ,
struct V_27 * V_27 )
{
struct V_7 * V_8 = F_9 ( V_24 , struct V_7 , V_24 ) ;
struct V_5 V_6 ;
int V_12 = 0 ;
if ( F_10 ( V_26 , V_27 , & V_6 , T_1 ) < 0 ) {
F_11 ( L_1 ,
V_26 -> V_28 . type ) ;
return - 1 ;
}
if ( V_8 -> V_29 && ! F_12 ( T_1 -> V_30 , V_8 -> V_31 ) )
goto V_32;
if ( ! V_6 . V_33 && F_1 ( V_2 , T_1 , & V_6 , V_8 ) ) {
F_11 ( L_2
L_3 ) ;
V_12 = - 1 ;
}
V_32:
F_13 ( & V_6 ) ;
return V_12 ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_15 ( V_11 -> V_34 . V_14 , V_11 -> V_34 . V_17 , V_2 ,
V_8 -> V_35 , V_8 -> V_36 , 0 , 0 ) ;
}
static void F_16 ( struct V_9 * V_9 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_16 * V_37 = F_17 ( & V_9 -> V_38 ) , * V_39 ;
int V_40 = V_41 ;
while ( V_37 ) {
struct V_10 * V_11 = F_18 ( V_37 , struct V_10 , V_16 ) ;
struct V_42 * V_43 ;
if ( V_11 -> V_34 . V_14 == NULL || V_11 -> V_34 . V_17 -> V_18 -> V_44 )
goto V_45;
V_43 = F_19 ( V_11 -> V_34 . V_14 ) ;
if ( V_43 -> V_46 == NULL ) {
V_45:
if ( V_40 == V_47 )
V_37 = F_20 ( V_37 ) ;
else
V_37 = F_21 ( V_37 ) ;
continue;
}
if ( V_48 == 2 ) {
int V_12 ;
int (* F_22)( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_49 * V_50 );
F_22 = F_23 ( V_51 ,
L_4 ) ;
if ( F_22 == NULL ) {
F_24 ( L_5 ) ;
return;
}
V_12 = F_22 ( V_11 , V_2 , NULL ) ;
if ( ! V_12 || ! V_8 -> V_52 )
return;
V_37 = F_21 ( V_37 ) ;
} else if ( V_48 == 1 ) {
V_40 = F_25 ( V_11 , V_2 , NULL ) ;
switch ( V_40 ) {
case - 1 :
if ( ! V_8 -> V_52 )
return;
case V_41 :
V_39 = F_21 ( V_37 ) ;
break;
case V_47 :
V_39 = F_20 ( V_37 ) ;
break;
default:
return;
}
if ( V_39 != NULL )
V_37 = V_39 ;
} else {
F_14 ( V_11 , V_2 , V_8 ) ;
V_37 = F_21 ( V_37 ) ;
F_26 ( & V_43 -> V_46 ) ;
}
}
}
static int F_27 ( struct V_7 * V_8 )
{
int V_12 ;
struct V_53 * V_54 = V_8 -> V_54 ;
struct V_1 * V_55 ;
T_2 V_56 ;
F_28 ( & V_54 -> V_57 , V_58 ) ;
if ( V_8 -> V_29 ) {
V_12 = F_29 ( V_54 , V_8 -> V_29 ,
V_8 -> V_31 ) ;
if ( V_12 )
goto V_59;
}
if ( ! V_60 ) {
V_12 = F_30 ( & V_54 -> V_28 . V_61 ) ;
if ( V_12 )
goto V_59;
}
V_12 = F_31 ( V_54 ) ;
if ( V_12 )
goto V_59;
if ( V_62 ) {
F_32 ( V_54 , stdout ) ;
F_33 ( V_54 -> V_63 , stdout ) ;
goto V_59;
}
if ( V_64 > 3 )
F_34 ( V_54 , stdout ) ;
if ( V_64 > 2 )
F_35 ( V_54 , stdout ) ;
V_56 = 0 ;
F_36 (session->evlist, pos) {
struct V_9 * V_9 = F_2 ( V_55 ) ;
T_3 V_65 = V_9 -> V_66 . V_67 [ V_68 ] ;
if ( V_65 > 0 ) {
V_56 += V_65 ;
F_37 ( V_9 , NULL ) ;
F_38 ( V_9 , NULL ) ;
if ( V_69 . V_70 &&
! F_39 ( V_55 ) )
continue;
F_16 ( V_9 , V_55 , V_8 ) ;
}
}
if ( V_56 == 0 ) {
F_24 ( L_6 , V_54 -> V_71 -> V_72 ) ;
goto V_59;
}
if ( V_48 == 2 ) {
void (* F_40)( void );
F_40 = F_23 ( V_51 ,
L_7 ) ;
if ( F_40 == NULL ) {
F_24 ( L_5 ) ;
goto V_59;
}
F_40 () ;
}
V_59:
return V_12 ;
}
int F_41 ( int V_73 , const char * * V_74 , const char * T_4 V_4 )
{
struct V_7 F_22 = {
. V_24 = {
. T_1 = F_8 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
. V_79 = V_80 ,
. exit = V_81 ,
. V_82 = V_83 ,
. V_84 = true ,
. V_85 = true ,
} ,
} ;
struct V_86 V_71 = {
. V_87 = V_88 ,
} ;
const struct V_89 V_90 [] = {
F_42 ( 'i' , L_8 , & V_91 , L_9 ,
L_10 ) ,
F_42 ( 'd' , L_11 , & V_69 . V_92 , L_12 ,
L_13 ) ,
F_42 ( 's' , L_14 , & F_22 . V_13 , L_14 ,
L_15 ) ,
F_43 ( 'f' , L_16 , & V_71 . V_93 , L_17 ) ,
F_44 ( 'v' , L_18 , & V_64 ,
L_19 ) ,
F_43 ( 'D' , L_20 , & V_62 ,
L_21 ) ,
F_43 ( 0 , L_22 , & F_22 . V_94 , L_23 ) ,
F_43 ( 0 , L_24 , & F_22 . V_95 , L_25 ) ,
F_43 ( 0 , L_26 , & F_22 . V_96 , L_27 ) ,
F_42 ( 'k' , L_28 , & V_69 . V_97 ,
L_9 , L_29 ) ,
F_43 ( 'm' , L_30 , & V_69 . V_98 ,
L_31 ) ,
F_43 ( 'l' , L_32 , & F_22 . V_35 ,
L_33 ) ,
F_43 ( 'P' , L_34 , & F_22 . V_36 ,
L_35 ) ,
F_43 ( 0 , L_36 , & F_22 . V_52 ,
L_37 ) ,
F_42 ( 'C' , L_38 , & F_22 . V_29 , L_38 , L_39 ) ,
F_42 ( 0 , L_40 , & V_69 . V_99 , L_41 ,
L_42 ) ,
F_43 ( 0 , L_43 , & V_69 . V_100 ,
L_44 ) ,
F_43 ( 0 , L_45 , & V_69 . V_101 ,
L_46 ) ,
F_42 ( 'M' , L_47 , & V_102 , L_48 ,
L_49 ) ,
F_42 ( 0 , L_50 , & V_60 , L_51 ,
L_52 ) ,
F_43 ( 0 , L_53 , & V_69 . V_70 ,
L_54 ) ,
F_43 ( 0 , L_55 , & V_69 . V_103 ,
L_56 ) ,
F_45 ()
} ;
int V_12 = F_46 () ;
if ( V_12 < 0 )
return V_12 ;
V_73 = F_47 ( V_73 , V_74 , V_90 , V_104 , 0 ) ;
if ( F_22 . V_96 )
V_48 = 0 ;
else if ( F_22 . V_95 )
V_48 = 1 ;
else if ( F_22 . V_94 )
V_48 = 2 ;
V_71 . V_72 = V_91 ;
F_48 ( true ) ;
F_22 . V_54 = F_49 ( & V_71 , false , & F_22 . V_24 ) ;
if ( F_22 . V_54 == NULL )
return - 1 ;
V_69 . V_105 = sizeof( struct V_42 ) ;
V_69 . V_106 = true ;
V_12 = F_50 ( & F_22 . V_54 -> V_28 . V_61 ) ;
if ( V_12 < 0 )
goto V_107;
if ( F_51 () < 0 )
F_52 ( V_104 , V_90 ) ;
if ( V_73 ) {
if ( V_73 > 1 )
F_52 ( V_104 , V_90 ) ;
F_22 . V_13 = V_74 [ 0 ] ;
}
V_12 = F_27 ( & F_22 ) ;
V_107:
return V_12 ;
}
