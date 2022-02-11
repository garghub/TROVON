static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_7 = V_6 -> V_8 -> V_9 ;
unsigned long V_10 ;
if ( ! ( V_7 & ( V_11 | V_12 ) ) || ! ( V_7 & V_13 ) )
return V_14 ;
F_3 ( V_4 -> V_15 , V_10 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_15 , V_10 ) ;
return V_16 ;
}
static int F_6 ( struct V_17 * V_18 , int V_19 )
{
struct V_3 * V_4 = V_18 -> V_20 -> V_21 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_22 * V_23 = & V_6 -> V_23 ;
struct V_24 * V_8 = V_6 -> V_8 ;
unsigned short V_25 = V_26 | V_27 ;
unsigned long V_28 = F_7 ( V_18 -> V_29 . V_30 ) ;
if ( V_28 & V_31 ) {
V_23 -> V_32 = ( V_18 -> V_29 . V_33 + 511 ) & ~ 0x1ff ;
V_23 -> V_34 = F_8 ( V_23 -> V_32 ,
V_35 ) ;
if ( ! V_23 -> V_34 ) {
V_23 -> V_32 = 0 ;
return 1 ;
}
V_28 = F_7 ( V_23 -> V_34 ) ;
if ( V_28 & V_31 ) {
F_9 ( V_23 -> V_34 ) ;
V_23 -> V_34 = NULL ;
V_23 -> V_32 = 0 ;
return 1 ;
}
if ( ! V_19 ) {
memcpy ( V_23 -> V_34 , V_18 -> V_29 . V_30 ,
V_18 -> V_29 . V_33 ) ;
}
}
if ( ! V_19 )
V_25 |= V_36 ;
V_23 -> V_37 = V_19 ;
V_8 -> V_38 = V_25 ;
V_8 -> V_39 = V_28 ;
if ( V_19 ) {
F_10 ( V_28 , V_18 -> V_29 . V_33 ) ;
} else {
F_11 ( V_28 , V_18 -> V_29 . V_33 ) ;
}
V_8 -> V_40 = 1 ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 , struct V_17 * V_41 ,
int V_7 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_22 * V_23 = & V_6 -> V_23 ;
struct V_24 * V_8 = V_6 -> V_8 ;
unsigned short V_25 = V_26 ;
if ( ! V_23 -> V_37 )
V_25 |= V_36 ;
V_8 -> V_38 = V_25 ;
if ( V_23 -> V_37 ) {
V_8 -> V_42 = 1 ;
while ( ! ( V_8 -> V_9 & V_43 ) )
;
}
V_8 -> V_44 = 1 ;
V_8 -> V_45 = 1 ;
V_8 -> V_38 = V_26 | V_27 ;
if ( V_7 && V_23 -> V_34 ) {
if ( V_23 -> V_37 )
memcpy ( V_41 -> V_29 . V_30 , V_23 -> V_34 ,
V_41 -> V_29 . V_33 ) ;
F_9 ( V_23 -> V_34 ) ;
V_23 -> V_34 = NULL ;
V_23 -> V_32 = 0 ;
}
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_20 -> V_21 ;
F_14 ( V_4 -> V_15 ) ;
F_15 ( V_18 ) ;
F_16 ( V_4 -> V_15 ) ;
return V_46 ;
}
static int F_17 ( struct V_47 * V_48 , const struct V_49 * V_50 )
{
struct V_3 * V_4 ;
int error ;
struct V_24 * V_8 ;
T_2 V_51 ;
struct V_5 * V_6 ;
if ( ! F_18 ( V_48 -> V_52 . V_53 , 256 , L_1 ) )
return - V_54 ;
V_4 = F_19 ( & V_55 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 ) {
error = - V_56 ;
goto V_57;
}
V_4 -> V_1 = V_58 ;
V_4 -> V_59 = V_48 -> V_60 ;
V_8 = (struct V_24 * ) F_20 ( V_48 -> V_52 . V_53 ) ;
V_8 -> V_61 = V_62 ;
V_51 . V_63 = & V_8 -> V_63 ;
V_51 . V_64 = & V_8 -> V_64 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_23 . V_65 = 0xff ;
V_6 -> V_23 . V_66 = 0 ;
V_6 -> V_23 . V_67 = V_68 ;
V_6 -> V_8 = V_8 ;
F_21 ( V_4 , V_51 , F_6 , F_12 , V_69 ) ;
error = F_22 ( V_58 , F_1 , V_70 ,
L_2 , V_4 ) ;
if ( error )
goto V_71;
V_8 -> V_38 = V_26 | V_27 ;
error = F_23 ( V_4 , NULL ) ;
if ( error )
goto V_72;
F_24 ( V_48 , V_4 ) ;
F_25 ( V_4 ) ;
return 0 ;
V_72:
F_26 ( V_58 , V_4 ) ;
V_71:
F_27 ( V_4 ) ;
V_57:
F_28 ( V_48 -> V_52 . V_53 , 256 ) ;
return error ;
}
static void F_29 ( struct V_47 * V_48 )
{
struct V_3 * V_4 = F_30 ( V_48 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_8 -> V_38 = 0 ;
F_31 ( V_4 ) ;
F_26 ( V_58 , V_4 ) ;
F_27 ( V_4 ) ;
F_28 ( V_48 -> V_52 . V_53 , 256 ) ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_73 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_73 ) ;
}
