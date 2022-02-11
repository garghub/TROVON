static int F_1 ( int V_1 )
{
int V_2 = 0 ;
if ( V_1 & V_3 )
V_2 |= V_4 ;
if ( V_1 & V_5 )
V_2 |= V_6 ;
if ( V_1 & V_7 )
V_2 |= V_8 ;
if ( V_1 & V_9 )
V_2 |= V_10 ;
if ( V_1 & V_11 )
V_2 |= V_12 ;
if ( V_1 & V_13 )
V_2 |= V_14 ;
if ( V_1 & V_15 )
V_2 |= V_16 ;
return V_2 ;
}
static int F_2 ( int V_17 )
{
int V_2 = 0 ;
if ( V_17 & V_18 )
V_2 |= V_19 ;
if ( V_17 & V_20 )
V_2 |= V_21 ;
return V_2 ;
}
static int F_3 ( struct V_22 * V_23 )
{
return V_24 | F_1 ( V_23 -> V_1 ) |
F_2 ( V_23 -> V_25 -> V_17 ) ;
}
static int F_4 ( struct V_26 * V_26 , struct V_27 * V_28 )
{
int V_29 ;
if ( ! V_26 -> V_30 -> V_31 -> V_32 )
return - V_33 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_29 = F_5 ( V_26 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_26 -> V_30 -> V_31 -> V_32 ( V_26 , V_28 ) ;
if ( V_29 == 0 && V_28 -> V_34 == 0 )
V_28 -> V_34 = V_28 -> V_35 ;
return V_29 ;
}
int F_6 ( struct V_36 * V_36 , struct V_27 * V_28 )
{
int error ;
error = F_4 ( V_36 -> V_26 , V_28 ) ;
if ( ! error )
V_28 -> V_37 = F_3 ( V_36 -> V_23 ) ;
return error ;
}
int F_7 ( const char T_1 * V_38 , struct V_27 * V_39 )
{
struct V_36 V_36 ;
int error ;
unsigned int V_40 = V_41 | V_42 ;
V_43:
error = F_8 ( V_44 , V_38 , V_40 , & V_36 ) ;
if ( ! error ) {
error = F_6 ( & V_36 , V_39 ) ;
F_9 ( & V_36 ) ;
if ( F_10 ( error , V_40 ) ) {
V_40 |= V_45 ;
goto V_43;
}
}
return error ;
}
int F_11 ( int V_46 , struct V_27 * V_39 )
{
struct V_46 V_47 = F_12 ( V_46 ) ;
int error = - V_48 ;
if ( V_47 . V_49 ) {
error = F_6 ( & V_47 . V_49 -> V_50 , V_39 ) ;
F_13 ( V_47 ) ;
}
return error ;
}
static int F_14 ( struct V_27 * V_39 , struct V_32 T_1 * V_51 )
{
struct V_32 V_28 ;
if ( sizeof( V_28 ) == sizeof( * V_39 ) )
memcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;
else {
if ( sizeof V_28 . V_52 == 4 ) {
if ( ( V_39 -> V_52 | V_39 -> V_53 | V_39 -> V_54 |
V_39 -> V_35 | V_39 -> V_34 ) &
0xffffffff00000000ULL )
return - V_55 ;
if ( V_39 -> V_56 != - 1 &&
( V_39 -> V_56 & 0xffffffff00000000ULL ) )
return - V_55 ;
if ( V_39 -> V_57 != - 1 &&
( V_39 -> V_57 & 0xffffffff00000000ULL ) )
return - V_55 ;
}
V_28 . V_58 = V_39 -> V_58 ;
V_28 . V_35 = V_39 -> V_35 ;
V_28 . V_52 = V_39 -> V_52 ;
V_28 . V_53 = V_39 -> V_53 ;
V_28 . V_54 = V_39 -> V_54 ;
V_28 . V_56 = V_39 -> V_56 ;
V_28 . V_57 = V_39 -> V_57 ;
V_28 . V_59 = V_39 -> V_59 ;
V_28 . V_60 = V_39 -> V_60 ;
V_28 . V_34 = V_39 -> V_34 ;
V_28 . V_37 = V_39 -> V_37 ;
memset ( V_28 . V_61 , 0 , sizeof( V_28 . V_61 ) ) ;
}
if ( F_15 ( V_51 , & V_28 , sizeof( V_28 ) ) )
return - V_62 ;
return 0 ;
}
static int F_16 ( struct V_27 * V_39 , struct V_63 T_1 * V_51 )
{
struct V_63 V_28 ;
if ( sizeof( V_28 ) == sizeof( * V_39 ) )
memcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;
else {
V_28 . V_58 = V_39 -> V_58 ;
V_28 . V_35 = V_39 -> V_35 ;
V_28 . V_52 = V_39 -> V_52 ;
V_28 . V_53 = V_39 -> V_53 ;
V_28 . V_54 = V_39 -> V_54 ;
V_28 . V_56 = V_39 -> V_56 ;
V_28 . V_57 = V_39 -> V_57 ;
V_28 . V_59 = V_39 -> V_59 ;
V_28 . V_60 = V_39 -> V_60 ;
V_28 . V_34 = V_39 -> V_34 ;
V_28 . V_37 = V_39 -> V_37 ;
memset ( V_28 . V_61 , 0 , sizeof( V_28 . V_61 ) ) ;
}
if ( F_15 ( V_51 , & V_28 , sizeof( V_28 ) ) )
return - V_62 ;
return 0 ;
}
int F_17 ( T_2 V_64 , struct V_27 * V_65 )
{
struct V_66 * V_67 = F_18 ( V_64 ) ;
int V_68 ;
if ( ! V_67 )
return - V_69 ;
V_68 = F_4 ( V_67 -> V_70 , V_65 ) ;
F_19 ( V_67 ) ;
return V_68 ;
}
