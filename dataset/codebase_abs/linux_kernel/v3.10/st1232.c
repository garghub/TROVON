static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 V_8 [ 2 ] ;
int error ;
T_1 V_9 ;
T_1 V_10 [ 10 ] ;
V_8 [ 0 ] . V_11 = V_6 -> V_11 ;
V_8 [ 0 ] . V_12 = 0 ;
V_8 [ 0 ] . V_13 = 1 ;
V_8 [ 0 ] . V_10 = & V_9 ;
V_9 = 0x10 ;
V_8 [ 1 ] . V_11 = V_2 -> V_6 -> V_11 ;
V_8 [ 1 ] . V_12 = V_14 ;
V_8 [ 1 ] . V_13 = sizeof( V_10 ) ;
V_8 [ 1 ] . V_10 = V_10 ;
error = F_2 ( V_6 -> V_15 , V_8 , 2 ) ;
if ( error < 0 )
return error ;
V_4 [ 0 ] . V_16 = V_10 [ 2 ] >> 7 ;
V_4 [ 1 ] . V_16 = V_10 [ 5 ] >> 7 ;
if ( V_4 [ 0 ] . V_16 ) {
V_4 [ 0 ] . V_17 = ( ( V_10 [ 2 ] & 0x0070 ) << 4 ) | V_10 [ 3 ] ;
V_4 [ 0 ] . V_18 = ( ( V_10 [ 2 ] & 0x0007 ) << 8 ) | V_10 [ 4 ] ;
V_4 [ 0 ] . V_19 = V_10 [ 8 ] ;
}
if ( V_4 [ 1 ] . V_16 ) {
V_4 [ 1 ] . V_17 = ( ( V_10 [ 5 ] & 0x0070 ) << 4 ) | V_10 [ 6 ] ;
V_4 [ 1 ] . V_18 = ( ( V_10 [ 5 ] & 0x0007 ) << 8 ) | V_10 [ 7 ] ;
V_4 [ 1 ] . V_19 = V_10 [ 9 ] ;
}
return 0 ;
}
static T_2 F_3 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_22 = V_2 -> V_22 ;
int V_23 = 0 ;
int V_24 , V_25 ;
V_25 = F_1 ( V_2 ) ;
if ( V_25 < 0 )
goto V_26;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
if ( ! V_4 [ V_24 ] . V_16 )
continue;
F_4 ( V_22 , V_28 , V_4 [ V_24 ] . V_19 ) ;
F_4 ( V_22 , V_29 , V_4 [ V_24 ] . V_17 ) ;
F_4 ( V_22 , V_30 , V_4 [ V_24 ] . V_18 ) ;
F_5 ( V_22 ) ;
V_23 ++ ;
}
if ( ! V_23 ) {
F_5 ( V_22 ) ;
if ( V_2 -> V_31 . V_32 ) {
F_6 ( & V_2 -> V_31 ) ;
V_2 -> V_31 . V_32 = NULL ;
}
} else if ( ! V_2 -> V_31 . V_32 ) {
F_7 ( & V_2 -> V_6 -> V_32 ,
& V_2 -> V_31 , 100 ) ;
}
F_8 ( V_22 ) ;
V_26:
return V_33 ;
}
static void F_9 ( struct V_1 * V_2 , bool V_34 )
{
if ( F_10 ( V_2 -> V_35 ) )
F_11 ( V_2 -> V_35 , V_34 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 = V_6 -> V_32 . V_40 ;
struct V_22 * V_22 ;
int error ;
if ( ! F_13 ( V_6 -> V_15 , V_41 ) ) {
F_14 ( & V_6 -> V_32 , L_1 ) ;
return - V_42 ;
}
if ( ! V_6 -> V_20 ) {
F_14 ( & V_6 -> V_32 , L_2 ) ;
return - V_43 ;
}
V_2 = F_15 ( & V_6 -> V_32 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_22 = F_16 ( & V_6 -> V_32 ) ;
if ( ! V_22 )
return - V_45 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_22 = V_22 ;
if ( V_39 )
V_2 -> V_35 = V_39 -> V_35 ;
else if ( V_6 -> V_32 . V_46 )
V_2 -> V_35 = F_17 ( V_6 -> V_32 . V_46 , 0 ) ;
else
V_2 -> V_35 = - V_47 ;
if ( F_10 ( V_2 -> V_35 ) ) {
error = F_18 ( & V_6 -> V_32 , V_2 -> V_35 , NULL ) ;
if ( error ) {
F_14 ( & V_6 -> V_32 ,
L_3 ,
V_2 -> V_35 ) ;
return error ;
}
}
F_9 ( V_2 , true ) ;
V_22 -> V_48 = L_4 ;
V_22 -> V_37 . V_49 = V_50 ;
V_22 -> V_32 . V_51 = & V_6 -> V_32 ;
F_19 ( V_52 , V_22 -> V_53 ) ;
F_19 ( V_54 , V_22 -> V_53 ) ;
F_19 ( V_55 , V_22 -> V_53 ) ;
F_20 ( V_22 , V_28 , 0 , V_56 , 0 , 0 ) ;
F_20 ( V_22 , V_29 , V_57 , V_58 , 0 , 0 ) ;
F_20 ( V_22 , V_30 , V_59 , V_60 , 0 , 0 ) ;
error = F_21 ( & V_6 -> V_32 , V_6 -> V_20 ,
NULL , F_3 ,
V_61 ,
V_6 -> V_48 , V_2 ) ;
if ( error ) {
F_14 ( & V_6 -> V_32 , L_5 ) ;
return error ;
}
error = F_22 ( V_2 -> V_22 ) ;
if ( error ) {
F_14 ( & V_6 -> V_32 , L_6 ,
V_22 -> V_48 ) ;
return error ;
}
F_23 ( V_6 , V_2 ) ;
F_24 ( & V_6 -> V_32 , 1 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
F_24 ( & V_6 -> V_32 , 0 ) ;
F_9 ( V_2 , false ) ;
return 0 ;
}
static int F_27 ( struct V_62 * V_32 )
{
struct V_5 * V_6 = F_28 ( V_32 ) ;
struct V_1 * V_2 = F_26 ( V_6 ) ;
if ( F_29 ( & V_6 -> V_32 ) ) {
F_30 ( V_6 -> V_20 ) ;
} else {
F_31 ( V_6 -> V_20 ) ;
F_9 ( V_2 , false ) ;
}
return 0 ;
}
static int F_32 ( struct V_62 * V_32 )
{
struct V_5 * V_6 = F_28 ( V_32 ) ;
struct V_1 * V_2 = F_26 ( V_6 ) ;
if ( F_29 ( & V_6 -> V_32 ) ) {
F_33 ( V_6 -> V_20 ) ;
} else {
F_9 ( V_2 , true ) ;
F_34 ( V_6 -> V_20 ) ;
}
return 0 ;
}
