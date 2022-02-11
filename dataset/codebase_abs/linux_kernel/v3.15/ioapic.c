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
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 -> V_17 . V_18 < 0 ) )
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_21 * V_22 )
{
bool V_23 , V_24 ;
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
union V_28 * V_29 ;
V_29 = & V_2 -> V_15 [ V_30 ] ;
if ( ! F_8 ( V_22 , NULL , 0 , V_29 -> V_31 . V_32 ,
V_29 -> V_31 . V_33 ) )
return;
V_23 = F_9 ( V_22 , V_29 -> V_31 . V_34 ) ;
V_24 = F_10 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
if ( V_23 == V_24 )
return;
if ( V_23 ) {
F_11 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 ++ ;
} else {
F_12 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 -- ;
F_4 ( V_2 ) ;
}
}
void F_13 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
F_14 ( & V_2 -> V_36 ) ;
F_7 ( V_22 ) ;
F_15 ( & V_2 -> V_36 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_37 ;
if ( V_30 >= V_8 )
return;
F_2 ( V_2 ) ;
F_16 (i, vcpu, ioapic->kvm)
F_7 ( V_22 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( F_18 ( V_22 -> V_35 , V_2 -> V_17 . V_19 ) ) {
-- V_2 -> V_17 . V_18 ;
F_4 ( V_2 ) ;
}
}
static bool F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 . V_18 > 0 )
return true ;
return false ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_38 ,
int V_39 , bool V_40 )
{
union V_28 V_41 ;
T_1 V_42 = 1 << V_38 ;
T_1 V_43 ;
int V_44 , V_45 ;
V_41 = V_2 -> V_15 [ V_38 ] ;
V_44 = ( V_41 . V_31 . V_46 == V_47 ) ;
if ( ! V_39 ) {
V_2 -> V_48 &= ~ V_42 ;
V_45 = 1 ;
goto V_49;
}
if ( V_38 == V_30 && V_40 &&
F_19 ( V_2 ) ) {
V_45 = 0 ;
goto V_49;
}
V_43 = V_2 -> V_48 ;
V_2 -> V_48 |= V_42 ;
if ( ( V_44 && V_43 == V_2 -> V_48 ) ||
( ! V_44 && V_41 . V_31 . V_50 ) ) {
V_45 = 0 ;
goto V_49;
}
V_45 = F_21 ( V_2 , V_38 , V_40 ) ;
V_49:
F_22 ( V_41 . V_16 , V_38 , V_45 == 0 ) ;
return V_45 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned long V_48 )
{
T_1 V_51 ;
F_2 ( V_2 ) ;
F_24 (idx, &irr, IOAPIC_NUM_PINS)
F_20 ( V_2 , V_51 , 1 , true ) ;
F_6 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_52 , 256 ) ;
int V_37 ;
memset ( V_52 , 0 , sizeof( V_52 ) ) ;
for ( V_37 = 0 ; V_37 < V_8 ; ++ V_37 )
F_11 ( V_2 -> V_15 [ V_37 ] . V_31 . V_34 , V_52 ) ;
memcpy ( V_2 -> V_52 , V_52 ,
sizeof( V_52 ) ) ;
F_27 () ;
}
void F_28 ( struct V_21 * V_22 , T_2 * V_53 ,
T_1 * V_54 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
union V_28 * V_29 ;
int V_55 ;
F_14 ( & V_2 -> V_36 ) ;
for ( V_55 = 0 ; V_55 < V_8 ; V_55 ++ ) {
V_29 = & V_2 -> V_15 [ V_55 ] ;
if ( ! V_29 -> V_31 . V_42 &&
( V_29 -> V_31 . V_46 == V_56 ||
F_29 ( V_2 -> V_25 , V_57 ,
V_55 ) || V_55 == V_30 ) ) {
if ( F_8 ( V_22 , NULL , 0 ,
V_29 -> V_31 . V_32 , V_29 -> V_31 . V_33 ) ) {
F_11 ( V_29 -> V_31 . V_34 ,
( unsigned long * ) V_53 ) ;
if ( V_29 -> V_31 . V_46 == V_56 )
F_11 ( V_29 -> V_31 . V_34 ,
( unsigned long * ) V_54 ) ;
}
}
}
F_15 ( & V_2 -> V_36 ) ;
}
void F_30 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
if ( ! V_2 )
return;
F_31 ( V_25 ) ;
}
void F_30 ( struct V_25 * V_25 )
{
return;
}
static void F_32 ( struct V_1 * V_2 , T_1 V_58 )
{
unsigned V_55 ;
bool V_59 , V_60 ;
union V_28 * V_29 ;
switch ( V_2 -> V_6 ) {
case V_7 :
break;
case V_10 :
V_2 -> V_12 = ( V_58 >> 24 ) & 0xf ;
break;
case V_11 :
break;
default:
V_55 = ( V_2 -> V_6 - 0x10 ) >> 1 ;
F_33 ( L_1 , V_55 , V_58 ) ;
if ( V_55 >= V_8 )
return;
V_29 = & V_2 -> V_15 [ V_55 ] ;
V_59 = V_29 -> V_31 . V_42 ;
if ( V_2 -> V_6 & 1 ) {
V_29 -> V_16 &= 0xffffffff ;
V_29 -> V_16 |= ( T_2 ) V_58 << 32 ;
} else {
V_29 -> V_16 &= ~ 0xffffffffULL ;
V_29 -> V_16 |= ( T_1 ) V_58 ;
V_29 -> V_31 . V_50 = 0 ;
}
F_25 ( V_2 ) ;
V_60 = V_29 -> V_31 . V_42 ;
if ( V_59 != V_60 )
F_34 ( V_2 -> V_25 , V_57 , V_55 , V_60 ) ;
if ( V_29 -> V_31 . V_46 == V_56
&& V_2 -> V_48 & ( 1 << V_55 ) )
F_21 ( V_2 , V_55 , false ) ;
F_30 ( V_2 -> V_25 ) ;
break;
}
}
static int F_21 ( struct V_1 * V_2 , int V_38 , bool V_40 )
{
union V_28 * V_41 = & V_2 -> V_15 [ V_38 ] ;
struct V_61 V_62 ;
int V_45 ;
if ( V_41 -> V_31 . V_42 )
return - 1 ;
F_33 ( L_2
L_3 ,
V_41 -> V_31 . V_32 , V_41 -> V_31 . V_33 ,
V_41 -> V_31 . V_63 , V_41 -> V_31 . V_34 ,
V_41 -> V_31 . V_46 ) ;
V_62 . V_32 = V_41 -> V_31 . V_32 ;
V_62 . V_34 = V_41 -> V_31 . V_34 ;
V_62 . V_33 = V_41 -> V_31 . V_33 ;
V_62 . V_46 = V_41 -> V_31 . V_46 ;
V_62 . V_63 = V_41 -> V_31 . V_63 << 8 ;
V_62 . V_64 = 1 ;
V_62 . V_65 = 0 ;
if ( V_62 . V_46 == V_47 )
V_2 -> V_48 &= ~ ( 1 << V_38 ) ;
if ( V_38 == V_30 && V_40 ) {
F_35 ( V_2 -> V_17 . V_18 != 0 ) ;
V_45 = F_36 ( V_2 -> V_25 , NULL , & V_62 ,
V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_18 = ( V_45 < 0 ? 0 : V_45 ) ;
} else
V_45 = F_36 ( V_2 -> V_25 , NULL , & V_62 , NULL ) ;
if ( V_45 && V_62 . V_46 == V_56 )
V_41 -> V_31 . V_50 = 1 ;
return V_45 ;
}
int F_37 ( struct V_1 * V_2 , int V_38 , int V_66 ,
int V_64 , bool V_40 )
{
int V_45 , V_39 ;
F_35 ( V_38 < 0 || V_38 >= V_8 ) ;
F_14 ( & V_2 -> V_36 ) ;
V_39 = F_38 ( & V_2 -> V_67 [ V_38 ] ,
V_66 , V_64 ) ;
V_45 = F_20 ( V_2 , V_38 , V_39 , V_40 ) ;
F_15 ( & V_2 -> V_36 ) ;
return V_45 ;
}
void F_39 ( struct V_1 * V_2 , int V_66 )
{
int V_37 ;
F_14 ( & V_2 -> V_36 ) ;
for ( V_37 = 0 ; V_37 < V_68 ; V_37 ++ )
F_12 ( V_66 , & V_2 -> V_67 [ V_37 ] ) ;
F_15 ( & V_2 -> V_36 ) ;
}
static void F_40 ( struct V_21 * V_22 ,
struct V_1 * V_2 , int V_34 , int V_69 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_8 ; V_37 ++ ) {
union V_28 * V_70 = & V_2 -> V_15 [ V_37 ] ;
if ( V_70 -> V_31 . V_34 != V_34 )
continue;
if ( V_37 == V_30 )
F_17 ( V_2 , V_22 ) ;
F_15 ( & V_2 -> V_36 ) ;
F_41 ( V_2 -> V_25 , V_57 , V_37 ) ;
F_14 ( & V_2 -> V_36 ) ;
if ( V_69 != V_56 )
continue;
ASSERT ( V_70 -> V_31 . V_46 == V_56 ) ;
V_70 -> V_31 . V_50 = 0 ;
if ( V_2 -> V_48 & ( 1 << V_37 ) )
F_21 ( V_2 , V_37 , false ) ;
}
}
bool F_42 ( struct V_25 * V_25 , int V_34 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
F_43 () ;
return F_10 ( V_34 , V_2 -> V_52 ) ;
}
void F_44 ( struct V_21 * V_22 , int V_34 , int V_69 )
{
struct V_1 * V_2 = V_22 -> V_25 -> V_26 . V_27 ;
F_14 ( & V_2 -> V_36 ) ;
F_40 ( V_22 , V_2 , V_34 , V_69 ) ;
F_15 ( & V_2 -> V_36 ) ;
}
static inline struct V_1 * F_45 ( struct V_71 * V_72 )
{
return F_46 ( V_72 , struct V_1 , V_72 ) ;
}
static inline int F_47 ( struct V_1 * V_2 , T_3 V_3 )
{
return ( ( V_3 >= V_2 -> V_73 &&
( V_3 < V_2 -> V_73 + V_74 ) ) ) ;
}
static int F_48 ( struct V_71 * V_75 , T_3 V_3 , int V_76 ,
void * V_58 )
{
struct V_1 * V_2 = F_45 ( V_75 ) ;
T_1 V_5 ;
if ( ! F_47 ( V_2 , V_3 ) )
return - V_77 ;
F_33 ( L_4 , ( unsigned long ) V_3 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
V_3 &= 0xff ;
F_14 ( & V_2 -> V_36 ) ;
switch ( V_3 ) {
case V_78 :
V_5 = V_2 -> V_6 ;
break;
case V_79 :
V_5 = F_1 ( V_2 , V_3 , V_76 ) ;
break;
default:
V_5 = 0 ;
break;
}
F_15 ( & V_2 -> V_36 ) ;
switch ( V_76 ) {
case 8 :
* ( T_2 * ) V_58 = V_5 ;
break;
case 1 :
case 2 :
case 4 :
memcpy ( V_58 , ( char * ) & V_5 , V_76 ) ;
break;
default:
F_49 ( V_80 L_5 , V_76 ) ;
}
return 0 ;
}
static int F_50 ( struct V_71 * V_75 , T_3 V_3 , int V_76 ,
const void * V_58 )
{
struct V_1 * V_2 = F_45 ( V_75 ) ;
T_1 V_81 ;
if ( ! F_47 ( V_2 , V_3 ) )
return - V_77 ;
F_33 ( L_6 ,
( void * ) V_3 , V_76 , V_58 ) ;
ASSERT ( ! ( V_3 & 0xf ) ) ;
switch ( V_76 ) {
case 8 :
case 4 :
V_81 = * ( T_1 * ) V_58 ;
break;
case 2 :
V_81 = * ( V_82 * ) V_58 ;
break;
case 1 :
V_81 = * ( V_83 * ) V_58 ;
break;
default:
F_49 ( V_80 L_7 , V_76 ) ;
return 0 ;
}
V_3 &= 0xff ;
F_14 ( & V_2 -> V_36 ) ;
switch ( V_3 ) {
case V_78 :
V_2 -> V_6 = V_81 & 0xFF ;
break;
case V_79 :
F_32 ( V_2 , V_81 ) ;
break;
#ifdef F_51
case V_84 :
F_40 ( NULL , V_2 , V_81 , V_56 ) ;
break;
#endif
default:
break;
}
F_15 ( & V_2 -> V_36 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_8 ; V_37 ++ )
V_2 -> V_15 [ V_37 ] . V_31 . V_42 = 1 ;
V_2 -> V_73 = V_85 ;
V_2 -> V_6 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_12 = 0 ;
F_2 ( V_2 ) ;
F_25 ( V_2 ) ;
}
int F_53 ( struct V_25 * V_25 )
{
struct V_1 * V_2 ;
int V_45 ;
V_2 = F_54 ( sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 )
return - V_87 ;
F_55 ( & V_2 -> V_36 ) ;
V_25 -> V_26 . V_27 = V_2 ;
F_52 ( V_2 ) ;
F_56 ( & V_2 -> V_72 , & V_88 ) ;
V_2 -> V_25 = V_25 ;
F_57 ( & V_25 -> V_89 ) ;
V_45 = F_58 ( V_25 , V_90 , V_2 -> V_73 ,
V_74 , & V_2 -> V_72 ) ;
F_59 ( & V_25 -> V_89 ) ;
if ( V_45 < 0 ) {
V_25 -> V_26 . V_27 = NULL ;
F_60 ( V_2 ) ;
}
return V_45 ;
}
void F_61 ( struct V_25 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
if ( V_2 ) {
F_62 ( V_25 , V_90 , & V_2 -> V_72 ) ;
V_25 -> V_26 . V_27 = NULL ;
F_60 ( V_2 ) ;
}
}
int F_63 ( struct V_25 * V_25 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_64 ( V_25 ) ;
if ( ! V_2 )
return - V_93 ;
F_14 ( & V_2 -> V_36 ) ;
memcpy ( V_92 , V_2 , sizeof( struct V_91 ) ) ;
F_15 ( & V_2 -> V_36 ) ;
return 0 ;
}
int F_65 ( struct V_25 * V_25 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_64 ( V_25 ) ;
if ( ! V_2 )
return - V_93 ;
F_14 ( & V_2 -> V_36 ) ;
memcpy ( V_2 , V_92 , sizeof( struct V_91 ) ) ;
V_2 -> V_48 = 0 ;
F_25 ( V_2 ) ;
F_30 ( V_25 ) ;
F_23 ( V_2 , V_92 -> V_48 ) ;
F_15 ( & V_2 -> V_36 ) ;
return 0 ;
}
