static inline unsigned int F_1 (
struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = V_2 -> V_4 [ 0 ] ++ ;
if ( F_2 ( V_2 -> V_4 [ 0 ] >= V_2 -> V_5 [ 0 ] . V_6 ) )
V_2 -> V_4 [ 0 ] = 0 ;
return V_3 ;
}
static int F_3 ( T_1 V_7 , int V_8 , int V_6 )
{
int V_9 ;
V_9 = ( V_7 >> V_10 ) & ( V_8 - 1 ) ;
V_9 *= V_6 ;
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_7 )
{
return F_3 ( V_7 , V_2 -> V_5 [ 0 ] . V_8 ,
V_2 -> V_5 [ 0 ] . V_6 ) ;
}
static unsigned int F_5 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_14 = F_7 ( V_12 ) ;
if ( V_13 == 0 ) {
V_14 &= V_2 -> V_5 [ 0 ] . V_6 - 1 ;
V_14 += F_4 ( V_2 , V_12 -> V_15 . V_16 -> V_17 ) ;
} else {
V_14 &= V_2 -> V_5 [ V_13 ] . V_18 - 1 ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_19 , int V_13 , unsigned int V_20 , int V_21 )
{
int V_22 = V_2 -> V_5 [ V_13 ] . V_18 ;
unsigned int V_9 , V_23 ;
int V_24 ;
if ( V_13 == 0 ) {
V_9 = F_4 ( V_2 , V_19 ) ;
V_22 = V_2 -> V_5 [ 0 ] . V_6 ;
} else {
if ( V_19 < V_2 -> V_25 ||
V_19 > V_2 -> V_26 )
return - 1 ;
V_9 = 0 ;
}
V_23 = V_2 -> V_27 [ V_13 ] ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
struct V_28 * V_29 =
& V_2 -> V_30 [ V_23 + V_9 + V_24 ] ;
unsigned int V_31 ;
if ( V_19 < F_9 ( V_29 ) )
continue;
if ( V_19 > F_10 ( V_29 ) )
continue;
V_31 = F_11 ( V_29 ) ;
if ( V_31 && ( V_31 != V_20 ) )
continue;
if ( ! F_12 ( V_29 ) )
continue;
if ( F_13 ( V_29 ) != V_21 && V_21 != - 1 )
continue;
return V_9 + V_24 ;
}
return - 1 ;
}
static inline void F_14 ( struct V_11 * V_12 ,
T_1 V_19 , int V_21 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned int V_3 , V_32 ;
int V_13 ;
V_13 = ( V_12 -> V_15 . V_16 -> V_33 >> 28 ) & 0x1 ;
V_3 = ( V_13 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_32 = ( V_12 -> V_15 . V_16 -> V_33 >> 7 ) & 0x1f ;
V_12 -> V_15 . V_16 -> V_34 = F_15 ( V_13 ) | F_16 ( V_3 )
| F_17 ( V_2 -> V_4 [ V_13 ] ) ;
V_12 -> V_15 . V_16 -> V_35 = V_36 | ( V_21 ? V_37 : 0 )
| F_18 ( F_19 ( V_12 ) )
| F_20 ( V_32 ) ;
V_12 -> V_15 . V_16 -> V_17 = ( V_19 & V_38 )
| ( V_12 -> V_15 . V_16 -> V_33 & V_39 ) ;
V_12 -> V_15 . V_16 -> V_40 &= V_41 | V_42 | V_43 | V_44 ;
V_12 -> V_15 . V_16 -> V_45 = ( V_12 -> V_15 . V_16 -> V_45 & V_46 )
| ( F_21 ( V_12 ) << 16 )
| ( V_21 ? V_47 : 0 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_22 = V_2 -> V_5 [ 1 ] . V_18 ;
unsigned int V_23 ;
T_1 V_19 ;
int V_24 ;
V_2 -> V_25 = ~ 0UL ;
V_2 -> V_26 = 0 ;
V_23 = V_2 -> V_27 [ 1 ] ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
struct V_28 * V_29 =
& V_2 -> V_30 [ V_23 + V_24 ] ;
if ( ! F_12 ( V_29 ) )
continue;
V_19 = F_9 ( V_29 ) ;
V_2 -> V_25 =
F_23 ( V_2 -> V_25 , V_19 ) ;
V_19 = F_10 ( V_29 ) ;
V_2 -> V_26 =
F_24 ( V_2 -> V_26 , V_19 ) ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_28 * V_48 )
{
unsigned long V_49 , V_50 , V_22 ;
V_22 = F_26 ( V_48 ) ;
V_49 = F_9 ( V_48 ) & ~ ( V_22 - 1 ) ;
V_50 = V_49 + V_22 - 1 ;
return V_2 -> V_25 == V_49 ||
V_2 -> V_26 == V_50 ;
}
static void F_27 ( struct V_11 * V_12 ,
struct V_28 * V_48 )
{
unsigned long V_49 , V_50 , V_22 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( ! F_12 ( V_48 ) )
return;
V_22 = F_26 ( V_48 ) ;
V_49 = F_9 ( V_48 ) & ~ ( V_22 - 1 ) ;
V_50 = V_49 + V_22 - 1 ;
V_2 -> V_25 = F_23 ( V_2 -> V_25 , V_49 ) ;
V_2 -> V_26 = F_24 ( V_2 -> V_26 , V_50 ) ;
}
static inline int F_28 (
struct V_1 * V_2 ,
int V_13 , int V_14 )
{
struct V_28 * V_48 =
F_29 ( V_2 , V_13 , V_14 ) ;
if ( F_2 ( F_30 ( V_48 ) ) )
return - 1 ;
if ( V_13 == 1 && F_25 ( V_2 , V_48 ) )
F_22 ( V_2 ) ;
V_48 -> V_35 = 0 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_51 )
{
int V_14 ;
if ( V_51 & V_52 )
for ( V_14 = 0 ; V_14 < V_2 -> V_5 [ 0 ] . V_18 ; V_14 ++ )
F_28 ( V_2 , 0 , V_14 ) ;
if ( V_51 & V_53 )
for ( V_14 = 0 ; V_14 < V_2 -> V_5 [ 1 ] . V_18 ; V_14 ++ )
F_28 ( V_2 , 1 , V_14 ) ;
F_32 ( & V_2 -> V_12 ) ;
return V_54 ;
}
int F_33 ( struct V_11 * V_12 , T_1 V_55 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned int V_56 ;
int V_14 , V_13 ;
V_56 = ( V_55 >> 2 ) & 0x1 ;
V_13 = ( V_55 >> 3 ) & 0x1 ;
if ( V_56 ) {
for ( V_14 = 0 ; V_14 < V_2 -> V_5 [ V_13 ] . V_18 ;
V_14 ++ )
F_28 ( V_2 , V_13 , V_14 ) ;
} else {
V_55 &= 0xfffff000 ;
V_14 = F_8 ( V_2 , V_55 , V_13 ,
F_21 ( V_12 ) , - 1 ) ;
if ( V_14 >= 0 )
F_28 ( V_2 , V_13 , V_14 ) ;
}
F_32 ( & V_2 -> V_12 ) ;
return V_54 ;
}
static void F_34 ( struct V_1 * V_2 , int V_13 ,
int V_20 , int type )
{
struct V_28 * V_29 ;
int V_31 , V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_5 [ V_13 ] . V_18 ; V_14 ++ ) {
V_29 = F_29 ( V_2 , V_13 , V_14 ) ;
V_31 = F_11 ( V_29 ) ;
if ( type == 0 || V_31 == V_20 ) {
F_35 ( V_2 , V_13 , V_14 ) ;
F_28 ( V_2 , V_13 , V_14 ) ;
}
}
}
static void F_36 ( struct V_1 * V_2 , int V_20 ,
T_1 V_55 )
{
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_14 = F_8 ( V_2 , V_55 , V_13 , V_20 , - 1 ) ;
if ( V_14 >= 0 ) {
F_35 ( V_2 , V_13 , V_14 ) ;
F_28 ( V_2 , V_13 , V_14 ) ;
break;
}
}
}
int F_37 ( struct V_11 * V_12 , int type , T_1 V_55 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_20 = F_38 ( V_12 ) ;
if ( type == 0 || type == 1 ) {
F_34 ( V_2 , 0 , V_20 , type ) ;
F_34 ( V_2 , 1 , V_20 , type ) ;
} else if ( type == 3 ) {
F_36 ( V_2 , V_20 , V_55 ) ;
}
return V_54 ;
}
int F_39 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_13 , V_14 ;
struct V_28 * V_48 ;
V_13 = F_40 ( V_12 ) ;
V_14 = F_5 ( V_12 , V_13 ) ;
V_48 = F_29 ( V_2 , V_13 , V_14 ) ;
V_12 -> V_15 . V_16 -> V_34 &= ~ F_17 ( ~ 0 ) ;
V_12 -> V_15 . V_16 -> V_34 |= F_17 ( V_2 -> V_4 [ V_13 ] ) ;
V_12 -> V_15 . V_16 -> V_35 = V_48 -> V_35 ;
V_12 -> V_15 . V_16 -> V_17 = V_48 -> V_17 ;
V_12 -> V_15 . V_16 -> V_40 = V_48 -> V_40 ;
return V_54 ;
}
int F_41 ( struct V_11 * V_12 , T_1 V_55 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_21 = ! ! F_42 ( V_12 ) ;
unsigned int V_20 = F_38 ( V_12 ) ;
int V_14 , V_13 ;
struct V_28 * V_48 = NULL ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_14 = F_8 ( V_2 , V_55 , V_13 , V_20 , V_21 ) ;
if ( V_14 >= 0 ) {
V_48 = F_29 ( V_2 , V_13 , V_14 ) ;
break;
}
}
if ( V_48 ) {
V_14 &= V_2 -> V_5 [ V_13 ] . V_6 - 1 ;
V_12 -> V_15 . V_16 -> V_34 = F_15 ( V_13 ) | F_16 ( V_14 )
| F_17 ( V_2 -> V_4 [ V_13 ] ) ;
V_12 -> V_15 . V_16 -> V_35 = V_48 -> V_35 ;
V_12 -> V_15 . V_16 -> V_17 = V_48 -> V_17 ;
V_12 -> V_15 . V_16 -> V_40 = V_48 -> V_40 ;
} else {
int V_3 ;
V_13 = V_12 -> V_15 . V_16 -> V_33 >> 28 & 0x1 ;
V_3 = ( V_13 == 0 ) ? F_1 ( V_2 ) : 0 ;
V_12 -> V_15 . V_16 -> V_34 = F_15 ( V_13 )
| F_16 ( V_3 )
| F_17 ( V_2 -> V_4 [ V_13 ] ) ;
V_12 -> V_15 . V_16 -> V_35 =
( V_12 -> V_15 . V_16 -> V_45 & V_57 )
| ( V_12 -> V_15 . V_16 -> V_45 & ( V_47 ? V_37 : 0 ) )
| ( V_12 -> V_15 . V_16 -> V_33 & F_43 ( ~ 0 ) ) ;
V_12 -> V_15 . V_16 -> V_17 &= V_38 ;
V_12 -> V_15 . V_16 -> V_17 |= V_12 -> V_15 . V_16 -> V_33 &
V_39 ;
V_12 -> V_15 . V_16 -> V_40 &= V_41 | V_42 |
V_43 | V_44 ;
}
F_44 ( V_12 , V_58 ) ;
return V_54 ;
}
int F_45 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_28 * V_48 ;
int V_13 , V_14 ;
int V_59 = 0 ;
int V_60 ;
V_13 = F_40 ( V_12 ) ;
V_14 = F_5 ( V_12 , V_13 ) ;
V_48 = F_29 ( V_2 , V_13 , V_14 ) ;
if ( F_12 ( V_48 ) ) {
F_35 ( V_2 , V_13 , V_14 ) ;
if ( ( V_13 == 1 ) &&
F_25 ( V_2 , V_48 ) )
V_59 = 1 ;
}
V_48 -> V_35 = V_12 -> V_15 . V_16 -> V_35 ;
V_48 -> V_17 = V_12 -> V_15 . V_16 -> V_17 ;
if ( ! ( V_12 -> V_15 . V_16 -> V_61 & V_62 ) )
V_48 -> V_17 &= 0xffffffffUL ;
V_48 -> V_40 = V_12 -> V_15 . V_16 -> V_40 ;
F_46 ( V_12 -> V_15 . V_16 -> V_34 , V_48 -> V_35 ,
V_48 -> V_17 , V_48 -> V_40 ) ;
if ( V_13 == 1 ) {
if ( V_59 )
F_22 ( V_2 ) ;
else
F_27 ( V_12 , V_48 ) ;
}
V_60 = F_47 ( & V_12 -> V_63 -> V_64 ) ;
if ( F_48 ( V_12 , V_48 ) ) {
T_3 V_19 = F_9 ( V_48 ) ;
T_3 V_65 = F_49 ( V_48 ) ;
if ( V_13 == 0 ) {
V_48 -> V_35 &= ~ F_20 ( ~ 0 ) ;
V_48 -> V_35 |= F_20 ( V_66 ) ;
}
F_50 ( V_12 , V_19 , V_65 , F_51 ( V_13 , V_14 ) ) ;
}
F_52 ( & V_12 -> V_63 -> V_64 , V_60 ) ;
F_44 ( V_12 , V_67 ) ;
return V_54 ;
}
static int F_53 ( struct V_11 * V_12 ,
T_1 V_19 , unsigned int V_20 , int V_21 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_14 , V_13 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_14 = F_8 ( V_2 , V_19 , V_13 , V_20 , V_21 ) ;
if ( V_14 >= 0 )
return F_51 ( V_13 , V_14 ) ;
}
return - 1 ;
}
int F_54 ( struct V_11 * V_12 ,
struct V_68 * V_69 )
{
int V_70 ;
T_1 V_19 ;
T_4 V_20 ;
T_4 V_21 ;
V_19 = V_69 -> V_71 ;
V_20 = ( V_69 -> V_71 >> 32 ) & 0xff ;
V_21 = ( V_69 -> V_71 >> 40 ) & 0x1 ;
V_70 = F_53 ( V_12 , V_19 , V_20 , V_21 ) ;
if ( V_70 < 0 ) {
V_69 -> V_72 = 0 ;
return 0 ;
}
V_69 -> V_73 = F_55 ( V_12 , V_70 , V_19 ) ;
V_69 -> V_72 = 1 ;
return 0 ;
}
int F_56 ( struct V_11 * V_12 , T_1 V_19 )
{
unsigned int V_21 = ! ! ( V_12 -> V_15 . V_16 -> V_61 & V_74 ) ;
return F_53 ( V_12 , V_19 , F_21 ( V_12 ) , V_21 ) ;
}
int F_57 ( struct V_11 * V_12 , T_1 V_19 )
{
unsigned int V_21 = ! ! ( V_12 -> V_15 . V_16 -> V_61 & V_75 ) ;
return F_53 ( V_12 , V_19 , F_21 ( V_12 ) , V_21 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
unsigned int V_21 = ! ! ( V_12 -> V_15 . V_16 -> V_61 & V_74 ) ;
F_14 ( V_12 , V_12 -> V_15 . V_76 , V_21 ) ;
}
void F_59 ( struct V_11 * V_12 )
{
unsigned int V_21 = ! ! ( V_12 -> V_15 . V_16 -> V_61 & V_75 ) ;
F_14 ( V_12 , V_12 -> V_15 . V_77 , V_21 ) ;
}
T_5 F_55 ( struct V_11 * V_12 , unsigned int V_70 ,
T_1 V_19 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_28 * V_48 ;
T_3 V_78 ;
V_48 = F_29 ( V_2 , F_60 ( V_70 ) , F_61 ( V_70 ) ) ;
V_78 = F_26 ( V_48 ) - 1 ;
return F_49 ( V_48 ) | ( V_19 & V_78 ) ;
}
void F_62 ( struct V_11 * V_12 )
{
}
static void F_63 ( struct V_1 * V_2 )
{
int V_24 ;
F_32 ( & V_2 -> V_12 ) ;
F_64 ( V_2 -> V_79 ) ;
F_64 ( V_2 -> V_80 [ 0 ] ) ;
F_64 ( V_2 -> V_80 [ 1 ] ) ;
if ( V_2 -> V_81 ) {
F_65 ( ( void * ) ( F_66 ( ( V_82 ) V_2 -> V_30 ,
V_83 ) ) ) ;
for ( V_24 = 0 ; V_24 < V_2 -> V_84 ; V_24 ++ ) {
F_67 ( V_2 -> V_81 [ V_24 ] ) ;
F_68 ( V_2 -> V_81 [ V_24 ] ) ;
}
V_2 -> V_84 = 0 ;
F_64 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
} else {
F_64 ( V_2 -> V_30 ) ;
}
V_2 -> V_30 = NULL ;
}
void F_69 ( struct V_11 * V_12 , struct V_85 * V_86 )
{
V_86 -> V_87 . V_88 . V_34 = V_12 -> V_15 . V_16 -> V_34 ;
V_86 -> V_87 . V_88 . V_35 = V_12 -> V_15 . V_16 -> V_35 ;
V_86 -> V_87 . V_88 . V_17 = V_12 -> V_15 . V_16 -> V_17 ;
V_86 -> V_87 . V_88 . V_40 = V_12 -> V_15 . V_16 -> V_40 ;
V_86 -> V_87 . V_88 . V_33 = V_12 -> V_15 . V_16 -> V_33 ;
V_86 -> V_87 . V_88 . V_45 = V_12 -> V_15 . V_16 -> V_45 ;
V_86 -> V_87 . V_88 . V_89 = V_12 -> V_15 . V_89 ;
V_86 -> V_87 . V_88 . V_90 [ 0 ] = V_12 -> V_15 . V_90 [ 0 ] ;
V_86 -> V_87 . V_88 . V_90 [ 1 ] = V_12 -> V_15 . V_90 [ 1 ] ;
V_86 -> V_87 . V_88 . V_90 [ 2 ] = 0 ;
V_86 -> V_87 . V_88 . V_90 [ 3 ] = 0 ;
}
int F_70 ( struct V_11 * V_12 , struct V_85 * V_86 )
{
if ( V_86 -> V_87 . V_88 . V_91 & V_92 ) {
V_12 -> V_15 . V_16 -> V_34 = V_86 -> V_87 . V_88 . V_34 ;
V_12 -> V_15 . V_16 -> V_35 = V_86 -> V_87 . V_88 . V_35 ;
V_12 -> V_15 . V_16 -> V_17 = V_86 -> V_87 . V_88 . V_17 ;
V_12 -> V_15 . V_16 -> V_40 = V_86 -> V_87 . V_88 . V_40 ;
V_12 -> V_15 . V_16 -> V_33 = V_86 -> V_87 . V_88 . V_33 ;
V_12 -> V_15 . V_16 -> V_45 = V_86 -> V_87 . V_88 . V_45 ;
}
return 0 ;
}
int F_71 ( struct V_11 * V_12 , T_3 V_93 ,
union V_94 * V_95 )
{
int V_96 = 0 ;
long int V_24 ;
switch ( V_93 ) {
case V_97 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_34 ) ;
break;
case V_98 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_35 ) ;
break;
case V_99 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_17 ) ;
break;
case V_100 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_40 ) ;
break;
case V_101 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_33 ) ;
break;
case V_102 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_16 -> V_45 ) ;
break;
case V_103 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_89 ) ;
break;
case V_104 :
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_105 ) ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_24 = V_93 - V_106 ;
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_90 [ V_24 ] ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_24 = V_93 - V_110 ;
* V_95 = F_72 ( V_93 , V_12 -> V_15 . V_114 [ V_24 ] ) ;
break;
default:
V_96 = - V_115 ;
break;
}
return V_96 ;
}
int F_73 ( struct V_11 * V_12 , T_3 V_93 ,
union V_94 * V_95 )
{
int V_96 = 0 ;
long int V_24 ;
switch ( V_93 ) {
case V_97 :
V_12 -> V_15 . V_16 -> V_34 = F_74 ( V_93 , * V_95 ) ;
break;
case V_98 :
V_12 -> V_15 . V_16 -> V_35 = F_74 ( V_93 , * V_95 ) ;
break;
case V_99 :
V_12 -> V_15 . V_16 -> V_17 = F_74 ( V_93 , * V_95 ) ;
break;
case V_100 :
V_12 -> V_15 . V_16 -> V_40 = F_74 ( V_93 , * V_95 ) ;
break;
case V_101 :
V_12 -> V_15 . V_16 -> V_33 = F_74 ( V_93 , * V_95 ) ;
break;
case V_102 :
V_12 -> V_15 . V_16 -> V_45 = F_74 ( V_93 , * V_95 ) ;
break;
case V_103 : {
T_6 V_116 = F_74 ( V_93 , * V_95 ) ;
if ( V_116 != V_12 -> V_15 . V_89 )
V_96 = - V_115 ;
break;
}
case V_104 : {
T_6 V_116 = F_74 ( V_93 , * V_95 ) ;
if ( V_116 != V_12 -> V_15 . V_105 )
V_96 = - V_115 ;
break;
}
case V_106 :
case V_107 :
case V_108 :
case V_109 : {
T_6 V_116 = F_74 ( V_93 , * V_95 ) ;
V_24 = V_93 - V_106 ;
if ( V_116 != V_12 -> V_15 . V_90 [ V_24 ] )
V_96 = - V_115 ;
break;
}
case V_110 :
case V_111 :
case V_112 :
case V_113 : {
T_6 V_116 = F_74 ( V_93 , * V_95 ) ;
V_24 = V_93 - V_110 ;
if ( V_116 != V_12 -> V_15 . V_114 [ V_24 ] )
V_96 = - V_115 ;
break;
}
default:
V_96 = - V_115 ;
break;
}
return V_96 ;
}
static int F_75 ( struct V_11 * V_12 ,
struct V_117 * V_118 )
{
V_12 -> V_15 . V_90 [ 0 ] &= ~ ( V_119 | V_120 ) ;
if ( V_118 -> V_121 [ 0 ] <= 2048 )
V_12 -> V_15 . V_90 [ 0 ] |= V_118 -> V_121 [ 0 ] ;
V_12 -> V_15 . V_90 [ 0 ] |= V_118 -> V_122 [ 0 ] << V_123 ;
V_12 -> V_15 . V_90 [ 1 ] &= ~ ( V_119 | V_120 ) ;
V_12 -> V_15 . V_90 [ 1 ] |= V_118 -> V_121 [ 1 ] ;
V_12 -> V_15 . V_90 [ 1 ] |= V_118 -> V_122 [ 1 ] << V_123 ;
return 0 ;
}
int F_76 ( struct V_11 * V_12 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_117 V_118 ;
char * V_126 ;
struct V_127 * * V_128 ;
struct V_129 * V_130 [ 2 ] = {} ;
T_3 * V_131 = NULL ;
T_7 V_132 ;
T_6 V_8 ;
int V_133 , V_134 , V_24 ;
if ( V_125 -> V_135 != V_136 )
return - V_115 ;
if ( F_77 ( & V_118 , ( void V_137 * ) ( V_82 ) V_125 -> V_118 ,
sizeof( V_118 ) ) )
return - V_138 ;
if ( V_118 . V_121 [ 1 ] > 64 )
return - V_115 ;
if ( V_118 . V_122 [ 1 ] != V_118 . V_121 [ 1 ] )
return - V_115 ;
if ( V_118 . V_121 [ 2 ] != 0 || V_118 . V_121 [ 3 ] != 0 )
return - V_115 ;
if ( V_118 . V_122 [ 2 ] != 0 || V_118 . V_122 [ 3 ] != 0 )
return - V_115 ;
if ( ! F_78 ( V_118 . V_122 [ 0 ] ) )
return - V_115 ;
V_8 = V_118 . V_121 [ 0 ] >> F_79 ( V_118 . V_122 [ 0 ] ) ;
if ( ! F_78 ( V_8 ) )
return - V_115 ;
V_132 = V_118 . V_121 [ 0 ] + V_118 . V_121 [ 1 ] ;
V_132 *= sizeof( struct V_28 ) ;
if ( V_125 -> V_132 < V_132 )
return - V_115 ;
V_133 = F_80 ( V_125 -> V_139 + V_132 - 1 , V_83 ) -
V_125 -> V_139 / V_83 ;
V_128 = F_81 ( sizeof( struct V_127 * ) * V_133 , V_140 ) ;
if ( ! V_128 )
return - V_141 ;
V_134 = F_82 ( V_125 -> V_139 , V_133 , 1 , V_128 ) ;
if ( V_134 < 0 )
goto V_142;
if ( V_134 != V_133 ) {
V_133 = V_134 ;
V_134 = - V_138 ;
goto V_143;
}
V_126 = F_83 ( V_128 , V_133 , V_144 , V_145 ) ;
if ( ! V_126 ) {
V_134 = - V_141 ;
goto V_143;
}
V_130 [ 0 ] = F_84 ( sizeof( struct V_129 ) * V_118 . V_121 [ 0 ] ,
V_140 ) ;
V_130 [ 1 ] = F_84 ( sizeof( struct V_129 ) * V_118 . V_121 [ 1 ] ,
V_140 ) ;
if ( ! V_130 [ 0 ] || ! V_130 [ 1 ] ) {
V_134 = - V_141 ;
goto V_146;
}
V_131 = F_84 ( sizeof( T_3 ) * V_118 . V_121 [ 1 ] ,
V_140 ) ;
if ( ! V_131 ) {
V_134 = - V_141 ;
goto V_146;
}
F_63 ( V_2 ) ;
V_2 -> V_80 [ 0 ] = V_130 [ 0 ] ;
V_2 -> V_80 [ 1 ] = V_130 [ 1 ] ;
V_2 -> V_79 = V_131 ;
V_2 -> V_30 = (struct V_28 * )
( V_126 + ( V_125 -> V_139 & ( V_83 - 1 ) ) ) ;
V_2 -> V_5 [ 0 ] . V_18 = V_118 . V_121 [ 0 ] ;
V_2 -> V_5 [ 1 ] . V_18 = V_118 . V_121 [ 1 ] ;
V_2 -> V_27 [ 0 ] = 0 ;
V_2 -> V_27 [ 1 ] = V_118 . V_121 [ 0 ] ;
F_75 ( V_12 , & V_118 ) ;
V_2 -> V_81 = V_128 ;
V_2 -> V_84 = V_133 ;
V_2 -> V_5 [ 0 ] . V_6 = V_118 . V_122 [ 0 ] ;
V_2 -> V_5 [ 0 ] . V_8 = V_8 ;
V_2 -> V_5 [ 1 ] . V_6 = V_118 . V_121 [ 1 ] ;
V_2 -> V_5 [ 1 ] . V_8 = 1 ;
F_22 ( V_2 ) ;
return 0 ;
V_146:
F_64 ( V_130 [ 0 ] ) ;
F_64 ( V_130 [ 1 ] ) ;
V_143:
for ( V_24 = 0 ; V_24 < V_133 ; V_24 ++ )
F_68 ( V_128 [ V_24 ] ) ;
V_142:
F_64 ( V_128 ) ;
return V_134 ;
}
int F_85 ( struct V_11 * V_12 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_22 ( V_2 ) ;
F_32 ( V_12 ) ;
return 0 ;
}
static int F_86 ( struct V_11 * V_12 ,
struct V_149 * V_118 )
{
V_12 -> V_15 . V_89 = F_87 ( V_150 ) & ~ V_151 ;
V_12 -> V_15 . V_90 [ 0 ] = F_87 ( V_152 ) &
~ ( V_119 | V_120 ) ;
V_12 -> V_15 . V_90 [ 0 ] |= V_118 [ 0 ] . V_18 ;
V_12 -> V_15 . V_90 [ 0 ] |= V_118 [ 0 ] . V_6 << V_123 ;
V_12 -> V_15 . V_90 [ 1 ] = F_87 ( V_153 ) &
~ ( V_119 | V_120 ) ;
V_12 -> V_15 . V_90 [ 1 ] |= V_118 [ 1 ] . V_18 ;
V_12 -> V_15 . V_90 [ 1 ] |= V_118 [ 1 ] . V_6 << V_123 ;
if ( F_88 ( V_12 , V_154 ) ) {
V_12 -> V_15 . V_114 [ 0 ] = F_87 ( V_155 ) ;
V_12 -> V_15 . V_114 [ 1 ] = F_87 ( V_156 ) ;
V_12 -> V_15 . V_89 &= ~ V_157 ;
V_12 -> V_15 . V_105 = 0 ;
V_12 -> V_15 . V_90 [ 0 ] &= ~ V_158 ;
V_12 -> V_15 . V_90 [ 1 ] &= ~ V_159 ;
}
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
int V_160 = sizeof( struct V_28 ) ;
int V_18 = V_161 + V_162 ;
if ( F_90 ( V_2 ) )
goto V_163;
V_2 -> V_5 [ 0 ] . V_18 = V_161 ;
V_2 -> V_5 [ 1 ] . V_18 = V_162 ;
V_2 -> V_5 [ 0 ] . V_6 = V_164 ;
V_2 -> V_5 [ 0 ] . V_8 =
V_161 / V_164 ;
V_2 -> V_5 [ 1 ] . V_6 = V_162 ;
V_2 -> V_5 [ 1 ] . V_8 = 1 ;
V_2 -> V_30 = F_81 ( V_18 * V_160 , V_140 ) ;
if ( ! V_2 -> V_30 )
return - V_141 ;
V_2 -> V_27 [ 0 ] = 0 ;
V_2 -> V_27 [ 1 ] = V_161 ;
V_2 -> V_80 [ 0 ] = F_84 ( sizeof( struct V_165 ) *
V_2 -> V_5 [ 0 ] . V_18 ,
V_140 ) ;
if ( ! V_2 -> V_80 [ 0 ] )
goto V_163;
V_2 -> V_80 [ 1 ] = F_84 ( sizeof( struct V_165 ) *
V_2 -> V_5 [ 1 ] . V_18 ,
V_140 ) ;
if ( ! V_2 -> V_80 [ 1 ] )
goto V_163;
V_2 -> V_79 = F_84 ( sizeof( T_3 ) *
V_2 -> V_5 [ 1 ] . V_18 ,
V_140 ) ;
if ( ! V_2 -> V_79 )
goto V_163;
F_86 ( V_12 , V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return 0 ;
V_163:
F_63 ( V_2 ) ;
return - 1 ;
}
void F_91 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
F_92 ( V_2 ) ;
}
