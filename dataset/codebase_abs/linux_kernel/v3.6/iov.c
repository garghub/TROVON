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
F_7 ( V_13 , V_11 , V_11 ) ;
V_13 -> V_2 . V_14 = V_4 -> V_15 ;
V_12 = F_8 ( V_13 ) ;
if ( V_12 ) {
F_9 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
static void F_10 ( struct V_10 * V_4 , int V_11 )
{
struct V_10 * V_13 ;
if ( V_4 -> V_5 == V_11 )
return;
V_13 = F_4 ( F_5 ( V_4 ) , V_11 ) ;
F_11 ( ! V_13 ) ;
if ( F_12 ( & V_13 -> V_16 ) )
F_9 ( V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
int V_18 ;
int V_12 ;
T_2 V_19 ;
char V_20 [ V_21 ] ;
struct V_1 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = V_2 -> V_7 ;
V_22 = F_14 () ;
if ( ! V_22 )
return - V_27 ;
F_15 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
V_22 -> V_4 = F_3 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_22 -> V_4 ) {
F_16 ( V_22 ) ;
F_17 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
return - V_27 ;
}
V_22 -> V_6 = F_2 ( V_2 , V_3 ) ;
V_22 -> V_29 = V_2 -> V_29 ;
F_18 ( V_2 , V_26 -> V_30 + V_31 , & V_22 -> V_32 ) ;
F_19 ( V_22 ) ;
V_22 -> V_2 . V_14 = V_2 -> V_2 . V_14 ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_24 = V_2 -> V_23 + V_34 + V_18 ;
if ( ! V_24 -> V_14 )
continue;
V_22 -> V_23 [ V_18 ] . V_35 = F_20 ( V_22 ) ;
V_22 -> V_23 [ V_18 ] . V_36 = V_24 -> V_36 ;
V_19 = F_21 ( V_24 ) ;
F_22 ( V_19 , V_26 -> V_37 ) ;
V_22 -> V_23 [ V_18 ] . V_38 = V_24 -> V_38 + V_19 * V_3 ;
V_22 -> V_23 [ V_18 ] . V_39 = V_22 -> V_23 [ V_18 ] . V_38 + V_19 - 1 ;
V_12 = F_23 ( V_24 , & V_22 -> V_23 [ V_18 ] ) ;
F_11 ( V_12 ) ;
}
if ( V_17 )
F_24 ( V_22 ) ;
F_25 ( V_22 , V_22 -> V_4 ) ;
F_17 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
V_22 -> V_40 = F_26 ( V_2 ) ;
V_22 -> V_41 = 1 ;
V_12 = F_27 ( V_22 ) ;
if ( V_12 )
goto V_42;
sprintf ( V_20 , L_1 , V_3 ) ;
V_12 = F_28 ( & V_2 -> V_2 . V_43 , & V_22 -> V_2 . V_43 , V_20 ) ;
if ( V_12 )
goto V_42;
V_12 = F_28 ( & V_22 -> V_2 . V_43 , & V_2 -> V_2 . V_43 , L_2 ) ;
if ( V_12 )
goto V_44;
F_29 ( & V_22 -> V_2 . V_43 , V_45 ) ;
return 0 ;
V_44:
F_30 ( & V_2 -> V_2 . V_43 , V_20 ) ;
V_42:
F_31 ( V_2 ) ;
F_15 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
F_32 ( V_22 ) ;
F_10 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_17 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
return V_12 ;
}
static void F_33 ( struct V_1 * V_2 , int V_3 , int V_17 )
{
char V_20 [ V_21 ] ;
struct V_10 * V_4 ;
struct V_1 * V_22 ;
struct V_25 * V_26 = V_2 -> V_7 ;
V_4 = F_4 ( F_5 ( V_2 -> V_4 ) , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_4 )
return;
V_22 = F_34 ( V_4 , F_2 ( V_2 , V_3 ) ) ;
if ( ! V_22 )
return;
F_31 ( V_22 ) ;
if ( V_17 ) {
F_35 ( & V_22 -> V_2 ) ;
F_24 ( V_22 ) ;
}
sprintf ( V_20 , L_1 , V_3 ) ;
F_30 ( & V_2 -> V_2 . V_43 , V_20 ) ;
if ( V_22 -> V_2 . V_43 . V_46 )
F_30 ( & V_22 -> V_2 . V_43 , L_2 ) ;
F_15 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
F_32 ( V_22 ) ;
F_10 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_17 ( & V_26 -> V_2 -> V_7 -> V_28 ) ;
F_31 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_3 V_47 ;
struct V_25 * V_26 = V_2 -> V_7 ;
if ( ! V_26 -> V_48 )
return 0 ;
if ( ! ( V_26 -> V_49 & V_50 ) )
return 0 ;
F_18 ( V_2 , V_26 -> V_30 + V_51 , & V_47 ) ;
if ( ! ( V_47 & V_52 ) )
return 0 ;
F_37 ( & V_26 -> V_53 ) ;
return 1 ;
}
static void F_38 ( struct V_54 * V_55 )
{
int V_18 ;
T_1 V_56 ;
T_3 V_47 ;
struct V_25 * V_26 = F_39 ( V_55 , struct V_25 , V_53 ) ;
for ( V_18 = V_26 -> V_57 ; V_18 < V_26 -> V_48 ; V_18 ++ ) {
V_56 = F_40 ( V_26 -> V_58 + V_18 ) ;
if ( V_56 == V_59 ) {
F_41 ( V_60 , V_26 -> V_58 + V_18 ) ;
V_56 = F_40 ( V_26 -> V_58 + V_18 ) ;
if ( V_56 == V_60 )
F_13 ( V_26 -> V_61 , V_18 , 1 ) ;
} else if ( V_56 == V_62 ) {
F_33 ( V_26 -> V_61 , V_18 , 1 ) ;
F_41 ( V_63 , V_26 -> V_58 + V_18 ) ;
V_56 = F_40 ( V_26 -> V_58 + V_18 ) ;
if ( V_56 == V_60 )
F_13 ( V_26 -> V_61 , V_18 , 0 ) ;
}
}
F_18 ( V_26 -> V_61 , V_26 -> V_30 + V_51 , & V_47 ) ;
V_47 &= ~ V_52 ;
F_42 ( V_26 -> V_61 , V_26 -> V_30 + V_51 , V_47 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_48 )
{
int V_64 ;
T_4 V_65 ;
T_5 V_66 ;
struct V_25 * V_26 = V_2 -> V_7 ;
if ( V_48 <= V_26 -> V_57 )
return 0 ;
F_44 ( V_2 , V_26 -> V_30 + V_67 , & V_65 ) ;
V_64 = F_45 ( V_65 ) ;
if ( V_64 > V_68 )
return - V_69 ;
V_65 = F_46 ( V_65 ) ;
if ( V_65 + V_48 > F_47 ( V_2 , V_64 ) )
return - V_69 ;
V_66 = F_48 ( V_2 , V_64 ) + V_65 ;
V_26 -> V_58 = F_49 ( V_66 , V_48 ) ;
if ( ! V_26 -> V_58 )
return - V_27 ;
F_50 ( & V_26 -> V_53 , F_38 ) ;
V_26 -> V_70 |= V_71 | V_72 ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_7 ;
V_26 -> V_70 &= ~ ( V_71 | V_72 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
F_52 ( & V_26 -> V_53 ) ;
F_53 ( V_26 -> V_58 ) ;
}
static int F_54 ( struct V_1 * V_2 , int V_48 )
{
int V_12 ;
int V_18 , V_74 ;
int V_75 ;
T_3 V_8 , V_9 , V_57 ;
struct V_23 * V_24 ;
struct V_1 * V_76 ;
struct V_25 * V_26 = V_2 -> V_7 ;
int V_77 = 0 ;
if ( ! V_48 )
return 0 ;
if ( V_26 -> V_48 )
return - V_78 ;
F_18 ( V_2 , V_26 -> V_30 + V_79 , & V_57 ) ;
if ( V_57 > V_26 -> V_37 ||
( ! ( V_26 -> V_49 & V_50 ) && ( V_57 != V_26 -> V_37 ) ) )
return - V_69 ;
if ( V_48 < 0 || V_48 > V_26 -> V_37 ||
( ! ( V_26 -> V_49 & V_50 ) && ( V_48 > V_57 ) ) )
return - V_78 ;
F_42 ( V_2 , V_26 -> V_30 + V_80 , V_48 ) ;
F_18 ( V_2 , V_26 -> V_30 + V_81 , & V_8 ) ;
F_18 ( V_2 , V_26 -> V_30 + V_82 , & V_9 ) ;
if ( ! V_8 || ( V_48 > 1 && ! V_9 ) )
return - V_69 ;
V_75 = 0 ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_77 |= ( 1 << ( V_18 + V_34 ) ) ;
V_24 = V_2 -> V_23 + V_34 + V_18 ;
if ( V_24 -> V_14 )
V_75 ++ ;
}
if ( V_75 != V_26 -> V_75 ) {
F_55 ( & V_2 -> V_2 , L_3 ) ;
return - V_27 ;
}
V_26 -> V_8 = V_8 ;
V_26 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_48 - 1 ) > V_2 -> V_4 -> V_83 . V_39 ) {
F_55 ( & V_2 -> V_2 , L_4 ) ;
return - V_27 ;
}
if ( F_56 ( V_2 , V_77 ) ) {
F_55 ( & V_2 -> V_2 , L_5 ) ;
return - V_27 ;
}
if ( V_26 -> V_84 != V_2 -> V_6 ) {
V_76 = F_34 ( V_2 -> V_4 , V_26 -> V_84 ) ;
if ( ! V_76 )
return - V_85 ;
F_31 ( V_76 ) ;
if ( ! V_76 -> V_86 )
return - V_85 ;
V_12 = F_28 ( & V_2 -> V_2 . V_43 ,
& V_76 -> V_2 . V_43 , L_6 ) ;
if ( V_12 )
return V_12 ;
}
V_26 -> V_70 |= V_87 | V_88 ;
F_57 ( V_2 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
F_58 ( 100 ) ;
F_59 ( V_2 ) ;
V_26 -> V_57 = V_57 ;
if ( V_48 < V_57 )
V_57 = V_48 ;
for ( V_18 = 0 ; V_18 < V_57 ; V_18 ++ ) {
V_12 = F_13 ( V_2 , V_18 , 0 ) ;
if ( V_12 )
goto V_89;
}
if ( V_26 -> V_49 & V_50 ) {
V_12 = F_43 ( V_2 , V_48 ) ;
if ( V_12 )
goto V_89;
}
F_29 ( & V_2 -> V_2 . V_43 , V_45 ) ;
V_26 -> V_48 = V_48 ;
return 0 ;
V_89:
for ( V_74 = 0 ; V_74 < V_18 ; V_74 ++ )
F_33 ( V_2 , V_74 , 0 ) ;
V_26 -> V_70 &= ~ ( V_87 | V_88 ) ;
F_57 ( V_2 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
F_60 ( 1 ) ;
F_59 ( V_2 ) ;
if ( V_26 -> V_84 != V_2 -> V_6 )
F_30 ( & V_2 -> V_2 . V_43 , L_6 ) ;
return V_12 ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_25 * V_26 = V_2 -> V_7 ;
if ( ! V_26 -> V_48 )
return;
if ( V_26 -> V_49 & V_50 )
F_51 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_26 -> V_48 ; V_18 ++ )
F_33 ( V_2 , V_18 , 0 ) ;
V_26 -> V_70 &= ~ ( V_87 | V_88 ) ;
F_57 ( V_2 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
F_60 ( 1 ) ;
F_59 ( V_2 ) ;
if ( V_26 -> V_84 != V_2 -> V_6 )
F_30 ( & V_2 -> V_2 . V_43 , L_6 ) ;
V_26 -> V_48 = 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_30 )
{
int V_18 ;
int V_12 ;
int V_75 ;
T_4 V_90 ;
T_3 V_70 , V_37 , V_8 , V_9 ;
struct V_25 * V_26 ;
struct V_23 * V_24 ;
struct V_1 * V_76 ;
if ( V_2 -> V_91 != V_92 &&
V_2 -> V_91 != V_93 )
return - V_85 ;
F_18 ( V_2 , V_30 + V_73 , & V_70 ) ;
if ( V_70 & V_87 ) {
F_42 ( V_2 , V_30 + V_73 , 0 ) ;
F_60 ( 1 ) ;
}
F_18 ( V_2 , V_30 + V_94 , & V_37 ) ;
if ( ! V_37 )
return 0 ;
V_70 = 0 ;
F_63 (pdev, &dev->bus->devices, bus_list)
if ( V_76 -> V_86 )
goto V_95;
V_76 = NULL ;
if ( F_64 ( V_2 -> V_4 ) )
V_70 |= V_96 ;
V_95:
F_42 ( V_2 , V_30 + V_73 , V_70 ) ;
F_18 ( V_2 , V_30 + V_81 , & V_8 ) ;
F_18 ( V_2 , V_30 + V_82 , & V_9 ) ;
if ( ! V_8 || ( V_37 > 1 && ! V_9 ) )
return - V_69 ;
F_44 ( V_2 , V_30 + V_97 , & V_90 ) ;
V_18 = V_98 > 12 ? V_98 - 12 : 0 ;
V_90 &= ~ ( ( 1 << V_18 ) - 1 ) ;
if ( ! V_90 )
return - V_69 ;
V_90 &= ~ ( V_90 - 1 ) ;
F_65 ( V_2 , V_30 + V_99 , V_90 ) ;
V_75 = 0 ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_24 = V_2 -> V_23 + V_34 + V_18 ;
V_18 += F_66 ( V_2 , V_100 , V_24 ,
V_30 + V_101 + V_18 * 4 ) ;
if ( ! V_24 -> V_36 )
continue;
if ( F_21 ( V_24 ) & ( V_102 - 1 ) ) {
V_12 = - V_69 ;
goto V_89;
}
V_24 -> V_39 = V_24 -> V_38 + F_21 ( V_24 ) * V_37 - 1 ;
V_75 ++ ;
}
V_26 = F_67 ( sizeof( * V_26 ) , V_103 ) ;
if ( ! V_26 ) {
V_12 = - V_27 ;
goto V_89;
}
V_26 -> V_30 = V_30 ;
V_26 -> V_75 = V_75 ;
V_26 -> V_70 = V_70 ;
V_26 -> V_37 = V_37 ;
V_26 -> V_8 = V_8 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_90 = V_90 ;
V_26 -> V_61 = V_2 ;
F_44 ( V_2 , V_30 + V_104 , & V_26 -> V_49 ) ;
F_68 ( V_2 , V_30 + V_105 , & V_26 -> V_84 ) ;
if ( V_2 -> V_91 == V_92 )
V_26 -> V_84 = F_69 ( F_70 ( V_2 -> V_6 ) , V_26 -> V_84 ) ;
if ( V_76 )
V_26 -> V_2 = F_26 ( V_76 ) ;
else
V_26 -> V_2 = V_2 ;
F_71 ( & V_26 -> V_28 ) ;
V_2 -> V_7 = V_26 ;
V_2 -> V_86 = 1 ;
return 0 ;
V_89:
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
V_24 = V_2 -> V_23 + V_34 + V_18 ;
V_24 -> V_36 = 0 ;
}
return V_12 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_7 -> V_48 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_31 ( V_2 -> V_7 -> V_2 ) ;
F_73 ( & V_2 -> V_7 -> V_28 ) ;
F_16 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_18 ;
T_3 V_70 ;
struct V_25 * V_26 = V_2 -> V_7 ;
F_18 ( V_2 , V_26 -> V_30 + V_73 , & V_70 ) ;
if ( V_70 & V_87 )
return;
for ( V_18 = V_34 ; V_18 <= V_106 ; V_18 ++ )
F_75 ( V_2 , V_18 ) ;
F_65 ( V_2 , V_26 -> V_30 + V_99 , V_26 -> V_90 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_80 , V_26 -> V_48 ) ;
F_42 ( V_2 , V_26 -> V_30 + V_73 , V_26 -> V_70 ) ;
if ( V_26 -> V_70 & V_87 )
F_58 ( 100 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_30 ;
if ( ! F_77 ( V_2 ) )
return - V_85 ;
V_30 = F_78 ( V_2 , V_107 ) ;
if ( V_30 )
return F_62 ( V_2 , V_30 ) ;
return - V_85 ;
}
void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 )
F_72 ( V_2 ) ;
}
int F_80 ( struct V_1 * V_2 , int V_108 ,
enum V_109 * type )
{
if ( V_108 < V_34 || V_108 > V_106 )
return 0 ;
F_11 ( ! V_2 -> V_86 ) ;
* type = V_100 ;
return V_2 -> V_7 -> V_30 + V_101 +
4 * ( V_108 - V_34 ) ;
}
T_5 F_81 ( struct V_1 * V_2 , int V_108 )
{
struct V_23 V_110 ;
enum V_109 type ;
int V_111 = F_80 ( V_2 , V_108 , & type ) ;
if ( ! V_111 )
return 0 ;
F_66 ( V_2 , type , & V_110 , V_111 ) ;
return F_82 ( & V_110 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 )
F_74 ( V_2 ) ;
}
int F_84 ( struct V_10 * V_4 )
{
int V_112 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_63 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_86 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_37 - 1 ) ;
if ( V_11 > V_112 )
V_112 = V_11 ;
}
return V_112 ? V_112 - V_4 -> V_5 : 0 ;
}
int F_85 ( struct V_1 * V_2 , int V_48 )
{
F_86 () ;
if ( ! V_2 -> V_86 )
return - V_85 ;
return F_54 ( V_2 , V_48 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_86 () ;
if ( ! V_2 -> V_86 )
return;
F_61 ( V_2 ) ;
}
T_6 F_88 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_86 )
return V_113 ;
return F_36 ( V_2 ) ? V_114 : V_113 ;
}
int F_89 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_86 )
return 0 ;
else
return V_2 -> V_7 -> V_48 ;
}
