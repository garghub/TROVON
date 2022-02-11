static void F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ , V_1 ++ )
* V_1 = F_2 ( * V_1 ) ;
}
static int F_3 ( struct V_4 * V_5 , void * V_6 , int V_7 )
{
int V_8 ;
int V_9 ;
V_8 = F_4 ( V_5 , F_5 ( V_5 , 1 ) , V_6 , V_7 ,
& V_9 , 1000 ) ;
if ( V_8 < 0 ) {
F_6 ( V_10 L_1 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , void * V_6 , int V_7 )
{
int V_8 ;
int V_9 ;
V_8 = F_4 ( V_5 , F_8 ( V_5 , 2 ) , V_6 , V_7 ,
& V_9 , 5000 ) ;
if ( V_8 < 0 ) {
F_6 ( V_10 L_2 ,
V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , struct V_11 * V_12 ,
T_2 * V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_16 V_17 ;
int V_8 = 0 ;
T_1 V_18 ;
int V_7 , V_19 ;
V_18 = ( V_14 + V_20 - 1 ) & ~ ( V_20 - 1 ) ;
V_17 . V_15 = F_10 ( V_15 ) ;
V_17 . V_21 = F_10 ( V_18 ) ;
V_8 = F_3 ( V_5 , & V_17 , sizeof( V_17 ) ) ;
if ( V_8 < 0 )
goto V_22;
V_19 = 0 ;
while ( ( V_7 = V_12 -> V_23 -> V_24 ( V_12 , V_25 , V_20 , V_13 ) ) ) {
if ( V_7 < 0 ) {
V_8 = - 1 ;
goto V_22;
}
V_19 += V_7 ;
V_8 = F_3 ( V_5 , V_25 , V_20 ) ;
if ( V_8 < 0 )
goto V_22;
if ( V_19 >= V_14 )
break;
}
if ( V_19 < V_14 ) {
F_6 ( V_10 L_3
L_4 , V_19 , V_14 ) ;
V_8 = - V_26 ;
}
V_22:
return V_8 ;
}
int F_11 ( struct V_4 * V_5 , T_3 V_27 )
{
int V_3 , V_8 = 0 ;
struct V_11 * V_12 = NULL ;
struct V_28 * V_28 = NULL ;
static T_4 V_29 ;
struct V_30 V_31 ;
struct V_32 V_32 ;
T_2 V_13 = 0 ;
char * V_33 = V_34 ;
int V_7 ;
V_25 = F_12 ( V_20 , V_35 ) ;
if ( V_25 == NULL ) {
F_6 ( V_10 L_5 ) ;
return - V_36 ;
}
V_29 = F_13 () ;
F_14 ( F_15 () ) ;
V_12 = F_16 ( V_33 , V_37 | V_38 , 0 ) ;
if ( F_17 ( V_12 ) ) {
F_6 ( V_10 L_6 , V_33 ) ;
F_14 ( V_29 ) ;
V_8 = - V_39 ;
goto V_40;
}
if ( V_12 -> V_41 )
V_28 = V_12 -> V_41 -> V_42 ;
if ( ! V_28 || ! F_18 ( V_28 -> V_43 ) ) {
F_6 ( V_10 L_7 , V_33 ) ;
V_8 = - V_44 ;
goto V_22;
}
V_7 = V_12 -> V_23 -> V_24 ( V_12 , ( V_45 * ) & V_31 , sizeof( V_31 ) , & V_13 ) ;
if ( V_7 != sizeof( V_31 ) ) {
F_6 ( V_10 L_8 ) ;
V_8 = - V_26 ;
goto V_22;
}
F_1 ( ( T_1 * ) & V_31 , 19 ) ;
#if 0
if (hdr.magic_code != 0x10767fff) {
printk(KERN_ERR "gdmwm: Invalid magic code 0x%08x\n",
hdr.magic_code);
ret = -EINVAL;
goto out;
}
#endif
if ( V_31 . V_46 > V_47 ) {
F_6 ( V_10 L_9 , V_31 . V_46 ) ;
V_8 = - V_44 ;
goto V_22;
}
for ( V_3 = 0 ; V_3 < V_31 . V_46 ; V_3 ++ ) {
if ( V_31 . V_48 [ V_3 ] > V_31 . V_7 ) {
F_6 ( V_10 L_10
L_11
L_12 ,
V_3 , V_31 . V_48 [ V_3 ] , V_31 . V_7 ) ;
V_8 = - V_44 ;
goto V_22;
}
V_13 = V_31 . V_48 [ V_3 ] ;
V_7 = V_12 -> V_23 -> V_24 ( V_12 , ( V_45 * ) & V_32 , sizeof( V_32 ) ,
& V_13 ) ;
if ( V_7 != sizeof( V_32 ) ) {
F_6 ( V_10 L_13 ) ;
V_8 = - V_26 ;
goto V_22;
}
F_1 ( ( T_1 * ) & V_32 , 8 ) ;
#if 0
if ((fw_info.id & 0xfffff000) != 0x10767000) {
printk(KERN_ERR "gdmwm: Invalid FW id. 0x%08x\n",
fw_info.id);
ret = -EIO;
goto out;
}
#endif
if ( ( V_32 . V_49 & 0xffff ) != V_27 )
continue;
V_13 = V_31 . V_48 [ V_3 ] + V_32 . V_50 ;
V_8 = F_9 ( V_5 , V_12 , & V_13 , V_32 . V_51 ,
V_52 ) ;
if ( V_8 < 0 )
goto V_22;
F_6 ( V_53 L_14 ) ;
V_13 = V_31 . V_48 [ V_3 ] + V_32 . V_54 ;
V_8 = F_9 ( V_5 , V_12 , & V_13 , V_32 . V_55 ,
V_56 ) ;
if ( V_8 < 0 )
goto V_22;
F_6 ( V_53 L_15 ) ;
break;
}
if ( V_3 == V_31 . V_46 ) {
F_6 ( V_10 L_16 , V_27 ) ;
V_8 = - V_44 ;
}
V_22:
F_19 ( V_12 , V_57 -> V_58 ) ;
V_40:
F_14 ( V_29 ) ;
F_20 ( V_25 ) ;
return V_8 ;
}
static int F_21 ( struct V_4 * V_5 , int V_59 )
{
int V_60 ;
int V_8 = - 1 ;
if ( V_59 ) {
V_8 = F_3 ( V_5 , NULL , 0 ) ;
if ( V_8 < 0 )
goto V_22;
}
V_8 = F_7 ( V_5 , & V_60 , sizeof( V_60 ) ) ;
if ( V_8 < 0 )
goto V_22;
V_22:
return V_8 ;
}
static int F_22 ( struct V_4 * V_5 , char * V_61 ,
char * V_62 )
{
struct V_11 * V_12 ;
struct V_28 * V_28 ;
static T_4 V_29 ;
char * V_63 = NULL ;
T_2 V_13 = 0 ;
int V_8 = 0 ;
int V_7 , V_19 = 0 ;
#if F_23 ( V_64 )
const int V_65 = V_64 ;
#else
const int V_65 = 0 ;
#endif
V_29 = F_13 () ;
F_14 ( F_15 () ) ;
V_12 = F_16 ( V_61 , V_37 | V_38 , 0 ) ;
if ( F_17 ( V_12 ) ) {
F_6 ( V_10 L_6 , V_61 ) ;
F_14 ( V_29 ) ;
V_8 = - V_39 ;
goto V_40;
}
if ( V_12 -> V_41 ) {
V_28 = V_12 -> V_41 -> V_42 ;
if ( ! V_28 || ! F_18 ( V_28 -> V_43 ) ) {
F_6 ( V_10 L_7 , V_61 ) ;
V_8 = - V_44 ;
goto V_22;
}
}
V_63 = F_12 ( V_66 + V_65 , V_35 ) ;
if ( V_63 == NULL ) {
F_6 ( V_10 L_5 ) ;
return - V_36 ;
}
strcpy ( V_63 + V_65 , V_62 ) ;
V_8 = F_3 ( V_5 , V_63 , strlen ( V_62 ) + V_65 ) ;
if ( V_8 < 0 )
goto V_22;
while ( ( V_7 = V_12 -> V_23 -> V_24 ( V_12 , V_63 + V_65 , V_66 ,
& V_13 ) ) ) {
if ( V_7 < 0 ) {
V_8 = - 1 ;
goto V_22;
}
V_19 += V_7 ;
V_8 = F_3 ( V_5 , V_63 , V_7 + V_65 ) ;
if ( V_8 < 0 )
goto V_22;
V_8 = F_21 ( V_5 , ( ( V_7 + V_65 ) % 512 == 0 ) ) ;
if ( V_8 < 0 )
goto V_22;
}
V_8 = F_21 ( V_5 , 1 ) ;
if ( V_8 < 0 )
goto V_22;
V_22:
F_19 ( V_12 , V_57 -> V_58 ) ;
V_40:
F_14 ( V_29 ) ;
F_20 ( V_63 ) ;
return V_8 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_3 ( V_5 , NULL , 0 ) ;
return V_8 ;
}
int F_25 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_22 ( V_5 , V_67 , V_68 ) ;
if ( V_8 < 0 )
goto V_22;
F_6 ( V_53 L_17 ) ;
V_8 = F_22 ( V_5 , V_69 , V_70 ) ;
if ( V_8 < 0 )
goto V_22;
F_6 ( V_53 L_18 ) ;
V_8 = F_24 ( V_5 ) ;
V_22:
return V_8 ;
}
