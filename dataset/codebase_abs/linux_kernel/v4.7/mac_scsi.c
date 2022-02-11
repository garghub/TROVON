static inline char F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 4 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_5 )
{
F_4 ( V_2 -> V_4 + ( V_3 << 4 ) , V_5 ) ;
}
static int T_1 F_5 ( char * V_6 )
{
int V_7 [ 8 ] ;
( void ) F_6 ( V_6 , F_7 ( V_7 ) , V_7 ) ;
if ( V_7 [ 0 ] < 1 ) {
F_8 ( L_1 ) ;
return 0 ;
}
if ( V_7 [ 0 ] >= 1 )
V_8 = V_7 [ 1 ] ;
if ( V_7 [ 0 ] >= 2 )
V_9 = V_7 [ 2 ] ;
if ( V_7 [ 0 ] >= 3 )
V_10 = V_7 [ 3 ] ;
if ( V_7 [ 0 ] >= 4 )
V_11 = V_7 [ 4 ] ;
if ( V_7 [ 0 ] >= 6 )
V_12 = V_7 [ 6 ] ;
if ( V_7 [ 0 ] >= 7 )
V_13 = V_7 [ 7 ] ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char * V_14 , int V_15 )
{
struct V_16 * V_17 = F_10 ( V_2 ) ;
unsigned char * V_18 = V_17 -> V_19 + ( V_20 << 4 ) ;
unsigned char * V_21 = V_14 ;
int V_22 = V_15 ;
int V_23 ;
while ( ! F_11 ( V_2 , V_24 ,
V_25 | V_26 ,
V_25 | V_26 , V_27 / 64 ) ) {
F_12 ( V_18 , V_21 , V_22 ) ;
V_23 = V_21 - V_14 - V_22 ;
V_17 -> V_28 = V_15 - V_23 ;
if ( V_22 == 0 )
return 0 ;
if ( F_13 ( V_2 , V_29 , V_30 , V_30 ,
V_24 , V_31 , V_31 , V_27 / 64 ) < 0 )
F_14 ( V_32 , V_17 -> V_33 ,
L_2 , V_34 ) ;
if ( ! ( F_15 ( V_24 ) & V_26 ) )
return 0 ;
F_16 ( V_35 , V_2 ,
L_3 , V_34 , V_23 , V_15 ) ;
F_17 ( V_35 , V_2 ) ;
V_21 = V_14 + V_23 ;
V_22 = V_15 - V_23 ;
}
F_14 ( V_32 , V_17 -> V_33 ,
L_4 , V_34 ) ;
F_17 ( V_35 , V_2 ) ;
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned char * V_36 , int V_15 )
{
struct V_16 * V_17 = F_10 ( V_2 ) ;
unsigned char * V_18 = V_36 ;
unsigned char * V_21 = V_17 -> V_19 + ( V_37 << 4 ) ;
int V_22 = V_15 ;
int V_23 ;
while ( ! F_11 ( V_2 , V_24 ,
V_25 | V_26 ,
V_25 | V_26 , V_27 / 64 ) ) {
F_19 ( V_18 , V_21 , V_22 ) ;
V_23 = V_18 - V_36 - V_22 ;
V_17 -> V_28 = V_15 - V_23 ;
if ( F_13 ( V_2 , V_29 , V_30 , V_30 ,
V_24 , V_31 , V_31 , V_27 / 64 ) < 0 )
F_14 ( V_32 , V_17 -> V_33 ,
L_2 , V_34 ) ;
if ( ! ( F_15 ( V_24 ) & V_26 ) )
return 0 ;
if ( V_22 == 0 ) {
if ( F_11 ( V_2 , V_38 ,
V_39 ,
V_39 , V_27 / 64 ) < 0 )
F_14 ( V_32 , V_17 -> V_33 ,
L_5 , V_34 ) ;
return 0 ;
}
F_16 ( V_35 , V_2 ,
L_3 , V_34 , V_23 , V_15 ) ;
F_17 ( V_35 , V_2 ) ;
V_18 = V_36 + V_23 ;
V_22 = V_15 - V_23 ;
}
F_14 ( V_32 , V_17 -> V_33 ,
L_4 , V_34 ) ;
F_17 ( V_35 , V_2 ) ;
return - 1 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_16 * V_17 = F_10 ( V_2 ) ;
if ( V_17 -> V_42 & V_43 ||
V_41 -> V_44 . V_45 < 16 )
return 0 ;
return V_41 -> V_44 . V_45 ;
}
static int T_1 F_21 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int error ;
int V_48 = 0 ;
struct V_49 * V_50 , * V_51 , * V_52 = NULL ;
V_51 = F_22 ( V_47 , V_53 , 0 ) ;
if ( ! V_51 )
return - V_54 ;
V_52 = F_22 ( V_47 , V_53 , 1 ) ;
V_50 = F_22 ( V_47 , V_55 , 0 ) ;
if ( ! F_23 ( ( unsigned char * ) V_51 -> V_56 +
( V_29 << 4 ) ) ) {
F_24 ( V_57 L_6 , & V_51 -> V_56 ) ;
return - V_54 ;
}
if ( V_8 > 0 )
V_58 . V_59 = V_8 ;
if ( V_9 > 0 )
V_58 . V_60 = V_9 ;
if ( V_10 >= 0 )
V_58 . V_61 = V_10 ;
if ( V_11 >= 0 )
V_58 . V_62 = V_11 & 7 ;
V_2 = F_25 ( & V_58 ,
sizeof( struct V_16 ) ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_4 = V_51 -> V_56 ;
if ( V_50 )
V_2 -> V_50 = V_50 -> V_56 ;
else
V_2 -> V_50 = V_64 ;
if ( V_52 && V_12 ) {
struct V_16 * V_17 = F_10 ( V_2 ) ;
V_17 -> V_19 = ( unsigned char * ) V_52 -> V_56 ;
} else
V_48 |= V_43 ;
V_48 |= V_13 > 0 ? V_65 : 0 ;
error = F_26 ( V_2 , V_48 | V_66 ) ;
if ( error )
goto V_67;
if ( V_2 -> V_50 != V_64 ) {
error = F_27 ( V_2 -> V_50 , V_68 , V_69 ,
L_7 , V_2 ) ;
if ( error )
goto V_70;
}
F_28 ( V_2 ) ;
error = F_29 ( V_2 , NULL ) ;
if ( error )
goto V_71;
F_30 ( V_47 , V_2 ) ;
F_31 ( V_2 ) ;
return 0 ;
V_71:
if ( V_2 -> V_50 != V_64 )
F_32 ( V_2 -> V_50 , V_2 ) ;
V_70:
F_33 ( V_2 ) ;
V_67:
F_34 ( V_2 ) ;
return error ;
}
static int T_2 F_35 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_36 ( V_47 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_50 != V_64 )
F_32 ( V_2 -> V_50 , V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
