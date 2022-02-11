static void F_1 ( struct V_1 * V_2 ,
bool V_3 , T_1 V_4 )
{
if ( ! V_3 )
V_2 -> V_5 [ V_2 -> V_6 ] = V_4 ;
V_2 -> V_6 ++ ;
}
static unsigned int F_2 ( struct V_7 * V_8 )
{
unsigned int V_9 = 0 ;
if ( V_8 -> V_10 & V_11 )
V_9 |= V_12 ;
if ( V_8 -> V_10 & V_13 )
V_9 |= V_14 ;
if ( V_8 -> V_10 & V_15 )
V_9 |= V_16 ;
return V_9 ;
}
static unsigned int F_3 ( struct V_17 * V_17 ,
struct V_7 * V_8 , struct V_18 * V_19 )
{
unsigned int V_20 ;
V_20 = F_4 ( F_5 ( V_17 -> V_21 ) ,
V_19 -> V_22 * 2 ) ;
if ( V_20 > 255 )
V_20 = 255 ;
else if ( V_20 > 0 )
V_20 -= 1 ;
return V_20 ;
}
static void F_6 ( struct V_1 * V_2 , bool V_3 ,
struct V_18 * V_19 )
{
unsigned int V_23 = V_19 -> V_23 ;
while ( V_23 ) {
unsigned int V_24 = F_7 ( V_23 , 256U ) ;
unsigned int V_25 = 0 ;
if ( V_19 -> V_26 )
V_25 |= V_27 ;
if ( V_19 -> V_28 )
V_25 |= V_29 ;
F_1 ( V_2 , V_3 ,
F_8 ( V_25 , V_24 - 1 ) ) ;
V_23 -= V_24 ;
}
}
static void F_9 ( struct V_1 * V_2 , bool V_3 ,
struct V_17 * V_17 , unsigned int V_20 , unsigned int V_30 )
{
unsigned int V_31 = F_5 ( V_17 -> V_21 ) ;
unsigned int V_32 ;
if ( V_30 == 0 )
return;
V_32 = F_4 ( V_30 * V_31 , ( V_20 + 1 ) * 2 ) ;
while ( V_32 ) {
unsigned int V_24 = F_7 ( V_32 , 256U ) ;
F_1 ( V_2 , V_3 , F_10 ( V_24 - 1 ) ) ;
V_32 -= V_24 ;
}
}
static void F_11 ( struct V_1 * V_2 , bool V_3 ,
struct V_7 * V_8 , bool assert )
{
unsigned int V_33 = 0xff ;
if ( assert )
V_33 ^= F_12 ( V_8 -> V_34 ) ;
F_1 ( V_2 , V_3 , F_13 ( 1 , V_33 ) ) ;
}
static int F_14 ( struct V_17 * V_17 ,
struct V_35 * V_36 , bool V_3 , struct V_1 * V_2 )
{
struct V_7 * V_8 = V_36 -> V_8 ;
struct V_18 * V_19 ;
int V_20 , V_37 ;
bool V_38 = true ;
V_20 = - 1 ;
F_1 ( V_2 , V_3 ,
F_15 ( V_39 ,
F_2 ( V_8 ) ) ) ;
F_16 (xfer, &msg->transfers, transfer_list) {
V_37 = F_3 ( V_17 , V_8 , V_19 ) ;
if ( V_37 != V_20 ) {
V_20 = V_37 ;
F_1 ( V_2 , V_3 ,
F_15 ( V_40 ,
V_20 ) ) ;
}
if ( V_38 )
F_11 ( V_2 , V_3 , V_8 , true ) ;
F_6 ( V_2 , V_3 , V_19 ) ;
F_9 ( V_2 , V_3 , V_17 , V_20 ,
V_19 -> V_41 ) ;
V_38 = V_19 -> V_38 ;
if ( F_17 ( & V_19 -> V_42 , & V_36 -> V_43 ) )
V_38 = ! V_38 ;
if ( V_38 )
F_11 ( V_2 , V_3 , V_8 , false ) ;
}
return 0 ;
}
static void F_18 ( struct V_17 * V_17 ,
struct V_18 * * V_44 )
{
struct V_35 * V_36 = V_17 -> V_36 ;
struct V_18 * V_19 = * V_44 ;
if ( ! V_19 ) {
V_19 = F_19 ( & V_36 -> V_43 ,
struct V_18 , V_42 ) ;
} else if ( F_17 ( & V_19 -> V_42 , & V_36 -> V_43 ) ) {
V_19 = NULL ;
} else {
V_19 = F_20 ( V_19 , V_42 ) ;
}
* V_44 = V_19 ;
}
static void F_21 ( struct V_17 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_45 ;
do {
F_18 ( V_17 , & V_19 ) ;
} while ( V_19 && ! V_19 -> V_26 );
V_17 -> V_45 = V_19 ;
if ( V_19 ) {
V_17 -> V_46 = V_19 -> V_23 ;
V_17 -> V_26 = V_19 -> V_26 ;
} else {
V_17 -> V_26 = NULL ;
}
}
static void F_22 ( struct V_17 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_47 ;
do {
F_18 ( V_17 , & V_19 ) ;
} while ( V_19 && ! V_19 -> V_28 );
V_17 -> V_47 = V_19 ;
if ( V_19 ) {
V_17 -> V_48 = V_19 -> V_23 ;
V_17 -> V_28 = V_19 -> V_28 ;
} else {
V_17 -> V_28 = NULL ;
}
}
static bool F_23 ( struct V_17 * V_17 )
{
void T_2 * V_49 = V_17 -> V_50 + V_51 ;
unsigned int V_24 , V_52 , V_53 ;
const T_1 * V_54 ;
V_24 = F_24 ( V_17 -> V_50 + V_55 ) ;
while ( V_24 && V_17 -> V_56 ) {
V_52 = F_7 ( V_24 , V_17 -> V_56 ) ;
V_54 = V_17 -> V_57 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
F_25 ( V_54 [ V_53 ] , V_49 ) ;
V_17 -> V_57 += V_52 ;
V_17 -> V_56 -= V_52 ;
V_24 -= V_52 ;
}
return V_17 -> V_56 != 0 ;
}
static bool F_26 ( struct V_17 * V_17 )
{
void T_2 * V_49 = V_17 -> V_50 + V_58 ;
unsigned int V_24 , V_52 , V_53 ;
const T_3 * V_54 ;
V_24 = F_24 ( V_17 -> V_50 + V_59 ) ;
while ( V_24 && V_17 -> V_46 ) {
V_52 = F_7 ( V_24 , V_17 -> V_46 ) ;
V_54 = V_17 -> V_26 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
F_25 ( V_54 [ V_53 ] , V_49 ) ;
V_17 -> V_26 += V_52 ;
V_17 -> V_46 -= V_52 ;
V_24 -= V_52 ;
if ( V_17 -> V_46 == 0 )
F_21 ( V_17 ) ;
}
return V_17 -> V_46 != 0 ;
}
static bool F_27 ( struct V_17 * V_17 )
{
void T_2 * V_49 = V_17 -> V_50 + V_60 ;
unsigned int V_24 , V_52 , V_53 ;
T_3 * V_54 ;
V_24 = F_24 ( V_17 -> V_50 + V_61 ) ;
while ( V_24 && V_17 -> V_48 ) {
V_52 = F_7 ( V_24 , V_17 -> V_48 ) ;
V_54 = V_17 -> V_28 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ )
V_54 [ V_53 ] = F_24 ( V_49 ) ;
V_17 -> V_28 += V_52 ;
V_17 -> V_48 -= V_52 ;
V_24 -= V_52 ;
if ( V_17 -> V_48 == 0 )
F_22 ( V_17 ) ;
}
return V_17 -> V_48 != 0 ;
}
static T_4 F_28 ( int V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
struct V_17 * V_17 = F_29 ( V_65 ) ;
unsigned int V_66 = 0 ;
unsigned int V_67 ;
V_67 = F_24 ( V_17 -> V_50 + V_68 ) ;
if ( V_67 & V_69 ) {
F_25 ( V_69 ,
V_17 -> V_50 + V_68 ) ;
V_17 -> V_70 = F_24 (
V_17 -> V_50 + V_71 ) ;
}
F_30 ( & V_17 -> V_72 ) ;
if ( V_67 & V_73 ) {
if ( ! F_23 ( V_17 ) )
V_66 |= V_73 ;
}
if ( V_67 & V_74 ) {
if ( ! F_26 ( V_17 ) )
V_66 |= V_74 ;
}
if ( V_67 & ( V_75 | V_69 ) ) {
if ( ! F_27 ( V_17 ) )
V_66 |= V_75 ;
}
if ( V_67 & V_69 ) {
if ( V_17 -> V_36 &&
V_17 -> V_70 == V_17 -> V_76 ) {
struct V_35 * V_36 = V_17 -> V_36 ;
F_31 ( V_17 -> V_2 ) ;
V_36 -> V_77 = 0 ;
V_36 -> V_78 = V_36 -> V_79 ;
V_17 -> V_36 = NULL ;
F_32 ( V_65 ) ;
V_66 |= V_69 ;
}
}
if ( V_66 ) {
V_17 -> V_80 &= ~ V_66 ;
F_25 ( V_17 -> V_80 ,
V_17 -> V_50 + V_81 ) ;
}
F_33 ( & V_17 -> V_72 ) ;
return V_82 ;
}
static int F_34 ( struct V_64 * V_65 ,
struct V_35 * V_36 )
{
struct V_1 V_83 , * V_2 ;
struct V_17 * V_17 = F_29 ( V_65 ) ;
unsigned int V_80 = 0 ;
unsigned long V_25 ;
T_5 V_84 ;
V_83 . V_6 = 0 ;
F_14 ( V_17 , V_36 , true , & V_83 ) ;
V_84 = sizeof( * V_2 -> V_5 ) * ( V_83 . V_6 + 1 ) ;
V_2 = F_35 ( sizeof( * V_2 ) + V_84 , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
F_14 ( V_17 , V_36 , false , V_2 ) ;
F_36 ( & V_17 -> V_72 , V_25 ) ;
V_17 -> V_76 = ( V_17 -> V_76 + 1 ) & 0xff ;
F_1 ( V_2 , false ,
F_37 ( V_17 -> V_76 ) ) ;
V_17 -> V_36 = V_36 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_57 = V_2 -> V_5 ;
V_17 -> V_56 = V_2 -> V_6 ;
if ( F_23 ( V_17 ) )
V_80 |= V_73 ;
F_21 ( V_17 ) ;
if ( F_26 ( V_17 ) )
V_80 |= V_74 ;
F_22 ( V_17 ) ;
if ( V_17 -> V_48 != 0 )
V_80 |= V_75 ;
V_80 |= V_69 ;
F_25 ( V_80 ,
V_17 -> V_50 + V_81 ) ;
V_17 -> V_80 = V_80 ;
F_38 ( & V_17 -> V_72 , V_25 ) ;
return 0 ;
}
static int F_39 ( struct V_87 * V_88 )
{
struct V_17 * V_17 ;
struct V_64 * V_65 ;
unsigned int V_89 ;
struct V_90 * V_91 ;
int V_62 ;
int V_92 ;
V_62 = F_40 ( V_88 , 0 ) ;
if ( V_62 <= 0 )
return - V_93 ;
V_17 = F_41 ( & V_88 -> V_94 , sizeof( * V_17 ) , V_85 ) ;
if ( ! V_17 )
return - V_86 ;
V_65 = F_42 ( & V_88 -> V_94 , 0 ) ;
if ( ! V_65 )
return - V_86 ;
F_43 ( V_65 , V_17 ) ;
F_44 ( & V_17 -> V_72 ) ;
V_91 = F_45 ( V_88 , V_95 , 0 ) ;
V_17 -> V_50 = F_46 ( & V_88 -> V_94 , V_91 ) ;
if ( F_47 ( V_17 -> V_50 ) ) {
V_92 = F_48 ( V_17 -> V_50 ) ;
goto V_96;
}
V_89 = F_49 ( V_17 -> V_50 + V_97 ) ;
if ( F_50 ( V_89 ) != 1 ) {
F_51 ( & V_88 -> V_94 , L_1 ,
F_50 ( V_89 ) ,
F_52 ( V_89 ) ,
F_53 ( V_89 ) ) ;
V_92 = - V_98 ;
goto V_96;
}
V_17 -> V_99 = F_54 ( & V_88 -> V_94 , L_2 ) ;
if ( F_47 ( V_17 -> V_99 ) ) {
V_92 = F_48 ( V_17 -> V_99 ) ;
goto V_96;
}
V_17 -> V_21 = F_54 ( & V_88 -> V_94 , L_3 ) ;
if ( F_47 ( V_17 -> V_21 ) ) {
V_92 = F_48 ( V_17 -> V_21 ) ;
goto V_96;
}
V_92 = F_55 ( V_17 -> V_99 ) ;
if ( V_92 )
goto V_96;
V_92 = F_55 ( V_17 -> V_21 ) ;
if ( V_92 )
goto V_100;
F_25 ( 0x00 , V_17 -> V_50 + V_101 ) ;
F_25 ( 0xff , V_17 -> V_50 + V_68 ) ;
F_25 ( 0x00 , V_17 -> V_50 + V_81 ) ;
V_92 = F_56 ( V_62 , F_28 , 0 , V_88 -> V_102 , V_65 ) ;
if ( V_92 )
goto V_103;
V_65 -> V_94 . V_104 = V_88 -> V_94 . V_104 ;
V_65 -> V_105 = V_11 | V_13 | V_15 ;
V_65 -> V_106 = F_57 ( 8 ) ;
V_65 -> V_107 = F_5 ( V_17 -> V_21 ) / 2 ;
V_65 -> V_108 = F_34 ;
V_65 -> V_109 = 8 ;
V_92 = F_58 ( V_65 ) ;
if ( V_92 )
goto V_110;
F_59 ( V_88 , V_65 ) ;
return 0 ;
V_110:
F_60 ( V_62 , V_65 ) ;
V_103:
F_61 ( V_17 -> V_21 ) ;
V_100:
F_61 ( V_17 -> V_99 ) ;
V_96:
F_62 ( V_65 ) ;
return V_92 ;
}
static int F_63 ( struct V_87 * V_88 )
{
struct V_64 * V_65 = F_64 ( V_88 ) ;
struct V_17 * V_17 = F_29 ( V_65 ) ;
int V_62 = F_40 ( V_88 , 0 ) ;
F_65 ( V_65 ) ;
F_60 ( V_62 , V_65 ) ;
F_25 ( 0xff , V_17 -> V_50 + V_68 ) ;
F_25 ( 0x00 , V_17 -> V_50 + V_81 ) ;
F_25 ( 0x01 , V_17 -> V_50 + V_101 ) ;
F_61 ( V_17 -> V_21 ) ;
F_61 ( V_17 -> V_99 ) ;
return 0 ;
}
