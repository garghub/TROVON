static unsigned char F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
unsigned char V_7 = 0 ;
if ( V_4 -> V_8 == V_9 || ! V_4 -> V_10 ) {
F_2 ( L_1 ) ;
return 0 ;
}
if ( V_4 -> V_11 >= V_12 ) {
F_2 ( L_2 ) ;
return 0 ;
}
if ( ! V_4 -> V_13 ) {
F_2 ( L_3 ) ;
return 0 ;
}
if ( F_3 ( V_2 , V_4 -> V_14 ) ) {
struct V_15 * V_16 =
F_4 ( V_2 , V_4 -> V_14 ) -> V_4 ;
V_7 = V_16 -> V_17 [ V_4 -> V_11 ] ;
V_4 -> V_11 ++ ;
} else {
F_2 ( L_4 ) ;
}
return V_7 ;
}
static inline int F_5 ( T_1 V_18 )
{
int V_19 = V_18 & V_20 ;
int V_14 = - V_21 ;
if ( V_19 == 2 )
V_14 = V_22 ;
else if ( V_19 == 4 )
V_14 = V_23 ;
else if ( V_19 == 5 )
V_14 = V_24 ;
else if ( V_19 == 6 )
V_14 = V_25 ;
return V_14 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_26 ) = V_27 ;
if ( ! V_2 -> V_5 . V_6 . V_13 )
F_7 ( V_2 , V_26 ) |= V_28 ;
V_2 -> V_5 . V_6 . V_29 . V_30 = V_31 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_32 , void * V_33 , unsigned int V_34 )
{
int V_14 , V_35 ;
memcpy ( & F_7 ( V_2 , V_32 ) , V_33 , V_34 ) ;
V_35 = F_7 ( V_2 , V_32 ) & V_20 ;
F_9 ( V_2 ) ;
if ( V_35 == 0 )
return 0 ;
V_14 = F_5 ( V_35 ) ;
if ( F_10 ( V_14 < 0 ) )
return 0 ;
V_2 -> V_5 . V_6 . V_8 = V_36 ;
V_2 -> V_5 . V_6 . V_29 . V_30 = V_31 ;
F_7 ( V_2 , V_26 ) &= ~ V_37 ;
F_7 ( V_2 , V_26 ) |= V_27 | V_38 ;
if ( F_3 ( V_2 , V_14 ) &&
! F_11 ( V_2 , V_14 ) ) {
V_2 -> V_5 . V_6 . V_14 = V_14 ;
V_2 -> V_5 . V_6 . V_13 = true ;
F_7 ( V_2 , V_26 ) &= ~ V_28 ;
} else
F_7 ( V_2 , V_26 ) |= V_28 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_33 , unsigned int V_34 )
{
struct V_3 * V_6 = & V_2 -> V_5 . V_6 ;
T_1 V_39 ;
T_1 V_40 = * ( T_1 * ) V_33 ;
if ( F_7 ( V_2 , V_32 ) & V_41 ) {
if ( ! ( V_40 & V_41 ) ) {
F_7 ( V_2 , V_32 ) &= ~ V_41 ;
F_6 ( V_2 ) ;
}
} else {
if ( V_40 & V_41 ) {
F_7 ( V_2 , V_26 ) &= ~ V_42 ;
F_7 ( V_2 , V_26 ) |= V_27 ;
}
if ( V_40 & V_43 )
V_40 &= ~ V_43 ;
V_6 -> V_29 . V_44 =
F_13 ( V_40 ) ;
V_39 = F_14 ( V_40 ) ;
if ( V_39 == V_45 ) {
V_6 -> V_10 = true ;
} else if ( V_39 != 0 ) {
F_15 (
L_5
L_6 ,
V_2 -> V_46 , V_39 ) ;
}
if ( V_40 & V_47 )
V_6 -> V_11 =
F_16 ( V_40 ) ;
V_6 -> V_29 . V_48 = F_17 ( V_40 ) ;
switch ( F_17 ( V_40 ) ) {
case V_49 :
break;
case V_50 :
if ( F_17 ( F_7 ( V_2 , V_32 ) )
!= V_49 ) {
F_9 ( V_2 ) ;
V_6 -> V_29 . V_30 = V_31 ;
F_7 ( V_2 , V_26 ) &= ~ V_37 ;
}
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_6 -> V_29 . V_30 = V_55 ;
F_7 ( V_2 , V_26 ) |= V_37 ;
break;
default:
F_2 ( L_7 ) ;
break;
}
F_7 ( V_2 , V_32 ) = V_40 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_33 , unsigned int V_34 )
{
F_10 ( 1 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_33 , unsigned int V_34 )
{
int V_56 ;
unsigned char V_57 ;
struct V_3 * V_6 = & V_2 -> V_5 . V_6 ;
int V_58 = V_6 -> V_29 . V_44 -
V_6 -> V_11 ;
int V_59 = V_58 ;
T_1 V_60 = 0 ;
if ( F_7 ( V_2 , V_61 ) & V_62 ) {
if ( V_58 <= 0 ) {
memcpy ( V_33 , & F_7 ( V_2 , V_32 ) , V_34 ) ;
return 0 ;
}
if ( V_59 > 4 )
V_59 = 4 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ ) {
V_57 = F_1 ( V_2 ) ;
V_60 |= ( V_57 << ( V_56 << 3 ) ) ;
}
memcpy ( & F_7 ( V_2 , V_32 ) , & V_60 , V_59 ) ;
memcpy ( V_33 , & F_7 ( V_2 , V_32 ) , V_34 ) ;
if ( V_58 <= 4 ) {
switch ( V_6 -> V_29 . V_48 ) {
case V_53 :
case V_54 :
V_6 -> V_29 . V_30 = V_31 ;
break;
case V_51 :
case V_52 :
default:
V_6 -> V_29 . V_30 = V_63 ;
break;
}
F_9 ( V_2 ) ;
}
} else {
memcpy ( V_33 , & F_7 ( V_2 , V_32 ) , V_34 ) ;
F_2 ( L_8 ,
V_2 -> V_46 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_33 , unsigned int V_34 )
{
T_1 V_64 = F_7 ( V_2 , V_32 ) ;
if ( ! ( F_7 ( V_2 , V_32 ) & V_65 ) )
F_7 ( V_2 , V_32 ) |= V_65 ;
memcpy ( V_33 , ( void * ) & V_64 , V_34 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_32 ,
void * V_33 , unsigned int V_34 )
{
T_1 V_40 = * ( T_1 * ) V_33 ;
if ( V_40 & V_65 )
F_7 ( V_2 , V_32 ) &= ~ V_65 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
unsigned int V_32 , void * V_33 , unsigned int V_34 )
{
if ( F_10 ( V_34 > 8 && ( V_32 & ( V_34 - 1 ) ) ) )
return - V_21 ;
if ( V_32 == F_23 ( V_26 ) )
return F_20 ( V_2 , V_32 , V_33 , V_34 ) ;
else if ( V_32 == F_23 ( V_66 ) )
return F_19 ( V_2 , V_32 , V_33 , V_34 ) ;
memcpy ( V_33 , & F_7 ( V_2 , V_32 ) , V_34 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
unsigned int V_32 , void * V_33 , unsigned int V_34 )
{
if ( F_10 ( V_34 > 8 && ( V_32 & ( V_34 - 1 ) ) ) )
return - V_21 ;
if ( V_32 == F_23 ( V_67 ) )
return F_8 ( V_2 , V_32 , V_33 , V_34 ) ;
else if ( V_32 == F_23 ( V_61 ) )
return F_12 ( V_2 , V_32 , V_33 , V_34 ) ;
else if ( V_32 == F_23 ( V_26 ) )
return F_21 ( V_2 , V_32 , V_33 , V_34 ) ;
else if ( V_32 == F_23 ( V_66 ) )
return F_18 ( V_2 , V_32 , V_33 , V_34 ) ;
memcpy ( & F_7 ( V_2 , V_32 ) , V_33 , V_34 ) ;
return 0 ;
}
static inline int F_25 ( unsigned int V_32 )
{
int V_68 ;
switch ( V_32 & 0xff ) {
case 0x10 :
V_68 = V_69 ;
break;
case 0x14 :
V_68 = V_70 ;
break;
case 0x18 :
V_68 = V_71 ;
break;
case 0x1c :
V_68 = V_72 ;
break;
case 0x20 :
V_68 = V_73 ;
break;
case 0x24 :
V_68 = V_74 ;
break;
default:
V_68 = - 1 ;
break;
}
return V_68 ;
}
void F_26 ( struct V_1 * V_2 ,
int V_75 ,
unsigned int V_32 ,
void * V_33 )
{
struct V_3 * V_6 = & V_2 -> V_5 . V_6 ;
int V_76 , V_77 ;
int V_78 , V_79 , V_80 , V_81 ;
T_1 V_64 = * ( T_1 * ) V_33 ;
int V_82 = 0 ;
int V_68 = F_25 ( V_32 ) ;
if ( V_68 != V_69 ) {
F_7 ( V_2 , V_32 ) = V_64 ;
return;
}
V_76 = F_27 ( V_64 ) ;
V_78 = F_7 ( V_2 , V_32 + 4 ) ;
V_79 = ( V_78 >> 8 ) & 0xffff ;
V_80 = ( V_78 >> 24 ) & 0xff ;
V_81 = V_80 >> 4 ;
if ( ! ( V_64 & V_83 ) ) {
return;
}
V_77 = ( ( ( V_81 & 0x1 ) == V_84 ) ? 2 : 1 ) ;
F_7 ( V_2 , V_32 ) =
V_85 |
( ( V_77 << V_86 ) &
V_87 ) ;
if ( V_76 == 3 ) {
if ( ! ( V_81 & V_88 ) ) {
F_9 ( V_2 ) ;
} else {
V_6 -> V_89 . V_90 = true ;
V_6 -> V_89 . V_91 = true ;
if ( V_79 == 0 ) {
F_9 ( V_2 ) ;
} else if ( V_79 == V_45 ) {
V_6 -> V_8 = V_92 ;
V_6 -> V_14 = V_75 ;
V_6 -> V_10 = true ;
if ( F_3 ( V_2 ,
V_75 ) &&
F_11 ( V_2 , V_75 ) )
V_6 -> V_13 = true ;
}
}
} else if ( ( V_81 & 0x1 ) == V_93 ) {
} else {
if ( F_10 ( ( V_81 & 0x1 ) != V_84 ) )
return;
if ( F_10 ( V_76 != 4 ) )
return;
if ( V_6 -> V_13 && V_6 -> V_10 ) {
unsigned char V_94 = F_1 ( V_2 ) ;
V_82 = ( V_94 << 16 ) ;
}
}
V_82 |= V_95 << 24 ;
F_7 ( V_2 , V_32 + 4 ) = V_82 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_14 = - 1 ;
V_4 -> V_10 = false ;
V_4 -> V_13 = false ;
V_4 -> V_11 = 0 ;
memset ( & V_4 -> V_29 , 0 , sizeof( struct V_96 ) ) ;
V_4 -> V_89 . V_90 = false ;
V_4 -> V_89 . V_91 = false ;
}
