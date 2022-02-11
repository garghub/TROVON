int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
unsigned int V_8 ;
if ( V_3 < V_9 || V_3 > V_10 )
return - V_11 ;
V_8 = F_3 ( V_3 - V_9 ) ;
if ( V_4 )
V_6 -> V_12 |= V_8 ;
else
V_6 -> V_12 &= ~ V_8 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_13 * V_13 = V_6 -> V_13 ;
F_5 ( V_13 ) ;
if ( V_13 -> V_14 ) {
V_13 -> V_14 -> V_15 ( V_13 , V_16 ,
V_17 ) ;
V_13 -> V_14 -> V_15 ( V_13 , V_6 -> V_12 ,
V_17 ) ;
}
F_6 ( V_13 ) ;
}
static int F_7 ( struct V_13 * V_18 , unsigned char V_19 )
{
struct V_5 * V_6 = V_18 -> V_20 ;
int error ;
F_8 ( V_21 , & V_6 -> V_2 -> V_7 ,
L_1 ,
V_22 , V_19 ) ;
error = F_9 ( V_6 -> V_2 -> V_23 , V_6 -> V_2 -> V_24 . V_25 , V_19 ) ;
if ( error ) {
F_10 ( & V_6 -> V_2 -> V_7 ,
L_2 ,
V_22 , error ) ;
return error ;
}
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_26 * V_7 = & V_2 -> V_7 ;
int error ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_29 [ V_30 * V_31 ] ;
T_2 V_32 ;
error = F_12 ( V_2 -> V_23 , V_2 -> V_24 . V_33 , & V_28 ) ;
if ( error ) {
F_10 ( V_7 , L_3 , error ) ;
return error ;
}
V_6 -> V_34 = V_28 & V_30 ;
V_27 = ( V_28 >> V_35 ) &
V_31 ;
V_32 = V_6 -> V_34 * V_27 ;
if ( V_32 < 1 ) {
V_6 -> V_34 = 1 ;
V_6 -> V_36 = 7 ;
} else {
error = F_13 ( V_2 -> V_23 , V_2 -> V_24 . V_33 + 1 ,
V_29 , V_32 ) ;
if ( error ) {
F_10 ( V_7 ,
L_4 ,
error ) ;
return error ;
}
V_6 -> V_36 = V_29 [ 0 ] & V_37 ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_13 * V_13 ;
V_13 = F_15 ( sizeof( struct V_13 ) , V_38 ) ;
if ( ! V_13 )
return - V_39 ;
V_13 -> V_18 . type = V_40 ;
V_13 -> V_41 = F_7 ;
V_13 -> V_20 = V_6 ;
F_16 ( V_13 -> V_42 , L_5 ,
sizeof( V_13 -> V_42 ) ) ;
F_16 ( V_13 -> V_43 , L_6 ,
sizeof( V_13 -> V_43 ) ) ;
V_13 -> V_7 . V_44 = & V_6 -> V_2 -> V_7 ;
V_6 -> V_13 = V_13 ;
F_17 ( V_13 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_7 = & V_2 -> V_7 ;
struct V_5 * V_6 ;
int error ;
V_6 = F_19 ( V_7 , sizeof( struct V_5 ) , V_38 ) ;
if ( ! V_6 )
return - V_39 ;
V_6 -> V_2 = V_2 ;
error = F_11 ( V_6 ) ;
if ( error < 0 )
return error ;
if ( V_6 -> V_34 != 1 )
F_20 ( V_7 , L_7 ,
V_6 -> V_34 ) ;
F_21 ( V_7 , V_6 ) ;
error = F_14 ( V_6 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_45 -> V_46 ( V_2 -> V_23 , V_2 -> V_47 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned long * V_48 )
{
struct V_49 * V_23 = V_2 -> V_23 ;
struct V_50 * V_51 = F_2 ( & V_23 -> V_7 ) ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_3 V_52 = V_2 -> V_24 . V_25 ;
const T_1 V_53 = V_6 -> V_36 * V_54 ;
T_1 V_55 [ V_37 * V_54 ] ;
T_1 V_56 ;
T_1 V_57 ;
unsigned int V_58 ;
int V_59 ;
int error ;
if ( V_51 -> V_60 . V_61 ) {
if ( V_51 -> V_60 . V_62 < V_53 ) {
F_20 ( & V_2 -> V_7 , L_8 ) ;
return 0 ;
}
memcpy ( V_55 , V_51 -> V_60 . V_61 , V_53 ) ;
V_51 -> V_60 . V_61 += V_53 ;
V_51 -> V_60 . V_62 -= V_53 ;
} else {
error = F_13 ( V_2 -> V_23 , V_52 + V_63 ,
& V_55 , V_53 ) ;
if ( error ) {
F_10 ( & V_2 -> V_7 ,
L_9 ,
V_22 , error ) ;
F_24 ( V_6 -> V_13 , 0 , V_64 ) ;
return error ;
}
}
for ( V_59 = 0 ; V_59 < V_53 ; V_59 += V_54 ) {
V_56 = V_55 [ V_59 ] ;
V_57 = V_55 [ V_59 + V_65 ] ;
V_58 = 0 ;
if ( ! ( V_56 & V_66 ) )
continue;
if ( V_56 & V_67 )
V_58 |= V_64 ;
if ( V_56 & V_68 )
V_58 |= V_69 ;
F_8 ( V_21 , & V_2 -> V_7 ,
L_10 ,
V_22 , V_57 ,
V_58 & V_64 ? 'Y' : 'N' ,
V_58 & V_69 ? 'Y' : 'N' ) ;
F_24 ( V_6 -> V_13 , V_57 , V_58 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
F_26 ( V_6 -> V_13 ) ;
}
