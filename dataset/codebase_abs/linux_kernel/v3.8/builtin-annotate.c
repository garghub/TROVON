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
if ( V_54 > 0 ) {
V_49 = F_21 ( V_10 , V_42 , NULL ) ;
switch ( V_49 ) {
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
static int F_22 ( struct V_7 * V_8 )
{
int V_11 ;
struct V_55 * V_56 ;
struct V_1 * V_57 ;
T_1 V_58 ;
V_56 = F_23 ( V_59 , V_60 ,
V_8 -> V_61 , false , & V_8 -> V_32 ) ;
if ( V_56 == NULL )
return - V_20 ;
if ( V_8 -> V_38 ) {
V_11 = F_24 ( V_56 , V_8 -> V_38 ,
V_8 -> V_40 ) ;
if ( V_11 )
goto V_62;
}
if ( ! V_63 ) {
V_11 = F_25 ( & V_56 -> V_37 . V_64 ) ;
if ( V_11 )
goto V_62;
}
V_11 = F_26 ( V_56 , & V_8 -> V_32 ) ;
if ( V_11 )
goto V_62;
if ( V_65 ) {
F_27 ( V_56 , stdout ) ;
goto V_62;
}
if ( V_66 > 3 )
F_28 ( V_56 , stdout ) ;
if ( V_66 > 2 )
F_29 ( V_56 , stdout ) ;
V_58 = 0 ;
F_30 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_57 -> V_19 ;
T_2 V_67 = V_19 -> V_27 . V_68 [ V_30 ] ;
if ( V_67 > 0 ) {
V_58 += V_67 ;
F_31 ( V_19 ) ;
F_32 ( V_19 ) ;
F_16 ( V_19 , V_57 -> V_25 , V_8 ) ;
}
}
if ( V_58 == 0 ) {
F_33 ( L_4 , V_56 -> V_69 ) ;
goto V_62;
}
V_62:
return V_11 ;
}
int F_34 ( int V_70 , const char * * V_71 , const char * T_3 V_72 )
{
struct V_7 V_73 = {
. V_32 = {
. V_4 = F_9 ,
. V_74 = V_75 ,
. V_76 = V_77 ,
. exit = V_78 ,
. V_79 = V_80 ,
. V_81 = true ,
. V_82 = true ,
} ,
} ;
const struct V_83 V_84 [] = {
F_35 ( 'i' , L_5 , & V_59 , L_6 ,
L_7 ) ,
F_35 ( 'd' , L_8 , & V_85 . V_86 , L_9 ,
L_10 ) ,
F_35 ( 's' , L_11 , & V_73 . V_12 , L_11 ,
L_12 ) ,
F_36 ( 'f' , L_13 , & V_73 . V_61 , L_14 ) ,
F_37 ( 'v' , L_15 , & V_66 ,
L_16 ) ,
F_36 ( 'D' , L_17 , & V_65 ,
L_18 ) ,
F_36 ( 0 , L_19 , & V_73 . V_87 , L_20 ) ,
F_36 ( 0 , L_21 , & V_73 . V_88 , L_22 ) ,
F_35 ( 'k' , L_23 , & V_85 . V_89 ,
L_6 , L_24 ) ,
F_36 ( 'm' , L_25 , & V_85 . V_90 ,
L_26 ) ,
F_36 ( 'l' , L_27 , & V_73 . V_43 ,
L_28 ) ,
F_36 ( 'P' , L_29 , & V_73 . V_44 ,
L_30 ) ,
F_35 ( 'C' , L_31 , & V_73 . V_38 , L_31 , L_32 ) ,
F_35 ( 0 , L_33 , & V_85 . V_91 , L_34 ,
L_35 ) ,
F_36 ( 0 , L_36 , & V_85 . V_92 ,
L_37 ) ,
F_36 ( 0 , L_38 , & V_85 . V_93 ,
L_39 ) ,
F_35 ( 'M' , L_40 , & V_94 , L_41 ,
L_42 ) ,
F_35 ( 0 , L_43 , & V_63 , L_44 ,
L_45 ) ,
F_38 ()
} ;
V_70 = F_39 ( V_70 , V_71 , V_84 , V_95 , 0 ) ;
if ( V_73 . V_88 )
V_54 = 0 ;
else if ( V_73 . V_87 )
V_54 = 1 ;
F_40 ( true ) ;
V_85 . V_96 = sizeof( struct V_22 ) ;
V_85 . V_97 = true ;
if ( F_41 () < 0 )
return - 1 ;
F_42 ( V_95 , V_84 ) ;
if ( V_70 ) {
if ( V_70 > 1 )
F_43 ( V_95 , V_84 ) ;
V_73 . V_12 = V_71 [ 0 ] ;
}
return F_22 ( & V_73 ) ;
}
