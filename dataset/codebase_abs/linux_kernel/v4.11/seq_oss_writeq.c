struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
struct V_6 V_7 ;
if ( ( V_5 = F_2 ( sizeof( * V_5 ) , V_8 ) ) == NULL )
return NULL ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
F_4 ( & V_5 -> V_12 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_13 = V_3 -> V_14 ;
V_7 . V_15 = V_4 ;
V_7 . V_16 = V_4 / 2 ;
F_5 ( V_3 , V_17 , & V_7 ) ;
return V_5 ;
}
void
F_6 ( struct V_1 * V_5 )
{
if ( V_5 ) {
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
}
}
void
F_7 ( struct V_1 * V_5 )
{
struct V_18 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_20 = V_21 ;
F_5 ( V_5 -> V_3 , V_22 , & V_19 ) ;
F_9 ( V_5 , 0 ) ;
}
int
F_10 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
T_1 time ;
time = F_11 ( V_3 -> V_23 ) ;
if ( V_5 -> V_11 >= time )
return 0 ;
if ( ! V_5 -> V_10 ) {
struct V_24 V_25 ;
union V_26 * V_27 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_28 = 0 ;
V_25 . type = V_29 ;
V_25 . time . V_30 = time ;
F_12 ( V_3 , & V_25 , V_3 -> V_31 . V_13 , V_3 -> V_31 . V_32 ) ;
V_27 = (union V_26 * ) & V_25 . V_33 ;
V_27 -> V_34 . V_35 = V_36 ;
V_27 -> V_34 . time = time ;
V_5 -> V_10 = 1 ;
F_13 ( V_3 -> V_14 , & V_25 , NULL , 0 , 0 ) ;
}
F_14 ( V_5 -> V_12 , ! V_5 -> V_10 , V_37 ) ;
if ( F_15 ( V_38 ) )
V_5 -> V_10 = 0 ;
if ( ! V_5 -> V_10 || V_5 -> V_11 >= time )
return 0 ;
return 1 ;
}
void
F_9 ( struct V_1 * V_5 , T_1 time )
{
unsigned long V_28 ;
F_16 ( & V_5 -> V_9 , V_28 ) ;
V_5 -> V_11 = time ;
V_5 -> V_10 = 0 ;
F_17 ( & V_5 -> V_12 ) ;
F_18 ( & V_5 -> V_9 , V_28 ) ;
}
int
F_19 ( struct V_1 * V_5 )
{
struct V_6 V_7 ;
V_7 . V_13 = V_5 -> V_3 -> V_14 ;
F_5 ( V_5 -> V_3 , V_39 , & V_7 ) ;
return V_7 . V_40 ;
}
void
F_20 ( struct V_1 * V_5 , int V_41 )
{
struct V_6 V_7 ;
V_7 . V_13 = V_5 -> V_3 -> V_14 ;
F_5 ( V_5 -> V_3 , V_39 , & V_7 ) ;
V_7 . V_16 = V_41 ;
F_5 ( V_5 -> V_3 , V_17 , & V_7 ) ;
}
