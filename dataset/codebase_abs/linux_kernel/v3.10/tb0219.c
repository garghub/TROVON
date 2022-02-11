static inline char F_1 ( void )
{
return ( char ) F_2 ( V_1 ) ;
}
static inline char F_3 ( unsigned int V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 & ( 1 << V_2 ) )
return '1' ;
return '0' ;
}
static inline char F_4 ( unsigned int V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_5 ) ;
if ( V_3 & ( 1 << V_2 ) )
return '1' ;
return '0' ;
}
static inline char F_5 ( unsigned int V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_6 ) ;
if ( V_3 & ( 1 << V_2 ) )
return '1' ;
return '0' ;
}
static inline int F_6 ( char V_7 )
{
F_7 ( V_1 , V_7 ) ;
return 0 ;
}
static inline int F_8 ( unsigned int V_2 , char V_7 )
{
unsigned long V_8 ;
T_1 V_9 ;
if ( V_7 != '0' && V_7 != '1' )
return - V_10 ;
F_9 ( & V_11 , V_8 ) ;
V_9 = F_2 ( V_5 ) ;
if ( V_7 == '0' )
V_9 &= ~ ( 1 << V_2 ) ;
else
V_9 |= 1 << V_2 ;
F_7 ( V_5 , V_9 ) ;
F_10 ( & V_11 , V_8 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_12 * V_12 , char T_3 * V_13 , T_4 V_14 ,
T_5 * V_15 )
{
unsigned int V_16 ;
char V_9 ;
V_16 = F_12 ( F_13 ( V_12 ) ) ;
switch ( V_16 ) {
case 0 :
V_9 = F_1 () ;
break;
case 16 ... 23 :
V_9 = F_3 ( V_16 - 16 ) ;
break;
case 32 ... 39 :
V_9 = F_4 ( V_16 - 32 ) ;
break;
case 48 ... 55 :
V_9 = F_5 ( V_16 - 48 ) ;
break;
default:
return - V_17 ;
}
if ( V_14 <= 0 )
return - V_18 ;
if ( F_14 ( V_9 , V_13 ) )
return - V_18 ;
return 1 ;
}
static T_2 F_15 ( struct V_12 * V_12 , const char T_3 * V_19 ,
T_4 V_14 , T_5 * V_15 )
{
unsigned int V_16 ;
T_6 type ;
T_4 V_20 ;
int V_21 = 0 ;
char V_22 ;
V_16 = F_12 ( F_13 ( V_12 ) ) ;
switch ( V_16 ) {
case 0 :
type = V_23 ;
break;
case 32 ... 39 :
type = V_24 ;
break;
default:
return - V_17 ;
}
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ ) {
if ( F_16 ( V_22 , V_19 + V_20 ) )
return - V_18 ;
switch ( type ) {
case V_23 :
V_21 = F_6 ( V_22 ) ;
break;
case V_24 :
V_21 = F_8 ( V_16 - 32 , V_22 ) ;
break;
}
if ( V_21 < 0 )
break;
}
return V_20 ;
}
static int F_17 ( struct V_25 * V_25 , struct V_12 * V_12 )
{
unsigned int V_16 ;
V_16 = F_12 ( V_25 ) ;
switch ( V_16 ) {
case 0 :
case 16 ... 23 :
case 32 ... 39 :
case 48 ... 55 :
return F_18 ( V_25 , V_12 ) ;
default:
break;
}
return - V_17 ;
}
static int F_19 ( struct V_25 * V_25 , struct V_12 * V_12 )
{
return 0 ;
}
static void F_20 ( char * V_7 )
{
F_7 ( V_26 , 0 ) ;
}
static void F_21 ( void )
{
F_22 ( V_27 , V_28 , V_29 ) ;
F_23 ( V_27 , V_30 ) ;
F_22 ( V_31 , V_28 , V_29 ) ;
F_23 ( V_31 , V_30 ) ;
F_22 ( V_32 , V_28 , V_29 ) ;
F_23 ( V_32 , V_30 ) ;
}
static int F_24 ( struct V_33 * V_34 )
{
int V_21 ;
if ( F_25 ( V_35 , V_36 , L_1 ) == NULL )
return - V_37 ;
V_38 = F_26 ( V_35 , V_36 ) ;
if ( V_38 == NULL ) {
F_27 ( V_35 , V_36 ) ;
return - V_39 ;
}
V_21 = F_28 ( V_40 , L_1 , & V_41 ) ;
if ( V_21 < 0 ) {
F_29 ( V_38 ) ;
V_38 = NULL ;
F_27 ( V_35 , V_36 ) ;
return V_21 ;
}
V_42 = V_43 ;
V_43 = F_20 ;
F_21 () ;
if ( V_40 == 0 ) {
V_40 = V_21 ;
F_30 ( V_44 L_2 , V_40 ) ;
}
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
V_43 = V_42 ;
F_29 ( V_38 ) ;
V_38 = NULL ;
F_27 ( V_35 , V_36 ) ;
return 0 ;
}
static int T_7 F_32 ( void )
{
int V_21 ;
V_45 = F_33 ( L_1 , - 1 ) ;
if ( ! V_45 )
return - V_39 ;
V_21 = F_34 ( V_45 ) ;
if ( V_21 < 0 ) {
F_35 ( V_45 ) ;
return V_21 ;
}
V_21 = F_36 ( & V_46 ) ;
if ( V_21 < 0 )
F_37 ( V_45 ) ;
return V_21 ;
}
static void T_8 F_38 ( void )
{
F_39 ( & V_46 ) ;
F_37 ( V_45 ) ;
}
