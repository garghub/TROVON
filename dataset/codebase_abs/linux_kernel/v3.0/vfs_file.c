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
V_10 = V_2 -> V_12 ;
else
V_10 = F_6 ( V_2 -> V_12 ,
F_7 ( V_7 ) ) ;
V_9 = V_2 -> V_13 ;
if ( ! V_9 ) {
V_9 = F_8 ( V_2 -> V_14 . V_15 ) ;
if ( F_9 ( V_9 ) )
return F_10 ( V_9 ) ;
V_3 = F_11 ( V_9 , V_10 ) ;
if ( V_3 < 0 ) {
F_12 ( V_9 ) ;
return V_3 ;
}
if ( V_2 -> V_12 & V_16 ) {
F_13 ( V_1 , 0 ) ;
V_1 -> V_17 = 0 ;
}
if ( ( V_2 -> V_12 & V_18 ) &&
( ! F_7 ( V_7 ) && ! F_5 ( V_7 ) ) )
F_14 ( V_2 , 0 , V_19 ) ;
}
V_2 -> V_13 = V_9 ;
F_15 ( & V_5 -> V_20 ) ;
if ( V_7 -> V_21 && ! V_5 -> V_22 &&
( ( V_2 -> V_12 & V_23 ) != V_24 ) ) {
V_9 = F_16 ( V_2 -> V_14 . V_15 ) ;
if ( F_9 ( V_9 ) ) {
V_3 = F_10 ( V_9 ) ;
F_17 ( & V_5 -> V_20 ) ;
goto V_25;
}
V_5 -> V_22 = ( void * ) V_9 ;
}
F_17 ( & V_5 -> V_20 ) ;
#ifdef F_18
if ( V_7 -> V_21 )
F_19 ( V_1 , V_2 ) ;
#endif
return 0 ;
V_25:
F_12 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return V_3 ;
}
static int F_20 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
int V_30 = 0 ;
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
F_2 ( V_11 , L_2 , V_26 , V_29 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_32 != V_33 )
return - V_34 ;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_24 ( V_1 -> V_35 ) ;
F_25 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
return V_30 ;
}
static int F_26 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_37 V_38 ;
struct V_8 * V_9 ;
T_1 V_39 ;
int V_30 = 0 ;
unsigned char V_32 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
if ( ( V_29 -> V_40 & V_41 ) != V_41 )
F_28 () ;
V_30 = F_29 ( V_26 , V_29 ) ;
if ( V_30 < 0 )
goto V_42;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . type = V_29 -> V_32 ;
V_38 . V_43 = V_29 -> V_44 ;
if ( V_29 -> V_45 == V_46 )
V_38 . V_47 = 0 ;
else
V_38 . V_47 = V_29 -> V_45 - V_29 -> V_44 + 1 ;
V_38 . V_48 = V_29 -> V_49 ;
V_38 . V_50 = F_30 () -> V_51 ;
if ( F_23 ( V_27 ) )
V_38 . V_52 = V_53 ;
for (; ; ) {
V_30 = F_31 ( V_9 , & V_38 , & V_39 ) ;
if ( V_30 < 0 )
break;
if ( V_39 != V_54 )
break;
if ( V_39 == V_54 && ! F_23 ( V_27 ) )
break;
F_32 ( V_55 ) ;
}
switch ( V_39 ) {
case V_56 :
V_30 = 0 ;
break;
case V_54 :
V_30 = - V_57 ;
break;
case V_58 :
case V_59 :
V_30 = - V_34 ;
break;
default:
F_28 () ;
}
if ( V_30 < 0 && V_29 -> V_32 != V_33 ) {
V_32 = V_29 -> V_32 ;
V_29 -> V_32 = V_33 ;
V_30 = F_29 ( V_26 , V_29 ) ;
V_29 -> V_32 = V_32 ;
}
V_42:
return V_30 ;
}
static int F_33 ( struct V_2 * V_26 , struct V_28 * V_29 )
{
struct V_60 V_61 ;
struct V_8 * V_9 ;
int V_30 = 0 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
F_34 ( V_26 , V_29 ) ;
if ( V_29 -> V_32 != V_33 )
return V_30 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . type = V_29 -> V_32 ;
V_61 . V_43 = V_29 -> V_44 ;
if ( V_29 -> V_45 == V_46 )
V_61 . V_47 = 0 ;
else
V_61 . V_47 = V_29 -> V_45 - V_29 -> V_44 + 1 ;
V_61 . V_48 = V_29 -> V_49 ;
V_61 . V_50 = F_30 () -> V_51 ;
V_30 = F_35 ( V_9 , & V_61 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_61 . type != V_33 ) {
V_29 -> V_32 = V_61 . type ;
V_29 -> V_44 = V_61 . V_43 ;
if ( V_61 . V_47 == 0 )
V_29 -> V_45 = V_46 ;
else
V_29 -> V_45 = V_61 . V_43 + V_61 . V_47 - 1 ;
V_29 -> V_49 = V_61 . V_48 ;
} else
V_29 -> V_32 = V_33 ;
return V_30 ;
}
static int F_36 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
int V_62 = - V_34 ;
F_2 ( V_11 , L_3 , V_26 ,
V_27 , V_29 , V_26 -> V_14 . V_15 -> V_63 . V_64 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_32 != V_33 )
goto V_65;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_24 ( V_1 -> V_35 ) ;
F_25 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
if ( F_22 ( V_27 ) || F_23 ( V_27 ) )
V_62 = F_26 ( V_26 , V_27 , V_29 ) ;
else if ( F_37 ( V_27 ) )
V_62 = F_33 ( V_26 , V_29 ) ;
else
V_62 = - V_66 ;
V_65:
return V_62 ;
}
static int F_38 ( struct V_2 * V_26 , int V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
int V_62 = - V_34 ;
F_2 ( V_11 , L_3 , V_26 ,
V_27 , V_29 , V_26 -> V_14 . V_15 -> V_63 . V_64 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_32 != V_33 )
goto V_65;
if ( ! ( V_29 -> V_40 & V_67 ) )
goto V_65;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_32 != V_33 ) {
F_24 ( V_1 -> V_35 ) ;
F_25 ( & V_1 -> V_36 , 0 , - 1 ) ;
}
V_29 -> V_68 = ( V_69 ) V_26 ;
V_29 -> V_44 = 0 ;
V_29 -> V_45 = V_46 ;
V_29 -> V_40 |= V_41 ;
V_29 -> V_40 ^= V_67 ;
if ( F_22 ( V_27 ) | F_23 ( V_27 ) )
V_62 = F_26 ( V_26 , V_27 , V_29 ) ;
else
V_62 = - V_66 ;
V_65:
return V_62 ;
}
T_2
F_39 ( struct V_8 * V_9 , char * V_70 , char T_3 * V_71 , T_4 V_72 ,
T_5 V_73 )
{
int V_74 , V_75 , V_76 ;
F_2 ( V_11 , L_4 , V_9 -> V_9 ,
( long long unsigned ) V_73 , V_72 ) ;
V_74 = 0 ;
V_75 = 0 ;
V_76 = V_9 -> V_77 ? V_9 -> V_77 : V_9 -> V_78 -> V_79 - V_80 ;
do {
V_74 = F_40 ( V_9 , V_70 , V_71 , V_73 , V_72 ) ;
if ( V_74 <= 0 )
break;
if ( V_70 )
V_70 += V_74 ;
if ( V_71 )
V_71 += V_74 ;
V_73 += V_74 ;
V_72 -= V_74 ;
V_75 += V_74 ;
} while ( V_72 > 0 && V_74 == V_76 );
if ( V_74 < 0 )
V_75 = V_74 ;
return V_75 ;
}
T_2
F_41 ( struct V_2 * V_26 , char * V_70 , char T_3 * V_71 , T_4 V_72 ,
T_5 V_73 )
{
return F_39 ( V_26 -> V_13 , V_70 , V_71 , V_72 , V_73 ) ;
}
static T_2
F_42 ( struct V_2 * V_26 , char T_3 * V_71 , T_6 V_72 ,
T_7 * V_73 )
{
int V_62 ;
struct V_8 * V_9 ;
T_6 V_76 ;
F_2 ( V_11 , L_5 , V_72 , * V_73 ) ;
V_9 = V_26 -> V_13 ;
V_76 = V_9 -> V_77 ? V_9 -> V_77 : V_9 -> V_78 -> V_79 - V_80 ;
if ( V_72 > V_76 )
V_62 = F_41 ( V_26 , NULL , V_71 , V_72 , * V_73 ) ;
else
V_62 = F_40 ( V_9 , NULL , V_71 , * V_73 , V_72 ) ;
if ( V_62 > 0 )
* V_73 += V_62 ;
return V_62 ;
}
T_2
F_43 ( struct V_1 * V_1 , struct V_8 * V_9 ,
const char T_3 * V_70 , T_6 V_72 ,
T_7 * V_73 , int V_81 )
{
int V_74 ;
T_7 V_82 ;
T_6 V_75 = 0 ;
struct V_83 * V_78 ;
T_7 V_84 = * V_73 ;
unsigned long V_85 , V_86 ;
F_2 ( V_11 , L_6 , V_70 ,
( int ) V_72 , ( int ) * V_73 ) ;
V_78 = V_9 -> V_78 ;
do {
V_74 = F_44 ( V_9 , NULL , V_70 + V_75 , V_84 + V_75 , V_72 ) ;
if ( V_74 <= 0 )
break;
V_72 -= V_74 ;
V_75 += V_74 ;
} while ( V_72 > 0 );
if ( V_81 && ( V_75 > 0 ) ) {
V_85 = V_84 >> V_87 ;
V_86 = ( V_84 + V_75 - 1 ) >> V_87 ;
if ( V_1 -> V_35 && V_1 -> V_35 -> V_88 )
F_45 ( V_1 -> V_35 ,
V_85 , V_86 ) ;
* V_73 += V_75 ;
V_82 = F_46 ( V_1 ) ;
if ( * V_73 > V_82 ) {
F_47 ( V_1 , * V_73 - V_82 ) ;
F_13 ( V_1 , * V_73 ) ;
}
}
if ( V_74 < 0 )
return V_74 ;
return V_75 ;
}
static T_2
F_48 ( struct V_2 * V_26 , const char T_3 * V_70 ,
T_6 V_72 , T_7 * V_73 )
{
T_2 V_89 = 0 ;
T_7 V_84 = * V_73 ;
V_89 = F_49 ( V_26 , & V_84 , & V_72 , 0 ) ;
if ( V_89 )
goto V_42;
V_89 = - V_66 ;
if ( ( T_2 ) V_72 < 0 )
goto V_42;
V_89 = 0 ;
if ( ! V_72 )
goto V_42;
V_89 = F_43 ( V_26 -> V_14 . V_15 -> V_31 ,
V_26 -> V_13 ,
V_70 , V_72 , & V_84 , 1 ) ;
if ( V_89 > 0 )
* V_73 = V_84 ;
V_42:
return V_89 ;
}
static int F_50 ( struct V_2 * V_26 , int V_90 )
{
struct V_8 * V_9 ;
struct V_91 V_92 ;
int V_89 ;
F_2 ( V_11 , L_7 , V_26 , V_90 ) ;
V_9 = V_26 -> V_13 ;
F_51 ( & V_92 ) ;
V_89 = F_52 ( V_9 , & V_92 ) ;
return V_89 ;
}
int F_53 ( struct V_2 * V_26 , int V_90 )
{
struct V_8 * V_9 ;
int V_89 ;
F_2 ( V_11 , L_8 ,
V_26 , V_90 ) ;
V_9 = V_26 -> V_13 ;
V_89 = F_54 ( V_9 , V_90 ) ;
return V_89 ;
}
static int
F_55 ( struct V_2 * V_2 , struct V_93 * V_94 )
{
int V_89 ;
V_89 = F_56 ( V_2 , V_94 ) ;
if ( ! V_89 )
V_94 -> V_95 = & V_96 ;
return V_89 ;
}
static int
F_57 ( struct V_93 * V_94 , struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_99 * V_99 = V_98 -> V_99 ;
struct V_2 * V_26 = V_94 -> V_100 ;
struct V_1 * V_1 = V_26 -> V_14 . V_15 -> V_31 ;
F_2 ( V_11 , L_9 ,
V_99 , ( unsigned long ) V_26 -> V_13 ) ;
V_5 = F_3 ( V_1 ) ;
F_58 ( V_1 , V_99 ) ;
F_27 ( ! V_5 -> V_22 ) ;
F_59 ( V_99 ) ;
if ( V_99 -> V_101 != V_1 -> V_35 )
goto V_102;
return V_103 ;
V_102:
F_60 ( V_99 ) ;
return V_104 ;
}
static T_2
F_61 ( struct V_2 * V_26 , char T_3 * V_71 , T_6 V_72 ,
T_7 * V_105 )
{
T_7 V_76 , V_73 ;
struct V_1 * V_1 ;
struct V_106 * V_101 ;
V_73 = * V_105 ;
V_101 = V_26 -> V_107 ;
V_1 = V_101 -> V_108 ;
if ( ! V_72 )
return 0 ;
V_76 = F_46 ( V_1 ) ;
if ( V_73 < V_76 )
F_62 ( V_101 , V_73 ,
V_73 + V_72 - 1 ) ;
return F_42 ( V_26 , V_71 , V_72 , V_105 ) ;
}
static T_2
F_63 ( struct V_2 * V_26 , char T_3 * V_70 , T_6 V_72 ,
T_7 * V_73 )
{
if ( V_26 -> V_12 & V_109 )
return F_61 ( V_26 , V_70 , V_72 , V_73 ) ;
return F_64 ( V_26 , V_70 , V_72 , V_73 ) ;
}
static T_2
F_65 ( struct V_2 * V_26 , const char T_3 * V_70 ,
T_6 V_72 , T_7 * V_105 )
{
T_7 V_73 ;
T_2 V_89 ;
struct V_1 * V_1 ;
struct V_106 * V_101 ;
V_73 = * V_105 ;
V_101 = V_26 -> V_107 ;
V_1 = V_101 -> V_108 ;
if ( ! V_72 )
return 0 ;
F_15 ( & V_1 -> V_110 ) ;
V_89 = F_62 ( V_101 , V_73 ,
V_73 + V_72 - 1 ) ;
if ( V_89 )
goto V_111;
if ( V_101 -> V_88 ) {
T_8 V_85 = V_73 >> V_87 ;
T_8 V_86 = ( V_73 + V_72 - 1 ) >> V_87 ;
V_89 = F_45 ( V_101 ,
V_85 , V_86 ) ;
if ( V_89 ) {
if ( V_89 == - V_112 )
goto V_113;
goto V_111;
}
}
V_89 = F_48 ( V_26 , V_70 , V_72 , V_105 ) ;
V_111:
F_17 ( & V_1 -> V_110 ) ;
return V_89 ;
V_113:
F_17 ( & V_1 -> V_110 ) ;
return F_66 ( V_26 , V_70 , V_72 , V_105 ) ;
}
static T_2
F_67 ( struct V_2 * V_26 , const char T_3 * V_70 ,
T_6 V_72 , T_7 * V_73 )
{
if ( V_26 -> V_12 & V_109 )
return F_65 ( V_26 , V_70 , V_72 , V_73 ) ;
return F_66 ( V_26 , V_70 , V_72 , V_73 ) ;
}
