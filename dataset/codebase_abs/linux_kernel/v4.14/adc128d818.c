static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
int V_8 , V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + V_13 ) || ! V_4 -> V_14 ) {
for ( V_8 = 0 ; V_8 < V_15 [ V_4 -> V_16 ] ; V_8 ++ ) {
V_9 = F_5 ( V_6 ,
F_6 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 0 ] [ V_8 ] = V_9 >> 4 ;
V_9 = F_7 ( V_6 ,
F_8 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 1 ] [ V_8 ] = V_9 << 4 ;
V_9 = F_7 ( V_6 ,
F_9 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_17 [ 2 ] [ V_8 ] = V_9 << 4 ;
}
if ( V_4 -> V_16 != 1 ) {
V_9 = F_5 ( V_6 ,
V_18 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ 0 ] = V_9 >> 7 ;
V_9 = F_7 ( V_6 ,
V_20 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ 1 ] = V_9 << 1 ;
V_9 = F_7 ( V_6 ,
V_21 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ 2 ] = V_9 << 1 ;
}
V_9 = F_7 ( V_6 , V_22 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_23 |= V_9 ;
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = true ;
}
goto V_24;
abort:
V_7 = F_10 ( V_9 ) ;
V_4 -> V_14 = false ;
V_24:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_1 F_12 ( struct V_2 * V_3 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_28 = F_13 ( V_26 ) -> V_28 ;
int V_29 = F_13 ( V_26 ) -> V_29 ;
int V_30 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_30 = F_16 ( V_4 -> V_17 [ V_28 ] [ V_29 ] * V_4 -> V_31 , 4095 ) ;
return sprintf ( V_27 , L_1 , V_30 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 , struct V_25 * V_26 ,
const char * V_27 , T_2 V_32 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_28 = F_13 ( V_26 ) -> V_28 ;
int V_29 = F_13 ( V_26 ) -> V_29 ;
T_3 V_33 , V_34 ;
long V_30 ;
int V_35 ;
V_35 = F_18 ( V_27 , 10 , & V_30 ) ;
if ( V_35 < 0 )
return V_35 ;
F_3 ( & V_4 -> V_10 ) ;
V_34 = F_19 ( F_16 ( V_30 , 10 ) , 0 , 255 ) ;
V_4 -> V_17 [ V_28 ] [ V_29 ] = V_34 << 4 ;
V_33 = V_28 == 1 ? F_8 ( V_29 ) : F_9 ( V_29 ) ;
F_20 ( V_4 -> V_6 , V_33 , V_34 ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_32 ;
}
static T_1 F_21 ( struct V_2 * V_3 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_28 = F_22 ( V_26 ) -> V_28 ;
int V_19 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_19 = F_23 ( V_4 -> V_19 [ V_28 ] , 8 ) ;
return sprintf ( V_27 , L_1 , V_19 * 500 ) ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
const char * V_27 , T_2 V_32 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_28 = F_22 ( V_26 ) -> V_28 ;
long V_30 ;
int V_35 ;
T_4 V_34 ;
V_35 = F_18 ( V_27 , 10 , & V_30 ) ;
if ( V_35 < 0 )
return V_35 ;
F_3 ( & V_4 -> V_10 ) ;
V_34 = F_19 ( F_16 ( V_30 , 1000 ) , - 128 , 127 ) ;
V_4 -> V_19 [ V_28 ] = V_34 << 1 ;
F_20 ( V_4 -> V_6 ,
V_28 == 1 ? V_20
: V_21 ,
V_34 ) ;
F_11 ( & V_4 -> V_10 ) ;
return V_32 ;
}
static T_1 F_25 ( struct V_2 * V_3 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_36 = 1 << F_22 ( V_26 ) -> V_28 ;
T_3 V_23 ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
V_23 = V_4 -> V_23 ;
V_4 -> V_23 &= ~ V_36 ;
return sprintf ( V_27 , L_2 , ! ! ( V_23 & V_36 ) ) ;
}
static T_5 F_26 ( struct V_37 * V_38 ,
struct V_39 * V_26 , int V_28 )
{
struct V_2 * V_3 = F_27 ( V_38 , struct V_2 , V_38 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_28 < V_40 ) {
if ( V_28 >= V_15 [ V_4 -> V_16 ] * 4 )
return 0 ;
} else {
if ( V_4 -> V_16 == 1 )
return 0 ;
}
return V_26 -> V_16 ;
}
static int F_28 ( struct V_5 * V_6 , struct V_41 * V_42 )
{
int V_43 , V_44 ;
if ( ! F_29 ( V_6 -> V_45 ,
V_46 |
V_47 ) )
return - V_48 ;
V_43 = F_7 ( V_6 , V_49 ) ;
V_44 = F_7 ( V_6 , V_50 ) ;
if ( V_43 != 0x01 || V_44 != 0x09 )
return - V_48 ;
if ( F_7 ( V_6 , V_51 ) & 0xf4 )
return - V_48 ;
if ( F_7 ( V_6 , V_52 ) & 0xfe )
return - V_48 ;
if ( F_7 ( V_6 , V_53 ) & 0xfe )
return - V_48 ;
if ( F_7 ( V_6 , V_54 ) & 0xfe )
return - V_48 ;
if ( F_7 ( V_6 , V_55 ) & 0xf8 )
return - V_48 ;
if ( F_7 ( V_6 , V_56 ) & 0xfc )
return - V_48 ;
F_30 ( V_42 -> type , L_3 , V_57 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_35 ;
V_35 = F_20 ( V_6 , V_51 , 0x80 ) ;
if ( V_35 )
return V_35 ;
if ( V_4 -> V_16 != 0 ) {
V_35 = F_20 ( V_6 ,
V_55 ,
V_4 -> V_16 << 1 ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_20 ( V_6 , V_51 , 0x01 ) ;
if ( V_35 )
return V_35 ;
if ( V_4 -> V_58 ) {
V_35 = F_20 ( V_6 ,
V_55 , 0x01 ) ;
if ( V_35 )
return V_35 ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_59 * V_60 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_58 * V_58 ;
struct V_2 * V_61 ;
struct V_1 * V_4 ;
int V_35 , V_31 ;
V_4 = F_33 ( V_3 , sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_4 )
return - V_63 ;
V_58 = F_34 ( V_3 , L_4 ) ;
if ( ! F_14 ( V_58 ) ) {
V_4 -> V_58 = V_58 ;
V_35 = F_35 ( V_58 ) ;
if ( V_35 < 0 )
return V_35 ;
V_31 = F_36 ( V_58 ) ;
if ( V_31 < 0 ) {
V_35 = V_31 ;
goto error;
}
V_4 -> V_31 = F_16 ( V_31 , 1000 ) ;
} else {
V_4 -> V_31 = 2560 ;
}
if ( F_37 ( V_3 -> V_64 , L_5 , & V_4 -> V_16 ) == 0 ) {
if ( V_4 -> V_16 > 3 ) {
F_38 ( V_3 , L_6 ,
V_4 -> V_16 ) ;
V_35 = - V_65 ;
goto error;
}
} else {
V_35 = F_7 ( V_6 , V_55 ) ;
if ( V_35 < 0 )
goto error;
V_4 -> V_16 = ( V_35 >> 1 ) & V_66 ;
}
V_4 -> V_6 = V_6 ;
F_39 ( V_6 , V_4 ) ;
F_40 ( & V_4 -> V_10 ) ;
V_35 = F_31 ( V_4 ) ;
if ( V_35 < 0 )
goto error;
V_61 = F_41 ( V_3 , V_6 -> V_67 ,
V_4 , V_68 ) ;
if ( F_14 ( V_61 ) ) {
V_35 = F_15 ( V_61 ) ;
goto error;
}
return 0 ;
error:
if ( V_4 -> V_58 )
F_42 ( V_4 -> V_58 ) ;
return V_35 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_44 ( V_6 ) ;
if ( V_4 -> V_58 )
F_42 ( V_4 -> V_58 ) ;
return 0 ;
}
