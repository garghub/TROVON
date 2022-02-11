void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
F_2 ( F_3 ( V_1 ) , F_4 ( 0 ) ,
V_2 ^ ( V_2 & V_3 ) ) ;
F_2 ( F_3 ( V_1 ) , F_5 ( 0 ) , V_2 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_1 V_6 )
{
F_7 ( L_1 , V_6 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_9 ( V_8 ) ) ;
F_10 ( V_9 ) ;
F_2 ( V_9 , F_4 ( 0 ) , 0xffffffff ) ;
F_2 ( V_9 , F_5 ( 0 ) , 0x00000000 ) ;
F_11 ( V_9 ) ;
}
int F_12 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_4 * V_10 = & V_9 -> V_10 ;
V_10 -> V_5 = F_6 ;
V_10 -> V_2 = V_11 |
V_12 |
V_13 |
V_14 ;
F_13 ( V_1 , V_10 ) ;
return 0 ;
}
void F_14 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_9 ( V_8 ) ) ;
F_10 ( V_9 ) ;
F_2 ( V_9 , F_5 ( 0 ) , 0x00000000 ) ;
F_11 ( V_9 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_20 ;
T_1 V_21 , V_22 ;
V_22 = F_16 ( V_9 , F_5 ( 0 ) ) ;
V_21 = F_16 ( V_9 , F_17 ( 0 ) ) & V_22 ;
F_2 ( V_9 , F_4 ( 0 ) , V_21 ) ;
F_18 ( L_2 , V_21 ) ;
F_19 ( V_1 , V_21 ) ;
for ( V_20 = 0 ; V_20 < V_18 -> V_23 ; V_20 ++ )
if ( V_21 & F_20 ( V_18 -> V_24 [ V_20 ] ) )
F_21 ( V_16 , V_20 ) ;
}
T_2 F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_9 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
T_1 V_25 ;
V_25 = F_16 ( V_9 , V_26 ) ;
F_18 ( L_3 , V_25 ) ;
if ( V_25 & V_27 ) {
F_15 ( V_1 ) ;
V_25 &= ~ V_27 ;
}
while ( V_25 ) {
T_3 V_28 = F_23 ( V_25 ) - 1 ;
F_24 ( F_25 (
V_9 -> V_29 . V_30 , V_28 ) ) ;
V_25 &= ~ ( 1 << V_28 ) ;
}
return V_31 ;
}
int F_26 ( struct V_7 * V_8 , struct V_32 * V_33 )
{
struct V_9 * V_9 = F_3 ( F_9 ( V_8 ) ) ;
F_10 ( V_9 ) ;
F_27 ( F_9 ( V_8 ) ,
F_20 ( V_33 ) , true ) ;
F_11 ( V_9 ) ;
return 0 ;
}
void F_28 ( struct V_7 * V_8 , struct V_32 * V_33 )
{
struct V_9 * V_9 = F_3 ( F_9 ( V_8 ) ) ;
F_10 ( V_9 ) ;
F_27 ( F_9 ( V_8 ) ,
F_20 ( V_33 ) , false ) ;
F_11 ( V_9 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_9 * V_9 = F_30 ( V_35 ) ;
F_31 () ;
F_32 ( V_35 -> V_28 , & V_9 -> V_29 . V_36 ) ;
F_33 () ;
}
static void F_34 ( struct V_34 * V_35 )
{
struct V_9 * V_9 = F_30 ( V_35 ) ;
F_31 () ;
F_35 ( V_35 -> V_28 , & V_9 -> V_29 . V_36 ) ;
F_33 () ;
}
static int F_36 ( struct V_37 * V_38 ,
unsigned int V_5 , T_3 V_28 )
{
struct V_9 * V_9 = V_38 -> V_39 ;
if ( ! ( V_40 & ( 1 << V_28 ) ) )
return - V_41 ;
F_37 ( V_5 , & V_42 , V_43 ) ;
F_38 ( V_5 , V_9 ) ;
return 0 ;
}
int F_39 ( struct V_9 * V_9 )
{
struct V_44 * V_16 = V_9 -> V_16 -> V_16 ;
struct V_37 * V_38 ;
V_38 = F_40 ( V_16 -> V_45 , 32 ,
& V_46 , V_9 ) ;
if ( ! V_38 ) {
F_41 ( V_16 , L_4 ) ;
return - V_47 ;
}
V_9 -> V_29 . V_36 = 0 ;
V_9 -> V_29 . V_30 = V_38 ;
return 0 ;
}
void F_42 ( struct V_9 * V_9 )
{
if ( V_9 -> V_29 . V_30 ) {
F_43 ( V_9 -> V_29 . V_30 ) ;
V_9 -> V_29 . V_30 = NULL ;
}
}
