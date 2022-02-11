static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (psi, &_path_selectors, list) {
if ( ! strcmp ( V_2 , V_3 -> V_4 . V_2 ) )
return V_3 ;
}
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_4 ( & V_5 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 && ! F_5 ( V_3 -> V_4 . V_6 ) )
V_3 = NULL ;
F_6 ( & V_5 ) ;
return V_3 ;
}
struct V_7 * F_7 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_3 ( V_2 ) ;
if ( ! V_3 ) {
F_8 ( L_1 , V_2 ) ;
V_3 = F_3 ( V_2 ) ;
}
return V_3 ? & V_3 -> V_4 : NULL ;
}
void F_9 ( struct V_7 * V_4 )
{
struct V_1 * V_3 ;
if ( ! V_4 )
return;
F_4 ( & V_5 ) ;
V_3 = F_1 ( V_4 -> V_2 ) ;
if ( ! V_3 )
goto V_8;
F_10 ( V_3 -> V_4 . V_6 ) ;
V_8:
F_6 ( & V_5 ) ;
}
static struct V_1 * F_11 ( struct V_7 * V_4 )
{
struct V_1 * V_3 = F_12 ( sizeof( * V_3 ) , V_9 ) ;
if ( V_3 )
V_3 -> V_4 = * V_4 ;
return V_3 ;
}
int F_13 ( struct V_7 * V_4 )
{
int V_10 = 0 ;
struct V_1 * V_3 = F_11 ( V_4 ) ;
if ( ! V_3 )
return - V_11 ;
F_14 ( & V_5 ) ;
if ( F_1 ( V_4 -> V_2 ) ) {
F_15 ( V_3 ) ;
V_10 = - V_12 ;
} else
F_16 ( & V_3 -> V_13 , & V_14 ) ;
F_17 ( & V_5 ) ;
return V_10 ;
}
int F_18 ( struct V_7 * V_4 )
{
struct V_1 * V_3 ;
F_14 ( & V_5 ) ;
V_3 = F_1 ( V_4 -> V_2 ) ;
if ( ! V_3 ) {
F_17 ( & V_5 ) ;
return - V_15 ;
}
F_19 ( & V_3 -> V_13 ) ;
F_17 ( & V_5 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
