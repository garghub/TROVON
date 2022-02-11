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
V_13 = F_6 ( V_10 -> V_17 , V_8 -> V_18 , V_12 ) ;
return ( V_13 < 0 ) ? V_13 : V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_11 ;
T_3 V_13 = F_8 ( V_10 -> V_17 , V_8 -> V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = ( ( ( V_19 ) V_13 ) * 250 ) / 32 ;
return F_9 ( V_5 , V_20 , L_1 , V_11 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned long V_21 ;
T_3 V_13 ;
int V_22 = 0 ;
V_13 = F_11 ( V_5 , 10 , & V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
while ( V_22 < ( V_23 ( V_24 ) - 1 ) &&
V_21 > V_24 [ V_22 ] )
V_22 ++ ;
F_12 ( & V_10 -> V_25 ) ;
V_10 -> V_26 &= V_27 ;
V_10 -> V_26 |= V_22 << V_28 ;
V_13 = F_13 ( V_10 -> V_17 , V_29 ,
V_10 -> V_26 ) ;
F_14 ( & V_10 -> V_25 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_6 ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_22 ;
V_22 = ( V_10 -> V_26 & V_30 ) >> V_28 ;
return F_9 ( V_5 , V_20 , L_2 , V_24 [ V_22 ] ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_3 V_26 ;
F_12 ( & V_10 -> V_25 ) ;
V_26 = F_17 ( V_10 -> V_17 , V_29 ) ;
if ( V_26 < 0 )
goto abort;
V_10 -> V_26 = V_26 ;
F_14 ( & V_10 -> V_25 ) ;
return F_9 ( V_5 , V_20 , L_1 , ( V_26 >> V_8 -> V_18 ) & 1 ) ;
abort:
F_14 ( & V_10 -> V_25 ) ;
return V_26 ;
}
static int
F_18 ( struct V_31 * V_17 , const struct V_32 * V_33 )
{
struct V_1 * V_2 = & V_17 -> V_2 ;
struct V_1 * V_34 ;
struct V_9 * V_10 ;
int V_26 ;
V_10 = F_19 ( V_2 , sizeof( struct V_9 ) , V_35 ) ;
if ( ! V_10 )
return - V_36 ;
V_10 -> V_17 = V_17 ;
F_20 ( & V_10 -> V_25 ) ;
V_26 = F_17 ( V_17 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
V_10 -> V_26 = V_26 ;
V_34 = F_21 ( V_2 , V_17 -> V_37 ,
V_10 , V_38 ) ;
if ( F_22 ( V_34 ) )
return F_23 ( V_34 ) ;
F_24 ( V_2 , L_3 , V_17 -> V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_39 -> V_43 ;
int V_33 , V_26 , V_44 ;
if ( ! F_26 ( V_43 , V_45 |
V_46 ) )
return - V_47 ;
V_26 = F_17 ( V_39 , V_29 ) ;
if ( V_26 < 0 || ( V_26 & 0x10 ) )
return - V_47 ;
V_44 = F_17 ( V_39 , V_48 ) ;
if ( V_44 < 0 || ( V_44 & 0x0c ) )
return - V_47 ;
V_33 = F_17 ( V_39 , V_49 ) ;
if ( V_33 < 0 || V_33 != ( V_50 & 0xff ) )
return - V_47 ;
V_33 = F_27 ( V_39 , V_49 ) ;
if ( V_33 < 0 || V_33 != V_50 )
return - V_47 ;
F_28 ( V_41 -> type , L_4 , V_51 ) ;
return 0 ;
}
