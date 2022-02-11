static void F_1 ( struct V_1 * V_2 ,
unsigned long long V_3 , T_1 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 = F_3 ( * V_4 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
F_5 ( & V_2 -> V_8 ) ;
}
static void F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 , int V_15 ,
int V_16 , unsigned long long V_3 ,
void * V_17 , T_2 V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
T_1 * V_4 = ( T_1 * ) V_17 ;
F_7 ( V_10 , V_12 , V_20 ) ;
if ( V_3 == V_2 -> V_21 . V_3 )
F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_9 ( V_2 -> V_24 ) ;
T_1 V_17 [ 2 ] ;
V_17 [ 0 ] = F_10 ( ( V_23 -> V_10 -> V_25 << 16 ) |
( V_2 -> V_21 . V_3 >> 32 ) ) ;
V_17 [ 1 ] = F_10 ( V_2 -> V_21 . V_3 ) ;
return F_11 ( V_2 -> V_24 , V_26 ,
V_27 + V_28 ,
& V_17 , sizeof( V_17 ) , 0 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 . V_19 == NULL )
return;
F_13 ( & V_2 -> V_21 ) ;
V_2 -> V_21 . V_19 = NULL ;
}
int F_14 ( struct V_1 * V_2 )
{
static const struct V_29 V_30 = {
. V_31 = 0xffffe0000000ull ,
. V_32 = 0xffffe000ffffull ,
} ;
int V_33 ;
V_2 -> V_21 . V_18 = 4 ;
V_2 -> V_21 . V_34 = F_6 ;
V_2 -> V_21 . V_19 = V_2 ;
V_33 = F_15 ( & V_2 -> V_21 ,
& V_30 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_8 ( V_2 ) ;
if ( V_33 < 0 )
F_12 ( V_2 ) ;
return V_33 ;
}
