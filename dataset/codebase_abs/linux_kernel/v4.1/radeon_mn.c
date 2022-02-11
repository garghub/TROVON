static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 , * V_9 ;
struct V_10 * V_11 , * V_12 ;
F_3 ( & V_6 -> V_13 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 (node, next_node, &rmn->objects,
it.rb) {
F_6 ( & V_8 -> V_15 , & V_4 -> V_16 ) ;
F_7 (bo, next_bo, &node->bos, mn_list) {
V_11 -> V_17 = NULL ;
F_8 ( & V_11 -> V_18 ) ;
}
F_9 ( V_8 ) ;
}
F_10 ( & V_4 -> V_14 ) ;
F_10 ( & V_6 -> V_13 ) ;
F_11 ( & V_4 -> V_17 , V_4 -> V_19 ) ;
F_9 ( V_4 ) ;
}
static void F_12 ( struct V_20 * V_17 ,
struct V_21 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_17 , struct V_3 , V_17 ) ;
F_13 ( & V_4 -> V_2 , F_1 ) ;
F_14 ( & V_4 -> V_2 ) ;
}
static void F_15 ( struct V_20 * V_17 ,
struct V_21 * V_19 ,
unsigned long V_22 ,
unsigned long V_23 )
{
struct V_3 * V_4 = F_2 ( V_17 , struct V_3 , V_17 ) ;
struct V_24 * V_15 ;
V_23 -= 1 ;
F_3 ( & V_4 -> V_14 ) ;
V_15 = F_16 ( & V_4 -> V_16 , V_22 , V_23 ) ;
while ( V_15 ) {
struct V_7 * V_8 ;
struct V_10 * V_11 ;
long V_25 ;
V_8 = F_2 ( V_15 , struct V_7 , V_15 ) ;
V_15 = F_17 ( V_15 , V_22 , V_23 ) ;
F_18 (bo, &node->bos, mn_list) {
if ( ! V_11 -> V_26 . V_27 || V_11 -> V_26 . V_27 -> V_28 != V_29 )
continue;
V_25 = F_19 ( V_11 , true ) ;
if ( V_25 ) {
F_20 ( L_1 , V_25 ) ;
continue;
}
V_25 = F_21 ( V_11 -> V_26 . V_30 ,
true , false , V_31 ) ;
if ( V_25 <= 0 )
F_20 ( L_2 , V_25 ) ;
F_22 ( V_11 , V_32 ) ;
V_25 = F_23 ( & V_11 -> V_26 , & V_11 -> V_33 , false , false ) ;
if ( V_25 )
F_20 ( L_3 , V_25 ) ;
F_24 ( V_11 ) ;
}
}
F_10 ( & V_4 -> V_14 ) ;
}
static struct V_3 * F_25 ( struct V_5 * V_6 )
{
struct V_21 * V_19 = V_34 -> V_19 ;
struct V_3 * V_4 ;
int V_25 ;
F_26 ( & V_19 -> V_35 ) ;
F_3 ( & V_6 -> V_13 ) ;
F_27 (rdev->mn_hash, rmn, node, (unsigned long)mm)
if ( V_4 -> V_19 == V_19 )
goto V_36;
V_4 = F_28 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 ) {
V_4 = F_29 ( - V_38 ) ;
goto V_36;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_17 . V_39 = & V_40 ;
F_30 ( & V_4 -> V_14 ) ;
V_4 -> V_16 = V_41 ;
V_25 = F_31 ( & V_4 -> V_17 , V_19 ) ;
if ( V_25 )
goto V_42;
F_32 ( V_6 -> V_43 , & V_4 -> V_8 , ( unsigned long ) V_19 ) ;
V_36:
F_10 ( & V_6 -> V_13 ) ;
F_33 ( & V_19 -> V_35 ) ;
return V_4 ;
V_42:
F_10 ( & V_6 -> V_13 ) ;
F_33 ( & V_19 -> V_35 ) ;
F_9 ( V_4 ) ;
return F_29 ( V_25 ) ;
}
int F_34 ( struct V_10 * V_11 , unsigned long V_44 )
{
unsigned long V_23 = V_44 + F_35 ( V_11 ) - 1 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_3 * V_4 ;
struct V_7 * V_8 = NULL ;
struct V_45 V_46 ;
struct V_24 * V_15 ;
V_4 = F_25 ( V_6 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
F_38 ( & V_46 ) ;
F_3 ( & V_4 -> V_14 ) ;
while ( ( V_15 = F_16 ( & V_4 -> V_16 , V_44 , V_23 ) ) ) {
F_9 ( V_8 ) ;
V_8 = F_2 ( V_15 , struct V_7 , V_15 ) ;
F_6 ( & V_8 -> V_15 , & V_4 -> V_16 ) ;
V_44 = F_39 ( V_15 -> V_22 , V_44 ) ;
V_23 = F_40 ( V_15 -> V_47 , V_23 ) ;
F_41 ( & V_8 -> V_46 , & V_46 ) ;
}
if ( ! V_8 ) {
V_8 = F_42 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_8 ) {
F_10 ( & V_4 -> V_14 ) ;
return - V_38 ;
}
}
V_11 -> V_17 = V_4 ;
V_8 -> V_15 . V_22 = V_44 ;
V_8 -> V_15 . V_47 = V_23 ;
F_38 ( & V_8 -> V_46 ) ;
F_41 ( & V_46 , & V_8 -> V_46 ) ;
F_43 ( & V_11 -> V_18 , & V_8 -> V_46 ) ;
F_44 ( & V_8 -> V_15 , & V_4 -> V_16 ) ;
F_10 ( & V_4 -> V_14 ) ;
return 0 ;
}
void F_45 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_3 * V_4 ;
struct V_45 * V_48 ;
F_3 ( & V_6 -> V_13 ) ;
V_4 = V_11 -> V_17 ;
if ( V_4 == NULL ) {
F_10 ( & V_6 -> V_13 ) ;
return;
}
F_3 ( & V_4 -> V_14 ) ;
V_48 = V_11 -> V_18 . V_49 ;
V_11 -> V_17 = NULL ;
F_46 ( & V_11 -> V_18 ) ;
if ( F_47 ( V_48 ) ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_48 , struct V_7 , V_46 ) ;
F_6 ( & V_8 -> V_15 , & V_4 -> V_16 ) ;
F_9 ( V_8 ) ;
}
F_10 ( & V_4 -> V_14 ) ;
F_10 ( & V_6 -> V_13 ) ;
}
