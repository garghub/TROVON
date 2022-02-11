static inline void F_1 ( T_1 V_1 )
{
V_2 |= 3 << ( V_1 * 2 ) ;
}
static inline void F_2 ( T_1 V_1 )
{
V_2 &= ~ ( 3 << ( V_1 * 2 ) ) ;
}
static inline int F_3 ( T_1 V_1 )
{
return V_2 & ( 3 << ( V_1 * 2 ) ) ;
}
static inline void F_4 ( T_1 V_1 )
{
F_5 ( V_3 , V_4 [ V_1 ] + V_5 ) ;
F_6 ( V_6 , L_1 , V_7 [ V_1 ] ) ;
}
static inline void F_7 ( T_1 V_1 )
{
F_5 ( V_8 , V_4 [ V_1 ] + V_5 ) ;
F_6 ( V_6 , L_2 , V_7 [ V_1 ] ) ;
}
static inline void F_8 ( T_1 V_1 )
{
F_5 ( 0x1 , V_4 [ V_1 ] + V_9 ) ;
F_6 ( V_6 , L_3 , V_7 [ V_1 ] ) ;
}
static inline void F_9 ( T_1 V_1 , unsigned long V_10 )
{
if ( F_10 ( V_10 == 0 ) ) {
V_10 = ( unsigned long ) F_11 ( 0 ) ;
F_5 ( 0x20 , V_4 [ V_1 ] + V_11 ) ;
} else {
F_5 ( 0x0 , V_4 [ V_1 ] + V_11 ) ;
}
F_5 ( V_10 , V_4 [ V_1 ] + V_12 ) ;
F_6 ( V_6 , L_4 ,
V_7 [ V_1 ] , V_10 ) ;
F_8 ( V_1 ) ;
}
void F_12 ( T_1 V_1 ,
int (* F_13)( enum V_13 V_14 ,
unsigned long V_15 ,
unsigned long V_16 ) )
{
F_14 ( ! ( ( V_1 >= V_17 ) && ( V_1 < V_18 ) ) ) ;
V_19 [ V_1 ] = F_13 ;
}
static T_2 F_15 ( int V_20 , void * V_21 )
{
unsigned long V_22 = 0 ;
T_1 V_1 = ( T_1 ) V_21 ;
enum V_13 V_14 ;
V_14 = (enum V_13 )
F_16 ( F_17 ( V_4 [ V_1 ] + V_23 ) ) ;
F_14 ( ! ( ( V_14 >= 0 ) && ( V_14 < 8 ) ) ) ;
F_18 ( V_6 , L_5 , V_24 [ V_14 ] ,
V_7 [ V_1 ] ) ;
if ( V_19 [ V_1 ] ) {
unsigned long V_25 ;
V_22 = F_17 ( V_4 [ V_1 ] + V_12 ) ;
V_25 = F_17 ( V_4 [ V_1 ] + V_26 [ V_14 ] ) ;
if ( V_19 [ V_1 ] ( V_14 , V_22 , V_25 ) ) {
F_5 ( 1 << V_14 ,
V_4 [ V_1 ] + V_27 ) ;
F_19 ( V_6 , L_6
L_7 ,
V_24 [ V_14 ] , V_7 [ V_1 ] ) ;
} else {
V_22 = 0 ;
}
}
F_7 ( V_1 ) ;
if ( ! V_22 )
F_19 ( V_6 , L_8 ,
V_24 [ V_14 ] , V_7 [ V_1 ] ) ;
return V_28 ;
}
void F_20 ( T_1 V_1 , unsigned long V_10 )
{
if ( F_3 ( V_1 ) ) {
F_4 ( V_1 ) ;
F_9 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
} else {
F_6 ( V_6 , L_9
L_10 ,
V_7 [ V_1 ] ) ;
}
}
void F_21 ( T_1 V_1 , unsigned long V_10 )
{
if ( ! F_3 ( V_1 ) ) {
F_22 ( V_1 ) ;
F_9 ( V_1 , V_10 ) ;
F_5 ( V_8 , V_4 [ V_1 ] + V_5 ) ;
F_1 ( V_1 ) ;
F_6 ( V_6 , L_11 , V_7 [ V_1 ] ) ;
} else {
F_6 ( V_6 , L_12 , V_7 [ V_1 ] ) ;
}
}
void F_23 ( T_1 V_1 )
{
if ( F_3 ( V_1 ) ) {
F_5 ( V_29 , V_4 [ V_1 ] + V_5 ) ;
F_2 ( V_1 ) ;
F_24 ( V_1 ) ;
F_6 ( V_6 , L_13 , V_7 [ V_1 ] ) ;
} else {
F_6 ( V_6 , L_14 , V_7 [ V_1 ] ) ;
}
}
void F_25 ( T_1 V_1 )
{
if ( F_3 ( V_1 ) ) {
F_4 ( V_1 ) ;
F_8 ( V_1 ) ;
F_7 ( V_1 ) ;
} else {
F_6 ( V_6 , L_9
L_15 , V_7 [ V_1 ] ) ;
}
}
static int F_26 ( struct V_30 * V_31 )
{
int V_32 , V_33 ;
struct V_34 * V_35 , * V_36 ;
V_6 = & V_31 -> V_6 ;
for ( V_32 = 0 ; V_32 < V_18 ; V_32 ++ ) {
int V_20 ;
F_27 ( V_6 , V_32 ) ;
F_24 ( V_32 ) ;
V_35 = F_28 ( V_31 , V_37 , V_32 ) ;
if ( ! V_35 ) {
F_29 ( V_6 , L_16 ,
V_7 [ V_32 ] ) ;
V_33 = - V_38 ;
goto V_39;
}
V_36 = F_30 ( V_35 -> V_40 ,
( ( V_35 -> V_41 ) - ( V_35 -> V_40 ) ) + 1 , V_31 -> V_42 ) ;
if ( ! V_36 ) {
F_29 ( V_6 , L_17 ,
V_7 [ V_32 ] ) ;
V_33 = - V_43 ;
goto V_39;
}
V_4 [ V_32 ] = F_31 ( V_35 -> V_40 , V_35 -> V_41 - V_35 -> V_40 + 1 ) ;
if ( ! V_4 [ V_32 ] ) {
F_29 ( V_6 , L_18 ,
V_7 [ V_32 ] ) ;
V_33 = - V_44 ;
goto V_45;
}
V_20 = F_32 ( V_31 , V_32 ) ;
if ( V_20 <= 0 ) {
F_29 ( V_6 , L_19 ,
V_7 [ V_32 ] ) ;
V_33 = - V_46 ;
goto V_47;
}
if ( F_33 ( V_20 , F_15 , V_48 ,
V_31 -> V_42 , ( void * ) V_32 ) ) {
F_29 ( V_6 , L_20 ,
V_7 [ V_32 ] ) ;
V_33 = - V_46 ;
goto V_47;
}
}
return 0 ;
V_47:
F_34 ( V_4 [ V_32 ] ) ;
V_45:
F_35 ( V_36 -> V_40 , F_36 ( V_36 ) ) ;
V_39:
return V_33 ;
}
static int F_37 ( struct V_30 * V_31 )
{
return 0 ;
}
int F_38 ( struct V_49 * V_6 )
{
return 0 ;
}
int F_39 ( struct V_49 * V_6 )
{
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_50 ) ;
}
