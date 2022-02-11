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
unsigned long V_16 = V_9 -> V_17 . V_18 <<
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
V_9 -> V_17 . V_18 = V_16 >> ( V_19 - 10 ) ;
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
static T_1 F_16 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_22 , ( V_2 ) ) ;
}
static T_1 F_17 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_18 ( V_9 ) )
return F_1 ( F_19 ( V_9 ) , ( V_2 ) ) ;
return F_1 ( V_23 , ( V_2 ) ) ;
}
static T_1 F_20 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_21 ( V_9 ) , V_2 ) ;
}
static T_1 F_22 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_23 ( V_9 ) , V_2 ) ;
}
static T_1 F_24 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_24 , V_2 ) ;
}
static T_1 F_25 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_26 ( V_9 ) , V_2 ) ;
}
static T_1 F_27 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_28 ( V_9 ) , V_2 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( V_9 -> V_21 . V_25 , V_2 ) ;
}
static T_1 F_30 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_26 << 9 ) ;
}
static T_1 F_31 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_27 << 9 ) ;
}
static T_1 F_32 ( struct V_8 * V_9 ,
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
static T_1 F_33 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_34 ( V_9 ) , V_2 ) ;
}
static T_1 F_35 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_29 << 9 ) ;
}
static T_1 F_36 ( struct V_8 * V_9 , char * V_2 )
{
return sprintf ( V_2 , L_2 ,
( unsigned long long ) V_9 -> V_21 . V_30 << 9 ) ;
}
static T_1
F_37 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
unsigned long V_20 ,
V_31 = F_38 ( V_9 ) >> 1 ,
V_32 = 1 << ( V_19 - 10 ) ;
T_1 V_12 = F_2 ( & V_20 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_31 = F_39 ( V_31 , ( unsigned long )
V_9 -> V_21 . V_33 >> 1 ) ;
if ( V_20 > V_31 || V_20 < V_32 )
return - V_7 ;
F_40 ( V_9 -> V_34 ) ;
V_9 -> V_21 . V_35 = V_20 << 1 ;
V_9 -> V_17 . V_36 = V_20 >> ( V_19 - 10 ) ;
F_41 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_42 ( struct V_8 * V_9 , char * V_2 )
{
int V_31 = F_38 ( V_9 ) >> 1 ;
return F_1 ( V_31 , ( V_2 ) ) ;
}
static T_1 F_43 ( struct V_8 * V_9 , char * V_2 )
{
switch ( F_44 ( V_9 ) ) {
case V_37 :
return sprintf ( V_2 , L_3 ) ;
case V_38 :
return sprintf ( V_2 , L_4 ) ;
default:
return sprintf ( V_2 , L_5 ) ;
}
}
static T_1 F_45 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( ( F_46 ( V_9 ) << 1 ) |
F_47 ( V_9 ) , V_2 ) ;
}
static T_1 F_48 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_39 ;
T_1 V_12 = F_2 ( & V_39 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_40 ( V_9 -> V_34 ) ;
F_49 ( V_40 , V_9 ) ;
F_49 ( V_41 , V_9 ) ;
if ( V_39 == 2 )
F_50 ( V_40 , V_9 ) ;
else if ( V_39 )
F_50 ( V_41 , V_9 ) ;
F_41 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_51 ( struct V_8 * V_9 , char * V_2 )
{
bool V_42 = F_52 ( V_43 , & V_9 -> V_44 ) ;
bool V_45 = F_52 ( V_46 , & V_9 -> V_44 ) ;
return F_1 ( V_42 << V_45 , V_2 ) ;
}
static T_1
F_53 ( struct V_8 * V_9 , const char * V_2 , T_2 V_3 )
{
T_1 V_12 = - V_7 ;
#ifdef F_54
unsigned long V_47 ;
V_12 = F_2 ( & V_47 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_40 ( V_9 -> V_34 ) ;
if ( V_47 == 2 ) {
F_50 ( V_43 , V_9 ) ;
F_50 ( V_46 , V_9 ) ;
} else if ( V_47 == 1 ) {
F_50 ( V_43 , V_9 ) ;
F_49 ( V_46 , V_9 ) ;
} else if ( V_47 == 0 ) {
F_49 ( V_43 , V_9 ) ;
F_49 ( V_46 , V_9 ) ;
}
F_41 ( V_9 -> V_34 ) ;
#endif
return V_12 ;
}
static T_1 F_55 ( struct V_8 * V_9 , char * V_2 )
{
int V_47 ;
if ( V_9 -> V_48 == - 1 )
V_47 = - 1 ;
else
V_47 = V_9 -> V_48 / 1000 ;
return sprintf ( V_2 , L_6 , V_47 ) ;
}
static T_1 F_56 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
int V_4 , V_47 ;
if ( ! V_9 -> V_14 || ! V_9 -> V_14 -> V_49 )
return - V_7 ;
V_4 = F_57 ( V_2 , 10 , & V_47 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_47 == - 1 )
V_9 -> V_48 = - 1 ;
else
V_9 -> V_48 = V_47 * 1000 ;
return V_3 ;
}
static T_1 F_58 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_52 ( V_50 , & V_9 -> V_44 ) , V_2 ) ;
}
static T_1 F_59 ( struct V_8 * V_9 , const char * V_2 ,
T_2 V_3 )
{
unsigned long V_51 ;
T_1 V_12 ;
if ( ! V_9 -> V_14 || ! V_9 -> V_14 -> V_49 )
return - V_7 ;
V_12 = F_2 ( & V_51 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_40 ( V_9 -> V_34 ) ;
if ( V_51 )
F_50 ( V_50 , V_9 ) ;
else
F_49 ( V_50 , V_9 ) ;
F_41 ( V_9 -> V_34 ) ;
return V_12 ;
}
static T_1 F_60 ( struct V_8 * V_9 , char * V_2 )
{
if ( ! V_9 -> V_52 )
return - V_7 ;
return sprintf ( V_2 , L_2 , F_61 ( V_9 -> V_52 -> V_53 , 1000 ) ) ;
}
static T_1 F_62 ( struct V_8 * V_9 , const char * V_2 ,
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
V_12 = F_63 ( V_9 ) ;
if ( V_12 )
return V_12 ;
V_54 = V_9 -> V_52 ;
if ( ! V_54 )
return - V_7 ;
}
if ( V_47 == - 1 )
V_54 -> V_53 = F_64 ( V_9 ) ;
else if ( V_47 >= 0 )
V_54 -> V_53 = V_47 * 1000ULL ;
if ( V_54 -> V_55 == V_56 )
V_54 -> V_55 = V_57 ;
F_65 ( V_54 ) ;
return V_3 ;
}
static T_1 F_66 ( struct V_8 * V_9 , char * V_2 )
{
if ( F_52 ( V_58 , & V_9 -> V_44 ) )
return sprintf ( V_2 , L_7 ) ;
return sprintf ( V_2 , L_8 ) ;
}
static T_1 F_67 ( struct V_8 * V_9 , const char * V_2 ,
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
F_40 ( V_9 -> V_34 ) ;
if ( V_42 )
F_50 ( V_58 , V_9 ) ;
else
F_49 ( V_58 , V_9 ) ;
F_41 ( V_9 -> V_34 ) ;
return V_3 ;
}
static T_1 F_68 ( struct V_8 * V_9 , char * V_2 )
{
return F_1 ( F_69 ( V_9 ) , V_2 ) ;
}
static T_1 F_70 ( char * V_2 , struct V_59 * V_60 , const char * V_61 )
{
return sprintf ( V_2 , L_12 ,
V_61 , ( long long ) V_60 -> V_62 ,
( long long ) V_60 -> V_63 , ( long long ) V_60 -> V_64 ,
( long long ) V_60 -> V_65 ) ;
}
static T_1 F_71 ( struct V_8 * V_9 , char * V_2 )
{
struct V_59 V_60 [ 2 ] ;
T_1 V_12 ;
F_72 ( V_9 , V_60 ) ;
V_12 = F_70 ( V_2 , & V_60 [ V_66 ] , L_13 ) ;
V_12 += F_70 ( V_2 + V_12 , & V_60 [ V_67 ] , L_14 ) ;
return V_12 ;
}
static T_1
F_73 ( struct V_68 * V_69 , struct V_70 * V_71 , char * V_2 )
{
struct V_72 * V_73 = F_74 ( V_71 ) ;
struct V_8 * V_9 =
F_75 ( V_69 , struct V_8 , V_69 ) ;
T_1 V_74 ;
if ( ! V_73 -> V_75 )
return - V_76 ;
F_76 ( & V_9 -> V_77 ) ;
if ( F_77 ( V_9 ) ) {
F_78 ( & V_9 -> V_77 ) ;
return - V_78 ;
}
V_74 = V_73 -> V_75 ( V_9 , V_2 ) ;
F_78 ( & V_9 -> V_77 ) ;
return V_74 ;
}
static T_1
F_79 ( struct V_68 * V_69 , struct V_70 * V_71 ,
const char * V_2 , T_2 V_79 )
{
struct V_72 * V_73 = F_74 ( V_71 ) ;
struct V_8 * V_9 ;
T_1 V_74 ;
if ( ! V_73 -> V_80 )
return - V_76 ;
V_9 = F_75 ( V_69 , struct V_8 , V_69 ) ;
F_76 ( & V_9 -> V_77 ) ;
if ( F_77 ( V_9 ) ) {
F_78 ( & V_9 -> V_77 ) ;
return - V_78 ;
}
V_74 = V_73 -> V_80 ( V_9 , V_2 , V_79 ) ;
F_78 ( & V_9 -> V_77 ) ;
return V_74 ;
}
static void F_80 ( struct V_81 * V_81 )
{
struct V_8 * V_9 = F_75 ( V_81 , struct V_8 ,
V_81 ) ;
F_81 ( V_82 , V_9 ) ;
}
static void F_82 ( struct V_68 * V_69 )
{
struct V_8 * V_9 =
F_75 ( V_69 , struct V_8 , V_69 ) ;
F_83 ( V_9 ) ;
F_84 ( & V_9 -> V_17 ) ;
F_85 ( V_9 ) ;
if ( V_9 -> V_83 ) {
F_40 ( V_9 -> V_34 ) ;
F_86 ( V_9 ) ;
F_41 ( V_9 -> V_34 ) ;
F_87 ( V_9 -> V_83 ) ;
}
F_88 ( & V_9 -> V_84 ) ;
if ( V_9 -> V_85 )
F_89 ( V_9 ) ;
if ( ! V_9 -> V_14 )
F_90 ( V_9 -> V_86 ) ;
else
F_91 ( V_9 ) ;
F_92 ( V_9 ) ;
if ( V_9 -> V_87 )
F_93 ( V_9 -> V_87 ) ;
F_94 ( & V_88 , V_9 -> V_89 ) ;
F_95 ( & V_9 -> V_81 , F_80 ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
#ifndef F_97
if ( V_9 -> V_14 )
return;
#endif
#ifndef F_98
if ( V_9 -> V_13 )
return;
#endif
F_63 ( V_9 ) ;
}
int F_99 ( struct V_90 * V_91 )
{
int V_12 ;
struct V_92 * V_93 = F_100 ( V_91 ) ;
struct V_8 * V_9 = V_91 -> V_94 ;
if ( F_101 ( ! V_9 ) )
return - V_95 ;
if ( ! F_102 ( V_9 ) ) {
F_103 ( V_96 , V_9 ) ;
F_104 ( & V_9 -> V_97 ) ;
F_105 ( V_9 ) ;
}
V_12 = F_106 ( V_93 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_107 ( & V_9 -> V_69 , F_108 ( & V_93 -> V_69 ) , L_15 , L_16 ) ;
if ( V_12 < 0 ) {
F_109 ( V_93 ) ;
return V_12 ;
}
F_110 ( & V_9 -> V_69 , V_98 ) ;
if ( V_9 -> V_14 )
F_111 ( V_93 , V_9 ) ;
F_96 ( V_9 ) ;
if ( ! V_9 -> V_13 )
return 0 ;
V_12 = F_112 ( V_9 ) ;
if ( V_12 ) {
F_110 ( & V_9 -> V_69 , V_99 ) ;
F_113 ( & V_9 -> V_69 ) ;
F_109 ( V_93 ) ;
F_114 ( & V_93 -> V_69 ) ;
return V_12 ;
}
return 0 ;
}
void F_115 ( struct V_90 * V_91 )
{
struct V_8 * V_9 = V_91 -> V_94 ;
if ( F_101 ( ! V_9 ) )
return;
if ( V_9 -> V_14 )
F_116 ( F_100 ( V_91 ) , V_9 ) ;
if ( V_9 -> V_13 )
F_117 ( V_9 ) ;
F_110 ( & V_9 -> V_69 , V_99 ) ;
F_113 ( & V_9 -> V_69 ) ;
F_109 ( F_100 ( V_91 ) ) ;
F_114 ( & F_100 ( V_91 ) -> V_69 ) ;
}
