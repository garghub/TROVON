static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 . V_13 = V_10 ;
V_10 = F_5 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_14 [ 0 ] . V_10 = V_10 ;
V_12 . V_15 = V_10 ;
V_9 -> V_16 = F_6 ( V_8 -> V_17 , & V_18 ) ;
if ( ! V_9 -> V_16 ) {
V_19:
ERROR ( V_8 , L_1 ,
V_3 -> V_20 , V_8 -> V_17 -> V_20 ) ;
return - V_21 ;
}
V_9 -> V_16 -> V_22 = V_8 ;
V_9 -> V_23 = F_6 ( V_8 -> V_17 , & V_24 ) ;
if ( ! V_9 -> V_23 )
goto V_19;
V_9 -> V_23 -> V_22 = V_8 ;
V_25 . V_26 =
V_18 . V_26 ;
V_27 . V_26 = V_24 . V_26 ;
V_28 . V_26 =
V_18 . V_26 ;
V_29 . V_26 = V_24 . V_26 ;
V_11 = F_7 ( V_3 , V_30 , V_31 ,
V_32 ) ;
if ( V_11 )
return V_11 ;
F_8 ( V_8 , L_2 ,
( F_9 ( V_6 -> V_8 -> V_17 ) ? L_3 :
( F_10 ( V_6 -> V_8 -> V_17 ) ? L_4 : L_5 ) ) ,
V_3 -> V_20 , V_9 -> V_16 -> V_20 , V_9 -> V_23 -> V_20 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 ) ;
F_13 ( F_1 ( V_3 ) ) ;
}
static void F_14 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
struct V_1 * V_9 = V_34 -> V_22 ;
struct V_7 * V_8 = V_9 -> V_4 . V_37 -> V_8 ;
int V_38 = V_36 -> V_38 ;
switch ( V_38 ) {
case 0 :
if ( V_34 == V_9 -> V_23 ) {
V_36 -> V_39 = ( V_36 -> V_40 < V_36 -> V_41 ) ;
V_36 -> V_41 = V_36 -> V_40 ;
V_38 = F_15 ( V_9 -> V_16 , V_36 , V_42 ) ;
if ( V_38 == 0 )
return;
ERROR ( V_8 , L_6 ,
V_34 -> V_20 , V_9 -> V_16 -> V_20 ,
V_38 ) ;
}
V_36 -> V_41 = V_43 ;
V_38 = F_15 ( V_9 -> V_23 , V_36 , V_42 ) ;
if ( V_38 == 0 )
return;
default:
ERROR ( V_8 , L_7 , V_34 -> V_20 ,
V_38 , V_36 -> V_40 , V_36 -> V_41 ) ;
case - V_44 :
case - V_45 :
case - V_46 :
F_16 ( V_34 , V_36 ) ;
return;
}
}
static void F_17 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_37 -> V_8 ;
F_18 ( V_8 , V_9 -> V_16 , V_9 -> V_23 , NULL , NULL ) ;
F_19 ( V_8 , L_8 , V_9 -> V_4 . V_20 ) ;
}
static int
F_20 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_47 = 0 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned V_48 ;
V_34 = V_9 -> V_16 ;
V_47 = F_21 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_34 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_22 ( V_34 ) ;
if ( V_47 < 0 )
return V_47 ;
V_34 -> V_22 = V_9 ;
V_34 = V_9 -> V_23 ;
V_47 = F_21 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_34 ) ;
if ( V_47 )
goto V_49;
V_47 = F_22 ( V_34 ) ;
if ( V_47 < 0 ) {
V_49:
V_34 = V_9 -> V_16 ;
F_23 ( V_34 ) ;
V_34 -> V_22 = NULL ;
return V_47 ;
}
V_34 -> V_22 = V_9 ;
for ( V_48 = 0 ; V_48 < V_50 && V_47 == 0 ; V_48 ++ ) {
V_36 = F_24 ( V_34 , 0 ) ;
if ( V_36 ) {
V_36 -> V_51 = F_14 ;
V_47 = F_15 ( V_34 , V_36 , V_42 ) ;
if ( V_47 )
ERROR ( V_8 , L_9 ,
V_34 -> V_20 , V_47 ) ;
} else {
F_23 ( V_34 ) ;
V_34 -> V_22 = NULL ;
V_47 = - V_52 ;
goto V_49;
}
}
F_8 ( V_8 , L_10 , V_9 -> V_4 . V_20 ) ;
return V_47 ;
}
static int F_25 ( struct V_2 * V_3 ,
unsigned V_53 , unsigned V_54 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_37 -> V_8 ;
if ( V_9 -> V_16 -> V_22 )
F_17 ( V_9 ) ;
return F_20 ( V_8 , V_9 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_17 ( V_9 ) ;
}
static struct V_2 * F_27 ( struct V_55 * V_56 )
{
struct V_1 * V_9 ;
struct V_57 * V_58 ;
V_9 = F_28 ( sizeof *V_9 , V_59 ) ;
if ( ! V_9 )
return F_29 ( - V_52 ) ;
V_58 = F_2 ( V_56 , struct V_57 , V_60 ) ;
V_43 = V_58 -> V_61 ;
V_50 = V_58 -> V_50 ;
if ( ! V_50 )
V_50 = 32 ;
V_9 -> V_4 . V_20 = L_11 ;
V_9 -> V_4 . V_62 = F_3 ;
V_9 -> V_4 . V_63 = F_25 ;
V_9 -> V_4 . V_64 = F_26 ;
V_9 -> V_4 . V_65 = V_66 ;
V_9 -> V_4 . V_67 = F_11 ;
return & V_9 -> V_4 ;
}
static void F_30 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
V_58 = F_2 ( V_56 , struct V_57 , V_60 ) ;
F_13 ( V_58 ) ;
}
static struct V_55 * F_31 ( void )
{
struct V_57 * V_58 ;
V_58 = F_28 ( sizeof( * V_58 ) , V_59 ) ;
if ( ! V_58 )
return F_29 ( - V_52 ) ;
V_58 -> V_60 . V_68 = F_30 ;
return & V_58 -> V_60 ;
}
int T_1 F_32 ( void )
{
int V_11 ;
V_11 = F_33 ( & V_69 ) ;
if ( V_11 )
return V_11 ;
return V_11 ;
}
void T_2 F_34 ( void )
{
F_35 ( & V_69 ) ;
}
