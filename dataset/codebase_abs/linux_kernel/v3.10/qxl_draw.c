static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned V_6 ,
struct V_7 * * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
int V_14 = sizeof( * V_12 ) + sizeof( struct V_1 ) * V_6 ;
V_13 = F_2 ( V_3 , V_14 , V_8 ) ;
if ( V_13 )
return NULL ;
V_13 = F_3 ( * V_8 , ( void * * ) & V_12 ) ;
if ( V_13 ) {
F_4 ( V_8 ) ;
return NULL ;
}
V_12 -> V_15 = V_6 ;
V_12 -> V_16 . V_17 = 0 ;
V_12 -> V_16 . V_18 = 0 ;
V_12 -> V_16 . V_19 = sizeof( struct V_1 ) * V_6 ;
return (struct V_1 * ) V_12 -> V_16 . V_20 ;
}
static int
F_5 ( struct V_2 * V_3 , int V_21 , T_1 type ,
const struct V_1 * V_22 ,
struct V_9 * * V_10 )
{
struct V_4 * V_5 ;
int V_23 , V_13 ;
V_13 = F_6 ( V_3 , sizeof( * V_5 ) ,
V_24 , V_10 ,
NULL ) ;
if ( V_13 )
return V_13 ;
V_5 = (struct V_4 * ) F_7 ( V_3 , * V_10 ) ;
V_5 -> type = type ;
V_5 -> V_25 = V_21 ;
V_5 -> V_26 = V_27 ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 . V_30 = 0 ;
V_5 -> V_29 . V_31 = 0 ;
V_5 -> V_29 . V_32 = 0 ;
V_5 -> V_29 . V_33 = 0 ;
V_5 -> V_34 . type = V_35 ;
for ( V_23 = 0 ; V_23 < 3 ; ++ V_23 )
V_5 -> V_36 [ V_23 ] = - 1 ;
if ( V_22 )
V_5 -> V_37 = * V_22 ;
V_5 -> V_38 = V_3 -> V_39 -> V_40 ;
F_8 ( V_3 , * V_10 , & V_5 -> V_41 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * * V_42 ,
const struct V_43 * V_43 )
{
struct V_2 * V_3 = V_43 -> V_3 ;
const struct V_44 * V_44 = & V_43 -> V_44 ;
T_2 V_45 = V_43 -> V_45 ;
const T_2 * V_46 = V_43 -> V_46 ;
struct V_47 * V_48 ;
int V_13 ;
T_2 V_49 , V_50 ;
static T_3 V_51 ;
V_13 = F_2 ( V_3 ,
sizeof( struct V_47 ) + sizeof( T_2 ) * 2 ,
V_42 ) ;
V_13 = F_3 ( * V_42 , ( void * * ) & V_48 ) ;
V_48 -> V_52 = 2 ;
V_48 -> V_51 = V_51 ++ ;
if ( V_45 == V_53 || V_45 == V_54 ) {
V_49 = V_46 [ V_44 -> V_55 ] ;
V_50 = V_46 [ V_44 -> V_56 ] ;
} else {
V_49 = V_44 -> V_55 ;
V_50 = V_44 -> V_56 ;
}
V_48 -> V_57 [ 0 ] = V_50 ;
V_48 -> V_57 [ 1 ] = V_49 ;
F_10 ( * V_42 ) ;
return 0 ;
}
void F_11 ( const struct V_43 * V_43 ,
int V_58 )
{
struct V_2 * V_3 = V_43 -> V_3 ;
struct V_4 * V_5 ;
struct V_1 V_22 ;
const struct V_44 * V_44 = & V_43 -> V_44 ;
int V_59 = V_44 -> V_60 ;
int V_61 = V_44 -> V_62 ;
int V_63 = V_44 -> V_63 ;
int V_64 = V_44 -> V_64 ;
const char * V_65 = V_44 -> V_20 ;
int V_66 = V_44 -> V_66 ;
struct V_9 * V_10 ;
struct V_7 * V_67 ;
struct V_68 * V_69 ;
int V_13 ;
if ( V_58 == 0 )
V_58 = V_66 * V_63 / 8 ;
V_22 . V_31 = V_59 ;
V_22 . V_33 = V_59 + V_63 ;
V_22 . V_30 = V_61 ;
V_22 . V_32 = V_61 + V_64 ;
V_13 = F_5 ( V_3 , 0 , V_70 , & V_22 , & V_10 ) ;
if ( V_13 )
return;
V_13 = F_12 ( V_3 , V_10 , & V_67 ,
( const T_1 * ) V_65 , 0 , 0 ,
V_63 , V_64 , V_66 , V_58 ) ;
if ( V_13 ) {
F_13 ( V_3 , V_10 ) ;
F_14 ( V_3 , V_10 ) ;
return;
}
if ( V_66 == 1 ) {
struct V_7 * V_42 ;
void * V_71 ;
V_13 = F_9 ( & V_42 , V_43 ) ;
F_15 ( V_3 , V_10 , V_42 ) ;
V_71 = F_16 ( V_3 , V_67 , 0 ) ;
V_69 = V_71 ;
V_69 -> V_72 . V_73 . V_74 =
F_17 ( V_3 , V_42 , 0 ) ;
F_18 ( V_3 , V_67 , V_71 ) ;
F_19 ( V_42 ) ;
F_4 ( & V_42 ) ;
}
V_5 = (struct V_4 * ) F_7 ( V_3 , V_10 ) ;
V_5 -> V_72 . V_75 . V_76 . V_30 = 0 ;
V_5 -> V_72 . V_75 . V_76 . V_32 = V_64 ;
V_5 -> V_72 . V_75 . V_76 . V_31 = 0 ;
V_5 -> V_72 . V_75 . V_76 . V_33 = V_63 ;
V_5 -> V_72 . V_75 . V_77 = V_78 ;
V_5 -> V_72 . V_75 . V_79 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_81 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_82 . V_59 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_82 . V_61 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_73 = 0 ;
V_5 -> V_72 . V_75 . V_83 =
F_17 ( V_3 , V_67 , 0 ) ;
F_8 ( V_3 , V_10 , & V_5 -> V_41 ) ;
F_15 ( V_3 , V_10 , V_67 ) ;
F_19 ( V_67 ) ;
F_4 ( & V_67 ) ;
F_20 ( V_3 , V_10 ) ;
F_21 ( V_3 , V_10 , V_84 , false ) ;
F_13 ( V_3 , V_10 ) ;
}
void F_22 ( struct V_2 * V_3 ,
struct V_85 * V_86 ,
struct V_7 * V_87 ,
unsigned V_81 , unsigned V_88 ,
struct V_89 * V_90 ,
unsigned V_6 , int V_91 )
{
struct V_89 * V_92 ;
int V_23 ;
int V_31 , V_33 , V_30 , V_32 ;
int V_63 , V_64 ;
struct V_4 * V_5 ;
struct V_1 V_93 ;
struct V_1 * V_94 ;
int V_58 = V_86 -> V_95 . V_96 [ 0 ] ;
int V_66 = V_86 -> V_95 . V_97 ;
T_1 * V_98 ;
struct V_9 * V_10 ;
struct V_7 * V_67 ;
struct V_7 * V_8 ;
int V_13 ;
V_31 = V_90 -> V_99 ;
V_33 = V_90 -> V_100 ;
V_30 = V_90 -> y1 ;
V_32 = V_90 -> V_101 ;
for ( V_23 = 1 , V_92 = V_90 + V_91 ;
V_23 < V_6 ; V_23 ++ , V_92 += V_91 ) {
V_31 = F_23 ( int , V_31 , ( int ) V_92 -> V_99 ) ;
V_33 = F_24 ( int , V_33 , ( int ) V_92 -> V_100 ) ;
V_30 = F_23 ( int , V_30 , ( int ) V_92 -> y1 ) ;
V_32 = F_24 ( int , V_32 , ( int ) V_92 -> V_101 ) ;
}
V_63 = V_33 - V_31 ;
V_64 = V_32 - V_30 ;
V_93 . V_31 = V_31 ;
V_93 . V_33 = V_33 ;
V_93 . V_30 = V_30 ;
V_93 . V_32 = V_32 ;
V_13 = F_5 ( V_3 , 0 , V_70 , & V_93 ,
& V_10 ) ;
if ( V_13 )
return;
V_13 = F_3 ( V_87 , ( void * * ) & V_98 ) ;
if ( V_13 )
goto V_102;
V_13 = F_12 ( V_3 , V_10 , & V_67 , V_98 ,
V_31 , V_30 , V_63 , V_64 , V_66 , V_58 ) ;
F_10 ( V_87 ) ;
if ( V_13 )
goto V_102;
V_94 = F_1 ( V_3 , V_5 , V_6 , & V_8 , V_10 ) ;
if ( ! V_94 ) {
F_4 ( & V_67 ) ;
goto V_102;
}
V_5 = (struct V_4 * ) F_7 ( V_3 , V_10 ) ;
V_5 -> V_34 . type = V_103 ;
V_5 -> V_34 . V_20 = F_17 ( V_3 ,
V_8 , 0 ) ;
F_15 ( V_3 , V_10 , V_8 ) ;
V_5 -> V_72 . V_75 . V_76 . V_30 = 0 ;
V_5 -> V_72 . V_75 . V_76 . V_32 = V_64 ;
V_5 -> V_72 . V_75 . V_76 . V_31 = 0 ;
V_5 -> V_72 . V_75 . V_76 . V_33 = V_63 ;
V_5 -> V_72 . V_75 . V_77 = V_78 ;
V_5 -> V_72 . V_75 . V_79 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_81 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_82 . V_59 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_82 . V_61 = 0 ;
V_5 -> V_72 . V_75 . V_80 . V_73 = 0 ;
V_5 -> V_72 . V_75 . V_83 = F_17 ( V_3 , V_67 , 0 ) ;
F_8 ( V_3 , V_10 , & V_5 -> V_41 ) ;
F_15 ( V_3 , V_10 , V_67 ) ;
F_19 ( V_67 ) ;
F_4 ( & V_67 ) ;
V_92 = V_90 ;
for ( V_23 = 0 ; V_23 < V_6 ; V_23 ++ , V_92 += V_91 ) {
V_94 [ V_23 ] . V_31 = V_92 -> V_99 ;
V_94 [ V_23 ] . V_33 = V_92 -> V_100 ;
V_94 [ V_23 ] . V_30 = V_92 -> y1 ;
V_94 [ V_23 ] . V_32 = V_92 -> V_101 ;
}
F_10 ( V_8 ) ;
F_19 ( V_8 ) ;
F_4 ( & V_8 ) ;
F_20 ( V_3 , V_10 ) ;
F_21 ( V_3 , V_10 , V_84 , false ) ;
F_13 ( V_3 , V_10 ) ;
return;
V_102:
F_13 ( V_3 , V_10 ) ;
F_14 ( V_3 , V_10 ) ;
}
void F_25 ( struct V_2 * V_3 ,
T_4 V_63 , T_4 V_64 ,
T_4 V_104 , T_4 V_105 ,
T_4 V_60 , T_4 V_62 )
{
struct V_4 * V_5 ;
struct V_1 V_22 ;
struct V_9 * V_10 ;
int V_13 ;
V_22 . V_31 = V_60 ;
V_22 . V_30 = V_62 ;
V_22 . V_33 = V_60 + V_63 ;
V_22 . V_32 = V_62 + V_64 ;
V_13 = F_5 ( V_3 , 0 , V_106 , & V_22 , & V_10 ) ;
if ( V_13 )
return;
V_5 = (struct V_4 * ) F_7 ( V_3 , V_10 ) ;
V_5 -> V_72 . V_107 . V_108 . V_59 = V_104 ;
V_5 -> V_72 . V_107 . V_108 . V_61 = V_105 ;
F_8 ( V_3 , V_10 , & V_5 -> V_41 ) ;
F_20 ( V_3 , V_10 ) ;
F_21 ( V_3 , V_10 , V_84 , false ) ;
F_13 ( V_3 , V_10 ) ;
}
void F_26 ( struct F_26 * V_109 )
{
struct V_2 * V_3 = V_109 -> V_3 ;
struct V_1 V_22 = V_109 -> V_22 ;
T_2 V_88 = V_109 -> V_88 ;
T_5 V_110 = V_109 -> V_110 ;
struct V_4 * V_5 ;
struct V_9 * V_10 ;
int V_13 ;
V_13 = F_5 ( V_3 , 0 , V_111 , & V_22 , & V_10 ) ;
if ( V_13 )
return;
V_5 = (struct V_4 * ) F_7 ( V_3 , V_10 ) ;
V_5 -> V_72 . V_112 . V_113 . type = V_114 ;
V_5 -> V_72 . V_112 . V_113 . V_72 . V_88 = V_88 ;
V_5 -> V_72 . V_112 . V_77 = V_110 ;
V_5 -> V_72 . V_112 . V_80 . V_81 = 0 ;
V_5 -> V_72 . V_112 . V_80 . V_82 . V_59 = 0 ;
V_5 -> V_72 . V_112 . V_80 . V_82 . V_61 = 0 ;
V_5 -> V_72 . V_112 . V_80 . V_73 = 0 ;
F_8 ( V_3 , V_10 , & V_5 -> V_41 ) ;
F_20 ( V_3 , V_10 ) ;
F_21 ( V_3 , V_10 , V_84 , false ) ;
F_13 ( V_3 , V_10 ) ;
}
