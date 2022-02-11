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
if ( ! V_8 )
V_8 = F_25 () ;
if ( F_26 () )
F_23 () ;
else
F_21 () ;
}
static void F_27 ( void )
{
T_1 V_6 ;
T_1 V_7 = V_39 ;
if ( F_26 () )
V_7 = V_47 ;
V_6 = F_2 ( V_8 + V_7 ) ;
V_6 &= ~ V_40 ;
F_4 ( V_6 , V_8 + V_7 ) ;
}
static void F_28 ( void )
{
T_1 V_48 ;
V_48 = F_29 ( V_49 ,
V_50 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_48 != V_51 )
F_30 ( L_1 ) ;
}
static int F_31 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
unsigned int V_2 = ( unsigned int ) V_55 ;
switch ( V_54 ) {
case V_56 :
F_20 ( V_2 , 0 ) ;
break;
case V_57 :
F_20 ( V_2 , 1 ) ;
break;
}
return V_58 ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_59 ) ;
}
static void T_3 F_32 ( void )
{}
static int F_34 ( struct V_52 * V_53 , unsigned long V_60 , void * V_61 )
{
switch ( V_60 ) {
case V_62 :
if ( F_35 () == V_63 )
F_24 () ;
else
F_28 () ;
break;
case V_64 :
if ( F_35 () == V_63 )
F_27 () ;
break;
}
return V_58 ;
}
static void T_3 F_36 ( void )
{
if ( ! F_37 ( V_65 ) )
F_38 ( & V_66 ) ;
}
static void T_3 F_36 ( void )
{}
void T_4 * F_39 ( void )
{
return V_3 ;
}
int F_40 ( void )
{
return V_67 ;
}
static int F_41 ( struct V_68 * V_15 ,
struct V_69 * V_70 ,
unsigned long * V_18 ,
unsigned int * type )
{
if ( F_42 ( V_70 -> V_71 ) ) {
if ( V_70 -> V_72 != 3 )
return - V_73 ;
if ( V_70 -> V_74 [ 0 ] != 0 )
return - V_73 ;
* V_18 = V_70 -> V_74 [ 1 ] ;
* type = V_70 -> V_74 [ 2 ] ;
return 0 ;
}
return - V_73 ;
}
static int F_43 ( struct V_68 * V_75 ,
unsigned int V_76 ,
unsigned int V_77 , void * V_78 )
{
struct V_69 * V_70 = V_78 ;
struct V_69 V_79 ;
T_5 V_18 ;
int V_13 ;
if ( V_70 -> V_72 != 3 )
return - V_73 ;
if ( V_70 -> V_74 [ 0 ] != 0 )
return - V_73 ;
V_18 = V_70 -> V_74 [ 1 ] ;
if ( V_18 >= V_80 )
return - V_73 ;
for ( V_13 = 0 ; V_13 < V_77 ; V_13 ++ )
F_44 ( V_75 , V_76 + V_13 , V_18 + V_13 ,
& V_81 , NULL ) ;
V_79 = * V_70 ;
V_79 . V_71 = V_75 -> V_82 -> V_71 ;
return F_45 ( V_75 , V_76 , V_77 ,
& V_79 ) ;
}
static int T_3 F_46 ( struct V_83 * V_84 ,
struct V_83 * V_82 )
{
struct V_68 * V_85 , * V_75 ;
int V_13 ;
unsigned int V_86 = F_47 () ;
T_1 V_6 ;
if ( ! V_82 ) {
F_30 ( L_2 , V_84 -> V_87 ) ;
return - V_88 ;
}
V_85 = F_48 ( V_82 ) ;
if ( ! V_85 ) {
F_30 ( L_3 , V_84 -> V_87 ) ;
return - V_89 ;
}
if ( F_22 () == V_26 ) {
F_49 ( 1 , L_4 ) ;
return - V_90 ;
}
V_3 = F_50 ( V_84 , 0 ) ;
if ( F_51 ( ! V_3 ) )
return - V_91 ;
if ( F_52 () ) {
V_20 = V_92 ;
V_93 = V_94 ;
V_67 = 1 ;
} else if ( F_53 () ) {
V_20 = V_95 ;
V_93 = V_96 ;
}
V_75 = F_54 ( V_85 , 0 , V_93 ,
V_84 , & V_97 ,
NULL ) ;
if ( ! V_75 ) {
F_55 ( V_3 ) ;
return - V_91 ;
}
for ( V_13 = 0 ; V_13 < V_20 ; V_13 ++ ) {
F_3 ( 0 , V_13 , V_98 ) ;
if ( ! F_53 () )
F_3 ( 0 , V_13 , V_99 ) ;
}
for ( V_13 = 0 ; V_13 < V_93 ; V_13 ++ )
V_19 [ V_13 ] = V_86 ;
if ( F_26 () || F_56 () ) {
V_6 = F_57 ( V_3 + V_100 ) ;
V_6 |= F_8 ( 5 ) ;
F_58 ( V_101 , V_6 ) ;
}
F_32 () ;
F_36 () ;
return 0 ;
}
