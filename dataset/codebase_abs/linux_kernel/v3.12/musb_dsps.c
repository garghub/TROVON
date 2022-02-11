static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
T_3 V_17 , V_18 ;
V_17 = ( ( V_4 -> V_17 & V_14 -> V_19 ) << V_14 -> V_20 ) |
( ( V_4 -> V_17 & V_14 -> V_21 ) << V_14 -> V_22 ) ;
V_18 = ( V_14 -> V_23 & ~ V_24 ) ;
F_7 ( V_15 , V_14 -> V_25 , V_17 ) ;
F_7 ( V_15 , V_14 -> V_26 , V_18 ) ;
F_7 ( V_15 , V_14 -> V_26 ,
( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ;
}
static void F_12 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
F_7 ( V_15 , V_14 -> V_29 , V_14 -> V_23 ) ;
F_7 ( V_15 , V_14 -> V_30 ,
V_14 -> V_31 | V_14 -> V_32 ) ;
F_5 ( V_4 -> V_33 , V_34 , 0 ) ;
}
static void F_13 ( unsigned long V_35 )
{
struct V_4 * V_4 = ( void * ) V_35 ;
void T_2 * V_33 = V_4 -> V_33 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_36 ;
unsigned long V_37 ;
V_36 = F_1 ( V_33 , V_34 ) ;
F_15 ( V_4 -> V_7 , L_1 , V_36 ,
F_16 ( V_4 -> V_38 -> V_39 ) ) ;
F_17 ( & V_4 -> V_40 , V_37 ) ;
switch ( V_4 -> V_38 -> V_39 ) {
case V_41 :
V_36 &= ~ V_42 ;
F_5 ( V_4 -> V_33 , V_34 , V_36 ) ;
V_36 = F_1 ( V_4 -> V_33 , V_34 ) ;
if ( V_36 & V_43 ) {
V_4 -> V_38 -> V_39 = V_44 ;
F_18 ( V_4 ) ;
} else {
V_4 -> V_38 -> V_39 = V_45 ;
F_19 ( V_4 ) ;
}
break;
case V_46 :
V_4 -> V_38 -> V_39 = V_47 ;
F_7 ( V_4 -> V_16 , V_14 -> V_26 ,
V_48 << V_14 -> V_28 ) ;
break;
case V_44 :
V_36 = F_1 ( V_33 , V_34 ) ;
if ( V_36 & V_43 )
F_20 ( & V_12 -> V_49 ,
V_50 + V_14 -> V_51 * V_52 ) ;
else
V_4 -> V_38 -> V_39 = V_45 ;
break;
default:
break;
}
F_21 ( & V_4 -> V_40 , V_37 ) ;
}
static void F_22 ( struct V_4 * V_4 , unsigned long V_53 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
if ( V_53 == 0 )
V_53 = V_50 + F_23 ( 3 ) ;
if ( V_4 -> V_54 || ( V_4 -> V_55 == 0 &&
V_4 -> V_38 -> V_39 == V_41 ) ) {
F_15 ( V_4 -> V_7 , L_2 ,
F_16 ( V_4 -> V_38 -> V_39 ) ) ;
F_24 ( & V_12 -> V_49 ) ;
V_12 -> V_56 = V_50 ;
return;
}
if ( V_4 -> V_57 == V_58 )
return;
if ( F_25 ( V_12 -> V_56 , V_53 ) &&
F_26 ( & V_12 -> V_49 ) ) {
F_15 ( V_4 -> V_7 ,
L_3 ) ;
return;
}
V_12 -> V_56 = V_53 ;
F_15 ( V_4 -> V_7 , L_4 ,
F_16 ( V_4 -> V_38 -> V_39 ) ,
F_27 ( V_53 - V_50 ) ) ;
F_20 ( & V_12 -> V_49 , V_53 ) ;
}
static T_4 F_28 ( int V_59 , void * V_60 )
{
struct V_4 * V_4 = V_60 ;
void T_2 * V_15 = V_4 -> V_16 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
unsigned long V_37 ;
T_4 V_61 = V_62 ;
T_3 V_63 , V_64 ;
F_17 ( & V_4 -> V_40 , V_37 ) ;
V_63 = F_3 ( V_15 , V_14 -> V_65 ) ;
V_4 -> V_66 = ( V_63 & V_14 -> V_32 ) >> V_14 -> V_22 ;
V_4 -> V_67 = ( V_63 & V_14 -> V_31 ) >> V_14 -> V_20 ;
if ( V_63 )
F_7 ( V_15 , V_14 -> V_65 , V_63 ) ;
V_64 = F_3 ( V_15 , V_14 -> V_68 ) ;
if ( ! V_64 && ! V_63 )
goto V_69;
V_4 -> V_70 = ( V_64 & V_14 -> V_23 ) >> V_14 -> V_28 ;
if ( V_64 )
F_7 ( V_15 , V_14 -> V_68 , V_64 ) ;
F_15 ( V_4 -> V_7 , L_5 ,
V_64 , V_63 ) ;
if ( F_29 ( V_4 ) && V_64 & V_71 )
F_30 ( L_6 ) ;
if ( V_64 & ( ( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ) {
int V_27 = F_3 ( V_15 , V_14 -> V_72 ) ;
void T_2 * V_33 = V_4 -> V_33 ;
T_1 V_36 = F_1 ( V_33 , V_34 ) ;
int V_73 ;
V_73 = V_4 -> V_70 & V_48 ;
if ( V_73 ) {
V_4 -> V_70 &= ~ V_48 ;
V_4 -> V_38 -> V_39 = V_46 ;
F_20 ( & V_12 -> V_49 ,
V_50 + V_14 -> V_51 * V_52 ) ;
F_31 ( L_7 ) ;
} else if ( V_27 ) {
F_19 ( V_4 ) ;
V_4 -> V_38 -> V_74 -> V_75 = 1 ;
V_4 -> V_38 -> V_39 = V_47 ;
F_24 ( & V_12 -> V_49 ) ;
} else {
V_4 -> V_54 = 0 ;
F_18 ( V_4 ) ;
V_4 -> V_38 -> V_74 -> V_75 = 0 ;
V_4 -> V_38 -> V_39 = V_44 ;
}
F_15 ( V_4 -> V_7 , L_8 ,
V_27 ? L_9 : L_10 ,
F_16 ( V_4 -> V_38 -> V_39 ) ,
V_73 ? L_11 : L_12 ,
V_36 ) ;
V_61 = V_76 ;
}
if ( V_4 -> V_67 || V_4 -> V_66 || V_4 -> V_70 )
V_61 |= F_32 ( V_4 ) ;
if ( V_4 -> V_38 -> V_39 == V_44 )
F_20 ( & V_12 -> V_49 , V_50 + V_14 -> V_51 * V_52 ) ;
V_69:
F_21 ( & V_4 -> V_40 , V_37 ) ;
return V_61 ;
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
struct V_8 * V_10 = F_10 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 ;
struct V_77 * V_78 ;
T_3 V_79 , V_80 ;
V_78 = F_34 ( V_10 , V_81 , L_13 ) ;
if ( ! V_78 )
return - V_82 ;
V_15 = F_35 ( V_6 , V_78 ) ;
if ( F_36 ( V_15 ) )
return F_37 ( V_15 ) ;
V_4 -> V_16 = V_15 ;
V_4 -> V_38 = F_38 ( V_6 , L_14 , 0 ) ;
if ( F_36 ( V_4 -> V_38 ) )
return F_37 ( V_4 -> V_38 ) ;
V_79 = F_3 ( V_15 , V_14 -> V_83 ) ;
if ( ! V_79 )
return - V_84 ;
F_39 ( V_4 -> V_38 ) ;
F_40 ( & V_12 -> V_49 , F_13 , ( unsigned long ) V_4 ) ;
F_7 ( V_15 , V_14 -> V_85 , ( 1 << V_14 -> V_86 ) ) ;
V_4 -> V_87 = F_28 ;
V_80 = F_3 ( V_15 , V_14 -> V_88 ) ;
V_80 &= ~ ( 1 << V_14 -> V_89 ) ;
F_7 ( V_4 -> V_16 , V_14 -> V_88 , V_80 ) ;
return 0 ;
}
static int F_41 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
F_42 ( & V_12 -> V_49 ) ;
F_43 ( V_4 -> V_38 ) ;
return 0 ;
}
static int F_44 ( struct V_90 * V_91 , const char * V_92 )
{
int V_61 ;
T_3 V_80 ;
V_61 = F_45 ( V_91 , V_92 , & V_80 ) ;
if ( V_61 )
return 0 ;
return V_80 ;
}
static int F_46 ( struct V_5 * V_6 )
{
enum V_93 V_94 ;
V_94 = F_47 ( V_6 -> V_95 ) ;
switch ( V_94 ) {
case V_96 :
return V_58 ;
case V_97 :
return V_98 ;
case V_99 :
case V_100 :
default:
return V_101 ;
} ;
}
static int F_48 ( struct V_11 * V_12 ,
struct V_8 * V_10 )
{
struct V_102 V_103 ;
struct V_77 V_104 [ 2 ] ;
struct V_77 * V_105 ;
struct V_5 * V_6 = & V_10 -> V_6 ;
struct V_106 * V_107 ;
struct V_8 * V_4 ;
struct V_90 * V_91 = V_10 -> V_6 . V_95 ;
int V_61 ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
V_105 = F_34 ( V_10 , V_81 , L_15 ) ;
if ( ! V_105 ) {
F_49 ( V_6 , L_16 ) ;
return - V_82 ;
}
V_104 [ 0 ] = * V_105 ;
V_105 = F_34 ( V_10 , V_108 , L_15 ) ;
if ( ! V_105 ) {
F_49 ( V_6 , L_17 ) ;
return - V_82 ;
}
V_104 [ 1 ] = * V_105 ;
V_4 = F_50 ( L_18 , V_109 ) ;
if ( ! V_4 ) {
F_49 ( V_6 , L_19 ) ;
return - V_110 ;
}
V_4 -> V_6 . V_10 = V_6 ;
V_4 -> V_6 . V_111 = & V_112 ;
V_4 -> V_6 . V_113 = V_112 ;
V_4 -> V_6 . V_95 = F_51 ( V_91 ) ;
V_12 -> V_4 = V_4 ;
V_61 = F_52 ( V_4 , V_104 ,
F_53 ( V_104 ) ) ;
if ( V_61 ) {
F_49 ( V_6 , L_20 ) ;
goto V_73;
}
V_107 = F_54 ( & V_10 -> V_6 , sizeof( * V_107 ) , V_114 ) ;
if ( ! V_107 ) {
F_49 ( V_6 , L_21 ) ;
V_61 = - V_110 ;
goto V_73;
}
V_103 . V_107 = V_107 ;
V_103 . V_115 = & V_116 ;
V_107 -> V_117 = F_44 ( V_91 , L_22 ) ;
V_107 -> V_118 = F_44 ( V_91 , L_23 ) ;
V_103 . V_94 = F_46 ( V_6 ) ;
V_103 . V_119 = F_44 ( V_91 , L_24 ) / 2 ;
V_107 -> V_120 = F_55 ( V_91 , L_25 ) ;
V_61 = F_56 ( V_4 , & V_103 , sizeof( V_103 ) ) ;
if ( V_61 ) {
F_49 ( V_6 , L_26 ) ;
goto V_73;
}
V_61 = F_57 ( V_4 ) ;
if ( V_61 ) {
F_49 ( V_6 , L_27 ) ;
goto V_73;
}
return 0 ;
V_73:
F_58 ( V_4 ) ;
return V_61 ;
}
static int F_59 ( struct V_8 * V_9 )
{
const struct V_121 * V_122 ;
const struct V_13 * V_14 ;
struct V_11 * V_12 ;
int V_61 ;
if ( ! strcmp ( V_9 -> V_123 , L_18 ) )
return - V_84 ;
V_122 = F_60 ( V_124 , V_9 -> V_6 . V_95 ) ;
if ( ! V_122 ) {
F_49 ( & V_9 -> V_6 , L_28 ) ;
return - V_82 ;
}
V_14 = V_122 -> V_3 ;
V_12 = F_61 ( sizeof( * V_12 ) , V_114 ) ;
if ( ! V_12 ) {
F_49 ( & V_9 -> V_6 , L_29 ) ;
return - V_110 ;
}
V_12 -> V_6 = & V_9 -> V_6 ;
V_12 -> V_14 = V_14 ;
F_62 ( V_9 , V_12 ) ;
F_63 ( & V_9 -> V_6 ) ;
V_61 = F_64 ( & V_9 -> V_6 ) ;
if ( V_61 < 0 ) {
F_49 ( & V_9 -> V_6 , L_30 ) ;
goto V_125;
}
V_61 = F_48 ( V_12 , V_9 ) ;
if ( V_61 )
goto V_126;
return 0 ;
V_126:
F_65 ( & V_9 -> V_6 ) ;
V_125:
F_66 ( & V_9 -> V_6 ) ;
F_67 ( V_12 ) ;
return V_61 ;
}
static int F_68 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
F_69 ( V_12 -> V_4 ) ;
F_65 ( & V_9 -> V_6 ) ;
F_66 ( & V_9 -> V_6 ) ;
F_67 ( V_12 ) ;
return 0 ;
}
