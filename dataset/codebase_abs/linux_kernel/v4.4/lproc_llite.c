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
int V_37 , V_11 , V_36 ;
int V_62 = 0 ;
int V_63 = 0 ;
char V_64 [ 128 ] ;
if ( V_44 >= sizeof( V_64 ) )
return - V_65 ;
if ( F_32 ( V_64 , V_43 , V_44 ) )
return - V_66 ;
V_64 [ V_44 ] = 0 ;
V_37 = 1 << ( 20 - V_41 ) ;
V_43 += F_33 ( V_64 , L_15 , & V_44 ) -
V_64 ;
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
V_62 = V_36 - V_50 -> V_55 ;
F_19 ( & V_7 -> V_38 ) ;
if ( V_62 >= 0 ) {
F_36 ( V_62 , & V_50 -> V_56 ) ;
V_11 = 0 ;
goto V_67;
}
V_62 = - V_62 ;
while ( V_62 > 0 ) {
int V_68 ;
do {
int V_69 , V_70 ;
V_69 = F_29 ( & V_50 -> V_56 ) ;
if ( V_69 == 0 )
break;
V_70 = V_69 > V_62 ? V_69 - V_62 : 0 ;
V_11 = F_37 ( & V_50 -> V_56 , V_69 , V_70 ) ;
if ( F_38 ( V_69 == V_11 ) ) {
V_62 -= V_69 - V_70 ;
V_63 += V_69 - V_70 ;
break;
}
} while ( 1 );
if ( V_62 <= 0 )
break;
if ( V_7 -> V_71 == NULL ) {
V_11 = - V_72 ;
break;
}
V_68 = V_62 << 1 ;
V_11 = F_39 ( NULL , V_7 -> V_71 ,
sizeof( V_73 ) ,
V_73 ,
sizeof( V_68 ) , & V_68 , NULL ) ;
if ( V_11 < 0 )
break;
}
V_67:
if ( V_11 >= 0 ) {
F_18 ( & V_7 -> V_38 ) ;
V_50 -> V_55 = V_36 ;
F_19 ( & V_7 -> V_38 ) ;
V_11 = V_44 ;
} else {
F_36 ( V_63 , & V_50 -> V_56 ) ;
}
return V_11 ;
}
static T_1 F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , ( V_7 -> V_23 & V_74 ) ? 1 : 0 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_75 ;
if ( ! V_7 -> V_71 )
return - V_76 ;
V_11 = F_22 ( V_43 , 10 , & V_75 ) ;
if ( V_11 )
return V_11 ;
if ( V_75 )
V_7 -> V_23 |= V_74 ;
else
V_7 -> V_23 &= ~ V_74 ;
V_11 = F_39 ( NULL , V_7 -> V_71 , sizeof( V_77 ) ,
V_77 , sizeof( V_75 ) , & V_75 , NULL ) ;
if ( V_11 )
F_42 ( L_17 , V_11 ) ;
return V_44 ;
}
static T_1 F_43 ( struct V_1 * V_2 , char * V_5 ,
enum V_78 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
if ( V_7 -> V_79 == type )
return sprintf ( V_5 , L_18 , V_7 -> V_80 ) ;
else if ( V_7 -> V_79 == V_81 )
return sprintf ( V_5 , L_19 ) ;
else
return sprintf ( V_5 , L_20 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 , const char * V_43 ,
T_4 V_44 ,
enum V_78 type )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_82 ;
V_11 = F_22 ( V_43 , 10 , & V_82 ) ;
if ( V_11 )
return V_11 ;
V_7 -> V_80 = V_82 ;
if ( V_82 == 0 )
V_7 -> V_79 = V_81 ;
else
V_7 -> V_79 = type ;
F_45 ( V_7 -> V_83 ) ;
return V_44 ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_43 ( V_2 , V_5 , V_84 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_44 ( V_2 , V_43 , V_44 , V_84 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_43 ( V_2 , V_5 , V_85 ) ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_44 ( V_2 , V_43 , V_44 , V_85 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return F_43 ( V_2 , V_5 , V_86 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
return F_44 ( V_2 , V_43 , V_44 , V_86 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_87 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_75 ;
V_11 = F_22 ( V_43 , 10 , & V_75 ) ;
if ( V_11 )
return V_11 ;
if ( V_75 <= V_88 )
V_7 -> V_87 = V_75 ;
else
F_23 ( L_21 ,
V_75 , V_88 ) ;
return V_44 ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_23 & V_89 ? 1 : 0 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_75 ;
V_11 = F_22 ( V_43 , 10 , & V_75 ) ;
if ( V_11 )
return V_11 ;
if ( V_75 )
V_7 -> V_23 |= V_89 ;
else
V_7 -> V_23 &= ~ V_89 ;
return V_44 ;
}
static int F_56 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
F_30 ( V_30 ,
L_22
L_23
L_24 ,
F_29 ( & V_7 -> V_90 ) ,
F_29 ( & V_7 -> V_91 ) ,
F_29 ( & V_7 -> V_92 ) ) ;
return 0 ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_23 & V_93 ? 1 : 0 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_75 ;
V_11 = F_22 ( V_43 , 10 , & V_75 ) ;
if ( V_11 )
return V_11 ;
if ( V_75 )
V_7 -> V_23 |= V_93 ;
else
V_7 -> V_23 &= ~ V_93 ;
return V_44 ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_94 ;
int V_11 ;
V_11 = F_60 ( V_7 , & V_94 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_94 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
unsigned int V_94 ;
int V_11 ;
V_11 = F_62 ( V_7 , & V_94 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_5 , L_1 , V_94 ) ;
}
static int F_63 ( struct V_29 * V_30 , void * V_31 )
{
const char * V_95 [] = V_96 ;
struct V_32 * V_33 = V_30 -> V_34 ;
int V_97 = F_16 ( V_33 ) -> V_23 ;
int V_98 = 0 ;
while ( V_97 != 0 ) {
if ( F_64 ( V_95 ) <= V_98 ) {
F_23 ( L_25 ,
F_35 ( V_33 , NULL , 0 ) ) ;
return - V_65 ;
}
if ( V_97 & 0x1 )
F_30 ( V_30 , L_26 , V_95 [ V_98 ] ) ;
V_97 >>= 1 ;
++ V_98 ;
}
F_30 ( V_30 , L_27 ) ;
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_99 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_43 ,
T_4 V_44 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
int V_11 ;
unsigned long V_75 ;
V_11 = F_22 ( V_43 , 10 , & V_75 ) ;
if ( V_11 )
return V_11 ;
if ( V_75 != 0 && V_75 != 1 )
return - V_46 ;
if ( V_75 == 1 && ! ( V_7 -> V_23 & V_100 ) )
return - V_101 ;
V_7 -> V_99 = V_75 ;
return V_44 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
F_68 ( & V_7 -> V_102 ) ;
}
void F_69 ( struct V_6 * V_7 , int V_103 , int V_44 )
{
if ( ! V_7 -> V_83 )
return;
if ( V_7 -> V_79 == V_81 )
F_70 ( V_7 -> V_83 , V_103 , V_44 ) ;
else if ( V_7 -> V_79 == V_84 &&
V_7 -> V_80 == V_104 -> V_82 )
F_70 ( V_7 -> V_83 , V_103 , V_44 ) ;
else if ( V_7 -> V_79 == V_85 &&
V_7 -> V_80 == V_104 -> V_105 -> V_82 )
F_70 ( V_7 -> V_83 , V_103 , V_44 ) ;
else if ( V_7 -> V_79 == V_86 &&
V_7 -> V_80 ==
F_71 ( & V_106 , F_72 () ) )
F_70 ( V_7 -> V_83 , V_103 , V_44 ) ;
}
int F_73 ( struct V_107 * V_108 ,
struct V_32 * V_33 , char * V_109 , char * V_110 )
{
struct V_111 * V_112 = F_74 ( V_33 ) ;
struct V_6 * V_7 = F_16 ( V_33 ) ;
struct V_113 * V_114 ;
struct V_107 * V_115 ;
char V_26 [ V_116 + 1 ] , * V_117 ;
int V_118 , V_119 , V_120 , V_11 ;
V_26 [ V_116 ] = '\0' ;
F_75 ( V_7 != NULL ) ;
F_75 ( V_110 != NULL ) ;
F_75 ( V_109 != NULL ) ;
V_120 = strlen ( V_112 -> V_121 -> V_122 ) ;
V_117 = strrchr ( V_112 -> V_121 -> V_122 , '-' ) ;
if ( V_117 && ( strcmp ( V_117 , L_28 ) == 0 ) )
V_120 -= 7 ;
snprintf ( V_26 , V_116 , L_29 , V_120 ,
V_112 -> V_121 -> V_122 , V_33 ) ;
V_115 = F_76 ( V_26 , V_108 , NULL , NULL ) ;
if ( F_77 ( V_115 ) ) {
V_118 = V_115 ? F_78 ( V_115 ) : - V_123 ;
V_7 -> V_124 = NULL ;
return V_118 ;
}
V_7 -> V_124 = V_115 ;
V_11 = F_79 ( V_7 -> V_124 , L_30 , 0444 ,
& V_125 , V_7 ) ;
if ( V_11 )
F_42 ( L_31 ) ;
V_11 = F_79 ( V_7 -> V_124 , L_32 , 0644 ,
& V_126 , V_7 ) ;
if ( V_11 )
F_42 ( L_33 ) ;
V_11 = F_79 ( V_7 -> V_124 ,
L_34 ,
0644 , & V_127 , V_7 ) ;
if ( V_11 )
F_42 ( L_35 ) ;
V_11 = F_79 ( V_7 -> V_124 , L_36 , 0644 ,
& V_128 , V_7 ) ;
if ( V_11 )
F_42 ( L_37 ) ;
V_7 -> V_83 = F_80 ( V_129 ,
V_130 ) ;
if ( V_7 -> V_83 == NULL ) {
V_118 = - V_123 ;
goto V_67;
}
for ( V_119 = 0 ; V_119 < V_129 ; V_119 ++ ) {
T_2 type = V_131 [ V_119 ] . type ;
void * V_117 = NULL ;
if ( type & V_132 )
V_117 = L_38 ;
else if ( type & V_133 )
V_117 = L_39 ;
else if ( type & V_134 )
V_117 = L_40 ;
F_81 ( V_7 -> V_83 ,
V_131 [ V_119 ] . V_135 ,
( type & V_136 ) ,
V_131 [ V_119 ] . V_137 , V_117 ) ;
}
V_118 = F_82 ( V_7 -> V_124 , L_41 ,
V_7 -> V_83 ) ;
if ( V_118 )
goto V_67;
V_7 -> V_138 = F_80 ( F_64 ( V_139 ) ,
V_130 ) ;
if ( V_7 -> V_138 == NULL ) {
V_118 = - V_123 ;
goto V_67;
}
for ( V_119 = 0 ; V_119 < F_64 ( V_139 ) ; V_119 ++ )
F_81 ( V_7 -> V_138 , V_119 , 0 ,
V_139 [ V_119 ] , L_40 ) ;
V_118 = F_82 ( V_7 -> V_124 , L_42 ,
V_7 -> V_138 ) ;
if ( V_118 )
goto V_67;
V_118 = F_83 ( V_7 -> V_124 ,
V_140 , V_33 ) ;
if ( V_118 )
goto V_67;
V_7 -> V_8 . V_141 = V_142 ;
F_84 ( & V_7 -> V_102 ) ;
V_118 = F_85 ( & V_7 -> V_8 , & V_143 , NULL ,
L_43 , V_26 ) ;
if ( V_118 )
goto V_67;
V_114 = F_86 ( V_110 ) ;
V_118 = F_87 ( & V_7 -> V_8 , & V_114 -> V_144 ,
V_114 -> V_145 -> V_146 ) ;
if ( V_118 )
goto V_67;
V_114 = F_86 ( V_109 ) ;
V_118 = F_87 ( & V_7 -> V_8 , & V_114 -> V_144 ,
V_114 -> V_145 -> V_146 ) ;
V_67:
if ( V_118 ) {
F_88 ( & V_7 -> V_124 ) ;
F_89 ( & V_7 -> V_138 ) ;
F_89 ( & V_7 -> V_83 ) ;
}
return V_118 ;
}
void F_90 ( struct V_6 * V_7 )
{
if ( V_7 -> V_124 ) {
F_88 ( & V_7 -> V_124 ) ;
F_91 ( & V_7 -> V_8 ) ;
F_92 ( & V_7 -> V_102 ) ;
F_89 ( & V_7 -> V_138 ) ;
F_89 ( & V_7 -> V_83 ) ;
}
}
static void F_93 ( struct V_147 * V_148 ,
struct V_29 * V_149 , int V_150 )
{
unsigned long V_151 = 0 , V_152 = 0 , V_153 , V_154 ;
unsigned long V_155 , V_156 , V_157 , V_158 ;
char * V_159 = L_44 ;
int V_98 , V_160 = 10 ;
struct V_161 * V_162 = & V_148 -> V_163 [ V_150 ] ;
V_153 = 0 ;
V_154 = 0 ;
V_155 = 0 ;
for ( V_98 = 0 ; V_98 < V_164 ; V_98 ++ ) {
V_151 += V_162 -> V_165 . V_166 [ V_98 ] ;
V_152 += V_162 -> V_167 . V_166 [ V_98 ] ;
}
for ( V_98 = 0 ; V_98 < V_164 ; V_98 ++ ) {
V_157 = V_162 -> V_165 . V_166 [ V_98 ] ;
V_158 = V_162 -> V_167 . V_166 [ V_98 ] ;
V_153 += V_157 ;
V_154 += V_158 ;
V_156 = 1 << ( V_98 + V_168 - V_160 ) ;
F_30 ( V_149 , L_45 ,
V_155 , * V_159 , V_156 , * V_159 ,
( V_98 == V_164 - 1 ) ? '+' : ' ' ,
V_157 , F_94 ( V_157 , V_151 ) , F_94 ( V_153 , V_151 ) ,
V_158 , F_94 ( V_158 , V_152 ) , F_94 ( V_154 , V_152 ) ) ;
V_155 = V_156 ;
if ( V_155 == 1 << 10 ) {
V_155 = 1 ;
V_160 += 10 ;
V_159 ++ ;
}
if ( V_153 == V_151 && V_154 == V_152 )
break;
}
}
static int F_95 ( struct V_29 * V_149 , void * V_31 )
{
struct V_169 V_170 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_147 * V_148 = & V_7 -> V_147 ;
int V_171 ;
F_96 ( & V_170 ) ;
if ( ! V_7 -> V_172 ) {
F_30 ( V_149 , L_46
L_47 ) ;
return 0 ;
}
F_30 ( V_149 , L_48 ,
( V_173 ) V_170 . V_174 , ( unsigned long ) V_170 . V_175 ) ;
F_30 ( V_149 , L_49 , L_50 , L_51 , L_52 ) ;
F_30 ( V_149 , L_53 ,
L_54 , L_55 , L_56 , L_57 ,
L_55 , L_56 , L_57 ) ;
F_18 ( & V_7 -> V_176 ) ;
for ( V_171 = 0 ; V_171 < V_177 ; V_171 ++ ) {
if ( V_148 -> V_163 [ V_171 ] . V_82 != 0 ) {
F_30 ( V_149 , L_58 ,
V_148 -> V_163 [ V_171 ] . V_82 ) ;
F_93 ( V_148 , V_149 , V_171 ) ;
}
}
F_19 ( & V_7 -> V_176 ) ;
return 0 ;
}
static T_1 F_97 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_120 ,
T_6 * V_60 )
{
struct V_29 * V_149 = V_59 -> V_61 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_147 * V_148 = & V_7 -> V_147 ;
int V_98 ;
int V_178 = 1 , V_11 = 0 ;
if ( V_120 == 0 )
return - V_65 ;
V_11 = F_98 ( V_5 , V_120 , & V_178 ) ;
if ( V_11 < 0 && V_120 < 16 ) {
char V_64 [ 16 ] ;
if ( F_32 ( V_64 , V_5 , V_120 ) )
return - V_66 ;
V_64 [ V_120 ] = 0 ;
if ( V_64 [ V_120 - 1 ] == '\n' )
V_64 [ V_120 - 1 ] = 0 ;
if ( strcmp ( V_64 , L_59 ) == 0 ||
strcmp ( V_64 , L_60 ) == 0 )
V_178 = 0 ;
}
if ( V_178 == 0 )
V_7 -> V_172 = 0 ;
else
V_7 -> V_172 = 1 ;
F_18 ( & V_7 -> V_176 ) ;
for ( V_98 = 0 ; V_98 < V_177 ; V_98 ++ ) {
V_148 -> V_163 [ V_98 ] . V_82 = 0 ;
F_99 ( & V_148 -> V_163 [ V_98 ] . V_165 ) ;
F_99 ( & V_148 -> V_163 [ V_98 ] . V_167 ) ;
}
F_19 ( & V_7 -> V_176 ) ;
return V_120 ;
}
static int F_100 ( struct V_29 * V_149 , void * V_31 )
{
struct V_169 V_170 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_147 * V_148 = & V_7 -> V_147 ;
F_96 ( & V_170 ) ;
if ( ! V_7 -> V_172 ) {
F_30 ( V_149 , L_46
L_47 ) ;
return 0 ;
}
F_30 ( V_149 , L_48 ,
( V_179 ) V_170 . V_174 , ( unsigned long ) V_170 . V_175 ) ;
F_30 ( V_149 , L_49 , L_50 , L_51 , L_52 ) ;
F_30 ( V_149 , L_53 ,
L_54 , L_55 , L_56 , L_57 ,
L_55 , L_56 , L_57 ) ;
F_18 ( & V_7 -> V_38 ) ;
F_93 ( V_148 , V_149 , V_177 ) ;
F_19 ( & V_7 -> V_38 ) ;
return 0 ;
}
static T_1 F_101 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_120 , T_6 * V_60 )
{
struct V_29 * V_149 = V_59 -> V_61 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_147 * V_148 = & V_7 -> V_147 ;
int V_98 ;
int V_178 = 1 , V_11 = 0 ;
if ( V_120 == 0 )
return - V_65 ;
V_11 = F_98 ( V_5 , V_120 , & V_178 ) ;
if ( V_11 < 0 && V_120 < 16 ) {
char V_64 [ 16 ] ;
if ( F_32 ( V_64 , V_5 , V_120 ) )
return - V_66 ;
V_64 [ V_120 ] = 0 ;
if ( V_64 [ V_120 - 1 ] == '\n' )
V_64 [ V_120 - 1 ] = 0 ;
if ( strcmp ( V_64 , L_59 ) == 0 ||
strcmp ( V_64 , L_60 ) == 0 )
V_178 = 0 ;
}
if ( V_178 == 0 )
V_7 -> V_172 = 0 ;
else
V_7 -> V_172 = 1 ;
F_18 ( & V_7 -> V_176 ) ;
for ( V_98 = 0 ; V_98 <= V_177 ; V_98 ++ ) {
V_148 -> V_163 [ V_98 ] . V_82 = 0 ;
F_99 ( & V_148 -> V_163 [ V_98 ] . V_165 ) ;
F_99 ( & V_148 -> V_163 [ V_98 ] . V_167 ) ;
}
F_19 ( & V_7 -> V_176 ) ;
return V_120 ;
}
void F_102 ( struct V_6 * V_7 , T_7 V_82 ,
struct V_180 * V_59 , T_6 V_181 ,
T_4 V_44 , int V_182 )
{
int V_98 , V_183 = - 1 ;
struct V_184 * V_185 ;
struct V_184 * V_186 ;
int * V_187 = & V_7 -> V_188 ;
int * V_189 = & V_7 -> V_190 ;
struct V_147 * V_148 = & V_7 -> V_147 ;
if ( ! V_7 -> V_172 )
return;
V_185 = V_7 -> V_184 ;
V_186 = V_7 -> V_191 ;
F_18 ( & V_7 -> V_176 ) ;
for ( V_98 = 0 ; V_98 < V_177 ; V_98 ++ ) {
if ( V_148 -> V_163 [ V_98 ] . V_82 == V_82 ) {
V_183 = V_98 ;
break;
}
}
if ( V_183 == - 1 ) {
V_7 -> V_192 =
( V_7 -> V_192 + 1 ) % V_177 ;
V_183 = V_7 -> V_192 ;
V_148 -> V_163 [ V_183 ] . V_82 = V_82 ;
F_99 ( & V_148 -> V_163 [ V_183 ] . V_165 ) ;
F_99 ( & V_148 -> V_163 [ V_183 ] . V_167 ) ;
}
for ( V_98 = 0 ; ( V_44 >= ( 1 << V_168 << V_98 ) ) &&
( V_98 < ( V_164 - 1 ) ) ; V_98 ++ )
;
if ( V_182 == 0 ) {
V_148 -> V_163 [ V_183 ] . V_165 . V_166 [ V_98 ] ++ ;
V_148 -> V_163 [ V_177 ] . V_165 . V_166 [ V_98 ] ++ ;
} else {
V_148 -> V_163 [ V_183 ] . V_167 . V_166 [ V_98 ] ++ ;
V_148 -> V_163 [ V_177 ] . V_167 . V_166 [ V_98 ] ++ ;
}
F_19 ( & V_7 -> V_176 ) ;
F_18 ( & V_7 -> V_193 ) ;
for ( V_98 = 0 ; V_98 < V_177 ; V_98 ++ ) {
if ( V_185 [ V_98 ] . V_194 == V_82 ) {
if ( V_185 [ V_98 ] . V_195 != V_59 ) {
V_185 [ V_98 ] . V_196 = V_181 ;
V_185 [ V_98 ] . V_197 = V_181 + V_44 ;
V_185 [ V_98 ] . V_198 = V_44 ;
V_185 [ V_98 ] . V_199 = V_44 ;
V_185 [ V_98 ] . V_200 = 0 ;
V_185 [ V_98 ] . V_195 = V_59 ;
F_19 ( & V_7 -> V_193 ) ;
return;
}
if ( V_185 [ V_98 ] . V_197 != V_181 ) {
* V_187 =
( * V_187 + 1 ) % V_201 ;
V_186 [ * V_187 ] . V_202 = V_185 [ V_98 ] . V_202 ;
V_186 [ * V_187 ] . V_194 = V_82 ;
V_186 [ * V_187 ] . V_196 =
V_185 [ V_98 ] . V_196 ;
V_186 [ * V_187 ] . V_203 =
V_185 [ V_98 ] . V_197 ;
V_186 [ * V_187 ] . V_198 =
V_185 [ V_98 ] . V_198 ;
V_186 [ * V_187 ] . V_199 =
V_185 [ V_98 ] . V_199 ;
V_186 [ * V_187 ] . V_200 =
V_185 [ V_98 ] . V_200 ;
V_185 [ V_98 ] . V_202 = V_182 ;
V_185 [ V_98 ] . V_196 = V_181 ;
V_185 [ V_98 ] . V_198 = V_44 ;
V_185 [ V_98 ] . V_199 = V_44 ;
V_185 [ V_98 ] . V_200 = V_181 -
V_185 [ V_98 ] . V_197 ;
}
if ( V_185 [ V_98 ] . V_198 > V_44 )
V_185 [ V_98 ] . V_198 = V_44 ;
if ( V_185 [ V_98 ] . V_199 < V_44 )
V_185 [ V_98 ] . V_199 = V_44 ;
V_185 [ V_98 ] . V_197 = V_181 + V_44 ;
F_19 ( & V_7 -> V_193 ) ;
return;
}
}
* V_189 = ( * V_189 + 1 ) % V_177 ;
V_185 [ * V_189 ] . V_194 = V_82 ;
V_185 [ * V_189 ] . V_202 = V_182 ;
V_185 [ * V_189 ] . V_196 = V_181 ;
V_185 [ * V_189 ] . V_197 = V_181 + V_44 ;
V_185 [ * V_189 ] . V_198 = V_44 ;
V_185 [ * V_189 ] . V_199 = V_44 ;
V_185 [ * V_189 ] . V_200 = 0 ;
V_185 [ * V_189 ] . V_195 = V_59 ;
F_19 ( & V_7 -> V_193 ) ;
}
static int F_103 ( struct V_29 * V_149 , void * V_31 )
{
struct V_169 V_170 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_184 * V_186 = V_7 -> V_191 ;
struct V_184 * V_185 = V_7 -> V_184 ;
int V_98 ;
F_96 ( & V_170 ) ;
if ( ! V_7 -> V_172 ) {
F_30 ( V_149 , L_46
L_47 ) ;
return 0 ;
}
F_18 ( & V_7 -> V_193 ) ;
F_30 ( V_149 , L_48 ,
( V_173 ) V_170 . V_174 , ( unsigned long ) V_170 . V_175 ) ;
F_30 ( V_149 , L_61 ,
L_62 , L_63 , L_64 , L_65 ,
L_66 , L_67 , L_68 ) ;
for ( V_98 = 0 ; V_98 < V_201 ; V_98 ++ ) {
if ( V_186 [ V_98 ] . V_194 != 0 )
F_30 ( V_149 ,
L_69 ,
V_186 [ V_98 ] . V_202 == V_204 ? 'R' : 'W' ,
V_186 [ V_98 ] . V_194 ,
V_186 [ V_98 ] . V_196 ,
V_186 [ V_98 ] . V_203 ,
( unsigned long ) V_186 [ V_98 ] . V_198 ,
( unsigned long ) V_186 [ V_98 ] . V_199 ,
V_186 [ V_98 ] . V_200 ) ;
}
for ( V_98 = 0 ; V_98 < V_177 ; V_98 ++ ) {
if ( V_185 [ V_98 ] . V_194 != 0 )
F_30 ( V_149 ,
L_69 ,
V_185 [ V_98 ] . V_202 == V_204 ? 'R' : 'W' ,
V_185 [ V_98 ] . V_194 ,
V_185 [ V_98 ] . V_196 ,
V_185 [ V_98 ] . V_197 ,
( unsigned long ) V_185 [ V_98 ] . V_198 ,
( unsigned long ) V_185 [ V_98 ] . V_199 ,
V_185 [ V_98 ] . V_200 ) ;
}
F_19 ( & V_7 -> V_193 ) ;
return 0 ;
}
static T_1 F_104 ( struct V_59 * V_59 ,
const char T_5 * V_5 ,
T_4 V_120 , T_6 * V_60 )
{
struct V_29 * V_149 = V_59 -> V_61 ;
struct V_6 * V_7 = V_149 -> V_34 ;
struct V_184 * V_205 = V_7 -> V_184 ;
struct V_184 * V_206 = V_7 -> V_191 ;
int V_178 = 1 , V_11 = 0 ;
if ( V_120 == 0 )
return - V_65 ;
V_11 = F_98 ( V_5 , V_120 , & V_178 ) ;
if ( V_11 < 0 && V_120 < 16 ) {
char V_64 [ 16 ] ;
if ( F_32 ( V_64 , V_5 , V_120 ) )
return - V_66 ;
V_64 [ V_120 ] = 0 ;
if ( V_64 [ V_120 - 1 ] == '\n' )
V_64 [ V_120 - 1 ] = 0 ;
if ( strcmp ( V_64 , L_59 ) == 0 ||
strcmp ( V_64 , L_60 ) == 0 )
V_178 = 0 ;
}
if ( V_178 == 0 )
V_7 -> V_172 = 0 ;
else
V_7 -> V_172 = 1 ;
F_18 ( & V_7 -> V_193 ) ;
V_7 -> V_190 = 0 ;
V_7 -> V_188 = 0 ;
memset ( V_205 , 0 , sizeof( struct V_184 ) *
V_177 ) ;
memset ( V_206 , 0 , sizeof( struct V_184 ) *
V_201 ) ;
F_19 ( & V_7 -> V_193 ) ;
return V_120 ;
}
void F_105 ( struct V_207 * V_208 )
{
V_208 -> V_209 = V_140 ;
}
