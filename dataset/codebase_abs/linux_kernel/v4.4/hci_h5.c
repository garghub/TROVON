static void F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( 3 , V_9 ) ;
if ( ! V_8 )
return;
F_3 ( V_8 ) -> V_10 = V_11 ;
memcpy ( F_4 ( V_8 , V_4 ) , V_3 , V_4 ) ;
F_5 ( & V_5 -> V_12 , V_8 ) ;
}
static T_2 F_6 ( struct V_5 * V_5 )
{
T_2 V_13 = 0 ;
V_13 |= ( V_5 -> V_14 & 7 ) ;
return V_13 ;
}
static void F_7 ( unsigned long V_15 )
{
const unsigned char V_16 [] = { 0x01 , 0x7e } ;
unsigned char V_17 [] = { 0x03 , 0xfc , 0x01 } ;
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_18 ;
unsigned long V_19 ;
F_8 ( L_1 , V_2 -> V_20 -> V_21 ) ;
if ( V_5 -> V_22 == V_23 )
F_1 ( V_2 , V_16 , sizeof( V_16 ) ) ;
if ( V_5 -> V_22 == V_24 ) {
V_17 [ 2 ] = F_6 ( V_5 ) ;
F_1 ( V_2 , V_17 , sizeof( V_17 ) ) ;
}
if ( V_5 -> V_22 != V_25 ) {
F_9 ( & V_5 -> V_26 , V_27 + V_28 ) ;
goto V_29;
}
if ( V_5 -> V_30 != V_31 ) {
V_5 -> V_30 = V_32 ;
goto V_29;
}
F_8 ( L_2 , V_2 , V_5 -> V_33 . V_34 ) ;
F_10 ( & V_5 -> V_33 . V_35 , V_19 , V_36 ) ;
while ( ( V_18 = F_11 ( & V_5 -> V_33 ) ) != NULL ) {
V_5 -> V_37 = ( V_5 -> V_37 - 1 ) & 0x07 ;
F_12 ( & V_5 -> V_38 , V_18 ) ;
}
F_13 ( & V_5 -> V_33 . V_35 , V_19 ) ;
V_29:
F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
F_16 ( L_3 ) ;
V_5 -> V_22 = V_23 ;
F_17 ( & V_5 -> V_26 ) ;
F_18 ( & V_5 -> V_38 ) ;
F_18 ( & V_5 -> V_12 ) ;
F_18 ( & V_5 -> V_33 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_39 = 0 ;
F_19 ( V_2 -> V_20 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_5 ;
const unsigned char V_40 [] = { 0x01 , 0x7e } ;
F_8 ( L_4 , V_2 ) ;
V_5 = F_21 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
V_2 -> V_6 = V_5 ;
F_22 ( & V_5 -> V_33 ) ;
F_22 ( & V_5 -> V_38 ) ;
F_22 ( & V_5 -> V_12 ) ;
F_23 ( V_5 ) ;
F_24 ( & V_5 -> V_26 ) ;
V_5 -> V_26 . V_43 = F_7 ;
V_5 -> V_26 . V_3 = ( unsigned long ) V_2 ;
V_5 -> V_14 = V_44 ;
F_25 ( V_45 , & V_2 -> V_46 ) ;
F_1 ( V_2 , V_40 , sizeof( V_40 ) ) ;
F_9 ( & V_5 -> V_26 , V_27 + V_28 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
F_27 ( & V_5 -> V_26 ) ;
F_18 ( & V_5 -> V_33 ) ;
F_18 ( & V_5 -> V_38 ) ;
F_18 ( & V_5 -> V_12 ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_5 )
{
struct V_7 * V_18 , * V_47 ;
unsigned long V_19 ;
int V_48 , V_49 ;
T_2 V_50 ;
F_30 ( & V_5 -> V_33 . V_35 , V_19 ) ;
V_49 = F_31 ( & V_5 -> V_33 ) ;
if ( V_49 == 0 )
goto V_51;
V_50 = V_5 -> V_37 ;
while ( V_49 > 0 ) {
if ( V_5 -> V_52 == V_50 )
break;
V_49 -- ;
V_50 = ( V_50 - 1 ) & 0x07 ;
}
if ( V_50 != V_5 -> V_52 )
F_16 ( L_5 ) ;
V_48 = 0 ;
F_32 (&h5->unack, skb, tmp) {
if ( V_48 ++ >= V_49 )
break;
F_33 ( V_18 , & V_5 -> V_33 ) ;
F_34 ( V_18 ) ;
}
if ( F_35 ( & V_5 -> V_33 ) )
F_17 ( & V_5 -> V_26 ) ;
V_51:
F_13 ( & V_5 -> V_33 . V_35 , V_19 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char V_16 [] = { 0x01 , 0x7e } ;
const unsigned char V_53 [] = { 0x02 , 0x7d } ;
unsigned char V_17 [] = { 0x03 , 0xfc , 0x01 } ;
const unsigned char V_54 [] = { 0x04 , 0x7b } ;
const unsigned char V_55 [] = { 0x05 , 0xfa } ;
const unsigned char V_56 [] = { 0x06 , 0xf9 } ;
const unsigned char V_57 [] = { 0x07 , 0x78 } ;
const unsigned char * V_58 = V_5 -> V_59 -> V_3 ;
const unsigned char * V_3 = & V_5 -> V_59 -> V_3 [ 4 ] ;
F_8 ( L_1 , V_2 -> V_20 -> V_21 ) ;
if ( F_37 ( V_58 ) != V_11 )
return;
if ( F_38 ( V_58 ) < 2 )
return;
V_17 [ 2 ] = F_6 ( V_5 ) ;
if ( memcmp ( V_3 , V_16 , 2 ) == 0 ) {
if ( V_5 -> V_22 == V_25 )
F_15 ( V_2 ) ;
F_1 ( V_2 , V_53 , 2 ) ;
} else if ( memcmp ( V_3 , V_53 , 2 ) == 0 ) {
if ( V_5 -> V_22 == V_25 )
F_15 ( V_2 ) ;
V_5 -> V_22 = V_24 ;
F_1 ( V_2 , V_17 , 3 ) ;
} else if ( memcmp ( V_3 , V_17 , 2 ) == 0 ) {
F_1 ( V_2 , V_54 , 2 ) ;
F_1 ( V_2 , V_17 , 3 ) ;
} else if ( memcmp ( V_3 , V_54 , 2 ) == 0 ) {
if ( F_38 ( V_58 ) > 2 )
V_5 -> V_14 = ( V_3 [ 2 ] & 7 ) ;
F_8 ( L_6 , V_5 -> V_14 ) ;
V_5 -> V_22 = V_25 ;
F_39 ( V_2 ) ;
return;
} else if ( memcmp ( V_3 , V_57 , 2 ) == 0 ) {
F_8 ( L_7 ) ;
V_5 -> V_30 = V_32 ;
return;
} else if ( memcmp ( V_3 , V_56 , 2 ) == 0 ) {
F_8 ( L_8 ) ;
V_5 -> V_30 = V_31 ;
} else if ( memcmp ( V_3 , V_55 , 2 ) == 0 ) {
F_8 ( L_9 ) ;
F_1 ( V_2 , V_56 , 2 ) ;
V_5 -> V_30 = V_31 ;
} else {
F_8 ( L_10 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
return;
}
F_14 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_58 = V_5 -> V_59 -> V_3 ;
if ( F_41 ( V_58 ) ) {
V_5 -> V_39 = ( V_5 -> V_39 + 1 ) % 8 ;
F_25 ( V_60 , & V_5 -> V_19 ) ;
F_14 ( V_2 ) ;
}
V_5 -> V_52 = F_42 ( V_58 ) ;
F_29 ( V_5 ) ;
switch ( F_37 ( V_58 ) ) {
case V_61 :
case V_62 :
case V_63 :
F_3 ( V_5 -> V_59 ) -> V_10 = F_37 ( V_58 ) ;
F_43 ( V_5 -> V_59 , 4 ) ;
F_44 ( V_2 -> V_20 , V_5 -> V_59 ) ;
V_5 -> V_59 = NULL ;
break;
default:
F_36 ( V_2 ) ;
break;
}
F_23 ( V_5 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned char V_64 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned char V_64 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_58 = V_5 -> V_59 -> V_3 ;
if ( F_47 ( V_58 ) ) {
V_5 -> V_65 = F_45 ;
V_5 -> V_66 = 2 ;
} else {
F_40 ( V_2 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned char V_64 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_58 = V_5 -> V_59 -> V_3 ;
F_8 ( L_11 ,
V_2 -> V_20 -> V_21 , F_49 ( V_58 ) , F_42 ( V_58 ) ,
F_47 ( V_58 ) , F_41 ( V_58 ) , F_37 ( V_58 ) ,
F_38 ( V_58 ) ) ;
if ( ( ( V_58 [ 0 ] + V_58 [ 1 ] + V_58 [ 2 ] + V_58 [ 3 ] ) & 0xff ) != 0xff ) {
F_16 ( L_12 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( F_41 ( V_58 ) && F_49 ( V_58 ) != V_5 -> V_39 ) {
F_16 ( L_13 ,
F_49 ( V_58 ) , V_5 -> V_39 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
if ( V_5 -> V_22 != V_25 &&
F_37 ( V_58 ) != V_11 ) {
F_16 ( L_14 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
V_5 -> V_65 = F_46 ;
V_5 -> V_66 = F_38 ( V_58 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned char V_64 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_64 == V_67 )
return 1 ;
V_5 -> V_65 = F_48 ;
V_5 -> V_66 = 4 ;
V_5 -> V_59 = F_51 ( V_68 , V_9 ) ;
if ( ! V_5 -> V_59 ) {
F_16 ( L_15 ) ;
F_23 ( V_5 ) ;
return - V_42 ;
}
V_5 -> V_59 -> V_69 = ( void * ) V_2 -> V_20 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned char V_64 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_64 == V_67 )
V_5 -> V_65 = F_50 ;
return 1 ;
}
static void F_53 ( struct V_5 * V_5 , unsigned char V_64 )
{
const T_2 V_70 = V_67 , V_71 = V_72 ;
const T_2 * V_73 = & V_64 ;
if ( ! F_54 ( V_74 , & V_5 -> V_19 ) && V_64 == V_72 ) {
F_25 ( V_74 , & V_5 -> V_19 ) ;
return;
}
if ( F_55 ( V_74 , & V_5 -> V_19 ) ) {
switch ( V_64 ) {
case V_75 :
V_73 = & V_70 ;
break;
case V_76 :
V_73 = & V_71 ;
break;
default:
F_16 ( L_16 , V_64 ) ;
F_23 ( V_5 ) ;
return;
}
}
memcpy ( F_4 ( V_5 -> V_59 , 1 ) , V_73 , 1 ) ;
V_5 -> V_66 -- ;
F_8 ( L_17 , * V_73 , V_5 -> V_66 ) ;
}
static void F_23 ( struct V_5 * V_5 )
{
if ( V_5 -> V_59 ) {
F_34 ( V_5 -> V_59 ) ;
V_5 -> V_59 = NULL ;
}
V_5 -> V_65 = F_52 ;
V_5 -> V_66 = 0 ;
F_56 ( V_74 , & V_5 -> V_19 ) ;
}
static int F_57 ( struct V_1 * V_2 , const void * V_3 , int V_77 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
const unsigned char * V_78 = V_3 ;
F_8 ( L_18 , V_2 -> V_20 -> V_21 , V_5 -> V_66 ,
V_77 ) ;
while ( V_77 > 0 ) {
int V_79 ;
if ( V_5 -> V_66 > 0 ) {
if ( * V_78 == V_67 ) {
F_16 ( L_19 ) ;
F_23 ( V_5 ) ;
continue;
}
F_53 ( V_5 , * V_78 ) ;
V_78 ++ ; V_77 -- ;
continue;
}
V_79 = V_5 -> V_65 ( V_2 , * V_78 ) ;
if ( V_79 < 0 )
return V_79 ;
V_78 += V_79 ;
V_77 -= V_79 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_7 * V_18 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
if ( V_18 -> V_4 > 0xfff ) {
F_16 ( L_20 , V_18 -> V_4 ) ;
F_34 ( V_18 ) ;
return 0 ;
}
if ( V_5 -> V_22 != V_25 ) {
F_16 ( L_21 ) ;
F_34 ( V_18 ) ;
return 0 ;
}
switch ( F_3 ( V_18 ) -> V_10 ) {
case V_62 :
case V_80 :
F_5 ( & V_5 -> V_38 , V_18 ) ;
break;
case V_63 :
F_5 ( & V_5 -> V_12 , V_18 ) ;
break;
default:
F_16 ( L_22 , F_3 ( V_18 ) -> V_10 ) ;
F_34 ( V_18 ) ;
break;
}
return 0 ;
}
static void F_59 ( struct V_7 * V_18 )
{
const char V_70 = V_67 ;
memcpy ( F_4 ( V_18 , 1 ) , & V_70 , 1 ) ;
}
static void F_60 ( struct V_7 * V_18 , T_2 V_64 )
{
const char V_81 [ 2 ] = { V_72 , V_75 } ;
const char V_82 [ 2 ] = { V_72 , V_76 } ;
switch ( V_64 ) {
case V_67 :
memcpy ( F_4 ( V_18 , 2 ) , & V_81 , 2 ) ;
break;
case V_72 :
memcpy ( F_4 ( V_18 , 2 ) , & V_82 , 2 ) ;
break;
default:
memcpy ( F_4 ( V_18 , 1 ) , & V_64 , 1 ) ;
}
}
static bool F_61 ( T_2 type )
{
switch ( type ) {
case V_62 :
case V_80 :
case V_63 :
case V_11 :
case V_83 :
return true ;
default:
return false ;
}
}
static struct V_7 * F_62 ( struct V_1 * V_2 , T_2 V_10 ,
const T_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
T_2 V_58 [ 4 ] ;
int V_48 ;
if ( ! F_61 ( V_10 ) ) {
F_16 ( L_22 , V_10 ) ;
return NULL ;
}
V_8 = F_2 ( ( V_4 + 6 ) * 2 + 2 , V_9 ) ;
if ( ! V_8 )
return NULL ;
F_3 ( V_8 ) -> V_10 = V_10 ;
F_59 ( V_8 ) ;
V_58 [ 0 ] = V_5 -> V_39 << 3 ;
F_56 ( V_60 , & V_5 -> V_19 ) ;
if ( V_10 == V_62 || V_10 == V_80 ) {
V_58 [ 0 ] |= 1 << 7 ;
V_58 [ 0 ] |= V_5 -> V_37 ;
V_5 -> V_37 = ( V_5 -> V_37 + 1 ) % 8 ;
}
V_58 [ 1 ] = V_10 | ( ( V_4 & 0x0f ) << 4 ) ;
V_58 [ 2 ] = V_4 >> 4 ;
V_58 [ 3 ] = ~ ( ( V_58 [ 0 ] + V_58 [ 1 ] + V_58 [ 2 ] ) & 0xff ) ;
F_8 ( L_23 ,
V_2 -> V_20 -> V_21 , F_49 ( V_58 ) , F_42 ( V_58 ) ,
F_47 ( V_58 ) , F_41 ( V_58 ) , F_37 ( V_58 ) ,
F_38 ( V_58 ) ) ;
for ( V_48 = 0 ; V_48 < 4 ; V_48 ++ )
F_60 ( V_8 , V_58 [ V_48 ] ) ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ )
F_60 ( V_8 , V_3 [ V_48 ] ) ;
F_59 ( V_8 ) ;
return V_8 ;
}
static struct V_7 * F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
unsigned long V_19 ;
struct V_7 * V_18 , * V_8 ;
if ( V_5 -> V_30 != V_31 ) {
const unsigned char V_55 [] = { 0x05 , 0xfa } ;
if ( V_5 -> V_30 == V_84 )
return NULL ;
V_5 -> V_30 = V_84 ;
F_8 ( L_24 ) ;
F_9 ( & V_5 -> V_26 , V_27 + V_85 / 100 ) ;
return F_62 ( V_2 , V_11 , V_55 , 2 ) ;
}
V_18 = F_64 ( & V_5 -> V_12 ) ;
if ( V_18 ) {
V_8 = F_62 ( V_2 , F_3 ( V_18 ) -> V_10 ,
V_18 -> V_3 , V_18 -> V_4 ) ;
if ( V_8 ) {
F_34 ( V_18 ) ;
return V_8 ;
}
F_12 ( & V_5 -> V_12 , V_18 ) ;
F_16 ( L_25 ) ;
}
F_10 ( & V_5 -> V_33 . V_35 , V_19 , V_36 ) ;
if ( V_5 -> V_33 . V_34 >= V_5 -> V_14 )
goto V_51;
V_18 = F_64 ( & V_5 -> V_38 ) ;
if ( V_18 ) {
V_8 = F_62 ( V_2 , F_3 ( V_18 ) -> V_10 ,
V_18 -> V_3 , V_18 -> V_4 ) ;
if ( V_8 ) {
F_65 ( & V_5 -> V_33 , V_18 ) ;
F_9 ( & V_5 -> V_26 , V_27 + V_86 ) ;
F_13 ( & V_5 -> V_33 . V_35 , V_19 ) ;
return V_8 ;
}
F_12 ( & V_5 -> V_38 , V_18 ) ;
F_16 ( L_25 ) ;
}
V_51:
F_13 ( & V_5 -> V_33 . V_35 , V_19 ) ;
if ( F_54 ( V_60 , & V_5 -> V_19 ) )
return F_62 ( V_2 , V_83 , NULL , 0 ) ;
return NULL ;
}
static int F_66 ( struct V_1 * V_2 )
{
F_8 ( L_4 , V_2 ) ;
return 0 ;
}
int T_3 F_67 ( void )
{
return F_68 ( & V_87 ) ;
}
int T_4 F_69 ( void )
{
return F_70 ( & V_87 ) ;
}
