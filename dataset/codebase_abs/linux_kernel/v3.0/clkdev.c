static struct V_1 * F_1 ( const char * V_2 , const char * V_3 )
{
struct V_1 * V_4 , * V_5 = NULL ;
int V_6 , V_7 = 0 ;
F_2 (p, &clocks, node) {
V_6 = 0 ;
if ( V_4 -> V_2 ) {
if ( ! V_2 || strcmp ( V_4 -> V_2 , V_2 ) )
continue;
V_6 += 2 ;
}
if ( V_4 -> V_3 ) {
if ( ! V_3 || strcmp ( V_4 -> V_3 , V_3 ) )
continue;
V_6 += 1 ;
}
if ( V_6 > V_7 ) {
V_5 = V_4 ;
if ( V_6 != 3 )
V_7 = V_6 ;
else
break;
}
}
return V_5 ;
}
struct V_8 * F_3 ( const char * V_2 , const char * V_3 )
{
struct V_1 * V_5 ;
F_4 ( & V_9 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 && ! F_5 ( V_5 -> V_8 ) )
V_5 = NULL ;
F_6 ( & V_9 ) ;
return V_5 ? V_5 -> V_8 : F_7 ( - V_10 ) ;
}
struct V_8 * F_8 ( struct V_11 * V_12 , const char * V_3 )
{
const char * V_2 = V_12 ? F_9 ( V_12 ) : NULL ;
return F_3 ( V_2 , V_3 ) ;
}
void F_10 ( struct V_8 * V_8 )
{
F_11 ( V_8 ) ;
}
void F_12 ( struct V_1 * V_5 )
{
F_4 ( & V_9 ) ;
F_13 ( & V_5 -> V_13 , & V_14 ) ;
F_6 ( & V_9 ) ;
}
void T_1 F_14 ( struct V_1 * V_5 , T_2 V_15 )
{
F_4 ( & V_9 ) ;
while ( V_15 -- ) {
F_13 ( & V_5 -> V_13 , & V_14 ) ;
V_5 ++ ;
}
F_6 ( & V_9 ) ;
}
struct V_1 * T_3
F_15 ( struct V_8 * V_8 , const char * V_3 , const char * V_16 , ... )
{
struct V_17 * V_18 ;
V_18 = F_16 ( sizeof( * V_18 ) ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_5 . V_8 = V_8 ;
if ( V_3 ) {
F_17 ( V_18 -> V_3 , V_3 , sizeof( V_18 -> V_3 ) ) ;
V_18 -> V_5 . V_3 = V_18 -> V_3 ;
}
if ( V_16 ) {
T_4 V_19 ;
va_start ( V_19 , V_16 ) ;
F_18 ( V_18 -> V_2 , sizeof( V_18 -> V_2 ) , V_16 , V_19 ) ;
V_18 -> V_5 . V_2 = V_18 -> V_2 ;
va_end ( V_19 ) ;
}
return & V_18 -> V_5 ;
}
int F_19 ( const char * V_20 , const char * V_21 , char * V_22 ,
struct V_11 * V_12 )
{
struct V_8 * V_23 = F_8 ( V_12 , V_22 ) ;
struct V_1 * V_24 ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_24 = F_15 ( V_23 , V_20 , V_21 ) ;
F_10 ( V_23 ) ;
if ( ! V_24 )
return - V_25 ;
F_12 ( V_24 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_5 )
{
F_4 ( & V_9 ) ;
F_23 ( & V_5 -> V_13 ) ;
F_6 ( & V_9 ) ;
F_24 ( V_5 ) ;
}
