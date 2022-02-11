static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 ;
F_4 ( & V_8 -> V_13 ) ;
if ( F_5 ( V_8 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_12 = F_6 ( V_5 , 10 , & V_11 ) ;
if ( V_12 )
goto V_15;
V_12 = F_7 ( V_10 , V_11 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = V_6 ;
V_15:
F_8 ( & V_8 -> V_13 ) ;
return V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_10 ( V_10 ) ;
return sprintf ( V_5 , L_1 , V_10 -> V_16 . V_17 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return sprintf ( V_5 , L_1 , V_10 -> V_16 . V_18 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_11 ;
T_1 V_12 = - V_19 ;
F_4 ( & V_8 -> V_13 ) ;
if ( F_5 ( V_8 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_12 = F_6 ( V_5 , 10 , & V_11 ) ;
if ( V_12 )
goto V_15;
if ( V_11 < 0 || V_11 > 1 ) {
V_12 = - V_19 ;
goto V_15;
}
V_12 = F_13 ( V_10 , V_11 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = V_6 ;
V_15:
F_8 ( & V_8 -> V_13 ) ;
return V_12 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
bool V_11 ;
int V_12 ;
V_12 = F_15 ( V_10 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_5 , L_1 , V_11 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_20 ;
T_1 V_12 ;
F_4 ( & V_8 -> V_13 ) ;
if ( F_5 ( V_8 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_12 = F_6 ( V_5 , 10 , & V_20 ) ;
if ( V_12 )
goto V_15;
V_12 = F_17 ( V_10 , V_20 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = V_6 ;
V_15:
F_8 ( & V_8 -> V_13 ) ;
return V_12 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return sprintf ( V_5 , L_1 , V_10 -> V_21 . V_17 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return sprintf ( V_5 , L_1 , V_10 -> V_21 . V_18 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_3 V_22 , V_23 = 0x1 ;
char * V_24 = V_5 ;
int V_25 , V_12 , V_26 ;
V_12 = F_21 ( V_10 , & V_22 ) ;
if ( V_12 < 0 )
return - V_19 ;
* V_5 = '\0' ;
for ( V_25 = 0 ; V_25 < V_27 ; ++ V_25 ) {
if ( V_22 & V_23 ) {
V_26 = sprintf ( V_24 , L_2 ,
V_28 [ V_25 ] ) ;
V_24 += V_26 ;
}
V_23 <<= 1 ;
}
return sprintf ( V_5 , L_3 , V_5 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
char * V_24 = V_5 ;
int V_25 , V_26 ;
V_26 = sprintf ( V_24 , L_4 ) ;
V_24 += V_26 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_29 ; ++ V_25 ) {
V_26 = sprintf ( V_24 , L_5 , V_25 + 1 ,
V_10 -> V_30 [ V_25 ] -> V_8 . V_31 ) ;
V_24 += V_26 ;
}
return sprintf ( V_5 , L_3 , V_5 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_32 ;
T_1 V_12 ;
F_4 ( & V_8 -> V_13 ) ;
if ( F_5 ( V_8 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_12 = F_6 ( V_5 , 10 , & V_32 ) ;
if ( V_12 )
goto V_15;
if ( V_32 > V_10 -> V_29 ) {
V_12 = - V_33 ;
goto V_15;
}
V_10 -> V_34 = V_32 ;
V_12 = V_6 ;
V_15:
F_8 ( & V_8 -> V_13 ) ;
return V_12 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_35 = V_10 -> V_34 ;
char * V_36 = L_6 ;
if ( V_10 -> V_34 > 0 )
V_36 = ( char * )
V_10 -> V_30 [ V_35 - 1 ] -> V_8 . V_31 ;
return sprintf ( V_5 , L_7 , V_35 , V_36 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_26 ( V_10 , V_37 ,
V_10 -> V_16 . V_17 ) ;
F_26 ( V_10 , V_38 , V_10 -> V_21 . V_17 ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
const struct V_39 * V_40 = V_10 -> V_40 ;
const struct V_41 * * V_42 = V_10 -> V_43 ;
int V_44 = 0 ;
V_42 [ V_44 ++ ] = & V_45 ;
if ( V_40 -> V_37 )
V_42 [ V_44 ++ ] = & V_46 ;
if ( V_40 -> V_38 )
V_42 [ V_44 ++ ] = & V_47 ;
if ( V_40 -> V_48 )
V_42 [ V_44 ++ ] = & V_49 ;
if ( V_8 -> V_50 & V_51 )
V_42 [ V_44 ++ ] = & V_52 ;
V_8 -> V_53 = V_42 ;
}
int F_28 ( struct V_1 * V_54 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 ;
const struct V_39 * V_40 ;
int V_12 ;
if ( ! V_10 )
return - V_19 ;
V_8 = & V_10 -> V_8 ;
if ( V_8 -> V_50 & V_55 ) {
if ( ! V_8 -> V_56 )
return - V_19 ;
V_40 = V_10 -> V_40 ;
if ( ! V_40 || ! V_40 -> V_57 )
return - V_19 ;
V_8 -> V_58 = F_25 ;
F_27 ( V_10 ) ;
}
V_12 = F_29 ( V_54 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_8 -> V_50 &= ~ V_59 ;
V_8 -> V_50 |= V_60 ;
return 0 ;
}
void F_30 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_31 ( & V_10 -> V_8 ) ;
}
static void F_32 ( struct V_61 * V_62 )
{
T_3 V_63 , V_64 ;
V_63 = V_62 -> V_17 + V_62 -> V_65 / 2 ;
V_63 = F_33 ( V_63 , V_62 -> V_66 , V_62 -> V_18 ) ;
V_64 = V_63 - V_62 -> V_66 ;
V_64 = V_62 -> V_65 * ( V_64 / V_62 -> V_65 ) ;
V_62 -> V_17 = V_62 -> V_66 + V_64 ;
}
int F_17 ( struct V_9 * V_10 , T_3 V_21 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_61 * V_62 = & V_10 -> V_21 ;
V_62 -> V_17 = V_21 ;
F_32 ( V_62 ) ;
if ( ! ( V_8 -> V_50 & V_67 ) )
return F_26 ( V_10 , V_38 , V_62 -> V_17 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , T_3 * V_22 )
{
return F_26 ( V_10 , V_48 , V_22 ) ;
}
int F_7 ( struct V_9 * V_10 ,
T_3 V_16 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_61 * V_62 = & V_10 -> V_16 ;
V_62 -> V_17 = V_16 ;
F_32 ( V_62 ) ;
if ( ! ( V_8 -> V_50 & V_67 ) )
return F_26 ( V_10 , V_37 , V_62 -> V_17 ) ;
return 0 ;
}
int F_10 ( struct V_9 * V_10 )
{
struct V_61 * V_62 = & V_10 -> V_16 ;
T_3 V_16 ;
if ( F_34 ( V_10 , V_68 ) ) {
int V_12 = F_26 ( V_10 , V_68 ,
& V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_62 -> V_17 = V_16 ;
}
return 0 ;
}
