static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_11 -> V_7 . integer . V_7 [ 0 ] = V_13 -> V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_15 = 0 ;
int V_16 = V_11 -> V_7 . integer . V_7 [ 0 ] ;
if ( V_16 != V_13 -> V_14 ) {
V_13 -> V_14 = V_16 ;
V_15 = 1 ;
}
return V_15 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_4 -> type = V_17 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . V_18 . V_19 = V_13 -> V_20 + 1 ;
if ( V_4 -> V_7 . V_18 . V_21 > V_13 -> V_20 )
V_4 -> V_7 . V_18 . V_21 = V_13 -> V_20 ;
sprintf ( V_4 -> V_7 . V_18 . V_22 , L_1 ,
( unsigned long ) F_6 ( V_4 -> V_7 . V_18 . V_21 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_11 -> V_7 . V_18 . V_21 [ 0 ] = V_13 -> V_23 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_15 = 0 ;
int V_23 = V_11 -> V_7 . V_18 . V_21 [ 0 ] ;
if ( V_23 != V_13 -> V_23 ) {
V_13 -> V_23 = V_23 ;
#if V_24
F_9 ( V_25 L_2 , F_10 () ) ;
#endif
V_15 = 1 ;
}
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
V_11 -> V_7 . integer . V_7 [ 0 ] = V_13 -> V_26 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_15 = 0 ;
int V_27 = V_11 -> V_7 . integer . V_7 [ 0 ] ;
if ( V_27 != V_13 -> V_26 ) {
V_13 -> V_26 = V_27 ;
V_15 = 1 ;
}
return V_15 ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_28 * V_29 , int V_30 )
{
int V_31 , V_32 ;
struct V_33 * V_34 = V_13 -> V_34 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_32 = F_15 ( V_34 , F_16 ( V_29 + V_31 , V_13 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
return 0 ;
}
int F_17 ( struct V_12 * V_13 , int V_35 )
{
int V_32 ;
struct V_33 * V_34 = V_13 -> V_34 ;
if ( ! V_35 ) {
V_32 = F_14 ( V_13 , V_36 ,
F_18 ( V_36 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_32 = F_14 ( V_13 , V_37 ,
F_18 ( V_37 ) ) ;
if ( V_32 < 0 )
return V_32 ;
strcpy ( V_34 -> V_38 , L_3 ) ;
return 0 ;
}
