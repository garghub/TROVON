static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 )
return - 1 ;
if ( V_2 -> V_4 )
return V_2 -> V_4 ;
return 9 ;
}
static void F_2 ( struct V_1 * V_2 , int V_5 )
{
struct V_6 * V_7 ;
F_3 (pal, &rc->pals, node) {
if ( V_7 -> V_5 && V_5 != V_7 -> V_5 ) {
V_7 -> V_5 = V_5 ;
if ( V_7 -> V_8 )
V_7 -> V_8 ( V_7 , V_7 -> V_5 ) ;
}
}
}
static int F_4 ( struct V_1 * V_2 , int V_5 )
{
int V_9 = 0 ;
struct V_10 * V_11 = & V_2 -> V_12 . V_11 ;
F_5 ( V_11 , L_1 , V_13 ,
V_5 , V_2 -> V_14 ) ;
if ( V_5 == - 1 )
F_2 ( V_2 , V_5 ) ;
if ( V_5 != V_2 -> V_14 ) {
if ( V_2 -> V_14 != - 1 && V_5 != - 1 ) {
V_9 = F_4 ( V_2 , - 1 ) ;
if ( V_9 < 0 )
return V_9 ;
}
V_9 = F_6 ( V_2 , V_5 , 0 ) ;
}
if ( V_5 != - 1 )
F_2 ( V_2 , V_2 -> V_14 ) ;
return V_9 ;
}
int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_9 = 0 ;
F_8 ( & V_2 -> V_12 . V_15 ) ;
if ( ! V_7 -> V_5 ) {
V_7 -> V_5 = - 1 ;
V_2 -> V_3 ++ ;
V_9 = F_4 ( V_2 , F_1 ( V_2 ) ) ;
}
F_9 ( & V_2 -> V_12 . V_15 ) ;
return V_9 ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_8 ( & V_2 -> V_12 . V_15 ) ;
if ( V_7 -> V_5 ) {
V_2 -> V_3 -- ;
F_4 ( V_2 , F_1 ( V_2 ) ) ;
V_7 -> V_5 = 0 ;
}
F_9 ( & V_2 -> V_12 . V_15 ) ;
}
int F_11 ( struct V_1 * V_2 , int V_5 )
{
int V_9 = 0 ;
F_8 ( & V_2 -> V_12 . V_15 ) ;
V_2 -> V_4 = V_5 ;
V_9 = F_4 ( V_2 , F_1 ( V_2 ) ) ;
F_9 ( & V_2 -> V_12 . V_15 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 )
{
return F_13 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_8 ( & V_2 -> V_12 . V_15 ) ;
F_3 (pal, &rc->pals, node) {
if ( V_7 -> V_5 ) {
V_7 -> V_5 = - 1 ;
if ( V_7 -> V_8 )
V_7 -> V_8 ( V_7 , - 1 ) ;
}
}
V_2 -> V_14 = - 1 ;
V_2 -> V_16 = - 1 ;
F_9 ( & V_2 -> V_12 . V_15 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_13 ( V_2 ) ;
}
