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
V_2 -> V_12 -> V_13 ( V_2 , V_8 , V_10 ) ;
V_2 -> V_12 -> V_14 ( V_2 ) ;
}
int
F_7 ( struct V_1 * V_2 , int V_15 , const T_1 V_16 [ 4 ] )
{
memcpy ( V_2 -> V_17 [ V_15 ] , V_16 , sizeof( V_2 -> V_17 [ V_15 ] ) ) ;
V_2 -> V_12 -> V_18 ( V_2 , V_15 , V_16 ) ;
return V_15 ;
}
int
F_8 ( struct V_1 * V_2 , int V_15 , const T_1 V_19 )
{
V_2 -> V_20 [ V_15 ] = V_19 ;
V_2 -> V_12 -> V_21 ( V_2 , V_15 , V_19 ) ;
return V_15 ;
}
void
F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 -> V_22 )
V_2 -> V_12 -> V_22 ( V_2 ) ;
}
void
F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 -> V_23 )
V_2 -> V_12 -> V_23 ( V_2 ) ;
}
static void
F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
V_2 -> V_12 -> V_26 ( V_2 ) ;
}
static int
F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
return V_2 -> V_12 -> V_27 ( V_2 ) ;
}
static int
F_13 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
int V_28 ;
for ( V_28 = V_2 -> V_29 ; V_28 <= V_2 -> V_30 ; V_28 ++ ) {
V_2 -> V_12 -> V_18 ( V_2 , V_28 , V_2 -> V_17 [ V_28 ] ) ;
V_2 -> V_12 -> V_21 ( V_2 , V_28 , V_2 -> V_20 [ V_28 ] ) ;
}
V_2 -> V_12 -> V_31 ( V_2 ) ;
return 0 ;
}
static void *
F_14 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_1 ( V_25 ) ;
struct V_32 * V_33 = V_2 -> V_25 . V_34 -> V_35 -> V_33 ;
F_15 ( & V_2 -> V_7 ) ;
if ( V_33 )
F_4 ( & V_33 -> V_36 , & V_2 -> V_37 ) ;
return V_2 ;
}
int
F_16 ( const struct V_38 * V_12 , struct V_39 * V_34 ,
int V_15 , struct V_1 * * V_40 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_40 = F_17 ( sizeof( * V_2 ) , V_41 ) ) )
return - V_42 ;
F_18 ( & V_1 , V_34 , V_15 , 0 , & V_2 -> V_25 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_29 = 1 ;
V_2 -> V_30 = F_19 ( V_12 -> V_43 , V_44 ) - 1 ;
return 0 ;
}
