static
int F_1 ( struct V_1 * V_1 , const void * V_2 ,
T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = & V_1 -> V_7 -> V_6 ;
struct V_8 * V_8 = & V_1 -> V_8 ;
F_2 ( 4 , V_6 , L_1 ,
V_1 , V_2 , V_3 ) ;
V_4 = - V_9 ;
if ( V_3 < sizeof( V_10 ) )
goto V_11;
V_4 = 0 ;
if ( ! memcmp ( V_10 , V_2 , sizeof( V_10 ) ) ) {
F_3 ( V_1 ) ;
goto V_12;
}
V_4 = F_4 ( V_8 , V_2 , V_3 ) ;
if ( F_5 ( V_4 >= 0 ) )
V_4 = F_6 ( V_8 , L_2 ) ;
else
F_7 ( V_8 , V_2 , V_3 ) ;
V_11:
V_12:
F_8 ( 4 , V_6 , L_3 ,
V_1 , V_2 , V_3 , V_4 ) ;
return V_4 ;
}
static
void F_9 ( struct V_13 * V_13 )
{
int V_4 ;
struct V_1 * V_1 = V_13 -> V_14 ;
struct V_5 * V_6 = & V_1 -> V_7 -> V_6 ;
F_2 ( 4 , V_6 , L_4 ,
V_13 , V_13 -> V_15 , V_13 -> V_16 ) ;
V_4 = V_13 -> V_15 ;
switch ( V_4 ) {
case 0 :
V_4 = F_1 ( V_1 , V_13 -> V_17 ,
V_13 -> V_16 ) ;
if ( V_4 == - V_9 && F_10 ( & V_1 -> V_18 , V_19 ,
V_20 ) )
goto V_21;
if ( V_4 == - V_22 )
goto V_21;
break;
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
goto V_12;
default:
if ( F_10 ( & V_1 -> V_18 ,
V_19 , V_20 ) )
goto V_21;
F_11 ( V_6 , L_5 ,
V_13 -> V_15 ) ;
}
F_12 ( V_1 -> V_28 ) ;
V_4 = F_13 ( V_1 -> V_29 , V_30 ) ;
switch ( V_4 ) {
case 0 :
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
break;
default:
F_11 ( V_6 , L_6 , V_4 ) ;
goto V_31;
}
F_8 ( 4 , V_6 , L_7 ,
V_13 , V_13 -> V_15 , V_13 -> V_16 ) ;
return;
V_21:
F_11 ( V_6 , L_8
L_9 ) ;
V_31:
F_14 ( V_1 -> V_7 ) ;
V_12:
F_8 ( 4 , V_6 , L_7 ,
V_13 , V_13 -> V_15 , V_13 -> V_16 ) ;
}
int F_15 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 -> V_6 ;
int V_32 , V_4 = 0 ;
struct V_33 * V_34 ;
char * V_2 ;
F_2 ( 4 , V_6 , L_10 , V_1 ) ;
V_2 = F_16 ( V_35 , V_36 | V_37 ) ;
if ( V_2 == NULL ) {
V_4 = - V_22 ;
goto V_38;
}
V_1 -> V_29 = F_17 ( 0 , V_36 ) ;
if ( ! V_1 -> V_29 ) {
V_4 = - V_22 ;
F_11 ( V_6 , L_11 ) ;
goto V_39;
}
V_34 = F_18 ( V_1 -> V_7 ,
V_1 -> V_40 . V_41 ) ;
V_32 = F_19 ( V_1 -> V_28 , V_34 -> V_42 ) ;
F_20 ( V_1 -> V_29 , V_1 -> V_28 , V_32 ,
V_2 , V_35 ,
F_9 , V_1 , V_34 -> V_43 ) ;
V_4 = F_13 ( V_1 -> V_29 , V_36 ) ;
if ( V_4 != 0 ) {
F_11 ( V_6 , L_6 , V_4 ) ;
goto V_31;
}
F_8 ( 4 , V_6 , L_12 , V_1 , V_4 ) ;
return V_4 ;
V_31:
F_21 ( V_1 -> V_29 ) ;
V_39:
F_22 ( V_2 ) ;
V_38:
F_8 ( 4 , V_6 , L_12 , V_1 , V_4 ) ;
return V_4 ;
}
void F_23 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_7 -> V_6 ;
F_2 ( 4 , V_6 , L_13 , V_1 ) ;
if ( V_1 -> V_29 != NULL ) {
F_24 ( V_1 -> V_29 ) ;
F_22 ( V_1 -> V_29 -> V_17 ) ;
F_21 ( V_1 -> V_29 ) ;
V_1 -> V_29 = NULL ;
}
F_8 ( 4 , V_6 , L_13 , V_1 ) ;
}
