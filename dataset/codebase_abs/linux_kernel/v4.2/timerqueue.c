bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * * V_6 = & V_2 -> V_2 . V_5 ;
struct V_5 * V_7 = NULL ;
struct V_3 * V_8 ;
F_2 ( ! F_3 ( & V_4 -> V_4 ) ) ;
while ( * V_6 ) {
V_7 = * V_6 ;
V_8 = F_4 ( V_7 , struct V_3 , V_4 ) ;
if ( V_4 -> V_9 . V_10 < V_8 -> V_9 . V_10 )
V_6 = & ( * V_6 ) -> V_11 ;
else
V_6 = & ( * V_6 ) -> V_12 ;
}
F_5 ( & V_4 -> V_4 , V_7 , V_6 ) ;
F_6 ( & V_4 -> V_4 , & V_2 -> V_2 ) ;
if ( ! V_2 -> V_13 || V_4 -> V_9 . V_10 < V_2 -> V_13 -> V_9 . V_10 ) {
V_2 -> V_13 = V_4 ;
return true ;
}
return false ;
}
bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( F_3 ( & V_4 -> V_4 ) ) ;
if ( V_2 -> V_13 == V_4 ) {
struct V_5 * V_14 = F_8 ( & V_4 -> V_4 ) ;
V_2 -> V_13 = V_14 ?
F_4 ( V_14 , struct V_3 , V_4 ) : NULL ;
}
F_9 ( & V_4 -> V_4 , & V_2 -> V_2 ) ;
F_10 ( & V_4 -> V_4 ) ;
return V_2 -> V_13 != NULL ;
}
struct V_3 * F_11 ( struct V_3 * V_4 )
{
struct V_5 * V_13 ;
if ( ! V_4 )
return NULL ;
V_13 = F_8 ( & V_4 -> V_4 ) ;
if ( ! V_13 )
return NULL ;
return F_12 ( V_13 , struct V_3 , V_4 ) ;
}
