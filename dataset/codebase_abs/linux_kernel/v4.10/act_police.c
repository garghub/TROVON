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
V_19 = F_5 ( V_20 , V_21 , V_12 , V_32 ) ;
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
F_13 ( & V_25 -> V_45 ) ;
if ( V_13 ) {
V_19 = F_14 ( & V_25 -> V_46 , NULL ,
& V_25 -> V_47 ,
& V_25 -> V_45 ,
NULL , V_13 ) ;
if ( V_19 )
goto V_48;
} else if ( V_20 [ V_49 ] &&
( V_18 == V_37 ||
! F_15 ( & V_25 -> V_47 ) ) ) {
V_19 = - V_31 ;
goto V_48;
}
V_25 -> V_50 = V_23 -> V_51 ;
if ( V_25 -> V_50 == 0 ) {
V_25 -> V_50 = ~ 0 ;
if ( V_27 )
V_25 -> V_50 = 255 << V_27 -> V_39 . V_52 ;
}
if ( V_27 ) {
V_25 -> V_53 = true ;
F_16 ( & V_25 -> V_39 , & V_27 -> V_39 , 0 ) ;
F_17 ( V_27 ) ;
} else {
V_25 -> V_53 = false ;
}
if ( V_28 ) {
V_25 -> V_54 = true ;
F_16 ( & V_25 -> V_55 , & V_28 -> V_39 , 0 ) ;
F_17 ( V_28 ) ;
} else {
V_25 -> V_54 = false ;
}
if ( V_20 [ V_56 ] )
V_25 -> V_57 = F_18 ( V_20 [ V_56 ] ) ;
V_25 -> V_58 = F_19 ( V_23 -> V_59 ) ;
V_25 -> V_60 = V_25 -> V_58 ;
if ( V_25 -> V_54 ) {
V_25 -> V_61 = ( V_62 ) F_20 ( & V_25 -> V_55 ,
V_25 -> V_50 ) ;
V_25 -> V_63 = V_25 -> V_61 ;
}
V_25 -> V_64 = V_23 -> V_65 ;
if ( V_20 [ V_49 ] )
V_25 -> V_66 = F_18 ( V_20 [ V_49 ] ) ;
F_21 ( & V_25 -> V_45 ) ;
if ( V_18 != V_37 )
return V_18 ;
V_25 -> V_67 = F_22 () ;
F_23 ( V_9 , * V_15 ) ;
return V_18 ;
V_48:
F_21 ( & V_25 -> V_45 ) ;
V_42:
F_17 ( V_28 ) ;
F_17 ( V_27 ) ;
if ( V_18 == V_37 )
F_24 ( * V_15 , V_13 ) ;
return V_19 ;
}
static int F_25 ( struct V_2 * V_3 , const struct V_14 * V_15 ,
struct V_68 * V_69 )
{
struct V_24 * V_25 = F_11 ( V_15 ) ;
V_62 V_70 ;
V_62 V_71 ;
V_62 V_72 = 0 ;
F_26 ( & V_25 -> V_45 ) ;
F_27 ( & V_25 -> V_46 , V_3 ) ;
F_28 ( & V_25 -> V_73 ) ;
if ( V_25 -> V_66 ) {
struct V_74 V_75 ;
if ( ! F_29 ( & V_25 -> V_47 , & V_75 ) ||
V_75 . V_76 >= V_25 -> V_66 ) {
V_25 -> V_77 . V_78 ++ ;
if ( V_25 -> V_64 == V_79 )
V_25 -> V_77 . V_80 ++ ;
F_30 ( & V_25 -> V_45 ) ;
return V_25 -> V_64 ;
}
}
if ( F_31 ( V_3 ) <= V_25 -> V_50 ) {
if ( ! V_25 -> V_53 ) {
F_30 ( & V_25 -> V_45 ) ;
return V_25 -> V_57 ;
}
V_70 = F_22 () ;
V_71 = F_32 ( V_62 , V_70 - V_25 -> V_67 ,
V_25 -> V_58 ) ;
if ( V_25 -> V_54 ) {
V_72 = V_71 + V_25 -> V_63 ;
if ( V_72 > V_25 -> V_61 )
V_72 = V_25 -> V_61 ;
V_72 -= ( V_62 ) F_20 ( & V_25 -> V_55 ,
F_31 ( V_3 ) ) ;
}
V_71 += V_25 -> V_60 ;
if ( V_71 > V_25 -> V_58 )
V_71 = V_25 -> V_58 ;
V_71 -= ( V_62 ) F_20 ( & V_25 -> V_39 , F_31 ( V_3 ) ) ;
if ( ( V_71 | V_72 ) >= 0 ) {
V_25 -> V_67 = V_70 ;
V_25 -> V_60 = V_71 ;
V_25 -> V_63 = V_72 ;
if ( V_25 -> V_57 == V_79 )
V_25 -> V_77 . V_80 ++ ;
F_30 ( & V_25 -> V_45 ) ;
return V_25 -> V_57 ;
}
}
V_25 -> V_77 . V_78 ++ ;
if ( V_25 -> V_64 == V_79 )
V_25 -> V_77 . V_80 ++ ;
F_30 ( & V_25 -> V_45 ) ;
return V_25 -> V_64 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int V_17 , int V_81 )
{
unsigned char * V_82 = F_34 ( V_3 ) ;
struct V_24 * V_25 = F_11 ( V_15 ) ;
struct V_22 V_83 = {
. V_35 = V_25 -> V_84 ,
. V_65 = V_25 -> V_64 ,
. V_51 = V_25 -> V_50 ,
. V_59 = F_35 ( V_25 -> V_58 ) ,
. V_85 = V_25 -> V_86 - V_81 ,
. V_87 = V_25 -> V_88 - V_17 ,
} ;
struct V_89 V_90 ;
if ( V_25 -> V_53 )
F_36 ( & V_83 . V_39 , & V_25 -> V_39 ) ;
if ( V_25 -> V_54 )
F_36 ( & V_83 . V_43 , & V_25 -> V_55 ) ;
if ( F_37 ( V_3 , V_33 , sizeof( V_83 ) , & V_83 ) )
goto V_91;
if ( V_25 -> V_57 &&
F_38 ( V_3 , V_56 , V_25 -> V_57 ) )
goto V_91;
if ( V_25 -> V_66 &&
F_38 ( V_3 , V_49 , V_25 -> V_66 ) )
goto V_91;
V_90 . V_92 = F_39 ( V_93 - V_25 -> V_73 . V_92 ) ;
V_90 . V_94 = F_39 ( V_93 - V_25 -> V_73 . V_94 ) ;
V_90 . V_95 = F_39 ( V_93 - V_25 -> V_73 . V_95 ) ;
V_90 . V_96 = F_39 ( V_25 -> V_73 . V_96 ) ;
if ( F_40 ( V_3 , V_97 , sizeof( V_90 ) , & V_90 , V_98 ) )
goto V_91;
return V_3 -> V_99 ;
V_91:
F_41 ( V_3 , V_82 ) ;
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
return F_45 ( V_9 , & V_36 , V_100 ) ;
}
static void T_3 F_46 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
F_47 ( V_9 ) ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_36 , & V_101 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_36 , & V_101 ) ;
}
