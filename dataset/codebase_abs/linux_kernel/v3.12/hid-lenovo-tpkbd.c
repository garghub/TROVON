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
struct V_20 * V_21 = F_4 ( V_2 ) ;
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
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 , V_21 -> V_26 ) ;
}
static T_1 F_8 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_40 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_40 ;
V_21 -> V_26 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static T_1 F_10 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 , V_21 -> V_27 ) ;
}
static T_1 F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_40 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_40 ;
V_21 -> V_27 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static T_1 F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 , V_21 -> V_28 ) ;
}
static T_1 F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_40 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_40 ;
V_21 -> V_28 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static T_1 F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 , V_21 -> V_29 ) ;
}
static T_1 F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) )
return - V_40 ;
if ( V_25 < 0 || V_25 > 1 )
return - V_40 ;
V_21 -> V_29 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static T_1 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 ,
V_21 -> V_30 ) ;
}
static T_1 F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) || V_25 < 1 || V_25 > 255 )
return - V_40 ;
V_21 -> V_30 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static T_1 F_18 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
return snprintf ( V_37 , V_38 , L_1 ,
V_21 -> V_31 ) ;
}
static T_1 F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_2 V_39 )
{
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_25 ;
if ( F_9 ( V_37 , 10 , & V_25 ) || V_25 < 1 || V_25 > 255 )
return - V_40 ;
V_21 -> V_31 = V_25 ;
F_3 ( V_2 ) ;
return V_39 ;
}
static enum V_41 F_20 (
struct V_42 * V_43 )
{
struct V_33 * V_34 = V_43 -> V_34 -> V_44 ;
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
int V_45 = 0 ;
if ( V_43 == & V_21 -> V_46 )
V_45 = 1 ;
return V_21 -> V_47 & ( 1 << V_45 )
? V_48
: V_49 ;
}
static void F_21 ( struct V_42 * V_43 ,
enum V_41 V_25 )
{
struct V_33 * V_34 = V_43 -> V_34 -> V_44 ;
struct V_1 * V_2 = F_7 ( V_34 , struct V_1 , V_34 ) ;
struct V_20 * V_21 = F_4 ( V_2 ) ;
struct V_18 * V_19 ;
int V_45 = 0 ;
if ( V_43 == & V_21 -> V_46 )
V_45 = 1 ;
if ( V_25 == V_49 )
V_21 -> V_47 &= ~ ( 1 << V_45 ) ;
else
V_21 -> V_47 |= 1 << V_45 ;
V_19 = V_2 -> V_22 [ V_50 ] . V_24 [ 3 ] ;
V_19 -> V_6 [ 0 ] -> V_25 [ 0 ] = ( V_21 -> V_47 >> 0 ) & 1 ;
V_19 -> V_6 [ 0 ] -> V_25 [ 1 ] = ( V_21 -> V_47 >> 1 ) & 1 ;
F_5 ( V_2 , V_19 , V_32 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_34 ;
struct V_20 * V_21 ;
T_2 V_51 = strlen ( F_23 ( V_34 ) ) + 16 ;
char * V_52 , * V_53 ;
int V_54 , V_55 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
if ( ! F_24 ( V_2 , V_23 , 4 , V_54 , 1 ) )
return - V_56 ;
}
if ( ! F_24 ( V_2 , V_50 , 3 , 0 , 2 ) )
return - V_56 ;
if ( F_25 ( & V_2 -> V_34 . V_57 ,
& V_58 ) ) {
F_26 ( V_2 , L_2 ) ;
}
V_21 = F_27 ( sizeof( struct V_20 ) , V_59 ) ;
if ( V_21 == NULL ) {
F_28 ( V_2 , L_3 ) ;
return - V_60 ;
}
V_21 -> V_30 = 0xa0 ;
V_21 -> V_31 = 0x38 ;
V_52 = F_27 ( V_51 , V_59 ) ;
if ( V_52 == NULL ) {
F_28 ( V_2 , L_4 ) ;
V_55 = - V_60 ;
goto V_61;
}
snprintf ( V_52 , V_51 , L_5 , F_23 ( V_34 ) ) ;
V_53 = F_27 ( V_51 , V_59 ) ;
if ( V_53 == NULL ) {
F_28 ( V_2 , L_4 ) ;
V_55 = - V_60 ;
goto V_62;
}
snprintf ( V_53 , V_51 , L_6 , F_23 ( V_34 ) ) ;
F_29 ( V_2 , V_21 ) ;
V_21 -> V_63 . V_64 = V_52 ;
V_21 -> V_63 . V_65 = F_20 ;
V_21 -> V_63 . V_66 = F_21 ;
V_21 -> V_63 . V_34 = V_34 ;
F_30 ( V_34 , & V_21 -> V_63 ) ;
V_21 -> V_46 . V_64 = V_53 ;
V_21 -> V_46 . V_65 = F_20 ;
V_21 -> V_46 . V_66 = F_21 ;
V_21 -> V_46 . V_34 = V_34 ;
F_30 ( V_34 , & V_21 -> V_46 ) ;
F_3 ( V_2 ) ;
return 0 ;
V_62:
F_31 ( V_52 ) ;
V_61:
F_31 ( V_21 ) ;
return V_55 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
int V_55 ;
struct V_11 * V_12 ;
V_55 = F_33 ( V_2 ) ;
if ( V_55 ) {
F_28 ( V_2 , L_7 ) ;
goto V_61;
}
V_55 = F_34 ( V_2 , V_69 ) ;
if ( V_55 ) {
F_28 ( V_2 , L_8 ) ;
goto V_61;
}
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_12 -> V_14 == 1 ) {
V_55 = F_22 ( V_2 ) ;
if ( V_55 )
goto V_70;
}
return 0 ;
V_70:
F_35 ( V_2 ) ;
V_61:
return V_55 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_4 ( V_2 ) ;
F_37 ( & V_2 -> V_34 . V_57 ,
& V_58 ) ;
F_38 ( & V_21 -> V_46 ) ;
F_38 ( & V_21 -> V_63 ) ;
F_29 ( V_2 , NULL ) ;
F_31 ( V_21 -> V_46 . V_64 ) ;
F_31 ( V_21 -> V_63 . V_64 ) ;
F_31 ( V_21 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_12 -> V_14 == 1 )
F_36 ( V_2 ) ;
F_35 ( V_2 ) ;
}
