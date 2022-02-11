static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_2 -> V_7 -> V_6 ;
unsigned int V_8 ;
int V_9 ;
if ( V_6 < V_10 ) {
V_3 = 12500 / V_3 ;
V_8 = ( V_3 >> 1 ) - ( V_3 >> 3 ) ;
V_9 = F_3 ( V_5 -> V_11 ,
V_2 -> V_7 -> V_12 + 4 ,
0xc0 , V_8 << 6 ) ;
if ( V_9 < 0 )
F_4 ( V_5 -> V_13 , L_1 , V_9 ) ;
} else
V_9 = - V_14 ;
return V_9 ;
}
static int F_5 ( struct V_4 * V_15 )
{
struct V_16 * V_13 = V_15 -> V_13 ;
struct V_17 * V_18 , * V_19 ;
int V_9 ;
V_18 = F_6 ( V_13 -> V_19 -> V_20 ) ;
if ( ! V_18 )
return 0 ;
V_19 = F_7 ( V_18 , L_2 ) ;
if ( ! V_19 ) {
F_4 ( V_13 , L_3 ) ;
return - V_21 ;
}
V_9 = F_8 ( V_13 , V_19 , V_22 ,
F_9 ( V_22 ) ) ;
F_10 ( V_19 ) ;
if ( V_9 < 0 ) {
F_4 ( V_13 , L_4 ,
V_9 ) ;
return V_9 ;
}
return 0 ;
}
static inline struct V_23 * F_11 ( int V_24 )
{
return V_22 [ V_24 ] . V_25 ;
}
static inline struct V_17 * F_12 ( int V_24 )
{
return V_22 [ V_24 ] . V_20 ;
}
static int F_5 ( struct V_4 * V_15 )
{
return 0 ;
}
static inline struct V_23 * F_11 ( int V_24 )
{
return NULL ;
}
static inline struct V_17 * F_12 ( int V_24 )
{
return NULL ;
}
static int F_13 ( struct V_4 * V_4 )
{
unsigned int V_26 ;
int V_9 ;
V_9 = F_14 ( V_4 -> V_11 , V_27 , & V_26 ) ;
if ( V_9 )
return V_9 ;
switch ( V_26 & 0x0f ) {
case 0x8 :
F_15 ( V_4 -> V_13 , L_5 ) ;
case 0x0 :
break;
default:
F_16 ( V_4 -> V_13 , L_6 , V_26 ) ;
return - V_28 ;
}
V_9 = F_14 ( V_4 -> V_11 , V_29 , & V_26 ) ;
if ( V_9 )
return V_9 ;
F_15 ( V_4 -> V_13 ,
L_7 ,
( V_26 & 0xf0 ) >> 4 , V_26 & 0x0f ) ;
V_9 = F_14 ( V_4 -> V_11 , V_30 , & V_26 ) ;
if ( V_9 )
return V_9 ;
F_15 ( V_4 -> V_13 , L_8 ,
( V_26 & 0xc ) >> 2 , V_26 & 0x3 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 ,
const struct V_33 * V_6 )
{
struct V_4 * V_4 ;
struct V_34 * V_35 =
F_18 ( & V_32 -> V_13 ) ;
struct V_36 V_37 = { } ;
int V_38 , V_9 ;
V_4 = F_19 ( & V_32 -> V_13 , sizeof( * V_4 ) ,
V_39 ) ;
if ( ! V_4 )
return - V_40 ;
F_20 ( V_32 , V_4 ) ;
memcpy ( V_4 -> V_41 , V_42 ,
sizeof( V_4 -> V_41 ) ) ;
V_4 -> V_13 = & V_32 -> V_13 ;
V_4 -> V_11 = F_21 ( V_32 , & V_43 ) ;
if ( F_22 ( V_4 -> V_11 ) ) {
V_9 = F_23 ( V_4 -> V_11 ) ;
F_4 ( & V_32 -> V_13 ,
L_9 , V_9 ) ;
return V_9 ;
}
V_9 = F_13 ( V_4 ) ;
if ( V_9 ) {
F_4 ( & V_32 -> V_13 , L_10 ) ;
return V_9 ;
}
V_9 = F_5 ( V_4 ) ;
if ( V_9 )
return V_9 ;
for ( V_38 = 0 ; V_38 < V_44 ; V_38 ++ ) {
struct V_23 * V_25 ;
struct V_45 * V_7 ;
int V_46 ;
V_7 = & V_4 -> V_41 [ V_38 ] . V_7 ;
if ( V_35 )
V_25 = V_35 -> V_25 [ V_38 ] ;
else
V_25 = F_11 ( V_38 ) ;
if ( V_38 > V_47 && V_38 < V_10 ) {
F_14 ( V_4 -> V_11 , V_7 -> V_12 , & V_46 ) ;
if ( V_46 & 0x40 ) {
V_7 -> V_48 = 800000 ;
V_7 -> V_49 = 50000 ;
V_7 -> V_50 = 51 ;
}
}
V_37 . V_13 = & V_32 -> V_13 ;
V_37 . V_25 = V_25 ;
V_37 . V_51 = V_4 ;
V_37 . V_20 = F_12 ( V_38 ) ;
V_4 -> V_52 [ V_38 ] =
F_24 ( & V_32 -> V_13 , V_7 , & V_37 ) ;
if ( F_22 ( V_4 -> V_52 [ V_38 ] ) ) {
F_4 ( & V_32 -> V_13 , L_11 ,
V_42 [ V_38 ] . V_7 . V_53 ) ;
return F_23 ( V_4 -> V_52 [ V_38 ] ) ;
}
}
return 0 ;
}
