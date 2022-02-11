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
V_16 = F_12 ( V_12 -> V_17 . V_18 -> V_19 ) ;
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
return - V_20 ;
}
if ( V_14 <= 0 )
return - V_21 ;
if ( F_13 ( V_9 , V_13 ) )
return - V_21 ;
return 1 ;
}
static T_2 F_14 ( struct V_12 * V_12 , const char T_3 * V_22 ,
T_4 V_14 , T_5 * V_15 )
{
unsigned int V_16 ;
T_6 type ;
T_4 V_23 ;
int V_24 = 0 ;
char V_25 ;
V_16 = F_12 ( V_12 -> V_17 . V_18 -> V_19 ) ;
switch ( V_16 ) {
case 0 :
type = V_26 ;
break;
case 32 ... 39 :
type = V_27 ;
break;
default:
return - V_20 ;
}
for ( V_23 = 0 ; V_23 < V_14 ; V_23 ++ ) {
if ( F_15 ( V_25 , V_22 + V_23 ) )
return - V_21 ;
switch ( type ) {
case V_26 :
V_24 = F_6 ( V_25 ) ;
break;
case V_27 :
V_24 = F_8 ( V_16 - 32 , V_25 ) ;
break;
}
if ( V_24 < 0 )
break;
}
return V_23 ;
}
static int F_16 ( struct V_28 * V_28 , struct V_12 * V_12 )
{
unsigned int V_16 ;
V_16 = F_12 ( V_28 ) ;
switch ( V_16 ) {
case 0 :
case 16 ... 23 :
case 32 ... 39 :
case 48 ... 55 :
return F_17 ( V_28 , V_12 ) ;
default:
break;
}
return - V_20 ;
}
static int F_18 ( struct V_28 * V_28 , struct V_12 * V_12 )
{
return 0 ;
}
static void F_19 ( char * V_7 )
{
F_7 ( V_29 , 0 ) ;
}
static void F_20 ( void )
{
F_21 ( V_30 , V_31 , V_32 ) ;
F_22 ( V_30 , V_33 ) ;
F_21 ( V_34 , V_31 , V_32 ) ;
F_22 ( V_34 , V_33 ) ;
F_21 ( V_35 , V_31 , V_32 ) ;
F_22 ( V_35 , V_33 ) ;
}
static int T_7 F_23 ( struct V_36 * V_37 )
{
int V_24 ;
if ( F_24 ( V_38 , V_39 , L_1 ) == NULL )
return - V_40 ;
V_41 = F_25 ( V_38 , V_39 ) ;
if ( V_41 == NULL ) {
F_26 ( V_38 , V_39 ) ;
return - V_42 ;
}
V_24 = F_27 ( V_43 , L_1 , & V_44 ) ;
if ( V_24 < 0 ) {
F_28 ( V_41 ) ;
V_41 = NULL ;
F_26 ( V_38 , V_39 ) ;
return V_24 ;
}
V_45 = V_46 ;
V_46 = F_19 ;
F_20 () ;
if ( V_43 == 0 ) {
V_43 = V_24 ;
F_29 ( V_47 L_2 , V_43 ) ;
}
return 0 ;
}
static int T_8 F_30 ( struct V_36 * V_37 )
{
V_46 = V_45 ;
F_28 ( V_41 ) ;
V_41 = NULL ;
F_26 ( V_38 , V_39 ) ;
return 0 ;
}
static int T_9 F_31 ( void )
{
int V_24 ;
V_48 = F_32 ( L_1 , - 1 ) ;
if ( ! V_48 )
return - V_42 ;
V_24 = F_33 ( V_48 ) ;
if ( V_24 < 0 ) {
F_34 ( V_48 ) ;
return V_24 ;
}
V_24 = F_35 ( & V_49 ) ;
if ( V_24 < 0 )
F_36 ( V_48 ) ;
return V_24 ;
}
static void T_10 F_37 ( void )
{
F_38 ( & V_49 ) ;
F_36 ( V_48 ) ;
}
