static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_10 = F_4 ( V_9 -> V_11 ) ;
return sprintf ( V_5 , L_1 , V_10 / ( V_12 + 1 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_10 = F_4 ( V_9 -> V_11 ) ;
return sprintf ( V_5 , L_1 , V_10 / 2 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( F_7 ( V_9 -> V_13 + V_14 ) & 0x1 ) {
unsigned long V_10 = F_4 ( V_9 -> V_11 ) ;
T_2 V_15 = F_7 ( V_9 -> V_13 + V_16 ) ;
return sprintf ( V_5 , L_1 , V_10 / ( V_15 + 1 ) ) ;
} else {
return sprintf ( V_5 , L_2 ) ;
}
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_3 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
long V_18 ;
int V_19 ;
V_19 = F_9 ( V_5 , 10 , & V_18 ) ;
if ( V_19 )
return - V_20 ;
if ( V_18 == 0 ) {
F_10 ( 0x0 , V_9 -> V_13 + V_14 ) ;
} else if ( V_18 <= ( F_4 ( V_9 -> V_11 ) / 2 ) ) {
T_4 V_15 , V_21 ;
V_18 = ( F_4 ( V_9 -> V_11 ) / V_18 ) - 1 ;
if ( V_18 > V_12 )
V_18 = V_12 ;
if ( V_18 < 1 )
V_18 = 1 ;
V_15 = F_7 ( V_9 -> V_13 + V_16 ) ;
V_21 = ( ( V_18 + 1 ) * V_9 -> V_22 / 100 ) - 1 ;
if ( V_18 > V_15 ) {
F_10 ( V_18 , V_9 -> V_13 + V_16 ) ;
F_10 ( V_21 , V_9 -> V_13 + V_23 ) ;
} else {
F_10 ( V_21 , V_9 -> V_13 + V_23 ) ;
F_10 ( V_18 , V_9 -> V_13 + V_16 ) ;
}
if ( ! F_7 ( V_9 -> V_13 + V_14 ) & 0x1 )
F_10 ( 0x1 , V_9 -> V_13 + V_14 ) ;
} else {
return - V_20 ;
}
return V_17 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_3 , V_9 -> V_22 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_3 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
long V_18 ;
int V_19 ;
V_19 = F_9 ( V_5 , 10 , & V_18 ) ;
if ( V_19 )
return - V_20 ;
if ( V_18 > 0 && V_18 < 100 ) {
T_4 V_15 = F_7 ( V_9 -> V_13 + V_16 ) ;
T_4 V_21 = ( ( V_15 + 1 ) * V_18 / 100 ) - 1 ;
F_10 ( V_21 , V_9 -> V_13 + V_23 ) ;
V_9 -> V_22 = V_18 ;
return V_17 ;
}
return - V_20 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_24 = F_7 ( V_9 -> V_13 + V_25 ) & 0x1 ;
return sprintf ( V_5 , L_3 , V_24 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_3 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
long V_18 ;
int V_19 ;
V_19 = F_9 ( V_5 , 10 , & V_18 ) ;
if ( V_19 )
return - V_20 ;
if ( V_18 == 0 )
F_10 ( 0x0 , V_9 -> V_13 + V_25 ) ;
else if ( V_18 == 1 )
F_10 ( 0x1 , V_9 -> V_13 + V_25 ) ;
else
return - V_20 ;
return V_17 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_26 * V_27 ;
int V_28 ;
V_9 = F_16 ( & V_7 -> V_2 , sizeof( * V_9 ) , V_29 ) ;
if ( ! V_9 )
return - V_30 ;
V_9 -> V_11 = F_17 ( & V_7 -> V_2 , L_4 ) ;
if ( F_18 ( V_9 -> V_11 ) )
return F_19 ( V_9 -> V_11 ) ;
V_27 = F_20 ( V_7 , V_31 , 0 ) ;
V_9 -> V_13 = F_21 ( & V_7 -> V_2 , V_27 ) ;
if ( F_18 ( V_9 -> V_13 ) )
return F_19 ( V_9 -> V_13 ) ;
V_28 = F_22 ( V_7 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_23 ( & V_7 -> V_2 . V_32 , & V_33 ) ;
if ( V_28 ) {
F_24 ( V_7 ) ;
return V_28 ;
}
V_9 -> V_22 = 50 ;
F_10 ( 0x0 , V_9 -> V_13 + V_14 ) ;
F_10 ( V_12 , V_9 -> V_13 + V_16 ) ;
F_10 ( V_12 / 2 , V_9 -> V_13 + V_23 ) ;
F_25 ( V_9 -> V_11 ) ;
F_26 ( V_7 , V_9 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_10 ( 0x0 , V_9 -> V_13 + V_14 ) ;
F_28 ( V_9 -> V_11 ) ;
F_29 ( & V_7 -> V_2 . V_32 , & V_33 ) ;
F_24 ( V_7 ) ;
return 0 ;
}
