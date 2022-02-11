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
struct V_10 * V_12 ;
if ( V_4 -> V_5 == V_11 )
return V_4 ;
V_12 = F_4 ( F_5 ( V_4 ) , V_11 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_4 , NULL , V_11 ) ;
if ( ! V_12 )
return NULL ;
F_7 ( V_12 , V_11 , V_11 ) ;
V_4 -> V_13 = 1 ;
return V_12 ;
}
static void F_8 ( struct V_10 * V_4 , int V_11 )
{
struct V_10 * V_12 ;
if ( V_4 -> V_5 == V_11 )
return;
V_12 = F_4 ( F_5 ( V_4 ) , V_11 ) ;
F_9 ( ! V_12 ) ;
if ( F_10 ( & V_12 -> V_14 ) )
F_11 ( V_12 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_3 , int V_15 )
{
int V_16 ;
int V_17 ;
T_2 V_18 ;
char V_19 [ V_20 ] ;
struct V_1 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = V_2 -> V_7 ;
V_21 = F_13 () ;
if ( ! V_21 )
return - V_26 ;
F_14 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
V_21 -> V_4 = F_3 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_21 -> V_4 ) {
F_15 ( V_21 ) ;
F_16 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
return - V_26 ;
}
V_21 -> V_6 = F_2 ( V_2 , V_3 ) ;
V_21 -> V_28 = V_2 -> V_28 ;
F_17 ( V_2 , V_25 -> V_29 + V_30 , & V_21 -> V_31 ) ;
F_18 ( V_21 ) ;
V_21 -> V_2 . V_32 = V_2 -> V_2 . V_32 ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_23 = V_2 -> V_22 + V_34 + V_16 ;
if ( ! V_23 -> V_32 )
continue;
V_21 -> V_22 [ V_16 ] . V_35 = F_19 ( V_21 ) ;
V_21 -> V_22 [ V_16 ] . V_36 = V_23 -> V_36 ;
V_18 = F_20 ( V_23 ) ;
F_21 ( V_18 , V_25 -> V_37 ) ;
V_21 -> V_22 [ V_16 ] . V_38 = V_23 -> V_38 + V_18 * V_3 ;
V_21 -> V_22 [ V_16 ] . V_39 = V_21 -> V_22 [ V_16 ] . V_38 + V_18 - 1 ;
V_17 = F_22 ( V_23 , & V_21 -> V_22 [ V_16 ] ) ;
F_9 ( V_17 ) ;
}
if ( V_15 )
F_23 ( V_21 ) ;
F_24 ( V_21 , V_21 -> V_4 ) ;
F_16 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
V_21 -> V_40 = F_25 ( V_2 ) ;
V_21 -> V_41 = 1 ;
V_17 = F_26 ( V_21 ) ;
sprintf ( V_19 , L_1 , V_3 ) ;
V_17 = F_27 ( & V_2 -> V_2 . V_42 , & V_21 -> V_2 . V_42 , V_19 ) ;
if ( V_17 )
goto V_43;
V_17 = F_27 ( & V_21 -> V_2 . V_42 , & V_2 -> V_2 . V_42 , L_2 ) ;
if ( V_17 )
goto V_44;
F_28 ( & V_21 -> V_2 . V_42 , V_45 ) ;
return 0 ;
V_44:
F_29 ( & V_2 -> V_2 . V_42 , V_19 ) ;
V_43:
F_30 ( V_2 ) ;
F_14 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
F_31 ( V_21 ) ;
F_8 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_16 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
return V_17 ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 , int V_15 )
{
char V_19 [ V_20 ] ;
struct V_10 * V_4 ;
struct V_1 * V_21 ;
struct V_24 * V_25 = V_2 -> V_7 ;
V_4 = F_4 ( F_5 ( V_2 -> V_4 ) , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_4 )
return;
V_21 = F_33 ( V_4 , F_2 ( V_2 , V_3 ) ) ;
if ( ! V_21 )
return;
F_30 ( V_21 ) ;
if ( V_15 ) {
F_34 ( & V_21 -> V_2 ) ;
F_23 ( V_21 ) ;
}
sprintf ( V_19 , L_1 , V_3 ) ;
F_29 ( & V_2 -> V_2 . V_42 , V_19 ) ;
if ( V_21 -> V_2 . V_42 . V_46 )
F_29 ( & V_21 -> V_2 . V_42 , L_2 ) ;
F_14 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
F_31 ( V_21 ) ;
F_8 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
F_16 ( & V_25 -> V_2 -> V_7 -> V_27 ) ;
F_30 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_3 V_47 ;
struct V_24 * V_25 = V_2 -> V_7 ;
if ( ! V_25 -> V_48 )
return 0 ;
if ( ! ( V_25 -> V_49 & V_50 ) )
return 0 ;
F_17 ( V_2 , V_25 -> V_29 + V_51 , & V_47 ) ;
if ( ! ( V_47 & V_52 ) )
return 0 ;
F_36 ( & V_25 -> V_53 ) ;
return 1 ;
}
static void F_37 ( struct V_54 * V_55 )
{
int V_16 ;
T_1 V_56 ;
T_3 V_47 ;
struct V_24 * V_25 = F_38 ( V_55 , struct V_24 , V_53 ) ;
for ( V_16 = V_25 -> V_57 ; V_16 < V_25 -> V_48 ; V_16 ++ ) {
V_56 = F_39 ( V_25 -> V_58 + V_16 ) ;
if ( V_56 == V_59 ) {
F_40 ( V_60 , V_25 -> V_58 + V_16 ) ;
V_56 = F_39 ( V_25 -> V_58 + V_16 ) ;
if ( V_56 == V_60 )
F_12 ( V_25 -> V_61 , V_16 , 1 ) ;
} else if ( V_56 == V_62 ) {
F_32 ( V_25 -> V_61 , V_16 , 1 ) ;
F_40 ( V_63 , V_25 -> V_58 + V_16 ) ;
V_56 = F_39 ( V_25 -> V_58 + V_16 ) ;
if ( V_56 == V_60 )
F_12 ( V_25 -> V_61 , V_16 , 0 ) ;
}
}
F_17 ( V_25 -> V_61 , V_25 -> V_29 + V_51 , & V_47 ) ;
V_47 &= ~ V_52 ;
F_41 ( V_25 -> V_61 , V_25 -> V_29 + V_51 , V_47 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_64 )
{
int V_65 ;
T_4 V_66 ;
T_5 V_67 ;
struct V_24 * V_25 = V_2 -> V_7 ;
if ( V_64 <= V_25 -> V_57 )
return 0 ;
F_43 ( V_2 , V_25 -> V_29 + V_68 , & V_66 ) ;
V_65 = F_44 ( V_66 ) ;
if ( V_65 > V_69 )
return - V_70 ;
V_66 = F_45 ( V_66 ) ;
if ( V_66 + V_64 > F_46 ( V_2 , V_65 ) )
return - V_70 ;
V_67 = F_47 ( V_2 , V_65 ) + V_66 ;
V_25 -> V_58 = F_48 ( V_67 , V_64 ) ;
if ( ! V_25 -> V_58 )
return - V_26 ;
F_49 ( & V_25 -> V_53 , F_37 ) ;
V_25 -> V_71 |= V_72 | V_73 ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_7 ;
V_25 -> V_71 &= ~ ( V_72 | V_73 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
F_51 ( & V_25 -> V_53 ) ;
F_52 ( V_25 -> V_58 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_64 )
{
int V_17 ;
int V_16 , V_75 ;
int V_76 ;
T_3 V_8 , V_9 , V_77 ;
struct V_22 * V_23 ;
struct V_1 * V_78 ;
struct V_24 * V_25 = V_2 -> V_7 ;
int V_79 = 0 ;
if ( ! V_64 )
return 0 ;
if ( V_25 -> V_48 )
return - V_80 ;
F_17 ( V_2 , V_25 -> V_29 + V_81 , & V_77 ) ;
if ( V_77 > V_25 -> V_37 ||
( ! ( V_25 -> V_49 & V_50 ) && ( V_77 != V_25 -> V_37 ) ) )
return - V_70 ;
if ( V_64 < 0 || V_64 > V_25 -> V_37 ||
( ! ( V_25 -> V_49 & V_50 ) && ( V_64 > V_77 ) ) )
return - V_80 ;
F_41 ( V_2 , V_25 -> V_29 + V_82 , V_64 ) ;
F_17 ( V_2 , V_25 -> V_29 + V_83 , & V_8 ) ;
F_17 ( V_2 , V_25 -> V_29 + V_84 , & V_9 ) ;
if ( ! V_8 || ( V_64 > 1 && ! V_9 ) )
return - V_70 ;
V_76 = 0 ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_79 |= ( 1 << ( V_16 + V_34 ) ) ;
V_23 = V_2 -> V_22 + V_34 + V_16 ;
if ( V_23 -> V_32 )
V_76 ++ ;
}
if ( V_76 != V_25 -> V_76 ) {
F_54 ( & V_2 -> V_2 , L_3 ) ;
return - V_26 ;
}
V_25 -> V_8 = V_8 ;
V_25 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_64 - 1 ) > V_2 -> V_4 -> V_85 . V_39 ) {
F_54 ( & V_2 -> V_2 , L_4 ) ;
return - V_26 ;
}
if ( F_55 ( V_2 , V_79 ) ) {
F_54 ( & V_2 -> V_2 , L_5 ) ;
return - V_26 ;
}
if ( V_25 -> V_86 != V_2 -> V_6 ) {
V_78 = F_33 ( V_2 -> V_4 , V_25 -> V_86 ) ;
if ( ! V_78 )
return - V_87 ;
F_30 ( V_78 ) ;
if ( ! V_78 -> V_88 )
return - V_87 ;
V_17 = F_27 ( & V_2 -> V_2 . V_42 ,
& V_78 -> V_2 . V_42 , L_6 ) ;
if ( V_17 )
return V_17 ;
}
V_25 -> V_71 |= V_89 | V_90 ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
F_57 ( 100 ) ;
F_58 ( V_2 ) ;
V_25 -> V_57 = V_77 ;
if ( V_64 < V_77 )
V_77 = V_64 ;
for ( V_16 = 0 ; V_16 < V_77 ; V_16 ++ ) {
V_17 = F_12 ( V_2 , V_16 , 0 ) ;
if ( V_17 )
goto V_91;
}
if ( V_25 -> V_49 & V_50 ) {
V_17 = F_42 ( V_2 , V_64 ) ;
if ( V_17 )
goto V_91;
}
F_28 ( & V_2 -> V_2 . V_42 , V_45 ) ;
V_25 -> V_48 = V_64 ;
return 0 ;
V_91:
for ( V_75 = 0 ; V_75 < V_16 ; V_75 ++ )
F_32 ( V_2 , V_75 , 0 ) ;
V_25 -> V_71 &= ~ ( V_89 | V_90 ) ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_25 -> V_86 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_42 , L_6 ) ;
return V_17 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_24 * V_25 = V_2 -> V_7 ;
if ( ! V_25 -> V_48 )
return;
if ( V_25 -> V_49 & V_50 )
F_50 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_25 -> V_48 ; V_16 ++ )
F_32 ( V_2 , V_16 , 0 ) ;
V_25 -> V_71 &= ~ ( V_89 | V_90 ) ;
F_56 ( V_2 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_25 -> V_86 != V_2 -> V_6 )
F_29 ( & V_2 -> V_2 . V_42 , L_6 ) ;
V_25 -> V_48 = 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_29 )
{
int V_16 ;
int V_17 ;
int V_76 ;
T_4 V_92 ;
T_3 V_71 , V_93 , V_8 , V_9 ;
struct V_24 * V_25 ;
struct V_22 * V_23 ;
struct V_1 * V_78 ;
if ( F_62 ( V_2 ) != V_94 &&
F_62 ( V_2 ) != V_95 )
return - V_87 ;
F_17 ( V_2 , V_29 + V_74 , & V_71 ) ;
if ( V_71 & V_89 ) {
F_41 ( V_2 , V_29 + V_74 , 0 ) ;
F_59 ( 1 ) ;
}
F_17 ( V_2 , V_29 + V_96 , & V_93 ) ;
if ( ! V_93 )
return 0 ;
V_71 = 0 ;
F_63 (pdev, &dev->bus->devices, bus_list)
if ( V_78 -> V_88 )
goto V_97;
V_78 = NULL ;
if ( F_64 ( V_2 -> V_4 ) )
V_71 |= V_98 ;
V_97:
F_41 ( V_2 , V_29 + V_74 , V_71 ) ;
F_17 ( V_2 , V_29 + V_83 , & V_8 ) ;
F_17 ( V_2 , V_29 + V_84 , & V_9 ) ;
if ( ! V_8 || ( V_93 > 1 && ! V_9 ) )
return - V_70 ;
F_43 ( V_2 , V_29 + V_99 , & V_92 ) ;
V_16 = V_100 > 12 ? V_100 - 12 : 0 ;
V_92 &= ~ ( ( 1 << V_16 ) - 1 ) ;
if ( ! V_92 )
return - V_70 ;
V_92 &= ~ ( V_92 - 1 ) ;
F_65 ( V_2 , V_29 + V_101 , V_92 ) ;
V_76 = 0 ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_23 = V_2 -> V_22 + V_34 + V_16 ;
V_16 += F_66 ( V_2 , V_102 , V_23 ,
V_29 + V_103 + V_16 * 4 ) ;
if ( ! V_23 -> V_36 )
continue;
if ( F_20 ( V_23 ) & ( V_104 - 1 ) ) {
V_17 = - V_70 ;
goto V_91;
}
V_23 -> V_39 = V_23 -> V_38 + F_20 ( V_23 ) * V_93 - 1 ;
V_76 ++ ;
}
V_25 = F_67 ( sizeof( * V_25 ) , V_105 ) ;
if ( ! V_25 ) {
V_17 = - V_26 ;
goto V_91;
}
V_25 -> V_29 = V_29 ;
V_25 -> V_76 = V_76 ;
V_25 -> V_71 = V_71 ;
V_25 -> V_37 = V_93 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_9 = V_9 ;
V_25 -> V_92 = V_92 ;
V_25 -> V_61 = V_2 ;
F_43 ( V_2 , V_29 + V_106 , & V_25 -> V_49 ) ;
F_68 ( V_2 , V_29 + V_107 , & V_25 -> V_86 ) ;
if ( F_62 ( V_2 ) == V_94 )
V_25 -> V_86 = F_69 ( F_70 ( V_2 -> V_6 ) , V_25 -> V_86 ) ;
if ( V_78 )
V_25 -> V_2 = F_25 ( V_78 ) ;
else
V_25 -> V_2 = V_2 ;
F_71 ( & V_25 -> V_27 ) ;
V_2 -> V_7 = V_25 ;
V_2 -> V_88 = 1 ;
return 0 ;
V_91:
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_23 = V_2 -> V_22 + V_34 + V_16 ;
V_23 -> V_36 = 0 ;
}
return V_17 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_7 -> V_48 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_30 ( V_2 -> V_7 -> V_2 ) ;
F_73 ( & V_2 -> V_7 -> V_27 ) ;
F_15 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_16 ;
T_3 V_71 ;
struct V_24 * V_25 = V_2 -> V_7 ;
F_17 ( V_2 , V_25 -> V_29 + V_74 , & V_71 ) ;
if ( V_71 & V_89 )
return;
for ( V_16 = V_34 ; V_16 <= V_108 ; V_16 ++ )
F_75 ( V_2 , V_16 ) ;
F_65 ( V_2 , V_25 -> V_29 + V_101 , V_25 -> V_92 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_82 , V_25 -> V_48 ) ;
F_41 ( V_2 , V_25 -> V_29 + V_74 , V_25 -> V_71 ) ;
if ( V_25 -> V_71 & V_89 )
F_57 ( 100 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! F_77 ( V_2 ) )
return - V_87 ;
V_29 = F_78 ( V_2 , V_109 ) ;
if ( V_29 )
return F_61 ( V_2 , V_29 ) ;
return - V_87 ;
}
void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 )
F_72 ( V_2 ) ;
}
int F_80 ( struct V_1 * V_2 , int V_110 ,
enum V_111 * type )
{
if ( V_110 < V_34 || V_110 > V_108 )
return 0 ;
F_9 ( ! V_2 -> V_88 ) ;
* type = V_102 ;
return V_2 -> V_7 -> V_29 + V_103 +
4 * ( V_110 - V_34 ) ;
}
T_5 F_81 ( struct V_1 * V_2 , int V_110 )
{
struct V_22 V_112 ;
enum V_111 type ;
int V_113 = F_80 ( V_2 , V_110 , & type ) ;
if ( ! V_113 )
return 0 ;
F_66 ( V_2 , type , & V_112 , V_113 ) ;
return F_82 ( & V_112 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 )
F_74 ( V_2 ) ;
}
int F_84 ( struct V_10 * V_4 )
{
int V_114 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_63 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_88 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_37 - 1 ) ;
if ( V_11 > V_114 )
V_114 = V_11 ;
}
return V_114 ? V_114 - V_4 -> V_5 : 0 ;
}
int F_85 ( struct V_1 * V_2 , int V_64 )
{
F_86 () ;
if ( ! V_2 -> V_88 )
return - V_87 ;
return F_53 ( V_2 , V_64 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_86 () ;
if ( ! V_2 -> V_88 )
return;
F_60 ( V_2 ) ;
}
T_6 F_88 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_88 )
return V_115 ;
return F_35 ( V_2 ) ? V_116 : V_115 ;
}
int F_89 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_88 )
return 0 ;
return V_2 -> V_7 -> V_48 ;
}
int F_90 ( struct V_1 * V_2 , T_3 V_117 )
{
if ( ! V_2 -> V_88 || ( V_117 > V_2 -> V_7 -> V_37 ) )
return - V_80 ;
if ( V_2 -> V_7 -> V_71 & V_89 )
return - V_118 ;
else
V_2 -> V_7 -> V_119 = V_117 ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_88 )
return - V_80 ;
if ( V_2 -> V_7 -> V_119 )
return V_2 -> V_7 -> V_119 ;
return V_2 -> V_7 -> V_37 ;
}
