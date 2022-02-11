static void F_1 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + F_3 ( V_2 ) ) ;
}
static void F_4 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + F_5 ( V_2 ) ) ;
}
static void F_6 ( T_1 V_1 , unsigned V_2 )
{
F_2 ( V_1 , V_3 + F_7 ( V_2 ) ) ;
}
static inline void F_8 ( int V_2 )
{
F_1 ( V_4 [ V_2 ] . V_5 , V_2 ) ;
F_4 ( V_4 [ V_2 ] . V_6 , V_2 ) ;
F_6 ( V_4 [ V_2 ] . V_7 , V_2 ) ;
}
static T_1 F_9 ( T_2 V_8 , T_3 V_9 )
{
unsigned long V_10 = V_8 * V_9 ;
unsigned long V_11 = ( V_10 / V_12 ) +
( V_10 % V_12 != 0 ) ;
return V_11 * V_12 / V_9 ;
}
static inline T_1 F_10 ( T_2 V_13 , T_3 V_9 )
{
return ( V_14 - V_13 ) * V_15 *
V_9 ;
}
void F_11 ( void )
{
int V_16 ;
unsigned long V_17 = V_18 ;
for ( V_16 = F_12 ( V_17 ) ; V_16 ; V_16 = F_12 ( V_17 ) ) {
V_16 -- ;
V_17 &= ~ ( 1 << V_16 ) ;
F_8 ( V_16 ) ;
}
}
void F_13 ( T_2 * V_8 , T_2 * V_19 ,
T_3 V_9 )
{
* V_8 = F_14 ( * V_8 * V_9 , V_12 ) / V_9 ;
* V_19 = F_14 ( * V_19 , V_15 ) ;
}
T_1 F_15 ( T_2 V_8 , T_2 V_19 , T_3 V_9 )
{
unsigned long V_13 = F_9 ( V_8 ,
V_9 ) ;
if ( V_13 > V_14 )
return 0 ;
return ( V_8 * V_19 * V_9 ) + F_10 (
V_13 , V_9 ) ;
}
T_2 F_16 ( T_1 V_20 , T_2 V_8 , T_3 V_9 )
{
unsigned long V_13 = F_9 ( V_8 ,
V_9 ) ;
unsigned long V_19 ;
unsigned long V_21 ;
if ( V_13 > V_14 )
return 0 ;
V_21 = F_10 ( V_13 , V_9 ) ;
if ( V_20 < V_21 )
return 0 ;
V_19 = ( V_20 - V_21 ) / ( V_8 * V_9 ) ;
return F_17 (unsigned long, height, 2048 ) ;
}
void F_18 ( struct V_22 * V_22 , unsigned long V_23 ,
T_2 V_8 , T_2 V_19 ,
unsigned V_9 , bool V_24 )
{
unsigned V_25 ;
T_2 V_26 ;
T_2 V_27 ;
T_3 V_2 = V_22 -> V_28 ;
T_1 V_6 ;
T_1 V_5 ;
F_19 ( L_1 , V_2 , V_23 ,
V_8 , V_19 , V_9 , V_24 ) ;
if ( V_24 ) {
V_9 *= 2 ;
V_8 /= 2 ;
}
if ( V_9 == 4 )
V_25 = 2 ;
else if ( V_9 == 2 )
V_25 = 1 ;
else {
F_20 () ;
return;
}
V_26 = F_14 ( V_8 * V_9 , V_12 ) / V_9 ;
V_27 = F_14 ( V_19 , V_15 ) ;
F_19 ( L_2 , V_26 , V_27 , V_9 ) ;
V_6 = V_26 << V_29 ;
V_6 |= V_27 << V_30 ;
V_5 = V_25 << V_31 ;
V_5 |= V_32 << V_33 ;
V_5 |= V_34 << V_35 ;
V_4 [ V_2 ] . V_7 = V_23 ;
V_4 [ V_2 ] . V_6 = V_6 ;
V_4 [ V_2 ] . V_5 = V_5 ;
F_6 ( V_23 , V_2 ) ;
F_4 ( V_6 , V_2 ) ;
F_1 ( V_5 , V_2 ) ;
F_19 ( L_3 ,
V_26 - V_8 , V_27 - V_19 ) ;
V_22 -> V_36 = V_8 ;
V_22 -> V_37 = V_19 ;
V_22 -> V_38 = V_26 - V_8 ;
V_22 -> V_39 = V_27 - V_19 ;
V_22 -> V_9 = V_9 ;
V_22 -> V_24 = V_24 ;
}
int F_21 ( struct V_22 * V_22 , T_2 V_19 , T_3 V_40 )
{
unsigned long V_6 = V_19 * V_14 * V_22 -> V_9 ;
V_22 -> V_41 [ V_40 ] = F_22 ( V_22 -> V_23 [ V_40 ] , V_6 ) ;
if ( ! V_22 -> V_41 [ V_40 ] ) {
F_23 ( V_42 L_4 ) ;
return - V_43 ;
}
F_19 ( L_5 , V_40 , V_6 ,
V_22 -> V_41 [ V_40 ] ) ;
return 0 ;
}
void F_24 ( struct V_22 * V_22 )
{
int V_40 ;
int V_2 = V_22 -> V_28 ;
if ( V_2 == 0xff )
return;
F_19 ( L_6 , V_2 ) ;
F_25 ( & V_44 ) ;
F_26 ( ! ( V_18 & ( 1 << V_2 ) ) ) ;
F_27 ( V_2 , & V_18 ) ;
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 ) {
if ( V_22 -> V_23 [ V_40 ] ) {
F_28 ( V_22 -> V_23 [ V_40 ] , V_45 ) ;
V_22 -> V_23 [ V_40 ] = 0 ;
}
}
V_22 -> V_28 = 0xff ;
F_29 ( & V_44 ) ;
}
int F_30 ( struct V_22 * V_22 )
{
int V_40 ;
T_1 V_23 ;
T_3 V_2 ;
int V_46 ;
F_19 ( L_7 ) ;
F_25 ( & V_44 ) ;
for ( V_2 = 0 ; V_2 < V_47 ; ++ V_2 )
if ( ( V_18 & ( 1 << V_2 ) ) == 0 )
break;
if ( V_2 == V_47 ) {
F_31 ( L_8 ) ;
V_46 = - V_48 ;
goto V_49;
}
F_19 ( L_9 , V_2 ) ;
F_32 ( V_2 , & V_18 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_28 = V_2 ;
for ( V_40 = 0 ; V_40 < 4 ; ++ V_40 ) {
V_23 = V_4 [ V_2 ] . V_50 + F_33 ( V_40 ) ;
if ( ! F_34 ( V_23 , V_45 , L_10 ) ) {
F_31 ( L_11
L_12 ,
V_2 , V_40 * 90 ) ;
F_24 ( V_22 ) ;
V_46 = - V_43 ;
goto V_49;
}
V_22 -> V_23 [ V_40 ] = V_23 ;
F_19 ( L_13 , V_2 , V_40 * 90 , V_22 -> V_23 [ V_40 ] ) ;
}
V_46 = 0 ;
V_49:
F_29 ( & V_44 ) ;
return V_46 ;
}
bool F_35 ( void )
{
return V_51 ;
}
static int T_4 F_36 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
int V_16 ;
V_55 = F_37 ( V_53 , V_56 , 0 ) ;
if ( ! V_55 ) {
F_38 ( & V_53 -> V_57 , L_14 ) ;
return - V_58 ;
}
V_3 = F_39 ( & V_53 -> V_57 , V_55 ) ;
if ( ! V_3 ) {
F_38 ( & V_53 -> V_57 , L_15 ) ;
return - V_43 ;
}
V_47 = V_53 -> V_59 - 1 ;
V_4 = F_40 ( & V_53 -> V_57 ,
sizeof( struct V_60 ) * V_47 ,
V_61 ) ;
if ( ! V_4 )
return - V_43 ;
for ( V_16 = 0 ; V_16 < V_47 ; ++ V_16 ) {
V_55 = F_37 ( V_53 , V_56 , 1 + V_16 ) ;
if ( ! V_55 ) {
F_38 ( & V_53 -> V_57 , L_16 ,
V_16 ) ;
return - V_58 ;
}
V_4 [ V_16 ] . V_50 = V_55 -> V_62 ;
}
V_51 = true ;
return 0 ;
}
static void T_5 F_41 ( struct V_52 * V_53 )
{
V_51 = false ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_63 , & F_36 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_63 ) ;
}
