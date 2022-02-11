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
V_10 = F_4 ( & V_2 -> V_19 , V_6 , NULL , 1 ) ;
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
static int F_14 ( struct V_9 * V_10 , int V_42 ,
struct V_7 * V_8 )
{
return F_15 ( V_10 -> V_21 . V_13 , V_10 -> V_21 . V_16 , V_42 ,
V_8 -> V_43 , V_8 -> V_44 , 0 , 0 ) ;
}
static void F_16 ( struct V_19 * V_45 , int V_42 ,
struct V_7 * V_8 )
{
struct V_15 * V_46 = F_17 ( & V_45 -> V_47 ) , * V_48 ;
int V_49 = V_50 ;
while ( V_46 ) {
struct V_9 * V_10 = F_18 ( V_46 , struct V_9 , V_15 ) ;
struct V_22 * V_23 ;
if ( V_10 -> V_21 . V_13 == NULL || V_10 -> V_21 . V_16 -> V_17 -> V_51 )
goto V_52;
V_23 = F_5 ( V_10 -> V_21 . V_13 ) ;
if ( V_23 -> V_24 == NULL ) {
V_52:
if ( V_49 == V_53 )
V_46 = F_19 ( V_46 ) ;
else
V_46 = F_20 ( V_46 ) ;
continue;
}
if ( V_54 == 2 ) {
int V_11 ;
V_11 = F_21 ( V_10 , V_42 , NULL ) ;
if ( ! V_11 || ! V_8 -> V_55 )
return;
V_46 = F_20 ( V_46 ) ;
} else if ( V_54 == 1 ) {
V_49 = F_22 ( V_10 , V_42 , NULL ) ;
switch ( V_49 ) {
case - 1 :
if ( ! V_8 -> V_55 )
return;
case V_50 :
V_48 = F_20 ( V_46 ) ;
break;
case V_53 :
V_48 = F_19 ( V_46 ) ;
break;
default:
return;
}
if ( V_48 != NULL )
V_46 = V_48 ;
} else {
F_14 ( V_10 , V_42 , V_8 ) ;
V_46 = F_20 ( V_46 ) ;
free ( V_23 -> V_24 ) ;
V_23 -> V_24 = NULL ;
}
}
}
static int F_23 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_56 * V_57 ;
struct V_1 * V_58 ;
T_1 V_59 ;
V_57 = F_24 ( V_60 , V_61 ,
V_8 -> V_62 , false , & V_8 -> V_32 ) ;
if ( V_57 == NULL )
return - V_20 ;
if ( V_8 -> V_38 ) {
V_11 = F_25 ( V_57 , V_8 -> V_38 ,
V_8 -> V_40 ) ;
if ( V_11 )
goto V_63;
}
if ( ! V_64 ) {
V_11 = F_26 ( & V_57 -> V_37 . V_65 ) ;
if ( V_11 )
goto V_63;
}
V_11 = F_27 ( V_57 , & V_8 -> V_32 ) ;
if ( V_11 )
goto V_63;
if ( V_66 ) {
F_28 ( V_57 , stdout ) ;
goto V_63;
}
if ( V_67 > 3 )
F_29 ( V_57 , stdout ) ;
if ( V_67 > 2 )
F_30 ( V_57 , stdout ) ;
V_59 = 0 ;
F_31 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_58 -> V_19 ;
T_2 V_68 = V_19 -> V_27 . V_69 [ V_30 ] ;
if ( V_68 > 0 ) {
V_59 += V_68 ;
F_32 ( V_19 ) ;
F_33 ( V_19 ) ;
F_16 ( V_19 , V_58 -> V_25 , V_8 ) ;
}
}
if ( V_59 == 0 ) {
F_34 ( L_4 , V_57 -> V_70 ) ;
goto V_63;
}
if ( V_54 == 2 )
F_35 () ;
V_63:
return V_11 ;
}
int F_36 ( int V_71 , const char * * V_72 , const char * T_3 V_73 )
{
struct V_7 V_74 = {
. V_32 = {
. V_4 = F_9 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
. exit = V_79 ,
. V_80 = V_81 ,
. V_82 = true ,
. V_83 = true ,
} ,
} ;
const struct V_84 V_85 [] = {
F_37 ( 'i' , L_5 , & V_60 , L_6 ,
L_7 ) ,
F_37 ( 'd' , L_8 , & V_86 . V_87 , L_9 ,
L_10 ) ,
F_37 ( 's' , L_11 , & V_74 . V_12 , L_11 ,
L_12 ) ,
F_38 ( 'f' , L_13 , & V_74 . V_62 , L_14 ) ,
F_39 ( 'v' , L_15 , & V_67 ,
L_16 ) ,
F_38 ( 'D' , L_17 , & V_66 ,
L_18 ) ,
F_38 ( 0 , L_19 , & V_74 . V_88 , L_20 ) ,
F_38 ( 0 , L_21 , & V_74 . V_89 , L_22 ) ,
F_38 ( 0 , L_23 , & V_74 . V_90 , L_24 ) ,
F_37 ( 'k' , L_25 , & V_86 . V_91 ,
L_6 , L_26 ) ,
F_38 ( 'm' , L_27 , & V_86 . V_92 ,
L_28 ) ,
F_38 ( 'l' , L_29 , & V_74 . V_43 ,
L_30 ) ,
F_38 ( 'P' , L_31 , & V_74 . V_44 ,
L_32 ) ,
F_38 ( 0 , L_33 , & V_74 . V_55 ,
L_34 ) ,
F_37 ( 'C' , L_35 , & V_74 . V_38 , L_35 , L_36 ) ,
F_37 ( 0 , L_37 , & V_86 . V_93 , L_38 ,
L_39 ) ,
F_38 ( 0 , L_40 , & V_86 . V_94 ,
L_41 ) ,
F_38 ( 0 , L_42 , & V_86 . V_95 ,
L_43 ) ,
F_37 ( 'M' , L_44 , & V_96 , L_45 ,
L_46 ) ,
F_37 ( 0 , L_47 , & V_64 , L_48 ,
L_49 ) ,
F_40 ()
} ;
V_71 = F_41 ( V_71 , V_72 , V_85 , V_97 , 0 ) ;
if ( V_74 . V_90 )
V_54 = 0 ;
else if ( V_74 . V_89 )
V_54 = 1 ;
else if ( V_74 . V_88 )
V_54 = 2 ;
F_42 ( true ) ;
V_86 . V_98 = sizeof( struct V_22 ) ;
V_86 . V_99 = true ;
if ( F_43 () < 0 )
return - 1 ;
if ( F_44 () < 0 )
F_45 ( V_97 , V_85 ) ;
if ( V_71 ) {
if ( V_71 > 1 )
F_45 ( V_97 , V_85 ) ;
V_74 . V_12 = V_72 [ 0 ] ;
}
return F_23 ( & V_74 ) ;
}
