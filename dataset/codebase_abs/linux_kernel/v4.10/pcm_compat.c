static int F_1 ( struct V_1 * V_2 ,
T_1 T_2 * V_3 )
{
T_3 V_4 ;
T_4 V_5 ;
int V_6 ;
V_5 = F_2 () ;
V_6 = F_3 ( V_2 , & V_4 ) ;
F_4 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_4 , V_3 ) )
return - V_7 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_5 T_2 * V_3 )
{
T_6 V_8 ;
int V_6 ;
if ( F_7 ( V_8 , V_3 ) )
return - V_7 ;
if ( V_2 -> V_9 == V_10 )
V_6 = F_8 ( V_2 , V_8 ) ;
else
V_6 = F_9 ( V_2 , V_8 ) ;
if ( F_5 ( V_6 , V_3 ) )
return - V_7 ;
return V_6 < 0 ? V_6 : 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_5 T_2 * V_3 )
{
T_6 V_8 ;
int V_6 ;
if ( F_7 ( V_8 , V_3 ) )
return - V_7 ;
if ( V_2 -> V_9 == V_10 )
V_6 = F_11 ( V_2 , V_8 ) ;
else
V_6 = F_12 ( V_2 , V_8 ) ;
if ( F_5 ( V_6 , V_3 ) )
return - V_7 ;
return V_6 < 0 ? V_6 : 0 ;
}
static T_6 F_13 ( struct V_11 * V_12 )
{
T_6 V_13 ;
if ( ! V_12 -> V_14 )
return 0 ;
V_13 = V_12 -> V_14 ;
while ( V_13 * 2 <= 0x7fffffffUL - V_12 -> V_14 )
V_13 *= 2 ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_15 T_2 * V_3 )
{
struct V_16 V_17 ;
T_6 V_13 ;
int V_6 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
if ( F_7 ( V_17 . V_18 , & V_3 -> V_18 ) ||
F_7 ( V_17 . V_19 , & V_3 -> V_19 ) ||
F_7 ( V_17 . V_20 , & V_3 -> V_20 ) ||
F_7 ( V_17 . V_21 , & V_3 -> V_21 ) ||
F_7 ( V_17 . V_22 , & V_3 -> V_22 ) ||
F_7 ( V_17 . V_23 , & V_3 -> V_23 ) ||
F_7 ( V_17 . V_24 , & V_3 -> V_24 ) ||
F_7 ( V_17 . V_25 , & V_3 -> V_25 ) ||
F_7 ( V_17 . V_26 , & V_3 -> V_26 ) ||
F_7 ( V_17 . V_27 , & V_3 -> V_27 ) ||
F_7 ( V_17 . V_28 , & V_3 -> V_28 ) )
return - V_7 ;
V_13 = F_13 ( V_2 -> V_12 ) ;
if ( V_13 && V_17 . V_26 >= V_13 )
V_17 . V_26 = V_2 -> V_12 -> V_13 ;
V_6 = V_16 ( V_2 , & V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_13 && F_5 ( V_13 , & V_3 -> V_13 ) )
return - V_7 ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_29 T_2 * V_3 )
{
struct V_30 V_31 ;
int V_6 ;
if ( F_7 ( V_31 . V_32 , & V_3 -> V_32 ) ||
F_7 ( V_31 . V_33 , & V_3 -> V_33 ) ||
F_7 ( V_31 . V_34 , & V_3 -> V_34 ) ||
F_7 ( V_31 . V_35 , & V_3 -> V_35 ) )
return - V_7 ;
V_6 = V_30 ( V_2 , & V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_31 . V_32 , & V_3 -> V_32 ) ||
F_5 ( V_31 . V_33 , & V_3 -> V_33 ) ||
F_5 ( V_31 . V_34 , & V_3 -> V_34 ) ||
F_5 ( V_31 . V_35 , & V_3 -> V_35 ) )
return - V_7 ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_36 T_2 * V_3 ,
bool V_37 )
{
struct V_38 V_39 ;
int V_6 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_37 && F_7 ( V_39 . V_40 ,
( T_5 T_2 * ) ( & V_3 -> V_40 ) ) )
return - V_7 ;
V_6 = V_38 ( V_2 , & V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_17 ( V_3 , sizeof( * V_3 ) ) )
return - V_7 ;
if ( F_5 ( V_39 . V_41 , & V_3 -> V_41 ) ||
F_18 ( & V_39 . V_42 , & V_3 -> V_42 ) ||
F_18 ( & V_39 . V_43 , & V_3 -> V_43 ) ||
F_5 ( V_39 . V_44 , & V_3 -> V_44 ) ||
F_5 ( V_39 . V_45 , & V_3 -> V_45 ) ||
F_5 ( V_39 . V_4 , & V_3 -> V_4 ) ||
F_5 ( V_39 . V_46 , & V_3 -> V_46 ) ||
F_5 ( V_39 . V_47 , & V_3 -> V_47 ) ||
F_5 ( V_39 . V_48 , & V_3 -> V_48 ) ||
F_5 ( V_39 . V_49 , & V_3 -> V_49 ) ||
F_5 ( V_39 . V_40 , & V_3 -> V_40 ) ||
F_18 ( & V_39 . V_50 , & V_3 -> V_50 ) ||
F_18 ( & V_39 . V_51 , & V_3 -> V_51 ) ||
F_5 ( V_39 . V_52 , & V_3 -> V_52 ) )
return - V_7 ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_53 T_2 * V_3 ,
bool V_37 )
{
struct V_38 V_39 ;
int V_6 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
if ( V_37 && F_7 ( V_39 . V_40 ,
( T_5 T_2 * ) ( & V_3 -> V_40 ) ) )
return - V_7 ;
V_6 = V_38 ( V_2 , & V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_17 ( V_3 , sizeof( * V_3 ) ) )
return - V_7 ;
if ( F_5 ( V_39 . V_41 , & V_3 -> V_41 ) ||
F_20 ( & V_39 . V_42 , & V_3 -> V_42 ) ||
F_20 ( & V_39 . V_43 , & V_3 -> V_43 ) ||
F_5 ( V_39 . V_44 , & V_3 -> V_44 ) ||
F_5 ( V_39 . V_45 , & V_3 -> V_45 ) ||
F_5 ( V_39 . V_4 , & V_3 -> V_4 ) ||
F_5 ( V_39 . V_46 , & V_3 -> V_46 ) ||
F_5 ( V_39 . V_47 , & V_3 -> V_47 ) ||
F_5 ( V_39 . V_48 , & V_3 -> V_48 ) ||
F_5 ( V_39 . V_49 , & V_3 -> V_49 ) ||
F_5 ( V_39 . V_40 , & V_3 -> V_40 ) ||
F_20 ( & V_39 . V_50 , & V_3 -> V_50 ) ||
F_20 ( & V_39 . V_51 , & V_3 -> V_51 ) ||
F_5 ( V_39 . V_52 , & V_3 -> V_52 ) )
return - V_7 ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_54 ,
struct V_55 T_2 * V_56 )
{
struct V_57 * V_58 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_12 = V_2 -> V_12 ) )
return - V_59 ;
V_58 = F_22 ( sizeof( * V_58 ) , V_60 ) ;
if ( ! V_58 )
return - V_61 ;
if ( F_23 ( V_58 , V_56 , sizeof( * V_56 ) ) ) {
V_6 = - V_7 ;
goto error;
}
if ( V_54 )
V_6 = F_24 ( V_2 , V_58 ) ;
else
V_6 = V_57 ( V_2 , V_58 ) ;
if ( V_6 < 0 )
goto error;
if ( F_25 ( V_56 , V_58 , sizeof( * V_56 ) ) ||
F_5 ( V_58 -> V_62 , & V_56 -> V_62 ) ) {
V_6 = - V_7 ;
goto error;
}
if ( ! V_54 ) {
unsigned int V_63 = F_13 ( V_12 ) ;
if ( V_63 )
V_12 -> V_13 = V_63 ;
}
error:
F_26 ( V_58 ) ;
return V_6 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_64 , struct V_65 T_2 * V_56 )
{
T_7 V_66 ;
T_5 V_8 ;
int V_6 ;
if ( ! V_2 -> V_12 )
return - V_59 ;
if ( V_2 -> V_9 != V_64 )
return - V_67 ;
if ( V_2 -> V_12 -> V_39 -> V_41 == V_68 )
return - V_69 ;
if ( F_7 ( V_66 , & V_56 -> V_66 ) ||
F_7 ( V_8 , & V_56 -> V_8 ) )
return - V_7 ;
if ( V_64 == V_10 )
V_6 = F_28 ( V_2 , F_29 ( V_66 ) , V_8 ) ;
else
V_6 = F_30 ( V_2 , F_29 ( V_66 ) , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_6 , & V_56 -> V_70 ) )
return - V_7 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_64 , struct V_71 T_2 * V_56 )
{
T_7 V_66 ;
T_7 T_2 * V_72 ;
T_5 V_8 ;
void T_2 * * V_73 ;
int V_6 , V_74 , V_75 ;
if ( ! V_2 -> V_12 )
return - V_59 ;
if ( V_2 -> V_9 != V_64 )
return - V_67 ;
if ( ( V_74 = V_2 -> V_12 -> V_76 ) > 128 )
return - V_67 ;
if ( F_7 ( V_66 , & V_56 -> V_73 ) ||
F_7 ( V_8 , & V_56 -> V_8 ) )
return - V_7 ;
V_72 = F_29 ( V_66 ) ;
V_73 = F_22 ( sizeof( void T_2 * ) * V_74 , V_60 ) ;
if ( V_73 == NULL )
return - V_61 ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ ) {
T_5 V_77 ;
if ( F_7 ( V_77 , V_72 ) ) {
F_26 ( V_73 ) ;
return - V_7 ;
}
V_73 [ V_75 ] = F_29 ( V_77 ) ;
V_72 ++ ;
}
if ( V_64 == V_10 )
V_6 = F_32 ( V_2 , V_73 , V_8 ) ;
else
V_6 = F_33 ( V_2 , V_73 , V_8 ) ;
if ( V_6 >= 0 ) {
if ( F_5 ( V_6 , & V_56 -> V_70 ) )
V_6 = - V_7 ;
}
F_26 ( V_73 ) ;
return V_6 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_78 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_79 * V_39 ;
volatile struct V_80 * V_81 ;
T_5 V_82 ;
struct V_80 V_83 ;
struct V_79 V_84 ;
T_6 V_13 ;
int V_6 ;
if ( F_35 ( ! V_12 ) )
return - V_67 ;
if ( F_7 ( V_82 , & V_3 -> V_85 ) ||
F_7 ( V_83 . V_44 , & V_3 -> V_86 . V_81 . V_44 ) ||
F_7 ( V_83 . V_21 , & V_3 -> V_86 . V_81 . V_21 ) )
return - V_7 ;
if ( V_82 & V_87 ) {
V_6 = F_36 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_39 = V_12 -> V_39 ;
V_81 = V_12 -> V_81 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_37 ( V_2 ) ;
if ( ! ( V_82 & V_88 ) )
V_81 -> V_44 = V_83 . V_44 ;
else
V_83 . V_44 = V_81 -> V_44 % V_13 ;
if ( ! ( V_82 & V_89 ) )
V_81 -> V_21 = V_83 . V_21 ;
else
V_83 . V_21 = V_81 -> V_21 ;
V_84 . V_41 = V_39 -> V_41 ;
V_84 . V_45 = V_39 -> V_45 % V_13 ;
V_84 . V_43 = V_39 -> V_43 ;
V_84 . V_49 = V_39 -> V_49 ;
V_84 . V_50 = V_39 -> V_50 ;
F_38 ( V_2 ) ;
if ( F_5 ( V_84 . V_41 , & V_3 -> V_90 . V_39 . V_41 ) ||
F_5 ( V_84 . V_45 , & V_3 -> V_90 . V_39 . V_45 ) ||
F_18 ( & V_84 . V_43 , & V_3 -> V_90 . V_39 . V_43 ) ||
F_5 ( V_84 . V_49 , & V_3 -> V_90 . V_39 . V_49 ) ||
F_18 ( & V_84 . V_50 ,
& V_3 -> V_90 . V_39 . V_50 ) ||
F_5 ( V_83 . V_44 , & V_3 -> V_86 . V_81 . V_44 ) ||
F_5 ( V_83 . V_21 , & V_3 -> V_86 . V_81 . V_21 ) )
return - V_7 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_91 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_79 * V_39 ;
volatile struct V_80 * V_81 ;
T_5 V_82 ;
struct V_80 V_83 ;
struct V_79 V_84 ;
T_6 V_13 ;
int V_6 ;
if ( F_35 ( ! V_12 ) )
return - V_67 ;
if ( F_7 ( V_82 , & V_3 -> V_85 ) ||
F_7 ( V_83 . V_44 , & V_3 -> V_86 . V_81 . V_44 ) ||
F_7 ( V_83 . V_21 , & V_3 -> V_86 . V_81 . V_21 ) )
return - V_7 ;
if ( V_82 & V_87 ) {
V_6 = F_36 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_39 = V_12 -> V_39 ;
V_81 = V_12 -> V_81 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_37 ( V_2 ) ;
if ( ! ( V_82 & V_88 ) )
V_81 -> V_44 = V_83 . V_44 ;
else
V_83 . V_44 = V_81 -> V_44 % V_13 ;
if ( ! ( V_82 & V_89 ) )
V_81 -> V_21 = V_83 . V_21 ;
else
V_83 . V_21 = V_81 -> V_21 ;
V_84 . V_41 = V_39 -> V_41 ;
V_84 . V_45 = V_39 -> V_45 % V_13 ;
V_84 . V_43 = V_39 -> V_43 ;
V_84 . V_49 = V_39 -> V_49 ;
V_84 . V_50 = V_39 -> V_50 ;
F_38 ( V_2 ) ;
if ( F_5 ( V_84 . V_41 , & V_3 -> V_90 . V_39 . V_41 ) ||
F_5 ( V_84 . V_45 , & V_3 -> V_90 . V_39 . V_45 ) ||
F_20 ( & V_84 . V_43 , & V_3 -> V_90 . V_39 . V_43 ) ||
F_5 ( V_84 . V_49 , & V_3 -> V_90 . V_39 . V_49 ) ||
F_20 ( & V_84 . V_50 , & V_3 -> V_90 . V_39 . V_50 ) ||
F_5 ( V_83 . V_44 , & V_3 -> V_86 . V_81 . V_44 ) ||
F_5 ( V_83 . V_21 , & V_3 -> V_86 . V_81 . V_21 ) )
return - V_7 ;
return 0 ;
}
static long F_40 ( struct V_92 * V_92 , unsigned int V_93 , unsigned long V_94 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
void T_2 * V_97 = F_29 ( V_94 ) ;
V_96 = V_92 -> V_98 ;
if ( ! V_96 )
return - V_59 ;
V_2 = V_96 -> V_2 ;
if ( ! V_2 )
return - V_59 ;
V_96 -> V_99 = 1 ;
switch ( V_93 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_2 -> V_9 == V_10 )
return F_41 ( V_92 , V_2 , V_93 , V_97 ) ;
else
return F_42 ( V_92 , V_2 , V_93 , V_97 ) ;
case V_116 :
return F_21 ( V_2 , 1 , V_97 ) ;
case V_117 :
return F_21 ( V_2 , 0 , V_97 ) ;
case V_118 :
return F_14 ( V_2 , V_97 ) ;
case V_119 :
return F_16 ( V_2 , V_97 , false ) ;
case V_120 :
return F_16 ( V_2 , V_97 , true ) ;
case V_121 :
return F_34 ( V_2 , V_97 ) ;
case V_122 :
return F_15 ( V_2 , V_97 ) ;
case V_123 :
return F_27 ( V_2 , V_10 , V_97 ) ;
case V_124 :
return F_27 ( V_2 , V_125 , V_97 ) ;
case V_126 :
return F_31 ( V_2 , V_10 , V_97 ) ;
case V_127 :
return F_31 ( V_2 , V_125 , V_97 ) ;
case V_128 :
return F_1 ( V_2 , V_97 ) ;
case V_129 :
return F_6 ( V_2 , V_97 ) ;
case V_130 :
return F_10 ( V_2 , V_97 ) ;
#ifdef F_43
case V_131 :
return F_19 ( V_2 , V_97 , false ) ;
case V_132 :
return F_19 ( V_2 , V_97 , true ) ;
case V_133 :
return F_39 ( V_2 , V_97 ) ;
case V_134 :
return F_44 ( V_2 , V_97 ) ;
#endif
}
return - V_135 ;
}
