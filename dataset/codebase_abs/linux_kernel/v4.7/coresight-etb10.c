static unsigned int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
F_2 ( V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_4 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_3 ;
F_6 ( V_2 -> V_5 ) ;
V_3 = V_2 -> V_8 ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ )
F_7 ( 0x0 , V_2 -> V_5 + V_10 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
F_7 ( V_2 -> V_12 , V_2 -> V_5 + V_13 ) ;
F_7 ( V_14 | V_15 ,
V_2 -> V_5 + V_16 ) ;
F_7 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_8 ( V_2 -> V_5 ) ;
}
static int F_9 ( struct V_19 * V_20 , T_1 V_21 )
{
T_1 V_22 ;
unsigned long V_23 ;
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_24 ) ;
V_22 = F_11 ( & V_2 -> V_21 ,
V_25 , V_21 ) ;
if ( V_22 == V_26 )
return - V_27 ;
if ( V_22 == V_28 )
goto V_29;
F_12 ( & V_2 -> V_30 , V_23 ) ;
F_5 ( V_2 ) ;
F_13 ( & V_2 -> V_30 , V_23 ) ;
V_29:
F_14 ( V_2 -> V_4 , L_1 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_31 ;
F_6 ( V_2 -> V_5 ) ;
V_31 = F_3 ( V_2 -> V_5 + V_16 ) ;
V_31 |= V_32 ;
F_7 ( V_31 , V_2 -> V_5 + V_16 ) ;
V_31 |= V_33 ;
F_7 ( V_31 , V_2 -> V_5 + V_16 ) ;
if ( F_16 ( V_2 -> V_5 , V_16 , V_34 , 0 ) ) {
F_17 ( V_2 -> V_4 ,
L_2 ,
V_16 ) ;
}
F_7 ( 0x0 , V_2 -> V_5 + V_18 ) ;
if ( F_16 ( V_2 -> V_5 , V_35 , V_36 , 1 ) ) {
F_17 ( V_2 -> V_4 ,
L_2 ,
V_16 ) ;
}
F_8 ( V_2 -> V_5 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_7 ;
T_2 * V_37 ;
T_1 V_38 , V_3 ;
T_1 V_39 , V_40 ;
T_1 V_41 , V_42 ;
F_6 ( V_2 -> V_5 ) ;
V_39 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_40 = F_3 ( V_2 -> V_5 + V_9 ) ;
V_41 = V_40 % V_43 ;
V_42 = V_43 - V_41 ;
if ( V_41 ) {
F_17 ( V_2 -> V_4 ,
L_3 ,
( unsigned long ) V_40 ) ;
F_17 ( V_2 -> V_4 , L_4 ,
( unsigned long ) V_41 , ( unsigned long ) V_42 ) ;
V_40 += V_42 ;
}
if ( ( F_3 ( V_2 -> V_5 + V_44 )
& V_45 ) == 0 )
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
else
F_7 ( V_40 , V_2 -> V_5 + V_11 ) ;
V_3 = V_2 -> V_8 ;
V_37 = V_2 -> V_46 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_38 = F_3 ( V_2 -> V_5 +
V_47 ) ;
* V_37 ++ = V_38 >> 0 ;
* V_37 ++ = V_38 >> 8 ;
* V_37 ++ = V_38 >> 16 ;
* V_37 ++ = V_38 >> 24 ;
}
if ( V_41 ) {
V_37 -= ( V_42 * 4 ) ;
for ( V_7 = 0 ; V_7 < V_42 ; V_7 ++ ) {
* V_37 ++ = 0x0 ;
* V_37 ++ = 0x0 ;
* V_37 ++ = 0x0 ;
* V_37 ++ = 0x0 ;
}
}
F_7 ( V_39 , V_2 -> V_5 + V_11 ) ;
F_8 ( V_2 -> V_5 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_24 ) ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_30 , V_23 ) ;
F_15 ( V_2 ) ;
F_18 ( V_2 ) ;
F_13 ( & V_2 -> V_30 , V_23 ) ;
F_20 ( & V_2 -> V_21 , V_25 ) ;
F_14 ( V_2 -> V_4 , L_5 ) ;
}
static void * F_21 ( struct V_19 * V_20 , int V_48 ,
void * * V_49 , int V_50 , bool V_51 )
{
int V_52 ;
struct V_53 * V_46 ;
if ( V_48 == - 1 )
V_48 = F_22 () ;
V_52 = F_23 ( V_48 ) ;
V_46 = F_24 ( sizeof( struct V_53 ) , V_54 , V_52 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_55 = V_51 ;
V_46 -> V_50 = V_50 ;
V_46 -> V_56 = V_49 ;
return V_46 ;
}
static void F_25 ( void * V_57 )
{
struct V_53 * V_46 = V_57 ;
F_26 ( V_46 ) ;
}
static int F_27 ( struct V_19 * V_20 ,
struct V_58 * V_59 ,
void * V_60 )
{
int V_61 = 0 ;
unsigned long V_62 ;
struct V_53 * V_46 = V_60 ;
V_62 = V_59 -> V_62 & ( ( V_46 -> V_50 << V_63 ) - 1 ) ;
V_46 -> V_64 = V_62 / V_65 ;
V_46 -> V_66 = V_62 % V_65 ;
F_20 ( & V_46 -> V_67 , 0 ) ;
return V_61 ;
}
static unsigned long F_28 ( struct V_19 * V_20 ,
struct V_58 * V_59 ,
void * V_60 , bool * V_68 )
{
unsigned long V_69 = 0 ;
struct V_53 * V_46 = V_60 ;
if ( V_46 ) {
if ( V_46 -> V_55 )
V_59 -> V_62 = F_29 ( & V_46 -> V_67 ,
V_46 -> V_50 << V_63 ) ;
* V_68 = ! ! F_29 ( & V_46 -> V_68 , 0 ) ;
V_69 = F_29 ( & V_46 -> V_67 , 0 ) ;
}
return V_69 ;
}
static void F_30 ( struct V_19 * V_20 ,
struct V_58 * V_59 ,
void * V_60 )
{
int V_7 , V_64 ;
T_2 * V_37 ;
T_1 V_39 , V_40 , V_70 ;
T_1 V_71 , V_38 , V_72 ;
unsigned long V_66 ;
struct V_53 * V_46 = V_60 ;
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_24 ) ;
if ( ! V_46 )
return;
V_70 = V_2 -> V_8 * V_43 ;
F_6 ( V_2 -> V_5 ) ;
F_15 ( V_2 ) ;
V_39 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_40 = F_3 ( V_2 -> V_5 + V_9 ) ;
if ( V_40 % V_43 ) {
F_17 ( V_2 -> V_4 ,
L_3 ,
( unsigned long ) V_40 ) ;
V_40 &= ~ ( V_43 - 1 ) ;
F_31 ( & V_46 -> V_68 ) ;
}
V_71 = F_3 ( V_2 -> V_5 + V_44 ) ;
if ( V_71 & V_45 ) {
F_31 ( & V_46 -> V_68 ) ;
V_72 = V_70 ;
V_39 = V_40 ;
} else {
V_72 = F_32 ( V_40 , V_39 , V_2 -> V_8 ) ;
V_72 *= V_43 ;
}
if ( ! V_46 -> V_55 && V_72 > V_59 -> V_69 ) {
T_1 V_73 = ~ ( V_43 - 1 ) ;
V_72 = V_59 -> V_69 & V_73 ;
V_39 = ( V_40 + V_2 -> V_8 ) -
V_72 / V_43 ;
if ( V_39 > ( V_2 -> V_8 - 1 ) )
V_39 -= V_2 -> V_8 ;
F_31 ( & V_46 -> V_68 ) ;
}
F_7 ( V_39 , V_2 -> V_5 + V_11 ) ;
V_64 = V_46 -> V_64 ;
V_66 = V_46 -> V_66 ;
for ( V_7 = 0 ; V_7 < V_72 ; V_7 += 4 ) {
V_37 = V_46 -> V_56 [ V_64 ] + V_66 ;
V_38 = F_3 ( V_2 -> V_5 +
V_47 ) ;
* V_37 ++ = V_38 >> 0 ;
* V_37 ++ = V_38 >> 8 ;
* V_37 ++ = V_38 >> 16 ;
* V_37 ++ = V_38 >> 24 ;
V_66 += 4 ;
if ( V_66 >= V_65 ) {
V_66 = 0 ;
V_64 ++ ;
V_64 &= V_46 -> V_50 - 1 ;
}
}
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
if ( V_46 -> V_55 )
F_20 ( & V_46 -> V_67 , ( V_64 * V_65 ) + V_66 ) ;
else
F_33 ( V_72 , & V_46 -> V_67 ) ;
F_5 ( V_2 ) ;
F_8 ( V_2 -> V_5 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_23 ;
F_12 ( & V_2 -> V_30 , V_23 ) ;
if ( F_35 ( & V_2 -> V_21 ) == V_28 ) {
F_15 ( V_2 ) ;
F_18 ( V_2 ) ;
F_5 ( V_2 ) ;
}
F_13 ( & V_2 -> V_30 , V_23 ) ;
F_14 ( V_2 -> V_4 , L_6 ) ;
}
static int F_36 ( struct V_74 * V_74 , struct V_75 * V_75 )
{
struct V_1 * V_2 = F_37 ( V_75 -> V_76 ,
struct V_1 , V_77 ) ;
if ( F_11 ( & V_2 -> V_78 , 0 , 1 ) )
return - V_27 ;
F_38 ( V_2 -> V_4 , L_7 , V_79 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_75 * V_75 , char T_4 * V_80 ,
T_5 V_81 , T_6 * V_82 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_37 ( V_75 -> V_76 ,
struct V_1 , V_77 ) ;
F_34 ( V_2 ) ;
V_3 = V_2 -> V_8 ;
if ( * V_82 + V_81 > V_3 * 4 )
V_81 = V_3 * 4 - * V_82 ;
if ( F_40 ( V_80 , V_2 -> V_46 + * V_82 , V_81 ) ) {
F_38 ( V_2 -> V_4 , L_8 , V_79 ) ;
return - V_83 ;
}
* V_82 += V_81 ;
F_38 ( V_2 -> V_4 , L_9 ,
V_79 , V_81 , ( int ) ( V_3 * 4 - * V_82 ) ) ;
return V_81 ;
}
static int F_41 ( struct V_74 * V_74 , struct V_75 * V_75 )
{
struct V_1 * V_2 = F_37 ( V_75 -> V_76 ,
struct V_1 , V_77 ) ;
F_20 ( & V_2 -> V_78 , 0 ) ;
F_38 ( V_2 -> V_4 , L_10 , V_79 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_84 * V_4 ,
struct V_85 * V_86 , char * V_46 )
{
struct V_1 * V_2 = F_10 ( V_4 -> V_24 ) ;
unsigned long V_22 = V_2 -> V_12 ;
return sprintf ( V_46 , L_11 , V_22 ) ;
}
static T_3 F_43 ( struct V_84 * V_4 ,
struct V_85 * V_86 ,
const char * V_46 , T_5 V_69 )
{
int V_61 ;
unsigned long V_22 ;
struct V_1 * V_2 = F_10 ( V_4 -> V_24 ) ;
V_61 = F_44 ( V_46 , 16 , & V_22 ) ;
if ( V_61 )
return V_61 ;
V_2 -> V_12 = V_22 ;
return V_69 ;
}
static int F_45 ( struct V_87 * V_88 , const struct V_89 * V_90 )
{
int V_61 ;
void T_7 * V_5 ;
struct V_84 * V_4 = & V_88 -> V_4 ;
struct V_91 * V_92 = NULL ;
struct V_1 * V_2 ;
struct V_93 * V_94 = & V_88 -> V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 = V_88 -> V_4 . V_99 ;
if ( V_98 ) {
V_92 = F_46 ( V_4 , V_98 ) ;
if ( F_47 ( V_92 ) )
return F_48 ( V_92 ) ;
V_88 -> V_4 . V_100 = V_92 ;
}
V_2 = F_49 ( V_4 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_4 = & V_88 -> V_4 ;
V_2 -> V_102 = F_50 ( & V_88 -> V_4 , L_12 ) ;
if ( ! F_47 ( V_2 -> V_102 ) ) {
V_61 = F_51 ( V_2 -> V_102 ) ;
if ( V_61 )
return V_61 ;
}
F_52 ( V_4 , V_2 ) ;
V_5 = F_53 ( V_4 , V_94 ) ;
if ( F_47 ( V_5 ) )
return F_48 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
F_54 ( & V_2 -> V_30 ) ;
V_2 -> V_8 = F_1 ( V_2 ) ;
F_4 ( & V_88 -> V_4 ) ;
if ( V_2 -> V_8 & 0x80000000 )
return - V_103 ;
V_2 -> V_46 = F_49 ( V_4 ,
V_2 -> V_8 * 4 , V_54 ) ;
if ( ! V_2 -> V_46 ) {
F_17 ( V_4 , L_13 ,
V_2 -> V_8 * 4 ) ;
return - V_101 ;
}
V_96 = F_49 ( V_4 , sizeof( * V_96 ) , V_54 ) ;
if ( ! V_96 )
return - V_101 ;
V_96 -> type = V_104 ;
V_96 -> V_105 . V_106 = V_107 ;
V_96 -> V_108 = & V_109 ;
V_96 -> V_92 = V_92 ;
V_96 -> V_4 = V_4 ;
V_96 -> V_110 = V_111 ;
V_2 -> V_20 = F_55 ( V_96 ) ;
if ( F_47 ( V_2 -> V_20 ) )
return F_48 ( V_2 -> V_20 ) ;
V_2 -> V_77 . V_112 = V_92 -> V_112 ;
V_2 -> V_77 . V_113 = V_114 ;
V_2 -> V_77 . V_115 = & V_116 ;
V_61 = F_56 ( & V_2 -> V_77 ) ;
if ( V_61 )
goto V_117;
return 0 ;
V_117:
F_57 ( V_2 -> V_20 ) ;
return V_61 ;
}
static int F_58 ( struct V_84 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_47 ( V_2 -> V_102 ) )
F_59 ( V_2 -> V_102 ) ;
return 0 ;
}
static int F_60 ( struct V_84 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_47 ( V_2 -> V_102 ) )
F_51 ( V_2 -> V_102 ) ;
return 0 ;
}
