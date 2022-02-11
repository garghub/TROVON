static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
if ( V_6 < V_9 ) {
V_3 = 12500 / V_3 ;
V_7 = ( V_3 >> 1 ) - ( V_3 >> 3 ) ;
V_8 = F_4 ( V_5 -> V_10 ,
V_2 -> V_11 -> V_12 + 4 ,
0xc0 , V_7 << 6 ) ;
if ( V_8 < 0 )
F_5 ( V_5 -> V_13 , L_1 , V_8 ) ;
} else
V_8 = - V_14 ;
return V_8 ;
}
static int F_6 ( struct V_4 * V_15 )
{
struct V_16 * V_13 = V_15 -> V_13 ;
struct V_17 * V_18 , * V_19 ;
int V_8 ;
V_18 = F_7 ( V_13 -> V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_19 = F_8 ( V_18 , L_2 ) ;
if ( ! V_19 ) {
F_5 ( V_13 , L_3 ) ;
return - V_21 ;
}
switch ( V_15 -> V_22 ) {
case V_23 :
V_24 = V_25 ;
V_8 = F_9 ( V_13 , V_19 , V_25 ,
F_10 ( V_25 ) ) ;
break;
case V_26 :
default:
V_24 = V_27 ;
V_8 = F_9 ( V_13 , V_19 , V_27 ,
F_10 ( V_27 ) ) ;
break;
}
F_11 ( V_19 ) ;
if ( V_8 < 0 ) {
F_5 ( V_13 , L_4 ,
V_8 ) ;
return V_8 ;
}
return 0 ;
}
static inline struct V_28 * F_12 ( int V_29 )
{
return V_24 [ V_29 ] . V_30 ;
}
static inline struct V_17 * F_13 ( int V_29 )
{
return V_24 [ V_29 ] . V_20 ;
}
static int F_6 ( struct V_4 * V_15 )
{
return 0 ;
}
static inline struct V_28 * F_12 ( int V_29 )
{
return NULL ;
}
static inline struct V_17 * F_13 ( int V_29 )
{
return NULL ;
}
static int F_14 ( struct V_4 * V_4 )
{
unsigned int V_31 ;
int V_8 ;
V_8 = F_15 ( V_4 -> V_10 , V_32 , & V_31 ) ;
if ( V_8 )
return V_8 ;
if ( ( ( V_31 & 0x0f ) == 0x8 ) && ( V_4 -> V_22 == V_26 ) ) {
F_16 ( V_4 -> V_13 , L_5 ) ;
} else if ( ( V_31 & 0x0f ) != V_4 -> V_22 ) {
F_17 ( V_4 -> V_13 , L_6 , V_31 ) ;
return - V_33 ;
}
V_8 = F_15 ( V_4 -> V_10 , V_34 , & V_31 ) ;
if ( V_8 )
return V_8 ;
F_16 ( V_4 -> V_13 ,
L_7 ,
( V_31 & 0xf0 ) >> 4 , V_31 & 0x0f ) ;
V_8 = F_15 ( V_4 -> V_10 , V_35 , & V_31 ) ;
if ( V_8 )
return V_8 ;
F_16 ( V_4 -> V_13 , L_8 ,
( V_31 & 0xc ) >> 2 , V_31 & 0x3 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_37 ,
const struct V_38 * V_6 )
{
struct V_4 * V_4 ;
struct V_39 * V_40 =
F_19 ( & V_37 -> V_13 ) ;
struct V_41 V_42 = { } ;
int V_43 , V_8 ;
const struct V_44 * V_45 ;
T_1 V_46 ;
T_1 V_47 , V_48 ;
V_4 = F_20 ( & V_37 -> V_13 , sizeof( * V_4 ) ,
V_49 ) ;
if ( ! V_4 )
return - V_50 ;
if ( V_37 -> V_13 . V_20 ) {
V_45 = F_21 ( F_22 ( V_51 ) ,
& V_37 -> V_13 ) ;
if ( ! V_45 ) {
F_5 ( & V_37 -> V_13 , L_9 ) ;
return - V_33 ;
}
V_4 -> V_22 = ( int ) ( long ) V_45 -> V_52 ;
} else if ( V_6 ) {
V_4 -> V_22 = V_6 -> V_53 ;
} else {
F_5 ( & V_37 -> V_13 , L_10 ) ;
return - V_33 ;
}
F_23 ( V_37 , V_4 ) ;
V_4 -> V_13 = & V_37 -> V_13 ;
V_4 -> V_10 = F_24 ( V_37 , & V_54 ) ;
if ( F_25 ( V_4 -> V_10 ) ) {
V_8 = F_26 ( V_4 -> V_10 ) ;
F_5 ( & V_37 -> V_13 ,
L_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_14 ( V_4 ) ;
if ( V_8 ) {
F_5 ( & V_37 -> V_13 , L_12 ) ;
return V_8 ;
}
switch ( V_4 -> V_22 ) {
case V_23 :
V_55 = V_56 ;
V_46 = F_10 ( V_56 ) ;
V_47 = V_57 ;
V_48 = V_58 ;
break;
case V_26 :
default:
V_55 = V_59 ;
V_46 = F_10 ( V_59 ) ;
V_47 = V_60 ;
V_48 = V_61 ;
break;
}
F_16 ( & V_37 -> V_13 , L_13 ,
( V_4 -> V_22 == V_26 ) ? L_14 : L_15 ) ;
memcpy ( V_4 -> V_62 , V_55 ,
sizeof( V_4 -> V_62 ) ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_8 )
return V_8 ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
struct V_28 * V_30 ;
struct V_63 * V_11 ;
int V_64 ;
V_11 = & V_4 -> V_62 [ V_43 ] . V_11 ;
if ( V_40 )
V_30 = V_40 -> V_30 [ V_43 ] ;
else
V_30 = F_12 ( V_43 ) ;
if ( V_43 >= V_47 && V_43 <= V_48 ) {
F_15 ( V_4 -> V_10 , V_11 -> V_12 , & V_64 ) ;
if ( V_64 & 0x40 ) {
V_11 -> V_65 = 800000 ;
V_11 -> V_66 = 50000 ;
V_11 -> V_67 = 51 ;
}
}
V_42 . V_13 = & V_37 -> V_13 ;
V_42 . V_30 = V_30 ;
V_42 . V_53 = V_4 ;
V_42 . V_20 = F_13 ( V_43 ) ;
V_42 . V_68 = - V_21 ;
V_4 -> V_69 [ V_43 ] =
F_27 ( & V_37 -> V_13 , V_11 , & V_42 ) ;
if ( F_25 ( V_4 -> V_69 [ V_43 ] ) ) {
F_5 ( & V_37 -> V_13 , L_16 ,
V_55 [ V_43 ] . V_11 . V_70 ) ;
return F_26 ( V_4 -> V_69 [ V_43 ] ) ;
}
}
return 0 ;
}
