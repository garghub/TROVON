static int F_1 ( void )
{
struct V_1 * V_2 = V_3 -> V_4 ;
unsigned int V_5 , V_6 , V_7 , V_8 , V_9 ;
int V_10 = 0 ;
struct V_11 * V_11 ;
F_2 () ;
for ( V_10 = 0 ; V_2 [ V_10 ] . V_12 != V_13 ; V_10 ++ ) {
V_11 = F_3 ( V_3 -> V_14 ,
V_2 [ V_10 ] . V_12 * 1000 , true ) ;
if ( F_4 ( V_11 ) ) {
F_5 () ;
F_6 ( V_3 -> V_14 ,
L_1 ,
V_2 [ V_10 ] . V_12 ) ;
return F_7 ( V_11 ) ;
}
V_8 = V_2 [ V_10 ] . V_12 / 1000 ;
V_6 = ( ( V_8 / V_15 ) & V_16 )
<< V_17 ;
V_6 |= ( ( V_8 / V_18 ) & V_19 )
<< V_20 ;
V_6 |= ( ( V_8 / V_21 ) & V_22 )
<< V_23 ;
V_9 = F_8 ( V_11 ) ;
V_9 = ( V_24 - V_9 ) / V_25 ;
if ( V_9 < V_26 ) {
V_7 = ( V_27 << V_28 ) |
( V_29 << V_30 ) ;
} else if ( V_9 > V_31 ) {
V_7 = ( V_32 << V_28 ) |
( V_33 << V_30 ) ;
} else {
V_7 = ( V_34 << V_28 ) |
( V_35 << V_30 ) ;
}
V_5 = ( V_6 | V_7 | ( V_9 << V_36 )
| ( ( V_8 / V_37 ) << V_38 ) ) ;
F_9 ( V_5 , V_3 -> V_39 + V_40 + 4 * V_10 ) ;
}
F_5 () ;
return 0 ;
}
static void F_10 ( void )
{
unsigned int V_5 , V_10 , V_41 ;
struct V_1 * V_4 = V_3 -> V_4 ;
F_9 ( 0 , V_3 -> V_39 + V_42 ) ;
V_5 = F_11 ( V_3 -> V_39 + V_43 ) ;
V_5 |= ( 1 << V_44 ) ;
F_9 ( V_5 , V_3 -> V_39 + V_43 ) ;
V_5 = F_11 ( V_3 -> V_39 + V_45 ) ;
V_5 |= ( 1 << V_46 ) ;
F_9 ( V_5 , V_3 -> V_39 + V_45 ) ;
for ( V_10 = 0 ; V_4 [ V_10 ] . V_12 != V_13 ; V_10 ++ )
if ( V_4 [ V_10 ] . V_12 == V_3 -> V_47 )
break;
if ( V_4 [ V_10 ] . V_12 == V_13 ) {
F_12 ( V_3 -> V_14 , L_2 ) ;
V_10 = 0 ;
V_3 -> V_47 = V_4 [ V_10 ] . V_12 ;
}
F_13 ( V_3 -> V_14 , L_3 ,
V_3 -> V_47 ) ;
for ( V_41 = 0 ; V_41 < V_48 ; V_41 ++ ) {
V_5 = F_11 ( V_3 -> V_39 + V_49 + V_41 * 4 ) ;
V_5 &= ~ ( V_50 << V_51 ) ;
V_5 |= ( V_10 << V_51 ) ;
F_9 ( V_5 , V_3 -> V_39 + V_49 + V_41 * 4 ) ;
}
F_9 ( 1 << V_52 ,
V_3 -> V_39 + V_42 ) ;
}
static int F_14 ( struct V_53 * V_54 )
{
return F_15 ( V_54 ,
V_3 -> V_4 ) ;
}
static unsigned int F_16 ( unsigned int V_41 )
{
return V_3 -> V_47 ;
}
static int F_17 ( struct V_53 * V_54 ,
unsigned int V_55 ,
unsigned int V_56 )
{
unsigned int V_57 , V_5 ;
int V_58 = 0 , V_10 ;
struct V_1 * V_4 = V_3 -> V_4 ;
F_18 ( & V_59 ) ;
V_58 = F_19 ( V_54 , V_4 ,
V_55 , V_56 , & V_57 ) ;
if ( V_58 )
goto V_60;
V_61 . V_62 = V_3 -> V_47 ;
V_61 . V_63 = V_4 [ V_57 ] . V_12 ;
F_20 ( V_54 , & V_61 , V_64 ) ;
F_21 (i, policy->cpus) {
V_5 = F_11 ( V_3 -> V_39 + V_49 + V_10 * 4 ) ;
V_5 &= ~ ( V_50 << V_51 ) ;
V_5 |= ( V_57 << V_51 ) ;
F_9 ( V_5 , V_3 -> V_39 + V_49 + V_10 * 4 ) ;
}
V_60:
F_22 ( & V_59 ) ;
return V_58 ;
}
static void F_23 ( struct V_65 * V_66 )
{
unsigned int V_67 , V_57 ;
struct V_53 * V_54 = F_24 ( 0 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( F_25 ( V_3 -> V_68 == false ) )
goto V_69;
F_18 ( & V_59 ) ;
V_61 . V_62 = V_3 -> V_47 ;
V_67 = F_11 ( V_3 -> V_39 + V_70 ) ;
if ( V_67 >> V_71 & 0x1 )
V_57 = ( V_67 >> V_72 ) & V_50 ;
else
V_57 = ( V_67 >> V_51 ) & V_50 ;
if ( F_26 ( V_57 < V_3 -> V_73 ) ) {
V_61 . V_63 = V_4 [ V_57 ] . V_12 ;
V_3 -> V_47 = V_61 . V_63 ;
} else {
F_12 ( V_3 -> V_14 , L_4 ) ;
V_61 . V_63 = V_3 -> V_47 ;
}
F_20 ( V_54 , & V_61 , V_74 ) ;
F_27 ( V_54 ) ;
F_22 ( & V_59 ) ;
V_69:
F_28 ( V_3 -> V_75 ) ;
}
static T_1 F_29 ( int V_75 , void * V_76 )
{
unsigned int V_5 ;
V_5 = F_11 ( V_3 -> V_39 + V_77 ) ;
if ( V_5 >> V_78 & 0x1 ) {
F_9 ( V_5 , V_3 -> V_39 + V_77 ) ;
F_30 ( V_75 ) ;
F_31 ( & V_3 -> V_79 ) ;
}
return V_80 ;
}
static void F_32 ( void )
{
struct V_1 * V_2 = V_3 -> V_4 ;
int V_10 = 0 , V_57 ;
unsigned int V_81 ;
for ( V_10 = 0 ; V_10 < V_3 -> V_73 / 2 ; V_10 ++ ) {
V_57 = V_3 -> V_73 - V_10 - 1 ;
V_81 = V_2 [ V_10 ] . V_12 ;
V_2 [ V_10 ] . V_12 = V_2 [ V_57 ] . V_12 ;
V_2 [ V_57 ] . V_12 = V_81 ;
}
}
static int F_33 ( struct V_53 * V_54 )
{
int V_58 ;
V_58 = F_34 ( V_54 , V_3 -> V_4 ) ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 , L_5 , V_58 ) ;
return V_58 ;
}
V_54 -> V_82 = V_3 -> V_47 ;
V_54 -> V_83 . V_84 = V_3 -> V_85 ;
F_35 ( V_54 -> V_86 ) ;
F_36 ( V_3 -> V_4 , V_54 -> V_41 ) ;
return 0 ;
}
static int F_37 ( struct V_87 * V_88 )
{
int V_58 = - V_89 ;
struct V_90 * V_91 ;
struct V_92 V_93 ;
V_91 = V_88 -> V_14 . V_94 ;
if ( ! V_91 )
return - V_95 ;
V_3 = F_38 ( & V_88 -> V_14 , sizeof( * V_3 ) , V_96 ) ;
if ( ! V_3 ) {
V_58 = - V_97 ;
goto V_98;
}
V_3 -> V_14 = & V_88 -> V_14 ;
V_58 = F_39 ( V_91 , 0 , & V_93 ) ;
if ( V_58 )
goto V_98;
V_3 -> V_39 = F_40 ( V_3 -> V_14 , & V_93 ) ;
if ( F_4 ( V_3 -> V_39 ) ) {
V_58 = F_7 ( V_3 -> V_39 ) ;
goto V_98;
}
V_3 -> V_75 = F_41 ( V_91 , 0 ) ;
if ( ! V_3 -> V_75 ) {
F_6 ( V_3 -> V_14 , L_6 ) ;
V_58 = - V_95 ;
goto V_98;
}
V_58 = F_42 ( V_3 -> V_14 ) ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 , L_7 , V_58 ) ;
goto V_98;
}
V_58 = F_43 ( V_3 -> V_14 , & V_3 -> V_4 ) ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 ,
L_8 , V_58 ) ;
goto V_98;
}
V_3 -> V_73 = F_44 ( V_3 -> V_14 ) ;
F_32 () ;
if ( F_45 ( V_91 , L_9 , & V_3 -> V_85 ) )
V_3 -> V_85 = V_99 ;
V_3 -> V_100 = F_46 ( V_3 -> V_14 , L_10 ) ;
if ( F_4 ( V_3 -> V_100 ) ) {
F_6 ( V_3 -> V_14 , L_11 ) ;
V_58 = F_7 ( V_3 -> V_100 ) ;
goto V_101;
}
V_3 -> V_47 = F_47 ( V_3 -> V_100 ) ;
if ( ! V_3 -> V_47 ) {
F_6 ( V_3 -> V_14 , L_12 ) ;
V_58 = - V_89 ;
goto V_101;
}
V_3 -> V_47 /= 1000 ;
F_48 ( & V_3 -> V_79 , F_23 ) ;
V_58 = F_49 ( V_3 -> V_14 , V_3 -> V_75 ,
F_29 , V_102 ,
V_103 , V_3 ) ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 , L_13 ) ;
goto V_101;
}
V_58 = F_1 () ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 , L_14 ) ;
goto V_101;
}
F_10 () ;
V_58 = F_50 ( & V_104 ) ;
if ( V_58 ) {
F_6 ( V_3 -> V_14 ,
L_15 , V_105 ) ;
goto V_101;
}
F_51 ( V_91 ) ;
V_3 -> V_68 = true ;
return 0 ;
V_101:
F_52 ( V_3 -> V_14 , & V_3 -> V_4 ) ;
V_98:
F_51 ( V_91 ) ;
F_6 ( V_3 -> V_14 , L_16 , V_105 ) ;
return V_58 ;
}
static int F_53 ( struct V_87 * V_88 )
{
F_54 ( & V_104 ) ;
F_52 ( V_3 -> V_14 , & V_3 -> V_4 ) ;
return 0 ;
}
