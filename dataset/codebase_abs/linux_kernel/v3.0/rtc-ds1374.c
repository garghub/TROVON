static int F_1 ( struct V_1 * V_2 , T_1 * time ,
int V_3 , int V_4 )
{
T_2 V_5 [ 4 ] ;
int V_6 ;
int V_7 ;
if ( V_4 > 4 ) {
F_2 ( 1 ) ;
return - V_8 ;
}
V_6 = F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_4 )
return - V_9 ;
for ( V_7 = V_4 - 1 , * time = 0 ; V_7 >= 0 ; V_7 -- )
* time = ( * time << 8 ) | V_5 [ V_7 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 time ,
int V_3 , int V_4 )
{
T_2 V_5 [ 4 ] ;
int V_7 ;
if ( V_4 > 4 ) {
F_2 ( 1 ) ;
return - V_8 ;
}
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
V_5 [ V_7 ] = time & 0xff ;
time >>= 8 ;
}
return F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
int V_10 , V_11 ;
V_11 = F_7 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 & V_13 )
F_8 ( & V_2 -> V_14 ,
L_1
L_2 ) ;
V_11 &= ~ ( V_13 | V_15 ) ;
V_6 = F_9 ( V_2 , V_12 , V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_10 = F_7 ( V_2 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ ( V_17 | V_18 ) ;
return F_9 ( V_2 , V_16 , V_10 ) ;
}
static int F_10 ( struct V_19 * V_14 , struct V_20 * time )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
T_1 V_21 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_21 , V_22 , 4 ) ;
if ( ! V_6 )
F_12 ( V_21 , time ) ;
return V_6 ;
}
static int F_13 ( struct V_19 * V_14 , struct V_20 * time )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned long V_21 ;
F_14 ( time , & V_21 ) ;
return F_4 ( V_2 , V_21 , V_22 , 4 ) ;
}
static int F_15 ( struct V_19 * V_14 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
T_1 V_26 , V_27 ;
int V_28 , V_29 ;
int V_6 = 0 ;
if ( V_2 -> V_30 <= 0 )
return - V_8 ;
F_17 ( & V_25 -> V_31 ) ;
V_28 = V_6 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
V_29 = V_6 = F_7 ( V_2 , V_12 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_1 ( V_2 , & V_26 , V_22 , 4 ) ;
if ( V_6 )
goto V_32;
V_6 = F_1 ( V_2 , & V_27 , V_33 , 3 ) ;
if ( V_6 )
goto V_32;
F_12 ( V_26 + V_27 , & V_24 -> time ) ;
V_24 -> V_34 = ! ! ( V_28 & V_17 ) ;
V_24 -> V_35 = ! ! ( V_29 & V_15 ) ;
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static int F_19 ( struct V_19 * V_14 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
struct V_20 V_26 ;
unsigned long V_36 , V_21 ;
int V_28 ;
int V_6 = 0 ;
if ( V_2 -> V_30 <= 0 )
return - V_8 ;
V_6 = F_10 ( V_14 , & V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
F_14 ( & V_24 -> time , & V_36 ) ;
F_14 ( & V_26 , & V_21 ) ;
if ( F_20 ( V_36 , V_21 ) )
V_36 = 1 ;
else
V_36 -= V_21 ;
F_17 ( & V_25 -> V_31 ) ;
V_6 = V_28 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
V_28 &= ~ V_17 ;
V_6 = F_9 ( V_2 , V_16 , V_28 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_4 ( V_2 , V_36 , V_33 , 3 ) ;
if ( V_6 )
goto V_32;
if ( V_24 -> V_34 ) {
V_28 |= V_17 | V_18 ;
V_28 &= ~ V_37 ;
V_6 = F_9 ( V_2 , V_16 , V_28 ) ;
}
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static T_3 F_21 ( int V_30 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
F_22 ( V_30 ) ;
F_23 ( & V_25 -> V_39 ) ;
return V_40 ;
}
static void F_24 ( struct V_41 * V_39 )
{
struct V_25 * V_25 = F_25 ( V_39 , struct V_25 , V_39 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_11 , V_10 ;
F_17 ( & V_25 -> V_31 ) ;
V_11 = F_7 ( V_2 , V_12 ) ;
if ( V_11 < 0 )
goto V_42;
if ( V_11 & V_15 ) {
V_11 &= ~ V_15 ;
F_9 ( V_2 , V_12 , V_11 ) ;
V_10 = F_7 ( V_2 , V_16 ) ;
if ( V_10 < 0 )
goto V_32;
V_10 &= ~ ( V_17 | V_18 ) ;
F_9 ( V_2 , V_16 , V_10 ) ;
F_26 ( V_25 -> V_43 , 1 , V_44 | V_45 ) ;
}
V_32:
if ( ! V_25 -> V_46 )
F_27 ( V_2 -> V_30 ) ;
V_42:
F_18 ( & V_25 -> V_31 ) ;
}
static int F_28 ( struct V_19 * V_14 , unsigned int V_34 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
struct V_25 * V_25 = F_16 ( V_2 ) ;
int V_6 ;
F_17 ( & V_25 -> V_31 ) ;
V_6 = F_7 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
goto V_32;
if ( V_34 ) {
V_6 |= V_17 | V_18 ;
V_6 &= ~ V_37 ;
} else {
V_6 &= ~ V_17 ;
}
V_6 = F_9 ( V_2 , V_16 , V_6 ) ;
V_32:
F_18 ( & V_25 -> V_31 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
struct V_25 * V_25 ;
int V_6 ;
V_25 = F_30 ( sizeof( struct V_25 ) , V_49 ) ;
if ( ! V_25 )
return - V_50 ;
V_25 -> V_2 = V_2 ;
F_31 ( V_2 , V_25 ) ;
F_32 ( & V_25 -> V_39 , F_24 ) ;
F_33 ( & V_25 -> V_31 ) ;
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
goto V_51;
if ( V_2 -> V_30 > 0 ) {
V_6 = F_34 ( V_2 -> V_30 , F_21 , 0 ,
L_3 , V_2 ) ;
if ( V_6 ) {
F_35 ( & V_2 -> V_14 , L_4 ) ;
goto V_51;
}
F_36 ( & V_2 -> V_14 , 1 ) ;
}
V_25 -> V_43 = F_37 ( V_2 -> V_52 , & V_2 -> V_14 ,
& V_53 , V_54 ) ;
if ( F_38 ( V_25 -> V_43 ) ) {
V_6 = F_39 ( V_25 -> V_43 ) ;
F_35 ( & V_2 -> V_14 , L_5 ) ;
goto V_55;
}
return 0 ;
V_55:
if ( V_2 -> V_30 > 0 )
F_40 ( V_2 -> V_30 , V_2 ) ;
V_51:
F_41 ( V_25 ) ;
return V_6 ;
}
static int T_4 F_42 ( struct V_1 * V_2 )
{
struct V_25 * V_25 = F_16 ( V_2 ) ;
if ( V_2 -> V_30 > 0 ) {
F_17 ( & V_25 -> V_31 ) ;
V_25 -> V_46 = 1 ;
F_18 ( & V_25 -> V_31 ) ;
F_40 ( V_2 -> V_30 , V_2 ) ;
F_43 ( & V_25 -> V_39 ) ;
}
F_44 ( V_25 -> V_43 ) ;
F_41 ( V_25 ) ;
return 0 ;
}
static int F_45 ( struct V_19 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_30 >= 0 && F_46 ( & V_2 -> V_14 ) )
F_47 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_48 ( struct V_19 * V_14 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
if ( V_2 -> V_30 >= 0 && F_46 ( & V_2 -> V_14 ) )
F_49 ( V_2 -> V_30 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_56 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_56 ) ;
}
