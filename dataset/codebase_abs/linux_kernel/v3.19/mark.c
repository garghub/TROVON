void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) ) {
if ( V_2 -> V_4 )
F_5 ( V_2 -> V_4 ) ;
V_2 -> V_5 ( V_2 ) ;
}
}
T_1 F_6 ( struct V_6 * V_7 )
{
T_1 V_8 = 0 ;
struct V_1 * V_2 ;
F_7 (mark, head, obj_list)
V_8 |= V_2 -> V_9 ;
return V_8 ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_10 * V_4 )
{
struct V_11 * V_11 = NULL ;
F_9 ( ! F_10 ( & V_4 -> V_12 ) ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) ) {
F_12 ( & V_2 -> V_13 ) ;
return;
}
V_2 -> V_14 &= ~ V_15 ;
if ( V_2 -> V_14 & V_16 ) {
V_11 = V_2 -> V_11 ;
F_13 ( V_2 ) ;
} else if ( V_2 -> V_14 & V_17 )
F_14 ( V_2 ) ;
else
F_15 () ;
F_16 ( & V_2 -> V_18 ) ;
F_12 ( & V_2 -> V_13 ) ;
if ( V_11 && ( V_2 -> V_14 & V_19 ) )
F_17 ( V_11 ) ;
F_18 ( & V_4 -> V_12 ) ;
F_11 ( & V_20 ) ;
F_19 ( & V_2 -> V_18 , & V_21 ) ;
F_12 ( & V_20 ) ;
F_20 ( & V_22 ) ;
if ( V_4 -> V_23 -> V_24 )
V_4 -> V_23 -> V_24 ( V_2 , V_4 ) ;
F_21 ( & V_4 -> V_25 ) ;
F_22 ( & V_4 -> V_12 , V_26 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_10 * V_4 )
{
F_22 ( & V_4 -> V_12 , V_26 ) ;
F_8 ( V_2 , V_4 ) ;
F_18 ( & V_4 -> V_12 ) ;
}
void F_24 ( struct V_27 * V_28 )
{
struct V_1 * V_2 , * V_29 ;
struct V_10 * V_4 ;
F_25 (mark, lmark, to_free, free_list) {
F_11 ( & V_2 -> V_13 ) ;
F_26 ( V_2 -> V_4 ) ;
V_4 = V_2 -> V_4 ;
F_12 ( & V_2 -> V_13 ) ;
F_23 ( V_2 , V_4 ) ;
F_3 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
void F_27 ( struct V_1 * V_2 , T_2 V_9 )
{
F_28 ( & V_2 -> V_13 ) ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_14 & V_16 )
F_29 ( V_2 , V_9 ) ;
}
void F_30 ( struct V_1 * V_2 , T_2 V_9 )
{
F_28 ( & V_2 -> V_13 ) ;
V_2 -> V_30 = V_9 ;
}
int F_31 ( struct V_10 * V_31 , struct V_10 * V_32 )
{
if ( V_31 == V_32 )
return 0 ;
if ( ! V_31 )
return 1 ;
if ( ! V_32 )
return - 1 ;
if ( V_31 -> V_33 < V_32 -> V_33 )
return 1 ;
if ( V_31 -> V_33 > V_32 -> V_33 )
return - 1 ;
if ( V_31 < V_32 )
return 1 ;
return - 1 ;
}
int F_32 ( struct V_6 * V_7 , struct V_1 * V_2 ,
int V_34 )
{
struct V_1 * V_29 , * V_35 = NULL ;
int V_36 ;
if ( F_33 ( V_7 ) ) {
F_34 ( & V_2 -> V_37 , V_7 ) ;
return 0 ;
}
F_7 (lmark, head, obj_list) {
V_35 = V_29 ;
if ( ( V_29 -> V_4 == V_2 -> V_4 ) && ! V_34 )
return - V_38 ;
V_36 = F_31 ( V_29 -> V_4 , V_2 -> V_4 ) ;
if ( V_36 >= 0 ) {
F_35 ( & V_2 -> V_37 , & V_29 -> V_37 ) ;
return 0 ;
}
}
F_9 ( V_35 == NULL ) ;
F_36 ( & V_2 -> V_37 , & V_35 -> V_37 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_10 * V_4 , struct V_11 * V_11 ,
struct V_39 * V_40 , int V_34 )
{
int V_41 = 0 ;
F_9 ( V_11 && V_40 ) ;
F_9 ( ! V_11 && ! V_40 ) ;
F_9 ( ! F_10 ( & V_4 -> V_12 ) ) ;
F_11 ( & V_2 -> V_13 ) ;
V_2 -> V_14 |= V_15 ;
F_26 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
F_19 ( & V_2 -> V_18 , & V_4 -> V_42 ) ;
F_2 ( & V_4 -> V_25 ) ;
F_1 ( V_2 ) ;
if ( V_11 ) {
V_41 = F_38 ( V_2 , V_4 , V_11 , V_34 ) ;
if ( V_41 )
goto V_43;
} else if ( V_40 ) {
V_41 = F_39 ( V_2 , V_4 , V_40 , V_34 ) ;
if ( V_41 )
goto V_43;
} else {
F_15 () ;
}
F_27 ( V_2 , V_2 -> V_9 ) ;
F_12 ( & V_2 -> V_13 ) ;
if ( V_11 )
F_40 ( V_11 ) ;
return V_41 ;
V_43:
V_2 -> V_14 &= ~ V_15 ;
F_16 ( & V_2 -> V_18 ) ;
F_5 ( V_4 ) ;
V_2 -> V_4 = NULL ;
F_21 ( & V_4 -> V_25 ) ;
F_12 ( & V_2 -> V_13 ) ;
F_11 ( & V_20 ) ;
F_19 ( & V_2 -> V_18 , & V_21 ) ;
F_12 ( & V_20 ) ;
F_20 ( & V_22 ) ;
return V_41 ;
}
int F_41 ( struct V_1 * V_2 , struct V_10 * V_4 ,
struct V_11 * V_11 , struct V_39 * V_40 , int V_34 )
{
int V_41 ;
F_42 ( & V_4 -> V_12 ) ;
V_41 = F_37 ( V_2 , V_4 , V_11 , V_40 , V_34 ) ;
F_18 ( & V_4 -> V_12 ) ;
return V_41 ;
}
struct V_1 * F_43 ( struct V_6 * V_7 ,
struct V_10 * V_4 )
{
struct V_1 * V_2 ;
F_7 (mark, head, obj_list) {
if ( V_2 -> V_4 == V_4 ) {
F_1 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
void F_44 ( struct V_10 * V_4 ,
unsigned int V_14 )
{
struct V_1 * V_29 , * V_2 ;
F_22 ( & V_4 -> V_12 , V_26 ) ;
F_25 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_14 & V_14 ) {
F_1 ( V_2 ) ;
F_8 ( V_2 , V_4 ) ;
F_3 ( V_2 ) ;
}
}
F_18 ( & V_4 -> V_12 ) ;
}
void F_45 ( struct V_10 * V_4 )
{
F_44 ( V_4 , ( unsigned int ) - 1 ) ;
}
void F_46 ( struct V_1 * V_44 , struct V_1 * V_45 )
{
F_28 ( & V_45 -> V_13 ) ;
V_44 -> V_11 = V_45 -> V_11 ;
V_44 -> V_40 = V_45 -> V_40 ;
if ( V_45 -> V_4 )
F_26 ( V_45 -> V_4 ) ;
V_44 -> V_4 = V_45 -> V_4 ;
V_44 -> V_9 = V_45 -> V_9 ;
V_44 -> V_5 = V_45 -> V_5 ;
}
void F_47 ( struct V_1 * V_2 ,
void (* V_5)( struct V_1 * V_2 ) )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_48 ( & V_2 -> V_13 ) ;
F_49 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_5 = V_5 ;
}
static int F_50 ( void * V_46 )
{
struct V_1 * V_2 , * V_47 ;
struct V_27 V_48 ;
for (; ; ) {
F_11 ( & V_20 ) ;
F_51 ( & V_21 , & V_48 ) ;
F_12 ( & V_20 ) ;
F_52 ( & V_49 ) ;
F_25 (mark, next, &private_destroy_list, g_list) {
F_16 ( & V_2 -> V_18 ) ;
F_3 ( V_2 ) ;
}
F_53 ( V_22 , ! F_54 ( & V_21 ) ) ;
}
return 0 ;
}
static int T_3 F_55 ( void )
{
struct V_50 * V_51 ;
V_51 = F_56 ( F_50 , NULL ,
L_1 ) ;
if ( F_57 ( V_51 ) )
F_58 ( L_2 ) ;
return 0 ;
}
