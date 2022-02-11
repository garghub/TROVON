static inline T_1 F_1 ( const volatile void T_2 * V_1 )
{
const volatile T_3 T_2 * V_2 = V_1 ;
T_3 V_3 , V_4 ;
V_3 = F_2 ( V_2 ) ;
V_4 = F_2 ( V_2 + 1 ) ;
return V_3 + ( ( V_5 ) V_4 << 32 ) ;
}
static void T_2 * F_3 ( T_4 V_1 , unsigned long V_6 )
{
if ( V_7 == V_8 )
return F_4 ( V_1 , V_6 ) ;
return F_5 ( V_1 , V_6 ) ;
}
static void F_6 ( void T_2 * V_1 )
{
if ( V_1 && V_7 == V_8 )
F_7 ( V_1 ) ;
else
F_8 ( V_1 ) ;
}
static int F_9 ( T_5 V_9 )
{
int V_10 = 0 , V_11 = 0 ;
static T_3 V_12 ;
F_10 ( L_1 , V_13 , V_9 ) ;
V_9 = V_9 == 1 ? V_14 : V_15 ;
F_11 ( & V_16 ) ;
if ( F_12 ( & V_17 -> V_18 ) != V_9 ) {
F_13 ( V_9 , & V_17 -> V_19 ) ;
switch ( V_20 ) {
case 8 :
V_12 = F_12 ( & V_17 -> V_21 ) ;
F_10 ( L_2 , V_12 ) ;
F_13 ( ( T_5 ) V_12 , V_22 ) ;
break;
case 16 :
V_12 = F_14 ( & V_17 -> V_21 ) ;
F_10 ( L_2 , V_12 ) ;
F_15 ( ( V_23 ) V_12 , V_22 ) ;
break;
case 32 :
V_12 = F_16 ( & V_17 -> V_21 ) ;
F_10 ( L_2 , V_12 ) ;
F_17 ( V_12 , V_22 ) ;
break;
}
while ( F_12 ( & V_17 -> V_19 ) ) {
F_18 ( 10 ) ;
if ( V_11 ++ > 500 ) {
F_19 ( L_3
L_4 ) ;
V_10 = - V_24 ;
break;
}
}
if ( F_12 ( & V_17 -> V_25 ) ) {
F_10 ( L_5 ) ;
V_10 = - V_24 ;
}
}
F_20 ( & V_16 ) ;
return V_10 ;
}
static T_6 F_21 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
return sprintf ( V_30 , L_6 , ( int ) F_12 ( & V_17 -> V_31 ) ) ;
}
static T_6 F_22 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
return sprintf ( V_30 , L_6 , F_12 ( & V_17 -> V_18 ) ) ;
}
static T_6 F_23 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_30 ,
T_7 V_11 )
{
T_6 V_10 ;
if ( V_11 < 1 || V_11 > 2 )
return - V_32 ;
switch ( V_30 [ 0 ] ) {
case '0' :
V_10 = F_9 ( 0 ) ;
break;
case '1' :
V_10 = F_9 ( 1 ) ;
break;
default:
V_10 = - V_32 ;
}
if ( V_10 >= 0 )
V_10 = V_11 ;
return V_10 ;
}
static int F_24 ( void ) {
int V_10 , V_33 ;
V_10 = F_25 ( & V_34 ) ;
if ( ! V_10 ) {
for ( V_33 = 0 ; V_35 [ V_33 ] ; V_33 ++ )
F_26 ( & V_34 , V_35 [ V_33 ] ) ;
}
return V_10 ;
}
static void F_27 ( void ) {
int V_33 ;
for ( V_33 = 0 ; V_35 [ V_33 ] ; V_33 ++ )
F_28 ( & V_34 , V_35 [ V_33 ] ) ;
F_29 ( & V_34 ) ;
}
static int T_8 F_30 ( void ) {
unsigned long V_36 , V_37 ;
unsigned int V_38 ;
int V_10 = - V_39 , V_33 ;
if ( V_40 )
F_31 ( L_7 ) ;
else if ( V_41 || ! F_32 ( V_42 ) )
return - V_39 ;
V_36 = F_33 () ;
if ( ! V_36 ) {
F_10 ( L_8 ) ;
return - V_39 ;
}
V_43 = F_4 ( V_36 , 4 ) ;
if ( ! V_43 )
return - V_44 ;
V_38 = F_14 ( V_43 ) ;
F_10 ( L_9 , V_38 ) ;
if ( V_38 == 0 )
goto V_45;
F_7 ( V_43 ) ;
V_37 = V_38 * 1024 ;
V_43 = F_4 ( V_36 , V_37 ) ;
if ( ! V_43 )
return - V_44 ;
for ( V_33 = 0 ; V_33 < V_37 /sizeof( unsigned int ) ; V_33 ++ ) {
struct V_46 T_2 * V_47 ;
V_47 = (struct V_46 T_2 * ) ( V_43 + V_33 ) ;
if ( ( F_1 ( & V_47 -> V_48 ) & V_49 ) == V_50 ) {
T_4 V_1 ;
unsigned int V_51 ;
F_10 ( L_10 , V_47 ) ;
V_17 = V_47 ;
V_20 = F_12 ( & V_17 -> V_52 ) ;
V_7 = F_12 ( & V_17 -> V_53 ) ;
F_10 ( L_11 ,
V_20 , V_7 ) ;
V_1 = F_16 ( & V_17 -> V_54 ) ;
F_10 ( L_12 , ( unsigned long long ) V_1 ) ;
V_51 = V_20 / sizeof( char ) ;
V_22 = F_3 ( V_1 , V_51 ) ;
F_10 ( L_13 , V_22 ) ;
if ( ! V_22 ) {
V_10 = - V_44 ;
break;
}
V_10 = F_24 () ;
break;
}
}
V_45:
if ( V_10 ) {
F_7 ( V_43 ) ;
F_6 ( V_22 ) ;
}
return V_10 ;
}
static void T_9 F_34 ( void )
{
if ( V_17 ) {
F_10 ( L_14 ) ;
F_9 ( 0 ) ;
F_27 () ;
F_7 ( V_43 ) ;
F_6 ( V_22 ) ;
}
}
