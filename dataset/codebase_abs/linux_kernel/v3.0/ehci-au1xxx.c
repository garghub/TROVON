static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) | V_2 , V_1 ) ;
F_4 () ;
F_5 ( 1000 ) ;
F_2 ( F_3 ( V_1 ) | V_3 , V_1 ) ;
F_4 () ;
F_5 ( 1000 ) ;
}
static void F_6 ( void )
{
unsigned long V_4 ;
F_2 ( F_3 ( V_1 ) & ~ V_5 , V_1 ) ;
F_4 () ;
F_5 ( 1000 ) ;
V_4 = F_3 ( V_1 ) & ~ V_6 ;
if ( ! ( V_4 & V_7 ) )
V_4 &= ~ V_8 ;
F_2 ( V_4 , V_1 ) ;
F_4 () ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
int V_13 = F_9 ( V_10 ) ;
V_12 -> V_14 = 0 ;
return V_13 ;
}
static int F_10 ( struct V_15 * V_16 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_17 * V_18 ;
int V_13 ;
if ( F_11 () )
return - V_19 ;
#if F_12 ( V_20 ) && F_12 ( V_21 )
if ( ! ( F_13 () & 0xff ) ) {
F_14 ( V_22 L_1 , V_16 -> V_23 ) ;
F_14 ( V_22 L_2
L_3 , V_16 -> V_23 ) ;
return - V_19 ;
}
#endif
if ( V_16 -> V_17 [ 1 ] . V_24 != V_25 ) {
F_15 ( L_4 ) ;
return - V_26 ;
}
V_10 = F_16 ( & V_27 , & V_16 -> V_28 , L_5 ) ;
if ( ! V_10 )
return - V_26 ;
V_18 = F_17 ( V_16 , V_29 , 0 ) ;
V_10 -> V_30 = V_18 -> V_31 ;
V_10 -> V_32 = F_18 ( V_18 ) ;
if ( ! F_19 ( V_10 -> V_30 , V_10 -> V_32 , V_33 ) ) {
F_15 ( L_6 ) ;
V_13 = - V_34 ;
goto V_35;
}
V_10 -> V_36 = F_20 ( V_10 -> V_30 , V_10 -> V_32 ) ;
if ( ! V_10 -> V_36 ) {
F_15 ( L_7 ) ;
V_13 = - V_26 ;
goto V_37;
}
F_1 () ;
V_12 = F_8 ( V_10 ) ;
V_12 -> V_38 = V_10 -> V_36 ;
V_12 -> V_36 = V_10 -> V_36 +
F_21 ( V_12 , F_22 ( & V_12 -> V_38 -> V_39 ) ) ;
V_12 -> V_40 = F_22 ( & V_12 -> V_38 -> V_40 ) ;
V_13 = F_23 ( V_10 , V_16 -> V_17 [ 1 ] . V_31 ,
V_41 | V_42 ) ;
if ( V_13 == 0 ) {
F_24 ( V_16 , V_10 ) ;
return V_13 ;
}
F_6 () ;
F_25 ( V_10 -> V_36 ) ;
V_37:
F_26 ( V_10 -> V_30 , V_10 -> V_32 ) ;
V_35:
F_27 ( V_10 ) ;
return V_13 ;
}
static int F_28 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_29 ( V_16 ) ;
F_30 ( V_10 ) ;
F_25 ( V_10 -> V_36 ) ;
F_26 ( V_10 -> V_30 , V_10 -> V_32 ) ;
F_27 ( V_10 ) ;
F_6 () ;
F_24 ( V_16 , NULL ) ;
return 0 ;
}
static int F_31 ( struct V_43 * V_28 )
{
struct V_9 * V_10 = F_32 ( V_28 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
unsigned long V_24 ;
int V_44 = 0 ;
if ( F_33 ( V_45 , V_12 -> V_46 ) )
F_34 ( 10 ) ;
F_35 ( V_12 , F_36 ( V_28 ) ) ;
F_37 ( & V_12 -> V_47 , V_24 ) ;
F_38 ( V_12 , 0 , & V_12 -> V_36 -> V_48 ) ;
( void ) F_39 ( V_12 , & V_12 -> V_36 -> V_48 ) ;
F_40 ( V_49 , & V_10 -> V_24 ) ;
F_41 ( & V_12 -> V_47 , V_24 ) ;
F_6 () ;
return V_44 ;
}
static int F_42 ( struct V_43 * V_28 )
{
struct V_9 * V_10 = F_32 ( V_28 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
F_1 () ;
if ( F_33 ( V_45 , V_12 -> V_46 ) )
F_34 ( 100 ) ;
F_43 ( V_49 , & V_10 -> V_24 ) ;
if ( F_39 ( V_12 , & V_12 -> V_36 -> V_50 ) == V_51 ) {
int V_52 = V_53 ;
F_44 ( V_12 ) ;
if ( ! V_10 -> V_54 . V_55 -> V_56 )
V_52 &= ~ V_57 ;
F_38 ( V_12 , V_52 , & V_12 -> V_36 -> V_48 ) ;
F_39 ( V_12 , & V_12 -> V_36 -> V_48 ) ;
return 0 ;
}
F_45 ( V_12 , L_8 ) ;
F_46 ( V_10 -> V_54 . V_55 ) ;
( void ) F_47 ( V_12 ) ;
( void ) F_48 ( V_12 ) ;
F_49 ( & V_12 -> V_47 ) ;
if ( V_12 -> V_58 )
F_50 ( V_12 ) ;
F_51 ( V_12 ) ;
F_52 ( & V_12 -> V_47 ) ;
F_38 ( V_12 , V_12 -> V_59 , & V_12 -> V_36 -> V_59 ) ;
F_38 ( V_12 , V_51 , & V_12 -> V_36 -> V_50 ) ;
F_39 ( V_12 , & V_12 -> V_36 -> V_59 ) ;
F_53 ( V_12 , 1 ) ;
V_10 -> V_60 = V_61 ;
return 0 ;
}
