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
int V_51 ;
int V_52 ;
V_51 = V_48 -> V_53 >> V_50 ;
V_52 = F_29 ( & V_48 -> V_54 ) >> V_50 ;
F_30 ( V_28 ,
L_8
L_9
L_10
L_11
L_12 ,
F_29 ( & V_48 -> V_55 ) ,
V_51 ,
V_51 - V_52 ,
V_52 ,
V_48 -> V_56 ) ;
return 0 ;
}
static T_1 F_31 ( struct V_57 * V_57 ,
const char T_5 * V_41 ,
T_4 V_42 , T_6 * V_58 )
{
struct V_30 * V_31 = ( (struct V_27 * ) V_57 -> V_59 ) -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_47 * V_48 = V_7 -> V_49 ;
struct V_60 * V_61 ;
int V_62 ;
int V_35 , V_11 , V_34 ;
int V_63 = 0 ;
int V_64 = 0 ;
char V_65 [ 128 ] ;
if ( V_42 >= sizeof( V_65 ) )
return - V_66 ;
if ( F_32 ( V_65 , V_41 , V_42 ) )
return - V_67 ;
V_65 [ V_42 ] = 0 ;
V_35 = 1 << ( 20 - V_39 ) ;
V_41 += F_33 ( V_65 , L_13 , & V_42 ) -
V_65 ;
V_11 = F_34 ( V_41 , V_42 , & V_34 , V_35 ) ;
if ( V_11 )
return V_11 ;
if ( V_34 < 0 || V_34 > V_43 ) {
F_23 ( L_14 ,
F_35 ( V_31 , NULL , 0 ) ,
V_43 >> ( 20 - V_39 ) ) ;
return - V_44 ;
}
F_18 ( & V_7 -> V_36 ) ;
V_63 = V_34 - V_48 -> V_53 ;
F_19 ( & V_7 -> V_36 ) ;
if ( V_63 >= 0 ) {
F_36 ( V_63 , & V_48 -> V_54 ) ;
V_11 = 0 ;
goto V_68;
}
V_61 = F_37 ( & V_62 ) ;
if ( F_38 ( V_61 ) )
return 0 ;
V_63 = - V_63 ;
while ( V_63 > 0 ) {
int V_69 ;
do {
int V_70 , V_71 ;
V_70 = F_29 ( & V_48 -> V_54 ) ;
if ( V_70 == 0 )
break;
V_71 = V_70 > V_63 ? V_70 - V_63 : 0 ;
V_11 = F_39 ( & V_48 -> V_54 , V_70 , V_71 ) ;
if ( F_40 ( V_70 == V_11 ) ) {
V_63 -= V_70 - V_71 ;
V_64 += V_70 - V_71 ;
break;
}
} while ( 1 );
if ( V_63 <= 0 )
break;
if ( ! V_7 -> V_72 ) {
V_11 = 0 ;
goto V_68;
}
V_69 = V_63 << 1 ;
V_11 = F_41 ( V_61 , V_7 -> V_72 ,
sizeof( V_73 ) ,
V_73 ,
sizeof( V_69 ) , & V_69 , NULL ) ;
if ( V_11 < 0 )
break;
}
F_42 ( V_61 , & V_62 ) ;
V_68:
if ( V_11 >= 0 ) {
F_18 ( & V_7 -> V_36 ) ;
V_48 -> V_53 = V_34 ;
F_19 ( & V_7 -> V_36 ) ;
V_11 = V_42 ;
} else {
F_36 ( V_64 , & V_48 -> V_54 ) ;
}
return V_11 ;
}
static T_1 F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ( V_7 -> V_74 & V_75 ) ? 1 : 0 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_76 ;
if ( ! V_7 -> V_72 )
return - V_77 ;
V_11 = F_22 ( V_41 , 10 , & V_76 ) ;
if ( V_11 )
return V_11 ;
if ( V_76 )
V_7 -> V_74 |= V_75 ;
else
V_7 -> V_74 &= ~ V_75 ;
V_11 = F_41 ( NULL , V_7 -> V_72 , sizeof( V_78 ) ,
V_78 , sizeof( V_76 ) , & V_76 , NULL ) ;
if ( V_11 )
F_45 ( L_15 , V_11 ) ;
return V_42 ;
}
static T_1 F_46 ( struct V_1 * V_2 , char * V_5 ,
enum V_79 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
if ( V_7 -> V_80 == type )
return sprintf ( V_5 , L_16 , V_7 -> V_81 ) ;
else if ( V_7 -> V_80 == V_82 )
return sprintf ( V_5 , L_17 ) ;
else
return sprintf ( V_5 , L_18 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 , const char * V_41 ,
T_4 V_42 ,
enum V_79 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_83 ;
V_11 = F_22 ( V_41 , 10 , & V_83 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_81 = V_83 ;
if ( V_83 == 0 )
V_7 -> V_80 = V_82 ;
else
V_7 -> V_80 = type ;
F_48 ( V_7 -> V_84 ) ;
return V_42 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_85 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_47 ( V_2 , V_41 , V_42 , V_85 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_86 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_47 ( V_2 , V_41 , V_42 , V_86 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_46 ( V_2 , V_5 , V_87 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
return F_47 ( V_2 , V_41 , V_42 , V_87 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_88 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_76 ;
V_11 = F_22 ( V_41 , 10 , & V_76 ) ;
if ( V_11 )
return V_11 ;
if ( V_76 <= V_89 )
V_7 -> V_88 = V_76 ;
else
F_23 ( L_19 ,
V_76 , V_89 ) ;
return V_42 ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_74 & V_90 ? 1 : 0 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_76 ;
V_11 = F_22 ( V_41 , 10 , & V_76 ) ;
if ( V_11 )
return V_11 ;
if ( V_76 )
V_7 -> V_74 |= V_90 ;
else
V_7 -> V_74 &= ~ V_90 ;
return V_42 ;
}
static int F_59 ( struct V_27 * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
F_30 ( V_28 ,
L_20
L_21
L_22 ,
F_29 ( & V_7 -> V_91 ) ,
F_29 ( & V_7 -> V_92 ) ,
F_29 ( & V_7 -> V_93 ) ) ;
return 0 ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_74 & V_94 ? 1 : 0 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_76 ;
V_11 = F_22 ( V_41 , 10 , & V_76 ) ;
if ( V_11 )
return V_11 ;
if ( V_76 )
V_7 -> V_74 |= V_94 ;
else
V_7 -> V_74 &= ~ V_94 ;
return V_42 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_95 ;
int V_11 ;
V_11 = F_63 ( V_7 , & V_95 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_95 ) ;
}
static T_1 F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_95 ;
int V_11 ;
V_11 = F_65 ( V_7 , & V_95 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_95 ) ;
}
static int F_66 ( struct V_27 * V_28 , void * V_29 )
{
const char * V_96 [] = V_97 ;
struct V_30 * V_31 = V_28 -> V_32 ;
int V_98 = F_16 ( V_31 ) -> V_74 ;
int V_99 = 0 ;
while ( V_98 != 0 ) {
if ( F_67 ( V_96 ) <= V_99 ) {
F_23 ( L_23 ,
F_35 ( V_31 , NULL , 0 ) ) ;
return - V_66 ;
}
if ( V_98 & 0x1 )
F_30 ( V_28 , L_24 , V_96 [ V_99 ] ) ;
V_98 >>= 1 ;
++ V_99 ;
}
F_30 ( V_28 , L_25 ) ;
return 0 ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_100 ) ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_41 ,
T_4 V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_76 ;
V_11 = F_22 ( V_41 , 10 , & V_76 ) ;
if ( V_11 )
return V_11 ;
if ( V_76 != 0 && V_76 != 1 )
return - V_44 ;
if ( V_76 == 1 && ! ( V_7 -> V_74 & V_101 ) )
return - V_102 ;
V_7 -> V_100 = V_76 ;
return V_42 ;
}
static T_1 F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_47 * V_48 = V_7 -> V_49 ;
int V_103 , V_104 ;
V_103 = F_29 ( & V_48 -> V_105 ) ;
V_104 = ( V_103 * V_40 ) >> 20 ;
return sprintf ( V_5 , L_26
L_27 , V_103 , V_104 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
F_72 ( & V_7 -> V_106 ) ;
}
void F_73 ( struct V_6 * V_7 , int V_107 , int V_42 )
{
if ( ! V_7 -> V_84 )
return;
if ( V_7 -> V_80 == V_82 )
F_74 ( V_7 -> V_84 , V_107 , V_42 ) ;
else if ( V_7 -> V_80 == V_85 &&
V_7 -> V_81 == V_108 -> V_83 )
F_74 ( V_7 -> V_84 , V_107 , V_42 ) ;
else if ( V_7 -> V_80 == V_86 &&
V_7 -> V_81 == V_108 -> V_109 -> V_83 )
F_74 ( V_7 -> V_84 , V_107 , V_42 ) ;
else if ( V_7 -> V_80 == V_87 &&
V_7 -> V_81 ==
F_75 ( & V_110 , F_76 () ) )
F_74 ( V_7 -> V_84 , V_107 , V_42 ) ;
}
int F_77 ( struct V_111 * V_112 ,
struct V_30 * V_31 , char * V_113 , char * V_114 )
{
struct V_115 * V_116 = F_78 ( V_31 ) ;
struct V_6 * V_7 = F_16 ( V_31 ) ;
struct V_117 * V_118 ;
struct V_111 * V_119 ;
char V_24 [ V_120 + 1 ] , * V_121 ;
int V_122 , V_123 , V_124 , V_11 ;
V_24 [ V_120 ] = '\0' ;
F_79 ( V_7 ) ;
F_79 ( V_114 ) ;
F_79 ( V_113 ) ;
V_124 = strlen ( V_116 -> V_125 -> V_126 ) ;
V_121 = strrchr ( V_116 -> V_125 -> V_126 , '-' ) ;
if ( V_121 && ( strcmp ( V_121 , L_28 ) == 0 ) )
V_124 -= 7 ;
snprintf ( V_24 , V_120 , L_29 , V_124 ,
V_116 -> V_125 -> V_126 , V_31 ) ;
V_119 = F_80 ( V_24 , V_112 , NULL , NULL ) ;
if ( F_81 ( V_119 ) ) {
V_122 = V_119 ? F_82 ( V_119 ) : - V_127 ;
V_7 -> V_128 = NULL ;
return V_122 ;
}
V_7 -> V_128 = V_119 ;
V_11 = F_83 ( V_7 -> V_128 , L_30 , 0444 ,
& V_129 , V_7 ) ;
if ( V_11 )
F_45 ( L_31 ) ;
V_11 = F_83 ( V_7 -> V_128 , L_32 , 0644 ,
& V_130 , V_7 ) ;
if ( V_11 )
F_45 ( L_33 ) ;
V_11 = F_83 ( V_7 -> V_128 ,
L_34 ,
0644 , & V_131 , V_7 ) ;
if ( V_11 )
F_45 ( L_35 ) ;
V_11 = F_83 ( V_7 -> V_128 , L_36 , 0644 ,
& V_132 , V_7 ) ;
if ( V_11 )
F_45 ( L_37 ) ;
V_7 -> V_84 = F_84 ( V_133 ,
V_134 ) ;
if ( ! V_7 -> V_84 ) {
V_122 = - V_127 ;
goto V_68;
}
for ( V_123 = 0 ; V_123 < V_133 ; V_123 ++ ) {
T_2 type = V_135 [ V_123 ] . type ;
void * V_121 = NULL ;
if ( type & V_136 )
V_121 = L_38 ;
else if ( type & V_137 )
V_121 = L_39 ;
else if ( type & V_138 )
V_121 = L_40 ;
F_85 ( V_7 -> V_84 ,
V_135 [ V_123 ] . V_139 ,
( type & V_140 ) ,
V_135 [ V_123 ] . V_141 , V_121 ) ;
}
V_122 = F_86 ( V_7 -> V_128 , L_41 ,
V_7 -> V_84 ) ;
if ( V_122 )
goto V_68;
V_7 -> V_142 = F_84 ( F_67 ( V_143 ) ,
V_134 ) ;
if ( ! V_7 -> V_142 ) {
V_122 = - V_127 ;
goto V_68;
}
for ( V_123 = 0 ; V_123 < F_67 ( V_143 ) ; V_123 ++ )
F_85 ( V_7 -> V_142 , V_123 , 0 ,
V_143 [ V_123 ] , L_40 ) ;
V_122 = F_86 ( V_7 -> V_128 , L_42 ,
V_7 -> V_142 ) ;
if ( V_122 )
goto V_68;
V_122 = F_87 ( V_7 -> V_128 ,
V_144 , V_31 ) ;
if ( V_122 )
goto V_68;
V_7 -> V_8 . V_145 = V_146 ;
F_88 ( & V_7 -> V_106 ) ;
V_122 = F_89 ( & V_7 -> V_8 , & V_147 , NULL ,
L_43 , V_24 ) ;
if ( V_122 )
goto V_68;
V_118 = F_90 ( V_114 ) ;
V_122 = F_91 ( & V_7 -> V_8 , & V_118 -> V_148 ,
V_118 -> V_149 -> V_150 ) ;
if ( V_122 )
goto V_68;
V_118 = F_90 ( V_113 ) ;
V_122 = F_91 ( & V_7 -> V_8 , & V_118 -> V_148 ,
V_118 -> V_149 -> V_150 ) ;
V_68:
if ( V_122 ) {
F_92 ( & V_7 -> V_128 ) ;
F_93 ( & V_7 -> V_142 ) ;
F_93 ( & V_7 -> V_84 ) ;
}
return V_122 ;
}
void F_94 ( struct V_6 * V_7 )
{
if ( V_7 -> V_128 ) {
F_92 ( & V_7 -> V_128 ) ;
F_95 ( & V_7 -> V_8 ) ;
F_96 ( & V_7 -> V_106 ) ;
F_93 ( & V_7 -> V_142 ) ;
F_93 ( & V_7 -> V_84 ) ;
}
}
static void F_97 ( struct V_151 * V_152 ,
struct V_27 * V_153 , int V_154 )
{
unsigned long V_155 = 0 , V_156 = 0 , V_157 , V_158 ;
unsigned long V_159 , V_160 , V_161 , V_162 ;
char * V_163 = L_44 ;
int V_99 , V_164 = 10 ;
struct V_165 * V_166 = & V_152 -> V_167 [ V_154 ] ;
V_157 = 0 ;
V_158 = 0 ;
V_159 = 0 ;
for ( V_99 = 0 ; V_99 < V_168 ; V_99 ++ ) {
V_155 += V_166 -> V_169 . V_170 [ V_99 ] ;
V_156 += V_166 -> V_171 . V_170 [ V_99 ] ;
}
for ( V_99 = 0 ; V_99 < V_168 ; V_99 ++ ) {
V_161 = V_166 -> V_169 . V_170 [ V_99 ] ;
V_162 = V_166 -> V_171 . V_170 [ V_99 ] ;
V_157 += V_161 ;
V_158 += V_162 ;
V_160 = 1 << ( V_99 + V_172 - V_164 ) ;
F_30 ( V_153 , L_45 ,
V_159 , * V_163 , V_160 , * V_163 ,
( V_99 == V_168 - 1 ) ? '+' : ' ' ,
V_161 , F_98 ( V_161 , V_155 ) , F_98 ( V_157 , V_155 ) ,
V_162 , F_98 ( V_162 , V_156 ) , F_98 ( V_158 , V_156 ) ) ;
V_159 = V_160 ;
if ( V_159 == 1 << 10 ) {
V_159 = 1 ;
V_164 += 10 ;
V_163 ++ ;
}
if ( V_157 == V_155 && V_158 == V_156 )
break;
}
}
static int F_99 ( struct V_27 * V_153 , void * V_29 )
{
struct V_173 V_174 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_151 * V_152 = & V_7 -> V_151 ;
int V_175 ;
F_100 ( & V_174 ) ;
if ( ! V_7 -> V_176 ) {
F_30 ( V_153 , L_46
L_47 ) ;
return 0 ;
}
F_30 ( V_153 , L_48 ,
( V_177 ) V_174 . V_178 , ( unsigned long ) V_174 . V_179 ) ;
F_30 ( V_153 , L_49 , L_50 , L_51 , L_52 ) ;
F_30 ( V_153 , L_53 ,
L_54 , L_55 , L_56 , L_57 ,
L_55 , L_56 , L_57 ) ;
F_18 ( & V_7 -> V_180 ) ;
for ( V_175 = 0 ; V_175 < V_181 ; V_175 ++ ) {
if ( V_152 -> V_167 [ V_175 ] . V_83 != 0 ) {
F_30 ( V_153 , L_58 ,
V_152 -> V_167 [ V_175 ] . V_83 ) ;
F_97 ( V_152 , V_153 , V_175 ) ;
}
}
F_19 ( & V_7 -> V_180 ) ;
return 0 ;
}
static T_1 F_101 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_124 ,
T_6 * V_58 )
{
struct V_27 * V_153 = V_57 -> V_59 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_151 * V_152 = & V_7 -> V_151 ;
int V_99 ;
int V_182 = 1 , V_11 = 0 ;
if ( V_124 == 0 )
return - V_66 ;
V_11 = F_102 ( V_5 , V_124 , & V_182 ) ;
if ( V_11 < 0 && V_124 < 16 ) {
char V_65 [ 16 ] ;
if ( F_32 ( V_65 , V_5 , V_124 ) )
return - V_67 ;
V_65 [ V_124 ] = 0 ;
if ( V_65 [ V_124 - 1 ] == '\n' )
V_65 [ V_124 - 1 ] = 0 ;
if ( strcmp ( V_65 , L_59 ) == 0 ||
strcmp ( V_65 , L_60 ) == 0 )
V_182 = 0 ;
}
if ( V_182 == 0 )
V_7 -> V_176 = 0 ;
else
V_7 -> V_176 = 1 ;
F_18 ( & V_7 -> V_180 ) ;
for ( V_99 = 0 ; V_99 < V_181 ; V_99 ++ ) {
V_152 -> V_167 [ V_99 ] . V_83 = 0 ;
F_103 ( & V_152 -> V_167 [ V_99 ] . V_169 ) ;
F_103 ( & V_152 -> V_167 [ V_99 ] . V_171 ) ;
}
F_19 ( & V_7 -> V_180 ) ;
return V_124 ;
}
static int F_104 ( struct V_27 * V_153 , void * V_29 )
{
struct V_173 V_174 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_151 * V_152 = & V_7 -> V_151 ;
F_100 ( & V_174 ) ;
if ( ! V_7 -> V_176 ) {
F_30 ( V_153 , L_46
L_47 ) ;
return 0 ;
}
F_30 ( V_153 , L_48 ,
( V_183 ) V_174 . V_178 , ( unsigned long ) V_174 . V_179 ) ;
F_30 ( V_153 , L_49 , L_50 , L_51 , L_52 ) ;
F_30 ( V_153 , L_53 ,
L_54 , L_55 , L_56 , L_57 ,
L_55 , L_56 , L_57 ) ;
F_18 ( & V_7 -> V_36 ) ;
F_97 ( V_152 , V_153 , V_181 ) ;
F_19 ( & V_7 -> V_36 ) ;
return 0 ;
}
static T_1 F_105 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_124 , T_6 * V_58 )
{
struct V_27 * V_153 = V_57 -> V_59 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_151 * V_152 = & V_7 -> V_151 ;
int V_99 ;
int V_182 = 1 , V_11 = 0 ;
if ( V_124 == 0 )
return - V_66 ;
V_11 = F_102 ( V_5 , V_124 , & V_182 ) ;
if ( V_11 < 0 && V_124 < 16 ) {
char V_65 [ 16 ] ;
if ( F_32 ( V_65 , V_5 , V_124 ) )
return - V_67 ;
V_65 [ V_124 ] = 0 ;
if ( V_65 [ V_124 - 1 ] == '\n' )
V_65 [ V_124 - 1 ] = 0 ;
if ( strcmp ( V_65 , L_59 ) == 0 ||
strcmp ( V_65 , L_60 ) == 0 )
V_182 = 0 ;
}
if ( V_182 == 0 )
V_7 -> V_176 = 0 ;
else
V_7 -> V_176 = 1 ;
F_18 ( & V_7 -> V_180 ) ;
for ( V_99 = 0 ; V_99 <= V_181 ; V_99 ++ ) {
V_152 -> V_167 [ V_99 ] . V_83 = 0 ;
F_103 ( & V_152 -> V_167 [ V_99 ] . V_169 ) ;
F_103 ( & V_152 -> V_167 [ V_99 ] . V_171 ) ;
}
F_19 ( & V_7 -> V_180 ) ;
return V_124 ;
}
void F_106 ( struct V_6 * V_7 , T_7 V_83 ,
struct V_184 * V_57 , T_6 V_185 ,
T_4 V_42 , int V_186 )
{
int V_99 , V_187 = - 1 ;
struct V_188 * V_189 ;
struct V_188 * V_190 ;
int * V_191 = & V_7 -> V_192 ;
int * V_193 = & V_7 -> V_194 ;
struct V_151 * V_152 = & V_7 -> V_151 ;
if ( ! V_7 -> V_176 )
return;
V_189 = V_7 -> V_188 ;
V_190 = V_7 -> V_195 ;
F_18 ( & V_7 -> V_180 ) ;
for ( V_99 = 0 ; V_99 < V_181 ; V_99 ++ ) {
if ( V_152 -> V_167 [ V_99 ] . V_83 == V_83 ) {
V_187 = V_99 ;
break;
}
}
if ( V_187 == - 1 ) {
V_7 -> V_196 =
( V_7 -> V_196 + 1 ) % V_181 ;
V_187 = V_7 -> V_196 ;
V_152 -> V_167 [ V_187 ] . V_83 = V_83 ;
F_103 ( & V_152 -> V_167 [ V_187 ] . V_169 ) ;
F_103 ( & V_152 -> V_167 [ V_187 ] . V_171 ) ;
}
for ( V_99 = 0 ; ( V_42 >= ( 1 << V_172 << V_99 ) ) &&
( V_99 < ( V_168 - 1 ) ) ; V_99 ++ )
;
if ( V_186 == 0 ) {
V_152 -> V_167 [ V_187 ] . V_169 . V_170 [ V_99 ] ++ ;
V_152 -> V_167 [ V_181 ] . V_169 . V_170 [ V_99 ] ++ ;
} else {
V_152 -> V_167 [ V_187 ] . V_171 . V_170 [ V_99 ] ++ ;
V_152 -> V_167 [ V_181 ] . V_171 . V_170 [ V_99 ] ++ ;
}
F_19 ( & V_7 -> V_180 ) ;
F_18 ( & V_7 -> V_197 ) ;
for ( V_99 = 0 ; V_99 < V_181 ; V_99 ++ ) {
if ( V_189 [ V_99 ] . V_198 == V_83 ) {
if ( V_189 [ V_99 ] . V_199 != V_57 ) {
V_189 [ V_99 ] . V_200 = V_185 ;
V_189 [ V_99 ] . V_201 = V_185 + V_42 ;
V_189 [ V_99 ] . V_202 = V_42 ;
V_189 [ V_99 ] . V_203 = V_42 ;
V_189 [ V_99 ] . V_204 = 0 ;
V_189 [ V_99 ] . V_199 = V_57 ;
F_19 ( & V_7 -> V_197 ) ;
return;
}
if ( V_189 [ V_99 ] . V_201 != V_185 ) {
* V_191 =
( * V_191 + 1 ) % V_205 ;
V_190 [ * V_191 ] . V_206 = V_189 [ V_99 ] . V_206 ;
V_190 [ * V_191 ] . V_198 = V_83 ;
V_190 [ * V_191 ] . V_200 =
V_189 [ V_99 ] . V_200 ;
V_190 [ * V_191 ] . V_207 =
V_189 [ V_99 ] . V_201 ;
V_190 [ * V_191 ] . V_202 =
V_189 [ V_99 ] . V_202 ;
V_190 [ * V_191 ] . V_203 =
V_189 [ V_99 ] . V_203 ;
V_190 [ * V_191 ] . V_204 =
V_189 [ V_99 ] . V_204 ;
V_189 [ V_99 ] . V_206 = V_186 ;
V_189 [ V_99 ] . V_200 = V_185 ;
V_189 [ V_99 ] . V_202 = V_42 ;
V_189 [ V_99 ] . V_203 = V_42 ;
V_189 [ V_99 ] . V_204 = V_185 -
V_189 [ V_99 ] . V_201 ;
}
if ( V_189 [ V_99 ] . V_202 > V_42 )
V_189 [ V_99 ] . V_202 = V_42 ;
if ( V_189 [ V_99 ] . V_203 < V_42 )
V_189 [ V_99 ] . V_203 = V_42 ;
V_189 [ V_99 ] . V_201 = V_185 + V_42 ;
F_19 ( & V_7 -> V_197 ) ;
return;
}
}
* V_193 = ( * V_193 + 1 ) % V_181 ;
V_189 [ * V_193 ] . V_198 = V_83 ;
V_189 [ * V_193 ] . V_206 = V_186 ;
V_189 [ * V_193 ] . V_200 = V_185 ;
V_189 [ * V_193 ] . V_201 = V_185 + V_42 ;
V_189 [ * V_193 ] . V_202 = V_42 ;
V_189 [ * V_193 ] . V_203 = V_42 ;
V_189 [ * V_193 ] . V_204 = 0 ;
V_189 [ * V_193 ] . V_199 = V_57 ;
F_19 ( & V_7 -> V_197 ) ;
}
static int F_107 ( struct V_27 * V_153 , void * V_29 )
{
struct V_173 V_174 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_188 * V_190 = V_7 -> V_195 ;
struct V_188 * V_189 = V_7 -> V_188 ;
int V_99 ;
F_100 ( & V_174 ) ;
if ( ! V_7 -> V_176 ) {
F_30 ( V_153 , L_46
L_47 ) ;
return 0 ;
}
F_18 ( & V_7 -> V_197 ) ;
F_30 ( V_153 , L_48 ,
( V_177 ) V_174 . V_178 , ( unsigned long ) V_174 . V_179 ) ;
F_30 ( V_153 , L_61 ,
L_62 , L_63 , L_64 , L_65 ,
L_66 , L_67 , L_68 ) ;
for ( V_99 = 0 ; V_99 < V_205 ; V_99 ++ ) {
if ( V_190 [ V_99 ] . V_198 != 0 )
F_30 ( V_153 ,
L_69 ,
V_190 [ V_99 ] . V_206 == V_208 ? 'R' : 'W' ,
V_190 [ V_99 ] . V_198 ,
V_190 [ V_99 ] . V_200 ,
V_190 [ V_99 ] . V_207 ,
( unsigned long ) V_190 [ V_99 ] . V_202 ,
( unsigned long ) V_190 [ V_99 ] . V_203 ,
V_190 [ V_99 ] . V_204 ) ;
}
for ( V_99 = 0 ; V_99 < V_181 ; V_99 ++ ) {
if ( V_189 [ V_99 ] . V_198 != 0 )
F_30 ( V_153 ,
L_69 ,
V_189 [ V_99 ] . V_206 == V_208 ? 'R' : 'W' ,
V_189 [ V_99 ] . V_198 ,
V_189 [ V_99 ] . V_200 ,
V_189 [ V_99 ] . V_201 ,
( unsigned long ) V_189 [ V_99 ] . V_202 ,
( unsigned long ) V_189 [ V_99 ] . V_203 ,
V_189 [ V_99 ] . V_204 ) ;
}
F_19 ( & V_7 -> V_197 ) ;
return 0 ;
}
static T_1 F_108 ( struct V_57 * V_57 ,
const char T_5 * V_5 ,
T_4 V_124 , T_6 * V_58 )
{
struct V_27 * V_153 = V_57 -> V_59 ;
struct V_6 * V_7 = V_153 -> V_32 ;
struct V_188 * V_209 = V_7 -> V_188 ;
struct V_188 * V_210 = V_7 -> V_195 ;
int V_182 = 1 , V_11 = 0 ;
if ( V_124 == 0 )
return - V_66 ;
V_11 = F_102 ( V_5 , V_124 , & V_182 ) ;
if ( V_11 < 0 && V_124 < 16 ) {
char V_65 [ 16 ] ;
if ( F_32 ( V_65 , V_5 , V_124 ) )
return - V_67 ;
V_65 [ V_124 ] = 0 ;
if ( V_65 [ V_124 - 1 ] == '\n' )
V_65 [ V_124 - 1 ] = 0 ;
if ( strcmp ( V_65 , L_59 ) == 0 ||
strcmp ( V_65 , L_60 ) == 0 )
V_182 = 0 ;
}
if ( V_182 == 0 )
V_7 -> V_176 = 0 ;
else
V_7 -> V_176 = 1 ;
F_18 ( & V_7 -> V_197 ) ;
V_7 -> V_194 = 0 ;
V_7 -> V_192 = 0 ;
memset ( V_209 , 0 , sizeof( struct V_188 ) *
V_181 ) ;
memset ( V_210 , 0 , sizeof( struct V_188 ) *
V_205 ) ;
F_19 ( & V_7 -> V_197 ) ;
return V_124 ;
}
void F_109 ( struct V_211 * V_212 )
{
V_212 -> V_213 = V_144 ;
}
