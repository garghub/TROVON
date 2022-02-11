static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int type , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 -> V_8 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 , V_15 = - 1 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
struct V_19 * V_20 ;
F_2 ( & V_8 -> V_21 ) ;
V_17 = V_4 -> args [ 0 ] ;
for ( V_16 = 0 ; V_16 < ( V_22 + 1 ) ; V_16 ++ ) {
V_11 = & V_8 -> V_23 [ F_3 ( V_16 , V_22 ) ] ;
F_4 (p, head, tcfc_head) {
V_15 ++ ;
if ( V_15 < V_17 )
continue;
V_6 -> V_24 = V_13 ;
V_6 -> V_25 = V_15 ;
V_20 = F_5 ( V_2 , V_6 -> V_25 ) ;
if ( V_20 == NULL )
goto V_26;
if ( type == V_27 )
V_14 = F_6 ( V_2 , V_6 , 0 , 1 ) ;
else
V_14 = F_6 ( V_2 , V_6 , 0 , 0 ) ;
if ( V_14 < 0 ) {
V_15 -- ;
F_7 ( V_2 , V_20 ) ;
goto V_28;
}
F_8 ( V_2 , V_20 ) ;
V_18 ++ ;
}
}
V_28:
F_9 ( & V_8 -> V_21 ) ;
if ( V_18 )
V_4 -> args [ 0 ] += V_18 ;
return V_18 ;
V_26:
F_7 ( V_2 , V_20 ) ;
goto V_28;
}
static int F_10 ( struct V_29 * V_29 , struct V_19 * V_30 ,
struct V_19 * V_31 , struct V_5 * V_6 ,
int V_32 , int V_33 )
{
unsigned int V_34 ;
int V_35 = 0 , V_14 ;
struct V_19 * V_36 [ V_37 + 1 ] ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 = NULL , * V_44 = NULL ;
struct V_7 * V_8 = V_6 -> V_9 -> V_8 ;
int V_45 ;
if ( V_30 == NULL )
return - V_46 ;
V_14 = F_11 ( V_36 , V_37 , V_30 , V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_36 [ V_48 ] == NULL )
return - V_46 ;
V_45 = F_12 ( V_36 [ V_48 ] ) ;
if ( V_45 != sizeof( * V_39 ) && V_45 != sizeof( struct V_49 ) )
return - V_46 ;
V_39 = F_13 ( V_36 [ V_48 ] ) ;
if ( V_39 -> V_15 ) {
if ( F_14 ( V_6 , V_39 -> V_15 ) ) {
V_41 = F_15 ( V_6 -> V_24 ) ;
if ( V_33 ) {
V_41 -> V_50 += 1 ;
V_41 -> V_51 += 1 ;
return 0 ;
}
if ( V_32 )
goto V_52;
return - V_53 ;
}
}
V_41 = F_16 ( sizeof( * V_41 ) , V_54 ) ;
if ( V_41 == NULL )
return - V_55 ;
V_35 = V_56 ;
V_41 -> V_51 = 1 ;
F_17 ( & V_41 -> V_57 ) ;
if ( V_33 )
V_41 -> V_50 = 1 ;
V_52:
if ( V_39 -> V_58 . V_58 ) {
V_14 = - V_55 ;
V_43 = F_18 ( & V_39 -> V_58 , V_36 [ V_59 ] ) ;
if ( V_43 == NULL )
goto V_60;
if ( V_39 -> V_61 . V_58 ) {
V_44 = F_18 ( & V_39 -> V_61 ,
V_36 [ V_62 ] ) ;
if ( V_44 == NULL )
goto V_60;
}
}
F_2 ( & V_41 -> V_57 ) ;
if ( V_31 ) {
V_14 = F_19 ( & V_41 -> V_63 , NULL ,
& V_41 -> V_64 ,
& V_41 -> V_57 , V_31 ) ;
if ( V_14 )
goto V_65;
} else if ( V_36 [ V_66 ] &&
( V_35 == V_56 ||
! F_20 ( & V_41 -> V_63 ,
& V_41 -> V_64 ) ) ) {
V_14 = - V_46 ;
goto V_65;
}
V_41 -> V_67 = V_39 -> V_68 ;
if ( V_41 -> V_67 == 0 ) {
V_41 -> V_67 = ~ 0 ;
if ( V_43 )
V_41 -> V_67 = 255 << V_43 -> V_58 . V_69 ;
}
if ( V_43 ) {
V_41 -> V_70 = true ;
F_21 ( & V_41 -> V_58 , & V_43 -> V_58 , 0 ) ;
F_22 ( V_43 ) ;
} else {
V_41 -> V_70 = false ;
}
if ( V_44 ) {
V_41 -> V_71 = true ;
F_21 ( & V_41 -> V_72 , & V_44 -> V_58 , 0 ) ;
F_22 ( V_44 ) ;
} else {
V_41 -> V_71 = false ;
}
if ( V_36 [ V_73 ] )
V_41 -> V_74 = F_23 ( V_36 [ V_73 ] ) ;
V_41 -> V_75 = F_24 ( V_39 -> V_76 ) ;
V_41 -> V_77 = V_41 -> V_75 ;
if ( V_41 -> V_71 ) {
V_41 -> V_78 = ( V_79 ) F_25 ( & V_41 -> V_72 ,
V_41 -> V_67 ) ;
V_41 -> V_80 = V_41 -> V_78 ;
}
V_41 -> V_81 = V_39 -> V_82 ;
if ( V_36 [ V_66 ] )
V_41 -> V_83 = F_23 ( V_36 [ V_66 ] ) ;
F_9 ( & V_41 -> V_57 ) ;
if ( V_35 != V_56 )
return V_35 ;
V_41 -> V_84 = F_26 () ;
V_41 -> V_85 = V_39 -> V_15 ? V_39 -> V_15 :
F_27 ( V_8 ) ;
V_34 = F_3 ( V_41 -> V_85 , V_22 ) ;
F_2 ( & V_8 -> V_21 ) ;
F_28 ( & V_41 -> V_86 , & V_8 -> V_23 [ V_34 ] ) ;
F_9 ( & V_8 -> V_21 ) ;
V_6 -> V_24 = V_41 ;
return V_35 ;
V_65:
F_9 ( & V_41 -> V_57 ) ;
V_60:
F_22 ( V_44 ) ;
F_22 ( V_43 ) ;
if ( V_35 == V_56 )
F_29 ( V_41 ) ;
return V_14 ;
}
static int F_30 ( struct V_1 * V_2 , const struct V_5 * V_6 ,
struct V_87 * V_88 )
{
struct V_40 * V_41 = V_6 -> V_24 ;
V_79 V_89 ;
V_79 V_90 ;
V_79 V_91 = 0 ;
F_31 ( & V_41 -> V_57 ) ;
F_32 ( & V_41 -> V_63 , V_2 ) ;
if ( V_41 -> V_83 &&
V_41 -> V_64 . V_92 >= V_41 -> V_83 ) {
V_41 -> V_93 . V_94 ++ ;
if ( V_41 -> V_81 == V_95 )
V_41 -> V_93 . V_96 ++ ;
F_33 ( & V_41 -> V_57 ) ;
return V_41 -> V_81 ;
}
if ( F_34 ( V_2 ) <= V_41 -> V_67 ) {
if ( ! V_41 -> V_70 ) {
F_33 ( & V_41 -> V_57 ) ;
return V_41 -> V_74 ;
}
V_89 = F_26 () ;
V_90 = F_35 ( V_79 , V_89 - V_41 -> V_84 ,
V_41 -> V_75 ) ;
if ( V_41 -> V_71 ) {
V_91 = V_90 + V_41 -> V_80 ;
if ( V_91 > V_41 -> V_78 )
V_91 = V_41 -> V_78 ;
V_91 -= ( V_79 ) F_25 ( & V_41 -> V_72 ,
F_34 ( V_2 ) ) ;
}
V_90 += V_41 -> V_77 ;
if ( V_90 > V_41 -> V_75 )
V_90 = V_41 -> V_75 ;
V_90 -= ( V_79 ) F_25 ( & V_41 -> V_58 , F_34 ( V_2 ) ) ;
if ( ( V_90 | V_91 ) >= 0 ) {
V_41 -> V_84 = V_89 ;
V_41 -> V_77 = V_90 ;
V_41 -> V_80 = V_91 ;
F_33 ( & V_41 -> V_57 ) ;
return V_41 -> V_74 ;
}
}
V_41 -> V_93 . V_94 ++ ;
if ( V_41 -> V_81 == V_95 )
V_41 -> V_93 . V_96 ++ ;
F_33 ( & V_41 -> V_57 ) ;
return V_41 -> V_81 ;
}
static int
F_36 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_33 , int V_97 )
{
unsigned char * V_98 = F_37 ( V_2 ) ;
struct V_40 * V_41 = V_6 -> V_24 ;
struct V_38 V_99 = {
. V_15 = V_41 -> V_85 ,
. V_82 = V_41 -> V_81 ,
. V_68 = V_41 -> V_67 ,
. V_76 = F_38 ( V_41 -> V_75 ) ,
. V_100 = V_41 -> V_51 - V_97 ,
. V_101 = V_41 -> V_50 - V_33 ,
} ;
if ( V_41 -> V_70 )
F_39 ( & V_99 . V_58 , & V_41 -> V_58 ) ;
if ( V_41 -> V_71 )
F_39 ( & V_99 . V_61 , & V_41 -> V_72 ) ;
if ( F_40 ( V_2 , V_48 , sizeof( V_99 ) , & V_99 ) )
goto V_26;
if ( V_41 -> V_74 &&
F_41 ( V_2 , V_73 , V_41 -> V_74 ) )
goto V_26;
if ( V_41 -> V_83 &&
F_41 ( V_2 , V_66 , V_41 -> V_83 ) )
goto V_26;
return V_2 -> V_102 ;
V_26:
F_42 ( V_2 , V_98 ) ;
return - 1 ;
}
static int T_1
F_43 ( void )
{
return F_44 ( & V_103 , V_22 ) ;
}
static void T_2
F_45 ( void )
{
F_46 ( & V_103 ) ;
}
