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
}
static bool F_6 ( struct V_2 * V_3 , bool V_18 )
{
if ( V_3 -> V_19 -> V_20 ) {
struct V_21 * V_19 = V_3 -> V_19 ;
F_7 ( V_3 , V_18 ) ;
F_8 ( V_19 ) ;
return false ;
} else {
if ( V_18 )
F_9 ( & V_3 -> V_22 , & V_3 -> V_19 -> V_23 ) ;
else
F_10 ( & V_3 -> V_22 , & V_3 -> V_19 -> V_23 ) ;
return true ;
}
}
static bool F_11 ( struct V_2 * V_3 ,
struct V_24 * V_25 ,
unsigned int V_12 , int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
struct V_26 * V_27 = & V_25 -> V_28 [ V_25 -> V_29 ] ;
bool V_30 = false , V_31 ;
F_12 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_13 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_32 ;
switch ( V_12 ) {
case V_8 :
case V_10 :
if ( F_14 ( V_27 ) )
V_25 -> V_33 = V_34 ;
F_15 ( & V_3 -> V_11 . V_35 , V_27 ) ;
break;
case V_5 :
F_15 ( & V_3 -> V_11 . V_35 , & V_25 -> V_36 ) ;
V_30 = F_6 ( V_3 , true ) ;
break;
case V_32 :
F_12 ( ! F_14 ( & V_3 -> V_22 ) ) ;
F_16 ( & V_3 -> V_11 . V_35 ) ;
F_5 ( V_3 ) ;
if ( V_19 -> V_20 )
F_17 ( V_3 , error ) ;
else
F_18 ( V_3 , error ) ;
break;
default:
F_19 () ;
}
V_31 = F_20 ( V_19 , V_25 ) ;
return V_31 | V_30 ;
}
static void F_21 ( struct V_2 * V_37 , int error )
{
struct V_21 * V_19 = V_37 -> V_19 ;
struct V_26 * V_38 ;
bool V_30 = false ;
struct V_2 * V_3 , * V_39 ;
unsigned long V_40 = 0 ;
struct V_24 * V_25 = F_22 ( V_19 , V_37 -> V_41 ) ;
if ( V_19 -> V_20 ) {
F_23 ( & V_25 -> V_42 , V_40 ) ;
V_37 -> V_43 = - 1 ;
}
V_38 = & V_25 -> V_28 [ V_25 -> V_44 ] ;
F_12 ( V_25 -> V_29 == V_25 -> V_44 ) ;
V_25 -> V_44 ^= 1 ;
if ( ! V_19 -> V_20 )
F_24 ( V_19 , V_37 ) ;
F_25 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_12 ( V_12 != V_8 && V_12 != V_10 ) ;
V_30 |= F_11 ( V_3 , V_25 , V_12 , error ) ;
}
if ( V_30 || V_25 -> V_45 ) {
F_26 ( V_19 -> V_20 ) ;
F_27 ( V_19 ) ;
}
V_25 -> V_45 = 0 ;
if ( V_19 -> V_20 )
F_28 ( & V_25 -> V_42 , V_40 ) ;
}
static bool F_20 ( struct V_21 * V_19 , struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_28 [ V_25 -> V_29 ] ;
struct V_2 * V_46 =
F_29 ( V_27 , struct V_2 , V_11 . V_35 ) ;
struct V_2 * V_37 = V_25 -> V_37 ;
if ( V_25 -> V_29 != V_25 -> V_44 || F_14 ( V_27 ) )
return false ;
if ( ! F_14 ( & V_25 -> V_36 ) &&
F_30 ( V_34 ,
V_25 -> V_33 + V_47 ) )
return false ;
V_25 -> V_29 ^= 1 ;
F_31 ( V_19 , V_37 ) ;
if ( V_19 -> V_20 ) {
V_37 -> V_41 = V_46 -> V_41 ;
V_37 -> V_43 = V_46 -> V_43 ;
}
V_37 -> V_48 = V_49 ;
V_37 -> V_7 = V_50 | V_15 ;
V_37 -> V_51 = V_46 -> V_51 ;
V_37 -> V_16 = F_21 ;
return F_6 ( V_37 , false ) ;
}
static void F_32 ( struct V_2 * V_3 , int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
struct V_24 * V_25 = F_22 ( V_19 , NULL ) ;
if ( F_11 ( V_3 , V_25 , V_5 , error ) )
F_27 ( V_19 ) ;
}
static void F_33 ( struct V_2 * V_3 , int error )
{
struct V_21 * V_19 = V_3 -> V_19 ;
struct V_52 * V_53 ;
struct V_54 * V_55 = V_3 -> V_41 ;
unsigned long V_40 ;
struct V_24 * V_25 = F_22 ( V_19 , V_55 ) ;
V_53 = V_19 -> V_20 -> V_56 ( V_19 , V_55 -> V_57 ) ;
F_23 ( & V_25 -> V_42 , V_40 ) ;
if ( F_11 ( V_3 , V_25 , V_5 , error ) )
F_34 ( V_53 , true ) ;
F_28 ( & V_25 -> V_42 , V_40 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
struct V_21 * V_19 = V_3 -> V_19 ;
unsigned int V_1 = V_19 -> V_58 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
struct V_24 * V_25 = F_22 ( V_19 , V_3 -> V_41 ) ;
V_3 -> V_7 &= ~ V_6 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_7 &= ~ V_9 ;
if ( ! V_4 ) {
if ( V_19 -> V_20 )
F_17 ( V_3 , 0 ) ;
else
F_36 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_12 ( V_3 -> V_13 != V_3 -> V_14 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_8 | V_10 ) ) ) {
if ( V_19 -> V_20 ) {
F_37 ( V_3 , false , false , true ) ;
} else
F_10 ( & V_3 -> V_22 , & V_19 -> V_23 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_38 ( & V_3 -> V_11 . V_35 ) ;
V_3 -> V_7 |= V_15 ;
V_3 -> V_11 . V_17 = V_3 -> V_16 ;
if ( V_19 -> V_20 ) {
V_3 -> V_16 = F_33 ;
F_39 ( & V_25 -> V_42 ) ;
F_11 ( V_3 , V_25 , V_59 & ~ V_4 , 0 ) ;
F_40 ( & V_25 -> V_42 ) ;
return;
}
V_3 -> V_16 = F_32 ;
F_11 ( V_3 , V_25 , V_59 & ~ V_4 , 0 ) ;
}
int F_41 ( struct V_60 * V_61 , T_1 V_62 ,
T_2 * V_63 )
{
struct V_21 * V_19 ;
struct V_13 * V_13 ;
int V_64 = 0 ;
if ( V_61 -> V_65 == NULL )
return - V_66 ;
V_19 = F_42 ( V_61 ) ;
if ( ! V_19 )
return - V_66 ;
if ( ! V_19 -> V_67 )
return - V_66 ;
V_13 = F_43 ( V_62 , 0 ) ;
V_13 -> V_68 = V_61 ;
V_64 = F_44 ( V_50 , V_13 ) ;
if ( V_63 )
* V_63 = V_13 -> V_69 . V_70 ;
F_45 ( V_13 ) ;
return V_64 ;
}
struct V_24 * F_46 ( struct V_21 * V_19 ,
int V_71 , int V_72 )
{
struct V_24 * V_25 ;
int V_73 = sizeof( struct V_2 ) ;
V_25 = F_47 ( sizeof( * V_25 ) , V_74 , V_71 ) ;
if ( ! V_25 )
goto V_75;
if ( V_19 -> V_20 ) {
F_48 ( & V_25 -> V_42 ) ;
V_73 = F_49 ( V_73 + V_72 , F_50 () ) ;
}
V_25 -> V_37 = F_47 ( V_73 , V_74 , V_71 ) ;
if ( ! V_25 -> V_37 )
goto V_76;
F_38 ( & V_25 -> V_28 [ 0 ] ) ;
F_38 ( & V_25 -> V_28 [ 1 ] ) ;
F_38 ( & V_25 -> V_36 ) ;
return V_25 ;
V_76:
F_51 ( V_25 ) ;
V_75:
return NULL ;
}
void F_52 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_51 ( V_25 -> V_37 ) ;
F_51 ( V_25 ) ;
}
