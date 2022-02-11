static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_7 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_9 ( V_2 , V_3 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_10 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 -> V_11 ( V_2 , V_3 , V_8 ) ;
}
static T_3 F_6 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
int V_14 ;
V_14 = F_1 ( V_2 , V_15 ) ;
if ( V_14 < 0 )
return V_16 ;
if ( V_14 & V_17 )
F_7 ( & V_2 -> V_18 , NULL , L_1 ) ;
if ( V_14 & V_19 )
F_7 ( & V_2 -> V_18 , NULL , L_2 ) ;
if ( V_14 & V_20 )
F_7 ( & V_2 -> V_18 , NULL , L_3 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_21 , V_14 ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ ) {
V_14 = F_1 ( V_2 , V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! ( V_14 & V_22 ) )
return 0 ;
F_9 ( 60 ) ;
}
return - V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
int V_24 = 0 ;
F_11 ( & V_8 -> V_25 ) ;
if ( F_12 ( V_26 , V_8 -> V_27 + V_28 + V_28 / 2 )
|| ! V_8 -> V_29 ) {
int V_30 ;
F_13 ( V_2 , L_4 ) ;
V_24 = F_8 ( V_2 ) ;
if ( V_24 )
goto abort;
V_30 = F_4 ( V_2 , V_31 [ 0 ] ) ;
if ( V_30 < 0 ) {
V_24 = V_30 ;
F_13 ( V_2 , L_5 ,
V_31 [ 0 ] , V_24 ) ;
goto abort;
}
V_8 -> V_30 [ 0 ] = V_30 ;
V_8 -> V_27 = V_26 ;
V_8 -> V_29 = true ;
}
abort:
F_14 ( & V_8 -> V_25 ) ;
return V_24 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
int V_24 ;
int V_21 ;
for ( V_21 = 1 ; V_21 < F_16 ( V_8 -> V_30 ) ; V_21 ++ ) {
V_24 = F_4 ( V_2 , V_31 [ V_21 ] ) ;
if ( V_24 < 0 ) {
F_13 ( V_2 , L_5 ,
V_31 [ V_21 ] , V_24 ) ;
return V_24 ;
}
V_8 -> V_30 [ V_21 ] = V_24 ;
}
V_24 = F_1 ( V_2 , V_32 ) ;
if ( V_24 < 0 ) {
F_13 ( V_2 , L_5 ,
V_32 , V_24 ) ;
return V_24 ;
}
V_8 -> V_33 = V_24 ;
return 0 ;
}
static T_4 F_17 ( long V_30 )
{
return F_18 ( F_19 ( V_30 , V_34 ,
V_35 ) * 128 , 1000 ) ;
}
static int F_20 ( struct V_4 * V_8 , T_4 V_3 )
{
if ( ! ( V_8 -> V_36 & V_37 ) )
V_3 &= V_38 ;
return F_18 ( V_3 * 1000 , 128 ) ;
}
static T_5 F_21 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_42 * V_43 = F_22 ( V_40 ) ;
struct V_4 * V_8 = F_2 ( V_2 ) ;
if ( V_43 -> V_44 == 0 ) {
int V_24 ;
V_24 = F_10 ( V_2 ) ;
if ( V_24 )
return V_24 ;
}
return sprintf ( V_41 , L_6 , F_20 ( V_8 ,
V_8 -> V_30 [ V_43 -> V_44 ] ) ) ;
}
static T_5 F_23 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
const char * V_41 , T_6 V_45 )
{
struct V_42 * V_43 = F_22 ( V_40 ) ;
struct V_4 * V_8 = F_2 ( V_2 ) ;
int V_46 = V_43 -> V_44 ;
long V_30 ;
int V_24 ;
V_24 = F_24 ( V_41 , 10 , & V_30 ) ;
if ( V_24 )
return V_24 ;
F_11 ( & V_8 -> V_25 ) ;
V_8 -> V_30 [ V_46 ] = F_17 ( V_30 ) ;
V_24 = F_5 ( V_2 , V_31 [ V_46 ] , V_8 -> V_30 [ V_46 ] ) ;
if ( V_24 )
V_45 = V_24 ;
F_14 ( & V_8 -> V_25 ) ;
return V_45 ;
}
static T_5 F_25 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_42 * V_43 = F_22 ( V_40 ) ;
struct V_4 * V_8 = F_2 ( V_2 ) ;
int V_46 = V_43 -> V_44 ;
int V_33 ;
V_33 = ( V_8 -> V_33 & V_47 ) * 1000 ;
if ( V_46 == 2 )
V_33 = - V_33 ;
return sprintf ( V_41 , L_6 ,
F_20 ( V_8 , V_8 -> V_30 [ V_46 ] ) - V_33 ) ;
}
static T_5 F_26 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
const char * V_41 , T_6 V_45 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
int V_48 , V_24 ;
long V_33 ;
V_24 = F_24 ( V_41 , 10 , & V_33 ) ;
if ( V_24 )
return V_24 ;
V_48 = F_20 ( V_8 , V_8 -> V_30 [ 1 ] ) ;
V_33 = F_19 ( V_33 , V_34 , V_35 ) ;
V_8 -> V_33 = F_19 ( F_18 ( V_48 - V_33 , 1000 ) ,
0 , V_47 ) ;
V_24 = F_3 ( V_2 , V_32 , V_8 -> V_33 ) ;
if ( V_24 )
return V_24 ;
return V_45 ;
}
static T_5 F_27 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_42 * V_43 = F_22 ( V_40 ) ;
int V_24 ;
V_24 = F_1 ( V_2 , V_15 ) ;
if ( V_24 < 0 )
return V_24 ;
return sprintf ( V_41 , L_6 , ! ! ( V_24 & V_43 -> V_44 ) ) ;
}
static T_5 F_28 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
char * V_41 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_41 , L_7 , V_8 -> V_49 ) ;
}
int F_29 ( struct V_1 * V_2 , const char * V_49 , int V_12 ,
const struct V_50 * V_6 )
{
struct V_4 * V_8 ;
int V_24 ;
V_8 = F_30 ( V_2 , sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
return - V_52 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_49 = V_49 ;
F_31 ( V_2 , V_8 ) ;
F_32 ( & V_8 -> V_25 ) ;
V_24 = F_1 ( V_2 , V_53 ) ;
if ( V_24 < 0 ) {
F_13 ( V_2 , L_8 , V_24 ) ;
return V_24 ;
}
V_8 -> V_54 = V_24 ;
V_8 -> V_36 = V_8 -> V_54 ;
V_8 -> V_36 &= ~ ( V_55 | V_56 |
V_57 ) ;
V_8 -> V_36 |= V_58 | V_37 | V_59 ;
if ( V_8 -> V_36 != V_8 -> V_54 ) {
V_24 = F_3 ( V_2 , V_53 , V_8 -> V_36 ) ;
if ( V_24 )
return V_24 ;
}
F_13 ( V_2 , L_9 , V_8 -> V_36 ) ;
V_24 = F_15 ( V_2 ) ;
if ( V_24 )
goto V_60;
V_24 = F_33 ( & V_2 -> V_18 , & V_61 ) ;
if ( V_24 )
goto V_60;
if ( V_49 ) {
V_24 = F_34 ( V_2 , & V_62 ) ;
if ( V_24 )
goto V_63;
}
V_8 -> V_64 = F_35 ( V_2 ) ;
if ( F_36 ( V_8 -> V_64 ) ) {
V_24 = F_37 ( V_8 -> V_64 ) ;
goto V_65;
}
if ( V_12 > 0 ) {
V_24 = F_38 ( V_12 , NULL , F_6 ,
V_66 | V_67 ,
F_39 ( V_2 ) , V_2 ) ;
if ( V_24 )
goto V_68;
}
return 0 ;
V_68:
F_40 ( V_8 -> V_64 ) ;
V_65:
if ( V_49 )
F_41 ( V_2 , & V_62 ) ;
V_63:
F_42 ( & V_2 -> V_18 , & V_61 ) ;
V_60:
F_3 ( V_2 , V_53 , V_8 -> V_54 ) ;
return V_24 ;
}
int F_43 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
if ( V_12 > 0 )
F_44 ( V_12 , V_2 ) ;
F_40 ( V_8 -> V_64 ) ;
if ( V_8 -> V_49 )
F_41 ( V_2 , & V_62 ) ;
F_42 ( & V_2 -> V_18 , & V_61 ) ;
if ( V_8 -> V_54 != V_8 -> V_36 )
F_3 ( V_2 , V_53 , V_8 -> V_54 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
return F_3 ( V_2 , V_53 ,
V_8 -> V_36 | V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_8 = F_2 ( V_2 ) ;
return F_3 ( V_2 , V_53 , V_8 -> V_36 ) ;
}
