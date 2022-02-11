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
F_18 ( V_2 , V_18 ,
V_23 ) ;
F_7 ( V_18 ) ;
F_19 ( V_2 , V_18 ) ;
F_20 ( V_2 , V_18 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_22 ( V_7 , V_24 ,
V_7 -> V_25 . V_26 . V_27 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_28 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_24 ( V_7 , V_24 ,
V_7 -> V_25 . V_26 . V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_26 ( V_2 ) ;
V_2 -> V_29 . V_30 = V_7 -> V_31 ;
V_2 -> V_29 . V_32 = V_7 -> V_31 ;
V_2 -> V_29 . V_33 = V_7 -> V_34 ;
V_2 -> V_29 . V_35 = V_7 -> V_34 ;
V_2 -> V_29 . V_36 = & V_37 ;
V_2 -> V_29 . V_38 = & V_39 ;
V_9 = F_27 ( V_2 ) ;
if ( V_9 ) {
F_28 ( V_2 ) ;
return V_9 ;
}
return 0 ;
}
static int F_29 ( struct V_40 * V_41 )
{
int V_42 , V_43 , V_9 = 0 ;
struct V_1 * V_2 = F_30 ( & V_41 -> V_8 ) ;
V_42 = F_31 ( V_41 , L_2 ) ;
if ( V_42 < 0 ) {
F_32 ( L_3 ) ;
return V_42 ;
}
V_43 = F_31 ( V_41 , L_4 ) ;
if ( V_43 < 0 ) {
F_32 ( L_5 ) ;
return V_43 ;
}
V_9 = F_33 ( V_2 , V_42 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_34 ( V_2 , V_43 ) ;
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
static int F_38 ( struct V_44 * V_8 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_40 * V_41 = F_39 ( V_8 ) ;
T_1 V_49 [ V_50 ] ;
int V_9 = 0 , V_51 ;
T_2 V_52 , V_53 = 0 ;
V_4 = F_40 ( V_8 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_7 = F_40 ( V_8 , sizeof( * V_7 ) , V_54 ) ;
if ( ! V_7 )
return - V_55 ;
memcpy ( V_7 , F_41 ( V_8 ) , sizeof( * V_7 ) ) ;
V_4 -> V_8 = V_7 ;
F_42 ( & V_4 -> V_56 ) ;
V_46 = F_43 ( V_41 , V_57 , 0 ) ;
V_7 -> V_58 = F_44 ( V_8 , V_46 ) ;
if ( F_45 ( V_7 -> V_58 ) )
return F_46 ( V_7 -> V_58 ) ;
V_7 -> V_59 = F_47 ( V_8 , L_6 ) ;
if ( F_45 ( V_7 -> V_59 ) )
return F_46 ( V_7 -> V_59 ) ;
V_7 -> V_60 = F_47 ( V_8 , L_7 ) ;
if ( F_45 ( V_7 -> V_60 ) )
return F_46 ( V_7 -> V_60 ) ;
V_7 -> V_61 = F_47 ( V_8 , L_8 ) ;
if ( F_45 ( V_7 -> V_61 ) )
return F_46 ( V_7 -> V_61 ) ;
V_7 -> V_62 = F_47 ( V_8 , L_9 ) ;
if ( F_45 ( V_7 -> V_62 ) )
return F_46 ( V_7 -> V_62 ) ;
V_9 = F_48 ( V_8 ) ;
if ( V_9 && V_9 != - V_63 )
return V_9 ;
V_2 = F_49 ( & V_64 , V_8 ) ;
if ( F_45 ( V_2 ) ) {
V_9 = F_46 ( V_2 ) ;
goto V_65;
}
F_50 ( V_7 -> V_59 ) ;
F_50 ( V_7 -> V_60 ) ;
F_50 ( V_7 -> V_61 ) ;
V_9 = V_7 -> V_66 ( V_7 ) ;
if ( V_9 ) {
F_32 ( L_10 ) ;
goto V_67;
}
V_52 = F_51 ( V_7 , V_7 -> V_25 . V_68 + V_69 ) ;
F_52 ( L_11 , V_52 >> 16 ,
( V_52 >> 12 ) & 0xf , ( V_52 >> 8 ) & 0xf ) ;
V_9 = F_53 ( V_8 -> V_70 ,
L_12 ,
V_49 , V_50 ) ;
if ( V_9 )
goto V_67;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
V_53 = ( V_53 << 8 ) | ( V_49 [ V_51 ] & 0xf ) ;
F_54 ( V_7 , V_53 , V_7 -> V_25 . V_71 ) ;
V_2 -> V_5 = V_4 ;
F_55 ( V_8 , V_2 ) ;
F_56 ( & V_4 -> V_13 , 0 ) ;
F_57 ( & V_4 -> V_12 ) ;
V_9 = F_25 ( V_2 ) ;
if ( V_9 < 0 )
goto V_72;
V_9 = F_58 ( V_2 , 0 ) ;
if ( V_9 )
goto V_73;
V_48 = F_59 ( V_8 -> V_70 , NULL ) ;
if ( ! V_48 ) {
V_9 = - V_74 ;
goto V_75;
}
V_4 -> V_21 . V_76 = F_60 ( V_48 ) ;
V_9 = F_61 ( V_8 , V_2 ) ;
if ( V_9 ) {
F_32 ( L_13 ) ;
goto V_77;
}
V_9 = F_29 ( V_41 ) ;
if ( V_9 < 0 )
goto V_78;
V_9 = F_62 ( V_2 , V_2 -> V_29 . V_79 ) ;
if ( V_9 < 0 ) {
F_32 ( L_14 ) ;
goto V_80;
}
F_63 ( V_2 ) ;
V_4 -> V_16 = F_64 ( V_2 , 32 , V_2 -> V_29 . V_79 ,
V_2 -> V_29 . V_81 ) ;
if ( F_45 ( V_4 -> V_16 ) ) {
V_9 = F_46 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
goto V_82;
}
F_65 ( V_2 ) ;
return 0 ;
V_82:
F_66 ( V_2 ) ;
V_80:
F_67 ( V_2 ) ;
F_35 ( V_2 ) ;
V_78:
F_68 ( V_8 , V_2 ) ;
V_77:
F_69 ( V_4 -> V_21 . V_76 ) ;
V_4 -> V_21 . V_76 = NULL ;
V_75:
F_70 ( V_2 ) ;
V_73:
F_71 ( V_2 ) ;
F_28 ( V_2 ) ;
V_72:
V_2 -> V_5 = NULL ;
F_55 ( V_8 , NULL ) ;
V_67:
F_72 ( V_7 -> V_61 ) ;
F_72 ( V_7 -> V_60 ) ;
F_72 ( V_7 -> V_59 ) ;
F_73 ( V_2 ) ;
V_65:
F_74 ( V_8 ) ;
return V_9 ;
}
static void F_75 ( struct V_44 * V_8 )
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
F_69 ( V_4 -> V_21 . V_76 ) ;
V_4 -> V_21 . V_76 = NULL ;
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_5 = NULL ;
F_55 ( V_8 , NULL ) ;
F_72 ( V_7 -> V_61 ) ;
F_72 ( V_7 -> V_60 ) ;
F_72 ( V_7 -> V_59 ) ;
F_73 ( V_2 ) ;
F_74 ( V_8 ) ;
}
static int F_78 ( struct V_44 * V_8 , void * V_83 )
{
struct V_47 * V_84 = V_83 ;
return V_8 -> V_70 == V_84 ;
}
static int F_79 ( struct V_40 * V_41 )
{
struct V_47 * V_76 , * V_48 ;
struct V_85 * V_86 = NULL ;
if ( ! V_41 -> V_8 . V_70 )
return - V_63 ;
V_48 = F_59 ( V_41 -> V_8 . V_70 , NULL ) ;
if ( ! V_48 )
return - V_63 ;
if ( ! F_80 ( V_48 ) ) {
F_69 ( V_48 ) ;
return - V_63 ;
}
V_76 = F_81 ( V_48 ) ;
F_69 ( V_48 ) ;
if ( ! V_76 || ! F_80 ( V_76 ) ) {
F_69 ( V_76 ) ;
return - V_87 ;
}
F_82 ( & V_41 -> V_8 , & V_86 , F_78 , V_76 ) ;
return F_83 ( & V_41 -> V_8 , & V_88 ,
V_86 ) ;
}
static int F_84 ( struct V_40 * V_41 )
{
F_85 ( & V_41 -> V_8 , & V_88 ) ;
return 0 ;
}
