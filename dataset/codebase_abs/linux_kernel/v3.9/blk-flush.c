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
static bool F_6 ( struct V_2 * V_3 , unsigned int V_12 ,
int error )
{
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_22 [ V_19 -> V_23 ] ;
bool V_24 = false ;
F_7 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_8 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_25 ;
switch ( V_12 ) {
case V_8 :
case V_10 :
if ( F_9 ( V_21 ) )
V_19 -> V_26 = V_27 ;
F_10 ( & V_3 -> V_11 . V_28 , V_21 ) ;
break;
case V_5 :
F_10 ( & V_3 -> V_11 . V_28 , & V_19 -> V_29 ) ;
F_11 ( & V_3 -> V_30 , & V_19 -> V_31 ) ;
V_24 = true ;
break;
case V_25 :
F_7 ( ! F_9 ( & V_3 -> V_30 ) ) ;
F_12 ( & V_3 -> V_11 . V_28 ) ;
F_5 ( V_3 ) ;
F_13 ( V_3 , error ) ;
break;
default:
F_14 () ;
}
return F_15 ( V_19 ) | V_24 ;
}
static void F_16 ( struct V_2 * V_32 , int error )
{
struct V_18 * V_19 = V_32 -> V_19 ;
struct V_20 * V_33 = & V_19 -> V_22 [ V_19 -> V_34 ] ;
bool V_24 = false ;
struct V_2 * V_3 , * V_35 ;
F_7 ( V_19 -> V_23 == V_19 -> V_34 ) ;
V_19 -> V_34 ^= 1 ;
F_17 ( V_19 , V_32 ) ;
F_18 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_7 ( V_12 != V_8 && V_12 != V_10 ) ;
V_24 |= F_6 ( V_3 , V_12 , error ) ;
}
if ( V_24 || V_19 -> V_36 )
F_19 ( V_19 ) ;
V_19 -> V_36 = 0 ;
}
static bool F_15 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_22 [ V_19 -> V_23 ] ;
struct V_2 * V_37 =
F_20 ( V_21 , struct V_2 , V_11 . V_28 ) ;
if ( V_19 -> V_23 != V_19 -> V_34 || F_9 ( V_21 ) )
return false ;
if ( ! F_9 ( & V_19 -> V_29 ) &&
F_21 ( V_27 ,
V_19 -> V_26 + V_38 ) )
return false ;
F_22 ( V_19 , & V_19 -> V_32 ) ;
V_19 -> V_32 . V_39 = V_40 ;
V_19 -> V_32 . V_7 = V_41 | V_15 ;
V_19 -> V_32 . V_42 = V_37 -> V_42 ;
V_19 -> V_32 . V_16 = F_16 ;
V_19 -> V_23 ^= 1 ;
F_23 ( & V_19 -> V_32 . V_30 , & V_19 -> V_31 ) ;
return true ;
}
static void F_24 ( struct V_2 * V_3 , int error )
{
struct V_18 * V_19 = V_3 -> V_19 ;
if ( F_6 ( V_3 , V_5 , error ) )
F_19 ( V_19 ) ;
}
void F_25 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = V_3 -> V_19 ;
unsigned int V_1 = V_19 -> V_43 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
V_3 -> V_7 &= ~ V_6 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_7 &= ~ V_9 ;
if ( ! V_4 ) {
F_26 ( V_3 , 0 , 0 , 0 ) ;
return;
}
F_7 ( V_3 -> V_13 != V_3 -> V_14 ) ;
if ( ( V_4 & V_5 ) &&
! ( V_4 & ( V_8 | V_10 ) ) ) {
F_23 ( & V_3 -> V_30 , & V_19 -> V_31 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_27 ( & V_3 -> V_11 . V_28 ) ;
V_3 -> V_7 |= V_15 ;
V_3 -> V_11 . V_17 = V_3 -> V_16 ;
V_3 -> V_16 = F_24 ;
F_6 ( V_3 , V_44 & ~ V_4 , 0 ) ;
}
void F_28 ( struct V_18 * V_19 )
{
struct V_2 * V_3 , * V_35 ;
int V_45 ;
F_18 (rq, n, &q->flush_data_in_flight, flush.list) {
F_12 ( & V_3 -> V_11 . V_28 ) ;
F_5 ( V_3 ) ;
}
for ( V_45 = 0 ; V_45 < F_29 ( V_19 -> V_22 ) ; V_45 ++ ) {
F_18 (rq, n, &q->flush_queue[i],
flush.list) {
F_12 ( & V_3 -> V_11 . V_28 ) ;
F_5 ( V_3 ) ;
F_23 ( & V_3 -> V_30 , & V_19 -> V_31 ) ;
}
}
}
static void F_30 ( struct V_13 * V_13 , int V_46 )
{
if ( V_46 )
F_31 ( V_47 , & V_13 -> V_48 ) ;
if ( V_13 -> V_49 )
F_32 ( V_13 -> V_49 ) ;
F_33 ( V_13 ) ;
}
int F_34 ( struct V_50 * V_51 , T_1 V_52 ,
T_2 * V_53 )
{
F_35 ( V_54 ) ;
struct V_18 * V_19 ;
struct V_13 * V_13 ;
int V_55 = 0 ;
if ( V_51 -> V_56 == NULL )
return - V_57 ;
V_19 = F_36 ( V_51 ) ;
if ( ! V_19 )
return - V_57 ;
if ( ! V_19 -> V_58 )
return - V_57 ;
V_13 = F_37 ( V_52 , 0 ) ;
V_13 -> V_59 = F_30 ;
V_13 -> V_60 = V_51 ;
V_13 -> V_49 = & V_54 ;
F_38 ( V_13 ) ;
F_39 ( V_41 , V_13 ) ;
F_40 ( & V_54 ) ;
if ( V_53 )
* V_53 = V_13 -> V_61 ;
if ( ! F_41 ( V_13 , V_47 ) )
V_55 = - V_62 ;
F_33 ( V_13 ) ;
return V_55 ;
}
