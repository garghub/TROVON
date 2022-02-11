int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 )
{
if ( ! V_5 )
return F_2 ( V_2 , V_3 , V_4 ) ;
V_2 -> V_2 . V_6 = V_3 ;
F_3 ( & V_2 -> V_7 , & V_8 ) ;
return 0 ;
}
static int T_1 F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_13 ;
int V_14 ;
F_5 (l, &ide_pci_drivers) {
V_13 = F_6 ( V_12 , struct V_1 , V_7 ) ;
if ( V_13 -> V_15 ) {
const struct V_16 * V_17 =
F_7 ( V_13 -> V_15 , V_10 ) ;
if ( V_17 != NULL ) {
F_8 ( V_10 ) ;
V_14 = V_13 -> V_18 ( V_10 , V_17 ) ;
if ( V_14 >= 0 ) {
V_10 -> V_2 = V_13 ;
F_9 ( V_10 ) ;
return 1 ;
}
}
}
}
return 0 ;
}
static int T_1 F_10 ( void )
{
struct V_9 * V_10 = NULL ;
struct V_1 * V_13 ;
struct V_11 * V_12 , * V_19 ;
V_5 = 0 ;
F_11 (dev)
F_4 ( V_10 ) ;
F_12 (l, n, &ide_pci_drivers) {
F_13 ( V_12 ) ;
V_13 = F_6 ( V_12 , struct V_1 , V_7 ) ;
if ( F_2 ( V_13 , V_13 -> V_2 . V_6 ,
V_13 -> V_2 . V_4 ) )
F_14 ( V_20 L_1 ,
V_21 , V_13 -> V_2 . V_4 ) ;
}
return 0 ;
}
