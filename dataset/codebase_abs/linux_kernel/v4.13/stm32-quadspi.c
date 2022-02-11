static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
if ( F_2 ( V_2 -> V_5 + V_6 ) & V_7 )
return 0 ;
F_3 ( & V_2 -> V_8 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_9 ) ;
F_4 ( V_3 | V_10 , V_2 -> V_5 + V_9 ) ;
if ( ! F_5 ( & V_2 -> V_8 ,
F_6 ( 1000 ) ) )
V_4 = - V_11 ;
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_12 ;
return F_8 ( V_2 -> V_5 + V_6 , V_12 ,
! ( V_12 & V_13 ) , 10 ,
V_14 ) ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 , bool V_19 )
{
T_1 V_20 = V_21 ;
V_18 -> V_22 = V_23 ;
if ( V_19 ) {
switch ( V_16 -> V_24 ) {
default:
case V_25 :
V_20 = V_21 ;
break;
case V_26 :
V_20 = V_27 ;
break;
case V_28 :
V_20 = V_29 ;
break;
}
}
V_18 -> V_22 |= V_18 -> V_30 ? V_20 : 0 ;
V_18 -> V_22 |= V_18 -> V_31 ? V_32 : 0 ;
}
static void F_10 ( T_2 * V_33 , void T_3 * V_34 )
{
* V_33 = F_11 ( V_34 ) ;
}
static void F_12 ( T_2 * V_33 , void T_3 * V_34 )
{
F_13 ( * V_33 , V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
void (* F_15)( T_2 * , void T_3 * );
T_1 V_35 = V_18 -> V_35 , V_12 ;
T_2 * V_36 = V_18 -> V_36 ;
int V_37 ;
if ( V_18 -> V_38 == V_39 )
F_15 = F_12 ;
else
F_15 = F_10 ;
while ( V_35 -- ) {
V_37 = F_8 ( V_2 -> V_5 + V_6 ,
V_12 , ( V_12 & V_40 ) , 10 ,
V_41 ) ;
if ( V_37 ) {
F_16 ( V_2 -> V_42 , L_1 , V_12 ) ;
break;
}
F_15 ( V_36 ++ , V_2 -> V_5 + V_43 ) ;
}
return V_37 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
F_18 ( V_18 -> V_36 , V_2 -> V_44 + V_18 -> V_34 , V_18 -> V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
if ( ! V_18 -> V_30 )
return 0 ;
if ( V_18 -> V_38 == V_45 )
return F_17 ( V_2 , V_18 ) ;
return F_14 ( V_2 , V_18 ) ;
}
static int F_20 ( struct V_46 * V_47 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 = V_47 -> V_2 ;
T_1 V_48 , V_49 , V_3 ;
int V_4 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 )
goto abort;
V_49 = F_2 ( V_2 -> V_5 + V_50 ) & ~ V_51 ;
V_49 |= F_21 ( V_47 -> V_52 ) ;
F_4 ( V_49 , V_2 -> V_5 + V_50 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_3 &= ~ V_53 & ~ V_54 ;
V_3 |= F_22 ( V_47 -> V_55 ) ;
V_3 |= V_47 -> V_56 ? V_54 : 0 ;
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
if ( V_18 -> V_30 )
F_4 ( V_18 -> V_35 - 1 , V_2 -> V_5 + V_57 ) ;
V_48 = V_18 -> V_22 | V_18 -> V_38 ;
if ( V_18 -> V_58 )
V_48 |= F_23 ( V_18 -> V_58 ) ;
if ( V_18 -> V_31 )
V_48 |= F_24 ( V_18 -> V_31 - 1 ) ;
V_48 |= F_25 ( V_18 -> V_59 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_60 ) ;
if ( V_18 -> V_31 && V_18 -> V_38 != V_45 )
F_4 ( V_18 -> V_34 , V_2 -> V_5 + V_61 ) ;
V_4 = F_19 ( V_2 , V_18 ) ;
if ( V_4 )
goto abort;
if ( V_18 -> V_38 != V_45 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
goto abort;
F_4 ( V_62 , V_2 -> V_5 + V_63 ) ;
}
return V_4 ;
abort:
V_3 = F_2 ( V_2 -> V_5 + V_9 ) | V_64 ;
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
F_16 ( V_2 -> V_42 , L_2 , V_65 , V_4 ) ;
return V_4 ;
}
static int F_26 ( struct V_15 * V_16 ,
T_2 V_59 , T_2 * V_36 , int V_35 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_67 * V_42 = V_47 -> V_2 -> V_42 ;
struct V_17 V_18 ;
F_27 ( V_42 , L_3 , V_59 , V_36 , V_35 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_59 = V_59 ;
V_18 . V_30 = true ;
V_18 . V_35 = V_35 ;
V_18 . V_36 = V_36 ;
V_18 . V_38 = V_68 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_47 , & V_18 ) ;
}
static int F_28 ( struct V_15 * V_16 , T_2 V_59 ,
T_2 * V_36 , int V_35 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_67 * V_42 = V_47 -> V_2 -> V_42 ;
struct V_17 V_18 ;
F_27 ( V_42 , L_4 , V_59 , V_36 , V_35 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_59 = V_59 ;
V_18 . V_30 = ! ! ( V_36 && V_35 > 0 ) ;
V_18 . V_35 = V_35 ;
V_18 . V_36 = V_36 ;
V_18 . V_38 = V_39 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_47 , & V_18 ) ;
}
static T_4 F_29 ( struct V_15 * V_16 , T_5 V_69 , T_6 V_35 ,
T_7 * V_36 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_1 * V_2 = V_47 -> V_2 ;
struct V_17 V_18 ;
int V_4 ;
F_27 ( V_2 -> V_42 , L_5 ,
V_16 -> V_70 , V_36 , ( T_1 ) V_69 , V_35 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_59 = V_16 -> V_70 ;
V_18 . V_31 = V_16 -> V_31 ;
V_18 . V_34 = ( T_1 ) V_69 ;
V_18 . V_30 = true ;
V_18 . V_58 = V_16 -> V_71 ;
V_18 . V_35 = V_35 ;
V_18 . V_36 = V_36 ;
V_18 . V_38 = V_47 -> V_72 ;
F_9 ( V_16 , & V_18 , true ) ;
V_4 = F_20 ( V_47 , & V_18 ) ;
return V_4 ? V_4 : V_35 ;
}
static T_4 F_30 ( struct V_15 * V_16 , T_5 V_73 , T_6 V_35 ,
const T_7 * V_36 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_67 * V_42 = V_47 -> V_2 -> V_42 ;
struct V_17 V_18 ;
int V_4 ;
F_27 ( V_42 , L_6 ,
V_16 -> V_74 , V_36 , ( T_1 ) V_73 , V_35 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_59 = V_16 -> V_74 ;
V_18 . V_31 = V_16 -> V_31 ;
V_18 . V_34 = ( T_1 ) V_73 ;
V_18 . V_30 = true ;
V_18 . V_35 = V_35 ;
V_18 . V_36 = ( void * ) V_36 ;
V_18 . V_38 = V_39 ;
F_9 ( V_16 , & V_18 , false ) ;
V_4 = F_20 ( V_47 , & V_18 ) ;
return V_4 ? V_4 : V_35 ;
}
static int F_31 ( struct V_15 * V_16 , T_5 V_75 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_67 * V_42 = V_47 -> V_2 -> V_42 ;
struct V_17 V_18 ;
F_27 ( V_42 , L_7 , V_16 -> V_76 , ( T_1 ) V_75 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_59 = V_16 -> V_76 ;
V_18 . V_31 = V_16 -> V_31 ;
V_18 . V_34 = ( T_1 ) V_75 ;
V_18 . V_38 = V_39 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_47 , & V_18 ) ;
}
static T_8 F_32 ( int V_77 , void * V_78 )
{
struct V_1 * V_2 = (struct V_1 * ) V_78 ;
T_1 V_3 , V_12 , V_79 = 0 ;
V_3 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_12 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ( V_3 & V_10 ) && ( V_12 & V_7 ) ) {
V_79 |= V_62 ;
F_33 ( & V_2 -> V_8 ) ;
} else {
F_34 ( V_2 -> V_42 , L_8 ) ;
}
F_4 ( V_79 , V_2 -> V_5 + V_63 ) ;
return V_80 ;
}
static int F_35 ( struct V_15 * V_16 , enum V_81 V_82 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_1 * V_2 = V_47 -> V_2 ;
F_36 ( & V_2 -> V_83 ) ;
return 0 ;
}
static void F_37 ( struct V_15 * V_16 , enum V_81 V_82 )
{
struct V_46 * V_47 = V_16 -> V_66 ;
struct V_1 * V_2 = V_47 -> V_2 ;
F_38 ( & V_2 -> V_83 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_86 V_87 = {
. V_88 = V_89 |
V_90 |
V_91 ,
} ;
T_1 V_92 , V_55 , V_93 , V_94 = 0 ;
struct V_46 * V_47 ;
struct V_95 * V_96 ;
int V_37 ;
F_40 ( V_85 , L_9 , & V_93 ) ;
if ( V_93 >= V_97 )
return - V_98 ;
F_40 ( V_85 , L_10 , & V_94 ) ;
if ( ! V_94 )
return - V_98 ;
V_55 = F_41 ( V_2 -> V_99 , V_94 ) - 1 ;
if ( F_40 ( V_85 , L_11 , & V_92 ) )
V_92 = 1 ;
if ( V_92 == 4 )
V_87 . V_88 |= V_100 ;
else if ( V_92 == 2 )
V_87 . V_88 |= V_101 ;
else if ( V_92 != 1 )
return - V_98 ;
V_47 = & V_2 -> V_47 [ V_93 ] ;
V_47 -> V_2 = V_2 ;
V_47 -> V_56 = V_93 ;
V_47 -> V_55 = V_55 ;
V_47 -> V_16 . V_42 = V_2 -> V_42 ;
F_42 ( & V_47 -> V_16 , V_85 ) ;
V_47 -> V_16 . V_66 = V_47 ;
V_96 = & V_47 -> V_16 . V_96 ;
V_47 -> V_16 . V_19 = F_29 ;
V_47 -> V_16 . V_102 = F_30 ;
V_47 -> V_16 . V_103 = F_31 ;
V_47 -> V_16 . V_104 = F_26 ;
V_47 -> V_16 . V_105 = F_28 ;
V_47 -> V_16 . V_106 = F_35 ;
V_47 -> V_16 . V_107 = F_37 ;
F_4 ( V_108 , V_2 -> V_5 + V_109 ) ;
F_4 ( F_22 ( V_55 ) | F_43 ( 3 ) | V_110 | V_111
| V_112 , V_2 -> V_5 + V_9 ) ;
V_47 -> V_52 = F_44 ( V_113 ) ;
V_37 = F_45 ( & V_47 -> V_16 , NULL , & V_87 ) ;
if ( V_37 ) {
F_16 ( V_2 -> V_42 , L_12 ) ;
return V_37 ;
}
V_47 -> V_52 = F_44 ( V_96 -> V_114 ) ;
V_47 -> V_72 = V_45 ;
if ( V_96 -> V_114 > V_2 -> V_115 )
V_47 -> V_72 = V_68 ;
F_4 ( F_46 ( 1 ) , V_2 -> V_5 + V_50 ) ;
V_37 = F_47 ( V_96 , NULL , 0 ) ;
if ( V_37 ) {
F_16 ( V_2 -> V_42 , L_13 ) ;
return V_37 ;
}
V_47 -> V_116 = true ;
F_27 ( V_2 -> V_42 , L_14 ,
V_47 -> V_72 == V_45 ? L_15 : L_16 , V_93 , V_92 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_97 ; V_117 ++ )
if ( V_2 -> V_47 [ V_117 ] . V_116 )
F_49 ( & V_2 -> V_47 [ V_117 ] . V_16 . V_96 ) ;
}
static int F_50 ( struct V_118 * V_119 )
{
struct V_67 * V_42 = & V_119 -> V_42 ;
struct V_84 * V_120 ;
struct V_121 * V_122 ;
struct V_1 * V_2 ;
struct V_123 * V_124 ;
int V_37 , V_77 ;
V_2 = F_51 ( V_42 , sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
V_2 -> V_127 = F_52 ( V_42 -> V_128 ) ;
if ( ! V_2 -> V_127 || V_2 -> V_127 > V_97 )
return - V_129 ;
V_124 = F_53 ( V_119 , V_130 , L_17 ) ;
V_2 -> V_5 = F_54 ( V_42 , V_124 ) ;
if ( F_55 ( V_2 -> V_5 ) )
return F_56 ( V_2 -> V_5 ) ;
V_124 = F_53 ( V_119 , V_130 , L_18 ) ;
V_2 -> V_44 = F_54 ( V_42 , V_124 ) ;
if ( F_55 ( V_2 -> V_44 ) )
return F_56 ( V_2 -> V_44 ) ;
V_2 -> V_115 = F_57 ( V_124 ) ;
V_77 = F_58 ( V_119 , 0 ) ;
V_37 = F_59 ( V_42 , V_77 , F_32 , 0 ,
F_60 ( V_42 ) , V_2 ) ;
if ( V_37 ) {
F_16 ( V_42 , L_19 ) ;
return V_37 ;
}
F_61 ( & V_2 -> V_8 ) ;
V_2 -> V_131 = F_62 ( V_42 , NULL ) ;
if ( F_55 ( V_2 -> V_131 ) )
return F_56 ( V_2 -> V_131 ) ;
V_2 -> V_99 = F_63 ( V_2 -> V_131 ) ;
if ( ! V_2 -> V_99 )
return - V_98 ;
V_37 = F_64 ( V_2 -> V_131 ) ;
if ( V_37 ) {
F_16 ( V_42 , L_20 ) ;
return V_37 ;
}
V_122 = F_65 ( V_42 , NULL ) ;
if ( ! F_55 ( V_122 ) ) {
F_66 ( V_122 ) ;
F_67 ( 2 ) ;
F_68 ( V_122 ) ;
}
V_2 -> V_42 = V_42 ;
F_69 ( V_119 , V_2 ) ;
F_70 ( & V_2 -> V_83 ) ;
F_71 (dev->of_node, flash_np) {
V_37 = F_39 ( V_2 , V_120 ) ;
if ( V_37 ) {
F_16 ( V_42 , L_21 ) ;
goto V_132;
}
}
return 0 ;
V_132:
F_72 ( & V_2 -> V_83 ) ;
F_48 ( V_2 ) ;
F_73 ( V_2 -> V_131 ) ;
return V_37 ;
}
static int F_74 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_75 ( V_119 ) ;
F_4 ( 0 , V_2 -> V_5 + V_9 ) ;
F_48 ( V_2 ) ;
F_72 ( & V_2 -> V_83 ) ;
F_73 ( V_2 -> V_131 ) ;
return 0 ;
}
