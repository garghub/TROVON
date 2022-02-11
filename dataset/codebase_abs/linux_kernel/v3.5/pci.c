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
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_5 ;
T_2 V_13 , V_14 ;
if ( V_5 -> V_15 == V_16 ) {
F_4 ( V_5 , V_17 , V_18 ) ;
( void ) F_5 ( V_5 , V_19 + ( 4 * V_11 ) ) ;
} else {
F_6 ( V_5 , V_11 , V_19 ) ;
F_4 ( V_5 , V_20 ,
V_21 ) ;
}
for ( V_14 = V_22 ; V_14 > 0 ; V_14 -- ) {
V_13 = F_5 ( V_5 , V_23 ) ;
if ( V_13 & V_24 ) {
if ( V_13 & V_25 )
return false ;
* V_12 = ( T_3 ) ( F_5 ( V_5 , V_26 ) &
0xffff ) ;
return true ;
}
F_7 ( 15 , 20 ) ;
}
return false ;
}
int F_8 ( struct V_4 * V_5 )
{
V_5 -> V_27 = F_5 ( V_5 , V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , T_1 * V_29 )
{
T_1 V_30 [ V_31 ] = {} ;
T_2 V_32 , V_11 ;
T_3 V_12 ;
int V_33 ;
F_10 ( 0x20 , V_12 ) ;
for ( V_11 = 0x1f , V_33 = 0 , V_32 = 0 ; V_11 >= 0x1d ; V_11 -- ) {
F_10 ( V_11 , V_12 ) ;
V_32 += V_12 ;
V_30 [ V_33 + 1 ] = V_12 & 0xff ;
V_30 [ V_33 ] = V_12 >> 8 ;
V_33 += 2 ;
}
if ( ! V_32 || V_32 == 3 * 0xffff )
return - V_34 ;
memcpy ( V_29 , V_30 , V_31 ) ;
return 0 ;
}
static int T_4
F_11 ( struct V_35 * V_8 ,
const struct V_36 * V_37 )
{
void T_5 * V_38 ;
struct V_4 * V_5 ;
struct V_39 * V_40 ;
int V_41 ;
T_1 V_3 ;
F_12 ( V_8 , V_42 ) ;
V_41 = F_13 ( V_8 ) ;
if ( V_41 ) {
F_14 ( & V_8 -> V_43 , L_1 ) ;
goto V_44;
}
V_41 = F_15 ( V_8 , F_16 ( 32 ) ) ;
if ( V_41 ) {
F_14 ( & V_8 -> V_43 , L_2 ) ;
goto V_45;
}
F_2 ( V_8 , V_9 , & V_3 ) ;
if ( V_3 == 0 ) {
V_3 = V_10 >> 2 ;
F_17 ( V_8 , V_9 , V_3 ) ;
}
F_17 ( V_8 , V_46 , 0xa8 ) ;
F_18 ( V_8 ) ;
F_17 ( V_8 , 0x41 , 0 ) ;
V_41 = F_19 ( V_8 , 0 , L_3 ) ;
if ( V_41 ) {
F_14 ( & V_8 -> V_43 , L_4 ) ;
goto V_45;
}
V_38 = F_20 ( V_8 , 0 , 0 ) ;
if ( ! V_38 ) {
F_14 ( & V_8 -> V_43 , L_5 ) ;
V_41 = - V_47 ;
goto V_48;
}
V_40 = F_21 ( sizeof( * V_5 ) , & V_49 ) ;
if ( V_40 == NULL ) {
F_14 ( & V_8 -> V_43 , L_6 ) ;
V_41 = - V_50 ;
goto V_51;
}
F_22 ( & V_8 -> V_43 , L_7 , F_23 ( V_40 -> V_52 ) ) ;
V_5 = V_40 -> V_6 ;
V_5 -> V_40 = V_40 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_43 = & V_8 -> V_43 ;
V_5 -> V_53 = V_8 -> V_53 ;
V_5 -> V_54 = V_37 -> V_55 ;
V_5 -> V_56 = V_38 ;
V_41 = F_24 ( V_5 , & V_57 ) ;
if ( V_41 )
goto V_58;
F_25 ( V_8 , V_40 ) ;
return 0 ;
V_58:
F_26 ( V_40 ) ;
V_51:
F_27 ( V_8 , V_38 ) ;
V_48:
F_28 ( V_8 , 0 ) ;
V_45:
F_29 ( V_8 ) ;
V_44:
return V_41 ;
}
static void T_6
F_30 ( struct V_35 * V_8 )
{
struct V_39 * V_40 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_40 -> V_6 ;
F_32 ( V_5 ) ;
F_27 ( V_8 , V_5 -> V_56 ) ;
F_28 ( V_8 , 0 ) ;
F_29 ( V_8 ) ;
F_26 ( V_40 ) ;
}
static int F_33 ( struct V_55 * V_43 )
{
struct V_35 * V_8 = F_34 ( V_43 ) ;
struct V_39 * V_40 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_40 -> V_6 ;
F_35 ( V_5 ) ;
return 0 ;
}
static int F_36 ( struct V_55 * V_43 )
{
struct V_35 * V_8 = F_34 ( V_43 ) ;
struct V_39 * V_40 = F_31 ( V_8 ) ;
struct V_4 * V_5 = V_40 -> V_6 ;
F_17 ( V_8 , 0x41 , 0 ) ;
F_37 ( V_5 ) ;
return 0 ;
}
