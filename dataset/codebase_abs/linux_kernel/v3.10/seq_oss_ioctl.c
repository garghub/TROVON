static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_4 V_5 ;
if ( F_2 ( & V_5 , V_3 , sizeof( V_5 ) ) )
return - V_6 ;
if ( F_3 ( V_2 , V_5 . V_7 , & V_5 ) < 0 )
return - V_8 ;
if ( F_4 ( V_3 , & V_5 , sizeof( V_5 ) ) )
return - V_6 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_9 V_5 ;
if ( F_2 ( & V_5 , V_3 , sizeof( V_5 ) ) )
return - V_6 ;
if ( F_6 ( V_2 , V_5 . V_7 , & V_5 ) < 0 )
return - V_8 ;
if ( F_4 ( V_3 , & V_5 , sizeof( V_5 ) ) )
return - V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , void T_1 * V_3 )
{
unsigned char V_10 [ 8 ] ;
struct V_11 V_12 ;
if ( F_2 ( V_10 , V_3 , 8 ) )
return - V_6 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
F_8 ( V_2 , & V_12 , V_2 -> V_13 . V_14 , V_2 -> V_13 . V_15 ) ;
V_12 . time . V_16 = 0 ;
if ( ! F_9 ( V_2 , (union V_17 * ) V_10 , & V_12 ) ) {
F_10 ( V_2 , & V_12 , 0 , 0 ) ;
}
return 0 ;
}
int
F_11 ( struct V_1 * V_2 , unsigned int V_18 , unsigned long V_19 )
{
int V_20 , V_21 ;
void T_1 * V_3 = ( void T_1 * ) V_19 ;
int T_1 * V_22 = V_3 ;
switch ( V_18 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
return F_12 ( V_2 -> V_32 , V_18 , V_3 ) ;
case V_33 :
F_13 ( ( L_1 ) ) ;
F_14 ( V_2 ) ;
return - V_8 ;
case V_34 :
F_13 ( ( L_2 ) ) ;
if ( ! F_15 ( V_2 -> V_35 ) || V_2 -> V_36 == NULL )
return 0 ;
while ( F_16 ( V_2 -> V_36 ) )
;
if ( F_17 ( V_37 ) )
return - V_38 ;
return 0 ;
case V_39 :
F_13 ( ( L_3 ) ) ;
F_14 ( V_2 ) ;
return 0 ;
case V_40 :
F_13 ( ( L_4 ) ) ;
if ( F_18 ( V_20 , V_22 ) )
return - V_6 ;
return F_19 ( V_2 , V_20 , V_2 -> V_35 ) ;
case V_41 :
F_13 ( ( L_5 ) ) ;
if ( V_2 -> V_42 == NULL || ! F_20 ( V_2 -> V_35 ) )
return 0 ;
return F_21 ( V_2 -> V_42 -> V_43 , V_22 ) ? - V_6 : 0 ;
case V_44 :
F_13 ( ( L_6 ) ) ;
if ( ! F_15 ( V_2 -> V_35 ) || V_2 -> V_36 == NULL )
return 0 ;
return F_21 ( F_22 ( V_2 -> V_36 ) , V_22 ) ? - V_6 : 0 ;
case V_45 :
F_13 ( ( L_7 ) ) ;
return F_21 ( F_23 ( V_2 -> V_32 ) , V_22 ) ? - V_6 : 0 ;
case V_46 :
F_13 ( ( L_8 ) ) ;
if ( F_18 ( V_20 , V_22 ) )
return - V_6 ;
return F_24 ( V_2 , V_20 , V_18 , V_19 ) ;
case V_47 :
F_13 ( ( L_9 ) ) ;
return F_21 ( V_2 -> V_48 , V_22 ) ? - V_6 : 0 ;
case V_49 :
F_13 ( ( L_10 ) ) ;
return F_21 ( V_2 -> V_50 , V_22 ) ? - V_6 : 0 ;
case V_51 :
F_13 ( ( L_11 ) ) ;
if ( F_18 ( V_20 , V_22 ) )
return - V_6 ;
V_21 = F_24 ( V_2 , V_20 , V_18 , V_19 ) ;
return F_21 ( V_21 , V_22 ) ? - V_6 : 0 ;
case V_52 :
F_13 ( ( L_12 ) ) ;
if ( F_18 ( V_20 , V_22 ) )
return - V_6 ;
F_24 ( V_2 , V_20 , V_18 , V_19 ) ;
return 0 ;
case V_53 :
case V_54 :
F_13 ( ( L_13 ) ) ;
return F_1 ( V_2 , V_3 ) ;
case V_55 :
F_13 ( ( L_14 ) ) ;
return F_7 ( V_2 , V_3 ) ;
case V_56 :
F_13 ( ( L_15 ) ) ;
return F_5 ( V_2 , V_3 ) ;
case V_57 :
F_13 ( ( L_16 ) ) ;
if ( ! F_15 ( V_2 -> V_35 ) )
return 0 ;
if ( F_18 ( V_21 , V_22 ) )
return - V_6 ;
if ( V_21 < 1 )
V_21 = 1 ;
if ( V_21 >= V_2 -> V_36 -> V_58 )
V_21 = V_2 -> V_36 -> V_58 - 1 ;
F_25 ( V_2 -> V_36 , V_21 ) ;
return 0 ;
case V_59 :
F_13 ( ( L_17 ) ) ;
if ( V_2 -> V_42 == NULL || ! F_20 ( V_2 -> V_35 ) )
return 0 ;
if ( F_18 ( V_21 , V_22 ) )
return - V_6 ;
if ( V_21 <= 0 )
V_21 = - 1 ;
else
V_21 = ( V_60 * V_21 ) / 10 ;
V_2 -> V_42 -> V_61 = V_21 ;
return F_21 ( V_21 , V_22 ) ? - V_6 : 0 ;
default:
F_13 ( ( L_18 ) ) ;
if ( ! F_15 ( V_2 -> V_35 ) )
return - V_62 ;
return F_24 ( V_2 , 0 , V_18 , V_19 ) ;
}
return 0 ;
}
