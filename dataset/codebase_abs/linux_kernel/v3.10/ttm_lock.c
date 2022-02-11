void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_2 ) ;
F_3 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
V_2 -> signal = V_7 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_2 ) ;
if ( -- V_2 -> V_4 == 0 )
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
bool V_8 = false ;
F_5 ( & V_2 -> V_2 ) ;
if ( F_9 ( V_2 -> V_6 ) ) {
F_10 ( V_2 -> signal , V_9 , 0 ) ;
F_7 ( & V_2 -> V_2 ) ;
return false ;
}
if ( V_2 -> V_4 >= 0 && V_2 -> V_5 == 0 ) {
++ V_2 -> V_4 ;
V_8 = true ;
}
F_7 ( & V_2 -> V_2 ) ;
return V_8 ;
}
int F_11 ( struct V_1 * V_2 , bool V_10 )
{
int V_11 = 0 ;
if ( V_10 )
V_11 = F_12 ( V_2 -> V_3 ,
F_8 ( V_2 ) ) ;
else
F_13 ( V_2 -> V_3 , F_8 ( V_2 ) ) ;
return V_11 ;
}
static bool F_14 ( struct V_1 * V_2 , bool * V_8 )
{
bool V_12 = true ;
* V_8 = false ;
F_5 ( & V_2 -> V_2 ) ;
if ( F_9 ( V_2 -> V_6 ) ) {
F_10 ( V_2 -> signal , V_9 , 0 ) ;
F_7 ( & V_2 -> V_2 ) ;
return false ;
}
if ( V_2 -> V_4 >= 0 && V_2 -> V_5 == 0 ) {
++ V_2 -> V_4 ;
V_12 = false ;
* V_8 = true ;
} else if ( V_2 -> V_5 == 0 ) {
V_12 = false ;
}
F_7 ( & V_2 -> V_2 ) ;
return ! V_12 ;
}
int F_15 ( struct V_1 * V_2 , bool V_10 )
{
int V_11 = 0 ;
bool V_8 ;
if ( V_10 )
V_11 = F_12
( V_2 -> V_3 , F_14 ( V_2 , & V_8 ) ) ;
else
F_13 ( V_2 -> V_3 , F_14 ( V_2 , & V_8 ) ) ;
if ( F_9 ( V_11 != 0 ) ) {
F_16 ( V_8 ) ;
return V_11 ;
}
return ( V_8 ) ? 0 : - V_13 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_2 ) ;
V_2 -> V_4 = 0 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
bool V_8 = false ;
F_5 ( & V_2 -> V_2 ) ;
if ( F_9 ( V_2 -> V_6 ) ) {
F_10 ( V_2 -> signal , V_9 , 0 ) ;
F_7 ( & V_2 -> V_2 ) ;
return false ;
}
if ( V_2 -> V_4 == 0 && ( ( V_2 -> V_5 & ~ V_14 ) == 0 ) ) {
V_2 -> V_4 = - 1 ;
V_2 -> V_5 &= ~ V_14 ;
V_8 = true ;
} else {
V_2 -> V_5 |= V_14 ;
}
F_7 ( & V_2 -> V_2 ) ;
return V_8 ;
}
int F_19 ( struct V_1 * V_2 , bool V_10 )
{
int V_11 = 0 ;
if ( V_10 ) {
V_11 = F_12 ( V_2 -> V_3 ,
F_18 ( V_2 ) ) ;
if ( F_9 ( V_11 != 0 ) ) {
F_5 ( & V_2 -> V_2 ) ;
V_2 -> V_5 &= ~ V_14 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
}
} else
F_13 ( V_2 -> V_3 , F_8 ( V_2 ) ) ;
return V_11 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_2 ) ;
V_2 -> V_4 = 1 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_5 ( & V_2 -> V_2 ) ;
if ( F_9 ( ! ( V_2 -> V_5 & V_15 ) ) )
V_11 = - V_16 ;
V_2 -> V_5 &= ~ V_15 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
return V_11 ;
}
static void F_22 ( struct V_17 * * V_18 )
{
struct V_17 * V_19 = * V_18 ;
struct V_1 * V_2 = F_23 ( V_19 , struct V_1 , V_19 ) ;
int V_11 ;
* V_18 = NULL ;
V_11 = F_21 ( V_2 ) ;
F_16 ( V_11 != 0 ) ;
}
static bool F_24 ( struct V_1 * V_2 )
{
bool V_8 = false ;
F_5 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_5 &= ~ V_20 ;
V_2 -> V_5 |= V_15 ;
V_8 = true ;
} else {
V_2 -> V_5 |= V_20 ;
}
F_7 ( & V_2 -> V_2 ) ;
return V_8 ;
}
int F_25 ( struct V_1 * V_2 ,
bool V_10 ,
struct V_21 * V_22 )
{
int V_11 = 0 ;
if ( V_10 ) {
V_11 = F_12 ( V_2 -> V_3 ,
F_24 ( V_2 ) ) ;
if ( F_9 ( V_11 != 0 ) ) {
F_5 ( & V_2 -> V_2 ) ;
V_2 -> V_5 &= ~ V_20 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
return V_11 ;
}
} else
F_13 ( V_2 -> V_3 , F_24 ( V_2 ) ) ;
V_11 = F_26 ( V_22 , & V_2 -> V_19 , false ,
V_23 , & F_22 , NULL ) ;
if ( V_11 )
( void ) F_21 ( V_2 ) ;
else
V_2 -> V_24 = V_22 ;
return V_11 ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_24 ,
V_2 -> V_19 . V_25 . V_26 , V_27 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_2 ) ;
V_2 -> V_5 &= ~ V_28 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( & V_2 -> V_2 ) ;
}
static bool F_30 ( struct V_1 * V_2 )
{
bool V_8 = false ;
F_5 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_4 == 0 ) {
V_2 -> V_5 &= ~ V_29 ;
V_2 -> V_5 |= V_28 ;
V_8 = true ;
} else {
V_2 -> V_5 |= V_29 ;
}
F_7 ( & V_2 -> V_2 ) ;
return V_8 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_3 , F_30 ( V_2 ) ) ;
}
