static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 , & V_6 ) ;
if ( ! V_7 )
F_3 ( V_2 -> V_8 , V_9 , V_6 & ~ 1 ) ;
F_4 ( V_2 -> V_8 ) ;
F_5 (map, scratch, &window->maps, list) {
if ( V_4 -> V_10 . V_11 )
F_6 ( & V_4 -> V_10 ) ;
F_7 ( V_4 -> V_12 ) ;
F_8 ( V_4 -> V_12 ) ;
F_9 ( & V_4 -> V_13 ) ;
F_10 ( V_4 ) ;
}
if ( V_2 -> V_10 . V_11 )
F_6 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_14 ) {
F_11 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_8 = NULL ;
}
}
static int T_2 F_12 ( struct V_17 * V_8 ,
const struct V_18 * V_19 )
{
static char * V_20 [] = { L_1 , L_2 , NULL } ;
struct V_1 * V_2 = & V_1 ;
struct V_3 * V_4 = NULL ;
unsigned long V_21 ;
T_3 V_22 ;
T_1 V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_15 = 0 ;
F_13 ( V_8 , V_23 , & V_22 ) ;
if ( V_22 == 0xff ) {
V_2 -> V_15 = 0xffc00000 ;
F_13 ( V_8 , V_24 , & V_22 ) ;
if ( ( V_22 & 0x0f ) == 0x0f ) {
V_2 -> V_15 = 0xff400000 ;
}
else if ( ( V_22 & 0x0e ) == 0x0e ) {
V_2 -> V_15 = 0xff500000 ;
}
else if ( ( V_22 & 0x0c ) == 0x0c ) {
V_2 -> V_15 = 0xff600000 ;
}
else if ( ( V_22 & 0x08 ) == 0x08 ) {
V_2 -> V_15 = 0xff700000 ;
}
}
else if ( ( V_22 & 0xfe ) == 0xfe ) {
V_2 -> V_15 = 0xffc80000 ;
}
else if ( ( V_22 & 0xfc ) == 0xfc ) {
V_2 -> V_15 = 0xffd00000 ;
}
else if ( ( V_22 & 0xf8 ) == 0xf8 ) {
V_2 -> V_15 = 0xffd80000 ;
}
else if ( ( V_22 & 0xf0 ) == 0xf0 ) {
V_2 -> V_15 = 0xffe00000 ;
}
else if ( ( V_22 & 0xe0 ) == 0xe0 ) {
V_2 -> V_15 = 0xffe80000 ;
}
else if ( ( V_22 & 0xc0 ) == 0xc0 ) {
V_2 -> V_15 = 0xfff00000 ;
}
else if ( ( V_22 & 0x80 ) == 0x80 ) {
V_2 -> V_15 = 0xfff80000 ;
}
if ( V_2 -> V_15 == 0 ) {
F_14 (KERN_ERR MOD_NAME L_3 ) ;
goto V_25;
}
V_2 -> V_15 -= 0x400000UL ;
V_2 -> V_16 = ( 0xffffffffUL - V_2 -> V_15 ) + 1UL ;
F_2 ( V_8 , V_9 , & V_6 ) ;
if ( ! ( V_6 & 1 ) && ( V_6 & ( 1 << 1 ) ) ) {
F_14 (KERN_ERR MOD_NAME L_4 ) ;
goto V_25;
}
F_3 ( V_8 , V_9 , V_6 | 1 ) ;
V_2 -> V_10 . V_26 = V_27 ;
V_2 -> V_10 . V_28 = V_2 -> V_15 ;
V_2 -> V_10 . V_29 = V_2 -> V_15 + V_2 -> V_16 - 1 ;
V_2 -> V_10 . V_30 = V_31 | V_32 ;
if ( F_15 ( & V_33 , & V_2 -> V_10 ) ) {
V_2 -> V_10 . V_11 = NULL ;
F_14 (KERN_DEBUG MOD_NAME L_5
L_6 ,
__func__, &window->rsrc) ;
}
V_2 -> V_14 = F_16 ( V_2 -> V_15 , V_2 -> V_16 ) ;
if ( ! V_2 -> V_14 ) {
F_14 (KERN_ERR MOD_NAME L_7 ,
window->phys, window->size) ;
goto V_25;
}
V_21 = V_2 -> V_15 ;
if ( ( V_2 -> V_15 & 0x3fffff ) != 0 ) {
V_21 = V_2 -> V_15 + 0x400000 ;
}
#if 1
if ( V_21 < 0xffc00000 ) {
V_21 = 0xffc00000 ;
}
#endif
while( ( V_21 - 1 ) < 0xffffffffUL ) {
struct V_34 * V_35 ;
unsigned long V_36 ;
int V_37 ;
if ( ! V_4 ) {
V_4 = F_17 ( sizeof( * V_4 ) , V_38 ) ;
}
if ( ! V_4 ) {
F_14 (KERN_ERR MOD_NAME L_8 ) ;
goto V_25;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_18 ( & V_4 -> V_13 ) ;
V_4 -> V_4 . V_26 = V_4 -> V_39 ;
V_4 -> V_4 . V_15 = V_21 ;
V_36 = V_21 - V_2 -> V_15 ;
V_4 -> V_4 . V_14 = ( void V_40 * )
( ( ( unsigned long ) ( V_2 -> V_14 ) ) + V_36 ) ;
V_4 -> V_4 . V_16 = 0xffffffffUL - V_21 + 1UL ;
sprintf ( V_4 -> V_39 , L_9 ,
V_27 , ( unsigned long long ) V_4 -> V_4 . V_15 ) ;
for( V_4 -> V_4 . V_41 = 32 ; V_4 -> V_4 . V_41 ;
V_4 -> V_4 . V_41 >>= 1 )
{
char * * V_42 ;
if ( ! F_19 ( V_4 -> V_4 . V_41 ) )
continue;
F_20 ( & V_4 -> V_4 ) ;
V_42 = V_20 ;
for(; * V_42 ; V_42 ++ ) {
V_4 -> V_12 = F_21 ( * V_42 , & V_4 -> V_4 ) ;
if ( V_4 -> V_12 )
goto V_43;
}
}
V_21 += V_44 ;
continue;
V_43:
if ( V_4 -> V_12 -> V_16 > V_4 -> V_4 . V_16 ) {
F_14 (KERN_WARNING MOD_NAME
L_10 ,
(unsigned long long)map->mtd->size, map->map.size) ;
V_4 -> V_12 -> V_16 = V_4 -> V_4 . V_16 ;
}
if ( V_2 -> V_10 . V_11 ) {
V_4 -> V_10 . V_26 = V_4 -> V_39 ;
V_4 -> V_10 . V_28 = V_4 -> V_4 . V_15 ;
V_4 -> V_10 . V_29 = V_4 -> V_4 . V_15 + V_4 -> V_12 -> V_16 - 1 ;
V_4 -> V_10 . V_30 = V_31 | V_32 ;
if ( F_15 ( & V_2 -> V_10 , & V_4 -> V_10 ) ) {
F_14 (KERN_ERR MOD_NAME
L_11 ) ;
V_4 -> V_10 . V_11 = NULL ;
}
}
V_4 -> V_4 . V_14 = V_2 -> V_14 ;
V_4 -> V_4 . V_15 = V_2 -> V_15 ;
V_35 = V_4 -> V_4 . V_45 ;
for( V_37 = 0 ; V_37 < V_35 -> V_46 ; V_37 ++ ) {
V_35 -> V_47 [ V_37 ] . V_28 += V_36 ;
}
V_4 -> V_12 -> V_48 = V_49 ;
if ( F_22 ( V_4 -> V_12 , NULL , 0 ) ) {
F_8 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
goto V_25;
}
V_21 += V_4 -> V_12 -> V_16 ;
F_23 ( & V_4 -> V_13 , & V_2 -> V_50 ) ;
V_4 = NULL ;
}
V_25:
F_10 ( V_4 ) ;
if ( F_24 ( & V_2 -> V_50 ) ) {
F_1 ( V_2 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_25 ( struct V_17 * V_8 )
{
struct V_1 * V_2 = & V_1 ;
F_1 ( V_2 ) ;
}
static int T_2 F_26 ( void )
{
struct V_17 * V_8 ;
const struct V_18 * V_52 ;
V_8 = NULL ;
for ( V_52 = V_53 ; V_52 -> V_54 ; V_52 ++ ) {
V_8 = F_27 ( V_52 -> V_54 , V_52 -> V_55 , NULL ) ;
if ( V_8 ) {
break;
}
}
if ( V_8 ) {
return F_12 ( V_8 , & V_53 [ 0 ] ) ;
}
return - V_56 ;
#if 0
return pci_register_driver(&ichxrom_driver);
#endif
}
static void T_4 F_28 ( void )
{
F_25 ( V_1 . V_8 ) ;
}
