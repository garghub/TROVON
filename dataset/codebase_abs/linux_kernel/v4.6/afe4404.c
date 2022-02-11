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
static int F_10 ( struct V_6 * V_7 ,
struct V_30 const * V_31 ,
int * V_29 , int * V_32 , long V_17 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_33 V_34 = V_35 [ V_31 -> V_36 ] ;
int V_13 ;
switch ( V_31 -> type ) {
case V_37 :
switch ( V_17 ) {
case V_38 :
V_13 = F_5 ( V_9 -> V_15 , V_34 . V_16 , V_29 ) ;
if ( V_13 )
return V_13 ;
return V_20 ;
case V_39 :
V_13 = F_5 ( V_9 -> V_15 , V_34 . V_40 ,
V_29 ) ;
if ( V_13 )
return V_13 ;
* V_29 &= V_34 . V_17 ;
* V_29 >>= V_34 . V_18 ;
return V_20 ;
}
break;
case V_41 :
switch ( V_17 ) {
case V_38 :
V_13 = F_5 ( V_9 -> V_15 , V_34 . V_16 , V_29 ) ;
if ( V_13 )
return V_13 ;
* V_29 &= V_34 . V_17 ;
* V_29 >>= V_34 . V_18 ;
return V_20 ;
case V_42 :
* V_29 = 0 ;
* V_32 = 800000 ;
return V_23 ;
}
break;
default:
break;
}
return - V_27 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_30 const * V_31 ,
int V_29 , int V_32 , long V_17 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
const struct V_33 V_34 = V_35 [ V_31 -> V_36 ] ;
switch ( V_31 -> type ) {
case V_37 :
switch ( V_17 ) {
case V_39 :
return F_9 ( V_9 -> V_15 ,
V_34 . V_40 ,
V_34 . V_17 ,
( V_29 << V_34 . V_18 ) ) ;
}
break;
case V_41 :
switch ( V_17 ) {
case V_38 :
return F_9 ( V_9 -> V_15 ,
V_34 . V_16 ,
V_34 . V_17 ,
( V_29 << V_34 . V_18 ) ) ;
}
break;
default:
break;
}
return - V_27 ;
}
static T_3 F_12 ( int V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 , V_47 , V_48 = 0 ;
T_4 V_49 [ 10 ] ;
F_13 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_5 ( V_9 -> V_15 , V_35 [ V_47 ] . V_16 ,
& V_49 [ V_48 ++ ] ) ;
if ( V_13 )
goto V_50;
}
F_14 ( V_7 , V_49 , V_46 -> V_51 ) ;
V_50:
F_15 ( V_7 -> V_52 ) ;
return V_53 ;
}
static int T_5 F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_9 ( V_9 -> V_15 , V_54 ,
V_55 ,
V_55 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_17 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_18 ( V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int T_5 F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_20 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_18 ( V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_9 ( V_9 -> V_15 , V_54 ,
V_55 , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 ,
const struct V_59 * V_60 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_13 ;
V_7 = F_22 ( & V_58 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_61 ;
V_9 = F_3 ( V_7 ) ;
F_23 ( V_58 , V_7 ) ;
V_9 -> V_2 = & V_58 -> V_2 ;
V_9 -> V_43 = V_58 -> V_43 ;
V_9 -> V_15 = F_24 ( V_58 , & V_62 ) ;
if ( F_25 ( V_9 -> V_15 ) ) {
F_18 ( V_9 -> V_2 , L_3 ) ;
return F_26 ( V_9 -> V_15 ) ;
}
V_9 -> V_56 = F_27 ( V_9 -> V_2 , L_4 ) ;
if ( F_25 ( V_9 -> V_56 ) ) {
F_18 ( V_9 -> V_2 , L_5 ) ;
return F_26 ( V_9 -> V_56 ) ;
}
V_13 = F_20 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_28 ( V_9 -> V_15 , V_63 ,
V_64 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_6 ) ;
goto V_65;
}
V_13 = F_29 ( V_9 -> V_15 , V_66 ,
F_30 ( V_66 ) ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_7 ) ;
goto V_65;
}
V_7 -> V_67 = V_68 ;
V_7 -> V_2 . V_69 = V_9 -> V_2 ;
V_7 -> V_70 = V_71 ;
V_7 -> V_72 = F_30 ( V_71 ) ;
V_7 -> V_73 = V_74 ;
V_7 -> V_75 = & V_76 ;
if ( V_9 -> V_43 > 0 ) {
V_9 -> V_52 = F_31 ( V_9 -> V_2 ,
L_8 ,
V_7 -> V_73 ,
V_7 -> V_60 ) ;
if ( ! V_9 -> V_52 ) {
F_18 ( V_9 -> V_2 , L_9 ) ;
V_13 = - V_61 ;
goto V_65;
}
F_32 ( V_9 -> V_52 , V_7 ) ;
V_9 -> V_52 -> V_77 = & V_78 ;
V_9 -> V_52 -> V_2 . V_69 = V_9 -> V_2 ;
V_13 = F_33 ( V_9 -> V_52 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_10 ) ;
goto V_65;
}
V_13 = F_34 ( V_9 -> V_2 , V_9 -> V_43 ,
V_79 ,
NULL , V_80 ,
V_74 ,
V_9 -> V_52 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_11 ) ;
goto V_65;
}
}
V_13 = F_35 ( V_7 , & V_81 ,
F_12 , NULL ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_12 ) ;
goto V_82;
}
V_13 = F_36 ( V_7 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_13 ) ;
goto V_83;
}
return 0 ;
V_83:
F_37 ( V_7 ) ;
V_82:
if ( V_9 -> V_43 > 0 )
F_38 ( V_9 -> V_52 ) ;
V_65:
F_17 ( V_9 -> V_56 ) ;
return V_13 ;
}
static int F_39 ( struct V_57 * V_58 )
{
struct V_6 * V_7 = F_40 ( V_58 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
F_41 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( V_9 -> V_43 > 0 )
F_38 ( V_9 -> V_52 ) ;
V_13 = F_17 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_18 ( V_9 -> V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
