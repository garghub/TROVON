static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_2 ) {
V_8 -> V_2 |= 0x0001 ;
V_8 -> V_2 &= ~ 0x0100 ;
} else {
V_8 -> V_2 &= ~ 0x0001 ;
V_8 -> V_2 |= 0x0100 ;
}
F_2 ( V_10 , 0x010000 | V_8 -> V_2 ) ;
F_3 ( V_10 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_2 ) {
V_8 -> V_2 |= 0x0002 ;
V_8 -> V_2 &= ~ 0x0200 ;
} else {
V_8 -> V_2 &= ~ 0x0002 ;
V_8 -> V_2 |= 0x0200 ;
}
F_2 ( V_10 , 0x020000 | V_8 -> V_2 ) ;
F_3 ( V_10 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_2 ;
V_2 = F_3 ( V_10 ) ;
return ( V_2 & 0x01 ) ? 1 : 0 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_2 ;
V_2 = F_3 ( V_10 ) ;
return ( V_2 & 0x02 ) ? 1 : 0 ;
}
int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
int V_11 ;
if ( V_6 -> V_12 != V_13 )
return 0 ;
V_8 = F_8 ( sizeof( * V_8 ) , V_14 ) ;
if ( V_8 == NULL )
return - V_15 ;
V_4 -> V_9 = V_8 ;
memcpy ( & V_8 -> V_16 , & V_17 ,
sizeof( V_8 -> V_16 ) ) ;
V_8 -> V_18 . V_4 . V_19 = & V_4 -> V_20 -> V_4 ;
F_9 ( V_8 -> V_18 . V_21 , V_6 -> V_21 ,
sizeof( V_8 -> V_18 . V_21 ) ) ;
V_8 -> V_18 . V_22 = V_23 ;
V_8 -> V_16 . V_1 = V_4 ;
F_10 ( & V_8 -> V_18 , V_4 ) ;
V_8 -> V_18 . V_24 = & V_8 -> V_16 ;
F_1 ( V_4 , 1 ) ;
F_4 ( V_4 , 1 ) ;
V_11 = F_11 ( & V_8 -> V_18 ) ;
if ( 0 != V_11 ) {
F_12 ( L_1 , V_6 -> V_21 ) ;
F_13 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
return V_11 ;
}
void F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_8 == NULL ||
V_4 -> V_6 -> V_12 != V_13 )
return;
F_15 ( & V_8 -> V_18 ) ;
F_13 ( V_8 ) ;
}
