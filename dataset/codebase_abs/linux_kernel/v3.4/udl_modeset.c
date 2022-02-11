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
static char * F_4 ( char * V_1 , bool V_4 )
{
if ( V_4 )
return F_1 ( V_1 , 0x1F , 0x00 ) ;
else
return F_1 ( V_1 , 0x1F , 0x07 ) ;
}
static char * F_5 ( char * V_1 , T_1 V_5 )
{
return F_1 ( V_1 , 0x00 , V_5 ) ;
}
static char * F_6 ( char * V_6 , T_2 V_7 )
{
V_6 = F_1 ( V_6 , 0x20 , V_7 >> 16 ) ;
V_6 = F_1 ( V_6 , 0x21 , V_7 >> 8 ) ;
return F_1 ( V_6 , 0x22 , V_7 ) ;
}
static char * F_7 ( char * V_6 , T_2 V_7 )
{
V_6 = F_1 ( V_6 , 0x26 , V_7 >> 16 ) ;
V_6 = F_1 ( V_6 , 0x27 , V_7 >> 8 ) ;
return F_1 ( V_6 , 0x28 , V_7 ) ;
}
static char * F_8 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
V_6 = F_1 ( V_6 , V_2 , V_8 >> 8 ) ;
return F_1 ( V_6 , V_2 + 1 , V_8 ) ;
}
static char * F_9 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
V_6 = F_1 ( V_6 , V_2 , V_8 ) ;
return F_1 ( V_6 , V_2 + 1 , V_8 >> 8 ) ;
}
static T_3 F_10 ( T_3 V_9 )
{
T_2 V_10 = 0xFFFF ;
while ( V_9 -- ) {
V_10 = ( ( V_10 << 1 ) |
( ( ( V_10 >> 15 ) ^ ( V_10 >> 4 ) ^ ( V_10 >> 2 ) ^ ( V_10 >> 1 ) ) & 1 ) )
& 0xFFFF ;
}
return ( T_3 ) V_10 ;
}
static char * F_11 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
return F_8 ( V_6 , V_2 , F_10 ( V_8 ) ) ;
}
static char * F_12 ( char * V_6 , struct V_11 * V_12 )
{
T_3 V_13 , V_14 ;
T_3 V_15 , V_16 ;
T_3 V_17 ;
V_13 = V_12 -> V_18 - V_12 -> V_19 ;
V_6 = F_11 ( V_6 , 0x01 , V_13 ) ;
V_15 = V_13 + V_12 -> V_20 ;
V_6 = F_11 ( V_6 , 0x03 , V_15 ) ;
V_14 = V_12 -> V_21 - V_12 -> V_22 ;
V_6 = F_11 ( V_6 , 0x05 , V_14 ) ;
V_16 = V_14 + V_12 -> V_23 ;
V_6 = F_11 ( V_6 , 0x07 , V_16 ) ;
V_6 = F_11 ( V_6 , 0x09 ,
V_12 -> V_18 - 1 ) ;
V_6 = F_11 ( V_6 , 0x0B , 1 ) ;
V_6 = F_11 ( V_6 , 0x0D ,
V_12 -> V_24 - V_12 -> V_19 + 1 ) ;
V_6 = F_8 ( V_6 , 0x0F , V_12 -> V_25 ) ;
V_17 = V_12 -> V_21 ;
V_6 = F_11 ( V_6 , 0x11 , V_17 ) ;
V_6 = F_11 ( V_6 , 0x13 , 0 ) ;
V_6 = F_11 ( V_6 , 0x15 , V_12 -> V_26 - V_12 -> V_22 ) ;
V_6 = F_8 ( V_6 , 0x17 , V_12 -> V_23 ) ;
V_6 = F_9 ( V_6 , 0x1B ,
V_12 -> clock / 5 ) ;
return V_6 ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_31 * V_32 = V_30 -> V_33 ;
struct V_34 * V_34 ;
char * V_1 ;
int V_35 ;
V_34 = F_14 ( V_30 ) ;
if ( ! V_34 )
return - V_36 ;
V_1 = ( char * ) V_34 -> V_37 ;
memcpy ( V_1 , V_32 -> V_38 , V_32 -> V_39 ) ;
V_35 = F_15 ( V_30 , V_34 , V_32 -> V_39 ) ;
F_16 ( L_1 , V_32 -> V_39 ) ;
return V_35 ;
}
static void F_17 ( struct V_27 * V_28 , int V_12 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_31 * V_32 = V_30 -> V_33 ;
int V_35 ;
if ( V_12 == V_40 ) {
char * V_1 ;
struct V_34 * V_34 ;
V_34 = F_14 ( V_30 ) ;
if ( ! V_34 )
return;
V_1 = ( char * ) V_34 -> V_37 ;
V_1 = F_2 ( V_1 ) ;
V_1 = F_4 ( V_1 , false ) ;
V_1 = F_3 ( V_1 ) ;
V_35 = F_15 ( V_30 , V_34 , V_1 - ( char * )
V_34 -> V_37 ) ;
} else {
if ( V_32 -> V_39 == 0 ) {
F_18 ( L_2 ) ;
return;
}
F_13 ( V_28 ) ;
}
}
static bool F_19 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
struct V_11 * V_41 )
{
return true ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
struct V_11 * V_41 ,
int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_29 * V_30 = V_28 -> V_30 ;
struct V_46 * V_47 = F_21 ( V_28 -> V_48 ) ;
struct V_31 * V_32 = V_30 -> V_33 ;
char * V_1 ;
char * V_6 ;
int V_49 = 0 ;
V_1 = ( char * ) V_32 -> V_38 ;
V_6 = F_2 ( V_1 ) ;
V_6 = F_5 ( V_6 , V_49 ) ;
V_6 = F_6 ( V_6 , 0 ) ;
V_6 = F_7 ( V_6 , 2 * V_12 -> V_50 * V_12 -> V_25 ) ;
V_6 = F_12 ( V_6 , V_41 ) ;
V_6 = F_4 ( V_6 , true ) ;
V_6 = F_3 ( V_6 ) ;
V_47 -> V_51 = true ;
if ( V_45 ) {
struct V_46 * V_52 = F_21 ( V_45 ) ;
V_52 -> V_51 = false ;
}
V_32 -> V_39 = V_6 - V_1 ;
F_22 ( V_47 , 0 , 0 , V_47 -> V_7 . V_53 , V_47 -> V_7 . V_54 ) ;
return 0 ;
}
static void F_23 ( struct V_27 * V_28 )
{
}
static void F_24 ( struct V_27 * V_28 )
{
F_25 ( V_28 ) ;
F_26 ( V_28 ) ;
}
static void F_27 ( struct V_27 * V_28 )
{
}
static void F_28 ( struct V_27 * V_28 )
{
}
static void F_29 ( struct V_27 * V_28 )
{
F_17 ( V_28 , V_55 ) ;
}
int F_30 ( struct V_29 * V_30 )
{
struct V_27 * V_28 ;
V_28 = F_31 ( sizeof( struct V_27 ) + sizeof( struct V_56 * ) , V_57 ) ;
if ( V_28 == NULL )
return - V_36 ;
F_32 ( V_30 , V_28 , & V_58 ) ;
F_33 ( V_28 , & V_59 ) ;
return 0 ;
}
int F_34 ( struct V_29 * V_30 )
{
struct V_60 * V_61 ;
F_35 ( V_30 ) ;
V_30 -> V_62 . V_63 = 640 ;
V_30 -> V_62 . V_64 = 480 ;
V_30 -> V_62 . V_65 = 2048 ;
V_30 -> V_62 . V_66 = 2048 ;
V_30 -> V_62 . V_67 = 0 ;
V_30 -> V_62 . V_68 = 24 ;
V_30 -> V_62 . V_69 = ( void * ) & V_70 ;
F_36 ( V_30 ) ;
F_30 ( V_30 ) ;
V_61 = F_37 ( V_30 ) ;
F_38 ( V_30 , V_61 ) ;
return 0 ;
}
void F_39 ( struct V_29 * V_30 )
{
F_40 ( V_30 ) ;
}
