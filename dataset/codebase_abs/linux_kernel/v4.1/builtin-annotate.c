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
if ( F_10 ( V_26 , V_27 , & V_6 , T_1 ) < 0 ) {
F_11 ( L_1 ,
V_26 -> V_28 . type ) ;
return - 1 ;
}
if ( V_8 -> V_29 && ! F_12 ( T_1 -> V_30 , V_8 -> V_31 ) )
return 0 ;
if ( ! V_6 . V_32 && F_1 ( V_2 , T_1 , & V_6 , V_8 ) ) {
F_11 ( L_2
L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_14 ( V_11 -> V_33 . V_14 , V_11 -> V_33 . V_17 , V_2 ,
V_8 -> V_34 , V_8 -> V_35 , 0 , 0 ) ;
}
static void F_15 ( struct V_9 * V_9 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_16 * V_36 = F_16 ( & V_9 -> V_37 ) , * V_38 ;
int V_39 = V_40 ;
while ( V_36 ) {
struct V_10 * V_11 = F_17 ( V_36 , struct V_10 , V_16 ) ;
struct V_41 * V_42 ;
if ( V_11 -> V_33 . V_14 == NULL || V_11 -> V_33 . V_17 -> V_18 -> V_43 )
goto V_44;
V_42 = F_18 ( V_11 -> V_33 . V_14 ) ;
if ( V_42 -> V_45 == NULL ) {
V_44:
if ( V_39 == V_46 )
V_36 = F_19 ( V_36 ) ;
else
V_36 = F_20 ( V_36 ) ;
continue;
}
if ( V_47 == 2 ) {
int V_12 ;
int (* F_21)( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_48 * V_49 );
F_21 = F_22 ( V_50 ,
L_4 ) ;
if ( F_21 == NULL ) {
F_23 ( L_5 ) ;
return;
}
V_12 = F_21 ( V_11 , V_2 , NULL ) ;
if ( ! V_12 || ! V_8 -> V_51 )
return;
V_36 = F_20 ( V_36 ) ;
} else if ( V_47 == 1 ) {
V_39 = F_24 ( V_11 , V_2 , NULL ) ;
switch ( V_39 ) {
case - 1 :
if ( ! V_8 -> V_51 )
return;
case V_40 :
V_38 = F_20 ( V_36 ) ;
break;
case V_46 :
V_38 = F_19 ( V_36 ) ;
break;
default:
return;
}
if ( V_38 != NULL )
V_36 = V_38 ;
} else {
F_13 ( V_11 , V_2 , V_8 ) ;
V_36 = F_20 ( V_36 ) ;
F_25 ( & V_42 -> V_45 ) ;
}
}
}
static int F_26 ( struct V_7 * V_8 )
{
int V_12 ;
struct V_52 * V_53 = V_8 -> V_53 ;
struct V_1 * V_54 ;
T_2 V_55 ;
F_27 ( & V_53 -> V_56 , V_57 ) ;
if ( V_8 -> V_29 ) {
V_12 = F_28 ( V_53 , V_8 -> V_29 ,
V_8 -> V_31 ) ;
if ( V_12 )
goto V_58;
}
if ( ! V_59 ) {
V_12 = F_29 ( & V_53 -> V_28 . V_60 ) ;
if ( V_12 )
goto V_58;
}
V_12 = F_30 ( V_53 ) ;
if ( V_12 )
goto V_58;
if ( V_61 ) {
F_31 ( V_53 , stdout ) ;
F_32 ( V_53 -> V_62 , stdout ) ;
goto V_58;
}
if ( V_63 > 3 )
F_33 ( V_53 , stdout ) ;
if ( V_63 > 2 )
F_34 ( V_53 , stdout ) ;
V_55 = 0 ;
F_35 (session->evlist, pos) {
struct V_9 * V_9 = F_2 ( V_54 ) ;
T_3 V_64 = V_9 -> V_65 . V_66 [ V_67 ] ;
if ( V_64 > 0 ) {
V_55 += V_64 ;
F_36 ( V_9 , NULL ) ;
F_37 ( V_9 , NULL ) ;
if ( V_68 . V_69 &&
! F_38 ( V_54 ) )
continue;
F_15 ( V_9 , V_54 , V_8 ) ;
}
}
if ( V_55 == 0 ) {
F_23 ( L_6 , V_53 -> V_70 -> V_71 ) ;
goto V_58;
}
if ( V_47 == 2 ) {
void (* F_39)( void );
F_39 = F_22 ( V_50 ,
L_7 ) ;
if ( F_39 == NULL ) {
F_23 ( L_5 ) ;
goto V_58;
}
F_39 () ;
}
V_58:
return V_12 ;
}
int F_40 ( int V_72 , const char * * V_73 , const char * T_4 V_4 )
{
struct V_7 F_21 = {
. V_24 = {
. T_1 = F_8 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
. V_78 = V_79 ,
. exit = V_80 ,
. V_81 = V_82 ,
. V_83 = true ,
. V_84 = true ,
} ,
} ;
struct V_85 V_70 = {
. V_71 = V_86 ,
. V_87 = V_88 ,
} ;
const struct V_89 V_90 [] = {
F_41 ( 'i' , L_8 , & V_86 , L_9 ,
L_10 ) ,
F_41 ( 'd' , L_11 , & V_68 . V_91 , L_12 ,
L_13 ) ,
F_41 ( 's' , L_14 , & F_21 . V_13 , L_14 ,
L_15 ) ,
F_42 ( 'f' , L_16 , & V_70 . V_92 , L_17 ) ,
F_43 ( 'v' , L_18 , & V_63 ,
L_19 ) ,
F_42 ( 'D' , L_20 , & V_61 ,
L_21 ) ,
F_42 ( 0 , L_22 , & F_21 . V_93 , L_23 ) ,
F_42 ( 0 , L_24 , & F_21 . V_94 , L_25 ) ,
F_42 ( 0 , L_26 , & F_21 . V_95 , L_27 ) ,
F_41 ( 'k' , L_28 , & V_68 . V_96 ,
L_9 , L_29 ) ,
F_42 ( 'm' , L_30 , & V_68 . V_97 ,
L_31 ) ,
F_42 ( 'l' , L_32 , & F_21 . V_34 ,
L_33 ) ,
F_42 ( 'P' , L_34 , & F_21 . V_35 ,
L_35 ) ,
F_42 ( 0 , L_36 , & F_21 . V_51 ,
L_37 ) ,
F_41 ( 'C' , L_38 , & F_21 . V_29 , L_38 , L_39 ) ,
F_41 ( 0 , L_40 , & V_68 . V_98 , L_41 ,
L_42 ) ,
F_42 ( 0 , L_43 , & V_68 . V_99 ,
L_44 ) ,
F_42 ( 0 , L_45 , & V_68 . V_100 ,
L_46 ) ,
F_41 ( 'M' , L_47 , & V_101 , L_48 ,
L_49 ) ,
F_41 ( 0 , L_50 , & V_59 , L_51 ,
L_52 ) ,
F_42 ( 0 , L_53 , & V_68 . V_69 ,
L_54 ) ,
F_44 ()
} ;
int V_12 = F_45 () ;
if ( V_12 < 0 )
return V_12 ;
V_72 = F_46 ( V_72 , V_73 , V_90 , V_102 , 0 ) ;
if ( F_21 . V_95 )
V_47 = 0 ;
else if ( F_21 . V_94 )
V_47 = 1 ;
else if ( F_21 . V_93 )
V_47 = 2 ;
F_47 ( true ) ;
F_21 . V_53 = F_48 ( & V_70 , false , & F_21 . V_24 ) ;
if ( F_21 . V_53 == NULL )
return - 1 ;
V_68 . V_103 = sizeof( struct V_41 ) ;
V_68 . V_104 = true ;
V_12 = F_49 ( & F_21 . V_53 -> V_28 . V_60 ) ;
if ( V_12 < 0 )
goto V_105;
if ( F_50 () < 0 )
F_51 ( V_102 , V_90 ) ;
if ( V_72 ) {
if ( V_72 > 1 )
F_51 ( V_102 , V_90 ) ;
F_21 . V_13 = V_73 [ 0 ] ;
}
V_12 = F_26 ( & F_21 ) ;
V_105:
return V_12 ;
}
