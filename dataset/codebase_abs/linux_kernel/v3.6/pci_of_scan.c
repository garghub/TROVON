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
struct V_25 V_26 ;
struct V_27 * V_28 ;
const T_1 * V_29 ;
T_1 V_30 ;
int V_31 ;
V_29 = F_2 ( V_20 , L_1 , & V_31 ) ;
if ( ! V_29 )
return;
F_5 ( L_2 , V_31 , V_29 ) ;
for (; V_31 >= 20 ; V_31 -= 20 , V_29 += 5 ) {
V_9 = F_3 ( V_29 [ 0 ] , 0 ) ;
if ( ! V_9 )
continue;
V_23 = F_6 ( & V_29 [ 1 ] , 2 ) ;
V_24 = F_6 ( & V_29 [ 3 ] , 2 ) ;
if ( ! V_24 )
continue;
V_30 = V_29 [ 0 ] & 0xff ;
F_5 ( L_3 ,
( unsigned long long ) V_23 ,
( unsigned long long ) V_24 , V_30 ) ;
if ( V_32 <= V_30 && V_30 <= V_33 ) {
V_28 = & V_22 -> V_27 [ ( V_30 - V_32 ) >> 2 ] ;
} else if ( V_30 == V_22 -> V_34 ) {
V_28 = & V_22 -> V_27 [ V_35 ] ;
V_9 |= V_16 | V_36 ;
} else {
F_7 ( V_37 L_4 , V_30 ) ;
continue;
}
V_28 -> V_9 = V_9 ;
V_28 -> V_3 = F_8 ( V_22 ) ;
V_26 . V_38 = V_23 ;
V_26 . V_39 = V_23 + V_24 - 1 ;
F_9 ( V_22 , V_28 , & V_26 ) ;
}
}
struct V_21 * F_10 ( struct V_1 * V_20 ,
struct V_40 * V_41 , int V_42 )
{
struct V_21 * V_22 ;
const char * type ;
struct V_43 * V_44 ;
V_22 = F_11 () ;
if ( ! V_22 )
return NULL ;
type = F_2 ( V_20 , L_5 , NULL ) ;
if ( type == NULL )
type = L_6 ;
F_5 ( L_7 , V_42 , type ) ;
V_22 -> V_41 = V_41 ;
V_22 -> V_22 . V_45 = F_12 ( V_20 ) ;
V_22 -> V_22 . V_46 = V_41 -> V_8 ;
V_22 -> V_22 . V_41 = & V_47 ;
V_22 -> V_42 = V_42 ;
V_22 -> V_48 = 0 ;
V_22 -> V_49 = 0 ;
F_13 ( V_22 ) ;
F_14 (slot, &dev->bus->slots, list)
if ( F_15 ( V_22 -> V_42 ) == V_44 -> V_50 )
V_22 -> V_44 = V_44 ;
V_22 -> V_51 = F_1 ( V_20 , L_8 , 0xffff ) ;
V_22 -> V_52 = F_1 ( V_20 , L_9 , 0xffff ) ;
V_22 -> V_53 = F_1 ( V_20 , L_10 , 0 ) ;
V_22 -> V_54 = F_1 ( V_20 , L_11 , 0 ) ;
V_22 -> V_55 = F_16 ( V_22 ) ;
F_17 ( & V_22 -> V_22 , L_12 , F_18 ( V_41 ) ,
V_22 -> V_41 -> V_50 , F_15 ( V_42 ) , F_19 ( V_42 ) ) ;
V_22 -> V_56 = F_1 ( V_20 , L_13 , 0 ) ;
V_22 -> V_57 = F_1 ( V_20 , L_14 , 0 ) ;
F_5 ( L_15 , V_22 -> V_56 ) ;
F_5 ( L_16 , V_22 -> V_57 ) ;
V_22 -> V_58 = 4 ;
V_22 -> V_59 = V_60 ;
V_22 -> V_61 = 0xffffffff ;
F_20 ( V_62 , V_22 ) ;
if ( ! strcmp ( type , L_17 ) || ! strcmp ( type , L_18 ) ) {
V_22 -> V_63 = V_64 ;
V_22 -> V_34 = V_65 ;
F_21 ( V_22 ) ;
} else if ( ! strcmp ( type , L_19 ) ) {
V_22 -> V_63 = V_66 ;
} else {
V_22 -> V_63 = V_67 ;
V_22 -> V_34 = V_68 ;
V_22 -> V_69 = V_70 ;
}
F_4 ( V_20 , V_22 ) ;
F_5 ( L_20 ) ;
F_22 ( V_22 , V_41 ) ;
return V_22 ;
}
void T_3 F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_20 = V_22 -> V_22 . V_45 ;
struct V_40 * V_41 ;
const T_1 * V_71 , * V_72 ;
int V_6 , V_30 , V_73 ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
unsigned int V_9 ;
T_2 V_24 ;
F_5 ( L_21 , V_20 -> V_74 ) ;
V_71 = F_2 ( V_20 , L_22 , & V_6 ) ;
if ( V_71 == NULL || V_6 != 8 ) {
F_7 ( V_75 L_23 ,
V_20 -> V_74 ) ;
return;
}
V_72 = F_2 ( V_20 , L_24 , & V_6 ) ;
if ( V_72 == NULL ) {
F_7 ( V_75 L_25 ,
V_20 -> V_74 ) ;
return;
}
V_41 = F_24 ( V_22 -> V_41 , V_22 , V_71 [ 0 ] ) ;
if ( ! V_41 ) {
F_7 ( V_37 L_26 ,
V_20 -> V_74 ) ;
return;
}
V_41 -> V_76 = V_22 -> V_41 -> V_50 ;
F_25 ( V_41 , V_71 [ 0 ] , V_71 [ 1 ] ) ;
V_41 -> V_77 = 0 ;
V_28 = & V_22 -> V_27 [ V_78 ] ;
for ( V_30 = 0 ; V_30 < V_79 - V_78 ; ++ V_30 ) {
V_28 -> V_9 = 0 ;
V_41 -> V_27 [ V_30 ] = V_28 ;
++ V_28 ;
}
V_30 = 1 ;
for (; V_6 >= 32 ; V_6 -= 32 , V_72 += 8 ) {
V_9 = F_3 ( V_72 [ 0 ] , 1 ) ;
V_24 = F_6 ( & V_72 [ 6 ] , 2 ) ;
if ( V_9 == 0 || V_24 == 0 )
continue;
if ( V_9 & V_17 ) {
V_28 = V_41 -> V_27 [ 0 ] ;
if ( V_28 -> V_9 ) {
F_7 ( V_37 L_27
L_28 , V_20 -> V_74 ) ;
continue;
}
} else {
if ( V_30 >= V_79 - V_78 ) {
F_7 ( V_37 L_29
L_28 , V_20 -> V_74 ) ;
continue;
}
V_28 = V_41 -> V_27 [ V_30 ] ;
++ V_30 ;
}
V_28 -> V_9 = V_9 ;
V_26 . V_38 = F_6 ( & V_72 [ 1 ] , 2 ) ;
V_26 . V_39 = V_26 . V_38 + V_24 - 1 ;
F_9 ( V_22 , V_28 , & V_26 ) ;
}
sprintf ( V_41 -> V_3 , L_30 , F_18 ( V_41 ) ,
V_41 -> V_50 ) ;
F_5 ( L_31 , V_41 -> V_3 ) ;
V_73 = V_80 ;
if ( V_81 . V_82 )
V_73 = V_81 . V_82 ( V_41 ) ;
F_5 ( L_32 , V_73 ) ;
if ( V_73 == V_83 )
F_26 ( V_20 , V_41 ) ;
else if ( V_73 == V_80 )
F_27 ( V_41 ) ;
}
static void T_3 F_28 ( struct V_1 * V_20 ,
struct V_40 * V_41 , int V_84 )
{
struct V_1 * V_85 ;
const T_1 * V_86 ;
int V_87 , V_42 ;
struct V_21 * V_22 ;
F_5 ( L_33 ,
V_20 -> V_74 , V_41 -> V_50 ) ;
F_29 (node, child) {
F_5 ( L_34 , V_85 -> V_74 ) ;
if ( ! F_30 ( V_85 ) )
continue;
V_86 = F_2 ( V_85 , L_35 , & V_87 ) ;
if ( V_86 == NULL || V_87 < 20 )
continue;
V_42 = ( V_86 [ 0 ] >> 8 ) & 0xff ;
V_22 = F_10 ( V_85 , V_41 , V_42 ) ;
if ( ! V_22 )
continue;
F_5 ( L_36 , V_22 -> V_63 ) ;
}
if ( ! V_84 )
F_31 ( V_41 ) ;
F_32 ( V_41 ) ;
F_14 (dev, &bus->devices, bus_list) {
if ( V_22 -> V_63 == V_64 ||
V_22 -> V_63 == V_66 ) {
F_23 ( V_22 ) ;
}
}
}
void T_3 F_26 ( struct V_1 * V_20 ,
struct V_40 * V_41 )
{
F_28 ( V_20 , V_41 , 0 ) ;
}
void T_3 F_33 ( struct V_1 * V_20 ,
struct V_40 * V_41 )
{
F_28 ( V_20 , V_41 , 1 ) ;
}
