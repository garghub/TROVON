static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (snode, n, &session->stat_root, node) {
if ( V_2 -> V_6 -> V_7 )
V_2 -> V_6 -> V_7 ( V_4 -> V_8 ) ;
F_3 ( V_4 ) ;
}
V_2 -> V_9 = V_10 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_11 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_12 ) ;
F_1 ( V_2 ) ;
F_9 ( & V_2 -> V_11 ) ;
F_3 ( V_2 ) ;
}
static int F_10 ( struct V_13 * V_14 , void * V_8 , T_1 V_15 )
{
struct V_16 * * V_17 = & ( V_14 -> V_16 ) , * V_18 = NULL ;
struct V_3 * V_19 ;
V_19 = F_11 ( sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return - V_21 ;
V_19 -> V_8 = V_8 ;
while ( * V_17 ) {
struct V_3 * V_22 ;
int V_23 ;
V_22 = F_12 ( * V_17 , struct V_3 , V_24 ) ;
V_23 = V_15 ( V_19 -> V_8 , V_22 -> V_8 ) ;
V_18 = * V_17 ;
if ( V_23 >= 0 )
V_17 = & ( ( * V_17 ) -> V_25 ) ;
else
V_17 = & ( ( * V_17 ) -> V_26 ) ;
}
F_13 ( & V_19 -> V_24 , V_18 , V_17 ) ;
F_14 ( & V_19 -> V_24 , V_14 ) ;
return 0 ;
}
static int F_15 ( void * V_27 , void * V_28 )
{
return - 1 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_6 = V_2 -> V_6 ;
struct V_13 * V_14 = & V_2 -> V_9 ;
void * V_8 ;
int V_30 = 0 ;
int V_31 ;
F_5 ( & V_2 -> V_11 ) ;
F_1 ( V_2 ) ;
if ( ! V_6 -> V_32 )
V_6 -> V_32 = F_15 ;
V_8 = V_6 -> V_33 ( V_6 ) ;
if ( ! V_8 )
goto exit;
V_30 = F_10 ( V_14 , V_8 , V_6 -> V_32 ) ;
if ( V_30 )
goto exit;
for ( V_31 = 1 ; ; V_31 ++ ) {
V_8 = V_6 -> V_34 ( V_8 , V_31 ) ;
if ( ! V_8 )
break;
V_30 = F_10 ( V_14 , V_8 , V_6 -> V_32 ) ;
if ( V_30 )
goto V_35;
}
exit:
F_6 ( & V_2 -> V_11 ) ;
return V_30 ;
V_35:
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_11 ) ;
return V_30 ;
}
static void * F_17 ( struct V_36 * V_37 , T_2 * V_38 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_16 * V_24 ;
int V_5 = * V_38 ;
int V_31 ;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_6 -> V_40 ) {
if ( V_5 == 0 )
return V_41 ;
V_5 -- ;
}
V_24 = F_18 ( & V_2 -> V_9 ) ;
for ( V_31 = 0 ; V_24 && V_31 < V_5 ; V_31 ++ )
V_24 = F_19 ( V_24 ) ;
return V_24 ;
}
static void * F_20 ( struct V_36 * V_37 , void * V_42 , T_2 * V_38 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_16 * V_24 = V_42 ;
( * V_38 ) ++ ;
if ( V_42 == V_41 )
return F_18 ( & V_2 -> V_9 ) ;
return F_19 ( V_24 ) ;
}
static void F_21 ( struct V_36 * V_37 , void * V_42 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
}
static int F_22 ( struct V_36 * V_37 , void * V_43 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_3 * V_44 = F_12 ( V_43 , struct V_3 , V_24 ) ;
if ( V_43 == V_41 )
return V_2 -> V_6 -> V_40 ( V_37 ) ;
return V_2 -> V_6 -> V_45 ( V_37 , V_44 -> V_8 ) ;
}
static int F_23 ( struct V_46 * V_46 , struct V_12 * V_12 )
{
int V_30 ;
struct V_36 * V_47 ;
struct V_1 * V_2 = V_46 -> V_48 ;
V_30 = F_16 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_24 ( V_12 , & V_49 ) ;
if ( V_30 ) {
F_4 ( V_2 ) ;
return V_30 ;
}
V_47 = V_12 -> V_50 ;
V_47 -> V_39 = V_2 ;
return V_30 ;
}
static int F_25 ( struct V_46 * V_31 , struct V_12 * V_51 )
{
struct V_1 * V_2 = V_31 -> V_48 ;
F_4 ( V_2 ) ;
return F_26 ( V_31 , V_51 ) ;
}
static int F_27 ( void )
{
struct V_52 * V_53 ;
V_53 = F_28 () ;
if ( F_29 ( V_53 ) )
return 0 ;
V_54 = F_30 ( L_1 , V_53 ) ;
if ( ! V_54 )
F_31 ( L_2 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( ! V_54 && F_27 () )
return - V_55 ;
V_2 -> V_12 = F_33 ( V_2 -> V_6 -> V_56 , 0644 ,
V_54 ,
V_2 , & V_57 ) ;
if ( ! V_2 -> V_12 )
return - V_21 ;
return 0 ;
}
int F_34 ( struct V_29 * V_58 )
{
struct V_1 * V_2 , * V_24 ;
int V_30 ;
if ( ! V_58 )
return - V_59 ;
if ( ! V_58 -> V_33 || ! V_58 -> V_34 || ! V_58 -> V_45 )
return - V_59 ;
F_5 ( & V_60 ) ;
F_35 (node, &all_stat_sessions, session_list) {
if ( V_24 -> V_6 == V_58 ) {
F_6 ( & V_60 ) ;
return - V_59 ;
}
}
F_6 ( & V_60 ) ;
V_2 = F_11 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_6 = V_58 ;
F_36 ( & V_2 -> V_61 ) ;
F_37 ( & V_2 -> V_11 ) ;
V_30 = F_32 ( V_2 ) ;
if ( V_30 ) {
F_7 ( V_2 ) ;
return V_30 ;
}
F_5 ( & V_60 ) ;
F_38 ( & V_2 -> V_61 , & V_62 ) ;
F_6 ( & V_60 ) ;
return 0 ;
}
void F_39 ( struct V_29 * V_58 )
{
struct V_1 * V_24 , * V_63 ;
F_5 ( & V_60 ) ;
F_40 (node, tmp, &all_stat_sessions, session_list) {
if ( V_24 -> V_6 == V_58 ) {
F_41 ( & V_24 -> V_61 ) ;
F_7 ( V_24 ) ;
break;
}
}
F_6 ( & V_60 ) ;
}
