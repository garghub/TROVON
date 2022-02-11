struct V_1 * F_1 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_5 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_5 = V_3 -> V_4 ;
V_3 -> V_4 = V_4 ;
F_3 ( & V_7 , V_6 ) ;
return V_5 ;
}
T_1 F_4 ( struct V_8 * V_9 , T_2 V_10 , T_3 V_11 , void * V_12 )
{
if ( ! V_9 -> V_13 || ! V_9 -> V_13 -> V_4 )
return - V_14 ;
return V_9 -> V_13 -> V_4 -> V_15 ( V_9 , V_10 , V_11 , V_12 ) ;
}
T_1 F_5 ( struct V_8 * V_9 , T_2 V_10 , T_3 V_11 , const void * V_12 )
{
if ( ! V_9 -> V_13 || ! V_9 -> V_13 -> V_4 )
return - V_14 ;
return V_9 -> V_13 -> V_4 -> V_16 ( V_9 , V_10 , V_11 , V_12 ) ;
}
static T_4 void F_6 ( struct V_8 * V_9 )
{
F_7 ( V_17 , V_18 ) ;
F_8 ( & V_19 , & V_17 ) ;
do {
F_9 ( V_20 ) ;
F_10 ( & V_7 ) ;
F_11 () ;
F_12 ( & V_7 ) ;
} while ( V_9 -> V_21 );
F_13 ( & V_19 , & V_17 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_22 * V_13 =
F_15 ( V_9 -> V_13 , struct V_22 , V_23 ) ;
unsigned long V_24 = V_25 + V_26 / 20 + 2 ;
T_5 V_27 ;
int V_28 ;
if ( ! V_13 -> V_29 )
return 0 ;
for (; ; ) {
V_28 = F_16 ( V_9 , V_13 -> V_30 + V_31 ,
& V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_27 & V_32 ) == V_13 -> V_33 ) {
V_13 -> V_29 = false ;
return 0 ;
}
if ( F_17 ( V_25 , V_24 ) ) {
F_18 ( V_34 , & V_9 -> V_9 , L_1 ) ;
return - V_35 ;
}
if ( F_19 ( V_18 ) )
return - V_36 ;
if ( ! F_20 () )
F_21 ( 10 ) ;
}
}
static T_1 F_22 ( struct V_8 * V_9 , T_2 V_10 , T_3 V_11 ,
void * V_37 )
{
struct V_22 * V_13 =
F_15 ( V_9 -> V_13 , struct V_22 , V_23 ) ;
int V_28 ;
T_2 V_38 = V_10 + V_11 ;
T_6 * V_12 = V_37 ;
if ( V_10 < 0 || V_10 > V_13 -> V_23 . V_39 || V_38 > V_13 -> V_23 . V_39 )
return - V_40 ;
if ( F_23 ( & V_13 -> V_41 ) )
return - V_36 ;
V_28 = F_14 ( V_9 ) ;
if ( V_28 < 0 )
goto V_42;
while ( V_10 < V_38 ) {
T_7 V_43 ;
unsigned int V_44 , V_45 ;
V_28 = F_24 ( V_9 , V_13 -> V_30 + V_31 ,
V_10 & ~ 3 ) ;
if ( V_28 < 0 )
break;
V_13 -> V_29 = true ;
V_13 -> V_33 = V_32 ;
V_28 = F_14 ( V_9 ) ;
if ( V_28 < 0 )
break;
V_28 = F_25 ( V_9 , V_13 -> V_30 + V_46 , & V_43 ) ;
if ( V_28 < 0 )
break;
V_45 = V_10 & 3 ;
for ( V_44 = 0 ; V_44 < sizeof( T_7 ) ; V_44 ++ ) {
if ( V_44 >= V_45 ) {
* V_12 ++ = V_43 ;
if ( ++ V_10 == V_38 )
break;
}
V_43 >>= 8 ;
}
}
V_42:
F_26 ( & V_13 -> V_41 ) ;
return V_28 ? V_28 : V_11 ;
}
static T_1 F_27 ( struct V_8 * V_9 , T_2 V_10 , T_3 V_11 ,
const void * V_37 )
{
struct V_22 * V_13 =
F_15 ( V_9 -> V_13 , struct V_22 , V_23 ) ;
const T_6 * V_12 = V_37 ;
T_2 V_38 = V_10 + V_11 ;
int V_28 = 0 ;
if ( V_10 < 0 || ( V_10 & 3 ) || ( V_11 & 3 ) || V_38 > V_13 -> V_23 . V_39 )
return - V_40 ;
if ( F_23 ( & V_13 -> V_41 ) )
return - V_36 ;
V_28 = F_14 ( V_9 ) ;
if ( V_28 < 0 )
goto V_42;
while ( V_10 < V_38 ) {
T_7 V_43 ;
V_43 = * V_12 ++ ;
V_43 |= * V_12 ++ << 8 ;
V_43 |= * V_12 ++ << 16 ;
V_43 |= * V_12 ++ << 24 ;
V_28 = F_28 ( V_9 , V_13 -> V_30 + V_46 , V_43 ) ;
if ( V_28 < 0 )
break;
V_28 = F_24 ( V_9 , V_13 -> V_30 + V_31 ,
V_10 | V_32 ) ;
if ( V_28 < 0 )
break;
V_13 -> V_29 = true ;
V_13 -> V_33 = 0 ;
V_28 = F_14 ( V_9 ) ;
if ( V_28 < 0 )
break;
V_10 += sizeof( T_7 ) ;
}
V_42:
F_26 ( & V_13 -> V_41 ) ;
return V_28 ? V_28 : V_11 ;
}
static void F_29 ( struct V_8 * V_9 )
{
F_30 ( F_15 ( V_9 -> V_13 , struct V_22 , V_23 ) ) ;
}
int F_31 ( struct V_8 * V_9 )
{
struct V_22 * V_13 ;
T_6 V_30 ;
V_30 = F_32 ( V_9 , V_47 ) ;
if ( ! V_30 )
return - V_14 ;
V_13 = F_33 ( sizeof( * V_13 ) , V_48 ) ;
if ( ! V_13 )
return - V_49 ;
V_13 -> V_23 . V_39 = V_50 ;
V_13 -> V_23 . V_4 = & V_51 ;
F_34 ( & V_13 -> V_41 ) ;
V_13 -> V_30 = V_30 ;
V_13 -> V_29 = false ;
V_9 -> V_13 = & V_13 -> V_23 ;
return 0 ;
}
void F_35 ( struct V_8 * V_9 )
{
F_36 () ;
F_12 ( & V_7 ) ;
if ( V_9 -> V_21 )
F_6 ( V_9 ) ;
V_9 -> V_21 = 1 ;
F_10 ( & V_7 ) ;
}
bool F_37 ( struct V_8 * V_9 )
{
unsigned long V_6 ;
bool V_52 = true ;
F_2 ( & V_7 , V_6 ) ;
if ( V_9 -> V_21 )
V_52 = false ;
else
V_9 -> V_21 = 1 ;
F_3 ( & V_7 , V_6 ) ;
return V_52 ;
}
void F_38 ( struct V_8 * V_9 )
{
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
F_39 ( ! V_9 -> V_21 ) ;
V_9 -> V_21 = 0 ;
F_40 ( & V_19 ) ;
F_3 ( & V_7 , V_6 ) ;
}
static inline int F_41 ( const struct V_8 * V_9 )
{
return F_42 ( V_9 ) & V_53 ;
}
static inline bool F_43 ( const struct V_8 * V_9 )
{
int type = F_44 ( V_9 ) ;
return type == V_54 ||
type == V_55 ||
type == V_56 ||
type == V_57 ||
type == V_58 ||
type == V_59 ||
type == V_60 ;
}
static inline bool F_45 ( const struct V_8 * V_9 )
{
int type = F_44 ( V_9 ) ;
return ( type == V_56 ||
type == V_58 ) &&
F_42 ( V_9 ) & V_61 ;
}
static inline bool F_46 ( const struct V_8 * V_9 )
{
int type = F_44 ( V_9 ) ;
return type == V_56 ||
type == V_62 ;
}
static bool F_47 ( struct V_8 * V_9 , int V_10 )
{
if ( ! F_48 ( V_9 ) )
return false ;
switch ( V_10 ) {
case V_63 :
return true ;
case V_64 :
case V_65 :
case V_66 :
return true ;
case V_67 :
case V_68 :
case V_69 :
return F_43 ( V_9 ) ;
case V_70 :
case V_71 :
case V_72 :
return F_45 ( V_9 ) ;
case V_73 :
case V_74 :
case V_75 :
return F_46 ( V_9 ) ;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return F_41 ( V_9 ) > 1 ;
default:
return false ;
}
}
int F_49 ( struct V_8 * V_9 , int V_10 , T_5 * V_43 )
{
int V_28 ;
* V_43 = 0 ;
if ( V_10 & 1 )
return - V_40 ;
if ( F_47 ( V_9 , V_10 ) ) {
V_28 = F_50 ( V_9 , F_51 ( V_9 ) + V_10 , V_43 ) ;
if ( V_28 )
* V_43 = 0 ;
return V_28 ;
}
if ( F_48 ( V_9 ) && V_10 == V_72 &&
F_44 ( V_9 ) == V_58 ) {
* V_43 = V_81 ;
}
return 0 ;
}
int F_52 ( struct V_8 * V_9 , int V_10 , T_7 * V_43 )
{
int V_28 ;
* V_43 = 0 ;
if ( V_10 & 3 )
return - V_40 ;
if ( F_47 ( V_9 , V_10 ) ) {
V_28 = F_53 ( V_9 , F_51 ( V_9 ) + V_10 , V_43 ) ;
if ( V_28 )
* V_43 = 0 ;
return V_28 ;
}
if ( F_48 ( V_9 ) && V_10 == V_71 &&
F_44 ( V_9 ) == V_58 ) {
* V_43 = V_81 ;
}
return 0 ;
}
int F_54 ( struct V_8 * V_9 , int V_10 , T_5 V_43 )
{
if ( V_10 & 1 )
return - V_40 ;
if ( ! F_47 ( V_9 , V_10 ) )
return 0 ;
return F_55 ( V_9 , F_51 ( V_9 ) + V_10 , V_43 ) ;
}
int F_56 ( struct V_8 * V_9 , int V_10 , T_7 V_43 )
{
if ( V_10 & 3 )
return - V_40 ;
if ( ! F_47 ( V_9 , V_10 ) )
return 0 ;
return F_57 ( V_9 , F_51 ( V_9 ) + V_10 , V_43 ) ;
}
int F_58 ( struct V_8 * V_9 , int V_10 ,
T_5 V_82 , T_5 V_83 )
{
int V_28 ;
T_5 V_43 ;
V_28 = F_49 ( V_9 , V_10 , & V_43 ) ;
if ( ! V_28 ) {
V_43 &= ~ V_82 ;
V_43 |= V_83 ;
V_28 = F_54 ( V_9 , V_10 , V_43 ) ;
}
return V_28 ;
}
int F_59 ( struct V_8 * V_9 , int V_10 ,
T_7 V_82 , T_7 V_83 )
{
int V_28 ;
T_7 V_43 ;
V_28 = F_52 ( V_9 , V_10 , & V_43 ) ;
if ( ! V_28 ) {
V_43 &= ~ V_82 ;
V_43 |= V_83 ;
V_28 = F_56 ( V_9 , V_10 , V_43 ) ;
}
return V_28 ;
}
