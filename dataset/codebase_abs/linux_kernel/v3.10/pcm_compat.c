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
F_17 ( & V_36 . V_38 , & V_3 -> V_38 ) ||
F_17 ( & V_36 . V_39 , & V_3 -> V_39 ) ||
F_5 ( V_36 . V_40 , & V_3 -> V_40 ) ||
F_5 ( V_36 . V_41 , & V_3 -> V_41 ) ||
F_5 ( V_36 . V_4 , & V_3 -> V_4 ) ||
F_5 ( V_36 . V_42 , & V_3 -> V_42 ) ||
F_5 ( V_36 . V_43 , & V_3 -> V_43 ) ||
F_5 ( V_36 . V_44 , & V_3 -> V_44 ) ||
F_5 ( V_36 . V_45 , & V_3 -> V_45 ) ||
F_17 ( & V_36 . V_46 , & V_3 -> V_46 ) )
return - V_7 ;
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_47 ,
struct V_48 T_2 * V_49 )
{
struct V_50 * V_51 ;
struct V_11 * V_12 ;
int V_6 ;
if ( ! ( V_12 = V_2 -> V_12 ) )
return - V_52 ;
V_51 = F_19 ( V_49 , sizeof( * V_49 ) ) ;
if ( F_20 ( V_51 ) )
return F_21 ( V_51 ) ;
if ( V_47 )
V_6 = F_22 ( V_2 , V_51 ) ;
else
V_6 = V_50 ( V_2 , V_51 ) ;
if ( V_6 < 0 )
goto error;
if ( F_23 ( V_49 , V_51 , sizeof( * V_49 ) ) ||
F_5 ( V_51 -> V_53 , & V_49 -> V_53 ) ) {
V_6 = - V_7 ;
goto error;
}
if ( ! V_47 ) {
unsigned int V_54 = F_13 ( V_12 ) ;
if ( V_54 )
V_12 -> V_13 = V_54 ;
}
error:
F_24 ( V_51 ) ;
return V_6 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_55 , struct V_56 T_2 * V_49 )
{
T_7 V_57 ;
T_5 V_8 ;
int V_6 ;
if ( ! V_2 -> V_12 )
return - V_52 ;
if ( V_2 -> V_9 != V_55 )
return - V_58 ;
if ( V_2 -> V_12 -> V_36 -> V_37 == V_59 )
return - V_60 ;
if ( F_7 ( V_57 , & V_49 -> V_57 ) ||
F_7 ( V_8 , & V_49 -> V_8 ) )
return - V_7 ;
if ( V_55 == V_10 )
V_6 = F_26 ( V_2 , F_27 ( V_57 ) , V_8 ) ;
else
V_6 = F_28 ( V_2 , F_27 ( V_57 ) , V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_5 ( V_6 , & V_49 -> V_61 ) )
return - V_7 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_55 , struct V_62 T_2 * V_49 )
{
T_7 V_57 ;
T_7 T_2 * V_63 ;
T_5 V_8 ;
void T_2 * * V_64 ;
int V_6 , V_65 , V_66 ;
if ( ! V_2 -> V_12 )
return - V_52 ;
if ( V_2 -> V_9 != V_55 )
return - V_58 ;
if ( ( V_65 = V_2 -> V_12 -> V_67 ) > 128 )
return - V_58 ;
if ( F_7 ( V_57 , & V_49 -> V_64 ) ||
F_7 ( V_8 , & V_49 -> V_8 ) )
return - V_7 ;
V_63 = F_27 ( V_57 ) ;
V_64 = F_30 ( sizeof( void T_2 * ) * V_65 , V_68 ) ;
if ( V_64 == NULL )
return - V_69 ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
T_5 V_70 ;
if ( F_7 ( V_70 , V_63 ) ) {
F_24 ( V_64 ) ;
return - V_7 ;
}
V_64 [ V_66 ] = F_27 ( V_70 ) ;
V_63 ++ ;
}
if ( V_55 == V_10 )
V_6 = F_31 ( V_2 , V_64 , V_8 ) ;
else
V_6 = F_32 ( V_2 , V_64 , V_8 ) ;
if ( V_6 >= 0 ) {
if ( F_5 ( V_6 , & V_49 -> V_61 ) )
V_6 = - V_7 ;
}
F_24 ( V_64 ) ;
return V_6 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_71 T_2 * V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
volatile struct V_72 * V_36 ;
volatile struct V_73 * V_74 ;
T_5 V_75 ;
struct V_73 V_76 ;
struct V_72 V_77 ;
T_6 V_13 ;
int V_6 ;
if ( F_34 ( ! V_12 ) )
return - V_58 ;
if ( F_7 ( V_75 , & V_3 -> V_78 ) ||
F_7 ( V_76 . V_40 , & V_3 -> V_79 . V_74 . V_40 ) ||
F_7 ( V_76 . V_21 , & V_3 -> V_79 . V_74 . V_21 ) )
return - V_7 ;
if ( V_75 & V_80 ) {
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_36 = V_12 -> V_36 ;
V_74 = V_12 -> V_74 ;
V_13 = F_13 ( V_12 ) ;
if ( ! V_13 )
V_13 = 0x7fffffff ;
F_36 ( V_2 ) ;
if ( ! ( V_75 & V_81 ) )
V_74 -> V_40 = V_76 . V_40 ;
else
V_76 . V_40 = V_74 -> V_40 % V_13 ;
if ( ! ( V_75 & V_82 ) )
V_74 -> V_21 = V_76 . V_21 ;
else
V_76 . V_21 = V_74 -> V_21 ;
V_77 . V_37 = V_36 -> V_37 ;
V_77 . V_41 = V_36 -> V_41 % V_13 ;
V_77 . V_39 = V_36 -> V_39 ;
V_77 . V_45 = V_36 -> V_45 ;
V_77 . V_46 = V_36 -> V_46 ;
F_37 ( V_2 ) ;
if ( F_5 ( V_77 . V_37 , & V_3 -> V_83 . V_36 . V_37 ) ||
F_5 ( V_77 . V_41 , & V_3 -> V_83 . V_36 . V_41 ) ||
F_17 ( & V_77 . V_39 , & V_3 -> V_83 . V_36 . V_39 ) ||
F_5 ( V_77 . V_45 , & V_3 -> V_83 . V_36 . V_45 ) ||
F_17 ( & V_77 . V_46 ,
& V_3 -> V_83 . V_36 . V_46 ) ||
F_5 ( V_76 . V_40 , & V_3 -> V_79 . V_74 . V_40 ) ||
F_5 ( V_76 . V_21 , & V_3 -> V_79 . V_74 . V_21 ) )
return - V_7 ;
return 0 ;
}
static long F_38 ( struct V_84 * V_84 , unsigned int V_85 , unsigned long V_86 )
{
struct V_87 * V_88 ;
struct V_1 * V_2 ;
void T_2 * V_89 = F_27 ( V_86 ) ;
V_88 = V_84 -> V_90 ;
if ( ! V_88 )
return - V_52 ;
V_2 = V_88 -> V_2 ;
if ( ! V_2 )
return - V_52 ;
V_88 -> V_91 = 1 ;
switch ( V_85 ) {
case V_92 :
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
if ( V_2 -> V_9 == V_10 )
return F_39 ( V_84 , V_2 , V_85 , V_89 ) ;
else
return F_40 ( V_84 , V_2 , V_85 , V_89 ) ;
case V_108 :
return F_18 ( V_2 , 1 , V_89 ) ;
case V_109 :
return F_18 ( V_2 , 0 , V_89 ) ;
case V_110 :
return F_14 ( V_2 , V_89 ) ;
case V_111 :
return F_16 ( V_2 , V_89 ) ;
case V_112 :
return F_33 ( V_2 , V_89 ) ;
case V_113 :
return F_15 ( V_2 , V_89 ) ;
case V_114 :
return F_25 ( V_2 , V_10 , V_89 ) ;
case V_115 :
return F_25 ( V_2 , V_116 , V_89 ) ;
case V_117 :
return F_29 ( V_2 , V_10 , V_89 ) ;
case V_118 :
return F_29 ( V_2 , V_116 , V_89 ) ;
case V_119 :
return F_1 ( V_2 , V_89 ) ;
case V_120 :
return F_6 ( V_2 , V_89 ) ;
case V_121 :
return F_10 ( V_2 , V_89 ) ;
}
return - V_122 ;
}
