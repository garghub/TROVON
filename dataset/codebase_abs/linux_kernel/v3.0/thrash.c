static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 )
F_3 ( F_4 ( V_4 ) ) ;
return V_4 ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return NULL ;
}
void F_5 ( struct V_2 * V_3 )
{
int V_5 ;
unsigned int V_6 = V_3 -> V_7 ;
V_8 ++ ;
V_5 = V_8 - V_3 -> V_9 ;
if ( ! F_6 ( & V_10 ) )
return;
if ( ! V_11 )
goto V_12;
if ( ( V_8 - V_13 ) > V_14 ) {
V_11 -> V_7 /= 2 ;
V_13 = V_8 ;
}
if ( V_3 == V_11 ) {
V_3 -> V_7 += 2 ;
goto V_15;
}
if ( V_5 < V_3 -> V_16 )
V_3 -> V_7 ++ ;
else {
if ( F_7 ( V_3 -> V_7 > 0 ) )
V_3 -> V_7 -- ;
}
if ( V_3 -> V_7 > V_11 -> V_7 )
goto V_12;
V_15:
F_8 ( V_3 , V_6 , V_11 ) ;
V_17:
V_3 -> V_9 = V_8 ;
V_3 -> V_16 = V_5 ;
F_9 ( & V_10 ) ;
return;
V_12:
V_3 -> V_7 += 2 ;
F_10 ( V_11 , V_3 ) ;
V_11 = V_3 ;
V_18 = F_1 ( V_3 ) ;
V_13 = V_8 ;
goto V_17;
}
void F_11 ( struct V_2 * V_3 )
{
F_12 ( & V_10 ) ;
if ( F_7 ( V_3 == V_11 ) ) {
F_13 ( V_11 ) ;
V_11 = NULL ;
V_18 = NULL ;
}
F_9 ( & V_10 ) ;
}
static bool F_14 ( struct V_1 * V_19 , struct V_1 * V_20 )
{
if ( ! V_19 )
return true ;
if ( ! V_20 )
return true ;
if ( V_19 == V_20 )
return true ;
return false ;
}
void F_15 ( struct V_1 * V_4 )
{
if ( F_14 ( V_4 , V_18 ) ) {
F_12 ( & V_10 ) ;
if ( F_14 ( V_4 , V_18 ) ) {
F_16 ( V_11 ) ;
V_11 = NULL ;
V_18 = NULL ;
}
F_9 ( & V_10 ) ;
}
}
