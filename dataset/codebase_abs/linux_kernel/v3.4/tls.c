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
T_2 int F_12 ( struct V_12 T_1 * V_20 )
{
int V_26 = F_9 ( V_3 , - 1 , V_20 , 1 ) ;
F_13 ( 1 , V_26 , V_20 ) ;
return V_26 ;
}
static void F_14 ( struct V_12 * V_13 , int V_5 ,
const struct V_15 * V_16 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_23 = V_5 ;
V_13 -> V_27 = F_15 ( V_16 ) ;
V_13 -> V_28 = F_16 ( V_16 ) ;
V_13 -> V_29 = V_16 -> V_30 ;
V_13 -> V_31 = V_16 -> type >> 2 ;
V_13 -> V_32 = ! ( V_16 -> type & 2 ) ;
V_13 -> V_33 = V_16 -> V_34 ;
V_13 -> V_35 = ! V_16 -> V_11 ;
V_13 -> V_36 = V_16 -> V_37 ;
#ifdef F_17
V_13 -> V_38 = V_16 -> V_39 ;
#endif
}
int F_18 ( struct V_10 * V_11 , int V_5 ,
struct V_12 T_1 * V_20 )
{
struct V_12 V_13 ;
if ( V_5 == - 1 && F_19 ( V_5 , & V_20 -> V_23 ) )
return - V_22 ;
if ( V_5 < V_8 || V_5 > V_24 )
return - V_25 ;
F_14 ( & V_13 , V_5 ,
& V_11 -> V_4 . V_7 [ V_5 - V_8 ] ) ;
if ( F_20 ( V_20 , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
return 0 ;
}
T_2 int F_21 ( struct V_12 T_1 * V_20 )
{
int V_26 = F_18 ( V_3 , - 1 , V_20 ) ;
F_13 ( 1 , V_26 , V_20 ) ;
return V_26 ;
}
int F_22 ( struct V_10 * V_40 ,
const struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_40 -> V_4 ;
int V_14 = V_6 ;
while ( V_14 > 0 && F_2 ( & V_2 -> V_7 [ V_14 - 1 ] ) )
-- V_14 ;
return V_14 ;
}
int F_23 ( struct V_10 * V_40 , const struct V_41 * V_42 ,
unsigned int V_43 , unsigned int V_44 ,
void * V_45 , void T_1 * V_46 )
{
const struct V_15 * V_47 ;
if ( V_43 >= V_6 * sizeof( struct V_12 ) ||
( V_43 % sizeof( struct V_12 ) ) != 0 ||
( V_44 % sizeof( struct V_12 ) ) != 0 )
return - V_25 ;
V_43 /= sizeof( struct V_12 ) ;
V_44 /= sizeof( struct V_12 ) ;
V_47 = & V_40 -> V_4 . V_7 [ V_43 ] ;
if ( V_45 ) {
struct V_12 * V_13 = V_45 ;
while ( V_44 -- > 0 )
F_14 ( V_13 ++ , V_8 + V_43 ++ ,
V_47 ++ ) ;
} else {
struct V_12 T_1 * V_20 = V_46 ;
while ( V_44 -- > 0 ) {
struct V_12 V_13 ;
F_14 ( & V_13 , V_8 + V_43 ++ , V_47 ++ ) ;
if ( F_24 ( V_20 ++ , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
}
}
return 0 ;
}
int F_25 ( struct V_10 * V_40 , const struct V_41 * V_42 ,
unsigned int V_43 , unsigned int V_44 ,
const void * V_45 , const void T_1 * V_46 )
{
struct V_12 V_48 [ V_6 ] ;
const struct V_12 * V_13 ;
if ( V_43 >= V_6 * sizeof( struct V_12 ) ||
( V_43 % sizeof( struct V_12 ) ) != 0 ||
( V_44 % sizeof( struct V_12 ) ) != 0 )
return - V_25 ;
if ( V_45 )
V_13 = V_45 ;
else if ( F_26 ( V_48 , V_46 , V_44 ) )
return - V_22 ;
else
V_13 = V_48 ;
F_3 ( V_40 ,
V_8 + ( V_43 / sizeof( struct V_12 ) ) ,
V_13 , V_44 / sizeof( struct V_12 ) ) ;
return 0 ;
}
