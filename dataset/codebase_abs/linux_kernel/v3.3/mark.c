void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
V_2 -> V_4 ( V_2 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_7 = NULL ;
F_6 ( & V_2 -> V_8 ) ;
V_6 = V_2 -> V_6 ;
if ( ! ( V_2 -> V_9 & V_10 ) ) {
F_7 ( & V_2 -> V_8 ) ;
return;
}
V_2 -> V_9 &= ~ V_10 ;
F_6 ( & V_6 -> V_11 ) ;
if ( V_2 -> V_9 & V_12 ) {
V_7 = V_2 -> V_13 . V_7 ;
F_8 ( V_2 ) ;
} else if ( V_2 -> V_9 & V_14 )
F_9 ( V_2 ) ;
else
F_10 () ;
F_11 ( & V_2 -> V_15 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_7 ( & V_2 -> V_8 ) ;
F_6 ( & V_16 ) ;
F_12 ( & V_2 -> V_17 , & V_17 ) ;
F_7 ( & V_16 ) ;
F_13 ( & V_18 ) ;
if ( V_6 -> V_19 -> V_20 )
V_6 -> V_19 -> V_20 ( V_2 , V_6 ) ;
if ( V_7 && ( V_2 -> V_9 & V_21 ) )
F_14 ( V_7 ) ;
if ( F_15 ( F_4 ( & V_6 -> V_22 ) ) )
F_16 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_23 )
{
F_18 ( & V_2 -> V_8 ) ;
V_2 -> V_23 = V_23 ;
if ( V_2 -> V_9 & V_12 )
F_19 ( V_2 , V_23 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_23 )
{
F_18 ( & V_2 -> V_8 ) ;
V_2 -> V_24 = V_23 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_7 * V_7 ,
struct V_25 * V_26 , int V_27 )
{
int V_28 = 0 ;
F_22 ( V_7 && V_26 ) ;
F_22 ( ! V_7 && ! V_26 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_6 ( & V_6 -> V_11 ) ;
V_2 -> V_9 |= V_10 ;
V_2 -> V_6 = V_6 ;
F_12 ( & V_2 -> V_15 , & V_6 -> V_29 ) ;
F_2 ( & V_6 -> V_22 ) ;
F_1 ( V_2 ) ;
if ( V_7 ) {
V_28 = F_23 ( V_2 , V_6 , V_7 , V_27 ) ;
if ( V_28 )
goto V_30;
} else if ( V_26 ) {
V_28 = F_24 ( V_2 , V_6 , V_26 , V_27 ) ;
if ( V_28 )
goto V_30;
} else {
F_10 () ;
}
F_7 ( & V_6 -> V_11 ) ;
F_17 ( V_2 , V_2 -> V_23 ) ;
F_7 ( & V_2 -> V_8 ) ;
if ( V_7 )
F_25 ( V_7 ) ;
return V_28 ;
V_30:
V_2 -> V_9 &= ~ V_10 ;
F_11 ( & V_2 -> V_15 ) ;
V_2 -> V_6 = NULL ;
F_26 ( & V_6 -> V_22 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_7 ( & V_2 -> V_8 ) ;
F_6 ( & V_16 ) ;
F_12 ( & V_2 -> V_17 , & V_17 ) ;
F_7 ( & V_16 ) ;
F_13 ( & V_18 ) ;
return V_28 ;
}
void F_27 ( struct V_5 * V_6 ,
unsigned int V_9 )
{
struct V_1 * V_31 , * V_2 ;
F_28 ( V_32 ) ;
F_6 ( & V_6 -> V_11 ) ;
F_29 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_9 & V_9 ) {
F_12 ( & V_2 -> V_33 , & V_32 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_1 ( V_2 ) ;
}
}
F_7 ( & V_6 -> V_11 ) ;
F_29 (mark, lmark, &free_list, free_g_list) {
F_5 ( V_2 ) ;
F_3 ( V_2 ) ;
}
}
void F_30 ( struct V_5 * V_6 )
{
F_27 ( V_6 , ( unsigned int ) - 1 ) ;
}
void F_31 ( struct V_1 * V_34 , struct V_1 * V_35 )
{
F_18 ( & V_35 -> V_8 ) ;
V_34 -> V_13 . V_7 = V_35 -> V_13 . V_7 ;
V_34 -> V_36 . V_26 = V_35 -> V_36 . V_26 ;
V_34 -> V_6 = V_35 -> V_6 ;
V_34 -> V_23 = V_35 -> V_23 ;
V_34 -> V_4 = V_35 -> V_4 ;
}
void F_32 ( struct V_1 * V_2 ,
void (* V_4)( struct V_1 * V_2 ) )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_33 ( & V_2 -> V_8 ) ;
F_34 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_4 = V_4 ;
}
static int F_35 ( void * V_37 )
{
struct V_1 * V_2 , * V_38 ;
F_28 ( V_39 ) ;
for (; ; ) {
F_6 ( & V_16 ) ;
F_36 ( & V_17 , & V_39 ) ;
F_7 ( & V_16 ) ;
F_37 ( & V_40 ) ;
F_29 (mark, next, &private_destroy_list, destroy_list) {
F_11 ( & V_2 -> V_17 ) ;
F_3 ( V_2 ) ;
}
F_38 ( V_18 , ! F_39 ( & V_17 ) ) ;
}
return 0 ;
}
static int T_2 F_40 ( void )
{
struct V_41 * V_42 ;
V_42 = F_41 ( F_35 , NULL ,
L_1 ) ;
if ( F_42 ( V_42 ) )
F_43 ( L_2 ) ;
return 0 ;
}
