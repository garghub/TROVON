struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 -> V_8 ,
V_4 , 0 ) ;
struct V_1 * V_9 ;
F_3 ( & V_10 ) ;
F_4 (prg, &ipu_prg_list, list) {
if ( V_7 == V_9 -> V_3 -> V_8 ) {
F_5 ( & V_10 ) ;
F_6 ( V_3 , V_9 -> V_3 , V_11 ) ;
V_9 -> V_12 = V_5 ;
return V_9 ;
}
}
F_5 ( & V_10 ) ;
return NULL ;
}
int F_7 ( void )
{
return F_8 () ;
}
bool F_9 ( struct V_13 * V_14 )
{
if ( V_14 -> V_15 )
return true ;
return false ;
}
bool F_10 ( struct V_13 * V_14 , T_1 V_16 ,
T_2 V_17 )
{
const struct V_18 * V_19 = V_18 ( V_16 ) ;
if ( V_19 -> V_20 != 1 )
return false ;
return true ;
}
int F_11 ( struct V_13 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_15 ;
int V_21 ;
if ( ! V_9 )
return 0 ;
V_21 = F_12 ( V_9 -> V_22 ) ;
if ( V_21 )
goto V_23;
return 0 ;
V_23:
F_13 ( V_9 -> V_24 ) ;
return V_21 ;
}
void F_14 ( struct V_13 * V_14 )
{
struct V_1 * V_9 = V_14 -> V_15 ;
if ( ! V_9 )
return;
F_13 ( V_9 -> V_22 ) ;
}
static int F_15 ( int V_25 )
{
switch ( V_25 ) {
case V_26 :
return 0 ;
case V_27 :
return 1 ;
case V_28 :
return 2 ;
default:
return - V_29 ;
}
}
static int F_16 ( struct V_1 * V_9 , int V_30 )
{
int V_31 , V_21 ;
if ( V_30 == 0 ) {
V_21 = F_17 ( V_9 -> V_32 [ 0 ] ) ;
if ( V_21 )
goto V_33;
V_9 -> V_34 [ V_30 ] . V_35 = 0 ;
return 0 ;
}
for ( V_31 = 1 ; V_31 < 3 ; V_31 ++ ) {
V_21 = F_17 ( V_9 -> V_32 [ V_31 ] ) ;
if ( ! V_21 ) {
T_3 V_36 , V_37 ;
int V_38 ;
V_9 -> V_34 [ V_30 ] . V_35 = V_31 ;
V_38 = ( V_31 == 1 ) ? 12 : 14 ;
V_37 = ( V_9 -> V_12 << 1 ) | ( V_30 - 1 ) ;
F_18 ( V_9 -> V_39 , V_40 ,
0x3 << V_38 , V_37 << V_38 ) ;
V_38 = ( V_31 == 1 ) ? 14 : 12 ;
F_19 ( V_9 -> V_39 , V_40 , & V_36 ) ;
if ( ( ( V_36 >> V_38 ) & 0x3 ) == V_37 ) {
F_18 ( V_9 -> V_39 , V_40 ,
0x3 << V_38 ,
( V_37 ^ 0x1 ) << V_38 ) ;
}
return 0 ;
}
}
V_33:
F_20 ( V_9 -> V_3 , L_1 , V_30 ) ;
return V_21 ;
}
static void F_21 ( struct V_1 * V_9 , int V_30 )
{
struct V_41 * V_34 = & V_9 -> V_34 [ V_30 ] ;
F_22 ( V_9 -> V_32 [ V_34 -> V_35 ] ) ;
V_34 -> V_35 = - 1 ;
}
void F_23 ( struct V_42 * V_25 )
{
int V_30 = F_15 ( V_25 -> V_43 ) ;
struct V_1 * V_9 = V_25 -> V_14 -> V_15 ;
struct V_41 * V_34 = & V_9 -> V_34 [ V_30 ] ;
T_3 V_36 ;
if ( ! V_34 -> V_44 || V_30 < 0 )
return;
F_12 ( V_9 -> V_24 ) ;
V_36 = F_24 ( V_9 -> V_45 + V_46 ) ;
V_36 |= F_25 ( V_30 ) ;
F_26 ( V_36 , V_9 -> V_45 + V_46 ) ;
V_36 = V_47 ;
F_26 ( V_36 , V_9 -> V_45 + V_48 ) ;
F_13 ( V_9 -> V_24 ) ;
F_21 ( V_9 , V_30 ) ;
V_34 -> V_44 = false ;
}
int F_27 ( struct V_42 * V_25 ,
unsigned int V_49 , unsigned int V_50 ,
unsigned int V_51 , unsigned int V_52 ,
T_3 V_16 , unsigned long * V_53 )
{
int V_30 = F_15 ( V_25 -> V_43 ) ;
struct V_1 * V_9 = V_25 -> V_14 -> V_15 ;
struct V_41 * V_34 = & V_9 -> V_34 [ V_30 ] ;
T_3 V_36 ;
int V_21 ;
if ( V_30 < 0 )
return V_30 ;
if ( V_34 -> V_44 ) {
F_28 ( V_9 -> V_32 [ V_34 -> V_35 ] , * V_53 ) ;
return 0 ;
}
V_21 = F_16 ( V_9 , V_30 ) ;
if ( V_21 )
return V_21 ;
F_29 ( V_9 -> V_32 [ V_34 -> V_35 ] ,
V_50 , V_51 , V_52 , V_16 , * V_53 ) ;
V_21 = F_12 ( V_9 -> V_24 ) ;
if ( V_21 ) {
F_21 ( V_9 , V_30 ) ;
return V_21 ;
}
V_36 = ( V_52 - 1 ) & V_54 ;
F_26 ( V_36 , V_9 -> V_45 + F_30 ( V_30 ) ) ;
V_36 = ( ( V_51 & V_55 ) <<
V_56 ) |
( ( V_51 & V_57 ) <<
V_58 ) ;
F_26 ( V_36 , V_9 -> V_45 + F_31 ( V_30 ) ) ;
V_36 = F_32 ( V_9 -> V_32 [ V_34 -> V_35 ] ) ;
* V_53 = V_36 ;
F_26 ( V_36 , V_9 -> V_45 + F_33 ( V_30 ) ) ;
V_36 = F_24 ( V_9 -> V_45 + V_46 ) ;
V_36 &= ~ ( V_59 <<
F_34 ( V_30 ) ) ;
V_36 |= F_35 ( V_30 , V_49 ) ;
V_36 &= ~ F_25 ( V_30 ) ;
F_26 ( V_36 , V_9 -> V_45 + V_46 ) ;
V_36 = V_47 ;
F_26 ( V_36 , V_9 -> V_45 + V_48 ) ;
F_13 ( V_9 -> V_24 ) ;
V_34 -> V_44 = true ;
return 0 ;
}
static int F_36 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = & V_61 -> V_3 ;
struct V_62 * V_63 ;
struct V_1 * V_9 ;
T_3 V_36 ;
int V_31 , V_21 ;
V_9 = F_37 ( V_3 , sizeof( * V_9 ) , V_64 ) ;
if ( ! V_9 )
return - V_65 ;
V_63 = F_38 ( V_61 , V_66 , 0 ) ;
V_9 -> V_45 = F_39 ( & V_61 -> V_3 , V_63 ) ;
if ( F_40 ( V_9 -> V_45 ) )
return F_41 ( V_9 -> V_45 ) ;
V_9 -> V_24 = F_42 ( V_3 , L_2 ) ;
if ( F_40 ( V_9 -> V_24 ) )
return F_41 ( V_9 -> V_24 ) ;
V_9 -> V_22 = F_42 ( V_3 , L_3 ) ;
if ( F_40 ( V_9 -> V_22 ) )
return F_41 ( V_9 -> V_22 ) ;
V_9 -> V_39 =
F_43 ( L_4 ) ;
if ( F_40 ( V_9 -> V_39 ) )
return F_41 ( V_9 -> V_39 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
V_9 -> V_32 [ V_31 ] = F_44 ( V_3 , L_5 , V_31 ) ;
if ( ! V_9 -> V_32 [ V_31 ] )
return - V_67 ;
}
V_21 = F_12 ( V_9 -> V_24 ) ;
if ( V_21 )
return V_21 ;
V_36 = F_24 ( V_9 -> V_45 + V_46 ) ;
V_36 |= V_68 ;
F_26 ( V_36 , V_9 -> V_45 + V_46 ) ;
F_26 ( 0xffffffff , V_9 -> V_45 + V_69 ) ;
F_13 ( V_9 -> V_24 ) ;
V_9 -> V_3 = V_3 ;
F_45 ( V_61 , V_9 ) ;
F_3 ( & V_10 ) ;
F_46 ( & V_9 -> V_70 , & V_71 ) ;
F_5 ( & V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_60 * V_61 )
{
struct V_1 * V_9 = F_48 ( V_61 ) ;
F_3 ( & V_10 ) ;
F_49 ( & V_9 -> V_70 ) ;
F_5 ( & V_10 ) ;
return 0 ;
}
