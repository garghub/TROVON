static unsigned int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = 0 ;
if ( V_1 & V_5 ) {
if ( V_3 -> V_6 & V_5 )
V_4 |= V_7 ;
if ( F_2 ( V_3 ) )
V_4 |= V_8 ;
if ( ! ( V_1 & V_9 ) && ( V_3 -> V_6 & V_9 ) )
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
V_3 -> V_6 &= ~ V_15 ;
V_3 -> V_16 = NULL ;
}
static bool F_6 ( struct V_2 * V_3 , unsigned int V_12 ,
int error )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_21 [ V_18 -> V_22 ] ;
bool V_23 = false ;
F_7 ( V_3 -> V_11 . V_12 & V_12 ) ;
V_3 -> V_11 . V_12 |= V_12 ;
if ( F_8 ( ! error ) )
V_12 = F_3 ( V_3 ) ;
else
V_12 = V_24 ;
switch ( V_12 ) {
case V_7 :
case V_10 :
if ( F_9 ( V_20 ) )
V_18 -> V_25 = V_26 ;
F_10 ( & V_3 -> V_11 . V_27 , V_20 ) ;
break;
case V_8 :
F_10 ( & V_3 -> V_11 . V_27 , & V_18 -> V_28 ) ;
F_11 ( & V_3 -> V_29 , & V_18 -> V_30 ) ;
V_23 = true ;
break;
case V_24 :
F_7 ( ! F_9 ( & V_3 -> V_29 ) ) ;
F_12 ( & V_3 -> V_11 . V_27 ) ;
F_5 ( V_3 ) ;
F_13 ( V_3 , error ) ;
break;
default:
F_14 () ;
}
return F_15 ( V_18 ) | V_23 ;
}
static void F_16 ( struct V_2 * V_31 , int error )
{
struct V_17 * V_18 = V_31 -> V_18 ;
struct V_19 * V_32 = & V_18 -> V_21 [ V_18 -> V_33 ] ;
bool V_23 = false ;
struct V_2 * V_3 , * V_34 ;
F_7 ( V_18 -> V_22 == V_18 -> V_33 ) ;
V_18 -> V_33 ^= 1 ;
F_17 ( V_18 , V_31 ) ;
F_18 (rq, n, running, flush.list) {
unsigned int V_12 = F_3 ( V_3 ) ;
F_7 ( V_12 != V_7 && V_12 != V_10 ) ;
V_23 |= F_6 ( V_3 , V_12 , error ) ;
}
if ( V_23 || V_18 -> V_35 )
F_19 ( V_18 ) ;
V_18 -> V_35 = 0 ;
}
static bool F_15 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 [ V_18 -> V_22 ] ;
struct V_2 * V_36 =
F_20 ( V_20 , struct V_2 , V_11 . V_27 ) ;
if ( V_18 -> V_22 != V_18 -> V_33 || F_9 ( V_20 ) )
return false ;
if ( ! F_9 ( & V_18 -> V_28 ) &&
F_21 ( V_26 ,
V_18 -> V_25 + V_37 ) )
return false ;
F_22 ( V_18 , & V_18 -> V_31 ) ;
V_18 -> V_31 . V_38 = V_39 ;
V_18 -> V_31 . V_6 = V_40 | V_15 ;
V_18 -> V_31 . V_41 = V_36 -> V_41 ;
V_18 -> V_31 . V_16 = F_16 ;
V_18 -> V_22 ^= 1 ;
F_23 ( & V_18 -> V_31 . V_29 , & V_18 -> V_30 ) ;
return true ;
}
static void F_24 ( struct V_2 * V_3 , int error )
{
struct V_17 * V_18 = V_3 -> V_18 ;
if ( F_6 ( V_3 , V_8 , error ) )
F_19 ( V_18 ) ;
}
void F_25 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
unsigned int V_1 = V_18 -> V_42 ;
unsigned int V_4 = F_1 ( V_1 , V_3 ) ;
F_7 ( V_3 -> V_16 ) ;
F_7 ( ! V_3 -> V_13 || V_3 -> V_13 != V_3 -> V_14 ) ;
V_3 -> V_6 &= ~ V_5 ;
if ( ! ( V_1 & V_9 ) )
V_3 -> V_6 &= ~ V_9 ;
if ( ( V_4 & V_8 ) &&
! ( V_4 & ( V_7 | V_10 ) ) ) {
F_23 ( & V_3 -> V_29 , & V_18 -> V_30 ) ;
return;
}
memset ( & V_3 -> V_11 , 0 , sizeof( V_3 -> V_11 ) ) ;
F_26 ( & V_3 -> V_11 . V_27 ) ;
V_3 -> V_6 |= V_15 ;
V_3 -> V_16 = F_24 ;
F_6 ( V_3 , V_43 & ~ V_4 , 0 ) ;
}
void F_27 ( struct V_17 * V_18 )
{
struct V_2 * V_3 , * V_34 ;
int V_44 ;
F_18 (rq, n, &q->flush_data_in_flight, flush.list) {
F_12 ( & V_3 -> V_11 . V_27 ) ;
F_5 ( V_3 ) ;
}
for ( V_44 = 0 ; V_44 < F_28 ( V_18 -> V_21 ) ; V_44 ++ ) {
F_18 (rq, n, &q->flush_queue[i],
flush.list) {
F_12 ( & V_3 -> V_11 . V_27 ) ;
F_5 ( V_3 ) ;
F_23 ( & V_3 -> V_29 , & V_18 -> V_30 ) ;
}
}
}
static void F_29 ( struct V_13 * V_13 , int V_45 )
{
if ( V_45 )
F_30 ( V_46 , & V_13 -> V_47 ) ;
if ( V_13 -> V_48 )
F_31 ( V_13 -> V_48 ) ;
F_32 ( V_13 ) ;
}
int F_33 ( struct V_49 * V_50 , T_1 V_51 ,
T_2 * V_52 )
{
F_34 ( V_53 ) ;
struct V_17 * V_18 ;
struct V_13 * V_13 ;
int V_54 = 0 ;
if ( V_50 -> V_55 == NULL )
return - V_56 ;
V_18 = F_35 ( V_50 ) ;
if ( ! V_18 )
return - V_56 ;
if ( ! V_18 -> V_57 )
return - V_56 ;
V_13 = F_36 ( V_51 , 0 ) ;
V_13 -> V_58 = F_29 ;
V_13 -> V_59 = V_50 ;
V_13 -> V_48 = & V_53 ;
F_37 ( V_13 ) ;
F_38 ( V_40 , V_13 ) ;
F_39 ( & V_53 ) ;
if ( V_52 )
* V_52 = V_13 -> V_60 ;
if ( ! F_40 ( V_13 , V_46 ) )
V_54 = - V_61 ;
F_32 ( V_13 ) ;
return V_54 ;
}
