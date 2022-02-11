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
static int F_21 ( struct V_19 * V_20 , unsigned long V_37 , bool * V_38 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
struct V_12 T_2 * * V_39 ;
struct V_12 * V_10 = NULL ;
F_7 ( L_6 , V_20 , V_37 , V_7 ) ;
if ( V_7 -> V_9 ) {
if ( ! V_2 -> V_4 . V_29 )
return - V_40 ;
} else {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_14 ; V_41 ++ ) {
V_39 = V_7 -> V_11 + V_41 ;
for ( V_10 = F_12 ( * V_39 ) ; V_10 ;
V_39 = & V_10 -> V_15 , V_10 = F_12 ( * V_39 ) ) {
if ( & V_10 -> V_16 == V_2 )
goto V_42;
}
}
return - V_40 ;
V_42:
F_15 ( * V_39 , F_12 ( V_10 -> V_15 ) ) ;
}
F_22 ( V_20 , & V_2 -> V_4 ) ;
if ( V_10 )
F_23 ( & V_10 -> V_36 , F_19 ) ;
else
F_23 ( & V_2 -> V_36 , F_16 ) ;
* V_38 = false ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
unsigned long V_37 ,
struct V_43 * V_44 )
{
bool V_38 ;
return F_21 ( V_20 , V_37 , & V_38 ) ;
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
return F_28 ( & V_2 -> V_3 , V_45 , V_46 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_17 ( V_35 , struct V_6 , V_36 ) ;
F_20 ( V_7 -> V_9 ) ;
F_20 ( V_7 ) ;
}
static void F_30 ( struct V_6 * V_47 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_47 -> V_14 ; V_41 ++ )
F_18 ( & V_47 -> V_9 [ V_41 ] . V_3 ) ;
F_20 ( V_47 -> V_9 ) ;
}
static int F_31 ( struct V_6 * V_47 )
{
int V_41 , V_48 = 0 ;
V_47 -> V_9 = F_32 ( V_47 -> V_14 , sizeof( struct V_1 ) ,
V_31 ) ;
if ( ! V_47 -> V_9 )
return - V_32 ;
for ( V_41 = 0 ; V_41 < V_47 -> V_14 ; V_41 ++ ) {
V_48 = F_28 ( & V_47 -> V_9 [ V_41 ] . V_3 ,
V_45 , V_46 ) ;
if ( V_48 < 0 )
goto V_49;
}
return 0 ;
V_49:
F_30 ( V_47 ) ;
return V_48 ;
}
static int
F_33 ( struct V_50 * V_50 , struct V_19 * V_20 , unsigned long V_51 ,
T_3 V_28 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_52 * * V_53 ,
struct V_52 * V_54 , bool V_55 )
{
struct V_1 V_56 , * V_57 = V_2 ;
struct V_1 V_58 ;
struct V_6 * V_47 = NULL , * V_59 ;
struct V_12 * V_10 = NULL ;
int V_48 , V_60 = 0 ;
struct V_61 V_62 ;
V_48 = F_28 ( & V_62 , V_45 , V_46 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_34 ( V_50 , V_20 , V_53 , V_54 , & V_62 , V_55 ) ;
if ( V_48 < 0 )
goto V_49;
V_48 = - V_32 ;
V_47 = F_14 ( sizeof( * V_47 ) , V_31 ) ;
if ( ! V_47 )
goto V_49;
V_47 -> V_24 = V_7 -> V_24 ;
V_47 -> V_25 = V_7 -> V_25 ;
V_47 -> V_14 = V_7 -> V_14 ;
V_47 -> V_30 = V_7 -> V_30 ;
V_47 -> V_26 = V_7 -> V_26 ;
V_47 -> V_20 = V_20 ;
if ( V_7 -> V_9 ) {
int V_41 ;
if ( F_31 ( V_47 ) < 0 )
goto V_49;
for ( V_41 = 0 ; V_41 < V_47 -> V_14 ; V_41 ++ )
V_47 -> V_9 [ V_41 ] . V_4 = V_7 -> V_9 [ V_41 ] . V_4 ;
V_60 = 1 ;
}
V_47 -> V_11 = V_7 -> V_11 ;
V_48 = F_27 ( & V_56 ) ;
if ( V_48 < 0 )
goto V_63;
V_48 = F_27 ( & V_58 ) ;
if ( V_48 < 0 )
goto V_63;
if ( V_57 )
V_58 . V_4 = V_2 -> V_4 ;
if ( V_53 [ V_64 ] )
V_47 -> V_14 = F_35 ( V_53 [ V_64 ] ) ;
if ( V_53 [ V_65 ] )
V_47 -> V_24 = F_36 ( V_53 [ V_65 ] ) ;
if ( V_53 [ V_66 ] )
V_47 -> V_25 = F_35 ( V_53 [ V_66 ] ) ;
V_48 = - V_67 ;
if ( V_47 -> V_9 ) {
if ( ! F_26 ( V_47 ) ||
V_47 -> V_14 > V_47 -> V_30 )
goto V_68;
} else if ( V_47 -> V_11 && V_47 -> V_14 != V_47 -> V_30 ) {
goto V_68;
}
V_48 = - V_69 ;
if ( V_53 [ V_70 ] )
V_47 -> V_26 = F_35 ( V_53 [ V_70 ] ) ;
if ( ! V_47 -> V_14 ) {
if ( ( V_47 -> V_24 >> V_47 -> V_25 ) < V_71 )
V_47 -> V_14 = ( V_47 -> V_24 >> V_47 -> V_25 ) + 1 ;
else
V_47 -> V_14 = V_33 ;
}
if ( ! V_47 -> V_9 && ! V_47 -> V_11 )
V_47 -> V_30 = V_47 -> V_14 ;
if ( V_47 -> V_9 || F_26 ( V_47 ) )
if ( V_28 >= V_47 -> V_30 )
goto V_68;
V_48 = - V_32 ;
if ( ! V_47 -> V_9 && ! V_47 -> V_11 ) {
if ( F_26 ( V_47 ) ) {
if ( F_31 ( V_47 ) < 0 )
goto V_68;
V_60 = 1 ;
} else {
struct V_12 T_2 * * V_14 ;
V_14 = F_32 ( V_47 -> V_14 ,
sizeof( struct V_12 * ) ,
V_31 ) ;
if ( ! V_14 )
goto V_68;
V_47 -> V_11 = V_14 ;
V_60 = 2 ;
}
}
if ( V_47 -> V_9 )
V_2 = V_47 -> V_9 + V_28 ;
else
V_2 = F_3 ( V_47 , V_28 ) ? : & V_56 ;
if ( V_2 == & V_56 ) {
V_10 = F_14 ( sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 )
goto V_68;
V_10 -> V_8 = V_28 ;
V_10 -> V_15 = NULL ;
V_48 = F_27 ( & V_10 -> V_16 ) ;
if ( V_48 < 0 ) {
F_20 ( V_10 ) ;
goto V_68;
}
}
if ( V_53 [ V_72 ] ) {
V_58 . V_4 . V_5 = F_35 ( V_53 [ V_72 ] ) ;
F_37 ( V_20 , & V_58 . V_4 , V_51 ) ;
}
if ( V_57 )
F_38 ( V_20 , & V_2 -> V_3 , & V_62 ) ;
else
F_38 ( V_20 , & V_58 . V_3 , & V_62 ) ;
if ( V_57 && V_57 != V_2 ) {
V_48 = F_27 ( V_57 ) ;
if ( V_48 < 0 ) {
F_20 ( V_10 ) ;
goto V_68;
}
}
V_59 = V_7 ;
V_2 -> V_4 = V_58 . V_4 ;
F_15 ( V_20 -> V_22 , V_47 ) ;
if ( V_2 == & V_56 ) {
struct V_12 * V_73 ;
struct V_12 T_2 * * V_13 ;
F_38 ( V_20 , & V_10 -> V_16 . V_3 , & V_2 -> V_3 ) ;
V_13 = V_47 -> V_11 + ( V_28 % V_47 -> V_14 ) ;
for ( V_73 = F_12 ( * V_13 ) ;
V_73 ;
V_13 = & V_73 -> V_15 , V_73 = F_12 ( * V_13 ) )
;
F_15 ( * V_13 , V_10 ) ;
}
if ( V_59 )
F_23 ( & V_59 -> V_36 , F_29 ) ;
return 0 ;
V_68:
if ( V_60 == 1 )
F_30 ( V_47 ) ;
else if ( V_60 == 2 )
F_20 ( V_47 -> V_11 ) ;
V_63:
F_18 ( & V_58 . V_3 ) ;
F_18 ( & V_56 . V_3 ) ;
V_49:
F_20 ( V_47 ) ;
F_18 ( & V_62 ) ;
return V_48 ;
}
static int
F_39 ( struct V_50 * V_50 , struct V_17 * V_74 ,
struct V_19 * V_20 , unsigned long V_51 , T_3 V_28 ,
struct V_52 * * V_75 , unsigned long * V_37 , bool V_55 )
{
struct V_52 * V_76 = V_75 [ V_77 ] ;
struct V_52 * V_53 [ V_78 + 1 ] ;
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_37 ;
int V_48 ;
F_7 ( L_7
L_8 ,
V_20 , V_28 , V_75 , V_37 , V_76 , V_7 , V_2 , V_37 ? * V_37 : 0L ) ;
if ( ! V_76 )
return 0 ;
V_48 = F_40 ( V_53 , V_78 , V_76 , V_79 , NULL ) ;
if ( V_48 < 0 )
return V_48 ;
return F_33 ( V_50 , V_20 , V_51 , V_28 , V_7 , V_2 , V_53 ,
V_75 [ V_80 ] , V_55 ) ;
}
static void F_41 ( struct V_19 * V_20 , struct V_43 * V_44 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_12 * V_10 , * V_15 ;
int V_41 ;
F_7 ( L_9 , V_20 , V_44 , V_7 ) ;
if ( V_7 -> V_9 ) {
for ( V_41 = 0 ; V_41 < V_7 -> V_14 ; V_41 ++ ) {
if ( ! V_7 -> V_9 [ V_41 ] . V_4 . V_29 )
continue;
if ( V_44 -> V_81 >= V_44 -> V_82 ) {
if ( V_44 -> V_83 ( V_20 ,
( unsigned long ) ( V_7 -> V_9 + V_41 ) , V_44 )
< 0 ) {
V_44 -> V_84 = 1 ;
return;
}
}
V_44 -> V_81 ++ ;
}
}
if ( ! V_7 -> V_11 )
return;
for ( V_41 = 0 ; V_41 < V_7 -> V_14 ; V_41 ++ ) {
for ( V_10 = F_12 ( V_7 -> V_11 [ V_41 ] ) ; V_10 ; V_10 = V_15 ) {
V_15 = F_12 ( V_10 -> V_15 ) ;
if ( V_44 -> V_81 >= V_44 -> V_82 ) {
if ( V_44 -> V_83 ( V_20 , ( unsigned long ) & V_10 -> V_16 ,
V_44 ) < 0 ) {
V_44 -> V_84 = 1 ;
return;
}
}
V_44 -> V_81 ++ ;
}
}
}
static void F_42 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_43 V_44 ;
F_7 ( L_10 , V_20 , V_7 ) ;
V_44 . V_81 = 0 ;
V_44 . V_82 = 0 ;
V_44 . V_83 = F_24 ;
F_41 ( V_20 , & V_44 ) ;
F_23 ( & V_7 -> V_36 , F_25 ) ;
}
static int F_43 ( struct V_50 * V_50 , struct V_19 * V_20 , unsigned long V_85 ,
struct V_17 * V_18 , struct V_86 * V_87 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
struct V_52 * V_88 ;
F_7 ( L_11 ,
V_20 , V_85 , V_18 , V_87 , V_7 , V_2 ) ;
F_7 ( L_12 , V_7 -> V_9 , V_7 -> V_11 ) ;
V_88 = F_44 ( V_18 , V_77 ) ;
if ( V_88 == NULL )
goto V_89;
if ( ! V_85 ) {
V_87 -> V_90 = ~ 0 ;
if ( F_45 ( V_18 , V_64 , V_7 -> V_14 ) ||
F_46 ( V_18 , V_65 , V_7 -> V_24 ) ||
F_45 ( V_18 , V_66 , V_7 -> V_25 ) ||
F_45 ( V_18 , V_70 , V_7 -> V_26 ) )
goto V_89;
F_47 ( V_18 , V_88 ) ;
} else {
if ( V_7 -> V_9 ) {
V_87 -> V_90 = V_2 - V_7 -> V_9 ;
} else {
struct V_12 * V_10 ;
struct V_12 T_2 * * V_13 ;
int V_41 ;
V_87 -> V_90 = 0 ;
for ( V_41 = 0 ; ! V_87 -> V_90 && V_41 < V_7 -> V_14 ; V_41 ++ ) {
V_13 = & V_7 -> V_11 [ V_41 ] ;
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
F_45 ( V_18 , V_72 , V_2 -> V_4 . V_5 ) )
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
