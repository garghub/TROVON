static inline int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) || V_2 -> V_4 . V_5 ;
}
static struct V_1 *
F_3 ( struct V_6 * V_7 , T_1 V_8 )
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
struct V_12 * V_10 = F_17 ( V_35 , struct V_12 , V_36 ) ;
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
static void F_27 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_28 ( & V_2 -> V_3 , V_44 , V_45 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_17 ( V_35 , struct V_6 , V_36 ) ;
F_20 ( V_7 -> V_9 ) ;
F_20 ( V_7 ) ;
}
static int
F_30 ( struct V_46 * V_46 , struct V_19 * V_20 , unsigned long V_47 ,
T_3 V_28 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_48 * * V_49 ,
struct V_48 * V_50 , bool V_51 )
{
int V_52 , V_53 = 0 ;
struct V_1 V_54 , * V_55 = V_2 ;
struct V_1 V_56 ;
struct V_6 * V_57 , * V_58 ;
struct V_12 * V_10 = NULL ;
struct V_59 V_60 ;
F_28 ( & V_60 , V_44 , V_45 ) ;
V_52 = F_31 ( V_46 , V_20 , V_49 , V_50 , & V_60 , V_51 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = - V_32 ;
V_57 = F_14 ( sizeof( * V_57 ) , V_31 ) ;
if ( ! V_57 )
goto V_61;
V_57 -> V_24 = V_7 -> V_24 ;
V_57 -> V_25 = V_7 -> V_25 ;
V_57 -> V_14 = V_7 -> V_14 ;
V_57 -> V_30 = V_7 -> V_30 ;
V_57 -> V_26 = V_7 -> V_26 ;
V_57 -> V_20 = V_20 ;
if ( V_7 -> V_9 ) {
int V_40 ;
V_57 -> V_9 = F_32 ( V_7 -> V_9 ,
sizeof( * V_2 ) * V_57 -> V_14 , V_31 ) ;
if ( ! V_57 -> V_9 )
goto V_61;
for ( V_40 = 0 ; V_40 < V_57 -> V_14 ; V_40 ++ )
F_28 ( & V_57 -> V_9 [ V_40 ] . V_3 ,
V_44 , V_45 ) ;
V_53 = 1 ;
}
V_57 -> V_11 = V_7 -> V_11 ;
F_27 ( & V_54 ) ;
F_27 ( & V_56 ) ;
if ( V_55 )
V_56 . V_4 = V_2 -> V_4 ;
if ( V_49 [ V_62 ] )
V_57 -> V_14 = F_33 ( V_49 [ V_62 ] ) ;
if ( V_49 [ V_63 ] )
V_57 -> V_24 = F_34 ( V_49 [ V_63 ] ) ;
if ( V_49 [ V_64 ] )
V_57 -> V_25 = F_33 ( V_49 [ V_64 ] ) ;
V_52 = - V_65 ;
if ( V_57 -> V_9 ) {
if ( ! F_26 ( V_57 ) ||
V_57 -> V_14 > V_57 -> V_30 )
goto V_66;
} else if ( V_57 -> V_11 && V_57 -> V_14 != V_57 -> V_30 ) {
goto V_66;
}
V_52 = - V_67 ;
if ( V_49 [ V_68 ] )
V_57 -> V_26 = F_33 ( V_49 [ V_68 ] ) ;
if ( ! V_57 -> V_14 ) {
if ( ( V_57 -> V_24 >> V_57 -> V_25 ) < V_69 )
V_57 -> V_14 = ( V_57 -> V_24 >> V_57 -> V_25 ) + 1 ;
else
V_57 -> V_14 = V_33 ;
}
if ( ! V_57 -> V_9 && ! V_57 -> V_11 )
V_57 -> V_30 = V_57 -> V_14 ;
if ( V_57 -> V_9 || F_26 ( V_57 ) )
if ( V_28 >= V_57 -> V_30 )
goto V_66;
V_52 = - V_32 ;
if ( ! V_57 -> V_9 && ! V_57 -> V_11 ) {
if ( F_26 ( V_57 ) ) {
int V_40 ;
V_57 -> V_9 = F_35 ( V_57 -> V_14 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_57 -> V_9 )
goto V_66;
for ( V_40 = 0 ; V_40 < V_57 -> V_14 ; V_40 ++ )
F_28 ( & V_57 -> V_9 [ V_40 ] . V_3 ,
V_44 ,
V_45 ) ;
V_53 = 1 ;
} else {
struct V_12 T_2 * * V_14 ;
V_14 = F_35 ( V_57 -> V_14 ,
sizeof( struct V_12 * ) ,
V_31 ) ;
if ( ! V_14 )
goto V_66;
V_57 -> V_11 = V_14 ;
V_53 = 2 ;
}
}
if ( V_57 -> V_9 )
V_2 = V_57 -> V_9 + V_28 ;
else
V_2 = F_3 ( V_57 , V_28 ) ? : & V_54 ;
if ( V_2 == & V_54 ) {
V_10 = F_14 ( sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 )
goto V_66;
V_10 -> V_8 = V_28 ;
F_27 ( & V_10 -> V_16 ) ;
V_10 -> V_15 = NULL ;
}
if ( V_49 [ V_70 ] ) {
V_56 . V_4 . V_5 = F_33 ( V_49 [ V_70 ] ) ;
F_36 ( V_20 , & V_56 . V_4 , V_47 ) ;
}
if ( V_55 )
F_37 ( V_20 , & V_2 -> V_3 , & V_60 ) ;
else
F_37 ( V_20 , & V_56 . V_3 , & V_60 ) ;
if ( V_55 && V_55 != V_2 )
F_27 ( V_55 ) ;
V_58 = V_7 ;
V_2 -> V_4 = V_56 . V_4 ;
F_15 ( V_20 -> V_22 , V_57 ) ;
if ( V_2 == & V_54 ) {
struct V_12 * V_71 ;
struct V_12 T_2 * * V_13 ;
F_37 ( V_20 , & V_10 -> V_16 . V_3 , & V_2 -> V_3 ) ;
V_13 = V_57 -> V_11 + ( V_28 % V_57 -> V_14 ) ;
for ( V_71 = F_12 ( * V_13 ) ;
V_71 ;
V_13 = & V_71 -> V_15 , V_71 = F_12 ( * V_13 ) )
;
F_15 ( * V_13 , V_10 ) ;
}
if ( V_58 )
F_23 ( & V_58 -> V_36 , F_29 ) ;
return 0 ;
V_66:
if ( V_53 == 1 )
F_20 ( V_57 -> V_9 ) ;
else if ( V_53 == 2 )
F_20 ( V_57 -> V_11 ) ;
V_61:
F_20 ( V_57 ) ;
F_18 ( & V_60 ) ;
return V_52 ;
}
static int
F_38 ( struct V_46 * V_46 , struct V_17 * V_72 ,
struct V_19 * V_20 , unsigned long V_47 , T_3 V_28 ,
struct V_48 * * V_73 , unsigned long * V_37 , bool V_51 )
{
struct V_48 * V_74 = V_73 [ V_75 ] ;
struct V_48 * V_49 [ V_76 + 1 ] ;
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_37 ;
int V_52 ;
F_7 ( L_7
L_8 ,
V_20 , V_28 , V_73 , V_37 , V_74 , V_7 , V_2 , V_37 ? * V_37 : 0L ) ;
if ( ! V_74 )
return 0 ;
V_52 = F_39 ( V_49 , V_76 , V_74 , V_77 ) ;
if ( V_52 < 0 )
return V_52 ;
return F_30 ( V_46 , V_20 , V_47 , V_28 , V_7 , V_2 , V_49 ,
V_73 [ V_78 ] , V_51 ) ;
}
static void F_40 ( struct V_19 * V_20 , struct V_42 * V_43 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_12 * V_10 , * V_15 ;
int V_40 ;
F_7 ( L_9 , V_20 , V_43 , V_7 ) ;
if ( V_7 -> V_9 ) {
for ( V_40 = 0 ; V_40 < V_7 -> V_14 ; V_40 ++ ) {
if ( ! V_7 -> V_9 [ V_40 ] . V_4 . V_29 )
continue;
if ( V_43 -> V_79 >= V_43 -> V_80 ) {
if ( V_43 -> V_81 ( V_20 ,
( unsigned long ) ( V_7 -> V_9 + V_40 ) , V_43 )
< 0 ) {
V_43 -> V_82 = 1 ;
return;
}
}
V_43 -> V_79 ++ ;
}
}
if ( ! V_7 -> V_11 )
return;
for ( V_40 = 0 ; V_40 < V_7 -> V_14 ; V_40 ++ ) {
for ( V_10 = F_12 ( V_7 -> V_11 [ V_40 ] ) ; V_10 ; V_10 = V_15 ) {
V_15 = F_12 ( V_10 -> V_15 ) ;
if ( V_43 -> V_79 >= V_43 -> V_80 ) {
if ( V_43 -> V_81 ( V_20 , ( unsigned long ) & V_10 -> V_16 ,
V_43 ) < 0 ) {
V_43 -> V_82 = 1 ;
return;
}
}
V_43 -> V_79 ++ ;
}
}
}
static bool F_41 ( struct V_19 * V_20 , bool V_83 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_42 V_43 ;
if ( ! V_83 )
return false ;
F_7 ( L_10 , V_20 , V_7 ) ;
V_43 . V_79 = 0 ;
V_43 . V_80 = 0 ;
V_43 . V_81 = F_24 ;
F_40 ( V_20 , & V_43 ) ;
F_42 ( V_20 -> V_22 , NULL ) ;
F_23 ( & V_7 -> V_36 , F_25 ) ;
return true ;
}
static int F_43 ( struct V_46 * V_46 , struct V_19 * V_20 , unsigned long V_84 ,
struct V_17 * V_18 , struct V_85 * V_86 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
struct V_48 * V_87 ;
F_7 ( L_11 ,
V_20 , V_84 , V_18 , V_86 , V_7 , V_2 ) ;
F_7 ( L_12 , V_7 -> V_9 , V_7 -> V_11 ) ;
V_87 = F_44 ( V_18 , V_75 ) ;
if ( V_87 == NULL )
goto V_88;
if ( ! V_84 ) {
V_86 -> V_89 = ~ 0 ;
if ( F_45 ( V_18 , V_62 , V_7 -> V_14 ) ||
F_46 ( V_18 , V_63 , V_7 -> V_24 ) ||
F_45 ( V_18 , V_64 , V_7 -> V_25 ) ||
F_45 ( V_18 , V_68 , V_7 -> V_26 ) )
goto V_88;
F_47 ( V_18 , V_87 ) ;
} else {
if ( V_7 -> V_9 ) {
V_86 -> V_89 = V_2 - V_7 -> V_9 ;
} else {
struct V_12 * V_10 ;
struct V_12 T_2 * * V_13 ;
int V_40 ;
V_86 -> V_89 = 0 ;
for ( V_40 = 0 ; ! V_86 -> V_89 && V_40 < V_7 -> V_14 ; V_40 ++ ) {
V_13 = & V_7 -> V_11 [ V_40 ] ;
for ( V_10 = F_12 ( * V_13 ) ;
! V_86 -> V_89 && V_10 ;
V_13 = & V_10 -> V_15 , V_10 = F_12 ( * V_13 ) ) {
if ( & V_10 -> V_16 == V_2 )
V_86 -> V_89 = V_10 -> V_8 ;
}
}
}
F_7 ( L_13 , V_86 -> V_89 ) ;
if ( V_2 -> V_4 . V_29 &&
F_45 ( V_18 , V_70 , V_2 -> V_4 . V_5 ) )
goto V_88;
if ( F_48 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_88;
F_47 ( V_18 , V_87 ) ;
if ( F_49 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_88;
}
return V_18 -> V_90 ;
V_88:
F_50 ( V_18 , V_87 ) ;
return - 1 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_91 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_91 ) ;
}
