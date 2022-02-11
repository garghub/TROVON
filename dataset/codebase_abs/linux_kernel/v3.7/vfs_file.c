int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
F_2 ( V_11 , L_1 , V_1 , V_2 ) ;
V_5 = F_3 ( V_1 ) ;
V_7 = F_4 ( V_1 ) ;
if ( F_5 ( V_7 ) )
V_10 = F_6 ( V_2 -> V_12 ) ;
else
V_10 = F_7 ( V_2 -> V_12 ,
F_8 ( V_7 ) ) ;
V_9 = V_2 -> V_13 ;
if ( ! V_9 ) {
V_9 = F_9 ( V_2 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_3 = F_12 ( V_9 , V_10 ) ;
if ( V_3 < 0 ) {
F_13 ( V_9 ) ;
return V_3 ;
}
if ( V_2 -> V_12 & V_16 ) {
F_14 ( V_1 , 0 ) ;
V_1 -> V_17 = 0 ;
}
if ( ( V_2 -> V_12 & V_18 ) &&
( ! F_8 ( V_7 ) && ! F_5 ( V_7 ) ) )
F_15 ( V_2 , 0 , V_19 ) ;
}
V_2 -> V_13 = V_9 ;
F_16 ( & V_5 -> V_20 ) ;
if ( V_7 -> V_21 && ! V_5 -> V_22 &&
( ( V_2 -> V_12 & V_23 ) != V_24 ) ) {
V_9 = F_17 ( V_2 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) ) {
V_3 = F_11 ( V_9 ) ;
F_18 ( & V_5 -> V_20 ) ;
goto V_25;
}
V_5 -> V_22 = ( void * ) V_9 ;
}
F_18 ( & V_5 -> V_20 ) ;
#ifdef F_19
if ( V_7 -> V_21 )
F_20 ( V_1 , V_2 ) ;
#endif
return 0 ;
V_25:
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return V_3 ;
}
static int F_21 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
int V_30 = 0 ;
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
F_2 ( V_11 , L_2 , V_26 , V_29 ) ;
if ( F_22 ( V_1 ) && V_29 -> V_32 != V_33 )
return - V_34 ;
if ( ( F_23 ( V_27 ) || F_24 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_25 ( V_1 -> V_35 ) ;
F_26 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
return V_30 ;
}
static int F_27 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_37 V_38 ;
struct V_8 * V_9 ;
T_1 V_39 ;
int V_30 = 0 ;
unsigned char V_32 ;
V_9 = V_26 -> V_13 ;
F_28 ( V_9 == NULL ) ;
if ( ( V_29 -> V_40 & V_41 ) != V_41 )
F_29 () ;
V_30 = F_30 ( V_26 , V_29 ) ;
if ( V_30 < 0 )
goto V_42;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
switch ( V_29 -> V_32 ) {
case V_43 :
V_38 . type = V_44 ;
break;
case V_45 :
V_38 . type = V_46 ;
break;
case V_33 :
V_38 . type = V_47 ;
break;
}
V_38 . V_48 = V_29 -> V_49 ;
if ( V_29 -> V_50 == V_51 )
V_38 . V_52 = 0 ;
else
V_38 . V_52 = V_29 -> V_50 - V_29 -> V_49 + 1 ;
V_38 . V_53 = V_29 -> V_54 ;
V_38 . V_55 = F_31 () -> V_56 ;
if ( F_24 ( V_27 ) )
V_38 . V_57 = V_58 ;
for (; ; ) {
V_30 = F_32 ( V_9 , & V_38 , & V_39 ) ;
if ( V_30 < 0 )
break;
if ( V_39 != V_59 )
break;
if ( V_39 == V_59 && ! F_24 ( V_27 ) )
break;
if ( F_33 ( V_60 ) != 0 )
break;
}
switch ( V_39 ) {
case V_61 :
V_30 = 0 ;
break;
case V_59 :
V_30 = - V_62 ;
break;
case V_63 :
case V_64 :
V_30 = - V_34 ;
break;
default:
F_29 () ;
}
if ( V_30 < 0 && V_29 -> V_32 != V_33 ) {
V_32 = V_29 -> V_32 ;
V_29 -> V_32 = V_33 ;
V_30 = F_30 ( V_26 , V_29 ) ;
V_29 -> V_32 = V_32 ;
}
V_42:
return V_30 ;
}
static int F_34 ( struct V_2 * V_26 , struct V_28 * V_29 )
{
struct V_65 V_66 ;
struct V_8 * V_9 ;
int V_30 = 0 ;
V_9 = V_26 -> V_13 ;
F_28 ( V_9 == NULL ) ;
F_35 ( V_26 , V_29 ) ;
if ( V_29 -> V_32 != V_33 )
return V_30 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_47 ;
V_66 . V_48 = V_29 -> V_49 ;
if ( V_29 -> V_50 == V_51 )
V_66 . V_52 = 0 ;
else
V_66 . V_52 = V_29 -> V_50 - V_29 -> V_49 + 1 ;
V_66 . V_53 = V_29 -> V_54 ;
V_66 . V_55 = F_31 () -> V_56 ;
V_30 = F_36 ( V_9 , & V_66 ) ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_66 . type ) {
case V_44 :
V_29 -> V_32 = V_43 ;
break;
case V_46 :
V_29 -> V_32 = V_45 ;
break;
case V_47 :
V_29 -> V_32 = V_33 ;
break;
}
if ( V_66 . type != V_47 ) {
V_29 -> V_49 = V_66 . V_48 ;
if ( V_66 . V_52 == 0 )
V_29 -> V_50 = V_51 ;
else
V_29 -> V_50 = V_66 . V_48 + V_66 . V_52 - 1 ;
V_29 -> V_54 = V_66 . V_53 ;
}
return V_30 ;
}
static int F_37 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
int V_67 = - V_34 ;
F_2 ( V_11 , L_3 ,
V_26 , V_27 , V_29 , V_26 -> V_14 . V_15 -> V_68 . V_69 ) ;
if ( F_22 ( V_1 ) && V_29 -> V_32 != V_33 )
goto V_70;
if ( ( F_23 ( V_27 ) || F_24 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_25 ( V_1 -> V_35 ) ;
F_26 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
if ( F_23 ( V_27 ) || F_24 ( V_27 ) )
V_67 = F_27 ( V_26 , V_27 , V_29 ) ;
else if ( F_38 ( V_27 ) )
V_67 = F_34 ( V_26 , V_29 ) ;
else
V_67 = - V_71 ;
V_70:
return V_67 ;
}
static int F_39 ( struct V_2 * V_26 , int V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
int V_67 = - V_34 ;
F_2 ( V_11 , L_3 ,
V_26 , V_27 , V_29 , V_26 -> V_14 . V_15 -> V_68 . V_69 ) ;
if ( F_22 ( V_1 ) && V_29 -> V_32 != V_33 )
goto V_70;
if ( ! ( V_29 -> V_40 & V_72 ) )
goto V_70;
if ( ( F_23 ( V_27 ) || F_24 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_25 ( V_1 -> V_35 ) ;
F_26 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
V_29 -> V_73 = ( V_74 ) V_26 ;
V_29 -> V_49 = 0 ;
V_29 -> V_50 = V_51 ;
V_29 -> V_40 |= V_41 ;
V_29 -> V_40 ^= V_72 ;
if ( F_23 ( V_27 ) | F_24 ( V_27 ) )
V_67 = F_27 ( V_26 , V_27 , V_29 ) ;
else
V_67 = - V_71 ;
V_70:
return V_67 ;
}
T_2
F_40 ( struct V_8 * V_9 , char * V_75 , char T_3 * V_76 , T_4 V_77 ,
T_5 V_78 )
{
int V_79 , V_80 , V_81 ;
F_2 ( V_11 , L_4 ,
V_9 -> V_9 , ( long long unsigned ) V_78 , V_77 ) ;
V_79 = 0 ;
V_80 = 0 ;
V_81 = V_9 -> V_82 ? V_9 -> V_82 : V_9 -> V_83 -> V_84 - V_85 ;
do {
V_79 = F_41 ( V_9 , V_75 , V_76 , V_78 , V_77 ) ;
if ( V_79 <= 0 )
break;
if ( V_75 )
V_75 += V_79 ;
if ( V_76 )
V_76 += V_79 ;
V_78 += V_79 ;
V_77 -= V_79 ;
V_80 += V_79 ;
} while ( V_77 > 0 && V_79 == V_81 );
if ( V_79 < 0 )
V_80 = V_79 ;
return V_80 ;
}
T_2
F_42 ( struct V_2 * V_26 , char * V_75 , char T_3 * V_76 , T_4 V_77 ,
T_5 V_78 )
{
return F_40 ( V_26 -> V_13 , V_75 , V_76 , V_77 , V_78 ) ;
}
static T_2
F_43 ( struct V_2 * V_26 , char T_3 * V_76 , T_6 V_77 ,
T_7 * V_78 )
{
int V_67 ;
struct V_8 * V_9 ;
T_6 V_81 ;
F_2 ( V_11 , L_5 , V_77 , * V_78 ) ;
V_9 = V_26 -> V_13 ;
V_81 = V_9 -> V_82 ? V_9 -> V_82 : V_9 -> V_83 -> V_84 - V_85 ;
if ( V_77 > V_81 )
V_67 = F_42 ( V_26 , NULL , V_76 , V_77 , * V_78 ) ;
else
V_67 = F_41 ( V_9 , NULL , V_76 , * V_78 , V_77 ) ;
if ( V_67 > 0 )
* V_78 += V_67 ;
return V_67 ;
}
T_2
F_44 ( struct V_1 * V_1 , struct V_8 * V_9 ,
const char T_3 * V_75 , T_6 V_77 ,
T_7 * V_78 , int V_86 )
{
int V_79 ;
T_7 V_87 ;
T_6 V_80 = 0 ;
struct V_88 * V_83 ;
T_7 V_89 = * V_78 ;
unsigned long V_90 , V_91 ;
F_2 ( V_11 , L_6 ,
V_75 , ( int ) V_77 , ( int ) * V_78 ) ;
V_83 = V_9 -> V_83 ;
do {
V_79 = F_45 ( V_9 , NULL , V_75 + V_80 , V_89 + V_80 , V_77 ) ;
if ( V_79 <= 0 )
break;
V_77 -= V_79 ;
V_80 += V_79 ;
} while ( V_77 > 0 );
if ( V_86 && ( V_80 > 0 ) ) {
V_90 = V_89 >> V_92 ;
V_91 = ( V_89 + V_80 - 1 ) >> V_92 ;
if ( V_1 -> V_35 && V_1 -> V_35 -> V_93 )
F_46 ( V_1 -> V_35 ,
V_90 , V_91 ) ;
* V_78 += V_80 ;
V_87 = F_47 ( V_1 ) ;
if ( * V_78 > V_87 ) {
F_48 ( V_1 , * V_78 - V_87 ) ;
F_14 ( V_1 , * V_78 ) ;
}
}
if ( V_79 < 0 )
return V_79 ;
return V_80 ;
}
static T_2
F_49 ( struct V_2 * V_26 , const char T_3 * V_75 ,
T_6 V_77 , T_7 * V_78 )
{
T_2 V_94 = 0 ;
T_7 V_89 = * V_78 ;
V_94 = F_50 ( V_26 , & V_89 , & V_77 , 0 ) ;
if ( V_94 )
goto V_42;
V_94 = - V_71 ;
if ( ( T_2 ) V_77 < 0 )
goto V_42;
V_94 = 0 ;
if ( ! V_77 )
goto V_42;
V_94 = F_44 ( V_26 -> V_14 . V_15 -> V_31 ,
V_26 -> V_13 ,
V_75 , V_77 , & V_89 , 1 ) ;
if ( V_94 > 0 )
* V_78 = V_89 ;
V_42:
return V_94 ;
}
static int F_51 ( struct V_2 * V_26 , T_7 V_48 , T_7 V_95 ,
int V_96 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_97 -> V_98 ;
struct V_99 V_100 ;
int V_94 ;
V_94 = F_52 ( V_1 -> V_35 , V_48 , V_95 ) ;
if ( V_94 )
return V_94 ;
F_16 ( & V_1 -> V_101 ) ;
F_2 ( V_11 , L_7 , V_26 , V_96 ) ;
V_9 = V_26 -> V_13 ;
F_53 ( & V_100 ) ;
V_94 = F_54 ( V_9 , & V_100 ) ;
F_18 ( & V_1 -> V_101 ) ;
return V_94 ;
}
int F_55 ( struct V_2 * V_26 , T_7 V_48 , T_7 V_95 ,
int V_96 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_97 -> V_98 ;
int V_94 ;
V_94 = F_52 ( V_1 -> V_35 , V_48 , V_95 ) ;
if ( V_94 )
return V_94 ;
F_16 ( & V_1 -> V_101 ) ;
F_2 ( V_11 , L_7 , V_26 , V_96 ) ;
V_9 = V_26 -> V_13 ;
V_94 = F_56 ( V_9 , V_96 ) ;
F_18 ( & V_1 -> V_101 ) ;
return V_94 ;
}
static int
F_57 ( struct V_2 * V_2 , struct V_102 * V_103 )
{
int V_94 ;
V_94 = F_58 ( V_2 , V_103 ) ;
if ( ! V_94 )
V_103 -> V_104 = & V_105 ;
return V_94 ;
}
static int
F_59 ( struct V_102 * V_103 , struct V_106 * V_107 )
{
struct V_4 * V_5 ;
struct V_108 * V_108 = V_107 -> V_108 ;
struct V_2 * V_26 = V_103 -> V_109 ;
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
F_2 ( V_11 , L_8 ,
V_108 , ( unsigned long ) V_26 -> V_13 ) ;
F_60 ( V_26 ) ;
V_5 = F_3 ( V_1 ) ;
F_61 ( V_1 , V_108 ) ;
F_28 ( ! V_5 -> V_22 ) ;
F_62 ( V_108 ) ;
if ( V_108 -> V_110 != V_1 -> V_35 )
goto V_111;
return V_112 ;
V_111:
F_63 ( V_108 ) ;
return V_113 ;
}
static T_2
F_64 ( struct V_2 * V_26 , char T_3 * V_76 , T_6 V_77 ,
T_7 * V_114 )
{
T_7 V_81 , V_78 ;
struct V_1 * V_1 ;
struct V_115 * V_110 ;
V_78 = * V_114 ;
V_110 = V_26 -> V_97 ;
V_1 = V_110 -> V_98 ;
if ( ! V_77 )
return 0 ;
V_81 = F_47 ( V_1 ) ;
if ( V_78 < V_81 )
F_52 ( V_110 , V_78 ,
V_78 + V_77 - 1 ) ;
return F_43 ( V_26 , V_76 , V_77 , V_114 ) ;
}
static T_2
F_65 ( struct V_2 * V_26 , char T_3 * V_75 , T_6 V_77 ,
T_7 * V_78 )
{
if ( V_26 -> V_12 & V_116 )
return F_64 ( V_26 , V_75 , V_77 , V_78 ) ;
return F_66 ( V_26 , V_75 , V_77 , V_78 ) ;
}
static T_2
F_67 ( struct V_2 * V_26 , const char T_3 * V_75 ,
T_6 V_77 , T_7 * V_114 )
{
T_7 V_78 ;
T_2 V_94 ;
struct V_1 * V_1 ;
struct V_115 * V_110 ;
V_78 = * V_114 ;
V_110 = V_26 -> V_97 ;
V_1 = V_110 -> V_98 ;
if ( ! V_77 )
return 0 ;
F_16 ( & V_1 -> V_101 ) ;
V_94 = F_52 ( V_110 , V_78 ,
V_78 + V_77 - 1 ) ;
if ( V_94 )
goto V_117;
if ( V_110 -> V_93 ) {
T_8 V_90 = V_78 >> V_92 ;
T_8 V_91 = ( V_78 + V_77 - 1 ) >> V_92 ;
V_94 = F_46 ( V_110 ,
V_90 , V_91 ) ;
if ( V_94 ) {
if ( V_94 == - V_118 )
goto V_119;
goto V_117;
}
}
V_94 = F_49 ( V_26 , V_75 , V_77 , V_114 ) ;
V_117:
F_18 ( & V_1 -> V_101 ) ;
return V_94 ;
V_119:
F_18 ( & V_1 -> V_101 ) ;
return F_68 ( V_26 , V_75 , V_77 , V_114 ) ;
}
static T_2
F_69 ( struct V_2 * V_26 , const char T_3 * V_75 ,
T_6 V_77 , T_7 * V_78 )
{
if ( V_26 -> V_12 & V_116 )
return F_67 ( V_26 , V_75 , V_77 , V_78 ) ;
return F_68 ( V_26 , V_75 , V_77 , V_78 ) ;
}
