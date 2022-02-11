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
T_3 F_14 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 , void * V_22 )
{
if ( ! V_19 -> V_23 || ! V_19 -> V_23 -> V_8 )
return - V_24 ;
return V_19 -> V_23 -> V_8 -> V_25 ( V_19 , V_20 , V_21 , V_22 ) ;
}
T_3 F_15 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 , const void * V_22 )
{
if ( ! V_19 -> V_23 || ! V_19 -> V_23 -> V_8 )
return - V_24 ;
return V_19 -> V_23 -> V_8 -> V_26 ( V_19 , V_20 , V_21 , V_22 ) ;
}
static T_6 void F_16 ( struct V_18 * V_19 )
{
F_17 ( V_27 , V_28 ) ;
F_18 ( & V_29 , & V_27 ) ;
do {
F_19 ( V_30 ) ;
F_20 ( & V_17 ) ;
F_21 () ;
F_22 ( & V_17 ) ;
} while ( V_19 -> V_31 );
F_23 ( & V_29 , & V_27 ) ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_32 * V_23 =
F_25 ( V_19 -> V_23 , struct V_32 , V_33 ) ;
unsigned long V_34 = V_35 + V_36 / 20 + 2 ;
T_7 V_37 ;
int V_38 ;
if ( ! V_23 -> V_39 )
return 0 ;
for (; ; ) {
V_38 = F_26 ( V_19 , V_23 -> V_40 + V_41 ,
& V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ( V_37 & V_42 ) == V_23 -> V_43 ) {
V_23 -> V_39 = false ;
return 0 ;
}
if ( F_27 ( V_35 , V_34 ) ) {
F_28 ( V_44 , & V_19 -> V_19 , L_1 ) ;
return - V_45 ;
}
if ( F_29 ( V_28 ) )
return - V_46 ;
if ( ! F_30 () )
F_31 ( 10 ) ;
}
}
static T_3 F_32 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 ,
void * V_47 )
{
struct V_32 * V_23 =
F_25 ( V_19 -> V_23 , struct V_32 , V_33 ) ;
int V_38 ;
T_4 V_48 = V_20 + V_21 ;
T_8 * V_22 = V_47 ;
if ( V_20 < 0 || V_20 > V_23 -> V_33 . V_49 || V_48 > V_23 -> V_33 . V_49 )
return - V_50 ;
if ( F_33 ( & V_23 -> V_51 ) )
return - V_46 ;
V_38 = F_24 ( V_19 ) ;
if ( V_38 < 0 )
goto V_52;
while ( V_20 < V_48 ) {
T_1 V_6 ;
unsigned int V_53 , V_54 ;
V_38 = F_34 ( V_19 , V_23 -> V_40 + V_41 ,
V_20 & ~ 3 ) ;
if ( V_38 < 0 )
break;
V_23 -> V_39 = true ;
V_23 -> V_43 = V_42 ;
V_38 = F_24 ( V_19 ) ;
if ( V_38 < 0 )
break;
V_38 = F_35 ( V_19 , V_23 -> V_40 + V_55 , & V_6 ) ;
if ( V_38 < 0 )
break;
V_54 = V_20 & 3 ;
for ( V_53 = 0 ; V_53 < sizeof( T_1 ) ; V_53 ++ ) {
if ( V_53 >= V_54 ) {
* V_22 ++ = V_6 ;
if ( ++ V_20 == V_48 )
break;
}
V_6 >>= 8 ;
}
}
V_52:
F_36 ( & V_23 -> V_51 ) ;
return V_38 ? V_38 : V_21 ;
}
static T_3 F_37 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 ,
const void * V_47 )
{
struct V_32 * V_23 =
F_25 ( V_19 -> V_23 , struct V_32 , V_33 ) ;
const T_8 * V_22 = V_47 ;
T_4 V_48 = V_20 + V_21 ;
int V_38 = 0 ;
if ( V_20 < 0 || ( V_20 & 3 ) || ( V_21 & 3 ) || V_48 > V_23 -> V_33 . V_49 )
return - V_50 ;
if ( F_33 ( & V_23 -> V_51 ) )
return - V_46 ;
V_38 = F_24 ( V_19 ) ;
if ( V_38 < 0 )
goto V_52;
while ( V_20 < V_48 ) {
T_1 V_6 ;
V_6 = * V_22 ++ ;
V_6 |= * V_22 ++ << 8 ;
V_6 |= * V_22 ++ << 16 ;
V_6 |= * V_22 ++ << 24 ;
V_38 = F_38 ( V_19 , V_23 -> V_40 + V_55 , V_6 ) ;
if ( V_38 < 0 )
break;
V_38 = F_34 ( V_19 , V_23 -> V_40 + V_41 ,
V_20 | V_42 ) ;
if ( V_38 < 0 )
break;
V_23 -> V_39 = true ;
V_23 -> V_43 = 0 ;
V_38 = F_24 ( V_19 ) ;
if ( V_38 < 0 )
break;
V_20 += sizeof( T_1 ) ;
}
V_52:
F_36 ( & V_23 -> V_51 ) ;
return V_38 ? V_38 : V_21 ;
}
static void F_39 ( struct V_18 * V_19 )
{
F_40 ( F_25 ( V_19 -> V_23 , struct V_32 , V_33 ) ) ;
}
static T_3 F_41 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 ,
void * V_47 )
{
struct V_18 * V_56 = F_42 ( V_19 -> V_2 ,
F_43 ( F_44 ( V_19 -> V_3 ) , 0 ) ) ;
T_3 V_38 ;
if ( ! V_56 )
return - V_24 ;
V_38 = F_14 ( V_56 , V_20 , V_21 , V_47 ) ;
F_45 ( V_56 ) ;
return V_38 ;
}
static T_3 F_46 ( struct V_18 * V_19 , T_4 V_20 , T_5 V_21 ,
const void * V_47 )
{
struct V_18 * V_56 = F_42 ( V_19 -> V_2 ,
F_43 ( F_44 ( V_19 -> V_3 ) , 0 ) ) ;
T_3 V_38 ;
if ( ! V_56 )
return - V_24 ;
V_38 = F_15 ( V_56 , V_20 , V_21 , V_47 ) ;
F_45 ( V_56 ) ;
return V_38 ;
}
int F_47 ( struct V_18 * V_19 )
{
struct V_32 * V_23 ;
T_8 V_40 ;
V_40 = F_48 ( V_19 , V_57 ) ;
if ( ! V_40 )
return - V_24 ;
V_23 = F_49 ( sizeof( * V_23 ) , V_58 ) ;
if ( ! V_23 )
return - V_59 ;
V_23 -> V_33 . V_49 = V_60 ;
if ( V_19 -> V_61 & V_62 )
V_23 -> V_33 . V_8 = & V_63 ;
else
V_23 -> V_33 . V_8 = & V_64 ;
F_50 ( & V_23 -> V_51 ) ;
V_23 -> V_40 = V_40 ;
V_23 -> V_39 = false ;
V_19 -> V_23 = & V_23 -> V_33 ;
return 0 ;
}
void F_51 ( struct V_18 * V_19 )
{
F_52 () ;
F_22 ( & V_17 ) ;
if ( V_19 -> V_31 )
F_16 ( V_19 ) ;
V_19 -> V_31 = 1 ;
F_20 ( & V_17 ) ;
}
bool F_53 ( struct V_18 * V_19 )
{
unsigned long V_16 ;
bool V_65 = true ;
F_12 ( & V_17 , V_16 ) ;
if ( V_19 -> V_31 )
V_65 = false ;
else
V_19 -> V_31 = 1 ;
F_13 ( & V_17 , V_16 ) ;
return V_65 ;
}
void F_54 ( struct V_18 * V_19 )
{
unsigned long V_16 ;
F_12 ( & V_17 , V_16 ) ;
F_55 ( ! V_19 -> V_31 ) ;
V_19 -> V_31 = 0 ;
F_56 ( & V_29 ) ;
F_13 ( & V_17 , V_16 ) ;
}
static inline int F_57 ( const struct V_18 * V_19 )
{
return F_58 ( V_19 ) & V_66 ;
}
static bool F_59 ( const struct V_18 * V_19 )
{
int type = F_60 ( V_19 ) ;
return type == V_67 ||
type == V_68 ;
}
bool F_61 ( const struct V_18 * V_19 )
{
int type = F_60 ( V_19 ) ;
return type == V_69 ||
type == V_70 ||
type == V_67 ||
type == V_71 ||
type == V_68 ||
type == V_72 ||
type == V_73 ;
}
static inline bool F_62 ( const struct V_18 * V_19 )
{
return F_59 ( V_19 ) &&
F_58 ( V_19 ) & V_74 ;
}
static inline bool F_63 ( const struct V_18 * V_19 )
{
int type = F_60 ( V_19 ) ;
return type == V_67 ||
type == V_75 ;
}
static bool F_64 ( struct V_18 * V_19 , int V_20 )
{
if ( ! F_65 ( V_19 ) )
return false ;
switch ( V_20 ) {
case V_76 :
return true ;
case V_77 :
case V_78 :
case V_79 :
return true ;
case V_80 :
case V_81 :
case V_82 :
return F_61 ( V_19 ) ;
case V_83 :
case V_84 :
case V_85 :
return F_62 ( V_19 ) ;
case V_86 :
case V_87 :
case V_88 :
return F_63 ( V_19 ) ;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
return F_57 ( V_19 ) > 1 ;
default:
return false ;
}
}
int F_66 ( struct V_18 * V_19 , int V_20 , T_7 * V_6 )
{
int V_38 ;
* V_6 = 0 ;
if ( V_20 & 1 )
return - V_50 ;
if ( F_64 ( V_19 , V_20 ) ) {
V_38 = F_67 ( V_19 , F_68 ( V_19 ) + V_20 , V_6 ) ;
if ( V_38 )
* V_6 = 0 ;
return V_38 ;
}
if ( F_65 ( V_19 ) && F_59 ( V_19 ) &&
V_20 == V_85 )
* V_6 = V_94 ;
return 0 ;
}
int F_69 ( struct V_18 * V_19 , int V_20 , T_1 * V_6 )
{
int V_38 ;
* V_6 = 0 ;
if ( V_20 & 3 )
return - V_50 ;
if ( F_64 ( V_19 , V_20 ) ) {
V_38 = F_70 ( V_19 , F_68 ( V_19 ) + V_20 , V_6 ) ;
if ( V_38 )
* V_6 = 0 ;
return V_38 ;
}
if ( F_65 ( V_19 ) && F_59 ( V_19 ) &&
V_20 == V_85 )
* V_6 = V_94 ;
return 0 ;
}
int F_71 ( struct V_18 * V_19 , int V_20 , T_7 V_6 )
{
if ( V_20 & 1 )
return - V_50 ;
if ( ! F_64 ( V_19 , V_20 ) )
return 0 ;
return F_72 ( V_19 , F_68 ( V_19 ) + V_20 , V_6 ) ;
}
int F_73 ( struct V_18 * V_19 , int V_20 , T_1 V_6 )
{
if ( V_20 & 3 )
return - V_50 ;
if ( ! F_64 ( V_19 , V_20 ) )
return 0 ;
return F_74 ( V_19 , F_68 ( V_19 ) + V_20 , V_6 ) ;
}
int F_75 ( struct V_18 * V_19 , int V_20 ,
T_7 V_95 , T_7 V_96 )
{
int V_38 ;
T_7 V_6 ;
V_38 = F_66 ( V_19 , V_20 , & V_6 ) ;
if ( ! V_38 ) {
V_6 &= ~ V_95 ;
V_6 |= V_96 ;
V_38 = F_71 ( V_19 , V_20 , V_6 ) ;
}
return V_38 ;
}
int F_76 ( struct V_18 * V_19 , int V_20 ,
T_1 V_95 , T_1 V_96 )
{
int V_38 ;
T_1 V_6 ;
V_38 = F_69 ( V_19 , V_20 , & V_6 ) ;
if ( ! V_38 ) {
V_6 &= ~ V_95 ;
V_6 |= V_96 ;
V_38 = F_73 ( V_19 , V_20 , V_6 ) ;
}
return V_38 ;
}
