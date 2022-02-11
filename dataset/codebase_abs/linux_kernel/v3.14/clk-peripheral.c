static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_8 ;
T_1 V_9 = V_4 -> V_9 ;
if ( V_9 < V_10 )
return 0 ;
if ( V_9 > V_11 )
V_7 = V_12 ;
F_3 ( V_6 , V_7 , F_4 ( V_9 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_13 ;
T_1 V_9 = V_4 -> V_9 ;
if ( V_9 < V_10 )
return;
if ( V_9 > V_11 )
V_7 = V_14 ;
F_3 ( V_6 , V_7 , F_4 ( V_9 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = V_15 ;
T_1 V_9 = V_4 -> V_9 ;
if ( V_9 < V_10 )
return 1 ;
if ( V_9 > V_11 )
V_7 = V_16 ;
return ! ! ( F_7 ( V_6 , V_7 ) & F_4 ( V_9 ) ) ;
}
static struct V_17 * T_2
F_8 ( struct V_5 * V_6 , const char * V_18 ,
const char * V_19 , T_1 V_9 )
{
struct V_3 * V_4 ;
struct V_17 * V_17 = NULL ;
struct V_20 V_21 ;
if ( ! V_6 || ! V_18 || ! V_19 || V_9 > V_11 )
return F_9 ( - V_22 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return F_9 ( - V_24 ) ;
V_21 . V_18 = V_18 ;
V_21 . V_25 = & V_26 ;
V_21 . V_27 = ( V_19 ? & V_19 : NULL ) ;
V_21 . V_28 = ( V_19 ? 1 : 0 ) ;
V_21 . V_29 = 0 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 . V_21 = & V_21 ;
V_4 -> V_6 = V_6 ;
V_17 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_17 ) )
F_13 ( V_4 ) ;
return V_17 ;
}
static void F_14 ( struct V_30 * V_4 )
{
struct V_17 * V_31 ;
unsigned long V_32 ;
int V_33 = 0 ;
if ( ! V_4 -> V_34 )
return;
if ( V_4 -> V_35 . V_36 ) {
V_31 = F_15 ( V_4 -> V_2 . V_17 , 0 ) ;
V_32 = F_16 ( V_31 ) ;
if ( ! V_32 )
return;
for (; V_33 < V_37 ; V_33 ++ ) {
if ( V_32 >> V_33 <= V_4 -> V_35 . V_36 )
break;
}
}
V_4 -> V_34 = false ;
V_4 -> div = V_33 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_18 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_9 < V_10 )
return 0 ;
F_3 ( V_6 , V_38 , ( V_4 -> V_9 & V_39 ) |
V_40 |
F_19 ( V_4 -> div ) |
V_41 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_18 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_9 < V_10 )
return;
F_3 ( V_6 , V_38 , ( V_4 -> V_9 & V_39 ) |
V_40 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_18 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_42 ;
if ( V_4 -> V_9 < V_10 )
return 1 ;
F_22 ( V_6 ) ;
F_3 ( V_6 , V_38 , ( V_4 -> V_9 & V_39 ) ) ;
V_42 = ! ! ( F_7 ( V_6 , V_38 ) & V_41 ) ;
F_23 ( V_6 ) ;
return V_42 ;
}
static unsigned long
F_24 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
struct V_30 * V_4 = F_18 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_43 ;
if ( V_4 -> V_9 < V_10 )
return V_32 ;
F_22 ( V_6 ) ;
F_3 ( V_6 , V_38 , ( V_4 -> V_9 & V_39 ) ) ;
V_43 = F_7 ( V_6 , V_38 ) ;
F_23 ( V_6 ) ;
if ( V_43 & V_41 ) {
V_4 -> div = F_25 ( V_43 ) ;
V_4 -> V_34 = false ;
} else {
F_14 ( V_4 ) ;
}
return V_32 >> V_4 -> div ;
}
static long F_26 ( struct V_1 * V_2 ,
unsigned long V_44 ,
unsigned long * V_32 )
{
int V_33 = 0 ;
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 = * V_32 ;
unsigned long V_48 ;
struct V_30 * V_4 = F_18 ( V_2 ) ;
if ( V_4 -> V_9 < V_10 || ! V_4 -> V_35 . V_36 )
return * V_32 ;
if ( V_4 -> V_35 . V_36 ) {
for (; V_33 < V_37 ; V_33 ++ ) {
V_47 = * V_32 >> V_33 ;
if ( V_47 <= V_4 -> V_35 . V_36 )
break;
}
}
if ( V_44 >= V_47 )
return V_47 ;
V_46 = V_47 - V_44 ;
V_45 = V_47 ;
for (; V_33 < V_37 ; V_33 ++ ) {
V_47 = * V_32 >> V_33 ;
if ( V_47 < V_44 )
V_48 = V_44 - V_47 ;
else
V_48 = V_47 - V_44 ;
if ( V_48 < V_46 ) {
V_46 = V_48 ;
V_45 = V_47 ;
}
if ( ! V_46 || V_47 < V_44 )
break;
}
return V_45 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned long V_44 ,
unsigned long V_32 )
{
int V_33 ;
struct V_30 * V_4 = F_18 ( V_2 ) ;
if ( V_4 -> V_9 < V_10 || ! V_4 -> V_35 . V_36 ) {
if ( V_32 == V_44 )
return 0 ;
else
return - V_22 ;
}
if ( V_4 -> V_35 . V_36 && V_44 > V_4 -> V_35 . V_36 )
return - V_22 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( V_32 >> V_33 == V_44 ) {
V_4 -> V_34 = false ;
V_4 -> div = V_33 ;
return 0 ;
}
}
return - V_22 ;
}
static struct V_17 * T_2
F_28 ( struct V_5 * V_6 , const char * V_18 ,
const char * V_19 , T_1 V_9 ,
const struct V_49 * V_35 )
{
struct V_30 * V_4 ;
struct V_17 * V_17 = NULL ;
struct V_20 V_21 ;
if ( ! V_6 || ! V_18 || ! V_19 )
return F_9 ( - V_22 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return F_9 ( - V_24 ) ;
V_21 . V_18 = V_18 ;
V_21 . V_25 = & V_50 ;
V_21 . V_27 = ( V_19 ? & V_19 : NULL ) ;
V_21 . V_28 = ( V_19 ? 1 : 0 ) ;
V_21 . V_29 = 0 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 . V_21 = & V_21 ;
V_4 -> div = 0 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = true ;
V_4 -> V_35 = * V_35 ;
V_17 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_17 ) )
F_13 ( V_4 ) ;
else
F_14 ( V_4 ) ;
return V_17 ;
}
static void T_2
F_29 ( struct V_51 * V_52 , struct V_5 * V_6 , T_3 type )
{
int V_53 ;
T_1 V_9 ;
struct V_17 * V_17 ;
const char * V_19 ;
const char * V_18 ;
struct V_51 * V_54 ;
V_19 = F_30 ( V_52 , 0 ) ;
if ( ! V_19 )
return;
V_53 = F_31 ( V_52 ) ;
if ( ! V_53 || V_53 > V_55 )
return;
F_32 (np, periphclknp) {
if ( F_33 ( V_54 , L_1 , & V_9 ) )
continue;
if ( V_9 >= V_55 )
continue;
if ( F_34 ( V_52 , L_2 , & V_18 ) )
V_18 = V_54 -> V_18 ;
if ( type == V_56 ) {
V_17 = F_8 ( V_6 , V_18 ,
V_19 , V_9 ) ;
} else {
struct V_49 V_35 = F_35 ( 0 , 0 ) ;
F_36 ( V_54 ,
L_3 ,
& V_35 ) ;
V_17 = F_28 ( V_6 , V_18 ,
V_19 ,
V_9 , & V_35 ) ;
}
if ( F_12 ( V_17 ) )
continue;
F_37 ( V_54 , V_57 , V_17 ) ;
}
}
void T_2 F_38 ( struct V_51 * V_52 ,
struct V_5 * V_6 )
{
F_29 ( V_52 , V_6 , V_56 ) ;
}
void T_2 F_39 ( struct V_51 * V_52 ,
struct V_5 * V_6 )
{
F_29 ( V_52 , V_6 , V_58 ) ;
}
