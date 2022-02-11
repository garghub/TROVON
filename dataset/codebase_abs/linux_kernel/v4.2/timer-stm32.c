static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
void * V_7 = V_6 -> V_7 ;
switch ( V_2 ) {
case V_8 :
F_3 ( V_6 -> V_9 , V_7 + V_10 ) ;
F_3 ( V_11 | V_12 , V_7 + V_13 ) ;
break;
case V_14 :
default:
F_3 ( 0 , V_7 + V_13 ) ;
break;
}
}
static int F_4 ( unsigned long V_15 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
F_3 ( V_15 , V_6 -> V_7 + V_10 ) ;
F_3 ( V_11 | V_16 | V_12 ,
V_6 -> V_7 + V_13 ) ;
return 0 ;
}
static T_1 F_5 ( int V_17 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
F_3 ( 0 , V_6 -> V_7 + V_19 ) ;
V_6 -> V_4 . V_20 ( & V_6 -> V_4 ) ;
return V_21 ;
}
static void T_2 F_6 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = & V_24 ;
struct V_25 * V_25 ;
struct V_26 * V_27 ;
unsigned long V_28 , V_29 ;
int V_17 , V_30 , V_31 , V_32 = 1 ;
V_25 = F_7 ( V_23 , 0 ) ;
if ( F_8 ( V_25 ) ) {
V_30 = F_9 ( V_25 ) ;
F_10 ( L_1 , V_30 ) ;
goto V_33;
}
V_30 = F_11 ( V_25 ) ;
if ( V_30 ) {
F_10 ( L_2 ,
V_30 ) ;
goto V_34;
}
V_28 = F_12 ( V_25 ) ;
V_27 = F_13 ( V_23 , NULL ) ;
if ( ! F_8 ( V_27 ) ) {
F_14 ( V_27 ) ;
F_15 ( V_27 ) ;
}
V_6 -> V_7 = F_16 ( V_23 , 0 ) ;
if ( ! V_6 -> V_7 ) {
F_10 ( L_3 ) ;
goto V_35;
}
V_17 = F_17 ( V_23 , 0 ) ;
if ( ! V_17 ) {
F_10 ( L_4 , V_23 -> V_36 ) ;
goto V_37;
}
F_3 ( ~ 0U , V_6 -> V_7 + V_10 ) ;
V_29 = F_18 ( V_6 -> V_7 + V_10 ) ;
if ( V_29 == ~ 0U ) {
V_32 = 1 ;
V_31 = 32 ;
} else {
V_32 = 1024 ;
V_31 = 16 ;
}
F_3 ( 0 , V_6 -> V_7 + V_10 ) ;
F_3 ( V_32 - 1 , V_6 -> V_7 + V_38 ) ;
F_3 ( V_39 , V_6 -> V_7 + V_40 ) ;
F_3 ( V_41 , V_6 -> V_7 + V_42 ) ;
F_3 ( 0 , V_6 -> V_7 + V_19 ) ;
V_6 -> V_9 = F_19 ( V_28 , V_32 * V_43 ) ;
F_20 ( & V_6 -> V_4 ,
F_19 ( V_28 , V_32 ) ,
0x1 , V_29 ) ;
V_30 = F_21 ( V_17 , F_5 , V_44 ,
L_5 , V_6 ) ;
if ( V_30 ) {
F_10 ( L_6 , V_23 -> V_36 ) ;
goto V_37;
}
F_22 ( L_7 ,
V_23 -> V_36 , V_31 ) ;
return;
V_37:
F_23 ( V_6 -> V_7 ) ;
V_35:
F_24 ( V_25 ) ;
V_34:
F_25 ( V_25 ) ;
V_33:
return;
}
