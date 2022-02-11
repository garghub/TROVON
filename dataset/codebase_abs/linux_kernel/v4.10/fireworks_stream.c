static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
enum V_7 V_8 ;
enum V_9 V_10 ;
int V_11 ;
if ( V_4 == & V_2 -> V_12 ) {
V_6 = & V_2 -> V_13 ;
V_8 = V_14 ;
V_10 = V_15 ;
} else {
V_6 = & V_2 -> V_16 ;
V_8 = V_17 ;
V_10 = V_18 ;
}
V_11 = F_2 ( V_6 , V_2 -> V_19 , V_8 , 0 ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_3 ( V_4 , V_2 -> V_19 , V_10 , V_21 ) ;
if ( V_11 < 0 ) {
F_4 ( V_4 ) ;
F_5 ( V_6 ) ;
}
V_20:
return V_11 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
if ( V_4 == & V_2 -> V_12 )
F_9 ( & V_2 -> V_13 ) ;
else
F_9 ( & V_2 -> V_16 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_22 )
{
struct V_5 * V_6 ;
unsigned int V_23 , V_24 , V_25 ;
int V_11 ;
V_11 = F_11 ( V_22 , & V_23 ) ;
if ( V_11 < 0 )
goto V_20;
if ( V_4 == & V_2 -> V_12 ) {
V_6 = & V_2 -> V_13 ;
V_24 = V_2 -> V_26 [ V_23 ] ;
V_25 = V_2 -> V_27 ;
} else {
V_6 = & V_2 -> V_16 ;
V_24 = V_2 -> V_28 [ V_23 ] ;
V_25 = V_2 -> V_29 ;
}
V_11 = F_12 ( V_4 , V_22 ,
V_24 , V_25 , false ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_13 ( V_6 ,
F_14 ( V_4 ) ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_15 ( V_4 ,
V_6 -> V_30 . V_31 ,
V_6 -> V_32 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 , V_4 ) ;
goto V_20;
}
if ( ! F_16 ( V_4 , V_33 ) ) {
F_6 ( V_2 , V_4 ) ;
V_11 = - V_34 ;
}
V_20:
return V_11 ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 == & V_2 -> V_12 )
V_6 = & V_2 -> V_13 ;
else
V_6 = & V_2 -> V_16 ;
F_4 ( V_4 ) ;
F_5 ( V_6 ) ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_3 * V_35 )
{
struct V_5 * V_6 ;
bool V_36 ;
int V_11 ;
if ( V_35 == & V_2 -> V_12 )
V_6 = & V_2 -> V_13 ;
else
V_6 = & V_2 -> V_16 ;
V_11 = F_19 ( V_6 , & V_36 ) ;
if ( ( V_11 >= 0 ) && V_36 && ! F_20 ( V_35 ) ) {
F_21 ( & V_2 -> V_19 -> V_37 ,
L_1 ,
( V_6 -> V_38 == V_14 ) ? 'o' : 'i' ,
V_6 -> V_39 ) ;
V_11 = - V_40 ;
}
return V_11 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_1 ( V_2 , & V_2 -> V_12 ) ;
if ( V_11 < 0 )
goto V_20;
V_2 -> V_12 . V_41 |= V_42 ;
V_2 -> V_12 . V_41 |= V_43 ;
V_2 -> V_12 . V_41 |= V_44 ;
if ( V_2 -> V_45 &&
( V_2 -> V_46 == 0x5070000 ||
V_2 -> V_46 == 0x5070300 ||
V_2 -> V_46 == 0x5080000 ) )
V_2 -> V_12 . V_47 = 0x02 ;
if ( V_2 -> V_48 )
V_2 -> V_12 . V_41 |= V_49 ;
if ( V_2 -> V_46 == 0x5050000 )
V_2 -> V_12 . V_50 = 8 ;
V_11 = F_1 ( V_2 , & V_2 -> V_51 ) ;
if ( V_11 < 0 ) {
F_17 ( V_2 , & V_2 -> V_12 ) ;
goto V_20;
}
V_11 = F_23 ( V_2 , V_52 ) ;
if ( V_11 < 0 ) {
F_17 ( V_2 , & V_2 -> V_12 ) ;
F_17 ( V_2 , & V_2 -> V_51 ) ;
}
V_20:
return V_11 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_53 )
{
unsigned int V_54 ;
int V_11 = 0 ;
if ( V_2 -> V_55 == 0 && V_2 -> V_56 == 0 )
goto V_20;
V_11 = F_18 ( V_2 , & V_2 -> V_51 ) ;
if ( V_11 < 0 )
goto V_20;
if ( F_25 ( & V_2 -> V_12 ) )
F_6 ( V_2 , & V_2 -> V_12 ) ;
if ( F_25 ( & V_2 -> V_51 ) )
F_6 ( V_2 , & V_2 -> V_51 ) ;
V_11 = F_26 ( V_2 , & V_54 ) ;
if ( V_11 < 0 )
goto V_20;
if ( V_53 == 0 )
V_53 = V_54 ;
if ( V_53 != V_54 ) {
F_6 ( V_2 , & V_2 -> V_12 ) ;
F_6 ( V_2 , & V_2 -> V_51 ) ;
}
if ( ! F_20 ( & V_2 -> V_51 ) ) {
V_11 = F_27 ( V_2 , V_53 ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_10 ( V_2 , & V_2 -> V_51 , V_53 ) ;
if ( V_11 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_37 ,
L_2 , V_11 ) ;
goto V_20;
}
}
if ( V_2 -> V_56 > 0 &&
! F_20 ( & V_2 -> V_12 ) ) {
V_11 = F_10 ( V_2 , & V_2 -> V_12 , V_53 ) ;
if ( V_11 < 0 ) {
F_21 ( & V_2 -> V_19 -> V_37 ,
L_3 , V_11 ) ;
F_6 ( V_2 , & V_2 -> V_51 ) ;
}
}
V_20:
return V_11 ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 == 0 ) {
F_6 ( V_2 , & V_2 -> V_12 ) ;
if ( V_2 -> V_55 == 0 )
F_6 ( V_2 , & V_2 -> V_51 ) ;
}
}
void F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( & V_2 -> V_13 ) < 0 ||
F_30 ( & V_2 -> V_16 ) < 0 ) {
F_6 ( V_2 , & V_2 -> V_51 ) ;
F_6 ( V_2 , & V_2 -> V_12 ) ;
} else {
F_31 ( & V_2 -> V_51 ) ;
F_31 ( & V_2 -> V_12 ) ;
}
}
void F_32 ( struct V_1 * V_2 )
{
F_17 ( V_2 , & V_2 -> V_51 ) ;
F_17 ( V_2 , & V_2 -> V_12 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_57 = true ;
F_34 ( & V_2 -> V_58 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_11 ;
F_36 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_60 < 0 ) {
V_11 = - V_40 ;
goto V_20;
}
if ( V_2 -> V_60 ++ == 0 )
F_33 ( V_2 ) ;
V_11 = 0 ;
V_20:
F_37 ( & V_2 -> V_59 ) ;
return V_11 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_59 ) ;
if ( F_39 ( V_2 -> V_60 <= 0 ) )
goto V_20;
if ( -- V_2 -> V_60 == 0 )
F_33 ( V_2 ) ;
V_20:
F_37 ( & V_2 -> V_59 ) ;
}
