static inline int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) || V_2 -> V_4 . V_5 ;
}
static struct V_1 *
F_3 ( struct V_6 * V_7 , T_1 V_8 )
{
struct V_9 * V_10 ;
if ( V_7 -> V_11 )
return F_1 ( V_7 -> V_11 + V_8 ) ?
V_7 -> V_11 + V_8 : NULL ;
else if ( V_7 -> V_12 ) {
for ( V_10 = V_7 -> V_12 [ V_8 % V_7 -> V_13 ] ; V_10 ; V_10 = V_10 -> V_14 )
if ( V_10 -> V_8 == V_8 )
return & V_10 -> V_15 ;
}
return NULL ;
}
static int F_4 ( struct V_16 * V_17 , const struct V_18 * V_19 ,
struct V_20 * V_4 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_1 * V_10 ;
int V_8 = ( V_17 -> V_22 & V_7 -> V_23 ) >> V_7 -> V_24 ;
F_5 ( L_1 ,
V_17 , V_19 , V_4 , V_7 ) ;
V_10 = F_3 ( V_7 , V_8 ) ;
if ( ! V_10 ) {
if ( ! V_7 -> V_25 )
return - 1 ;
V_4 -> V_5 = F_6 ( F_7 ( V_19 -> V_26 -> V_27 ) , V_8 ) ;
V_4 -> V_28 = 0 ;
F_5 ( L_2 , V_4 -> V_5 ) ;
return 0 ;
}
* V_4 = V_10 -> V_4 ;
F_5 ( L_3 , V_4 -> V_5 ) ;
return F_8 ( V_17 , & V_10 -> V_3 , V_4 ) ;
}
static unsigned long F_9 ( struct V_18 * V_19 , T_2 V_27 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_1 * V_2 ;
F_5 ( L_4 , V_19 , V_27 ) ;
if ( V_7 -> V_11 && V_27 >= V_7 -> V_29 )
return 0 ;
V_2 = F_3 ( V_7 , V_27 ) ;
return V_2 && F_1 ( V_2 ) ? ( unsigned long ) V_2 : 0UL ;
}
static void F_10 ( struct V_18 * V_19 , unsigned long V_10 )
{
F_5 ( L_5 , V_19 , V_10 ) ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
F_5 ( L_6 , V_19 ) ;
V_7 = F_12 ( sizeof( struct V_6 ) , V_30 ) ;
if ( ! V_7 )
return - V_31 ;
V_7 -> V_23 = 0xffff ;
V_7 -> V_13 = V_32 ;
V_7 -> V_25 = 1 ;
V_19 -> V_21 = V_7 ;
return 0 ;
}
static int
F_13 ( struct V_18 * V_19 , unsigned long V_33 , int V_34 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
struct V_9 * V_10 = NULL ;
F_5 ( L_7 , V_19 , V_33 , V_7 , V_10 ) ;
if ( V_7 -> V_11 ) {
if ( ! V_2 -> V_4 . V_28 )
return - V_35 ;
} else {
int V_36 ;
struct V_9 * * V_37 = NULL ;
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ )
for ( V_37 = V_7 -> V_12 + V_36 ; * V_37 ; V_37 = & ( * V_37 ) -> V_14 )
if ( & ( * V_37 ) -> V_15 == V_2 )
goto V_38;
return - V_35 ;
V_38:
V_10 = * V_37 ;
if ( V_34 )
F_14 ( V_19 ) ;
* V_37 = V_10 -> V_14 ;
if ( V_34 )
F_15 ( V_19 ) ;
}
F_16 ( V_19 , & V_2 -> V_4 ) ;
F_17 ( V_19 , & V_2 -> V_3 ) ;
F_18 ( V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , unsigned long V_33 )
{
return F_13 ( V_19 , V_33 , 1 ) ;
}
static inline int
F_20 ( struct V_6 * V_7 )
{
return V_7 -> V_13 > ( V_7 -> V_23 >> V_7 -> V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_22 ( & V_2 -> V_3 , V_39 , V_40 ) ;
}
static int
F_23 ( struct V_41 * V_41 , struct V_18 * V_19 , unsigned long V_42 ,
T_2 V_27 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_43 * * V_44 ,
struct V_43 * V_45 , bool V_46 )
{
int V_47 , V_48 = 0 ;
struct V_1 V_49 , * V_50 = V_2 ;
struct V_1 V_51 ;
struct V_6 V_52 ;
struct V_9 * V_10 = NULL ;
struct V_53 V_54 ;
F_22 ( & V_54 , V_39 , V_40 ) ;
V_47 = F_24 ( V_41 , V_19 , V_44 , V_45 , & V_54 , V_46 ) ;
if ( V_47 < 0 )
return V_47 ;
memcpy ( & V_52 , V_7 , sizeof( V_52 ) ) ;
F_21 ( & V_49 ) ;
F_21 ( & V_51 ) ;
if ( V_50 )
V_51 . V_4 = V_2 -> V_4 ;
if ( V_44 [ V_55 ] )
V_52 . V_13 = F_25 ( V_44 [ V_55 ] ) ;
if ( V_44 [ V_56 ] )
V_52 . V_23 = F_26 ( V_44 [ V_56 ] ) ;
if ( V_44 [ V_57 ] )
V_52 . V_24 = F_25 ( V_44 [ V_57 ] ) ;
V_47 = - V_58 ;
if ( V_52 . V_11 ) {
if ( ! F_20 ( & V_52 ) ||
V_52 . V_13 > V_52 . V_29 )
goto V_59;
} else if ( V_52 . V_12 && V_52 . V_13 != V_52 . V_29 )
goto V_59;
V_47 = - V_60 ;
if ( V_44 [ V_61 ] )
V_52 . V_25 = F_25 ( V_44 [ V_61 ] ) ;
if ( ! V_52 . V_13 ) {
if ( ( V_52 . V_23 >> V_52 . V_24 ) < V_62 )
V_52 . V_13 = ( V_52 . V_23 >> V_52 . V_24 ) + 1 ;
else
V_52 . V_13 = V_32 ;
}
if ( ! V_52 . V_11 && ! V_52 . V_12 )
V_52 . V_29 = V_52 . V_13 ;
if ( V_52 . V_11 || F_20 ( & V_52 ) )
if ( V_27 >= V_52 . V_29 )
goto V_59;
V_47 = - V_31 ;
if ( ! V_52 . V_11 && ! V_52 . V_12 ) {
if ( F_20 ( & V_52 ) ) {
int V_36 ;
V_52 . V_11 = F_27 ( V_52 . V_13 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_52 . V_11 )
goto V_59;
for ( V_36 = 0 ; V_36 < V_52 . V_13 ; V_36 ++ )
F_22 ( & V_52 . V_11 [ V_36 ] . V_3 , V_39 ,
V_40 ) ;
V_48 = 1 ;
} else {
V_52 . V_12 = F_27 ( V_52 . V_13 , sizeof( V_10 ) , V_30 ) ;
if ( ! V_52 . V_12 )
goto V_59;
V_48 = 2 ;
}
}
if ( V_52 . V_11 )
V_2 = V_52 . V_11 + V_27 ;
else
V_2 = F_3 ( & V_52 , V_27 ) ? : & V_49 ;
if ( V_2 == & V_49 ) {
V_10 = F_12 ( sizeof( * V_10 ) , V_30 ) ;
if ( ! V_10 )
goto V_63;
}
if ( V_44 [ V_64 ] ) {
V_51 . V_4 . V_5 = F_25 ( V_44 [ V_64 ] ) ;
F_28 ( V_19 , & V_51 . V_4 , V_42 ) ;
}
if ( V_50 )
F_29 ( V_19 , & V_2 -> V_3 , & V_54 ) ;
else
F_29 ( V_19 , & V_51 . V_3 , & V_54 ) ;
F_14 ( V_19 ) ;
if ( V_50 && V_50 != V_2 )
F_21 ( V_50 ) ;
memcpy ( V_7 , & V_52 , sizeof( V_52 ) ) ;
V_2 -> V_4 = V_51 . V_4 ;
if ( V_2 == & V_49 ) {
struct V_9 * * V_65 ;
V_10 -> V_8 = V_27 ;
V_10 -> V_15 = V_49 ;
V_10 -> V_14 = NULL ;
for ( V_65 = V_7 -> V_12 + ( V_27 % V_7 -> V_13 ) ; * V_65 ; V_65 = & ( * V_65 ) -> V_14 )
;
* V_65 = V_10 ;
}
F_15 ( V_19 ) ;
return 0 ;
V_63:
if ( V_48 == 1 )
F_18 ( V_52 . V_11 ) ;
else if ( V_48 == 2 )
F_18 ( V_52 . V_12 ) ;
V_59:
F_17 ( V_19 , & V_54 ) ;
return V_47 ;
}
static int
F_30 ( struct V_41 * V_41 , struct V_16 * V_66 ,
struct V_18 * V_19 , unsigned long V_42 , T_2 V_27 ,
struct V_43 * * V_67 , unsigned long * V_33 , bool V_46 )
{
struct V_43 * V_68 = V_67 [ V_69 ] ;
struct V_43 * V_44 [ V_70 + 1 ] ;
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_1 * V_2 = (struct V_1 * ) * V_33 ;
int V_47 ;
F_5 ( L_8
L_9 ,
V_19 , V_27 , V_67 , V_33 , V_68 , V_7 , V_2 , V_33 ? * V_33 : 0L ) ;
if ( ! V_68 )
return 0 ;
V_47 = F_31 ( V_44 , V_70 , V_68 , V_71 ) ;
if ( V_47 < 0 )
return V_47 ;
return F_23 ( V_41 , V_19 , V_42 , V_27 , V_7 , V_2 , V_44 ,
V_67 [ V_72 ] , V_46 ) ;
}
static void F_32 ( struct V_18 * V_19 , struct V_73 * V_74 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_9 * V_10 , * V_14 ;
int V_36 ;
F_5 ( L_10 , V_19 , V_74 , V_7 ) ;
if ( V_7 -> V_11 ) {
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
if ( ! V_7 -> V_11 [ V_36 ] . V_4 . V_28 )
continue;
if ( V_74 -> V_75 >= V_74 -> V_76 ) {
if ( V_74 -> V_77 ( V_19 ,
( unsigned long ) ( V_7 -> V_11 + V_36 ) , V_74 )
< 0 ) {
V_74 -> V_78 = 1 ;
return;
}
}
V_74 -> V_75 ++ ;
}
}
if ( ! V_7 -> V_12 )
return;
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; V_10 ; V_10 = V_14 ) {
V_14 = V_10 -> V_14 ;
if ( V_74 -> V_75 >= V_74 -> V_76 ) {
if ( V_74 -> V_77 ( V_19 , ( unsigned long ) & V_10 -> V_15 ,
V_74 ) < 0 ) {
V_74 -> V_78 = 1 ;
return;
}
}
V_74 -> V_75 ++ ;
}
}
}
static int F_33 ( struct V_18 * V_19 ,
unsigned long V_33 , struct V_73 * V_74 )
{
return F_13 ( V_19 , V_33 , 0 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_73 V_74 ;
F_5 ( L_11 , V_19 , V_7 ) ;
V_74 . V_75 = 0 ;
V_74 . V_76 = 0 ;
V_74 . V_77 = & F_33 ;
F_32 ( V_19 , & V_74 ) ;
F_18 ( V_7 -> V_11 ) ;
F_18 ( V_7 -> V_12 ) ;
F_18 ( V_7 ) ;
V_19 -> V_21 = NULL ;
}
static int F_35 ( struct V_41 * V_41 , struct V_18 * V_19 , unsigned long V_79 ,
struct V_16 * V_17 , struct V_80 * V_81 )
{
struct V_6 * V_7 = V_19 -> V_21 ;
struct V_1 * V_2 = (struct V_1 * ) V_79 ;
unsigned char * V_82 = F_36 ( V_17 ) ;
struct V_43 * V_83 ;
F_5 ( L_12 ,
V_19 , V_79 , V_17 , V_81 , V_7 , V_2 , V_82 ) ;
F_5 ( L_13 , V_7 -> V_11 , V_7 -> V_12 ) ;
V_83 = F_37 ( V_17 , V_69 ) ;
if ( V_83 == NULL )
goto V_84;
if ( ! V_79 ) {
V_81 -> V_85 = ~ 0 ;
if ( F_38 ( V_17 , V_55 , V_7 -> V_13 ) ||
F_39 ( V_17 , V_56 , V_7 -> V_23 ) ||
F_38 ( V_17 , V_57 , V_7 -> V_24 ) ||
F_38 ( V_17 , V_61 , V_7 -> V_25 ) )
goto V_84;
F_40 ( V_17 , V_83 ) ;
} else {
if ( V_7 -> V_11 ) {
V_81 -> V_85 = V_2 - V_7 -> V_11 ;
} else {
struct V_9 * V_10 ;
int V_36 ;
V_81 -> V_85 = 0 ;
for ( V_36 = 0 ; ! V_81 -> V_85 && V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; ! V_81 -> V_85 && V_10 ;
V_10 = V_10 -> V_14 ) {
if ( & V_10 -> V_15 == V_2 )
V_81 -> V_85 = V_10 -> V_8 ;
}
}
}
F_5 ( L_14 , V_81 -> V_85 ) ;
if ( V_2 -> V_4 . V_28 &&
F_38 ( V_17 , V_64 , V_2 -> V_4 . V_5 ) )
goto V_84;
if ( F_41 ( V_17 , & V_2 -> V_3 ) < 0 )
goto V_84;
F_40 ( V_17 , V_83 ) ;
if ( F_42 ( V_17 , & V_2 -> V_3 ) < 0 )
goto V_84;
}
return V_17 -> V_86 ;
V_84:
F_43 ( V_17 , V_82 ) ;
return - 1 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_87 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_87 ) ;
}
