static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_6 ;
T_1 V_7 = V_4 -> V_7 ;
if ( V_7 < V_8 )
return 0 ;
if ( V_7 > V_9 )
V_5 = V_10 ;
F_3 ( V_4 -> V_11 , V_5 , F_4 ( V_7 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_12 ;
T_1 V_7 = V_4 -> V_7 ;
if ( V_7 < V_8 )
return;
if ( V_7 > V_9 )
V_5 = V_13 ;
F_3 ( V_4 -> V_11 , V_5 , F_4 ( V_7 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_14 ;
unsigned int V_15 ;
T_1 V_7 = V_4 -> V_7 ;
if ( V_7 < V_8 )
return 1 ;
if ( V_7 > V_9 )
V_5 = V_16 ;
F_7 ( V_4 -> V_11 , V_5 , & V_15 ) ;
return V_15 & F_4 ( V_7 ) ? 1 : 0 ;
}
static struct V_1 * T_2
F_8 ( struct V_11 * V_11 , const char * V_17 ,
const char * V_18 , T_1 V_7 )
{
struct V_3 * V_4 ;
struct V_19 V_20 ;
struct V_1 * V_2 ;
int V_21 ;
if ( ! V_17 || ! V_18 || V_7 > V_9 )
return F_9 ( - V_22 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return F_9 ( - V_24 ) ;
V_20 . V_17 = V_17 ;
V_20 . V_25 = & V_26 ;
V_20 . V_27 = ( V_18 ? & V_18 : NULL ) ;
V_20 . V_28 = ( V_18 ? 1 : 0 ) ;
V_20 . V_29 = 0 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_4 -> V_11 = V_11 ;
V_2 = & V_4 -> V_2 ;
V_21 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( V_21 ) {
F_12 ( V_4 ) ;
V_2 = F_9 ( V_21 ) ;
}
return V_2 ;
}
static void F_13 ( struct V_30 * V_4 )
{
struct V_1 * V_31 ;
unsigned long V_32 ;
int V_33 = 0 ;
if ( ! V_4 -> V_34 )
return;
if ( V_4 -> V_35 . V_36 ) {
V_31 = F_14 ( & V_4 -> V_2 , 0 ) ;
V_32 = F_15 ( V_31 ) ;
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
static int F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_17 ( V_2 ) ;
unsigned long V_29 ;
if ( V_4 -> V_7 < V_8 )
return 0 ;
F_18 ( V_4 -> V_38 , V_29 ) ;
F_3 ( V_4 -> V_11 , V_39 ,
( V_4 -> V_7 & V_40 ) ) ;
F_19 ( V_4 -> V_11 , V_39 ,
V_41 | V_42 |
V_43 ,
F_20 ( V_4 -> div ) |
V_42 |
V_43 ) ;
F_21 ( V_4 -> V_38 , V_29 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_17 ( V_2 ) ;
unsigned long V_29 ;
if ( V_4 -> V_7 < V_8 )
return;
F_18 ( V_4 -> V_38 , V_29 ) ;
F_3 ( V_4 -> V_11 , V_39 ,
( V_4 -> V_7 & V_40 ) ) ;
F_19 ( V_4 -> V_11 , V_39 ,
V_43 | V_42 ,
V_42 ) ;
F_21 ( V_4 -> V_38 , V_29 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_17 ( V_2 ) ;
unsigned long V_29 ;
unsigned int V_15 ;
if ( V_4 -> V_7 < V_8 )
return 1 ;
F_18 ( V_4 -> V_38 , V_29 ) ;
F_3 ( V_4 -> V_11 , V_39 ,
( V_4 -> V_7 & V_40 ) ) ;
F_7 ( V_4 -> V_11 , V_39 , & V_15 ) ;
F_21 ( V_4 -> V_38 , V_29 ) ;
return V_15 & V_43 ? 1 : 0 ;
}
static unsigned long
F_24 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
struct V_30 * V_4 = F_17 ( V_2 ) ;
unsigned long V_29 ;
unsigned int V_15 ;
if ( V_4 -> V_7 < V_8 )
return V_32 ;
F_18 ( V_4 -> V_38 , V_29 ) ;
F_3 ( V_4 -> V_11 , V_39 ,
( V_4 -> V_7 & V_40 ) ) ;
F_7 ( V_4 -> V_11 , V_39 , & V_15 ) ;
F_21 ( V_4 -> V_38 , V_29 ) ;
if ( V_15 & V_43 ) {
V_4 -> div = F_25 ( V_15 ) ;
V_4 -> V_34 = false ;
} else {
F_13 ( V_4 ) ;
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
struct V_30 * V_4 = F_17 ( V_2 ) ;
if ( V_4 -> V_7 < V_8 || ! V_4 -> V_35 . V_36 )
return * V_32 ;
if ( V_4 -> V_35 . V_36 ) {
for (; V_33 <= V_37 ; V_33 ++ ) {
V_47 = * V_32 >> V_33 ;
if ( V_47 <= V_4 -> V_35 . V_36 )
break;
}
}
if ( V_44 >= V_47 )
return V_47 ;
V_46 = V_47 - V_44 ;
V_45 = V_47 ;
for (; V_33 <= V_37 ; V_33 ++ ) {
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
struct V_30 * V_4 = F_17 ( V_2 ) ;
if ( V_4 -> V_7 < V_8 || ! V_4 -> V_35 . V_36 ) {
if ( V_32 == V_44 )
return 0 ;
else
return - V_22 ;
}
if ( V_4 -> V_35 . V_36 && V_44 > V_4 -> V_35 . V_36 )
return - V_22 ;
for ( V_33 = 0 ; V_33 <= V_37 ; V_33 ++ ) {
if ( V_32 >> V_33 == V_44 ) {
V_4 -> V_34 = false ;
V_4 -> div = V_33 ;
return 0 ;
}
}
return - V_22 ;
}
static struct V_1 * T_2
F_28 ( struct V_11 * V_11 , T_3 * V_38 ,
const char * V_17 , const char * V_18 ,
T_1 V_7 , const struct V_49 * V_35 )
{
struct V_30 * V_4 ;
struct V_19 V_20 ;
struct V_1 * V_2 ;
int V_21 ;
if ( ! V_17 || ! V_18 )
return F_9 ( - V_22 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return F_9 ( - V_24 ) ;
V_20 . V_17 = V_17 ;
V_20 . V_25 = & V_50 ;
V_20 . V_27 = ( V_18 ? & V_18 : NULL ) ;
V_20 . V_28 = ( V_18 ? 1 : 0 ) ;
V_20 . V_29 = 0 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_4 -> div = 0 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_38 = V_38 ;
V_4 -> V_34 = true ;
V_4 -> V_35 = * V_35 ;
V_2 = & V_4 -> V_2 ;
V_21 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( V_21 ) {
F_12 ( V_4 ) ;
V_2 = F_9 ( V_21 ) ;
} else
F_13 ( V_4 ) ;
return V_2 ;
}
static void T_2
F_29 ( struct V_51 * V_52 , T_4 type )
{
int V_53 ;
T_1 V_7 ;
struct V_1 * V_2 ;
const char * V_18 ;
const char * V_17 ;
struct V_51 * V_54 ;
struct V_11 * V_11 ;
V_18 = F_30 ( V_52 , 0 ) ;
if ( ! V_18 )
return;
V_53 = F_31 ( V_52 ) ;
if ( ! V_53 || V_53 > V_55 )
return;
V_11 = F_32 ( F_33 ( V_52 ) ) ;
if ( F_34 ( V_11 ) )
return;
F_35 (np, periphclknp) {
if ( F_36 ( V_54 , L_1 , & V_7 ) )
continue;
if ( V_7 >= V_55 )
continue;
if ( F_37 ( V_52 , L_2 , & V_17 ) )
V_17 = V_54 -> V_17 ;
if ( type == V_56 ) {
V_2 = F_8 ( V_11 , V_17 ,
V_18 , V_7 ) ;
} else {
struct V_49 V_35 = F_38 ( 0 , 0 ) ;
F_39 ( V_54 ,
L_3 ,
& V_35 ) ;
V_2 = F_28 ( V_11 ,
& V_57 ,
V_17 ,
V_18 ,
V_7 , & V_35 ) ;
}
if ( F_34 ( V_2 ) )
continue;
F_40 ( V_54 , V_58 , V_2 ) ;
}
}
static void T_2 F_41 ( struct V_51 * V_52 )
{
F_29 ( V_52 , V_56 ) ;
}
static void T_2 F_42 ( struct V_51 * V_52 )
{
F_29 ( V_52 , V_59 ) ;
}
