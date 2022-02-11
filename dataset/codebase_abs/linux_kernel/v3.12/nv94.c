static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00310000 , 0x00000000 ) ;
}
static int
F_3 ( struct V_1 * V_2 , int V_3 )
{
const T_1 V_4 = 1 ;
const T_1 V_5 = V_4 ? 0x00100000 : 0x00200000 ;
const T_1 V_6 = V_4 ? 0x01000000 : 0x02000000 ;
T_1 V_7 , V_8 ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_1 , V_7 ) ;
return - V_9 ;
}
} while ( V_7 & 0x03010000 );
F_2 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00300000 , V_5 ) ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_2 , V_7 ) ;
F_1 ( V_2 , V_3 ) ;
return - V_9 ;
}
} while ( ( V_7 & 0x03000000 ) != V_6 );
return 0 ;
}
int
F_7 ( struct V_10 * V_11 , T_2 type , T_1 V_12 , T_2 * V_13 , T_2 V_14 )
{
struct V_1 * V_2 = V_1 ( V_11 ) ;
struct V_15 * V_16 = ( void * ) V_11 ;
T_1 V_7 , V_17 , V_8 , V_18 ;
T_1 V_19 [ 4 ] = {} ;
int V_3 = V_16 -> V_12 ;
int V_20 , V_21 ;
F_8 ( L_3 , type , V_12 , V_14 ) ;
V_20 = F_3 ( V_2 , V_3 ) ;
if ( V_20 )
goto V_22;
V_17 = F_4 ( V_2 , 0x00e4e8 + ( V_3 * 0x50 ) ) ;
if ( ! ( V_17 & 0x10000000 ) ) {
F_8 ( L_4 ) ;
V_20 = - V_23 ;
goto V_22;
}
if ( ! ( type & 1 ) ) {
memcpy ( V_19 , V_13 , V_14 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 += 4 ) {
F_8 ( L_5 , V_19 [ V_21 / 4 ] ) ;
F_9 ( V_2 , 0x00e4c0 + ( V_3 * 0x50 ) + V_21 , V_19 [ V_21 / 4 ] ) ;
}
}
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
V_7 &= ~ 0x0001f0ff ;
V_7 |= type << 12 ;
V_7 |= V_14 - 1 ;
F_9 ( V_2 , 0x00e4e0 + ( V_3 * 0x50 ) , V_12 ) ;
V_20 = - V_24 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ ) {
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x80000000 | V_7 ) ;
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00000000 | V_7 ) ;
if ( V_18 )
F_5 ( 400 ) ;
F_9 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) , 0x00010000 | V_7 ) ;
V_8 = 1000 ;
do {
V_7 = F_4 ( V_2 , 0x00e4e4 + ( V_3 * 0x50 ) ) ;
F_5 ( 1 ) ;
if ( ! V_8 -- ) {
F_6 ( L_6 , V_7 ) ;
goto V_22;
}
} while ( V_7 & 0x00010000 );
V_17 = F_2 ( V_2 , 0x00e4e8 + ( V_3 * 0x50 ) , 0 , 0 ) ;
if ( ! ( V_17 & 0x000f0f00 ) ) {
V_20 = 0 ;
break;
}
F_8 ( L_7 , V_18 , V_7 , V_17 ) ;
}
if ( type & 1 ) {
for ( V_21 = 0 ; V_21 < 16 ; V_21 += 4 ) {
V_19 [ V_21 / 4 ] = F_4 ( V_2 , 0x00e4d0 + ( V_3 * 0x50 ) + V_21 ) ;
F_8 ( L_8 , V_19 [ V_21 / 4 ] ) ;
}
memcpy ( V_13 , V_19 , V_14 ) ;
}
V_22:
F_1 ( V_2 , V_3 ) ;
return V_20 ;
}
void
F_10 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = ( void * ) F_11 ( V_11 ) -> V_27 ;
struct V_15 * V_16 = ( void * ) V_11 ;
if ( V_16 -> V_7 ) {
F_2 ( V_26 , V_16 -> V_7 + 0x0c , 0x00000001 , 0x00000000 ) ;
F_2 ( V_26 , V_16 -> V_7 + 0x00 , 0x0000f003 , V_16 -> V_13 ) ;
}
}
void
F_12 ( struct V_10 * V_11 )
{
}
static int
F_13 ( struct V_28 * V_29 , struct V_28 * V_27 ,
struct V_30 * V_31 , void * V_13 , T_1 V_32 ,
struct V_28 * * V_33 )
{
struct V_34 * V_35 = V_13 ;
struct V_15 * V_16 ;
int V_20 ;
V_20 = F_14 ( V_29 , V_27 , V_31 , V_32 ,
& V_36 , & V_37 ,
& V_16 ) ;
* V_33 = F_11 ( V_16 ) ;
if ( V_20 )
return V_20 ;
if ( V_35 -> V_38 >= V_39 )
return - V_40 ;
V_16 -> V_41 = 7 ;
V_16 -> V_12 = V_42 [ V_35 -> V_38 ] ;
if ( V_35 -> V_43 != V_44 ) {
V_16 -> V_7 = 0x00e500 + ( V_35 -> V_43 * 0x50 ) ;
V_16 -> V_13 = 0x0000e001 ;
}
return 0 ;
}
int
F_15 ( struct V_28 * V_29 , struct V_28 * V_27 ,
struct V_30 * V_31 , void * V_13 , T_1 V_32 ,
struct V_28 * * V_33 )
{
struct V_34 * V_35 = V_13 ;
struct V_15 * V_16 ;
int V_20 ;
V_20 = F_14 ( V_29 , V_27 , V_31 , V_32 ,
& V_45 , & V_46 ,
& V_16 ) ;
* V_33 = F_11 ( V_16 ) ;
if ( V_20 )
return V_20 ;
V_16 -> V_12 = V_35 -> V_38 ;
if ( V_35 -> V_43 != V_44 ) {
V_16 -> V_7 = 0x00e500 + ( V_35 -> V_38 * 0x50 ) ;
V_16 -> V_13 = 0x00002002 ;
}
return 0 ;
}
static int
F_16 ( struct V_28 * V_29 , struct V_28 * V_27 ,
struct V_30 * V_31 , void * V_13 , T_1 V_14 ,
struct V_28 * * V_33 )
{
struct V_25 * V_26 ;
int V_20 ;
V_20 = F_17 ( V_29 , V_27 , V_31 , V_47 , & V_26 ) ;
* V_33 = F_11 ( V_26 ) ;
if ( V_20 )
return V_20 ;
return 0 ;
}
