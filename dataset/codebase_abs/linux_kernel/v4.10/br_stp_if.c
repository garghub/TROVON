static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( ( V_3 ) V_1 << V_4 )
| ( V_2 & ( ( 1 << V_4 ) - 1 ) ) ;
}
void F_2 ( struct V_5 * V_6 )
{
int V_7 ;
V_6 -> T_1 = F_1 ( V_6 -> V_1 , V_6 -> V_2 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_7 = F_5 ( V_6 -> V_11 , V_6 -> V_12 -> V_13 ) ;
if ( V_7 )
F_6 ( V_6 -> V_11 , L_1 ) ;
}
void F_7 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
F_8 ( & V_12 -> V_15 ) ;
if ( V_12 -> V_16 == V_17 )
F_9 ( & V_12 -> V_18 , V_19 + V_12 -> V_20 ) ;
F_9 ( & V_12 -> V_21 , V_19 + V_22 / 10 ) ;
F_10 ( V_12 ) ;
F_11 (p, &br->port_list, list) {
if ( F_12 ( V_6 -> V_11 ) && F_13 ( V_6 -> V_11 ) )
F_14 ( V_6 ) ;
}
F_15 ( & V_12 -> V_15 ) ;
}
void F_16 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
F_8 ( & V_12 -> V_15 ) ;
F_11 (p, &br->port_list, list) {
if ( V_6 -> V_23 != V_24 )
F_17 ( V_6 ) ;
}
F_18 ( V_12 , 0 ) ;
V_12 -> V_25 = 0 ;
F_15 ( & V_12 -> V_15 ) ;
F_19 ( & V_12 -> V_18 ) ;
F_19 ( & V_12 -> V_26 ) ;
F_19 ( & V_12 -> V_27 ) ;
F_19 ( & V_12 -> V_21 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_20 ( V_6 -> V_12 ) ;
F_21 ( V_28 , V_6 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_14 * V_12 = V_6 -> V_12 ;
int V_29 ;
V_29 = F_22 ( V_12 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_24 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
F_21 ( V_28 , V_6 ) ;
F_23 ( & V_6 -> V_30 ) ;
F_23 ( & V_6 -> V_31 ) ;
F_23 ( & V_6 -> V_32 ) ;
F_24 ( V_12 , V_6 , 0 , 0 ) ;
F_25 ( V_6 ) ;
F_26 ( V_12 ) ;
F_20 ( V_12 ) ;
if ( F_22 ( V_12 ) && ! V_29 )
F_27 ( V_12 ) ;
}
static int F_28 ( struct V_14 * V_12 , char * V_33 )
{
char * V_34 [] = { V_35 , V_12 -> V_11 -> V_36 , V_33 , NULL } ;
char * V_37 [] = { NULL } ;
int V_38 ;
V_38 = F_29 ( V_35 , V_34 , V_37 , V_39 ) ;
if ( V_38 > 0 ) {
if ( V_38 & 0xff )
F_30 ( V_12 , V_35 L_2 ,
V_38 & 0x7f ) ;
else
F_30 ( V_12 , V_35 L_3 ,
( V_38 >> 8 ) & 0xff ) ;
}
return V_38 ;
}
static void F_31 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
int V_7 = - V_40 ;
if ( F_32 ( F_33 ( V_12 -> V_11 ) , & V_41 ) )
V_7 = F_28 ( V_12 , L_4 ) ;
if ( V_7 && V_7 != - V_40 )
F_34 ( V_12 , L_5 , V_7 ) ;
F_8 ( & V_12 -> V_15 ) ;
if ( V_12 -> V_42 < V_43 )
F_35 ( V_12 , V_43 ) ;
else if ( V_12 -> V_42 > V_44 )
F_35 ( V_12 , V_44 ) ;
if ( ! V_7 ) {
V_12 -> V_16 = V_45 ;
F_30 ( V_12 , L_6 ) ;
F_23 ( & V_12 -> V_18 ) ;
F_11 (p, &br->port_list, list)
F_23 ( & V_6 -> V_32 ) ;
} else {
V_12 -> V_16 = V_17 ;
F_30 ( V_12 , L_7 ) ;
F_20 ( V_12 ) ;
}
F_15 ( & V_12 -> V_15 ) ;
}
static void F_36 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( V_12 -> V_16 == V_45 ) {
V_7 = F_28 ( V_12 , L_8 ) ;
if ( V_7 )
F_34 ( V_12 , L_9 , V_7 ) ;
F_9 ( & V_12 -> V_18 , V_19 + V_12 -> V_20 ) ;
F_11 (p, &br->port_list, list)
F_9 ( & V_6 -> V_32 ,
F_37 ( V_19 + V_46 ) ) ;
F_8 ( & V_12 -> V_15 ) ;
F_20 ( V_12 ) ;
F_15 ( & V_12 -> V_15 ) ;
}
V_12 -> V_16 = V_47 ;
}
void F_38 ( struct V_14 * V_12 , unsigned long V_48 )
{
F_39 () ;
if ( V_48 ) {
if ( V_12 -> V_16 == V_47 )
F_31 ( V_12 ) ;
} else {
if ( V_12 -> V_16 != V_47 )
F_36 ( V_12 ) ;
}
}
void F_40 ( struct V_14 * V_12 , const unsigned char * V_49 )
{
unsigned short V_50 [ V_51 >> 1 ] ;
unsigned char * V_52 = ( unsigned char * ) V_50 ;
struct V_5 * V_6 ;
int V_29 ;
V_29 = F_22 ( V_12 ) ;
F_41 ( V_12 , V_49 ) ;
memcpy ( V_52 , V_12 -> V_53 . V_49 , V_51 ) ;
memcpy ( V_12 -> V_53 . V_49 , V_49 , V_51 ) ;
memcpy ( V_12 -> V_11 -> V_54 , V_49 , V_51 ) ;
F_11 (p, &br->port_list, list) {
if ( F_42 ( V_6 -> V_55 . V_49 , V_52 ) )
memcpy ( V_6 -> V_55 . V_49 , V_49 , V_51 ) ;
if ( F_42 ( V_6 -> V_56 . V_49 , V_52 ) )
memcpy ( V_6 -> V_56 . V_49 , V_49 , V_51 ) ;
}
F_26 ( V_12 ) ;
F_20 ( V_12 ) ;
if ( F_22 ( V_12 ) && ! V_29 )
F_27 ( V_12 ) ;
}
bool F_43 ( struct V_14 * V_12 )
{
const unsigned char * V_57 =
( const unsigned char * ) V_58 ;
const unsigned char * V_49 = V_57 ;
struct V_5 * V_6 ;
if ( V_12 -> V_11 -> V_59 == V_60 )
return false ;
F_11 (p, &br->port_list, list) {
if ( V_49 == V_57 ||
memcmp ( V_6 -> V_11 -> V_54 , V_49 , V_51 ) < 0 )
V_49 = V_6 -> V_11 -> V_54 ;
}
if ( F_42 ( V_12 -> V_53 . V_49 , V_49 ) )
return false ;
F_40 ( V_12 , V_49 ) ;
return true ;
}
void F_44 ( struct V_14 * V_12 , V_3 V_61 )
{
struct V_5 * V_6 ;
int V_29 ;
F_8 ( & V_12 -> V_15 ) ;
V_29 = F_22 ( V_12 ) ;
F_11 (p, &br->port_list, list) {
if ( V_6 -> V_23 != V_24 &&
F_45 ( V_6 ) ) {
V_6 -> V_55 . V_62 [ 0 ] = ( V_61 >> 8 ) & 0xFF ;
V_6 -> V_55 . V_62 [ 1 ] = V_61 & 0xFF ;
}
}
V_12 -> V_53 . V_62 [ 0 ] = ( V_61 >> 8 ) & 0xFF ;
V_12 -> V_53 . V_62 [ 1 ] = V_61 & 0xFF ;
F_26 ( V_12 ) ;
F_20 ( V_12 ) ;
if ( F_22 ( V_12 ) && ! V_29 )
F_27 ( V_12 ) ;
F_15 ( & V_12 -> V_15 ) ;
}
int F_46 ( struct V_5 * V_6 , unsigned long V_61 )
{
T_1 V_63 ;
if ( V_61 > V_64 )
return - V_65 ;
V_63 = F_1 ( V_61 , V_6 -> V_2 ) ;
if ( F_45 ( V_6 ) )
V_6 -> V_66 = V_63 ;
V_6 -> T_1 = V_63 ;
V_6 -> V_1 = V_61 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_53 , & V_6 -> V_55 , 8 ) &&
V_6 -> T_1 < V_6 -> V_66 ) {
F_3 ( V_6 ) ;
F_20 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 , unsigned long V_67 )
{
if ( V_67 < V_68 ||
V_67 > V_69 )
return - V_65 ;
V_6 -> V_70 |= V_71 ;
V_6 -> V_67 = V_67 ;
F_26 ( V_6 -> V_12 ) ;
F_20 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_48 ( char * V_72 , const struct V_53 * V_73 )
{
return sprintf ( V_72 , L_10 ,
V_73 -> V_62 [ 0 ] , V_73 -> V_62 [ 1 ] ,
V_73 -> V_49 [ 0 ] , V_73 -> V_49 [ 1 ] , V_73 -> V_49 [ 2 ] ,
V_73 -> V_49 [ 3 ] , V_73 -> V_49 [ 4 ] , V_73 -> V_49 [ 5 ] ) ;
}
