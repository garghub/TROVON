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
void F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( ! V_2 ) )
return;
if ( F_9 ( ! V_2 -> V_7 ) )
return;
if ( V_2 -> V_10 -> V_12 )
V_2 -> V_10 -> V_12 ( V_2 ) ;
V_2 -> V_7 = NULL ;
}
bool F_10 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
struct V_13 * V_15 )
{
bool V_16 = true ;
if ( ! V_2 )
return true ;
if ( V_2 -> V_10 -> V_17 )
V_16 = V_2 -> V_10 -> V_17 ( V_2 , V_14 , V_15 ) ;
V_16 = V_16 && F_10 ( V_2 -> V_18 , V_14 , V_15 ) ;
return V_16 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_11 ( V_2 -> V_18 ) ;
if ( V_2 -> V_10 -> V_19 )
V_2 -> V_10 -> V_19 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_20 )
V_2 -> V_10 -> V_20 ( V_2 ) ;
F_12 ( V_2 -> V_18 ) ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_13 * V_15 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_21 )
V_2 -> V_10 -> V_21 ( V_2 , V_14 , V_15 ) ;
F_13 ( V_2 -> V_18 , V_14 , V_15 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_14 ( V_2 -> V_18 ) ;
if ( V_2 -> V_10 -> V_22 )
V_2 -> V_10 -> V_22 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_10 -> V_23 )
V_2 -> V_10 -> V_23 ( V_2 ) ;
F_15 ( V_2 -> V_18 ) ;
}
struct V_1 * F_16 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_17 (bridge, &bridge_list, list) {
if ( V_2 -> V_26 == V_25 ) {
F_4 ( & V_3 ) ;
return V_2 ;
}
}
F_4 ( & V_3 ) ;
return NULL ;
}
