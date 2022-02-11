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
F_3 ( ! V_23 ) ;
F_3 ( F_20 ( V_23 , V_17 -> V_26 ,
V_27 | V_28 , L_6 , NULL ) ) ;
}
void T_3 F_21 ( void )
{
F_18 () ;
V_29 -> V_30 = V_17 -> V_30 ;
}
void F_22 ( void )
{
struct V_31 * V_32 = F_23 ( & V_31 ) ;
V_32 -> V_13 = 0 ;
V_17 -> V_18 ( 0 ) ;
V_17 -> V_33 () ;
}
void F_24 ( int V_34 )
{
F_22 () ;
V_17 -> V_35 () ;
if ( V_34 )
F_9 ( V_10 , 0 ) ;
}
void F_25 ( void )
{
int V_36 = F_26 () , V_37 = F_27 () ;
unsigned int V_38 , V_39 ;
struct V_40 * V_41 ;
if ( V_37 == V_9 )
F_1 () ;
V_17 -> V_18 ( 0 ) ;
F_9 ( V_10 , 0 ) ;
F_28 (virq, desc) {
struct V_42 * V_43 ;
long V_44 ;
unsigned long V_45 ;
struct V_21 * V_21 ;
if ( V_39 < V_46 )
continue;
if ( ! V_41 -> V_47 )
continue;
if ( V_41 -> V_48 . V_49 != V_24 )
continue;
V_38 = V_41 -> V_48 . V_50 ;
if ( V_38 == V_25 || V_38 == V_51 )
continue;
V_43 = F_29 ( V_41 ) ;
if ( ! V_43 || ! V_43 -> V_52 )
continue;
F_30 ( & V_41 -> V_53 , V_45 ) ;
V_44 = - 1 ;
V_21 = F_31 ( V_41 ) ;
if ( V_21 )
V_44 = V_21 -> V_54 ( V_21 , V_38 ) ;
if ( V_44 < 0 ) {
F_32 ( V_55 L_7 ,
V_56 , V_38 ) ;
goto V_57;
}
if ( V_44 != V_37 )
goto V_57;
if ( F_33 ( V_36 ) )
F_34 ( L_8 ,
V_39 , V_36 ) ;
F_35 ( & V_41 -> V_53 , V_45 ) ;
V_52 ( V_39 , V_58 ) ;
continue;
V_57:
F_35 ( & V_41 -> V_53 , V_45 ) ;
}
F_36 ( 5 ) ;
V_17 -> V_18 ( V_59 ) ;
}
int F_37 ( unsigned int V_39 , const struct V_60 * V_60 ,
unsigned int V_61 )
{
if ( ! V_62 )
return V_9 ;
if ( ! F_38 ( V_63 , V_60 ) ) {
int V_44 = F_39 ( V_64 , V_60 ) ;
if ( V_44 < V_65 )
return F_4 ( V_44 ) ;
if ( V_61 )
return - 1 ;
}
if ( F_40 ( V_64 , V_66 ) )
return V_10 ;
return V_9 ;
}
static int F_41 ( struct V_67 * V_68 , struct V_3 * V_69 ,
enum V_70 V_71 )
{
struct V_21 * V_21 ;
F_17 (ics, &ics_list, link)
if ( V_21 -> V_72 ( V_21 , V_69 ) )
return 1 ;
return 0 ;
}
static void F_42 ( struct V_48 * V_73 ) { }
static void F_43 ( struct V_48 * V_73 ) { }
static int F_44 ( struct V_67 * V_68 , unsigned int V_39 ,
T_4 V_74 )
{
struct V_21 * V_21 ;
F_5 ( L_9 , V_39 , V_74 ) ;
F_45 ( V_39 , V_75 ) ;
if ( V_74 == V_25 ) {
F_46 ( V_39 , & V_76 ,
V_77 ) ;
return 0 ;
}
F_17 (ics, &ics_list, link)
if ( V_21 -> V_78 ( V_21 , V_39 ) == 0 )
return 0 ;
return - V_79 ;
}
static int F_47 ( struct V_67 * V_68 , struct V_3 * V_80 ,
const T_1 * V_81 , unsigned int V_82 ,
T_4 * V_83 , unsigned int * V_84 )
{
* V_83 = V_81 [ 0 ] ;
if ( V_82 > 1 ) {
if ( V_81 [ 1 ] & 1 )
* V_84 = V_85 ;
else
* V_84 = V_86 ;
} else
* V_84 = V_85 ;
return 0 ;
}
int F_48 ( struct V_48 * V_73 , unsigned int V_87 )
{
if ( V_87 == V_88 || V_87 == V_89 )
V_87 = V_86 ;
if ( V_87 != V_86 &&
V_87 != V_85 )
return - V_79 ;
F_49 ( V_73 , V_87 ) ;
return V_90 ;
}
int F_50 ( struct V_48 * V_91 )
{
F_51 ( 0 ) ;
return 0 ;
}
static void T_3 F_52 ( void )
{
V_24 = F_53 ( NULL , & V_92 , NULL ) ;
F_3 ( V_24 == NULL ) ;
F_54 ( V_24 ) ;
}
void T_3 F_55 ( struct V_21 * V_21 )
{
F_56 ( & V_21 -> V_93 , & V_94 ) ;
}
static void T_3 F_57 ( void )
{
struct V_3 * V_4 ;
const T_2 * V_95 ;
V_4 = F_58 ( NULL , NULL , L_10 ) ;
if ( ! V_4 )
return;
V_95 = F_6 ( V_4 , L_11 , NULL ) ;
if ( ! V_95 )
return;
V_16 = F_8 ( * V_95 ) ;
F_7 ( V_4 ) ;
}
void T_3 F_59 ( void )
{
int V_96 = - 1 ;
if ( F_60 ( V_97 ) )
V_96 = F_61 () ;
if ( V_96 < 0 ) {
V_96 = F_62 () ;
if ( V_96 == - V_98 )
V_96 = F_63 () ;
}
if ( V_96 < 0 ) {
F_34 ( L_12 ) ;
return;
}
V_99 . V_100 = V_17 -> V_100 ;
V_76 . V_101 = V_17 -> V_102 ;
V_96 = F_64 () ;
if ( V_96 < 0 )
V_96 = F_65 () ;
if ( V_96 < 0 )
F_34 ( L_13 ) ;
F_57 () ;
F_1 () ;
F_52 () ;
F_14 () ;
}
