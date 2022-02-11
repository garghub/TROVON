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
F_25 ( V_23 ) ;
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
static int F_34 ( struct V_1 * V_2 , int V_51 )
{
int V_18 ;
int V_17 , V_52 ;
int V_53 ;
T_3 V_8 , V_9 , V_54 ;
struct V_24 * V_25 ;
struct V_1 * V_55 ;
struct V_26 * V_27 = V_2 -> V_7 ;
int V_56 = 0 ;
if ( ! V_51 )
return 0 ;
if ( V_27 -> V_57 )
return - V_58 ;
F_14 ( V_2 , V_27 -> V_32 + V_59 , & V_54 ) ;
if ( V_54 > V_27 -> V_43 ||
( ! ( V_27 -> V_60 & V_61 ) && ( V_54 != V_27 -> V_43 ) ) )
return - V_62 ;
if ( V_51 < 0 || V_51 > V_27 -> V_43 ||
( ! ( V_27 -> V_60 & V_61 ) && ( V_51 > V_54 ) ) )
return - V_58 ;
F_14 ( V_2 , V_27 -> V_32 + V_63 , & V_8 ) ;
F_14 ( V_2 , V_27 -> V_32 + V_64 , & V_9 ) ;
if ( ! V_8 || ( V_51 > 1 && ! V_9 ) )
return - V_62 ;
V_53 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_56 |= ( 1 << ( V_17 + V_40 ) ) ;
V_25 = V_2 -> V_24 + V_40 + V_17 ;
if ( V_25 -> V_35 )
V_53 ++ ;
}
if ( V_53 != V_27 -> V_53 ) {
F_35 ( & V_2 -> V_2 , L_3 ) ;
return - V_19 ;
}
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
if ( F_1 ( V_2 , V_51 - 1 ) > V_2 -> V_4 -> V_65 . V_45 ) {
F_35 ( & V_2 -> V_2 , L_4 ) ;
return - V_19 ;
}
if ( F_36 ( V_2 , V_56 ) ) {
F_35 ( & V_2 -> V_2 , L_5 ) ;
return - V_19 ;
}
if ( V_27 -> V_66 != V_2 -> V_6 ) {
V_55 = F_37 ( V_2 -> V_4 , V_27 -> V_66 ) ;
if ( ! V_55 )
return - V_67 ;
if ( ! V_55 -> V_68 ) {
F_29 ( V_55 ) ;
return - V_69 ;
}
V_18 = F_26 ( & V_2 -> V_2 . V_46 ,
& V_55 -> V_2 . V_46 , L_6 ) ;
F_29 ( V_55 ) ;
if ( V_18 )
return V_18 ;
}
F_38 ( V_2 , V_27 -> V_32 + V_70 , V_51 ) ;
V_27 -> V_71 |= V_72 | V_73 ;
F_39 ( V_2 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_74 , V_27 -> V_71 ) ;
F_40 ( 100 ) ;
F_41 ( V_2 ) ;
V_27 -> V_75 = V_54 ;
if ( V_51 < V_54 )
V_54 = V_51 ;
for ( V_17 = 0 ; V_17 < V_54 ; V_17 ++ ) {
V_18 = F_11 ( V_2 , V_17 , 0 ) ;
if ( V_18 )
goto V_29;
}
F_27 ( & V_2 -> V_2 . V_46 , V_49 ) ;
V_27 -> V_57 = V_51 ;
return 0 ;
V_29:
for ( V_52 = 0 ; V_52 < V_17 ; V_52 ++ )
F_31 ( V_2 , V_52 , 0 ) ;
V_27 -> V_71 &= ~ ( V_72 | V_73 ) ;
F_39 ( V_2 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_74 , V_27 -> V_71 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_70 , 0 ) ;
F_42 ( 1 ) ;
F_41 ( V_2 ) ;
if ( V_27 -> V_66 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_46 , L_6 ) ;
return V_18 ;
}
static void F_43 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_26 * V_27 = V_2 -> V_7 ;
if ( ! V_27 -> V_57 )
return;
for ( V_17 = 0 ; V_17 < V_27 -> V_57 ; V_17 ++ )
F_31 ( V_2 , V_17 , 0 ) ;
V_27 -> V_71 &= ~ ( V_72 | V_73 ) ;
F_39 ( V_2 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_74 , V_27 -> V_71 ) ;
F_42 ( 1 ) ;
F_41 ( V_2 ) ;
if ( V_27 -> V_66 != V_2 -> V_6 )
F_28 ( & V_2 -> V_2 . V_46 , L_6 ) ;
V_27 -> V_57 = 0 ;
F_38 ( V_2 , V_27 -> V_32 + V_70 , 0 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_32 )
{
int V_17 ;
int V_18 ;
int V_53 ;
T_4 V_76 ;
T_3 V_71 , V_77 , V_8 , V_9 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
struct V_1 * V_55 ;
if ( F_45 ( V_2 ) != V_78 &&
F_45 ( V_2 ) != V_79 )
return - V_67 ;
F_14 ( V_2 , V_32 + V_74 , & V_71 ) ;
if ( V_71 & V_72 ) {
F_38 ( V_2 , V_32 + V_74 , 0 ) ;
F_42 ( 1 ) ;
}
F_14 ( V_2 , V_32 + V_80 , & V_77 ) ;
if ( ! V_77 )
return 0 ;
V_71 = 0 ;
F_46 (pdev, &dev->bus->devices, bus_list)
if ( V_55 -> V_68 )
goto V_81;
V_55 = NULL ;
if ( F_47 ( V_2 -> V_4 ) )
V_71 |= V_82 ;
V_81:
F_38 ( V_2 , V_32 + V_74 , V_71 ) ;
F_38 ( V_2 , V_32 + V_70 , 0 ) ;
F_14 ( V_2 , V_32 + V_63 , & V_8 ) ;
F_14 ( V_2 , V_32 + V_64 , & V_9 ) ;
if ( ! V_8 || ( V_77 > 1 && ! V_9 ) )
return - V_62 ;
F_48 ( V_2 , V_32 + V_83 , & V_76 ) ;
V_17 = V_84 > 12 ? V_84 - 12 : 0 ;
V_76 &= ~ ( ( 1 << V_17 ) - 1 ) ;
if ( ! V_76 )
return - V_62 ;
V_76 &= ~ ( V_76 - 1 ) ;
F_49 ( V_2 , V_32 + V_85 , V_76 ) ;
V_53 = 0 ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_40 + V_17 ;
V_17 += F_50 ( V_2 , V_86 , V_25 ,
V_32 + V_87 + V_17 * 4 ) ;
if ( ! V_25 -> V_42 )
continue;
if ( F_18 ( V_25 ) & ( V_88 - 1 ) ) {
V_18 = - V_62 ;
goto V_29;
}
V_25 -> V_45 = V_25 -> V_44 + F_18 ( V_25 ) * V_77 - 1 ;
V_53 ++ ;
}
V_27 = F_51 ( sizeof( * V_27 ) , V_89 ) ;
if ( ! V_27 ) {
V_18 = - V_19 ;
goto V_29;
}
V_27 -> V_32 = V_32 ;
V_27 -> V_53 = V_53 ;
V_27 -> V_71 = V_71 ;
V_27 -> V_43 = V_77 ;
V_27 -> V_8 = V_8 ;
V_27 -> V_9 = V_9 ;
V_27 -> V_76 = V_76 ;
V_27 -> V_90 = V_2 ;
F_48 ( V_2 , V_32 + V_91 , & V_27 -> V_60 ) ;
F_52 ( V_2 , V_32 + V_92 , & V_27 -> V_66 ) ;
if ( F_45 ( V_2 ) == V_78 )
V_27 -> V_66 = F_53 ( F_54 ( V_2 -> V_6 ) , V_27 -> V_66 ) ;
if ( V_55 )
V_27 -> V_2 = F_16 ( V_55 ) ;
else
V_27 -> V_2 = V_2 ;
F_55 ( & V_27 -> V_28 ) ;
V_2 -> V_7 = V_27 ;
V_2 -> V_68 = 1 ;
return 0 ;
V_29:
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
V_25 = V_2 -> V_24 + V_40 + V_17 ;
V_25 -> V_42 = 0 ;
}
return V_18 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_7 -> V_57 ) ;
if ( V_2 != V_2 -> V_7 -> V_2 )
F_29 ( V_2 -> V_7 -> V_2 ) ;
F_57 ( & V_2 -> V_7 -> V_28 ) ;
F_58 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_17 ;
T_3 V_71 ;
struct V_26 * V_27 = V_2 -> V_7 ;
F_14 ( V_2 , V_27 -> V_32 + V_74 , & V_71 ) ;
if ( V_71 & V_72 )
return;
for ( V_17 = V_40 ; V_17 <= V_93 ; V_17 ++ )
F_60 ( V_2 , V_17 ) ;
F_49 ( V_2 , V_27 -> V_32 + V_85 , V_27 -> V_76 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_70 , V_27 -> V_57 ) ;
F_38 ( V_2 , V_27 -> V_32 + V_74 , V_27 -> V_71 ) ;
if ( V_27 -> V_71 & V_72 )
F_40 ( 100 ) ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_62 ( V_2 ) )
return - V_67 ;
V_32 = F_63 ( V_2 , V_94 ) ;
if ( V_32 )
return F_44 ( V_2 , V_32 ) ;
return - V_67 ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 )
F_56 ( V_2 ) ;
}
int F_65 ( struct V_1 * V_2 , int V_95 ,
enum V_96 * type )
{
if ( V_95 < V_40 || V_95 > V_93 )
return 0 ;
F_21 ( ! V_2 -> V_68 ) ;
* type = V_86 ;
return V_2 -> V_7 -> V_32 + V_87 +
4 * ( V_95 - V_40 ) ;
}
T_5 F_66 ( struct V_1 * V_2 , int V_95 )
{
struct V_24 V_97 ;
enum V_96 type ;
int V_98 = F_65 ( V_2 , V_95 , & type ) ;
if ( ! V_98 )
return 0 ;
F_50 ( V_2 , type , & V_97 , V_98 ) ;
return F_67 ( & V_97 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 )
F_59 ( V_2 ) ;
}
int F_69 ( struct V_10 * V_4 )
{
int V_99 = 0 ;
T_1 V_11 ;
struct V_1 * V_2 ;
F_46 (dev, &bus->devices, bus_list) {
if ( ! V_2 -> V_68 )
continue;
V_11 = F_1 ( V_2 , V_2 -> V_7 -> V_43 - 1 ) ;
if ( V_11 > V_99 )
V_99 = V_11 ;
}
return V_99 ? V_99 - V_4 -> V_5 : 0 ;
}
int F_70 ( struct V_1 * V_2 , int V_51 )
{
F_71 () ;
if ( ! V_2 -> V_68 )
return - V_69 ;
return F_34 ( V_2 , V_51 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
F_71 () ;
if ( ! V_2 -> V_68 )
return;
F_43 ( V_2 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 )
return 0 ;
return V_2 -> V_7 -> V_57 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_1 * V_100 ;
unsigned int V_101 = 0 ;
unsigned short V_102 ;
if ( ! V_2 -> V_68 )
return 0 ;
F_14 ( V_2 , V_2 -> V_7 -> V_32 + V_33 , & V_102 ) ;
V_100 = F_75 ( V_2 -> V_31 , V_102 , NULL ) ;
while ( V_100 ) {
if ( V_100 -> V_37 && ( V_100 -> V_36 == V_2 ) &&
( V_100 -> V_103 & V_104 ) )
V_101 ++ ;
V_100 = F_75 ( V_2 -> V_31 , V_102 , V_100 ) ;
}
return V_101 ;
}
int F_76 ( struct V_1 * V_2 , T_3 V_105 )
{
if ( ! V_2 -> V_68 )
return - V_69 ;
if ( V_105 > V_2 -> V_7 -> V_43 )
return - V_58 ;
if ( V_2 -> V_7 -> V_71 & V_72 )
return - V_106 ;
else
V_2 -> V_7 -> V_107 = V_105 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 )
return 0 ;
if ( V_2 -> V_7 -> V_107 )
return V_2 -> V_7 -> V_107 ;
return V_2 -> V_7 -> V_43 ;
}
