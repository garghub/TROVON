static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_2 -> V_5 > 0 ) {
V_4 = V_2 -> V_6 -> V_7 -> V_8 ;
F_2 ( V_2 -> V_9 [ V_4 ] , V_3 ? 0 : 1 ) ;
} else
F_3 ( V_2 -> V_10 + V_11 , V_3 ? 0 : 0x08 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_12 = V_2 -> V_13 -> V_12 ;
V_2 -> V_14 = V_2 -> V_13 -> V_14 ;
V_2 -> V_15 = V_2 -> V_13 -> V_15 ;
if ( V_2 -> V_16 )
F_1 ( V_2 , 1 ) ;
V_2 -> V_16 = V_2 -> V_13 -> V_16 ;
V_2 -> V_17 = F_5 () ;
if ( V_2 -> V_14 )
F_3 ( V_2 -> V_10 + V_18 , * V_2 -> V_14 ++ ) ;
else
F_3 ( V_2 -> V_10 + V_18 , 0 ) ;
}
static int
F_6 ( int V_19 , struct V_1 * V_2 , T_1 V_20 , T_1 V_21 )
{
struct V_22 * V_7 ;
int V_23 , V_24 ;
T_1 V_25 ;
if ( V_20 && ( V_19 != V_26 ) )
F_7 ( & V_2 -> V_27 -> V_28 , L_1 ,
V_20 ) ;
if ( F_8 ( & V_2 -> V_29 ) )
return V_30 ;
V_2 -> V_6 = F_9 ( & V_2 -> V_29 , struct V_31 , V_29 ) ;
F_10 ( & V_2 -> V_6 -> V_29 ) ;
V_25 = V_32 | V_33 | V_34 ;
V_7 = V_2 -> V_6 -> V_7 ;
if ( V_7 -> V_35 & V_36 )
V_25 |= V_37 ;
if ( V_7 -> V_35 & V_38 )
V_25 |= V_39 ;
if ( V_7 -> V_35 & V_40 )
V_25 |= V_41 ;
F_3 ( V_2 -> V_10 + V_42 , V_25 ) ;
V_24 = ( ( V_2 -> V_43 / V_2 -> V_6 -> V_7 -> V_44 ) + 1 ) >> 1 ;
V_23 = 0 ;
if ( V_24 < 1 )
V_24 = 1 ;
while ( ( ( V_24 - 1 ) & ~ 0x7 ) != 0 ) {
V_24 = ( V_24 + 1 ) >> 1 ;
V_23 ++ ;
}
V_24 -- ;
if ( V_23 > 7 ) {
V_23 = 7 ;
V_24 = 7 ;
}
F_3 ( V_2 -> V_10 + V_45 , V_24 << 4 | V_23 ) ;
V_2 -> V_16 = 1 ;
V_2 -> V_13 = F_11 ( V_2 -> V_6 -> V_46 . V_47 ,
struct V_48 , V_49 ) ;
F_4 ( V_2 ) ;
V_2 -> V_50 = V_51 ;
return V_52 ;
}
static int V_51 ( int V_19 , struct V_1 * V_2 ,
T_1 V_20 , T_1 V_21 )
{
if ( ! V_20 )
return V_2 -> V_53 ? V_30 : V_54 ;
if ( V_20 & V_55 ) {
V_2 -> V_56 ++ ;
V_2 -> V_57 += F_5 () - V_2 -> V_17 ;
V_2 -> V_17 = F_5 () ;
V_21 = 0 ;
if ( V_2 -> V_14 )
V_21 = * ( V_2 -> V_14 - 1 ) ;
F_3 ( V_2 -> V_10 + V_18 , V_21 ) ;
return V_52 ;
} else if ( V_20 & V_58 ) {
V_2 -> V_59 ++ ;
F_7 ( & V_2 -> V_27 -> V_28 , L_2 ) ;
F_1 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_20 = - V_60 ;
V_2 -> V_6 -> V_61 ( V_2 -> V_6 -> V_62 ) ;
V_2 -> V_50 = F_6 ;
return V_52 ;
}
V_2 -> V_63 ++ ;
if ( V_2 -> V_12 )
* V_2 -> V_12 ++ = V_21 ;
V_2 -> V_15 -- ;
if ( V_2 -> V_15 == 0 ) {
V_2 -> V_64 = F_5 () ;
V_2 -> V_64 += V_2 -> V_13 -> V_65 * V_66 ;
V_2 -> V_50 = V_67 ;
return V_52 ;
}
V_2 -> V_17 = F_5 () ;
if ( V_2 -> V_14 )
F_3 ( V_2 -> V_10 + V_18 , * V_2 -> V_14 ++ ) ;
else
F_3 ( V_2 -> V_10 + V_18 , 0 ) ;
return V_52 ;
}
static int
V_67 ( int V_19 , struct V_1 * V_2 , T_1 V_20 , T_1 V_21 )
{
if ( V_20 && V_19 )
F_7 ( & V_2 -> V_27 -> V_28 , L_1 ,
V_20 ) ;
if ( ( ( int ) F_5 () ) - V_2 -> V_64 < 0 )
return V_54 ;
V_2 -> V_6 -> V_68 += V_2 -> V_13 -> V_15 ;
if ( V_2 -> V_13 -> V_49 . V_47 == & V_2 -> V_6 -> V_46 ) {
V_2 -> V_69 ++ ;
F_1 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_20 = 0 ;
V_2 -> V_6 -> V_61 ( V_2 -> V_6 -> V_62 ) ;
V_2 -> V_50 = F_6 ;
return V_52 ;
}
if ( V_2 -> V_16 )
F_1 ( V_2 , 0 ) ;
V_2 -> V_13 = F_11 ( V_2 -> V_13 -> V_49 . V_47 ,
struct V_48 , V_49 ) ;
F_4 ( V_2 ) ;
V_2 -> V_50 = V_51 ;
return V_52 ;
}
static void F_12 ( int V_19 , struct V_1 * V_2 )
{
int V_70 = V_52 ;
T_1 V_20 , V_21 ;
while ( V_70 == V_52 ) {
V_20 = F_13 ( V_2 -> V_10 + V_71 ) ;
V_21 = F_13 ( V_2 -> V_10 + V_18 ) ;
V_70 = V_2 -> V_50 ( V_19 , V_2 , V_20 , V_21 ) ;
}
if ( V_70 == V_54 )
F_14 ( & V_2 -> V_72 ) ;
}
static T_2 F_15 ( int V_19 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
F_16 ( & V_2 -> V_74 ) ;
F_12 ( V_19 , V_2 ) ;
F_17 ( & V_2 -> V_74 ) ;
return V_75 ;
}
static void F_18 ( struct V_76 * V_72 )
{
struct V_1 * V_2 = F_11 ( V_72 , struct V_1 , V_72 ) ;
unsigned long V_77 ;
F_19 ( & V_2 -> V_74 , V_77 ) ;
F_12 ( 0 , V_2 ) ;
F_20 ( & V_2 -> V_74 , V_77 ) ;
}
static int F_21 ( struct V_22 * V_7 )
{
if ( V_7 -> V_78 % 8 )
return - V_79 ;
if ( V_7 -> V_35 & ~ ( V_38 | V_36 | V_40 ) )
return - V_79 ;
if ( V_7 -> V_8 >= V_7 -> V_27 -> V_80 )
return - V_79 ;
return 0 ;
}
static int F_22 ( struct V_22 * V_7 , struct V_31 * V_81 )
{
struct V_1 * V_2 = F_23 ( V_7 -> V_27 ) ;
unsigned long V_77 ;
V_81 -> V_68 = 0 ;
V_81 -> V_20 = - V_82 ;
F_19 ( & V_2 -> V_74 , V_77 ) ;
F_24 ( & V_81 -> V_29 , & V_2 -> V_29 ) ;
F_20 ( & V_2 -> V_74 , V_77 ) ;
F_14 ( & V_2 -> V_72 ) ;
return 0 ;
}
static int T_3 F_25 ( struct V_83 * V_84 )
{
struct V_85 * V_27 ;
struct V_1 * V_2 ;
void T_4 * V_10 ;
T_1 V_25 ;
int V_70 , V_86 = 0 ;
int V_9 ;
F_26 ( & V_84 -> V_28 , L_3 ) ;
V_10 = F_27 ( V_84 -> V_28 . V_87 , 0 ) ;
if ( ! V_10 )
return - V_88 ;
V_25 = V_32 | V_33 | V_34 ;
F_3 ( V_10 + V_42 , V_25 ) ;
F_3 ( V_10 + V_89 , 0x0 ) ;
F_3 ( V_10 + V_90 , 0xe ) ;
F_3 ( V_10 + V_11 , 0x8 ) ;
F_13 ( V_10 + V_71 ) ;
F_3 ( V_10 + V_42 , V_25 ) ;
F_13 ( V_10 + V_18 ) ;
if ( F_13 ( V_10 + V_71 ) & V_58 ) {
F_7 ( & V_84 -> V_28 , L_4 ) ;
V_70 = - V_60 ;
goto V_91;
}
F_26 ( & V_84 -> V_28 , L_5 ) ;
V_27 = F_28 ( & V_84 -> V_28 , sizeof *V_2 ) ;
if ( ! V_27 ) {
V_70 = - V_92 ;
goto V_93;
}
V_27 -> V_94 = - 1 ;
V_27 -> V_95 = F_21 ;
V_27 -> V_13 = F_22 ;
V_27 -> V_96 = V_38 | V_36 | V_40 ;
V_27 -> V_28 . V_87 = V_84 -> V_28 . V_87 ;
F_29 ( & V_84 -> V_28 , V_27 ) ;
V_2 = F_23 ( V_27 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_53 = F_30 ( V_84 -> V_28 . V_87 , 0 ) ;
V_2 -> V_97 = F_30 ( V_84 -> V_28 . V_87 , 1 ) ;
V_2 -> V_50 = F_6 ;
V_2 -> V_43 = F_31 ( V_84 -> V_28 . V_87 ) ;
V_2 -> V_5 = F_32 ( V_84 -> V_28 . V_87 ) ;
if ( V_2 -> V_5 > 0 ) {
V_27 -> V_80 = V_2 -> V_5 ;
V_2 -> V_9 = F_33 ( V_2 -> V_5 * sizeof( unsigned int ) ,
V_98 ) ;
if ( ! V_2 -> V_9 ) {
V_70 = - V_92 ;
goto V_93;
}
for ( V_86 = 0 ; V_86 < V_2 -> V_5 ; V_86 ++ ) {
V_9 = F_34 ( V_84 -> V_28 . V_87 , V_86 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_84 -> V_28 ,
L_6
L_7 ) ;
V_70 = - V_88 ;
goto V_99;
}
V_70 = F_35 ( V_9 , F_36 ( & V_84 -> V_28 ) ) ;
if ( V_70 ) {
F_7 ( & V_84 -> V_28 ,
L_8
L_9 , V_86 , V_9 ) ;
goto V_99;
}
F_37 ( V_9 , 1 ) ;
V_2 -> V_9 [ V_86 ] = V_9 ;
}
} else {
V_27 -> V_80 = 1 ;
}
F_38 ( & V_2 -> V_74 ) ;
F_39 ( & V_2 -> V_29 ) ;
F_40 ( & V_2 -> V_72 , F_18 ) ;
if ( V_2 -> V_53 && V_2 -> V_97 ) {
V_70 = F_41 ( V_2 -> V_53 , F_15 , 0 ,
L_10 , V_2 ) ;
V_70 |= F_41 ( V_2 -> V_97 , F_15 , 0 ,
L_11 , V_2 ) ;
if ( V_70 ) {
F_42 ( V_2 -> V_53 , V_2 ) ;
F_42 ( V_2 -> V_97 , V_2 ) ;
V_2 -> V_53 = V_2 -> V_97 = 0 ;
}
} else {
V_2 -> V_53 = V_2 -> V_97 = 0 ;
}
if ( ! V_2 -> V_53 )
F_43 ( & V_84 -> V_28 , L_12 ) ;
F_26 ( & V_84 -> V_28 , L_13 ) ;
V_70 = F_44 ( V_27 ) ;
if ( V_70 )
goto V_100;
F_43 ( & V_2 -> V_27 -> V_28 , L_14 ) ;
return V_70 ;
V_100:
F_7 ( & V_2 -> V_27 -> V_28 , L_15 ) ;
F_45 ( V_27 ) ;
V_99:
while ( V_86 -- > 0 )
F_46 ( V_2 -> V_9 [ V_86 ] ) ;
F_47 ( V_2 -> V_9 ) ;
V_93:
V_91:
F_48 ( V_10 ) ;
return V_70 ;
}
static int T_5 F_49 ( struct V_83 * V_84 )
{
struct V_85 * V_27 = F_50 ( & V_84 -> V_28 ) ;
struct V_1 * V_2 = F_23 ( V_27 ) ;
int V_86 ;
F_42 ( V_2 -> V_53 , V_2 ) ;
F_42 ( V_2 -> V_97 , V_2 ) ;
for ( V_86 = 0 ; V_86 < V_2 -> V_5 ; V_86 ++ )
F_46 ( V_2 -> V_9 [ V_86 ] ) ;
F_47 ( V_2 -> V_9 ) ;
F_51 ( V_27 ) ;
F_45 ( V_27 ) ;
F_48 ( V_2 -> V_10 ) ;
return 0 ;
}
static int T_6 F_52 ( void )
{
return F_53 ( & V_101 ) ;
}
static void T_7 F_54 ( void )
{
F_55 ( & V_101 ) ;
}
