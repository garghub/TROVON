static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
if ( V_8 -> V_11 == ( V_12 | 0x0010 ) ) {
F_2 ( V_2 , ( void * ) 1 ) ;
F_3 ( V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
V_15 = V_2 -> V_18 [ V_19 ] . V_20 [ 4 ] ;
V_15 -> V_6 [ 0 ] -> V_21 [ 0 ] = V_17 -> V_22 ? 0x01 : 0x02 ;
V_15 -> V_6 [ 0 ] -> V_21 [ 0 ] |= V_17 -> V_23 ? 0x04 : 0x08 ;
V_15 -> V_6 [ 0 ] -> V_21 [ 0 ] |= V_17 -> V_24 ? 0x10 : 0x20 ;
V_15 -> V_6 [ 0 ] -> V_21 [ 0 ] |= V_17 -> V_25 ? 0x80 : 0x40 ;
V_15 -> V_6 [ 1 ] -> V_21 [ 0 ] = 0x03 ;
V_15 -> V_6 [ 2 ] -> V_21 [ 0 ] = V_17 -> V_26 ;
V_15 -> V_6 [ 3 ] -> V_21 [ 0 ] = V_17 -> V_27 ;
F_6 ( V_2 , V_15 , V_28 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 , V_17 -> V_22 ) ;
}
static T_1 F_9 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) )
return - V_36 ;
if ( V_21 < 0 || V_21 > 1 )
return - V_36 ;
V_17 -> V_22 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static T_1 F_11 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 , V_17 -> V_23 ) ;
}
static T_1 F_12 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) )
return - V_36 ;
if ( V_21 < 0 || V_21 > 1 )
return - V_36 ;
V_17 -> V_23 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static T_1 F_13 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 , V_17 -> V_24 ) ;
}
static T_1 F_14 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) )
return - V_36 ;
if ( V_21 < 0 || V_21 > 1 )
return - V_36 ;
V_17 -> V_24 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static T_1 F_15 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 , V_17 -> V_25 ) ;
}
static T_1 F_16 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) )
return - V_36 ;
if ( V_21 < 0 || V_21 > 1 )
return - V_36 ;
V_17 -> V_25 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static T_1 F_17 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 ,
V_17 -> V_26 ) ;
}
static T_1 F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) || V_21 < 1 || V_21 > 255 )
return - V_36 ;
V_17 -> V_26 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static T_1 F_19 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
return snprintf ( V_33 , V_34 , L_1 ,
V_17 -> V_27 ) ;
}
static T_1 F_20 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_2 V_35 )
{
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_21 ;
if ( F_10 ( V_33 , 10 , & V_21 ) || V_21 < 1 || V_21 > 255 )
return - V_36 ;
V_17 -> V_27 = V_21 ;
F_4 ( V_2 ) ;
return V_35 ;
}
static enum V_37 F_21 (
struct V_38 * V_39 )
{
struct V_29 * V_30 = V_39 -> V_30 -> V_40 ;
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_41 = 0 ;
if ( V_39 == & V_17 -> V_42 )
V_41 = 1 ;
return V_17 -> V_43 & ( 1 << V_41 )
? V_44
: V_45 ;
}
static void F_22 ( struct V_38 * V_39 ,
enum V_37 V_21 )
{
struct V_29 * V_30 = V_39 -> V_30 -> V_40 ;
struct V_1 * V_2 = F_8 ( V_30 , struct V_1 , V_30 ) ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
struct V_14 * V_15 ;
int V_41 = 0 ;
if ( V_39 == & V_17 -> V_42 )
V_41 = 1 ;
if ( V_21 == V_45 )
V_17 -> V_43 &= ~ ( 1 << V_41 ) ;
else
V_17 -> V_43 |= 1 << V_41 ;
V_15 = V_2 -> V_18 [ V_46 ] . V_20 [ 3 ] ;
V_15 -> V_6 [ 0 ] -> V_21 [ 0 ] = ( V_17 -> V_43 >> 0 ) & 1 ;
V_15 -> V_6 [ 0 ] -> V_21 [ 1 ] = ( V_17 -> V_43 >> 1 ) & 1 ;
F_6 ( V_2 , V_15 , V_28 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
struct V_16 * V_17 ;
T_2 V_47 = strlen ( F_24 ( V_30 ) ) + 16 ;
char * V_48 , * V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! F_25 ( V_2 , V_19 , 4 , V_50 , 1 ) )
return - V_51 ;
}
if ( ! F_25 ( V_2 , V_46 , 3 , 0 , 2 ) )
return - V_51 ;
if ( F_26 ( & V_2 -> V_30 . V_52 ,
& V_53 ) ) {
F_27 ( V_2 , L_2 ) ;
}
V_17 = F_28 ( & V_2 -> V_30 ,
sizeof( struct V_16 ) ,
V_54 ) ;
if ( V_17 == NULL ) {
F_29 ( V_2 , L_3 ) ;
return - V_55 ;
}
V_17 -> V_26 = 0xa0 ;
V_17 -> V_27 = 0x38 ;
V_48 = F_28 ( & V_2 -> V_30 , V_47 , V_54 ) ;
V_49 = F_28 ( & V_2 -> V_30 , V_47 , V_54 ) ;
if ( V_48 == NULL || V_49 == NULL ) {
F_29 ( V_2 , L_4 ) ;
return - V_55 ;
}
snprintf ( V_48 , V_47 , L_5 , F_24 ( V_30 ) ) ;
snprintf ( V_49 , V_47 , L_6 , F_24 ( V_30 ) ) ;
F_2 ( V_2 , V_17 ) ;
V_17 -> V_56 . V_57 = V_48 ;
V_17 -> V_56 . V_58 = F_21 ;
V_17 -> V_56 . V_59 = F_22 ;
V_17 -> V_56 . V_30 = V_30 ;
F_30 ( V_30 , & V_17 -> V_56 ) ;
V_17 -> V_42 . V_57 = V_49 ;
V_17 -> V_42 . V_58 = F_21 ;
V_17 -> V_42 . V_59 = F_22 ;
V_17 -> V_42 . V_30 = V_30 ;
F_30 ( V_30 , & V_17 -> V_42 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
int V_62 ;
V_62 = F_32 ( V_2 ) ;
if ( V_62 ) {
F_29 ( V_2 , L_7 ) ;
goto V_63;
}
V_62 = F_33 ( V_2 , V_64 ) ;
if ( V_62 ) {
F_29 ( V_2 , L_8 ) ;
goto V_63;
}
if ( F_5 ( V_2 ) ) {
F_2 ( V_2 , NULL ) ;
V_62 = F_23 ( V_2 ) ;
if ( V_62 )
goto V_65;
}
return 0 ;
V_65:
F_34 ( V_2 ) ;
V_63:
return V_62 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
F_36 ( & V_2 -> V_30 . V_52 ,
& V_53 ) ;
F_37 ( & V_17 -> V_42 ) ;
F_37 ( & V_17 -> V_56 ) ;
F_2 ( V_2 , NULL ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
F_35 ( V_2 ) ;
F_34 ( V_2 ) ;
}
