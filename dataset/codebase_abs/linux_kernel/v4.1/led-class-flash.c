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
static void F_22 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_23 ( V_10 , V_29 ,
V_10 -> V_16 . V_17 ) ;
F_23 ( V_10 , V_30 , V_10 -> V_21 . V_17 ) ;
}
static void F_24 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
const struct V_31 * V_32 = V_10 -> V_32 ;
const struct V_33 * * V_34 = V_10 -> V_35 ;
int V_36 = 0 ;
V_34 [ V_36 ++ ] = & V_37 ;
if ( V_32 -> V_29 )
V_34 [ V_36 ++ ] = & V_38 ;
if ( V_32 -> V_30 )
V_34 [ V_36 ++ ] = & V_39 ;
if ( V_32 -> V_40 )
V_34 [ V_36 ++ ] = & V_41 ;
V_8 -> V_42 = V_34 ;
}
int F_25 ( struct V_1 * V_43 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 ;
const struct V_31 * V_32 ;
int V_12 ;
if ( ! V_10 )
return - V_19 ;
V_8 = & V_10 -> V_8 ;
if ( V_8 -> V_44 & V_45 ) {
if ( ! V_8 -> V_46 )
return - V_19 ;
V_32 = V_10 -> V_32 ;
if ( ! V_32 || ! V_32 -> V_47 )
return - V_19 ;
V_8 -> V_48 = F_22 ;
F_24 ( V_10 ) ;
}
V_12 = F_26 ( V_43 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
V_8 -> V_44 &= ~ V_49 ;
V_8 -> V_44 |= V_50 ;
return 0 ;
}
void F_27 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return;
F_28 ( & V_10 -> V_8 ) ;
}
static void F_29 ( struct V_51 * V_52 )
{
T_3 V_53 , V_54 ;
V_53 = V_52 -> V_17 + V_52 -> V_55 / 2 ;
V_53 = F_30 ( V_53 , V_52 -> V_56 , V_52 -> V_18 ) ;
V_54 = V_53 - V_52 -> V_56 ;
V_54 = V_52 -> V_55 * ( V_54 / V_52 -> V_55 ) ;
V_52 -> V_17 = V_52 -> V_56 + V_54 ;
}
int F_17 ( struct V_9 * V_10 , T_3 V_21 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_51 * V_52 = & V_10 -> V_21 ;
V_52 -> V_17 = V_21 ;
F_29 ( V_52 ) ;
if ( ! ( V_8 -> V_44 & V_57 ) )
return F_23 ( V_10 , V_30 , V_52 -> V_17 ) ;
return 0 ;
}
int F_21 ( struct V_9 * V_10 , T_3 * V_22 )
{
return F_23 ( V_10 , V_40 , V_22 ) ;
}
int F_7 ( struct V_9 * V_10 ,
T_3 V_16 )
{
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_51 * V_52 = & V_10 -> V_16 ;
V_52 -> V_17 = V_16 ;
F_29 ( V_52 ) ;
if ( ! ( V_8 -> V_44 & V_57 ) )
return F_23 ( V_10 , V_29 , V_52 -> V_17 ) ;
return 0 ;
}
int F_10 ( struct V_9 * V_10 )
{
struct V_51 * V_52 = & V_10 -> V_16 ;
T_3 V_16 ;
if ( F_31 ( V_10 , V_58 ) ) {
int V_12 = F_23 ( V_10 , V_58 ,
& V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_52 -> V_17 = V_16 ;
}
return 0 ;
}
