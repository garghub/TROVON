static void F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( 3 , V_9 ) ;
if ( ! V_8 )
return;
F_3 ( V_8 ) = V_10 ;
memcpy ( F_4 ( V_8 , V_4 ) , V_3 , V_4 ) ;
F_5 ( & V_5 -> V_11 , V_8 ) ;
}
static T_2 F_6 ( struct V_5 * V_5 )
{
return V_5 -> V_12 & 0x07 ;
}
static void F_7 ( unsigned long V_13 )
{
const unsigned char V_14 [] = { 0x01 , 0x7e } ;
unsigned char V_15 [ 3 ] = { 0x03 , 0xfc } ;
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_16 ;
unsigned long V_17 ;
F_8 ( L_1 , V_2 -> V_18 -> V_19 ) ;
if ( V_5 -> V_20 == V_21 )
F_1 ( V_2 , V_14 , sizeof( V_14 ) ) ;
if ( V_5 -> V_20 == V_22 ) {
V_15 [ 2 ] = F_6 ( V_5 ) ;
F_1 ( V_2 , V_15 , sizeof( V_15 ) ) ;
}
if ( V_5 -> V_20 != V_23 ) {
F_9 ( & V_5 -> V_24 , V_25 + V_26 ) ;
goto V_27;
}
if ( V_5 -> V_28 != V_29 ) {
V_5 -> V_28 = V_30 ;
goto V_27;
}
F_8 ( L_2 , V_2 , V_5 -> V_31 . V_32 ) ;
F_10 ( & V_5 -> V_31 . V_33 , V_17 , V_34 ) ;
while ( ( V_16 = F_11 ( & V_5 -> V_31 ) ) != NULL ) {
V_5 -> V_35 = ( V_5 -> V_35 - 1 ) & 0x07 ;
F_12 ( & V_5 -> V_36 , V_16 ) ;
}
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
V_27:
F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
F_16 ( L_3 ) ;
V_5 -> V_20 = V_21 ;
F_17 ( & V_5 -> V_24 ) ;
F_18 ( & V_5 -> V_36 ) ;
F_18 ( & V_5 -> V_11 ) ;
F_18 ( & V_5 -> V_31 ) ;
V_5 -> V_35 = 0 ;
V_5 -> V_37 = 0 ;
F_19 ( V_2 -> V_18 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
const unsigned char V_38 [] = { 0x01 , 0x7e } ;
F_8 ( L_4 , V_2 ) ;
V_5 = F_21 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_2 -> V_6 = V_5 ;
F_22 ( & V_5 -> V_31 ) ;
F_22 ( & V_5 -> V_36 ) ;
F_22 ( & V_5 -> V_11 ) ;
F_23 ( V_5 ) ;
F_24 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_41 = F_7 ;
V_5 -> V_24 . V_3 = ( unsigned long ) V_2 ;
V_5 -> V_12 = V_42 ;
F_25 ( V_43 , & V_2 -> V_44 ) ;
F_1 ( V_2 , V_38 , sizeof( V_38 ) ) ;
F_9 ( & V_5 -> V_24 , V_25 + V_26 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
F_27 ( & V_5 -> V_24 ) ;
F_18 ( & V_5 -> V_31 ) ;
F_18 ( & V_5 -> V_36 ) ;
F_18 ( & V_5 -> V_11 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_5 )
{
struct V_7 * V_16 , * V_45 ;
unsigned long V_17 ;
int V_46 , V_47 ;
T_2 V_48 ;
F_30 ( & V_5 -> V_31 . V_33 , V_17 ) ;
V_47 = F_31 ( & V_5 -> V_31 ) ;
if ( V_47 == 0 )
goto V_49;
V_48 = V_5 -> V_35 ;
while ( V_47 > 0 ) {
if ( V_5 -> V_50 == V_48 )
break;
V_47 -- ;
V_48 = ( V_48 - 1 ) & 0x07 ;
}
if ( V_48 != V_5 -> V_50 )
F_16 ( L_5 ) ;
V_46 = 0 ;
F_32 (&h5->unack, skb, tmp) {
if ( V_46 ++ >= V_47 )
break;
F_33 ( V_16 , & V_5 -> V_31 ) ;
F_34 ( V_16 ) ;
}
if ( F_35 ( & V_5 -> V_31 ) )
F_17 ( & V_5 -> V_24 ) ;
V_49:
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char V_14 [] = { 0x01 , 0x7e } ;
const unsigned char V_51 [] = { 0x02 , 0x7d } ;
unsigned char V_15 [ 3 ] = { 0x03 , 0xfc } ;
const unsigned char V_52 [] = { 0x04 , 0x7b } ;
const unsigned char V_53 [] = { 0x05 , 0xfa } ;
const unsigned char V_54 [] = { 0x06 , 0xf9 } ;
const unsigned char V_55 [] = { 0x07 , 0x78 } ;
const unsigned char * V_56 = V_5 -> V_57 -> V_3 ;
const unsigned char * V_3 = & V_5 -> V_57 -> V_3 [ 4 ] ;
F_8 ( L_1 , V_2 -> V_18 -> V_19 ) ;
if ( F_37 ( V_56 ) != V_10 )
return;
if ( F_38 ( V_56 ) < 2 )
return;
V_15 [ 2 ] = F_6 ( V_5 ) ;
if ( memcmp ( V_3 , V_14 , 2 ) == 0 ) {
if ( V_5 -> V_20 == V_23 )
F_15 ( V_2 ) ;
F_1 ( V_2 , V_51 , 2 ) ;
} else if ( memcmp ( V_3 , V_51 , 2 ) == 0 ) {
if ( V_5 -> V_20 == V_23 )
F_15 ( V_2 ) ;
V_5 -> V_20 = V_22 ;
F_1 ( V_2 , V_15 , 3 ) ;
} else if ( memcmp ( V_3 , V_15 , 2 ) == 0 ) {
F_1 ( V_2 , V_52 , 2 ) ;
F_1 ( V_2 , V_15 , 3 ) ;
} else if ( memcmp ( V_3 , V_52 , 2 ) == 0 ) {
if ( F_38 ( V_56 ) > 2 )
V_5 -> V_12 = ( V_3 [ 2 ] & 0x07 ) ;
F_8 ( L_6 , V_5 -> V_12 ) ;
V_5 -> V_20 = V_23 ;
F_39 ( V_2 ) ;
return;
} else if ( memcmp ( V_3 , V_55 , 2 ) == 0 ) {
F_8 ( L_7 ) ;
V_5 -> V_28 = V_30 ;
return;
} else if ( memcmp ( V_3 , V_54 , 2 ) == 0 ) {
F_8 ( L_8 ) ;
V_5 -> V_28 = V_29 ;
} else if ( memcmp ( V_3 , V_53 , 2 ) == 0 ) {
F_8 ( L_9 ) ;
F_1 ( V_2 , V_54 , 2 ) ;
V_5 -> V_28 = V_29 ;
} else {
F_8 ( L_10 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
return;
}
F_14 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_56 = V_5 -> V_57 -> V_3 ;
if ( F_41 ( V_56 ) ) {
V_5 -> V_37 = ( V_5 -> V_37 + 1 ) % 8 ;
F_25 ( V_58 , & V_5 -> V_17 ) ;
F_14 ( V_2 ) ;
}
V_5 -> V_50 = F_42 ( V_56 ) ;
F_29 ( V_5 ) ;
switch ( F_37 ( V_56 ) ) {
case V_59 :
case V_60 :
case V_61 :
F_3 ( V_5 -> V_57 ) = F_37 ( V_56 ) ;
F_43 ( V_5 -> V_57 , 4 ) ;
F_44 ( V_2 -> V_18 , V_5 -> V_57 ) ;
V_5 -> V_57 = NULL ;
break;
default:
F_36 ( V_2 ) ;
break;
}
F_23 ( V_5 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned char V_62 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char V_62 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_56 = V_5 -> V_57 -> V_3 ;
if ( F_47 ( V_56 ) ) {
V_5 -> V_63 = F_45 ;
V_5 -> V_64 = 2 ;
} else {
F_40 ( V_2 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_62 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_56 = V_5 -> V_57 -> V_3 ;
F_8 ( L_11 ,
V_2 -> V_18 -> V_19 , F_49 ( V_56 ) , F_42 ( V_56 ) ,
F_47 ( V_56 ) , F_41 ( V_56 ) , F_37 ( V_56 ) ,
F_38 ( V_56 ) ) ;
if ( ( ( V_56 [ 0 ] + V_56 [ 1 ] + V_56 [ 2 ] + V_56 [ 3 ] ) & 0xff ) != 0xff ) {
F_16 ( L_12 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( F_41 ( V_56 ) && F_49 ( V_56 ) != V_5 -> V_37 ) {
F_16 ( L_13 ,
F_49 ( V_56 ) , V_5 -> V_37 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_20 != V_23 &&
F_37 ( V_56 ) != V_10 ) {
F_16 ( L_14 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
V_5 -> V_63 = F_46 ;
V_5 -> V_64 = F_38 ( V_56 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned char V_62 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_62 == V_65 )
return 1 ;
V_5 -> V_63 = F_48 ;
V_5 -> V_64 = 4 ;
V_5 -> V_57 = F_51 ( V_66 , V_9 ) ;
if ( ! V_5 -> V_57 ) {
F_16 ( L_15 ) ;
F_23 ( V_5 ) ;
return - V_40 ;
}
V_5 -> V_57 -> V_67 = ( void * ) V_2 -> V_18 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned char V_62 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_62 == V_65 )
V_5 -> V_63 = F_50 ;
return 1 ;
}
static void F_53 ( struct V_5 * V_5 , unsigned char V_62 )
{
const T_2 V_68 = V_65 , V_69 = V_70 ;
const T_2 * V_71 = & V_62 ;
if ( ! F_54 ( V_72 , & V_5 -> V_17 ) && V_62 == V_70 ) {
F_25 ( V_72 , & V_5 -> V_17 ) ;
return;
}
if ( F_55 ( V_72 , & V_5 -> V_17 ) ) {
switch ( V_62 ) {
case V_73 :
V_71 = & V_68 ;
break;
case V_74 :
V_71 = & V_69 ;
break;
default:
F_16 ( L_16 , V_62 ) ;
F_23 ( V_5 ) ;
return;
}
}
memcpy ( F_4 ( V_5 -> V_57 , 1 ) , V_71 , 1 ) ;
V_5 -> V_64 -- ;
F_8 ( L_17 , * V_71 , V_5 -> V_64 ) ;
}
static void F_23 ( struct V_5 * V_5 )
{
if ( V_5 -> V_57 ) {
F_34 ( V_5 -> V_57 ) ;
V_5 -> V_57 = NULL ;
}
V_5 -> V_63 = F_52 ;
V_5 -> V_64 = 0 ;
F_56 ( V_72 , & V_5 -> V_17 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_3 , int V_75 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_76 = V_3 ;
F_8 ( L_18 , V_2 -> V_18 -> V_19 , V_5 -> V_64 ,
V_75 ) ;
while ( V_75 > 0 ) {
int V_77 ;
if ( V_5 -> V_64 > 0 ) {
if ( * V_76 == V_65 ) {
F_16 ( L_19 ) ;
F_23 ( V_5 ) ;
continue;
}
F_53 ( V_5 , * V_76 ) ;
V_76 ++ ; V_75 -- ;
continue;
}
V_77 = V_5 -> V_63 ( V_2 , * V_76 ) ;
if ( V_77 < 0 )
return V_77 ;
V_76 += V_77 ;
V_75 -= V_77 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_7 * V_16 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_16 -> V_4 > 0xfff ) {
F_16 ( L_20 , V_16 -> V_4 ) ;
F_34 ( V_16 ) ;
return 0 ;
}
if ( V_5 -> V_20 != V_23 ) {
F_16 ( L_21 ) ;
F_34 ( V_16 ) ;
return 0 ;
}
switch ( F_3 ( V_16 ) ) {
case V_60 :
case V_78 :
F_5 ( & V_5 -> V_36 , V_16 ) ;
break;
case V_61 :
F_5 ( & V_5 -> V_11 , V_16 ) ;
break;
default:
F_16 ( L_22 , F_3 ( V_16 ) ) ;
F_34 ( V_16 ) ;
break;
}
return 0 ;
}
static void F_59 ( struct V_7 * V_16 )
{
const char V_68 = V_65 ;
memcpy ( F_4 ( V_16 , 1 ) , & V_68 , 1 ) ;
}
static void F_60 ( struct V_7 * V_16 , T_2 V_62 )
{
const char V_79 [ 2 ] = { V_70 , V_73 } ;
const char V_80 [ 2 ] = { V_70 , V_74 } ;
switch ( V_62 ) {
case V_65 :
memcpy ( F_4 ( V_16 , 2 ) , & V_79 , 2 ) ;
break;
case V_70 :
memcpy ( F_4 ( V_16 , 2 ) , & V_80 , 2 ) ;
break;
default:
memcpy ( F_4 ( V_16 , 1 ) , & V_62 , 1 ) ;
}
}
static bool F_61 ( T_2 type )
{
switch ( type ) {
case V_60 :
case V_78 :
case V_61 :
case V_10 :
case V_81 :
return true ;
default:
return false ;
}
}
static struct V_7 * F_62 ( struct V_1 * V_2 , T_2 V_82 ,
const T_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
T_2 V_56 [ 4 ] ;
int V_46 ;
if ( ! F_61 ( V_82 ) ) {
F_16 ( L_22 , V_82 ) ;
return NULL ;
}
V_8 = F_2 ( ( V_4 + 6 ) * 2 + 2 , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_3 ( V_8 ) = V_82 ;
F_59 ( V_8 ) ;
V_56 [ 0 ] = V_5 -> V_37 << 3 ;
F_56 ( V_58 , & V_5 -> V_17 ) ;
if ( V_82 == V_60 || V_82 == V_78 ) {
V_56 [ 0 ] |= 1 << 7 ;
V_56 [ 0 ] |= V_5 -> V_35 ;
V_5 -> V_35 = ( V_5 -> V_35 + 1 ) % 8 ;
}
V_56 [ 1 ] = V_82 | ( ( V_4 & 0x0f ) << 4 ) ;
V_56 [ 2 ] = V_4 >> 4 ;
V_56 [ 3 ] = ~ ( ( V_56 [ 0 ] + V_56 [ 1 ] + V_56 [ 2 ] ) & 0xff ) ;
F_8 ( L_23 ,
V_2 -> V_18 -> V_19 , F_49 ( V_56 ) , F_42 ( V_56 ) ,
F_47 ( V_56 ) , F_41 ( V_56 ) , F_37 ( V_56 ) ,
F_38 ( V_56 ) ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ )
F_60 ( V_8 , V_56 [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < V_4 ; V_46 ++ )
F_60 ( V_8 , V_3 [ V_46 ] ) ;
F_59 ( V_8 ) ;
return V_8 ;
}
static struct V_7 * F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
unsigned long V_17 ;
struct V_7 * V_16 , * V_8 ;
if ( V_5 -> V_28 != V_29 ) {
const unsigned char V_53 [] = { 0x05 , 0xfa } ;
if ( V_5 -> V_28 == V_83 )
return NULL ;
V_5 -> V_28 = V_83 ;
F_8 ( L_24 ) ;
F_9 ( & V_5 -> V_24 , V_25 + V_84 / 100 ) ;
return F_62 ( V_2 , V_10 , V_53 , 2 ) ;
}
V_16 = F_64 ( & V_5 -> V_11 ) ;
if ( V_16 ) {
V_8 = F_62 ( V_2 , F_3 ( V_16 ) ,
V_16 -> V_3 , V_16 -> V_4 ) ;
if ( V_8 ) {
F_34 ( V_16 ) ;
return V_8 ;
}
F_12 ( & V_5 -> V_11 , V_16 ) ;
F_16 ( L_25 ) ;
}
F_10 ( & V_5 -> V_31 . V_33 , V_17 , V_34 ) ;
if ( V_5 -> V_31 . V_32 >= V_5 -> V_12 )
goto V_49;
V_16 = F_64 ( & V_5 -> V_36 ) ;
if ( V_16 ) {
V_8 = F_62 ( V_2 , F_3 ( V_16 ) ,
V_16 -> V_3 , V_16 -> V_4 ) ;
if ( V_8 ) {
F_65 ( & V_5 -> V_31 , V_16 ) ;
F_9 ( & V_5 -> V_24 , V_25 + V_85 ) ;
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
return V_8 ;
}
F_12 ( & V_5 -> V_36 , V_16 ) ;
F_16 ( L_25 ) ;
}
V_49:
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
if ( F_54 ( V_58 , & V_5 -> V_17 ) )
return F_62 ( V_2 , V_81 , NULL , 0 ) ;
return NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
F_8 ( L_4 , V_2 ) ;
return 0 ;
}
int T_3 F_67 ( void )
{
return F_68 ( & V_86 ) ;
}
int T_4 F_69 ( void )
{
return F_70 ( & V_86 ) ;
}
