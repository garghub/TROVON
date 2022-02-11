static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 . V_4 = V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( V_8 , V_4 ) ;
F_5 ( V_8 , V_4 , false ) ;
F_6 ( V_8 , V_4 ) ;
F_7 ( V_8 , V_4 ) ;
F_8 ( V_8 , V_4 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_10 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ,
struct V_1 , V_5 . V_6 ) ;
F_3 ( V_2 , V_2 -> V_5 . V_4 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_3 * V_4 , bool V_11 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_13 ;
V_13 = F_13 ( V_8 , V_4 ) ;
if ( V_13 )
return V_13 ;
F_14 ( & V_2 -> V_5 . V_14 ) ;
F_15 ( & V_2 -> V_5 . V_6 ) ;
F_16 ( V_8 , V_4 ) ;
if ( V_11 )
F_1 ( V_2 , V_4 ) ;
else
F_3 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_5 . V_14 ) ;
return 0 ;
}
static void F_18 ( struct V_7 * V_15 )
{
V_15 -> V_16 . V_17 = 0 ;
V_15 -> V_16 . V_18 = 0 ;
V_15 -> V_16 . V_19 = V_20 ;
V_15 -> V_16 . V_21 = V_22 ;
V_15 -> V_16 . V_23 = & V_24 ;
}
static int F_19 ( struct V_7 * V_15 , unsigned long V_25 )
{
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 ) {
F_21 ( L_1 ) ;
return - V_28 ;
}
V_15 -> V_12 = ( void * ) V_2 ;
V_2 -> V_9 = V_15 ;
F_22 ( & V_2 -> V_5 . V_14 ) ;
F_23 ( & V_2 -> V_5 . V_6 , F_10 ) ;
F_24 ( V_15 ) ;
F_25 ( V_15 ) ;
F_18 ( V_15 ) ;
V_26 = F_26 ( V_15 -> V_15 , V_15 ) ;
if ( V_26 ) {
F_27 ( V_15 ) ;
F_28 ( V_15 ) ;
F_29 ( V_2 ) ;
return V_26 ;
}
F_30 ( V_15 ) ;
F_31 ( V_15 ) ;
F_32 ( V_15 , 32 ,
V_15 -> V_16 . V_29 ,
V_15 -> V_16 . V_30 ) ;
return 0 ;
}
static struct V_31 * F_33 ( struct V_7 * V_15 ,
struct V_32 * V_33 ,
int V_25 )
{
V_25 |= V_34 ;
return F_34 ( V_15 , V_33 , V_25 ) ;
}
static int F_35 ( struct V_35 * V_15 , void * V_36 )
{
return V_15 -> V_37 == V_36 ;
}
static int F_36 ( struct V_35 * V_15 )
{
return F_37 ( & V_38 , F_38 ( V_15 ) ) ;
}
static void F_39 ( struct V_35 * V_15 )
{
F_40 ( F_41 ( V_15 ) ) ;
}
static int F_42 ( struct V_39 * V_40 )
{
struct V_35 * V_15 = & V_40 -> V_15 ;
struct V_41 * V_42 = V_15 -> V_37 ;
struct V_41 * V_43 ;
struct V_44 * V_45 = NULL ;
F_43 ( V_15 , F_44 ( 32 ) ) ;
F_45 ( V_42 , NULL , NULL , V_15 ) ;
V_43 = F_46 ( V_42 , NULL ) ;
while ( V_43 ) {
F_47 ( V_15 , & V_45 , F_35 , V_43 ) ;
F_48 ( V_43 ) ;
V_43 = F_46 ( V_42 , V_43 ) ;
}
return F_49 ( V_15 , & V_46 , V_45 ) ;
}
static int F_50 ( struct V_39 * V_40 )
{
F_51 ( & V_40 -> V_15 , & V_46 ) ;
F_52 ( & V_40 -> V_15 ) ;
return 0 ;
}
static int F_53 ( void )
{
return F_54 ( V_47 , F_55 ( V_47 ) ) ;
}
static void F_56 ( void )
{
F_57 ( V_47 , F_55 ( V_47 ) ) ;
}
