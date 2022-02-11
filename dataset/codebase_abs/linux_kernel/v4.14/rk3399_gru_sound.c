static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
int V_9 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_8 = F_2 ( V_4 ) * V_10 ;
break;
default:
F_3 ( V_6 -> V_11 -> V_12 , L_1 ,
V_13 , F_2 ( V_4 ) ) ;
return - V_14 ;
}
V_9 = F_4 ( V_6 -> V_15 , 0 , V_8 , 0 ) ;
if ( V_9 ) {
F_3 ( V_6 -> V_11 -> V_12 , L_2 ,
V_13 , V_8 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_16 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_17 ;
unsigned int V_8 ;
int V_9 ;
V_8 = F_2 ( V_4 ) * V_10 ;
V_9 = F_4 ( V_15 , 0 , V_8 ,
V_18 ) ;
if ( V_9 < 0 ) {
F_3 ( V_6 -> V_11 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_4 ( V_17 , V_19 ,
V_8 , V_20 ) ;
if ( V_9 ) {
F_3 ( V_6 -> V_11 -> V_12 , L_2 ,
V_13 , F_2 ( V_4 ) * 512 , V_9 ) ;
return V_9 ;
}
F_6 ( V_21 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_16 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_17 ;
int V_8 , V_9 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_8 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_8 = 11289600 ;
break;
default:
return - V_14 ;
}
V_9 = F_4 ( V_15 , 0 , V_8 ,
V_18 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_4 ( V_17 , 0 , V_8 ,
V_20 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_8 ( V_17 , 0 , V_22 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_5 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = V_6 -> V_25 [ 0 ] -> V_24 ;
struct V_16 * V_17 = V_6 -> V_17 ;
int V_9 ;
V_9 = F_4 ( V_17 , 0 , 12288000 ,
V_20 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_8 ( V_17 , 0 , V_22 , 0 , 0 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_6 -> V_11 , L_8 ,
V_26 | V_27 |
V_28 | V_29 |
V_30 | V_31 ,
& V_32 , NULL , 0 ) ;
if ( V_9 ) {
F_3 ( V_6 -> V_11 -> V_12 , L_9 , V_9 ) ;
return V_9 ;
}
F_11 ( V_32 . V_33 , V_28 , V_34 ) ;
F_11 (
V_32 . V_33 , V_29 , V_35 ) ;
F_11 (
V_32 . V_33 , V_30 , V_36 ) ;
F_11 (
V_32 . V_33 , V_31 , V_37 ) ;
F_12 ( V_24 , & V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_16 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_17 ;
int V_8 , V_9 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_8 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_8 = 11289600 ;
break;
default:
return - V_14 ;
}
V_9 = F_4 ( V_15 , 0 , V_8 ,
V_18 ) ;
if ( V_9 < 0 ) {
F_3 ( V_17 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
int V_9 ;
V_8 = F_2 ( V_4 ) * V_10 ;
V_9 = F_4 ( V_6 -> V_15 , 0 , V_8 , 0 ) ;
if ( V_9 ) {
F_3 ( V_6 -> V_11 -> V_12 , L_2 ,
V_13 , V_8 , V_9 ) ;
return V_9 ;
}
F_6 ( V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_16 ( V_41 ) ; V_40 ++ ) {
if ( F_17 ( V_39 , V_41 [ V_40 ] ) )
return V_40 ;
}
return - 1 ;
}
static int F_18 ( struct V_42 * V_12 ,
struct V_43 * V_11 )
{
struct V_38 * V_44 , * V_45 , * V_46 ;
struct V_38 * V_39 ;
struct V_47 * V_48 ;
int V_40 , V_49 ;
V_11 -> V_50 = F_19 ( V_12 , sizeof( V_51 ) ,
V_52 ) ;
if ( ! V_11 -> V_50 )
return - V_53 ;
V_45 = F_20 ( V_12 -> V_54 , L_10 , 0 ) ;
V_46 = F_20 ( V_12 -> V_54 , L_10 , 1 ) ;
V_11 -> V_55 = 0 ;
for ( V_40 = 0 ; V_40 < F_16 ( V_51 ) ; V_40 ++ ) {
V_39 = F_20 ( V_12 -> V_54 ,
L_11 , V_40 ) ;
if ( ! V_39 )
break;
if ( ! F_21 ( V_39 ) )
continue;
V_49 = F_15 ( V_39 ) ;
if ( V_49 < 0 )
continue;
V_44 = ( V_49 == V_56 ) ? V_46 : V_45 ;
if ( ! V_44 ) {
F_3 ( V_12 , L_12 ,
V_51 [ V_49 ] . V_57 ) ;
return - V_14 ;
}
V_48 = & V_11 -> V_50 [ V_11 -> V_55 ++ ] ;
* V_48 = V_51 [ V_49 ] ;
V_48 -> V_58 = V_39 ;
V_48 -> V_59 = V_44 ;
V_48 -> V_60 = V_44 ;
}
return 0 ;
}
static int F_22 ( struct V_61 * V_62 )
{
struct V_43 * V_11 = & V_63 ;
int V_9 ;
V_9 = F_18 ( & V_62 -> V_12 , V_11 ) ;
if ( V_9 < 0 ) {
F_3 ( & V_62 -> V_12 , L_13 , V_9 ) ;
return V_9 ;
}
V_9 = F_23 ( & V_62 -> V_12 , L_14 ,
& V_21 ) ;
if ( V_9 ) {
V_21 = 0 ;
F_24 ( & V_62 -> V_12 ,
L_15 ) ;
}
V_11 -> V_12 = & V_62 -> V_12 ;
return F_25 ( & V_62 -> V_12 , V_11 ) ;
}
