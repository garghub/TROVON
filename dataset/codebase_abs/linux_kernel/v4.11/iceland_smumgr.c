static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 , V_6 , 0 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 ,
V_6 , 1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_7 ,
V_8 , 1 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_7 ,
V_8 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_8 ( V_2 , V_9 , V_10 ,
V_11 , 1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_12 , const T_2 * V_13 ,
T_1 V_14 , T_1 V_15 )
{
T_1 V_16 = V_12 ;
T_1 V_17 ;
F_10 ((limit >= byte_count), L_1 , return -EINVAL) ;
F_11 ( V_2 -> V_3 , V_18 , V_15 ) ;
F_12 ( V_2 -> V_3 , V_19 , V_20 , 1 ) ;
while ( V_16 >= 4 ) {
V_17 = V_13 [ 0 ] * 0x1000000 + V_13 [ 1 ] * 0x10000 + V_13 [ 2 ] * 0x100 + V_13 [ 3 ] ;
F_11 ( V_2 -> V_3 , V_21 , V_17 ) ;
V_13 += 4 ;
V_16 -= 4 ;
}
F_12 ( V_2 -> V_3 , V_19 , V_20 , 0 ) ;
F_10 ((0 == byte_count), L_2 , return -EINVAL) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_22 ;
struct V_23 V_24 = { 0 } ;
if ( V_2 == NULL || V_2 -> V_3 == NULL )
return - V_25 ;
F_14 ( V_2 -> V_3 ,
F_15 ( V_26 ) , & V_24 ) ;
if ( V_24 . V_27 & 3 ) {
F_16 ( L_3 ) ;
return - V_25 ;
}
if ( V_24 . V_27 > V_28 ) {
F_16 ( L_4 ) ;
return - V_25 ;
}
F_17 ( V_2 , V_9 ,
V_29 , V_30 , 0 ) ;
V_22 = F_18 ( V_2 -> V_3 , V_4 ,
V_31 ) ;
F_19 ( V_2 -> V_3 , V_4 ,
V_31 , V_22 | 1 ) ;
F_4 ( V_2 ) ;
F_3 ( V_2 ) ;
F_9 ( V_2 , V_24 . V_27 ,
( T_2 * ) V_24 . V_32 , V_28 ,
V_24 . V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_34 )
{
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_13 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_6 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_22 ( V_2 ) ) {
F_23 ( L_5 ) ;
V_35 = F_13 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_6 ( V_2 ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_24 ( V_2 ) ;
return V_35 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_36 ;
struct V_37 * V_38 = NULL ;
V_38 = F_26 ( sizeof( struct V_37 ) , V_39 ) ;
if ( V_38 == NULL )
return - V_40 ;
V_2 -> V_41 = V_38 ;
if ( F_27 ( V_2 ) )
return - V_25 ;
for ( V_36 = 0 ; V_36 < V_42 ; V_36 ++ )
V_38 -> V_43 [ V_36 ] = 30 ;
return 0 ;
}
