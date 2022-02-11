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
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_3 ,
V_7 -> V_23 & V_24 ? L_4 : L_5 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_6 , V_7 -> V_12 -> V_25 -> V_26 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_6 , V_7 -> V_27 . V_28 ) ;
}
static int F_13 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
return F_14 ( F_15 ( F_16 ( V_33 ) -> V_35 ) , V_30 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_36 ;
int V_37 ;
F_18 ( & V_7 -> V_38 ) ;
V_36 = V_7 -> V_39 . V_40 ;
F_19 ( & V_7 -> V_38 ) ;
V_37 = 1 << ( 20 - V_41 ) ;
return F_20 ( V_5 , V_42 , V_36 , V_37 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_36 ;
V_11 = F_22 ( V_43 , 10 , & V_36 ) ;
if ( V_11 )
return V_11 ;
V_36 *= 1 << ( 20 - V_41 ) ;
if ( V_36 > V_45 / 2 ) {
F_23 ( L_7 ,
V_45 >> ( 20 - V_41 + 1 ) ) ;
return - V_46 ;
}
F_18 ( & V_7 -> V_38 ) ;
V_7 -> V_39 . V_40 = V_36 ;
F_19 ( & V_7 -> V_38 ) ;
return V_44 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_36 ;
int V_37 ;
F_18 ( & V_7 -> V_38 ) ;
V_36 = V_7 -> V_39 . V_47 ;
F_19 ( & V_7 -> V_38 ) ;
V_37 = 1 << ( 20 - V_41 ) ;
return F_20 ( V_5 , V_42 , V_36 , V_37 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_36 ;
V_11 = F_22 ( V_43 , 10 , & V_36 ) ;
if ( V_11 )
return V_11 ;
if ( V_36 > V_7 -> V_39 . V_40 ) {
F_23 ( L_8 ,
V_7 -> V_39 . V_40 ) ;
return - V_46 ;
}
F_18 ( & V_7 -> V_38 ) ;
V_7 -> V_39 . V_47 = V_36 ;
F_19 ( & V_7 -> V_38 ) ;
return V_44 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
long V_36 ;
int V_37 ;
F_18 ( & V_7 -> V_38 ) ;
V_36 = V_7 -> V_39 . V_48 ;
F_19 ( & V_7 -> V_38 ) ;
V_37 = 1 << ( 20 - V_41 ) ;
return F_20 ( V_5 , V_42 , V_36 , V_37 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_36 ;
V_11 = F_22 ( V_43 , 10 , & V_36 ) ;
if ( V_11 )
return V_11 ;
if ( V_36 > V_7 -> V_39 . V_47 ) {
F_23 ( L_9 ,
V_7 -> V_39 . V_47 >> ( 20 - V_41 ) ) ;
return - V_46 ;
}
F_18 ( & V_7 -> V_38 ) ;
V_7 -> V_39 . V_48 = V_36 ;
F_19 ( & V_7 -> V_38 ) ;
return V_44 ;
}
static int F_28 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
struct V_49 * V_50 = & V_7 -> V_51 ;
int V_52 = 20 - V_41 ;
int V_53 ;
int V_54 ;
V_53 = V_50 -> V_55 >> V_52 ;
V_54 = F_29 ( & V_50 -> V_56 ) >> V_52 ;
F_30 ( V_30 ,
L_10
L_11
L_12
L_13
L_14 ,
F_29 ( & V_50 -> V_57 ) ,
V_53 ,
V_53 - V_54 ,
V_54 ,
V_50 -> V_58 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_59 * V_59 ,
const char T_5 * V_43 ,
T_4 V_44 , T_6 * V_60 )
{
struct V_32 * V_33 = ( (struct V_29 * ) V_59 -> V_61 ) -> V_34 ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
struct V_49 * V_50 = & V_7 -> V_51 ;
struct V_62 * V_63 ;
int V_64 ;
int V_37 , V_11 , V_36 ;
int V_65 = 0 ;
int V_66 = 0 ;
char V_67 [ 128 ] ;
if ( V_44 >= sizeof( V_67 ) )
return - V_68 ;
if ( F_32 ( V_67 , V_43 , V_44 ) )
return - V_69 ;
V_67 [ V_44 ] = 0 ;
V_37 = 1 << ( 20 - V_41 ) ;
V_43 += F_33 ( V_67 , L_15 , & V_44 ) -
V_67 ;
V_11 = F_34 ( V_43 , V_44 , & V_36 , V_37 ) ;
if ( V_11 )
return V_11 ;
if ( V_36 < 0 || V_36 > V_45 ) {
F_23 ( L_16 ,
F_35 ( V_33 , NULL , 0 ) ,
V_45 >> ( 20 - V_41 ) ) ;
return - V_46 ;
}
F_18 ( & V_7 -> V_38 ) ;
V_65 = V_36 - V_50 -> V_55 ;
F_19 ( & V_7 -> V_38 ) ;
if ( V_65 >= 0 ) {
F_36 ( V_65 , & V_50 -> V_56 ) ;
V_11 = 0 ;
goto V_70;
}
V_63 = F_37 ( & V_64 ) ;
if ( F_38 ( V_63 ) )
return 0 ;
V_65 = - V_65 ;
while ( V_65 > 0 ) {
int V_71 ;
do {
int V_72 , V_73 ;
V_72 = F_29 ( & V_50 -> V_56 ) ;
if ( V_72 == 0 )
break;
V_73 = V_72 > V_65 ? V_72 - V_65 : 0 ;
V_11 = F_39 ( & V_50 -> V_56 , V_72 , V_73 ) ;
if ( F_40 ( V_72 == V_11 ) ) {
V_65 -= V_72 - V_73 ;
V_66 += V_72 - V_73 ;
break;
}
} while ( 1 );
if ( V_65 <= 0 )
break;
if ( ! V_7 -> V_74 ) {
V_11 = 0 ;
goto V_70;
}
V_71 = V_65 << 1 ;
V_11 = F_41 ( V_63 , V_7 -> V_74 ,
sizeof( V_75 ) ,
V_75 ,
sizeof( V_71 ) , & V_71 , NULL ) ;
if ( V_11 < 0 )
break;
}
F_42 ( V_63 , & V_64 ) ;
V_70:
if ( V_11 >= 0 ) {
F_18 ( & V_7 -> V_38 ) ;
V_50 -> V_55 = V_36 ;
F_19 ( & V_7 -> V_38 ) ;
V_11 = V_44 ;
} else {
F_36 ( V_66 , & V_50 -> V_56 ) ;
}
return V_11 ;
}
static T_1 F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ( V_7 -> V_23 & V_76 ) ? 1 : 0 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_77 ;
if ( ! V_7 -> V_74 )
return - V_78 ;
V_11 = F_22 ( V_43 , 10 , & V_77 ) ;
if ( V_11 )
return V_11 ;
if ( V_77 )
V_7 -> V_23 |= V_76 ;
else
V_7 -> V_23 &= ~ V_76 ;
V_11 = F_41 ( NULL , V_7 -> V_74 , sizeof( V_79 ) ,
V_79 , sizeof( V_77 ) , & V_77 , NULL ) ;
if ( V_11 )
F_45 ( L_17 , V_11 ) ;
return V_44 ;
}
static T_1 F_46 ( struct V_1 * V_2 , char * V_5 ,
enum V_80 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
if ( V_7 -> V_81 == type )
return sprintf ( V_5 , L_18 , V_7 -> V_82 ) ;
else if ( V_7 -> V_81 == V_83 )
return sprintf ( V_5 , L_19 ) ;
else
return sprintf ( V_5 , L_20 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 , const char * V_43 ,
T_4 V_44 ,
enum V_80 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_84 ;
V_11 = F_22 ( V_43 , 10 , & V_84 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_82 = V_84 ;
if ( V_84 == 0 )
V_7 -> V_81 = V_83 ;
else
V_7 -> V_81 = type ;
F_48 ( V_7 -> V_85 ) ;
return V_44 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_86 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_47 ( V_2 , V_43 , V_44 , V_86 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_87 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_47 ( V_2 , V_43 , V_44 , V_87 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_88 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_47 ( V_2 , V_43 , V_44 , V_88 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_89 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_77 ;
V_11 = F_22 ( V_43 , 10 , & V_77 ) ;
if ( V_11 )
return V_11 ;
if ( V_77 <= V_90 )
V_7 -> V_89 = V_77 ;
else
F_23 ( L_21 ,
V_77 , V_90 ) ;
return V_44 ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_23 & V_91 ? 1 : 0 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_77 ;
V_11 = F_22 ( V_43 , 10 , & V_77 ) ;
if ( V_11 )
return V_11 ;
if ( V_77 )
V_7 -> V_23 |= V_91 ;
else
V_7 -> V_23 &= ~ V_91 ;
return V_44 ;
}
static int F_59 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
F_30 ( V_30 ,
L_22
L_23
L_24 ,
F_29 ( & V_7 -> V_92 ) ,
F_29 ( & V_7 -> V_93 ) ,
F_29 ( & V_7 -> V_94 ) ) ;
return 0 ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_23 & V_95 ? 1 : 0 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_77 ;
V_11 = F_22 ( V_43 , 10 , & V_77 ) ;
if ( V_11 )
return V_11 ;
if ( V_77 )
V_7 -> V_23 |= V_95 ;
else
V_7 -> V_23 &= ~ V_95 ;
return V_44 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_96 ;
int V_11 ;
V_11 = F_63 ( V_7 , & V_96 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_96 ) ;
}
static T_1 F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_96 ;
int V_11 ;
V_11 = F_65 ( V_7 , & V_96 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_96 ) ;
}
static int F_66 ( struct V_29 * V_30 , void * V_31 )
{
const char * V_97 [] = V_98 ;
struct V_32 * V_33 = V_30 -> V_34 ;
int V_99 = F_16 ( V_33 ) -> V_23 ;
int V_100 = 0 ;
while ( V_99 != 0 ) {
if ( F_67 ( V_97 ) <= V_100 ) {
F_23 ( L_25 ,
F_35 ( V_33 , NULL , 0 ) ) ;
return - V_68 ;
}
if ( V_99 & 0x1 )
F_30 ( V_30 , L_26 , V_97 [ V_100 ] ) ;
V_99 >>= 1 ;
++ V_100 ;
}
F_30 ( V_30 , L_27 ) ;
return 0 ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_101 ) ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_77 ;
V_11 = F_22 ( V_43 , 10 , & V_77 ) ;
if ( V_11 )
return V_11 ;
if ( V_77 != 0 && V_77 != 1 )
return - V_46 ;
if ( V_77 == 1 && ! ( V_7 -> V_23 & V_102 ) )
return - V_103 ;
V_7 -> V_101 = V_77 ;
return V_44 ;
}
static T_1 F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_49 * V_50 = & V_7 -> V_51 ;
int V_104 , V_105 ;
V_104 = F_29 ( & V_50 -> V_106 ) ;
V_105 = ( V_104 * V_42 ) >> 20 ;
return sprintf ( V_5 , L_28
L_29 , V_104 , V_105 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
F_72 ( & V_7 -> V_107 ) ;
}
void F_73 ( struct V_6 * V_7 , int V_108 , int V_44 )
{
if ( ! V_7 -> V_85 )
return;
if ( V_7 -> V_81 == V_83 )
F_74 ( V_7 -> V_85 , V_108 , V_44 ) ;
else if ( V_7 -> V_81 == V_86 &&
V_7 -> V_82 == V_109 -> V_84 )
F_74 ( V_7 -> V_85 , V_108 , V_44 ) ;
else if ( V_7 -> V_81 == V_87 &&
V_7 -> V_82 == V_109 -> V_110 -> V_84 )
F_74 ( V_7 -> V_85 , V_108 , V_44 ) ;
else if ( V_7 -> V_81 == V_88 &&
V_7 -> V_82 ==
F_75 ( & V_111 , F_76 () ) )
F_74 ( V_7 -> V_85 , V_108 , V_44 ) ;
}
int F_77 ( struct V_112 * V_113 ,
struct V_32 * V_33 , char * V_114 , char * V_115 )
{
struct V_116 * V_117 = F_78 ( V_33 ) ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
struct V_118 * V_119 ;
struct V_112 * V_120 ;
char V_26 [ V_121 + 1 ] , * V_122 ;
int V_123 , V_124 , V_125 , V_11 ;
V_26 [ V_121 ] = '\0' ;
F_79 ( V_7 ) ;
F_79 ( V_115 ) ;
F_79 ( V_114 ) ;
V_125 = strlen ( V_117 -> V_126 -> V_127 ) ;
V_122 = strrchr ( V_117 -> V_126 -> V_127 , '-' ) ;
if ( V_122 && ( strcmp ( V_122 , L_30 ) == 0 ) )
V_125 -= 7 ;
snprintf ( V_26 , V_121 , L_31 , V_125 ,
V_117 -> V_126 -> V_127 , V_33 ) ;
V_120 = F_80 ( V_26 , V_113 , NULL , NULL ) ;
if ( F_81 ( V_120 ) ) {
V_123 = V_120 ? F_82 ( V_120 ) : - V_128 ;
V_7 -> V_129 = NULL ;
return V_123 ;
}
V_7 -> V_129 = V_120 ;
V_11 = F_83 ( V_7 -> V_129 , L_32 , 0444 ,
& V_130 , V_7 ) ;
if ( V_11 )
F_45 ( L_33 ) ;
V_11 = F_83 ( V_7 -> V_129 , L_34 , 0644 ,
& V_131 , V_7 ) ;
if ( V_11 )
F_45 ( L_35 ) ;
V_11 = F_83 ( V_7 -> V_129 ,
L_36 ,
0644 , & V_132 , V_7 ) ;
if ( V_11 )
F_45 ( L_37 ) ;
V_11 = F_83 ( V_7 -> V_129 , L_38 , 0644 ,
& V_133 , V_7 ) ;
if ( V_11 )
F_45 ( L_39 ) ;
V_7 -> V_85 = F_84 ( V_134 ,
V_135 ) ;
if ( ! V_7 -> V_85 ) {
V_123 = - V_128 ;
goto V_70;
}
for ( V_124 = 0 ; V_124 < V_134 ; V_124 ++ ) {
T_2 type = V_136 [ V_124 ] . type ;
void * V_122 = NULL ;
if ( type & V_137 )
V_122 = L_40 ;
else if ( type & V_138 )
V_122 = L_41 ;
else if ( type & V_139 )
V_122 = L_42 ;
F_85 ( V_7 -> V_85 ,
V_136 [ V_124 ] . V_140 ,
( type & V_141 ) ,
V_136 [ V_124 ] . V_142 , V_122 ) ;
}
V_123 = F_86 ( V_7 -> V_129 , L_43 ,
V_7 -> V_85 ) ;
if ( V_123 )
goto V_70;
V_7 -> V_143 = F_84 ( F_67 ( V_144 ) ,
V_135 ) ;
if ( ! V_7 -> V_143 ) {
V_123 = - V_128 ;
goto V_70;
}
for ( V_124 = 0 ; V_124 < F_67 ( V_144 ) ; V_124 ++ )
F_85 ( V_7 -> V_143 , V_124 , 0 ,
V_144 [ V_124 ] , L_42 ) ;
V_123 = F_86 ( V_7 -> V_129 , L_44 ,
V_7 -> V_143 ) ;
if ( V_123 )
goto V_70;
V_123 = F_87 ( V_7 -> V_129 ,
V_145 , V_33 ) ;
if ( V_123 )
goto V_70;
V_7 -> V_8 . V_146 = V_147 ;
F_88 ( & V_7 -> V_107 ) ;
V_123 = F_89 ( & V_7 -> V_8 , & V_148 , NULL ,
L_45 , V_26 ) ;
if ( V_123 )
goto V_70;
V_119 = F_90 ( V_115 ) ;
V_123 = F_91 ( & V_7 -> V_8 , & V_119 -> V_149 ,
V_119 -> V_150 -> V_151 ) ;
if ( V_123 )
goto V_70;
V_119 = F_90 ( V_114 ) ;
V_123 = F_91 ( & V_7 -> V_8 , & V_119 -> V_149 ,
V_119 -> V_150 -> V_151 ) ;
V_70:
if ( V_123 ) {
F_92 ( & V_7 -> V_129 ) ;
F_93 ( & V_7 -> V_143 ) ;
F_93 ( & V_7 -> V_85 ) ;
}
return V_123 ;
}
void F_94 ( struct V_6 * V_7 )
{
if ( V_7 -> V_129 ) {
F_92 ( & V_7 -> V_129 ) ;
F_95 ( & V_7 -> V_8 ) ;
F_96 ( & V_7 -> V_107 ) ;
F_93 ( & V_7 -> V_143 ) ;
F_93 ( & V_7 -> V_85 ) ;
}
}
static void F_97 ( struct V_152 * V_153 ,
struct V_29 * V_154 , int V_155 )
{
unsigned long V_156 = 0 , V_157 = 0 , V_158 , V_159 ;
unsigned long V_160 , V_161 , V_162 , V_163 ;
char * V_164 = L_46 ;
int V_100 , V_165 = 10 ;
struct V_166 * V_167 = & V_153 -> V_168 [ V_155 ] ;
V_158 = 0 ;
V_159 = 0 ;
V_160 = 0 ;
for ( V_100 = 0 ; V_100 < V_169 ; V_100 ++ ) {
V_156 += V_167 -> V_170 . V_171 [ V_100 ] ;
V_157 += V_167 -> V_172 . V_171 [ V_100 ] ;
}
for ( V_100 = 0 ; V_100 < V_169 ; V_100 ++ ) {
V_162 = V_167 -> V_170 . V_171 [ V_100 ] ;
V_163 = V_167 -> V_172 . V_171 [ V_100 ] ;
V_158 += V_162 ;
V_159 += V_163 ;
V_161 = 1 << ( V_100 + V_173 - V_165 ) ;
F_30 ( V_154 , L_47 ,
V_160 , * V_164 , V_161 , * V_164 ,
( V_100 == V_169 - 1 ) ? '+' : ' ' ,
V_162 , F_98 ( V_162 , V_156 ) , F_98 ( V_158 , V_156 ) ,
V_163 , F_98 ( V_163 , V_157 ) , F_98 ( V_159 , V_157 ) ) ;
V_160 = V_161 ;
if ( V_160 == 1 << 10 ) {
V_160 = 1 ;
V_165 += 10 ;
V_164 ++ ;
}
if ( V_158 == V_156 && V_159 == V_157 )
break;
}
}
static int F_99 ( struct V_29 * V_154 , void * V_31 )
{
struct V_174 V_175 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_152 * V_153 = & V_7 -> V_152 ;
int V_176 ;
F_100 ( & V_175 ) ;
if ( ! V_7 -> V_177 ) {
F_30 ( V_154 , L_48
L_49 ) ;
return 0 ;
}
F_30 ( V_154 , L_50 ,
( V_178 ) V_175 . V_179 , ( unsigned long ) V_175 . V_180 ) ;
F_30 ( V_154 , L_51 , L_52 , L_53 , L_54 ) ;
F_30 ( V_154 , L_55 ,
L_56 , L_57 , L_58 , L_59 ,
L_57 , L_58 , L_59 ) ;
F_18 ( & V_7 -> V_181 ) ;
for ( V_176 = 0 ; V_176 < V_182 ; V_176 ++ ) {
if ( V_153 -> V_168 [ V_176 ] . V_84 != 0 ) {
F_30 ( V_154 , L_60 ,
V_153 -> V_168 [ V_176 ] . V_84 ) ;
F_97 ( V_153 , V_154 , V_176 ) ;
}
}
F_19 ( & V_7 -> V_181 ) ;
return 0 ;
}
static T_1 F_101 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_125 ,
T_6 * V_60 )
{
struct V_29 * V_154 = V_59 -> V_61 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_152 * V_153 = & V_7 -> V_152 ;
int V_100 ;
int V_183 = 1 , V_11 = 0 ;
if ( V_125 == 0 )
return - V_68 ;
V_11 = F_102 ( V_5 , V_125 , & V_183 ) ;
if ( V_11 < 0 && V_125 < 16 ) {
char V_67 [ 16 ] ;
if ( F_32 ( V_67 , V_5 , V_125 ) )
return - V_69 ;
V_67 [ V_125 ] = 0 ;
if ( V_67 [ V_125 - 1 ] == '\n' )
V_67 [ V_125 - 1 ] = 0 ;
if ( strcmp ( V_67 , L_61 ) == 0 ||
strcmp ( V_67 , L_62 ) == 0 )
V_183 = 0 ;
}
if ( V_183 == 0 )
V_7 -> V_177 = 0 ;
else
V_7 -> V_177 = 1 ;
F_18 ( & V_7 -> V_181 ) ;
for ( V_100 = 0 ; V_100 < V_182 ; V_100 ++ ) {
V_153 -> V_168 [ V_100 ] . V_84 = 0 ;
F_103 ( & V_153 -> V_168 [ V_100 ] . V_170 ) ;
F_103 ( & V_153 -> V_168 [ V_100 ] . V_172 ) ;
}
F_19 ( & V_7 -> V_181 ) ;
return V_125 ;
}
static int F_104 ( struct V_29 * V_154 , void * V_31 )
{
struct V_174 V_175 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_152 * V_153 = & V_7 -> V_152 ;
F_100 ( & V_175 ) ;
if ( ! V_7 -> V_177 ) {
F_30 ( V_154 , L_48
L_49 ) ;
return 0 ;
}
F_30 ( V_154 , L_50 ,
( V_184 ) V_175 . V_179 , ( unsigned long ) V_175 . V_180 ) ;
F_30 ( V_154 , L_51 , L_52 , L_53 , L_54 ) ;
F_30 ( V_154 , L_55 ,
L_56 , L_57 , L_58 , L_59 ,
L_57 , L_58 , L_59 ) ;
F_18 ( & V_7 -> V_38 ) ;
F_97 ( V_153 , V_154 , V_182 ) ;
F_19 ( & V_7 -> V_38 ) ;
return 0 ;
}
static T_1 F_105 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_125 , T_6 * V_60 )
{
struct V_29 * V_154 = V_59 -> V_61 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_152 * V_153 = & V_7 -> V_152 ;
int V_100 ;
int V_183 = 1 , V_11 = 0 ;
if ( V_125 == 0 )
return - V_68 ;
V_11 = F_102 ( V_5 , V_125 , & V_183 ) ;
if ( V_11 < 0 && V_125 < 16 ) {
char V_67 [ 16 ] ;
if ( F_32 ( V_67 , V_5 , V_125 ) )
return - V_69 ;
V_67 [ V_125 ] = 0 ;
if ( V_67 [ V_125 - 1 ] == '\n' )
V_67 [ V_125 - 1 ] = 0 ;
if ( strcmp ( V_67 , L_61 ) == 0 ||
strcmp ( V_67 , L_62 ) == 0 )
V_183 = 0 ;
}
if ( V_183 == 0 )
V_7 -> V_177 = 0 ;
else
V_7 -> V_177 = 1 ;
F_18 ( & V_7 -> V_181 ) ;
for ( V_100 = 0 ; V_100 <= V_182 ; V_100 ++ ) {
V_153 -> V_168 [ V_100 ] . V_84 = 0 ;
F_103 ( & V_153 -> V_168 [ V_100 ] . V_170 ) ;
F_103 ( & V_153 -> V_168 [ V_100 ] . V_172 ) ;
}
F_19 ( & V_7 -> V_181 ) ;
return V_125 ;
}
void F_106 ( struct V_6 * V_7 , T_7 V_84 ,
struct V_185 * V_59 , T_6 V_186 ,
T_4 V_44 , int V_187 )
{
int V_100 , V_188 = - 1 ;
struct V_189 * V_190 ;
struct V_189 * V_191 ;
int * V_192 = & V_7 -> V_193 ;
int * V_194 = & V_7 -> V_195 ;
struct V_152 * V_153 = & V_7 -> V_152 ;
if ( ! V_7 -> V_177 )
return;
V_190 = V_7 -> V_189 ;
V_191 = V_7 -> V_196 ;
F_18 ( & V_7 -> V_181 ) ;
for ( V_100 = 0 ; V_100 < V_182 ; V_100 ++ ) {
if ( V_153 -> V_168 [ V_100 ] . V_84 == V_84 ) {
V_188 = V_100 ;
break;
}
}
if ( V_188 == - 1 ) {
V_7 -> V_197 =
( V_7 -> V_197 + 1 ) % V_182 ;
V_188 = V_7 -> V_197 ;
V_153 -> V_168 [ V_188 ] . V_84 = V_84 ;
F_103 ( & V_153 -> V_168 [ V_188 ] . V_170 ) ;
F_103 ( & V_153 -> V_168 [ V_188 ] . V_172 ) ;
}
for ( V_100 = 0 ; ( V_44 >= ( 1 << V_173 << V_100 ) ) &&
( V_100 < ( V_169 - 1 ) ) ; V_100 ++ )
;
if ( V_187 == 0 ) {
V_153 -> V_168 [ V_188 ] . V_170 . V_171 [ V_100 ] ++ ;
V_153 -> V_168 [ V_182 ] . V_170 . V_171 [ V_100 ] ++ ;
} else {
V_153 -> V_168 [ V_188 ] . V_172 . V_171 [ V_100 ] ++ ;
V_153 -> V_168 [ V_182 ] . V_172 . V_171 [ V_100 ] ++ ;
}
F_19 ( & V_7 -> V_181 ) ;
F_18 ( & V_7 -> V_198 ) ;
for ( V_100 = 0 ; V_100 < V_182 ; V_100 ++ ) {
if ( V_190 [ V_100 ] . V_199 == V_84 ) {
if ( V_190 [ V_100 ] . V_200 != V_59 ) {
V_190 [ V_100 ] . V_201 = V_186 ;
V_190 [ V_100 ] . V_202 = V_186 + V_44 ;
V_190 [ V_100 ] . V_203 = V_44 ;
V_190 [ V_100 ] . V_204 = V_44 ;
V_190 [ V_100 ] . V_205 = 0 ;
V_190 [ V_100 ] . V_200 = V_59 ;
F_19 ( & V_7 -> V_198 ) ;
return;
}
if ( V_190 [ V_100 ] . V_202 != V_186 ) {
* V_192 =
( * V_192 + 1 ) % V_206 ;
V_191 [ * V_192 ] . V_207 = V_190 [ V_100 ] . V_207 ;
V_191 [ * V_192 ] . V_199 = V_84 ;
V_191 [ * V_192 ] . V_201 =
V_190 [ V_100 ] . V_201 ;
V_191 [ * V_192 ] . V_208 =
V_190 [ V_100 ] . V_202 ;
V_191 [ * V_192 ] . V_203 =
V_190 [ V_100 ] . V_203 ;
V_191 [ * V_192 ] . V_204 =
V_190 [ V_100 ] . V_204 ;
V_191 [ * V_192 ] . V_205 =
V_190 [ V_100 ] . V_205 ;
V_190 [ V_100 ] . V_207 = V_187 ;
V_190 [ V_100 ] . V_201 = V_186 ;
V_190 [ V_100 ] . V_203 = V_44 ;
V_190 [ V_100 ] . V_204 = V_44 ;
V_190 [ V_100 ] . V_205 = V_186 -
V_190 [ V_100 ] . V_202 ;
}
if ( V_190 [ V_100 ] . V_203 > V_44 )
V_190 [ V_100 ] . V_203 = V_44 ;
if ( V_190 [ V_100 ] . V_204 < V_44 )
V_190 [ V_100 ] . V_204 = V_44 ;
V_190 [ V_100 ] . V_202 = V_186 + V_44 ;
F_19 ( & V_7 -> V_198 ) ;
return;
}
}
* V_194 = ( * V_194 + 1 ) % V_182 ;
V_190 [ * V_194 ] . V_199 = V_84 ;
V_190 [ * V_194 ] . V_207 = V_187 ;
V_190 [ * V_194 ] . V_201 = V_186 ;
V_190 [ * V_194 ] . V_202 = V_186 + V_44 ;
V_190 [ * V_194 ] . V_203 = V_44 ;
V_190 [ * V_194 ] . V_204 = V_44 ;
V_190 [ * V_194 ] . V_205 = 0 ;
V_190 [ * V_194 ] . V_200 = V_59 ;
F_19 ( & V_7 -> V_198 ) ;
}
static int F_107 ( struct V_29 * V_154 , void * V_31 )
{
struct V_174 V_175 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_189 * V_191 = V_7 -> V_196 ;
struct V_189 * V_190 = V_7 -> V_189 ;
int V_100 ;
F_100 ( & V_175 ) ;
if ( ! V_7 -> V_177 ) {
F_30 ( V_154 , L_48
L_49 ) ;
return 0 ;
}
F_18 ( & V_7 -> V_198 ) ;
F_30 ( V_154 , L_50 ,
( V_178 ) V_175 . V_179 , ( unsigned long ) V_175 . V_180 ) ;
F_30 ( V_154 , L_63 ,
L_64 , L_65 , L_66 , L_67 ,
L_68 , L_69 , L_70 ) ;
for ( V_100 = 0 ; V_100 < V_206 ; V_100 ++ ) {
if ( V_191 [ V_100 ] . V_199 != 0 )
F_30 ( V_154 ,
L_71 ,
V_191 [ V_100 ] . V_207 == V_209 ? 'R' : 'W' ,
V_191 [ V_100 ] . V_199 ,
V_191 [ V_100 ] . V_201 ,
V_191 [ V_100 ] . V_208 ,
( unsigned long ) V_191 [ V_100 ] . V_203 ,
( unsigned long ) V_191 [ V_100 ] . V_204 ,
V_191 [ V_100 ] . V_205 ) ;
}
for ( V_100 = 0 ; V_100 < V_182 ; V_100 ++ ) {
if ( V_190 [ V_100 ] . V_199 != 0 )
F_30 ( V_154 ,
L_71 ,
V_190 [ V_100 ] . V_207 == V_209 ? 'R' : 'W' ,
V_190 [ V_100 ] . V_199 ,
V_190 [ V_100 ] . V_201 ,
V_190 [ V_100 ] . V_202 ,
( unsigned long ) V_190 [ V_100 ] . V_203 ,
( unsigned long ) V_190 [ V_100 ] . V_204 ,
V_190 [ V_100 ] . V_205 ) ;
}
F_19 ( & V_7 -> V_198 ) ;
return 0 ;
}
static T_1 F_108 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_125 , T_6 * V_60 )
{
struct V_29 * V_154 = V_59 -> V_61 ;
struct V_6 * V_7 = V_154 -> V_34 ;
struct V_189 * V_210 = V_7 -> V_189 ;
struct V_189 * V_211 = V_7 -> V_196 ;
int V_183 = 1 , V_11 = 0 ;
if ( V_125 == 0 )
return - V_68 ;
V_11 = F_102 ( V_5 , V_125 , & V_183 ) ;
if ( V_11 < 0 && V_125 < 16 ) {
char V_67 [ 16 ] ;
if ( F_32 ( V_67 , V_5 , V_125 ) )
return - V_69 ;
V_67 [ V_125 ] = 0 ;
if ( V_67 [ V_125 - 1 ] == '\n' )
V_67 [ V_125 - 1 ] = 0 ;
if ( strcmp ( V_67 , L_61 ) == 0 ||
strcmp ( V_67 , L_62 ) == 0 )
V_183 = 0 ;
}
if ( V_183 == 0 )
V_7 -> V_177 = 0 ;
else
V_7 -> V_177 = 1 ;
F_18 ( & V_7 -> V_198 ) ;
V_7 -> V_195 = 0 ;
V_7 -> V_193 = 0 ;
memset ( V_210 , 0 , sizeof( struct V_189 ) *
V_182 ) ;
memset ( V_211 , 0 , sizeof( struct V_189 ) *
V_206 ) ;
F_19 ( & V_7 -> V_198 ) ;
return V_125 ;
}
void F_109 ( struct V_212 * V_213 )
{
V_213 -> V_214 = V_145 ;
}
