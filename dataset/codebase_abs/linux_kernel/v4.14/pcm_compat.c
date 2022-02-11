static int F_1 ( struct V_1 * V_2 ,
T_1 T_2 * V_3 )
{
T_3 V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_3 ( V_4 , V_3 ) )
return - V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_4 T_2 * V_3 )
{
T_5 V_6 ;
int V_7 ;
if ( F_5 ( V_6 , V_3 ) )
return - V_5 ;
if ( V_2 -> V_8 == V_9 )
V_7 = F_6 ( V_2 , V_6 ) ;
else
V_7 = F_7 ( V_2 , V_6 ) ;
if ( F_3 ( V_7 , V_3 ) )
return - V_5 ;
return V_7 < 0 ? V_7 : 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_4 T_2 * V_3 )
{
T_5 V_6 ;
int V_7 ;
if ( F_5 ( V_6 , V_3 ) )
return - V_5 ;
if ( V_2 -> V_8 == V_9 )
V_7 = F_9 ( V_2 , V_6 ) ;
else
V_7 = F_10 ( V_2 , V_6 ) ;
if ( F_3 ( V_7 , V_3 ) )
return - V_5 ;
return V_7 < 0 ? V_7 : 0 ;
}
static T_5 F_11 ( struct V_10 * V_11 )
{
T_5 V_12 ;
if ( ! V_11 -> V_13 )
return 0 ;
V_12 = V_11 -> V_13 ;
while ( V_12 * 2 <= 0x7fffffffUL - V_11 -> V_13 )
V_12 *= 2 ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_14 T_2 * V_3 )
{
struct V_15 V_16 ;
T_5 V_12 ;
int V_7 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( F_5 ( V_16 . V_17 , & V_3 -> V_17 ) ||
F_5 ( V_16 . V_18 , & V_3 -> V_18 ) ||
F_5 ( V_16 . V_19 , & V_3 -> V_19 ) ||
F_5 ( V_16 . V_20 , & V_3 -> V_20 ) ||
F_5 ( V_16 . V_21 , & V_3 -> V_21 ) ||
F_5 ( V_16 . V_22 , & V_3 -> V_22 ) ||
F_5 ( V_16 . V_23 , & V_3 -> V_23 ) ||
F_5 ( V_16 . V_24 , & V_3 -> V_24 ) ||
F_5 ( V_16 . V_25 , & V_3 -> V_25 ) ||
F_5 ( V_16 . V_26 , & V_3 -> V_26 ) ||
F_5 ( V_16 . V_27 , & V_3 -> V_27 ) )
return - V_5 ;
V_12 = F_11 ( V_2 -> V_11 ) ;
if ( V_12 && V_16 . V_25 >= V_12 )
V_16 . V_25 = V_2 -> V_11 -> V_12 ;
V_7 = V_15 ( V_2 , & V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_12 && F_3 ( V_12 , & V_3 -> V_12 ) )
return - V_5 ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_28 T_2 * V_3 )
{
struct V_29 V_30 ;
int V_7 ;
if ( F_5 ( V_30 . V_31 , & V_3 -> V_31 ) ||
F_5 ( V_30 . V_32 , & V_3 -> V_32 ) ||
F_5 ( V_30 . V_33 , & V_3 -> V_33 ) ||
F_5 ( V_30 . V_34 , & V_3 -> V_34 ) )
return - V_5 ;
V_7 = V_29 ( V_2 , & V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_3 ( V_30 . V_31 , & V_3 -> V_31 ) ||
F_3 ( V_30 . V_32 , & V_3 -> V_32 ) ||
F_3 ( V_30 . V_33 , & V_3 -> V_33 ) ||
F_3 ( V_30 . V_34 , & V_3 -> V_34 ) )
return - V_5 ;
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_35 T_2 * V_3 ,
bool V_36 )
{
struct V_37 V_38 ;
int V_7 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_36 && F_5 ( V_38 . V_39 ,
( T_4 T_2 * ) ( & V_3 -> V_39 ) ) )
return - V_5 ;
V_7 = V_37 ( V_2 , & V_38 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_15 ( V_3 , sizeof( * V_3 ) ) )
return - V_5 ;
if ( F_3 ( V_38 . V_40 , & V_3 -> V_40 ) ||
F_16 ( & V_38 . V_41 , & V_3 -> V_41 ) ||
F_16 ( & V_38 . V_42 , & V_3 -> V_42 ) ||
F_3 ( V_38 . V_43 , & V_3 -> V_43 ) ||
F_3 ( V_38 . V_44 , & V_3 -> V_44 ) ||
F_3 ( V_38 . V_4 , & V_3 -> V_4 ) ||
F_3 ( V_38 . V_45 , & V_3 -> V_45 ) ||
F_3 ( V_38 . V_46 , & V_3 -> V_46 ) ||
F_3 ( V_38 . V_47 , & V_3 -> V_47 ) ||
F_3 ( V_38 . V_48 , & V_3 -> V_48 ) ||
F_3 ( V_38 . V_39 , & V_3 -> V_39 ) ||
F_16 ( & V_38 . V_49 , & V_3 -> V_49 ) ||
F_16 ( & V_38 . V_50 , & V_3 -> V_50 ) ||
F_3 ( V_38 . V_51 , & V_3 -> V_51 ) )
return - V_5 ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_52 T_2 * V_3 ,
bool V_36 )
{
struct V_37 V_38 ;
int V_7 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
if ( V_36 && F_5 ( V_38 . V_39 ,
( T_4 T_2 * ) ( & V_3 -> V_39 ) ) )
return - V_5 ;
V_7 = V_37 ( V_2 , & V_38 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_15 ( V_3 , sizeof( * V_3 ) ) )
return - V_5 ;
if ( F_3 ( V_38 . V_40 , & V_3 -> V_40 ) ||
F_18 ( & V_38 . V_41 , & V_3 -> V_41 ) ||
F_18 ( & V_38 . V_42 , & V_3 -> V_42 ) ||
F_3 ( V_38 . V_43 , & V_3 -> V_43 ) ||
F_3 ( V_38 . V_44 , & V_3 -> V_44 ) ||
F_3 ( V_38 . V_4 , & V_3 -> V_4 ) ||
F_3 ( V_38 . V_45 , & V_3 -> V_45 ) ||
F_3 ( V_38 . V_46 , & V_3 -> V_46 ) ||
F_3 ( V_38 . V_47 , & V_3 -> V_47 ) ||
F_3 ( V_38 . V_48 , & V_3 -> V_48 ) ||
F_3 ( V_38 . V_39 , & V_3 -> V_39 ) ||
F_18 ( & V_38 . V_49 , & V_3 -> V_49 ) ||
F_18 ( & V_38 . V_50 , & V_3 -> V_50 ) ||
F_3 ( V_38 . V_51 , & V_3 -> V_51 ) )
return - V_5 ;
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_53 ,
struct V_54 T_2 * V_55 )
{
struct V_56 * V_57 ;
struct V_10 * V_11 ;
int V_7 ;
if ( ! ( V_11 = V_2 -> V_11 ) )
return - V_58 ;
V_57 = F_20 ( sizeof( * V_57 ) , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
if ( F_21 ( V_57 , V_55 , sizeof( * V_55 ) ) ) {
V_7 = - V_5 ;
goto error;
}
if ( V_53 )
V_7 = F_22 ( V_2 , V_57 ) ;
else
V_7 = V_56 ( V_2 , V_57 ) ;
if ( V_7 < 0 )
goto error;
if ( F_23 ( V_55 , V_57 , sizeof( * V_55 ) ) ||
F_3 ( V_57 -> V_61 , & V_55 -> V_61 ) ) {
V_7 = - V_5 ;
goto error;
}
if ( ! V_53 ) {
unsigned int V_62 = F_11 ( V_11 ) ;
if ( V_62 )
V_11 -> V_12 = V_62 ;
}
error:
F_24 ( V_57 ) ;
return V_7 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_63 , struct V_64 T_2 * V_55 )
{
T_6 V_65 ;
T_4 V_6 ;
int V_7 ;
if ( ! V_2 -> V_11 )
return - V_58 ;
if ( V_2 -> V_8 != V_63 )
return - V_66 ;
if ( V_2 -> V_11 -> V_38 -> V_40 == V_67 )
return - V_68 ;
if ( F_5 ( V_65 , & V_55 -> V_65 ) ||
F_5 ( V_6 , & V_55 -> V_6 ) )
return - V_5 ;
if ( V_63 == V_9 )
V_7 = F_26 ( V_2 , F_27 ( V_65 ) , V_6 ) ;
else
V_7 = F_28 ( V_2 , F_27 ( V_65 ) , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_3 ( V_7 , & V_55 -> V_69 ) )
return - V_5 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_63 , struct V_70 T_2 * V_55 )
{
T_6 V_65 ;
T_6 T_2 * V_71 ;
T_4 V_6 ;
void T_2 * * V_72 ;
int V_7 , V_73 , V_74 ;
if ( ! V_2 -> V_11 )
return - V_58 ;
if ( V_2 -> V_8 != V_63 )
return - V_66 ;
if ( ( V_73 = V_2 -> V_11 -> V_75 ) > 128 )
return - V_66 ;
if ( F_5 ( V_65 , & V_55 -> V_72 ) ||
F_5 ( V_6 , & V_55 -> V_6 ) )
return - V_5 ;
V_71 = F_27 ( V_65 ) ;
V_72 = F_20 ( sizeof( void T_2 * ) * V_73 , V_59 ) ;
if ( V_72 == NULL )
return - V_60 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
T_4 V_76 ;
if ( F_5 ( V_76 , V_71 ) ) {
F_24 ( V_72 ) ;
return - V_5 ;
}
V_72 [ V_74 ] = F_27 ( V_76 ) ;
V_71 ++ ;
}
if ( V_63 == V_9 )
V_7 = F_30 ( V_2 , V_72 , V_6 ) ;
else
V_7 = F_31 ( V_2 , V_72 , V_6 ) ;
if ( V_7 >= 0 ) {
if ( F_3 ( V_7 , & V_55 -> V_69 ) )
V_7 = - V_5 ;
}
F_24 ( V_72 ) ;
return V_7 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_77 T_2 * V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
volatile struct V_78 * V_38 ;
volatile struct V_79 * V_80 ;
T_4 V_81 ;
struct V_79 V_82 ;
struct V_78 V_83 ;
T_5 V_12 ;
int V_7 ;
if ( F_33 ( ! V_11 ) )
return - V_66 ;
if ( F_5 ( V_81 , & V_3 -> V_84 ) ||
F_5 ( V_82 . V_43 , & V_3 -> V_85 . V_80 . V_43 ) ||
F_5 ( V_82 . V_20 , & V_3 -> V_85 . V_80 . V_20 ) )
return - V_5 ;
if ( V_81 & V_86 ) {
V_7 = F_34 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_38 = V_11 -> V_38 ;
V_80 = V_11 -> V_80 ;
V_12 = F_11 ( V_11 ) ;
if ( ! V_12 )
V_12 = 0x7fffffff ;
F_35 ( V_2 ) ;
if ( ! ( V_81 & V_87 ) )
V_80 -> V_43 = V_82 . V_43 ;
else
V_82 . V_43 = V_80 -> V_43 % V_12 ;
if ( ! ( V_81 & V_88 ) )
V_80 -> V_20 = V_82 . V_20 ;
else
V_82 . V_20 = V_80 -> V_20 ;
V_83 . V_40 = V_38 -> V_40 ;
V_83 . V_44 = V_38 -> V_44 % V_12 ;
V_83 . V_42 = V_38 -> V_42 ;
V_83 . V_48 = V_38 -> V_48 ;
V_83 . V_49 = V_38 -> V_49 ;
F_36 ( V_2 ) ;
if ( F_3 ( V_83 . V_40 , & V_3 -> V_89 . V_38 . V_40 ) ||
F_3 ( V_83 . V_44 , & V_3 -> V_89 . V_38 . V_44 ) ||
F_16 ( & V_83 . V_42 , & V_3 -> V_89 . V_38 . V_42 ) ||
F_3 ( V_83 . V_48 , & V_3 -> V_89 . V_38 . V_48 ) ||
F_16 ( & V_83 . V_49 ,
& V_3 -> V_89 . V_38 . V_49 ) ||
F_3 ( V_82 . V_43 , & V_3 -> V_85 . V_80 . V_43 ) ||
F_3 ( V_82 . V_20 , & V_3 -> V_85 . V_80 . V_20 ) )
return - V_5 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_90 T_2 * V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
volatile struct V_78 * V_38 ;
volatile struct V_79 * V_80 ;
T_4 V_81 ;
struct V_79 V_82 ;
struct V_78 V_83 ;
T_5 V_12 ;
int V_7 ;
if ( F_33 ( ! V_11 ) )
return - V_66 ;
if ( F_5 ( V_81 , & V_3 -> V_84 ) ||
F_5 ( V_82 . V_43 , & V_3 -> V_85 . V_80 . V_43 ) ||
F_5 ( V_82 . V_20 , & V_3 -> V_85 . V_80 . V_20 ) )
return - V_5 ;
if ( V_81 & V_86 ) {
V_7 = F_34 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_38 = V_11 -> V_38 ;
V_80 = V_11 -> V_80 ;
V_12 = F_11 ( V_11 ) ;
if ( ! V_12 )
V_12 = 0x7fffffff ;
F_35 ( V_2 ) ;
if ( ! ( V_81 & V_87 ) )
V_80 -> V_43 = V_82 . V_43 ;
else
V_82 . V_43 = V_80 -> V_43 % V_12 ;
if ( ! ( V_81 & V_88 ) )
V_80 -> V_20 = V_82 . V_20 ;
else
V_82 . V_20 = V_80 -> V_20 ;
V_83 . V_40 = V_38 -> V_40 ;
V_83 . V_44 = V_38 -> V_44 % V_12 ;
V_83 . V_42 = V_38 -> V_42 ;
V_83 . V_48 = V_38 -> V_48 ;
V_83 . V_49 = V_38 -> V_49 ;
F_36 ( V_2 ) ;
if ( F_3 ( V_83 . V_40 , & V_3 -> V_89 . V_38 . V_40 ) ||
F_3 ( V_83 . V_44 , & V_3 -> V_89 . V_38 . V_44 ) ||
F_18 ( & V_83 . V_42 , & V_3 -> V_89 . V_38 . V_42 ) ||
F_3 ( V_83 . V_48 , & V_3 -> V_89 . V_38 . V_48 ) ||
F_18 ( & V_83 . V_49 , & V_3 -> V_89 . V_38 . V_49 ) ||
F_3 ( V_82 . V_43 , & V_3 -> V_85 . V_80 . V_43 ) ||
F_3 ( V_82 . V_20 , & V_3 -> V_85 . V_80 . V_20 ) )
return - V_5 ;
return 0 ;
}
static long F_38 ( struct V_91 * V_91 , unsigned int V_92 , unsigned long V_93 )
{
struct V_94 * V_95 ;
struct V_1 * V_2 ;
void T_2 * V_96 = F_27 ( V_93 ) ;
V_95 = V_91 -> V_97 ;
if ( ! V_95 )
return - V_58 ;
V_2 = V_95 -> V_2 ;
if ( ! V_2 )
return - V_58 ;
V_95 -> V_98 = 1 ;
switch ( V_92 ) {
case V_99 :
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
return F_39 ( V_91 , V_2 , V_92 , V_96 ) ;
case V_116 :
return F_19 ( V_2 , 1 , V_96 ) ;
case V_117 :
return F_19 ( V_2 , 0 , V_96 ) ;
case V_118 :
return F_12 ( V_2 , V_96 ) ;
case V_119 :
return F_14 ( V_2 , V_96 , false ) ;
case V_120 :
return F_14 ( V_2 , V_96 , true ) ;
case V_121 :
return F_32 ( V_2 , V_96 ) ;
case V_122 :
return F_13 ( V_2 , V_96 ) ;
case V_123 :
return F_25 ( V_2 , V_9 , V_96 ) ;
case V_124 :
return F_25 ( V_2 , V_125 , V_96 ) ;
case V_126 :
return F_29 ( V_2 , V_9 , V_96 ) ;
case V_127 :
return F_29 ( V_2 , V_125 , V_96 ) ;
case V_128 :
return F_1 ( V_2 , V_96 ) ;
case V_129 :
return F_4 ( V_2 , V_96 ) ;
case V_130 :
return F_8 ( V_2 , V_96 ) ;
#ifdef F_40
case V_131 :
return F_17 ( V_2 , V_96 , false ) ;
case V_132 :
return F_17 ( V_2 , V_96 , true ) ;
case V_133 :
return F_37 ( V_2 , V_96 ) ;
case V_134 :
return F_41 ( V_2 , V_96 ) ;
#endif
}
return - V_135 ;
}
