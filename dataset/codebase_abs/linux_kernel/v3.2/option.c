static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 )
goto V_3;
V_1 = F_3 ( & V_4 ) ;
if ( V_1 )
goto V_5;
F_4 (KERN_INFO KBUILD_MODNAME L_1 DRIVER_VERSION L_2
DRIVER_DESC L_3 ) ;
return 0 ;
V_5:
F_5 ( & V_2 ) ;
V_3:
return V_1 ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_4 ) ;
F_5 ( & V_2 ) ;
}
static bool F_8 ( const T_3 V_6 , enum V_7 V_8 ,
const struct V_9 * V_10 )
{
unsigned long V_11 ;
const unsigned long * V_12 ;
if ( V_10 ) {
if ( V_8 == V_13 )
V_12 = & V_10 -> V_14 ;
else if ( V_8 == V_15 )
V_12 = & V_10 -> V_16 ;
else {
F_9 ( V_8 ) ;
return false ;
}
F_10 (num, intf_list, MAX_BL_NUM + 1 ) {
if ( V_11 == V_6 )
return true ;
}
}
return false ;
}
static int F_11 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_21 * V_22 ;
if ( V_18 -> V_23 -> V_24 . V_25 == V_26 &&
V_18 -> V_23 -> V_24 . V_27 == V_28 &&
V_18 -> V_29 -> V_30 -> V_31 . V_32 == 0x8 )
return - V_33 ;
if ( ( V_18 -> V_23 -> V_24 . V_25 == V_34 ||
V_18 -> V_23 -> V_24 . V_25 == V_35 ) &&
V_18 -> V_29 -> V_30 -> V_31 . V_32 != 0xff )
return - V_33 ;
if ( F_8 (
V_18 -> V_29 -> V_30 -> V_31 . V_36 ,
V_15 ,
( const struct V_9 * ) V_20 -> V_37 ) )
if ( V_18 -> V_23 -> V_24 . V_25 == V_38 &&
V_18 -> V_23 -> V_24 . V_27 == V_39 &&
V_18 -> V_29 -> V_30 -> V_31 . V_32 != V_40 )
return - V_33 ;
V_22 = V_18 -> V_41 = F_12 ( sizeof( struct V_21 ) , V_42 ) ;
if ( ! V_22 )
return - V_43 ;
V_22 -> V_44 = V_45 ;
F_13 ( & V_22 -> V_46 ) ;
V_22 -> V_41 = ( void * ) V_20 -> V_37 ;
return 0 ;
}
static void F_14 ( struct V_47 * V_47 )
{
int V_48 ;
int V_49 = V_47 -> V_49 ;
struct V_50 * V_51 = V_47 -> V_52 ;
struct V_53 * V_54 = F_15 ( V_51 ) ;
F_16 ( L_4 , V_55 ) ;
F_16 ( L_5 , V_55 , V_47 , V_51 , V_54 ) ;
if ( V_49 == 0 ) {
struct V_56 * V_57 =
(struct V_56 * ) V_47 -> V_58 ;
if ( ! V_57 ) {
F_16 ( L_6 , V_55 ) ;
return;
}
if ( ( V_57 -> V_59 == 0xA1 ) &&
( V_57 -> V_60 == 0x20 ) ) {
int V_61 ;
unsigned char V_62 = * ( ( unsigned char * )
V_47 -> V_58 +
sizeof( struct V_56 ) ) ;
F_16 ( L_7 , V_55 , V_62 ) ;
V_61 = V_54 -> V_63 ;
V_54 -> V_64 = 1 ;
V_54 -> V_63 = ( ( V_62 & 0x01 ) ? 1 : 0 ) ;
V_54 -> V_65 = ( ( V_62 & 0x02 ) ? 1 : 0 ) ;
V_54 -> V_66 = ( ( V_62 & 0x08 ) ? 1 : 0 ) ;
if ( V_61 && ! V_54 -> V_63 ) {
struct V_67 * V_68 =
F_17 ( & V_51 -> V_51 ) ;
if ( V_68 && ! F_18 ( V_68 ) )
F_19 ( V_68 ) ;
F_20 ( V_68 ) ;
}
} else {
F_16 ( L_8 , V_55 ,
V_57 -> V_59 , V_57 -> V_60 ) ;
}
} else
V_48 ( L_9 , V_55 , V_49 ) ;
if ( V_49 != - V_69 && V_49 != - V_70 ) {
V_48 = F_21 ( V_47 , V_71 ) ;
if ( V_48 )
F_16 ( L_10 ,
V_55 , V_48 ) ;
}
}
static int V_45 ( struct V_50 * V_51 )
{
struct V_17 * V_18 = V_51 -> V_18 ;
struct V_21 * V_72 =
(struct V_21 * ) V_18 -> V_41 ;
struct V_53 * V_54 ;
int V_73 = V_18 -> V_29 -> V_30 -> V_31 . V_36 ;
int V_74 = 0 ;
F_16 ( L_4 , V_55 ) ;
if ( F_8 ( V_73 , V_13 ,
(struct V_9 * ) V_72 -> V_41 ) ) {
F_16 ( L_11 , V_73 ) ;
return - V_75 ;
}
V_54 = F_15 ( V_51 ) ;
if ( V_54 -> V_76 )
V_74 |= 0x01 ;
if ( V_54 -> V_77 )
V_74 |= 0x02 ;
return F_22 ( V_18 -> V_23 ,
F_23 ( V_18 -> V_23 , 0 ) ,
0x22 , 0x21 , V_74 , V_73 , NULL , 0 , V_78 ) ;
}
