static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_4 -> V_5 + ( ( V_2 -> V_6 + V_2 -> V_7 -> V_8 +
V_2 -> V_7 -> V_9 * V_3 ) >> 8 ) ;
}
static inline T_1 F_2 ( struct V_1 * V_2 , int V_3 )
{
return ( V_2 -> V_6 + V_2 -> V_7 -> V_8 +
V_2 -> V_7 -> V_9 * V_3 ) & 0xff ;
}
static struct V_10 * F_3 ( struct V_10 * V_4 , int V_11 )
{
int V_12 ;
struct V_10 * V_13 ;
if ( V_4 -> V_5 == V_11 )
return V_4 ;
V_13 = F_4 ( F_5 ( V_4 ) , V_11 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_6 ( V_4 , NULL , V_11 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_14 = V_11 ;
V_13 -> V_2 . V_15 = V_4 -> V_16 ;
V_12 = F_7 ( V_13 ) ;
if ( V_12 ) {
F_8 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
static void F_9 ( struct V_10 * V_4 , int V_11 )
{
struct V_10 * V_13 ;
if ( V_4 -> V_5 == V_11 )
return;
V_13 = F_4 ( F_5 ( V_4 ) , V_11 ) ;
F_10 ( ! V_13 ) ;
if ( F_11 ( & V_13 -> V_17 ) )
F_8 ( V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 , int V_18 )
{
int V_19 ;
int V_12 ;
T_2 V_20 ;
char V_21 [ V_22 ] ;
struct V_1 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = V_2 -> V_7 ;
V_23 = F_13 () ;
if ( ! V_23 )
return - V_28 ;
F_14 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
V_23 -> V_4 = F_3 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_23 -> V_4 ) {
F_15 ( V_23 ) ;
F_16 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
return - V_28 ;
}
V_23 -> V_6 = F_2 ( V_2 , V_3 ) ;
V_23 -> V_30 = V_2 -> V_30 ;
F_17 ( V_2 , V_27 -> V_31 + V_32 , & V_23 -> V_33 ) ;
F_18 ( V_23 ) ;
V_23 -> V_2 . V_15 = V_2 -> V_2 . V_15 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
if ( ! V_25 -> V_15 )
continue;
V_23 -> V_24 [ V_19 ] . V_36 = F_19 ( V_23 ) ;
V_23 -> V_24 [ V_19 ] . V_37 = V_25 -> V_37 ;
V_20 = F_20 ( V_25 ) ;
F_21 ( V_20 , V_27 -> V_38 ) ;
V_23 -> V_24 [ V_19 ] . V_39 = V_25 -> V_39 + V_20 * V_3 ;
V_23 -> V_24 [ V_19 ] . V_40 = V_23 -> V_24 [ V_19 ] . V_39 + V_20 - 1 ;
V_12 = F_22 ( V_25 , & V_23 -> V_24 [ V_19 ] ) ;
F_10 ( V_12 ) ;
}
if ( V_18 )
F_23 ( V_23 ) ;
F_24 ( V_23 , V_23 -> V_4 ) ;
F_16 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
V_23 -> V_41 = F_25 ( V_2 ) ;
V_23 -> V_42 = 1 ;
V_12 = F_26 ( V_23 ) ;
if ( V_12 )
goto V_43;
sprintf ( V_21 , L_1 , V_3 ) ;
V_12 = F_27 ( & V_2 -> V_2 . V_44 , & V_23 -> V_2 . V_44 , V_21 ) ;
if ( V_12 )
goto V_43;
V_12 = F_27 ( & V_23 -> V_2 . V_44 , & V_2 -> V_2 . V_44 , L_2 ) ;
if ( V_12 )
goto V_45;
F_28 ( & V_23 -> V_2 . V_44 , V_46 ) ;
return 0 ;
V_45:
F_29 ( & V_2 -> V_2 . V_44 , V_21 ) ;
V_43:
F_30 ( V_2 ) ;
F_14 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
F_31 ( V_23 ) ;
F_9 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_16 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
return V_12 ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 , int V_18 )
{
char V_21 [ V_22 ] ;
struct V_10 * V_4 ;
struct V_1 * V_23 ;
struct V_26 * V_27 = V_2 -> V_7 ;
V_4 = F_4 ( F_5 ( V_2 -> V_4 ) , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_4 )
return;
V_23 = F_33 ( V_4 , F_2 ( V_2 , V_3 ) ) ;
if ( ! V_23 )
return;
F_30 ( V_23 ) ;
if ( V_18 ) {
F_34 ( & V_23 -> V_2 ) ;
F_23 ( V_23 ) ;
}
sprintf ( V_21 , L_1 , V_3 ) ;
F_29 ( & V_2 -> V_2 . V_44 , V_21 ) ;
F_29 ( & V_23 -> V_2 . V_44 , L_2 ) ;
F_14 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
F_31 ( V_23 ) ;
F_9 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_16 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
F_30 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_3 V_47 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_48 )
return 0 ;
if ( ! ( V_27 -> V_49 & V_50 ) )
return 0 ;
F_17 ( V_2 , V_27 -> V_31 + V_51 , & V_47 ) ;
if ( ! ( V_47 & V_52 ) )
return 0 ;
F_36 ( & V_27 -> V_53 ) ;
return 1 ;
}
static void F_37 ( struct V_54 * V_55 )
{
int V_19 ;
T_1 V_56 ;
T_3 V_47 ;
struct V_26 * V_27 = F_38 ( V_55 , struct V_26 , V_53 ) ;
for ( V_19 = V_27 -> V_57 ; V_19 < V_27 -> V_48 ; V_19 ++ ) {
V_56 = F_39 ( V_27 -> V_58 + V_19 ) ;
if ( V_56 == V_59 ) {
F_40 ( V_60 , V_27 -> V_58 + V_19 ) ;
V_56 = F_39 ( V_27 -> V_58 + V_19 ) ;
if ( V_56 == V_60 )
F_12 ( V_27 -> V_61 , V_19 , 1 ) ;
} else if ( V_56 == V_62 ) {
F_32 ( V_27 -> V_61 , V_19 , 1 ) ;
F_40 ( V_63 , V_27 -> V_58 + V_19 ) ;
V_56 = F_39 ( V_27 -> V_58 + V_19 ) ;
if ( V_56 == V_60 )
F_12 ( V_27 -> V_61 , V_19 , 0 ) ;
}
}
F_17 ( V_27 -> V_61 , V_27 -> V_31 + V_51 , & V_47 ) ;
V_47 &= ~ V_52 ;
F_41 ( V_27 -> V_61 , V_27 -> V_31 + V_51 , V_47 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_48 )
{
int V_64 ;
T_4 V_65 ;
T_5 V_66 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( V_48 <= V_27 -> V_57 )
return 0 ;
F_43 ( V_2 , V_27 -> V_31 + V_67 , & V_65 ) ;
V_64 = F_44 ( V_65 ) ;
if ( V_64 > V_68 )
return - V_69 ;
V_65 = F_45 ( V_65 ) ;
if ( V_65 + V_48 > F_46 ( V_2 , V_64 ) )
return - V_69 ;
V_66 = F_47 ( V_2 , V_64 ) + V_65 ;
V_27 -> V_58 = F_48 ( V_66 , V_48 ) ;
if ( ! V_27 -> V_58 )
return - V_28 ;
F_49 ( & V_27 -> V_53 , F_37 ) ;
V_27 -> V_70 |= V_71 | V_72 ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_7 ;
V_27 -> V_70 &= ~ ( V_71 | V_72 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
F_51 ( & V_27 -> V_53 ) ;
F_52 ( V_27 -> V_58 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_48 )
{
int V_12 ;
int V_19 , V_74 ;
int V_75 ;
T_3 V_8 , V_9 , V_57 ;
struct V_24 * V_25 ;
struct V_1 * V_76 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_48 )
return 0 ;
if ( V_27 -> V_48 )
return - V_77 ;
F_17 ( V_2 , V_27 -> V_31 + V_78 , & V_57 ) ;
if ( V_57 > V_27 -> V_38 ||
( ! ( V_27 -> V_49 & V_50 ) && ( V_57 != V_27 -> V_38 ) ) )
return - V_69 ;
if ( V_48 < 0 || V_48 > V_27 -> V_38 ||
( ! ( V_27 -> V_49 & V_50 ) && ( V_48 > V_57 ) ) )
return - V_77 ;
F_41 ( V_2 , V_27 -> V_31 + V_79 , V_48 ) ;
F_17 ( V_2 , V_27 -> V_31 + V_80 , & V_8 ) ;
F_17 ( V_2 , V_27 -> V_31 + V_81 , & V_9 ) ;
if ( ! V_8 || ( V_48 > 1 && ! V_9 ) )
return - V_69 ;
V_75 = 0 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
if ( V_25 -> V_15 )
V_75 ++ ;
}
if ( V_75 != V_27 -> V_75 ) {
F_54 ( & V_2 -> V_2 , L_3 ) ;
return - V_28 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_48 - 1 ) > V_2 -> V_4 -> V_14 ) {
F_54 ( & V_2 -> V_2 , L_4 ) ;
return - V_28 ;
}
if ( V_27 -> V_82 != V_2 -> V_6 ) {
V_76 = F_33 ( V_2 -> V_4 , V_27 -> V_82 ) ;
if ( ! V_76 )
return - V_83 ;
F_30 ( V_76 ) ;
if ( ! V_76 -> V_84 )
return - V_83 ;
V_12 = F_27 ( & V_2 -> V_2 . V_44 ,
& V_76 -> V_2 . V_44 , L_5 ) ;
if ( V_12 )
return V_12 ;
}
V_27 -> V_70 |= V_85 | V_86 ;
F_55 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
F_56 ( 100 ) ;
F_57 ( V_2 ) ;
V_27 -> V_57 = V_57 ;
if ( V_48 < V_57 )
V_57 = V_48 ;
for ( V_19 = 0 ; V_19 < V_57 ; V_19 ++ ) {
V_12 = F_12 ( V_2 , V_19 , 0 ) ;
if ( V_12 )
goto V_87;
}
if ( V_27 -> V_49 & V_50 ) {
V_12 = F_42 ( V_2 , V_48 ) ;
if ( V_12 )
goto V_87;
}
F_28 ( & V_2 -> V_2 . V_44 , V_46 ) ;
V_27 -> V_48 = V_48 ;
return 0 ;
V_87:
for ( V_74 = 0 ; V_74 < V_19 ; V_74 ++ )
F_32 ( V_2 , V_74 , 0 ) ;
V_27 -> V_70 &= ~ ( V_85 | V_86 ) ;
F_55 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
F_58 ( 1 ) ;
F_57 ( V_2 ) ;
if ( V_27 -> V_82 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_44 , L_5 ) ;
return V_12 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_48 )
return;
if ( V_27 -> V_49 & V_50 )
F_50 ( V_2 ) ;
for ( V_19 = 0 ; V_19 < V_27 -> V_48 ; V_19 ++ )
F_32 ( V_2 , V_19 , 0 ) ;
V_27 -> V_70 &= ~ ( V_85 | V_86 ) ;
F_55 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
F_58 ( 1 ) ;
F_57 ( V_2 ) ;
if ( V_27 -> V_82 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_44 , L_5 ) ;
V_27 -> V_48 = 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_31 )
{
int V_19 ;
int V_12 ;
int V_75 ;
T_4 V_88 ;
T_3 V_70 , V_38 , V_8 , V_9 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_1 * V_76 ;
if ( V_2 -> V_89 != V_90 &&
V_2 -> V_89 != V_91 )
return - V_83 ;
F_17 ( V_2 , V_31 + V_73 , & V_70 ) ;
if ( V_70 & V_85 ) {
F_41 ( V_2 , V_31 + V_73 , 0 ) ;
F_58 ( 1 ) ;
}
F_17 ( V_2 , V_31 + V_92 , & V_38 ) ;
if ( ! V_38 )
return 0 ;
V_70 = 0 ;
F_61 (pdev, &dev->bus->devices, bus_list)
if ( V_76 -> V_84 )
goto V_93;
V_76 = NULL ;
if ( F_62 ( V_2 -> V_4 ) )
V_70 |= V_94 ;
V_93:
F_41 ( V_2 , V_31 + V_73 , V_70 ) ;
F_41 ( V_2 , V_31 + V_79 , V_38 ) ;
F_17 ( V_2 , V_31 + V_80 , & V_8 ) ;
F_17 ( V_2 , V_31 + V_81 , & V_9 ) ;
if ( ! V_8 || ( V_38 > 1 && ! V_9 ) )
return - V_69 ;
F_43 ( V_2 , V_31 + V_95 , & V_88 ) ;
V_19 = V_96 > 12 ? V_96 - 12 : 0 ;
V_88 &= ~ ( ( 1 << V_19 ) - 1 ) ;
if ( ! V_88 )
return - V_69 ;
V_88 &= ~ ( V_88 - 1 ) ;
F_63 ( V_2 , V_31 + V_97 , V_88 ) ;
V_75 = 0 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
V_19 += F_64 ( V_2 , V_98 , V_25 ,
V_31 + V_99 + V_19 * 4 ) ;
if ( ! V_25 -> V_37 )
continue;
if ( F_20 ( V_25 ) & ( V_100 - 1 ) ) {
V_12 = - V_69 ;
goto V_87;
}
V_25 -> V_40 = V_25 -> V_39 + F_20 ( V_25 ) * V_38 - 1 ;
V_75 ++ ;
}
V_27 = F_65 ( sizeof( * V_27 ) , V_101 ) ;
if ( ! V_27 ) {
V_12 = - V_28 ;
goto V_87;
}
V_27 -> V_31 = V_31 ;
V_27 -> V_75 = V_75 ;
V_27 -> V_70 = V_70 ;
V_27 -> V_38 = V_38 ;
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
V_27 -> V_88 = V_88 ;
V_27 -> V_61 = V_2 ;
F_43 ( V_2 , V_31 + V_102 , & V_27 -> V_49 ) ;
F_66 ( V_2 , V_31 + V_103 , & V_27 -> V_82 ) ;
if ( V_2 -> V_89 == V_90 )
V_27 -> V_82 = F_67 ( F_68 ( V_2 -> V_6 ) , V_27 -> V_82 ) ;
if ( V_76 )
V_27 -> V_2 = F_25 ( V_76 ) ;
else
V_27 -> V_2 = V_2 ;
F_69 ( & V_27 -> V_29 ) ;
V_2 -> V_7 = V_27 ;
V_2 -> V_84 = 1 ;
return 0 ;
V_87:
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
V_25 -> V_37 = 0 ;
}
return V_12 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_7 -> V_48 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_30 ( V_2 -> V_7 -> V_2 ) ;
F_71 ( & V_2 -> V_7 -> V_29 ) ;
F_15 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_19 ;
T_3 V_70 ;
struct V_26 * V_27 = V_2 -> V_7 ;
F_17 ( V_2 , V_27 -> V_31 + V_73 , & V_70 ) ;
if ( V_70 & V_85 )
return;
for ( V_19 = V_35 ; V_19 <= V_104 ; V_19 ++ )
F_73 ( V_2 , V_19 ) ;
F_63 ( V_2 , V_27 -> V_31 + V_97 , V_27 -> V_88 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_79 , V_27 -> V_48 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_73 , V_27 -> V_70 ) ;
if ( V_27 -> V_70 & V_85 )
F_56 ( 100 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! F_75 ( V_2 ) )
return - V_83 ;
V_31 = F_76 ( V_2 , V_105 ) ;
if ( V_31 )
return F_60 ( V_2 , V_31 ) ;
return - V_83 ;
}
void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 )
F_70 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 , int V_106 ,
enum V_107 * type )
{
if ( V_106 < V_35 || V_106 > V_104 )
return 0 ;
F_10 ( ! V_2 -> V_84 ) ;
* type = V_98 ;
return V_2 -> V_7 -> V_31 + V_99 +
4 * ( V_106 - V_35 ) ;
}
T_5 F_79 ( struct V_1 * V_2 , int V_106 )
{
struct V_24 V_108 ;
enum V_107 type ;
int V_109 = F_78 ( V_2 , V_106 , & type ) ;
if ( ! V_109 )
return 0 ;
F_64 ( V_2 , type , & V_108 , V_109 ) ;
return F_80 ( & V_108 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_84 )
F_72 ( V_2 ) ;
}
int F_82 ( struct V_10 * V_4 )
{
int V_110 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_61 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_84 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_38 - 1 ) ;
if ( V_11 > V_110 )
V_110 = V_11 ;
}
return V_110 ? V_110 - V_4 -> V_5 : 0 ;
}
int F_83 ( struct V_1 * V_2 , int V_48 )
{
F_84 () ;
if ( ! V_2 -> V_84 )
return - V_83 ;
return F_53 ( V_2 , V_48 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_84 () ;
if ( ! V_2 -> V_84 )
return;
F_59 ( V_2 ) ;
}
T_6 F_86 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_84 )
return V_111 ;
return F_35 ( V_2 ) ? V_112 : V_111 ;
}
int F_87 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_84 )
return 0 ;
else
return V_2 -> V_7 -> V_48 ;
}
static int F_88 ( struct V_1 * V_2 , int V_113 )
{
int V_31 ;
T_3 V_49 ;
struct V_114 * V_115 ;
V_31 = F_76 ( V_2 , V_116 ) ;
if ( ! V_31 )
return - V_83 ;
V_115 = F_65 ( sizeof( * V_115 ) , V_101 ) ;
if ( ! V_115 )
return - V_28 ;
V_115 -> V_31 = V_31 ;
V_115 -> V_117 = V_113 ;
F_17 ( V_2 , V_31 + V_118 , & V_49 ) ;
V_115 -> V_119 = F_89 ( V_49 ) ? F_89 ( V_49 ) :
V_120 ;
V_2 -> V_115 = V_115 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_115 ) ;
V_2 -> V_115 = NULL ;
}
int F_91 ( struct V_1 * V_2 , int V_113 )
{
int V_12 ;
T_3 V_70 ;
F_10 ( V_2 -> V_115 && V_2 -> V_115 -> V_121 ) ;
if ( V_113 < V_122 )
return - V_77 ;
if ( V_2 -> V_84 || V_2 -> V_42 ) {
struct V_1 * V_76 = V_2 -> V_84 ? V_2 : V_2 -> V_41 ;
F_14 ( & V_76 -> V_7 -> V_29 ) ;
if ( V_76 -> V_115 )
V_12 = V_76 -> V_115 -> V_117 == V_113 ? 0 : - V_77 ;
else
V_12 = F_88 ( V_76 , V_113 ) ;
if ( ! V_12 )
V_76 -> V_115 -> V_123 ++ ;
F_16 ( & V_76 -> V_7 -> V_29 ) ;
if ( V_12 )
return V_12 ;
}
if ( ! V_2 -> V_84 ) {
V_12 = F_88 ( V_2 , V_113 ) ;
if ( V_12 )
return V_12 ;
}
V_70 = V_124 ;
if ( ! V_2 -> V_42 )
V_70 |= F_92 ( V_113 - V_122 ) ;
F_41 ( V_2 , V_2 -> V_115 -> V_31 + V_125 , V_70 ) ;
V_2 -> V_115 -> V_121 = 1 ;
return 0 ;
}
void F_93 ( struct V_1 * V_2 )
{
T_3 V_70 ;
F_10 ( ! V_2 -> V_115 || ! V_2 -> V_115 -> V_121 ) ;
F_17 ( V_2 , V_2 -> V_115 -> V_31 + V_125 , & V_70 ) ;
V_70 &= ~ V_124 ;
F_41 ( V_2 , V_2 -> V_115 -> V_31 + V_125 , V_70 ) ;
V_2 -> V_115 -> V_121 = 0 ;
if ( V_2 -> V_84 || V_2 -> V_42 ) {
struct V_1 * V_76 = V_2 -> V_84 ? V_2 : V_2 -> V_41 ;
F_14 ( & V_76 -> V_7 -> V_29 ) ;
V_76 -> V_115 -> V_123 -- ;
if ( ! V_76 -> V_115 -> V_123 )
F_90 ( V_76 ) ;
F_16 ( & V_76 -> V_7 -> V_29 ) ;
}
if ( ! V_2 -> V_84 )
F_90 ( V_2 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
int V_31 ;
T_3 V_49 ;
if ( V_2 -> V_42 )
return 0 ;
if ( V_2 -> V_115 )
return V_2 -> V_115 -> V_119 ;
V_31 = F_76 ( V_2 , V_116 ) ;
if ( ! V_31 )
return - V_83 ;
F_17 ( V_2 , V_31 + V_118 , & V_49 ) ;
return F_89 ( V_49 ) ? F_89 ( V_49 ) :
V_120 ;
}
