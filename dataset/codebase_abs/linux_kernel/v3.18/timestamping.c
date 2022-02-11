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
unsigned int type ;
if ( ! V_2 -> V_9 )
return;
type = F_1 ( V_2 ) ;
if ( type == V_6 )
return;
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_10 ) ) {
V_8 = F_5 ( V_2 ) ;
if ( ! V_8 )
return;
V_4 -> V_5 -> V_10 ( V_4 , V_8 , type ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
unsigned int type ;
if ( F_7 ( V_2 ) < V_11 )
return false ;
F_8 ( V_2 , V_11 ) ;
type = F_1 ( V_2 ) ;
F_9 ( V_2 , V_11 ) ;
if ( type == V_6 )
return false ;
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_12 ) )
return V_4 -> V_5 -> V_12 ( V_4 , V_2 , type ) ;
return false ;
}
