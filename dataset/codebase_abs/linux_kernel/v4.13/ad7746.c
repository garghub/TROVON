static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 , V_9 ;
T_1 V_10 , V_11 ;
switch ( V_4 -> type ) {
case V_12 :
V_11 = ( V_4 -> V_13 & 0xFF ) | V_14 ;
V_10 = V_6 -> V_10 & ~ V_15 ;
V_9 = ( V_6 -> V_16 & V_17 ) >>
V_18 ;
V_8 = V_19 [ V_9 ] [ 1 ] ;
if ( V_6 -> V_20 != V_4 -> V_21 ) {
V_7 = F_3 ( V_6 -> V_22 ,
V_23 ,
V_6 -> V_24 [ V_4 -> V_21 ] [ 0 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_6 -> V_22 ,
V_25 ,
V_6 -> V_24 [ V_4 -> V_21 ] [ 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_20 = V_4 -> V_21 ;
}
break;
case V_26 :
case V_27 :
V_10 = ( V_4 -> V_13 & 0xFF ) | V_15 ;
V_11 = V_6 -> V_11 & ~ V_14 ;
V_9 = ( V_6 -> V_16 & V_28 ) >>
V_29 ;
V_8 = V_19 [ V_9 ] [ 1 ] ;
break;
default:
return - V_30 ;
}
if ( V_6 -> V_11 != V_11 ) {
V_7 = F_3 ( V_6 -> V_22 ,
V_31 ,
V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_11 = V_11 ;
}
if ( V_6 -> V_10 != V_10 ) {
V_7 = F_3 ( V_6 -> V_22 ,
V_32 ,
V_10 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_10 = V_10 ;
}
return V_8 ;
}
static inline T_2 F_4 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 ,
T_1 V_39 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_40 ;
int V_7 , V_41 = 10 ;
V_7 = F_6 ( V_37 , & V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_40 )
return 0 ;
F_7 ( & V_6 -> V_42 ) ;
V_39 |= V_6 -> V_16 ;
V_7 = F_3 ( V_6 -> V_22 , V_43 , V_39 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_6 -> V_42 ) ;
return V_7 ;
}
do {
F_9 ( 20 ) ;
V_7 = F_10 ( V_6 -> V_22 , V_43 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_6 -> V_42 ) ;
return V_7 ;
}
} while ( ( V_7 == V_39 ) && V_41 -- );
F_8 ( & V_6 -> V_42 ) ;
return V_38 ;
}
static T_2 F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
int V_7 = F_1 ( V_2 ,
& V_44 [ F_12 ( V_36 ) -> V_13 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_34 , V_36 , V_37 , V_38 ,
V_45 ) ;
}
static T_2 F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 ,
T_3 V_38 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
int V_7 = F_1 ( V_2 ,
& V_44 [ F_12 ( V_36 ) -> V_13 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_34 , V_36 , V_37 , V_38 ,
V_46 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_15 ( V_19 ) ; V_48 ++ )
if ( V_47 >= V_19 [ V_48 ] [ 0 ] )
break;
if ( V_48 >= F_15 ( V_19 ) )
V_48 = F_15 ( V_19 ) - 1 ;
V_6 -> V_16 &= ~ V_17 ;
V_6 -> V_16 |= V_48 << V_18 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_15 ( V_49 ) ; V_48 ++ )
if ( V_47 >= V_49 [ V_48 ] [ 0 ] )
break;
if ( V_48 >= F_15 ( V_49 ) )
V_48 = F_15 ( V_49 ) - 1 ;
V_6 -> V_16 &= ~ V_28 ;
V_6 -> V_16 |= V_48 << V_29 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_47 ,
int V_50 ,
long V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_52 ;
F_7 ( & V_6 -> V_42 ) ;
switch ( V_51 ) {
case V_53 :
if ( V_47 != 1 ) {
V_7 = - V_30 ;
goto V_54;
}
V_47 = ( V_50 * 1024 ) / 15625 ;
switch ( V_4 -> type ) {
case V_12 :
V_52 = V_55 ;
break;
case V_26 :
V_52 = V_56 ;
break;
default:
V_7 = - V_30 ;
goto V_54;
}
V_7 = F_18 ( V_6 -> V_22 , V_52 , F_19 ( V_47 ) ) ;
if ( V_7 < 0 )
goto V_54;
V_7 = 0 ;
break;
case V_57 :
if ( ( V_47 < 0 ) | ( V_47 > 0xFFFF ) ) {
V_7 = - V_30 ;
goto V_54;
}
V_7 = F_18 ( V_6 -> V_22 ,
V_58 , F_19 ( V_47 ) ) ;
if ( V_7 < 0 )
goto V_54;
V_7 = 0 ;
break;
case V_59 :
if ( ( V_47 < 0 ) | ( V_47 > 43008000 ) ) {
V_7 = - V_30 ;
goto V_54;
}
V_47 /= 338646 ;
V_6 -> V_24 [ V_4 -> V_21 ] [ V_4 -> V_60 ] = V_47 > 0 ?
F_20 ( V_47 ) | V_61 : 0 ;
V_7 = F_3 ( V_6 -> V_22 ,
V_23 ,
V_6 -> V_24 [ V_4 -> V_21 ] [ 0 ] ) ;
if ( V_7 < 0 )
goto V_54;
V_7 = F_3 ( V_6 -> V_22 ,
V_25 ,
V_6 -> V_24 [ V_4 -> V_21 ] [ 1 ] ) ;
if ( V_7 < 0 )
goto V_54;
V_6 -> V_20 = V_4 -> V_21 ;
V_7 = 0 ;
break;
case V_62 :
if ( V_50 ) {
V_7 = - V_30 ;
goto V_54;
}
switch ( V_4 -> type ) {
case V_12 :
V_7 = F_14 ( V_6 , V_47 ) ;
break;
case V_26 :
V_7 = F_16 ( V_6 , V_47 ) ;
break;
default:
V_7 = - V_30 ;
}
break;
default:
V_7 = - V_30 ;
}
V_54:
F_8 ( & V_6 -> V_42 ) ;
return V_7 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_47 , int * V_50 ,
long V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 , V_9 ;
T_1 V_39 , V_52 ;
F_7 ( & V_6 -> V_42 ) ;
switch ( V_51 ) {
case V_63 :
case V_64 :
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_54;
V_8 = V_7 ;
V_39 = V_6 -> V_16 | V_65 ;
V_7 = F_3 ( V_6 -> V_22 , V_43 ,
V_39 ) ;
if ( V_7 < 0 )
goto V_54;
F_9 ( V_8 ) ;
V_7 = F_22 ( V_6 -> V_22 ,
V_4 -> V_13 >> 8 , 3 , & V_6 -> V_66 . V_67 [ 1 ] ) ;
if ( V_7 < 0 )
goto V_54;
* V_47 = ( F_23 ( V_6 -> V_66 . V_68 ) & 0xFFFFFF ) - 0x800000 ;
switch ( V_4 -> type ) {
case V_27 :
* V_47 = ( * V_47 * 125 ) / 256 ;
break;
case V_26 :
if ( V_4 -> V_21 == 1 )
* V_47 = * V_47 * 6 ;
break;
default:
break;
}
V_7 = V_69 ;
break;
case V_53 :
switch ( V_4 -> type ) {
case V_12 :
V_52 = V_55 ;
break;
case V_26 :
V_52 = V_56 ;
break;
default:
V_7 = - V_30 ;
goto V_54;
}
V_7 = F_24 ( V_6 -> V_22 , V_52 ) ;
if ( V_7 < 0 )
goto V_54;
* V_47 = 1 ;
* V_50 = ( 15625 * F_19 ( V_7 ) ) / 1024 ;
V_7 = V_70 ;
break;
case V_57 :
V_7 = F_24 ( V_6 -> V_22 ,
V_58 ) ;
if ( V_7 < 0 )
goto V_54;
* V_47 = F_19 ( V_7 ) ;
V_7 = V_69 ;
break;
case V_59 :
* V_47 = F_20 ( V_6 -> V_24 [ V_4 -> V_21 ]
[ V_4 -> V_60 ] ) * 338646 ;
V_7 = V_69 ;
break;
case V_71 :
switch ( V_4 -> type ) {
case V_12 :
* V_47 = 0 ;
* V_50 = 488 ;
V_7 = V_72 ;
break;
case V_26 :
* V_47 = 1170 ;
* V_50 = 23 ;
V_7 = V_73 ;
break;
default:
V_7 = - V_30 ;
break;
}
break;
case V_62 :
switch ( V_4 -> type ) {
case V_12 :
V_9 = ( V_6 -> V_16 & V_17 ) >>
V_18 ;
* V_47 = V_19 [ V_9 ] [ 0 ] ;
V_7 = V_69 ;
break;
case V_26 :
V_9 = ( V_6 -> V_16 & V_28 ) >>
V_29 ;
* V_47 = V_49 [ V_9 ] [ 0 ] ;
V_7 = V_69 ;
break;
default:
V_7 = - V_30 ;
}
break;
default:
V_7 = - V_30 ;
}
V_54:
F_8 ( & V_6 -> V_42 ) ;
return V_7 ;
}
static int F_25 ( struct V_74 * V_22 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 = V_22 -> V_34 . V_79 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_7 = 0 ;
unsigned char V_39 = 0 ;
V_2 = F_26 ( & V_22 -> V_34 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_80 ;
V_6 = F_2 ( V_2 ) ;
F_27 ( & V_6 -> V_42 ) ;
F_28 ( V_22 , V_2 ) ;
V_6 -> V_22 = V_22 ;
V_6 -> V_20 = - 1 ;
V_2 -> V_81 = V_76 -> V_81 ;
V_2 -> V_34 . V_82 = & V_22 -> V_34 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = V_44 ;
if ( V_76 -> V_86 == 7746 )
V_2 -> V_87 = F_15 ( V_44 ) ;
else
V_2 -> V_87 = F_15 ( V_44 ) - 2 ;
V_2 -> V_87 = F_15 ( V_44 ) ;
V_2 -> V_88 = V_89 ;
if ( V_78 ) {
if ( V_78 -> V_90 ) {
if ( V_78 -> V_91 )
V_39 |= V_92 ;
else
V_39 |= V_93 ;
}
if ( V_78 -> V_94 ) {
if ( V_78 -> V_95 )
V_39 |= V_96 ;
else
V_39 |= V_97 ;
}
V_39 |= F_29 ( V_78 -> V_98 ) ;
} else {
F_30 ( & V_22 -> V_34 , L_1 ) ;
V_39 = V_93 | V_97 |
F_29 ( 3 ) ;
}
V_7 = F_3 ( V_6 -> V_22 ,
V_99 , V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_31 ( V_2 -> V_34 . V_82 , V_2 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
