static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 | V_8 ,
V_7 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_1 , V_4 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 | V_8 , 0 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_2 , V_4 ) ;
}
return V_4 ;
}
static T_1 F_4 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
F_5 ( V_2 -> V_2 , 1 , V_11 | V_12 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_4 ;
T_2 V_16 [ 2 ] [ 5 ] ;
int V_17 = 1 ;
int V_18 = V_19 ;
V_4 = F_7 ( V_2 -> V_5 , V_20 , 5 , & V_16 [ 0 ] [ 0 ] ) ;
if ( V_4 ) {
F_3 ( V_2 , L_3 , V_4 ) ;
return V_4 ;
}
do {
V_4 = F_7 ( V_2 -> V_5 ,
V_20 , 5 , & V_16 [ V_17 ] [ 0 ] ) ;
if ( V_4 ) {
F_3 ( V_2 , L_3 , V_4 ) ;
return V_4 ;
}
if ( memcmp ( & V_16 [ 0 ] [ 0 ] , & V_16 [ 1 ] [ 0 ] , 5 ) == 0 ) {
V_15 -> V_21 = ( V_16 [ 0 ] [ 4 ] & V_22 ) + 100 ;
V_15 -> V_23 = ( V_16 [ 0 ] [ 3 ] & V_24 ) - 1 ;
V_15 -> V_25 = V_16 [ 0 ] [ 2 ] & V_26 ;
V_15 -> V_27 = V_16 [ 0 ] [ 1 ] & V_28 ;
V_15 -> V_29 = V_16 [ 0 ] [ 0 ] & V_30 ;
V_4 = F_8 ( V_15 ) ;
return V_4 ;
}
V_17 = ( 1 - V_17 ) ;
F_9 ( 20 ) ;
} while ( V_18 -- );
F_3 ( V_2 , L_4 ) ;
return - V_31 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned long V_32 ;
int V_4 ;
T_2 V_16 [ 3 ] ;
V_4 = F_11 ( V_15 , & V_32 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_15 -> V_33 > 0 ) {
V_32 += 60 - V_15 -> V_33 ;
F_12 ( V_32 , V_15 ) ;
}
F_13 ( V_15 -> V_33 ) ;
V_15 -> V_21 -= 100 ;
V_15 -> V_23 += 1 ;
V_4 = F_2 ( V_5 , V_20 ,
V_30 , V_15 -> V_29 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 , L_5 , V_4 ) ;
return V_4 ;
}
V_16 [ 0 ] = V_15 -> V_27 ;
V_16 [ 1 ] = V_15 -> V_25 ;
V_16 [ 2 ] = V_15 -> V_23 ;
V_4 = F_14 ( V_5 , V_34 , 3 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_5 , V_6 ,
V_22 , V_15 -> V_21 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_6 , V_4 ) ;
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_16 ( V_2 -> V_5 , V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 , L_7 , V_4 ) ;
return V_4 ;
}
return ! ! ( V_4 & V_7 ) ;
}
static int F_17 ( struct V_35 * V_36 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_18 ( V_36 ) ;
int V_4 ;
T_2 V_16 [ 2 ] [ 6 ] ;
int V_17 = 1 ;
int V_18 = V_19 ;
V_4 = F_7 ( V_2 -> V_5 , V_37 , 6 , & V_16 [ 0 ] [ 0 ] ) ;
if ( V_4 ) {
F_3 ( V_2 , L_8 , V_4 ) ;
return V_4 ;
}
do {
V_4 = F_7 ( V_2 -> V_5 ,
V_37 , 6 , & V_16 [ V_17 ] [ 0 ] ) ;
if ( V_4 ) {
F_3 ( V_2 , L_8 , V_4 ) ;
return V_4 ;
}
if ( memcmp ( & V_16 [ 0 ] [ 0 ] , & V_16 [ 1 ] [ 0 ] , 6 ) == 0 ) {
V_15 -> V_21 = ( V_16 [ 0 ] [ 5 ] & V_22 ) + 100 ;
V_15 -> V_23 = ( V_16 [ 0 ] [ 4 ] & V_24 ) - 1 ;
V_15 -> V_25 = V_16 [ 0 ] [ 3 ] & V_26 ;
V_15 -> V_27 = V_16 [ 0 ] [ 2 ] & V_28 ;
V_15 -> V_29 = V_16 [ 0 ] [ 1 ] & V_30 ;
V_15 -> V_33 = V_16 [ 0 ] [ 0 ] & V_38 ;
V_4 = F_8 ( V_15 ) ;
return V_4 ;
}
V_17 = ( 1 - V_17 ) ;
F_9 ( 20 ) ;
} while ( V_18 -- );
F_3 ( V_2 , L_9 ) ;
return - V_31 ;
}
static int F_19 ( struct V_35 * V_36 , struct V_14 * V_39 )
{
struct V_1 * V_2 ;
T_2 V_16 [ 6 ] ;
int V_4 ;
if ( ( V_39 -> V_21 < 100 ) || ( V_39 -> V_21 > 163 ) )
return - V_40 ;
V_2 = F_18 ( V_36 ) ;
V_16 [ 0 ] = V_39 -> V_33 ;
V_16 [ 1 ] = V_39 -> V_29 ;
V_16 [ 2 ] = V_39 -> V_27 ;
V_16 [ 3 ] = V_39 -> V_25 ;
V_16 [ 4 ] = V_39 -> V_23 + 1 ;
V_16 [ 5 ] = V_39 -> V_21 - 100 ;
V_4 = F_14 ( V_2 -> V_5 , V_37 , 6 , V_16 ) ;
if ( V_4 < 0 )
F_3 ( V_2 , L_10 , V_4 ) ;
return V_4 ;
}
static int F_20 ( struct V_35 * V_36 , struct V_41 * V_42 )
{
int V_4 ;
struct V_14 * V_39 = & V_42 -> time ;
struct V_1 * V_2 = F_18 ( V_36 ) ;
V_4 = F_6 ( V_2 , V_39 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 , L_11 , V_4 ) ;
return V_4 ;
}
V_42 -> V_43 = F_15 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_41 * V_42 )
{
int V_4 ;
struct V_14 * V_39 = & V_42 -> time ;
struct V_1 * V_2 = F_18 ( V_36 ) ;
if ( ( V_39 -> V_21 < 100 ) || ( V_39 -> V_21 > 163 ) )
return - V_40 ;
V_4 = F_1 ( V_2 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_10 ( V_2 , V_39 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , 1 ) ;
return V_4 ;
}
static int F_22 ( struct V_35 * V_36 , unsigned int V_43 )
{
struct V_1 * V_2 = F_18 ( V_36 ) ;
return F_1 ( V_2 , V_43 ) ;
}
static int F_23 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_24 ( & V_45 -> V_36 , sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_5 = F_18 ( V_45 -> V_36 . V_48 ) ;
F_25 ( V_45 , V_2 ) ;
V_4 = F_26 ( V_2 -> V_5 , V_49 , 0xFE ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 ,
L_12 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_8 , 0 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_13 , V_4 ) ;
V_4 = F_27 ( V_2 -> V_5 , V_50 , L_14 ,
F_4 , V_2 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 , L_15 , V_4 ) ;
return V_4 ;
}
F_28 ( & V_45 -> V_36 , true ) ;
V_2 -> V_2 = F_29 ( & V_45 -> V_36 , V_45 -> V_51 ,
& V_52 , V_53 ) ;
return F_30 ( V_2 -> V_2 ) ;
}
