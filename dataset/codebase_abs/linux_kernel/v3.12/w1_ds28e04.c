static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
if ( V_1 > V_3 )
return 0 ;
if ( ( V_1 + V_2 ) > V_3 )
return V_3 - V_1 ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_8 )
{
T_3 V_9 [ 3 ] ;
int V_1 = V_8 * V_10 ;
if ( V_7 -> V_11 & ( 1 << V_8 ) )
return 0 ;
if ( F_3 ( V_5 ) ) {
V_7 -> V_11 = 0 ;
return - V_12 ;
}
V_9 [ 0 ] = V_13 ;
V_9 [ 1 ] = V_1 & 0xff ;
V_9 [ 2 ] = V_1 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_5 ( V_5 -> V_14 , & V_7 -> V_15 [ V_1 ] , V_10 ) ;
if ( F_6 ( V_16 , & V_7 -> V_15 [ V_1 ] , V_10 ) == V_17 )
V_7 -> V_11 |= ( 1 << V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , int V_18 , int V_19 , char * V_7 )
{
T_3 V_9 [ 3 ] ;
if ( F_3 ( V_5 ) )
return - V_12 ;
V_9 [ 0 ] = V_13 ;
V_9 [ 1 ] = V_18 & 0xff ;
V_9 [ 2 ] = V_18 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , sizeof( V_9 ) ) ;
return F_5 ( V_5 -> V_14 , V_7 , V_19 ) ;
}
static T_4 F_8 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_9 ( V_23 ) ;
struct V_6 * V_7 = V_5 -> V_27 ;
int V_28 , V_29 , V_30 ;
V_2 = F_1 ( V_1 , V_2 , V_31 ) ;
if ( V_2 == 0 )
return 0 ;
F_10 ( & V_5 -> V_14 -> V_32 ) ;
if ( V_33 ) {
V_29 = ( V_1 >> V_34 ) ;
V_30 = ( V_1 + V_2 - 1 ) >> V_34 ;
for ( V_28 = V_29 ; V_28 <= V_30 ; V_28 ++ ) {
if ( F_2 ( V_5 , V_7 , V_28 ) ) {
V_2 = - V_12 ;
goto V_35;
}
}
memcpy ( V_26 , & V_7 -> V_15 [ V_1 ] , V_2 ) ;
} else {
V_2 = F_7 ( V_5 , V_1 , V_2 , V_26 ) ;
}
V_35:
F_11 ( & V_5 -> V_14 -> V_32 ) ;
return V_2 ;
}
static int F_12 ( struct V_4 * V_5 , int V_18 , int V_19 , const T_3 * V_7 )
{
T_3 V_9 [ 4 ] ;
T_3 V_36 [ V_10 + 3 ] ;
T_3 V_37 = ( V_18 + V_19 - 1 ) & 0x1f ;
unsigned int V_38 = 10 ;
int V_28 ;
struct V_6 * V_39 = V_5 -> V_27 ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_9 [ 0 ] = V_40 ;
V_9 [ 1 ] = V_18 & 0xff ;
V_9 [ 2 ] = V_18 >> 8 ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_4 ( V_5 -> V_14 , V_7 , V_19 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_13 ( V_5 -> V_14 , V_41 ) ;
F_5 ( V_5 -> V_14 , V_36 , V_19 + 3 ) ;
if ( ( V_36 [ 0 ] != V_9 [ 1 ] ) || ( V_36 [ 1 ] != V_9 [ 2 ] ) ||
( V_36 [ 2 ] != V_37 ) || ( memcmp ( V_7 , & V_36 [ 3 ] , V_19 ) != 0 ) )
return - 1 ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_9 [ 0 ] = V_42 ;
V_9 [ 3 ] = V_37 ;
for ( V_28 = 0 ; V_28 < sizeof( V_9 ) ; ++ V_28 ) {
if ( V_43 && V_28 == sizeof( V_9 ) - 1 )
F_14 ( V_5 -> V_14 , V_38 ) ;
F_13 ( V_5 -> V_14 , V_9 [ V_28 ] ) ;
}
if ( ! V_43 )
F_15 ( V_38 ) ;
if ( V_33 ) {
V_39 -> V_11 &= ~ ( 1 << ( V_18 >> V_34 ) ) ;
}
F_16 ( V_5 -> V_14 ) ;
return 0 ;
}
static T_4 F_17 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_9 ( V_23 ) ;
int V_18 , V_19 , V_44 ;
V_2 = F_1 ( V_1 , V_2 , V_31 ) ;
if ( V_2 == 0 )
return 0 ;
if ( V_33 ) {
if ( ( V_1 & V_45 ) || ( V_2 & V_45 ) ) {
F_18 ( & V_5 -> V_46 , L_1 ,
( int ) V_1 , V_2 ) ;
return - V_47 ;
}
for ( V_44 = 0 ; V_44 < V_2 ; V_44 += V_10 ) {
if ( F_6 ( V_16 , & V_26 [ V_44 ] , V_10 )
!= V_17 ) {
F_18 ( & V_5 -> V_46 , L_2 ,
( int ) V_1 ) ;
return - V_47 ;
}
}
}
F_10 ( & V_5 -> V_14 -> V_32 ) ;
V_44 = 0 ;
while ( V_44 < V_2 ) {
V_18 = V_1 + V_44 ;
V_19 = V_10 - ( V_18 & V_45 ) ;
if ( V_19 > ( V_2 - V_44 ) )
V_19 = V_2 - V_44 ;
if ( F_12 ( V_5 , V_18 , V_19 , & V_26 [ V_44 ] ) < 0 ) {
V_2 = - V_12 ;
goto V_35;
}
V_44 += V_19 ;
}
V_35:
F_11 ( & V_5 -> V_14 -> V_32 ) ;
return V_2 ;
}
static T_4 F_19 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 , T_2 V_1 ,
T_1 V_2 )
{
struct V_4 * V_5 = F_9 ( V_23 ) ;
int V_48 ;
if ( V_1 != 0 || V_2 != 1 || V_26 == NULL )
return - V_47 ;
F_10 ( & V_5 -> V_14 -> V_32 ) ;
V_48 = F_7 ( V_5 , V_49 , V_2 , V_26 ) ;
F_11 ( & V_5 -> V_14 -> V_32 ) ;
return V_48 ;
}
static T_4 F_20 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 , T_2 V_1 ,
T_1 V_2 )
{
struct V_4 * V_5 = F_9 ( V_23 ) ;
T_3 V_9 [ 3 ] ;
T_3 V_50 ;
if ( V_1 != 0 || V_2 != 1 || V_26 == NULL )
return - V_47 ;
F_10 ( & V_5 -> V_14 -> V_32 ) ;
if ( F_3 ( V_5 ) ) {
F_11 ( & V_5 -> V_14 -> V_32 ) ;
return - 1 ;
}
* V_26 = * V_26 | 0xFC ;
V_9 [ 0 ] = V_51 ;
V_9 [ 1 ] = * V_26 ;
V_9 [ 2 ] = ~ ( * V_26 ) ;
F_4 ( V_5 -> V_14 , V_9 , 3 ) ;
F_5 ( V_5 -> V_14 , & V_50 , sizeof( V_50 ) ) ;
F_11 ( & V_5 -> V_14 -> V_32 ) ;
if ( V_50 != 0xAA )
return - V_12 ;
return V_2 ;
}
static T_4 F_21 ( struct V_52 * V_46 , struct V_53 * V_54 ,
char * V_26 )
{
if ( F_22 ( V_33 + 0x30 , V_26 ) )
return - V_55 ;
return sizeof( V_33 ) ;
}
static T_4 F_23 ( struct V_52 * V_46 , struct V_53 * V_54 ,
const char * V_26 , T_1 V_2 )
{
char V_56 ;
if ( V_2 != 1 || ! V_26 )
return - V_47 ;
if ( F_24 ( V_56 , V_26 ) )
return - V_55 ;
V_56 = V_56 - 0x30 ;
if ( V_56 != 0 && V_56 != 1 )
return - V_47 ;
V_33 = V_56 ;
return sizeof( V_33 ) ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
if ( V_33 ) {
V_7 = F_26 ( sizeof( struct V_6 ) , V_57 ) ;
if ( ! V_7 )
return - V_58 ;
V_5 -> V_27 = V_7 ;
}
return 0 ;
}
static void F_27 ( struct V_4 * V_5 )
{
F_28 ( V_5 -> V_27 ) ;
V_5 -> V_27 = NULL ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_59 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_59 ) ;
}
