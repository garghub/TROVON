static inline char F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_5 )
{
F_4 ( V_2 -> V_4 + ( V_3 << 4 ) , V_5 ) ;
}
static int T_1 F_5 ( char * V_6 )
{
int V_7 [ 8 ] ;
( void ) F_6 ( V_6 , F_7 ( V_7 ) , V_7 ) ;
if ( V_7 [ 0 ] < 1 ) {
F_8 ( L_1 ) ;
return 0 ;
}
if ( V_7 [ 0 ] >= 1 )
V_8 = V_7 [ 1 ] ;
if ( V_7 [ 0 ] >= 2 )
V_9 = V_7 [ 2 ] ;
if ( V_7 [ 0 ] >= 3 )
V_10 = V_7 [ 3 ] ;
if ( V_7 [ 0 ] >= 4 )
V_11 = V_7 [ 4 ] ;
if ( V_7 [ 0 ] >= 5 )
V_12 = V_7 [ 5 ] ;
if ( V_7 [ 0 ] >= 6 )
V_13 = V_7 [ 6 ] ;
if ( V_7 [ 0 ] >= 7 )
V_14 = V_7 [ 7 ] ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char * V_15 , int V_16 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
unsigned char * V_19 ;
unsigned char * V_20 ;
V_20 = V_18 -> V_21 + ( V_22 << 4 ) ;
V_19 = V_15 ;
while ( ! ( F_11 ( V_23 ) & V_24 ) &&
! ( F_11 ( V_25 ) & V_26 ) )
;
if ( ! ( F_11 ( V_23 ) & V_24 ) &&
( F_11 ( V_23 ) & V_27 ) ) {
F_8 ( L_2 ) ;
return - 1 ;
}
F_12 ( V_20 , V_19 , V_16 ) ;
if ( V_16 != 0 ) {
F_13 ( L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned char * V_28 , int V_16 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
unsigned char * V_20 ;
unsigned char * V_19 ;
V_20 = V_28 ;
V_19 = V_18 -> V_21 + ( V_29 << 4 ) ;
while ( ! ( F_11 ( V_23 ) & V_24 ) &&
( ! ( F_11 ( V_25 ) & V_26 ) ||
( F_11 ( V_23 ) & V_27 ) ) )
;
if ( ! ( F_11 ( V_23 ) & V_24 ) ) {
F_8 ( L_4 ) ;
return - 1 ;
}
F_15 ( V_20 , V_19 , V_16 ) ;
if ( V_16 != 0 ) {
F_13 ( L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_16 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
int error ;
int V_32 = 0 ;
struct V_33 * V_34 , * V_35 , * V_36 = NULL ;
V_35 = F_17 ( V_31 , V_37 , 0 ) ;
if ( ! V_35 )
return - V_38 ;
#ifdef F_18
V_36 = F_17 ( V_31 , V_37 , 1 ) ;
#endif
V_34 = F_17 ( V_31 , V_39 , 0 ) ;
if ( ! F_19 ( ( unsigned char * ) V_35 -> V_40 +
( V_25 << 4 ) ) ) {
F_20 ( V_41 L_6 , & V_35 -> V_40 ) ;
return - V_38 ;
}
if ( V_8 > 0 )
V_42 . V_43 = V_8 ;
if ( V_9 > 0 )
V_42 . V_44 = V_9 ;
if ( V_10 >= 0 )
V_42 . V_45 = V_10 ;
if ( V_11 >= 0 )
V_42 . V_46 = V_11 & 7 ;
if ( V_13 < 0 )
V_13 = 0 ;
V_2 = F_21 ( & V_42 ,
sizeof( struct V_17 ) ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_4 = V_35 -> V_40 ;
if ( V_34 )
V_2 -> V_34 = V_34 -> V_40 ;
else
V_2 -> V_34 = V_48 ;
if ( V_36 && V_13 ) {
struct V_17 * V_18 = F_10 ( V_2 ) ;
V_18 -> V_21 = ( unsigned char * ) V_36 -> V_40 ;
} else
V_32 |= V_49 ;
#ifdef F_22
V_32 |= V_12 > 0 ? V_50 : 0 ;
#endif
V_32 |= V_14 > 0 ? V_51 : 0 ;
error = F_23 ( V_2 , V_32 ) ;
if ( error )
goto V_52;
if ( V_2 -> V_34 != V_48 ) {
error = F_24 ( V_2 -> V_34 , V_53 , V_54 ,
L_7 , V_2 ) ;
if ( error )
goto V_55;
}
F_25 ( V_2 ) ;
error = F_26 ( V_2 , NULL ) ;
if ( error )
goto V_56;
F_27 ( V_31 , V_2 ) ;
F_28 ( V_2 ) ;
return 0 ;
V_56:
if ( V_2 -> V_34 != V_48 )
F_29 ( V_2 -> V_34 , V_2 ) ;
V_55:
F_30 ( V_2 ) ;
V_52:
F_31 ( V_2 ) ;
return error ;
}
static int T_2 F_32 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_33 ( V_31 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_34 != V_48 )
F_29 ( V_2 -> V_34 , V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
