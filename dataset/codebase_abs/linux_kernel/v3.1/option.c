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
V_7 -> V_12 -> V_13 . V_16 == V_27 ||
V_7 -> V_12 -> V_13 . V_16 == V_28 ) &&
( V_7 -> V_18 -> V_19 -> V_20 . V_29 == 1 ||
V_7 -> V_18 -> V_19 -> V_20 . V_29 == 2 ) )
return - V_22 ;
if ( V_7 -> V_12 -> V_13 . V_14 == V_30 &&
V_7 -> V_12 -> V_13 . V_16 == V_31 &&
V_7 -> V_18 -> V_19 -> V_20 . V_21 != V_32 )
return - V_22 ;
V_11 = V_7 -> V_33 = F_9 ( sizeof( struct V_10 ) , V_34 ) ;
if ( ! V_11 )
return - V_35 ;
V_11 -> V_36 = V_37 ;
F_10 ( & V_11 -> V_38 ) ;
V_11 -> V_33 = ( void * ) V_9 -> V_39 ;
return 0 ;
}
static enum V_40 F_11 ( const T_3 V_41 ,
const struct V_42 * V_43 )
{
const T_3 * V_44 ;
int V_45 ;
if ( V_43 ) {
V_44 = V_43 -> V_46 ;
for ( V_45 = 0 ; V_45 < V_43 -> V_47 ; V_45 ++ ) {
if ( V_44 [ V_45 ] == V_41 )
return V_43 -> V_48 ;
}
}
return V_49 ;
}
static void F_12 ( struct V_50 * V_50 )
{
int V_51 ;
int V_52 = V_50 -> V_52 ;
struct V_53 * V_54 = V_50 -> V_55 ;
struct V_56 * V_57 = F_13 ( V_54 ) ;
F_14 ( L_4 , V_58 ) ;
F_14 ( L_5 , V_58 , V_50 , V_54 , V_57 ) ;
if ( V_52 == 0 ) {
struct V_59 * V_60 =
(struct V_59 * ) V_50 -> V_61 ;
if ( ! V_60 ) {
F_14 ( L_6 , V_58 ) ;
return;
}
if ( ( V_60 -> V_62 == 0xA1 ) &&
( V_60 -> V_63 == 0x20 ) ) {
int V_64 ;
unsigned char V_65 = * ( ( unsigned char * )
V_50 -> V_61 +
sizeof( struct V_59 ) ) ;
F_14 ( L_7 , V_58 , V_65 ) ;
V_64 = V_57 -> V_66 ;
V_57 -> V_67 = 1 ;
V_57 -> V_66 = ( ( V_65 & 0x01 ) ? 1 : 0 ) ;
V_57 -> V_68 = ( ( V_65 & 0x02 ) ? 1 : 0 ) ;
V_57 -> V_69 = ( ( V_65 & 0x08 ) ? 1 : 0 ) ;
if ( V_64 && ! V_57 -> V_66 ) {
struct V_70 * V_71 =
F_15 ( & V_54 -> V_54 ) ;
if ( V_71 && ! F_16 ( V_71 ) )
F_17 ( V_71 ) ;
F_18 ( V_71 ) ;
}
} else {
F_14 ( L_8 , V_58 ,
V_60 -> V_62 , V_60 -> V_63 ) ;
}
} else
V_51 ( L_9 , V_58 , V_52 ) ;
if ( V_52 != - V_72 && V_52 != - V_73 ) {
V_51 = F_19 ( V_50 , V_74 ) ;
if ( V_51 )
F_14 ( L_10 ,
V_58 , V_51 ) ;
}
}
static int V_37 ( struct V_53 * V_54 )
{
struct V_6 * V_7 = V_54 -> V_7 ;
struct V_10 * V_75 =
(struct V_10 * ) V_7 -> V_33 ;
struct V_56 * V_57 ;
int V_76 = V_7 -> V_18 -> V_19 -> V_20 . V_29 ;
int V_77 = 0 ;
F_14 ( L_4 , V_58 ) ;
if ( F_11 ( V_76 ,
(struct V_42 * ) V_75 -> V_33 )
== V_78 ) {
F_14 ( L_11 , V_76 ) ;
return - V_79 ;
}
V_57 = F_13 ( V_54 ) ;
if ( V_57 -> V_80 )
V_77 |= 0x01 ;
if ( V_57 -> V_81 )
V_77 |= 0x02 ;
return F_20 ( V_7 -> V_12 ,
F_21 ( V_7 -> V_12 , 0 ) ,
0x22 , 0x21 , V_77 , V_76 , NULL , 0 , V_82 ) ;
}
