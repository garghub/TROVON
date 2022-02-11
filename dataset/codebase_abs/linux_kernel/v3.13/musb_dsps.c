static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_4 , unsigned long V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
if ( V_5 == 0 )
V_5 = V_12 + F_11 ( 3 ) ;
if ( V_4 -> V_13 || ( V_4 -> V_14 == 0 &&
V_4 -> V_15 -> V_16 == V_17 ) ) {
F_12 ( V_4 -> V_8 , L_1 ,
F_13 ( V_4 -> V_15 -> V_16 ) ) ;
F_14 ( & V_10 -> V_18 ) ;
V_10 -> V_19 = V_12 ;
return;
}
if ( V_4 -> V_20 != V_21 )
return;
if ( ! V_4 -> V_22 . V_7 . V_23 )
return;
if ( F_15 ( V_10 -> V_19 , V_5 ) &&
F_16 ( & V_10 -> V_18 ) ) {
F_12 ( V_4 -> V_8 ,
L_2 ) ;
return;
}
V_10 -> V_19 = V_5 ;
F_12 ( V_4 -> V_8 , L_3 ,
F_13 ( V_4 -> V_15 -> V_16 ) ,
F_17 ( V_5 - V_12 ) ) ;
F_18 ( & V_10 -> V_18 , V_5 ) ;
}
static void F_19 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_24 * V_25 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_25 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 = V_4 -> V_29 ;
T_3 V_30 , V_31 ;
V_30 = ( ( V_4 -> V_30 & V_27 -> V_32 ) << V_27 -> V_33 ) |
( ( V_4 -> V_30 & V_27 -> V_34 ) << V_27 -> V_35 ) ;
V_31 = ( V_27 -> V_36 & ~ V_37 ) ;
F_7 ( V_28 , V_27 -> V_38 , V_30 ) ;
F_7 ( V_28 , V_27 -> V_39 , V_31 ) ;
F_7 ( V_28 , V_27 -> V_39 ,
( 1 << V_27 -> V_40 ) << V_27 -> V_41 ) ;
F_9 ( V_4 , 0 ) ;
}
static void F_22 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_24 * V_25 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_25 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 = V_4 -> V_29 ;
F_7 ( V_28 , V_27 -> V_42 , V_27 -> V_36 ) ;
F_7 ( V_28 , V_27 -> V_43 ,
V_27 -> V_44 | V_27 -> V_45 ) ;
F_5 ( V_4 -> V_46 , V_47 , 0 ) ;
}
static void F_23 ( unsigned long V_48 )
{
struct V_4 * V_4 = ( void * ) V_48 ;
void T_2 * V_46 = V_4 -> V_46 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
T_1 V_49 ;
unsigned long V_50 ;
int V_51 = 0 ;
V_49 = F_1 ( V_46 , V_47 ) ;
F_12 ( V_4 -> V_8 , L_4 , V_49 ,
F_13 ( V_4 -> V_15 -> V_16 ) ) ;
F_24 ( & V_4 -> V_52 , V_50 ) ;
switch ( V_4 -> V_15 -> V_16 ) {
case V_17 :
F_5 ( V_4 -> V_46 , V_47 , 0 ) ;
V_51 = 1 ;
case V_53 :
case V_54 :
if ( V_49 & V_55 ) {
V_4 -> V_15 -> V_16 = V_54 ;
F_25 ( V_4 ) ;
} else {
V_4 -> V_15 -> V_16 = V_53 ;
F_26 ( V_4 ) ;
}
if ( ! ( V_49 & V_56 ) && ! V_51 )
F_5 ( V_46 , V_47 , V_56 ) ;
F_18 ( & V_10 -> V_18 , V_12 + V_27 -> V_57 * V_58 ) ;
break;
case V_59 :
V_4 -> V_15 -> V_16 = V_60 ;
F_7 ( V_4 -> V_29 , V_27 -> V_39 ,
V_61 << V_27 -> V_41 ) ;
break;
default:
break;
}
F_27 ( & V_4 -> V_52 , V_50 ) ;
}
static T_4 F_28 ( int V_62 , void * V_63 )
{
struct V_4 * V_4 = V_63 ;
void T_2 * V_28 = V_4 -> V_29 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
unsigned long V_50 ;
T_4 V_64 = V_65 ;
T_3 V_66 , V_67 ;
F_24 ( & V_4 -> V_52 , V_50 ) ;
V_66 = F_3 ( V_28 , V_27 -> V_68 ) ;
V_4 -> V_69 = ( V_66 & V_27 -> V_45 ) >> V_27 -> V_35 ;
V_4 -> V_70 = ( V_66 & V_27 -> V_44 ) >> V_27 -> V_33 ;
if ( V_66 )
F_7 ( V_28 , V_27 -> V_68 , V_66 ) ;
V_67 = F_3 ( V_28 , V_27 -> V_71 ) ;
if ( ! V_67 && ! V_66 )
goto V_72;
V_4 -> V_73 = ( V_67 & V_27 -> V_36 ) >> V_27 -> V_41 ;
if ( V_67 )
F_7 ( V_28 , V_27 -> V_71 , V_67 ) ;
F_12 ( V_4 -> V_8 , L_5 ,
V_67 , V_66 ) ;
if ( F_29 ( V_4 ) && V_67 & V_74 )
F_30 ( L_6 ) ;
if ( V_67 & ( ( 1 << V_27 -> V_40 ) << V_27 -> V_41 ) ) {
int V_40 = F_3 ( V_28 , V_27 -> V_75 ) ;
void T_2 * V_46 = V_4 -> V_46 ;
T_1 V_49 = F_1 ( V_46 , V_47 ) ;
int V_76 ;
V_76 = V_4 -> V_73 & V_61 ;
if ( V_76 ) {
V_4 -> V_73 &= ~ V_61 ;
V_4 -> V_15 -> V_16 = V_59 ;
F_18 ( & V_10 -> V_18 ,
V_12 + V_27 -> V_57 * V_58 ) ;
F_31 ( L_7 ) ;
} else if ( V_40 ) {
F_26 ( V_4 ) ;
V_4 -> V_15 -> V_77 -> V_78 = 1 ;
V_4 -> V_15 -> V_16 = V_60 ;
F_14 ( & V_10 -> V_18 ) ;
} else {
V_4 -> V_13 = 0 ;
F_25 ( V_4 ) ;
V_4 -> V_15 -> V_77 -> V_78 = 0 ;
V_4 -> V_15 -> V_16 = V_54 ;
}
F_12 ( V_4 -> V_8 , L_8 ,
V_40 ? L_9 : L_10 ,
F_13 ( V_4 -> V_15 -> V_16 ) ,
V_76 ? L_11 : L_12 ,
V_49 ) ;
V_64 = V_79 ;
}
if ( V_4 -> V_70 || V_4 -> V_69 || V_4 -> V_73 )
V_64 |= F_32 ( V_4 ) ;
if ( V_4 -> V_15 -> V_16 == V_54 )
F_18 ( & V_10 -> V_18 , V_12 + V_27 -> V_57 * V_58 ) ;
V_72:
F_27 ( & V_4 -> V_52 , V_50 ) ;
return V_64 ;
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
struct V_24 * V_11 = F_20 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 ;
struct V_80 * V_81 ;
T_3 V_82 , V_83 ;
V_81 = F_34 ( V_11 , V_84 , L_13 ) ;
if ( ! V_81 )
return - V_85 ;
V_28 = F_35 ( V_7 , V_81 ) ;
if ( F_36 ( V_28 ) )
return F_37 ( V_28 ) ;
V_4 -> V_29 = V_28 ;
V_4 -> V_15 = F_38 ( V_7 , L_14 , 0 ) ;
if ( F_36 ( V_4 -> V_15 ) )
return F_37 ( V_4 -> V_15 ) ;
V_82 = F_3 ( V_28 , V_27 -> V_86 ) ;
if ( ! V_82 )
return - V_87 ;
F_39 ( V_4 -> V_15 ) ;
F_40 ( & V_10 -> V_18 , F_23 , ( unsigned long ) V_4 ) ;
F_7 ( V_28 , V_27 -> V_88 , ( 1 << V_27 -> V_89 ) ) ;
V_4 -> V_90 = F_28 ;
V_83 = F_3 ( V_28 , V_27 -> V_91 ) ;
V_83 &= ~ ( 1 << V_27 -> V_92 ) ;
F_7 ( V_4 -> V_29 , V_27 -> V_91 , V_83 ) ;
return 0 ;
}
static int F_41 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
F_42 ( & V_10 -> V_18 ) ;
F_43 ( V_4 -> V_15 ) ;
return 0 ;
}
static int F_44 ( struct V_93 * V_94 , const char * V_95 )
{
int V_64 ;
T_3 V_83 ;
V_64 = F_45 ( V_94 , V_95 , & V_83 ) ;
if ( V_64 )
return 0 ;
return V_83 ;
}
static int F_46 ( struct V_6 * V_7 )
{
enum V_96 V_97 ;
V_97 = F_47 ( V_7 -> V_98 ) ;
switch ( V_97 ) {
case V_99 :
return V_100 ;
case V_101 :
return V_102 ;
case V_103 :
case V_104 :
default:
return V_21 ;
}
}
static int F_48 ( struct V_9 * V_10 ,
struct V_24 * V_11 )
{
struct V_105 V_106 ;
struct V_80 V_107 [ 2 ] ;
struct V_80 * V_108 ;
struct V_6 * V_7 = & V_11 -> V_7 ;
struct V_109 * V_110 ;
struct V_24 * V_4 ;
struct V_93 * V_94 = V_11 -> V_7 . V_98 ;
int V_64 ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
V_108 = F_34 ( V_11 , V_84 , L_15 ) ;
if ( ! V_108 ) {
F_49 ( V_7 , L_16 ) ;
return - V_85 ;
}
V_107 [ 0 ] = * V_108 ;
V_108 = F_34 ( V_11 , V_111 , L_15 ) ;
if ( ! V_108 ) {
F_49 ( V_7 , L_17 ) ;
return - V_85 ;
}
V_107 [ 1 ] = * V_108 ;
V_4 = F_50 ( L_18 , V_112 ) ;
if ( ! V_4 ) {
F_49 ( V_7 , L_19 ) ;
return - V_113 ;
}
V_4 -> V_7 . V_11 = V_7 ;
V_4 -> V_7 . V_114 = & V_115 ;
V_4 -> V_7 . V_116 = V_115 ;
V_4 -> V_7 . V_98 = F_51 ( V_94 ) ;
V_10 -> V_4 = V_4 ;
V_64 = F_52 ( V_4 , V_107 ,
F_53 ( V_107 ) ) ;
if ( V_64 ) {
F_49 ( V_7 , L_20 ) ;
goto V_76;
}
V_110 = F_54 ( & V_11 -> V_7 , sizeof( * V_110 ) , V_117 ) ;
if ( ! V_110 ) {
F_49 ( V_7 , L_21 ) ;
V_64 = - V_113 ;
goto V_76;
}
V_106 . V_110 = V_110 ;
V_106 . V_118 = & V_119 ;
V_110 -> V_120 = F_44 ( V_94 , L_22 ) ;
V_110 -> V_121 = F_44 ( V_94 , L_23 ) ;
V_106 . V_97 = F_46 ( V_7 ) ;
V_106 . V_122 = F_44 ( V_94 , L_24 ) / 2 ;
V_110 -> V_123 = F_55 ( V_94 , L_25 ) ;
V_64 = F_56 ( V_4 , & V_106 , sizeof( V_106 ) ) ;
if ( V_64 ) {
F_49 ( V_7 , L_26 ) ;
goto V_76;
}
V_64 = F_57 ( V_4 ) ;
if ( V_64 ) {
F_49 ( V_7 , L_27 ) ;
goto V_76;
}
return 0 ;
V_76:
F_58 ( V_4 ) ;
return V_64 ;
}
static int F_59 ( struct V_24 * V_25 )
{
const struct V_124 * V_125 ;
const struct V_26 * V_27 ;
struct V_9 * V_10 ;
int V_64 ;
if ( ! strcmp ( V_25 -> V_126 , L_18 ) )
return - V_87 ;
V_125 = F_60 ( V_127 , V_25 -> V_7 . V_98 ) ;
if ( ! V_125 ) {
F_49 ( & V_25 -> V_7 , L_28 ) ;
return - V_85 ;
}
V_27 = V_125 -> V_3 ;
V_10 = F_61 ( sizeof( * V_10 ) , V_117 ) ;
if ( ! V_10 ) {
F_49 ( & V_25 -> V_7 , L_29 ) ;
return - V_113 ;
}
V_10 -> V_7 = & V_25 -> V_7 ;
V_10 -> V_27 = V_27 ;
F_62 ( V_25 , V_10 ) ;
F_63 ( & V_25 -> V_7 ) ;
V_64 = F_64 ( & V_25 -> V_7 ) ;
if ( V_64 < 0 ) {
F_49 ( & V_25 -> V_7 , L_30 ) ;
goto V_128;
}
V_64 = F_48 ( V_10 , V_25 ) ;
if ( V_64 )
goto V_129;
return 0 ;
V_129:
F_65 ( & V_25 -> V_7 ) ;
V_128:
F_66 ( & V_25 -> V_7 ) ;
F_67 ( V_10 ) ;
return V_64 ;
}
static int F_68 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_21 ( V_25 ) ;
F_69 ( V_10 -> V_4 ) ;
F_65 ( & V_25 -> V_7 ) ;
F_66 ( & V_25 -> V_7 ) ;
F_67 ( V_10 ) ;
return 0 ;
}
