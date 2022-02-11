int
F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * * V_5 )
{
int V_6 = F_2 ( & V_2 -> V_7 , 0 , 1 , V_3 , V_3 , 1 , V_5 ) ;
if ( V_6 )
* V_5 = NULL ;
return V_6 ;
}
void
F_3 ( struct V_1 * V_2 , struct V_4 * * V_5 )
{
F_4 ( & V_2 -> V_7 , V_5 ) ;
}
void
F_5 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 )
{
const T_1 V_10 = V_8 + V_9 - 1 ;
F_6 ( ( V_8 > V_10 ) || ( V_10 >= V_2 -> V_11 ) ) ;
F_7 ( & V_2 -> V_12 . V_13 ) ;
V_2 -> V_14 -> V_15 ( V_2 , V_8 , V_10 ) ;
V_2 -> V_14 -> V_16 ( V_2 ) ;
F_8 ( & V_2 -> V_12 . V_13 ) ;
}
int
F_9 ( struct V_1 * V_2 , int V_17 , const T_1 V_18 [ 4 ] )
{
memcpy ( V_2 -> V_19 [ V_17 ] , V_18 , sizeof( V_2 -> V_19 [ V_17 ] ) ) ;
V_2 -> V_14 -> V_20 ( V_2 , V_17 , V_18 ) ;
return V_17 ;
}
int
F_10 ( struct V_1 * V_2 , int V_17 , const T_1 V_21 )
{
V_2 -> V_22 [ V_17 ] = V_21 ;
V_2 -> V_14 -> V_23 ( V_2 , V_17 , V_21 ) ;
return V_17 ;
}
void
F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 -> V_24 )
V_2 -> V_14 -> V_24 ( V_2 ) ;
}
void
F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 -> V_25 )
V_2 -> V_14 -> V_25 ( V_2 ) ;
}
static void
F_13 ( struct V_26 * V_12 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
V_2 -> V_14 -> V_27 ( V_2 ) ;
}
static int
F_14 ( struct V_26 * V_12 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
return V_2 -> V_14 -> V_28 ( V_2 ) ;
}
static int
F_15 ( struct V_26 * V_12 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
int V_29 ;
for ( V_29 = V_2 -> V_30 ; V_29 <= V_2 -> V_31 ; V_29 ++ ) {
V_2 -> V_14 -> V_20 ( V_2 , V_29 , V_2 -> V_19 [ V_29 ] ) ;
V_2 -> V_14 -> V_23 ( V_2 , V_29 , V_2 -> V_22 [ V_29 ] ) ;
}
V_2 -> V_14 -> V_32 ( V_2 ) ;
return 0 ;
}
static void *
F_16 ( struct V_26 * V_12 )
{
struct V_1 * V_2 = V_1 ( V_12 ) ;
struct V_33 * V_34 = V_2 -> V_12 . V_35 -> V_36 -> V_34 ;
F_17 ( & V_2 -> V_7 ) ;
if ( V_34 )
F_4 ( & V_34 -> V_37 , & V_2 -> V_38 ) ;
return V_2 ;
}
int
F_18 ( const struct V_39 * V_14 , struct V_40 * V_35 ,
int V_17 , struct V_1 * * V_41 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_41 = F_19 ( sizeof( * V_2 ) , V_42 ) ) )
return - V_43 ;
F_20 ( & V_1 , V_35 , V_17 , & V_2 -> V_12 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = F_21 ( V_14 -> V_44 , V_45 ) - 1 ;
return 0 ;
}
