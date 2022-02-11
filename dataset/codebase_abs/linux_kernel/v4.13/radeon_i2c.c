static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_4 -> V_8 ) & ~ ( V_9 ) ;
if ( ! V_2 )
V_7 |= V_9 ;
F_3 ( V_4 -> V_8 , V_7 ) ;
( void ) F_2 ( V_4 -> V_8 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_4 -> V_8 ) & ~ ( V_10 ) ;
if ( ! V_2 )
V_7 |= V_10 ;
F_3 ( V_4 -> V_8 , V_7 ) ;
( void ) F_2 ( V_4 -> V_8 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_4 -> V_8 ) ;
return ( V_7 & V_11 ) ? 1 : 0 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_4 -> V_8 ) ;
return ( V_7 & V_12 ) ? 1 : 0 ;
}
static int F_7 ( struct V_3 * V_4 , const char * V_13 )
{
int V_14 ;
snprintf ( V_4 -> V_15 . V_13 , sizeof( V_4 -> V_15 . V_13 ) ,
L_1 , V_13 ) ;
V_4 -> V_15 . V_16 = V_17 ;
V_4 -> V_15 . V_18 = & V_4 -> V_19 ;
V_4 -> V_15 . V_20 . V_21 = & V_4 -> V_6 -> V_22 -> V_20 ;
V_4 -> V_19 . V_23 = F_4 ;
V_4 -> V_19 . V_24 = F_1 ;
V_4 -> V_19 . V_25 = F_6 ;
V_4 -> V_19 . V_26 = F_5 ;
V_4 -> V_19 . V_27 = 10 ;
V_4 -> V_19 . V_28 = 20 ;
V_4 -> V_19 . V_1 = V_4 ;
F_8 ( & V_4 -> V_15 , V_4 ) ;
F_4 ( V_4 , 1 ) ;
F_1 ( V_4 , 1 ) ;
V_27 ( 20 ) ;
V_14 = F_9 ( & V_4 -> V_15 ) ;
if ( V_14 == 0 )
F_10 ( & V_4 -> V_6 -> V_22 -> V_20 , L_2 , V_13 ) ;
else
F_11 ( & V_4 -> V_6 -> V_22 -> V_20 , L_3 , V_13 ) ;
return V_14 ;
}
void F_12 ( struct V_5 * V_6 )
{
V_6 -> V_29 [ 0 ] . V_6 = V_6 ;
V_6 -> V_29 [ 0 ] . V_8 = V_30 ;
#ifndef F_13
V_6 -> V_29 [ 0 ] . V_15 . V_31 = V_32 ;
#endif
F_7 ( & V_6 -> V_29 [ 0 ] , L_4 ) ;
V_6 -> V_29 [ 1 ] . V_6 = V_6 ;
V_6 -> V_29 [ 1 ] . V_8 = V_33 ;
F_7 ( & V_6 -> V_29 [ 1 ] , L_5 ) ;
V_6 -> V_29 [ 2 ] . V_6 = V_6 ;
V_6 -> V_29 [ 2 ] . V_8 = V_34 ;
F_7 ( & V_6 -> V_29 [ 2 ] , L_6 ) ;
V_6 -> V_29 [ 3 ] . V_6 = V_6 ;
V_6 -> V_29 [ 3 ] . V_8 = V_35 ;
F_7 ( & V_6 -> V_29 [ 3 ] , L_7 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
if ( V_6 -> V_29 [ 0 ] . V_6 )
F_15 ( & V_6 -> V_29 [ 0 ] . V_15 ) ;
V_6 -> V_29 [ 0 ] . V_6 = NULL ;
if ( V_6 -> V_29 [ 1 ] . V_6 )
F_15 ( & V_6 -> V_29 [ 1 ] . V_15 ) ;
V_6 -> V_29 [ 1 ] . V_6 = NULL ;
if ( V_6 -> V_29 [ 2 ] . V_6 )
F_15 ( & V_6 -> V_29 [ 2 ] . V_15 ) ;
V_6 -> V_29 [ 2 ] . V_6 = NULL ;
if ( V_6 -> V_29 [ 3 ] . V_6 )
F_15 ( & V_6 -> V_29 [ 3 ] . V_15 ) ;
V_6 -> V_29 [ 3 ] . V_6 = NULL ;
}
int F_16 ( struct V_5 * V_6 , int V_36 ,
T_2 * * V_37 )
{
T_2 * V_38 ;
V_38 = F_17 ( & V_6 -> V_29 [ V_36 - 1 ] . V_15 ) ;
if ( V_37 )
* V_37 = V_38 ;
if ( ! V_38 ) {
F_18 ( L_8 , V_36 ) ;
return V_39 ;
}
if ( V_38 [ 0x14 ] & 0x80 ) {
if ( V_6 -> V_40 &&
( F_2 ( V_41 ) & V_42 ) ) {
F_18 ( L_9 , V_36 ) ;
return V_43 ;
} else {
F_18 ( L_10 , V_36 ) ;
return V_44 ;
}
}
F_18 ( L_11 , V_36 ) ;
return V_45 ;
}
