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
} else {
V_12 = ~ ( ( ( 1 << ( V_5 * 8 ) ) - 1 ) << ( ( V_4 & 0x3 ) * 8 ) ) ;
}
V_13 = F_4 ( V_7 ) & V_12 ;
V_13 |= V_6 << ( ( V_4 & 0x3 ) * 8 ) ;
F_8 ( V_13 , V_7 ) ;
return V_11 ;
}
struct V_14 * F_11 ( struct V_1 * V_2 , struct V_14 * V_8 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
F_12 ( & V_17 , V_16 ) ;
V_15 = V_2 -> V_8 ;
V_2 -> V_8 = V_8 ;
F_13 ( & V_17 , V_16 ) ;
return V_15 ;
}
static T_3 void F_14 ( struct V_18 * V_19 )
{
F_15 ( V_20 , V_21 ) ;
F_16 ( & V_22 , & V_20 ) ;
do {
F_17 ( V_23 ) ;
F_18 ( & V_17 ) ;
F_19 () ;
F_20 ( & V_17 ) ;
} while ( V_19 -> V_24 );
F_21 ( & V_22 , & V_20 ) ;
}
T_4 F_22 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 , void * V_27 )
{
if ( ! V_19 -> V_28 || ! V_19 -> V_28 -> V_8 )
return - V_29 ;
return V_19 -> V_28 -> V_8 -> V_30 ( V_19 , V_25 , V_26 , V_27 ) ;
}
T_4 F_23 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 , const void * V_27 )
{
if ( ! V_19 -> V_28 || ! V_19 -> V_28 -> V_8 )
return - V_29 ;
return V_19 -> V_28 -> V_8 -> V_31 ( V_19 , V_25 , V_26 , V_27 ) ;
}
int F_24 ( struct V_18 * V_19 , T_6 V_32 )
{
if ( ! V_19 -> V_28 || ! V_19 -> V_28 -> V_8 )
return - V_29 ;
return V_19 -> V_28 -> V_8 -> V_33 ( V_19 , V_32 ) ;
}
static T_6 F_25 ( struct V_18 * V_19 , T_6 V_34 )
{
T_6 V_35 = 0 ;
unsigned char V_36 [ 1 + 2 ] ;
while ( V_35 < V_34 &&
F_22 ( V_19 , V_35 , 1 , V_36 ) == 1 ) {
unsigned char V_37 ;
if ( V_36 [ 0 ] & V_38 ) {
V_37 = F_26 ( V_36 ) ;
if ( ( V_37 == V_39 ) ||
( V_37 == V_40 ) ||
( V_37 == V_41 ) ) {
if ( F_22 ( V_19 , V_35 + 1 , 2 ,
& V_36 [ 1 ] ) != 2 ) {
F_27 ( & V_19 -> V_19 ,
L_1 ,
V_37 , V_35 + 1 ) ;
return 0 ;
}
V_35 += V_42 +
F_28 ( V_36 ) ;
}
} else {
V_35 += V_43 +
F_29 ( V_36 ) ;
V_37 = F_30 ( V_36 ) ;
}
if ( V_37 == V_44 )
return V_35 ;
if ( ( V_37 != V_39 ) &&
( V_37 != V_40 ) &&
( V_37 != V_41 ) ) {
F_27 ( & V_19 -> V_19 ,
L_2 ,
( V_36 [ 0 ] & V_38 ) ? L_3 : L_4 ,
V_37 , V_35 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_45 * V_28 = V_19 -> V_28 ;
unsigned long V_46 = V_47 + F_32 ( 50 ) ;
unsigned long V_48 = 16 ;
T_7 V_49 ;
int V_50 ;
if ( ! V_28 -> V_51 )
return 0 ;
while ( F_33 ( V_47 , V_46 ) ) {
V_50 = F_34 ( V_19 , V_28 -> V_52 + V_53 ,
& V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( ( V_49 & V_54 ) == V_28 -> V_55 ) {
V_28 -> V_51 = 0 ;
return 0 ;
}
if ( F_35 ( V_21 ) )
return - V_56 ;
F_36 ( 10 , V_48 ) ;
if ( V_48 < 1024 )
V_48 *= 2 ;
}
F_27 ( & V_19 -> V_19 , L_5 ) ;
return - V_57 ;
}
static T_4 F_37 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 ,
void * V_58 )
{
struct V_45 * V_28 = V_19 -> V_28 ;
int V_50 ;
T_5 V_59 = V_25 + V_26 ;
T_8 * V_27 = V_58 ;
if ( V_25 < 0 )
return - V_60 ;
if ( ! V_28 -> V_61 ) {
V_28 -> V_61 = 1 ;
V_28 -> V_32 = F_25 ( V_19 , V_28 -> V_32 ) ;
}
if ( V_28 -> V_32 == 0 )
return - V_62 ;
if ( V_25 > V_28 -> V_32 )
return 0 ;
if ( V_59 > V_28 -> V_32 ) {
V_59 = V_28 -> V_32 ;
V_26 = V_59 - V_25 ;
}
if ( F_38 ( & V_28 -> V_63 ) )
return - V_56 ;
V_50 = F_31 ( V_19 ) ;
if ( V_50 < 0 )
goto V_64;
while ( V_25 < V_59 ) {
T_1 V_6 ;
unsigned int V_65 , V_66 ;
V_50 = F_39 ( V_19 , V_28 -> V_52 + V_53 ,
V_25 & ~ 3 ) ;
if ( V_50 < 0 )
break;
V_28 -> V_51 = 1 ;
V_28 -> V_55 = V_54 ;
V_50 = F_31 ( V_19 ) ;
if ( V_50 < 0 )
break;
V_50 = F_40 ( V_19 , V_28 -> V_52 + V_67 , & V_6 ) ;
if ( V_50 < 0 )
break;
V_66 = V_25 & 3 ;
for ( V_65 = 0 ; V_65 < sizeof( T_1 ) ; V_65 ++ ) {
if ( V_65 >= V_66 ) {
* V_27 ++ = V_6 ;
if ( ++ V_25 == V_59 )
break;
}
V_6 >>= 8 ;
}
}
V_64:
F_41 ( & V_28 -> V_63 ) ;
return V_50 ? V_50 : V_26 ;
}
static T_4 F_42 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 ,
const void * V_58 )
{
struct V_45 * V_28 = V_19 -> V_28 ;
const T_8 * V_27 = V_58 ;
T_5 V_59 = V_25 + V_26 ;
int V_50 = 0 ;
if ( V_25 < 0 || ( V_25 & 3 ) || ( V_26 & 3 ) )
return - V_60 ;
if ( ! V_28 -> V_61 ) {
V_28 -> V_61 = 1 ;
V_28 -> V_32 = F_25 ( V_19 , V_28 -> V_32 ) ;
}
if ( V_28 -> V_32 == 0 )
return - V_62 ;
if ( V_59 > V_28 -> V_32 )
return - V_60 ;
if ( F_38 ( & V_28 -> V_63 ) )
return - V_56 ;
V_50 = F_31 ( V_19 ) ;
if ( V_50 < 0 )
goto V_64;
while ( V_25 < V_59 ) {
T_1 V_6 ;
V_6 = * V_27 ++ ;
V_6 |= * V_27 ++ << 8 ;
V_6 |= * V_27 ++ << 16 ;
V_6 |= * V_27 ++ << 24 ;
V_50 = F_43 ( V_19 , V_28 -> V_52 + V_67 , V_6 ) ;
if ( V_50 < 0 )
break;
V_50 = F_39 ( V_19 , V_28 -> V_52 + V_53 ,
V_25 | V_54 ) ;
if ( V_50 < 0 )
break;
V_28 -> V_51 = 1 ;
V_28 -> V_55 = 0 ;
V_50 = F_31 ( V_19 ) ;
if ( V_50 < 0 )
break;
V_25 += sizeof( T_1 ) ;
}
V_64:
F_41 ( & V_28 -> V_63 ) ;
return V_50 ? V_50 : V_26 ;
}
static int F_44 ( struct V_18 * V_19 , T_6 V_32 )
{
struct V_45 * V_28 = V_19 -> V_28 ;
if ( V_32 == 0 || V_32 > V_68 )
return - V_62 ;
V_28 -> V_61 = 1 ;
V_28 -> V_32 = V_32 ;
return 0 ;
}
static T_4 F_45 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 ,
void * V_58 )
{
struct V_18 * V_69 = F_46 ( V_19 -> V_2 ,
F_47 ( F_48 ( V_19 -> V_3 ) , 0 ) ) ;
T_4 V_50 ;
if ( ! V_69 )
return - V_29 ;
V_50 = F_22 ( V_69 , V_25 , V_26 , V_58 ) ;
F_49 ( V_69 ) ;
return V_50 ;
}
static T_4 F_50 ( struct V_18 * V_19 , T_5 V_25 , T_6 V_26 ,
const void * V_58 )
{
struct V_18 * V_69 = F_46 ( V_19 -> V_2 ,
F_47 ( F_48 ( V_19 -> V_3 ) , 0 ) ) ;
T_4 V_50 ;
if ( ! V_69 )
return - V_29 ;
V_50 = F_23 ( V_69 , V_25 , V_26 , V_58 ) ;
F_49 ( V_69 ) ;
return V_50 ;
}
static int F_51 ( struct V_18 * V_19 , T_6 V_32 )
{
struct V_18 * V_69 = F_46 ( V_19 -> V_2 ,
F_47 ( F_48 ( V_19 -> V_3 ) , 0 ) ) ;
int V_50 ;
if ( ! V_69 )
return - V_29 ;
V_50 = F_24 ( V_69 , V_32 ) ;
F_49 ( V_69 ) ;
return V_50 ;
}
int F_52 ( struct V_18 * V_19 )
{
struct V_45 * V_28 ;
T_8 V_52 ;
V_52 = F_53 ( V_19 , V_70 ) ;
if ( ! V_52 )
return - V_29 ;
V_28 = F_54 ( sizeof( * V_28 ) , V_71 ) ;
if ( ! V_28 )
return - V_72 ;
V_28 -> V_32 = V_68 ;
if ( V_19 -> V_73 & V_74 )
V_28 -> V_8 = & V_75 ;
else
V_28 -> V_8 = & V_76 ;
F_55 ( & V_28 -> V_63 ) ;
V_28 -> V_52 = V_52 ;
V_28 -> V_51 = 0 ;
V_28 -> V_61 = 0 ;
V_19 -> V_28 = V_28 ;
return 0 ;
}
void F_56 ( struct V_18 * V_19 )
{
F_57 ( V_19 -> V_28 ) ;
}
void F_58 ( struct V_18 * V_19 )
{
F_59 () ;
F_20 ( & V_17 ) ;
if ( V_19 -> V_24 )
F_14 ( V_19 ) ;
V_19 -> V_24 = 1 ;
F_18 ( & V_17 ) ;
}
bool F_60 ( struct V_18 * V_19 )
{
unsigned long V_16 ;
bool V_77 = true ;
F_12 ( & V_17 , V_16 ) ;
if ( V_19 -> V_24 )
V_77 = false ;
else
V_19 -> V_24 = 1 ;
F_13 ( & V_17 , V_16 ) ;
return V_77 ;
}
void F_61 ( struct V_18 * V_19 )
{
unsigned long V_16 ;
F_12 ( & V_17 , V_16 ) ;
F_62 ( ! V_19 -> V_24 ) ;
V_19 -> V_24 = 0 ;
F_63 ( & V_22 ) ;
F_13 ( & V_17 , V_16 ) ;
}
static inline int F_64 ( const struct V_18 * V_19 )
{
return F_65 ( V_19 ) & V_78 ;
}
static bool F_66 ( const struct V_18 * V_19 )
{
int type = F_67 ( V_19 ) ;
return type == V_79 ||
type == V_80 ;
}
bool F_68 ( const struct V_18 * V_19 )
{
int type = F_67 ( V_19 ) ;
return type == V_81 ||
type == V_82 ||
type == V_79 ||
type == V_83 ||
type == V_80 ||
type == V_84 ||
type == V_85 ;
}
static inline bool F_69 ( const struct V_18 * V_19 )
{
return F_66 ( V_19 ) &&
F_65 ( V_19 ) & V_86 ;
}
static inline bool F_70 ( const struct V_18 * V_19 )
{
int type = F_67 ( V_19 ) ;
return type == V_79 ||
type == V_87 ;
}
static bool F_71 ( struct V_18 * V_19 , int V_25 )
{
if ( ! F_72 ( V_19 ) )
return false ;
switch ( V_25 ) {
case V_88 :
return true ;
case V_89 :
case V_90 :
case V_91 :
return true ;
case V_92 :
case V_93 :
case V_94 :
return F_68 ( V_19 ) ;
case V_95 :
case V_96 :
case V_97 :
return F_69 ( V_19 ) ;
case V_98 :
case V_99 :
case V_100 :
return F_70 ( V_19 ) ;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
return F_64 ( V_19 ) > 1 ;
default:
return false ;
}
}
int F_73 ( struct V_18 * V_19 , int V_25 , T_7 * V_6 )
{
int V_50 ;
* V_6 = 0 ;
if ( V_25 & 1 )
return - V_60 ;
if ( F_71 ( V_19 , V_25 ) ) {
V_50 = F_74 ( V_19 , F_75 ( V_19 ) + V_25 , V_6 ) ;
if ( V_50 )
* V_6 = 0 ;
return V_50 ;
}
if ( F_72 ( V_19 ) && F_66 ( V_19 ) &&
V_25 == V_97 )
* V_6 = V_106 ;
return 0 ;
}
int F_76 ( struct V_18 * V_19 , int V_25 , T_1 * V_6 )
{
int V_50 ;
* V_6 = 0 ;
if ( V_25 & 3 )
return - V_60 ;
if ( F_71 ( V_19 , V_25 ) ) {
V_50 = F_77 ( V_19 , F_75 ( V_19 ) + V_25 , V_6 ) ;
if ( V_50 )
* V_6 = 0 ;
return V_50 ;
}
if ( F_72 ( V_19 ) && F_66 ( V_19 ) &&
V_25 == V_97 )
* V_6 = V_106 ;
return 0 ;
}
int F_78 ( struct V_18 * V_19 , int V_25 , T_7 V_6 )
{
if ( V_25 & 1 )
return - V_60 ;
if ( ! F_71 ( V_19 , V_25 ) )
return 0 ;
return F_79 ( V_19 , F_75 ( V_19 ) + V_25 , V_6 ) ;
}
int F_80 ( struct V_18 * V_19 , int V_25 , T_1 V_6 )
{
if ( V_25 & 3 )
return - V_60 ;
if ( ! F_71 ( V_19 , V_25 ) )
return 0 ;
return F_81 ( V_19 , F_75 ( V_19 ) + V_25 , V_6 ) ;
}
int F_82 ( struct V_18 * V_19 , int V_25 ,
T_7 V_107 , T_7 V_108 )
{
int V_50 ;
T_7 V_6 ;
V_50 = F_73 ( V_19 , V_25 , & V_6 ) ;
if ( ! V_50 ) {
V_6 &= ~ V_107 ;
V_6 |= V_108 ;
V_50 = F_78 ( V_19 , V_25 , V_6 ) ;
}
return V_50 ;
}
int F_83 ( struct V_18 * V_19 , int V_25 ,
T_1 V_107 , T_1 V_108 )
{
int V_50 ;
T_1 V_6 ;
V_50 = F_76 ( V_19 , V_25 , & V_6 ) ;
if ( ! V_50 ) {
V_6 &= ~ V_107 ;
V_6 |= V_108 ;
V_50 = F_80 ( V_19 , V_25 , V_6 ) ;
}
return V_50 ;
}
