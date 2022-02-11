static T_1
F_1 ( unsigned long V_1 , char * V_2 )
{
return sprintf ( V_2 , L_1 , V_1 ) ;
}
static T_1
F_2 ( unsigned long * V_1 , const char * V_2 , T_2 V_3 )
{
int V_4 ;
unsigned long V_5 ;
V_4 = F_3 ( V_2 , 10 , & V_5 ) ;
if ( V_4 || V_5 > V_6 )
return - V_7 ;
* V_1 = V_5 ;
return V_3 ;
}
static T_1 F_4 ( T_3 * V_1 , const char * V_2 )
{
int V_4 ;
T_3 V_5 ;
V_4 = F_5 ( V_2 , 10 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_1 = V_5 ;
return 0 ;
}
static T_1 F_6 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_10 , ( V_2 ) ) ;
}
static T_1
F_7 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_11 ;
int V_12 , V_4 ;
if ( ! V_9 -> V_13 && ! V_9 -> V_14 )
return - V_7 ;
V_12 = F_2 ( & V_11 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 < V_15 )
V_11 = V_15 ;
if ( V_9 -> V_13 )
V_4 = F_8 ( V_9 , V_11 ) ;
else
V_4 = F_9 ( V_9 , V_11 ) ;
if ( V_4 )
return V_4 ;
return V_12 ;
}
static T_1 F_10 ( struct V_8 * V_9 , char * V_2 )
{
unsigned long V_16 = V_9 -> V_17 -> V_18 <<
( V_19 - 10 ) ;
return F_1 ( V_16 , ( V_2 ) ) ;
}
static T_1
F_11 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_16 ;
T_1 V_12 = F_2 ( & V_16 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_9 -> V_17 -> V_18 = V_16 >> ( V_19 - 10 ) ;
return V_12 ;
}
static T_1 F_12 ( struct V_8 * V_9 , char * V_2 )
{
int V_20 = F_13 ( V_9 ) >> 1 ;
return F_1 ( V_20 , ( V_2 ) ) ;
}
static T_1 F_14 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_15 ( V_9 ) , ( V_2 ) ) ;
}
static T_1 F_16 ( struct V_8 * V_9 ,
char * V_2 )
{
return F_1 ( F_17 ( V_9 ) , ( V_2 ) ) ;
}
static T_1 F_18 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_22 , ( V_2 ) ) ;
}
static T_1 F_19 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_20 ( V_9 ) )
return F_1 ( F_21 ( V_9 ) , ( V_2 ) ) ;
return F_1 ( V_23 , ( V_2 ) ) ;
}
static T_1 F_22 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_23 ( V_9 ) , V_2 ) ;
}
static T_1 F_24 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_25 ( V_9 ) , V_2 ) ;
}
static T_1 F_26 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_24 , V_2 ) ;
}
static T_1 F_27 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_28 ( V_9 ) , V_2 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_30 ( V_9 ) , V_2 ) ;
}
static T_1 F_31 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_25 , V_2 ) ;
}
static T_1 F_32 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_26 << 9 ) ;
}
static T_1 F_33 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_27 << 9 ) ;
}
static T_1 F_34 ( struct V_8 * V_9 ,
const char * V_2 , T_2 V_3 )
{
unsigned long V_28 ;
T_1 V_12 = F_2 ( & V_28 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_28 & ( V_9 -> V_21 . V_25 - 1 ) )
return - V_7 ;
V_28 >>= 9 ;
if ( V_28 > V_6 )
return - V_7 ;
if ( V_28 > V_9 -> V_21 . V_26 )
V_28 = V_9 -> V_21 . V_26 ;
V_9 -> V_21 . V_27 = V_28 ;
return V_12 ;
}
static T_1 F_35 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( 0 , V_2 ) ;
}
static T_1 F_36 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_29 << 9 ) ;
}
static T_1 F_37 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_30 << 9 ) ;
}
static T_1
F_38 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ,
V_31 = F_39 ( V_9 ) >> 1 ,
V_32 = 1 << ( V_19 - 10 ) ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_31 = F_40 ( V_31 , ( unsigned long )
V_9 -> V_21 . V_33 >> 1 ) ;
if ( V_20 > V_31 || V_20 < V_32 )
return - V_7 ;
F_41 ( V_9 -> V_34 ) ;
V_9 -> V_21 . V_35 = V_20 << 1 ;
V_9 -> V_17 -> V_36 = V_20 >> ( V_19 - 10 ) ;
F_42 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_43 ( struct V_8 * V_9 , char * V_2 )
{
int V_31 = F_39 ( V_9 ) >> 1 ;
return F_1 ( V_31 , ( V_2 ) ) ;
}
static T_1 F_44 ( struct V_8 * V_9 , char * V_2 )
{
switch ( F_45 ( V_9 ) ) {
case V_37 :
return sprintf ( V_2 , L_3 ) ;
case V_38 :
return sprintf ( V_2 , L_4 ) ;
default:
return sprintf ( V_2 , L_5 ) ;
}
}
static T_1 F_46 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_47 ( V_9 ) << 1 ) |
F_48 ( V_9 ) , V_2 ) ;
}
static T_1 F_49 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_39 ;
T_1 V_12 = F_2 ( & V_39 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_41 ( V_9 -> V_34 ) ;
F_50 ( V_40 , V_9 ) ;
F_50 ( V_41 , V_9 ) ;
if ( V_39 == 2 )
F_51 ( V_40 , V_9 ) ;
else if ( V_39 )
F_51 ( V_41 , V_9 ) ;
F_42 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_52 ( struct V_8 * V_9 , char * V_2 )
{
bool V_42 = F_53 ( V_43 , & V_9 -> V_44 ) ;
bool V_45 = F_53 ( V_46 , & V_9 -> V_44 ) ;
return F_1 ( V_42 << V_45 , V_2 ) ;
}
static T_1
F_54 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_7 ;
#ifdef F_55
unsigned long V_47 ;
V_12 = F_2 ( & V_47 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_41 ( V_9 -> V_34 ) ;
if ( V_47 == 2 ) {
F_51 ( V_43 , V_9 ) ;
F_51 ( V_46 , V_9 ) ;
} else if ( V_47 == 1 ) {
F_51 ( V_43 , V_9 ) ;
F_50 ( V_46 , V_9 ) ;
} else if ( V_47 == 0 ) {
F_50 ( V_43 , V_9 ) ;
F_50 ( V_46 , V_9 ) ;
}
F_42 ( V_9 -> V_34 ) ;
#endif
return V_12 ;
}
static T_1 F_56 ( struct V_8 * V_9 , char * V_2 )
{
int V_47 ;
if ( V_9 -> V_48 == - 1 )
V_47 = - 1 ;
else
V_47 = V_9 -> V_48 / 1000 ;
return sprintf ( V_2 , L_6 , V_47 ) ;
}
static T_1 F_57 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
int V_4 , V_47 ;
if ( ! V_9 -> V_14 || ! V_9 -> V_14 -> V_49 )
return - V_7 ;
V_4 = F_58 ( V_2 , 10 , & V_47 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_47 == - 1 )
V_9 -> V_48 = - 1 ;
else
V_9 -> V_48 = V_47 * 1000 ;
return V_3 ;
}
static T_1 F_59 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_53 ( V_50 , & V_9 -> V_44 ) , V_2 ) ;
}
static T_1 F_60 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_51 ;
T_1 V_12 ;
if ( ! V_9 -> V_14 || ! V_9 -> V_14 -> V_49 )
return - V_7 ;
V_12 = F_2 ( & V_51 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_41 ( V_9 -> V_34 ) ;
if ( V_51 )
F_51 ( V_50 , V_9 ) ;
else
F_50 ( V_50 , V_9 ) ;
F_42 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_61 ( struct V_8 * V_9 , char * V_2 )
{
if ( ! V_9 -> V_52 )
return - V_7 ;
return sprintf ( V_2 , L_2 , F_62 ( V_9 -> V_52 -> V_53 , 1000 ) ) ;
}
static T_1 F_63 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
struct V_52 * V_54 ;
T_1 V_12 ;
T_3 V_47 ;
V_12 = F_4 ( & V_47 , V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_47 < - 1 )
return - V_7 ;
V_54 = V_9 -> V_52 ;
if ( ! V_54 ) {
V_12 = F_64 ( V_9 ) ;
if ( V_12 )
return V_12 ;
V_54 = V_9 -> V_52 ;
if ( ! V_54 )
return - V_7 ;
}
if ( V_47 == - 1 )
V_54 -> V_53 = F_65 ( V_9 ) ;
else if ( V_47 >= 0 )
V_54 -> V_53 = V_47 * 1000ULL ;
if ( V_54 -> V_55 == V_56 )
V_54 -> V_55 = V_57 ;
F_66 ( V_54 ) ;
return V_3 ;
}
static T_1 F_67 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_53 ( V_58 , & V_9 -> V_44 ) )
return sprintf ( V_2 , L_7 ) ;
return sprintf ( V_2 , L_8 ) ;
}
static T_1 F_68 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
int V_42 = - 1 ;
if ( ! strncmp ( V_2 , L_9 , 10 ) )
V_42 = 1 ;
else if ( ! strncmp ( V_2 , L_10 , 13 ) ||
! strncmp ( V_2 , L_11 , 4 ) )
V_42 = 0 ;
if ( V_42 == - 1 )
return - V_7 ;
F_41 ( V_9 -> V_34 ) ;
if ( V_42 )
F_51 ( V_58 , V_9 ) ;
else
F_50 ( V_58 , V_9 ) ;
F_42 ( V_9 -> V_34 ) ;
return V_3 ;
}
static T_1 F_69 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_70 ( V_9 ) , V_2 ) ;
}
static T_1
F_71 ( struct V_59 * V_60 , struct V_61 * V_62 , char * V_2 )
{
struct V_63 * V_64 = F_72 ( V_62 ) ;
struct V_8 * V_9 =
F_73 ( V_60 , struct V_8 , V_60 ) ;
T_1 V_65 ;
if ( ! V_64 -> V_66 )
return - V_67 ;
F_74 ( & V_9 -> V_68 ) ;
if ( F_75 ( V_9 ) ) {
F_76 ( & V_9 -> V_68 ) ;
return - V_69 ;
}
V_65 = V_64 -> V_66 ( V_9 , V_2 ) ;
F_76 ( & V_9 -> V_68 ) ;
return V_65 ;
}
static T_1
F_77 ( struct V_59 * V_60 , struct V_61 * V_62 ,
const char * V_2 , T_2 V_70 )
{
struct V_63 * V_64 = F_72 ( V_62 ) ;
struct V_8 * V_9 ;
T_1 V_65 ;
if ( ! V_64 -> V_71 )
return - V_67 ;
V_9 = F_73 ( V_60 , struct V_8 , V_60 ) ;
F_74 ( & V_9 -> V_68 ) ;
if ( F_75 ( V_9 ) ) {
F_76 ( & V_9 -> V_68 ) ;
return - V_69 ;
}
V_65 = V_64 -> V_71 ( V_9 , V_2 , V_70 ) ;
F_76 ( & V_9 -> V_68 ) ;
return V_65 ;
}
static void F_78 ( struct V_72 * V_72 )
{
struct V_8 * V_9 = F_73 ( V_72 , struct V_8 ,
V_72 ) ;
F_79 ( V_73 , V_9 ) ;
}
static void F_80 ( struct V_74 * V_75 )
{
struct V_8 * V_9 = F_73 ( V_75 , F_81 ( * V_9 ) , V_76 ) ;
if ( F_53 ( V_77 , & V_9 -> V_44 ) )
F_82 ( V_9 , V_9 -> V_78 ) ;
F_83 ( V_9 -> V_78 ) ;
F_84 ( V_9 -> V_17 ) ;
F_85 ( V_9 ) ;
if ( V_9 -> V_79 ) {
F_86 ( V_9 ) ;
F_87 ( V_9 , V_9 -> V_79 ) ;
}
F_88 ( V_9 -> V_80 ) ;
F_89 ( V_9 , & V_9 -> V_81 ) ;
if ( V_9 -> V_82 )
F_90 ( V_9 ) ;
if ( ! V_9 -> V_14 ) {
if ( V_9 -> V_83 )
V_9 -> V_83 ( V_9 , V_9 -> V_84 -> V_85 ) ;
F_91 ( V_9 -> V_84 ) ;
} else {
F_92 ( V_9 ) ;
}
F_93 ( V_9 ) ;
if ( V_9 -> V_14 )
F_94 ( V_9 ) ;
if ( V_9 -> V_86 )
F_95 ( V_9 -> V_86 ) ;
F_96 ( & V_87 , V_9 -> V_88 ) ;
F_97 ( & V_9 -> V_72 , F_78 ) ;
}
static void F_98 ( struct V_59 * V_60 )
{
struct V_8 * V_9 =
F_73 ( V_60 , struct V_8 , V_60 ) ;
F_99 ( & V_9 -> V_76 , F_80 ) ;
F_100 ( & V_9 -> V_76 ) ;
}
int F_101 ( struct V_89 * V_90 )
{
int V_12 ;
struct V_91 * V_92 = F_102 ( V_90 ) ;
struct V_8 * V_9 = V_90 -> V_93 ;
if ( F_103 ( ! V_9 ) )
return - V_94 ;
F_104 ( F_53 ( V_95 , & V_9 -> V_44 ) ,
L_12 ,
F_105 ( & V_92 -> V_60 ) ) ;
F_106 ( V_95 , V_9 ) ;
if ( ! F_107 ( V_9 ) ) {
F_106 ( V_96 , V_9 ) ;
F_108 ( & V_9 -> V_97 ) ;
F_109 ( V_9 ) ;
}
V_12 = F_110 ( V_92 ) ;
if ( V_12 )
return V_12 ;
F_74 ( & V_9 -> V_68 ) ;
V_12 = F_111 ( & V_9 -> V_60 , F_112 ( & V_92 -> V_60 ) , L_13 , L_14 ) ;
if ( V_12 < 0 ) {
F_113 ( V_92 ) ;
goto V_98;
}
if ( V_9 -> V_14 ) {
F_114 ( V_92 , V_9 ) ;
F_115 ( V_9 ) ;
}
F_116 ( & V_9 -> V_60 , V_99 ) ;
F_117 ( V_9 ) ;
F_118 ( V_9 ) ;
if ( V_9 -> V_13 || ( V_9 -> V_14 && V_9 -> V_79 ) ) {
V_12 = F_119 ( V_9 ) ;
if ( V_12 ) {
F_116 ( & V_9 -> V_60 , V_100 ) ;
F_120 ( & V_9 -> V_60 ) ;
F_113 ( V_92 ) ;
F_121 ( & V_92 -> V_60 ) ;
goto V_98;
}
}
V_12 = 0 ;
V_98:
F_76 ( & V_9 -> V_68 ) ;
return V_12 ;
}
void F_122 ( struct V_89 * V_90 )
{
struct V_8 * V_9 = V_90 -> V_93 ;
if ( F_103 ( ! V_9 ) )
return;
F_74 ( & V_9 -> V_68 ) ;
F_123 ( V_95 , V_9 ) ;
F_76 ( & V_9 -> V_68 ) ;
F_124 ( V_9 ) ;
if ( V_9 -> V_14 )
F_125 ( F_102 ( V_90 ) , V_9 ) ;
if ( V_9 -> V_13 || ( V_9 -> V_14 && V_9 -> V_79 ) )
F_126 ( V_9 ) ;
F_116 ( & V_9 -> V_60 , V_100 ) ;
F_120 ( & V_9 -> V_60 ) ;
F_113 ( F_102 ( V_90 ) ) ;
F_121 ( & F_102 ( V_90 ) -> V_60 ) ;
}
