static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
long V_11 ;
short V_12 ;
T_3 V_13 ;
int V_14 = F_4 ( V_5 , 10 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_12 = F_5 ( V_11 / 250 , V_15 , V_16 ) << 5 ;
V_13 = F_6 ( V_10 , V_8 -> V_17 , V_12 ) ;
return ( V_13 < 0 ) ? V_13 : V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_11 ;
T_3 V_13 = F_8 ( V_10 , V_8 -> V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = ( ( ( V_18 ) V_13 ) * 250 ) / 32 ;
return F_9 ( V_5 , V_19 , L_1 , V_11 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_20 * V_21 = F_11 ( V_10 ) ;
unsigned long V_22 ;
T_3 V_13 ;
int V_23 = 0 ;
V_13 = F_12 ( V_5 , 10 , & V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
while ( V_23 < ( V_24 ( V_25 ) - 1 ) &&
V_22 > V_25 [ V_23 ] )
V_23 ++ ;
F_13 ( & V_21 -> V_26 ) ;
V_21 -> V_27 &= V_28 ;
V_21 -> V_27 |= V_23 << V_29 ;
V_13 = F_14 ( V_10 , V_30 , V_21 -> V_27 ) ;
F_15 ( & V_21 -> V_26 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_6 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_20 * V_21 = F_11 ( V_10 ) ;
int V_23 ;
V_23 = ( V_21 -> V_27 & V_31 ) >> V_29 ;
return F_9 ( V_5 , V_19 , L_2 , V_25 [ V_23 ] ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_20 * V_21 = F_11 ( V_10 ) ;
T_3 V_27 ;
F_13 ( & V_21 -> V_26 ) ;
V_27 = F_18 ( V_10 , V_30 ) ;
if ( V_27 < 0 )
goto abort;
V_21 -> V_27 = V_27 ;
F_15 ( & V_21 -> V_26 ) ;
return F_9 ( V_5 , V_19 , L_1 , ( V_27 >> V_8 -> V_17 ) & 1 ) ;
abort:
F_15 ( & V_21 -> V_26 ) ;
return V_27 ;
}
static int
F_19 ( struct V_9 * V_10 , const struct V_32 * V_33 )
{
int V_14 ;
struct V_20 * V_21 ;
int V_27 ;
V_21 = F_20 ( & V_10 -> V_2 , sizeof( struct V_20 ) ,
V_34 ) ;
if ( ! V_21 )
return - V_35 ;
F_21 ( V_10 , V_21 ) ;
F_22 ( & V_21 -> V_26 ) ;
V_27 = F_18 ( V_10 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_21 -> V_27 = V_27 ;
V_14 = F_23 ( & V_10 -> V_2 . V_36 , & V_37 ) ;
if ( V_14 )
return V_14 ;
V_21 -> V_38 = F_24 ( & V_10 -> V_2 ) ;
if ( F_25 ( V_21 -> V_38 ) ) {
V_14 = F_26 ( V_21 -> V_38 ) ;
goto V_39;
}
F_27 ( & V_10 -> V_2 , L_3 ,
F_28 ( V_21 -> V_38 ) , V_10 -> V_40 ) ;
return 0 ;
V_39:
F_29 ( & V_10 -> V_2 . V_36 , & V_37 ) ;
return V_14 ;
}
static int F_30 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_11 ( V_10 ) ;
F_31 ( V_21 -> V_38 ) ;
F_29 ( & V_10 -> V_2 . V_36 , & V_37 ) ;
return 0 ;
}
static int F_32 ( struct V_9 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_41 -> V_45 ;
int V_33 , V_27 , V_46 ;
if ( ! F_33 ( V_45 , V_47 |
V_48 ) )
return - V_49 ;
V_27 = F_18 ( V_41 , V_30 ) ;
if ( V_27 < 0 || ( V_27 & 0x10 ) )
return - V_49 ;
V_46 = F_18 ( V_41 , V_50 ) ;
if ( V_46 < 0 || ( V_46 & 0x0c ) )
return - V_49 ;
V_33 = F_18 ( V_41 , V_51 ) ;
if ( V_33 < 0 || V_33 != ( V_52 & 0xff ) )
return - V_49 ;
V_33 = F_34 ( V_41 , V_51 ) ;
if ( V_33 < 0 || V_33 != V_52 )
return - V_49 ;
F_35 ( V_43 -> type , L_4 , V_53 ) ;
return 0 ;
}
