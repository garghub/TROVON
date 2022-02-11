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
int error = F_8 ( V_40 , V_38 , V_41 | V_42 , & V_36 ) ;
if ( ! error ) {
error = F_6 ( & V_36 , V_39 ) ;
F_9 ( & V_36 ) ;
}
return error ;
}
int F_10 ( int V_43 , struct V_27 * V_39 )
{
struct V_43 V_44 = F_11 ( V_43 ) ;
int error = - V_45 ;
if ( V_44 . V_46 ) {
error = F_6 ( & V_44 . V_46 -> V_47 , V_39 ) ;
F_12 ( V_44 ) ;
}
return error ;
}
static int F_13 ( struct V_27 * V_39 , struct V_32 T_1 * V_48 )
{
struct V_32 V_28 ;
if ( sizeof( V_28 ) == sizeof( * V_39 ) )
memcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;
else {
if ( sizeof V_28 . V_49 == 4 ) {
if ( ( V_39 -> V_49 | V_39 -> V_50 | V_39 -> V_51 |
V_39 -> V_35 | V_39 -> V_34 ) &
0xffffffff00000000ULL )
return - V_52 ;
if ( V_39 -> V_53 != - 1 &&
( V_39 -> V_53 & 0xffffffff00000000ULL ) )
return - V_52 ;
if ( V_39 -> V_54 != - 1 &&
( V_39 -> V_54 & 0xffffffff00000000ULL ) )
return - V_52 ;
}
V_28 . V_55 = V_39 -> V_55 ;
V_28 . V_35 = V_39 -> V_35 ;
V_28 . V_49 = V_39 -> V_49 ;
V_28 . V_50 = V_39 -> V_50 ;
V_28 . V_51 = V_39 -> V_51 ;
V_28 . V_53 = V_39 -> V_53 ;
V_28 . V_54 = V_39 -> V_54 ;
V_28 . V_56 = V_39 -> V_56 ;
V_28 . V_57 = V_39 -> V_57 ;
V_28 . V_34 = V_39 -> V_34 ;
V_28 . V_37 = V_39 -> V_37 ;
memset ( V_28 . V_58 , 0 , sizeof( V_28 . V_58 ) ) ;
}
if ( F_14 ( V_48 , & V_28 , sizeof( V_28 ) ) )
return - V_59 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_39 , struct V_60 T_1 * V_48 )
{
struct V_60 V_28 ;
if ( sizeof( V_28 ) == sizeof( * V_39 ) )
memcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;
else {
V_28 . V_55 = V_39 -> V_55 ;
V_28 . V_35 = V_39 -> V_35 ;
V_28 . V_49 = V_39 -> V_49 ;
V_28 . V_50 = V_39 -> V_50 ;
V_28 . V_51 = V_39 -> V_51 ;
V_28 . V_53 = V_39 -> V_53 ;
V_28 . V_54 = V_39 -> V_54 ;
V_28 . V_56 = V_39 -> V_56 ;
V_28 . V_57 = V_39 -> V_57 ;
V_28 . V_34 = V_39 -> V_34 ;
V_28 . V_37 = V_39 -> V_37 ;
memset ( V_28 . V_58 , 0 , sizeof( V_28 . V_58 ) ) ;
}
if ( F_14 ( V_48 , & V_28 , sizeof( V_28 ) ) )
return - V_59 ;
return 0 ;
}
int F_16 ( T_2 V_61 , struct V_27 * V_62 )
{
struct V_63 * V_64 = F_17 ( V_61 ) ;
int V_65 ;
if ( ! V_64 )
return - V_66 ;
V_65 = F_4 ( V_64 -> V_67 , V_62 ) ;
F_18 ( V_64 ) ;
return V_65 ;
}
