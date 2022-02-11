static void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 ) ;
}
static T_1 F_3 ( T_1 V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_3 * V_4 ,
enum V_5 V_6 )
{
union V_7 V_8 ;
if ( V_6 == V_4 -> V_9 )
return;
V_8 . T_1 = F_3 ( V_4 -> V_10 + V_11 ) ;
V_8 . V_12 . V_9 = ( V_6 == V_13 ) ? 1 : 0 ;
V_8 . V_12 . V_14 = 1 ;
F_1 ( V_8 . T_1 , V_4 -> V_10 + V_11 ) ;
V_4 -> V_9 = V_6 ;
}
static int F_6 ( struct V_3 * V_4 ,
int V_15 , int V_16 )
{
union V_17 V_18 ;
union V_19 V_20 ;
int V_21 = 1000 ;
F_5 ( V_4 , V_13 ) ;
V_20 . T_1 = 0 ;
V_20 . V_12 . V_22 = V_16 & 0xffff ;
F_1 ( V_20 . T_1 , V_4 -> V_10 + V_23 ) ;
V_16 = ( V_16 >> 16 ) & 0x1f ;
V_18 . T_1 = 0 ;
V_18 . V_12 . V_24 = 0 ;
V_18 . V_12 . V_25 = V_15 ;
V_18 . V_12 . V_26 = V_16 ;
F_1 ( V_18 . T_1 , V_4 -> V_10 + V_27 ) ;
do {
F_7 ( 1000 ) ;
V_20 . T_1 = F_3 ( V_4 -> V_10 + V_23 ) ;
} while ( V_20 . V_12 . V_28 && -- V_21 );
if ( V_21 <= 0 )
return - V_29 ;
return 0 ;
}
static int F_8 ( struct V_30 * V_31 , int V_15 , int V_16 )
{
struct V_3 * V_4 = V_31 -> V_32 ;
union V_17 V_18 ;
union V_33 V_34 ;
unsigned int V_35 = 1 ;
int V_21 = 1000 ;
if ( V_16 & V_36 ) {
int V_37 = F_6 ( V_4 , V_15 , V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
V_16 = ( V_16 >> 16 ) & 0x1f ;
V_35 = 3 ;
} else {
F_5 ( V_4 , V_38 ) ;
}
V_18 . T_1 = 0 ;
V_18 . V_12 . V_24 = V_35 ;
V_18 . V_12 . V_25 = V_15 ;
V_18 . V_12 . V_26 = V_16 ;
F_1 ( V_18 . T_1 , V_4 -> V_10 + V_27 ) ;
do {
F_7 ( 1000 ) ;
V_34 . T_1 = F_3 ( V_4 -> V_10 + V_39 ) ;
} while ( V_34 . V_12 . V_28 && -- V_21 );
if ( V_34 . V_12 . V_1 )
return V_34 . V_12 . V_22 ;
else
return - V_29 ;
}
static int F_9 ( struct V_30 * V_31 , int V_15 ,
int V_16 , T_2 V_1 )
{
struct V_3 * V_4 = V_31 -> V_32 ;
union V_17 V_18 ;
union V_19 V_20 ;
unsigned int V_35 = 0 ;
int V_21 = 1000 ;
if ( V_16 & V_36 ) {
int V_37 = F_6 ( V_4 , V_15 , V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
V_16 = ( V_16 >> 16 ) & 0x1f ;
V_35 = 1 ;
} else {
F_5 ( V_4 , V_38 ) ;
}
V_20 . T_1 = 0 ;
V_20 . V_12 . V_22 = V_1 ;
F_1 ( V_20 . T_1 , V_4 -> V_10 + V_23 ) ;
V_18 . T_1 = 0 ;
V_18 . V_12 . V_24 = V_35 ;
V_18 . V_12 . V_25 = V_15 ;
V_18 . V_12 . V_26 = V_16 ;
F_1 ( V_18 . T_1 , V_4 -> V_10 + V_27 ) ;
do {
F_7 ( 1000 ) ;
V_20 . T_1 = F_3 ( V_4 -> V_10 + V_23 ) ;
} while ( V_20 . V_12 . V_28 && -- V_21 );
if ( V_21 <= 0 )
return - V_29 ;
return 0 ;
}
static int F_10 ( struct V_40 * V_41 )
{
struct V_3 * V_31 ;
struct V_30 * V_30 ;
struct V_42 * V_43 ;
union V_44 V_45 ;
int V_46 = - V_47 ;
V_30 = F_11 ( & V_41 -> V_48 , sizeof( * V_31 ) ) ;
if ( ! V_30 )
return - V_49 ;
V_43 = F_12 ( V_41 , V_50 , 0 ) ;
if ( V_43 == NULL ) {
F_13 ( & V_41 -> V_48 , L_1 ) ;
return - V_51 ;
}
V_31 = V_30 -> V_32 ;
V_31 -> V_30 = V_30 ;
V_31 -> V_52 = V_43 -> V_53 ;
V_31 -> V_54 = F_14 ( V_43 ) ;
if ( ! F_15 ( & V_41 -> V_48 , V_31 -> V_52 , V_31 -> V_54 ,
V_43 -> V_55 ) ) {
F_13 ( & V_41 -> V_48 , L_2 ) ;
return - V_51 ;
}
V_31 -> V_10 =
( T_1 ) F_16 ( & V_41 -> V_48 , V_31 -> V_52 , V_31 -> V_54 ) ;
if ( ! V_31 -> V_10 ) {
F_13 ( & V_41 -> V_48 , L_3 ) ;
return - V_49 ;
}
V_45 . T_1 = 0 ;
V_45 . V_12 . V_56 = 1 ;
F_1 ( V_45 . T_1 , V_31 -> V_10 + V_57 ) ;
V_31 -> V_30 -> V_32 = V_31 ;
V_31 -> V_30 -> V_55 = L_4 ;
snprintf ( V_31 -> V_30 -> V_58 , V_59 , L_5 , V_31 -> V_10 ) ;
V_31 -> V_30 -> V_60 = & V_41 -> V_48 ;
V_31 -> V_30 -> V_61 = F_8 ;
V_31 -> V_30 -> V_62 = F_9 ;
F_17 ( V_41 , V_31 ) ;
V_46 = F_18 ( V_31 -> V_30 , V_41 -> V_48 . V_63 ) ;
if ( V_46 )
goto V_64;
F_19 ( & V_41 -> V_48 , L_6 V_65 L_7 ) ;
return 0 ;
V_64:
F_20 ( V_31 -> V_30 ) ;
V_45 . T_1 = 0 ;
F_1 ( V_45 . T_1 , V_31 -> V_10 + V_57 ) ;
return V_46 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_3 * V_31 ;
union V_44 V_45 ;
V_31 = F_22 ( V_41 ) ;
F_23 ( V_31 -> V_30 ) ;
F_20 ( V_31 -> V_30 ) ;
V_45 . T_1 = 0 ;
F_1 ( V_45 . T_1 , V_31 -> V_10 + V_57 ) ;
return 0 ;
}
void F_24 ( void )
{
}
