static unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
const struct V_11 * V_12 = NULL ;
struct V_11 V_13 ;
int V_14 = 0 , V_15 , V_16 , V_17 ;
for ( V_15 = 1 ; V_15 < V_5 -> V_18 ; V_15 ++ ) {
V_14 = F_4 ( & V_12 , V_5 -> V_19 [ V_15 ] . V_20 , V_2 -> V_21 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_1 ,
V_5 -> V_19 [ V_15 ] . V_20 , V_14 ) ;
return V_14 ;
}
if ( V_9 -> V_22 ) {
V_14 = F_6 ( V_2 , V_12 ,
V_23 , V_15 ) ;
if ( V_14 < 0 )
goto V_24;
}
V_13 . V_25 = V_12 -> V_25 ;
V_13 . V_26 = V_12 -> V_26 ;
F_7 ( & V_13 ) ;
V_17 = V_2 -> V_27 . V_28 ( V_2 -> V_21 , 0x40 ,
V_13 . V_26 , & V_7 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_21 , L_2 ,
V_17 ) ;
V_14 = V_17 ;
goto V_24;
}
V_16 = V_17 - 1 ;
memcpy ( V_7 . V_29 , V_13 . V_25 , V_13 . V_26 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , true , V_17 ) ;
V_14 = F_8 ( & V_9 -> V_31 , V_16 , V_15 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_21 , L_3 ,
V_5 -> V_19 [ V_15 ] . V_20 , V_14 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , false , V_17 ) ;
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_7 , V_17 ) ;
F_9 ( V_12 ) ;
V_12 = NULL ;
}
return V_14 ;
V_24:
F_9 ( V_12 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
const void * V_33 , T_1 V_34 )
{
int V_17 , V_14 , V_15 ;
T_1 V_35 ;
V_17 = V_2 -> V_27 . V_28 ( V_2 -> V_21 , 0x40 , V_34 , & V_2 -> V_7 ) ;
if ( V_17 <= 0 ) {
F_5 ( V_2 -> V_21 , L_4 ,
V_17 ) ;
return V_17 ;
}
V_2 -> V_27 . V_17 = V_17 ;
memcpy ( V_2 -> V_7 . V_29 , V_33 , V_34 ) ;
V_14 = F_11 ( V_2 , V_36 |
F_12 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_5 ) ;
goto V_37;
}
F_13 ( V_2 , V_38 , V_39 |
( V_40 | ( ( V_17 - 1 ) << 9 ) ) ) ;
V_14 = F_14 ( V_2 , V_36 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_6 , V_14 ) ;
V_14 = - V_41 ;
goto V_37;
}
for ( V_15 = V_42 ; V_15 > 0 ; -- V_15 ) {
V_35 = F_2 ( V_2 , V_43 ) ;
if ( V_35 & V_44 ) {
F_15 ( V_2 ,
V_43 ,
V_44 ,
V_44 ) ;
break;
}
F_16 ( 1 ) ;
}
if ( ! V_15 ) {
F_17 ( V_2 -> V_21 , L_7 , V_35 ) ;
F_18 ( V_2 , V_43 ,
V_44 ,
V_44 ) ;
}
V_14 = F_19 ( V_2 , F_12 ( 1 ) ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_8 ) ;
goto V_37;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
for ( V_15 = V_42 ; V_15 > 0 ; -- V_15 ) {
if ( V_45 ==
( F_2 ( V_2 , V_46 ) &
V_47 ) ) {
F_17 ( V_2 -> V_21 , L_9 ) ;
break;
}
F_16 ( 1 ) ;
}
if ( ! V_15 ) {
F_5 ( V_2 -> V_21 , L_10 , V_35 ) ;
V_14 = - V_41 ;
goto V_37;
}
return V_14 ;
V_37:
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_2 -> V_7 , V_17 ) ;
F_19 ( V_2 , F_12 ( 1 ) ) ;
F_22 ( V_2 , V_36 ) ;
return V_14 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_14 ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , true , V_2 -> V_27 . V_17 ) ;
V_14 = F_24 ( V_2 , V_46 , V_47 ,
V_48 , V_49 , L_11 ) ;
V_2 -> V_27 . V_30 ( V_2 -> V_21 , false , V_2 -> V_27 . V_17 ) ;
V_2 -> V_27 . V_32 ( V_2 -> V_21 , & V_2 -> V_7 , V_2 -> V_27 . V_17 ) ;
return V_14 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_11 V_13 ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
V_14 = F_4 ( & V_2 -> V_12 , V_2 -> V_50 , V_2 -> V_21 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_12 , V_14 ) ;
goto V_51;
}
if ( V_2 -> V_12 == NULL )
goto V_51;
if ( V_9 -> V_22 ) {
V_14 = F_6 ( V_2 , V_2 -> V_12 , V_23 , 0 ) ;
if ( V_14 < 0 )
goto V_51;
}
V_13 . V_25 = V_2 -> V_12 -> V_25 ;
V_13 . V_26 = V_2 -> V_12 -> V_26 ;
F_7 ( & V_13 ) ;
V_14 = F_10 ( V_2 , V_13 . V_25 , V_13 . V_26 ) ;
if ( V_14 < 0 ) {
V_14 = F_10 ( V_2 , V_13 . V_25 , V_13 . V_26 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_5 ( V_2 -> V_21 , L_14 , V_14 ) ;
goto V_51;
}
}
V_14 = F_23 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_15 , V_14 ) ;
F_17 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_22 ( V_2 , V_36 ) ;
} else {
F_26 ( V_2 -> V_21 , L_16 ) ;
V_14 = F_27 ( V_9 -> V_52 , V_9 -> V_53 ,
F_28 ( V_54 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_21 , L_17 ) ;
F_22 ( V_2 , V_36 ) ;
V_14 = - V_41 ;
} else {
V_14 = 0 ;
V_9 -> V_55 = true ;
}
}
V_51:
F_9 ( V_2 -> V_12 ) ;
return V_14 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
if ( V_9 -> V_58 . V_59 [ V_60 ] != V_61 )
return V_62 ;
if ( V_57 -> V_63 )
return V_62 ;
else if ( V_57 -> V_64 )
return V_65 ;
else if ( V_57 -> V_66 )
return V_67 ;
else
return V_62 ;
}
static void F_30 ( struct V_68 * V_69 )
{
int V_14 ;
struct V_70 V_71 ;
struct V_8 * V_9 = F_31 ( V_69 ,
struct V_8 , V_57 . V_69 . V_69 ) ;
struct V_1 * V_2 = V_9 -> V_72 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
int V_73 ;
F_26 ( V_2 -> V_21 , L_18 , V_74 ) ;
if ( F_32 ( V_2 ) != V_36 ) {
F_33 ( V_2 -> V_21 ,
L_19 ) ;
return;
}
V_73 = F_29 ( V_2 ) ;
if ( V_73 == V_62 )
return;
V_71 . V_75 = 0 ;
V_71 . V_76 = 0 ;
V_71 . V_77 = 1 ;
V_71 . V_64 = 0 ;
if ( V_73 == V_65 )
V_71 . V_64 = 1 ;
V_14 = F_34 ( & V_9 -> V_31 , & V_71 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_20 ) ;
return;
}
if ( V_9 -> V_78 )
V_9 -> V_78 ( V_9 -> V_21 , true ) ;
V_57 -> V_59 = V_73 ;
V_9 -> V_58 . V_59 [ V_60 ] = V_79 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_56 * V_57 = & V_9 -> V_57 ;
if ( F_29 ( V_2 ) != V_62 ) {
F_26 ( V_2 -> V_21 , L_21 , V_74 ) ;
F_36 ( & V_57 -> V_69 ,
F_28 ( V_80 ) ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_70 V_71 ;
struct V_8 * V_9 = V_2 -> V_10 ;
F_26 ( V_2 -> V_21 , L_18 , V_74 ) ;
F_38 ( & V_9 -> V_57 . V_69 ) ;
if ( V_9 -> V_58 . V_59 [ V_60 ] != V_79 )
return 0 ;
F_26 ( V_2 -> V_21 , L_22 ) ;
V_71 . V_75 = 0 ;
V_71 . V_76 = 0 ;
V_71 . V_64 = 0 ;
V_71 . V_77 = 0 ;
if ( V_9 -> V_57 . V_59 == V_65 )
V_71 . V_64 = 1 ;
if ( V_9 -> V_78 )
V_9 -> V_78 ( V_9 -> V_21 , false ) ;
V_14 = F_34 ( & V_9 -> V_31 , & V_71 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_23 ) ;
return V_14 ;
}
V_9 -> V_58 . V_59 [ V_60 ] = V_61 ;
V_9 -> V_57 . V_59 = V_62 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_81 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
struct V_82 V_83 ;
unsigned int V_84 = F_12 ( V_81 ) ;
struct V_4 * V_5 = & V_9 -> V_85 ;
if ( V_9 -> V_55 == false ) {
V_9 -> V_53 = false ;
V_14 = F_25 ( V_2 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_24 , V_14 ) ;
return V_14 ;
}
if ( V_5 -> V_18 > 1 ) {
V_14 = F_3 ( V_2 , V_5 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_25 , V_14 ) ;
return V_14 ;
}
}
return V_14 ;
}
if ( V_81 == V_60 )
V_14 = F_11 ( V_2 , V_84 |
F_12 ( 1 ) ) ;
else
V_14 = F_11 ( V_2 , V_84 ) ;
if ( V_14 < 0 )
goto V_86;
if ( V_81 == V_60 ) {
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_9 -> V_53 = false ;
}
V_14 = F_14 ( V_2 , V_84 ) ;
if ( V_14 < 0 )
goto V_86;
if ( V_81 == V_60 ) {
V_14 = F_27 ( V_9 -> V_52 ,
V_9 -> V_53 ,
F_28 ( V_54 ) ) ;
F_19 ( V_2 , F_12 ( 1 ) ) ;
if ( V_14 == 0 ) {
F_5 ( V_2 -> V_21 , L_26 , V_74 ) ;
F_5 ( V_2 -> V_21 , L_13 ,
F_2 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_46 ) ) ;
F_5 ( V_2 -> V_21 , L_27 ) ;
V_14 = - V_41 ;
goto V_86;
}
}
if ( V_81 != V_60 ) {
V_83 . V_84 = V_84 ;
V_83 . V_87 = V_84 ;
V_14 = F_40 ( & V_9 -> V_31 , V_88 ,
V_89 , & V_83 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_28 ,
V_81 , V_14 ) ;
goto V_86;
}
}
V_9 -> V_58 . V_59 [ V_81 ] = V_61 ;
return 0 ;
V_86:
if ( V_81 == V_60 )
V_84 |= F_12 ( 1 ) ;
F_22 ( V_2 , V_84 ) ;
return V_14 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_81 )
{
int V_14 ;
struct V_82 V_83 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_84 = F_12 ( V_81 ) ;
V_83 . V_84 = V_84 ;
V_83 . V_87 = V_90 ;
F_26 ( V_2 -> V_21 , L_29 ,
V_83 . V_84 , V_83 . V_87 ) ;
V_14 = F_40 ( & V_9 -> V_31 , V_88 ,
V_89 , & V_83 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_21 ,
L_30 ,
V_81 ) ;
V_14 = F_22 ( V_2 , V_84 ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_21 , L_31 , V_14 ) ;
return V_14 ;
}
V_9 -> V_58 . V_59 [ V_81 ] = V_91 ;
return 0 ;
}
int F_42 ( struct V_92 * V_21 , void T_2 * V_93 , int V_94 ,
const char * V_50 , struct V_95 V_27 ,
struct V_8 * * V_72 )
{
struct V_8 * V_9 ;
struct V_1 * V_96 ;
int V_14 ;
V_9 = F_43 ( V_21 , sizeof( * V_9 ) , V_97 ) ;
if ( V_9 == NULL )
return - V_98 ;
V_9 -> V_21 = V_21 ;
V_99 . V_10 = V_9 ;
F_44 ( & V_9 -> V_100 ) ;
V_9 -> V_72 = F_45 ( V_21 , & V_99 , V_94 ) ;
if ( ! V_9 -> V_72 ) {
F_5 ( V_9 -> V_21 , L_32 ) ;
return - V_101 ;
}
V_96 = V_9 -> V_72 ;
V_96 -> V_50 = V_50 ;
V_96 -> V_27 = V_27 ;
V_96 -> V_102 = V_103 ;
V_96 -> V_104 . V_105 = V_93 ;
V_96 -> V_104 . V_106 = V_93 ;
F_46 ( V_96 , ( V_107 + V_108 ) ,
V_109 , V_110 , V_111 ) ;
F_44 ( & V_96 -> V_112 ) ;
V_14 = F_47 ( V_21 , V_9 ) ;
if ( V_14 )
return V_14 ;
V_9 -> V_31 . V_113 . V_114 = V_115 ;
V_9 -> V_58 . V_116 = 2 ;
V_9 -> V_53 = false ;
F_48 ( & V_9 -> V_52 ) ;
V_9 -> V_22 = true ;
F_49 ( & V_9 -> V_57 . V_69 , F_30 ) ;
V_9 -> V_57 . V_59 = V_62 ;
if ( V_72 )
* V_72 = V_9 ;
return 0 ;
}
int F_50 ( struct V_92 * V_21 , struct V_8 * V_2 )
{
int V_14 ;
struct V_1 * V_96 = V_2 -> V_72 ;
V_14 = V_96 -> V_102 . V_117 ( V_96 ) ;
if ( V_14 < 0 ) {
F_5 ( V_21 , L_33 , V_14 ) ;
return V_14 ;
}
F_51 ( V_96 ) ;
if ( V_2 -> V_85 . V_18 > 1 ) {
V_14 = V_96 -> V_102 . V_118 ( V_96 , & V_2 -> V_85 ) ;
if ( V_14 < 0 ) {
F_5 ( V_21 , L_34 , V_14 ) ;
return V_14 ;
}
}
V_2 -> V_22 = false ;
return 0 ;
}
void F_52 ( struct V_92 * V_21 , struct V_8 * V_2 )
{
F_53 ( V_2 ) ;
F_54 ( & V_2 -> V_31 ) ;
V_2 -> V_72 -> V_119 . V_113 . V_120 ( V_2 -> V_72 ) ;
if ( V_2 -> V_72 -> V_104 . V_105 )
F_55 ( V_2 -> V_72 -> V_104 . V_105 ) ;
V_2 -> V_72 -> V_113 -> free ( V_2 -> V_72 ) ;
}
