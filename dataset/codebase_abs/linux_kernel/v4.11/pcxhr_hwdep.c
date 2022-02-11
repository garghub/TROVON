static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
int V_6 ;
if ( V_2 -> V_7 )
V_6 = V_2 -> V_8 * 2 ;
else
V_6 = V_2 -> V_8 ;
V_6 += V_2 -> V_9 * V_10 ;
F_2 ( V_2 ) ;
F_3 ( & V_5 , V_11 ) ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_5 . V_12 [ 0 ] & V_13 ) < V_2 -> V_9 * 2 )
return - V_14 ;
if ( ( ( V_5 . V_12 [ 0 ] >> ( 2 * V_15 ) ) & V_13 ) <
V_2 -> V_8 * 2 )
return - V_14 ;
if ( ( V_5 . V_12 [ 1 ] & 0x5F ) < V_6 )
return - V_14 ;
if ( ( ( V_5 . V_12 [ 1 ] >> 7 ) & 0x5F ) < V_10 )
return - V_14 ;
F_5 ( & V_2 -> V_16 -> V_17 ,
L_1 ,
V_5 . V_12 [ 2 ] , V_5 . V_12 [ 3 ] ) ;
F_3 ( & V_5 , V_18 ) ;
V_5 . V_19 [ 0 ] |= V_2 -> V_20 ;
V_5 . V_19 [ 1 ] = ( 1 << 23 ) + V_2 -> V_21 ;
V_5 . V_22 = 2 ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
F_5 ( & V_2 -> V_16 -> V_17 ,
L_2 , ( V_5 . V_12 [ 0 ] >> 16 ) & 0xff ,
( V_5 . V_12 [ 0 ] >> 8 ) & 0xff , V_5 . V_12 [ 0 ] & 0xff ) ;
V_2 -> V_23 = V_5 . V_12 [ 0 ] ;
if ( V_2 -> V_24 )
V_3 = F_6 ( V_2 ) ;
else
V_3 = F_7 ( V_2 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 ;
F_3 ( & V_5 , V_25 ) ;
V_5 . V_19 [ 0 ] |= V_26 ;
V_5 . V_19 [ 1 ] = V_27 ;
V_5 . V_22 = 2 ;
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_5 . V_12 [ 1 ] & V_28 ) ==
V_29 )
V_2 -> V_30 = 1 ;
V_3 = F_8 ( V_2 , V_31 ,
V_31 , NULL ) ;
if ( V_3 )
return V_3 ;
F_3 ( & V_5 , V_25 ) ;
V_5 . V_19 [ 0 ] |= V_32 ;
if ( F_9 ( V_2 ) ) {
V_5 . V_19 [ 1 ] = 1 ;
V_5 . V_22 = 2 ;
}
V_3 = F_4 ( V_2 , & V_5 ) ;
return V_3 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
if ( V_2 -> V_33 & ( 1 << V_34 ) ) {
if ( ! V_2 -> V_24 ) {
F_3 ( & V_5 , V_35 ) ;
V_5 . V_19 [ 0 ] |= V_32 ;
F_4 ( V_2 , & V_5 ) ;
F_8 ( V_2 , V_31 ,
0 , NULL ) ;
}
}
if ( V_2 -> V_33 & ( 1 << V_36 ) )
F_11 ( V_2 ) ;
if ( V_2 -> V_33 & ( 1 << V_37 ) ) {
F_12 ( V_2 ) ;
V_2 -> V_33 = 1 ;
}
return;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_40 , int V_41 )
{
int V_42 , V_43 ;
int V_3 ;
struct V_4 V_5 ;
if ( V_40 ) {
V_42 = 1 ;
if ( V_2 -> V_7 )
V_43 = 1 ;
else
V_43 = 2 ;
} else {
V_42 = V_10 ;
V_43 = 2 ;
}
F_5 ( & V_2 -> V_16 -> V_17 , L_3 ,
V_41 , V_40 ? 'c' : 'p' ) ;
V_39 -> V_40 = V_40 ;
V_39 -> V_44 = V_41 ;
F_3 ( & V_5 , V_45 ) ;
F_14 ( & V_5 , V_40 , V_41 ,
V_43 , V_42 ) ;
V_5 . V_19 [ 1 ] |= 0x020000 ;
if ( F_9 ( V_2 ) ) {
V_5 . V_19 [ V_5 . V_22 ++ ] = ( V_43 == 1 ) ? 0x01 : 0x03 ;
}
V_3 = F_4 ( V_2 , & V_5 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_16 -> V_17 , L_4
L_5 , V_3 ) ;
return V_3 ;
}
V_39 -> V_46 = V_47 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 , V_48 , V_49 ;
struct V_50 * V_51 ;
struct V_38 * V_39 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_52 ; V_48 ++ ) {
V_51 = V_2 -> V_51 [ V_48 ] ;
if ( V_51 -> V_53 ) {
V_39 = & V_51 -> V_54 ;
V_3 = F_13 ( V_2 , V_39 , 0 , V_48 * 2 ) ;
if ( V_3 )
return V_3 ;
for( V_49 = 0 ; V_49 < V_51 -> V_53 ; V_49 ++ )
V_51 -> V_55 [ V_49 ] . V_39 = V_39 ;
}
for ( V_49 = 0 ; V_49 < V_51 -> V_56 ; V_49 ++ ) {
V_39 = & V_51 -> V_57 [ V_49 ] ;
V_3 = F_13 ( V_2 , V_39 , 1 , V_48 * 2 + V_49 ) ;
if ( V_3 )
return V_3 ;
V_51 -> V_58 [ V_49 ] . V_39 = V_39 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_48 , V_49 ;
struct V_50 * V_51 ;
int V_59 = 0 ;
int V_60 = 0 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_52 ; V_48 ++ ) {
V_51 = V_2 -> V_51 [ V_48 ] ;
if ( V_51 -> V_53 )
V_59 |= 1 << V_51 -> V_54 . V_44 ;
for ( V_49 = 0 ; V_49 < V_51 -> V_56 ; V_49 ++ )
V_60 |= 1 << V_51 -> V_57 [ V_49 ] . V_44 ;
}
return F_18 ( V_2 , V_59 , V_60 , 1 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_61 ,
const struct V_62 * V_63 )
{
int V_3 , V_64 ;
F_5 ( & V_2 -> V_16 -> V_17 ,
L_6 , V_61 , V_63 -> V_65 ) ;
switch ( V_61 ) {
case V_66 :
F_12 ( V_2 ) ;
return F_20 ( V_2 , V_63 , 0 ) ;
case V_37 :
F_12 ( V_2 ) ;
return F_20 ( V_2 , V_63 , 1 ) ;
case V_36 :
F_11 ( V_2 ) ;
return F_21 ( V_2 , V_63 ) ;
case V_67 :
return F_22 ( V_2 , V_63 ) ;
case V_34 :
V_3 = F_23 ( V_2 , V_63 ) ;
if ( V_3 )
return V_3 ;
break;
default:
F_15 ( & V_2 -> V_16 -> V_17 , L_7 ) ;
return - V_68 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_16 -> V_17 , L_8 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_16 -> V_17 , L_9 ) ;
return V_3 ;
}
for ( V_64 = 0 ; V_64 < V_2 -> V_52 ; V_64 ++ ) {
struct V_50 * V_51 = V_2 -> V_51 [ V_64 ] ;
if ( ( V_3 = F_24 ( V_51 ) ) < 0 )
return V_3 ;
if ( V_64 == 0 ) {
if ( ( V_3 = F_25 ( V_51 -> V_2 ) ) < 0 )
return V_3 ;
}
if ( ( V_3 = F_26 ( V_51 -> V_69 ) ) < 0 )
return V_3 ;
}
V_3 = F_17 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_16 -> V_17 , L_10 ) ;
return V_3 ;
}
F_5 ( & V_2 -> V_16 -> V_17 ,
L_11 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
static char * V_70 [] [ 5 ] = {
[ 0 ] = { L_12 , L_13 ,
L_14 , L_15 , L_16 } ,
[ 1 ] = { L_12 , L_17 ,
L_14 , L_18 , L_16 } ,
[ 2 ] = { L_12 , L_19 ,
L_14 , L_20 , L_21 } ,
[ 3 ] = { L_12 , L_22 ,
L_14 , L_23 , L_21 } ,
[ 4 ] = { NULL , L_24 ,
L_25 , L_26 , L_27 } ,
[ 5 ] = { NULL , L_28 ,
L_25 , L_26 , L_27 } ,
} ;
char V_71 [ 32 ] ;
const struct V_62 * V_72 ;
int V_48 , V_3 ;
int V_73 = V_2 -> V_74 ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ ) {
if ( ! V_70 [ V_73 ] [ V_48 ] )
continue;
sprintf ( V_71 , L_29 , V_70 [ V_73 ] [ V_48 ] ) ;
if ( F_28 ( & V_72 , V_71 , & V_2 -> V_16 -> V_17 ) ) {
F_15 ( & V_2 -> V_16 -> V_17 ,
L_30 ,
V_71 ) ;
return - V_75 ;
}
V_3 = F_19 ( V_2 , V_48 , V_72 ) ;
F_29 ( V_72 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_33 |= 1 << V_48 ;
}
return 0 ;
}
