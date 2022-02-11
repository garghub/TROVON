static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( ( V_3 ) V_1 << V_4 )
| ( V_2 & ( ( 1 << V_4 ) - 1 ) ) ;
}
void F_2 ( struct V_5 * V_6 )
{
struct V_7 V_8 = {
. V_9 = V_6 -> V_10 ,
. V_11 = V_12 ,
. V_13 = V_14 | V_15 ,
. V_16 . V_17 = F_3 ( V_6 -> V_18 -> V_17 ) ,
} ;
int V_19 ;
V_6 -> T_1 = F_1 ( V_6 -> V_1 , V_6 -> V_2 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_20 ) ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
V_19 = F_6 ( V_6 -> V_10 , & V_8 ) ;
if ( V_19 && V_19 != - V_23 )
F_7 ( V_6 -> V_10 , L_1 ) ;
}
void F_8 ( struct V_24 * V_18 )
{
struct V_5 * V_6 ;
F_9 ( & V_18 -> V_25 ) ;
if ( V_18 -> V_26 == V_27 )
F_10 ( & V_18 -> V_28 , V_29 + V_18 -> V_30 ) ;
F_10 ( & V_18 -> V_31 , V_29 + V_32 / 10 ) ;
F_11 ( V_18 ) ;
F_12 (p, &br->port_list, list) {
if ( F_13 ( V_6 -> V_10 ) && F_14 ( V_6 -> V_10 ) )
F_15 ( V_6 ) ;
}
F_16 ( & V_18 -> V_25 ) ;
}
void F_17 ( struct V_24 * V_18 )
{
struct V_5 * V_6 ;
F_9 ( & V_18 -> V_25 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_33 != V_34 )
F_18 ( V_6 ) ;
}
V_18 -> V_35 = 0 ;
V_18 -> V_36 = 0 ;
F_16 ( & V_18 -> V_25 ) ;
F_19 ( & V_18 -> V_28 ) ;
F_19 ( & V_18 -> V_37 ) ;
F_19 ( & V_18 -> V_38 ) ;
F_19 ( & V_18 -> V_31 ) ;
}
void F_15 ( struct V_5 * V_6 )
{
F_2 ( V_6 ) ;
F_20 ( V_6 -> V_18 ) ;
F_21 ( V_6 ) ;
F_22 ( V_39 , V_6 ) ;
}
void F_18 ( struct V_5 * V_6 )
{
struct V_24 * V_18 = V_6 -> V_18 ;
int V_40 ;
V_40 = F_23 ( V_18 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_34 ) ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
F_21 ( V_6 ) ;
F_22 ( V_39 , V_6 ) ;
F_24 ( & V_6 -> V_41 ) ;
F_24 ( & V_6 -> V_42 ) ;
F_24 ( & V_6 -> V_43 ) ;
F_25 ( V_18 , V_6 , 0 , 0 ) ;
F_26 ( V_6 ) ;
F_27 ( V_18 ) ;
F_20 ( V_18 ) ;
if ( F_23 ( V_18 ) && ! V_40 )
F_28 ( V_18 ) ;
}
static void F_29 ( struct V_24 * V_18 )
{
int V_44 ;
char * V_45 [] = { V_46 , V_18 -> V_10 -> V_47 , L_2 , NULL } ;
char * V_48 [] = { NULL } ;
struct V_5 * V_6 ;
if ( F_30 ( F_31 ( V_18 -> V_10 ) , & V_49 ) )
V_44 = F_32 ( V_46 , V_45 , V_48 , V_50 ) ;
else
V_44 = - V_51 ;
F_9 ( & V_18 -> V_25 ) ;
if ( V_18 -> V_52 < V_53 )
F_33 ( V_18 , V_53 ) ;
else if ( V_18 -> V_52 > V_54 )
F_33 ( V_18 , V_54 ) ;
if ( V_44 == 0 ) {
V_18 -> V_26 = V_55 ;
F_34 ( V_18 , L_3 ) ;
F_24 ( & V_18 -> V_28 ) ;
F_12 (p, &br->port_list, list)
F_24 ( & V_6 -> V_43 ) ;
} else {
V_18 -> V_26 = V_27 ;
F_34 ( V_18 , L_4 ) ;
F_20 ( V_18 ) ;
}
F_16 ( & V_18 -> V_25 ) ;
}
static void F_35 ( struct V_24 * V_18 )
{
int V_44 ;
char * V_45 [] = { V_46 , V_18 -> V_10 -> V_47 , L_5 , NULL } ;
char * V_48 [] = { NULL } ;
struct V_5 * V_6 ;
if ( V_18 -> V_26 == V_55 ) {
V_44 = F_32 ( V_46 , V_45 , V_48 , V_50 ) ;
F_36 ( V_18 , L_6 , V_44 ) ;
F_10 ( & V_18 -> V_28 , V_29 + V_18 -> V_30 ) ;
F_12 (p, &br->port_list, list)
F_10 ( & V_6 -> V_43 ,
F_37 ( V_29 + V_56 ) ) ;
F_9 ( & V_18 -> V_25 ) ;
F_20 ( V_18 ) ;
F_16 ( & V_18 -> V_25 ) ;
}
V_18 -> V_26 = V_57 ;
}
void F_38 ( struct V_24 * V_18 , unsigned long V_58 )
{
F_39 () ;
if ( V_58 ) {
if ( V_18 -> V_26 == V_57 )
F_29 ( V_18 ) ;
} else {
if ( V_18 -> V_26 != V_57 )
F_35 ( V_18 ) ;
}
}
void F_40 ( struct V_24 * V_18 , const unsigned char * V_59 )
{
unsigned short V_60 [ V_61 >> 1 ] ;
unsigned char * V_62 = ( unsigned char * ) V_60 ;
struct V_5 * V_6 ;
int V_40 ;
V_40 = F_23 ( V_18 ) ;
F_41 ( V_18 , V_59 ) ;
memcpy ( V_62 , V_18 -> V_63 . V_59 , V_61 ) ;
memcpy ( V_18 -> V_63 . V_59 , V_59 , V_61 ) ;
memcpy ( V_18 -> V_10 -> V_64 , V_59 , V_61 ) ;
F_12 (p, &br->port_list, list) {
if ( F_42 ( V_6 -> V_65 . V_59 , V_62 ) )
memcpy ( V_6 -> V_65 . V_59 , V_59 , V_61 ) ;
if ( F_42 ( V_6 -> V_66 . V_59 , V_62 ) )
memcpy ( V_6 -> V_66 . V_59 , V_59 , V_61 ) ;
}
F_27 ( V_18 ) ;
F_20 ( V_18 ) ;
if ( F_23 ( V_18 ) && ! V_40 )
F_28 ( V_18 ) ;
}
bool F_43 ( struct V_24 * V_18 )
{
const unsigned char * V_67 =
( const unsigned char * ) V_68 ;
const unsigned char * V_59 = V_67 ;
struct V_5 * V_6 ;
if ( V_18 -> V_10 -> V_69 == V_70 )
return false ;
F_12 (p, &br->port_list, list) {
if ( V_59 == V_67 ||
memcmp ( V_6 -> V_10 -> V_64 , V_59 , V_61 ) < 0 )
V_59 = V_6 -> V_10 -> V_64 ;
}
if ( F_42 ( V_18 -> V_63 . V_59 , V_59 ) )
return false ;
F_40 ( V_18 , V_59 ) ;
return true ;
}
void F_44 ( struct V_24 * V_18 , V_3 V_71 )
{
struct V_5 * V_6 ;
int V_40 ;
F_9 ( & V_18 -> V_25 ) ;
V_40 = F_23 ( V_18 ) ;
F_12 (p, &br->port_list, list) {
if ( V_6 -> V_33 != V_34 &&
F_45 ( V_6 ) ) {
V_6 -> V_65 . V_72 [ 0 ] = ( V_71 >> 8 ) & 0xFF ;
V_6 -> V_65 . V_72 [ 1 ] = V_71 & 0xFF ;
}
}
V_18 -> V_63 . V_72 [ 0 ] = ( V_71 >> 8 ) & 0xFF ;
V_18 -> V_63 . V_72 [ 1 ] = V_71 & 0xFF ;
F_27 ( V_18 ) ;
F_20 ( V_18 ) ;
if ( F_23 ( V_18 ) && ! V_40 )
F_28 ( V_18 ) ;
F_16 ( & V_18 -> V_25 ) ;
}
int F_46 ( struct V_5 * V_6 , unsigned long V_71 )
{
T_1 V_73 ;
if ( V_71 > V_74 )
return - V_75 ;
V_73 = F_1 ( V_71 , V_6 -> V_2 ) ;
if ( F_45 ( V_6 ) )
V_6 -> V_76 = V_73 ;
V_6 -> T_1 = V_73 ;
V_6 -> V_1 = V_71 ;
if ( ! memcmp ( & V_6 -> V_18 -> V_63 , & V_6 -> V_65 , 8 ) &&
V_6 -> T_1 < V_6 -> V_76 ) {
F_4 ( V_6 ) ;
F_20 ( V_6 -> V_18 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 , unsigned long V_77 )
{
if ( V_77 < V_78 ||
V_77 > V_79 )
return - V_75 ;
V_6 -> V_13 |= V_80 ;
V_6 -> V_77 = V_77 ;
F_27 ( V_6 -> V_18 ) ;
F_20 ( V_6 -> V_18 ) ;
return 0 ;
}
T_4 F_48 ( char * V_81 , const struct V_63 * V_11 )
{
return sprintf ( V_81 , L_7 ,
V_11 -> V_72 [ 0 ] , V_11 -> V_72 [ 1 ] ,
V_11 -> V_59 [ 0 ] , V_11 -> V_59 [ 1 ] , V_11 -> V_59 [ 2 ] ,
V_11 -> V_59 [ 3 ] , V_11 -> V_59 [ 4 ] , V_11 -> V_59 [ 5 ] ) ;
}
