static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_3 ) &
V_4 ;
if ( V_2 == 0 )
return 133333333 ;
else if ( V_2 == 1 )
return 150000000 ;
else if ( V_2 == 2 )
return 166666667 ;
else
return 0 ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_5 ) &
V_6 ;
if ( V_2 == 0 )
return 333333333 ;
else if ( V_2 == 1 || V_2 == 2 )
return 400000000 ;
else if ( V_2 == 3 )
return 500000000 ;
else
return 0 ;
}
static void T_2 F_4 ( void T_3 * V_1 , int V_7 ,
int * V_8 , int * div )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_5 ) &
V_6 ;
if ( V_2 == 0 || V_2 == 1 ) {
* V_8 = 1 ;
* div = 2 ;
} else if ( V_2 == 2 || V_2 == 3 ) {
* V_8 = 1 ;
* div = 3 ;
} else {
* V_8 = 0 ;
* div = 1 ;
}
}
static void T_2 F_5 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , & V_11 ) ;
}
static T_1 T_2 F_7 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_12 ) &
V_13 ;
if ( V_2 == 1 )
return 150000000 ;
else if ( V_2 == 2 )
return 166666667 ;
else
return 0 ;
}
static T_1 T_2 F_8 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) &
V_15 ;
if ( V_2 == 0 )
return 333333333 ;
else if ( V_2 == 1 || V_2 == 2 )
return 400000000 ;
else if ( V_2 == 3 )
return 500000000 ;
else
return 0 ;
}
static void T_2 F_9 ( void T_3 * V_1 , int V_7 ,
int * V_8 , int * div )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) &
V_15 ;
if ( V_2 == 0 || V_2 == 1 ) {
* V_8 = 1 ;
* div = 2 ;
} else if ( V_2 == 2 || V_2 == 3 ) {
* V_8 = 1 ;
* div = 3 ;
} else {
* V_8 = 0 ;
* div = 1 ;
}
}
static void T_2 F_10 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , & V_16 ) ;
}
static T_1 T_2 F_11 ( void T_3 * V_1 )
{
return 166666667 ;
}
static T_1 T_2 F_12 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_17 ) &
V_18 ;
if ( V_2 == 1 || V_2 == 2 )
return 400000000 ;
else if ( V_2 == 3 )
return 500000000 ;
else
return 0 ;
}
static void T_2 F_13 ( void T_3 * V_1 , int V_7 ,
int * V_8 , int * div )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_17 ) &
V_18 ;
if ( V_2 == 1 ) {
* V_8 = 1 ;
* div = 2 ;
} else if ( V_2 == 2 || V_2 == 3 ) {
* V_8 = 1 ;
* div = 3 ;
} else {
* V_8 = 0 ;
* div = 1 ;
}
}
static void T_2 F_14 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , & V_19 ) ;
}
static T_1 T_2 F_15 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_20 ) &
V_21 ;
if ( V_2 == 0 )
return 133333333 ;
else if ( V_2 == 1 )
return 166666667 ;
else
return 0 ;
}
static T_1 T_2 F_16 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_22 ) &
V_23 ;
if ( V_2 == 9 )
return 333333333 ;
else if ( V_2 == 17 )
return 400000000 ;
else
return 0 ;
}
static void T_2 F_17 ( void T_3 * V_1 , int V_7 ,
int * V_8 , int * div )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_22 ) &
V_23 ;
if ( V_2 == 9 || V_2 == 17 ) {
* V_8 = 1 ;
* div = 2 ;
} else {
* V_8 = 0 ;
* div = 1 ;
}
}
static void T_2 F_18 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , & V_24 ) ;
}
