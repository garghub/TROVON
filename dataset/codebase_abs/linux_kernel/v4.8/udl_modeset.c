static char * F_1 ( char * V_1 , T_1 V_2 , T_1 V_3 )
{
* V_1 ++ = 0xAF ;
* V_1 ++ = 0x20 ;
* V_1 ++ = V_2 ;
* V_1 ++ = V_3 ;
return V_1 ;
}
static char * F_2 ( char * V_1 )
{
return F_1 ( V_1 , 0xFF , 0x00 ) ;
}
static char * F_3 ( char * V_1 )
{
return F_1 ( V_1 , 0xFF , 0xFF ) ;
}
static char * F_4 ( char * V_1 , int V_4 )
{
T_1 V_2 ;
switch ( V_4 ) {
case V_5 :
V_2 = 0x07 ;
break;
case V_6 :
V_2 = 0x05 ;
break;
case V_7 :
V_2 = 0x01 ;
break;
case V_8 :
V_2 = 0x00 ;
break;
}
return F_1 ( V_1 , 0x1f , V_2 ) ;
}
static char * F_5 ( char * V_1 , T_1 V_9 )
{
return F_1 ( V_1 , 0x00 , V_9 ) ;
}
static char * F_6 ( char * V_10 , T_2 V_11 )
{
V_10 = F_1 ( V_10 , 0x20 , V_11 >> 16 ) ;
V_10 = F_1 ( V_10 , 0x21 , V_11 >> 8 ) ;
return F_1 ( V_10 , 0x22 , V_11 ) ;
}
static char * F_7 ( char * V_10 , T_2 V_11 )
{
V_10 = F_1 ( V_10 , 0x26 , V_11 >> 16 ) ;
V_10 = F_1 ( V_10 , 0x27 , V_11 >> 8 ) ;
return F_1 ( V_10 , 0x28 , V_11 ) ;
}
static char * F_8 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
V_10 = F_1 ( V_10 , V_2 , V_12 >> 8 ) ;
return F_1 ( V_10 , V_2 + 1 , V_12 ) ;
}
static char * F_9 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
V_10 = F_1 ( V_10 , V_2 , V_12 ) ;
return F_1 ( V_10 , V_2 + 1 , V_12 >> 8 ) ;
}
static T_3 F_10 ( T_3 V_13 )
{
T_2 V_14 = 0xFFFF ;
while ( V_13 -- ) {
V_14 = ( ( V_14 << 1 ) |
( ( ( V_14 >> 15 ) ^ ( V_14 >> 4 ) ^ ( V_14 >> 2 ) ^ ( V_14 >> 1 ) ) & 1 ) )
& 0xFFFF ;
}
return ( T_3 ) V_14 ;
}
static char * F_11 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
return F_8 ( V_10 , V_2 , F_10 ( V_12 ) ) ;
}
static char * F_12 ( char * V_10 , struct V_15 * V_16 )
{
T_3 V_17 , V_18 ;
T_3 V_19 , V_20 ;
T_3 V_21 ;
V_17 = V_16 -> V_22 - V_16 -> V_23 ;
V_10 = F_11 ( V_10 , 0x01 , V_17 ) ;
V_19 = V_17 + V_16 -> V_24 ;
V_10 = F_11 ( V_10 , 0x03 , V_19 ) ;
V_18 = V_16 -> V_25 - V_16 -> V_26 ;
V_10 = F_11 ( V_10 , 0x05 , V_18 ) ;
V_20 = V_18 + V_16 -> V_27 ;
V_10 = F_11 ( V_10 , 0x07 , V_20 ) ;
V_10 = F_11 ( V_10 , 0x09 ,
V_16 -> V_22 - 1 ) ;
V_10 = F_11 ( V_10 , 0x0B , 1 ) ;
V_10 = F_11 ( V_10 , 0x0D ,
V_16 -> V_28 - V_16 -> V_23 + 1 ) ;
V_10 = F_8 ( V_10 , 0x0F , V_16 -> V_29 ) ;
V_21 = V_16 -> V_25 ;
V_10 = F_11 ( V_10 , 0x11 , V_21 ) ;
V_10 = F_11 ( V_10 , 0x13 , 0 ) ;
V_10 = F_11 ( V_10 , 0x15 , V_16 -> V_30 - V_16 -> V_26 ) ;
V_10 = F_8 ( V_10 , 0x17 , V_16 -> V_27 ) ;
V_10 = F_9 ( V_10 , 0x1B ,
V_16 -> clock / 5 ) ;
return V_10 ;
}
static char * F_13 ( char * V_10 )
{
* V_10 ++ = 0xAF ;
* V_10 ++ = 0x6A ;
* V_10 ++ = 0x00 ;
* V_10 ++ = 0x00 ;
* V_10 ++ = 0x00 ;
* V_10 ++ = 0x01 ;
* V_10 ++ = 0x00 ;
* V_10 ++ = 0x00 ;
* V_10 ++ = 0x00 ;
return V_10 ;
}
static int F_14 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_38 * V_38 ;
char * V_1 ;
int V_39 ;
V_38 = F_15 ( V_34 ) ;
if ( ! V_38 )
return - V_40 ;
V_1 = ( char * ) V_38 -> V_41 ;
memcpy ( V_1 , V_36 -> V_42 , V_36 -> V_43 ) ;
V_39 = F_16 ( V_34 , V_38 , V_36 -> V_43 ) ;
F_17 ( L_1 , V_36 -> V_43 ) ;
return V_39 ;
}
static void F_18 ( struct V_31 * V_32 , int V_16 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_35 * V_36 = V_34 -> V_37 ;
int V_39 ;
if ( V_16 == V_5 ) {
char * V_1 ;
struct V_38 * V_38 ;
V_38 = F_15 ( V_34 ) ;
if ( ! V_38 )
return;
V_1 = ( char * ) V_38 -> V_41 ;
V_1 = F_2 ( V_1 ) ;
V_1 = F_4 ( V_1 , V_16 ) ;
V_1 = F_3 ( V_1 ) ;
V_1 = F_13 ( V_1 ) ;
V_39 = F_16 ( V_34 , V_38 , V_1 - ( char * )
V_38 -> V_41 ) ;
} else {
if ( V_36 -> V_43 == 0 ) {
F_19 ( L_2 ) ;
return;
}
F_14 ( V_32 ) ;
}
}
static int F_20 ( struct V_31 * V_32 ,
struct V_15 * V_16 ,
struct V_15 * V_44 ,
int V_45 , int V_46 ,
struct V_47 * V_48 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_49 * V_50 = F_21 ( V_32 -> V_51 -> V_52 ) ;
struct V_35 * V_36 = V_34 -> V_37 ;
char * V_1 ;
char * V_10 ;
int V_53 = 0 ;
V_1 = ( char * ) V_36 -> V_42 ;
V_10 = F_2 ( V_1 ) ;
V_10 = F_5 ( V_10 , V_53 ) ;
V_10 = F_6 ( V_10 , 0 ) ;
V_10 = F_7 ( V_10 , 2 * V_16 -> V_54 * V_16 -> V_29 ) ;
V_10 = F_12 ( V_10 , V_44 ) ;
V_10 = F_4 ( V_10 , V_8 ) ;
V_10 = F_3 ( V_10 ) ;
V_10 = F_13 ( V_10 ) ;
if ( V_48 ) {
struct V_49 * V_55 = F_21 ( V_48 ) ;
V_55 -> V_56 = false ;
}
V_50 -> V_56 = true ;
V_36 -> V_43 = V_10 - V_1 ;
F_22 ( V_50 , 0 , 0 , V_50 -> V_11 . V_57 , V_50 -> V_11 . V_58 ) ;
return 0 ;
}
static void F_23 ( struct V_31 * V_32 )
{
F_18 ( V_32 , V_5 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
F_25 ( V_32 ) ;
F_26 ( V_32 ) ;
}
static int F_27 ( struct V_31 * V_32 ,
struct V_47 * V_52 ,
struct V_59 * V_60 ,
T_4 V_61 )
{
struct V_49 * V_50 = F_21 ( V_52 ) ;
struct V_33 * V_34 = V_32 -> V_34 ;
unsigned long V_62 ;
struct V_47 * V_48 = V_32 -> V_51 -> V_52 ;
if ( V_48 ) {
struct V_49 * V_55 = F_21 ( V_48 ) ;
V_55 -> V_56 = false ;
}
V_50 -> V_56 = true ;
F_22 ( V_50 , 0 , 0 , V_52 -> V_57 , V_52 -> V_58 ) ;
F_28 ( & V_34 -> V_63 , V_62 ) ;
if ( V_60 )
F_29 ( V_32 , V_60 ) ;
F_30 ( & V_34 -> V_63 , V_62 ) ;
V_32 -> V_51 -> V_52 = V_52 ;
return 0 ;
}
static void F_31 ( struct V_31 * V_32 )
{
}
static void F_32 ( struct V_31 * V_32 )
{
F_18 ( V_32 , V_8 ) ;
}
static int F_33 ( struct V_33 * V_34 )
{
struct V_31 * V_32 ;
V_32 = F_34 ( sizeof( struct V_31 ) + sizeof( struct V_64 * ) , V_65 ) ;
if ( V_32 == NULL )
return - V_40 ;
F_35 ( V_34 , V_32 , & V_66 ) ;
F_36 ( V_32 , & V_67 ) ;
return 0 ;
}
int F_37 ( struct V_33 * V_34 )
{
struct V_68 * V_69 ;
F_38 ( V_34 ) ;
V_34 -> V_70 . V_71 = 640 ;
V_34 -> V_70 . V_72 = 480 ;
V_34 -> V_70 . V_73 = 2048 ;
V_34 -> V_70 . V_74 = 2048 ;
V_34 -> V_70 . V_75 = 0 ;
V_34 -> V_70 . V_76 = 24 ;
V_34 -> V_70 . V_77 = & V_78 ;
F_39 ( V_34 ) ;
F_33 ( V_34 ) ;
V_69 = F_40 ( V_34 ) ;
F_41 ( V_34 , V_69 ) ;
return 0 ;
}
void F_42 ( struct V_33 * V_34 )
{
F_43 ( V_34 ) ;
}
