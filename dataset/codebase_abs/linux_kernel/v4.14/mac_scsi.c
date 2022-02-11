static int T_1 F_1 ( char * V_1 )
{
int V_2 [ 8 ] ;
( void ) F_2 ( V_1 , F_3 ( V_2 ) , V_2 ) ;
if ( V_2 [ 0 ] < 1 ) {
F_4 ( L_1 ) ;
return 0 ;
}
if ( V_2 [ 0 ] >= 1 )
V_3 = V_2 [ 1 ] ;
if ( V_2 [ 0 ] >= 2 )
V_4 = V_2 [ 2 ] ;
if ( V_2 [ 0 ] >= 3 )
V_5 = V_2 [ 3 ] ;
if ( V_2 [ 0 ] >= 4 )
V_6 = V_2 [ 4 ] ;
if ( V_2 [ 0 ] >= 6 )
V_7 = V_2 [ 6 ] ;
if ( V_2 [ 0 ] >= 7 )
V_8 = V_2 [ 7 ] ;
return 1 ;
}
static inline int F_5 ( struct V_9 * V_10 ,
unsigned char * V_11 , int V_12 )
{
T_2 T_3 * V_13 = V_10 -> V_14 + ( V_15 << 4 ) ;
unsigned char * V_16 = V_11 ;
int V_17 = V_12 ;
int V_18 ;
while ( ! F_6 ( V_10 , V_19 ,
V_20 | V_21 ,
V_20 | V_21 , V_22 / 64 ) ) {
F_7 ( V_13 , V_16 , V_17 ) ;
V_18 = V_16 - V_11 - V_17 ;
V_10 -> V_23 = V_12 - V_18 ;
if ( V_17 == 0 )
return 0 ;
if ( F_8 ( V_10 , V_24 , V_25 , V_25 ,
V_19 , V_26 , V_26 , V_22 / 64 ) < 0 )
F_9 ( V_27 , V_10 -> V_28 ,
L_2 , V_29 ) ;
if ( ! ( F_10 ( V_19 ) & V_21 ) )
return 0 ;
F_11 ( V_30 , V_10 -> V_31 ,
L_3 , V_29 , V_18 , V_12 ) ;
F_12 ( V_30 , V_10 -> V_31 ) ;
V_16 = V_11 + V_18 ;
V_17 = V_12 - V_18 ;
}
F_9 ( V_27 , V_10 -> V_28 ,
L_4 , V_29 ) ;
F_12 ( V_30 , V_10 -> V_31 ) ;
return - 1 ;
}
static inline int F_13 ( struct V_9 * V_10 ,
unsigned char * V_32 , int V_12 )
{
unsigned char * V_13 = V_32 ;
T_2 T_3 * V_16 = V_10 -> V_14 + ( V_33 << 4 ) ;
int V_17 = V_12 ;
int V_18 ;
while ( ! F_6 ( V_10 , V_19 ,
V_20 | V_21 ,
V_20 | V_21 , V_22 / 64 ) ) {
F_14 ( V_13 , V_16 , V_17 ) ;
V_18 = V_13 - V_32 - V_17 ;
V_10 -> V_23 = V_12 - V_18 ;
if ( F_8 ( V_10 , V_24 , V_25 , V_25 ,
V_19 , V_26 , V_26 , V_22 / 64 ) < 0 )
F_9 ( V_27 , V_10 -> V_28 ,
L_2 , V_29 ) ;
if ( ! ( F_10 ( V_19 ) & V_21 ) )
return 0 ;
if ( V_17 == 0 ) {
if ( F_6 ( V_10 , V_34 ,
V_35 ,
V_35 , V_22 / 64 ) < 0 )
F_9 ( V_27 , V_10 -> V_28 ,
L_5 , V_29 ) ;
return 0 ;
}
F_11 ( V_30 , V_10 -> V_31 ,
L_3 , V_29 , V_18 , V_12 ) ;
F_12 ( V_30 , V_10 -> V_31 ) ;
V_13 = V_32 + V_18 ;
V_17 = V_12 - V_18 ;
}
F_9 ( V_27 , V_10 -> V_28 ,
L_4 , V_29 ) ;
F_12 ( V_30 , V_10 -> V_31 ) ;
return - 1 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_36 * V_37 )
{
if ( V_10 -> V_38 & V_39 ||
V_37 -> V_40 . V_41 < 16 )
return 0 ;
return V_37 -> V_40 . V_41 ;
}
static int F_16 ( struct V_9 * V_10 )
{
return V_10 -> V_23 ;
}
static int T_1 F_17 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
struct V_9 * V_10 ;
int error ;
int V_46 = 0 ;
struct V_47 * V_48 , * V_49 , * V_50 = NULL ;
V_49 = F_18 ( V_43 , V_51 , 0 ) ;
if ( ! V_49 )
return - V_52 ;
V_50 = F_18 ( V_43 , V_51 , 1 ) ;
V_48 = F_18 ( V_43 , V_53 , 0 ) ;
if ( ! F_19 ( ( unsigned char * ) V_49 -> V_54 +
( V_24 << 4 ) ) ) {
F_20 ( V_55 L_6 , & V_49 -> V_54 ) ;
return - V_52 ;
}
if ( V_3 > 0 )
V_56 . V_57 = V_3 ;
if ( V_4 > 0 )
V_56 . V_58 = V_4 ;
if ( V_5 >= 0 )
V_56 . V_59 = V_5 ;
if ( V_6 >= 0 )
V_56 . V_60 = V_6 & 7 ;
V_45 = F_21 ( & V_56 ,
sizeof( struct V_9 ) ) ;
if ( ! V_45 )
return - V_61 ;
if ( V_48 )
V_45 -> V_48 = V_48 -> V_54 ;
else
V_45 -> V_48 = V_62 ;
V_10 = F_22 ( V_45 ) ;
V_10 -> V_63 = V_49 -> V_54 ;
V_10 -> V_64 = ( T_2 T_3 * ) V_49 -> V_54 ;
if ( V_50 && V_7 )
V_10 -> V_14 = ( T_2 T_3 * ) V_50 -> V_54 ;
else
V_46 |= V_39 ;
V_46 |= V_8 > 0 ? V_65 : 0 ;
error = F_23 ( V_45 , V_46 | V_66 ) ;
if ( error )
goto V_67;
if ( V_45 -> V_48 != V_62 ) {
error = F_24 ( V_45 -> V_48 , V_68 , V_69 ,
L_7 , V_45 ) ;
if ( error )
goto V_70;
}
F_25 ( V_45 ) ;
error = F_26 ( V_45 , NULL ) ;
if ( error )
goto V_71;
F_27 ( V_43 , V_45 ) ;
F_28 ( V_45 ) ;
return 0 ;
V_71:
if ( V_45 -> V_48 != V_62 )
F_29 ( V_45 -> V_48 , V_45 ) ;
V_70:
F_30 ( V_45 ) ;
V_67:
F_31 ( V_45 ) ;
return error ;
}
static int T_4 F_32 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_33 ( V_43 ) ;
F_34 ( V_45 ) ;
if ( V_45 -> V_48 != V_62 )
F_29 ( V_45 -> V_48 , V_45 ) ;
F_30 ( V_45 ) ;
F_31 ( V_45 ) ;
return 0 ;
}
