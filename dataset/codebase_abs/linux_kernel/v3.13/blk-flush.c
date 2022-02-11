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
static void F_7 ( struct V_18 * V_19 )
{
struct V_2 * V_3 ;
V_3 = F_8 ( V_19 , struct V_2 , V_20 ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
F_9 ( V_3 , true , false ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_11 ( & V_3 -> V_20 , F_7 ) ;
F_12 ( V_3 -> V_22 , & V_3 -> V_20 ) ;
}
static bool F_13 ( struct V_2 * V_3 , unsigned int V_12 ,
int error )
{
struct V_23 * V_22 = V_3 -> V_22 ;
struct V_24 * V_25 = & V_22 -> V_26 [ V_22 -> V_27 ] ;
bool V_28 = false , V_29 ;
F_14 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_15 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_30 ;
switch ( V_12 ) {
case V_8 :
case V_10 :
if ( F_16 ( V_25 ) )
V_22 -> V_31 = V_32 ;
F_17 ( & V_3 -> V_11 . V_33 , V_25 ) ;
break;
case V_5 :
F_17 ( & V_3 -> V_11 . V_33 , & V_22 -> V_34 ) ;
if ( V_22 -> V_35 )
F_10 ( V_3 ) ;
else {
F_18 ( & V_3 -> V_36 , & V_22 -> V_37 ) ;
V_28 = true ;
}
break;
case V_30 :
F_14 ( ! F_16 ( & V_3 -> V_36 ) ) ;
F_19 ( & V_3 -> V_11 . V_33 ) ;
F_5 ( V_3 ) ;
if ( V_22 -> V_35 )
F_20 ( V_3 , error ) ;
else
F_21 ( V_3 , error ) ;
break;
default:
F_22 () ;
}
V_29 = F_23 ( V_22 ) ;
if ( V_22 -> V_35 )
return V_28 ;
return V_29 | V_28 ;
}
static void F_24 ( struct V_2 * V_38 , int error )
{
struct V_23 * V_22 = V_38 -> V_22 ;
struct V_24 * V_39 ;
bool V_28 = false ;
struct V_2 * V_3 , * V_40 ;
unsigned long V_41 = 0 ;
if ( V_22 -> V_35 ) {
F_25 ( V_38 ) ;
F_26 ( & V_22 -> V_42 , V_41 ) ;
}
V_39 = & V_22 -> V_26 [ V_22 -> V_43 ] ;
F_14 ( V_22 -> V_27 == V_22 -> V_43 ) ;
V_22 -> V_43 ^= 1 ;
if ( ! V_22 -> V_35 )
F_27 ( V_22 , V_38 ) ;
F_28 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_14 ( V_12 != V_8 && V_12 != V_10 ) ;
V_28 |= F_13 ( V_3 , V_12 , error ) ;
}
if ( V_28 || V_22 -> V_44 ) {
if ( ! V_22 -> V_35 )
F_29 ( V_22 ) ;
else
F_30 ( V_22 , true ) ;
}
V_22 -> V_44 = 0 ;
if ( V_22 -> V_35 )
F_31 ( & V_22 -> V_42 , V_41 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
struct V_23 * V_22 ;
struct V_2 * V_3 ;
V_22 = F_8 ( V_19 , struct V_23 , F_32 ) ;
V_3 = F_33 ( V_22 , V_45 | V_15 ,
V_46 | V_47 , true ) ;
V_3 -> V_48 = V_49 ;
V_3 -> V_16 = F_24 ;
F_9 ( V_3 , true , false ) ;
}
static void F_34 ( struct V_23 * V_22 )
{
F_12 ( V_22 , & V_22 -> F_32 ) ;
}
static bool F_23 ( struct V_23 * V_22 )
{
struct V_24 * V_25 = & V_22 -> V_26 [ V_22 -> V_27 ] ;
struct V_2 * V_50 =
F_35 ( V_25 , struct V_2 , V_11 . V_33 ) ;
if ( V_22 -> V_27 != V_22 -> V_43 || F_16 ( V_25 ) )
return false ;
if ( ! F_16 ( & V_22 -> V_34 ) &&
F_36 ( V_32 ,
V_22 -> V_31 + V_51 ) )
return false ;
V_22 -> V_27 ^= 1 ;
if ( V_22 -> V_35 ) {
F_34 ( V_22 ) ;
return true ;
}
F_37 ( V_22 , & V_22 -> V_38 ) ;
V_22 -> V_38 . V_48 = V_49 ;
V_22 -> V_38 . V_7 = V_45 | V_15 ;
V_22 -> V_38 . V_52 = V_50 -> V_52 ;
V_22 -> V_38 . V_16 = F_24 ;
F_38 ( & V_22 -> V_38 . V_36 , & V_22 -> V_37 ) ;
return true ;
}
static void F_39 ( struct V_2 * V_3 , int error )
{
struct V_23 * V_22 = V_3 -> V_22 ;
if ( F_13 ( V_3 , V_5 , error ) )
F_29 ( V_22 ) ;
}
static void F_40 ( struct V_2 * V_3 , int error )
{
struct V_23 * V_22 = V_3 -> V_22 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_41 ;
V_56 = V_3 -> V_57 ;
V_54 = V_22 -> V_35 -> V_58 ( V_22 , V_56 -> V_59 ) ;
F_26 ( & V_22 -> V_42 , V_41 ) ;
if ( F_13 ( V_3 , V_5 , error ) )
F_41 ( V_54 , true ) ;
F_31 ( & V_22 -> V_42 , V_41 ) ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_23 * V_22 = V_3 -> V_22 ;
unsigned int V_1 = V_22 -> V_60 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
V_3 -> V_7 &= ~ V_6 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_7 &= ~ V_9 ;
if ( ! V_4 ) {
if ( V_22 -> V_35 )
F_20 ( V_3 , 0 ) ;
else
F_43 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_14 ( V_3 -> V_13 != V_3 -> V_14 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_8 | V_10 ) ) ) {
if ( V_22 -> V_35 ) {
F_9 ( V_3 , false , true ) ;
} else
F_38 ( & V_3 -> V_36 , & V_22 -> V_37 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_44 ( & V_3 -> V_11 . V_33 ) ;
V_3 -> V_7 |= V_15 ;
V_3 -> V_11 . V_17 = V_3 -> V_16 ;
if ( V_22 -> V_35 ) {
V_3 -> V_16 = F_40 ;
F_45 ( & V_22 -> V_42 ) ;
F_13 ( V_3 , V_61 & ~ V_4 , 0 ) ;
F_46 ( & V_22 -> V_42 ) ;
return;
}
V_3 -> V_16 = F_39 ;
F_13 ( V_3 , V_61 & ~ V_4 , 0 ) ;
}
void F_47 ( struct V_23 * V_22 )
{
struct V_2 * V_3 , * V_40 ;
int V_62 ;
F_28 (rq, n, &q->flush_data_in_flight, flush.list) {
F_19 ( & V_3 -> V_11 . V_33 ) ;
F_5 ( V_3 ) ;
}
for ( V_62 = 0 ; V_62 < F_48 ( V_22 -> V_26 ) ; V_62 ++ ) {
F_28 (rq, n, &q->flush_queue[i],
flush.list) {
F_19 ( & V_3 -> V_11 . V_33 ) ;
F_5 ( V_3 ) ;
F_38 ( & V_3 -> V_36 , & V_22 -> V_37 ) ;
}
}
}
int F_49 ( struct V_63 * V_64 , T_1 V_65 ,
T_2 * V_66 )
{
struct V_23 * V_22 ;
struct V_13 * V_13 ;
int V_67 = 0 ;
if ( V_64 -> V_68 == NULL )
return - V_69 ;
V_22 = F_50 ( V_64 ) ;
if ( ! V_22 )
return - V_69 ;
if ( ! V_22 -> V_70 )
return - V_69 ;
V_13 = F_51 ( V_65 , 0 ) ;
V_13 -> V_71 = V_64 ;
V_67 = F_52 ( V_45 , V_13 ) ;
if ( V_66 )
* V_66 = V_13 -> V_72 ;
F_53 ( V_13 ) ;
return V_67 ;
}
void F_54 ( struct V_23 * V_22 )
{
F_55 ( & V_22 -> V_42 ) ;
F_11 ( & V_22 -> F_32 , F_32 ) ;
}
