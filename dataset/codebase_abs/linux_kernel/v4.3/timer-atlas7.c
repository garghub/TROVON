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
T_3 V_14 ;
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
static int F_14 ( struct V_6 * V_7 )
{
int V_8 = F_6 () ;
struct V_28 * V_29 ;
if ( V_8 == 0 )
V_29 = & V_30 ;
else
V_29 = & V_31 ;
V_7 -> V_4 = V_29 -> V_4 ;
V_7 -> V_32 = L_1 ;
V_7 -> V_33 = V_34 ;
V_7 -> V_35 = 200 ;
V_7 -> V_36 = F_11 ;
V_7 -> V_37 = F_11 ;
V_7 -> V_38 = F_11 ;
V_7 -> V_39 = F_10 ;
F_15 ( V_7 , V_40 , 60 ) ;
V_7 -> V_41 = F_16 ( - 2 , V_7 ) ;
V_7 -> V_42 = F_16 ( 2 , V_7 ) ;
V_7 -> V_43 = F_17 ( V_8 ) ;
V_29 -> V_5 = V_7 ;
F_18 ( F_19 ( V_7 -> V_4 , V_29 ) ) ;
F_20 ( V_29 -> V_4 , F_17 ( V_8 ) ) ;
F_21 ( V_7 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
int V_8 = F_6 () ;
F_1 ( 1 ) ;
if ( V_8 == 0 )
F_23 ( V_30 . V_4 , & V_30 ) ;
else
F_23 ( V_31 . V_4 , & V_31 ) ;
}
static int F_24 ( struct V_44 * V_45 ,
unsigned long V_29 , void * V_46 )
{
switch ( V_29 & ~ V_47 ) {
case V_48 :
F_14 ( F_25 ( V_49 ) ) ;
break;
case V_50 :
F_22 ( F_25 ( V_49 ) ) ;
break;
}
return V_51 ;
}
static void T_4 F_26 ( void )
{
V_49 = F_27 ( struct V_6 ) ;
F_18 ( ! V_49 ) ;
F_18 ( F_28 ( & V_52 ) ) ;
F_14 ( F_25 ( V_49 ) ) ;
}
static void T_4 F_29 ( struct V_53 * V_54 )
{
struct V_55 * V_55 ;
V_55 = F_30 ( V_54 , 0 ) ;
F_18 ( F_31 ( V_55 ) ) ;
F_18 ( F_32 ( V_55 ) ) ;
V_40 = F_33 ( V_55 ) ;
F_2 ( 0 , V_2 + V_15 ) ;
F_2 ( 0 , V_2 + V_3 ) ;
F_2 ( 0 , V_2 + V_56 ) ;
F_2 ( 0 , V_2 + V_26 ) ;
F_2 ( 0 , V_2 + V_27 ) ;
F_2 ( F_3 ( V_2 + V_15 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_15 ) ;
F_2 ( 0 , V_2 + V_19 ) ;
F_2 ( 0 , V_2 + V_57 ) ;
F_2 ( 0xFFFF , V_2 + V_9 ) ;
F_18 ( F_34 ( & V_58 , V_40 ) ) ;
F_26 () ;
}
static void T_4 F_35 ( struct V_53 * V_54 )
{
V_2 = F_36 ( V_54 , 0 ) ;
if ( ! V_2 )
F_37 ( L_2 ) ;
V_30 . V_4 = F_38 ( V_54 , 0 ) ;
if ( ! V_30 . V_4 )
F_37 ( L_3 ) ;
V_31 . V_4 = F_38 ( V_54 , 1 ) ;
if ( ! V_31 . V_4 )
F_37 ( L_4 ) ;
F_29 ( V_54 ) ;
}
