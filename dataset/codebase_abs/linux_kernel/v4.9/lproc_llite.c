static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 )
return sprintf ( V_5 , L_1 , V_10 . V_15 ) ;
return V_11 ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 ) {
T_2 V_16 = V_10 . V_15 >> 10 ;
T_3 V_17 = V_10 . V_18 ;
while ( V_16 >>= 1 )
V_17 <<= 1 ;
V_11 = sprintf ( V_5 , L_2 , V_17 ) ;
}
return V_11 ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 ) {
T_2 V_16 = V_10 . V_15 >> 10 ;
T_3 V_17 = V_10 . V_19 ;
while ( V_16 >>= 1 )
V_17 <<= 1 ;
V_11 = sprintf ( V_5 , L_2 , V_17 ) ;
}
return V_11 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 ) {
T_2 V_16 = V_10 . V_15 >> 10 ;
T_3 V_17 = V_10 . V_20 ;
while ( V_16 >>= 1 )
V_17 <<= 1 ;
V_11 = sprintf ( V_5 , L_2 , V_17 ) ;
}
return V_11 ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 )
return sprintf ( V_5 , L_2 , V_10 . V_21 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_9 V_10 ;
int V_11 ;
V_11 = F_3 ( V_7 -> V_12 , & V_10 ,
F_4 ( - V_13 ) ,
V_14 ) ;
if ( ! V_11 )
return sprintf ( V_5 , L_2 , V_10 . V_22 ) ;
return V_11 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_3 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_4 , V_7 -> V_12 -> V_23 -> V_24 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_4 , V_7 -> V_25 . V_26 ) ;
}
static int F_13 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
return F_14 ( F_15 ( F_16 ( V_31 ) -> V_33 ) , V_28 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_34 ;
int V_35 ;
F_18 ( & V_7 -> V_36 ) ;
V_34 = V_7 -> V_37 . V_38 ;
F_19 ( & V_7 -> V_36 ) ;
V_35 = 1 << ( 20 - V_39 ) ;
return F_20 ( V_5 , V_40 , V_34 , V_35 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_34 ;
V_11 = F_22 ( V_41 , 10 , & V_34 ) ;
if ( V_11 )
return V_11 ;
V_34 *= 1 << ( 20 - V_39 ) ;
if ( V_34 > V_43 / 2 ) {
F_23 ( L_5 ,
V_43 >> ( 20 - V_39 + 1 ) ) ;
return - V_44 ;
}
F_18 ( & V_7 -> V_36 ) ;
V_7 -> V_37 . V_38 = V_34 ;
F_19 ( & V_7 -> V_36 ) ;
return V_42 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_34 ;
int V_35 ;
F_18 ( & V_7 -> V_36 ) ;
V_34 = V_7 -> V_37 . V_45 ;
F_19 ( & V_7 -> V_36 ) ;
V_35 = 1 << ( 20 - V_39 ) ;
return F_20 ( V_5 , V_40 , V_34 , V_35 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_34 ;
V_11 = F_22 ( V_41 , 10 , & V_34 ) ;
if ( V_11 )
return V_11 ;
if ( V_34 > V_7 -> V_37 . V_38 ) {
F_23 ( L_6 ,
V_7 -> V_37 . V_38 ) ;
return - V_44 ;
}
F_18 ( & V_7 -> V_36 ) ;
V_7 -> V_37 . V_45 = V_34 ;
F_19 ( & V_7 -> V_36 ) ;
return V_42 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_34 ;
int V_35 ;
F_18 ( & V_7 -> V_36 ) ;
V_34 = V_7 -> V_37 . V_46 ;
F_19 ( & V_7 -> V_36 ) ;
V_35 = 1 << ( 20 - V_39 ) ;
return F_20 ( V_5 , V_40 , V_34 , V_35 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_34 ;
V_11 = F_22 ( V_41 , 10 , & V_34 ) ;
if ( V_11 )
return V_11 ;
if ( V_34 > V_7 -> V_37 . V_45 ) {
F_23 ( L_7 ,
V_7 -> V_37 . V_45 >> ( 20 - V_39 ) ) ;
return - V_44 ;
}
F_18 ( & V_7 -> V_36 ) ;
V_7 -> V_37 . V_46 = V_34 ;
F_19 ( & V_7 -> V_36 ) ;
return V_42 ;
}
static int F_28 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_47 * V_48 = V_7 -> V_49 ;
int V_50 = 20 - V_39 ;
long V_51 ;
long V_52 ;
V_51 = V_48 -> V_53 >> V_50 ;
V_52 = F_29 ( & V_48 -> V_54 ) >> V_50 ;
F_30 ( V_28 ,
L_8
L_9
L_10
L_11
L_12 ,
F_31 ( & V_48 -> V_55 ) ,
V_51 ,
V_51 - V_52 ,
V_52 ,
V_48 -> V_56 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_57 * V_57 ,
const char T_5 * V_41 ,
T_4 V_42 , T_6 * V_58 )
{
struct V_30 * V_31 = ( (struct V_27 * ) V_57 -> V_59 ) -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_47 * V_48 = V_7 -> V_49 ;
struct V_60 * V_61 ;
long V_62 = 0 ;
long V_63 = 0 ;
int V_64 ;
long V_34 ;
int V_35 ;
long V_11 ;
T_7 V_65 ;
char V_66 [ 128 ] ;
if ( V_42 >= sizeof( V_66 ) )
return - V_67 ;
if ( F_33 ( V_66 , V_41 , V_42 ) )
return - V_68 ;
V_66 [ V_42 ] = 0 ;
V_35 = 1 << ( 20 - V_39 ) ;
V_41 += F_34 ( V_66 , L_13 , & V_42 ) -
V_66 ;
V_11 = F_35 ( V_41 , V_42 , & V_65 , V_35 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 > V_69 )
return - V_44 ;
V_34 = ( long ) V_65 ;
if ( V_34 < 0 || V_34 > V_43 ) {
F_23 ( L_14 ,
F_36 ( V_31 , NULL , 0 ) ,
V_43 >> ( 20 - V_39 ) ) ;
return - V_44 ;
}
F_18 ( & V_7 -> V_36 ) ;
V_62 = V_34 - V_48 -> V_53 ;
F_19 ( & V_7 -> V_36 ) ;
if ( V_62 >= 0 ) {
F_37 ( V_62 , & V_48 -> V_54 ) ;
V_11 = 0 ;
goto V_70;
}
V_61 = F_38 ( & V_64 ) ;
if ( F_39 ( V_61 ) )
return 0 ;
V_62 = - V_62 ;
while ( V_62 > 0 ) {
long V_71 ;
do {
long V_72 , V_73 ;
V_72 = F_29 ( & V_48 -> V_54 ) ;
if ( V_72 == 0 )
break;
V_73 = V_72 > V_62 ? V_72 - V_62 : 0 ;
V_11 = F_40 ( & V_48 -> V_54 , V_72 , V_73 ) ;
if ( F_41 ( V_72 == V_11 ) ) {
V_62 -= V_72 - V_73 ;
V_63 += V_72 - V_73 ;
break;
}
} while ( 1 );
if ( V_62 <= 0 )
break;
if ( ! V_7 -> V_74 ) {
V_11 = 0 ;
goto V_70;
}
V_71 = V_62 << 1 ;
V_11 = F_42 ( V_61 , V_7 -> V_74 ,
sizeof( V_75 ) ,
V_75 ,
sizeof( V_71 ) , & V_71 , NULL ) ;
if ( V_11 < 0 )
break;
}
F_43 ( V_61 , & V_64 ) ;
V_70:
if ( V_11 >= 0 ) {
F_18 ( & V_7 -> V_36 ) ;
V_48 -> V_53 = V_34 ;
F_19 ( & V_7 -> V_36 ) ;
V_11 = V_42 ;
} else {
F_37 ( V_63 , & V_48 -> V_54 ) ;
}
return V_11 ;
}
static T_1 F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ( V_7 -> V_76 & V_77 ) ? 1 : 0 ) ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_65 ;
if ( ! V_7 -> V_74 )
return - V_78 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 )
V_7 -> V_76 |= V_77 ;
else
V_7 -> V_76 &= ~ V_77 ;
V_11 = F_42 ( NULL , V_7 -> V_74 , sizeof( V_79 ) ,
V_79 , sizeof( V_65 ) , & V_65 , NULL ) ;
if ( V_11 )
F_46 ( L_15 , V_11 ) ;
return V_42 ;
}
static T_1 F_47 ( struct V_1 * V_2 , char * V_5 ,
enum V_80 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
if ( V_7 -> V_81 == type )
return sprintf ( V_5 , L_16 , V_7 -> V_82 ) ;
else if ( V_7 -> V_81 == V_83 )
return sprintf ( V_5 , L_17 ) ;
else
return sprintf ( V_5 , L_18 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 , const char * V_41 ,
T_4 V_42 ,
enum V_80 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_84 ;
V_11 = F_22 ( V_41 , 10 , & V_84 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_82 = V_84 ;
if ( V_84 == 0 )
V_7 -> V_81 = V_83 ;
else
V_7 -> V_81 = type ;
F_49 ( V_7 -> V_85 ) ;
return V_42 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_47 ( V_2 , V_5 , V_86 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_48 ( V_2 , V_41 , V_42 , V_86 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_47 ( V_2 , V_5 , V_87 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_48 ( V_2 , V_41 , V_42 , V_87 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_47 ( V_2 , V_5 , V_88 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_48 ( V_2 , V_41 , V_42 , V_88 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_89 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_65 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 <= V_90 )
V_7 -> V_89 = V_65 ;
else
F_23 ( L_19 ,
V_65 , V_90 ) ;
return V_42 ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_76 & V_91 ? 1 : 0 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_65 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 )
V_7 -> V_76 |= V_91 ;
else
V_7 -> V_76 &= ~ V_91 ;
return V_42 ;
}
static int F_60 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
F_30 ( V_28 ,
L_20
L_21
L_22 ,
F_31 ( & V_7 -> V_92 ) ,
F_31 ( & V_7 -> V_93 ) ,
F_31 ( & V_7 -> V_94 ) ) ;
return 0 ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_76 & V_95 ? 1 : 0 ) ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_65 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 )
V_7 -> V_76 |= V_95 ;
else
V_7 -> V_76 &= ~ V_95 ;
return V_42 ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_96 ;
int V_11 ;
V_11 = F_64 ( V_7 , & V_96 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_96 ) ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_96 ;
int V_11 ;
V_11 = F_66 ( V_7 , & V_96 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_96 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned long V_65 ;
int V_11 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_68 ( V_7 , V_65 ) ;
if ( V_11 )
return V_11 ;
return V_42 ;
}
static int F_69 ( struct V_27 * V_28 , void * V_29 )
{
const char * V_97 [] = V_98 ;
struct V_30 * V_31 = V_28 -> V_32 ;
int V_99 = F_16 ( V_31 ) -> V_76 ;
int V_100 = 0 ;
while ( V_99 != 0 ) {
if ( F_70 ( V_97 ) <= V_100 ) {
F_23 ( L_23 ,
F_36 ( V_31 , NULL , 0 ) ) ;
return - V_67 ;
}
if ( V_99 & 0x1 )
F_30 ( V_28 , L_24 , V_97 [ V_100 ] ) ;
V_99 >>= 1 ;
++ V_100 ;
}
F_71 ( V_28 , L_25 ) ;
return 0 ;
}
static T_1 F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_101 ) ;
}
static T_1 F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_65 ;
V_11 = F_22 ( V_41 , 10 , & V_65 ) ;
if ( V_11 )
return V_11 ;
if ( V_65 != 0 && V_65 != 1 )
return - V_44 ;
if ( V_65 == 1 && ! ( V_7 -> V_76 & V_102 ) )
return - V_103 ;
V_7 -> V_101 = V_65 ;
return V_42 ;
}
static int F_74 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_47 * V_48 = V_7 -> V_49 ;
long V_104 ;
int V_105 ;
V_104 = F_29 ( & V_48 -> V_106 ) ;
V_105 = ( V_104 * V_40 ) >> 20 ;
F_30 ( V_28 ,
L_26
L_27
L_28 ,
V_48 -> V_107 , V_104 , V_105 ) ;
return 0 ;
}
static T_1 F_75 ( struct V_57 * V_57 ,
const char T_5 * V_41 ,
T_4 V_42 , T_6 * V_58 )
{
struct V_30 * V_31 = ( (struct V_27 * ) V_57 -> V_59 ) -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
char V_66 [ 128 ] ;
int V_65 , V_11 ;
if ( ! V_42 )
return 0 ;
if ( V_42 >= sizeof( V_66 ) )
return - V_67 ;
if ( F_33 ( V_66 , V_41 , V_42 ) )
return - V_68 ;
V_66 [ V_42 ] = 0 ;
V_41 += F_34 ( V_66 , L_29 , & V_42 ) -
V_66 ;
V_11 = F_76 ( V_41 , V_42 , & V_65 ) ;
if ( V_11 < 0 )
return V_11 ;
F_18 ( & V_7 -> V_49 -> V_108 ) ;
V_7 -> V_49 -> V_107 = ! ! V_65 ;
F_19 ( & V_7 -> V_49 -> V_108 ) ;
return V_42 ;
}
static T_1 F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_109 * V_110 = & V_7 -> V_111 ;
return sprintf ( V_5 , L_30 , V_110 -> V_112 , V_110 -> V_113 ) ;
}
static T_1 F_78 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_41 , T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_109 * V_110 = & V_7 -> V_111 ;
return F_79 ( V_41 , V_42 , V_110 ,
F_36 ( V_7 -> V_12 , NULL , 0 ) ) ;
}
static int F_80 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_109 * V_110 = & V_7 -> V_111 ;
int V_114 ;
F_81 ( & V_110 -> V_115 ) ;
if ( ! F_82 ( & V_110 -> V_116 ) ) {
V_114 = F_83 ( V_28 -> V_5 + V_28 -> V_42 , V_28 -> V_117 - V_28 -> V_42 ,
& V_110 -> V_116 ) ;
V_28 -> V_42 += V_114 ;
F_71 ( V_28 , L_31 ) ;
} else {
F_71 ( V_28 , L_32 ) ;
}
F_84 ( & V_110 -> V_115 ) ;
return 0 ;
}
static T_1 F_85 ( struct V_57 * V_57 ,
const char T_5 * V_41 ,
T_4 V_42 , T_6 * V_58 )
{
struct V_27 * V_28 = V_57 -> V_59 ;
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_109 * V_110 = & V_7 -> V_111 ;
int V_11 ;
V_11 = F_86 ( V_41 , V_42 , V_110 ,
F_36 ( V_31 , NULL , 0 ) ) ;
if ( V_11 < 0 )
return V_11 ;
F_87 ( V_7 ) ;
return V_11 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
F_89 ( & V_7 -> V_118 ) ;
}
void F_90 ( struct V_6 * V_7 , int V_119 , int V_42 )
{
if ( ! V_7 -> V_85 )
return;
if ( V_7 -> V_81 == V_83 )
F_91 ( V_7 -> V_85 , V_119 , V_42 ) ;
else if ( V_7 -> V_81 == V_86 &&
V_7 -> V_82 == V_120 -> V_84 )
F_91 ( V_7 -> V_85 , V_119 , V_42 ) ;
else if ( V_7 -> V_81 == V_87 &&
V_7 -> V_82 == V_120 -> V_121 -> V_84 )
F_91 ( V_7 -> V_85 , V_119 , V_42 ) ;
else if ( V_7 -> V_81 == V_88 &&
V_7 -> V_82 ==
F_92 ( & V_122 , F_93 () ) )
F_91 ( V_7 -> V_85 , V_119 , V_42 ) ;
}
int F_94 ( struct V_123 * V_124 ,
struct V_30 * V_31 , char * V_125 , char * V_126 )
{
struct V_127 * V_128 = F_95 ( V_31 ) ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_129 * V_130 ;
struct V_123 * V_131 ;
char V_24 [ V_132 + 1 ] , * V_133 ;
int V_134 , V_135 , V_114 , V_11 ;
V_24 [ V_132 ] = '\0' ;
F_96 ( V_7 ) ;
F_96 ( V_126 ) ;
F_96 ( V_125 ) ;
V_114 = strlen ( V_128 -> V_136 -> V_137 ) ;
V_133 = strrchr ( V_128 -> V_136 -> V_137 , '-' ) ;
if ( V_133 && ( strcmp ( V_133 , L_33 ) == 0 ) )
V_114 -= 7 ;
snprintf ( V_24 , V_132 , L_34 , V_114 ,
V_128 -> V_136 -> V_137 , V_31 ) ;
V_131 = F_97 ( V_24 , V_124 , NULL , NULL ) ;
if ( F_98 ( V_131 ) ) {
V_134 = V_131 ? F_99 ( V_131 ) : - V_138 ;
V_7 -> V_139 = NULL ;
return V_134 ;
}
V_7 -> V_139 = V_131 ;
V_11 = F_100 ( V_7 -> V_139 , L_35 , 0444 ,
& V_140 , V_7 ) ;
if ( V_11 )
F_46 ( L_36 ) ;
V_11 = F_100 ( V_7 -> V_139 , L_37 , 0644 ,
& V_141 , V_7 ) ;
if ( V_11 )
F_46 ( L_38 ) ;
V_11 = F_100 ( V_7 -> V_139 ,
L_39 ,
0644 , & V_142 , V_7 ) ;
if ( V_11 )
F_46 ( L_40 ) ;
V_11 = F_100 ( V_7 -> V_139 , L_41 , 0644 ,
& V_143 , V_7 ) ;
if ( V_11 )
F_46 ( L_42 ) ;
V_7 -> V_85 = F_101 ( V_144 ,
V_145 ) ;
if ( ! V_7 -> V_85 ) {
V_134 = - V_138 ;
goto V_70;
}
for ( V_135 = 0 ; V_135 < V_144 ; V_135 ++ ) {
T_2 type = V_146 [ V_135 ] . type ;
void * V_133 = NULL ;
if ( type & V_147 )
V_133 = L_43 ;
else if ( type & V_148 )
V_133 = L_44 ;
else if ( type & V_149 )
V_133 = L_45 ;
F_102 ( V_7 -> V_85 ,
V_146 [ V_135 ] . V_150 ,
( type & V_151 ) ,
V_146 [ V_135 ] . V_152 , V_133 ) ;
}
V_134 = F_103 ( V_7 -> V_139 , L_46 ,
V_7 -> V_85 ) ;
if ( V_134 )
goto V_70;
V_7 -> V_153 = F_101 ( F_70 ( V_154 ) ,
V_145 ) ;
if ( ! V_7 -> V_153 ) {
V_134 = - V_138 ;
goto V_70;
}
for ( V_135 = 0 ; V_135 < F_70 ( V_154 ) ; V_135 ++ )
F_102 ( V_7 -> V_153 , V_135 , 0 ,
V_154 [ V_135 ] , L_45 ) ;
V_134 = F_103 ( V_7 -> V_139 , L_47 ,
V_7 -> V_153 ) ;
if ( V_134 )
goto V_70;
V_134 = F_104 ( V_7 -> V_139 ,
V_155 , V_31 ) ;
if ( V_134 )
goto V_70;
V_7 -> V_8 . V_156 = V_157 ;
F_105 ( & V_7 -> V_118 ) ;
V_134 = F_106 ( & V_7 -> V_8 , & V_158 , NULL ,
L_48 , V_24 ) ;
if ( V_134 )
goto V_70;
V_130 = F_107 ( V_126 ) ;
V_134 = F_108 ( & V_7 -> V_8 , & V_130 -> V_159 ,
V_130 -> V_160 -> V_161 ) ;
if ( V_134 )
goto V_70;
V_130 = F_107 ( V_125 ) ;
V_134 = F_108 ( & V_7 -> V_8 , & V_130 -> V_159 ,
V_130 -> V_160 -> V_161 ) ;
V_70:
if ( V_134 ) {
F_109 ( & V_7 -> V_139 ) ;
F_110 ( & V_7 -> V_153 ) ;
F_110 ( & V_7 -> V_85 ) ;
}
return V_134 ;
}
void F_111 ( struct V_6 * V_7 )
{
if ( V_7 -> V_139 ) {
F_109 ( & V_7 -> V_139 ) ;
F_112 ( & V_7 -> V_8 ) ;
F_113 ( & V_7 -> V_118 ) ;
F_110 ( & V_7 -> V_153 ) ;
F_110 ( & V_7 -> V_85 ) ;
}
}
static void F_114 ( struct V_162 * V_163 ,
struct V_27 * V_164 , int V_165 )
{
unsigned long V_166 = 0 , V_167 = 0 , V_168 , V_169 ;
unsigned long V_170 , V_171 , V_172 , V_173 ;
char * V_174 = L_49 ;
int V_100 , V_175 = 10 ;
struct V_176 * V_177 = & V_163 -> V_178 [ V_165 ] ;
V_168 = 0 ;
V_169 = 0 ;
V_170 = 0 ;
for ( V_100 = 0 ; V_100 < V_179 ; V_100 ++ ) {
V_166 += V_177 -> V_180 . V_181 [ V_100 ] ;
V_167 += V_177 -> V_182 . V_181 [ V_100 ] ;
}
for ( V_100 = 0 ; V_100 < V_179 ; V_100 ++ ) {
V_172 = V_177 -> V_180 . V_181 [ V_100 ] ;
V_173 = V_177 -> V_182 . V_181 [ V_100 ] ;
V_168 += V_172 ;
V_169 += V_173 ;
V_171 = 1 << ( V_100 + V_183 - V_175 ) ;
F_30 ( V_164 , L_50 ,
V_170 , * V_174 , V_171 , * V_174 ,
( V_100 == V_179 - 1 ) ? '+' : ' ' ,
V_172 , F_115 ( V_172 , V_166 ) , F_115 ( V_168 , V_166 ) ,
V_173 , F_115 ( V_173 , V_167 ) , F_115 ( V_169 , V_167 ) ) ;
V_170 = V_171 ;
if ( V_170 == 1 << 10 ) {
V_170 = 1 ;
V_175 += 10 ;
V_174 ++ ;
}
if ( V_168 == V_166 && V_169 == V_167 )
break;
}
}
static int F_116 ( struct V_27 * V_164 , void * V_29 )
{
struct V_184 V_185 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_162 * V_163 = & V_7 -> V_162 ;
int V_186 ;
F_117 ( & V_185 ) ;
if ( ! V_7 -> V_187 ) {
F_30 ( V_164 , L_51
L_52 ) ;
return 0 ;
}
F_30 ( V_164 , L_53 ,
( V_188 ) V_185 . V_189 , ( unsigned long ) V_185 . V_190 ) ;
F_30 ( V_164 , L_54 , L_55 , L_56 , L_57 ) ;
F_30 ( V_164 , L_58 ,
L_59 , L_60 , L_61 , L_62 ,
L_60 , L_61 , L_62 ) ;
F_18 ( & V_7 -> V_191 ) ;
for ( V_186 = 0 ; V_186 < V_192 ; V_186 ++ ) {
if ( V_163 -> V_178 [ V_186 ] . V_84 != 0 ) {
F_30 ( V_164 , L_63 ,
V_163 -> V_178 [ V_186 ] . V_84 ) ;
F_114 ( V_163 , V_164 , V_186 ) ;
}
}
F_19 ( & V_7 -> V_191 ) ;
return 0 ;
}
static T_1 F_118 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_114 ,
T_6 * V_58 )
{
struct V_27 * V_164 = V_57 -> V_59 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_162 * V_163 = & V_7 -> V_162 ;
int V_100 ;
int V_193 = 1 , V_11 = 0 ;
if ( V_114 == 0 )
return - V_67 ;
V_11 = F_76 ( V_5 , V_114 , & V_193 ) ;
if ( V_11 < 0 && V_114 < 16 ) {
char V_66 [ 16 ] ;
if ( F_33 ( V_66 , V_5 , V_114 ) )
return - V_68 ;
V_66 [ V_114 ] = 0 ;
if ( V_66 [ V_114 - 1 ] == '\n' )
V_66 [ V_114 - 1 ] = 0 ;
if ( strcmp ( V_66 , L_64 ) == 0 ||
strcmp ( V_66 , L_65 ) == 0 )
V_193 = 0 ;
}
if ( V_193 == 0 )
V_7 -> V_187 = 0 ;
else
V_7 -> V_187 = 1 ;
F_18 ( & V_7 -> V_191 ) ;
for ( V_100 = 0 ; V_100 < V_192 ; V_100 ++ ) {
V_163 -> V_178 [ V_100 ] . V_84 = 0 ;
F_119 ( & V_163 -> V_178 [ V_100 ] . V_180 ) ;
F_119 ( & V_163 -> V_178 [ V_100 ] . V_182 ) ;
}
F_19 ( & V_7 -> V_191 ) ;
return V_114 ;
}
static int F_120 ( struct V_27 * V_164 , void * V_29 )
{
struct V_184 V_185 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_162 * V_163 = & V_7 -> V_162 ;
F_117 ( & V_185 ) ;
if ( ! V_7 -> V_187 ) {
F_30 ( V_164 , L_51
L_52 ) ;
return 0 ;
}
F_30 ( V_164 , L_53 ,
( T_7 ) V_185 . V_189 , ( unsigned long ) V_185 . V_190 ) ;
F_30 ( V_164 , L_54 , L_55 , L_56 , L_57 ) ;
F_30 ( V_164 , L_58 ,
L_59 , L_60 , L_61 , L_62 ,
L_60 , L_61 , L_62 ) ;
F_18 ( & V_7 -> V_36 ) ;
F_114 ( V_163 , V_164 , V_192 ) ;
F_19 ( & V_7 -> V_36 ) ;
return 0 ;
}
static T_1 F_121 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_114 , T_6 * V_58 )
{
struct V_27 * V_164 = V_57 -> V_59 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_162 * V_163 = & V_7 -> V_162 ;
int V_100 ;
int V_193 = 1 , V_11 = 0 ;
if ( V_114 == 0 )
return - V_67 ;
V_11 = F_76 ( V_5 , V_114 , & V_193 ) ;
if ( V_11 < 0 && V_114 < 16 ) {
char V_66 [ 16 ] ;
if ( F_33 ( V_66 , V_5 , V_114 ) )
return - V_68 ;
V_66 [ V_114 ] = 0 ;
if ( V_66 [ V_114 - 1 ] == '\n' )
V_66 [ V_114 - 1 ] = 0 ;
if ( strcmp ( V_66 , L_64 ) == 0 ||
strcmp ( V_66 , L_65 ) == 0 )
V_193 = 0 ;
}
if ( V_193 == 0 )
V_7 -> V_187 = 0 ;
else
V_7 -> V_187 = 1 ;
F_18 ( & V_7 -> V_191 ) ;
for ( V_100 = 0 ; V_100 <= V_192 ; V_100 ++ ) {
V_163 -> V_178 [ V_100 ] . V_84 = 0 ;
F_119 ( & V_163 -> V_178 [ V_100 ] . V_180 ) ;
F_119 ( & V_163 -> V_178 [ V_100 ] . V_182 ) ;
}
F_19 ( & V_7 -> V_191 ) ;
return V_114 ;
}
void F_122 ( struct V_6 * V_7 , T_8 V_84 ,
struct V_194 * V_57 , T_6 V_195 ,
T_4 V_42 , int V_196 )
{
int V_100 , V_197 = - 1 ;
struct V_198 * V_199 ;
struct V_198 * V_200 ;
int * V_201 = & V_7 -> V_202 ;
int * V_203 = & V_7 -> V_204 ;
struct V_162 * V_163 = & V_7 -> V_162 ;
if ( ! V_7 -> V_187 )
return;
V_199 = V_7 -> V_198 ;
V_200 = V_7 -> V_205 ;
F_18 ( & V_7 -> V_191 ) ;
for ( V_100 = 0 ; V_100 < V_192 ; V_100 ++ ) {
if ( V_163 -> V_178 [ V_100 ] . V_84 == V_84 ) {
V_197 = V_100 ;
break;
}
}
if ( V_197 == - 1 ) {
V_7 -> V_206 =
( V_7 -> V_206 + 1 ) % V_192 ;
V_197 = V_7 -> V_206 ;
V_163 -> V_178 [ V_197 ] . V_84 = V_84 ;
F_119 ( & V_163 -> V_178 [ V_197 ] . V_180 ) ;
F_119 ( & V_163 -> V_178 [ V_197 ] . V_182 ) ;
}
for ( V_100 = 0 ; ( V_42 >= ( 1 << V_183 << V_100 ) ) &&
( V_100 < ( V_179 - 1 ) ) ; V_100 ++ )
;
if ( V_196 == 0 ) {
V_163 -> V_178 [ V_197 ] . V_180 . V_181 [ V_100 ] ++ ;
V_163 -> V_178 [ V_192 ] . V_180 . V_181 [ V_100 ] ++ ;
} else {
V_163 -> V_178 [ V_197 ] . V_182 . V_181 [ V_100 ] ++ ;
V_163 -> V_178 [ V_192 ] . V_182 . V_181 [ V_100 ] ++ ;
}
F_19 ( & V_7 -> V_191 ) ;
F_18 ( & V_7 -> V_207 ) ;
for ( V_100 = 0 ; V_100 < V_192 ; V_100 ++ ) {
if ( V_199 [ V_100 ] . V_208 == V_84 ) {
if ( V_199 [ V_100 ] . V_209 != V_57 ) {
V_199 [ V_100 ] . V_210 = V_195 ;
V_199 [ V_100 ] . V_211 = V_195 + V_42 ;
V_199 [ V_100 ] . V_212 = V_42 ;
V_199 [ V_100 ] . V_213 = V_42 ;
V_199 [ V_100 ] . V_214 = 0 ;
V_199 [ V_100 ] . V_209 = V_57 ;
F_19 ( & V_7 -> V_207 ) ;
return;
}
if ( V_199 [ V_100 ] . V_211 != V_195 ) {
* V_201 =
( * V_201 + 1 ) % V_215 ;
V_200 [ * V_201 ] . V_216 = V_199 [ V_100 ] . V_216 ;
V_200 [ * V_201 ] . V_208 = V_84 ;
V_200 [ * V_201 ] . V_210 =
V_199 [ V_100 ] . V_210 ;
V_200 [ * V_201 ] . V_217 =
V_199 [ V_100 ] . V_211 ;
V_200 [ * V_201 ] . V_212 =
V_199 [ V_100 ] . V_212 ;
V_200 [ * V_201 ] . V_213 =
V_199 [ V_100 ] . V_213 ;
V_200 [ * V_201 ] . V_214 =
V_199 [ V_100 ] . V_214 ;
V_199 [ V_100 ] . V_216 = V_196 ;
V_199 [ V_100 ] . V_210 = V_195 ;
V_199 [ V_100 ] . V_212 = V_42 ;
V_199 [ V_100 ] . V_213 = V_42 ;
V_199 [ V_100 ] . V_214 = V_195 -
V_199 [ V_100 ] . V_211 ;
}
if ( V_199 [ V_100 ] . V_212 > V_42 )
V_199 [ V_100 ] . V_212 = V_42 ;
if ( V_199 [ V_100 ] . V_213 < V_42 )
V_199 [ V_100 ] . V_213 = V_42 ;
V_199 [ V_100 ] . V_211 = V_195 + V_42 ;
F_19 ( & V_7 -> V_207 ) ;
return;
}
}
* V_203 = ( * V_203 + 1 ) % V_192 ;
V_199 [ * V_203 ] . V_208 = V_84 ;
V_199 [ * V_203 ] . V_216 = V_196 ;
V_199 [ * V_203 ] . V_210 = V_195 ;
V_199 [ * V_203 ] . V_211 = V_195 + V_42 ;
V_199 [ * V_203 ] . V_212 = V_42 ;
V_199 [ * V_203 ] . V_213 = V_42 ;
V_199 [ * V_203 ] . V_214 = 0 ;
V_199 [ * V_203 ] . V_209 = V_57 ;
F_19 ( & V_7 -> V_207 ) ;
}
static int F_123 ( struct V_27 * V_164 , void * V_29 )
{
struct V_184 V_185 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_198 * V_200 = V_7 -> V_205 ;
struct V_198 * V_199 = V_7 -> V_198 ;
int V_100 ;
F_117 ( & V_185 ) ;
if ( ! V_7 -> V_187 ) {
F_30 ( V_164 , L_51
L_52 ) ;
return 0 ;
}
F_18 ( & V_7 -> V_207 ) ;
F_30 ( V_164 , L_53 ,
( V_188 ) V_185 . V_189 , ( unsigned long ) V_185 . V_190 ) ;
F_30 ( V_164 , L_66 ,
L_67 , L_68 , L_69 , L_70 ,
L_71 , L_72 , L_73 ) ;
for ( V_100 = 0 ; V_100 < V_215 ; V_100 ++ ) {
if ( V_200 [ V_100 ] . V_208 != 0 )
F_30 ( V_164 ,
L_74 ,
V_200 [ V_100 ] . V_216 == V_218 ? 'R' : 'W' ,
V_200 [ V_100 ] . V_208 ,
V_200 [ V_100 ] . V_210 ,
V_200 [ V_100 ] . V_217 ,
( unsigned long ) V_200 [ V_100 ] . V_212 ,
( unsigned long ) V_200 [ V_100 ] . V_213 ,
V_200 [ V_100 ] . V_214 ) ;
}
for ( V_100 = 0 ; V_100 < V_192 ; V_100 ++ ) {
if ( V_199 [ V_100 ] . V_208 != 0 )
F_30 ( V_164 ,
L_74 ,
V_199 [ V_100 ] . V_216 == V_218 ? 'R' : 'W' ,
V_199 [ V_100 ] . V_208 ,
V_199 [ V_100 ] . V_210 ,
V_199 [ V_100 ] . V_211 ,
( unsigned long ) V_199 [ V_100 ] . V_212 ,
( unsigned long ) V_199 [ V_100 ] . V_213 ,
V_199 [ V_100 ] . V_214 ) ;
}
F_19 ( & V_7 -> V_207 ) ;
return 0 ;
}
static T_1 F_124 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_114 , T_6 * V_58 )
{
struct V_27 * V_164 = V_57 -> V_59 ;
struct V_6 * V_7 = V_164 -> V_32 ;
struct V_198 * V_219 = V_7 -> V_198 ;
struct V_198 * V_220 = V_7 -> V_205 ;
int V_193 = 1 , V_11 = 0 ;
if ( V_114 == 0 )
return - V_67 ;
V_11 = F_76 ( V_5 , V_114 , & V_193 ) ;
if ( V_11 < 0 && V_114 < 16 ) {
char V_66 [ 16 ] ;
if ( F_33 ( V_66 , V_5 , V_114 ) )
return - V_68 ;
V_66 [ V_114 ] = 0 ;
if ( V_66 [ V_114 - 1 ] == '\n' )
V_66 [ V_114 - 1 ] = 0 ;
if ( strcmp ( V_66 , L_64 ) == 0 ||
strcmp ( V_66 , L_65 ) == 0 )
V_193 = 0 ;
}
if ( V_193 == 0 )
V_7 -> V_187 = 0 ;
else
V_7 -> V_187 = 1 ;
F_18 ( & V_7 -> V_207 ) ;
V_7 -> V_204 = 0 ;
V_7 -> V_202 = 0 ;
memset ( V_219 , 0 , sizeof( struct V_198 ) *
V_192 ) ;
memset ( V_220 , 0 , sizeof( struct V_198 ) *
V_215 ) ;
F_19 ( & V_7 -> V_207 ) ;
return V_114 ;
}
void F_125 ( struct V_221 * V_222 )
{
V_222 -> V_223 = V_155 ;
}
