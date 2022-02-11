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
if ( V_13 < V_8 )
V_14 =
V_2 -> V_15 [ V_13 ] . V_16 ;
else
V_14 = ~ 0ULL ;
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
void F_8 ( struct V_29 * V_30 ,
T_2 * V_31 )
{
struct V_1 * V_2 = V_30 -> V_32 -> V_33 . V_34 ;
union V_18 * V_35 ;
struct V_36 V_37 ;
int V_38 ;
F_9 ( & V_2 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_8 ; V_38 ++ ) {
V_35 = & V_2 -> V_15 [ V_38 ] ;
if ( ! V_35 -> V_21 . V_22 &&
( V_35 -> V_21 . V_23 == V_24 ||
F_10 ( V_2 -> V_32 , V_40 ,
V_38 ) ) ) {
V_37 . V_41 = V_35 -> V_21 . V_41 ;
V_37 . V_28 = V_35 -> V_21 . V_28 ;
V_37 . V_42 = V_35 -> V_21 . V_42 ;
V_37 . V_43 = V_35 -> V_21 . V_43 << 8 ;
F_11 ( V_30 , & V_37 , V_31 ) ;
}
}
F_12 ( & V_2 -> V_39 ) ;
}
void F_13 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 . V_34 ;
if ( ! F_14 ( V_32 ) || ! V_2 )
return;
F_15 ( V_32 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_44 )
{
unsigned V_38 ;
bool V_45 , V_46 ;
union V_18 * V_35 ;
switch ( V_2 -> V_6 ) {
case V_7 :
break;
case V_10 :
V_2 -> V_12 = ( V_44 >> 24 ) & 0xf ;
break;
case V_11 :
break;
default:
V_38 = ( V_2 -> V_6 - 0x10 ) >> 1 ;
F_17 ( L_1 , V_38 , V_44 ) ;
if ( V_38 >= V_8 )
return;
V_35 = & V_2 -> V_15 [ V_38 ] ;
V_45 = V_35 -> V_21 . V_22 ;
if ( V_2 -> V_6 & 1 ) {
V_35 -> V_16 &= 0xffffffff ;
V_35 -> V_16 |= ( T_2 ) V_44 << 32 ;
} else {
V_35 -> V_16 &= ~ 0xffffffffULL ;
V_35 -> V_16 |= ( T_1 ) V_44 ;
V_35 -> V_21 . V_25 = 0 ;
}
F_4 ( V_2 ) ;
V_46 = V_35 -> V_21 . V_22 ;
if ( V_45 != V_46 )
F_18 ( V_2 -> V_32 , V_40 , V_38 , V_46 ) ;
if ( V_35 -> V_21 . V_23 == V_24
&& V_2 -> V_47 & ( 1 << V_38 ) )
F_2 ( V_2 , V_38 ) ;
F_13 ( V_2 -> V_32 ) ;
break;
}
}
static int F_3 ( struct V_1 * V_2 , int V_48 )
{
union V_18 * V_49 = & V_2 -> V_15 [ V_48 ] ;
struct V_36 V_37 ;
F_17 ( L_2
L_3 ,
V_49 -> V_21 . V_41 , V_49 -> V_21 . V_42 ,
V_49 -> V_21 . V_43 , V_49 -> V_21 . V_28 ,
V_49 -> V_21 . V_23 ) ;
V_37 . V_41 = V_49 -> V_21 . V_41 ;
V_37 . V_28 = V_49 -> V_21 . V_28 ;
V_37 . V_42 = V_49 -> V_21 . V_42 ;
V_37 . V_23 = V_49 -> V_21 . V_23 ;
V_37 . V_43 = V_49 -> V_21 . V_43 << 8 ;
V_37 . V_50 = 1 ;
V_37 . V_51 = 0 ;
return F_19 ( V_2 -> V_32 , NULL , & V_37 ) ;
}
int F_20 ( struct V_1 * V_2 , int V_48 , int V_52 ,
int V_50 )
{
T_1 V_53 ;
T_1 V_22 = 1 << V_48 ;
union V_18 V_49 ;
int V_54 , V_55 ;
F_21 ( V_48 < 0 || V_48 >= V_8 ) ;
F_9 ( & V_2 -> V_39 ) ;
V_53 = V_2 -> V_47 ;
V_55 = F_22 ( & V_2 -> V_56 [ V_48 ] ,
V_52 , V_50 ) ;
V_49 = V_2 -> V_15 [ V_48 ] ;
V_55 ^= V_49 . V_21 . V_57 ;
if ( ! V_55 ) {
V_2 -> V_47 &= ~ V_22 ;
V_54 = 1 ;
} else {
int V_58 = ( V_49 . V_21 . V_23 == V_59 ) ;
V_2 -> V_47 |= V_22 ;
if ( ( V_58 && V_53 != V_2 -> V_47 ) ||
( ! V_58 && ! V_49 . V_21 . V_25 ) )
V_54 = F_2 ( V_2 , V_48 ) ;
else
V_54 = 0 ;
}
F_23 ( V_49 . V_16 , V_48 , V_54 == 0 ) ;
F_12 ( & V_2 -> V_39 ) ;
return V_54 ;
}
void F_24 ( struct V_1 * V_2 , int V_52 )
{
int V_27 ;
F_9 ( & V_2 -> V_39 ) ;
for ( V_27 = 0 ; V_27 < V_60 ; V_27 ++ )
F_25 ( V_52 , & V_2 -> V_56 [ V_27 ] ) ;
F_12 ( & V_2 -> V_39 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_28 ,
int V_61 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_8 ; V_27 ++ ) {
union V_18 * V_62 = & V_2 -> V_15 [ V_27 ] ;
if ( V_62 -> V_21 . V_28 != V_28 )
continue;
F_12 ( & V_2 -> V_39 ) ;
F_27 ( V_2 -> V_32 , V_40 , V_27 ) ;
F_9 ( & V_2 -> V_39 ) ;
if ( V_61 != V_24 )
continue;
ASSERT ( V_62 -> V_21 . V_23 == V_24 ) ;
V_62 -> V_21 . V_25 = 0 ;
if ( ! V_62 -> V_21 . V_22 && ( V_2 -> V_47 & ( 1 << V_27 ) ) )
F_2 ( V_2 , V_27 ) ;
}
}
bool F_28 ( struct V_32 * V_32 , int V_28 )
{
struct V_1 * V_2 = V_32 -> V_33 . V_34 ;
F_29 () ;
return F_30 ( V_28 , V_2 -> V_26 ) ;
}
void F_31 ( struct V_32 * V_32 , int V_28 , int V_61 )
{
struct V_1 * V_2 = V_32 -> V_33 . V_34 ;
F_9 ( & V_2 -> V_39 ) ;
F_26 ( V_2 , V_28 , V_61 ) ;
F_12 ( & V_2 -> V_39 ) ;
}
static inline struct V_1 * F_32 ( struct V_63 * V_64 )
{
return F_33 ( V_64 , struct V_1 , V_64 ) ;
}
static inline int F_34 ( struct V_1 * V_2 , T_3 V_3 )
{
return ( ( V_3 >= V_2 -> V_65 &&
( V_3 < V_2 -> V_65 + V_66 ) ) ) ;
}
static int F_35 ( struct V_63 * V_67 , T_3 V_3 , int V_68 ,
void * V_44 )
{
struct V_1 * V_2 = F_32 ( V_67 ) ;
T_1 V_5 ;
if ( ! F_34 ( V_2 , V_3 ) )
return - V_69 ;
F_17 ( L_4 , ( unsigned long ) V_3 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
V_3 &= 0xff ;
F_9 ( & V_2 -> V_39 ) ;
switch ( V_3 ) {
case V_70 :
V_5 = V_2 -> V_6 ;
break;
case V_71 :
V_5 = F_1 ( V_2 , V_3 , V_68 ) ;
break;
default:
V_5 = 0 ;
break;
}
F_12 ( & V_2 -> V_39 ) ;
switch ( V_68 ) {
case 8 :
* ( T_2 * ) V_44 = V_5 ;
break;
case 1 :
case 2 :
case 4 :
memcpy ( V_44 , ( char * ) & V_5 , V_68 ) ;
break;
default:
F_36 ( V_72 L_5 , V_68 ) ;
}
return 0 ;
}
static int F_37 ( struct V_63 * V_67 , T_3 V_3 , int V_68 ,
const void * V_44 )
{
struct V_1 * V_2 = F_32 ( V_67 ) ;
T_1 V_73 ;
if ( ! F_34 ( V_2 , V_3 ) )
return - V_69 ;
F_17 ( L_6 ,
( void * ) V_3 , V_68 , V_44 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
switch ( V_68 ) {
case 8 :
case 4 :
V_73 = * ( T_1 * ) V_44 ;
break;
case 2 :
V_73 = * ( V_74 * ) V_44 ;
break;
case 1 :
V_73 = * ( V_75 * ) V_44 ;
break;
default:
F_36 ( V_72 L_7 , V_68 ) ;
return 0 ;
}
V_3 &= 0xff ;
F_9 ( & V_2 -> V_39 ) ;
switch ( V_3 ) {
case V_70 :
V_2 -> V_6 = V_73 & 0xFF ;
break;
case V_71 :
F_16 ( V_2 , V_73 ) ;
break;
#ifdef F_38
case V_76 :
F_26 ( V_2 , V_73 , V_24 ) ;
break;
#endif
default:
break;
}
F_12 ( & V_2 -> V_39 ) ;
return 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_8 ; V_27 ++ )
V_2 -> V_15 [ V_27 ] . V_21 . V_22 = 1 ;
V_2 -> V_65 = V_77 ;
V_2 -> V_6 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_12 = 0 ;
F_4 ( V_2 ) ;
}
int F_40 ( struct V_32 * V_32 )
{
struct V_1 * V_2 ;
int V_54 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
F_42 ( & V_2 -> V_39 ) ;
V_32 -> V_33 . V_34 = V_2 ;
F_39 ( V_2 ) ;
F_43 ( & V_2 -> V_64 , & V_80 ) ;
V_2 -> V_32 = V_32 ;
F_44 ( & V_32 -> V_81 ) ;
V_54 = F_45 ( V_32 , V_82 , V_2 -> V_65 ,
V_66 , & V_2 -> V_64 ) ;
F_46 ( & V_32 -> V_81 ) ;
if ( V_54 < 0 ) {
V_32 -> V_33 . V_34 = NULL ;
F_47 ( V_2 ) ;
}
return V_54 ;
}
void F_48 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 . V_34 ;
if ( V_2 ) {
F_49 ( V_32 , V_82 , & V_2 -> V_64 ) ;
V_32 -> V_33 . V_34 = NULL ;
F_47 ( V_2 ) ;
}
}
int F_50 ( struct V_32 * V_32 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_51 ( V_32 ) ;
if ( ! V_2 )
return - V_85 ;
F_9 ( & V_2 -> V_39 ) ;
memcpy ( V_84 , V_2 , sizeof( struct V_83 ) ) ;
F_12 ( & V_2 -> V_39 ) ;
return 0 ;
}
int F_52 ( struct V_32 * V_32 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_51 ( V_32 ) ;
if ( ! V_2 )
return - V_85 ;
F_9 ( & V_2 -> V_39 ) ;
memcpy ( V_2 , V_84 , sizeof( struct V_83 ) ) ;
F_4 ( V_2 ) ;
F_13 ( V_32 ) ;
F_12 ( & V_2 -> V_39 ) ;
return 0 ;
}
