static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_5 ( & V_4 -> V_6 ) ;
}
struct V_7 *
F_6 ( struct V_8 * V_6 )
{
struct V_3 * V_4 =
F_2 ( V_6 , struct V_3 , V_6 ) ;
return V_4 -> V_9 ;
}
int
F_7 ( struct V_7 * V_9 )
{
F_8 ( & V_9 -> V_5 ) ;
F_9 ( & V_9 -> V_10 , F_1 ,
F_4 ) ;
F_10 ( & V_11 ) ;
F_11 ( & V_9 -> V_5 , & V_12 ) ;
F_12 ( & V_11 ) ;
return 0 ;
}
int
F_13 ( struct V_7 * V_9 )
{
int V_13 = - V_14 ;
F_10 ( & V_11 ) ;
F_14 ( & V_9 -> V_10 . V_15 ) ;
if ( ! F_15 ( & V_9 -> V_10 . V_16 ) )
goto V_17;
V_13 = 0 ;
F_16 ( & V_9 -> V_5 ) ;
V_17:
F_17 ( & V_9 -> V_10 . V_15 ) ;
F_12 ( & V_11 ) ;
return V_13 ;
}
static void F_18 ( struct V_8 * V_6 )
{
struct V_3 * V_4
= F_2 ( V_6 , struct V_3 , V_6 ) ;
struct V_8 * V_18 = V_6 -> V_19 ;
F_19 ( V_4 ) ;
F_5 ( V_18 ) ;
}
void
F_20 ( struct V_8 * V_18 ,
int (* F_21)( struct V_7 * ,
struct V_8 * ,
struct V_8 * ) )
{
struct V_7 * V_9 ;
F_10 ( & V_11 ) ;
F_22 (cont, &attribute_container_list, node) {
struct V_3 * V_4 ;
if ( F_23 ( V_9 ) )
continue;
if ( ! V_9 -> V_20 ( V_9 , V_18 ) )
continue;
V_4 = F_24 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 ) {
F_25 ( V_18 , L_1 ) ;
continue;
}
V_4 -> V_9 = V_9 ;
F_26 ( & V_4 -> V_6 ) ;
V_4 -> V_6 . V_19 = F_3 ( V_18 ) ;
V_4 -> V_6 . V_22 = V_9 -> V_22 ;
V_9 -> V_22 -> V_23 = F_18 ;
F_27 ( & V_4 -> V_6 , F_28 ( V_18 ) ) ;
if ( F_21 )
F_21 ( V_9 , V_18 , & V_4 -> V_6 ) ;
else
F_29 ( & V_4 -> V_6 ) ;
F_30 ( & V_4 -> V_5 , & V_9 -> V_10 ) ;
}
F_12 ( & V_11 ) ;
}
void
F_31 ( struct V_8 * V_18 ,
void (* F_21)( struct V_7 * ,
struct V_8 * ,
struct V_8 * ) )
{
struct V_7 * V_9 ;
F_10 ( & V_11 ) ;
F_22 (cont, &attribute_container_list, node) {
struct V_3 * V_4 ;
struct V_24 V_25 ;
if ( F_23 ( V_9 ) )
continue;
if ( ! V_9 -> V_20 ( V_9 , V_18 ) )
continue;
F_32 (ic, &cont->containers, node, &iter) {
if ( V_18 != V_4 -> V_6 . V_19 )
continue;
F_33 ( & V_4 -> V_5 ) ;
if ( F_21 )
F_21 ( V_9 , V_18 , & V_4 -> V_6 ) ;
else {
F_34 ( & V_4 -> V_6 ) ;
F_35 ( & V_4 -> V_6 ) ;
}
}
}
F_12 ( & V_11 ) ;
}
void
F_36 ( struct V_8 * V_18 ,
int (* F_21)( struct V_7 * ,
struct V_8 * ,
struct V_8 * ) )
{
struct V_7 * V_9 ;
F_10 ( & V_11 ) ;
F_22 (cont, &attribute_container_list, node) {
struct V_3 * V_4 ;
struct V_24 V_25 ;
if ( ! V_9 -> V_20 ( V_9 , V_18 ) )
continue;
if ( F_23 ( V_9 ) ) {
F_21 ( V_9 , V_18 , NULL ) ;
continue;
}
F_32 (ic, &cont->containers, node, &iter) {
if ( V_18 == V_4 -> V_6 . V_19 )
F_21 ( V_9 , V_18 , & V_4 -> V_6 ) ;
}
}
F_12 ( & V_11 ) ;
}
void
F_37 ( struct V_8 * V_18 ,
int (* F_21)( struct V_7 * ,
struct V_8 * ) )
{
struct V_7 * V_9 ;
F_10 ( & V_11 ) ;
F_22 (cont, &attribute_container_list, node) {
if ( V_9 -> V_20 ( V_9 , V_18 ) )
F_21 ( V_9 , V_18 ) ;
}
F_12 ( & V_11 ) ;
}
int
F_38 ( struct V_8 * V_6 )
{
struct V_7 * V_9 =
F_6 ( V_6 ) ;
struct V_26 * * V_27 = V_9 -> V_27 ;
int V_28 , error ;
F_39 ( V_27 && V_9 -> V_29 ) ;
if ( ! V_27 && ! V_9 -> V_29 )
return 0 ;
if ( V_9 -> V_29 )
return F_40 ( & V_6 -> V_30 , V_9 -> V_29 ) ;
for ( V_28 = 0 ; V_27 [ V_28 ] ; V_28 ++ ) {
F_41 ( & V_27 [ V_28 ] -> V_31 ) ;
error = F_42 ( V_6 , V_27 [ V_28 ] ) ;
if ( error )
return error ;
}
return 0 ;
}
int
F_29 ( struct V_8 * V_6 )
{
int error = F_43 ( V_6 ) ;
if ( error )
return error ;
return F_38 ( V_6 ) ;
}
int
F_44 ( struct V_7 * V_9 ,
struct V_8 * V_18 ,
struct V_8 * V_6 )
{
return F_29 ( V_6 ) ;
}
void
F_34 ( struct V_8 * V_6 )
{
struct V_7 * V_9 =
F_6 ( V_6 ) ;
struct V_26 * * V_27 = V_9 -> V_27 ;
int V_28 ;
if ( ! V_27 && ! V_9 -> V_29 )
return;
if ( V_9 -> V_29 ) {
F_45 ( & V_6 -> V_30 , V_9 -> V_29 ) ;
return ;
}
for ( V_28 = 0 ; V_27 [ V_28 ] ; V_28 ++ )
F_46 ( V_6 , V_27 [ V_28 ] ) ;
}
void
F_47 ( struct V_8 * V_6 )
{
F_34 ( V_6 ) ;
F_48 ( V_6 ) ;
}
struct V_8 *
F_49 ( struct V_7 * V_9 ,
struct V_8 * V_18 )
{
struct V_8 * V_32 = NULL ;
struct V_3 * V_4 ;
struct V_24 V_25 ;
F_32 (ic, &cont->containers, node, &iter) {
if ( V_4 -> V_6 . V_19 == V_18 ) {
V_32 = & V_4 -> V_6 ;
F_50 ( & V_25 ) ;
break;
}
}
return V_32 ;
}
