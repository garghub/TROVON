static unsigned int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = 0 ;
if ( F_2 ( V_3 ) )
V_4 |= V_5 ;
if ( V_1 & ( 1UL << V_6 ) ) {
if ( V_3 -> V_7 & V_8 )
V_4 |= V_9 ;
if ( ! ( V_1 & ( 1UL << V_10 ) ) &&
( V_3 -> V_7 & V_11 ) )
V_4 |= V_12 ;
}
return V_4 ;
}
static unsigned int F_3 ( struct V_2 * V_3 )
{
return 1 << F_4 ( V_3 -> V_13 . V_14 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
V_3 -> V_15 = V_3 -> V_16 ;
V_3 -> V_7 &= ~ V_17 ;
V_3 -> V_18 = V_3 -> V_13 . V_19 ;
}
static bool F_6 ( struct V_2 * V_3 , bool V_20 )
{
if ( V_3 -> V_21 -> V_22 ) {
struct V_23 * V_21 = V_3 -> V_21 ;
F_7 ( V_3 , V_20 ) ;
F_8 ( V_21 ) ;
return false ;
} else {
if ( V_20 )
F_9 ( & V_3 -> V_24 , & V_3 -> V_21 -> V_25 ) ;
else
F_10 ( & V_3 -> V_24 , & V_3 -> V_21 -> V_25 ) ;
return true ;
}
}
static bool F_11 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
unsigned int V_14 , int error )
{
struct V_23 * V_21 = V_3 -> V_21 ;
struct V_28 * V_29 = & V_27 -> V_30 [ V_27 -> V_31 ] ;
bool V_32 = false , V_33 ;
F_12 ( V_3 -> V_13 . V_14 & V_14 ) ;
V_3 -> V_13 . V_14 |= V_14 ;
if ( F_13 ( ! error ) )
V_14 = F_3 ( V_3 ) ;
else
V_14 = V_34 ;
switch ( V_14 ) {
case V_9 :
case V_12 :
if ( F_14 ( V_29 ) )
V_27 -> V_35 = V_36 ;
F_15 ( & V_3 -> V_13 . V_37 , V_29 ) ;
break;
case V_5 :
F_15 ( & V_3 -> V_13 . V_37 , & V_27 -> V_38 ) ;
V_32 = F_6 ( V_3 , true ) ;
break;
case V_34 :
F_12 ( ! F_14 ( & V_3 -> V_24 ) ) ;
F_16 ( & V_3 -> V_13 . V_37 ) ;
F_5 ( V_3 ) ;
if ( V_21 -> V_22 )
F_17 ( V_3 , error ) ;
else
F_18 ( V_3 , error ) ;
break;
default:
F_19 () ;
}
V_33 = F_20 ( V_21 , V_27 ) ;
return V_33 | V_32 ;
}
static void F_21 ( struct V_2 * V_39 , int error )
{
struct V_23 * V_21 = V_39 -> V_21 ;
struct V_28 * V_40 ;
bool V_32 = false ;
struct V_2 * V_3 , * V_41 ;
unsigned long V_42 = 0 ;
struct V_26 * V_27 = F_22 ( V_21 , V_39 -> V_43 ) ;
if ( V_21 -> V_22 ) {
struct V_44 * V_45 ;
F_23 ( & V_27 -> V_46 , V_42 ) ;
V_45 = V_21 -> V_22 -> V_47 ( V_21 , V_39 -> V_43 -> V_48 ) ;
F_24 ( V_45 , V_39 -> V_49 , V_27 -> V_50 ) ;
V_39 -> V_49 = - 1 ;
}
V_40 = & V_27 -> V_30 [ V_27 -> V_51 ] ;
F_12 ( V_27 -> V_31 == V_27 -> V_51 ) ;
V_27 -> V_51 ^= 1 ;
if ( ! V_21 -> V_22 )
F_25 ( V_21 , V_39 ) ;
F_26 (rq, n, running, flush.list) {
unsigned int V_14 = F_3 ( V_3 ) ;
F_12 ( V_14 != V_9 && V_14 != V_12 ) ;
V_32 |= F_11 ( V_3 , V_27 , V_14 , error ) ;
}
if ( V_32 || V_27 -> V_52 ) {
F_27 ( V_21 -> V_22 ) ;
F_28 ( V_21 ) ;
}
V_27 -> V_52 = 0 ;
if ( V_21 -> V_22 )
F_29 ( & V_27 -> V_46 , V_42 ) ;
}
static bool F_20 ( struct V_23 * V_21 , struct V_26 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_30 [ V_27 -> V_31 ] ;
struct V_2 * V_53 =
F_30 ( V_29 , struct V_2 , V_13 . V_37 ) ;
struct V_2 * V_39 = V_27 -> V_39 ;
if ( V_27 -> V_31 != V_27 -> V_51 || F_14 ( V_29 ) )
return false ;
if ( ! F_14 ( & V_27 -> V_38 ) &&
F_31 ( V_36 ,
V_27 -> V_35 + V_54 ) )
return false ;
V_27 -> V_31 ^= 1 ;
F_32 ( V_21 , V_39 ) ;
if ( V_21 -> V_22 ) {
struct V_44 * V_45 ;
V_39 -> V_43 = V_53 -> V_43 ;
V_39 -> V_49 = V_53 -> V_49 ;
V_27 -> V_50 = V_53 ;
V_45 = V_21 -> V_22 -> V_47 ( V_21 , V_53 -> V_43 -> V_48 ) ;
F_24 ( V_45 , V_53 -> V_49 , V_39 ) ;
}
V_39 -> V_55 = V_56 ;
V_39 -> V_7 = V_57 | V_17 ;
V_39 -> V_58 = V_53 -> V_58 ;
V_39 -> V_18 = F_21 ;
return F_6 ( V_39 , false ) ;
}
static void F_33 ( struct V_2 * V_3 , int error )
{
struct V_23 * V_21 = V_3 -> V_21 ;
struct V_26 * V_27 = F_22 ( V_21 , NULL ) ;
if ( F_11 ( V_3 , V_27 , V_5 , error ) )
F_28 ( V_21 ) ;
}
static void F_34 ( struct V_2 * V_3 , int error )
{
struct V_23 * V_21 = V_3 -> V_21 ;
struct V_44 * V_45 ;
struct V_59 * V_60 = V_3 -> V_43 ;
unsigned long V_42 ;
struct V_26 * V_27 = F_22 ( V_21 , V_60 ) ;
V_45 = V_21 -> V_22 -> V_47 ( V_21 , V_60 -> V_48 ) ;
F_23 ( & V_27 -> V_46 , V_42 ) ;
if ( F_11 ( V_3 , V_27 , V_5 , error ) )
F_35 ( V_45 , true ) ;
F_29 ( & V_27 -> V_46 , V_42 ) ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_23 * V_21 = V_3 -> V_21 ;
unsigned long V_1 = V_21 -> V_61 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
struct V_26 * V_27 = F_22 ( V_21 , V_3 -> V_43 ) ;
V_3 -> V_7 &= ~ V_8 ;
if ( ! ( V_1 & ( 1UL << V_10 ) ) )
V_3 -> V_7 &= ~ V_11 ;
if ( ! V_4 ) {
if ( V_21 -> V_22 )
F_17 ( V_3 , 0 ) ;
else
F_37 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_12 ( V_3 -> V_15 != V_3 -> V_16 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_9 | V_12 ) ) ) {
if ( V_21 -> V_22 ) {
F_38 ( V_3 , false , false , true ) ;
} else
F_10 ( & V_3 -> V_24 , & V_21 -> V_25 ) ;
return;
}
memset ( & V_3 -> V_13 , 0 , sizeof( V_3 -> V_13 ) ) ;
F_39 ( & V_3 -> V_13 . V_37 ) ;
V_3 -> V_7 |= V_17 ;
V_3 -> V_13 . V_19 = V_3 -> V_18 ;
if ( V_21 -> V_22 ) {
V_3 -> V_18 = F_34 ;
F_40 ( & V_27 -> V_46 ) ;
F_11 ( V_3 , V_27 , V_62 & ~ V_4 , 0 ) ;
F_41 ( & V_27 -> V_46 ) ;
return;
}
V_3 -> V_18 = F_33 ;
F_11 ( V_3 , V_27 , V_62 & ~ V_4 , 0 ) ;
}
int F_42 ( struct V_63 * V_64 , T_1 V_65 ,
T_2 * V_66 )
{
struct V_23 * V_21 ;
struct V_15 * V_15 ;
int V_67 = 0 ;
if ( V_64 -> V_68 == NULL )
return - V_69 ;
V_21 = F_43 ( V_64 ) ;
if ( ! V_21 )
return - V_69 ;
if ( ! V_21 -> V_70 )
return - V_69 ;
V_15 = F_44 ( V_65 , 0 ) ;
V_15 -> V_71 = V_64 ;
V_67 = F_45 ( V_57 , V_15 ) ;
if ( V_66 )
* V_66 = V_15 -> V_72 . V_73 ;
F_46 ( V_15 ) ;
return V_67 ;
}
struct V_26 * F_47 ( struct V_23 * V_21 ,
int V_74 , int V_75 )
{
struct V_26 * V_27 ;
int V_76 = sizeof( struct V_2 ) ;
V_27 = F_48 ( sizeof( * V_27 ) , V_77 , V_74 ) ;
if ( ! V_27 )
goto V_78;
if ( V_21 -> V_22 ) {
F_49 ( & V_27 -> V_46 ) ;
V_76 = F_50 ( V_76 + V_75 , F_51 () ) ;
}
V_27 -> V_39 = F_48 ( V_76 , V_77 , V_74 ) ;
if ( ! V_27 -> V_39 )
goto V_79;
F_39 ( & V_27 -> V_30 [ 0 ] ) ;
F_39 ( & V_27 -> V_30 [ 1 ] ) ;
F_39 ( & V_27 -> V_38 ) ;
return V_27 ;
V_79:
F_52 ( V_27 ) ;
V_78:
return NULL ;
}
void F_53 ( struct V_26 * V_27 )
{
if ( ! V_27 )
return;
F_52 ( V_27 -> V_39 ) ;
F_52 ( V_27 ) ;
}
