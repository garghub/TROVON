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
static int F_13 ( struct V_38 * V_12 , void * V_39 )
{
return 1 ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_42 * V_11 = & V_43 ;
struct V_44 * V_45 ;
struct V_38 * V_12 ;
struct V_46 * V_47 ;
int V_48 , V_9 ;
V_45 = F_15 ( V_41 -> V_12 . V_49 , L_10 , 0 ) ;
if ( ! V_45 ) {
F_3 ( & V_41 -> V_12 , L_11 ) ;
return - V_14 ;
}
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_51 [ V_48 ] . V_52 = V_45 ;
V_51 [ V_48 ] . V_53 = V_45 ;
V_51 [ V_48 ] . V_54 =
F_15 ( V_41 -> V_12 . V_49 , L_12 , V_48 ) ;
if ( ! V_51 [ V_48 ] . V_54 ) {
F_3 ( & V_41 -> V_12 ,
L_13 , V_48 ) ;
return - V_14 ;
}
}
V_47 = F_16 ( L_14 , & V_55 ) ;
if ( ! V_47 ) {
F_3 ( & V_41 -> V_12 , L_15 ) ;
return - V_14 ;
}
V_12 = F_17 ( V_47 , NULL , NULL , F_13 ) ;
if ( ! V_12 ) {
F_3 ( & V_41 -> V_12 , L_16 ) ;
return - V_56 ;
}
V_9 = F_18 ( & V_41 -> V_12 , L_17 ,
& V_21 ) ;
if ( V_9 ) {
V_21 = 0 ;
F_19 ( & V_41 -> V_12 ,
L_18 ) ;
}
V_51 [ V_57 ] . V_58 = F_20 ( F_21 ( V_12 ) , V_59 ) ;
V_51 [ V_57 ] . V_60 = F_20 ( F_21 ( V_12 ) , V_59 ) ;
V_51 [ V_57 ] . V_61 = F_20 ( F_21 ( V_12 ) , V_59 ) ;
V_11 -> V_12 = & V_41 -> V_12 ;
F_22 ( V_41 , V_11 ) ;
V_9 = F_23 ( & V_41 -> V_12 , V_11 ) ;
if ( V_9 )
F_3 ( & V_41 -> V_12 , L_19 ,
V_13 , V_9 ) ;
return V_9 ;
}
