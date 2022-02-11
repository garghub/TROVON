static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned short * V_7 = V_6 -> V_8 ;
unsigned int V_9 ;
int V_10 , V_11 ;
T_2 V_12 ;
T_3 V_13 [ 8 ] ;
T_3 V_14 , V_15 ;
V_12 = F_2 ( V_4 -> V_16 + V_17 ) & V_4 -> V_18 ;
if ( ! V_12 )
return V_19 ;
F_3 ( V_13 , V_4 -> V_16 + V_20 , sizeof( V_13 ) ) ;
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ ) {
V_14 = V_13 [ V_10 ] ;
if ( V_4 -> V_22 )
V_14 = ~ V_14 ;
V_15 = V_14 ^ V_4 -> V_13 [ V_10 ] ;
if ( ! V_15 )
continue;
V_4 -> V_13 [ V_10 ] = V_14 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
if ( ! ( V_15 & ( 1U << V_11 ) ) )
continue;
V_9 = F_4 ( V_10 , V_11 , V_4 -> V_24 ) ;
F_5 ( V_6 , V_25 , V_26 , V_9 ) ;
F_6 ( V_6 , V_7 [ V_9 ] ,
V_14 & ( 1U << V_11 ) ) ;
}
}
F_7 ( V_6 ) ;
F_8 ( 0x3 , V_4 -> V_16 + V_17 ) ;
return V_27 ;
}
static int F_9 ( struct V_3 * V_4 )
{
unsigned long V_28 = 0 , V_29 , V_30 , V_31 ;
V_29 = ( F_10 ( V_4 -> V_32 ) / 1000000 ) ;
if ( V_29 == 0 )
V_29 = 1 ;
V_30 = V_29 * V_4 -> V_33 ;
F_11 ( V_30 >= ( 1 << 16 ) ) ;
V_30 &= 0xffff ;
V_31 = V_29 * V_4 -> V_34 ;
F_11 ( V_31 >= ( 1 << 14 ) ) ;
V_31 &= 0x3fff ;
V_28 |= 3 << 0 ;
V_28 |= V_31 << 2 ;
V_28 |= V_30 << 16 ;
F_8 ( V_28 , V_4 -> V_16 + V_35 ) ;
V_28 = ( V_21 & 0xff ) | ( V_23 & 0xff ) << 8 ;
F_8 ( V_28 , V_4 -> V_16 + V_36 ) ;
V_4 -> V_18 = 1 << 1 ;
F_8 ( V_4 -> V_18 , V_4 -> V_16 + V_37 ) ;
F_8 ( 0 , V_4 -> V_16 + V_38 ) ;
F_8 ( ~ 0 , V_4 -> V_16 + V_39 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
int error ;
error = F_14 ( V_4 -> V_32 ) ;
if ( error )
return error ;
error = F_9 ( V_4 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_13 ( V_6 ) ;
F_16 ( V_4 -> V_32 ) ;
}
static int F_17 ( struct V_40 * V_41 )
{
const struct V_42 * V_43 = V_41 -> V_44 . V_43 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_45 * V_46 ;
int V_1 ;
int error ;
V_1 = F_18 ( V_41 , 0 ) ;
if ( V_1 < 0 ) {
F_19 ( & V_41 -> V_44 , L_1 ) ;
return - V_47 ;
}
V_4 = F_20 ( & V_41 -> V_44 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 ) {
F_19 ( & V_41 -> V_44 , L_2 ) ;
return - V_49 ;
}
V_4 -> V_24 = F_21 ( V_23 ) ;
error = F_22 ( V_43 , L_3 ,
& V_4 -> V_33 ) ;
if ( error ) {
F_19 ( & V_41 -> V_44 , L_4 ) ;
return error ;
}
error = F_22 ( V_43 , L_5 ,
& V_4 -> V_34 ) ;
if ( error ) {
F_19 ( & V_41 -> V_44 , L_6 ) ;
return error ;
}
V_4 -> V_22 = F_23 ( V_43 , L_7 ) ;
V_4 -> V_32 = F_24 ( & V_41 -> V_44 , NULL ) ;
if ( F_25 ( V_4 -> V_32 ) ) {
F_19 ( & V_41 -> V_44 , L_8 ) ;
return F_26 ( V_4 -> V_32 ) ;
}
V_46 = F_27 ( V_41 , V_50 , 0 ) ;
V_4 -> V_16 = F_28 ( & V_41 -> V_44 , V_46 ) ;
if ( F_25 ( V_4 -> V_16 ) )
return F_26 ( V_4 -> V_16 ) ;
V_4 -> V_6 = V_6 = F_29 ( & V_41 -> V_44 ) ;
if ( ! V_6 ) {
F_19 ( & V_41 -> V_44 , L_9 ) ;
return - V_49 ;
}
F_30 ( V_6 , V_4 ) ;
V_6 -> V_51 . V_52 = V_53 ;
V_6 -> V_54 = L_10 ;
V_6 -> V_55 = F_12 ;
V_6 -> V_56 = F_15 ;
F_31 ( V_57 , V_6 -> V_58 ) ;
F_31 ( V_59 , V_6 -> V_58 ) ;
F_32 ( V_6 , V_25 , V_26 ) ;
error = F_33 ( NULL , NULL ,
V_21 ,
V_23 ,
NULL , V_6 ) ;
if ( error ) {
F_19 ( & V_41 -> V_44 , L_11 ) ;
return error ;
}
error = F_34 ( & V_41 -> V_44 , V_1 , F_1 , 0 ,
L_12 , V_4 ) ;
if ( error ) {
F_19 ( & V_41 -> V_44 , L_13 , V_1 ) ;
return error ;
}
error = F_35 ( V_6 ) ;
if ( error ) {
F_19 ( & V_41 -> V_44 ,
L_14 , error ) ;
return error ;
}
F_36 ( V_41 , V_4 ) ;
F_37 ( & V_41 -> V_44 ,
L_15 ,
V_46 , V_4 -> V_34 , V_4 -> V_33 ,
V_4 -> V_22 ? L_16 : L_17 ) ;
return 0 ;
}
