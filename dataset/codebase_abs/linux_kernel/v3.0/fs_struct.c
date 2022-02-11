static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_2 ) ;
}
static inline void F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 -> V_2 ) ;
F_6 ( V_1 ) ;
}
void F_7 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_1 V_5 ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_5 = V_4 -> V_8 ;
V_4 -> V_8 = * V_1 ;
F_1 ( V_1 ) ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
if ( V_5 . V_9 )
F_4 ( & V_5 ) ;
}
void F_12 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_1 V_10 ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_10 = V_4 -> V_11 ;
V_4 -> V_11 = * V_1 ;
F_1 ( V_1 ) ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
if ( V_10 . V_9 )
F_4 ( & V_10 ) ;
}
void F_13 ( struct V_1 * V_5 , struct V_1 * V_12 )
{
struct V_13 * V_14 , * V_15 ;
struct V_3 * V_4 ;
int V_16 = 0 ;
F_14 ( & V_17 ) ;
F_15 (g, p) {
F_16 ( V_15 ) ;
V_4 = V_15 -> V_4 ;
if ( V_4 ) {
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 . V_9 == V_5 -> V_9
&& V_4 -> V_8 . V_2 == V_5 -> V_2 ) {
F_1 ( V_12 ) ;
V_4 -> V_8 = * V_12 ;
V_16 ++ ;
}
if ( V_4 -> V_11 . V_9 == V_5 -> V_9
&& V_4 -> V_11 . V_2 == V_5 -> V_2 ) {
F_1 ( V_12 ) ;
V_4 -> V_11 = * V_12 ;
V_16 ++ ;
}
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
}
F_17 ( V_15 ) ;
} F_18 ( V_14 , V_15 ) ;
F_19 ( & V_17 ) ;
while ( V_16 -- )
F_4 ( V_5 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_8 ) ;
F_4 ( & V_4 -> V_11 ) ;
F_21 ( V_18 , V_4 ) ;
}
void F_22 ( struct V_13 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_4 ;
if ( V_4 ) {
int V_20 ;
F_16 ( V_19 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_19 -> V_4 = NULL ;
V_20 = ! -- V_4 -> V_21 ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
F_17 ( V_19 ) ;
if ( V_20 )
F_20 ( V_4 ) ;
}
}
struct V_3 * F_23 ( struct V_3 * V_22 )
{
struct V_3 * V_4 = F_24 ( V_18 , V_23 ) ;
if ( V_4 ) {
V_4 -> V_21 = 1 ;
V_4 -> V_24 = 0 ;
F_25 ( & V_4 -> V_6 ) ;
F_26 ( & V_4 -> V_7 ) ;
V_4 -> V_25 = V_22 -> V_25 ;
F_8 ( & V_22 -> V_6 ) ;
V_4 -> V_8 = V_22 -> V_8 ;
F_1 ( & V_4 -> V_8 ) ;
V_4 -> V_11 = V_22 -> V_11 ;
F_1 ( & V_4 -> V_11 ) ;
F_11 ( & V_22 -> V_6 ) ;
}
return V_4 ;
}
int F_27 ( void )
{
struct V_3 * V_4 = V_26 -> V_4 ;
struct V_3 * V_27 = F_23 ( V_4 ) ;
int V_20 ;
if ( ! V_27 )
return - V_28 ;
F_16 ( V_26 ) ;
F_8 ( & V_4 -> V_6 ) ;
V_20 = ! -- V_4 -> V_21 ;
V_26 -> V_4 = V_27 ;
F_11 ( & V_4 -> V_6 ) ;
F_17 ( V_26 ) ;
if ( V_20 )
F_20 ( V_4 ) ;
return 0 ;
}
int F_28 ( void )
{
return V_26 -> V_4 -> V_25 ;
}
void F_29 ( void )
{
struct V_3 * V_4 = V_26 -> V_4 ;
if ( V_4 ) {
int V_20 ;
F_16 ( V_26 ) ;
F_8 ( & V_29 . V_6 ) ;
V_29 . V_21 ++ ;
F_11 ( & V_29 . V_6 ) ;
F_8 ( & V_4 -> V_6 ) ;
V_26 -> V_4 = & V_29 ;
V_20 = ! -- V_4 -> V_21 ;
F_11 ( & V_4 -> V_6 ) ;
F_17 ( V_26 ) ;
if ( V_20 )
F_20 ( V_4 ) ;
}
}
