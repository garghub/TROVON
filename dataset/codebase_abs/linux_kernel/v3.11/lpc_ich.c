static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 . V_6 >= 0 ) {
F_3 ( V_2 , V_4 -> V_5 . V_7 , V_4 -> V_5 . V_6 ) ;
V_4 -> V_5 . V_6 = - 1 ;
}
if ( V_4 -> V_8 . V_6 >= 0 ) {
F_3 ( V_2 , V_4 -> V_8 . V_7 , V_4 -> V_8 . V_6 ) ;
V_4 -> V_8 . V_6 = - 1 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_5 ( V_2 , V_4 -> V_5 . V_7 , & V_9 ) ;
F_3 ( V_2 , V_4 -> V_5 . V_7 , V_9 | 0x10 ) ;
V_4 -> V_5 . V_6 = V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_5 ( V_2 , V_4 -> V_8 . V_7 , & V_9 ) ;
F_3 ( V_2 , V_4 -> V_8 . V_7 , V_9 | 0x10 ) ;
V_4 -> V_8 . V_6 = V_9 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_11 -> V_12 = & V_13 [ V_4 -> V_14 ] ;
V_11 -> V_15 = sizeof( struct V_16 ) ;
}
static int F_8 ( struct V_17 * V_18 )
{
int V_19 ;
T_1 V_20 = 0 ;
if ( F_9 ( V_18 ) >= 0x50 &&
! F_10 ( V_18 -> V_21 + 0x40 , 0x10 , L_1 ) )
V_20 |= 1 << 2 ;
if ( ! F_10 ( V_18 -> V_21 + 0x30 , 0x10 , L_2 ) )
V_20 |= 1 << 1 ;
V_19 = F_10 ( V_18 -> V_21 + 0x00 , 0x30 , L_3 ) ;
if ( ! V_19 )
V_20 |= 1 << 0 ;
return V_20 ? V_20 : V_19 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_22 ;
T_2 V_23 ;
int V_19 ;
bool V_24 = false ;
struct V_17 * V_18 ;
F_12 ( V_2 , V_4 -> V_5 . V_25 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_13 ( & V_2 -> V_2 , L_4 ) ;
V_26 [ V_27 ] . V_28 -- ;
goto V_29;
}
V_18 = & V_30 [ V_31 ] ;
V_18 -> V_21 = V_23 + V_32 ;
V_18 -> V_33 = V_23 + V_34 ;
V_19 = F_14 ( V_18 ) ;
if ( V_19 ) {
V_26 [ V_27 ] . V_28 -- ;
V_24 = true ;
} else {
F_4 ( V_2 ) ;
}
V_29:
F_12 ( V_2 , V_4 -> V_8 . V_25 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_13 ( & V_2 -> V_2 , L_5 ) ;
V_19 = - V_35 ;
goto V_36;
}
V_18 = & V_30 [ V_37 ] ;
V_18 -> V_21 = V_23 ;
switch ( V_13 [ V_4 -> V_14 ] . V_38 ) {
case V_39 :
case V_40 :
V_18 -> V_33 = V_18 -> V_21 + 128 - 1 ;
break;
default:
V_18 -> V_33 = V_18 -> V_21 + 64 - 1 ;
break;
}
V_19 = F_8 ( V_18 ) ;
if ( V_19 < 0 ) {
V_24 = true ;
goto V_36;
}
V_13 [ V_4 -> V_14 ] . V_20 = V_19 ;
F_6 ( V_2 ) ;
F_7 ( V_2 , & V_26 [ V_27 ] ) ;
V_19 = F_15 ( & V_2 -> V_2 , - 1 , & V_26 [ V_27 ] ,
1 , NULL , 0 , NULL ) ;
V_36:
if ( V_24 )
F_16 ( L_6 ,
V_26 [ V_27 ] . V_41 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_22 ;
T_2 V_23 ;
int V_19 ;
struct V_17 * V_18 ;
F_12 ( V_2 , V_4 -> V_5 . V_25 , & V_22 ) ;
V_23 = V_22 & 0x0000ff80 ;
if ( ! V_23 ) {
F_13 ( & V_2 -> V_2 , L_4 ) ;
V_19 = - V_35 ;
goto V_42;
}
V_18 = F_18 ( V_43 ) ;
V_18 -> V_21 = V_23 + V_44 ;
V_18 -> V_33 = V_23 + V_45 ;
V_18 = F_18 ( V_46 ) ;
V_18 -> V_21 = V_23 + V_47 ;
V_18 -> V_33 = V_23 + V_48 ;
F_4 ( V_2 ) ;
if ( V_13 [ V_4 -> V_14 ] . V_49 == 1 ) {
V_26 [ V_50 ] . V_28 -- ;
} else {
F_12 ( V_2 , V_51 , & V_22 ) ;
V_23 = V_22 & 0xffffc000 ;
if ( ! ( V_22 & 1 ) ) {
F_13 ( & V_2 -> V_2 , L_7
L_8 ) ;
V_19 = - V_35 ;
goto V_42;
}
V_18 = F_19 ( V_52 ) ;
V_18 -> V_21 = V_23 + V_53 ;
V_18 -> V_33 = V_23 + V_54 ;
}
F_7 ( V_2 , & V_26 [ V_50 ] ) ;
V_19 = F_15 ( & V_2 -> V_2 , - 1 , & V_26 [ V_50 ] ,
1 , NULL , 0 , NULL ) ;
V_42:
return V_19 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_3 * V_4 ;
int V_19 ;
bool V_57 = false ;
V_4 = F_21 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) , V_58 ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_14 = V_56 -> V_60 ;
V_4 -> V_5 . V_6 = - 1 ;
V_4 -> V_5 . V_25 = V_61 ;
V_4 -> V_5 . V_7 = V_62 ;
V_4 -> V_8 . V_6 = - 1 ;
if ( V_4 -> V_14 <= V_63 ) {
V_4 -> V_8 . V_25 = V_64 ;
V_4 -> V_8 . V_7 = V_65 ;
} else {
V_4 -> V_8 . V_25 = V_66 ;
V_4 -> V_8 . V_7 = V_67 ;
}
F_22 ( V_2 , V_4 ) ;
V_19 = F_17 ( V_2 ) ;
if ( ! V_19 )
V_57 = true ;
V_19 = F_11 ( V_2 ) ;
if ( ! V_19 )
V_57 = true ;
if ( ! V_57 ) {
F_23 ( & V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 ) ;
F_22 ( V_2 , NULL ) ;
return - V_35 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_2 ) ;
F_1 ( V_2 ) ;
F_22 ( V_2 , NULL ) ;
}
