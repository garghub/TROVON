static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_6 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_4 -> V_7 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_8 ) ; V_6 ++ ) {
switch ( V_8 [ V_6 ] . V_9 ) {
case 8 :
F_2 ( V_2 , L_2 , V_8 [ V_6 ] . V_10 ,
F_5 ( V_4 -> V_11 , V_8 [ V_6 ] . V_12 ) ) ;
break;
case 16 :
F_2 ( V_2 , L_3 , V_8 [ V_6 ] . V_10 ,
F_6 ( V_4 -> V_11 , V_8 [ V_6 ] . V_12 ) ) ;
break;
case 32 :
F_2 ( V_2 , L_4 , V_8 [ V_6 ] . V_10 ,
F_7 ( V_4 -> V_11 , V_8 [ V_6 ] . V_12 ) ) ;
break;
}
}
F_8 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_11 ( V_14 , F_1 , V_13 -> V_15 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_16 ;
F_3 ( V_4 -> V_7 ) ;
V_16 = F_5 ( V_4 -> V_11 , V_17 ) ;
F_8 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
if ( V_16 == ( V_18 | V_19 ) )
F_2 ( V_2 , L_5 ) ;
else if ( V_16 == ( V_18 | V_20 ) )
F_2 ( V_2 , L_6 ) ;
else if ( V_16 == V_18 )
F_2 ( V_2 , L_7 ) ;
else if ( V_16 == V_21 )
F_2 ( V_2 , L_8 ) ;
else if ( V_16 == V_19 )
F_2 ( V_2 , L_9 ) ;
else if ( V_16 == V_20 )
F_2 ( V_2 , L_10 ) ;
else if ( V_16 == V_22 )
F_2 ( V_2 , L_11 ) ;
else if ( V_16 == V_23 )
F_2 ( V_2 , L_12 ) ;
else if ( V_16 == V_24 )
F_2 ( V_2 , L_13 ) ;
else if ( V_16 == V_25 )
F_2 ( V_2 , L_14 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_11 ( V_14 , F_12 , V_13 -> V_15 ) ;
}
static T_1 F_14 ( struct V_14 * V_14 ,
const char T_2 * V_26 , T_3 V_27 , T_4 * V_28 )
{
struct V_1 * V_2 = V_14 -> V_29 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_5 V_16 ;
char V_30 [ 24 ] ;
F_3 ( V_4 -> V_7 ) ;
V_16 = F_5 ( V_4 -> V_11 , V_17 ) ;
if ( V_16 ) {
F_15 ( V_4 -> V_7 , L_15
L_16 ) ;
goto V_31;
}
memset ( V_30 , 0x00 , sizeof( V_30 ) ) ;
if ( F_16 ( V_30 , V_26 , F_17 ( T_3 , sizeof( V_30 ) - 1 , V_27 ) ) )
return - V_32 ;
if ( F_18 ( V_30 , L_17 ) )
V_16 = V_18 | V_19 ;
else if ( F_18 ( V_30 , L_18 ) )
V_16 = V_18 | V_20 ;
else if ( F_18 ( V_30 , L_19 ) )
V_16 = V_18 ;
else if ( F_18 ( V_30 , L_20 ) )
V_16 = V_21 ;
else if ( F_18 ( V_30 , L_21 ) )
V_16 = V_19 ;
else if ( F_18 ( V_30 , L_22 ) )
V_16 = V_20 ;
else if ( F_18 ( V_30 , L_23 ) ) {
V_16 = V_22 ;
F_19 ( V_4 ) ;
}
else if ( F_18 ( V_30 , L_24 ) )
V_16 = V_23 ;
else if ( F_18 ( V_30 , L_25 ) )
V_16 = V_24 ;
else if ( F_18 ( V_30 , L_26 ) )
V_16 = V_25 ;
F_20 ( V_4 -> V_11 , V_17 , V_16 ) ;
V_31:
F_8 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
T_5 V_33 ;
int V_34 ;
switch ( V_4 -> V_35 -> V_36 -> V_37 ) {
case V_38 :
case V_39 :
F_3 ( V_4 -> V_7 ) ;
V_33 = F_5 ( V_4 -> V_11 , V_40 ) ;
V_34 = V_33 & V_41 ? 1 : 0 ;
F_8 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
break;
default:
V_34 = - 1 ;
}
F_2 ( V_2 , L_27 , V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_11 ( V_14 , F_21 , V_13 -> V_15 ) ;
}
static T_1 F_23 ( struct V_14 * V_14 ,
const char T_2 * V_26 , T_3 V_27 , T_4 * V_28 )
{
struct V_1 * V_2 = V_14 -> V_29 ;
struct V_4 * V_4 = V_2 -> V_5 ;
char V_30 [ 2 ] ;
T_5 V_33 ;
memset ( V_30 , 0x00 , sizeof( V_30 ) ) ;
if ( F_16 ( & V_30 , V_26 , F_17 ( T_3 , sizeof( V_30 ) - 1 , V_27 ) ) )
return - V_32 ;
F_3 ( V_4 -> V_7 ) ;
if ( ! strncmp ( V_30 , L_28 , 1 ) ) {
switch ( V_4 -> V_35 -> V_36 -> V_37 ) {
case V_38 :
F_24 ( V_4 ) ;
V_33 = F_5 ( V_4 -> V_11 , V_40 ) ;
V_33 &= ~ V_41 ;
F_20 ( V_4 -> V_11 , V_40 , V_33 ) ;
break;
default:
break;
}
} else if ( ! strncmp ( V_30 , L_29 , 1 ) ) {
switch ( V_4 -> V_35 -> V_36 -> V_37 ) {
case V_39 :
V_4 -> V_42 . V_43 |= V_41 ;
V_33 = F_5 ( V_4 -> V_11 , V_40 ) ;
V_33 |= V_41 ;
F_20 ( V_4 -> V_11 , V_40 , V_33 ) ;
break;
default:
break;
}
}
F_8 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
return V_27 ;
}
int F_25 ( struct V_4 * V_4 )
{
struct V_44 * V_45 ;
struct V_44 * V_14 ;
int V_31 ;
V_45 = F_26 ( F_27 ( V_4 -> V_7 ) , NULL ) ;
if ( ! V_45 ) {
V_31 = - V_46 ;
goto V_47;
}
V_14 = F_28 ( L_30 , V_48 , V_45 , V_4 ,
& V_49 ) ;
if ( ! V_14 ) {
V_31 = - V_46 ;
goto V_50;
}
V_14 = F_28 ( L_31 , V_48 | V_51 ,
V_45 , V_4 , & V_52 ) ;
if ( ! V_14 ) {
V_31 = - V_46 ;
goto V_50;
}
V_14 = F_28 ( L_32 , V_48 | V_51 ,
V_45 , V_4 , & V_53 ) ;
if ( ! V_14 ) {
V_31 = - V_46 ;
goto V_50;
}
V_4 -> V_54 = V_45 ;
return 0 ;
V_50:
F_29 ( V_45 ) ;
V_47:
return V_31 ;
}
void F_30 ( struct V_4 * V_4 )
{
F_29 ( V_4 -> V_54 ) ;
}
