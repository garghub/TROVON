static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = V_3 -> V_7 . V_6 ;
struct V_6 * V_8 = NULL ;
struct V_1 * V_9 ;
unsigned V_10 = V_3 -> V_11 ;
struct V_12 V_13 ;
int V_14 = 0 ;
int V_15 ;
F_2 ( L_1 ,
V_6 -> V_16 -> V_17 . V_18 ,
V_6 -> V_17 . V_18 ) ;
if ( ( V_10 & V_19 ) == 3 )
V_10 -- ;
V_10 &= ~ ( V_20 | V_21 ) ;
V_8 = F_3 ( V_6 ) ;
V_9 = V_8 -> V_22 ;
V_5 = F_4 ( V_3 -> V_7 . V_6 , V_3 -> V_23 ) ;
V_15 = F_5 ( V_5 ) ;
if ( F_6 ( V_5 ) )
goto V_24;
V_13 . V_25 = V_26 ;
if ( V_10 & V_27 ) {
V_13 . V_25 |= V_28 ;
V_13 . V_29 = 0 ;
F_7 ( V_1 ) ;
}
V_1 = F_8 ( V_9 ) -> F_9 ( V_9 , V_5 , V_10 , & V_13 , & V_14 ) ;
if ( F_6 ( V_1 ) ) {
V_15 = F_5 ( V_1 ) ;
switch ( V_15 ) {
case - V_30 :
case - V_31 :
case - V_32 :
case - V_33 :
case - V_34 :
goto V_35;
default:
goto V_36;
}
}
if ( V_1 != V_6 -> V_22 )
goto V_36;
F_10 ( V_6 , F_11 ( V_9 ) ) ;
F_12 ( V_3 , V_5 ) ;
F_13 ( V_1 , V_3 ) ;
V_15 = 0 ;
V_35:
F_14 ( V_5 ) ;
V_24:
F_15 ( V_8 ) ;
return V_15 ;
V_36:
F_16 ( V_6 ) ;
V_15 = - V_37 ;
goto V_35;
}
static int
F_17 ( struct V_2 * V_2 , T_1 V_38 , T_1 V_39 , int V_40 )
{
int V_41 ;
struct V_1 * V_1 = F_18 ( V_2 ) ;
do {
V_41 = F_19 ( V_1 -> V_42 , V_38 , V_39 ) ;
if ( V_41 != 0 )
break;
F_20 ( & V_1 -> V_43 ) ;
V_41 = F_21 ( V_2 , V_38 , V_39 , V_40 ) ;
if ( ! V_41 && ! V_40 )
V_41 = F_22 ( V_1 , true ) ;
F_23 ( & V_1 -> V_43 ) ;
V_38 = 0 ;
V_39 = V_44 ;
} while ( V_41 == - V_45 );
return V_41 ;
}
