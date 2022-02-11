static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
V_3 = F_2 ( V_1 -> V_5 , V_2 ) ;
return V_3 ;
}
int F_3 ( struct V_1 * V_1 , int V_2 , char * V_6 ,
T_1 V_7 , void * V_8 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return V_2 ;
return F_4 ( V_2 , NULL , V_7 , V_9 ,
V_6 , V_8 ) ;
}
void F_5 ( struct V_1 * V_1 , int V_2 , void * V_8 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return;
F_6 ( V_2 , V_8 ) ;
}
int F_7 ( struct V_1 * V_1 , int V_2 , int V_10 )
{
V_2 = F_1 ( V_1 , V_2 ) ;
if ( V_2 < 0 )
return V_2 ;
return F_8 ( V_2 , V_10 ) ;
}
static T_2 F_9 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
F_10 ( V_1 -> V_11 , L_1 ) ;
return V_12 ;
}
static T_2 F_11 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
F_12 ( V_1 -> V_11 , L_2 ) ;
return V_12 ;
}
static T_2 F_13 ( int V_2 , void * V_8 )
{
struct V_1 * V_1 = V_8 ;
unsigned int V_13 ;
int V_3 ;
V_3 = F_14 ( V_1 -> V_11 ) ;
if ( V_3 < 0 ) {
F_12 ( V_1 -> V_11 , L_3 , V_3 ) ;
return V_14 ;
}
F_15 ( F_16 ( V_1 -> V_15 , 0 ) ) ;
V_3 = F_17 ( V_1 -> V_16 , V_17 , & V_13 ) ;
if ( V_3 == 0 && V_13 & V_18 ) {
F_15 ( F_16 ( V_1 -> V_15 , 1 ) ) ;
} else if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_4 ,
V_3 ) ;
}
F_18 ( V_1 -> V_11 ) ;
F_19 ( V_1 -> V_11 ) ;
return V_12 ;
}
static void F_20 ( struct V_19 * V_8 )
{
}
static void F_21 ( struct V_19 * V_8 )
{
}
static int F_22 ( struct V_20 * V_21 , unsigned int V_15 ,
T_3 V_22 )
{
struct V_23 * V_8 = V_21 -> V_24 ;
F_23 ( V_15 , V_8 ) ;
F_24 ( V_15 , & V_25 , V_26 ) ;
F_25 ( V_15 , 1 ) ;
#ifdef F_26
F_27 ( V_15 , V_27 ) ;
#else
F_28 ( V_15 ) ;
#endif
return 0 ;
}
int F_29 ( struct V_1 * V_1 )
{
int V_28 = V_9 ;
int V_3 , V_29 ;
const struct V_30 * V_31 , * V_2 ;
bool V_32 = true ;
switch ( V_1 -> type ) {
#ifdef F_30
case V_33 :
V_31 = & V_34 ;
V_2 = & V_35 ;
switch ( V_1 -> V_36 ) {
case 0 :
case 1 :
V_32 = false ;
break;
default:
break;
}
break;
#endif
#ifdef F_31
case V_37 :
V_31 = & V_38 ;
V_2 = & V_39 ;
switch ( V_1 -> V_36 ) {
case 0 :
case 1 :
V_32 = false ;
break;
default:
break;
}
break;
#endif
default:
F_32 ( L_5 == NULL ) ;
return - V_40 ;
}
if ( V_1 -> V_41 . V_42 ) {
V_3 = F_33 ( V_1 -> V_16 , V_43 ,
V_44 , 0 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_6 ,
V_3 ) ;
goto V_45;
}
V_28 |= V_46 ;
} else {
V_28 |= V_47 ;
}
V_1 -> V_15 = F_34 ( NULL , 2 , & V_48 ,
V_1 ) ;
if ( ! V_1 -> V_15 ) {
V_3 = - V_40 ;
goto V_45;
}
V_3 = F_35 ( V_1 -> V_16 ,
F_36 ( V_1 -> V_15 , 0 ) ,
V_9 , - 1 , V_31 ,
& V_1 -> V_4 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_7 , V_3 ) ;
goto V_49;
}
V_3 = F_35 ( V_1 -> V_16 ,
F_36 ( V_1 -> V_15 , 1 ) ,
V_9 , - 1 , V_2 ,
& V_1 -> V_5 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_7 , V_3 ) ;
goto V_50;
}
V_29 = F_1 ( V_1 , V_51 ) ;
V_3 = F_4 ( V_29 , NULL , F_9 , V_9 ,
L_8 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_9 ,
V_1 -> V_2 , V_3 ) ;
goto V_52;
}
if ( V_32 ) {
V_29 = F_1 ( V_1 , V_53 ) ;
V_3 = F_4 ( V_29 , NULL , F_11 ,
V_9 ,
L_10 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 ,
L_11 ,
V_1 -> V_2 , V_3 ) ;
goto V_54;
}
}
V_3 = F_4 ( V_1 -> V_2 , NULL , F_13 ,
V_28 , L_12 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_13 ,
V_1 -> V_2 , V_3 ) ;
goto V_55;
}
return 0 ;
V_55:
F_6 ( F_1 ( V_1 , V_53 ) , V_1 ) ;
V_54:
F_6 ( F_1 ( V_1 , V_51 ) , V_1 ) ;
V_52:
F_37 ( F_36 ( V_1 -> V_15 , 1 ) ,
V_1 -> V_5 ) ;
V_50:
F_37 ( F_36 ( V_1 -> V_15 , 0 ) ,
V_1 -> V_4 ) ;
V_49:
V_45:
return V_3 ;
}
int F_38 ( struct V_1 * V_1 )
{
F_6 ( F_1 ( V_1 , V_53 ) , V_1 ) ;
F_6 ( F_1 ( V_1 , V_51 ) , V_1 ) ;
F_37 ( F_36 ( V_1 -> V_15 , 1 ) ,
V_1 -> V_5 ) ;
F_37 ( F_36 ( V_1 -> V_15 , 0 ) ,
V_1 -> V_4 ) ;
F_6 ( V_1 -> V_2 , V_1 ) ;
return 0 ;
}
