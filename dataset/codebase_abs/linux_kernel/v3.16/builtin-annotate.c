static int F_1 ( struct V_1 * V_2 ,
struct V_3 * T_1 V_4 ,
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
V_10 = F_4 ( & V_2 -> V_19 , V_6 , NULL , NULL , NULL , 1 , 1 , 0 ,
true ) ;
if ( V_10 == NULL )
return - V_20 ;
V_11 = F_5 ( V_10 , V_2 -> V_21 , V_6 -> V_22 ) ;
F_6 ( & V_2 -> V_19 , true ) ;
return V_11 ;
}
static int F_7 ( struct V_23 * V_24 ,
union V_25 * V_26 ,
struct V_3 * T_1 ,
struct V_1 * V_2 ,
struct V_27 * V_27 )
{
struct V_7 * V_8 = F_8 ( V_24 , struct V_7 , V_24 ) ;
struct V_5 V_6 ;
if ( F_9 ( V_26 , V_27 , & V_6 , T_1 ) < 0 ) {
F_10 ( L_1 ,
V_26 -> V_28 . type ) ;
return - 1 ;
}
if ( V_8 -> V_29 && ! F_11 ( T_1 -> V_30 , V_8 -> V_31 ) )
return 0 ;
if ( ! V_6 . V_32 && F_1 ( V_2 , T_1 , & V_6 , V_8 ) ) {
F_10 ( L_2
L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_13 ( V_10 -> V_33 . V_13 , V_10 -> V_33 . V_16 , V_2 ,
V_8 -> V_34 , V_8 -> V_35 , 0 , 0 ) ;
}
static void F_14 ( struct V_19 * V_19 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_15 * V_36 = F_15 ( & V_19 -> V_37 ) , * V_38 ;
int V_39 = V_40 ;
while ( V_36 ) {
struct V_9 * V_10 = F_16 ( V_36 , struct V_9 , V_15 ) ;
struct V_41 * V_42 ;
if ( V_10 -> V_33 . V_13 == NULL || V_10 -> V_33 . V_16 -> V_17 -> V_43 )
goto V_44;
V_42 = F_17 ( V_10 -> V_33 . V_13 ) ;
if ( V_42 -> V_45 == NULL ) {
V_44:
if ( V_39 == V_46 )
V_36 = F_18 ( V_36 ) ;
else
V_36 = F_19 ( V_36 ) ;
continue;
}
if ( V_47 == 2 ) {
int V_11 ;
int (* F_20)( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_48 * V_49 );
F_20 = F_21 ( V_50 ,
L_4 ) ;
if ( F_20 == NULL ) {
F_22 ( L_5 ) ;
return;
}
V_11 = F_20 ( V_10 , V_2 , NULL ) ;
if ( ! V_11 || ! V_8 -> V_51 )
return;
V_36 = F_19 ( V_36 ) ;
} else if ( V_47 == 1 ) {
V_39 = F_23 ( V_10 , V_2 , NULL ) ;
switch ( V_39 ) {
case - 1 :
if ( ! V_8 -> V_51 )
return;
case V_40 :
V_38 = F_19 ( V_36 ) ;
break;
case V_46 :
V_38 = F_18 ( V_36 ) ;
break;
default:
return;
}
if ( V_38 != NULL )
V_36 = V_38 ;
} else {
F_12 ( V_10 , V_2 , V_8 ) ;
V_36 = F_19 ( V_36 ) ;
F_24 ( & V_42 -> V_45 ) ;
}
}
}
static int F_25 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_52 * V_53 ;
struct V_1 * V_54 ;
T_2 V_55 ;
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = V_61 ,
. V_62 = V_8 -> V_62 ,
} ;
V_53 = F_26 ( & V_57 , false , & V_8 -> V_24 ) ;
if ( V_53 == NULL )
return - V_20 ;
F_27 ( & V_53 -> V_63 , V_64 ) ;
if ( V_8 -> V_29 ) {
V_11 = F_28 ( V_53 , V_8 -> V_29 ,
V_8 -> V_31 ) ;
if ( V_11 )
goto V_65;
}
if ( ! V_66 ) {
V_11 = F_29 ( & V_53 -> V_28 . V_67 ) ;
if ( V_11 )
goto V_65;
}
V_11 = F_30 ( V_53 , & V_8 -> V_24 ) ;
if ( V_11 )
goto V_65;
if ( V_68 ) {
F_31 ( V_53 , stdout ) ;
goto V_65;
}
if ( V_69 > 3 )
F_32 ( V_53 , stdout ) ;
if ( V_69 > 2 )
F_33 ( V_53 , stdout ) ;
V_55 = 0 ;
F_34 (session->evlist, pos) {
struct V_19 * V_19 = & V_54 -> V_19 ;
T_3 V_70 = V_19 -> V_71 . V_72 [ V_73 ] ;
if ( V_70 > 0 ) {
V_55 += V_70 ;
F_35 ( V_19 , NULL ) ;
F_36 ( V_19 ) ;
if ( V_74 . V_75 &&
! F_37 ( V_54 ) )
continue;
F_14 ( V_19 , V_54 , V_8 ) ;
}
}
if ( V_55 == 0 ) {
F_22 ( L_6 , V_57 . V_58 ) ;
goto V_65;
}
if ( V_47 == 2 ) {
void (* F_38)( void );
F_38 = F_21 ( V_50 ,
L_7 ) ;
if ( F_38 == NULL ) {
F_22 ( L_5 ) ;
goto V_65;
}
F_38 () ;
}
V_65:
return V_11 ;
}
int F_39 ( int V_76 , const char * * V_77 , const char * T_4 V_4 )
{
struct V_7 F_20 = {
. V_24 = {
. T_1 = F_7 ,
. V_78 = V_79 ,
. V_80 = V_81 ,
. V_82 = V_83 ,
. exit = V_84 ,
. V_85 = V_86 ,
. V_87 = true ,
. V_88 = true ,
} ,
} ;
const struct V_89 V_90 [] = {
F_40 ( 'i' , L_8 , & V_59 , L_9 ,
L_10 ) ,
F_40 ( 'd' , L_11 , & V_74 . V_91 , L_12 ,
L_13 ) ,
F_40 ( 's' , L_14 , & F_20 . V_12 , L_14 ,
L_15 ) ,
F_41 ( 'f' , L_16 , & F_20 . V_62 , L_17 ) ,
F_42 ( 'v' , L_18 , & V_69 ,
L_19 ) ,
F_41 ( 'D' , L_20 , & V_68 ,
L_21 ) ,
F_41 ( 0 , L_22 , & F_20 . V_92 , L_23 ) ,
F_41 ( 0 , L_24 , & F_20 . V_93 , L_25 ) ,
F_41 ( 0 , L_26 , & F_20 . V_94 , L_27 ) ,
F_40 ( 'k' , L_28 , & V_74 . V_95 ,
L_9 , L_29 ) ,
F_41 ( 'm' , L_30 , & V_74 . V_96 ,
L_31 ) ,
F_41 ( 'l' , L_32 , & F_20 . V_34 ,
L_33 ) ,
F_41 ( 'P' , L_34 , & F_20 . V_35 ,
L_35 ) ,
F_41 ( 0 , L_36 , & F_20 . V_51 ,
L_37 ) ,
F_40 ( 'C' , L_38 , & F_20 . V_29 , L_38 , L_39 ) ,
F_40 ( 0 , L_40 , & V_74 . V_97 , L_41 ,
L_42 ) ,
F_41 ( 0 , L_43 , & V_74 . V_98 ,
L_44 ) ,
F_41 ( 0 , L_45 , & V_74 . V_99 ,
L_46 ) ,
F_40 ( 'M' , L_47 , & V_100 , L_48 ,
L_49 ) ,
F_40 ( 0 , L_50 , & V_66 , L_51 ,
L_52 ) ,
F_41 ( 0 , L_53 , & V_74 . V_75 ,
L_54 ) ,
F_43 ()
} ;
V_76 = F_44 ( V_76 , V_77 , V_90 , V_101 , 0 ) ;
if ( F_20 . V_94 )
V_47 = 0 ;
else if ( F_20 . V_93 )
V_47 = 1 ;
else if ( F_20 . V_92 )
V_47 = 2 ;
F_45 ( true ) ;
V_74 . V_102 = sizeof( struct V_41 ) ;
V_74 . V_103 = true ;
if ( F_46 () < 0 )
return - 1 ;
if ( F_47 () < 0 )
F_48 ( V_101 , V_90 ) ;
if ( V_76 ) {
if ( V_76 > 1 )
F_48 ( V_101 , V_90 ) ;
F_20 . V_12 = V_77 [ 0 ] ;
}
return F_25 ( & F_20 ) ;
}
