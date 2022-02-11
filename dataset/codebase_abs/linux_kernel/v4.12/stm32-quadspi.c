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
case V_25 :
case V_26 :
V_20 = V_21 ;
break;
case V_27 :
V_20 = V_28 ;
break;
case V_29 :
V_20 = V_30 ;
break;
}
}
V_18 -> V_22 |= V_18 -> V_31 ? V_20 : 0 ;
V_18 -> V_22 |= V_18 -> V_32 ? V_33 : 0 ;
}
static void F_10 ( T_2 * V_34 , void T_3 * V_35 )
{
* V_34 = F_11 ( V_35 ) ;
}
static void F_12 ( T_2 * V_34 , void T_3 * V_35 )
{
F_13 ( * V_34 , V_35 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
void (* F_15)( T_2 * , void T_3 * );
T_1 V_36 = V_18 -> V_36 , V_12 ;
T_2 * V_37 = V_18 -> V_37 ;
int V_38 ;
if ( V_18 -> V_39 == V_40 )
F_15 = F_12 ;
else
F_15 = F_10 ;
while ( V_36 -- ) {
V_38 = F_8 ( V_2 -> V_5 + V_6 ,
V_12 , ( V_12 & V_41 ) , 10 ,
V_42 ) ;
if ( V_38 ) {
F_16 ( V_2 -> V_43 , L_1 , V_12 ) ;
break;
}
F_15 ( V_37 ++ , V_2 -> V_5 + V_44 ) ;
}
return V_38 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
F_18 ( V_18 -> V_37 , V_2 -> V_45 + V_18 -> V_35 , V_18 -> V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
if ( ! V_18 -> V_31 )
return 0 ;
if ( V_18 -> V_39 == V_46 )
return F_17 ( V_2 , V_18 ) ;
return F_14 ( V_2 , V_18 ) ;
}
static int F_20 ( struct V_47 * V_48 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
T_1 V_49 , V_50 , V_3 ;
int V_4 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 )
goto abort;
V_50 = F_2 ( V_2 -> V_5 + V_51 ) & ~ V_52 ;
V_50 |= F_21 ( V_48 -> V_53 ) ;
F_4 ( V_50 , V_2 -> V_5 + V_51 ) ;
V_3 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_3 &= ~ V_54 & ~ V_55 ;
V_3 |= F_22 ( V_48 -> V_56 ) ;
V_3 |= V_48 -> V_57 ? V_55 : 0 ;
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
if ( V_18 -> V_31 )
F_4 ( V_18 -> V_36 - 1 , V_2 -> V_5 + V_58 ) ;
V_49 = V_18 -> V_22 | V_18 -> V_39 ;
if ( V_18 -> V_59 )
V_49 |= F_23 ( V_18 -> V_59 ) ;
if ( V_18 -> V_32 )
V_49 |= F_24 ( V_18 -> V_32 - 1 ) ;
V_49 |= F_25 ( V_18 -> V_60 ) ;
F_4 ( V_49 , V_2 -> V_5 + V_61 ) ;
if ( V_18 -> V_32 && V_18 -> V_39 != V_46 )
F_4 ( V_18 -> V_35 , V_2 -> V_5 + V_62 ) ;
V_4 = F_19 ( V_2 , V_18 ) ;
if ( V_4 )
goto abort;
if ( V_18 -> V_39 != V_46 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
goto abort;
F_4 ( V_63 , V_2 -> V_5 + V_64 ) ;
}
return V_4 ;
abort:
V_3 = F_2 ( V_2 -> V_5 + V_9 ) | V_65 ;
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
F_16 ( V_2 -> V_43 , L_2 , V_66 , V_4 ) ;
return V_4 ;
}
static int F_26 ( struct V_15 * V_16 ,
T_2 V_60 , T_2 * V_37 , int V_36 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_68 * V_43 = V_48 -> V_2 -> V_43 ;
struct V_17 V_18 ;
F_27 ( V_43 , L_3 , V_60 , V_37 , V_36 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_60 = V_60 ;
V_18 . V_31 = true ;
V_18 . V_36 = V_36 ;
V_18 . V_37 = V_37 ;
V_18 . V_39 = V_69 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_48 , & V_18 ) ;
}
static int F_28 ( struct V_15 * V_16 , T_2 V_60 ,
T_2 * V_37 , int V_36 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_68 * V_43 = V_48 -> V_2 -> V_43 ;
struct V_17 V_18 ;
F_27 ( V_43 , L_4 , V_60 , V_37 , V_36 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_60 = V_60 ;
V_18 . V_31 = ! ! ( V_37 && V_36 > 0 ) ;
V_18 . V_36 = V_36 ;
V_18 . V_37 = V_37 ;
V_18 . V_39 = V_40 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_48 , & V_18 ) ;
}
static T_4 F_29 ( struct V_15 * V_16 , T_5 V_70 , T_6 V_36 ,
T_7 * V_37 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_17 V_18 ;
int V_4 ;
F_27 ( V_2 -> V_43 , L_5 ,
V_16 -> V_71 , V_37 , ( T_1 ) V_70 , V_36 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_60 = V_16 -> V_71 ;
V_18 . V_32 = V_16 -> V_32 ;
V_18 . V_35 = ( T_1 ) V_70 ;
V_18 . V_31 = true ;
V_18 . V_59 = V_16 -> V_72 ;
V_18 . V_36 = V_36 ;
V_18 . V_37 = V_37 ;
V_18 . V_39 = V_48 -> V_73 ;
F_9 ( V_16 , & V_18 , true ) ;
V_4 = F_20 ( V_48 , & V_18 ) ;
return V_4 ? V_4 : V_36 ;
}
static T_4 F_30 ( struct V_15 * V_16 , T_5 V_74 , T_6 V_36 ,
const T_7 * V_37 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_68 * V_43 = V_48 -> V_2 -> V_43 ;
struct V_17 V_18 ;
int V_4 ;
F_27 ( V_43 , L_6 ,
V_16 -> V_75 , V_37 , ( T_1 ) V_74 , V_36 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_60 = V_16 -> V_75 ;
V_18 . V_32 = V_16 -> V_32 ;
V_18 . V_35 = ( T_1 ) V_74 ;
V_18 . V_31 = true ;
V_18 . V_36 = V_36 ;
V_18 . V_37 = ( void * ) V_37 ;
V_18 . V_39 = V_40 ;
F_9 ( V_16 , & V_18 , false ) ;
V_4 = F_20 ( V_48 , & V_18 ) ;
return V_4 ? V_4 : V_36 ;
}
static int F_31 ( struct V_15 * V_16 , T_5 V_76 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_68 * V_43 = V_48 -> V_2 -> V_43 ;
struct V_17 V_18 ;
F_27 ( V_43 , L_7 , V_16 -> V_77 , ( T_1 ) V_76 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_60 = V_16 -> V_77 ;
V_18 . V_32 = V_16 -> V_32 ;
V_18 . V_35 = ( T_1 ) V_76 ;
V_18 . V_39 = V_40 ;
F_9 ( V_16 , & V_18 , false ) ;
return F_20 ( V_48 , & V_18 ) ;
}
static T_8 F_32 ( int V_78 , void * V_79 )
{
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
T_1 V_3 , V_12 , V_80 = 0 ;
V_3 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_12 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ( V_3 & V_10 ) && ( V_12 & V_7 ) ) {
V_80 |= V_63 ;
F_33 ( & V_2 -> V_8 ) ;
} else {
F_34 ( V_2 -> V_43 , L_8 ) ;
}
F_4 ( V_80 , V_2 -> V_5 + V_64 ) ;
return V_81 ;
}
static int F_35 ( struct V_15 * V_16 , enum V_82 V_83 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_36 ( & V_2 -> V_84 ) ;
return 0 ;
}
static void F_37 ( struct V_15 * V_16 , enum V_82 V_83 )
{
struct V_47 * V_48 = V_16 -> V_67 ;
struct V_1 * V_2 = V_48 -> V_2 ;
F_38 ( & V_2 -> V_84 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
T_1 V_87 , V_24 , V_56 , V_88 , V_89 = 0 ;
struct V_47 * V_48 ;
struct V_90 * V_91 ;
int V_38 ;
F_40 ( V_86 , L_9 , & V_88 ) ;
if ( V_88 >= V_92 )
return - V_93 ;
F_40 ( V_86 , L_10 , & V_89 ) ;
if ( ! V_89 )
return - V_93 ;
V_56 = F_41 ( V_2 -> V_94 , V_89 ) - 1 ;
if ( F_40 ( V_86 , L_11 , & V_87 ) )
V_87 = 1 ;
if ( V_87 == 4 )
V_24 = V_29 ;
else if ( V_87 == 2 )
V_24 = V_27 ;
else if ( V_87 == 1 )
V_24 = V_25 ;
else
return - V_93 ;
V_48 = & V_2 -> V_48 [ V_88 ] ;
V_48 -> V_2 = V_2 ;
V_48 -> V_57 = V_88 ;
V_48 -> V_56 = V_56 ;
V_48 -> V_16 . V_43 = V_2 -> V_43 ;
F_42 ( & V_48 -> V_16 , V_86 ) ;
V_48 -> V_16 . V_67 = V_48 ;
V_91 = & V_48 -> V_16 . V_91 ;
V_48 -> V_16 . V_19 = F_29 ;
V_48 -> V_16 . V_95 = F_30 ;
V_48 -> V_16 . V_96 = F_31 ;
V_48 -> V_16 . V_97 = F_26 ;
V_48 -> V_16 . V_98 = F_28 ;
V_48 -> V_16 . V_99 = F_35 ;
V_48 -> V_16 . V_100 = F_37 ;
F_4 ( V_101 , V_2 -> V_5 + V_102 ) ;
F_4 ( F_22 ( V_56 ) | F_43 ( 3 ) | V_103 | V_104
| V_105 , V_2 -> V_5 + V_9 ) ;
V_48 -> V_53 = F_44 ( V_106 ) ;
V_38 = F_45 ( & V_48 -> V_16 , NULL , V_24 ) ;
if ( V_38 ) {
F_16 ( V_2 -> V_43 , L_12 ) ;
return V_38 ;
}
V_48 -> V_53 = F_44 ( V_91 -> V_107 ) ;
V_48 -> V_73 = V_46 ;
if ( V_91 -> V_107 > V_2 -> V_108 )
V_48 -> V_73 = V_69 ;
F_4 ( F_46 ( 1 ) , V_2 -> V_5 + V_51 ) ;
V_38 = F_47 ( V_91 , NULL , 0 ) ;
if ( V_38 ) {
F_16 ( V_2 -> V_43 , L_13 ) ;
return V_38 ;
}
V_48 -> V_109 = true ;
F_27 ( V_2 -> V_43 , L_14 ,
V_48 -> V_73 == V_46 ? L_15 : L_16 , V_88 , V_87 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_92 ; V_110 ++ )
if ( V_2 -> V_48 [ V_110 ] . V_109 )
F_49 ( & V_2 -> V_48 [ V_110 ] . V_16 . V_91 ) ;
}
static int F_50 ( struct V_111 * V_112 )
{
struct V_68 * V_43 = & V_112 -> V_43 ;
struct V_85 * V_113 ;
struct V_114 * V_115 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
int V_38 , V_78 ;
V_2 = F_51 ( V_43 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
V_2 -> V_120 = F_52 ( V_43 -> V_121 ) ;
if ( ! V_2 -> V_120 || V_2 -> V_120 > V_92 )
return - V_122 ;
V_117 = F_53 ( V_112 , V_123 , L_17 ) ;
V_2 -> V_5 = F_54 ( V_43 , V_117 ) ;
if ( F_55 ( V_2 -> V_5 ) )
return F_56 ( V_2 -> V_5 ) ;
V_117 = F_53 ( V_112 , V_123 , L_18 ) ;
V_2 -> V_45 = F_54 ( V_43 , V_117 ) ;
if ( F_55 ( V_2 -> V_45 ) )
return F_56 ( V_2 -> V_45 ) ;
V_2 -> V_108 = F_57 ( V_117 ) ;
V_78 = F_58 ( V_112 , 0 ) ;
V_38 = F_59 ( V_43 , V_78 , F_32 , 0 ,
F_60 ( V_43 ) , V_2 ) ;
if ( V_38 ) {
F_16 ( V_43 , L_19 ) ;
return V_38 ;
}
F_61 ( & V_2 -> V_8 ) ;
V_2 -> V_124 = F_62 ( V_43 , NULL ) ;
if ( F_55 ( V_2 -> V_124 ) )
return F_56 ( V_2 -> V_124 ) ;
V_2 -> V_94 = F_63 ( V_2 -> V_124 ) ;
if ( ! V_2 -> V_94 )
return - V_93 ;
V_38 = F_64 ( V_2 -> V_124 ) ;
if ( V_38 ) {
F_16 ( V_43 , L_20 ) ;
return V_38 ;
}
V_115 = F_65 ( V_43 , NULL ) ;
if ( ! F_55 ( V_115 ) ) {
F_66 ( V_115 ) ;
F_67 ( 2 ) ;
F_68 ( V_115 ) ;
}
V_2 -> V_43 = V_43 ;
F_69 ( V_112 , V_2 ) ;
F_70 ( & V_2 -> V_84 ) ;
F_71 (dev->of_node, flash_np) {
V_38 = F_39 ( V_2 , V_113 ) ;
if ( V_38 ) {
F_16 ( V_43 , L_21 ) ;
goto V_125;
}
}
return 0 ;
V_125:
F_72 ( & V_2 -> V_84 ) ;
F_48 ( V_2 ) ;
F_73 ( V_2 -> V_124 ) ;
return V_38 ;
}
static int F_74 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_75 ( V_112 ) ;
F_4 ( 0 , V_2 -> V_5 + V_9 ) ;
F_48 ( V_2 ) ;
F_72 ( & V_2 -> V_84 ) ;
F_73 ( V_2 -> V_124 ) ;
return 0 ;
}
