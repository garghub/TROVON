static inline bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_6 ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_12 = V_7 -> V_10 ;
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned int V_16 = F_3 ( V_14 ) ;
return V_9 -> V_17 >= V_9 -> V_18 + ( V_9 -> V_19 ? 0 : V_16 ) ;
}
static int F_4 ( struct V_20 * V_1 , struct V_21 * V_22 , T_1 V_23 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_6 ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
struct V_11 * V_12 = V_7 -> V_10 ;
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned int V_24 = F_5 ( V_14 ) ;
return F_6 ( V_1 , V_22 , V_23 , V_24 ) ;
}
static int F_7 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_27 * V_29 , unsigned int V_30 )
{
F_8 ( V_31 , V_26 ) ;
F_9 ( V_31 , V_26 ) ;
F_10 ( V_31 , V_32 ,
NULL , NULL ) ;
F_11 ( V_31 , V_28 , V_29 , V_30 , NULL ) ;
return F_12 ( V_31 ) ;
}
static int F_13 ( struct V_20 * V_1 , struct V_21 * V_22 ,
T_1 V_33 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_6 ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_12 = V_7 -> V_10 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_25 * V_26 = V_12 -> V_26 ;
unsigned int V_16 = F_3 ( V_14 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_27 * V_28 ;
int V_39 = 0 ;
T_1 V_17 = 0 ;
T_1 V_40 = 0 ;
T_1 V_41 = 0 ;
T_1 V_42 = 0 ;
V_17 = V_9 -> V_17 ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
if ( V_9 -> V_19 )
V_40 = V_17 + V_16 ;
else
V_40 = V_17 - V_16 ;
V_17 -= V_9 -> V_18 ;
V_36 = F_14 ( V_2 , sizeof( struct V_35 ) +
F_15 ( V_14 ) ) ;
if ( F_16 ( V_36 ) )
return F_17 ( V_36 ) ;
V_39 = F_18 ( V_2 , V_22 , V_34 , V_36 , V_40 , & V_41 ) ;
if ( V_39 )
goto free;
if ( V_41 < V_40 ) {
T_1 V_44 = V_40 - V_41 ;
if ( V_17 < V_44 ) {
V_39 = - V_43 ;
goto free;
}
V_17 -= V_44 ;
V_40 -= V_44 ;
}
V_42 = V_17 + V_9 -> V_18 ;
V_38 = F_19 ( & V_9 -> V_45 , struct V_37 , V_46 ) ;
V_28 = V_36 -> V_47 . V_48 . V_49 ;
if ( V_9 -> V_19 ) {
V_39 = F_7 ( V_26 , V_38 -> V_49 ,
V_36 -> V_47 . V_48 . V_49 , V_42 ) ;
if ( V_39 )
goto free;
F_20 ( V_2 , V_42 , NULL , 0 ) ;
} else {
V_39 = F_7 ( V_26 , V_38 -> V_49 ,
V_36 -> V_47 . V_48 . V_49 , V_40 ) ;
if ( V_39 )
goto free;
V_36 -> V_50 = F_21 ( V_2 , V_42 ,
V_42 - V_16 ) ;
if ( ! V_36 -> V_50 )
V_36 -> V_50 = 1 ;
V_36 -> V_38 = F_22 ( V_2 , sizeof( * V_36 -> V_38 ) *
V_36 -> V_50 ,
V_51 ) ;
if ( ! V_36 -> V_38 ) {
V_39 = - V_52 ;
goto free;
}
F_23 ( V_36 -> V_38 , V_36 -> V_50 ) ;
F_20 ( V_2 , V_42 , V_36 -> V_38 , V_42 - V_16 ) ;
if ( V_41 ) {
struct V_53 * V_54 = & V_36 -> V_55 -> V_48 ;
F_24 ( V_54 -> V_49 + V_54 -> V_56 - 1 ) ;
F_25 ( V_54 -> V_49 , V_54 -> V_56 + 1 ,
V_36 -> V_38 ) ;
} else
V_28 = V_36 -> V_38 ;
}
F_26 ( & V_36 -> V_57 . V_58 , V_28 ,
V_36 -> V_47 . V_48 . V_49 , V_17 , V_9 -> V_59 ) ;
F_27 ( & V_36 -> V_57 . V_58 , V_9 -> V_18 ) ;
F_28 ( & V_36 -> V_57 . V_58 , V_14 ) ;
if ( V_22 -> V_60 && ! F_29 ( V_22 -> V_60 ) ) {
V_36 -> V_61 = V_22 -> V_60 ;
F_30 ( & V_36 -> V_57 . V_58 ,
V_32 ,
V_62 , V_36 ) ;
V_39 = V_9 -> V_19 ? F_31 ( & V_36 -> V_57 . V_58 ) :
F_32 ( & V_36 -> V_57 . V_58 ) ;
} else {
F_30 ( & V_36 -> V_57 . V_58 ,
V_32 ,
V_63 , & V_9 -> V_64 ) ;
V_39 = F_33 ( V_9 -> V_19 ?
F_31 ( & V_36 -> V_57 . V_58 ) :
F_32 ( & V_36 -> V_57 . V_58 ) ,
& V_9 -> V_64 ) ;
}
if ( V_39 == - V_65 ) {
F_34 ( V_2 ) ;
V_36 -> V_40 = V_40 ;
return - V_66 ;
}
free:
F_35 ( V_36 ) ;
F_36 ( V_2 , V_36 , V_36 -> V_67 ) ;
return V_39 ? V_39 : V_40 ;
}
static int F_37 ( struct V_20 * V_1 , struct V_21 * V_22 ,
T_1 V_33 , int V_34 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_68 = 0 ;
F_38 ( V_2 ) ;
while ( F_39 ( V_22 ) ) {
int V_39 = F_13 ( V_1 , V_22 , V_33 , V_34 ) ;
if ( V_39 <= 0 ) {
if ( V_39 == - V_66 || V_39 == - V_69 || ! V_68 )
V_68 = V_39 ;
goto V_70;
}
V_68 += V_39 ;
}
V_70:
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
return V_68 ;
}
static int F_42 ( struct V_20 * V_1 )
{
int V_39 = 0 ;
struct V_1 * V_5 ;
struct V_3 * V_7 ;
struct V_11 * V_14 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( V_4 -> V_71 )
goto V_72;
V_5 = V_4 -> V_6 ;
V_7 = F_2 ( V_4 -> V_6 ) ;
V_14 = V_7 -> V_10 ;
V_39 = - V_73 ;
F_43 ( V_5 , V_74 ) ;
if ( ! V_14 -> V_75 )
goto V_76;
if ( ! V_7 -> V_71 ++ )
F_34 ( V_5 ) ;
V_4 -> V_71 = 1 ;
F_44 ( V_5 ) ;
V_39 = 0 ;
V_76:
F_41 ( V_5 ) ;
V_72:
F_41 ( V_2 ) ;
return V_39 ;
}
static int F_45 ( struct V_20 * V_1 , struct V_21 * V_22 ,
T_1 V_23 )
{
int V_39 ;
V_39 = F_42 ( V_1 ) ;
if ( V_39 )
return V_39 ;
return F_4 ( V_1 , V_22 , V_23 ) ;
}
static T_2 F_46 ( struct V_20 * V_1 , struct V_77 * V_77 ,
int V_78 , T_1 V_23 , int V_34 )
{
int V_39 ;
V_39 = F_42 ( V_1 ) ;
if ( V_39 )
return V_39 ;
return F_47 ( V_1 , V_77 , V_78 , V_23 , V_34 ) ;
}
static int F_48 ( struct V_20 * V_1 , struct V_21 * V_22 ,
T_1 V_33 , int V_34 )
{
int V_39 ;
V_39 = F_42 ( V_1 ) ;
if ( V_39 )
return V_39 ;
return F_37 ( V_1 , V_22 , V_33 , V_34 ) ;
}
static void * F_49 ( const char * V_79 , T_3 type , T_3 V_80 )
{
struct V_11 * V_14 ;
struct V_13 * V_15 ;
struct V_25 * V_26 ;
V_14 = F_50 ( sizeof( * V_14 ) , V_51 ) ;
if ( ! V_14 )
return F_51 ( - V_52 ) ;
V_15 = F_52 ( V_79 , type , V_80 ) ;
if ( F_16 ( V_15 ) ) {
F_53 ( V_14 ) ;
return F_54 ( V_15 ) ;
}
V_26 = F_55 () ;
if ( F_16 ( V_26 ) ) {
F_56 ( V_15 ) ;
F_53 ( V_14 ) ;
return F_54 ( V_26 ) ;
}
V_14 -> V_15 = V_15 ;
V_14 -> V_26 = V_26 ;
return V_14 ;
}
static void F_57 ( void * V_10 )
{
struct V_11 * V_14 = V_10 ;
F_56 ( V_14 -> V_15 ) ;
F_53 ( V_14 ) ;
}
static int F_58 ( void * V_10 , unsigned int V_81 )
{
struct V_11 * V_14 = V_10 ;
return F_59 ( V_14 -> V_15 , V_81 ) ;
}
static int F_60 ( void * V_10 , const T_4 * V_82 , unsigned int V_83 )
{
struct V_11 * V_14 = V_10 ;
int V_39 ;
V_39 = F_61 ( V_14 -> V_15 , V_82 , V_83 ) ;
V_14 -> V_75 = ! V_39 ;
return V_39 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_1 * V_5 = V_4 -> V_6 ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
struct V_11 * V_12 = V_7 -> V_10 ;
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned int V_84 = F_5 ( V_14 ) ;
F_20 ( V_2 , V_9 -> V_17 , NULL , 0 ) ;
F_63 () ;
F_64 ( V_2 , V_9 -> V_59 , V_84 ) ;
F_36 ( V_2 , V_9 , V_9 -> V_30 ) ;
F_65 ( V_2 ) ;
}
static int F_66 ( void * V_10 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_14 = V_10 ;
struct V_13 * V_15 = V_14 -> V_15 ;
unsigned int V_30 = sizeof( * V_9 ) ;
unsigned int V_84 = F_5 ( V_15 ) ;
V_9 = F_22 ( V_2 , V_30 , V_51 ) ;
if ( ! V_9 )
return - V_52 ;
memset ( V_9 , 0 , V_30 ) ;
V_9 -> V_59 = F_22 ( V_2 , V_84 , V_51 ) ;
if ( ! V_9 -> V_59 ) {
F_36 ( V_2 , V_9 , V_30 ) ;
return - V_52 ;
}
memset ( V_9 -> V_59 , 0 , V_84 ) ;
F_67 ( & V_9 -> V_45 ) ;
V_9 -> V_30 = V_30 ;
V_9 -> V_17 = 0 ;
V_9 -> V_85 = 0 ;
V_9 -> V_86 = 0 ;
V_9 -> V_87 = 0 ;
V_9 -> V_19 = 0 ;
V_9 -> V_18 = 0 ;
F_68 ( & V_9 -> V_64 ) ;
V_4 -> V_10 = V_9 ;
V_2 -> V_88 = F_62 ;
return 0 ;
}
static int F_69 ( void * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_14 = V_10 ;
if ( ! V_14 -> V_75 )
return - V_73 ;
return F_66 ( V_10 , V_2 ) ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_89 ) ;
}
static void T_6 F_72 ( void )
{
int V_39 = F_73 ( & V_89 ) ;
F_74 ( V_39 ) ;
}
