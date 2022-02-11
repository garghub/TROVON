static int F_1 ( void )
{
struct V_1 * V_2 = & V_3 -> V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( F_2 ( & V_2 -> V_7 [ V_5 ] ) )
return V_5 + V_8 ;
return - V_9 ;
}
static bool F_3 ( const struct V_10 * V_11 )
{
if ( F_4 ( V_11 ) || F_5 ( V_11 ) )
return true ;
if ( ! V_11 -> V_12 )
return false ;
if ( V_11 -> V_13 > 1 )
return false ;
if ( V_11 -> V_14 )
return false ;
return true ;
}
static void F_6 ( struct V_15 * V_16 , int V_5 ,
const struct V_10 * V_11 , int V_17 )
{
struct V_1 * V_2 = & V_16 -> V_4 ;
struct V_18 * V_19 = & V_2 -> V_7 [ V_5 - V_8 ] ;
int V_20 ;
V_20 = F_7 () ;
while ( V_17 -- > 0 ) {
if ( F_4 ( V_11 ) || F_5 ( V_11 ) )
V_19 -> V_21 = V_19 -> V_22 = 0 ;
else
F_8 ( V_19 , V_11 ) ;
++ V_11 ;
++ V_19 ;
}
if ( V_2 == & V_3 -> V_4 )
F_9 ( V_2 , V_20 ) ;
F_10 () ;
}
int F_11 ( struct V_15 * V_16 , int V_5 ,
struct V_10 T_1 * V_23 ,
int V_24 )
{
struct V_10 V_11 ;
if ( F_12 ( & V_11 , V_23 , sizeof( V_11 ) ) )
return - V_25 ;
if ( ! F_3 ( & V_11 ) )
return - V_26 ;
if ( V_5 == - 1 )
V_5 = V_11 . V_27 ;
if ( V_5 == - 1 && V_24 ) {
V_5 = F_1 () ;
if ( V_5 < 0 )
return V_5 ;
if ( F_13 ( V_5 , & V_23 -> V_27 ) )
return - V_25 ;
}
if ( V_5 < V_8 || V_5 > V_28 )
return - V_26 ;
F_6 ( V_16 , V_5 , & V_11 , 1 ) ;
return 0 ;
}
static void F_14 ( struct V_10 * V_11 , int V_5 ,
const struct V_18 * V_19 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_27 = V_5 ;
V_11 -> V_29 = F_15 ( V_19 ) ;
V_11 -> V_30 = F_16 ( V_19 ) ;
V_11 -> V_12 = V_19 -> V_31 ;
V_11 -> V_13 = V_19 -> type >> 2 ;
V_11 -> V_32 = ! ( V_19 -> type & 2 ) ;
V_11 -> V_33 = V_19 -> V_34 ;
V_11 -> V_14 = ! V_19 -> V_16 ;
V_11 -> V_35 = V_19 -> V_36 ;
#ifdef F_17
V_11 -> V_37 = V_19 -> V_38 ;
#endif
}
int F_18 ( struct V_15 * V_16 , int V_5 ,
struct V_10 T_1 * V_23 )
{
struct V_10 V_11 ;
if ( V_5 == - 1 && F_19 ( V_5 , & V_23 -> V_27 ) )
return - V_25 ;
if ( V_5 < V_8 || V_5 > V_28 )
return - V_26 ;
F_14 ( & V_11 , V_5 ,
& V_16 -> V_4 . V_7 [ V_5 - V_8 ] ) ;
if ( F_20 ( V_23 , & V_11 , sizeof( V_11 ) ) )
return - V_25 ;
return 0 ;
}
int F_21 ( struct V_15 * V_39 ,
const struct V_40 * V_41 )
{
struct V_1 * V_2 = & V_39 -> V_4 ;
int V_17 = V_6 ;
while ( V_17 > 0 && F_2 ( & V_2 -> V_7 [ V_17 - 1 ] ) )
-- V_17 ;
return V_17 ;
}
int F_22 ( struct V_15 * V_39 , const struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 ,
void * V_44 , void T_1 * V_45 )
{
const struct V_18 * V_46 ;
if ( V_42 >= V_6 * sizeof( struct V_10 ) ||
( V_42 % sizeof( struct V_10 ) ) != 0 ||
( V_43 % sizeof( struct V_10 ) ) != 0 )
return - V_26 ;
V_42 /= sizeof( struct V_10 ) ;
V_43 /= sizeof( struct V_10 ) ;
V_46 = & V_39 -> V_4 . V_7 [ V_42 ] ;
if ( V_44 ) {
struct V_10 * V_11 = V_44 ;
while ( V_43 -- > 0 )
F_14 ( V_11 ++ , V_8 + V_42 ++ ,
V_46 ++ ) ;
} else {
struct V_10 T_1 * V_23 = V_45 ;
while ( V_43 -- > 0 ) {
struct V_10 V_11 ;
F_14 ( & V_11 , V_8 + V_42 ++ , V_46 ++ ) ;
if ( F_23 ( V_23 ++ , & V_11 , sizeof( V_11 ) ) )
return - V_25 ;
}
}
return 0 ;
}
int F_24 ( struct V_15 * V_39 , const struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 ,
const void * V_44 , const void T_1 * V_45 )
{
struct V_10 V_47 [ V_6 ] ;
const struct V_10 * V_11 ;
int V_48 ;
if ( V_42 >= V_6 * sizeof( struct V_10 ) ||
( V_42 % sizeof( struct V_10 ) ) != 0 ||
( V_43 % sizeof( struct V_10 ) ) != 0 )
return - V_26 ;
if ( V_44 )
V_11 = V_44 ;
else if ( F_25 ( V_47 , V_45 , V_43 ) )
return - V_25 ;
else
V_11 = V_47 ;
for ( V_48 = 0 ; V_48 < V_43 / sizeof( struct V_10 ) ; V_48 ++ )
if ( ! F_3 ( V_11 + V_48 ) )
return - V_26 ;
F_6 ( V_39 ,
V_8 + ( V_42 / sizeof( struct V_10 ) ) ,
V_11 , V_43 / sizeof( struct V_10 ) ) ;
return 0 ;
}
