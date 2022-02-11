void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static struct V_1 * F_7 ( const char * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 = NULL , * V_10 ;
F_2 ( & V_3 ) ;
F_8 (pos, &chip_drvs_list) {
V_10 = F_9 ( V_8 , F_10 ( * V_10 ) , V_4 ) ;
if ( ! strcmp ( V_10 -> V_6 , V_6 ) ) {
V_9 = V_10 ;
break;
}
}
if ( V_9 && ! F_11 ( V_9 -> V_11 ) )
V_9 = NULL ;
F_4 ( & V_3 ) ;
return V_9 ;
}
struct V_12 * F_12 ( const char * V_6 , struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 && ! F_13 ( L_1 , V_6 ) )
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
return NULL ;
V_9 = V_2 -> V_15 ( V_14 ) ;
F_14 ( V_2 -> V_11 ) ;
if ( V_9 )
return V_9 ;
return NULL ;
}
void F_15 ( struct V_12 * V_16 )
{
struct V_13 * V_14 = V_16 -> V_17 ;
if ( V_14 -> V_18 -> V_19 )
V_14 -> V_18 -> V_19 ( V_16 ) ;
F_14 ( V_14 -> V_18 -> V_11 ) ;
F_16 ( V_16 ) ;
}
