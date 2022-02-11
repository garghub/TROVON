static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , int type ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 = 0 , V_18 = - 1 , V_19 = 0 , V_20 = 0 , V_21 = 0 ;
struct V_22 * V_23 ;
F_3 ( & V_12 -> V_24 ) ;
V_20 = V_5 -> args [ 0 ] ;
for ( V_19 = 0 ; V_19 < ( V_25 + 1 ) ; V_19 ++ ) {
V_14 = & V_12 -> V_26 [ F_4 ( V_19 , V_25 ) ] ;
F_5 (p, head, tcfc_head) {
V_18 ++ ;
if ( V_18 < V_20 )
continue;
V_7 -> V_27 = V_16 ;
V_7 -> V_28 = V_18 ;
V_23 = F_6 ( V_3 , V_7 -> V_28 ) ;
if ( V_23 == NULL )
goto V_29;
if ( type == V_30 )
V_17 = F_7 ( V_3 , V_7 , 0 , 1 ) ;
else
V_17 = F_7 ( V_3 , V_7 , 0 , 0 ) ;
if ( V_17 < 0 ) {
V_18 -- ;
F_8 ( V_3 , V_23 ) ;
goto V_31;
}
F_9 ( V_3 , V_23 ) ;
V_21 ++ ;
}
}
V_31:
F_10 ( & V_12 -> V_24 ) ;
if ( V_21 )
V_5 -> args [ 0 ] += V_21 ;
return V_21 ;
V_29:
F_8 ( V_3 , V_23 ) ;
goto V_31;
}
static int F_11 ( struct V_1 * V_1 , struct V_22 * V_32 ,
struct V_22 * V_33 , struct V_6 * V_7 ,
int V_34 , int V_35 )
{
int V_36 = 0 , V_17 ;
struct V_22 * V_37 [ V_38 + 1 ] ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 = NULL , * V_45 = NULL ;
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
int V_46 ;
if ( V_32 == NULL )
return - V_47 ;
V_17 = F_12 ( V_37 , V_38 , V_32 , V_48 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_37 [ V_49 ] == NULL )
return - V_47 ;
V_46 = F_13 ( V_37 [ V_49 ] ) ;
if ( V_46 != sizeof( * V_40 ) && V_46 != sizeof( struct V_50 ) )
return - V_47 ;
V_40 = F_14 ( V_37 [ V_49 ] ) ;
if ( V_40 -> V_18 ) {
if ( F_15 ( V_9 , V_7 , V_40 -> V_18 ) ) {
V_42 = F_16 ( V_7 ) ;
if ( V_35 ) {
V_42 -> V_51 += 1 ;
V_42 -> V_52 += 1 ;
return 0 ;
}
if ( V_34 )
goto V_53;
return - V_54 ;
}
} else {
V_36 = F_17 ( V_9 , V_40 -> V_18 , NULL , V_7 ,
sizeof( * V_42 ) , V_35 , false ) ;
if ( V_36 )
return V_36 ;
V_36 = V_55 ;
}
V_42 = F_16 ( V_7 ) ;
V_53:
if ( V_40 -> V_56 . V_56 ) {
V_17 = - V_57 ;
V_44 = F_18 ( & V_40 -> V_56 , V_37 [ V_58 ] ) ;
if ( V_44 == NULL )
goto V_59;
if ( V_40 -> V_60 . V_56 ) {
V_45 = F_18 ( & V_40 -> V_60 ,
V_37 [ V_61 ] ) ;
if ( V_45 == NULL )
goto V_59;
}
}
F_3 ( & V_42 -> V_62 ) ;
if ( V_33 ) {
V_17 = F_19 ( & V_42 -> V_63 , NULL ,
& V_42 -> V_64 ,
& V_42 -> V_62 , V_33 ) ;
if ( V_17 )
goto V_65;
} else if ( V_37 [ V_66 ] &&
( V_36 == V_55 ||
! F_20 ( & V_42 -> V_63 ,
& V_42 -> V_64 ) ) ) {
V_17 = - V_47 ;
goto V_65;
}
V_42 -> V_67 = V_40 -> V_68 ;
if ( V_42 -> V_67 == 0 ) {
V_42 -> V_67 = ~ 0 ;
if ( V_44 )
V_42 -> V_67 = 255 << V_44 -> V_56 . V_69 ;
}
if ( V_44 ) {
V_42 -> V_70 = true ;
F_21 ( & V_42 -> V_56 , & V_44 -> V_56 , 0 ) ;
F_22 ( V_44 ) ;
} else {
V_42 -> V_70 = false ;
}
if ( V_45 ) {
V_42 -> V_71 = true ;
F_21 ( & V_42 -> V_72 , & V_45 -> V_56 , 0 ) ;
F_22 ( V_45 ) ;
} else {
V_42 -> V_71 = false ;
}
if ( V_37 [ V_73 ] )
V_42 -> V_74 = F_23 ( V_37 [ V_73 ] ) ;
V_42 -> V_75 = F_24 ( V_40 -> V_76 ) ;
V_42 -> V_77 = V_42 -> V_75 ;
if ( V_42 -> V_71 ) {
V_42 -> V_78 = ( V_79 ) F_25 ( & V_42 -> V_72 ,
V_42 -> V_67 ) ;
V_42 -> V_80 = V_42 -> V_78 ;
}
V_42 -> V_81 = V_40 -> V_82 ;
if ( V_37 [ V_66 ] )
V_42 -> V_83 = F_23 ( V_37 [ V_66 ] ) ;
F_10 ( & V_42 -> V_62 ) ;
if ( V_36 != V_55 )
return V_36 ;
V_42 -> V_84 = F_26 () ;
F_27 ( V_9 , V_7 ) ;
return V_36 ;
V_65:
F_10 ( & V_42 -> V_62 ) ;
V_59:
F_22 ( V_45 ) ;
F_22 ( V_44 ) ;
if ( V_36 == V_55 )
F_28 ( V_7 , V_33 ) ;
return V_17 ;
}
static int F_29 ( struct V_2 * V_3 , const struct V_6 * V_7 ,
struct V_85 * V_86 )
{
struct V_41 * V_42 = V_7 -> V_27 ;
V_79 V_87 ;
V_79 V_88 ;
V_79 V_89 = 0 ;
F_30 ( & V_42 -> V_62 ) ;
F_31 ( & V_42 -> V_63 , V_3 ) ;
F_32 ( & V_42 -> V_90 ) ;
if ( V_42 -> V_83 &&
V_42 -> V_64 . V_91 >= V_42 -> V_83 ) {
V_42 -> V_92 . V_93 ++ ;
if ( V_42 -> V_81 == V_94 )
V_42 -> V_92 . V_95 ++ ;
F_33 ( & V_42 -> V_62 ) ;
return V_42 -> V_81 ;
}
if ( F_34 ( V_3 ) <= V_42 -> V_67 ) {
if ( ! V_42 -> V_70 ) {
F_33 ( & V_42 -> V_62 ) ;
return V_42 -> V_74 ;
}
V_87 = F_26 () ;
V_88 = F_35 ( V_79 , V_87 - V_42 -> V_84 ,
V_42 -> V_75 ) ;
if ( V_42 -> V_71 ) {
V_89 = V_88 + V_42 -> V_80 ;
if ( V_89 > V_42 -> V_78 )
V_89 = V_42 -> V_78 ;
V_89 -= ( V_79 ) F_25 ( & V_42 -> V_72 ,
F_34 ( V_3 ) ) ;
}
V_88 += V_42 -> V_77 ;
if ( V_88 > V_42 -> V_75 )
V_88 = V_42 -> V_75 ;
V_88 -= ( V_79 ) F_25 ( & V_42 -> V_56 , F_34 ( V_3 ) ) ;
if ( ( V_88 | V_89 ) >= 0 ) {
V_42 -> V_84 = V_87 ;
V_42 -> V_77 = V_88 ;
V_42 -> V_80 = V_89 ;
F_33 ( & V_42 -> V_62 ) ;
return V_42 -> V_74 ;
}
}
V_42 -> V_92 . V_93 ++ ;
if ( V_42 -> V_81 == V_94 )
V_42 -> V_92 . V_95 ++ ;
F_33 ( & V_42 -> V_62 ) ;
return V_42 -> V_81 ;
}
static int
F_36 ( struct V_2 * V_3 , struct V_6 * V_7 , int V_35 , int V_96 )
{
unsigned char * V_97 = F_37 ( V_3 ) ;
struct V_41 * V_42 = V_7 -> V_27 ;
struct V_39 V_98 = {
. V_18 = V_42 -> V_99 ,
. V_82 = V_42 -> V_81 ,
. V_68 = V_42 -> V_67 ,
. V_76 = F_38 ( V_42 -> V_75 ) ,
. V_100 = V_42 -> V_52 - V_96 ,
. V_101 = V_42 -> V_51 - V_35 ,
} ;
struct V_102 V_103 ;
if ( V_42 -> V_70 )
F_39 ( & V_98 . V_56 , & V_42 -> V_56 ) ;
if ( V_42 -> V_71 )
F_39 ( & V_98 . V_60 , & V_42 -> V_72 ) ;
if ( F_40 ( V_3 , V_49 , sizeof( V_98 ) , & V_98 ) )
goto V_29;
if ( V_42 -> V_74 &&
F_41 ( V_3 , V_73 , V_42 -> V_74 ) )
goto V_29;
if ( V_42 -> V_83 &&
F_41 ( V_3 , V_66 , V_42 -> V_83 ) )
goto V_29;
V_103 . V_104 = F_42 ( V_105 - V_42 -> V_90 . V_104 ) ;
V_103 . V_106 = F_42 ( V_105 - V_42 -> V_90 . V_106 ) ;
V_103 . V_107 = F_42 ( V_42 -> V_90 . V_107 ) ;
if ( F_43 ( V_3 , V_108 , sizeof( V_103 ) , & V_103 , V_109 ) )
goto V_29;
return V_3 -> V_110 ;
V_29:
F_44 ( V_3 , V_97 ) ;
return - 1 ;
}
static int F_45 ( struct V_1 * V_1 , struct V_6 * V_7 , T_1 V_18 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_15 ( V_9 , V_7 , V_18 ) ;
}
static T_2 int F_46 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_47 ( V_9 , & V_111 , V_25 ) ;
}
static void T_3 F_48 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
F_49 ( V_9 ) ;
}
static int T_4
F_50 ( void )
{
return F_51 ( & V_111 , & V_112 ) ;
}
static void T_5
F_52 ( void )
{
F_53 ( & V_111 , & V_112 ) ;
}
