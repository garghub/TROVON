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
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_10 ;
int V_8 = ( V_17 -> V_21 & V_7 -> V_22 ) >> V_7 -> V_23 ;
F_6 ( L_1 ,
V_17 , V_19 , V_4 , V_7 ) ;
V_10 = F_3 ( V_7 , V_8 ) ;
if ( ! V_10 ) {
if ( ! V_7 -> V_24 )
return - 1 ;
V_4 -> V_5 = F_7 ( F_8 ( V_19 -> V_25 -> V_26 ) , V_8 ) ;
V_4 -> V_27 = 0 ;
F_6 ( L_2 , V_4 -> V_5 ) ;
return 0 ;
}
* V_4 = V_10 -> V_4 ;
F_6 ( L_3 , V_4 -> V_5 ) ;
return F_9 ( V_17 , & V_10 -> V_3 , V_4 ) ;
}
static unsigned long F_10 ( struct V_18 * V_19 , T_2 V_26 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 ;
F_6 ( L_4 , V_19 , V_26 ) ;
if ( V_7 -> V_11 && V_26 >= V_7 -> V_28 )
return 0 ;
V_2 = F_3 ( V_7 , V_26 ) ;
return V_2 && F_1 ( V_2 ) ? ( unsigned long ) V_2 : 0UL ;
}
static void F_11 ( struct V_18 * V_19 , unsigned long V_10 )
{
F_6 ( L_5 , V_19 , V_10 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
F_6 ( L_6 , V_19 ) ;
V_7 = F_13 ( sizeof( struct V_6 ) , V_29 ) ;
if ( ! V_7 )
return - V_30 ;
V_7 -> V_22 = 0xffff ;
V_7 -> V_13 = V_31 ;
V_7 -> V_24 = 1 ;
V_19 -> V_32 = V_7 ;
return 0 ;
}
static int
F_14 ( struct V_18 * V_19 , unsigned long V_33 , int V_34 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
struct V_9 * V_10 = NULL ;
F_6 ( L_7 , V_19 , V_33 , V_7 , V_10 ) ;
if ( V_7 -> V_11 ) {
if ( ! V_2 -> V_4 . V_27 )
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
F_15 ( V_19 ) ;
* V_37 = V_10 -> V_14 ;
if ( V_34 )
F_16 ( V_19 ) ;
}
F_17 ( V_19 , & V_2 -> V_4 ) ;
F_18 ( V_19 , & V_2 -> V_3 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , unsigned long V_33 )
{
return F_14 ( V_19 , V_33 , 1 ) ;
}
static inline int
F_21 ( struct V_6 * V_7 )
{
return V_7 -> V_13 > ( V_7 -> V_22 >> V_7 -> V_23 ) ;
}
static int
F_22 ( struct V_18 * V_19 , unsigned long V_39 , T_2 V_26 ,
struct V_6 * V_7 , struct V_1 * V_2 ,
struct V_40 * * V_41 , struct V_40 * V_42 )
{
int V_43 , V_44 = 0 ;
struct V_1 V_45 , * V_46 = V_2 ;
struct V_1 V_47 ;
struct V_6 V_48 ;
struct V_9 * V_10 = NULL ;
struct V_49 V_50 ;
V_43 = F_23 ( V_19 , V_41 , V_42 , & V_50 , & V_51 ) ;
if ( V_43 < 0 )
return V_43 ;
memcpy ( & V_48 , V_7 , sizeof( V_48 ) ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
if ( V_46 )
memcpy ( & V_47 , V_2 , sizeof( V_47 ) ) ;
else
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( V_41 [ V_52 ] )
V_48 . V_13 = F_24 ( V_41 [ V_52 ] ) ;
if ( V_41 [ V_53 ] )
V_48 . V_22 = F_25 ( V_41 [ V_53 ] ) ;
if ( V_41 [ V_54 ] )
V_48 . V_23 = F_24 ( V_41 [ V_54 ] ) ;
V_43 = - V_55 ;
if ( V_48 . V_11 ) {
if ( ! F_21 ( & V_48 ) ||
V_48 . V_13 > V_48 . V_28 )
goto V_56;
} else if ( V_48 . V_12 && V_48 . V_13 != V_48 . V_28 )
goto V_56;
V_43 = - V_57 ;
if ( V_41 [ V_58 ] )
V_48 . V_24 = F_24 ( V_41 [ V_58 ] ) ;
if ( ! V_48 . V_13 ) {
if ( ( V_48 . V_22 >> V_48 . V_23 ) < V_59 )
V_48 . V_13 = ( V_48 . V_22 >> V_48 . V_23 ) + 1 ;
else
V_48 . V_13 = V_31 ;
}
if ( ! V_48 . V_11 && ! V_48 . V_12 )
V_48 . V_28 = V_48 . V_13 ;
if ( V_48 . V_11 || F_21 ( & V_48 ) )
if ( V_26 >= V_48 . V_28 )
goto V_56;
V_43 = - V_30 ;
if ( ! V_48 . V_11 && ! V_48 . V_12 ) {
if ( F_21 ( & V_48 ) ) {
V_48 . V_11 = F_26 ( V_48 . V_13 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_48 . V_11 )
goto V_56;
V_44 = 1 ;
} else {
V_48 . V_12 = F_26 ( V_48 . V_13 , sizeof( V_10 ) , V_29 ) ;
if ( ! V_48 . V_12 )
goto V_56;
V_44 = 2 ;
}
}
if ( V_48 . V_11 )
V_2 = V_48 . V_11 + V_26 ;
else
V_2 = F_3 ( & V_48 , V_26 ) ? : & V_45 ;
if ( V_2 == & V_45 ) {
V_10 = F_13 ( sizeof( * V_10 ) , V_29 ) ;
if ( ! V_10 )
goto V_60;
}
if ( V_41 [ V_61 ] ) {
V_47 . V_4 . V_5 = F_24 ( V_41 [ V_61 ] ) ;
F_27 ( V_19 , & V_47 . V_4 , V_39 ) ;
}
F_28 ( V_19 , & V_47 . V_3 , & V_50 ) ;
F_15 ( V_19 ) ;
if ( V_46 && V_46 != V_2 )
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
memcpy ( V_7 , & V_48 , sizeof( V_48 ) ) ;
memcpy ( V_2 , & V_47 , sizeof( V_47 ) ) ;
if ( V_2 == & V_45 ) {
struct V_9 * * V_62 ;
V_10 -> V_8 = V_26 ;
V_10 -> V_15 = V_45 ;
V_10 -> V_14 = NULL ;
for ( V_62 = V_7 -> V_12 + ( V_26 % V_7 -> V_13 ) ; * V_62 ; V_62 = & ( * V_62 ) -> V_14 )
;
* V_62 = V_10 ;
}
F_16 ( V_19 ) ;
return 0 ;
V_60:
if ( V_44 == 1 )
F_19 ( V_48 . V_11 ) ;
else if ( V_44 == 2 )
F_19 ( V_48 . V_12 ) ;
V_56:
F_18 ( V_19 , & V_50 ) ;
return V_43 ;
}
static int
F_29 ( struct V_16 * V_63 ,
struct V_18 * V_19 , unsigned long V_39 , T_2 V_26 ,
struct V_40 * * V_64 , unsigned long * V_33 )
{
struct V_40 * V_65 = V_64 [ V_66 ] ;
struct V_40 * V_41 [ V_67 + 1 ] ;
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_33 ;
int V_43 ;
F_6 ( L_8
L_9 ,
V_19 , V_26 , V_64 , V_33 , V_65 , V_7 , V_2 , V_33 ? * V_33 : 0L ) ;
if ( ! V_65 )
return 0 ;
V_43 = F_30 ( V_41 , V_67 , V_65 , V_68 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_22 ( V_19 , V_39 , V_26 , V_7 , V_2 , V_41 , V_64 [ V_69 ] ) ;
}
static void F_31 ( struct V_18 * V_19 , struct V_70 * V_71 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_9 * V_10 , * V_14 ;
int V_36 ;
F_6 ( L_10 , V_19 , V_71 , V_7 ) ;
if ( V_7 -> V_11 ) {
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
if ( ! V_7 -> V_11 [ V_36 ] . V_4 . V_27 )
continue;
if ( V_71 -> V_72 >= V_71 -> V_73 ) {
if ( V_71 -> V_74 ( V_19 ,
( unsigned long ) ( V_7 -> V_11 + V_36 ) , V_71 )
< 0 ) {
V_71 -> V_75 = 1 ;
return;
}
}
V_71 -> V_72 ++ ;
}
}
if ( ! V_7 -> V_12 )
return;
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; V_10 ; V_10 = V_14 ) {
V_14 = V_10 -> V_14 ;
if ( V_71 -> V_72 >= V_71 -> V_73 ) {
if ( V_71 -> V_74 ( V_19 , ( unsigned long ) & V_10 -> V_15 ,
V_71 ) < 0 ) {
V_71 -> V_75 = 1 ;
return;
}
}
V_71 -> V_72 ++ ;
}
}
}
static int F_32 ( struct V_18 * V_19 ,
unsigned long V_33 , struct V_70 * V_71 )
{
return F_14 ( V_19 , V_33 , 0 ) ;
}
static void F_33 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_70 V_71 ;
F_6 ( L_11 , V_19 , V_7 ) ;
V_71 . V_72 = 0 ;
V_71 . V_73 = 0 ;
V_71 . V_74 = & F_32 ;
F_31 ( V_19 , & V_71 ) ;
F_19 ( V_7 -> V_11 ) ;
F_19 ( V_7 -> V_12 ) ;
F_19 ( V_7 ) ;
V_19 -> V_32 = NULL ;
}
static int F_34 ( struct V_18 * V_19 , unsigned long V_76 ,
struct V_16 * V_17 , struct V_77 * V_78 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
unsigned char * V_79 = F_35 ( V_17 ) ;
struct V_40 * V_80 ;
F_6 ( L_12 ,
V_19 , V_76 , V_17 , V_78 , V_7 , V_2 , V_79 ) ;
F_6 ( L_13 , V_7 -> V_11 , V_7 -> V_12 ) ;
V_80 = F_36 ( V_17 , V_66 ) ;
if ( V_80 == NULL )
goto V_81;
if ( ! V_76 ) {
V_78 -> V_82 = ~ 0 ;
if ( F_37 ( V_17 , V_52 , V_7 -> V_13 ) ||
F_38 ( V_17 , V_53 , V_7 -> V_22 ) ||
F_37 ( V_17 , V_54 , V_7 -> V_23 ) ||
F_37 ( V_17 , V_58 , V_7 -> V_24 ) )
goto V_81;
F_39 ( V_17 , V_80 ) ;
} else {
if ( V_7 -> V_11 ) {
V_78 -> V_82 = V_2 - V_7 -> V_11 ;
} else {
struct V_9 * V_10 ;
int V_36 ;
V_78 -> V_82 = 0 ;
for ( V_36 = 0 ; ! V_78 -> V_82 && V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; ! V_78 -> V_82 && V_10 ;
V_10 = V_10 -> V_14 ) {
if ( & V_10 -> V_15 == V_2 )
V_78 -> V_82 = V_10 -> V_8 ;
}
}
}
F_6 ( L_14 , V_78 -> V_82 ) ;
if ( V_2 -> V_4 . V_27 &&
F_37 ( V_17 , V_61 , V_2 -> V_4 . V_5 ) )
goto V_81;
if ( F_40 ( V_17 , & V_2 -> V_3 , & V_51 ) < 0 )
goto V_81;
F_39 ( V_17 , V_80 ) ;
if ( F_41 ( V_17 , & V_2 -> V_3 , & V_51 ) < 0 )
goto V_81;
}
return V_17 -> V_83 ;
V_81:
F_42 ( V_17 , V_79 ) ;
return - 1 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_84 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_84 ) ;
}
