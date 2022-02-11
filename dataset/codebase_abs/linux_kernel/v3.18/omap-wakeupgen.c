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
unsigned int V_12 ;
if ( V_9 < V_13 )
return - V_14 ;
V_12 = V_9 - V_13 ;
if ( V_12 > V_15 ) {
F_7 ( L_1 , V_9 ) ;
return - V_14 ;
}
* V_11 = V_12 >> 5 ;
* V_10 = V_12 %= 32 ;
return 0 ;
}
static void F_8 ( unsigned int V_9 , unsigned int V_2 )
{
T_1 V_6 , V_16 ;
T_2 V_17 ;
if ( F_6 ( V_9 , & V_16 , & V_17 ) )
return;
V_6 = F_1 ( V_17 , V_2 ) ;
V_6 &= ~ F_9 ( V_16 ) ;
F_3 ( V_6 , V_17 , V_2 ) ;
}
static void F_10 ( unsigned int V_9 , unsigned int V_2 )
{
T_1 V_6 , V_16 ;
T_2 V_17 ;
if ( F_6 ( V_9 , & V_16 , & V_17 ) )
return;
V_6 = F_1 ( V_17 , V_2 ) ;
V_6 |= F_9 ( V_16 ) ;
F_3 ( V_6 , V_17 , V_2 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_12 ( & V_21 , V_20 ) ;
F_8 ( V_19 -> V_22 , V_23 [ V_19 -> V_22 ] ) ;
F_13 ( & V_21 , V_20 ) ;
}
static void F_14 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_12 ( & V_21 , V_20 ) ;
F_10 ( V_19 -> V_22 , V_23 [ V_19 -> V_22 ] ) ;
F_13 ( & V_21 , V_20 ) ;
}
static void F_15 ( unsigned int V_2 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ )
F_16 ( V_25 , V_2 ) [ V_17 ] = F_1 ( V_17 , V_2 ) ;
}
static void F_17 ( unsigned int V_2 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ )
F_3 ( F_16 ( V_25 , V_2 ) [ V_17 ] , V_17 , V_2 ) ;
}
static void F_18 ( unsigned int V_2 , unsigned int V_26 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ )
F_3 ( V_26 , V_17 , V_2 ) ;
}
static void F_19 ( unsigned int V_2 , unsigned int V_27 )
{
unsigned long V_20 ;
F_12 ( & V_21 , V_20 ) ;
if ( V_27 ) {
F_15 ( V_2 ) ;
F_18 ( V_2 , V_28 ) ;
} else {
F_18 ( V_2 , V_29 ) ;
F_17 ( V_2 ) ;
}
F_13 ( & V_21 , V_20 ) ;
}
static inline void F_20 ( void )
{
T_1 V_17 , V_6 ;
if ( F_21 () == V_30 )
return;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_6 = F_1 ( V_17 , 0 ) ;
F_5 ( V_6 , V_31 , V_17 ) ;
V_6 = F_1 ( V_17 , 1 ) ;
F_5 ( V_6 , V_32 , V_17 ) ;
F_5 ( 0x0 , V_33 , V_17 ) ;
F_5 ( 0x0 , V_34 , V_17 ) ;
}
V_6 = F_2 ( V_3 + V_35 ) ;
F_4 ( V_6 , V_8 + V_36 ) ;
V_6 = F_2 ( V_3 + V_37 ) ;
F_4 ( V_6 , V_8 + V_38 ) ;
V_6 = F_2 ( V_3 + V_39 ) ;
F_4 ( V_6 , V_8 + V_40 ) ;
V_6 = F_2 ( V_3 + V_41 ) ;
F_4 ( V_6 , V_8 + V_42 ) ;
V_6 = F_2 ( V_8 + V_43 ) ;
V_6 |= V_44 ;
F_4 ( V_6 , V_8 + V_43 ) ;
}
static inline void F_22 ( void )
{
T_1 V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
V_6 = F_1 ( V_17 , 0 ) ;
F_5 ( V_6 , V_45 , V_17 ) ;
V_6 = F_1 ( V_17 , 1 ) ;
F_5 ( V_6 , V_46 , V_17 ) ;
F_5 ( 0x0 , V_47 , V_17 ) ;
F_5 ( 0x0 , V_48 , V_17 ) ;
}
V_6 = F_2 ( V_3 + V_35 ) ;
F_4 ( V_6 , V_8 + V_49 ) ;
V_6 = F_2 ( V_3 + V_35 ) ;
F_4 ( V_6 , V_8 + V_50 ) ;
V_6 = F_2 ( V_8 + V_51 ) ;
V_6 |= V_44 ;
F_4 ( V_6 , V_8 + V_51 ) ;
}
static void F_23 ( void )
{
if ( ! V_8 )
V_8 = F_24 () ;
if ( F_25 () )
F_22 () ;
else
F_20 () ;
}
static void F_26 ( void )
{
T_1 V_6 ;
T_1 V_7 = V_43 ;
if ( F_25 () )
V_7 = V_51 ;
V_6 = F_2 ( V_8 + V_7 ) ;
V_6 &= ~ V_44 ;
F_4 ( V_6 , V_8 + V_7 ) ;
}
static void F_27 ( void )
{
T_1 V_52 ;
V_52 = F_28 ( V_53 ,
V_54 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_52 != V_55 )
F_7 ( L_2 ) ;
}
static int F_29 ( struct V_56 * V_57 ,
unsigned long V_58 , void * V_59 )
{
unsigned int V_2 = ( unsigned int ) V_59 ;
switch ( V_58 ) {
case V_60 :
F_19 ( V_2 , 0 ) ;
break;
case V_61 :
F_19 ( V_2 , 1 ) ;
break;
}
return V_62 ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_63 ) ;
}
static void T_3 F_30 ( void )
{}
static int F_32 ( struct V_56 * V_57 , unsigned long V_64 , void * V_65 )
{
switch ( V_64 ) {
case V_66 :
if ( F_33 () == V_67 )
F_23 () ;
else
F_27 () ;
break;
case V_68 :
if ( F_33 () == V_67 )
F_26 () ;
break;
}
return V_62 ;
}
static void T_3 F_34 ( void )
{
if ( ! F_35 ( V_69 ) )
F_36 ( & V_70 ) ;
}
static void T_3 F_34 ( void )
{}
void T_4 * F_37 ( void )
{
return V_3 ;
}
int F_38 ( void )
{
return V_71 ;
}
int T_3 F_39 ( void )
{
int V_17 ;
unsigned int V_72 = F_40 () ;
T_1 V_6 ;
if ( F_21 () == V_30 ) {
F_41 ( 1 , L_3 ) ;
return - V_73 ;
}
V_3 = F_42 ( V_74 , V_75 ) ;
if ( F_43 ( ! V_3 ) )
return - V_76 ;
if ( F_44 () ) {
V_24 = V_77 ;
V_78 = V_79 ;
V_71 = 1 ;
} else if ( F_45 () ) {
V_24 = V_80 ;
V_78 = V_81 ;
}
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
F_3 ( 0 , V_17 , V_82 ) ;
if ( ! F_45 () )
F_3 ( 0 , V_17 , V_83 ) ;
}
V_84 . V_85 = F_11 ;
V_84 . V_86 = F_14 ;
V_84 . V_20 = V_87 | V_88 ;
for ( V_17 = 0 ; V_17 < V_78 ; V_17 ++ )
V_23 [ V_17 ] = V_72 ;
if ( F_25 () || F_46 () ) {
V_6 = F_47 ( V_3 + V_89 ) ;
V_6 |= F_9 ( 5 ) ;
F_48 ( V_90 , V_6 ) ;
}
F_30 () ;
F_34 () ;
return 0 ;
}
