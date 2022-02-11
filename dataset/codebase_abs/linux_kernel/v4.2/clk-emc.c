static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 , div ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 = F_3 ( F_4 ( V_2 -> V_7 ) ) ;
V_6 = F_5 ( V_5 -> V_8 + V_9 ) ;
div = V_6 & V_10 ;
return V_3 / ( div + 2 ) * 2 ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_12 ,
unsigned long V_13 ,
unsigned long * V_14 ,
struct V_1 * * V_15 )
{
struct V_4 * V_5 ;
T_2 V_16 = F_7 () ;
struct V_17 * V_18 = NULL ;
int V_19 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_19 = 0 ; V_19 < V_5 -> V_20 ; V_19 ++ ) {
if ( V_5 -> V_21 [ V_19 ] . V_16 != V_16 )
continue;
V_18 = V_5 -> V_21 + V_19 ;
if ( V_18 -> V_11 > V_13 ) {
V_19 = F_8 ( V_19 , 1 ) ;
return V_5 -> V_21 [ V_19 - 1 ] . V_11 ;
}
if ( V_18 -> V_11 < V_12 )
continue;
if ( V_18 -> V_11 >= V_11 )
return V_18 -> V_11 ;
}
if ( V_18 )
return V_18 -> V_11 ;
return F_3 ( V_2 -> V_7 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_6 = F_5 ( V_5 -> V_8 + V_9 ) ;
return ( V_6 >> V_22 )
& V_23 ;
}
static struct V_24 * F_10 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
if ( V_5 -> V_27 )
return V_5 -> V_27 ;
if ( ! V_5 -> V_28 )
return NULL ;
V_26 = F_11 ( V_5 -> V_28 ) ;
if ( ! V_26 ) {
F_12 ( L_1 ,
V_29 ) ;
return NULL ;
}
F_13 ( V_5 -> V_28 ) ;
V_5 -> V_28 = NULL ;
V_5 -> V_27 = F_14 ( V_26 ) ;
if ( ! V_5 -> V_27 ) {
F_12 ( L_2 , V_29 ) ;
return NULL ;
}
return V_5 -> V_27 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_17 * V_18 )
{
int V_30 ;
T_2 div ;
T_1 V_31 ;
unsigned long V_32 = 0 ;
struct V_24 * V_27 = F_10 ( V_5 ) ;
if ( ! V_27 )
return - V_33 ;
F_16 ( L_3 , V_18 -> V_11 ,
V_18 -> V_3 , F_17 ( V_18 -> V_34 ) ) ;
if ( F_9 ( & V_5 -> V_2 ) == V_18 -> V_35 &&
F_18 ( V_18 -> V_34 ) != V_18 -> V_3 ) {
F_19 () ;
return - V_36 ;
}
V_5 -> V_37 = true ;
V_30 = F_20 ( V_18 -> V_34 , V_18 -> V_3 ) ;
if ( V_30 ) {
F_12 ( L_4 ,
F_17 ( V_18 -> V_34 ) , V_18 -> V_3 ,
V_30 ) ;
return V_30 ;
}
V_30 = F_21 ( V_18 -> V_34 ) ;
if ( V_30 ) {
F_12 ( L_5 , V_30 ) ;
return V_30 ;
}
div = V_18 -> V_3 / ( V_18 -> V_11 / 2 ) - 2 ;
V_30 = F_22 ( V_27 , V_18 -> V_11 ) ;
if ( V_30 )
return V_30 ;
F_23 ( V_5 -> V_38 , V_32 ) ;
V_31 = F_5 ( V_5 -> V_8 + V_9 ) ;
V_31 &= ~ F_24 ( ~ 0 ) ;
V_31 |= F_24 ( V_18 -> V_35 ) ;
V_31 &= ~ F_25 ( ~ 0 ) ;
V_31 |= F_25 ( div ) ;
F_26 ( V_31 , V_5 -> V_8 + V_9 ) ;
F_27 ( V_5 -> V_38 , V_32 ) ;
F_28 ( V_27 , V_18 -> V_11 ) ;
F_29 ( & V_5 -> V_2 , F_30 ( V_18 -> V_34 ) ) ;
F_31 ( V_5 -> V_39 ) ;
V_5 -> V_39 = V_18 -> V_34 ;
V_5 -> V_37 = false ;
return 0 ;
}
static struct V_17 * F_32 ( struct V_4 * V_5 ,
int V_40 )
{
int V_19 ;
T_1 V_16 = F_7 () ;
struct V_17 * V_18 ;
for ( V_19 = V_40 + 1 ; V_19 < V_5 -> V_20 ; V_19 ++ ) {
V_18 = V_5 -> V_21 + V_19 ;
if ( V_18 -> V_16 != V_16 )
continue;
if ( V_41 [ V_18 -> V_35 ] !=
V_41 [
V_5 -> V_21 [ V_40 ] . V_35 ] )
return V_18 ;
}
for ( V_19 = V_40 - 1 ; V_19 >= 0 ; -- V_19 ) {
V_18 = V_5 -> V_21 + V_19 ;
if ( V_18 -> V_16 != V_16 )
continue;
if ( V_41 [ V_18 -> V_35 ] !=
V_41 [
V_5 -> V_21 [ V_40 ] . V_35 ] )
return V_18 ;
}
return NULL ;
}
static int F_33 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_17 * V_18 = NULL ;
int V_19 , V_30 ;
T_1 V_16 = F_7 () ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( F_3 ( V_2 -> V_7 ) == V_11 )
return 0 ;
if ( V_5 -> V_37 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_20 ; V_19 ++ ) {
if ( V_5 -> V_21 [ V_19 ] . V_11 == V_11 &&
V_5 -> V_21 [ V_19 ] . V_16 == V_16 ) {
V_18 = V_5 -> V_21 + V_19 ;
break;
}
}
if ( ! V_18 ) {
F_12 ( L_6 , V_11 ) ;
return - V_36 ;
}
if ( V_41 [ F_9 ( V_2 ) ] ==
V_41 [ V_18 -> V_35 ] &&
F_18 ( V_18 -> V_34 ) != V_18 -> V_3 ) {
struct V_17 * V_42 ;
V_42 = F_32 ( V_5 , V_19 ) ;
if ( ! V_42 ) {
F_12 ( L_7 ) ;
return - V_36 ;
}
F_16 ( L_8 ,
V_42 -> V_11 , V_11 ) ;
V_30 = F_15 ( V_5 , V_42 ) ;
if ( V_30 ) {
F_12 ( L_9 , V_30 ) ;
return V_30 ;
}
}
return F_15 ( V_5 , V_18 ) ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
struct V_43 * V_44 )
{
int V_30 , V_19 ;
T_1 V_45 ;
V_30 = F_35 ( V_44 , L_10 , & V_45 ) ;
if ( V_30 ) {
F_12 ( L_11 , V_44 -> V_46 ) ;
return V_30 ;
}
V_18 -> V_11 = V_45 ;
V_30 = F_35 ( V_44 , L_12 , & V_45 ) ;
if ( V_30 ) {
F_12 ( L_13 ,
V_44 -> V_46 ) ;
return V_30 ;
}
V_18 -> V_3 = V_45 ;
V_18 -> V_34 = F_36 ( V_44 , L_14 ) ;
if ( F_37 ( V_18 -> V_34 ) ) {
F_12 ( L_15 ,
V_44 -> V_46 ) ;
return F_38 ( V_18 -> V_34 ) ;
}
V_18 -> V_35 = 0xff ;
for ( V_19 = 0 ; V_19 < F_39 ( V_47 ) ; V_19 ++ ) {
if ( ! strcmp ( V_47 [ V_19 ] ,
F_17 ( V_18 -> V_34 ) ) ) {
V_18 -> V_35 = V_19 ;
break;
}
}
if ( V_18 -> V_35 == 0xff ) {
F_12 ( L_16 ,
V_44 -> V_46 , F_17 ( V_18 -> V_34 ) ) ;
F_40 ( V_18 -> V_34 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_41 ( const void * V_48 , const void * V_49 )
{
const struct V_17 * V_50 = V_48 ;
const struct V_17 * V_51 = V_49 ;
if ( V_50 -> V_11 < V_51 -> V_11 )
return - 1 ;
else if ( V_50 -> V_11 == V_51 -> V_11 )
return 0 ;
else
return 1 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_43 * V_44 ,
T_1 V_16 )
{
struct V_43 * V_52 ;
int V_53 = F_43 ( V_44 ) ;
int V_19 = 0 , V_30 ;
V_5 -> V_21 = F_44 ( V_53 , sizeof( struct V_17 ) ,
V_54 ) ;
if ( ! V_5 -> V_21 )
return - V_55 ;
V_5 -> V_20 = V_53 ;
F_45 (node, child) {
struct V_17 * V_18 = V_5 -> V_21 + ( V_19 ++ ) ;
V_30 = F_34 ( V_5 , V_18 , V_52 ) ;
if ( V_30 )
return V_30 ;
V_18 -> V_16 = V_16 ;
}
F_46 ( V_5 -> V_21 , V_5 -> V_20 , sizeof( struct V_17 ) ,
F_41 , NULL ) ;
return 0 ;
}
struct V_7 * F_47 ( void T_3 * V_56 , struct V_43 * V_57 ,
T_4 * V_38 )
{
struct V_4 * V_5 ;
struct V_58 V_59 ;
struct V_43 * V_44 ;
T_1 V_60 ;
struct V_7 * V_7 ;
int V_30 ;
V_5 = F_44 ( 1 , sizeof( * V_5 ) , V_54 ) ;
if ( ! V_5 )
return F_48 ( - V_55 ) ;
V_5 -> V_8 = V_56 ;
V_5 -> V_38 = V_38 ;
V_5 -> V_20 = 0 ;
F_45 (np, node) {
V_30 = F_35 ( V_44 , L_17 ,
& V_60 ) ;
if ( V_30 ) {
F_13 ( V_44 ) ;
continue;
}
V_30 = F_42 ( V_5 , V_44 , V_60 ) ;
if ( V_30 )
return F_48 ( V_30 ) ;
F_13 ( V_44 ) ;
break;
}
if ( V_5 -> V_20 == 0 )
F_49 ( L_18 , V_29 ) ;
V_5 -> V_28 = F_50 ( V_57 ,
L_19 , 0 ) ;
if ( ! V_5 -> V_28 )
F_49 ( L_20 , V_29 ) ;
V_59 . V_61 = L_21 ;
V_59 . V_62 = & V_63 ;
V_59 . V_32 = 0 ;
V_59 . V_64 = V_47 ;
V_59 . V_65 = F_39 ( V_47 ) ;
V_5 -> V_2 . V_59 = & V_59 ;
V_7 = F_51 ( NULL , & V_5 -> V_2 ) ;
if ( F_37 ( V_7 ) )
return V_7 ;
V_5 -> V_39 = F_52 (
V_5 -> V_2 . V_7 , F_9 ( & V_5 -> V_2 ) ) ;
V_5 -> V_37 = false ;
F_53 ( V_7 , L_21 , L_22 ) ;
F_21 ( V_7 ) ;
return V_7 ;
}
