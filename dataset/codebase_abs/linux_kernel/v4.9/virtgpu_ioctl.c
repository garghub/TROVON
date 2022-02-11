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
sizeof( T_1 ) ) ;
V_50 = F_16 ( V_39 -> V_54 ,
sizeof( struct V_28 ) ) ;
if ( ! V_47 || ! V_50 ) {
F_17 ( V_47 ) ;
F_17 ( V_50 ) ;
return - V_55 ;
}
V_48 = ( void T_2 * ) ( V_56 ) V_39 -> V_47 ;
if ( F_18 ( V_47 , V_48 ,
V_39 -> V_54 * sizeof( T_1 ) ) ) {
V_34 = - V_57 ;
F_17 ( V_47 ) ;
F_17 ( V_50 ) ;
return V_34 ;
}
for ( V_51 = 0 ; V_51 < V_39 -> V_54 ; V_51 ++ ) {
V_44 = F_19 ( V_14 , V_47 [ V_51 ] ) ;
if ( ! V_44 ) {
F_17 ( V_47 ) ;
F_17 ( V_50 ) ;
return - V_58 ;
}
V_33 = F_20 ( V_44 ) ;
V_50 [ V_51 ] . V_31 = & V_33 -> V_35 ;
F_21 ( & V_50 [ V_51 ] . V_27 , & V_49 ) ;
}
F_17 ( V_47 ) ;
}
V_34 = F_5 ( & V_25 , & V_49 ) ;
if ( V_34 )
goto V_59;
V_29 = F_22 ( ( void T_2 * ) ( V_56 ) V_39 -> V_60 ,
V_39 -> V_61 ) ;
if ( F_23 ( V_29 ) ) {
V_34 = F_24 ( V_29 ) ;
goto V_62;
}
F_25 ( V_17 , V_29 , V_39 -> V_61 ,
V_41 -> V_63 , & V_46 ) ;
F_26 ( & V_25 , & V_49 , & V_46 -> V_64 ) ;
F_11 ( & V_49 ) ;
F_17 ( V_50 ) ;
F_27 ( & V_46 -> V_64 ) ;
return 0 ;
V_62:
F_10 ( & V_25 , & V_49 ) ;
V_59:
F_11 ( & V_49 ) ;
F_17 ( V_50 ) ;
return V_34 ;
}
static int F_28 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_65 * V_66 = V_13 ;
int V_67 ;
switch ( V_66 -> V_66 ) {
case V_68 :
V_67 = V_17 -> V_52 == true ? 1 : 0 ;
break;
default:
return - V_69 ;
}
if ( F_29 ( ( void T_2 * ) ( unsigned long ) V_66 -> V_67 ,
& V_67 , sizeof( int ) ) ) {
return - V_57 ;
}
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_70 * V_71 = V_13 ;
int V_34 ;
T_1 V_72 ;
struct V_32 * V_33 ;
struct V_43 * V_73 ;
T_1 V_22 = 0 ;
T_1 V_61 ;
struct V_26 V_49 ;
struct V_28 V_74 ;
struct V_45 * V_46 = NULL ;
struct V_24 V_25 ;
struct V_75 V_76 ;
if ( V_17 -> V_52 == false ) {
if ( V_71 -> V_77 > 1 )
return - V_69 ;
if ( V_71 -> V_78 > 1 )
return - V_69 ;
if ( V_71 -> V_79 > 1 )
return - V_69 ;
if ( V_71 -> V_80 != 2 )
return - V_69 ;
if ( V_71 -> V_81 > 1 )
return - V_69 ;
}
F_14 ( & V_49 ) ;
memset ( & V_74 , 0 , sizeof( struct V_28 ) ) ;
F_31 ( V_17 , & V_72 ) ;
V_61 = V_71 -> V_61 ;
if ( V_61 == 0 )
V_61 = V_82 ;
V_33 = F_32 ( V_12 , V_61 , false , false ) ;
if ( F_23 ( V_33 ) ) {
V_34 = F_24 ( V_33 ) ;
goto V_83;
}
V_73 = & V_33 -> V_37 ;
if ( ! V_17 -> V_52 ) {
F_33 ( V_17 , V_72 , V_71 -> V_84 ,
V_71 -> V_85 , V_71 -> V_86 ) ;
V_34 = F_34 ( V_17 , V_33 , V_72 , NULL ) ;
} else {
F_35 ( & V_33 -> V_37 ) ;
V_74 . V_31 = & V_33 -> V_35 ;
F_21 ( & V_74 . V_27 , & V_49 ) ;
V_34 = F_5 ( & V_25 , & V_49 ) ;
if ( V_34 ) {
F_36 ( L_1 ) ;
goto V_87;
}
V_76 . V_88 = F_2 ( V_72 ) ;
V_76 . V_80 = F_2 ( V_71 -> V_80 ) ;
V_76 . V_84 = F_2 ( V_71 -> V_84 ) ;
V_76 . V_89 = F_2 ( V_71 -> V_89 ) ;
V_76 . V_85 = F_2 ( V_71 -> V_85 ) ;
V_76 . V_86 = F_2 ( V_71 -> V_86 ) ;
V_76 . V_77 = F_2 ( V_71 -> V_77 ) ;
V_76 . V_81 = F_2 ( V_71 -> V_81 ) ;
V_76 . V_79 = F_2 ( V_71 -> V_79 ) ;
V_76 . V_78 = F_2 ( V_71 -> V_78 ) ;
V_76 . V_90 = F_2 ( V_71 -> V_90 ) ;
F_37 ( V_17 , & V_76 , NULL ) ;
V_34 = F_34 ( V_17 , V_33 , V_72 , & V_46 ) ;
if ( V_34 ) {
F_10 ( & V_25 , & V_49 ) ;
goto V_87;
}
F_26 ( & V_25 , & V_49 , & V_46 -> V_64 ) ;
}
V_33 -> V_91 = V_72 ;
V_34 = F_38 ( V_15 , V_73 , & V_22 ) ;
if ( V_34 ) {
F_39 ( V_73 ) ;
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_27 ( & V_46 -> V_64 ) ;
}
return V_34 ;
}
F_12 ( V_73 ) ;
V_71 -> V_92 = V_72 ;
V_71 -> V_93 = V_22 ;
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_27 ( & V_46 -> V_64 ) ;
}
return 0 ;
V_87:
if ( V_17 -> V_52 ) {
F_11 ( & V_49 ) ;
F_27 ( & V_46 -> V_64 ) ;
}
V_83:
F_40 ( V_17 , V_72 ) ;
return V_34 ;
}
static int F_41 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_15 )
{
struct V_94 * V_95 = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
V_44 = F_19 ( V_15 , V_95 -> V_93 ) ;
if ( V_44 == NULL )
return - V_58 ;
V_33 = F_20 ( V_44 ) ;
V_95 -> V_61 = V_33 -> V_37 . V_61 ;
V_95 -> V_92 = V_33 -> V_91 ;
F_12 ( V_44 ) ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 ,
void * V_13 ,
struct V_14 * V_96 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_40 * V_41 = V_96 -> V_42 ;
struct V_97 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_45 * V_46 ;
int V_34 ;
T_3 V_23 = args -> V_23 ;
struct V_1 V_98 ;
if ( V_17 -> V_52 == false )
return - V_53 ;
V_44 = F_19 ( V_96 , args -> V_93 ) ;
if ( V_44 == NULL )
return - V_58 ;
V_33 = F_20 ( V_44 ) ;
V_34 = F_43 ( V_33 , false ) ;
if ( V_34 )
goto V_99;
V_34 = F_9 ( & V_33 -> V_35 , & V_33 -> V_36 ,
true , false ) ;
if ( F_44 ( V_34 ) )
goto V_100;
F_1 ( & V_98 , & args -> V_98 ) ;
F_45
( V_17 , V_33 -> V_91 ,
V_41 -> V_63 , V_23 , args -> V_101 ,
& V_98 , & V_46 ) ;
F_46 ( V_33 -> V_35 . V_102 ,
& V_46 -> V_64 ) ;
F_27 ( & V_46 -> V_64 ) ;
V_100:
F_47 ( V_33 ) ;
V_99:
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_48 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_96 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_40 * V_41 = V_96 -> V_42 ;
struct V_103 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_45 * V_46 ;
struct V_1 V_98 ;
int V_34 ;
T_3 V_23 = args -> V_23 ;
V_44 = F_19 ( V_96 , args -> V_93 ) ;
if ( V_44 == NULL )
return - V_58 ;
V_33 = F_20 ( V_44 ) ;
V_34 = F_43 ( V_33 , false ) ;
if ( V_34 )
goto V_99;
V_34 = F_9 ( & V_33 -> V_35 , & V_33 -> V_36 ,
true , false ) ;
if ( F_44 ( V_34 ) )
goto V_100;
F_1 ( & V_98 , & args -> V_98 ) ;
if ( ! V_17 -> V_52 ) {
F_49
( V_17 , V_33 -> V_91 , V_23 ,
V_98 . V_8 , V_98 . V_9 , V_98 . V_5 , V_98 . V_6 , NULL ) ;
} else {
F_50
( V_17 , V_33 -> V_91 ,
V_41 ? V_41 -> V_63 : 0 , V_23 ,
args -> V_101 , & V_98 , & V_46 ) ;
F_46 ( V_33 -> V_35 . V_102 ,
& V_46 -> V_64 ) ;
F_27 ( & V_46 -> V_64 ) ;
}
V_100:
F_47 ( V_33 ) ;
V_99:
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_51 ( struct V_11 * V_12 , void * V_13 ,
struct V_14 * V_96 )
{
struct V_104 * args = V_13 ;
struct V_43 * V_44 = NULL ;
struct V_32 * V_33 = NULL ;
int V_34 ;
bool V_105 = false ;
V_44 = F_19 ( V_96 , args -> V_22 ) ;
if ( V_44 == NULL )
return - V_58 ;
V_33 = F_20 ( V_44 ) ;
if ( args -> V_90 & V_106 )
V_105 = true ;
V_34 = F_52 ( V_33 , V_105 ) ;
F_12 ( V_44 ) ;
return V_34 ;
}
static int F_53 ( struct V_11 * V_12 ,
void * V_13 , struct V_14 * V_96 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_107 * args = V_13 ;
int V_61 ;
int V_51 ;
int V_108 = - 1 ;
int V_34 ;
struct V_109 * V_110 ;
void * V_111 ;
if ( V_17 -> V_112 == 0 )
return - V_53 ;
F_54 ( & V_17 -> V_113 ) ;
for ( V_51 = 0 ; V_51 < V_17 -> V_112 ; V_51 ++ ) {
if ( V_17 -> V_114 [ V_51 ] . V_115 == args -> V_116 ) {
if ( V_17 -> V_114 [ V_51 ] . V_117 >= args -> V_118 ) {
V_108 = V_51 ;
break;
}
}
}
if ( V_108 == - 1 ) {
F_55 ( & V_17 -> V_113 ) ;
return - V_69 ;
}
V_61 = V_17 -> V_114 [ V_108 ] . V_119 ;
if ( args -> V_61 > V_61 ) {
F_55 ( & V_17 -> V_113 ) ;
return - V_69 ;
}
F_7 (cache_ent, &vgdev->cap_cache, head) {
if ( V_110 -> V_115 == args -> V_116 &&
V_110 -> V_120 == args -> V_118 ) {
V_111 = V_110 -> V_121 ;
F_55 ( & V_17 -> V_113 ) ;
goto V_122;
}
}
F_55 ( & V_17 -> V_113 ) ;
F_56 ( V_17 , V_108 , args -> V_118 ,
& V_110 ) ;
V_34 = F_57 ( V_17 -> V_123 ,
F_58 ( & V_110 -> V_124 ) , 5 * V_125 ) ;
V_111 = V_110 -> V_121 ;
V_122:
if ( F_29 ( ( void T_2 * ) ( unsigned long ) args -> V_126 , V_111 , V_61 ) )
return - V_57 ;
return 0 ;
}
