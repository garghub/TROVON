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
F_9 ( V_3 , false , true , false ) ;
}
static bool F_10 ( struct V_2 * V_3 , bool V_22 )
{
if ( V_3 -> V_23 -> V_24 ) {
F_11 ( & V_3 -> V_20 , F_7 ) ;
F_12 ( V_3 -> V_23 , & V_3 -> V_20 ) ;
return false ;
} else {
if ( V_22 )
F_13 ( & V_3 -> V_25 , & V_3 -> V_23 -> V_26 ) ;
else
F_14 ( & V_3 -> V_25 , & V_3 -> V_23 -> V_26 ) ;
return true ;
}
}
static bool F_15 ( struct V_2 * V_3 , unsigned int V_12 ,
int error )
{
struct V_27 * V_23 = V_3 -> V_23 ;
struct V_28 * V_29 = & V_23 -> V_30 [ V_23 -> V_31 ] ;
bool V_32 = false , V_33 ;
F_16 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_17 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_34 ;
switch ( V_12 ) {
case V_8 :
case V_10 :
if ( F_18 ( V_29 ) )
V_23 -> V_35 = V_36 ;
F_19 ( & V_3 -> V_11 . V_37 , V_29 ) ;
break;
case V_5 :
F_19 ( & V_3 -> V_11 . V_37 , & V_23 -> V_38 ) ;
V_32 = F_10 ( V_3 , true ) ;
break;
case V_34 :
F_16 ( ! F_18 ( & V_3 -> V_25 ) ) ;
F_20 ( & V_3 -> V_11 . V_37 ) ;
F_5 ( V_3 ) ;
if ( V_23 -> V_24 )
F_21 ( V_3 , error ) ;
else
F_22 ( V_3 , error ) ;
break;
default:
F_23 () ;
}
V_33 = F_24 ( V_23 ) ;
return V_33 | V_32 ;
}
static void F_25 ( struct V_2 * V_39 , int error )
{
struct V_27 * V_23 = V_39 -> V_23 ;
struct V_28 * V_40 ;
bool V_32 = false ;
struct V_2 * V_3 , * V_41 ;
unsigned long V_42 = 0 ;
if ( V_23 -> V_24 )
F_26 ( & V_23 -> V_43 , V_42 ) ;
V_40 = & V_23 -> V_30 [ V_23 -> V_44 ] ;
F_16 ( V_23 -> V_31 == V_23 -> V_44 ) ;
V_23 -> V_44 ^= 1 ;
if ( ! V_23 -> V_24 )
F_27 ( V_23 , V_39 ) ;
F_28 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_16 ( V_12 != V_8 && V_12 != V_10 ) ;
V_32 |= F_15 ( V_3 , V_12 , error ) ;
}
if ( V_32 || V_23 -> V_45 ) {
F_29 ( V_23 -> V_24 ) ;
F_30 ( V_23 ) ;
}
V_23 -> V_45 = 0 ;
if ( V_23 -> V_24 )
F_31 ( & V_23 -> V_43 , V_42 ) ;
}
static bool F_24 ( struct V_27 * V_23 )
{
struct V_28 * V_29 = & V_23 -> V_30 [ V_23 -> V_31 ] ;
struct V_2 * V_46 =
F_32 ( V_29 , struct V_2 , V_11 . V_37 ) ;
if ( V_23 -> V_31 != V_23 -> V_44 || F_18 ( V_29 ) )
return false ;
if ( ! F_18 ( & V_23 -> V_38 ) &&
F_33 ( V_36 ,
V_23 -> V_35 + V_47 ) )
return false ;
V_23 -> V_31 ^= 1 ;
if ( V_23 -> V_24 ) {
struct V_48 * V_49 = V_46 -> V_50 ;
struct V_51 * V_52 = V_23 -> V_24 -> V_53 ( V_23 , V_49 -> V_54 ) ;
F_34 ( V_52 , V_23 -> V_39 ) ;
V_23 -> V_39 -> V_50 = V_49 ;
V_23 -> V_39 -> V_55 = V_46 -> V_55 ;
} else {
F_35 ( V_23 , V_23 -> V_39 ) ;
}
V_23 -> V_39 -> V_56 = V_57 ;
V_23 -> V_39 -> V_7 = V_58 | V_15 ;
V_23 -> V_39 -> V_59 = V_46 -> V_59 ;
V_23 -> V_39 -> V_16 = F_25 ;
return F_10 ( V_23 -> V_39 , false ) ;
}
static void F_36 ( struct V_2 * V_3 , int error )
{
struct V_27 * V_23 = V_3 -> V_23 ;
if ( F_15 ( V_3 , V_5 , error ) )
F_30 ( V_23 ) ;
}
static void F_37 ( struct V_2 * V_3 , int error )
{
struct V_27 * V_23 = V_3 -> V_23 ;
struct V_51 * V_52 ;
struct V_48 * V_49 ;
unsigned long V_42 ;
V_49 = V_3 -> V_50 ;
V_52 = V_23 -> V_24 -> V_53 ( V_23 , V_49 -> V_54 ) ;
F_26 ( & V_23 -> V_43 , V_42 ) ;
if ( F_15 ( V_3 , V_5 , error ) )
F_38 ( V_52 , true ) ;
F_31 ( & V_23 -> V_43 , V_42 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_27 * V_23 = V_3 -> V_23 ;
unsigned int V_1 = V_23 -> V_60 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
V_3 -> V_7 &= ~ V_6 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_7 &= ~ V_9 ;
if ( ! V_4 ) {
if ( V_23 -> V_24 )
F_21 ( V_3 , 0 ) ;
else
F_40 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_16 ( V_3 -> V_13 != V_3 -> V_14 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_8 | V_10 ) ) ) {
if ( V_23 -> V_24 ) {
F_9 ( V_3 , false , false , true ) ;
} else
F_14 ( & V_3 -> V_25 , & V_23 -> V_26 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_41 ( & V_3 -> V_11 . V_37 ) ;
V_3 -> V_7 |= V_15 ;
V_3 -> V_11 . V_17 = V_3 -> V_16 ;
if ( V_23 -> V_24 ) {
V_3 -> V_16 = F_37 ;
F_42 ( & V_23 -> V_43 ) ;
F_15 ( V_3 , V_61 & ~ V_4 , 0 ) ;
F_43 ( & V_23 -> V_43 ) ;
return;
}
V_3 -> V_16 = F_36 ;
F_15 ( V_3 , V_61 & ~ V_4 , 0 ) ;
}
void F_44 ( struct V_27 * V_23 )
{
struct V_2 * V_3 , * V_41 ;
int V_62 ;
F_28 (rq, n, &q->flush_data_in_flight, flush.list) {
F_20 ( & V_3 -> V_11 . V_37 ) ;
F_5 ( V_3 ) ;
}
for ( V_62 = 0 ; V_62 < F_45 ( V_23 -> V_30 ) ; V_62 ++ ) {
F_28 (rq, n, &q->flush_queue[i],
flush.list) {
F_20 ( & V_3 -> V_11 . V_37 ) ;
F_5 ( V_3 ) ;
F_14 ( & V_3 -> V_25 , & V_23 -> V_26 ) ;
}
}
}
int F_46 ( struct V_63 * V_64 , T_1 V_65 ,
T_2 * V_66 )
{
struct V_27 * V_23 ;
struct V_13 * V_13 ;
int V_67 = 0 ;
if ( V_64 -> V_68 == NULL )
return - V_69 ;
V_23 = F_47 ( V_64 ) ;
if ( ! V_23 )
return - V_69 ;
if ( ! V_23 -> V_70 )
return - V_69 ;
V_13 = F_48 ( V_65 , 0 ) ;
V_13 -> V_71 = V_64 ;
V_67 = F_49 ( V_58 , V_13 ) ;
if ( V_66 )
* V_66 = V_13 -> V_72 . V_73 ;
F_50 ( V_13 ) ;
return V_67 ;
}
void F_51 ( struct V_27 * V_23 )
{
F_52 ( & V_23 -> V_43 ) ;
}
