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
L_2 ) ;
}
F_7 ( 0x0 , V_2 -> V_5 + V_18 ) ;
if ( F_16 ( V_2 -> V_5 , V_35 , V_36 , 1 ) ) {
F_17 ( V_2 -> V_4 ,
L_3 ) ;
}
F_8 ( V_2 -> V_5 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
bool V_37 = false ;
int V_7 ;
T_2 * V_38 ;
const T_1 * V_39 ;
T_1 V_40 , V_3 ;
T_1 V_41 , V_42 ;
T_1 V_43 , V_44 ;
F_6 ( V_2 -> V_5 ) ;
V_41 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_42 = F_3 ( V_2 -> V_5 + V_9 ) ;
V_43 = V_42 % V_45 ;
V_44 = V_45 - V_43 ;
if ( V_43 ) {
F_17 ( V_2 -> V_4 ,
L_4 ,
( unsigned long ) V_42 ) ;
F_17 ( V_2 -> V_4 , L_5 ,
( unsigned long ) V_43 , ( unsigned long ) V_44 ) ;
V_42 += V_44 ;
}
if ( ( F_3 ( V_2 -> V_5 + V_46 )
& V_47 ) == 0 ) {
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
} else {
F_7 ( V_42 , V_2 -> V_5 + V_11 ) ;
V_37 = true ;
}
V_3 = V_2 -> V_8 ;
V_38 = V_2 -> V_48 ;
V_39 = V_49 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_40 = F_3 ( V_2 -> V_5 +
V_50 ) ;
if ( V_37 && * V_39 ) {
V_40 = * V_39 ;
V_39 ++ ;
}
* ( T_1 * ) V_38 = V_40 ;
V_38 += 4 ;
}
if ( V_43 ) {
V_38 -= ( V_44 * 4 ) ;
for ( V_7 = 0 ; V_7 < V_44 ; V_7 ++ ) {
* V_38 ++ = 0x0 ;
* V_38 ++ = 0x0 ;
* V_38 ++ = 0x0 ;
* V_38 ++ = 0x0 ;
}
}
F_7 ( V_41 , V_2 -> V_5 + V_11 ) ;
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
F_14 ( V_2 -> V_4 , L_6 ) ;
}
static void * F_21 ( struct V_19 * V_20 , int V_51 ,
void * * V_52 , int V_53 , bool V_54 )
{
int V_55 ;
struct V_56 * V_48 ;
if ( V_51 == - 1 )
V_51 = F_22 () ;
V_55 = F_23 ( V_51 ) ;
V_48 = F_24 ( sizeof( struct V_56 ) , V_57 , V_55 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_58 = V_54 ;
V_48 -> V_53 = V_53 ;
V_48 -> V_59 = V_52 ;
return V_48 ;
}
static void F_25 ( void * V_60 )
{
struct V_56 * V_48 = V_60 ;
F_26 ( V_48 ) ;
}
static int F_27 ( struct V_19 * V_20 ,
struct V_61 * V_62 ,
void * V_63 )
{
int V_64 = 0 ;
unsigned long V_65 ;
struct V_56 * V_48 = V_63 ;
V_65 = V_62 -> V_65 & ( ( V_48 -> V_53 << V_66 ) - 1 ) ;
V_48 -> V_67 = V_65 / V_68 ;
V_48 -> V_69 = V_65 % V_68 ;
F_20 ( & V_48 -> V_70 , 0 ) ;
return V_64 ;
}
static unsigned long F_28 ( struct V_19 * V_20 ,
struct V_61 * V_62 ,
void * V_63 )
{
unsigned long V_71 = 0 ;
struct V_56 * V_48 = V_63 ;
if ( V_48 ) {
if ( V_48 -> V_58 )
V_62 -> V_65 = F_29 ( & V_48 -> V_70 ,
V_48 -> V_53 << V_66 ) ;
V_71 = F_29 ( & V_48 -> V_70 , 0 ) ;
}
return V_71 ;
}
static void F_30 ( struct V_19 * V_20 ,
struct V_61 * V_62 ,
void * V_63 )
{
bool V_37 = false ;
int V_7 , V_67 ;
T_2 * V_38 ;
const T_1 * V_39 ;
T_1 V_41 , V_42 , V_72 ;
T_1 V_73 , V_40 , V_74 ;
unsigned long V_69 ;
struct V_56 * V_48 = V_63 ;
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_24 ) ;
if ( ! V_48 )
return;
V_72 = V_2 -> V_8 * V_45 ;
F_15 ( V_2 ) ;
F_6 ( V_2 -> V_5 ) ;
V_41 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_42 = F_3 ( V_2 -> V_5 + V_9 ) ;
if ( V_42 % V_45 ) {
F_17 ( V_2 -> V_4 ,
L_4 ,
( unsigned long ) V_42 ) ;
V_42 &= ~ ( V_45 - 1 ) ;
V_37 = true ;
}
V_73 = F_3 ( V_2 -> V_5 + V_46 ) ;
if ( V_73 & V_47 ) {
V_37 = true ;
V_74 = V_72 ;
V_41 = V_42 ;
} else {
V_74 = F_31 ( V_42 , V_41 , V_2 -> V_8 ) ;
V_74 *= V_45 ;
}
if ( ! V_48 -> V_58 && V_74 > V_62 -> V_71 ) {
T_1 V_75 = ~ ( V_45 - 1 ) ;
V_74 = V_62 -> V_71 & V_75 ;
V_41 = ( V_42 + V_2 -> V_8 ) -
V_74 / V_45 ;
if ( V_41 > ( V_2 -> V_8 - 1 ) )
V_41 -= V_2 -> V_8 ;
V_37 = true ;
}
if ( V_37 )
F_32 ( V_62 , V_76 ) ;
F_7 ( V_41 , V_2 -> V_5 + V_11 ) ;
V_67 = V_48 -> V_67 ;
V_69 = V_48 -> V_69 ;
V_39 = V_49 ;
for ( V_7 = 0 ; V_7 < V_74 ; V_7 += 4 ) {
V_38 = V_48 -> V_59 [ V_67 ] + V_69 ;
V_40 = F_3 ( V_2 -> V_5 +
V_50 ) ;
if ( V_37 && * V_39 ) {
V_40 = * V_39 ;
V_39 ++ ;
}
* ( T_1 * ) V_38 = V_40 ;
V_38 += 4 ;
V_69 += 4 ;
if ( V_69 >= V_68 ) {
V_69 = 0 ;
V_67 ++ ;
V_67 &= V_48 -> V_53 - 1 ;
}
}
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
if ( V_48 -> V_58 )
F_20 ( & V_48 -> V_70 , ( V_67 * V_68 ) + V_69 ) ;
else
F_33 ( V_74 , & V_48 -> V_70 ) ;
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
F_14 ( V_2 -> V_4 , L_7 ) ;
}
static int F_36 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_1 * V_2 = F_37 ( V_78 -> V_79 ,
struct V_1 , V_80 ) ;
if ( F_11 ( & V_2 -> V_81 , 0 , 1 ) )
return - V_27 ;
F_38 ( V_2 -> V_4 , L_8 , V_82 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_78 * V_78 , char T_4 * V_83 ,
T_5 V_84 , T_6 * V_85 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_37 ( V_78 -> V_79 ,
struct V_1 , V_80 ) ;
F_34 ( V_2 ) ;
V_3 = V_2 -> V_8 ;
if ( * V_85 + V_84 > V_3 * 4 )
V_84 = V_3 * 4 - * V_85 ;
if ( F_40 ( V_83 , V_2 -> V_48 + * V_85 , V_84 ) ) {
F_38 ( V_2 -> V_4 , L_9 , V_82 ) ;
return - V_86 ;
}
* V_85 += V_84 ;
F_38 ( V_2 -> V_4 , L_10 ,
V_82 , V_84 , ( int ) ( V_3 * 4 - * V_85 ) ) ;
return V_84 ;
}
static int F_41 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_1 * V_2 = F_37 ( V_78 -> V_79 ,
struct V_1 , V_80 ) ;
F_20 ( & V_2 -> V_81 , 0 ) ;
F_38 ( V_2 -> V_4 , L_11 , V_82 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_87 * V_4 ,
struct V_88 * V_89 , char * V_48 )
{
struct V_1 * V_2 = F_10 ( V_4 -> V_24 ) ;
unsigned long V_22 = V_2 -> V_12 ;
return sprintf ( V_48 , L_12 , V_22 ) ;
}
static T_3 F_43 ( struct V_87 * V_4 ,
struct V_88 * V_89 ,
const char * V_48 , T_5 V_71 )
{
int V_64 ;
unsigned long V_22 ;
struct V_1 * V_2 = F_10 ( V_4 -> V_24 ) ;
V_64 = F_44 ( V_48 , 16 , & V_22 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_12 = V_22 ;
return V_71 ;
}
static int F_45 ( struct V_90 * V_91 , const struct V_92 * V_93 )
{
int V_64 ;
void T_7 * V_5 ;
struct V_87 * V_4 = & V_91 -> V_4 ;
struct V_94 * V_95 = NULL ;
struct V_1 * V_2 ;
struct V_96 * V_97 = & V_91 -> V_97 ;
struct V_98 V_99 = { 0 } ;
struct V_100 * V_101 = V_91 -> V_4 . V_102 ;
if ( V_101 ) {
V_95 = F_46 ( V_4 , V_101 ) ;
if ( F_47 ( V_95 ) )
return F_48 ( V_95 ) ;
V_91 -> V_4 . V_103 = V_95 ;
}
V_2 = F_49 ( V_4 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_4 = & V_91 -> V_4 ;
V_2 -> V_105 = F_50 ( & V_91 -> V_4 , L_13 ) ;
if ( ! F_47 ( V_2 -> V_105 ) ) {
V_64 = F_51 ( V_2 -> V_105 ) ;
if ( V_64 )
return V_64 ;
}
F_52 ( V_4 , V_2 ) ;
V_5 = F_53 ( V_4 , V_97 ) ;
if ( F_47 ( V_5 ) )
return F_48 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
F_54 ( & V_2 -> V_30 ) ;
V_2 -> V_8 = F_1 ( V_2 ) ;
F_4 ( & V_91 -> V_4 ) ;
if ( V_2 -> V_8 & 0x80000000 )
return - V_106 ;
V_2 -> V_48 = F_49 ( V_4 ,
V_2 -> V_8 * 4 , V_57 ) ;
if ( ! V_2 -> V_48 )
return - V_104 ;
V_99 . type = V_107 ;
V_99 . V_108 . V_109 = V_110 ;
V_99 . V_111 = & V_112 ;
V_99 . V_95 = V_95 ;
V_99 . V_4 = V_4 ;
V_99 . V_113 = V_114 ;
V_2 -> V_20 = F_55 ( & V_99 ) ;
if ( F_47 ( V_2 -> V_20 ) )
return F_48 ( V_2 -> V_20 ) ;
V_2 -> V_80 . V_115 = V_95 -> V_115 ;
V_2 -> V_80 . V_116 = V_117 ;
V_2 -> V_80 . V_118 = & V_119 ;
V_64 = F_56 ( & V_2 -> V_80 ) ;
if ( V_64 )
goto V_120;
return 0 ;
V_120:
F_57 ( V_2 -> V_20 ) ;
return V_64 ;
}
static int F_58 ( struct V_87 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_47 ( V_2 -> V_105 ) )
F_59 ( V_2 -> V_105 ) ;
return 0 ;
}
static int F_60 ( struct V_87 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_47 ( V_2 -> V_105 ) )
F_51 ( V_2 -> V_105 ) ;
return 0 ;
}
