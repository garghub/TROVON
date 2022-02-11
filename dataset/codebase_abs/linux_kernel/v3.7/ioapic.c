static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 = 0 ;
switch ( V_2 -> V_6 ) {
case V_7 :
V_5 = ( ( ( ( V_8 - 1 ) & 0xff ) << 16 )
| ( V_9 & 0xff ) ) ;
break;
case V_10 :
case V_11 :
V_5 = ( ( V_2 -> V_12 & 0xf ) << 24 ) ;
break;
default:
{
T_1 V_13 = ( V_2 -> V_6 - 0x10 ) >> 1 ;
T_2 V_14 ;
ASSERT ( V_13 < V_8 ) ;
V_14 = V_2 -> V_15 [ V_13 ] . V_16 ;
V_5 = ( V_2 -> V_6 & 0x1 ) ?
( V_14 >> 32 ) & 0xffffffff :
V_14 & 0xffffffff ;
break;
}
}
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_17 )
{
union V_18 * V_19 ;
int V_20 = - 1 ;
V_19 = & V_2 -> V_15 [ V_17 ] ;
if ( ! V_19 -> V_21 . V_22 ) {
V_20 = F_3 ( V_2 , V_17 ) ;
if ( V_20 && V_19 -> V_21 . V_23 == V_24 )
V_19 -> V_21 . V_25 = 1 ;
}
return V_20 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_26 , 256 ) ;
int V_27 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
for ( V_27 = 0 ; V_27 < V_8 ; ++ V_27 )
F_6 ( V_2 -> V_15 [ V_27 ] . V_21 . V_28 , V_26 ) ;
memcpy ( V_2 -> V_26 , V_26 ,
sizeof( V_26 ) ) ;
F_7 () ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_29 )
{
unsigned V_30 ;
bool V_31 , V_32 ;
union V_18 * V_33 ;
switch ( V_2 -> V_6 ) {
case V_7 :
break;
case V_10 :
V_2 -> V_12 = ( V_29 >> 24 ) & 0xf ;
break;
case V_11 :
break;
default:
V_30 = ( V_2 -> V_6 - 0x10 ) >> 1 ;
F_9 ( L_1 , V_30 , V_29 ) ;
if ( V_30 >= V_8 )
return;
V_33 = & V_2 -> V_15 [ V_30 ] ;
V_31 = V_33 -> V_21 . V_22 ;
if ( V_2 -> V_6 & 1 ) {
V_33 -> V_16 &= 0xffffffff ;
V_33 -> V_16 |= ( T_2 ) V_29 << 32 ;
} else {
V_33 -> V_16 &= ~ 0xffffffffULL ;
V_33 -> V_16 |= ( T_1 ) V_29 ;
V_33 -> V_21 . V_25 = 0 ;
}
F_4 ( V_2 ) ;
V_32 = V_33 -> V_21 . V_22 ;
if ( V_31 != V_32 )
F_10 ( V_2 -> V_34 , V_35 , V_30 , V_32 ) ;
if ( V_33 -> V_21 . V_23 == V_24
&& V_2 -> V_36 & ( 1 << V_30 ) )
F_2 ( V_2 , V_30 ) ;
break;
}
}
static int F_3 ( struct V_1 * V_2 , int V_37 )
{
union V_18 * V_38 = & V_2 -> V_15 [ V_37 ] ;
struct V_39 V_40 ;
F_9 ( L_2
L_3 ,
V_38 -> V_21 . V_41 , V_38 -> V_21 . V_42 ,
V_38 -> V_21 . V_43 , V_38 -> V_21 . V_28 ,
V_38 -> V_21 . V_23 ) ;
V_40 . V_41 = V_38 -> V_21 . V_41 ;
V_40 . V_28 = V_38 -> V_21 . V_28 ;
V_40 . V_42 = V_38 -> V_21 . V_42 ;
V_40 . V_23 = V_38 -> V_21 . V_23 ;
V_40 . V_43 = V_38 -> V_21 . V_43 << 8 ;
V_40 . V_44 = 1 ;
V_40 . V_45 = 0 ;
#ifdef F_11
if ( V_37 == 0 ) {
V_40 . V_42 = 0 ;
V_40 . V_41 = V_2 -> V_34 -> V_46 ;
}
#endif
return F_12 ( V_2 -> V_34 , NULL , & V_40 ) ;
}
int F_13 ( struct V_1 * V_2 , int V_37 , int V_47 ,
int V_44 )
{
T_1 V_48 ;
T_1 V_22 = 1 << V_37 ;
union V_18 V_38 ;
int V_49 , V_50 ;
F_14 ( V_37 < 0 || V_37 >= V_8 ) ;
F_15 ( & V_2 -> V_51 ) ;
V_48 = V_2 -> V_36 ;
V_50 = F_16 ( & V_2 -> V_52 [ V_37 ] ,
V_47 , V_44 ) ;
V_38 = V_2 -> V_15 [ V_37 ] ;
V_50 ^= V_38 . V_21 . V_53 ;
if ( ! V_50 ) {
V_2 -> V_36 &= ~ V_22 ;
V_49 = 1 ;
} else {
int V_54 = ( V_38 . V_21 . V_23 == V_55 ) ;
V_2 -> V_36 |= V_22 ;
if ( ( V_54 && V_48 != V_2 -> V_36 ) ||
( ! V_54 && ! V_38 . V_21 . V_25 ) )
V_49 = F_2 ( V_2 , V_37 ) ;
else
V_49 = 0 ;
}
F_17 ( V_38 . V_16 , V_37 , V_49 == 0 ) ;
F_18 ( & V_2 -> V_51 ) ;
return V_49 ;
}
void F_19 ( struct V_1 * V_2 , int V_47 )
{
int V_27 ;
F_15 ( & V_2 -> V_51 ) ;
for ( V_27 = 0 ; V_27 < V_56 ; V_27 ++ )
F_20 ( V_47 , & V_2 -> V_52 [ V_27 ] ) ;
F_18 ( & V_2 -> V_51 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_28 ,
int V_57 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_8 ; V_27 ++ ) {
union V_18 * V_58 = & V_2 -> V_15 [ V_27 ] ;
if ( V_58 -> V_21 . V_28 != V_28 )
continue;
F_18 ( & V_2 -> V_51 ) ;
F_22 ( V_2 -> V_34 , V_35 , V_27 ) ;
F_15 ( & V_2 -> V_51 ) ;
if ( V_57 != V_24 )
continue;
ASSERT ( V_58 -> V_21 . V_23 == V_24 ) ;
V_58 -> V_21 . V_25 = 0 ;
if ( ! V_58 -> V_21 . V_22 && ( V_2 -> V_36 & ( 1 << V_27 ) ) )
F_2 ( V_2 , V_27 ) ;
}
}
bool F_23 ( struct V_34 * V_34 , int V_28 )
{
struct V_1 * V_2 = V_34 -> V_59 . V_60 ;
F_24 () ;
return F_25 ( V_28 , V_2 -> V_26 ) ;
}
void F_26 ( struct V_34 * V_34 , int V_28 , int V_57 )
{
struct V_1 * V_2 = V_34 -> V_59 . V_60 ;
F_15 ( & V_2 -> V_51 ) ;
F_21 ( V_2 , V_28 , V_57 ) ;
F_18 ( & V_2 -> V_51 ) ;
}
static inline struct V_1 * F_27 ( struct V_61 * V_62 )
{
return F_28 ( V_62 , struct V_1 , V_62 ) ;
}
static inline int F_29 ( struct V_1 * V_2 , T_3 V_3 )
{
return ( ( V_3 >= V_2 -> V_63 &&
( V_3 < V_2 -> V_63 + V_64 ) ) ) ;
}
static int F_30 ( struct V_61 * V_65 , T_3 V_3 , int V_66 ,
void * V_29 )
{
struct V_1 * V_2 = F_27 ( V_65 ) ;
T_1 V_5 ;
if ( ! F_29 ( V_2 , V_3 ) )
return - V_67 ;
F_9 ( L_4 , ( unsigned long ) V_3 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
V_3 &= 0xff ;
F_15 ( & V_2 -> V_51 ) ;
switch ( V_3 ) {
case V_68 :
V_5 = V_2 -> V_6 ;
break;
case V_69 :
V_5 = F_1 ( V_2 , V_3 , V_66 ) ;
break;
default:
V_5 = 0 ;
break;
}
F_18 ( & V_2 -> V_51 ) ;
switch ( V_66 ) {
case 8 :
* ( T_2 * ) V_29 = V_5 ;
break;
case 1 :
case 2 :
case 4 :
memcpy ( V_29 , ( char * ) & V_5 , V_66 ) ;
break;
default:
F_31 ( V_70 L_5 , V_66 ) ;
}
return 0 ;
}
static int F_32 ( struct V_61 * V_65 , T_3 V_3 , int V_66 ,
const void * V_29 )
{
struct V_1 * V_2 = F_27 ( V_65 ) ;
T_1 V_71 ;
if ( ! F_29 ( V_2 , V_3 ) )
return - V_67 ;
F_9 ( L_6 ,
( void * ) V_3 , V_66 , V_29 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
switch ( V_66 ) {
case 8 :
case 4 :
V_71 = * ( T_1 * ) V_29 ;
break;
case 2 :
V_71 = * ( V_72 * ) V_29 ;
break;
case 1 :
V_71 = * ( V_73 * ) V_29 ;
break;
default:
F_31 ( V_70 L_7 , V_66 ) ;
return 0 ;
}
V_3 &= 0xff ;
F_15 ( & V_2 -> V_51 ) ;
switch ( V_3 ) {
case V_68 :
V_2 -> V_6 = V_71 & 0xFF ;
break;
case V_69 :
F_8 ( V_2 , V_71 ) ;
break;
#ifdef F_33
case V_74 :
F_21 ( V_2 , V_71 , V_24 ) ;
break;
#endif
default:
break;
}
F_18 ( & V_2 -> V_51 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_8 ; V_27 ++ )
V_2 -> V_15 [ V_27 ] . V_21 . V_22 = 1 ;
V_2 -> V_63 = V_75 ;
V_2 -> V_6 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_12 = 0 ;
F_4 ( V_2 ) ;
}
int F_35 ( struct V_34 * V_34 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
F_37 ( & V_2 -> V_51 ) ;
V_34 -> V_59 . V_60 = V_2 ;
F_34 ( V_2 ) ;
F_38 ( & V_2 -> V_62 , & V_78 ) ;
V_2 -> V_34 = V_34 ;
F_39 ( & V_34 -> V_79 ) ;
V_49 = F_40 ( V_34 , V_80 , V_2 -> V_63 ,
V_64 , & V_2 -> V_62 ) ;
F_41 ( & V_34 -> V_79 ) ;
if ( V_49 < 0 ) {
V_34 -> V_59 . V_60 = NULL ;
F_42 ( V_2 ) ;
}
return V_49 ;
}
void F_43 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_59 . V_60 ;
if ( V_2 ) {
F_44 ( V_34 , V_80 , & V_2 -> V_62 ) ;
V_34 -> V_59 . V_60 = NULL ;
F_42 ( V_2 ) ;
}
}
int F_45 ( struct V_34 * V_34 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_46 ( V_34 ) ;
if ( ! V_2 )
return - V_83 ;
F_15 ( & V_2 -> V_51 ) ;
memcpy ( V_82 , V_2 , sizeof( struct V_81 ) ) ;
F_18 ( & V_2 -> V_51 ) ;
return 0 ;
}
int F_47 ( struct V_34 * V_34 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_46 ( V_34 ) ;
if ( ! V_2 )
return - V_83 ;
F_15 ( & V_2 -> V_51 ) ;
memcpy ( V_2 , V_82 , sizeof( struct V_81 ) ) ;
F_4 ( V_2 ) ;
F_18 ( & V_2 -> V_51 ) ;
return 0 ;
}
