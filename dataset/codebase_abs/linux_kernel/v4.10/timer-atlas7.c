static inline void F_1 ( int V_1 )
{
F_2 ( F_3 ( V_2 + V_3 + 4 * V_1 ) & ~ 0x7 ,
V_2 + V_3 + 4 * V_1 ) ;
}
static inline void F_4 ( int V_1 )
{
F_2 ( F_3 ( V_2 + V_3 + 4 * V_1 ) | 0x3 ,
V_2 + V_3 + 4 * V_1 ) ;
}
static T_1 F_5 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
int V_8 = F_6 () ;
F_2 ( F_7 ( V_8 ) , V_2 + V_9 ) ;
if ( F_8 ( V_7 ) )
F_1 ( V_8 ) ;
V_7 -> V_10 ( V_7 ) ;
return V_11 ;
}
static T_2 F_9 ( struct V_12 * V_13 )
{
T_2 V_14 ;
F_2 ( ( F_3 ( V_2 + V_15 ) |
F_7 ( 0 ) ) & ~ F_7 ( 1 ) , V_2 + V_15 ) ;
V_14 = F_3 ( V_2 + V_16 ) ;
V_14 = ( V_14 << 32 ) | F_3 ( V_2 + V_17 ) ;
return V_14 ;
}
static int F_10 ( unsigned long V_18 ,
struct V_6 * V_7 )
{
int V_8 = F_6 () ;
F_1 ( V_8 ) ;
F_2 ( 0 , V_2 + V_19 +
4 * V_8 ) ;
F_2 ( V_18 , V_2 + V_20 +
4 * V_8 ) ;
F_4 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_21 )
{
F_1 ( F_6 () ) ;
return 0 ;
}
static void F_12 ( struct V_12 * V_13 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
V_24 [ V_22 ] = F_3 ( V_2 + V_25 [ V_22 ] ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 - 2 ; V_22 ++ )
F_2 ( V_24 [ V_22 ] , V_2 + V_25 [ V_22 ] ) ;
F_2 ( V_24 [ V_23 - 2 ] ,
V_2 + V_26 ) ;
F_2 ( V_24 [ V_23 - 1 ] ,
V_2 + V_27 ) ;
F_2 ( F_3 ( V_2 + V_15 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_15 ) ;
}
static int F_14 ( unsigned int V_8 )
{
struct V_6 * V_7 = F_15 ( V_28 , V_8 ) ;
struct V_29 * V_30 ;
if ( V_8 == 0 )
V_30 = & V_31 ;
else
V_30 = & V_32 ;
V_7 -> V_4 = V_30 -> V_4 ;
V_7 -> V_33 = L_1 ;
V_7 -> V_34 = V_35 ;
V_7 -> V_36 = 200 ;
V_7 -> V_37 = F_11 ;
V_7 -> V_38 = F_11 ;
V_7 -> V_39 = F_11 ;
V_7 -> V_40 = F_10 ;
F_16 ( V_7 , V_41 , 60 ) ;
V_7 -> V_42 = F_17 ( - 2 , V_7 ) ;
V_7 -> V_43 = F_17 ( 2 , V_7 ) ;
V_7 -> V_44 = F_18 ( V_8 ) ;
V_30 -> V_5 = V_7 ;
F_19 ( F_20 ( V_7 -> V_4 , V_30 ) ) ;
F_21 ( V_30 -> V_4 , F_18 ( V_8 ) ) ;
F_22 ( V_7 ) ;
return 0 ;
}
static int F_23 ( unsigned int V_8 )
{
F_1 ( 1 ) ;
if ( V_8 == 0 )
F_24 ( V_31 . V_4 , & V_31 ) ;
else
F_24 ( V_32 . V_4 , & V_32 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
V_28 = F_26 ( struct V_6 ) ;
F_19 ( ! V_28 ) ;
return F_27 ( V_45 ,
L_2 ,
F_14 ,
F_23 ) ;
}
static int T_3 F_28 ( struct V_46 * V_47 )
{
struct V_48 * V_48 ;
V_48 = F_29 ( V_47 , 0 ) ;
F_19 ( F_30 ( V_48 ) ) ;
F_19 ( F_31 ( V_48 ) ) ;
V_41 = F_32 ( V_48 ) ;
F_2 ( 0 , V_2 + V_15 ) ;
F_2 ( 0 , V_2 + V_3 ) ;
F_2 ( 0 , V_2 + V_49 ) ;
F_2 ( 0 , V_2 + V_26 ) ;
F_2 ( 0 , V_2 + V_27 ) ;
F_2 ( F_3 ( V_2 + V_15 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_15 ) ;
F_2 ( 0 , V_2 + V_19 ) ;
F_2 ( 0 , V_2 + V_50 ) ;
F_2 ( 0xFFFF , V_2 + V_9 ) ;
F_19 ( F_33 ( & V_51 , V_41 ) ) ;
return F_25 () ;
}
static int T_3 F_34 ( struct V_46 * V_47 )
{
V_2 = F_35 ( V_47 , 0 ) ;
if ( ! V_2 ) {
F_36 ( L_3 ) ;
return - V_52 ;
}
V_31 . V_4 = F_37 ( V_47 , 0 ) ;
if ( ! V_31 . V_4 ) {
F_36 ( L_4 ) ;
return - V_53 ;
}
V_32 . V_4 = F_37 ( V_47 , 1 ) ;
if ( ! V_32 . V_4 ) {
F_36 ( L_5 ) ;
return - V_53 ;
}
return F_28 ( V_47 ) ;
}
