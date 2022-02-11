static void F_1 ( void )
{
static unsigned long V_1 ;
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = V_1 ;
V_1 = F_2 () ;
if ( ! V_1 ||
( V_1 > V_2 ) ) {
V_4 = V_5 ;
return;
}
if ( V_4 && -- V_4 )
return;
if ( V_1 <= V_6 )
V_3 = 0 ;
else
V_3 = V_1 -
( V_1 / V_6 ) ;
F_3 ( V_3 ) ;
V_4 = V_5 ;
}
static void F_4 ( struct V_7 * V_8 )
{
unsigned long V_9 , V_10 , V_11 , V_12 ;
unsigned long V_13 ;
bool V_14 = false ;
if ( V_15 ) {
V_9 = V_16 ;
V_11 = V_9 ;
V_10 = F_5 () +
V_17 +
F_6 ( V_18 ) ;
#ifdef F_7
if ( V_19 )
V_10 += F_2 () ;
#endif
if ( V_9 > V_10 )
V_11 = V_9 -
( ( V_9 - V_10 ) /
V_20 ) ;
else if ( V_9 < V_10 )
V_11 = V_9 +
( ( V_10 - V_9 ) /
V_21 ) ;
V_13 = V_22 - V_17 ;
if ( V_23 != 0 )
V_12 = V_17 +
F_6 ( V_23 ) ;
else if ( V_13 < F_6 ( 16 ) )
V_12 = V_22 ;
else if ( V_13 < F_6 ( 64 ) )
V_12 = V_17 + F_6 ( 16 ) +
( ( V_13 - F_6 ( 16 ) ) >> 1 ) ;
else if ( V_13 < F_6 ( 512 ) )
V_12 = V_17 + F_6 ( 40 ) +
( ( V_13 - F_6 ( 40 ) ) >> 3 ) ;
else
V_12 = V_17 + F_6 ( 99 ) +
( ( V_13 - F_6 ( 99 ) ) >> 5 ) ;
if ( V_11 < V_12 )
V_11 = V_12 ;
F_8 ( V_11 +
V_24 . V_25 - V_16 ) ;
V_14 = true ;
}
#ifdef F_7
if ( V_19 ) {
F_1 () ;
V_14 = true ;
}
#endif
if ( V_14 )
F_9 ( & V_26 ,
V_27 * V_28 ) ;
}
static T_1 F_10 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
bool V_35 = V_15 ;
unsigned long V_36 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_36 ) ;
if ( V_37 )
return V_37 ;
if ( ( V_36 != 0 ) && ( V_36 != 1 ) )
return - V_40 ;
V_15 = ! ! V_36 ;
if ( ! V_35 && V_15 )
F_9 ( & V_26 ,
V_27 * V_28 ) ;
return V_34 ;
}
static T_1 F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_27 = V_41 ;
return V_34 ;
}
static T_1 F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_20 = V_41 ;
return V_34 ;
}
static T_1 F_15 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_21 = V_41 ;
return V_34 ;
}
static T_1 F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_23 = V_41 ;
return V_34 ;
}
static T_1 F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_18 = V_41 ;
return V_34 ;
}
static T_1 F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
bool V_35 = V_19 ;
unsigned long V_36 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_36 ) ;
if ( V_37 )
return V_37 ;
if ( ( V_36 != 0 ) && ( V_36 != 1 ) )
return - V_40 ;
V_19 = ! ! V_36 ;
if ( ! V_35 && ! V_15 &&
V_19 )
F_9 ( & V_26 ,
V_27 * V_28 ) ;
return V_34 ;
}
static T_1 F_19 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_5 = V_41 ;
V_4 = V_41 ;
return V_34 ;
}
static T_1 F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_34 )
{
unsigned long V_41 ;
int V_37 ;
if ( ! F_11 ( V_38 ) )
return - V_39 ;
V_37 = F_12 ( V_33 , 10 , & V_41 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 == 0 )
return - V_40 ;
V_6 = V_41 ;
return V_34 ;
}
int F_21 ( struct V_29 * V_30 )
{
int error = - 1 ;
#ifdef F_22
error = F_23 ( & V_30 -> V_42 , & V_43 ) ;
#endif
return error ;
}
int F_24 ( bool V_44 , bool V_45 )
{
bool V_46 = false ;
unsigned long V_47 ;
if ( ! F_25 () )
return - V_48 ;
if ( F_26 () ) {
F_27 ( L_1 ) ;
return - V_48 ;
}
V_15 = V_49 && V_44 ;
if ( V_15 ) {
F_27 ( L_2 ) ;
V_46 = true ;
}
#ifdef F_7
V_19 = V_49 && V_45 ;
if ( V_19 ) {
F_27 ( L_3 ) ;
V_46 = true ;
}
#endif
if ( ! V_46 )
return - V_48 ;
if ( ! V_18 ) {
V_47 = V_16 / 10 ;
V_18 = F_28 ( V_47 ) ;
}
F_9 ( & V_26 , V_27 * V_28 ) ;
return 0 ;
}
