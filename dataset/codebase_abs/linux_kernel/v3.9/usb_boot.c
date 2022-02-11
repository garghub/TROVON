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
F_6 ( & V_5 -> V_10 , L_1 ,
V_8 ) ;
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
F_6 ( & V_5 -> V_10 ,
L_2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_11 * V_12 ,
T_2 V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_16 V_17 ;
int V_8 = 0 ;
T_1 V_18 ;
V_18 = F_10 ( V_14 , V_19 ) ;
V_17 . V_15 = F_11 ( V_15 ) ;
V_17 . V_20 = F_11 ( V_18 ) ;
V_8 = F_3 ( V_5 , & V_17 , sizeof( V_17 ) ) ;
if ( V_8 < 0 )
return V_8 ;
while ( V_14 > 0 ) {
if ( V_14 > V_19 )
V_18 = V_19 ;
else
V_18 = V_14 ;
memcpy ( V_21 , V_12 -> V_6 + V_13 , V_18 ) ;
V_8 = F_3 ( V_5 , V_21 , V_18 ) ;
if ( V_8 < 0 )
return V_8 ;
V_14 -= V_18 ;
V_13 += V_18 ;
}
return V_8 ;
}
int F_12 ( struct V_4 * V_5 , T_3 V_22 )
{
int V_3 , V_8 = 0 ;
struct V_23 V_24 ;
struct V_25 V_25 ;
T_2 V_13 = 0 ;
char * V_26 = V_27 V_28 ;
const struct V_11 * V_12 ;
V_8 = F_13 ( & V_12 , V_26 , & V_5 -> V_10 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_5 -> V_10 ,
L_3 ,
V_26 , V_8 ) ;
return V_8 ;
}
V_21 = F_14 ( V_19 , V_29 ) ;
if ( V_21 == NULL )
return - V_30 ;
if ( V_12 -> V_18 < sizeof( V_24 ) ) {
F_6 ( & V_5 -> V_10 , L_4 ) ;
V_8 = - V_31 ;
goto V_32;
}
memcpy ( & V_24 , V_12 -> V_6 , sizeof( V_24 ) ) ;
F_1 ( ( T_1 * ) & V_24 , 19 ) ;
#if 0
if (hdr.magic_code != 0x10767fff) {
dev_err(&usbdev->dev, "Invalid magic code 0x%08x\n",
hdr.magic_code);
ret = -EINVAL;
goto out;
}
#endif
if ( V_24 . V_33 > V_34 ) {
F_6 ( & V_5 -> V_10 , L_5 , V_24 . V_33 ) ;
V_8 = - V_35 ;
goto V_32;
}
for ( V_3 = 0 ; V_3 < V_24 . V_33 ; V_3 ++ ) {
if ( V_24 . V_36 [ V_3 ] > V_24 . V_7 ) {
F_6 ( & V_5 -> V_10 ,
L_6 ,
V_3 , V_24 . V_36 [ V_3 ] , V_24 . V_7 ) ;
V_8 = - V_35 ;
goto V_32;
}
V_13 = V_24 . V_36 [ V_3 ] ;
if ( V_12 -> V_18 < sizeof( V_25 ) + V_13 ) {
F_6 ( & V_5 -> V_10 , L_7 ) ;
V_8 = - V_31 ;
goto V_32;
}
memcpy ( & V_25 , V_12 -> V_6 + V_13 , sizeof( V_25 ) ) ;
F_1 ( ( T_1 * ) & V_25 , 8 ) ;
#if 0
if ((fw_info.id & 0xfffff000) != 0x10767000) {
dev_err(&usbdev->dev, "Invalid FW id. 0x%08x\n",
fw_info.id);
ret = -EIO;
goto out;
}
#endif
if ( ( V_25 . V_37 & 0xffff ) != V_22 )
continue;
V_13 = V_24 . V_36 [ V_3 ] + V_25 . V_38 ;
if ( V_12 -> V_18 < V_25 . V_39 + V_13 ) {
F_6 ( & V_5 -> V_10 , L_8 ) ;
goto V_32;
}
V_8 = F_9 ( V_5 , V_12 , V_13 ,
V_25 . V_39 , V_40 ) ;
if ( V_8 < 0 )
goto V_32;
F_15 ( & V_5 -> V_10 , L_9 ) ;
V_13 = V_24 . V_36 [ V_3 ] + V_25 . V_41 ;
if ( V_12 -> V_18 < V_25 . V_42 + V_13 ) {
F_6 ( & V_5 -> V_10 , L_10 ) ;
goto V_32;
}
V_8 = F_9 ( V_5 , V_12 , V_13 , V_25 . V_42 ,
V_43 ) ;
if ( V_8 < 0 )
goto V_32;
F_15 ( & V_5 -> V_10 , L_11 ) ;
break;
}
if ( V_3 == V_24 . V_33 ) {
F_6 ( & V_5 -> V_10 , L_12 ,
V_22 ) ;
V_8 = - V_35 ;
}
V_32:
F_16 ( V_12 ) ;
F_17 ( V_21 ) ;
return V_8 ;
}
static int F_18 ( struct V_4 * V_5 , int V_44 )
{
int V_45 ;
int V_8 = - 1 ;
if ( V_44 ) {
V_8 = F_3 ( V_5 , NULL , 0 ) ;
if ( V_8 < 0 )
goto V_32;
}
V_8 = F_7 ( V_5 , & V_45 , sizeof( V_45 ) ) ;
if ( V_8 < 0 )
goto V_32;
V_32:
return V_8 ;
}
static int F_19 ( struct V_4 * V_5 , const char * V_26 ,
char * V_46 )
{
char * V_47 = NULL ;
T_2 V_13 = 0 ;
int V_8 = 0 ;
int V_7 ;
int V_14 ;
const struct V_11 * V_12 ;
#if F_20 ( V_48 )
const int V_49 = V_48 ;
#else
const int V_49 = 0 ;
#endif
V_8 = F_13 ( & V_12 , V_26 , & V_5 -> V_10 ) ;
if ( V_8 < 0 ) {
F_6 ( & V_5 -> V_10 ,
L_3 ,
V_26 , V_8 ) ;
return V_8 ;
}
V_47 = F_14 ( V_50 + V_49 , V_29 ) ;
if ( V_47 == NULL )
return - V_30 ;
strcpy ( V_47 + V_49 , V_46 ) ;
V_8 = F_3 ( V_5 , V_47 , strlen ( V_46 ) + V_49 ) ;
if ( V_8 < 0 )
goto V_32;
V_14 = V_12 -> V_18 ;
if ( V_14 <= 0 ) {
V_8 = - 1 ;
goto V_32;
}
while ( V_14 > 0 ) {
if ( V_14 > V_50 )
V_7 = V_50 ;
else
V_7 = V_14 ;
memcpy ( V_47 + V_49 , V_12 -> V_6 + V_13 , V_7 ) ;
V_8 = F_3 ( V_5 , V_47 , V_7 + V_49 ) ;
if ( V_8 < 0 )
goto V_32;
V_14 -= V_50 ;
V_13 += V_50 ;
V_8 = F_18 ( V_5 , ( ( V_7 + V_49 ) % 512 == 0 ) ) ;
if ( V_8 < 0 )
goto V_32;
}
V_8 = F_18 ( V_5 , 1 ) ;
if ( V_8 < 0 )
goto V_32;
V_32:
F_16 ( V_12 ) ;
F_17 ( V_47 ) ;
return V_8 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_8 ;
V_8 = F_3 ( V_5 , NULL , 0 ) ;
return V_8 ;
}
int F_22 ( struct V_4 * V_5 )
{
int V_8 ;
const char * V_51 = V_27 V_52 ;
const char * V_53 = V_27 V_54 ;
V_8 = F_19 ( V_5 , V_51 , V_55 ) ;
if ( V_8 < 0 )
return V_8 ;
F_6 ( & V_5 -> V_10 , L_13 ) ;
V_8 = F_19 ( V_5 , V_53 , V_56 ) ;
if ( V_8 < 0 )
return V_8 ;
F_15 ( & V_5 -> V_10 , L_14 ) ;
V_8 = F_21 ( V_5 ) ;
return V_8 ;
}
