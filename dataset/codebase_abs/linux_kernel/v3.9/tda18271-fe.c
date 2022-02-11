static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = F_2 ( V_2 , V_3 ? 1 : 0 ,
V_5 -> V_8 & V_9 ? 1 : 0 ,
V_5 -> V_8 & V_10 ? 1 : 0 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
F_4 ( L_1 ,
V_3 ? L_2 : L_3 ,
V_5 -> V_8 & V_10 ? L_4 : L_5 ,
V_5 -> V_8 & V_9 ? L_4 : L_5 ) ;
V_11:
return V_7 ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_6 ( V_2 ,
( V_5 -> V_13 == V_14 ) ?
V_15 :
V_16 , V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
switch ( V_5 -> V_19 ) {
case V_20 :
V_17 [ V_21 ] &= ~ 0x80 ;
break;
case V_22 :
V_17 [ V_21 ] |= 0x80 ;
break;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
T_1 V_25 , T_1 V_26 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
T_1 V_27 ;
V_17 [ V_28 ] &= ~ 0x1f ;
V_17 [ V_28 ] |= ( V_24 -> V_29 << 3 ) | V_24 -> V_30 ;
if ( V_5 -> V_31 == V_32 ) {
V_17 [ V_28 ] &= ~ 0x04 ;
}
V_17 [ V_33 ] &= ~ 0x03 ;
V_17 [ V_33 ] &= ~ 0x1c ;
V_17 [ V_33 ] |= ( V_24 -> V_34 << 2 ) ;
V_17 [ V_33 ] &= ~ 0x80 ;
V_17 [ V_33 ] |= V_24 -> V_35 << 7 ;
V_17 [ V_36 ] = 0x00 ;
V_17 [ V_36 ] |= V_24 -> V_37 ;
V_7 = F_9 ( V_2 , V_36 , 1 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_38 ] |= 0x40 ;
V_17 [ V_39 ] &= ~ 0x10 ;
F_10 ( V_2 , & V_25 ) ;
F_11 ( V_2 , & V_25 ) ;
F_12 ( V_2 , & V_25 ) ;
F_13 ( V_2 , & V_25 ) ;
switch ( V_5 -> V_13 ) {
case V_40 :
V_17 [ V_41 ] |= 0x04 ;
break;
case V_14 :
V_17 [ V_41 ] &= ~ 0x04 ;
break;
}
V_17 [ V_41 ] &= ~ 0x02 ;
V_17 [ V_41 ] &= ~ 0x01 ;
V_7 = F_9 ( V_2 , V_41 , 1 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_27 = V_24 -> V_42 * 1000 + V_25 ;
switch ( V_5 -> V_13 ) {
case V_40 :
F_14 ( V_2 , V_27 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 , V_21 , 4 ) ;
break;
case V_14 :
F_15 ( V_2 , V_27 ) ;
F_9 ( V_2 , V_43 , 4 ) ;
V_17 [ V_21 ] = V_17 [ V_43 ] & 0x7f ;
F_7 ( V_2 ) ;
F_9 ( V_2 , V_21 , 1 ) ;
break;
}
V_7 = F_9 ( V_2 , V_39 , 7 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
F_5 ( V_2 , 1 ) ;
F_16 ( 1 ) ;
F_5 ( V_2 , 0 ) ;
F_16 ( 20 ) ;
if ( V_5 -> V_31 == V_32 ) {
if ( V_24 -> V_35 )
V_17 [ V_28 ] &= ~ 0x04 ;
else
V_17 [ V_28 ] |= 0x04 ;
V_7 = F_9 ( V_2 , V_28 , 1 ) ;
}
V_11:
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_44 ;
V_17 [ V_39 ] |= 0x10 ;
F_9 ( V_2 , V_39 , 1 ) ;
F_18 ( V_2 ) ;
if ( ( ( ( V_17 [ V_39 ] & 0x0f ) == 0x00 ) && ( ( V_17 [ V_39 ] & 0x20 ) == 0x20 ) ) ||
( ( ( V_17 [ V_39 ] & 0x0f ) == 0x08 ) && ( ( V_17 [ V_39 ] & 0x20 ) == 0x00 ) ) ) {
if ( ( V_17 [ V_39 ] & 0x20 ) == 0x20 )
V_17 [ V_39 ] &= ~ 0x20 ;
else
V_17 [ V_39 ] |= 0x20 ;
F_9 ( V_2 , V_39 , 1 ) ;
F_16 ( 10 ) ;
F_18 ( V_2 ) ;
}
V_44 = F_19 ( V_2 ) ;
V_17 [ V_39 ] &= ~ 0x10 ;
F_9 ( V_2 , V_39 , 1 ) ;
V_17 [ V_33 ] &= ~ 0x03 ;
F_9 ( V_2 , V_33 , 1 ) ;
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_45 * V_24 = V_5 -> V_46 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_47 , V_7 ;
T_2 V_48 , V_49 , V_50 ;
T_3 V_51 , V_52 ;
V_7 = F_2 ( V_2 , 0 , 0 , 0 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_48 = F_17 ( V_2 ) ;
F_21 ( V_2 , & V_25 ) ;
V_50 = V_17 [ V_53 ] ;
V_47 = F_22 ( V_2 , & V_25 , NULL ) ;
if ( F_3 ( V_47 ) )
return V_47 ;
if ( ( 0 == V_24 [ V_47 ] . V_54 ) || ( V_25 / 1000 < V_24 [ V_47 ] . V_55 ) ) {
V_52 = V_24 [ V_47 ] . V_56 * ( T_3 ) ( V_25 / 1000 - V_24 [ V_47 ] . V_57 ) +
V_24 [ V_47 ] . V_58 + V_50 ;
} else {
V_52 = V_24 [ V_47 ] . V_59 * ( T_3 ) ( V_25 / 1000 - V_24 [ V_47 ] . V_55 ) +
V_24 [ V_47 ] . V_60 + V_50 ;
}
if ( V_52 < 0 )
V_52 = 0 ;
if ( V_52 > 255 )
V_52 = 255 ;
F_23 ( V_2 , V_61 , & V_25 , & V_49 ) ;
V_51 = V_49 * ( T_3 ) ( V_48 - V_5 -> V_62 ) / 1000 ;
V_17 [ V_53 ] = ( unsigned char ) ( V_52 + V_51 ) ;
V_7 = F_9 ( V_2 , V_53 , 1 ) ;
V_11:
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
V_17 [ V_63 ] &= ~ 0x20 ;
V_7 = F_9 ( V_2 , V_63 , 1 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_64 ] &= ~ 0x80 ;
V_17 [ V_64 ] &= ~ 0x03 ;
V_7 = F_9 ( V_2 , V_64 , 1 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_65 ] |= 0x03 ;
V_7 = F_2 ( V_2 , 1 , 0 , 0 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_66 ] &= ~ 0x04 ;
V_17 [ V_66 ] &= ~ 0x02 ;
V_7 = F_9 ( V_2 , V_65 , 3 ) ;
V_11:
return V_7 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
T_1 V_27 ;
V_17 [ V_33 ] &= ~ 0x03 ;
F_9 ( V_2 , V_33 , 1 ) ;
V_17 [ V_28 ] |= 0x40 ;
V_17 [ V_64 ] |= 0x03 ;
F_9 ( V_2 , V_64 , 1 ) ;
F_11 ( V_2 , & V_25 ) ;
F_13 ( V_2 , & V_25 ) ;
F_12 ( V_2 , & V_25 ) ;
F_26 ( V_2 , & V_25 ) ;
F_9 ( V_2 , V_38 , 3 ) ;
F_9 ( V_2 , V_67 , 1 ) ;
F_6 ( V_2 , V_16 , 1 ) ;
F_6 ( V_2 , V_15 , 1 ) ;
V_17 [ V_53 ] = 0x00 ;
F_9 ( V_2 , V_53 , 1 ) ;
V_17 [ V_68 ] &= ~ 0x20 ;
F_9 ( V_2 , V_68 , 1 ) ;
V_17 [ V_33 ] |= 0x03 ;
F_9 ( V_2 , V_33 , 2 ) ;
V_27 = V_25 ;
F_15 ( V_2 , V_27 ) ;
F_9 ( V_2 , V_43 , 4 ) ;
V_27 += 1000000 ;
F_14 ( V_2 , V_27 ) ;
F_9 ( V_2 , V_21 , 4 ) ;
F_16 ( 5 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
F_6 ( V_2 , V_16 , 0 ) ;
F_6 ( V_2 , V_15 , 0 ) ;
F_16 ( 10 ) ;
V_17 [ V_68 ] |= 0x20 ;
F_9 ( V_2 , V_68 , 1 ) ;
F_16 ( 60 ) ;
V_17 [ V_33 ] &= ~ 0x03 ;
V_17 [ V_28 ] &= ~ 0x40 ;
V_17 [ V_64 ] &= ~ 0x03 ;
F_9 ( V_2 , V_64 , 1 ) ;
F_9 ( V_2 , V_28 , 2 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
F_27 ( V_2 ) ;
return V_17 [ V_53 ] ;
}
static int F_28 ( struct V_1 * V_2 ,
T_1 * V_70 , T_1 * V_71 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_72 , V_73 , V_74 , V_75 , V_7 ;
T_2 V_76 ;
T_4 V_77 ;
T_1 V_25 ;
V_25 = * V_70 ;
F_12 ( V_2 , & V_25 ) ;
F_21 ( V_2 , & V_25 ) ;
F_13 ( V_2 , & V_25 ) ;
F_29 ( V_2 , & V_25 , & V_76 , & V_77 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
F_9 ( V_2 , V_53 , 1 ) ;
V_25 += 1000000 ;
F_14 ( V_2 , V_25 ) ;
F_9 ( V_2 , V_21 , 4 ) ;
F_16 ( 5 ) ;
V_17 [ V_33 ] &= ~ 0x03 ;
V_17 [ V_33 ] |= 0x01 ;
F_9 ( V_2 , V_33 , 1 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
V_7 = F_27 ( V_2 ) ;
if ( F_3 ( V_7 ) )
return V_7 ;
V_72 = 1 ;
* V_71 = * V_70 ;
V_73 = 0 ;
V_74 = 0 ;
V_75 = false ;
while ( ( V_17 [ V_78 ] & 0x3f ) < V_76 ) {
V_25 = * V_70 + ( V_72 * V_74 ) + 1000000 ;
F_14 ( V_2 , V_25 ) ;
F_9 ( V_2 , V_21 , 4 ) ;
if ( V_75 ) {
F_16 ( 5 ) ;
V_75 = false ;
} else
F_30 ( 100 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
V_7 = F_27 ( V_2 ) ;
if ( F_3 ( V_7 ) )
return V_7 ;
V_74 += 200 ;
if ( V_74 <= V_77 )
continue;
if ( V_72 <= 0 )
break;
V_72 = - 1 * V_72 ;
V_74 = 200 ;
V_75 = true ;
}
if ( ( V_17 [ V_78 ] & 0x3f ) >= V_76 ) {
V_73 = 1 ;
* V_71 = V_25 - 1000000 ;
} else
V_73 = 0 ;
F_31 ( L_6 ,
V_73 , * V_70 , * V_71 , V_25 ) ;
return V_73 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
V_17 [ V_28 ] &= ~ 0x1f ;
V_17 [ V_28 ] |= 0x12 ;
V_17 [ V_33 ] &= ~ 0x03 ;
V_17 [ V_33 ] &= ~ 0x1c ;
V_7 = F_9 ( V_2 , V_28 , 2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_64 ] &= ~ 0x03 ;
V_7 = F_9 ( V_2 , V_64 , 1 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_17 [ V_65 ] &= ~ 0x03 ;
V_17 [ V_66 ] |= 0x04 ;
V_17 [ V_66 ] |= 0x02 ;
V_7 = F_9 ( V_2 , V_65 , 3 ) ;
V_11:
return V_7 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_45 * V_24 = V_5 -> V_46 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_73 , V_79 , V_47 ;
T_3 V_80 , V_81 ;
#define F_34 0
#define F_35 1
#define F_36 2
T_1 V_82 [ 3 ] ;
T_1 V_83 [ 3 ] ;
T_3 V_84 [ 3 ] ;
T_3 V_85 [ 3 ] ;
V_47 = F_22 ( V_2 , & V_25 , NULL ) ;
if ( F_3 ( V_47 ) )
return V_47 ;
V_82 [ F_34 ] = 1000 * V_24 [ V_47 ] . V_86 ;
V_82 [ F_35 ] = 1000 * V_24 [ V_47 ] . V_87 ;
V_82 [ F_36 ] = 1000 * V_24 [ V_47 ] . V_88 ;
for ( V_79 = F_34 ; V_79 <= F_36 ; V_79 ++ ) {
if ( 0 == V_82 [ V_79 ] )
return 0 ;
F_31 ( L_7 , V_25 , V_79 ) ;
V_73 = F_28 ( V_2 , & V_82 [ V_79 ] , & V_83 [ V_79 ] ) ;
if ( F_3 ( V_73 ) )
return V_73 ;
F_21 ( V_2 , & V_83 [ V_79 ] ) ;
V_85 [ V_79 ] = ( T_3 ) V_17 [ V_53 ] ;
if ( 1 == V_73 )
V_84 [ V_79 ] =
( T_3 ) F_25 ( V_2 , V_83 [ V_79 ] ) ;
else
V_84 [ V_79 ] = V_85 [ V_79 ] ;
switch ( V_79 ) {
case F_34 :
V_24 [ V_47 ] . V_56 = 0 ;
V_24 [ V_47 ] . V_58 = ( V_84 [ F_34 ] - V_85 [ F_34 ] ) ;
V_24 [ V_47 ] . V_57 = V_83 [ F_34 ] / 1000 ;
break;
case F_35 :
V_81 = ( V_84 [ F_35 ] - V_85 [ F_35 ] -
V_84 [ F_34 ] + V_85 [ F_34 ] ) ;
V_80 = ( T_3 ) ( V_83 [ F_35 ] - V_83 [ F_34 ] ) / 1000 ;
V_24 [ V_47 ] . V_56 = ( V_81 / V_80 ) ;
V_24 [ V_47 ] . V_55 = V_83 [ F_35 ] / 1000 ;
break;
case F_36 :
V_81 = ( V_84 [ F_36 ] - V_85 [ F_36 ] -
V_84 [ F_35 ] + V_85 [ F_35 ] ) ;
V_80 = ( T_3 ) ( V_83 [ F_36 ] - V_83 [ F_35 ] ) / 1000 ;
V_24 [ V_47 ] . V_59 = ( V_81 / V_80 ) ;
V_24 [ V_47 ] . V_60 = ( V_84 [ F_35 ] - V_85 [ F_35 ] ) ;
V_24 [ V_47 ] . V_54 = V_83 [ F_36 ] / 1000 ;
break;
default:
F_37 () ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_47 ;
int V_7 ;
F_39 ( L_8 ) ;
F_16 ( 200 ) ;
V_7 = F_32 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
for ( V_47 = 0 ; V_5 -> V_46 [ V_47 ] . V_89 != 0 ; V_47 ++ ) {
V_7 =
F_33 ( V_2 , 1000 *
V_5 -> V_46 [ V_47 ] . V_89 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
}
V_5 -> V_62 = F_17 ( V_2 ) ;
V_11:
return V_7 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
if ( ( V_17 [ V_38 ] & 0x10 ) == 0 )
V_5 -> V_90 = false ;
if ( V_5 -> V_90 )
return 0 ;
V_7 = F_38 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_7 = F_24 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
F_39 ( L_9 ) ;
V_5 -> V_90 = true ;
goto V_91;
V_11:
F_39 ( L_10 ) ;
V_91:
return V_7 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_1 V_25 , T_1 V_26 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
T_1 V_27 = 0 ;
F_11 ( V_2 , & V_25 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
V_17 [ V_92 ] &= 0x07 ;
V_17 [ V_92 ] |= 0x60 ;
F_9 ( V_2 , V_92 , 1 ) ;
V_17 [ V_93 ] = 0x60 ;
F_9 ( V_2 , V_93 , 1 ) ;
V_17 [ V_53 ] = 0x00 ;
F_9 ( V_2 , V_53 , 1 ) ;
V_17 [ V_68 ] = 0xcc ;
F_9 ( V_2 , V_68 , 1 ) ;
V_17 [ V_33 ] |= 0x03 ;
switch ( V_5 -> V_19 ) {
case V_20 :
V_27 = V_25 - 1250000 ;
break;
case V_22 :
V_27 = V_25 + V_26 / 2 ;
break;
}
F_15 ( V_2 , V_27 ) ;
switch ( V_5 -> V_19 ) {
case V_20 :
V_27 = V_25 - 250000 ;
break;
case V_22 :
V_27 = V_25 + V_26 / 2 + 1000000 ;
break;
}
F_14 ( V_2 , V_27 ) ;
V_7 = F_9 ( V_2 , V_28 , 11 ) ;
if ( F_3 ( V_7 ) )
return V_7 ;
F_16 ( 5 ) ;
F_26 ( V_2 , & V_25 ) ;
F_9 ( V_2 , V_67 , 1 ) ;
F_12 ( V_2 , & V_25 ) ;
F_13 ( V_2 , & V_25 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
F_9 ( V_2 , V_69 , 1 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
V_17 [ V_92 ] &= 0x07 ;
V_17 [ V_92 ] |= 0x40 ;
F_9 ( V_2 , V_92 , 1 ) ;
V_17 [ V_93 ] = 0x40 ;
F_9 ( V_2 , V_93 , 1 ) ;
F_16 ( 10 ) ;
V_17 [ V_68 ] = 0xec ;
F_9 ( V_2 , V_68 , 1 ) ;
F_16 ( 60 ) ;
V_17 [ V_33 ] &= ~ 0x03 ;
F_9 ( V_2 , V_33 , 1 ) ;
F_9 ( V_2 , V_38 , 1 ) ;
if ( 0 == F_21 ( V_2 , & V_25 ) )
F_9 ( V_2 , V_53 , 1 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
int V_7 ;
V_7 = F_18 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
if ( ( V_17 [ V_38 ] & 0x08 ) == 0 )
V_7 = F_43 ( V_2 ) ;
V_11:
return V_7 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_45 ( & V_5 -> V_94 ) ;
V_7 = F_2 ( V_2 , 0 , 0 , 0 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_7 = F_42 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
if ( V_5 -> V_31 == V_32 )
F_40 ( V_2 ) ;
V_11:
F_46 ( & V_5 -> V_94 ) ;
return V_7 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_45 ( & V_5 -> V_94 ) ;
V_7 = F_1 ( V_2 , 1 ) ;
F_46 ( & V_5 -> V_94 ) ;
return V_7 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 0 ;
switch ( V_5 -> V_95 ) {
case 0 :
if ( V_96 & V_97 )
F_4 ( L_11 ) ;
break;
case 3 :
F_4 ( L_12 ) ;
if ( V_2 -> V_98 )
V_7 = V_2 -> V_98 ( V_5 -> V_99 . V_100 -> V_101 ,
V_102 ,
V_103 ,
V_5 -> V_19 ) ;
break;
case 1 :
case 2 :
default:
F_49 ( L_13 , V_5 -> V_95 ) ;
V_7 = - V_104 ;
break;
}
return V_7 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_1 V_25 , T_1 V_26 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
F_4 ( L_14 ,
V_25 , V_24 -> V_42 , V_26 , V_24 -> V_29 , V_24 -> V_30 ) ;
V_7 = F_48 ( V_2 ) ;
if ( F_3 ( V_7 ) )
F_51 ( L_15 ) ;
V_7 = F_44 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
F_45 ( & V_5 -> V_94 ) ;
switch ( V_5 -> V_31 ) {
case V_105 :
F_41 ( V_2 , V_25 , V_26 ) ;
break;
case V_32 :
F_20 ( V_2 , V_25 ) ;
break;
}
V_7 = F_8 ( V_2 , V_24 , V_25 , V_26 ) ;
F_46 ( & V_5 -> V_94 ) ;
V_11:
return V_7 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = & V_2 -> V_108 ;
T_1 V_109 = V_107 -> V_110 ;
T_1 V_26 = V_107 -> V_111 ;
T_1 V_25 = V_107 -> V_112 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_113 * V_114 = & V_5 -> V_30 ;
struct V_23 * V_24 ;
int V_7 ;
V_5 -> V_19 = V_22 ;
switch ( V_109 ) {
case V_115 :
V_24 = & V_114 -> V_116 ;
V_26 = 6000000 ;
break;
case V_117 :
case V_118 :
case V_119 :
if ( V_26 <= 6000000 ) {
V_24 = & V_114 -> V_120 ;
} else if ( V_26 <= 7000000 ) {
V_24 = & V_114 -> V_121 ;
} else {
V_24 = & V_114 -> V_122 ;
}
break;
case V_123 :
V_26 = 6000000 ;
case V_124 :
case V_125 :
if ( V_26 <= 6000000 ) {
V_24 = & V_114 -> V_126 ;
} else if ( V_26 <= 7000000 ) {
V_24 = & V_114 -> V_127 ;
} else {
V_24 = & V_114 -> V_128 ;
}
break;
default:
F_51 ( L_16 ) ;
return - V_104 ;
}
if ( V_2 -> V_129 . V_130 . V_3 )
V_2 -> V_129 . V_130 . V_3 ( V_2 ) ;
V_7 = F_50 ( V_2 , V_24 , V_25 , V_26 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_5 -> V_42 = V_24 -> V_42 ;
V_5 -> V_112 = V_25 ;
V_5 -> V_131 = V_26 ;
V_11:
return V_7 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_113 * V_114 = & V_5 -> V_30 ;
struct V_23 * V_24 ;
char * V_19 ;
int V_7 ;
T_1 V_25 = V_133 -> V_112 * 125 *
( ( V_133 -> V_19 == V_134 ) ? 1 : 1000 ) / 2 ;
V_5 -> V_19 = V_20 ;
if ( V_133 -> V_19 == V_134 ) {
V_24 = & V_114 -> V_135 ;
V_19 = L_17 ;
} else if ( V_133 -> V_30 & V_136 ) {
V_24 = & V_114 -> V_137 ;
V_19 = L_18 ;
} else if ( V_133 -> V_30 & V_138 ) {
V_24 = & V_114 -> V_139 ;
V_19 = L_19 ;
} else if ( V_133 -> V_30 & V_140 ) {
V_24 = & V_114 -> V_141 ;
V_19 = L_20 ;
} else if ( V_133 -> V_30 & V_142 ) {
V_24 = & V_114 -> V_143 ;
V_19 = L_21 ;
} else if ( V_133 -> V_30 & V_144 ) {
V_24 = & V_114 -> V_145 ;
V_19 = L_22 ;
} else if ( V_133 -> V_30 & V_146 ) {
V_24 = & V_114 -> V_147 ;
V_19 = L_23 ;
} else if ( V_133 -> V_30 & V_148 ) {
V_24 = & V_114 -> V_149 ;
V_19 = L_24 ;
} else {
V_24 = & V_114 -> V_143 ;
V_19 = L_25 ;
}
F_4 ( L_26 , V_19 ) ;
V_7 = F_50 ( V_2 , V_24 , V_25 , 0 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_5 -> V_42 = V_24 -> V_42 ;
V_5 -> V_112 = V_25 ;
V_5 -> V_131 = 0 ;
V_11:
return V_7 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_45 ( & V_150 ) ;
if ( V_5 )
F_55 ( V_5 ) ;
F_46 ( & V_150 ) ;
V_2 -> V_6 = NULL ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , T_1 * V_112 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_112 = V_5 -> V_112 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 * V_131 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_131 = V_5 -> V_131 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 * V_112 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_112 = ( T_1 ) V_5 -> V_42 * 1000 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_113 * V_30 = & V_5 -> V_30 ;
F_4 ( L_27 ) ;
F_60 ( V_135 , L_28 ) ;
F_60 ( V_139 , L_29 ) ;
F_60 ( V_145 , L_30 ) ;
F_60 ( V_141 , L_31 ) ;
F_60 ( V_143 , L_32 ) ;
F_60 ( V_147 , L_33 ) ;
F_60 ( V_149 , L_34 ) ;
F_60 ( V_137 , L_35 ) ;
F_60 ( V_116 , L_36 ) ;
F_60 ( V_120 , L_37 ) ;
F_60 ( V_121 , L_38 ) ;
F_60 ( V_122 , L_39 ) ;
F_60 ( V_126 , L_40 ) ;
F_60 ( V_127 , L_41 ) ;
F_60 ( V_128 , L_42 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_113 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_113 * V_30 = & V_5 -> V_30 ;
if ( ! V_24 )
return - V_104 ;
F_62 ( V_135 , L_17 ) ;
F_62 ( V_139 , L_43 ) ;
F_62 ( V_145 , L_30 ) ;
F_62 ( V_141 , L_31 ) ;
F_62 ( V_143 , L_44 ) ;
F_62 ( V_147 , L_45 ) ;
F_62 ( V_149 , L_34 ) ;
F_62 ( V_137 , L_35 ) ;
F_62 ( V_116 , L_36 ) ;
F_62 ( V_120 , L_37 ) ;
F_62 ( V_121 , L_38 ) ;
F_62 ( V_122 , L_39 ) ;
F_62 ( V_126 , L_46 ) ;
F_62 ( V_127 , L_47 ) ;
F_62 ( V_128 , L_48 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char * V_17 = V_5 -> V_18 ;
char * V_151 ;
int V_7 ;
F_45 ( & V_5 -> V_94 ) ;
V_7 = F_18 ( V_2 ) ;
F_46 ( & V_5 -> V_94 ) ;
if ( V_7 ) {
F_39 ( L_49 ,
F_64 ( V_5 -> V_99 . V_100 ) ,
V_5 -> V_99 . V_152 ) ;
return - V_153 ;
}
switch ( V_17 [ V_154 ] & 0x7f ) {
case 3 :
V_151 = L_50 ;
V_5 -> V_31 = V_105 ;
break;
case 4 :
V_151 = L_51 ;
V_5 -> V_31 = V_32 ;
break;
default:
F_39 ( L_52 ,
V_17 [ V_154 ] , F_64 ( V_5 -> V_99 . V_100 ) ,
V_5 -> V_99 . V_152 ) ;
return - V_104 ;
}
F_39 ( L_53 , V_151 ,
F_64 ( V_5 -> V_99 . V_100 ) , V_5 -> V_99 . V_152 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_155 * V_156 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_157 = ( V_156 ) ? V_156 -> V_157 : V_158 ;
V_5 -> V_13 = ( V_156 ) ? V_156 -> V_13 : V_40 ;
V_5 -> V_95 = ( V_156 ) ? V_156 -> V_95 : 0 ;
V_5 -> V_159 = ( V_156 ) ?
V_156 -> V_159 : V_160 ;
V_5 -> V_8 = ( V_156 ) ?
V_156 -> V_8 : V_161 ;
return 0 ;
}
static inline int F_66 ( struct V_155 * V_156 )
{
return ( ( V_162 == - 1 ) ?
( ( V_156 ) && ( V_156 -> V_163 ) ) :
( V_162 ) ) ? 1 : 0 ;
}
static int F_67 ( struct V_1 * V_2 , void * V_164 )
{
struct V_155 * V_156 = (struct V_155 * ) V_164 ;
F_65 ( V_2 , V_156 ) ;
if ( F_66 ( V_156 ) )
F_44 ( V_2 ) ;
if ( ( V_156 ) && ( V_156 -> V_114 ) )
F_61 ( V_2 , V_156 -> V_114 ) ;
return 0 ;
}
struct V_1 * F_68 ( struct V_1 * V_2 , T_2 V_152 ,
struct V_165 * V_166 ,
struct V_155 * V_156 )
{
struct V_4 * V_5 = NULL ;
int V_167 , V_7 ;
F_45 ( & V_150 ) ;
V_167 = F_69 ( struct V_4 , V_5 ,
V_168 ,
V_166 , V_152 , L_54 ) ;
switch ( V_167 ) {
case 0 :
goto V_11;
case 1 :
V_2 -> V_6 = V_5 ;
F_65 ( V_2 , V_156 ) ;
V_5 -> V_90 = false ;
F_70 ( & V_5 -> V_94 ) ;
V_7 = F_63 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
V_7 = F_71 ( V_2 ) ;
if ( F_3 ( V_7 ) )
goto V_11;
if ( ( V_156 -> V_169 ) && ( ! F_66 ( V_156 ) ) )
break;
F_45 ( & V_5 -> V_94 ) ;
F_43 ( V_2 ) ;
if ( ( F_66 ( V_156 ) ) &&
( V_5 -> V_31 == V_32 ) )
F_40 ( V_2 ) ;
V_7 = F_1 ( V_2 , 1 ) ;
F_3 ( V_7 ) ;
F_46 ( & V_5 -> V_94 ) ;
break;
default:
V_2 -> V_6 = V_5 ;
if ( V_156 ) {
if ( V_156 -> V_157 != V_170 )
V_5 -> V_157 = V_156 -> V_157 ;
if ( V_156 -> V_13 )
V_5 -> V_13 = V_156 -> V_13 ;
if ( V_156 -> V_95 )
V_5 -> V_95 = V_156 -> V_95 ;
if ( V_156 -> V_159 )
V_5 -> V_159 = V_156 -> V_159 ;
if ( V_156 -> V_8 )
V_5 -> V_8 = V_156 -> V_8 ;
if ( V_156 -> V_114 )
F_61 ( V_2 , V_156 -> V_114 ) ;
}
if ( F_66 ( V_156 ) )
F_44 ( V_2 ) ;
break;
}
if ( ( V_156 ) && ( V_156 -> V_114 ) )
F_61 ( V_2 , V_156 -> V_114 ) ;
F_46 ( & V_150 ) ;
memcpy ( & V_2 -> V_129 . V_171 , & V_172 ,
sizeof( struct V_173 ) ) ;
if ( V_96 & ( V_174 | V_97 ) )
F_59 ( V_2 ) ;
return V_2 ;
V_11:
F_46 ( & V_150 ) ;
F_54 ( V_2 ) ;
return NULL ;
}
