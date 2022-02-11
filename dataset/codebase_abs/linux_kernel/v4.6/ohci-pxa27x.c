static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
T_1 V_7 = F_2 ( V_2 -> V_5 + V_8 ) ;
switch ( V_3 ) {
case V_9 :
V_4 |= V_10 ;
break;
case V_11 :
V_4 &= ~ ( V_10 & V_12 ) ;
break;
case V_13 :
V_4 &= ~ ( V_10 ) ;
V_4 |= V_12 ;
V_7 |= ( 0x7 << 17 ) ;
break;
default:
F_3 ( V_14
L_1 ,
V_3 ) ;
V_4 |= V_10 ;
}
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_4 ( V_7 , V_2 -> V_5 + V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_15 , bool V_16 )
{
struct V_17 * V_18 = V_2 -> V_18 [ V_15 ] ;
int V_19 = 0 ;
if ( F_6 ( V_18 ) )
return 0 ;
if ( V_16 && ! V_2 -> V_20 [ V_15 ] )
V_19 = F_7 ( V_18 ) ;
else if ( ! V_16 && V_2 -> V_20 [ V_15 ] )
V_19 = F_8 ( V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 -> V_20 [ V_15 ] = V_16 ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , T_2 V_23 , T_2 V_24 ,
T_2 V_25 , char * V_26 , T_2 V_27 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_19 ;
switch ( V_23 ) {
case V_28 :
case V_29 :
if ( ! V_25 || V_25 > 3 )
return - V_30 ;
if ( V_24 != V_31 )
break;
V_19 = F_5 ( V_2 , V_25 - 1 ,
V_23 == V_28 ) ;
if ( V_19 )
return V_19 ;
break;
}
return F_11 ( V_22 , V_23 , V_24 , V_25 , V_26 , V_27 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
T_1 V_34 = F_2 ( V_2 -> V_5 + V_35 ) ;
T_1 V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_33 -> V_36 & V_37 )
V_34 &= ~ V_38 ;
if ( V_33 -> V_36 & V_39 )
V_34 &= ~ V_40 ;
if ( V_33 -> V_36 & V_41 )
V_34 &= ~ V_42 ;
if ( V_33 -> V_36 & V_43 )
V_34 |= V_44 ;
if ( V_33 -> V_36 & V_45 )
V_34 |= V_46 ;
if ( V_33 -> V_36 & V_47 )
V_4 |= V_48 ;
else
V_4 &= ~ V_48 ;
if ( V_33 -> V_36 & V_49 )
V_4 |= V_50 ;
else
V_4 &= ~ V_50 ;
if ( V_33 -> V_51 ) {
V_4 &= ~ F_13 ( 0xff ) ;
V_4 |= F_13 ( V_33 -> V_51 / 2 ) ;
}
F_4 ( V_34 , V_2 -> V_5 + V_35 ) ;
F_4 ( V_4 , V_2 -> V_5 + V_6 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
T_1 V_34 = F_2 ( V_2 -> V_5 + V_35 ) ;
F_4 ( V_34 | V_52 , V_2 -> V_5 + V_35 ) ;
F_15 ( 11 ) ;
F_4 ( V_34 & ~ V_52 , V_2 -> V_5 + V_35 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
int V_55 = 0 ;
struct V_32 * V_33 ;
T_1 V_34 ;
struct V_21 * V_22 = F_17 ( V_54 ) ;
V_33 = F_18 ( V_54 ) ;
F_19 ( V_2 -> V_56 ) ;
F_14 ( V_2 ) ;
V_34 = F_2 ( V_2 -> V_5 + V_35 ) | V_57 ;
F_4 ( V_34 , V_2 -> V_5 + V_35 ) ;
while ( F_2 ( V_2 -> V_5 + V_35 ) & V_57 )
F_20 () ;
F_12 ( V_2 , V_33 ) ;
if ( V_33 -> V_58 )
V_55 = V_33 -> V_58 ( V_54 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_21 () )
F_22 ( & V_22 -> V_59 ) ;
V_34 = F_2 ( V_2 -> V_5 + V_35 ) & ~ V_60 ;
F_4 ( V_34 , V_2 -> V_5 + V_35 ) ;
F_4 ( V_61 | V_62 , V_2 -> V_5 + V_63 ) ;
F_23 () ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_32 * V_33 ;
struct V_21 * V_22 = F_17 ( V_54 ) ;
T_1 V_64 ;
V_33 = F_18 ( V_54 ) ;
if ( F_21 () )
F_25 ( & V_22 -> V_59 ) ;
if ( V_33 -> exit )
V_33 -> exit ( V_54 ) ;
F_14 ( V_2 ) ;
V_64 = F_2 ( V_2 -> V_5 + V_65 ) | 0x01 ;
F_4 ( V_64 , V_2 -> V_5 + V_65 ) ;
F_15 ( 10 ) ;
F_26 ( V_2 -> V_56 ) ;
}
static int F_27 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_54 . V_70 ;
struct V_32 * V_71 ;
T_3 V_72 ;
int V_19 ;
if ( ! V_69 )
return 0 ;
V_19 = F_28 ( & V_67 -> V_54 , F_29 ( 32 ) ) ;
if ( V_19 )
return V_19 ;
V_71 = F_30 ( & V_67 -> V_54 , sizeof( * V_71 ) , V_73 ) ;
if ( ! V_71 )
return - V_74 ;
if ( F_31 ( V_69 , L_2 ) )
V_71 -> V_36 |= V_37 ;
if ( F_31 ( V_69 , L_3 ) )
V_71 -> V_36 |= V_39 ;
if ( F_31 ( V_69 , L_4 ) )
V_71 -> V_36 |= V_41 ;
if ( F_31 ( V_69 , L_5 ) )
V_71 -> V_36 |= V_45 ;
if ( F_31 ( V_69 , L_6 ) )
V_71 -> V_36 |= V_43 ;
if ( F_31 ( V_69 , L_7 ) )
V_71 -> V_36 |= V_47 ;
if ( F_31 ( V_69 , L_8 ) )
V_71 -> V_36 |= V_49 ;
if ( ! F_32 ( V_69 , L_9 , & V_72 ) )
V_71 -> V_51 = V_72 ;
if ( ! F_32 ( V_69 , L_10 , & V_72 ) )
V_71 -> V_75 = V_72 ;
if ( ! F_32 ( V_69 , L_11 , & V_72 ) )
V_71 -> V_76 = V_72 ;
V_67 -> V_54 . V_77 = V_71 ;
return 0 ;
}
static int F_27 ( struct V_66 * V_67 )
{
return 0 ;
}
int F_33 ( const struct V_78 * V_79 , struct V_66 * V_67 )
{
int V_55 , V_80 ;
struct V_21 * V_22 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_56 * V_85 ;
unsigned int V_86 ;
V_55 = F_27 ( V_67 ) ;
if ( V_55 )
return V_55 ;
V_33 = F_18 ( & V_67 -> V_54 ) ;
if ( ! V_33 )
return - V_87 ;
V_80 = F_34 ( V_67 , 0 ) ;
if ( V_80 < 0 ) {
F_35 ( L_12 ) ;
return V_80 ;
}
V_85 = F_36 ( & V_67 -> V_54 , NULL ) ;
if ( F_37 ( V_85 ) )
return F_38 ( V_85 ) ;
V_22 = F_39 ( V_79 , & V_67 -> V_54 , L_13 ) ;
if ( ! V_22 )
return - V_74 ;
V_84 = F_40 ( V_67 , V_88 , 0 ) ;
V_22 -> V_89 = F_41 ( & V_67 -> V_54 , V_84 ) ;
if ( F_37 ( V_22 -> V_89 ) ) {
V_55 = F_38 ( V_22 -> V_89 ) ;
goto V_90;
}
V_22 -> V_91 = V_84 -> V_92 ;
V_22 -> V_93 = F_42 ( V_84 ) ;
V_2 = F_10 ( V_22 ) ;
V_2 -> V_56 = V_85 ;
V_2 -> V_5 = ( void V_94 * ) V_22 -> V_89 ;
for ( V_86 = 0 ; V_86 < 3 ; ++ V_86 ) {
char V_95 [ 6 ] ;
if ( ! ( V_33 -> V_36 & ( V_37 << V_86 ) ) )
continue;
sprintf ( V_95 , L_14 , V_86 + 1 ) ;
V_2 -> V_18 [ V_86 ] = F_43 ( & V_67 -> V_54 , V_95 ) ;
}
V_55 = F_16 ( V_2 , & V_67 -> V_54 ) ;
if ( V_55 < 0 ) {
F_44 ( L_15 ) ;
goto V_90;
}
F_1 ( V_2 , V_33 -> V_75 ) ;
if ( V_33 -> V_76 )
V_22 -> V_76 = V_33 -> V_76 ;
V_82 = F_45 ( V_22 ) ;
V_82 -> V_96 = 3 ;
V_55 = F_46 ( V_22 , V_80 , 0 ) ;
if ( V_55 == 0 ) {
F_47 ( V_22 -> V_59 . V_97 ) ;
return V_55 ;
}
F_24 ( V_2 , & V_67 -> V_54 ) ;
V_90:
F_48 ( V_22 ) ;
return V_55 ;
}
void F_49 ( struct V_21 * V_22 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
unsigned int V_86 ;
F_50 ( V_22 ) ;
F_24 ( V_2 , & V_67 -> V_54 ) ;
for ( V_86 = 0 ; V_86 < 3 ; ++ V_86 )
F_5 ( V_2 , V_86 , false ) ;
F_48 ( V_22 ) ;
}
static int F_51 ( struct V_66 * V_67 )
{
F_44 ( L_16 ) ;
if ( F_52 () )
return - V_87 ;
return F_33 ( & V_98 , V_67 ) ;
}
static int F_53 ( struct V_66 * V_67 )
{
struct V_21 * V_22 = F_54 ( V_67 ) ;
F_49 ( V_22 , V_67 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 )
{
struct V_21 * V_22 = F_17 ( V_54 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
struct V_81 * V_82 = F_45 ( V_22 ) ;
bool V_99 = F_56 ( V_54 ) ;
int V_19 ;
if ( F_57 ( V_100 , V_82 -> V_101 ) )
F_58 ( 5 ) ;
V_82 -> V_101 = V_100 ;
V_19 = F_59 ( V_22 , V_99 ) ;
if ( V_19 )
return V_19 ;
F_24 ( V_2 , V_54 ) ;
return V_19 ;
}
static int F_60 ( struct V_53 * V_54 )
{
struct V_21 * V_22 = F_17 ( V_54 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
struct V_32 * V_33 = F_18 ( V_54 ) ;
struct V_81 * V_82 = F_45 ( V_22 ) ;
int V_102 ;
if ( F_57 ( V_100 , V_82 -> V_101 ) )
F_58 ( 5 ) ;
V_82 -> V_101 = V_100 ;
V_102 = F_16 ( V_2 , V_54 ) ;
if ( V_102 < 0 )
return V_102 ;
F_1 ( V_2 , V_33 -> V_75 ) ;
F_61 ( V_22 , false ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
if ( F_52 () )
return - V_87 ;
F_63 ( L_17 V_103 L_18 , V_104 ) ;
F_64 ( & V_98 , & V_105 ) ;
V_98 . V_106 = F_9 ;
return F_65 ( & V_107 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_107 ) ;
}
