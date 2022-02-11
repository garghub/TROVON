static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
unsigned int V_11 , type ;
int V_12 [ 2 ] ;
int V_13 , V_14 ;
V_13 = F_5 ( V_9 -> V_15 , V_10 -> V_16 , & V_11 ) ;
if ( V_13 )
return V_13 ;
V_11 &= V_10 -> V_17 ;
V_11 >>= V_10 -> V_18 ;
switch ( V_10 -> type ) {
case V_19 :
type = V_20 ;
V_14 = 1 ;
V_12 [ 0 ] = V_11 ;
break;
case V_21 :
case V_22 :
type = V_23 ;
V_14 = 2 ;
if ( V_11 < V_10 -> V_24 ) {
V_12 [ 0 ] = V_10 -> V_25 [ V_11 ] . integer ;
V_12 [ 1 ] = V_10 -> V_25 [ V_11 ] . V_26 ;
break;
}
return - V_27 ;
default:
return - V_27 ;
}
return F_6 ( V_5 , type , V_14 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
int V_29 , integer , V_26 , V_13 ;
V_13 = F_8 ( V_5 , 100000 , & integer , & V_26 ) ;
if ( V_13 )
return V_13 ;
switch ( V_10 -> type ) {
case V_19 :
V_29 = integer ;
break;
case V_21 :
case V_22 :
for ( V_29 = 0 ; V_29 < V_10 -> V_24 ; V_29 ++ )
if ( V_10 -> V_25 [ V_29 ] . integer == integer &&
V_10 -> V_25 [ V_29 ] . V_26 == V_26 )
break;
if ( V_29 == V_10 -> V_24 )
return - V_27 ;
break;
default:
return - V_27 ;
}
V_13 = F_9 ( V_9 -> V_15 , V_10 -> V_16 ,
V_10 -> V_17 ,
( V_29 << V_10 -> V_18 ) ) ;
if ( V_13 )
return V_13 ;
return V_28 ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_16 , T_3 * V_29 )
{
T_4 V_30 [ 4 ] = { V_31 , 0x0 , 0x0 , V_32 } ;
T_4 V_33 [ 3 ] ;
int V_13 ;
V_13 = F_11 ( V_9 -> V_34 , V_30 , 4 , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_9 -> V_34 , & V_16 , 1 , V_33 , 3 ) ;
if ( V_13 )
return V_13 ;
* V_29 = ( V_33 [ 0 ] << 16 ) |
( V_33 [ 1 ] << 8 ) |
( V_33 [ 2 ] ) ;
V_30 [ 3 ] = V_35 ;
V_13 = F_11 ( V_9 -> V_34 , V_30 , 4 , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_36 const * V_37 ,
int * V_29 , int * V_38 , long V_17 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_39 V_40 = V_41 [ V_37 -> V_42 ] ;
int V_13 ;
switch ( V_37 -> type ) {
case V_43 :
switch ( V_17 ) {
case V_44 :
V_13 = F_10 ( V_9 , V_40 . V_16 , V_29 ) ;
if ( V_13 )
return V_13 ;
return V_20 ;
case V_45 :
V_13 = F_5 ( V_9 -> V_15 , V_40 . V_46 ,
V_29 ) ;
if ( V_13 )
return V_13 ;
* V_29 &= V_40 . V_17 ;
* V_29 >>= V_40 . V_18 ;
return V_20 ;
}
break;
case V_47 :
switch ( V_17 ) {
case V_44 :
V_13 = F_5 ( V_9 -> V_15 , V_40 . V_16 , V_29 ) ;
if ( V_13 )
return V_13 ;
* V_29 &= V_40 . V_17 ;
* V_29 >>= V_40 . V_18 ;
return V_20 ;
case V_48 :
* V_29 = 0 ;
* V_38 = 800000 ;
return V_23 ;
}
break;
default:
break;
}
return - V_27 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_36 const * V_37 ,
int V_29 , int V_38 , long V_17 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_39 V_40 = V_41 [ V_37 -> V_42 ] ;
switch ( V_37 -> type ) {
case V_43 :
switch ( V_17 ) {
case V_45 :
return F_9 ( V_9 -> V_15 ,
V_40 . V_46 ,
V_40 . V_17 ,
( V_29 << V_40 . V_18 ) ) ;
}
break;
case V_47 :
switch ( V_17 ) {
case V_44 :
return F_9 ( V_9 -> V_15 ,
V_40 . V_16 ,
V_40 . V_17 ,
( V_29 << V_40 . V_18 ) ) ;
}
break;
default:
break;
}
return - V_27 ;
}
static T_5 F_14 ( int V_49 , void * V_50 )
{
struct V_51 * V_52 = V_50 ;
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 , V_53 , V_54 = 0 ;
T_6 V_55 [ 8 ] ;
T_4 V_30 [ 4 ] = { V_31 , 0x0 , 0x0 , V_32 } ;
T_4 V_33 [ 3 ] ;
V_13 = F_11 ( V_9 -> V_34 , V_30 , 4 , NULL , 0 ) ;
if ( V_13 )
goto V_56;
F_15 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_11 ( V_9 -> V_34 ,
& V_41 [ V_53 ] . V_16 , 1 ,
V_33 , 3 ) ;
if ( V_13 )
goto V_56;
V_55 [ V_54 ++ ] = ( V_33 [ 0 ] << 16 ) |
( V_33 [ 1 ] << 8 ) |
( V_33 [ 2 ] ) ;
}
V_30 [ 3 ] = V_35 ;
V_13 = F_11 ( V_9 -> V_34 , V_30 , 4 , NULL , 0 ) ;
if ( V_13 )
goto V_56;
F_16 ( V_7 , V_55 , V_52 -> V_57 ) ;
V_56:
F_17 ( V_7 -> V_58 ) ;
return V_59 ;
}
static int T_7 F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_9 ( V_9 -> V_15 , V_60 ,
V_61 ,
V_61 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_19 ( V_9 -> V_62 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int T_7 F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_22 ( V_9 -> V_62 ) ;
if ( V_13 ) {
F_20 ( V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_9 ( V_9 -> V_15 , V_60 ,
V_61 , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_23 ( struct V_63 * V_34 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_13 ;
V_7 = F_24 ( & V_34 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_64 ;
V_9 = F_3 ( V_7 ) ;
F_25 ( V_34 , V_7 ) ;
V_9 -> V_2 = & V_34 -> V_2 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_49 = V_34 -> V_49 ;
V_9 -> V_15 = F_26 ( V_34 , & V_65 ) ;
if ( F_27 ( V_9 -> V_15 ) ) {
F_20 ( V_9 -> V_2 , L_3 ) ;
return F_28 ( V_9 -> V_15 ) ;
}
V_9 -> V_62 = F_29 ( V_9 -> V_2 , L_4 ) ;
if ( F_27 ( V_9 -> V_62 ) ) {
F_20 ( V_9 -> V_2 , L_5 ) ;
return F_28 ( V_9 -> V_62 ) ;
}
V_13 = F_22 ( V_9 -> V_62 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_30 ( V_9 -> V_15 , V_31 ,
V_66 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_6 ) ;
goto V_67;
}
V_13 = F_31 ( V_9 -> V_15 , V_68 ,
F_32 ( V_68 ) ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_7 ) ;
goto V_67;
}
V_7 -> V_69 = V_70 ;
V_7 -> V_2 . V_71 = V_9 -> V_2 ;
V_7 -> V_72 = V_73 ;
V_7 -> V_74 = F_32 ( V_73 ) ;
V_7 -> V_75 = V_76 ;
V_7 -> V_77 = & V_78 ;
if ( V_9 -> V_49 > 0 ) {
V_9 -> V_58 = F_33 ( V_9 -> V_2 ,
L_8 ,
V_7 -> V_75 ,
V_7 -> V_79 ) ;
if ( ! V_9 -> V_58 ) {
F_20 ( V_9 -> V_2 , L_9 ) ;
V_13 = - V_64 ;
goto V_67;
}
F_34 ( V_9 -> V_58 , V_7 ) ;
V_9 -> V_58 -> V_80 = & V_81 ;
V_9 -> V_58 -> V_2 . V_71 = V_9 -> V_2 ;
V_13 = F_35 ( V_9 -> V_58 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_10 ) ;
goto V_67;
}
V_13 = F_36 ( V_9 -> V_2 , V_9 -> V_49 ,
V_82 ,
NULL , V_83 ,
V_76 ,
V_9 -> V_58 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_11 ) ;
goto V_84;
}
}
V_13 = F_37 ( V_7 , & V_85 ,
F_14 , NULL ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_12 ) ;
goto V_84;
}
V_13 = F_38 ( V_7 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_13 ) ;
goto V_86;
}
return 0 ;
V_86:
F_39 ( V_7 ) ;
V_84:
if ( V_9 -> V_49 > 0 )
F_40 ( V_9 -> V_58 ) ;
V_67:
F_19 ( V_9 -> V_62 ) ;
return V_13 ;
}
static int F_41 ( struct V_63 * V_34 )
{
struct V_6 * V_7 = F_42 ( V_34 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
F_43 ( V_7 ) ;
F_39 ( V_7 ) ;
if ( V_9 -> V_49 > 0 )
F_40 ( V_9 -> V_58 ) ;
V_13 = F_19 ( V_9 -> V_62 ) ;
if ( V_13 ) {
F_20 ( V_9 -> V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
