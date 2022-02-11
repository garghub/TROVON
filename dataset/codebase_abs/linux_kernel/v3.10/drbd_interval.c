static inline
T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
return V_4 -> V_6 ;
}
static inline T_1
F_3 ( struct V_3 * V_2 )
{
T_1 V_7 = V_2 -> V_8 + ( V_2 -> V_9 >> 9 ) ;
if ( V_2 -> V_5 . V_10 ) {
T_1 V_11 = F_1 ( V_2 -> V_5 . V_10 ) ;
if ( V_11 > V_7 )
V_7 = V_11 ;
}
if ( V_2 -> V_5 . V_12 ) {
T_1 V_13 = F_1 ( V_2 -> V_5 . V_12 ) ;
if ( V_13 > V_7 )
V_7 = V_13 ;
}
return V_7 ;
}
static void F_4 ( struct V_1 * V_5 , struct V_1 * V_14 )
{
while ( V_5 != V_14 ) {
struct V_3 * V_2 = F_2 ( V_5 , struct V_3 , V_5 ) ;
T_1 V_15 = F_3 ( V_2 ) ;
if ( V_2 -> V_6 == V_15 )
break;
V_2 -> V_6 = V_15 ;
V_5 = F_5 ( & V_2 -> V_5 ) ;
}
}
static void F_6 ( struct V_1 * V_16 , struct V_1 * V_17 )
{
struct V_3 * V_18 = F_2 ( V_16 , struct V_3 , V_5 ) ;
struct V_3 * V_19 = F_2 ( V_17 , struct V_3 , V_5 ) ;
V_19 -> V_6 = V_18 -> V_6 ;
}
static void F_7 ( struct V_1 * V_16 , struct V_1 * V_17 )
{
struct V_3 * V_18 = F_2 ( V_16 , struct V_3 , V_5 ) ;
struct V_3 * V_19 = F_2 ( V_17 , struct V_3 , V_5 ) ;
V_19 -> V_6 = V_18 -> V_6 ;
V_18 -> V_6 = F_3 ( V_18 ) ;
}
bool
F_8 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_1 * * V_19 = & V_21 -> V_1 , * V_22 = NULL ;
F_9 ( ! F_10 ( V_4 -> V_9 , 512 ) ) ;
while ( * V_19 ) {
struct V_3 * V_23 =
F_2 ( * V_19 , struct V_3 , V_5 ) ;
V_22 = * V_19 ;
if ( V_4 -> V_8 < V_23 -> V_8 )
V_19 = & ( * V_19 ) -> V_10 ;
else if ( V_4 -> V_8 > V_23 -> V_8 )
V_19 = & ( * V_19 ) -> V_12 ;
else if ( V_4 < V_23 )
V_19 = & ( * V_19 ) -> V_10 ;
else if ( V_4 > V_23 )
V_19 = & ( * V_19 ) -> V_12 ;
else
return false ;
}
F_11 ( & V_4 -> V_5 , V_22 , V_19 ) ;
F_12 ( & V_4 -> V_5 , V_21 , & V_24 ) ;
return true ;
}
bool
F_13 ( struct V_20 * V_21 , T_1 V_8 ,
struct V_3 * V_25 )
{
struct V_1 * V_2 = V_21 -> V_1 ;
while ( V_2 ) {
struct V_3 * V_23 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_8 < V_23 -> V_8 )
V_2 = V_2 -> V_10 ;
else if ( V_8 > V_23 -> V_8 )
V_2 = V_2 -> V_12 ;
else if ( V_25 < V_23 )
V_2 = V_2 -> V_10 ;
else if ( V_25 > V_23 )
V_2 = V_2 -> V_12 ;
else
return true ;
}
return false ;
}
void
F_14 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
F_15 ( & V_4 -> V_5 , V_21 , & V_24 ) ;
}
struct V_3 *
F_16 ( struct V_20 * V_21 , T_1 V_8 , unsigned int V_9 )
{
struct V_1 * V_2 = V_21 -> V_1 ;
struct V_3 * V_26 = NULL ;
T_1 V_6 = V_8 + ( V_9 >> 9 ) ;
F_9 ( ! F_10 ( V_9 , 512 ) ) ;
while ( V_2 ) {
struct V_3 * V_23 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_2 -> V_10 &&
V_8 < F_1 ( V_2 -> V_10 ) ) {
V_2 = V_2 -> V_10 ;
} else if ( V_23 -> V_8 < V_6 &&
V_8 < V_23 -> V_8 + ( V_23 -> V_9 >> 9 ) ) {
V_26 = V_23 ;
break;
} else if ( V_8 >= V_23 -> V_8 ) {
V_2 = V_2 -> V_12 ;
} else
break;
}
return V_26 ;
}
struct V_3 *
F_17 ( struct V_3 * V_27 , T_1 V_8 , unsigned int V_9 )
{
T_1 V_6 = V_8 + ( V_9 >> 9 ) ;
struct V_1 * V_2 ;
for (; ; ) {
V_2 = F_18 ( & V_27 -> V_5 ) ;
if ( ! V_2 )
return NULL ;
V_27 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_27 -> V_8 >= V_6 )
return NULL ;
if ( V_8 < V_27 -> V_8 + ( V_27 -> V_9 >> 9 ) )
return V_27 ;
}
}
