void F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 = V_5 -> V_9 . V_10 - sizeof( struct V_4 ) ;
V_7 = F_2 ( sizeof( struct V_6 ) + V_8 , V_11 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , V_8 ) ;
return;
}
V_7 -> V_3 = V_3 ;
memcpy ( & V_7 -> V_12 , V_5 , V_5 -> V_9 . V_10 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_5 ( & V_7 -> V_14 , & V_2 -> V_15 ) ;
F_6 ( & V_2 -> V_13 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_4 ( & V_2 -> V_13 ) ;
for (; ; ) {
if ( F_8 ( & V_2 -> V_15 ) ) {
F_6 ( & V_2 -> V_13 ) ;
error = 0 ;
break;
}
V_7 = F_9 ( V_2 -> V_15 . V_16 , struct V_6 , V_14 ) ;
F_6 ( & V_2 -> V_13 ) ;
F_10 ( V_2 , & V_7 -> V_12 ) ;
F_4 ( & V_2 -> V_13 ) ;
F_11 ( & V_7 -> V_14 ) ;
F_12 ( V_7 ) ;
if ( F_13 ( V_2 ) ) {
F_14 ( V_2 , L_2 ) ;
F_6 ( & V_2 -> V_13 ) ;
error = - V_17 ;
break;
}
F_15 () ;
}
return error ;
}
void F_16 ( struct V_1 * V_2 )
{
for (; ; ) {
F_4 ( & V_2 -> V_13 ) ;
if ( F_8 ( & V_2 -> V_15 ) )
break;
F_6 ( & V_2 -> V_13 ) ;
F_15 () ;
}
F_6 ( & V_2 -> V_13 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_4 * V_5 , int V_3 )
{
T_1 type = V_5 -> V_18 ;
if ( ! V_2 -> V_19 )
return 1 ;
if ( F_18 ( V_2 , V_3 ) )
return 1 ;
if ( type == V_20 ||
type == V_21 ||
type == V_22 )
return 1 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
switch ( type ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
if ( F_20 ( V_2 , V_5 -> V_27 ) != F_21 () )
return 1 ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
if ( F_20 ( V_2 , V_5 -> V_27 ) != V_3 )
return 1 ;
break;
}
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 , * V_33 ;
F_4 ( & V_2 -> V_13 ) ;
F_23 (e, safe, &ls->ls_requestqueue, list) {
V_5 = & V_7 -> V_12 ;
if ( F_17 ( V_2 , V_5 , V_7 -> V_3 ) ) {
F_11 ( & V_7 -> V_14 ) ;
F_12 ( V_7 ) ;
}
}
F_6 ( & V_2 -> V_13 ) ;
}
