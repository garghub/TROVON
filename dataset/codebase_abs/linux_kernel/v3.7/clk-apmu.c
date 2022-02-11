static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) | V_4 -> V_9 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
unsigned long V_6 = 0 ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_6 ) ;
V_5 = F_4 ( V_4 -> V_8 ) & ~ V_4 -> V_9 ;
F_5 ( V_5 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 )
F_6 ( V_4 -> V_7 , V_6 ) ;
}
struct V_10 * F_8 ( const char * V_11 , const char * V_12 ,
void T_1 * V_8 , T_2 V_9 , T_3 * V_7 )
{
struct V_3 * V_4 ;
struct V_10 * V_10 ;
struct V_13 V_14 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
return NULL ;
V_14 . V_11 = V_11 ;
V_14 . V_16 = & V_17 ;
V_14 . V_6 = V_18 ;
V_14 . V_19 = ( V_12 ? & V_12 : NULL ) ;
V_14 . V_20 = ( V_12 ? 1 : 0 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_14 = & V_14 ;
V_10 = F_10 ( NULL , & V_4 -> V_2 ) ;
if ( F_11 ( V_10 ) )
F_12 ( V_4 ) ;
return V_10 ;
}
