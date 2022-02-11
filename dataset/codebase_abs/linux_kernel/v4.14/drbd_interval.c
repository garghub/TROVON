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
bool
F_4 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_1 * * V_16 = & V_15 -> V_1 , * V_17 = NULL ;
T_1 V_18 = V_4 -> V_8 + ( V_4 -> V_9 >> 9 ) ;
F_5 ( ! F_6 ( V_4 -> V_9 , 512 ) ) ;
while ( * V_16 ) {
struct V_3 * V_19 =
F_2 ( * V_16 , struct V_3 , V_5 ) ;
V_17 = * V_16 ;
if ( V_19 -> V_6 < V_18 )
V_19 -> V_6 = V_18 ;
if ( V_4 -> V_8 < V_19 -> V_8 )
V_16 = & ( * V_16 ) -> V_10 ;
else if ( V_4 -> V_8 > V_19 -> V_8 )
V_16 = & ( * V_16 ) -> V_12 ;
else if ( V_4 < V_19 )
V_16 = & ( * V_16 ) -> V_10 ;
else if ( V_4 > V_19 )
V_16 = & ( * V_16 ) -> V_12 ;
else
return false ;
}
V_4 -> V_6 = V_18 ;
F_7 ( & V_4 -> V_5 , V_17 , V_16 ) ;
F_8 ( & V_4 -> V_5 , V_15 , & V_20 ) ;
return true ;
}
bool
F_9 ( struct V_14 * V_15 , T_1 V_8 ,
struct V_3 * V_21 )
{
struct V_1 * V_2 = V_15 -> V_1 ;
while ( V_2 ) {
struct V_3 * V_19 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_8 < V_19 -> V_8 )
V_2 = V_2 -> V_10 ;
else if ( V_8 > V_19 -> V_8 )
V_2 = V_2 -> V_12 ;
else if ( V_21 < V_19 )
V_2 = V_2 -> V_10 ;
else if ( V_21 > V_19 )
V_2 = V_2 -> V_12 ;
else
return true ;
}
return false ;
}
void
F_10 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_5 , V_15 , & V_20 ) ;
}
struct V_3 *
F_12 ( struct V_14 * V_15 , T_1 V_8 , unsigned int V_9 )
{
struct V_1 * V_2 = V_15 -> V_1 ;
struct V_3 * V_22 = NULL ;
T_1 V_6 = V_8 + ( V_9 >> 9 ) ;
F_5 ( ! F_6 ( V_9 , 512 ) ) ;
while ( V_2 ) {
struct V_3 * V_19 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_2 -> V_10 &&
V_8 < F_1 ( V_2 -> V_10 ) ) {
V_2 = V_2 -> V_10 ;
} else if ( V_19 -> V_8 < V_6 &&
V_8 < V_19 -> V_8 + ( V_19 -> V_9 >> 9 ) ) {
V_22 = V_19 ;
break;
} else if ( V_8 >= V_19 -> V_8 ) {
V_2 = V_2 -> V_12 ;
} else
break;
}
return V_22 ;
}
struct V_3 *
F_13 ( struct V_3 * V_23 , T_1 V_8 , unsigned int V_9 )
{
T_1 V_6 = V_8 + ( V_9 >> 9 ) ;
struct V_1 * V_2 ;
for (; ; ) {
V_2 = F_14 ( & V_23 -> V_5 ) ;
if ( ! V_2 )
return NULL ;
V_23 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_23 -> V_8 >= V_6 )
return NULL ;
if ( V_8 < V_23 -> V_8 + ( V_23 -> V_9 >> 9 ) )
return V_23 ;
}
}
