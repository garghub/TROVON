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
if ( V_11 == 3 ) {
V_12 = F_6 ( V_7 , V_18 ) ;
} else {
V_12 = F_7 ( V_7 ,
V_18 ) ;
}
if ( V_12 < 0 )
return V_12 ;
V_9 -> V_3 [ V_11 ] [ V_10 ] = V_11 == 3 ? V_12 << 8 : V_12 ;
}
}
return 0 ;
}
static struct V_8 * F_8 ( struct V_21 * V_22 )
{
struct V_8 * V_9 = F_9 ( V_22 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_8 * V_23 = V_9 ;
int V_10 , V_12 ;
unsigned long V_24 ;
F_10 ( & V_9 -> V_25 ) ;
V_24 = V_9 -> V_26 +
F_11 ( V_9 -> V_27 ) ;
if ( F_12 ( V_28 , V_24 ) || ! V_9 -> V_29 ) {
if ( V_9 -> V_14 != V_17 ) {
V_12 = F_6 ( V_7 , V_30 ) ;
if ( V_12 < 0 ) {
V_23 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_31 [ 0 ] =
( V_12 & V_32 ) >> 1 ;
V_9 -> V_31 [ 1 ] =
( ( V_12 & V_33 ) >> 2 ) |
( ( V_12 & V_34 ) >> 5 ) ;
V_9 -> V_31 [ 2 ] =
( ( V_12 & V_35 ) >> 3 ) |
( ( V_12 & V_36 ) >> 6 ) ;
V_9 -> V_31 [ 3 ] = V_12 & ( V_37
| V_38 ) ;
} else {
for ( V_10 = 0 ; V_10 < F_14 ( V_9 -> V_31 ) ; V_10 ++ ) {
V_12 = F_6 ( V_7 ,
V_39 [ V_10 ] ) ;
if ( V_12 < 0 ) {
V_23 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_31 [ V_10 ] = V_12 ;
}
}
V_12 = F_6 ( V_7 , V_40 ) ;
if ( V_12 < 0 ) {
V_23 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_2 = V_12 ;
V_12 = F_5 ( V_7 , V_9 ) ;
if ( V_12 < 0 ) {
V_23 = F_13 ( V_12 ) ;
goto abort;
}
V_12 = F_6 ( V_7 , V_41 ) ;
if ( V_12 < 0 ) {
V_23 = F_13 ( V_12 ) ;
goto abort;
}
V_9 -> V_42 = V_12 ;
V_9 -> V_26 = V_28 ;
V_9 -> V_29 = 1 ;
}
abort:
F_15 ( & V_9 -> V_25 ) ;
return V_23 ;
}
static T_3 F_16 ( struct V_21 * V_22 ,
struct V_43 * V_44 , char * V_45 )
{
int V_46 = F_17 ( V_44 ) -> V_46 ;
int V_47 = F_17 ( V_44 ) -> V_47 ;
struct V_8 * V_9 = F_8 ( V_22 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
return sprintf ( V_45 , L_1 ,
F_1 ( V_9 -> V_3 [ V_46 ] [ V_47 ] , V_9 -> V_2 ) ) ;
}
static T_3 F_20 ( struct V_21 * V_22 ,
struct V_43 * V_44 , char * V_45 )
{
int V_3 , V_47 = F_21 ( V_44 ) -> V_47 ;
struct V_8 * V_9 = F_8 ( V_22 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
F_10 ( & V_9 -> V_25 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_47 ] , V_9 -> V_2 ) ;
V_3 -= V_9 -> V_42 * 1000 ;
F_15 ( & V_9 -> V_25 ) ;
return sprintf ( V_45 , L_1 , V_3 ) ;
}
static T_3 F_22 ( struct V_21 * V_22 ,
struct V_43 * V_44 , char * V_45 )
{
int V_46 = F_17 ( V_44 ) -> V_46 ;
int V_48 = F_17 ( V_44 ) -> V_47 ;
struct V_8 * V_9 = F_8 ( V_22 ) ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
return sprintf ( V_45 , L_1 , ! ! ( V_9 -> V_31 [ V_46 ] & V_48 ) ) ;
}
static T_3 F_23 ( struct V_21 * V_22 , struct V_43 * V_44 ,
const char * V_45 , T_4 V_49 )
{
int V_46 = F_17 ( V_44 ) -> V_46 ;
int V_47 = F_17 ( V_44 ) -> V_47 ;
struct V_8 * V_9 = F_9 ( V_22 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
long V_12 ;
T_1 V_1 ;
T_2 V_18 ;
if ( F_24 ( V_45 , 10 , & V_12 ) )
return - V_50 ;
V_1 = F_3 ( V_12 , V_9 -> V_2 , V_46 == 3 ? 8 : 4 ) ;
F_10 ( & V_9 -> V_25 ) ;
V_18 = V_9 -> V_14 == V_17 ? V_51 [ V_46 ] [ V_47 ]
: V_52 [ V_46 ] [ V_47 ] ;
if ( V_46 == 3 ) {
F_25 ( V_7 , V_18 , V_1 >> 8 ) ;
} else {
F_26 ( V_7 , V_18 , V_1 ) ;
}
V_9 -> V_3 [ V_46 ] [ V_47 ] = V_1 ;
F_15 ( & V_9 -> V_25 ) ;
return V_49 ;
}
static T_3 F_27 ( struct V_21 * V_22 , struct V_43
* V_44 , const char * V_45 , T_4 V_49 )
{
int V_3 , V_47 = F_21 ( V_44 ) -> V_47 ;
struct V_8 * V_9 = F_8 ( V_22 ) ;
long V_12 ;
T_2 V_1 ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
if ( F_24 ( V_45 , 10 , & V_12 ) )
return - V_50 ;
if ( V_9 -> V_2 & V_4 )
V_12 = F_4 ( V_12 , - 64000 , 191000 ) ;
else
V_12 = F_4 ( V_12 , 0 , 127000 ) ;
F_10 ( & V_9 -> V_25 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_47 ] , V_9 -> V_2 ) ;
V_12 = F_4 ( V_12 , V_3 - 255000 , V_3 ) ;
V_1 = ( ( V_3 - V_12 ) + 500 ) / 1000 ;
F_25 ( V_9 -> V_7 , V_41 ,
V_1 ) ;
V_9 -> V_42 = V_1 ;
F_15 ( & V_9 -> V_25 ) ;
return V_49 ;
}
static T_3 F_28 ( struct V_21 * V_22 ,
struct V_43 * V_44 , const char * V_45 , T_4 V_49 )
{
struct V_8 * V_9 = F_9 ( V_22 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
long V_12 ;
if ( F_24 ( V_45 , 10 , & V_12 ) )
return - V_50 ;
if ( V_12 != 1 ) {
F_29 ( V_22 ,
L_2 ,
V_12 ) ;
return - V_50 ;
}
F_10 ( & V_9 -> V_25 ) ;
F_25 ( V_7 , V_52 [ 5 ] [ 0 ] , V_12 ) ;
V_9 -> V_29 = 0 ;
F_15 ( & V_9 -> V_25 ) ;
return V_49 ;
}
static T_3 F_30 ( struct V_21 * V_22 ,
struct V_43 * V_53 , char * V_45 )
{
struct V_8 * V_9 = F_9 ( V_22 ) ;
return sprintf ( V_45 , L_3 , V_9 -> V_27 ) ;
}
static T_3 F_31 ( struct V_21 * V_22 ,
struct V_43 * V_53 ,
const char * V_45 , T_4 V_49 )
{
struct V_8 * V_9 = F_9 ( V_22 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
unsigned long V_12 ;
int V_54 , V_55 ;
V_54 = F_32 ( V_45 , 10 , & V_12 ) ;
if ( V_54 )
return V_54 ;
V_12 = F_4 ( V_12 , 125 , 16000 ) ;
V_55 = 7 - F_33 ( V_12 * 4 / ( 125 * 3 ) ) ;
F_10 ( & V_9 -> V_25 ) ;
F_25 ( V_7 , V_56 , V_55 ) ;
V_9 -> V_27 = ( 1 << ( 7 - V_55 ) ) * 125 ;
F_15 ( & V_9 -> V_25 ) ;
return V_49 ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
int V_2 , V_57 , V_31 = 0 ;
F_25 ( V_7 , V_56 , 5 ) ;
V_9 -> V_27 = 500 ;
V_2 = F_6 ( V_7 , V_40 ) ;
if ( V_2 < 0 )
return V_2 ;
V_57 = V_2 ;
V_2 &= ~ V_58 ;
if ( V_2 != V_57 )
V_31 = F_25 ( V_7 ,
V_59 ,
V_2 ) ;
return V_31 ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_60 * V_61 )
{
enum V_62 V_14 ;
struct V_63 * V_64 = V_7 -> V_64 ;
T_2 V_1 ;
if ( ! F_36 ( V_64 , V_65 ) )
return - V_66 ;
V_1 = F_6 ( V_7 , V_67 ) ;
if ( V_1 != V_68 )
return - V_66 ;
V_1 = F_6 ( V_7 , V_69 ) ;
switch ( V_1 ) {
case V_70 :
if ( V_7 -> V_71 != 0x4c )
return - V_66 ;
V_14 = V_72 ;
break;
case V_73 :
if ( V_7 -> V_71 != 0x4c )
return - V_66 ;
V_14 = V_15 ;
break;
case V_74 :
if ( V_7 -> V_71 != 0x4d )
return - V_66 ;
V_14 = V_15 ;
break;
case V_75 :
if ( V_7 -> V_71 != 0x4e )
return - V_66 ;
V_14 = V_15 ;
break;
case V_76 :
if ( V_7 -> V_71 != 0x4c && V_7 -> V_71 != 0x4d )
return - V_66 ;
V_14 = V_77 ;
break;
case V_78 :
if ( V_7 -> V_71 != 0x4c && V_7 -> V_71 != 0x4d )
return - V_66 ;
V_14 = V_17 ;
break;
case V_79 :
V_14 = V_80 ;
break;
default:
return - V_66 ;
}
V_1 = F_6 ( V_7 , V_40 ) ;
if ( V_1 & 0x1b )
return - V_66 ;
V_1 = F_6 ( V_7 , V_81 ) ;
if ( V_1 > 15 )
return - V_66 ;
F_37 ( V_61 -> type , V_82 [ V_14 ] . V_83 , V_84 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 ,
const struct V_85 * V_86 )
{
static const char * const V_87 [] = {
L_4 , L_5 , L_6 , L_7 , L_8 , L_9
} ;
struct V_21 * V_22 = & V_7 -> V_22 ;
struct V_21 * V_88 ;
struct V_8 * V_9 ;
int V_89 = 0 , V_31 ;
V_9 = F_39 ( V_22 , sizeof( struct V_8 ) , V_90 ) ;
if ( ! V_9 )
return - V_91 ;
V_9 -> V_7 = V_7 ;
F_40 ( & V_9 -> V_25 ) ;
V_9 -> V_14 = V_86 -> V_92 ;
V_31 = F_34 ( V_9 , V_7 ) ;
if ( V_31 < 0 )
return V_31 ;
V_9 -> V_89 [ V_89 ++ ] = & V_93 ;
if ( V_9 -> V_14 == V_15 )
V_9 -> V_89 [ V_89 ++ ] = & V_94 ;
if ( V_9 -> V_14 == V_17 )
V_9 -> V_89 [ V_89 ++ ] = & V_95 ;
if ( V_9 -> V_14 == V_96 )
V_9 -> V_89 [ V_89 ++ ] = & V_97 ;
V_88 = F_41 ( V_22 , V_7 -> V_83 ,
V_9 , V_9 -> V_89 ) ;
if ( F_18 ( V_88 ) )
return F_19 ( V_88 ) ;
F_42 ( V_22 , L_10 , V_87 [ V_9 -> V_14 ] ) ;
return 0 ;
}
