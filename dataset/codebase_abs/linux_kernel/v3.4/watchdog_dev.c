static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ) {
if ( V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 ) ;
else
return V_2 -> V_5 -> V_7 ( V_2 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_8 = V_2 -> V_5 -> V_7 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
F_4 ( V_3 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_8 = - V_9 ;
if ( F_2 ( V_10 , & V_2 -> V_4 ) ) {
F_6 ( L_1 ,
V_2 -> V_11 -> V_12 ) ;
return V_8 ;
}
if ( F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_8 = V_2 -> V_5 -> V_13 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
F_7 ( V_3 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static T_1 F_8 ( struct V_14 * V_14 , const char T_2 * V_15 ,
T_3 V_16 , T_4 * V_17 )
{
T_3 V_18 ;
char V_19 ;
if ( V_16 == 0 )
return 0 ;
F_7 ( V_20 , & V_21 -> V_4 ) ;
for ( V_18 = 0 ; V_18 != V_16 ; V_18 ++ ) {
if ( F_9 ( V_19 , V_15 + V_18 ) )
return - V_22 ;
if ( V_19 == 'V' )
F_4 ( V_20 , & V_21 -> V_4 ) ;
}
F_1 ( V_21 ) ;
return V_16 ;
}
static long F_10 ( struct V_14 * V_14 , unsigned int V_23 ,
unsigned long V_24 )
{
void T_2 * V_25 = ( void T_2 * ) V_24 ;
int T_2 * V_26 = V_25 ;
unsigned int V_27 ;
int V_8 ;
if ( V_21 -> V_5 -> V_28 ) {
V_8 = V_21 -> V_5 -> V_28 ( V_21 , V_23 , V_24 ) ;
if ( V_8 != - V_29 )
return V_8 ;
}
switch ( V_23 ) {
case V_30 :
return F_11 ( V_25 , V_21 -> V_11 ,
sizeof( struct V_31 ) ) ? - V_22 : 0 ;
case V_32 :
V_27 = V_21 -> V_5 -> V_4 ? V_21 -> V_5 -> V_4 ( V_21 ) : 0 ;
return F_12 ( V_27 , V_26 ) ;
case V_33 :
return F_12 ( V_21 -> V_34 , V_26 ) ;
case V_35 :
if ( F_9 ( V_27 , V_26 ) )
return - V_22 ;
if ( V_27 & V_36 ) {
V_8 = F_5 ( V_21 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_27 & V_37 ) {
V_8 = F_3 ( V_21 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
case V_38 :
if ( ! ( V_21 -> V_11 -> V_39 & V_40 ) )
return - V_41 ;
F_1 ( V_21 ) ;
return 0 ;
case V_42 :
if ( ( V_21 -> V_5 -> V_43 == NULL ) ||
! ( V_21 -> V_11 -> V_39 & V_44 ) )
return - V_41 ;
if ( F_9 ( V_27 , V_26 ) )
return - V_22 ;
if ( ( V_21 -> V_45 != 0 ) &&
( V_27 < V_21 -> V_46 || V_27 > V_21 -> V_45 ) )
return - V_47 ;
V_8 = V_21 -> V_5 -> V_43 ( V_21 , V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
F_1 ( V_21 ) ;
case V_48 :
if ( V_21 -> V_49 == 0 )
return - V_41 ;
return F_12 ( V_21 -> V_49 , V_26 ) ;
case V_50 :
if ( ! V_21 -> V_5 -> V_51 )
return - V_41 ;
return F_12 ( V_21 -> V_5 -> V_51 ( V_21 ) , V_26 ) ;
default:
return - V_52 ;
}
}
static int F_13 ( struct V_53 * V_53 , struct V_14 * V_14 )
{
int V_8 = - V_9 ;
if ( F_14 ( V_54 , & V_21 -> V_4 ) )
return - V_9 ;
if ( ! F_15 ( V_21 -> V_5 -> V_55 ) )
goto V_56;
V_8 = F_3 ( V_21 ) ;
if ( V_8 < 0 )
goto V_57;
return F_16 ( V_53 , V_14 ) ;
V_57:
F_17 ( V_21 -> V_5 -> V_55 ) ;
V_56:
F_7 ( V_54 , & V_21 -> V_4 ) ;
return V_8 ;
}
static int F_18 ( struct V_53 * V_53 , struct V_14 * V_14 )
{
int V_8 = - V_9 ;
if ( F_19 ( V_20 , & V_21 -> V_4 ) ||
! ( V_21 -> V_11 -> V_39 & V_58 ) )
V_8 = F_5 ( V_21 ) ;
if ( V_8 < 0 ) {
F_20 ( L_2 , V_21 -> V_11 -> V_12 ) ;
F_1 ( V_21 ) ;
}
F_17 ( V_21 -> V_5 -> V_55 ) ;
F_7 ( V_54 , & V_21 -> V_4 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_59 )
{
int V_8 ;
if ( F_14 ( 0 , & V_60 ) ) {
F_22 ( L_3 ) ;
return - V_9 ;
}
V_21 = V_59 ;
V_8 = F_23 ( & V_61 ) ;
if ( V_8 != 0 ) {
F_22 ( L_4 ,
V_59 -> V_11 -> V_12 , V_62 , V_8 ) ;
goto V_56;
}
return 0 ;
V_56:
V_21 = NULL ;
F_7 ( 0 , & V_60 ) ;
return V_8 ;
}
int F_24 ( struct V_1 * V_59 )
{
if ( ! F_2 ( 0 , & V_60 ) || ! V_21 )
return - V_63 ;
if ( V_59 != V_21 ) {
F_22 ( L_5 ,
V_59 -> V_11 -> V_12 ) ;
return - V_63 ;
}
F_25 ( & V_61 ) ;
V_21 = NULL ;
F_7 ( 0 , & V_60 ) ;
return 0 ;
}
