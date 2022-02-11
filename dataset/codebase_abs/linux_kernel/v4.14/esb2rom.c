static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
F_2 ( V_2 -> V_7 , V_8 , & V_6 ) ;
F_3 ( V_2 -> V_7 , V_8 ,
V_6 & ~ V_9 ) ;
F_4 (map, scratch, &window->maps, list) {
if ( V_4 -> V_10 . V_11 )
F_5 ( & V_4 -> V_10 ) ;
F_6 ( V_4 -> V_12 ) ;
F_7 ( V_4 -> V_12 ) ;
F_8 ( & V_4 -> V_13 ) ;
F_9 ( V_4 ) ;
}
if ( V_2 -> V_10 . V_11 )
F_5 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_14 ) {
F_10 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
}
F_11 ( V_2 -> V_7 ) ;
}
static int T_2 F_12 ( struct V_17 * V_7 ,
const struct V_18 * V_19 )
{
static char * V_20 [] = { L_1 , L_2 , NULL } ;
struct V_1 * V_2 = & V_1 ;
struct V_3 * V_4 = NULL ;
unsigned long V_21 ;
T_1 V_6 ;
T_3 V_22 ;
V_2 -> V_7 = F_13 ( V_7 ) ;
V_2 -> V_15 = 0 ;
F_14 ( V_7 , V_23 , & V_22 ) ;
F_15 ( V_24 L_3 , V_22 ) ;
if ( ( V_22 & V_25 ) == V_25 )
V_2 -> V_15 = 0xff400000 ;
else if ( ( V_22 & V_26 ) == V_26 )
V_2 -> V_15 = 0xff500000 ;
else if ( ( V_22 & V_27 ) == V_27 )
V_2 -> V_15 = 0xff600000 ;
else if ( ( V_22 & V_28 ) == V_28 )
V_2 -> V_15 = 0xFF700000 ;
else if ( ( V_22 & V_29 ) == V_29 )
V_2 -> V_15 = 0xffc00000 ;
else if ( ( V_22 & V_30 ) == V_30 )
V_2 -> V_15 = 0xffc80000 ;
else if ( ( V_22 & V_31 ) == V_31 )
V_2 -> V_15 = 0xffd00000 ;
else if ( ( V_22 & V_32 ) == V_32 )
V_2 -> V_15 = 0xffd80000 ;
else if ( ( V_22 & V_33 ) == V_33 )
V_2 -> V_15 = 0xffe00000 ;
else if ( ( V_22 & V_34 ) == V_34 )
V_2 -> V_15 = 0xffe80000 ;
else if ( ( V_22 & V_35 ) == V_35 )
V_2 -> V_15 = 0xfff00000 ;
else if ( ( V_22 & V_36 ) == V_36 )
V_2 -> V_15 = 0xfff80000 ;
if ( V_2 -> V_15 == 0 ) {
F_15 (KERN_ERR MOD_NAME L_4 ) ;
goto V_37;
}
V_2 -> V_15 -= 0x400000UL ;
V_2 -> V_16 = ( 0xffffffffUL - V_2 -> V_15 ) + 1UL ;
F_2 ( V_7 , V_8 , & V_6 ) ;
if ( ! ( V_6 & V_9 ) && ( V_6 & ( V_38 ) ) ) {
F_15 (KERN_ERR MOD_NAME L_5 ) ;
goto V_37;
}
F_3 ( V_7 , V_8 , V_6 | V_9 ) ;
V_2 -> V_10 . V_39 = V_40 ;
V_2 -> V_10 . V_41 = V_2 -> V_15 ;
V_2 -> V_10 . V_42 = V_2 -> V_15 + V_2 -> V_16 - 1 ;
V_2 -> V_10 . V_43 = V_44 | V_45 ;
if ( F_16 ( & V_46 , & V_2 -> V_10 ) ) {
V_2 -> V_10 . V_11 = NULL ;
F_15 (KERN_DEBUG MOD_NAME L_6
L_7 ,
__func__, &window->rsrc) ;
}
V_2 -> V_14 = F_17 ( V_2 -> V_15 , V_2 -> V_16 ) ;
if ( ! V_2 -> V_14 ) {
F_15 (KERN_ERR MOD_NAME L_8 ,
window->phys, window->size) ;
goto V_37;
}
V_21 = V_2 -> V_15 ;
if ( ( V_2 -> V_15 & 0x3fffff ) != 0 ) {
V_21 = V_2 -> V_15 + 0x400000 ;
}
#if 1
if ( V_21 < 0xffc00000 )
V_21 = 0xffc00000 ;
#endif
while ( ( V_21 - 1 ) < 0xffffffffUL ) {
struct V_47 * V_48 ;
unsigned long V_49 ;
int V_50 ;
if ( ! V_4 )
V_4 = F_18 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 ) {
F_15 (KERN_ERR MOD_NAME L_9 ) ;
goto V_37;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_19 ( & V_4 -> V_13 ) ;
V_4 -> V_4 . V_39 = V_4 -> V_52 ;
V_4 -> V_4 . V_15 = V_21 ;
V_49 = V_21 - V_2 -> V_15 ;
V_4 -> V_4 . V_14 = ( void V_53 * )
( ( ( unsigned long ) ( V_2 -> V_14 ) ) + V_49 ) ;
V_4 -> V_4 . V_16 = 0xffffffffUL - V_21 + 1UL ;
sprintf ( V_4 -> V_52 , L_10 ,
V_40 , ( unsigned long long ) V_4 -> V_4 . V_15 ) ;
for( V_4 -> V_4 . V_54 = 32 ; V_4 -> V_4 . V_54 ;
V_4 -> V_4 . V_54 >>= 1 ) {
char * * V_55 ;
if ( ! F_20 ( V_4 -> V_4 . V_54 ) )
continue;
F_21 ( & V_4 -> V_4 ) ;
V_55 = V_20 ;
for(; * V_55 ; V_55 ++ ) {
V_4 -> V_12 = F_22 ( * V_55 , & V_4 -> V_4 ) ;
if ( V_4 -> V_12 )
goto V_56;
}
}
V_21 += V_57 ;
continue;
V_56:
if ( V_4 -> V_12 -> V_16 > V_4 -> V_4 . V_16 ) {
F_15 (KERN_WARNING MOD_NAME
L_11 ,
(unsigned long long)map->mtd->size, map->map.size) ;
V_4 -> V_12 -> V_16 = V_4 -> V_4 . V_16 ;
}
if ( V_2 -> V_10 . V_11 ) {
V_4 -> V_10 . V_39 = V_4 -> V_52 ;
V_4 -> V_10 . V_41 = V_4 -> V_4 . V_15 ;
V_4 -> V_10 . V_42 = V_4 -> V_4 . V_15 + V_4 -> V_12 -> V_16 - 1 ;
V_4 -> V_10 . V_43 = V_44 | V_45 ;
if ( F_16 ( & V_2 -> V_10 , & V_4 -> V_10 ) ) {
F_15 (KERN_ERR MOD_NAME
L_12 ) ;
V_4 -> V_10 . V_11 = NULL ;
}
}
V_4 -> V_4 . V_14 = V_2 -> V_14 ;
V_4 -> V_4 . V_15 = V_2 -> V_15 ;
V_48 = V_4 -> V_4 . V_58 ;
for( V_50 = 0 ; V_50 < V_48 -> V_59 ; V_50 ++ )
V_48 -> V_60 [ V_50 ] . V_41 += V_49 ;
V_4 -> V_12 -> V_61 = V_62 ;
if ( F_23 ( V_4 -> V_12 , NULL , 0 ) ) {
F_7 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
goto V_37;
}
V_21 += V_4 -> V_12 -> V_16 ;
F_24 ( & V_4 -> V_13 , & V_2 -> V_63 ) ;
V_4 = NULL ;
}
V_37:
F_9 ( V_4 ) ;
if ( F_25 ( & V_2 -> V_63 ) ) {
F_1 ( V_2 ) ;
return - V_64 ;
}
return 0 ;
}
static void F_26 ( struct V_17 * V_7 )
{
struct V_1 * V_2 = & V_1 ;
F_1 ( V_2 ) ;
}
static int T_2 F_27 ( void )
{
struct V_17 * V_7 ;
const struct V_18 * V_65 ;
int V_66 ;
V_7 = NULL ;
for ( V_65 = V_67 ; V_65 -> V_68 ; V_65 ++ ) {
F_15 ( V_24 L_13 , V_65 -> V_69 ) ;
V_7 = F_28 ( V_65 -> V_68 , V_65 -> V_69 , NULL ) ;
if ( V_7 ) {
F_15 ( V_24 L_14 , V_65 -> V_69 ) ;
break;
}
}
if ( V_7 ) {
F_15 ( V_24 L_15 , V_65 -> V_69 ) ;
V_66 = F_12 ( V_7 , & V_67 [ 0 ] ) ;
F_11 ( V_7 ) ;
F_15 ( V_24 L_16 , V_66 ) ;
return V_66 ;
}
return - V_70 ;
#if 0
return pci_register_driver(&esb2rom_driver);
#endif
}
static void T_4 F_29 ( void )
{
F_26 ( V_1 . V_7 ) ;
}
