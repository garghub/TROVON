static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( ( V_3 ) V_1 << V_4 )
| ( V_2 & ( ( 1 << V_4 ) - 1 ) ) ;
}
void F_2 ( struct V_5 * V_6 )
{
V_6 -> T_1 = F_1 ( V_6 -> V_1 , V_6 -> V_2 ) ;
F_3 ( V_6 ) ;
V_6 -> V_7 = V_8 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
}
void F_4 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
F_5 ( & V_12 -> V_13 ) ;
F_6 ( & V_12 -> V_14 , V_15 + V_12 -> V_16 ) ;
F_6 ( & V_12 -> V_17 , V_15 + V_18 / 10 ) ;
F_7 ( V_12 ) ;
F_8 (p, &br->port_list, list) {
if ( ( V_6 -> V_19 -> V_20 & V_21 ) && F_9 ( V_6 -> V_19 ) )
F_10 ( V_6 ) ;
}
F_11 ( & V_12 -> V_13 ) ;
}
void F_12 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
F_5 ( & V_12 -> V_13 ) ;
F_8 (p, &br->port_list, list) {
if ( V_6 -> V_7 != V_22 )
F_13 ( V_6 ) ;
}
V_12 -> V_23 = 0 ;
V_12 -> V_24 = 0 ;
F_11 ( & V_12 -> V_13 ) ;
F_14 ( & V_12 -> V_14 ) ;
F_14 ( & V_12 -> V_25 ) ;
F_14 ( & V_12 -> V_26 ) ;
F_14 ( & V_12 -> V_17 ) ;
}
void F_10 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_15 ( V_6 -> V_12 ) ;
F_16 ( V_6 ) ;
}
void F_13 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
int V_27 ;
F_16 ( V_6 ) ;
V_27 = F_17 ( V_12 ) ;
F_3 ( V_6 ) ;
V_6 -> V_7 = V_22 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
F_18 ( & V_6 -> V_28 ) ;
F_18 ( & V_6 -> V_29 ) ;
F_18 ( & V_6 -> V_30 ) ;
F_19 ( V_12 , V_6 , 0 ) ;
F_20 ( V_6 ) ;
F_21 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_17 ( V_12 ) && ! V_27 )
F_22 ( V_12 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
int V_31 ;
char * V_32 [] = { V_33 , V_12 -> V_19 -> V_34 , L_1 , NULL } ;
char * V_35 [] = { NULL } ;
V_31 = F_24 ( V_33 , V_32 , V_35 , V_36 ) ;
if ( V_31 == 0 ) {
V_12 -> V_37 = V_38 ;
F_25 ( V_12 , L_2 ) ;
} else {
V_12 -> V_37 = V_39 ;
F_25 ( V_12 , L_3 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_15 ( V_12 ) ;
F_11 ( & V_12 -> V_13 ) ;
}
}
static void F_26 ( struct V_11 * V_12 )
{
int V_31 ;
char * V_32 [] = { V_33 , V_12 -> V_19 -> V_34 , L_4 , NULL } ;
char * V_35 [] = { NULL } ;
if ( V_12 -> V_37 == V_38 ) {
V_31 = F_24 ( V_33 , V_32 , V_35 , V_36 ) ;
F_27 ( V_12 , L_5 , V_31 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_15 ( V_12 ) ;
F_11 ( & V_12 -> V_13 ) ;
}
V_12 -> V_37 = V_40 ;
}
void F_28 ( struct V_11 * V_12 , unsigned long V_41 )
{
F_29 () ;
if ( V_41 ) {
if ( V_12 -> V_37 == V_40 )
F_23 ( V_12 ) ;
} else {
if ( V_12 -> V_37 != V_40 )
F_26 ( V_12 ) ;
}
}
void F_30 ( struct V_11 * V_12 , const unsigned char * V_42 )
{
unsigned short V_43 [ V_44 >> 1 ] ;
unsigned char * V_45 = ( unsigned char * ) V_43 ;
struct V_5 * V_6 ;
int V_27 ;
V_27 = F_17 ( V_12 ) ;
memcpy ( V_45 , V_12 -> V_46 . V_42 , V_44 ) ;
memcpy ( V_12 -> V_46 . V_42 , V_42 , V_44 ) ;
memcpy ( V_12 -> V_19 -> V_47 , V_42 , V_44 ) ;
F_8 (p, &br->port_list, list) {
if ( ! F_31 ( V_6 -> V_48 . V_42 , V_45 ) )
memcpy ( V_6 -> V_48 . V_42 , V_42 , V_44 ) ;
if ( ! F_31 ( V_6 -> V_49 . V_42 , V_45 ) )
memcpy ( V_6 -> V_49 . V_42 , V_42 , V_44 ) ;
}
F_21 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_17 ( V_12 ) && ! V_27 )
F_22 ( V_12 ) ;
}
bool F_32 ( struct V_11 * V_12 )
{
const unsigned char * V_50 =
( const unsigned char * ) V_51 ;
const unsigned char * V_42 = V_50 ;
struct V_5 * V_6 ;
if ( V_12 -> V_20 & V_52 )
return false ;
F_8 (p, &br->port_list, list) {
if ( V_42 == V_50 ||
memcmp ( V_6 -> V_19 -> V_47 , V_42 , V_44 ) < 0 )
V_42 = V_6 -> V_19 -> V_47 ;
}
if ( F_31 ( V_12 -> V_46 . V_42 , V_42 ) == 0 )
return false ;
F_30 ( V_12 , V_42 ) ;
return true ;
}
void F_33 ( struct V_11 * V_12 , V_3 V_53 )
{
struct V_5 * V_6 ;
int V_27 ;
V_27 = F_17 ( V_12 ) ;
F_8 (p, &br->port_list, list) {
if ( V_6 -> V_7 != V_22 &&
F_34 ( V_6 ) ) {
V_6 -> V_48 . V_54 [ 0 ] = ( V_53 >> 8 ) & 0xFF ;
V_6 -> V_48 . V_54 [ 1 ] = V_53 & 0xFF ;
}
}
V_12 -> V_46 . V_54 [ 0 ] = ( V_53 >> 8 ) & 0xFF ;
V_12 -> V_46 . V_54 [ 1 ] = V_53 & 0xFF ;
F_21 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_17 ( V_12 ) && ! V_27 )
F_22 ( V_12 ) ;
}
int F_35 ( struct V_5 * V_6 , unsigned long V_53 )
{
T_1 V_55 ;
if ( V_53 > V_56 )
return - V_57 ;
V_55 = F_1 ( V_53 , V_6 -> V_2 ) ;
if ( F_34 ( V_6 ) )
V_6 -> V_58 = V_55 ;
V_6 -> T_1 = V_55 ;
V_6 -> V_1 = V_53 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_46 , & V_6 -> V_48 , 8 ) &&
V_6 -> T_1 < V_6 -> V_58 ) {
F_3 ( V_6 ) ;
F_15 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_36 ( struct V_5 * V_6 , unsigned long V_59 )
{
if ( V_59 < V_60 ||
V_59 > V_61 )
return - V_57 ;
V_6 -> V_59 = V_59 ;
F_21 ( V_6 -> V_12 ) ;
F_15 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_37 ( char * V_62 , const struct V_46 * V_63 )
{
return sprintf ( V_62 , L_6 ,
V_63 -> V_54 [ 0 ] , V_63 -> V_54 [ 1 ] ,
V_63 -> V_42 [ 0 ] , V_63 -> V_42 [ 1 ] , V_63 -> V_42 [ 2 ] ,
V_63 -> V_42 [ 3 ] , V_63 -> V_42 [ 4 ] , V_63 -> V_42 [ 5 ] ) ;
}
