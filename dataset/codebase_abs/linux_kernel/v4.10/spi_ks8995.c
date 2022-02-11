static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 >> V_2 ) & V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return ( V_1 >> V_4 ) & V_5 ;
}
static inline T_2 F_3 ( struct V_6 * V_7 , int V_8 ,
unsigned V_9 )
{
T_3 V_10 = V_8 ;
V_10 <<= V_7 -> V_11 -> V_12 + V_7 -> V_11 -> V_13 ;
V_10 |= V_9 << V_7 -> V_11 -> V_13 ;
return F_4 ( V_10 ) ;
}
static int F_5 ( struct V_6 * V_7 , char * V_14 ,
unsigned V_15 , T_4 V_16 )
{
T_2 V_8 ;
struct V_17 V_18 [ 2 ] ;
struct V_19 V_20 ;
int V_21 ;
V_8 = F_3 ( V_7 , V_22 , V_15 ) ;
F_6 ( & V_20 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_23 = & V_8 ;
V_18 [ 0 ] . V_24 = sizeof( V_8 ) ;
F_7 ( & V_18 [ 0 ] , & V_20 ) ;
V_18 [ 1 ] . V_25 = V_14 ;
V_18 [ 1 ] . V_24 = V_16 ;
F_7 ( & V_18 [ 1 ] , & V_20 ) ;
F_8 ( & V_7 -> V_26 ) ;
V_21 = F_9 ( V_7 -> V_27 , & V_20 ) ;
F_10 ( & V_7 -> V_26 ) ;
return V_21 ? V_21 : V_16 ;
}
static int F_11 ( struct V_6 * V_7 , char * V_14 ,
unsigned V_15 , T_4 V_16 )
{
T_2 V_8 ;
struct V_17 V_18 [ 2 ] ;
struct V_19 V_20 ;
int V_21 ;
V_8 = F_3 ( V_7 , V_28 , V_15 ) ;
F_6 ( & V_20 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_23 = & V_8 ;
V_18 [ 0 ] . V_24 = sizeof( V_8 ) ;
F_7 ( & V_18 [ 0 ] , & V_20 ) ;
V_18 [ 1 ] . V_23 = V_14 ;
V_18 [ 1 ] . V_24 = V_16 ;
F_7 ( & V_18 [ 1 ] , & V_20 ) ;
F_8 ( & V_7 -> V_26 ) ;
V_21 = F_9 ( V_7 -> V_27 , & V_20 ) ;
F_10 ( & V_7 -> V_26 ) ;
return V_21 ? V_21 : V_16 ;
}
static inline int F_12 ( struct V_6 * V_7 , T_1 V_29 , T_1 * V_14 )
{
return F_5 ( V_7 , V_14 , V_29 , 1 ) != 1 ;
}
static inline int F_13 ( struct V_6 * V_7 , T_1 V_29 , T_1 V_1 )
{
char V_14 = V_1 ;
return F_11 ( V_7 , & V_14 , V_29 , 1 ) != 1 ;
}
static int F_14 ( struct V_6 * V_7 )
{
return F_13 ( V_7 , V_30 , 0 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
return F_13 ( V_7 , V_30 , 1 ) ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_21 ;
V_21 = F_14 ( V_7 ) ;
if ( V_21 )
return V_21 ;
F_17 ( V_31 ) ;
return F_15 ( V_7 ) ;
}
static T_5 F_18 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_14 , T_6 V_38 , T_4 V_16 )
{
struct V_39 * V_40 ;
struct V_6 * V_41 ;
V_40 = F_19 ( V_35 , struct V_39 , V_35 ) ;
V_41 = F_20 ( V_40 ) ;
return F_5 ( V_41 , V_14 , V_38 , V_16 ) ;
}
static T_5 F_21 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_14 , T_6 V_38 , T_4 V_16 )
{
struct V_39 * V_40 ;
struct V_6 * V_41 ;
V_40 = F_19 ( V_35 , struct V_39 , V_35 ) ;
V_41 = F_20 ( V_40 ) ;
return F_11 ( V_41 , V_14 , V_38 , V_16 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
int V_21 ;
T_1 V_42 , V_43 , V_44 ;
V_21 = F_12 ( V_7 , V_45 , & V_42 ) ;
if ( V_21 ) {
V_21 = - V_46 ;
goto V_47;
}
if ( V_42 != V_7 -> V_11 -> V_48 ) {
F_23 ( & V_7 -> V_27 -> V_40 , L_1 ,
V_7 -> V_11 -> V_48 , V_42 ) ;
V_21 = - V_49 ;
goto V_47;
}
switch ( V_7 -> V_11 -> V_48 ) {
case V_50 :
V_21 = F_12 ( V_7 , V_30 , & V_43 ) ;
if ( V_21 ) {
V_21 = - V_46 ;
goto V_47;
}
if ( ( F_1 ( V_43 ) == V_51 ) &&
( F_1 ( V_43 ) == V_7 -> V_11 -> V_52 ) ) {
V_7 -> V_53 = F_2 ( V_43 ) ;
} else if ( F_1 ( V_43 ) != V_51 ) {
V_21 = F_12 ( V_7 , V_30 , & V_44 ) ;
if ( V_21 ) {
V_21 = - V_46 ;
goto V_47;
}
if ( ( V_44 & 0x80 ) &&
( V_7 -> V_11 -> V_52 == V_54 ) ) {
V_7 -> V_53 = F_2 ( V_43 ) ;
}
} else {
F_23 ( & V_7 -> V_27 -> V_40 , L_2 ,
V_43 ) ;
V_21 = - V_49 ;
}
break;
case V_55 :
V_21 = F_12 ( V_7 , V_30 , & V_43 ) ;
if ( V_21 ) {
V_21 = - V_46 ;
goto V_47;
}
if ( F_1 ( V_43 ) == V_7 -> V_11 -> V_52 ) {
V_7 -> V_53 = F_2 ( V_43 ) ;
} else {
F_23 ( & V_7 -> V_27 -> V_40 , L_3 ,
V_43 ) ;
V_21 = - V_49 ;
}
break;
default:
F_23 ( & V_7 -> V_27 -> V_40 , L_4 , V_42 ) ;
V_21 = - V_49 ;
break;
}
V_47:
return V_21 ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_56 * V_57 = V_7 -> V_27 -> V_40 . V_58 ;
struct V_59 * V_60 = V_7 -> V_60 ;
if ( ! V_57 )
return;
V_60 -> V_61 = F_25 ( V_57 , L_5 , 0 ,
& V_60 -> V_62 ) ;
}
static int F_26 ( struct V_63 * V_27 )
{
struct V_6 * V_7 ;
int V_21 ;
int V_64 = F_27 ( V_27 ) -> V_65 ;
if ( V_64 >= V_66 ) {
F_23 ( & V_27 -> V_40 , L_6 , V_64 ) ;
return - V_49 ;
}
V_7 = F_28 ( & V_27 -> V_40 , sizeof( * V_7 ) , V_67 ) ;
if ( ! V_7 )
return - V_68 ;
F_29 ( & V_7 -> V_26 ) ;
V_7 -> V_27 = V_27 ;
V_7 -> V_11 = & V_69 [ V_64 ] ;
if ( V_7 -> V_27 -> V_40 . V_58 ) {
V_7 -> V_60 = F_28 ( & V_27 -> V_40 , sizeof( * V_7 -> V_60 ) ,
V_67 ) ;
if ( ! V_7 -> V_60 )
return - V_68 ;
V_7 -> V_60 -> V_61 = - 1 ;
F_24 ( V_7 ) ;
}
if ( ! V_7 -> V_60 )
V_7 -> V_60 = V_27 -> V_40 . V_70 ;
if ( V_7 -> V_60 && F_30 ( V_7 -> V_60 -> V_61 ) ) {
unsigned long V_71 ;
V_71 = ( V_7 -> V_60 -> V_62 == V_72 ?
V_73 : 0 ) ;
V_21 = F_31 ( & V_27 -> V_40 ,
V_7 -> V_60 -> V_61 ,
V_71 , L_7 ) ;
if ( V_21 ) {
F_23 ( & V_27 -> V_40 ,
L_8 , V_21 ) ;
return - V_46 ;
}
F_32 ( F_33 ( V_7 -> V_60 -> V_61 ) , 0 ) ;
}
F_34 ( V_27 , V_7 ) ;
V_27 -> V_74 = V_75 ;
V_27 -> V_76 = 8 ;
V_21 = F_35 ( V_27 ) ;
if ( V_21 ) {
F_23 ( & V_27 -> V_40 , L_9 , V_21 ) ;
return V_21 ;
}
V_21 = F_22 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_7 -> V_77 . V_78 = V_7 -> V_11 -> V_79 ;
memcpy ( & V_7 -> V_77 , & V_80 , sizeof( V_7 -> V_77 ) ) ;
V_21 = F_16 ( V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_36 ( & V_27 -> V_40 . V_35 , & V_7 -> V_77 ) ;
if ( V_21 ) {
F_23 ( & V_27 -> V_40 , L_10 ,
V_21 ) ;
return V_21 ;
}
F_37 ( & V_27 -> V_40 , L_11 ,
V_7 -> V_11 -> V_81 , V_7 -> V_11 -> V_52 , V_7 -> V_53 ) ;
return 0 ;
}
static int F_38 ( struct V_63 * V_27 )
{
struct V_6 * V_7 = F_39 ( V_27 ) ;
F_40 ( & V_27 -> V_40 . V_35 , & V_7 -> V_77 ) ;
if ( V_7 -> V_60 && F_30 ( V_7 -> V_60 -> V_61 ) )
F_32 ( F_33 ( V_7 -> V_60 -> V_61 ) , 1 ) ;
return 0 ;
}
