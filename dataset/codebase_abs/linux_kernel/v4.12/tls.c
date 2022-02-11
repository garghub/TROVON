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
if ( F_4 ( V_11 ) || F_5 ( V_11 ) ) {
V_19 -> V_21 = V_19 -> V_22 = 0 ;
} else {
F_8 ( V_19 , V_11 ) ;
V_19 -> type |= 1 ;
}
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
unsigned short T_2 V_25 , V_26 ;
if ( F_12 ( & V_11 , V_23 , sizeof( V_11 ) ) )
return - V_27 ;
if ( ! F_3 ( & V_11 ) )
return - V_28 ;
if ( V_5 == - 1 )
V_5 = V_11 . V_29 ;
if ( V_5 == - 1 && V_24 ) {
V_5 = F_1 () ;
if ( V_5 < 0 )
return V_5 ;
if ( F_13 ( V_5 , & V_23 -> V_29 ) )
return - V_27 ;
}
if ( V_5 < V_8 || V_5 > V_30 )
return - V_28 ;
F_6 ( V_16 , V_5 , & V_11 , 1 ) ;
V_26 = ( V_5 << 3 ) | 3 ;
if ( V_16 == V_3 ) {
#ifdef F_14
F_15 ( V_31 , V_25 ) ;
if ( V_25 == V_26 )
F_16 ( V_31 , V_25 ) ;
F_15 ( V_32 , V_25 ) ;
if ( V_25 == V_26 )
F_16 ( V_32 , V_25 ) ;
F_15 ( V_33 , V_25 ) ;
if ( V_25 == V_26 )
F_16 ( V_33 , V_25 ) ;
F_15 ( V_34 , V_25 ) ;
if ( V_25 == V_26 )
F_17 ( V_25 ) ;
#endif
#ifdef F_18
F_15 ( V_34 , V_25 ) ;
if ( V_25 == V_26 )
F_16 ( V_34 , V_25 ) ;
#endif
} else {
#ifdef F_14
if ( V_16 -> V_4 . V_35 == V_26 )
V_16 -> V_4 . V_36 = V_11 . V_37 ;
if ( V_16 -> V_4 . V_38 == V_26 )
V_16 -> V_4 . V_39 = V_11 . V_37 ;
#endif
}
return 0 ;
}
static void F_19 ( struct V_10 * V_11 , int V_5 ,
const struct V_18 * V_19 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_29 = V_5 ;
V_11 -> V_37 = F_20 ( V_19 ) ;
V_11 -> V_40 = F_21 ( V_19 ) ;
V_11 -> V_12 = V_19 -> V_41 ;
V_11 -> V_13 = V_19 -> type >> 2 ;
V_11 -> V_42 = ! ( V_19 -> type & 2 ) ;
V_11 -> V_43 = V_19 -> V_44 ;
V_11 -> V_14 = ! V_19 -> V_16 ;
V_11 -> V_45 = V_19 -> V_46 ;
#ifdef F_14
V_11 -> V_47 = V_19 -> V_48 ;
#endif
}
int F_22 ( struct V_15 * V_16 , int V_5 ,
struct V_10 T_1 * V_23 )
{
struct V_10 V_11 ;
if ( V_5 == - 1 && F_23 ( V_5 , & V_23 -> V_29 ) )
return - V_27 ;
if ( V_5 < V_8 || V_5 > V_30 )
return - V_28 ;
F_19 ( & V_11 , V_5 ,
& V_16 -> V_4 . V_7 [ V_5 - V_8 ] ) ;
if ( F_24 ( V_23 , & V_11 , sizeof( V_11 ) ) )
return - V_27 ;
return 0 ;
}
int F_25 ( struct V_15 * V_49 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 = & V_49 -> V_4 ;
int V_17 = V_6 ;
while ( V_17 > 0 && F_2 ( & V_2 -> V_7 [ V_17 - 1 ] ) )
-- V_17 ;
return V_17 ;
}
int F_26 ( struct V_15 * V_49 , const struct V_50 * V_51 ,
unsigned int V_52 , unsigned int V_53 ,
void * V_54 , void T_1 * V_55 )
{
const struct V_18 * V_56 ;
if ( V_52 >= V_6 * sizeof( struct V_10 ) ||
( V_52 % sizeof( struct V_10 ) ) != 0 ||
( V_53 % sizeof( struct V_10 ) ) != 0 )
return - V_28 ;
V_52 /= sizeof( struct V_10 ) ;
V_53 /= sizeof( struct V_10 ) ;
V_56 = & V_49 -> V_4 . V_7 [ V_52 ] ;
if ( V_54 ) {
struct V_10 * V_11 = V_54 ;
while ( V_53 -- > 0 )
F_19 ( V_11 ++ , V_8 + V_52 ++ ,
V_56 ++ ) ;
} else {
struct V_10 T_1 * V_23 = V_55 ;
while ( V_53 -- > 0 ) {
struct V_10 V_11 ;
F_19 ( & V_11 , V_8 + V_52 ++ , V_56 ++ ) ;
if ( F_27 ( V_23 ++ , & V_11 , sizeof( V_11 ) ) )
return - V_27 ;
}
}
return 0 ;
}
int F_28 ( struct V_15 * V_49 , const struct V_50 * V_51 ,
unsigned int V_52 , unsigned int V_53 ,
const void * V_54 , const void T_1 * V_55 )
{
struct V_10 V_57 [ V_6 ] ;
const struct V_10 * V_11 ;
int V_58 ;
if ( V_52 >= V_6 * sizeof( struct V_10 ) ||
( V_52 % sizeof( struct V_10 ) ) != 0 ||
( V_53 % sizeof( struct V_10 ) ) != 0 )
return - V_28 ;
if ( V_54 )
V_11 = V_54 ;
else if ( F_29 ( V_57 , V_55 , V_53 ) )
return - V_27 ;
else
V_11 = V_57 ;
for ( V_58 = 0 ; V_58 < V_53 / sizeof( struct V_10 ) ; V_58 ++ )
if ( ! F_3 ( V_11 + V_58 ) )
return - V_28 ;
F_6 ( V_49 ,
V_8 + ( V_52 / sizeof( struct V_10 ) ) ,
V_11 , V_53 / sizeof( struct V_10 ) ) ;
return 0 ;
}
