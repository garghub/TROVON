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
V_23 -> V_38 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_40 + V_17 ;
if ( ! V_25 -> V_35 )
continue;
V_23 -> V_24 [ V_17 ] . V_41 = F_17 ( V_23 ) ;
V_23 -> V_24 [ V_17 ] . V_42 = V_25 -> V_42 ;
V_20 = F_18 ( V_25 ) ;
F_19 ( V_20 , V_27 -> V_43 ) ;
V_23 -> V_24 [ V_17 ] . V_44 = V_25 -> V_44 + V_20 * V_3 ;
V_23 -> V_24 [ V_17 ] . V_45 = V_23 -> V_24 [ V_17 ] . V_44 + V_20 - 1 ;
V_18 = F_20 ( V_25 , & V_23 -> V_24 [ V_17 ] ) ;
F_21 ( V_18 ) ;
}
if ( V_16 )
F_22 ( V_23 ) ;
F_23 ( V_23 , V_23 -> V_4 ) ;
F_24 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
V_18 = F_25 ( V_23 ) ;
sprintf ( V_21 , L_1 , V_3 ) ;
V_18 = F_26 ( & V_2 -> V_2 . V_46 , & V_23 -> V_2 . V_46 , V_21 ) ;
if ( V_18 )
goto V_47;
V_18 = F_26 ( & V_23 -> V_2 . V_46 , & V_2 -> V_2 . V_46 , L_2 ) ;
if ( V_18 )
goto V_48;
F_27 ( & V_23 -> V_2 . V_46 , V_49 ) ;
return 0 ;
V_48:
F_28 ( & V_2 -> V_2 . V_46 , V_21 ) ;
V_47:
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
F_28 ( & V_2 -> V_2 . V_46 , V_21 ) ;
if ( V_23 -> V_2 . V_46 . V_50 )
F_28 ( & V_23 -> V_2 . V_46 , L_2 ) ;
F_12 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
F_30 ( V_23 ) ;
F_8 ( V_2 -> V_4 , V_23 -> V_4 ) ;
F_24 ( & V_27 -> V_2 -> V_7 -> V_28 ) ;
F_29 ( V_23 ) ;
F_29 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_3 V_51 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_52 )
return 0 ;
if ( ! ( V_27 -> V_53 & V_54 ) )
return 0 ;
F_14 ( V_2 , V_27 -> V_32 + V_55 , & V_51 ) ;
if ( ! ( V_51 & V_56 ) )
return 0 ;
F_35 ( & V_27 -> V_57 ) ;
return 1 ;
}
static void F_36 ( struct V_58 * V_59 )
{
int V_17 ;
T_1 V_60 ;
T_3 V_51 ;
struct V_26 * V_27 = F_37 ( V_59 , struct V_26 , V_57 ) ;
for ( V_17 = V_27 -> V_61 ; V_17 < V_27 -> V_52 ; V_17 ++ ) {
V_60 = F_38 ( V_27 -> V_62 + V_17 ) ;
if ( V_60 == V_63 ) {
F_39 ( V_64 , V_27 -> V_62 + V_17 ) ;
V_60 = F_38 ( V_27 -> V_62 + V_17 ) ;
if ( V_60 == V_64 )
F_11 ( V_27 -> V_65 , V_17 , 1 ) ;
} else if ( V_60 == V_66 ) {
F_31 ( V_27 -> V_65 , V_17 , 1 ) ;
F_39 ( V_67 , V_27 -> V_62 + V_17 ) ;
V_60 = F_38 ( V_27 -> V_62 + V_17 ) ;
if ( V_60 == V_64 )
F_11 ( V_27 -> V_65 , V_17 , 0 ) ;
}
}
F_14 ( V_27 -> V_65 , V_27 -> V_32 + V_55 , & V_51 ) ;
V_51 &= ~ V_56 ;
F_40 ( V_27 -> V_65 , V_27 -> V_32 + V_55 , V_51 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_68 )
{
int V_69 ;
T_4 V_70 ;
T_5 V_71 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( V_68 <= V_27 -> V_61 )
return 0 ;
F_42 ( V_2 , V_27 -> V_32 + V_72 , & V_70 ) ;
V_69 = F_43 ( V_70 ) ;
if ( V_69 > V_73 )
return - V_74 ;
V_70 = F_44 ( V_70 ) ;
if ( V_70 + V_68 > F_45 ( V_2 , V_69 ) )
return - V_74 ;
V_71 = F_46 ( V_2 , V_69 ) + V_70 ;
V_27 -> V_62 = F_47 ( V_71 , V_68 ) ;
if ( ! V_27 -> V_62 )
return - V_19 ;
F_48 ( & V_27 -> V_57 , F_36 ) ;
V_27 -> V_75 |= V_76 | V_77 ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_7 ;
V_27 -> V_75 &= ~ ( V_76 | V_77 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
F_50 ( & V_27 -> V_57 ) ;
F_51 ( V_27 -> V_62 ) ;
}
static int F_52 ( struct V_1 * V_2 , int V_68 )
{
int V_18 ;
int V_17 , V_79 ;
int V_80 ;
T_3 V_8 , V_9 , V_81 ;
struct V_24 * V_25 ;
struct V_1 * V_82 ;
struct V_26 * V_27 = V_2 -> V_7 ;
int V_83 = 0 ;
if ( ! V_68 )
return 0 ;
if ( V_27 -> V_52 )
return - V_84 ;
F_14 ( V_2 , V_27 -> V_32 + V_85 , & V_81 ) ;
if ( V_81 > V_27 -> V_43 ||
( ! ( V_27 -> V_53 & V_54 ) && ( V_81 != V_27 -> V_43 ) ) )
return - V_74 ;
if ( V_68 < 0 || V_68 > V_27 -> V_43 ||
( ! ( V_27 -> V_53 & V_54 ) && ( V_68 > V_81 ) ) )
return - V_84 ;
F_14 ( V_2 , V_27 -> V_32 + V_86 , & V_8 ) ;
F_14 ( V_2 , V_27 -> V_32 + V_87 , & V_9 ) ;
if ( ! V_8 || ( V_68 > 1 && ! V_9 ) )
return - V_74 ;
V_80 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_83 |= ( 1 << ( V_17 + V_40 ) ) ;
V_25 = V_2 -> V_24 + V_40 + V_17 ;
if ( V_25 -> V_35 )
V_80 ++ ;
}
if ( V_80 != V_27 -> V_80 ) {
F_53 ( & V_2 -> V_2 , L_3 ) ;
return - V_19 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_68 - 1 ) > V_2 -> V_4 -> V_88 . V_45 ) {
F_53 ( & V_2 -> V_2 , L_4 ) ;
return - V_19 ;
}
if ( F_54 ( V_2 , V_83 ) ) {
F_53 ( & V_2 -> V_2 , L_5 ) ;
return - V_19 ;
}
if ( V_27 -> V_89 != V_2 -> V_6 ) {
V_82 = F_55 ( V_2 -> V_4 , V_27 -> V_89 ) ;
if ( ! V_82 )
return - V_90 ;
if ( ! V_82 -> V_91 ) {
F_29 ( V_82 ) ;
return - V_92 ;
}
V_18 = F_26 ( & V_2 -> V_2 . V_46 ,
& V_82 -> V_2 . V_46 , L_6 ) ;
F_29 ( V_82 ) ;
if ( V_18 )
return V_18 ;
}
F_40 ( V_2 , V_27 -> V_32 + V_93 , V_68 ) ;
V_27 -> V_75 |= V_94 | V_95 ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
F_57 ( 100 ) ;
F_58 ( V_2 ) ;
V_27 -> V_61 = V_81 ;
if ( V_68 < V_81 )
V_81 = V_68 ;
for ( V_17 = 0 ; V_17 < V_81 ; V_17 ++ ) {
V_18 = F_11 ( V_2 , V_17 , 0 ) ;
if ( V_18 )
goto V_29;
}
if ( V_27 -> V_53 & V_54 ) {
V_18 = F_41 ( V_2 , V_68 ) ;
if ( V_18 )
goto V_29;
}
F_27 ( & V_2 -> V_2 . V_46 , V_49 ) ;
V_27 -> V_52 = V_68 ;
return 0 ;
V_29:
for ( V_79 = 0 ; V_79 < V_17 ; V_79 ++ )
F_31 ( V_2 , V_79 , 0 ) ;
V_27 -> V_75 &= ~ ( V_94 | V_95 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_93 , 0 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_89 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_46 , L_6 ) ;
return V_18 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_52 )
return;
if ( V_27 -> V_53 & V_54 )
F_49 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < V_27 -> V_52 ; V_17 ++ )
F_31 ( V_2 , V_17 , 0 ) ;
V_27 -> V_75 &= ~ ( V_94 | V_95 ) ;
F_56 ( V_2 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
F_59 ( 1 ) ;
F_58 ( V_2 ) ;
if ( V_27 -> V_89 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_46 , L_6 ) ;
V_27 -> V_52 = 0 ;
F_40 ( V_2 , V_27 -> V_32 + V_93 , 0 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_32 )
{
int V_17 ;
int V_18 ;
int V_80 ;
T_4 V_96 ;
T_3 V_75 , V_97 , V_8 , V_9 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_1 * V_82 ;
if ( F_62 ( V_2 ) != V_98 &&
F_62 ( V_2 ) != V_99 )
return - V_90 ;
F_14 ( V_2 , V_32 + V_78 , & V_75 ) ;
if ( V_75 & V_94 ) {
F_40 ( V_2 , V_32 + V_78 , 0 ) ;
F_59 ( 1 ) ;
}
F_14 ( V_2 , V_32 + V_100 , & V_97 ) ;
if ( ! V_97 )
return 0 ;
V_75 = 0 ;
F_63 (pdev, &dev->bus->devices, bus_list)
if ( V_82 -> V_91 )
goto V_101;
V_82 = NULL ;
if ( F_64 ( V_2 -> V_4 ) )
V_75 |= V_102 ;
V_101:
F_40 ( V_2 , V_32 + V_78 , V_75 ) ;
F_40 ( V_2 , V_32 + V_93 , 0 ) ;
F_14 ( V_2 , V_32 + V_86 , & V_8 ) ;
F_14 ( V_2 , V_32 + V_87 , & V_9 ) ;
if ( ! V_8 || ( V_97 > 1 && ! V_9 ) )
return - V_74 ;
F_42 ( V_2 , V_32 + V_103 , & V_96 ) ;
V_17 = V_104 > 12 ? V_104 - 12 : 0 ;
V_96 &= ~ ( ( 1 << V_17 ) - 1 ) ;
if ( ! V_96 )
return - V_74 ;
V_96 &= ~ ( V_96 - 1 ) ;
F_65 ( V_2 , V_32 + V_105 , V_96 ) ;
V_80 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_40 + V_17 ;
V_17 += F_66 ( V_2 , V_106 , V_25 ,
V_32 + V_107 + V_17 * 4 ) ;
if ( ! V_25 -> V_42 )
continue;
if ( F_18 ( V_25 ) & ( V_108 - 1 ) ) {
V_18 = - V_74 ;
goto V_29;
}
V_25 -> V_45 = V_25 -> V_44 + F_18 ( V_25 ) * V_97 - 1 ;
V_80 ++ ;
}
V_27 = F_67 ( sizeof( * V_27 ) , V_109 ) ;
if ( ! V_27 ) {
V_18 = - V_19 ;
goto V_29;
}
V_27 -> V_32 = V_32 ;
V_27 -> V_80 = V_80 ;
V_27 -> V_75 = V_75 ;
V_27 -> V_43 = V_97 ;
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
V_27 -> V_96 = V_96 ;
V_27 -> V_65 = V_2 ;
F_42 ( V_2 , V_32 + V_110 , & V_27 -> V_53 ) ;
F_68 ( V_2 , V_32 + V_111 , & V_27 -> V_89 ) ;
if ( F_62 ( V_2 ) == V_98 )
V_27 -> V_89 = F_69 ( F_70 ( V_2 -> V_6 ) , V_27 -> V_89 ) ;
if ( V_82 )
V_27 -> V_2 = F_16 ( V_82 ) ;
else
V_27 -> V_2 = V_2 ;
F_71 ( & V_27 -> V_28 ) ;
V_2 -> V_7 = V_27 ;
V_2 -> V_91 = 1 ;
return 0 ;
V_29:
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_40 + V_17 ;
V_25 -> V_42 = 0 ;
}
return V_18 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_7 -> V_52 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_29 ( V_2 -> V_7 -> V_2 ) ;
F_73 ( & V_2 -> V_7 -> V_28 ) ;
F_74 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_75 ( struct V_1 * V_2 )
{
int V_17 ;
T_3 V_75 ;
struct V_26 * V_27 = V_2 -> V_7 ;
F_14 ( V_2 , V_27 -> V_32 + V_78 , & V_75 ) ;
if ( V_75 & V_94 )
return;
for ( V_17 = V_40 ; V_17 <= V_112 ; V_17 ++ )
F_76 ( V_2 , V_17 ) ;
F_65 ( V_2 , V_27 -> V_32 + V_105 , V_27 -> V_96 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_93 , V_27 -> V_52 ) ;
F_40 ( V_2 , V_27 -> V_32 + V_78 , V_27 -> V_75 ) ;
if ( V_27 -> V_75 & V_94 )
F_57 ( 100 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_78 ( V_2 ) )
return - V_90 ;
V_32 = F_79 ( V_2 , V_113 ) ;
if ( V_32 )
return F_61 ( V_2 , V_32 ) ;
return - V_90 ;
}
void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 )
F_72 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 , int V_114 ,
enum V_115 * type )
{
if ( V_114 < V_40 || V_114 > V_112 )
return 0 ;
F_21 ( ! V_2 -> V_91 ) ;
* type = V_106 ;
return V_2 -> V_7 -> V_32 + V_107 +
4 * ( V_114 - V_40 ) ;
}
T_5 F_82 ( struct V_1 * V_2 , int V_114 )
{
struct V_24 V_116 ;
enum V_115 type ;
int V_117 = F_81 ( V_2 , V_114 , & type ) ;
if ( ! V_117 )
return 0 ;
F_66 ( V_2 , type , & V_116 , V_117 ) ;
return F_83 ( & V_116 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 )
F_75 ( V_2 ) ;
}
int F_85 ( struct V_10 * V_4 )
{
int V_118 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_63 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_91 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_43 - 1 ) ;
if ( V_11 > V_118 )
V_118 = V_11 ;
}
return V_118 ? V_118 - V_4 -> V_5 : 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_68 )
{
F_87 () ;
if ( ! V_2 -> V_91 )
return - V_92 ;
return F_52 ( V_2 , V_68 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_87 () ;
if ( ! V_2 -> V_91 )
return;
F_60 ( V_2 ) ;
}
T_6 F_89 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return V_119 ;
return F_34 ( V_2 ) ? V_120 : V_119 ;
}
int F_90 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return 0 ;
return V_2 -> V_7 -> V_52 ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_1 * V_121 ;
unsigned int V_122 = 0 ;
unsigned short V_123 ;
if ( ! V_2 -> V_91 )
return 0 ;
F_14 ( V_2 , V_2 -> V_7 -> V_32 + V_33 , & V_123 ) ;
V_121 = F_92 ( V_2 -> V_31 , V_123 , NULL ) ;
while ( V_121 ) {
if ( V_121 -> V_37 && ( V_121 -> V_36 == V_2 ) &&
( V_121 -> V_124 & V_125 ) )
V_122 ++ ;
V_121 = F_92 ( V_2 -> V_31 , V_123 , V_121 ) ;
}
return V_122 ;
}
int F_93 ( struct V_1 * V_2 , T_3 V_126 )
{
if ( ! V_2 -> V_91 )
return - V_92 ;
if ( V_126 > V_2 -> V_7 -> V_43 )
return - V_84 ;
if ( V_2 -> V_7 -> V_75 & V_94 )
return - V_127 ;
else
V_2 -> V_7 -> V_128 = V_126 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 )
return 0 ;
if ( V_2 -> V_7 -> V_128 )
return V_2 -> V_7 -> V_128 ;
return V_2 -> V_7 -> V_43 ;
}
