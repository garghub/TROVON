static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_1 )
{
F_4 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static inline T_1 F_5 ( T_1 V_1 )
{
return F_2 ( V_2 . V_5 + V_1 ) ;
}
static inline void F_6 ( T_1 V_4 , T_1 V_1 )
{
F_4 ( V_4 , V_2 . V_5 + V_1 ) ;
}
static inline T_1 F_7 ( T_1 V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_8 ( T_1 V_4 , T_1 V_1 )
{
F_4 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static void F_9 ( enum V_6 V_7 )
{
T_1 V_8 = F_7 ( V_9 ) & ~ V_10 ;
if ( V_7 == V_11 || V_7 == V_12 )
V_8 |= 0x08 ;
V_8 |= ( V_7 << V_13 ) ;
F_8 ( V_8 , V_9 ) ;
}
static void F_10 ( enum V_6 V_7 )
{
F_3 ( V_7 << V_14 , V_15 ) ;
}
int F_11 ( void )
{
if ( ! V_2 . V_16 . V_17 )
return 2 ;
return V_2 . V_16 . V_17 () ;
}
int F_12 ( enum V_6 V_7 )
{
if ( ! V_2 . V_16 . V_18 )
return - V_19 ;
V_2 . V_16 . V_18 ( V_7 ) ;
return 0 ;
}
static int F_13 ( enum V_20 V_21 )
{
T_1 V_22 = 1 , V_4 ;
if ( V_21 < V_23 ||
V_21 > V_24 )
return - V_19 ;
V_22 = ~ ( V_22 << V_21 ) ;
V_4 = F_1 ( V_25 ) & V_22 ;
F_3 ( V_4 , V_25 ) ;
return 0 ;
}
void F_14 ( struct V_26 V_27 )
{
if ( ! V_2 . V_16 . V_28 )
return;
V_2 . V_16 . V_28 ( V_27 ) ;
}
int F_15 ( enum V_20 V_21 )
{
if ( ! V_2 . V_16 . V_29 )
return - V_19 ;
return V_2 . V_16 . V_29 ( V_21 ) ;
}
static int F_16 ( enum V_30 V_31 , int V_32 )
{
unsigned long V_33 ;
T_1 V_34 , V_22 = 0x1 , V_35 = 0 ;
switch ( V_31 ) {
case V_36 :
break;
case V_37 :
V_35 = 2 ;
break;
case V_38 :
V_35 = 3 ;
break;
case V_39 :
V_35 = 4 ;
break;
case V_40 :
V_35 = 5 ;
break;
case V_41 :
V_35 = 6 ;
break;
default:
F_17 ( V_42 L_1
L_2 , V_31 ) ;
return - V_19 ;
}
F_18 ( & V_2 . V_43 , V_33 ) ;
V_34 = F_5 ( V_44 ) ;
if ( ! V_32 )
V_34 &= ~ ( V_22 << V_35 ) ;
else
V_34 |= ( V_22 << V_35 ) ;
F_6 ( V_34 , V_44 ) ;
F_19 ( & V_2 . V_43 , V_33 ) ;
return 0 ;
}
static int F_20 ( enum V_30 V_31 , int V_32 )
{
unsigned long V_33 ;
T_1 V_34 , V_22 = 0x1 , V_35 = 0 , V_1 = V_45 ;
T_1 (* F_21)( T_1 V_1 ) = F_7 ;
void (* F_22)( T_1 V_4 , T_1 V_1 ) = F_8 ;
switch ( V_31 ) {
case V_46 :
break;
case V_41 :
V_35 = 1 ;
break;
case V_39 :
V_35 = 2 ;
break;
case V_47 :
V_35 = 3 ;
break;
case V_40 :
V_35 = 4 ;
break;
case V_48 :
V_35 = 5 ;
break;
case V_49 :
V_35 = 6 ;
break;
case V_50 :
V_35 = 7 ;
break;
case V_36 :
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
case V_37 :
V_35 = 2 ;
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
case V_52 :
V_35 = 3 ;
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
case V_53 :
V_35 = 4 ;
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
case V_54 :
V_35 = 6 ;
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
case V_55 :
V_35 = 7 ;
F_21 = F_5 ;
F_22 = F_6 ;
V_1 = V_51 ;
break;
default:
F_17 ( V_42 L_3 ,
V_31 ) ;
return - 1 ;
}
F_18 ( & V_2 . V_43 , V_33 ) ;
V_34 = F_21 ( V_1 ) ;
if ( ! V_32 ) {
V_22 = ~ V_22 ;
V_34 &= ( V_22 << V_35 ) ;
} else
V_34 |= ( V_22 << V_35 ) ;
F_22 ( V_34 , V_1 ) ;
F_19 ( & V_2 . V_43 , V_33 ) ;
return 0 ;
}
int F_23 ( enum V_30 V_31 , int V_32 )
{
if ( ! V_2 . V_16 . V_56 )
return - V_19 ;
return V_2 . V_16 . V_56 ( V_31 , V_32 ) ;
}
void F_24 ( struct V_26 V_27 )
{
int V_4 = 0 ;
V_4 = F_7 ( V_9 ) ;
V_4 |= ( V_27 . V_57 << V_58 ) ;
V_4 |= ( V_27 . V_59 << V_60 ) ;
F_8 ( V_4 , V_9 ) ;
}
void F_25 ( struct V_61 V_62 )
{
if ( ! V_2 . V_16 . V_63 )
return;
V_2 . V_16 . V_63 ( V_62 ) ;
}
void F_26 ( struct V_61 V_62 )
{
int V_64 = ( ( V_62 . V_65 >> 1 ) - 1 ) << 16 ;
V_64 |= ( V_62 . V_66 - 1 ) ;
F_8 ( V_64 , V_67 ) ;
}
static int F_27 ( struct V_68 * V_69 )
{
struct V_70 * V_71 , * V_72 ;
char * V_73 ;
int V_74 ;
if ( ! V_69 -> V_75 . V_76 ) {
F_28 ( & V_69 -> V_75 , L_4 ) ;
return - V_77 ;
}
V_73 = V_69 -> V_75 . V_76 ;
if ( ! strcmp ( V_73 , L_5 ) )
V_2 . V_78 = V_79 ;
else if ( ! strcmp ( V_73 , L_6 ) )
V_2 . V_78 = V_80 ;
else if ( ! strcmp ( V_73 , L_7 ) )
V_2 . V_78 = V_81 ;
else {
F_28 ( & V_69 -> V_75 , L_8
L_9 ) ;
return - V_82 ;
}
F_29 ( & V_69 -> V_75 , L_10 , V_73 ) ;
V_71 = F_30 ( V_69 , V_83 , 0 ) ;
if ( ! V_71 )
return - V_77 ;
V_71 = F_31 ( V_71 -> V_84 , F_32 ( V_71 ) , V_71 -> V_85 ) ;
if ( ! V_71 )
return - V_86 ;
V_2 . V_3 = F_33 ( V_71 -> V_84 , F_32 ( V_71 ) ) ;
if ( ! V_2 . V_3 ) {
V_74 = - V_86 ;
goto V_87;
}
if ( V_2 . V_78 == V_79 || V_2 . V_78 == V_80 ) {
V_72 = F_30 ( V_69 , V_83 , 1 ) ;
if ( ! V_72 ) {
V_74 = - V_77 ;
goto V_88;
}
V_72 = F_31 ( V_72 -> V_84 , F_32 ( V_72 ) , V_72 -> V_85 ) ;
if ( ! V_72 ) {
V_74 = - V_86 ;
goto V_88;
}
V_2 . V_5 = F_33 ( V_72 -> V_84 ,
F_32 ( V_72 ) ) ;
if ( ! V_2 . V_5 ) {
V_74 = - V_86 ;
goto V_89;
}
}
if ( V_2 . V_78 == V_79 ) {
V_2 . V_16 . V_56 = F_16 ;
V_2 . V_16 . V_18 = F_10 ;
F_3 ( V_90 , V_91 ) ;
F_3 ( V_92 , V_93 ) ;
} else if ( V_2 . V_78 == V_80 ) {
V_2 . V_16 . V_56 = F_20 ;
V_2 . V_16 . V_18 = F_9 ;
F_8 ( ( F_7 ( V_45 ) |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 ) , V_45 ) ;
F_8 ( ( F_7 ( V_101 ) |
V_102 ) , V_101 ) ;
F_8 ( V_103 , V_104 ) ;
F_8 ( V_105 , V_106 ) ;
F_8 ( V_107 , V_108 ) ;
} else
V_2 . V_16 . V_29 = F_13 ;
F_34 ( & V_2 . V_43 ) ;
F_29 ( & V_69 -> V_75 , L_11 , V_73 ) ;
return 0 ;
V_89:
F_35 ( V_72 -> V_84 , F_32 ( V_72 ) ) ;
V_88:
F_36 ( V_2 . V_3 ) ;
V_87:
F_35 ( V_71 -> V_84 , F_32 ( V_71 ) ) ;
return V_74 ;
}
static int F_37 ( struct V_68 * V_69 )
{
struct V_70 * V_109 ;
F_36 ( V_2 . V_3 ) ;
V_109 = F_30 ( V_69 , V_83 , 0 ) ;
F_35 ( V_109 -> V_84 , F_32 ( V_109 ) ) ;
if ( V_2 . V_78 == V_79 || V_2 . V_78 == V_80 ) {
F_36 ( V_2 . V_5 ) ;
V_109 = F_30 ( V_69 , V_83 , 1 ) ;
F_35 ( V_109 -> V_84 , F_32 ( V_109 ) ) ;
}
return 0 ;
}
static void F_38 ( void )
{
F_36 ( V_2 . V_110 ) ;
F_35 ( V_111 , 4 ) ;
F_39 ( & V_112 ) ;
}
static int T_2 F_40 ( void )
{
if ( ! F_31 ( V_111 , 4 , L_12 ) )
return - V_86 ;
V_2 . V_110 = F_33 ( V_111 , 4 ) ;
F_41 ( V_113 |
V_114 , V_2 . V_110 ) ;
return F_42 ( & V_112 ) ;
}
