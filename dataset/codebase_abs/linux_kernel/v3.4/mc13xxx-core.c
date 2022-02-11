void F_1 ( struct V_1 * V_1 )
{
if ( ! F_2 ( & V_1 -> V_2 ) ) {
F_3 ( & V_1 -> V_3 -> V_4 , L_1 ,
V_5 , F_4 ( 0 ) ) ;
F_5 ( & V_1 -> V_2 ) ;
}
F_3 ( & V_1 -> V_3 -> V_4 , L_2 ,
V_5 , F_4 ( 0 ) ) ;
}
void F_6 ( struct V_1 * V_1 )
{
F_3 ( & V_1 -> V_3 -> V_4 , L_2 ,
V_5 , F_4 ( 0 ) ) ;
F_7 ( & V_1 -> V_2 ) ;
}
int F_8 ( struct V_1 * V_1 , unsigned int V_6 , T_1 * V_7 )
{
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_12 ;
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
if ( V_6 > V_13 )
return - V_14 ;
* V_7 = V_6 << V_15 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_7 ;
V_9 . V_17 = V_7 ;
V_9 . V_18 = sizeof( T_1 ) ;
F_11 ( & V_11 ) ;
F_12 ( & V_9 , & V_11 ) ;
V_12 = F_13 ( V_1 -> V_3 , & V_11 ) ;
F_9 ( ! V_12 && V_11 . V_19 ) ;
if ( V_12 )
return V_12 ;
* V_7 &= 0xffffff ;
F_14 ( & V_1 -> V_3 -> V_4 , L_3 , V_6 , * V_7 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_1 , unsigned int V_6 , T_1 V_7 )
{
T_1 V_20 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
int V_12 ;
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
F_14 ( & V_1 -> V_3 -> V_4 , L_4 , V_6 , V_7 ) ;
if ( V_6 > V_13 || V_7 > 0xffffff )
return - V_14 ;
V_20 = 1 << 31 | V_6 << V_15 | V_7 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = & V_20 ;
V_9 . V_17 = & V_20 ;
V_9 . V_18 = sizeof( T_1 ) ;
F_11 ( & V_11 ) ;
F_12 ( & V_9 , & V_11 ) ;
V_12 = F_13 ( V_1 -> V_3 , & V_11 ) ;
F_9 ( ! V_12 && V_11 . V_19 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
int F_16 ( struct V_1 * V_1 , unsigned int V_6 ,
T_1 V_21 , T_1 V_7 )
{
int V_12 ;
T_1 V_22 ;
F_9 ( V_7 & ~ V_21 ) ;
V_12 = F_8 ( V_1 , V_6 , & V_22 ) ;
if ( V_12 )
return V_12 ;
V_22 = ( V_22 & ~ V_21 ) | V_7 ;
return F_15 ( V_1 , V_6 , V_22 ) ;
}
int F_17 ( struct V_1 * V_1 , int V_23 )
{
int V_12 ;
unsigned int V_24 = V_23 < 24 ? V_25 : V_26 ;
T_1 V_27 = 1 << ( V_23 < 24 ? V_23 : V_23 - 24 ) ;
T_1 V_21 ;
if ( V_23 < 0 || V_23 >= V_28 )
return - V_14 ;
V_12 = F_8 ( V_1 , V_24 , & V_21 ) ;
if ( V_12 )
return V_12 ;
if ( V_21 & V_27 )
return 0 ;
return F_15 ( V_1 , V_24 , V_21 | V_27 ) ;
}
int F_18 ( struct V_1 * V_1 , int V_23 )
{
int V_12 ;
unsigned int V_24 = V_23 < 24 ? V_25 : V_26 ;
T_1 V_27 = 1 << ( V_23 < 24 ? V_23 : V_23 - 24 ) ;
T_1 V_21 ;
if ( V_23 < 0 || V_23 >= V_28 )
return - V_14 ;
V_12 = F_8 ( V_1 , V_24 , & V_21 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_21 & V_27 ) )
return 0 ;
return F_15 ( V_1 , V_24 , V_21 & ~ V_27 ) ;
}
int F_19 ( struct V_1 * V_1 , int V_23 ,
int * V_29 , int * V_30 )
{
int V_12 ;
unsigned int V_24 = V_23 < 24 ? V_25 : V_26 ;
unsigned int V_31 = V_23 < 24 ? V_32 : V_33 ;
T_1 V_27 = 1 << ( V_23 < 24 ? V_23 : V_23 - 24 ) ;
if ( V_23 < 0 || V_23 >= V_28 )
return - V_14 ;
if ( V_29 ) {
T_1 V_21 ;
V_12 = F_8 ( V_1 , V_24 , & V_21 ) ;
if ( V_12 )
return V_12 ;
* V_29 = V_21 & V_27 ;
}
if ( V_30 ) {
T_1 V_34 ;
V_12 = F_8 ( V_1 , V_31 , & V_34 ) ;
if ( V_12 )
return V_12 ;
* V_30 = V_34 & V_27 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_1 , int V_23 )
{
unsigned int V_31 = V_23 < 24 ? V_32 : V_33 ;
unsigned int V_7 = 1 << ( V_23 < 24 ? V_23 : V_23 - 24 ) ;
F_9 ( V_23 < 0 || V_23 >= V_28 ) ;
return F_15 ( V_1 , V_31 , V_7 ) ;
}
int F_21 ( struct V_1 * V_1 , int V_23 ,
T_2 V_35 , const char * V_36 , void * V_4 )
{
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
F_9 ( ! V_35 ) ;
if ( V_23 < 0 || V_23 >= V_28 )
return - V_14 ;
if ( V_1 -> V_37 [ V_23 ] )
return - V_38 ;
V_1 -> V_37 [ V_23 ] = V_35 ;
V_1 -> V_39 [ V_23 ] = V_4 ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 , int V_23 ,
T_2 V_35 , const char * V_36 , void * V_4 )
{
int V_12 ;
V_12 = F_21 ( V_1 , V_23 , V_35 , V_36 , V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_18 ( V_1 , V_23 ) ;
if ( V_12 ) {
V_1 -> V_37 [ V_23 ] = NULL ;
V_1 -> V_39 [ V_23 ] = NULL ;
return V_12 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_1 , int V_23 , void * V_4 )
{
int V_12 ;
F_9 ( ! F_10 ( & V_1 -> V_2 ) ) ;
if ( V_23 < 0 || V_23 >= V_28 || ! V_1 -> V_37 [ V_23 ] ||
V_1 -> V_39 [ V_23 ] != V_4 )
return - V_14 ;
V_12 = F_17 ( V_1 , V_23 ) ;
if ( V_12 )
return V_12 ;
V_1 -> V_37 [ V_23 ] = NULL ;
V_1 -> V_39 [ V_23 ] = NULL ;
return 0 ;
}
static inline T_3 F_24 ( struct V_1 * V_1 , int V_23 )
{
return V_1 -> V_37 [ V_23 ] ( V_23 , V_1 -> V_39 [ V_23 ] ) ;
}
static int F_25 ( struct V_1 * V_1 ,
unsigned int V_31 , unsigned int V_24 , int V_40 )
{
T_1 V_34 , V_21 ;
int V_12 = F_8 ( V_1 , V_31 , & V_34 ) ;
int V_41 = 0 ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_1 , V_24 , & V_21 ) ;
if ( V_12 )
return V_12 ;
while ( V_34 & ~ V_21 ) {
int V_23 = F_26 ( V_34 & ~ V_21 ) ;
V_34 &= ~ ( 1 << V_23 ) ;
if ( F_27 ( V_1 -> V_37 [ V_40 + V_23 ] ) ) {
T_3 V_42 ;
V_42 = F_24 ( V_1 , V_40 + V_23 ) ;
if ( V_42 == V_43 )
V_41 ++ ;
} else {
F_28 ( & V_1 -> V_3 -> V_4 ,
L_5 ,
V_40 + V_23 ) ;
V_21 |= 1 << V_23 ;
V_12 = F_15 ( V_1 , V_24 , V_21 ) ;
}
}
return V_41 ;
}
static T_3 F_29 ( int V_23 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
T_3 V_12 ;
int V_42 = 0 ;
F_1 ( V_1 ) ;
V_12 = F_25 ( V_1 , V_32 ,
V_25 , 0 ) ;
if ( V_12 > 0 )
V_42 = 1 ;
V_12 = F_25 ( V_1 , V_33 ,
V_26 , 24 ) ;
if ( V_12 > 0 )
V_42 = 1 ;
F_6 ( V_1 ) ;
return F_30 ( V_42 ) ;
}
static int F_31 ( struct V_1 * V_1 , enum V_45 * V_46 )
{
T_1 V_47 ;
T_1 V_48 ;
const char * V_36 ;
int V_12 ;
V_12 = F_8 ( V_1 , 46 , & V_47 ) ;
if ( V_12 )
return V_12 ;
V_47 = ( V_47 >> 6 ) & 0x7 ;
switch ( V_47 ) {
case 2 :
* V_46 = V_49 ;
V_36 = L_6 ;
break;
case 7 :
* V_46 = V_50 ;
V_36 = L_7 ;
break;
default:
* V_46 = V_51 ;
break;
}
if ( * V_46 == V_49 || * V_46 == V_50 ) {
V_12 = F_8 ( V_1 , V_52 , & V_48 ) ;
if ( V_12 )
return V_12 ;
F_32 ( & V_1 -> V_3 -> V_4 , L_8
L_9 ,
V_53 [ * V_46 ] ,
F_33 ( V_48 , V_54 ) ,
F_33 ( V_48 , V_55 ) ,
F_33 ( V_48 , V_56 ) ,
F_33 ( V_48 , V_57 ) ,
F_33 ( V_48 , V_58 ) ,
F_33 ( V_48 , V_59 ) ) ;
}
if ( * V_46 != V_51 ) {
const struct V_60 * V_61 =
F_34 ( V_1 -> V_3 ) ;
if ( ! V_61 || V_61 -> V_62 != * V_46 )
F_35 ( & V_1 -> V_3 -> V_4 , L_10
L_11 ) ;
}
return 0 ;
}
static const char * F_36 ( struct V_1 * V_1 )
{
const struct V_60 * V_61 =
F_34 ( V_1 -> V_3 ) ;
if ( ! V_61 )
return NULL ;
return V_53 [ V_61 -> V_62 ] ;
}
int F_37 ( struct V_1 * V_1 )
{
return V_1 -> V_63 ;
}
static T_3 F_38 ( int V_23 , void * V_44 )
{
struct V_64 * V_65 = V_44 ;
F_20 ( V_65 -> V_1 , V_23 ) ;
F_39 ( & V_65 -> V_66 ) ;
return V_43 ;
}
int F_40 ( struct V_1 * V_1 , unsigned int V_67 ,
unsigned int V_68 , T_4 V_69 , bool V_70 ,
unsigned int * V_71 )
{
T_1 V_72 , V_73 , V_74 ;
int V_75 , V_12 ;
struct V_64 V_65 = {
. V_1 = V_1 ,
} ;
F_41 ( & V_65 . V_66 ) ;
F_3 ( & V_1 -> V_3 -> V_4 , L_12 , V_5 ) ;
F_1 ( V_1 ) ;
if ( V_1 -> V_76 & V_77 ) {
V_12 = - V_38 ;
goto V_78;
}
V_1 -> V_76 |= V_77 ;
F_8 ( V_1 , V_79 , & V_74 ) ;
V_72 = V_80 | V_81 ;
V_73 = V_82 | V_83 | V_84 ;
if ( V_68 > 7 )
V_73 |= V_85 ;
switch ( V_67 ) {
case V_86 :
V_72 |= V_87 | V_88 |
V_89 ;
V_73 |= 4 << V_90 ;
break;
case V_91 :
V_72 |= V_74 & V_92 ;
V_73 |= ( V_68 & 0x7 ) << V_93 ;
V_73 |= V_94 ;
break;
case V_95 :
V_72 |= V_74 & V_92 ;
V_73 |= 4 << V_90 ;
break;
default:
F_6 ( V_1 ) ;
return - V_14 ;
}
V_73 |= V_69 << V_96 ;
if ( V_70 )
V_73 |= V_97 ;
F_3 ( & V_1 -> V_3 -> V_4 , L_13 , V_5 ) ;
F_22 ( V_1 , V_98 ,
F_38 , V_5 , & V_65 ) ;
F_20 ( V_1 , V_98 ) ;
F_15 ( V_1 , V_79 , V_72 ) ;
F_15 ( V_1 , V_99 , V_73 ) ;
F_6 ( V_1 ) ;
V_12 = F_42 ( & V_65 . V_66 , V_100 ) ;
if ( ! V_12 )
V_12 = - V_101 ;
F_1 ( V_1 ) ;
F_23 ( V_1 , V_98 , & V_65 ) ;
if ( V_12 > 0 )
for ( V_75 = 0 ; V_75 < 4 ; ++ V_75 ) {
V_12 = F_8 ( V_1 ,
V_102 , & V_71 [ V_75 ] ) ;
if ( V_12 )
break;
}
if ( V_67 == V_86 )
F_15 ( V_1 , V_79 , V_74 ) ;
V_1 -> V_76 &= ~ V_77 ;
V_78:
F_6 ( V_1 ) ;
return V_12 ;
}
static int F_43 ( struct V_1 * V_1 ,
const char * V_103 , void * V_104 , T_5 V_105 )
{
char V_20 [ 30 ] ;
const char * V_36 = F_36 ( V_1 ) ;
struct V_106 V_107 = {
. V_108 = V_104 ,
. V_105 = V_105 ,
} ;
if ( snprintf ( V_20 , sizeof( V_20 ) , V_103 , V_36 ) > sizeof( V_20 ) )
return - V_109 ;
V_107 . V_36 = F_44 ( V_20 , strlen ( V_20 ) + 1 , V_110 ) ;
if ( ! V_107 . V_36 )
return - V_111 ;
return F_45 ( & V_1 -> V_3 -> V_4 , - 1 , & V_107 , 1 , NULL , 0 ) ;
}
static int F_46 ( struct V_1 * V_1 , const char * V_103 )
{
return F_43 ( V_1 , V_103 , NULL , 0 ) ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_112 * V_113 = V_1 -> V_3 -> V_4 . V_114 ;
if ( ! V_113 )
return - V_115 ;
if ( F_48 ( V_113 , L_14 , NULL ) )
V_1 -> V_63 |= V_116 ;
if ( F_48 ( V_113 , L_15 , NULL ) )
V_1 -> V_63 |= V_117 ;
if ( F_48 ( V_113 , L_16 , NULL ) )
V_1 -> V_63 |= V_118 ;
if ( F_48 ( V_113 , L_17 , NULL ) )
V_1 -> V_63 |= V_119 ;
return 0 ;
}
static inline int F_47 ( struct V_1 * V_1 )
{
return - V_115 ;
}
static int F_49 ( struct V_120 * V_121 )
{
const struct V_122 * V_123 ;
struct V_124 * V_125 = F_50 ( V_121 -> V_4 . V_126 ) ;
struct V_1 * V_1 ;
struct V_127 * V_104 = F_51 ( & V_121 -> V_4 ) ;
enum V_45 V_46 ;
int V_12 ;
V_123 = F_52 ( V_128 , & V_121 -> V_4 ) ;
if ( V_123 )
V_125 -> V_129 = & V_130 [ ( enum V_45 ) of_id->data];
int T_6 F_53 ( struct V_120 * V_121 )
{
struct V_1 * V_1 = F_54 ( & V_121 -> V_4 ) ;
F_55 ( V_1 -> V_3 -> V_23 , V_1 ) ;
F_56 ( & V_121 -> V_4 ) ;
F_57 ( V_1 ) ;
return 0 ;
}
static int T_7 F_58 ( void )
{
return F_59 ( & V_131 ) ;
}
static void T_8 F_60 ( void )
{
F_61 ( & V_131 ) ;
}
