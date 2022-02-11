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
struct V_36 T_2 * V_3 )
{
struct V_37 V_38 ;
int V_6 ;
V_6 = V_37 ( V_2 , & V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_38 . V_39 , & V_3 -> V_39 ) ||
F_17 ( & V_38 . V_40 , & V_3 -> V_40 ) ||
F_17 ( & V_38 . V_41 , & V_3 -> V_41 ) ||
F_5 ( V_38 . V_42 , & V_3 -> V_42 ) ||
F_5 ( V_38 . V_43 , & V_3 -> V_43 ) ||
F_5 ( V_38 . V_4 , & V_3 -> V_4 ) ||
F_5 ( V_38 . V_44 , & V_3 -> V_44 ) ||
F_5 ( V_38 . V_45 , & V_3 -> V_45 ) ||
F_5 ( V_38 . V_46 , & V_3 -> V_46 ) ||
F_5 ( V_38 . V_47 , & V_3 -> V_47 ) ||
F_17 ( & V_38 . V_48 , & V_3 -> V_48 ) )
return - V_7 ;
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_49 ,
struct V_50 T_2 * V_51 )
{
struct V_52 * V_53 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_12 = V_2 -> V_12 ) )
return - V_54 ;
V_53 = F_19 ( V_51 , sizeof( * V_51 ) ) ;
if ( F_20 ( V_53 ) )
return F_21 ( V_53 ) ;
if ( V_49 )
V_6 = F_22 ( V_2 , V_53 ) ;
else
V_6 = V_52 ( V_2 , V_53 ) ;
if ( V_6 < 0 )
goto error;
if ( F_23 ( V_51 , V_53 , sizeof( * V_51 ) ) ||
F_5 ( V_53 -> V_55 , & V_51 -> V_55 ) ) {
V_6 = - V_7 ;
goto error;
}
if ( ! V_49 ) {
unsigned int V_56 = F_13 ( V_12 ) ;
if ( V_56 )
V_12 -> V_13 = V_56 ;
}
error:
F_24 ( V_53 ) ;
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_57 , struct V_58 T_2 * V_51 )
{
T_7 V_59 ;
T_5 V_8 ;
int V_6 ;
if ( ! V_2 -> V_12 )
return - V_54 ;
if ( V_2 -> V_9 != V_57 )
return - V_60 ;
if ( V_2 -> V_12 -> V_38 -> V_39 == V_61 )
return - V_62 ;
if ( F_7 ( V_59 , & V_51 -> V_59 ) ||
F_7 ( V_8 , & V_51 -> V_8 ) )
return - V_7 ;
if ( V_57 == V_10 )
V_6 = F_26 ( V_2 , F_27 ( V_59 ) , V_8 ) ;
else
V_6 = F_28 ( V_2 , F_27 ( V_59 ) , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_6 , & V_51 -> V_63 ) )
return - V_7 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_57 , struct V_64 T_2 * V_51 )
{
T_7 V_59 ;
T_7 T_2 * V_65 ;
T_5 V_8 ;
void T_2 * * V_66 ;
int V_6 , V_67 , V_68 ;
if ( ! V_2 -> V_12 )
return - V_54 ;
if ( V_2 -> V_9 != V_57 )
return - V_60 ;
if ( ( V_67 = V_2 -> V_12 -> V_69 ) > 128 )
return - V_60 ;
if ( F_7 ( V_59 , & V_51 -> V_66 ) ||
F_7 ( V_8 , & V_51 -> V_8 ) )
return - V_7 ;
V_65 = F_27 ( V_59 ) ;
V_66 = F_30 ( sizeof( void T_2 * ) * V_67 , V_70 ) ;
if ( V_66 == NULL )
return - V_71 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
T_5 V_72 ;
if ( F_7 ( V_72 , V_65 ) ) {
F_24 ( V_66 ) ;
return - V_7 ;
}
V_66 [ V_68 ] = F_27 ( V_72 ) ;
V_65 ++ ;
}
if ( V_57 == V_10 )
V_6 = F_31 ( V_2 , V_66 , V_8 ) ;
else
V_6 = F_32 ( V_2 , V_66 , V_8 ) ;
if ( V_6 >= 0 ) {
if ( F_5 ( V_6 , & V_51 -> V_63 ) )
V_6 = - V_7 ;
}
F_24 ( V_66 ) ;
return V_6 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_73 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_74 * V_38 ;
volatile struct V_75 * V_76 ;
T_5 V_77 ;
struct V_75 V_78 ;
struct V_74 V_79 ;
T_6 V_13 ;
int V_6 ;
if ( F_34 ( ! V_12 ) )
return - V_60 ;
if ( F_7 ( V_77 , & V_3 -> V_80 ) ||
F_7 ( V_78 . V_42 , & V_3 -> V_81 . V_76 . V_42 ) ||
F_7 ( V_78 . V_21 , & V_3 -> V_81 . V_76 . V_21 ) )
return - V_7 ;
if ( V_77 & V_82 ) {
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_38 = V_12 -> V_38 ;
V_76 = V_12 -> V_76 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_36 ( V_2 ) ;
if ( ! ( V_77 & V_83 ) )
V_76 -> V_42 = V_78 . V_42 ;
else
V_78 . V_42 = V_76 -> V_42 % V_13 ;
if ( ! ( V_77 & V_84 ) )
V_76 -> V_21 = V_78 . V_21 ;
else
V_78 . V_21 = V_76 -> V_21 ;
V_79 . V_39 = V_38 -> V_39 ;
V_79 . V_43 = V_38 -> V_43 % V_13 ;
V_79 . V_41 = V_38 -> V_41 ;
V_79 . V_47 = V_38 -> V_47 ;
V_79 . V_48 = V_38 -> V_48 ;
F_37 ( V_2 ) ;
if ( F_5 ( V_79 . V_39 , & V_3 -> V_85 . V_38 . V_39 ) ||
F_5 ( V_79 . V_43 , & V_3 -> V_85 . V_38 . V_43 ) ||
F_17 ( & V_79 . V_41 , & V_3 -> V_85 . V_38 . V_41 ) ||
F_5 ( V_79 . V_47 , & V_3 -> V_85 . V_38 . V_47 ) ||
F_17 ( & V_79 . V_48 ,
& V_3 -> V_85 . V_38 . V_48 ) ||
F_5 ( V_78 . V_42 , & V_3 -> V_81 . V_76 . V_42 ) ||
F_5 ( V_78 . V_21 , & V_3 -> V_81 . V_76 . V_21 ) )
return - V_7 ;
return 0 ;
}
static long F_38 ( struct V_86 * V_86 , unsigned int V_87 , unsigned long V_88 )
{
struct V_89 * V_90 ;
struct V_1 * V_2 ;
void T_2 * V_91 = F_27 ( V_88 ) ;
V_90 = V_86 -> V_92 ;
if ( ! V_90 )
return - V_54 ;
V_2 = V_90 -> V_2 ;
if ( ! V_2 )
return - V_54 ;
V_90 -> V_93 = 1 ;
switch ( V_87 ) {
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
case V_109 :
if ( V_2 -> V_9 == V_10 )
return F_39 ( V_86 , V_2 , V_87 , V_91 ) ;
else
return F_40 ( V_86 , V_2 , V_87 , V_91 ) ;
case V_110 :
return F_18 ( V_2 , 1 , V_91 ) ;
case V_111 :
return F_18 ( V_2 , 0 , V_91 ) ;
case V_112 :
return F_14 ( V_2 , V_91 ) ;
case V_113 :
return F_16 ( V_2 , V_91 ) ;
case V_114 :
return F_33 ( V_2 , V_91 ) ;
case V_115 :
return F_15 ( V_2 , V_91 ) ;
case V_116 :
return F_25 ( V_2 , V_10 , V_91 ) ;
case V_117 :
return F_25 ( V_2 , V_118 , V_91 ) ;
case V_119 :
return F_29 ( V_2 , V_10 , V_91 ) ;
case V_120 :
return F_29 ( V_2 , V_118 , V_91 ) ;
case V_121 :
return F_1 ( V_2 , V_91 ) ;
case V_122 :
return F_6 ( V_2 , V_91 ) ;
case V_123 :
return F_10 ( V_2 , V_91 ) ;
}
return - V_124 ;
}
