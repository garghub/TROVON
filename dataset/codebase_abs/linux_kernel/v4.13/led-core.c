static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! V_2 -> V_5 )
return - V_6 ;
V_2 -> V_5 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! V_2 -> V_7 )
return - V_6 ;
return V_2 -> V_7 ( V_2 , V_4 ) ;
}
static void F_3 ( unsigned long V_8 )
{
struct V_1 * V_2 = ( void * ) V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
if ( ! V_2 -> V_11 || ! V_2 -> V_12 ) {
F_4 ( V_2 , V_13 ) ;
F_5 ( V_14 , & V_2 -> V_15 ) ;
return;
}
if ( F_6 ( V_16 ,
& V_2 -> V_15 ) ) {
F_5 ( V_14 , & V_2 -> V_15 ) ;
return;
}
V_9 = F_7 ( V_2 ) ;
if ( ! V_9 ) {
if ( F_6 ( V_17 ,
& V_2 -> V_15 ) )
V_9 = V_2 -> V_18 ;
else
V_9 = V_2 -> V_19 ;
V_10 = V_2 -> V_11 ;
} else {
V_2 -> V_19 = V_9 ;
V_9 = V_13 ;
V_10 = V_2 -> V_12 ;
}
F_4 ( V_2 , V_9 ) ;
if ( F_8 ( V_20 , & V_2 -> V_15 ) ) {
if ( F_8 ( V_21 , & V_2 -> V_15 ) ) {
if ( V_9 )
F_9 ( V_16 ,
& V_2 -> V_15 ) ;
} else {
if ( ! V_9 )
F_9 ( V_16 ,
& V_2 -> V_15 ) ;
}
}
F_10 ( & V_2 -> V_22 , V_23 + F_11 ( V_10 ) ) ;
}
static void F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_26 ) ;
int V_27 = 0 ;
if ( F_6 ( V_28 , & V_2 -> V_15 ) ) {
V_2 -> V_29 = V_13 ;
F_14 ( V_2 ) ;
}
V_27 = F_1 ( V_2 , V_2 -> V_29 ) ;
if ( V_27 == - V_6 )
V_27 = F_2 ( V_2 ,
V_2 -> V_29 ) ;
if ( V_27 < 0 &&
! ( V_27 == - V_30 && ( V_2 -> V_31 & V_32 ) &&
( V_2 -> V_31 & V_33 ) ) )
F_15 ( V_2 -> V_34 ,
L_1 , V_27 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned long V_35 ,
unsigned long V_36 )
{
int V_37 ;
V_37 = F_7 ( V_2 ) ;
if ( V_37 )
V_2 -> V_19 = V_37 ;
if ( ! V_2 -> V_19 )
V_2 -> V_19 = V_2 -> V_38 ;
V_2 -> V_11 = V_35 ;
V_2 -> V_12 = V_36 ;
if ( ! V_35 ) {
F_4 ( V_2 , V_13 ) ;
return;
}
if ( ! V_36 ) {
F_4 ( V_2 ,
V_2 -> V_19 ) ;
return;
}
F_9 ( V_14 , & V_2 -> V_15 ) ;
F_10 ( & V_2 -> V_22 , V_23 + 1 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned long * V_35 ,
unsigned long * V_36 )
{
if ( ! F_8 ( V_20 , & V_2 -> V_15 ) &&
V_2 -> V_39 &&
! V_2 -> V_39 ( V_2 , V_35 , V_36 ) )
return;
if ( ! * V_35 && ! * V_36 )
* V_35 = * V_36 = 500 ;
F_16 ( V_2 , * V_35 , * V_36 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_26 , F_12 ) ;
F_20 ( & V_2 -> V_22 , F_3 ,
( unsigned long ) V_2 ) ;
}
void F_21 ( struct V_1 * V_2 ,
unsigned long * V_35 ,
unsigned long * V_36 )
{
F_22 ( & V_2 -> V_22 ) ;
F_5 ( V_20 , & V_2 -> V_15 ) ;
F_5 ( V_16 , & V_2 -> V_15 ) ;
F_17 ( V_2 , V_35 , V_36 ) ;
}
void F_23 ( struct V_1 * V_2 ,
unsigned long * V_35 ,
unsigned long * V_36 ,
int V_40 )
{
if ( F_8 ( V_20 , & V_2 -> V_15 ) &&
F_24 ( & V_2 -> V_22 ) )
return;
F_9 ( V_20 , & V_2 -> V_15 ) ;
F_5 ( V_16 , & V_2 -> V_15 ) ;
if ( V_40 )
F_9 ( V_21 , & V_2 -> V_15 ) ;
else
F_5 ( V_21 , & V_2 -> V_15 ) ;
F_17 ( V_2 , V_35 , V_36 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_22 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
F_5 ( V_14 , & V_2 -> V_15 ) ;
}
void F_25 ( struct V_1 * V_2 ,
enum V_3 V_9 )
{
if ( F_8 ( V_14 , & V_2 -> V_15 ) ) {
if ( V_9 == V_13 ) {
F_9 ( V_28 , & V_2 -> V_15 ) ;
F_26 ( & V_2 -> V_26 ) ;
} else {
F_9 ( V_17 ,
& V_2 -> V_15 ) ;
V_2 -> V_18 = V_9 ;
}
return;
}
F_4 ( V_2 , V_9 ) ;
}
void F_27 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! F_1 ( V_2 , V_4 ) )
return;
V_2 -> V_29 = V_4 ;
F_26 ( & V_2 -> V_26 ) ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
V_2 -> V_9 = F_28 ( V_4 , V_2 -> V_38 ) ;
if ( V_2 -> V_31 & V_41 )
return;
F_27 ( V_2 , V_2 -> V_9 ) ;
}
int F_29 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_2 -> V_11 || V_2 -> V_12 )
return - V_42 ;
V_2 -> V_9 = F_28 ( V_4 , V_2 -> V_38 ) ;
if ( V_2 -> V_31 & V_41 )
return 0 ;
return F_2 ( V_2 , V_2 -> V_9 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
if ( V_2 -> V_43 ) {
V_27 = V_2 -> V_43 ( V_2 ) ;
if ( V_27 >= 0 ) {
V_2 -> V_9 = V_27 ;
return 0 ;
}
}
return V_27 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_44 ) ;
V_2 -> V_31 |= V_45 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_44 ) ;
V_2 -> V_31 &= ~ V_45 ;
}
