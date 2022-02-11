void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! F_2 () )
return;
V_4 = F_3 ( V_2 , V_5 ,
1 << V_6 , V_3 << V_6 ) ;
if ( V_4 < 0 ) {
F_4 ( V_7 L_1 , V_4 ) ;
return;
}
F_5 ( V_8 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! F_2 () )
return;
V_3 = V_3 ? 0 : 1 ;
V_4 = F_3 ( V_2 , V_9 ,
1 << V_10 , V_3 << V_10 ) ;
if ( V_4 < 0 )
F_4 ( V_7 L_2 , V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> type = V_15 ;
V_14 -> V_16 = 1 ;
V_14 -> V_17 . integer . V_18 = 0 ;
V_14 -> V_17 . integer . V_19 = 1 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
V_21 -> V_17 . integer . V_17 [ 0 ] = F_9 ( V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_12 ) ;
F_1 ( V_23 -> V_2 , V_21 -> V_17 . integer . V_17 [ 0 ] ) ;
return 1 ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> type = V_15 ;
V_14 -> V_16 = 1 ;
V_14 -> V_17 . integer . V_18 = 0 ;
V_14 -> V_17 . integer . V_19 = 1 ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_12 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
int V_24 ;
V_24 = ( F_14 ( V_2 , V_9 ) >> V_10 ) & 0x1 ;
V_21 -> V_17 . integer . V_17 [ 0 ] = V_24 ? 0 : 1 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_12 ) ;
F_6 ( V_23 -> V_2 , V_21 -> V_17 . integer . V_17 [ 0 ] ) ;
return 1 ;
}
void F_16 ( struct V_25 * V_26 ,
struct V_27 * V_2 )
{
if ( ! F_2 () )
return;
if ( F_17 ( F_18 ( 0xb3 ) ) )
V_2 -> V_28 |= V_29 ;
}
int F_19 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_30 V_31 ;
int V_24 , V_4 ;
if ( ! F_2 () )
return 0 ;
if ( F_20 ( V_8 , V_32 ) ) {
F_21 (KERN_ERR DRV_NAME L_3 ) ;
return - V_33 ;
}
F_22 ( V_8 , 0 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = V_35 ;
strncpy ( V_31 . V_36 , L_4 , sizeof( V_31 . V_36 ) ) ;
F_23 ( V_26 , & V_31 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_34 = V_35 ;
strncpy ( V_31 . V_36 , L_5 , sizeof( V_31 . V_36 ) ) ;
F_23 ( V_26 , & V_31 ) ;
for ( V_24 = 0 ; V_24 < F_24 ( V_37 ) ; V_24 ++ ) {
V_4 = F_25 ( V_26 , F_26 ( & V_37 [ V_24 ] ,
V_2 -> V_38 ) ) ;
if ( V_4 < 0 ) {
F_27 ( V_8 ) ;
return V_4 ;
}
}
F_6 ( V_2 , 0 ) ;
return 0 ;
}
void F_28 ( void )
{
F_27 ( V_8 ) ;
}
