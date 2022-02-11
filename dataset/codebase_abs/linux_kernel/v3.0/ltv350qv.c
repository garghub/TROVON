static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 = {
. V_9 = 3 ,
. V_10 = 1 ,
} ;
struct V_7 V_11 = {
. V_9 = 3 ,
} ;
F_2 ( & V_6 ) ;
V_2 -> V_12 [ 0 ] = V_13 ;
V_2 -> V_12 [ 1 ] = 0x00 ;
V_2 -> V_12 [ 2 ] = V_3 & 0x7f ;
V_8 . V_14 = V_2 -> V_12 ;
F_3 ( & V_8 , & V_6 ) ;
V_2 -> V_12 [ 4 ] = V_15 ;
V_2 -> V_12 [ 5 ] = V_4 >> 8 ;
V_2 -> V_12 [ 6 ] = V_4 ;
V_11 . V_14 = V_2 -> V_12 + 4 ;
F_3 ( & V_11 , & V_6 ) ;
return F_4 ( V_2 -> V_16 , & V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_17 ;
if ( F_1 ( V_2 , V_18 , 0x0000 ) )
goto V_19;
F_6 ( 15 ) ;
if ( F_1 ( V_2 , V_18 , V_20 ) )
goto V_19;
if ( F_1 ( V_2 , V_21 , V_22 ) )
goto V_23;
if ( F_1 ( V_2 , V_18 ,
V_20 | F_7 ( 5 )
| F_8 ( 5 ) ) )
goto V_24;
F_6 ( 55 ) ;
V_17 = F_1 ( V_2 , V_25 ,
V_26 | V_27 | F_9 ( 0x1d ) ) ;
V_17 |= F_1 ( V_2 , V_28 ,
V_29 | V_30
| V_31 | V_32 ) ;
V_17 |= F_1 ( V_2 , V_33 ,
V_34
| V_35
| V_36
| V_37
| V_38 ) ;
V_17 |= F_1 ( V_2 , V_39 , F_10 ( 3 ) ) ;
V_17 |= F_1 ( V_2 , V_40 ,
V_41 | F_11 ( 3 ) ) ;
V_17 |= F_1 ( V_2 , V_42 , 0x000a ) ;
V_17 |= F_1 ( V_2 , V_43 , 0x0021 ) ;
V_17 |= F_1 ( V_2 , V_44 , F_12 ( 3 ) | F_13 ( 0 ) ) ;
V_17 |= F_1 ( V_2 , F_14 ( 0 ) , 0x0103 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 1 ) , 0x0301 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 2 ) , 0x1f0f ) ;
V_17 |= F_1 ( V_2 , F_14 ( 3 ) , 0x1f0f ) ;
V_17 |= F_1 ( V_2 , F_14 ( 4 ) , 0x0707 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 5 ) , 0x0307 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 6 ) , 0x0707 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 7 ) , 0x0000 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 8 ) , 0x0004 ) ;
V_17 |= F_1 ( V_2 , F_14 ( 9 ) , 0x0000 ) ;
if ( V_17 )
goto V_45;
F_6 ( 20 ) ;
V_17 = F_1 ( V_2 , V_18 ,
V_20 | V_46
| V_47 | F_7 ( 5 )
| F_8 ( 5 ) ) ;
V_17 |= F_1 ( V_2 , V_40 ,
V_41 | V_48 | F_11 ( 3 ) ) ;
if ( V_17 )
goto V_49;
return 0 ;
V_49:
F_1 ( V_2 , V_18 ,
V_20 | F_7 ( 5 )
| F_8 ( 5 ) ) ;
F_1 ( V_2 , V_40 ,
V_41 | F_11 ( 3 ) ) ;
V_45:
V_24:
V_23:
F_1 ( V_2 , V_21 , 0x0000 ) ;
F_6 ( 1 ) ;
V_19:
F_1 ( V_2 , V_18 , V_20 ) ;
return - V_50 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_1 ( V_2 , V_18 ,
V_20
| F_7 ( 5 )
| F_8 ( 5 ) ) ;
V_17 |= F_1 ( V_2 , V_40 ,
V_41 | F_11 ( 3 ) ) ;
V_17 |= F_1 ( V_2 , V_21 , 0x0000 ) ;
F_6 ( 1 ) ;
V_17 |= F_1 ( V_2 , V_18 , V_20 ) ;
if ( V_17 )
return - V_50 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_51 )
{
int V_17 = 0 ;
if ( F_17 ( V_51 ) && ! F_17 ( V_2 -> V_51 ) )
V_17 = F_5 ( V_2 ) ;
else if ( ! F_17 ( V_51 ) && F_17 ( V_2 -> V_51 ) )
V_17 = F_15 ( V_2 ) ;
if ( ! V_17 )
V_2 -> V_51 = V_51 ;
return V_17 ;
}
static int F_18 ( struct V_52 * V_53 , int V_51 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
return F_16 ( V_2 , V_51 ) ;
}
static int F_20 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_19 ( V_53 ) ;
return V_2 -> V_51 ;
}
static int T_3 F_21 ( struct V_54 * V_16 )
{
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_17 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_51 = V_57 ;
V_2 -> V_12 = F_22 ( 8 , V_55 ) ;
if ( ! V_2 -> V_12 ) {
V_17 = - V_56 ;
goto V_58;
}
V_53 = F_23 ( L_1 , & V_16 -> V_59 , V_2 , & V_60 ) ;
if ( F_24 ( V_53 ) ) {
V_17 = F_25 ( V_53 ) ;
goto V_61;
}
V_2 -> V_53 = V_53 ;
V_17 = F_16 ( V_2 , V_62 ) ;
if ( V_17 )
goto V_63;
F_26 ( & V_16 -> V_59 , V_2 ) ;
return 0 ;
V_63:
F_27 ( V_53 ) ;
V_61:
F_28 ( V_2 -> V_12 ) ;
V_58:
F_28 ( V_2 ) ;
return V_17 ;
}
static int T_4 F_29 ( struct V_54 * V_16 )
{
struct V_1 * V_2 = F_30 ( & V_16 -> V_59 ) ;
F_16 ( V_2 , V_57 ) ;
F_27 ( V_2 -> V_53 ) ;
F_28 ( V_2 -> V_12 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_16 , T_5 V_64 )
{
struct V_1 * V_2 = F_30 ( & V_16 -> V_59 ) ;
return F_16 ( V_2 , V_57 ) ;
}
static int F_32 ( struct V_54 * V_16 )
{
struct V_1 * V_2 = F_30 ( & V_16 -> V_59 ) ;
return F_16 ( V_2 , V_62 ) ;
}
static void F_33 ( struct V_54 * V_16 )
{
struct V_1 * V_2 = F_30 ( & V_16 -> V_59 ) ;
F_16 ( V_2 , V_57 ) ;
}
static int T_6 F_34 ( void )
{
return F_35 ( & V_65 ) ;
}
static void T_7 F_36 ( void )
{
F_37 ( & V_65 ) ;
}
