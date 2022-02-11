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
static void F_24 ( void )
{
if ( F_25 () )
return;
if ( ! V_8 )
V_8 = F_26 () ;
if ( F_27 () )
F_23 () ;
else
F_21 () ;
}
static void F_28 ( void )
{
T_1 V_6 ;
T_1 V_7 = V_39 ;
if ( F_25 () )
return;
if ( F_27 () )
V_7 = V_47 ;
V_6 = F_2 ( V_8 + V_7 ) ;
V_6 &= ~ V_40 ;
F_4 ( V_6 , V_8 + V_7 ) ;
}
static void F_29 ( void )
{
T_1 V_48 ;
V_48 = F_30 ( V_49 ,
V_50 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_48 != V_51 )
F_31 ( L_1 ) ;
}
static int F_32 ( unsigned int V_2 )
{
F_20 ( V_2 , 0 ) ;
return 0 ;
}
static int F_33 ( unsigned int V_2 )
{
F_20 ( V_2 , 1 ) ;
return 0 ;
}
static void T_3 F_34 ( void )
{
F_35 ( V_52 , L_2 ,
F_32 , NULL ) ;
F_35 ( V_53 ,
L_3 , NULL ,
F_33 ) ;
}
static void T_3 F_34 ( void )
{}
static int F_36 ( struct V_54 * V_55 , unsigned long V_56 , void * V_57 )
{
switch ( V_56 ) {
case V_58 :
if ( F_37 () == V_59 )
F_24 () ;
else
F_29 () ;
break;
case V_60 :
if ( F_37 () == V_59 )
F_28 () ;
break;
}
return V_61 ;
}
static void T_3 F_38 ( void )
{
if ( ! F_39 ( V_62 ) )
F_40 ( & V_63 ) ;
}
static void T_3 F_38 ( void )
{}
void T_4 * F_41 ( void )
{
return V_3 ;
}
int F_42 ( void )
{
return V_64 ;
}
static int F_43 ( struct V_65 * V_15 ,
struct V_66 * V_67 ,
unsigned long * V_18 ,
unsigned int * type )
{
if ( F_44 ( V_67 -> V_68 ) ) {
if ( V_67 -> V_69 != 3 )
return - V_70 ;
if ( V_67 -> V_71 [ 0 ] != 0 )
return - V_70 ;
* V_18 = V_67 -> V_71 [ 1 ] ;
* type = V_67 -> V_71 [ 2 ] ;
return 0 ;
}
return - V_70 ;
}
static int F_45 ( struct V_65 * V_72 ,
unsigned int V_73 ,
unsigned int V_74 , void * V_75 )
{
struct V_66 * V_67 = V_75 ;
struct V_66 V_76 ;
T_5 V_18 ;
int V_13 ;
if ( V_67 -> V_69 != 3 )
return - V_70 ;
if ( V_67 -> V_71 [ 0 ] != 0 )
return - V_70 ;
V_18 = V_67 -> V_71 [ 1 ] ;
if ( V_18 >= V_77 )
return - V_70 ;
for ( V_13 = 0 ; V_13 < V_74 ; V_13 ++ )
F_46 ( V_72 , V_73 + V_13 , V_18 + V_13 ,
& V_78 , NULL ) ;
V_76 = * V_67 ;
V_76 . V_68 = V_72 -> V_79 -> V_68 ;
return F_47 ( V_72 , V_73 , V_74 ,
& V_76 ) ;
}
static int T_3 F_48 ( struct V_80 * V_81 ,
struct V_80 * V_79 )
{
struct V_65 * V_82 , * V_72 ;
int V_13 ;
unsigned int V_83 = F_49 () ;
T_1 V_6 ;
if ( ! V_79 ) {
F_31 ( L_4 , V_81 -> V_84 ) ;
return - V_85 ;
}
V_82 = F_50 ( V_79 ) ;
if ( ! V_82 ) {
F_31 ( L_5 , V_81 -> V_84 ) ;
return - V_86 ;
}
if ( F_22 () == V_26 ) {
F_51 ( 1 , L_6 ) ;
return - V_87 ;
}
V_3 = F_52 ( V_81 , 0 ) ;
if ( F_53 ( ! V_3 ) )
return - V_88 ;
if ( F_54 () ) {
V_20 = V_89 ;
V_90 = V_91 ;
V_64 = 1 ;
} else if ( F_55 () ) {
V_20 = V_92 ;
V_90 = V_93 ;
}
V_72 = F_56 ( V_82 , 0 , V_90 ,
V_81 , & V_94 ,
NULL ) ;
if ( ! V_72 ) {
F_57 ( V_3 ) ;
return - V_88 ;
}
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
F_3 ( 0 , V_13 , V_95 ) ;
if ( ! F_55 () )
F_3 ( 0 , V_13 , V_96 ) ;
}
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ )
V_19 [ V_13 ] = V_83 ;
if ( F_27 () || F_25 () ) {
V_6 = F_58 ( V_3 + V_97 ) ;
V_6 |= F_8 ( 5 ) ;
F_59 ( V_98 , V_6 ) ;
}
F_34 () ;
F_38 () ;
return 0 ;
}
