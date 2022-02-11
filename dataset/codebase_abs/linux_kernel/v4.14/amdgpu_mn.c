static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 , * V_9 ;
struct V_10 * V_11 , * V_12 ;
F_3 ( & V_6 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 (node, next_node,
&rmn->objects.rb_root, it.rb) {
F_6 (bo, next_bo, &node->bos, mn_list) {
V_11 -> V_15 = NULL ;
F_7 ( & V_11 -> V_16 ) ;
}
F_8 ( V_8 ) ;
}
F_9 ( & V_4 -> V_14 ) ;
F_9 ( & V_6 -> V_13 ) ;
F_10 ( & V_4 -> V_15 , V_4 -> V_17 ) ;
F_8 ( V_4 ) ;
}
static void F_11 ( struct V_18 * V_15 ,
struct V_19 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_15 , struct V_3 , V_15 ) ;
F_12 ( & V_4 -> V_2 , F_1 ) ;
F_13 ( & V_4 -> V_2 ) ;
}
static void F_14 ( struct V_7 * V_8 ,
unsigned long V_20 ,
unsigned long V_21 )
{
struct V_10 * V_11 ;
long V_22 ;
F_15 (bo, &node->bos, mn_list) {
if ( ! F_16 ( V_11 -> V_23 . V_24 , V_20 , V_21 ) )
continue;
V_22 = F_17 ( V_11 , true ) ;
if ( V_22 ) {
F_18 ( L_1 , V_22 ) ;
continue;
}
V_22 = F_19 ( V_11 -> V_23 . V_25 ,
true , false , V_26 ) ;
if ( V_22 <= 0 )
F_18 ( L_2 , V_22 ) ;
F_20 ( V_11 , V_27 ) ;
V_22 = F_21 ( & V_11 -> V_23 , & V_11 -> V_28 , false , false ) ;
if ( V_22 )
F_18 ( L_3 , V_22 ) ;
F_22 ( V_11 ) ;
}
}
static void F_23 ( struct V_18 * V_15 ,
struct V_19 * V_17 ,
unsigned long V_20 ,
unsigned long V_21 )
{
struct V_3 * V_4 = F_2 ( V_15 , struct V_3 , V_15 ) ;
struct V_29 * V_30 ;
V_21 -= 1 ;
F_3 ( & V_4 -> V_14 ) ;
V_30 = F_24 ( & V_4 -> V_31 , V_20 , V_21 ) ;
while ( V_30 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_30 , struct V_7 , V_30 ) ;
V_30 = F_25 ( V_30 , V_20 , V_21 ) ;
F_14 ( V_8 , V_20 , V_21 ) ;
}
F_9 ( & V_4 -> V_14 ) ;
}
static struct V_3 * F_26 ( struct V_5 * V_6 )
{
struct V_19 * V_17 = V_32 -> V_17 ;
struct V_3 * V_4 ;
int V_22 ;
F_3 ( & V_6 -> V_13 ) ;
if ( F_27 ( & V_17 -> V_33 ) ) {
F_9 ( & V_6 -> V_13 ) ;
return F_28 ( - V_34 ) ;
}
F_29 (adev->mn_hash, rmn, node, (unsigned long)mm)
if ( V_4 -> V_17 == V_17 )
goto V_35;
V_4 = F_30 ( sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 ) {
V_4 = F_28 ( - V_37 ) ;
goto V_35;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_15 . V_38 = & V_39 ;
F_31 ( & V_4 -> V_14 ) ;
V_4 -> V_31 = V_40 ;
V_22 = F_32 ( & V_4 -> V_15 , V_17 ) ;
if ( V_22 )
goto V_41;
F_33 ( V_6 -> V_42 , & V_4 -> V_8 , ( unsigned long ) V_17 ) ;
V_35:
F_34 ( & V_17 -> V_33 ) ;
F_9 ( & V_6 -> V_13 ) ;
return V_4 ;
V_41:
F_34 ( & V_17 -> V_33 ) ;
F_9 ( & V_6 -> V_13 ) ;
F_8 ( V_4 ) ;
return F_28 ( V_22 ) ;
}
int F_35 ( struct V_10 * V_11 , unsigned long V_43 )
{
unsigned long V_21 = V_43 + F_36 ( V_11 ) - 1 ;
struct V_5 * V_6 = F_37 ( V_11 -> V_23 . V_44 ) ;
struct V_3 * V_4 ;
struct V_7 * V_8 = NULL ;
struct V_45 V_46 ;
struct V_29 * V_30 ;
V_4 = F_26 ( V_6 ) ;
if ( F_38 ( V_4 ) )
return F_39 ( V_4 ) ;
F_40 ( & V_46 ) ;
F_3 ( & V_4 -> V_14 ) ;
while ( ( V_30 = F_24 ( & V_4 -> V_31 , V_43 , V_21 ) ) ) {
F_8 ( V_8 ) ;
V_8 = F_2 ( V_30 , struct V_7 , V_30 ) ;
F_41 ( & V_8 -> V_30 , & V_4 -> V_31 ) ;
V_43 = F_42 ( V_30 -> V_20 , V_43 ) ;
V_21 = F_43 ( V_30 -> V_47 , V_21 ) ;
F_44 ( & V_8 -> V_46 , & V_46 ) ;
}
if ( ! V_8 ) {
V_8 = F_45 ( sizeof( struct V_7 ) , V_36 ) ;
if ( ! V_8 ) {
F_9 ( & V_4 -> V_14 ) ;
return - V_37 ;
}
}
V_11 -> V_15 = V_4 ;
V_8 -> V_30 . V_20 = V_43 ;
V_8 -> V_30 . V_47 = V_21 ;
F_40 ( & V_8 -> V_46 ) ;
F_44 ( & V_46 , & V_8 -> V_46 ) ;
F_46 ( & V_11 -> V_16 , & V_8 -> V_46 ) ;
F_47 ( & V_8 -> V_30 , & V_4 -> V_31 ) ;
F_9 ( & V_4 -> V_14 ) ;
return 0 ;
}
void F_48 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_37 ( V_11 -> V_23 . V_44 ) ;
struct V_3 * V_4 ;
struct V_45 * V_48 ;
F_3 ( & V_6 -> V_13 ) ;
V_4 = V_11 -> V_15 ;
if ( V_4 == NULL ) {
F_9 ( & V_6 -> V_13 ) ;
return;
}
F_3 ( & V_4 -> V_14 ) ;
V_48 = V_11 -> V_16 . V_49 ;
V_11 -> V_15 = NULL ;
F_7 ( & V_11 -> V_16 ) ;
if ( F_49 ( V_48 ) ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_48 , struct V_7 , V_46 ) ;
F_41 ( & V_8 -> V_30 , & V_4 -> V_31 ) ;
F_8 ( V_8 ) ;
}
F_9 ( & V_4 -> V_14 ) ;
F_9 ( & V_6 -> V_13 ) ;
}
