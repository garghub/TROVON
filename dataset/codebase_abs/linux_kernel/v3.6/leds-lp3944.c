static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return - V_6 ;
* V_4 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_8 )
{
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
if ( V_7 == V_12 )
V_9 = V_13 ;
else if ( V_7 == V_14 )
V_9 = V_15 ;
else
return - V_6 ;
if ( V_8 > V_16 )
return - V_6 ;
V_10 = ( V_8 * 255 ) / V_16 ;
V_11 = F_3 ( V_2 , V_9 , V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 V_17 )
{
T_1 V_18 ;
T_1 V_19 ;
int V_11 ;
if ( V_7 == V_12 )
V_18 = V_20 ;
else if ( V_7 == V_14 )
V_18 = V_21 ;
else
return - V_6 ;
if ( V_17 > V_22 )
return - V_6 ;
V_19 = ( V_17 * 255 ) / V_22 ;
V_11 = F_3 ( V_2 , V_18 , V_19 ) ;
return V_11 ;
}
static int F_7 ( struct V_23 * V_24 , T_1 V_25 )
{
struct V_26 * V_27 = F_8 ( V_24 -> V_2 ) ;
T_1 V_28 = V_24 -> V_28 ;
T_1 V_3 ;
T_1 V_29 = 0 ;
int V_11 ;
F_9 ( & V_24 -> V_2 -> V_30 , L_1 ,
V_31 , V_24 -> V_32 . V_33 , V_25 ) ;
switch ( V_28 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_3 = V_38 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_28 -= V_39 ;
V_3 = V_43 ;
break;
default:
return - V_6 ;
}
if ( V_25 > V_44 )
return - V_6 ;
if ( V_24 -> type == V_45 && V_25 < 2 )
V_25 = 1 - V_25 ;
F_10 ( & V_27 -> V_46 ) ;
F_1 ( V_24 -> V_2 , V_3 , & V_29 ) ;
V_29 &= ~ ( V_47 << ( V_28 << 1 ) ) ;
V_29 |= ( V_25 << ( V_28 << 1 ) ) ;
F_9 ( & V_24 -> V_2 -> V_30 , L_2 ,
V_31 , V_24 -> V_32 . V_33 , V_3 , V_28 , V_25 , V_29 ) ;
V_11 = F_3 ( V_24 -> V_2 , V_3 , V_29 ) ;
F_11 ( & V_27 -> V_46 ) ;
return V_11 ;
}
static int F_12 ( struct V_48 * V_49 ,
unsigned long * V_50 ,
unsigned long * V_51 )
{
struct V_23 * V_24 = F_13 ( V_49 ) ;
T_2 V_8 ;
T_1 V_17 ;
int V_11 ;
if ( * V_50 + * V_51 > V_16 )
return - V_6 ;
if ( * V_50 == 0 && * V_51 == 0 ) {
* V_50 = 500 ;
* V_51 = 500 ;
}
V_8 = ( * V_50 ) + ( * V_51 ) ;
V_17 = 100 * ( * V_50 ) / V_8 ;
if ( V_24 -> type == V_45 )
V_17 = 100 - V_17 ;
V_11 = F_5 ( V_24 -> V_2 , V_12 , V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_6 ( V_24 -> V_2 , V_12 , V_17 ) ;
if ( V_11 )
return V_11 ;
F_9 ( & V_24 -> V_2 -> V_30 , L_3 ,
V_31 ) ;
V_24 -> V_25 = V_52 ;
F_14 ( & V_24 -> V_53 ) ;
return 0 ;
}
static void F_15 ( struct V_48 * V_49 ,
enum V_54 V_55 )
{
struct V_23 * V_24 = F_13 ( V_49 ) ;
F_9 ( & V_24 -> V_2 -> V_30 , L_4 ,
V_31 , V_49 -> V_33 , V_55 ) ;
V_24 -> V_25 = V_55 ;
F_14 ( & V_24 -> V_53 ) ;
}
static void F_16 ( struct V_56 * V_53 )
{
struct V_23 * V_24 ;
V_24 = F_17 ( V_53 , struct V_23 , V_53 ) ;
F_7 ( V_24 , V_24 -> V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_57 * V_58 )
{
int V_59 , V_11 = 0 ;
for ( V_59 = 0 ; V_59 < V_58 -> V_60 ; V_59 ++ ) {
struct V_61 * V_62 = & V_58 -> V_63 [ V_59 ] ;
struct V_23 * V_24 = & V_27 -> V_63 [ V_59 ] ;
V_24 -> V_2 = V_2 ;
V_24 -> V_28 = V_59 ;
switch ( V_62 -> type ) {
case V_64 :
case V_45 :
V_24 -> type = V_62 -> type ;
V_24 -> V_25 = V_62 -> V_25 ;
V_24 -> V_32 . V_33 = V_62 -> V_33 ;
V_24 -> V_32 . V_65 = 1 ;
V_24 -> V_32 . V_66 = F_15 ;
V_24 -> V_32 . V_67 = F_12 ;
V_24 -> V_32 . V_68 = V_69 ;
F_19 ( & V_24 -> V_53 , F_16 ) ;
V_11 = F_20 ( & V_2 -> V_30 , & V_24 -> V_32 ) ;
if ( V_11 < 0 ) {
F_21 ( & V_2 -> V_30 ,
L_5 ,
V_24 -> V_32 . V_33 ) ;
goto exit;
}
V_24 -> V_32 . V_55 = V_24 -> V_25 ;
V_11 = F_7 ( V_24 , V_24 -> V_25 ) ;
if ( V_11 < 0 ) {
F_21 ( & V_2 -> V_30 ,
L_6 ,
V_24 -> V_32 . V_33 , V_24 -> V_25 ) ;
goto exit;
}
break;
case V_70 :
default:
break;
}
}
return 0 ;
exit:
if ( V_59 > 0 )
for ( V_59 = V_59 - 1 ; V_59 >= 0 ; V_59 -- )
switch ( V_58 -> V_63 [ V_59 ] . type ) {
case V_64 :
case V_45 :
F_22 ( & V_27 -> V_63 [ V_59 ] . V_32 ) ;
F_23 ( & V_27 -> V_63 [ V_59 ] . V_53 ) ;
break;
case V_70 :
default:
break;
}
return V_11 ;
}
static int T_3 F_24 ( struct V_1 * V_2 ,
const struct V_71 * V_28 )
{
struct V_57 * V_72 = V_2 -> V_30 . V_73 ;
struct V_26 * V_27 ;
int V_11 ;
if ( V_72 == NULL ) {
F_21 ( & V_2 -> V_30 , L_7 ) ;
return - V_6 ;
}
if ( ! F_25 ( V_2 -> V_74 ,
V_75 ) ) {
F_21 ( & V_2 -> V_30 , L_8 ) ;
return - V_76 ;
}
V_27 = F_26 ( & V_2 -> V_30 , sizeof( struct V_26 ) ,
V_77 ) ;
if ( ! V_27 )
return - V_78 ;
V_27 -> V_2 = V_2 ;
F_27 ( V_2 , V_27 ) ;
F_28 ( & V_27 -> V_46 ) ;
V_11 = F_18 ( V_2 , V_27 , V_72 ) ;
if ( V_11 < 0 )
return V_11 ;
F_29 ( & V_2 -> V_30 , L_9 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = V_2 -> V_30 . V_73 ;
struct V_26 * V_27 = F_8 ( V_2 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_58 -> V_60 ; V_59 ++ )
switch ( V_27 -> V_63 [ V_59 ] . type ) {
case V_64 :
case V_45 :
F_22 ( & V_27 -> V_63 [ V_59 ] . V_32 ) ;
F_23 ( & V_27 -> V_63 [ V_59 ] . V_53 ) ;
break;
case V_70 :
default:
break;
}
return 0 ;
}
