static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_6 = V_2 -> V_7 + 0x100 ;
#ifdef F_3
V_5 -> V_8 = 1 ;
V_5 -> V_9 = 1 ;
#endif
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_10 = 0 ;
F_5 ( V_5 , 0x1010 , & V_5 -> V_7 -> V_11 [ 1 ] ) ;
return V_3 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_3 ;
if ( F_7 () )
return - V_16 ;
if ( V_13 -> V_14 [ 1 ] . V_17 != V_18 ) {
F_8 ( L_1 ) ;
return - V_19 ;
}
V_2 = F_9 ( & V_20 , & V_13 -> V_21 , L_2 ) ;
if ( ! V_2 )
return - V_19 ;
V_15 = F_10 ( V_13 , V_22 , 0 ) ;
V_2 -> V_23 = V_15 -> V_24 ;
V_2 -> V_25 = F_11 ( V_15 ) ;
if ( ! F_12 ( V_2 -> V_23 , V_2 -> V_25 , V_26 ) ) {
F_8 ( L_3 ) ;
V_3 = - V_27 ;
goto V_28;
}
V_2 -> V_7 = F_13 ( V_2 -> V_23 , V_2 -> V_25 ) ;
if ( ! V_2 -> V_7 ) {
F_8 ( L_4 ) ;
V_3 = - V_19 ;
goto V_29;
}
V_2 -> V_30 = 1 ;
V_3 = F_14 ( V_2 , V_13 -> V_14 [ 1 ] . V_24 ,
V_31 ) ;
if ( V_3 == 0 ) {
F_15 ( V_13 , V_2 ) ;
return V_3 ;
}
F_16 ( V_2 -> V_7 ) ;
V_29:
F_17 ( V_2 -> V_23 , V_2 -> V_25 ) ;
V_28:
F_18 ( V_2 ) ;
return V_3 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
F_21 ( V_2 ) ;
F_16 ( V_2 -> V_7 ) ;
F_17 ( V_2 -> V_23 , V_2 -> V_25 ) ;
F_18 ( V_2 ) ;
F_15 ( V_13 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_32 * V_21 )
{
struct V_1 * V_2 = F_23 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_17 ;
int V_33 = 0 ;
if ( F_24 ( V_34 , V_5 -> V_35 ) )
F_25 ( 20 ) ;
F_26 ( V_5 , F_27 ( V_21 ) ) ;
F_28 ( & V_5 -> V_36 , V_17 ) ;
F_5 ( V_5 , 0 , & V_5 -> V_7 -> V_37 ) ;
( void ) F_29 ( V_5 , & V_5 -> V_7 -> V_37 ) ;
F_30 ( V_38 , & V_2 -> V_17 ) ;
F_31 ( & V_5 -> V_36 , V_17 ) ;
return V_33 ;
}
static int F_32 ( struct V_32 * V_21 )
{
struct V_1 * V_2 = F_23 ( V_21 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_24 ( V_34 , V_5 -> V_35 ) )
F_25 ( 100 ) ;
F_33 ( V_38 , & V_2 -> V_17 ) ;
if ( F_29 ( V_5 , & V_5 -> V_7 -> V_39 ) == V_40 ) {
int V_41 = V_42 ;
F_34 ( V_5 ) ;
if ( ! V_2 -> V_43 . V_44 -> V_45 )
V_41 &= ~ V_46 ;
F_5 ( V_5 , V_41 , & V_5 -> V_7 -> V_37 ) ;
F_29 ( V_5 , & V_5 -> V_7 -> V_37 ) ;
return 0 ;
}
F_35 ( V_5 , L_5 ) ;
F_36 ( V_2 -> V_43 . V_44 ) ;
( void ) F_37 ( V_5 ) ;
( void ) F_38 ( V_5 ) ;
F_39 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_47 )
F_40 ( V_5 ) ;
F_41 ( V_5 ) ;
F_42 ( & V_5 -> V_36 ) ;
F_5 ( V_5 , V_5 -> V_48 , & V_5 -> V_7 -> V_48 ) ;
F_5 ( V_5 , V_40 , & V_5 -> V_7 -> V_39 ) ;
F_29 ( V_5 , & V_5 -> V_7 -> V_48 ) ;
F_43 ( V_5 , 1 ) ;
V_5 -> V_49 = V_50 ;
return 0 ;
}
