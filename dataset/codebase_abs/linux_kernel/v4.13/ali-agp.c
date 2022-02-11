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
V_5 -> V_21 = F_8 ( V_5 -> V_6 ,
V_22 ) ;
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
static void F_9 ( void )
{
int V_1 , V_23 ;
T_1 V_2 ;
F_10 () ;
V_23 = 1 << F_3 ( V_5 -> V_13 ) -> V_24 ;
for ( V_1 = 0 ; V_1 < V_25 * V_23 ; V_1 += V_25 ) {
F_2 ( V_5 -> V_6 , V_26 ,
& V_2 ) ;
F_5 ( V_5 -> V_6 , V_26 ,
( ( ( V_2 & V_27 ) |
( V_5 -> V_20 + V_1 ) ) |
V_28 ) ) ;
}
}
static struct V_29 * F_11 ( struct V_30 * V_31 )
{
struct V_29 * V_29 = F_12 ( V_5 ) ;
T_1 V_2 ;
if ( ! V_29 )
return NULL ;
F_2 ( V_5 -> V_6 , V_26 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_26 ,
( ( ( V_2 & V_27 ) |
F_13 ( V_29 ) ) | V_28 ) ) ;
return V_29 ;
}
static void F_14 ( struct V_29 * V_29 , int V_32 )
{
if ( V_29 ) {
if ( V_32 & V_33 ) {
F_10 () ;
F_15 ( V_29 , V_32 ) ;
} else
F_15 ( V_29 , V_32 ) ;
}
}
static void F_16 ( struct V_29 * V_29 , int V_32 )
{
T_1 V_2 ;
if ( V_29 == NULL )
return;
if ( V_32 & V_33 ) {
F_10 () ;
F_2 ( V_5 -> V_6 , V_26 , & V_2 ) ;
F_5 ( V_5 -> V_6 , V_26 ,
( ( ( V_2 & V_27 ) |
F_13 ( V_29 ) ) | V_28 ) ) ;
}
F_15 ( V_29 , V_32 ) ;
}
static int F_17 ( struct V_34 * V_35 , const struct V_36 * V_37 )
{
struct V_38 * V_39 = V_40 ;
struct V_30 * V_31 ;
T_2 V_41 , V_42 ;
int V_43 ;
V_42 = F_18 ( V_35 , V_44 ) ;
if ( ! V_42 )
return - V_45 ;
for ( V_43 = 0 ; V_39 [ V_43 ] . V_46 ; V_43 ++ ) {
if ( V_35 -> V_47 == V_39 [ V_43 ] . V_48 )
goto V_49;
}
F_19 ( & V_35 -> V_6 , L_1 ,
V_35 -> V_50 , V_35 -> V_47 ) ;
return - V_45 ;
V_49:
V_31 = F_20 () ;
if ( ! V_31 )
return - V_51 ;
V_31 -> V_6 = V_35 ;
V_31 -> V_52 = V_42 ;
switch ( V_35 -> V_47 ) {
case V_53 :
V_31 -> V_8 = & V_54 ;
break;
case V_55 :
F_21 ( V_35 , 0xFB , & V_41 ) ;
switch ( V_41 ) {
case 0x31 :
V_39 [ V_43 ] . V_46 = L_2 ;
break;
case 0x32 :
V_39 [ V_43 ] . V_46 = L_3 ;
break;
case 0x41 :
V_39 [ V_43 ] . V_46 = L_4 ;
break;
case 0x43 :
V_39 [ V_43 ] . V_46 = L_5 ;
break;
case 0x47 :
V_39 [ V_43 ] . V_46 = L_6 ;
break;
case 0x51 :
V_39 [ V_43 ] . V_46 = L_7 ;
break;
default:
break;
}
default:
V_31 -> V_8 = & V_56 ;
}
F_22 ( & V_35 -> V_6 , L_8 , V_39 [ V_43 ] . V_46 ) ;
F_2 ( V_35 ,
V_31 -> V_52 + V_57 ,
& V_31 -> V_58 ) ;
F_23 ( V_35 , V_31 ) ;
return F_24 ( V_31 ) ;
}
static void F_25 ( struct V_34 * V_35 )
{
struct V_30 * V_31 = F_26 ( V_35 ) ;
F_27 ( V_31 ) ;
F_28 ( V_31 ) ;
}
static int T_3 F_29 ( void )
{
if ( V_59 )
return - V_60 ;
return F_30 ( & V_61 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_61 ) ;
}
