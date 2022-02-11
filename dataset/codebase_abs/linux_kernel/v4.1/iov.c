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
static inline T_1 F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
int V_12 ;
T_1 V_19 = 0 ;
int V_20 ;
for ( V_12 = 1 ; V_12 <= V_14 -> V_21 ; V_12 ++ ) {
F_3 ( V_2 , V_12 ) ;
V_20 = F_1 ( V_2 , V_12 - 1 ) ;
if ( V_20 > V_19 )
V_19 = V_20 ;
}
return V_19 ;
}
static struct V_22 * F_7 ( struct V_22 * V_6 , int V_20 )
{
struct V_22 * V_23 ;
if ( V_6 -> V_7 == V_20 )
return V_6 ;
V_23 = F_8 ( F_9 ( V_6 ) , V_20 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_10 ( V_6 , NULL , V_20 ) ;
if ( ! V_23 )
return NULL ;
F_11 ( V_23 , V_20 , V_20 ) ;
return V_23 ;
}
static void F_12 ( struct V_22 * V_24 , struct V_22 * V_25 )
{
if ( V_24 != V_25 && F_13 ( & V_25 -> V_26 ) )
F_14 ( V_25 ) ;
}
T_2 F_15 ( struct V_1 * V_2 , int V_27 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return V_2 -> V_9 -> V_28 [ V_27 - V_29 ] ;
}
static int F_16 ( struct V_1 * V_2 , int V_30 , int V_31 )
{
int V_32 ;
int V_33 = - V_34 ;
T_3 V_35 ;
char V_36 [ V_37 ] ;
struct V_1 * V_38 ;
struct V_39 * V_40 ;
struct V_13 * V_14 = V_2 -> V_9 ;
struct V_22 * V_6 ;
F_17 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
V_6 = F_7 ( V_2 -> V_6 , F_1 ( V_2 , V_30 ) ) ;
if ( ! V_6 )
goto V_42;
V_38 = F_18 ( V_6 ) ;
if ( ! V_38 )
goto V_43;
V_38 -> V_8 = F_2 ( V_2 , V_30 ) ;
V_38 -> V_44 = V_2 -> V_44 ;
F_5 ( V_2 , V_14 -> V_15 + V_45 , & V_38 -> V_46 ) ;
F_19 ( V_38 ) ;
V_38 -> V_2 . V_47 = V_2 -> V_2 . V_47 ;
V_38 -> V_48 = F_20 ( V_2 ) ;
V_38 -> V_49 = 1 ;
V_38 -> V_50 = 0 ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_40 = & V_2 -> V_39 [ V_32 + V_29 ] ;
if ( ! V_40 -> V_47 )
continue;
V_38 -> V_39 [ V_32 ] . V_52 = F_21 ( V_38 ) ;
V_38 -> V_39 [ V_32 ] . V_53 = V_40 -> V_53 ;
V_35 = F_15 ( V_2 , V_32 + V_29 ) ;
V_38 -> V_39 [ V_32 ] . V_54 = V_40 -> V_54 + V_35 * V_30 ;
V_38 -> V_39 [ V_32 ] . V_55 = V_38 -> V_39 [ V_32 ] . V_54 + V_35 - 1 ;
V_33 = F_22 ( V_40 , & V_38 -> V_39 [ V_32 ] ) ;
F_23 ( V_33 ) ;
}
if ( V_31 )
F_24 ( V_38 ) ;
F_25 ( V_38 , V_38 -> V_6 ) ;
F_26 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
F_27 ( V_38 ) ;
sprintf ( V_36 , L_1 , V_30 ) ;
V_33 = F_28 ( & V_2 -> V_2 . V_56 , & V_38 -> V_2 . V_56 , V_36 ) ;
if ( V_33 )
goto V_57;
V_33 = F_28 ( & V_38 -> V_2 . V_56 , & V_2 -> V_2 . V_56 , L_2 ) ;
if ( V_33 )
goto V_58;
F_29 ( & V_38 -> V_2 . V_56 , V_59 ) ;
return 0 ;
V_58:
F_30 ( & V_2 -> V_2 . V_56 , V_36 ) ;
V_57:
F_31 ( V_2 ) ;
F_17 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
F_32 ( V_38 ) ;
V_43:
F_12 ( V_2 -> V_6 , V_6 ) ;
V_42:
F_26 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
return V_33 ;
}
static void F_33 ( struct V_1 * V_2 , int V_30 , int V_31 )
{
char V_36 [ V_37 ] ;
struct V_1 * V_38 ;
struct V_13 * V_14 = V_2 -> V_9 ;
V_38 = F_34 ( F_9 ( V_2 -> V_6 ) ,
F_1 ( V_2 , V_30 ) ,
F_2 ( V_2 , V_30 ) ) ;
if ( ! V_38 )
return;
if ( V_31 ) {
F_35 ( & V_38 -> V_2 ) ;
F_24 ( V_38 ) ;
}
sprintf ( V_36 , L_1 , V_30 ) ;
F_30 ( & V_2 -> V_2 . V_56 , V_36 ) ;
if ( V_38 -> V_2 . V_56 . V_60 )
F_30 ( & V_38 -> V_2 . V_56 , L_2 ) ;
F_17 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
F_32 ( V_38 ) ;
F_12 ( V_2 -> V_6 , V_38 -> V_6 ) ;
F_26 ( & V_14 -> V_2 -> V_9 -> V_41 ) ;
F_31 ( V_38 ) ;
F_31 ( V_2 ) ;
}
int __weak F_36 ( struct V_1 * V_61 , T_4 V_62 )
{
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_12 )
{
int V_33 ;
int V_32 , V_63 ;
int V_64 ;
T_4 V_10 , V_11 , V_65 ;
struct V_39 * V_40 ;
struct V_1 * V_61 ;
struct V_13 * V_14 = V_2 -> V_9 ;
int V_66 = 0 ;
int V_6 ;
int V_67 ;
if ( ! V_12 )
return 0 ;
if ( V_14 -> V_68 )
return - V_5 ;
F_5 ( V_2 , V_14 -> V_15 + V_69 , & V_65 ) ;
if ( V_65 > V_14 -> V_21 ||
( ! ( V_14 -> V_70 & V_71 ) && ( V_65 != V_14 -> V_21 ) ) )
return - V_72 ;
if ( V_12 < 0 || V_12 > V_14 -> V_21 ||
( ! ( V_14 -> V_70 & V_71 ) && ( V_12 > V_65 ) ) )
return - V_5 ;
F_5 ( V_2 , V_14 -> V_15 + V_17 , & V_10 ) ;
F_5 ( V_2 , V_14 -> V_15 + V_18 , & V_11 ) ;
if ( ! V_10 || ( V_12 > 1 && ! V_11 ) )
return - V_72 ;
V_64 = 0 ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_66 |= ( 1 << ( V_32 + V_29 ) ) ;
V_40 = & V_2 -> V_39 [ V_32 + V_29 ] ;
if ( V_40 -> V_47 )
V_64 ++ ;
}
if ( V_64 != V_14 -> V_64 ) {
F_38 ( & V_2 -> V_2 , L_3 ) ;
return - V_34 ;
}
V_14 -> V_10 = V_10 ;
V_14 -> V_11 = V_11 ;
V_6 = F_1 ( V_2 , V_12 - 1 ) ;
if ( V_6 > V_2 -> V_6 -> V_73 . V_55 ) {
F_38 ( & V_2 -> V_2 , L_4 ,
V_12 , V_6 , & V_2 -> V_6 -> V_73 ) ;
return - V_34 ;
}
if ( F_39 ( V_2 , V_66 ) ) {
F_38 ( & V_2 -> V_2 , L_5 ) ;
return - V_34 ;
}
if ( V_14 -> V_74 != V_2 -> V_8 ) {
V_61 = F_40 ( V_2 -> V_6 , V_14 -> V_74 ) ;
if ( ! V_61 )
return - V_75 ;
if ( ! V_61 -> V_4 ) {
F_31 ( V_61 ) ;
return - V_76 ;
}
V_33 = F_28 ( & V_2 -> V_2 . V_56 ,
& V_61 -> V_2 . V_56 , L_6 ) ;
F_31 ( V_61 ) ;
if ( V_33 )
return V_33 ;
}
F_3 ( V_2 , V_12 ) ;
V_14 -> V_77 |= V_78 | V_79 ;
F_41 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_42 ( 100 ) ;
F_43 ( V_2 ) ;
V_14 -> V_81 = V_65 ;
if ( V_12 < V_65 )
V_65 = V_12 ;
if ( ( V_67 = F_36 ( V_2 , V_65 ) ) ) {
F_38 ( & V_2 -> V_2 , L_7 ,
V_67 ) ;
return V_67 ;
}
for ( V_32 = 0 ; V_32 < V_65 ; V_32 ++ ) {
V_33 = F_16 ( V_2 , V_32 , 0 ) ;
if ( V_33 )
goto V_42;
}
F_29 ( & V_2 -> V_2 . V_56 , V_59 ) ;
V_14 -> V_68 = V_12 ;
return 0 ;
V_42:
for ( V_63 = 0 ; V_63 < V_32 ; V_63 ++ )
F_33 ( V_2 , V_63 , 0 ) ;
V_14 -> V_77 &= ~ ( V_78 | V_79 ) ;
F_41 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_3 ( V_2 , 0 ) ;
F_44 ( 1 ) ;
F_43 ( V_2 ) ;
if ( V_14 -> V_74 != V_2 -> V_8 )
F_30 ( & V_2 -> V_2 . V_56 , L_6 ) ;
return V_33 ;
}
int __weak F_45 ( struct V_1 * V_61 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_13 * V_14 = V_2 -> V_9 ;
if ( ! V_14 -> V_68 )
return;
for ( V_32 = 0 ; V_32 < V_14 -> V_68 ; V_32 ++ )
F_33 ( V_2 , V_32 , 0 ) ;
F_45 ( V_2 ) ;
V_14 -> V_77 &= ~ ( V_78 | V_79 ) ;
F_41 ( V_2 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
F_44 ( 1 ) ;
F_43 ( V_2 ) ;
if ( V_14 -> V_74 != V_2 -> V_8 )
F_30 ( & V_2 -> V_2 . V_56 , L_6 ) ;
V_14 -> V_68 = 0 ;
F_3 ( V_2 , 0 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_15 )
{
int V_32 , V_82 ;
int V_33 ;
int V_64 ;
T_5 V_83 ;
T_4 V_77 , V_84 , V_10 , V_11 ;
struct V_13 * V_14 ;
struct V_39 * V_40 ;
struct V_1 * V_61 ;
if ( F_48 ( V_2 ) != V_85 &&
F_48 ( V_2 ) != V_86 )
return - V_75 ;
F_5 ( V_2 , V_15 + V_80 , & V_77 ) ;
if ( V_77 & V_78 ) {
F_4 ( V_2 , V_15 + V_80 , 0 ) ;
F_44 ( 1 ) ;
}
F_5 ( V_2 , V_15 + V_87 , & V_84 ) ;
if ( ! V_84 )
return 0 ;
V_77 = 0 ;
F_49 (pdev, &dev->bus->devices, bus_list)
if ( V_61 -> V_4 )
goto V_88;
V_61 = NULL ;
if ( F_50 ( V_2 -> V_6 ) )
V_77 |= V_89 ;
V_88:
F_4 ( V_2 , V_15 + V_80 , V_77 ) ;
F_4 ( V_2 , V_15 + V_16 , 0 ) ;
F_5 ( V_2 , V_15 + V_17 , & V_10 ) ;
F_5 ( V_2 , V_15 + V_18 , & V_11 ) ;
if ( ! V_10 || ( V_84 > 1 && ! V_11 ) )
return - V_72 ;
F_51 ( V_2 , V_15 + V_90 , & V_83 ) ;
V_32 = V_91 > 12 ? V_91 - 12 : 0 ;
V_83 &= ~ ( ( 1 << V_32 ) - 1 ) ;
if ( ! V_83 )
return - V_72 ;
V_83 &= ~ ( V_83 - 1 ) ;
F_52 ( V_2 , V_15 + V_92 , V_83 ) ;
V_14 = F_53 ( sizeof( * V_14 ) , V_93 ) ;
if ( ! V_14 )
return - V_34 ;
V_64 = 0 ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_40 = & V_2 -> V_39 [ V_32 + V_29 ] ;
V_82 = F_54 ( V_2 , V_94 , V_40 ,
V_15 + V_95 + V_32 * 4 ) ;
if ( ! V_40 -> V_53 )
continue;
if ( F_55 ( V_40 ) & ( V_96 - 1 ) ) {
V_33 = - V_72 ;
goto V_42;
}
V_14 -> V_28 [ V_32 ] = F_55 ( V_40 ) ;
V_40 -> V_55 = V_40 -> V_54 + F_55 ( V_40 ) * V_84 - 1 ;
F_56 ( & V_2 -> V_2 , L_8 ,
V_32 , V_40 , V_32 , V_84 ) ;
V_32 += V_82 ;
V_64 ++ ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_64 = V_64 ;
V_14 -> V_77 = V_77 ;
V_14 -> V_21 = V_84 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 = V_11 ;
V_14 -> V_83 = V_83 ;
V_14 -> V_97 = V_2 ;
F_51 ( V_2 , V_15 + V_98 , & V_14 -> V_70 ) ;
F_57 ( V_2 , V_15 + V_99 , & V_14 -> V_74 ) ;
if ( F_48 ( V_2 ) == V_85 )
V_14 -> V_74 = F_58 ( F_59 ( V_2 -> V_8 ) , V_14 -> V_74 ) ;
if ( V_61 )
V_14 -> V_2 = F_20 ( V_61 ) ;
else
V_14 -> V_2 = V_2 ;
F_60 ( & V_14 -> V_41 ) ;
V_2 -> V_9 = V_14 ;
V_2 -> V_4 = 1 ;
V_14 -> V_100 = F_6 ( V_2 ) ;
return 0 ;
V_42:
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_40 = & V_2 -> V_39 [ V_32 + V_29 ] ;
V_40 -> V_53 = 0 ;
}
F_61 ( V_14 ) ;
return V_33 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_9 -> V_68 ) ;
if ( V_2 != V_2 -> V_9 -> V_2 )
F_31 ( V_2 -> V_9 -> V_2 ) ;
F_63 ( & V_2 -> V_9 -> V_41 ) ;
F_61 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_32 ;
T_4 V_77 ;
struct V_13 * V_14 = V_2 -> V_9 ;
F_5 ( V_2 , V_14 -> V_15 + V_80 , & V_77 ) ;
if ( V_77 & V_78 )
return;
for ( V_32 = V_29 ; V_32 <= V_101 ; V_32 ++ )
F_65 ( V_2 , V_32 ) ;
F_52 ( V_2 , V_14 -> V_15 + V_92 , V_14 -> V_83 ) ;
F_3 ( V_2 , V_14 -> V_68 ) ;
F_4 ( V_2 , V_14 -> V_15 + V_80 , V_14 -> V_77 ) ;
if ( V_14 -> V_77 & V_78 )
F_42 ( 100 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_67 ( V_2 ) )
return - V_75 ;
V_15 = F_68 ( V_2 , V_102 ) ;
if ( V_15 )
return F_47 ( V_2 , V_15 ) ;
return - V_75 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_62 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_2 , int V_27 )
{
if ( V_27 < V_29 || V_27 > V_101 )
return 0 ;
F_23 ( ! V_2 -> V_4 ) ;
return V_2 -> V_9 -> V_15 + V_95 +
4 * ( V_27 - V_29 ) ;
}
T_2 __weak F_71 ( struct V_1 * V_2 ,
int V_27 )
{
return F_15 ( V_2 , V_27 ) ;
}
T_2 F_72 ( struct V_1 * V_2 , int V_27 )
{
return F_71 ( V_2 , V_27 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_64 ( V_2 ) ;
}
int F_74 ( struct V_22 * V_6 )
{
int V_19 = 0 ;
struct V_1 * V_2 ;
F_49 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_4 )
continue;
if ( V_2 -> V_9 -> V_100 > V_19 )
V_19 = V_2 -> V_9 -> V_100 ;
}
return V_19 ? V_19 - V_6 -> V_7 : 0 ;
}
int F_75 ( struct V_1 * V_2 , int V_12 )
{
F_76 () ;
if ( ! V_2 -> V_4 )
return - V_76 ;
return F_37 ( V_2 , V_12 ) ;
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
struct V_1 * V_103 ;
unsigned int V_104 = 0 ;
unsigned short V_105 ;
if ( ! V_2 -> V_4 )
return 0 ;
F_5 ( V_2 , V_2 -> V_9 -> V_15 + V_45 , & V_105 ) ;
V_103 = F_80 ( V_2 -> V_44 , V_105 , NULL ) ;
while ( V_103 ) {
if ( V_103 -> V_49 && ( V_103 -> V_48 == V_2 ) &&
F_81 ( V_103 ) )
V_104 ++ ;
V_103 = F_80 ( V_2 -> V_44 , V_105 , V_103 ) ;
}
return V_104 ;
}
int F_82 ( struct V_1 * V_2 , T_4 V_106 )
{
if ( ! V_2 -> V_4 )
return - V_76 ;
if ( V_106 > V_2 -> V_9 -> V_21 )
return - V_5 ;
if ( V_2 -> V_9 -> V_77 & V_78 )
return - V_107 ;
else
V_2 -> V_9 -> V_108 = V_106 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_9 -> V_108 )
return V_2 -> V_9 -> V_108 ;
return V_2 -> V_9 -> V_21 ;
}
