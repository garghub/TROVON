static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , int V_5 )
{
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 ,
. V_4 = V_2 -> V_4 ,
. V_5 = V_5 ,
} ;
int V_9 ;
if ( V_2 -> V_10 != V_1 )
V_3 = ( V_3 & 0xc0 ) | ( ( V_3 & 0x0f ) << 2 ) ;
V_2 -> V_8 [ 0 ] = V_3 ;
V_9 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
if ( V_9 )
return V_9 ;
memcpy ( V_4 , V_2 -> V_4 , V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_4 [ 2 ] ;
int V_9 ;
V_9 = F_1 ( V_2 , V_12 ,
V_4 , 2 ) ;
if ( V_9 )
return V_9 ;
return ( V_4 [ 0 ] << 1 ) | ( V_4 [ 1 ] >> 7 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 const * V_14 ,
void * V_15 , int V_5 )
{
const T_1 V_16 [] = { 0 , 4 , 1 , 5 , 2 , 6 , 3 , 7 } ;
T_1 V_3 = ( V_16 [ V_14 -> V_14 ] << 4 ) |
( V_14 -> V_17 ? 0 : 0x80 ) ;
return F_1 ( V_2 , V_3 , V_15 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 const * V_14 )
{
T_1 V_18 ;
return F_4 ( V_2 , V_14 , & V_18 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_13 const * V_14 ,
T_2 * V_15 )
{
return F_4 ( V_2 , V_14 , V_15 , 2 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_19 )
{
return F_1 ( V_2 , V_12 ,
V_19 , sizeof( * V_19 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_20 )
{
if ( ! F_9 ( & V_2 -> V_21 , V_20 ) )
return - V_22 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_13 const * V_14 ,
T_2 * V_19 )
{
int V_9 ;
F_11 ( & V_2 -> V_21 ) ;
V_9 = F_5 ( V_2 , V_14 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_8 ( V_2 , F_12 ( 100 ) ) ;
if ( V_9 )
return V_9 ;
return F_7 ( V_2 , V_19 ) ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_13 const * V_14 , int * V_19 ,
int * V_25 , long V_26 )
{
struct V_1 * V_2 = F_14 ( V_24 ) ;
int V_9 ;
T_2 V_15 ;
switch ( V_26 ) {
case V_27 :
F_15 ( & V_2 -> V_28 ) ;
V_9 = F_10 ( V_2 , V_14 , & V_15 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( V_9 )
return V_9 ;
* V_19 = F_17 ( F_18 ( V_15 ) >> 3 , 12 ) ;
return V_29 ;
case V_30 :
V_9 = F_19 ( V_2 -> V_31 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_19 = V_9 ;
if ( ! F_20 ( V_2 -> V_32 ) ) {
V_9 = F_19 ( V_2 -> V_32 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_19 -= V_9 ;
}
* V_19 /= 1000 ;
* V_25 = V_14 -> V_33 . V_34 - 1 ;
return V_35 ;
case V_36 :
if ( ! F_20 ( V_2 -> V_32 ) ) {
* V_19 = F_19 ( V_2 -> V_32 ) ;
if ( * V_19 < 0 )
return * V_19 ;
} else {
* V_19 = 0 ;
}
* V_19 /= 1000 ;
return V_29 ;
}
return - V_37 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_9 ;
int V_38 ;
T_1 V_3 ;
T_1 V_18 ;
F_11 ( & V_2 -> V_21 ) ;
V_9 = F_1 ( V_2 , V_39 , & V_18 , 1 ) ;
if ( V_9 )
return V_9 ;
V_38 = F_3 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
F_8 ( V_2 , F_12 ( 100 ) ) ;
V_38 = F_3 ( V_2 ) ;
if ( V_38 & V_40 ) {
F_22 ( & V_2 -> V_11 -> V_41 ,
L_1 ,
V_38 ) ;
return - V_42 ;
}
switch ( V_2 -> V_43 ) {
case 6 :
V_3 = V_44 ;
break;
case 10 :
V_3 = V_45 ;
break;
case 18 :
V_3 = V_46 ;
break;
case 34 :
V_3 = V_47 ;
break;
default:
return - V_37 ;
}
return F_1 ( V_2 , V_3 , & V_18 , 1 ) ;
}
static T_3 F_23 ( int V_48 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
struct V_23 * V_52 = V_51 -> V_52 ;
struct V_1 * V_2 = F_14 ( V_52 ) ;
T_2 V_15 [ 20 ] = { } ;
T_2 V_18 ;
int V_9 ;
int V_53 ;
int V_54 = 0 ;
F_15 ( & V_2 -> V_28 ) ;
F_24 (scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct V_13 * V_55 =
& V_52 -> V_56 [ V_53 ] ;
F_11 ( & V_2 -> V_21 ) ;
V_9 = F_6 ( V_2 , V_55 ,
V_54 ? & V_15 [ V_54 - 1 ] : & V_18 ) ;
if ( V_9 ) {
F_22 ( & V_2 -> V_11 -> V_41 ,
L_2 ) ;
goto V_57;
}
V_9 = F_8 ( V_2 , F_12 ( 100 ) ) ;
if ( V_9 ) {
F_22 ( & V_2 -> V_11 -> V_41 , L_3 ) ;
goto V_57;
}
V_54 ++ ;
}
if ( V_54 ) {
V_9 = F_7 ( V_2 , & V_15 [ V_54 - 1 ] ) ;
if ( V_9 ) {
F_22 ( & V_2 -> V_11 -> V_41 ,
L_4 ) ;
goto V_57;
}
}
F_25 ( V_52 , V_15 ,
F_26 ( V_52 ) ) ;
V_57:
F_16 ( & V_2 -> V_28 ) ;
F_27 ( V_52 -> V_58 ) ;
return V_59 ;
}
static T_3 F_28 ( int V_48 , void * V_49 )
{
struct V_23 * V_52 = V_49 ;
struct V_1 * V_2 = F_14 ( V_52 ) ;
V_21 ( & V_2 -> V_21 ) ;
return V_59 ;
}
static int F_29 ( struct V_60 * V_11 )
{
struct V_23 * V_52 ;
struct V_1 * V_2 ;
int V_9 ;
V_52 = F_30 ( & V_11 -> V_41 , sizeof( * V_2 ) ) ;
if ( ! V_52 )
return - V_61 ;
V_2 = F_14 ( V_52 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_10 = F_31 ( V_11 ) -> V_62 ;
F_32 ( & V_2 -> V_28 ) ;
F_33 ( & V_2 -> V_21 ) ;
V_52 -> V_63 = F_31 ( V_11 ) -> V_63 ;
V_52 -> V_41 . V_64 = & V_11 -> V_41 ;
V_52 -> V_65 = & V_66 ;
V_52 -> V_67 = V_68 ;
switch ( V_2 -> V_10 ) {
case V_69 :
case V_70 :
V_52 -> V_56 = V_71 ;
V_52 -> V_72 = F_34 ( V_71 ) ;
break;
case V_1 :
V_52 -> V_56 = V_73 ;
V_52 -> V_72 = F_34 ( V_73 ) ;
break;
default:
return - V_37 ;
}
V_9 = F_35 ( V_11 -> V_41 . V_74 , L_5 ,
& V_2 -> V_43 ) ;
if ( V_9 )
V_2 -> V_43 = 10 ;
V_2 -> V_75 = F_36 ( & V_11 -> V_41 , NULL ) ;
if ( F_20 ( V_2 -> V_75 ) )
return F_37 ( V_2 -> V_75 ) ;
V_2 -> V_31 = F_38 ( & V_11 -> V_41 , L_6 ) ;
if ( F_20 ( V_2 -> V_31 ) )
return F_37 ( V_2 -> V_31 ) ;
V_2 -> V_32 = F_39 ( & V_11 -> V_41 , L_7 ) ;
if ( F_20 ( V_2 -> V_32 ) ) {
V_9 = F_37 ( V_2 -> V_32 ) ;
if ( V_9 != - V_76 )
return V_9 ;
}
V_9 = F_40 ( & V_11 -> V_41 , V_11 -> V_48 , F_28 ,
V_77 , V_52 -> V_63 , V_52 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_41 ( V_2 -> V_75 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_42 ( V_2 -> V_31 ) ;
if ( V_9 )
goto V_78;
if ( ! F_20 ( V_2 -> V_32 ) ) {
V_9 = F_42 ( V_2 -> V_32 ) ;
if ( V_9 )
goto V_79;
}
V_9 = F_21 ( V_2 ) ;
if ( V_9 )
goto V_80;
F_43 ( V_11 , V_52 ) ;
V_9 = F_44 ( V_52 , NULL ,
F_23 , NULL ) ;
if ( V_9 )
goto V_80;
V_9 = F_45 ( V_52 ) ;
if ( V_9 )
goto V_81;
return 0 ;
V_81:
F_46 ( V_52 ) ;
V_80:
if ( ! F_20 ( V_2 -> V_32 ) )
F_47 ( V_2 -> V_32 ) ;
V_79:
F_47 ( V_2 -> V_31 ) ;
V_78:
F_48 ( V_2 -> V_75 ) ;
return V_9 ;
}
static int F_49 ( struct V_60 * V_11 )
{
struct V_23 * V_52 = F_50 ( V_11 ) ;
struct V_1 * V_2 = F_14 ( V_52 ) ;
F_51 ( V_52 ) ;
F_46 ( V_52 ) ;
if ( ! F_20 ( V_2 -> V_32 ) )
F_47 ( V_2 -> V_32 ) ;
F_47 ( V_2 -> V_31 ) ;
F_48 ( V_2 -> V_75 ) ;
return 0 ;
}
