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
int V_7 [ 7 ] ;
( void ) F_6 ( V_6 , F_7 ( V_7 ) , V_7 ) ;
if ( V_7 [ 0 ] < 1 || V_7 [ 0 ] > 6 ) {
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
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_10 () ;
F_11 ( V_2 ) ;
F_12 ( V_15 L_2 ) ;
F_13 ( V_16 ,
F_14 ( F_15 ( V_17 ) ) ) ;
F_13 ( V_18 , V_19 | V_20 ) ;
F_16 ( 50 ) ;
F_13 ( V_18 , V_19 ) ;
F_15 ( V_21 ) ;
for( V_14 = V_22 + V_23 ; F_17 ( V_22 , V_14 ) ; )
F_18 () ;
F_12 ( V_15 L_3 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned char * V_24 , int V_25 )
{
struct V_26 * V_27 = F_20 ( V_2 ) ;
unsigned char * V_28 ;
unsigned char * V_29 ;
F_10 () ;
F_11 ( V_2 ) ;
V_29 = V_27 -> V_30 + ( V_31 << 4 ) ;
V_28 = V_24 ;
while ( ! ( F_15 ( V_32 ) & V_33 ) &&
! ( F_15 ( V_17 ) & V_34 ) )
;
if ( ! ( F_15 ( V_32 ) & V_33 ) &&
( F_15 ( V_32 ) & V_35 ) ) {
F_8 ( L_4 ) ;
return - 1 ;
}
F_21 ( V_29 , V_28 , V_25 ) ;
if ( V_25 != 0 ) {
F_22 ( L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned char * V_36 , int V_25 )
{
struct V_26 * V_27 = F_20 ( V_2 ) ;
unsigned char * V_29 ;
unsigned char * V_28 ;
F_10 () ;
F_11 ( V_2 ) ;
V_29 = V_36 ;
V_28 = V_27 -> V_30 + ( V_37 << 4 ) ;
while ( ! ( F_15 ( V_32 ) & V_33 ) &&
( ! ( F_15 ( V_17 ) & V_34 ) ||
( F_15 ( V_32 ) & V_35 ) ) )
;
if ( ! ( F_15 ( V_32 ) & V_33 ) ) {
F_8 ( L_6 ) ;
return - 1 ;
}
F_24 ( V_29 , V_28 , V_25 ) ;
if ( V_25 != 0 ) {
F_22 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
static int T_1 F_25 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int error ;
int V_40 = 0 ;
struct V_41 * V_42 , * V_43 , * V_44 = NULL ;
V_43 = F_26 ( V_39 , V_45 , 0 ) ;
if ( ! V_43 )
return - V_46 ;
#ifdef F_27
V_44 = F_26 ( V_39 , V_45 , 1 ) ;
#endif
V_42 = F_26 ( V_39 , V_47 , 0 ) ;
if ( ! F_28 ( ( unsigned char * ) V_43 -> V_48 +
( V_17 << 4 ) ) ) {
F_29 ( V_49 L_8 , & V_43 -> V_48 ) ;
return - V_46 ;
}
if ( V_8 > 0 )
V_50 . V_51 = V_8 ;
if ( V_9 > 0 )
V_50 . V_52 = V_9 ;
if ( V_10 >= 0 )
V_50 . V_53 = V_10 ;
if ( V_11 >= 0 )
V_50 . V_54 = V_11 & 7 ;
if ( V_13 < 0 )
V_13 = 0 ;
V_2 = F_30 ( & V_50 ,
sizeof( struct V_26 ) ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_4 = V_43 -> V_48 ;
if ( V_42 )
V_2 -> V_42 = V_42 -> V_48 ;
else
V_2 -> V_42 = V_56 ;
if ( V_44 && V_13 ) {
struct V_26 * V_27 = F_20 ( V_2 ) ;
V_27 -> V_30 = ( unsigned char * ) V_44 -> V_48 ;
} else
V_40 |= V_57 ;
#ifdef F_31
F_9 ( V_2 ) ;
#endif
#ifdef F_32
V_40 |= V_12 > 0 ? V_58 : 0 ;
#endif
F_33 ( V_2 , V_40 ) ;
if ( V_2 -> V_42 != V_56 ) {
error = F_34 ( V_2 -> V_42 , V_59 , V_60 ,
L_9 , V_2 ) ;
if ( error )
goto V_61;
}
error = F_35 ( V_2 , NULL ) ;
if ( error )
goto V_62;
F_36 ( V_39 , V_2 ) ;
F_37 ( V_2 ) ;
return 0 ;
V_62:
if ( V_2 -> V_42 != V_56 )
F_38 ( V_2 -> V_42 , V_2 ) ;
V_61:
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
return error ;
}
static int T_2 F_41 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_42 ( V_39 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_42 != V_56 )
F_38 ( V_2 -> V_42 , V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
