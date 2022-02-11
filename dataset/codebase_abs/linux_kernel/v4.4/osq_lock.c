static inline int F_1 ( int V_1 )
{
return V_1 + 1 ;
}
static inline struct V_2 * F_2 ( int V_3 )
{
int V_1 = V_3 - 1 ;
return F_3 ( & V_4 , V_1 ) ;
}
static inline struct V_2 *
F_4 ( struct V_5 * V_6 ,
struct V_2 * V_7 ,
struct V_2 * V_8 )
{
struct V_2 * V_9 = NULL ;
int V_10 = F_1 ( F_5 () ) ;
int V_11 ;
V_11 = V_8 ? V_8 -> V_12 : V_13 ;
for (; ; ) {
if ( F_6 ( & V_6 -> V_14 ) == V_10 &&
F_7 ( & V_6 -> V_14 , V_10 , V_11 ) == V_10 ) {
break;
}
if ( V_7 -> V_9 ) {
V_9 = F_8 ( & V_7 -> V_9 , NULL ) ;
if ( V_9 )
break;
}
F_9 () ;
}
return V_9 ;
}
bool F_10 ( struct V_5 * V_6 )
{
struct V_2 * V_7 = F_11 ( & V_4 ) ;
struct V_2 * V_8 , * V_9 ;
int V_10 = F_1 ( F_5 () ) ;
int V_11 ;
V_7 -> V_15 = 0 ;
V_7 -> V_9 = NULL ;
V_7 -> V_12 = V_10 ;
V_11 = F_12 ( & V_6 -> V_14 , V_10 ) ;
if ( V_11 == V_13 )
return true ;
V_8 = F_2 ( V_11 ) ;
V_7 -> V_8 = V_8 ;
F_13 ( V_8 -> V_9 , V_7 ) ;
while ( ! F_14 ( V_7 -> V_15 ) ) {
if ( F_15 () )
goto V_16;
F_9 () ;
}
return true ;
V_16:
for (; ; ) {
if ( V_8 -> V_9 == V_7 &&
F_16 ( & V_8 -> V_9 , V_7 , NULL ) == V_7 )
break;
if ( F_17 ( & V_7 -> V_15 ) )
return true ;
F_9 () ;
V_8 = F_14 ( V_7 -> V_8 ) ;
}
V_9 = F_4 ( V_6 , V_7 , V_8 ) ;
if ( ! V_9 )
return false ;
F_13 ( V_9 -> V_8 , V_8 ) ;
F_13 ( V_8 -> V_9 , V_9 ) ;
return false ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_2 * V_7 , * V_9 ;
int V_10 = F_1 ( F_5 () ) ;
if ( F_19 ( F_20 ( & V_6 -> V_14 , V_10 ,
V_13 ) == V_10 ) )
return;
V_7 = F_11 ( & V_4 ) ;
V_9 = F_8 ( & V_7 -> V_9 , NULL ) ;
if ( V_9 ) {
F_13 ( V_9 -> V_15 , 1 ) ;
return;
}
V_9 = F_4 ( V_6 , V_7 , NULL ) ;
if ( V_9 )
F_13 ( V_9 -> V_15 , 1 ) ;
}
