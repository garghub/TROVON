static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_10 )
{
V_10 -> V_11 = F_5 (
& V_12 ) ;
F_6 ( L_1 , V_10 -> V_11 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 ) {
F_8 ( V_10 -> V_11 ) ;
V_10 -> V_11 = 0 ;
}
}
static void F_9 ( struct V_9 * V_10 , int V_13 )
{
if ( V_10 -> V_11 ) {
F_6 ( L_2 , V_13 ) ;
V_13 = 1 ;
F_10 ( V_10 -> V_11 , V_13 ) ;
}
}
static void F_4 ( struct V_9 * V_10 ) {}
static void F_7 ( struct V_9 * V_10 ) {}
static void F_9 ( struct V_9 * V_10 , int V_13 ) {}
static int F_11 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_6 = V_3 -> V_6 -> V_6 ;
T_1 V_17 , V_18 , V_19 ;
long V_20 ;
int V_21 = F_12 ( F_13 ( V_3 -> V_22 ) ) ;
if ( F_14 ( V_1 -> V_23 ) ) {
F_15 ( V_6 , L_3 ) ;
return - V_24 ;
}
V_17 = V_15 -> V_25 * V_15 -> V_26 ;
if ( ! V_17 ) {
F_15 ( V_6 , L_4 ,
V_27 , V_15 -> V_25 , V_15 -> V_26 ) ;
return - V_24 ;
}
V_20 = F_16 ( V_1 -> V_23 , V_28 ) ;
if ( V_20 <= 0 ) {
F_15 ( V_6 , L_5 ,
V_20 ) ;
return - V_24 ;
}
V_18 = V_20 * 100 / V_17 ;
V_19 = V_29
| V_30 ;
V_19 |= F_17 ( V_18 ) ;
F_18 ( V_1 , F_19 ( V_21 ) , V_19 ) ;
F_18 ( V_1 ,
F_20 ( V_21 ) , 0xfff0 ) ;
F_18 ( V_1 ,
F_21 ( V_21 ) , V_15 -> V_31 ) ;
F_18 ( V_1 , F_22 ( V_21 ) , V_15 -> V_31 + 1 ) ;
F_18 ( V_1 , F_23 ( V_21 ) , V_15 -> V_31 ) ;
F_18 ( V_1 , F_24 ( V_21 ) ,
F_25 ( 4 ) |
F_26 ( 4 ) ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_21 = F_12 ( F_13 ( V_3 -> V_22 ) ) ;
int V_32 ;
V_32 = F_28 ( V_1 -> V_23 ,
F_16 ( V_1 -> V_23 , V_28 ) ) ;
if ( V_32 ) {
F_15 ( V_3 -> V_6 -> V_6 ,
L_6 , V_32 ) ;
return V_32 ;
}
V_32 = F_29 ( V_1 -> V_23 ) ;
if ( V_32 ) {
F_15 ( V_3 -> V_6 -> V_6 ,
L_7 , V_32 ) ;
return V_32 ;
}
F_18 ( V_1 , F_30 ( V_21 ) , 1 ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_21 = F_12 ( F_13 ( V_3 -> V_22 ) ) ;
F_18 ( V_1 , F_30 ( V_21 ) , 0 ) ;
F_32 ( V_1 -> V_23 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_34 ( V_3 ) ;
F_7 ( V_10 ) ;
F_35 ( V_3 ) ;
F_36 ( V_10 ) ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_14 * V_33 )
{
struct V_9 * V_10 = F_34 ( V_3 ) ;
V_15 = V_33 ;
F_6 ( L_8 ,
V_15 -> V_34 . V_35 , V_15 -> V_36 ,
V_15 -> V_26 , V_15 -> clock ,
V_15 -> V_37 , V_15 -> V_38 ,
V_15 -> V_39 , V_15 -> V_40 ,
V_15 -> V_31 , V_15 -> V_41 ,
V_15 -> V_42 , V_15 -> V_25 ,
V_15 -> type , V_15 -> V_43 ) ;
F_11 ( V_3 , V_15 ) ;
F_38 ( V_3 -> V_22 , & V_10 -> V_44 ,
V_10 -> V_45 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_34 ( V_3 ) ;
struct V_46 * V_45 = V_10 -> V_45 ;
struct V_47 * V_44 = & V_10 -> V_44 ;
if ( F_40 ( ! V_10 -> V_48 ) )
return;
F_31 ( V_3 ) ;
F_41 ( V_45 , false ) ;
F_42 ( V_45 , F_43 ( V_44 ) ) ;
F_9 ( V_10 , 0 ) ;
V_10 -> V_48 = false ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_34 ( V_3 ) ;
struct V_46 * V_45 = V_10 -> V_45 ;
struct V_47 * V_44 = & V_10 -> V_44 ;
if ( F_40 ( V_10 -> V_48 ) )
return;
F_9 ( V_10 , 1 ) ;
if ( F_27 ( V_3 ) )
return;
F_42 ( V_45 , F_43 ( V_44 ) ) ;
F_41 ( V_45 , true ) ;
V_10 -> V_48 = true ;
}
int F_45 ( struct V_2 * V_3 ,
struct V_2 * V_49 )
{
struct V_9 * V_10 = F_34 ( V_3 ) ;
struct V_1 * V_1 ;
int V_50 ;
T_1 V_51 = 0 ;
if ( ! V_3 || ! V_49 )
return - V_24 ;
V_1 = F_1 ( V_3 ) ;
V_50 = V_10 -> V_44 . V_52 ;
if ( V_50 == 1 )
V_51 |= V_53 ;
else if ( V_50 == 2 )
V_51 |= V_54 ;
else
return - V_24 ;
V_51 |= V_55 ;
F_46 ( V_1 ) ;
F_18 ( V_1 , F_47 ( 0 ) , V_51 ) ;
F_18 ( V_1 , F_48 ( 0 ) ,
V_56 ) ;
F_18 ( V_1 , F_49 ( 0 ) , 1 ) ;
F_50 ( V_1 ) ;
return 0 ;
}
struct V_2 * F_51 ( struct V_57 * V_6 ,
struct V_47 * V_44 , struct V_46 * V_45 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_10 ;
int V_32 ;
if ( F_40 ( ( V_44 -> type != V_58 ) &&
( V_44 -> V_15 != V_59 ) ) ) {
V_32 = - V_24 ;
goto V_60;
}
V_10 = F_52 ( sizeof( * V_10 ) , V_61 ) ;
if ( ! V_10 ) {
V_32 = - V_62 ;
goto V_60;
}
memcpy ( & V_10 -> V_44 , V_44 , sizeof( V_10 -> V_44 ) ) ;
V_3 = & V_10 -> V_34 ;
V_10 -> V_45 = V_45 ;
F_53 ( V_6 , V_3 , & V_63 ,
V_64 , NULL ) ;
F_54 ( V_3 , & V_65 ) ;
F_4 ( V_10 ) ;
return V_3 ;
V_60:
if ( V_3 )
F_33 ( V_3 ) ;
return F_55 ( V_32 ) ;
}
