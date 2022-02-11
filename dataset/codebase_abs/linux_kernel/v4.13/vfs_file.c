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
V_9 = F_9 ( F_10 ( V_2 ) ) ;
if ( F_11 ( V_9 ) )
return F_12 ( V_9 ) ;
V_3 = F_13 ( V_9 , V_10 ) ;
if ( V_3 < 0 ) {
F_14 ( V_9 ) ;
return V_3 ;
}
if ( ( V_2 -> V_12 & V_14 ) &&
( ! F_8 ( V_7 ) && ! F_5 ( V_7 ) ) )
F_15 ( V_2 , 0 , V_15 ) ;
}
V_2 -> V_13 = V_9 ;
F_16 ( & V_5 -> V_16 ) ;
if ( ( V_7 -> V_17 == V_18 || V_7 -> V_17 == V_19 ) &&
! V_5 -> V_20 &&
( ( V_2 -> V_12 & V_21 ) != V_22 ) ) {
V_9 = F_17 ( F_10 ( V_2 ) ) ;
if ( F_11 ( V_9 ) ) {
V_3 = F_12 ( V_9 ) ;
F_18 ( & V_5 -> V_16 ) ;
goto V_23;
}
V_5 -> V_20 = ( void * ) V_9 ;
}
F_18 ( & V_5 -> V_16 ) ;
if ( V_7 -> V_17 == V_18 || V_7 -> V_17 == V_19 )
F_19 ( V_1 , V_2 ) ;
return 0 ;
V_23:
F_14 ( V_2 -> V_13 ) ;
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
T_1 V_36 = V_37 ;
int V_28 = 0 ;
unsigned char V_29 ;
V_9 = V_24 -> V_13 ;
F_28 ( V_9 == NULL ) ;
if ( ( V_27 -> V_38 & V_39 ) != V_39 )
F_29 () ;
V_28 = F_30 ( V_24 , V_27 ) ;
if ( V_28 < 0 )
goto V_40;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
switch ( V_27 -> V_29 ) {
case V_41 :
V_35 . type = V_42 ;
break;
case V_43 :
V_35 . type = V_44 ;
break;
case V_30 :
V_35 . type = V_45 ;
break;
}
V_35 . V_46 = V_27 -> V_47 ;
if ( V_27 -> V_48 == V_49 )
V_35 . V_50 = 0 ;
else
V_35 . V_50 = V_27 -> V_48 - V_27 -> V_47 + 1 ;
V_35 . V_51 = V_27 -> V_52 ;
V_35 . V_53 = V_9 -> V_54 -> V_55 ;
if ( F_24 ( V_25 ) )
V_35 . V_56 = V_57 ;
for (; ; ) {
V_28 = F_31 ( V_9 , & V_35 , & V_36 ) ;
if ( V_28 < 0 )
goto V_58;
if ( V_36 != V_59 )
break;
if ( V_36 == V_59 && ! F_24 ( V_25 ) )
break;
if ( F_32 ( V_60 ) != 0 )
break;
}
switch ( V_36 ) {
case V_61 :
V_28 = 0 ;
break;
case V_59 :
V_28 = - V_62 ;
break;
default:
F_33 ( 1 , L_3 , V_36 ) ;
case V_37 :
case V_63 :
V_28 = - V_31 ;
break;
}
V_58:
if ( V_28 < 0 && V_27 -> V_29 != V_30 ) {
V_29 = V_27 -> V_29 ;
V_27 -> V_29 = V_30 ;
F_30 ( V_24 , V_27 ) ;
V_27 -> V_29 = V_29 ;
}
V_40:
return V_28 ;
}
static int F_34 ( struct V_2 * V_24 , struct V_26 * V_27 )
{
struct V_64 V_65 ;
struct V_8 * V_9 ;
int V_28 = 0 ;
V_9 = V_24 -> V_13 ;
F_28 ( V_9 == NULL ) ;
F_35 ( V_24 , V_27 ) ;
if ( V_27 -> V_29 != V_30 )
return V_28 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . type = V_45 ;
V_65 . V_46 = V_27 -> V_47 ;
if ( V_27 -> V_48 == V_49 )
V_65 . V_50 = 0 ;
else
V_65 . V_50 = V_27 -> V_48 - V_27 -> V_47 + 1 ;
V_65 . V_51 = V_27 -> V_52 ;
V_65 . V_53 = V_9 -> V_54 -> V_55 ;
V_28 = F_36 ( V_9 , & V_65 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_65 . type ) {
case V_42 :
V_27 -> V_29 = V_41 ;
break;
case V_44 :
V_27 -> V_29 = V_43 ;
break;
case V_45 :
V_27 -> V_29 = V_30 ;
break;
}
if ( V_65 . type != V_45 ) {
V_27 -> V_47 = V_65 . V_46 ;
if ( V_65 . V_50 == 0 )
V_27 -> V_48 = V_49 ;
else
V_27 -> V_48 = V_65 . V_46 + V_65 . V_50 - 1 ;
V_27 -> V_52 = V_65 . V_51 ;
}
F_37 ( V_65 . V_53 ) ;
return V_28 ;
}
static int F_38 ( struct V_2 * V_24 , int V_25 , struct V_26 * V_27 )
{
struct V_1 * V_1 = F_21 ( V_24 ) ;
int V_66 = - V_31 ;
F_2 ( V_11 , L_4 ,
V_24 , V_25 , V_27 , V_24 ) ;
if ( F_22 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ( F_23 ( V_25 ) || F_24 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_25 ( V_1 -> V_32 ) ;
F_26 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
if ( F_23 ( V_25 ) || F_24 ( V_25 ) )
V_66 = F_27 ( V_24 , V_25 , V_27 ) ;
else if ( F_39 ( V_25 ) )
V_66 = F_34 ( V_24 , V_27 ) ;
else
V_66 = - V_68 ;
V_67:
return V_66 ;
}
static int F_40 ( struct V_2 * V_24 , int V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_1 = F_21 ( V_24 ) ;
int V_66 = - V_31 ;
F_2 ( V_11 , L_4 ,
V_24 , V_25 , V_27 , V_24 ) ;
if ( F_22 ( V_1 ) && V_27 -> V_29 != V_30 )
goto V_67;
if ( ! ( V_27 -> V_38 & V_69 ) )
goto V_67;
if ( ( F_23 ( V_25 ) || F_24 ( V_25 ) ) && V_27 -> V_29 != V_30 ) {
F_25 ( V_1 -> V_32 ) ;
F_26 ( & V_1 -> V_33 , 0 , - 1 ) ;
}
V_27 -> V_38 |= V_39 ;
V_27 -> V_38 ^= V_69 ;
if ( F_23 ( V_25 ) | F_24 ( V_25 ) )
V_66 = F_27 ( V_24 , V_25 , V_27 ) ;
else
V_66 = - V_68 ;
V_67:
return V_66 ;
}
static T_2
F_41 ( struct V_70 * V_71 , struct V_72 * V_73 )
{
struct V_8 * V_9 = V_71 -> V_74 -> V_13 ;
int V_66 , V_3 = 0 ;
F_2 ( V_11 , L_5 ,
F_42 ( V_73 ) , V_71 -> V_75 ) ;
V_66 = F_43 ( V_9 , V_71 -> V_75 , V_73 , & V_3 ) ;
if ( ! V_66 )
return V_3 ;
V_71 -> V_75 += V_66 ;
return V_66 ;
}
static T_2
F_44 ( struct V_70 * V_71 , struct V_72 * V_76 )
{
struct V_2 * V_2 = V_71 -> V_74 ;
T_2 V_77 ;
T_3 V_78 ;
int V_3 = 0 ;
V_77 = F_45 ( V_71 , V_76 ) ;
if ( V_77 <= 0 )
return V_77 ;
V_78 = V_71 -> V_75 ;
V_77 = F_46 ( V_2 -> V_13 , V_71 -> V_75 , V_76 , & V_3 ) ;
if ( V_77 > 0 ) {
struct V_1 * V_1 = F_21 ( V_2 ) ;
T_3 V_79 ;
unsigned long V_80 , V_81 ;
V_80 = V_78 >> V_82 ;
V_81 = ( V_78 + V_77 - 1 ) >> V_82 ;
if ( V_1 -> V_32 && V_1 -> V_32 -> V_83 )
F_47 ( V_1 -> V_32 ,
V_80 , V_81 ) ;
V_71 -> V_75 += V_77 ;
V_79 = F_48 ( V_1 ) ;
if ( V_71 -> V_75 > V_79 ) {
F_49 ( V_1 , V_71 -> V_75 - V_79 ) ;
F_50 ( V_1 , V_71 -> V_75 ) ;
}
return V_77 ;
}
return V_3 ;
}
static int F_51 ( struct V_2 * V_24 , T_3 V_46 , T_3 V_84 ,
int V_85 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_86 -> V_87 ;
struct V_88 V_89 ;
int V_77 ;
V_77 = F_52 ( V_1 -> V_32 , V_46 , V_84 ) ;
if ( V_77 )
return V_77 ;
F_53 ( V_1 ) ;
F_2 ( V_11 , L_6 , V_24 , V_85 ) ;
V_9 = V_24 -> V_13 ;
F_54 ( & V_89 ) ;
V_77 = F_55 ( V_9 , & V_89 ) ;
F_56 ( V_1 ) ;
return V_77 ;
}
int F_57 ( struct V_2 * V_24 , T_3 V_46 , T_3 V_84 ,
int V_85 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 = V_24 -> V_86 -> V_87 ;
int V_77 ;
V_77 = F_52 ( V_1 -> V_32 , V_46 , V_84 ) ;
if ( V_77 )
return V_77 ;
F_53 ( V_1 ) ;
F_2 ( V_11 , L_6 , V_24 , V_85 ) ;
V_9 = V_24 -> V_13 ;
V_77 = F_58 ( V_9 , V_85 ) ;
F_56 ( V_1 ) ;
return V_77 ;
}
static int
F_59 ( struct V_2 * V_24 , struct V_90 * V_91 )
{
int V_77 ;
V_77 = F_60 ( V_24 , V_91 ) ;
if ( ! V_77 )
V_91 -> V_92 = & V_93 ;
return V_77 ;
}
static int
F_61 ( struct V_2 * V_24 , struct V_90 * V_91 )
{
int V_77 ;
struct V_1 * V_1 ;
struct V_4 * V_5 ;
struct V_8 * V_9 ;
V_1 = F_21 ( V_24 ) ;
V_5 = F_3 ( V_1 ) ;
F_16 ( & V_5 -> V_16 ) ;
if ( ! V_5 -> V_20 &&
( V_91 -> V_94 & V_95 ) ) {
V_9 = F_17 ( F_10 ( V_24 ) ) ;
if ( F_11 ( V_9 ) ) {
V_77 = F_12 ( V_9 ) ;
F_18 ( & V_5 -> V_16 ) ;
return V_77 ;
}
V_5 -> V_20 = ( void * ) V_9 ;
}
F_18 ( & V_5 -> V_16 ) ;
V_77 = F_60 ( V_24 , V_91 ) ;
if ( ! V_77 )
V_91 -> V_92 = & V_96 ;
return V_77 ;
}
static int
F_62 ( struct V_97 * V_98 )
{
struct V_4 * V_5 ;
struct V_99 * V_99 = V_98 -> V_99 ;
struct V_2 * V_24 = V_98 -> V_91 -> V_100 ;
struct V_1 * V_1 = F_21 ( V_24 ) ;
F_2 ( V_11 , L_7 ,
V_99 , ( unsigned long ) V_24 -> V_13 ) ;
F_63 ( V_24 ) ;
V_5 = F_3 ( V_1 ) ;
F_64 ( V_1 , V_99 ) ;
F_28 ( ! V_5 -> V_20 ) ;
F_65 ( V_99 ) ;
if ( V_99 -> V_101 != V_1 -> V_32 )
goto V_58;
F_66 ( V_99 ) ;
return V_102 ;
V_58:
F_67 ( V_99 ) ;
return V_103 ;
}
static T_2
F_68 ( struct V_70 * V_71 , struct V_72 * V_73 )
{
return F_41 ( V_71 , V_73 ) ;
}
static T_2
F_69 ( struct V_70 * V_71 , struct V_72 * V_76 )
{
return F_44 ( V_71 , V_76 ) ;
}
static void F_70 ( struct V_90 * V_91 )
{
struct V_1 * V_1 ;
struct V_104 V_105 = {
. V_106 = V_107 ,
. V_108 = V_109 ,
. V_110 = V_91 -> V_111 * V_112 ,
. V_113 = V_91 -> V_111 * V_112 +
( V_91 -> V_114 - V_91 -> V_115 - 1 ) ,
} ;
F_2 ( V_11 , L_8 , V_91 ) ;
V_1 = F_21 ( V_91 -> V_100 ) ;
if ( ! F_71 ( V_1 -> V_32 ) )
V_105 . V_106 = 0 ;
F_72 () ;
F_73 ( V_1 , & V_105 ) ;
}
