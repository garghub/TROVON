void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( F_3 ( V_1 ) , F_4 ( 0 ) , V_2 ) ;
}
static void F_5 ( struct V_3 * V_4 , T_1 V_5 )
{
F_6 ( L_1 , V_5 ) ;
}
void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_3 ( F_8 ( V_7 ) ) ;
F_9 ( V_8 ) ;
F_2 ( V_8 , F_10 ( 0 ) , 0xffffffff ) ;
F_2 ( V_8 , F_4 ( 0 ) , 0x00000000 ) ;
F_11 ( V_8 ) ;
}
int F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_8 ( V_7 ) ;
struct V_8 * V_8 = F_3 ( V_1 ) ;
struct V_3 * V_9 = & V_8 -> V_9 ;
V_9 -> V_4 = F_5 ;
V_9 -> V_2 = V_10 |
V_11 |
V_12 |
V_13 ;
F_13 ( V_1 , V_9 ) ;
return 0 ;
}
void F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_3 ( F_8 ( V_7 ) ) ;
F_9 ( V_8 ) ;
F_2 ( V_8 , F_4 ( 0 ) , 0x00000000 ) ;
F_11 ( V_8 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = F_3 ( V_1 ) ;
struct V_14 * V_15 = V_8 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_19 ;
T_1 V_20 ;
V_20 = F_16 ( V_8 , F_17 ( 0 ) ) ;
F_2 ( V_8 , F_10 ( 0 ) , V_20 ) ;
F_18 ( L_2 , V_20 ) ;
F_19 ( V_1 , V_20 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_21 ; V_19 ++ )
if ( V_20 & F_20 ( V_17 -> V_22 [ V_19 ] ) )
F_21 ( V_15 , V_19 ) ;
}
T_2 F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_8 ( V_7 ) ;
struct V_8 * V_8 = F_3 ( V_1 ) ;
T_1 V_23 ;
V_23 = F_16 ( V_8 , V_24 ) ;
F_18 ( L_3 , V_23 ) ;
if ( V_23 & V_25 ) {
F_15 ( V_1 ) ;
V_23 &= ~ V_25 ;
}
while ( V_23 ) {
T_3 V_26 = F_23 ( V_23 ) - 1 ;
F_24 ( F_25 (
V_8 -> V_27 . V_28 , V_26 ) ) ;
V_23 &= ~ ( 1 << V_26 ) ;
}
return V_29 ;
}
int F_26 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
F_27 ( F_8 ( V_7 ) ,
F_20 ( V_31 ) , true ) ;
return 0 ;
}
void F_28 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
F_27 ( F_8 ( V_7 ) ,
F_20 ( V_31 ) , false ) ;
}
static void F_29 ( struct V_32 * V_33 )
{
struct V_8 * V_8 = F_30 ( V_33 ) ;
F_31 () ;
F_32 ( V_33 -> V_26 , & V_8 -> V_27 . V_34 ) ;
F_33 () ;
}
static void F_34 ( struct V_32 * V_33 )
{
struct V_8 * V_8 = F_30 ( V_33 ) ;
F_31 () ;
F_35 ( V_33 -> V_26 , & V_8 -> V_27 . V_34 ) ;
F_33 () ;
}
static int F_36 ( struct V_35 * V_36 ,
unsigned int V_4 , T_3 V_26 )
{
struct V_8 * V_8 = V_36 -> V_37 ;
if ( ! ( V_38 & ( 1 << V_26 ) ) )
return - V_39 ;
F_37 ( V_4 , & V_40 , V_41 ) ;
F_38 ( V_4 , V_8 ) ;
F_39 ( V_4 , V_42 ) ;
return 0 ;
}
int F_40 ( struct V_8 * V_8 )
{
struct V_43 * V_15 = V_8 -> V_15 -> V_15 ;
struct V_35 * V_36 ;
V_36 = F_41 ( V_15 -> V_44 , 32 ,
& V_45 , V_8 ) ;
if ( ! V_36 ) {
F_42 ( V_15 , L_4 ) ;
return - V_46 ;
}
V_8 -> V_27 . V_34 = 0 ;
V_8 -> V_27 . V_28 = V_36 ;
return 0 ;
}
void F_43 ( struct V_8 * V_8 )
{
if ( V_8 -> V_27 . V_28 ) {
F_44 ( V_8 -> V_27 . V_28 ) ;
V_8 -> V_27 . V_28 = NULL ;
}
}
