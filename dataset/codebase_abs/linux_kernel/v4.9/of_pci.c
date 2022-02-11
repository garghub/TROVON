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
void F_10 ( void )
{
T_3 V_22 ;
int V_23 ;
V_23 = F_11 ( V_24 , L_5 , & V_22 ) ;
if ( V_23 ) {
if ( V_23 == - V_25 || V_23 == - V_26 )
F_12 ( L_6 ) ;
return;
}
if ( V_22 )
F_13 ( V_27 ) ;
else
F_14 ( V_27 ) ;
F_15 ( L_7 , V_22 ? L_8 : L_9 ) ;
}
int F_16 ( struct V_1 * V_28 ,
unsigned char V_29 , unsigned char V_30 ,
struct V_31 * V_32 , T_4 * V_33 )
{
struct V_34 * V_35 ;
struct V_12 * V_13 ;
struct V_12 * V_36 ;
struct V_37 V_38 ;
struct V_39 V_40 ;
char V_41 [ 4 ] ;
int V_42 ;
if ( V_33 )
* V_33 = ( T_4 ) V_43 ;
V_36 = F_17 ( sizeof( * V_36 ) , V_44 ) ;
if ( ! V_36 )
return - V_45 ;
F_15 ( L_10 , V_28 -> V_46 ) ;
V_42 = F_8 ( V_28 , V_36 ) ;
if ( V_42 ) {
V_36 -> V_16 = V_29 ;
V_36 -> V_17 = V_30 ;
V_36 -> V_18 = V_19 ;
F_15 ( L_11 ,
V_28 -> V_46 , V_36 ) ;
} else {
if ( V_36 -> V_17 > V_36 -> V_16 + V_30 )
V_36 -> V_17 = V_36 -> V_16 + V_30 ;
}
F_18 ( V_32 , V_36 ) ;
V_42 = F_19 ( & V_40 , V_28 ) ;
if ( V_42 )
goto V_47;
F_20 ( L_12 ) ;
F_21 (&parser, &range) {
if ( ( V_38 . V_18 & V_48 ) == V_49 )
snprintf ( V_41 , 4 , L_13 ) ;
else if ( ( V_38 . V_18 & V_48 ) == V_50 )
snprintf ( V_41 , 4 , L_14 ) ;
else
snprintf ( V_41 , 4 , L_15 ) ;
F_15 ( L_16 , V_41 ,
V_38 . V_51 , V_38 . V_51 + V_38 . V_9 - 1 ,
V_38 . V_52 ) ;
if ( V_38 . V_51 == V_43 || V_38 . V_9 == 0 )
continue;
V_13 = F_17 ( sizeof( struct V_12 ) , V_44 ) ;
if ( ! V_13 ) {
V_42 = - V_45 ;
goto V_47;
}
V_42 = F_22 ( & V_38 , V_28 , V_13 ) ;
if ( V_42 ) {
F_23 ( V_13 ) ;
continue;
}
if ( F_24 ( V_13 ) == V_49 ) {
if ( ! V_33 ) {
F_25 ( L_17 ,
V_28 -> V_46 ) ;
V_42 = - V_11 ;
goto V_53;
}
if ( * V_33 != ( T_4 ) V_43 )
F_12 ( L_18 ,
V_28 -> V_46 ) ;
* V_33 = V_38 . V_51 ;
}
F_26 ( V_32 , V_13 , V_13 -> V_16 - V_38 . V_52 ) ;
}
return 0 ;
V_53:
F_23 ( V_13 ) ;
V_47:
F_27 (window, resources)
F_23 ( V_35 -> V_13 ) ;
F_28 ( V_32 ) ;
return V_42 ;
}
int F_29 ( struct V_54 * V_55 )
{
if ( ! F_30 ( V_55 -> V_56 , L_19 ) )
return - V_11 ;
F_31 ( & V_57 ) ;
F_32 ( & V_55 -> V_58 , & V_59 ) ;
F_33 ( & V_57 ) ;
return 0 ;
}
void F_34 ( struct V_54 * V_55 )
{
F_31 ( & V_57 ) ;
F_35 ( & V_55 -> V_58 ) ;
F_33 ( & V_57 ) ;
}
struct V_54 * F_36 ( struct V_1 * V_56 )
{
struct V_54 * V_60 ;
F_31 ( & V_57 ) ;
F_37 (c, &of_pci_msi_chip_list, list) {
if ( V_60 -> V_56 == V_56 ) {
F_33 ( & V_57 ) ;
return V_60 ;
}
}
F_33 ( & V_57 ) ;
return NULL ;
}
int F_38 ( struct V_1 * V_8 , T_3 V_61 ,
const char * V_62 , const char * V_63 ,
struct V_1 * * V_64 , T_3 * V_65 )
{
T_3 V_66 , V_67 ;
int V_68 ;
const T_1 * V_69 = NULL ;
if ( ! V_8 || ! V_62 || ( ! V_64 && ! V_65 ) )
return - V_11 ;
V_69 = F_6 ( V_8 , V_62 , & V_68 ) ;
if ( ! V_69 ) {
if ( V_64 )
return - V_70 ;
* V_65 = V_61 ;
return 0 ;
}
if ( ! V_68 || V_68 % ( 4 * sizeof( * V_69 ) ) ) {
F_25 ( L_20 , V_8 -> V_46 ,
V_62 , V_68 ) ;
return - V_11 ;
}
V_66 = 0xffffffff ;
if ( V_63 )
F_11 ( V_8 , V_63 , & V_66 ) ;
V_67 = V_66 & V_61 ;
for ( ; V_68 > 0 ; V_68 -= 4 * sizeof( * V_69 ) , V_69 += 4 ) {
struct V_1 * V_71 ;
T_3 V_72 = F_7 ( V_69 + 0 ) ;
T_3 V_73 = F_7 ( V_69 + 1 ) ;
T_3 V_74 = F_7 ( V_69 + 2 ) ;
T_3 V_75 = F_7 ( V_69 + 3 ) ;
if ( V_72 & ~ V_66 ) {
F_25 ( L_21 ,
V_8 -> V_46 , V_62 , V_62 ,
V_66 , V_72 ) ;
return - V_76 ;
}
if ( V_67 < V_72 || V_67 >= V_72 + V_75 )
continue;
V_71 = F_39 ( V_73 ) ;
if ( ! V_71 )
return - V_70 ;
if ( V_64 ) {
if ( * V_64 )
F_5 ( V_71 ) ;
else
* V_64 = V_71 ;
if ( * V_64 != V_71 )
continue;
}
if ( V_65 )
* V_65 = V_67 - V_72 + V_74 ;
F_20 ( L_22 ,
V_8 -> V_46 , V_62 , V_66 , V_72 , V_74 ,
V_75 , V_61 , * V_65 ) ;
return 0 ;
}
F_25 ( L_23 ,
V_8 -> V_46 , V_62 , V_61 ,
V_64 && * V_64 ? ( * V_64 ) -> V_46 : L_24 ) ;
return - V_76 ;
}
