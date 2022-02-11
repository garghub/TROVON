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
static void F_7 ( struct V_12 * V_13 )
{
struct V_16 * V_42 = F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
F_10 ( V_42 ) ;
}
static void F_11 ( struct V_43 * V_43 )
{
int V_44 ;
int V_45 = V_43 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_48 ;
struct V_49 * V_50 =
F_12 ( V_47 ) ;
F_13 ( L_1 , V_51 , V_43 , V_47 , V_50 ) ;
if ( V_45 == 0 ) {
struct V_52 * V_53 =
(struct V_52 * ) V_43 -> V_54 ;
if ( ! V_53 ) {
F_13 ( L_2 , V_51 ) ;
return;
}
if ( ( V_53 -> V_55 == 0xA1 ) &&
( V_53 -> V_56 == 0x20 ) ) {
int V_57 ;
unsigned char V_58 = * ( ( unsigned char * )
V_43 -> V_54 +
sizeof( struct V_52 ) ) ;
F_13 ( L_3 , V_51 , V_58 ) ;
V_57 = V_50 -> V_59 ;
V_50 -> V_60 = 1 ;
V_50 -> V_59 = ( ( V_58 & 0x01 ) ? 1 : 0 ) ;
V_50 -> V_61 = ( ( V_58 & 0x02 ) ? 1 : 0 ) ;
V_50 -> V_62 = ( ( V_58 & 0x08 ) ? 1 : 0 ) ;
if ( V_57 && ! V_50 -> V_59 ) {
struct V_63 * V_64 =
F_14 ( & V_47 -> V_47 ) ;
if ( V_64 && ! F_15 ( V_64 ) )
F_16 ( V_64 ) ;
F_17 ( V_64 ) ;
}
} else {
F_13 ( L_4 , V_51 ,
V_53 -> V_55 , V_53 -> V_56 ) ;
}
} else
F_18 ( & V_47 -> V_18 , L_5 , V_51 , V_45 ) ;
if ( V_45 != - V_65 && V_45 != - V_66 ) {
V_44 = F_19 ( V_43 , V_67 ) ;
if ( V_44 )
F_13 ( L_6 ,
V_51 , V_44 ) ;
}
}
static int V_40 ( struct V_46 * V_47 )
{
struct V_12 * V_13 = V_47 -> V_13 ;
struct V_16 * V_68 =
(struct V_16 * ) V_13 -> V_36 ;
struct V_49 * V_50 ;
int V_69 = V_13 -> V_24 -> V_25 -> V_26 . V_31 ;
int V_70 = 0 ;
if ( F_1 ( V_69 , V_8 ,
(struct V_4 * ) V_68 -> V_36 ) ) {
F_13 ( L_7 , V_69 ) ;
return - V_71 ;
}
V_50 = F_12 ( V_47 ) ;
if ( V_50 -> V_72 )
V_70 |= 0x01 ;
if ( V_50 -> V_73 )
V_70 |= 0x02 ;
return F_20 ( V_13 -> V_18 ,
F_21 ( V_13 -> V_18 , 0 ) ,
0x22 , 0x21 , V_70 , V_69 , NULL , 0 , V_74 ) ;
}
