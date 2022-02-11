static T_1 F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
const T_1 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 && V_6 >= 4 )
return * V_5 ;
return V_4 ;
}
unsigned int F_3 ( T_1 V_7 , int V_8 )
{
unsigned int V_9 = 0 ;
if ( V_7 & 0x02000000 ) {
V_9 = V_10 | V_11 ;
V_9 |= ( V_7 >> 22 ) & V_12 ;
V_9 |= ( V_7 >> 28 ) & V_13 ;
if ( V_7 & 0x40000000 )
V_9 |= V_14
| V_15 ;
if ( ! V_8 && ( V_7 & 0xff ) == 0x30 )
V_9 |= V_16 ;
} else if ( V_7 & 0x01000000 )
V_9 = V_17 | V_18 ;
if ( V_9 )
V_9 |= V_19 ;
return V_9 ;
}
static void F_4 ( struct V_1 * V_20 , struct V_21 * V_22 )
{
T_2 V_23 , V_24 ;
unsigned int V_9 ;
struct V_25 * V_26 ;
const T_1 * V_27 ;
T_1 V_28 ;
int V_29 ;
V_27 = F_2 ( V_20 , L_1 , & V_29 ) ;
if ( ! V_27 )
return;
F_5 ( L_2 , V_29 , V_27 ) ;
for (; V_29 >= 20 ; V_29 -= 20 , V_27 += 5 ) {
V_9 = F_3 ( V_27 [ 0 ] , 0 ) ;
if ( ! V_9 )
continue;
V_23 = F_6 ( & V_27 [ 1 ] , 2 ) ;
V_24 = F_6 ( & V_27 [ 3 ] , 2 ) ;
if ( ! V_24 )
continue;
V_28 = V_27 [ 0 ] & 0xff ;
F_5 ( L_3 ,
( unsigned long long ) V_23 ,
( unsigned long long ) V_24 , V_28 ) ;
if ( V_30 <= V_28 && V_28 <= V_31 ) {
V_26 = & V_22 -> V_25 [ ( V_28 - V_30 ) >> 2 ] ;
} else if ( V_28 == V_22 -> V_32 ) {
V_26 = & V_22 -> V_25 [ V_33 ] ;
V_9 |= V_16 | V_34 ;
} else {
F_7 ( V_35 L_4 , V_28 ) ;
continue;
}
V_26 -> V_36 = V_23 ;
V_26 -> V_37 = V_23 + V_24 - 1 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_3 = F_8 ( V_22 ) ;
}
}
struct V_21 * F_9 ( struct V_1 * V_20 ,
struct V_38 * V_39 , int V_40 )
{
struct V_21 * V_22 ;
const char * type ;
struct V_41 * V_42 ;
V_22 = F_10 () ;
if ( ! V_22 )
return NULL ;
type = F_2 ( V_20 , L_5 , NULL ) ;
if ( type == NULL )
type = L_6 ;
F_5 ( L_7 , V_40 , type ) ;
V_22 -> V_39 = V_39 ;
V_22 -> V_22 . V_43 = F_11 ( V_20 ) ;
V_22 -> V_22 . V_44 = V_39 -> V_8 ;
V_22 -> V_22 . V_39 = & V_45 ;
V_22 -> V_40 = V_40 ;
V_22 -> V_46 = 0 ;
V_22 -> V_47 = 0 ;
F_12 ( V_22 ) ;
F_13 (slot, &dev->bus->slots, list)
if ( F_14 ( V_22 -> V_40 ) == V_42 -> V_48 )
V_22 -> V_42 = V_42 ;
V_22 -> V_49 = F_1 ( V_20 , L_8 , 0xffff ) ;
V_22 -> V_50 = F_1 ( V_20 , L_9 , 0xffff ) ;
V_22 -> V_51 = F_1 ( V_20 , L_10 , 0 ) ;
V_22 -> V_52 = F_1 ( V_20 , L_11 , 0 ) ;
V_22 -> V_53 = F_15 ( V_22 ) ;
F_16 ( & V_22 -> V_22 , L_12 , F_17 ( V_39 ) ,
V_22 -> V_39 -> V_48 , F_14 ( V_40 ) , F_18 ( V_40 ) ) ;
V_22 -> V_54 = F_1 ( V_20 , L_13 , 0 ) ;
V_22 -> V_55 = F_1 ( V_20 , L_14 , 0 ) ;
F_5 ( L_15 , V_22 -> V_54 ) ;
F_5 ( L_16 , V_22 -> V_55 ) ;
V_22 -> V_56 = 4 ;
V_22 -> V_57 = V_58 ;
V_22 -> V_59 = 0xffffffff ;
F_19 ( V_60 , V_22 ) ;
if ( ! strcmp ( type , L_17 ) || ! strcmp ( type , L_18 ) ) {
V_22 -> V_61 = V_62 ;
V_22 -> V_32 = V_63 ;
F_20 ( V_22 ) ;
} else if ( ! strcmp ( type , L_19 ) ) {
V_22 -> V_61 = V_64 ;
} else {
V_22 -> V_61 = V_65 ;
V_22 -> V_32 = V_66 ;
V_22 -> V_67 = V_68 ;
}
F_4 ( V_20 , V_22 ) ;
F_5 ( L_20 ) ;
F_21 ( V_22 , V_39 ) ;
return V_22 ;
}
void T_3 F_22 ( struct V_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_38 * V_39 ;
const T_1 * V_69 , * V_70 ;
int V_6 , V_28 , V_71 ;
struct V_25 * V_26 ;
unsigned int V_9 ;
T_2 V_24 ;
F_5 ( L_21 , V_20 -> V_72 ) ;
V_69 = F_2 ( V_20 , L_22 , & V_6 ) ;
if ( V_69 == NULL || V_6 != 8 ) {
F_7 ( V_73 L_23 ,
V_20 -> V_72 ) ;
return;
}
V_70 = F_2 ( V_20 , L_24 , & V_6 ) ;
if ( V_70 == NULL ) {
F_7 ( V_73 L_25 ,
V_20 -> V_72 ) ;
return;
}
V_39 = F_23 ( V_22 -> V_39 , V_22 , V_69 [ 0 ] ) ;
if ( ! V_39 ) {
F_7 ( V_35 L_26 ,
V_20 -> V_72 ) ;
return;
}
V_39 -> V_74 = V_22 -> V_39 -> V_48 ;
V_39 -> V_75 = V_69 [ 1 ] ;
V_39 -> V_76 = 0 ;
V_39 -> V_22 . V_43 = F_11 ( V_20 ) ;
V_26 = & V_22 -> V_25 [ V_77 ] ;
for ( V_28 = 0 ; V_28 < V_78 - V_77 ; ++ V_28 ) {
V_26 -> V_9 = 0 ;
V_39 -> V_25 [ V_28 ] = V_26 ;
++ V_26 ;
}
V_28 = 1 ;
for (; V_6 >= 32 ; V_6 -= 32 , V_70 += 8 ) {
V_9 = F_3 ( V_70 [ 0 ] , 1 ) ;
V_24 = F_6 ( & V_70 [ 6 ] , 2 ) ;
if ( V_9 == 0 || V_24 == 0 )
continue;
if ( V_9 & V_17 ) {
V_26 = V_39 -> V_25 [ 0 ] ;
if ( V_26 -> V_9 ) {
F_7 ( V_35 L_27
L_28 , V_20 -> V_72 ) ;
continue;
}
} else {
if ( V_28 >= V_78 - V_77 ) {
F_7 ( V_35 L_29
L_28 , V_20 -> V_72 ) ;
continue;
}
V_26 = V_39 -> V_25 [ V_28 ] ;
++ V_28 ;
}
V_26 -> V_36 = F_6 ( & V_70 [ 1 ] , 2 ) ;
V_26 -> V_37 = V_26 -> V_36 + V_24 - 1 ;
V_26 -> V_9 = V_9 ;
}
sprintf ( V_39 -> V_3 , L_30 , F_17 ( V_39 ) ,
V_39 -> V_48 ) ;
F_5 ( L_31 , V_39 -> V_3 ) ;
V_71 = V_79 ;
if ( V_80 . V_81 )
V_71 = V_80 . V_81 ( V_39 ) ;
F_5 ( L_32 , V_71 ) ;
if ( V_71 == V_82 )
F_24 ( V_20 , V_39 ) ;
else if ( V_71 == V_79 )
F_25 ( V_39 ) ;
}
static void T_3 F_26 ( struct V_1 * V_20 ,
struct V_38 * V_39 , int V_83 )
{
struct V_1 * V_84 ;
const T_1 * V_85 ;
int V_86 , V_40 ;
struct V_21 * V_22 ;
F_5 ( L_33 ,
V_20 -> V_72 , V_39 -> V_48 ) ;
F_27 (node, child) {
F_5 ( L_34 , V_84 -> V_72 ) ;
if ( ! F_28 ( V_84 ) )
continue;
V_85 = F_2 ( V_84 , L_35 , & V_86 ) ;
if ( V_85 == NULL || V_86 < 20 )
continue;
V_40 = ( V_85 [ 0 ] >> 8 ) & 0xff ;
V_22 = F_9 ( V_84 , V_39 , V_40 ) ;
if ( ! V_22 )
continue;
F_5 ( L_36 , V_22 -> V_61 ) ;
}
if ( ! V_83 )
F_29 ( V_39 ) ;
F_30 ( V_39 ) ;
F_13 (dev, &bus->devices, bus_list) {
if ( V_22 -> V_61 == V_62 ||
V_22 -> V_61 == V_64 ) {
struct V_1 * V_84 = F_31 ( V_22 ) ;
if ( V_84 )
F_22 ( V_84 , V_22 ) ;
}
}
}
void T_3 F_24 ( struct V_1 * V_20 ,
struct V_38 * V_39 )
{
F_26 ( V_20 , V_39 , 0 ) ;
}
void T_3 F_32 ( struct V_1 * V_20 ,
struct V_38 * V_39 )
{
F_26 ( V_20 , V_39 , 1 ) ;
}
