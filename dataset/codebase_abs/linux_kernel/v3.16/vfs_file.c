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
if ( ( V_2 -> V_12 & V_16 ) &&
( ! F_8 ( V_7 ) && ! F_5 ( V_7 ) ) )
F_14 ( V_2 , 0 , V_17 ) ;
}
V_2 -> V_13 = V_9 ;
F_15 ( & V_5 -> V_18 ) ;
if ( ( V_7 -> V_19 == V_20 || V_7 -> V_19 == V_21 ) &&
! V_5 -> V_22 &&
( ( V_2 -> V_12 & V_23 ) != V_24 ) ) {
V_9 = F_16 ( V_2 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) ) {
V_3 = F_11 ( V_9 ) ;
F_17 ( & V_5 -> V_18 ) ;
goto V_25;
}
V_5 -> V_22 = ( void * ) V_9 ;
}
F_17 ( & V_5 -> V_18 ) ;
if ( V_7 -> V_19 == V_20 || V_7 -> V_19 == V_21 )
F_18 ( V_1 , V_2 ) ;
return 0 ;
V_25:
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return V_3 ;
}
static int F_19 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
int V_30 = 0 ;
struct V_1 * V_1 = F_20 ( V_26 ) ;
F_2 ( V_11 , L_2 , V_26 , V_29 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_31 != V_32 )
return - V_33 ;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_31 != V_32 ) {
F_24 ( V_1 -> V_34 ) ;
F_25 ( & V_1 -> V_35 , 0 , - 1 ) ;
}
return V_30 ;
}
static int F_26 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_36 V_37 ;
struct V_8 * V_9 ;
T_1 V_38 ;
int V_30 = 0 ;
unsigned char V_31 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
if ( ( V_29 -> V_39 & V_40 ) != V_40 )
F_28 () ;
V_30 = F_29 ( V_26 , V_29 ) ;
if ( V_30 < 0 )
goto V_41;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
switch ( V_29 -> V_31 ) {
case V_42 :
V_37 . type = V_43 ;
break;
case V_44 :
V_37 . type = V_45 ;
break;
case V_32 :
V_37 . type = V_46 ;
break;
}
V_37 . V_47 = V_29 -> V_48 ;
if ( V_29 -> V_49 == V_50 )
V_37 . V_51 = 0 ;
else
V_37 . V_51 = V_29 -> V_49 - V_29 -> V_48 + 1 ;
V_37 . V_52 = V_29 -> V_53 ;
V_37 . V_54 = V_9 -> V_55 -> V_56 ;
if ( F_23 ( V_27 ) )
V_37 . V_57 = V_58 ;
for (; ; ) {
V_30 = F_30 ( V_9 , & V_37 , & V_38 ) ;
if ( V_30 < 0 )
break;
if ( V_38 != V_59 )
break;
if ( V_38 == V_59 && ! F_23 ( V_27 ) )
break;
if ( F_31 ( V_60 ) != 0 )
break;
}
switch ( V_38 ) {
case V_61 :
V_30 = 0 ;
break;
case V_59 :
V_30 = - V_62 ;
break;
case V_63 :
case V_64 :
V_30 = - V_33 ;
break;
default:
F_28 () ;
}
if ( V_30 < 0 && V_29 -> V_31 != V_32 ) {
V_31 = V_29 -> V_31 ;
V_29 -> V_31 = V_32 ;
V_30 = F_29 ( V_26 , V_29 ) ;
V_29 -> V_31 = V_31 ;
}
V_41:
return V_30 ;
}
static int F_32 ( struct V_2 * V_26 , struct V_28 * V_29 )
{
struct V_65 V_66 ;
struct V_8 * V_9 ;
int V_30 = 0 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
F_33 ( V_26 , V_29 ) ;
if ( V_29 -> V_31 != V_32 )
return V_30 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_46 ;
V_66 . V_47 = V_29 -> V_48 ;
if ( V_29 -> V_49 == V_50 )
V_66 . V_51 = 0 ;
else
V_66 . V_51 = V_29 -> V_49 - V_29 -> V_48 + 1 ;
V_66 . V_52 = V_29 -> V_53 ;
V_66 . V_54 = V_9 -> V_55 -> V_56 ;
V_30 = F_34 ( V_9 , & V_66 ) ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_66 . type ) {
case V_43 :
V_29 -> V_31 = V_42 ;
break;
case V_45 :
V_29 -> V_31 = V_44 ;
break;
case V_46 :
V_29 -> V_31 = V_32 ;
break;
}
if ( V_66 . type != V_46 ) {
V_29 -> V_48 = V_66 . V_47 ;
if ( V_66 . V_51 == 0 )
V_29 -> V_49 = V_50 ;
else
V_29 -> V_49 = V_66 . V_47 + V_66 . V_51 - 1 ;
V_29 -> V_53 = V_66 . V_52 ;
}
return V_30 ;
}
static int F_35 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_1 * V_1 = F_20 ( V_26 ) ;
int V_67 = - V_33 ;
F_2 ( V_11 , L_3 ,
V_26 , V_27 , V_29 , V_26 -> V_14 . V_15 -> V_68 . V_56 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_31 != V_32 )
goto V_69;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_31 != V_32 ) {
F_24 ( V_1 -> V_34 ) ;
F_25 ( & V_1 -> V_35 , 0 , - 1 ) ;
}
if ( F_22 ( V_27 ) || F_23 ( V_27 ) )
V_67 = F_26 ( V_26 , V_27 , V_29 ) ;
else if ( F_36 ( V_27 ) )
V_67 = F_32 ( V_26 , V_29 ) ;
else
V_67 = - V_70 ;
V_69:
return V_67 ;
}
static int F_37 ( struct V_2 * V_26 , int V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = F_20 ( V_26 ) ;
int V_67 = - V_33 ;
F_2 ( V_11 , L_3 ,
V_26 , V_27 , V_29 , V_26 -> V_14 . V_15 -> V_68 . V_56 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_31 != V_32 )
goto V_69;
if ( ! ( V_29 -> V_39 & V_71 ) )
goto V_69;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_31 != V_32 ) {
F_24 ( V_1 -> V_34 ) ;
F_25 ( & V_1 -> V_35 , 0 , - 1 ) ;
}
V_29 -> V_39 |= V_40 ;
V_29 -> V_39 ^= V_71 ;
if ( F_22 ( V_27 ) | F_23 ( V_27 ) )
V_67 = F_26 ( V_26 , V_27 , V_29 ) ;
else
V_67 = - V_70 ;
V_69:
return V_67 ;
}
T_2
F_38 ( struct V_8 * V_9 , char * V_72 , char T_3 * V_73 , T_4 V_74 ,
T_5 V_75 )
{
int V_76 , V_77 , V_78 ;
F_2 ( V_11 , L_4 ,
V_9 -> V_9 , ( long long unsigned ) V_75 , V_74 ) ;
V_76 = 0 ;
V_77 = 0 ;
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_55 -> V_80 - V_81 ;
do {
V_76 = F_39 ( V_9 , V_72 , V_73 , V_75 , V_74 ) ;
if ( V_76 <= 0 )
break;
if ( V_72 )
V_72 += V_76 ;
if ( V_73 )
V_73 += V_76 ;
V_75 += V_76 ;
V_74 -= V_76 ;
V_77 += V_76 ;
} while ( V_74 > 0 && V_76 == V_78 );
if ( V_76 < 0 )
V_77 = V_76 ;
return V_77 ;
}
T_2
F_40 ( struct V_2 * V_26 , char * V_72 , char T_3 * V_73 , T_4 V_74 ,
T_5 V_75 )
{
return F_38 ( V_26 -> V_13 , V_72 , V_73 , V_74 , V_75 ) ;
}
static T_2
F_41 ( struct V_2 * V_26 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_75 )
{
int V_67 ;
struct V_8 * V_9 ;
T_6 V_78 ;
F_2 ( V_11 , L_5 , V_74 , * V_75 ) ;
V_9 = V_26 -> V_13 ;
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_55 -> V_80 - V_81 ;
if ( V_74 > V_78 )
V_67 = F_40 ( V_26 , NULL , V_73 , V_74 , * V_75 ) ;
else
V_67 = F_39 ( V_9 , NULL , V_73 , * V_75 , V_74 ) ;
if ( V_67 > 0 )
* V_75 += V_67 ;
return V_67 ;
}
T_2
F_42 ( struct V_1 * V_1 , struct V_8 * V_9 ,
const char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 , int V_82 )
{
int V_76 ;
T_7 V_83 ;
T_6 V_77 = 0 ;
T_7 V_84 = * V_75 ;
unsigned long V_85 , V_86 ;
F_2 ( V_11 , L_6 ,
V_72 , ( int ) V_74 , ( int ) * V_75 ) ;
do {
V_76 = F_43 ( V_9 , NULL , V_72 + V_77 , V_84 + V_77 , V_74 ) ;
if ( V_76 <= 0 )
break;
V_74 -= V_76 ;
V_77 += V_76 ;
} while ( V_74 > 0 );
if ( V_82 && ( V_77 > 0 ) ) {
V_85 = V_84 >> V_87 ;
V_86 = ( V_84 + V_77 - 1 ) >> V_87 ;
if ( V_1 -> V_34 && V_1 -> V_34 -> V_88 )
F_44 ( V_1 -> V_34 ,
V_85 , V_86 ) ;
* V_75 += V_77 ;
V_83 = F_45 ( V_1 ) ;
if ( * V_75 > V_83 ) {
F_46 ( V_1 , * V_75 - V_83 ) ;
F_47 ( V_1 , * V_75 ) ;
}
}
if ( V_76 < 0 )
return V_76 ;
return V_77 ;
}
static T_2
F_48 ( struct V_2 * V_26 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
T_2 V_89 = 0 ;
T_7 V_84 = * V_75 ;
V_89 = F_49 ( V_26 , & V_84 , & V_74 , 0 ) ;
if ( V_89 )
goto V_41;
V_89 = - V_70 ;
if ( ( T_2 ) V_74 < 0 )
goto V_41;
V_89 = 0 ;
if ( ! V_74 )
goto V_41;
V_89 = F_42 ( F_20 ( V_26 ) ,
V_26 -> V_13 ,
V_72 , V_74 , & V_84 , 1 ) ;
if ( V_89 > 0 )
* V_75 = V_84 ;
V_41:
return V_89 ;
}
static int F_50 ( struct V_2 * V_26 , T_7 V_47 , T_7 V_90 ,
int V_91 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_92 -> V_93 ;
struct V_94 V_95 ;
int V_89 ;
V_89 = F_51 ( V_1 -> V_34 , V_47 , V_90 ) ;
if ( V_89 )
return V_89 ;
F_15 ( & V_1 -> V_96 ) ;
F_2 ( V_11 , L_7 , V_26 , V_91 ) ;
V_9 = V_26 -> V_13 ;
F_52 ( & V_95 ) ;
V_89 = F_53 ( V_9 , & V_95 ) ;
F_17 ( & V_1 -> V_96 ) ;
return V_89 ;
}
int F_54 ( struct V_2 * V_26 , T_7 V_47 , T_7 V_90 ,
int V_91 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_92 -> V_93 ;
int V_89 ;
V_89 = F_51 ( V_1 -> V_34 , V_47 , V_90 ) ;
if ( V_89 )
return V_89 ;
F_15 ( & V_1 -> V_96 ) ;
F_2 ( V_11 , L_7 , V_26 , V_91 ) ;
V_9 = V_26 -> V_13 ;
V_89 = F_55 ( V_9 , V_91 ) ;
F_17 ( & V_1 -> V_96 ) ;
return V_89 ;
}
static int
F_56 ( struct V_2 * V_26 , struct V_97 * V_98 )
{
int V_89 ;
V_89 = F_57 ( V_26 , V_98 ) ;
if ( ! V_89 )
V_98 -> V_99 = & V_100 ;
return V_89 ;
}
static int
F_58 ( struct V_2 * V_26 , struct V_97 * V_98 )
{
int V_89 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
struct V_8 * V_9 ;
V_1 = F_20 ( V_26 ) ;
V_5 = F_3 ( V_1 ) ;
F_15 ( & V_5 -> V_18 ) ;
if ( ! V_5 -> V_22 &&
( V_98 -> V_101 & V_102 ) ) {
V_9 = F_16 ( V_26 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) ) {
V_89 = F_11 ( V_9 ) ;
F_17 ( & V_5 -> V_18 ) ;
return V_89 ;
}
V_5 -> V_22 = ( void * ) V_9 ;
}
F_17 ( & V_5 -> V_18 ) ;
V_89 = F_57 ( V_26 , V_98 ) ;
if ( ! V_89 )
V_98 -> V_99 = & V_103 ;
return V_89 ;
}
static int
F_59 ( struct V_97 * V_98 , struct V_104 * V_105 )
{
struct V_4 * V_5 ;
struct V_106 * V_106 = V_105 -> V_106 ;
struct V_2 * V_26 = V_98 -> V_107 ;
struct V_1 * V_1 = F_20 ( V_26 ) ;
F_2 ( V_11 , L_8 ,
V_106 , ( unsigned long ) V_26 -> V_13 ) ;
F_60 ( V_26 ) ;
V_5 = F_3 ( V_1 ) ;
F_61 ( V_1 , V_106 ) ;
F_27 ( ! V_5 -> V_22 ) ;
F_62 ( V_106 ) ;
if ( V_106 -> V_108 != V_1 -> V_34 )
goto V_109;
F_63 ( V_106 ) ;
return V_110 ;
V_109:
F_64 ( V_106 ) ;
return V_111 ;
}
static T_2
F_65 ( struct V_2 * V_26 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_112 )
{
T_7 V_78 , V_75 ;
struct V_1 * V_1 ;
struct V_113 * V_108 ;
V_75 = * V_112 ;
V_108 = V_26 -> V_92 ;
V_1 = V_108 -> V_93 ;
if ( ! V_74 )
return 0 ;
V_78 = F_45 ( V_1 ) ;
if ( V_75 < V_78 )
F_51 ( V_108 , V_75 ,
V_75 + V_74 - 1 ) ;
return F_41 ( V_26 , V_73 , V_74 , V_112 ) ;
}
static T_2
F_66 ( struct V_2 * V_26 , char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 )
{
if ( V_26 -> V_12 & V_114 )
return F_65 ( V_26 , V_72 , V_74 , V_75 ) ;
return F_67 ( V_26 , V_72 , V_74 , V_75 ) ;
}
static T_2
F_68 ( struct V_2 * V_26 , char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 )
{
return F_41 ( V_26 , V_72 , V_74 , V_75 ) ;
}
static T_2
F_69 ( struct V_2 * V_26 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_112 )
{
T_7 V_75 ;
T_2 V_89 ;
struct V_1 * V_1 ;
struct V_113 * V_108 ;
V_75 = * V_112 ;
V_108 = V_26 -> V_92 ;
V_1 = V_108 -> V_93 ;
if ( ! V_74 )
return 0 ;
F_15 ( & V_1 -> V_96 ) ;
V_89 = F_51 ( V_108 , V_75 ,
V_75 + V_74 - 1 ) ;
if ( V_89 )
goto V_115;
if ( V_108 -> V_88 ) {
T_8 V_85 = V_75 >> V_87 ;
T_8 V_86 = ( V_75 + V_74 - 1 ) >> V_87 ;
V_89 = F_44 ( V_108 ,
V_85 , V_86 ) ;
if ( V_89 ) {
if ( V_89 == - V_116 )
goto V_117;
goto V_115;
}
}
V_89 = F_48 ( V_26 , V_72 , V_74 , V_112 ) ;
V_115:
F_17 ( & V_1 -> V_96 ) ;
return V_89 ;
V_117:
F_17 ( & V_1 -> V_96 ) ;
return F_70 ( V_26 , V_72 , V_74 , V_112 ) ;
}
static T_2
F_71 ( struct V_2 * V_26 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
if ( V_26 -> V_12 & V_114 )
return F_69 ( V_26 , V_72 , V_74 , V_75 ) ;
return F_70 ( V_26 , V_72 , V_74 , V_75 ) ;
}
static T_2
F_72 ( struct V_2 * V_26 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
return F_48 ( V_26 , V_72 , V_74 , V_75 ) ;
}
static void F_73 ( struct V_97 * V_98 )
{
struct V_1 * V_1 ;
struct V_118 V_119 = {
. V_120 = V_121 ,
. V_122 = V_123 ,
. V_124 = V_98 -> V_125 * V_126 ,
. V_127 = V_98 -> V_125 * V_126 +
( V_98 -> V_128 - V_98 -> V_129 - 1 ) ,
} ;
F_2 ( V_11 , L_9 , V_98 ) ;
V_1 = F_20 ( V_98 -> V_107 ) ;
if ( ! F_74 ( V_1 -> V_34 ) )
V_119 . V_120 = 0 ;
F_75 () ;
F_76 ( V_1 , & V_119 ) ;
}
