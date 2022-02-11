static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 [ 2 ] , V_8 [ 2 ] ;
int V_9 ;
int V_10 = 0 ;
V_9 = F_3 ( V_6 , V_11 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
if ( ! ( V_9 & V_12 ) ) {
F_5 ( V_2 , L_2 ) ;
return - V_13 ;
}
do {
V_9 = F_6 ( V_6 , V_14 ,
2 , V_7 ) ;
if ( V_9 != 0 )
continue;
V_9 = F_6 ( V_6 , V_14 ,
2 , V_8 ) ;
if ( V_9 != 0 )
continue;
if ( memcmp ( V_7 , V_8 , sizeof( V_7 ) ) == 0 ) {
T_2 time = ( V_7 [ 0 ] << 16 ) | V_7 [ 1 ] ;
F_7 ( time , V_4 ) ;
return F_8 ( V_4 ) ;
}
} while ( ++ V_10 < V_15 );
F_4 ( V_2 , L_3 ) ;
return - V_16 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long time )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_3 V_17 ;
unsigned long V_18 ;
int V_9 ;
int V_10 = 0 ;
V_9 = F_10 ( V_6 , V_14 ,
( time >> 16 ) & 0xffff ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_6 , V_19 , time & 0xffff ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_5 , V_9 ) ;
return V_9 ;
}
do {
F_11 ( 1 ) ;
V_9 = F_3 ( V_6 , V_11 ) ;
if ( V_9 < 0 )
V_9 = V_20 ;
} while ( ! ( V_9 & V_20 ) &&
++ V_10 < V_21 );
if ( V_9 & V_20 ) {
F_4 ( V_2 , L_6 ) ;
return - V_16 ;
}
V_9 = F_1 ( V_2 , & V_17 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_12 ( & V_17 , & V_18 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
if ( V_18 - time > 1 ) {
F_4 ( V_2 , L_8 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_9 ;
T_1 V_25 [ 2 ] ;
T_2 time ;
V_9 = F_6 ( V_5 -> V_6 , V_26 ,
2 , V_25 ) ;
if ( V_9 != 0 ) {
F_4 ( V_2 , L_9 , V_9 ) ;
return V_9 ;
}
time = ( V_25 [ 0 ] << 16 ) | V_25 [ 1 ] ;
F_7 ( time , & V_24 -> time ) ;
V_9 = F_3 ( V_5 -> V_6 , V_11 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
if ( V_9 & V_27 )
V_24 -> V_28 = 1 ;
else
V_24 -> V_28 = 0 ;
return 0 ;
}
static int F_14 ( struct V_5 * V_5 )
{
V_5 -> V_29 = 0 ;
return F_15 ( V_5 -> V_6 , V_11 ,
V_27 , 0 ) ;
}
static int F_16 ( struct V_5 * V_5 )
{
V_5 -> V_29 = 1 ;
return F_15 ( V_5 -> V_6 , V_11 ,
V_27 , V_27 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_9 ;
unsigned long time ;
V_9 = F_12 ( & V_24 -> time , & time ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_14 ( V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_10 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_6 , V_26 ,
( time >> 16 ) & 0xffff ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_11 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_6 , V_30 , time & 0xffff ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_12 , V_9 ) ;
return V_9 ;
}
if ( V_24 -> V_28 ) {
V_9 = F_16 ( V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_13 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_28 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_28 )
return F_16 ( V_5 ) ;
else
return F_14 ( V_5 ) ;
}
static T_3 F_19 ( int V_31 , void * V_25 )
{
struct V_5 * V_5 = V_25 ;
F_20 ( V_5 -> V_32 , 1 , V_33 | V_34 ) ;
return V_35 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_22 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_37 -> V_2 ) ;
int V_9 , V_38 ;
if ( V_5 -> V_29 && F_23 ( & V_37 -> V_2 ) )
V_38 = V_27 ;
else
V_38 = 0 ;
V_9 = F_15 ( V_5 -> V_6 , V_11 ,
V_27 , V_38 ) ;
if ( V_9 != 0 )
F_4 ( & V_37 -> V_2 , L_14 , V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_22 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_37 -> V_2 ) ;
int V_9 ;
if ( V_5 -> V_29 ) {
V_9 = F_16 ( V_5 ) ;
if ( V_9 != 0 )
F_4 ( & V_37 -> V_2 ,
L_15 , V_9 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_22 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( & V_37 -> V_2 ) ;
int V_9 ;
V_9 = F_15 ( V_5 -> V_6 , V_11 ,
V_27 , 0 ) ;
if ( V_9 != 0 )
F_4 ( & V_37 -> V_2 , L_16 , V_9 ) ;
return 0 ;
}
static int F_26 ( struct V_36 * V_37 )
{
struct V_6 * V_6 = F_2 ( V_37 -> V_2 . V_39 ) ;
struct V_5 * V_5 ;
int V_40 = F_27 ( V_6 , F_28 ( V_37 , L_17 ) ) ;
int V_9 = 0 ;
V_5 = F_29 ( & V_37 -> V_2 , sizeof( * V_5 ) , V_41 ) ;
if ( V_5 == NULL )
return - V_42 ;
F_30 ( V_37 , V_5 ) ;
V_5 -> V_6 = V_6 ;
V_9 = F_3 ( V_6 , V_11 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_37 -> V_2 , L_1 , V_9 ) ;
goto V_43;
}
if ( V_9 & V_27 )
V_5 -> V_29 = 1 ;
F_31 ( & V_37 -> V_2 , 1 ) ;
V_5 -> V_32 = F_32 ( L_18 , & V_37 -> V_2 ,
& V_44 , V_45 ) ;
if ( F_33 ( V_5 -> V_32 ) ) {
V_9 = F_34 ( V_5 -> V_32 ) ;
goto V_43;
}
V_9 = F_35 ( V_40 , NULL , F_19 ,
V_46 , L_19 ,
V_5 ) ;
if ( V_9 != 0 ) {
F_4 ( & V_37 -> V_2 , L_20 ,
V_40 , V_9 ) ;
}
return 0 ;
V_43:
return V_9 ;
}
static int T_4 F_36 ( struct V_36 * V_37 )
{
struct V_5 * V_5 = F_37 ( V_37 ) ;
int V_40 = F_28 ( V_37 , L_17 ) ;
F_38 ( V_40 , V_5 ) ;
F_39 ( V_5 -> V_32 ) ;
return 0 ;
}
