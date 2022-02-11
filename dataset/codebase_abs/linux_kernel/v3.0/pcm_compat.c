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
F_7 ( V_17 . V_26 , & V_3 -> V_26 ) )
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
struct V_27 T_2 * V_3 )
{
struct V_28 V_29 ;
int V_6 ;
if ( F_7 ( V_29 . V_30 , & V_3 -> V_30 ) ||
F_7 ( V_29 . V_31 , & V_3 -> V_31 ) ||
F_7 ( V_29 . V_32 , & V_3 -> V_32 ) ||
F_7 ( V_29 . V_33 , & V_3 -> V_33 ) )
return - V_7 ;
V_6 = V_28 ( V_2 , & V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_29 . V_30 , & V_3 -> V_30 ) ||
F_5 ( V_29 . V_31 , & V_3 -> V_31 ) ||
F_5 ( V_29 . V_32 , & V_3 -> V_32 ) ||
F_5 ( V_29 . V_33 , & V_3 -> V_33 ) )
return - V_7 ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_34 T_2 * V_3 )
{
struct V_35 V_36 ;
int V_6 ;
V_6 = V_35 ( V_2 , & V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_36 . V_37 , & V_3 -> V_37 ) ||
F_5 ( V_36 . V_38 . V_39 , & V_3 -> V_38 . V_39 ) ||
F_5 ( V_36 . V_38 . V_40 , & V_3 -> V_38 . V_40 ) ||
F_5 ( V_36 . V_41 . V_39 , & V_3 -> V_41 . V_39 ) ||
F_5 ( V_36 . V_41 . V_40 , & V_3 -> V_41 . V_40 ) ||
F_5 ( V_36 . V_42 , & V_3 -> V_42 ) ||
F_5 ( V_36 . V_43 , & V_3 -> V_43 ) ||
F_5 ( V_36 . V_4 , & V_3 -> V_4 ) ||
F_5 ( V_36 . V_44 , & V_3 -> V_44 ) ||
F_5 ( V_36 . V_45 , & V_3 -> V_45 ) ||
F_5 ( V_36 . V_46 , & V_3 -> V_46 ) ||
F_5 ( V_36 . V_47 , & V_3 -> V_47 ) )
return - V_7 ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_48 ,
struct V_49 T_2 * V_50 )
{
struct V_51 * V_52 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_12 = V_2 -> V_12 ) )
return - V_53 ;
V_52 = F_18 ( V_50 , sizeof( * V_50 ) ) ;
if ( F_19 ( V_52 ) )
return F_20 ( V_52 ) ;
if ( V_48 )
V_6 = F_21 ( V_2 , V_52 ) ;
else
V_6 = V_51 ( V_2 , V_52 ) ;
if ( V_6 < 0 )
goto error;
if ( F_22 ( V_50 , V_52 , sizeof( * V_50 ) ) ||
F_5 ( V_52 -> V_54 , & V_50 -> V_54 ) ) {
V_6 = - V_7 ;
goto error;
}
if ( ! V_48 ) {
unsigned int V_55 = F_13 ( V_12 ) ;
if ( V_55 )
V_12 -> V_13 = V_55 ;
}
error:
F_23 ( V_52 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_56 , struct V_57 T_2 * V_50 )
{
T_7 V_58 ;
T_5 V_8 ;
int V_6 ;
if ( ! V_2 -> V_12 )
return - V_53 ;
if ( V_2 -> V_9 != V_56 )
return - V_59 ;
if ( V_2 -> V_12 -> V_36 -> V_37 == V_60 )
return - V_61 ;
if ( F_7 ( V_58 , & V_50 -> V_58 ) ||
F_7 ( V_8 , & V_50 -> V_8 ) )
return - V_7 ;
if ( V_56 == V_10 )
V_6 = F_25 ( V_2 , F_26 ( V_58 ) , V_8 ) ;
else
V_6 = F_27 ( V_2 , F_26 ( V_58 ) , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_6 , & V_50 -> V_62 ) )
return - V_7 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_56 , struct V_63 T_2 * V_50 )
{
T_7 V_58 ;
T_7 T_2 * V_64 ;
T_5 V_8 ;
void T_2 * * V_65 ;
int V_6 , V_66 , V_67 ;
if ( ! V_2 -> V_12 )
return - V_53 ;
if ( V_2 -> V_9 != V_56 )
return - V_59 ;
if ( ( V_66 = V_2 -> V_12 -> V_68 ) > 128 )
return - V_59 ;
if ( F_7 ( V_58 , & V_50 -> V_65 ) ||
F_7 ( V_8 , & V_50 -> V_8 ) )
return - V_7 ;
V_64 = F_26 ( V_58 ) ;
V_65 = F_29 ( sizeof( void T_2 * ) * V_66 , V_69 ) ;
if ( V_65 == NULL )
return - V_70 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
T_5 V_71 ;
if ( F_7 ( V_71 , V_64 ) ) {
F_23 ( V_65 ) ;
return - V_7 ;
}
V_65 [ V_66 ] = F_26 ( V_71 ) ;
V_64 ++ ;
}
if ( V_56 == V_10 )
V_6 = F_30 ( V_2 , V_65 , V_8 ) ;
else
V_6 = F_31 ( V_2 , V_65 , V_8 ) ;
if ( V_6 >= 0 ) {
if ( F_5 ( V_6 , & V_50 -> V_62 ) )
V_6 = - V_7 ;
}
F_23 ( V_65 ) ;
return V_6 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_72 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_73 * V_36 ;
volatile struct V_74 * V_75 ;
T_5 V_76 ;
struct V_74 V_77 ;
struct V_73 V_78 ;
T_6 V_13 ;
int V_6 ;
if ( F_33 ( ! V_12 ) )
return - V_59 ;
if ( F_7 ( V_76 , & V_3 -> V_79 ) ||
F_7 ( V_77 . V_42 , & V_3 -> V_80 . V_75 . V_42 ) ||
F_7 ( V_77 . V_21 , & V_3 -> V_80 . V_75 . V_21 ) )
return - V_7 ;
if ( V_76 & V_81 ) {
V_6 = F_34 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_36 = V_12 -> V_36 ;
V_75 = V_12 -> V_75 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_35 ( V_2 ) ;
if ( ! ( V_76 & V_82 ) )
V_75 -> V_42 = V_77 . V_42 ;
else
V_77 . V_42 = V_75 -> V_42 % V_13 ;
if ( ! ( V_76 & V_83 ) )
V_75 -> V_21 = V_77 . V_21 ;
else
V_77 . V_21 = V_75 -> V_21 ;
V_78 . V_37 = V_36 -> V_37 ;
V_78 . V_43 = V_36 -> V_43 % V_13 ;
V_78 . V_41 = V_36 -> V_41 ;
V_78 . V_47 = V_36 -> V_47 ;
F_36 ( V_2 ) ;
if ( F_5 ( V_78 . V_37 , & V_3 -> V_84 . V_36 . V_37 ) ||
F_5 ( V_78 . V_43 , & V_3 -> V_84 . V_36 . V_43 ) ||
F_5 ( V_78 . V_41 . V_39 , & V_3 -> V_84 . V_36 . V_41 . V_39 ) ||
F_5 ( V_78 . V_41 . V_40 , & V_3 -> V_84 . V_36 . V_41 . V_40 ) ||
F_5 ( V_78 . V_47 , & V_3 -> V_84 . V_36 . V_47 ) ||
F_5 ( V_77 . V_42 , & V_3 -> V_80 . V_75 . V_42 ) ||
F_5 ( V_77 . V_21 , & V_3 -> V_80 . V_75 . V_21 ) )
return - V_7 ;
return 0 ;
}
static long F_37 ( struct V_85 * V_85 , unsigned int V_86 , unsigned long V_87 )
{
struct V_88 * V_89 ;
struct V_1 * V_2 ;
void T_2 * V_90 = F_26 ( V_87 ) ;
V_89 = V_85 -> V_91 ;
if ( ! V_89 )
return - V_53 ;
V_2 = V_89 -> V_2 ;
if ( ! V_2 )
return - V_53 ;
V_89 -> V_92 = 1 ;
switch ( V_86 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
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
if ( V_2 -> V_9 == V_10 )
return F_38 ( V_85 , V_2 , V_86 , V_90 ) ;
else
return F_39 ( V_85 , V_2 , V_86 , V_90 ) ;
case V_109 :
return F_17 ( V_2 , 1 , V_90 ) ;
case V_110 :
return F_17 ( V_2 , 0 , V_90 ) ;
case V_111 :
return F_14 ( V_2 , V_90 ) ;
case V_112 :
return F_16 ( V_2 , V_90 ) ;
case V_113 :
return F_32 ( V_2 , V_90 ) ;
case V_114 :
return F_15 ( V_2 , V_90 ) ;
case V_115 :
return F_24 ( V_2 , V_10 , V_90 ) ;
case V_116 :
return F_24 ( V_2 , V_117 , V_90 ) ;
case V_118 :
return F_28 ( V_2 , V_10 , V_90 ) ;
case V_119 :
return F_28 ( V_2 , V_117 , V_90 ) ;
case V_120 :
return F_1 ( V_2 , V_90 ) ;
case V_121 :
return F_6 ( V_2 , V_90 ) ;
case V_122 :
return F_10 ( V_2 , V_90 ) ;
}
return - V_123 ;
}
