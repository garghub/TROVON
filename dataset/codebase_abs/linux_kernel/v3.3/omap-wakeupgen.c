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
static void F_6 ( unsigned int V_2 , unsigned int V_9 )
{
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_3 ( V_9 , V_10 , V_2 ) ;
}
static inline int F_7 ( T_1 V_12 , T_1 * V_13 , T_2 * V_14 )
{
unsigned int V_15 ;
if ( V_12 < V_16 )
return - V_17 ;
V_15 = V_12 - V_16 ;
if ( V_15 > V_18 ) {
F_8 ( L_1 , V_12 ) ;
return - V_17 ;
}
* V_14 = V_15 >> 5 ;
* V_13 = V_15 %= 32 ;
return 0 ;
}
static void F_9 ( unsigned int V_12 , unsigned int V_2 )
{
T_1 V_6 , V_19 ;
T_2 V_10 ;
if ( F_7 ( V_12 , & V_19 , & V_10 ) )
return;
V_6 = F_1 ( V_10 , V_2 ) ;
V_6 &= ~ F_10 ( V_19 ) ;
F_3 ( V_6 , V_10 , V_2 ) ;
}
static void F_11 ( unsigned int V_12 , unsigned int V_2 )
{
T_1 V_6 , V_19 ;
T_2 V_10 ;
if ( F_7 ( V_12 , & V_19 , & V_10 ) )
return;
V_6 = F_1 ( V_10 , V_2 ) ;
V_6 |= F_10 ( V_19 ) ;
F_3 ( V_6 , V_10 , V_2 ) ;
}
static void F_12 ( unsigned int V_2 )
{
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_13 ( V_20 , V_2 ) [ V_10 ] = F_1 ( V_10 , V_2 ) ;
}
static void F_14 ( unsigned int V_2 )
{
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_3 ( F_13 ( V_20 , V_2 ) [ V_10 ] , V_10 , V_2 ) ;
}
static void F_15 ( struct V_21 * V_22 )
{
unsigned long V_23 ;
F_16 ( & V_24 , V_23 ) ;
F_9 ( V_22 -> V_12 , V_25 [ V_22 -> V_12 ] ) ;
F_17 ( & V_24 , V_23 ) ;
}
static void F_18 ( struct V_21 * V_22 )
{
unsigned long V_23 ;
F_16 ( & V_24 , V_23 ) ;
F_11 ( V_22 -> V_12 , V_25 [ V_22 -> V_12 ] ) ;
F_17 ( & V_24 , V_23 ) ;
}
static void F_19 ( unsigned int V_2 , unsigned int V_26 )
{
unsigned long V_23 ;
F_16 ( & V_24 , V_23 ) ;
if ( V_26 ) {
F_12 ( V_2 ) ;
F_6 ( V_2 , V_27 ) ;
} else {
F_6 ( V_2 , V_28 ) ;
F_14 ( V_2 ) ;
}
F_17 ( & V_24 , V_23 ) ;
}
static void F_20 ( void )
{
T_1 V_10 , V_6 ;
if ( F_21 () == V_29 )
return;
if ( ! V_8 )
V_8 = F_22 () ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_6 = F_1 ( V_10 , 0 ) ;
F_5 ( V_6 , V_30 , V_10 ) ;
V_6 = F_1 ( V_10 , 1 ) ;
F_5 ( V_6 , V_31 , V_10 ) ;
F_5 ( 0x0 , V_32 , V_10 ) ;
F_5 ( 0x0 , V_33 , V_10 ) ;
}
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_35 ) ;
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_36 ) ;
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_35 ) ;
V_6 = F_2 ( V_3 + V_34 ) ;
F_4 ( V_6 , V_8 + V_36 ) ;
V_6 = F_2 ( V_3 + V_37 ) ;
F_4 ( V_6 , V_8 + V_38 ) ;
V_6 = F_2 ( V_3 + V_39 ) ;
F_4 ( V_6 , V_8 + V_40 ) ;
V_6 = F_2 ( V_8 + V_41 ) ;
V_6 |= V_42 ;
F_4 ( V_6 , V_8 + V_41 ) ;
}
void F_23 ( void )
{
T_1 V_6 ;
V_6 = F_2 ( V_8 + V_41 ) ;
V_6 &= ~ V_42 ;
F_4 ( V_6 , V_8 + V_41 ) ;
}
static void F_24 ( void )
{
T_1 V_43 ;
V_43 = F_25 ( V_44 ,
V_45 ,
0 , 0 , 0 , 0 , 0 ) ;
if ( V_43 != V_46 )
F_8 ( L_2 ) ;
}
static int T_3 F_26 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
unsigned int V_2 = ( unsigned int ) V_50 ;
switch ( V_49 ) {
case V_51 :
F_19 ( V_2 , 0 ) ;
break;
case V_52 :
F_19 ( V_2 , 1 ) ;
break;
}
return V_53 ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_54 ) ;
}
static void T_4 F_27 ( void )
{}
static int F_29 ( struct V_47 * V_48 , unsigned long V_55 , void * V_56 )
{
switch ( V_55 ) {
case V_57 :
if ( F_30 () == V_58 )
F_20 () ;
else
F_24 () ;
break;
case V_59 :
if ( F_30 () == V_58 )
F_23 () ;
break;
}
return V_53 ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_60 ) ;
}
static void T_4 F_31 ( void )
{}
int T_4 F_33 ( void )
{
int V_10 ;
unsigned int V_61 = F_34 () ;
if ( F_21 () == V_29 ) {
F_35 ( 1 , L_3 ) ;
return - V_62 ;
}
V_3 = F_36 ( V_63 , V_64 ) ;
if ( F_37 ( ! V_3 ) )
return - V_65 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
F_3 ( 0 , V_10 , V_66 ) ;
F_3 ( 0 , V_10 , V_67 ) ;
}
V_68 . V_69 = F_15 ;
V_68 . V_70 = F_18 ;
V_68 . V_23 = V_71 | V_72 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ )
V_25 [ V_10 ] = V_61 ;
F_27 () ;
F_31 () ;
return 0 ;
}
