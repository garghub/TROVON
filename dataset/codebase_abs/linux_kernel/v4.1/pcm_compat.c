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
int V_53 ,
struct V_54 T_2 * V_55 )
{
struct V_56 * V_57 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_12 = V_2 -> V_12 ) )
return - V_58 ;
V_57 = F_20 ( V_55 , sizeof( * V_55 ) ) ;
if ( F_21 ( V_57 ) )
return F_22 ( V_57 ) ;
if ( V_53 )
V_6 = F_23 ( V_2 , V_57 ) ;
else
V_6 = V_56 ( V_2 , V_57 ) ;
if ( V_6 < 0 )
goto error;
if ( F_24 ( V_55 , V_57 , sizeof( * V_55 ) ) ||
F_5 ( V_57 -> V_59 , & V_55 -> V_59 ) ) {
V_6 = - V_7 ;
goto error;
}
if ( ! V_53 ) {
unsigned int V_60 = F_13 ( V_12 ) ;
if ( V_60 )
V_12 -> V_13 = V_60 ;
}
error:
F_25 ( V_57 ) ;
return V_6 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_61 , struct V_62 T_2 * V_55 )
{
T_7 V_63 ;
T_5 V_8 ;
int V_6 ;
if ( ! V_2 -> V_12 )
return - V_58 ;
if ( V_2 -> V_9 != V_61 )
return - V_64 ;
if ( V_2 -> V_12 -> V_39 -> V_41 == V_65 )
return - V_66 ;
if ( F_7 ( V_63 , & V_55 -> V_63 ) ||
F_7 ( V_8 , & V_55 -> V_8 ) )
return - V_7 ;
if ( V_61 == V_10 )
V_6 = F_27 ( V_2 , F_28 ( V_63 ) , V_8 ) ;
else
V_6 = F_29 ( V_2 , F_28 ( V_63 ) , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_6 , & V_55 -> V_67 ) )
return - V_7 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_61 , struct V_68 T_2 * V_55 )
{
T_7 V_63 ;
T_7 T_2 * V_69 ;
T_5 V_8 ;
void T_2 * * V_70 ;
int V_6 , V_71 , V_72 ;
if ( ! V_2 -> V_12 )
return - V_58 ;
if ( V_2 -> V_9 != V_61 )
return - V_64 ;
if ( ( V_71 = V_2 -> V_12 -> V_73 ) > 128 )
return - V_64 ;
if ( F_7 ( V_63 , & V_55 -> V_70 ) ||
F_7 ( V_8 , & V_55 -> V_8 ) )
return - V_7 ;
V_69 = F_28 ( V_63 ) ;
V_70 = F_31 ( sizeof( void T_2 * ) * V_71 , V_74 ) ;
if ( V_70 == NULL )
return - V_75 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
T_5 V_76 ;
if ( F_7 ( V_76 , V_69 ) ) {
F_25 ( V_70 ) ;
return - V_7 ;
}
V_70 [ V_72 ] = F_28 ( V_76 ) ;
V_69 ++ ;
}
if ( V_61 == V_10 )
V_6 = F_32 ( V_2 , V_70 , V_8 ) ;
else
V_6 = F_33 ( V_2 , V_70 , V_8 ) ;
if ( V_6 >= 0 ) {
if ( F_5 ( V_6 , & V_55 -> V_67 ) )
V_6 = - V_7 ;
}
F_25 ( V_70 ) ;
return V_6 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_77 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_78 * V_39 ;
volatile struct V_79 * V_80 ;
T_5 V_81 ;
struct V_79 V_82 ;
struct V_78 V_83 ;
T_6 V_13 ;
int V_6 ;
if ( F_35 ( ! V_12 ) )
return - V_64 ;
if ( F_7 ( V_81 , & V_3 -> V_84 ) ||
F_7 ( V_82 . V_44 , & V_3 -> V_85 . V_80 . V_44 ) ||
F_7 ( V_82 . V_21 , & V_3 -> V_85 . V_80 . V_21 ) )
return - V_7 ;
if ( V_81 & V_86 ) {
V_6 = F_36 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_39 = V_12 -> V_39 ;
V_80 = V_12 -> V_80 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_37 ( V_2 ) ;
if ( ! ( V_81 & V_87 ) )
V_80 -> V_44 = V_82 . V_44 ;
else
V_82 . V_44 = V_80 -> V_44 % V_13 ;
if ( ! ( V_81 & V_88 ) )
V_80 -> V_21 = V_82 . V_21 ;
else
V_82 . V_21 = V_80 -> V_21 ;
V_83 . V_41 = V_39 -> V_41 ;
V_83 . V_45 = V_39 -> V_45 % V_13 ;
V_83 . V_43 = V_39 -> V_43 ;
V_83 . V_49 = V_39 -> V_49 ;
V_83 . V_50 = V_39 -> V_50 ;
F_38 ( V_2 ) ;
if ( F_5 ( V_83 . V_41 , & V_3 -> V_89 . V_39 . V_41 ) ||
F_5 ( V_83 . V_45 , & V_3 -> V_89 . V_39 . V_45 ) ||
F_18 ( & V_83 . V_43 , & V_3 -> V_89 . V_39 . V_43 ) ||
F_5 ( V_83 . V_49 , & V_3 -> V_89 . V_39 . V_49 ) ||
F_18 ( & V_83 . V_50 ,
& V_3 -> V_89 . V_39 . V_50 ) ||
F_5 ( V_82 . V_44 , & V_3 -> V_85 . V_80 . V_44 ) ||
F_5 ( V_82 . V_21 , & V_3 -> V_85 . V_80 . V_21 ) )
return - V_7 ;
return 0 ;
}
static long F_39 ( struct V_90 * V_90 , unsigned int V_91 , unsigned long V_92 )
{
struct V_93 * V_94 ;
struct V_1 * V_2 ;
void T_2 * V_95 = F_28 ( V_92 ) ;
V_94 = V_90 -> V_96 ;
if ( ! V_94 )
return - V_58 ;
V_2 = V_94 -> V_2 ;
if ( ! V_2 )
return - V_58 ;
V_94 -> V_97 = 1 ;
switch ( V_91 ) {
case V_98 :
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
if ( V_2 -> V_9 == V_10 )
return F_40 ( V_90 , V_2 , V_91 , V_95 ) ;
else
return F_41 ( V_90 , V_2 , V_91 , V_95 ) ;
case V_114 :
return F_19 ( V_2 , 1 , V_95 ) ;
case V_115 :
return F_19 ( V_2 , 0 , V_95 ) ;
case V_116 :
return F_14 ( V_2 , V_95 ) ;
case V_117 :
return F_16 ( V_2 , V_95 , false ) ;
case V_118 :
return F_16 ( V_2 , V_95 , true ) ;
case V_119 :
return F_34 ( V_2 , V_95 ) ;
case V_120 :
return F_15 ( V_2 , V_95 ) ;
case V_121 :
return F_26 ( V_2 , V_10 , V_95 ) ;
case V_122 :
return F_26 ( V_2 , V_123 , V_95 ) ;
case V_124 :
return F_30 ( V_2 , V_10 , V_95 ) ;
case V_125 :
return F_30 ( V_2 , V_123 , V_95 ) ;
case V_126 :
return F_1 ( V_2 , V_95 ) ;
case V_127 :
return F_6 ( V_2 , V_95 ) ;
case V_128 :
return F_10 ( V_2 , V_95 ) ;
}
return - V_129 ;
}
