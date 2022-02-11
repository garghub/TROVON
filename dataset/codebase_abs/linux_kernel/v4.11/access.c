int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
void T_2 * V_7 ;
V_7 = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 ) ;
if ( ! V_7 ) {
* V_6 = ~ 0 ;
return V_10 ;
}
if ( V_5 == 1 )
* V_6 = F_2 ( V_7 ) ;
else if ( V_5 == 2 )
* V_6 = F_3 ( V_7 ) ;
else
* V_6 = F_4 ( V_7 ) ;
return V_11 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
void T_2 * V_7 ;
V_7 = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 ) ;
if ( ! V_7 )
return V_10 ;
if ( V_5 == 1 )
F_6 ( V_6 , V_7 ) ;
else if ( V_5 == 2 )
F_7 ( V_6 , V_7 ) ;
else
F_8 ( V_6 , V_7 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
void T_2 * V_7 ;
V_7 = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 & ~ 0x3 ) ;
if ( ! V_7 ) {
* V_6 = ~ 0 ;
return V_10 ;
}
* V_6 = F_4 ( V_7 ) ;
if ( V_5 <= 2 )
* V_6 = ( * V_6 >> ( 8 * ( V_4 & 3 ) ) ) & ( ( 1 << ( V_5 * 8 ) ) - 1 ) ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
void T_2 * V_7 ;
T_1 V_12 , V_13 ;
V_7 = V_2 -> V_8 -> V_9 ( V_2 , V_3 , V_4 & ~ 0x3 ) ;
if ( ! V_7 )
return V_10 ;
if ( V_5 == 4 ) {
F_8 ( V_6 , V_7 ) ;
return V_11 ;
}
F_11 ( & V_2 -> V_14 , L_1 ,
V_5 , F_12 ( V_2 ) , V_2 -> V_15 ,
F_13 ( V_3 ) , F_14 ( V_3 ) , V_4 ) ;
V_12 = ~ ( ( ( 1 << ( V_5 * 8 ) ) - 1 ) << ( ( V_4 & 0x3 ) * 8 ) ) ;
V_13 = F_4 ( V_7 ) & V_12 ;
V_13 |= V_6 << ( ( V_4 & 0x3 ) * 8 ) ;
F_8 ( V_13 , V_7 ) ;
return V_11 ;
}
struct V_16 * F_15 ( struct V_1 * V_2 , struct V_16 * V_8 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
F_16 ( & V_19 , V_18 ) ;
V_17 = V_2 -> V_8 ;
V_2 -> V_8 = V_8 ;
F_17 ( & V_19 , V_18 ) ;
return V_17 ;
}
static T_3 void F_18 ( struct V_20 * V_14 )
{
F_19 ( V_21 , V_22 ) ;
F_20 ( & V_23 , & V_21 ) ;
do {
F_21 ( V_24 ) ;
F_22 ( & V_19 ) ;
F_23 () ;
F_24 ( & V_19 ) ;
} while ( V_14 -> V_25 );
F_25 ( & V_23 , & V_21 ) ;
}
T_4 F_26 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 , void * V_28 )
{
if ( ! V_14 -> V_29 || ! V_14 -> V_29 -> V_8 )
return - V_30 ;
return V_14 -> V_29 -> V_8 -> V_31 ( V_14 , V_26 , V_27 , V_28 ) ;
}
T_4 F_27 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 , const void * V_28 )
{
if ( ! V_14 -> V_29 || ! V_14 -> V_29 -> V_8 )
return - V_30 ;
return V_14 -> V_29 -> V_8 -> V_32 ( V_14 , V_26 , V_27 , V_28 ) ;
}
int F_28 ( struct V_20 * V_14 , T_6 V_33 )
{
if ( ! V_14 -> V_29 || ! V_14 -> V_29 -> V_8 )
return - V_30 ;
return V_14 -> V_29 -> V_8 -> V_34 ( V_14 , V_33 ) ;
}
static T_6 F_29 ( struct V_20 * V_14 , T_6 V_35 )
{
T_6 V_36 = 0 ;
unsigned char V_37 [ 1 + 2 ] ;
while ( V_36 < V_35 &&
F_26 ( V_14 , V_36 , 1 , V_37 ) == 1 ) {
unsigned char V_38 ;
if ( V_37 [ 0 ] & V_39 ) {
V_38 = F_30 ( V_37 ) ;
if ( ( V_38 == V_40 ) ||
( V_38 == V_41 ) ||
( V_38 == V_42 ) ) {
if ( F_26 ( V_14 , V_36 + 1 , 2 ,
& V_37 [ 1 ] ) != 2 ) {
F_31 ( & V_14 -> V_14 ,
L_2 ,
V_38 , V_36 + 1 ) ;
return 0 ;
}
V_36 += V_43 +
F_32 ( V_37 ) ;
}
} else {
V_36 += V_44 +
F_33 ( V_37 ) ;
V_38 = F_34 ( V_37 ) ;
}
if ( V_38 == V_45 )
return V_36 ;
if ( ( V_38 != V_40 ) &&
( V_38 != V_41 ) &&
( V_38 != V_42 ) ) {
F_31 ( & V_14 -> V_14 ,
L_3 ,
( V_37 [ 0 ] & V_39 ) ? L_4 : L_5 ,
V_38 , V_36 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_35 ( struct V_20 * V_14 )
{
struct V_46 * V_29 = V_14 -> V_29 ;
unsigned long V_47 = V_48 + F_36 ( 125 ) ;
unsigned long V_49 = 16 ;
T_7 V_50 ;
int V_51 ;
if ( ! V_29 -> V_52 )
return 0 ;
while ( F_37 ( V_48 , V_47 ) ) {
V_51 = F_38 ( V_14 , V_29 -> V_53 + V_54 ,
& V_50 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ( V_50 & V_55 ) == V_29 -> V_56 ) {
V_29 -> V_52 = 0 ;
return 0 ;
}
if ( F_39 ( V_22 ) )
return - V_57 ;
F_40 ( 10 , V_49 ) ;
if ( V_49 < 1024 )
V_49 *= 2 ;
}
F_31 ( & V_14 -> V_14 , L_6 ) ;
return - V_58 ;
}
static T_4 F_41 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 ,
void * V_59 )
{
struct V_46 * V_29 = V_14 -> V_29 ;
int V_51 ;
T_5 V_60 = V_26 + V_27 ;
T_8 * V_28 = V_59 ;
if ( V_26 < 0 )
return - V_61 ;
if ( ! V_29 -> V_62 ) {
V_29 -> V_62 = 1 ;
V_29 -> V_33 = F_29 ( V_14 , V_29 -> V_33 ) ;
}
if ( V_29 -> V_33 == 0 )
return - V_63 ;
if ( V_26 > V_29 -> V_33 )
return 0 ;
if ( V_60 > V_29 -> V_33 ) {
V_60 = V_29 -> V_33 ;
V_27 = V_60 - V_26 ;
}
if ( F_42 ( & V_29 -> V_64 ) )
return - V_57 ;
V_51 = F_35 ( V_14 ) ;
if ( V_51 < 0 )
goto V_65;
while ( V_26 < V_60 ) {
T_1 V_6 ;
unsigned int V_66 , V_67 ;
V_51 = F_43 ( V_14 , V_29 -> V_53 + V_54 ,
V_26 & ~ 3 ) ;
if ( V_51 < 0 )
break;
V_29 -> V_52 = 1 ;
V_29 -> V_56 = V_55 ;
V_51 = F_35 ( V_14 ) ;
if ( V_51 < 0 )
break;
V_51 = F_44 ( V_14 , V_29 -> V_53 + V_68 , & V_6 ) ;
if ( V_51 < 0 )
break;
V_67 = V_26 & 3 ;
for ( V_66 = 0 ; V_66 < sizeof( T_1 ) ; V_66 ++ ) {
if ( V_66 >= V_67 ) {
* V_28 ++ = V_6 ;
if ( ++ V_26 == V_60 )
break;
}
V_6 >>= 8 ;
}
}
V_65:
F_45 ( & V_29 -> V_64 ) ;
return V_51 ? V_51 : V_27 ;
}
static T_4 F_46 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 ,
const void * V_59 )
{
struct V_46 * V_29 = V_14 -> V_29 ;
const T_8 * V_28 = V_59 ;
T_5 V_60 = V_26 + V_27 ;
int V_51 = 0 ;
if ( V_26 < 0 || ( V_26 & 3 ) || ( V_27 & 3 ) )
return - V_61 ;
if ( ! V_29 -> V_62 ) {
V_29 -> V_62 = 1 ;
V_29 -> V_33 = F_29 ( V_14 , V_29 -> V_33 ) ;
}
if ( V_29 -> V_33 == 0 )
return - V_63 ;
if ( V_60 > V_29 -> V_33 )
return - V_61 ;
if ( F_42 ( & V_29 -> V_64 ) )
return - V_57 ;
V_51 = F_35 ( V_14 ) ;
if ( V_51 < 0 )
goto V_65;
while ( V_26 < V_60 ) {
T_1 V_6 ;
V_6 = * V_28 ++ ;
V_6 |= * V_28 ++ << 8 ;
V_6 |= * V_28 ++ << 16 ;
V_6 |= * V_28 ++ << 24 ;
V_51 = F_47 ( V_14 , V_29 -> V_53 + V_68 , V_6 ) ;
if ( V_51 < 0 )
break;
V_51 = F_43 ( V_14 , V_29 -> V_53 + V_54 ,
V_26 | V_55 ) ;
if ( V_51 < 0 )
break;
V_29 -> V_52 = 1 ;
V_29 -> V_56 = 0 ;
V_51 = F_35 ( V_14 ) ;
if ( V_51 < 0 )
break;
V_26 += sizeof( T_1 ) ;
}
V_65:
F_45 ( & V_29 -> V_64 ) ;
return V_51 ? V_51 : V_27 ;
}
static int F_48 ( struct V_20 * V_14 , T_6 V_33 )
{
struct V_46 * V_29 = V_14 -> V_29 ;
if ( V_33 == 0 || V_33 > V_69 )
return - V_63 ;
V_29 -> V_62 = 1 ;
V_29 -> V_33 = V_33 ;
return 0 ;
}
static T_4 F_49 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 ,
void * V_59 )
{
struct V_20 * V_70 = F_50 ( V_14 -> V_2 ,
F_51 ( F_13 ( V_14 -> V_3 ) , 0 ) ) ;
T_4 V_51 ;
if ( ! V_70 )
return - V_30 ;
V_51 = F_26 ( V_70 , V_26 , V_27 , V_59 ) ;
F_52 ( V_70 ) ;
return V_51 ;
}
static T_4 F_53 ( struct V_20 * V_14 , T_5 V_26 , T_6 V_27 ,
const void * V_59 )
{
struct V_20 * V_70 = F_50 ( V_14 -> V_2 ,
F_51 ( F_13 ( V_14 -> V_3 ) , 0 ) ) ;
T_4 V_51 ;
if ( ! V_70 )
return - V_30 ;
V_51 = F_27 ( V_70 , V_26 , V_27 , V_59 ) ;
F_52 ( V_70 ) ;
return V_51 ;
}
static int F_54 ( struct V_20 * V_14 , T_6 V_33 )
{
struct V_20 * V_70 = F_50 ( V_14 -> V_2 ,
F_51 ( F_13 ( V_14 -> V_3 ) , 0 ) ) ;
int V_51 ;
if ( ! V_70 )
return - V_30 ;
V_51 = F_28 ( V_70 , V_33 ) ;
F_52 ( V_70 ) ;
return V_51 ;
}
int F_55 ( struct V_20 * V_14 )
{
struct V_46 * V_29 ;
T_8 V_53 ;
V_53 = F_56 ( V_14 , V_71 ) ;
if ( ! V_53 )
return - V_30 ;
V_29 = F_57 ( sizeof( * V_29 ) , V_72 ) ;
if ( ! V_29 )
return - V_73 ;
V_29 -> V_33 = V_69 ;
if ( V_14 -> V_74 & V_75 )
V_29 -> V_8 = & V_76 ;
else
V_29 -> V_8 = & V_77 ;
F_58 ( & V_29 -> V_64 ) ;
V_29 -> V_53 = V_53 ;
V_29 -> V_52 = 0 ;
V_29 -> V_62 = 0 ;
V_14 -> V_29 = V_29 ;
return 0 ;
}
void F_59 ( struct V_20 * V_14 )
{
F_60 ( V_14 -> V_29 ) ;
}
void F_61 ( struct V_20 * V_14 )
{
F_62 () ;
F_24 ( & V_19 ) ;
if ( V_14 -> V_25 )
F_18 ( V_14 ) ;
V_14 -> V_25 = 1 ;
F_22 ( & V_19 ) ;
}
bool F_63 ( struct V_20 * V_14 )
{
unsigned long V_18 ;
bool V_78 = true ;
F_16 ( & V_19 , V_18 ) ;
if ( V_14 -> V_25 )
V_78 = false ;
else
V_14 -> V_25 = 1 ;
F_17 ( & V_19 , V_18 ) ;
return V_78 ;
}
void F_64 ( struct V_20 * V_14 )
{
unsigned long V_18 ;
F_16 ( & V_19 , V_18 ) ;
F_65 ( ! V_14 -> V_25 ) ;
V_14 -> V_25 = 0 ;
F_17 ( & V_19 , V_18 ) ;
F_66 ( & V_23 ) ;
}
static inline int F_67 ( const struct V_20 * V_14 )
{
return F_68 ( V_14 ) & V_79 ;
}
static bool F_69 ( const struct V_20 * V_14 )
{
int type = F_70 ( V_14 ) ;
return type == V_80 ||
type == V_81 ;
}
bool F_71 ( const struct V_20 * V_14 )
{
int type = F_70 ( V_14 ) ;
return type == V_82 ||
type == V_83 ||
type == V_80 ||
type == V_84 ||
type == V_81 ||
type == V_85 ||
type == V_86 ;
}
static inline bool F_72 ( const struct V_20 * V_14 )
{
return F_69 ( V_14 ) &&
F_68 ( V_14 ) & V_87 ;
}
static inline bool F_73 ( const struct V_20 * V_14 )
{
int type = F_70 ( V_14 ) ;
return type == V_80 ||
type == V_88 ;
}
static bool F_74 ( struct V_20 * V_14 , int V_26 )
{
if ( ! F_75 ( V_14 ) )
return false ;
switch ( V_26 ) {
case V_89 :
return true ;
case V_90 :
case V_91 :
case V_92 :
return true ;
case V_93 :
case V_94 :
case V_95 :
return F_71 ( V_14 ) ;
case V_96 :
case V_97 :
case V_98 :
return F_72 ( V_14 ) ;
case V_99 :
case V_100 :
case V_101 :
return F_73 ( V_14 ) ;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
return F_67 ( V_14 ) > 1 ;
default:
return false ;
}
}
int F_76 ( struct V_20 * V_14 , int V_26 , T_7 * V_6 )
{
int V_51 ;
* V_6 = 0 ;
if ( V_26 & 1 )
return - V_61 ;
if ( F_74 ( V_14 , V_26 ) ) {
V_51 = F_77 ( V_14 , F_78 ( V_14 ) + V_26 , V_6 ) ;
if ( V_51 )
* V_6 = 0 ;
return V_51 ;
}
if ( F_75 ( V_14 ) && F_69 ( V_14 ) &&
V_26 == V_98 )
* V_6 = V_107 ;
return 0 ;
}
int F_79 ( struct V_20 * V_14 , int V_26 , T_1 * V_6 )
{
int V_51 ;
* V_6 = 0 ;
if ( V_26 & 3 )
return - V_61 ;
if ( F_74 ( V_14 , V_26 ) ) {
V_51 = F_80 ( V_14 , F_78 ( V_14 ) + V_26 , V_6 ) ;
if ( V_51 )
* V_6 = 0 ;
return V_51 ;
}
if ( F_75 ( V_14 ) && F_69 ( V_14 ) &&
V_26 == V_98 )
* V_6 = V_107 ;
return 0 ;
}
int F_81 ( struct V_20 * V_14 , int V_26 , T_7 V_6 )
{
if ( V_26 & 1 )
return - V_61 ;
if ( ! F_74 ( V_14 , V_26 ) )
return 0 ;
return F_82 ( V_14 , F_78 ( V_14 ) + V_26 , V_6 ) ;
}
int F_83 ( struct V_20 * V_14 , int V_26 , T_1 V_6 )
{
if ( V_26 & 3 )
return - V_61 ;
if ( ! F_74 ( V_14 , V_26 ) )
return 0 ;
return F_84 ( V_14 , F_78 ( V_14 ) + V_26 , V_6 ) ;
}
int F_85 ( struct V_20 * V_14 , int V_26 ,
T_7 V_108 , T_7 V_109 )
{
int V_51 ;
T_7 V_6 ;
V_51 = F_76 ( V_14 , V_26 , & V_6 ) ;
if ( ! V_51 ) {
V_6 &= ~ V_108 ;
V_6 |= V_109 ;
V_51 = F_81 ( V_14 , V_26 , V_6 ) ;
}
return V_51 ;
}
int F_86 ( struct V_20 * V_14 , int V_26 ,
T_1 V_108 , T_1 V_109 )
{
int V_51 ;
T_1 V_6 ;
V_51 = F_79 ( V_14 , V_26 , & V_6 ) ;
if ( ! V_51 ) {
V_6 &= ~ V_108 ;
V_6 |= V_109 ;
V_51 = F_83 ( V_14 , V_26 , V_6 ) ;
}
return V_51 ;
}
