static void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 )
{
if ( V_3 == V_4 )
return F_2 ( V_1 , V_2 ) ;
return F_3 ( V_1 , V_2 ) ;
}
static void F_4 ( void T_1 * V_1 )
{
if ( V_1 && V_3 == V_4 )
F_5 ( V_1 ) ;
else
F_6 ( V_1 ) ;
}
static int F_7 ( T_3 V_5 )
{
int V_6 = 0 , V_7 = 0 ;
static T_4 V_8 ;
F_8 ( L_1 , V_9 , V_5 ) ;
V_5 = V_5 == 1 ? V_10 : V_11 ;
F_9 ( & V_12 ) ;
if ( F_10 ( & V_13 -> V_14 ) != V_5 ) {
F_11 ( V_5 , & V_13 -> V_15 ) ;
switch ( V_16 ) {
case 8 :
V_8 = F_10 ( & V_13 -> V_17 ) ;
F_8 ( L_2 , V_8 ) ;
F_11 ( ( T_3 ) V_8 , V_18 ) ;
break;
case 16 :
V_8 = F_12 ( & V_13 -> V_17 ) ;
F_8 ( L_2 , V_8 ) ;
F_13 ( ( V_19 ) V_8 , V_18 ) ;
break;
case 32 :
V_8 = F_14 ( & V_13 -> V_17 ) ;
F_8 ( L_2 , V_8 ) ;
F_15 ( V_8 , V_18 ) ;
break;
}
while ( F_10 ( & V_13 -> V_15 ) ) {
F_16 ( 10 ) ;
if ( V_7 ++ > 500 ) {
F_17 ( L_3
L_4 ) ;
V_6 = - V_20 ;
break;
}
}
if ( F_10 ( & V_13 -> V_21 ) ) {
F_8 ( L_5 ) ;
V_6 = - V_20 ;
}
}
F_18 ( & V_12 ) ;
return V_6 ;
}
static T_5 F_19 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
return sprintf ( V_26 , L_6 , ( int ) F_10 ( & V_13 -> V_27 ) ) ;
}
static T_5 F_20 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
return sprintf ( V_26 , L_6 , F_10 ( & V_13 -> V_14 ) ) ;
}
static T_5 F_21 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_6 V_7 )
{
T_5 V_6 ;
if ( V_7 < 1 || V_7 > 2 )
return - V_28 ;
switch ( V_26 [ 0 ] ) {
case '0' :
V_6 = F_7 ( 0 ) ;
break;
case '1' :
V_6 = F_7 ( 1 ) ;
break;
default:
V_6 = - V_28 ;
}
if ( V_6 >= 0 )
V_6 = V_7 ;
return V_6 ;
}
static int F_22 ( void ) {
int V_6 , V_29 ;
V_6 = F_23 ( & V_30 , NULL ) ;
if ( ! V_6 ) {
for ( V_29 = 0 ; V_31 [ V_29 ] ; V_29 ++ )
F_24 ( V_30 . V_32 , V_31 [ V_29 ] ) ;
}
return V_6 ;
}
static void F_25 ( void ) {
int V_29 ;
for ( V_29 = 0 ; V_31 [ V_29 ] ; V_29 ++ )
F_26 ( V_30 . V_32 , V_31 [ V_29 ] ) ;
F_27 ( & V_30 ) ;
}
static int T_7 F_28 ( void ) {
unsigned long V_33 , V_34 ;
unsigned int V_35 ;
int V_6 = - V_36 , V_29 ;
if ( V_37 )
F_29 ( L_7 ) ;
else if ( F_30 ( V_38 ) || ! F_31 ( V_39 ) )
return - V_36 ;
V_33 = F_32 () ;
if ( ! V_33 ) {
F_8 ( L_8 ) ;
return - V_36 ;
}
V_40 = F_2 ( V_33 , 4 ) ;
if ( ! V_40 )
return - V_41 ;
V_35 = F_12 ( V_40 ) ;
F_8 ( L_9 , V_35 ) ;
if ( V_35 == 0 )
goto V_42;
F_5 ( V_40 ) ;
V_34 = V_35 * 1024 ;
V_40 = F_2 ( V_33 , V_34 ) ;
if ( ! V_40 )
return - V_41 ;
for ( V_29 = 0 ; V_29 < V_34 /sizeof( unsigned int ) ; V_29 ++ ) {
struct V_43 T_1 * V_44 ;
V_44 = (struct V_43 T_1 * ) ( V_40 + V_29 ) ;
if ( ( F_33 ( & V_44 -> V_45 ) & V_46 ) == V_47 ) {
T_2 V_1 ;
unsigned int V_48 ;
F_8 ( L_10 , V_44 ) ;
V_13 = V_44 ;
V_16 = F_10 ( & V_13 -> V_49 ) ;
V_3 = F_10 ( & V_13 -> V_50 ) ;
F_8 ( L_11 ,
V_16 , V_3 ) ;
V_1 = F_14 ( & V_13 -> V_51 ) ;
F_8 ( L_12 , ( unsigned long long ) V_1 ) ;
V_48 = V_16 / sizeof( char ) ;
V_18 = F_1 ( V_1 , V_48 ) ;
F_8 ( L_13 , V_18 ) ;
if ( ! V_18 ) {
V_6 = - V_41 ;
break;
}
V_6 = F_22 () ;
break;
}
}
V_42:
if ( V_6 ) {
F_5 ( V_40 ) ;
F_4 ( V_18 ) ;
}
return V_6 ;
}
static void T_8 F_34 ( void )
{
if ( V_13 ) {
F_8 ( L_14 ) ;
F_7 ( 0 ) ;
F_25 () ;
F_5 ( V_40 ) ;
F_4 ( V_18 ) ;
}
}
