static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) ( V_2 -> V_4 ) ;
T_2 * V_5 = V_3 -> V_5 ;
unsigned int V_6 = V_5 -> V_6 ;
F_2 ( V_6 ) ;
F_2 ( V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_5 -> V_7 , V_5 ) ;
F_5 ( V_5 ) ;
}
static int F_6 ( unsigned int V_6 , unsigned V_7 ,
enum V_8 V_9 )
{
T_1 * V_3 ;
T_2 * V_5 ;
char * V_10 ;
int V_11 ;
V_5 = F_7 ( 1 ) ;
if ( ! V_5 ) {
F_8 ( V_12 L_1 ) ;
V_11 = - V_13 ;
goto V_14;
}
V_3 = V_5 -> V_15 ;
switch ( V_9 ) {
case V_16 : sprintf ( V_5 -> V_17 , L_2 , V_6 ) ; break;
case V_18 : sprintf ( V_5 -> V_17 , L_3 , V_6 ) ; break;
default: sprintf ( V_5 -> V_17 , L_4 , V_6 ) ; break;
}
V_5 -> V_6 = V_6 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_9 = V_9 ;
V_11 = F_9 ( V_5 -> V_7 , V_19 , V_20 , V_5 -> V_17 , V_5 ) ;
if ( V_11 ) {
F_8 ( V_21 L_5 ,
V_5 -> V_7 ) ;
V_11 = - V_22 ;
goto V_23;
}
F_2 ( V_5 -> V_6 ) ;
if ( ( V_11 = F_10 ( V_5 -> V_6 , V_5 -> V_9 ) ) != 0 ) {
F_8 ( V_24 L_6 ,
V_5 -> V_6 , V_11 ) ;
V_11 = - V_25 ;
goto V_26;
}
F_2 ( V_5 -> V_6 ) ;
F_11 ( V_5 ) ;
V_3 -> V_27 . V_28 = V_29 ;
V_3 -> V_27 . V_30 = L_7 ;
V_3 -> V_27 . V_4 = V_3 ;
V_3 -> V_27 . V_31 = V_32 ;
V_3 -> V_27 . V_33 = V_34 ;
V_3 -> V_27 . V_35 = V_36 ;
V_3 -> V_27 . V_37 = V_38 ;
V_3 -> V_27 . V_39 = V_40 ;
V_3 -> V_27 . V_41 = V_42 ;
V_3 -> V_27 . V_43 = & V_44 ;
strcpy ( V_3 -> V_27 . V_17 , V_5 -> V_17 ) ;
V_11 = F_12 ( & V_3 -> V_27 ) ;
if ( V_11 ) {
F_8 ( V_21 L_8 ) ;
goto V_26;
}
switch ( V_9 ) {
case V_16 : V_10 = L_9 ; break;
case V_18 : V_10 = L_10 ; break;
default : V_10 = L_11 ; break;
}
F_8 ( V_45 L_12 ,
V_10 , V_5 -> V_6 , V_5 -> V_7 , V_5 -> V_46 ) ;
F_13 ( & V_5 -> V_47 , & V_48 ) ;
return V_3 -> V_27 . V_49 ;
V_26:
F_4 ( V_5 -> V_7 , V_5 ) ;
V_23:
F_5 ( V_5 ) ;
V_14:
return V_11 ;
}
static char * V_42 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) ( V_2 -> V_4 ) ;
if ( ! V_3 )
return L_13 ;
sprintf ( V_3 -> V_50 , L_14 ,
V_3 -> V_10 [ 0 ] ? V_3 -> V_10 : L_15 ,
V_3 -> V_51 [ V_52 ] ? V_3 -> V_51 [ V_52 ] : L_15 ,
V_3 -> V_5 ? V_3 -> V_5 -> V_6 : 0x0 ,
V_3 -> V_5 ? V_3 -> V_5 -> V_7 : 0 ,
V_3 -> V_5 ? V_3 -> V_5 -> V_46 : 0
) ;
return V_3 -> V_50 ;
}
int F_14 ( unsigned int V_6 , unsigned V_7 )
{
return F_6 ( V_6 , V_7 , V_53 ) ;
}
int F_15 ( unsigned int V_6 , unsigned V_7 )
{
return F_6 ( V_6 , V_7 , V_16 ) ;
}
int F_16 ( unsigned int V_6 , unsigned V_7 )
{
return F_6 ( V_6 , V_7 , V_18 ) ;
}
int F_17 ( unsigned int V_6 , unsigned V_7 )
{
struct V_54 * V_55 ;
T_2 * V_5 ;
F_18 (l, &cards) {
V_5 = F_19 ( V_55 , T_2 , V_47 ) ;
if ( V_5 -> V_6 == V_6 && V_5 -> V_7 == V_7 ) {
F_1 ( & V_5 -> V_15 [ 0 ] . V_27 ) ;
return 0 ;
}
}
return - V_56 ;
}
static int T_3 F_20 ( void )
{
char * V_57 ;
char V_58 [ 32 ] ;
if ( ( V_57 = strchr ( V_46 , ':' ) ) != NULL && V_57 [ 1 ] ) {
F_21 ( V_58 , V_57 + 2 , 32 ) ;
if ( ( V_57 = strchr ( V_58 , '$' ) ) != NULL && V_57 > V_58 )
* ( V_57 - 1 ) = 0 ;
} else
strcpy ( V_58 , L_16 ) ;
F_21 ( V_59 . V_46 , V_58 , 32 ) ;
F_22 ( & V_59 ) ;
F_8 ( V_45 L_17 , V_58 ) ;
return 0 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_59 ) ;
}
