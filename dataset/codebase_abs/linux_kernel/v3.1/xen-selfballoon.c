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
unsigned long V_12 , V_13 , V_14 ;
bool V_15 = false ;
if ( V_16 ) {
V_12 = V_17 . V_18 ;
V_14 = V_12 ;
V_13 = F_8 ( & V_19 ) +
V_17 . V_18 - V_20 ;
#ifdef F_9
if ( V_21 && V_22 )
V_13 += F_2 () ;
#endif
if ( V_12 > V_13 )
V_14 = V_12 -
( ( V_12 - V_13 ) /
V_23 ) ;
else if ( V_12 < V_13 )
V_14 = V_12 +
( ( V_13 - V_12 ) /
V_24 ) ;
F_10 ( V_14 ) ;
V_15 = true ;
}
#ifdef F_9
if ( V_21 && V_22 ) {
F_1 () ;
V_15 = true ;
}
#endif
if ( V_15 )
F_11 ( & V_25 ,
V_26 * V_27 ) ;
}
static T_2 F_12 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
bool V_34 = V_16 ;
unsigned long V_35 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_35 ) ;
if ( V_36 || ( ( V_35 != 0 ) && ( V_35 != 1 ) ) )
return - V_39 ;
V_16 = ! ! V_35 ;
if ( ! V_34 && V_16 )
F_11 ( & V_25 ,
V_26 * V_27 ) ;
return V_33 ;
}
static T_2 F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
unsigned long V_40 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_40 ) ;
if ( V_36 || V_40 == 0 )
return - V_39 ;
V_26 = V_40 ;
return V_33 ;
}
static T_2 F_16 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
unsigned long V_40 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_40 ) ;
if ( V_36 || V_40 == 0 )
return - V_39 ;
V_23 = V_40 ;
return V_33 ;
}
static T_2 F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
unsigned long V_40 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_40 ) ;
if ( V_36 || V_40 == 0 )
return - V_39 ;
V_24 = V_40 ;
return V_33 ;
}
static T_2 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
bool V_34 = V_21 ;
unsigned long V_35 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_35 ) ;
if ( V_36 || ( ( V_35 != 0 ) && ( V_35 != 1 ) ) )
return - V_39 ;
V_21 = ! ! V_35 ;
if ( ! V_34 && ! V_16 &&
V_21 )
F_11 ( & V_25 ,
V_26 * V_27 ) ;
return V_33 ;
}
static T_2 F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
unsigned long V_40 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_40 ) ;
if ( V_36 || V_40 == 0 )
return - V_39 ;
V_5 = V_40 ;
V_4 = V_40 ;
return V_33 ;
}
static T_2 F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 ,
T_3 V_33 )
{
unsigned long V_40 ;
int V_36 ;
if ( ! F_13 ( V_37 ) )
return - V_38 ;
V_36 = F_14 ( V_32 , 10 , & V_40 ) ;
if ( V_36 || V_40 == 0 )
return - V_39 ;
V_6 = V_40 ;
return V_33 ;
}
int F_21 ( struct V_28 * V_41 )
{
int error = - 1 ;
#ifdef F_22
error = F_23 ( & V_41 -> V_42 , & V_43 ) ;
#endif
return error ;
}
static int T_1 F_24 ( void )
{
bool V_44 = false ;
if ( ! F_25 () )
return - V_45 ;
if ( F_26 () ) {
F_27 ( L_1
L_2 ) ;
return - V_45 ;
}
V_16 = V_46 && V_9 ;
if ( V_16 ) {
F_27 ( L_3
L_4 ) ;
V_44 = true ;
}
#ifdef F_9
V_21 = V_46 && V_8 ;
if ( V_21 ) {
F_27 ( L_5
L_6 ) ;
V_44 = true ;
}
#endif
if ( ! V_44 )
return - V_45 ;
F_11 ( & V_25 , V_26 * V_27 ) ;
return 0 ;
}
