static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( ( V_3 ) V_1 << V_4 )
| ( V_2 & ( ( 1 << V_4 ) - 1 ) ) ;
}
void F_2 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {
. V_9 = V_10 ,
. V_11 = V_12 | V_13 ,
. V_14 . V_15 = F_3 ( V_6 -> V_16 -> V_15 ) ,
} ;
int V_17 ;
V_6 -> T_1 = F_1 ( V_6 -> V_1 , V_6 -> V_2 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_18 ) ;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = 0 ;
V_17 = F_6 ( V_6 -> V_21 , & V_8 ) ;
if ( V_17 && V_17 != - V_22 )
F_7 ( V_6 -> V_21 , L_1 ) ;
}
void F_8 ( struct V_23 * V_16 )
{
struct V_5 * V_6 ;
F_9 ( & V_16 -> V_24 ) ;
if ( V_16 -> V_25 == V_26 )
F_10 ( & V_16 -> V_27 , V_28 + V_16 -> V_29 ) ;
F_10 ( & V_16 -> V_30 , V_28 + V_31 / 10 ) ;
F_11 ( V_16 ) ;
F_12 (p, &br->port_list, list) {
if ( F_13 ( V_6 -> V_21 ) && F_14 ( V_6 -> V_21 ) )
F_15 ( V_6 ) ;
}
F_16 ( & V_16 -> V_24 ) ;
}
void F_17 ( struct V_23 * V_16 )
{
struct V_5 * V_6 ;
F_9 ( & V_16 -> V_24 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_32 != V_33 )
F_18 ( V_6 ) ;
}
V_16 -> V_34 = 0 ;
V_16 -> V_35 = 0 ;
F_16 ( & V_16 -> V_24 ) ;
F_19 ( & V_16 -> V_27 ) ;
F_19 ( & V_16 -> V_36 ) ;
F_19 ( & V_16 -> V_37 ) ;
F_19 ( & V_16 -> V_30 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_20 ( V_6 -> V_16 ) ;
F_21 ( V_6 ) ;
F_22 ( V_38 , V_6 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_23 * V_16 = V_6 -> V_16 ;
int V_39 ;
V_39 = F_23 ( V_16 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_33 ) ;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = 0 ;
F_21 ( V_6 ) ;
F_22 ( V_38 , V_6 ) ;
F_24 ( & V_6 -> V_40 ) ;
F_24 ( & V_6 -> V_41 ) ;
F_24 ( & V_6 -> V_42 ) ;
F_25 ( V_16 , V_6 , 0 , 0 ) ;
F_26 ( V_6 ) ;
F_27 ( V_16 ) ;
F_20 ( V_16 ) ;
if ( F_23 ( V_16 ) && ! V_39 )
F_28 ( V_16 ) ;
}
static void F_29 ( struct V_23 * V_16 )
{
int V_43 ;
char * V_44 [] = { V_45 , V_16 -> V_21 -> V_46 , L_2 , NULL } ;
char * V_47 [] = { NULL } ;
struct V_5 * V_6 ;
if ( F_30 ( F_31 ( V_16 -> V_21 ) , & V_48 ) )
V_43 = F_32 ( V_45 , V_44 , V_47 , V_49 ) ;
else
V_43 = - V_50 ;
F_9 ( & V_16 -> V_24 ) ;
if ( V_16 -> V_51 < V_52 )
F_33 ( V_16 , V_52 ) ;
else if ( V_16 -> V_51 > V_53 )
F_33 ( V_16 , V_53 ) ;
if ( V_43 == 0 ) {
V_16 -> V_25 = V_54 ;
F_34 ( V_16 , L_3 ) ;
F_24 ( & V_16 -> V_27 ) ;
F_12 (p, &br->port_list, list)
F_24 ( & V_6 -> V_42 ) ;
} else {
V_16 -> V_25 = V_26 ;
F_34 ( V_16 , L_4 ) ;
F_20 ( V_16 ) ;
}
F_16 ( & V_16 -> V_24 ) ;
}
static void F_35 ( struct V_23 * V_16 )
{
int V_43 ;
char * V_44 [] = { V_45 , V_16 -> V_21 -> V_46 , L_5 , NULL } ;
char * V_47 [] = { NULL } ;
struct V_5 * V_6 ;
if ( V_16 -> V_25 == V_54 ) {
V_43 = F_32 ( V_45 , V_44 , V_47 , V_49 ) ;
F_36 ( V_16 , L_6 , V_43 ) ;
F_10 ( & V_16 -> V_27 , V_28 + V_16 -> V_29 ) ;
F_12 (p, &br->port_list, list)
F_10 ( & V_6 -> V_42 ,
F_37 ( V_28 + V_55 ) ) ;
F_9 ( & V_16 -> V_24 ) ;
F_20 ( V_16 ) ;
F_16 ( & V_16 -> V_24 ) ;
}
V_16 -> V_25 = V_56 ;
}
void F_38 ( struct V_23 * V_16 , unsigned long V_57 )
{
F_39 () ;
if ( V_57 ) {
if ( V_16 -> V_25 == V_56 )
F_29 ( V_16 ) ;
} else {
if ( V_16 -> V_25 != V_56 )
F_35 ( V_16 ) ;
}
}
void F_40 ( struct V_23 * V_16 , const unsigned char * V_58 )
{
unsigned short V_59 [ V_60 >> 1 ] ;
unsigned char * V_61 = ( unsigned char * ) V_59 ;
struct V_5 * V_6 ;
int V_39 ;
V_39 = F_23 ( V_16 ) ;
F_41 ( V_16 , V_58 ) ;
memcpy ( V_61 , V_16 -> V_62 . V_58 , V_60 ) ;
memcpy ( V_16 -> V_62 . V_58 , V_58 , V_60 ) ;
memcpy ( V_16 -> V_21 -> V_63 , V_58 , V_60 ) ;
F_12 (p, &br->port_list, list) {
if ( F_42 ( V_6 -> V_64 . V_58 , V_61 ) )
memcpy ( V_6 -> V_64 . V_58 , V_58 , V_60 ) ;
if ( F_42 ( V_6 -> V_65 . V_58 , V_61 ) )
memcpy ( V_6 -> V_65 . V_58 , V_58 , V_60 ) ;
}
F_27 ( V_16 ) ;
F_20 ( V_16 ) ;
if ( F_23 ( V_16 ) && ! V_39 )
F_28 ( V_16 ) ;
}
bool F_43 ( struct V_23 * V_16 )
{
const unsigned char * V_66 =
( const unsigned char * ) V_67 ;
const unsigned char * V_58 = V_66 ;
struct V_5 * V_6 ;
if ( V_16 -> V_21 -> V_68 == V_69 )
return false ;
F_12 (p, &br->port_list, list) {
if ( V_58 == V_66 ||
memcmp ( V_6 -> V_21 -> V_63 , V_58 , V_60 ) < 0 )
V_58 = V_6 -> V_21 -> V_63 ;
}
if ( F_42 ( V_16 -> V_62 . V_58 , V_58 ) )
return false ;
F_40 ( V_16 , V_58 ) ;
return true ;
}
void F_44 ( struct V_23 * V_16 , V_3 V_70 )
{
struct V_5 * V_6 ;
int V_39 ;
F_9 ( & V_16 -> V_24 ) ;
V_39 = F_23 ( V_16 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_32 != V_33 &&
F_45 ( V_6 ) ) {
V_6 -> V_64 . V_71 [ 0 ] = ( V_70 >> 8 ) & 0xFF ;
V_6 -> V_64 . V_71 [ 1 ] = V_70 & 0xFF ;
}
}
V_16 -> V_62 . V_71 [ 0 ] = ( V_70 >> 8 ) & 0xFF ;
V_16 -> V_62 . V_71 [ 1 ] = V_70 & 0xFF ;
F_27 ( V_16 ) ;
F_20 ( V_16 ) ;
if ( F_23 ( V_16 ) && ! V_39 )
F_28 ( V_16 ) ;
F_16 ( & V_16 -> V_24 ) ;
}
int F_46 ( struct V_5 * V_6 , unsigned long V_70 )
{
T_1 V_72 ;
if ( V_70 > V_73 )
return - V_74 ;
V_72 = F_1 ( V_70 , V_6 -> V_2 ) ;
if ( F_45 ( V_6 ) )
V_6 -> V_75 = V_72 ;
V_6 -> T_1 = V_72 ;
V_6 -> V_1 = V_70 ;
if ( ! memcmp ( & V_6 -> V_16 -> V_62 , & V_6 -> V_64 , 8 ) &&
V_6 -> T_1 < V_6 -> V_75 ) {
F_4 ( V_6 ) ;
F_20 ( V_6 -> V_16 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 , unsigned long V_76 )
{
if ( V_76 < V_77 ||
V_76 > V_78 )
return - V_74 ;
V_6 -> V_11 |= V_79 ;
V_6 -> V_76 = V_76 ;
F_27 ( V_6 -> V_16 ) ;
F_20 ( V_6 -> V_16 ) ;
return 0 ;
}
T_4 F_48 ( char * V_80 , const struct V_62 * V_9 )
{
return sprintf ( V_80 , L_7 ,
V_9 -> V_71 [ 0 ] , V_9 -> V_71 [ 1 ] ,
V_9 -> V_58 [ 0 ] , V_9 -> V_58 [ 1 ] , V_9 -> V_58 [ 2 ] ,
V_9 -> V_58 [ 3 ] , V_9 -> V_58 [ 4 ] , V_9 -> V_58 [ 5 ] ) ;
}
