int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_3 V_5 )
{
int V_6 ;
if ( V_5 % sizeof( T_2 ) > 0 || V_5 <= 0 )
return - V_7 ;
if ( V_5 == sizeof( T_2 ) )
V_6 = V_8 ;
else
V_6 = V_9 ;
return F_2 ( V_2 -> V_10 , V_6 ,
V_11 + V_3 , V_4 , V_5 , 0 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_3 V_5 )
{
int V_6 ;
if ( V_5 % sizeof( T_2 ) > 0 || V_5 <= 0 )
return - V_7 ;
if ( V_5 == sizeof( T_2 ) )
V_6 = V_12 ;
else
V_6 = V_13 ;
return F_2 ( V_2 -> V_10 , V_6 ,
V_11 + V_3 , V_4 , V_5 , 0 ) ;
}
static void F_4 ( struct V_14 * V_15 , struct V_16 * V_17 ,
int V_6 , int V_18 , int V_19 ,
int V_20 , unsigned long long V_3 ,
void * V_21 , T_3 V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
T_2 * V_24 = ( T_2 * ) V_21 ;
unsigned long V_25 ;
if ( V_6 != V_12 ) {
F_5 ( V_15 , V_17 , V_26 ) ;
return;
}
if ( V_3 != V_2 -> V_27 . V_3 || V_22 != 4 ) {
F_5 ( V_15 , V_17 , V_28 ) ;
return;
}
F_6 ( & V_2 -> V_29 , V_25 ) ;
V_2 -> V_30 = F_7 ( * V_24 ) ;
F_8 ( & V_2 -> V_29 , V_25 ) ;
F_5 ( V_15 , V_17 , V_26 ) ;
F_9 ( & V_2 -> V_31 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_11 ( V_2 -> V_10 ) ;
T_2 V_21 ;
int V_34 ;
if ( V_2 -> V_27 . V_23 == NULL )
return - V_7 ;
V_21 = F_12 ( ( V_33 -> V_15 -> V_35 << 16 ) |
( V_2 -> V_27 . V_3 >> 32 ) ) ;
V_34 = F_3 ( V_2 , V_36 , & V_21 ,
sizeof( V_21 ) ) ;
if ( V_34 < 0 )
return V_34 ;
V_21 = F_12 ( V_2 -> V_27 . V_3 ) ;
return F_3 ( V_2 , V_37 , & V_21 ,
sizeof( V_21 ) ) ;
}
int F_13 ( struct V_1 * V_2 )
{
static const struct V_38 V_39 = {
. V_40 = 0xffffe0000000ull ,
. V_41 = 0xffffe000ffffull ,
} ;
int V_34 ;
V_2 -> V_27 . V_22 = 4 ;
V_2 -> V_27 . V_42 = F_4 ;
V_2 -> V_27 . V_23 = V_2 ;
V_34 = F_14 ( & V_2 -> V_27 ,
& V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_10 ( V_2 ) ;
if ( V_34 < 0 ) {
F_15 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_42 = NULL ;
}
return V_34 ;
}
void F_16 ( struct V_1 * V_2 )
{
T_2 V_21 ;
if ( V_2 -> V_27 . V_42 != NULL )
F_15 ( & V_2 -> V_27 ) ;
V_2 -> V_27 . V_42 = NULL ;
V_21 = F_12 ( 0x00000000 ) ;
F_3 ( V_2 , V_36 , & V_21 , sizeof( V_21 ) ) ;
F_3 ( V_2 , V_37 , & V_21 , sizeof( V_21 ) ) ;
}
