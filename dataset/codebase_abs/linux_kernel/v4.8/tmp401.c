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
struct V_8 * V_9 = F_8 ( V_24 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_8 * V_25 = V_9 ;
int V_10 , V_12 ;
unsigned long V_26 ;
F_9 ( & V_9 -> V_27 ) ;
V_26 = V_9 -> V_28 +
F_10 ( V_9 -> V_29 ) ;
if ( F_11 ( V_30 , V_26 ) || ! V_9 -> V_31 ) {
if ( V_9 -> V_14 != V_17 ) {
V_12 = F_6 ( V_7 , V_32 ) ;
if ( V_12 < 0 ) {
V_25 = F_12 ( V_12 ) ;
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
for ( V_10 = 0 ; V_10 < F_13 ( V_9 -> V_33 ) ; V_10 ++ ) {
V_12 = F_6 ( V_7 ,
V_41 [ V_10 ] ) ;
if ( V_12 < 0 ) {
V_25 = F_12 ( V_12 ) ;
goto abort;
}
V_9 -> V_33 [ V_10 ] = V_12 ;
}
}
V_12 = F_6 ( V_7 , V_42 ) ;
if ( V_12 < 0 ) {
V_25 = F_12 ( V_12 ) ;
goto abort;
}
V_9 -> V_2 = V_12 ;
V_12 = F_5 ( V_7 , V_9 ) ;
if ( V_12 < 0 ) {
V_25 = F_12 ( V_12 ) ;
goto abort;
}
V_12 = F_6 ( V_7 , V_43 ) ;
if ( V_12 < 0 ) {
V_25 = F_12 ( V_12 ) ;
goto abort;
}
V_9 -> V_44 = V_12 ;
V_9 -> V_28 = V_30 ;
V_9 -> V_31 = 1 ;
}
abort:
F_14 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_15 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_48 = F_16 ( V_46 ) -> V_48 ;
int V_49 = F_16 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
return sprintf ( V_47 , L_1 ,
F_1 ( V_9 -> V_3 [ V_48 ] [ V_49 ] , V_9 -> V_2 ) ) ;
}
static T_3 F_19 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_3 , V_49 = F_20 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
F_9 ( & V_9 -> V_27 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_49 ] , V_9 -> V_2 ) ;
V_3 -= V_9 -> V_44 * 1000 ;
F_14 ( & V_9 -> V_27 ) ;
return sprintf ( V_47 , L_1 , V_3 ) ;
}
static T_3 F_21 ( struct V_23 * V_24 ,
struct V_45 * V_46 , char * V_47 )
{
int V_48 = F_16 ( V_46 ) -> V_48 ;
int V_50 = F_16 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
return sprintf ( V_47 , L_1 , ! ! ( V_9 -> V_33 [ V_48 ] & V_50 ) ) ;
}
static T_3 F_22 ( struct V_23 * V_24 , struct V_45 * V_46 ,
const char * V_47 , T_4 V_51 )
{
int V_48 = F_16 ( V_46 ) -> V_48 ;
int V_49 = F_16 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_8 ( V_24 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
long V_12 ;
T_1 V_1 ;
T_2 V_18 ;
if ( F_23 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
V_1 = F_3 ( V_12 , V_9 -> V_2 , V_48 == 3 ? 8 : 4 ) ;
F_9 ( & V_9 -> V_27 ) ;
V_18 = V_9 -> V_14 == V_17 ? V_53 [ V_48 ] [ V_49 ]
: V_54 [ V_48 ] [ V_49 ] ;
F_24 ( V_7 , V_18 , V_1 >> 8 ) ;
if ( V_48 != 3 ) {
V_18 = V_9 -> V_14 == V_17 ? V_21 [ V_48 ] [ V_49 ]
: V_22 [ V_48 ] [ V_49 ] ;
F_24 ( V_7 , V_18 , V_1 & 0xFF ) ;
}
V_9 -> V_3 [ V_48 ] [ V_49 ] = V_1 ;
F_14 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_25 ( struct V_23 * V_24 , struct V_45
* V_46 , const char * V_47 , T_4 V_51 )
{
int V_3 , V_49 = F_20 ( V_46 ) -> V_49 ;
struct V_8 * V_9 = F_7 ( V_24 ) ;
long V_12 ;
T_2 V_1 ;
if ( F_17 ( V_9 ) )
return F_18 ( V_9 ) ;
if ( F_23 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
if ( V_9 -> V_2 & V_4 )
V_12 = F_4 ( V_12 , - 64000 , 191000 ) ;
else
V_12 = F_4 ( V_12 , 0 , 127000 ) ;
F_9 ( & V_9 -> V_27 ) ;
V_3 = F_1 ( V_9 -> V_3 [ 3 ] [ V_49 ] , V_9 -> V_2 ) ;
V_12 = F_4 ( V_12 , V_3 - 255000 , V_3 ) ;
V_1 = ( ( V_3 - V_12 ) + 500 ) / 1000 ;
F_24 ( V_9 -> V_7 , V_43 ,
V_1 ) ;
V_9 -> V_44 = V_1 ;
F_14 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_26 ( struct V_23 * V_24 ,
struct V_45 * V_46 , const char * V_47 , T_4 V_51 )
{
struct V_8 * V_9 = F_8 ( V_24 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
long V_12 ;
if ( F_23 ( V_47 , 10 , & V_12 ) )
return - V_52 ;
if ( V_12 != 1 ) {
F_27 ( V_24 ,
L_2 ,
V_12 ) ;
return - V_52 ;
}
F_9 ( & V_9 -> V_27 ) ;
F_24 ( V_7 , V_54 [ 5 ] [ 0 ] , V_12 ) ;
V_9 -> V_31 = 0 ;
F_14 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static T_3 F_28 ( struct V_23 * V_24 ,
struct V_45 * V_55 , char * V_47 )
{
struct V_8 * V_9 = F_8 ( V_24 ) ;
return sprintf ( V_47 , L_3 , V_9 -> V_29 ) ;
}
static T_3 F_29 ( struct V_23 * V_24 ,
struct V_45 * V_55 ,
const char * V_47 , T_4 V_51 )
{
struct V_8 * V_9 = F_8 ( V_24 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
unsigned long V_12 ;
int V_56 , V_57 ;
V_56 = F_30 ( V_47 , 10 , & V_12 ) ;
if ( V_56 )
return V_56 ;
V_12 = F_4 ( V_12 , 125 , 16000 ) ;
V_57 = 7 - F_31 ( V_12 * 4 / ( 125 * 3 ) ) ;
F_9 ( & V_9 -> V_27 ) ;
F_24 ( V_7 , V_58 , V_57 ) ;
V_9 -> V_29 = ( 1 << ( 7 - V_57 ) ) * 125 ;
F_14 ( & V_9 -> V_27 ) ;
return V_51 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
int V_2 , V_59 , V_33 = 0 ;
F_24 ( V_7 , V_58 , 5 ) ;
V_9 -> V_29 = 500 ;
V_2 = F_6 ( V_7 , V_42 ) ;
if ( V_2 < 0 )
return V_2 ;
V_59 = V_2 ;
V_2 &= ~ V_60 ;
if ( V_2 != V_59 )
V_33 = F_24 ( V_7 ,
V_61 ,
V_2 ) ;
return V_33 ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_62 * V_63 )
{
enum V_64 V_14 ;
struct V_65 * V_66 = V_7 -> V_66 ;
T_2 V_1 ;
if ( ! F_34 ( V_66 , V_67 ) )
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
if ( V_7 -> V_73 != 0x4c && V_7 -> V_73 != 0x4d )
return - V_68 ;
V_14 = V_79 ;
break;
case V_80 :
if ( V_7 -> V_73 != 0x4c && V_7 -> V_73 != 0x4d )
return - V_68 ;
V_14 = V_17 ;
break;
case V_81 :
V_14 = V_82 ;
break;
default:
return - V_68 ;
}
V_1 = F_6 ( V_7 , V_42 ) ;
if ( V_1 & 0x1b )
return - V_68 ;
V_1 = F_6 ( V_7 , V_83 ) ;
if ( V_1 > 15 )
return - V_68 ;
F_35 ( V_63 -> type , V_84 [ V_14 ] . V_85 , V_86 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
const struct V_87 * V_88 )
{
static const char * const V_89 [] = {
L_4 , L_5 , L_6 , L_7 , L_8 , L_9
} ;
struct V_23 * V_24 = & V_7 -> V_24 ;
struct V_23 * V_90 ;
struct V_8 * V_9 ;
int V_91 = 0 , V_33 ;
V_9 = F_37 ( V_24 , sizeof( struct V_8 ) , V_92 ) ;
if ( ! V_9 )
return - V_93 ;
V_9 -> V_7 = V_7 ;
F_38 ( & V_9 -> V_27 ) ;
V_9 -> V_14 = V_88 -> V_94 ;
V_33 = F_32 ( V_9 , V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
V_9 -> V_91 [ V_91 ++ ] = & V_95 ;
if ( V_9 -> V_14 == V_15 )
V_9 -> V_91 [ V_91 ++ ] = & V_96 ;
if ( V_9 -> V_14 == V_17 )
V_9 -> V_91 [ V_91 ++ ] = & V_97 ;
if ( V_9 -> V_14 == V_98 )
V_9 -> V_91 [ V_91 ++ ] = & V_99 ;
V_90 = F_39 ( V_24 , V_7 -> V_85 ,
V_9 , V_9 -> V_91 ) ;
if ( F_17 ( V_90 ) )
return F_18 ( V_90 ) ;
F_40 ( V_24 , L_10 , V_89 [ V_9 -> V_14 ] ) ;
return 0 ;
}
