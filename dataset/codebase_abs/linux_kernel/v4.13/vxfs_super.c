static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 ) ;
}
static int
F_6 ( struct V_9 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_12 ) ;
struct V_13 * V_14 = V_4 -> V_15 ;
V_11 -> V_16 = V_17 ;
V_11 -> V_18 = V_9 -> V_12 -> V_19 ;
V_11 -> V_20 = F_7 ( V_4 , V_14 -> V_21 ) ;
V_11 -> V_22 = F_7 ( V_4 , V_14 -> V_23 ) ;
V_11 -> V_24 = 0 ;
V_11 -> V_25 = 0 ;
V_11 -> V_26 = F_7 ( V_4 , V_14 -> V_27 ) ;
V_11 -> V_28 = V_29 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_30 , int * V_31 , char * V_32 )
{
F_9 ( V_30 ) ;
* V_31 |= V_33 ;
return 0 ;
}
static struct V_34 * F_10 ( struct V_1 * V_30 )
{
struct V_35 * V_36 ;
V_36 = F_11 ( V_37 , V_38 ) ;
if ( ! V_36 )
return NULL ;
F_12 ( & V_36 -> V_39 ) ;
return & V_36 -> V_39 ;
}
static void F_13 ( struct V_40 * V_41 )
{
struct V_34 * V_34 = F_14 ( V_41 , struct V_34 , V_42 ) ;
F_15 ( V_37 , F_16 ( V_34 ) ) ;
}
static void F_17 ( struct V_34 * V_34 )
{
F_18 ( & V_34 -> V_42 , F_13 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_43 ,
unsigned V_44 , T_1 V_45 )
{
struct V_46 * V_47 ;
struct V_13 * V_48 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_49 = - V_50 ;
V_47 = F_20 ( V_2 , V_44 ) ;
do {
if ( ! V_47 || ! F_21 ( V_47 ) ) {
if ( ! V_43 ) {
F_22 ( V_51
L_1 ,
V_44 ) ;
}
break;
}
V_49 = - V_52 ;
V_48 = (struct V_13 * ) V_47 -> V_53 ;
if ( V_48 -> V_54 != V_45 ) {
if ( ! V_43 )
F_22 ( V_55
L_2 ,
V_48 -> V_54 , V_44 ) ;
break;
}
V_49 = 0 ;
V_4 -> V_15 = V_48 ;
V_4 -> V_8 = V_47 ;
} while ( 0 );
if ( V_49 ) {
V_4 -> V_15 = NULL ;
V_4 -> V_8 = NULL ;
F_4 ( V_47 ) ;
}
return V_49 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_56 , int V_43 )
{
struct V_3 * V_4 ;
struct V_13 * V_48 ;
T_2 V_57 ;
struct V_34 * V_58 ;
int V_59 = - V_52 ;
T_3 V_60 ;
V_2 -> V_61 |= V_33 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
F_22 ( V_51 L_3 ) ;
return - V_50 ;
}
V_57 = F_25 ( V_2 , V_62 ) ;
if ( ! V_57 ) {
F_22 ( V_51 L_4 ) ;
goto V_63;
}
V_2 -> V_64 = & V_65 ;
V_2 -> V_66 = V_4 ;
if ( ! F_19 ( V_2 , V_43 , 1 ,
( V_67 T_1 ) F_26 ( V_17 ) ) ) {
V_4 -> V_68 = V_69 ;
} else if ( ! F_19 ( V_2 , V_43 , 8 ,
( V_67 T_1 ) F_27 ( V_17 ) ) ) {
V_4 -> V_68 = V_70 ;
} else {
if ( ! V_43 )
F_22 ( V_55 L_5 ) ;
goto V_63;
}
V_48 = V_4 -> V_15 ;
V_60 = F_7 ( V_4 , V_48 -> V_71 ) ;
if ( ( V_60 < 2 || V_60 > 4 ) && ! V_43 ) {
F_22 ( V_55 L_6 , V_60 ) ;
goto V_63;
}
#ifdef F_28
F_22 ( V_72 L_7 , V_60 ) ;
F_22 ( V_72 L_8 ,
F_7 ( V_4 , V_48 -> V_73 ) ) ;
#endif
V_2 -> V_74 = F_7 ( V_4 , V_48 -> V_54 ) ;
V_4 -> V_75 = F_7 ( V_4 , V_48 -> V_76 [ 0 ] ) ;
V_4 -> V_77 = F_7 ( V_4 , V_48 -> V_78 ) ;
V_60 = F_7 ( V_4 , V_48 -> V_73 ) ;
if ( ! F_29 ( V_2 , V_60 ) ) {
F_22 ( V_51 L_9 ) ;
goto V_63;
}
if ( F_30 ( V_2 , V_57 ) ) {
F_22 ( V_51 L_10 ) ;
goto V_63;
}
if ( F_31 ( V_2 ) ) {
F_22 ( V_51 L_11 ) ;
goto V_63;
}
V_58 = F_32 ( V_2 , V_79 ) ;
if ( F_33 ( V_58 ) ) {
V_59 = F_34 ( V_58 ) ;
goto V_63;
}
V_2 -> V_80 = F_35 ( V_58 ) ;
if ( ! V_2 -> V_80 ) {
F_22 ( V_51 L_12 ) ;
goto V_81;
}
return 0 ;
V_81:
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
V_63:
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 ) ;
return V_59 ;
}
static struct V_9 * F_36 ( struct V_82 * V_83 ,
int V_31 , const char * V_84 , void * V_32 )
{
return F_37 ( V_83 , V_31 , V_84 , V_32 , F_23 ) ;
}
static int T_4
F_38 ( void )
{
int V_85 ;
V_37 = F_39 ( L_13 ,
sizeof( struct V_35 ) , 0 ,
V_86 | V_87 , NULL ) ;
if ( ! V_37 )
return - V_50 ;
V_85 = F_40 ( & V_88 ) ;
if ( V_85 < 0 )
F_41 ( V_37 ) ;
return V_85 ;
}
static void T_5
F_42 ( void )
{
F_43 ( & V_88 ) ;
F_44 () ;
F_41 ( V_37 ) ;
}
