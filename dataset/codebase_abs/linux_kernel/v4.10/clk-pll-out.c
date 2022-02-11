static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 ) ;
int V_7 ;
V_7 = ( V_5 & F_4 ( V_4 ) ) ? 1 : 0 ;
if ( ! ( V_5 & ( F_5 ( V_4 ) ) ) )
V_7 = 0 ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_8 = 0 ;
T_1 V_5 ;
if ( V_4 -> V_9 )
F_7 ( V_4 -> V_9 , V_8 ) ;
V_5 = F_3 ( V_4 -> V_6 ) ;
V_5 |= ( F_4 ( V_4 ) | F_5 ( V_4 ) ) ;
F_8 ( V_5 , V_4 -> V_6 ) ;
F_9 ( 2 ) ;
if ( V_4 -> V_9 )
F_10 ( V_4 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_8 = 0 ;
T_1 V_5 ;
if ( V_4 -> V_9 )
F_7 ( V_4 -> V_9 , V_8 ) ;
V_5 = F_3 ( V_4 -> V_6 ) ;
V_5 &= ~ ( F_4 ( V_4 ) | F_5 ( V_4 ) ) ;
F_8 ( V_5 , V_4 -> V_6 ) ;
F_9 ( 2 ) ;
if ( V_4 -> V_9 )
F_10 ( V_4 -> V_9 , V_8 ) ;
}
struct V_10 * F_12 ( const char * V_11 ,
const char * V_12 , void T_2 * V_6 , T_3 V_13 ,
T_3 V_14 , unsigned long V_8 , T_3 V_15 ,
T_4 * V_9 )
{
struct V_3 * V_4 ;
struct V_10 * V_10 ;
struct V_16 V_17 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_14 ( - V_19 ) ;
V_17 . V_11 = V_11 ;
V_17 . V_20 = & V_21 ;
V_17 . V_22 = ( V_12 ? & V_12 : NULL ) ;
V_17 . V_23 = ( V_12 ? 1 : 0 ) ;
V_17 . V_8 = V_8 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_8 = V_15 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 . V_17 = & V_17 ;
V_10 = F_15 ( NULL , & V_4 -> V_2 ) ;
if ( F_16 ( V_10 ) )
F_17 ( V_4 ) ;
return V_10 ;
}
