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
F_8 ( & V_8 , V_6 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
F_7 ( & V_8 , V_6 ) ;
V_4 -> V_9 [ V_4 -> V_10 ] -- ;
if ( V_4 -> V_9 [ V_4 -> V_10 ] > 0 ) {
F_8 ( & V_8 , V_6 ) ;
return;
}
if ( V_4 -> V_6 & V_12 )
F_13 () ;
F_14 ( F_4 ( V_4 ) , V_4 ) ;
F_8 ( & V_8 , V_6 ) ;
}
void F_15 ( struct V_3 * V_4 , bool assert )
{
if ( V_4 -> V_6 & V_7 )
return;
if ( assert ) {
if ( V_4 -> V_6 & V_12 )
F_13 () ;
F_16 ( F_4 ( V_4 ) , V_4 ) ;
} else {
F_11 ( F_4 ( V_4 ) , V_4 ) ;
}
}
struct V_13 * F_17 ( const char * V_14 ,
const char * V_15 , T_1 V_16 , void T_2 * V_17 ,
unsigned long V_6 , int V_10 ,
struct V_18 * V_19 , int * V_9 )
{
struct V_3 * V_4 ;
struct V_13 * V_13 ;
struct V_20 V_21 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 ) {
F_19 ( L_1 , V_23 ) ;
return F_20 ( - V_24 ) ;
}
V_21 . V_14 = V_14 ;
V_21 . V_6 = V_6 ;
V_21 . V_25 = V_15 ? & V_15 : NULL ;
V_21 . V_26 = V_15 ? 1 : 0 ;
V_21 . V_27 = & V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_6 = V_16 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_31 = V_19 ;
V_4 -> V_2 . V_21 = & V_21 ;
V_13 = F_21 ( NULL , & V_4 -> V_2 ) ;
if ( F_22 ( V_13 ) )
F_23 ( V_4 ) ;
return V_13 ;
}
