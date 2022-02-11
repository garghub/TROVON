static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
int V_8 , V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + V_13 ) || ! V_4 -> V_14 ) {
for ( V_8 = 0 ; V_8 < 7 ; V_8 ++ ) {
V_9 = F_5 ( V_6 ,
F_6 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_15 [ 0 ] [ V_8 ] = V_9 >> 4 ;
V_9 = F_7 ( V_6 ,
F_8 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_15 [ 1 ] [ V_8 ] = V_9 << 4 ;
V_9 = F_7 ( V_6 ,
F_9 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_15 [ 2 ] [ V_8 ] = V_9 << 4 ;
}
V_9 = F_5 ( V_6 , V_16 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 0 ] = V_9 >> 7 ;
V_9 = F_7 ( V_6 , V_18 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 1 ] = V_9 << 1 ;
V_9 = F_7 ( V_6 , V_19 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 2 ] = V_9 << 1 ;
V_9 = F_7 ( V_6 , V_20 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_21 |= V_9 ;
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = true ;
}
goto V_22;
abort:
V_7 = F_10 ( V_9 ) ;
V_4 -> V_14 = false ;
V_22:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_26 = F_13 ( V_24 ) -> V_26 ;
int V_27 = F_13 ( V_24 ) -> V_27 ;
int V_28 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_28 = F_16 ( V_4 -> V_15 [ V_26 ] [ V_27 ] * V_4 -> V_29 , 4095 ) ;
return sprintf ( V_25 , L_1 , V_28 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 , struct V_23 * V_24 ,
const char * V_25 , T_2 V_30 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_26 = F_13 ( V_24 ) -> V_26 ;
int V_27 = F_13 ( V_24 ) -> V_27 ;
T_3 V_31 , V_32 ;
long V_28 ;
int V_33 ;
V_33 = F_18 ( V_25 , 10 , & V_28 ) ;
if ( V_33 < 0 )
return V_33 ;
F_3 ( & V_4 -> V_10 ) ;
V_32 = F_19 ( F_16 ( V_28 , 10 ) , 0 , 255 ) ;
V_4 -> V_15 [ V_26 ] [ V_27 ] = V_32 << 4 ;
V_31 = V_26 == 1 ? F_8 ( V_27 ) : F_9 ( V_27 ) ;
F_20 ( V_4 -> V_6 , V_31 , V_32 ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_30 ;
}
static T_1 F_21 ( struct V_2 * V_3 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_26 = F_22 ( V_24 ) -> V_26 ;
int V_17 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_17 = ( V_4 -> V_17 [ V_26 ] << 7 ) >> 7 ;
return sprintf ( V_25 , L_1 , V_17 * 500 ) ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_30 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_26 = F_22 ( V_24 ) -> V_26 ;
long V_28 ;
int V_33 ;
T_4 V_32 ;
V_33 = F_18 ( V_25 , 10 , & V_28 ) ;
if ( V_33 < 0 )
return V_33 ;
F_3 ( & V_4 -> V_10 ) ;
V_32 = F_19 ( F_16 ( V_28 , 1000 ) , - 128 , 127 ) ;
V_4 -> V_17 [ V_26 ] = V_32 << 1 ;
F_20 ( V_4 -> V_6 ,
V_26 == 1 ? V_18
: V_19 ,
V_32 ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_30 ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_34 = 1 << F_22 ( V_24 ) -> V_26 ;
T_3 V_21 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_21 = V_4 -> V_21 ;
V_4 -> V_21 &= ~ V_34 ;
return sprintf ( V_25 , L_2 , ! ! ( V_21 & V_34 ) ) ;
}
static int F_25 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
int V_37 , V_38 ;
if ( ! F_26 ( V_6 -> V_39 ,
V_40 |
V_41 ) )
return - V_42 ;
V_37 = F_7 ( V_6 , V_43 ) ;
V_38 = F_7 ( V_6 , V_44 ) ;
if ( V_37 != 0x01 || V_38 != 0x09 )
return - V_42 ;
if ( F_7 ( V_6 , V_45 ) & 0xf4 )
return - V_42 ;
if ( F_7 ( V_6 , V_46 ) & 0xfe )
return - V_42 ;
if ( F_7 ( V_6 , V_47 ) & 0xfe )
return - V_42 ;
if ( F_7 ( V_6 , V_48 ) & 0xfe )
return - V_42 ;
if ( F_7 ( V_6 , V_49 ) & 0xf8 )
return - V_42 ;
if ( F_7 ( V_6 , V_50 ) & 0xfc )
return - V_42 ;
F_27 ( V_36 -> type , L_3 , V_51 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_33 ;
V_33 = F_20 ( V_6 , V_45 , 0x80 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_20 ( V_6 , V_45 , 0x01 ) ;
if ( V_33 )
return V_33 ;
if ( V_4 -> V_52 ) {
V_33 = F_20 ( V_6 ,
V_49 , 0x01 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
const struct V_53 * V_54 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_52 * V_52 ;
struct V_2 * V_55 ;
struct V_1 * V_4 ;
int V_33 , V_29 ;
V_4 = F_30 ( V_3 , sizeof( struct V_1 ) , V_56 ) ;
if ( ! V_4 )
return - V_57 ;
V_52 = F_31 ( V_3 , L_4 ) ;
if ( ! F_14 ( V_52 ) ) {
V_4 -> V_52 = V_52 ;
V_33 = F_32 ( V_52 ) ;
if ( V_33 < 0 )
return V_33 ;
V_29 = F_33 ( V_52 ) ;
if ( V_29 < 0 ) {
V_33 = V_29 ;
goto error;
}
V_4 -> V_29 = F_16 ( V_29 , 1000 ) ;
} else {
V_4 -> V_29 = 2560 ;
}
V_4 -> V_6 = V_6 ;
F_34 ( V_6 , V_4 ) ;
F_35 ( & V_4 -> V_10 ) ;
V_33 = F_28 ( V_4 ) ;
if ( V_33 < 0 )
goto error;
V_55 = F_36 ( V_3 , V_6 -> V_58 ,
V_4 , V_59 ) ;
if ( F_14 ( V_55 ) ) {
V_33 = F_15 ( V_55 ) ;
goto error;
}
return 0 ;
error:
if ( V_4 -> V_52 )
F_37 ( V_4 -> V_52 ) ;
return V_33 ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_39 ( V_6 ) ;
if ( V_4 -> V_52 )
F_37 ( V_4 -> V_52 ) ;
return 0 ;
}
