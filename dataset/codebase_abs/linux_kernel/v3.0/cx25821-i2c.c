static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
return F_2 ( V_4 -> V_8 ) & 0x01 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
return F_2 ( V_4 -> V_8 ) & 0x02 ? 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! F_3 ( V_2 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_10 == V_9 )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_12 * V_13 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_1 V_15 , V_16 , V_17 ;
int V_18 , V_19 ;
if ( V_14 )
F_7 ( 1 , L_1 , V_20 ,
V_13 -> V_21 , V_14 ) ;
else
F_7 ( 1 , L_2 , V_20 , V_13 -> V_21 ) ;
if ( V_13 -> V_21 == 0 ) {
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_4 -> V_24 | ( 1 << 2 ) ) ;
if ( ! F_4 ( V_2 ) )
return - V_25 ;
if ( ! F_1 ( V_2 ) )
return - V_25 ;
F_7 ( 1 , L_3 , V_20 ) ;
return 0 ;
}
V_16 = ( V_13 -> V_16 << 25 ) | V_13 -> V_26 [ 0 ] ;
V_15 = V_13 -> V_26 [ 0 ] ;
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) ;
if ( V_13 -> V_21 > 1 )
V_17 |= V_27 | V_28 ;
else if ( V_14 )
V_17 |= V_27 ;
F_8 ( V_4 -> V_22 , V_16 ) ;
F_8 ( V_4 -> V_29 , V_15 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
V_18 = F_4 ( V_2 ) ;
if ( V_18 < 0 )
goto V_30;
if ( V_18 == 0 )
goto V_31;
if ( V_32 ) {
if ( ! ( V_17 & V_27 ) )
F_9 ( L_4 ) ;
}
for ( V_19 = 1 ; V_19 < V_13 -> V_21 ; V_19 ++ ) {
V_15 = V_13 -> V_26 [ V_19 ] ;
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) ;
if ( V_19 < V_13 -> V_21 - 1 )
V_17 |= V_27 | V_28 ;
else if ( V_14 )
V_17 |= V_27 ;
F_8 ( V_4 -> V_22 , V_16 ) ;
F_8 ( V_4 -> V_29 , V_15 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
V_18 = F_4 ( V_2 ) ;
if ( V_18 < 0 )
goto V_30;
if ( V_18 == 0 )
goto V_31;
if ( V_32 ) {
F_7 ( 1 , L_5 , V_13 -> V_26 [ V_19 ] ) ;
if ( ! ( V_17 & V_27 ) )
F_7 ( 1 , L_4 ) ;
}
}
return V_13 -> V_21 ;
V_31:
V_18 = - V_25 ;
V_30:
if ( V_32 )
F_10 ( L_6 , V_18 ) ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_12 * V_13 , int V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_1 V_17 , V_19 ;
int V_18 ;
if ( V_32 && ! V_33 )
F_7 ( 1 , L_7 , V_20 , V_13 -> V_21 ) ;
if ( V_13 -> V_21 == 0 ) {
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_4 -> V_24 | ( 1 << 2 ) | 1 ) ;
if ( ! F_4 ( V_2 ) )
return - V_25 ;
if ( ! F_1 ( V_2 ) )
return - V_25 ;
F_7 ( 1 , L_3 , V_20 ) ;
return 0 ;
}
if ( V_32 ) {
if ( V_33 )
F_7 ( 1 , L_8 ) ;
else
F_7 ( 1 , L_9 , ( V_13 -> V_16 << 1 ) + 1 ) ;
}
for ( V_19 = 0 ; V_19 < V_13 -> V_21 ; V_19 ++ ) {
V_17 = V_4 -> V_24 | ( 1 << 12 ) | ( 1 << 2 ) | 1 ;
if ( V_19 < V_13 -> V_21 - 1 )
V_17 |= V_27 | V_28 ;
F_8 ( V_4 -> V_22 , V_13 -> V_16 << 25 ) ;
F_8 ( V_4 -> V_23 , V_17 ) ;
V_18 = F_4 ( V_2 ) ;
if ( V_18 < 0 )
goto V_30;
if ( V_18 == 0 )
goto V_31;
V_13 -> V_26 [ V_19 ] = F_2 ( V_4 -> V_34 ) & 0xff ;
if ( V_32 ) {
F_7 ( 1 , L_5 , V_13 -> V_26 [ V_19 ] ) ;
if ( ! ( V_17 & V_27 ) )
F_7 ( 1 , L_4 ) ;
}
}
return V_13 -> V_21 ;
V_31:
V_18 = - V_25 ;
V_30:
if ( V_32 )
F_10 ( L_6 , V_18 ) ;
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_12 * V_35 , int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_37 , V_18 = 0 ;
F_7 ( 1 , L_10 , V_20 , V_36 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
F_7 ( 1 , L_11 ,
V_20 , V_36 , V_35 [ V_37 ] . V_16 , V_35 [ V_37 ] . V_21 ) ;
if ( V_35 [ V_37 ] . V_38 & V_39 ) {
V_18 = F_11 ( V_2 , & V_35 [ V_37 ] , 0 ) ;
} else if ( V_37 + 1 < V_36 && ( V_35 [ V_37 + 1 ] . V_38 & V_39 ) &&
V_35 [ V_37 ] . V_16 == V_35 [ V_37 + 1 ] . V_16 ) {
V_18 =
F_6 ( V_2 , & V_35 [ V_37 ] , V_35 [ V_37 + 1 ] . V_21 ) ;
if ( V_18 < 0 )
goto V_30;
V_37 ++ ;
V_18 = F_11 ( V_2 , & V_35 [ V_37 ] , 1 ) ;
} else {
V_18 = F_6 ( V_2 , & V_35 [ V_37 ] , 0 ) ;
}
if ( V_18 < 0 )
goto V_30;
}
return V_36 ;
V_30:
return V_18 ;
}
static T_1 F_13 ( struct V_1 * V_40 )
{
return V_41 |
V_42 |
V_43 |
V_44 | V_45 ;
}
int F_14 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
F_7 ( 1 , L_12 , V_20 , V_4 -> V_46 ) ;
memcpy ( & V_4 -> V_2 , & V_47 ,
sizeof( V_4 -> V_2 ) ) ;
memcpy ( & V_4 -> V_48 , & V_49 ,
sizeof( V_4 -> V_48 ) ) ;
memcpy ( & V_4 -> V_50 , & V_51 ,
sizeof( V_4 -> V_50 ) ) ;
V_4 -> V_2 . V_7 . V_52 = & V_7 -> V_53 -> V_7 ;
F_15 ( V_4 -> V_2 . V_54 , V_4 -> V_7 -> V_54 , sizeof( V_4 -> V_2 . V_54 ) ) ;
V_4 -> V_48 . V_55 = V_4 ;
V_4 -> V_2 . V_5 = V_4 ;
F_16 ( & V_4 -> V_2 , & V_7 -> V_56 ) ;
F_17 ( & V_4 -> V_2 ) ;
V_4 -> V_50 . V_57 = & V_4 -> V_2 ;
V_4 -> V_50 . V_16 = ( 0x88 >> 1 ) ;
return V_4 -> V_58 ;
}
int F_18 ( struct V_3 * V_4 )
{
F_19 ( & V_4 -> V_2 ) ;
return 0 ;
}
void F_20 ( struct V_6 * V_7 , int V_59 )
{
char V_60 [ 3 ] ;
struct V_12 V_13 ;
F_7 ( 1 , L_13 , V_20 , V_59 ) ;
V_60 [ 0 ] = 0x01 ;
V_60 [ 1 ] = 0x44 ;
if ( V_59 == 1 )
V_60 [ 2 ] = 0x05 ;
else
V_60 [ 2 ] = 0x00 ;
V_13 . V_16 = 0x44 ;
V_13 . V_38 = V_61 ;
V_13 . V_21 = 3 ;
V_13 . V_26 = V_60 ;
F_12 ( & V_7 -> V_62 [ 0 ] . V_2 , & V_13 , 1 ) ;
}
int F_21 ( struct V_3 * V_4 , T_2 V_22 , int * V_63 )
{
struct V_50 * V_64 = & V_4 -> V_50 ;
int V_18 = 0 ;
int V_65 = 0 ;
T_3 V_16 [ 2 ] = { 0 , 0 } ;
T_3 V_26 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_12 V_35 [ 2 ] = {
{
. V_16 = V_64 -> V_16 ,
. V_38 = 0 ,
. V_21 = 2 ,
. V_26 = V_16 ,
} , {
. V_16 = V_64 -> V_16 ,
. V_38 = V_39 ,
. V_21 = 4 ,
. V_26 = V_26 ,
}
} ;
V_16 [ 0 ] = ( V_22 >> 8 ) ;
V_16 [ 1 ] = ( V_22 & 0xff ) ;
V_35 [ 0 ] . V_16 = 0x44 ;
V_35 [ 1 ] . V_16 = 0x44 ;
V_18 = F_12 ( V_64 -> V_57 , V_35 , 2 ) ;
V_65 = ( V_26 [ 3 ] << 24 ) | ( V_26 [ 2 ] << 16 ) | ( V_26 [ 1 ] << 8 ) | V_26 [ 0 ] ;
* V_63 = V_65 ;
return V_65 ;
}
int F_22 ( struct V_3 * V_4 , T_2 V_22 , int V_63 )
{
struct V_50 * V_64 = & V_4 -> V_50 ;
int V_18 = 0 ;
T_3 V_26 [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
struct V_12 V_35 [ 1 ] = {
{
. V_16 = V_64 -> V_16 ,
. V_38 = 0 ,
. V_21 = 6 ,
. V_26 = V_26 ,
}
} ;
V_26 [ 0 ] = V_22 >> 8 ;
V_26 [ 1 ] = V_22 & 0xff ;
V_26 [ 5 ] = ( V_63 >> 24 ) & 0xff ;
V_26 [ 4 ] = ( V_63 >> 16 ) & 0xff ;
V_26 [ 3 ] = ( V_63 >> 8 ) & 0xff ;
V_26 [ 2 ] = V_63 & 0xff ;
V_64 -> V_38 = 0 ;
V_35 [ 0 ] . V_16 = 0x44 ;
V_18 = F_12 ( V_64 -> V_57 , V_35 , 1 ) ;
return V_18 ;
}
