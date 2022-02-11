void F_1 ( void )
{
int V_1 , V_2 ;
struct V_3 * V_4 ;
T_1 V_5 ;
const T_2 * V_6 ;
T_1 V_7 ;
V_4 = F_2 ( V_8 , NULL ) ;
F_3 ( ! V_4 ) ;
V_7 = F_4 ( V_8 ) ;
V_9 = V_10 = V_7 ;
F_5 ( L_1 , V_9 ) ;
V_6 = F_6 ( V_4 , L_2 , & V_5 ) ;
if ( ! V_6 ) {
F_7 ( V_4 ) ;
return;
}
V_1 = V_5 / sizeof( int ) ;
for ( V_2 = 0 ; V_2 < V_1 ; V_2 += 2 ) {
if ( F_8 ( V_6 [ V_2 ] ) == V_7 ) {
V_10 = F_8 ( V_6 [ V_2 + 1 ] ) ;
break;
}
}
F_5 ( L_3 ,
V_10 ) ;
F_7 ( V_4 ) ;
}
void F_9 ( unsigned int V_11 , unsigned int V_12 )
{
#ifdef F_10
int V_13 ;
int V_14 ;
if ( ! F_11 ( V_15 , NULL ) )
return;
V_13 = ( 1UL << V_16 ) - 1 - V_11 ;
V_14 = F_12 ( V_15 , V_13 , V_12 ) ;
F_13 ( V_14 < 0 , L_4 ,
V_15 , V_13 , V_12 , V_14 ) ;
#endif
}
void F_14 ( void )
{
V_17 -> V_18 ( V_19 ) ;
F_9 ( V_10 , 1 ) ;
}
void F_15 ( unsigned int V_20 )
{
struct V_21 * V_21 ;
F_16 ( L_5 , V_20 ) ;
F_17 (ics, &ics_list, link)
V_21 -> V_22 ( V_21 , V_20 ) ;
}
static void F_18 ( void )
{
unsigned int V_23 ;
V_23 = F_19 ( V_24 , V_25 ) ;
F_3 ( V_23 == V_26 ) ;
F_3 ( F_20 ( V_23 , V_17 -> V_27 ,
V_28 | V_29 , L_6 , NULL ) ) ;
}
int T_3 F_21 ( void )
{
V_30 -> V_31 = V_17 -> V_31 ;
F_18 () ;
return F_22 ( V_32 ) ;
}
void F_23 ( void )
{
struct V_33 * V_34 = F_24 ( & V_33 ) ;
V_34 -> V_13 = 0 ;
V_17 -> V_18 ( 0 ) ;
V_17 -> V_35 () ;
}
void F_25 ( int V_36 )
{
F_23 () ;
V_17 -> V_37 () ;
if ( V_36 )
F_9 ( V_10 , 0 ) ;
}
void F_26 ( void )
{
int V_38 = F_27 () , V_39 = F_28 () ;
unsigned int V_40 , V_41 ;
struct V_42 * V_43 ;
if ( V_39 == V_9 )
F_1 () ;
V_17 -> V_18 ( 0 ) ;
F_9 ( V_10 , 0 ) ;
V_17 -> V_18 ( V_44 ) ;
F_29 (virq, desc) {
struct V_45 * V_46 ;
long V_47 ;
unsigned long V_48 ;
struct V_21 * V_21 ;
if ( V_41 < V_49 )
continue;
if ( ! V_43 -> V_50 )
continue;
if ( V_43 -> V_51 . V_52 != V_24 )
continue;
V_40 = V_43 -> V_51 . V_53 ;
if ( V_40 == V_25 || V_40 == V_54 )
continue;
V_46 = F_30 ( V_43 ) ;
if ( ! V_46 || ! V_46 -> V_55 )
continue;
F_31 ( & V_43 -> V_56 , V_48 ) ;
V_47 = - 1 ;
V_21 = F_32 ( V_41 ) ;
if ( V_21 )
V_47 = V_21 -> V_57 ( V_21 , V_40 ) ;
if ( V_47 < 0 ) {
F_33 ( V_58 L_7 ,
V_59 , V_40 ) ;
goto V_60;
}
if ( V_47 != V_39 )
goto V_60;
if ( F_34 ( V_38 ) )
F_35 ( L_8 ,
V_41 , V_38 ) ;
F_36 ( & V_43 -> V_56 , V_48 ) ;
V_55 ( V_41 , V_61 ) ;
continue;
V_60:
F_36 ( & V_43 -> V_56 , V_48 ) ;
}
}
int F_37 ( unsigned int V_41 , const struct V_62 * V_62 ,
unsigned int V_63 )
{
if ( ! V_64 )
return V_9 ;
if ( ! F_38 ( V_32 , V_62 ) ) {
int V_47 = F_39 ( V_65 , V_62 ) ;
if ( V_47 < V_66 )
return F_4 ( V_47 ) ;
if ( V_63 )
return - 1 ;
}
if ( F_40 ( V_65 , V_67 ) )
return V_10 ;
return V_9 ;
}
static int F_41 ( struct V_68 * V_69 , struct V_3 * V_70 )
{
struct V_21 * V_21 ;
F_17 (ics, &ics_list, link)
if ( V_21 -> V_71 ( V_21 , V_70 ) )
return 1 ;
return 0 ;
}
static void F_42 ( struct V_51 * V_72 ) { }
static void F_43 ( struct V_51 * V_72 ) { }
static int F_44 ( struct V_68 * V_69 , unsigned int V_41 ,
T_4 V_73 )
{
struct V_21 * V_21 ;
F_5 ( L_9 , V_41 , V_73 ) ;
F_45 ( V_41 , V_74 ) ;
if ( V_73 == V_25 ) {
F_46 ( V_41 , & V_75 ,
V_76 ) ;
return 0 ;
}
F_17 (ics, &ics_list, link)
if ( V_21 -> V_77 ( V_21 , V_41 ) == 0 )
return 0 ;
return - V_78 ;
}
static int F_47 ( struct V_68 * V_69 , struct V_3 * V_79 ,
const T_1 * V_80 , unsigned int V_81 ,
T_4 * V_82 , unsigned int * V_83 )
{
* V_82 = V_80 [ 0 ] ;
* V_83 = V_84 ;
return 0 ;
}
static void T_3 F_48 ( void )
{
V_24 = F_49 ( NULL , & V_85 , NULL ) ;
F_3 ( V_24 == NULL ) ;
F_50 ( V_24 ) ;
}
void T_3 F_51 ( struct V_21 * V_21 )
{
F_52 ( & V_21 -> V_86 , & V_87 ) ;
}
static void T_3 F_53 ( void )
{
struct V_3 * V_4 ;
const T_2 * V_88 ;
V_4 = F_54 ( NULL , NULL , L_10 ) ;
if ( ! V_4 )
return;
V_88 = F_6 ( V_4 , L_11 , NULL ) ;
if ( ! V_88 )
return;
V_16 = F_8 ( * V_88 ) ;
F_7 ( V_4 ) ;
}
void T_3 F_55 ( void )
{
int V_89 = - 1 ;
if ( F_56 ( V_90 ) )
V_89 = F_57 () ;
if ( V_89 < 0 )
V_89 = F_58 () ;
if ( V_89 < 0 ) {
F_35 ( L_12 ) ;
return;
}
V_91 . V_92 = V_17 -> V_92 ;
V_75 . V_93 = V_17 -> V_94 ;
V_89 = F_59 () ;
if ( V_89 < 0 )
V_89 = F_60 () ;
if ( V_89 < 0 )
F_35 ( L_13 ) ;
F_53 () ;
F_1 () ;
F_48 () ;
F_14 () ;
}
