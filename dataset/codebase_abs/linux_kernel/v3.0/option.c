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
static int F_8 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 ;
if ( V_7 -> V_12 -> V_13 . V_14 == V_15 &&
V_7 -> V_12 -> V_13 . V_16 == V_17 &&
V_7 -> V_18 -> V_19 -> V_20 . V_21 == 0x8 )
return - V_22 ;
if ( ( V_7 -> V_12 -> V_13 . V_14 == V_23 ||
V_7 -> V_12 -> V_13 . V_14 == V_24 ) &&
V_7 -> V_18 -> V_19 -> V_20 . V_21 != 0xff )
return - V_22 ;
if ( V_7 -> V_12 -> V_13 . V_14 == V_25 &&
( V_7 -> V_12 -> V_13 . V_16 == V_26 ||
V_7 -> V_12 -> V_13 . V_16 == V_27 ) &&
V_7 -> V_18 -> V_19 -> V_20 . V_28 == 1 )
return - V_22 ;
if ( V_7 -> V_12 -> V_13 . V_14 == V_29 &&
V_7 -> V_12 -> V_13 . V_16 == V_30 &&
V_7 -> V_18 -> V_19 -> V_20 . V_21 != V_31 )
return - V_22 ;
V_11 = V_7 -> V_32 = F_9 ( sizeof( struct V_10 ) , V_33 ) ;
if ( ! V_11 )
return - V_34 ;
V_11 -> V_35 = V_36 ;
F_10 ( & V_11 -> V_37 ) ;
V_11 -> V_32 = ( void * ) V_9 -> V_38 ;
return 0 ;
}
static enum V_39 F_11 ( const T_3 V_40 ,
const struct V_41 * V_42 )
{
const T_3 * V_43 ;
int V_44 ;
if ( V_42 ) {
V_43 = V_42 -> V_45 ;
for ( V_44 = 0 ; V_44 < V_42 -> V_46 ; V_44 ++ ) {
if ( V_43 [ V_44 ] == V_40 )
return V_42 -> V_47 ;
}
}
return V_48 ;
}
static void F_12 ( struct V_49 * V_49 )
{
int V_50 ;
int V_51 = V_49 -> V_51 ;
struct V_52 * V_53 = V_49 -> V_54 ;
struct V_55 * V_56 = F_13 ( V_53 ) ;
F_14 ( L_4 , V_57 ) ;
F_14 ( L_5 , V_57 , V_49 , V_53 , V_56 ) ;
if ( V_51 == 0 ) {
struct V_58 * V_59 =
(struct V_58 * ) V_49 -> V_60 ;
if ( ! V_59 ) {
F_14 ( L_6 , V_57 ) ;
return;
}
if ( ( V_59 -> V_61 == 0xA1 ) &&
( V_59 -> V_62 == 0x20 ) ) {
int V_63 ;
unsigned char V_64 = * ( ( unsigned char * )
V_49 -> V_60 +
sizeof( struct V_58 ) ) ;
F_14 ( L_7 , V_57 , V_64 ) ;
V_63 = V_56 -> V_65 ;
V_56 -> V_66 = 1 ;
V_56 -> V_65 = ( ( V_64 & 0x01 ) ? 1 : 0 ) ;
V_56 -> V_67 = ( ( V_64 & 0x02 ) ? 1 : 0 ) ;
V_56 -> V_68 = ( ( V_64 & 0x08 ) ? 1 : 0 ) ;
if ( V_63 && ! V_56 -> V_65 ) {
struct V_69 * V_70 =
F_15 ( & V_53 -> V_53 ) ;
if ( V_70 && ! F_16 ( V_70 ) )
F_17 ( V_70 ) ;
F_18 ( V_70 ) ;
}
} else {
F_14 ( L_8 , V_57 ,
V_59 -> V_61 , V_59 -> V_62 ) ;
}
} else
V_50 ( L_9 , V_57 , V_51 ) ;
if ( V_51 != - V_71 && V_51 != - V_72 ) {
V_50 = F_19 ( V_49 , V_73 ) ;
if ( V_50 )
F_14 ( L_10 ,
V_57 , V_50 ) ;
}
}
static int V_36 ( struct V_52 * V_53 )
{
struct V_6 * V_7 = V_53 -> V_7 ;
struct V_10 * V_74 =
(struct V_10 * ) V_7 -> V_32 ;
struct V_55 * V_56 ;
int V_75 = V_7 -> V_18 -> V_19 -> V_20 . V_28 ;
int V_76 = 0 ;
F_14 ( L_4 , V_57 ) ;
if ( F_11 ( V_75 ,
(struct V_41 * ) V_74 -> V_32 )
== V_77 ) {
F_14 ( L_11 , V_75 ) ;
return - V_78 ;
}
V_56 = F_13 ( V_53 ) ;
if ( V_56 -> V_79 )
V_76 |= 0x01 ;
if ( V_56 -> V_80 )
V_76 |= 0x02 ;
return F_20 ( V_7 -> V_12 ,
F_21 ( V_7 -> V_12 , 0 ) ,
0x22 , 0x21 , V_76 , V_75 , NULL , 0 , V_81 ) ;
}
