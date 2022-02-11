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
int F_11 ( enum V_6 V_7 )
{
if ( ! V_2 . V_16 . V_17 )
return - V_18 ;
V_2 . V_16 . V_17 ( V_7 ) ;
return 0 ;
}
static int F_12 ( enum V_19 V_20 )
{
T_1 V_21 = 1 , V_4 ;
if ( V_20 < V_22 ||
V_20 > V_23 )
return - V_18 ;
V_21 = ~ ( V_21 << V_20 ) ;
V_4 = F_1 ( V_24 ) & V_21 ;
F_3 ( V_4 , V_24 ) ;
return 0 ;
}
int F_13 ( enum V_19 V_20 )
{
if ( ! V_2 . V_16 . V_25 )
return - V_18 ;
return V_2 . V_16 . V_25 ( V_20 ) ;
}
static int F_14 ( enum V_26 V_27 , int V_28 )
{
unsigned long V_29 ;
T_1 V_30 , V_21 = 0x1 , V_31 = 0 ;
switch ( V_27 ) {
case V_32 :
break;
case V_33 :
V_31 = 2 ;
break;
case V_34 :
V_31 = 3 ;
break;
case V_35 :
V_31 = 4 ;
break;
case V_36 :
V_31 = 5 ;
break;
case V_37 :
V_31 = 6 ;
break;
default:
F_15 ( V_38 L_1
L_2 , V_27 ) ;
return - V_18 ;
}
F_16 ( & V_2 . V_39 , V_29 ) ;
V_30 = F_5 ( V_40 ) ;
if ( ! V_28 )
V_30 &= ~ ( V_21 << V_31 ) ;
else
V_30 |= ( V_21 << V_31 ) ;
F_6 ( V_30 , V_40 ) ;
F_17 ( & V_2 . V_39 , V_29 ) ;
return 0 ;
}
static int F_18 ( enum V_26 V_27 , int V_28 )
{
unsigned long V_29 ;
T_1 V_30 , V_21 = 0x1 , V_31 = 0 , V_1 = V_41 ;
T_1 (* F_19)( T_1 V_1 ) = F_7 ;
void (* F_20)( T_1 V_4 , T_1 V_1 ) = F_8 ;
switch ( V_27 ) {
case V_42 :
break;
case V_37 :
V_31 = 1 ;
break;
case V_35 :
V_31 = 2 ;
break;
case V_43 :
V_31 = 3 ;
break;
case V_36 :
V_31 = 4 ;
break;
case V_44 :
V_31 = 5 ;
break;
case V_45 :
V_31 = 6 ;
break;
case V_46 :
V_31 = 7 ;
break;
case V_32 :
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
case V_33 :
V_31 = 2 ;
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
case V_48 :
V_31 = 3 ;
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
case V_49 :
V_31 = 4 ;
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
case V_50 :
V_31 = 6 ;
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
case V_51 :
V_31 = 7 ;
F_19 = F_5 ;
F_20 = F_6 ;
V_1 = V_47 ;
break;
default:
F_15 ( V_38 L_3 ,
V_27 ) ;
return - 1 ;
}
F_16 ( & V_2 . V_39 , V_29 ) ;
V_30 = F_19 ( V_1 ) ;
if ( ! V_28 ) {
V_21 = ~ V_21 ;
V_30 &= ( V_21 << V_31 ) ;
} else
V_30 |= ( V_21 << V_31 ) ;
F_20 ( V_30 , V_1 ) ;
F_17 ( & V_2 . V_39 , V_29 ) ;
return 0 ;
}
int F_21 ( enum V_26 V_27 , int V_28 )
{
if ( ! V_2 . V_16 . V_52 )
return - V_18 ;
return V_2 . V_16 . V_52 ( V_27 , V_28 ) ;
}
void F_22 ( struct V_53 V_54 )
{
int V_4 = 0 ;
V_4 = F_7 ( V_9 ) ;
V_4 |= ( V_54 . V_55 << V_56 ) ;
V_4 |= ( V_54 . V_57 << V_58 ) ;
F_8 ( V_4 , V_9 ) ;
}
void F_23 ( struct V_59 V_60 )
{
int V_61 = ( ( V_60 . V_62 >> 1 ) - 1 ) << 16 ;
V_61 |= ( V_60 . V_63 - 1 ) ;
F_8 ( V_61 , V_64 ) ;
}
static int F_24 ( struct V_65 * V_66 )
{
struct V_67 * V_68 , * V_69 ;
char * V_70 ;
int V_71 ;
if ( ! V_66 -> V_72 . V_73 ) {
F_25 ( & V_66 -> V_72 , L_4 ) ;
return - V_74 ;
}
V_70 = V_66 -> V_72 . V_73 ;
if ( ! strcmp ( V_70 , L_5 ) )
V_2 . V_75 = V_76 ;
else if ( ! strcmp ( V_70 , L_6 ) )
V_2 . V_75 = V_77 ;
else if ( ! strcmp ( V_70 , L_7 ) )
V_2 . V_75 = V_78 ;
else {
F_25 ( & V_66 -> V_72 , L_8
L_9 ) ;
return - V_79 ;
}
F_26 ( & V_66 -> V_72 , L_10 , V_70 ) ;
V_68 = F_27 ( V_66 , V_80 , 0 ) ;
if ( ! V_68 )
return - V_74 ;
V_68 = F_28 ( V_68 -> V_81 , F_29 ( V_68 ) , V_68 -> V_82 ) ;
if ( ! V_68 )
return - V_83 ;
V_2 . V_3 = F_30 ( V_68 -> V_81 , F_29 ( V_68 ) ) ;
if ( ! V_2 . V_3 ) {
V_71 = - V_83 ;
goto V_84;
}
if ( V_2 . V_75 == V_76 || V_2 . V_75 == V_77 ) {
V_69 = F_27 ( V_66 , V_80 , 1 ) ;
if ( ! V_69 ) {
V_71 = - V_74 ;
goto V_85;
}
V_69 = F_28 ( V_69 -> V_81 , F_29 ( V_69 ) , V_69 -> V_82 ) ;
if ( ! V_69 ) {
V_71 = - V_83 ;
goto V_85;
}
V_2 . V_5 = F_30 ( V_69 -> V_81 ,
F_29 ( V_69 ) ) ;
if ( ! V_2 . V_5 ) {
V_71 = - V_83 ;
goto V_86;
}
}
if ( V_2 . V_75 == V_76 ) {
V_2 . V_16 . V_52 = F_14 ;
V_2 . V_16 . V_17 = F_10 ;
F_3 ( V_87 , V_88 ) ;
F_3 ( V_89 , V_90 ) ;
} else if ( V_2 . V_75 == V_77 ) {
V_2 . V_16 . V_52 = F_18 ;
V_2 . V_16 . V_17 = F_9 ;
F_8 ( V_91 , V_92 ) ;
F_8 ( V_93 , V_94 ) ;
F_8 ( V_95 , V_96 ) ;
} else
V_2 . V_16 . V_25 = F_12 ;
F_31 ( & V_2 . V_39 ) ;
F_26 ( & V_66 -> V_72 , L_11 , V_70 ) ;
return 0 ;
V_86:
F_32 ( V_69 -> V_81 , F_29 ( V_69 ) ) ;
V_85:
F_33 ( V_2 . V_3 ) ;
V_84:
F_32 ( V_68 -> V_81 , F_29 ( V_68 ) ) ;
return V_71 ;
}
static int F_34 ( struct V_65 * V_66 )
{
struct V_67 * V_97 ;
F_33 ( V_2 . V_3 ) ;
V_97 = F_27 ( V_66 , V_80 , 0 ) ;
F_32 ( V_97 -> V_81 , F_29 ( V_97 ) ) ;
if ( V_2 . V_75 == V_76 || V_2 . V_75 == V_77 ) {
F_33 ( V_2 . V_5 ) ;
V_97 = F_27 ( V_66 , V_80 , 1 ) ;
F_32 ( V_97 -> V_81 , F_29 ( V_97 ) ) ;
}
return 0 ;
}
static void F_35 ( void )
{
F_36 ( & V_98 ) ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_98 ) ;
}
