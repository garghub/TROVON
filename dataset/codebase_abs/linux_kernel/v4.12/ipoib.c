static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_7 = V_7 ;
F_3 ( V_2 , & V_9 -> V_10 . V_11 , V_6 -> V_12 ( V_2 ) ) ;
F_4 ( V_2 , & V_9 -> V_10 . V_11 , V_13 ) ;
V_9 -> V_10 . V_11 . V_14 = false ;
F_5 ( & V_9 -> V_15 ) ;
V_4 -> V_16 |= V_17 ;
V_4 -> V_16 |= V_18 ;
V_4 -> V_16 |= V_19 ;
V_4 -> V_16 |= V_20 ;
V_4 -> V_16 |= V_21 ;
V_4 -> V_16 |= V_22 ;
V_4 -> V_16 |= V_23 ;
V_4 -> V_16 |= V_24 ;
V_4 -> V_25 = & V_26 ;
}
static void F_6 ( struct V_8 * V_9 )
{
}
static int F_7 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
T_1 * V_31 = NULL ;
void * V_32 ;
int V_33 = 0 ;
int V_34 ;
void * V_35 ;
V_34 = F_8 ( V_36 ) ;
V_31 = F_9 ( V_34 ) ;
if ( ! V_31 )
return - V_37 ;
V_35 = F_10 ( V_36 , V_31 , V_35 ) ;
F_11 ( V_35 , V_35 , V_38 , V_39 ) ;
F_11 ( V_35 , V_35 , V_40 , V_41 ) ;
F_11 ( V_35 , V_35 , V_42 ,
V_43 ) ;
V_32 = F_10 ( V_35 , V_35 , V_44 ) ;
F_11 ( V_45 , V_32 , V_46 , 1 ) ;
F_11 ( V_45 , V_32 , V_47 , 1 ) ;
V_33 = F_12 ( V_2 , V_28 , V_31 , V_34 ) ;
if ( V_33 ) {
F_13 ( V_2 , L_1 , V_33 ) ;
goto V_48;
}
V_30 = F_14 ( sizeof( * V_30 ) , V_49 ) ;
if ( ! V_30 ) {
V_33 = - V_37 ;
goto V_48;
}
V_30 -> V_50 = F_15 ( V_41 << 11 ) ;
V_30 -> V_51 . V_46 = 1 ;
V_30 -> V_52 = F_15 ( V_53 ) ;
V_33 = F_16 ( V_2 , V_54 , 0 , V_30 , V_28 ) ;
if ( V_33 ) {
F_13 ( V_2 , L_2 , V_33 ) ;
goto V_48;
}
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_33 = F_16 ( V_2 , V_55 , 0 , V_30 , V_28 ) ;
if ( V_33 ) {
F_13 ( V_2 , L_3 , V_33 ) ;
goto V_48;
}
V_33 = F_16 ( V_2 , V_56 , 0 , V_30 , V_28 ) ;
if ( V_33 ) {
F_13 ( V_2 , L_4 , V_33 ) ;
goto V_48;
}
V_48:
F_17 ( V_30 ) ;
F_18 ( V_31 ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_20 ( V_2 , V_28 -> V_57 ) ;
F_21 ( V_2 , V_28 ) ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_7 ;
int V_60 ;
V_60 = F_7 ( V_9 -> V_2 , & V_59 -> V_28 ) ;
if ( V_60 ) {
F_23 ( V_9 -> V_2 , L_5 , V_60 ) ;
return V_60 ;
}
F_24 ( V_9 -> V_2 , V_59 -> V_28 . V_57 ) ;
V_60 = F_25 ( V_9 -> V_2 , 0 , V_59 -> V_28 . V_57 , & V_9 -> V_61 [ 0 ] ) ;
if ( V_60 ) {
F_23 ( V_9 -> V_2 , L_6 , V_60 ) ;
return V_60 ;
}
return 0 ;
}
static void F_26 ( struct V_8 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_7 ;
F_27 ( V_9 -> V_2 , V_9 -> V_61 [ 0 ] ) ;
F_19 ( V_9 -> V_2 , & V_59 -> V_28 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
int V_60 ;
V_9 -> V_62 . V_63 = F_29 ( V_9 -> V_2 ,
V_64 ) ;
if ( ! V_9 -> V_62 . V_63 )
return - V_65 ;
V_60 = F_30 ( V_9 ) ;
if ( V_60 ) {
F_31 ( V_9 -> V_4 , L_7 ,
V_60 ) ;
V_9 -> V_4 -> V_16 &= ~ V_66 ;
}
V_60 = F_32 ( V_9 ) ;
if ( V_60 ) {
F_31 ( V_9 -> V_4 , L_8 ,
V_60 ) ;
goto V_67;
}
return 0 ;
V_67:
F_33 ( V_9 ) ;
return V_60 ;
}
static void F_34 ( struct V_8 * V_9 )
{
F_35 ( V_9 ) ;
F_33 ( V_9 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
int V_60 ;
V_60 = F_37 ( V_9 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_38 ( V_9 ) ;
if ( V_60 )
goto V_68;
V_60 = F_39 ( V_9 ) ;
if ( V_60 )
goto V_69;
V_60 = F_40 ( V_9 ) ;
if ( V_60 )
goto V_70;
V_60 = F_28 ( V_9 ) ;
if ( V_60 )
goto V_71;
return 0 ;
V_71:
F_41 ( V_9 ) ;
V_70:
F_42 ( V_9 ) ;
V_69:
F_43 ( V_9 ) ;
V_68:
F_44 ( V_9 , & V_9 -> V_72 ) ;
return V_60 ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_34 ( V_9 ) ;
F_41 ( V_9 ) ;
F_42 ( V_9 ) ;
F_43 ( V_9 ) ;
F_44 ( V_9 , & V_9 -> V_72 ) ;
}
static int F_46 ( struct V_3 * V_73 )
{
struct V_8 * V_9 = F_2 ( V_73 ) ;
struct V_58 * V_59 = V_9 -> V_7 ;
V_73 -> V_74 [ 1 ] = ( V_59 -> V_28 . V_57 >> 16 ) & 0xff ;
V_73 -> V_74 [ 2 ] = ( V_59 -> V_28 . V_57 >> 8 ) & 0xff ;
V_73 -> V_74 [ 3 ] = ( V_59 -> V_28 . V_57 ) & 0xff ;
return 0 ;
}
static void F_47 ( struct V_3 * V_73 )
{
struct V_8 * V_9 = F_2 ( V_73 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_58 * V_59 = V_9 -> V_7 ;
struct V_29 V_30 ;
F_16 ( V_2 , V_75 , 0 , & V_30 , & V_59 -> V_28 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
int V_60 ;
F_49 ( & V_9 -> V_15 ) ;
F_50 ( V_76 , & V_9 -> V_77 ) ;
V_60 = F_51 ( V_9 , & V_9 -> V_10 ) ;
if ( V_60 )
goto V_78;
F_52 ( V_9 , false ) ;
F_53 ( V_9 ) ;
F_54 ( & V_9 -> V_15 ) ;
return 0 ;
V_78:
F_55 ( V_76 , & V_9 -> V_77 ) ;
F_54 ( & V_9 -> V_15 ) ;
return V_60 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
F_49 ( & V_9 -> V_15 ) ;
if ( ! F_57 ( V_76 , & V_9 -> V_77 ) )
goto V_79;
F_55 ( V_76 , & V_9 -> V_77 ) ;
F_58 ( V_9 -> V_4 ) ;
F_59 ( V_9 ) ;
F_60 ( & V_9 -> V_10 ) ;
V_79:
F_54 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_3 * V_4 , struct V_80 * V_81 ,
union V_82 * V_83 , T_2 V_84 , int V_85 ,
T_1 V_52 )
{
struct V_8 * V_86 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_86 -> V_2 ;
struct V_58 * V_59 = V_86 -> V_7 ;
int V_60 ;
F_62 ( V_2 , L_9 , V_59 -> V_28 . V_57 , V_83 -> V_87 ) ;
V_60 = F_63 ( V_2 , V_83 , V_59 -> V_28 . V_57 ) ;
if ( V_60 )
F_23 ( V_2 , L_10 ,
V_59 -> V_28 . V_57 , V_83 -> V_87 ) ;
if ( V_85 ) {
F_62 ( V_2 , L_11 ,
V_4 -> V_88 , V_52 ) ;
V_59 -> V_52 = V_52 ;
}
return V_60 ;
}
static int F_64 ( struct V_3 * V_4 , struct V_80 * V_81 ,
union V_82 * V_83 , T_2 V_84 )
{
struct V_8 * V_86 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_86 -> V_2 ;
struct V_58 * V_59 = V_86 -> V_7 ;
int V_60 ;
F_62 ( V_2 , L_12 , V_59 -> V_28 . V_57 , V_83 -> V_87 ) ;
V_60 = F_65 ( V_2 , V_83 , V_59 -> V_28 . V_57 ) ;
if ( V_60 )
F_62 ( V_2 , L_13 ,
V_59 -> V_28 . V_57 , V_83 -> V_87 ) ;
return V_60 ;
}
static int F_66 ( struct V_3 * V_73 , struct V_89 * V_90 ,
struct V_91 * V_92 , T_1 V_93 )
{
struct V_8 * V_86 = F_2 ( V_73 ) ;
struct V_94 * V_95 = V_86 -> V_96 [ F_67 ( V_90 ) ] ;
struct V_97 * V_98 = F_68 ( V_92 ) ;
struct V_58 * V_59 = V_86 -> V_7 ;
return F_69 ( V_95 , V_90 , & V_98 -> V_99 , V_93 , V_59 -> V_52 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
if ( F_71 ( V_2 , V_100 ) != V_101 )
return - V_102 ;
if ( ! F_71 ( V_2 , V_103 ) ) {
F_23 ( V_2 , L_14 ) ;
return - V_102 ;
}
return 0 ;
}
struct V_3 * F_72 ( struct V_1 * V_2 ,
struct V_80 * V_104 ,
const char * V_88 ,
void (* F_73)( struct V_3 * ) )
{
const struct V_5 * V_6 = & V_105 ;
int V_106 = V_6 -> V_12 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
struct V_8 * V_86 ;
struct V_107 * V_108 ;
int V_60 ;
if ( F_70 ( V_2 ) ) {
F_23 ( V_2 , L_15 ) ;
return F_74 ( - V_102 ) ;
}
V_60 = F_75 ( V_2 ) ;
if ( V_60 )
return NULL ;
V_4 = F_76 ( sizeof( struct V_58 ) + sizeof( struct V_8 ) ,
V_88 , V_109 ,
F_73 ,
V_106 * V_110 ,
V_106 ) ;
if ( ! V_4 ) {
F_23 ( V_2 , L_16 ) ;
goto V_111;
}
V_59 = F_77 ( V_4 ) ;
V_86 = F_2 ( V_4 ) ;
V_86 -> V_112 = F_78 ( L_17 ) ;
if ( ! V_86 -> V_112 )
goto V_113;
V_6 -> V_114 ( V_2 , V_4 , V_6 , V_59 ) ;
F_79 ( V_86 ) ;
F_58 ( V_4 ) ;
V_108 = & V_59 -> V_108 ;
V_108 -> V_81 = V_104 ;
V_108 -> V_115 = F_66 ;
V_108 -> V_116 = F_61 ;
V_108 -> V_117 = F_64 ;
return V_4 ;
V_113:
F_80 ( V_4 ) ;
V_111:
F_81 ( V_2 ) ;
return NULL ;
}
void F_82 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
const struct V_5 * V_6 = V_9 -> V_6 ;
F_83 ( V_9 ) ;
V_6 -> V_118 ( V_9 ) ;
F_84 ( V_9 -> V_112 ) ;
F_80 ( V_4 ) ;
F_81 ( V_9 -> V_2 ) ;
}
