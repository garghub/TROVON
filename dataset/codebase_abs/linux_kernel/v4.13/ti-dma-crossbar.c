static inline void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 & 0x1f , V_1 + V_2 ) ;
}
static void F_3 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = F_4 ( V_5 ) ;
struct V_9 * V_10 = V_6 ;
F_5 ( V_5 , L_1 ,
V_10 -> V_11 , V_10 -> V_12 ) ;
F_1 ( V_8 -> V_1 , V_10 -> V_12 , 0 ) ;
F_6 ( V_10 ) ;
}
static void * F_7 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_8 ( V_16 -> V_19 ) ;
struct V_7 * V_8 = F_9 ( V_18 ) ;
struct V_9 * V_10 ;
if ( V_14 -> V_20 != 3 )
return F_10 ( - V_21 ) ;
if ( V_14 -> args [ 2 ] >= V_8 -> V_22 ) {
F_11 ( & V_18 -> V_5 , L_2 ,
V_14 -> args [ 2 ] ) ;
return F_10 ( - V_21 ) ;
}
if ( V_14 -> args [ 0 ] >= V_8 -> V_23 ) {
F_11 ( & V_18 -> V_5 , L_3 ,
V_14 -> args [ 0 ] ) ;
return F_10 ( - V_21 ) ;
}
V_14 -> V_24 = F_12 ( V_16 -> V_19 , L_4 , 0 ) ;
if ( ! V_14 -> V_24 ) {
F_11 ( & V_18 -> V_5 , L_5 ) ;
return F_10 ( - V_21 ) ;
}
V_10 = F_13 ( sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 ) {
F_14 ( V_14 -> V_24 ) ;
return F_10 ( - V_26 ) ;
}
V_10 -> V_12 = ( T_2 ) V_14 -> args [ 0 ] ;
V_10 -> V_11 = ( T_2 ) V_14 -> args [ 2 ] ;
V_14 -> args [ 2 ] = 0 ;
V_14 -> V_20 = 2 ;
F_5 ( & V_18 -> V_5 , L_6 ,
V_10 -> V_11 , V_10 -> V_12 ) ;
F_1 ( V_8 -> V_1 , V_10 -> V_12 , V_10 -> V_11 ) ;
return V_10 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_27 * V_28 = V_18 -> V_5 . V_19 ;
const struct V_29 * V_30 ;
struct V_27 * V_31 ;
struct V_7 * V_8 ;
struct V_32 * V_33 ;
void T_1 * V_1 ;
int V_34 , V_35 ;
if ( ! V_28 )
return - V_36 ;
V_8 = F_16 ( & V_18 -> V_5 , sizeof( * V_8 ) , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_31 = F_12 ( V_28 , L_4 , 0 ) ;
if ( ! V_31 ) {
F_11 ( & V_18 -> V_5 , L_7 ) ;
return - V_36 ;
}
V_30 = F_17 ( V_37 , V_31 ) ;
if ( ! V_30 ) {
F_11 ( & V_18 -> V_5 , L_8 ) ;
F_14 ( V_31 ) ;
return - V_21 ;
}
if ( F_18 ( V_31 , L_9 ,
& V_8 -> V_23 ) ) {
F_19 ( & V_18 -> V_5 ,
L_10 ,
V_38 ) ;
V_8 -> V_23 = V_38 ;
}
F_14 ( V_31 ) ;
if ( F_18 ( V_28 , L_9 , & V_8 -> V_22 ) ) {
F_19 ( & V_18 -> V_5 ,
L_11 ,
V_38 ) ;
V_8 -> V_22 = V_38 ;
}
V_33 = F_20 ( V_18 , V_39 , 0 ) ;
V_1 = F_21 ( & V_18 -> V_5 , V_33 ) ;
if ( F_22 ( V_1 ) )
return F_23 ( V_1 ) ;
V_8 -> V_1 = V_1 ;
V_8 -> V_40 . V_5 = & V_18 -> V_5 ;
V_8 -> V_40 . V_41 = F_3 ;
F_24 ( V_18 , V_8 ) ;
for ( V_34 = 0 ; V_34 < V_8 -> V_23 ; V_34 ++ )
F_1 ( V_8 -> V_1 , V_34 , 0 ) ;
V_35 = F_25 ( V_28 , F_7 ,
& V_8 -> V_40 ) ;
return V_35 ;
}
static inline void F_26 ( void T_1 * V_1 , int V_8 , T_2 V_3 )
{
F_27 ( V_3 , V_1 + ( V_8 * 2 ) ) ;
}
static void F_28 ( struct V_4 * V_5 , void * V_6 )
{
struct V_42 * V_8 = F_4 ( V_5 ) ;
struct V_43 * V_10 = V_6 ;
F_5 ( V_5 , L_12 ,
V_10 -> V_44 , V_10 -> V_45 ) ;
F_26 ( V_8 -> V_1 , V_10 -> V_45 , V_8 -> V_46 ) ;
F_29 ( & V_8 -> V_47 ) ;
F_30 ( V_10 -> V_45 , V_8 -> V_48 ) ;
F_31 ( & V_8 -> V_47 ) ;
F_6 ( V_10 ) ;
}
static void * F_32 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_8 ( V_16 -> V_19 ) ;
struct V_42 * V_8 = F_9 ( V_18 ) ;
struct V_43 * V_10 ;
if ( V_14 -> args [ 0 ] >= V_8 -> V_49 ) {
F_11 ( & V_18 -> V_5 , L_13 ,
V_14 -> args [ 0 ] ) ;
return F_10 ( - V_21 ) ;
}
V_14 -> V_24 = F_12 ( V_16 -> V_19 , L_4 , 0 ) ;
if ( ! V_14 -> V_24 ) {
F_11 ( & V_18 -> V_5 , L_5 ) ;
return F_10 ( - V_21 ) ;
}
V_10 = F_13 ( sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 ) {
F_14 ( V_14 -> V_24 ) ;
return F_10 ( - V_26 ) ;
}
F_29 ( & V_8 -> V_47 ) ;
V_10 -> V_45 = F_33 ( V_8 -> V_48 ,
V_8 -> V_23 ) ;
F_31 ( & V_8 -> V_47 ) ;
if ( V_10 -> V_45 == V_8 -> V_23 ) {
F_11 ( & V_18 -> V_5 , L_14 ) ;
F_6 ( V_10 ) ;
return F_10 ( - V_26 ) ;
}
F_34 ( V_10 -> V_45 , V_8 -> V_48 ) ;
V_10 -> V_44 = ( T_2 ) V_14 -> args [ 0 ] ;
V_14 -> args [ 0 ] = V_10 -> V_45 + V_8 -> V_50 ;
F_5 ( & V_18 -> V_5 , L_15 ,
V_10 -> V_44 , V_10 -> V_45 ) ;
F_26 ( V_8 -> V_1 , V_10 -> V_45 , V_10 -> V_44 ) ;
return V_10 ;
}
static inline void F_35 ( int V_51 , int V_52 , unsigned long * V_53 )
{
for (; V_52 > 0 ; V_52 -- )
F_30 ( V_51 + ( V_52 - 1 ) , V_53 ) ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_27 * V_28 = V_18 -> V_5 . V_19 ;
const struct V_29 * V_30 ;
struct V_27 * V_31 ;
struct V_42 * V_8 ;
struct V_54 * V_55 ;
struct V_32 * V_33 ;
T_3 V_46 ;
int V_56 ;
void T_1 * V_1 ;
int V_34 , V_35 ;
if ( ! V_28 )
return - V_36 ;
V_8 = F_16 ( & V_18 -> V_5 , sizeof( * V_8 ) , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_31 = F_12 ( V_28 , L_4 , 0 ) ;
if ( ! V_31 ) {
F_11 ( & V_18 -> V_5 , L_7 ) ;
return - V_36 ;
}
V_30 = F_17 ( V_57 , V_31 ) ;
if ( ! V_30 ) {
F_11 ( & V_18 -> V_5 , L_8 ) ;
F_14 ( V_31 ) ;
return - V_21 ;
}
if ( F_18 ( V_31 , L_9 ,
& V_8 -> V_23 ) ) {
F_19 ( & V_18 -> V_5 ,
L_10 ,
V_58 ) ;
V_8 -> V_23 = V_58 ;
}
F_14 ( V_31 ) ;
V_8 -> V_48 = F_37 ( & V_18 -> V_5 ,
F_38 ( V_8 -> V_23 ) ,
sizeof( unsigned long ) , V_25 ) ;
if ( ! V_8 -> V_48 )
return - V_26 ;
if ( F_18 ( V_28 , L_9 , & V_8 -> V_49 ) ) {
F_19 ( & V_18 -> V_5 ,
L_11 ,
V_59 ) ;
V_8 -> V_49 = V_59 ;
}
if ( ! F_18 ( V_28 , L_16 , & V_46 ) )
V_8 -> V_46 = ( T_2 ) V_46 ;
V_55 = F_39 ( V_28 , L_17 , & V_56 ) ;
if ( V_55 ) {
const char V_60 [] = L_17 ;
T_3 ( * V_61 ) [ 2 ] ;
T_4 V_62 = V_56 / sizeof( * V_61 ) ;
int V_34 ;
if ( ! V_62 )
return - V_21 ;
V_61 = F_40 ( V_62 , sizeof( * V_61 ) , V_25 ) ;
if ( ! V_61 )
return - V_26 ;
V_35 = F_41 ( V_28 , V_60 , ( T_3 * ) V_61 ,
V_62 * 2 ) ;
if ( V_35 )
return V_35 ;
for ( V_34 = 0 ; V_34 < V_62 ; V_34 ++ ) {
F_35 ( V_61 [ V_34 ] [ 0 ] , V_61 [ V_34 ] [ 1 ] ,
V_8 -> V_48 ) ;
}
F_6 ( V_61 ) ;
}
V_33 = F_20 ( V_18 , V_39 , 0 ) ;
V_1 = F_21 ( & V_18 -> V_5 , V_33 ) ;
if ( F_22 ( V_1 ) )
return F_23 ( V_1 ) ;
V_8 -> V_1 = V_1 ;
V_8 -> V_40 . V_5 = & V_18 -> V_5 ;
V_8 -> V_40 . V_41 = F_28 ;
V_8 -> V_50 = * ( T_3 * ) V_30 -> V_63 ;
F_42 ( & V_8 -> V_47 ) ;
F_24 ( V_18 , V_8 ) ;
for ( V_34 = 0 ; V_34 < V_8 -> V_23 ; V_34 ++ ) {
if ( ! F_43 ( V_34 , V_8 -> V_48 ) )
F_26 ( V_8 -> V_1 , V_34 , V_8 -> V_46 ) ;
}
V_35 = F_25 ( V_28 , F_32 ,
& V_8 -> V_40 ) ;
if ( V_35 ) {
for ( V_34 = 0 ; V_34 < V_8 -> V_23 ; V_34 ++ ) {
if ( ! F_43 ( V_34 , V_8 -> V_48 ) )
F_26 ( V_8 -> V_1 , V_34 , V_34 ) ;
}
}
return V_35 ;
}
static int F_44 ( struct V_17 * V_18 )
{
const struct V_29 * V_30 ;
int V_35 ;
V_30 = F_17 ( V_64 , V_18 -> V_5 . V_19 ) ;
if ( F_45 ( ! V_30 ) )
return - V_21 ;
switch ( * ( T_3 * ) V_30 -> V_63 ) {
case V_65 :
V_35 = F_36 ( V_18 ) ;
break;
case V_66 :
V_35 = F_15 ( V_18 ) ;
break;
default:
F_11 ( & V_18 -> V_5 , L_18 ) ;
V_35 = - V_36 ;
break;
}
return V_35 ;
}
static int F_46 ( void )
{
return F_47 ( & V_67 ) ;
}
