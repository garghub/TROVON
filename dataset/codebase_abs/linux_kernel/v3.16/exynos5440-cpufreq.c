static int F_1 ( void )
{
struct V_1 * V_2 , * V_3 = V_4 -> V_5 ;
unsigned int V_6 , V_7 , V_8 , V_9 , V_10 ;
struct V_11 * V_12 ;
F_2 () ;
F_3 (pos, freq_tbl) {
V_12 = F_4 ( V_4 -> V_13 ,
V_2 -> V_14 * 1000 , true ) ;
if ( F_5 ( V_12 ) ) {
F_6 () ;
F_7 ( V_4 -> V_13 ,
L_1 ,
V_2 -> V_14 ) ;
return F_8 ( V_12 ) ;
}
V_9 = V_2 -> V_14 / 1000 ;
V_7 = ( ( V_9 / V_15 ) & V_16 )
<< V_17 ;
V_7 |= ( ( V_9 / V_18 ) & V_19 )
<< V_20 ;
V_7 |= ( ( V_9 / V_21 ) & V_22 )
<< V_23 ;
V_10 = F_9 ( V_12 ) ;
V_10 = ( V_24 - V_10 ) / V_25 ;
if ( V_10 < V_26 ) {
V_8 = ( V_27 << V_28 ) |
( V_29 << V_30 ) ;
} else if ( V_10 > V_31 ) {
V_8 = ( V_32 << V_28 ) |
( V_33 << V_30 ) ;
} else {
V_8 = ( V_34 << V_28 ) |
( V_35 << V_30 ) ;
}
V_6 = ( V_7 | V_8 | ( V_10 << V_36 )
| ( ( V_9 / V_37 ) << V_38 ) ) ;
F_10 ( V_6 , V_4 -> V_39 + V_40 + 4 *
( V_2 - V_3 ) ) ;
}
F_6 () ;
return 0 ;
}
static void F_11 ( unsigned int V_41 )
{
unsigned int V_6 , V_42 ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 ;
F_10 ( 0 , V_4 -> V_39 + V_43 ) ;
V_6 = F_12 ( V_4 -> V_39 + V_44 ) ;
V_6 |= ( 1 << V_45 ) ;
F_10 ( V_6 , V_4 -> V_39 + V_44 ) ;
V_6 = F_12 ( V_4 -> V_39 + V_46 ) ;
V_6 |= ( 1 << V_47 ) ;
F_10 ( V_6 , V_4 -> V_39 + V_46 ) ;
F_3 (pos, freq_table)
if ( V_2 -> V_14 == V_41 )
break;
if ( V_2 -> V_14 == V_48 ) {
F_13 ( V_4 -> V_13 , L_2 ) ;
V_2 = V_5 ;
V_41 = V_2 -> V_14 ;
}
F_14 ( V_4 -> V_13 , L_3 ,
V_41 ) ;
for ( V_42 = 0 ; V_42 < V_49 ; V_42 ++ ) {
V_6 = F_12 ( V_4 -> V_39 + V_50 + V_42 * 4 ) ;
V_6 &= ~ ( V_51 << V_52 ) ;
V_6 |= ( ( V_2 - V_5 ) << V_52 ) ;
F_10 ( V_6 , V_4 -> V_39 + V_50 + V_42 * 4 ) ;
}
F_10 ( 1 << V_53 ,
V_4 -> V_39 + V_43 ) ;
}
static int F_15 ( struct V_54 * V_55 , unsigned int V_56 )
{
unsigned int V_6 ;
int V_57 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_16 ( & V_58 ) ;
V_59 . V_60 = V_55 -> V_61 ;
V_59 . V_62 = V_5 [ V_56 ] . V_14 ;
F_17 ( V_55 , & V_59 ) ;
F_18 (i, policy->cpus) {
V_6 = F_12 ( V_4 -> V_39 + V_50 + V_57 * 4 ) ;
V_6 &= ~ ( V_51 << V_52 ) ;
V_6 |= ( V_56 << V_52 ) ;
F_10 ( V_6 , V_4 -> V_39 + V_50 + V_57 * 4 ) ;
}
F_19 ( & V_58 ) ;
return 0 ;
}
static void F_20 ( struct V_63 * V_64 )
{
unsigned int V_65 , V_56 ;
struct V_54 * V_55 = F_21 ( 0 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( F_22 ( V_4 -> V_66 == false ) )
goto V_67;
F_16 ( & V_58 ) ;
V_59 . V_60 = V_55 -> V_61 ;
V_65 = F_12 ( V_4 -> V_39 + V_68 ) ;
if ( V_65 >> V_69 & 0x1 )
V_56 = ( V_65 >> V_70 ) & V_51 ;
else
V_56 = ( V_65 >> V_52 ) & V_51 ;
if ( F_23 ( V_56 < V_4 -> V_71 ) ) {
V_59 . V_62 = V_5 [ V_56 ] . V_14 ;
} else {
F_13 ( V_4 -> V_13 , L_4 ) ;
V_59 . V_62 = V_59 . V_60 ;
}
F_24 ( V_55 , & V_59 , 0 ) ;
F_25 ( V_55 ) ;
F_19 ( & V_58 ) ;
V_67:
F_26 ( V_4 -> V_72 ) ;
}
static T_1 F_27 ( int V_72 , void * V_73 )
{
unsigned int V_6 ;
V_6 = F_12 ( V_4 -> V_39 + V_74 ) ;
if ( V_6 >> V_75 & 0x1 ) {
F_10 ( V_6 , V_4 -> V_39 + V_74 ) ;
F_28 ( V_72 ) ;
F_29 ( & V_4 -> V_76 ) ;
}
return V_77 ;
}
static void F_30 ( void )
{
struct V_1 * V_3 = V_4 -> V_5 ;
int V_57 = 0 , V_56 ;
unsigned int V_78 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_71 / 2 ; V_57 ++ ) {
V_56 = V_4 -> V_71 - V_57 - 1 ;
V_78 = V_3 [ V_57 ] . V_14 ;
V_3 [ V_57 ] . V_14 = V_3 [ V_56 ] . V_14 ;
V_3 [ V_56 ] . V_14 = V_78 ;
}
}
static int F_31 ( struct V_54 * V_55 )
{
V_55 -> V_79 = V_4 -> V_80 ;
return F_32 ( V_55 , V_4 -> V_5 ,
V_4 -> V_81 ) ;
}
static int F_33 ( struct V_82 * V_83 )
{
int V_84 = - V_85 ;
struct V_86 * V_87 ;
struct V_88 V_89 ;
unsigned int V_41 ;
V_87 = V_83 -> V_13 . V_90 ;
if ( ! V_87 )
return - V_91 ;
V_4 = F_34 ( & V_83 -> V_13 , sizeof( * V_4 ) , V_92 ) ;
if ( ! V_4 ) {
V_84 = - V_93 ;
goto V_94;
}
V_4 -> V_13 = & V_83 -> V_13 ;
V_84 = F_35 ( V_87 , 0 , & V_89 ) ;
if ( V_84 )
goto V_94;
V_4 -> V_39 = F_36 ( V_4 -> V_13 , & V_89 ) ;
if ( F_5 ( V_4 -> V_39 ) ) {
V_84 = F_8 ( V_4 -> V_39 ) ;
goto V_94;
}
V_4 -> V_72 = F_37 ( V_87 , 0 ) ;
if ( ! V_4 -> V_72 ) {
F_7 ( V_4 -> V_13 , L_5 ) ;
V_84 = - V_91 ;
goto V_94;
}
V_84 = F_38 ( V_4 -> V_13 ) ;
if ( V_84 ) {
F_7 ( V_4 -> V_13 , L_6 , V_84 ) ;
goto V_94;
}
V_84 = F_39 ( V_4 -> V_13 ,
& V_4 -> V_5 ) ;
if ( V_84 ) {
F_7 ( V_4 -> V_13 ,
L_7 , V_84 ) ;
goto V_94;
}
V_4 -> V_71 = F_40 ( V_4 -> V_13 ) ;
F_30 () ;
if ( F_41 ( V_87 , L_8 , & V_4 -> V_81 ) )
V_4 -> V_81 = V_95 ;
V_4 -> V_80 = F_42 ( V_4 -> V_13 , L_9 ) ;
if ( F_5 ( V_4 -> V_80 ) ) {
F_7 ( V_4 -> V_13 , L_10 ) ;
V_84 = F_8 ( V_4 -> V_80 ) ;
goto V_96;
}
V_41 = F_43 ( V_4 -> V_80 ) ;
if ( ! V_41 ) {
F_7 ( V_4 -> V_13 , L_11 ) ;
V_84 = - V_85 ;
goto V_96;
}
V_41 /= 1000 ;
F_44 ( & V_4 -> V_76 , F_20 ) ;
V_84 = F_45 ( V_4 -> V_13 , V_4 -> V_72 ,
F_27 , V_97 ,
V_98 , V_4 ) ;
if ( V_84 ) {
F_7 ( V_4 -> V_13 , L_12 ) ;
goto V_96;
}
V_84 = F_1 () ;
if ( V_84 ) {
F_7 ( V_4 -> V_13 , L_13 ) ;
goto V_96;
}
F_11 ( V_41 ) ;
V_84 = F_46 ( & V_99 ) ;
if ( V_84 ) {
F_7 ( V_4 -> V_13 ,
L_14 , V_100 ) ;
goto V_96;
}
F_47 ( V_87 ) ;
V_4 -> V_66 = true ;
return 0 ;
V_96:
F_48 ( V_4 -> V_13 , & V_4 -> V_5 ) ;
V_94:
F_47 ( V_87 ) ;
F_7 ( & V_83 -> V_13 , L_15 , V_100 ) ;
return V_84 ;
}
static int F_49 ( struct V_82 * V_83 )
{
F_50 ( & V_99 ) ;
F_48 ( V_4 -> V_13 , & V_4 -> V_5 ) ;
return 0 ;
}
