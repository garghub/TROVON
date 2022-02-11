static inline unsigned long F_1 ( unsigned V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_3 , unsigned V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static unsigned long F_5 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
unsigned long V_7 = V_6 ;
struct V_8 * V_9 = F_6 ( V_5 ) ;
T_1 V_10 = V_9 -> V_11 + V_12 -
V_13 ;
if ( F_1 ( V_10 ) & F_7 ( 2 ) ) {
return V_7 ;
} else {
T_1 V_14 = F_1 ( V_9 -> V_11 ) ;
T_1 V_15 = ( V_14 & ( F_7 ( 13 ) - 1 ) ) + 1 ;
T_1 V_16 = ( ( V_14 >> 13 ) & ( F_7 ( 6 ) - 1 ) ) + 1 ;
T_1 V_17 = ( ( V_14 >> 19 ) & ( F_7 ( 4 ) - 1 ) ) + 1 ;
F_8 ( V_7 % V_18 ) ;
return V_7 / V_18 * V_15 / V_16 / V_17 * V_18 ;
}
}
static long F_9 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long * V_6 )
{
unsigned long V_7 , V_15 , V_16 , V_17 ;
V_19 = V_19 - V_19 % V_18 ;
V_15 = V_19 / V_18 ;
if ( V_15 > F_7 ( 13 ) )
V_15 = F_7 ( 13 ) ;
if ( V_15 < 1 )
V_15 = 1 ;
V_7 = * V_6 ;
V_16 = V_7 / V_18 ;
if ( V_16 > F_7 ( 6 ) )
V_16 = F_7 ( 6 ) ;
V_17 = 1 ;
return V_7 * V_15 / ( V_16 * V_17 ) ;
}
static int F_10 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long V_6 )
{
struct V_8 * V_9 = F_6 ( V_5 ) ;
unsigned long V_7 , V_15 , V_16 , V_17 , V_1 ;
V_15 = V_19 / V_18 ;
if ( F_11 ( ( V_19 % V_18 ) || V_15 > F_7 ( 13 ) || V_15 < 1 ) )
return - V_20 ;
V_7 = V_6 ;
F_12 ( V_7 < V_18 ) ;
V_16 = V_7 / V_18 ;
F_12 ( ( V_7 % V_18 ) || V_16 > F_7 ( 6 ) ) ;
V_17 = 1 ;
V_1 = ( V_15 - 1 ) | ( ( V_16 - 1 ) << 13 ) | ( ( V_17 - 1 ) << 19 ) ;
F_3 ( V_1 , V_9 -> V_11 ) ;
V_1 = V_9 -> V_11 + V_21 - V_13 ;
F_3 ( ( V_15 >> 1 ) - 1 , V_1 ) ;
V_1 = V_9 -> V_11 + V_12 - V_13 ;
while ( ! ( F_1 ( V_1 ) & F_7 ( 6 ) ) )
F_13 () ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
T_1 V_1 = F_2 ( V_22 + V_23 ) ;
V_1 &= ~ ( V_24 | V_25 ) ;
F_4 ( V_1 , V_22 + V_23 ) ;
while ( ! ( F_2 ( V_22 + V_23 ) &
V_26 ) )
F_13 () ;
return 0 ;
}
static void F_15 ( struct V_4 * V_9 )
{
T_1 V_1 = F_2 ( V_22 + V_23 ) ;
V_1 |= ( V_24 | V_25 ) ;
F_4 ( V_1 , V_22 + V_23 ) ;
}
static unsigned long F_16 ( struct V_4 * V_5 , unsigned long V_6 )
{
T_1 V_1 = F_2 ( V_22 + V_23 ) ;
return ( V_1 & V_25 ) ? V_6 : 48 * V_18 ;
}
static T_2 F_17 ( struct V_4 * V_5 )
{
struct V_27 * V_9 = F_18 ( V_5 ) ;
T_1 V_28 = F_1 ( V_9 -> V_11 ) ;
if ( strcmp ( V_5 -> V_29 -> V_30 , L_1 ) == 0 )
return 4 ;
F_8 ( ( V_28 & ( F_7 ( 3 ) - 1 ) ) > 4 ) ;
return V_28 & ( F_7 ( 3 ) - 1 ) ;
}
static int F_19 ( struct V_4 * V_5 , T_2 V_31 )
{
struct V_27 * V_9 = F_18 ( V_5 ) ;
T_1 V_28 = F_1 ( V_9 -> V_11 ) ;
if ( strcmp ( V_5 -> V_29 -> V_30 , L_1 ) == 0 )
return - V_20 ;
V_28 &= ~ ( F_7 ( 3 ) - 1 ) ;
F_3 ( V_28 | V_31 , V_9 -> V_11 ) ;
while ( F_1 ( V_9 -> V_11 ) & F_7 ( 3 ) )
F_13 () ;
return 0 ;
}
static unsigned long F_20 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
unsigned long V_7 = V_6 ;
struct V_27 * V_9 = F_18 ( V_5 ) ;
T_1 V_28 = F_1 ( V_9 -> V_11 ) ;
if ( V_28 & F_7 ( 24 ) ) {
return V_7 ;
} else {
T_1 V_32 = ( V_28 >> 16 ) & ( F_7 ( 4 ) - 1 ) ;
T_1 V_33 = ( V_28 >> 20 ) & ( F_7 ( 4 ) - 1 ) ;
return V_7 / ( V_32 + V_33 + 2 ) ;
}
}
static long F_21 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long * V_6 )
{
unsigned long V_7 ;
unsigned V_34 , V_32 , V_33 ;
unsigned V_35 = ( strcmp ( V_5 -> V_29 -> V_30 , L_2 ) == 0 ) ? 3 : 4 ;
V_7 = * V_6 ;
V_34 = V_7 / V_19 ;
if ( V_34 < 2 )
V_34 = 2 ;
if ( V_34 > F_7 ( V_35 + 1 ) )
V_34 = F_7 ( V_35 + 1 ) ;
V_32 = ( V_34 >> 1 ) - 1 ;
V_33 = V_34 - V_32 - 2 ;
return V_7 / ( V_32 + V_33 + 2 ) ;
}
static int F_22 ( struct V_4 * V_5 , unsigned long V_19 ,
unsigned long V_6 )
{
struct V_27 * V_9 = F_18 ( V_5 ) ;
unsigned long V_7 ;
unsigned V_34 , V_32 , V_33 , V_1 ;
unsigned V_35 = ( strcmp ( V_5 -> V_29 -> V_30 , L_2 ) == 0 ) ? 3 : 4 ;
V_7 = V_6 ;
V_34 = V_7 / V_19 ;
if ( F_11 ( V_34 < 2 || V_34 > F_7 ( V_35 + 1 ) ) )
return - V_20 ;
F_8 ( V_7 % V_19 ) ;
V_32 = ( V_34 >> 1 ) - 1 ;
V_33 = V_34 - V_32 - 2 ;
V_1 = F_1 ( V_9 -> V_11 ) ;
V_1 &= ~ ( ( ( F_7 ( V_35 ) - 1 ) << 16 ) | ( ( F_7 ( V_35 ) - 1 ) << 20 ) ) ;
V_1 |= ( V_32 << 16 ) | ( V_33 << 20 ) | F_7 ( 25 ) ;
F_3 ( V_1 , V_9 -> V_11 ) ;
while ( F_1 ( V_9 -> V_11 ) & F_7 ( 25 ) )
F_13 () ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
T_1 V_1 ;
int V_36 ;
struct V_37 * V_9 = F_24 ( V_5 ) ;
V_36 = V_9 -> V_38 % 32 ;
V_1 = V_9 -> V_38 / 32 ;
V_1 = V_39 + V_1 * sizeof( V_1 ) ;
return ! ! ( F_1 ( V_1 ) & F_7 ( V_36 ) ) ;
}
static int F_25 ( struct V_4 * V_5 )
{
T_1 V_3 , V_1 ;
int V_36 ;
struct V_37 * V_9 = F_24 ( V_5 ) ;
F_12 ( V_9 -> V_38 < 0 || V_9 -> V_38 > 63 ) ;
V_36 = V_9 -> V_38 % 32 ;
V_1 = V_9 -> V_38 / 32 ;
V_1 = V_39 + V_1 * sizeof( V_1 ) ;
V_3 = F_1 ( V_1 ) | F_7 ( V_36 ) ;
F_3 ( V_3 , V_1 ) ;
return 0 ;
}
static void F_26 ( struct V_4 * V_5 )
{
T_1 V_3 , V_1 ;
int V_36 ;
struct V_37 * V_9 = F_24 ( V_5 ) ;
F_12 ( V_9 -> V_38 < 0 || V_9 -> V_38 > 63 ) ;
V_36 = V_9 -> V_38 % 32 ;
V_1 = V_9 -> V_38 / 32 ;
V_1 = V_39 + V_1 * sizeof( V_1 ) ;
V_3 = F_1 ( V_1 ) & ~ F_7 ( V_36 ) ;
F_3 ( V_3 , V_1 ) ;
}
void T_3 F_27 ( void )
{
struct V_40 * V_41 ;
int V_42 ;
V_41 = F_28 ( NULL , V_43 ) ;
if ( ! V_41 )
F_29 ( L_3 ) ;
V_22 = F_30 ( V_41 , 0 ) ;
if ( ! V_22 )
F_29 ( L_4 ) ;
F_31 ( V_41 ) ;
V_41 = F_28 ( NULL , V_44 ) ;
if ( ! V_41 )
return;
V_2 = F_30 ( V_41 , 0 ) ;
if ( ! V_2 )
F_29 ( L_5 ) ;
V_45 [ V_46 ] = F_32 ( NULL , L_6 , NULL ,
V_47 , 32768 ) ;
V_45 [ V_48 ] = F_32 ( NULL , L_7 , NULL ,
V_47 , 26000000 ) ;
for ( V_42 = V_49 ; V_42 < V_50 ; V_42 ++ ) {
V_45 [ V_42 ] = F_33 ( NULL , V_51 [ V_42 ] ) ;
F_12 ( F_34 ( V_45 [ V_42 ] ) ) ;
}
F_35 ( V_45 [ V_52 ] , NULL , L_8 ) ;
F_35 ( V_45 [ V_53 ] , NULL , L_1 ) ;
F_35 ( V_45 [ V_54 ] , NULL , L_2 ) ;
V_55 . V_56 = V_45 ;
V_55 . V_57 = V_50 ;
F_36 ( V_41 , V_58 , & V_55 ) ;
}
