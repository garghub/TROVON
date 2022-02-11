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
if ( V_8 -> V_33 )
F_13 ( V_8 -> V_33 ) ;
if ( V_8 -> V_34 )
F_13 ( V_8 -> V_34 ) ;
F_14 ( V_8 , V_35 ) ;
return;
}
}
F_15 ( 1 ) ;
}
static int F_16 ( struct V_14 * V_36 , struct V_14 * V_37 ,
struct V_5 * V_6 , int V_38 , int V_39 )
{
unsigned int V_26 ;
int V_40 = 0 , V_9 ;
struct V_14 * V_41 [ V_42 + 1 ] ;
struct V_43 * V_44 ;
struct V_25 * V_45 ;
struct V_46 * V_47 = NULL , * V_48 = NULL ;
int V_49 ;
if ( V_36 == NULL )
return - V_50 ;
V_9 = F_17 ( V_41 , V_42 , V_36 , V_51 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_41 [ V_52 ] == NULL )
return - V_50 ;
V_49 = F_18 ( V_41 [ V_52 ] ) ;
if ( V_49 != sizeof( * V_44 ) && V_49 != sizeof( struct V_53 ) )
return - V_50 ;
V_44 = F_19 ( V_41 [ V_52 ] ) ;
if ( V_44 -> V_10 ) {
struct V_7 * V_54 ;
V_54 = F_20 ( V_44 -> V_10 , & V_55 ) ;
if ( V_54 != NULL ) {
V_6 -> V_20 = V_54 ;
V_45 = F_21 ( V_54 ) ;
if ( V_39 ) {
V_45 -> V_56 += 1 ;
V_45 -> V_57 += 1 ;
}
if ( V_38 )
goto V_58;
return V_40 ;
}
}
V_45 = F_22 ( sizeof( * V_45 ) , V_59 ) ;
if ( V_45 == NULL )
return - V_60 ;
V_40 = V_61 ;
V_45 -> V_57 = 1 ;
F_23 ( & V_45 -> V_62 ) ;
if ( V_39 )
V_45 -> V_56 = 1 ;
V_58:
if ( V_44 -> V_63 . V_63 ) {
V_9 = - V_60 ;
V_47 = F_24 ( & V_44 -> V_63 , V_41 [ V_64 ] ) ;
if ( V_47 == NULL )
goto V_65;
if ( V_44 -> V_66 . V_63 ) {
V_48 = F_24 ( & V_44 -> V_66 ,
V_41 [ V_67 ] ) ;
if ( V_48 == NULL )
goto V_65;
}
}
F_25 ( & V_45 -> V_62 ) ;
if ( V_37 ) {
V_9 = F_26 ( & V_45 -> V_31 ,
& V_45 -> V_32 ,
& V_45 -> V_62 , V_37 ) ;
if ( V_9 )
goto V_68;
} else if ( V_41 [ V_69 ] &&
( V_40 == V_61 ||
! F_27 ( & V_45 -> V_31 ,
& V_45 -> V_32 ) ) ) {
V_9 = - V_50 ;
goto V_68;
}
if ( V_47 != NULL ) {
F_13 ( V_45 -> V_33 ) ;
V_45 -> V_33 = V_47 ;
}
if ( V_48 != NULL ) {
F_13 ( V_45 -> V_34 ) ;
V_45 -> V_34 = V_48 ;
}
if ( V_41 [ V_70 ] )
V_45 -> V_71 = F_28 ( V_41 [ V_70 ] ) ;
V_45 -> V_72 = V_45 -> V_73 = V_44 -> V_74 ;
V_45 -> V_75 = V_44 -> V_76 ;
if ( V_45 -> V_75 == 0 ) {
V_45 -> V_75 = ~ 0 ;
if ( V_45 -> V_33 )
V_45 -> V_75 = 255 << V_45 -> V_33 -> V_63 . V_77 ;
}
if ( V_45 -> V_34 )
V_45 -> V_78 = F_29 ( V_45 , V_45 -> V_75 ) ;
V_45 -> V_79 = V_44 -> V_80 ;
if ( V_41 [ V_69 ] )
V_45 -> V_81 = F_28 ( V_41 [ V_69 ] ) ;
F_30 ( & V_45 -> V_62 ) ;
if ( V_40 != V_61 )
return V_40 ;
V_45 -> V_82 = F_31 () ;
V_45 -> V_27 = V_44 -> V_10 ? V_44 -> V_10 :
F_32 ( & V_83 , & V_55 ) ;
V_26 = F_3 ( V_45 -> V_27 , V_17 ) ;
F_10 ( & V_16 ) ;
V_45 -> V_30 = V_18 [ V_26 ] ;
V_18 [ V_26 ] = & V_45 -> V_29 ;
F_11 ( & V_16 ) ;
V_6 -> V_20 = V_45 ;
return V_40 ;
V_68:
F_30 ( & V_45 -> V_62 ) ;
V_65:
if ( V_48 )
F_13 ( V_48 ) ;
if ( V_47 )
F_13 ( V_47 ) ;
if ( V_40 == V_61 )
F_33 ( V_45 ) ;
return V_9 ;
}
static int F_34 ( struct V_5 * V_6 , int V_39 )
{
struct V_25 * V_8 = V_6 -> V_20 ;
int V_40 = 0 ;
if ( V_8 != NULL ) {
if ( V_39 )
V_8 -> V_56 -- ;
V_8 -> V_57 -- ;
if ( V_8 -> V_57 <= 0 && ! V_8 -> V_56 ) {
F_9 ( V_8 ) ;
V_40 = 1 ;
}
}
return V_40 ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_5 * V_6 ,
struct V_84 * V_85 )
{
struct V_25 * V_45 = V_6 -> V_20 ;
T_1 V_86 ;
long V_87 ;
long V_88 = 0 ;
F_36 ( & V_45 -> V_62 ) ;
F_37 ( & V_45 -> V_31 , V_2 ) ;
if ( V_45 -> V_81 &&
V_45 -> V_32 . V_89 >= V_45 -> V_81 ) {
V_45 -> V_90 . V_91 ++ ;
if ( V_45 -> V_79 == V_92 )
V_45 -> V_90 . V_93 ++ ;
F_38 ( & V_45 -> V_62 ) ;
return V_45 -> V_79 ;
}
if ( F_39 ( V_2 ) <= V_45 -> V_75 ) {
if ( V_45 -> V_33 == NULL ) {
F_38 ( & V_45 -> V_62 ) ;
return V_45 -> V_71 ;
}
V_86 = F_31 () ;
V_87 = F_40 ( V_86 , V_45 -> V_82 ,
V_45 -> V_73 ) ;
if ( V_45 -> V_34 ) {
V_88 = V_87 + V_45 -> V_78 ;
if ( V_88 > ( long ) F_29 ( V_45 , V_45 -> V_75 ) )
V_88 = ( long ) F_29 ( V_45 , V_45 -> V_75 ) ;
V_88 -= F_29 ( V_45 , F_39 ( V_2 ) ) ;
}
V_87 += V_45 -> V_72 ;
if ( V_87 > ( long ) V_45 -> V_73 )
V_87 = V_45 -> V_73 ;
V_87 -= F_41 ( V_45 , F_39 ( V_2 ) ) ;
if ( ( V_87 | V_88 ) >= 0 ) {
V_45 -> V_82 = V_86 ;
V_45 -> V_72 = V_87 ;
V_45 -> V_78 = V_88 ;
F_38 ( & V_45 -> V_62 ) ;
return V_45 -> V_71 ;
}
}
V_45 -> V_90 . V_91 ++ ;
if ( V_45 -> V_79 == V_92 )
V_45 -> V_90 . V_93 ++ ;
F_38 ( & V_45 -> V_62 ) ;
return V_45 -> V_79 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_39 , int V_94 )
{
unsigned char * V_95 = F_43 ( V_2 ) ;
struct V_25 * V_45 = V_6 -> V_20 ;
struct V_43 V_96 = {
. V_10 = V_45 -> V_27 ,
. V_80 = V_45 -> V_79 ,
. V_76 = V_45 -> V_75 ,
. V_74 = V_45 -> V_73 ,
. V_97 = V_45 -> V_57 - V_94 ,
. V_98 = V_45 -> V_56 - V_39 ,
} ;
if ( V_45 -> V_33 )
V_96 . V_63 = V_45 -> V_33 -> V_63 ;
if ( V_45 -> V_34 )
V_96 . V_66 = V_45 -> V_34 -> V_63 ;
F_44 ( V_2 , V_52 , sizeof( V_96 ) , & V_96 ) ;
if ( V_45 -> V_71 )
F_45 ( V_2 , V_70 , V_45 -> V_71 ) ;
if ( V_45 -> V_81 )
F_45 ( V_2 , V_69 , V_45 -> V_81 ) ;
return V_2 -> V_99 ;
V_22:
F_46 ( V_2 , V_95 ) ;
return - 1 ;
}
static int T_2
F_47 ( void )
{
return F_48 ( & V_100 ) ;
}
static void T_3
F_49 ( void )
{
F_50 ( & V_100 ) ;
}
