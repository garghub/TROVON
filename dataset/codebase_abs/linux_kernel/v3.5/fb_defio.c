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
static int F_5 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
unsigned long V_14 ;
struct V_1 * V_1 ;
struct V_2 * V_3 = V_11 -> V_15 ;
V_14 = V_13 -> V_16 << V_9 ;
if ( V_14 >= V_3 -> V_7 . V_17 )
return V_18 ;
V_1 = F_1 ( V_3 , V_14 ) ;
if ( ! V_1 )
return V_18 ;
F_6 ( V_1 ) ;
if ( V_11 -> V_19 )
V_1 -> V_20 = V_11 -> V_19 -> V_21 ;
else
F_7 ( V_22 L_1 ) ;
F_8 ( ! V_1 -> V_20 ) ;
V_1 -> V_23 = V_13 -> V_16 ;
V_13 -> V_1 = V_1 ;
return 0 ;
}
int F_9 ( struct V_24 * V_24 , T_1 V_25 , T_1 V_26 , int V_27 )
{
struct V_2 * V_3 = V_24 -> V_28 ;
struct V_29 * V_29 = V_24 -> V_30 . V_31 -> V_32 ;
int V_33 = F_10 ( V_29 -> V_34 , V_25 , V_26 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_3 -> V_35 )
return 0 ;
F_11 ( & V_29 -> V_36 ) ;
F_12 ( & V_3 -> V_37 ) ;
V_33 = F_13 ( & V_3 -> V_37 , 0 ) ;
F_14 ( & V_29 -> V_36 ) ;
return V_33 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
struct V_2 * V_3 = V_11 -> V_15 ;
struct V_38 * V_35 = V_3 -> V_35 ;
struct V_1 * V_39 ;
F_11 ( & V_35 -> V_40 ) ;
if ( V_35 -> V_41 && F_16 ( & V_35 -> V_42 ) )
V_35 -> V_41 ( V_3 ) ;
F_17 ( V_1 ) ;
F_18 (cur, &fbdefio->pagelist, lru) {
if ( F_19 ( V_39 == V_1 ) )
goto V_43;
else if ( V_39 -> V_23 > V_1 -> V_23 )
break;
}
F_20 ( & V_1 -> V_44 , & V_39 -> V_44 ) ;
V_43:
F_14 ( & V_35 -> V_40 ) ;
F_13 ( & V_3 -> V_37 , V_35 -> V_45 ) ;
return V_46 ;
}
static int F_21 ( struct V_1 * V_1 )
{
if ( ! F_22 ( V_1 ) )
F_23 ( V_1 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
V_11 -> V_47 = & V_48 ;
V_11 -> V_49 |= ( V_50 | V_51 ) ;
if ( ! ( V_3 -> V_52 & V_53 ) )
V_11 -> V_49 |= V_54 ;
V_11 -> V_15 = V_3 ;
return 0 ;
}
static void F_25 ( struct V_55 * V_56 )
{
struct V_2 * V_3 = F_26 ( V_56 , struct V_2 ,
V_37 . V_56 ) ;
struct V_57 * V_58 , * V_59 ;
struct V_1 * V_39 ;
struct V_38 * V_35 = V_3 -> V_35 ;
F_11 ( & V_35 -> V_40 ) ;
F_18 (cur, &fbdefio->pagelist, lru) {
F_17 ( V_39 ) ;
F_27 ( V_39 ) ;
F_28 ( V_39 ) ;
}
V_35 -> V_60 ( V_3 , & V_35 -> V_42 ) ;
F_29 (node, next, &fbdefio->pagelist) {
F_30 ( V_58 ) ;
}
F_14 ( & V_35 -> V_40 ) ;
}
void F_31 ( struct V_2 * V_3 )
{
struct V_38 * V_35 = V_3 -> V_35 ;
F_8 ( ! V_35 ) ;
F_32 ( & V_35 -> V_40 ) ;
V_3 -> V_61 -> V_62 = F_24 ;
F_33 ( & V_3 -> V_37 , F_25 ) ;
F_34 ( & V_35 -> V_42 ) ;
if ( V_35 -> V_45 == 0 )
V_35 -> V_45 = V_63 ;
}
void F_35 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
struct V_24 * V_24 )
{
V_24 -> V_21 -> V_64 = & V_65 ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_38 * V_35 = V_3 -> V_35 ;
struct V_1 * V_1 ;
int V_66 ;
F_8 ( ! V_35 ) ;
F_12 ( & V_3 -> V_37 ) ;
for ( V_66 = 0 ; V_66 < V_3 -> V_7 . V_17 ; V_66 += V_67 ) {
V_1 = F_1 ( V_3 , V_66 ) ;
V_1 -> V_20 = NULL ;
}
V_3 -> V_61 -> V_62 = NULL ;
F_37 ( & V_35 -> V_40 ) ;
}
