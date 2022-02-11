static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned long * * V_9 , int * V_10 )
{
struct V_11 * V_12 ;
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_12 -> V_14 == 1 && V_8 -> V_15 == ( V_16 | 0x0010 ) ) {
F_2 ( V_17 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
V_19 = V_2 -> V_22 [ V_23 ] . V_24 [ 4 ] ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] = V_21 -> V_26 ? 0x01 : 0x02 ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] |= V_21 -> V_27 ? 0x04 : 0x08 ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] |= V_21 -> V_28 ? 0x10 : 0x20 ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] |= V_21 -> V_29 ? 0x80 : 0x40 ;
V_19 -> V_6 [ 1 ] -> V_25 [ 0 ] = 0x03 ;
V_19 -> V_6 [ 2 ] -> V_25 [ 0 ] = V_21 -> V_30 ;
V_19 -> V_6 [ 3 ] -> V_25 [ 0 ] = V_21 -> V_31 ;
F_5 ( V_2 , V_19 , V_32 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 , V_21 -> V_26 ) ;
}
static T_1 F_8 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_41 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_41 ;
V_21 -> V_26 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static T_1 F_10 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 , V_21 -> V_27 ) ;
}
static T_1 F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_41 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_41 ;
V_21 -> V_27 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static T_1 F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 , V_21 -> V_28 ) ;
}
static T_1 F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_41 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_41 ;
V_21 -> V_28 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static T_1 F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 , V_21 -> V_29 ) ;
}
static T_1 F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_41 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_41 ;
V_21 -> V_29 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static T_1 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 ,
V_21 -> V_30 ) ;
}
static T_1 F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) || V_25 < 1 || V_25 > 255 )
return - V_41 ;
V_21 -> V_30 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static T_1 F_18 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
return snprintf ( V_37 , V_39 , L_1 ,
V_21 -> V_31 ) ;
}
static T_1 F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_40 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_25 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
if ( V_2 == NULL )
return - V_38 ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( F_9 ( V_37 , 10 , & V_25 ) || V_25 < 1 || V_25 > 255 )
return - V_41 ;
V_21 -> V_31 = V_25 ;
F_3 ( V_2 ) ;
return V_40 ;
}
static enum V_42 F_20 (
struct V_43 * V_44 )
{
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_45 = 0 ;
V_34 = V_44 -> V_34 -> V_46 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( V_44 == & V_21 -> V_47 )
V_45 = 1 ;
return V_21 -> V_48 & ( 1 << V_45 )
? V_49
: V_50 ;
}
static void F_21 ( struct V_43 * V_44 ,
enum V_42 V_25 )
{
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_45 = 0 ;
V_34 = V_44 -> V_34 -> V_46 ;
V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
if ( V_44 == & V_21 -> V_47 )
V_45 = 1 ;
if ( V_25 == V_50 )
V_21 -> V_48 &= ~ ( 1 << V_45 ) ;
else
V_21 -> V_48 |= 1 << V_45 ;
V_19 = V_2 -> V_22 [ V_51 ] . V_24 [ 3 ] ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] = ( V_21 -> V_48 >> 0 ) & 1 ;
V_19 -> V_6 [ 0 ] -> V_25 [ 1 ] = ( V_21 -> V_48 >> 1 ) & 1 ;
F_5 ( V_2 , V_19 , V_32 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_34 ;
struct V_20 * V_21 ;
T_2 V_52 = strlen ( F_23 ( V_34 ) ) + 16 ;
char * V_53 , * V_54 ;
int V_55 ;
if ( F_24 ( & V_2 -> V_34 . V_56 ,
& V_57 ) ) {
F_25 ( V_2 , L_2 ) ;
}
V_21 = F_26 ( sizeof( struct V_20 ) , V_58 ) ;
if ( V_21 == NULL ) {
F_27 ( V_2 , L_3 ) ;
return - V_59 ;
}
V_21 -> V_30 = 0xa0 ;
V_21 -> V_31 = 0x38 ;
V_53 = F_26 ( V_52 , V_58 ) ;
if ( V_53 == NULL ) {
F_27 ( V_2 , L_4 ) ;
V_55 = - V_59 ;
goto V_60;
}
snprintf ( V_53 , V_52 , L_5 , F_23 ( V_34 ) ) ;
V_54 = F_26 ( V_52 , V_58 ) ;
if ( V_54 == NULL ) {
F_27 ( V_2 , L_4 ) ;
V_55 = - V_59 ;
goto V_61;
}
snprintf ( V_54 , V_52 , L_6 , F_23 ( V_34 ) ) ;
F_28 ( V_2 , V_21 ) ;
V_21 -> V_62 . V_63 = V_53 ;
V_21 -> V_62 . V_64 = F_20 ;
V_21 -> V_62 . V_65 = F_21 ;
V_21 -> V_62 . V_34 = V_34 ;
F_29 ( V_34 , & V_21 -> V_62 ) ;
V_21 -> V_47 . V_63 = V_54 ;
V_21 -> V_47 . V_64 = F_20 ;
V_21 -> V_47 . V_65 = F_21 ;
V_21 -> V_47 . V_34 = V_34 ;
F_29 ( V_34 , & V_21 -> V_47 ) ;
F_3 ( V_2 ) ;
return 0 ;
V_61:
F_30 ( V_53 ) ;
V_60:
F_30 ( V_21 ) ;
return V_55 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
int V_55 ;
struct V_11 * V_12 ;
V_55 = F_32 ( V_2 ) ;
if ( V_55 ) {
F_27 ( V_2 , L_7 ) ;
goto V_68;
}
V_55 = F_33 ( V_2 , V_69 ) ;
if ( V_55 ) {
F_27 ( V_2 , L_8 ) ;
goto V_68;
}
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_12 -> V_14 == 1 )
return F_22 ( V_2 ) ;
return 0 ;
V_68:
return V_55 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
F_35 ( & V_2 -> V_34 . V_56 ,
& V_57 ) ;
V_21 = (struct V_20 * ) F_4 ( V_2 ) ;
F_36 ( & V_21 -> V_47 ) ;
F_36 ( & V_21 -> V_62 ) ;
F_28 ( V_2 , NULL ) ;
F_30 ( V_21 -> V_47 . V_63 ) ;
F_30 ( V_21 -> V_62 . V_63 ) ;
F_30 ( V_21 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_12 -> V_14 == 1 )
F_34 ( V_2 ) ;
F_38 ( V_2 ) ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_70 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_70 ) ;
}
