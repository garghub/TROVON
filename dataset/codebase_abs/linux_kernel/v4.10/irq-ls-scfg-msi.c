static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = F_3 ( V_6 -> V_8 ) ;
V_4 -> V_9 = F_4 ( V_6 -> V_8 ) ;
V_4 -> V_2 = V_2 -> V_10 << V_11 ;
}
static int F_5 ( struct V_1 * V_1 ,
const struct V_12 * V_13 , bool V_14 )
{
return - V_15 ;
}
static int F_6 ( struct V_16 * V_17 ,
unsigned int V_18 ,
unsigned int V_19 ,
void * args )
{
struct V_5 * V_6 = V_17 -> V_20 ;
int V_21 , V_22 = 0 ;
F_7 ( V_19 != 1 ) ;
F_8 ( & V_6 -> V_23 ) ;
V_21 = F_9 ( V_6 -> V_24 , V_25 ) ;
if ( V_21 < V_25 )
F_10 ( V_21 , V_6 -> V_24 ) ;
else
V_22 = - V_26 ;
F_11 ( & V_6 -> V_23 ) ;
if ( V_22 )
return V_22 ;
F_12 ( V_17 , V_18 , V_21 ,
& V_27 , V_6 ,
V_28 , NULL , NULL ) ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 ,
unsigned int V_18 , unsigned int V_19 )
{
struct V_1 * V_29 = F_14 ( V_17 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_29 ) ;
int V_21 ;
V_21 = V_29 -> V_10 ;
if ( V_21 < 0 || V_21 >= V_25 ) {
F_15 ( L_1 , V_21 ) ;
return;
}
F_8 ( & V_6 -> V_23 ) ;
F_16 ( V_21 , V_6 -> V_24 ) ;
F_11 ( & V_6 -> V_23 ) ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_5 * V_6 = F_18 ( V_31 ) ;
unsigned long V_32 ;
int V_21 , V_18 ;
F_19 ( F_20 ( V_31 ) , V_31 ) ;
V_32 = F_21 ( V_6 -> V_33 + V_34 ) ;
F_22 (pos, &val, MSI_MAX_IRQS) {
V_18 = F_23 ( V_6 -> V_35 , ( 31 - V_21 ) ) ;
if ( V_18 )
F_24 ( V_18 ) ;
}
F_25 ( F_20 ( V_31 ) , V_31 ) ;
}
static int F_26 ( struct V_5 * V_6 )
{
V_6 -> V_35 = F_27 ( NULL ,
V_25 ,
& V_36 ,
V_6 ) ;
if ( ! V_6 -> V_35 ) {
F_28 ( & V_6 -> V_37 -> V_38 , L_2 ) ;
return - V_39 ;
}
V_6 -> V_40 = F_29 (
F_30 ( V_6 -> V_37 -> V_38 . V_41 ) ,
& V_42 ,
V_6 -> V_35 ) ;
if ( ! V_6 -> V_40 ) {
F_28 ( & V_6 -> V_37 -> V_38 , L_3 ) ;
F_31 ( V_6 -> V_35 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_32 ( struct V_43 * V_37 )
{
struct V_5 * V_6 ;
struct V_44 * V_45 ;
int V_46 ;
V_6 = F_33 ( & V_37 -> V_38 , sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return - V_39 ;
V_45 = F_34 ( V_37 , V_48 , 0 ) ;
V_6 -> V_33 = F_35 ( & V_37 -> V_38 , V_45 ) ;
if ( F_36 ( V_6 -> V_33 ) ) {
F_28 ( & V_37 -> V_38 , L_4 ) ;
return F_37 ( V_6 -> V_33 ) ;
}
V_6 -> V_8 = V_45 -> V_49 ;
V_6 -> V_50 = F_38 ( V_37 , 0 ) ;
if ( V_6 -> V_50 <= 0 ) {
F_28 ( & V_37 -> V_38 , L_5 ) ;
return - V_51 ;
}
V_6 -> V_37 = V_37 ;
F_39 ( & V_6 -> V_23 ) ;
V_46 = F_26 ( V_6 ) ;
if ( V_46 )
return V_46 ;
F_40 ( V_6 -> V_50 ,
F_17 ,
V_6 ) ;
F_41 ( V_37 , V_6 ) ;
return 0 ;
}
static int F_42 ( struct V_43 * V_37 )
{
struct V_5 * V_6 = F_43 ( V_37 ) ;
F_40 ( V_6 -> V_50 , NULL , NULL ) ;
F_31 ( V_6 -> V_40 ) ;
F_31 ( V_6 -> V_35 ) ;
F_41 ( V_37 , NULL ) ;
return 0 ;
}
