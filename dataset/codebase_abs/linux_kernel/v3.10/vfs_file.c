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
#ifdef F_18
if ( V_7 -> V_19 )
F_19 ( V_1 , V_2 ) ;
#endif
return 0 ;
V_23:
F_13 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
return V_3 ;
}
static int F_20 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
int V_28 = 0 ;
struct V_1 * V_1 = F_21 ( V_24 ) ;
F_2 ( V_11 , L_2 , V_24 , V_27 ) ;
if ( F_22 ( V_1 ) && V_27 -> V_29 != V_30 )
return - V_31 ;
if ( ( F_23 ( V_25 ) || F_24 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_25 ( V_1 -> V_32 ) ;
F_26 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
return V_28 ;
}
static int F_27 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
struct V_34 V_35 ;
struct V_8 * V_9 ;
T_1 V_36 ;
int V_28 = 0 ;
unsigned char V_29 ;
V_9 = V_24 -> V_13 ;
F_28 ( V_9 == NULL ) ;
if ( ( V_27 -> V_37 & V_38 ) != V_38 )
F_29 () ;
V_28 = F_30 ( V_24 , V_27 ) ;
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
V_35 . V_52 = F_31 () -> V_53 ;
if ( F_24 ( V_25 ) )
V_35 . V_54 = V_55 ;
for (; ; ) {
V_28 = F_32 ( V_9 , & V_35 , & V_36 ) ;
if ( V_28 < 0 )
break;
if ( V_36 != V_56 )
break;
if ( V_36 == V_56 && ! F_24 ( V_25 ) )
break;
if ( F_33 ( V_57 ) != 0 )
break;
}
switch ( V_36 ) {
case V_58 :
V_28 = 0 ;
break;
case V_56 :
V_28 = - V_59 ;
break;
case V_60 :
case V_61 :
V_28 = - V_31 ;
break;
default:
F_29 () ;
}
if ( V_28 < 0 && V_27 -> V_29 != V_30 ) {
V_29 = V_27 -> V_29 ;
V_27 -> V_29 = V_30 ;
V_28 = F_30 ( V_24 , V_27 ) ;
V_27 -> V_29 = V_29 ;
}
V_39:
return V_28 ;
}
static int F_34 ( struct V_2 * V_24 , struct V_26 * V_27 )
{
struct V_62 V_63 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
V_9 = V_24 -> V_13 ;
F_28 ( V_9 == NULL ) ;
F_35 ( V_24 , V_27 ) ;
if ( V_27 -> V_29 != V_30 )
return V_28 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . type = V_44 ;
V_63 . V_45 = V_27 -> V_46 ;
if ( V_27 -> V_47 == V_48 )
V_63 . V_49 = 0 ;
else
V_63 . V_49 = V_27 -> V_47 - V_27 -> V_46 + 1 ;
V_63 . V_50 = V_27 -> V_51 ;
V_63 . V_52 = F_31 () -> V_53 ;
V_28 = F_36 ( V_9 , & V_63 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_63 . type ) {
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
if ( V_63 . type != V_44 ) {
V_27 -> V_46 = V_63 . V_45 ;
if ( V_63 . V_49 == 0 )
V_27 -> V_47 = V_48 ;
else
V_27 -> V_47 = V_63 . V_45 + V_63 . V_49 - 1 ;
V_27 -> V_51 = V_63 . V_50 ;
}
return V_28 ;
}
static int F_37 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
struct V_1 * V_1 = F_21 ( V_24 ) ;
int V_64 = - V_31 ;
F_2 ( V_11 , L_3 ,
V_24 , V_25 , V_27 , V_24 -> V_14 . V_15 -> V_65 . V_66 ) ;
if ( F_22 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ( F_23 ( V_25 ) || F_24 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_25 ( V_1 -> V_32 ) ;
F_26 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
if ( F_23 ( V_25 ) || F_24 ( V_25 ) )
V_64 = F_27 ( V_24 , V_25 , V_27 ) ;
else if ( F_38 ( V_25 ) )
V_64 = F_34 ( V_24 , V_27 ) ;
else
V_64 = - V_68 ;
V_67:
return V_64 ;
}
static int F_39 ( struct V_2 * V_24 , int V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_1 = F_21 ( V_24 ) ;
int V_64 = - V_31 ;
F_2 ( V_11 , L_3 ,
V_24 , V_25 , V_27 , V_24 -> V_14 . V_15 -> V_65 . V_66 ) ;
if ( F_22 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ! ( V_27 -> V_37 & V_69 ) )
goto V_67;
if ( ( F_23 ( V_25 ) || F_24 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_25 ( V_1 -> V_32 ) ;
F_26 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
V_27 -> V_70 = ( V_71 ) V_24 ;
V_27 -> V_46 = 0 ;
V_27 -> V_47 = V_48 ;
V_27 -> V_37 |= V_38 ;
V_27 -> V_37 ^= V_69 ;
if ( F_23 ( V_25 ) | F_24 ( V_25 ) )
V_64 = F_27 ( V_24 , V_25 , V_27 ) ;
else
V_64 = - V_68 ;
V_67:
return V_64 ;
}
T_2
F_40 ( struct V_8 * V_9 , char * V_72 , char T_3 * V_73 , T_4 V_74 ,
T_5 V_75 )
{
int V_76 , V_77 , V_78 ;
F_2 ( V_11 , L_4 ,
V_9 -> V_9 , ( long long unsigned ) V_75 , V_74 ) ;
V_76 = 0 ;
V_77 = 0 ;
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_80 -> V_81 - V_82 ;
do {
V_76 = F_41 ( V_9 , V_72 , V_73 , V_75 , V_74 ) ;
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
F_42 ( struct V_2 * V_24 , char * V_72 , char T_3 * V_73 , T_4 V_74 ,
T_5 V_75 )
{
return F_40 ( V_24 -> V_13 , V_72 , V_73 , V_74 , V_75 ) ;
}
static T_2
F_43 ( struct V_2 * V_24 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_75 )
{
int V_64 ;
struct V_8 * V_9 ;
T_6 V_78 ;
F_2 ( V_11 , L_5 , V_74 , * V_75 ) ;
V_9 = V_24 -> V_13 ;
V_78 = V_9 -> V_79 ? V_9 -> V_79 : V_9 -> V_80 -> V_81 - V_82 ;
if ( V_74 > V_78 )
V_64 = F_42 ( V_24 , NULL , V_73 , V_74 , * V_75 ) ;
else
V_64 = F_41 ( V_9 , NULL , V_73 , * V_75 , V_74 ) ;
if ( V_64 > 0 )
* V_75 += V_64 ;
return V_64 ;
}
T_2
F_44 ( struct V_1 * V_1 , struct V_8 * V_9 ,
const char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 , int V_83 )
{
int V_76 ;
T_7 V_84 ;
T_6 V_77 = 0 ;
struct V_85 * V_80 ;
T_7 V_86 = * V_75 ;
unsigned long V_87 , V_88 ;
F_2 ( V_11 , L_6 ,
V_72 , ( int ) V_74 , ( int ) * V_75 ) ;
V_80 = V_9 -> V_80 ;
do {
V_76 = F_45 ( V_9 , NULL , V_72 + V_77 , V_86 + V_77 , V_74 ) ;
if ( V_76 <= 0 )
break;
V_74 -= V_76 ;
V_77 += V_76 ;
} while ( V_74 > 0 );
if ( V_83 && ( V_77 > 0 ) ) {
V_87 = V_86 >> V_89 ;
V_88 = ( V_86 + V_77 - 1 ) >> V_89 ;
if ( V_1 -> V_32 && V_1 -> V_32 -> V_90 )
F_46 ( V_1 -> V_32 ,
V_87 , V_88 ) ;
* V_75 += V_77 ;
V_84 = F_47 ( V_1 ) ;
if ( * V_75 > V_84 ) {
F_48 ( V_1 , * V_75 - V_84 ) ;
F_49 ( V_1 , * V_75 ) ;
}
}
if ( V_76 < 0 )
return V_76 ;
return V_77 ;
}
static T_2
F_50 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
T_2 V_91 = 0 ;
T_7 V_86 = * V_75 ;
V_91 = F_51 ( V_24 , & V_86 , & V_74 , 0 ) ;
if ( V_91 )
goto V_39;
V_91 = - V_68 ;
if ( ( T_2 ) V_74 < 0 )
goto V_39;
V_91 = 0 ;
if ( ! V_74 )
goto V_39;
V_91 = F_44 ( F_21 ( V_24 ) ,
V_24 -> V_13 ,
V_72 , V_74 , & V_86 , 1 ) ;
if ( V_91 > 0 )
* V_75 = V_86 ;
V_39:
return V_91 ;
}
static int F_52 ( struct V_2 * V_24 , T_7 V_45 , T_7 V_92 ,
int V_93 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_94 -> V_95 ;
struct V_96 V_97 ;
int V_91 ;
V_91 = F_53 ( V_1 -> V_32 , V_45 , V_92 ) ;
if ( V_91 )
return V_91 ;
F_15 ( & V_1 -> V_98 ) ;
F_2 ( V_11 , L_7 , V_24 , V_93 ) ;
V_9 = V_24 -> V_13 ;
F_54 ( & V_97 ) ;
V_91 = F_55 ( V_9 , & V_97 ) ;
F_17 ( & V_1 -> V_98 ) ;
return V_91 ;
}
int F_56 ( struct V_2 * V_24 , T_7 V_45 , T_7 V_92 ,
int V_93 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_94 -> V_95 ;
int V_91 ;
V_91 = F_53 ( V_1 -> V_32 , V_45 , V_92 ) ;
if ( V_91 )
return V_91 ;
F_15 ( & V_1 -> V_98 ) ;
F_2 ( V_11 , L_7 , V_24 , V_93 ) ;
V_9 = V_24 -> V_13 ;
V_91 = F_57 ( V_9 , V_93 ) ;
F_17 ( & V_1 -> V_98 ) ;
return V_91 ;
}
static int
F_58 ( struct V_2 * V_2 , struct V_99 * V_100 )
{
int V_91 ;
V_91 = F_59 ( V_2 , V_100 ) ;
if ( ! V_91 )
V_100 -> V_101 = & V_102 ;
return V_91 ;
}
static int
F_60 ( struct V_99 * V_100 , struct V_103 * V_104 )
{
struct V_4 * V_5 ;
struct V_105 * V_105 = V_104 -> V_105 ;
struct V_2 * V_24 = V_100 -> V_106 ;
struct V_1 * V_1 = F_21 ( V_24 ) ;
F_2 ( V_11 , L_8 ,
V_105 , ( unsigned long ) V_24 -> V_13 ) ;
F_61 ( V_24 ) ;
V_5 = F_3 ( V_1 ) ;
F_62 ( V_1 , V_105 ) ;
F_28 ( ! V_5 -> V_20 ) ;
F_63 ( V_105 ) ;
if ( V_105 -> V_107 != V_1 -> V_32 )
goto V_108;
F_64 ( V_105 ) ;
return V_109 ;
V_108:
F_65 ( V_105 ) ;
return V_110 ;
}
static T_2
F_66 ( struct V_2 * V_24 , char T_3 * V_73 , T_6 V_74 ,
T_7 * V_111 )
{
T_7 V_78 , V_75 ;
struct V_1 * V_1 ;
struct V_112 * V_107 ;
V_75 = * V_111 ;
V_107 = V_24 -> V_94 ;
V_1 = V_107 -> V_95 ;
if ( ! V_74 )
return 0 ;
V_78 = F_47 ( V_1 ) ;
if ( V_75 < V_78 )
F_53 ( V_107 , V_75 ,
V_75 + V_74 - 1 ) ;
return F_43 ( V_24 , V_73 , V_74 , V_111 ) ;
}
static T_2
F_67 ( struct V_2 * V_24 , char T_3 * V_72 , T_6 V_74 ,
T_7 * V_75 )
{
if ( V_24 -> V_12 & V_113 )
return F_66 ( V_24 , V_72 , V_74 , V_75 ) ;
return F_68 ( V_24 , V_72 , V_74 , V_75 ) ;
}
static T_2
F_69 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_111 )
{
T_7 V_75 ;
T_2 V_91 ;
struct V_1 * V_1 ;
struct V_112 * V_107 ;
V_75 = * V_111 ;
V_107 = V_24 -> V_94 ;
V_1 = V_107 -> V_95 ;
if ( ! V_74 )
return 0 ;
F_15 ( & V_1 -> V_98 ) ;
V_91 = F_53 ( V_107 , V_75 ,
V_75 + V_74 - 1 ) ;
if ( V_91 )
goto V_114;
if ( V_107 -> V_90 ) {
T_8 V_87 = V_75 >> V_89 ;
T_8 V_88 = ( V_75 + V_74 - 1 ) >> V_89 ;
V_91 = F_46 ( V_107 ,
V_87 , V_88 ) ;
if ( V_91 ) {
if ( V_91 == - V_115 )
goto V_116;
goto V_114;
}
}
V_91 = F_50 ( V_24 , V_72 , V_74 , V_111 ) ;
V_114:
F_17 ( & V_1 -> V_98 ) ;
return V_91 ;
V_116:
F_17 ( & V_1 -> V_98 ) ;
return F_70 ( V_24 , V_72 , V_74 , V_111 ) ;
}
static T_2
F_71 ( struct V_2 * V_24 , const char T_3 * V_72 ,
T_6 V_74 , T_7 * V_75 )
{
if ( V_24 -> V_12 & V_113 )
return F_69 ( V_24 , V_72 , V_74 , V_75 ) ;
return F_70 ( V_24 , V_72 , V_74 , V_75 ) ;
}
