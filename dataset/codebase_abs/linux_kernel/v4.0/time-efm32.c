static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
switch ( V_2 ) {
case V_7 :
F_3 ( V_8 , V_6 -> V_9 + V_10 ) ;
F_3 ( V_6 -> V_11 , V_6 -> V_9 + V_12 ) ;
F_3 ( V_13 |
V_14 |
V_15 ,
V_6 -> V_9 + V_16 ) ;
F_3 ( V_17 , V_6 -> V_9 + V_10 ) ;
break;
case V_18 :
F_3 ( V_8 , V_6 -> V_9 + V_10 ) ;
F_3 ( V_13 |
V_14 |
V_19 |
V_15 ,
V_6 -> V_9 + V_16 ) ;
break;
case V_20 :
case V_21 :
F_3 ( V_8 , V_6 -> V_9 + V_10 ) ;
break;
case V_22 :
break;
}
}
static int F_4 ( unsigned long V_23 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
F_3 ( V_8 , V_6 -> V_9 + V_10 ) ;
F_3 ( V_23 , V_6 -> V_9 + V_24 ) ;
F_3 ( V_17 , V_6 -> V_9 + V_10 ) ;
return 0 ;
}
static T_1 F_5 ( int V_25 , void * V_26 )
{
struct V_5 * V_6 = V_26 ;
F_3 ( V_27 , V_6 -> V_9 + V_28 ) ;
V_6 -> V_4 . V_29 ( & V_6 -> V_4 ) ;
return V_30 ;
}
static int T_2 F_6 ( struct V_31 * V_32 )
{
struct V_33 * V_33 ;
void T_3 * V_9 ;
unsigned long V_34 ;
int V_35 ;
V_33 = F_7 ( V_32 , 0 ) ;
if ( F_8 ( V_33 ) ) {
V_35 = F_9 ( V_33 ) ;
F_10 ( L_1 , V_35 ) ;
goto V_36;
}
V_35 = F_11 ( V_33 ) ;
if ( V_35 ) {
F_10 ( L_2 ,
V_35 ) ;
goto V_37;
}
V_34 = F_12 ( V_33 ) ;
V_9 = F_13 ( V_32 , 0 ) ;
if ( ! V_9 ) {
V_35 = - V_38 ;
F_10 ( L_3 ) ;
goto V_39;
}
F_3 ( V_13 |
V_14 |
V_40 , V_9 + V_16 ) ;
F_3 ( V_17 , V_9 + V_10 ) ;
V_35 = F_14 ( V_9 + V_24 , L_4 ,
F_15 ( V_34 , 1024 ) , 200 , 16 ,
V_41 ) ;
if ( V_35 ) {
F_10 ( L_5 , V_35 ) ;
goto V_42;
}
return 0 ;
V_42:
F_16 ( V_9 ) ;
V_39:
F_17 ( V_33 ) ;
V_37:
F_18 ( V_33 ) ;
V_36:
return V_35 ;
}
static int T_2 F_19 ( struct V_31 * V_32 )
{
struct V_33 * V_33 ;
void T_3 * V_9 ;
unsigned long V_34 ;
int V_25 ;
int V_35 ;
V_33 = F_7 ( V_32 , 0 ) ;
if ( F_8 ( V_33 ) ) {
V_35 = F_9 ( V_33 ) ;
F_10 ( L_6 , V_35 ) ;
goto V_36;
}
V_35 = F_11 ( V_33 ) ;
if ( V_35 ) {
F_10 ( L_7 ,
V_35 ) ;
goto V_37;
}
V_34 = F_12 ( V_33 ) ;
V_9 = F_13 ( V_32 , 0 ) ;
if ( ! V_9 ) {
V_35 = - V_38 ;
F_10 ( L_8 ) ;
goto V_39;
}
V_25 = F_20 ( V_32 , 0 ) ;
if ( ! V_25 ) {
V_35 = - V_43 ;
F_10 ( L_9 ) ;
goto V_44;
}
F_3 ( V_27 , V_9 + V_45 ) ;
V_46 . V_9 = V_9 ;
V_46 . V_11 = F_15 ( V_34 , 1024 * V_47 ) ;
F_21 ( & V_46 . V_4 ,
F_15 ( V_34 , 1024 ) ,
0xf , 0xffff ) ;
F_22 ( V_25 , & V_48 ) ;
return 0 ;
V_44:
F_16 ( V_9 ) ;
V_39:
F_17 ( V_33 ) ;
V_37:
F_18 ( V_33 ) ;
V_36:
return V_35 ;
}
static void T_2 F_23 ( struct V_31 * V_32 )
{
static int V_49 , V_50 ;
int V_35 ;
if ( ! V_49 ) {
V_35 = F_6 ( V_32 ) ;
if ( ! V_35 ) {
V_49 = 1 ;
return;
}
}
if ( ! V_50 ) {
V_35 = F_19 ( V_32 ) ;
if ( ! V_35 ) {
V_50 = 1 ;
return;
}
}
}
