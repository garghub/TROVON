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
int V_13 , V_3 ;
V_3 = F_14 ( V_1 -> V_11 ) ;
if ( V_3 < 0 ) {
F_12 ( V_1 -> V_11 , L_3 , V_3 ) ;
return V_14 ;
}
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ )
F_15 ( F_16 ( V_1 -> V_15 , V_13 ) ) ;
F_17 ( V_1 -> V_11 ) ;
F_18 ( V_1 -> V_11 ) ;
return V_12 ;
}
static void F_19 ( struct V_16 * V_8 )
{
}
static void F_20 ( struct V_16 * V_8 )
{
}
static int F_21 ( struct V_17 * V_18 , unsigned int V_15 ,
T_3 V_19 )
{
struct V_20 * V_8 = V_18 -> V_21 ;
F_22 ( V_15 , V_8 ) ;
F_23 ( V_15 , & V_22 , V_23 ) ;
F_24 ( V_15 , 1 ) ;
#ifdef F_25
F_26 ( V_15 , V_24 ) ;
#else
F_27 ( V_15 ) ;
#endif
return 0 ;
}
int F_28 ( struct V_1 * V_1 )
{
int V_25 = V_9 ;
int V_3 , V_13 ;
const struct V_26 * V_27 , * V_2 ;
switch ( V_1 -> type ) {
#ifdef F_29
case V_28 :
V_27 = & V_29 ;
V_2 = & V_30 ;
break;
#endif
#ifdef F_30
case V_31 :
V_27 = & V_32 ;
V_2 = & V_33 ;
break;
#endif
default:
F_31 ( L_4 == NULL ) ;
return - V_34 ;
}
if ( V_1 -> V_35 . V_36 ) {
V_3 = F_32 ( V_1 -> V_37 , V_38 ,
V_39 , 0 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_5 ,
V_3 ) ;
goto V_40;
}
V_25 |= V_41 ;
} else {
V_25 |= V_42 ;
}
V_1 -> V_15 = F_33 ( NULL , 2 , & V_43 ,
V_1 ) ;
if ( ! V_1 -> V_15 ) {
V_3 = - V_34 ;
goto V_40;
}
V_3 = F_34 ( V_1 -> V_37 ,
F_35 ( V_1 -> V_15 , 0 ) ,
V_9 , - 1 , V_27 ,
& V_1 -> V_4 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_6 , V_3 ) ;
goto V_44;
}
V_3 = F_34 ( V_1 -> V_37 ,
F_35 ( V_1 -> V_15 , 1 ) ,
V_9 , - 1 , V_2 ,
& V_1 -> V_5 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_6 , V_3 ) ;
goto V_45;
}
V_13 = F_1 ( V_1 , V_46 ) ;
V_3 = F_4 ( V_13 , NULL , F_9 , V_9 ,
L_7 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_8 ,
V_1 -> V_2 , V_3 ) ;
goto V_47;
}
V_13 = F_1 ( V_1 , V_48 ) ;
V_3 = F_4 ( V_13 , NULL , F_11 , V_9 ,
L_9 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_8 ,
V_1 -> V_2 , V_3 ) ;
goto V_49;
}
V_3 = F_4 ( V_1 -> V_2 , NULL , F_13 ,
V_25 , L_10 , V_1 ) ;
if ( V_3 != 0 ) {
F_12 ( V_1 -> V_11 , L_11 ,
V_1 -> V_2 , V_3 ) ;
goto V_50;
}
return 0 ;
V_50:
F_6 ( F_1 ( V_1 , V_48 ) , V_1 ) ;
V_49:
F_6 ( F_1 ( V_1 , V_46 ) , V_1 ) ;
V_47:
F_36 ( F_35 ( V_1 -> V_15 , 1 ) ,
V_1 -> V_5 ) ;
V_45:
F_36 ( F_35 ( V_1 -> V_15 , 0 ) ,
V_1 -> V_4 ) ;
V_44:
V_40:
return V_3 ;
}
int F_37 ( struct V_1 * V_1 )
{
F_6 ( F_1 ( V_1 , V_48 ) , V_1 ) ;
F_6 ( F_1 ( V_1 , V_46 ) , V_1 ) ;
F_36 ( F_35 ( V_1 -> V_15 , 1 ) ,
V_1 -> V_5 ) ;
F_36 ( F_35 ( V_1 -> V_15 , 0 ) ,
V_1 -> V_4 ) ;
F_6 ( V_1 -> V_2 , V_1 ) ;
return 0 ;
}
