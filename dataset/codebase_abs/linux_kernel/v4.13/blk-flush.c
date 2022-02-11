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
V_3 -> V_17 &= ~ V_18 ;
V_3 -> V_19 = V_3 -> V_13 . V_20 ;
}
static bool F_6 ( struct V_2 * V_3 , bool V_21 )
{
if ( V_3 -> V_22 -> V_23 ) {
F_7 ( V_3 , V_21 , true ) ;
return false ;
} else {
if ( V_21 )
F_8 ( & V_3 -> V_24 , & V_3 -> V_22 -> V_25 ) ;
else
F_9 ( & V_3 -> V_24 , & V_3 -> V_22 -> V_25 ) ;
return true ;
}
}
static bool F_10 ( struct V_2 * V_3 ,
struct V_26 * V_27 ,
unsigned int V_14 , T_1 error )
{
struct V_28 * V_22 = V_3 -> V_22 ;
struct V_29 * V_30 = & V_27 -> V_31 [ V_27 -> V_32 ] ;
bool V_33 = false , V_34 ;
F_11 ( V_3 -> V_13 . V_14 & V_14 ) ;
V_3 -> V_13 . V_14 |= V_14 ;
if ( F_12 ( ! error ) )
V_14 = F_3 ( V_3 ) ;
else
V_14 = V_35 ;
switch ( V_14 ) {
case V_9 :
case V_12 :
if ( F_13 ( V_30 ) )
V_27 -> V_36 = V_37 ;
F_14 ( & V_3 -> V_13 . V_38 , V_30 ) ;
break;
case V_5 :
F_14 ( & V_3 -> V_13 . V_38 , & V_27 -> V_39 ) ;
V_33 = F_6 ( V_3 , true ) ;
break;
case V_35 :
F_11 ( ! F_13 ( & V_3 -> V_24 ) ) ;
F_15 ( & V_3 -> V_13 . V_38 ) ;
F_5 ( V_3 ) ;
if ( V_22 -> V_23 )
F_16 ( V_3 , error ) ;
else
F_17 ( V_3 , error ) ;
break;
default:
F_18 () ;
}
V_34 = F_19 ( V_22 , V_27 ) ;
return V_34 | V_33 ;
}
static void F_20 ( struct V_2 * V_40 , T_1 error )
{
struct V_28 * V_22 = V_40 -> V_22 ;
struct V_29 * V_41 ;
bool V_33 = false ;
struct V_2 * V_3 , * V_42 ;
unsigned long V_43 = 0 ;
struct V_26 * V_27 = F_21 ( V_22 , V_40 -> V_44 ) ;
if ( V_22 -> V_23 ) {
struct V_45 * V_46 ;
F_22 ( & V_27 -> V_47 , V_43 ) ;
V_46 = F_23 ( V_22 , V_40 -> V_44 -> V_48 ) ;
F_24 ( V_46 , V_40 -> V_49 , V_27 -> V_50 ) ;
V_40 -> V_49 = - 1 ;
}
V_41 = & V_27 -> V_31 [ V_27 -> V_51 ] ;
F_11 ( V_27 -> V_32 == V_27 -> V_51 ) ;
V_27 -> V_51 ^= 1 ;
if ( ! V_22 -> V_23 )
F_25 ( V_22 , V_40 ) ;
F_26 (rq, n, running, flush.list) {
unsigned int V_14 = F_3 ( V_3 ) ;
F_11 ( V_14 != V_9 && V_14 != V_12 ) ;
V_33 |= F_10 ( V_3 , V_27 , V_14 , error ) ;
}
if ( V_33 || V_27 -> V_52 ) {
F_27 ( V_22 -> V_23 ) ;
F_28 ( V_22 ) ;
}
V_27 -> V_52 = 0 ;
if ( V_22 -> V_23 )
F_29 ( & V_27 -> V_47 , V_43 ) ;
}
static bool F_19 ( struct V_28 * V_22 , struct V_26 * V_27 )
{
struct V_29 * V_30 = & V_27 -> V_31 [ V_27 -> V_32 ] ;
struct V_2 * V_53 =
F_30 ( V_30 , struct V_2 , V_13 . V_38 ) ;
struct V_2 * V_40 = V_27 -> V_40 ;
if ( V_27 -> V_32 != V_27 -> V_51 || F_13 ( V_30 ) )
return false ;
if ( ! F_13 ( & V_27 -> V_39 ) &&
! ( V_22 -> V_23 && V_22 -> V_54 ) &&
F_31 ( V_37 ,
V_27 -> V_36 + V_55 ) )
return false ;
V_27 -> V_32 ^= 1 ;
F_32 ( V_22 , V_40 ) ;
if ( V_22 -> V_23 ) {
struct V_45 * V_46 ;
V_40 -> V_44 = V_53 -> V_44 ;
V_40 -> V_49 = V_53 -> V_49 ;
V_27 -> V_50 = V_53 ;
V_46 = F_23 ( V_22 , V_53 -> V_44 -> V_48 ) ;
F_24 ( V_46 , V_53 -> V_49 , V_40 ) ;
}
V_40 -> V_7 = V_56 | V_8 ;
V_40 -> V_17 |= V_18 ;
V_40 -> V_57 = V_53 -> V_57 ;
V_40 -> V_19 = F_20 ;
return F_6 ( V_40 , false ) ;
}
static void F_33 ( struct V_2 * V_3 , T_1 error )
{
struct V_28 * V_22 = V_3 -> V_22 ;
struct V_26 * V_27 = F_21 ( V_22 , NULL ) ;
F_34 ( V_22 -> V_58 ) ;
F_25 ( V_22 , V_3 ) ;
V_3 -> V_17 &= ~ V_59 ;
if ( F_10 ( V_3 , V_27 , V_5 , error ) )
F_28 ( V_22 ) ;
}
static void F_35 ( struct V_2 * V_3 , T_1 error )
{
struct V_28 * V_22 = V_3 -> V_22 ;
struct V_45 * V_46 ;
struct V_60 * V_61 = V_3 -> V_44 ;
unsigned long V_43 ;
struct V_26 * V_27 = F_21 ( V_22 , V_61 ) ;
V_46 = F_23 ( V_22 , V_61 -> V_48 ) ;
F_22 ( & V_27 -> V_47 , V_43 ) ;
F_10 ( V_3 , V_27 , V_5 , error ) ;
F_29 ( & V_27 -> V_47 , V_43 ) ;
F_36 ( V_46 , true ) ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_28 * V_22 = V_3 -> V_22 ;
unsigned long V_1 = V_22 -> V_62 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
struct V_26 * V_27 = F_21 ( V_22 , V_3 -> V_44 ) ;
if ( ! V_22 -> V_23 )
F_34 ( V_22 -> V_58 ) ;
V_3 -> V_7 &= ~ V_8 ;
if ( ! ( V_1 & ( 1UL << V_10 ) ) )
V_3 -> V_7 &= ~ V_11 ;
V_3 -> V_7 |= V_63 ;
if ( ! V_4 ) {
if ( V_22 -> V_23 )
F_16 ( V_3 , 0 ) ;
else
F_38 ( V_3 , 0 , 0 ) ;
return;
}
F_11 ( V_3 -> V_15 != V_3 -> V_16 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_9 | V_12 ) ) ) {
if ( V_22 -> V_23 )
F_39 ( V_3 , false , true , false , false ) ;
else
F_9 ( & V_3 -> V_24 , & V_22 -> V_25 ) ;
return;
}
memset ( & V_3 -> V_13 , 0 , sizeof( V_3 -> V_13 ) ) ;
F_40 ( & V_3 -> V_13 . V_38 ) ;
V_3 -> V_17 |= V_18 ;
V_3 -> V_13 . V_20 = V_3 -> V_19 ;
if ( V_22 -> V_23 ) {
V_3 -> V_19 = F_35 ;
F_41 ( & V_27 -> V_47 ) ;
F_10 ( V_3 , V_27 , V_64 & ~ V_4 , 0 ) ;
F_42 ( & V_27 -> V_47 ) ;
return;
}
V_3 -> V_19 = F_33 ;
F_10 ( V_3 , V_27 , V_64 & ~ V_4 , 0 ) ;
}
int F_43 ( struct V_65 * V_66 , T_2 V_67 ,
T_3 * V_68 )
{
struct V_28 * V_22 ;
struct V_15 * V_15 ;
int V_69 = 0 ;
if ( V_66 -> V_70 == NULL )
return - V_71 ;
V_22 = F_44 ( V_66 ) ;
if ( ! V_22 )
return - V_71 ;
if ( ! V_22 -> V_72 )
return - V_71 ;
V_15 = F_45 ( V_67 , 0 ) ;
V_15 -> V_73 = V_66 ;
V_15 -> V_74 = V_75 | V_8 ;
V_69 = F_46 ( V_15 ) ;
if ( V_68 )
* V_68 = V_15 -> V_76 . V_77 ;
F_47 ( V_15 ) ;
return V_69 ;
}
struct V_26 * F_48 ( struct V_28 * V_22 ,
int V_78 , int V_79 )
{
struct V_26 * V_27 ;
int V_80 = sizeof( struct V_2 ) ;
V_27 = F_49 ( sizeof( * V_27 ) , V_81 , V_78 ) ;
if ( ! V_27 )
goto V_82;
if ( V_22 -> V_23 )
F_50 ( & V_27 -> V_47 ) ;
V_80 = F_51 ( V_80 + V_79 , F_52 () ) ;
V_27 -> V_40 = F_49 ( V_80 , V_81 , V_78 ) ;
if ( ! V_27 -> V_40 )
goto V_83;
F_40 ( & V_27 -> V_31 [ 0 ] ) ;
F_40 ( & V_27 -> V_31 [ 1 ] ) ;
F_40 ( & V_27 -> V_39 ) ;
return V_27 ;
V_83:
F_53 ( V_27 ) ;
V_82:
return NULL ;
}
void F_54 ( struct V_26 * V_27 )
{
if ( ! V_27 )
return;
F_53 ( V_27 -> V_40 ) ;
F_53 ( V_27 ) ;
}
