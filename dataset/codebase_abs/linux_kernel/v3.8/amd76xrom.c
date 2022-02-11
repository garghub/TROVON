static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
if ( V_2 -> V_7 ) {
F_2 ( V_2 -> V_7 , 0x40 , & V_6 ) ;
F_3 ( V_2 -> V_7 , 0x40 , V_6 & ~ 1 ) ;
F_4 ( V_2 -> V_7 ) ;
}
F_5 (map, scratch, &window->maps, list) {
if ( V_4 -> V_8 . V_9 ) {
F_6 ( & V_4 -> V_8 ) ;
}
F_7 ( V_4 -> V_10 ) ;
F_8 ( V_4 -> V_10 ) ;
F_9 ( & V_4 -> V_11 ) ;
F_10 ( V_4 ) ;
}
if ( V_2 -> V_8 . V_9 )
F_6 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_12 ) {
F_11 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_7 = NULL ;
}
}
static int F_12 ( struct V_15 * V_7 ,
const struct V_16 * V_17 )
{
static char * V_18 [] = { L_1 , L_2 , NULL } ;
T_1 V_6 ;
struct V_1 * V_2 = & V_1 ;
struct V_3 * V_4 = NULL ;
unsigned long V_19 ;
V_2 -> V_7 = V_7 ;
F_2 ( V_7 , 0x43 , & V_6 ) ;
F_3 ( V_7 , 0x43 , V_6 | V_20 ) ;
F_2 ( V_7 , 0x43 , & V_6 ) ;
if ( ( V_6 & ( ( 1 << 7 ) | ( 1 << 6 ) ) ) == ( ( 1 << 7 ) | ( 1 << 6 ) ) ) {
V_2 -> V_13 = 0xffb00000 ;
}
else if ( ( V_6 & ( 1 << 7 ) ) == ( 1 << 7 ) ) {
V_2 -> V_13 = 0xffc00000 ;
}
else {
V_2 -> V_13 = 0xffff0000 ;
}
V_2 -> V_14 = 0xffffffffUL - V_2 -> V_13 + 1UL ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_23 = V_2 -> V_13 ;
V_2 -> V_8 . V_24 = V_2 -> V_13 + V_2 -> V_14 - 1 ;
V_2 -> V_8 . V_25 = V_26 | V_27 ;
if ( F_13 ( & V_28 , & V_2 -> V_8 ) ) {
V_2 -> V_8 . V_9 = NULL ;
F_14 (KERN_ERR MOD_NAME
L_3 ,
__func__, &window->rsrc) ;
return - V_29 ;
}
F_2 ( V_7 , 0x40 , & V_6 ) ;
F_3 ( V_7 , 0x40 , V_6 | 1 ) ;
V_2 -> V_12 = F_15 ( V_2 -> V_13 , V_2 -> V_14 ) ;
if ( ! V_2 -> V_12 ) {
F_14 (KERN_ERR MOD_NAME L_4 ,
window->phys, window->size) ;
goto V_30;
}
V_19 = V_2 -> V_13 ;
#if 1
if ( V_19 < 0xffc00000 ) {
V_19 = 0xffc00000 ;
}
#endif
while( ( V_19 - 1 ) < 0xffffffffUL ) {
struct V_31 * V_32 ;
unsigned long V_33 ;
int V_34 ;
if ( ! V_4 ) {
V_4 = F_16 ( sizeof( * V_4 ) , V_35 ) ;
}
if ( ! V_4 ) {
F_14 (KERN_ERR MOD_NAME L_5 ) ;
goto V_30;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_17 ( & V_4 -> V_11 ) ;
V_4 -> V_4 . V_21 = V_4 -> V_36 ;
V_4 -> V_4 . V_13 = V_19 ;
V_33 = V_19 - V_2 -> V_13 ;
V_4 -> V_4 . V_12 = ( void V_37 * )
( ( ( unsigned long ) ( V_2 -> V_12 ) ) + V_33 ) ;
V_4 -> V_4 . V_14 = 0xffffffffUL - V_19 + 1UL ;
sprintf ( V_4 -> V_36 , L_6 ,
V_22 , ( unsigned long long ) V_4 -> V_4 . V_13 ) ;
for( V_4 -> V_4 . V_38 = 32 ; V_4 -> V_4 . V_38 ;
V_4 -> V_4 . V_38 >>= 1 )
{
char * * V_39 ;
if ( ! F_18 ( V_4 -> V_4 . V_38 ) )
continue;
F_19 ( & V_4 -> V_4 ) ;
V_39 = V_18 ;
for(; * V_39 ; V_39 ++ ) {
V_4 -> V_10 = F_20 ( * V_39 , & V_4 -> V_4 ) ;
if ( V_4 -> V_10 )
goto V_40;
}
}
V_19 += V_41 ;
continue;
V_40:
if ( V_4 -> V_10 -> V_14 > V_4 -> V_4 . V_14 ) {
F_14 (KERN_WARNING MOD_NAME
L_7 ,
(unsigned long long)map->mtd->size, map->map.size) ;
V_4 -> V_10 -> V_14 = V_4 -> V_4 . V_14 ;
}
if ( V_2 -> V_8 . V_9 ) {
V_4 -> V_8 . V_21 = V_4 -> V_36 ;
V_4 -> V_8 . V_23 = V_4 -> V_4 . V_13 ;
V_4 -> V_8 . V_24 = V_4 -> V_4 . V_13 + V_4 -> V_10 -> V_14 - 1 ;
V_4 -> V_8 . V_25 = V_26 | V_27 ;
if ( F_13 ( & V_2 -> V_8 , & V_4 -> V_8 ) ) {
F_14 (KERN_ERR MOD_NAME
L_8 ) ;
V_4 -> V_8 . V_9 = NULL ;
}
}
V_4 -> V_4 . V_12 = V_2 -> V_12 ;
V_4 -> V_4 . V_13 = V_2 -> V_13 ;
V_32 = V_4 -> V_4 . V_42 ;
for( V_34 = 0 ; V_34 < V_32 -> V_43 ; V_34 ++ ) {
V_32 -> V_44 [ V_34 ] . V_23 += V_33 ;
}
V_4 -> V_10 -> V_45 = V_46 ;
if ( F_21 ( V_4 -> V_10 , NULL , 0 ) ) {
F_8 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
goto V_30;
}
V_19 += V_4 -> V_10 -> V_14 ;
F_22 ( & V_4 -> V_11 , & V_2 -> V_47 ) ;
V_4 = NULL ;
}
V_30:
F_10 ( V_4 ) ;
if ( F_23 ( & V_2 -> V_47 ) ) {
F_1 ( V_2 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_24 ( struct V_15 * V_7 )
{
struct V_1 * V_2 = & V_1 ;
F_1 ( V_2 ) ;
}
static int T_2 F_25 ( void )
{
struct V_15 * V_7 ;
struct V_16 * V_49 ;
V_7 = NULL ;
for( V_49 = V_50 ; V_49 -> V_51 ; V_49 ++ ) {
V_7 = F_26 ( V_49 -> V_51 , V_49 -> V_52 , NULL ) ;
if ( V_7 ) {
break;
}
}
if ( V_7 ) {
return F_12 ( V_7 , & V_50 [ 0 ] ) ;
}
return - V_53 ;
#if 0
return pci_register_driver(&amd76xrom_driver);
#endif
}
static void T_3 F_27 ( void )
{
F_24 ( V_1 . V_7 ) ;
}
