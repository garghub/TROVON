static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , T_1 * V_6 )
{
int V_7 = 0 ;
const struct V_8 * V_9 = V_4 -> V_9 ;
* V_6 = 0 ;
switch ( V_9 -> V_10 ) {
case 1 :
if ( V_9 -> V_11 . V_12 . V_13 )
V_7 = V_9 -> V_11 . V_12 . V_13 ( V_2 , V_5 , ( V_14 * ) V_6 ,
V_4 -> V_15 ) ;
break;
case 2 :
if ( V_9 -> V_11 . V_16 . V_13 )
V_7 = V_9 -> V_11 . V_16 . V_13 ( V_2 , V_5 , ( V_17 * ) V_6 ,
V_4 -> V_15 ) ;
break;
case 4 :
if ( V_9 -> V_11 . V_18 . V_13 )
V_7 = V_9 -> V_11 . V_18 . V_13 ( V_2 , V_5 , V_6 , V_4 -> V_15 ) ;
break;
}
return V_7 ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
int V_7 = 0 ;
const struct V_8 * V_9 = V_4 -> V_9 ;
switch ( V_9 -> V_10 ) {
case 1 :
if ( V_9 -> V_11 . V_12 . V_19 )
V_7 = V_9 -> V_11 . V_12 . V_19 ( V_2 , V_5 , ( V_14 ) V_6 ,
V_4 -> V_15 ) ;
break;
case 2 :
if ( V_9 -> V_11 . V_16 . V_19 )
V_7 = V_9 -> V_11 . V_16 . V_19 ( V_2 , V_5 , ( V_17 ) V_6 ,
V_4 -> V_15 ) ;
break;
case 4 :
if ( V_9 -> V_11 . V_18 . V_19 )
V_7 = V_9 -> V_11 . V_18 . V_19 ( V_2 , V_5 , V_6 ,
V_4 -> V_15 ) ;
break;
}
return V_7 ;
}
static inline T_1 F_3 ( int V_10 )
{
if ( V_10 == 1 )
return 0xff ;
else if ( V_10 == 2 )
return 0xffff ;
else
return 0xffffffff ;
}
static inline int F_4 ( int V_5 , int V_10 )
{
if ( ( V_10 == 1 || V_10 == 2 || V_10 == 4 ) && ( V_5 % V_10 ) == 0 )
return 1 ;
return 0 ;
}
static inline T_1 F_5 ( T_1 V_20 , T_1 V_21 , T_1 V_22 ,
int V_5 )
{
if ( V_5 >= 0 ) {
V_22 <<= ( V_5 * 8 ) ;
V_21 <<= ( V_5 * 8 ) ;
} else {
V_22 >>= ( V_5 * - 8 ) ;
V_21 >>= ( V_5 * - 8 ) ;
}
V_20 = ( V_20 & ~ V_22 ) | ( V_21 & V_22 ) ;
return V_20 ;
}
static int F_6 ( int V_23 )
{
switch ( V_23 ) {
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
}
return V_23 ;
}
int F_7 ( struct V_1 * V_2 , int V_5 , int V_10 ,
T_1 * V_34 )
{
int V_23 = 0 ;
struct V_35 * V_36 = F_8 ( V_2 ) ;
const struct V_3 * V_37 ;
const struct V_8 * V_9 ;
int V_38 , V_39 ;
T_1 V_6 = 0 , V_40 ;
if ( F_9 ( V_41 ) )
F_10 (KERN_DEBUG DRV_NAME L_1 ,
pci_name(dev), size, offset) ;
if ( ! F_4 ( V_5 , V_10 ) ) {
V_23 = V_29 ;
goto V_42;
}
switch ( V_10 ) {
case 1 :
V_23 = F_11 ( V_2 , V_5 , ( V_14 * ) & V_6 ) ;
break;
case 2 :
V_23 = F_12 ( V_2 , V_5 , ( V_17 * ) & V_6 ) ;
break;
case 4 :
V_23 = F_13 ( V_2 , V_5 , & V_6 ) ;
break;
}
F_14 (cfg_entry, &dev_data->config_fields, list) {
V_9 = V_37 -> V_9 ;
V_38 = F_15 ( V_37 ) ;
V_39 = F_15 ( V_37 ) + V_9 -> V_10 ;
if ( V_5 + V_10 > V_38 && V_39 > V_5 ) {
V_23 = F_1 ( V_2 , V_37 , V_38 ,
& V_40 ) ;
if ( V_23 )
goto V_42;
V_6 = F_5 ( V_6 , V_40 ,
F_3 ( V_9 -> V_10 ) ,
V_38 - V_5 ) ;
}
}
V_42:
if ( F_9 ( V_41 ) )
F_10 (KERN_DEBUG DRV_NAME L_2 ,
pci_name(dev), size, offset, value) ;
* V_34 = V_6 ;
return F_6 ( V_23 ) ;
}
int F_16 ( struct V_1 * V_2 , int V_5 , int V_10 , T_1 V_6 )
{
int V_23 = 0 , V_43 = 0 ;
struct V_35 * V_36 = F_8 ( V_2 ) ;
const struct V_3 * V_37 ;
const struct V_8 * V_9 ;
T_1 V_40 ;
int V_38 , V_39 ;
if ( F_9 ( V_41 ) )
F_10 (KERN_DEBUG
DRV_NAME L_3 ,
pci_name(dev), size, offset, value) ;
if ( ! F_4 ( V_5 , V_10 ) )
return V_29 ;
F_14 (cfg_entry, &dev_data->config_fields, list) {
V_9 = V_37 -> V_9 ;
V_38 = F_15 ( V_37 ) ;
V_39 = F_15 ( V_37 ) + V_9 -> V_10 ;
if ( V_5 + V_10 > V_38 && V_39 > V_5 ) {
V_23 = F_1 ( V_2 , V_37 , V_38 ,
& V_40 ) ;
if ( V_23 )
break;
V_40 = F_5 ( V_40 , V_6 , F_3 ( V_10 ) ,
V_5 - V_38 ) ;
V_23 = F_2 ( V_2 , V_37 , V_38 ,
V_40 ) ;
V_43 = 1 ;
}
}
if ( ! V_43 && ! V_23 ) {
if ( V_36 -> V_44 || V_45 ) {
switch ( V_10 ) {
case 1 :
V_23 = F_17 ( V_2 , V_5 ,
( V_14 ) V_6 ) ;
break;
case 2 :
V_23 = F_18 ( V_2 , V_5 ,
( V_17 ) V_6 ) ;
break;
case 4 :
V_23 = F_19 ( V_2 , V_5 ,
( T_1 ) V_6 ) ;
break;
}
} else if ( ! V_36 -> V_46 ) {
V_36 -> V_46 = 1 ;
F_20 ( & V_2 -> V_2 , L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 , V_5 , V_10 ) ;
}
}
return F_6 ( V_23 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
struct V_3 * V_37 , * V_47 ;
const struct V_8 * V_9 ;
F_22 ( & V_2 -> V_2 , L_12
L_13 ) ;
if ( ! V_36 )
return;
F_23 (cfg_entry, t, &dev_data->config_fields, list) {
V_9 = V_37 -> V_9 ;
if ( V_9 -> V_48 ) {
V_9 -> V_48 ( (struct V_8 * ) V_9 ) ;
F_24 ( V_37 -> V_15 ) ;
F_25 ( & V_37 -> V_49 ) ;
F_24 ( V_37 ) ;
}
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
const struct V_3 * V_37 ;
const struct V_8 * V_9 ;
F_22 ( & V_2 -> V_2 , L_14 ) ;
if ( ! V_36 )
return;
F_14 (cfg_entry, &dev_data->config_fields, list) {
V_9 = V_37 -> V_9 ;
if ( V_9 -> V_50 )
V_9 -> V_50 ( V_2 , F_15 ( V_37 ) , V_37 -> V_15 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
struct V_3 * V_37 , * V_47 ;
const struct V_8 * V_9 ;
F_22 ( & V_2 -> V_2 , L_15 ) ;
if ( ! V_36 )
return;
F_23 (cfg_entry, t, &dev_data->config_fields, list) {
F_25 ( & V_37 -> V_49 ) ;
V_9 = V_37 -> V_9 ;
if ( V_9 -> V_51 )
V_9 -> V_51 ( V_2 , F_15 ( V_37 ) , V_37 -> V_15 ) ;
F_24 ( V_37 ) ;
}
}
int F_28 ( struct V_1 * V_2 ,
const struct V_8 * V_9 ,
unsigned int V_52 )
{
int V_23 = 0 ;
struct V_35 * V_36 = F_8 ( V_2 ) ;
struct V_3 * V_37 ;
void * V_53 ;
V_37 = F_29 ( sizeof( * V_37 ) , V_54 ) ;
if ( ! V_37 ) {
V_23 = - V_55 ;
goto V_42;
}
V_37 -> V_15 = NULL ;
V_37 -> V_9 = V_9 ;
V_37 -> V_52 = V_52 ;
V_23 = F_30 ( V_2 , F_15 ( V_37 ) ) ;
if ( V_23 )
goto V_42;
if ( V_9 -> V_56 ) {
V_53 = V_9 -> V_56 ( V_2 , F_15 ( V_37 ) ) ;
if ( F_31 ( V_53 ) ) {
V_23 = F_32 ( V_53 ) ;
goto V_42;
}
V_37 -> V_15 = V_53 ;
}
F_22 ( & V_2 -> V_2 , L_16 ,
F_15 ( V_37 ) ) ;
F_33 ( & V_37 -> V_49 , & V_36 -> V_57 ) ;
V_42:
if ( V_23 )
F_24 ( V_37 ) ;
return V_23 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
struct V_35 * V_36 = F_8 ( V_2 ) ;
F_22 ( & V_2 -> V_2 , L_17 ) ;
F_35 ( & V_36 -> V_57 ) ;
V_23 = F_36 ( V_2 ) ;
if ( V_23 )
goto V_42;
V_23 = F_37 ( V_2 ) ;
if ( V_23 )
goto V_42;
V_23 = F_38 ( V_2 ) ;
V_42:
return V_23 ;
}
int F_39 ( void )
{
return F_40 () ;
}
