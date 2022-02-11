void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_3 V_4 ;
F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_4 = V_2 -> V_7 ;
V_2 -> V_7 = * V_3 ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_5 ) ;
if ( V_4 . V_8 )
F_7 ( & V_4 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_3 V_9 ;
F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_9 = V_2 -> V_10 ;
V_2 -> V_10 = * V_3 ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_5 ) ;
if ( V_9 . V_8 )
F_7 ( & V_9 ) ;
}
static inline int F_9 ( struct V_3 * V_11 , const struct V_3 * V_12 , const struct V_3 * V_13 )
{
if ( F_10 ( V_11 -> V_8 != V_12 -> V_8 || V_11 -> V_14 != V_12 -> V_14 ) )
return 0 ;
* V_11 = * V_13 ;
return 1 ;
}
void F_11 ( struct V_3 * V_4 , struct V_3 * V_15 )
{
struct V_16 * V_17 , * V_11 ;
struct V_1 * V_2 ;
int V_18 = 0 ;
F_12 ( & V_19 ) ;
F_13 (g, p) {
F_14 ( V_11 ) ;
V_2 = V_11 -> V_2 ;
if ( V_2 ) {
int V_20 = 0 ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_20 += F_9 ( & V_2 -> V_7 , V_4 , V_15 ) ;
V_20 += F_9 ( & V_2 -> V_10 , V_4 , V_15 ) ;
F_5 ( & V_2 -> V_6 ) ;
while ( V_20 -- ) {
V_18 ++ ;
F_2 ( V_15 ) ;
}
F_6 ( & V_2 -> V_5 ) ;
}
F_15 ( V_11 ) ;
} F_16 ( V_17 , V_11 ) ;
F_17 ( & V_19 ) ;
while ( V_18 -- )
F_7 ( V_4 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_10 ) ;
F_19 ( V_21 , V_2 ) ;
}
void F_20 ( struct V_16 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
if ( V_2 ) {
int V_23 ;
F_14 ( V_22 ) ;
F_3 ( & V_2 -> V_5 ) ;
V_22 -> V_2 = NULL ;
V_23 = ! -- V_2 -> V_24 ;
F_6 ( & V_2 -> V_5 ) ;
F_15 ( V_22 ) ;
if ( V_23 )
F_18 ( V_2 ) ;
}
}
struct V_1 * F_21 ( struct V_1 * V_12 )
{
struct V_1 * V_2 = F_22 ( V_21 , V_25 ) ;
if ( V_2 ) {
V_2 -> V_24 = 1 ;
V_2 -> V_26 = 0 ;
F_23 ( & V_2 -> V_5 ) ;
F_24 ( & V_2 -> V_6 ) ;
V_2 -> V_27 = V_12 -> V_27 ;
F_3 ( & V_12 -> V_5 ) ;
V_2 -> V_7 = V_12 -> V_7 ;
F_2 ( & V_2 -> V_7 ) ;
V_2 -> V_10 = V_12 -> V_10 ;
F_2 ( & V_2 -> V_10 ) ;
F_6 ( & V_12 -> V_5 ) ;
}
return V_2 ;
}
int F_25 ( void )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_1 * V_29 = F_21 ( V_2 ) ;
int V_23 ;
if ( ! V_29 )
return - V_30 ;
F_14 ( V_28 ) ;
F_3 ( & V_2 -> V_5 ) ;
V_23 = ! -- V_2 -> V_24 ;
V_28 -> V_2 = V_29 ;
F_6 ( & V_2 -> V_5 ) ;
F_15 ( V_28 ) ;
if ( V_23 )
F_18 ( V_2 ) ;
return 0 ;
}
int F_26 ( void )
{
return V_28 -> V_2 -> V_27 ;
}
void F_27 ( void )
{
struct V_1 * V_2 = V_28 -> V_2 ;
if ( V_2 ) {
int V_23 ;
F_14 ( V_28 ) ;
F_3 ( & V_31 . V_5 ) ;
V_31 . V_24 ++ ;
F_6 ( & V_31 . V_5 ) ;
F_3 ( & V_2 -> V_5 ) ;
V_28 -> V_2 = & V_31 ;
V_23 = ! -- V_2 -> V_24 ;
F_6 ( & V_2 -> V_5 ) ;
F_15 ( V_28 ) ;
if ( V_23 )
F_18 ( V_2 ) ;
}
}
