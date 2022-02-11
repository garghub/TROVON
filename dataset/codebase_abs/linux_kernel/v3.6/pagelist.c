static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
struct V_4 * V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
F_3 ( V_4 ) ;
V_2 -> V_3 = NULL ;
}
}
int F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
while ( ! F_5 ( & V_2 -> V_5 ) ) {
struct V_4 * V_4 = F_6 ( & V_2 -> V_5 , struct V_4 ,
V_7 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_8 ( V_4 ) ;
}
F_9 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
if ( ! V_2 -> V_8 ) {
V_4 = F_11 ( V_9 ) ;
} else {
V_4 = F_6 ( & V_2 -> V_10 , struct V_4 , V_7 ) ;
F_7 ( & V_4 -> V_7 ) ;
-- V_2 -> V_8 ;
}
if ( ! V_4 )
return - V_11 ;
V_2 -> V_12 += V_13 ;
F_1 ( V_2 ) ;
F_12 ( & V_4 -> V_7 , & V_2 -> V_5 ) ;
V_2 -> V_3 = F_13 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , const void * V_14 , T_1 V_15 )
{
while ( V_2 -> V_12 < V_15 ) {
T_1 V_16 = V_2 -> V_12 ;
int V_17 ;
memcpy ( V_2 -> V_3 + ( V_2 -> V_18 & ~ V_19 ) ,
V_14 , V_16 ) ;
V_2 -> V_18 += V_16 ;
V_2 -> V_12 -= V_16 ;
V_14 += V_16 ;
V_15 -= V_16 ;
V_17 = F_10 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
memcpy ( V_2 -> V_3 + ( V_2 -> V_18 & ~ V_19 ) , V_14 , V_15 ) ;
V_2 -> V_18 += V_15 ;
V_2 -> V_12 -= V_15 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_20 )
{
if ( V_20 <= V_2 -> V_12 )
return 0 ;
V_20 -= V_2 -> V_12 ;
V_20 = ( V_20 + V_13 - 1 ) >> V_21 ;
while ( V_20 > V_2 -> V_8 ) {
struct V_4 * V_4 = F_11 ( V_9 ) ;
if ( ! V_4 )
return - V_11 ;
F_12 ( & V_4 -> V_7 , & V_2 -> V_10 ) ;
++ V_2 -> V_8 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
while ( ! F_5 ( & V_2 -> V_10 ) ) {
struct V_4 * V_4 = F_6 ( & V_2 -> V_10 ,
struct V_4 , V_7 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_8 ( V_4 ) ;
-- V_2 -> V_8 ;
}
F_16 ( V_2 -> V_8 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
V_23 -> V_2 = V_2 ;
V_23 -> V_24 = V_2 -> V_5 . V_6 ;
V_23 -> V_12 = V_2 -> V_12 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_4 * V_4 ;
if ( V_2 != V_23 -> V_2 )
return - V_25 ;
F_1 ( V_2 ) ;
while ( V_2 -> V_5 . V_6 != V_23 -> V_24 ) {
V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_12 ( & V_4 -> V_7 , & V_2 -> V_10 ) ;
++ V_2 -> V_8 ;
}
V_2 -> V_12 = V_23 -> V_12 ;
if ( ! F_5 ( & V_2 -> V_5 ) ) {
V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
V_2 -> V_3 = F_13 ( V_4 ) ;
}
return 0 ;
}
