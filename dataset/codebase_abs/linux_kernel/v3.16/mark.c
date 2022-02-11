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
void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_4 )
{
struct V_7 * V_7 = NULL ;
F_7 ( ! F_8 ( & V_4 -> V_8 ) ) ;
F_9 ( & V_2 -> V_9 ) ;
if ( ! ( V_2 -> V_10 & V_11 ) ) {
F_10 ( & V_2 -> V_9 ) ;
return;
}
V_2 -> V_10 &= ~ V_11 ;
if ( V_2 -> V_10 & V_12 ) {
V_7 = V_2 -> V_13 . V_7 ;
F_11 ( V_2 ) ;
} else if ( V_2 -> V_10 & V_14 )
F_12 ( V_2 ) ;
else
F_13 () ;
F_14 ( & V_2 -> V_15 ) ;
F_10 ( & V_2 -> V_9 ) ;
if ( V_7 && ( V_2 -> V_10 & V_16 ) )
F_15 ( V_7 ) ;
F_16 ( & V_4 -> V_8 ) ;
F_9 ( & V_17 ) ;
F_17 ( & V_2 -> V_18 , & V_18 ) ;
F_10 ( & V_17 ) ;
F_18 ( & V_19 ) ;
if ( V_4 -> V_20 -> V_21 )
V_4 -> V_20 -> V_21 ( V_2 , V_4 ) ;
F_19 ( & V_4 -> V_22 ) ;
F_20 ( & V_4 -> V_8 , V_23 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_6 * V_4 )
{
F_20 ( & V_4 -> V_8 , V_23 ) ;
F_6 ( V_2 , V_4 ) ;
F_16 ( & V_4 -> V_8 ) ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_24 )
{
F_23 ( & V_2 -> V_9 ) ;
V_2 -> V_24 = V_24 ;
if ( V_2 -> V_10 & V_12 )
F_24 ( V_2 , V_24 ) ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_24 )
{
F_23 ( & V_2 -> V_9 ) ;
V_2 -> V_25 = V_24 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_6 * V_4 , struct V_7 * V_7 ,
struct V_26 * V_27 , int V_28 )
{
int V_29 = 0 ;
F_7 ( V_7 && V_27 ) ;
F_7 ( ! V_7 && ! V_27 ) ;
F_7 ( ! F_8 ( & V_4 -> V_8 ) ) ;
F_9 ( & V_2 -> V_9 ) ;
V_2 -> V_10 |= V_11 ;
F_27 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
F_17 ( & V_2 -> V_15 , & V_4 -> V_30 ) ;
F_2 ( & V_4 -> V_22 ) ;
F_1 ( V_2 ) ;
if ( V_7 ) {
V_29 = F_28 ( V_2 , V_4 , V_7 , V_28 ) ;
if ( V_29 )
goto V_31;
} else if ( V_27 ) {
V_29 = F_29 ( V_2 , V_4 , V_27 , V_28 ) ;
if ( V_29 )
goto V_31;
} else {
F_13 () ;
}
F_22 ( V_2 , V_2 -> V_24 ) ;
F_10 ( & V_2 -> V_9 ) ;
if ( V_7 )
F_30 ( V_7 ) ;
return V_29 ;
V_31:
V_2 -> V_10 &= ~ V_11 ;
F_14 ( & V_2 -> V_15 ) ;
F_5 ( V_4 ) ;
V_2 -> V_4 = NULL ;
F_19 ( & V_4 -> V_22 ) ;
F_10 ( & V_2 -> V_9 ) ;
F_9 ( & V_17 ) ;
F_17 ( & V_2 -> V_18 , & V_18 ) ;
F_10 ( & V_17 ) ;
F_18 ( & V_19 ) ;
return V_29 ;
}
int F_31 ( struct V_1 * V_2 , struct V_6 * V_4 ,
struct V_7 * V_7 , struct V_26 * V_27 , int V_28 )
{
int V_29 ;
F_32 ( & V_4 -> V_8 ) ;
V_29 = F_26 ( V_2 , V_4 , V_7 , V_27 , V_28 ) ;
F_16 ( & V_4 -> V_8 ) ;
return V_29 ;
}
void F_33 ( struct V_6 * V_4 ,
unsigned int V_10 )
{
struct V_1 * V_32 , * V_2 ;
F_20 ( & V_4 -> V_8 , V_23 ) ;
F_34 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_10 & V_10 ) {
F_1 ( V_2 ) ;
F_6 ( V_2 , V_4 ) ;
F_3 ( V_2 ) ;
}
}
F_16 ( & V_4 -> V_8 ) ;
}
void F_35 ( struct V_6 * V_4 )
{
F_33 ( V_4 , ( unsigned int ) - 1 ) ;
}
void F_36 ( struct V_1 * V_33 , struct V_1 * V_34 )
{
F_23 ( & V_34 -> V_9 ) ;
V_33 -> V_13 . V_7 = V_34 -> V_13 . V_7 ;
V_33 -> V_35 . V_27 = V_34 -> V_35 . V_27 ;
if ( V_34 -> V_4 )
F_27 ( V_34 -> V_4 ) ;
V_33 -> V_4 = V_34 -> V_4 ;
V_33 -> V_24 = V_34 -> V_24 ;
V_33 -> V_5 = V_34 -> V_5 ;
}
void F_37 ( struct V_1 * V_2 ,
void (* V_5)( struct V_1 * V_2 ) )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_38 ( & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_5 = V_5 ;
}
static int F_40 ( void * V_36 )
{
struct V_1 * V_2 , * V_37 ;
struct V_38 V_39 ;
for (; ; ) {
F_9 ( & V_17 ) ;
F_41 ( & V_18 , & V_39 ) ;
F_10 ( & V_17 ) ;
F_42 ( & V_40 ) ;
F_34 (mark, next, &private_destroy_list, destroy_list) {
F_14 ( & V_2 -> V_18 ) ;
F_3 ( V_2 ) ;
}
F_43 ( V_19 , ! F_44 ( & V_18 ) ) ;
}
return 0 ;
}
static int T_2 F_45 ( void )
{
struct V_41 * V_42 ;
V_42 = F_46 ( F_40 , NULL ,
L_1 ) ;
if ( F_47 ( V_42 ) )
F_48 ( L_2 ) ;
return 0 ;
}
