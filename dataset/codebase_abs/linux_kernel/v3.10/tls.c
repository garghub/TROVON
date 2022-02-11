static int F_1 ( void )
{
struct V_1 * V_2 = & V_3 -> V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( F_2 ( & V_2 -> V_7 [ V_5 ] ) )
return V_5 + V_8 ;
return - V_9 ;
}
static void F_3 ( struct V_10 * V_11 , int V_5 ,
const struct V_12 * V_13 , int V_14 )
{
struct V_1 * V_2 = & V_11 -> V_4 ;
struct V_15 * V_16 = & V_2 -> V_7 [ V_5 - V_8 ] ;
int V_17 ;
V_17 = F_4 () ;
while ( V_14 -- > 0 ) {
if ( F_5 ( V_13 ) )
V_16 -> V_18 = V_16 -> V_19 = 0 ;
else
F_6 ( V_16 , V_13 ) ;
++ V_13 ;
++ V_16 ;
}
if ( V_2 == & V_3 -> V_4 )
F_7 ( V_2 , V_17 ) ;
F_8 () ;
}
int F_9 ( struct V_10 * V_11 , int V_5 ,
struct V_12 T_1 * V_20 ,
int V_21 )
{
struct V_12 V_13 ;
if ( F_10 ( & V_13 , V_20 , sizeof( V_13 ) ) )
return - V_22 ;
if ( V_5 == - 1 )
V_5 = V_13 . V_23 ;
if ( V_5 == - 1 && V_21 ) {
V_5 = F_1 () ;
if ( V_5 < 0 )
return V_5 ;
if ( F_11 ( V_5 , & V_20 -> V_23 ) )
return - V_22 ;
}
if ( V_5 < V_8 || V_5 > V_24 )
return - V_25 ;
F_3 ( V_11 , V_5 , & V_13 , 1 ) ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 , int V_5 ,
const struct V_15 * V_16 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_23 = V_5 ;
V_13 -> V_26 = F_13 ( V_16 ) ;
V_13 -> V_27 = F_14 ( V_16 ) ;
V_13 -> V_28 = V_16 -> V_29 ;
V_13 -> V_30 = V_16 -> type >> 2 ;
V_13 -> V_31 = ! ( V_16 -> type & 2 ) ;
V_13 -> V_32 = V_16 -> V_33 ;
V_13 -> V_34 = ! V_16 -> V_11 ;
V_13 -> V_35 = V_16 -> V_36 ;
#ifdef F_15
V_13 -> V_37 = V_16 -> V_38 ;
#endif
}
int F_16 ( struct V_10 * V_11 , int V_5 ,
struct V_12 T_1 * V_20 )
{
struct V_12 V_13 ;
if ( V_5 == - 1 && F_17 ( V_5 , & V_20 -> V_23 ) )
return - V_22 ;
if ( V_5 < V_8 || V_5 > V_24 )
return - V_25 ;
F_12 ( & V_13 , V_5 ,
& V_11 -> V_4 . V_7 [ V_5 - V_8 ] ) ;
if ( F_18 ( V_20 , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
return 0 ;
}
int F_19 ( struct V_10 * V_39 ,
const struct V_40 * V_41 )
{
struct V_1 * V_2 = & V_39 -> V_4 ;
int V_14 = V_6 ;
while ( V_14 > 0 && F_2 ( & V_2 -> V_7 [ V_14 - 1 ] ) )
-- V_14 ;
return V_14 ;
}
int F_20 ( struct V_10 * V_39 , const struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 ,
void * V_44 , void T_1 * V_45 )
{
const struct V_15 * V_46 ;
if ( V_42 >= V_6 * sizeof( struct V_12 ) ||
( V_42 % sizeof( struct V_12 ) ) != 0 ||
( V_43 % sizeof( struct V_12 ) ) != 0 )
return - V_25 ;
V_42 /= sizeof( struct V_12 ) ;
V_43 /= sizeof( struct V_12 ) ;
V_46 = & V_39 -> V_4 . V_7 [ V_42 ] ;
if ( V_44 ) {
struct V_12 * V_13 = V_44 ;
while ( V_43 -- > 0 )
F_12 ( V_13 ++ , V_8 + V_42 ++ ,
V_46 ++ ) ;
} else {
struct V_12 T_1 * V_20 = V_45 ;
while ( V_43 -- > 0 ) {
struct V_12 V_13 ;
F_12 ( & V_13 , V_8 + V_42 ++ , V_46 ++ ) ;
if ( F_21 ( V_20 ++ , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
}
}
return 0 ;
}
int F_22 ( struct V_10 * V_39 , const struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 ,
const void * V_44 , const void T_1 * V_45 )
{
struct V_12 V_47 [ V_6 ] ;
const struct V_12 * V_13 ;
if ( V_42 >= V_6 * sizeof( struct V_12 ) ||
( V_42 % sizeof( struct V_12 ) ) != 0 ||
( V_43 % sizeof( struct V_12 ) ) != 0 )
return - V_25 ;
if ( V_44 )
V_13 = V_44 ;
else if ( F_23 ( V_47 , V_45 , V_43 ) )
return - V_22 ;
else
V_13 = V_47 ;
F_3 ( V_39 ,
V_8 + ( V_42 / sizeof( struct V_12 ) ) ,
V_13 , V_43 / sizeof( struct V_12 ) ) ;
return 0 ;
}
