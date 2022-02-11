struct V_1 *
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_1 ) ;
F_3 ( V_2 , V_3 ) ;
V_2 -> V_5 = 0 ;
return V_2 ;
}
struct V_1 *
F_4 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_2 ) ;
F_3 ( V_2 , V_3 ) ;
V_2 -> V_5 = ! V_2 -> V_5 ;
return V_2 ;
}
struct V_1 *
F_5 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
int V_6 ;
F_2 ( V_4 , L_3 ) ;
F_6 ( V_2 , V_3 ) ;
if ( F_7 ( V_2 ) ) {
if ( F_7 ( V_3 ) && ( V_3 -> V_5 != V_2 -> V_5 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_3 ) ) {
F_9 ( V_2 , V_3 ) ;
return V_2 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_10 ( V_3 ) ) {
if ( V_3 -> V_5 != V_2 -> V_5 ) {
if ( V_7 -> V_8 == V_9 )
V_2 -> V_5 = 1 ;
else
V_2 -> V_5 = 0 ;
}
} else
F_9 ( V_2 , V_3 ) ;
return V_2 ;
}
V_2 -> V_10 = V_3 -> V_10 = 0 ;
if ( ( V_6 = V_2 -> exp - V_3 -> exp ) > 0 )
F_11 ( V_3 , V_6 ) ;
else if ( ( V_6 = - V_6 ) > 0 )
F_11 ( V_2 , V_6 ) ;
if ( V_2 -> V_5 == V_3 -> V_5 ) {
if ( F_12 ( V_2 , V_3 ) )
if ( ! F_13 ( V_2 ) )
return V_2 ;
} else {
if ( V_2 -> V_11 . V_12 < V_3 -> V_11 . V_12 ) {
F_14 ( V_2 , V_3 , V_2 ) ;
V_2 -> V_5 = ! V_2 -> V_5 ;
} else
F_14 ( V_2 , V_2 , V_3 ) ;
}
return V_2 ;
}
struct V_1 *
F_15 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_4 ) ;
V_3 -> V_5 = ! V_3 -> V_5 ;
return F_5 ( V_2 , V_3 ) ;
}
struct V_1 *
F_16 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_5 ) ;
V_7 -> V_13 [ 1 ] = * V_2 ;
V_3 -> V_5 = ! V_3 -> V_5 ;
return F_5 ( & V_7 -> V_13 [ 1 ] , V_3 ) ;
}
struct V_1 *
F_17 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_6 ) ;
( void ) V_2 ;
return V_3 ;
}
struct V_1 *
F_18 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
union V_14 V_13 ;
int exp ;
F_2 ( V_4 , L_7 ) ;
F_6 ( V_2 , V_3 ) ;
V_2 -> V_5 = V_3 -> V_5 ^ V_2 -> V_5 ;
if ( F_7 ( V_2 ) ) {
if ( F_10 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_3 ) ) {
if ( F_10 ( V_2 ) )
F_8 ( V_2 ) ;
else
F_9 ( V_2 , V_3 ) ;
return V_2 ;
}
if ( F_10 ( V_2 ) || F_10 ( V_3 ) ) {
V_2 -> exp = 0 ;
V_2 -> V_11 . V_12 = 0 ;
V_2 -> V_10 = 0 ;
return V_2 ;
}
exp = V_2 -> exp + V_3 -> exp - 0x3ffe ;
if ( ( long ) V_2 -> V_11 . V_15 [ 0 ] >= 0 )
exp -= F_19 ( V_2 ) ;
if ( ( long ) V_3 -> V_11 . V_15 [ 0 ] >= 0 )
exp -= F_19 ( V_3 ) ;
F_20 ( & V_13 , V_2 , V_3 ) ;
if ( ( long ) V_13 . V_15 [ 0 ] > 0 ) {
exp -- ;
F_21 ( V_2 , & V_13 , 1 ) ;
} else
F_21 ( V_2 , & V_13 , 0 ) ;
if ( exp >= 0x7fff ) {
F_22 ( V_2 ) ;
return V_2 ;
}
V_2 -> exp = exp ;
if ( exp < 0 ) {
F_23 ( V_16 ) ;
F_11 ( V_2 , - exp ) ;
}
return V_2 ;
}
struct V_1 *
F_24 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
union V_14 V_13 ;
int exp ;
F_2 ( V_4 , L_8 ) ;
F_6 ( V_2 , V_3 ) ;
V_2 -> V_5 = V_3 -> V_5 ^ V_2 -> V_5 ;
if ( F_7 ( V_2 ) ) {
if ( F_7 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_3 ) ) {
V_2 -> exp = 0 ;
V_2 -> V_11 . V_12 = 0 ;
V_2 -> V_10 = 0 ;
return V_2 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_10 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_10 ( V_3 ) ) {
F_23 ( V_17 ) ;
V_2 -> exp = 0x7fff ;
V_2 -> V_11 . V_12 = 0 ;
return V_2 ;
}
exp = V_2 -> exp - V_3 -> exp + 0x3fff ;
if ( ( long ) V_2 -> V_11 . V_15 [ 0 ] >= 0 )
exp -= F_19 ( V_2 ) ;
if ( ( long ) V_3 -> V_11 . V_15 [ 0 ] >= 0 )
exp -= F_19 ( V_3 ) ;
F_25 ( & V_13 , V_2 , V_3 ) ;
if ( ! V_13 . V_15 [ 0 ] ) {
exp -- ;
F_21 ( V_2 , & V_13 , 32 ) ;
} else
F_21 ( V_2 , & V_13 , 31 ) ;
if ( exp >= 0x7fff ) {
F_22 ( V_2 ) ;
return V_2 ;
}
V_2 -> exp = exp ;
if ( exp < 0 ) {
F_23 ( V_16 ) ;
F_11 ( V_2 , - exp ) ;
}
return V_2 ;
}
struct V_1 *
F_26 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
int exp ;
F_2 ( V_4 , L_9 ) ;
F_6 ( V_2 , V_3 ) ;
V_2 -> V_5 = V_3 -> V_5 ^ V_2 -> V_5 ;
if ( F_7 ( V_2 ) ) {
if ( F_10 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_3 ) ) {
if ( F_10 ( V_2 ) )
F_8 ( V_2 ) ;
else
F_9 ( V_2 , V_3 ) ;
return V_2 ;
}
if ( F_10 ( V_2 ) || F_10 ( V_3 ) ) {
V_2 -> exp = 0 ;
V_2 -> V_11 . V_12 = 0 ;
V_2 -> V_10 = 0 ;
return V_2 ;
}
exp = V_2 -> exp + V_3 -> exp - 0x3ffe ;
F_27 ( V_2 -> V_11 . V_15 [ 0 ] , V_2 -> V_11 . V_15 [ 1 ] ,
V_2 -> V_11 . V_15 [ 0 ] & 0xffffff00 ,
V_3 -> V_11 . V_15 [ 0 ] & 0xffffff00 ) ;
if ( exp >= 0x7fff ) {
F_22 ( V_2 ) ;
return V_2 ;
}
V_2 -> exp = exp ;
if ( exp < 0 ) {
F_23 ( V_16 ) ;
F_11 ( V_2 , - exp ) ;
}
return V_2 ;
}
struct V_1 *
F_28 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
int exp ;
unsigned long V_18 , V_19 ;
F_2 ( V_4 , L_10 ) ;
F_6 ( V_2 , V_3 ) ;
V_2 -> V_5 = V_3 -> V_5 ^ V_2 -> V_5 ;
if ( F_7 ( V_2 ) ) {
if ( F_7 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_3 ) ) {
V_2 -> exp = 0 ;
V_2 -> V_11 . V_12 = 0 ;
V_2 -> V_10 = 0 ;
return V_2 ;
}
if ( F_10 ( V_2 ) ) {
if ( F_10 ( V_3 ) )
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_10 ( V_3 ) ) {
F_23 ( V_17 ) ;
V_2 -> exp = 0x7fff ;
V_2 -> V_11 . V_12 = 0 ;
return V_2 ;
}
exp = V_2 -> exp - V_3 -> exp + 0x3fff ;
V_2 -> V_11 . V_15 [ 0 ] &= 0xffffff00 ;
V_3 -> V_11 . V_15 [ 0 ] &= 0xffffff00 ;
if ( V_2 -> V_11 . V_15 [ 0 ] >= V_3 -> V_11 . V_15 [ 0 ] ) {
F_29 ( V_2 -> V_11 , V_3 -> V_11 ) ;
F_30 ( V_18 , V_19 , V_2 -> V_11 . V_15 [ 0 ] , 0 , V_3 -> V_11 . V_15 [ 0 ] ) ;
V_2 -> V_11 . V_15 [ 0 ] = 0x80000000 | ( V_18 >> 1 ) ;
V_2 -> V_11 . V_15 [ 1 ] = ( V_18 & 1 ) | V_19 ;
} else {
F_30 ( V_18 , V_19 , V_2 -> V_11 . V_15 [ 0 ] , 0 , V_3 -> V_11 . V_15 [ 0 ] ) ;
V_2 -> V_11 . V_15 [ 0 ] = V_18 ;
V_2 -> V_11 . V_15 [ 1 ] = V_19 ;
exp -- ;
}
if ( exp >= 0x7fff ) {
F_22 ( V_2 ) ;
return V_2 ;
}
V_2 -> exp = exp ;
if ( exp < 0 ) {
F_23 ( V_16 ) ;
F_11 ( V_2 , - exp ) ;
}
return V_2 ;
}
static void F_31 ( struct V_1 * V_2 , int V_20 )
{
union V_21 V_22 ;
unsigned long V_23 ;
if ( ! F_32 ( V_2 ) )
return;
if ( F_7 ( V_2 ) || F_10 ( V_2 ) )
return;
V_22 = V_2 -> V_11 ;
switch ( V_2 -> exp ) {
case 0 ... 0x3ffe :
V_2 -> V_11 . V_12 = 0 ;
break;
case 0x3fff ... 0x401e :
V_2 -> V_11 . V_15 [ 0 ] &= 0xffffffffU << ( 0x401e - V_2 -> exp ) ;
V_2 -> V_11 . V_15 [ 1 ] = 0 ;
if ( V_22 . V_12 == V_2 -> V_11 . V_12 )
return;
break;
case 0x401f ... 0x403e :
V_2 -> V_11 . V_15 [ 1 ] &= 0xffffffffU << ( 0x403e - V_2 -> exp ) ;
if ( V_22 . V_15 [ 1 ] == V_2 -> V_11 . V_15 [ 1 ] )
return;
break;
default:
return;
}
F_23 ( V_24 ) ;
switch ( V_20 ) {
case V_25 :
switch ( V_2 -> exp ) {
case 0 ... 0x3ffd :
return;
case 0x3ffe :
if ( V_22 . V_12 == ( 1ULL << 63 ) )
return;
break;
case 0x3fff ... 0x401d :
V_23 = 1 << ( 0x401d - V_2 -> exp ) ;
if ( ! ( V_22 . V_15 [ 0 ] & V_23 ) )
return;
if ( V_22 . V_15 [ 0 ] & ( V_23 << 1 ) )
break;
if ( ! ( V_22 . V_15 [ 0 ] << ( V_2 -> exp - 0x3ffd ) ) &&
! V_22 . V_15 [ 1 ] )
return;
break;
case 0x401e :
if ( V_22 . V_15 [ 1 ] & 0x80000000 )
return;
if ( V_22 . V_15 [ 0 ] & 1 )
break;
if ( ! ( V_22 . V_15 [ 1 ] << 1 ) )
return;
break;
case 0x401f ... 0x403d :
V_23 = 1 << ( 0x403d - V_2 -> exp ) ;
if ( ! ( V_22 . V_15 [ 1 ] & V_23 ) )
return;
if ( V_22 . V_15 [ 1 ] & ( V_23 << 1 ) )
break;
if ( ! ( V_22 . V_15 [ 1 ] << ( V_2 -> exp - 0x401d ) ) )
return;
break;
default:
return;
}
break;
case V_26 :
return;
default:
if ( V_2 -> V_5 ^ ( V_20 - V_9 ) )
break;
return;
}
switch ( V_2 -> exp ) {
case 0 ... 0x3ffe :
V_2 -> exp = 0x3fff ;
V_2 -> V_11 . V_12 = 1ULL << 63 ;
break;
case 0x3fff ... 0x401e :
V_23 = 1 << ( 0x401e - V_2 -> exp ) ;
if ( V_2 -> V_11 . V_15 [ 0 ] += V_23 )
break;
V_2 -> V_11 . V_15 [ 0 ] = 0x80000000 ;
V_2 -> exp ++ ;
break;
case 0x401f ... 0x403e :
V_23 = 1 << ( 0x403e - V_2 -> exp ) ;
if ( V_2 -> V_11 . V_15 [ 1 ] += V_23 )
break;
if ( V_2 -> V_11 . V_15 [ 0 ] += 1 )
break;
V_2 -> V_11 . V_15 [ 0 ] = 0x80000000 ;
V_2 -> exp ++ ;
break;
}
}
static struct V_1 *
F_33 ( struct V_1 * V_2 , struct V_1 * V_3 , int V_20 )
{
struct V_1 V_27 ;
F_6 ( V_2 , V_3 ) ;
if ( F_7 ( V_2 ) || F_10 ( V_3 ) ) {
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_10 ( V_2 ) || F_7 ( V_3 ) )
return V_2 ;
F_9 ( & V_27 , V_2 ) ;
F_24 ( & V_27 , V_3 ) ;
F_31 ( & V_27 , V_20 ) ;
F_18 ( & V_27 , V_3 ) ;
F_15 ( V_2 , & V_27 ) ;
F_34 ( ( V_2 -> V_11 . V_12 & 0x7f ) | ( V_2 -> V_5 << 7 ) ) ;
return V_2 ;
}
struct V_1 *
F_35 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_11 ) ;
return F_33 ( V_2 , V_3 , V_26 ) ;
}
struct V_1 *
F_36 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_12 ) ;
return F_33 ( V_2 , V_3 , V_25 ) ;
}
struct V_1 *
F_37 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_13 ) ;
F_9 ( V_2 , V_3 ) ;
F_31 ( V_2 , V_7 -> V_8 ) ;
return V_2 ;
}
struct V_1 *
F_38 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_4 , L_14 ) ;
F_9 ( V_2 , V_3 ) ;
F_31 ( V_2 , V_26 ) ;
return V_2 ;
}
struct V_1 *
F_39 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
int V_28 , V_29 ;
F_2 ( V_4 , L_15 ) ;
F_6 ( V_2 , V_3 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( V_2 ) ;
return V_2 ;
}
if ( F_7 ( V_2 ) )
return V_2 ;
if ( F_10 ( V_3 ) || F_10 ( V_2 ) )
return V_2 ;
if ( V_3 -> exp >= 0x400c ) {
F_22 ( V_2 ) ;
return V_2 ;
}
V_29 = V_7 -> V_8 ;
V_7 -> V_8 = V_26 ;
V_28 = F_40 ( V_3 ) ;
V_7 -> V_8 = V_29 ;
V_28 += V_2 -> exp ;
if ( V_28 >= 0x7fff ) {
F_22 ( V_2 ) ;
} else if ( V_28 <= 0 ) {
F_23 ( V_16 ) ;
F_11 ( V_2 , - V_28 ) ;
} else
V_2 -> exp = V_28 ;
return V_2 ;
}
