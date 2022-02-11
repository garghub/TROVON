static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 0 ;
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
if ( V_2 -> V_8 -> V_9 & V_10 )
V_4 = 1 ;
V_7 = F_2 ( & V_2 -> V_11 , V_3 , V_4 ,
& V_2 -> V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( & V_2 -> V_13 , V_3 , V_4 ,
& V_2 -> V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( & V_2 -> V_15 ,
F_4 ( & V_2 -> V_11 ) ,
F_5 ( V_2 -> V_16 ) -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( & V_2 -> V_18 ,
F_4 ( & V_2 -> V_13 ) ,
F_5 ( V_2 -> V_16 ) -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_19 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = F_7 ( V_5 ) & ~ V_20 ;
V_6 |= V_21 | V_22 |
( V_2 -> V_15 . V_23 << V_24 ) |
V_25 | V_26 |
( V_2 -> V_18 . V_23 << V_27 ) ;
V_5 = F_8 ( V_6 ) ;
return F_9 ( V_2 , V_19 , & V_5 ,
sizeof( V_5 ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_7 = V_2 -> V_8 -> V_28 -> V_29 ( V_2 , false ) ;
if ( V_7 < 0 )
return;
V_7 = F_6 ( V_2 , V_19 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return;
V_6 = F_7 ( V_5 ) ;
V_6 &= ~ ( V_22 | V_26 ) ;
V_6 |= V_21 | V_25 ;
V_5 = F_8 ( V_6 ) ;
F_9 ( V_2 , V_19 , & V_5 ,
sizeof( V_5 ) ) ;
F_11 ( & V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_15 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_7 ;
if ( V_31 == & V_2 -> V_11 )
V_33 = & V_2 -> V_15 ;
else
V_33 = & V_2 -> V_18 ;
V_7 = F_13 ( V_31 , V_33 -> V_23 ,
F_5 ( V_2 -> V_16 ) -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! F_14 ( V_31 , V_34 ) ) {
F_15 ( V_31 ) ;
F_11 ( V_33 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_32 * V_33 ;
if ( V_31 == & V_2 -> V_11 )
V_33 = & V_2 -> V_15 ;
else
V_33 = & V_2 -> V_18 ;
F_15 ( V_31 ) ;
F_11 ( V_33 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_7 = F_6 ( V_2 , V_36 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = F_7 ( V_5 ) ;
V_6 &= ~ ( V_37 |
V_38 |
V_39 ) ;
if ( V_2 -> V_14 . V_40 [ 0 ] == 0 )
V_6 |= V_37 ;
if ( V_2 -> V_12 . V_40 [ 0 ] == 0 )
V_6 |= V_38 ;
V_6 |= F_5 ( V_2 -> V_16 ) -> V_17 ;
V_5 = F_8 ( V_6 ) ;
return F_9 ( V_2 , V_36 , & V_5 ,
sizeof( V_5 ) ) ;
}
int F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
const struct V_41 * V_28 = V_2 -> V_8 -> V_28 ;
unsigned int V_42 ;
int V_7 = 0 ;
if ( V_2 -> V_43 == 0 && V_2 -> V_44 == 0 )
return 0 ;
if ( F_19 ( & V_2 -> V_11 ) ||
F_19 ( & V_2 -> V_13 ) ) {
F_15 ( & V_2 -> V_11 ) ;
F_15 ( & V_2 -> V_13 ) ;
F_10 ( V_2 ) ;
}
V_7 = V_28 -> V_45 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_28 -> V_46 ( V_2 , & V_42 ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_1 , V_7 ) ;
return V_7 ;
}
if ( V_3 == 0 )
V_3 = V_42 ;
if ( V_3 != V_42 ) {
F_15 ( & V_2 -> V_11 ) ;
F_15 ( & V_2 -> V_13 ) ;
F_10 ( V_2 ) ;
}
if ( ! F_21 ( & V_2 -> V_11 ) ) {
V_7 = V_28 -> V_48 ( V_2 , V_3 ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_3 , V_7 ) ;
F_10 ( V_2 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 , & V_2 -> V_11 ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_4 , V_7 ) ;
F_10 ( V_2 ) ;
return V_7 ;
}
V_7 = V_28 -> V_29 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_5 , V_7 ) ;
F_10 ( V_2 ) ;
return V_7 ;
}
}
if ( ! F_21 ( & V_2 -> V_13 ) &&
V_2 -> V_43 > 0 ) {
V_7 = F_12 ( V_2 , & V_2 -> V_13 ) ;
if ( V_7 < 0 ) {
F_20 ( & V_2 -> V_16 -> V_47 ,
L_6 , V_7 ) ;
F_15 ( & V_2 -> V_11 ) ;
F_10 ( V_2 ) ;
return V_7 ;
}
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 == 0 ) {
if ( F_21 ( & V_2 -> V_13 ) )
F_16 ( V_2 , & V_2 -> V_13 ) ;
if ( V_2 -> V_44 == 0 ) {
if ( F_21 ( & V_2 -> V_11 ) )
F_16 ( V_2 , & V_2 -> V_11 ) ;
F_10 ( V_2 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 , enum V_49 V_50 )
{
int V_7 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( V_50 == V_51 ) {
V_31 = & V_2 -> V_13 ;
V_33 = & V_2 -> V_18 ;
} else {
V_31 = & V_2 -> V_11 ;
V_33 = & V_2 -> V_15 ;
}
V_7 = F_24 ( V_33 , V_2 -> V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_25 ( V_31 , V_2 -> V_16 , V_50 , V_2 -> V_8 -> V_28 ) ;
if ( V_7 < 0 ) {
F_26 ( V_31 ) ;
F_27 ( V_33 ) ;
}
return V_7 ;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_49 V_50 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( V_50 == V_51 ) {
V_31 = & V_2 -> V_13 ;
V_33 = & V_2 -> V_18 ;
} else {
V_31 = & V_2 -> V_11 ;
V_33 = & V_2 -> V_15 ;
}
F_26 ( V_31 ) ;
F_11 ( V_33 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_23 ( V_2 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_23 ( V_2 , V_52 ) ;
if ( V_7 < 0 )
F_28 ( V_2 , V_51 ) ;
return V_7 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_51 ) ;
F_28 ( V_2 , V_52 ) ;
V_2 -> V_44 = 0 ;
V_2 -> V_43 = 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
V_2 -> V_53 = true ;
F_32 ( & V_2 -> V_54 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_7 ;
F_34 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_56 < 0 ) {
V_7 = - V_57 ;
goto V_58;
}
if ( V_2 -> V_56 ++ == 0 )
F_31 ( V_2 ) ;
V_7 = 0 ;
V_58:
F_35 ( & V_2 -> V_55 ) ;
return V_7 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_55 ) ;
if ( F_37 ( V_2 -> V_56 <= 0 ) )
goto V_58;
if ( -- V_2 -> V_56 == 0 )
F_31 ( V_2 ) ;
V_58:
F_35 ( & V_2 -> V_55 ) ;
}
