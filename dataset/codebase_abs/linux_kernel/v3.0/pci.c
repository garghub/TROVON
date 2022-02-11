static void F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
T_1 V_7 ;
F_2 ( V_5 -> V_8 , V_9 , & V_7 ) ;
* V_3 = ( int ) V_7 ;
if ( * V_3 == 0 )
* V_3 = V_10 >> 2 ;
}
static bool
F_3 ( struct V_1 * V_2 , T_2 V_11 , T_3 * V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_14 ;
T_2 V_15 , V_16 ;
if ( V_14 -> V_17 == V_18 ) {
F_4 ( V_14 , V_19 , V_20 ) ;
( void ) F_5 ( V_14 , V_21 + ( 4 * V_11 ) ) ;
} else {
F_6 ( V_14 , V_11 , V_21 ) ;
F_4 ( V_14 , V_22 ,
V_23 ) ;
}
for ( V_16 = V_24 ; V_16 > 0 ; V_16 -- ) {
V_15 = F_5 ( V_14 , V_25 ) ;
if ( V_15 & V_26 ) {
if ( V_15 & V_27 )
return false ;
* V_12 = ( T_3 ) ( F_5 ( V_14 , V_28 ) &
0xffff ) ;
return true ;
}
F_7 ( 15 ) ;
}
return false ;
}
int F_8 ( struct V_13 * V_14 )
{
V_14 -> V_29 = F_5 ( V_14 , V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , T_1 * V_31 )
{
T_1 V_32 [ V_33 ] = {} ;
T_2 V_34 , V_11 ;
T_3 V_12 ;
int V_35 ;
F_10 ( 0x20 , V_12 ) ;
for ( V_11 = 0x1f , V_35 = 0 , V_34 = 0 ; V_11 >= 0x1d ; V_11 -- ) {
F_10 ( V_11 , V_12 ) ;
V_34 += V_12 ;
V_32 [ V_35 + 1 ] = V_12 & 0xff ;
V_32 [ V_35 ] = V_12 >> 8 ;
V_35 += 2 ;
}
if ( ! V_34 || V_34 == 3 * 0xffff )
return - V_36 ;
memcpy ( V_31 , V_32 , V_33 ) ;
return 0 ;
}
static int T_4
F_11 ( struct V_37 * V_8 ,
const struct V_38 * V_39 )
{
void T_5 * V_40 ;
struct V_4 * V_5 ;
struct V_41 * V_42 ;
int V_43 ;
T_1 V_3 ;
F_12 ( V_8 , V_44 ) ;
V_43 = F_13 ( V_8 ) ;
if ( V_43 ) {
F_14 ( & V_8 -> V_45 , L_1 ) ;
goto V_46;
}
V_43 = F_15 ( V_8 , F_16 ( 32 ) ) ;
if ( V_43 ) {
F_14 ( & V_8 -> V_45 , L_2 ) ;
goto V_47;
}
F_2 ( V_8 , V_9 , & V_3 ) ;
if ( V_3 == 0 ) {
V_3 = V_10 >> 2 ;
F_17 ( V_8 , V_9 , V_3 ) ;
}
F_17 ( V_8 , V_48 , 0xa8 ) ;
F_18 ( V_8 ) ;
F_17 ( V_8 , 0x41 , 0 ) ;
V_43 = F_19 ( V_8 , 0 , L_3 ) ;
if ( V_43 ) {
F_14 ( & V_8 -> V_45 , L_4 ) ;
goto V_47;
}
V_40 = F_20 ( V_8 , 0 , 0 ) ;
if ( ! V_40 ) {
F_14 ( & V_8 -> V_45 , L_5 ) ;
V_43 = - V_49 ;
goto V_50;
}
V_42 = F_21 ( sizeof( * V_5 ) , & V_51 ) ;
if ( V_42 == NULL ) {
F_14 ( & V_8 -> V_45 , L_6 ) ;
V_43 = - V_52 ;
goto V_53;
}
F_22 ( & V_8 -> V_45 , L_7 , F_23 ( V_42 -> V_54 ) ) ;
V_5 = V_42 -> V_6 ;
V_5 -> V_42 = V_42 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_45 = & V_8 -> V_45 ;
V_5 -> V_55 = V_8 -> V_55 ;
V_5 -> V_56 = V_39 -> V_57 ;
V_5 -> V_58 = V_40 ;
V_43 = F_24 ( V_5 , & V_59 ) ;
if ( V_43 )
goto V_60;
F_25 ( V_8 , V_42 ) ;
return 0 ;
V_60:
F_26 ( V_42 ) ;
V_53:
F_27 ( V_8 , V_40 ) ;
V_50:
F_28 ( V_8 , 0 ) ;
V_47:
F_29 ( V_8 ) ;
V_46:
return V_43 ;
}
static void T_6
F_30 ( struct V_37 * V_8 )
{
struct V_41 * V_42 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_42 -> V_6 ;
F_32 ( V_5 ) ;
F_27 ( V_8 , V_5 -> V_58 ) ;
F_28 ( V_8 , 0 ) ;
F_29 ( V_8 ) ;
F_26 ( V_42 ) ;
}
static int F_33 ( struct V_57 * V_45 )
{
struct V_37 * V_8 = F_34 ( V_45 ) ;
struct V_41 * V_42 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_42 -> V_6 ;
F_35 ( V_5 ) ;
return 0 ;
}
static int F_36 ( struct V_57 * V_45 )
{
struct V_37 * V_8 = F_34 ( V_45 ) ;
struct V_41 * V_42 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_42 -> V_6 ;
F_17 ( V_8 , 0x41 , 0 ) ;
F_37 ( V_5 ) ;
return 0 ;
}
static int T_7
F_38 ( void )
{
int V_43 ;
V_43 = F_39 ( & V_61 ) ;
if ( V_43 ) {
F_40 ( V_62 L_8 ) ;
return V_43 ;
}
return 0 ;
}
static void T_8
F_41 ( void )
{
F_42 ( & V_61 ) ;
}
