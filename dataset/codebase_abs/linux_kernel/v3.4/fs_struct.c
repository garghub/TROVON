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
F_1 ( V_1 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_5 = V_4 -> V_8 ;
V_4 -> V_8 = * V_1 ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
if ( V_5 . V_9 )
F_4 ( & V_5 ) ;
}
void F_12 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_1 V_10 ;
F_1 ( V_1 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_10 = V_4 -> V_11 ;
V_4 -> V_11 = * V_1 ;
F_10 ( & V_4 -> V_7 ) ;
F_11 ( & V_4 -> V_6 ) ;
if ( V_10 . V_9 )
F_4 ( & V_10 ) ;
}
static inline int F_13 ( struct V_1 * V_12 , const struct V_1 * V_13 , const struct V_1 * V_14 )
{
if ( F_14 ( V_12 -> V_9 != V_13 -> V_9 || V_12 -> V_2 != V_13 -> V_2 ) )
return 0 ;
* V_12 = * V_14 ;
return 1 ;
}
void F_15 ( struct V_1 * V_5 , struct V_1 * V_15 )
{
struct V_16 * V_17 , * V_12 ;
struct V_3 * V_4 ;
int V_18 = 0 ;
F_16 ( & V_19 ) ;
F_17 (g, p) {
F_18 ( V_12 ) ;
V_4 = V_12 -> V_4 ;
if ( V_4 ) {
int V_20 = 0 ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_7 ) ;
V_20 += F_13 ( & V_4 -> V_8 , V_5 , V_15 ) ;
V_20 += F_13 ( & V_4 -> V_11 , V_5 , V_15 ) ;
F_10 ( & V_4 -> V_7 ) ;
while ( V_20 -- ) {
V_18 ++ ;
F_1 ( V_15 ) ;
}
F_11 ( & V_4 -> V_6 ) ;
}
F_19 ( V_12 ) ;
} F_20 ( V_17 , V_12 ) ;
F_21 ( & V_19 ) ;
while ( V_18 -- )
F_4 ( V_5 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_8 ) ;
F_4 ( & V_4 -> V_11 ) ;
F_23 ( V_21 , V_4 ) ;
}
void F_24 ( struct V_16 * V_22 )
{
struct V_3 * V_4 = V_22 -> V_4 ;
if ( V_4 ) {
int V_23 ;
F_18 ( V_22 ) ;
F_8 ( & V_4 -> V_6 ) ;
V_22 -> V_4 = NULL ;
V_23 = ! -- V_4 -> V_24 ;
F_11 ( & V_4 -> V_6 ) ;
F_19 ( V_22 ) ;
if ( V_23 )
F_22 ( V_4 ) ;
}
}
struct V_3 * F_25 ( struct V_3 * V_13 )
{
struct V_3 * V_4 = F_26 ( V_21 , V_25 ) ;
if ( V_4 ) {
V_4 -> V_24 = 1 ;
V_4 -> V_26 = 0 ;
F_27 ( & V_4 -> V_6 ) ;
F_28 ( & V_4 -> V_7 ) ;
V_4 -> V_27 = V_13 -> V_27 ;
F_8 ( & V_13 -> V_6 ) ;
V_4 -> V_8 = V_13 -> V_8 ;
F_1 ( & V_4 -> V_8 ) ;
V_4 -> V_11 = V_13 -> V_11 ;
F_1 ( & V_4 -> V_11 ) ;
F_11 ( & V_13 -> V_6 ) ;
}
return V_4 ;
}
int F_29 ( void )
{
struct V_3 * V_4 = V_28 -> V_4 ;
struct V_3 * V_29 = F_25 ( V_4 ) ;
int V_23 ;
if ( ! V_29 )
return - V_30 ;
F_18 ( V_28 ) ;
F_8 ( & V_4 -> V_6 ) ;
V_23 = ! -- V_4 -> V_24 ;
V_28 -> V_4 = V_29 ;
F_11 ( & V_4 -> V_6 ) ;
F_19 ( V_28 ) ;
if ( V_23 )
F_22 ( V_4 ) ;
return 0 ;
}
int F_30 ( void )
{
return V_28 -> V_4 -> V_27 ;
}
void F_31 ( void )
{
struct V_3 * V_4 = V_28 -> V_4 ;
if ( V_4 ) {
int V_23 ;
F_18 ( V_28 ) ;
F_8 ( & V_31 . V_6 ) ;
V_31 . V_24 ++ ;
F_11 ( & V_31 . V_6 ) ;
F_8 ( & V_4 -> V_6 ) ;
V_28 -> V_4 = & V_31 ;
V_23 = ! -- V_4 -> V_24 ;
F_11 ( & V_4 -> V_6 ) ;
F_19 ( V_28 ) ;
if ( V_23 )
F_22 ( V_4 ) ;
}
}
