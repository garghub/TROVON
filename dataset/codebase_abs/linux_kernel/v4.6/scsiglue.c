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
}
if ( ! V_4 -> V_21 -> V_22 -> V_23 -> V_24 )
F_8 ( V_7 -> V_9 , V_25 ) ;
if ( V_7 -> type == V_26 ) {
switch ( F_9 ( V_4 -> V_21 -> V_27 . V_28 ) ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
if ( ! ( V_4 -> V_15 & ( V_33 |
V_34 ) ) )
V_4 -> V_15 |= V_35 ;
break;
}
if ( V_4 -> V_36 != V_37 && V_4 -> V_36 != V_38 )
V_7 -> V_39 = 1 ;
V_7 -> V_40 = 1 ;
if ( V_4 -> V_15 & V_41 )
V_7 -> V_42 = 1 ;
V_7 -> V_43 = 1 ;
V_7 -> V_44 = 1 ;
V_7 -> V_45 = 1 ;
V_7 -> V_46 = 1 ;
if ( V_4 -> V_15 & V_33 )
V_7 -> V_47 = 1 ;
if ( V_4 -> V_15 & V_35 )
V_7 -> V_48 = 1 ;
if ( V_4 -> V_15 & V_49 )
V_7 -> V_50 = 1 ;
if ( ! ( V_4 -> V_15 & V_51 ) )
V_7 -> V_52 = 1 ;
if ( V_7 -> V_53 > V_54 )
V_4 -> V_15 |= V_55 ;
V_7 -> V_56 = 1 ;
V_7 -> V_57 = 1 ;
V_7 -> V_58 = 1 ;
if ( ! ( V_4 -> V_15 & ( V_33 | V_34 |
V_59 ) ) &&
V_4 -> V_10 == V_11 )
V_4 -> V_60 = 1 ;
if ( V_4 -> V_15 & V_61 )
V_7 -> V_62 = 1 ;
if ( V_4 -> V_15 & V_63 )
V_7 -> V_64 = 1 ;
} else {
V_7 -> V_39 = 1 ;
if ( V_4 -> V_15 & V_65 )
V_7 -> V_66 = 1 ;
}
if ( ( V_4 -> V_10 == V_67 || V_4 -> V_10 == V_68 ) &&
V_7 -> V_53 == V_69 )
V_4 -> V_12 = 0 ;
if ( V_4 -> V_15 & V_70 )
V_7 -> V_71 = 0 ;
return 0 ;
}
static int F_10 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_2 ( F_11 ( V_73 -> V_74 . V_75 ) ) ;
V_73 -> V_76 = 1 ;
if ( V_4 -> V_36 == V_77 )
V_73 -> V_78 = 1 ;
return 0 ;
}
static int F_12 ( struct V_79 * V_80 ,
void (* F_13)( struct V_79 * ) )
{
struct V_3 * V_4 = F_2 ( V_80 -> V_81 -> V_2 ) ;
if ( V_4 -> V_80 != NULL ) {
F_14 (KERN_ERR USB_STORAGE L_1 ,
__func__, us->srb) ;
return V_82 ;
}
if ( F_15 ( V_83 , & V_4 -> V_84 ) ) {
F_16 ( V_4 , L_2 ) ;
V_80 -> V_85 = V_86 << 16 ;
F_13 ( V_80 ) ;
return 0 ;
}
V_80 -> V_87 = F_13 ;
V_4 -> V_80 = V_80 ;
F_17 ( & V_4 -> V_88 ) ;
return 0 ;
}
int F_18 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_80 -> V_81 -> V_2 ) ;
int V_85 ;
F_16 ( V_4 , L_3 , V_89 ) ;
F_19 ( & ( V_4 -> V_90 ) ) ;
V_85 = V_4 -> V_91 ( V_4 ) ;
F_20 ( & V_4 -> V_90 ) ;
return V_85 < 0 ? V_92 : V_93 ;
}
static int F_21 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_80 -> V_81 -> V_2 ) ;
int V_85 ;
F_16 ( V_4 , L_3 , V_89 ) ;
V_85 = F_22 ( V_4 ) ;
return V_85 < 0 ? V_92 : V_93 ;
}
void F_23 ( struct V_3 * V_4 )
{
int V_94 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
F_25 ( V_2 , 0 , 0 ) ;
if ( V_4 -> V_15 & V_59 ) {
for ( V_94 = 1 ; V_94 < V_2 -> V_95 ; ++ V_94 )
F_25 ( V_2 , 0 , V_94 ) ;
}
}
void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 , 0 ) ;
F_29 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 , char * V_96 , int V_97 )
{
return V_97 ;
}
static int F_31 ( struct V_98 * V_99 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * string ;
F_32 ( V_99 , L_4 , V_2 -> V_100 ) ;
if ( V_4 -> V_21 -> V_101 )
string = V_4 -> V_21 -> V_101 ;
else if ( V_4 -> V_102 -> V_103 )
string = V_4 -> V_102 -> V_103 ;
else
string = L_5 ;
F_32 ( V_99 , L_6 , string ) ;
if ( V_4 -> V_21 -> V_104 )
string = V_4 -> V_21 -> V_104 ;
else if ( V_4 -> V_102 -> V_105 )
string = V_4 -> V_102 -> V_105 ;
else
string = L_5 ;
F_32 ( V_99 , L_7 , string ) ;
if ( V_4 -> V_21 -> V_106 )
string = V_4 -> V_21 -> V_106 ;
else
string = L_8 ;
F_32 ( V_99 , L_9 , string ) ;
F_32 ( V_99 , L_10 , V_4 -> V_107 ) ;
F_32 ( V_99 , L_11 , V_4 -> V_108 ) ;
F_32 ( V_99 , L_12 ) ;
#define F_33 ( T_1 , T_2 ) \
if (us->fflags & value) seq_printf(m, " " #name);
T_3
#undef F_33
V_109 ( V_99 , '\n' ) ;
return 0 ;
}
static T_4 F_34 ( struct V_81 * V_74 , struct V_110 * V_111 , char * V_112 )
{
struct V_6 * V_7 = F_35 ( V_74 ) ;
return sprintf ( V_112 , L_13 , F_6 ( V_7 -> V_9 ) ) ;
}
static T_4 F_36 ( struct V_81 * V_74 , struct V_110 * V_111 , const char * V_112 ,
T_5 V_113 )
{
struct V_6 * V_7 = F_35 ( V_74 ) ;
unsigned short V_114 ;
if ( sscanf ( V_112 , L_14 , & V_114 ) > 0 ) {
F_7 ( V_7 -> V_9 , V_114 ) ;
return V_113 ;
}
return - V_115 ;
}
void F_37 ( struct V_116 * V_117 ,
const char * T_1 , struct V_118 * V_119 )
{
* V_117 = V_120 ;
V_117 -> T_1 = T_1 ;
V_117 -> V_121 = T_1 ;
V_117 -> V_118 = V_119 ;
}
