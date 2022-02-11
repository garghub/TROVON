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
static int
F_10 ( struct V_27 * V_28 , const struct V_29 * V_30 ,
struct V_4 * V_31 , const char * V_32 )
{
struct V_33 V_34 ;
unsigned long V_35 = 0 , V_36 = 0 ;
int V_24 ;
V_34 . V_32 = V_32 ;
V_34 . V_37 = 0 ;
V_34 . V_38 = 0 ;
V_34 . V_39 = V_30 -> V_40 ;
V_31 -> V_2 . V_34 = & V_34 ;
V_31 -> V_6 = F_11 () ;
if ( V_34 . V_39 == & V_41 ) {
V_31 -> V_17 = V_31 -> V_6 -> V_42 ( V_31 -> V_8 ) ;
if ( F_12 ( V_31 -> V_17 ) )
return F_13 ( V_31 -> V_17 ) ;
} else if ( V_34 . V_39 == & V_43 ) {
if ( V_31 -> V_6 -> V_44 ( V_31 -> V_8 , & V_35 , & V_36 ) || ! V_36 )
return - V_23 ;
} else {
return - V_23 ;
}
V_24 = F_14 ( V_28 , & V_31 -> V_2 ) ;
if ( ! V_24 && V_36 )
F_15 ( & V_31 -> V_2 , V_35 , V_36 ) ;
return V_24 ;
}
static struct V_1 *
F_16 ( struct V_45 * V_46 , void * V_40 )
{
struct V_4 * V_31 ;
struct V_47 * V_48 = V_40 ;
unsigned int V_11 = V_46 -> args [ 0 ] , V_19 ;
for ( V_19 = 0 ; V_19 < V_48 -> V_49 ; V_19 ++ ) {
V_31 = V_48 -> V_5 [ V_19 ] ;
if ( V_11 == V_31 -> V_8 )
return & V_31 -> V_2 ;
}
return F_17 ( - V_23 ) ;
}
static int F_18 ( struct V_27 * V_28 , struct V_50 * V_51 ,
const struct V_29 * V_30 )
{
int V_11 , V_19 , V_52 ;
struct V_47 * V_48 ;
V_19 = F_19 ( V_51 , L_1 ) ;
if ( V_19 < 0 ) {
F_20 ( V_28 , L_2 , V_51 -> V_32 ) ;
return - V_23 ;
}
V_48 = F_21 ( V_28 , sizeof( * V_48 ) , V_53 ) ;
if ( ! V_48 )
return - V_54 ;
V_48 -> V_49 = V_19 ;
V_48 -> V_5 = F_22 ( V_28 , V_19 , sizeof( * V_48 -> V_5 ) ,
V_53 ) ;
if ( ! V_48 -> V_5 )
return - V_54 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
struct V_4 * V_31 ;
const char * V_32 ;
T_1 V_55 ;
V_31 = F_23 ( V_28 , sizeof( * V_31 ) , V_53 ) ;
if ( ! V_31 )
return - V_54 ;
if ( F_24 ( V_51 , L_1 ,
V_11 , & V_32 ) ) {
F_20 ( V_28 , L_3 , V_51 -> V_32 ) ;
return - V_23 ;
}
if ( F_25 ( V_51 , L_4 ,
V_11 , & V_55 ) ) {
F_20 ( V_28 , L_5 , V_51 -> V_32 ) ;
return - V_23 ;
}
V_31 -> V_8 = V_55 ;
V_52 = F_10 ( V_28 , V_30 , V_31 , V_32 ) ;
if ( V_52 )
F_20 ( V_28 , L_6 , V_32 ) ;
else
F_26 ( V_28 , L_7 , V_32 ) ;
V_48 -> V_5 [ V_11 ] = V_31 ;
}
return F_27 ( V_51 , F_16 , V_48 ) ;
}
static int F_28 ( struct V_56 * V_57 )
{
struct V_27 * V_28 = & V_57 -> V_28 ;
struct V_50 * V_58 , * V_51 = V_28 -> V_59 ;
if ( V_60 ) {
F_29 ( V_60 ) ;
V_60 = NULL ;
}
F_30 (np, child)
F_31 ( V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_56 * V_57 )
{
int V_24 ;
struct V_27 * V_28 = & V_57 -> V_28 ;
struct V_50 * V_58 , * V_51 = V_28 -> V_59 ;
const struct V_29 * V_30 ;
if ( ! F_11 () )
return - V_61 ;
F_30 (np, child) {
V_30 = F_33 ( V_62 , V_58 ) ;
if ( ! V_30 )
continue;
V_24 = F_18 ( V_28 , V_58 , V_30 ) ;
if ( V_24 ) {
F_28 ( V_57 ) ;
F_34 ( V_58 ) ;
return V_24 ;
}
if ( V_30 -> V_40 != & V_41 )
continue;
V_60 = F_35 ( L_8 ,
- 1 , NULL , 0 ) ;
if ( F_12 ( V_60 ) )
F_36 ( L_9 ) ;
}
return 0 ;
}
