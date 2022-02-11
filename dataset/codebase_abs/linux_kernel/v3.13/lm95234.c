static int F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 )
{
int V_5 ;
T_1 V_6 = 0 ;
if ( V_3 ) {
V_5 = F_2 ( V_2 ,
F_3 ( V_3 - 1 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = V_5 << 8 ;
V_5 = F_2 ( V_2 ,
F_4 ( V_3 - 1 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 |= V_5 ;
* V_4 = V_6 ;
}
if ( ! V_6 ) {
V_5 = F_2 ( V_2 ,
F_5 ( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = V_5 << 8 ;
V_5 = F_2 ( V_2 ,
F_6 ( V_3 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 |= V_5 ;
* V_4 = ( V_7 ) V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
int V_10 , V_11 ;
V_11 = F_2 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_13 = F_8 ( V_14 [ V_11 & 0x03 ] ) ;
for ( V_10 = 0 ; V_10 < F_9 ( V_9 -> V_15 ) ; V_10 ++ ) {
V_11 = F_2 ( V_2 , F_10 ( V_10 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_15 [ V_10 ] = V_11 ;
}
for ( V_10 = 0 ; V_10 < F_9 ( V_9 -> V_16 ) ; V_10 ++ ) {
V_11 = F_2 ( V_2 , F_11 ( V_10 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_16 [ V_10 ] = V_11 ;
}
for ( V_10 = 0 ; V_10 < F_9 ( V_9 -> V_17 ) ; V_10 ++ ) {
V_11 = F_2 ( V_2 , F_12 ( V_10 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_17 [ V_10 ] = V_11 ;
}
V_11 = F_2 ( V_2 , V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_19 = V_11 ;
V_11 = F_2 ( V_2 , V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 -> V_21 = V_11 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_11 ;
F_14 ( & V_9 -> V_22 ) ;
if ( F_15 ( V_23 , V_9 -> V_24 + V_9 -> V_13 ) ||
! V_9 -> V_25 ) {
int V_10 ;
if ( ! V_9 -> V_25 ) {
V_11 = F_7 ( V_9 , V_2 ) ;
if ( V_11 < 0 )
goto abort;
}
V_9 -> V_25 = false ;
for ( V_10 = 0 ; V_10 < F_9 ( V_9 -> V_6 ) ; V_10 ++ ) {
V_11 = F_1 ( V_2 , V_10 , & V_9 -> V_6 [ V_10 ] ) ;
if ( V_11 < 0 )
goto abort;
}
V_11 = F_2 ( V_2 , V_26 ) ;
if ( V_11 < 0 )
goto abort;
V_9 -> V_27 = V_11 ;
V_11 = F_2 ( V_2 , V_28 ) ;
if ( V_11 < 0 )
goto abort;
V_9 -> V_27 |= V_11 << 8 ;
V_11 = F_2 ( V_2 , V_29 ) ;
if ( V_11 < 0 )
goto abort;
V_9 -> V_27 |= V_11 << 16 ;
V_9 -> V_24 = V_23 ;
V_9 -> V_25 = true ;
}
V_11 = 0 ;
abort:
F_16 ( & V_9 -> V_22 ) ;
return V_11 ;
}
static T_2 F_17 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_1 ,
F_20 ( V_9 -> V_6 [ V_3 ] * 125 , 32 ) ) ;
}
static T_2 F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
T_3 V_35 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_2 , ! ! ( V_9 -> V_27 & V_35 ) ) ;
}
static T_2 F_22 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
T_4 V_35 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , V_9 -> V_21 & V_35 ? L_3 : L_4 ) ;
}
static T_2 F_23 ( struct V_30 * V_31 , struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
unsigned long V_5 ;
T_4 V_35 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_24 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_5 != 1 && V_5 != 2 )
return - V_37 ;
F_14 ( & V_9 -> V_22 ) ;
if ( V_5 == 1 )
V_9 -> V_21 |= V_35 ;
else
V_9 -> V_21 &= ~ V_35 ;
V_9 -> V_25 = false ;
F_25 ( V_9 -> V_2 , V_20 ,
V_9 -> V_21 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static T_2 F_26 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_2 , V_9 -> V_16 [ V_3 ] * 1000 ) ;
}
static T_2 F_27 ( struct V_30 * V_31 , struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
long V_5 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_5 = F_29 ( F_20 ( V_5 , 1000 ) , 0 , V_3 ? 255 : 127 ) ;
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_16 [ V_3 ] = V_5 ;
F_25 ( V_9 -> V_2 , F_11 ( V_3 ) , V_5 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static T_2 F_30 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_5 ,
( ( int ) V_9 -> V_16 [ V_3 ] - ( int ) V_9 -> V_19 ) * 1000 ) ;
}
static T_2 F_31 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
return sprintf ( V_34 , L_2 , V_9 -> V_15 [ V_3 ] * 1000 ) ;
}
static T_2 F_32 ( struct V_30 * V_31 , struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
long V_5 ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_5 = F_29 ( F_20 ( V_5 , 1000 ) , 0 , 255 ) ;
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_15 [ V_3 ] = V_5 ;
F_25 ( V_9 -> V_2 , F_10 ( V_3 ) , V_5 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static T_2 F_33 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_5 ,
( ( int ) V_9 -> V_15 [ V_3 ] - ( int ) V_9 -> V_19 ) * 1000 ) ;
}
static T_2 F_34 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
long V_5 ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_5 = F_20 ( V_5 , 1000 ) ;
V_5 = F_29 ( ( int ) V_9 -> V_15 [ V_3 ] - V_5 , 0 , 31 ) ;
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_19 = V_5 ;
F_25 ( V_9 -> V_2 , V_18 , V_5 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static T_2 F_35 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_5 , V_9 -> V_17 [ V_3 ] * 500 ) ;
}
static T_2 F_36 ( struct V_30 * V_31 , struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_3 = F_19 ( V_33 ) -> V_3 ;
int V_11 = F_13 ( V_9 ) ;
long V_5 ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_5 = F_29 ( F_20 ( V_5 , 500 ) , - 128 , 127 ) ;
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_17 [ V_3 ] = V_5 ;
F_25 ( V_9 -> V_2 , F_12 ( V_3 ) , V_5 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static T_2 F_37 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_34 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_11 = F_13 ( V_9 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_34 , L_6 ,
F_20 ( V_9 -> V_13 * 1000 , V_38 ) ) ;
}
static T_2 F_38 ( struct V_30 * V_31 , struct V_32 * V_33 ,
const char * V_34 , T_5 V_36 )
{
struct V_8 * V_9 = F_18 ( V_31 ) ;
int V_11 = F_13 ( V_9 ) ;
unsigned long V_5 ;
T_4 V_39 ;
if ( V_11 )
return V_11 ;
V_11 = F_24 ( V_34 , 10 , & V_5 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
if ( V_5 <= V_14 [ V_39 ] )
break;
}
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_13 = F_8 ( V_14 [ V_39 ] ) ;
F_25 ( V_9 -> V_2 , V_12 , V_39 ) ;
F_16 ( & V_9 -> V_22 ) ;
return V_36 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
int V_44 , V_45 , V_5 ;
if ( ! F_40 ( V_43 , V_46 ) )
return - V_47 ;
V_44 = F_2 ( V_2 , V_48 ) ;
if ( V_44 != V_49 )
return - V_47 ;
V_45 = F_2 ( V_2 , V_50 ) ;
if ( V_45 != V_51 )
return - V_47 ;
V_5 = F_2 ( V_2 , V_52 ) ;
if ( V_5 & 0x30 )
return - V_47 ;
V_5 = F_2 ( V_2 , V_53 ) ;
if ( V_5 & 0xbc )
return - V_47 ;
V_5 = F_2 ( V_2 , V_12 ) ;
if ( V_5 & 0xfc )
return - V_47 ;
V_5 = F_2 ( V_2 , V_20 ) ;
if ( V_5 & 0xe1 )
return - V_47 ;
V_5 = F_2 ( V_2 , V_54 ) ;
if ( V_5 & 0xe1 )
return - V_47 ;
F_41 ( V_41 -> type , L_7 , V_55 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_5 , V_56 ;
V_5 = F_2 ( V_2 , V_53 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & 0x40 )
F_25 ( V_2 , V_53 ,
V_5 & ~ 0x40 ) ;
V_5 = F_2 ( V_2 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_56 = F_2 ( V_2 , V_20 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_56 & V_5 ) {
F_43 ( & V_2 -> V_31 ,
L_8 ,
V_5 ) ;
F_25 ( V_2 , V_20 ,
V_56 & ~ V_5 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_57 * V_58 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_8 * V_9 ;
struct V_30 * V_59 ;
int V_60 ;
V_9 = F_45 ( V_31 , sizeof( struct V_8 ) , V_61 ) ;
if ( ! V_9 )
return - V_62 ;
V_9 -> V_2 = V_2 ;
F_46 ( & V_9 -> V_22 ) ;
V_60 = F_42 ( V_2 ) ;
if ( V_60 < 0 )
return V_60 ;
V_59 = F_47 ( V_31 , V_2 -> V_63 ,
V_9 ,
V_64 ) ;
return F_48 ( V_59 ) ;
}
