static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_6 )
{
struct V_7 V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 V_13 ;
int V_14 = 0 , V_15 , V_16 , V_17 ;
for ( V_15 = 1 ; V_15 < V_6 ; V_15 ++ ) {
V_14 = F_4 ( V_10 , & V_10 -> V_18 [ V_15 ] , & V_13 ,
V_19 , V_15 ) ;
if ( V_14 < 0 )
goto V_20;
V_17 = V_2 -> V_21 . V_22 ( V_2 -> V_23 , 0x40 ,
V_13 . V_24 , & V_8 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_23 , L_1 ,
V_17 ) ;
V_14 = V_17 ;
goto V_20;
}
V_16 = V_17 - 1 ;
memcpy ( V_8 . V_25 , V_13 . V_26 , V_13 . V_24 ) ;
V_2 -> V_21 . V_27 ( V_2 -> V_23 , true , V_17 ) ;
V_14 = F_6 ( & V_10 -> V_28 , V_16 , V_15 , true ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_23 , L_2 ,
V_5 [ V_15 ] . V_29 , V_14 ) ;
V_2 -> V_21 . V_27 ( V_2 -> V_23 , false , V_17 ) ;
V_2 -> V_21 . V_30 ( V_2 -> V_23 , & V_8 , V_17 ) ;
}
return V_14 ;
V_20:
F_7 ( V_5 , V_6 ) ;
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
const void * V_31 , T_1 V_32 )
{
int V_17 , V_14 ;
V_17 = V_2 -> V_21 . V_22 ( V_2 -> V_23 , 0x40 , V_32 , & V_2 -> V_8 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_23 , L_3 ,
V_17 ) ;
return V_17 ;
}
V_2 -> V_21 . V_17 = V_17 ;
memcpy ( V_2 -> V_8 . V_25 , V_31 , V_32 ) ;
V_14 = F_9 ( V_2 , V_33 |
F_10 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_4 ) ;
goto V_34;
}
F_11 ( V_2 , V_35 , V_36 |
( V_37 | ( ( V_17 - 1 ) << 9 ) ) ) ;
V_14 = F_12 ( V_2 , V_33 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_5 , V_14 ) ;
V_14 = - V_38 ;
goto V_34;
}
V_14 = F_13 ( V_2 , V_39 ,
V_40 ,
V_40 ,
V_41 , L_6 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_7 , V_14 ) ;
goto V_34;
}
V_14 = F_14 ( V_2 , F_10 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_8 ) ;
goto V_34;
}
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_14 = F_13 ( V_2 , V_42 , V_43 ,
V_44 , V_45 , L_9 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_10 , V_14 ) ;
goto V_34;
}
return V_14 ;
V_34:
V_2 -> V_21 . V_30 ( V_2 -> V_23 , & V_2 -> V_8 , V_17 ) ;
F_14 ( V_2 , F_10 ( 1 ) ) ;
F_17 ( V_2 , V_33 ) ;
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_14 ;
V_2 -> V_21 . V_27 ( V_2 -> V_23 , true , V_2 -> V_21 . V_17 ) ;
V_14 = F_13 ( V_2 , V_42 , V_43 ,
V_46 , V_47 , L_11 ) ;
V_2 -> V_21 . V_27 ( V_2 -> V_23 , false , V_2 -> V_21 . V_17 ) ;
V_2 -> V_21 . V_30 ( V_2 -> V_23 , & V_2 -> V_8 , V_2 -> V_21 . V_17 ) ;
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_12 V_13 ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_14 , V_15 ;
if ( V_2 -> V_48 == NULL ) {
V_14 = F_20 ( & V_2 -> V_48 , V_2 -> V_49 , V_2 -> V_23 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_12 , V_14 ) ;
return V_14 ;
}
}
if ( V_10 -> V_50 ) {
V_14 = F_21 ( V_2 , V_2 -> V_48 , V_19 , 0 ) ;
if ( V_14 < 0 )
goto V_51;
}
V_13 . V_26 = V_2 -> V_48 -> V_26 ;
V_13 . V_24 = V_2 -> V_48 -> V_24 ;
F_22 ( & V_13 ) ;
for ( V_15 = 0 ; V_15 < V_52 ; V_15 ++ ) {
V_14 = F_8 ( V_2 , V_13 . V_26 , V_13 . V_24 ) ;
if ( V_14 == 0 )
break;
}
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_42 ) ) ;
F_5 ( V_2 -> V_23 , L_14 , V_14 ) ;
goto V_51;
}
V_14 = F_18 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_15 , V_14 ) ;
F_23 ( V_2 -> V_23 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_42 ) ) ;
F_17 ( V_2 , V_33 ) ;
} else {
F_24 ( V_2 -> V_23 , L_16 ) ;
V_14 = F_25 ( V_10 -> V_53 , V_10 -> V_54 ,
F_26 ( V_55 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_23 , L_17 ) ;
F_17 ( V_2 , V_33 ) ;
V_14 = - V_38 ;
} else {
V_14 = 0 ;
V_10 -> V_56 = true ;
}
}
return V_14 ;
V_51:
F_27 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
return V_14 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_57 * V_58 = & V_10 -> V_58 ;
if ( V_10 -> V_59 . V_60 [ V_61 ] != V_62 )
return V_63 ;
if ( V_58 -> V_64 )
return V_63 ;
else if ( V_58 -> V_65 )
return V_66 ;
else if ( V_58 -> V_67 )
return V_68 ;
else
return V_63 ;
}
static void F_29 ( struct V_69 * V_70 )
{
int V_14 ;
struct V_71 V_72 ;
struct V_9 * V_10 = F_30 ( V_70 ,
struct V_9 , V_58 . V_70 . V_70 ) ;
struct V_1 * V_2 = V_10 -> V_73 ;
struct V_57 * V_58 = & V_10 -> V_58 ;
int V_74 ;
F_24 ( V_2 -> V_23 , L_18 , V_75 ) ;
if ( F_31 ( V_2 ) != V_33 ) {
F_32 ( V_2 -> V_23 ,
L_19 ) ;
return;
}
V_74 = F_28 ( V_2 ) ;
if ( V_74 == V_63 )
return;
V_72 . V_76 = 0 ;
V_72 . V_77 = 0 ;
V_72 . V_78 = 1 ;
V_72 . V_65 = 0 ;
if ( V_74 == V_66 )
V_72 . V_65 = 1 ;
V_14 = F_33 ( & V_10 -> V_28 , & V_72 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_20 ) ;
return;
}
if ( V_10 -> V_79 )
V_10 -> V_79 ( V_10 -> V_23 , true ) ;
V_58 -> V_60 = V_74 ;
V_10 -> V_59 . V_60 [ V_61 ] = V_80 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_57 * V_58 = & V_10 -> V_58 ;
if ( F_28 ( V_2 ) != V_63 ) {
F_24 ( V_2 -> V_23 , L_21 , V_75 ) ;
F_35 ( & V_58 -> V_70 ,
F_26 ( V_81 ) ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_71 V_72 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_24 ( V_2 -> V_23 , L_18 , V_75 ) ;
F_37 ( & V_10 -> V_58 . V_70 ) ;
if ( V_10 -> V_59 . V_60 [ V_61 ] != V_80 )
return 0 ;
F_24 ( V_2 -> V_23 , L_22 ) ;
V_72 . V_76 = 0 ;
V_72 . V_77 = 0 ;
V_72 . V_65 = 0 ;
V_72 . V_78 = 0 ;
if ( V_10 -> V_58 . V_60 == V_66 )
V_72 . V_65 = 1 ;
if ( V_10 -> V_79 )
V_10 -> V_79 ( V_10 -> V_23 , false ) ;
V_14 = F_33 ( & V_10 -> V_28 , & V_72 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_23 ) ;
return V_14 ;
}
V_10 -> V_59 . V_60 [ V_61 ] = V_62 ;
V_10 -> V_58 . V_60 = V_63 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_82 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_14 ;
struct V_83 V_84 ;
unsigned int V_85 = F_10 ( V_82 ) ;
if ( V_10 -> V_56 == false ) {
V_10 -> V_54 = false ;
V_14 = F_19 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_24 , V_14 ) ;
return V_14 ;
}
if ( V_10 -> V_6 > 1 ) {
V_14 = F_3 ( V_2 , V_10 -> V_18 ,
V_10 -> V_6 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_25 , V_14 ) ;
return V_14 ;
}
}
V_10 -> V_59 . V_60 [ V_82 ] = V_62 ;
return V_14 ;
}
if ( V_82 == V_61 )
V_14 = F_9 ( V_2 , V_85 |
F_10 ( 1 ) ) ;
else
V_14 = F_9 ( V_2 , V_85 ) ;
if ( V_14 < 0 )
goto V_86;
if ( V_82 == V_61 ) {
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_10 -> V_54 = false ;
}
V_14 = F_12 ( V_2 , V_85 ) ;
if ( V_14 < 0 )
goto V_86;
if ( V_82 == V_61 ) {
V_14 = F_25 ( V_10 -> V_53 ,
V_10 -> V_54 ,
F_26 ( V_55 ) ) ;
F_14 ( V_2 , F_10 ( 1 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_23 , L_26 , V_75 ) ;
F_5 ( V_2 -> V_23 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_42 ) ) ;
F_5 ( V_2 -> V_23 , L_27 ) ;
V_14 = - V_38 ;
goto V_86;
}
}
if ( V_82 != V_61 ) {
V_84 . V_85 = V_85 ;
V_84 . V_87 = V_85 ;
V_14 = F_39 ( & V_10 -> V_28 , V_88 ,
V_89 , & V_84 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_28 ,
V_82 , V_14 ) ;
goto V_86;
}
}
V_10 -> V_59 . V_60 [ V_82 ] = V_62 ;
return 0 ;
V_86:
if ( V_82 == V_61 )
V_85 |= F_10 ( 1 ) ;
F_17 ( V_2 , V_85 ) ;
return V_14 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_82 )
{
int V_14 ;
struct V_83 V_84 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_85 = F_10 ( V_82 ) ;
V_84 . V_85 = V_85 ;
V_84 . V_87 = V_90 ;
F_24 ( V_2 -> V_23 , L_29 ,
V_84 . V_85 , V_84 . V_87 ) ;
V_14 = F_39 ( & V_10 -> V_28 , V_88 ,
V_89 , & V_84 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 ,
L_30 ,
V_82 ) ;
V_10 -> V_56 = false ;
}
if ( V_82 == V_61 ) {
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
V_14 = F_17 ( V_2 , V_85 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_23 , L_31 , V_14 ) ;
return V_14 ;
}
V_10 -> V_59 . V_60 [ V_82 ] = V_91 ;
return 0 ;
}
int F_43 ( struct V_92 * V_23 , void T_2 * V_93 , int V_94 ,
const char * V_49 , struct V_95 V_21 ,
struct V_9 * * V_73 )
{
struct V_9 * V_10 ;
struct V_1 * V_96 ;
int V_14 ;
V_14 = F_44 ( V_23 , V_94 , V_49 , V_21 , V_73 , & V_97 ) ;
if ( V_14 < 0 ) {
F_5 ( V_23 , L_32 , V_75 ) ;
return V_14 ;
}
V_10 = * V_73 ;
V_96 = V_10 -> V_73 ;
V_96 -> V_98 = V_99 ;
V_96 -> V_100 . V_101 = V_93 ;
V_96 -> V_100 . V_102 = V_93 ;
F_45 ( V_96 , ( V_103 + V_104 ) ,
V_105 , V_106 , V_107 ) ;
V_10 -> V_28 . V_108 . V_109 = V_110 ;
V_10 -> V_59 . V_111 = 2 ;
V_10 -> V_54 = false ;
F_46 ( & V_10 -> V_53 ) ;
F_47 ( & V_10 -> V_58 . V_70 , F_29 ) ;
V_10 -> V_58 . V_60 = V_63 ;
return 0 ;
}
int F_48 ( struct V_92 * V_23 , struct V_9 * V_2 )
{
int V_14 ;
struct V_1 * V_96 = V_2 -> V_73 ;
V_14 = V_96 -> V_98 . V_112 ( V_96 ) ;
if ( V_14 < 0 ) {
F_5 ( V_23 , L_33 , V_14 ) ;
return V_14 ;
}
F_49 ( V_96 ) ;
if ( V_2 -> V_6 > 1 ) {
V_14 = V_96 -> V_98 . V_113 ( V_96 , V_2 -> V_18 ,
V_2 -> V_6 ) ;
if ( V_14 < 0 ) {
F_5 ( V_23 , L_34 , V_14 ) ;
return V_14 ;
}
}
V_2 -> V_50 = false ;
return 0 ;
}
void F_50 ( struct V_92 * V_23 , struct V_9 * V_2 )
{
F_7 ( V_2 -> V_18 , V_2 -> V_6 ) ;
if ( V_2 -> V_73 -> V_48 )
F_27 ( V_2 -> V_73 -> V_48 ) ;
F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_28 ) ;
V_2 -> V_73 -> V_114 . V_108 . V_115 ( V_2 -> V_73 ) ;
if ( V_2 -> V_73 -> V_100 . V_101 )
F_53 ( V_2 -> V_73 -> V_100 . V_101 ) ;
V_2 -> V_73 -> V_108 -> free ( V_2 -> V_73 ) ;
}
