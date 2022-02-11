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
F_12 ( & V_29 -> V_33 ) ;
F_13 ( & V_3 -> V_34 ) ;
F_14 ( & V_3 -> V_34 , 0 ) ;
F_15 ( & V_29 -> V_33 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
struct V_2 * V_3 = V_11 -> V_15 ;
struct V_35 * V_32 = V_3 -> V_32 ;
struct V_1 * V_36 ;
F_17 ( V_11 -> V_19 ) ;
F_12 ( & V_32 -> V_37 ) ;
if ( V_32 -> V_38 && F_18 ( & V_32 -> V_39 ) )
V_32 -> V_38 ( V_3 ) ;
F_19 ( V_1 ) ;
F_20 (cur, &fbdefio->pagelist, lru) {
if ( F_21 ( V_36 == V_1 ) )
goto V_40;
else if ( V_36 -> V_23 > V_1 -> V_23 )
break;
}
F_22 ( & V_1 -> V_41 , & V_36 -> V_41 ) ;
V_40:
F_15 ( & V_32 -> V_37 ) ;
F_14 ( & V_3 -> V_34 , V_32 -> V_42 ) ;
return V_43 ;
}
static int F_23 ( struct V_1 * V_1 )
{
if ( ! F_24 ( V_1 ) )
F_25 ( V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
V_11 -> V_44 = & V_45 ;
V_11 -> V_46 |= V_47 | V_48 ;
if ( ! ( V_3 -> V_49 & V_50 ) )
V_11 -> V_46 |= V_51 ;
V_11 -> V_15 = V_3 ;
return 0 ;
}
static void F_27 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = F_28 ( V_53 , struct V_2 ,
V_34 . V_53 ) ;
struct V_54 * V_55 , * V_56 ;
struct V_1 * V_36 ;
struct V_35 * V_32 = V_3 -> V_32 ;
F_12 ( & V_32 -> V_37 ) ;
F_20 (cur, &fbdefio->pagelist, lru) {
F_19 ( V_36 ) ;
F_29 ( V_36 ) ;
F_30 ( V_36 ) ;
}
V_32 -> V_57 ( V_3 , & V_32 -> V_39 ) ;
F_31 (node, next, &fbdefio->pagelist) {
F_32 ( V_55 ) ;
}
F_15 ( & V_32 -> V_37 ) ;
}
void F_33 ( struct V_2 * V_3 )
{
struct V_35 * V_32 = V_3 -> V_32 ;
F_8 ( ! V_32 ) ;
F_34 ( & V_32 -> V_37 ) ;
V_3 -> V_58 -> V_59 = F_26 ;
F_35 ( & V_3 -> V_34 , F_27 ) ;
F_36 ( & V_32 -> V_39 ) ;
if ( V_32 -> V_42 == 0 )
V_32 -> V_42 = V_60 ;
}
void F_37 ( struct V_2 * V_3 ,
struct V_29 * V_29 ,
struct V_24 * V_24 )
{
V_24 -> V_21 -> V_61 = & V_62 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_35 * V_32 = V_3 -> V_32 ;
struct V_1 * V_1 ;
int V_63 ;
F_8 ( ! V_32 ) ;
F_13 ( & V_3 -> V_34 ) ;
for ( V_63 = 0 ; V_63 < V_3 -> V_7 . V_17 ; V_63 += V_64 ) {
V_1 = F_1 ( V_3 , V_63 ) ;
V_1 -> V_20 = NULL ;
}
V_3 -> V_58 -> V_59 = NULL ;
F_39 ( & V_32 -> V_37 ) ;
}
