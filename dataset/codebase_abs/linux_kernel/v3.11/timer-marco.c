static inline void F_1 ( int V_1 )
{
F_2 ( F_3 ( V_2 + V_3 + 4 * V_1 ) & ~ 0x7 ,
V_2 + V_3 + 4 * V_1 ) ;
}
static inline void F_4 ( int V_1 )
{
F_2 ( F_3 ( V_2 + V_3 + 4 * V_1 ) | 0x7 ,
V_2 + V_3 + 4 * V_1 ) ;
}
static T_1 F_5 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
int V_8 = F_6 () ;
F_2 ( F_7 ( V_8 ) , V_2 + V_9 ) ;
if ( V_7 -> V_10 == V_11 )
F_1 ( V_8 ) ;
V_7 -> V_12 ( V_7 ) ;
return V_13 ;
}
static T_2 F_8 ( struct V_14 * V_15 )
{
T_3 V_16 ;
F_2 ( ( F_3 ( V_2 + V_17 ) |
F_7 ( 0 ) ) & ~ F_7 ( 1 ) , V_2 + V_17 ) ;
V_16 = F_3 ( V_2 + V_18 ) ;
V_16 = ( V_16 << 32 ) | F_3 ( V_2 + V_19 ) ;
return V_16 ;
}
static int F_9 ( unsigned long V_20 ,
struct V_6 * V_7 )
{
int V_8 = F_6 () ;
F_2 ( 0 , V_2 + V_21 +
4 * V_8 ) ;
F_2 ( V_20 , V_2 + V_22 +
4 * V_8 ) ;
F_4 ( V_8 ) ;
return 0 ;
}
static void F_10 ( enum V_23 V_10 ,
struct V_6 * V_7 )
{
switch ( V_10 ) {
case V_11 :
break;
default:
break;
}
F_1 ( F_6 () ) ;
}
static void F_11 ( struct V_14 * V_15 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
V_26 [ V_24 ] = F_3 ( V_2 + V_27 [ V_24 ] ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 - 2 ; V_24 ++ )
F_2 ( V_26 [ V_24 ] , V_2 + V_27 [ V_24 ] ) ;
F_2 ( V_26 [ V_25 - 2 ] ,
V_2 + V_28 ) ;
F_2 ( V_26 [ V_25 - 1 ] ,
V_2 + V_29 ) ;
F_2 ( F_3 ( V_2 + V_17 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_17 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
if ( ! F_6 () )
return 0 ;
V_7 -> V_4 = V_30 . V_4 ;
V_7 -> V_31 = L_1 ;
V_7 -> V_32 = V_33 . V_32 ;
V_7 -> V_34 = V_33 . V_34 ;
V_7 -> V_35 = F_10 ;
V_7 -> V_36 = F_9 ;
V_7 -> V_37 = V_33 . V_37 ;
V_7 -> V_38 = V_33 . V_38 ;
V_7 -> V_39 = V_33 . V_39 ;
V_7 -> V_40 = V_33 . V_40 ;
V_30 . V_5 = V_7 ;
F_14 ( F_15 ( V_7 -> V_4 , & V_30 ) ) ;
F_16 ( V_30 . V_4 , F_17 ( 1 ) ) ;
F_18 ( V_7 ) ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
F_1 ( 1 ) ;
F_20 ( V_30 . V_4 , & V_30 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_33 , V_41 , 60 ) ;
V_33 . V_39 =
F_23 ( - 2 , & V_33 ) ;
V_33 . V_40 =
F_23 ( 2 , & V_33 ) ;
V_33 . V_42 = F_17 ( 0 ) ;
F_18 ( & V_33 ) ;
#ifdef F_24
F_25 ( & V_43 ) ;
#endif
}
static void T_4 F_26 ( void )
{
unsigned long V_44 ;
T_5 V_45 ;
struct V_46 * V_46 ;
V_46 = F_27 ( L_2 , NULL ) ;
F_14 ( F_28 ( V_46 ) ) ;
V_44 = F_29 ( V_46 ) ;
F_14 ( V_44 < V_41 ) ;
F_14 ( V_44 % V_41 ) ;
V_45 = V_44 / V_41 - 1 ;
F_2 ( V_45 << 16 , V_2 + V_17 ) ;
F_2 ( V_45 << 16 , V_2 + V_3 ) ;
F_2 ( V_45 << 16 , V_2 + V_47 ) ;
F_2 ( 0 , V_2 + V_28 ) ;
F_2 ( 0 , V_2 + V_29 ) ;
F_2 ( F_3 ( V_2 + V_17 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_17 ) ;
F_2 ( 0 , V_2 + V_21 ) ;
F_2 ( 0 , V_2 + V_48 ) ;
F_2 ( 0xFFFF , V_2 + V_9 ) ;
F_14 ( F_30 ( & V_49 , V_41 ) ) ;
F_14 ( F_15 ( V_50 . V_4 , & V_50 ) ) ;
F_21 () ;
}
static void T_4 F_31 ( struct V_51 * V_52 )
{
V_2 = F_32 ( V_52 , 0 ) ;
if ( ! V_2 )
F_33 ( L_3 ) ;
V_50 . V_4 = F_34 ( V_52 , 0 ) ;
if ( ! V_50 . V_4 )
F_33 ( L_4 ) ;
#ifdef F_24
V_30 . V_4 = F_34 ( V_52 , 1 ) ;
if ( ! V_30 . V_4 )
F_33 ( L_5 ) ;
#endif
F_26 () ;
}
