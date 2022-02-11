struct V_1 * F_1 ( struct V_2 * V_3 , unsigned long V_4 )
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
int F_9 ( struct V_24 * V_24 , int V_25 )
{
struct V_2 * V_3 = V_24 -> V_26 ;
if ( ! V_3 -> V_27 )
return 0 ;
F_10 ( & V_3 -> V_28 ) ;
return F_11 ( & V_3 -> V_28 , 0 ) ;
}
static int F_12 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = V_13 -> V_1 ;
struct V_2 * V_3 = V_11 -> V_15 ;
struct V_29 * V_27 = V_3 -> V_27 ;
struct V_1 * V_30 ;
F_13 ( & V_27 -> V_31 ) ;
F_14 ( V_1 ) ;
F_15 (cur, &fbdefio->pagelist, lru) {
if ( F_16 ( V_30 == V_1 ) )
goto V_32;
else if ( V_30 -> V_23 > V_1 -> V_23 )
break;
}
F_17 ( & V_1 -> V_33 , & V_30 -> V_33 ) ;
V_32:
F_18 ( & V_27 -> V_31 ) ;
F_11 ( & V_3 -> V_28 , V_27 -> V_34 ) ;
return V_35 ;
}
static int F_19 ( struct V_1 * V_1 )
{
if ( ! F_20 ( V_1 ) )
F_21 ( V_1 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
V_11 -> V_36 = & V_37 ;
V_11 -> V_38 |= ( V_39 | V_40 ) ;
if ( ! ( V_3 -> V_41 & V_42 ) )
V_11 -> V_38 |= V_43 ;
V_11 -> V_15 = V_3 ;
return 0 ;
}
static void F_23 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_24 ( V_45 , struct V_2 ,
V_28 . V_45 ) ;
struct V_46 * V_47 , * V_48 ;
struct V_1 * V_30 ;
struct V_29 * V_27 = V_3 -> V_27 ;
F_13 ( & V_27 -> V_31 ) ;
F_15 (cur, &fbdefio->pagelist, lru) {
F_14 ( V_30 ) ;
F_25 ( V_30 ) ;
F_26 ( V_30 ) ;
}
V_27 -> V_49 ( V_3 , & V_27 -> V_50 ) ;
F_27 (node, next, &fbdefio->pagelist) {
F_28 ( V_47 ) ;
}
F_18 ( & V_27 -> V_31 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_29 * V_27 = V_3 -> V_27 ;
F_8 ( ! V_27 ) ;
F_30 ( & V_27 -> V_31 ) ;
V_3 -> V_51 -> V_52 = F_22 ;
F_31 ( & V_3 -> V_28 , F_23 ) ;
F_32 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_34 == 0 )
V_27 -> V_34 = V_53 ;
}
void F_33 ( struct V_2 * V_3 ,
struct V_54 * V_54 ,
struct V_24 * V_24 )
{
V_24 -> V_21 -> V_55 = & V_56 ;
}
void F_34 ( struct V_2 * V_3 )
{
struct V_29 * V_27 = V_3 -> V_27 ;
struct V_1 * V_1 ;
int V_57 ;
F_8 ( ! V_27 ) ;
F_35 ( & V_3 -> V_28 ) ;
F_36 () ;
for ( V_57 = 0 ; V_57 < V_3 -> V_7 . V_17 ; V_57 += V_58 ) {
V_1 = F_1 ( V_3 , V_57 ) ;
V_1 -> V_20 = NULL ;
}
V_3 -> V_51 -> V_52 = NULL ;
F_37 ( & V_27 -> V_31 ) ;
}
