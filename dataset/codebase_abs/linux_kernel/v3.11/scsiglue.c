static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_2 ) ;
V_4 -> V_7 = 36 ;
F_4 ( V_4 -> V_8 , ( 512 - 1 ) ) ;
if ( V_6 -> V_9 == V_10 )
V_4 -> V_11 -> V_12 = 1 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 -> V_2 ) ;
if ( V_6 -> V_13 & ( V_14 | V_15 ) ) {
unsigned int V_16 = 64 ;
if ( V_6 -> V_13 & V_15 )
V_16 = V_17 >> 9 ;
if ( F_6 ( V_4 -> V_8 ) > V_16 )
F_7 ( V_4 -> V_8 ,
V_16 ) ;
}
if ( V_4 -> type == V_18 ) {
if ( V_6 -> V_9 != V_19 &&
V_6 -> V_9 != V_20 )
V_4 -> V_21 = 1 ;
V_4 -> V_22 = 1 ;
if ( V_6 -> V_13 & V_23 )
V_4 -> V_24 = 1 ;
V_4 -> V_25 = 1 ;
if ( V_6 -> V_13 & V_26 )
V_4 -> V_27 = 1 ;
if ( V_6 -> V_13 & V_28 )
V_4 -> V_29 = 1 ;
if ( V_4 -> V_30 > V_31 )
V_4 -> V_11 -> V_30 = V_4 -> V_30
= V_31 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = 1 ;
} else {
V_4 -> V_21 = 1 ;
}
if ( ( V_6 -> V_35 == V_36 || V_6 -> V_35 == V_37 ) &&
V_4 -> V_30 == V_38 )
V_6 -> V_39 = 0 ;
if ( V_6 -> V_13 & V_40 )
V_4 -> V_41 = 0 ;
return 0 ;
}
static int F_8 ( struct V_42 * V_43 ,
void (* F_9)( struct V_42 * ) )
{
struct V_5 * V_6 = F_3 ( V_43 -> V_44 -> V_2 ) ;
if ( V_6 -> V_43 != NULL ) {
return V_45 ;
}
if ( F_10 ( V_46 , & V_6 -> V_47 ) ) {
F_11 ( L_2 ) ;
V_43 -> V_48 = V_49 << 16 ;
F_9 ( V_43 ) ;
return 0 ;
}
V_43 -> V_50 = F_9 ;
V_6 -> V_43 = V_43 ;
F_12 ( & V_6 -> V_51 ) ;
return 0 ;
}
int F_13 ( struct V_42 * V_43 )
{
struct V_5 * V_6 = F_3 ( V_43 -> V_44 -> V_2 ) ;
int V_48 ;
F_14 ( & ( V_6 -> V_52 ) ) ;
V_48 = V_6 -> V_53 ( V_6 ) ;
F_15 ( & V_6 -> V_52 ) ;
return V_48 < 0 ? V_54 : V_55 ;
}
static int F_16 ( struct V_42 * V_43 )
{
struct V_5 * V_6 = F_3 ( V_43 -> V_44 -> V_2 ) ;
int V_48 ;
V_48 = F_17 ( V_6 ) ;
return V_48 < 0 ? V_54 : V_55 ;
}
void F_18 ( struct V_5 * V_6 )
{
int V_56 ;
struct V_1 * V_2 = F_19 ( V_6 ) ;
F_20 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_13 & V_57 ) {
for ( V_56 = 1 ; V_56 < V_2 -> V_58 ; ++ V_56 )
F_20 ( V_2 , 0 , V_56 ) ;
}
}
void F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_19 ( V_6 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , char * V_59 , int V_60 )
{
return V_60 ;
}
static int F_26 ( struct V_61 * V_62 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
const char * string ;
SPRINTF ( L_3 , V_2 -> V_63 ) ;
if ( V_6 -> V_64 -> V_65 )
string = V_6 -> V_64 -> V_65 ;
else if ( V_6 -> V_66 -> V_67 )
string = V_6 -> V_66 -> V_67 ;
else
string = L_4 ;
SPRINTF ( L_5 , string ) ;
if ( V_6 -> V_64 -> V_68 )
string = V_6 -> V_64 -> V_68 ;
else if ( V_6 -> V_66 -> V_69 )
string = V_6 -> V_66 -> V_69 ;
else
string = L_4 ;
SPRINTF ( L_6 , string ) ;
if ( V_6 -> V_64 -> V_70 )
string = V_6 -> V_64 -> V_70 ;
else
string = L_7 ;
SPRINTF ( L_8 , string ) ;
SPRINTF ( L_9 , V_6 -> V_71 ) ;
SPRINTF ( L_10 , V_6 -> V_72 ) ;
SPRINTF ( L_11 ) ;
#define F_27 ( T_1 , T_2 ) \
do { \
if (us->fflags & value) \
SPRINTF(" " #name); \
} while (0);
T_3
#undef F_27
V_73 ( V_62 , '\n' ) ;
return 0 ;
}
static T_4 F_28 ( struct V_44 * V_74 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_3 * V_4 = F_29 ( V_74 ) ;
return sprintf ( V_77 , L_12 , F_6 ( V_4 -> V_8 ) ) ;
}
static T_4 F_30 ( struct V_44 * V_74 ,
struct V_75 * V_76 ,
const char * V_77 , T_5 V_78 )
{
struct V_3 * V_4 = F_29 ( V_74 ) ;
unsigned short V_79 ;
if ( sscanf ( V_77 , L_13 , & V_79 ) > 0 && V_79 <= V_80 ) {
F_7 ( V_4 -> V_8 , V_79 ) ;
return strlen ( V_77 ) ;
}
return - V_81 ;
}
unsigned int F_31 ( struct V_5 * V_6 ,
unsigned char * V_59 , unsigned int V_82 ,
struct V_42 * V_43 , struct V_83 * * V_84 ,
unsigned int * V_85 , enum V_86 V_87 )
{
unsigned int V_88 ;
struct V_83 * V_89 = * V_84 ;
if ( ! V_89 )
V_89 = F_32 ( V_43 ) ;
V_88 = 0 ;
while ( V_88 < V_82 && V_89 ) {
struct V_90 * V_90 = F_33 ( V_89 ) +
( ( V_89 -> V_85 + * V_85 ) >> V_91 ) ;
unsigned int V_92 = ( V_89 -> V_85 + * V_85 ) & ( V_93 - 1 ) ;
unsigned int V_94 = V_89 -> V_60 - * V_85 ;
if ( V_94 > V_82 - V_88 ) {
V_94 = V_82 - V_88 ;
* V_85 += V_94 ;
} else {
* V_85 = 0 ;
V_89 = F_34 ( V_89 ) ;
}
while ( V_94 > 0 ) {
unsigned int V_95 = F_35 ( V_94 ,
( unsigned int ) V_93 - V_92 ) ;
unsigned char * V_96 = F_36 ( V_90 ) ;
if ( V_87 == V_97 )
memcpy ( V_96 + V_92 , V_59 + V_88 , V_95 ) ;
else
memcpy ( V_59 + V_88 , V_96 + V_92 , V_95 ) ;
F_37 ( V_90 ) ;
V_92 = 0 ;
++ V_90 ;
V_88 += V_95 ;
V_94 -= V_95 ;
}
}
* V_84 = V_89 ;
return V_88 ;
}
void F_38 ( struct V_5 * V_6 , unsigned char * V_59 ,
unsigned int V_82 , struct V_42 * V_43 , unsigned int V_87 )
{
unsigned int V_85 = 0 ;
struct V_83 * V_89 = NULL ;
V_82 = F_35 ( V_82 , F_39 ( V_43 ) ) ;
V_82 = F_31 ( V_6 , V_59 , V_82 , V_43 ,
& V_89 , & V_85 , V_87 ) ;
if ( V_82 < F_39 ( V_43 ) )
F_40 ( V_43 , F_39 ( V_43 ) - V_82 ) ;
}
