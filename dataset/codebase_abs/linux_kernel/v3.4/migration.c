void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_3 ( ! F_4 ( & V_4 -> V_1 ) ) )
return;
if ( ! F_5 ( & V_4 -> V_1 ) ) {
F_6 ( 1 ) ;
return;
}
F_7 ( & V_4 -> V_1 ) ;
if ( F_8 ( F_9 ( V_4 -> V_7 ) ) )
return;
if ( ! V_6 -> V_8 )
return;
F_10 ( & V_4 -> V_9 ) ;
if ( F_3 ( F_11 ( V_4 -> V_7 , V_10 )
< V_11 ) ) {
int V_12 = V_6 -> V_8 ( & V_4 -> V_1 ,
V_4 -> V_7 , false ) ;
switch ( V_12 ) {
case V_13 :
F_12 ( V_4 -> V_1 . V_14 , V_4 -> V_7 ) ;
case V_15 :
F_13 ( V_4 ) ;
}
}
F_14 ( V_4 -> V_7 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
bool V_16 ;
if ( F_3 ( ! F_4 ( V_2 ) ) )
return;
if ( F_8 ( F_16 ( V_2 ) ) )
return;
V_16 = F_17 ( V_2 ) ;
if ( ! V_16 )
V_2 -> V_6 -> V_17 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( ! V_16 )
V_2 -> V_6 -> V_18 ( V_2 ) ;
}
