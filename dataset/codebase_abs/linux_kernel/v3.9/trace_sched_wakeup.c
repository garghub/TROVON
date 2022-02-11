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
F_10 ( unsigned long V_12 , unsigned long V_13 ,
struct V_14 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 ;
unsigned long V_18 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_11 ( V_18 ) ;
F_12 ( V_2 , V_12 , V_13 , V_18 , V_5 ) ;
F_13 ( V_18 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
}
static int F_14 ( int V_19 )
{
int V_20 ;
if ( ! V_19 )
V_20 = F_15 ( & V_21 ) ;
else
V_20 = F_16 ( & V_22 ,
& V_23 ) ;
if ( ! V_20 && F_17 () )
V_24 = 1 ;
else
V_24 = 0 ;
return V_20 ;
}
static void F_18 ( int V_19 )
{
V_24 = 0 ;
if ( ! V_19 )
F_19 ( & V_21 ) ;
else
F_20 () ;
}
static int F_21 ( T_1 V_25 , T_1 V_26 , int V_27 )
{
if ( ! ( V_26 & V_28 ) )
return - V_29 ;
if ( ! ( F_22 () ^ V_27 ) )
return 0 ;
F_18 ( ! V_27 ) ;
F_23 ( V_17 ) ;
V_30 = 0 ;
return F_14 ( V_27 ) ;
}
static int V_23 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 ;
unsigned long V_18 ;
int V_5 , V_20 = 0 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return 0 ;
F_24 ( V_18 ) ;
V_20 = F_25 ( V_2 , V_32 , V_18 , V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
return V_20 ;
}
static void V_22 ( struct V_33 * V_32 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 ;
unsigned long V_18 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_24 ( V_18 ) ;
F_26 ( V_2 , V_32 , V_18 , V_5 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 () ;
return;
}
static void F_27 ( struct V_34 * V_35 )
{
if ( F_22 () )
F_28 ( V_35 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
if ( V_35 -> V_36 )
F_30 ( V_35 ) ;
}
static enum V_37 F_31 ( struct V_34 * V_35 )
{
if ( F_22 () )
return F_32 ( V_35 , V_38 ) ;
return V_39 ;
}
static void F_33 ( struct V_40 * V_41 )
{
if ( F_22 () )
F_34 ( V_41 , V_38 ) ;
else
F_35 ( V_41 ) ;
}
static void
F_36 ( struct V_1 * V_2 ,
unsigned long V_12 , unsigned long V_13 ,
unsigned long V_18 , int V_5 )
{
if ( F_22 () )
F_37 ( V_2 , V_12 , V_13 , V_18 , V_5 ) ;
else
F_12 ( V_2 , V_12 , V_13 , V_18 , V_5 ) ;
}
static int F_21 ( T_1 V_25 , T_1 V_26 , int V_27 )
{
return - V_29 ;
}
static int V_23 ( struct V_31 * V_32 )
{
return - 1 ;
}
static enum V_37 F_31 ( struct V_34 * V_35 )
{
return V_39 ;
}
static void V_22 ( struct V_33 * V_32 ) { }
static void F_27 ( struct V_34 * V_35 ) { }
static void F_29 ( struct V_34 * V_35 ) { }
static void F_33 ( struct V_40 * V_41 )
{
F_35 ( V_41 ) ;
}
static void F_33 ( struct V_40 * V_41 )
{
F_38 ( V_41 ) ;
}
static int F_39 ( T_2 V_42 )
{
if ( V_43 ) {
if ( V_42 < V_43 )
return 0 ;
} else {
if ( V_42 <= V_30 )
return 0 ;
}
return 1 ;
}
static void
F_40 ( void * V_44 , struct V_45 * V_46 , int V_7 )
{
if ( V_46 != V_8 )
return;
V_9 = V_7 ;
}
static void T_3
F_41 ( void * V_44 ,
struct V_45 * V_47 , struct V_45 * V_48 )
{
struct V_3 * V_4 ;
T_2 V_49 , V_50 , V_42 ;
unsigned long V_18 ;
long V_6 ;
int V_7 ;
int V_5 ;
F_42 ( V_47 ) ;
if ( F_7 ( ! V_24 ) )
return;
F_43 () ;
if ( V_48 != V_8 )
return;
V_5 = F_3 () ;
V_7 = F_5 () ;
V_6 = F_6 ( & V_17 -> V_4 [ V_7 ] -> V_6 ) ;
if ( F_2 ( V_6 != 1 ) )
goto V_11;
F_11 ( V_18 ) ;
F_44 ( & V_51 ) ;
if ( F_7 ( ! V_24 || V_48 != V_8 ) )
goto V_52;
V_4 = V_17 -> V_4 [ V_53 ] ;
F_36 ( V_17 , V_54 , V_55 , V_18 , V_5 ) ;
F_45 ( V_17 , V_47 , V_48 , V_18 , V_5 ) ;
V_49 = V_4 -> V_56 ;
V_50 = F_46 ( V_7 ) ;
V_42 = V_50 - V_49 ;
if ( ! F_39 ( V_42 ) )
goto V_52;
if ( F_2 ( ! F_47 () ) ) {
V_30 = V_42 ;
F_48 ( V_17 , V_8 , V_53 ) ;
}
V_52:
F_49 ( V_17 ) ;
F_50 ( & V_51 ) ;
F_13 ( V_18 ) ;
V_11:
F_8 ( & V_17 -> V_4 [ V_7 ] -> V_6 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
V_53 = - 1 ;
V_57 = - 1 ;
if ( V_8 )
F_51 ( V_8 ) ;
V_8 = NULL ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
F_52 ( V_2 ) ;
F_11 ( V_18 ) ;
F_44 ( & V_51 ) ;
F_49 ( V_2 ) ;
F_50 ( & V_51 ) ;
F_13 ( V_18 ) ;
}
static void
F_53 ( void * V_44 , struct V_45 * V_58 , int V_59 )
{
struct V_3 * V_4 ;
int V_7 = F_54 () ;
unsigned long V_18 ;
long V_6 ;
int V_5 ;
if ( F_2 ( ! V_24 ) )
return;
F_42 ( V_58 ) ;
F_42 ( V_60 ) ;
if ( ( V_61 && ! F_55 ( V_58 ) ) ||
V_58 -> V_62 >= V_57 ||
V_58 -> V_62 >= V_60 -> V_62 )
return;
V_5 = F_3 () ;
V_6 = F_6 ( & V_17 -> V_4 [ V_7 ] -> V_6 ) ;
if ( F_7 ( V_6 != 1 ) )
goto V_11;
F_44 ( & V_51 ) ;
if ( ! V_24 || V_58 -> V_62 >= V_57 )
goto V_63;
F_49 ( V_17 ) ;
V_53 = F_56 ( V_58 ) ;
V_9 = V_53 ;
V_57 = V_58 -> V_62 ;
V_8 = V_58 ;
F_57 ( V_8 ) ;
F_24 ( V_18 ) ;
V_4 = V_17 -> V_4 [ V_53 ] ;
V_4 -> V_56 = F_46 ( V_7 ) ;
F_58 ( V_17 , V_58 , V_60 , V_18 , V_5 ) ;
F_36 ( V_17 , V_55 , V_64 , V_18 , V_5 ) ;
V_63:
F_50 ( & V_51 ) ;
V_11:
F_8 ( & V_17 -> V_4 [ V_7 ] -> V_6 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_60 ( F_53 , NULL ) ;
if ( V_20 ) {
F_61 ( L_1
L_2 ) ;
return;
}
V_20 = F_62 ( F_53 , NULL ) ;
if ( V_20 ) {
F_61 ( L_1
L_3 ) ;
goto V_65;
}
V_20 = F_63 ( F_41 , NULL ) ;
if ( V_20 ) {
F_61 ( L_4
L_5 ) ;
goto V_66;
}
V_20 = F_64 ( F_40 , NULL ) ;
if ( V_20 ) {
F_61 ( L_1
L_6 ) ;
return;
}
F_23 ( V_2 ) ;
F_65 () ;
if ( F_14 ( F_22 () ) )
F_66 ( V_67 L_7 ) ;
return;
V_66:
F_67 ( F_53 , NULL ) ;
V_65:
F_68 ( F_53 , NULL ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
V_24 = 0 ;
F_18 ( F_22 () ) ;
F_70 ( F_41 , NULL ) ;
F_67 ( F_53 , NULL ) ;
F_68 ( F_53 , NULL ) ;
F_71 ( F_40 , NULL ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
V_68 = V_69 ;
F_73 ( V_70 , 1 ) ;
F_73 ( V_71 , 1 ) ;
V_30 = 0 ;
V_17 = V_2 ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
V_61 = 0 ;
return F_72 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
V_61 = 1 ;
return F_72 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_72 = V_68 & V_71 ;
int V_73 = V_68 & V_70 ;
F_69 ( V_2 ) ;
F_23 ( V_2 ) ;
F_73 ( V_71 , V_72 ) ;
F_73 ( V_70 , V_73 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
V_24 = 1 ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_24 = 0 ;
}
T_4 static int F_79 ( void )
{
int V_20 ;
V_20 = F_80 ( & V_74 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_80 ( & V_75 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
