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
V_28 | V_29 , L_6 , NULL ) ) ;
}
int T_2 F_20 ( void )
{
V_30 -> V_31 = V_17 -> V_31 ;
F_17 () ;
return F_21 ( V_32 ) ;
}
void F_22 ( void )
{
struct V_33 * V_34 = & F_23 ( V_33 ) ;
V_34 -> V_13 = 0 ;
V_17 -> V_18 ( 0 ) ;
V_17 -> V_35 () ;
}
void F_24 ( int V_36 )
{
F_22 () ;
V_17 -> V_37 () ;
if ( V_36 )
F_8 ( V_10 , 0 ) ;
}
void F_25 ( void )
{
int V_38 = F_26 () , V_39 = F_27 () ;
unsigned int V_40 , V_41 ;
if ( V_39 == V_9 )
F_1 () ;
V_17 -> V_18 ( 0 ) ;
F_8 ( V_10 , 0 ) ;
V_17 -> V_18 ( V_42 ) ;
F_28 (virq) {
struct V_43 * V_44 ;
struct V_45 * V_46 ;
long V_47 ;
unsigned long V_48 ;
struct V_21 * V_21 ;
if ( V_41 < V_49 )
continue;
if ( ! F_29 ( V_41 , V_24 ) )
continue;
V_40 = ( unsigned int ) F_30 ( V_41 ) ;
if ( V_40 == V_25 || V_40 == V_50 )
continue;
V_44 = F_31 ( V_41 ) ;
if ( ! V_44 || ! V_44 -> V_51 )
continue;
V_46 = F_32 ( V_44 ) ;
if ( ! V_46 || ! V_46 -> V_52 )
continue;
F_33 ( & V_44 -> V_53 , V_48 ) ;
V_47 = - 1 ;
V_21 = F_34 ( V_41 ) ;
if ( V_21 )
V_47 = V_21 -> V_54 ( V_21 , V_40 ) ;
if ( V_47 < 0 ) {
F_35 ( V_55 L_7 ,
V_56 , V_40 ) ;
goto V_57;
}
if ( V_47 != V_39 )
goto V_57;
if ( F_36 ( V_38 ) )
F_37 ( L_8 ,
V_41 , V_38 ) ;
F_38 ( & V_44 -> V_53 , V_48 ) ;
V_52 ( V_41 , V_58 ) ;
continue;
V_57:
F_38 ( & V_44 -> V_53 , V_48 ) ;
}
}
int F_39 ( unsigned int V_41 , const struct V_59 * V_59 ,
unsigned int V_60 )
{
if ( ! V_61 )
return V_9 ;
if ( ! F_40 ( V_32 , V_59 ) ) {
int V_47 = F_41 ( V_62 , V_59 ) ;
if ( V_47 < V_63 )
return F_4 ( V_47 ) ;
if ( V_60 )
return - 1 ;
}
if ( F_42 ( V_62 , V_64 ) )
return V_10 ;
return V_9 ;
}
static int F_43 ( struct V_65 * V_66 , struct V_3 * V_67 )
{
struct V_21 * V_21 ;
F_16 (ics, &ics_list, link)
if ( V_21 -> V_68 ( V_21 , V_67 ) )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_69 * V_70 ) { }
static void F_45 ( struct V_69 * V_70 ) { }
static int F_46 ( struct V_65 * V_66 , unsigned int V_41 ,
T_3 V_71 )
{
struct V_21 * V_21 ;
F_5 ( L_9 , V_41 , V_71 ) ;
F_47 ( V_24 , V_41 , V_71 ) ;
F_48 ( V_41 , V_72 ) ;
if ( V_71 == V_25 ) {
F_49 ( V_41 , & V_73 ,
V_74 ) ;
return 0 ;
}
F_16 (ics, &ics_list, link)
if ( V_21 -> V_75 ( V_21 , V_41 ) == 0 )
return 0 ;
return - V_76 ;
}
static int F_50 ( struct V_65 * V_66 , struct V_3 * V_77 ,
const T_1 * V_78 , unsigned int V_79 ,
T_3 * V_80 , unsigned int * V_81 )
{
* V_80 = V_78 [ 0 ] ;
* V_81 = V_82 ;
return 0 ;
}
static void T_2 F_51 ( void )
{
V_24 = F_52 ( NULL , V_83 , 0 , & V_84 ,
V_50 ) ;
F_3 ( V_24 == NULL ) ;
F_53 ( V_24 ) ;
}
void T_2 F_54 ( struct V_21 * V_21 )
{
F_55 ( & V_21 -> V_85 , & V_86 ) ;
}
static void T_2 F_56 ( void )
{
struct V_3 * V_4 ;
const T_1 * V_87 ;
V_4 = F_57 ( NULL , NULL , L_10 ) ;
if ( ! V_4 )
return;
V_87 = F_6 ( V_4 , L_11 , NULL ) ;
if ( ! V_87 )
return;
V_16 = * V_87 ;
F_7 ( V_4 ) ;
}
void T_2 F_58 ( void )
{
int V_88 = - 1 ;
if ( F_59 ( V_89 ) )
V_88 = F_60 () ;
if ( V_88 < 0 )
V_88 = F_61 () ;
if ( V_88 < 0 ) {
F_37 ( L_12 ) ;
return;
}
V_90 . V_91 = V_17 -> V_91 ;
V_73 . V_92 = V_17 -> V_93 ;
V_88 = F_62 () ;
if ( V_88 < 0 )
V_88 = F_63 () ;
if ( V_88 < 0 )
F_37 ( L_13 ) ;
F_56 () ;
F_1 () ;
F_51 () ;
F_13 () ;
}
