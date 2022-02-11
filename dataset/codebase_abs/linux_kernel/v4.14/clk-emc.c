static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 , div ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 = F_3 ( F_4 ( V_2 ) ) ;
V_6 = F_5 ( V_5 -> V_7 + V_8 ) ;
div = V_6 & V_9 ;
return V_3 / ( div + 2 ) * 2 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_4 * V_5 ;
T_2 V_12 = F_7 () ;
struct V_13 * V_14 = NULL ;
int V_15 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_15 = 0 ; V_15 < V_5 -> V_16 ; V_15 ++ ) {
if ( V_5 -> V_17 [ V_15 ] . V_12 != V_12 )
continue;
V_14 = V_5 -> V_17 + V_15 ;
if ( V_14 -> V_18 > V_11 -> V_19 ) {
V_15 = F_8 ( V_15 , 1 ) ;
V_11 -> V_18 = V_5 -> V_17 [ V_15 - 1 ] . V_18 ;
return 0 ;
}
if ( V_14 -> V_18 < V_11 -> V_20 )
continue;
if ( V_14 -> V_18 >= V_11 -> V_18 ) {
V_11 -> V_18 = V_14 -> V_18 ;
return 0 ;
}
}
if ( V_14 ) {
V_11 -> V_18 = V_14 -> V_18 ;
return 0 ;
}
V_11 -> V_18 = F_3 ( V_2 ) ;
return 0 ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_6 = F_5 ( V_5 -> V_7 + V_8 ) ;
return ( V_6 >> V_21 )
& V_22 ;
}
static struct V_23 * F_10 ( struct V_4 * V_5 )
{
struct V_24 * V_25 ;
if ( V_5 -> V_26 )
return V_5 -> V_26 ;
if ( ! V_5 -> V_27 )
return NULL ;
V_25 = F_11 ( V_5 -> V_27 ) ;
if ( ! V_25 ) {
F_12 ( L_1 ,
V_28 ) ;
return NULL ;
}
F_13 ( V_5 -> V_27 ) ;
V_5 -> V_27 = NULL ;
V_5 -> V_26 = F_14 ( V_25 ) ;
if ( ! V_5 -> V_26 ) {
F_12 ( L_2 , V_28 ) ;
return NULL ;
}
return V_5 -> V_26 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_13 * V_14 )
{
int V_29 ;
T_2 div ;
T_1 V_30 ;
unsigned long V_31 = 0 ;
struct V_23 * V_26 = F_10 ( V_5 ) ;
if ( ! V_26 )
return - V_32 ;
F_16 ( L_3 , V_14 -> V_18 ,
V_14 -> V_3 , F_17 ( V_14 -> V_33 ) ) ;
if ( F_9 ( & V_5 -> V_2 ) == V_14 -> V_34 &&
F_18 ( V_14 -> V_33 ) != V_14 -> V_3 ) {
F_19 () ;
return - V_35 ;
}
V_5 -> V_36 = true ;
V_29 = F_20 ( V_14 -> V_33 , V_14 -> V_3 ) ;
if ( V_29 ) {
F_12 ( L_4 ,
F_17 ( V_14 -> V_33 ) , V_14 -> V_3 ,
V_29 ) ;
return V_29 ;
}
V_29 = F_21 ( V_14 -> V_33 ) ;
if ( V_29 ) {
F_12 ( L_5 , V_29 ) ;
return V_29 ;
}
div = V_14 -> V_3 / ( V_14 -> V_18 / 2 ) - 2 ;
V_29 = F_22 ( V_26 , V_14 -> V_18 ) ;
if ( V_29 )
return V_29 ;
F_23 ( V_5 -> V_37 , V_31 ) ;
V_30 = F_5 ( V_5 -> V_7 + V_8 ) ;
V_30 &= ~ F_24 ( ~ 0 ) ;
V_30 |= F_24 ( V_14 -> V_34 ) ;
V_30 &= ~ F_25 ( ~ 0 ) ;
V_30 |= F_25 ( div ) ;
F_26 ( V_30 , V_5 -> V_7 + V_8 ) ;
F_27 ( V_5 -> V_37 , V_31 ) ;
F_28 ( V_26 , V_14 -> V_18 ) ;
F_29 ( & V_5 -> V_2 , F_30 ( V_14 -> V_33 ) ) ;
F_31 ( V_5 -> V_38 ) ;
V_5 -> V_38 = V_14 -> V_33 ;
V_5 -> V_36 = false ;
return 0 ;
}
static struct V_13 * F_32 ( struct V_4 * V_5 ,
int V_39 )
{
int V_15 ;
T_1 V_12 = F_7 () ;
struct V_13 * V_14 ;
for ( V_15 = V_39 + 1 ; V_15 < V_5 -> V_16 ; V_15 ++ ) {
V_14 = V_5 -> V_17 + V_15 ;
if ( V_14 -> V_12 != V_12 )
continue;
if ( V_40 [ V_14 -> V_34 ] !=
V_40 [
V_5 -> V_17 [ V_39 ] . V_34 ] )
return V_14 ;
}
for ( V_15 = V_39 - 1 ; V_15 >= 0 ; -- V_15 ) {
V_14 = V_5 -> V_17 + V_15 ;
if ( V_14 -> V_12 != V_12 )
continue;
if ( V_40 [ V_14 -> V_34 ] !=
V_40 [
V_5 -> V_17 [ V_39 ] . V_34 ] )
return V_14 ;
}
return NULL ;
}
static int F_33 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_13 * V_14 = NULL ;
int V_15 , V_29 ;
T_1 V_12 = F_7 () ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( F_3 ( V_2 ) == V_18 )
return 0 ;
if ( V_5 -> V_36 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_16 ; V_15 ++ ) {
if ( V_5 -> V_17 [ V_15 ] . V_18 == V_18 &&
V_5 -> V_17 [ V_15 ] . V_12 == V_12 ) {
V_14 = V_5 -> V_17 + V_15 ;
break;
}
}
if ( ! V_14 ) {
F_12 ( L_6 , V_18 ) ;
return - V_35 ;
}
if ( V_40 [ F_9 ( V_2 ) ] ==
V_40 [ V_14 -> V_34 ] &&
F_18 ( V_14 -> V_33 ) != V_14 -> V_3 ) {
struct V_13 * V_41 ;
V_41 = F_32 ( V_5 , V_15 ) ;
if ( ! V_41 ) {
F_12 ( L_7 ) ;
return - V_35 ;
}
F_16 ( L_8 ,
V_41 -> V_18 , V_18 ) ;
V_29 = F_15 ( V_5 , V_41 ) ;
if ( V_29 ) {
F_12 ( L_9 , V_29 ) ;
return V_29 ;
}
}
return F_15 ( V_5 , V_14 ) ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_42 * V_43 )
{
int V_29 , V_15 ;
T_1 V_44 ;
V_29 = F_35 ( V_43 , L_10 , & V_44 ) ;
if ( V_29 ) {
F_12 ( L_11 , V_43 ) ;
return V_29 ;
}
V_14 -> V_18 = V_44 ;
V_29 = F_35 ( V_43 , L_12 , & V_44 ) ;
if ( V_29 ) {
F_12 ( L_13 , V_43 ) ;
return V_29 ;
}
V_14 -> V_3 = V_44 ;
V_14 -> V_33 = F_36 ( V_43 , L_14 ) ;
if ( F_37 ( V_14 -> V_33 ) ) {
F_12 ( L_15 , V_43 ) ;
return F_38 ( V_14 -> V_33 ) ;
}
V_14 -> V_34 = 0xff ;
for ( V_15 = 0 ; V_15 < F_39 ( V_45 ) ; V_15 ++ ) {
if ( ! strcmp ( V_45 [ V_15 ] ,
F_17 ( V_14 -> V_33 ) ) ) {
V_14 -> V_34 = V_15 ;
break;
}
}
if ( V_14 -> V_34 == 0xff ) {
F_12 ( L_16 ,
V_43 , F_17 ( V_14 -> V_33 ) ) ;
F_40 ( V_14 -> V_33 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_41 ( const void * V_46 , const void * V_47 )
{
const struct V_13 * V_48 = V_46 ;
const struct V_13 * V_49 = V_47 ;
if ( V_48 -> V_18 < V_49 -> V_18 )
return - 1 ;
else if ( V_48 -> V_18 == V_49 -> V_18 )
return 0 ;
else
return 1 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_42 * V_43 ,
T_1 V_12 )
{
struct V_42 * V_50 ;
int V_51 = F_43 ( V_43 ) ;
int V_15 = 0 , V_29 ;
V_5 -> V_17 = F_44 ( V_51 , sizeof( struct V_13 ) ,
V_52 ) ;
if ( ! V_5 -> V_17 )
return - V_53 ;
V_5 -> V_16 = V_51 ;
F_45 (node, child) {
struct V_13 * V_14 = V_5 -> V_17 + ( V_15 ++ ) ;
V_29 = F_34 ( V_5 , V_14 , V_50 ) ;
if ( V_29 ) {
F_13 ( V_50 ) ;
return V_29 ;
}
V_14 -> V_12 = V_12 ;
}
F_46 ( V_5 -> V_17 , V_5 -> V_16 , sizeof( struct V_13 ) ,
F_41 , NULL ) ;
return 0 ;
}
struct V_54 * F_47 ( void T_3 * V_55 , struct V_42 * V_56 ,
T_4 * V_37 )
{
struct V_4 * V_5 ;
struct V_57 V_58 ;
struct V_42 * V_43 ;
T_1 V_59 ;
struct V_54 * V_54 ;
int V_29 ;
V_5 = F_44 ( 1 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return F_48 ( - V_53 ) ;
V_5 -> V_7 = V_55 ;
V_5 -> V_37 = V_37 ;
V_5 -> V_16 = 0 ;
F_45 (np, node) {
V_29 = F_35 ( V_43 , L_17 ,
& V_59 ) ;
if ( V_29 )
continue;
V_29 = F_42 ( V_5 , V_43 , V_59 ) ;
F_13 ( V_43 ) ;
if ( V_29 )
return F_48 ( V_29 ) ;
break;
}
if ( V_5 -> V_16 == 0 )
F_49 ( L_18 , V_28 ) ;
V_5 -> V_27 = F_50 ( V_56 ,
L_19 , 0 ) ;
if ( ! V_5 -> V_27 )
F_49 ( L_20 , V_28 ) ;
V_58 . V_60 = L_21 ;
V_58 . V_61 = & V_62 ;
V_58 . V_31 = 0 ;
V_58 . V_63 = V_45 ;
V_58 . V_64 = F_39 ( V_45 ) ;
V_5 -> V_2 . V_58 = & V_58 ;
V_54 = F_51 ( NULL , & V_5 -> V_2 ) ;
if ( F_37 ( V_54 ) )
return V_54 ;
V_5 -> V_38 = F_52 (
& V_5 -> V_2 , F_9 ( & V_5 -> V_2 ) ) -> V_54 ;
V_5 -> V_36 = false ;
F_53 ( V_54 , L_21 , L_22 ) ;
F_21 ( V_54 ) ;
return V_54 ;
}
