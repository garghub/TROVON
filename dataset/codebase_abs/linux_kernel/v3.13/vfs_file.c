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
if ( V_7 -> V_19 && ! V_5 -> V_20 &&
( ( V_2 -> V_12 & V_21 ) != V_22 ) ) {
V_9 = F_16 ( V_2 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) ) {
V_3 = F_11 ( V_9 ) ;
F_17 ( & V_5 -> V_18 ) ;
goto V_23;
}
V_5 -> V_20 = ( void * ) V_9 ;
}
F_17 ( & V_5 -> V_18 ) ;
if ( V_7 -> V_19 )
F_18 ( V_1 , V_2 ) ;
return 0 ;
V_23:
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return V_3 ;
}
static int F_19 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
int V_28 = 0 ;
struct V_1 * V_1 = F_20 ( V_24 ) ;
F_2 ( V_11 , L_2 , V_24 , V_27 ) ;
if ( F_21 ( V_1 ) && V_27 -> V_29 != V_30 )
return - V_31 ;
if ( ( F_22 ( V_25 ) || F_23 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_24 ( V_1 -> V_32 ) ;
F_25 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
return V_28 ;
}
static int F_26 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
struct V_34 V_35 ;
struct V_8 * V_9 ;
T_1 V_36 ;
int V_28 = 0 ;
unsigned char V_29 ;
V_9 = V_24 -> V_13 ;
F_27 ( V_9 == NULL ) ;
if ( ( V_27 -> V_37 & V_38 ) != V_38 )
F_28 () ;
V_28 = F_29 ( V_24 , V_27 ) ;
if ( V_28 < 0 )
goto V_39;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
switch ( V_27 -> V_29 ) {
case V_40 :
V_35 . type = V_41 ;
break;
case V_42 :
V_35 . type = V_43 ;
break;
case V_30 :
V_35 . type = V_44 ;
break;
}
V_35 . V_45 = V_27 -> V_46 ;
if ( V_27 -> V_47 == V_48 )
V_35 . V_49 = 0 ;
else
V_35 . V_49 = V_27 -> V_47 - V_27 -> V_46 + 1 ;
V_35 . V_50 = V_27 -> V_51 ;
V_35 . V_52 = V_9 -> V_53 -> V_54 ;
if ( F_23 ( V_25 ) )
V_35 . V_55 = V_56 ;
for (; ; ) {
V_28 = F_30 ( V_9 , & V_35 , & V_36 ) ;
if ( V_28 < 0 )
break;
if ( V_36 != V_57 )
break;
if ( V_36 == V_57 && ! F_23 ( V_25 ) )
break;
if ( F_31 ( V_58 ) != 0 )
break;
}
switch ( V_36 ) {
case V_59 :
V_28 = 0 ;
break;
case V_57 :
V_28 = - V_60 ;
break;
case V_61 :
case V_62 :
V_28 = - V_31 ;
break;
default:
F_28 () ;
}
if ( V_28 < 0 && V_27 -> V_29 != V_30 ) {
V_29 = V_27 -> V_29 ;
V_27 -> V_29 = V_30 ;
V_28 = F_29 ( V_24 , V_27 ) ;
V_27 -> V_29 = V_29 ;
}
V_39:
return V_28 ;
}
static int F_32 ( struct V_2 * V_24 , struct V_26 * V_27 )
{
struct V_63 V_64 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
V_9 = V_24 -> V_13 ;
F_27 ( V_9 == NULL ) ;
F_33 ( V_24 , V_27 ) ;
if ( V_27 -> V_29 != V_30 )
return V_28 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . type = V_44 ;
V_64 . V_45 = V_27 -> V_46 ;
if ( V_27 -> V_47 == V_48 )
V_64 . V_49 = 0 ;
else
V_64 . V_49 = V_27 -> V_47 - V_27 -> V_46 + 1 ;
V_64 . V_50 = V_27 -> V_51 ;
V_64 . V_52 = V_9 -> V_53 -> V_54 ;
V_28 = F_34 ( V_9 , & V_64 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_64 . type ) {
case V_41 :
V_27 -> V_29 = V_40 ;
break;
case V_43 :
V_27 -> V_29 = V_42 ;
break;
case V_44 :
V_27 -> V_29 = V_30 ;
break;
}
if ( V_64 . type != V_44 ) {
V_27 -> V_46 = V_64 . V_45 ;
if ( V_64 . V_49 == 0 )
V_27 -> V_47 = V_48 ;
else
V_27 -> V_47 = V_64 . V_45 + V_64 . V_49 - 1 ;
V_27 -> V_51 = V_64 . V_50 ;
}
return V_28 ;
}
static int F_35 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
struct V_1 * V_1 = F_20 ( V_24 ) ;
int V_65 = - V_31 ;
F_2 ( V_11 , L_3 ,
V_24 , V_25 , V_27 , V_24 -> V_14 . V_15 -> V_66 . V_54 ) ;
if ( F_21 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ( F_22 ( V_25 ) || F_23 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_24 ( V_1 -> V_32 ) ;
F_25 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
if ( F_22 ( V_25 ) || F_23 ( V_25 ) )
V_65 = F_26 ( V_24 , V_25 , V_27 ) ;
else if ( F_36 ( V_25 ) )
V_65 = F_32 ( V_24 , V_27 ) ;
else
V_65 = - V_68 ;
V_67:
return V_65 ;
}
static int F_37 ( struct V_2 * V_24 , int V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_1 = F_20 ( V_24 ) ;
int V_65 = - V_31 ;
F_2 ( V_11 , L_3 ,
V_24 , V_25 , V_27 , V_24 -> V_14 . V_15 -> V_66 . V_54 ) ;
if ( F_21 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ! ( V_27 -> V_37 & V_69 ) )
goto V_67;
if ( ( F_22 ( V_25 ) || F_23 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_24 ( V_1 -> V_32 ) ;
F_25 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
V_27 -> V_70 = ( V_71 ) V_24 ;
V_27 -> V_46 = 0 ;
V_27 -> V_47 = V_48 ;
V_27 -> V_37 |= V_38 ;
V_27 -> V_37 ^= V_69 ;
if ( F_22 ( V_25 ) | F_23 ( V_25 ) )
V_65 = F_26 ( V_24 , V_25 , V_27 ) ;
else
V_65 = - V_68 ;
V_67:
return V_65 ;
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
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_53 -> V_80 - V_81 ;
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
F_40 ( struct V_2 * V_24 , char * V_72 , char T_3 * V_73 , T_4 V_74 ,
T_5 V_75 )
{
return F_38 ( V_24 -> V_13 , V_72 , V_73 , V_74 , V_75 ) ;
}
static T_2
F_41 ( struct V_2 * V_24 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_75 )
{
int V_65 ;
struct V_8 * V_9 ;
T_6 V_78 ;
F_2 ( V_11 , L_5 , V_74 , * V_75 ) ;
V_9 = V_24 -> V_13 ;
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_53 -> V_80 - V_81 ;
if ( V_74 > V_78 )
V_65 = F_40 ( V_24 , NULL , V_73 , V_74 , * V_75 ) ;
else
V_65 = F_39 ( V_9 , NULL , V_73 , * V_75 , V_74 ) ;
if ( V_65 > 0 )
* V_75 += V_65 ;
return V_65 ;
}
T_2
F_42 ( struct V_1 * V_1 , struct V_8 * V_9 ,
const char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 , int V_82 )
{
int V_76 ;
T_7 V_83 ;
T_6 V_77 = 0 ;
struct V_84 * V_53 ;
T_7 V_85 = * V_75 ;
unsigned long V_86 , V_87 ;
F_2 ( V_11 , L_6 ,
V_72 , ( int ) V_74 , ( int ) * V_75 ) ;
V_53 = V_9 -> V_53 ;
do {
V_76 = F_43 ( V_9 , NULL , V_72 + V_77 , V_85 + V_77 , V_74 ) ;
if ( V_76 <= 0 )
break;
V_74 -= V_76 ;
V_77 += V_76 ;
} while ( V_74 > 0 );
if ( V_82 && ( V_77 > 0 ) ) {
V_86 = V_85 >> V_88 ;
V_87 = ( V_85 + V_77 - 1 ) >> V_88 ;
if ( V_1 -> V_32 && V_1 -> V_32 -> V_89 )
F_44 ( V_1 -> V_32 ,
V_86 , V_87 ) ;
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
F_48 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
T_2 V_90 = 0 ;
T_7 V_85 = * V_75 ;
V_90 = F_49 ( V_24 , & V_85 , & V_74 , 0 ) ;
if ( V_90 )
goto V_39;
V_90 = - V_68 ;
if ( ( T_2 ) V_74 < 0 )
goto V_39;
V_90 = 0 ;
if ( ! V_74 )
goto V_39;
V_90 = F_42 ( F_20 ( V_24 ) ,
V_24 -> V_13 ,
V_72 , V_74 , & V_85 , 1 ) ;
if ( V_90 > 0 )
* V_75 = V_85 ;
V_39:
return V_90 ;
}
static int F_50 ( struct V_2 * V_24 , T_7 V_45 , T_7 V_91 ,
int V_92 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_93 -> V_94 ;
struct V_95 V_96 ;
int V_90 ;
V_90 = F_51 ( V_1 -> V_32 , V_45 , V_91 ) ;
if ( V_90 )
return V_90 ;
F_15 ( & V_1 -> V_97 ) ;
F_2 ( V_11 , L_7 , V_24 , V_92 ) ;
V_9 = V_24 -> V_13 ;
F_52 ( & V_96 ) ;
V_90 = F_53 ( V_9 , & V_96 ) ;
F_17 ( & V_1 -> V_97 ) ;
return V_90 ;
}
int F_54 ( struct V_2 * V_24 , T_7 V_45 , T_7 V_91 ,
int V_92 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_93 -> V_94 ;
int V_90 ;
V_90 = F_51 ( V_1 -> V_32 , V_45 , V_91 ) ;
if ( V_90 )
return V_90 ;
F_15 ( & V_1 -> V_97 ) ;
F_2 ( V_11 , L_7 , V_24 , V_92 ) ;
V_9 = V_24 -> V_13 ;
V_90 = F_55 ( V_9 , V_92 ) ;
F_17 ( & V_1 -> V_97 ) ;
return V_90 ;
}
static int
F_56 ( struct V_2 * V_2 , struct V_98 * V_99 )
{
int V_90 ;
V_90 = F_57 ( V_2 , V_99 ) ;
if ( ! V_90 )
V_99 -> V_100 = & V_101 ;
return V_90 ;
}
static int
F_58 ( struct V_98 * V_99 , struct V_102 * V_103 )
{
struct V_4 * V_5 ;
struct V_104 * V_104 = V_103 -> V_104 ;
struct V_2 * V_24 = V_99 -> V_105 ;
struct V_1 * V_1 = F_20 ( V_24 ) ;
F_2 ( V_11 , L_8 ,
V_104 , ( unsigned long ) V_24 -> V_13 ) ;
F_59 ( V_24 ) ;
V_5 = F_3 ( V_1 ) ;
F_60 ( V_1 , V_104 ) ;
F_27 ( ! V_5 -> V_20 ) ;
F_61 ( V_104 ) ;
if ( V_104 -> V_106 != V_1 -> V_32 )
goto V_107;
F_62 ( V_104 ) ;
return V_108 ;
V_107:
F_63 ( V_104 ) ;
return V_109 ;
}
static T_2
F_64 ( struct V_2 * V_24 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_110 )
{
T_7 V_78 , V_75 ;
struct V_1 * V_1 ;
struct V_111 * V_106 ;
V_75 = * V_110 ;
V_106 = V_24 -> V_93 ;
V_1 = V_106 -> V_94 ;
if ( ! V_74 )
return 0 ;
V_78 = F_45 ( V_1 ) ;
if ( V_75 < V_78 )
F_51 ( V_106 , V_75 ,
V_75 + V_74 - 1 ) ;
return F_41 ( V_24 , V_73 , V_74 , V_110 ) ;
}
static T_2
F_65 ( struct V_2 * V_24 , char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 )
{
if ( V_24 -> V_12 & V_112 )
return F_64 ( V_24 , V_72 , V_74 , V_75 ) ;
return F_66 ( V_24 , V_72 , V_74 , V_75 ) ;
}
static T_2
F_67 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_110 )
{
T_7 V_75 ;
T_2 V_90 ;
struct V_1 * V_1 ;
struct V_111 * V_106 ;
V_75 = * V_110 ;
V_106 = V_24 -> V_93 ;
V_1 = V_106 -> V_94 ;
if ( ! V_74 )
return 0 ;
F_15 ( & V_1 -> V_97 ) ;
V_90 = F_51 ( V_106 , V_75 ,
V_75 + V_74 - 1 ) ;
if ( V_90 )
goto V_113;
if ( V_106 -> V_89 ) {
T_8 V_86 = V_75 >> V_88 ;
T_8 V_87 = ( V_75 + V_74 - 1 ) >> V_88 ;
V_90 = F_44 ( V_106 ,
V_86 , V_87 ) ;
if ( V_90 ) {
if ( V_90 == - V_114 )
goto V_115;
goto V_113;
}
}
V_90 = F_48 ( V_24 , V_72 , V_74 , V_110 ) ;
V_113:
F_17 ( & V_1 -> V_97 ) ;
return V_90 ;
V_115:
F_17 ( & V_1 -> V_97 ) ;
return F_68 ( V_24 , V_72 , V_74 , V_110 ) ;
}
static T_2
F_69 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
if ( V_24 -> V_12 & V_112 )
return F_67 ( V_24 , V_72 , V_74 , V_75 ) ;
return F_68 ( V_24 , V_72 , V_74 , V_75 ) ;
}
