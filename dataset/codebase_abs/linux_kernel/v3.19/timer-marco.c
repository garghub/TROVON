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
F_1 ( V_8 ) ;
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
int V_8 = F_6 () ;
struct V_30 * V_31 ;
if ( V_8 == 0 )
V_31 = & V_32 ;
else
V_31 = & V_33 ;
V_7 -> V_4 = V_31 -> V_4 ;
V_7 -> V_34 = L_1 ;
V_7 -> V_35 = V_36 ;
V_7 -> V_37 = 200 ;
V_7 -> V_38 = F_10 ;
V_7 -> V_39 = F_9 ;
F_14 ( V_7 , V_40 , 60 ) ;
V_7 -> V_41 = F_15 ( - 2 , V_7 ) ;
V_7 -> V_42 = F_15 ( 2 , V_7 ) ;
V_7 -> V_43 = F_16 ( V_8 ) ;
V_31 -> V_5 = V_7 ;
F_17 ( F_18 ( V_7 -> V_4 , V_31 ) ) ;
F_19 ( V_31 -> V_4 , F_16 ( V_8 ) ) ;
F_20 ( V_7 ) ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
int V_8 = F_6 () ;
F_1 ( 1 ) ;
if ( V_8 == 0 )
F_22 ( V_32 . V_4 , & V_32 ) ;
else
F_22 ( V_33 . V_4 , & V_33 ) ;
}
static int F_23 ( struct V_44 * V_45 ,
unsigned long V_31 , void * V_46 )
{
switch ( V_31 & ~ V_47 ) {
case V_48 :
F_13 ( F_24 ( V_49 ) ) ;
break;
case V_50 :
F_21 ( F_24 ( V_49 ) ) ;
break;
}
return V_51 ;
}
static void T_4 F_25 ( void )
{
V_49 = F_26 ( struct V_6 ) ;
F_17 ( ! V_49 ) ;
F_17 ( F_27 ( & V_52 ) ) ;
F_13 ( F_24 ( V_49 ) ) ;
}
static void T_4 F_28 ( struct V_53 * V_54 )
{
T_5 V_55 ;
struct V_56 * V_56 ;
V_56 = F_29 ( V_54 , 0 ) ;
F_17 ( F_30 ( V_56 ) ) ;
F_17 ( F_31 ( V_56 ) ) ;
V_40 = F_32 ( V_56 ) ;
F_2 ( 0 , V_2 + V_17 ) ;
F_2 ( 0 , V_2 + V_3 ) ;
F_2 ( 0 , V_2 + V_57 ) ;
F_2 ( 0 , V_2 + V_28 ) ;
F_2 ( 0 , V_2 + V_29 ) ;
F_2 ( F_3 ( V_2 + V_17 ) |
F_7 ( 1 ) | F_7 ( 0 ) , V_2 + V_17 ) ;
F_2 ( 0 , V_2 + V_21 ) ;
F_2 ( 0 , V_2 + V_58 ) ;
F_2 ( 0xFFFF , V_2 + V_9 ) ;
F_17 ( F_33 ( & V_59 , V_40 ) ) ;
F_25 () ;
}
static void T_4 F_34 ( struct V_53 * V_54 )
{
V_2 = F_35 ( V_54 , 0 ) ;
if ( ! V_2 )
F_36 ( L_2 ) ;
V_32 . V_4 = F_37 ( V_54 , 0 ) ;
if ( ! V_32 . V_4 )
F_36 ( L_3 ) ;
V_33 . V_4 = F_37 ( V_54 , 1 ) ;
if ( ! V_33 . V_4 )
F_36 ( L_4 ) ;
F_28 ( V_54 ) ;
}
