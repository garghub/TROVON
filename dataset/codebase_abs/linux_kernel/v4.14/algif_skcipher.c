static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_2 * V_9 = V_8 -> V_10 ;
struct V_7 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned V_18 = F_3 ( V_16 ) ;
return F_4 ( V_2 , V_4 , V_5 , V_18 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_19 , int V_20 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_2 * V_9 = V_8 -> V_10 ;
struct V_7 * V_11 = F_2 ( V_9 ) ;
struct V_21 * V_22 = V_8 -> V_14 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned int V_23 = F_6 ( V_16 ) ;
struct V_24 * V_25 ;
int V_26 = 0 ;
T_1 V_27 = 0 ;
V_25 = F_7 ( V_6 , sizeof( struct V_24 ) +
F_8 ( V_16 ) ) ;
if ( F_9 ( V_25 ) )
return F_10 ( V_25 ) ;
V_26 = F_11 ( V_6 , V_4 , V_20 , V_25 , - 1 , & V_27 ) ;
if ( V_26 )
goto free;
if ( V_27 > V_22 -> V_28 )
V_27 = V_22 -> V_28 ;
if ( V_22 -> V_29 || V_27 < V_22 -> V_28 )
V_27 -= V_27 % V_23 ;
V_25 -> V_30 = F_12 ( V_6 , V_27 , 0 ) ;
if ( ! V_25 -> V_30 )
V_25 -> V_30 = 1 ;
V_25 -> V_31 = F_13 ( V_6 , sizeof( * V_25 -> V_31 ) * V_25 -> V_30 ,
V_32 ) ;
if ( ! V_25 -> V_31 ) {
V_26 = - V_33 ;
goto free;
}
F_14 ( V_25 -> V_31 , V_25 -> V_30 ) ;
F_15 ( V_6 , V_27 , V_25 -> V_31 , 0 ) ;
F_16 ( & V_25 -> V_34 . V_35 , V_16 ) ;
F_17 ( & V_25 -> V_34 . V_35 , V_25 -> V_31 ,
V_25 -> V_36 . V_37 . V_38 , V_27 , V_22 -> V_39 ) ;
if ( V_4 -> V_40 && ! F_18 ( V_4 -> V_40 ) ) {
V_25 -> V_41 = V_4 -> V_40 ;
F_19 ( & V_25 -> V_34 . V_35 ,
V_42 ,
V_43 , V_25 ) ;
V_26 = V_22 -> V_44 ?
F_20 ( & V_25 -> V_34 . V_35 ) :
F_21 ( & V_25 -> V_34 . V_35 ) ;
} else {
F_19 ( & V_25 -> V_34 . V_35 ,
V_42 |
V_45 ,
V_46 ,
& V_22 -> V_47 ) ;
V_26 = F_22 ( V_22 -> V_44 ?
F_20 ( & V_25 -> V_34 . V_35 ) :
F_21 ( & V_25 -> V_34 . V_35 ) ,
& V_22 -> V_47 ) ;
}
if ( V_26 == - V_48 ) {
F_23 ( V_6 ) ;
V_25 -> V_49 = V_27 ;
return - V_50 ;
}
free:
F_24 ( V_25 ) ;
F_25 ( V_6 , V_25 , V_25 -> V_51 ) ;
return V_26 ? V_26 : V_27 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_19 , int V_20 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int V_52 = 0 ;
F_27 ( V_6 ) ;
while ( F_28 ( V_4 ) ) {
int V_26 = F_5 ( V_2 , V_4 , V_19 , V_20 ) ;
if ( V_26 <= 0 ) {
if ( V_26 == - V_50 || ! V_52 )
V_52 = V_26 ;
goto V_53;
}
V_52 += V_26 ;
}
V_53:
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
return V_52 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
struct V_2 * V_9 ;
struct V_7 * V_11 ;
struct V_12 * V_16 ;
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
F_27 ( V_6 ) ;
if ( V_8 -> V_54 )
goto V_55;
V_9 = V_8 -> V_10 ;
V_11 = F_2 ( V_8 -> V_10 ) ;
V_16 = V_11 -> V_14 ;
V_26 = - V_56 ;
F_32 ( V_9 , V_57 ) ;
if ( ! V_16 -> V_58 )
goto V_59;
if ( ! V_11 -> V_54 ++ )
F_23 ( V_9 ) ;
V_8 -> V_54 = 1 ;
F_33 ( V_9 ) ;
V_26 = 0 ;
V_59:
F_30 ( V_9 ) ;
V_55:
F_30 ( V_6 ) ;
return V_26 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
int V_26 ;
V_26 = F_31 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_1 ( V_2 , V_4 , V_5 ) ;
}
static T_2 F_35 ( struct V_1 * V_2 , struct V_60 * V_60 ,
int V_61 , T_1 V_5 , int V_20 )
{
int V_26 ;
V_26 = F_31 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_36 ( V_2 , V_60 , V_61 , V_5 , V_20 ) ;
}
static int F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_19 , int V_20 )
{
int V_26 ;
V_26 = F_31 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return F_26 ( V_2 , V_4 , V_19 , V_20 ) ;
}
static void * F_38 ( const char * V_62 , T_3 type , T_3 V_63 )
{
struct V_12 * V_16 ;
struct V_15 * V_17 ;
V_16 = F_39 ( sizeof( * V_16 ) , V_32 ) ;
if ( ! V_16 )
return F_40 ( - V_33 ) ;
V_17 = F_41 ( V_62 , type , V_63 ) ;
if ( F_9 ( V_17 ) ) {
F_42 ( V_16 ) ;
return F_43 ( V_17 ) ;
}
V_16 -> V_17 = V_17 ;
return V_16 ;
}
static void F_44 ( void * V_14 )
{
struct V_12 * V_16 = V_14 ;
F_45 ( V_16 -> V_17 ) ;
F_42 ( V_16 ) ;
}
static int F_46 ( void * V_14 , const T_4 * V_64 , unsigned int V_65 )
{
struct V_12 * V_16 = V_14 ;
int V_26 ;
V_26 = F_47 ( V_16 -> V_17 , V_64 , V_65 ) ;
V_16 -> V_58 = ! V_26 ;
return V_26 ;
}
static void F_48 ( struct V_2 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_21 * V_22 = V_8 -> V_14 ;
struct V_2 * V_9 = V_8 -> V_10 ;
struct V_7 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 ;
F_15 ( V_6 , V_22 -> V_28 , NULL , 0 ) ;
F_49 ( V_6 , V_22 -> V_39 , F_3 ( V_16 ) ) ;
F_25 ( V_6 , V_22 , V_22 -> V_27 ) ;
F_50 ( V_6 ) ;
}
static int F_51 ( void * V_14 , struct V_2 * V_6 )
{
struct V_21 * V_22 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_12 * V_16 = V_14 ;
struct V_15 * V_17 = V_16 -> V_17 ;
unsigned int V_27 = sizeof( * V_22 ) ;
V_22 = F_13 ( V_6 , V_27 , V_32 ) ;
if ( ! V_22 )
return - V_33 ;
V_22 -> V_39 = F_13 ( V_6 , F_3 ( V_17 ) ,
V_32 ) ;
if ( ! V_22 -> V_39 ) {
F_25 ( V_6 , V_22 , V_27 ) ;
return - V_33 ;
}
memset ( V_22 -> V_39 , 0 , F_3 ( V_17 ) ) ;
F_52 ( & V_22 -> V_66 ) ;
V_22 -> V_27 = V_27 ;
V_22 -> V_28 = 0 ;
V_22 -> V_67 = 0 ;
V_22 -> V_29 = 0 ;
V_22 -> V_68 = 0 ;
V_22 -> V_44 = 0 ;
F_53 ( & V_22 -> V_47 ) ;
V_8 -> V_14 = V_22 ;
V_6 -> V_69 = F_48 ;
return 0 ;
}
static int F_54 ( void * V_14 , struct V_2 * V_6 )
{
struct V_12 * V_16 = V_14 ;
if ( ! V_16 -> V_58 && F_55 ( V_16 -> V_17 ) )
return - V_56 ;
return F_51 ( V_14 , V_6 ) ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_70 ) ;
}
static void T_6 F_58 ( void )
{
int V_26 = F_59 ( & V_70 ) ;
F_60 ( V_26 ) ;
}
