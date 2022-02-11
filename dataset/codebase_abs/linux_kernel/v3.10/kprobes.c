static unsigned F_1 ( struct V_1 * V_2 , int * V_3 )
{
unsigned V_4 ;
T_1 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
T_4 V_8 , * V_9 , * V_10 , * V_11 ;
V_11 = 0 ;
* V_3 = V_12 ;
V_9 = ( T_4 * ) V_2 -> V_9 ;
V_10 = ( T_4 * ) ( V_2 + 1 ) ;
V_8 = * V_9 ;
V_4 = V_13 [ V_8 ] ;
if ( V_4 > 0 ) {
V_11 = V_9 + V_4 ;
} else {
switch ( V_8 ) {
case 0xc0 ... 0xca :
V_5 = 2 ;
if ( V_14 [ V_2 -> V_15 & 0xf ] & ( 1 << ( V_8 & 0xf ) ) )
V_5 = ( T_1 ) V_9 [ 1 ] ;
V_11 = V_9 + V_5 ;
* V_3 |= V_16 ;
break;
case 0xcc :
case 0xcd :
F_2 ( V_9 + 1 , & V_6 ) ;
V_11 = V_9 + V_6 ;
* V_3 |= V_16 ;
break;
case 0xdc :
case 0xdd :
F_3 ( V_9 + 1 , & V_7 ) ;
V_11 = V_9 + V_7 ;
* V_3 |= V_16 ;
break;
case 0xde :
V_11 = ( T_4 * ) V_2 -> V_17 ;
* V_3 &= ~ V_12 ;
* V_3 |= V_16 ;
break;
case 0xdf :
V_10 += V_9 [ 2 ] ;
F_3 ( V_10 , & V_7 ) ;
V_11 = ( T_4 * ) V_7 ;
* V_3 &= ~ V_12 ;
* V_3 |= V_16 ;
break;
case 0xf0 :
V_11 = V_9 + 2 ;
V_8 = V_9 [ 1 ] ;
if ( V_8 >= 0xf0 && V_8 <= 0xf7 ) {
switch ( V_8 & 3 ) {
case 0 :
V_11 = ( T_4 * ) V_2 -> V_18 ;
break;
case 1 :
V_11 = ( T_4 * ) V_2 -> V_19 ;
break;
case 2 :
V_11 = ( T_4 * ) V_2 -> V_20 ;
break;
case 3 :
V_11 = ( T_4 * ) V_2 -> V_21 ;
break;
}
* V_3 &= ~ V_12 ;
* V_3 |= V_16 ;
} else if ( V_8 == 0xfc ) {
F_3 ( V_10 , & V_7 ) ;
V_11 = ( T_4 * ) V_7 ;
* V_3 &= ~ V_12 ;
* V_3 |= V_16 ;
} else if ( V_8 == 0xfd ) {
F_3 ( V_10 + 4 , & V_7 ) ;
V_11 = ( T_4 * ) V_7 ;
* V_3 &= ~ V_12 ;
* V_3 |= V_16 ;
}
break;
case 0xf8 :
V_11 = V_9 + 3 ;
V_8 = V_9 [ 1 ] ;
if ( V_8 >= 0xe8 && V_8 <= 0xeb &&
( V_14 [ V_2 -> V_15 & 0xf ] &
( 1 << ( ( V_8 & 0xf ) + 3 ) ) )
) {
F_4 ( V_9 + 2 , & V_5 ) ;
V_11 = V_9 + V_5 ;
* V_3 |= V_16 ;
}
break;
case 0xfa :
if ( V_9 [ 1 ] == 0xff ) {
F_2 ( V_9 + 2 , & V_6 ) ;
V_11 = V_9 + V_6 ;
} else
V_11 = V_9 + 4 ;
* V_3 |= V_16 ;
break;
case 0xfc :
V_7 = 6 ;
if ( V_9 [ 1 ] == 0xff ) {
F_3 ( V_9 + 2 , & V_7 ) ;
}
V_11 = V_9 + V_7 ;
* V_3 |= V_16 ;
break;
case 0xd0 ... 0xda :
case 0xdb :
F_5 ( L_1 ) ;
break;
}
}
return ( unsigned ) V_11 ;
}
static unsigned T_5 F_6 ( struct V_1 * V_2 )
{
T_4 V_8 , * V_9 , * V_10 , * V_11 ;
V_11 = NULL ;
V_9 = ( T_4 * ) V_2 -> V_9 ;
V_10 = ( T_4 * ) ( V_2 + 1 ) ;
switch ( V_9 [ 0 ] ) {
case 0xc0 ... 0xca :
case 0xcc :
case 0xdc :
case 0xf8 :
V_11 = V_9 ;
break;
case 0xcd :
V_9 [ 1 ] = 5 ;
V_9 [ 2 ] = 0 ;
V_11 = V_9 + 5 ;
break;
case 0xdd :
V_9 [ 1 ] = 7 ;
V_9 [ 2 ] = 0 ;
V_9 [ 3 ] = 0 ;
V_9 [ 4 ] = 0 ;
V_11 = V_9 + 7 ;
break;
case 0xde :
V_11 = V_9 + 3 ;
V_2 -> V_17 = ( unsigned ) V_11 ;
break;
case 0xdf :
V_10 += V_9 [ 2 ] ;
V_11 = V_9 + 3 ;
* ( unsigned * ) V_10 = ( unsigned ) V_11 ;
break;
case 0xf0 :
V_11 = V_9 + 2 ;
V_8 = V_9 [ 1 ] ;
if ( V_8 >= 0xf0 && V_8 <= 0xf3 ) {
V_9 [ 0 ] = 0xfa ;
V_9 [ 1 ] = 0xff ;
V_9 [ 2 ] = 4 ;
V_9 [ 3 ] = 0 ;
V_11 = V_9 + 4 ;
} else if ( V_8 >= 0xf4 && V_8 <= 0xf7 ) {
V_11 = V_9 ;
} else if ( V_8 == 0xfc ) {
V_11 = V_9 + 2 ;
* ( unsigned * ) V_10 = ( unsigned ) V_11 ;
} else if ( V_8 == 0xfd ) {
V_11 = V_9 + 2 ;
* ( unsigned * ) ( V_10 + 4 ) = ( unsigned ) V_11 ;
}
break;
case 0xfa :
V_9 [ 2 ] = 4 ;
V_9 [ 3 ] = 0 ;
V_11 = V_9 + 4 ;
break;
case 0xfc :
V_9 [ 2 ] = 6 ;
V_9 [ 3 ] = 0 ;
V_9 [ 4 ] = 0 ;
V_9 [ 5 ] = 0 ;
V_11 = V_9 + 6 ;
break;
case 0xd0 ... 0xda :
case 0xdb :
F_5 ( L_1 ) ;
}
return ( unsigned ) V_11 ;
}
int T_5 F_7 ( struct V_22 * V_23 )
{
return 0 ;
}
void T_5 F_8 ( struct V_22 * V_23 )
{
memcpy ( V_23 -> V_24 . V_25 , V_23 -> V_26 , V_27 ) ;
}
void T_5 F_9 ( struct V_22 * V_23 )
{
* V_23 -> V_26 = V_28 ;
F_10 ( ( unsigned long ) V_23 -> V_26 ,
( unsigned long ) V_23 -> V_26 + sizeof( V_29 ) ) ;
}
void T_5 F_11 ( struct V_22 * V_23 )
{
#ifndef F_12
F_13 () ;
F_14 () ;
#endif
}
void F_15 ( struct V_22 * V_23 )
{
}
static inline
void T_5 F_16 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
* V_23 -> V_26 = V_23 -> V_30 ;
V_2 -> V_9 = ( unsigned long ) V_23 -> V_26 ;
#ifndef F_12
F_13 () ;
F_14 () ;
#endif
}
static inline
void T_5 F_17 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
unsigned long V_31 ;
V_32 = V_2 -> V_9 ;
memcpy ( V_33 , & V_23 -> V_24 . V_25 [ 0 ] , V_27 ) ;
V_2 -> V_9 = ( unsigned long ) V_33 ;
V_31 = F_1 ( V_2 , & V_34 ) ;
if ( V_34 & V_12 )
V_35 = V_32 + ( V_31 - V_2 -> V_9 ) ;
else
V_35 = V_31 ;
if ( V_34 & V_16 )
V_31 = F_6 ( V_2 ) ;
V_36 = V_31 ;
* ( T_4 * ) V_31 = V_28 ;
F_18 ( ( unsigned ) V_33 ,
sizeof( V_33 ) ) ;
F_14 () ;
}
static inline int T_5 F_19 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
int V_37 = 0 ;
unsigned int * V_26 = ( unsigned int * ) V_2 -> V_9 ;
F_20 () ;
if ( F_21 () ) {
V_23 = F_22 ( V_26 ) ;
if ( V_23 ) {
F_16 ( V_23 , V_2 ) ;
V_37 = 1 ;
} else {
V_23 = V_38 ;
if ( V_23 -> V_39 && V_23 -> V_39 ( V_23 , V_2 ) )
goto V_40;
}
goto V_41;
}
V_23 = F_22 ( V_26 ) ;
if ( ! V_23 ) {
if ( * V_26 != V_28 ) {
V_37 = 1 ;
}
goto V_41;
}
V_42 = V_43 ;
V_38 = V_23 ;
if ( V_23 -> V_44 ( V_23 , V_2 ) ) {
return 1 ;
}
V_40:
F_17 ( V_23 , V_2 ) ;
V_42 = V_45 ;
return 1 ;
V_41:
F_23 () ;
return V_37 ;
}
static void T_5 F_24 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
if ( V_34 & V_16 ) {
V_2 -> V_9 = V_32 ;
switch ( V_23 -> V_24 . V_25 [ 0 ] ) {
case 0xcd :
* ( unsigned * ) V_2 -> V_10 = V_2 -> V_17 = V_2 -> V_9 + 5 ;
break;
case 0xdd :
* ( unsigned * ) V_2 -> V_10 = V_2 -> V_17 = V_2 -> V_9 + 7 ;
break;
case 0xf0 :
if ( V_23 -> V_24 . V_25 [ 1 ] >= 0xf0 &&
V_23 -> V_24 . V_25 [ 1 ] <= 0xf3 ) {
V_2 -> V_17 = V_2 -> V_9 + 2 ;
* ( unsigned * ) V_2 -> V_10 = V_2 -> V_17 ;
}
break;
case 0xfa :
* ( unsigned * ) V_2 -> V_10 = V_2 -> V_17 = V_2 -> V_9 + 4 ;
break;
case 0xfc :
* ( unsigned * ) V_2 -> V_10 = V_2 -> V_17 = V_2 -> V_9 + 6 ;
break;
}
}
V_2 -> V_9 = V_35 ;
V_36 = 0 ;
}
static inline int T_5 F_25 ( struct V_1 * V_2 )
{
if ( ! F_21 () )
return 0 ;
if ( V_38 -> V_46 )
V_38 -> V_46 ( V_38 , V_2 , 0 ) ;
F_24 ( V_38 , V_2 ) ;
F_26 () ;
F_23 () ;
return 1 ;
}
static inline
int T_5 F_27 ( struct V_1 * V_2 , int V_47 )
{
if ( V_38 -> V_48 &&
V_38 -> V_48 ( V_38 , V_2 , V_47 ) )
return 1 ;
if ( V_42 & V_45 ) {
F_24 ( V_38 , V_2 ) ;
F_26 () ;
F_23 () ;
}
return 0 ;
}
int T_5 F_28 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
struct V_53 * args = V_52 ;
switch ( V_51 ) {
case V_54 :
if ( V_36 != args -> V_2 -> V_9 ) {
if ( F_19 ( args -> V_2 ) )
return V_55 ;
} else {
if ( F_25 ( args -> V_2 ) )
return V_55 ;
}
break;
case V_56 :
if ( F_21 () &&
F_27 ( args -> V_2 , args -> V_47 ) )
return V_55 ;
break;
default:
break;
}
return V_57 ;
}
int T_5 F_29 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_58 * V_59 = F_30 ( V_23 , struct V_58 , V_60 ) ;
V_61 = V_2 ;
memcpy ( & V_62 , V_2 , sizeof( struct V_1 ) ) ;
memcpy ( & V_63 , V_2 + 1 , sizeof( V_63 ) ) ;
V_2 -> V_9 = ( unsigned long ) V_59 -> V_64 ;
return 1 ;
}
void T_5 F_31 ( void )
{
void * V_65 = V_61 + 1 ;
F_23 () ;
asm volatile(" mov %0,sp\n"
".globl jprobe_return_bp_addr\n"
"jprobe_return_bp_addr:\n\t"
" .byte 0xff\n"
: : "d" (orig_sp));
}
int T_5 F_32 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
T_4 * V_26 = ( T_4 * ) V_2 -> V_9 ;
if ( V_26 == ( T_4 * ) V_66 ) {
if ( V_61 != V_2 ) {
F_33 ( V_67 L_2
L_3
L_4 ,
V_2 , V_61 ) ;
F_34 () ;
}
memcpy ( V_2 , & V_62 , sizeof( struct V_1 ) ) ;
memcpy ( V_2 + 1 , & V_63 ,
sizeof( V_63 ) ) ;
return 1 ;
}
return 0 ;
}
int T_6 F_35 ( void )
{
return 0 ;
}
