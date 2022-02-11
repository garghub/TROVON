static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = F_2 ( V_3 ) ;
int V_8 ;
if ( ! F_3 ( V_2 ) )
return;
if ( ! V_5 -> V_9 )
return;
V_8 = F_4 ( V_7 ) ;
if ( ! F_5 ( V_2 ) && ( V_8 & V_10 ) ) {
F_6 ( L_1 ) ;
F_7 ( V_5 , V_3 ) ;
V_8 &= ~ V_10 ;
F_8 ( V_7 , V_8 ) ;
F_9 ( V_2 , V_3 ) ;
V_8 = F_4 ( V_7 ) ;
if ( V_8 & V_10 )
F_6 ( L_2 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
unsigned V_11 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
enum V_3 V_3 ;
if ( ! V_14 . V_15 )
return;
F_11 (dev_priv, pipe) {
if ( ! ( V_11 & F_12 ( V_3 ) ) )
continue;
F_1 ( V_2 , V_3 ) ;
if ( V_13 && F_13 ( V_2 ) )
V_13 -> V_16 = true ;
}
}
void F_14 ( struct V_17 * V_18 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = V_18 -> V_19 . V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_15 ( ! F_16 ( & V_2 -> V_20 ) ) ;
if ( ! V_18 -> V_11 )
return;
if ( V_13 ) {
F_17 ( & V_5 -> V_21 . V_22 ) ;
V_5 -> V_21 . V_23
|= V_18 -> V_11 ;
V_5 -> V_21 . V_24
&= ~ V_18 -> V_11 ;
F_18 ( & V_5 -> V_21 . V_22 ) ;
}
F_10 ( V_2 , V_18 -> V_11 , V_13 ) ;
F_19 ( V_2 , V_18 -> V_11 ) ;
}
void F_20 ( struct V_1 * V_2 ,
unsigned V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_17 ( & V_5 -> V_21 . V_22 ) ;
V_11 &= ~ V_5 -> V_21 . V_23 ;
F_18 ( & V_5 -> V_21 . V_22 ) ;
F_10 ( V_2 , V_11 , NULL ) ;
F_21 ( V_2 , V_11 ) ;
if ( V_5 -> V_25 . V_26 ) {
V_5 -> V_25 . V_26 = false ;
F_22 ( V_2 , V_27 ) ;
}
}
void F_23 ( struct V_17 * V_18 ,
bool V_28 )
{
struct V_1 * V_2 = V_18 -> V_19 . V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned V_11 ;
F_15 ( ! F_16 ( & V_2 -> V_20 ) ) ;
if ( ! V_18 -> V_11 )
return;
V_11 = V_18 -> V_11 ;
if ( V_28 ) {
F_17 ( & V_5 -> V_21 . V_22 ) ;
V_11 &= V_5 -> V_21 . V_23 ;
V_5 -> V_21 . V_23 &= ~ V_11 ;
F_18 ( & V_5 -> V_21 . V_22 ) ;
}
F_20 ( V_2 , V_11 ) ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_17 ( & V_5 -> V_21 . V_22 ) ;
V_5 -> V_21 . V_24 |= V_11 ;
V_5 -> V_21 . V_23 &= ~ V_11 ;
F_18 ( & V_5 -> V_21 . V_22 ) ;
}
void F_25 ( struct V_1 * V_2 ,
unsigned V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_17 ( & V_5 -> V_21 . V_22 ) ;
V_11 &= V_5 -> V_21 . V_24 ;
V_5 -> V_21 . V_24 &= ~ V_11 ;
F_18 ( & V_5 -> V_21 . V_22 ) ;
F_20 ( V_2 , V_11 ) ;
}
