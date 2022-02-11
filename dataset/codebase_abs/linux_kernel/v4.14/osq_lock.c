static inline int F_1 ( int V_1 )
{
return V_1 + 1 ;
}
static inline int F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 - 1 ;
}
static inline struct V_2 * F_3 ( int V_5 )
{
int V_1 = V_5 - 1 ;
return F_4 ( & V_6 , V_1 ) ;
}
static inline struct V_2 *
F_5 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_2 * V_9 )
{
struct V_2 * V_10 = NULL ;
int V_11 = F_1 ( F_6 () ) ;
int V_12 ;
V_12 = V_9 ? V_9 -> V_4 : V_13 ;
for (; ; ) {
if ( F_7 ( & V_8 -> V_14 ) == V_11 &&
F_8 ( & V_8 -> V_14 , V_11 , V_12 ) == V_11 ) {
break;
}
if ( V_3 -> V_10 ) {
V_10 = F_9 ( & V_3 -> V_10 , NULL ) ;
if ( V_10 )
break;
}
F_10 () ;
}
return V_10 ;
}
bool F_11 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_12 ( & V_6 ) ;
struct V_2 * V_9 , * V_10 ;
int V_11 = F_1 ( F_6 () ) ;
int V_12 ;
V_3 -> V_15 = 0 ;
V_3 -> V_10 = NULL ;
V_3 -> V_4 = V_11 ;
V_12 = F_13 ( & V_8 -> V_14 , V_11 ) ;
if ( V_12 == V_13 )
return true ;
V_9 = F_3 ( V_12 ) ;
V_3 -> V_9 = V_9 ;
F_14 () ;
F_15 ( V_9 -> V_10 , V_3 ) ;
while ( ! F_16 ( V_3 -> V_15 ) ) {
if ( F_17 () || F_18 ( F_2 ( V_3 -> V_9 ) ) )
goto V_16;
F_10 () ;
}
return true ;
V_16:
for (; ; ) {
if ( V_9 -> V_10 == V_3 &&
F_19 ( & V_9 -> V_10 , V_3 , NULL ) == V_3 )
break;
if ( F_20 ( & V_3 -> V_15 ) )
return true ;
F_10 () ;
V_9 = F_16 ( V_3 -> V_9 ) ;
}
V_10 = F_5 ( V_8 , V_3 , V_9 ) ;
if ( ! V_10 )
return false ;
F_15 ( V_10 -> V_9 , V_9 ) ;
F_15 ( V_9 -> V_10 , V_10 ) ;
return false ;
}
void F_21 ( struct V_7 * V_8 )
{
struct V_2 * V_3 , * V_10 ;
int V_11 = F_1 ( F_6 () ) ;
if ( F_22 ( F_23 ( & V_8 -> V_14 , V_11 ,
V_13 ) == V_11 ) )
return;
V_3 = F_12 ( & V_6 ) ;
V_10 = F_9 ( & V_3 -> V_10 , NULL ) ;
if ( V_10 ) {
F_15 ( V_10 -> V_15 , 1 ) ;
return;
}
V_10 = F_5 ( V_8 , V_3 , NULL ) ;
if ( V_10 )
F_15 ( V_10 -> V_15 , 1 ) ;
}
