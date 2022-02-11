static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_6 ;
F_2 ( V_2 , L_1 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ ) {
switch ( V_7 [ V_6 ] . V_8 ) {
case 8 :
F_2 ( V_2 , L_2 , V_7 [ V_6 ] . V_9 ,
F_4 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
case 16 :
F_2 ( V_2 , L_3 , V_7 [ V_6 ] . V_9 ,
F_5 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
case 32 :
F_2 ( V_2 , L_4 , V_7 [ V_6 ] . V_9 ,
F_6 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
}
}
return 0 ;
}
static int F_7 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_8 ( V_13 , F_1 , V_12 -> V_14 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_15 ;
V_15 = F_4 ( V_4 -> V_10 , V_16 ) ;
if ( V_15 & V_17 )
F_2 ( V_2 , L_5 ) ;
if ( V_15 & V_18 )
F_2 ( V_2 , L_6 ) ;
if ( V_15 & V_19 )
F_2 ( V_2 , L_7 ) ;
if ( V_15 & V_20 )
F_2 ( V_2 , L_8 ) ;
if ( V_15 & V_21 )
F_2 ( V_2 , L_9 ) ;
if ( V_15 & V_22 )
F_2 ( V_2 , L_10 ) ;
if ( V_15 & V_23 )
F_2 ( V_2 , L_11 ) ;
if ( V_15 & V_24 )
F_2 ( V_2 , L_12 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_8 ( V_13 , F_9 , V_12 -> V_14 ) ;
}
static T_1 F_11 ( struct V_13 * V_13 ,
const char T_2 * V_25 , T_3 V_26 , T_4 * V_27 )
{
struct V_1 * V_2 = V_13 -> V_28 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_5 V_15 ;
char V_29 [ 18 ] ;
V_15 = F_4 ( V_4 -> V_10 , V_16 ) ;
if ( V_15 ) {
F_12 ( V_4 -> V_30 , L_13
L_14 ) ;
return V_26 ;
}
memset ( V_29 , 0x00 , sizeof( V_29 ) ) ;
if ( F_13 ( V_29 , V_25 , F_14 ( T_3 , sizeof( V_29 ) - 1 , V_26 ) ) )
return - V_31 ;
if ( F_15 ( V_29 , L_15 ) )
V_15 = V_17 ;
if ( F_15 ( V_29 , L_16 ) )
V_15 = V_18 ;
if ( F_15 ( V_29 , L_17 ) )
V_15 = V_19 ;
if ( F_15 ( V_29 , L_18 ) )
V_15 = V_20 ;
if ( F_15 ( V_29 , L_19 ) ) {
V_15 = V_21 ;
F_16 ( V_4 ) ;
}
if ( F_15 ( V_29 , L_20 ) )
V_15 = V_22 ;
if ( F_15 ( V_29 , L_21 ) )
V_15 = V_23 ;
if ( F_15 ( V_29 , L_22 ) )
V_15 = V_24 ;
F_17 ( V_4 -> V_10 , V_16 , V_15 ) ;
return V_26 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_5 V_32 ;
int V_33 ;
switch ( V_4 -> V_34 -> V_35 -> V_36 ) {
case V_37 :
case V_38 :
V_32 = F_4 ( V_4 -> V_10 , V_39 ) ;
V_33 = V_32 & V_40 ? 1 : 0 ;
break;
default:
V_33 = - 1 ;
}
F_2 ( V_2 , L_23 , V_33 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_8 ( V_13 , F_18 , V_12 -> V_14 ) ;
}
static T_1 F_20 ( struct V_13 * V_13 ,
const char T_2 * V_25 , T_3 V_26 , T_4 * V_27 )
{
struct V_1 * V_2 = V_13 -> V_28 ;
struct V_4 * V_4 = V_2 -> V_5 ;
char V_29 [ 2 ] ;
T_5 V_32 ;
memset ( V_29 , 0x00 , sizeof( V_29 ) ) ;
if ( F_13 ( & V_29 , V_25 , F_14 ( T_3 , sizeof( V_29 ) - 1 , V_26 ) ) )
return - V_31 ;
if ( ! strncmp ( V_29 , L_24 , 1 ) ) {
switch ( V_4 -> V_34 -> V_35 -> V_36 ) {
case V_37 :
F_21 ( V_4 ) ;
V_32 = F_4 ( V_4 -> V_10 , V_39 ) ;
V_32 &= ~ V_40 ;
F_17 ( V_4 -> V_10 , V_39 , V_32 ) ;
break;
default:
break;
}
} else if ( ! strncmp ( V_29 , L_25 , 1 ) ) {
switch ( V_4 -> V_34 -> V_35 -> V_36 ) {
case V_38 :
V_4 -> V_41 . V_42 |= V_40 ;
V_32 = F_4 ( V_4 -> V_10 , V_39 ) ;
V_32 |= V_40 ;
F_17 ( V_4 -> V_10 , V_39 , V_32 ) ;
break;
default:
break;
}
}
return V_26 ;
}
int F_22 ( struct V_4 * V_4 )
{
struct V_43 * V_44 ;
struct V_43 * V_13 ;
int V_45 ;
V_44 = F_23 ( F_24 ( V_4 -> V_30 ) , NULL ) ;
if ( ! V_44 ) {
V_45 = - V_46 ;
goto V_47;
}
V_13 = F_25 ( L_26 , V_48 , V_44 , V_4 ,
& V_49 ) ;
if ( ! V_13 ) {
V_45 = - V_46 ;
goto V_50;
}
V_13 = F_25 ( L_27 , V_48 | V_51 ,
V_44 , V_4 , & V_52 ) ;
if ( ! V_13 ) {
V_45 = - V_46 ;
goto V_50;
}
V_13 = F_25 ( L_28 , V_48 | V_51 ,
V_44 , V_4 , & V_53 ) ;
if ( ! V_13 ) {
V_45 = - V_46 ;
goto V_50;
}
V_4 -> V_54 = V_44 ;
return 0 ;
V_50:
F_26 ( V_44 ) ;
V_47:
return V_45 ;
}
void F_27 ( struct V_4 * V_4 )
{
F_26 ( V_4 -> V_54 ) ;
}
