int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 -> V_4 )
return - V_5 ;
return V_2 -> V_6 -> V_7 + ( ( V_2 -> V_8 + V_2 -> V_9 -> V_10 +
V_2 -> V_9 -> V_11 * V_3 ) >> 8 ) ;
}
int F_2 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 -> V_4 )
return - V_5 ;
return ( V_2 -> V_8 + V_2 -> V_9 -> V_10 +
V_2 -> V_9 -> V_11 * V_3 ) & 0xff ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
F_4 ( V_2 , V_14 -> V_15 + V_16 , V_12 ) ;
F_5 ( V_2 , V_14 -> V_15 + V_17 , & V_14 -> V_10 ) ;
F_5 ( V_2 , V_14 -> V_15 + V_18 , & V_14 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
int V_12 , V_19 , V_20 = 0 ;
for ( V_12 = V_14 -> V_21 ; V_12 ; V_12 -- ) {
F_3 ( V_2 , V_12 ) ;
if ( ! V_14 -> V_10 || ( V_12 > 1 && ! V_14 -> V_11 ) ) {
V_20 = - V_22 ;
goto V_23;
}
V_19 = F_1 ( V_2 , V_12 - 1 ) ;
if ( V_19 > V_14 -> V_24 )
V_14 -> V_24 = V_19 ;
}
V_23:
F_3 ( V_2 , 0 ) ;
return V_20 ;
}
static struct V_25 * F_7 ( struct V_25 * V_6 , int V_19 )
{
struct V_25 * V_26 ;
if ( V_6 -> V_7 == V_19 )
return V_6 ;
V_26 = F_8 ( F_9 ( V_6 ) , V_19 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_10 ( V_6 , NULL , V_19 ) ;
if ( ! V_26 )
return NULL ;
F_11 ( V_26 , V_19 , V_19 ) ;
return V_26 ;
}
static void F_12 ( struct V_25 * V_27 , struct V_25 * V_28 )
{
if ( V_27 != V_28 && F_13 ( & V_28 -> V_29 ) )
F_14 ( V_28 ) ;
}
T_1 F_15 ( struct V_1 * V_2 , int V_30 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> V_9 -> V_31 [ V_30 - V_32 ] ;
}
int F_16 ( struct V_1 * V_2 , int V_33 , int V_34 )
{
int V_35 ;
int V_20 = - V_36 ;
T_2 V_37 ;
char V_38 [ V_39 ] ;
struct V_1 * V_40 ;
struct V_41 * V_42 ;
struct V_13 * V_14 = V_2 -> V_9 ;
struct V_25 * V_6 ;
V_6 = F_7 ( V_2 -> V_6 , F_1 ( V_2 , V_33 ) ) ;
if ( ! V_6 )
goto V_43;
V_40 = F_17 ( V_6 ) ;
if ( ! V_40 )
goto V_44;
V_40 -> V_8 = F_2 ( V_2 , V_33 ) ;
V_40 -> V_45 = V_2 -> V_45 ;
F_5 ( V_2 , V_14 -> V_15 + V_46 , & V_40 -> V_47 ) ;
V_20 = F_18 ( V_40 ) ;
if ( V_20 )
goto V_44;
V_40 -> V_2 . V_48 = V_2 -> V_2 . V_48 ;
V_40 -> V_49 = F_19 ( V_2 ) ;
V_40 -> V_50 = 1 ;
V_40 -> V_51 = 0 ;
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( ! V_42 -> V_48 )
continue;
V_40 -> V_41 [ V_35 ] . V_53 = F_20 ( V_40 ) ;
V_40 -> V_41 [ V_35 ] . V_54 = V_42 -> V_54 ;
V_37 = F_15 ( V_2 , V_35 + V_32 ) ;
V_40 -> V_41 [ V_35 ] . V_55 = V_42 -> V_55 + V_37 * V_33 ;
V_40 -> V_41 [ V_35 ] . V_56 = V_40 -> V_41 [ V_35 ] . V_55 + V_37 - 1 ;
V_20 = F_21 ( V_42 , & V_40 -> V_41 [ V_35 ] ) ;
F_22 ( V_20 ) ;
}
if ( V_34 )
F_23 ( V_40 ) ;
F_24 ( V_40 , V_40 -> V_6 ) ;
F_25 ( V_40 ) ;
sprintf ( V_38 , L_1 , V_33 ) ;
V_20 = F_26 ( & V_2 -> V_2 . V_57 , & V_40 -> V_2 . V_57 , V_38 ) ;
if ( V_20 )
goto V_58;
V_20 = F_26 ( & V_40 -> V_2 . V_57 , & V_2 -> V_2 . V_57 , L_2 ) ;
if ( V_20 )
goto V_59;
F_27 ( & V_40 -> V_2 . V_57 , V_60 ) ;
return 0 ;
V_59:
F_28 ( & V_2 -> V_2 . V_57 , V_38 ) ;
V_58:
F_29 ( V_2 ) ;
F_30 ( V_40 ) ;
V_44:
F_12 ( V_2 -> V_6 , V_6 ) ;
V_43:
return V_20 ;
}
void F_31 ( struct V_1 * V_2 , int V_33 , int V_34 )
{
char V_38 [ V_39 ] ;
struct V_1 * V_40 ;
V_40 = F_32 ( F_9 ( V_2 -> V_6 ) ,
F_1 ( V_2 , V_33 ) ,
F_2 ( V_2 , V_33 ) ) ;
if ( ! V_40 )
return;
if ( V_34 ) {
F_33 ( & V_40 -> V_2 ) ;
F_23 ( V_40 ) ;
}
sprintf ( V_38 , L_1 , V_33 ) ;
F_28 ( & V_2 -> V_2 . V_57 , V_38 ) ;
if ( V_40 -> V_2 . V_57 . V_61 )
F_28 ( & V_40 -> V_2 . V_57 , L_2 ) ;
F_30 ( V_40 ) ;
F_12 ( V_2 -> V_6 , V_40 -> V_6 ) ;
F_29 ( V_40 ) ;
F_29 ( V_2 ) ;
}
int __weak F_34 ( struct V_1 * V_62 , T_3 V_63 )
{
return 0 ;
}
int __weak F_35 ( struct V_1 * V_62 )
{
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_12 )
{
int V_20 ;
int V_35 ;
int V_64 ;
T_3 V_65 ;
struct V_41 * V_42 ;
struct V_1 * V_62 ;
struct V_13 * V_14 = V_2 -> V_9 ;
int V_66 = 0 ;
int V_6 ;
if ( ! V_12 )
return 0 ;
if ( V_14 -> V_67 )
return - V_5 ;
F_5 ( V_2 , V_14 -> V_15 + V_68 , & V_65 ) ;
if ( V_65 > V_14 -> V_21 ||
( ! ( V_14 -> V_69 & V_70 ) && ( V_65 != V_14 -> V_21 ) ) )
return - V_22 ;
if ( V_12 < 0 || V_12 > V_14 -> V_21 ||
( ! ( V_14 -> V_69 & V_70 ) && ( V_12 > V_65 ) ) )
return - V_5 ;
V_64 = 0 ;
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
V_66 |= ( 1 << ( V_35 + V_32 ) ) ;
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( V_42 -> V_48 )
V_64 ++ ;
}
if ( V_64 != V_14 -> V_64 ) {
F_37 ( & V_2 -> V_2 , L_3 ) ;
return - V_36 ;
}
V_6 = F_1 ( V_2 , V_12 - 1 ) ;
if ( V_6 > V_2 -> V_6 -> V_71 . V_56 ) {
F_37 ( & V_2 -> V_2 , L_4 ,
V_12 , V_6 , & V_2 -> V_6 -> V_71 ) ;
return - V_36 ;
}
if ( F_38 ( V_2 , V_66 ) ) {
F_37 ( & V_2 -> V_2 , L_5 ) ;
return - V_36 ;
}
if ( V_14 -> V_72 != V_2 -> V_8 ) {
V_62 = F_39 ( V_2 -> V_6 , V_14 -> V_72 ) ;
if ( ! V_62 )
return - V_73 ;
if ( ! V_62 -> V_4 ) {
F_29 ( V_62 ) ;
return - V_74 ;
}
V_20 = F_26 ( & V_2 -> V_2 . V_57 ,
& V_62 -> V_2 . V_57 , L_6 ) ;
F_29 ( V_62 ) ;
if ( V_20 )
return V_20 ;
}
V_14 -> V_75 = V_65 ;
if ( V_12 < V_65 )
V_65 = V_12 ;
V_20 = F_34 ( V_2 , V_65 ) ;
if ( V_20 ) {
F_37 ( & V_2 -> V_2 , L_7 , V_20 ) ;
goto V_76;
}
F_3 ( V_2 , V_12 ) ;
V_14 -> V_77 |= V_78 | V_79 ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_41 ( 100 ) ;
F_42 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
V_20 = F_16 ( V_2 , V_35 , 0 ) ;
if ( V_20 )
goto V_43;
}
F_27 ( & V_2 -> V_2 . V_57 , V_60 ) ;
V_14 -> V_67 = V_12 ;
return 0 ;
V_43:
while ( V_35 -- )
F_31 ( V_2 , V_35 , 0 ) ;
F_35 ( V_2 ) ;
V_76:
V_14 -> V_77 &= ~ ( V_78 | V_79 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_43 ( 1 ) ;
F_42 ( V_2 ) ;
if ( V_14 -> V_72 != V_2 -> V_8 )
F_28 ( & V_2 -> V_2 . V_57 , L_6 ) ;
F_3 ( V_2 , 0 ) ;
return V_20 ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_13 * V_14 = V_2 -> V_9 ;
if ( ! V_14 -> V_67 )
return;
for ( V_35 = 0 ; V_35 < V_14 -> V_67 ; V_35 ++ )
F_31 ( V_2 , V_35 , 0 ) ;
F_35 ( V_2 ) ;
V_14 -> V_77 &= ~ ( V_78 | V_79 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_43 ( 1 ) ;
F_42 ( V_2 ) ;
if ( V_14 -> V_72 != V_2 -> V_8 )
F_28 ( & V_2 -> V_2 . V_57 , L_6 ) ;
V_14 -> V_67 = 0 ;
F_3 ( V_2 , 0 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_15 )
{
int V_35 , V_81 ;
int V_20 ;
int V_64 ;
T_4 V_82 ;
T_3 V_77 , V_83 ;
struct V_13 * V_14 ;
struct V_41 * V_42 ;
struct V_1 * V_62 ;
F_5 ( V_2 , V_15 + V_80 , & V_77 ) ;
if ( V_77 & V_78 ) {
F_4 ( V_2 , V_15 + V_80 , 0 ) ;
F_43 ( 1 ) ;
}
V_77 = 0 ;
F_46 (pdev, &dev->bus->devices, bus_list)
if ( V_62 -> V_4 )
goto V_84;
V_62 = NULL ;
if ( F_47 ( V_2 -> V_6 ) )
V_77 |= V_85 ;
V_84:
F_4 ( V_2 , V_15 + V_80 , V_77 ) ;
F_5 ( V_2 , V_15 + V_86 , & V_83 ) ;
if ( ! V_83 )
return 0 ;
F_48 ( V_2 , V_15 + V_87 , & V_82 ) ;
V_35 = V_88 > 12 ? V_88 - 12 : 0 ;
V_82 &= ~ ( ( 1 << V_35 ) - 1 ) ;
if ( ! V_82 )
return - V_22 ;
V_82 &= ~ ( V_82 - 1 ) ;
F_49 ( V_2 , V_15 + V_89 , V_82 ) ;
V_14 = F_50 ( sizeof( * V_14 ) , V_90 ) ;
if ( ! V_14 )
return - V_36 ;
V_64 = 0 ;
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( V_42 -> V_54 & V_91 )
V_81 = ( V_42 -> V_54 & V_92 ) ? 1 : 0 ;
else
V_81 = F_51 ( V_2 , V_93 , V_42 ,
V_15 + V_94 + V_35 * 4 ) ;
if ( ! V_42 -> V_54 )
continue;
if ( F_52 ( V_42 ) & ( V_95 - 1 ) ) {
V_20 = - V_22 ;
goto V_43;
}
V_14 -> V_31 [ V_35 ] = F_52 ( V_42 ) ;
V_42 -> V_56 = V_42 -> V_55 + F_52 ( V_42 ) * V_83 - 1 ;
F_53 ( & V_2 -> V_2 , L_8 ,
V_35 , V_42 , V_35 , V_83 ) ;
V_35 += V_81 ;
V_64 ++ ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_64 = V_64 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_21 = V_83 ;
V_14 -> V_82 = V_82 ;
V_14 -> V_96 = V_2 ;
V_14 -> V_97 = true ;
F_48 ( V_2 , V_15 + V_98 , & V_14 -> V_69 ) ;
F_54 ( V_2 , V_15 + V_99 , & V_14 -> V_72 ) ;
if ( F_55 ( V_2 ) == V_100 )
V_14 -> V_72 = F_56 ( F_57 ( V_2 -> V_8 ) , V_14 -> V_72 ) ;
if ( V_62 )
V_14 -> V_2 = F_19 ( V_62 ) ;
else
V_14 -> V_2 = V_2 ;
F_58 ( & V_14 -> V_101 ) ;
V_2 -> V_9 = V_14 ;
V_2 -> V_4 = 1 ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 )
goto V_102;
return 0 ;
V_102:
V_2 -> V_9 = NULL ;
V_2 -> V_4 = 0 ;
V_43:
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
V_42 -> V_54 = 0 ;
}
F_59 ( V_14 ) ;
return V_20 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_9 -> V_67 ) ;
if ( V_2 != V_2 -> V_9 -> V_2 )
F_29 ( V_2 -> V_9 -> V_2 ) ;
F_61 ( & V_2 -> V_9 -> V_101 ) ;
F_59 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_35 ;
T_3 V_77 ;
struct V_13 * V_14 = V_2 -> V_9 ;
F_5 ( V_2 , V_14 -> V_15 + V_80 , & V_77 ) ;
if ( V_77 & V_78 )
return;
for ( V_35 = V_32 ; V_35 <= V_103 ; V_35 ++ )
F_63 ( V_2 , V_35 ) ;
F_49 ( V_2 , V_14 -> V_15 + V_89 , V_14 -> V_82 ) ;
F_3 ( V_2 , V_14 -> V_67 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
if ( V_14 -> V_77 & V_78 )
F_41 ( 100 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_65 ( V_2 ) )
return - V_73 ;
V_15 = F_66 ( V_2 , V_104 ) ;
if ( V_15 )
return F_45 ( V_2 , V_15 ) ;
return - V_73 ;
}
void F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_60 ( V_2 ) ;
}
void F_68 ( struct V_1 * V_2 , int V_30 )
{
struct V_13 * V_14 = V_2 -> V_4 ? V_2 -> V_9 : NULL ;
struct V_41 * V_42 = V_2 -> V_41 + V_30 ;
int V_105 = V_30 - V_32 ;
struct V_106 V_107 ;
T_3 V_108 ;
T_4 V_109 ;
int V_110 ;
if ( ! V_14 )
return;
F_5 ( V_2 , V_14 -> V_15 + V_80 , & V_108 ) ;
if ( ( V_108 & V_78 ) && ( V_108 & V_79 ) ) {
F_69 ( & V_2 -> V_2 , L_9 ,
V_105 , V_42 ) ;
return;
}
if ( ! V_42 -> V_54 )
return;
if ( V_42 -> V_54 & V_111 )
return;
if ( V_42 -> V_54 & V_91 )
return;
F_70 ( V_2 -> V_6 , & V_107 , V_42 ) ;
V_109 = V_107 . V_55 ;
V_109 |= V_42 -> V_54 & ~ V_112 ;
V_110 = V_14 -> V_15 + V_94 + 4 * V_105 ;
F_49 ( V_2 , V_110 , V_109 ) ;
if ( V_42 -> V_54 & V_92 ) {
V_109 = V_107 . V_55 >> 16 >> 16 ;
F_49 ( V_2 , V_110 + 4 , V_109 ) ;
}
}
T_1 __weak F_71 ( struct V_1 * V_2 ,
int V_30 )
{
return F_15 ( V_2 , V_30 ) ;
}
T_1 F_72 ( struct V_1 * V_2 , int V_30 )
{
return F_71 ( V_2 , V_30 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_62 ( V_2 ) ;
}
int F_74 ( struct V_25 * V_6 )
{
int V_113 = 0 ;
struct V_1 * V_2 ;
F_46 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_4 )
continue;
if ( V_2 -> V_9 -> V_24 > V_113 )
V_113 = V_2 -> V_9 -> V_24 ;
}
return V_113 ? V_113 - V_6 -> V_7 : 0 ;
}
int F_75 ( struct V_1 * V_2 , int V_12 )
{
F_76 () ;
if ( ! V_2 -> V_4 )
return - V_74 ;
return F_36 ( V_2 , V_12 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_76 () ;
if ( ! V_2 -> V_4 )
return;
F_44 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> V_9 -> V_67 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_1 * V_114 ;
unsigned int V_115 = 0 ;
unsigned short V_116 ;
if ( ! V_2 -> V_4 )
return 0 ;
F_5 ( V_2 , V_2 -> V_9 -> V_15 + V_46 , & V_116 ) ;
V_114 = F_80 ( V_2 -> V_45 , V_116 , NULL ) ;
while ( V_114 ) {
if ( V_114 -> V_50 && ( V_114 -> V_49 == V_2 ) &&
F_81 ( V_114 ) )
V_115 ++ ;
V_114 = F_80 ( V_2 -> V_45 , V_116 , V_114 ) ;
}
return V_115 ;
}
int F_82 ( struct V_1 * V_2 , T_3 V_117 )
{
if ( ! V_2 -> V_4 )
return - V_74 ;
if ( V_117 > V_2 -> V_9 -> V_21 )
return - V_5 ;
if ( V_2 -> V_9 -> V_77 & V_78 )
return - V_118 ;
else
V_2 -> V_9 -> V_119 = V_117 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_9 -> V_119 )
return V_2 -> V_9 -> V_119 ;
return V_2 -> V_9 -> V_21 ;
}
