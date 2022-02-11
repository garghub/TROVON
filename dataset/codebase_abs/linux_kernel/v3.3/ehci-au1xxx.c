static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
V_4 -> V_6 = 0 ;
F_4 ( V_4 ) ;
return V_5 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
int V_5 ;
if ( F_6 () )
return - V_11 ;
if ( V_8 -> V_9 [ 1 ] . V_12 != V_13 ) {
F_7 ( L_1 ) ;
return - V_14 ;
}
V_2 = F_8 ( & V_15 , & V_8 -> V_16 , L_2 ) ;
if ( ! V_2 )
return - V_14 ;
V_10 = F_9 ( V_8 , V_17 , 0 ) ;
V_2 -> V_18 = V_10 -> V_19 ;
V_2 -> V_20 = F_10 ( V_10 ) ;
if ( ! F_11 ( V_2 -> V_18 , V_2 -> V_20 , V_21 ) ) {
F_7 ( L_3 ) ;
V_5 = - V_22 ;
goto V_23;
}
V_2 -> V_24 = F_12 ( V_2 -> V_18 , V_2 -> V_20 ) ;
if ( ! V_2 -> V_24 ) {
F_7 ( L_4 ) ;
V_5 = - V_14 ;
goto V_25;
}
if ( F_13 ( V_26 , 1 ) ) {
F_14 ( V_27 L_5 , V_8 -> V_28 ) ;
V_5 = - V_11 ;
goto V_29;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_30 = V_2 -> V_24 ;
V_4 -> V_24 = V_2 -> V_24 +
F_15 ( V_4 , F_16 ( & V_4 -> V_30 -> V_31 ) ) ;
V_4 -> V_32 = F_16 ( & V_4 -> V_30 -> V_32 ) ;
V_5 = F_17 ( V_2 , V_8 -> V_9 [ 1 ] . V_19 ,
V_33 ) ;
if ( V_5 == 0 ) {
F_18 ( V_8 , V_2 ) ;
return V_5 ;
}
F_13 ( V_26 , 0 ) ;
V_29:
F_19 ( V_2 -> V_24 ) ;
V_25:
F_20 ( V_2 -> V_18 , V_2 -> V_20 ) ;
V_23:
F_21 ( V_2 ) ;
return V_5 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_23 ( V_8 ) ;
F_24 ( V_2 ) ;
F_13 ( V_26 , 0 ) ;
F_19 ( V_2 -> V_24 ) ;
F_20 ( V_2 -> V_18 , V_2 -> V_20 ) ;
F_21 ( V_2 ) ;
F_18 ( V_8 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_34 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_12 ;
int V_35 = 0 ;
if ( F_27 ( V_36 , V_4 -> V_37 ) )
F_28 ( 10 ) ;
F_29 ( V_4 , F_30 ( V_16 ) ) ;
F_31 ( & V_4 -> V_38 , V_12 ) ;
F_32 ( V_4 , 0 , & V_4 -> V_24 -> V_39 ) ;
( void ) F_33 ( V_4 , & V_4 -> V_24 -> V_39 ) ;
F_34 ( V_40 , & V_2 -> V_12 ) ;
F_35 ( & V_4 -> V_38 , V_12 ) ;
F_13 ( V_26 , 0 ) ;
return V_35 ;
}
static int F_36 ( struct V_34 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_13 ( V_26 , 1 ) ;
if ( F_27 ( V_36 , V_4 -> V_37 ) )
F_28 ( 100 ) ;
F_37 ( V_40 , & V_2 -> V_12 ) ;
if ( F_33 ( V_4 , & V_4 -> V_24 -> V_41 ) == V_42 ) {
int V_43 = V_44 ;
F_38 ( V_4 ) ;
if ( ! V_2 -> V_45 . V_46 -> V_47 )
V_43 &= ~ V_48 ;
F_32 ( V_4 , V_43 , & V_4 -> V_24 -> V_39 ) ;
F_33 ( V_4 , & V_4 -> V_24 -> V_39 ) ;
return 0 ;
}
F_39 ( V_4 , L_6 ) ;
F_40 ( V_2 -> V_45 . V_46 ) ;
( void ) F_41 ( V_4 ) ;
( void ) F_4 ( V_4 ) ;
F_42 ( & V_4 -> V_38 ) ;
if ( V_4 -> V_49 )
F_43 ( V_4 ) ;
F_44 ( V_4 ) ;
F_45 ( & V_4 -> V_38 ) ;
F_32 ( V_4 , V_4 -> V_50 , & V_4 -> V_24 -> V_50 ) ;
F_32 ( V_4 , V_42 , & V_4 -> V_24 -> V_41 ) ;
F_33 ( V_4 , & V_4 -> V_24 -> V_50 ) ;
F_46 ( V_4 , 1 ) ;
V_4 -> V_51 = V_52 ;
return 0 ;
}
