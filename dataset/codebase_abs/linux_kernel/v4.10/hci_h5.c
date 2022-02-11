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
F_24 ( & V_5 -> V_24 , F_7 , ( unsigned long ) V_2 ) ;
V_5 -> V_12 = V_41 ;
F_25 ( V_42 , & V_2 -> V_43 ) ;
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
struct V_7 * V_16 , * V_44 ;
unsigned long V_17 ;
int V_45 , V_46 ;
T_2 V_47 ;
F_30 ( & V_5 -> V_31 . V_33 , V_17 ) ;
V_46 = F_31 ( & V_5 -> V_31 ) ;
if ( V_46 == 0 )
goto V_48;
V_47 = V_5 -> V_35 ;
while ( V_46 > 0 ) {
if ( V_5 -> V_49 == V_47 )
break;
V_46 -- ;
V_47 = ( V_47 - 1 ) & 0x07 ;
}
if ( V_47 != V_5 -> V_49 )
F_16 ( L_5 ) ;
V_45 = 0 ;
F_32 (&h5->unack, skb, tmp) {
if ( V_45 ++ >= V_46 )
break;
F_33 ( V_16 , & V_5 -> V_31 ) ;
F_34 ( V_16 ) ;
}
if ( F_35 ( & V_5 -> V_31 ) )
F_17 ( & V_5 -> V_24 ) ;
V_48:
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char V_14 [] = { 0x01 , 0x7e } ;
const unsigned char V_50 [] = { 0x02 , 0x7d } ;
unsigned char V_15 [ 3 ] = { 0x03 , 0xfc } ;
const unsigned char V_51 [] = { 0x04 , 0x7b } ;
const unsigned char V_52 [] = { 0x05 , 0xfa } ;
const unsigned char V_53 [] = { 0x06 , 0xf9 } ;
const unsigned char V_54 [] = { 0x07 , 0x78 } ;
const unsigned char * V_55 = V_5 -> V_56 -> V_3 ;
const unsigned char * V_3 = & V_5 -> V_56 -> V_3 [ 4 ] ;
F_8 ( L_1 , V_2 -> V_18 -> V_19 ) ;
if ( F_37 ( V_55 ) != V_10 )
return;
if ( F_38 ( V_55 ) < 2 )
return;
V_15 [ 2 ] = F_6 ( V_5 ) ;
if ( memcmp ( V_3 , V_14 , 2 ) == 0 ) {
if ( V_5 -> V_20 == V_23 )
F_15 ( V_2 ) ;
F_1 ( V_2 , V_50 , 2 ) ;
} else if ( memcmp ( V_3 , V_50 , 2 ) == 0 ) {
if ( V_5 -> V_20 == V_23 )
F_15 ( V_2 ) ;
V_5 -> V_20 = V_22 ;
F_1 ( V_2 , V_15 , 3 ) ;
} else if ( memcmp ( V_3 , V_15 , 2 ) == 0 ) {
F_1 ( V_2 , V_51 , 2 ) ;
F_1 ( V_2 , V_15 , 3 ) ;
} else if ( memcmp ( V_3 , V_51 , 2 ) == 0 ) {
if ( F_38 ( V_55 ) > 2 )
V_5 -> V_12 = ( V_3 [ 2 ] & 0x07 ) ;
F_8 ( L_6 , V_5 -> V_12 ) ;
V_5 -> V_20 = V_23 ;
F_39 ( V_2 ) ;
return;
} else if ( memcmp ( V_3 , V_54 , 2 ) == 0 ) {
F_8 ( L_7 ) ;
V_5 -> V_28 = V_30 ;
return;
} else if ( memcmp ( V_3 , V_53 , 2 ) == 0 ) {
F_8 ( L_8 ) ;
V_5 -> V_28 = V_29 ;
} else if ( memcmp ( V_3 , V_52 , 2 ) == 0 ) {
F_8 ( L_9 ) ;
F_1 ( V_2 , V_53 , 2 ) ;
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
const unsigned char * V_55 = V_5 -> V_56 -> V_3 ;
if ( F_41 ( V_55 ) ) {
V_5 -> V_37 = ( V_5 -> V_37 + 1 ) % 8 ;
F_25 ( V_57 , & V_5 -> V_17 ) ;
F_14 ( V_2 ) ;
}
V_5 -> V_49 = F_42 ( V_55 ) ;
F_29 ( V_5 ) ;
switch ( F_37 ( V_55 ) ) {
case V_58 :
case V_59 :
case V_60 :
F_3 ( V_5 -> V_56 ) = F_37 ( V_55 ) ;
F_43 ( V_5 -> V_56 , 4 ) ;
F_44 ( V_2 -> V_18 , V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
break;
default:
F_36 ( V_2 ) ;
break;
}
F_23 ( V_5 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned char V_61 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char V_61 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_55 = V_5 -> V_56 -> V_3 ;
if ( F_47 ( V_55 ) ) {
V_5 -> V_62 = F_45 ;
V_5 -> V_63 = 2 ;
} else {
F_40 ( V_2 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_61 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_55 = V_5 -> V_56 -> V_3 ;
F_8 ( L_11 ,
V_2 -> V_18 -> V_19 , F_49 ( V_55 ) , F_42 ( V_55 ) ,
F_47 ( V_55 ) , F_41 ( V_55 ) , F_37 ( V_55 ) ,
F_38 ( V_55 ) ) ;
if ( ( ( V_55 [ 0 ] + V_55 [ 1 ] + V_55 [ 2 ] + V_55 [ 3 ] ) & 0xff ) != 0xff ) {
F_16 ( L_12 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( F_41 ( V_55 ) && F_49 ( V_55 ) != V_5 -> V_37 ) {
F_16 ( L_13 ,
F_49 ( V_55 ) , V_5 -> V_37 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_20 != V_23 &&
F_37 ( V_55 ) != V_10 ) {
F_16 ( L_14 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
V_5 -> V_62 = F_46 ;
V_5 -> V_63 = F_38 ( V_55 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned char V_61 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_61 == V_64 )
return 1 ;
V_5 -> V_62 = F_48 ;
V_5 -> V_63 = 4 ;
V_5 -> V_56 = F_51 ( V_65 , V_9 ) ;
if ( ! V_5 -> V_56 ) {
F_16 ( L_15 ) ;
F_23 ( V_5 ) ;
return - V_40 ;
}
V_5 -> V_56 -> V_66 = ( void * ) V_2 -> V_18 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned char V_61 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_61 == V_64 )
V_5 -> V_62 = F_50 ;
return 1 ;
}
static void F_53 ( struct V_5 * V_5 , unsigned char V_61 )
{
const T_2 V_67 = V_64 , V_68 = V_69 ;
const T_2 * V_70 = & V_61 ;
if ( ! F_54 ( V_71 , & V_5 -> V_17 ) && V_61 == V_69 ) {
F_25 ( V_71 , & V_5 -> V_17 ) ;
return;
}
if ( F_55 ( V_71 , & V_5 -> V_17 ) ) {
switch ( V_61 ) {
case V_72 :
V_70 = & V_67 ;
break;
case V_73 :
V_70 = & V_68 ;
break;
default:
F_16 ( L_16 , V_61 ) ;
F_23 ( V_5 ) ;
return;
}
}
memcpy ( F_4 ( V_5 -> V_56 , 1 ) , V_70 , 1 ) ;
V_5 -> V_63 -- ;
F_8 ( L_17 , * V_70 , V_5 -> V_63 ) ;
}
static void F_23 ( struct V_5 * V_5 )
{
if ( V_5 -> V_56 ) {
F_34 ( V_5 -> V_56 ) ;
V_5 -> V_56 = NULL ;
}
V_5 -> V_62 = F_52 ;
V_5 -> V_63 = 0 ;
F_56 ( V_71 , & V_5 -> V_17 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_3 , int V_74 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_75 = V_3 ;
F_8 ( L_18 , V_2 -> V_18 -> V_19 , V_5 -> V_63 ,
V_74 ) ;
while ( V_74 > 0 ) {
int V_76 ;
if ( V_5 -> V_63 > 0 ) {
if ( * V_75 == V_64 ) {
F_16 ( L_19 ) ;
F_23 ( V_5 ) ;
continue;
}
F_53 ( V_5 , * V_75 ) ;
V_75 ++ ; V_74 -- ;
continue;
}
V_76 = V_5 -> V_62 ( V_2 , * V_75 ) ;
if ( V_76 < 0 )
return V_76 ;
V_75 += V_76 ;
V_74 -= V_76 ;
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
case V_59 :
case V_77 :
F_5 ( & V_5 -> V_36 , V_16 ) ;
break;
case V_60 :
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
const char V_67 = V_64 ;
memcpy ( F_4 ( V_16 , 1 ) , & V_67 , 1 ) ;
}
static void F_60 ( struct V_7 * V_16 , T_2 V_61 )
{
const char V_78 [ 2 ] = { V_69 , V_72 } ;
const char V_79 [ 2 ] = { V_69 , V_73 } ;
switch ( V_61 ) {
case V_64 :
memcpy ( F_4 ( V_16 , 2 ) , & V_78 , 2 ) ;
break;
case V_69 :
memcpy ( F_4 ( V_16 , 2 ) , & V_79 , 2 ) ;
break;
default:
memcpy ( F_4 ( V_16 , 1 ) , & V_61 , 1 ) ;
}
}
static bool F_61 ( T_2 type )
{
switch ( type ) {
case V_59 :
case V_77 :
case V_60 :
case V_10 :
case V_80 :
return true ;
default:
return false ;
}
}
static struct V_7 * F_62 ( struct V_1 * V_2 , T_2 V_81 ,
const T_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
T_2 V_55 [ 4 ] ;
int V_45 ;
if ( ! F_61 ( V_81 ) ) {
F_16 ( L_22 , V_81 ) ;
return NULL ;
}
V_8 = F_2 ( ( V_4 + 6 ) * 2 + 2 , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_3 ( V_8 ) = V_81 ;
F_59 ( V_8 ) ;
V_55 [ 0 ] = V_5 -> V_37 << 3 ;
F_56 ( V_57 , & V_5 -> V_17 ) ;
if ( V_81 == V_59 || V_81 == V_77 ) {
V_55 [ 0 ] |= 1 << 7 ;
V_55 [ 0 ] |= V_5 -> V_35 ;
V_5 -> V_35 = ( V_5 -> V_35 + 1 ) % 8 ;
}
V_55 [ 1 ] = V_81 | ( ( V_4 & 0x0f ) << 4 ) ;
V_55 [ 2 ] = V_4 >> 4 ;
V_55 [ 3 ] = ~ ( ( V_55 [ 0 ] + V_55 [ 1 ] + V_55 [ 2 ] ) & 0xff ) ;
F_8 ( L_23 ,
V_2 -> V_18 -> V_19 , F_49 ( V_55 ) , F_42 ( V_55 ) ,
F_47 ( V_55 ) , F_41 ( V_55 ) , F_37 ( V_55 ) ,
F_38 ( V_55 ) ) ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ )
F_60 ( V_8 , V_55 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < V_4 ; V_45 ++ )
F_60 ( V_8 , V_3 [ V_45 ] ) ;
F_59 ( V_8 ) ;
return V_8 ;
}
static struct V_7 * F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
unsigned long V_17 ;
struct V_7 * V_16 , * V_8 ;
if ( V_5 -> V_28 != V_29 ) {
const unsigned char V_52 [] = { 0x05 , 0xfa } ;
if ( V_5 -> V_28 == V_82 )
return NULL ;
V_5 -> V_28 = V_82 ;
F_8 ( L_24 ) ;
F_9 ( & V_5 -> V_24 , V_25 + V_83 / 100 ) ;
return F_62 ( V_2 , V_10 , V_52 , 2 ) ;
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
goto V_48;
V_16 = F_64 ( & V_5 -> V_36 ) ;
if ( V_16 ) {
V_8 = F_62 ( V_2 , F_3 ( V_16 ) ,
V_16 -> V_3 , V_16 -> V_4 ) ;
if ( V_8 ) {
F_65 ( & V_5 -> V_31 , V_16 ) ;
F_9 ( & V_5 -> V_24 , V_25 + V_84 ) ;
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
return V_8 ;
}
F_12 ( & V_5 -> V_36 , V_16 ) ;
F_16 ( L_25 ) ;
}
V_48:
F_13 ( & V_5 -> V_31 . V_33 , V_17 ) ;
if ( F_54 ( V_57 , & V_5 -> V_17 ) )
return F_62 ( V_2 , V_80 , NULL , 0 ) ;
return NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
F_8 ( L_4 , V_2 ) ;
return 0 ;
}
int T_3 F_67 ( void )
{
return F_68 ( & V_85 ) ;
}
int T_4 F_69 ( void )
{
return F_70 ( & V_85 ) ;
}
