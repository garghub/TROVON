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
V_24 = V_27 ;
V_8 = F_9 ( V_13 , V_19 , V_27 ,
F_10 ( V_27 ) ) ;
break;
case V_28 :
default:
V_24 = V_29 ;
V_8 = F_9 ( V_13 , V_19 , V_29 ,
F_10 ( V_29 ) ) ;
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
static inline struct V_30 * F_12 ( int V_31 )
{
return V_24 [ V_31 ] . V_32 ;
}
static inline struct V_17 * F_13 ( int V_31 )
{
return V_24 [ V_31 ] . V_20 ;
}
static int F_6 ( struct V_4 * V_15 )
{
return 0 ;
}
static inline struct V_30 * F_12 ( int V_31 )
{
return NULL ;
}
static inline struct V_17 * F_13 ( int V_31 )
{
return NULL ;
}
static int F_14 ( struct V_4 * V_4 )
{
unsigned int V_33 ;
int V_8 ;
V_8 = F_15 ( V_4 -> V_10 , V_34 , & V_33 ) ;
if ( V_8 )
return V_8 ;
if ( ( ( V_33 & 0x0f ) == 0x8 ) && ( V_4 -> V_22 == V_28 ) ) {
F_16 ( V_4 -> V_13 , L_5 ) ;
} else if ( ( V_33 & 0x0f ) != V_4 -> V_22 &&
( V_33 & 0xf0 ) >> 4 != V_4 -> V_22 ) {
F_17 ( V_4 -> V_13 , L_6 , V_33 ) ;
return - V_35 ;
}
V_8 = F_15 ( V_4 -> V_10 , V_36 , & V_33 ) ;
if ( V_8 )
return V_8 ;
F_16 ( V_4 -> V_13 ,
L_7 ,
( V_33 & 0xf0 ) >> 4 , V_33 & 0x0f ) ;
V_8 = F_15 ( V_4 -> V_10 , V_37 , & V_33 ) ;
if ( V_8 )
return V_8 ;
F_16 ( V_4 -> V_13 , L_8 ,
( V_33 & 0xc ) >> 2 , V_33 & 0x3 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 ,
const struct V_40 * V_6 )
{
struct V_4 * V_4 ;
struct V_41 * V_42 =
F_19 ( & V_39 -> V_13 ) ;
struct V_43 V_44 = { } ;
int V_45 , V_8 ;
const struct V_46 * V_47 ;
T_1 V_48 ;
T_1 V_49 , V_50 , V_51 = 0x40 ;
V_4 = F_20 ( & V_39 -> V_13 , sizeof( * V_4 ) ,
V_52 ) ;
if ( ! V_4 )
return - V_53 ;
if ( V_39 -> V_13 . V_20 ) {
V_47 = F_21 ( F_22 ( V_54 ) ,
& V_39 -> V_13 ) ;
if ( ! V_47 ) {
F_5 ( & V_39 -> V_13 , L_9 ) ;
return - V_35 ;
}
V_4 -> V_22 = ( int ) ( long ) V_47 -> V_55 ;
} else if ( V_6 ) {
V_4 -> V_22 = V_6 -> V_56 ;
} else {
F_5 ( & V_39 -> V_13 , L_10 ) ;
return - V_35 ;
}
F_23 ( V_39 , V_4 ) ;
V_4 -> V_13 = & V_39 -> V_13 ;
V_4 -> V_10 = F_24 ( V_39 , & V_57 ) ;
if ( F_25 ( V_4 -> V_10 ) ) {
V_8 = F_26 ( V_4 -> V_10 ) ;
F_5 ( & V_39 -> V_13 ,
L_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_14 ( V_4 ) ;
if ( V_8 ) {
F_5 ( & V_39 -> V_13 , L_12 ) ;
return V_8 ;
}
switch ( V_4 -> V_22 ) {
case V_23 :
V_58 = V_59 ;
V_48 = F_10 ( V_59 ) ;
V_49 = V_60 ;
V_50 = V_60 ;
V_51 = 1 << 3 ;
break;
case V_26 :
V_58 = V_61 ;
V_48 = F_10 ( V_61 ) ;
V_49 = V_62 ;
V_50 = V_63 ;
break;
case V_28 :
default:
V_58 = V_64 ;
V_48 = F_10 ( V_64 ) ;
V_49 = V_65 ;
V_50 = V_66 ;
break;
}
F_16 ( & V_39 -> V_13 , L_13 ,
( V_4 -> V_22 == V_28 ) ? L_14 :
( ( V_4 -> V_22 == V_26 ) ? L_15 : L_16 ) ) ;
memcpy ( V_4 -> V_67 , V_58 ,
sizeof( V_4 -> V_67 ) ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_8 )
return V_8 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
struct V_30 * V_32 ;
struct V_68 * V_11 ;
int V_69 ;
V_11 = & V_4 -> V_67 [ V_45 ] . V_11 ;
if ( V_42 )
V_32 = V_42 -> V_32 [ V_45 ] ;
else
V_32 = F_12 ( V_45 ) ;
if ( V_45 >= V_49 && V_45 <= V_50 ) {
F_15 ( V_4 -> V_10 , V_11 -> V_12 , & V_69 ) ;
if ( V_69 & V_51 ) {
if ( V_4 -> V_22 == V_23 ) {
V_11 -> V_70 = V_71 ;
V_11 -> V_72 = F_10 ( V_71 ) ;
} else {
V_11 -> V_73 = 800000 ;
V_11 -> V_74 = 50000 ;
V_11 -> V_72 = 51 ;
}
}
}
V_44 . V_13 = & V_39 -> V_13 ;
V_44 . V_32 = V_32 ;
V_44 . V_56 = V_4 ;
V_44 . V_20 = F_13 ( V_45 ) ;
V_44 . V_75 = - V_21 ;
V_4 -> V_76 [ V_45 ] =
F_27 ( & V_39 -> V_13 , V_11 , & V_44 ) ;
if ( F_25 ( V_4 -> V_76 [ V_45 ] ) ) {
F_5 ( & V_39 -> V_13 , L_17 ,
V_58 [ V_45 ] . V_11 . V_77 ) ;
return F_26 ( V_4 -> V_76 [ V_45 ] ) ;
}
}
return 0 ;
}
