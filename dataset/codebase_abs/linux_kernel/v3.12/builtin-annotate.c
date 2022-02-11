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
V_10 = F_4 ( & V_2 -> V_19 , V_6 , NULL , 1 , 1 ) ;
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
static void F_16 ( struct V_19 * V_43 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_15 * V_44 = F_17 ( & V_43 -> V_45 ) , * V_46 ;
int V_47 = V_48 ;
while ( V_44 ) {
struct V_9 * V_10 = F_18 ( V_44 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_49 )
goto V_50;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_50:
if ( V_47 == V_51 )
V_44 = F_19 ( V_44 ) ;
else
V_44 = F_20 ( V_44 ) ;
continue;
}
if ( V_52 == 2 ) {
int V_11 ;
V_11 = F_21 ( V_10 , V_2 , NULL ) ;
if ( ! V_11 || ! V_8 -> V_53 )
return;
V_44 = F_20 ( V_44 ) ;
} else if ( V_52 == 1 ) {
V_47 = F_22 ( V_10 , V_2 , NULL ) ;
switch ( V_47 ) {
case - 1 :
if ( ! V_8 -> V_53 )
return;
case V_48 :
V_46 = F_20 ( V_44 ) ;
break;
case V_51 :
V_46 = F_19 ( V_44 ) ;
break;
default:
return;
}
if ( V_46 != NULL )
V_44 = V_46 ;
} else {
F_14 ( V_10 , V_2 , V_8 ) ;
V_44 = F_20 ( V_44 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_23 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_54 * V_55 ;
struct V_1 * V_56 ;
T_1 V_57 ;
V_55 = F_24 ( V_58 , V_59 ,
V_8 -> V_60 , false , & V_8 -> V_32 ) ;
if ( V_55 == NULL )
return - V_20 ;
F_25 ( & V_55 -> V_61 , V_62 ) ;
if ( V_8 -> V_37 ) {
V_11 = F_26 ( V_55 , V_8 -> V_37 ,
V_8 -> V_39 ) ;
if ( V_11 )
goto V_63;
}
if ( ! V_64 ) {
V_11 = F_27 ( & V_55 -> V_36 . V_65 ) ;
if ( V_11 )
goto V_63;
}
V_11 = F_28 ( V_55 , & V_8 -> V_32 ) ;
if ( V_11 )
goto V_63;
if ( V_66 ) {
F_29 ( V_55 , stdout ) ;
goto V_63;
}
if ( V_67 > 3 )
F_30 ( V_55 , stdout ) ;
if ( V_67 > 2 )
F_31 ( V_55 , stdout ) ;
V_57 = 0 ;
F_32 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_56 -> V_19 ;
T_2 V_68 = V_19 -> V_27 . V_69 [ V_30 ] ;
if ( V_68 > 0 ) {
V_57 += V_68 ;
F_33 ( V_19 ) ;
F_34 ( V_19 ) ;
if ( V_70 . V_71 &&
! F_35 ( V_56 ) )
continue;
F_16 ( V_19 , V_56 , V_8 ) ;
}
}
if ( V_57 == 0 ) {
F_36 ( L_4 , V_55 -> V_72 ) ;
goto V_63;
}
if ( V_52 == 2 )
F_37 () ;
V_63:
return V_11 ;
}
int F_38 ( int V_73 , const char * * V_74 , const char * T_3 V_75 )
{
struct V_7 V_76 = {
. V_32 = {
. V_4 = F_9 ,
. V_77 = V_78 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
. exit = V_83 ,
. V_84 = V_85 ,
. V_86 = true ,
. V_87 = true ,
} ,
} ;
const struct V_88 V_89 [] = {
F_39 ( 'i' , L_5 , & V_58 , L_6 ,
L_7 ) ,
F_39 ( 'd' , L_8 , & V_70 . V_90 , L_9 ,
L_10 ) ,
F_39 ( 's' , L_11 , & V_76 . V_12 , L_11 ,
L_12 ) ,
F_40 ( 'f' , L_13 , & V_76 . V_60 , L_14 ) ,
F_41 ( 'v' , L_15 , & V_67 ,
L_16 ) ,
F_40 ( 'D' , L_17 , & V_66 ,
L_18 ) ,
F_40 ( 0 , L_19 , & V_76 . V_91 , L_20 ) ,
F_40 ( 0 , L_21 , & V_76 . V_92 , L_22 ) ,
F_40 ( 0 , L_23 , & V_76 . V_93 , L_24 ) ,
F_39 ( 'k' , L_25 , & V_70 . V_94 ,
L_6 , L_26 ) ,
F_40 ( 'm' , L_27 , & V_70 . V_95 ,
L_28 ) ,
F_40 ( 'l' , L_29 , & V_76 . V_41 ,
L_30 ) ,
F_40 ( 'P' , L_31 , & V_76 . V_42 ,
L_32 ) ,
F_40 ( 0 , L_33 , & V_76 . V_53 ,
L_34 ) ,
F_39 ( 'C' , L_35 , & V_76 . V_37 , L_35 , L_36 ) ,
F_39 ( 0 , L_37 , & V_70 . V_96 , L_38 ,
L_39 ) ,
F_40 ( 0 , L_40 , & V_70 . V_97 ,
L_41 ) ,
F_40 ( 0 , L_42 , & V_70 . V_98 ,
L_43 ) ,
F_39 ( 'M' , L_44 , & V_99 , L_45 ,
L_46 ) ,
F_39 ( 0 , L_47 , & V_64 , L_48 ,
L_49 ) ,
F_40 ( 0 , L_50 , & V_70 . V_71 ,
L_51 ) ,
F_42 ()
} ;
V_73 = F_43 ( V_73 , V_74 , V_89 , V_100 , 0 ) ;
if ( V_76 . V_93 )
V_52 = 0 ;
else if ( V_76 . V_92 )
V_52 = 1 ;
else if ( V_76 . V_91 )
V_52 = 2 ;
F_44 ( true ) ;
V_70 . V_101 = sizeof( struct V_22 ) ;
V_70 . V_102 = true ;
if ( F_45 () < 0 )
return - 1 ;
if ( F_46 () < 0 )
F_47 ( V_100 , V_89 ) ;
if ( V_73 ) {
if ( V_73 > 1 )
F_47 ( V_100 , V_89 ) ;
V_76 . V_12 = V_74 [ 0 ] ;
}
return F_23 ( & V_76 ) ;
}
