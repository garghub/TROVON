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
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_18 = 0 ;
F_3 ( V_2 -> V_17 . V_19 , V_20 ) ;
}
static void F_4 ( struct V_21 * V_22 )
{
bool V_23 , V_24 ;
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
union V_28 * V_29 ;
V_29 = & V_2 -> V_15 [ V_30 ] ;
if ( ! F_5 ( V_22 , NULL , 0 , V_29 -> V_31 . V_32 ,
V_29 -> V_31 . V_33 ) )
return;
V_23 = F_6 ( V_22 , V_29 -> V_31 . V_34 ) ;
V_24 = F_7 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
if ( V_23 == V_24 )
return;
if ( V_23 ) {
F_8 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 ++ ;
} else {
F_9 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 -- ;
}
F_10 ( V_2 -> V_17 . V_18 < 0 ) ;
}
void F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
F_12 ( & V_2 -> V_36 ) ;
F_4 ( V_22 ) ;
F_13 ( & V_2 -> V_36 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_37 ;
if ( V_30 >= V_8 )
return;
F_2 ( V_2 ) ;
F_15 (i, vcpu, ioapic->kvm)
F_4 ( V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( F_17 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) )
-- V_2 -> V_17 . V_18 ;
F_10 ( V_2 -> V_17 . V_18 < 0 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 . V_18 > 0 )
return true ;
return false ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_38 ,
bool V_39 )
{
union V_28 * V_40 ;
int V_41 = - 1 ;
V_40 = & V_2 -> V_15 [ V_38 ] ;
if ( ! V_40 -> V_31 . V_42 ) {
V_41 = F_20 ( V_2 , V_38 , V_39 ) ;
if ( V_41 && V_40 -> V_31 . V_43 == V_44 )
V_40 -> V_31 . V_45 = 1 ;
}
return V_41 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_46 , 256 ) ;
int V_37 ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
for ( V_37 = 0 ; V_37 < V_8 ; ++ V_37 )
F_8 ( V_2 -> V_15 [ V_37 ] . V_31 . V_34 , V_46 ) ;
memcpy ( V_2 -> V_46 , V_46 ,
sizeof( V_46 ) ) ;
F_23 () ;
}
void F_24 ( struct V_21 * V_22 , T_2 * V_47 ,
T_1 * V_48 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
union V_28 * V_29 ;
int V_49 ;
F_12 ( & V_2 -> V_36 ) ;
for ( V_49 = 0 ; V_49 < V_8 ; V_49 ++ ) {
V_29 = & V_2 -> V_15 [ V_49 ] ;
if ( ! V_29 -> V_31 . V_42 &&
( V_29 -> V_31 . V_43 == V_44 ||
F_25 ( V_2 -> V_25 , V_50 ,
V_49 ) || V_49 == V_30 ) ) {
if ( F_5 ( V_22 , NULL , 0 ,
V_29 -> V_31 . V_32 , V_29 -> V_31 . V_33 ) ) {
F_8 ( V_29 -> V_31 . V_34 ,
( unsigned long * ) V_47 ) ;
if ( V_29 -> V_31 . V_43 == V_44 )
F_8 ( V_29 -> V_31 . V_34 ,
( unsigned long * ) V_48 ) ;
}
}
}
F_13 ( & V_2 -> V_36 ) ;
}
void F_26 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
if ( ! V_2 )
return;
F_27 ( V_25 ) ;
}
void F_26 ( struct V_25 * V_25 )
{
return;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_51 )
{
unsigned V_49 ;
bool V_52 , V_53 ;
union V_28 * V_29 ;
switch ( V_2 -> V_6 ) {
case V_7 :
break;
case V_10 :
V_2 -> V_12 = ( V_51 >> 24 ) & 0xf ;
break;
case V_11 :
break;
default:
V_49 = ( V_2 -> V_6 - 0x10 ) >> 1 ;
F_29 ( L_1 , V_49 , V_51 ) ;
if ( V_49 >= V_8 )
return;
V_29 = & V_2 -> V_15 [ V_49 ] ;
V_52 = V_29 -> V_31 . V_42 ;
if ( V_2 -> V_6 & 1 ) {
V_29 -> V_16 &= 0xffffffff ;
V_29 -> V_16 |= ( T_2 ) V_51 << 32 ;
} else {
V_29 -> V_16 &= ~ 0xffffffffULL ;
V_29 -> V_16 |= ( T_1 ) V_51 ;
V_29 -> V_31 . V_45 = 0 ;
}
F_21 ( V_2 ) ;
V_53 = V_29 -> V_31 . V_42 ;
if ( V_52 != V_53 )
F_30 ( V_2 -> V_25 , V_50 , V_49 , V_53 ) ;
if ( V_29 -> V_31 . V_43 == V_44
&& V_2 -> V_54 & ( 1 << V_49 ) )
F_19 ( V_2 , V_49 , false ) ;
F_26 ( V_2 -> V_25 ) ;
break;
}
}
static int F_20 ( struct V_1 * V_2 , int V_55 , bool V_39 )
{
union V_28 * V_56 = & V_2 -> V_15 [ V_55 ] ;
struct V_57 V_58 ;
int V_59 ;
F_29 ( L_2
L_3 ,
V_56 -> V_31 . V_32 , V_56 -> V_31 . V_33 ,
V_56 -> V_31 . V_60 , V_56 -> V_31 . V_34 ,
V_56 -> V_31 . V_43 ) ;
V_58 . V_32 = V_56 -> V_31 . V_32 ;
V_58 . V_34 = V_56 -> V_31 . V_34 ;
V_58 . V_33 = V_56 -> V_31 . V_33 ;
V_58 . V_43 = V_56 -> V_31 . V_43 ;
V_58 . V_60 = V_56 -> V_31 . V_60 << 8 ;
V_58 . V_61 = 1 ;
V_58 . V_62 = 0 ;
if ( V_55 == V_30 && V_39 ) {
F_31 ( V_2 -> V_17 . V_18 != 0 ) ;
V_59 = F_32 ( V_2 -> V_25 , NULL , & V_58 ,
V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 = V_59 ;
} else
V_59 = F_32 ( V_2 -> V_25 , NULL , & V_58 , NULL ) ;
return V_59 ;
}
int F_33 ( struct V_1 * V_2 , int V_55 , int V_63 ,
int V_61 , bool V_39 )
{
T_1 V_64 ;
T_1 V_42 = 1 << V_55 ;
union V_28 V_56 ;
int V_59 , V_65 ;
F_31 ( V_55 < 0 || V_55 >= V_8 ) ;
F_12 ( & V_2 -> V_36 ) ;
V_64 = V_2 -> V_54 ;
V_65 = F_34 ( & V_2 -> V_66 [ V_55 ] ,
V_63 , V_61 ) ;
V_56 = V_2 -> V_15 [ V_55 ] ;
V_65 ^= V_56 . V_31 . V_67 ;
if ( ! V_65 ) {
V_2 -> V_54 &= ~ V_42 ;
V_59 = 1 ;
} else {
int V_68 = ( V_56 . V_31 . V_43 == V_69 ) ;
if ( V_55 == V_30 && V_39 &&
F_18 ( V_2 ) ) {
V_59 = 0 ;
goto V_70;
}
V_2 -> V_54 |= V_42 ;
if ( ( V_68 && V_64 != V_2 -> V_54 ) ||
( ! V_68 && ! V_56 . V_31 . V_45 ) )
V_59 = F_19 ( V_2 , V_55 , V_39 ) ;
else
V_59 = 0 ;
}
V_70:
F_35 ( V_56 . V_16 , V_55 , V_59 == 0 ) ;
F_13 ( & V_2 -> V_36 ) ;
return V_59 ;
}
void F_36 ( struct V_1 * V_2 , int V_63 )
{
int V_37 ;
F_12 ( & V_2 -> V_36 ) ;
for ( V_37 = 0 ; V_37 < V_71 ; V_37 ++ )
F_9 ( V_63 , & V_2 -> V_66 [ V_37 ] ) ;
F_13 ( & V_2 -> V_36 ) ;
}
static void F_37 ( struct V_21 * V_22 ,
struct V_1 * V_2 , int V_34 , int V_72 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_8 ; V_37 ++ ) {
union V_28 * V_73 = & V_2 -> V_15 [ V_37 ] ;
if ( V_73 -> V_31 . V_34 != V_34 )
continue;
if ( V_37 == V_30 )
F_16 ( V_2 , V_22 ) ;
F_13 ( & V_2 -> V_36 ) ;
F_38 ( V_2 -> V_25 , V_50 , V_37 ) ;
F_12 ( & V_2 -> V_36 ) ;
if ( V_72 != V_44 )
continue;
ASSERT ( V_73 -> V_31 . V_43 == V_44 ) ;
V_73 -> V_31 . V_45 = 0 ;
if ( ! V_73 -> V_31 . V_42 && ( V_2 -> V_54 & ( 1 << V_37 ) ) )
F_19 ( V_2 , V_37 , false ) ;
}
}
bool F_39 ( struct V_25 * V_25 , int V_34 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
F_40 () ;
return F_7 ( V_34 , V_2 -> V_46 ) ;
}
void F_41 ( struct V_21 * V_22 , int V_34 , int V_72 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
F_12 ( & V_2 -> V_36 ) ;
F_37 ( V_22 , V_2 , V_34 , V_72 ) ;
F_13 ( & V_2 -> V_36 ) ;
}
static inline struct V_1 * F_42 ( struct V_74 * V_75 )
{
return F_43 ( V_75 , struct V_1 , V_75 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , T_3 V_3 )
{
return ( ( V_3 >= V_2 -> V_76 &&
( V_3 < V_2 -> V_76 + V_77 ) ) ) ;
}
static int F_45 ( struct V_74 * V_78 , T_3 V_3 , int V_79 ,
void * V_51 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
T_1 V_5 ;
if ( ! F_44 ( V_2 , V_3 ) )
return - V_80 ;
F_29 ( L_4 , ( unsigned long ) V_3 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
V_3 &= 0xff ;
F_12 ( & V_2 -> V_36 ) ;
switch ( V_3 ) {
case V_81 :
V_5 = V_2 -> V_6 ;
break;
case V_82 :
V_5 = F_1 ( V_2 , V_3 , V_79 ) ;
break;
default:
V_5 = 0 ;
break;
}
F_13 ( & V_2 -> V_36 ) ;
switch ( V_79 ) {
case 8 :
* ( T_2 * ) V_51 = V_5 ;
break;
case 1 :
case 2 :
case 4 :
memcpy ( V_51 , ( char * ) & V_5 , V_79 ) ;
break;
default:
F_46 ( V_83 L_5 , V_79 ) ;
}
return 0 ;
}
static int F_47 ( struct V_74 * V_78 , T_3 V_3 , int V_79 ,
const void * V_51 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
T_1 V_84 ;
if ( ! F_44 ( V_2 , V_3 ) )
return - V_80 ;
F_29 ( L_6 ,
( void * ) V_3 , V_79 , V_51 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
switch ( V_79 ) {
case 8 :
case 4 :
V_84 = * ( T_1 * ) V_51 ;
break;
case 2 :
V_84 = * ( V_85 * ) V_51 ;
break;
case 1 :
V_84 = * ( V_86 * ) V_51 ;
break;
default:
F_46 ( V_83 L_7 , V_79 ) ;
return 0 ;
}
V_3 &= 0xff ;
F_12 ( & V_2 -> V_36 ) ;
switch ( V_3 ) {
case V_81 :
V_2 -> V_6 = V_84 & 0xFF ;
break;
case V_82 :
F_28 ( V_2 , V_84 ) ;
break;
#ifdef F_48
case V_87 :
F_37 ( NULL , V_2 , V_84 , V_44 ) ;
break;
#endif
default:
break;
}
F_13 ( & V_2 -> V_36 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_8 ; V_37 ++ )
V_2 -> V_15 [ V_37 ] . V_31 . V_42 = 1 ;
V_2 -> V_76 = V_88 ;
V_2 -> V_6 = 0 ;
V_2 -> V_54 = 0 ;
V_2 -> V_12 = 0 ;
F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
}
int F_50 ( struct V_25 * V_25 )
{
struct V_1 * V_2 ;
int V_59 ;
V_2 = F_51 ( sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
F_52 ( & V_2 -> V_36 ) ;
V_25 -> V_26 . V_27 = V_2 ;
F_49 ( V_2 ) ;
F_53 ( & V_2 -> V_75 , & V_91 ) ;
V_2 -> V_25 = V_25 ;
F_54 ( & V_25 -> V_92 ) ;
V_59 = F_55 ( V_25 , V_93 , V_2 -> V_76 ,
V_77 , & V_2 -> V_75 ) ;
F_56 ( & V_25 -> V_92 ) ;
if ( V_59 < 0 ) {
V_25 -> V_26 . V_27 = NULL ;
F_57 ( V_2 ) ;
}
return V_59 ;
}
void F_58 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
if ( V_2 ) {
F_59 ( V_25 , V_93 , & V_2 -> V_75 ) ;
V_25 -> V_26 . V_27 = NULL ;
F_57 ( V_2 ) ;
}
}
int F_60 ( struct V_25 * V_25 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_61 ( V_25 ) ;
if ( ! V_2 )
return - V_96 ;
F_12 ( & V_2 -> V_36 ) ;
memcpy ( V_95 , V_2 , sizeof( struct V_94 ) ) ;
F_13 ( & V_2 -> V_36 ) ;
return 0 ;
}
int F_62 ( struct V_25 * V_25 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_61 ( V_25 ) ;
if ( ! V_2 )
return - V_96 ;
F_12 ( & V_2 -> V_36 ) ;
memcpy ( V_2 , V_95 , sizeof( struct V_94 ) ) ;
F_21 ( V_2 ) ;
F_26 ( V_25 ) ;
F_14 ( V_2 ) ;
F_13 ( & V_2 -> V_36 ) ;
return 0 ;
}
