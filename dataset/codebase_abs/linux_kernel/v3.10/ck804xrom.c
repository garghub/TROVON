static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
if ( V_2 -> V_7 ) {
F_2 ( V_2 -> V_7 , 0x6d , & V_6 ) ;
F_3 ( V_2 -> V_7 , 0x6d , V_6 & ~ 1 ) ;
}
F_4 (map, scratch, &window->maps, list) {
if ( V_4 -> V_8 . V_9 )
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_4 -> V_10 ) ;
F_7 ( V_4 -> V_10 ) ;
F_8 ( & V_4 -> V_11 ) ;
F_9 ( V_4 ) ;
}
if ( V_2 -> V_8 . V_9 )
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_12 ) {
F_10 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
}
F_11 ( V_2 -> V_7 ) ;
}
static int F_12 ( struct V_15 * V_7 ,
const struct V_16 * V_17 )
{
static char * V_18 [] = { L_1 , L_2 , NULL } ;
T_1 V_6 ;
T_2 V_19 ;
struct V_1 * V_2 = & V_1 ;
struct V_3 * V_4 = NULL ;
unsigned long V_20 ;
V_2 -> V_7 = F_13 ( V_7 ) ;
switch ( V_17 -> V_21 ) {
case V_22 :
F_2 ( V_7 , 0x88 , & V_6 ) ;
F_3 ( V_7 , 0x88 , V_6 | V_23 ) ;
F_2 ( V_7 , 0x88 , & V_6 ) ;
if ( ( V_6 & ( ( 1 << 7 ) | ( 1 << 6 ) ) ) == ( ( 1 << 7 ) | ( 1 << 6 ) ) )
V_2 -> V_13 = 0xffb00000 ;
else if ( ( V_6 & ( 1 << 7 ) ) == ( 1 << 7 ) )
V_2 -> V_13 = 0xffc00000 ;
else
V_2 -> V_13 = 0xffff0000 ;
break;
case V_24 :
F_2 ( V_7 , 0x88 , & V_6 ) ;
F_3 ( V_7 , 0x88 , V_6 | ( V_23 & 0xff ) ) ;
F_2 ( V_7 , 0x8c , & V_6 ) ;
F_3 ( V_7 , 0x8c , V_6 | ( ( V_23 & 0xff00 ) >> 8 ) ) ;
F_14 ( V_7 , 0x90 , & V_19 ) ;
F_15 ( V_7 , 0x90 , V_19 | ( ( V_23 & 0x7fff0000 ) >> 16 ) ) ;
V_2 -> V_13 = 0xff000000 ;
break;
}
V_2 -> V_14 = 0xffffffffUL - V_2 -> V_13 + 1UL ;
V_2 -> V_8 . V_25 = V_26 ;
V_2 -> V_8 . V_27 = V_2 -> V_13 ;
V_2 -> V_8 . V_28 = V_2 -> V_13 + V_2 -> V_14 - 1 ;
V_2 -> V_8 . V_29 = V_30 | V_31 ;
if ( F_16 ( & V_32 , & V_2 -> V_8 ) ) {
V_2 -> V_8 . V_9 = NULL ;
F_17 (KERN_ERR MOD_NAME
L_3 ,
__func__, &window->rsrc) ;
}
F_2 ( V_7 , 0x6d , & V_6 ) ;
F_3 ( V_7 , 0x6d , V_6 | 1 ) ;
V_2 -> V_12 = F_18 ( V_2 -> V_13 , V_2 -> V_14 ) ;
if ( ! V_2 -> V_12 ) {
F_17 (KERN_ERR MOD_NAME L_4 ,
window->phys, window->size) ;
goto V_33;
}
V_20 = V_2 -> V_13 ;
#if 1
if ( V_20 < 0xffc00000 )
V_20 = 0xffc00000 ;
#endif
while( ( V_20 - 1 ) < 0xffffffffUL ) {
struct V_34 * V_35 ;
unsigned long V_36 ;
int V_37 ;
if ( ! V_4 )
V_4 = F_19 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
F_17 (KERN_ERR MOD_NAME L_5 ) ;
goto V_33;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_20 ( & V_4 -> V_11 ) ;
V_4 -> V_4 . V_25 = V_4 -> V_39 ;
V_4 -> V_4 . V_13 = V_20 ;
V_36 = V_20 - V_2 -> V_13 ;
V_4 -> V_4 . V_12 = ( void V_40 * )
( ( ( unsigned long ) ( V_2 -> V_12 ) ) + V_36 ) ;
V_4 -> V_4 . V_14 = 0xffffffffUL - V_20 + 1UL ;
sprintf ( V_4 -> V_39 , L_6 ,
V_26 , ( unsigned long long ) V_4 -> V_4 . V_13 ) ;
for( V_4 -> V_4 . V_41 = 32 ; V_4 -> V_4 . V_41 ;
V_4 -> V_4 . V_41 >>= 1 )
{
char * * V_42 ;
if ( ! F_21 ( V_4 -> V_4 . V_41 ) )
continue;
F_22 ( & V_4 -> V_4 ) ;
V_42 = V_18 ;
for(; * V_42 ; V_42 ++ ) {
V_4 -> V_10 = F_23 ( * V_42 , & V_4 -> V_4 ) ;
if ( V_4 -> V_10 )
goto V_43;
}
}
V_20 += V_44 ;
continue;
V_43:
if ( V_4 -> V_10 -> V_14 > V_4 -> V_4 . V_14 ) {
F_17 (KERN_WARNING MOD_NAME
L_7 ,
(unsigned long long)map->mtd->size, map->map.size) ;
V_4 -> V_10 -> V_14 = V_4 -> V_4 . V_14 ;
}
if ( V_2 -> V_8 . V_9 ) {
V_4 -> V_8 . V_25 = V_4 -> V_39 ;
V_4 -> V_8 . V_27 = V_4 -> V_4 . V_13 ;
V_4 -> V_8 . V_28 = V_4 -> V_4 . V_13 + V_4 -> V_10 -> V_14 - 1 ;
V_4 -> V_8 . V_29 = V_30 | V_31 ;
if ( F_16 ( & V_2 -> V_8 , & V_4 -> V_8 ) ) {
F_17 (KERN_ERR MOD_NAME
L_8 ) ;
V_4 -> V_8 . V_9 = NULL ;
}
}
V_4 -> V_4 . V_12 = V_2 -> V_12 ;
V_4 -> V_4 . V_13 = V_2 -> V_13 ;
V_35 = V_4 -> V_4 . V_45 ;
for( V_37 = 0 ; V_37 < V_35 -> V_46 ; V_37 ++ )
V_35 -> V_47 [ V_37 ] . V_27 += V_36 ;
V_4 -> V_10 -> V_48 = V_49 ;
if ( F_24 ( V_4 -> V_10 , NULL , 0 ) ) {
F_7 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
goto V_33;
}
V_20 += V_4 -> V_10 -> V_14 ;
F_25 ( & V_4 -> V_11 , & V_2 -> V_50 ) ;
V_4 = NULL ;
}
V_33:
F_9 ( V_4 ) ;
if ( F_26 ( & V_2 -> V_50 ) ) {
F_1 ( V_2 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_27 ( struct V_15 * V_7 )
{
struct V_1 * V_2 = & V_1 ;
F_1 ( V_2 ) ;
}
static int T_3 F_28 ( void )
{
struct V_15 * V_7 ;
struct V_16 * V_52 ;
int V_53 ;
V_7 = NULL ;
for( V_52 = V_54 ; V_52 -> V_55 ; V_52 ++ ) {
V_7 = F_29 ( V_52 -> V_55 , V_52 -> V_56 , NULL ) ;
if ( V_7 )
break;
}
if ( V_7 ) {
V_53 = F_12 ( V_7 , V_52 ) ;
F_11 ( V_7 ) ;
return V_53 ;
}
return - V_57 ;
#if 0
return pci_register_driver(&ck804xrom_driver);
#endif
}
static void T_4 F_30 ( void )
{
F_27 ( V_1 . V_7 ) ;
}
