static T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static void F_3 ( T_1 V_3 , unsigned long V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( int V_4 , bool V_5 )
{
bool V_6 ;
unsigned long V_7 ;
F_6 ( & V_8 , V_7 ) ;
V_6 = F_1 ( V_9 ) & ( 1 << V_4 ) ;
if ( V_6 == V_5 ) {
F_7 ( & V_8 , V_7 ) ;
return 0 ;
}
F_3 ( V_10 | V_4 , V_11 ) ;
F_7 ( & V_8 , V_7 ) ;
return 0 ;
}
int F_8 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
return F_5 ( V_4 , true ) ;
}
int F_9 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
return F_5 ( V_4 , false ) ;
}
int F_10 ( int V_4 )
{
T_1 V_6 ;
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
V_6 = F_1 ( V_9 ) & ( 1 << V_4 ) ;
return ! ! V_6 ;
}
int F_11 ( int V_4 )
{
T_1 V_14 ;
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
if ( V_15 == V_16 ) {
if ( V_4 == V_17 ) {
F_3 ( 0 , V_18 ) ;
return 0 ;
}
}
if ( V_4 == V_19 )
V_14 = ( 1 << V_20 ) ;
else if ( V_4 == V_20 )
V_14 = ( 1 << V_19 ) ;
else
V_14 = ( 1 << V_4 ) ;
F_3 ( V_14 , V_21 ) ;
return 0 ;
}
int F_12 ( int V_4 , struct V_22 * V_22 ,
struct V_23 * V_24 )
{
int V_25 ;
F_13 ( V_24 ) ;
V_25 = F_8 ( V_4 ) ;
if ( V_25 )
goto V_26;
V_25 = F_14 ( V_22 ) ;
if ( V_25 )
goto V_27;
F_15 ( 10 ) ;
V_25 = F_11 ( V_4 ) ;
if ( V_25 )
goto V_28;
F_15 ( 10 ) ;
F_16 ( V_24 ) ;
return 0 ;
V_28:
F_17 ( V_22 ) ;
V_27:
F_9 ( V_4 ) ;
V_26:
return V_25 ;
}
int F_18 ( int V_29 )
{
if ( V_29 > 0 && V_29 < V_30 )
return V_31 [ V_29 ] ;
return - V_13 ;
}
int T_2 F_19 ( void )
{
switch ( V_15 ) {
case V_32 :
V_12 = 7 ;
break;
case V_33 :
V_12 = 14 ;
V_30 = 4 ;
V_31 = V_34 ;
break;
case V_35 :
V_12 = 23 ;
V_30 = 4 ;
V_31 = V_36 ;
break;
case V_16 :
V_12 = 25 ;
V_30 = 4 ;
V_31 = V_37 ;
break;
default:
V_12 = 0 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , void * V_40 )
{
int V_41 ;
F_21 ( V_39 , L_1 ) ;
F_21 ( V_39 , L_2 ) ;
for ( V_41 = 0 ; V_41 < V_12 ; V_41 ++ ) {
if ( ! V_42 [ V_41 ] )
continue;
F_21 ( V_39 , L_3 , V_42 [ V_41 ] ,
F_10 ( V_41 ) ? L_4 : L_5 ) ;
}
return 0 ;
}
static int F_22 ( struct V_43 * V_43 , struct V_44 * V_44 )
{
return F_23 ( V_44 , F_20 , V_43 -> V_45 ) ;
}
int T_2 F_24 ( void )
{
struct V_46 * V_47 ;
switch ( V_15 ) {
case V_32 :
V_42 = V_48 ;
break;
case V_33 :
V_42 = V_49 ;
break;
case V_35 :
V_42 = V_50 ;
break;
case V_16 :
V_42 = V_51 ;
break;
}
if ( V_42 ) {
V_47 = F_25 ( L_6 , V_52 , NULL , NULL ,
& V_53 ) ;
if ( ! V_47 )
return - V_54 ;
}
return 0 ;
}
static int F_26 ( int V_4 , unsigned long * V_55 ,
unsigned long * V_6 , unsigned int * V_56 )
{
unsigned long V_57 , V_58 ;
struct V_22 * V_22 ;
* V_56 = V_4 % 32 ;
if ( V_4 > 63 || * V_56 == 30 || * V_56 == 31 )
return - V_13 ;
if ( V_4 < 32 ) {
* V_6 = V_59 ;
* V_55 = V_60 ;
} else {
* V_6 = V_61 ;
* V_55 = V_62 ;
}
V_22 = F_27 ( NULL , L_7 ) ;
if ( F_28 ( V_22 ) )
return F_29 ( V_22 ) ;
V_57 = F_30 ( V_22 ) ;
F_31 ( V_22 ) ;
F_3 ( V_63 , V_64 ) ;
V_58 = F_32 ( 1000000000 , V_57 ) ;
V_58 = F_32 ( 200 , V_58 ) ;
F_3 ( V_58 , V_65 ) ;
return 0 ;
}
static int F_33 ( unsigned long V_66 , unsigned long V_14 ,
unsigned long V_3 , unsigned long V_67 )
{
unsigned long V_58 ;
V_67 = V_68 + F_34 ( V_67 ) ;
while ( F_35 ( V_67 , V_68 ) ) {
V_58 = F_1 ( V_66 ) ;
if ( ( V_58 & V_14 ) == V_3 )
return 0 ;
F_36 ( 250 , 1000 ) ;
}
return - V_69 ;
}
static void F_37 ( void )
{
F_3 ( V_70 , V_64 ) ;
}
int F_38 ( int V_4 )
{
unsigned long V_55 , V_6 , V_58 ;
unsigned int V_56 , V_14 ;
int V_71 ;
V_71 = F_26 ( V_4 , & V_55 , & V_6 , & V_56 ) ;
if ( V_71 < 0 )
return V_71 ;
V_14 = 1 << V_56 ;
V_58 = F_1 ( V_55 ) ;
V_58 |= V_14 ;
V_58 &= ~ V_72 ;
V_58 |= V_73 ;
F_3 ( V_58 , V_55 ) ;
V_71 = F_33 ( V_6 , V_14 , 0 , 250 ) ;
if ( V_71 < 0 )
return V_71 ;
F_37 () ;
return 0 ;
}
int F_39 ( int V_4 )
{
unsigned long V_55 , V_6 , V_58 ;
unsigned int V_56 , V_14 ;
int V_71 ;
V_71 = F_26 ( V_4 , & V_55 , & V_6 , & V_56 ) ;
if ( V_71 < 0 )
return V_71 ;
V_14 = 1 << V_56 ;
V_58 = F_1 ( V_55 ) ;
V_58 |= V_14 ;
V_58 &= ~ V_72 ;
V_58 |= V_74 ;
F_3 ( V_58 , V_55 ) ;
V_71 = F_33 ( V_6 , V_14 , V_14 , 250 ) ;
if ( V_71 < 0 )
return V_71 ;
F_37 () ;
return 0 ;
}
