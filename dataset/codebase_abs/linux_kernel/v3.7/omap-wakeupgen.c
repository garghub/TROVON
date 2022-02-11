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
F_8 ( V_19 -> V_9 , V_22 [ V_19 -> V_9 ] ) ;
F_13 ( & V_21 , V_20 ) ;
}
static void F_14 ( struct V_18 * V_19 )
{
unsigned long V_20 ;
F_12 ( & V_21 , V_20 ) ;
F_10 ( V_19 -> V_9 , V_22 [ V_19 -> V_9 ] ) ;
F_13 ( & V_21 , V_20 ) ;
}
static void F_15 ( unsigned int V_2 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
F_16 ( V_24 , V_2 ) [ V_17 ] = F_1 ( V_17 , V_2 ) ;
}
static void F_17 ( unsigned int V_2 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
F_3 ( F_16 ( V_24 , V_2 ) [ V_17 ] , V_17 , V_2 ) ;
}
static void F_18 ( unsigned int V_2 , unsigned int V_25 )
{
T_2 V_17 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
F_3 ( V_25 , V_17 , V_2 ) ;
}
static void F_19 ( unsigned int V_2 , unsigned int V_26 )
{
unsigned long V_20 ;
F_12 ( & V_21 , V_20 ) ;
if ( V_26 ) {
F_15 ( V_2 ) ;
F_18 ( V_2 , V_27 ) ;
} else {
F_18 ( V_2 , V_28 ) ;
F_17 ( V_2 ) ;
}
F_13 ( & V_21 , V_20 ) ;
}
static inline void F_20 ( void )
{
T_1 V_17 , V_6 ;
if ( F_21 () == V_29 )
return;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
V_6 = F_1 ( V_17 , 0 ) ;
F_5 ( V_6 , V_30 , V_17 ) ;
V_6 = F_1 ( V_17 , 1 ) ;
F_5 ( V_6 , V_31 , V_17 ) ;
F_5 ( 0x0 , V_32 , V_17 ) ;
F_5 ( 0x0 , V_33 , V_17 ) ;
}
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_35 ) ;
V_6 = F_2 ( V_3 + V_36 ) ;
F_4 ( V_6 , V_8 + V_37 ) ;
V_6 = F_2 ( V_3 + V_38 ) ;
F_4 ( V_6 , V_8 + V_39 ) ;
V_6 = F_2 ( V_3 + V_40 ) ;
F_4 ( V_6 , V_8 + V_41 ) ;
V_6 = F_2 ( V_8 + V_42 ) ;
V_6 |= V_43 ;
F_4 ( V_6 , V_8 + V_42 ) ;
}
static inline void F_22 ( void )
{
T_1 V_17 , V_6 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
V_6 = F_1 ( V_17 , 0 ) ;
F_5 ( V_6 , V_44 , V_17 ) ;
V_6 = F_1 ( V_17 , 1 ) ;
F_5 ( V_6 , V_45 , V_17 ) ;
F_5 ( 0x0 , V_46 , V_17 ) ;
F_5 ( 0x0 , V_47 , V_17 ) ;
}
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_48 ) ;
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_49 ) ;
V_6 = F_2 ( V_8 + V_50 ) ;
V_6 |= V_43 ;
F_4 ( V_6 , V_8 + V_50 ) ;
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
T_1 V_7 = V_42 ;
if ( F_25 () )
V_7 = V_50 ;
V_6 = F_2 ( V_8 + V_7 ) ;
V_6 &= ~ V_43 ;
F_4 ( V_6 , V_8 + V_7 ) ;
}
static void F_27 ( void )
{
T_1 V_51 ;
V_51 = F_28 ( V_52 ,
V_53 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_51 != V_54 )
F_7 ( L_2 ) ;
}
static int T_3 F_29 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
unsigned int V_2 = ( unsigned int ) V_58 ;
switch ( V_57 ) {
case V_59 :
F_19 ( V_2 , 0 ) ;
break;
case V_60 :
F_19 ( V_2 , 1 ) ;
break;
}
return V_61 ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_62 ) ;
}
static void T_4 F_30 ( void )
{}
static int F_32 ( struct V_55 * V_56 , unsigned long V_63 , void * V_64 )
{
switch ( V_63 ) {
case V_65 :
if ( F_33 () == V_66 )
F_23 () ;
else
F_27 () ;
break;
case V_67 :
if ( F_33 () == V_66 )
F_26 () ;
break;
}
return V_61 ;
}
static void T_4 F_34 ( void )
{
if ( ! F_25 () )
F_35 ( & V_68 ) ;
}
static void T_4 F_34 ( void )
{}
void T_5 * F_36 ( void )
{
return V_3 ;
}
int F_37 ( void )
{
return V_69 ;
}
int T_4 F_38 ( void )
{
int V_17 ;
unsigned int V_70 = F_39 () ;
if ( F_21 () == V_29 ) {
F_40 ( 1 , L_3 ) ;
return - V_71 ;
}
V_3 = F_41 ( V_72 , V_73 ) ;
if ( F_42 ( ! V_3 ) )
return - V_74 ;
if ( F_43 () ) {
V_23 = V_75 ;
V_76 = V_77 ;
V_69 = 1 ;
}
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ ) {
F_3 ( 0 , V_17 , V_78 ) ;
F_3 ( 0 , V_17 , V_79 ) ;
}
V_80 . V_81 = F_11 ;
V_80 . V_82 = F_14 ;
V_80 . V_20 = V_83 | V_84 ;
for ( V_17 = 0 ; V_17 < V_76 ; V_17 ++ )
V_22 [ V_17 ] = V_70 ;
F_30 () ;
F_34 () ;
return 0 ;
}
