static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) || V_2 -> V_4 . V_5 ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 ,
T_1 V_8 )
{
if ( V_7 -> V_9 ) {
struct V_1 * V_10 = V_7 -> V_9 + V_8 ;
return F_1 ( V_10 ) ? V_10 : NULL ;
} else if ( V_7 -> V_11 ) {
struct V_12 T_2 * * V_13 ;
struct V_12 * V_10 ;
V_13 = & V_7 -> V_11 [ V_8 % V_7 -> V_14 ] ;
for ( V_10 = F_4 ( * V_13 ) ;
V_10 ;
V_13 = & V_10 -> V_15 , V_10 = F_4 ( * V_13 ) )
if ( V_10 -> V_8 == V_8 )
return & V_10 -> V_16 ;
}
return NULL ;
}
static int F_5 ( struct V_17 * V_18 , const struct V_19 * V_20 ,
struct V_21 * V_4 )
{
struct V_6 * V_7 = F_6 ( V_20 -> V_22 ) ;
struct V_1 * V_10 ;
int V_8 = ( V_18 -> V_23 & V_7 -> V_24 ) >> V_7 -> V_25 ;
F_7 ( L_1 ,
V_18 , V_20 , V_4 , V_7 ) ;
V_10 = F_3 ( V_7 , V_8 ) ;
if ( ! V_10 ) {
if ( ! V_7 -> V_26 )
return - 1 ;
V_4 -> V_5 = F_8 ( F_9 ( V_20 -> V_27 -> V_28 ) , V_8 ) ;
V_4 -> V_29 = 0 ;
F_7 ( L_2 , V_4 -> V_5 ) ;
return 0 ;
}
* V_4 = V_10 -> V_4 ;
F_7 ( L_3 , V_4 -> V_5 ) ;
return F_10 ( V_18 , & V_10 -> V_3 , V_4 ) ;
}
static unsigned long F_11 ( struct V_19 * V_20 , T_3 V_28 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 ;
F_7 ( L_4 , V_20 , V_28 ) ;
if ( V_7 -> V_9 && V_28 >= V_7 -> V_30 )
return 0 ;
V_2 = F_3 ( V_7 , V_28 ) ;
return V_2 && F_1 ( V_2 ) ? ( unsigned long ) V_2 : 0UL ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_6 * V_7 ;
F_7 ( L_5 , V_20 ) ;
V_7 = F_14 ( sizeof( struct V_6 ) , V_31 ) ;
if ( ! V_7 )
return - V_32 ;
V_7 -> V_24 = 0xffff ;
V_7 -> V_14 = V_33 ;
V_7 -> V_26 = 1 ;
F_15 ( V_20 -> V_22 , V_7 ) ;
return 0 ;
}
static void F_16 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_35 , struct V_1 , V_36 ) ;
F_18 ( & V_2 -> V_3 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_12 * V_10 = F_17 ( V_35 , struct V_12 ,
V_36 ) ;
F_18 ( & V_10 -> V_16 . V_3 ) ;
F_20 ( V_10 ) ;
}
static int F_21 ( struct V_19 * V_20 , unsigned long V_37 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_12 T_2 * * V_38 ;
struct V_12 * V_10 = NULL ;
F_7 ( L_6 , V_20 , V_37 , V_7 ) ;
if ( V_7 -> V_9 ) {
if ( ! V_2 -> V_4 . V_29 )
return - V_39 ;
} else {
int V_40 ;
for ( V_40 = 0 ; V_40 < V_7 -> V_14 ; V_40 ++ ) {
V_38 = V_7 -> V_11 + V_40 ;
for ( V_10 = F_12 ( * V_38 ) ; V_10 ;
V_38 = & V_10 -> V_15 , V_10 = F_12 ( * V_38 ) ) {
if ( & V_10 -> V_16 == V_2 )
goto V_41;
}
}
return - V_39 ;
V_41:
F_15 ( * V_38 , F_12 ( V_10 -> V_15 ) ) ;
}
F_22 ( V_20 , & V_2 -> V_4 ) ;
if ( V_10 )
F_23 ( & V_10 -> V_36 , F_19 ) ;
else
F_23 ( & V_2 -> V_36 , F_16 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
unsigned long V_37 ,
struct V_42 * V_43 )
{
return F_21 ( V_20 , V_37 ) ;
}
static void F_25 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_17 ( V_35 , struct V_6 , V_36 ) ;
F_20 ( V_7 -> V_9 ) ;
F_20 ( V_7 -> V_11 ) ;
F_20 ( V_7 ) ;
}
static inline int
F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_14 > ( V_7 -> V_24 >> V_7 -> V_25 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return F_28 ( & V_2 -> V_3 , V_44 , V_45 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_17 ( V_35 , struct V_6 , V_36 ) ;
F_20 ( V_7 -> V_9 ) ;
F_20 ( V_7 ) ;
}
static void F_30 ( struct V_6 * V_46 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_46 -> V_14 ; V_40 ++ )
F_18 ( & V_46 -> V_9 [ V_40 ] . V_3 ) ;
F_20 ( V_46 -> V_9 ) ;
}
static int F_31 ( struct V_6 * V_46 )
{
int V_40 , V_47 = 0 ;
V_46 -> V_9 = F_32 ( V_46 -> V_14 , sizeof( struct V_1 ) ,
V_31 ) ;
if ( ! V_46 -> V_9 )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_46 -> V_14 ; V_40 ++ ) {
V_47 = F_28 ( & V_46 -> V_9 [ V_40 ] . V_3 ,
V_44 , V_45 ) ;
if ( V_47 < 0 )
goto V_48;
}
return 0 ;
V_48:
F_30 ( V_46 ) ;
return V_47 ;
}
static int
F_33 ( struct V_49 * V_49 , struct V_19 * V_20 , unsigned long V_50 ,
T_3 V_28 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_51 * * V_52 ,
struct V_51 * V_53 , bool V_54 )
{
struct V_1 V_55 , * V_56 = V_2 ;
struct V_1 V_57 ;
struct V_6 * V_46 = NULL , * V_58 ;
struct V_12 * V_10 = NULL ;
int V_47 , V_59 = 0 ;
struct V_60 V_61 ;
V_47 = F_28 ( & V_61 , V_44 , V_45 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_34 ( V_49 , V_20 , V_52 , V_53 , & V_61 , V_54 ) ;
if ( V_47 < 0 )
goto V_48;
V_47 = - V_32 ;
V_46 = F_14 ( sizeof( * V_46 ) , V_31 ) ;
if ( ! V_46 )
goto V_48;
V_46 -> V_24 = V_7 -> V_24 ;
V_46 -> V_25 = V_7 -> V_25 ;
V_46 -> V_14 = V_7 -> V_14 ;
V_46 -> V_30 = V_7 -> V_30 ;
V_46 -> V_26 = V_7 -> V_26 ;
V_46 -> V_20 = V_20 ;
if ( V_7 -> V_9 ) {
int V_40 ;
if ( F_31 ( V_46 ) < 0 )
goto V_48;
for ( V_40 = 0 ; V_40 < V_46 -> V_14 ; V_40 ++ )
V_46 -> V_9 [ V_40 ] . V_4 = V_7 -> V_9 [ V_40 ] . V_4 ;
V_59 = 1 ;
}
V_46 -> V_11 = V_7 -> V_11 ;
V_47 = F_27 ( & V_55 ) ;
if ( V_47 < 0 )
goto V_62;
V_47 = F_27 ( & V_57 ) ;
if ( V_47 < 0 )
goto V_62;
if ( V_56 )
V_57 . V_4 = V_2 -> V_4 ;
if ( V_52 [ V_63 ] )
V_46 -> V_14 = F_35 ( V_52 [ V_63 ] ) ;
if ( V_52 [ V_64 ] )
V_46 -> V_24 = F_36 ( V_52 [ V_64 ] ) ;
if ( V_52 [ V_65 ] )
V_46 -> V_25 = F_35 ( V_52 [ V_65 ] ) ;
V_47 = - V_66 ;
if ( V_46 -> V_9 ) {
if ( ! F_26 ( V_46 ) ||
V_46 -> V_14 > V_46 -> V_30 )
goto V_67;
} else if ( V_46 -> V_11 && V_46 -> V_14 != V_46 -> V_30 ) {
goto V_67;
}
V_47 = - V_68 ;
if ( V_52 [ V_69 ] )
V_46 -> V_26 = F_35 ( V_52 [ V_69 ] ) ;
if ( ! V_46 -> V_14 ) {
if ( ( V_46 -> V_24 >> V_46 -> V_25 ) < V_70 )
V_46 -> V_14 = ( V_46 -> V_24 >> V_46 -> V_25 ) + 1 ;
else
V_46 -> V_14 = V_33 ;
}
if ( ! V_46 -> V_9 && ! V_46 -> V_11 )
V_46 -> V_30 = V_46 -> V_14 ;
if ( V_46 -> V_9 || F_26 ( V_46 ) )
if ( V_28 >= V_46 -> V_30 )
goto V_67;
V_47 = - V_32 ;
if ( ! V_46 -> V_9 && ! V_46 -> V_11 ) {
if ( F_26 ( V_46 ) ) {
if ( F_31 ( V_46 ) < 0 )
goto V_67;
V_59 = 1 ;
} else {
struct V_12 T_2 * * V_14 ;
V_14 = F_32 ( V_46 -> V_14 ,
sizeof( struct V_12 * ) ,
V_31 ) ;
if ( ! V_14 )
goto V_67;
V_46 -> V_11 = V_14 ;
V_59 = 2 ;
}
}
if ( V_46 -> V_9 )
V_2 = V_46 -> V_9 + V_28 ;
else
V_2 = F_3 ( V_46 , V_28 ) ? : & V_55 ;
if ( V_2 == & V_55 ) {
V_10 = F_14 ( sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 )
goto V_67;
V_10 -> V_8 = V_28 ;
V_10 -> V_15 = NULL ;
V_47 = F_27 ( & V_10 -> V_16 ) ;
if ( V_47 < 0 ) {
F_20 ( V_10 ) ;
goto V_67;
}
}
if ( V_52 [ V_71 ] ) {
V_57 . V_4 . V_5 = F_35 ( V_52 [ V_71 ] ) ;
F_37 ( V_20 , & V_57 . V_4 , V_50 ) ;
}
if ( V_56 )
F_38 ( V_20 , & V_2 -> V_3 , & V_61 ) ;
else
F_38 ( V_20 , & V_57 . V_3 , & V_61 ) ;
if ( V_56 && V_56 != V_2 ) {
V_47 = F_27 ( V_56 ) ;
if ( V_47 < 0 ) {
F_20 ( V_10 ) ;
goto V_67;
}
}
V_58 = V_7 ;
V_2 -> V_4 = V_57 . V_4 ;
F_15 ( V_20 -> V_22 , V_46 ) ;
if ( V_2 == & V_55 ) {
struct V_12 * V_72 ;
struct V_12 T_2 * * V_13 ;
F_38 ( V_20 , & V_10 -> V_16 . V_3 , & V_2 -> V_3 ) ;
V_13 = V_46 -> V_11 + ( V_28 % V_46 -> V_14 ) ;
for ( V_72 = F_12 ( * V_13 ) ;
V_72 ;
V_13 = & V_72 -> V_15 , V_72 = F_12 ( * V_13 ) )
;
F_15 ( * V_13 , V_10 ) ;
}
if ( V_58 )
F_23 ( & V_58 -> V_36 , F_29 ) ;
return 0 ;
V_67:
if ( V_59 == 1 )
F_30 ( V_46 ) ;
else if ( V_59 == 2 )
F_20 ( V_46 -> V_11 ) ;
V_62:
F_18 ( & V_57 . V_3 ) ;
F_18 ( & V_55 . V_3 ) ;
V_48:
F_20 ( V_46 ) ;
F_18 ( & V_61 ) ;
return V_47 ;
}
static int
F_39 ( struct V_49 * V_49 , struct V_17 * V_73 ,
struct V_19 * V_20 , unsigned long V_50 , T_3 V_28 ,
struct V_51 * * V_74 , unsigned long * V_37 , bool V_54 )
{
struct V_51 * V_75 = V_74 [ V_76 ] ;
struct V_51 * V_52 [ V_77 + 1 ] ;
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_37 ;
int V_47 ;
F_7 ( L_7
L_8 ,
V_20 , V_28 , V_74 , V_37 , V_75 , V_7 , V_2 , V_37 ? * V_37 : 0L ) ;
if ( ! V_75 )
return 0 ;
V_47 = F_40 ( V_52 , V_77 , V_75 , V_78 ) ;
if ( V_47 < 0 )
return V_47 ;
return F_33 ( V_49 , V_20 , V_50 , V_28 , V_7 , V_2 , V_52 ,
V_74 [ V_79 ] , V_54 ) ;
}
static void F_41 ( struct V_19 * V_20 , struct V_42 * V_43 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_12 * V_10 , * V_15 ;
int V_40 ;
F_7 ( L_9 , V_20 , V_43 , V_7 ) ;
if ( V_7 -> V_9 ) {
for ( V_40 = 0 ; V_40 < V_7 -> V_14 ; V_40 ++ ) {
if ( ! V_7 -> V_9 [ V_40 ] . V_4 . V_29 )
continue;
if ( V_43 -> V_80 >= V_43 -> V_81 ) {
if ( V_43 -> V_82 ( V_20 ,
( unsigned long ) ( V_7 -> V_9 + V_40 ) , V_43 )
< 0 ) {
V_43 -> V_83 = 1 ;
return;
}
}
V_43 -> V_80 ++ ;
}
}
if ( ! V_7 -> V_11 )
return;
for ( V_40 = 0 ; V_40 < V_7 -> V_14 ; V_40 ++ ) {
for ( V_10 = F_12 ( V_7 -> V_11 [ V_40 ] ) ; V_10 ; V_10 = V_15 ) {
V_15 = F_12 ( V_10 -> V_15 ) ;
if ( V_43 -> V_80 >= V_43 -> V_81 ) {
if ( V_43 -> V_82 ( V_20 , ( unsigned long ) & V_10 -> V_16 ,
V_43 ) < 0 ) {
V_43 -> V_83 = 1 ;
return;
}
}
V_43 -> V_80 ++ ;
}
}
}
static bool F_42 ( struct V_19 * V_20 , bool V_84 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_42 V_43 ;
if ( ! V_84 )
return false ;
F_7 ( L_10 , V_20 , V_7 ) ;
V_43 . V_80 = 0 ;
V_43 . V_81 = 0 ;
V_43 . V_82 = F_24 ;
F_41 ( V_20 , & V_43 ) ;
F_23 ( & V_7 -> V_36 , F_25 ) ;
return true ;
}
static int F_43 ( struct V_49 * V_49 , struct V_19 * V_20 , unsigned long V_85 ,
struct V_17 * V_18 , struct V_86 * V_87 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
struct V_51 * V_88 ;
F_7 ( L_11 ,
V_20 , V_85 , V_18 , V_87 , V_7 , V_2 ) ;
F_7 ( L_12 , V_7 -> V_9 , V_7 -> V_11 ) ;
V_88 = F_44 ( V_18 , V_76 ) ;
if ( V_88 == NULL )
goto V_89;
if ( ! V_85 ) {
V_87 -> V_90 = ~ 0 ;
if ( F_45 ( V_18 , V_63 , V_7 -> V_14 ) ||
F_46 ( V_18 , V_64 , V_7 -> V_24 ) ||
F_45 ( V_18 , V_65 , V_7 -> V_25 ) ||
F_45 ( V_18 , V_69 , V_7 -> V_26 ) )
goto V_89;
F_47 ( V_18 , V_88 ) ;
} else {
if ( V_7 -> V_9 ) {
V_87 -> V_90 = V_2 - V_7 -> V_9 ;
} else {
struct V_12 * V_10 ;
struct V_12 T_2 * * V_13 ;
int V_40 ;
V_87 -> V_90 = 0 ;
for ( V_40 = 0 ; ! V_87 -> V_90 && V_40 < V_7 -> V_14 ; V_40 ++ ) {
V_13 = & V_7 -> V_11 [ V_40 ] ;
for ( V_10 = F_12 ( * V_13 ) ;
! V_87 -> V_90 && V_10 ;
V_13 = & V_10 -> V_15 , V_10 = F_12 ( * V_13 ) ) {
if ( & V_10 -> V_16 == V_2 )
V_87 -> V_90 = V_10 -> V_8 ;
}
}
}
F_7 ( L_13 , V_87 -> V_90 ) ;
if ( V_2 -> V_4 . V_29 &&
F_45 ( V_18 , V_71 , V_2 -> V_4 . V_5 ) )
goto V_89;
if ( F_48 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_89;
F_47 ( V_18 , V_88 ) ;
if ( F_49 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_89;
}
return V_18 -> V_91 ;
V_89:
F_50 ( V_18 , V_88 ) ;
return - 1 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_92 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_92 ) ;
}
