void F_1 ( void )
{
int V_1 , V_2 ;
struct V_3 * V_4 ;
T_1 V_5 ;
const T_1 * V_6 ;
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
if ( V_6 [ V_2 ] == V_7 ) {
V_10 = V_6 [ V_2 + 1 ] ;
break;
}
}
F_5 ( L_3 ,
V_10 ) ;
F_7 ( V_4 ) ;
}
void F_8 ( unsigned int V_11 , unsigned int V_12 )
{
#ifdef F_9
int V_13 ;
int V_14 ;
if ( ! F_10 ( V_15 , NULL ) )
return;
V_13 = ( 1UL << V_16 ) - 1 - V_11 ;
V_14 = F_11 ( V_15 , V_13 , V_12 ) ;
F_12 ( V_14 < 0 , L_4 ,
V_15 , V_13 , V_12 , V_14 ) ;
#endif
}
void F_13 ( void )
{
V_17 -> V_18 ( V_19 ) ;
F_8 ( V_10 , 1 ) ;
}
void F_14 ( unsigned int V_20 )
{
struct V_21 * V_21 ;
F_15 ( L_5 , V_20 ) ;
F_16 (ics, &ics_list, link)
V_21 -> V_22 ( V_21 , V_20 ) ;
}
static void F_17 ( void )
{
unsigned int V_23 ;
V_23 = F_18 ( V_24 , V_25 ) ;
F_3 ( V_23 == V_26 ) ;
F_3 ( F_19 ( V_23 , V_17 -> V_27 ,
V_28 , L_6 , NULL ) ) ;
}
int T_2 F_20 ( void )
{
V_29 -> V_30 = V_17 -> V_30 ;
F_17 () ;
return F_21 ( V_31 ) ;
}
void F_22 ( void )
{
struct V_32 * V_33 = & F_23 ( V_32 ) ;
V_33 -> V_13 = 0 ;
V_17 -> V_18 ( 0 ) ;
V_17 -> V_34 () ;
}
void F_24 ( int V_35 )
{
F_22 () ;
V_17 -> V_36 () ;
if ( V_35 )
F_8 ( V_10 , 0 ) ;
}
void F_25 ( void )
{
int V_37 = F_26 () , V_38 = F_27 () ;
unsigned int V_39 , V_40 ;
if ( V_38 == V_9 )
F_1 () ;
V_17 -> V_18 ( 0 ) ;
F_8 ( V_10 , 0 ) ;
V_17 -> V_18 ( V_41 ) ;
F_28 (virq) {
struct V_42 * V_43 ;
struct V_44 * V_45 ;
long V_46 ;
unsigned long V_47 ;
struct V_21 * V_21 ;
if ( V_40 < V_48 )
continue;
if ( ! F_29 ( V_40 , V_24 ) )
continue;
V_39 = ( unsigned int ) F_30 ( V_40 ) ;
if ( V_39 == V_25 || V_39 == V_49 )
continue;
V_43 = F_31 ( V_40 ) ;
if ( ! V_43 || ! V_43 -> V_50 )
continue;
V_45 = F_32 ( V_43 ) ;
if ( ! V_45 || ! V_45 -> V_51 )
continue;
F_33 ( & V_43 -> V_52 , V_47 ) ;
V_46 = - 1 ;
V_21 = F_34 ( V_40 ) ;
if ( V_21 )
V_46 = V_21 -> V_53 ( V_21 , V_39 ) ;
if ( V_46 < 0 ) {
F_35 ( V_54 L_7 ,
V_55 , V_39 ) ;
goto V_56;
}
if ( V_46 != V_38 )
goto V_56;
if ( F_36 ( V_37 ) )
F_37 ( L_8 ,
V_40 , V_37 ) ;
F_38 ( & V_43 -> V_52 , V_47 ) ;
V_51 ( V_40 , V_57 ) ;
continue;
V_56:
F_38 ( & V_43 -> V_52 , V_47 ) ;
}
}
int F_39 ( unsigned int V_40 , const struct V_58 * V_58 ,
unsigned int V_59 )
{
if ( ! V_60 )
return V_9 ;
if ( ! F_40 ( V_31 , V_58 ) ) {
int V_46 = F_41 ( V_61 , V_58 ) ;
if ( V_46 < V_62 )
return F_4 ( V_46 ) ;
if ( V_59 )
return - 1 ;
}
if ( F_42 ( V_61 , V_63 ) )
return V_10 ;
return V_9 ;
}
static int F_43 ( struct V_64 * V_65 , struct V_3 * V_66 )
{
struct V_21 * V_21 ;
F_16 (ics, &ics_list, link)
if ( V_21 -> V_67 ( V_21 , V_66 ) )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_68 * V_69 ) { }
static void F_45 ( struct V_68 * V_69 ) { }
static int F_46 ( struct V_64 * V_65 , unsigned int V_40 ,
T_3 V_70 )
{
struct V_21 * V_21 ;
F_5 ( L_9 , V_40 , V_70 ) ;
F_47 ( V_24 , V_40 , V_70 ) ;
F_48 ( V_40 , V_71 ) ;
if ( V_70 == V_25 ) {
F_49 ( V_40 , & V_72 ,
V_73 ) ;
return 0 ;
}
F_16 (ics, &ics_list, link)
if ( V_21 -> V_74 ( V_21 , V_40 ) == 0 )
return 0 ;
return - V_75 ;
}
static int F_50 ( struct V_64 * V_65 , struct V_3 * V_76 ,
const T_1 * V_77 , unsigned int V_78 ,
T_3 * V_79 , unsigned int * V_80 )
{
* V_79 = V_77 [ 0 ] ;
* V_80 = V_81 ;
return 0 ;
}
static void T_2 F_51 ( void )
{
V_24 = F_52 ( NULL , V_82 , 0 , & V_83 ,
V_49 ) ;
F_3 ( V_24 == NULL ) ;
F_53 ( V_24 ) ;
}
void T_2 F_54 ( struct V_21 * V_21 )
{
F_55 ( & V_21 -> V_84 , & V_85 ) ;
}
static void T_2 F_56 ( void )
{
struct V_3 * V_4 ;
const T_1 * V_86 ;
V_4 = F_57 ( NULL , NULL , L_10 ) ;
if ( ! V_4 )
return;
V_86 = F_6 ( V_4 , L_11 , NULL ) ;
if ( ! V_86 )
return;
V_16 = * V_86 ;
F_7 ( V_4 ) ;
}
void T_2 F_58 ( void )
{
int V_87 = - 1 ;
if ( F_59 ( V_88 ) )
V_87 = F_60 () ;
if ( V_87 < 0 )
V_87 = F_61 () ;
if ( V_87 < 0 ) {
F_37 ( L_12 ) ;
return;
}
V_89 . V_90 = V_17 -> V_90 ;
V_72 . V_91 = V_17 -> V_92 ;
V_87 = F_62 () ;
if ( V_87 < 0 )
V_87 = F_63 () ;
if ( V_87 < 0 )
F_37 ( L_13 ) ;
F_56 () ;
F_1 () ;
F_51 () ;
F_13 () ;
}
