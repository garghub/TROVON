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
T_1 V_9 [ 5 ] ;
int error ;
error = F_6 ( V_8 , L_2 , V_9 , F_7 ( V_9 ) ) ;
if ( error )
return error ;
return ( V_9 [ 0 ] >> 8 ) & 0xff ;
}
int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
T_1 V_12 [ 2 ] ;
int error ;
error = F_6 ( V_2 , L_3 , V_12 ,
F_7 ( V_12 ) ) ;
if ( error )
return error ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_13 = V_12 [ 0 ] ;
V_11 -> V_14 = V_12 [ 1 ] ;
V_11 -> V_15 = V_16 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
T_1 V_17 ;
int error ;
error = F_10 ( V_2 , L_4 , & V_17 ) ;
if ( error )
return error ;
return ( V_18 ) V_17 ;
}
int F_11 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( F_10 ( V_2 , L_5 , & V_19 ) ||
V_19 > 4 )
return - V_20 ;
return V_19 ;
}
void F_12 ( void )
{
T_1 V_21 ;
int V_22 ;
V_22 = F_10 ( V_23 , L_6 , & V_21 ) ;
if ( V_22 ) {
if ( V_22 == - V_24 || V_22 == - V_25 )
F_13 ( L_7 ) ;
return;
}
if ( V_21 )
F_14 ( V_26 ) ;
else
F_15 ( V_26 ) ;
F_16 ( L_8 , V_21 ? L_9 : L_10 ) ;
}
int F_17 ( struct V_1 * V_27 ,
unsigned char V_28 , unsigned char V_29 ,
struct V_30 * V_31 , T_2 * V_32 )
{
struct V_33 * V_34 ;
struct V_10 * V_11 ;
struct V_10 * V_12 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
char V_39 [ 4 ] ;
int V_40 ;
if ( V_32 )
* V_32 = ( T_2 ) V_41 ;
V_12 = F_18 ( sizeof( * V_12 ) , V_42 ) ;
if ( ! V_12 )
return - V_43 ;
F_16 ( L_11 , V_27 ) ;
V_40 = F_8 ( V_27 , V_12 ) ;
if ( V_40 ) {
V_12 -> V_13 = V_28 ;
V_12 -> V_14 = V_29 ;
V_12 -> V_15 = V_16 ;
F_16 ( L_12 ,
V_27 , V_12 ) ;
} else {
if ( V_12 -> V_14 > V_12 -> V_13 + V_29 )
V_12 -> V_14 = V_12 -> V_13 + V_29 ;
}
F_19 ( V_31 , V_12 ) ;
V_40 = F_20 ( & V_38 , V_27 ) ;
if ( V_40 )
goto V_44;
F_21 ( L_13 ) ;
F_22 (&parser, &range) {
if ( ( V_36 . V_15 & V_45 ) == V_46 )
snprintf ( V_39 , 4 , L_14 ) ;
else if ( ( V_36 . V_15 & V_45 ) == V_47 )
snprintf ( V_39 , 4 , L_15 ) ;
else
snprintf ( V_39 , 4 , L_16 ) ;
F_16 ( L_17 , V_39 ,
V_36 . V_48 , V_36 . V_48 + V_36 . V_49 - 1 ,
V_36 . V_50 ) ;
if ( V_36 . V_48 == V_41 || V_36 . V_49 == 0 )
continue;
V_11 = F_18 ( sizeof( struct V_10 ) , V_42 ) ;
if ( ! V_11 ) {
V_40 = - V_43 ;
goto V_44;
}
V_40 = F_23 ( & V_36 , V_27 , V_11 ) ;
if ( V_40 ) {
F_24 ( V_11 ) ;
continue;
}
if ( F_25 ( V_11 ) == V_46 ) {
if ( ! V_32 ) {
F_26 ( L_18 ,
V_27 ) ;
V_40 = - V_20 ;
goto V_51;
}
if ( * V_32 != ( T_2 ) V_41 )
F_13 ( L_19 ,
V_27 ) ;
* V_32 = V_36 . V_48 ;
}
F_27 ( V_31 , V_11 , V_11 -> V_13 - V_36 . V_50 ) ;
}
return 0 ;
V_51:
F_24 ( V_11 ) ;
V_44:
F_28 (window, resources)
F_24 ( V_34 -> V_11 ) ;
F_29 ( V_31 ) ;
return V_40 ;
}
int F_30 ( struct V_1 * V_8 , T_1 V_52 ,
const char * V_53 , const char * V_54 ,
struct V_1 * * V_55 , T_1 * V_56 )
{
T_1 V_57 , V_58 ;
int V_59 ;
const T_3 * V_60 = NULL ;
if ( ! V_8 || ! V_53 || ( ! V_55 && ! V_56 ) )
return - V_20 ;
V_60 = F_31 ( V_8 , V_53 , & V_59 ) ;
if ( ! V_60 ) {
if ( V_55 )
return - V_61 ;
* V_56 = V_52 ;
return 0 ;
}
if ( ! V_59 || V_59 % ( 4 * sizeof( * V_60 ) ) ) {
F_26 ( L_20 , V_8 ,
V_53 , V_59 ) ;
return - V_20 ;
}
V_57 = 0xffffffff ;
if ( V_54 )
F_10 ( V_8 , V_54 , & V_57 ) ;
V_58 = V_57 & V_52 ;
for ( ; V_59 > 0 ; V_59 -= 4 * sizeof( * V_60 ) , V_60 += 4 ) {
struct V_1 * V_62 ;
T_1 V_63 = F_32 ( V_60 + 0 ) ;
T_1 V_64 = F_32 ( V_60 + 1 ) ;
T_1 V_65 = F_32 ( V_60 + 2 ) ;
T_1 V_66 = F_32 ( V_60 + 3 ) ;
if ( V_63 & ~ V_57 ) {
F_26 ( L_21 ,
V_8 , V_53 , V_53 ,
V_57 , V_63 ) ;
return - V_67 ;
}
if ( V_58 < V_63 || V_58 >= V_63 + V_66 )
continue;
V_62 = F_33 ( V_64 ) ;
if ( ! V_62 )
return - V_61 ;
if ( V_55 ) {
if ( * V_55 )
F_5 ( V_62 ) ;
else
* V_55 = V_62 ;
if ( * V_55 != V_62 )
continue;
}
if ( V_56 )
* V_56 = V_58 - V_63 + V_65 ;
F_21 ( L_22 ,
V_8 , V_53 , V_57 , V_63 , V_65 ,
V_66 , V_52 , * V_56 ) ;
return 0 ;
}
F_26 ( L_23 ,
V_8 , V_53 , V_52 , V_55 && * V_55 ? * V_55 : NULL ) ;
return - V_67 ;
}
