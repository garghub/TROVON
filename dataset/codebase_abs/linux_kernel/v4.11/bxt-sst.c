static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
const struct V_12 * V_13 = NULL ;
struct V_12 V_14 ;
int V_15 = 0 , V_16 , V_17 , V_18 ;
for ( V_16 = 1 ; V_16 < V_6 ; V_16 ++ ) {
V_15 = F_4 ( & V_13 , V_5 [ V_16 ] . V_19 , V_2 -> V_20 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_1 ,
V_5 [ V_16 ] . V_19 , V_15 ) ;
return V_15 ;
}
if ( V_10 -> V_21 ) {
V_15 = F_6 ( V_2 , V_13 ,
V_22 , V_16 ) ;
if ( V_15 < 0 )
goto V_23;
}
V_14 . V_24 = V_13 -> V_24 ;
V_14 . V_25 = V_13 -> V_25 ;
F_7 ( & V_14 ) ;
V_18 = V_2 -> V_26 . V_27 ( V_2 -> V_20 , 0x40 ,
V_14 . V_25 , & V_8 ) ;
if ( V_18 <= 0 ) {
F_5 ( V_2 -> V_20 , L_2 ,
V_18 ) ;
V_15 = V_18 ;
goto V_23;
}
V_17 = V_18 - 1 ;
memcpy ( V_8 . V_28 , V_14 . V_24 , V_14 . V_25 ) ;
V_2 -> V_26 . V_29 ( V_2 -> V_20 , true , V_18 ) ;
V_15 = F_8 ( & V_10 -> V_30 , V_17 , V_16 ) ;
if ( V_15 < 0 )
F_5 ( V_2 -> V_20 , L_3 ,
V_5 [ V_16 ] . V_19 , V_15 ) ;
V_2 -> V_26 . V_29 ( V_2 -> V_20 , false , V_18 ) ;
V_2 -> V_26 . V_31 ( V_2 -> V_20 , & V_8 , V_18 ) ;
F_9 ( V_13 ) ;
V_13 = NULL ;
}
return V_15 ;
V_23:
F_9 ( V_13 ) ;
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
const void * V_32 , T_1 V_33 )
{
int V_18 , V_15 ;
V_18 = V_2 -> V_26 . V_27 ( V_2 -> V_20 , 0x40 , V_33 , & V_2 -> V_8 ) ;
if ( V_18 <= 0 ) {
F_5 ( V_2 -> V_20 , L_4 ,
V_18 ) ;
return V_18 ;
}
V_2 -> V_26 . V_18 = V_18 ;
memcpy ( V_2 -> V_8 . V_28 , V_32 , V_33 ) ;
V_15 = F_11 ( V_2 , V_34 |
F_12 ( 1 ) ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_5 ) ;
goto V_35;
}
F_13 ( V_2 , V_36 , V_37 |
( V_38 | ( ( V_18 - 1 ) << 9 ) ) ) ;
V_15 = F_14 ( V_2 , V_34 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_6 , V_15 ) ;
V_15 = - V_39 ;
goto V_35;
}
V_15 = F_15 ( V_2 , V_40 ,
V_41 ,
V_41 ,
V_42 , L_7 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_8 , V_15 ) ;
goto V_35;
}
V_15 = F_16 ( V_2 , F_12 ( 1 ) ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_9 ) ;
goto V_35;
}
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_15 = F_15 ( V_2 , V_43 , V_44 ,
V_45 , V_42 , L_10 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_11 , V_15 ) ;
goto V_35;
}
return V_15 ;
V_35:
V_2 -> V_26 . V_31 ( V_2 -> V_20 , & V_2 -> V_8 , V_18 ) ;
F_16 ( V_2 , F_12 ( 1 ) ) ;
F_19 ( V_2 , V_34 ) ;
return V_15 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_26 . V_29 ( V_2 -> V_20 , true , V_2 -> V_26 . V_18 ) ;
V_15 = F_15 ( V_2 , V_43 , V_44 ,
V_46 , V_47 , L_12 ) ;
V_2 -> V_26 . V_29 ( V_2 -> V_20 , false , V_2 -> V_26 . V_18 ) ;
V_2 -> V_26 . V_31 ( V_2 -> V_20 , & V_2 -> V_8 , V_2 -> V_26 . V_18 ) ;
return V_15 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_12 V_14 ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_15 ;
V_15 = F_4 ( & V_2 -> V_13 , V_2 -> V_48 , V_2 -> V_20 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_13 , V_15 ) ;
goto V_49;
}
if ( V_2 -> V_13 == NULL )
goto V_49;
if ( V_10 -> V_21 ) {
V_15 = F_6 ( V_2 , V_2 -> V_13 , V_22 , 0 ) ;
if ( V_15 < 0 )
goto V_49;
}
V_14 . V_24 = V_2 -> V_13 -> V_24 ;
V_14 . V_25 = V_2 -> V_13 -> V_25 ;
F_7 ( & V_14 ) ;
V_15 = F_10 ( V_2 , V_14 . V_24 , V_14 . V_25 ) ;
if ( V_15 < 0 ) {
V_15 = F_10 ( V_2 , V_14 . V_24 , V_14 . V_25 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_14 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_43 ) ) ;
F_5 ( V_2 -> V_20 , L_15 , V_15 ) ;
goto V_49;
}
}
V_15 = F_20 ( V_2 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_16 , V_15 ) ;
F_22 ( V_2 -> V_20 , L_14 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_43 ) ) ;
F_19 ( V_2 , V_34 ) ;
} else {
F_23 ( V_2 -> V_20 , L_17 ) ;
V_15 = F_24 ( V_10 -> V_50 , V_10 -> V_51 ,
F_25 ( V_52 ) ) ;
if ( V_15 == 0 ) {
F_5 ( V_2 -> V_20 , L_18 ) ;
F_19 ( V_2 , V_34 ) ;
V_15 = - V_39 ;
} else {
V_15 = 0 ;
V_10 -> V_53 = true ;
}
}
V_49:
F_9 ( V_2 -> V_13 ) ;
return V_15 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_54 * V_55 = & V_10 -> V_55 ;
if ( V_10 -> V_56 . V_57 [ V_58 ] != V_59 )
return V_60 ;
if ( V_55 -> V_61 )
return V_60 ;
else if ( V_55 -> V_62 )
return V_63 ;
else if ( V_55 -> V_64 )
return V_65 ;
else
return V_60 ;
}
static void F_27 ( struct V_66 * V_67 )
{
int V_15 ;
struct V_68 V_69 ;
struct V_9 * V_10 = F_28 ( V_67 ,
struct V_9 , V_55 . V_67 . V_67 ) ;
struct V_1 * V_2 = V_10 -> V_70 ;
struct V_54 * V_55 = & V_10 -> V_55 ;
int V_71 ;
F_23 ( V_2 -> V_20 , L_19 , V_72 ) ;
if ( F_29 ( V_2 ) != V_34 ) {
F_30 ( V_2 -> V_20 ,
L_20 ) ;
return;
}
V_71 = F_26 ( V_2 ) ;
if ( V_71 == V_60 )
return;
V_69 . V_73 = 0 ;
V_69 . V_74 = 0 ;
V_69 . V_75 = 1 ;
V_69 . V_62 = 0 ;
if ( V_71 == V_63 )
V_69 . V_62 = 1 ;
V_15 = F_31 ( & V_10 -> V_30 , & V_69 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_21 ) ;
return;
}
if ( V_10 -> V_76 )
V_10 -> V_76 ( V_10 -> V_20 , true ) ;
V_55 -> V_57 = V_71 ;
V_10 -> V_56 . V_57 [ V_58 ] = V_77 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_54 * V_55 = & V_10 -> V_55 ;
if ( F_26 ( V_2 ) != V_60 ) {
F_23 ( V_2 -> V_20 , L_22 , V_72 ) ;
F_33 ( & V_55 -> V_67 ,
F_25 ( V_78 ) ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_15 ;
struct V_68 V_69 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_23 ( V_2 -> V_20 , L_19 , V_72 ) ;
F_35 ( & V_10 -> V_55 . V_67 ) ;
if ( V_10 -> V_56 . V_57 [ V_58 ] != V_77 )
return 0 ;
F_23 ( V_2 -> V_20 , L_23 ) ;
V_69 . V_73 = 0 ;
V_69 . V_74 = 0 ;
V_69 . V_62 = 0 ;
V_69 . V_75 = 0 ;
if ( V_10 -> V_55 . V_57 == V_63 )
V_69 . V_62 = 1 ;
if ( V_10 -> V_76 )
V_10 -> V_76 ( V_10 -> V_20 , false ) ;
V_15 = F_31 ( & V_10 -> V_30 , & V_69 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_24 ) ;
return V_15 ;
}
V_10 -> V_56 . V_57 [ V_58 ] = V_59 ;
V_10 -> V_55 . V_57 = V_60 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_79 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_15 ;
struct V_80 V_81 ;
unsigned int V_82 = F_12 ( V_79 ) ;
if ( V_10 -> V_53 == false ) {
V_10 -> V_51 = false ;
V_15 = F_21 ( V_2 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_25 , V_15 ) ;
return V_15 ;
}
if ( V_10 -> V_6 > 1 ) {
V_15 = F_3 ( V_2 , V_10 -> V_83 ,
V_10 -> V_6 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_26 , V_15 ) ;
return V_15 ;
}
}
return V_15 ;
}
if ( V_79 == V_58 )
V_15 = F_11 ( V_2 , V_82 |
F_12 ( 1 ) ) ;
else
V_15 = F_11 ( V_2 , V_82 ) ;
if ( V_15 < 0 )
goto V_84;
if ( V_79 == V_58 ) {
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_10 -> V_51 = false ;
}
V_15 = F_14 ( V_2 , V_82 ) ;
if ( V_15 < 0 )
goto V_84;
if ( V_79 == V_58 ) {
V_15 = F_24 ( V_10 -> V_50 ,
V_10 -> V_51 ,
F_25 ( V_52 ) ) ;
F_16 ( V_2 , F_12 ( 1 ) ) ;
if ( V_15 == 0 ) {
F_5 ( V_2 -> V_20 , L_27 , V_72 ) ;
F_5 ( V_2 -> V_20 , L_14 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_43 ) ) ;
F_5 ( V_2 -> V_20 , L_28 ) ;
V_15 = - V_39 ;
goto V_84;
}
}
if ( V_79 != V_58 ) {
V_81 . V_82 = V_82 ;
V_81 . V_85 = V_82 ;
V_15 = F_37 ( & V_10 -> V_30 , V_86 ,
V_87 , & V_81 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_29 ,
V_79 , V_15 ) ;
goto V_84;
}
}
V_10 -> V_56 . V_57 [ V_79 ] = V_59 ;
return 0 ;
V_84:
if ( V_79 == V_58 )
V_82 |= F_12 ( 1 ) ;
F_19 ( V_2 , V_82 ) ;
return V_15 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_79 )
{
int V_15 ;
struct V_80 V_81 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_82 = F_12 ( V_79 ) ;
V_81 . V_82 = V_82 ;
V_81 . V_85 = V_88 ;
F_23 ( V_2 -> V_20 , L_30 ,
V_81 . V_82 , V_81 . V_85 ) ;
V_15 = F_37 ( & V_10 -> V_30 , V_86 ,
V_87 , & V_81 ) ;
if ( V_15 < 0 )
F_5 ( V_2 -> V_20 ,
L_31 ,
V_79 ) ;
V_15 = F_19 ( V_2 , V_82 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_20 , L_32 , V_15 ) ;
return V_15 ;
}
V_10 -> V_56 . V_57 [ V_79 ] = V_89 ;
return 0 ;
}
int F_39 ( struct V_90 * V_20 , void T_2 * V_91 , int V_92 ,
const char * V_48 , struct V_93 V_26 ,
struct V_9 * * V_70 )
{
struct V_9 * V_10 ;
struct V_1 * V_94 ;
int V_15 ;
V_10 = F_40 ( V_20 , sizeof( * V_10 ) , V_95 ) ;
if ( V_10 == NULL )
return - V_96 ;
V_10 -> V_20 = V_20 ;
V_97 . V_11 = V_10 ;
F_41 ( & V_10 -> V_98 ) ;
V_10 -> V_70 = F_42 ( V_20 , & V_97 , V_92 ) ;
if ( ! V_10 -> V_70 ) {
F_5 ( V_10 -> V_20 , L_33 ) ;
return - V_99 ;
}
V_94 = V_10 -> V_70 ;
V_94 -> V_48 = V_48 ;
V_94 -> V_26 = V_26 ;
V_94 -> V_100 = V_101 ;
V_94 -> V_102 . V_103 = V_91 ;
V_94 -> V_102 . V_104 = V_91 ;
F_43 ( V_94 , ( V_105 + V_106 ) ,
V_107 , V_108 , V_109 ) ;
F_41 ( & V_94 -> V_110 ) ;
V_15 = F_44 ( V_20 , V_10 ) ;
if ( V_15 )
return V_15 ;
V_10 -> V_30 . V_111 . V_112 = V_113 ;
V_10 -> V_56 . V_114 = 2 ;
V_10 -> V_51 = false ;
F_45 ( & V_10 -> V_50 ) ;
V_10 -> V_21 = true ;
F_46 ( & V_10 -> V_55 . V_67 , F_27 ) ;
V_10 -> V_55 . V_57 = V_60 ;
if ( V_70 )
* V_70 = V_10 ;
return 0 ;
}
int F_47 ( struct V_90 * V_20 , struct V_9 * V_2 )
{
int V_15 ;
struct V_1 * V_94 = V_2 -> V_70 ;
V_15 = V_94 -> V_100 . V_115 ( V_94 ) ;
if ( V_15 < 0 ) {
F_5 ( V_20 , L_34 , V_15 ) ;
return V_15 ;
}
F_48 ( V_94 ) ;
if ( V_2 -> V_6 > 1 ) {
V_15 = V_94 -> V_100 . V_116 ( V_94 , V_2 -> V_83 ,
V_2 -> V_6 ) ;
if ( V_15 < 0 ) {
F_5 ( V_20 , L_35 , V_15 ) ;
return V_15 ;
}
}
V_2 -> V_21 = false ;
return 0 ;
}
void F_49 ( struct V_90 * V_20 , struct V_9 * V_2 )
{
F_50 ( V_2 ) ;
F_51 ( & V_2 -> V_30 ) ;
V_2 -> V_70 -> V_117 . V_111 . V_118 ( V_2 -> V_70 ) ;
if ( V_2 -> V_70 -> V_102 . V_103 )
F_52 ( V_2 -> V_70 -> V_102 . V_103 ) ;
V_2 -> V_70 -> V_111 -> free ( V_2 -> V_70 ) ;
}
