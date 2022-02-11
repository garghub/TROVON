static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
static struct V_2 * F_3 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
int V_6 ;
V_3 = F_4 ( V_5 , L_1 ) ;
if ( F_5 ( V_3 ) ) {
F_6 ( V_5 , L_2 ,
F_7 ( V_3 ) ) ;
return V_3 ;
}
V_6 = F_8 ( V_3 ) ;
if ( V_6 ) {
F_6 ( V_5 , L_3 , V_6 ) ;
return F_9 ( V_6 ) ;
}
V_6 = F_10 ( V_5 , F_1 , V_3 ) ;
if ( V_6 ) {
F_2 ( V_3 ) ;
F_6 ( V_5 , L_4 ,
V_6 ) ;
return F_9 ( V_6 ) ;
}
return V_3 ;
}
static T_1 F_11 ( int V_7 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_13 ;
unsigned long V_15 ;
unsigned int V_16 ;
int V_17 ;
V_17 = F_12 ( V_12 , V_18 ) ;
if ( V_17 < 0 ) {
F_6 ( & V_12 -> V_5 , L_5 , V_17 ) ;
goto V_19;
}
V_17 <<= 8 ;
V_17 |= F_12 ( V_12 , V_20 ) ;
if ( V_17 < 0 ) {
F_6 ( & V_12 -> V_5 , L_5 , V_17 ) ;
goto V_19;
}
V_17 &= V_21 ;
V_15 = V_17 ^ V_10 -> V_22 ;
V_10 -> V_22 = V_17 ;
F_13 (key_num, &bit_changed, mpr121->keycount) {
unsigned int V_23 , V_24 ;
V_24 = V_17 & F_14 ( V_16 ) ;
V_23 = V_10 -> V_25 [ V_16 ] ;
F_15 ( V_14 , V_26 , V_27 , V_16 ) ;
F_16 ( V_14 , V_23 , V_24 ) ;
F_17 ( & V_12 -> V_5 , L_6 , V_16 , V_23 ,
V_24 ? L_7 : L_8 ) ;
}
F_18 ( V_14 ) ;
V_19:
return V_28 ;
}
static int F_19 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_29 )
{
const struct V_30 * V_17 ;
unsigned char V_31 , V_32 , V_33 , V_34 ;
int V_35 , V_36 , V_37 , V_38 ;
for ( V_35 = 0 ; V_35 <= V_39 ; V_35 ++ ) {
V_36 = V_40 + ( V_35 * 2 ) ;
V_38 = F_20 ( V_12 , V_36 , V_41 ) ;
if ( V_38 < 0 )
goto V_42;
V_38 = F_20 ( V_12 , V_36 + 1 ,
V_43 ) ;
if ( V_38 < 0 )
goto V_42;
}
for ( V_35 = 0 ; V_35 < F_21 ( V_44 ) ; V_35 ++ ) {
V_17 = & V_44 [ V_35 ] ;
V_38 = F_20 ( V_12 , V_17 -> V_45 , V_17 -> V_46 ) ;
if ( V_38 < 0 )
goto V_42;
}
V_37 = V_29 / 1000 ;
V_31 = ( ( V_37 - 700 ) * 256 ) / V_37 ;
V_32 = ( V_31 * 65 ) / 100 ;
V_33 = ( V_31 * 90 ) / 100 ;
V_38 = F_20 ( V_12 , V_47 , V_31 ) ;
V_38 |= F_20 ( V_12 , V_48 , V_32 ) ;
V_38 |= F_20 ( V_12 , V_49 , V_33 ) ;
V_34 = V_10 -> V_50 | V_51 ;
V_38 |= F_20 ( V_12 , V_52 ,
V_34 ) ;
if ( V_38 != 0 )
goto V_42;
F_17 ( & V_12 -> V_5 , L_9 , V_10 -> V_50 ) ;
return 0 ;
V_42:
F_6 ( & V_12 -> V_5 , L_10 , V_38 ) ;
return V_38 ;
}
static int F_22 ( struct V_11 * V_12 ,
const struct V_53 * V_54 )
{
struct V_4 * V_5 = & V_12 -> V_5 ;
struct V_2 * V_3 ;
int V_29 ;
struct V_9 * V_10 ;
struct V_13 * V_13 ;
int error ;
int V_35 ;
if ( ! V_12 -> V_7 ) {
F_6 ( V_5 , L_11 ) ;
return - V_55 ;
}
V_3 = F_3 ( V_5 ) ;
if ( F_5 ( V_3 ) )
return F_7 ( V_3 ) ;
V_29 = F_23 ( V_3 ) ;
V_10 = F_24 ( V_5 , sizeof( * V_10 ) , V_56 ) ;
if ( ! V_10 )
return - V_57 ;
V_13 = F_25 ( V_5 ) ;
if ( ! V_13 )
return - V_57 ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_50 = F_26 ( V_5 , L_12 ,
NULL , 0 ) ;
if ( V_10 -> V_50 > V_39 ) {
F_6 ( V_5 , L_13 , V_10 -> V_50 ) ;
return - V_55 ;
}
error = F_26 ( V_5 , L_12 ,
V_10 -> V_25 ,
V_10 -> V_50 ) ;
if ( error ) {
F_6 ( V_5 ,
L_14 , error ) ;
return error ;
}
V_13 -> V_58 = L_15 ;
V_13 -> V_54 . V_59 = V_60 ;
V_13 -> V_5 . V_61 = V_5 ;
if ( F_27 ( V_5 , L_16 ) )
F_28 ( V_62 , V_13 -> V_63 ) ;
F_29 ( V_13 , V_26 , V_27 ) ;
V_13 -> V_64 = V_10 -> V_25 ;
V_13 -> V_65 = sizeof( V_10 -> V_25 [ 0 ] ) ;
V_13 -> V_66 = V_10 -> V_50 ;
for ( V_35 = 0 ; V_35 < V_10 -> V_50 ; V_35 ++ )
F_29 ( V_13 , V_67 , V_10 -> V_25 [ V_35 ] ) ;
error = F_19 ( V_10 , V_12 , V_29 ) ;
if ( error ) {
F_6 ( V_5 , L_17 ) ;
return error ;
}
error = F_30 ( V_5 , V_12 -> V_7 , NULL ,
F_11 ,
V_68 | V_69 ,
V_5 -> V_70 -> V_58 , V_10 ) ;
if ( error ) {
F_6 ( V_5 , L_18 ) ;
return error ;
}
error = F_31 ( V_13 ) ;
if ( error )
return error ;
F_32 ( V_12 , V_10 ) ;
F_33 ( V_5 ,
F_27 ( V_5 , L_19 ) ) ;
return 0 ;
}
static int T_2 F_34 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_35 ( V_5 ) ;
if ( F_36 ( & V_12 -> V_5 ) )
F_37 ( V_12 -> V_7 ) ;
F_20 ( V_12 , V_52 , 0x00 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_35 ( V_5 ) ;
struct V_9 * V_10 = F_39 ( V_12 ) ;
if ( F_36 ( & V_12 -> V_5 ) )
F_40 ( V_12 -> V_7 ) ;
F_20 ( V_12 , V_52 ,
V_10 -> V_50 ) ;
return 0 ;
}
