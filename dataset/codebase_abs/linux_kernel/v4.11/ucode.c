static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
T_1 * V_5 = V_2 -> V_6 -> V_5 ;
F_2 ( & V_4 . V_7 , V_8 ) ;
V_4 . V_9 = F_3 ( V_5 [ 0 ] ) ;
V_4 . V_10 = F_3 ( V_5 [ 1 ] ) ;
return F_4 ( V_2 , ( void * ) & V_4 , sizeof( V_4 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_11 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_2 ( & V_4 . V_7 , V_12 ) ;
V_4 . V_13 = V_2 -> V_6 -> V_14 ;
if ( ! ( V_4 . V_13 ) )
V_4 . V_13 = V_15 ;
F_6 ( V_2 , L_1 ,
F_3 ( V_4 . V_13 ) ) ;
return F_4 ( V_2 , ( void * ) & V_4 , sizeof( V_4 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_16 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_2 ( & V_4 . V_7 , V_12 ) ;
V_4 . V_17 = V_2 -> V_6 -> V_18 ;
V_4 . V_19 = V_2 -> V_6 -> V_14 ;
if ( ! V_4 . V_19 ) {
F_6 ( V_2 , L_2 ) ;
V_4 . V_19 = V_15 ;
V_4 . V_17 = V_15 ;
}
V_4 . V_20 = V_2 -> V_6 -> V_21 ;
F_6 ( V_2 , L_3 ,
F_3 ( V_4 . V_17 ) ) ;
F_6 ( V_2 , L_4 ,
F_3 ( V_4 . V_19 ) ) ;
F_6 ( V_2 , L_5 ,
F_3 ( V_4 . V_20 ) ) ;
return F_4 ( V_2 , ( void * ) & V_4 , sizeof( V_4 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_22 V_23 ;
struct V_24 V_4 = {
. V_25 = V_26 ,
. V_27 = { sizeof( struct V_22 ) , } ,
. V_28 = { & V_23 , } ,
} ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_29 . V_30 . V_31 = V_32 ;
V_23 . V_29 . V_30 . V_33 = V_32 ;
V_23 . V_29 . V_30 . V_34 = V_32 ;
V_23 . V_29 . V_35 =
V_36 ;
return F_9 ( V_2 , & V_4 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_37 ;
if ( V_2 -> V_38 -> V_39 &&
V_2 -> V_38 -> V_39 -> V_40 ) {
V_37 = F_11 ( V_2 , V_41 ,
V_42 ) ;
if ( V_37 )
return V_37 ;
}
V_37 = F_8 ( V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 -> V_38 -> V_43 ) {
if ( V_2 -> V_38 -> V_44 )
return F_7 ( V_2 ) ;
else
return F_5 ( V_2 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_45 V_46 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
return F_13 ( V_2 ,
V_47 , 0 ,
sizeof( V_46 ) , & V_46 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_48 V_49 ;
memcpy ( V_49 . V_50 , V_51 ,
sizeof( V_51 ) ) ;
if ( F_13 ( V_2 ,
V_52 , 0 ,
sizeof( V_49 ) , & V_49 ) )
F_15 ( V_2 , L_6 ) ;
}
int F_11 ( struct V_1 * V_2 , T_2 V_53 , T_2 type )
{
struct V_54 V_55 ;
int V_37 ;
V_55 . V_53 = V_53 ;
V_55 . type = type ;
V_37 = F_13 ( V_2 ,
V_56 , 0 ,
sizeof( V_55 ) , & V_55 ) ;
if ( V_37 )
F_15 ( V_2 , L_7 ) ;
return V_37 ;
}
static int F_16 ( struct V_1 * V_2 )
{
const T_2 * V_57 ;
T_2 V_58 ;
int V_37 ;
int V_59 ;
F_17 ( V_2 -> V_60 , 0 ) ;
if ( V_2 -> V_61 -> V_62 . V_35 & V_63 &&
V_2 -> V_6 -> V_64 ) {
V_58 = F_18 ( V_65 ) ;
V_57 = V_65 ;
} else {
V_58 = F_18 ( V_66 ) ;
V_57 = V_66 ;
}
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ )
if ( V_57 [ V_59 ] != V_67 )
F_19 ( V_2 -> V_60 , V_59 ,
V_57 [ V_59 ] , 0 ) ;
V_2 -> V_68 = false ;
V_2 -> V_69 = 0 ;
V_37 = F_12 ( V_2 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_2 -> V_38 -> V_70 ) {
V_37 = F_1 ( V_2 ) ;
if ( V_37 )
return V_37 ;
}
return F_20 ( V_2 ) ;
}
static bool F_21 ( struct V_71 * V_72 ,
struct V_73 * V_74 , void * V_28 )
{
struct V_1 * V_2 =
F_22 ( V_72 , struct V_1 , V_72 ) ;
struct V_75 * V_76 = V_28 ;
struct V_77 * V_78 ;
V_78 = ( void * ) V_74 -> V_28 ;
F_23 ( V_2 , L_8
L_9 ,
V_78 -> V_79 , V_78 -> V_80 ,
V_78 -> V_81 ) ;
V_2 -> V_82 . V_83 =
F_24 ( V_78 -> V_84 ) ;
V_2 -> V_82 . V_85 =
F_24 ( V_78 -> V_86 ) ;
V_76 -> V_87 = V_78 -> V_81 ;
V_76 -> V_88 = V_78 -> V_79 == V_89 ;
return true ;
}
int F_25 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
struct V_92 V_93 ;
struct V_75 V_76 ;
const struct V_94 * V_61 ;
int V_37 ;
enum V_90 V_95 ;
static const T_3 V_96 [] = { V_97 } ;
V_61 = F_26 ( V_2 -> V_61 , V_91 ) ;
if ( F_27 ( ! V_61 ) )
return - V_98 ;
V_95 = V_2 -> V_99 ;
V_2 -> V_99 = V_91 ;
V_2 -> V_100 = false ;
F_28 ( & V_2 -> V_72 , & V_93 ,
V_96 , F_18 ( V_96 ) ,
F_21 , & V_76 ) ;
V_37 = F_29 ( V_2 -> V_60 , V_61 , false ) ;
if ( V_37 ) {
V_2 -> V_99 = V_95 ;
F_30 ( & V_2 -> V_72 , & V_93 ) ;
return V_37 ;
}
V_37 = F_31 ( & V_2 -> V_72 , & V_93 ,
V_101 ) ;
if ( V_37 ) {
V_2 -> V_99 = V_95 ;
return V_37 ;
}
if ( ! V_76 . V_88 ) {
F_15 ( V_2 , L_10 ) ;
V_2 -> V_99 = V_95 ;
return - V_102 ;
}
V_2 -> V_100 = true ;
if ( V_91 != V_103 ) {
F_32 ( 5 ) ;
}
V_37 = F_16 ( V_2 ) ;
if ( V_37 ) {
F_33 ( V_2 ,
L_11 , V_37 ) ;
V_2 -> V_99 = V_95 ;
return V_37 ;
}
return 0 ;
}
static bool F_34 ( struct V_71 * V_72 ,
struct V_73 * V_74 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
struct V_104 * V_7 ;
if ( V_74 -> V_7 . V_4 != V_105 ) {
F_27 ( V_74 -> V_7 . V_4 != V_106 ) ;
return true ;
}
V_7 = (struct V_104 * ) V_74 -> V_28 ;
if ( F_4 ( V_2 , V_7 , F_35 ( V_74 ) ) )
F_15 ( V_2 , L_12 ,
V_7 -> V_107 ) ;
return false ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_92 V_108 ;
static const T_3 V_109 [] = {
V_105 ,
V_106
} ;
int V_37 ;
F_37 ( & V_2 -> V_110 ) ;
if ( ! V_2 -> V_61 -> V_111 [ V_112 ] . V_113 )
return 0 ;
F_28 ( & V_2 -> V_72 , & V_108 ,
V_109 , F_18 ( V_109 ) ,
F_34 , V_2 ) ;
V_37 = F_25 ( V_2 , V_112 ) ;
if ( V_37 )
goto error;
V_37 = F_10 ( V_2 ) ;
if ( V_37 )
goto error;
V_37 = F_31 ( & V_2 -> V_72 , & V_108 ,
V_114 ) ;
goto V_115;
error:
F_30 ( & V_2 -> V_72 , & V_108 ) ;
V_115:
F_38 ( V_2 -> V_60 ) ;
V_2 -> V_100 = false ;
return V_37 ;
}
