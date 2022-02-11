static int F_1 ( T_1 V_1 , T_2 V_2 )
{
int V_3 = V_1 ;
if ( V_2 & V_4 )
V_3 -= 64 * 256 ;
return ( V_3 * 625 + 80 ) / 160 ;
}
static T_1 F_2 ( long V_3 , T_2 V_2 )
{
if ( V_2 & V_4 ) {
V_3 = F_3 ( V_3 , - 64000 , 191000 ) ;
V_3 += 64000 ;
} else
V_3 = F_3 ( V_3 , 0 , 127000 ) ;
return ( V_3 * 160 + 312 ) / 625 ;
}
static int F_4 ( T_2 V_1 , T_2 V_2 )
{
int V_3 = V_1 ;
if ( V_2 & V_4 )
V_3 -= 64 ;
return V_3 * 1000 ;
}
static T_2 F_5 ( long V_3 , T_2 V_2 )
{
if ( V_2 & V_4 ) {
V_3 = F_3 ( V_3 , - 64000 , 191000 ) ;
V_3 += 64000 ;
} else
V_3 = F_3 ( V_3 , 0 , 127000 ) ;
return ( V_3 + 500 ) / 1000 ;
}
static struct V_5 * F_6 (
struct V_6 * V_7 , struct V_5 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_8 -> V_3 [ V_9 ] = F_7 ( V_7 ,
V_10 [ V_9 ] ) << 8 ;
V_8 -> V_3 [ V_9 ] |= F_7 ( V_7 ,
V_11 [ V_9 ] ) ;
V_8 -> V_12 [ V_9 ] = F_7 ( V_7 ,
V_13 [ V_9 ] ) << 8 ;
V_8 -> V_12 [ V_9 ] |= F_7 ( V_7 ,
V_14 [ V_9 ] ) ;
V_8 -> V_15 [ V_9 ] = F_7 ( V_7 ,
V_16 [ V_9 ] ) << 8 ;
V_8 -> V_15 [ V_9 ] |= F_7 ( V_7 ,
V_17 [ V_9 ] ) ;
V_8 -> V_18 [ V_9 ] = F_7 ( V_7 ,
V_19 [ V_9 ] ) ;
if ( V_8 -> V_20 == V_21 ) {
V_8 -> V_22 [ V_9 ] = F_7 ( V_7 ,
V_23 [ V_9 ] ) << 8 ;
V_8 -> V_22 [ V_9 ] |= F_7 (
V_7 , V_24 [ V_9 ] ) ;
V_8 -> V_25 [ V_9 ] = F_7 (
V_7 , V_26 [ V_9 ] ) << 8 ;
V_8 -> V_25 [ V_9 ] |= F_7 (
V_7 , V_27 [ V_9 ] ) ;
}
}
return V_8 ;
}
static struct V_5 * F_8 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = F_9 ( V_29 ) ;
struct V_5 * V_8 = F_10 ( V_7 ) ;
F_11 ( & V_8 -> V_30 ) ;
if ( F_12 ( V_31 , V_8 -> V_32 + V_33 ) || ! V_8 -> V_34 ) {
V_8 -> V_35 = F_7 ( V_7 , V_36 ) ;
V_8 -> V_2 = F_7 ( V_7 ,
V_37 ) ;
F_6 ( V_7 , V_8 ) ;
V_8 -> V_38 = F_7 ( V_7 ,
V_39 ) ;
V_8 -> V_32 = V_31 ;
V_8 -> V_34 = 1 ;
}
F_13 ( & V_8 -> V_30 ) ;
return V_8 ;
}
static T_3 F_14 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_1 ( V_8 -> V_3 [ V_43 ] , V_8 -> V_2 ) ) ;
}
static T_3 F_16 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_1 ( V_8 -> V_12 [ V_43 ] , V_8 -> V_2 ) ) ;
}
static T_3 F_17 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_1 ( V_8 -> V_15 [ V_43 ] , V_8 -> V_2 ) ) ;
}
static T_3 F_18 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_4 ( V_8 -> V_18 [ V_43 ] ,
V_8 -> V_2 ) ) ;
}
static T_3 F_19 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_3 , V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
F_11 ( & V_8 -> V_30 ) ;
V_3 = F_4 ( V_8 -> V_18 [ V_43 ] ,
V_8 -> V_2 ) ;
V_3 -= V_8 -> V_38 * 1000 ;
F_13 ( & V_8 -> V_30 ) ;
return sprintf ( V_42 , L_1 , V_3 ) ;
}
static T_3 F_20 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_1 ( V_8 -> V_22 [ V_43 ] ,
V_8 -> V_2 ) ) ;
}
static T_3 F_21 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
return sprintf ( V_42 , L_1 ,
F_1 ( V_8 -> V_25 [ V_43 ] ,
V_8 -> V_2 ) ) ;
}
static T_3 F_22 ( struct V_28 * V_29 ,
struct V_40 * V_41 , char * V_42 )
{
int V_44 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
if ( V_8 -> V_35 & V_44 )
return sprintf ( V_42 , L_2 ) ;
else
return sprintf ( V_42 , L_3 ) ;
}
static T_3 F_23 ( struct V_28 * V_29 , struct V_40
* V_41 , const char * V_42 , T_4 V_45 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
long V_46 ;
T_1 V_1 ;
if ( F_24 ( V_42 , 10 , & V_46 ) )
return - V_47 ;
V_1 = F_2 ( V_46 , V_8 -> V_2 ) ;
F_11 ( & V_8 -> V_30 ) ;
F_25 ( F_9 ( V_29 ) ,
V_48 [ V_43 ] , V_1 >> 8 ) ;
F_25 ( F_9 ( V_29 ) ,
V_14 [ V_43 ] , V_1 & 0xFF ) ;
V_8 -> V_12 [ V_43 ] = V_1 ;
F_13 ( & V_8 -> V_30 ) ;
return V_45 ;
}
static T_3 F_26 ( struct V_28 * V_29 , struct V_40
* V_41 , const char * V_42 , T_4 V_45 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
long V_46 ;
T_1 V_1 ;
if ( F_24 ( V_42 , 10 , & V_46 ) )
return - V_47 ;
V_1 = F_2 ( V_46 , V_8 -> V_2 ) ;
F_11 ( & V_8 -> V_30 ) ;
F_25 ( F_9 ( V_29 ) ,
V_49 [ V_43 ] , V_1 >> 8 ) ;
F_25 ( F_9 ( V_29 ) ,
V_17 [ V_43 ] , V_1 & 0xFF ) ;
V_8 -> V_15 [ V_43 ] = V_1 ;
F_13 ( & V_8 -> V_30 ) ;
return V_45 ;
}
static T_3 F_27 ( struct V_28 * V_29 , struct V_40
* V_41 , const char * V_42 , T_4 V_45 )
{
int V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
long V_46 ;
T_2 V_1 ;
if ( F_24 ( V_42 , 10 , & V_46 ) )
return - V_47 ;
V_1 = F_5 ( V_46 , V_8 -> V_2 ) ;
F_11 ( & V_8 -> V_30 ) ;
F_25 ( F_9 ( V_29 ) ,
V_19 [ V_43 ] , V_1 ) ;
V_8 -> V_18 [ V_43 ] = V_1 ;
F_13 ( & V_8 -> V_30 ) ;
return V_45 ;
}
static T_3 F_28 ( struct V_28 * V_29 , struct V_40
* V_41 , const char * V_42 , T_4 V_45 )
{
int V_3 , V_43 = F_15 ( V_41 ) -> V_43 ;
struct V_5 * V_8 = F_8 ( V_29 ) ;
long V_46 ;
T_2 V_1 ;
if ( F_24 ( V_42 , 10 , & V_46 ) )
return - V_47 ;
if ( V_8 -> V_2 & V_4 )
V_46 = F_3 ( V_46 , - 64000 , 191000 ) ;
else
V_46 = F_3 ( V_46 , 0 , 127000 ) ;
F_11 ( & V_8 -> V_30 ) ;
V_3 = F_4 ( V_8 -> V_18 [ V_43 ] ,
V_8 -> V_2 ) ;
V_46 = F_3 ( V_46 , V_3 - 255000 , V_3 ) ;
V_1 = ( ( V_3 - V_46 ) + 500 ) / 1000 ;
F_25 ( F_9 ( V_29 ) ,
V_39 , V_1 ) ;
V_8 -> V_38 = V_1 ;
F_13 ( & V_8 -> V_30 ) ;
return V_45 ;
}
static T_3 F_29 ( struct V_28 * V_29 ,
struct V_40 * V_41 , const char * V_42 , T_4 V_45 )
{
long V_46 ;
if ( F_24 ( V_42 , 10 , & V_46 ) )
return - V_47 ;
if ( V_46 != 1 ) {
F_30 ( V_29 , L_4
L_5 , V_46 ) ;
return - V_47 ;
}
F_25 ( F_9 ( V_29 ) ,
V_23 [ 0 ] , V_46 ) ;
return V_45 ;
}
static void F_31 ( struct V_6 * V_7 )
{
int V_2 , V_50 ;
F_25 ( V_7 , V_51 , 5 ) ;
V_2 = F_7 ( V_7 , V_37 ) ;
if ( V_2 < 0 ) {
F_32 ( & V_7 -> V_29 , L_6 ) ;
return;
}
V_50 = V_2 ;
V_2 &= ~ V_52 ;
if ( V_2 != V_50 )
F_25 ( V_7 , V_53 , V_2 ) ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
enum V_56 V_20 ;
struct V_57 * V_58 = V_7 -> V_58 ;
T_2 V_1 ;
if ( ! F_34 ( V_58 , V_59 ) )
return - V_60 ;
V_1 = F_7 ( V_7 , V_61 ) ;
if ( V_1 != V_62 )
return - V_60 ;
V_1 = F_7 ( V_7 , V_63 ) ;
switch ( V_1 ) {
case V_64 :
V_20 = V_65 ;
break;
case V_66 :
V_20 = V_21 ;
break;
default:
return - V_60 ;
}
V_1 = F_7 ( V_7 , V_37 ) ;
if ( V_1 & 0x1b )
return - V_60 ;
V_1 = F_7 ( V_7 , V_67 ) ;
if ( V_1 > 15 )
return - V_60 ;
F_35 ( V_55 -> type , V_68 [ V_20 ] . V_69 , V_70 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_5 * V_8 = F_10 ( V_7 ) ;
int V_9 ;
if ( V_8 -> V_71 )
F_37 ( V_8 -> V_71 ) ;
for ( V_9 = 0 ; V_9 < F_38 ( V_72 ) ; V_9 ++ )
F_39 ( & V_7 -> V_29 , & V_72 [ V_9 ] . V_73 ) ;
if ( V_8 -> V_20 == V_21 ) {
for ( V_9 = 0 ; V_9 < F_38 ( V_74 ) ; V_9 ++ )
F_39 ( & V_7 -> V_29 ,
& V_74 [ V_9 ] . V_73 ) ;
}
F_40 ( V_8 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 ,
const struct V_75 * V_76 )
{
int V_9 , V_77 = 0 ;
struct V_5 * V_8 ;
const char * V_78 [] = { L_7 , L_8 } ;
V_8 = F_42 ( sizeof( struct V_5 ) , V_79 ) ;
if ( ! V_8 )
return - V_80 ;
F_43 ( V_7 , V_8 ) ;
F_44 ( & V_8 -> V_30 ) ;
V_8 -> V_20 = V_76 -> V_81 ;
F_31 ( V_7 ) ;
for ( V_9 = 0 ; V_9 < F_38 ( V_72 ) ; V_9 ++ ) {
V_77 = F_45 ( & V_7 -> V_29 ,
& V_72 [ V_9 ] . V_73 ) ;
if ( V_77 )
goto V_82;
}
if ( V_8 -> V_20 == V_21 ) {
for ( V_9 = 0 ; V_9 < F_38 ( V_74 ) ; V_9 ++ ) {
V_77 = F_45 ( & V_7 -> V_29 ,
& V_74 [ V_9 ] . V_73 ) ;
if ( V_77 )
goto V_82;
}
}
V_8 -> V_71 = F_46 ( & V_7 -> V_29 ) ;
if ( F_47 ( V_8 -> V_71 ) ) {
V_77 = F_48 ( V_8 -> V_71 ) ;
V_8 -> V_71 = NULL ;
goto V_82;
}
F_49 ( & V_7 -> V_29 , L_9 , V_78 [ V_8 -> V_20 ] ) ;
return 0 ;
V_82:
F_36 ( V_7 ) ;
return V_77 ;
}
