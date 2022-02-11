long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = F_2 ( V_4 | V_5 | V_6 | V_7 ,
V_8 - V_9 ) ;
if ( ! V_2 ) {
F_3 ( L_1 ) ;
return - V_10 ;
}
V_1 -> V_11 . V_12 = V_2 ;
do {
V_3 = F_4 ( V_13 , V_14 ) ;
if ( V_3 >= V_14 ) {
F_3 ( L_2 ) ;
F_5 ( V_2 , V_8 - V_9 ) ;
return - V_10 ;
}
} while ( F_6 ( V_3 , V_13 ) );
V_1 -> V_11 . V_15 = F_7 ( V_2 ) | ( V_8 - 18 ) ;
V_1 -> V_11 . V_3 = V_3 ;
F_8 ( L_3 , V_2 , V_3 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_10 ( V_1 -> V_11 . V_3 , V_13 ) ;
F_5 ( V_1 -> V_11 . V_12 , V_8 - V_9 ) ;
}
void F_11 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
unsigned long V_18 ;
unsigned long V_19 = V_1 -> V_11 . V_20 ;
unsigned long V_21 ;
unsigned long * V_22 ;
unsigned long V_23 ;
struct V_24 * V_25 = V_1 -> V_11 . V_26 ;
if ( ! V_25 )
return;
if ( V_19 > 1ul << ( 40 - V_1 -> V_11 . V_27 ) )
V_19 = 1ul << ( 40 - V_1 -> V_11 . V_27 ) ;
if ( V_19 > V_28 )
V_19 = V_28 ;
for ( V_18 = 0 ; V_18 < V_19 ; ++ V_18 ) {
V_21 = V_25 [ V_18 ] . V_21 ;
if ( ! V_21 )
break;
V_23 = ( V_18 ^ ( V_29 ^ ( V_29 << 25 ) ) ) & V_30 ;
V_22 = ( unsigned long * ) ( V_1 -> V_11 . V_12 + ( V_23 << 7 ) ) ;
V_22 += 7 * 2 ;
V_22 [ 1 ] = ( V_21 << V_9 ) | V_31 | V_32 |
V_33 | V_34 ;
F_12 () ;
V_22 [ 0 ] = V_35 | ( V_29 << ( 40 - 16 ) ) |
( V_18 << ( V_36 - 16 ) ) | V_37 |
V_38 | V_39 ;
}
}
int F_13 ( void )
{
unsigned long V_40 , V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
if ( F_14 ( V_44 ) ) {
V_40 = F_15 ( V_45 ) ;
V_41 = V_46 ;
} else {
V_40 = 0 ;
V_41 = V_47 ;
}
F_16 ( V_40 , V_13 ) ;
F_16 ( V_41 , V_13 ) ;
return 0 ;
}
void F_17 ( struct V_48 * V_49 )
{
}
static void F_18 ( struct V_48 * V_49 )
{
F_19 ( V_49 , V_50 | V_51 ) ;
}
static int F_20 ( struct V_48 * V_49 , T_1 V_52 ,
struct V_53 * V_54 , bool V_55 )
{
return - V_56 ;
}
void F_21 ( struct V_48 * V_49 )
{
struct V_57 * V_58 = & V_49 -> V_11 . V_58 ;
if ( F_14 ( V_44 ) )
V_49 -> V_11 . V_59 = 32 ;
else
V_49 -> V_11 . V_59 = 64 ;
V_58 -> V_60 = F_20 ;
V_58 -> V_61 = F_18 ;
V_49 -> V_11 . V_62 |= V_63 ;
}
