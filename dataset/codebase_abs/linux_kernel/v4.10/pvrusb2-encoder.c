static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
const T_1 * V_4 , unsigned int V_5 )
{
unsigned int V_6 , V_7 ;
unsigned int V_8 ;
int V_9 ;
unsigned int V_10 ;
while ( V_5 ) {
V_10 = 8 ;
if ( V_10 > V_5 ) V_10 = V_5 ;
memset ( V_2 -> V_11 , 0 , sizeof( V_2 -> V_11 ) ) ;
V_8 = 0 ;
V_2 -> V_11 [ V_8 ++ ] = V_12 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_7 = V_6 + V_3 ;
V_2 -> V_11 [ V_8 + 6 ] = ( V_7 & 0xffu ) ;
V_2 -> V_11 [ V_8 + 5 ] = ( ( V_7 >> 8 ) & 0xffu ) ;
V_2 -> V_11 [ V_8 + 4 ] = ( ( V_7 >> 16 ) & 0xffu ) ;
F_2 ( V_2 -> V_11 , V_8 , V_4 [ V_6 ] ) ;
V_8 += 7 ;
}
V_9 = F_3 ( V_2 ,
V_2 -> V_11 , 1 + ( V_10 * 7 ) ,
NULL , 0 ) ;
if ( V_9 ) return V_9 ;
V_4 += V_10 ;
V_5 -= V_10 ;
V_3 += V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 ,
T_1 * V_4 , unsigned int V_5 )
{
unsigned int V_6 ;
int V_9 ;
unsigned int V_10 ;
while ( V_5 ) {
V_10 = 16 ;
if ( V_10 > V_5 ) V_10 = V_5 ;
if ( V_10 < 16 ) V_10 = 1 ;
V_2 -> V_11 [ 0 ] =
( ( V_10 == 1 ) ?
V_13 : V_14 ) ;
V_2 -> V_11 [ 1 ] = 0 ;
V_2 -> V_11 [ 2 ] = 0 ;
V_2 -> V_11 [ 3 ] = 0 ;
V_2 -> V_11 [ 4 ] = 0 ;
V_2 -> V_11 [ 5 ] = ( ( V_3 >> 16 ) & 0xffu ) ;
V_2 -> V_11 [ 6 ] = ( ( V_3 >> 8 ) & 0xffu ) ;
V_2 -> V_11 [ 7 ] = ( V_3 & 0xffu ) ;
V_9 = F_3 ( V_2 ,
V_2 -> V_11 , 8 ,
V_2 -> V_11 ,
( V_10 == 1 ? 4 : 16 * 4 ) ) ;
if ( V_9 ) return V_9 ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_4 [ V_6 ] = F_5 ( V_2 -> V_11 , V_6 * 4 ) ;
}
V_4 += V_10 ;
V_5 -= V_10 ;
V_3 += V_10 ;
}
return 0 ;
}
static int F_6 ( void * V_15 ,
T_1 V_16 ,
int V_17 ,
int V_18 ,
T_1 * V_19 )
{
unsigned int V_20 ;
unsigned int V_21 = 0 ;
int V_22 ;
int V_9 = 0 ;
unsigned int V_6 ;
T_1 V_23 [ 16 ] ;
T_1 V_24 [ 16 ] ;
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
if ( V_17 > ( F_7 ( V_23 ) - 4 ) ) {
F_8 (
V_25 ,
L_1 ,
V_17 , ( long unsigned ) F_7 ( V_23 ) - 4 ) ;
return - V_26 ;
}
if ( V_18 > ( F_7 ( V_24 ) - 4 ) ) {
F_8 (
V_25 ,
L_2 ,
V_18 , ( long unsigned ) F_7 ( V_24 ) - 4 ) ;
return - V_26 ;
}
F_9 ( V_2 -> V_27 ) ; do {
if ( ! V_2 -> V_28 ) {
V_9 = - V_29 ;
break;
}
V_22 = 0 ;
V_21 ++ ;
V_9 = 0 ;
V_23 [ 0 ] = 0 ;
V_23 [ 1 ] = V_16 ;
V_23 [ 2 ] = 0 ;
V_23 [ 3 ] = 0x00060000 ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ ) {
V_23 [ V_6 + 4 ] = V_19 [ V_6 ] ;
}
for (; V_6 < F_7 ( V_23 ) - 4 ; V_6 ++ ) {
V_23 [ V_6 + 4 ] = 0 ;
}
V_9 = F_1 ( V_2 , V_30 , V_23 , V_6 ) ;
if ( V_9 ) break;
V_23 [ 0 ] = V_31 | V_32 ;
V_9 = F_1 ( V_2 , V_30 , V_23 , 1 ) ;
if ( V_9 ) break;
V_20 = 0 ;
while ( 1 ) {
V_20 ++ ;
V_9 = F_4 ( V_2 , V_30 , V_24 ,
V_18 + 4 ) ;
if ( V_9 ) {
break;
}
if ( V_24 [ 0 ] & V_33 ) {
break;
}
if ( V_24 [ 0 ] && ( V_20 < 1000 ) ) continue;
if ( ! V_24 [ 0 ] ) {
V_22 = ! 0 ;
F_8 (
V_25 ,
L_3 ) ;
} else {
F_8 (
V_25 ,
L_4 ,
V_24 [ 0 ] ) ;
}
F_8 (
V_25 ,
L_5 , V_16 ) ;
for ( V_6 = 4 ; V_6 < V_17 ; V_6 ++ ) {
F_8 (
V_25 ,
L_6 ,
V_6 - 3 , V_23 [ V_6 ] ) ;
}
V_9 = - V_34 ;
break;
}
if ( V_22 ) {
if ( V_21 < 20 ) continue;
F_8 (
V_25 ,
L_7 ) ;
V_9 = - V_34 ;
}
if ( V_9 ) {
F_10 ( & V_2 -> V_35 ) ;
V_2 -> V_28 = 0 ;
F_8 ( V_36 ,
L_8 ,
L_9 ,
( V_2 -> V_28 ? L_10 : L_11 ) ) ;
if ( V_2 -> V_37 ) {
V_2 -> V_37 = 0 ;
F_8 ( V_36 ,
L_8 ,
L_12 ,
( V_2 -> V_37 ?
L_10 : L_11 ) ) ;
}
F_8 (
V_25 ,
L_13 ) ;
break;
}
V_23 [ 0 ] = 0x7 ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
V_19 [ V_6 ] = V_24 [ V_6 + 4 ] ;
}
V_23 [ 0 ] = 0x0 ;
V_9 = F_1 ( V_2 , V_30 , V_23 , 1 ) ;
if ( V_9 ) break;
} while( 0 ); F_11 ( V_2 -> V_27 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , int V_16 ,
int args , ... )
{
T_2 V_38 ;
unsigned int V_6 ;
T_1 V_4 [ 12 ] ;
if ( args > F_7 ( V_4 ) ) {
F_8 (
V_25 ,
L_14 ,
args , ( long unsigned ) F_7 ( V_4 ) ) ;
return - V_26 ;
}
va_start ( V_38 , args ) ;
for ( V_6 = 0 ; V_6 < args ; V_6 ++ ) {
V_4 [ V_6 ] = va_arg ( V_38 , T_1 ) ;
}
va_end ( V_38 ) ;
return F_6 ( V_2 , V_16 , args , 0 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
int V_39 = 0 ;
#if 0
LOCK_TAKE(hdw->ctl_lock); do {
u32 dat[1];
dat[0] = 0x80000640;
pvr2_encoder_write_words(hdw,0x01fe,dat,1);
pvr2_encoder_write_words(hdw,0x023e,dat,1);
} while(0); LOCK_GIVE(hdw->ctl_lock);
#endif
#if 0
ret |= pvr2_encoder_vcmd(hdw, CX2341X_ENC_MISC,4, 5,0,0,0);
#endif
if ( V_2 -> V_40 -> V_41 ) {
V_39 = 1 ;
} else {
V_39 = 0 ;
}
V_9 |= F_12 ( V_2 , V_42 , 4 , 3 ,
V_39 , 0 , 0 ) ;
V_9 |= F_12 ( V_2 , V_42 , 4 , 8 , 0 , 0 , 0 ) ;
#if 0
ret |= pvr2_encoder_vcmd(hdw, CX2341X_ENC_MISC,4, 4,1,0,0);
#endif
V_9 |= F_12 ( V_2 , V_42 , 4 , 0 , 3 , 0 , 0 ) ;
V_9 |= F_12 ( V_2 , V_42 , 4 , 15 , 0 , 0 , 0 ) ;
V_9 |= F_12 ( V_2 , V_42 , 2 , 4 , 1 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_15 ( V_2 , F_6 ,
( V_2 -> V_43 ? & V_2 -> V_44 : NULL ) ,
& V_2 -> V_45 ) ;
if ( V_9 ) {
F_8 ( V_25 ,
L_15 , V_9 ) ;
} else {
V_2 -> V_44 = V_2 -> V_45 ;
V_2 -> V_43 = ! 0 ;
}
return V_9 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_9 ;
int V_46 ;
F_8 ( V_47 , L_16 ) ;
V_2 -> V_45 . V_48 = V_49 ;
V_2 -> V_45 . V_50 = V_2 -> V_51 ;
V_2 -> V_45 . V_52 = V_2 -> V_53 ;
V_2 -> V_45 . V_54 = ( ( V_2 -> V_55 & V_56 ) ?
0 : 1 ) ;
V_9 = 0 ;
V_9 |= F_13 ( V_2 ) ;
V_46 = 0xf0 ;
if ( V_2 -> V_40 -> V_41 ) {
V_46 = 0x140 ;
}
if ( ! V_9 ) V_9 = F_12 (
V_2 , V_57 , 2 ,
V_46 , V_46 ) ;
if ( ! V_9 ) V_9 = F_12 (
V_2 , V_58 , 4 ,
0 , 0 , 0x10000000 , 0xffffffff ) ;
if ( ! V_9 ) V_9 = F_12 (
V_2 , V_59 , 5 ,
0xffffffff , 0 , 0 , 0 , 0 ) ;
if ( V_9 ) {
F_8 ( V_25 ,
L_17 ) ;
return V_9 ;
}
V_9 = F_14 ( V_2 ) ;
if ( V_9 ) return V_9 ;
V_9 = F_12 (
V_2 , V_60 , 0 ) ;
if ( V_9 ) {
F_8 ( V_25 ,
L_18 ) ;
return V_9 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_61 ;
F_18 ( V_2 , 0x0048 , 0xbfffffff ) ;
F_12 ( V_2 , V_62 , 1 ,
V_2 -> V_63 == V_64 ? 1 : 0 ) ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_61 = F_12 ( V_2 , V_67 , 2 ,
0x01 , 0x14 ) ;
break;
case V_68 :
V_61 = F_12 ( V_2 , V_67 , 2 ,
0 , 0x13 ) ;
break;
default:
V_61 = F_12 ( V_2 , V_67 , 2 ,
0 , 0x13 ) ;
break;
}
return V_61 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_61 ;
F_18 ( V_2 , 0x0048 , 0xffffffff ) ;
switch ( V_2 -> V_65 ) {
case V_66 :
V_61 = F_12 ( V_2 , V_69 , 3 ,
0x01 , 0x01 , 0x14 ) ;
break;
case V_68 :
V_61 = F_12 ( V_2 , V_69 , 3 ,
0x01 , 0 , 0x13 ) ;
break;
default:
V_61 = F_12 ( V_2 , V_69 , 3 ,
0x01 , 0 , 0x13 ) ;
break;
}
return V_61 ;
}
