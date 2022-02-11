int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
int F_7 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( ! V_7 || ! V_2 )
return - V_8 ;
if ( V_2 -> V_7 )
return - V_9 ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_10 -> V_11 )
return V_2 -> V_10 -> V_11 ( V_2 ) ;
return 0 ;
}
bool F_8 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
struct V_12 * V_14 )
{
bool V_15 = true ;
if ( ! V_2 )
return true ;
if ( V_2 -> V_10 -> V_16 )
V_15 = V_2 -> V_10 -> V_16 ( V_2 , V_13 , V_14 ) ;
V_15 = V_15 && F_8 ( V_2 -> V_17 , V_13 , V_14 ) ;
return V_15 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_9 ( V_2 -> V_17 ) ;
if ( V_2 -> V_10 -> V_18 )
V_2 -> V_10 -> V_18 ( V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_19 )
V_2 -> V_10 -> V_19 ( V_2 ) ;
F_10 ( V_2 -> V_17 ) ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_12 * V_14 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_20 )
V_2 -> V_10 -> V_20 ( V_2 , V_13 , V_14 ) ;
F_11 ( V_2 -> V_17 , V_13 , V_14 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_12 ( V_2 -> V_17 ) ;
if ( V_2 -> V_10 -> V_21 )
V_2 -> V_10 -> V_21 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_22 )
V_2 -> V_10 -> V_22 ( V_2 ) ;
F_13 ( V_2 -> V_17 ) ;
}
struct V_1 * F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_15 (bridge, &bridge_list, list) {
if ( V_2 -> V_25 == V_24 ) {
F_4 ( & V_3 ) ;
return V_2 ;
}
}
F_4 ( & V_3 ) ;
return NULL ;
}
