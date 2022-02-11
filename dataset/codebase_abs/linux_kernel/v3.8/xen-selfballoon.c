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
static int T_1 F_4 ( char * V_7 )
{
V_8 = false ;
return 1 ;
}
static int T_1 F_5 ( char * V_7 )
{
V_9 = false ;
return 1 ;
}
static int T_1 F_6 ( char * V_7 )
{
V_9 = true ;
return 1 ;
}
static void F_7 ( struct V_10 * V_11 )
{
unsigned long V_12 , V_13 , V_14 , V_15 ;
unsigned long V_16 ;
bool V_17 = false ;
if ( V_18 ) {
V_12 = V_19 ;
V_14 = V_12 ;
V_13 = F_8 () +
V_20 +
F_9 ( V_21 ) ;
#ifdef F_10
if ( V_22 && V_23 )
V_13 += F_2 () ;
#endif
if ( V_12 > V_13 )
V_14 = V_12 -
( ( V_12 - V_13 ) /
V_24 ) ;
else if ( V_12 < V_13 )
V_14 = V_12 +
( ( V_13 - V_12 ) /
V_25 ) ;
V_16 = V_26 - V_20 ;
if ( V_27 != 0 )
V_15 = V_20 +
F_9 ( V_27 ) ;
else if ( V_16 < F_9 ( 16 ) )
V_15 = V_26 ;
else if ( V_16 < F_9 ( 64 ) )
V_15 = V_20 + F_9 ( 16 ) +
( ( V_16 - F_9 ( 16 ) ) >> 1 ) ;
else if ( V_16 < F_9 ( 512 ) )
V_15 = V_20 + F_9 ( 40 ) +
( ( V_16 - F_9 ( 40 ) ) >> 3 ) ;
else
V_15 = V_20 + F_9 ( 99 ) +
( ( V_16 - F_9 ( 99 ) ) >> 5 ) ;
if ( V_14 < V_15 )
V_14 = V_15 ;
F_11 ( V_14 +
V_28 . V_29 - V_19 ) ;
V_17 = true ;
}
#ifdef F_10
if ( V_22 && V_23 ) {
F_1 () ;
V_17 = true ;
}
#endif
if ( V_17 )
F_12 ( & V_30 ,
V_31 * V_32 ) ;
}
static T_2 F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
bool V_39 = V_18 ;
unsigned long V_40 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_40 ) ;
if ( V_41 || ( ( V_40 != 0 ) && ( V_40 != 1 ) ) )
return - V_44 ;
V_18 = ! ! V_40 ;
if ( ! V_39 && V_18 )
F_12 ( & V_30 ,
V_31 * V_32 ) ;
return V_38 ;
}
static T_2 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_31 = V_45 ;
return V_38 ;
}
static T_2 F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_24 = V_45 ;
return V_38 ;
}
static T_2 F_18 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_25 = V_45 ;
return V_38 ;
}
static T_2 F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_27 = V_45 ;
return V_38 ;
}
static T_2 F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_21 = V_45 ;
return V_38 ;
}
static T_2 F_21 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
bool V_39 = V_22 ;
unsigned long V_40 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_40 ) ;
if ( V_41 || ( ( V_40 != 0 ) && ( V_40 != 1 ) ) )
return - V_44 ;
V_22 = ! ! V_40 ;
if ( ! V_39 && ! V_18 &&
V_22 )
F_12 ( & V_30 ,
V_31 * V_32 ) ;
return V_38 ;
}
static T_2 F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_5 = V_45 ;
V_4 = V_45 ;
return V_38 ;
}
static T_2 F_23 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
unsigned long V_45 ;
int V_41 ;
if ( ! F_14 ( V_42 ) )
return - V_43 ;
V_41 = F_15 ( V_37 , 10 , & V_45 ) ;
if ( V_41 || V_45 == 0 )
return - V_44 ;
V_6 = V_45 ;
return V_38 ;
}
int F_24 ( struct V_33 * V_34 )
{
int error = - 1 ;
#ifdef F_25
error = F_26 ( & V_34 -> V_46 , & V_47 ) ;
#endif
return error ;
}
static int T_1 F_27 ( void )
{
bool V_48 = false ;
if ( ! F_28 () )
return - V_49 ;
if ( F_29 () ) {
F_30 ( L_1
L_2 ) ;
return - V_49 ;
}
V_18 = V_50 && V_9 ;
if ( V_18 ) {
F_30 ( L_3
L_4 ) ;
V_48 = true ;
}
#ifdef F_10
V_22 = V_50 && V_8 ;
if ( V_22 ) {
F_30 ( L_5
L_6 ) ;
V_48 = true ;
}
#endif
if ( ! V_48 )
return - V_49 ;
F_12 ( & V_30 , V_31 * V_32 ) ;
return 0 ;
}
