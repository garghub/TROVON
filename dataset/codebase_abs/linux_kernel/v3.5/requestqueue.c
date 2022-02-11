void F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 = V_5 -> V_9 . V_10 - sizeof( struct V_4 ) ;
V_7 = F_2 ( sizeof( struct V_6 ) + V_8 , V_11 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 -> V_12 = V_2 -> V_13 & 0xFFFFFFFF ;
V_7 -> V_3 = V_3 ;
memcpy ( & V_7 -> V_14 , V_5 , V_5 -> V_9 . V_10 ) ;
F_4 ( & V_2 -> V_15 ) ;
F_5 ( & V_7 -> V_16 , & V_2 -> V_17 ) ;
F_6 ( & V_2 -> V_15 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
int error = 0 ;
F_4 ( & V_2 -> V_15 ) ;
for (; ; ) {
if ( F_8 ( & V_2 -> V_17 ) ) {
F_6 ( & V_2 -> V_15 ) ;
error = 0 ;
break;
}
V_7 = F_9 ( V_2 -> V_17 . V_18 , struct V_6 , V_16 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_5 = & V_7 -> V_14 ;
F_10 ( V_2 , L_2
L_3 ,
V_5 -> V_19 , V_5 -> V_9 . V_20 ,
V_5 -> V_21 , V_5 -> V_22 , V_5 -> V_23 ,
V_7 -> V_12 ) ;
F_11 ( V_2 , & V_7 -> V_14 , V_7 -> V_12 ) ;
F_4 ( & V_2 -> V_15 ) ;
F_12 ( & V_7 -> V_16 ) ;
F_13 ( V_7 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_2 , L_4 ) ;
F_6 ( & V_2 -> V_15 ) ;
error = - V_24 ;
break;
}
F_16 () ;
}
return error ;
}
void F_17 ( struct V_1 * V_2 )
{
for (; ; ) {
F_4 ( & V_2 -> V_15 ) ;
if ( F_8 ( & V_2 -> V_17 ) )
break;
F_6 ( & V_2 -> V_15 ) ;
F_16 () ;
}
F_6 ( & V_2 -> V_15 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_3 )
{
T_1 type = V_5 -> V_19 ;
if ( ! V_2 -> V_25 )
return 1 ;
if ( F_19 ( V_2 , V_3 ) )
return 1 ;
if ( type == V_26 ||
type == V_27 ||
type == V_28 )
return 1 ;
if ( ! F_20 ( V_2 ) )
return 0 ;
return 1 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 , * V_29 ;
F_4 ( & V_2 -> V_15 ) ;
F_22 (e, safe, &ls->ls_requestqueue, list) {
V_5 = & V_7 -> V_14 ;
if ( F_18 ( V_2 , V_5 , V_7 -> V_3 ) ) {
F_12 ( & V_7 -> V_16 ) ;
F_13 ( V_7 ) ;
}
}
F_6 ( & V_2 -> V_15 ) ;
}
