static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 = 0 ;
T_1 V_10 ;
int V_11 ;
V_11 = F_2 ( V_4 -> V_12 , false ) ;
if ( V_11 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_8 = F_4 ( V_4 -> V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( L_2 , ( int ) F_6 ( V_8 ) ) ;
return F_6 ( V_8 ) ;
}
F_7 ( V_2 , V_15 ) ;
F_8 ( V_16 , F_9 ( V_2 ) ) ;
F_8 ( V_17 , V_18 |
V_19 ) ;
V_9 = F_10 ( V_8 ) + V_4 -> V_20 ;
F_8 ( V_21 , F_11 ( V_9 ) ) ;
F_8 ( V_22 , F_12 ( V_9 ) & 0xFFFF ) ;
F_8 ( V_23 , 0 ) ;
F_8 ( V_24 , V_25 ) ;
V_10 = V_4 -> V_26 + V_4 -> V_27 ;
F_8 ( V_28 , V_10 ) ;
F_8 ( V_29 , F_13 ( V_30 | V_31 ) ) ;
V_11 = F_14 ( ( F_15 ( V_29 ) & V_31 ) == 0 , 100 ) ;
F_3 ( L_3 , V_11 ) ;
F_8 ( V_29 , F_16 ( V_30 ) ) ;
F_17 ( V_2 , V_15 ) ;
F_18 ( V_8 ) ;
return V_11 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_5 = & V_2 -> V_5 ;
struct V_3 * V_4 = & V_5 -> V_6 ;
const char * V_33 = NULL ;
V_4 -> V_34 = NULL ;
V_4 -> V_35 = V_36 ;
V_4 -> V_37 = V_36 ;
V_4 -> V_6 = V_38 ;
if ( ! F_20 ( V_2 ) )
return;
if ( F_21 ( V_2 ) ) {
V_33 = V_39 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = V_43 ;
} else if ( F_22 ( V_2 ) ) {
V_33 = V_44 ;
V_4 -> V_40 = V_45 ;
V_4 -> V_42 = V_46 ;
} else if ( F_23 ( V_2 ) ) {
V_33 = V_47 ;
V_4 -> V_40 = V_48 ;
V_4 -> V_42 = V_49 ;
}
V_4 -> V_34 = V_33 ;
V_4 -> V_35 = V_50 ;
F_3 ( L_4 , V_33 ) ;
F_24 ( V_4 -> V_34 == NULL , L_5 ) ;
F_25 ( V_2 , V_4 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
int V_51 ;
if ( V_4 -> V_35 == V_36 )
return 0 ;
F_3 ( L_6 ,
V_4 -> V_34 ,
F_27 ( V_4 -> V_35 ) ,
F_27 ( V_4 -> V_37 ) ) ;
if ( V_4 -> V_35 == V_52 &&
V_4 -> V_37 == V_53 )
return - V_54 ;
V_4 -> V_37 = V_50 ;
switch ( V_4 -> V_35 ) {
case V_53 :
V_51 = - V_55 ;
goto V_56;
case V_36 :
case V_50 :
default:
F_28 ( 1 , L_7 ,
V_4 -> V_34 ,
F_27 ( V_4 -> V_35 ) ,
V_4 -> V_35 ) ;
V_51 = - V_57 ;
goto V_56;
case V_52 :
break;
}
V_51 = F_1 ( V_2 ) ;
if ( V_51 )
goto V_56;
V_4 -> V_37 = V_52 ;
F_3 ( L_6 ,
V_4 -> V_34 ,
F_27 ( V_4 -> V_35 ) ,
F_27 ( V_4 -> V_37 ) ) ;
return 0 ;
V_56:
if ( V_4 -> V_37 == V_50 )
V_4 -> V_37 = V_53 ;
F_29 ( L_8 , V_51 ) ;
return V_51 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
F_31 ( & V_2 -> V_58 . V_59 ) ;
if ( V_4 -> V_12 )
F_32 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
F_33 ( & V_2 -> V_58 . V_59 ) ;
V_4 -> V_35 = V_36 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_61 ;
struct V_32 * V_5 = & V_2 -> V_5 ;
struct V_7 * V_8 ;
int V_11 ;
T_1 V_62 [ 2 ] ;
if ( V_5 -> V_6 . V_37 != V_52 )
return;
V_8 = F_4 ( V_5 -> V_6 . V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_29 ( L_9 ,
( int ) F_6 ( V_8 ) ) ;
return;
}
V_62 [ 0 ] = V_63 ;
V_62 [ 1 ] = F_10 ( V_8 ) + V_5 -> V_6 . V_64 ;
V_11 = F_35 ( V_61 , V_62 , F_36 ( V_62 ) ) ;
if ( V_11 ) {
F_29 ( L_10 , V_11 ) ;
goto V_65;
}
V_11 = F_37 ( V_2 ,
V_66 ,
V_67 ,
V_67 ,
50 ) ;
if ( V_11 ) {
F_29 ( L_11 , V_11 ) ;
goto V_65;
}
V_65:
F_18 ( V_8 ) ;
}
