static void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = * V_1 ;
V_3 = ( V_3 >> 4 ) ^ V_4 [ ( V_3 ^ V_2 ) & 0x000f ] ;
V_3 = ( V_3 >> 4 ) ^ V_4 [ ( V_3 ^ ( V_2 >> 4 ) ) & 0x000f ] ;
* V_1 = V_3 ;
}
static void F_2 ( struct V_5 * V_6 )
{
const char V_7 = 0xc0 ;
memcpy ( F_3 ( V_6 , 1 ) , & V_7 , 1 ) ;
}
static void F_4 ( struct V_5 * V_6 , T_2 V_8 )
{
const char V_9 [ 2 ] = { 0xdb , 0xdc } ;
const char V_10 [ 2 ] = { 0xdb , 0xdd } ;
switch ( V_8 ) {
case 0xc0 :
memcpy ( F_3 ( V_6 , 2 ) , & V_9 , 2 ) ;
break;
case 0xdb :
memcpy ( F_3 ( V_6 , 2 ) , & V_10 , 2 ) ;
break;
default:
memcpy ( F_3 ( V_6 , 1 ) , & V_8 , 1 ) ;
}
}
static int F_5 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
if ( V_6 -> V_16 > 0xFFF ) {
F_6 ( L_1 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
switch ( F_8 ( V_6 ) ) {
case V_17 :
case V_18 :
F_9 ( & V_14 -> V_19 , V_6 ) ;
break;
case V_20 :
F_9 ( & V_14 -> V_21 , V_6 ) ;
break;
default:
F_6 ( L_2 ) ;
F_7 ( V_6 ) ;
break;
}
return 0 ;
}
static struct V_5 * F_10 ( struct V_13 * V_14 , T_2 * V_22 ,
int V_16 , int V_23 )
{
struct V_5 * V_24 ;
T_2 V_25 [ 4 ] , V_26 ;
T_1 V_27 ( V_28 ) ;
int V_19 , V_29 ;
switch ( V_23 ) {
case V_17 :
V_26 = 6 ;
V_19 = 1 ;
break;
case V_18 :
V_26 = 5 ;
V_19 = 1 ;
break;
case V_20 :
V_26 = 7 ;
V_19 = 0 ;
break;
case V_30 :
V_26 = 1 ;
V_19 = 0 ;
break;
case V_31 :
V_26 = 0 ;
V_19 = 0 ;
break;
default:
F_6 ( L_2 ) ;
return NULL ;
}
if ( V_32 && V_26 == 5 ) {
T_3 V_33 = ( (struct V_34 * ) V_22 ) -> V_33 ;
if ( F_11 ( F_12 ( V_33 ) ) == 0x3f ) {
T_2 V_35 = * ( V_22 + V_36 ) ;
if ( ( V_35 & 0xf0 ) == 0xc0 ) {
V_22 += V_36 + 1 ;
V_16 -= V_36 + 1 ;
V_26 = V_35 & 0x0f ;
}
}
}
V_24 = F_13 ( ( V_16 + 6 ) * 2 + 2 , V_37 ) ;
if ( ! V_24 )
return NULL ;
F_8 ( V_24 ) = V_23 ;
F_2 ( V_24 ) ;
V_25 [ 0 ] = V_14 -> V_38 << 3 ;
V_14 -> V_39 = 0 ;
F_14 ( L_3 , V_14 -> V_38 ) ;
if ( V_19 ) {
V_25 [ 0 ] |= 0x80 + V_14 -> V_40 ;
F_14 ( L_4 , V_14 -> V_40 ) ;
V_14 -> V_40 = ( V_14 -> V_40 + 1 ) & 0x07 ;
}
if ( V_14 -> V_41 )
V_25 [ 0 ] |= 0x40 ;
V_25 [ 1 ] = ( ( V_16 << 4 ) & 0xff ) | V_26 ;
V_25 [ 2 ] = V_16 >> 4 ;
V_25 [ 3 ] = ~ ( V_25 [ 0 ] + V_25 [ 1 ] + V_25 [ 2 ] ) ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
F_4 ( V_24 , V_25 [ V_29 ] ) ;
if ( V_14 -> V_41 )
F_1 ( & V_28 , V_25 [ V_29 ] ) ;
}
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ ) {
F_4 ( V_24 , V_22 [ V_29 ] ) ;
if ( V_14 -> V_41 )
F_1 ( & V_28 , V_22 [ V_29 ] ) ;
}
if ( V_14 -> V_41 ) {
V_28 = F_15 ( V_28 ) ;
F_4 ( V_24 , ( T_2 ) ( ( V_28 >> 8 ) & 0x00ff ) ) ;
F_4 ( V_24 , ( T_2 ) ( V_28 & 0x00ff ) ) ;
}
F_2 ( V_24 ) ;
return V_24 ;
}
static struct V_5 * F_16 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned long V_42 ;
struct V_5 * V_6 ;
V_6 = F_17 ( & V_14 -> V_21 ) ;
if ( V_6 != NULL ) {
struct V_5 * V_24 ;
V_24 = F_10 ( V_14 , V_6 -> V_22 , V_6 -> V_16 ,
F_8 ( V_6 ) ) ;
if ( V_24 ) {
F_7 ( V_6 ) ;
return V_24 ;
} else {
F_18 ( & V_14 -> V_21 , V_6 ) ;
F_6 ( L_5 ) ;
}
}
F_19 ( & V_14 -> V_43 . V_44 , V_42 , V_45 ) ;
if ( V_14 -> V_43 . V_46 < V_47 ) {
V_6 = F_17 ( & V_14 -> V_19 ) ;
if ( V_6 != NULL ) {
struct V_5 * V_24 ;
V_24 = F_10 ( V_14 , V_6 -> V_22 , V_6 -> V_16 ,
F_8 ( V_6 ) ) ;
if ( V_24 ) {
F_20 ( & V_14 -> V_43 , V_6 ) ;
F_21 ( & V_14 -> V_48 , V_49 + V_50 / 4 ) ;
F_22 ( & V_14 -> V_43 . V_44 , V_42 ) ;
return V_24 ;
} else {
F_18 ( & V_14 -> V_19 , V_6 ) ;
F_6 ( L_5 ) ;
}
}
}
F_22 ( & V_14 -> V_43 . V_44 , V_42 ) ;
if ( V_14 -> V_39 ) {
struct V_5 * V_24 = F_10 ( V_14 , NULL , 0 , V_31 ) ;
return V_24 ;
}
return NULL ;
}
static int F_23 ( struct V_11 * V_12 )
{
F_14 ( L_6 , V_12 ) ;
return 0 ;
}
static void F_24 ( struct V_13 * V_14 )
{
struct V_5 * V_6 , * V_51 ;
unsigned long V_42 ;
int V_29 , V_52 ;
T_2 V_53 ;
F_25 ( & V_14 -> V_43 . V_44 , V_42 ) ;
V_52 = F_26 ( & V_14 -> V_43 ) ;
V_53 = V_14 -> V_40 ;
while ( V_52 ) {
if ( V_14 -> V_54 == V_53 )
break;
V_52 -- ;
V_53 = ( V_53 - 1 ) & 0x07 ;
}
if ( V_14 -> V_54 != V_53 )
F_6 ( L_7 ) ;
F_14 ( L_8 ,
V_52 , F_26 ( & V_14 -> V_43 ) ,
( V_53 - 1 ) & 0x07 ) ;
V_29 = 0 ;
F_27 (&bcsp->unack, skb, tmp) {
if ( V_29 >= V_52 )
break;
V_29 ++ ;
F_28 ( V_6 , & V_14 -> V_43 ) ;
F_7 ( V_6 ) ;
}
if ( F_29 ( & V_14 -> V_43 ) )
F_30 ( & V_14 -> V_48 ) ;
F_22 ( & V_14 -> V_43 . V_44 , V_42 ) ;
if ( V_29 != V_52 )
F_6 ( L_9 , V_29 , V_52 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
T_2 V_55 [ 4 ] = { 0xad , 0xef , 0xac , 0xed } ;
T_2 V_56 [ 4 ] = { 0xde , 0xad , 0xd0 , 0xd0 } ;
T_2 V_57 [ 4 ] = { 0xda , 0xdc , 0xed , 0xed } ;
if ( V_14 -> V_58 -> V_22 [ 1 ] >> 4 == 4 && V_14 -> V_58 -> V_22 [ 2 ] == 0 &&
! memcmp ( & V_14 -> V_58 -> V_22 [ 4 ] , V_55 , 4 ) ) {
struct V_5 * V_24 = F_13 ( 4 , V_37 ) ;
F_14 ( L_10 ) ;
if ( ! V_24 )
return;
memcpy ( F_3 ( V_24 , 4 ) , V_56 , 4 ) ;
F_8 ( V_24 ) = V_30 ;
F_18 ( & V_14 -> V_21 , V_24 ) ;
F_32 ( V_12 ) ;
}
else if ( V_14 -> V_58 -> V_22 [ 1 ] >> 4 == 4 && V_14 -> V_58 -> V_22 [ 2 ] == 0 &&
! memcmp ( & V_14 -> V_58 -> V_22 [ 4 ] , V_57 , 4 ) ) {
F_6 ( L_11 ) ;
}
}
static inline void F_33 ( struct V_13 * V_14 , unsigned char V_59 )
{
const T_2 V_60 = 0xc0 , V_61 = 0xdb ;
switch ( V_14 -> V_62 ) {
case V_63 :
switch ( V_59 ) {
case 0xdb :
V_14 -> V_62 = V_64 ;
break;
default:
memcpy ( F_3 ( V_14 -> V_58 , 1 ) , & V_59 , 1 ) ;
if ( ( V_14 -> V_58 -> V_22 [ 0 ] & 0x40 ) != 0 &&
V_14 -> V_65 != V_66 )
F_1 ( & V_14 -> V_67 , V_59 ) ;
V_14 -> V_68 -- ;
}
break;
case V_64 :
switch ( V_59 ) {
case 0xdc :
memcpy ( F_3 ( V_14 -> V_58 , 1 ) , & V_60 , 1 ) ;
if ( ( V_14 -> V_58 -> V_22 [ 0 ] & 0x40 ) != 0 &&
V_14 -> V_65 != V_66 )
F_1 ( & V_14 -> V_67 , 0xc0 ) ;
V_14 -> V_62 = V_63 ;
V_14 -> V_68 -- ;
break;
case 0xdd :
memcpy ( F_3 ( V_14 -> V_58 , 1 ) , & V_61 , 1 ) ;
if ( ( V_14 -> V_58 -> V_22 [ 0 ] & 0x40 ) != 0 &&
V_14 -> V_65 != V_66 )
F_1 ( & V_14 -> V_67 , 0xdb ) ;
V_14 -> V_62 = V_63 ;
V_14 -> V_68 -- ;
break;
default:
F_6 ( L_12 , V_59 ) ;
F_7 ( V_14 -> V_58 ) ;
V_14 -> V_58 = NULL ;
V_14 -> V_65 = V_69 ;
V_14 -> V_68 = 0 ;
}
}
}
static void F_34 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
int V_70 = 0 ;
if ( V_14 -> V_58 -> V_22 [ 0 ] & 0x80 ) {
F_14 ( L_13 , V_14 -> V_38 ) ;
if ( ( V_14 -> V_58 -> V_22 [ 0 ] & 0x07 ) == V_14 -> V_38 ) {
V_14 -> V_38 ++ ;
V_14 -> V_38 %= 0x8 ;
} else {
F_6 ( L_14 ,
V_14 -> V_58 -> V_22 [ 0 ] & 0x07 , V_14 -> V_38 ) ;
V_70 = 2 ;
}
V_14 -> V_39 = 1 ;
F_32 ( V_12 ) ;
}
V_14 -> V_54 = ( V_14 -> V_58 -> V_22 [ 0 ] >> 3 ) & 0x07 ;
F_14 ( L_15 , V_14 -> V_54 ) ;
F_24 ( V_14 ) ;
if ( V_70 != 2 ) {
if ( ( V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ) == 6 &&
( V_14 -> V_58 -> V_22 [ 0 ] & 0x80 ) ) {
F_8 ( V_14 -> V_58 ) = V_17 ;
V_70 = 1 ;
} else if ( ( V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ) == 5 &&
( V_14 -> V_58 -> V_22 [ 0 ] & 0x80 ) ) {
F_8 ( V_14 -> V_58 ) = V_71 ;
V_70 = 1 ;
} else if ( ( V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ) == 7 ) {
F_8 ( V_14 -> V_58 ) = V_20 ;
V_70 = 1 ;
} else if ( ( V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ) == 1 &&
! ( V_14 -> V_58 -> V_22 [ 0 ] & 0x80 ) ) {
F_31 ( V_12 ) ;
V_70 = 0 ;
} else {
V_70 = 0 ;
}
}
if ( V_70 == 0 ) {
struct V_72 V_25 ;
T_2 V_35 = ( V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ) ;
if ( V_35 != 0 && V_35 != 1 ) {
if ( V_32 ) {
V_35 |= 0xc0 ;
F_35 ( V_14 -> V_58 , 4 ) ;
memcpy ( F_36 ( V_14 -> V_58 , 1 ) , & V_35 , 1 ) ;
V_25 . V_73 = 0xff ;
V_25 . V_74 = V_14 -> V_58 -> V_16 ;
memcpy ( F_36 ( V_14 -> V_58 , V_75 ) , & V_25 , V_75 ) ;
F_8 ( V_14 -> V_58 ) = V_71 ;
F_37 ( V_12 -> V_76 , V_14 -> V_58 ) ;
} else {
F_6 ( L_16 ,
V_14 -> V_58 -> V_22 [ 1 ] & 0x0f ,
V_14 -> V_58 -> V_22 [ 0 ] & 0x80 ?
L_17 : L_18 ) ;
F_7 ( V_14 -> V_58 ) ;
}
} else
F_7 ( V_14 -> V_58 ) ;
} else if ( V_70 == 1 ) {
F_35 ( V_14 -> V_58 , 4 ) ;
F_37 ( V_12 -> V_76 , V_14 -> V_58 ) ;
} else {
F_7 ( V_14 -> V_58 ) ;
}
V_14 -> V_65 = V_69 ;
V_14 -> V_58 = NULL ;
}
static T_1 F_38 ( struct V_13 * V_14 )
{
return F_39 ( & V_14 -> V_58 -> V_22 [ V_14 -> V_58 -> V_16 - 2 ] ) ;
}
static int F_40 ( struct V_11 * V_12 , const void * V_22 , int V_77 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
const unsigned char * V_78 ;
F_14 ( L_19 ,
V_12 , V_77 , V_14 -> V_65 , V_14 -> V_68 ) ;
V_78 = V_22 ;
while ( V_77 ) {
if ( V_14 -> V_68 ) {
if ( * V_78 == 0xc0 ) {
F_6 ( L_20 ) ;
F_7 ( V_14 -> V_58 ) ;
V_14 -> V_65 = V_79 ;
V_14 -> V_68 = 0 ;
} else
F_33 ( V_14 , * V_78 ) ;
V_78 ++ ; V_77 -- ;
continue;
}
switch ( V_14 -> V_65 ) {
case V_80 :
if ( ( 0xff & ( T_2 ) ~ ( V_14 -> V_58 -> V_22 [ 0 ] + V_14 -> V_58 -> V_22 [ 1 ] +
V_14 -> V_58 -> V_22 [ 2 ] ) ) != V_14 -> V_58 -> V_22 [ 3 ] ) {
F_6 ( L_21 ) ;
F_7 ( V_14 -> V_58 ) ;
V_14 -> V_65 = V_69 ;
V_14 -> V_68 = 0 ;
continue;
}
V_14 -> V_65 = V_81 ;
V_14 -> V_68 = ( V_14 -> V_58 -> V_22 [ 1 ] >> 4 ) +
( V_14 -> V_58 -> V_22 [ 2 ] << 4 ) ;
continue;
case V_81 :
if ( V_14 -> V_58 -> V_22 [ 0 ] & 0x40 ) {
V_14 -> V_65 = V_66 ;
V_14 -> V_68 = 2 ;
} else
F_34 ( V_12 ) ;
continue;
case V_66 :
if ( F_15 ( V_14 -> V_67 ) != F_38 ( V_14 ) ) {
F_6 ( L_22 ,
F_15 ( V_14 -> V_67 ) ,
F_38 ( V_14 ) ) ;
F_7 ( V_14 -> V_58 ) ;
V_14 -> V_65 = V_69 ;
V_14 -> V_68 = 0 ;
continue;
}
F_41 ( V_14 -> V_58 , V_14 -> V_58 -> V_16 - 2 ) ;
F_34 ( V_12 ) ;
continue;
case V_69 :
switch ( * V_78 ) {
case 0xc0 :
V_14 -> V_65 = V_79 ;
break;
default:
break;
}
V_78 ++ ; V_77 -- ;
break;
case V_79 :
switch ( * V_78 ) {
case 0xc0 :
V_78 ++ ; V_77 -- ;
break;
default:
V_14 -> V_65 = V_80 ;
V_14 -> V_68 = 4 ;
V_14 -> V_62 = V_63 ;
V_27 ( V_14 -> V_67 ) ;
V_14 -> V_58 = F_42 ( 0x1005 , V_37 ) ;
if ( ! V_14 -> V_58 ) {
F_6 ( L_23 ) ;
V_14 -> V_65 = V_69 ;
V_14 -> V_68 = 0 ;
return 0 ;
}
break;
}
break;
}
}
return V_77 ;
}
static void F_43 ( unsigned long V_82 )
{
struct V_11 * V_12 = (struct V_11 * ) V_82 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_5 * V_6 ;
unsigned long V_42 ;
F_14 ( L_24 , V_12 , V_14 -> V_43 . V_46 ) ;
F_19 ( & V_14 -> V_43 . V_44 , V_42 , V_45 ) ;
while ( ( V_6 = F_44 ( & V_14 -> V_43 ) ) != NULL ) {
V_14 -> V_40 = ( V_14 -> V_40 - 1 ) & 0x07 ;
F_18 ( & V_14 -> V_19 , V_6 ) ;
}
F_22 ( & V_14 -> V_43 . V_44 , V_42 ) ;
F_32 ( V_12 ) ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
F_14 ( L_6 , V_12 ) ;
V_14 = F_46 ( sizeof( * V_14 ) , V_83 ) ;
if ( ! V_14 )
return - V_84 ;
V_12 -> V_15 = V_14 ;
F_47 ( & V_14 -> V_43 ) ;
F_47 ( & V_14 -> V_19 ) ;
F_47 ( & V_14 -> V_21 ) ;
F_48 ( & V_14 -> V_48 , F_43 , ( V_85 ) V_12 ) ;
V_14 -> V_65 = V_69 ;
if ( V_86 )
V_14 -> V_41 = 1 ;
return 0 ;
}
static int F_49 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
F_50 ( & V_14 -> V_48 ) ;
V_12 -> V_15 = NULL ;
F_14 ( L_6 , V_12 ) ;
F_51 ( & V_14 -> V_43 ) ;
F_51 ( & V_14 -> V_19 ) ;
F_51 ( & V_14 -> V_21 ) ;
F_52 ( V_14 ) ;
return 0 ;
}
int T_4 F_53 ( void )
{
return F_54 ( & V_14 ) ;
}
int T_5 F_55 ( void )
{
return F_56 ( & V_14 ) ;
}
