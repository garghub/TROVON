static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 -> V_5 ) ;
V_2 -> V_6 = F_2 ( V_4 -> V_6 ) ;
V_2 -> V_7 = F_2 ( V_4 -> V_7 ) ;
V_2 -> V_8 = F_2 ( V_4 -> V_8 ) ;
V_2 -> V_9 = F_2 ( V_4 -> V_9 ) ;
V_2 -> V_10 = F_2 ( V_4 -> V_10 ) ;
}
static int F_3 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_19 * V_20 = V_13 ;
return F_4 ( V_15 , V_17 -> V_21 ,
V_20 -> V_22 ,
& V_20 -> V_23 ) ;
}
static int F_5 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
V_34 = F_6 ( V_25 , V_27 , true , NULL ) ;
if ( V_34 != 0 )
return V_34 ;
F_7 (buf, head, head) {
V_31 = V_29 -> V_31 ;
V_33 = F_8 ( V_31 , struct V_32 , V_35 ) ;
V_34 = F_9 ( V_31 , & V_33 -> V_36 , false , false ) ;
if ( V_34 ) {
F_10 ( V_25 , V_27 ) ;
return V_34 ;
}
}
return 0 ;
}
static void F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
F_7 (buf, head, head) {
V_31 = V_29 -> V_31 ;
V_33 = F_8 ( V_31 , struct V_32 , V_35 ) ;
F_12 ( & V_33 -> V_37 ) ;
}
}
static int F_13 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_14 )
{
struct V_38 * V_39 = V_13 ;
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_40 * V_41 = V_14 -> V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_32 * V_33 ;
int V_34 ;
T_1 * V_47 = NULL ;
void T_2 * V_48 = NULL ;
struct V_26 V_49 ;
struct V_28 * V_50 = NULL ;
int V_51 ;
struct V_24 V_25 ;
void * V_29 ;
if ( V_17 -> V_52 == false )
return - V_53 ;
F_14 ( & V_49 ) ;
if ( V_39 -> V_54 ) {
V_47 = F_15 ( V_39 -> V_54 ,
sizeof( T_1 ) , V_55 ) ;
V_50 = F_15 ( V_39 -> V_54 ,
sizeof( struct V_28 ) ,
V_55 | V_56 ) ;
if ( ! V_47 || ! V_50 ) {
F_16 ( V_47 ) ;
F_16 ( V_50 ) ;
return - V_57 ;
}
V_48 = ( void T_2 * ) ( V_58 ) V_39 -> V_47 ;
if ( F_17 ( V_47 , V_48 ,
V_39 -> V_54 * sizeof( T_1 ) ) ) {
V_34 = - V_59 ;
F_16 ( V_47 ) ;
F_16 ( V_50 ) ;
return V_34 ;
}
for ( V_51 = 0 ; V_51 < V_39 -> V_54 ; V_51 ++ ) {
V_44 = F_18 ( V_14 , V_47 [ V_51 ] ) ;
if ( ! V_44 ) {
F_16 ( V_47 ) ;
F_16 ( V_50 ) ;
return - V_60 ;
}
V_33 = F_19 ( V_44 ) ;
V_50 [ V_51 ] . V_31 = & V_33 -> V_35 ;
F_20 ( & V_50 [ V_51 ] . V_27 , & V_49 ) ;
}
F_16 ( V_47 ) ;
}
V_34 = F_5 ( & V_25 , & V_49 ) ;
if ( V_34 )
goto V_61;
V_29 = F_21 ( ( void T_2 * ) ( V_58 ) V_39 -> V_62 ,
V_39 -> V_63 ) ;
if ( F_22 ( V_29 ) ) {
V_34 = F_23 ( V_29 ) ;
goto V_64;
}
F_24 ( V_17 , V_29 , V_39 -> V_63 ,
V_41 -> V_65 , & V_46 ) ;
F_25 ( & V_25 , & V_49 , & V_46 -> V_66 ) ;
F_11 ( & V_49 ) ;
F_16 ( V_50 ) ;
F_26 ( & V_46 -> V_66 ) ;
return 0 ;
V_64:
F_10 ( & V_25 , & V_49 ) ;
V_61:
F_11 ( & V_49 ) ;
F_16 ( V_50 ) ;
return V_34 ;
}
static int F_27 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_67 * V_68 = V_13 ;
int V_69 ;
switch ( V_68 -> V_68 ) {
case V_70 :
V_69 = V_17 -> V_52 == true ? 1 : 0 ;
break;
default:
return - V_71 ;
}
if ( F_28 ( ( void T_2 * ) ( unsigned long ) V_68 -> V_69 ,
& V_69 , sizeof( int ) ) ) {
return - V_59 ;
}
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_72 * V_73 = V_13 ;
int V_34 ;
T_1 V_74 ;
struct V_32 * V_33 ;
struct V_43 * V_75 ;
T_1 V_22 = 0 ;
T_1 V_63 ;
struct V_26 V_49 ;
struct V_28 V_76 ;
struct V_45 * V_46 = NULL ;
struct V_24 V_25 ;
struct V_77 V_78 ;
if ( V_17 -> V_52 == false ) {
if ( V_73 -> V_79 > 1 )
return - V_71 ;
if ( V_73 -> V_80 > 1 )
return - V_71 ;
if ( V_73 -> V_81 > 1 )
return - V_71 ;
if ( V_73 -> V_82 != 2 )
return - V_71 ;
if ( V_73 -> V_83 > 1 )
return - V_71 ;
}
F_14 ( & V_49 ) ;
memset ( & V_76 , 0 , sizeof( struct V_28 ) ) ;
F_30 ( V_17 , & V_74 ) ;
V_63 = V_73 -> V_63 ;
if ( V_63 == 0 )
V_63 = V_84 ;
V_33 = F_31 ( V_12 , V_63 , false , false ) ;
if ( F_22 ( V_33 ) ) {
V_34 = F_23 ( V_33 ) ;
goto V_85;
}
V_75 = & V_33 -> V_37 ;
if ( ! V_17 -> V_52 ) {
F_32 ( V_17 , V_74 , V_73 -> V_86 ,
V_73 -> V_87 , V_73 -> V_88 ) ;
V_34 = F_33 ( V_17 , V_33 , V_74 , NULL ) ;
} else {
F_34 ( & V_33 -> V_37 ) ;
V_76 . V_31 = & V_33 -> V_35 ;
F_20 ( & V_76 . V_27 , & V_49 ) ;
V_34 = F_5 ( & V_25 , & V_49 ) ;
if ( V_34 ) {
F_35 ( L_1 ) ;
goto V_89;
}
V_78 . V_90 = F_2 ( V_74 ) ;
V_78 . V_82 = F_2 ( V_73 -> V_82 ) ;
V_78 . V_86 = F_2 ( V_73 -> V_86 ) ;
V_78 . V_91 = F_2 ( V_73 -> V_91 ) ;
V_78 . V_87 = F_2 ( V_73 -> V_87 ) ;
V_78 . V_88 = F_2 ( V_73 -> V_88 ) ;
V_78 . V_79 = F_2 ( V_73 -> V_79 ) ;
V_78 . V_83 = F_2 ( V_73 -> V_83 ) ;
V_78 . V_81 = F_2 ( V_73 -> V_81 ) ;
V_78 . V_80 = F_2 ( V_73 -> V_80 ) ;
V_78 . V_92 = F_2 ( V_73 -> V_92 ) ;
F_36 ( V_17 , & V_78 , NULL ) ;
V_34 = F_33 ( V_17 , V_33 , V_74 , & V_46 ) ;
if ( V_34 ) {
F_10 ( & V_25 , & V_49 ) ;
goto V_89;
}
F_25 ( & V_25 , & V_49 , & V_46 -> V_66 ) ;
}
V_33 -> V_93 = V_74 ;
V_34 = F_37 ( V_15 , V_75 , & V_22 ) ;
if ( V_34 ) {
F_38 ( V_75 ) ;
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_26 ( & V_46 -> V_66 ) ;
}
return V_34 ;
}
F_12 ( V_75 ) ;
V_73 -> V_94 = V_74 ;
V_73 -> V_95 = V_22 ;
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_26 ( & V_46 -> V_66 ) ;
}
return 0 ;
V_89:
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_26 ( & V_46 -> V_66 ) ;
}
V_85:
F_39 ( V_17 , V_74 ) ;
return V_34 ;
}
static int F_40 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_96 * V_97 = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
V_44 = F_18 ( V_15 , V_97 -> V_95 ) ;
if ( V_44 == NULL )
return - V_60 ;
V_33 = F_19 ( V_44 ) ;
V_97 -> V_63 = V_33 -> V_37 . V_63 ;
V_97 -> V_94 = V_33 -> V_93 ;
F_12 ( V_44 ) ;
return 0 ;
}
static int F_41 ( struct V_11 * V_12 ,
void * V_13 ,
struct V_14 * V_98 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_40 * V_41 = V_98 -> V_42 ;
struct V_99 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_45 * V_46 ;
int V_34 ;
T_3 V_23 = args -> V_23 ;
struct V_1 V_100 ;
if ( V_17 -> V_52 == false )
return - V_53 ;
V_44 = F_18 ( V_98 , args -> V_95 ) ;
if ( V_44 == NULL )
return - V_60 ;
V_33 = F_19 ( V_44 ) ;
V_34 = F_42 ( V_33 , false ) ;
if ( V_34 )
goto V_101;
V_34 = F_9 ( & V_33 -> V_35 , & V_33 -> V_36 ,
true , false ) ;
if ( F_43 ( V_34 ) )
goto V_102;
F_1 ( & V_100 , & args -> V_100 ) ;
F_44
( V_17 , V_33 -> V_93 ,
V_41 -> V_65 , V_23 , args -> V_103 ,
& V_100 , & V_46 ) ;
F_45 ( V_33 -> V_35 . V_104 ,
& V_46 -> V_66 ) ;
F_26 ( & V_46 -> V_66 ) ;
V_102:
F_46 ( V_33 ) ;
V_101:
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_47 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_98 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_40 * V_41 = V_98 -> V_42 ;
struct V_105 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_45 * V_46 ;
struct V_1 V_100 ;
int V_34 ;
T_3 V_23 = args -> V_23 ;
V_44 = F_18 ( V_98 , args -> V_95 ) ;
if ( V_44 == NULL )
return - V_60 ;
V_33 = F_19 ( V_44 ) ;
V_34 = F_42 ( V_33 , false ) ;
if ( V_34 )
goto V_101;
V_34 = F_9 ( & V_33 -> V_35 , & V_33 -> V_36 ,
true , false ) ;
if ( F_43 ( V_34 ) )
goto V_102;
F_1 ( & V_100 , & args -> V_100 ) ;
if ( ! V_17 -> V_52 ) {
F_48
( V_17 , V_33 -> V_93 , V_23 ,
V_100 . V_8 , V_100 . V_9 , V_100 . V_5 , V_100 . V_6 , NULL ) ;
} else {
F_49
( V_17 , V_33 -> V_93 ,
V_41 ? V_41 -> V_65 : 0 , V_23 ,
args -> V_103 , & V_100 , & V_46 ) ;
F_45 ( V_33 -> V_35 . V_104 ,
& V_46 -> V_66 ) ;
F_26 ( & V_46 -> V_66 ) ;
}
V_102:
F_46 ( V_33 ) ;
V_101:
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_50 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_98 )
{
struct V_106 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
int V_34 ;
bool V_107 = false ;
V_44 = F_18 ( V_98 , args -> V_22 ) ;
if ( V_44 == NULL )
return - V_60 ;
V_33 = F_19 ( V_44 ) ;
if ( args -> V_92 & V_108 )
V_107 = true ;
V_34 = F_51 ( V_33 , V_107 ) ;
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_52 ( struct V_11 * V_12 ,
void * V_13 , struct V_14 * V_98 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_109 * args = V_13 ;
int V_63 ;
int V_51 ;
int V_110 = - 1 ;
int V_34 ;
struct V_111 * V_112 ;
void * V_113 ;
if ( V_17 -> V_114 == 0 )
return - V_53 ;
F_53 ( & V_17 -> V_115 ) ;
for ( V_51 = 0 ; V_51 < V_17 -> V_114 ; V_51 ++ ) {
if ( V_17 -> V_116 [ V_51 ] . V_117 == args -> V_118 ) {
if ( V_17 -> V_116 [ V_51 ] . V_119 >= args -> V_120 ) {
V_110 = V_51 ;
break;
}
}
}
if ( V_110 == - 1 ) {
F_54 ( & V_17 -> V_115 ) ;
return - V_71 ;
}
V_63 = V_17 -> V_116 [ V_110 ] . V_121 ;
if ( args -> V_63 > V_63 ) {
F_54 ( & V_17 -> V_115 ) ;
return - V_71 ;
}
F_7 (cache_ent, &vgdev->cap_cache, head) {
if ( V_112 -> V_117 == args -> V_118 &&
V_112 -> V_122 == args -> V_120 ) {
V_113 = V_112 -> V_123 ;
F_54 ( & V_17 -> V_115 ) ;
goto V_124;
}
}
F_54 ( & V_17 -> V_115 ) ;
F_55 ( V_17 , V_110 , args -> V_120 ,
& V_112 ) ;
V_34 = F_56 ( V_17 -> V_125 ,
F_57 ( & V_112 -> V_126 ) , 5 * V_127 ) ;
V_113 = V_112 -> V_123 ;
V_124:
if ( F_28 ( ( void T_2 * ) ( unsigned long ) args -> V_128 , V_113 , V_63 ) )
return - V_59 ;
return 0 ;
}
