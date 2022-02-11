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
void F_8 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = NULL ;
struct V_11 * V_4 = V_2 -> V_4 ;
F_9 ( ! F_10 ( & V_4 -> V_12 ) ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) ) {
F_12 ( & V_2 -> V_13 ) ;
return;
}
V_2 -> V_14 &= ~ V_15 ;
if ( V_2 -> V_14 & V_16 ) {
V_10 = V_2 -> V_10 ;
F_13 ( V_2 ) ;
} else if ( V_2 -> V_14 & V_17 )
F_14 ( V_2 ) ;
else
F_15 () ;
F_16 ( & V_2 -> V_18 ) ;
F_12 ( & V_2 -> V_13 ) ;
if ( V_10 && ( V_2 -> V_14 & V_19 ) )
F_17 ( V_10 ) ;
F_18 ( & V_4 -> V_20 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_13 ) ;
if ( ! ( V_2 -> V_14 & V_21 ) ) {
F_12 ( & V_2 -> V_13 ) ;
return;
}
V_2 -> V_14 &= ~ V_21 ;
F_12 ( & V_2 -> V_13 ) ;
F_11 ( & V_22 ) ;
F_20 ( & V_2 -> V_18 , & V_23 ) ;
F_12 ( & V_22 ) ;
F_21 ( & V_24 ) ;
if ( V_4 -> V_25 -> V_26 )
V_4 -> V_25 -> V_26 ( V_2 , V_4 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_11 * V_4 )
{
F_23 ( & V_4 -> V_12 , V_27 ) ;
F_8 ( V_2 ) ;
F_24 ( & V_4 -> V_12 ) ;
F_19 ( V_2 ) ;
}
void F_25 ( struct V_6 * V_7 , T_2 * V_13 )
{
struct V_1 * V_2 ;
while ( 1 ) {
F_11 ( V_13 ) ;
if ( F_26 ( V_7 ) ) {
F_12 ( V_13 ) ;
break;
}
V_2 = F_27 ( V_7 -> V_28 , struct V_1 , V_29 ) ;
F_28 ( & V_2 -> V_29 ) ;
F_1 ( V_2 ) ;
F_12 ( V_13 ) ;
F_22 ( V_2 , V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
}
void F_29 ( struct V_1 * V_2 , T_3 V_9 )
{
F_30 ( & V_2 -> V_13 ) ;
V_2 -> V_9 = V_9 ;
if ( V_2 -> V_14 & V_16 )
F_31 ( V_2 , V_9 ) ;
}
void F_32 ( struct V_1 * V_2 , T_3 V_9 )
{
F_30 ( & V_2 -> V_13 ) ;
V_2 -> V_30 = V_9 ;
}
int F_33 ( struct V_11 * V_31 , struct V_11 * V_32 )
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
int F_34 ( struct V_6 * V_7 , struct V_1 * V_2 ,
int V_34 )
{
struct V_1 * V_35 , * V_36 = NULL ;
int V_37 ;
if ( F_26 ( V_7 ) ) {
F_35 ( & V_2 -> V_29 , V_7 ) ;
return 0 ;
}
F_7 (lmark, head, obj_list) {
V_36 = V_35 ;
if ( ( V_35 -> V_4 == V_2 -> V_4 ) && ! V_34 )
return - V_38 ;
V_37 = F_33 ( V_35 -> V_4 , V_2 -> V_4 ) ;
if ( V_37 >= 0 ) {
F_36 ( & V_2 -> V_29 , & V_35 -> V_29 ) ;
return 0 ;
}
}
F_9 ( V_36 == NULL ) ;
F_37 ( & V_2 -> V_29 , & V_36 -> V_29 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_11 * V_4 , struct V_10 * V_10 ,
struct V_39 * V_40 , int V_34 )
{
int V_41 = 0 ;
F_9 ( V_10 && V_40 ) ;
F_9 ( ! V_10 && ! V_40 ) ;
F_9 ( ! F_10 ( & V_4 -> V_12 ) ) ;
F_11 ( & V_2 -> V_13 ) ;
V_2 -> V_14 |= V_21 | V_15 ;
F_39 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_2 -> V_18 , & V_4 -> V_42 ) ;
F_2 ( & V_4 -> V_20 ) ;
F_1 ( V_2 ) ;
if ( V_10 ) {
V_41 = F_40 ( V_2 , V_4 , V_10 , V_34 ) ;
if ( V_41 )
goto V_43;
} else if ( V_40 ) {
V_41 = F_41 ( V_2 , V_4 , V_40 , V_34 ) ;
if ( V_41 )
goto V_43;
} else {
F_15 () ;
}
F_29 ( V_2 , V_2 -> V_9 ) ;
F_12 ( & V_2 -> V_13 ) ;
if ( V_10 )
F_42 ( V_10 ) ;
return V_41 ;
V_43:
V_2 -> V_14 &= ~ V_21 ;
F_16 ( & V_2 -> V_18 ) ;
F_5 ( V_4 ) ;
V_2 -> V_4 = NULL ;
F_18 ( & V_4 -> V_20 ) ;
F_12 ( & V_2 -> V_13 ) ;
F_11 ( & V_22 ) ;
F_20 ( & V_2 -> V_18 , & V_23 ) ;
F_12 ( & V_22 ) ;
F_21 ( & V_24 ) ;
return V_41 ;
}
int F_43 ( struct V_1 * V_2 , struct V_11 * V_4 ,
struct V_10 * V_10 , struct V_39 * V_40 , int V_34 )
{
int V_41 ;
F_44 ( & V_4 -> V_12 ) ;
V_41 = F_38 ( V_2 , V_4 , V_10 , V_40 , V_34 ) ;
F_24 ( & V_4 -> V_12 ) ;
return V_41 ;
}
struct V_1 * F_45 ( struct V_6 * V_7 ,
struct V_11 * V_4 )
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
void F_46 ( struct V_11 * V_4 ,
unsigned int V_14 )
{
struct V_1 * V_35 , * V_2 ;
F_47 ( V_44 ) ;
F_23 ( & V_4 -> V_12 , V_27 ) ;
F_48 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_14 & V_14 )
F_49 ( & V_2 -> V_18 , & V_44 ) ;
}
F_24 ( & V_4 -> V_12 ) ;
while ( 1 ) {
F_23 ( & V_4 -> V_12 , V_27 ) ;
if ( F_50 ( & V_44 ) ) {
F_24 ( & V_4 -> V_12 ) ;
break;
}
V_2 = F_51 ( & V_44 , struct V_1 , V_18 ) ;
F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
F_24 ( & V_4 -> V_12 ) ;
F_19 ( V_2 ) ;
F_3 ( V_2 ) ;
}
}
void F_52 ( struct V_11 * V_4 )
{
F_46 ( V_4 , ( unsigned int ) - 1 ) ;
}
void F_53 ( struct V_1 * V_45 , struct V_1 * V_46 )
{
F_30 ( & V_46 -> V_13 ) ;
V_45 -> V_10 = V_46 -> V_10 ;
V_45 -> V_40 = V_46 -> V_40 ;
if ( V_46 -> V_4 )
F_39 ( V_46 -> V_4 ) ;
V_45 -> V_4 = V_46 -> V_4 ;
V_45 -> V_9 = V_46 -> V_9 ;
V_45 -> V_5 = V_46 -> V_5 ;
}
void F_54 ( struct V_1 * V_2 ,
void (* V_5)( struct V_1 * V_2 ) )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_55 ( & V_2 -> V_13 ) ;
F_56 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_5 = V_5 ;
}
static int F_57 ( void * V_47 )
{
struct V_1 * V_2 , * V_48 ;
struct V_49 V_50 ;
for (; ; ) {
F_11 ( & V_22 ) ;
F_58 ( & V_23 , & V_50 ) ;
F_12 ( & V_22 ) ;
F_59 ( & V_51 ) ;
F_48 (mark, next, &private_destroy_list, g_list) {
F_16 ( & V_2 -> V_18 ) ;
F_3 ( V_2 ) ;
}
F_60 ( V_24 , ! F_50 ( & V_23 ) ) ;
}
return 0 ;
}
static int T_4 F_61 ( void )
{
struct V_52 * V_53 ;
V_53 = F_62 ( F_57 , NULL ,
L_1 ) ;
if ( F_63 ( V_53 ) )
F_64 ( L_2 ) ;
return 0 ;
}
