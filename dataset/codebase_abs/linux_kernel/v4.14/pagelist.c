static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
struct V_4 * V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
F_3 ( V_4 ) ;
V_2 -> V_3 = NULL ;
}
}
void F_4 ( struct V_1 * V_2 )
{
if ( ! F_5 ( & V_2 -> V_8 ) )
return;
F_1 ( V_2 ) ;
while ( ! F_6 ( & V_2 -> V_5 ) ) {
struct V_4 * V_4 = F_7 ( & V_2 -> V_5 , struct V_4 ,
V_7 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_4 ) ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_4 ;
if ( ! V_2 -> V_9 ) {
V_4 = F_13 ( V_10 ) ;
} else {
V_4 = F_7 ( & V_2 -> V_11 , struct V_4 , V_7 ) ;
F_8 ( & V_4 -> V_7 ) ;
-- V_2 -> V_9 ;
}
if ( ! V_4 )
return - V_12 ;
V_2 -> V_13 += V_14 ;
F_1 ( V_2 ) ;
F_14 ( & V_4 -> V_7 , & V_2 -> V_5 ) ;
V_2 -> V_3 = F_15 ( V_4 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , const void * V_15 , T_1 V_16 )
{
while ( V_2 -> V_13 < V_16 ) {
T_1 V_17 = V_2 -> V_13 ;
int V_18 ;
memcpy ( V_2 -> V_3 + ( V_2 -> V_19 & ~ V_20 ) ,
V_15 , V_17 ) ;
V_2 -> V_19 += V_17 ;
V_2 -> V_13 -= V_17 ;
V_15 += V_17 ;
V_16 -= V_17 ;
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
memcpy ( V_2 -> V_3 + ( V_2 -> V_19 & ~ V_20 ) , V_15 , V_16 ) ;
V_2 -> V_19 += V_16 ;
V_2 -> V_13 -= V_16 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_21 )
{
if ( V_21 <= V_2 -> V_13 )
return 0 ;
V_21 -= V_2 -> V_13 ;
V_21 = ( V_21 + V_14 - 1 ) >> V_22 ;
while ( V_21 > V_2 -> V_9 ) {
struct V_4 * V_4 = F_13 ( V_10 ) ;
if ( ! V_4 )
return - V_12 ;
F_14 ( & V_4 -> V_7 , & V_2 -> V_11 ) ;
++ V_2 -> V_9 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
while ( ! F_6 ( & V_2 -> V_11 ) ) {
struct V_4 * V_4 = F_7 ( & V_2 -> V_11 ,
struct V_4 , V_7 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_4 ) ;
-- V_2 -> V_9 ;
}
F_18 ( V_2 -> V_9 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
V_24 -> V_2 = V_2 ;
V_24 -> V_25 = V_2 -> V_5 . V_6 ;
V_24 -> V_13 = V_2 -> V_13 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_4 * V_4 ;
if ( V_2 != V_24 -> V_2 )
return - V_26 ;
F_1 ( V_2 ) ;
while ( V_2 -> V_5 . V_6 != V_24 -> V_25 ) {
V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
F_21 ( & V_4 -> V_7 , & V_2 -> V_11 ) ;
++ V_2 -> V_9 ;
}
V_2 -> V_13 = V_24 -> V_13 ;
if ( ! F_6 ( & V_2 -> V_5 ) ) {
V_4 = F_2 ( V_2 -> V_5 . V_6 , struct V_4 , V_7 ) ;
V_2 -> V_3 = F_15 ( V_4 ) ;
}
return 0 ;
}
