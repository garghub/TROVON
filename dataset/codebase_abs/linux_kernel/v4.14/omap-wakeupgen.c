static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 )
{
return F_2 ( V_3 + V_4 +
( V_2 * V_5 ) + ( V_1 * 4 ) ) ;
}
static inline void F_3 ( T_1 V_6 , T_2 V_1 , T_1 V_2 )
{
F_4 ( V_6 , V_3 + V_4 +
( V_2 * V_5 ) + ( V_1 * 4 ) ) ;
}
static inline void F_5 ( T_1 V_6 , T_1 V_7 , T_2 V_1 )
{
F_4 ( V_6 , V_8 + V_7 + ( V_1 * 4 ) ) ;
}
static inline int F_6 ( T_1 V_9 , T_1 * V_10 , T_2 * V_11 )
{
* V_11 = V_9 >> 5 ;
* V_10 = V_9 %= 32 ;
return 0 ;
}
static void F_7 ( unsigned int V_9 , unsigned int V_2 )
{
T_1 V_6 , V_12 ;
T_2 V_13 ;
if ( F_6 ( V_9 , & V_12 , & V_13 ) )
return;
V_6 = F_1 ( V_13 , V_2 ) ;
V_6 &= ~ F_8 ( V_12 ) ;
F_3 ( V_6 , V_13 , V_2 ) ;
}
static void F_9 ( unsigned int V_9 , unsigned int V_2 )
{
T_1 V_6 , V_12 ;
T_2 V_13 ;
if ( F_6 ( V_9 , & V_12 , & V_13 ) )
return;
V_6 = F_1 ( V_13 , V_2 ) ;
V_6 |= F_8 ( V_12 ) ;
F_3 ( V_6 , V_13 , V_2 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
unsigned long V_16 ;
F_11 ( & V_17 , V_16 ) ;
F_7 ( V_15 -> V_18 , V_19 [ V_15 -> V_18 ] ) ;
F_12 ( & V_17 , V_16 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
unsigned long V_16 ;
F_11 ( & V_17 , V_16 ) ;
F_9 ( V_15 -> V_18 , V_19 [ V_15 -> V_18 ] ) ;
F_12 ( & V_17 , V_16 ) ;
F_15 ( V_15 ) ;
}
static void F_16 ( unsigned int V_2 )
{
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_17 ( V_21 , V_2 ) [ V_13 ] = F_1 ( V_13 , V_2 ) ;
}
static void F_18 ( unsigned int V_2 )
{
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_3 ( F_17 ( V_21 , V_2 ) [ V_13 ] , V_13 , V_2 ) ;
}
static void F_19 ( unsigned int V_2 , unsigned int V_22 )
{
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_3 ( V_22 , V_13 , V_2 ) ;
}
static void F_20 ( unsigned int V_2 , unsigned int V_23 )
{
unsigned long V_16 ;
F_11 ( & V_17 , V_16 ) ;
if ( V_23 ) {
F_16 ( V_2 ) ;
F_19 ( V_2 , V_24 ) ;
} else {
F_19 ( V_2 , V_25 ) ;
F_18 ( V_2 ) ;
}
F_12 ( & V_17 , V_16 ) ;
}
static inline void F_21 ( void )
{
T_1 V_13 , V_6 ;
if ( F_22 () == V_26 )
return;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_6 = F_1 ( V_13 , 0 ) ;
F_5 ( V_6 , V_27 , V_13 ) ;
V_6 = F_1 ( V_13 , 1 ) ;
F_5 ( V_6 , V_28 , V_13 ) ;
F_5 ( 0x0 , V_29 , V_13 ) ;
F_5 ( 0x0 , V_30 , V_13 ) ;
}
V_6 = F_2 ( V_3 + V_31 ) ;
F_4 ( V_6 , V_8 + V_32 ) ;
V_6 = F_2 ( V_3 + V_33 ) ;
F_4 ( V_6 , V_8 + V_34 ) ;
V_6 = F_2 ( V_3 + V_35 ) ;
F_4 ( V_6 , V_8 + V_36 ) ;
V_6 = F_2 ( V_3 + V_37 ) ;
F_4 ( V_6 , V_8 + V_38 ) ;
V_6 = F_2 ( V_8 + V_39 ) ;
V_6 |= V_40 ;
F_4 ( V_6 , V_8 + V_39 ) ;
}
static inline void F_23 ( void )
{
T_1 V_13 , V_6 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_6 = F_1 ( V_13 , 0 ) ;
F_5 ( V_6 , V_41 , V_13 ) ;
V_6 = F_1 ( V_13 , 1 ) ;
F_5 ( V_6 , V_42 , V_13 ) ;
F_5 ( 0x0 , V_43 , V_13 ) ;
F_5 ( 0x0 , V_44 , V_13 ) ;
}
V_6 = F_2 ( V_3 + V_31 ) ;
F_4 ( V_6 , V_8 + V_45 ) ;
V_6 = F_2 ( V_3 + V_31 ) ;
F_4 ( V_6 , V_8 + V_46 ) ;
V_6 = F_2 ( V_8 + V_47 ) ;
V_6 |= V_40 ;
F_4 ( V_6 , V_8 + V_47 ) ;
}
static inline void F_24 ( void )
{
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
V_48 [ V_13 ] = F_1 ( V_13 , 0 ) ;
F_3 ( 0 , V_13 , V_49 ) ;
}
}
static void F_25 ( void )
{
if ( F_26 () )
return;
if ( ! V_8 )
V_8 = F_27 () ;
if ( V_50 && V_50 -> V_51 )
V_50 -> V_51 () ;
}
static void F_28 ( void )
{
T_1 V_6 ;
T_1 V_7 = V_39 ;
if ( F_26 () )
return;
if ( F_29 () )
V_7 = V_47 ;
V_6 = F_2 ( V_8 + V_7 ) ;
V_6 &= ~ V_40 ;
F_4 ( V_6 , V_8 + V_7 ) ;
}
static void F_30 ( void )
{
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ )
F_3 ( V_48 [ V_13 ] , V_13 , V_49 ) ;
}
static void F_31 ( void )
{
if ( V_50 && V_50 -> V_52 )
V_50 -> V_52 () ;
}
static void F_32 ( void )
{
T_1 V_53 ;
V_53 = F_33 ( V_54 ,
V_55 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_53 != V_56 )
F_34 ( L_1 ) ;
}
static int F_35 ( unsigned int V_2 )
{
F_20 ( V_2 , 0 ) ;
return 0 ;
}
static int F_36 ( unsigned int V_2 )
{
F_20 ( V_2 , 1 ) ;
return 0 ;
}
static void T_3 F_37 ( void )
{
F_38 ( V_57 , L_2 ,
F_35 , NULL ) ;
F_38 ( V_58 ,
L_3 , NULL ,
F_36 ) ;
}
static void T_3 F_37 ( void )
{}
static int F_39 ( struct V_59 * V_60 , unsigned long V_61 , void * V_62 )
{
switch ( V_61 ) {
case V_63 :
if ( F_40 () == V_64 )
F_25 () ;
else
F_32 () ;
break;
case V_65 :
if ( F_40 () == V_64 )
F_31 () ;
break;
}
return V_66 ;
}
static void T_3 F_41 ( void )
{
if ( ! F_42 ( V_67 ) )
F_43 ( & V_68 ) ;
}
static void T_3 F_41 ( void )
{}
void T_4 * F_44 ( void )
{
return V_3 ;
}
int F_45 ( void )
{
return V_69 ;
}
static int F_46 ( struct V_70 * V_15 ,
struct V_71 * V_72 ,
unsigned long * V_18 ,
unsigned int * type )
{
if ( F_47 ( V_72 -> V_73 ) ) {
if ( V_72 -> V_74 != 3 )
return - V_75 ;
if ( V_72 -> V_76 [ 0 ] != 0 )
return - V_75 ;
* V_18 = V_72 -> V_76 [ 1 ] ;
* type = V_72 -> V_76 [ 2 ] ;
return 0 ;
}
return - V_75 ;
}
static int F_48 ( struct V_70 * V_77 ,
unsigned int V_78 ,
unsigned int V_79 , void * V_80 )
{
struct V_71 * V_72 = V_80 ;
struct V_71 V_81 ;
T_5 V_18 ;
int V_13 ;
if ( V_72 -> V_74 != 3 )
return - V_75 ;
if ( V_72 -> V_76 [ 0 ] != 0 )
return - V_75 ;
V_18 = V_72 -> V_76 [ 1 ] ;
if ( V_18 >= V_82 )
return - V_75 ;
for ( V_13 = 0 ; V_13 < V_79 ; V_13 ++ )
F_49 ( V_77 , V_78 + V_13 , V_18 + V_13 ,
& V_83 , NULL ) ;
V_81 = * V_72 ;
V_81 . V_73 = V_77 -> V_84 -> V_73 ;
return F_50 ( V_77 , V_78 , V_79 ,
& V_81 ) ;
}
static int T_3 F_51 ( struct V_85 * V_86 ,
struct V_85 * V_84 )
{
struct V_70 * V_87 , * V_77 ;
int V_13 ;
unsigned int V_88 = F_52 () ;
T_1 V_6 ;
if ( ! V_84 ) {
F_34 ( L_4 , V_86 ) ;
return - V_89 ;
}
V_87 = F_53 ( V_84 ) ;
if ( ! V_87 ) {
F_34 ( L_5 , V_86 ) ;
return - V_90 ;
}
if ( F_22 () == V_26 ) {
F_54 ( 1 , L_6 ) ;
return - V_91 ;
}
V_3 = F_55 ( V_86 , 0 ) ;
if ( F_56 ( ! V_3 ) )
return - V_92 ;
if ( F_57 () ) {
V_20 = V_93 ;
V_94 = V_95 ;
V_69 = 1 ;
V_50 = & V_96 ;
} else if ( F_29 () ) {
V_50 = & V_97 ;
} else if ( F_58 () ) {
V_20 = V_98 ;
V_94 = V_99 ;
V_50 = & V_100 ;
}
V_77 = F_59 ( V_87 , 0 , V_94 ,
V_86 , & V_101 ,
NULL ) ;
if ( ! V_77 ) {
F_60 ( V_3 ) ;
return - V_92 ;
}
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
F_3 ( 0 , V_13 , V_49 ) ;
if ( ! F_58 () )
F_3 ( 0 , V_13 , V_102 ) ;
}
for ( V_13 = 0 ; V_13 < V_94 ; V_13 ++ )
V_19 [ V_13 ] = V_88 ;
if ( F_29 () || F_26 () ) {
V_6 = F_61 ( V_3 + V_103 ) ;
V_6 |= F_8 ( 5 ) ;
F_62 ( V_104 , V_6 ) ;
}
F_37 () ;
F_41 () ;
return 0 ;
}
