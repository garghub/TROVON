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
int F_26 ( struct V_6 * V_26 , struct V_6 * V_27 )
{
if ( V_26 == V_27 )
return 0 ;
if ( ! V_26 )
return 1 ;
if ( ! V_27 )
return - 1 ;
if ( V_26 -> V_28 < V_27 -> V_28 )
return 1 ;
if ( V_26 -> V_28 > V_27 -> V_28 )
return - 1 ;
if ( V_26 < V_27 )
return 1 ;
return - 1 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_6 * V_4 , struct V_7 * V_7 ,
struct V_29 * V_30 , int V_31 )
{
int V_32 = 0 ;
F_7 ( V_7 && V_30 ) ;
F_7 ( ! V_7 && ! V_30 ) ;
F_7 ( ! F_8 ( & V_4 -> V_8 ) ) ;
F_9 ( & V_2 -> V_9 ) ;
V_2 -> V_10 |= V_11 ;
F_28 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
F_17 ( & V_2 -> V_15 , & V_4 -> V_33 ) ;
F_2 ( & V_4 -> V_22 ) ;
F_1 ( V_2 ) ;
if ( V_7 ) {
V_32 = F_29 ( V_2 , V_4 , V_7 , V_31 ) ;
if ( V_32 )
goto V_34;
} else if ( V_30 ) {
V_32 = F_30 ( V_2 , V_4 , V_30 , V_31 ) ;
if ( V_32 )
goto V_34;
} else {
F_13 () ;
}
F_22 ( V_2 , V_2 -> V_24 ) ;
F_10 ( & V_2 -> V_9 ) ;
if ( V_7 )
F_31 ( V_7 ) ;
return V_32 ;
V_34:
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
return V_32 ;
}
int F_32 ( struct V_1 * V_2 , struct V_6 * V_4 ,
struct V_7 * V_7 , struct V_29 * V_30 , int V_31 )
{
int V_32 ;
F_33 ( & V_4 -> V_8 ) ;
V_32 = F_27 ( V_2 , V_4 , V_7 , V_30 , V_31 ) ;
F_16 ( & V_4 -> V_8 ) ;
return V_32 ;
}
void F_34 ( struct V_6 * V_4 ,
unsigned int V_10 )
{
struct V_1 * V_35 , * V_2 ;
F_20 ( & V_4 -> V_8 , V_23 ) ;
F_35 (mark, lmark, &group->marks_list, g_list) {
if ( V_2 -> V_10 & V_10 ) {
F_1 ( V_2 ) ;
F_6 ( V_2 , V_4 ) ;
F_3 ( V_2 ) ;
}
}
F_16 ( & V_4 -> V_8 ) ;
}
void F_36 ( struct V_6 * V_4 )
{
F_34 ( V_4 , ( unsigned int ) - 1 ) ;
}
void F_37 ( struct V_1 * V_36 , struct V_1 * V_37 )
{
F_23 ( & V_37 -> V_9 ) ;
V_36 -> V_13 . V_7 = V_37 -> V_13 . V_7 ;
V_36 -> V_38 . V_30 = V_37 -> V_38 . V_30 ;
if ( V_37 -> V_4 )
F_28 ( V_37 -> V_4 ) ;
V_36 -> V_4 = V_37 -> V_4 ;
V_36 -> V_24 = V_37 -> V_24 ;
V_36 -> V_5 = V_37 -> V_5 ;
}
void F_38 ( struct V_1 * V_2 ,
void (* V_5)( struct V_1 * V_2 ) )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_39 ( & V_2 -> V_9 ) ;
F_40 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_5 = V_5 ;
}
static int F_41 ( void * V_39 )
{
struct V_1 * V_2 , * V_40 ;
struct V_41 V_42 ;
for (; ; ) {
F_9 ( & V_17 ) ;
F_42 ( & V_18 , & V_42 ) ;
F_10 ( & V_17 ) ;
F_43 ( & V_43 ) ;
F_35 (mark, next, &private_destroy_list, destroy_list) {
F_14 ( & V_2 -> V_18 ) ;
F_3 ( V_2 ) ;
}
F_44 ( V_19 , ! F_45 ( & V_18 ) ) ;
}
return 0 ;
}
static int T_2 F_46 ( void )
{
struct V_44 * V_45 ;
V_45 = F_47 ( F_41 , NULL ,
L_1 ) ;
if ( F_48 ( V_45 ) )
F_49 ( L_2 ) ;
return 0 ;
}
