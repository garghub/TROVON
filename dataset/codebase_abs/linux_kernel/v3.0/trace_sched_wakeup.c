static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int * V_5 )
{
long V_6 ;
int V_7 ;
if ( F_2 ( ! V_8 ) )
return 0 ;
* V_5 = F_3 () ;
F_4 () ;
V_7 = F_5 () ;
if ( V_7 != V_9 )
goto V_10;
* V_4 = V_2 -> V_4 [ V_7 ] ;
V_6 = F_6 ( & ( * V_4 ) -> V_6 ) ;
if ( F_7 ( V_6 != 1 ) )
goto V_11;
return 1 ;
V_11:
F_8 ( & ( * V_4 ) -> V_6 ) ;
V_10:
F_9 () ;
return 0 ;
}
static void
F_10 ( unsigned long V_12 , unsigned long V_13 )
{
struct V_1 * V_2 = V_14 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_11 ( V_15 ) ;
F_12 ( V_2 , V_12 , V_13 , V_15 , V_5 ) ;
F_13 ( V_15 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
}
static int F_14 ( int V_16 )
{
int V_17 ;
if ( ! V_16 )
V_17 = F_15 ( & V_18 ) ;
else
V_17 = F_16 ( & V_19 ,
& V_20 ) ;
if ( ! V_17 && F_17 () )
V_21 = 1 ;
else
V_21 = 0 ;
return V_17 ;
}
static void F_18 ( int V_16 )
{
V_21 = 0 ;
if ( ! V_16 )
F_19 ( & V_18 ) ;
else
F_20 () ;
}
static int F_21 ( T_1 V_22 , T_1 V_23 , int V_24 )
{
if ( ! ( V_23 & V_25 ) )
return - V_26 ;
if ( ! ( F_22 () ^ V_24 ) )
return 0 ;
F_18 ( ! V_24 ) ;
F_23 ( V_14 ) ;
V_27 = 0 ;
return F_14 ( V_24 ) ;
}
static int V_20 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_14 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
int V_5 , V_17 = 0 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return 0 ;
F_24 ( V_15 ) ;
V_17 = F_25 ( V_2 , V_29 , V_15 , V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
return V_17 ;
}
static void V_19 ( struct V_30 * V_29 )
{
struct V_1 * V_2 = V_14 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_24 ( V_15 ) ;
F_26 ( V_2 , V_29 , V_15 , V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
return;
}
static void F_27 ( struct V_31 * V_32 )
{
if ( F_22 () )
F_28 ( V_32 ) ;
}
static void F_29 ( struct V_31 * V_32 )
{
if ( V_32 -> V_33 )
F_30 ( V_32 ) ;
}
static enum V_34 F_31 ( struct V_31 * V_32 )
{
if ( F_22 () )
return F_32 ( V_32 , V_35 ) ;
return V_36 ;
}
static void F_33 ( struct V_37 * V_38 )
{
if ( F_22 () )
F_34 ( V_38 , V_35 ) ;
else
F_35 ( V_38 ) ;
}
static void
F_36 ( struct V_1 * V_2 ,
unsigned long V_12 , unsigned long V_13 ,
unsigned long V_15 , int V_5 )
{
if ( F_22 () )
F_37 ( V_2 , V_12 , V_13 , V_15 , V_5 ) ;
else
F_12 ( V_2 , V_12 , V_13 , V_15 , V_5 ) ;
}
static int F_21 ( T_1 V_22 , T_1 V_23 , int V_24 )
{
return - V_26 ;
}
static int V_20 ( struct V_28 * V_29 )
{
return - 1 ;
}
static enum V_34 F_31 ( struct V_31 * V_32 )
{
return V_36 ;
}
static void V_19 ( struct V_30 * V_29 ) { }
static void F_33 ( struct V_37 * V_38 ) { }
static void F_27 ( struct V_31 * V_32 ) { }
static void F_29 ( struct V_31 * V_32 ) { }
static int F_38 ( T_2 V_39 )
{
if ( V_40 ) {
if ( V_39 < V_40 )
return 0 ;
} else {
if ( V_39 <= V_27 )
return 0 ;
}
return 1 ;
}
static void
F_39 ( void * V_41 , struct V_42 * V_43 , int V_7 )
{
if ( V_43 != V_8 )
return;
V_9 = V_7 ;
}
static void T_3
F_40 ( void * V_41 ,
struct V_42 * V_44 , struct V_42 * V_45 )
{
struct V_3 * V_4 ;
T_2 V_46 , V_47 , V_39 ;
unsigned long V_15 ;
long V_6 ;
int V_7 ;
int V_5 ;
F_41 ( V_44 ) ;
if ( F_7 ( ! V_21 ) )
return;
F_42 () ;
if ( V_45 != V_8 )
return;
V_5 = F_3 () ;
V_7 = F_5 () ;
V_6 = F_6 ( & V_14 -> V_4 [ V_7 ] -> V_6 ) ;
if ( F_2 ( V_6 != 1 ) )
goto V_11;
F_11 ( V_15 ) ;
F_43 ( & V_48 ) ;
if ( F_7 ( ! V_21 || V_45 != V_8 ) )
goto V_49;
V_4 = V_14 -> V_4 [ V_50 ] ;
F_36 ( V_14 , V_51 , V_52 , V_15 , V_5 ) ;
F_44 ( V_14 , V_44 , V_45 , V_15 , V_5 ) ;
V_46 = V_4 -> V_53 ;
V_47 = F_45 ( V_7 ) ;
V_39 = V_47 - V_46 ;
if ( ! F_38 ( V_39 ) )
goto V_49;
if ( F_2 ( ! F_46 () ) ) {
V_27 = V_39 ;
F_47 ( V_14 , V_8 , V_50 ) ;
}
V_49:
F_48 ( V_14 ) ;
F_49 ( & V_48 ) ;
F_13 ( V_15 ) ;
V_11:
F_8 ( & V_14 -> V_4 [ V_7 ] -> V_6 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
V_50 = - 1 ;
V_54 = - 1 ;
if ( V_8 )
F_50 ( V_8 ) ;
V_8 = NULL ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
F_51 ( V_2 ) ;
F_11 ( V_15 ) ;
F_43 ( & V_48 ) ;
F_48 ( V_2 ) ;
F_49 ( & V_48 ) ;
F_13 ( V_15 ) ;
}
static void
F_52 ( void * V_41 , struct V_42 * V_55 , int V_56 )
{
struct V_3 * V_4 ;
int V_7 = F_53 () ;
unsigned long V_15 ;
long V_6 ;
int V_5 ;
if ( F_2 ( ! V_21 ) )
return;
F_41 ( V_55 ) ;
F_41 ( V_57 ) ;
if ( ( V_58 && ! F_54 ( V_55 ) ) ||
V_55 -> V_59 >= V_54 ||
V_55 -> V_59 >= V_57 -> V_59 )
return;
V_5 = F_3 () ;
V_6 = F_6 ( & V_14 -> V_4 [ V_7 ] -> V_6 ) ;
if ( F_7 ( V_6 != 1 ) )
goto V_11;
F_43 ( & V_48 ) ;
if ( ! V_21 || V_55 -> V_59 >= V_54 )
goto V_60;
F_48 ( V_14 ) ;
V_50 = F_55 ( V_55 ) ;
V_9 = V_50 ;
V_54 = V_55 -> V_59 ;
V_8 = V_55 ;
F_56 ( V_8 ) ;
F_24 ( V_15 ) ;
V_4 = V_14 -> V_4 [ V_50 ] ;
V_4 -> V_53 = F_45 ( V_7 ) ;
F_57 ( V_14 , V_55 , V_57 , V_15 , V_5 ) ;
F_36 ( V_14 , V_52 , V_61 , V_15 , V_5 ) ;
V_60:
F_49 ( & V_48 ) ;
V_11:
F_8 ( & V_14 -> V_4 [ V_7 ] -> V_6 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_59 ( F_52 , NULL ) ;
if ( V_17 ) {
F_60 ( L_1
L_2 ) ;
return;
}
V_17 = F_61 ( F_52 , NULL ) ;
if ( V_17 ) {
F_60 ( L_1
L_3 ) ;
goto V_62;
}
V_17 = F_62 ( F_40 , NULL ) ;
if ( V_17 ) {
F_60 ( L_4
L_5 ) ;
goto V_63;
}
V_17 = F_63 ( F_39 , NULL ) ;
if ( V_17 ) {
F_60 ( L_1
L_6 ) ;
return;
}
F_23 ( V_2 ) ;
F_64 () ;
if ( F_14 ( F_22 () ) )
F_65 ( V_64 L_7 ) ;
return;
V_63:
F_66 ( F_52 , NULL ) ;
V_62:
F_67 ( F_52 , NULL ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
V_21 = 0 ;
F_18 ( F_22 () ) ;
F_69 ( F_40 , NULL ) ;
F_66 ( F_52 , NULL ) ;
F_67 ( F_52 , NULL ) ;
F_70 ( F_39 , NULL ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
V_65 = V_66 & V_67 ;
V_66 |= V_67 ;
V_27 = 0 ;
V_14 = V_2 ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
V_58 = 0 ;
return F_71 ( V_2 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
V_58 = 1 ;
return F_71 ( V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! V_65 )
V_66 &= ~ V_67 ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
V_21 = 1 ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_21 = 0 ;
}
T_4 static int F_77 ( void )
{
int V_17 ;
V_17 = F_78 ( & V_68 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_78 ( & V_69 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
