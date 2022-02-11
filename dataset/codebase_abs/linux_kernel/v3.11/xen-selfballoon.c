static void F_1 ( void )
{
static unsigned long V_1 ;
static unsigned long V_2 ;
static unsigned long V_3 ;
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
if ( V_19 && V_20 )
V_10 += F_2 () ;
#endif
if ( V_9 > V_10 )
V_11 = V_9 -
( ( V_9 - V_10 ) /
V_21 ) ;
else if ( V_9 < V_10 )
V_11 = V_9 +
( ( V_10 - V_9 ) /
V_22 ) ;
V_13 = V_23 - V_17 ;
if ( V_24 != 0 )
V_12 = V_17 +
F_6 ( V_24 ) ;
else if ( V_13 < F_6 ( 16 ) )
V_12 = V_23 ;
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
V_25 . V_26 - V_16 ) ;
V_14 = true ;
}
#ifdef F_7
if ( V_19 && V_20 ) {
F_1 () ;
V_14 = true ;
}
#endif
if ( V_14 )
F_9 ( & V_27 ,
V_28 * V_29 ) ;
}
static T_1 F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
bool V_36 = V_15 ;
unsigned long V_37 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_37 ) ;
if ( V_38 || ( ( V_37 != 0 ) && ( V_37 != 1 ) ) )
return - V_41 ;
V_15 = ! ! V_37 ;
if ( ! V_36 && V_15 )
F_9 ( & V_27 ,
V_28 * V_29 ) ;
return V_35 ;
}
static T_1 F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_28 = V_42 ;
return V_35 ;
}
static T_1 F_14 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_21 = V_42 ;
return V_35 ;
}
static T_1 F_15 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_22 = V_42 ;
return V_35 ;
}
static T_1 F_16 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_24 = V_42 ;
return V_35 ;
}
static T_1 F_17 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_18 = V_42 ;
return V_35 ;
}
static T_1 F_18 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
bool V_36 = V_19 ;
unsigned long V_37 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_37 ) ;
if ( V_38 || ( ( V_37 != 0 ) && ( V_37 != 1 ) ) )
return - V_41 ;
V_19 = ! ! V_37 ;
if ( ! V_36 && ! V_15 &&
V_19 )
F_9 ( & V_27 ,
V_28 * V_29 ) ;
return V_35 ;
}
static T_1 F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_5 = V_42 ;
V_4 = V_42 ;
return V_35 ;
}
static T_1 F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 ,
T_2 V_35 )
{
unsigned long V_42 ;
int V_38 ;
if ( ! F_11 ( V_39 ) )
return - V_40 ;
V_38 = F_12 ( V_34 , 10 , & V_42 ) ;
if ( V_38 || V_42 == 0 )
return - V_41 ;
V_6 = V_42 ;
return V_35 ;
}
int F_21 ( struct V_30 * V_31 )
{
int error = - 1 ;
#ifdef F_22
error = F_23 ( & V_31 -> V_43 , & V_44 ) ;
#endif
return error ;
}
int F_24 ( bool V_45 , bool V_46 )
{
bool V_47 = false ;
if ( ! F_25 () )
return - V_48 ;
if ( F_26 () ) {
F_27 ( L_1 ) ;
return - V_48 ;
}
V_15 = V_49 && V_45 ;
if ( V_15 ) {
F_27 ( L_2 ) ;
V_47 = true ;
}
#ifdef F_7
V_19 = V_49 && V_46 ;
if ( V_19 ) {
F_27 ( L_3 ) ;
V_47 = true ;
}
#endif
if ( ! V_47 )
return - V_48 ;
F_9 ( & V_27 , V_28 * V_29 ) ;
return 0 ;
}
