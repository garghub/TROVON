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
F_7 ( & V_11 -> V_13 , V_14 + V_11 -> V_15 ) ;
F_7 ( & V_11 -> V_16 , V_14 + V_17 / 10 ) ;
F_8 ( V_11 ) ;
F_9 (p, &br->port_list, list) {
if ( F_10 ( V_6 -> V_18 ) && F_11 ( V_6 -> V_18 ) )
F_12 ( V_6 ) ;
}
F_13 ( & V_11 -> V_12 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
F_6 ( & V_11 -> V_12 ) ;
F_9 (p, &br->port_list, list) {
if ( V_6 -> V_19 != V_20 )
F_15 ( V_6 ) ;
}
V_11 -> V_21 = 0 ;
V_11 -> V_22 = 0 ;
F_13 ( & V_11 -> V_12 ) ;
F_16 ( & V_11 -> V_13 ) ;
F_16 ( & V_11 -> V_23 ) ;
F_16 ( & V_11 -> V_24 ) ;
F_16 ( & V_11 -> V_16 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_17 ( V_6 -> V_11 ) ;
F_18 ( V_6 ) ;
F_19 ( V_25 , V_6 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
int V_26 ;
V_26 = F_20 ( V_11 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , V_20 ) ;
V_6 -> V_8 = 0 ;
V_6 -> V_9 = 0 ;
F_18 ( V_6 ) ;
F_19 ( V_25 , V_6 ) ;
F_21 ( & V_6 -> V_27 ) ;
F_21 ( & V_6 -> V_28 ) ;
F_21 ( & V_6 -> V_29 ) ;
F_22 ( V_11 , V_6 , 0 ) ;
F_23 ( V_6 ) ;
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_26 )
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_10 * V_11 )
{
int V_30 ;
char * V_31 [] = { V_32 , V_11 -> V_18 -> V_33 , L_1 , NULL } ;
char * V_34 [] = { NULL } ;
V_30 = F_27 ( V_32 , V_31 , V_34 , V_35 ) ;
F_6 ( & V_11 -> V_12 ) ;
if ( V_11 -> V_36 < V_37 )
F_28 ( V_11 , V_37 ) ;
else if ( V_11 -> V_36 > V_38 )
F_28 ( V_11 , V_38 ) ;
if ( V_30 == 0 ) {
V_11 -> V_39 = V_40 ;
F_29 ( V_11 , L_2 ) ;
} else {
V_11 -> V_39 = V_41 ;
F_29 ( V_11 , L_3 ) ;
F_17 ( V_11 ) ;
}
F_13 ( & V_11 -> V_12 ) ;
}
static void F_30 ( struct V_10 * V_11 )
{
int V_30 ;
char * V_31 [] = { V_32 , V_11 -> V_18 -> V_33 , L_4 , NULL } ;
char * V_34 [] = { NULL } ;
if ( V_11 -> V_39 == V_40 ) {
V_30 = F_27 ( V_32 , V_31 , V_34 , V_35 ) ;
F_31 ( V_11 , L_5 , V_30 ) ;
F_6 ( & V_11 -> V_12 ) ;
F_17 ( V_11 ) ;
F_13 ( & V_11 -> V_12 ) ;
}
V_11 -> V_39 = V_42 ;
}
void F_32 ( struct V_10 * V_11 , unsigned long V_43 )
{
F_33 () ;
if ( V_43 ) {
if ( V_11 -> V_39 == V_42 )
F_26 ( V_11 ) ;
} else {
if ( V_11 -> V_39 != V_42 )
F_30 ( V_11 ) ;
}
}
void F_34 ( struct V_10 * V_11 , const unsigned char * V_44 )
{
unsigned short V_45 [ V_46 >> 1 ] ;
unsigned char * V_47 = ( unsigned char * ) V_45 ;
struct V_5 * V_6 ;
int V_26 ;
V_26 = F_20 ( V_11 ) ;
F_35 ( V_11 , V_44 ) ;
memcpy ( V_47 , V_11 -> V_48 . V_44 , V_46 ) ;
memcpy ( V_11 -> V_48 . V_44 , V_44 , V_46 ) ;
memcpy ( V_11 -> V_18 -> V_49 , V_44 , V_46 ) ;
F_9 (p, &br->port_list, list) {
if ( F_36 ( V_6 -> V_50 . V_44 , V_47 ) )
memcpy ( V_6 -> V_50 . V_44 , V_44 , V_46 ) ;
if ( F_36 ( V_6 -> V_51 . V_44 , V_47 ) )
memcpy ( V_6 -> V_51 . V_44 , V_44 , V_46 ) ;
}
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_26 )
F_25 ( V_11 ) ;
}
bool F_37 ( struct V_10 * V_11 )
{
const unsigned char * V_52 =
( const unsigned char * ) V_53 ;
const unsigned char * V_44 = V_52 ;
struct V_5 * V_6 ;
if ( V_11 -> V_18 -> V_54 == V_55 )
return false ;
F_9 (p, &br->port_list, list) {
if ( V_44 == V_52 ||
memcmp ( V_6 -> V_18 -> V_49 , V_44 , V_46 ) < 0 )
V_44 = V_6 -> V_18 -> V_49 ;
}
if ( F_36 ( V_11 -> V_48 . V_44 , V_44 ) )
return false ;
F_34 ( V_11 , V_44 ) ;
return true ;
}
void F_38 ( struct V_10 * V_11 , V_3 V_56 )
{
struct V_5 * V_6 ;
int V_26 ;
V_26 = F_20 ( V_11 ) ;
F_9 (p, &br->port_list, list) {
if ( V_6 -> V_19 != V_20 &&
F_39 ( V_6 ) ) {
V_6 -> V_50 . V_57 [ 0 ] = ( V_56 >> 8 ) & 0xFF ;
V_6 -> V_50 . V_57 [ 1 ] = V_56 & 0xFF ;
}
}
V_11 -> V_48 . V_57 [ 0 ] = ( V_56 >> 8 ) & 0xFF ;
V_11 -> V_48 . V_57 [ 1 ] = V_56 & 0xFF ;
F_24 ( V_11 ) ;
F_17 ( V_11 ) ;
if ( F_20 ( V_11 ) && ! V_26 )
F_25 ( V_11 ) ;
}
int F_40 ( struct V_5 * V_6 , unsigned long V_56 )
{
T_1 V_58 ;
if ( V_56 > V_59 )
return - V_60 ;
V_58 = F_1 ( V_56 , V_6 -> V_2 ) ;
if ( F_39 ( V_6 ) )
V_6 -> V_61 = V_58 ;
V_6 -> T_1 = V_58 ;
V_6 -> V_1 = V_56 ;
if ( ! memcmp ( & V_6 -> V_11 -> V_48 , & V_6 -> V_50 , 8 ) &&
V_6 -> T_1 < V_6 -> V_61 ) {
F_3 ( V_6 ) ;
F_17 ( V_6 -> V_11 ) ;
}
return 0 ;
}
int F_41 ( struct V_5 * V_6 , unsigned long V_62 )
{
if ( V_62 < V_63 ||
V_62 > V_64 )
return - V_60 ;
V_6 -> V_65 |= V_66 ;
V_6 -> V_62 = V_62 ;
F_24 ( V_6 -> V_11 ) ;
F_17 ( V_6 -> V_11 ) ;
return 0 ;
}
T_4 F_42 ( char * V_67 , const struct V_48 * V_68 )
{
return sprintf ( V_67 , L_6 ,
V_68 -> V_57 [ 0 ] , V_68 -> V_57 [ 1 ] ,
V_68 -> V_44 [ 0 ] , V_68 -> V_44 [ 1 ] , V_68 -> V_44 [ 2 ] ,
V_68 -> V_44 [ 3 ] , V_68 -> V_44 [ 4 ] , V_68 -> V_44 [ 5 ] ) ;
}
