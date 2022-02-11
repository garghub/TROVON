static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_7 ( V_5 -> V_8 ) ;
}
static long F_3 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_10 ( V_5 -> V_8 , V_9 ) ;
}
static int F_5 ( struct V_4 * V_5 , unsigned long V_9 )
{
int V_11 ;
T_1 V_12 = 0 , V_13 = ~ 0 , V_14 ;
const struct V_15 * V_16 = V_5 -> V_17 -> V_18 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_17 -> V_19 ; V_11 ++ , V_16 ++ ) {
V_14 = V_16 -> V_20 ;
if ( V_14 >= ( T_1 ) V_9 ) {
if ( V_14 <= V_13 )
V_13 = V_14 ;
break;
} else if ( V_14 >= V_12 ) {
V_12 = V_14 ;
}
}
return V_13 != ~ 0 ? V_13 : V_12 ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_11 = V_5 -> V_6 -> V_21 ( V_5 -> V_8 ) ;
const struct V_15 * V_16 ;
if ( V_11 < 0 )
return 0 ;
V_16 = V_5 -> V_17 -> V_18 + V_11 ;
return V_16 -> V_20 ;
}
static long F_7 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_5 ( V_5 , V_9 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned long V_9 )
{
int V_11 , V_22 = V_5 -> V_17 -> V_19 ;
const struct V_15 * V_16 = V_5 -> V_17 -> V_18 ;
for ( V_11 = 0 ; V_11 < V_22 ; V_11 ++ , V_16 ++ )
if ( V_16 -> V_20 == V_9 )
return V_11 ;
return - V_23 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_24 = F_8 ( V_5 , V_9 ) ;
if ( V_24 < 0 )
return V_24 ;
return V_5 -> V_6 -> V_25 ( V_5 -> V_8 , ( V_26 ) V_24 ) ;
}
static struct V_5 *
F_10 ( struct V_27 * V_28 , const struct V_29 * V_30 ,
struct V_4 * V_31 , const char * V_32 )
{
struct V_33 V_34 ;
struct V_5 * V_5 ;
unsigned long V_35 = 0 , V_36 = 0 ;
V_34 . V_32 = V_32 ;
V_34 . V_37 = V_38 ;
V_34 . V_39 = 0 ;
V_34 . V_40 = V_30 -> V_41 ;
V_31 -> V_2 . V_34 = & V_34 ;
V_31 -> V_6 = F_11 () ;
if ( V_34 . V_40 == & V_42 ) {
V_31 -> V_17 = V_31 -> V_6 -> V_43 ( V_31 -> V_8 ) ;
if ( F_12 ( V_31 -> V_17 ) )
return NULL ;
} else if ( V_34 . V_40 == & V_44 ) {
if ( V_31 -> V_6 -> V_45 ( V_31 -> V_8 , & V_35 , & V_36 ) || ! V_36 )
return NULL ;
} else {
return NULL ;
}
V_5 = F_13 ( V_28 , & V_31 -> V_2 ) ;
if ( ! F_12 ( V_5 ) && V_36 )
F_14 ( & V_31 -> V_2 , V_35 , V_36 ) ;
return V_5 ;
}
static struct V_5 *
F_15 ( struct V_46 * V_47 , void * V_41 )
{
struct V_4 * V_31 ;
struct V_48 * V_49 = V_41 ;
unsigned int V_11 = V_47 -> args [ 0 ] , V_19 ;
for ( V_19 = 0 ; V_19 < V_49 -> V_50 ; V_19 ++ ) {
V_31 = V_49 -> V_5 [ V_19 ] ;
if ( V_11 == V_31 -> V_8 )
return V_31 -> V_2 . V_5 ;
}
return F_16 ( - V_23 ) ;
}
static int F_17 ( struct V_27 * V_28 , struct V_51 * V_52 ,
const struct V_29 * V_30 )
{
struct V_5 * * V_53 ;
int V_11 , V_19 ;
struct V_48 * V_49 ;
V_19 = F_18 ( V_52 , L_1 ) ;
if ( V_19 < 0 ) {
F_19 ( V_28 , L_2 , V_52 -> V_32 ) ;
return - V_23 ;
}
V_49 = F_20 ( V_28 , sizeof( * V_49 ) , V_54 ) ;
if ( ! V_49 )
return - V_55 ;
V_49 -> V_50 = V_19 ;
V_49 -> V_5 = F_21 ( V_28 , V_19 , sizeof( * V_49 -> V_5 ) ,
V_54 ) ;
if ( ! V_49 -> V_5 )
return - V_55 ;
V_53 = F_21 ( V_28 , V_19 , sizeof( * V_53 ) , V_54 ) ;
if ( ! V_53 )
return - V_55 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
struct V_4 * V_31 ;
const char * V_32 ;
T_1 V_56 ;
V_31 = F_22 ( V_28 , sizeof( * V_31 ) , V_54 ) ;
if ( ! V_31 )
return - V_55 ;
if ( F_23 ( V_52 , L_1 ,
V_11 , & V_32 ) ) {
F_19 ( V_28 , L_3 , V_52 -> V_32 ) ;
return - V_23 ;
}
if ( F_24 ( V_52 , L_4 ,
V_11 , & V_56 ) ) {
F_19 ( V_28 , L_5 , V_52 -> V_32 ) ;
return - V_23 ;
}
V_31 -> V_8 = V_56 ;
V_53 [ V_11 ] = F_10 ( V_28 , V_30 , V_31 , V_32 ) ;
if ( F_25 ( V_53 [ V_11 ] ) )
F_19 ( V_28 , L_6 , V_32 ) ;
else
F_26 ( V_28 , L_7 , V_32 ) ;
V_49 -> V_5 [ V_11 ] = V_31 ;
}
return F_27 ( V_52 , F_15 , V_49 ) ;
}
static int F_28 ( struct V_57 * V_58 )
{
struct V_27 * V_28 = & V_58 -> V_28 ;
struct V_51 * V_59 , * V_52 = V_28 -> V_60 ;
if ( V_61 ) {
F_29 ( V_61 ) ;
V_61 = NULL ;
}
F_30 (np, child)
F_31 ( V_52 ) ;
return 0 ;
}
static int F_32 ( struct V_57 * V_58 )
{
int V_24 ;
struct V_27 * V_28 = & V_58 -> V_28 ;
struct V_51 * V_59 , * V_52 = V_28 -> V_60 ;
const struct V_29 * V_30 ;
if ( ! F_11 () )
return - V_62 ;
F_30 (np, child) {
V_30 = F_33 ( V_63 , V_59 ) ;
if ( ! V_30 )
continue;
V_24 = F_17 ( V_28 , V_59 , V_30 ) ;
if ( V_24 ) {
F_28 ( V_58 ) ;
F_34 ( V_59 ) ;
return V_24 ;
}
}
V_61 = F_35 ( L_8 ,
- 1 , NULL , 0 ) ;
if ( F_12 ( V_61 ) )
F_36 ( L_9 ) ;
return 0 ;
}
