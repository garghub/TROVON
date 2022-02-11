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
if ( F_11 ( V_34 , V_35 , & V_6 , V_4 ,
V_36 ) < 0 ) {
F_12 ( L_1 ,
V_34 -> V_37 . type ) ;
return - 1 ;
}
if ( V_8 -> V_38 && ! F_13 ( V_4 -> V_39 , V_8 -> V_40 ) )
return 0 ;
if ( ! V_6 . V_41 && F_1 ( V_2 , V_4 , & V_6 , V_8 ) ) {
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
V_8 -> V_42 , V_8 -> V_43 , 0 , 0 ) ;
}
static void F_16 ( struct V_19 * V_44 ,
struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_15 * V_45 = F_17 ( & V_44 -> V_46 ) , * V_47 ;
int V_48 = V_49 ;
while ( V_45 ) {
struct V_9 * V_10 = F_18 ( V_45 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_50 )
goto V_51;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_51:
if ( V_48 == V_52 )
V_45 = F_19 ( V_45 ) ;
else
V_45 = F_20 ( V_45 ) ;
continue;
}
if ( V_53 == 2 ) {
int V_11 ;
V_11 = F_21 ( V_10 , V_2 , NULL ) ;
if ( ! V_11 || ! V_8 -> V_54 )
return;
V_45 = F_20 ( V_45 ) ;
} else if ( V_53 == 1 ) {
V_48 = F_22 ( V_10 , V_2 , NULL ) ;
switch ( V_48 ) {
case - 1 :
if ( ! V_8 -> V_54 )
return;
case V_49 :
V_47 = F_20 ( V_45 ) ;
break;
case V_52 :
V_47 = F_19 ( V_45 ) ;
break;
default:
return;
}
if ( V_47 != NULL )
V_45 = V_47 ;
} else {
F_14 ( V_10 , V_2 , V_8 ) ;
V_45 = F_20 ( V_45 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_23 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_55 * V_56 ;
struct V_1 * V_57 ;
T_1 V_58 ;
V_56 = F_24 ( V_59 , V_60 ,
V_8 -> V_61 , false , & V_8 -> V_32 ) ;
if ( V_56 == NULL )
return - V_20 ;
if ( V_8 -> V_38 ) {
V_11 = F_25 ( V_56 , V_8 -> V_38 ,
V_8 -> V_40 ) ;
if ( V_11 )
goto V_62;
}
if ( ! V_63 ) {
V_11 = F_26 ( & V_56 -> V_37 . V_64 ) ;
if ( V_11 )
goto V_62;
}
V_11 = F_27 ( V_56 , & V_8 -> V_32 ) ;
if ( V_11 )
goto V_62;
if ( V_65 ) {
F_28 ( V_56 , stdout ) ;
goto V_62;
}
if ( V_66 > 3 )
F_29 ( V_56 , stdout ) ;
if ( V_66 > 2 )
F_30 ( V_56 , stdout ) ;
V_58 = 0 ;
F_31 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_57 -> V_19 ;
T_2 V_67 = V_19 -> V_27 . V_68 [ V_30 ] ;
if ( V_67 > 0 ) {
V_58 += V_67 ;
F_32 ( V_19 ) ;
F_33 ( V_19 ) ;
if ( V_69 . V_70 &&
! F_34 ( V_57 ) )
continue;
F_16 ( V_19 , V_57 , V_8 ) ;
}
}
if ( V_58 == 0 ) {
F_35 ( L_4 , V_56 -> V_71 ) ;
goto V_62;
}
if ( V_53 == 2 )
F_36 () ;
V_62:
return V_11 ;
}
int F_37 ( int V_72 , const char * * V_73 , const char * T_3 V_74 )
{
struct V_7 V_75 = {
. V_32 = {
. V_4 = F_9 ,
. V_76 = V_77 ,
. V_78 = V_79 ,
. exit = V_80 ,
. V_81 = V_82 ,
. V_83 = true ,
. V_84 = true ,
} ,
} ;
const struct V_85 V_86 [] = {
F_38 ( 'i' , L_5 , & V_59 , L_6 ,
L_7 ) ,
F_38 ( 'd' , L_8 , & V_69 . V_87 , L_9 ,
L_10 ) ,
F_38 ( 's' , L_11 , & V_75 . V_12 , L_11 ,
L_12 ) ,
F_39 ( 'f' , L_13 , & V_75 . V_61 , L_14 ) ,
F_40 ( 'v' , L_15 , & V_66 ,
L_16 ) ,
F_39 ( 'D' , L_17 , & V_65 ,
L_18 ) ,
F_39 ( 0 , L_19 , & V_75 . V_88 , L_20 ) ,
F_39 ( 0 , L_21 , & V_75 . V_89 , L_22 ) ,
F_39 ( 0 , L_23 , & V_75 . V_90 , L_24 ) ,
F_38 ( 'k' , L_25 , & V_69 . V_91 ,
L_6 , L_26 ) ,
F_39 ( 'm' , L_27 , & V_69 . V_92 ,
L_28 ) ,
F_39 ( 'l' , L_29 , & V_75 . V_42 ,
L_30 ) ,
F_39 ( 'P' , L_31 , & V_75 . V_43 ,
L_32 ) ,
F_39 ( 0 , L_33 , & V_75 . V_54 ,
L_34 ) ,
F_38 ( 'C' , L_35 , & V_75 . V_38 , L_35 , L_36 ) ,
F_38 ( 0 , L_37 , & V_69 . V_93 , L_38 ,
L_39 ) ,
F_39 ( 0 , L_40 , & V_69 . V_94 ,
L_41 ) ,
F_39 ( 0 , L_42 , & V_69 . V_95 ,
L_43 ) ,
F_38 ( 'M' , L_44 , & V_96 , L_45 ,
L_46 ) ,
F_38 ( 0 , L_47 , & V_63 , L_48 ,
L_49 ) ,
F_39 ( 0 , L_50 , & V_69 . V_70 ,
L_51 ) ,
F_41 ()
} ;
V_72 = F_42 ( V_72 , V_73 , V_86 , V_97 , 0 ) ;
if ( V_75 . V_90 )
V_53 = 0 ;
else if ( V_75 . V_89 )
V_53 = 1 ;
else if ( V_75 . V_88 )
V_53 = 2 ;
F_43 ( true ) ;
V_69 . V_98 = sizeof( struct V_22 ) ;
V_69 . V_99 = true ;
if ( F_44 () < 0 )
return - 1 ;
if ( F_45 () < 0 )
F_46 ( V_97 , V_86 ) ;
if ( V_72 ) {
if ( V_72 > 1 )
F_46 ( V_97 , V_86 ) ;
V_75 . V_12 = V_73 [ 0 ] ;
}
return F_23 ( & V_75 ) ;
}
