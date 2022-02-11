static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
V_4 -> V_5 ( V_4 , V_4 -> V_6 ) ;
}
static inline void F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_3 * V_4 = F_2 ( V_8 ,
struct V_3 , V_7 ) ;
V_4 -> V_6 = V_10 ;
F_4 ( & V_4 -> V_2 ) ;
}
int F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
if ( F_6 ( V_14 -> V_16 , V_17 ,
NULL , NULL ) != V_18 )
return - V_19 ;
return 0 ;
}
int F_7 ( struct V_11 * V_12 , int V_20 , T_1 * V_21 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
union V_22 V_23 = { V_24 } ;
struct V_25 args = { 1 , & V_23 } ;
unsigned long long V_26 ;
T_2 V_27 ;
V_23 . integer . V_28 = V_20 ;
V_27 = F_8 ( V_14 -> V_16 , L_1 , & args , & V_26 ) ;
* V_21 = V_26 ;
return ( V_27 != V_18 ) ? - V_19 : 0 ;
}
int F_9 ( struct V_11 * V_12 , int V_20 , T_1 V_29 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned long long V_21 ;
union V_22 V_30 [ 2 ] ;
struct V_25 args = { 2 , V_30 } ;
V_30 [ 0 ] . type = V_24 ;
V_30 [ 0 ] . integer . V_28 = V_20 ;
V_30 [ 1 ] . type = V_24 ;
V_30 [ 1 ] . integer . V_28 = V_29 ;
if ( F_8 ( V_14 -> V_16 , L_2 , & args , & V_21 ) != V_18 )
return - V_19 ;
return 0 ;
}
static int F_10 ( const struct V_31 * V_32 )
{
V_33 . V_34 = * ( (union V_35 * ) V_32 -> V_36 ) ;
F_11 ( L_3 , V_32 -> V_37 ) ;
return 1 ;
}
static void F_12 ( struct V_3 * V_8 , enum V_9 V_28 )
{
struct V_13 * V_14 = V_33 . V_15 ;
unsigned long long V_21 ;
union V_22 V_30 [ 1 ] ;
struct V_25 args = { 1 , V_30 } ;
V_30 [ 0 ] . type = V_24 ;
V_30 [ 0 ] . integer . V_28 = ! ! V_28 ;
F_8 ( V_14 -> V_16 , L_4 , & args , & V_21 ) ;
}
static T_2
F_13 ( struct V_38 * V_39 , void * V_40 )
{
if ( V_39 -> type == V_41 ) {
struct V_42 * V_43 ;
T_3 * V_44 = V_40 ;
V_43 = & V_39 -> V_4 . V_45 ;
* V_44 = V_43 -> V_46 [ 0 ] ;
}
return V_18 ;
}
static void F_14 ( struct V_13 * V_47 )
{
T_2 V_27 ;
V_27 = F_15 ( V_47 -> V_16 , V_48 ,
F_13 , & V_33 . V_43 ) ;
if ( F_16 ( V_27 ) )
F_17 (KERN_DEBUG DRIVER_NAME L_5 ) ;
}
static int F_18 ( struct V_13 * V_47 )
{
int V_21 ;
if ( ! V_47 )
return - V_19 ;
V_33 . V_15 = V_47 ;
V_33 . V_49 = F_5 ;
V_33 . V_50 = F_7 ;
V_33 . V_51 = F_9 ;
strcpy ( F_19 ( V_47 ) , V_52 ) ;
strcpy ( F_20 ( V_47 ) , V_53 ) ;
V_47 -> V_36 = & V_33 ;
F_14 ( V_47 ) ;
if ( V_33 . V_34 . V_54 && V_33 . V_34 . V_55 && V_33 . V_34 . V_56 ) {
F_11 ( L_6 ,
V_33 . V_34 . V_54 , V_33 . V_34 . V_55 , V_33 . V_34 . V_56 ) ;
} else if ( F_21 ( V_57 ) == 0 ) {
F_11 ( L_7 ) ;
V_33 . V_34 = V_58 ;
}
V_21 = F_22 ( & V_33 ) ;
if ( V_21 )
return V_21 ;
F_23 ( & V_59 . V_2 , F_1 ) ;
V_21 = F_24 ( NULL , & V_59 . V_7 ) ;
if ( V_21 ) {
F_25 ( & V_33 ) ;
F_26 ( & V_33 ) ;
F_27 ( & V_59 . V_2 ) ;
return V_21 ;
}
return V_21 ;
}
static int F_28 ( struct V_13 * V_47 , int type )
{
if ( ! V_47 )
return - V_19 ;
F_25 ( & V_33 ) ;
F_26 ( & V_33 ) ;
F_29 ( & V_59 . V_7 ) ;
F_27 ( & V_59 . V_2 ) ;
return F_30 ( & V_33 ) ;
}
static int F_31 ( struct V_13 * V_47 , T_4 V_60 )
{
F_26 ( & V_33 ) ;
return 0 ;
}
static int F_32 ( struct V_13 * V_47 )
{
return F_33 ( & V_33 ) ;
}
static int T_5 F_34 ( void )
{
int V_21 ;
if ( V_61 )
return - V_62 ;
V_21 = F_35 ( & V_63 ) ;
if ( V_21 < 0 )
return V_21 ;
F_11 ( L_8 ) ;
return 0 ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_63 ) ;
}
