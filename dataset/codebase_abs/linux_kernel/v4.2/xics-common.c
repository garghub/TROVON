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
void T_3 F_21 ( void )
{
V_30 -> V_31 = V_17 -> V_31 ;
F_18 () ;
}
void F_22 ( void )
{
struct V_32 * V_33 = F_23 ( & V_32 ) ;
V_33 -> V_13 = 0 ;
V_17 -> V_18 ( 0 ) ;
V_17 -> V_34 () ;
}
void F_24 ( int V_35 )
{
F_22 () ;
V_17 -> V_36 () ;
if ( V_35 )
F_9 ( V_10 , 0 ) ;
}
void F_25 ( void )
{
int V_37 = F_26 () , V_38 = F_27 () ;
unsigned int V_39 , V_40 ;
struct V_41 * V_42 ;
if ( V_38 == V_9 )
F_1 () ;
V_17 -> V_18 ( 0 ) ;
F_9 ( V_10 , 0 ) ;
V_17 -> V_18 ( V_43 ) ;
F_28 (virq, desc) {
struct V_44 * V_45 ;
long V_46 ;
unsigned long V_47 ;
struct V_21 * V_21 ;
if ( V_40 < V_48 )
continue;
if ( ! V_42 -> V_49 )
continue;
if ( V_42 -> V_50 . V_51 != V_24 )
continue;
V_39 = V_42 -> V_50 . V_52 ;
if ( V_39 == V_25 || V_39 == V_53 )
continue;
V_45 = F_29 ( V_42 ) ;
if ( ! V_45 || ! V_45 -> V_54 )
continue;
F_30 ( & V_42 -> V_55 , V_47 ) ;
V_46 = - 1 ;
V_21 = F_31 ( V_42 ) ;
if ( V_21 )
V_46 = V_21 -> V_56 ( V_21 , V_39 ) ;
if ( V_46 < 0 ) {
F_32 ( V_57 L_7 ,
V_58 , V_39 ) ;
goto V_59;
}
if ( V_46 != V_38 )
goto V_59;
if ( F_33 ( V_37 ) )
F_34 ( L_8 ,
V_40 , V_37 ) ;
F_35 ( & V_42 -> V_55 , V_47 ) ;
V_54 ( V_40 , V_60 ) ;
continue;
V_59:
F_35 ( & V_42 -> V_55 , V_47 ) ;
}
}
int F_36 ( unsigned int V_40 , const struct V_61 * V_61 ,
unsigned int V_62 )
{
if ( ! V_63 )
return V_9 ;
if ( ! F_37 ( V_64 , V_61 ) ) {
int V_46 = F_38 ( V_65 , V_61 ) ;
if ( V_46 < V_66 )
return F_4 ( V_46 ) ;
if ( V_62 )
return - 1 ;
}
if ( F_39 ( V_65 , V_67 ) )
return V_10 ;
return V_9 ;
}
static int F_40 ( struct V_68 * V_69 , struct V_3 * V_70 )
{
struct V_21 * V_21 ;
F_17 (ics, &ics_list, link)
if ( V_21 -> V_71 ( V_21 , V_70 ) )
return 1 ;
return 0 ;
}
static void F_41 ( struct V_50 * V_72 ) { }
static void F_42 ( struct V_50 * V_72 ) { }
static int F_43 ( struct V_68 * V_69 , unsigned int V_40 ,
T_4 V_73 )
{
struct V_21 * V_21 ;
F_5 ( L_9 , V_40 , V_73 ) ;
F_44 ( V_40 , V_74 ) ;
if ( V_73 == V_25 ) {
F_45 ( V_40 , & V_75 ,
V_76 ) ;
return 0 ;
}
F_17 (ics, &ics_list, link)
if ( V_21 -> V_77 ( V_21 , V_40 ) == 0 )
return 0 ;
return - V_78 ;
}
static int F_46 ( struct V_68 * V_69 , struct V_3 * V_79 ,
const T_1 * V_80 , unsigned int V_81 ,
T_4 * V_82 , unsigned int * V_83 )
{
* V_82 = V_80 [ 0 ] ;
* V_83 = V_84 ;
return 0 ;
}
static void T_3 F_47 ( void )
{
V_24 = F_48 ( NULL , & V_85 , NULL ) ;
F_3 ( V_24 == NULL ) ;
F_49 ( V_24 ) ;
}
void T_3 F_50 ( struct V_21 * V_21 )
{
F_51 ( & V_21 -> V_86 , & V_87 ) ;
}
static void T_3 F_52 ( void )
{
struct V_3 * V_4 ;
const T_2 * V_88 ;
V_4 = F_53 ( NULL , NULL , L_10 ) ;
if ( ! V_4 )
return;
V_88 = F_6 ( V_4 , L_11 , NULL ) ;
if ( ! V_88 )
return;
V_16 = F_8 ( * V_88 ) ;
F_7 ( V_4 ) ;
}
void T_3 F_54 ( void )
{
int V_89 = - 1 ;
if ( F_55 ( V_90 ) )
V_89 = F_56 () ;
if ( V_89 < 0 )
V_89 = F_57 () ;
if ( V_89 < 0 ) {
F_34 ( L_12 ) ;
return;
}
V_91 . V_92 = V_17 -> V_92 ;
V_75 . V_93 = V_17 -> V_94 ;
V_89 = F_58 () ;
if ( V_89 < 0 )
V_89 = F_59 () ;
if ( V_89 < 0 )
F_34 ( L_13 ) ;
F_52 () ;
F_1 () ;
F_47 () ;
F_14 () ;
}
