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
int F_10 ( struct V_1 * V_2 )
{
T_3 V_22 ;
if ( F_11 ( V_2 , L_5 , & V_22 ) ||
V_22 > 4 )
return - V_11 ;
return V_22 ;
}
void F_12 ( void )
{
T_3 V_23 ;
int V_24 ;
V_24 = F_11 ( V_25 , L_6 , & V_23 ) ;
if ( V_24 ) {
if ( V_24 == - V_26 || V_24 == - V_27 )
F_13 ( L_7 ) ;
return;
}
if ( V_23 )
F_14 ( V_28 ) ;
else
F_15 ( V_28 ) ;
F_16 ( L_8 , V_23 ? L_9 : L_10 ) ;
}
int F_17 ( struct V_1 * V_29 ,
unsigned char V_30 , unsigned char V_31 ,
struct V_32 * V_33 , T_4 * V_34 )
{
struct V_35 * V_36 ;
struct V_12 * V_13 ;
struct V_12 * V_37 ;
struct V_38 V_39 ;
struct V_40 V_41 ;
char V_42 [ 4 ] ;
int V_43 ;
if ( V_34 )
* V_34 = ( T_4 ) V_44 ;
V_37 = F_18 ( sizeof( * V_37 ) , V_45 ) ;
if ( ! V_37 )
return - V_46 ;
F_16 ( L_11 , V_29 -> V_47 ) ;
V_43 = F_8 ( V_29 , V_37 ) ;
if ( V_43 ) {
V_37 -> V_16 = V_30 ;
V_37 -> V_17 = V_31 ;
V_37 -> V_18 = V_19 ;
F_16 ( L_12 ,
V_29 -> V_47 , V_37 ) ;
} else {
if ( V_37 -> V_17 > V_37 -> V_16 + V_31 )
V_37 -> V_17 = V_37 -> V_16 + V_31 ;
}
F_19 ( V_33 , V_37 ) ;
V_43 = F_20 ( & V_41 , V_29 ) ;
if ( V_43 )
goto V_48;
F_21 ( L_13 ) ;
F_22 (&parser, &range) {
if ( ( V_39 . V_18 & V_49 ) == V_50 )
snprintf ( V_42 , 4 , L_14 ) ;
else if ( ( V_39 . V_18 & V_49 ) == V_51 )
snprintf ( V_42 , 4 , L_15 ) ;
else
snprintf ( V_42 , 4 , L_16 ) ;
F_16 ( L_17 , V_42 ,
V_39 . V_52 , V_39 . V_52 + V_39 . V_9 - 1 ,
V_39 . V_53 ) ;
if ( V_39 . V_52 == V_44 || V_39 . V_9 == 0 )
continue;
V_13 = F_18 ( sizeof( struct V_12 ) , V_45 ) ;
if ( ! V_13 ) {
V_43 = - V_46 ;
goto V_48;
}
V_43 = F_23 ( & V_39 , V_29 , V_13 ) ;
if ( V_43 ) {
F_24 ( V_13 ) ;
continue;
}
if ( F_25 ( V_13 ) == V_50 ) {
if ( ! V_34 ) {
F_26 ( L_18 ,
V_29 -> V_47 ) ;
V_43 = - V_11 ;
goto V_54;
}
if ( * V_34 != ( T_4 ) V_44 )
F_13 ( L_19 ,
V_29 -> V_47 ) ;
* V_34 = V_39 . V_52 ;
}
F_27 ( V_33 , V_13 , V_13 -> V_16 - V_39 . V_53 ) ;
}
return 0 ;
V_54:
F_24 ( V_13 ) ;
V_48:
F_28 (window, resources)
F_24 ( V_36 -> V_13 ) ;
F_29 ( V_33 ) ;
return V_43 ;
}
int F_30 ( struct V_1 * V_8 , T_3 V_55 ,
const char * V_56 , const char * V_57 ,
struct V_1 * * V_58 , T_3 * V_59 )
{
T_3 V_60 , V_61 ;
int V_62 ;
const T_1 * V_63 = NULL ;
if ( ! V_8 || ! V_56 || ( ! V_58 && ! V_59 ) )
return - V_11 ;
V_63 = F_6 ( V_8 , V_56 , & V_62 ) ;
if ( ! V_63 ) {
if ( V_58 )
return - V_64 ;
* V_59 = V_55 ;
return 0 ;
}
if ( ! V_62 || V_62 % ( 4 * sizeof( * V_63 ) ) ) {
F_26 ( L_20 , V_8 -> V_47 ,
V_56 , V_62 ) ;
return - V_11 ;
}
V_60 = 0xffffffff ;
if ( V_57 )
F_11 ( V_8 , V_57 , & V_60 ) ;
V_61 = V_60 & V_55 ;
for ( ; V_62 > 0 ; V_62 -= 4 * sizeof( * V_63 ) , V_63 += 4 ) {
struct V_1 * V_65 ;
T_3 V_66 = F_7 ( V_63 + 0 ) ;
T_3 V_67 = F_7 ( V_63 + 1 ) ;
T_3 V_68 = F_7 ( V_63 + 2 ) ;
T_3 V_69 = F_7 ( V_63 + 3 ) ;
if ( V_66 & ~ V_60 ) {
F_26 ( L_21 ,
V_8 -> V_47 , V_56 , V_56 ,
V_60 , V_66 ) ;
return - V_70 ;
}
if ( V_61 < V_66 || V_61 >= V_66 + V_69 )
continue;
V_65 = F_31 ( V_67 ) ;
if ( ! V_65 )
return - V_64 ;
if ( V_58 ) {
if ( * V_58 )
F_5 ( V_65 ) ;
else
* V_58 = V_65 ;
if ( * V_58 != V_65 )
continue;
}
if ( V_59 )
* V_59 = V_61 - V_66 + V_68 ;
F_21 ( L_22 ,
V_8 -> V_47 , V_56 , V_60 , V_66 , V_68 ,
V_69 , V_55 , * V_59 ) ;
return 0 ;
}
F_26 ( L_23 ,
V_8 -> V_47 , V_56 , V_55 ,
V_58 && * V_58 ? ( * V_58 ) -> V_47 : L_24 ) ;
return - V_70 ;
}
