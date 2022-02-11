static unsigned long F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_10 ;
#if 0
if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
pci_read_config_dword(pdev, 0xA4, &base);
} else {
pci_bus_read_config_dword(pdev->bus, 2, 0x5C, &base);
}
#else
if ( F_2 ( V_2 ) -> V_11 > 3 || F_3 ( V_2 ) ) {
T_2 V_12 ;
F_4 ( V_8 , 0xb0 , & V_12 ) ;
V_10 = V_12 >> 4 << 20 ;
} else {
T_3 V_12 ;
F_5 ( V_8 , 0x9c , & V_12 ) ;
V_10 = V_12 >> 3 << 27 ;
}
V_10 -= V_5 -> V_13 . V_14 -> V_15 ;
#endif
return V_10 + V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( L_1 ) ;
F_7 ( L_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 , * V_19 ( V_20 ) ;
unsigned long V_21 ;
unsigned long V_22 = 0 ;
F_9 ( V_2 ) ;
V_18 = F_10 ( & V_5 -> V_13 . V_23 , V_16 , 4096 , 0 ) ;
if ( V_18 )
V_18 = F_11 ( V_18 , V_16 , 4096 ) ;
if ( ! V_18 )
goto V_24;
V_21 = F_1 ( V_2 , V_18 -> V_25 ) ;
if ( ! V_21 )
goto V_26;
if ( ! ( F_12 ( V_2 ) || F_13 ( V_2 ) ) ) {
V_20 = F_10 ( & V_5 -> V_13 . V_23 ,
4096 , 4096 , 0 ) ;
if ( V_20 )
V_20 = F_11 ( V_20 ,
4096 , 4096 ) ;
if ( ! V_20 )
goto V_26;
V_22 = F_1 ( V_2 , V_20 -> V_25 ) ;
if ( ! V_22 )
goto V_27;
}
V_5 -> V_28 = V_16 ;
V_5 -> V_18 = V_18 ;
if ( F_13 ( V_2 ) )
F_14 ( V_29 , V_18 -> V_25 ) ;
else if ( F_12 ( V_2 ) ) {
F_14 ( V_30 , V_18 -> V_25 ) ;
} else {
F_14 ( V_31 , V_21 ) ;
F_14 ( V_32 , V_22 ) ;
V_5 -> V_20 = V_20 ;
}
F_15 ( L_3 ,
V_21 , V_22 , V_16 >> 20 ) ;
return;
V_27:
F_16 ( V_20 ) ;
V_26:
F_16 ( V_18 ) ;
V_24:
V_5 -> V_33 = V_34 ;
F_6 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_16 ( V_5 -> V_18 ) ;
if ( V_5 -> V_20 )
F_16 ( V_5 -> V_20 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 ) && V_35 )
F_17 ( V_2 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_36 = V_5 -> V_13 . V_14 -> V_15 ;
F_21 ( & V_5 -> V_13 . V_23 , 0 , V_36 ) ;
if ( F_19 ( V_2 ) && V_35 ) {
int V_28 ;
if ( V_36 > ( 36 * 1024 * 1024 ) )
V_28 = 32 * 1024 * 1024 ;
else
V_28 = V_36 * 7 / 8 ;
F_8 ( V_2 , V_28 ) ;
}
return 0 ;
}
