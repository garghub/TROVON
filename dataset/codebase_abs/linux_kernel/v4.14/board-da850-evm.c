static void F_1 ( struct V_1 * V_2 )
{
char * V_3 = V_4 . V_5 -> V_3 ;
T_1 V_6 ;
if ( ! strcmp ( V_2 -> V_7 , L_1 ) ) {
F_2 ( V_2 , 0 , V_8 , & V_6 , V_3 ) ;
if ( V_6 == V_8 )
F_3 ( L_2 ,
V_3 ) ;
}
}
static void F_4 ( void )
{
F_5 ( & V_9 ) ;
}
static void F_4 ( void ) { }
static void T_2 F_6 ( void )
{
void T_3 * V_10 ;
V_10 = F_7 ( V_11 , V_12 ) ;
F_8 ( F_9 ( V_10 + V_13 ) |
V_14 ,
V_10 + V_13 ) ;
F_10 ( V_10 ) ;
}
static inline void F_11 ( void )
{
int V_15 = 0 ;
if ( ! V_16 ) {
V_15 = F_12 ( V_17 ) ;
if ( V_15 )
F_13 ( L_3 ,
V_18 , V_15 ) ;
V_15 = F_12 ( V_19 ) ;
if ( V_15 )
F_13 ( L_4 ,
V_18 , V_15 ) ;
F_6 () ;
F_14 ( V_20 ,
F_15 ( V_20 ) ) ;
if ( F_16 ( & V_21 ) )
F_13 ( L_5 , V_18 ) ;
}
}
static inline void F_17 ( int V_22 )
{
struct V_4 * V_23 = & V_4 ;
V_23 -> V_5 -> V_24 = 1 ;
F_18 ( V_22 , 0 ) ;
}
static inline void F_17 ( int V_22 ) { }
static void F_19 ( unsigned V_25 )
{
int V_26 ;
struct V_27 * V_28 ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_28 = & V_30 [ V_26 ] ;
V_28 -> V_31 = V_32 - V_26 ;
V_28 -> V_33 = V_34 [ V_35 + V_26 ] ;
V_28 -> V_25 = V_25 + V_35 + V_26 ;
}
}
static inline void F_20 ( int V_36 )
{
F_18 ( V_36 , 0 ) ;
}
static inline void F_20 ( int V_36 ) { }
static int F_21 ( struct V_37 * V_38 , unsigned V_25 ,
unsigned V_39 , void * V_40 )
{
int V_41 , V_42 , V_43 , V_15 ;
V_41 = V_25 + V_44 ;
V_42 = V_25 + V_45 ;
V_43 = V_25 + V_46 ;
V_15 = F_22 ( V_41 , V_34 [ V_44 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_41 ) ;
goto V_47;
}
V_15 = F_22 ( V_42 , V_34 [ V_45 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_42 ) ;
goto V_48;
}
V_15 = F_22 ( V_43 , V_34 [ V_46 ] ) ;
if ( V_15 ) {
F_13 ( L_6 , V_43 ) ;
goto V_49;
}
F_23 ( V_41 , 1 ) ;
F_23 ( V_42 , 1 ) ;
F_23 ( V_43 , 1 ) ;
F_19 ( V_25 ) ;
V_15 = F_24 ( & V_50 ) ;
if ( V_15 ) {
F_13 ( L_7 ) ;
goto V_51;
}
F_3 ( L_8 ) ;
F_11 () ;
F_17 ( V_41 ) ;
F_20 ( V_43 ) ;
return 0 ;
V_51:
F_25 ( V_43 ) ;
V_49:
F_25 ( V_42 ) ;
V_48:
F_25 ( V_41 ) ;
V_47:
return V_15 ;
}
static int F_26 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 , void * V_40 )
{
F_27 ( & V_50 ) ;
F_18 ( V_25 + V_46 , 1 ) ;
F_18 ( V_25 + V_45 , 1 ) ;
F_18 ( V_25 + V_44 , 1 ) ;
F_25 ( V_25 + V_46 ) ;
F_25 ( V_25 + V_45 ) ;
F_25 ( V_25 + V_44 ) ;
return 0 ;
}
static void F_28 ( unsigned V_25 )
{
int V_26 ;
struct V_27 * V_28 ;
V_28 = & V_52 [ 0 ] ;
V_28 -> V_33 = V_53 [ V_54 ] ;
V_28 -> V_25 = V_25 + V_54 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
V_28 = & V_52 [ V_26 + 1 ] ;
V_28 -> V_31 = V_56 + V_26 ;
V_28 -> V_33 = V_53 [ V_57 + V_26 ] ;
V_28 -> V_25 = V_25 + V_57 + V_26 ;
}
}
static void F_29 ( unsigned V_25 )
{
int V_26 ;
struct V_58 * V_59 ;
for ( V_26 = 0 ; V_26 < V_60 ; V_26 ++ ) {
V_59 = & V_61 [ V_26 ] ;
V_59 -> V_25 = V_25 + V_62 + V_26 ;
V_59 -> V_7 =
V_53 [ V_62 + V_26 ] ;
}
}
static int F_30 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 ,
void * V_40 )
{
int V_15 ;
F_28 ( V_25 ) ;
V_15 = F_24 ( & V_63 ) ;
if ( V_15 ) {
F_13 ( L_9 ) ;
goto V_64;
}
F_29 ( V_25 ) ;
V_15 = F_24 ( & V_65 ) ;
if ( V_15 ) {
F_13 ( L_10 ) ;
goto V_66;
}
return 0 ;
V_66:
F_27 ( & V_63 ) ;
V_64:
return V_15 ;
}
static int F_31 ( struct V_37 * V_38 ,
unsigned V_25 , unsigned V_39 , void * V_40 )
{
F_27 ( & V_65 ) ;
F_27 ( & V_63 ) ;
return 0 ;
}
static void F_32 ( int V_67 )
{
F_33 ( V_68 , V_67 ) ;
F_33 ( V_69 , V_67 ) ;
}
static int F_34 ( void )
{
int V_70 ;
V_70 = F_22 ( V_68 , L_11 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_22 ( V_69 , L_12 ) ;
if ( V_70 < 0 ) {
F_25 ( V_68 ) ;
return V_70 ;
}
F_23 ( V_68 , 0 ) ;
F_23 ( V_69 , 0 ) ;
F_32 ( 0 ) ;
F_32 ( 1 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( 1 , V_71 ,
F_15 ( V_71 ) ) ;
}
static int T_2 F_37 ( void )
{
void T_3 * V_72 ;
int V_15 ;
T_4 V_67 ;
struct V_4 * V_23 = & V_4 ;
T_5 V_24 = V_23 -> V_5 -> V_24 ;
if ( ! F_38 () )
return 0 ;
V_72 = F_39 ( V_73 ) ;
V_67 = F_40 ( V_72 ) ;
if ( V_24 ) {
V_67 |= F_41 ( 8 ) ;
V_15 = F_12 ( V_74 ) ;
F_3 ( L_13
L_14 ) ;
} else {
V_67 &= ~ F_41 ( 8 ) ;
V_15 = F_12 ( V_75 ) ;
F_3 ( L_15
L_14 ) ;
}
if ( V_15 )
F_13 ( L_16 ,
V_18 , V_15 ) ;
F_42 ( V_67 , V_72 ) ;
V_15 = F_43 ( V_76 ) ;
if ( V_15 )
F_13 ( L_17 , V_18 ) ;
V_15 = F_22 ( V_77 , L_18 ) ;
if ( V_15 ) {
F_13 ( L_19 , V_77 ) ;
return V_15 ;
}
F_23 ( V_77 , V_24 ) ;
V_23 -> V_5 -> V_78 = V_79 ;
V_15 = F_44 () ;
if ( V_15 )
F_13 ( L_20 , V_18 , V_15 ) ;
return 0 ;
}
static T_2 int F_45 ( void )
{
switch ( V_80 & 0xF ) {
case 3 :
V_81 = 456000 ;
break;
case 2 :
V_81 = 408000 ;
break;
case 1 :
V_81 = 372000 ;
break;
}
return F_46 ( L_21 ) ;
}
static T_2 int F_45 ( void ) { return 0 ; }
static T_2 void F_47 ( void )
{
int V_15 ;
V_15 = F_48 () ;
if ( V_15 )
F_13 ( L_22 , V_15 ) ;
V_15 = F_12 ( V_82 ) ;
if ( V_15 )
F_13 ( L_23 ,
V_15 ) ;
V_15 = F_49 ( & V_83 ) ;
if ( V_15 )
F_13 ( L_24 , V_15 ) ;
V_15 = F_12 ( V_84 ) ;
if ( V_15 )
F_13 ( L_25 ,
V_15 ) ;
V_15 = F_50 ( & V_85 ) ;
if ( V_15 )
F_13 ( L_26 , V_15 ) ;
}
static T_2 void F_47 ( void ) {}
static T_2 void F_51 ( void )
{
int V_15 ;
V_15 = F_52 () ;
if ( V_15 )
F_13 ( L_27 , V_18 , V_15 ) ;
V_15 = F_53 () ;
if ( V_15 )
F_13 ( L_28 , V_18 , V_15 ) ;
F_54 ( 0 , V_86 , F_15 ( V_86 ) ) ;
V_15 = F_35 () ;
if ( V_15 )
F_13 ( L_29 , V_18 , V_15 ) ;
V_15 = F_55 ( V_87 ) ;
if ( V_15 )
F_13 ( L_30 , V_18 , V_15 ) ;
V_15 = F_12 ( V_88 ) ;
if ( V_15 )
F_13 ( L_31 , V_18 , V_15 ) ;
V_15 = F_56 ( 0 , & V_89 ) ;
if ( V_15 )
F_13 ( L_32 , V_18 , V_15 ) ;
V_15 = F_57 () ;
if ( V_15 )
F_13 ( L_33 ,
V_18 , V_15 ) ;
if ( V_16 ) {
V_15 = F_12 ( V_90 ) ;
if ( V_15 )
F_13 ( L_34 ,
V_18 , V_15 ) ;
F_58 ( & V_91 ) ;
V_15 = F_59 ( & V_92 ) ;
if ( V_15 )
F_13 ( L_35 ,
V_18 , V_15 ) ;
}
F_60 ( V_93 ) ;
F_36 ( 1 , V_94 ,
F_15 ( V_94 ) ) ;
F_42 ( 0 , F_61 ( V_95 ) + 0x30 ) ;
F_42 ( 0 , F_61 ( V_96 ) + 0x30 ) ;
V_15 = F_12 ( V_97 ) ;
if ( V_15 )
F_13 ( L_36 , V_18 , V_15 ) ;
V_98 . V_99 = F_62 () ;
F_63 ( 0 , & V_98 ) ;
V_15 = F_12 ( V_100 ) ;
if ( V_15 )
F_13 ( L_37 , V_18 , V_15 ) ;
V_15 = F_64 () ;
if ( V_15 )
F_13 ( L_38 ,
V_15 ) ;
V_15 = F_12 ( V_101 ) ;
if ( V_15 )
F_13 ( L_39 ,
V_18 , V_15 ) ;
V_15 = F_34 () ;
if ( V_15 )
F_13 ( L_40 , V_18 , V_15 ) ;
V_102 . V_103 = F_32 ,
V_15 = F_65 ( & V_102 ) ;
if ( V_15 )
F_13 ( L_41 , V_18 , V_15 ) ;
V_15 = F_66 () ;
if ( V_15 )
F_13 ( L_42 , V_18 , V_15 ) ;
V_15 = F_45 () ;
if ( V_15 )
F_13 ( L_43 , V_18 , V_15 ) ;
V_15 = F_67 () ;
if ( V_15 )
F_13 ( L_44 , V_18 , V_15 ) ;
F_68 () ;
F_47 () ;
V_15 = F_69 ( V_104 ,
F_15 ( V_104 ) ) ;
if ( V_15 )
F_13 ( L_45 , V_18 ,
V_15 ) ;
V_15 = F_70 ( 1 , F_15 ( V_104 ) ) ;
if ( V_15 )
F_13 ( L_46 , V_18 , V_15 ) ;
V_15 = F_71 ( V_105 ) ;
if ( V_15 )
F_13 ( L_47 , V_18 , V_15 ) ;
F_4 () ;
V_15 = F_72 () ;
if ( V_15 )
F_13 ( L_48 ,
V_18 , V_15 ) ;
}
static int T_2 F_73 ( void )
{
if ( ! F_38 () )
return 0 ;
return F_74 ( L_49 , 2 , L_50 ) ;
}
static void T_2 F_75 ( void )
{
F_76 () ;
}
