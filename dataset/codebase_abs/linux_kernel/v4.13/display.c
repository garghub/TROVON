void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
* V_4 = V_2 -> V_5 . V_4 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 -> V_13 , L_1 ) ;
if ( V_11 < 0 )
V_11 = V_14 ++ ;
snprintf ( V_2 -> V_15 , sizeof( V_2 -> V_15 ) , L_2 , V_11 ) ;
F_4 ( V_2 -> V_12 -> V_13 , L_3 , & V_2 -> V_16 ) ;
if ( V_2 -> V_16 == NULL )
V_2 -> V_16 = V_2 -> V_15 ;
if ( V_7 && V_7 -> V_17 == NULL )
V_7 -> V_17 = F_1 ;
F_5 ( & V_18 ) ;
F_6 (cur, &panel_list) {
struct V_1 * V_19 = F_7 ( V_10 ,
struct V_1 ,
V_20 ) ;
if ( strcmp ( V_19 -> V_15 , V_2 -> V_15 ) > 0 )
break;
}
F_8 ( & V_2 -> V_20 , V_10 ) ;
F_9 ( & V_18 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_5 ( & V_18 ) ;
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_18 ) ;
}
bool F_12 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
bool V_23 = false ;
F_5 ( & V_18 ) ;
F_13 (dssdev, &panel_list, panel_list) {
if ( V_2 -> V_12 -> V_13 == V_22 ) {
V_23 = true ;
goto V_24;
}
}
V_24:
F_9 ( & V_18 ) ;
return V_23 ;
}
struct V_1 * F_14 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_2 -> V_25 ) )
return NULL ;
if ( F_16 ( V_2 -> V_12 ) == NULL ) {
F_17 ( V_2 -> V_25 ) ;
return NULL ;
}
return V_2 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_12 ) ;
F_17 ( V_2 -> V_25 ) ;
}
struct V_1 * F_20 ( struct V_1 * V_26 )
{
struct V_9 * V_27 ;
struct V_1 * V_2 ;
F_5 ( & V_18 ) ;
if ( F_21 ( & V_20 ) ) {
V_2 = NULL ;
goto V_24;
}
if ( V_26 == NULL ) {
V_2 = F_22 ( & V_20 , struct V_1 ,
V_20 ) ;
F_14 ( V_2 ) ;
goto V_24;
}
F_18 ( V_26 ) ;
F_6 (l, &panel_list) {
V_2 = F_7 ( V_27 , struct V_1 , V_20 ) ;
if ( V_2 == V_26 ) {
if ( F_23 ( V_27 , & V_20 ) ) {
V_2 = NULL ;
goto V_24;
}
V_2 = F_7 ( V_27 -> V_28 , struct V_1 ,
V_20 ) ;
F_14 ( V_2 ) ;
goto V_24;
}
}
F_24 ( 1 , L_4 ) ;
V_2 = NULL ;
V_24:
F_9 ( & V_18 ) ;
return V_2 ;
}
struct V_1 * F_25 ( void * V_29 ,
int (* F_26)( struct V_1 * V_2 , void * V_29 ) )
{
struct V_1 * V_2 = NULL ;
while ( ( V_2 = F_20 ( V_2 ) ) != NULL ) {
if ( F_26 ( V_2 , V_29 ) )
return V_2 ;
}
return NULL ;
}
