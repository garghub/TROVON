static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 ;
V_7 -> V_10 ( V_7 ) ;
if ( V_7 -> V_11 ( V_7 ) )
return 0 ;
V_9 = F_2 ( V_4 -> V_12 ,
F_3 ( & V_4 -> V_13 ) == 1 ,
F_4 ( V_14 ) ) ;
return ( V_9 > 0 ) ? 0 : - V_15 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_6 ( V_4 -> V_16 ) ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_18 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_8 ( L_1 ) ;
V_20 = V_4 -> V_21 . V_18 -> V_20 ;
if ( V_20 ) {
V_4 -> V_21 . V_18 -> V_20 = NULL ;
F_9 ( & V_2 -> V_22 ) ;
if ( F_10 ( & V_4 -> V_21 ) == 0 )
F_11 ( & V_4 -> V_21 , V_20 ) ;
else
F_12 ( & V_4 -> V_21 , V_20 ) ;
F_13 ( & V_2 -> V_22 ) ;
}
F_14 ( V_18 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_8 ;
F_16 ( V_2 , V_18 ) ;
F_17 ( V_2 , V_18 ) ;
F_18 ( V_2 , V_18 , true ) ;
F_7 ( V_18 ) ;
F_19 ( V_2 , V_18 ) ;
F_20 ( V_2 , V_18 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_22 ( V_7 , V_23 ,
V_7 -> V_24 . V_25 . V_26 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_24 ( V_7 , V_23 ,
V_7 -> V_24 . V_25 . V_26 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_26 ( V_2 ) ;
V_2 -> V_28 . V_29 = V_7 -> V_30 ;
V_2 -> V_28 . V_31 = V_7 -> V_30 ;
V_2 -> V_28 . V_32 = V_7 -> V_33 ;
V_2 -> V_28 . V_34 = V_7 -> V_33 ;
V_2 -> V_28 . V_35 = & V_36 ;
V_2 -> V_28 . V_37 = & V_38 ;
V_9 = F_27 ( V_2 ) ;
if ( V_9 ) {
F_28 ( V_2 ) ;
return V_9 ;
}
return 0 ;
}
static int F_29 ( struct V_39 * V_40 )
{
int V_41 , V_42 , V_9 = 0 ;
struct V_1 * V_2 = F_30 ( & V_40 -> V_8 ) ;
V_41 = F_31 ( V_40 , L_2 ) ;
if ( V_41 < 0 ) {
F_32 ( L_3 ) ;
return V_41 ;
}
V_42 = F_31 ( V_40 , L_4 ) ;
if ( V_42 < 0 ) {
F_32 ( L_5 ) ;
return V_42 ;
}
V_9 = F_33 ( V_2 , V_41 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_34 ( V_2 , V_42 ) ;
if ( V_9 ) {
F_35 ( V_2 ) ;
return V_9 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_37 ( V_4 -> V_16 ) ;
}
static int F_38 ( struct V_43 * V_8 )
{
struct V_44 * V_45 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_39 * V_40 = F_39 ( V_8 ) ;
T_1 V_48 [ V_49 ] ;
int V_9 = 0 , V_50 ;
T_2 V_51 , V_52 = 0 ;
V_4 = F_40 ( V_8 , sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_7 = F_40 ( V_8 , sizeof( * V_7 ) , V_53 ) ;
if ( ! V_7 )
return - V_54 ;
memcpy ( V_7 , F_41 ( V_8 ) , sizeof( * V_7 ) ) ;
V_4 -> V_8 = V_7 ;
F_42 ( & V_4 -> V_55 ) ;
V_45 = F_43 ( V_40 , V_56 , 0 ) ;
V_7 -> V_57 = F_44 ( V_8 , V_45 ) ;
if ( F_45 ( V_7 -> V_57 ) )
return F_46 ( V_7 -> V_57 ) ;
V_7 -> V_58 = F_47 ( V_8 , L_6 ) ;
if ( F_45 ( V_7 -> V_58 ) )
return F_46 ( V_7 -> V_58 ) ;
V_7 -> V_59 = F_47 ( V_8 , L_7 ) ;
if ( F_45 ( V_7 -> V_59 ) )
return F_46 ( V_7 -> V_59 ) ;
V_7 -> V_60 = F_47 ( V_8 , L_8 ) ;
if ( F_45 ( V_7 -> V_60 ) )
return F_46 ( V_7 -> V_60 ) ;
V_7 -> V_61 = F_47 ( V_8 , L_9 ) ;
if ( F_45 ( V_7 -> V_61 ) )
return F_46 ( V_7 -> V_61 ) ;
V_9 = F_48 ( V_8 ) ;
if ( V_9 && V_9 != - V_62 )
return V_9 ;
V_2 = F_49 ( & V_63 , V_8 ) ;
if ( ! V_2 ) {
V_9 = - V_54 ;
goto V_64;
}
F_50 ( V_7 -> V_58 ) ;
F_50 ( V_7 -> V_59 ) ;
F_50 ( V_7 -> V_60 ) ;
V_9 = V_7 -> V_65 ( V_7 ) ;
if ( V_9 ) {
F_32 ( L_10 ) ;
goto V_66;
}
V_51 = F_51 ( V_7 , V_7 -> V_24 . V_67 + V_68 ) ;
F_52 ( L_11 , V_51 >> 16 ,
( V_51 >> 12 ) & 0xf , ( V_51 >> 8 ) & 0xf ) ;
V_9 = F_53 ( V_8 -> V_69 ,
L_12 ,
V_48 , V_49 ) ;
if ( V_9 )
goto V_66;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ )
V_52 = ( V_52 << 8 ) | ( V_48 [ V_50 ] & 0xf ) ;
F_54 ( V_7 , V_52 , V_7 -> V_24 . V_70 ) ;
V_2 -> V_5 = V_4 ;
F_55 ( V_8 , V_2 ) ;
F_56 ( & V_4 -> V_13 , 0 ) ;
F_57 ( & V_4 -> V_12 ) ;
V_9 = F_25 ( V_2 ) ;
if ( V_9 < 0 )
goto V_71;
V_9 = F_58 ( V_2 , 0 ) ;
if ( V_9 )
goto V_72;
V_47 = F_59 ( V_8 -> V_69 , NULL ) ;
if ( ! V_47 ) {
V_9 = - V_73 ;
goto V_74;
}
V_4 -> V_21 . V_75 = F_60 ( V_47 ) ;
V_9 = F_61 ( V_8 , V_2 ) ;
if ( V_9 ) {
F_32 ( L_13 ) ;
goto V_76;
}
V_9 = F_29 ( V_40 ) ;
if ( V_9 < 0 )
goto V_77;
V_9 = F_62 ( V_2 , V_2 -> V_28 . V_78 ) ;
if ( V_9 < 0 ) {
F_32 ( L_14 ) ;
goto V_79;
}
F_63 ( V_2 ) ;
V_4 -> V_16 = F_64 ( V_2 , 32 , V_2 -> V_28 . V_78 ,
V_2 -> V_28 . V_80 ) ;
if ( F_45 ( V_4 -> V_16 ) ) {
V_9 = F_46 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
goto V_81;
}
F_65 ( V_2 ) ;
return 0 ;
V_81:
F_66 ( V_2 ) ;
V_79:
F_67 ( V_2 ) ;
F_35 ( V_2 ) ;
V_77:
F_68 ( V_8 , V_2 ) ;
V_76:
F_69 ( V_4 -> V_21 . V_75 ) ;
V_4 -> V_21 . V_75 = NULL ;
V_74:
F_70 ( V_2 ) ;
V_72:
F_71 ( V_2 ) ;
F_28 ( V_2 ) ;
V_71:
V_2 -> V_5 = NULL ;
F_55 ( V_8 , NULL ) ;
V_66:
F_72 ( V_7 -> V_60 ) ;
F_72 ( V_7 -> V_59 ) ;
F_72 ( V_7 -> V_58 ) ;
F_73 ( V_2 ) ;
V_64:
F_74 ( V_8 ) ;
return V_9 ;
}
static void F_75 ( struct V_43 * V_8 )
{
struct V_1 * V_2 = F_30 ( V_8 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
if ( V_4 -> V_16 ) {
F_76 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
}
F_77 ( V_2 ) ;
F_67 ( V_2 ) ;
F_35 ( V_2 ) ;
F_66 ( V_2 ) ;
F_68 ( V_8 , V_2 ) ;
F_69 ( V_4 -> V_21 . V_75 ) ;
V_4 -> V_21 . V_75 = NULL ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_55 ( V_8 , NULL ) ;
F_72 ( V_7 -> V_60 ) ;
F_72 ( V_7 -> V_59 ) ;
F_72 ( V_7 -> V_58 ) ;
F_73 ( V_2 ) ;
F_74 ( V_8 ) ;
}
static int F_78 ( struct V_43 * V_8 , void * V_82 )
{
struct V_46 * V_83 = V_82 ;
return V_8 -> V_69 == V_83 ;
}
static int F_79 ( struct V_39 * V_40 )
{
struct V_46 * V_75 , * V_47 ;
struct V_84 * V_85 = NULL ;
if ( ! V_40 -> V_8 . V_69 )
return - V_62 ;
V_47 = F_59 ( V_40 -> V_8 . V_69 , NULL ) ;
if ( ! V_47 )
return - V_62 ;
if ( ! F_80 ( V_47 ) ) {
F_69 ( V_47 ) ;
return - V_62 ;
}
V_75 = F_81 ( V_47 ) ;
F_69 ( V_47 ) ;
if ( ! V_75 || ! F_80 ( V_75 ) ) {
F_69 ( V_75 ) ;
return - V_86 ;
}
F_82 ( & V_40 -> V_8 , & V_85 , F_78 , V_75 ) ;
return F_83 ( & V_40 -> V_8 , & V_87 ,
V_85 ) ;
}
static int F_84 ( struct V_39 * V_40 )
{
F_85 ( & V_40 -> V_8 , & V_87 ) ;
return 0 ;
}
