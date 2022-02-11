static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
unsigned int V_11 ;
int V_12 [ 2 ] ;
int V_13 ;
V_13 = F_5 ( V_9 -> V_14 [ V_10 -> V_15 ] , & V_11 ) ;
if ( V_13 )
return V_13 ;
if ( V_11 >= V_10 -> V_16 )
return - V_17 ;
V_12 [ 0 ] = V_10 -> V_18 [ V_11 ] . integer ;
V_12 [ 1 ] = V_10 -> V_18 [ V_11 ] . V_19 ;
return F_6 ( V_5 , V_20 , 2 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_10 = F_4 ( V_4 ) ;
int V_22 , integer , V_19 , V_13 ;
V_13 = F_8 ( V_5 , 100000 , & integer , & V_19 ) ;
if ( V_13 )
return V_13 ;
for ( V_22 = 0 ; V_22 < V_10 -> V_16 ; V_22 ++ )
if ( V_10 -> V_18 [ V_22 ] . integer == integer &&
V_10 -> V_18 [ V_22 ] . V_19 == V_19 )
break;
if ( V_22 == V_10 -> V_16 )
return - V_17 ;
V_13 = F_9 ( V_9 -> V_14 [ V_10 -> V_15 ] , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_21 ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_23 , T_3 * V_22 )
{
T_4 V_24 [ 4 ] = { V_25 , 0x0 , 0x0 , V_26 } ;
T_4 V_27 [ 3 ] ;
int V_13 ;
V_13 = F_11 ( V_9 -> V_28 , V_24 , 4 , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_9 -> V_28 , & V_23 , 1 , V_27 , 3 ) ;
if ( V_13 )
return V_13 ;
* V_22 = ( V_27 [ 0 ] << 16 ) |
( V_27 [ 1 ] << 8 ) |
( V_27 [ 2 ] ) ;
V_24 [ 3 ] = V_29 ;
V_13 = F_11 ( V_9 -> V_28 , V_24 , 4 , NULL , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_30 const * V_31 ,
int * V_22 , int * V_32 , long V_33 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_23 = V_34 [ V_31 -> V_35 ] ;
unsigned int V_15 = V_36 [ V_31 -> V_35 ] ;
int V_13 ;
switch ( V_31 -> type ) {
case V_37 :
switch ( V_33 ) {
case V_38 :
V_13 = F_10 ( V_9 , V_23 , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_39 ;
}
break;
case V_40 :
switch ( V_33 ) {
case V_38 :
V_13 = F_5 ( V_9 -> V_14 [ V_15 ] , V_22 ) ;
if ( V_13 )
return V_13 ;
return V_39 ;
case V_41 :
* V_22 = 0 ;
* V_32 = 800000 ;
return V_20 ;
}
break;
default:
break;
}
return - V_17 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_30 const * V_31 ,
int V_22 , int V_32 , long V_33 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_15 = V_36 [ V_31 -> V_35 ] ;
switch ( V_31 -> type ) {
case V_40 :
switch ( V_33 ) {
case V_38 :
return F_9 ( V_9 -> V_14 [ V_15 ] , V_22 ) ;
}
break;
default:
break;
}
return - V_17 ;
}
static T_5 F_14 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_6 * V_7 = V_45 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 , V_46 , V_47 = 0 ;
T_6 V_48 [ 8 ] ;
T_4 V_24 [ 4 ] = { V_25 , 0x0 , 0x0 , V_26 } ;
T_4 V_27 [ 3 ] ;
V_13 = F_11 ( V_9 -> V_28 , V_24 , 4 , NULL , 0 ) ;
if ( V_13 )
goto V_49;
F_15 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_13 = F_11 ( V_9 -> V_28 ,
& V_34 [ V_46 ] , 1 ,
V_27 , 3 ) ;
if ( V_13 )
goto V_49;
V_48 [ V_47 ++ ] = ( V_27 [ 0 ] << 16 ) |
( V_27 [ 1 ] << 8 ) |
( V_27 [ 2 ] ) ;
}
V_24 [ 3 ] = V_29 ;
V_13 = F_11 ( V_9 -> V_28 , V_24 , 4 , NULL , 0 ) ;
if ( V_13 )
goto V_49;
F_16 ( V_7 , V_48 , V_45 -> V_50 ) ;
V_49:
F_17 ( V_7 -> V_51 ) ;
return V_52 ;
}
static int T_7 F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_19 ( F_20 ( V_2 ) ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_21 ( V_9 -> V_53 , V_54 ,
V_55 ,
V_55 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_22 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_23 ( V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int T_7 F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_19 ( F_20 ( V_2 ) ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_25 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_23 ( V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_21 ( V_9 -> V_53 , V_54 ,
V_55 , 0 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_26 ( struct V_57 * V_28 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_47 , V_13 ;
V_7 = F_27 ( & V_28 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_58 ;
V_9 = F_3 ( V_7 ) ;
F_28 ( V_28 , V_7 ) ;
V_9 -> V_2 = & V_28 -> V_2 ;
V_9 -> V_28 = V_28 ;
V_9 -> V_42 = V_28 -> V_42 ;
V_9 -> V_53 = F_29 ( V_28 , & V_59 ) ;
if ( F_30 ( V_9 -> V_53 ) ) {
F_23 ( V_9 -> V_2 , L_3 ) ;
return F_31 ( V_9 -> V_53 ) ;
}
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
V_9 -> V_14 [ V_47 ] = F_32 ( V_9 -> V_2 , V_9 -> V_53 ,
V_61 [ V_47 ] ) ;
if ( F_30 ( V_9 -> V_14 [ V_47 ] ) ) {
F_23 ( V_9 -> V_2 , L_4 ) ;
return F_31 ( V_9 -> V_14 [ V_47 ] ) ;
}
}
V_9 -> V_56 = F_33 ( V_9 -> V_2 , L_5 ) ;
if ( F_30 ( V_9 -> V_56 ) ) {
F_23 ( V_9 -> V_2 , L_6 ) ;
return F_31 ( V_9 -> V_56 ) ;
}
V_13 = F_25 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_2 ) ;
return V_13 ;
}
V_13 = F_34 ( V_9 -> V_53 , V_25 ,
V_62 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_7 ) ;
goto V_63;
}
V_13 = F_35 ( V_9 -> V_53 , V_64 ,
F_36 ( V_64 ) ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_8 ) ;
goto V_63;
}
V_7 -> V_65 = V_66 ;
V_7 -> V_2 . V_67 = V_9 -> V_2 ;
V_7 -> V_68 = V_69 ;
V_7 -> V_70 = F_36 ( V_69 ) ;
V_7 -> V_71 = V_72 ;
V_7 -> V_73 = & V_74 ;
if ( V_9 -> V_42 > 0 ) {
V_9 -> V_51 = F_37 ( V_9 -> V_2 ,
L_9 ,
V_7 -> V_71 ,
V_7 -> V_75 ) ;
if ( ! V_9 -> V_51 ) {
F_23 ( V_9 -> V_2 , L_10 ) ;
V_13 = - V_58 ;
goto V_63;
}
F_38 ( V_9 -> V_51 , V_7 ) ;
V_9 -> V_51 -> V_76 = & V_77 ;
V_9 -> V_51 -> V_2 . V_67 = V_9 -> V_2 ;
V_13 = F_39 ( V_9 -> V_51 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_11 ) ;
goto V_63;
}
V_13 = F_40 ( V_9 -> V_2 , V_9 -> V_42 ,
V_78 ,
NULL , V_79 ,
V_72 ,
V_9 -> V_51 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_12 ) ;
goto V_80;
}
}
V_13 = F_41 ( V_7 , & V_81 ,
F_14 , NULL ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_13 ) ;
goto V_80;
}
V_13 = F_42 ( V_7 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_14 ) ;
goto V_82;
}
return 0 ;
V_82:
F_43 ( V_7 ) ;
V_80:
if ( V_9 -> V_42 > 0 )
F_44 ( V_9 -> V_51 ) ;
V_63:
F_22 ( V_9 -> V_56 ) ;
return V_13 ;
}
static int F_45 ( struct V_57 * V_28 )
{
struct V_6 * V_7 = F_19 ( V_28 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
F_46 ( V_7 ) ;
F_43 ( V_7 ) ;
if ( V_9 -> V_42 > 0 )
F_44 ( V_9 -> V_51 ) ;
V_13 = F_22 ( V_9 -> V_56 ) ;
if ( V_13 ) {
F_23 ( V_9 -> V_2 , L_1 ) ;
return V_13 ;
}
return 0 ;
}
