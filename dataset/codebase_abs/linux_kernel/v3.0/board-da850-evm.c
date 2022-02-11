static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
F_3 ( F_4 ( V_1 + V_4 ) |
V_5 ,
V_1 + V_4 ) ;
F_5 ( V_1 ) ;
}
static inline void F_6 ( void )
{
int V_6 = 0 ;
if ( ! V_7 ) {
V_6 = F_7 ( V_8 ) ;
if ( V_6 )
F_8 ( L_1
L_2 , V_6 ) ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 )
F_8 ( L_3 ,
V_6 ) ;
F_1 () ;
F_9 ( V_10 ,
F_10 ( V_10 ) ) ;
}
}
static inline void F_11 ( int V_11 )
{
struct V_12 * V_13 = & V_12 ;
V_13 -> V_14 -> V_15 = 1 ;
F_12 ( V_11 , 0 ) ;
}
static inline void F_11 ( int V_11 ) { }
static void F_13 ( unsigned V_16 )
{
int V_17 ;
struct V_18 * V_19 ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
V_19 = & V_21 [ V_17 ] ;
V_19 -> V_22 = V_23 - V_17 ;
V_19 -> V_24 = ( char * )
V_25 [ V_26 + V_17 ] ;
V_19 -> V_16 = V_16 + V_26 + V_17 ;
}
}
static int F_14 ( struct V_27 * V_28 , unsigned V_16 ,
unsigned V_29 , void * V_30 )
{
int V_31 , V_32 , V_33 , V_6 ;
V_31 = V_16 + V_34 ;
V_32 = V_16 + V_35 ;
V_33 = V_16 + V_36 ;
V_6 = F_15 ( V_31 , V_25 [ V_34 ] ) ;
if ( V_6 ) {
F_8 ( L_4 , V_31 ) ;
goto V_37;
}
V_6 = F_15 ( V_32 , V_25 [ V_35 ] ) ;
if ( V_6 ) {
F_8 ( L_4 , V_32 ) ;
goto V_38;
}
V_6 = F_15 ( V_33 , V_25 [ V_36 ] ) ;
if ( V_6 ) {
F_8 ( L_4 , V_33 ) ;
goto V_39;
}
F_16 ( V_31 , 1 ) ;
F_16 ( V_32 , 1 ) ;
F_16 ( V_33 , 1 ) ;
F_13 ( V_16 ) ;
V_6 = F_17 ( & V_40 ) ;
if ( V_6 ) {
F_8 ( L_5 ) ;
goto V_41;
}
F_18 ( L_6 ) ;
F_6 () ;
F_11 ( V_31 ) ;
return 0 ;
V_41:
F_19 ( V_33 ) ;
V_39:
F_19 ( V_32 ) ;
V_38:
F_19 ( V_31 ) ;
V_37:
return V_6 ;
}
static int F_20 ( struct V_27 * V_28 ,
unsigned V_16 , unsigned V_29 , void * V_30 )
{
F_21 ( & V_40 ) ;
F_12 ( V_16 + V_36 , 1 ) ;
F_12 ( V_16 + V_35 , 1 ) ;
F_12 ( V_16 + V_34 , 1 ) ;
F_19 ( V_16 + V_36 ) ;
F_19 ( V_16 + V_35 ) ;
F_19 ( V_16 + V_34 ) ;
return 0 ;
}
static void F_22 ( unsigned V_16 )
{
int V_17 ;
struct V_18 * V_19 ;
V_19 = & V_42 [ 0 ] ;
V_19 -> V_24 = ( char * )
V_43 [ V_44 ] ;
V_19 -> V_16 = V_16 + V_44 ;
for ( V_17 = 0 ; V_17 < V_45 ; V_17 ++ ) {
V_19 = & V_42 [ V_17 + 1 ] ;
V_19 -> V_22 = V_46 + V_17 ;
V_19 -> V_24 = ( char * )
V_43 [ V_47 + V_17 ] ;
V_19 -> V_16 = V_16 + V_47 + V_17 ;
}
}
static void F_23 ( unsigned V_16 )
{
int V_17 ;
struct V_48 * V_49 ;
for ( V_17 = 0 ; V_17 < V_50 ; V_17 ++ ) {
V_49 = & V_51 [ V_17 ] ;
V_49 -> V_16 = V_16 + V_52 + V_17 ;
V_49 -> V_53 =
V_43 [ V_52 + V_17 ] ;
}
}
static int F_24 ( struct V_27 * V_28 ,
unsigned V_16 , unsigned V_29 ,
void * V_30 )
{
int V_6 ;
F_22 ( V_16 ) ;
V_6 = F_17 ( & V_54 ) ;
if ( V_6 ) {
F_8 ( L_7 ) ;
goto V_55;
}
F_23 ( V_16 ) ;
V_6 = F_17 ( & V_56 ) ;
if ( V_6 ) {
F_8 ( L_8 ) ;
goto V_57;
}
return 0 ;
V_57:
F_21 ( & V_54 ) ;
V_55:
return V_6 ;
}
static int F_25 ( struct V_27 * V_28 ,
unsigned V_16 , unsigned V_29 , void * V_30 )
{
F_21 ( & V_56 ) ;
F_21 ( & V_54 ) ;
return 0 ;
}
static int F_26 ( int V_58 )
{
return F_27 ( V_59 ) ;
}
static int F_28 ( int V_58 )
{
return ! F_27 ( V_60 ) ;
}
static void F_29 ( int V_61 )
{
F_30 ( V_62 , V_61 ) ;
F_30 ( V_63 , V_61 ) ;
}
static int F_31 ( void )
{
int V_64 ;
V_64 = F_15 ( V_62 , L_9 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_15 ( V_63 , L_10 ) ;
if ( V_64 < 0 ) {
F_19 ( V_62 ) ;
return V_64 ;
}
F_16 ( V_62 , 0 ) ;
F_16 ( V_63 , 0 ) ;
F_29 ( 0 ) ;
F_29 ( 1 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( 1 , V_65 ,
F_10 ( V_65 ) ) ;
}
static int T_1 F_34 ( void )
{
void T_2 * V_66 ;
int V_6 ;
T_3 V_61 ;
struct V_12 * V_13 = & V_12 ;
T_4 V_15 = V_13 -> V_14 -> V_15 ;
if ( ! F_35 () )
return 0 ;
V_66 = F_36 ( V_67 ) ;
V_61 = F_37 ( V_66 ) ;
if ( V_15 ) {
V_61 |= F_38 ( 8 ) ;
V_6 = F_7 ( V_68 ) ;
F_18 ( L_11
L_12 ) ;
} else {
V_61 &= ~ F_38 ( 8 ) ;
V_6 = F_7 ( V_69 ) ;
F_18 ( L_13
L_12 ) ;
}
if ( V_6 )
F_8 ( L_14 ,
V_6 ) ;
F_39 ( V_61 , V_66 ) ;
V_6 = F_40 ( V_70 ) ;
if ( V_6 )
F_8 ( L_15
L_16 ) ;
V_6 = F_15 ( V_71 , L_17 ) ;
if ( V_6 ) {
F_8 ( L_18 ,
V_71 ) ;
return V_6 ;
}
F_16 ( V_71 , V_15 ) ;
V_13 -> V_14 -> V_72 = V_73 ;
V_6 = F_41 () ;
if ( V_6 )
F_8 ( L_19 ,
V_6 ) ;
return 0 ;
}
static T_1 int F_42 ( void )
{
switch ( V_74 & 0xF ) {
case 3 :
V_75 = 456000 ;
break;
case 2 :
V_75 = 408000 ;
break;
case 1 :
V_75 = 372000 ;
break;
}
return F_43 ( L_20 ) ;
}
static T_1 int F_42 ( void ) { return 0 ; }
static T_1 void F_44 ( void )
{
int V_6 ;
V_6 = F_32 () ;
if ( V_6 )
F_8 ( L_21 ,
V_6 ) ;
V_6 = F_45 ( V_76 ) ;
if ( V_6 )
F_8 ( L_22 ,
V_6 ) ;
V_6 = F_7 ( V_77 ) ;
if ( V_6 )
F_8 ( L_23 ,
V_6 ) ;
V_6 = F_46 ( 0 , & V_78 ) ;
if ( V_6 )
F_8 ( L_24 ,
V_6 ) ;
V_6 = F_47 () ;
if ( V_6 )
F_8 ( L_25 ,
V_6 ) ;
if ( V_7 ) {
V_6 = F_7 ( V_79 ) ;
if ( V_6 )
F_8 ( L_26
L_27 , V_6 ) ;
V_6 = F_15 ( V_60 , L_28 ) ;
if ( V_6 )
F_8 ( L_29 ,
V_60 ) ;
F_48 ( V_60 ) ;
V_6 = F_15 ( V_59 , L_30 ) ;
if ( V_6 )
F_8 ( L_29 ,
V_59 ) ;
F_48 ( V_59 ) ;
V_6 = F_49 ( & V_80 ) ;
if ( V_6 )
F_8 ( L_31
L_27 , V_6 ) ;
}
F_50 ( & V_81 ) ;
F_33 ( 1 , V_82 ,
F_10 ( V_82 ) ) ;
F_39 ( 0 , F_51 ( V_83 ) + 0x30 ) ;
F_39 ( 0 , F_51 ( V_84 ) + 0x30 ) ;
V_6 = F_7 ( V_85 ) ;
if ( V_6 )
F_8 ( L_32 ,
V_6 ) ;
F_52 ( 0 , & V_86 ) ;
V_6 = F_7 ( V_87 ) ;
if ( V_6 )
F_8 ( L_33 ,
V_6 ) ;
V_6 = F_7 ( V_88 ) ;
if ( V_6 )
F_8 ( L_34
L_35 , V_6 ) ;
V_6 = F_31 () ;
if ( V_6 )
F_8 ( L_36 ,
V_6 ) ;
V_89 . V_90 = F_29 ,
V_6 = F_53 ( & V_89 ) ;
if ( V_6 )
F_8 ( L_37 ,
V_6 ) ;
V_6 = F_54 () ;
if ( V_6 )
F_8 ( L_38 , V_6 ) ;
V_6 = F_42 () ;
if ( V_6 )
F_8 ( L_39 ,
V_6 ) ;
V_6 = F_55 () ;
if ( V_6 )
F_8 ( L_40 ,
V_6 ) ;
V_6 = F_56 ( & V_91 ) ;
if ( V_6 )
F_8 ( L_41 ,
V_6 ) ;
V_6 = F_57 ( 1 , V_92 ,
F_10 ( V_92 ) ) ;
if ( V_6 )
F_8 ( L_42 ,
V_6 ) ;
}
static int T_1 F_58 ( void )
{
if ( ! F_35 () )
return 0 ;
return F_59 ( L_43 , 2 , L_44 ) ;
}
static void T_1 F_60 ( void )
{
F_61 () ;
}
