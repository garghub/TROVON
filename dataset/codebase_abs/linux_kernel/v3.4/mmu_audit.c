static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
T_2 * V_9 = V_4 -> V_10 ;
V_5 ( V_2 , V_9 + V_7 , V_6 ) ;
if ( F_2 ( V_9 [ V_7 ] ) &&
! F_3 ( V_9 [ V_7 ] , V_6 ) ) {
struct V_3 * V_11 ;
V_11 = F_4 ( V_9 [ V_7 ] & V_12 ) ;
F_1 ( V_2 , V_11 , V_5 , V_6 - 1 ) ;
}
}
}
static void F_5 ( struct V_1 * V_2 , T_1 V_5 )
{
int V_7 ;
struct V_3 * V_4 ;
if ( ! F_6 ( V_2 -> V_13 . V_14 . V_15 ) )
return;
if ( V_2 -> V_13 . V_14 . V_16 == V_17 ) {
T_3 V_18 = V_2 -> V_13 . V_14 . V_15 ;
V_4 = F_4 ( V_18 ) ;
F_1 ( V_2 , V_4 , V_5 , V_17 ) ;
return;
}
for ( V_7 = 0 ; V_7 < 4 ; ++ V_7 ) {
T_3 V_18 = V_2 -> V_13 . V_14 . V_19 [ V_7 ] ;
if ( V_18 && F_6 ( V_18 ) ) {
V_18 &= V_12 ;
V_4 = F_4 ( V_18 ) ;
F_1 ( V_2 , V_4 , V_5 , 2 ) ;
}
}
return;
}
static void F_7 ( struct V_20 * V_20 , T_4 V_5 )
{
struct V_3 * V_4 ;
F_8 (sp, &kvm->arch.active_mmu_pages, link)
V_5 ( V_20 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 * V_21 , int V_6 )
{
struct V_3 * V_4 ;
T_5 V_22 ;
T_6 V_23 ;
T_3 V_24 ;
V_4 = F_4 ( F_10 ( V_21 ) ) ;
if ( V_4 -> V_25 ) {
if ( V_6 != V_26 ) {
F_11 ( V_2 -> V_20 , L_1
L_2 , V_4 , V_6 ) ;
return;
}
}
if ( ! F_2 ( * V_21 ) || ! F_3 ( * V_21 , V_6 ) )
return;
V_22 = F_12 ( V_4 , V_21 - V_4 -> V_10 ) ;
V_23 = F_13 ( V_2 -> V_20 , V_22 ) ;
if ( F_14 ( V_23 ) ) {
F_15 ( V_23 ) ;
return;
}
V_24 = V_23 << V_27 ;
if ( ( * V_21 & V_12 ) != V_24 )
F_11 ( V_2 -> V_20 , L_3
L_4 , V_2 -> V_13 . V_14 . V_16 , V_23 ,
V_24 , * V_21 ) ;
}
static void F_16 ( struct V_20 * V_20 , T_2 * V_21 )
{
static F_17 ( V_28 , 5 * V_29 , 10 ) ;
unsigned long * V_30 ;
struct V_3 * V_31 ;
T_5 V_22 ;
V_31 = F_4 ( F_10 ( V_21 ) ) ;
V_22 = F_12 ( V_31 , V_21 - V_31 -> V_10 ) ;
if ( ! F_18 ( V_20 , V_22 ) ) {
if ( ! F_19 ( & V_28 ) )
return;
F_11 ( V_20 , L_5 , V_22 ) ;
F_11 ( V_20 , L_6 ,
( long int ) ( V_21 - V_31 -> V_10 ) , V_31 -> V_22 ) ;
F_20 () ;
return;
}
V_30 = F_21 ( V_20 , V_22 , V_31 -> V_32 . V_6 ) ;
if ( ! * V_30 ) {
if ( ! F_19 ( & V_28 ) )
return;
F_11 ( V_20 , L_7 ,
* V_21 ) ;
F_20 () ;
}
}
static void F_22 ( struct V_1 * V_2 , T_2 * V_21 , int V_6 )
{
if ( F_2 ( * V_21 ) && F_3 ( * V_21 , V_6 ) )
F_16 ( V_2 -> V_20 , V_21 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 * V_21 , int V_6 )
{
struct V_3 * V_4 = F_4 ( F_10 ( V_21 ) ) ;
if ( V_2 -> V_20 -> V_13 . V_33 == V_34 && V_4 -> V_25 )
F_11 ( V_2 -> V_20 , L_8
L_9 , V_4 ) ;
}
static void F_24 ( struct V_20 * V_20 , struct V_3 * V_4 )
{
int V_7 ;
if ( V_4 -> V_32 . V_6 != V_26 )
return;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( ! F_25 ( V_4 -> V_10 [ V_7 ] ) )
continue;
F_16 ( V_20 , V_4 -> V_10 + V_7 ) ;
}
}
static void F_26 ( struct V_20 * V_20 , struct V_3 * V_4 )
{
struct V_35 * V_36 ;
unsigned long * V_30 ;
T_2 * V_37 ;
if ( V_4 -> V_32 . V_38 || V_4 -> V_25 || V_4 -> V_32 . V_39 )
return;
V_36 = F_18 ( V_20 , V_4 -> V_22 ) ;
V_30 = & V_36 -> V_40 [ V_4 -> V_22 - V_36 -> V_41 ] ;
V_37 = F_27 ( V_30 , NULL ) ;
while ( V_37 ) {
if ( F_28 ( * V_37 ) )
F_11 ( V_20 , L_10
L_11 ,
V_4 -> V_22 , V_4 -> V_32 . V_42 ) ;
V_37 = F_27 ( V_30 , V_37 ) ;
}
}
static void F_29 ( struct V_20 * V_20 , struct V_3 * V_4 )
{
F_24 ( V_20 , V_4 ) ;
F_26 ( V_20 , V_4 ) ;
}
static void F_30 ( struct V_20 * V_20 )
{
F_7 ( V_20 , F_29 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_2 * V_21 , int V_6 )
{
F_22 ( V_2 , V_21 , V_6 ) ;
F_9 ( V_2 , V_21 , V_6 ) ;
F_23 ( V_2 , V_21 , V_6 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_5 ( V_2 , F_31 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_43 )
{
static F_17 ( V_28 , 5 * V_29 , 10 ) ;
if ( ! F_19 ( & V_28 ) )
return;
V_2 -> V_20 -> V_13 . V_33 = V_43 ;
F_30 ( V_2 -> V_20 ) ;
F_32 ( V_2 ) ;
}
static inline void F_34 ( struct V_1 * V_2 , int V_43 )
{
if ( F_35 ( ( & V_44 ) ) )
F_33 ( V_2 , V_43 ) ;
}
static void F_36 ( void )
{
if ( V_45 )
return;
F_37 ( & V_44 ) ;
V_45 = true ;
}
static void F_38 ( void )
{
if ( ! V_45 )
return;
F_39 ( & V_44 ) ;
V_45 = false ;
}
static int F_40 ( const char * V_46 , const struct V_47 * V_48 )
{
int V_49 ;
unsigned long V_50 ;
V_49 = F_41 ( V_46 , 10 , & V_50 ) ;
if ( V_49 < 0 )
return - V_51 ;
switch ( V_50 ) {
case 0 :
F_38 () ;
break;
case 1 :
F_36 () ;
break;
default:
return - V_51 ;
}
return 0 ;
}
