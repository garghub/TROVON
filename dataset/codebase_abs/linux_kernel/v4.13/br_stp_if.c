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
int V_7 ;
if ( V_12 -> V_16 == V_46 ) {
V_7 = F_30 ( V_12 , L_8 ) ;
if ( V_7 )
F_36 ( V_12 , L_9 , V_7 ) ;
F_8 ( & V_12 -> V_15 ) ;
F_22 ( V_12 ) ;
F_16 ( & V_12 -> V_15 ) ;
}
V_12 -> V_16 = V_49 ;
}
void F_39 ( struct V_14 * V_12 , unsigned long V_50 )
{
F_40 () ;
if ( V_50 ) {
if ( V_12 -> V_16 == V_49 )
F_33 ( V_12 ) ;
} else {
if ( V_12 -> V_16 != V_49 )
F_38 ( V_12 ) ;
}
}
void F_41 ( struct V_14 * V_12 , const unsigned char * V_51 )
{
unsigned short V_52 [ V_53 >> 1 ] ;
unsigned char * V_54 = ( unsigned char * ) V_52 ;
struct V_5 * V_6 ;
int V_30 ;
V_30 = F_24 ( V_12 ) ;
F_42 ( V_12 , V_51 ) ;
memcpy ( V_54 , V_12 -> V_55 . V_51 , V_53 ) ;
memcpy ( V_12 -> V_55 . V_51 , V_51 , V_53 ) ;
memcpy ( V_12 -> V_11 -> V_56 , V_51 , V_53 ) ;
F_12 (p, &br->port_list, list) {
if ( F_43 ( V_6 -> V_57 . V_51 , V_54 ) )
memcpy ( V_6 -> V_57 . V_51 , V_51 , V_53 ) ;
if ( F_43 ( V_6 -> V_58 . V_51 , V_54 ) )
memcpy ( V_6 -> V_58 . V_51 , V_51 , V_53 ) ;
}
F_28 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( F_24 ( V_12 ) && ! V_30 )
F_29 ( V_12 ) ;
}
bool F_44 ( struct V_14 * V_12 )
{
const unsigned char * V_59 =
( const unsigned char * ) V_60 ;
const unsigned char * V_51 = V_59 ;
struct V_5 * V_6 ;
if ( V_12 -> V_11 -> V_61 == V_62 )
return false ;
F_12 (p, &br->port_list, list) {
if ( V_51 == V_59 ||
memcmp ( V_6 -> V_11 -> V_56 , V_51 , V_53 ) < 0 )
V_51 = V_6 -> V_11 -> V_56 ;
}
if ( F_43 ( V_12 -> V_55 . V_51 , V_51 ) )
return false ;
F_41 ( V_12 , V_51 ) ;
return true ;
}
void F_45 ( struct V_14 * V_12 , V_3 V_63 )
{
struct V_5 * V_6 ;
int V_30 ;
F_8 ( & V_12 -> V_15 ) ;
V_30 = F_24 ( V_12 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_24 != V_25 &&
F_46 ( V_6 ) ) {
V_6 -> V_57 . V_64 [ 0 ] = ( V_63 >> 8 ) & 0xFF ;
V_6 -> V_57 . V_64 [ 1 ] = V_63 & 0xFF ;
}
}
V_12 -> V_55 . V_64 [ 0 ] = ( V_63 >> 8 ) & 0xFF ;
V_12 -> V_55 . V_64 [ 1 ] = V_63 & 0xFF ;
F_28 ( V_12 ) ;
F_22 ( V_12 ) ;
if ( F_24 ( V_12 ) && ! V_30 )
F_29 ( V_12 ) ;
F_16 ( & V_12 -> V_15 ) ;
}
int F_47 ( struct V_5 * V_6 , unsigned long V_63 )
{
T_1 V_65 ;
if ( V_63 > V_66 )
return - V_67 ;
V_65 = F_1 ( V_63 , V_6 -> V_2 ) ;
if ( F_46 ( V_6 ) )
V_6 -> V_68 = V_65 ;
V_6 -> T_1 = V_65 ;
V_6 -> V_1 = V_63 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_55 , & V_6 -> V_57 , 8 ) &&
V_6 -> T_1 < V_6 -> V_68 ) {
F_3 ( V_6 ) ;
F_22 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_48 ( struct V_5 * V_6 , unsigned long V_69 )
{
if ( V_69 < V_70 ||
V_69 > V_71 )
return - V_67 ;
V_6 -> V_47 |= V_72 ;
V_6 -> V_69 = V_69 ;
F_28 ( V_6 -> V_12 ) ;
F_22 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_49 ( char * V_73 , const struct V_55 * V_74 )
{
return sprintf ( V_73 , L_10 ,
V_74 -> V_64 [ 0 ] , V_74 -> V_64 [ 1 ] ,
V_74 -> V_51 [ 0 ] , V_74 -> V_51 [ 1 ] , V_74 -> V_51 [ 2 ] ,
V_74 -> V_51 [ 3 ] , V_74 -> V_51 [ 4 ] , V_74 -> V_51 [ 5 ] ) ;
}
