static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
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
V_4 -> V_20 = 1 ;
V_4 -> V_21 = 1 ;
V_11 = F_6 ( V_9 , V_6 , NULL , NULL , NULL , V_4 , true ) ;
if ( V_11 == NULL )
return - V_22 ;
V_12 = F_7 ( V_11 , V_2 -> V_23 , V_6 -> V_24 ) ;
F_8 ( V_9 , true ) ;
return V_12 ;
}
static int F_9 ( struct V_25 * V_26 ,
union V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_29 * V_29 )
{
struct V_7 * V_8 = F_10 ( V_26 , struct V_7 , V_26 ) ;
struct V_5 V_6 ;
int V_12 = 0 ;
if ( F_11 ( V_29 , & V_6 , V_4 ) < 0 ) {
F_12 ( L_1 ,
V_28 -> V_30 . type ) ;
return - 1 ;
}
if ( V_8 -> V_31 && ! F_13 ( V_4 -> V_32 , V_8 -> V_33 ) )
goto V_34;
if ( ! V_6 . V_35 && F_1 ( V_2 , V_4 , & V_6 , V_8 ) ) {
F_12 ( L_2
L_3 ) ;
V_12 = - 1 ;
}
V_34:
F_14 ( & V_6 ) ;
return V_12 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_16 ( V_11 -> V_36 . V_14 , V_11 -> V_36 . V_17 , V_2 ,
V_8 -> V_37 , V_8 -> V_38 , 0 , 0 ) ;
}
static void F_17 ( struct V_9 * V_9 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_16 * V_39 = F_18 ( & V_9 -> V_40 ) , * V_41 ;
int V_42 = V_43 ;
while ( V_39 ) {
struct V_10 * V_11 = F_19 ( V_39 , struct V_10 , V_16 ) ;
struct V_44 * V_45 ;
if ( V_11 -> V_36 . V_14 == NULL || V_11 -> V_36 . V_17 -> V_18 -> V_46 )
goto V_47;
V_45 = F_20 ( V_11 -> V_36 . V_14 ) ;
if ( V_45 -> V_48 == NULL ) {
V_47:
if ( V_42 == V_49 )
V_39 = F_21 ( V_39 ) ;
else
V_39 = F_22 ( V_39 ) ;
continue;
}
if ( V_50 == 2 ) {
int V_12 ;
int (* F_23)( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_51 * V_52 );
F_23 = F_24 ( V_53 ,
L_4 ) ;
if ( F_23 == NULL ) {
F_25 ( L_5 ) ;
return;
}
V_12 = F_23 ( V_11 , V_2 , NULL ) ;
if ( ! V_12 || ! V_8 -> V_54 )
return;
V_39 = F_22 ( V_39 ) ;
} else if ( V_50 == 1 ) {
V_42 = F_26 ( V_11 , V_2 , NULL ) ;
switch ( V_42 ) {
case - 1 :
if ( ! V_8 -> V_54 )
return;
case V_43 :
V_41 = F_22 ( V_39 ) ;
break;
case V_49 :
V_41 = F_21 ( V_39 ) ;
break;
default:
return;
}
if ( V_41 != NULL )
V_39 = V_41 ;
} else {
F_15 ( V_11 , V_2 , V_8 ) ;
V_39 = F_22 ( V_39 ) ;
F_27 ( & V_45 -> V_48 -> V_55 ) ;
F_27 ( & V_45 -> V_48 ) ;
}
}
}
static int F_28 ( struct V_7 * V_8 )
{
int V_12 ;
struct V_56 * V_57 = V_8 -> V_57 ;
struct V_1 * V_58 ;
T_1 V_59 ;
F_29 ( & V_57 -> V_60 , V_61 ) ;
if ( V_8 -> V_31 ) {
V_12 = F_30 ( V_57 , V_8 -> V_31 ,
V_8 -> V_33 ) ;
if ( V_12 )
goto V_62;
}
if ( ! V_63 ) {
V_12 = F_31 ( & V_57 -> V_30 . V_64 ) ;
if ( V_12 )
goto V_62;
}
V_12 = F_32 ( V_57 ) ;
if ( V_12 )
goto V_62;
if ( V_65 ) {
F_33 ( V_57 , stdout ) ;
F_34 ( V_57 -> V_66 , stdout ) ;
goto V_62;
}
if ( V_67 > 3 )
F_35 ( V_57 , stdout ) ;
if ( V_67 > 2 )
F_36 ( V_57 , stdout ) ;
V_59 = 0 ;
F_37 (session->evlist, pos) {
struct V_9 * V_9 = F_2 ( V_58 ) ;
T_2 V_68 = V_9 -> V_69 . V_70 [ V_71 ] ;
if ( V_68 > 0 ) {
V_59 += V_68 ;
F_38 ( V_9 , NULL ) ;
F_39 ( V_58 , V_72 ) ;
F_40 ( V_58 , NULL ) ;
if ( V_73 . V_74 &&
! F_41 ( V_58 ) )
continue;
F_17 ( V_9 , V_58 , V_8 ) ;
}
}
if ( V_59 == 0 ) {
F_25 ( L_6 , V_57 -> V_75 -> V_76 ) ;
goto V_62;
}
if ( V_50 == 2 ) {
void (* F_42)( void );
F_42 = F_24 ( V_53 ,
L_7 ) ;
if ( F_42 == NULL ) {
F_25 ( L_5 ) ;
goto V_62;
}
F_42 () ;
}
V_62:
return V_12 ;
}
int F_43 ( int V_77 , const char * * V_78 , const char * T_3 V_79 )
{
struct V_7 F_23 = {
. V_26 = {
. V_4 = F_9 ,
. V_80 = V_81 ,
. V_82 = V_83 ,
. V_84 = V_85 ,
. exit = V_86 ,
. V_87 = V_88 ,
. V_89 = true ,
. V_90 = true ,
} ,
} ;
struct V_91 V_75 = {
. V_92 = V_93 ,
} ;
const struct V_94 V_95 [] = {
F_44 ( 'i' , L_8 , & V_96 , L_9 ,
L_10 ) ,
F_44 ( 'd' , L_11 , & V_73 . V_97 , L_12 ,
L_13 ) ,
F_44 ( 's' , L_14 , & F_23 . V_13 , L_14 ,
L_15 ) ,
F_45 ( 'f' , L_16 , & V_75 . V_98 , L_17 ) ,
F_46 ( 'v' , L_18 , & V_67 ,
L_19 ) ,
F_45 ( 'D' , L_20 , & V_65 ,
L_21 ) ,
F_45 ( 0 , L_22 , & F_23 . V_99 , L_23 ) ,
F_45 ( 0 , L_24 , & F_23 . V_100 , L_25 ) ,
F_45 ( 0 , L_26 , & F_23 . V_101 , L_27 ) ,
F_44 ( 'k' , L_28 , & V_73 . V_102 ,
L_9 , L_29 ) ,
F_45 ( 'm' , L_30 , & V_73 . V_103 ,
L_31 ) ,
F_45 ( 'l' , L_32 , & F_23 . V_37 ,
L_33 ) ,
F_45 ( 'P' , L_34 , & F_23 . V_38 ,
L_35 ) ,
F_45 ( 0 , L_36 , & F_23 . V_54 ,
L_37 ) ,
F_44 ( 'C' , L_38 , & F_23 . V_31 , L_38 , L_39 ) ,
F_47 ( 0 , L_40 , NULL , L_41 ,
L_42 ,
V_104 ) ,
F_45 ( 0 , L_43 , & V_73 . V_105 ,
L_44 ) ,
F_45 ( 0 , L_45 , & V_73 . V_106 ,
L_46 ) ,
F_44 ( 'M' , L_47 , & V_107 , L_48 ,
L_49 ) ,
F_44 ( 0 , L_50 , & V_63 , L_51 ,
L_52 ) ,
F_45 ( 0 , L_53 , & V_73 . V_74 ,
L_54 ) ,
F_45 ( 0 , L_55 , & V_73 . V_108 ,
L_56 ) ,
F_48 ()
} ;
int V_12 = F_49 () ;
if ( V_12 < 0 )
return V_12 ;
V_77 = F_50 ( V_77 , V_78 , V_95 , V_109 , 0 ) ;
if ( V_77 ) {
if ( V_77 > 1 )
F_51 ( V_109 , V_95 ) ;
F_23 . V_13 = V_78 [ 0 ] ;
}
V_75 . V_76 = V_96 ;
F_23 . V_57 = F_52 ( & V_75 , false , & F_23 . V_26 ) ;
if ( F_23 . V_57 == NULL )
return - 1 ;
V_73 . V_110 = sizeof( struct V_44 ) ;
V_73 . V_111 = true ;
V_12 = F_53 ( & F_23 . V_57 -> V_30 . V_64 ) ;
if ( V_12 < 0 )
goto V_112;
if ( F_54 ( NULL ) < 0 )
F_51 ( V_109 , V_95 ) ;
if ( F_23 . V_101 )
V_50 = 0 ;
else if ( F_23 . V_100 )
V_50 = 1 ;
else if ( F_23 . V_99 )
V_50 = 2 ;
F_55 ( true ) ;
V_12 = F_28 ( & F_23 ) ;
V_112:
return V_12 ;
}
