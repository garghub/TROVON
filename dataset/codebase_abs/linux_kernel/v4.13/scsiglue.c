static const char * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_2 ) ;
V_7 -> V_8 = 36 ;
F_4 ( V_7 -> V_9 , ( 512 - 1 ) ) ;
if ( V_4 -> V_10 == V_11 && V_4 -> V_12 > 0 )
V_7 -> V_13 |= V_14 ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_7 -> V_2 ) ;
if ( V_4 -> V_15 & ( V_16 | V_17 ) ) {
unsigned int V_18 = 64 ;
if ( V_4 -> V_15 & V_17 )
V_18 = V_19 >> 9 ;
if ( F_6 ( V_7 -> V_9 ) > V_18 )
F_7 ( V_7 -> V_9 ,
V_18 ) ;
} else if ( V_7 -> type == V_20 ) {
F_7 ( V_7 -> V_9 , 0x7FFFFF ) ;
} else if ( V_4 -> V_21 -> V_22 >= V_23 ) {
F_7 ( V_7 -> V_9 , 2048 ) ;
}
if ( ! V_4 -> V_21 -> V_24 -> V_25 -> V_26 )
F_8 ( V_7 -> V_9 , V_27 ) ;
if ( V_7 -> type == V_28 ) {
switch ( F_9 ( V_4 -> V_21 -> V_29 . V_30 ) ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
if ( ! ( V_4 -> V_15 & ( V_35 |
V_36 ) ) )
V_4 -> V_15 |= V_37 ;
break;
}
if ( V_4 -> V_38 != V_39 && V_4 -> V_38 != V_40 )
V_7 -> V_41 = 1 ;
V_7 -> V_42 = 1 ;
if ( V_4 -> V_15 & V_43 )
V_7 -> V_44 = 1 ;
V_7 -> V_45 = 1 ;
V_7 -> V_46 = 1 ;
V_7 -> V_47 = 1 ;
V_7 -> V_48 = 1 ;
if ( V_4 -> V_15 & V_35 )
V_7 -> V_49 = 1 ;
if ( V_4 -> V_15 & V_37 )
V_7 -> V_50 = 1 ;
if ( V_4 -> V_15 & V_51 )
V_7 -> V_52 = 1 ;
if ( ! ( V_4 -> V_15 & V_53 ) )
V_7 -> V_54 = 1 ;
if ( V_7 -> V_55 > V_56 )
V_4 -> V_15 |= V_57 ;
V_7 -> V_58 = 1 ;
V_7 -> V_59 = 1 ;
V_7 -> V_60 = 1 ;
if ( ! ( V_4 -> V_15 & ( V_35 | V_36 |
V_61 ) ) &&
V_4 -> V_10 == V_11 )
V_4 -> V_62 = 1 ;
if ( V_4 -> V_15 & V_63 )
V_7 -> V_64 = 1 ;
if ( V_4 -> V_15 & V_65 )
V_7 -> V_66 = 1 ;
if ( V_4 -> V_15 & V_67 ) {
V_7 -> V_45 = 1 ;
V_7 -> V_44 = 1 ;
V_7 -> V_64 = 1 ;
}
} else {
V_7 -> V_41 = 1 ;
if ( V_4 -> V_15 & V_68 )
V_7 -> V_69 = 1 ;
}
if ( ( V_4 -> V_10 == V_70 || V_4 -> V_10 == V_71 ) &&
V_7 -> V_55 == V_72 )
V_4 -> V_12 = 0 ;
if ( V_4 -> V_15 & V_73 )
V_7 -> V_74 = 0 ;
return 0 ;
}
static int F_10 ( struct V_75 * V_76 )
{
struct V_3 * V_4 = F_2 ( F_11 ( V_76 -> V_77 . V_78 ) ) ;
V_76 -> V_79 = 1 ;
if ( V_4 -> V_38 == V_80 )
V_76 -> V_81 = 1 ;
return 0 ;
}
static int F_12 ( struct V_82 * V_83 ,
void (* F_13)( struct V_82 * ) )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_84 -> V_2 ) ;
if ( V_4 -> V_83 != NULL ) {
F_14 (KERN_ERR USB_STORAGE L_1 ,
__func__, us->srb) ;
return V_85 ;
}
if ( F_15 ( V_86 , & V_4 -> V_87 ) ) {
F_16 ( V_4 , L_2 ) ;
V_83 -> V_88 = V_89 << 16 ;
F_13 ( V_83 ) ;
return 0 ;
}
V_83 -> V_90 = F_13 ;
V_4 -> V_83 = V_83 ;
F_17 ( & V_4 -> V_91 ) ;
return 0 ;
}
int F_18 ( struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_84 -> V_2 ) ;
int V_88 ;
F_16 ( V_4 , L_3 , V_92 ) ;
F_19 ( & ( V_4 -> V_93 ) ) ;
V_88 = V_4 -> V_94 ( V_4 ) ;
F_20 ( & V_4 -> V_93 ) ;
return V_88 < 0 ? V_95 : V_96 ;
}
static int F_21 ( struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_84 -> V_2 ) ;
int V_88 ;
F_16 ( V_4 , L_3 , V_92 ) ;
V_88 = F_22 ( V_4 ) ;
return V_88 < 0 ? V_95 : V_96 ;
}
void F_23 ( struct V_3 * V_4 )
{
int V_97 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
F_25 ( V_2 , 0 , 0 ) ;
if ( V_4 -> V_15 & V_61 ) {
for ( V_97 = 1 ; V_97 < V_2 -> V_98 ; ++ V_97 )
F_25 ( V_2 , 0 , V_97 ) ;
}
}
void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 , 0 ) ;
F_29 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , char * V_99 , int V_100 )
{
return V_100 ;
}
static int F_31 ( struct V_101 * V_102 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * string ;
F_32 ( V_102 , L_4 , V_2 -> V_103 ) ;
if ( V_4 -> V_21 -> V_104 )
string = V_4 -> V_21 -> V_104 ;
else if ( V_4 -> V_105 -> V_106 )
string = V_4 -> V_105 -> V_106 ;
else
string = L_5 ;
F_32 ( V_102 , L_6 , string ) ;
if ( V_4 -> V_21 -> V_107 )
string = V_4 -> V_21 -> V_107 ;
else if ( V_4 -> V_105 -> V_108 )
string = V_4 -> V_105 -> V_108 ;
else
string = L_5 ;
F_32 ( V_102 , L_7 , string ) ;
if ( V_4 -> V_21 -> V_109 )
string = V_4 -> V_21 -> V_109 ;
else
string = L_8 ;
F_32 ( V_102 , L_9 , string ) ;
F_32 ( V_102 , L_10 , V_4 -> V_110 ) ;
F_32 ( V_102 , L_11 , V_4 -> V_111 ) ;
F_32 ( V_102 , L_12 ) ;
#define F_33 ( T_1 , T_2 ) \
if (us->fflags & value) seq_printf(m, " " #name);
T_3
#undef F_33
V_112 ( V_102 , '\n' ) ;
return 0 ;
}
static T_4 F_34 ( struct V_84 * V_77 , struct V_113 * V_114 , char * V_115 )
{
struct V_6 * V_7 = F_35 ( V_77 ) ;
return sprintf ( V_115 , L_13 , F_6 ( V_7 -> V_9 ) ) ;
}
static T_4 F_36 ( struct V_84 * V_77 , struct V_113 * V_114 , const char * V_115 ,
T_5 V_116 )
{
struct V_6 * V_7 = F_35 ( V_77 ) ;
unsigned short V_117 ;
if ( sscanf ( V_115 , L_14 , & V_117 ) > 0 ) {
F_7 ( V_7 -> V_9 , V_117 ) ;
return V_116 ;
}
return - V_118 ;
}
void F_37 ( struct V_119 * V_120 ,
const char * T_1 , struct V_121 * V_122 )
{
* V_120 = V_123 ;
V_120 -> T_1 = T_1 ;
V_120 -> V_124 = T_1 ;
V_120 -> V_121 = V_122 ;
}
