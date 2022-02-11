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
if ( V_23 -> V_2 . V_44 . V_47 )
F_29 ( & V_23 -> V_2 . V_44 , L_2 ) ;
F_14 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
F_31 ( V_23 ) ;
F_9 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_16 ( & V_27 -> V_2 -> V_7 -> V_29 ) ;
F_30 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_3 V_48 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_49 )
return 0 ;
if ( ! ( V_27 -> V_50 & V_51 ) )
return 0 ;
F_17 ( V_2 , V_27 -> V_31 + V_52 , & V_48 ) ;
if ( ! ( V_48 & V_53 ) )
return 0 ;
F_36 ( & V_27 -> V_54 ) ;
return 1 ;
}
static void F_37 ( struct V_55 * V_56 )
{
int V_19 ;
T_1 V_57 ;
T_3 V_48 ;
struct V_26 * V_27 = F_38 ( V_56 , struct V_26 , V_54 ) ;
for ( V_19 = V_27 -> V_58 ; V_19 < V_27 -> V_49 ; V_19 ++ ) {
V_57 = F_39 ( V_27 -> V_59 + V_19 ) ;
if ( V_57 == V_60 ) {
F_40 ( V_61 , V_27 -> V_59 + V_19 ) ;
V_57 = F_39 ( V_27 -> V_59 + V_19 ) ;
if ( V_57 == V_61 )
F_12 ( V_27 -> V_62 , V_19 , 1 ) ;
} else if ( V_57 == V_63 ) {
F_32 ( V_27 -> V_62 , V_19 , 1 ) ;
F_40 ( V_64 , V_27 -> V_59 + V_19 ) ;
V_57 = F_39 ( V_27 -> V_59 + V_19 ) ;
if ( V_57 == V_61 )
F_12 ( V_27 -> V_62 , V_19 , 0 ) ;
}
}
F_17 ( V_27 -> V_62 , V_27 -> V_31 + V_52 , & V_48 ) ;
V_48 &= ~ V_53 ;
F_41 ( V_27 -> V_62 , V_27 -> V_31 + V_52 , V_48 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_49 )
{
int V_65 ;
T_4 V_66 ;
T_5 V_67 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( V_49 <= V_27 -> V_58 )
return 0 ;
F_43 ( V_2 , V_27 -> V_31 + V_68 , & V_66 ) ;
V_65 = F_44 ( V_66 ) ;
if ( V_65 > V_69 )
return - V_70 ;
V_66 = F_45 ( V_66 ) ;
if ( V_66 + V_49 > F_46 ( V_2 , V_65 ) )
return - V_70 ;
V_67 = F_47 ( V_2 , V_65 ) + V_66 ;
V_27 -> V_59 = F_48 ( V_67 , V_49 ) ;
if ( ! V_27 -> V_59 )
return - V_28 ;
F_49 ( & V_27 -> V_54 , F_37 ) ;
V_27 -> V_71 |= V_72 | V_73 ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_7 ;
V_27 -> V_71 &= ~ ( V_72 | V_73 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
F_51 ( & V_27 -> V_54 ) ;
F_52 ( V_27 -> V_59 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_49 )
{
int V_12 ;
int V_19 , V_75 ;
int V_76 ;
T_3 V_8 , V_9 , V_58 ;
struct V_24 * V_25 ;
struct V_1 * V_77 ;
struct V_26 * V_27 = V_2 -> V_7 ;
int V_78 = 0 ;
if ( ! V_49 )
return 0 ;
if ( V_27 -> V_49 )
return - V_79 ;
F_17 ( V_2 , V_27 -> V_31 + V_80 , & V_58 ) ;
if ( V_58 > V_27 -> V_38 ||
( ! ( V_27 -> V_50 & V_51 ) && ( V_58 != V_27 -> V_38 ) ) )
return - V_70 ;
if ( V_49 < 0 || V_49 > V_27 -> V_38 ||
( ! ( V_27 -> V_50 & V_51 ) && ( V_49 > V_58 ) ) )
return - V_79 ;
F_41 ( V_2 , V_27 -> V_31 + V_81 , V_49 ) ;
F_17 ( V_2 , V_27 -> V_31 + V_82 , & V_8 ) ;
F_17 ( V_2 , V_27 -> V_31 + V_83 , & V_9 ) ;
if ( ! V_8 || ( V_49 > 1 && ! V_9 ) )
return - V_70 ;
V_76 = 0 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_78 |= ( 1 << ( V_19 + V_35 ) ) ;
V_25 = V_2 -> V_24 + V_35 + V_19 ;
if ( V_25 -> V_15 )
V_76 ++ ;
}
if ( V_76 != V_27 -> V_76 ) {
F_54 ( & V_2 -> V_2 , L_3 ) ;
return - V_28 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_49 - 1 ) > V_2 -> V_4 -> V_14 ) {
F_54 ( & V_2 -> V_2 , L_4 ) ;
return - V_28 ;
}
if ( F_55 ( V_2 , V_78 ) ) {
F_54 ( & V_2 -> V_2 , L_5 ) ;
return - V_28 ;
}
if ( V_27 -> V_84 != V_2 -> V_6 ) {
V_77 = F_33 ( V_2 -> V_4 , V_27 -> V_84 ) ;
if ( ! V_77 )
return - V_85 ;
F_30 ( V_77 ) ;
if ( ! V_77 -> V_86 )
return - V_85 ;
V_12 = F_27 ( & V_2 -> V_2 . V_44 ,
& V_77 -> V_2 . V_44 , L_6 ) ;
if ( V_12 )
return V_12 ;
}
V_27 -> V_71 |= V_87 | V_88 ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
F_57 ( 100 ) ;
F_58 ( V_2 ) ;
V_27 -> V_58 = V_58 ;
if ( V_49 < V_58 )
V_58 = V_49 ;
for ( V_19 = 0 ; V_19 < V_58 ; V_19 ++ ) {
V_12 = F_12 ( V_2 , V_19 , 0 ) ;
if ( V_12 )
goto V_89;
}
if ( V_27 -> V_50 & V_51 ) {
V_12 = F_42 ( V_2 , V_49 ) ;
if ( V_12 )
goto V_89;
}
F_28 ( & V_2 -> V_2 . V_44 , V_46 ) ;
V_27 -> V_49 = V_49 ;
return 0 ;
V_89:
for ( V_75 = 0 ; V_75 < V_19 ; V_75 ++ )
F_32 ( V_2 , V_75 , 0 ) ;
V_27 -> V_71 &= ~ ( V_87 | V_88 ) ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_84 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_44 , L_6 ) ;
return V_12 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_49 )
return;
if ( V_27 -> V_50 & V_51 )
F_50 ( V_2 ) ;
for ( V_19 = 0 ; V_19 < V_27 -> V_49 ; V_19 ++ )
F_32 ( V_2 , V_19 , 0 ) ;
V_27 -> V_71 &= ~ ( V_87 | V_88 ) ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_84 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_44 , L_6 ) ;
V_27 -> V_49 = 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_31 )
{
int V_19 ;
int V_12 ;
int V_76 ;
T_4 V_90 ;
T_3 V_71 , V_38 , V_8 , V_9 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_1 * V_77 ;
if ( V_2 -> V_91 != V_92 &&
V_2 -> V_91 != V_93 )
return - V_85 ;
F_17 ( V_2 , V_31 + V_74 , & V_71 ) ;
if ( V_71 & V_87 ) {
F_41 ( V_2 , V_31 + V_74 , 0 ) ;
F_59 ( 1 ) ;
}
F_17 ( V_2 , V_31 + V_94 , & V_38 ) ;
if ( ! V_38 )
return 0 ;
V_71 = 0 ;
F_62 (pdev, &dev->bus->devices, bus_list)
if ( V_77 -> V_86 )
goto V_95;
V_77 = NULL ;
if ( F_63 ( V_2 -> V_4 ) )
V_71 |= V_96 ;
V_95:
F_41 ( V_2 , V_31 + V_74 , V_71 ) ;
F_17 ( V_2 , V_31 + V_82 , & V_8 ) ;
F_17 ( V_2 , V_31 + V_83 , & V_9 ) ;
if ( ! V_8 || ( V_38 > 1 && ! V_9 ) )
return - V_70 ;
F_43 ( V_2 , V_31 + V_97 , & V_90 ) ;
V_19 = V_98 > 12 ? V_98 - 12 : 0 ;
V_90 &= ~ ( ( 1 << V_19 ) - 1 ) ;
if ( ! V_90 )
return - V_70 ;
V_90 &= ~ ( V_90 - 1 ) ;
F_64 ( V_2 , V_31 + V_99 , V_90 ) ;
V_76 = 0 ;
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
V_19 += F_65 ( V_2 , V_100 , V_25 ,
V_31 + V_101 + V_19 * 4 ) ;
if ( ! V_25 -> V_37 )
continue;
if ( F_20 ( V_25 ) & ( V_102 - 1 ) ) {
V_12 = - V_70 ;
goto V_89;
}
V_25 -> V_40 = V_25 -> V_39 + F_20 ( V_25 ) * V_38 - 1 ;
V_76 ++ ;
}
V_27 = F_66 ( sizeof( * V_27 ) , V_103 ) ;
if ( ! V_27 ) {
V_12 = - V_28 ;
goto V_89;
}
V_27 -> V_31 = V_31 ;
V_27 -> V_76 = V_76 ;
V_27 -> V_71 = V_71 ;
V_27 -> V_38 = V_38 ;
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
V_27 -> V_90 = V_90 ;
V_27 -> V_62 = V_2 ;
F_43 ( V_2 , V_31 + V_104 , & V_27 -> V_50 ) ;
F_67 ( V_2 , V_31 + V_105 , & V_27 -> V_84 ) ;
if ( V_2 -> V_91 == V_92 )
V_27 -> V_84 = F_68 ( F_69 ( V_2 -> V_6 ) , V_27 -> V_84 ) ;
if ( V_77 )
V_27 -> V_2 = F_25 ( V_77 ) ;
else
V_27 -> V_2 = V_2 ;
F_70 ( & V_27 -> V_29 ) ;
V_2 -> V_7 = V_27 ;
V_2 -> V_86 = 1 ;
return 0 ;
V_89:
for ( V_19 = 0 ; V_19 < V_34 ; V_19 ++ ) {
V_25 = V_2 -> V_24 + V_35 + V_19 ;
V_25 -> V_37 = 0 ;
}
return V_12 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_7 -> V_49 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_30 ( V_2 -> V_7 -> V_2 ) ;
F_72 ( & V_2 -> V_7 -> V_29 ) ;
F_15 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_19 ;
T_3 V_71 ;
struct V_26 * V_27 = V_2 -> V_7 ;
F_17 ( V_2 , V_27 -> V_31 + V_74 , & V_71 ) ;
if ( V_71 & V_87 )
return;
for ( V_19 = V_35 ; V_19 <= V_106 ; V_19 ++ )
F_74 ( V_2 , V_19 ) ;
F_64 ( V_2 , V_27 -> V_31 + V_99 , V_27 -> V_90 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_81 , V_27 -> V_49 ) ;
F_41 ( V_2 , V_27 -> V_31 + V_74 , V_27 -> V_71 ) ;
if ( V_27 -> V_71 & V_87 )
F_57 ( 100 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! F_76 ( V_2 ) )
return - V_85 ;
V_31 = F_77 ( V_2 , V_107 ) ;
if ( V_31 )
return F_61 ( V_2 , V_31 ) ;
return - V_85 ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 )
F_71 ( V_2 ) ;
}
int F_79 ( struct V_1 * V_2 , int V_108 ,
enum V_109 * type )
{
if ( V_108 < V_35 || V_108 > V_106 )
return 0 ;
F_10 ( ! V_2 -> V_86 ) ;
* type = V_100 ;
return V_2 -> V_7 -> V_31 + V_101 +
4 * ( V_108 - V_35 ) ;
}
T_5 F_80 ( struct V_1 * V_2 , int V_108 )
{
struct V_24 V_110 ;
enum V_109 type ;
int V_111 = F_79 ( V_2 , V_108 , & type ) ;
if ( ! V_111 )
return 0 ;
F_65 ( V_2 , type , & V_110 , V_111 ) ;
return F_81 ( & V_110 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_86 )
F_73 ( V_2 ) ;
}
int F_83 ( struct V_10 * V_4 )
{
int V_112 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_62 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_86 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_38 - 1 ) ;
if ( V_11 > V_112 )
V_112 = V_11 ;
}
return V_112 ? V_112 - V_4 -> V_5 : 0 ;
}
int F_84 ( struct V_1 * V_2 , int V_49 )
{
F_85 () ;
if ( ! V_2 -> V_86 )
return - V_85 ;
return F_53 ( V_2 , V_49 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_85 () ;
if ( ! V_2 -> V_86 )
return;
F_60 ( V_2 ) ;
}
T_6 F_87 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_86 )
return V_113 ;
return F_35 ( V_2 ) ? V_114 : V_113 ;
}
int F_88 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_86 )
return 0 ;
else
return V_2 -> V_7 -> V_49 ;
}
