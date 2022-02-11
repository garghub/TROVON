static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 50 ;
int V_4 ;
while ( V_3 -- ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_7 )
break;
F_3 ( 20 ) ;
}
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_5 -> V_8 , L_1 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_12 const * V_13 ,
int * V_14 , int * V_15 , long V_16 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_4 ;
switch ( V_16 ) {
case V_17 :
V_4 = F_7 ( V_11 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_8 ( V_11 ) ;
return V_4 ;
}
V_4 = F_9 ( V_2 -> V_5 , V_13 -> V_18 ) ;
F_8 ( V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = V_4 ;
return V_19 ;
case V_20 :
* V_14 = V_21 [ V_2 -> V_22 &
V_23 ] ;
return V_19 ;
case V_24 :
* V_14 = 0 ;
* V_15 = ( 256 - V_2 -> V_25 ) * 2400 ;
return V_26 ;
}
return - V_27 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_12 const * V_13 ,
int V_14 , int V_15 , long V_16 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_28 ;
switch ( V_16 ) {
case V_20 :
if ( V_15 != 0 )
return - V_27 ;
for ( V_28 = 0 ; V_28 < F_11 ( V_21 ) ; V_28 ++ ) {
if ( V_14 == V_21 [ V_28 ] ) {
V_2 -> V_22 &= ~ V_23 ;
V_2 -> V_22 |= V_28 ;
return F_12 (
V_2 -> V_5 , V_29 ,
V_2 -> V_22 ) ;
}
}
return - V_27 ;
case V_24 :
if ( V_14 != 0 )
return - V_27 ;
for ( V_28 = 0 ; V_28 < 256 ; V_28 ++ ) {
if ( V_15 == ( 256 - V_28 ) * 2400 ) {
V_2 -> V_25 = V_28 ;
return F_13 (
V_2 -> V_5 , V_30 ,
V_2 -> V_25 ) ;
}
}
return - V_27 ;
}
return - V_27 ;
}
static T_1 F_14 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_10 * V_11 = V_34 -> V_11 ;
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_28 , V_35 = 0 ;
int V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
goto V_36;
F_15 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_4 = F_9 ( V_2 -> V_5 ,
V_37 + 2 * V_28 ) ;
if ( V_4 < 0 )
goto V_36;
V_2 -> V_38 [ V_35 ++ ] = V_4 ;
}
F_16 ( V_11 , V_2 -> V_38 ,
F_17 ( V_11 ) ) ;
V_36:
F_18 ( V_11 -> V_39 ) ;
return V_40 ;
}
static T_2 F_19 ( struct V_41 * V_8 ,
struct V_42 * V_43 ,
char * V_44 )
{
T_3 V_45 = 0 ;
int V_28 ;
for ( V_28 = 1 ; V_28 <= 256 ; V_28 ++ )
V_45 += F_20 ( V_44 + V_45 , V_46 - V_45 , L_2 ,
2400 * V_28 ) ;
V_44 [ V_45 - 1 ] = '\n' ;
return V_45 ;
}
static int F_21 ( struct V_47 * V_5 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_4 ;
V_11 = F_22 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( V_11 == NULL )
return - V_50 ;
V_2 = F_6 ( V_11 ) ;
F_23 ( V_5 , V_11 ) ;
V_2 -> V_5 = V_5 ;
V_11 -> V_8 . V_51 = & V_5 -> V_8 ;
V_11 -> V_52 = & V_53 ;
V_11 -> V_54 = V_55 ;
V_11 -> V_56 = V_57 ;
V_11 -> V_58 = F_11 ( V_57 ) ;
V_11 -> V_59 = V_60 ;
V_4 = F_2 ( V_2 -> V_5 , V_61 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 == 0x44 )
F_24 ( & V_5 -> V_8 , L_3 ) ;
else if ( V_4 == 0x4d )
F_24 ( & V_5 -> V_8 , L_4 ) ;
else
return - V_62 ;
V_4 = F_2 ( V_2 -> V_5 , V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_22 = V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_30 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_25 = V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_63 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_64 = V_4 | V_65 | V_66 ;
V_4 = F_12 ( V_2 -> V_5 , V_63 ,
V_2 -> V_64 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( V_11 , NULL ,
F_14 , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_26 ( V_11 ) ;
if ( V_4 < 0 )
goto V_67;
return 0 ;
V_67:
F_27 ( V_11 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_5 , V_63 ,
V_2 -> V_64 & ~ ( V_66 | V_65 ) ) ;
}
static int F_29 ( struct V_47 * V_5 )
{
struct V_10 * V_11 = F_30 ( V_5 ) ;
F_31 ( V_11 ) ;
F_27 ( V_11 ) ;
F_28 ( F_6 ( V_11 ) ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_8 )
{
struct V_1 * V_2 = F_6 ( F_30 (
F_33 ( V_8 ) ) ) ;
return F_28 ( V_2 ) ;
}
static int F_34 ( struct V_41 * V_8 )
{
struct V_1 * V_2 = F_6 ( F_30 (
F_33 ( V_8 ) ) ) ;
return F_12 ( V_2 -> V_5 , V_63 ,
V_2 -> V_64 | ( V_66 | V_65 ) ) ;
}
