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
static void T_2 F_21 ( void )
{
struct V_3 V_4 ;
struct V_1 V_2 ;
int V_20 ;
T_3 V_21 ;
if ( V_22 <= 0 || V_22 >= 0xff )
return;
F_17 ( L_4 ) ;
for ( V_20 = 0 ; V_20 <= V_22 ; V_20 ++ ) {
if ( F_22 ( 0 , V_20 ) )
continue;
V_4 . V_10 = V_20 ;
V_4 . V_23 = V_24 ;
V_2 . V_4 = & V_4 ;
for( V_2 . V_5 = 0 ; V_2 . V_5 < 256 ; V_2 . V_5 += 8 )
if ( ! F_23 ( & V_2 , V_17 , & V_21 ) &&
V_21 != 0x0000 && V_21 != 0xffff ) {
F_17 ( L_5 , V_20 , V_2 . V_5 , V_21 ) ;
F_17 ( L_6 , V_20 ) ;
F_24 ( V_20 , V_24 , NULL ) ;
break;
}
}
}
static void T_2 F_25 ( struct V_1 * V_25 )
{
int V_26 ;
F_17 ( L_7 , F_26 ( V_25 ) ) ;
for( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_25 -> V_27 [ V_26 ] . V_18 |= V_28 ;
}
static void F_27 ( struct V_1 * V_25 )
{
int V_26 ;
if ( ( V_25 -> V_29 >> 8 ) != V_30 )
return;
F_17 ( L_8 , F_26 ( V_25 ) ) ;
for( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
struct V_27 * V_31 = & V_25 -> V_27 [ V_26 ] ;
if ( ( V_31 -> V_32 & ~ 0x80 ) == 0x374 ) {
V_31 -> V_32 |= 2 ;
V_31 -> V_33 = V_31 -> V_32 ;
}
}
}
static void F_28 ( struct V_1 * V_25 )
{
int V_26 ;
F_17 ( L_9 , F_26 ( V_25 ) ) ;
for( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_25 -> V_27 [ V_26 ] . V_32 = V_25 -> V_27 [ V_26 ] . V_33 = V_25 -> V_27 [ V_26 ] . V_18 = 0 ;
}
static void F_29 ( struct V_1 * V_25 )
{
F_30 ( L_10 ) ;
V_34 = 32 ;
}
void F_31 ( struct V_3 * V_4 )
{
#if 0
printk("### PCIBIOS_FIXUP_BUS(%d)\n",bus->number);
#endif
F_32 ( V_4 ) ;
if ( V_4 -> V_10 == 0 ) {
struct V_1 * V_2 ;
F_33 (dev, &bus->devices, bus_list) {
if ( V_2 -> V_5 == 0 ) {
V_2 -> V_27 [ 0 ] . V_32 = 0 ;
V_2 -> V_27 [ 0 ] . V_33 = 0 ;
}
}
}
}
int T_2 F_34 ( void )
{
struct V_13 * V_35 = NULL ;
F_35 ( V_36 ) ;
if ( ! V_37 )
return - V_38 ;
V_39 |= V_40 | V_41 ;
F_36 ( 1 ) = ( ( V_42 + 0x01000000 ) >> 9 ) | 0x08000000 ;
F_36 ( 2 ) = ( ( V_42 + 0x00000000 ) >> 9 ) | 0x08000000 ;
* ( volatile V_43 * ) ( V_44 + 0x848 ) = 0xe0000000 ;
* ( volatile V_43 * ) ( V_44 + 0x8b8 ) = 0x00000000 ;
V_45 = ( V_42 + 0x04000000 ) >> 9 ;
V_46 = ( V_42 + 0x08000000 ) >> 9 ;
V_47 = V_42 + 0x04000000 ;
V_48 = V_42 + 0x08000000 ;
F_37 () ;
V_49 = V_50 ;
V_51 . V_32 = ( V_45 << 9 ) & 0xfffffc00 ;
V_51 . V_33 = ( V_52 << 9 ) | 0x3ff ;
V_51 . V_33 += V_51 . V_32 ;
F_17 ( L_11 ,
( unsigned long long ) V_51 . V_32 ,
( unsigned long long ) V_51 . V_33 ) ;
V_53 . V_32 = ( V_46 << 9 ) & 0xfffffc00 ;
V_53 . V_33 = ( V_54 << 9 ) | 0x3ff ;
V_53 . V_33 += V_53 . V_32 ;
V_53 . V_32 += 0x400 ;
F_17 ( L_12 ,
( unsigned long long ) V_53 . V_32 ,
( unsigned long long ) V_53 . V_33 ) ;
F_17 ( L_13 ,
V_55 , V_56 ) ;
if ( F_38 ( & V_57 , & V_53 ) < 0 )
F_39 ( L_14 ) ;
if ( F_38 ( & V_58 , & V_51 ) < 0 )
F_39 ( L_15 ) ;
if ( ! V_59 )
return - V_38 ;
V_35 = F_18 () ;
if ( V_35 )
V_24 = V_35 ;
else {
F_17 ( L_16 ) ;
return - V_38 ;
}
F_17 ( L_17 ) ;
F_40 ( & V_36 , & V_51 ) ;
F_40 ( & V_36 , & V_53 ) ;
F_41 ( NULL , 0 , V_24 , NULL , & V_36 ) ;
F_42 () ;
F_21 () ;
F_43 () ;
F_44 () ;
return 0 ;
}
char * T_2 F_45 ( char * V_60 )
{
if ( ! strcmp ( V_60 , L_18 ) ) {
V_59 = 0 ;
return NULL ;
} else if ( ! strncmp ( V_60 , L_19 , 8 ) ) {
V_22 = F_46 ( V_60 + 8 , NULL , 0 ) ;
return NULL ;
}
return V_60 ;
}
int F_47 ( struct V_1 * V_2 , int V_61 )
{
int V_62 ;
if ( ( V_62 = F_48 ( V_2 , V_61 ) ) < 0 )
return V_62 ;
if ( ! V_2 -> V_63 )
F_49 ( V_2 ) ;
return 0 ;
}
