static struct V_1 * F_1 ( T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 . V_6 [ V_3 ] . V_7 && V_2 == V_5 . V_6 [ V_3 ] . V_2 )
return & V_5 . V_6 [ V_3 ] ;
return NULL ;
}
static void F_2 ( T_1 V_2 , T_1 V_8 ,
T_1 V_9 , T_1 V_7 )
{
void T_2 * V_10 = V_5 . V_11 + V_2 ;
void T_2 * V_12 = V_5 . V_11 + V_9 ;
asm volatile ("b .s2 0f\n"
"nop 5\n"
" .align 5\n"
"0:\n"
"stw .D1T2 %3,*%2\n"
"stw .D1T2 %1,*%0\n"
:
: "a"(reg_addr), "b"(val), "a"(lock_addr), "b"(key)
);
F_3 ( 0 , V_12 ) ;
}
static void F_4 ( T_1 V_2 , T_1 V_8 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_16 )
{
F_3 ( V_14 , V_5 . V_11 + V_13 ) ;
F_3 ( V_16 , V_5 . V_11 + V_15 ) ;
F_3 ( V_8 , V_5 . V_11 + V_2 ) ;
F_3 ( 0 , V_5 . V_11 + V_13 ) ;
F_3 ( 0 , V_5 . V_11 + V_15 ) ;
}
static void F_5 ( T_1 V_2 , T_1 V_8 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
F_2 ( V_2 , V_8 , V_9 -> V_17 , V_9 -> V_7 ) ;
else if ( V_5 . V_18 [ 0 ] )
F_4 ( V_2 , V_8 , V_5 . V_19 [ 0 ] , V_5 . V_18 [ 0 ] ,
V_5 . V_19 [ 1 ] , V_5 . V_18 [ 1 ] ) ;
else
F_3 ( V_8 , V_5 . V_11 + V_2 ) ;
}
void F_6 ( int V_20 , enum V_21 V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_1 V_29 , V_8 ;
int V_30 , V_31 ;
unsigned long V_32 ;
if ( ! V_5 . V_11 )
return;
if ( V_20 < 0 || V_20 >= V_33 )
return;
V_28 = & V_5 . V_27 [ V_20 ] ;
V_24 = V_28 -> V_24 ;
V_26 = V_28 -> V_26 ;
if ( V_24 == NULL )
return;
V_30 = V_24 -> V_34 + V_24 -> V_35 * ( V_20 - V_24 -> V_36 ) ;
V_31 = ( ( 1 << V_24 -> V_35 ) - 1 ) << V_30 ;
switch ( V_22 ) {
case V_37 :
V_29 = V_24 -> V_38 << V_30 ;
break;
case V_39 :
if ( V_24 -> V_40 )
return;
V_29 = V_24 -> V_41 << V_30 ;
break;
default:
return;
}
F_7 ( & V_5 . V_9 , V_32 ) ;
V_8 = F_8 ( V_5 . V_11 + V_24 -> V_2 ) ;
V_8 &= ~ V_31 ;
V_8 |= V_29 ;
F_5 ( V_24 -> V_2 , V_8 ) ;
F_9 ( & V_5 . V_9 , V_32 ) ;
if ( ! V_26 )
return;
V_30 = V_26 -> V_34 + V_26 -> V_35 * ( V_20 - V_26 -> V_36 ) ;
if ( V_22 == V_37 )
V_29 = V_26 -> V_38 ;
else
V_29 = V_26 -> V_41 ;
do {
V_8 = F_8 ( V_5 . V_11 + V_26 -> V_2 ) ;
V_8 >>= V_30 ;
V_8 &= ( ( 1 << V_26 -> V_35 ) - 1 ) ;
} while ( V_8 != V_29 );
}
void F_10 ( int V_20 , int assert )
{
struct V_42 * V_43 ;
unsigned long V_32 ;
T_1 V_8 ;
if ( V_20 < 0 || V_20 >= V_44 )
return;
V_43 = & V_5 . V_45 [ V_20 ] ;
if ( V_43 -> V_46 == 0 )
return;
F_7 ( & V_5 . V_9 , V_32 ) ;
V_8 = F_8 ( V_5 . V_11 + V_43 -> V_2 ) ;
if ( assert )
F_5 ( V_43 -> V_2 , V_8 | V_43 -> V_46 ) ;
else
F_5 ( V_43 -> V_2 , V_8 & ~ ( V_43 -> V_46 ) ) ;
F_9 ( & V_5 . V_9 , V_32 ) ;
}
static void T_3 F_11 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
T_1 V_8 ;
int V_49 ;
V_49 = F_12 ( V_48 , L_1 , & V_8 , 1 ) ;
if ( ! V_49 )
V_50 = F_8 ( V_11 + V_8 ) ;
F_13 ( V_51 L_2 , V_50 ) ;
}
static void T_3 F_14 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
T_1 V_52 [ 3 ] ;
int V_49 ;
V_49 = F_12 ( V_48 , L_3 , V_52 , 3 ) ;
if ( ! V_49 ) {
V_53 = F_8 ( V_11 + V_52 [ 0 ] ) ;
V_53 >>= V_52 [ 1 ] ;
V_53 &= V_52 [ 2 ] ;
}
}
static void T_3 F_15 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
T_1 V_52 [ 10 ] , V_54 ;
int V_55 , V_3 , V_56 , V_49 ;
V_49 = F_12 ( V_48 , L_4 ,
V_52 , 10 ) ;
if ( V_49 )
return;
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
V_54 = F_8 ( V_11 + V_52 [ V_55 * 5 ] ) ;
for ( V_56 = ( V_55 * 5 ) + 1 , V_3 = 24 ; V_3 >= 0 ; V_3 -= 8 , V_56 ++ )
if ( V_52 [ V_56 ] && V_52 [ V_56 ] <= 6 )
V_57 [ V_52 [ V_56 ] - 1 ] = V_54 >> V_3 ;
}
}
static void T_3 F_16 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
const T_4 * V_58 ;
int V_3 , V_59 ;
V_58 = F_17 ( V_48 , L_5 , & V_59 ) ;
if ( V_58 ) {
V_59 /= ( sizeof( * V_58 ) * 2 ) ;
if ( V_59 > V_44 )
V_59 = V_44 ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
V_5 . V_45 [ V_3 ] . V_2 = F_18 ( V_58 ++ ) ;
V_5 . V_45 [ V_3 ] . V_46 = F_18 ( V_58 ++ ) ;
}
}
}
static void T_3 F_19 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
T_1 V_52 [ 2 ] ;
int V_49 ;
V_49 = F_12 ( V_48 , L_6 , V_52 , 2 ) ;
if ( V_49 )
return;
F_5 ( V_52 [ 0 ] , V_52 [ 1 ] ) ;
}
static void T_3 F_20 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
struct V_1 * V_43 ;
const T_4 * V_58 ;
int V_3 , V_59 ;
V_58 = F_17 ( V_48 , L_7 , & V_59 ) ;
if ( V_58 ) {
V_59 /= ( sizeof( * V_58 ) * 3 ) ;
if ( V_59 > V_4 )
V_59 = V_4 ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
V_43 = & V_5 . V_6 [ V_3 ] ;
V_43 -> V_2 = F_18 ( V_58 ++ ) ;
V_43 -> V_17 = F_18 ( V_58 ++ ) ;
V_43 -> V_7 = F_18 ( V_58 ++ ) ;
}
}
}
static void T_3 F_21 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
T_1 V_52 [ 4 ] ;
int V_49 ;
V_49 = F_12 ( V_48 , L_8 , V_52 , 4 ) ;
if ( ! V_49 ) {
V_5 . V_19 [ 0 ] = V_52 [ 0 ] ;
V_5 . V_18 [ 0 ] = V_52 [ 1 ] ;
V_5 . V_19 [ 1 ] = V_52 [ 2 ] ;
V_5 . V_18 [ 1 ] = V_52 [ 3 ] ;
}
}
static void T_3 F_22 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
struct V_23 * V_43 ;
const T_4 * V_58 ;
int V_3 , V_56 , V_59 ;
V_58 = F_17 ( V_48 , L_9 , & V_59 ) ;
if ( V_58 ) {
V_59 /= ( sizeof( * V_58 ) * 7 ) ;
if ( V_59 > V_60 )
V_59 = V_60 ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
V_43 = & V_5 . V_61 [ V_3 ] ;
V_43 -> V_36 = F_18 ( V_58 ++ ) ;
V_43 -> V_62 = F_18 ( V_58 ++ ) ;
V_43 -> V_2 = F_18 ( V_58 ++ ) ;
V_43 -> V_38 = F_18 ( V_58 ++ ) ;
V_43 -> V_41 = F_18 ( V_58 ++ ) ;
if ( V_43 -> V_41 == 0xffffffff )
V_43 -> V_40 = 1 ;
V_43 -> V_34 = F_18 ( V_58 ++ ) ;
V_43 -> V_35 = F_18 ( V_58 ++ ) ;
for ( V_56 = V_43 -> V_36 ;
V_56 < ( V_43 -> V_36 + V_43 -> V_62 ) ;
V_56 ++ )
V_5 . V_27 [ V_56 ] . V_24 = V_43 ;
}
}
}
static void T_3 F_23 ( struct V_47 * V_48 ,
void T_2 * V_11 )
{
struct V_25 * V_43 ;
const T_4 * V_58 ;
int V_3 , V_56 , V_59 ;
V_58 = F_17 ( V_48 , L_10 , & V_59 ) ;
if ( V_58 ) {
V_59 /= ( sizeof( * V_58 ) * 7 ) ;
if ( V_59 > V_63 )
V_59 = V_63 ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
V_43 = & V_5 . V_64 [ V_3 ] ;
V_43 -> V_36 = F_18 ( V_58 ++ ) ;
V_43 -> V_62 = F_18 ( V_58 ++ ) ;
V_43 -> V_2 = F_18 ( V_58 ++ ) ;
V_43 -> V_38 = F_18 ( V_58 ++ ) ;
V_43 -> V_41 = F_18 ( V_58 ++ ) ;
V_43 -> V_34 = F_18 ( V_58 ++ ) ;
V_43 -> V_35 = F_18 ( V_58 ++ ) ;
for ( V_56 = V_43 -> V_36 ;
V_56 < ( V_43 -> V_36 + V_43 -> V_62 ) ;
V_56 ++ )
V_5 . V_27 [ V_56 ] . V_26 = V_43 ;
}
}
}
void T_3 F_24 ( void )
{
struct V_47 * V_48 ;
void T_2 * V_11 ;
F_25 ( & V_5 . V_9 ) ;
V_48 = F_26 ( NULL , V_65 ) ;
if ( ! V_48 )
return;
V_11 = F_27 ( V_48 , 0 ) ;
if ( ! V_11 ) {
F_28 ( V_48 ) ;
return;
}
V_5 . V_11 = V_11 ;
F_11 ( V_48 , V_11 ) ;
F_14 ( V_48 , V_11 ) ;
F_15 ( V_48 , V_11 ) ;
F_16 ( V_48 , V_11 ) ;
F_20 ( V_48 , V_11 ) ;
F_21 ( V_48 , V_11 ) ;
F_22 ( V_48 , V_11 ) ;
F_23 ( V_48 , V_11 ) ;
F_19 ( V_48 , V_11 ) ;
}
