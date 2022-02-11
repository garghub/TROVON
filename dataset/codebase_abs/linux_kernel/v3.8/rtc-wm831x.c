static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
T_1 V_3 ;
V_2 = F_2 ( V_1 , V_4 ) ;
if ( V_2 >= 0 ) {
V_3 = V_2 ;
F_3 ( & V_3 , sizeof( V_3 ) ) ;
} else {
F_4 ( V_1 -> V_5 , L_1 ,
V_2 ) ;
}
}
static int F_5 ( struct V_6 * V_5 , struct V_7 * V_8 )
{
struct V_9 * V_9 = F_6 ( V_5 ) ;
struct V_1 * V_1 = V_9 -> V_1 ;
T_1 V_10 [ 2 ] , V_11 [ 2 ] ;
int V_2 ;
int V_12 = 0 ;
V_2 = F_2 ( V_1 , V_13 ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_2 , V_2 ) ;
return V_2 ;
}
if ( ! ( V_2 & V_14 ) ) {
F_8 ( V_5 , L_3 ) ;
return - V_15 ;
}
do {
V_2 = F_9 ( V_1 , V_16 ,
2 , V_10 ) ;
if ( V_2 != 0 )
continue;
V_2 = F_9 ( V_1 , V_16 ,
2 , V_11 ) ;
if ( V_2 != 0 )
continue;
if ( memcmp ( V_10 , V_11 , sizeof( V_10 ) ) == 0 ) {
T_2 time = ( V_10 [ 0 ] << 16 ) | V_10 [ 1 ] ;
F_10 ( time , V_8 ) ;
return F_11 ( V_8 ) ;
}
} while ( ++ V_12 < V_17 );
F_7 ( V_5 , L_4 ) ;
return - V_18 ;
}
static int F_12 ( struct V_6 * V_5 , unsigned long time )
{
struct V_9 * V_9 = F_6 ( V_5 ) ;
struct V_1 * V_1 = V_9 -> V_1 ;
struct V_7 V_19 ;
unsigned long V_20 ;
int V_2 ;
int V_12 = 0 ;
V_2 = F_13 ( V_1 , V_16 ,
( time >> 16 ) & 0xffff ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_5 , V_2 ) ;
return V_2 ;
}
V_2 = F_13 ( V_1 , V_21 , time & 0xffff ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_6 , V_2 ) ;
return V_2 ;
}
do {
F_14 ( 1 ) ;
V_2 = F_2 ( V_1 , V_13 ) ;
if ( V_2 < 0 )
V_2 = V_22 ;
} while ( ! ( V_2 & V_22 ) &&
++ V_12 < V_23 );
if ( V_2 & V_22 ) {
F_7 ( V_5 , L_7 ) ;
return - V_18 ;
}
V_2 = F_5 ( V_5 , & V_19 ) ;
if ( V_2 < 0 )
return V_2 ;
V_2 = F_15 ( & V_19 , & V_20 ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_8 , V_2 ) ;
return V_2 ;
}
if ( V_20 - time > 1 ) {
F_7 ( V_5 , L_9 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_16 ( struct V_6 * V_5 , struct V_25 * V_26 )
{
struct V_9 * V_9 = F_6 ( V_5 ) ;
int V_2 ;
T_1 V_27 [ 2 ] ;
T_2 time ;
V_2 = F_9 ( V_9 -> V_1 , V_28 ,
2 , V_27 ) ;
if ( V_2 != 0 ) {
F_7 ( V_5 , L_10 , V_2 ) ;
return V_2 ;
}
time = ( V_27 [ 0 ] << 16 ) | V_27 [ 1 ] ;
F_10 ( time , & V_26 -> time ) ;
V_2 = F_2 ( V_9 -> V_1 , V_13 ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_2 , V_2 ) ;
return V_2 ;
}
if ( V_2 & V_29 )
V_26 -> V_30 = 1 ;
else
V_26 -> V_30 = 0 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_9 )
{
V_9 -> V_31 = 0 ;
return F_18 ( V_9 -> V_1 , V_13 ,
V_29 , 0 ) ;
}
static int F_19 ( struct V_9 * V_9 )
{
V_9 -> V_31 = 1 ;
return F_18 ( V_9 -> V_1 , V_13 ,
V_29 , V_29 ) ;
}
static int F_20 ( struct V_6 * V_5 , struct V_25 * V_26 )
{
struct V_9 * V_9 = F_6 ( V_5 ) ;
struct V_1 * V_1 = V_9 -> V_1 ;
int V_2 ;
unsigned long time ;
V_2 = F_15 ( & V_26 -> time , & time ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_8 , V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_9 ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_11 , V_2 ) ;
return V_2 ;
}
V_2 = F_13 ( V_1 , V_28 ,
( time >> 16 ) & 0xffff ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_12 , V_2 ) ;
return V_2 ;
}
V_2 = F_13 ( V_1 , V_32 , time & 0xffff ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_13 , V_2 ) ;
return V_2 ;
}
if ( V_26 -> V_30 ) {
V_2 = F_19 ( V_9 ) ;
if ( V_2 < 0 ) {
F_7 ( V_5 , L_14 , V_2 ) ;
return V_2 ;
}
}
return 0 ;
}
static int F_21 ( struct V_6 * V_5 ,
unsigned int V_30 )
{
struct V_9 * V_9 = F_6 ( V_5 ) ;
if ( V_30 )
return F_19 ( V_9 ) ;
else
return F_17 ( V_9 ) ;
}
static T_3 F_22 ( int V_33 , void * V_27 )
{
struct V_9 * V_9 = V_27 ;
F_23 ( V_9 -> V_34 , 1 , V_35 | V_36 ) ;
return V_37 ;
}
static int F_24 ( struct V_6 * V_5 )
{
struct V_38 * V_39 = F_25 ( V_5 ) ;
struct V_9 * V_9 = F_6 ( & V_39 -> V_5 ) ;
int V_2 , V_40 ;
if ( V_9 -> V_31 && F_26 ( & V_39 -> V_5 ) )
V_40 = V_29 ;
else
V_40 = 0 ;
V_2 = F_18 ( V_9 -> V_1 , V_13 ,
V_29 , V_40 ) ;
if ( V_2 != 0 )
F_7 ( & V_39 -> V_5 , L_15 , V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_5 )
{
struct V_38 * V_39 = F_25 ( V_5 ) ;
struct V_9 * V_9 = F_6 ( & V_39 -> V_5 ) ;
int V_2 ;
if ( V_9 -> V_31 ) {
V_2 = F_19 ( V_9 ) ;
if ( V_2 != 0 )
F_7 ( & V_39 -> V_5 ,
L_16 , V_2 ) ;
}
return 0 ;
}
static int F_28 ( struct V_6 * V_5 )
{
struct V_38 * V_39 = F_25 ( V_5 ) ;
struct V_9 * V_9 = F_6 ( & V_39 -> V_5 ) ;
int V_2 ;
V_2 = F_18 ( V_9 -> V_1 , V_13 ,
V_29 , 0 ) ;
if ( V_2 != 0 )
F_7 ( & V_39 -> V_5 , L_17 , V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_6 ( V_39 -> V_5 . V_41 ) ;
struct V_9 * V_9 ;
int V_42 = F_30 ( V_1 , F_31 ( V_39 , L_18 ) ) ;
int V_2 = 0 ;
V_9 = F_32 ( & V_39 -> V_5 , sizeof( * V_9 ) , V_43 ) ;
if ( V_9 == NULL )
return - V_44 ;
F_33 ( V_39 , V_9 ) ;
V_9 -> V_1 = V_1 ;
V_2 = F_2 ( V_1 , V_13 ) ;
if ( V_2 < 0 ) {
F_7 ( & V_39 -> V_5 , L_2 , V_2 ) ;
goto V_45;
}
if ( V_2 & V_29 )
V_9 -> V_31 = 1 ;
F_34 ( & V_39 -> V_5 , 1 ) ;
V_9 -> V_34 = F_35 ( L_19 , & V_39 -> V_5 ,
& V_46 , V_47 ) ;
if ( F_36 ( V_9 -> V_34 ) ) {
V_2 = F_37 ( V_9 -> V_34 ) ;
goto V_45;
}
V_2 = F_38 ( V_42 , NULL , F_22 ,
V_48 , L_20 ,
V_9 ) ;
if ( V_2 != 0 ) {
F_7 ( & V_39 -> V_5 , L_21 ,
V_42 , V_2 ) ;
}
F_1 ( V_1 ) ;
return 0 ;
V_45:
return V_2 ;
}
static int F_39 ( struct V_38 * V_39 )
{
struct V_9 * V_9 = F_40 ( V_39 ) ;
int V_42 = F_31 ( V_39 , L_18 ) ;
F_41 ( V_42 , V_9 ) ;
F_42 ( V_9 -> V_34 ) ;
return 0 ;
}
