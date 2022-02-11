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
struct V_1 * V_2 ;
int V_14 ;
struct V_25 V_26 ;
V_2 = * (struct V_1 * * ) F_16 ( V_24 ) ;
if ( ! V_2 )
return - V_27 ;
if ( F_17 ( V_2 ) < 0 )
return - V_28 ;
V_2 -> V_22 = F_18 ( 16 ) ;
if ( ! V_2 -> V_22 )
return - V_29 ;
V_2 -> V_22 -> V_6 = V_2 ;
V_14 = F_19 ( V_2 -> V_3 , V_2 -> V_30 ,
L_1 ) ;
if ( V_14 < 0 ) {
F_14 ( V_2 -> V_22 ) ;
return V_14 ;
}
V_2 -> V_31 = V_14 ;
V_2 -> V_22 -> V_14 = V_14 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_32 = V_33 ;
V_26 . V_34 = F_5 ;
V_26 . V_35 = F_9 ;
V_26 . V_36 = F_11 ;
V_26 . V_37 = F_13 ;
V_26 . V_6 = V_2 ;
V_2 -> V_22 -> V_38 = F_20 ( V_14 , & V_26 ,
V_39 |
V_40 ,
V_41 |
V_42 |
V_43 |
V_44 ,
16 , 24 ,
L_2 ) ;
if ( V_2 -> V_22 -> V_38 < 0 ) {
int V_9 = V_2 -> V_22 -> V_38 ;
F_14 ( V_2 -> V_22 ) ;
F_21 ( V_14 ) ;
V_2 -> V_31 = - 1 ;
return V_9 ;
}
return 0 ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
V_2 = * (struct V_1 * * ) F_16 ( V_24 ) ;
if ( ! V_2 )
return - V_27 ;
if ( V_2 -> V_31 >= 0 ) {
F_21 ( V_2 -> V_31 ) ;
V_2 -> V_31 = - 1 ;
}
return 0 ;
}
static int T_1 F_23 ( void )
{
static struct V_45 V_46 = {
F_15 ,
F_22
} ;
return F_24 ( V_47 , & V_46 ,
sizeof( struct V_1 * ) ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( V_47 ) ;
}
