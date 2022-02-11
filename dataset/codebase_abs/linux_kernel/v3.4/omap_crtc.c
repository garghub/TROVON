static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 , T_1 * V_5 , T_2 V_6 , T_2 V_7 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_3 ( V_2 ) ;
V_8 -> V_9 -> V_10 -> V_11 ( V_8 -> V_9 ) ;
F_4 ( V_2 ) ;
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 -> V_16 ;
struct V_8 * V_8 = F_3 ( V_2 ) ;
int V_17 ;
F_7 ( F_8 ( V_8 -> V_9 , V_12 ) ) ;
for ( V_17 = 0 ; V_17 < V_14 -> V_18 ; V_17 ++ ) {
struct V_19 * V_9 = V_14 -> V_20 [ V_17 ] ;
if ( V_9 -> V_2 == V_2 )
F_7 ( F_8 ( V_9 , V_12 ) ) ;
}
}
static bool F_9 ( struct V_1 * V_2 ,
struct V_21 * V_12 ,
struct V_21 * V_22 )
{
return true ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_21 * V_12 ,
struct V_21 * V_22 ,
int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_8 * V_8 = F_3 ( V_2 ) ;
struct V_19 * V_9 = V_8 -> V_9 ;
return F_11 ( V_9 , V_2 , V_2 -> V_27 ,
0 , 0 , V_12 -> V_28 , V_12 -> V_29 ,
V_23 << 16 , V_24 << 16 ,
V_12 -> V_28 << 16 , V_12 -> V_29 << 16 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_3 ( V_2 ) ;
F_13 ( L_1 , V_8 -> V_30 ) ;
F_6 ( V_2 , V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_3 ( V_2 ) ;
F_13 ( L_1 , V_8 -> V_30 ) ;
F_6 ( V_2 , V_32 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_8 * V_8 = F_3 ( V_2 ) ;
struct V_19 * V_9 = V_8 -> V_9 ;
struct V_21 * V_12 = & V_2 -> V_12 ;
return V_9 -> V_10 -> V_33 ( V_9 , V_2 , V_2 -> V_27 ,
0 , 0 , V_12 -> V_28 , V_12 -> V_29 ,
V_23 << 16 , V_24 << 16 ,
V_12 -> V_28 << 16 , V_12 -> V_29 << 16 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static void F_17 ( void * V_34 )
{
static T_2 V_35 = 0 ;
struct V_1 * V_2 = V_34 ;
struct V_36 * V_15 = V_2 -> V_15 ;
struct V_8 * V_8 = F_3 ( V_2 ) ;
struct V_37 * V_38 = V_8 -> V_38 ;
unsigned long V_39 ;
struct V_40 V_41 ;
F_7 ( ! V_38 ) ;
V_8 -> V_38 = NULL ;
if ( V_38 ) {
F_18 ( & V_41 ) ;
F_19 ( & V_15 -> V_42 , V_39 ) ;
V_38 -> V_38 . V_35 = V_35 ++ ;
V_38 -> V_38 . V_43 = V_41 . V_43 ;
V_38 -> V_38 . V_44 = V_41 . V_44 ;
F_20 ( & V_38 -> V_45 . V_46 ,
& V_38 -> V_45 . V_47 -> V_48 ) ;
F_21 ( & V_38 -> V_45 . V_47 -> V_49 ) ;
F_22 ( & V_15 -> V_42 , V_39 ) ;
}
}
static void F_23 ( void * V_34 )
{
struct V_1 * V_2 = V_34 ;
struct V_8 * V_8 = F_3 ( V_2 ) ;
struct V_25 * V_26 = V_8 -> V_26 ;
V_8 -> V_26 = NULL ;
F_15 ( V_2 , V_2 -> V_23 , V_2 -> V_24 , V_26 ) ;
F_24 ( V_8 -> V_9 , F_17 , V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_25 * V_27 ,
struct V_37 * V_38 )
{
struct V_36 * V_15 = V_2 -> V_15 ;
struct V_8 * V_8 = F_3 ( V_2 ) ;
F_13 ( L_2 , V_2 -> V_27 ? V_2 -> V_27 -> V_45 . V_50 : - 1 , V_27 -> V_45 . V_50 ) ;
if ( V_8 -> V_38 ) {
F_26 ( V_15 -> V_15 , L_3 ) ;
return - V_51 ;
}
V_8 -> V_26 = V_2 -> V_27 ;
V_8 -> V_38 = V_38 ;
V_2 -> V_27 = V_27 ;
F_27 ( F_28 ( V_27 , 0 ) , V_52 ,
F_23 , V_2 ) ;
return 0 ;
}
struct V_1 * F_29 ( struct V_36 * V_15 ,
struct V_53 * V_54 , int V_50 )
{
struct V_1 * V_2 = NULL ;
struct V_8 * V_8 = F_30 ( sizeof( * V_8 ) , V_55 ) ;
F_13 ( L_1 , V_54 -> V_30 ) ;
if ( ! V_8 ) {
F_26 ( V_15 -> V_15 , L_4 ) ;
goto V_56;
}
V_2 = & V_8 -> V_45 ;
V_8 -> V_9 = F_31 ( V_15 , V_54 , ( 1 << V_50 ) , true ) ;
V_8 -> V_9 -> V_2 = V_2 ;
V_8 -> V_30 = V_54 -> V_30 ;
V_8 -> V_50 = V_50 ;
F_32 ( V_15 , V_2 , & V_57 ) ;
F_33 ( V_2 , & V_58 ) ;
return V_2 ;
V_56:
if ( V_2 ) {
F_2 ( V_2 ) ;
}
return NULL ;
}
