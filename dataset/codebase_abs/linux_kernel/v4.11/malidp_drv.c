static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 ;
F_2 ( & V_4 -> V_10 , 0 ) ;
V_7 -> V_11 ( V_7 ) ;
if ( V_7 -> V_12 ( V_7 ) )
return 0 ;
V_9 = F_3 ( V_4 -> V_13 ,
F_4 ( & V_4 -> V_10 ) == 1 ,
F_5 ( V_14 ) ) ;
return ( V_9 > 0 ) ? 0 : - V_15 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_7 ( V_4 -> V_16 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_18 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_9 ( L_1 ) ;
V_20 = V_4 -> V_21 . V_18 -> V_20 ;
if ( V_20 ) {
V_4 -> V_21 . V_18 -> V_20 = NULL ;
F_10 ( & V_2 -> V_22 ) ;
if ( F_11 ( & V_4 -> V_21 ) == 0 )
F_12 ( & V_4 -> V_21 , V_20 ) ;
else
F_13 ( & V_4 -> V_21 , V_20 ) ;
F_14 ( & V_2 -> V_22 ) ;
}
F_15 ( V_18 ) ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_8 ;
F_17 ( V_2 , V_18 ) ;
F_18 ( V_2 , V_18 ) ;
F_19 ( V_2 , V_18 , 0 ) ;
F_8 ( V_18 ) ;
F_20 ( V_2 , V_18 ) ;
F_21 ( V_2 , V_18 ) ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_23 ( V_7 , V_23 ,
V_7 -> V_24 . V_25 . V_26 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_25 ( V_7 , V_23 ,
V_7 -> V_24 . V_25 . V_26 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_27 ( V_2 ) ;
V_2 -> V_28 . V_29 = V_7 -> V_30 ;
V_2 -> V_28 . V_31 = V_7 -> V_30 ;
V_2 -> V_28 . V_32 = V_7 -> V_33 ;
V_2 -> V_28 . V_34 = V_7 -> V_33 ;
V_2 -> V_28 . V_35 = & V_36 ;
V_2 -> V_28 . V_37 = & V_38 ;
V_9 = F_28 ( V_2 ) ;
if ( V_9 ) {
F_29 ( V_2 ) ;
return V_9 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static int F_32 ( struct V_39 * V_40 )
{
int V_41 , V_42 , V_9 = 0 ;
struct V_1 * V_2 = F_33 ( & V_40 -> V_8 ) ;
V_41 = F_34 ( V_40 , L_2 ) ;
if ( V_41 < 0 ) {
F_35 ( L_3 ) ;
return V_41 ;
}
V_42 = F_34 ( V_40 , L_4 ) ;
if ( V_42 < 0 ) {
F_35 ( L_5 ) ;
return V_42 ;
}
V_9 = F_36 ( V_2 , V_41 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_37 ( V_2 , V_42 ) ;
if ( V_9 ) {
F_38 ( V_2 ) ;
return V_9 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( V_4 -> V_16 ) ;
}
static bool F_41 ( struct V_6 * V_7 ,
const struct V_43 * V_44 )
{
T_1 V_45 ;
const char * V_46 = L_6 ;
bool V_47 ;
bool V_48 ;
V_45 = F_42 ( V_7 , V_49 + V_50 ) ;
V_47 = ( F_43 ( V_45 ) == 0x500 ) ;
V_48 = F_44 ( V_44 -> V_51 , V_46 ,
sizeof( V_44 -> V_51 ) ) != NULL ;
if ( V_47 != V_48 ) {
F_35 ( L_7 ,
V_44 -> V_51 , V_47 ? L_8 : L_9 ) ;
return false ;
} else if ( ! V_48 ) {
T_2 V_52 ;
char V_53 [ 32 ] ;
V_45 = F_42 ( V_7 ,
V_54 + V_50 ) ;
V_52 = F_43 ( V_45 ) ;
snprintf ( V_53 , sizeof( V_53 ) , L_10 , V_52 ) ;
if ( ! F_44 ( V_44 -> V_51 , V_53 ,
sizeof( V_44 -> V_51 ) ) ) {
F_35 ( L_11 ,
V_44 -> V_51 , V_52 ) ;
return false ;
}
}
return true ;
}
static bool F_45 ( const struct V_55 * V_56 ,
const struct V_43 * V_44 )
{
T_3 V_57 = F_46 ( V_56 ) ;
const char * V_46 = L_6 ;
if ( ! F_44 ( V_44 -> V_51 , V_46 ,
sizeof( V_44 -> V_51 ) ) )
return V_57 >= V_58 ;
else if ( V_57 < V_59 )
return false ;
return true ;
}
static int F_47 ( struct V_60 * V_8 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_39 * V_40 = F_48 ( V_8 ) ;
struct V_43 const * V_44 ;
T_4 V_63 [ V_64 ] ;
int V_9 = 0 , V_65 ;
T_1 V_66 , V_67 = 0 ;
V_4 = F_49 ( V_8 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
V_7 = F_49 ( V_8 , sizeof( * V_7 ) , V_68 ) ;
if ( ! V_7 )
return - V_69 ;
memcpy ( V_7 , F_50 ( V_8 ) , sizeof( * V_7 ) ) ;
V_4 -> V_8 = V_7 ;
V_56 = F_51 ( V_40 , V_70 , 0 ) ;
V_7 -> V_71 = F_52 ( V_8 , V_56 ) ;
if ( F_53 ( V_7 -> V_71 ) )
return F_54 ( V_7 -> V_71 ) ;
V_7 -> V_72 = F_55 ( V_8 , L_12 ) ;
if ( F_53 ( V_7 -> V_72 ) )
return F_54 ( V_7 -> V_72 ) ;
V_7 -> V_73 = F_55 ( V_8 , L_13 ) ;
if ( F_53 ( V_7 -> V_73 ) )
return F_54 ( V_7 -> V_73 ) ;
V_7 -> V_74 = F_55 ( V_8 , L_14 ) ;
if ( F_53 ( V_7 -> V_74 ) )
return F_54 ( V_7 -> V_74 ) ;
V_7 -> V_75 = F_55 ( V_8 , L_15 ) ;
if ( F_53 ( V_7 -> V_75 ) )
return F_54 ( V_7 -> V_75 ) ;
V_9 = F_56 ( V_8 ) ;
if ( V_9 && V_9 != - V_76 )
return V_9 ;
V_2 = F_57 ( & V_77 , V_8 ) ;
if ( F_53 ( V_2 ) ) {
V_9 = F_54 ( V_2 ) ;
goto V_78;
}
F_58 ( V_7 -> V_72 ) ;
F_58 ( V_7 -> V_73 ) ;
F_58 ( V_7 -> V_74 ) ;
V_44 = F_59 ( V_79 , V_8 ) ;
if ( ! V_44 ) {
V_9 = - V_80 ;
goto V_81;
}
if ( ! F_45 ( V_56 , V_44 ) ) {
F_35 ( L_16 ) ;
V_9 = - V_80 ;
goto V_81;
}
if ( ! F_41 ( V_7 , V_44 ) ) {
V_9 = - V_80 ;
goto V_81;
}
V_9 = V_7 -> V_82 ( V_7 ) ;
if ( V_9 ) {
F_35 ( L_17 ) ;
goto V_81;
}
V_66 = F_42 ( V_7 , V_7 -> V_24 . V_83 + V_50 ) ;
F_60 ( L_18 , V_66 >> 16 ,
( V_66 >> 12 ) & 0xf , ( V_66 >> 8 ) & 0xf ) ;
V_9 = F_61 ( V_8 -> V_84 ,
L_19 ,
V_63 , V_64 ) ;
if ( V_9 )
goto V_81;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
V_67 = ( V_67 << 8 ) | ( V_63 [ V_65 ] & 0xf ) ;
F_62 ( V_7 , V_67 , V_7 -> V_24 . V_85 ) ;
V_2 -> V_5 = V_4 ;
F_63 ( V_8 , V_2 ) ;
F_2 ( & V_4 -> V_10 , 0 ) ;
F_64 ( & V_4 -> V_13 ) ;
V_9 = F_26 ( V_2 ) ;
if ( V_9 < 0 )
goto V_86;
V_62 = F_65 ( V_8 -> V_84 , NULL ) ;
if ( ! V_62 ) {
V_9 = - V_80 ;
goto V_87;
}
V_4 -> V_21 . V_88 = F_66 ( V_62 ) ;
V_9 = F_67 ( V_8 , V_2 ) ;
if ( V_9 ) {
F_35 ( L_20 ) ;
goto V_89;
}
V_9 = F_32 ( V_40 ) ;
if ( V_9 < 0 )
goto V_90;
V_2 -> V_91 = true ;
V_9 = F_68 ( V_2 , V_2 -> V_28 . V_92 ) ;
if ( V_9 < 0 ) {
F_35 ( L_21 ) ;
goto V_93;
}
F_69 ( V_2 ) ;
V_4 -> V_16 = F_70 ( V_2 , 32 ,
V_2 -> V_28 . V_94 ) ;
if ( F_53 ( V_4 -> V_16 ) ) {
V_9 = F_54 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
goto V_95;
}
F_71 ( V_2 ) ;
V_9 = F_72 ( V_2 , 0 ) ;
if ( V_9 )
goto V_96;
return 0 ;
V_96:
if ( V_4 -> V_16 ) {
F_73 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
}
V_95:
F_74 ( V_2 ) ;
V_93:
F_75 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_91 = false ;
V_90:
F_76 ( V_8 , V_2 ) ;
V_89:
F_77 ( V_4 -> V_21 . V_88 ) ;
V_4 -> V_21 . V_88 = NULL ;
V_87:
F_30 ( V_2 ) ;
V_86:
V_2 -> V_5 = NULL ;
F_63 ( V_8 , NULL ) ;
V_81:
F_78 ( V_7 -> V_74 ) ;
F_78 ( V_7 -> V_73 ) ;
F_78 ( V_7 -> V_72 ) ;
F_79 ( V_2 ) ;
V_78:
F_80 ( V_8 ) ;
return V_9 ;
}
static void F_81 ( struct V_60 * V_8 )
{
struct V_1 * V_2 = F_33 ( V_8 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_82 ( V_2 ) ;
if ( V_4 -> V_16 ) {
F_73 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
}
F_83 ( V_2 ) ;
F_75 ( V_2 ) ;
F_38 ( V_2 ) ;
F_74 ( V_2 ) ;
F_76 ( V_8 , V_2 ) ;
F_77 ( V_4 -> V_21 . V_88 ) ;
V_4 -> V_21 . V_88 = NULL ;
F_30 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_63 ( V_8 , NULL ) ;
F_78 ( V_7 -> V_74 ) ;
F_78 ( V_7 -> V_73 ) ;
F_78 ( V_7 -> V_72 ) ;
F_79 ( V_2 ) ;
F_80 ( V_8 ) ;
}
static int F_84 ( struct V_60 * V_8 , void * V_97 )
{
struct V_61 * V_98 = V_97 ;
return V_8 -> V_84 == V_98 ;
}
static int F_85 ( struct V_39 * V_40 )
{
struct V_61 * V_88 , * V_62 ;
struct V_99 * V_100 = NULL ;
if ( ! V_40 -> V_8 . V_84 )
return - V_76 ;
V_62 = F_65 ( V_40 -> V_8 . V_84 , NULL ) ;
if ( ! V_62 )
return - V_76 ;
if ( ! F_86 ( V_62 ) ) {
F_77 ( V_62 ) ;
return - V_76 ;
}
V_88 = F_87 ( V_62 ) ;
F_77 ( V_62 ) ;
if ( ! V_88 || ! F_86 ( V_88 ) ) {
F_77 ( V_88 ) ;
return - V_101 ;
}
F_88 ( & V_40 -> V_8 , & V_100 , F_84 ,
V_88 ) ;
F_77 ( V_88 ) ;
return F_89 ( & V_40 -> V_8 , & V_102 ,
V_100 ) ;
}
static int F_90 ( struct V_39 * V_40 )
{
F_91 ( & V_40 -> V_8 , & V_102 ) ;
return 0 ;
}
