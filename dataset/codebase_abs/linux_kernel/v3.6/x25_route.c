static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = - V_11 ;
F_2 ( & V_12 ) ;
F_3 (entry, &x25_route_list) {
V_7 = F_4 ( V_9 , struct V_6 , V_13 ) ;
if ( ! memcmp ( & V_7 -> V_2 , V_2 , V_3 ) &&
V_7 -> V_3 == V_3 )
goto V_14;
}
V_7 = F_5 ( sizeof( * V_7 ) , V_15 ) ;
V_10 = - V_16 ;
if ( ! V_7 )
goto V_14;
strcpy ( V_7 -> V_2 . V_17 , L_1 ) ;
memcpy ( V_7 -> V_2 . V_17 , V_2 -> V_17 , V_3 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_5 = V_5 ;
F_6 ( & V_7 -> V_18 , 1 ) ;
F_7 ( & V_7 -> V_13 , & V_19 ) ;
V_10 = 0 ;
V_14:
F_8 ( & V_12 ) ;
return V_10 ;
}
static void F_9 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 . V_20 ) {
F_10 ( & V_7 -> V_13 ) ;
F_11 ( V_7 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = - V_11 ;
F_2 ( & V_12 ) ;
F_3 (entry, &x25_route_list) {
V_7 = F_4 ( V_9 , struct V_6 , V_13 ) ;
if ( ! memcmp ( & V_7 -> V_2 , V_2 , V_3 ) &&
V_7 -> V_3 == V_3 && V_7 -> V_5 == V_5 ) {
F_9 ( V_7 ) ;
V_10 = 0 ;
break;
}
}
F_8 ( & V_12 ) ;
return V_10 ;
}
void F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_21 ;
F_2 ( & V_12 ) ;
F_14 (entry, tmp, &x25_route_list) {
V_7 = F_4 ( V_9 , struct V_6 , V_13 ) ;
if ( V_7 -> V_5 == V_5 )
F_9 ( V_7 ) ;
}
F_8 ( & V_12 ) ;
F_15 ( V_5 ) ;
}
struct V_4 * F_16 ( char * V_22 )
{
struct V_4 * V_5 = F_17 ( & V_23 , V_22 ) ;
if ( V_5 &&
( ! ( V_5 -> V_24 & V_25 ) || ( V_5 -> type != V_26
#if F_18 ( V_27 )
&& V_5 -> type != V_28
#endif
) ) ) {
F_19 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
struct V_6 * F_20 ( struct V_1 * V_29 )
{
struct V_6 * V_7 , * V_30 = NULL ;
struct V_8 * V_9 ;
F_21 ( & V_12 ) ;
F_3 (entry, &x25_route_list) {
V_7 = F_4 ( V_9 , struct V_6 , V_13 ) ;
if ( ! memcmp ( & V_7 -> V_2 , V_29 , V_7 -> V_3 ) ) {
if ( ! V_30 )
V_30 = V_7 ;
else if ( V_7 -> V_3 > V_30 -> V_3 )
V_30 = V_7 ;
}
}
if ( V_30 )
F_22 ( V_30 ) ;
F_23 ( & V_12 ) ;
return V_30 ;
}
int F_24 ( unsigned int V_31 , void T_1 * V_32 )
{
struct V_33 V_7 ;
struct V_4 * V_5 ;
int V_10 = - V_11 ;
if ( V_31 != V_34 && V_31 != V_35 )
goto V_14;
V_10 = - V_36 ;
if ( F_25 ( & V_7 , V_32 , sizeof( V_7 ) ) )
goto V_14;
V_10 = - V_11 ;
if ( V_7 . V_3 > 15 )
goto V_14;
V_5 = F_16 ( V_7 . V_37 ) ;
if ( ! V_5 )
goto V_14;
if ( V_31 == V_34 )
V_10 = F_1 ( & V_7 . V_2 , V_7 . V_3 , V_5 ) ;
else
V_10 = F_12 ( & V_7 . V_2 , V_7 . V_3 , V_5 ) ;
F_19 ( V_5 ) ;
V_14:
return V_10 ;
}
void T_2 F_26 ( void )
{
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_21 ;
F_2 ( & V_12 ) ;
F_14 (entry, tmp, &x25_route_list) {
V_7 = F_4 ( V_9 , struct V_6 , V_13 ) ;
F_9 ( V_7 ) ;
}
F_8 ( & V_12 ) ;
}
