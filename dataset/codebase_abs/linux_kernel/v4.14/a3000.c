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
static int T_2 F_16 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_3 * V_4 ;
int error ;
struct V_23 * V_8 ;
T_3 V_49 ;
struct V_5 * V_6 ;
V_48 = F_17 ( V_46 , V_50 , 0 ) ;
if ( ! V_48 )
return - V_51 ;
if ( ! F_18 ( V_48 -> V_52 , F_19 ( V_48 ) , L_2 ) )
return - V_53 ;
V_4 = F_20 ( & V_54 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 ) {
error = - V_55 ;
goto V_56;
}
V_4 -> V_1 = V_57 ;
V_8 = F_21 ( V_48 -> V_52 ) ;
V_8 -> V_58 = V_59 ;
V_49 . V_60 = & V_8 -> V_60 ;
V_49 . V_61 = & V_8 -> V_61 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_22 . V_62 = 0xff ;
V_6 -> V_22 . V_63 = 0 ;
V_6 -> V_22 . V_64 = V_65 ;
V_6 -> V_8 = V_8 ;
F_22 ( V_4 , V_49 , F_7 , F_13 , V_66 ) ;
error = F_23 ( V_57 , F_1 , V_67 ,
L_3 , V_4 ) ;
if ( error )
goto V_68;
V_8 -> V_37 = V_25 | V_26 ;
error = F_24 ( V_4 , NULL ) ;
if ( error )
goto V_69;
F_25 ( V_46 , V_4 ) ;
F_26 ( V_4 ) ;
return 0 ;
V_69:
F_27 ( V_57 , V_4 ) ;
V_68:
F_28 ( V_4 ) ;
V_56:
F_29 ( V_48 -> V_52 , F_19 ( V_48 ) ) ;
return error ;
}
static int T_4 F_30 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = F_31 ( V_46 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_47 * V_48 = F_17 ( V_46 , V_50 , 0 ) ;
V_6 -> V_8 -> V_37 = 0 ;
F_32 ( V_4 ) ;
F_27 ( V_57 , V_4 ) ;
F_28 ( V_4 ) ;
F_29 ( V_48 -> V_52 , F_19 ( V_48 ) ) ;
return 0 ;
}
