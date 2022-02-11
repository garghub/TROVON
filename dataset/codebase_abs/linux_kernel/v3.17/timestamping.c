static unsigned int F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 && V_2 -> V_3 -> V_4 &&
V_2 -> V_3 -> V_4 -> V_5 ) )
return F_3 ( V_2 ) ;
else
return V_6 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
struct V_1 * V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int type ;
if ( ! V_10 )
return;
type = F_1 ( V_2 ) ;
if ( type == V_6 )
return;
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_11 ) ) {
if ( ! F_5 ( & V_10 -> V_12 ) )
return;
V_8 = F_6 ( V_2 , V_13 ) ;
if ( ! V_8 ) {
F_7 ( V_10 ) ;
return;
}
V_8 -> V_10 = V_10 ;
V_4 -> V_5 -> V_11 ( V_4 , V_8 , type ) ;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_16 * V_17 ;
int V_18 ;
if ( ! V_15 ) {
F_7 ( V_10 ) ;
F_9 ( V_2 ) ;
return;
}
* F_10 ( V_2 ) = * V_15 ;
V_17 = F_11 ( V_2 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_19 . V_20 = V_21 ;
V_17 -> V_19 . V_22 = V_23 ;
V_2 -> V_10 = NULL ;
V_18 = F_12 ( V_10 , V_2 ) ;
F_7 ( V_10 ) ;
if ( V_18 )
F_9 ( V_2 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
unsigned int type ;
if ( F_14 ( V_2 ) < V_24 )
return false ;
F_15 ( V_2 , V_24 ) ;
type = F_1 ( V_2 ) ;
F_16 ( V_2 , V_24 ) ;
if ( type == V_6 )
return false ;
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_25 ) )
return V_4 -> V_5 -> V_25 ( V_4 , V_2 , type ) ;
return false ;
}
