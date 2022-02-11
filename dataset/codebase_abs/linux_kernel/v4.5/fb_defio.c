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
struct V_29 * V_29 = F_10 ( V_24 ) ;
int V_30 = F_11 ( V_29 -> V_31 , V_25 , V_26 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_3 -> V_32 )
return 0 ;
F_12 ( V_29 ) ;
F_13 ( & V_3 -> V_33 ) ;
F_14 ( & V_3 -> V_33 , 0 ) ;
F_15 ( V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
struct V_2 * V_3 = V_11 -> V_15 ;
struct V_34 * V_32 = V_3 -> V_32 ;
struct V_1 * V_35 ;
F_17 ( V_11 -> V_19 ) ;
F_18 ( & V_32 -> V_36 ) ;
if ( V_32 -> V_37 && F_19 ( & V_32 -> V_38 ) )
V_32 -> V_37 ( V_3 ) ;
F_20 ( V_1 ) ;
F_21 (cur, &fbdefio->pagelist, lru) {
if ( F_22 ( V_35 == V_1 ) )
goto V_39;
else if ( V_35 -> V_23 > V_1 -> V_23 )
break;
}
F_23 ( & V_1 -> V_40 , & V_35 -> V_40 ) ;
V_39:
F_24 ( & V_32 -> V_36 ) ;
F_14 ( & V_3 -> V_33 , V_32 -> V_41 ) ;
return V_42 ;
}
static int F_25 ( struct V_1 * V_1 )
{
if ( ! F_26 ( V_1 ) )
F_27 ( V_1 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
V_11 -> V_43 = & V_44 ;
V_11 -> V_45 |= V_46 | V_47 ;
if ( ! ( V_3 -> V_48 & V_49 ) )
V_11 -> V_45 |= V_50 ;
V_11 -> V_15 = V_3 ;
return 0 ;
}
static void F_29 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_30 ( V_52 , struct V_2 ,
V_33 . V_52 ) ;
struct V_53 * V_54 , * V_55 ;
struct V_1 * V_35 ;
struct V_34 * V_32 = V_3 -> V_32 ;
F_18 ( & V_32 -> V_36 ) ;
F_21 (cur, &fbdefio->pagelist, lru) {
F_20 ( V_35 ) ;
F_31 ( V_35 ) ;
F_32 ( V_35 ) ;
}
V_32 -> V_56 ( V_3 , & V_32 -> V_38 ) ;
F_33 (node, next, &fbdefio->pagelist) {
F_34 ( V_54 ) ;
}
F_24 ( & V_32 -> V_36 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
struct V_34 * V_32 = V_3 -> V_32 ;
F_8 ( ! V_32 ) ;
F_36 ( & V_32 -> V_36 ) ;
V_3 -> V_57 -> V_58 = F_28 ;
F_37 ( & V_3 -> V_33 , F_29 ) ;
F_38 ( & V_32 -> V_38 ) ;
if ( V_32 -> V_41 == 0 )
V_32 -> V_41 = V_59 ;
}
void F_39 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
struct V_24 * V_24 )
{
V_24 -> V_21 -> V_60 = & V_61 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_34 * V_32 = V_3 -> V_32 ;
struct V_1 * V_1 ;
int V_62 ;
F_8 ( ! V_32 ) ;
F_13 ( & V_3 -> V_33 ) ;
for ( V_62 = 0 ; V_62 < V_3 -> V_7 . V_17 ; V_62 += V_63 ) {
V_1 = F_1 ( V_3 , V_62 ) ;
V_1 -> V_20 = NULL ;
}
V_3 -> V_57 -> V_58 = NULL ;
F_41 ( & V_32 -> V_36 ) ;
}
