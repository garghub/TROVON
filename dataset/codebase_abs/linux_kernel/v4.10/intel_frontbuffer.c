void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 . V_9 ) ;
if ( V_4 == V_10 ) {
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_7 -> V_11 . V_13 |= V_5 ;
V_7 -> V_11 . V_14 &= ~ V_5 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
}
F_5 ( V_7 , V_5 ) ;
F_6 ( V_7 , V_5 ) ;
F_7 ( V_7 , V_5 , V_4 ) ;
}
static void F_8 ( struct V_6 * V_7 ,
unsigned V_5 ,
enum V_3 V_4 )
{
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_5 &= ~ V_7 -> V_11 . V_13 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
if ( ! V_5 )
return;
F_9 ( V_7 , V_5 ) ;
F_10 ( V_7 , V_5 , V_4 ) ;
F_11 ( V_7 , V_5 , V_4 ) ;
}
void F_12 ( struct V_1 * V_2 ,
bool V_15 ,
enum V_3 V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 . V_9 ) ;
if ( V_15 ) {
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_5 &= V_7 -> V_11 . V_13 ;
V_7 -> V_11 . V_13 &= ~ V_5 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
}
if ( V_5 )
F_8 ( V_7 , V_5 , V_4 ) ;
}
void F_13 ( struct V_6 * V_7 ,
unsigned V_5 )
{
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_7 -> V_11 . V_14 |= V_5 ;
V_7 -> V_11 . V_13 &= ~ V_5 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
F_14 ( V_7 , V_5 ) ;
}
void F_15 ( struct V_6 * V_7 ,
unsigned V_5 )
{
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_5 &= V_7 -> V_11 . V_14 ;
V_7 -> V_11 . V_14 &= ~ V_5 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
if ( V_5 )
F_8 ( V_7 ,
V_5 , V_16 ) ;
}
void F_16 ( struct V_6 * V_7 ,
unsigned V_5 )
{
F_3 ( & V_7 -> V_11 . V_12 ) ;
V_7 -> V_11 . V_13 &= ~ V_5 ;
F_4 ( & V_7 -> V_11 . V_12 ) ;
F_8 ( V_7 , V_5 , V_16 ) ;
}
