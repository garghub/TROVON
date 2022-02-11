static inline int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 < 0 )
return 0 ;
return V_4 == V_3 ;
}
struct V_1 * F_3 ( struct V_1 * V_5 ,
unsigned int V_4 )
{
struct V_1 * V_2 , * V_6 ;
F_4 (parent, node) {
if ( F_1 ( V_2 , V_4 ) )
return V_2 ;
if ( ! strcmp ( V_2 -> V_7 , L_1 ) ) {
F_4 (node, node2) {
if ( F_1 ( V_6 , V_4 ) ) {
F_5 ( V_2 ) ;
return V_6 ;
}
}
}
}
return NULL ;
}
int F_2 ( struct V_1 * V_8 )
{
unsigned int V_9 ;
const T_1 * V_10 ;
V_10 = F_6 ( V_8 , L_2 , & V_9 ) ;
if ( ! V_10 || V_9 < 5 * sizeof( T_1 ) )
return - V_11 ;
return ( F_7 ( V_10 ) >> 8 ) & 0xff ;
}
int F_8 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const T_1 * V_14 ;
int V_15 ;
V_14 = F_6 ( V_2 , L_3 , & V_15 ) ;
if ( ! V_14 || V_15 < sizeof( * V_14 ) * 2 )
return - V_11 ;
V_13 -> V_7 = V_2 -> V_7 ;
V_13 -> V_16 = F_7 ( V_14 ++ ) ;
V_13 -> V_17 = F_7 ( V_14 ) ;
V_13 -> V_18 = V_19 ;
return 0 ;
}
int F_9 ( struct V_20 * V_21 )
{
if ( ! F_10 ( V_21 -> V_22 , L_4 ) )
return - V_11 ;
F_11 ( & V_23 ) ;
F_12 ( & V_21 -> V_24 , & V_25 ) ;
F_13 ( & V_23 ) ;
return 0 ;
}
void F_14 ( struct V_20 * V_21 )
{
F_11 ( & V_23 ) ;
F_15 ( & V_21 -> V_24 ) ;
F_13 ( & V_23 ) ;
}
struct V_20 * F_16 ( struct V_1 * V_22 )
{
struct V_20 * V_26 ;
F_11 ( & V_23 ) ;
F_17 (c, &of_pci_msi_chip_list, list) {
if ( V_26 -> V_22 == V_22 ) {
F_13 ( & V_23 ) ;
return V_26 ;
}
}
F_13 ( & V_23 ) ;
return NULL ;
}
