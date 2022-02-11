static inline bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
return V_7 -> V_10 [ V_8 ] & F_2 ( V_9 ) ;
}
static inline
struct V_1 * F_3 ( struct V_11 * V_12 ,
unsigned int V_8 ,
unsigned int V_9 )
{
struct V_3 * V_4 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_14 ; V_13 ++ ) {
V_4 = V_12 -> V_15 [ V_13 ] . V_5 ;
if ( V_4 &&
V_4 -> V_8 == V_8 &&
V_4 -> V_9 == V_9 )
return & V_12 -> V_15 [ V_13 ] ;
}
F_4 ( V_12 -> V_16 ,
L_1 ,
V_8 , V_9 ) ;
return NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
unsigned long V_17 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
F_7 ( & V_7 -> V_19 , V_17 ) ;
V_7 -> V_10 [ V_8 ] |= F_2 ( V_9 ) ;
F_8 ( F_2 ( V_9 ) , V_18 + V_20 ) ;
F_9 ( & V_7 -> V_19 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
unsigned long V_17 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
F_7 ( & V_7 -> V_19 , V_17 ) ;
V_7 -> V_10 [ V_8 ] &= ~ F_2 ( V_9 ) ;
F_8 ( F_2 ( V_9 ) , V_18 + V_21 ) ;
F_9 ( & V_7 -> V_19 , V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
F_8 ( F_2 ( V_9 ) , V_18 + V_22 ) ;
}
static struct V_1 * F_12 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_1 * V_2 = NULL ;
unsigned int V_9 ;
unsigned long V_23 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
V_23 = F_13 ( V_18 + V_24 ) ;
if ( ! V_23 )
return NULL ;
for ( V_9 = 0 ; V_23 ; V_9 ++ ) {
if ( ! F_14 ( V_9 , & V_23 ) )
continue;
V_2 = F_3 ( V_12 , V_8 , V_9 ) ;
if ( V_2 ) {
F_15 ( V_12 -> V_16 ,
L_2 ,
V_8 , V_9 ) ;
break;
}
}
return V_2 ;
}
static T_2 F_16 ( int V_25 , void * V_26 )
{
struct V_6 * V_7 = V_26 ;
struct V_27 * V_28 = F_17 ( V_7 -> V_16 ) ;
struct V_1 * V_2 ;
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_28 -> V_29 ; V_8 ++ ) {
V_30:
V_2 = F_12 ( V_7 , V_8 ) ;
if ( ! V_2 )
continue;
F_18 ( V_2 , NULL ) ;
F_11 ( V_2 ) ;
F_5 ( V_2 ) ;
goto V_30;
}
return V_31 ;
}
static T_2 F_19 ( int V_25 , void * V_26 )
{
struct V_6 * V_7 = V_26 ;
struct V_27 * V_28 = F_17 ( V_7 -> V_16 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_8 ;
int V_32 = V_33 ;
for ( V_8 = 0 ; V_8 < V_28 -> V_29 ; V_8 ++ ) {
V_2 = F_12 ( V_7 , V_8 ) ;
if ( ! V_2 )
continue;
V_4 = V_2 -> V_5 ;
if ( ! F_1 ( V_2 ) ) {
F_20 ( V_7 -> V_16 ,
L_3
L_4 ,
V_7 -> V_34 , V_4 -> V_8 ,
V_4 -> V_9 , V_7 -> V_10 [ V_8 ] ) ;
if ( V_32 == V_33 )
V_32 = V_31 ;
continue;
}
F_10 ( V_2 ) ;
V_32 = V_35 ;
}
if ( V_32 == V_33 )
F_4 ( V_7 -> V_16 , L_5 ) ;
return V_32 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
if ( ! ( F_13 ( V_18 + V_36 ) & F_2 ( V_9 ) ) ) {
F_15 ( V_7 -> V_16 , L_6 ,
V_7 -> V_34 , V_8 , V_9 ) ;
return false ;
}
if ( F_13 ( V_18 + V_24 ) & F_2 ( V_9 ) ) {
F_15 ( V_7 -> V_16 , L_7 ,
V_7 -> V_34 , V_8 , V_9 ) ;
return false ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 , void * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_8 = V_4 -> V_8 ;
unsigned int V_9 = V_4 -> V_9 ;
void T_1 * V_18 = F_6 ( V_7 , V_8 ) ;
F_8 ( F_2 ( V_9 ) , V_18 + V_37 ) ;
F_15 ( V_7 -> V_16 ,
L_8 ,
V_7 -> V_34 , V_8 , V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_11 * V_12 = V_4 -> V_7 -> V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_14 ; V_13 ++ )
if ( V_2 == & V_12 -> V_15 [ V_13 ] )
break;
if ( V_12 -> V_14 == V_13 ) {
F_20 ( V_12 -> V_16 , L_9 ) ;
return;
}
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_5 = NULL ;
}
static struct V_1 * F_25 ( struct V_11 * V_12 ,
const struct V_38 * V_39 )
{
struct V_6 * V_7 = F_26 ( V_12 -> V_16 ) ;
struct V_27 * V_28 = F_17 ( V_7 -> V_16 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 = NULL ;
unsigned int V_8 = V_39 -> args [ 0 ] ;
unsigned int V_9 = V_39 -> args [ 1 ] ;
int V_13 ;
if ( V_8 >= V_28 -> V_29 || V_9 >= V_28 -> V_40 ) {
F_4 ( V_12 -> V_16 ,
L_10 ,
V_8 , V_9 ) ;
return F_27 ( - V_41 ) ;
}
for ( V_13 = 0 ; V_13 < V_12 -> V_14 ; V_13 ++ ) {
V_4 = V_12 -> V_15 [ V_13 ] . V_5 ;
if ( V_4 &&
V_12 -> V_16 == V_4 -> V_7 -> V_16 &&
V_8 == V_4 -> V_8 &&
V_9 == V_4 -> V_9 ) {
F_4 ( V_12 -> V_16 , L_11 ) ;
return F_27 ( - V_42 ) ;
}
if ( ! V_2 && ! V_4 )
V_2 = & V_12 -> V_15 [ V_13 ] ;
}
if ( ! V_2 ) {
F_4 ( V_12 -> V_16 , L_12 ) ;
return F_27 ( - V_42 ) ;
}
V_4 = F_28 ( V_12 -> V_16 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return F_27 ( - V_44 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_2 -> V_5 = V_4 ;
F_29 ( V_12 -> V_16 ,
L_13 ,
V_7 -> V_34 , V_8 , V_9 ) ;
return V_2 ;
}
static int F_30 ( struct V_45 * V_46 )
{
const struct V_47 * V_48 ;
struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_49 * V_50 = V_46 -> V_16 . V_51 ;
struct V_1 * V_15 ;
struct V_52 * V_53 ;
int V_25 ;
int V_32 ;
V_48 = F_31 ( V_54 , & V_46 -> V_16 ) ;
if ( ! V_48 ) {
F_4 ( & V_46 -> V_16 , L_14 ) ;
return - V_55 ;
}
V_46 -> V_16 . V_56 = (struct V_27 * ) V_48 -> V_26 ;
V_7 = F_28 ( & V_46 -> V_16 , sizeof( * V_7 ) , V_43 ) ;
if ( ! V_7 )
return - V_44 ;
F_32 ( V_46 , V_7 ) ;
V_53 = F_33 ( V_46 , V_57 , 0 ) ;
V_7 -> V_18 = F_34 ( & V_46 -> V_16 , V_53 ) ;
if ( F_35 ( V_7 -> V_18 ) )
return F_36 ( V_7 -> V_18 ) ;
V_32 = F_37 ( V_50 , L_15 , & V_7 -> V_34 ) ;
if ( V_32 )
V_7 -> V_34 = V_50 -> V_58 ;
V_12 = F_28 ( & V_46 -> V_16 , sizeof( * V_12 ) , V_43 ) ;
if ( ! V_12 )
return - V_44 ;
V_15 = F_28 ( & V_46 -> V_16 ,
sizeof( * V_15 ) * V_59 , V_43 ) ;
if ( ! V_15 )
return - V_44 ;
V_7 -> V_16 = & V_46 -> V_16 ;
V_7 -> V_12 = V_12 ;
F_38 ( & V_7 -> V_19 ) ;
V_12 -> V_60 = false ;
V_12 -> V_61 = true ;
V_12 -> V_62 = 100 ;
V_12 -> V_63 = & V_64 ;
V_12 -> V_16 = V_7 -> V_16 ;
V_12 -> V_65 = F_25 ;
V_12 -> V_15 = V_15 ;
V_12 -> V_14 = V_59 ;
V_32 = F_39 ( V_12 ) ;
if ( V_32 )
return V_32 ;
V_25 = F_40 ( V_46 , 0 ) ;
if ( V_25 < 0 ) {
F_29 ( & V_46 -> V_16 ,
L_16 , V_7 -> V_34 ) ;
return 0 ;
}
V_32 = F_41 ( & V_46 -> V_16 , V_25 ,
F_19 ,
F_16 ,
V_66 , V_7 -> V_34 , V_7 ) ;
if ( V_32 ) {
F_4 ( & V_46 -> V_16 , L_17 , V_25 ) ;
F_42 ( V_12 ) ;
return - V_41 ;
}
F_29 ( & V_46 -> V_16 , L_18 , V_7 -> V_34 ) ;
return 0 ;
}
static int F_43 ( struct V_45 * V_46 )
{
struct V_6 * V_7 = F_44 ( V_46 ) ;
F_42 ( V_7 -> V_12 ) ;
return 0 ;
}
