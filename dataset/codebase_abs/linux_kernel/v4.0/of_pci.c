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
int F_9 ( struct V_1 * V_2 )
{
const T_1 * V_20 ;
int V_15 ;
T_2 V_21 ;
V_20 = F_6 ( V_2 , L_4 , & V_15 ) ;
if ( ! V_20 || V_15 < sizeof( * V_20 ) )
return - V_11 ;
V_21 = ( T_2 ) F_7 ( V_20 ) ;
return V_21 ;
}
int F_10 ( struct V_1 * V_22 ,
unsigned char V_23 , unsigned char V_24 ,
struct V_25 * V_26 , T_3 * V_27 )
{
struct V_28 * V_29 ;
struct V_12 * V_13 ;
struct V_12 * V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
char V_35 [ 4 ] ;
int V_36 ;
if ( V_27 )
* V_27 = ( T_3 ) V_37 ;
V_30 = F_11 ( sizeof( * V_30 ) , V_38 ) ;
if ( ! V_30 )
return - V_39 ;
F_12 ( L_5 , V_22 -> V_40 ) ;
V_36 = F_8 ( V_22 , V_30 ) ;
if ( V_36 ) {
V_30 -> V_16 = V_23 ;
V_30 -> V_17 = V_24 ;
V_30 -> V_18 = V_19 ;
F_12 ( L_6 ,
V_22 -> V_40 , V_30 ) ;
} else {
if ( V_30 -> V_17 > V_30 -> V_16 + V_24 )
V_30 -> V_17 = V_30 -> V_16 + V_24 ;
}
F_13 ( V_26 , V_30 ) ;
V_36 = F_14 ( & V_34 , V_22 ) ;
if ( V_36 )
goto V_41;
F_15 ( L_7 ) ;
F_16 (&parser, &range) {
if ( ( V_32 . V_18 & V_42 ) == V_43 )
snprintf ( V_35 , 4 , L_8 ) ;
else if ( ( V_32 . V_18 & V_42 ) == V_44 )
snprintf ( V_35 , 4 , L_9 ) ;
else
snprintf ( V_35 , 4 , L_10 ) ;
F_12 ( L_11 , V_35 ,
V_32 . V_45 , V_32 . V_45 + V_32 . V_9 - 1 ,
V_32 . V_46 ) ;
if ( V_32 . V_45 == V_37 || V_32 . V_9 == 0 )
continue;
V_13 = F_11 ( sizeof( struct V_12 ) , V_38 ) ;
if ( ! V_13 ) {
V_36 = - V_39 ;
goto V_41;
}
V_36 = F_17 ( & V_32 , V_22 , V_13 ) ;
if ( V_36 )
goto V_47;
if ( F_18 ( V_13 ) == V_43 ) {
if ( ! V_27 ) {
F_19 ( L_12 ,
V_22 -> V_40 ) ;
V_36 = - V_11 ;
goto V_47;
}
if ( * V_27 != ( T_3 ) V_37 )
F_20 ( L_13 ,
V_22 -> V_40 ) ;
* V_27 = V_32 . V_45 ;
}
F_21 ( V_26 , V_13 , V_13 -> V_16 - V_32 . V_46 ) ;
}
return 0 ;
V_47:
F_22 ( V_13 ) ;
V_41:
F_23 (window, resources)
F_22 ( V_29 -> V_13 ) ;
F_24 ( V_26 ) ;
return V_36 ;
}
int F_25 ( struct V_48 * V_49 )
{
if ( ! F_26 ( V_49 -> V_50 , L_14 ) )
return - V_11 ;
F_27 ( & V_51 ) ;
F_28 ( & V_49 -> V_52 , & V_53 ) ;
F_29 ( & V_51 ) ;
return 0 ;
}
void F_30 ( struct V_48 * V_49 )
{
F_27 ( & V_51 ) ;
F_31 ( & V_49 -> V_52 ) ;
F_29 ( & V_51 ) ;
}
struct V_48 * F_32 ( struct V_1 * V_50 )
{
struct V_48 * V_54 ;
F_27 ( & V_51 ) ;
F_33 (c, &of_pci_msi_chip_list, list) {
if ( V_54 -> V_50 == V_50 ) {
F_29 ( & V_51 ) ;
return V_54 ;
}
}
F_29 ( & V_51 ) ;
return NULL ;
}
