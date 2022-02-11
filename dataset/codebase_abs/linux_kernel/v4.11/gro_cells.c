int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
if ( ! V_2 -> V_9 || F_2 ( V_4 ) || ! ( V_6 -> V_10 & V_11 ) )
return F_3 ( V_4 ) ;
V_8 = F_4 ( V_2 -> V_9 ) ;
if ( F_5 ( & V_8 -> V_12 ) > V_13 ) {
F_6 ( & V_6 -> V_14 ) ;
F_7 ( V_4 ) ;
return V_15 ;
}
F_8 ( & V_8 -> V_12 , V_4 ) ;
if ( F_5 ( & V_8 -> V_12 ) == 1 )
F_9 ( & V_8 -> V_16 ) ;
return V_17 ;
}
static int F_10 ( struct V_18 * V_16 , int V_19 )
{
struct V_7 * V_8 = F_11 ( V_16 , struct V_7 , V_16 ) ;
struct V_3 * V_4 ;
int V_20 = 0 ;
while ( V_20 < V_19 ) {
V_4 = F_12 ( & V_8 -> V_12 ) ;
if ( ! V_4 )
break;
F_13 ( V_16 , V_4 ) ;
V_20 ++ ;
}
if ( V_20 < V_19 )
F_14 ( V_16 , V_20 ) ;
return V_20 ;
}
int F_15 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_21 ;
V_2 -> V_9 = F_16 ( struct V_7 ) ;
if ( ! V_2 -> V_9 )
return - V_22 ;
F_17 (i) {
struct V_7 * V_8 = F_18 ( V_2 -> V_9 , V_21 ) ;
F_19 ( & V_8 -> V_12 ) ;
F_20 ( V_23 , & V_8 -> V_16 . V_24 ) ;
F_21 ( V_6 , & V_8 -> V_16 , F_10 ,
V_25 ) ;
F_22 ( & V_8 -> V_16 ) ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! V_2 -> V_9 )
return;
F_17 (i) {
struct V_7 * V_8 = F_18 ( V_2 -> V_9 , V_21 ) ;
F_24 ( & V_8 -> V_16 ) ;
F_25 ( & V_8 -> V_12 ) ;
}
F_26 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
