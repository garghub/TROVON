static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
T_1 F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
T_1 V_9 ;
F_5 ( & V_5 -> V_10 , V_8 ) ;
V_9 = F_6 ( V_3 ) ;
F_7 ( & V_7 -> V_11 , & V_5 -> V_12 ) ;
F_8 ( & V_5 -> V_10 , V_8 ) ;
F_9 ( V_5 -> V_6 . V_13 -> V_14 , L_1 ,
V_5 , V_7 , V_9 ) ;
return V_9 ;
}
struct V_1 * F_10 ( struct V_4 * V_5 ,
T_1 V_9 )
{
struct V_1 * V_7 ;
F_11 (vd, &vc->desc_issued, node)
if ( V_7 -> V_3 . V_9 == V_9 )
return V_7 ;
return NULL ;
}
static void F_12 ( unsigned long V_15 )
{
struct V_4 * V_5 = (struct V_4 * ) V_15 ;
struct V_1 * V_7 ;
T_2 V_16 = NULL ;
void * V_17 = NULL ;
F_13 ( V_18 ) ;
F_14 ( & V_5 -> V_10 ) ;
F_15 ( & V_5 -> V_19 , & V_18 ) ;
V_7 = V_5 -> V_20 ;
if ( V_7 ) {
V_5 -> V_20 = NULL ;
V_16 = V_7 -> V_3 . V_21 ;
V_17 = V_7 -> V_3 . V_22 ;
}
F_16 ( & V_5 -> V_10 ) ;
if ( V_16 )
V_16 ( V_17 ) ;
while ( ! F_17 ( & V_18 ) ) {
V_7 = F_18 ( & V_18 , struct V_1 , V_11 ) ;
V_16 = V_7 -> V_3 . V_21 ;
V_17 = V_7 -> V_3 . V_22 ;
F_19 ( & V_7 -> V_11 ) ;
V_5 -> V_23 ( V_7 ) ;
if ( V_16 )
V_16 ( V_17 ) ;
}
}
void F_20 ( struct V_4 * V_5 , struct V_24 * V_18 )
{
while ( ! F_17 ( V_18 ) ) {
struct V_1 * V_7 = F_18 ( V_18 ,
struct V_1 , V_11 ) ;
F_19 ( & V_7 -> V_11 ) ;
F_9 ( V_5 -> V_6 . V_13 -> V_14 , L_2 , V_7 ) ;
V_5 -> V_23 ( V_7 ) ;
}
}
void F_21 ( struct V_4 * V_5 , struct V_25 * V_26 )
{
F_22 ( & V_5 -> V_6 ) ;
F_23 ( & V_5 -> V_10 ) ;
F_24 ( & V_5 -> V_12 ) ;
F_24 ( & V_5 -> V_27 ) ;
F_24 ( & V_5 -> V_19 ) ;
F_25 ( & V_5 -> V_28 , F_12 , ( unsigned long ) V_5 ) ;
V_5 -> V_6 . V_13 = V_26 ;
F_7 ( & V_5 -> V_6 . V_29 , & V_26 -> V_30 ) ;
}
