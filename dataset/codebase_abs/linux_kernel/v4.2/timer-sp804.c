static long T_1 F_1 ( struct V_1 * V_1 )
{
long V_2 ;
int V_3 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
F_4 ( V_1 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 ) ;
if ( V_3 ) {
F_3 ( L_2 , V_3 ) ;
F_6 ( V_1 ) ;
F_4 ( V_1 ) ;
return V_3 ;
}
V_2 = F_7 ( V_1 ) ;
if ( V_2 < 0 ) {
F_3 ( L_3 , V_2 ) ;
F_8 ( V_1 ) ;
F_6 ( V_1 ) ;
F_4 ( V_1 ) ;
}
return V_2 ;
}
static T_2 T_3 F_9 ( void )
{
return ~ F_10 ( V_4 + V_5 ) ;
}
void T_1 F_11 ( void T_4 * V_6 )
{
F_12 ( 0 , V_6 + V_7 ) ;
}
void T_1 F_13 ( void T_4 * V_6 ,
const char * V_8 ,
struct V_1 * V_1 ,
int V_9 )
{
long V_2 ;
if ( ! V_1 ) {
V_1 = F_14 ( L_4 , V_8 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_5 ,
( int ) F_16 ( V_1 ) ) ;
return;
}
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0xffffffff , V_6 + V_10 ) ;
F_12 ( 0xffffffff , V_6 + V_5 ) ;
F_12 ( V_11 | V_12 | V_13 ,
V_6 + V_7 ) ;
F_17 ( V_6 + V_5 , V_8 ,
V_2 , 200 , 32 , V_14 ) ;
if ( V_9 ) {
V_4 = V_6 ;
F_18 ( F_9 , 32 , V_2 ) ;
}
}
static T_5 F_19 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
F_12 ( 1 , V_19 + V_20 ) ;
V_18 -> V_21 ( V_18 ) ;
return V_22 ;
}
static void F_20 ( enum V_23 V_24 ,
struct V_17 * V_18 )
{
unsigned long V_25 = V_11 | V_26 ;
F_12 ( V_25 , V_19 + V_7 ) ;
switch ( V_24 ) {
case V_27 :
F_12 ( V_28 , V_19 + V_10 ) ;
V_25 |= V_13 | V_12 ;
break;
case V_29 :
V_25 |= V_30 ;
break;
case V_31 :
case V_32 :
default:
break;
}
F_12 ( V_25 , V_19 + V_7 ) ;
}
static int F_21 ( unsigned long V_33 ,
struct V_17 * V_18 )
{
unsigned long V_25 = F_22 ( V_19 + V_7 ) ;
F_12 ( V_33 , V_19 + V_10 ) ;
F_12 ( V_25 | V_12 , V_19 + V_7 ) ;
return 0 ;
}
void T_1 F_23 ( void T_4 * V_6 , unsigned int V_15 , struct V_1 * V_1 , const char * V_8 )
{
struct V_17 * V_18 = & V_34 ;
long V_2 ;
if ( ! V_1 )
V_1 = F_14 ( L_4 , V_8 ) ;
if ( F_15 ( V_1 ) ) {
F_3 ( L_6 , V_8 ,
( int ) F_16 ( V_1 ) ) ;
return;
}
V_2 = F_1 ( V_1 ) ;
if ( V_2 < 0 )
return;
V_19 = V_6 ;
V_28 = F_24 ( V_2 , V_35 ) ;
V_18 -> V_8 = V_8 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_36 = V_37 ;
F_12 ( 0 , V_6 + V_7 ) ;
F_25 ( V_15 , & V_38 ) ;
F_26 ( V_18 , V_2 , 0xf , 0xffffffff ) ;
}
static void T_1 F_27 ( struct V_39 * V_40 )
{
static bool V_41 = false ;
void T_4 * V_6 ;
int V_15 ;
T_6 V_42 = 0 ;
struct V_1 * V_43 , * V_44 ;
const char * V_8 = F_28 ( V_40 , L_7 , NULL ) ;
V_6 = F_29 ( V_40 , 0 ) ;
if ( F_30 ( ! V_6 ) )
return;
F_12 ( 0 , V_6 + V_7 ) ;
F_12 ( 0 , V_6 + V_45 + V_7 ) ;
if ( V_41 || ! F_31 ( V_40 ) )
goto V_3;
V_43 = F_32 ( V_40 , 0 ) ;
if ( F_15 ( V_43 ) )
V_43 = NULL ;
if ( F_33 ( V_40 , L_8 , L_9 ) == 3 ) {
V_44 = F_32 ( V_40 , 1 ) ;
if ( F_15 ( V_44 ) ) {
F_3 ( L_6 , V_40 -> V_8 ,
( int ) F_16 ( V_44 ) ) ;
V_44 = NULL ;
}
} else
V_44 = V_43 ;
V_15 = F_34 ( V_40 , 0 ) ;
if ( V_15 <= 0 )
goto V_3;
F_35 ( V_40 , L_10 , & V_42 ) ;
if ( V_42 == 2 ) {
F_23 ( V_6 + V_45 , V_15 , V_44 , V_8 ) ;
F_13 ( V_6 , V_8 , V_43 , 1 ) ;
} else {
F_23 ( V_6 , V_15 , V_43 , V_8 ) ;
F_13 ( V_6 + V_45 ,
V_8 , V_44 , 1 ) ;
}
V_41 = true ;
return;
V_3:
F_36 ( V_6 ) ;
}
static void T_1 F_37 ( struct V_39 * V_40 )
{
static int V_46 = 0 ;
void T_4 * V_6 ;
int V_15 ;
const char * V_8 = F_28 ( V_40 , L_7 , NULL ) ;
struct V_1 * V_1 ;
V_6 = F_29 ( V_40 , 0 ) ;
if ( F_30 ( ! V_6 ) )
return;
V_1 = F_32 ( V_40 , 0 ) ;
if ( F_30 ( F_15 ( V_1 ) ) )
return;
F_12 ( 0 , V_6 + V_7 ) ;
if ( V_46 == 2 || ! F_31 ( V_40 ) )
goto V_3;
if ( ! V_46 )
F_13 ( V_6 , V_8 , V_1 , 0 ) ;
else {
V_15 = F_34 ( V_40 , 0 ) ;
if ( V_15 <= 0 )
goto V_3;
F_23 ( V_6 , V_15 , V_1 , V_8 ) ;
}
V_46 ++ ;
return;
V_3:
F_36 ( V_6 ) ;
}
