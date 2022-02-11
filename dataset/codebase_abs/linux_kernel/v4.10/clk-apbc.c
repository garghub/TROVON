static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( V_4 -> V_6 & V_9 )
V_5 |= V_10 ;
V_5 |= V_11 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
F_7 ( V_4 -> V_12 ) ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
V_5 |= V_13 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
F_7 ( V_4 -> V_12 ) ;
if ( ! ( V_4 -> V_6 & V_14 ) ) {
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
V_5 &= ~ V_15 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( V_4 -> V_6 & V_9 )
V_5 &= ~ V_10 ;
V_5 &= ~ V_11 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
F_7 ( 10 ) ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
V_5 &= ~ V_13 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
}
struct V_16 * F_9 ( const char * V_17 , const char * V_18 ,
void T_1 * V_8 , unsigned int V_12 ,
unsigned int V_19 , T_2 * V_7 )
{
struct V_3 * V_4 ;
struct V_16 * V_16 ;
struct V_20 V_21 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return NULL ;
V_21 . V_17 = V_17 ;
V_21 . V_23 = & V_24 ;
V_21 . V_6 = V_25 ;
V_21 . V_26 = ( V_18 ? & V_18 : NULL ) ;
V_21 . V_27 = ( V_18 ? 1 : 0 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_6 = V_19 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_21 = & V_21 ;
V_16 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_16 ) )
F_13 ( V_4 ) ;
return V_16 ;
}
