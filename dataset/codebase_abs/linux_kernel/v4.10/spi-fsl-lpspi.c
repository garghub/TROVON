static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return F_5 ( V_2 -> V_8 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_7 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_9 ;
unsigned long V_10 = V_11 ;
do {
V_9 = F_9 ( V_2 -> V_4 + V_12 ) & 0xff ;
if ( F_10 ( V_11 , V_10 + F_11 ( 500 ) ) ) {
F_12 ( V_2 -> V_13 , L_1 ) ;
return - V_14 ;
}
F_13 () ;
} while ( V_9 );
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_15 ;
V_15 = F_9 ( V_2 -> V_4 + V_12 ) & 0xff ;
while ( V_15 < V_2 -> V_16 ) {
if ( ! V_2 -> V_17 )
break;
V_2 -> V_18 ( V_2 ) ;
V_15 ++ ;
}
if ( ! V_2 -> V_17 && ( V_15 < V_2 -> V_16 ) )
F_2 ( 0 , V_2 -> V_4 + V_19 ) ;
else
F_1 ( V_2 , V_20 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
while ( ! ( F_9 ( V_2 -> V_4 + V_21 ) & V_22 ) )
V_2 -> V_23 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
bool V_24 )
{
T_1 V_25 = 0 ;
V_25 |= V_2 -> V_26 . V_27 - 1 ;
V_25 |= V_2 -> V_26 . V_28 << 27 ;
V_25 |= ( V_2 -> V_26 . V_29 & 0x3 ) << 30 ;
V_25 |= ( V_2 -> V_26 . V_30 & 0x3 ) << 24 ;
V_25 |= V_31 ;
if ( V_24 )
V_25 &= ~ V_32 ;
else
V_25 |= V_32 ;
F_2 ( V_25 , V_2 -> V_4 + V_33 ) ;
F_12 ( V_2 -> V_13 , L_2 , V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_25 ;
V_25 = V_2 -> V_16 >> 1 | ( V_2 -> V_34 >> 1 ) << 16 ;
F_2 ( V_25 , V_2 -> V_4 + V_35 ) ;
F_12 ( V_2 -> V_13 , L_3 , V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_36 V_26 = V_2 -> V_26 ;
unsigned int V_37 , V_38 ;
T_2 V_28 ;
V_37 = F_19 ( V_2 -> V_8 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_38 = V_37 /
( V_39 [ V_28 ] * V_26 . V_40 ) - 2 ;
if ( V_38 < 256 ) {
V_2 -> V_26 . V_28 = V_28 ;
break;
}
}
if ( V_28 == 8 && V_38 >= 256 )
return - V_41 ;
F_2 ( V_38 , V_2 -> V_4 + V_42 ) ;
F_12 ( V_2 -> V_13 , L_4 ,
V_37 , V_26 . V_40 , V_28 , V_38 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_25 ;
int V_43 ;
V_25 = V_44 ;
F_2 ( V_25 , V_2 -> V_4 + V_45 ) ;
F_2 ( 0 , V_2 -> V_4 + V_45 ) ;
V_43 = F_18 ( V_2 ) ;
if ( V_43 )
return V_43 ;
F_17 ( V_2 ) ;
V_25 = V_46 | V_47 | V_48 ;
if ( V_2 -> V_26 . V_29 & V_49 )
V_25 |= V_50 ;
F_2 ( V_25 , V_2 -> V_4 + V_51 ) ;
V_25 = F_9 ( V_2 -> V_4 + V_45 ) ;
V_25 |= V_52 | V_53 | V_54 ;
F_2 ( V_25 , V_2 -> V_4 + V_45 ) ;
return 0 ;
}
static void F_21 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_56 -> V_7 ) ;
V_2 -> V_26 . V_29 = V_56 -> V_29 ;
V_2 -> V_26 . V_27 = V_58 ? V_58 -> V_59 : V_56 -> V_59 ;
V_2 -> V_26 . V_40 = V_58 ? V_58 -> V_40 : V_56 -> V_60 ;
V_2 -> V_26 . V_30 = V_56 -> V_30 ;
if ( ! V_2 -> V_26 . V_40 )
V_2 -> V_26 . V_40 = V_56 -> V_60 ;
if ( ! V_2 -> V_26 . V_27 )
V_2 -> V_26 . V_27 = V_56 -> V_59 ;
if ( V_2 -> V_26 . V_27 <= 8 ) {
V_2 -> V_23 = V_61 ;
V_2 -> V_18 = V_62 ;
} else if ( V_2 -> V_26 . V_27 <= 16 ) {
V_2 -> V_23 = V_63 ;
V_2 -> V_18 = V_64 ;
} else {
V_2 -> V_23 = V_65 ;
V_2 -> V_18 = V_66 ;
}
F_20 ( V_2 ) ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_43 ;
V_2 -> V_67 = V_58 -> V_67 ;
V_2 -> V_68 = V_58 -> V_68 ;
V_2 -> V_17 = V_58 -> V_69 ;
F_23 ( & V_2 -> V_70 ) ;
F_14 ( V_2 ) ;
V_43 = F_24 ( & V_2 -> V_70 , V_71 ) ;
if ( ! V_43 ) {
F_12 ( V_2 -> V_13 , L_5 ) ;
return - V_14 ;
}
V_43 = F_8 ( V_2 ) ;
if ( V_43 )
return V_43 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_55 * V_56 = V_73 -> V_56 ;
struct V_57 * V_74 ;
bool V_24 = true ;
T_1 V_25 ;
int V_43 ;
V_73 -> V_75 = 0 ;
V_73 -> V_76 = 0 ;
F_26 (xfer, &msg->transfers, transfer_list) {
F_21 ( V_56 , V_74 ) ;
F_16 ( V_2 , V_24 ) ;
V_24 = false ;
V_43 = F_22 ( V_7 , V_56 , V_74 ) ;
if ( V_43 < 0 )
goto V_77;
V_73 -> V_76 += V_74 -> V_69 ;
}
V_77:
V_25 = F_9 ( V_2 -> V_4 + V_33 ) ;
V_25 &= ~ V_32 ;
F_2 ( V_25 , V_2 -> V_4 + V_33 ) ;
V_73 -> V_75 = V_43 ;
F_27 ( V_7 ) ;
return V_43 ;
}
static T_3 F_28 ( int V_78 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
T_1 V_25 ;
F_1 ( V_2 , 0 ) ;
V_25 = F_9 ( V_2 -> V_4 + V_80 ) ;
F_15 ( V_2 ) ;
if ( V_25 & V_81 ) {
F_14 ( V_2 ) ;
if ( ! V_2 -> V_17 )
V_77 ( & V_2 -> V_70 ) ;
return V_82 ;
}
return V_83 ;
}
static int F_29 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_86 * V_87 ;
int V_43 , V_78 ;
T_1 V_25 ;
V_7 = F_30 ( & V_85 -> V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_7 )
return - V_88 ;
F_31 ( V_85 , V_7 ) ;
V_7 -> V_89 = F_32 ( 8 , 32 ) ;
V_7 -> V_90 = V_85 -> V_91 ;
V_2 = F_4 ( V_7 ) ;
V_2 -> V_13 = & V_85 -> V_13 ;
V_7 -> V_92 = F_25 ;
V_7 -> V_93 = F_3 ;
V_7 -> V_94 = F_6 ;
V_7 -> V_95 = V_96 | V_97 | V_49 ;
V_7 -> V_98 = V_99 | V_100 ;
V_7 -> V_13 . V_101 = V_85 -> V_13 . V_101 ;
V_7 -> V_90 = V_85 -> V_91 ;
F_33 ( & V_2 -> V_70 ) ;
V_87 = F_34 ( V_85 , V_102 , 0 ) ;
V_2 -> V_4 = F_35 ( & V_85 -> V_13 , V_87 ) ;
if ( F_36 ( V_2 -> V_4 ) ) {
V_43 = F_37 ( V_2 -> V_4 ) ;
goto V_103;
}
V_78 = F_38 ( V_85 , 0 ) ;
if ( V_78 < 0 ) {
V_43 = V_78 ;
goto V_103;
}
V_43 = F_39 ( & V_85 -> V_13 , V_78 , F_28 , 0 ,
F_40 ( & V_85 -> V_13 ) , V_2 ) ;
if ( V_43 ) {
F_41 ( & V_85 -> V_13 , L_6 , V_78 , V_43 ) ;
goto V_103;
}
V_2 -> V_8 = F_42 ( & V_85 -> V_13 , L_7 ) ;
if ( F_36 ( V_2 -> V_8 ) ) {
V_43 = F_37 ( V_2 -> V_8 ) ;
goto V_103;
}
V_43 = F_5 ( V_2 -> V_8 ) ;
if ( V_43 ) {
F_41 ( & V_85 -> V_13 , L_8 , V_43 ) ;
goto V_103;
}
V_25 = F_9 ( V_2 -> V_4 + V_104 ) ;
V_2 -> V_16 = 1 << ( V_25 & 0x0f ) ;
V_2 -> V_34 = 1 << ( ( V_25 >> 8 ) & 0x0f ) ;
F_7 ( V_2 -> V_8 ) ;
V_43 = F_43 ( & V_85 -> V_13 , V_7 ) ;
if ( V_43 < 0 ) {
F_41 ( & V_85 -> V_13 , L_9 ) ;
goto V_103;
}
return 0 ;
V_103:
F_44 ( V_7 ) ;
return V_43 ;
}
static int F_45 ( struct V_84 * V_85 )
{
struct V_6 * V_7 = F_46 ( V_85 ) ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_7 ( V_2 -> V_8 ) ;
return 0 ;
}
