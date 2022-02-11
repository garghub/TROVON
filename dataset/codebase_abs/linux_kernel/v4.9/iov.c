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
F_17 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
V_6 = F_7 ( V_2 -> V_6 , F_1 ( V_2 , V_33 ) ) ;
if ( ! V_6 )
goto V_44;
V_40 = F_18 ( V_6 ) ;
if ( ! V_40 )
goto V_45;
V_40 -> V_8 = F_2 ( V_2 , V_33 ) ;
V_40 -> V_46 = V_2 -> V_46 ;
F_5 ( V_2 , V_14 -> V_15 + V_47 , & V_40 -> V_48 ) ;
V_20 = F_19 ( V_40 ) ;
if ( V_20 )
goto V_45;
V_40 -> V_2 . V_49 = V_2 -> V_2 . V_49 ;
V_40 -> V_50 = F_20 ( V_2 ) ;
V_40 -> V_51 = 1 ;
V_40 -> V_52 = 0 ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( ! V_42 -> V_49 )
continue;
V_40 -> V_41 [ V_35 ] . V_54 = F_21 ( V_40 ) ;
V_40 -> V_41 [ V_35 ] . V_55 = V_42 -> V_55 ;
V_37 = F_15 ( V_2 , V_35 + V_32 ) ;
V_40 -> V_41 [ V_35 ] . V_56 = V_42 -> V_56 + V_37 * V_33 ;
V_40 -> V_41 [ V_35 ] . V_57 = V_40 -> V_41 [ V_35 ] . V_56 + V_37 - 1 ;
V_20 = F_22 ( V_42 , & V_40 -> V_41 [ V_35 ] ) ;
F_23 ( V_20 ) ;
}
if ( V_34 )
F_24 ( V_40 ) ;
F_25 ( V_40 , V_40 -> V_6 ) ;
F_26 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
F_27 ( V_40 ) ;
sprintf ( V_38 , L_1 , V_33 ) ;
V_20 = F_28 ( & V_2 -> V_2 . V_58 , & V_40 -> V_2 . V_58 , V_38 ) ;
if ( V_20 )
goto V_59;
V_20 = F_28 ( & V_40 -> V_2 . V_58 , & V_2 -> V_2 . V_58 , L_2 ) ;
if ( V_20 )
goto V_60;
F_29 ( & V_40 -> V_2 . V_58 , V_61 ) ;
return 0 ;
V_60:
F_30 ( & V_2 -> V_2 . V_58 , V_38 ) ;
V_59:
F_31 ( V_2 ) ;
F_17 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
F_32 ( V_40 ) ;
V_45:
F_12 ( V_2 -> V_6 , V_6 ) ;
V_44:
F_26 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
return V_20 ;
}
void F_33 ( struct V_1 * V_2 , int V_33 , int V_34 )
{
char V_38 [ V_39 ] ;
struct V_1 * V_40 ;
struct V_13 * V_14 = V_2 -> V_9 ;
V_40 = F_34 ( F_9 ( V_2 -> V_6 ) ,
F_1 ( V_2 , V_33 ) ,
F_2 ( V_2 , V_33 ) ) ;
if ( ! V_40 )
return;
if ( V_34 ) {
F_35 ( & V_40 -> V_2 ) ;
F_24 ( V_40 ) ;
}
sprintf ( V_38 , L_1 , V_33 ) ;
F_30 ( & V_2 -> V_2 . V_58 , V_38 ) ;
if ( V_40 -> V_2 . V_58 . V_62 )
F_30 ( & V_40 -> V_2 . V_58 , L_2 ) ;
F_17 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
F_32 ( V_40 ) ;
F_12 ( V_2 -> V_6 , V_40 -> V_6 ) ;
F_26 ( & V_14 -> V_2 -> V_9 -> V_43 ) ;
F_31 ( V_40 ) ;
F_31 ( V_2 ) ;
}
int __weak F_36 ( struct V_1 * V_63 , T_3 V_64 )
{
return 0 ;
}
int __weak F_37 ( struct V_1 * V_63 )
{
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_12 )
{
int V_20 ;
int V_35 ;
int V_65 ;
T_3 V_66 ;
struct V_41 * V_42 ;
struct V_1 * V_63 ;
struct V_13 * V_14 = V_2 -> V_9 ;
int V_67 = 0 ;
int V_6 ;
if ( ! V_12 )
return 0 ;
if ( V_14 -> V_68 )
return - V_5 ;
F_5 ( V_2 , V_14 -> V_15 + V_69 , & V_66 ) ;
if ( V_66 > V_14 -> V_21 ||
( ! ( V_14 -> V_70 & V_71 ) && ( V_66 != V_14 -> V_21 ) ) )
return - V_22 ;
if ( V_12 < 0 || V_12 > V_14 -> V_21 ||
( ! ( V_14 -> V_70 & V_71 ) && ( V_12 > V_66 ) ) )
return - V_5 ;
V_65 = 0 ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ ) {
V_67 |= ( 1 << ( V_35 + V_32 ) ) ;
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( V_42 -> V_49 )
V_65 ++ ;
}
if ( V_65 != V_14 -> V_65 ) {
F_39 ( & V_2 -> V_2 , L_3 ) ;
return - V_36 ;
}
V_6 = F_1 ( V_2 , V_12 - 1 ) ;
if ( V_6 > V_2 -> V_6 -> V_72 . V_57 ) {
F_39 ( & V_2 -> V_2 , L_4 ,
V_12 , V_6 , & V_2 -> V_6 -> V_72 ) ;
return - V_36 ;
}
if ( F_40 ( V_2 , V_67 ) ) {
F_39 ( & V_2 -> V_2 , L_5 ) ;
return - V_36 ;
}
if ( V_14 -> V_73 != V_2 -> V_8 ) {
V_63 = F_41 ( V_2 -> V_6 , V_14 -> V_73 ) ;
if ( ! V_63 )
return - V_74 ;
if ( ! V_63 -> V_4 ) {
F_31 ( V_63 ) ;
return - V_75 ;
}
V_20 = F_28 ( & V_2 -> V_2 . V_58 ,
& V_63 -> V_2 . V_58 , L_6 ) ;
F_31 ( V_63 ) ;
if ( V_20 )
return V_20 ;
}
F_3 ( V_2 , V_12 ) ;
V_14 -> V_76 |= V_77 | V_78 ;
F_42 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_79 , V_14 -> V_76 ) ;
F_43 ( 100 ) ;
F_44 ( V_2 ) ;
V_14 -> V_80 = V_66 ;
if ( V_12 < V_66 )
V_66 = V_12 ;
V_20 = F_36 ( V_2 , V_66 ) ;
if ( V_20 ) {
F_39 ( & V_2 -> V_2 , L_7 , V_20 ) ;
goto V_81;
}
for ( V_35 = 0 ; V_35 < V_66 ; V_35 ++ ) {
V_20 = F_16 ( V_2 , V_35 , 0 ) ;
if ( V_20 )
goto V_44;
}
F_29 ( & V_2 -> V_2 . V_58 , V_61 ) ;
V_14 -> V_68 = V_12 ;
return 0 ;
V_44:
while ( V_35 -- )
F_33 ( V_2 , V_35 , 0 ) ;
F_37 ( V_2 ) ;
V_81:
V_14 -> V_76 &= ~ ( V_77 | V_78 ) ;
F_42 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_79 , V_14 -> V_76 ) ;
F_45 ( 1 ) ;
F_44 ( V_2 ) ;
if ( V_14 -> V_73 != V_2 -> V_8 )
F_30 ( & V_2 -> V_2 . V_58 , L_6 ) ;
F_3 ( V_2 , 0 ) ;
return V_20 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_35 ;
struct V_13 * V_14 = V_2 -> V_9 ;
if ( ! V_14 -> V_68 )
return;
for ( V_35 = 0 ; V_35 < V_14 -> V_68 ; V_35 ++ )
F_33 ( V_2 , V_35 , 0 ) ;
F_37 ( V_2 ) ;
V_14 -> V_76 &= ~ ( V_77 | V_78 ) ;
F_42 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_79 , V_14 -> V_76 ) ;
F_45 ( 1 ) ;
F_44 ( V_2 ) ;
if ( V_14 -> V_73 != V_2 -> V_8 )
F_30 ( & V_2 -> V_2 . V_58 , L_6 ) ;
V_14 -> V_68 = 0 ;
F_3 ( V_2 , 0 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_15 )
{
int V_35 , V_82 ;
int V_20 ;
int V_65 ;
T_4 V_83 ;
T_3 V_76 , V_84 ;
struct V_13 * V_14 ;
struct V_41 * V_42 ;
struct V_1 * V_63 ;
F_5 ( V_2 , V_15 + V_79 , & V_76 ) ;
if ( V_76 & V_77 ) {
F_4 ( V_2 , V_15 + V_79 , 0 ) ;
F_45 ( 1 ) ;
}
V_76 = 0 ;
F_48 (pdev, &dev->bus->devices, bus_list)
if ( V_63 -> V_4 )
goto V_85;
V_63 = NULL ;
if ( F_49 ( V_2 -> V_6 ) )
V_76 |= V_86 ;
V_85:
F_4 ( V_2 , V_15 + V_79 , V_76 ) ;
F_5 ( V_2 , V_15 + V_87 , & V_84 ) ;
if ( ! V_84 )
return 0 ;
F_50 ( V_2 , V_15 + V_88 , & V_83 ) ;
V_35 = V_89 > 12 ? V_89 - 12 : 0 ;
V_83 &= ~ ( ( 1 << V_35 ) - 1 ) ;
if ( ! V_83 )
return - V_22 ;
V_83 &= ~ ( V_83 - 1 ) ;
F_51 ( V_2 , V_15 + V_90 , V_83 ) ;
V_14 = F_52 ( sizeof( * V_14 ) , V_91 ) ;
if ( ! V_14 )
return - V_36 ;
V_65 = 0 ;
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
if ( V_42 -> V_55 & V_92 )
V_82 = ( V_42 -> V_55 & V_93 ) ? 1 : 0 ;
else
V_82 = F_53 ( V_2 , V_94 , V_42 ,
V_15 + V_95 + V_35 * 4 ) ;
if ( ! V_42 -> V_55 )
continue;
if ( F_54 ( V_42 ) & ( V_96 - 1 ) ) {
V_20 = - V_22 ;
goto V_44;
}
V_14 -> V_31 [ V_35 ] = F_54 ( V_42 ) ;
V_42 -> V_57 = V_42 -> V_56 + F_54 ( V_42 ) * V_84 - 1 ;
F_55 ( & V_2 -> V_2 , L_8 ,
V_35 , V_42 , V_35 , V_84 ) ;
V_35 += V_82 ;
V_65 ++ ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_65 = V_65 ;
V_14 -> V_76 = V_76 ;
V_14 -> V_21 = V_84 ;
V_14 -> V_83 = V_83 ;
V_14 -> V_97 = V_2 ;
F_50 ( V_2 , V_15 + V_98 , & V_14 -> V_70 ) ;
F_56 ( V_2 , V_15 + V_99 , & V_14 -> V_73 ) ;
if ( F_57 ( V_2 ) == V_100 )
V_14 -> V_73 = F_58 ( F_59 ( V_2 -> V_8 ) , V_14 -> V_73 ) ;
if ( V_63 )
V_14 -> V_2 = F_20 ( V_63 ) ;
else
V_14 -> V_2 = V_2 ;
F_60 ( & V_14 -> V_43 ) ;
V_2 -> V_9 = V_14 ;
V_2 -> V_4 = 1 ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 )
goto V_101;
return 0 ;
V_101:
V_2 -> V_9 = NULL ;
V_2 -> V_4 = 0 ;
V_44:
for ( V_35 = 0 ; V_35 < V_53 ; V_35 ++ ) {
V_42 = & V_2 -> V_41 [ V_35 + V_32 ] ;
V_42 -> V_55 = 0 ;
}
F_61 ( V_14 ) ;
return V_20 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_9 -> V_68 ) ;
if ( V_2 != V_2 -> V_9 -> V_2 )
F_31 ( V_2 -> V_9 -> V_2 ) ;
F_63 ( & V_2 -> V_9 -> V_43 ) ;
F_61 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_35 ;
T_3 V_76 ;
struct V_13 * V_14 = V_2 -> V_9 ;
F_5 ( V_2 , V_14 -> V_15 + V_79 , & V_76 ) ;
if ( V_76 & V_77 )
return;
for ( V_35 = V_32 ; V_35 <= V_102 ; V_35 ++ )
F_65 ( V_2 , V_35 ) ;
F_51 ( V_2 , V_14 -> V_15 + V_90 , V_14 -> V_83 ) ;
F_3 ( V_2 , V_14 -> V_68 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_79 , V_14 -> V_76 ) ;
if ( V_14 -> V_76 & V_77 )
F_43 ( 100 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_67 ( V_2 ) )
return - V_74 ;
V_15 = F_68 ( V_2 , V_103 ) ;
if ( V_15 )
return F_47 ( V_2 , V_15 ) ;
return - V_74 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_62 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 < V_32 || V_30 > V_102 )
return 0 ;
F_23 ( ! V_2 -> V_4 ) ;
return V_2 -> V_9 -> V_15 + V_95 +
4 * ( V_30 - V_32 ) ;
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
F_64 ( V_2 ) ;
}
int F_74 ( struct V_25 * V_6 )
{
int V_104 = 0 ;
struct V_1 * V_2 ;
F_48 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_4 )
continue;
if ( V_2 -> V_9 -> V_24 > V_104 )
V_104 = V_2 -> V_9 -> V_24 ;
}
return V_104 ? V_104 - V_6 -> V_7 : 0 ;
}
int F_75 ( struct V_1 * V_2 , int V_12 )
{
F_76 () ;
if ( ! V_2 -> V_4 )
return - V_75 ;
return F_38 ( V_2 , V_12 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_76 () ;
if ( ! V_2 -> V_4 )
return;
F_46 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> V_9 -> V_68 ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_1 * V_105 ;
unsigned int V_106 = 0 ;
unsigned short V_107 ;
if ( ! V_2 -> V_4 )
return 0 ;
F_5 ( V_2 , V_2 -> V_9 -> V_15 + V_47 , & V_107 ) ;
V_105 = F_80 ( V_2 -> V_46 , V_107 , NULL ) ;
while ( V_105 ) {
if ( V_105 -> V_51 && ( V_105 -> V_50 == V_2 ) &&
F_81 ( V_105 ) )
V_106 ++ ;
V_105 = F_80 ( V_2 -> V_46 , V_107 , V_105 ) ;
}
return V_106 ;
}
int F_82 ( struct V_1 * V_2 , T_3 V_108 )
{
if ( ! V_2 -> V_4 )
return - V_75 ;
if ( V_108 > V_2 -> V_9 -> V_21 )
return - V_5 ;
if ( V_2 -> V_9 -> V_76 & V_77 )
return - V_109 ;
else
V_2 -> V_9 -> V_110 = V_108 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_9 -> V_110 )
return V_2 -> V_9 -> V_110 ;
return V_2 -> V_9 -> V_21 ;
}
