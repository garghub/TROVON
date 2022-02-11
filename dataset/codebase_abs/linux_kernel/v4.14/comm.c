static struct V_1 * F_1 ( struct V_1 * V_2 )
{
if ( V_2 )
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 && F_4 ( & V_2 -> V_3 ) ) {
F_5 ( & V_2 -> V_4 , & V_5 ) ;
F_6 ( & V_2 -> V_6 ) ;
free ( V_2 ) ;
}
}
static struct V_1 * F_7 ( const char * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = F_9 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
free ( V_2 ) ;
return NULL ;
}
F_10 ( & V_2 -> V_3 , 1 ) ;
return V_2 ;
}
static struct V_1 * F_11 ( const char * V_6 , struct V_7 * V_8 )
{
struct V_4 * * V_9 = & V_8 -> V_4 ;
struct V_4 * V_10 = NULL ;
struct V_1 * V_11 , * V_12 ;
int V_13 ;
while ( * V_9 != NULL ) {
V_10 = * V_9 ;
V_11 = F_12 ( V_10 , struct V_1 , V_4 ) ;
V_13 = strcmp ( V_6 , V_11 -> V_6 ) ;
if ( ! V_13 )
return F_1 ( V_11 ) ;
if ( V_13 < 0 )
V_9 = & ( * V_9 ) -> V_14 ;
else
V_9 = & ( * V_9 ) -> V_15 ;
}
V_12 = F_7 ( V_6 ) ;
if ( ! V_12 )
return NULL ;
F_13 ( & V_12 -> V_4 , V_10 , V_9 ) ;
F_14 ( & V_12 -> V_4 , V_8 ) ;
return V_12 ;
}
struct V_16 * F_15 ( const char * V_6 , T_1 V_17 , bool V_18 )
{
struct V_16 * V_16 = F_8 ( sizeof( * V_16 ) ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_19 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_1 = F_11 ( V_6 , & V_5 ) ;
if ( ! V_16 -> V_1 ) {
free ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
int F_16 ( struct V_16 * V_16 , const char * V_6 , T_1 V_17 , bool V_18 )
{
struct V_1 * V_12 , * V_20 = V_16 -> V_1 ;
V_12 = F_11 ( V_6 , & V_5 ) ;
if ( ! V_12 )
return - V_21 ;
F_3 ( V_20 ) ;
V_16 -> V_1 = V_12 ;
V_16 -> V_19 = V_17 ;
if ( V_18 )
V_16 -> V_18 = true ;
return 0 ;
}
void F_17 ( struct V_16 * V_16 )
{
F_3 ( V_16 -> V_1 ) ;
free ( V_16 ) ;
}
const char * F_18 ( const struct V_16 * V_16 )
{
return V_16 -> V_1 -> V_6 ;
}
