static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 , * V_9 ;
F_3 ( & V_6 -> V_10 ) ;
F_3 ( & V_4 -> V_11 ) ;
F_4 ( & V_4 -> V_12 ) ;
F_5 (bo, next, &rmn->objects, mn_it.rb) {
F_6 ( & V_8 -> V_13 , & V_4 -> V_14 ) ;
V_8 -> V_15 = NULL ;
}
F_7 ( & V_4 -> V_11 ) ;
F_7 ( & V_6 -> V_10 ) ;
F_8 ( & V_4 -> V_15 , V_4 -> V_16 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_17 * V_15 ,
struct V_18 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_15 , struct V_3 , V_15 ) ;
F_11 ( & V_4 -> V_2 , F_1 ) ;
F_12 ( & V_4 -> V_2 ) ;
}
static void F_13 ( struct V_17 * V_15 ,
struct V_18 * V_16 ,
unsigned long V_19 ,
unsigned long V_20 )
{
struct V_3 * V_4 = F_2 ( V_15 , struct V_3 , V_15 ) ;
struct V_21 * V_22 ;
V_20 -= 1 ;
F_3 ( & V_4 -> V_11 ) ;
V_22 = F_14 ( & V_4 -> V_14 , V_19 , V_20 ) ;
while ( V_22 ) {
struct V_7 * V_8 ;
struct V_23 * V_23 ;
int V_24 ;
V_8 = F_2 ( V_22 , struct V_7 , V_13 ) ;
V_22 = F_15 ( V_22 , V_19 , V_20 ) ;
V_24 = F_16 ( V_8 , true ) ;
if ( V_24 ) {
F_17 ( L_1 , V_24 ) ;
continue;
}
V_23 = F_18 ( V_8 -> V_25 . V_26 ) ;
if ( V_23 ) {
V_24 = F_19 ( (struct V_27 * ) V_23 , false ) ;
if ( V_24 )
F_17 ( L_2 , V_24 ) ;
}
F_20 ( V_8 , V_28 ) ;
V_24 = F_21 ( & V_8 -> V_25 , & V_8 -> V_29 , false , false ) ;
if ( V_24 )
F_17 ( L_3 , V_24 ) ;
F_22 ( V_8 ) ;
}
F_7 ( & V_4 -> V_11 ) ;
}
static struct V_3 * F_23 ( struct V_5 * V_6 )
{
struct V_18 * V_16 = V_30 -> V_16 ;
struct V_3 * V_4 ;
int V_24 ;
F_24 ( & V_16 -> V_31 ) ;
F_3 ( & V_6 -> V_10 ) ;
F_25 (rdev->mn_hash, rmn, node, (unsigned long)mm)
if ( V_4 -> V_16 == V_16 )
goto V_32;
V_4 = F_26 ( sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 ) {
V_4 = F_27 ( - V_34 ) ;
goto V_32;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_15 . V_35 = & V_36 ;
F_28 ( & V_4 -> V_11 ) ;
V_4 -> V_14 = V_37 ;
V_24 = F_29 ( & V_4 -> V_15 , V_16 ) ;
if ( V_24 )
goto V_38;
F_30 ( V_6 -> V_39 , & V_4 -> V_12 , ( unsigned long ) V_16 ) ;
V_32:
F_7 ( & V_6 -> V_10 ) ;
F_31 ( & V_16 -> V_31 ) ;
return V_4 ;
V_38:
F_7 ( & V_6 -> V_10 ) ;
F_31 ( & V_16 -> V_31 ) ;
F_9 ( V_4 ) ;
return F_27 ( V_24 ) ;
}
int F_32 ( struct V_7 * V_8 , unsigned long V_40 )
{
unsigned long V_20 = V_40 + F_33 ( V_8 ) - 1 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
V_4 = F_23 ( V_6 ) ;
if ( F_34 ( V_4 ) )
return F_35 ( V_4 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_22 = F_14 ( & V_4 -> V_14 , V_40 , V_20 ) ;
if ( V_22 ) {
F_7 ( & V_4 -> V_11 ) ;
return - V_41 ;
}
V_8 -> V_15 = V_4 ;
V_8 -> V_13 . V_19 = V_40 ;
V_8 -> V_13 . V_42 = V_20 ;
F_36 ( & V_8 -> V_13 , & V_4 -> V_14 ) ;
F_7 ( & V_4 -> V_11 ) ;
return 0 ;
}
void F_37 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_3 * V_4 ;
F_3 ( & V_6 -> V_10 ) ;
V_4 = V_8 -> V_15 ;
if ( V_4 == NULL ) {
F_7 ( & V_6 -> V_10 ) ;
return;
}
F_3 ( & V_4 -> V_11 ) ;
F_6 ( & V_8 -> V_13 , & V_4 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_7 ( & V_4 -> V_11 ) ;
F_7 ( & V_6 -> V_10 ) ;
}
