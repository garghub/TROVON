static bool F_1 ( const T_1 V_1 , enum V_2 V_3 ,
const struct V_4 * V_5 )
{
unsigned long V_6 ;
const unsigned long * V_7 ;
if ( V_5 ) {
if ( V_3 == V_8 )
V_7 = & V_5 -> V_9 ;
else if ( V_3 == V_10 )
V_7 = & V_5 -> V_11 ;
else {
F_2 ( V_3 ) ;
return false ;
}
F_3 (num, intf_list, MAX_BL_NUM + 1 ) {
if ( V_6 == V_1 )
return true ;
}
}
return false ;
}
static int F_4 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 =
& V_13 -> V_22 -> V_23 -> V_24 ;
struct V_25 * V_26 = & V_13 -> V_27 -> V_28 ;
if ( V_26 -> V_29 == V_30 &&
V_26 -> V_31 == V_32 &&
V_21 -> V_33 == 0x08 )
return - V_34 ;
if ( ( V_26 -> V_29 == V_35 ||
V_26 -> V_29 == V_36 ) &&
V_21 -> V_33 != 0xff )
return - V_34 ;
if ( F_1 (
V_21 -> V_37 ,
V_10 ,
( const struct V_4 * ) V_15 -> V_38 ) )
return - V_34 ;
if ( V_26 -> V_29 == V_39 &&
V_26 -> V_31 == V_40 &&
V_21 -> V_33 != V_41 )
return - V_34 ;
V_17 = F_5 ( sizeof( struct V_16 ) , V_42 ) ;
if ( ! V_17 )
return - V_43 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 ) {
F_6 ( V_17 ) ;
return - V_43 ;
}
V_19 -> V_37 = V_21 -> V_37 ;
V_17 -> V_44 = V_19 ;
if ( ! F_1 ( V_21 -> V_37 ,
V_8 ,
(struct V_4 * ) V_15 -> V_38 ) ) {
V_17 -> V_45 = V_46 ;
}
F_7 ( & V_17 -> V_47 ) ;
F_8 ( V_13 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_16 * V_48 = F_10 ( V_13 ) ;
struct V_18 * V_19 = V_48 -> V_44 ;
F_6 ( V_19 ) ;
F_6 ( V_48 ) ;
}
static void F_11 ( struct V_49 * V_49 )
{
int V_50 ;
int V_51 = V_49 -> V_51 ;
struct V_52 * V_53 = V_49 -> V_54 ;
struct V_55 * V_56 =
F_12 ( V_53 ) ;
F_13 ( L_1 , V_57 , V_49 , V_53 , V_56 ) ;
if ( V_51 == 0 ) {
struct V_58 * V_59 =
(struct V_58 * ) V_49 -> V_60 ;
if ( ! V_59 ) {
F_13 ( L_2 , V_57 ) ;
return;
}
if ( ( V_59 -> V_61 == 0xA1 ) &&
( V_59 -> V_62 == 0x20 ) ) {
int V_63 ;
unsigned char V_64 = * ( ( unsigned char * )
V_49 -> V_60 +
sizeof( struct V_58 ) ) ;
F_13 ( L_3 , V_57 , V_64 ) ;
V_63 = V_56 -> V_65 ;
V_56 -> V_66 = 1 ;
V_56 -> V_65 = ( ( V_64 & 0x01 ) ? 1 : 0 ) ;
V_56 -> V_67 = ( ( V_64 & 0x02 ) ? 1 : 0 ) ;
V_56 -> V_68 = ( ( V_64 & 0x08 ) ? 1 : 0 ) ;
if ( V_63 && ! V_56 -> V_65 ) {
struct V_69 * V_70 =
F_14 ( & V_53 -> V_53 ) ;
if ( V_70 && ! F_15 ( V_70 ) )
F_16 ( V_70 ) ;
F_17 ( V_70 ) ;
}
} else {
F_13 ( L_4 , V_57 ,
V_59 -> V_61 , V_59 -> V_62 ) ;
}
} else
F_18 ( & V_53 -> V_27 , L_5 , V_57 , V_51 ) ;
if ( V_51 != - V_71 && V_51 != - V_72 ) {
V_50 = F_19 ( V_49 , V_73 ) ;
if ( V_50 )
F_13 ( L_6 ,
V_57 , V_50 ) ;
}
}
static int V_46 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = V_53 -> V_13 ;
struct V_16 * V_48 = F_10 ( V_13 ) ;
struct V_18 * V_19 = V_48 -> V_44 ;
struct V_55 * V_56 ;
int V_74 = 0 ;
V_56 = F_12 ( V_53 ) ;
if ( V_56 -> V_75 )
V_74 |= 0x01 ;
if ( V_56 -> V_76 )
V_74 |= 0x02 ;
return F_20 ( V_13 -> V_27 , F_21 ( V_13 -> V_27 , 0 ) ,
0x22 , 0x21 , V_74 , V_19 -> V_37 , NULL ,
0 , V_77 ) ;
}
