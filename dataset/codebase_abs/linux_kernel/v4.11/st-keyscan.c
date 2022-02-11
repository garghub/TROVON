static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned short * V_5 = V_4 -> V_6 -> V_5 ;
unsigned long V_7 , V_8 ;
int V_9 ;
V_7 = F_2 ( V_4 -> V_10 + V_11 ) & 0xffff ;
V_8 = V_4 -> V_12 ^ V_7 ;
V_4 -> V_12 = V_7 ;
F_3 (bit_nr, &change, BITS_PER_LONG)
F_4 ( V_4 -> V_6 ,
V_5 [ V_9 ] , V_7 & F_5 ( V_9 ) ) ;
F_6 ( V_4 -> V_6 ) ;
return V_13 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int error ;
error = F_8 ( V_4 -> V_14 ) ;
if ( error )
return error ;
F_9 ( V_4 -> V_15 * ( F_10 ( V_4 -> V_14 ) / 1000000 ) ,
V_4 -> V_10 + V_16 ) ;
F_9 ( ( ( V_4 -> V_17 - 1 ) << V_18 ) |
( ( V_4 -> V_19 - 1 ) << V_20 ) ,
V_4 -> V_10 + V_21 ) ;
F_9 ( V_22 , V_4 -> V_10 + V_23 ) ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_9 ( 0 , V_4 -> V_10 + V_23 ) ;
F_12 ( V_4 -> V_14 ) ;
}
static int F_13 ( struct V_6 * V_24 )
{
struct V_3 * V_4 = F_14 ( V_24 ) ;
return F_7 ( V_4 ) ;
}
static void F_15 ( struct V_6 * V_24 )
{
struct V_3 * V_4 = F_14 ( V_24 ) ;
F_11 ( V_4 ) ;
}
static int F_16 ( struct V_3 * V_25 )
{
struct V_26 * V_24 = V_25 -> V_6 -> V_24 . V_27 ;
struct V_28 * V_29 = V_24 -> V_30 ;
int error ;
error = F_17 ( V_24 , & V_25 -> V_19 ,
& V_25 -> V_17 ) ;
if ( error ) {
F_18 ( V_24 , L_1 ) ;
return error ;
}
F_19 ( V_29 , L_2 , & V_25 -> V_15 ) ;
F_20 ( V_24 , L_3 ,
V_25 -> V_19 , V_25 -> V_17 ,
V_25 -> V_15 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 )
{
struct V_3 * V_25 ;
struct V_6 * V_6 ;
struct V_33 * V_34 ;
int error ;
if ( ! V_32 -> V_24 . V_30 ) {
F_18 ( & V_32 -> V_24 , L_4 ) ;
return - V_35 ;
}
V_25 = F_22 ( & V_32 -> V_24 , sizeof( * V_25 ) ,
V_36 ) ;
if ( ! V_25 )
return - V_37 ;
V_6 = F_23 ( & V_32 -> V_24 ) ;
if ( ! V_6 ) {
F_18 ( & V_32 -> V_24 , L_5 ) ;
return - V_37 ;
}
V_6 -> V_38 = V_32 -> V_38 ;
V_6 -> V_39 = L_6 ;
V_6 -> V_24 . V_27 = & V_32 -> V_24 ;
V_6 -> V_40 = F_13 ;
V_6 -> V_41 = F_15 ;
V_6 -> V_42 . V_43 = V_44 ;
error = F_16 ( V_25 ) ;
if ( error )
return error ;
error = F_24 ( NULL , NULL ,
V_25 -> V_19 ,
V_25 -> V_17 ,
NULL , V_6 ) ;
if ( error ) {
F_18 ( & V_32 -> V_24 , L_7 ) ;
return error ;
}
F_25 ( V_6 , V_25 ) ;
V_25 -> V_6 = V_6 ;
V_34 = F_26 ( V_32 , V_45 , 0 ) ;
V_25 -> V_10 = F_27 ( & V_32 -> V_24 , V_34 ) ;
if ( F_28 ( V_25 -> V_10 ) )
return F_29 ( V_25 -> V_10 ) ;
V_25 -> V_14 = F_30 ( & V_32 -> V_24 , NULL ) ;
if ( F_28 ( V_25 -> V_14 ) ) {
F_18 ( & V_32 -> V_24 , L_8 ) ;
return F_29 ( V_25 -> V_14 ) ;
}
error = F_8 ( V_25 -> V_14 ) ;
if ( error ) {
F_18 ( & V_32 -> V_24 , L_9 ) ;
return error ;
}
F_11 ( V_25 ) ;
V_25 -> V_1 = F_31 ( V_32 , 0 ) ;
if ( V_25 -> V_1 < 0 ) {
F_18 ( & V_32 -> V_24 , L_10 ) ;
return - V_35 ;
}
error = F_32 ( & V_32 -> V_24 , V_25 -> V_1 , F_1 , 0 ,
V_32 -> V_38 , V_25 ) ;
if ( error ) {
F_18 ( & V_32 -> V_24 , L_11 ) ;
return error ;
}
error = F_33 ( V_6 ) ;
if ( error ) {
F_18 ( & V_32 -> V_24 , L_12 ) ;
return error ;
}
F_34 ( V_32 , V_25 ) ;
F_35 ( & V_32 -> V_24 , 1 ) ;
return 0 ;
}
static int F_36 ( struct V_26 * V_24 )
{
struct V_31 * V_32 = F_37 ( V_24 ) ;
struct V_3 * V_4 = F_38 ( V_32 ) ;
struct V_6 * V_46 = V_4 -> V_6 ;
F_39 ( & V_46 -> V_47 ) ;
if ( F_40 ( V_24 ) )
F_41 ( V_4 -> V_1 ) ;
else if ( V_46 -> V_48 )
F_11 ( V_4 ) ;
F_42 ( & V_46 -> V_47 ) ;
return 0 ;
}
static int F_43 ( struct V_26 * V_24 )
{
struct V_31 * V_32 = F_37 ( V_24 ) ;
struct V_3 * V_4 = F_38 ( V_32 ) ;
struct V_6 * V_46 = V_4 -> V_6 ;
int V_49 = 0 ;
F_39 ( & V_46 -> V_47 ) ;
if ( F_40 ( V_24 ) )
F_44 ( V_4 -> V_1 ) ;
else if ( V_46 -> V_48 )
V_49 = F_7 ( V_4 ) ;
F_42 ( & V_46 -> V_47 ) ;
return V_49 ;
}
