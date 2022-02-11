static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = V_3 -> V_7 . V_6 ;
struct V_6 * V_8 = NULL ;
struct V_1 * V_9 ;
unsigned V_10 = V_3 -> V_11 ;
struct V_12 V_13 ;
int V_14 ;
F_2 ( L_1 ,
V_6 -> V_15 -> V_16 . V_17 ,
V_6 -> V_16 . V_17 ) ;
if ( ( V_10 & V_18 ) == 3 )
V_10 -- ;
V_10 &= ~ ( V_19 | V_20 ) ;
V_8 = F_3 ( V_6 ) ;
V_9 = V_8 -> V_21 ;
V_5 = F_4 ( V_3 -> V_7 . V_6 , V_3 -> V_22 ) ;
V_14 = F_5 ( V_5 ) ;
if ( F_6 ( V_5 ) )
goto V_23;
V_13 . V_24 = V_25 ;
if ( V_10 & V_26 ) {
V_13 . V_24 |= V_27 ;
V_13 . V_28 = 0 ;
F_7 ( V_1 ) ;
}
V_1 = F_8 ( V_9 ) -> F_9 ( V_9 , V_5 , V_10 , & V_13 ) ;
if ( F_6 ( V_1 ) ) {
V_14 = F_5 ( V_1 ) ;
switch ( V_14 ) {
case - V_29 :
case - V_30 :
case - V_31 :
case - V_32 :
case - V_33 :
goto V_34;
default:
goto V_35;
}
}
F_10 ( V_1 ) ;
if ( V_1 != V_6 -> V_21 )
goto V_35;
F_11 ( V_6 , F_12 ( V_9 ) ) ;
F_13 ( V_3 , V_5 ) ;
F_14 ( V_1 , V_3 ) ;
V_14 = 0 ;
V_34:
F_15 ( V_5 ) ;
V_23:
F_16 ( V_8 ) ;
return V_14 ;
V_35:
F_17 ( V_6 ) ;
V_14 = - V_36 ;
goto V_34;
}
static int
F_18 ( struct V_2 * V_2 , T_1 V_37 , T_1 V_38 , int V_39 )
{
int V_40 ;
struct V_1 * V_1 = F_19 ( V_2 ) ;
do {
V_40 = F_20 ( V_1 -> V_41 , V_37 , V_38 ) ;
if ( V_40 != 0 )
break;
F_21 ( & V_1 -> V_42 ) ;
V_40 = F_22 ( V_2 , V_37 , V_38 , V_39 ) ;
if ( ! V_40 && ! V_39 )
V_40 = F_23 ( V_1 , true ) ;
F_24 ( & V_1 -> V_42 ) ;
V_37 = 0 ;
V_38 = V_43 ;
} while ( V_40 == - V_44 );
return V_40 ;
}
