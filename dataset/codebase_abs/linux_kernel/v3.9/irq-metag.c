static inline void T_1 * F_1 ( T_2 V_1 )
{
void T_1 * V_2 ;
switch ( V_1 ) {
case V_3 :
V_2 = ( void T_1 * ) V_4 ;
break;
case V_5 :
V_2 = ( void T_1 * ) V_6 ;
break;
default:
V_2 = NULL ;
break;
}
return V_2 ;
}
static unsigned int F_2 ( struct V_7 * V_8 )
{
F_3 ( V_8 ) ;
F_4 ( V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 ) ;
F_3 ( V_8 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
T_2 V_1 = V_8 -> V_9 ;
unsigned int V_10 = 1 << V_1 ;
if ( F_7 ( V_11 ) & V_10 )
F_8 ( V_10 , V_11 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = & V_12 ;
T_2 V_1 = V_8 -> V_9 ;
void T_1 * V_14 = F_1 ( V_1 ) ;
F_9 ( V_1 , & V_13 -> V_15 ) ;
F_8 ( 0 , V_14 ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_12 * V_13 = & V_12 ;
T_2 V_1 = V_8 -> V_9 ;
unsigned int V_10 = 1 << V_1 ;
void T_1 * V_14 = F_1 ( V_1 ) ;
unsigned int V_16 = F_10 () ;
F_11 ( V_1 , & V_13 -> V_15 ) ;
F_8 ( F_12 ( F_13 ( V_16 ) ) , V_14 ) ;
if ( F_7 ( V_11 ) & V_10 ) {
F_8 ( V_10 , V_11 ) ;
while ( ! ( F_7 ( V_11 ) & V_10 ) )
F_8 ( V_10 , V_11 ) ;
}
}
static int F_14 ( struct V_7 * V_8 ,
const struct V_17 * V_17 , bool V_18 )
{
unsigned int V_19 , V_16 ;
T_2 V_1 = V_8 -> V_9 ;
V_19 = F_15 ( V_17 ) ;
V_16 = V_20 [ V_19 ] ;
F_8 ( F_12 ( F_13 ( V_16 ) ) ,
F_1 ( V_1 ) ) ;
return 0 ;
}
static void F_16 ( unsigned int V_21 , struct V_22 * V_23 )
{
struct V_12 * V_13 = F_17 ( V_23 ) ;
T_2 V_1 ;
unsigned int V_24 ;
T_3 V_25 ;
V_26:
V_25 = F_7 ( V_11 ) & V_13 -> V_15 ;
for ( V_1 = 0 ; V_25 != 0 ; V_25 >>= 1 , ++ V_1 ) {
if ( V_25 & 0x1 ) {
V_24 = F_18 ( V_13 -> V_27 , V_1 ) ;
F_19 ( V_24 ) ;
goto V_26;
}
}
}
int F_20 ( unsigned int V_1 )
{
struct V_12 * V_13 = & V_12 ;
if ( ! V_13 -> V_27 )
return - V_28 ;
return F_21 ( V_13 -> V_27 , V_1 ) ;
}
static void F_22 ( struct V_12 * V_13 ,
int V_19 )
{
unsigned int V_16 = V_20 [ V_19 ] ;
unsigned int V_29 = F_13 ( V_16 ) ;
int V_21 = F_23 ( V_29 ) ;
F_24 ( V_21 , V_13 ) ;
F_25 ( V_21 , F_16 ) ;
F_26 ( V_21 , V_30 ) ;
}
static int F_27 ( struct V_31 * V_32 , unsigned int V_21 ,
T_2 V_1 )
{
if ( ! F_1 ( V_1 ) )
return - V_33 ;
F_28 ( V_21 , & V_34 ,
V_35 ) ;
return 0 ;
}
int T_4 F_29 ( void )
{
struct V_12 * V_13 = & V_12 ;
unsigned int V_19 ;
V_13 -> V_27 = F_30 ( NULL , 32 ,
& V_36 ,
V_13 ) ;
if ( F_31 ( ! V_13 -> V_27 ) ) {
F_32 ( L_1 ) ;
return - V_37 ;
}
F_33 (cpu)
F_22 ( V_13 , V_19 ) ;
return 0 ;
}
