static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( ( V_3 ) V_1 << V_4 )
| ( V_2 & ( ( 1 << V_4 ) - 1 ) ) ;
}
void F_2 ( struct V_5 * V_6 )
{
V_6 -> T_1 = F_1 ( V_6 -> V_1 , V_6 -> V_2 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_7 ) ;
V_6 -> V_8 = 0 ;
V_6 -> V_9 = 0 ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
F_6 ( & V_11 -> V_12 ) ;
if ( V_11 -> V_13 == V_14 )
F_7 ( & V_11 -> V_15 , V_16 + V_11 -> V_17 ) ;
F_7 ( & V_11 -> V_18 , V_16 + V_19 / 10 ) ;
F_8 ( V_11 ) ;
F_9 (p, &br->port_list, list) {
if ( F_10 ( V_6 -> V_20 ) && F_11 ( V_6 -> V_20 ) )
F_12 ( V_6 ) ;
}
F_13 ( & V_11 -> V_12 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
F_6 ( & V_11 -> V_12 ) ;
F_9 (p, &br->port_list, list) {
if ( V_6 -> V_21 != V_22 )
F_15 ( V_6 ) ;
}
V_11 -> V_23 = 0 ;
V_11 -> V_24 = 0 ;
F_13 ( & V_11 -> V_12 ) ;
F_16 ( & V_11 -> V_15 ) ;
F_16 ( & V_11 -> V_25 ) ;
F_16 ( & V_11 -> V_26 ) ;
F_16 ( & V_11 -> V_18 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_17 ( V_6 -> V_11 ) ;
F_18 ( V_6 ) ;
F_19 ( V_27 , V_6 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_28 ;
V_28 = F_20 ( V_11 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_22 ) ;
V_6 -> V_8 = 0 ;
V_6 -> V_9 = 0 ;
F_18 ( V_6 ) ;
F_19 ( V_27 , V_6 ) ;
F_21 ( & V_6 -> V_29 ) ;
F_21 ( & V_6 -> V_30 ) ;
F_21 ( & V_6 -> V_31 ) ;
F_22 ( V_11 , V_6 , 0 , 0 ) ;
F_23 ( V_6 ) ;
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_28 )
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_10 * V_11 )
{
int V_32 ;
char * V_33 [] = { V_34 , V_11 -> V_20 -> V_35 , L_1 , NULL } ;
char * V_36 [] = { NULL } ;
struct V_5 * V_6 ;
V_32 = F_27 ( V_34 , V_33 , V_36 , V_37 ) ;
F_6 ( & V_11 -> V_12 ) ;
if ( V_11 -> V_38 < V_39 )
F_28 ( V_11 , V_39 ) ;
else if ( V_11 -> V_38 > V_40 )
F_28 ( V_11 , V_40 ) ;
if ( V_32 == 0 ) {
V_11 -> V_13 = V_41 ;
F_29 ( V_11 , L_2 ) ;
F_21 ( & V_11 -> V_15 ) ;
F_9 (p, &br->port_list, list)
F_21 ( & V_6 -> V_31 ) ;
} else {
V_11 -> V_13 = V_14 ;
F_29 ( V_11 , L_3 ) ;
F_17 ( V_11 ) ;
}
F_13 ( & V_11 -> V_12 ) ;
}
static void F_30 ( struct V_10 * V_11 )
{
int V_32 ;
char * V_33 [] = { V_34 , V_11 -> V_20 -> V_35 , L_4 , NULL } ;
char * V_36 [] = { NULL } ;
struct V_5 * V_6 ;
if ( V_11 -> V_13 == V_41 ) {
V_32 = F_27 ( V_34 , V_33 , V_36 , V_37 ) ;
F_31 ( V_11 , L_5 , V_32 ) ;
F_7 ( & V_11 -> V_15 , V_16 + V_11 -> V_17 ) ;
F_9 (p, &br->port_list, list)
F_7 ( & V_6 -> V_31 ,
F_32 ( V_16 + V_42 ) ) ;
F_6 ( & V_11 -> V_12 ) ;
F_17 ( V_11 ) ;
F_13 ( & V_11 -> V_12 ) ;
}
V_11 -> V_13 = V_43 ;
}
void F_33 ( struct V_10 * V_11 , unsigned long V_44 )
{
F_34 () ;
if ( V_44 ) {
if ( V_11 -> V_13 == V_43 )
F_26 ( V_11 ) ;
} else {
if ( V_11 -> V_13 != V_43 )
F_30 ( V_11 ) ;
}
}
void F_35 ( struct V_10 * V_11 , const unsigned char * V_45 )
{
unsigned short V_46 [ V_47 >> 1 ] ;
unsigned char * V_48 = ( unsigned char * ) V_46 ;
struct V_5 * V_6 ;
int V_28 ;
V_28 = F_20 ( V_11 ) ;
F_36 ( V_11 , V_45 ) ;
memcpy ( V_48 , V_11 -> V_49 . V_45 , V_47 ) ;
memcpy ( V_11 -> V_49 . V_45 , V_45 , V_47 ) ;
memcpy ( V_11 -> V_20 -> V_50 , V_45 , V_47 ) ;
F_9 (p, &br->port_list, list) {
if ( F_37 ( V_6 -> V_51 . V_45 , V_48 ) )
memcpy ( V_6 -> V_51 . V_45 , V_45 , V_47 ) ;
if ( F_37 ( V_6 -> V_52 . V_45 , V_48 ) )
memcpy ( V_6 -> V_52 . V_45 , V_45 , V_47 ) ;
}
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_28 )
F_25 ( V_11 ) ;
}
bool F_38 ( struct V_10 * V_11 )
{
const unsigned char * V_53 =
( const unsigned char * ) V_54 ;
const unsigned char * V_45 = V_53 ;
struct V_5 * V_6 ;
if ( V_11 -> V_20 -> V_55 == V_56 )
return false ;
F_9 (p, &br->port_list, list) {
if ( V_45 == V_53 ||
memcmp ( V_6 -> V_20 -> V_50 , V_45 , V_47 ) < 0 )
V_45 = V_6 -> V_20 -> V_50 ;
}
if ( F_37 ( V_11 -> V_49 . V_45 , V_45 ) )
return false ;
F_35 ( V_11 , V_45 ) ;
return true ;
}
void F_39 ( struct V_10 * V_11 , V_3 V_57 )
{
struct V_5 * V_6 ;
int V_28 ;
F_6 ( & V_11 -> V_12 ) ;
V_28 = F_20 ( V_11 ) ;
F_9 (p, &br->port_list, list) {
if ( V_6 -> V_21 != V_22 &&
F_40 ( V_6 ) ) {
V_6 -> V_51 . V_58 [ 0 ] = ( V_57 >> 8 ) & 0xFF ;
V_6 -> V_51 . V_58 [ 1 ] = V_57 & 0xFF ;
}
}
V_11 -> V_49 . V_58 [ 0 ] = ( V_57 >> 8 ) & 0xFF ;
V_11 -> V_49 . V_58 [ 1 ] = V_57 & 0xFF ;
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_28 )
F_25 ( V_11 ) ;
F_13 ( & V_11 -> V_12 ) ;
}
int F_41 ( struct V_5 * V_6 , unsigned long V_57 )
{
T_1 V_59 ;
if ( V_57 > V_60 )
return - V_61 ;
V_59 = F_1 ( V_57 , V_6 -> V_2 ) ;
if ( F_40 ( V_6 ) )
V_6 -> V_62 = V_59 ;
V_6 -> T_1 = V_59 ;
V_6 -> V_1 = V_57 ;
if ( ! memcmp ( & V_6 -> V_11 -> V_49 , & V_6 -> V_51 , 8 ) &&
V_6 -> T_1 < V_6 -> V_62 ) {
F_3 ( V_6 ) ;
F_17 ( V_6 -> V_11 ) ;
}
return 0 ;
}
int F_42 ( struct V_5 * V_6 , unsigned long V_63 )
{
if ( V_63 < V_64 ||
V_63 > V_65 )
return - V_61 ;
V_6 -> V_66 |= V_67 ;
V_6 -> V_63 = V_63 ;
F_24 ( V_6 -> V_11 ) ;
F_17 ( V_6 -> V_11 ) ;
return 0 ;
}
T_4 F_43 ( char * V_68 , const struct V_49 * V_69 )
{
return sprintf ( V_68 , L_6 ,
V_69 -> V_58 [ 0 ] , V_69 -> V_58 [ 1 ] ,
V_69 -> V_45 [ 0 ] , V_69 -> V_45 [ 1 ] , V_69 -> V_45 [ 2 ] ,
V_69 -> V_45 [ 3 ] , V_69 -> V_45 [ 4 ] , V_69 -> V_45 [ 5 ] ) ;
}
