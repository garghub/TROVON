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
if ( V_17 & V_22 )
V_2 |= V_4 ;
return V_2 ;
}
static int F_3 ( struct V_23 * V_24 )
{
return V_25 | F_1 ( V_24 -> V_1 ) |
F_2 ( V_24 -> V_26 -> V_17 ) ;
}
static int F_4 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
int V_30 ;
if ( ! V_27 -> V_31 -> V_32 -> V_33 )
return - V_34 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_30 = F_5 ( V_27 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_27 -> V_31 -> V_32 -> V_33 ( V_27 , V_29 ) ;
if ( V_30 == 0 && V_29 -> V_35 == 0 )
V_29 -> V_35 = V_29 -> V_36 ;
return V_30 ;
}
int F_6 ( const struct V_37 * V_37 , struct V_28 * V_29 )
{
int error ;
error = F_4 ( V_37 -> V_27 , V_29 ) ;
if ( ! error )
V_29 -> V_38 = F_3 ( V_37 -> V_24 ) ;
return error ;
}
int F_7 ( const char T_1 * V_39 , struct V_28 * V_40 )
{
struct V_37 V_37 ;
int error ;
unsigned int V_41 = V_42 | V_43 ;
V_44:
error = F_8 ( V_45 , V_39 , V_41 , & V_37 ) ;
if ( ! error ) {
error = F_6 ( & V_37 , V_40 ) ;
F_9 ( & V_37 ) ;
if ( F_10 ( error , V_41 ) ) {
V_41 |= V_46 ;
goto V_44;
}
}
return error ;
}
int F_11 ( int V_47 , struct V_28 * V_40 )
{
struct V_47 V_48 = F_12 ( V_47 ) ;
int error = - V_49 ;
if ( V_48 . V_50 ) {
error = F_6 ( & V_48 . V_50 -> V_51 , V_40 ) ;
F_13 ( V_48 ) ;
}
return error ;
}
static int F_14 ( struct V_28 * V_40 , struct V_33 T_1 * V_52 )
{
struct V_33 V_29 ;
if ( sizeof( V_29 ) == sizeof( * V_40 ) )
memcpy ( & V_29 , V_40 , sizeof( * V_40 ) ) ;
else {
if ( sizeof V_29 . V_53 == 4 ) {
if ( ( V_40 -> V_53 | V_40 -> V_54 | V_40 -> V_55 |
V_40 -> V_36 | V_40 -> V_35 ) &
0xffffffff00000000ULL )
return - V_56 ;
if ( V_40 -> V_57 != - 1 &&
( V_40 -> V_57 & 0xffffffff00000000ULL ) )
return - V_56 ;
if ( V_40 -> V_58 != - 1 &&
( V_40 -> V_58 & 0xffffffff00000000ULL ) )
return - V_56 ;
}
V_29 . V_59 = V_40 -> V_59 ;
V_29 . V_36 = V_40 -> V_36 ;
V_29 . V_53 = V_40 -> V_53 ;
V_29 . V_54 = V_40 -> V_54 ;
V_29 . V_55 = V_40 -> V_55 ;
V_29 . V_57 = V_40 -> V_57 ;
V_29 . V_58 = V_40 -> V_58 ;
V_29 . V_60 = V_40 -> V_60 ;
V_29 . V_61 = V_40 -> V_61 ;
V_29 . V_35 = V_40 -> V_35 ;
V_29 . V_38 = V_40 -> V_38 ;
memset ( V_29 . V_62 , 0 , sizeof( V_29 . V_62 ) ) ;
}
if ( F_15 ( V_52 , & V_29 , sizeof( V_29 ) ) )
return - V_63 ;
return 0 ;
}
static int F_16 ( struct V_28 * V_40 , struct V_64 T_1 * V_52 )
{
struct V_64 V_29 ;
if ( sizeof( V_29 ) == sizeof( * V_40 ) )
memcpy ( & V_29 , V_40 , sizeof( * V_40 ) ) ;
else {
V_29 . V_59 = V_40 -> V_59 ;
V_29 . V_36 = V_40 -> V_36 ;
V_29 . V_53 = V_40 -> V_53 ;
V_29 . V_54 = V_40 -> V_54 ;
V_29 . V_55 = V_40 -> V_55 ;
V_29 . V_57 = V_40 -> V_57 ;
V_29 . V_58 = V_40 -> V_58 ;
V_29 . V_60 = V_40 -> V_60 ;
V_29 . V_61 = V_40 -> V_61 ;
V_29 . V_35 = V_40 -> V_35 ;
V_29 . V_38 = V_40 -> V_38 ;
memset ( V_29 . V_62 , 0 , sizeof( V_29 . V_62 ) ) ;
}
if ( F_15 ( V_52 , & V_29 , sizeof( V_29 ) ) )
return - V_63 ;
return 0 ;
}
int F_17 ( T_2 V_65 , struct V_28 * V_66 )
{
struct V_67 * V_68 = F_18 ( V_65 ) ;
int V_69 ;
if ( ! V_68 )
return - V_70 ;
V_69 = F_4 ( V_68 -> V_71 , V_66 ) ;
F_19 ( V_68 ) ;
return V_69 ;
}
static int F_20 ( struct V_72 T_1 * V_73 , struct V_28 * V_74 )
{
struct V_72 V_29 ;
if ( sizeof V_73 -> V_53 == 4 ) {
if ( ( V_74 -> V_53 | V_74 -> V_54 | V_74 -> V_55 |
V_74 -> V_36 | V_74 -> V_35 ) & 0xffffffff00000000ULL )
return - V_56 ;
if ( V_74 -> V_57 != 0xffffffffffffffffULL
&& ( V_74 -> V_57 & 0xffffffff00000000ULL ) )
return - V_56 ;
if ( V_74 -> V_58 != 0xffffffffffffffffULL
&& ( V_74 -> V_58 & 0xffffffff00000000ULL ) )
return - V_56 ;
}
memset ( & V_29 , 0 , sizeof( struct V_72 ) ) ;
V_29 . V_59 = V_74 -> V_59 ;
V_29 . V_36 = V_74 -> V_36 ;
V_29 . V_53 = V_74 -> V_53 ;
V_29 . V_54 = V_74 -> V_54 ;
V_29 . V_55 = V_74 -> V_55 ;
V_29 . V_57 = V_74 -> V_57 ;
V_29 . V_58 = V_74 -> V_58 ;
V_29 . V_61 = V_74 -> V_61 ;
V_29 . V_60 . V_75 [ 0 ] = V_74 -> V_60 . V_75 [ 0 ] ;
V_29 . V_60 . V_75 [ 1 ] = V_74 -> V_60 . V_75 [ 1 ] ;
V_29 . V_35 = V_74 -> V_35 ;
V_29 . V_38 = V_74 -> V_38 ;
if ( F_15 ( V_73 , & V_29 , sizeof( struct V_72 ) ) )
return - V_63 ;
return 0 ;
}
static int F_21 ( struct V_76 T_1 * V_73 , struct V_28 * V_74 )
{
struct V_76 V_29 ;
if ( sizeof( V_73 -> V_36 ) == 4 ) {
if ( ( V_74 -> V_59 | V_74 -> V_36 | V_74 -> V_61 |
V_74 -> V_35 | V_74 -> V_38 ) & 0xffffffff00000000ULL )
return - V_56 ;
if ( V_74 -> V_57 != 0xffffffffffffffffULL
&& ( V_74 -> V_57 & 0xffffffff00000000ULL ) )
return - V_56 ;
if ( V_74 -> V_58 != 0xffffffffffffffffULL
&& ( V_74 -> V_58 & 0xffffffff00000000ULL ) )
return - V_56 ;
}
memset ( & V_29 , 0 , sizeof( struct V_76 ) ) ;
V_29 . V_59 = V_74 -> V_59 ;
V_29 . V_36 = V_74 -> V_36 ;
V_29 . V_53 = V_74 -> V_53 ;
V_29 . V_54 = V_74 -> V_54 ;
V_29 . V_55 = V_74 -> V_55 ;
V_29 . V_57 = V_74 -> V_57 ;
V_29 . V_58 = V_74 -> V_58 ;
V_29 . V_61 = V_74 -> V_61 ;
V_29 . V_60 . V_75 [ 0 ] = V_74 -> V_60 . V_75 [ 0 ] ;
V_29 . V_60 . V_75 [ 1 ] = V_74 -> V_60 . V_75 [ 1 ] ;
V_29 . V_35 = V_74 -> V_35 ;
V_29 . V_38 = V_74 -> V_38 ;
if ( F_15 ( V_73 , & V_29 , sizeof( struct V_76 ) ) )
return - V_63 ;
return 0 ;
}
