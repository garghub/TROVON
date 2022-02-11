static T_1 F_1 ( T_2 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( V_1 & 0x8000 )
V_1 = V_1 ^ V_3 ;
V_1 = V_1 << 1 ;
}
return ( T_1 ) ( V_1 >> 8 ) ;
}
static T_1 F_2 ( T_1 V_4 , T_1 * V_5 , T_3 V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ )
V_4 = F_1 ( ( V_4 ^ V_5 [ V_2 ] ) << 8 ) ;
return V_4 ;
}
static T_1 F_3 ( T_1 V_7 , struct V_8 * V_9 )
{
T_1 V_10 = F_4 ( V_9 ) ;
V_7 = F_2 ( V_7 , & V_10 , 1 ) ;
return F_2 ( V_7 , V_9 -> V_11 , V_9 -> V_12 ) ;
}
static inline void F_5 ( struct V_8 * V_9 )
{
V_9 -> V_11 [ V_9 -> V_12 ] = F_3 ( 0 , V_9 ) ;
V_9 -> V_12 ++ ;
}
static int F_6 ( T_1 V_13 , struct V_8 * V_9 )
{
T_1 V_14 = V_9 -> V_11 [ -- V_9 -> V_12 ] ;
V_13 = F_3 ( V_13 , V_9 ) ;
if ( V_14 != V_13 ) {
F_7 ( L_1 ,
V_14 , V_13 ) ;
return - V_15 ;
}
return 0 ;
}
T_4 F_8 ( const struct V_16 * V_17 )
{
union V_18 V_1 ;
int V_19 ;
V_19 = F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_22 , 0 ,
V_23 , & V_1 ) ;
return ( V_19 < 0 ) ? V_19 : V_1 . V_24 ;
}
T_4 F_10 ( const struct V_16 * V_17 , T_1 V_25 )
{
return F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_26 , V_25 , V_23 , NULL ) ;
}
T_4 F_11 ( const struct V_16 * V_17 , T_1 V_27 )
{
union V_18 V_1 ;
int V_19 ;
V_19 = F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_22 , V_27 ,
V_28 , & V_1 ) ;
return ( V_19 < 0 ) ? V_19 : V_1 . V_24 ;
}
T_4 F_12 ( const struct V_16 * V_17 , T_1 V_27 ,
T_1 V_25 )
{
union V_18 V_1 ;
V_1 . V_24 = V_25 ;
return F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_26 , V_27 ,
V_28 , & V_1 ) ;
}
T_4 F_13 ( const struct V_16 * V_17 , T_1 V_27 )
{
union V_18 V_1 ;
int V_19 ;
V_19 = F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_22 , V_27 ,
V_29 , & V_1 ) ;
return ( V_19 < 0 ) ? V_19 : V_1 . V_30 ;
}
T_4 F_14 ( const struct V_16 * V_17 , T_1 V_27 ,
T_2 V_25 )
{
union V_18 V_1 ;
V_1 . V_30 = V_25 ;
return F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_26 , V_27 ,
V_29 , & V_1 ) ;
}
T_4 F_15 ( const struct V_16 * V_17 , T_1 V_27 ,
T_1 * V_31 )
{
union V_18 V_1 ;
int V_19 ;
V_19 = F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_22 , V_27 ,
V_32 , & V_1 ) ;
if ( V_19 )
return V_19 ;
memcpy ( V_31 , & V_1 . V_33 [ 1 ] , V_1 . V_33 [ 0 ] ) ;
return V_1 . V_33 [ 0 ] ;
}
T_4 F_16 ( const struct V_16 * V_17 , T_1 V_27 ,
T_1 V_34 , const T_1 * V_31 )
{
union V_18 V_1 ;
if ( V_34 > V_35 )
V_34 = V_35 ;
V_1 . V_33 [ 0 ] = V_34 ;
memcpy ( & V_1 . V_33 [ 1 ] , V_31 , V_34 ) ;
return F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_26 , V_27 ,
V_32 , & V_1 ) ;
}
T_4 F_17 ( const struct V_16 * V_17 , T_1 V_27 ,
T_1 V_34 , T_1 * V_31 )
{
union V_18 V_1 ;
int V_19 ;
if ( V_34 > V_35 )
V_34 = V_35 ;
V_1 . V_33 [ 0 ] = V_34 ;
V_19 = F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_22 , V_27 ,
V_36 , & V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
memcpy ( V_31 , & V_1 . V_33 [ 1 ] , V_1 . V_33 [ 0 ] ) ;
return V_1 . V_33 [ 0 ] ;
}
T_4 F_18 ( const struct V_16 * V_17 , T_1 V_27 ,
T_1 V_34 , const T_1 * V_31 )
{
union V_18 V_1 ;
if ( V_34 > V_35 )
V_34 = V_35 ;
V_1 . V_33 [ 0 ] = V_34 ;
memcpy ( V_1 . V_33 + 1 , V_31 , V_34 ) ;
return F_9 ( V_17 -> V_20 , V_17 -> V_10 , V_17 -> V_21 ,
V_26 , V_27 ,
V_36 , & V_1 ) ;
}
static T_4 F_19 ( struct V_37 * V_20 , T_2 V_10 ,
unsigned short V_21 ,
char V_38 , T_1 V_27 , int V_39 ,
union V_18 * V_1 )
{
unsigned char V_40 [ V_35 + 3 ] ;
unsigned char V_41 [ V_35 + 2 ] ;
int V_42 = V_38 == V_22 ? 2 : 1 ;
int V_2 ;
T_1 V_43 = 0 ;
int V_19 ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_10 ,
. V_21 = V_21 ,
. V_12 = 1 ,
. V_11 = V_40 ,
} , {
. V_10 = V_10 ,
. V_21 = V_21 | V_44 ,
. V_12 = 0 ,
. V_11 = V_41 ,
} ,
} ;
V_40 [ 0 ] = V_27 ;
switch ( V_39 ) {
case V_45 :
V_9 [ 0 ] . V_12 = 0 ;
V_9 [ 0 ] . V_21 = V_21 | ( V_38 == V_22 ?
V_44 : 0 ) ;
V_42 = 1 ;
break;
case V_23 :
if ( V_38 == V_22 ) {
V_9 [ 0 ] . V_21 = V_44 | V_21 ;
V_42 = 1 ;
}
break;
case V_28 :
if ( V_38 == V_22 )
V_9 [ 1 ] . V_12 = 1 ;
else {
V_9 [ 0 ] . V_12 = 2 ;
V_40 [ 1 ] = V_1 -> V_24 ;
}
break;
case V_29 :
if ( V_38 == V_22 )
V_9 [ 1 ] . V_12 = 2 ;
else {
V_9 [ 0 ] . V_12 = 3 ;
V_40 [ 1 ] = V_1 -> V_30 & 0xff ;
V_40 [ 2 ] = V_1 -> V_30 >> 8 ;
}
break;
case V_46 :
V_42 = 2 ;
V_38 = V_22 ;
V_9 [ 0 ] . V_12 = 3 ;
V_9 [ 1 ] . V_12 = 2 ;
V_40 [ 1 ] = V_1 -> V_30 & 0xff ;
V_40 [ 2 ] = V_1 -> V_30 >> 8 ;
break;
case V_32 :
if ( V_38 == V_22 ) {
V_9 [ 1 ] . V_21 |= V_47 ;
V_9 [ 1 ] . V_12 = 1 ;
} else {
V_9 [ 0 ] . V_12 = V_1 -> V_33 [ 0 ] + 2 ;
if ( V_9 [ 0 ] . V_12 > V_35 + 2 ) {
F_20 ( & V_20 -> V_48 ,
L_2 ,
V_1 -> V_33 [ 0 ] ) ;
return - V_49 ;
}
for ( V_2 = 1 ; V_2 < V_9 [ 0 ] . V_12 ; V_2 ++ )
V_40 [ V_2 ] = V_1 -> V_33 [ V_2 - 1 ] ;
}
break;
case V_50 :
V_42 = 2 ;
V_38 = V_22 ;
if ( V_1 -> V_33 [ 0 ] > V_35 ) {
F_20 ( & V_20 -> V_48 ,
L_2 ,
V_1 -> V_33 [ 0 ] ) ;
return - V_49 ;
}
V_9 [ 0 ] . V_12 = V_1 -> V_33 [ 0 ] + 2 ;
for ( V_2 = 1 ; V_2 < V_9 [ 0 ] . V_12 ; V_2 ++ )
V_40 [ V_2 ] = V_1 -> V_33 [ V_2 - 1 ] ;
V_9 [ 1 ] . V_21 |= V_47 ;
V_9 [ 1 ] . V_12 = 1 ;
break;
case V_36 :
if ( V_38 == V_22 ) {
V_9 [ 1 ] . V_12 = V_1 -> V_33 [ 0 ] ;
} else {
V_9 [ 0 ] . V_12 = V_1 -> V_33 [ 0 ] + 1 ;
if ( V_9 [ 0 ] . V_12 > V_35 + 1 ) {
F_20 ( & V_20 -> V_48 ,
L_2 ,
V_1 -> V_33 [ 0 ] ) ;
return - V_49 ;
}
for ( V_2 = 1 ; V_2 <= V_1 -> V_33 [ 0 ] ; V_2 ++ )
V_40 [ V_2 ] = V_1 -> V_33 [ V_2 ] ;
}
break;
default:
F_20 ( & V_20 -> V_48 , L_3 , V_39 ) ;
return - V_51 ;
}
V_2 = ( ( V_21 & V_52 ) && V_39 != V_45
&& V_39 != V_36 ) ;
if ( V_2 ) {
if ( ! ( V_9 [ 0 ] . V_21 & V_44 ) ) {
if ( V_42 == 1 )
F_5 ( & V_9 [ 0 ] ) ;
else
V_43 = F_3 ( 0 , & V_9 [ 0 ] ) ;
}
if ( V_9 [ V_42 - 1 ] . V_21 & V_44 )
V_9 [ V_42 - 1 ] . V_12 ++ ;
}
V_19 = F_21 ( V_20 , V_9 , V_42 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_2 && ( V_9 [ V_42 - 1 ] . V_21 & V_44 ) ) {
V_19 = F_6 ( V_43 , & V_9 [ V_42 - 1 ] ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( V_38 == V_22 )
switch ( V_39 ) {
case V_23 :
V_1 -> V_24 = V_40 [ 0 ] ;
break;
case V_28 :
V_1 -> V_24 = V_41 [ 0 ] ;
break;
case V_29 :
case V_46 :
V_1 -> V_30 = V_41 [ 0 ] | ( V_41 [ 1 ] << 8 ) ;
break;
case V_36 :
for ( V_2 = 0 ; V_2 < V_1 -> V_33 [ 0 ] ; V_2 ++ )
V_1 -> V_33 [ V_2 + 1 ] = V_41 [ V_2 ] ;
break;
case V_32 :
case V_50 :
for ( V_2 = 0 ; V_2 < V_41 [ 0 ] + 1 ; V_2 ++ )
V_1 -> V_33 [ V_2 ] = V_41 [ V_2 ] ;
break;
}
return 0 ;
}
T_4 F_9 ( struct V_37 * V_20 , T_2 V_10 , unsigned short V_21 ,
char V_38 , T_1 V_27 , int V_53 ,
union V_18 * V_1 )
{
unsigned long V_54 ;
int V_55 ;
T_4 V_56 ;
F_22 ( V_20 , V_10 , V_21 , V_38 ,
V_27 , V_53 , V_1 ) ;
F_23 ( V_20 , V_10 , V_21 , V_38 ,
V_27 , V_53 ) ;
V_21 &= V_57 | V_52 | V_58 ;
if ( V_20 -> V_59 -> V_60 ) {
F_24 ( V_20 , V_61 ) ;
V_54 = V_62 ;
for ( V_56 = 0 , V_55 = 0 ; V_55 <= V_20 -> V_63 ; V_55 ++ ) {
V_56 = V_20 -> V_59 -> V_60 ( V_20 , V_10 , V_21 ,
V_38 , V_27 ,
V_53 , V_1 ) ;
if ( V_56 != - V_64 )
break;
if ( F_25 ( V_62 ,
V_54 + V_20 -> V_65 ) )
break;
}
F_26 ( V_20 , V_61 ) ;
if ( V_56 != - V_51 || ! V_20 -> V_59 -> V_66 )
goto V_67;
}
V_56 = F_19 ( V_20 , V_10 , V_21 , V_38 ,
V_27 , V_53 , V_1 ) ;
V_67:
F_27 ( V_20 , V_10 , V_21 , V_38 ,
V_27 , V_53 , V_1 ) ;
F_28 ( V_20 , V_10 , V_21 , V_38 ,
V_27 , V_53 , V_56 ) ;
return V_56 ;
}
T_4 F_29 ( const struct V_16 * V_17 ,
T_1 V_27 , T_1 V_34 , T_1 * V_31 )
{
T_1 V_2 = 0 ;
int V_19 ;
if ( V_34 > V_35 )
V_34 = V_35 ;
if ( F_30 ( V_17 -> V_20 , V_68 ) )
return F_17 ( V_17 , V_27 , V_34 , V_31 ) ;
if ( ! F_30 ( V_17 -> V_20 , V_69 ) )
return - V_51 ;
if ( F_30 ( V_17 -> V_20 , V_70 ) ) {
while ( ( V_2 + 2 ) <= V_34 ) {
V_19 = F_13 ( V_17 , V_27 + V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_31 [ V_2 ] = V_19 & 0xff ;
V_31 [ V_2 + 1 ] = V_19 >> 8 ;
V_2 += 2 ;
}
}
while ( V_2 < V_34 ) {
V_19 = F_11 ( V_17 , V_27 + V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_31 [ V_2 ] = V_19 ;
V_2 ++ ;
}
return V_2 ;
}
