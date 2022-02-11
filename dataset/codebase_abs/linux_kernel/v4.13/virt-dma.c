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
int F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_8 ;
F_5 ( & V_5 -> V_10 , V_8 ) ;
F_11 ( & V_7 -> V_11 ) ;
F_8 ( & V_5 -> V_10 , V_8 ) ;
F_9 ( V_5 -> V_6 . V_13 -> V_14 , L_2 ,
V_5 , V_7 , V_7 -> V_3 . V_9 ) ;
V_5 -> V_15 ( V_7 ) ;
return 0 ;
}
struct V_1 * F_12 ( struct V_4 * V_5 ,
T_1 V_9 )
{
struct V_1 * V_7 ;
F_13 (vd, &vc->desc_issued, node)
if ( V_7 -> V_3 . V_9 == V_9 )
return V_7 ;
return NULL ;
}
static void F_14 ( unsigned long V_16 )
{
struct V_4 * V_5 = (struct V_4 * ) V_16 ;
struct V_1 * V_7 , * V_17 ;
struct V_18 V_19 ;
F_15 ( V_20 ) ;
F_16 ( & V_5 -> V_10 ) ;
F_17 ( & V_5 -> V_21 , & V_20 ) ;
V_7 = V_5 -> V_22 ;
if ( V_7 ) {
V_5 -> V_22 = NULL ;
F_18 ( & V_7 -> V_3 , & V_19 ) ;
} else {
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
}
F_19 ( & V_5 -> V_10 ) ;
F_20 ( & V_19 , NULL ) ;
F_21 (vd, _vd, &head, node) {
F_18 ( & V_7 -> V_3 , & V_19 ) ;
F_11 ( & V_7 -> V_11 ) ;
if ( F_22 ( & V_7 -> V_3 ) )
F_23 ( & V_7 -> V_11 , & V_5 -> V_23 ) ;
else
V_5 -> V_15 ( V_7 ) ;
F_20 ( & V_19 , NULL ) ;
}
}
void F_24 ( struct V_4 * V_5 , struct V_24 * V_20 )
{
struct V_1 * V_7 , * V_17 ;
F_21 (vd, _vd, head, node) {
if ( F_22 ( & V_7 -> V_3 ) ) {
F_7 ( & V_7 -> V_11 , & V_5 -> V_23 ) ;
} else {
F_9 ( V_5 -> V_6 . V_13 -> V_14 , L_3 , V_7 ) ;
F_11 ( & V_7 -> V_11 ) ;
V_5 -> V_15 ( V_7 ) ;
}
}
}
void F_25 ( struct V_4 * V_5 , struct V_25 * V_26 )
{
F_26 ( & V_5 -> V_6 ) ;
F_27 ( & V_5 -> V_10 ) ;
F_28 ( & V_5 -> V_23 ) ;
F_28 ( & V_5 -> V_12 ) ;
F_28 ( & V_5 -> V_27 ) ;
F_28 ( & V_5 -> V_21 ) ;
F_29 ( & V_5 -> V_28 , F_14 , ( unsigned long ) V_5 ) ;
V_5 -> V_6 . V_13 = V_26 ;
F_30 ( & V_5 -> V_6 . V_29 , & V_26 -> V_30 ) ;
}
