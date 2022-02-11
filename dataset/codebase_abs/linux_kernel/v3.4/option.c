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
if ( V_13 -> V_18 -> V_19 . V_20 == V_21 &&
V_13 -> V_18 -> V_19 . V_22 == V_23 &&
V_13 -> V_24 -> V_25 -> V_26 . V_27 == 0x8 )
return - V_28 ;
if ( ( V_13 -> V_18 -> V_19 . V_20 == V_29 ||
V_13 -> V_18 -> V_19 . V_20 == V_30 ) &&
V_13 -> V_24 -> V_25 -> V_26 . V_27 != 0xff )
return - V_28 ;
if ( F_1 (
V_13 -> V_24 -> V_25 -> V_26 . V_31 ,
V_10 ,
( const struct V_4 * ) V_15 -> V_32 ) )
return - V_28 ;
if ( V_13 -> V_18 -> V_19 . V_20 == V_33 &&
V_13 -> V_18 -> V_19 . V_22 == V_34 &&
V_13 -> V_24 -> V_25 -> V_26 . V_27 != V_35 )
return - V_28 ;
V_17 = V_13 -> V_36 = F_5 ( sizeof( struct V_16 ) , V_37 ) ;
if ( ! V_17 )
return - V_38 ;
V_17 -> V_39 = V_40 ;
F_6 ( & V_17 -> V_41 ) ;
V_17 -> V_36 = ( void * ) V_15 -> V_32 ;
return 0 ;
}
static void F_7 ( struct V_42 * V_42 )
{
int V_43 ;
int V_44 = V_42 -> V_44 ;
struct V_45 * V_46 = V_42 -> V_47 ;
struct V_48 * V_49 = F_8 ( V_46 ) ;
F_9 ( L_1 , V_50 ) ;
F_9 ( L_2 , V_50 , V_42 , V_46 , V_49 ) ;
if ( V_44 == 0 ) {
struct V_51 * V_52 =
(struct V_51 * ) V_42 -> V_53 ;
if ( ! V_52 ) {
F_9 ( L_3 , V_50 ) ;
return;
}
if ( ( V_52 -> V_54 == 0xA1 ) &&
( V_52 -> V_55 == 0x20 ) ) {
int V_56 ;
unsigned char V_57 = * ( ( unsigned char * )
V_42 -> V_53 +
sizeof( struct V_51 ) ) ;
F_9 ( L_4 , V_50 , V_57 ) ;
V_56 = V_49 -> V_58 ;
V_49 -> V_59 = 1 ;
V_49 -> V_58 = ( ( V_57 & 0x01 ) ? 1 : 0 ) ;
V_49 -> V_60 = ( ( V_57 & 0x02 ) ? 1 : 0 ) ;
V_49 -> V_61 = ( ( V_57 & 0x08 ) ? 1 : 0 ) ;
if ( V_56 && ! V_49 -> V_58 ) {
struct V_62 * V_63 =
F_10 ( & V_46 -> V_46 ) ;
if ( V_63 && ! F_11 ( V_63 ) )
F_12 ( V_63 ) ;
F_13 ( V_63 ) ;
}
} else {
F_9 ( L_5 , V_50 ,
V_52 -> V_54 , V_52 -> V_55 ) ;
}
} else
V_43 ( L_6 , V_50 , V_44 ) ;
if ( V_44 != - V_64 && V_44 != - V_65 ) {
V_43 = F_14 ( V_42 , V_66 ) ;
if ( V_43 )
F_9 ( L_7 ,
V_50 , V_43 ) ;
}
}
static int V_40 ( struct V_45 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_16 * V_67 =
(struct V_16 * ) V_13 -> V_36 ;
struct V_48 * V_49 ;
int V_68 = V_13 -> V_24 -> V_25 -> V_26 . V_31 ;
int V_69 = 0 ;
F_9 ( L_1 , V_50 ) ;
if ( F_1 ( V_68 , V_8 ,
(struct V_4 * ) V_67 -> V_36 ) ) {
F_9 ( L_8 , V_68 ) ;
return - V_70 ;
}
V_49 = F_8 ( V_46 ) ;
if ( V_49 -> V_71 )
V_69 |= 0x01 ;
if ( V_49 -> V_72 )
V_69 |= 0x02 ;
return F_15 ( V_13 -> V_18 ,
F_16 ( V_13 -> V_18 , 0 ) ,
0x22 , 0x21 , V_69 , V_68 , NULL , 0 , V_73 ) ;
}
