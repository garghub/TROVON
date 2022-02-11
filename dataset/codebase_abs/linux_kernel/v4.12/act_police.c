static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , int type ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_3 ( V_9 , V_3 , V_5 , type , V_7 ) ;
}
static int F_4 ( struct V_1 * V_1 , struct V_11 * V_12 ,
struct V_11 * V_13 , struct V_14 * * V_15 ,
int V_16 , int V_17 )
{
int V_18 = 0 , V_19 ;
struct V_11 * V_20 [ V_21 + 1 ] ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = NULL , * V_28 = NULL ;
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
bool V_29 = false ;
int V_30 ;
if ( V_12 == NULL )
return - V_31 ;
V_19 = F_5 ( V_20 , V_21 , V_12 , V_32 , NULL ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_20 [ V_33 ] == NULL )
return - V_31 ;
V_30 = F_6 ( V_20 [ V_33 ] ) ;
if ( V_30 != sizeof( * V_23 ) && V_30 != sizeof( struct V_34 ) )
return - V_31 ;
V_23 = F_7 ( V_20 [ V_33 ] ) ;
V_29 = F_8 ( V_9 , V_23 -> V_35 , V_15 , V_17 ) ;
if ( V_29 && V_17 )
return 0 ;
if ( ! V_29 ) {
V_18 = F_9 ( V_9 , V_23 -> V_35 , NULL , V_15 ,
& V_36 , V_17 , false ) ;
if ( V_18 )
return V_18 ;
V_18 = V_37 ;
} else {
F_10 ( * V_15 , V_17 ) ;
if ( ! V_16 )
return - V_38 ;
}
V_25 = F_11 ( * V_15 ) ;
if ( V_23 -> V_39 . V_39 ) {
V_19 = - V_40 ;
V_27 = F_12 ( & V_23 -> V_39 , V_20 [ V_41 ] ) ;
if ( V_27 == NULL )
goto V_42;
if ( V_23 -> V_43 . V_39 ) {
V_28 = F_12 ( & V_23 -> V_43 ,
V_20 [ V_44 ] ) ;
if ( V_28 == NULL )
goto V_42;
}
}
if ( V_13 ) {
V_19 = F_13 ( & V_25 -> V_45 , NULL ,
& V_25 -> V_46 ,
& V_25 -> V_47 ,
NULL , V_13 ) ;
if ( V_19 )
goto V_42;
} else if ( V_20 [ V_48 ] &&
( V_18 == V_37 ||
! F_14 ( & V_25 -> V_46 ) ) ) {
V_19 = - V_31 ;
goto V_42;
}
F_15 ( & V_25 -> V_47 ) ;
V_25 -> V_49 = V_23 -> V_50 ;
if ( V_25 -> V_49 == 0 ) {
V_25 -> V_49 = ~ 0 ;
if ( V_27 )
V_25 -> V_49 = 255 << V_27 -> V_39 . V_51 ;
}
if ( V_27 ) {
V_25 -> V_52 = true ;
F_16 ( & V_25 -> V_39 , & V_27 -> V_39 , 0 ) ;
F_17 ( V_27 ) ;
} else {
V_25 -> V_52 = false ;
}
if ( V_28 ) {
V_25 -> V_53 = true ;
F_16 ( & V_25 -> V_54 , & V_28 -> V_39 , 0 ) ;
F_17 ( V_28 ) ;
} else {
V_25 -> V_53 = false ;
}
if ( V_20 [ V_55 ] )
V_25 -> V_56 = F_18 ( V_20 [ V_55 ] ) ;
V_25 -> V_57 = F_19 ( V_23 -> V_58 ) ;
V_25 -> V_59 = V_25 -> V_57 ;
if ( V_25 -> V_53 ) {
V_25 -> V_60 = ( V_61 ) F_20 ( & V_25 -> V_54 ,
V_25 -> V_49 ) ;
V_25 -> V_62 = V_25 -> V_60 ;
}
V_25 -> V_63 = V_23 -> V_64 ;
if ( V_20 [ V_48 ] )
V_25 -> V_65 = F_18 ( V_20 [ V_48 ] ) ;
F_21 ( & V_25 -> V_47 ) ;
if ( V_18 != V_37 )
return V_18 ;
V_25 -> V_66 = F_22 () ;
F_23 ( V_9 , * V_15 ) ;
return V_18 ;
V_42:
F_17 ( V_28 ) ;
F_17 ( V_27 ) ;
if ( V_18 == V_37 )
F_24 ( * V_15 , V_13 ) ;
return V_19 ;
}
static int F_25 ( struct V_2 * V_3 , const struct V_14 * V_15 ,
struct V_67 * V_68 )
{
struct V_24 * V_25 = F_11 ( V_15 ) ;
V_61 V_69 ;
V_61 V_70 ;
V_61 V_71 = 0 ;
F_26 ( & V_25 -> V_47 ) ;
F_27 ( & V_25 -> V_45 , V_3 ) ;
F_28 ( & V_25 -> V_72 ) ;
if ( V_25 -> V_65 ) {
struct V_73 V_74 ;
if ( ! F_29 ( & V_25 -> V_46 , & V_74 ) ||
V_74 . V_75 >= V_25 -> V_65 ) {
V_25 -> V_76 . V_77 ++ ;
if ( V_25 -> V_63 == V_78 )
V_25 -> V_76 . V_79 ++ ;
F_30 ( & V_25 -> V_47 ) ;
return V_25 -> V_63 ;
}
}
if ( F_31 ( V_3 ) <= V_25 -> V_49 ) {
if ( ! V_25 -> V_52 ) {
F_30 ( & V_25 -> V_47 ) ;
return V_25 -> V_56 ;
}
V_69 = F_22 () ;
V_70 = F_32 ( V_61 , V_69 - V_25 -> V_66 ,
V_25 -> V_57 ) ;
if ( V_25 -> V_53 ) {
V_71 = V_70 + V_25 -> V_62 ;
if ( V_71 > V_25 -> V_60 )
V_71 = V_25 -> V_60 ;
V_71 -= ( V_61 ) F_20 ( & V_25 -> V_54 ,
F_31 ( V_3 ) ) ;
}
V_70 += V_25 -> V_59 ;
if ( V_70 > V_25 -> V_57 )
V_70 = V_25 -> V_57 ;
V_70 -= ( V_61 ) F_20 ( & V_25 -> V_39 , F_31 ( V_3 ) ) ;
if ( ( V_70 | V_71 ) >= 0 ) {
V_25 -> V_66 = V_69 ;
V_25 -> V_59 = V_70 ;
V_25 -> V_62 = V_71 ;
if ( V_25 -> V_56 == V_78 )
V_25 -> V_76 . V_79 ++ ;
F_30 ( & V_25 -> V_47 ) ;
return V_25 -> V_56 ;
}
}
V_25 -> V_76 . V_77 ++ ;
if ( V_25 -> V_63 == V_78 )
V_25 -> V_76 . V_79 ++ ;
F_30 ( & V_25 -> V_47 ) ;
return V_25 -> V_63 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int V_17 , int V_80 )
{
unsigned char * V_81 = F_34 ( V_3 ) ;
struct V_24 * V_25 = F_11 ( V_15 ) ;
struct V_22 V_82 = {
. V_35 = V_25 -> V_83 ,
. V_64 = V_25 -> V_63 ,
. V_50 = V_25 -> V_49 ,
. V_58 = F_35 ( V_25 -> V_57 ) ,
. V_84 = V_25 -> V_85 - V_80 ,
. V_86 = V_25 -> V_87 - V_17 ,
} ;
struct V_88 V_89 ;
if ( V_25 -> V_52 )
F_36 ( & V_82 . V_39 , & V_25 -> V_39 ) ;
if ( V_25 -> V_53 )
F_36 ( & V_82 . V_43 , & V_25 -> V_54 ) ;
if ( F_37 ( V_3 , V_33 , sizeof( V_82 ) , & V_82 ) )
goto V_90;
if ( V_25 -> V_56 &&
F_38 ( V_3 , V_55 , V_25 -> V_56 ) )
goto V_90;
if ( V_25 -> V_65 &&
F_38 ( V_3 , V_48 , V_25 -> V_65 ) )
goto V_90;
V_89 . V_91 = F_39 ( V_92 - V_25 -> V_72 . V_91 ) ;
V_89 . V_93 = F_39 ( V_92 - V_25 -> V_72 . V_93 ) ;
V_89 . V_94 = F_39 ( V_92 - V_25 -> V_72 . V_94 ) ;
V_89 . V_95 = F_39 ( V_25 -> V_72 . V_95 ) ;
if ( F_40 ( V_3 , V_96 , sizeof( V_89 ) , & V_89 , V_97 ) )
goto V_90;
return V_3 -> V_98 ;
V_90:
F_41 ( V_3 , V_81 ) ;
return - 1 ;
}
static int F_42 ( struct V_1 * V_1 , struct V_14 * * V_15 , T_1 V_35 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_43 ( V_9 , V_15 , V_35 ) ;
}
static T_2 int F_44 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_45 ( V_9 , & V_36 , V_99 ) ;
}
static void T_3 F_46 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
F_47 ( V_9 ) ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_36 , & V_100 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_36 , & V_100 ) ;
}
