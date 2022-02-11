static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 ++ ;
}
static void F_2 ( struct V_1 * V_2 )
{
if ( ! -- V_2 -> V_3 ) {
F_3 ( & V_2 -> V_4 , & V_5 ) ;
free ( V_2 -> V_6 ) ;
free ( V_2 ) ;
}
}
static struct V_1 * F_4 ( const char * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_6 = F_6 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
free ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_1 * F_7 ( const char * V_6 , struct V_7 * V_8 )
{
struct V_4 * * V_9 = & V_8 -> V_4 ;
struct V_4 * V_10 = NULL ;
struct V_1 * V_11 , * V_12 ;
int V_13 ;
while ( * V_9 != NULL ) {
V_10 = * V_9 ;
V_11 = F_8 ( V_10 , struct V_1 , V_4 ) ;
V_13 = strcmp ( V_6 , V_11 -> V_6 ) ;
if ( ! V_13 )
return V_11 ;
if ( V_13 < 0 )
V_9 = & ( * V_9 ) -> V_14 ;
else
V_9 = & ( * V_9 ) -> V_15 ;
}
V_12 = F_4 ( V_6 ) ;
if ( ! V_12 )
return NULL ;
F_9 ( & V_12 -> V_4 , V_10 , V_9 ) ;
F_10 ( & V_12 -> V_4 , V_8 ) ;
return V_12 ;
}
struct V_16 * F_11 ( const char * V_6 , T_1 V_17 )
{
struct V_16 * V_16 = F_5 ( sizeof( * V_16 ) ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_18 = V_17 ;
V_16 -> V_1 = F_7 ( V_6 , & V_5 ) ;
if ( ! V_16 -> V_1 ) {
free ( V_16 ) ;
return NULL ;
}
F_1 ( V_16 -> V_1 ) ;
return V_16 ;
}
void F_12 ( struct V_16 * V_16 , const char * V_6 , T_1 V_17 )
{
struct V_1 * V_19 = V_16 -> V_1 ;
V_16 -> V_1 = F_7 ( V_6 , & V_5 ) ;
if ( ! V_16 -> V_1 ) {
V_16 -> V_1 = V_19 ;
return;
}
V_16 -> V_18 = V_17 ;
F_1 ( V_16 -> V_1 ) ;
F_2 ( V_19 ) ;
}
void F_13 ( struct V_16 * V_16 )
{
F_2 ( V_16 -> V_1 ) ;
free ( V_16 ) ;
}
const char * F_14 ( const struct V_16 * V_16 )
{
return V_16 -> V_1 -> V_6 ;
}
