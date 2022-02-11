static unsigned int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = 0 ;
if ( F_2 ( V_3 ) )
V_4 |= V_5 ;
if ( V_1 & V_6 ) {
if ( V_3 -> V_7 & V_6 )
V_4 |= V_8 ;
if ( ! ( V_1 & V_9 ) && ( V_3 -> V_7 & V_9 ) )
V_4 |= V_10 ;
}
return V_4 ;
}
static unsigned int F_3 ( struct V_2 * V_3 )
{
return 1 << F_4 ( V_3 -> V_11 . V_12 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
V_3 -> V_13 = V_3 -> V_14 ;
V_3 -> V_7 &= ~ V_15 ;
V_3 -> V_16 = V_3 -> V_11 . V_17 ;
F_6 ( V_3 ) ;
}
static bool F_7 ( struct V_2 * V_3 , bool V_18 )
{
if ( V_3 -> V_19 -> V_20 ) {
struct V_21 * V_19 = V_3 -> V_19 ;
F_8 ( V_3 , V_18 ) ;
F_9 ( V_19 ) ;
return false ;
} else {
if ( V_18 )
F_10 ( & V_3 -> V_22 , & V_3 -> V_19 -> V_23 ) ;
else
F_11 ( & V_3 -> V_22 , & V_3 -> V_19 -> V_23 ) ;
return true ;
}
}
static bool F_12 ( struct V_2 * V_3 , unsigned int V_12 ,
int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
struct V_24 * V_25 = & V_19 -> V_26 [ V_19 -> V_27 ] ;
bool V_28 = false , V_29 ;
F_13 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_14 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_30 ;
switch ( V_12 ) {
case V_8 :
case V_10 :
if ( F_15 ( V_25 ) )
V_19 -> V_31 = V_32 ;
F_16 ( & V_3 -> V_11 . V_33 , V_25 ) ;
break;
case V_5 :
F_16 ( & V_3 -> V_11 . V_33 , & V_19 -> V_34 ) ;
V_28 = F_7 ( V_3 , true ) ;
break;
case V_30 :
F_13 ( ! F_15 ( & V_3 -> V_22 ) ) ;
F_17 ( & V_3 -> V_11 . V_33 ) ;
F_5 ( V_3 ) ;
if ( V_19 -> V_20 )
F_18 ( V_3 , error ) ;
else
F_19 ( V_3 , error ) ;
break;
default:
F_20 () ;
}
V_29 = F_21 ( V_19 ) ;
return V_29 | V_28 ;
}
static void F_22 ( struct V_2 * V_35 , int error )
{
struct V_21 * V_19 = V_35 -> V_19 ;
struct V_24 * V_36 ;
bool V_28 = false ;
struct V_2 * V_3 , * V_37 ;
unsigned long V_38 = 0 ;
if ( V_19 -> V_20 ) {
F_23 ( & V_19 -> V_39 , V_38 ) ;
V_19 -> V_35 -> V_40 = - 1 ;
}
V_36 = & V_19 -> V_26 [ V_19 -> V_41 ] ;
F_13 ( V_19 -> V_27 == V_19 -> V_41 ) ;
V_19 -> V_41 ^= 1 ;
if ( ! V_19 -> V_20 )
F_24 ( V_19 , V_35 ) ;
F_25 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_13 ( V_12 != V_8 && V_12 != V_10 ) ;
V_28 |= F_12 ( V_3 , V_12 , error ) ;
}
if ( V_28 || V_19 -> V_42 ) {
F_26 ( V_19 -> V_20 ) ;
F_27 ( V_19 ) ;
}
V_19 -> V_42 = 0 ;
if ( V_19 -> V_20 )
F_28 ( & V_19 -> V_39 , V_38 ) ;
}
static bool F_21 ( struct V_21 * V_19 )
{
struct V_24 * V_25 = & V_19 -> V_26 [ V_19 -> V_27 ] ;
struct V_2 * V_43 =
F_29 ( V_25 , struct V_2 , V_11 . V_33 ) ;
if ( V_19 -> V_27 != V_19 -> V_41 || F_15 ( V_25 ) )
return false ;
if ( ! F_15 ( & V_19 -> V_34 ) &&
F_30 ( V_32 ,
V_19 -> V_31 + V_44 ) )
return false ;
V_19 -> V_27 ^= 1 ;
F_31 ( V_19 , V_19 -> V_35 ) ;
if ( V_19 -> V_20 )
F_32 ( V_19 -> V_35 , V_43 ) ;
V_19 -> V_35 -> V_45 = V_46 ;
V_19 -> V_35 -> V_7 = V_47 | V_15 ;
V_19 -> V_35 -> V_48 = V_43 -> V_48 ;
V_19 -> V_35 -> V_16 = F_22 ;
return F_7 ( V_19 -> V_35 , false ) ;
}
static void F_33 ( struct V_2 * V_3 , int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
if ( F_12 ( V_3 , V_5 , error ) )
F_27 ( V_19 ) ;
}
static void F_34 ( struct V_2 * V_3 , int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
unsigned long V_38 ;
V_52 = V_3 -> V_53 ;
V_50 = V_19 -> V_20 -> V_54 ( V_19 , V_52 -> V_55 ) ;
F_23 ( & V_19 -> V_39 , V_38 ) ;
if ( F_12 ( V_3 , V_5 , error ) )
F_35 ( V_50 , true ) ;
F_28 ( & V_19 -> V_39 , V_38 ) ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_21 * V_19 = V_3 -> V_19 ;
unsigned int V_1 = V_19 -> V_56 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
V_3 -> V_7 &= ~ V_6 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_7 &= ~ V_9 ;
if ( ! V_4 ) {
if ( V_19 -> V_20 )
F_18 ( V_3 , 0 ) ;
else
F_37 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_13 ( V_3 -> V_13 != V_3 -> V_14 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_8 | V_10 ) ) ) {
if ( V_19 -> V_20 ) {
F_38 ( V_3 , false , false , true ) ;
} else
F_11 ( & V_3 -> V_22 , & V_19 -> V_23 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_39 ( & V_3 -> V_11 . V_33 ) ;
V_3 -> V_7 |= V_15 ;
V_3 -> V_11 . V_17 = V_3 -> V_16 ;
if ( V_19 -> V_20 ) {
V_3 -> V_16 = F_34 ;
F_40 ( & V_19 -> V_39 ) ;
F_12 ( V_3 , V_57 & ~ V_4 , 0 ) ;
F_41 ( & V_19 -> V_39 ) ;
return;
}
V_3 -> V_16 = F_33 ;
F_12 ( V_3 , V_57 & ~ V_4 , 0 ) ;
}
int F_42 ( struct V_58 * V_59 , T_1 V_60 ,
T_2 * V_61 )
{
struct V_21 * V_19 ;
struct V_13 * V_13 ;
int V_62 = 0 ;
if ( V_59 -> V_63 == NULL )
return - V_64 ;
V_19 = F_43 ( V_59 ) ;
if ( ! V_19 )
return - V_64 ;
if ( ! V_19 -> V_65 )
return - V_64 ;
V_13 = F_44 ( V_60 , 0 ) ;
V_13 -> V_66 = V_59 ;
V_62 = F_45 ( V_47 , V_13 ) ;
if ( V_61 )
* V_61 = V_13 -> V_67 . V_68 ;
F_46 ( V_13 ) ;
return V_62 ;
}
void F_47 ( struct V_21 * V_19 )
{
F_48 ( & V_19 -> V_39 ) ;
}
