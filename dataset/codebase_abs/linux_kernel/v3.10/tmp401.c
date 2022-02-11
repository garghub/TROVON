static int F_1 ( T_1 V_1 , T_2 V_2 )
{
int V_3 = V_1 ;
if ( V_2 & V_4 )
V_3 -= 64 * 256 ;
return F_2 ( V_3 * 125 , 32 ) ;
}
static T_1 F_3 ( long V_3 , T_2 V_2 , int V_5 )
{
if ( V_2 & V_4 ) {
V_3 = F_4 ( V_3 , - 64000 , 191000 ) ;
V_3 += 64000 ;
} else
V_3 = F_4 ( V_3 , 0 , 127000 ) ;
return F_2 ( V_3 * ( 1 << ( 8 - V_5 ) ) , 1000 ) << V_5 ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_10 , V_11 , V_12 ;
int V_13 = V_9 -> V_14 == V_15 ? 6 : 4 ;
int V_16 = V_9 -> V_14 == V_17 ? 3 : 2 ;
for ( V_10 = 0 ; V_10 < V_16 ; V_10 ++ ) {
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
T_2 V_18 ;
V_18 = V_9 -> V_14 == V_17 ?
V_19 [ V_11 ] [ V_10 ] :
V_20 [ V_11 ] [ V_10 ] ;
V_12 = F_6 ( V_7 , V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
V_9 -> V_3 [ V_11 ] [ V_10 ] = V_12 << 8 ;
if ( V_11 == 3 )
continue;
V_18 = V_9 -> V_14 == V_17 ? V_21 [ V_11 ] [ V_10 ]
: V_22 [ V_11 ] [ V_10 ] ;
V_12 = F_6 ( V_7 , V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
V_9 -> V_3 [ V_11 ] [ V_10 ] |= V_12 ;
}
}
return 0 ;
}
static struct V_8 * F_7 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
struct V_8 * V_25 = V_9 ;
int V_10 , V_12 ;
unsigned long V_26 ;
F_10 ( & V_9 -> V_27 ) ;
V_26 = V_9 -> V_28 +
F_11 ( V_9 -> V_29 ) ;
if ( F_12 ( V_30 , V_26 ) || ! V_9 -> V_31 ) {
if ( V_9 -> V_14 != V_17 ) {
V_12 = F_6 ( V_7 , V_32 ) ;
if ( V_12 < 0 ) {
V_25 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_33 [ 0 ] =
( V_12 & V_34 ) >> 1 ;
V_9 -> V_33 [ 1 ] =
( ( V_12 & V_35 ) >> 2 ) |
( ( V_12 & V_36 ) >> 5 ) ;
V_9 -> V_33 [ 2 ] =
( ( V_12 & V_37 ) >> 3 ) |
( ( V_12 & V_38 ) >> 6 ) ;
V_9 -> V_33 [ 3 ] = V_12 & ( V_39
| V_40 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_14 ( V_9 -> V_33 ) ; V_10 ++ ) {
V_12 = F_6 ( V_7 ,
V_41 [ V_10 ] ) ;
if ( V_12 < 0 ) {
V_25 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_33 [ V_10 ] = V_12 ;
}
}
V_12 = F_6 ( V_7 , V_42 ) ;
if ( V_12 < 0 ) {
V_25 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_2 = V_12 ;
V_12 = F_5 ( V_7 , V_9 ) ;
if ( V_12 < 0 ) {
V_25 = F_13 ( V_12 ) ;
goto abort;
}
V_12 = F_6 ( V_7 , V_43 ) ;
if ( V_12 < 0 ) {
V_25 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_44 = V_12 ;
V_9 -> V_28 = V_30 ;
V_9 -> V_31 = 1 ;
}
abort:
F_15 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_16 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_48 = F_17 ( V_46 ) -> V_48 ;
int V_49 = F_17 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
return sprintf ( V_47 , L_1 ,
F_1 ( V_9 -> V_3 [ V_48 ] [ V_49 ] , V_9 -> V_2 ) ) ;
}
static T_3 F_20 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_3 , V_49 = F_21 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
F_10 ( & V_9 -> V_27 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_49 ] , V_9 -> V_2 ) ;
V_3 -= V_9 -> V_44 * 1000 ;
F_15 ( & V_9 -> V_27 ) ;
return sprintf ( V_47 , L_1 , V_3 ) ;
}
static T_3 F_22 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_48 = F_17 ( V_46 ) -> V_48 ;
int V_50 = F_17 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
return sprintf ( V_47 , L_1 , ! ! ( V_9 -> V_33 [ V_48 ] & V_50 ) ) ;
}
static T_3 F_23 ( struct V_23 * V_24 , struct V_45 * V_46 ,
const char * V_47 , T_4 V_51 )
{
int V_48 = F_17 ( V_46 ) -> V_48 ;
int V_49 = F_17 ( V_46 ) -> V_49 ;
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
long V_12 ;
T_1 V_1 ;
T_2 V_18 ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
if ( F_24 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
V_1 = F_3 ( V_12 , V_9 -> V_2 , V_48 == 3 ? 8 : 4 ) ;
F_10 ( & V_9 -> V_27 ) ;
V_18 = V_9 -> V_14 == V_17 ? V_53 [ V_48 ] [ V_49 ]
: V_54 [ V_48 ] [ V_49 ] ;
F_25 ( V_7 , V_18 , V_1 >> 8 ) ;
if ( V_48 != 3 ) {
V_18 = V_9 -> V_14 == V_17 ? V_21 [ V_48 ] [ V_49 ]
: V_22 [ V_48 ] [ V_49 ] ;
F_25 ( V_7 , V_18 , V_1 & 0xFF ) ;
}
V_9 -> V_3 [ V_48 ] [ V_49 ] = V_1 ;
F_15 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_26 ( struct V_23 * V_24 , struct V_45
* V_46 , const char * V_47 , T_4 V_51 )
{
int V_3 , V_49 = F_21 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
long V_12 ;
T_2 V_1 ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
if ( F_24 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
if ( V_9 -> V_2 & V_4 )
V_12 = F_4 ( V_12 , - 64000 , 191000 ) ;
else
V_12 = F_4 ( V_12 , 0 , 127000 ) ;
F_10 ( & V_9 -> V_27 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_49 ] , V_9 -> V_2 ) ;
V_12 = F_4 ( V_12 , V_3 - 255000 , V_3 ) ;
V_1 = ( ( V_3 - V_12 ) + 500 ) / 1000 ;
F_25 ( F_8 ( V_24 ) , V_43 ,
V_1 ) ;
V_9 -> V_44 = V_1 ;
F_15 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_27 ( struct V_23 * V_24 ,
struct V_45 * V_46 , const char * V_47 , T_4 V_51 )
{
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
long V_12 ;
if ( F_24 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
if ( V_12 != 1 ) {
F_28 ( V_24 ,
L_2 ,
V_12 ) ;
return - V_52 ;
}
F_10 ( & V_9 -> V_27 ) ;
F_25 ( V_7 , V_54 [ 5 ] [ 0 ] , V_12 ) ;
V_9 -> V_31 = 0 ;
F_15 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_29 ( struct V_23 * V_24 ,
struct V_45 * V_55 , char * V_47 )
{
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
return sprintf ( V_47 , L_3 , V_9 -> V_29 ) ;
}
static T_3 F_30 ( struct V_23 * V_24 ,
struct V_45 * V_55 ,
const char * V_47 , T_4 V_51 )
{
struct V_6 * V_7 = F_8 ( V_24 ) ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
unsigned long V_12 ;
int V_56 , V_57 ;
V_56 = F_31 ( V_47 , 10 , & V_12 ) ;
if ( V_56 )
return V_56 ;
V_12 = F_4 ( V_12 , 125 , 16000 ) ;
V_57 = 7 - F_32 ( V_12 * 4 / ( 125 * 3 ) ) ;
F_10 ( & V_9 -> V_27 ) ;
F_25 ( V_7 , V_58 , V_57 ) ;
V_9 -> V_29 = ( 1 << ( 7 - V_57 ) ) * 125 ;
F_15 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static void F_33 ( struct V_6 * V_7 )
{
int V_2 , V_59 ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
F_25 ( V_7 , V_58 , 5 ) ;
V_9 -> V_29 = 500 ;
V_2 = F_6 ( V_7 , V_42 ) ;
if ( V_2 < 0 ) {
F_34 ( & V_7 -> V_24 , L_4 ) ;
return;
}
V_59 = V_2 ;
V_2 &= ~ V_60 ;
if ( V_2 != V_59 )
F_25 ( V_7 , V_61 , V_2 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_62 * V_63 )
{
enum V_64 V_14 ;
struct V_65 * V_66 = V_7 -> V_66 ;
T_2 V_1 ;
if ( ! F_36 ( V_66 , V_67 ) )
return - V_68 ;
V_1 = F_6 ( V_7 , V_69 ) ;
if ( V_1 != V_70 )
return - V_68 ;
V_1 = F_6 ( V_7 , V_71 ) ;
switch ( V_1 ) {
case V_72 :
if ( V_7 -> V_73 != 0x4c )
return - V_68 ;
V_14 = V_74 ;
break;
case V_75 :
if ( V_7 -> V_73 != 0x4c )
return - V_68 ;
V_14 = V_15 ;
break;
case V_76 :
if ( V_7 -> V_73 != 0x4d )
return - V_68 ;
V_14 = V_15 ;
break;
case V_77 :
if ( V_7 -> V_73 != 0x4e )
return - V_68 ;
V_14 = V_15 ;
break;
case V_78 :
if ( V_7 -> V_73 == 0x4e )
return - V_68 ;
V_14 = V_79 ;
break;
case V_80 :
if ( V_7 -> V_73 == 0x4e )
return - V_68 ;
V_14 = V_17 ;
break;
default:
return - V_68 ;
}
V_1 = F_6 ( V_7 , V_42 ) ;
if ( V_1 & 0x1b )
return - V_68 ;
V_1 = F_6 ( V_7 , V_81 ) ;
if ( V_1 > 15 )
return - V_68 ;
F_37 ( V_63 -> type , V_82 [ V_14 ] . V_83 , V_84 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_23 * V_24 = & V_7 -> V_24 ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
if ( V_9 -> V_85 )
F_39 ( V_9 -> V_85 ) ;
F_40 ( & V_24 -> V_86 , & V_87 ) ;
if ( V_9 -> V_14 == V_15 )
F_40 ( & V_24 -> V_86 , & V_88 ) ;
if ( V_9 -> V_14 == V_17 )
F_40 ( & V_24 -> V_86 , & V_89 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 ,
const struct V_90 * V_91 )
{
struct V_23 * V_24 = & V_7 -> V_24 ;
int V_56 ;
struct V_8 * V_9 ;
const char * V_92 [] = { L_5 , L_6 , L_7 , L_8 } ;
V_9 = F_42 ( V_24 , sizeof( struct V_8 ) , V_93 ) ;
if ( ! V_9 )
return - V_94 ;
F_43 ( V_7 , V_9 ) ;
F_44 ( & V_9 -> V_27 ) ;
V_9 -> V_14 = V_91 -> V_95 ;
F_33 ( V_7 ) ;
V_56 = F_45 ( & V_24 -> V_86 , & V_87 ) ;
if ( V_56 )
return V_56 ;
if ( V_9 -> V_14 == V_15 ) {
V_56 = F_45 ( & V_24 -> V_86 , & V_88 ) ;
if ( V_56 )
goto V_96;
}
if ( V_9 -> V_14 == V_17 ) {
V_56 = F_45 ( & V_24 -> V_86 , & V_89 ) ;
if ( V_56 )
goto V_96;
}
V_9 -> V_85 = F_46 ( V_24 ) ;
if ( F_18 ( V_9 -> V_85 ) ) {
V_56 = F_19 ( V_9 -> V_85 ) ;
V_9 -> V_85 = NULL ;
goto V_96;
}
F_47 ( V_24 , L_9 , V_92 [ V_9 -> V_14 ] ) ;
return 0 ;
V_96:
F_38 ( V_7 ) ;
return V_56 ;
}
