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
return V_12 ;
}
static void F_8 ( struct V_10 * V_13 , struct V_10 * V_14 )
{
if ( V_13 != V_14 && F_9 ( & V_14 -> V_15 ) )
F_10 ( V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
int V_17 ;
int V_18 = - V_19 ;
T_2 V_20 ;
char V_21 [ V_22 ] ;
struct V_1 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = V_2 -> V_7 ;
struct V_10 * V_4 ;
F_12 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
V_4 = F_3 ( V_2 -> V_4 , F_1 ( V_2 , V_3 ) ) ;
if ( ! V_4 )
goto V_29;
V_23 = F_13 ( V_4 ) ;
if ( ! V_23 )
goto V_30;
V_23 -> V_6 = F_2 ( V_2 , V_3 ) ;
V_23 -> V_31 = V_2 -> V_31 ;
F_14 ( V_2 , V_27 -> V_32 + V_33 , & V_23 -> V_34 ) ;
F_15 ( V_23 ) ;
V_23 -> V_2 . V_35 = V_2 -> V_2 . V_35 ;
V_23 -> V_36 = F_16 ( V_2 ) ;
V_23 -> V_37 = 1 ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_39 + V_17 ;
if ( ! V_25 -> V_35 )
continue;
V_23 -> V_24 [ V_17 ] . V_40 = F_17 ( V_23 ) ;
V_23 -> V_24 [ V_17 ] . V_41 = V_25 -> V_41 ;
V_20 = F_18 ( V_25 ) ;
F_19 ( V_20 , V_27 -> V_42 ) ;
V_23 -> V_24 [ V_17 ] . V_43 = V_25 -> V_43 + V_20 * V_3 ;
V_23 -> V_24 [ V_17 ] . V_44 = V_23 -> V_24 [ V_17 ] . V_43 + V_20 - 1 ;
V_18 = F_20 ( V_25 , & V_23 -> V_24 [ V_17 ] ) ;
F_21 ( V_18 ) ;
}
if ( V_16 )
F_22 ( V_23 ) ;
F_23 ( V_23 , V_23 -> V_4 ) ;
F_24 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
V_18 = F_25 ( V_23 ) ;
sprintf ( V_21 , L_1 , V_3 ) ;
V_18 = F_26 ( & V_2 -> V_2 . V_45 , & V_23 -> V_2 . V_45 , V_21 ) ;
if ( V_18 )
goto V_46;
V_18 = F_26 ( & V_23 -> V_2 . V_45 , & V_2 -> V_2 . V_45 , L_2 ) ;
if ( V_18 )
goto V_47;
F_27 ( & V_23 -> V_2 . V_45 , V_48 ) ;
return 0 ;
V_47:
F_28 ( & V_2 -> V_2 . V_45 , V_21 ) ;
V_46:
F_29 ( V_2 ) ;
F_12 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
F_30 ( V_23 ) ;
V_30:
F_8 ( V_2 -> V_4 , V_4 ) ;
V_29:
F_24 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
return V_18 ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
char V_21 [ V_22 ] ;
struct V_1 * V_23 ;
struct V_26 * V_27 = V_2 -> V_7 ;
V_23 = F_32 ( F_5 ( V_2 -> V_4 ) ,
F_1 ( V_2 , V_3 ) ,
F_2 ( V_2 , V_3 ) ) ;
if ( ! V_23 )
return;
if ( V_16 ) {
F_33 ( & V_23 -> V_2 ) ;
F_22 ( V_23 ) ;
}
sprintf ( V_21 , L_1 , V_3 ) ;
F_28 ( & V_2 -> V_2 . V_45 , V_21 ) ;
if ( V_23 -> V_2 . V_45 . V_49 )
F_28 ( & V_23 -> V_2 . V_45 , L_2 ) ;
F_12 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
F_30 ( V_23 ) ;
F_8 ( V_2 -> V_4 , V_23 -> V_4 ) ;
F_24 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
F_29 ( V_23 ) ;
F_29 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_3 V_50 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_51 )
return 0 ;
if ( ! ( V_27 -> V_52 & V_53 ) )
return 0 ;
F_14 ( V_2 , V_27 -> V_32 + V_54 , & V_50 ) ;
if ( ! ( V_50 & V_55 ) )
return 0 ;
F_35 ( & V_27 -> V_56 ) ;
return 1 ;
}
static void F_36 ( struct V_57 * V_58 )
{
int V_17 ;
T_1 V_59 ;
T_3 V_50 ;
struct V_26 * V_27 = F_37 ( V_58 , struct V_26 , V_56 ) ;
for ( V_17 = V_27 -> V_60 ; V_17 < V_27 -> V_51 ; V_17 ++ ) {
V_59 = F_38 ( V_27 -> V_61 + V_17 ) ;
if ( V_59 == V_62 ) {
F_39 ( V_63 , V_27 -> V_61 + V_17 ) ;
V_59 = F_38 ( V_27 -> V_61 + V_17 ) ;
if ( V_59 == V_63 )
F_11 ( V_27 -> V_64 , V_17 , 1 ) ;
} else if ( V_59 == V_65 ) {
F_31 ( V_27 -> V_64 , V_17 , 1 ) ;
F_39 ( V_66 , V_27 -> V_61 + V_17 ) ;
V_59 = F_38 ( V_27 -> V_61 + V_17 ) ;
if ( V_59 == V_63 )
F_11 ( V_27 -> V_64 , V_17 , 0 ) ;
}
}
F_14 ( V_27 -> V_64 , V_27 -> V_32 + V_54 , & V_50 ) ;
V_50 &= ~ V_55 ;
F_40 ( V_27 -> V_64 , V_27 -> V_32 + V_54 , V_50 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_67 )
{
int V_68 ;
T_4 V_69 ;
T_5 V_70 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( V_67 <= V_27 -> V_60 )
return 0 ;
F_42 ( V_2 , V_27 -> V_32 + V_71 , & V_69 ) ;
V_68 = F_43 ( V_69 ) ;
if ( V_68 > V_72 )
return - V_73 ;
V_69 = F_44 ( V_69 ) ;
if ( V_69 + V_67 > F_45 ( V_2 , V_68 ) )
return - V_73 ;
V_70 = F_46 ( V_2 , V_68 ) + V_69 ;
V_27 -> V_61 = F_47 ( V_70 , V_67 ) ;
if ( ! V_27 -> V_61 )
return - V_19 ;
F_48 ( & V_27 -> V_56 , F_36 ) ;
V_27 -> V_74 |= V_75 | V_76 ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_7 ;
V_27 -> V_74 &= ~ ( V_75 | V_76 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
F_50 ( & V_27 -> V_56 ) ;
F_51 ( V_27 -> V_61 ) ;
}
static int F_52 ( struct V_1 * V_2 , int V_67 )
{
int V_18 ;
int V_17 , V_78 ;
int V_79 ;
T_3 V_8 , V_9 , V_80 ;
struct V_24 * V_25 ;
struct V_1 * V_81 ;
struct V_26 * V_27 = V_2 -> V_7 ;
int V_82 = 0 ;
if ( ! V_67 )
return 0 ;
if ( V_27 -> V_51 )
return - V_83 ;
F_14 ( V_2 , V_27 -> V_32 + V_84 , & V_80 ) ;
if ( V_80 > V_27 -> V_42 ||
( ! ( V_27 -> V_52 & V_53 ) && ( V_80 != V_27 -> V_42 ) ) )
return - V_73 ;
if ( V_67 < 0 || V_67 > V_27 -> V_42 ||
( ! ( V_27 -> V_52 & V_53 ) && ( V_67 > V_80 ) ) )
return - V_83 ;
F_14 ( V_2 , V_27 -> V_32 + V_85 , & V_8 ) ;
F_14 ( V_2 , V_27 -> V_32 + V_86 , & V_9 ) ;
if ( ! V_8 || ( V_67 > 1 && ! V_9 ) )
return - V_73 ;
V_79 = 0 ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
V_82 |= ( 1 << ( V_17 + V_39 ) ) ;
V_25 = V_2 -> V_24 + V_39 + V_17 ;
if ( V_25 -> V_35 )
V_79 ++ ;
}
if ( V_79 != V_27 -> V_79 ) {
F_53 ( & V_2 -> V_2 , L_3 ) ;
return - V_19 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_67 - 1 ) > V_2 -> V_4 -> V_87 . V_44 ) {
F_53 ( & V_2 -> V_2 , L_4 ) ;
return - V_19 ;
}
if ( F_54 ( V_2 , V_82 ) ) {
F_53 ( & V_2 -> V_2 , L_5 ) ;
return - V_19 ;
}
if ( V_27 -> V_88 != V_2 -> V_6 ) {
V_81 = F_55 ( V_2 -> V_4 , V_27 -> V_88 ) ;
if ( ! V_81 )
return - V_89 ;
if ( ! V_81 -> V_90 ) {
F_29 ( V_81 ) ;
return - V_91 ;
}
V_18 = F_26 ( & V_2 -> V_2 . V_45 ,
& V_81 -> V_2 . V_45 , L_6 ) ;
F_29 ( V_81 ) ;
if ( V_18 )
return V_18 ;
}
F_40 ( V_2 , V_27 -> V_32 + V_92 , V_67 ) ;
V_27 -> V_74 |= V_93 | V_94 ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
F_57 ( 100 ) ;
F_58 ( V_2 ) ;
V_27 -> V_60 = V_80 ;
if ( V_67 < V_80 )
V_80 = V_67 ;
for ( V_17 = 0 ; V_17 < V_80 ; V_17 ++ ) {
V_18 = F_11 ( V_2 , V_17 , 0 ) ;
if ( V_18 )
goto V_29;
}
if ( V_27 -> V_52 & V_53 ) {
V_18 = F_41 ( V_2 , V_67 ) ;
if ( V_18 )
goto V_29;
}
F_27 ( & V_2 -> V_2 . V_45 , V_48 ) ;
V_27 -> V_51 = V_67 ;
return 0 ;
V_29:
for ( V_78 = 0 ; V_78 < V_17 ; V_78 ++ )
F_31 ( V_2 , V_78 , 0 ) ;
V_27 -> V_74 &= ~ ( V_93 | V_94 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_92 , 0 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_88 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_45 , L_6 ) ;
return V_18 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_51 )
return;
if ( V_27 -> V_52 & V_53 )
F_49 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < V_27 -> V_51 ; V_17 ++ )
F_31 ( V_2 , V_17 , 0 ) ;
V_27 -> V_74 &= ~ ( V_93 | V_94 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_88 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_45 , L_6 ) ;
V_27 -> V_51 = 0 ;
F_40 ( V_2 , V_27 -> V_32 + V_92 , 0 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_32 )
{
int V_17 ;
int V_18 ;
int V_79 ;
T_4 V_95 ;
T_3 V_74 , V_96 , V_8 , V_9 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_1 * V_81 ;
if ( F_62 ( V_2 ) != V_97 &&
F_62 ( V_2 ) != V_98 )
return - V_89 ;
F_14 ( V_2 , V_32 + V_77 , & V_74 ) ;
if ( V_74 & V_93 ) {
F_40 ( V_2 , V_32 + V_77 , 0 ) ;
F_59 ( 1 ) ;
}
F_14 ( V_2 , V_32 + V_99 , & V_96 ) ;
if ( ! V_96 )
return 0 ;
V_74 = 0 ;
F_63 (pdev, &dev->bus->devices, bus_list)
if ( V_81 -> V_90 )
goto V_100;
V_81 = NULL ;
if ( F_64 ( V_2 -> V_4 ) )
V_74 |= V_101 ;
V_100:
F_40 ( V_2 , V_32 + V_77 , V_74 ) ;
F_14 ( V_2 , V_32 + V_85 , & V_8 ) ;
F_14 ( V_2 , V_32 + V_86 , & V_9 ) ;
if ( ! V_8 || ( V_96 > 1 && ! V_9 ) )
return - V_73 ;
F_42 ( V_2 , V_32 + V_102 , & V_95 ) ;
V_17 = V_103 > 12 ? V_103 - 12 : 0 ;
V_95 &= ~ ( ( 1 << V_17 ) - 1 ) ;
if ( ! V_95 )
return - V_73 ;
V_95 &= ~ ( V_95 - 1 ) ;
F_65 ( V_2 , V_32 + V_104 , V_95 ) ;
V_79 = 0 ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_39 + V_17 ;
V_17 += F_66 ( V_2 , V_105 , V_25 ,
V_32 + V_106 + V_17 * 4 ) ;
if ( ! V_25 -> V_41 )
continue;
if ( F_18 ( V_25 ) & ( V_107 - 1 ) ) {
V_18 = - V_73 ;
goto V_29;
}
V_25 -> V_44 = V_25 -> V_43 + F_18 ( V_25 ) * V_96 - 1 ;
V_79 ++ ;
}
V_27 = F_67 ( sizeof( * V_27 ) , V_108 ) ;
if ( ! V_27 ) {
V_18 = - V_19 ;
goto V_29;
}
V_27 -> V_32 = V_32 ;
V_27 -> V_79 = V_79 ;
V_27 -> V_74 = V_74 ;
V_27 -> V_42 = V_96 ;
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
V_27 -> V_95 = V_95 ;
V_27 -> V_64 = V_2 ;
F_42 ( V_2 , V_32 + V_109 , & V_27 -> V_52 ) ;
F_68 ( V_2 , V_32 + V_110 , & V_27 -> V_88 ) ;
if ( F_62 ( V_2 ) == V_97 )
V_27 -> V_88 = F_69 ( F_70 ( V_2 -> V_6 ) , V_27 -> V_88 ) ;
if ( V_81 )
V_27 -> V_2 = F_16 ( V_81 ) ;
else
V_27 -> V_2 = V_2 ;
F_71 ( & V_27 -> V_28 ) ;
V_2 -> V_7 = V_27 ;
V_2 -> V_90 = 1 ;
return 0 ;
V_29:
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_39 + V_17 ;
V_25 -> V_41 = 0 ;
}
return V_18 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_7 -> V_51 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_29 ( V_2 -> V_7 -> V_2 ) ;
F_73 ( & V_2 -> V_7 -> V_28 ) ;
F_74 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_75 ( struct V_1 * V_2 )
{
int V_17 ;
T_3 V_74 ;
struct V_26 * V_27 = V_2 -> V_7 ;
F_14 ( V_2 , V_27 -> V_32 + V_77 , & V_74 ) ;
if ( V_74 & V_93 )
return;
for ( V_17 = V_39 ; V_17 <= V_111 ; V_17 ++ )
F_76 ( V_2 , V_17 ) ;
F_65 ( V_2 , V_27 -> V_32 + V_104 , V_27 -> V_95 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_92 , V_27 -> V_51 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_77 , V_27 -> V_74 ) ;
if ( V_27 -> V_74 & V_93 )
F_57 ( 100 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_78 ( V_2 ) )
return - V_89 ;
V_32 = F_79 ( V_2 , V_112 ) ;
if ( V_32 )
return F_61 ( V_2 , V_32 ) ;
return - V_89 ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 )
F_72 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 , int V_113 ,
enum V_114 * type )
{
if ( V_113 < V_39 || V_113 > V_111 )
return 0 ;
F_21 ( ! V_2 -> V_90 ) ;
* type = V_105 ;
return V_2 -> V_7 -> V_32 + V_106 +
4 * ( V_113 - V_39 ) ;
}
T_5 F_82 ( struct V_1 * V_2 , int V_113 )
{
struct V_24 V_115 ;
enum V_114 type ;
int V_116 = F_81 ( V_2 , V_113 , & type ) ;
if ( ! V_116 )
return 0 ;
F_66 ( V_2 , type , & V_115 , V_116 ) ;
return F_83 ( & V_115 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_90 )
F_75 ( V_2 ) ;
}
int F_85 ( struct V_10 * V_4 )
{
int V_117 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_63 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_90 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_42 - 1 ) ;
if ( V_11 > V_117 )
V_117 = V_11 ;
}
return V_117 ? V_117 - V_4 -> V_5 : 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_67 )
{
F_87 () ;
if ( ! V_2 -> V_90 )
return - V_91 ;
return F_52 ( V_2 , V_67 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_87 () ;
if ( ! V_2 -> V_90 )
return;
F_60 ( V_2 ) ;
}
T_6 F_89 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_90 )
return V_118 ;
return F_34 ( V_2 ) ? V_119 : V_118 ;
}
int F_90 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_90 )
return 0 ;
return V_2 -> V_7 -> V_51 ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_1 * V_120 ;
unsigned int V_121 = 0 ;
unsigned short V_122 ;
if ( ! V_2 -> V_90 )
return 0 ;
F_14 ( V_2 , V_2 -> V_7 -> V_32 + V_33 , & V_122 ) ;
V_120 = F_92 ( V_2 -> V_31 , V_122 , NULL ) ;
while ( V_120 ) {
if ( V_120 -> V_37 && ( V_120 -> V_36 == V_2 ) &&
( V_120 -> V_123 & V_124 ) )
V_121 ++ ;
V_120 = F_92 ( V_2 -> V_31 , V_122 , V_120 ) ;
}
return V_121 ;
}
int F_93 ( struct V_1 * V_2 , T_3 V_125 )
{
if ( ! V_2 -> V_90 )
return - V_91 ;
if ( V_125 > V_2 -> V_7 -> V_42 )
return - V_83 ;
if ( V_2 -> V_7 -> V_74 & V_93 )
return - V_126 ;
else
V_2 -> V_7 -> V_127 = V_125 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_90 )
return 0 ;
if ( V_2 -> V_7 -> V_127 )
return V_2 -> V_7 -> V_127 ;
return V_2 -> V_7 -> V_42 ;
}
