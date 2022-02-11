int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
if ( ! V_2 -> V_9 || F_2 ( V_4 ) || F_3 ( V_6 ) )
return F_4 ( V_4 ) ;
V_8 = F_5 ( V_2 -> V_9 ) ;
if ( F_6 ( & V_8 -> V_10 ) > V_11 ) {
F_7 ( & V_6 -> V_12 ) ;
F_8 ( V_4 ) ;
return V_13 ;
}
F_9 ( & V_8 -> V_10 , V_4 ) ;
if ( F_6 ( & V_8 -> V_10 ) == 1 )
F_10 ( & V_8 -> V_14 ) ;
return V_15 ;
}
static int F_11 ( struct V_16 * V_14 , int V_17 )
{
struct V_7 * V_8 = F_12 ( V_14 , struct V_7 , V_14 ) ;
struct V_3 * V_4 ;
int V_18 = 0 ;
while ( V_18 < V_17 ) {
V_4 = F_13 ( & V_8 -> V_10 ) ;
if ( ! V_4 )
break;
F_14 ( V_14 , V_4 ) ;
V_18 ++ ;
}
if ( V_18 < V_17 )
F_15 ( V_14 , V_18 ) ;
return V_18 ;
}
int F_16 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_19 ;
V_2 -> V_9 = F_17 ( struct V_7 ) ;
if ( ! V_2 -> V_9 )
return - V_20 ;
F_18 (i) {
struct V_7 * V_8 = F_19 ( V_2 -> V_9 , V_19 ) ;
F_20 ( & V_8 -> V_10 ) ;
F_21 ( V_21 , & V_8 -> V_14 . V_22 ) ;
F_22 ( V_6 , & V_8 -> V_14 , F_11 ,
V_23 ) ;
F_23 ( & V_8 -> V_14 ) ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_9 )
return;
F_18 (i) {
struct V_7 * V_8 = F_19 ( V_2 -> V_9 , V_19 ) ;
F_25 ( & V_8 -> V_14 ) ;
F_26 ( & V_8 -> V_10 ) ;
}
F_27 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
