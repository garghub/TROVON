static int F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
struct V_3 * V_4 ;
F_2 ( V_5 -> V_6 , V_7 , & V_2 ) ;
V_2 &= ~ ( 0xfffffff0 ) ;
V_4 = F_3 ( V_5 -> V_8 -> V_9 ) ;
for ( V_1 = 0 ; V_1 < V_5 -> V_8 -> V_10 ; V_1 ++ ) {
if ( V_2 == V_4 [ V_1 ] . V_11 ) {
V_5 -> V_12 =
V_5 -> V_13 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_14 = V_1 ;
return V_4 [ V_1 ] . V_15 ;
}
}
return 0 ;
}
static void F_4 ( struct V_16 * V_17 )
{
T_1 V_2 ;
F_2 ( V_5 -> V_6 , V_18 , & V_2 ) ;
V_2 &= 0xfffffff0 ;
V_2 |= ( 1 << 0 | 1 << 1 ) ;
F_5 ( V_5 -> V_6 , V_19 , V_2 ) ;
}
static void F_6 ( void )
{
struct V_3 * V_12 ;
T_1 V_2 ;
V_12 = F_3 ( V_5 -> V_12 ) ;
F_2 ( V_5 -> V_6 , V_18 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_19 ,
( ( V_2 & 0xffffff00 ) | 0x00000001 | 0x00000002 ) ) ;
F_2 ( V_5 -> V_6 , V_7 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_7 ,
( ( V_2 & 0x00000ff0 ) | V_12 -> V_11 ) ) ;
}
static int F_7 ( void )
{
T_1 V_2 ;
struct V_3 * V_13 ;
V_13 = F_3 ( V_5 -> V_13 ) ;
F_2 ( V_5 -> V_6 , V_7 , & V_2 ) ;
V_2 = ( ( ( V_2 & 0x00000ff0 ) | ( V_5 -> V_20 & 0xfffff000 ) )
| ( V_13 -> V_11 & 0xf ) ) ;
F_5 ( V_5 -> V_6 , V_7 , V_2 ) ;
F_2 ( V_5 -> V_6 , V_18 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_18 , ( ( V_2 & 0xffffff00 ) | 0x00000010 ) ) ;
F_2 ( V_5 -> V_6 , V_21 , & V_2 ) ;
V_5 -> V_22 = ( V_2 & V_23 ) ;
#if 0
if (agp_bridge->type == ALI_M1541) {
u32 nlvm_addr = 0;
switch (current_size->size_value) {
case 0: break;
case 1: nlvm_addr = 0x100000;break;
case 2: nlvm_addr = 0x200000;break;
case 3: nlvm_addr = 0x400000;break;
case 4: nlvm_addr = 0x800000;break;
case 6: nlvm_addr = 0x1000000;break;
case 7: nlvm_addr = 0x2000000;break;
case 8: nlvm_addr = 0x4000000;break;
case 9: nlvm_addr = 0x8000000;break;
case 10: nlvm_addr = 0x10000000;break;
default: break;
}
nlvm_addr--;
nlvm_addr&=0xfff00000;
nlvm_addr+= agp_bridge->gart_bus_addr;
nlvm_addr|=(agp_bridge->gart_bus_addr>>12);
dev_info(&agp_bridge->dev->dev, "nlvm top &base = %8x\n",
nlvm_addr);
}
#endif
F_2 ( V_5 -> V_6 , V_18 , & V_2 ) ;
V_2 &= 0xffffff7f ;
F_5 ( V_5 -> V_6 , V_18 , V_2 ) ;
return 0 ;
}
static void F_8 ( void )
{
int V_1 , V_24 ;
T_1 V_2 ;
F_9 () ;
V_24 = 1 << F_3 ( V_5 -> V_13 ) -> V_25 ;
for ( V_1 = 0 ; V_1 < V_26 * V_24 ; V_1 += V_26 ) {
F_2 ( V_5 -> V_6 , V_27 ,
& V_2 ) ;
F_5 ( V_5 -> V_6 , V_27 ,
( ( ( V_2 & V_28 ) |
( V_5 -> V_20 + V_1 ) ) |
V_29 ) ) ;
}
}
static struct V_30 * F_10 ( struct V_31 * V_32 )
{
struct V_30 * V_30 = F_11 ( V_5 ) ;
T_1 V_2 ;
if ( ! V_30 )
return NULL ;
F_2 ( V_5 -> V_6 , V_27 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_27 ,
( ( ( V_2 & V_28 ) |
F_12 ( V_30 ) ) | V_29 ) ) ;
return V_30 ;
}
static void F_13 ( struct V_30 * V_30 , int V_33 )
{
if ( V_30 ) {
if ( V_33 & V_34 ) {
F_9 () ;
F_14 ( V_30 , V_33 ) ;
} else
F_14 ( V_30 , V_33 ) ;
}
}
static void F_15 ( struct V_30 * V_30 , int V_33 )
{
T_1 V_2 ;
if ( V_30 == NULL )
return;
if ( V_33 & V_34 ) {
F_9 () ;
F_2 ( V_5 -> V_6 , V_27 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_27 ,
( ( ( V_2 & V_28 ) |
F_12 ( V_30 ) ) | V_29 ) ) ;
}
F_14 ( V_30 , V_33 ) ;
}
static int T_2 F_16 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_39 * V_40 = V_41 ;
struct V_31 * V_32 ;
T_3 V_42 , V_43 ;
int V_44 ;
V_43 = F_17 ( V_36 , V_45 ) ;
if ( ! V_43 )
return - V_46 ;
for ( V_44 = 0 ; V_40 [ V_44 ] . V_47 ; V_44 ++ ) {
if ( V_36 -> V_48 == V_40 [ V_44 ] . V_49 )
goto V_50;
}
F_18 ( & V_36 -> V_6 , L_1 ,
V_36 -> V_51 , V_36 -> V_48 ) ;
return - V_46 ;
V_50:
V_32 = F_19 () ;
if ( ! V_32 )
return - V_52 ;
V_32 -> V_6 = V_36 ;
V_32 -> V_53 = V_43 ;
switch ( V_36 -> V_48 ) {
case V_54 :
V_32 -> V_8 = & V_55 ;
break;
case V_56 :
F_20 ( V_36 , 0xFB , & V_42 ) ;
switch ( V_42 ) {
case 0x31 :
V_40 [ V_44 ] . V_47 = L_2 ;
break;
case 0x32 :
V_40 [ V_44 ] . V_47 = L_3 ;
break;
case 0x41 :
V_40 [ V_44 ] . V_47 = L_4 ;
break;
case 0x43 :
V_40 [ V_44 ] . V_47 = L_5 ;
break;
case 0x47 :
V_40 [ V_44 ] . V_47 = L_6 ;
break;
case 0x51 :
V_40 [ V_44 ] . V_47 = L_7 ;
break;
default:
break;
}
default:
V_32 -> V_8 = & V_57 ;
}
F_21 ( & V_36 -> V_6 , L_8 , V_40 [ V_44 ] . V_47 ) ;
F_2 ( V_36 ,
V_32 -> V_53 + V_58 ,
& V_32 -> V_59 ) ;
F_22 ( V_36 , V_32 ) ;
return F_23 ( V_32 ) ;
}
static void T_4 F_24 ( struct V_35 * V_36 )
{
struct V_31 * V_32 = F_25 ( V_36 ) ;
F_26 ( V_32 ) ;
F_27 ( V_32 ) ;
}
static int T_5 F_28 ( void )
{
if ( V_60 )
return - V_61 ;
return F_29 ( & V_62 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_62 ) ;
}
