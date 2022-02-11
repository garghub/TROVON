static struct V_1 * F_1 ( struct V_2 * V_3 , unsigned long V_4 )
{
void * V_5 = ( void V_6 * ) V_3 -> V_5 ;
struct V_1 * V_1 ;
if ( F_2 ( V_5 + V_4 ) )
V_1 = F_3 ( V_5 + V_4 ) ;
else
V_1 = F_4 ( ( V_3 -> V_7 . V_8 + V_4 ) >> V_9 ) ;
return V_1 ;
}
static int F_5 ( struct V_10 * V_11 )
{
unsigned long V_12 ;
struct V_1 * V_1 ;
struct V_2 * V_3 = V_11 -> V_13 -> V_14 ;
V_12 = V_11 -> V_15 << V_9 ;
if ( V_12 >= V_3 -> V_7 . V_16 )
return V_17 ;
V_1 = F_1 ( V_3 , V_12 ) ;
if ( ! V_1 )
return V_17 ;
F_6 ( V_1 ) ;
if ( V_11 -> V_13 -> V_18 )
V_1 -> V_19 = V_11 -> V_13 -> V_18 -> V_20 ;
else
F_7 ( V_21 L_1 ) ;
F_8 ( ! V_1 -> V_19 ) ;
V_1 -> V_22 = V_11 -> V_15 ;
V_11 -> V_1 = V_1 ;
return 0 ;
}
int F_9 ( struct V_23 * V_23 , T_1 V_24 , T_1 V_25 , int V_26 )
{
struct V_2 * V_3 = V_23 -> V_27 ;
struct V_28 * V_28 = F_10 ( V_23 ) ;
int V_29 = F_11 ( V_23 , V_24 , V_25 ) ;
if ( V_29 )
return V_29 ;
if ( ! V_3 -> V_30 )
return 0 ;
F_12 ( V_28 ) ;
F_13 ( & V_3 -> V_31 ) ;
F_14 ( & V_3 -> V_31 , 0 ) ;
F_15 ( V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_1 * V_1 = V_11 -> V_1 ;
struct V_2 * V_3 = V_11 -> V_13 -> V_14 ;
struct V_32 * V_30 = V_3 -> V_30 ;
struct V_1 * V_33 ;
F_17 ( V_11 -> V_13 -> V_18 ) ;
F_18 ( & V_30 -> V_34 ) ;
if ( V_30 -> V_35 && F_19 ( & V_30 -> V_36 ) )
V_30 -> V_35 ( V_3 ) ;
F_20 ( V_1 ) ;
F_21 (cur, &fbdefio->pagelist, lru) {
if ( F_22 ( V_33 == V_1 ) )
goto V_37;
else if ( V_33 -> V_22 > V_1 -> V_22 )
break;
}
F_23 ( & V_1 -> V_38 , & V_33 -> V_38 ) ;
V_37:
F_24 ( & V_30 -> V_34 ) ;
F_14 ( & V_3 -> V_31 , V_30 -> V_39 ) ;
return V_40 ;
}
static int F_25 ( struct V_1 * V_1 )
{
if ( ! F_26 ( V_1 ) )
F_27 ( V_1 ) ;
return 0 ;
}
int F_28 ( struct V_2 * V_3 , struct V_41 * V_13 )
{
V_13 -> V_42 = & V_43 ;
V_13 -> V_44 |= V_45 | V_46 ;
if ( ! ( V_3 -> V_47 & V_48 ) )
V_13 -> V_44 |= V_49 ;
V_13 -> V_14 = V_3 ;
return 0 ;
}
static void F_29 ( struct V_50 * V_51 )
{
struct V_2 * V_3 = F_30 ( V_51 , struct V_2 ,
V_31 . V_51 ) ;
struct V_52 * V_53 , * V_54 ;
struct V_1 * V_33 ;
struct V_32 * V_30 = V_3 -> V_30 ;
F_18 ( & V_30 -> V_34 ) ;
F_21 (cur, &fbdefio->pagelist, lru) {
F_20 ( V_33 ) ;
F_31 ( V_33 ) ;
F_32 ( V_33 ) ;
}
V_30 -> V_55 ( V_3 , & V_30 -> V_36 ) ;
F_33 (node, next, &fbdefio->pagelist) {
F_34 ( V_53 ) ;
}
F_24 ( & V_30 -> V_34 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
struct V_32 * V_30 = V_3 -> V_30 ;
F_8 ( ! V_30 ) ;
F_36 ( & V_30 -> V_34 ) ;
V_3 -> V_56 -> V_57 = F_28 ;
F_37 ( & V_3 -> V_31 , F_29 ) ;
F_38 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_39 == 0 )
V_30 -> V_39 = V_58 ;
}
void F_39 ( struct V_2 * V_3 ,
struct V_28 * V_28 ,
struct V_23 * V_23 )
{
V_23 -> V_20 -> V_59 = & V_60 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_32 * V_30 = V_3 -> V_30 ;
struct V_1 * V_1 ;
int V_61 ;
F_8 ( ! V_30 ) ;
F_13 ( & V_3 -> V_31 ) ;
for ( V_61 = 0 ; V_61 < V_3 -> V_7 . V_16 ; V_61 += V_62 ) {
V_1 = F_1 ( V_3 , V_61 ) ;
V_1 -> V_19 = NULL ;
}
V_3 -> V_56 -> V_57 = NULL ;
F_41 ( & V_30 -> V_34 ) ;
}
