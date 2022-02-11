static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_4 -> V_5 -> V_6 ( V_3 -> V_4 ) ;
F_3 ( V_2 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 ;
F_6 ( F_7 ( V_3 -> V_4 , V_7 ) ) ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
struct V_14 * V_4 = V_9 -> V_15 [ V_12 ] ;
if ( V_4 -> V_2 == V_2 )
F_6 ( F_7 ( V_4 , V_7 ) ) ;
}
}
static bool F_8 ( struct V_1 * V_2 ,
struct V_16 * V_7 ,
struct V_16 * V_17 )
{
return true ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 * V_7 ,
struct V_16 * V_17 ,
int V_18 , int V_19 ,
struct V_20 * V_21 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_14 * V_4 = V_3 -> V_4 ;
return F_10 ( V_4 , V_2 , V_2 -> V_22 ,
0 , 0 , V_7 -> V_23 , V_7 -> V_24 ,
V_18 << 16 , V_19 << 16 ,
V_7 -> V_23 << 16 , V_7 -> V_24 << 16 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_12 ( L_1 , V_3 -> V_25 ) ;
F_5 ( V_2 , V_26 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_12 ( L_1 , V_3 -> V_25 ) ;
F_5 ( V_2 , V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_18 , int V_19 ,
struct V_20 * V_21 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_14 * V_4 = V_3 -> V_4 ;
struct V_16 * V_7 = & V_2 -> V_7 ;
return V_4 -> V_5 -> V_28 ( V_4 , V_2 , V_2 -> V_22 ,
0 , 0 , V_7 -> V_23 , V_7 -> V_24 ,
V_18 << 16 , V_19 << 16 ,
V_7 -> V_23 << 16 , V_7 -> V_24 << 16 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
}
static void F_16 ( void * V_29 )
{
static T_1 V_30 = 0 ;
struct V_1 * V_2 = V_29 ;
struct V_31 * V_10 = V_2 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_32 * V_33 = V_3 -> V_33 ;
unsigned long V_34 ;
struct V_35 V_36 ;
F_6 ( ! V_33 ) ;
V_3 -> V_33 = NULL ;
if ( V_33 ) {
F_17 ( & V_36 ) ;
F_18 ( & V_10 -> V_37 , V_34 ) ;
V_33 -> V_33 . V_30 = V_30 ++ ;
V_33 -> V_33 . V_38 = V_36 . V_38 ;
V_33 -> V_33 . V_39 = V_36 . V_39 ;
F_19 ( & V_33 -> V_40 . V_41 ,
& V_33 -> V_40 . V_42 -> V_43 ) ;
F_20 ( & V_33 -> V_40 . V_42 -> V_44 ) ;
F_21 ( & V_10 -> V_37 , V_34 ) ;
}
}
static void F_22 ( void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_3 -> V_21 ;
V_3 -> V_21 = NULL ;
F_14 ( V_2 , V_2 -> V_18 , V_2 -> V_19 , V_21 ) ;
F_23 ( V_3 -> V_4 , F_16 , V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_20 * V_22 ,
struct V_32 * V_33 )
{
struct V_31 * V_10 = V_2 -> V_10 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_12 ( L_2 , V_2 -> V_22 ? V_2 -> V_22 -> V_40 . V_45 : - 1 , V_22 -> V_40 . V_45 ) ;
if ( V_3 -> V_33 ) {
F_25 ( V_10 -> V_10 , L_3 ) ;
return - V_46 ;
}
V_3 -> V_21 = V_2 -> V_22 ;
V_3 -> V_33 = V_33 ;
V_2 -> V_22 = V_22 ;
F_26 ( F_27 ( V_22 , 0 ) , V_47 ,
F_22 , V_2 ) ;
return 0 ;
}
struct V_1 * F_28 ( struct V_31 * V_10 ,
struct V_48 * V_49 , int V_45 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 = F_29 ( sizeof( * V_3 ) , V_50 ) ;
F_12 ( L_1 , V_49 -> V_25 ) ;
if ( ! V_3 ) {
F_25 ( V_10 -> V_10 , L_4 ) ;
goto V_51;
}
V_2 = & V_3 -> V_40 ;
V_3 -> V_4 = F_30 ( V_10 , V_49 , ( 1 << V_45 ) , true ) ;
V_3 -> V_4 -> V_2 = V_2 ;
V_3 -> V_25 = V_49 -> V_25 ;
V_3 -> V_45 = V_45 ;
F_31 ( V_10 , V_2 , & V_52 ) ;
F_32 ( V_2 , & V_53 ) ;
return V_2 ;
V_51:
if ( V_2 ) {
F_1 ( V_2 ) ;
}
return NULL ;
}
