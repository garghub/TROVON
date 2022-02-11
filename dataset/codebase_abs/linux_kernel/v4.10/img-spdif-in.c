static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
T_1 V_6 )
{
F_1 ( V_2 , V_2 -> V_7 [ V_6 ] ,
V_8 + ( V_6 * 0x4 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_9 , unsigned long * V_10 )
{
unsigned long V_11 , V_12 ;
V_11 = V_9 * 2 * 32 * 24 ;
V_12 = F_7 ( V_2 -> V_13 ) ;
if ( V_12 < V_11 )
return - V_14 ;
* V_10 = V_12 ;
return 0 ;
}
static int F_8 ( unsigned int V_15 , unsigned int * V_16 ,
unsigned int * V_17 , unsigned long V_18 )
{
unsigned int V_19 , V_20 , V_21 ;
if ( ! V_15 )
return - V_14 ;
V_19 = V_18 / ( V_15 * 64 ) ;
if ( ! V_19 )
return - V_14 ;
V_20 = ( 4096 / V_19 ) + 1 ;
do
V_21 = 4096 - ( -- V_20 * ( V_19 - 1 ) ) ;
while ( V_21 < 120 );
* V_16 = V_20 ;
* V_17 = V_21 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
unsigned int V_20 , V_21 ;
unsigned long V_22 , V_18 ;
int V_23 = 0 ;
T_1 V_4 ;
V_23 = F_6 ( V_2 , V_15 , & V_18 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_8 ( V_15 , & V_20 , & V_21 , V_18 ) ;
if ( V_23 )
return V_23 ;
V_4 = ( V_20 << V_24 ) &
V_25 ;
V_4 |= ( V_21 << V_26 ) &
V_27 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
F_1 ( V_2 , V_4 , V_31 ) ;
V_2 -> V_32 = V_15 ;
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_33 [] )
{
unsigned int V_20 , V_21 , V_15 , V_34 = 0 ;
unsigned long V_22 , V_18 ;
int V_35 , V_23 = 0 ;
T_1 V_4 , V_36 , V_37 [ V_38 ] ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
if ( V_33 [ V_35 ] > V_34 )
V_34 = V_33 [ V_35 ] ;
V_23 = F_6 ( V_2 , V_34 , & V_18 ) ;
if ( V_23 )
return V_23 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_15 = V_33 [ V_35 ] ;
V_23 = F_8 ( V_15 , & V_20 , & V_21 , V_18 ) ;
if ( V_23 )
return V_23 ;
V_4 = ( V_20 << V_39 ) &
V_40 ;
V_4 |= ( V_21 << V_41 ) &
V_42 ;
V_37 [ V_35 ] = V_4 ;
}
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
V_36 = V_2 -> V_43 << V_44 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_2 -> V_7 [ V_35 ] = V_37 [ V_35 ] | V_36 ;
F_5 ( V_2 , V_35 ) ;
}
V_2 -> V_45 = true ;
V_2 -> V_33 [ 0 ] = V_33 [ 0 ] ;
V_2 -> V_33 [ 1 ] = V_33 [ 1 ] ;
V_2 -> V_33 [ 2 ] = V_33 [ 2 ] ;
V_2 -> V_33 [ 3 ] = V_33 [ 3 ] ;
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_50 ;
V_49 -> V_51 = 1 ;
return 0 ;
}
static int F_14 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
V_53 -> V_54 . V_55 . V_56 [ 0 ] = 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 1 ] = 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 2 ] = 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 3 ] = 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 4 ] = 0xff ;
return 0 ;
}
static int F_15 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
T_1 V_4 ;
V_4 = F_3 ( V_2 , V_59 ) ;
V_53 -> V_54 . V_55 . V_56 [ 0 ] = V_4 & 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 1 ] = ( V_4 >> 8 ) & 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 2 ] = ( V_4 >> 16 ) & 0xff ;
V_53 -> V_54 . V_55 . V_56 [ 3 ] = ( V_4 >> 24 ) & 0xff ;
V_4 = F_3 ( V_2 , V_60 ) ;
V_53 -> V_54 . V_55 . V_56 [ 4 ] = ( V_4 & V_61 )
>> V_62 ;
return 0 ;
}
static int F_18 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_63 ;
V_49 -> V_51 = V_38 ;
V_49 -> V_54 . integer . V_64 = 0 ;
V_49 -> V_54 . integer . V_65 = V_66 ;
return 0 ;
}
static int F_19 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
unsigned long V_22 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_45 ) {
V_53 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_33 [ 0 ] ;
V_53 -> V_54 . integer . V_54 [ 1 ] = V_2 -> V_33 [ 1 ] ;
V_53 -> V_54 . integer . V_54 [ 2 ] = V_2 -> V_33 [ 2 ] ;
V_53 -> V_54 . integer . V_54 [ 3 ] = V_2 -> V_33 [ 3 ] ;
} else {
V_53 -> V_54 . integer . V_54 [ 0 ] = 0 ;
V_53 -> V_54 . integer . V_54 [ 1 ] = 0 ;
V_53 -> V_54 . integer . V_54 [ 2 ] = 0 ;
V_53 -> V_54 . integer . V_54 [ 3 ] = 0 ;
}
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
unsigned int V_33 [ V_38 ] ;
bool V_45 ;
unsigned long V_22 ;
if ( ( V_53 -> V_54 . integer . V_54 [ 0 ] == 0 ) &&
( V_53 -> V_54 . integer . V_54 [ 1 ] == 0 ) &&
( V_53 -> V_54 . integer . V_54 [ 2 ] == 0 ) &&
( V_53 -> V_54 . integer . V_54 [ 3 ] == 0 ) ) {
V_45 = false ;
} else {
V_33 [ 0 ] = V_53 -> V_54 . integer . V_54 [ 0 ] ;
V_33 [ 1 ] = V_53 -> V_54 . integer . V_54 [ 1 ] ;
V_33 [ 2 ] = V_53 -> V_54 . integer . V_54 [ 2 ] ;
V_33 [ 3 ] = V_53 -> V_54 . integer . V_54 [ 3 ] ;
V_45 = true ;
}
if ( V_45 )
return F_12 ( V_2 , V_33 ) ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
V_2 -> V_45 = false ;
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_63 ;
V_49 -> V_51 = 1 ;
V_49 -> V_54 . integer . V_64 = 0 ;
V_49 -> V_54 . integer . V_65 = V_66 ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
struct V_52 * V_67 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
T_1 V_4 ;
int V_35 ;
unsigned long V_22 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
V_4 = F_3 ( V_2 , V_68 ) ;
if ( V_4 & V_69 ) {
if ( V_2 -> V_45 ) {
V_35 = ( ( V_4 & V_70 ) >>
V_71 ) - 1 ;
V_67 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_33 [ V_35 ] ;
} else {
V_67 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_32 ;
}
} else {
V_67 -> V_54 . integer . V_54 [ 0 ] = 0 ;
}
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_63 ;
V_49 -> V_51 = 1 ;
V_49 -> V_54 . integer . V_64 = 0 ;
V_49 -> V_54 . integer . V_65 = 255 ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
V_53 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_43 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
unsigned long V_22 ;
int V_35 ;
T_1 V_4 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
V_2 -> V_43 = V_53 -> V_54 . integer . V_54 [ 0 ] ;
V_4 = F_3 ( V_2 , V_72 ) ;
V_4 &= ~ V_73 ;
V_4 |= V_2 -> V_43 << V_74 ;
F_1 ( V_2 , V_4 , V_72 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
V_2 -> V_7 [ V_35 ] = ( V_2 -> V_7 [ V_35 ] &
~ V_75 ) |
( V_2 -> V_43 << V_44 ) ;
F_5 ( V_2 , V_35 ) ;
}
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_63 ;
V_49 -> V_51 = 1 ;
V_49 -> V_54 . integer . V_64 = - 128 ;
V_49 -> V_54 . integer . V_65 = 127 ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
V_53 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_76 ;
return 0 ;
}
static int F_28 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
unsigned long V_22 ;
T_1 V_4 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
V_2 -> V_76 = V_53 -> V_54 . integer . V_54 [ 0 ] ;
V_4 = F_3 ( V_2 , V_72 ) ;
V_4 &= ~ V_77 ;
V_4 |= ( V_2 -> V_76 << V_78 ) &
V_77 ;
F_1 ( V_2 , V_4 , V_72 ) ;
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_29 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
V_53 -> V_54 . integer . V_54 [ 0 ] = V_2 -> V_79 ;
return 0 ;
}
static int F_30 ( struct V_46 * V_47 ,
struct V_52 * V_53 )
{
struct V_57 * V_58 = F_16 ( V_47 ) ;
struct V_1 * V_2 = F_17 ( V_58 ) ;
unsigned long V_22 ;
T_1 V_4 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
if ( V_2 -> V_29 ) {
F_11 ( & V_2 -> V_28 , V_22 ) ;
return - V_30 ;
}
V_2 -> V_79 = V_53 -> V_54 . integer . V_54 [ 0 ] ;
V_4 = F_3 ( V_2 , V_72 ) ;
V_4 &= ~ V_80 ;
V_4 |= ( V_2 -> V_79 << V_81 ) &
V_80 ;
F_1 ( V_2 , V_4 , V_72 ) ;
F_11 ( & V_2 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 , int V_84 ,
struct V_57 * V_85 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_17 ( V_85 ) ;
int V_23 = 0 ;
T_1 V_4 ;
F_10 ( & V_2 -> V_28 , V_22 ) ;
switch ( V_84 ) {
case V_86 :
case V_87 :
case V_88 :
V_4 = F_3 ( V_2 , V_72 ) ;
if ( V_2 -> V_45 )
V_4 &= ~ V_89 ;
else
V_4 |= ( 1UL << V_90 ) ;
V_4 |= V_91 ;
F_1 ( V_2 , V_4 , V_72 ) ;
V_2 -> V_29 = true ;
break;
case V_92 :
case V_93 :
case V_94 :
V_4 = F_3 ( V_2 , V_72 ) ;
V_4 &= ~ V_91 ;
F_1 ( V_2 , V_4 , V_72 ) ;
V_2 -> V_29 = false ;
break;
default:
V_23 = - V_14 ;
}
F_11 ( & V_2 -> V_28 , V_22 ) ;
return V_23 ;
}
static int F_32 ( struct V_82 * V_83 ,
struct V_95 * V_96 , struct V_57 * V_85 )
{
struct V_1 * V_2 = F_17 ( V_85 ) ;
unsigned int V_15 , V_97 ;
T_2 V_98 ;
V_15 = F_33 ( V_96 ) ;
V_97 = F_34 ( V_96 ) ;
V_98 = F_35 ( V_96 ) ;
if ( V_98 != V_99 )
return - V_14 ;
if ( V_97 != 2 )
return - V_14 ;
return F_9 ( V_2 , V_15 ) ;
}
static int F_36 ( struct V_57 * V_85 )
{
struct V_1 * V_2 = F_17 ( V_85 ) ;
F_37 ( V_85 , NULL , & V_2 -> V_100 ) ;
F_38 ( V_85 , V_101 ,
F_39 ( V_101 ) ) ;
return 0 ;
}
static int F_40 ( struct V_102 * V_103 )
{
struct V_1 * V_2 ;
struct V_104 * V_105 ;
void T_3 * V_5 ;
int V_23 ;
struct V_106 * V_107 ;
T_1 V_4 ;
struct V_108 * V_109 = & V_103 -> V_109 ;
V_2 = F_41 ( & V_103 -> V_109 , sizeof( * V_2 ) , V_110 ) ;
if ( ! V_2 )
return - V_111 ;
F_42 ( V_103 , V_2 ) ;
V_2 -> V_109 = & V_103 -> V_109 ;
V_105 = F_43 ( V_103 , V_112 , 0 ) ;
V_5 = F_44 ( & V_103 -> V_109 , V_105 ) ;
if ( F_45 ( V_5 ) )
return F_46 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = F_47 ( V_109 , L_1 ) ;
if ( F_45 ( V_2 -> V_13 ) ) {
if ( F_46 ( V_2 -> V_13 ) != - V_113 )
F_48 ( V_109 , L_2 ) ;
return F_46 ( V_2 -> V_13 ) ;
}
V_23 = F_49 ( V_2 -> V_13 ) ;
if ( V_23 )
return V_23 ;
V_107 = F_50 ( & V_103 -> V_109 , L_3 ) ;
if ( F_45 ( V_107 ) ) {
if ( F_46 ( V_107 ) == - V_113 ) {
V_23 = - V_113 ;
goto V_114;
}
F_51 ( V_109 , L_4 ) ;
F_1 ( V_2 , V_115 ,
V_116 ) ;
F_1 ( V_2 , 0 , V_116 ) ;
} else {
F_52 ( V_107 ) ;
F_53 ( V_107 ) ;
}
F_54 ( & V_2 -> V_28 ) ;
V_2 -> V_100 . V_117 = V_105 -> V_118 + V_119 ;
V_2 -> V_100 . V_120 = 4 ;
V_2 -> V_100 . V_121 = 4 ;
V_2 -> V_43 = 0x80 ;
V_2 -> V_76 = 4 ;
V_2 -> V_79 = - 128 ;
V_4 = ( V_2 -> V_76 << V_78 ) &
V_77 ;
V_4 |= ( V_2 -> V_79 << V_81 ) &
V_80 ;
V_4 |= ( V_2 -> V_43 << V_74 ) &
V_73 ;
F_1 ( V_2 , V_4 , V_72 ) ;
V_23 = F_55 ( & V_103 -> V_109 ,
& V_122 , & V_123 , 1 ) ;
if ( V_23 )
goto V_114;
V_23 = F_56 ( & V_103 -> V_109 , NULL , 0 ) ;
if ( V_23 )
goto V_114;
return 0 ;
V_114:
F_57 ( V_2 -> V_13 ) ;
return V_23 ;
}
static int F_58 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_59 ( V_103 ) ;
F_57 ( V_2 -> V_13 ) ;
return 0 ;
}
