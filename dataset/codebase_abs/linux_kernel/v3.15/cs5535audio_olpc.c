void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! F_2 () )
return;
V_4 = F_3 ( V_2 , V_5 ,
1 << V_6 , V_3 << V_6 ) ;
if ( V_4 < 0 ) {
F_4 ( V_2 -> V_7 -> V_8 -> V_9 ,
L_1 , V_4 ) ;
return;
}
F_5 ( V_10 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! F_2 () )
return;
V_3 = V_3 ? 0 : 1 ;
V_4 = F_3 ( V_2 , V_11 ,
1 << V_12 , V_3 << V_12 ) ;
if ( V_4 < 0 )
F_4 ( V_2 -> V_7 -> V_8 -> V_9 , L_2 , V_4 ) ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
V_16 -> type = V_17 ;
V_16 -> V_18 = 1 ;
V_16 -> V_19 . integer . V_20 = 0 ;
V_16 -> V_19 . integer . V_21 = 1 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 , struct V_22 * V_23 )
{
V_23 -> V_19 . integer . V_19 [ 0 ] = F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , struct V_22 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_14 ) ;
F_1 ( V_25 -> V_2 , V_23 -> V_19 . integer . V_19 [ 0 ] ) ;
return 1 ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
V_16 -> type = V_17 ;
V_16 -> V_18 = 1 ;
V_16 -> V_19 . integer . V_20 = 0 ;
V_16 -> V_19 . integer . V_21 = 1 ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_22 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_14 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_26 ;
V_26 = ( F_14 ( V_2 , V_11 ) >> V_12 ) & 0x1 ;
V_23 -> V_19 . integer . V_19 [ 0 ] = V_26 ? 0 : 1 ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_22 * V_23 )
{
struct V_24 * V_25 = F_11 ( V_14 ) ;
F_6 ( V_25 -> V_2 , V_23 -> V_19 . integer . V_19 [ 0 ] ) ;
return 1 ;
}
void F_16 ( struct V_27 * V_8 ,
struct V_28 * V_2 )
{
if ( ! F_2 () )
return;
if ( F_17 ( F_18 ( 0xb3 ) ) )
V_2 -> V_29 |= V_30 ;
}
int F_19 ( struct V_27 * V_8 , struct V_1 * V_2 )
{
struct V_31 V_32 ;
int V_26 , V_4 ;
if ( ! F_2 () )
return 0 ;
if ( F_20 ( V_10 , V_33 ) ) {
F_4 ( V_8 -> V_9 , L_3 ) ;
return - V_34 ;
}
F_21 ( V_10 , 0 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_35 = V_36 ;
F_22 ( V_32 . V_37 , L_4 , sizeof( V_32 . V_37 ) ) ;
F_23 ( V_8 , & V_32 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_35 = V_36 ;
F_22 ( V_32 . V_37 , L_5 , sizeof( V_32 . V_37 ) ) ;
F_23 ( V_8 , & V_32 ) ;
for ( V_26 = 0 ; V_26 < F_24 ( V_38 ) ; V_26 ++ ) {
V_4 = F_25 ( V_8 , F_26 ( & V_38 [ V_26 ] ,
V_2 -> V_39 ) ) ;
if ( V_4 < 0 ) {
F_27 ( V_10 ) ;
return V_4 ;
}
}
F_6 ( V_2 , 0 ) ;
return 0 ;
}
void F_28 ( void )
{
F_27 ( V_10 ) ;
}
