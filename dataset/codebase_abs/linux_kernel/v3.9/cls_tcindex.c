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
F_22 ( struct V_39 * V_39 , struct V_18 * V_19 , unsigned long V_40 ,
T_2 V_26 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_41 * * V_42 ,
struct V_41 * V_43 )
{
int V_44 , V_45 = 0 ;
struct V_1 V_46 , * V_47 = V_2 ;
struct V_1 V_48 ;
struct V_6 V_49 ;
struct V_9 * V_10 = NULL ;
struct V_50 V_51 ;
V_44 = F_23 ( V_39 , V_19 , V_42 , V_43 , & V_51 , & V_52 ) ;
if ( V_44 < 0 )
return V_44 ;
memcpy ( & V_49 , V_7 , sizeof( V_49 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( V_47 )
memcpy ( & V_48 , V_2 , sizeof( V_48 ) ) ;
else
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( V_42 [ V_53 ] )
V_49 . V_13 = F_24 ( V_42 [ V_53 ] ) ;
if ( V_42 [ V_54 ] )
V_49 . V_22 = F_25 ( V_42 [ V_54 ] ) ;
if ( V_42 [ V_55 ] )
V_49 . V_23 = F_24 ( V_42 [ V_55 ] ) ;
V_44 = - V_56 ;
if ( V_49 . V_11 ) {
if ( ! F_21 ( & V_49 ) ||
V_49 . V_13 > V_49 . V_28 )
goto V_57;
} else if ( V_49 . V_12 && V_49 . V_13 != V_49 . V_28 )
goto V_57;
V_44 = - V_58 ;
if ( V_42 [ V_59 ] )
V_49 . V_24 = F_24 ( V_42 [ V_59 ] ) ;
if ( ! V_49 . V_13 ) {
if ( ( V_49 . V_22 >> V_49 . V_23 ) < V_60 )
V_49 . V_13 = ( V_49 . V_22 >> V_49 . V_23 ) + 1 ;
else
V_49 . V_13 = V_31 ;
}
if ( ! V_49 . V_11 && ! V_49 . V_12 )
V_49 . V_28 = V_49 . V_13 ;
if ( V_49 . V_11 || F_21 ( & V_49 ) )
if ( V_26 >= V_49 . V_28 )
goto V_57;
V_44 = - V_30 ;
if ( ! V_49 . V_11 && ! V_49 . V_12 ) {
if ( F_21 ( & V_49 ) ) {
V_49 . V_11 = F_26 ( V_49 . V_13 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_49 . V_11 )
goto V_57;
V_45 = 1 ;
} else {
V_49 . V_12 = F_26 ( V_49 . V_13 , sizeof( V_10 ) , V_29 ) ;
if ( ! V_49 . V_12 )
goto V_57;
V_45 = 2 ;
}
}
if ( V_49 . V_11 )
V_2 = V_49 . V_11 + V_26 ;
else
V_2 = F_3 ( & V_49 , V_26 ) ? : & V_46 ;
if ( V_2 == & V_46 ) {
V_10 = F_13 ( sizeof( * V_10 ) , V_29 ) ;
if ( ! V_10 )
goto V_61;
}
if ( V_42 [ V_62 ] ) {
V_48 . V_4 . V_5 = F_24 ( V_42 [ V_62 ] ) ;
F_27 ( V_19 , & V_48 . V_4 , V_40 ) ;
}
F_28 ( V_19 , & V_48 . V_3 , & V_51 ) ;
F_15 ( V_19 ) ;
if ( V_47 && V_47 != V_2 )
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
memcpy ( V_7 , & V_49 , sizeof( V_49 ) ) ;
memcpy ( V_2 , & V_48 , sizeof( V_48 ) ) ;
if ( V_2 == & V_46 ) {
struct V_9 * * V_63 ;
V_10 -> V_8 = V_26 ;
V_10 -> V_15 = V_46 ;
V_10 -> V_14 = NULL ;
for ( V_63 = V_7 -> V_12 + ( V_26 % V_7 -> V_13 ) ; * V_63 ; V_63 = & ( * V_63 ) -> V_14 )
;
* V_63 = V_10 ;
}
F_16 ( V_19 ) ;
return 0 ;
V_61:
if ( V_45 == 1 )
F_19 ( V_49 . V_11 ) ;
else if ( V_45 == 2 )
F_19 ( V_49 . V_12 ) ;
V_57:
F_18 ( V_19 , & V_51 ) ;
return V_44 ;
}
static int
F_29 ( struct V_39 * V_39 , struct V_16 * V_64 ,
struct V_18 * V_19 , unsigned long V_40 , T_2 V_26 ,
struct V_41 * * V_65 , unsigned long * V_33 )
{
struct V_41 * V_66 = V_65 [ V_67 ] ;
struct V_41 * V_42 [ V_68 + 1 ] ;
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 = (struct V_1 * ) * V_33 ;
int V_44 ;
F_6 ( L_8
L_9 ,
V_19 , V_26 , V_65 , V_33 , V_66 , V_7 , V_2 , V_33 ? * V_33 : 0L ) ;
if ( ! V_66 )
return 0 ;
V_44 = F_30 ( V_42 , V_68 , V_66 , V_69 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_22 ( V_39 , V_19 , V_40 , V_26 , V_7 , V_2 , V_42 ,
V_65 [ V_70 ] ) ;
}
static void F_31 ( struct V_18 * V_19 , struct V_71 * V_72 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_9 * V_10 , * V_14 ;
int V_36 ;
F_6 ( L_10 , V_19 , V_72 , V_7 ) ;
if ( V_7 -> V_11 ) {
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
if ( ! V_7 -> V_11 [ V_36 ] . V_4 . V_27 )
continue;
if ( V_72 -> V_73 >= V_72 -> V_74 ) {
if ( V_72 -> V_75 ( V_19 ,
( unsigned long ) ( V_7 -> V_11 + V_36 ) , V_72 )
< 0 ) {
V_72 -> V_76 = 1 ;
return;
}
}
V_72 -> V_73 ++ ;
}
}
if ( ! V_7 -> V_12 )
return;
for ( V_36 = 0 ; V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; V_10 ; V_10 = V_14 ) {
V_14 = V_10 -> V_14 ;
if ( V_72 -> V_73 >= V_72 -> V_74 ) {
if ( V_72 -> V_75 ( V_19 , ( unsigned long ) & V_10 -> V_15 ,
V_72 ) < 0 ) {
V_72 -> V_76 = 1 ;
return;
}
}
V_72 -> V_73 ++ ;
}
}
}
static int F_32 ( struct V_18 * V_19 ,
unsigned long V_33 , struct V_71 * V_72 )
{
return F_14 ( V_19 , V_33 , 0 ) ;
}
static void F_33 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_71 V_72 ;
F_6 ( L_11 , V_19 , V_7 ) ;
V_72 . V_73 = 0 ;
V_72 . V_74 = 0 ;
V_72 . V_75 = & F_32 ;
F_31 ( V_19 , & V_72 ) ;
F_19 ( V_7 -> V_11 ) ;
F_19 ( V_7 -> V_12 ) ;
F_19 ( V_7 ) ;
V_19 -> V_32 = NULL ;
}
static int F_34 ( struct V_18 * V_19 , unsigned long V_77 ,
struct V_16 * V_17 , struct V_78 * V_79 )
{
struct V_6 * V_7 = F_5 ( V_19 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_77 ;
unsigned char * V_80 = F_35 ( V_17 ) ;
struct V_41 * V_81 ;
F_6 ( L_12 ,
V_19 , V_77 , V_17 , V_79 , V_7 , V_2 , V_80 ) ;
F_6 ( L_13 , V_7 -> V_11 , V_7 -> V_12 ) ;
V_81 = F_36 ( V_17 , V_67 ) ;
if ( V_81 == NULL )
goto V_82;
if ( ! V_77 ) {
V_79 -> V_83 = ~ 0 ;
if ( F_37 ( V_17 , V_53 , V_7 -> V_13 ) ||
F_38 ( V_17 , V_54 , V_7 -> V_22 ) ||
F_37 ( V_17 , V_55 , V_7 -> V_23 ) ||
F_37 ( V_17 , V_59 , V_7 -> V_24 ) )
goto V_82;
F_39 ( V_17 , V_81 ) ;
} else {
if ( V_7 -> V_11 ) {
V_79 -> V_83 = V_2 - V_7 -> V_11 ;
} else {
struct V_9 * V_10 ;
int V_36 ;
V_79 -> V_83 = 0 ;
for ( V_36 = 0 ; ! V_79 -> V_83 && V_36 < V_7 -> V_13 ; V_36 ++ ) {
for ( V_10 = V_7 -> V_12 [ V_36 ] ; ! V_79 -> V_83 && V_10 ;
V_10 = V_10 -> V_14 ) {
if ( & V_10 -> V_15 == V_2 )
V_79 -> V_83 = V_10 -> V_8 ;
}
}
}
F_6 ( L_14 , V_79 -> V_83 ) ;
if ( V_2 -> V_4 . V_27 &&
F_37 ( V_17 , V_62 , V_2 -> V_4 . V_5 ) )
goto V_82;
if ( F_40 ( V_17 , & V_2 -> V_3 , & V_52 ) < 0 )
goto V_82;
F_39 ( V_17 , V_81 ) ;
if ( F_41 ( V_17 , & V_2 -> V_3 , & V_52 ) < 0 )
goto V_82;
}
return V_17 -> V_84 ;
V_82:
F_42 ( V_17 , V_80 ) ;
return - 1 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_85 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_85 ) ;
}
