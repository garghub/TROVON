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
void F_10 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
struct V_23 * V_25 = F_11 ( V_22 ) ;
if ( ! V_25 -> V_5 )
return;
F_12 ( V_24 , V_25 -> V_5 -> V_26 ) ;
F_13 ( V_25 ) ;
}
int F_14 ( struct V_1 * V_24 ,
unsigned char V_27 , unsigned char V_28 ,
struct V_29 * V_30 , T_3 * V_31 )
{
struct V_32 * V_33 ;
struct V_12 * V_13 ;
struct V_12 * V_34 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
char V_39 [ 4 ] ;
int V_40 ;
if ( V_31 )
* V_31 = ( T_3 ) V_41 ;
V_34 = F_15 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
F_16 ( L_5 , V_24 -> V_44 ) ;
V_40 = F_8 ( V_24 , V_34 ) ;
if ( V_40 ) {
V_34 -> V_16 = V_27 ;
V_34 -> V_17 = V_28 ;
V_34 -> V_18 = V_19 ;
F_16 ( L_6 ,
V_24 -> V_44 , V_34 ) ;
} else {
if ( V_34 -> V_17 > V_34 -> V_16 + V_28 )
V_34 -> V_17 = V_34 -> V_16 + V_28 ;
}
F_17 ( V_30 , V_34 ) ;
V_40 = F_18 ( & V_38 , V_24 ) ;
if ( V_40 )
goto V_45;
F_19 ( L_7 ) ;
F_20 (&parser, &range) {
if ( ( V_36 . V_18 & V_46 ) == V_47 )
snprintf ( V_39 , 4 , L_8 ) ;
else if ( ( V_36 . V_18 & V_46 ) == V_48 )
snprintf ( V_39 , 4 , L_9 ) ;
else
snprintf ( V_39 , 4 , L_10 ) ;
F_16 ( L_11 , V_39 ,
V_36 . V_49 , V_36 . V_49 + V_36 . V_9 - 1 ,
V_36 . V_50 ) ;
if ( V_36 . V_49 == V_41 || V_36 . V_9 == 0 )
continue;
V_13 = F_15 ( sizeof( struct V_12 ) , V_42 ) ;
if ( ! V_13 ) {
V_40 = - V_43 ;
goto V_45;
}
V_40 = F_21 ( & V_36 , V_24 , V_13 ) ;
if ( V_40 )
goto V_51;
if ( F_22 ( V_13 ) == V_47 ) {
if ( ! V_31 ) {
F_23 ( L_12 ,
V_24 -> V_44 ) ;
V_40 = - V_11 ;
goto V_51;
}
if ( * V_31 != ( T_3 ) V_41 )
F_24 ( L_13 ,
V_24 -> V_44 ) ;
* V_31 = V_36 . V_49 ;
}
F_25 ( V_30 , V_13 , V_13 -> V_16 - V_36 . V_50 ) ;
}
return 0 ;
V_51:
F_26 ( V_13 ) ;
V_45:
F_27 (window, resources)
F_26 ( V_33 -> V_13 ) ;
F_28 ( V_30 ) ;
return V_40 ;
}
int F_29 ( struct V_52 * V_53 )
{
if ( ! F_30 ( V_53 -> V_26 , L_14 ) )
return - V_11 ;
F_31 ( & V_54 ) ;
F_32 ( & V_53 -> V_55 , & V_56 ) ;
F_33 ( & V_54 ) ;
return 0 ;
}
void F_34 ( struct V_52 * V_53 )
{
F_31 ( & V_54 ) ;
F_35 ( & V_53 -> V_55 ) ;
F_33 ( & V_54 ) ;
}
struct V_52 * F_36 ( struct V_1 * V_26 )
{
struct V_52 * V_57 ;
F_31 ( & V_54 ) ;
F_37 (c, &of_pci_msi_chip_list, list) {
if ( V_57 -> V_26 == V_26 ) {
F_33 ( & V_54 ) ;
return V_57 ;
}
}
F_33 ( & V_54 ) ;
return NULL ;
}
