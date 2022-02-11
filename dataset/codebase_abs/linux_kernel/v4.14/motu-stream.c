static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 0 ;
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
if ( ( V_2 -> V_8 -> V_9 & V_10 ) ||
( V_2 -> V_8 -> V_9 & V_11 ) )
V_4 = 1 ;
V_7 = F_2 ( & V_2 -> V_12 , V_3 , V_4 ,
& V_2 -> V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ( V_2 -> V_8 -> V_9 & V_14 ) ||
( V_2 -> V_8 -> V_9 & V_15 ) )
V_4 = 1 ;
else
V_4 = 0 ;
V_7 = F_2 ( & V_2 -> V_16 , V_3 , V_4 ,
& V_2 -> V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( & V_2 -> V_18 ,
F_4 ( & V_2 -> V_12 ) ,
F_5 ( V_2 -> V_19 ) -> V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( & V_2 -> V_21 ,
F_4 ( & V_2 -> V_16 ) ,
F_5 ( V_2 -> V_19 ) -> V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_22 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = F_7 ( V_5 ) & ~ V_23 ;
V_6 |= V_24 | V_25 |
( V_2 -> V_18 . V_26 << V_27 ) |
V_28 | V_29 |
( V_2 -> V_21 . V_26 << V_30 ) ;
V_5 = F_8 ( V_6 ) ;
return F_9 ( V_2 , V_22 , & V_5 ,
sizeof( V_5 ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_7 = V_2 -> V_8 -> V_31 -> V_32 ( V_2 , false ) ;
if ( V_7 < 0 )
return;
V_7 = F_6 ( V_2 , V_22 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return;
V_6 = F_7 ( V_5 ) ;
V_6 &= ~ ( V_25 | V_29 ) ;
V_6 |= V_24 | V_28 ;
V_5 = F_8 ( V_6 ) ;
F_9 ( V_2 , V_22 , & V_5 ,
sizeof( V_5 ) ) ;
F_11 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_35 * V_36 ;
int V_7 ;
if ( V_34 == & V_2 -> V_12 )
V_36 = & V_2 -> V_18 ;
else
V_36 = & V_2 -> V_21 ;
V_7 = F_13 ( V_34 , V_36 -> V_26 ,
F_5 ( V_2 -> V_19 ) -> V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! F_14 ( V_34 , V_37 ) ) {
F_15 ( V_34 ) ;
F_11 ( V_36 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_35 * V_36 ;
if ( V_34 == & V_2 -> V_12 )
V_36 = & V_2 -> V_18 ;
else
V_36 = & V_2 -> V_21 ;
F_15 ( V_34 ) ;
F_11 ( V_36 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = V_2 -> V_8 -> V_31 -> V_39 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_8 -> V_9 & V_14 ) {
V_2 -> V_17 . V_40 = 4 ;
V_2 -> V_17 . V_41 = 6 ;
} else if ( V_2 -> V_8 -> V_9 & V_15 ) {
V_2 -> V_17 . V_40 = 8 ;
V_2 -> V_17 . V_41 = 7 ;
}
if ( V_2 -> V_8 -> V_9 & V_10 ) {
V_2 -> V_13 . V_40 = 4 ;
V_2 -> V_13 . V_41 = 6 ;
} else if ( V_2 -> V_8 -> V_9 & V_11 ) {
V_2 -> V_13 . V_40 = 8 ;
V_2 -> V_13 . V_41 = 7 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_7 = F_6 ( V_2 , V_42 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = F_7 ( V_5 ) ;
V_6 &= ~ ( V_43 |
V_44 |
V_45 ) ;
if ( V_2 -> V_17 . V_46 [ 0 ] == 0 )
V_6 |= V_43 ;
if ( V_2 -> V_13 . V_46 [ 0 ] == 0 )
V_6 |= V_44 ;
V_6 |= F_5 ( V_2 -> V_19 ) -> V_20 ;
V_5 = F_8 ( V_6 ) ;
return F_9 ( V_2 , V_42 , & V_5 ,
sizeof( V_5 ) ) ;
}
int F_19 ( struct V_1 * V_2 , unsigned int V_3 )
{
const struct V_47 * V_31 = V_2 -> V_8 -> V_31 ;
unsigned int V_48 ;
int V_7 = 0 ;
if ( V_2 -> V_49 == 0 && V_2 -> V_50 == 0 )
return 0 ;
if ( F_20 ( & V_2 -> V_12 ) ||
F_20 ( & V_2 -> V_16 ) ) {
F_15 ( & V_2 -> V_12 ) ;
F_15 ( & V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
}
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_31 -> V_51 ( V_2 , & V_48 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_1 , V_7 ) ;
return V_7 ;
}
if ( V_3 == 0 )
V_3 = V_48 ;
if ( V_3 != V_48 ) {
F_15 ( & V_2 -> V_12 ) ;
F_15 ( & V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
}
if ( ! F_22 ( & V_2 -> V_12 ) ) {
V_7 = V_31 -> V_53 ( V_2 , V_3 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_3 , V_7 ) ;
goto V_54;
}
V_7 = F_12 ( V_2 , & V_2 -> V_12 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_4 , V_7 ) ;
goto V_54;
}
V_7 = V_31 -> V_32 ( V_2 , true ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_5 , V_7 ) ;
goto V_54;
}
}
if ( ! F_22 ( & V_2 -> V_16 ) &&
V_2 -> V_49 > 0 ) {
V_7 = F_12 ( V_2 , & V_2 -> V_16 ) ;
if ( V_7 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_52 ,
L_6 , V_7 ) ;
F_15 ( & V_2 -> V_12 ) ;
goto V_54;
}
}
return 0 ;
V_54:
F_10 ( V_2 ) ;
return V_7 ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 == 0 ) {
if ( F_22 ( & V_2 -> V_16 ) )
F_16 ( V_2 , & V_2 -> V_16 ) ;
if ( V_2 -> V_50 == 0 ) {
if ( F_22 ( & V_2 -> V_12 ) )
F_16 ( V_2 , & V_2 -> V_12 ) ;
F_10 ( V_2 ) ;
}
}
}
static int F_24 ( struct V_1 * V_2 , enum V_55 V_56 )
{
int V_7 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
if ( V_56 == V_57 ) {
V_34 = & V_2 -> V_16 ;
V_36 = & V_2 -> V_21 ;
} else {
V_34 = & V_2 -> V_12 ;
V_36 = & V_2 -> V_18 ;
}
V_7 = F_25 ( V_36 , V_2 -> V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_26 ( V_34 , V_2 -> V_19 , V_56 , V_2 -> V_8 -> V_31 ) ;
if ( V_7 < 0 ) {
F_27 ( V_34 ) ;
F_28 ( V_36 ) ;
}
return V_7 ;
}
static void F_29 ( struct V_1 * V_2 ,
enum V_55 V_56 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
if ( V_56 == V_57 ) {
V_34 = & V_2 -> V_16 ;
V_36 = & V_2 -> V_21 ;
} else {
V_34 = & V_2 -> V_12 ;
V_36 = & V_2 -> V_18 ;
}
F_27 ( V_34 ) ;
F_11 ( V_36 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_24 ( V_2 , V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_24 ( V_2 , V_58 ) ;
if ( V_7 < 0 )
F_29 ( V_2 , V_57 ) ;
return V_7 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_57 ) ;
F_29 ( V_2 , V_58 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_49 = 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_59 = true ;
F_33 ( & V_2 -> V_60 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_7 ;
F_35 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_62 < 0 ) {
V_7 = - V_63 ;
goto V_64;
}
if ( V_2 -> V_62 ++ == 0 )
F_32 ( V_2 ) ;
V_7 = 0 ;
V_64:
F_36 ( & V_2 -> V_61 ) ;
return V_7 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_61 ) ;
if ( F_38 ( V_2 -> V_62 <= 0 ) )
goto V_64;
if ( -- V_2 -> V_62 == 0 )
F_32 ( V_2 ) ;
V_64:
F_36 ( & V_2 -> V_61 ) ;
}
