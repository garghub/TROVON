static inline struct V_1 *
F_1 ( struct V_1 * * V_2 ,
struct V_1 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 = NULL ;
for (; ; ) {
if ( * V_2 == V_3 && F_2 ( V_2 , V_3 , V_4 ) == V_3 ) {
break;
}
if ( V_3 -> V_5 ) {
V_5 = F_3 ( & V_3 -> V_5 , NULL ) ;
if ( V_5 )
break;
}
F_4 () ;
}
return V_5 ;
}
bool F_5 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = F_6 ( & V_6 ) ;
struct V_1 * V_4 , * V_5 ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = NULL ;
V_3 -> V_4 = V_4 = F_3 ( V_2 , V_3 ) ;
if ( F_7 ( V_4 == NULL ) )
return true ;
F_8 ( V_4 -> V_5 ) = V_3 ;
while ( ! F_9 ( & V_3 -> V_7 ) ) {
if ( F_10 () )
goto V_8;
F_4 () ;
}
return true ;
V_8:
for (; ; ) {
if ( V_4 -> V_5 == V_3 &&
F_2 ( & V_4 -> V_5 , V_3 , NULL ) == V_3 )
break;
if ( F_9 ( & V_3 -> V_7 ) )
return true ;
F_4 () ;
V_4 = F_8 ( V_3 -> V_4 ) ;
}
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_5 )
return false ;
F_8 ( V_5 -> V_4 ) = V_4 ;
F_8 ( V_4 -> V_5 ) = V_5 ;
return false ;
}
void F_11 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = F_6 ( & V_6 ) ;
struct V_1 * V_5 ;
if ( F_7 ( F_2 ( V_2 , V_3 , NULL ) == V_3 ) )
return;
V_5 = F_3 ( & V_3 -> V_5 , NULL ) ;
if ( V_5 ) {
F_8 ( V_5 -> V_7 ) = 1 ;
return;
}
V_5 = F_1 ( V_2 , V_3 , NULL ) ;
if ( V_5 )
F_8 ( V_5 -> V_7 ) = 1 ;
}
