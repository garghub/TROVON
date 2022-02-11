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
unsigned int V_36 ;
int V_37 = 0 , V_17 ;
struct V_22 * V_38 [ V_39 + 1 ] ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 = NULL , * V_46 = NULL ;
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_47 ;
if ( V_32 == NULL )
return - V_48 ;
V_17 = F_12 ( V_38 , V_39 , V_32 , V_49 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_38 [ V_50 ] == NULL )
return - V_48 ;
V_47 = F_13 ( V_38 [ V_50 ] ) ;
if ( V_47 != sizeof( * V_41 ) && V_47 != sizeof( struct V_51 ) )
return - V_48 ;
V_41 = F_14 ( V_38 [ V_50 ] ) ;
if ( V_41 -> V_18 ) {
if ( F_15 ( V_9 , V_7 , V_41 -> V_18 ) ) {
V_43 = F_16 ( V_7 -> V_27 ) ;
if ( V_35 ) {
V_43 -> V_52 += 1 ;
V_43 -> V_53 += 1 ;
return 0 ;
}
if ( V_34 )
goto V_54;
return - V_55 ;
}
}
V_43 = F_17 ( sizeof( * V_43 ) , V_56 ) ;
if ( V_43 == NULL )
return - V_57 ;
V_37 = V_58 ;
V_43 -> V_53 = 1 ;
F_18 ( & V_43 -> V_59 ) ;
if ( V_35 )
V_43 -> V_52 = 1 ;
V_54:
if ( V_41 -> V_60 . V_60 ) {
V_17 = - V_57 ;
V_45 = F_19 ( & V_41 -> V_60 , V_38 [ V_61 ] ) ;
if ( V_45 == NULL )
goto V_62;
if ( V_41 -> V_63 . V_60 ) {
V_46 = F_19 ( & V_41 -> V_63 ,
V_38 [ V_64 ] ) ;
if ( V_46 == NULL )
goto V_62;
}
}
F_3 ( & V_43 -> V_59 ) ;
if ( V_33 ) {
V_17 = F_20 ( & V_43 -> V_65 , NULL ,
& V_43 -> V_66 ,
& V_43 -> V_59 , V_33 ) ;
if ( V_17 )
goto V_67;
} else if ( V_38 [ V_68 ] &&
( V_37 == V_58 ||
! F_21 ( & V_43 -> V_65 ,
& V_43 -> V_66 ) ) ) {
V_17 = - V_48 ;
goto V_67;
}
V_43 -> V_69 = V_41 -> V_70 ;
if ( V_43 -> V_69 == 0 ) {
V_43 -> V_69 = ~ 0 ;
if ( V_45 )
V_43 -> V_69 = 255 << V_45 -> V_60 . V_71 ;
}
if ( V_45 ) {
V_43 -> V_72 = true ;
F_22 ( & V_43 -> V_60 , & V_45 -> V_60 , 0 ) ;
F_23 ( V_45 ) ;
} else {
V_43 -> V_72 = false ;
}
if ( V_46 ) {
V_43 -> V_73 = true ;
F_22 ( & V_43 -> V_74 , & V_46 -> V_60 , 0 ) ;
F_23 ( V_46 ) ;
} else {
V_43 -> V_73 = false ;
}
if ( V_38 [ V_75 ] )
V_43 -> V_76 = F_24 ( V_38 [ V_75 ] ) ;
V_43 -> V_77 = F_25 ( V_41 -> V_78 ) ;
V_43 -> V_79 = V_43 -> V_77 ;
if ( V_43 -> V_73 ) {
V_43 -> V_80 = ( V_81 ) F_26 ( & V_43 -> V_74 ,
V_43 -> V_69 ) ;
V_43 -> V_82 = V_43 -> V_80 ;
}
V_43 -> V_83 = V_41 -> V_84 ;
if ( V_38 [ V_68 ] )
V_43 -> V_85 = F_24 ( V_38 [ V_68 ] ) ;
F_10 ( & V_43 -> V_59 ) ;
if ( V_37 != V_58 )
return V_37 ;
V_43 -> V_86 = F_27 () ;
V_43 -> V_87 = V_41 -> V_18 ? V_41 -> V_18 :
F_28 ( V_9 ) ;
V_36 = F_4 ( V_43 -> V_87 , V_25 ) ;
F_3 ( & V_12 -> V_24 ) ;
F_29 ( & V_43 -> V_88 , & V_12 -> V_26 [ V_36 ] ) ;
F_10 ( & V_12 -> V_24 ) ;
V_7 -> V_27 = V_43 ;
return V_37 ;
V_67:
F_10 ( & V_43 -> V_59 ) ;
V_62:
F_23 ( V_46 ) ;
F_23 ( V_45 ) ;
if ( V_37 == V_58 )
F_30 ( V_43 ) ;
return V_17 ;
}
static int F_31 ( struct V_2 * V_3 , const struct V_6 * V_7 ,
struct V_89 * V_90 )
{
struct V_42 * V_43 = V_7 -> V_27 ;
V_81 V_91 ;
V_81 V_92 ;
V_81 V_93 = 0 ;
F_32 ( & V_43 -> V_59 ) ;
F_33 ( & V_43 -> V_65 , V_3 ) ;
if ( V_43 -> V_85 &&
V_43 -> V_66 . V_94 >= V_43 -> V_85 ) {
V_43 -> V_95 . V_96 ++ ;
if ( V_43 -> V_83 == V_97 )
V_43 -> V_95 . V_98 ++ ;
F_34 ( & V_43 -> V_59 ) ;
return V_43 -> V_83 ;
}
if ( F_35 ( V_3 ) <= V_43 -> V_69 ) {
if ( ! V_43 -> V_72 ) {
F_34 ( & V_43 -> V_59 ) ;
return V_43 -> V_76 ;
}
V_91 = F_27 () ;
V_92 = F_36 ( V_81 , V_91 - V_43 -> V_86 ,
V_43 -> V_77 ) ;
if ( V_43 -> V_73 ) {
V_93 = V_92 + V_43 -> V_82 ;
if ( V_93 > V_43 -> V_80 )
V_93 = V_43 -> V_80 ;
V_93 -= ( V_81 ) F_26 ( & V_43 -> V_74 ,
F_35 ( V_3 ) ) ;
}
V_92 += V_43 -> V_79 ;
if ( V_92 > V_43 -> V_77 )
V_92 = V_43 -> V_77 ;
V_92 -= ( V_81 ) F_26 ( & V_43 -> V_60 , F_35 ( V_3 ) ) ;
if ( ( V_92 | V_93 ) >= 0 ) {
V_43 -> V_86 = V_91 ;
V_43 -> V_79 = V_92 ;
V_43 -> V_82 = V_93 ;
F_34 ( & V_43 -> V_59 ) ;
return V_43 -> V_76 ;
}
}
V_43 -> V_95 . V_96 ++ ;
if ( V_43 -> V_83 == V_97 )
V_43 -> V_95 . V_98 ++ ;
F_34 ( & V_43 -> V_59 ) ;
return V_43 -> V_83 ;
}
static int
F_37 ( struct V_2 * V_3 , struct V_6 * V_7 , int V_35 , int V_99 )
{
unsigned char * V_100 = F_38 ( V_3 ) ;
struct V_42 * V_43 = V_7 -> V_27 ;
struct V_40 V_101 = {
. V_18 = V_43 -> V_87 ,
. V_84 = V_43 -> V_83 ,
. V_70 = V_43 -> V_69 ,
. V_78 = F_39 ( V_43 -> V_77 ) ,
. V_102 = V_43 -> V_53 - V_99 ,
. V_103 = V_43 -> V_52 - V_35 ,
} ;
if ( V_43 -> V_72 )
F_40 ( & V_101 . V_60 , & V_43 -> V_60 ) ;
if ( V_43 -> V_73 )
F_40 ( & V_101 . V_63 , & V_43 -> V_74 ) ;
if ( F_41 ( V_3 , V_50 , sizeof( V_101 ) , & V_101 ) )
goto V_29;
if ( V_43 -> V_76 &&
F_42 ( V_3 , V_75 , V_43 -> V_76 ) )
goto V_29;
if ( V_43 -> V_85 &&
F_42 ( V_3 , V_68 , V_43 -> V_85 ) )
goto V_29;
return V_3 -> V_104 ;
V_29:
F_43 ( V_3 , V_100 ) ;
return - 1 ;
}
static int F_44 ( struct V_1 * V_1 , struct V_6 * V_7 , T_1 V_18 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_15 ( V_9 , V_7 , V_18 ) ;
}
static T_2 int F_45 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
return F_46 ( V_9 , & V_105 , V_25 ) ;
}
static void T_3 F_47 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = F_2 ( V_1 , V_10 ) ;
F_48 ( V_9 ) ;
}
static int T_4
F_49 ( void )
{
return F_50 ( & V_105 , & V_106 ) ;
}
static void T_5
F_51 ( void )
{
F_52 ( & V_105 , & V_106 ) ;
}
