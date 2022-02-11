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
T_1 V_38 = V_39 ;
int V_30 = 0 ;
unsigned char V_31 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
if ( ( V_29 -> V_40 & V_41 ) != V_41 )
F_28 () ;
V_30 = F_29 ( V_26 , V_29 ) ;
if ( V_30 < 0 )
goto V_42;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
switch ( V_29 -> V_31 ) {
case V_43 :
V_37 . type = V_44 ;
break;
case V_45 :
V_37 . type = V_46 ;
break;
case V_32 :
V_37 . type = V_47 ;
break;
}
V_37 . V_48 = V_29 -> V_49 ;
if ( V_29 -> V_50 == V_51 )
V_37 . V_52 = 0 ;
else
V_37 . V_52 = V_29 -> V_50 - V_29 -> V_49 + 1 ;
V_37 . V_53 = V_29 -> V_54 ;
V_37 . V_55 = V_9 -> V_56 -> V_57 ;
if ( F_23 ( V_27 ) )
V_37 . V_58 = V_59 ;
for (; ; ) {
V_30 = F_30 ( V_9 , & V_37 , & V_38 ) ;
if ( V_30 < 0 )
goto V_60;
if ( V_38 != V_61 )
break;
if ( V_38 == V_61 && ! F_23 ( V_27 ) )
break;
if ( F_31 ( V_62 ) != 0 )
break;
}
switch ( V_38 ) {
case V_63 :
V_30 = 0 ;
break;
case V_61 :
V_30 = - V_64 ;
break;
default:
F_32 ( 1 , L_3 , V_38 ) ;
case V_39 :
case V_65 :
V_30 = - V_33 ;
break;
}
V_60:
if ( V_30 < 0 && V_29 -> V_31 != V_32 ) {
V_31 = V_29 -> V_31 ;
V_29 -> V_31 = V_32 ;
F_29 ( V_26 , V_29 ) ;
V_29 -> V_31 = V_31 ;
}
V_42:
return V_30 ;
}
static int F_33 ( struct V_2 * V_26 , struct V_28 * V_29 )
{
struct V_66 V_67 ;
struct V_8 * V_9 ;
int V_30 = 0 ;
V_9 = V_26 -> V_13 ;
F_27 ( V_9 == NULL ) ;
F_34 ( V_26 , V_29 ) ;
if ( V_29 -> V_31 != V_32 )
return V_30 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . type = V_47 ;
V_67 . V_48 = V_29 -> V_49 ;
if ( V_29 -> V_50 == V_51 )
V_67 . V_52 = 0 ;
else
V_67 . V_52 = V_29 -> V_50 - V_29 -> V_49 + 1 ;
V_67 . V_53 = V_29 -> V_54 ;
V_67 . V_55 = V_9 -> V_56 -> V_57 ;
V_30 = F_35 ( V_9 , & V_67 ) ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_67 . type ) {
case V_44 :
V_29 -> V_31 = V_43 ;
break;
case V_46 :
V_29 -> V_31 = V_45 ;
break;
case V_47 :
V_29 -> V_31 = V_32 ;
break;
}
if ( V_67 . type != V_47 ) {
V_29 -> V_49 = V_67 . V_48 ;
if ( V_67 . V_52 == 0 )
V_29 -> V_50 = V_51 ;
else
V_29 -> V_50 = V_67 . V_48 + V_67 . V_52 - 1 ;
V_29 -> V_54 = V_67 . V_53 ;
}
F_36 ( V_67 . V_55 ) ;
return V_30 ;
}
static int F_37 ( struct V_2 * V_26 , int V_27 , struct V_28 * V_29 )
{
struct V_1 * V_1 = F_20 ( V_26 ) ;
int V_68 = - V_33 ;
F_2 ( V_11 , L_4 ,
V_26 , V_27 , V_29 , V_26 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_31 != V_32 )
goto V_69;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_31 != V_32 ) {
F_24 ( V_1 -> V_34 ) ;
F_25 ( & V_1 -> V_35 , 0 , - 1 ) ;
}
if ( F_22 ( V_27 ) || F_23 ( V_27 ) )
V_68 = F_26 ( V_26 , V_27 , V_29 ) ;
else if ( F_38 ( V_27 ) )
V_68 = F_33 ( V_26 , V_29 ) ;
else
V_68 = - V_70 ;
V_69:
return V_68 ;
}
static int F_39 ( struct V_2 * V_26 , int V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_1 = F_20 ( V_26 ) ;
int V_68 = - V_33 ;
F_2 ( V_11 , L_4 ,
V_26 , V_27 , V_29 , V_26 ) ;
if ( F_21 ( V_1 ) && V_29 -> V_31 != V_32 )
goto V_69;
if ( ! ( V_29 -> V_40 & V_71 ) )
goto V_69;
if ( ( F_22 ( V_27 ) || F_23 ( V_27 ) ) && V_29 -> V_31 != V_32 ) {
F_24 ( V_1 -> V_34 ) ;
F_25 ( & V_1 -> V_35 , 0 , - 1 ) ;
}
V_29 -> V_40 |= V_41 ;
V_29 -> V_40 ^= V_71 ;
if ( F_22 ( V_27 ) | F_23 ( V_27 ) )
V_68 = F_26 ( V_26 , V_27 , V_29 ) ;
else
V_68 = - V_70 ;
V_69:
return V_68 ;
}
static T_2
F_40 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
struct V_8 * V_9 = V_73 -> V_76 -> V_13 ;
int V_68 , V_3 = 0 ;
F_2 ( V_11 , L_5 ,
F_41 ( V_75 ) , V_73 -> V_77 ) ;
V_68 = F_42 ( V_9 , V_73 -> V_77 , V_75 , & V_3 ) ;
if ( ! V_68 )
return V_3 ;
V_73 -> V_77 += V_68 ;
return V_68 ;
}
static T_2
F_43 ( struct V_72 * V_73 , struct V_74 * V_78 )
{
struct V_2 * V_2 = V_73 -> V_76 ;
T_2 V_79 ;
T_3 V_80 ;
int V_3 = 0 ;
V_79 = F_44 ( V_73 , V_78 ) ;
if ( V_79 <= 0 )
return V_79 ;
V_80 = V_73 -> V_77 ;
V_79 = F_45 ( V_2 -> V_13 , V_73 -> V_77 , V_78 , & V_3 ) ;
if ( V_79 > 0 ) {
struct V_1 * V_1 = F_20 ( V_2 ) ;
T_3 V_81 ;
unsigned long V_82 , V_83 ;
V_82 = V_80 >> V_84 ;
V_83 = ( V_80 + V_79 - 1 ) >> V_84 ;
if ( V_1 -> V_34 && V_1 -> V_34 -> V_85 )
F_46 ( V_1 -> V_34 ,
V_82 , V_83 ) ;
V_73 -> V_77 += V_79 ;
V_81 = F_47 ( V_1 ) ;
if ( V_73 -> V_77 > V_81 ) {
F_48 ( V_1 , V_73 -> V_77 - V_81 ) ;
F_49 ( V_1 , V_73 -> V_77 ) ;
}
return V_79 ;
}
return V_3 ;
}
static int F_50 ( struct V_2 * V_26 , T_3 V_48 , T_3 V_86 ,
int V_87 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_88 -> V_89 ;
struct V_90 V_91 ;
int V_79 ;
V_79 = F_51 ( V_1 -> V_34 , V_48 , V_86 ) ;
if ( V_79 )
return V_79 ;
F_15 ( & V_1 -> V_92 ) ;
F_2 ( V_11 , L_6 , V_26 , V_87 ) ;
V_9 = V_26 -> V_13 ;
F_52 ( & V_91 ) ;
V_79 = F_53 ( V_9 , & V_91 ) ;
F_17 ( & V_1 -> V_92 ) ;
return V_79 ;
}
int F_54 ( struct V_2 * V_26 , T_3 V_48 , T_3 V_86 ,
int V_87 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_26 -> V_88 -> V_89 ;
int V_79 ;
V_79 = F_51 ( V_1 -> V_34 , V_48 , V_86 ) ;
if ( V_79 )
return V_79 ;
F_15 ( & V_1 -> V_92 ) ;
F_2 ( V_11 , L_6 , V_26 , V_87 ) ;
V_9 = V_26 -> V_13 ;
V_79 = F_55 ( V_9 , V_87 ) ;
F_17 ( & V_1 -> V_92 ) ;
return V_79 ;
}
static int
F_56 ( struct V_2 * V_26 , struct V_93 * V_94 )
{
int V_79 ;
V_79 = F_57 ( V_26 , V_94 ) ;
if ( ! V_79 )
V_94 -> V_95 = & V_96 ;
return V_79 ;
}
static int
F_58 ( struct V_2 * V_26 , struct V_93 * V_94 )
{
int V_79 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
struct V_8 * V_9 ;
V_1 = F_20 ( V_26 ) ;
V_5 = F_3 ( V_1 ) ;
F_15 ( & V_5 -> V_18 ) ;
if ( ! V_5 -> V_22 &&
( V_94 -> V_97 & V_98 ) ) {
V_9 = F_16 ( V_26 -> V_14 . V_15 ) ;
if ( F_10 ( V_9 ) ) {
V_79 = F_11 ( V_9 ) ;
F_17 ( & V_5 -> V_18 ) ;
return V_79 ;
}
V_5 -> V_22 = ( void * ) V_9 ;
}
F_17 ( & V_5 -> V_18 ) ;
V_79 = F_57 ( V_26 , V_94 ) ;
if ( ! V_79 )
V_94 -> V_95 = & V_99 ;
return V_79 ;
}
static int
F_59 ( struct V_93 * V_94 , struct V_100 * V_101 )
{
struct V_4 * V_5 ;
struct V_102 * V_102 = V_101 -> V_102 ;
struct V_2 * V_26 = V_94 -> V_103 ;
struct V_1 * V_1 = F_20 ( V_26 ) ;
F_2 ( V_11 , L_7 ,
V_102 , ( unsigned long ) V_26 -> V_13 ) ;
F_60 ( V_26 ) ;
V_5 = F_3 ( V_1 ) ;
F_61 ( V_1 , V_102 ) ;
F_27 ( ! V_5 -> V_22 ) ;
F_62 ( V_102 ) ;
if ( V_102 -> V_104 != V_1 -> V_34 )
goto V_60;
F_63 ( V_102 ) ;
return V_105 ;
V_60:
F_64 ( V_102 ) ;
return V_106 ;
}
static T_2
F_65 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
return F_40 ( V_73 , V_75 ) ;
}
static T_2
F_66 ( struct V_72 * V_73 , struct V_74 * V_78 )
{
return F_43 ( V_73 , V_78 ) ;
}
static void F_67 ( struct V_93 * V_94 )
{
struct V_1 * V_1 ;
struct V_107 V_108 = {
. V_109 = V_110 ,
. V_111 = V_112 ,
. V_113 = V_94 -> V_114 * V_115 ,
. V_116 = V_94 -> V_114 * V_115 +
( V_94 -> V_117 - V_94 -> V_118 - 1 ) ,
} ;
F_2 ( V_11 , L_8 , V_94 ) ;
V_1 = F_20 ( V_94 -> V_103 ) ;
if ( ! F_68 ( V_1 -> V_34 ) )
V_108 . V_109 = 0 ;
F_69 () ;
F_70 ( V_1 , & V_108 ) ;
}
