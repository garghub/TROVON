static inline int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return memcmp ( V_2 , V_3 , sizeof( * V_2 ) ) == 0 ;
}
static void F_2 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
F_3 ( V_4 , V_6 ) ;
if ( F_4 ( V_4 -> V_7 ) ) {
V_4 -> V_8 = & V_9 ;
V_4 -> V_10 = & V_11 ;
} else if ( F_5 ( V_4 -> V_7 ) ) {
V_4 -> V_8 = & V_12 ;
V_4 -> V_10 = & V_13 ;
} else if ( F_6 ( V_4 -> V_7 ) ) {
V_4 -> V_8 = & V_14 ;
F_7 ( V_4 ) ;
V_4 -> V_15 . V_16 = & V_17 ;
V_4 -> V_18 = & V_4 -> V_15 ;
} else
F_8 ( V_4 , V_4 -> V_7 , F_9 ( V_6 -> V_19 ) ) ;
}
static int F_10 ( struct V_4 * V_4 , void * V_20 )
{
struct V_1 * V_21 = (struct V_1 * ) V_20 ;
struct V_22 * V_23 = F_11 ( V_4 ) ;
return F_1 ( & V_23 -> V_24 , V_21 ) ;
}
static int F_12 ( struct V_4 * V_4 , void * V_20 )
{
struct V_1 * V_21 = (struct V_1 * ) V_20 ;
struct V_22 * V_23 = F_11 ( V_4 ) ;
V_23 -> V_24 = * V_21 ;
return 0 ;
}
struct V_4 * F_13 ( struct V_25 * V_26 , struct V_1 * V_21 ,
struct V_5 * V_6 )
{
struct V_4 * V_4 ;
struct V_22 * V_23 ;
unsigned long V_27 = F_14 ( V_21 ) ;
V_4 = F_15 ( V_26 , V_27 , F_10 , F_12 , V_21 ) ;
if ( ! V_4 )
return F_16 ( - V_28 ) ;
if ( V_4 -> V_29 & V_30 ) {
V_23 = F_11 ( V_4 ) ;
V_4 -> V_31 = V_27 ;
V_23 -> V_32 = 0 ;
F_17 ( V_4 ) ;
}
F_2 ( V_4 , V_6 ) ;
return V_4 ;
}
struct V_4 * F_18 ( struct V_1 * V_21 , struct V_25 * V_26 )
{
struct V_5 V_6 ;
struct V_4 * V_4 ;
int error ;
error = F_19 ( V_26 , V_21 , & V_6 ) ;
if ( error )
return F_16 ( error ) ;
V_4 = F_13 ( V_26 , V_21 , & V_6 ) ;
if ( F_20 ( V_4 ) )
F_21 ( L_1 , V_33 ) ;
return V_4 ;
}
void F_22 ( struct V_4 * V_4 , struct V_1 * V_34 ,
struct V_1 * V_35 )
{
struct V_22 * V_23 = F_11 ( V_4 ) ;
unsigned long V_27 = F_14 ( V_35 ) ;
F_23 ( ! F_1 ( & V_23 -> V_24 , V_34 ) ) ;
F_24 ( V_4 ) ;
V_23 -> V_24 = * V_35 ;
V_4 -> V_31 = V_27 ;
F_25 ( V_4 , V_27 ) ;
}
struct V_4 * F_26 ( struct V_1 * V_21 , struct V_25 * V_26 )
{
struct V_4 * V_4 ;
unsigned long V_27 = F_14 ( V_21 ) ;
if ( ! V_26 ) {
F_21 ( L_2 , V_33 ) ;
return NULL ;
}
V_4 = F_27 ( V_26 , V_27 , F_10 , V_21 ) ;
if ( ! V_4 )
return NULL ;
F_23 ( V_4 -> V_29 & V_30 ) ;
return V_4 ;
}
struct V_4 * F_28 ( struct V_25 * V_26 )
{
struct V_4 * V_4 = F_29 ( V_26 ) ;
if ( V_4 ) {
V_4 -> V_31 = V_36 ;
V_4 -> V_8 = & V_37 ;
V_4 -> V_10 = & V_38 ;
V_4 -> V_7 = 0444 ;
return V_4 ;
}
return F_16 ( - V_28 ) ;
}
