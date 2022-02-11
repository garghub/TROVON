static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_9 ;
unsigned int V_11 ;
unsigned int V_12 ;
int V_13 ;
V_13 = F_2 ( V_8 , V_6 -> V_14 ) ;
if ( V_13 < 0 ) {
F_3 ( & V_8 -> V_15 , L_1 , V_13 ) ;
goto V_16;
}
V_12 = ( V_13 & ( 1 << V_6 -> V_17 ) ) >> V_6 -> V_17 ;
if ( V_6 -> V_18 )
V_12 ^= V_6 -> V_18 ;
if ( V_12 ) {
V_11 = V_13 & ( 0xff >> ( 8 - V_6 -> V_17 ) ) ;
if ( ! V_11 )
goto V_16;
V_11 -= V_6 -> V_19 ;
V_4 -> V_20 = V_4 -> V_21 [ V_11 ] ;
V_4 -> V_11 = V_11 ;
}
F_4 ( V_10 , V_22 , V_23 , V_4 -> V_11 ) ;
F_5 ( V_10 , V_4 -> V_20 , V_12 ) ;
F_6 ( V_10 ) ;
F_7 ( & V_8 -> V_15 , L_2 , V_4 -> V_11 , V_4 -> V_20 ,
V_12 ? L_3 : L_4 ) ;
V_16:
return V_24 ;
}
static int F_8 ( struct V_7 * V_8 ,
const struct V_25 * V_26 )
{
const struct V_27 * V_28 ;
struct V_3 * V_4 ;
struct V_9 * V_9 ;
unsigned int V_29 ;
int V_30 ;
int error ;
int V_31 ;
V_28 = F_9 ( & V_8 -> V_15 ) ;
if ( ! V_28 ) {
F_3 ( & V_8 -> V_15 , L_5 ) ;
return - V_32 ;
}
V_4 = F_10 ( sizeof( struct V_3 ) +
sizeof( V_4 -> V_21 [ 0 ] ) * ( V_28 -> V_33 + 1 ) ,
V_34 ) ;
V_9 = F_11 () ;
if ( ! V_4 || ! V_9 ) {
F_3 ( & V_8 -> V_15 , L_6 ) ;
error = - V_35 ;
goto V_36;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
if ( V_26 -> V_37 == V_38 ) {
V_4 -> V_6 . V_14 = V_39 ;
V_4 -> V_6 . V_17 = V_40 ;
V_4 -> V_6 . V_19 = V_41 ;
V_29 = V_42 ;
} else {
V_4 -> V_6 . V_14 = V_43 ;
V_4 -> V_6 . V_17 = V_44 ;
V_4 -> V_6 . V_18 = 1 ;
V_4 -> V_6 . V_19 = V_45 ;
V_29 = V_46 ;
}
V_30 = F_2 ( V_8 , V_29 ) ;
if ( V_30 < 0 ) {
error = V_30 ;
F_3 ( & V_8 -> V_15 , L_7 , error ) ;
goto V_36;
}
F_12 ( & V_8 -> V_15 , L_8 , V_30 ) ;
V_9 -> V_47 = L_9 ;
V_9 -> V_26 . V_48 = V_49 ;
V_9 -> V_15 . V_50 = & V_8 -> V_15 ;
V_9 -> V_51 [ 0 ] = F_13 ( V_52 ) ;
if ( ! V_28 -> V_53 )
V_9 -> V_51 [ 0 ] |= F_13 ( V_54 ) ;
V_9 -> V_55 = V_4 -> V_21 ;
V_9 -> V_56 = sizeof( V_4 -> V_21 [ 0 ] ) ;
V_9 -> V_57 = V_28 -> V_33 + 1 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_58 ; V_31 ++ ) {
unsigned int V_13 = F_14 ( V_28 -> V_59 [ V_31 ] ) ;
unsigned int V_60 = F_15 ( V_28 -> V_59 [ V_31 ] ) ;
V_4 -> V_21 [ V_13 ] = V_60 ;
F_16 ( V_60 , V_9 -> V_61 ) ;
}
F_17 ( V_9 , V_22 , V_23 ) ;
F_18 ( V_9 , V_4 ) ;
if ( V_28 -> V_62 )
V_28 -> V_62 () ;
if ( V_28 -> V_63 ) {
V_4 -> V_63 = V_28 -> V_63 ;
V_4 -> V_63 ( true ) ;
}
error = F_19 ( V_8 -> V_1 , NULL , F_1 ,
V_64 | V_65 ,
V_8 -> V_15 . V_66 -> V_47 , V_4 ) ;
if ( error ) {
F_3 ( & V_8 -> V_15 , L_10 ) ;
goto V_36;
}
error = F_20 ( V_9 ) ;
if ( error )
goto V_67;
F_21 ( V_8 , V_4 ) ;
return 0 ;
V_67:
F_22 ( V_8 -> V_1 , V_4 ) ;
V_36:
F_23 ( V_9 ) ;
F_24 ( V_4 ) ;
return error ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_26 ( V_8 ) ;
F_22 ( V_8 -> V_1 , V_4 ) ;
if ( V_4 -> V_63 )
V_4 -> V_63 ( false ) ;
F_27 ( V_4 -> V_9 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_26 ( V_8 ) ;
if ( V_4 -> V_63 )
V_4 -> V_63 ( false ) ;
}
static int F_29 ( struct V_68 * V_15 )
{
struct V_3 * V_4 = F_30 ( V_15 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
F_31 ( V_8 -> V_1 ) ;
if ( V_4 -> V_63 )
V_4 -> V_63 ( false ) ;
return 0 ;
}
static int F_32 ( struct V_68 * V_15 )
{
struct V_3 * V_4 = F_30 ( V_15 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_4 -> V_63 )
V_4 -> V_63 ( true ) ;
F_33 ( V_8 -> V_1 ) ;
return 0 ;
}
