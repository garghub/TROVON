static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
if ( ! V_3 )
return;
F_2 ( V_3 , V_4 , 0 ) ;
}
static T_1 F_3 ( int V_5 , void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_6 * V_7 ;
T_2 V_8 ;
if ( ! V_3 )
return V_9 ;
V_7 = V_3 -> V_10 -> V_7 ;
if ( ! V_7 ) {
F_4 ( V_11 , L_1 ,
V_12 ) ;
return V_9 ;
}
F_5 ( V_7 -> V_13 , & V_8 ) ;
if ( V_8 == V_14 ) {
F_6 ( V_7 -> V_13 , & V_15 ) ;
F_4 ( V_11 , L_2 , V_12 ,
V_8 , V_15 ) ;
F_7 ( & V_3 -> V_16 ) ;
F_8 ( V_7 -> V_13 ,
V_14 ) ;
} else {
F_8 ( V_7 -> V_13 ,
V_17 ) ;
}
return V_9 ;
}
int F_9 ( struct V_2 * * V_18 ,
struct V_19 * V_20 )
{
int V_21 ;
struct V_2 * V_3 ;
struct V_22 * V_23 = NULL ;
F_10 ( V_20 , & V_23 ) ;
V_3 = F_11 ( sizeof( * V_3 ) , V_24 ) ;
if ( ! V_3 ) {
V_21 = - V_25 ;
goto V_26;
}
V_3 -> V_27 = F_12 ( sizeof( struct V_28 ) , V_24 ) ;
if ( ! V_3 -> V_27 ) {
V_21 = - V_25 ;
goto V_26;
}
F_13 ( V_3 -> V_27 ) ;
F_14 ( & V_3 -> V_16 , F_1 , ( T_2 ) V_3 ) ;
V_3 -> V_10 = V_23 ;
V_21 = F_15 ( V_29 , F_3 , 0 ,
L_3 , V_3 ) ;
if ( V_21 < 0 )
goto V_26;
* V_18 = V_3 ;
return 0 ;
V_26:
F_16 ( V_3 ) ;
* V_18 = NULL ;
return V_21 ;
}
int F_16 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_30 ;
if ( V_3 -> V_27 ) {
F_17 ( V_3 -> V_27 ) ;
F_18 ( V_3 -> V_27 ) ;
}
F_19 ( V_29 , V_3 ) ;
F_20 ( & V_3 -> V_16 ) ;
F_18 ( V_3 ) ;
return 0 ;
}
int F_21 ( struct V_2 * V_3 , T_2 V_31 ,
T_2 V_32 ,
struct V_33 * V_34 )
{
if ( ! V_3 )
return - V_30 ;
if ( V_31 )
return F_22 ( V_3 -> V_27 , V_34 ,
V_31 , V_32 ) ;
else
return F_23 ( V_3 -> V_27 , V_34 ) ;
}
static void F_24 ( struct V_22 * V_35 )
{
struct V_6 * V_7 ;
struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
} ;
void * V_44 ;
V_7 = V_35 -> V_7 ;
V_44 = ( void * ) F_25 ( V_45 ) ;
F_26 ( V_7 -> V_13 ) ;
F_27 ( V_7 -> V_13 ) ;
F_28 ( V_7 -> V_13 ,
F_29 ( V_44 ) , V_15 ,
V_46 , 1 ,
& V_37 , V_47 , V_47 ) ;
F_30 ( V_48 ) ;
F_31 ( V_48 , 0xfffffffe ) ;
F_32 ( V_7 -> V_13 ,
V_14 ) ;
F_33 ( V_35 ) ;
F_34 ( V_48 ) ;
F_35 ( V_7 -> V_13 ) ;
F_36 ( ( unsigned long ) V_44 ) ;
}
static inline const char * F_37 ( int V_8 )
{
switch ( V_8 ) {
case V_49 : return L_4 ; break;
case V_4 : return L_5 ; break;
case V_50 : return L_6 ; break;
case V_51 : return L_7 ; break;
default: return L_8 ; break;
}
}
void F_2 ( struct V_2 * V_3 , int V_8 , int V_52 )
{
struct V_22 * V_35 ;
const char * V_53 = F_37 ( V_8 ) ;
if ( ! V_3 )
return;
F_4 ( V_11 , L_9 , V_12 ) ;
V_35 = V_3 -> V_10 ;
switch ( V_8 ) {
case V_49 :
F_38 ( V_11 , L_10 , V_12 ,
V_53 , V_52 ) ;
#ifdef F_39
F_40 ( V_35 ) ;
F_33 ( V_35 ) ;
#endif
break;
case V_4 :
F_38 ( V_11 , L_11 , V_12 ,
V_53 , V_15 ) ;
#ifdef F_39
F_41 ( V_35 ) ;
F_40 ( V_35 ) ;
F_24 ( V_35 ) ;
#endif
break;
default:
F_38 ( V_11 , L_12 , V_12 , V_53 ) ;
break;
}
if ( V_35 -> V_54 != V_55 ) {
F_42 ( V_3 -> V_27 , V_8 ) ;
#ifdef F_43
F_44 () ;
#endif
}
V_35 -> V_54 = V_55 ;
F_45 ( V_35 -> V_56 ) ;
F_46 ( false ) ;
}
