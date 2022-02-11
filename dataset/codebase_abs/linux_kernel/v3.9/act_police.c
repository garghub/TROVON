static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int type , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 = 0 , V_10 = - 1 , V_11 = 0 , V_12 = 0 , V_13 = 0 ;
struct V_14 * V_15 ;
F_2 ( & V_16 ) ;
V_12 = V_4 -> args [ 0 ] ;
for ( V_11 = 0 ; V_11 < ( V_17 + 1 ) ; V_11 ++ ) {
V_8 = V_18 [ F_3 ( V_11 , V_17 ) ] ;
for (; V_8 ; V_8 = V_8 -> V_19 ) {
V_10 ++ ;
if ( V_10 < V_12 )
continue;
V_6 -> V_20 = V_8 ;
V_6 -> V_21 = V_10 ;
V_15 = F_4 ( V_2 , V_6 -> V_21 ) ;
if ( V_15 == NULL )
goto V_22;
if ( type == V_23 )
V_9 = F_5 ( V_2 , V_6 , 0 , 1 ) ;
else
V_9 = F_5 ( V_2 , V_6 , 0 , 0 ) ;
if ( V_9 < 0 ) {
V_10 -- ;
F_6 ( V_2 , V_15 ) ;
goto V_24;
}
F_7 ( V_2 , V_15 ) ;
V_13 ++ ;
}
}
V_24:
F_8 ( & V_16 ) ;
if ( V_13 )
V_4 -> args [ 0 ] += V_13 ;
return V_13 ;
V_22:
F_6 ( V_2 , V_15 ) ;
goto V_24;
}
static void F_9 ( struct V_25 * V_8 )
{
unsigned int V_26 = F_3 ( V_8 -> V_27 , V_17 ) ;
struct V_7 * * V_28 ;
for ( V_28 = & V_18 [ V_26 ] ; * V_28 ; V_28 = & ( * V_28 ) -> V_19 ) {
if ( * V_28 == & V_8 -> V_29 ) {
F_10 ( & V_16 ) ;
* V_28 = V_8 -> V_30 ;
F_11 ( & V_16 ) ;
F_12 ( & V_8 -> V_31 ,
& V_8 -> V_32 ) ;
F_13 ( V_8 , V_33 ) ;
return;
}
}
F_14 ( 1 ) ;
}
static int F_15 ( struct V_34 * V_34 , struct V_14 * V_35 ,
struct V_14 * V_36 , struct V_5 * V_6 ,
int V_37 , int V_38 )
{
unsigned int V_26 ;
int V_39 = 0 , V_9 ;
struct V_14 * V_40 [ V_41 + 1 ] ;
struct V_42 * V_43 ;
struct V_25 * V_44 ;
struct V_45 * V_46 = NULL , * V_47 = NULL ;
int V_48 ;
if ( V_35 == NULL )
return - V_49 ;
V_9 = F_16 ( V_40 , V_41 , V_35 , V_50 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_40 [ V_51 ] == NULL )
return - V_49 ;
V_48 = F_17 ( V_40 [ V_51 ] ) ;
if ( V_48 != sizeof( * V_43 ) && V_48 != sizeof( struct V_52 ) )
return - V_49 ;
V_43 = F_18 ( V_40 [ V_51 ] ) ;
if ( V_43 -> V_10 ) {
struct V_7 * V_53 ;
V_53 = F_19 ( V_43 -> V_10 , & V_54 ) ;
if ( V_53 != NULL ) {
V_6 -> V_20 = V_53 ;
V_44 = F_20 ( V_53 ) ;
if ( V_38 ) {
V_44 -> V_55 += 1 ;
V_44 -> V_56 += 1 ;
}
if ( V_37 )
goto V_57;
return V_39 ;
}
}
V_44 = F_21 ( sizeof( * V_44 ) , V_58 ) ;
if ( V_44 == NULL )
return - V_59 ;
V_39 = V_60 ;
V_44 -> V_56 = 1 ;
F_22 ( & V_44 -> V_61 ) ;
if ( V_38 )
V_44 -> V_55 = 1 ;
V_57:
if ( V_43 -> V_62 . V_62 ) {
V_9 = - V_59 ;
V_46 = F_23 ( & V_43 -> V_62 , V_40 [ V_63 ] ) ;
if ( V_46 == NULL )
goto V_64;
if ( V_43 -> V_65 . V_62 ) {
V_47 = F_23 ( & V_43 -> V_65 ,
V_40 [ V_66 ] ) ;
if ( V_47 == NULL )
goto V_64;
}
}
F_24 ( & V_44 -> V_61 ) ;
if ( V_36 ) {
V_9 = F_25 ( & V_44 -> V_31 ,
& V_44 -> V_32 ,
& V_44 -> V_61 , V_36 ) ;
if ( V_9 )
goto V_67;
} else if ( V_40 [ V_68 ] &&
( V_39 == V_60 ||
! F_26 ( & V_44 -> V_31 ,
& V_44 -> V_32 ) ) ) {
V_9 = - V_49 ;
goto V_67;
}
V_44 -> V_69 = V_43 -> V_70 ;
if ( V_44 -> V_69 == 0 ) {
V_44 -> V_69 = ~ 0 ;
if ( V_46 )
V_44 -> V_69 = 255 << V_46 -> V_62 . V_71 ;
}
if ( V_46 ) {
V_44 -> V_72 = true ;
F_27 ( & V_44 -> V_62 , V_46 -> V_62 . V_62 ) ;
F_28 ( V_46 ) ;
} else {
V_44 -> V_72 = false ;
}
if ( V_47 ) {
V_44 -> V_73 = true ;
F_27 ( & V_44 -> V_74 , V_47 -> V_62 . V_62 ) ;
F_28 ( V_47 ) ;
} else {
V_44 -> V_73 = false ;
}
if ( V_40 [ V_75 ] )
V_44 -> V_76 = F_29 ( V_40 [ V_75 ] ) ;
V_44 -> V_77 = F_30 ( V_43 -> V_78 ) ;
V_44 -> V_79 = V_44 -> V_77 ;
if ( V_44 -> V_73 ) {
V_44 -> V_80 = ( V_81 ) F_31 ( & V_44 -> V_74 ,
V_44 -> V_69 ) ;
V_44 -> V_82 = V_44 -> V_80 ;
}
V_44 -> V_83 = V_43 -> V_84 ;
if ( V_40 [ V_68 ] )
V_44 -> V_85 = F_29 ( V_40 [ V_68 ] ) ;
F_32 ( & V_44 -> V_61 ) ;
if ( V_39 != V_60 )
return V_39 ;
V_44 -> V_86 = F_33 ( F_34 () ) ;
V_44 -> V_27 = V_43 -> V_10 ? V_43 -> V_10 :
F_35 ( & V_87 , & V_54 ) ;
V_26 = F_3 ( V_44 -> V_27 , V_17 ) ;
F_10 ( & V_16 ) ;
V_44 -> V_30 = V_18 [ V_26 ] ;
V_18 [ V_26 ] = & V_44 -> V_29 ;
F_11 ( & V_16 ) ;
V_6 -> V_20 = V_44 ;
return V_39 ;
V_67:
F_32 ( & V_44 -> V_61 ) ;
V_64:
if ( V_47 )
F_28 ( V_47 ) ;
if ( V_46 )
F_28 ( V_46 ) ;
if ( V_39 == V_60 )
F_36 ( V_44 ) ;
return V_9 ;
}
static int F_37 ( struct V_5 * V_6 , int V_38 )
{
struct V_25 * V_8 = V_6 -> V_20 ;
int V_39 = 0 ;
if ( V_8 != NULL ) {
if ( V_38 )
V_8 -> V_55 -- ;
V_8 -> V_56 -- ;
if ( V_8 -> V_56 <= 0 && ! V_8 -> V_55 ) {
F_9 ( V_8 ) ;
V_39 = 1 ;
}
}
return V_39 ;
}
static int F_38 ( struct V_1 * V_2 , const struct V_5 * V_6 ,
struct V_88 * V_89 )
{
struct V_25 * V_44 = V_6 -> V_20 ;
V_81 V_90 ;
V_81 V_91 ;
V_81 V_92 = 0 ;
F_39 ( & V_44 -> V_61 ) ;
F_40 ( & V_44 -> V_31 , V_2 ) ;
if ( V_44 -> V_85 &&
V_44 -> V_32 . V_93 >= V_44 -> V_85 ) {
V_44 -> V_94 . V_95 ++ ;
if ( V_44 -> V_83 == V_96 )
V_44 -> V_94 . V_97 ++ ;
F_41 ( & V_44 -> V_61 ) ;
return V_44 -> V_83 ;
}
if ( F_42 ( V_2 ) <= V_44 -> V_69 ) {
if ( ! V_44 -> V_72 ) {
F_41 ( & V_44 -> V_61 ) ;
return V_44 -> V_76 ;
}
V_90 = F_33 ( F_34 () ) ;
V_91 = F_43 ( V_81 , V_90 - V_44 -> V_86 ,
V_44 -> V_77 ) ;
if ( V_44 -> V_73 ) {
V_92 = V_91 + V_44 -> V_82 ;
if ( V_92 > V_44 -> V_80 )
V_92 = V_44 -> V_80 ;
V_92 -= ( V_81 ) F_31 ( & V_44 -> V_74 ,
F_42 ( V_2 ) ) ;
}
V_91 += V_44 -> V_79 ;
if ( V_91 > V_44 -> V_77 )
V_91 = V_44 -> V_77 ;
V_91 -= ( V_81 ) F_31 ( & V_44 -> V_62 , F_42 ( V_2 ) ) ;
if ( ( V_91 | V_92 ) >= 0 ) {
V_44 -> V_86 = V_90 ;
V_44 -> V_79 = V_91 ;
V_44 -> V_82 = V_92 ;
F_41 ( & V_44 -> V_61 ) ;
return V_44 -> V_76 ;
}
}
V_44 -> V_94 . V_95 ++ ;
if ( V_44 -> V_83 == V_96 )
V_44 -> V_94 . V_97 ++ ;
F_41 ( & V_44 -> V_61 ) ;
return V_44 -> V_83 ;
}
static int
F_44 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_38 , int V_98 )
{
unsigned char * V_99 = F_45 ( V_2 ) ;
struct V_25 * V_44 = V_6 -> V_20 ;
struct V_42 V_100 = {
. V_10 = V_44 -> V_27 ,
. V_84 = V_44 -> V_83 ,
. V_70 = V_44 -> V_69 ,
. V_78 = F_46 ( V_44 -> V_77 ) ,
. V_101 = V_44 -> V_56 - V_98 ,
. V_102 = V_44 -> V_55 - V_38 ,
} ;
if ( V_44 -> V_72 )
V_100 . V_62 . V_62 = F_47 ( & V_44 -> V_62 ) ;
if ( V_44 -> V_73 )
V_100 . V_65 . V_62 = F_47 ( & V_44 -> V_74 ) ;
if ( F_48 ( V_2 , V_51 , sizeof( V_100 ) , & V_100 ) )
goto V_22;
if ( V_44 -> V_76 &&
F_49 ( V_2 , V_75 , V_44 -> V_76 ) )
goto V_22;
if ( V_44 -> V_85 &&
F_49 ( V_2 , V_68 , V_44 -> V_85 ) )
goto V_22;
return V_2 -> V_103 ;
V_22:
F_50 ( V_2 , V_99 ) ;
return - 1 ;
}
static int T_1
F_51 ( void )
{
return F_52 ( & V_104 ) ;
}
static void T_2
F_53 ( void )
{
F_54 ( & V_104 ) ;
}
