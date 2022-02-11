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
static void * F_11 ( struct V_19 * V_20 , T_3 V_28 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 ;
F_7 ( L_4 , V_20 , V_28 ) ;
if ( V_7 -> V_9 && V_28 >= V_7 -> V_30 )
return NULL ;
V_2 = F_3 ( V_7 , V_28 ) ;
return V_2 && F_1 ( V_2 ) ? V_2 : NULL ;
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
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_3 ) ;
F_18 ( & V_2 -> V_3 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_35 , struct V_1 , V_35 ) ;
F_21 () ;
F_16 ( V_2 ) ;
F_22 () ;
}
static void F_23 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_37 , struct V_1 , V_38 ) ;
F_24 ( & V_2 -> V_35 , F_19 ) ;
F_25 ( & V_2 -> V_35 ) ;
}
static void F_26 ( struct V_12 * V_10 )
{
F_17 ( & V_10 -> V_16 . V_3 ) ;
F_18 ( & V_10 -> V_16 . V_3 ) ;
F_27 ( V_10 ) ;
}
static void F_28 ( struct V_34 * V_35 )
{
struct V_12 * V_10 = F_20 ( V_35 , struct V_12 ,
V_35 ) ;
F_21 () ;
F_26 ( V_10 ) ;
F_22 () ;
}
static void F_29 ( struct V_36 * V_37 )
{
struct V_12 * V_10 = F_20 ( V_37 , struct V_12 ,
V_38 ) ;
F_24 ( & V_10 -> V_35 , F_28 ) ;
F_25 ( & V_10 -> V_35 ) ;
}
static int F_30 ( struct V_19 * V_20 , void * V_39 , bool * V_40 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = V_39 ;
struct V_12 T_2 * * V_41 ;
struct V_12 * V_10 = NULL ;
F_7 ( L_6 , V_20 , V_39 , V_7 ) ;
if ( V_7 -> V_9 ) {
if ( ! V_2 -> V_4 . V_29 )
return - V_42 ;
} else {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_14 ; V_43 ++ ) {
V_41 = V_7 -> V_11 + V_43 ;
for ( V_10 = F_12 ( * V_41 ) ; V_10 ;
V_41 = & V_10 -> V_15 , V_10 = F_12 ( * V_41 ) ) {
if ( & V_10 -> V_16 == V_2 )
goto V_44;
}
}
return - V_42 ;
V_44:
F_15 ( * V_41 , F_12 ( V_10 -> V_15 ) ) ;
}
F_31 ( V_20 , & V_2 -> V_4 ) ;
if ( V_10 ) {
if ( F_32 ( & V_10 -> V_16 . V_3 ) )
F_33 ( & V_10 -> V_38 , F_29 ) ;
else
F_26 ( V_10 ) ;
} else {
if ( F_32 ( & V_2 -> V_3 ) )
F_33 ( & V_2 -> V_38 , F_23 ) ;
else
F_16 ( V_2 ) ;
}
* V_40 = false ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 ,
void * V_39 , struct V_45 * V_46 )
{
bool V_40 ;
return F_30 ( V_20 , V_39 , & V_40 ) ;
}
static void F_35 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_20 ( V_37 , struct V_6 , V_38 ) ;
F_27 ( V_7 -> V_9 ) ;
F_27 ( V_7 -> V_11 ) ;
F_27 ( V_7 ) ;
}
static inline int
F_36 ( struct V_6 * V_7 )
{
return V_7 -> V_14 > ( V_7 -> V_24 >> V_7 -> V_25 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return F_38 ( & V_2 -> V_3 , V_47 , V_48 ) ;
}
static void F_39 ( struct V_36 * V_37 )
{
struct V_6 * V_7 = F_20 ( V_37 , struct V_6 , V_38 ) ;
F_27 ( V_7 -> V_9 ) ;
F_27 ( V_7 ) ;
}
static void F_40 ( struct V_6 * V_49 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_49 -> V_14 ; V_43 ++ )
F_17 ( & V_49 -> V_9 [ V_43 ] . V_3 ) ;
F_27 ( V_49 -> V_9 ) ;
}
static int F_41 ( struct V_6 * V_49 )
{
int V_43 , V_50 = 0 ;
V_49 -> V_9 = F_42 ( V_49 -> V_14 , sizeof( struct V_1 ) ,
V_31 ) ;
if ( ! V_49 -> V_9 )
return - V_32 ;
for ( V_43 = 0 ; V_43 < V_49 -> V_14 ; V_43 ++ ) {
V_50 = F_38 ( & V_49 -> V_9 [ V_43 ] . V_3 ,
V_47 , V_48 ) ;
if ( V_50 < 0 )
goto V_51;
}
return 0 ;
V_51:
F_40 ( V_49 ) ;
return V_50 ;
}
static int
F_43 ( struct V_52 * V_52 , struct V_19 * V_20 , unsigned long V_53 ,
T_3 V_28 , struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_54 * * V_55 ,
struct V_54 * V_56 , bool V_57 )
{
struct V_1 V_58 , * V_59 = V_2 ;
struct V_1 V_60 ;
struct V_6 * V_49 = NULL , * V_61 ;
struct V_12 * V_10 = NULL ;
int V_50 , V_62 = 0 ;
struct V_63 V_64 ;
V_50 = F_38 ( & V_64 , V_47 , V_48 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_44 ( V_52 , V_20 , V_55 , V_56 , & V_64 , V_57 ) ;
if ( V_50 < 0 )
goto V_51;
V_50 = - V_32 ;
V_49 = F_14 ( sizeof( * V_49 ) , V_31 ) ;
if ( ! V_49 )
goto V_51;
V_49 -> V_24 = V_7 -> V_24 ;
V_49 -> V_25 = V_7 -> V_25 ;
V_49 -> V_14 = V_7 -> V_14 ;
V_49 -> V_30 = V_7 -> V_30 ;
V_49 -> V_26 = V_7 -> V_26 ;
V_49 -> V_20 = V_20 ;
if ( V_7 -> V_9 ) {
int V_43 ;
if ( F_41 ( V_49 ) < 0 )
goto V_51;
for ( V_43 = 0 ; V_43 < V_49 -> V_14 ; V_43 ++ )
V_49 -> V_9 [ V_43 ] . V_4 = V_7 -> V_9 [ V_43 ] . V_4 ;
V_62 = 1 ;
}
V_49 -> V_11 = V_7 -> V_11 ;
V_50 = F_37 ( & V_58 ) ;
if ( V_50 < 0 )
goto V_65;
V_50 = F_37 ( & V_60 ) ;
if ( V_50 < 0 )
goto V_65;
if ( V_59 )
V_60 . V_4 = V_2 -> V_4 ;
if ( V_55 [ V_66 ] )
V_49 -> V_14 = F_45 ( V_55 [ V_66 ] ) ;
if ( V_55 [ V_67 ] )
V_49 -> V_24 = F_46 ( V_55 [ V_67 ] ) ;
if ( V_55 [ V_68 ] )
V_49 -> V_25 = F_45 ( V_55 [ V_68 ] ) ;
V_50 = - V_69 ;
if ( V_49 -> V_9 ) {
if ( ! F_36 ( V_49 ) ||
V_49 -> V_14 > V_49 -> V_30 )
goto V_70;
} else if ( V_49 -> V_11 && V_49 -> V_14 != V_49 -> V_30 ) {
goto V_70;
}
V_50 = - V_71 ;
if ( V_55 [ V_72 ] )
V_49 -> V_26 = F_45 ( V_55 [ V_72 ] ) ;
if ( ! V_49 -> V_14 ) {
if ( ( V_49 -> V_24 >> V_49 -> V_25 ) < V_73 )
V_49 -> V_14 = ( V_49 -> V_24 >> V_49 -> V_25 ) + 1 ;
else
V_49 -> V_14 = V_33 ;
}
if ( ! V_49 -> V_9 && ! V_49 -> V_11 )
V_49 -> V_30 = V_49 -> V_14 ;
if ( V_49 -> V_9 || F_36 ( V_49 ) )
if ( V_28 >= V_49 -> V_30 )
goto V_70;
V_50 = - V_32 ;
if ( ! V_49 -> V_9 && ! V_49 -> V_11 ) {
if ( F_36 ( V_49 ) ) {
if ( F_41 ( V_49 ) < 0 )
goto V_70;
V_62 = 1 ;
} else {
struct V_12 T_2 * * V_14 ;
V_14 = F_42 ( V_49 -> V_14 ,
sizeof( struct V_12 * ) ,
V_31 ) ;
if ( ! V_14 )
goto V_70;
V_49 -> V_11 = V_14 ;
V_62 = 2 ;
}
}
if ( V_49 -> V_9 )
V_2 = V_49 -> V_9 + V_28 ;
else
V_2 = F_3 ( V_49 , V_28 ) ? : & V_58 ;
if ( V_2 == & V_58 ) {
V_10 = F_14 ( sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 )
goto V_70;
V_10 -> V_8 = V_28 ;
V_10 -> V_15 = NULL ;
V_50 = F_37 ( & V_10 -> V_16 ) ;
if ( V_50 < 0 ) {
F_27 ( V_10 ) ;
goto V_70;
}
}
if ( V_55 [ V_74 ] ) {
V_60 . V_4 . V_5 = F_45 ( V_55 [ V_74 ] ) ;
F_47 ( V_20 , & V_60 . V_4 , V_53 ) ;
}
if ( V_59 )
F_48 ( & V_2 -> V_3 , & V_64 ) ;
else
F_48 ( & V_60 . V_3 , & V_64 ) ;
if ( V_59 && V_59 != V_2 ) {
V_50 = F_37 ( V_59 ) ;
if ( V_50 < 0 ) {
F_27 ( V_10 ) ;
goto V_70;
}
}
V_61 = V_7 ;
V_2 -> V_4 = V_60 . V_4 ;
F_15 ( V_20 -> V_22 , V_49 ) ;
if ( V_2 == & V_58 ) {
struct V_12 * V_75 ;
struct V_12 T_2 * * V_13 ;
F_48 ( & V_10 -> V_16 . V_3 , & V_2 -> V_3 ) ;
V_13 = V_49 -> V_11 + ( V_28 % V_49 -> V_14 ) ;
for ( V_75 = F_12 ( * V_13 ) ;
V_75 ;
V_13 = & V_75 -> V_15 , V_75 = F_12 ( * V_13 ) )
;
F_15 ( * V_13 , V_10 ) ;
}
if ( V_61 )
F_33 ( & V_61 -> V_38 , F_39 ) ;
return 0 ;
V_70:
if ( V_62 == 1 )
F_40 ( V_49 ) ;
else if ( V_62 == 2 )
F_27 ( V_49 -> V_11 ) ;
V_65:
F_17 ( & V_60 . V_3 ) ;
F_17 ( & V_58 . V_3 ) ;
V_51:
F_27 ( V_49 ) ;
F_17 ( & V_64 ) ;
return V_50 ;
}
static int
F_49 ( struct V_52 * V_52 , struct V_17 * V_76 ,
struct V_19 * V_20 , unsigned long V_53 , T_3 V_28 ,
struct V_54 * * V_77 , void * * V_39 , bool V_57 )
{
struct V_54 * V_78 = V_77 [ V_79 ] ;
struct V_54 * V_55 [ V_80 + 1 ] ;
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = * V_39 ;
int V_50 ;
F_7 ( L_7
L_8 ,
V_20 , V_28 , V_77 , V_39 , V_78 , V_7 , V_2 , V_39 ? * V_39 : NULL ) ;
if ( ! V_78 )
return 0 ;
V_50 = F_50 ( V_55 , V_80 , V_78 , V_81 , NULL ) ;
if ( V_50 < 0 )
return V_50 ;
return F_43 ( V_52 , V_20 , V_53 , V_28 , V_7 , V_2 , V_55 ,
V_77 [ V_82 ] , V_57 ) ;
}
static void F_51 ( struct V_19 * V_20 , struct V_45 * V_46 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_12 * V_10 , * V_15 ;
int V_43 ;
F_7 ( L_9 , V_20 , V_46 , V_7 ) ;
if ( V_7 -> V_9 ) {
for ( V_43 = 0 ; V_43 < V_7 -> V_14 ; V_43 ++ ) {
if ( ! V_7 -> V_9 [ V_43 ] . V_4 . V_29 )
continue;
if ( V_46 -> V_83 >= V_46 -> V_84 ) {
if ( V_46 -> V_85 ( V_20 , V_7 -> V_9 + V_43 , V_46 ) < 0 ) {
V_46 -> V_86 = 1 ;
return;
}
}
V_46 -> V_83 ++ ;
}
}
if ( ! V_7 -> V_11 )
return;
for ( V_43 = 0 ; V_43 < V_7 -> V_14 ; V_43 ++ ) {
for ( V_10 = F_12 ( V_7 -> V_11 [ V_43 ] ) ; V_10 ; V_10 = V_15 ) {
V_15 = F_12 ( V_10 -> V_15 ) ;
if ( V_46 -> V_83 >= V_46 -> V_84 ) {
if ( V_46 -> V_85 ( V_20 , & V_10 -> V_16 , V_46 ) < 0 ) {
V_46 -> V_86 = 1 ;
return;
}
}
V_46 -> V_83 ++ ;
}
}
}
static void F_52 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_45 V_46 ;
F_7 ( L_10 , V_20 , V_7 ) ;
V_46 . V_83 = 0 ;
V_46 . V_84 = 0 ;
V_46 . V_85 = F_34 ;
F_51 ( V_20 , & V_46 ) ;
F_33 ( & V_7 -> V_38 , F_35 ) ;
}
static int F_53 ( struct V_52 * V_52 , struct V_19 * V_20 , void * V_87 ,
struct V_17 * V_18 , struct V_88 * V_89 )
{
struct V_6 * V_7 = F_12 ( V_20 -> V_22 ) ;
struct V_1 * V_2 = V_87 ;
struct V_54 * V_90 ;
F_7 ( L_11 ,
V_20 , V_87 , V_18 , V_89 , V_7 , V_2 ) ;
F_7 ( L_12 , V_7 -> V_9 , V_7 -> V_11 ) ;
V_90 = F_54 ( V_18 , V_79 ) ;
if ( V_90 == NULL )
goto V_91;
if ( ! V_87 ) {
V_89 -> V_92 = ~ 0 ;
if ( F_55 ( V_18 , V_66 , V_7 -> V_14 ) ||
F_56 ( V_18 , V_67 , V_7 -> V_24 ) ||
F_55 ( V_18 , V_68 , V_7 -> V_25 ) ||
F_55 ( V_18 , V_72 , V_7 -> V_26 ) )
goto V_91;
F_57 ( V_18 , V_90 ) ;
} else {
if ( V_7 -> V_9 ) {
V_89 -> V_92 = V_2 - V_7 -> V_9 ;
} else {
struct V_12 * V_10 ;
struct V_12 T_2 * * V_13 ;
int V_43 ;
V_89 -> V_92 = 0 ;
for ( V_43 = 0 ; ! V_89 -> V_92 && V_43 < V_7 -> V_14 ; V_43 ++ ) {
V_13 = & V_7 -> V_11 [ V_43 ] ;
for ( V_10 = F_12 ( * V_13 ) ;
! V_89 -> V_92 && V_10 ;
V_13 = & V_10 -> V_15 , V_10 = F_12 ( * V_13 ) ) {
if ( & V_10 -> V_16 == V_2 )
V_89 -> V_92 = V_10 -> V_8 ;
}
}
}
F_7 ( L_13 , V_89 -> V_92 ) ;
if ( V_2 -> V_4 . V_29 &&
F_55 ( V_18 , V_74 , V_2 -> V_4 . V_5 ) )
goto V_91;
if ( F_58 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_91;
F_57 ( V_18 , V_90 ) ;
if ( F_59 ( V_18 , & V_2 -> V_3 ) < 0 )
goto V_91;
}
return V_18 -> V_93 ;
V_91:
F_60 ( V_18 , V_90 ) ;
return - 1 ;
}
static void F_61 ( void * V_87 , T_3 V_5 , unsigned long V_94 )
{
struct V_1 * V_2 = V_87 ;
if ( V_2 && V_2 -> V_4 . V_5 == V_5 )
V_2 -> V_4 . V_29 = V_94 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_95 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_95 ) ;
}
