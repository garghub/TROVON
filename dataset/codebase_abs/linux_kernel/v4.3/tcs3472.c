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
if ( F_7 ( V_11 ) )
return - V_18 ;
F_8 ( & V_2 -> V_19 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_2 -> V_19 ) ;
return V_4 ;
}
V_4 = F_10 ( V_2 -> V_5 , V_13 -> V_20 ) ;
F_9 ( & V_2 -> V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = V_4 ;
return V_21 ;
case V_22 :
* V_14 = V_23 [ V_2 -> V_24 &
V_25 ] ;
return V_21 ;
case V_26 :
* V_14 = 0 ;
* V_15 = ( 256 - V_2 -> V_27 ) * 2400 ;
return V_28 ;
}
return - V_29 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_12 const * V_13 ,
int V_14 , int V_15 , long V_16 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_30 ;
switch ( V_16 ) {
case V_22 :
if ( V_15 != 0 )
return - V_29 ;
for ( V_30 = 0 ; V_30 < F_12 ( V_23 ) ; V_30 ++ ) {
if ( V_14 == V_23 [ V_30 ] ) {
V_2 -> V_24 &= ~ V_25 ;
V_2 -> V_24 |= V_30 ;
return F_13 (
V_2 -> V_5 , V_31 ,
V_2 -> V_24 ) ;
}
}
return - V_29 ;
case V_26 :
if ( V_14 != 0 )
return - V_29 ;
for ( V_30 = 0 ; V_30 < 256 ; V_30 ++ ) {
if ( V_15 == ( 256 - V_30 ) * 2400 ) {
V_2 -> V_27 = V_30 ;
return F_14 (
V_2 -> V_5 , V_32 ,
V_2 -> V_27 ) ;
}
}
return - V_29 ;
}
return - V_29 ;
}
static T_1 F_15 ( int V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_1 * V_2 = F_6 ( V_11 ) ;
int V_30 , V_37 = 0 ;
int V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
goto V_38;
F_16 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_4 = F_10 ( V_2 -> V_5 ,
V_39 + 2 * V_30 ) ;
if ( V_4 < 0 )
goto V_38;
V_2 -> V_40 [ V_37 ++ ] = V_4 ;
}
F_17 ( V_11 , V_2 -> V_40 ,
F_18 () ) ;
V_38:
F_19 ( V_11 -> V_41 ) ;
return V_42 ;
}
static T_2 F_20 ( struct V_43 * V_8 ,
struct V_44 * V_45 ,
char * V_46 )
{
T_3 V_47 = 0 ;
int V_30 ;
for ( V_30 = 1 ; V_30 <= 256 ; V_30 ++ )
V_47 += F_21 ( V_46 + V_47 , V_48 - V_47 , L_2 ,
2400 * V_30 ) ;
V_46 [ V_47 - 1 ] = '\n' ;
return V_47 ;
}
static int F_22 ( struct V_49 * V_5 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_4 ;
V_11 = F_23 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( V_11 == NULL )
return - V_52 ;
V_2 = F_6 ( V_11 ) ;
F_24 ( V_5 , V_11 ) ;
V_2 -> V_5 = V_5 ;
F_25 ( & V_2 -> V_19 ) ;
V_11 -> V_8 . V_53 = & V_5 -> V_8 ;
V_11 -> V_54 = & V_55 ;
V_11 -> V_56 = V_57 ;
V_11 -> V_58 = V_59 ;
V_11 -> V_60 = F_12 ( V_59 ) ;
V_11 -> V_61 = V_62 ;
V_4 = F_2 ( V_2 -> V_5 , V_63 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 == 0x44 )
F_26 ( & V_5 -> V_8 , L_3 ) ;
else if ( V_4 == 0x4d )
F_26 ( & V_5 -> V_8 , L_4 ) ;
else
return - V_64 ;
V_4 = F_2 ( V_2 -> V_5 , V_31 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_24 = V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_27 = V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_65 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_66 = V_4 | V_67 | V_68 ;
V_4 = F_13 ( V_2 -> V_5 , V_65 ,
V_2 -> V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_27 ( V_11 , NULL ,
F_15 , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_28 ( V_11 ) ;
if ( V_4 < 0 )
goto V_69;
return 0 ;
V_69:
F_29 ( V_11 ) ;
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_13 ( V_2 -> V_5 , V_65 ,
V_2 -> V_66 & ~ ( V_68 | V_67 ) ) ;
}
static int F_31 ( struct V_49 * V_5 )
{
struct V_10 * V_11 = F_32 ( V_5 ) ;
F_33 ( V_11 ) ;
F_29 ( V_11 ) ;
F_30 ( F_6 ( V_11 ) ) ;
return 0 ;
}
static int F_34 ( struct V_43 * V_8 )
{
struct V_1 * V_2 = F_6 ( F_32 (
F_35 ( V_8 ) ) ) ;
return F_30 ( V_2 ) ;
}
static int F_36 ( struct V_43 * V_8 )
{
struct V_1 * V_2 = F_6 ( F_32 (
F_35 ( V_8 ) ) ) ;
return F_13 ( V_2 -> V_5 , V_65 ,
V_2 -> V_66 | ( V_68 | V_67 ) ) ;
}
