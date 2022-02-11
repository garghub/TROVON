static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 1 ;
if ( ! ( F_3 ( V_4 ) & F_4 ( V_4 ) ) )
V_5 = 0 ;
if ( ! ( V_4 -> V_6 & V_7 ) )
if ( F_5 ( V_4 ) & F_4 ( V_4 ) )
V_5 = 0 ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
F_7 ( & V_8 , V_6 ) ;
V_4 -> V_9 [ V_4 -> V_10 ] ++ ;
if ( V_4 -> V_9 [ V_4 -> V_10 ] > 1 ) {
F_8 ( & V_8 , V_6 ) ;
return 0 ;
}
F_9 ( F_4 ( V_4 ) , V_4 ) ;
F_10 ( 2 ) ;
if ( ! ( V_4 -> V_6 & V_7 ) &&
! ( V_4 -> V_6 & V_11 ) ) {
if ( F_5 ( V_4 ) & F_4 ( V_4 ) ) {
F_10 ( 5 ) ;
F_11 ( F_4 ( V_4 ) , V_4 ) ;
}
}
if ( V_4 -> V_6 & V_12 ) {
F_12 ( 0 , V_4 -> V_13 + V_14 ) ;
F_12 ( F_13 ( 22 ) , V_4 -> V_13 + V_14 ) ;
F_10 ( 1 ) ;
F_12 ( 0 , V_4 -> V_13 + V_14 ) ;
}
F_8 ( & V_8 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
F_7 ( & V_8 , V_6 ) ;
V_4 -> V_9 [ V_4 -> V_10 ] -- ;
if ( V_4 -> V_9 [ V_4 -> V_10 ] > 0 ) {
F_8 ( & V_8 , V_6 ) ;
return;
}
if ( V_4 -> V_6 & V_15 )
F_15 () ;
F_16 ( F_4 ( V_4 ) , V_4 ) ;
F_8 ( & V_8 , V_6 ) ;
}
void F_17 ( struct V_3 * V_4 , bool assert )
{
if ( V_4 -> V_6 & V_7 )
return;
if ( assert ) {
if ( V_4 -> V_6 & V_15 )
F_15 () ;
F_18 ( F_4 ( V_4 ) , V_4 ) ;
} else {
F_11 ( F_4 ( V_4 ) , V_4 ) ;
}
}
struct V_16 * F_19 ( const char * V_17 ,
const char * V_18 , T_1 V_19 , void T_2 * V_13 ,
unsigned long V_6 , int V_10 ,
struct V_20 * V_21 , int * V_9 )
{
struct V_3 * V_4 ;
struct V_16 * V_16 ;
struct V_22 V_23 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 ) {
F_21 ( L_1 , V_25 ) ;
return F_22 ( - V_26 ) ;
}
V_23 . V_17 = V_17 ;
V_23 . V_6 = V_6 ;
V_23 . V_27 = V_18 ? & V_18 : NULL ;
V_23 . V_28 = V_18 ? 1 : 0 ;
V_23 . V_29 = & V_30 ;
V_4 -> V_31 = V_32 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_6 = V_19 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_33 = V_21 ;
V_4 -> V_2 . V_23 = & V_23 ;
V_16 = F_23 ( NULL , & V_4 -> V_2 ) ;
if ( F_24 ( V_16 ) )
F_25 ( V_4 ) ;
return V_16 ;
}
