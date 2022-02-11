void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 , V_5 ) ;
F_2 ( V_2 -> V_3 . V_6 , V_5 ) ;
F_2 ( V_2 -> V_3 . V_7 , V_5 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_4 ( V_9 -> V_10 , V_2 -> V_3 . V_4 , V_2 -> V_3 . V_6 , V_5 ) ;
F_4 ( V_9 -> V_10 , V_9 -> V_10 , V_2 -> V_3 . V_7 , V_5 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_8 * V_11 )
{
struct V_8 V_9 ;
F_3 ( V_2 , & V_9 ) ;
if ( ! F_6 ( V_11 -> V_10 , V_9 . V_10 , V_5 ) )
return - V_12 ;
F_7 ( V_2 -> V_3 . V_7 , V_2 -> V_3 . V_7 , V_11 -> V_10 , V_5 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 , struct V_8 * V_11 )
{
F_9 ( V_2 -> V_3 . V_7 , V_2 -> V_3 . V_7 , V_11 -> V_10 , V_5 ) ;
F_7 ( V_2 -> V_3 . V_6 , V_2 -> V_3 . V_6 , V_11 -> V_10 , V_5 ) ;
V_2 -> V_3 . V_13 = false ;
}
void F_10 ( struct V_1 * V_2 , struct V_8 * V_11 )
{
F_9 ( V_2 -> V_3 . V_6 , V_2 -> V_3 . V_6 , V_11 -> V_10 , V_5 ) ;
F_9 ( V_2 -> V_3 . V_7 , V_2 -> V_3 . V_7 , V_11 -> V_10 , V_5 ) ;
V_2 -> V_3 . V_13 = false ;
F_11 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
F_4 ( V_9 . V_10 , V_2 -> V_3 . V_4 , V_2 -> V_3 . V_6 , V_5 ) ;
V_2 -> V_3 . V_14 . V_15 . V_16 = V_17 ;
V_2 -> V_3 . V_14 . V_15 . V_18 = V_5 / 8 ;
F_13 ( V_2 -> V_3 . V_14 . V_19 , & V_9 ) ;
V_2 -> V_3 . V_13 = true ;
}
static
unsigned long F_14 ( T_1 * V_20 , T_2 V_21 , T_2 V_22 )
{
unsigned long V_23 = 0 ;
T_2 V_24 = V_21 + V_22 ;
F_15 ( V_22 > sizeof( V_23 ) ) ;
while ( V_21 < V_24 ) {
V_23 <<= 8 ;
V_23 |= V_20 [ V_24 - 1 ] ;
V_24 -- ;
}
V_23 <<= 8 * ( sizeof( V_23 ) - V_22 ) ;
return V_23 ;
}
static
void F_16 ( unsigned long * V_25 , void * V_26 ,
T_2 V_27 )
{
T_1 * V_28 = V_26 ;
T_2 V_21 , V_22 ;
unsigned long V_23 ;
V_21 = 0 ;
while ( V_21 < V_27 ) {
V_22 = V_27 - V_21 >= sizeof( V_23 ) ?
sizeof( V_23 ) : V_27 - V_21 ;
V_23 = F_14 ( V_28 , V_21 , V_22 ) ;
V_25 [ V_21 / sizeof( V_23 ) ] = V_23 ;
V_21 += sizeof( V_23 ) ;
}
}
static
int F_17 ( struct V_29 * V_30 , unsigned long * V_19 )
{
struct V_31 * V_32 = & V_30 -> V_2 -> V_33 . V_32 ;
struct V_34 * V_35 ;
int V_36 = - V_37 ;
if ( V_30 -> V_38 . V_39 < sizeof( * V_35 ) ) {
F_18 ( V_32 , L_1
L_2
L_3 , V_30 -> V_38 . V_39 , sizeof( * V_35 ) ) ;
goto error;
}
V_35 = F_19 ( V_30 -> V_38 . V_40 , struct V_34 , V_40 ) ;
F_16 ( V_19 , V_35 -> V_19 , V_5 / 8 ) ;
V_36 = 0 ;
error:
return V_36 ;
}
int F_20 ( struct V_29 * V_30 )
{
int V_36 ;
struct V_1 * V_2 = V_30 -> V_2 ;
F_21 ( V_19 , V_5 ) ;
V_36 = F_17 ( V_30 , V_19 ) ;
if ( V_36 < 0 )
return V_36 ;
F_22 ( & V_2 -> V_41 ) ;
F_23 ( V_2 -> V_3 . V_4 , V_19 , V_5 ) ;
V_2 -> V_3 . V_13 = false ;
F_11 ( V_2 ) ;
F_24 ( & V_2 -> V_41 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
