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
F_10 ( V_21 , & V_12 -> V_22 , V_23 / 10 ) ;
F_11 ( V_12 ) ;
F_12 (p, &br->port_list, list) {
if ( F_13 ( V_6 -> V_11 ) && F_14 ( V_6 -> V_11 ) )
F_15 ( V_6 ) ;
}
F_16 ( & V_12 -> V_15 ) ;
}
void F_17 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
F_8 ( & V_12 -> V_15 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_24 != V_25 )
F_18 ( V_6 ) ;
}
F_19 ( V_12 , 0 ) ;
V_12 -> V_26 = 0 ;
F_16 ( & V_12 -> V_15 ) ;
F_20 ( & V_12 -> V_18 ) ;
F_20 ( & V_12 -> V_27 ) ;
F_20 ( & V_12 -> V_28 ) ;
F_21 ( & V_12 -> V_22 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_22 ( V_6 -> V_12 ) ;
F_23 ( V_29 , V_6 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_14 * V_12 = V_6 -> V_12 ;
int V_30 ;
V_30 = F_24 ( V_12 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_25 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
F_23 ( V_29 , V_6 ) ;
F_25 ( & V_6 -> V_31 ) ;
F_25 ( & V_6 -> V_32 ) ;
F_25 ( & V_6 -> V_33 ) ;
F_26 ( V_12 , V_6 , 0 , 0 ) ;
F_27 ( V_6 ) ;
F_28 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( F_24 ( V_12 ) && ! V_30 )
F_29 ( V_12 ) ;
}
static int F_30 ( struct V_14 * V_12 , char * V_34 )
{
char * V_35 [] = { V_36 , V_12 -> V_11 -> V_37 , V_34 , NULL } ;
char * V_38 [] = { NULL } ;
int V_39 ;
V_39 = F_31 ( V_36 , V_35 , V_38 , V_40 ) ;
if ( V_39 > 0 ) {
if ( V_39 & 0xff )
F_32 ( V_12 , V_36 L_2 ,
V_39 & 0x7f ) ;
else
F_32 ( V_12 , V_36 L_3 ,
( V_39 >> 8 ) & 0xff ) ;
}
return V_39 ;
}
static void F_33 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
int V_7 = - V_41 ;
if ( F_34 ( F_35 ( V_12 -> V_11 ) , & V_42 ) )
V_7 = F_30 ( V_12 , L_4 ) ;
if ( V_7 && V_7 != - V_41 )
F_36 ( V_12 , L_5 , V_7 ) ;
F_8 ( & V_12 -> V_15 ) ;
if ( V_12 -> V_43 < V_44 )
F_37 ( V_12 , V_44 ) ;
else if ( V_12 -> V_43 > V_45 )
F_37 ( V_12 , V_45 ) ;
if ( ! V_7 ) {
V_12 -> V_16 = V_46 ;
F_32 ( V_12 , L_6 ) ;
F_25 ( & V_12 -> V_18 ) ;
F_12 (p, &br->port_list, list)
F_25 ( & V_6 -> V_33 ) ;
} else {
V_12 -> V_16 = V_17 ;
F_32 ( V_12 , L_7 ) ;
if ( V_12 -> V_11 -> V_47 & V_48 )
F_9 ( & V_12 -> V_18 , V_19 + V_12 -> V_20 ) ;
F_22 ( V_12 ) ;
}
F_16 ( & V_12 -> V_15 ) ;
}
static void F_38 ( struct V_14 * V_12 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( V_12 -> V_16 == V_46 ) {
V_7 = F_30 ( V_12 , L_8 ) ;
if ( V_7 )
F_36 ( V_12 , L_9 , V_7 ) ;
F_9 ( & V_12 -> V_18 , V_19 + V_12 -> V_20 ) ;
F_12 (p, &br->port_list, list)
F_9 ( & V_6 -> V_33 ,
F_39 ( V_19 + V_49 ) ) ;
F_8 ( & V_12 -> V_15 ) ;
F_22 ( V_12 ) ;
F_16 ( & V_12 -> V_15 ) ;
}
V_12 -> V_16 = V_50 ;
}
void F_40 ( struct V_14 * V_12 , unsigned long V_51 )
{
F_41 () ;
if ( V_51 ) {
if ( V_12 -> V_16 == V_50 )
F_33 ( V_12 ) ;
} else {
if ( V_12 -> V_16 != V_50 )
F_38 ( V_12 ) ;
}
}
void F_42 ( struct V_14 * V_12 , const unsigned char * V_52 )
{
unsigned short V_53 [ V_54 >> 1 ] ;
unsigned char * V_55 = ( unsigned char * ) V_53 ;
struct V_5 * V_6 ;
int V_30 ;
V_30 = F_24 ( V_12 ) ;
F_43 ( V_12 , V_52 ) ;
memcpy ( V_55 , V_12 -> V_56 . V_52 , V_54 ) ;
memcpy ( V_12 -> V_56 . V_52 , V_52 , V_54 ) ;
memcpy ( V_12 -> V_11 -> V_57 , V_52 , V_54 ) ;
F_12 (p, &br->port_list, list) {
if ( F_44 ( V_6 -> V_58 . V_52 , V_55 ) )
memcpy ( V_6 -> V_58 . V_52 , V_52 , V_54 ) ;
if ( F_44 ( V_6 -> V_59 . V_52 , V_55 ) )
memcpy ( V_6 -> V_59 . V_52 , V_52 , V_54 ) ;
}
F_28 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( F_24 ( V_12 ) && ! V_30 )
F_29 ( V_12 ) ;
}
bool F_45 ( struct V_14 * V_12 )
{
const unsigned char * V_60 =
( const unsigned char * ) V_61 ;
const unsigned char * V_52 = V_60 ;
struct V_5 * V_6 ;
if ( V_12 -> V_11 -> V_62 == V_63 )
return false ;
F_12 (p, &br->port_list, list) {
if ( V_52 == V_60 ||
memcmp ( V_6 -> V_11 -> V_57 , V_52 , V_54 ) < 0 )
V_52 = V_6 -> V_11 -> V_57 ;
}
if ( F_44 ( V_12 -> V_56 . V_52 , V_52 ) )
return false ;
F_42 ( V_12 , V_52 ) ;
return true ;
}
void F_46 ( struct V_14 * V_12 , V_3 V_64 )
{
struct V_5 * V_6 ;
int V_30 ;
F_8 ( & V_12 -> V_15 ) ;
V_30 = F_24 ( V_12 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_24 != V_25 &&
F_47 ( V_6 ) ) {
V_6 -> V_58 . V_65 [ 0 ] = ( V_64 >> 8 ) & 0xFF ;
V_6 -> V_58 . V_65 [ 1 ] = V_64 & 0xFF ;
}
}
V_12 -> V_56 . V_65 [ 0 ] = ( V_64 >> 8 ) & 0xFF ;
V_12 -> V_56 . V_65 [ 1 ] = V_64 & 0xFF ;
F_28 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( F_24 ( V_12 ) && ! V_30 )
F_29 ( V_12 ) ;
F_16 ( & V_12 -> V_15 ) ;
}
int F_48 ( struct V_5 * V_6 , unsigned long V_64 )
{
T_1 V_66 ;
if ( V_64 > V_67 )
return - V_68 ;
V_66 = F_1 ( V_64 , V_6 -> V_2 ) ;
if ( F_47 ( V_6 ) )
V_6 -> V_69 = V_66 ;
V_6 -> T_1 = V_66 ;
V_6 -> V_1 = V_64 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_56 , & V_6 -> V_58 , 8 ) &&
V_6 -> T_1 < V_6 -> V_69 ) {
F_3 ( V_6 ) ;
F_22 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_49 ( struct V_5 * V_6 , unsigned long V_70 )
{
if ( V_70 < V_71 ||
V_70 > V_72 )
return - V_68 ;
V_6 -> V_47 |= V_73 ;
V_6 -> V_70 = V_70 ;
F_28 ( V_6 -> V_12 ) ;
F_22 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_50 ( char * V_74 , const struct V_56 * V_75 )
{
return sprintf ( V_74 , L_10 ,
V_75 -> V_65 [ 0 ] , V_75 -> V_65 [ 1 ] ,
V_75 -> V_52 [ 0 ] , V_75 -> V_52 [ 1 ] , V_75 -> V_52 [ 2 ] ,
V_75 -> V_52 [ 3 ] , V_75 -> V_52 [ 4 ] , V_75 -> V_52 [ 5 ] ) ;
}
