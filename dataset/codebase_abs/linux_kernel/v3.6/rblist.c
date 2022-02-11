int F_1 ( struct V_1 * V_1 , const void * V_2 )
{
struct V_3 * * V_4 = & V_1 -> V_5 . V_3 ;
struct V_3 * V_6 = NULL , * V_7 ;
while ( * V_4 != NULL ) {
int V_8 ;
V_6 = * V_4 ;
V_8 = V_1 -> V_9 ( V_6 , V_2 ) ;
if ( V_8 > 0 )
V_4 = & ( * V_4 ) -> V_10 ;
else if ( V_8 < 0 )
V_4 = & ( * V_4 ) -> V_11 ;
else
return - V_12 ;
}
V_7 = V_1 -> V_13 ( V_1 , V_2 ) ;
if ( V_7 == NULL )
return - V_14 ;
F_2 ( V_7 , V_6 , V_4 ) ;
F_3 ( V_7 , & V_1 -> V_5 ) ;
++ V_1 -> V_15 ;
return 0 ;
}
void F_4 ( struct V_1 * V_1 , struct V_3 * V_3 )
{
F_5 ( V_3 , & V_1 -> V_5 ) ;
V_1 -> V_16 ( V_1 , V_3 ) ;
}
struct V_3 * F_6 ( struct V_1 * V_1 , const void * V_17 )
{
struct V_3 * * V_4 = & V_1 -> V_5 . V_3 ;
struct V_3 * V_6 = NULL ;
while ( * V_4 != NULL ) {
int V_8 ;
V_6 = * V_4 ;
V_8 = V_1 -> V_9 ( V_6 , V_17 ) ;
if ( V_8 > 0 )
V_4 = & ( * V_4 ) -> V_10 ;
else if ( V_8 < 0 )
V_4 = & ( * V_4 ) -> V_11 ;
else
return V_6 ;
}
return NULL ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( V_1 != NULL ) {
V_1 -> V_5 = V_18 ;
V_1 -> V_15 = 0 ;
}
return;
}
void F_8 ( struct V_1 * V_1 )
{
if ( V_1 != NULL ) {
struct V_3 * V_19 , * V_20 = F_9 ( & V_1 -> V_5 ) ;
while ( V_20 ) {
V_19 = V_20 ;
V_20 = F_10 ( V_19 ) ;
F_5 ( V_19 , & V_1 -> V_5 ) ;
V_1 -> V_16 ( V_1 , V_19 ) ;
}
free ( V_1 ) ;
}
}
struct V_3 * F_11 ( const struct V_1 * V_1 , unsigned int V_21 )
{
struct V_3 * V_22 ;
for ( V_22 = F_9 ( & V_1 -> V_5 ) ; V_22 ; V_22 = F_10 ( V_22 ) ) {
if ( ! V_21 -- )
return V_22 ;
}
return NULL ;
}
