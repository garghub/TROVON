static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_7 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_6 ( V_2 , struct V_8 , V_2 ) ;
F_7 ( & V_9 -> V_10 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
T_1 V_11 = F_2 ( V_2 -> V_4 + V_12 ) ;
return ( V_11 & V_13 ) ? V_14 : 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_2 ) ) {
T_2 V_15 = F_10 ( V_2 -> V_4 + V_16 ) |
V_17 ;
F_11 ( V_15 , V_2 -> V_4 + V_16 ) ;
F_3 ( V_18 , V_2 -> V_4 + V_12 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_21 -> V_2 ;
while ( F_2 ( V_2 -> V_4 + V_12 ) & V_22 ) {
T_2 V_23 = F_10 ( V_2 -> V_4 + V_24 ) ;
V_2 -> V_25 . V_26 ++ ;
F_13 ( V_20 , V_23 , V_27 ) ;
}
F_14 ( & V_2 -> V_28 ) ;
F_15 ( V_20 ) ;
F_16 ( & V_2 -> V_28 ) ;
F_17 ( V_2 -> V_29 , L_1 ,
V_30 , V_2 -> V_25 . V_26 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_21 -> V_32 ;
while ( ! ( F_2 ( V_2 -> V_4 + V_12 ) & V_18 ) &&
! F_19 ( V_32 ) ) {
F_11 ( V_32 -> V_33 [ V_32 -> V_34 ] ,
V_2 -> V_4 + V_35 ) ;
V_32 -> V_34 = ( V_32 -> V_34 + 1 ) & ( V_36 - 1 ) ;
V_2 -> V_25 . V_37 ++ ;
}
F_17 ( V_2 -> V_29 ,
L_2 ,
V_30 ,
V_2 -> V_25 . V_37 ,
F_10 ( V_2 -> V_4 + V_16 ) ,
V_2 -> V_38 & V_39 ,
F_10 ( V_2 -> V_4 + V_40 ) ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_11 , T_1 * V_3 )
{
struct V_8 * V_9 =
F_6 ( V_2 , struct V_8 , V_2 ) ;
struct V_31 * V_32 = & V_2 -> V_21 -> V_32 ;
if ( F_19 ( V_32 ) || F_21 ( V_2 ) )
return;
if ( V_2 -> V_41 )
return;
if ( V_11 & V_42 ) {
F_18 ( V_2 ) ;
F_3 ( V_42 , V_2 -> V_4 + V_12 ) ;
if ( F_22 ( V_32 ) < V_43 )
F_23 ( V_2 ) ;
} else
* V_3 |= V_9 -> V_44 & V_42 ;
if ( ! F_19 ( V_32 ) )
* V_3 |= V_7 ;
F_17 ( V_2 -> V_29 , L_3 , V_30 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_11 , T_1 * V_3 )
{
if ( V_11 & V_6 ) {
if ( V_11 & V_45 ) {
T_2 V_15 = F_10 ( V_2 -> V_4 + V_16 ) |
V_46 ;
F_11 ( V_15 , V_2 -> V_4 + V_16 ) ;
V_2 -> V_25 . V_47 ++ ;
} else if ( V_11 & ( V_22 ) )
F_12 ( V_2 ) ;
F_3 ( V_6 , V_2 -> V_4 + V_12 ) ;
}
* V_3 |= V_48 | V_45 | V_49 ;
F_17 ( V_2 -> V_29 , L_3 , V_30 ) ;
}
static void F_25 ( unsigned long V_50 )
{
struct V_8 * V_9 = (struct V_8 * ) V_50 ;
T_1 V_11 , V_3 = 0 ;
F_16 ( & V_9 -> V_2 . V_28 ) ;
V_11 = F_2 ( V_9 -> V_2 . V_4 + V_12 ) ;
F_17 ( V_9 -> V_2 . V_29 , L_4 , V_30 , V_11 ) ;
if ( ! V_9 -> V_51 )
F_20 ( & V_9 -> V_2 , V_11 , & V_3 ) ;
F_26 ( & V_9 -> V_2 , V_11 , & V_3 ) ;
if ( ! V_9 -> V_51 )
F_24 ( & V_9 -> V_2 , V_11 , & V_3 ) ;
F_3 ( V_3 , V_9 -> V_2 . V_4 + V_5 ) ;
F_14 ( & V_9 -> V_2 . V_28 ) ;
F_17 ( V_9 -> V_2 . V_29 , L_5 , V_30 ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
T_2 V_52 = F_10 ( V_2 -> V_4 + V_16 ) ;
F_17 ( V_2 -> V_29 , L_6 , V_30 , V_52 ) ;
if ( V_52 & V_53 )
return V_54 | V_55 | V_56 ;
else
return V_55 | V_56 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_38 )
{
F_17 ( V_2 -> V_29 , L_7 , V_30 , V_38 ) ;
if ( V_38 & V_39 )
F_11 ( V_57 , V_2 -> V_4 + V_16 ) ;
else
F_11 ( 0 , V_2 -> V_4 + V_16 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_11 , T_1 * V_3 )
{
unsigned int V_52 ;
if ( V_11 & V_58 ) {
F_3 ( V_58 , V_2 -> V_4 + V_12 ) ;
V_52 = F_27 ( V_2 ) ;
F_29 ( V_2 , V_52 & V_54 ) ;
F_30 ( & V_2 -> V_21 -> V_2 . V_59 ) ;
}
* V_3 |= V_58 ;
}
static void F_31 ( struct V_1 * V_2 , int V_15 )
{
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_6 ( V_2 , struct V_8 , V_2 ) ;
F_17 ( V_2 -> V_29 , L_8 , V_30 ) ;
F_11 ( V_46 , V_2 -> V_4 + V_16 ) ;
F_3 ( 0x1ff , V_2 -> V_4 + V_12 ) ;
F_3 ( V_48 | V_45 | V_49 | V_58 ,
V_2 -> V_4 + V_5 ) ;
return F_33 ( V_2 -> V_60 , V_61 , V_62 ,
L_9 , V_9 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_8 * V_9 =
F_6 ( V_2 , struct V_8 , V_2 ) ;
F_17 ( V_2 -> V_29 , L_8 , V_30 ) ;
F_35 ( V_2 -> V_60 , V_9 ) ;
F_3 ( 0 , V_2 -> V_4 + V_5 ) ;
}
static int F_36 ( int V_63 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < F_37 ( V_65 ) ; V_64 ++ )
if ( V_63 <= V_65 [ V_64 ] )
return V_64 ;
return - 1 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_66 * V_68 )
{
unsigned int V_63 ;
short V_69 ;
unsigned long V_70 ;
V_63 = F_39 ( V_2 , V_67 , V_68 , 0 , V_2 -> V_71 / 16 ) ;
V_69 = F_36 ( V_63 ) ;
F_17 ( V_2 -> V_29 , L_10 , V_30 , V_69 ) ;
if ( V_69 < 0 )
V_69 = 0 ;
V_63 = V_65 [ V_69 ] ;
if ( V_68 )
F_40 ( V_67 , V_68 ) ;
F_41 ( V_67 , V_63 , V_63 ) ;
F_42 ( & V_2 -> V_28 , V_70 ) ;
F_11 ( ( T_2 ) V_69 , V_2 -> V_4 + V_40 ) ;
F_43 ( V_2 , V_67 -> V_72 , V_63 ) ;
F_44 ( & V_2 -> V_28 , V_70 ) ;
}
static const char * F_45 ( struct V_1 * V_2 )
{
return V_2 -> type == V_73 ? L_11 : NULL ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_47 ( V_2 -> V_29 ) ;
int V_76 =
F_48 ( F_49 ( V_75 , V_77 , 0 ) ) ;
if ( V_2 -> V_70 & V_78 ) {
F_50 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
F_51 ( V_2 -> V_79 , V_76 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_47 ( V_2 -> V_29 ) ;
int V_76 =
F_48 ( F_49 ( V_75 , V_77 , 0 ) ) ;
if ( ! F_53 ( V_2 -> V_79 , V_76 , L_9 ) )
return - V_80 ;
if ( V_2 -> V_70 & V_78 ) {
V_2 -> V_4 = F_54 ( V_2 -> V_79 , V_76 ) ;
if ( V_2 -> V_4 == NULL ) {
F_51 ( V_2 -> V_79 , V_76 ) ;
return - V_81 ;
}
}
return 0 ;
}
static T_3 V_61 ( int V_60 , void * V_82 )
{
struct V_8 * V_9 = (struct V_8 * ) V_82 ;
if ( F_10 ( V_9 -> V_2 . V_4 + V_83 ) ) {
V_9 -> V_44 = F_2 ( V_9 -> V_2 . V_4 + V_5 ) ;
F_3 ( 0 , V_9 -> V_2 . V_4 + V_5 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_84 ;
} else
return V_85 ;
}
static void F_55 ( struct V_1 * V_2 , int V_70 )
{
if ( V_70 & V_86 ) {
V_2 -> type = V_87 ;
F_52 ( V_2 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
return - V_90 ;
}
static int F_57 ( struct V_74 * V_29 )
{
int V_91 , V_60 ;
struct V_8 * V_9 ;
struct V_92 * V_93 ;
F_17 ( & V_29 -> V_29 , L_8 , V_30 ) ;
V_9 = F_58 ( sizeof( * V_9 ) , V_94 ) ;
if ( ! V_9 ) {
V_91 = - V_90 ;
goto V_95;
}
V_9 -> V_51 = 0 ;
V_9 -> V_2 . V_71 = 3250000 * 16 ;
V_9 -> V_2 . V_96 = V_97 ;
V_9 -> V_2 . V_98 = 2 ;
V_9 -> V_2 . V_99 = V_100 ;
V_9 -> V_2 . V_101 = & V_102 ;
V_9 -> V_2 . V_60 = 0 ;
V_9 -> V_2 . V_70 = V_103 | V_78 ;
V_9 -> V_2 . line = 0 ;
V_9 -> V_2 . V_29 = & V_29 -> V_29 ;
V_93 = F_49 ( V_29 , V_77 , 0 ) ;
if ( ! V_93 ) {
V_91 = - V_81 ;
goto V_104;
}
V_9 -> V_2 . V_79 = V_93 -> V_105 ;
V_9 -> V_2 . V_4 = NULL ;
V_60 = F_59 ( V_29 , 0 ) ;
if ( V_60 < 0 ) {
V_91 = - V_90 ;
goto V_104;
}
V_9 -> V_2 . V_60 = V_60 ;
F_60 ( & V_9 -> V_10 , F_25 , ( unsigned long ) V_9 ) ;
V_91 = F_61 ( & V_106 ) ;
if ( V_91 )
goto V_104;
V_91 = F_62 ( & V_106 , & V_9 -> V_2 ) ;
if ( V_91 )
goto V_107;
F_63 ( V_29 , V_9 ) ;
return 0 ;
V_107:
F_64 ( & V_106 ) ;
V_104:
F_65 ( V_9 ) ;
V_95:
F_66 ( V_108 L_12 ,
V_91 ) ;
return V_91 ;
}
static int F_67 ( struct V_74 * V_29 )
{
struct V_8 * V_9 = F_68 ( V_29 ) ;
F_69 ( & V_9 -> V_10 ) ;
F_70 ( & V_106 , & V_9 -> V_2 ) ;
F_64 ( & V_106 ) ;
F_65 ( V_9 ) ;
return 0 ;
}
