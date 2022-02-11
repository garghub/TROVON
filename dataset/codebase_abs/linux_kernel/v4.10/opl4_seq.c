static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 -> V_4 ) )
return - V_5 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 -> V_4 ) ;
}
static int F_5 ( void * V_6 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_6 ;
int V_9 ;
F_6 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_11 ) {
F_7 ( & V_2 -> V_10 ) ;
return - V_12 ;
}
V_2 -> V_11 ++ ;
if ( V_8 -> V_13 . V_14 != V_15 ) {
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_10 ) ;
return V_9 ;
}
}
F_7 ( & V_2 -> V_10 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( void * V_6 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_6 ;
F_10 ( V_2 ) ;
F_6 ( & V_2 -> V_10 ) ;
V_2 -> V_11 -- ;
F_7 ( & V_2 -> V_10 ) ;
if ( V_8 -> V_13 . V_14 != V_15 )
F_3 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 , int V_18 ,
void * V_6 , int V_19 , int V_20 )
{
struct V_1 * V_2 = V_6 ;
F_12 ( & V_21 , V_17 , V_2 -> V_22 ) ;
return 0 ;
}
static void F_13 ( void * V_6 )
{
struct V_1 * V_2 = V_6 ;
F_14 ( V_2 -> V_22 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_24 ) ;
struct V_1 * V_2 ;
int V_14 ;
struct V_27 V_28 ;
V_2 = * (struct V_1 * * ) F_17 ( V_26 ) ;
if ( ! V_2 )
return - V_29 ;
if ( F_18 ( V_2 ) < 0 )
return - V_30 ;
V_2 -> V_22 = F_19 ( 16 ) ;
if ( ! V_2 -> V_22 )
return - V_31 ;
V_2 -> V_22 -> V_6 = V_2 ;
V_14 = F_20 ( V_2 -> V_3 , V_2 -> V_32 ,
L_1 ) ;
if ( V_14 < 0 ) {
F_14 ( V_2 -> V_22 ) ;
return V_14 ;
}
V_2 -> V_33 = V_14 ;
V_2 -> V_22 -> V_14 = V_14 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_34 = V_35 ;
V_28 . V_36 = F_5 ;
V_28 . V_37 = F_9 ;
V_28 . V_38 = F_11 ;
V_28 . V_39 = F_13 ;
V_28 . V_6 = V_2 ;
V_2 -> V_22 -> V_40 = F_21 ( V_14 , & V_28 ,
V_41 |
V_42 ,
V_43 |
V_44 |
V_45 |
V_46 ,
16 , 24 ,
L_2 ) ;
if ( V_2 -> V_22 -> V_40 < 0 ) {
int V_9 = V_2 -> V_22 -> V_40 ;
F_14 ( V_2 -> V_22 ) ;
F_22 ( V_14 ) ;
V_2 -> V_33 = - 1 ;
return V_9 ;
}
return 0 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_24 ) ;
struct V_1 * V_2 ;
V_2 = * (struct V_1 * * ) F_17 ( V_26 ) ;
if ( ! V_2 )
return - V_29 ;
if ( V_2 -> V_33 >= 0 ) {
F_22 ( V_2 -> V_33 ) ;
V_2 -> V_33 = - 1 ;
}
return 0 ;
}
