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
if ( F_9 ( V_6 -> V_19 ) && F_10 ( V_6 -> V_19 ) )
F_11 ( V_6 ) ;
}
F_12 ( & V_12 -> V_13 ) ;
}
void F_13 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
F_5 ( & V_12 -> V_13 ) ;
F_8 (p, &br->port_list, list) {
if ( V_6 -> V_7 != V_20 )
F_14 ( V_6 ) ;
}
V_12 -> V_21 = 0 ;
V_12 -> V_22 = 0 ;
F_12 ( & V_12 -> V_13 ) ;
F_15 ( & V_12 -> V_14 ) ;
F_15 ( & V_12 -> V_23 ) ;
F_15 ( & V_12 -> V_24 ) ;
F_15 ( & V_12 -> V_17 ) ;
}
void F_11 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_16 ( V_6 -> V_12 ) ;
F_17 ( V_6 ) ;
F_18 ( V_25 , V_6 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
int V_26 ;
V_26 = F_19 ( V_12 ) ;
F_3 ( V_6 ) ;
V_6 -> V_7 = V_20 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
F_17 ( V_6 ) ;
F_18 ( V_25 , V_6 ) ;
F_20 ( & V_6 -> V_27 ) ;
F_20 ( & V_6 -> V_28 ) ;
F_20 ( & V_6 -> V_29 ) ;
F_21 ( V_12 , V_6 , 0 ) ;
F_22 ( V_6 ) ;
F_23 ( V_12 ) ;
F_16 ( V_12 ) ;
if ( F_19 ( V_12 ) && ! V_26 )
F_24 ( V_12 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
int V_30 ;
char * V_31 [] = { V_32 , V_12 -> V_19 -> V_33 , L_1 , NULL } ;
char * V_34 [] = { NULL } ;
V_30 = F_26 ( V_32 , V_31 , V_34 , V_35 ) ;
F_5 ( & V_12 -> V_13 ) ;
if ( V_12 -> V_36 < V_37 )
F_27 ( V_12 , V_37 ) ;
else if ( V_12 -> V_36 > V_38 )
F_27 ( V_12 , V_38 ) ;
if ( V_30 == 0 ) {
V_12 -> V_39 = V_40 ;
F_28 ( V_12 , L_2 ) ;
} else {
V_12 -> V_39 = V_41 ;
F_28 ( V_12 , L_3 ) ;
F_16 ( V_12 ) ;
}
F_12 ( & V_12 -> V_13 ) ;
}
static void F_29 ( struct V_11 * V_12 )
{
int V_30 ;
char * V_31 [] = { V_32 , V_12 -> V_19 -> V_33 , L_4 , NULL } ;
char * V_34 [] = { NULL } ;
if ( V_12 -> V_39 == V_40 ) {
V_30 = F_26 ( V_32 , V_31 , V_34 , V_35 ) ;
F_30 ( V_12 , L_5 , V_30 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_16 ( V_12 ) ;
F_12 ( & V_12 -> V_13 ) ;
}
V_12 -> V_39 = V_42 ;
}
void F_31 ( struct V_11 * V_12 , unsigned long V_43 )
{
F_32 () ;
if ( V_43 ) {
if ( V_12 -> V_39 == V_42 )
F_25 ( V_12 ) ;
} else {
if ( V_12 -> V_39 != V_42 )
F_29 ( V_12 ) ;
}
}
void F_33 ( struct V_11 * V_12 , const unsigned char * V_44 )
{
unsigned short V_45 [ V_46 >> 1 ] ;
unsigned char * V_47 = ( unsigned char * ) V_45 ;
struct V_5 * V_6 ;
int V_26 ;
V_26 = F_19 ( V_12 ) ;
F_34 ( V_12 , V_44 ) ;
memcpy ( V_47 , V_12 -> V_48 . V_44 , V_46 ) ;
memcpy ( V_12 -> V_48 . V_44 , V_44 , V_46 ) ;
memcpy ( V_12 -> V_19 -> V_49 , V_44 , V_46 ) ;
F_8 (p, &br->port_list, list) {
if ( F_35 ( V_6 -> V_50 . V_44 , V_47 ) )
memcpy ( V_6 -> V_50 . V_44 , V_44 , V_46 ) ;
if ( F_35 ( V_6 -> V_51 . V_44 , V_47 ) )
memcpy ( V_6 -> V_51 . V_44 , V_44 , V_46 ) ;
}
F_23 ( V_12 ) ;
F_16 ( V_12 ) ;
if ( F_19 ( V_12 ) && ! V_26 )
F_24 ( V_12 ) ;
}
bool F_36 ( struct V_11 * V_12 )
{
const unsigned char * V_52 =
( const unsigned char * ) V_53 ;
const unsigned char * V_44 = V_52 ;
struct V_5 * V_6 ;
if ( V_12 -> V_19 -> V_54 == V_55 )
return false ;
F_8 (p, &br->port_list, list) {
if ( V_44 == V_52 ||
memcmp ( V_6 -> V_19 -> V_49 , V_44 , V_46 ) < 0 )
V_44 = V_6 -> V_19 -> V_49 ;
}
if ( F_35 ( V_12 -> V_48 . V_44 , V_44 ) )
return false ;
F_33 ( V_12 , V_44 ) ;
return true ;
}
void F_37 ( struct V_11 * V_12 , V_3 V_56 )
{
struct V_5 * V_6 ;
int V_26 ;
V_26 = F_19 ( V_12 ) ;
F_8 (p, &br->port_list, list) {
if ( V_6 -> V_7 != V_20 &&
F_38 ( V_6 ) ) {
V_6 -> V_50 . V_57 [ 0 ] = ( V_56 >> 8 ) & 0xFF ;
V_6 -> V_50 . V_57 [ 1 ] = V_56 & 0xFF ;
}
}
V_12 -> V_48 . V_57 [ 0 ] = ( V_56 >> 8 ) & 0xFF ;
V_12 -> V_48 . V_57 [ 1 ] = V_56 & 0xFF ;
F_23 ( V_12 ) ;
F_16 ( V_12 ) ;
if ( F_19 ( V_12 ) && ! V_26 )
F_24 ( V_12 ) ;
}
int F_39 ( struct V_5 * V_6 , unsigned long V_56 )
{
T_1 V_58 ;
if ( V_56 > V_59 )
return - V_60 ;
V_58 = F_1 ( V_56 , V_6 -> V_2 ) ;
if ( F_38 ( V_6 ) )
V_6 -> V_61 = V_58 ;
V_6 -> T_1 = V_58 ;
V_6 -> V_1 = V_56 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_48 , & V_6 -> V_50 , 8 ) &&
V_6 -> T_1 < V_6 -> V_61 ) {
F_3 ( V_6 ) ;
F_16 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_40 ( struct V_5 * V_6 , unsigned long V_62 )
{
if ( V_62 < V_63 ||
V_62 > V_64 )
return - V_60 ;
V_6 -> V_65 |= V_66 ;
V_6 -> V_62 = V_62 ;
F_23 ( V_6 -> V_12 ) ;
F_16 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_41 ( char * V_67 , const struct V_48 * V_68 )
{
return sprintf ( V_67 , L_6 ,
V_68 -> V_57 [ 0 ] , V_68 -> V_57 [ 1 ] ,
V_68 -> V_44 [ 0 ] , V_68 -> V_44 [ 1 ] , V_68 -> V_44 [ 2 ] ,
V_68 -> V_44 [ 3 ] , V_68 -> V_44 [ 4 ] , V_68 -> V_44 [ 5 ] ) ;
}
