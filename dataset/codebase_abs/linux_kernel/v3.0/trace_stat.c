static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 )
return V_4 -> V_8 ;
else if ( V_4 -> V_9 )
return V_4 -> V_9 ;
else {
if ( ! V_7 )
;
else if ( V_7 -> V_8 == V_4 )
V_7 -> V_8 = NULL ;
else
V_7 -> V_9 = NULL ;
V_6 = F_3 ( V_4 , struct V_5 , V_4 ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 ( V_6 -> V_11 ) ;
F_4 ( V_6 ) ;
return V_7 ;
}
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_14 . V_1 ;
while ( V_4 )
V_4 = F_1 ( V_13 -> V_3 , V_4 ) ;
V_13 -> V_14 = V_15 ;
}
static void F_6 ( struct V_12 * V_13 )
{
F_7 ( & V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
F_8 ( & V_13 -> V_16 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
F_10 ( V_13 -> V_17 ) ;
F_5 ( V_13 ) ;
F_11 ( & V_13 -> V_16 ) ;
F_4 ( V_13 ) ;
}
static int F_12 ( struct V_18 * V_19 , void * V_11 , T_1 V_20 )
{
struct V_1 * * V_21 = & ( V_19 -> V_1 ) , * V_7 = NULL ;
struct V_5 * V_22 ;
V_22 = F_13 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
V_22 -> V_11 = V_11 ;
while ( * V_21 ) {
struct V_5 * V_25 ;
int V_26 ;
V_25 = F_3 ( * V_21 , struct V_5 , V_4 ) ;
V_26 = V_20 ( V_22 -> V_11 , V_25 -> V_11 ) ;
V_7 = * V_21 ;
if ( V_26 >= 0 )
V_21 = & ( ( * V_21 ) -> V_8 ) ;
else
V_21 = & ( ( * V_21 ) -> V_9 ) ;
}
F_14 ( & V_22 -> V_4 , V_7 , V_21 ) ;
F_15 ( & V_22 -> V_4 , V_19 ) ;
return 0 ;
}
static int F_16 ( void * V_27 , void * V_28 )
{
return - 1 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_18 * V_19 = & V_13 -> V_14 ;
void * V_11 ;
int V_29 = 0 ;
int V_30 ;
F_7 ( & V_13 -> V_16 ) ;
F_5 ( V_13 ) ;
if ( ! V_3 -> V_31 )
V_3 -> V_31 = F_16 ;
V_11 = V_3 -> V_32 ( V_3 ) ;
if ( ! V_11 )
goto exit;
V_29 = F_12 ( V_19 , V_11 , V_3 -> V_31 ) ;
if ( V_29 )
goto exit;
for ( V_30 = 1 ; ; V_30 ++ ) {
V_11 = V_3 -> V_33 ( V_11 , V_30 ) ;
if ( ! V_11 )
break;
V_29 = F_12 ( V_19 , V_11 , V_3 -> V_31 ) ;
if ( V_29 )
goto V_34;
}
exit:
F_8 ( & V_13 -> V_16 ) ;
return V_29 ;
V_34:
F_5 ( V_13 ) ;
F_8 ( & V_13 -> V_16 ) ;
return V_29 ;
}
static void * F_18 ( struct V_35 * V_36 , T_2 * V_37 )
{
struct V_12 * V_13 = V_36 -> V_38 ;
struct V_1 * V_4 ;
int V_39 = * V_37 ;
int V_30 ;
F_7 ( & V_13 -> V_16 ) ;
if ( V_13 -> V_3 -> V_40 ) {
if ( V_39 == 0 )
return V_41 ;
V_39 -- ;
}
V_4 = F_19 ( & V_13 -> V_14 ) ;
for ( V_30 = 0 ; V_4 && V_30 < V_39 ; V_30 ++ )
V_4 = F_20 ( V_4 ) ;
return V_4 ;
}
static void * F_21 ( struct V_35 * V_36 , void * V_42 , T_2 * V_37 )
{
struct V_12 * V_13 = V_36 -> V_38 ;
struct V_1 * V_4 = V_42 ;
( * V_37 ) ++ ;
if ( V_42 == V_41 )
return F_19 ( & V_13 -> V_14 ) ;
return F_20 ( V_4 ) ;
}
static void F_22 ( struct V_35 * V_36 , void * V_42 )
{
struct V_12 * V_13 = V_36 -> V_38 ;
F_8 ( & V_13 -> V_16 ) ;
}
static int F_23 ( struct V_35 * V_36 , void * V_43 )
{
struct V_12 * V_13 = V_36 -> V_38 ;
struct V_5 * V_44 = F_3 ( V_43 , struct V_5 , V_4 ) ;
if ( V_43 == V_41 )
return V_13 -> V_3 -> V_40 ( V_36 ) ;
return V_13 -> V_3 -> V_45 ( V_36 , V_44 -> V_11 ) ;
}
static int F_24 ( struct V_46 * V_46 , struct V_17 * V_17 )
{
int V_29 ;
struct V_35 * V_47 ;
struct V_12 * V_13 = V_46 -> V_48 ;
V_29 = F_17 ( V_13 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_25 ( V_17 , & V_49 ) ;
if ( V_29 ) {
F_6 ( V_13 ) ;
return V_29 ;
}
V_47 = V_17 -> V_50 ;
V_47 -> V_38 = V_13 ;
return V_29 ;
}
static int F_26 ( struct V_46 * V_30 , struct V_17 * V_51 )
{
struct V_12 * V_13 = V_30 -> V_48 ;
F_6 ( V_13 ) ;
return F_27 ( V_30 , V_51 ) ;
}
static int F_28 ( void )
{
struct V_52 * V_53 ;
V_53 = F_29 () ;
V_54 = F_30 ( L_1 , V_53 ) ;
if ( ! V_54 )
F_31 ( L_2
L_3 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
if ( ! V_54 && F_28 () )
return - V_55 ;
V_13 -> V_17 = F_33 ( V_13 -> V_3 -> V_56 , 0644 ,
V_54 ,
V_13 , & V_57 ) ;
if ( ! V_13 -> V_17 )
return - V_24 ;
return 0 ;
}
int F_34 ( struct V_2 * V_58 )
{
struct V_12 * V_13 , * V_4 ;
int V_29 ;
if ( ! V_58 )
return - V_59 ;
if ( ! V_58 -> V_32 || ! V_58 -> V_33 || ! V_58 -> V_45 )
return - V_59 ;
F_7 ( & V_60 ) ;
F_35 (node, &all_stat_sessions, session_list) {
if ( V_4 -> V_3 == V_58 ) {
F_8 ( & V_60 ) ;
return - V_59 ;
}
}
F_8 ( & V_60 ) ;
V_13 = F_13 ( sizeof( * V_13 ) , V_23 ) ;
if ( ! V_13 )
return - V_24 ;
V_13 -> V_3 = V_58 ;
F_36 ( & V_13 -> V_61 ) ;
F_37 ( & V_13 -> V_16 ) ;
V_29 = F_32 ( V_13 ) ;
if ( V_29 ) {
F_9 ( V_13 ) ;
return V_29 ;
}
F_7 ( & V_60 ) ;
F_38 ( & V_13 -> V_61 , & V_62 ) ;
F_8 ( & V_60 ) ;
return 0 ;
}
void F_39 ( struct V_2 * V_58 )
{
struct V_12 * V_4 , * V_63 ;
F_7 ( & V_60 ) ;
F_40 (node, tmp, &all_stat_sessions, session_list) {
if ( V_4 -> V_3 == V_58 ) {
F_41 ( & V_4 -> V_61 ) ;
F_9 ( V_4 ) ;
break;
}
}
F_8 ( & V_60 ) ;
}
