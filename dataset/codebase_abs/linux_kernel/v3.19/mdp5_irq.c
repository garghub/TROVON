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
F_2 ( V_9 , V_10 , 0xffffffff ) ;
}
int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_4 * V_11 = & V_9 -> V_11 ;
V_11 -> V_5 = F_4 ;
V_11 -> V_2 = V_12 |
V_13 |
V_14 |
V_15 ;
F_9 ( V_1 , V_11 ) ;
return 0 ;
}
void F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_3 ( F_7 ( V_8 ) ) ;
F_2 ( V_9 , V_3 , 0x00000000 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_9 * V_9 = F_3 ( V_1 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_21 ;
T_1 V_22 ;
V_22 = F_12 ( V_9 , V_23 ) ;
F_2 ( V_9 , V_10 , V_22 ) ;
F_13 ( L_2 , V_22 ) ;
F_14 ( V_1 , V_22 ) ;
for ( V_21 = 0 ; V_21 < V_19 -> V_24 ; V_21 ++ )
if ( V_22 & F_15 ( V_19 -> V_25 [ V_21 ] ) )
F_16 ( V_17 , V_21 ) ;
}
T_2 F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_7 ( V_8 ) ;
struct V_9 * V_9 = F_3 ( V_1 ) ;
T_1 V_26 ;
V_26 = F_12 ( V_9 , V_27 ) ;
F_13 ( L_3 , V_26 ) ;
if ( V_26 & V_28 ) {
F_11 ( V_1 ) ;
V_26 &= ~ V_28 ;
}
while ( V_26 ) {
T_3 V_29 = F_18 ( V_26 ) - 1 ;
F_19 ( F_20 (
V_9 -> V_30 . V_31 , V_29 ) ) ;
V_26 &= ~ ( 1 << V_29 ) ;
}
return V_32 ;
}
int F_21 ( struct V_7 * V_8 , struct V_33 * V_34 )
{
F_22 ( F_7 ( V_8 ) ,
F_15 ( V_34 ) , true ) ;
return 0 ;
}
void F_23 ( struct V_7 * V_8 , struct V_33 * V_34 )
{
F_22 ( F_7 ( V_8 ) ,
F_15 ( V_34 ) , false ) ;
}
static void F_24 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = F_25 ( V_36 ) ;
F_26 () ;
F_27 ( V_36 -> V_29 , & V_9 -> V_30 . V_37 ) ;
F_28 () ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_9 * V_9 = F_25 ( V_36 ) ;
F_26 () ;
F_30 ( V_36 -> V_29 , & V_9 -> V_30 . V_37 ) ;
F_28 () ;
}
static int F_31 ( struct V_38 * V_39 ,
unsigned int V_5 , T_3 V_29 )
{
struct V_9 * V_9 = V_39 -> V_40 ;
if ( ! ( V_41 & ( 1 << V_29 ) ) )
return - V_42 ;
F_32 ( V_5 , & V_43 , V_44 ) ;
F_33 ( V_5 , V_9 ) ;
F_34 ( V_5 , V_45 ) ;
return 0 ;
}
int F_35 ( struct V_9 * V_9 )
{
struct V_46 * V_17 = V_9 -> V_17 -> V_17 ;
struct V_38 * V_39 ;
V_39 = F_36 ( V_17 -> V_47 , 32 ,
& V_48 , V_9 ) ;
if ( ! V_39 ) {
F_37 ( V_17 , L_4 ) ;
return - V_49 ;
}
V_9 -> V_30 . V_37 = 0 ;
V_9 -> V_30 . V_31 = V_39 ;
return 0 ;
}
void F_38 ( struct V_9 * V_9 )
{
if ( V_9 -> V_30 . V_31 ) {
F_39 ( V_9 -> V_30 . V_31 ) ;
V_9 -> V_30 . V_31 = NULL ;
}
}
