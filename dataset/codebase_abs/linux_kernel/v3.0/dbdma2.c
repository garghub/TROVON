static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 , V_6 ) ;
++ V_2 -> V_7 ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_7 >= V_2 -> V_8 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_4 = V_2 -> V_9 ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 , V_6 ) ;
++ V_2 -> V_7 ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_7 >= V_2 -> V_8 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_4 = V_2 -> V_9 ;
}
}
static void F_5 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
V_2 -> V_12 += V_2 -> V_5 ;
if ( ++ V_2 -> V_13 >= V_2 -> V_8 ) {
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
}
F_6 ( V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
}
static void F_7 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
V_2 -> V_12 += V_2 -> V_5 ;
if ( ++ V_2 -> V_13 >= V_2 -> V_8 ) {
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
}
F_6 ( V_2 -> V_14 ) ;
F_3 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_15 )
{
if ( V_15 -> V_3 ) {
F_9 ( V_15 -> V_3 ) ;
F_10 ( V_15 -> V_3 ) ;
F_11 ( V_15 -> V_3 ) ;
V_15 -> V_3 = 0 ;
V_15 -> V_16 = 0 ;
}
}
static int F_12 ( struct V_1 * V_15 ,
int V_17 , int V_16 )
{
if ( V_16 == 24 )
V_16 = 32 ;
if ( ( V_15 -> V_3 ) && ( V_16 == V_15 -> V_16 ) )
goto V_18;
F_8 ( V_15 ) ;
if ( V_17 == V_19 )
V_15 -> V_3 = F_13 ( V_15 -> V_20 ,
V_21 ,
F_7 , ( void * ) V_15 ) ;
else
V_15 -> V_3 = F_13 ( V_21 ,
V_15 -> V_20 ,
F_5 , ( void * ) V_15 ) ;
if ( ! V_15 -> V_3 )
return - V_22 ;
F_14 ( V_15 -> V_3 , V_16 ) ;
F_15 ( V_15 -> V_3 , 2 ) ;
V_15 -> V_16 = V_16 ;
F_9 ( V_15 -> V_3 ) ;
F_10 ( V_15 -> V_3 ) ;
V_18:
return 0 ;
}
static inline struct V_1 * F_16 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_15 =
F_17 ( V_26 -> V_28 ) ;
return & V_15 [ F_18 ( V_24 ) ] ;
}
static int F_19 ( struct V_23 * V_14 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_14 -> V_32 ;
struct V_1 * V_15 ;
int V_17 , V_33 ;
V_33 = F_20 ( V_14 , F_21 ( V_30 ) ) ;
if ( V_33 < 0 )
goto V_18;
V_17 = F_18 ( V_14 ) ;
V_15 = F_16 ( V_14 ) ;
F_22 ( L_1
L_2 ,
( unsigned long ) V_32 -> V_4 ,
( unsigned long ) V_32 -> V_34 , V_32 -> V_35 ,
V_32 -> V_36 ) ;
F_22 ( L_3 , V_30 -> V_16 ,
F_23 ( V_30 ) , F_24 ( V_30 ) , V_17 ) ;
V_33 = F_12 ( V_15 , V_17 , V_30 -> V_16 ) ;
if ( V_33 ) {
F_25 ( L_4 ) ;
goto V_18;
}
V_15 -> V_14 = V_14 ;
V_15 -> V_5 = F_24 ( V_30 ) ;
V_15 -> V_8 = F_23 ( V_30 ) ;
V_15 -> V_9 = V_15 -> V_4 = V_32 -> V_34 ;
V_15 -> V_7 = 0 ;
V_15 -> V_13 = 0 ;
V_15 -> V_12 = 0 ;
V_33 = 0 ;
V_18:
return V_33 ;
}
static int F_26 ( struct V_23 * V_14 )
{
F_27 ( V_14 ) ;
return 0 ;
}
static int F_28 ( struct V_23 * V_14 )
{
struct V_1 * V_15 = F_16 ( V_14 ) ;
F_10 ( V_15 -> V_3 ) ;
if ( F_18 ( V_14 ) == V_19 ) {
F_3 ( V_15 ) ;
F_3 ( V_15 ) ;
} else {
F_1 ( V_15 ) ;
F_1 ( V_15 ) ;
}
return 0 ;
}
static int F_29 ( struct V_23 * V_14 , int V_37 )
{
T_1 V_38 = F_16 ( V_14 ) -> V_3 ;
switch ( V_37 ) {
case V_39 :
case V_40 :
F_30 ( V_38 ) ;
break;
case V_41 :
case V_42 :
F_9 ( V_38 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static T_2
F_31 ( struct V_23 * V_14 )
{
return F_32 ( V_14 -> V_32 , F_16 ( V_14 ) -> V_12 ) ;
}
static int F_33 ( struct V_23 * V_14 )
{
F_34 ( V_14 , & V_44 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_14 )
{
F_8 ( F_16 ( V_14 ) ) ;
return 0 ;
}
static void F_36 ( struct V_45 * V_46 )
{
F_37 ( V_46 ) ;
}
static int F_38 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_45 * V_46 )
{
F_39 ( V_46 , V_51 ,
V_48 -> V_52 , V_53 , ( 4096 * 1024 ) - 1 ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_56 ;
struct V_57 * V_58 ;
int V_33 ;
V_56 = F_41 ( 2 * sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_56 )
return - V_22 ;
V_58 = F_42 ( V_55 , V_60 , 0 ) ;
if ( ! V_58 ) {
V_33 = - V_61 ;
goto V_62;
}
V_56 [ V_63 ] . V_20 = V_58 -> V_64 ;
V_58 = F_42 ( V_55 , V_60 , 1 ) ;
if ( ! V_58 ) {
V_33 = - V_61 ;
goto V_62;
}
V_56 [ V_19 ] . V_20 = V_58 -> V_64 ;
F_43 ( V_55 , V_56 ) ;
V_33 = F_44 ( & V_55 -> V_52 , & V_65 ) ;
if ( ! V_33 )
return V_33 ;
V_62:
F_45 ( V_56 ) ;
return V_33 ;
}
static int T_4 F_46 ( struct V_54 * V_55 )
{
struct V_1 * V_56 = F_47 ( V_55 ) ;
F_48 ( & V_55 -> V_52 ) ;
F_45 ( V_56 ) ;
return 0 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_66 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_66 ) ;
}
struct V_54 * F_53 ( struct V_54 * V_55 )
{
struct V_57 * V_67 , * V_58 ;
struct V_54 * V_68 ;
int V_69 [ 2 ] ;
int V_33 ;
V_58 = F_42 ( V_55 , V_60 , 0 ) ;
if ( ! V_58 )
return NULL ;
V_69 [ 0 ] = V_58 -> V_64 ;
V_58 = F_42 ( V_55 , V_60 , 1 ) ;
if ( ! V_58 )
return NULL ;
V_69 [ 1 ] = V_58 -> V_64 ;
V_67 = F_41 ( sizeof( struct V_57 ) * 2 , V_59 ) ;
if ( ! V_67 )
return NULL ;
V_67 [ 0 ] . V_64 = V_67 [ 0 ] . V_70 = V_69 [ 0 ] ;
V_67 [ 1 ] . V_64 = V_67 [ 1 ] . V_70 = V_69 [ 1 ] ;
V_67 [ 0 ] . V_71 = V_67 [ 1 ] . V_71 = V_60 ;
V_68 = F_54 ( L_5 , V_55 -> V_69 ) ;
if ( ! V_68 )
goto V_18;
V_68 -> V_57 = V_67 ;
V_68 -> V_72 = 2 ;
V_33 = F_55 ( V_68 ) ;
if ( ! V_33 )
return V_68 ;
F_56 ( V_68 ) ;
V_18:
F_45 ( V_67 ) ;
return NULL ;
}
void F_57 ( struct V_54 * V_73 )
{
if ( V_73 )
F_58 ( V_73 ) ;
}
