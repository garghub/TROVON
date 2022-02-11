static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 -> V_4 , V_3 -> V_5 ,
& V_3 -> V_4 , & V_3 -> V_6 , & V_3 -> V_5 , & V_3 -> V_7 ) ;
}
static T_1 F_3 ( struct V_8 * V_8 , T_1 V_9 , int V_10 )
{
T_1 V_11 ;
struct V_12 * V_12 = V_8 -> V_13 -> V_14 ;
F_4 ( & V_12 -> V_15 ) ;
switch ( V_10 ) {
case 0 :
V_8 -> V_16 = V_9 ;
V_11 = V_8 -> V_16 ;
break;
case 1 :
V_8 -> V_16 += V_9 ;
V_11 = V_8 -> V_16 ;
break;
default:
V_11 = - V_17 ;
}
F_5 ( & V_12 -> V_15 ) ;
return V_11 ;
}
static T_2 F_6 ( struct V_8 * V_8 , char T_3 * V_18 ,
T_4 V_19 , T_1 * V_20 )
{
char T_3 * V_21 = V_18 ;
struct V_2 V_3 ;
int V_22 = F_7 ( V_8 -> V_23 . V_24 -> V_25 ) ;
T_5 V_26 = * V_20 ;
T_2 V_27 = 0 ;
int V_28 = 0 ;
if ( V_19 % 16 )
return - V_17 ;
for (; V_19 ; V_19 -= 16 ) {
V_3 . V_4 = V_26 ;
V_3 . V_5 = V_26 >> 32 ;
V_28 = F_8 ( V_22 , F_1 , & V_3 , 1 ) ;
if ( V_28 )
break;
if ( F_9 ( V_21 , & V_3 , 16 ) ) {
V_28 = - V_29 ;
break;
}
V_21 += 16 ;
V_27 += 16 ;
* V_20 = ++ V_26 ;
}
return V_27 ? V_27 : V_28 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_8 * V_8 )
{
unsigned int V_22 ;
struct V_30 * V_31 ;
V_22 = F_7 ( V_8 -> V_23 . V_24 -> V_25 ) ;
if ( V_22 >= V_32 || ! F_11 ( V_22 ) )
return - V_33 ;
V_31 = & F_12 ( V_22 ) ;
if ( V_31 -> V_34 < 0 )
return - V_35 ;
return 0 ;
}
static T_6 int F_13 ( int V_22 )
{
struct V_36 * V_37 ;
V_37 = F_14 ( V_38 , NULL , F_15 ( V_39 , V_22 ) , NULL ,
L_1 , V_22 ) ;
return F_16 ( V_37 ) ? F_17 ( V_37 ) : 0 ;
}
static void F_18 ( int V_22 )
{
F_19 ( V_38 , F_15 ( V_39 , V_22 ) ) ;
}
static int T_6 F_20 ( struct V_40 * V_41 ,
unsigned long V_42 ,
void * V_43 )
{
unsigned int V_22 = ( unsigned long ) V_43 ;
int V_28 = 0 ;
switch ( V_42 ) {
case V_44 :
V_28 = F_13 ( V_22 ) ;
break;
case V_45 :
case V_46 :
case V_47 :
F_18 ( V_22 ) ;
break;
}
return F_21 ( V_28 ) ;
}
static char * F_22 ( struct V_36 * V_37 , T_7 * V_48 )
{
return F_23 ( V_49 , L_2 , F_24 ( V_37 -> V_50 ) ) ;
}
static int T_8 F_25 ( void )
{
int V_51 , V_28 = 0 ;
V_51 = 0 ;
if ( F_26 ( V_39 , 0 , V_52 ,
L_3 , & V_53 ) ) {
F_27 ( V_54 L_4 ,
V_39 ) ;
V_28 = - V_55 ;
goto V_56;
}
V_38 = F_28 ( V_57 , L_5 ) ;
if ( F_16 ( V_38 ) ) {
V_28 = F_17 ( V_38 ) ;
goto V_58;
}
V_38 -> V_59 = F_22 ;
F_29 (i) {
V_28 = F_13 ( V_51 ) ;
if ( V_28 != 0 )
goto V_60;
}
F_30 ( & V_61 ) ;
V_28 = 0 ;
goto V_56;
V_60:
V_51 = 0 ;
F_29 (i) {
F_18 ( V_51 ) ;
}
F_31 ( V_38 ) ;
V_58:
F_32 ( V_39 , 0 , V_52 , L_3 ) ;
V_56:
return V_28 ;
}
static void T_9 F_33 ( void )
{
int V_22 = 0 ;
F_29 (cpu)
F_18 ( V_22 ) ;
F_31 ( V_38 ) ;
F_32 ( V_39 , 0 , V_52 , L_3 ) ;
F_34 ( & V_61 ) ;
}
