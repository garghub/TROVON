static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_7 = V_6 -> V_8 -> V_9 ;
unsigned long V_10 ;
if ( ! ( V_7 & V_11 ) )
return V_12 ;
if ( V_7 & V_13 ) {
F_3 ( V_4 -> V_14 , V_10 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_14 , V_10 ) ;
return V_15 ;
}
F_6 ( L_1 , V_7 ) ;
return V_12 ;
}
static int F_7 ( struct V_16 * V_17 , int V_18 )
{
struct V_3 * V_4 = V_17 -> V_19 -> V_20 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_21 * V_22 = & V_6 -> V_22 ;
struct V_23 * V_8 = V_6 -> V_8 ;
unsigned short V_24 = V_25 | V_26 ;
unsigned long V_27 = F_8 ( V_17 -> V_28 . V_29 ) ;
if ( V_27 & V_30 ) {
V_22 -> V_31 = ( V_17 -> V_28 . V_32 + 511 ) & ~ 0x1ff ;
V_22 -> V_33 = F_9 ( V_22 -> V_31 ,
V_34 ) ;
if ( ! V_22 -> V_33 ) {
V_22 -> V_31 = 0 ;
return 1 ;
}
if ( ! V_18 ) {
memcpy ( V_22 -> V_33 , V_17 -> V_28 . V_29 ,
V_17 -> V_28 . V_32 ) ;
}
V_27 = F_8 ( V_22 -> V_33 ) ;
}
if ( ! V_18 )
V_24 |= V_35 ;
V_22 -> V_36 = V_18 ;
V_8 -> V_37 = V_24 ;
V_8 -> V_38 = V_27 ;
if ( V_18 ) {
F_10 ( V_27 , V_17 -> V_28 . V_32 ) ;
} else {
F_11 ( V_27 , V_17 -> V_28 . V_32 ) ;
}
F_12 () ;
V_8 -> V_39 = 1 ;
F_12 () ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 , struct V_16 * V_40 ,
int V_7 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_21 * V_22 = & V_6 -> V_22 ;
struct V_23 * V_8 = V_6 -> V_8 ;
unsigned short V_24 = V_25 ;
if ( ! V_22 -> V_36 )
V_24 |= V_35 ;
V_8 -> V_37 = V_24 ;
F_12 () ;
if ( V_22 -> V_36 ) {
V_8 -> V_41 = 1 ;
F_12 () ;
while ( ! ( V_8 -> V_9 & V_42 ) )
F_14 () ;
F_12 () ;
}
V_8 -> V_43 = 1 ;
V_8 -> V_44 = 1 ;
F_12 () ;
V_8 -> V_37 = V_25 | V_26 ;
F_12 () ;
if ( V_7 && V_22 -> V_33 ) {
if ( V_40 ) {
if ( V_22 -> V_36 && V_40 )
memcpy ( V_40 -> V_28 . V_29 , V_22 -> V_33 ,
V_40 -> V_28 . V_32 ) ;
F_15 ( V_22 -> V_33 ) ;
V_22 -> V_33 = NULL ;
V_22 -> V_31 = 0 ;
} else {
F_15 ( V_22 -> V_33 ) ;
V_22 -> V_33 = NULL ;
V_22 -> V_31 = 0 ;
}
}
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = V_17 -> V_19 -> V_20 ;
F_17 ( V_4 -> V_14 ) ;
F_18 ( V_17 ) ;
F_19 ( V_4 -> V_14 ) ;
return V_45 ;
}
static int T_2 F_20 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_3 * V_4 ;
int error ;
struct V_23 * V_8 ;
T_3 V_50 ;
struct V_5 * V_6 ;
V_49 = F_21 ( V_47 , V_51 , 0 ) ;
if ( ! V_49 )
return - V_52 ;
if ( ! F_22 ( V_49 -> V_53 , F_23 ( V_49 ) , L_2 ) )
return - V_54 ;
V_4 = F_24 ( & V_55 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 ) {
error = - V_56 ;
goto V_57;
}
V_4 -> V_1 = V_58 ;
V_8 = (struct V_23 * ) F_25 ( V_49 -> V_53 ) ;
V_8 -> V_59 = V_60 ;
V_50 . V_61 = & V_8 -> V_61 ;
V_50 . V_62 = & V_8 -> V_62 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_22 . V_63 = 0xff ;
V_6 -> V_22 . V_64 = 0 ;
V_6 -> V_22 . V_65 = V_66 ;
V_6 -> V_8 = V_8 ;
F_26 ( V_4 , V_50 , F_7 , F_13 , V_67 ) ;
error = F_27 ( V_58 , F_1 , V_68 ,
L_3 , V_4 ) ;
if ( error )
goto V_69;
V_8 -> V_37 = V_25 | V_26 ;
error = F_28 ( V_4 , NULL ) ;
if ( error )
goto V_70;
F_29 ( V_47 , V_4 ) ;
F_30 ( V_4 ) ;
return 0 ;
V_70:
F_31 ( V_58 , V_4 ) ;
V_69:
F_32 ( V_4 ) ;
V_57:
F_33 ( V_49 -> V_53 , F_23 ( V_49 ) ) ;
return error ;
}
static int T_4 F_34 ( struct V_46 * V_47 )
{
struct V_3 * V_4 = F_35 ( V_47 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_48 * V_49 = F_21 ( V_47 , V_51 , 0 ) ;
V_6 -> V_8 -> V_37 = 0 ;
F_36 ( V_4 ) ;
F_31 ( V_58 , V_4 ) ;
F_32 ( V_4 ) ;
F_33 ( V_49 -> V_53 , F_23 ( V_49 ) ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_71 ,
F_20 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_71 ) ;
}
