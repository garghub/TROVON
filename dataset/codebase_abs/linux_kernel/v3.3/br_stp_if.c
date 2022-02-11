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
F_17 ( V_27 , V_6 ) ;
}
void F_13 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
int V_28 ;
V_28 = F_18 ( V_12 ) ;
F_3 ( V_6 ) ;
V_6 -> V_7 = V_22 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
F_16 ( V_6 ) ;
F_17 ( V_27 , V_6 ) ;
F_19 ( & V_6 -> V_29 ) ;
F_19 ( & V_6 -> V_30 ) ;
F_19 ( & V_6 -> V_31 ) ;
F_20 ( V_12 , V_6 , 0 ) ;
F_21 ( V_6 ) ;
F_22 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_18 ( V_12 ) && ! V_28 )
F_23 ( V_12 ) ;
}
static void F_24 ( struct V_11 * V_12 )
{
int V_32 ;
char * V_33 [] = { V_34 , V_12 -> V_19 -> V_35 , L_1 , NULL } ;
char * V_36 [] = { NULL } ;
V_32 = F_25 ( V_34 , V_33 , V_36 , V_37 ) ;
if ( V_32 == 0 ) {
V_12 -> V_38 = V_39 ;
F_26 ( V_12 , L_2 ) ;
} else {
V_12 -> V_38 = V_40 ;
F_26 ( V_12 , L_3 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_15 ( V_12 ) ;
F_11 ( & V_12 -> V_13 ) ;
}
}
static void F_27 ( struct V_11 * V_12 )
{
int V_32 ;
char * V_33 [] = { V_34 , V_12 -> V_19 -> V_35 , L_4 , NULL } ;
char * V_36 [] = { NULL } ;
if ( V_12 -> V_38 == V_39 ) {
V_32 = F_25 ( V_34 , V_33 , V_36 , V_37 ) ;
F_28 ( V_12 , L_5 , V_32 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_15 ( V_12 ) ;
F_11 ( & V_12 -> V_13 ) ;
}
V_12 -> V_38 = V_41 ;
}
void F_29 ( struct V_11 * V_12 , unsigned long V_42 )
{
F_30 () ;
if ( V_42 ) {
if ( V_12 -> V_38 == V_41 )
F_24 ( V_12 ) ;
} else {
if ( V_12 -> V_38 != V_41 )
F_27 ( V_12 ) ;
}
}
void F_31 ( struct V_11 * V_12 , const unsigned char * V_43 )
{
unsigned short V_44 [ V_45 >> 1 ] ;
unsigned char * V_46 = ( unsigned char * ) V_44 ;
struct V_5 * V_6 ;
int V_28 ;
V_28 = F_18 ( V_12 ) ;
memcpy ( V_46 , V_12 -> V_47 . V_43 , V_45 ) ;
memcpy ( V_12 -> V_47 . V_43 , V_43 , V_45 ) ;
memcpy ( V_12 -> V_19 -> V_48 , V_43 , V_45 ) ;
F_8 (p, &br->port_list, list) {
if ( ! F_32 ( V_6 -> V_49 . V_43 , V_46 ) )
memcpy ( V_6 -> V_49 . V_43 , V_43 , V_45 ) ;
if ( ! F_32 ( V_6 -> V_50 . V_43 , V_46 ) )
memcpy ( V_6 -> V_50 . V_43 , V_43 , V_45 ) ;
}
F_22 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_18 ( V_12 ) && ! V_28 )
F_23 ( V_12 ) ;
}
bool F_33 ( struct V_11 * V_12 )
{
const unsigned char * V_51 =
( const unsigned char * ) V_52 ;
const unsigned char * V_43 = V_51 ;
struct V_5 * V_6 ;
if ( V_12 -> V_20 & V_53 )
return false ;
F_8 (p, &br->port_list, list) {
if ( V_43 == V_51 ||
memcmp ( V_6 -> V_19 -> V_48 , V_43 , V_45 ) < 0 )
V_43 = V_6 -> V_19 -> V_48 ;
}
if ( F_32 ( V_12 -> V_47 . V_43 , V_43 ) == 0 )
return false ;
F_31 ( V_12 , V_43 ) ;
return true ;
}
void F_34 ( struct V_11 * V_12 , V_3 V_54 )
{
struct V_5 * V_6 ;
int V_28 ;
V_28 = F_18 ( V_12 ) ;
F_8 (p, &br->port_list, list) {
if ( V_6 -> V_7 != V_22 &&
F_35 ( V_6 ) ) {
V_6 -> V_49 . V_55 [ 0 ] = ( V_54 >> 8 ) & 0xFF ;
V_6 -> V_49 . V_55 [ 1 ] = V_54 & 0xFF ;
}
}
V_12 -> V_47 . V_55 [ 0 ] = ( V_54 >> 8 ) & 0xFF ;
V_12 -> V_47 . V_55 [ 1 ] = V_54 & 0xFF ;
F_22 ( V_12 ) ;
F_15 ( V_12 ) ;
if ( F_18 ( V_12 ) && ! V_28 )
F_23 ( V_12 ) ;
}
int F_36 ( struct V_5 * V_6 , unsigned long V_54 )
{
T_1 V_56 ;
if ( V_54 > V_57 )
return - V_58 ;
V_56 = F_1 ( V_54 , V_6 -> V_2 ) ;
if ( F_35 ( V_6 ) )
V_6 -> V_59 = V_56 ;
V_6 -> T_1 = V_56 ;
V_6 -> V_1 = V_54 ;
if ( ! memcmp ( & V_6 -> V_12 -> V_47 , & V_6 -> V_49 , 8 ) &&
V_6 -> T_1 < V_6 -> V_59 ) {
F_3 ( V_6 ) ;
F_15 ( V_6 -> V_12 ) ;
}
return 0 ;
}
int F_37 ( struct V_5 * V_6 , unsigned long V_60 )
{
if ( V_60 < V_61 ||
V_60 > V_62 )
return - V_58 ;
V_6 -> V_60 = V_60 ;
F_22 ( V_6 -> V_12 ) ;
F_15 ( V_6 -> V_12 ) ;
return 0 ;
}
T_4 F_38 ( char * V_63 , const struct V_47 * V_64 )
{
return sprintf ( V_63 , L_6 ,
V_64 -> V_55 [ 0 ] , V_64 -> V_55 [ 1 ] ,
V_64 -> V_43 [ 0 ] , V_64 -> V_43 [ 1 ] , V_64 -> V_43 [ 2 ] ,
V_64 -> V_43 [ 3 ] , V_64 -> V_43 [ 4 ] , V_64 -> V_43 [ 5 ] ) ;
}
