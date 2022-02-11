void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( F_3 ( V_1 ) , V_3 , V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 , T_1 V_6 )
{
F_5 ( L_1 , V_6 ) ;
}
void F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_8 ( V_9 ) ;
F_2 ( V_9 , V_10 , 0xffffffff ) ;
F_2 ( V_9 , V_3 , 0x00000000 ) ;
F_9 ( V_9 ) ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_4 * V_11 = & V_9 -> V_11 ;
V_11 -> V_5 = F_4 ;
V_11 -> V_2 = V_12 |
V_13 |
V_14 |
V_15 ;
F_11 ( V_1 , V_11 ) ;
return 0 ;
}
void F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_8 ( V_9 ) ;
F_2 ( V_9 , V_3 , 0x00000000 ) ;
F_9 ( V_9 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_21 ;
T_1 V_22 ;
V_22 = F_14 ( V_9 , V_23 ) ;
F_2 ( V_9 , V_10 , V_22 ) ;
F_15 ( L_2 , V_22 ) ;
F_16 ( V_1 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_19 -> V_24 ; V_21 ++ )
if ( V_22 & F_17 ( V_19 -> V_25 [ V_21 ] ) )
F_18 ( V_17 , V_21 ) ;
}
T_2 F_19 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
T_1 V_26 ;
V_26 = F_14 ( V_9 , V_27 ) ;
F_15 ( L_3 , V_26 ) ;
if ( V_26 & V_28 ) {
F_13 ( V_1 ) ;
V_26 &= ~ V_28 ;
}
while ( V_26 ) {
T_3 V_29 = F_20 ( V_26 ) - 1 ;
F_21 ( F_22 (
V_9 -> V_30 . V_31 , V_29 ) ) ;
V_26 &= ~ ( 1 << V_29 ) ;
}
return V_32 ;
}
int F_23 ( struct V_7 * V_8 , struct V_33 * V_34 )
{
F_24 ( F_7 ( V_8 ) ,
F_17 ( V_34 ) , true ) ;
return 0 ;
}
void F_25 ( struct V_7 * V_8 , struct V_33 * V_34 )
{
F_24 ( F_7 ( V_8 ) ,
F_17 ( V_34 ) , false ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = F_27 ( V_36 ) ;
F_28 () ;
F_29 ( V_36 -> V_29 , & V_9 -> V_30 . V_37 ) ;
F_30 () ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = F_27 ( V_36 ) ;
F_28 () ;
F_32 ( V_36 -> V_29 , & V_9 -> V_30 . V_37 ) ;
F_30 () ;
}
static int F_33 ( struct V_38 * V_39 ,
unsigned int V_5 , T_3 V_29 )
{
struct V_9 * V_9 = V_39 -> V_40 ;
if ( ! ( V_41 & ( 1 << V_29 ) ) )
return - V_42 ;
F_34 ( V_5 , & V_43 , V_44 ) ;
F_35 ( V_5 , V_9 ) ;
F_36 ( V_5 , V_45 ) ;
return 0 ;
}
int F_37 ( struct V_9 * V_9 )
{
struct V_46 * V_17 = V_9 -> V_17 -> V_17 ;
struct V_38 * V_39 ;
V_39 = F_38 ( V_17 -> V_47 , 32 ,
& V_48 , V_9 ) ;
if ( ! V_39 ) {
F_39 ( V_17 , L_4 ) ;
return - V_49 ;
}
V_9 -> V_30 . V_37 = 0 ;
V_9 -> V_30 . V_31 = V_39 ;
return 0 ;
}
void F_40 ( struct V_9 * V_9 )
{
if ( V_9 -> V_30 . V_31 ) {
F_41 ( V_9 -> V_30 . V_31 ) ;
V_9 -> V_30 . V_31 = NULL ;
}
}
