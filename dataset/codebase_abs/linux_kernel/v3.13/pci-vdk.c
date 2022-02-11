static inline int F_1 ( const struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_3 * V_4 , unsigned int V_5 , int V_6 , int V_7 ,
T_1 * V_8 )
{
T_1 V_9 ;
if ( V_4 -> V_10 == 0 && V_5 == F_3 ( 0 , 0 ) ) {
V_9 = F_4 ( V_6 & ~ 3 ) ;
}
else {
F_5 ( F_6 ( V_4 , V_5 , V_6 ) ) ;
V_9 = F_7 ( V_6 & ~ 3 ) ;
}
switch ( V_7 ) {
case 1 :
V_9 = V_9 >> ( ( V_6 & 3 ) * 8 ) ;
break;
case 2 :
V_9 = V_9 >> ( ( V_6 & 2 ) * 8 ) ;
break;
case 4 :
break;
default:
F_8 () ;
}
* V_8 = V_9 ;
return V_11 ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_5 , int V_6 , int V_7 ,
T_1 V_12 )
{
switch ( V_7 ) {
case 1 :
if ( V_4 -> V_10 == 0 && V_5 == F_3 ( 0 , 0 ) ) {
F_10 ( V_6 , V_12 ) ;
}
else {
F_5 ( F_6 ( V_4 , V_5 , V_6 ) ) ;
F_11 ( V_6 , V_12 ) ;
}
break;
case 2 :
if ( V_4 -> V_10 == 0 && V_5 == F_3 ( 0 , 0 ) ) {
F_12 ( V_6 , V_12 ) ;
}
else {
F_5 ( F_6 ( V_4 , V_5 , V_6 ) ) ;
F_13 ( V_6 , V_12 ) ;
}
break;
case 4 :
if ( V_4 -> V_10 == 0 && V_5 == F_3 ( 0 , 0 ) ) {
F_14 ( V_6 , V_12 ) ;
}
else {
F_5 ( F_6 ( V_4 , V_5 , V_6 ) ) ;
F_15 ( V_6 , V_12 ) ;
}
break;
default:
F_8 () ;
}
return V_11 ;
}
static int T_2 F_16 ( struct V_13 * V_14 )
{
struct V_3 V_4 ;
T_1 V_15 ;
V_4 . V_10 = 0 ;
if ( V_14 -> V_16 ( & V_4 , 0 , V_17 , 4 , & V_15 ) == V_11 ) {
F_17 ( L_1 , V_15 ) ;
if ( V_15 == 0x200e10cf )
return 1 ;
}
F_17 ( L_2 ) ;
return 0 ;
}
static struct V_13 * T_2 F_18 ( void )
{
unsigned long V_18 ;
F_19 ( V_18 ) ;
if ( F_16 ( & V_19 ) ) {
F_20 ( V_18 ) ;
F_17 ( L_3 ) ;
return & V_19 ;
}
F_20 ( V_18 ) ;
return NULL ;
}
static void T_2 F_21 ( struct V_1 * V_20 )
{
int V_21 ;
F_17 ( L_4 , F_22 ( V_20 ) ) ;
for( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
V_20 -> V_22 [ V_21 ] . V_18 |= V_23 ;
}
static void F_23 ( struct V_1 * V_20 )
{
int V_21 ;
if ( ( V_20 -> V_24 >> 8 ) != V_25 )
return;
F_17 ( L_5 , F_22 ( V_20 ) ) ;
for( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
struct V_22 * V_26 = & V_20 -> V_22 [ V_21 ] ;
if ( ( V_26 -> V_27 & ~ 0x80 ) == 0x374 ) {
V_26 -> V_27 |= 2 ;
V_26 -> V_28 = V_26 -> V_27 ;
}
}
}
static void F_24 ( struct V_1 * V_20 )
{
int V_21 ;
F_17 ( L_6 , F_22 ( V_20 ) ) ;
for( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
V_20 -> V_22 [ V_21 ] . V_27 = V_20 -> V_22 [ V_21 ] . V_28 = V_20 -> V_22 [ V_21 ] . V_18 = 0 ;
}
static void F_25 ( struct V_1 * V_20 )
{
F_26 ( L_7 ) ;
V_29 = 32 ;
}
void F_27 ( struct V_3 * V_4 )
{
#if 0
printk("### PCIBIOS_FIXUP_BUS(%d)\n",bus->number);
#endif
F_28 ( V_4 ) ;
if ( V_4 -> V_10 == 0 ) {
struct V_1 * V_2 ;
F_29 (dev, &bus->devices, bus_list) {
if ( V_2 -> V_5 == 0 ) {
V_2 -> V_22 [ 0 ] . V_27 = 0 ;
V_2 -> V_22 [ 0 ] . V_28 = 0 ;
}
}
}
}
int T_2 F_30 ( void )
{
struct V_13 * V_30 = NULL ;
F_31 ( V_31 ) ;
if ( ! V_32 )
return - V_33 ;
V_34 |= V_35 | V_36 ;
F_32 ( 1 ) = ( ( V_37 + 0x01000000 ) >> 9 ) | 0x08000000 ;
F_32 ( 2 ) = ( ( V_37 + 0x00000000 ) >> 9 ) | 0x08000000 ;
* ( volatile V_38 * ) ( V_39 + 0x848 ) = 0xe0000000 ;
* ( volatile V_38 * ) ( V_39 + 0x8b8 ) = 0x00000000 ;
V_40 = ( V_37 + 0x04000000 ) >> 9 ;
V_41 = ( V_37 + 0x08000000 ) >> 9 ;
V_42 = V_37 + 0x04000000 ;
V_43 = V_37 + 0x08000000 ;
F_33 () ;
V_44 = V_45 ;
V_46 . V_27 = ( V_40 << 9 ) & 0xfffffc00 ;
V_46 . V_28 = ( V_47 << 9 ) | 0x3ff ;
V_46 . V_28 += V_46 . V_27 ;
F_17 ( L_8 ,
( unsigned long long ) V_46 . V_27 ,
( unsigned long long ) V_46 . V_28 ) ;
V_48 . V_27 = ( V_41 << 9 ) & 0xfffffc00 ;
V_48 . V_28 = ( V_49 << 9 ) | 0x3ff ;
V_48 . V_28 += V_48 . V_27 ;
V_48 . V_27 += 0x400 ;
F_17 ( L_9 ,
( unsigned long long ) V_48 . V_27 ,
( unsigned long long ) V_48 . V_28 ) ;
F_17 ( L_10 ,
V_50 , V_51 ) ;
if ( F_34 ( & V_52 , & V_48 ) < 0 )
F_35 ( L_11 ) ;
if ( F_34 ( & V_53 , & V_46 ) < 0 )
F_35 ( L_12 ) ;
if ( ! V_54 )
return - V_33 ;
V_30 = F_18 () ;
if ( V_30 )
V_55 = V_30 ;
else {
F_17 ( L_13 ) ;
return - V_33 ;
}
F_17 ( L_14 ) ;
F_36 ( & V_31 , & V_46 ) ;
F_36 ( & V_31 , & V_48 ) ;
F_37 ( NULL , 0 , V_55 , NULL , & V_31 ) ;
F_38 () ;
F_39 () ;
F_40 () ;
return 0 ;
}
char * T_2 F_41 ( char * V_56 )
{
if ( ! strcmp ( V_56 , L_15 ) ) {
V_54 = 0 ;
return NULL ;
}
return V_56 ;
}
int F_42 ( struct V_1 * V_2 , int V_57 )
{
int V_58 ;
if ( ( V_58 = F_43 ( V_2 , V_57 ) ) < 0 )
return V_58 ;
if ( ! V_2 -> V_59 )
F_44 ( V_2 ) ;
return 0 ;
}
