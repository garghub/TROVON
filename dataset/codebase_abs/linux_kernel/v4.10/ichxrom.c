static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
F_2 ( V_2 -> V_7 , V_8 , & V_6 ) ;
F_3 ( V_2 -> V_7 , V_8 , V_6 & ~ 1 ) ;
F_4 ( V_2 -> V_7 ) ;
F_5 (map, scratch, &window->maps, list) {
if ( V_4 -> V_9 . V_10 )
F_6 ( & V_4 -> V_9 ) ;
F_7 ( V_4 -> V_11 ) ;
F_8 ( V_4 -> V_11 ) ;
F_9 ( & V_4 -> V_12 ) ;
F_10 ( V_4 ) ;
}
if ( V_2 -> V_9 . V_10 )
F_6 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_13 ) {
F_11 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_7 = NULL ;
}
}
static int T_2 F_12 ( struct V_16 * V_7 ,
const struct V_17 * V_18 )
{
static char * V_19 [] = { L_1 , L_2 , NULL } ;
struct V_1 * V_2 = & V_1 ;
struct V_3 * V_4 = NULL ;
unsigned long V_20 ;
T_3 V_21 ;
T_1 V_6 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_14 = 0 ;
F_13 ( V_7 , V_22 , & V_21 ) ;
if ( V_21 == 0xff ) {
V_2 -> V_14 = 0xffc00000 ;
F_13 ( V_7 , V_23 , & V_21 ) ;
if ( ( V_21 & 0x0f ) == 0x0f ) {
V_2 -> V_14 = 0xff400000 ;
}
else if ( ( V_21 & 0x0e ) == 0x0e ) {
V_2 -> V_14 = 0xff500000 ;
}
else if ( ( V_21 & 0x0c ) == 0x0c ) {
V_2 -> V_14 = 0xff600000 ;
}
else if ( ( V_21 & 0x08 ) == 0x08 ) {
V_2 -> V_14 = 0xff700000 ;
}
}
else if ( ( V_21 & 0xfe ) == 0xfe ) {
V_2 -> V_14 = 0xffc80000 ;
}
else if ( ( V_21 & 0xfc ) == 0xfc ) {
V_2 -> V_14 = 0xffd00000 ;
}
else if ( ( V_21 & 0xf8 ) == 0xf8 ) {
V_2 -> V_14 = 0xffd80000 ;
}
else if ( ( V_21 & 0xf0 ) == 0xf0 ) {
V_2 -> V_14 = 0xffe00000 ;
}
else if ( ( V_21 & 0xe0 ) == 0xe0 ) {
V_2 -> V_14 = 0xffe80000 ;
}
else if ( ( V_21 & 0xc0 ) == 0xc0 ) {
V_2 -> V_14 = 0xfff00000 ;
}
else if ( ( V_21 & 0x80 ) == 0x80 ) {
V_2 -> V_14 = 0xfff80000 ;
}
if ( V_2 -> V_14 == 0 ) {
F_14 (KERN_ERR MOD_NAME L_3 ) ;
goto V_24;
}
V_2 -> V_14 -= 0x400000UL ;
V_2 -> V_15 = ( 0xffffffffUL - V_2 -> V_14 ) + 1UL ;
F_2 ( V_7 , V_8 , & V_6 ) ;
if ( ! ( V_6 & 1 ) && ( V_6 & ( 1 << 1 ) ) ) {
F_14 (KERN_ERR MOD_NAME L_4 ) ;
goto V_24;
}
F_3 ( V_7 , V_8 , V_6 | 1 ) ;
V_2 -> V_9 . V_25 = V_26 ;
V_2 -> V_9 . V_27 = V_2 -> V_14 ;
V_2 -> V_9 . V_28 = V_2 -> V_14 + V_2 -> V_15 - 1 ;
V_2 -> V_9 . V_29 = V_30 | V_31 ;
if ( F_15 ( & V_32 , & V_2 -> V_9 ) ) {
V_2 -> V_9 . V_10 = NULL ;
F_14 (KERN_DEBUG MOD_NAME L_5
L_6 ,
__func__, &window->rsrc) ;
}
V_2 -> V_13 = F_16 ( V_2 -> V_14 , V_2 -> V_15 ) ;
if ( ! V_2 -> V_13 ) {
F_14 (KERN_ERR MOD_NAME L_7 ,
window->phys, window->size) ;
goto V_24;
}
V_20 = V_2 -> V_14 ;
if ( ( V_2 -> V_14 & 0x3fffff ) != 0 ) {
V_20 = V_2 -> V_14 + 0x400000 ;
}
#if 1
if ( V_20 < 0xffc00000 ) {
V_20 = 0xffc00000 ;
}
#endif
while( ( V_20 - 1 ) < 0xffffffffUL ) {
struct V_33 * V_34 ;
unsigned long V_35 ;
int V_36 ;
if ( ! V_4 ) {
V_4 = F_17 ( sizeof( * V_4 ) , V_37 ) ;
}
if ( ! V_4 ) {
F_14 (KERN_ERR MOD_NAME L_8 ) ;
goto V_24;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_18 ( & V_4 -> V_12 ) ;
V_4 -> V_4 . V_25 = V_4 -> V_38 ;
V_4 -> V_4 . V_14 = V_20 ;
V_35 = V_20 - V_2 -> V_14 ;
V_4 -> V_4 . V_13 = ( void V_39 * )
( ( ( unsigned long ) ( V_2 -> V_13 ) ) + V_35 ) ;
V_4 -> V_4 . V_15 = 0xffffffffUL - V_20 + 1UL ;
sprintf ( V_4 -> V_38 , L_9 ,
V_26 , ( unsigned long long ) V_4 -> V_4 . V_14 ) ;
for( V_4 -> V_4 . V_40 = 32 ; V_4 -> V_4 . V_40 ;
V_4 -> V_4 . V_40 >>= 1 )
{
char * * V_41 ;
if ( ! F_19 ( V_4 -> V_4 . V_40 ) )
continue;
F_20 ( & V_4 -> V_4 ) ;
V_41 = V_19 ;
for(; * V_41 ; V_41 ++ ) {
V_4 -> V_11 = F_21 ( * V_41 , & V_4 -> V_4 ) ;
if ( V_4 -> V_11 )
goto V_42;
}
}
V_20 += V_43 ;
continue;
V_42:
if ( V_4 -> V_11 -> V_15 > V_4 -> V_4 . V_15 ) {
F_14 (KERN_WARNING MOD_NAME
L_10 ,
(unsigned long long)map->mtd->size, map->map.size) ;
V_4 -> V_11 -> V_15 = V_4 -> V_4 . V_15 ;
}
if ( V_2 -> V_9 . V_10 ) {
V_4 -> V_9 . V_25 = V_4 -> V_38 ;
V_4 -> V_9 . V_27 = V_4 -> V_4 . V_14 ;
V_4 -> V_9 . V_28 = V_4 -> V_4 . V_14 + V_4 -> V_11 -> V_15 - 1 ;
V_4 -> V_9 . V_29 = V_30 | V_31 ;
if ( F_15 ( & V_2 -> V_9 , & V_4 -> V_9 ) ) {
F_14 (KERN_ERR MOD_NAME
L_11 ) ;
V_4 -> V_9 . V_10 = NULL ;
}
}
V_4 -> V_4 . V_13 = V_2 -> V_13 ;
V_4 -> V_4 . V_14 = V_2 -> V_14 ;
V_34 = V_4 -> V_4 . V_44 ;
for( V_36 = 0 ; V_36 < V_34 -> V_45 ; V_36 ++ ) {
V_34 -> V_46 [ V_36 ] . V_27 += V_35 ;
}
V_4 -> V_11 -> V_47 = V_48 ;
if ( F_22 ( V_4 -> V_11 , NULL , 0 ) ) {
F_8 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
goto V_24;
}
V_20 += V_4 -> V_11 -> V_15 ;
F_23 ( & V_4 -> V_12 , & V_2 -> V_49 ) ;
V_4 = NULL ;
}
V_24:
F_10 ( V_4 ) ;
if ( F_24 ( & V_2 -> V_49 ) ) {
F_1 ( V_2 ) ;
return - V_50 ;
}
return 0 ;
}
static void F_25 ( struct V_16 * V_7 )
{
struct V_1 * V_2 = & V_1 ;
F_1 ( V_2 ) ;
}
static int T_2 F_26 ( void )
{
struct V_16 * V_7 ;
struct V_17 * V_51 ;
V_7 = NULL ;
for ( V_51 = V_52 ; V_51 -> V_53 ; V_51 ++ ) {
V_7 = F_27 ( V_51 -> V_53 , V_51 -> V_54 , NULL ) ;
if ( V_7 ) {
break;
}
}
if ( V_7 ) {
return F_12 ( V_7 , & V_52 [ 0 ] ) ;
}
return - V_55 ;
#if 0
return pci_register_driver(&ichxrom_driver);
#endif
}
static void T_4 F_28 ( void )
{
F_25 ( V_1 . V_7 ) ;
}
