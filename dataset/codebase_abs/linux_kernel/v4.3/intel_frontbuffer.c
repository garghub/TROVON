void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_3 ( ! F_4 ( & V_6 -> V_10 ) ) ;
if ( ! V_2 -> V_11 )
return;
if ( V_4 == V_12 ) {
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_9 -> V_13 . V_15
|= V_2 -> V_11 ;
V_9 -> V_13 . V_16
&= ~ V_2 -> V_11 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
}
F_7 ( V_6 , V_2 -> V_11 ) ;
F_8 ( V_6 , V_2 -> V_11 ) ;
F_9 ( V_9 , V_2 -> V_11 , V_4 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned V_11 ,
enum V_3 V_4 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_11 &= ~ V_9 -> V_13 . V_15 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
if ( ! V_11 )
return;
F_11 ( V_6 , V_11 ) ;
F_12 ( V_6 , V_11 , V_4 ) ;
F_13 ( V_9 , V_11 , V_4 ) ;
}
void F_14 ( struct V_1 * V_2 ,
bool V_17 , enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
unsigned V_11 ;
F_3 ( ! F_4 ( & V_6 -> V_10 ) ) ;
if ( ! V_2 -> V_11 )
return;
V_11 = V_2 -> V_11 ;
if ( V_17 ) {
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_11 &= V_9 -> V_13 . V_15 ;
V_9 -> V_13 . V_15 &= ~ V_11 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
}
F_10 ( V_6 , V_11 , V_4 ) ;
}
void F_15 ( struct V_5 * V_6 ,
unsigned V_11 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_9 -> V_13 . V_16 |= V_11 ;
V_9 -> V_13 . V_15 &= ~ V_11 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
F_16 ( V_6 , V_11 ) ;
}
void F_17 ( struct V_5 * V_6 ,
unsigned V_11 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_11 &= V_9 -> V_13 . V_16 ;
V_9 -> V_13 . V_16 &= ~ V_11 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
F_10 ( V_6 , V_11 , V_18 ) ;
}
void F_18 ( struct V_5 * V_6 ,
unsigned V_11 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
F_5 ( & V_9 -> V_13 . V_14 ) ;
V_9 -> V_13 . V_15 &= ~ V_11 ;
F_6 ( & V_9 -> V_13 . V_14 ) ;
F_10 ( V_6 , V_11 , V_18 ) ;
}
