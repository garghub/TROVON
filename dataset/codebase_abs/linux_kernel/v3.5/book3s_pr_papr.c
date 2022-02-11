static unsigned long F_1 ( struct V_1 * V_2 , long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
V_3 <<= 4 ;
V_3 &= ( ( 1 << ( ( V_5 -> V_7 & 0x1f ) + 11 ) ) - 1 ) << 7 | 0x70 ;
V_6 = V_5 -> V_7 & 0xfffffffffffc0000ULL ;
V_6 |= V_3 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
long V_8 = F_4 ( V_2 , 4 ) ;
long V_3 = F_4 ( V_2 , 5 ) ;
unsigned long V_9 [ 2 * 8 ] ;
unsigned long V_6 , V_10 , * V_11 ;
V_3 &= ~ 7UL ;
V_6 = F_1 ( V_2 , V_3 ) ;
F_5 ( V_9 , ( void V_12 * ) V_6 , sizeof( V_9 ) ) ;
V_11 = V_9 ;
if ( F_6 ( ( V_8 & V_13 ) == 0 ) ) {
V_3 &= ~ 7UL ;
for ( V_10 = 0 ; ; ++ V_10 ) {
if ( V_10 == 8 )
return V_14 ;
if ( ( * V_11 & V_15 ) == 0 )
break;
V_11 += 2 ;
}
} else {
V_10 = F_4 ( V_2 , 5 ) & 7UL ;
V_11 += V_10 * 2 ;
}
V_11 [ 0 ] = F_4 ( V_2 , 6 ) ;
V_11 [ 1 ] = F_4 ( V_2 , 7 ) ;
F_7 ( ( void V_12 * ) V_6 , V_9 , sizeof( V_9 ) ) ;
F_8 ( V_2 , 3 , V_16 ) ;
F_8 ( V_2 , 4 , V_3 | V_10 ) ;
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned long V_8 = F_4 ( V_2 , 4 ) ;
unsigned long V_3 = F_4 ( V_2 , 5 ) ;
unsigned long V_18 = F_4 ( V_2 , 6 ) ;
unsigned long V_19 = 0 , V_9 , V_20 ;
unsigned long V_21 [ 2 ] ;
V_9 = F_1 ( V_2 , V_3 ) ;
F_5 ( V_21 , ( void V_12 * ) V_9 , sizeof( V_21 ) ) ;
if ( ( V_21 [ 0 ] & V_15 ) == 0 ||
( ( V_8 & V_22 ) && ( V_21 [ 0 ] & ~ 0x7fUL ) != V_18 ) ||
( ( V_8 & V_23 ) && ( V_21 [ 0 ] & V_18 ) != 0 ) ) {
F_8 ( V_2 , 3 , V_24 ) ;
return V_17 ;
}
F_7 ( ( void V_12 * ) V_9 , & V_19 , sizeof( V_19 ) ) ;
V_20 = F_10 ( V_21 [ 0 ] , V_21 [ 1 ] , V_3 ) ;
V_2 -> V_25 . V_26 . V_27 ( V_2 , V_20 , V_20 & 1 ? true : false ) ;
F_8 ( V_2 , 3 , V_16 ) ;
F_8 ( V_2 , 4 , V_21 [ 0 ] ) ;
F_8 ( V_2 , 5 , V_21 [ 1 ] ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_10 ;
int V_28 = 4 ;
int V_29 = V_16 ;
for ( V_10 = 0 ; V_10 < V_30 ; V_10 ++ ) {
unsigned long V_31 = F_4 ( V_2 , V_28 + ( 2 * V_10 ) ) ;
unsigned long V_32 = F_4 ( V_2 , V_28 + ( 2 * V_10 ) + 1 ) ;
unsigned long V_9 , V_20 , V_8 ;
unsigned long V_21 [ 2 ] ;
unsigned long V_19 = 0 ;
if ( ( V_31 & V_33 ) == V_34 ) {
break;
} else if ( ( V_31 & V_33 ) !=
V_35 ) {
V_29 = V_36 ;
break;
}
V_31 &= V_37 | V_38 ;
V_31 |= V_39 ;
if ( ( V_31 & V_40 ) &&
( V_31 & V_41 ) ) {
V_31 |= V_42 ;
F_8 ( V_2 , V_28 + ( 2 * V_10 ) , V_31 ) ;
V_29 = V_36 ;
break;
}
V_9 = F_1 ( V_2 , V_31 & V_37 ) ;
F_5 ( V_21 , ( void V_12 * ) V_9 , sizeof( V_21 ) ) ;
V_8 = ( V_31 & V_38 ) >> 26 ;
if ( ( V_21 [ 0 ] & V_15 ) == 0 ||
( ( V_8 & V_22 ) && ( V_21 [ 0 ] & ~ 0x7fUL ) != V_32 ) ||
( ( V_8 & V_23 ) && ( V_21 [ 0 ] & V_32 ) != 0 ) ) {
V_31 |= V_43 ;
} else {
F_7 ( ( void V_12 * ) V_9 , & V_19 , sizeof( V_19 ) ) ;
V_20 = F_10 ( V_21 [ 0 ] , V_21 [ 1 ] ,
V_31 & V_37 ) ;
V_2 -> V_25 . V_26 . V_27 ( V_2 , V_20 , V_20 & 1 ? true : false ) ;
V_31 |= V_44 ;
V_31 |= ( V_21 [ 1 ] & ( V_45 | V_46 ) ) << 43 ;
}
F_8 ( V_2 , V_28 + ( 2 * V_10 ) , V_31 ) ;
}
F_8 ( V_2 , 3 , V_29 ) ;
return V_17 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_8 = F_4 ( V_2 , 4 ) ;
unsigned long V_3 = F_4 ( V_2 , 5 ) ;
unsigned long V_18 = F_4 ( V_2 , 6 ) ;
unsigned long V_20 , V_9 , V_47 , V_19 ;
unsigned long V_21 [ 2 ] ;
V_9 = F_1 ( V_2 , V_3 ) ;
F_5 ( V_21 , ( void V_12 * ) V_9 , sizeof( V_21 ) ) ;
if ( ( V_21 [ 0 ] & V_15 ) == 0 ||
( ( V_8 & V_22 ) && ( V_21 [ 0 ] & ~ 0x7fUL ) != V_18 ) ) {
F_8 ( V_2 , 3 , V_24 ) ;
return V_17 ;
}
V_19 = V_21 [ 0 ] ;
V_47 = V_21 [ 1 ] ;
V_47 &= ~ ( V_48 | V_49 | V_50 | V_51 |
V_52 ) ;
V_47 |= ( V_8 << 55 ) & V_48 ;
V_47 |= ( V_8 << 48 ) & V_51 ;
V_47 |= V_8 & ( V_49 | V_50 | V_52 ) ;
V_21 [ 1 ] = V_47 ;
V_20 = F_10 ( V_19 , V_47 , V_3 ) ;
V_2 -> V_25 . V_26 . V_27 ( V_2 , V_20 , V_20 & 1 ? true : false ) ;
F_7 ( ( void V_12 * ) V_9 , V_21 , sizeof( V_21 ) ) ;
F_8 ( V_2 , 3 , V_16 ) ;
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned long V_53 = F_4 ( V_2 , 4 ) ;
unsigned long V_54 = F_4 ( V_2 , 5 ) ;
unsigned long V_55 = F_4 ( V_2 , 6 ) ;
long V_56 ;
V_56 = F_14 ( V_2 , V_53 , V_54 , V_55 ) ;
if ( V_56 == V_57 )
return V_58 ;
F_8 ( V_2 , 3 , V_56 ) ;
return V_17 ;
}
int F_15 ( struct V_1 * V_2 , unsigned long V_59 )
{
switch ( V_59 ) {
case V_60 :
return F_3 ( V_2 ) ;
case V_61 :
return F_9 ( V_2 ) ;
case V_62 :
return F_12 ( V_2 ) ;
case V_63 :
return F_11 ( V_2 ) ;
case V_64 :
return F_13 ( V_2 ) ;
case V_65 :
V_2 -> V_25 . V_66 -> V_67 |= V_68 ;
F_16 ( V_2 ) ;
F_17 ( V_69 , & V_2 -> V_70 ) ;
V_2 -> V_71 . V_72 ++ ;
return V_17 ;
}
return V_58 ;
}
