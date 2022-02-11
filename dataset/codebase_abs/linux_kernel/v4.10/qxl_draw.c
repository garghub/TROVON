static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_5 ,
struct V_6 * * V_7 )
{
int V_8 = sizeof( struct V_9 ) + sizeof( struct V_10 ) * V_5 ;
return F_2 ( V_2 , V_4 , V_8 , V_7 ) ;
}
static struct V_10 * F_3 ( struct V_1 * V_2 ,
unsigned V_5 ,
struct V_6 * V_7 )
{
struct V_9 * V_11 ;
int V_12 ;
V_12 = F_4 ( V_7 , ( void * * ) & V_11 ) ;
if ( V_12 ) {
return NULL ;
}
V_11 -> V_13 = V_5 ;
V_11 -> V_14 . V_15 = 0 ;
V_11 -> V_14 . V_16 = 0 ;
V_11 -> V_14 . V_17 = sizeof( struct V_10 ) * V_5 ;
return (struct V_10 * ) V_11 -> V_14 . V_18 ;
}
static int
F_5 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
return F_6 ( V_2 , sizeof( struct V_19 ) ,
V_20 , V_4 , NULL ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_8 ( V_2 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , int V_21 , T_1 type ,
const struct V_10 * V_22 ,
struct V_3 * V_4 )
{
struct V_19 * V_23 ;
int V_24 ;
V_23 = (struct V_19 * ) F_10 ( V_2 , V_4 ) ;
if ( ! V_23 )
return - V_25 ;
V_23 -> type = type ;
V_23 -> V_26 = V_21 ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 . V_31 = 0 ;
V_23 -> V_30 . V_32 = 0 ;
V_23 -> V_30 . V_33 = 0 ;
V_23 -> V_30 . V_34 = 0 ;
V_23 -> V_35 . type = V_36 ;
for ( V_24 = 0 ; V_24 < 3 ; ++ V_24 )
V_23 -> V_37 [ V_24 ] = - 1 ;
if ( V_22 )
V_23 -> V_38 = * V_22 ;
V_23 -> V_39 = V_2 -> V_40 -> V_41 ;
F_11 ( V_2 , V_4 , & V_23 -> V_42 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * * V_43 )
{
return F_2 ( V_2 , V_4 ,
sizeof( struct V_44 ) + sizeof( V_45 ) * 2 ,
V_43 ) ;
}
static int F_13 ( struct V_6 * V_43 ,
struct V_3 * V_4 ,
const struct V_46 * V_46 )
{
const struct V_47 * V_47 = & V_46 -> V_47 ;
V_45 V_48 = V_46 -> V_48 ;
const V_45 * V_49 = V_46 -> V_49 ;
struct V_44 * V_50 ;
int V_12 ;
V_45 V_51 , V_52 ;
static T_2 V_53 ;
V_12 = F_4 ( V_43 , ( void * * ) & V_50 ) ;
if ( V_12 )
return V_12 ;
V_50 -> V_54 = 2 ;
V_50 -> V_53 = V_53 ++ ;
if ( V_48 == V_55 || V_48 == V_56 ) {
V_51 = V_49 [ V_47 -> V_57 ] ;
V_52 = V_49 [ V_47 -> V_58 ] ;
} else {
V_51 = V_47 -> V_57 ;
V_52 = V_47 -> V_58 ;
}
V_50 -> V_59 [ 0 ] = V_52 ;
V_50 -> V_59 [ 1 ] = V_51 ;
F_14 ( V_43 ) ;
return 0 ;
}
void F_15 ( const struct V_46 * V_46 ,
int V_60 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_19 * V_23 ;
struct V_10 V_22 ;
const struct V_47 * V_47 = & V_46 -> V_47 ;
int V_61 = V_47 -> V_62 ;
int V_63 = V_47 -> V_64 ;
int V_65 = V_47 -> V_65 ;
int V_66 = V_47 -> V_66 ;
const char * V_67 = V_47 -> V_18 ;
int V_68 = V_47 -> V_68 ;
struct V_3 * V_4 ;
struct V_69 * V_70 ;
int V_12 ;
struct V_71 * V_72 ;
struct V_6 * V_43 = NULL ;
if ( V_60 == 0 )
V_60 = V_68 * V_65 / 8 ;
V_12 = F_5 ( V_2 , & V_4 ) ;
if ( V_12 )
return;
V_12 = F_16 ( V_2 , V_4 ,
& V_72 ,
V_66 , V_60 ) ;
if ( V_12 )
goto V_73;
if ( V_68 == 1 ) {
V_12 = F_12 ( V_2 , V_4 , & V_43 ) ;
if ( V_12 )
goto V_74;
}
V_12 = F_17 ( V_4 , true ) ;
if ( V_12 )
goto V_75;
V_22 . V_32 = V_61 ;
V_22 . V_34 = V_61 + V_65 ;
V_22 . V_31 = V_63 ;
V_22 . V_33 = V_63 + V_66 ;
V_12 = F_9 ( V_2 , 0 , V_76 , & V_22 , V_4 ) ;
if ( V_12 ) {
F_18 ( V_4 ) ;
goto V_75;
}
V_12 = F_19 ( V_2 , V_4 , V_72 ,
( const T_1 * ) V_67 , 0 , 0 ,
V_65 , V_66 , V_68 , V_60 ) ;
if ( V_12 ) {
F_18 ( V_4 ) ;
F_8 ( V_2 , V_4 ) ;
return;
}
if ( V_68 == 1 ) {
void * V_77 ;
V_12 = F_13 ( V_43 , V_4 , V_46 ) ;
V_77 = F_20 ( V_2 , V_72 -> V_78 , 0 ) ;
V_70 = V_77 ;
V_70 -> V_79 . V_80 . V_81 =
F_21 ( V_2 , V_43 , 0 ) ;
F_22 ( V_2 , V_72 -> V_78 , V_77 ) ;
}
V_23 = (struct V_19 * ) F_10 ( V_2 , V_4 ) ;
V_23 -> V_79 . V_82 . V_83 . V_31 = 0 ;
V_23 -> V_79 . V_82 . V_83 . V_33 = V_66 ;
V_23 -> V_79 . V_82 . V_83 . V_32 = 0 ;
V_23 -> V_79 . V_82 . V_83 . V_34 = V_65 ;
V_23 -> V_79 . V_82 . V_84 = V_85 ;
V_23 -> V_79 . V_82 . V_86 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_88 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_89 . V_61 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_89 . V_63 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_80 = 0 ;
V_23 -> V_79 . V_82 . V_90 =
F_21 ( V_2 , V_72 -> V_78 , 0 ) ;
F_11 ( V_2 , V_4 , & V_23 -> V_42 ) ;
F_23 ( V_2 , V_4 , V_91 , false ) ;
F_24 ( V_4 ) ;
V_75:
if ( V_43 )
F_25 ( & V_43 ) ;
V_74:
F_26 ( V_2 , V_72 ) ;
V_73:
if ( V_12 )
F_7 ( V_2 , V_4 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_6 * V_78 ,
unsigned V_88 , unsigned V_94 ,
struct V_95 * V_96 ,
unsigned V_5 , int V_97 )
{
struct V_95 * V_98 ;
int V_24 ;
int V_32 , V_34 , V_31 , V_33 ;
int V_65 , V_66 ;
struct V_19 * V_23 ;
struct V_10 V_99 ;
struct V_10 * V_100 ;
int V_60 = V_93 -> V_101 . V_102 [ 0 ] ;
int V_68 = V_93 -> V_101 . V_103 ;
T_1 * V_104 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_71 * V_72 ;
int V_12 ;
V_12 = F_5 ( V_2 , & V_4 ) ;
if ( V_12 )
return;
V_32 = V_96 -> V_105 ;
V_34 = V_96 -> V_106 ;
V_31 = V_96 -> y1 ;
V_33 = V_96 -> V_107 ;
for ( V_24 = 1 , V_98 = V_96 + V_97 ;
V_24 < V_5 ; V_24 ++ , V_98 += V_97 ) {
V_32 = F_28 ( int , V_32 , ( int ) V_98 -> V_105 ) ;
V_34 = F_29 ( int , V_34 , ( int ) V_98 -> V_106 ) ;
V_31 = F_28 ( int , V_31 , ( int ) V_98 -> y1 ) ;
V_33 = F_29 ( int , V_33 , ( int ) V_98 -> V_107 ) ;
}
V_65 = V_34 - V_32 ;
V_66 = V_33 - V_31 ;
V_12 = F_1 ( V_2 , V_4 , V_5 , & V_7 ) ;
if ( V_12 )
goto V_73;
V_12 = F_16 ( V_2 , V_4 ,
& V_72 ,
V_66 , V_60 ) ;
if ( V_12 )
goto V_108;
V_12 = F_17 ( V_4 , true ) ;
if ( V_12 )
goto V_74;
V_99 . V_32 = V_32 ;
V_99 . V_34 = V_34 ;
V_99 . V_31 = V_31 ;
V_99 . V_33 = V_33 ;
V_12 = F_9 ( V_2 , 0 , V_76 , & V_99 ,
V_4 ) ;
if ( V_12 )
goto V_109;
V_12 = F_4 ( V_78 , ( void * * ) & V_104 ) ;
if ( V_12 )
goto V_109;
V_12 = F_19 ( V_2 , V_4 , V_72 , V_104 ,
V_32 , V_31 , V_65 , V_66 , V_68 , V_60 ) ;
F_14 ( V_78 ) ;
if ( V_12 )
goto V_109;
V_100 = F_3 ( V_2 , V_5 , V_7 ) ;
if ( ! V_100 )
goto V_109;
V_23 = (struct V_19 * ) F_10 ( V_2 , V_4 ) ;
V_23 -> V_35 . type = V_110 ;
V_23 -> V_35 . V_18 = F_21 ( V_2 ,
V_7 , 0 ) ;
V_23 -> V_79 . V_82 . V_83 . V_31 = 0 ;
V_23 -> V_79 . V_82 . V_83 . V_33 = V_66 ;
V_23 -> V_79 . V_82 . V_83 . V_32 = 0 ;
V_23 -> V_79 . V_82 . V_83 . V_34 = V_65 ;
V_23 -> V_79 . V_82 . V_84 = V_85 ;
V_23 -> V_79 . V_82 . V_86 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_88 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_89 . V_61 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_89 . V_63 = 0 ;
V_23 -> V_79 . V_82 . V_87 . V_80 = 0 ;
V_23 -> V_79 . V_82 . V_90 = F_21 ( V_2 , V_72 -> V_78 , 0 ) ;
F_11 ( V_2 , V_4 , & V_23 -> V_42 ) ;
V_98 = V_96 ;
for ( V_24 = 0 ; V_24 < V_5 ; V_24 ++ , V_98 += V_97 ) {
V_100 [ V_24 ] . V_32 = V_98 -> V_105 ;
V_100 [ V_24 ] . V_34 = V_98 -> V_106 ;
V_100 [ V_24 ] . V_31 = V_98 -> y1 ;
V_100 [ V_24 ] . V_33 = V_98 -> V_107 ;
}
F_14 ( V_7 ) ;
F_23 ( V_2 , V_4 , V_91 , false ) ;
F_24 ( V_4 ) ;
V_109:
if ( V_12 )
F_18 ( V_4 ) ;
V_74:
F_26 ( V_2 , V_72 ) ;
V_108:
F_25 ( & V_7 ) ;
V_73:
if ( V_12 )
F_7 ( V_2 , V_4 ) ;
}
void F_30 ( struct V_1 * V_2 ,
T_3 V_65 , T_3 V_66 ,
T_3 V_111 , T_3 V_112 ,
T_3 V_62 , T_3 V_64 )
{
struct V_19 * V_23 ;
struct V_10 V_22 ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = F_5 ( V_2 , & V_4 ) ;
if ( V_12 )
return;
V_12 = F_17 ( V_4 , true ) ;
if ( V_12 )
goto V_113;
V_22 . V_32 = V_62 ;
V_22 . V_31 = V_64 ;
V_22 . V_34 = V_62 + V_65 ;
V_22 . V_33 = V_64 + V_66 ;
V_12 = F_9 ( V_2 , 0 , V_114 , & V_22 , V_4 ) ;
if ( V_12 ) {
F_18 ( V_4 ) ;
goto V_113;
}
V_23 = (struct V_19 * ) F_10 ( V_2 , V_4 ) ;
V_23 -> V_79 . V_115 . V_116 . V_61 = V_111 ;
V_23 -> V_79 . V_115 . V_116 . V_63 = V_112 ;
F_11 ( V_2 , V_4 , & V_23 -> V_42 ) ;
F_23 ( V_2 , V_4 , V_91 , false ) ;
F_24 ( V_4 ) ;
V_113:
if ( V_12 )
F_7 ( V_2 , V_4 ) ;
}
void F_31 ( struct F_31 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_2 ;
struct V_10 V_22 = V_117 -> V_22 ;
V_45 V_94 = V_117 -> V_94 ;
T_4 V_118 = V_117 -> V_118 ;
struct V_19 * V_23 ;
struct V_3 * V_4 ;
int V_12 ;
V_12 = F_5 ( V_2 , & V_4 ) ;
if ( V_12 )
return;
V_12 = F_17 ( V_4 , true ) ;
if ( V_12 )
goto V_113;
V_12 = F_9 ( V_2 , 0 , V_119 , & V_22 , V_4 ) ;
if ( V_12 ) {
F_18 ( V_4 ) ;
goto V_113;
}
V_23 = (struct V_19 * ) F_10 ( V_2 , V_4 ) ;
V_23 -> V_79 . V_120 . V_121 . type = V_122 ;
V_23 -> V_79 . V_120 . V_121 . V_79 . V_94 = V_94 ;
V_23 -> V_79 . V_120 . V_84 = V_118 ;
V_23 -> V_79 . V_120 . V_87 . V_88 = 0 ;
V_23 -> V_79 . V_120 . V_87 . V_89 . V_61 = 0 ;
V_23 -> V_79 . V_120 . V_87 . V_89 . V_63 = 0 ;
V_23 -> V_79 . V_120 . V_87 . V_80 = 0 ;
F_11 ( V_2 , V_4 , & V_23 -> V_42 ) ;
F_23 ( V_2 , V_4 , V_91 , false ) ;
F_24 ( V_4 ) ;
V_113:
if ( V_12 )
F_7 ( V_2 , V_4 ) ;
}
