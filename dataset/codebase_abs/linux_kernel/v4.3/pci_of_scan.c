static T_1 F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
const T_2 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 && V_6 >= 4 )
return F_3 ( V_5 , 1 ) ;
return V_4 ;
}
static unsigned int F_4 ( T_1 V_7 , int V_8 )
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
static void F_5 ( struct V_1 * V_20 , struct V_21 * V_22 )
{
T_3 V_23 , V_24 ;
unsigned int V_9 ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
const T_2 * V_29 ;
T_1 V_30 ;
int V_31 ;
V_29 = F_2 ( V_20 , L_1 , & V_31 ) ;
if ( ! V_29 )
return;
F_6 ( L_2 , V_31 , V_29 ) ;
for (; V_31 >= 20 ; V_31 -= 20 , V_29 += 5 ) {
V_9 = F_4 ( F_3 ( V_29 , 1 ) , 0 ) ;
if ( ! V_9 )
continue;
V_23 = F_3 ( & V_29 [ 1 ] , 2 ) ;
V_24 = F_3 ( & V_29 [ 3 ] , 2 ) ;
if ( ! V_24 )
continue;
V_30 = F_3 ( V_29 , 1 ) & 0xff ;
F_6 ( L_3 ,
( unsigned long long ) V_23 ,
( unsigned long long ) V_24 , V_30 ) ;
if ( V_32 <= V_30 && V_30 <= V_33 ) {
V_28 = & V_22 -> V_27 [ ( V_30 - V_32 ) >> 2 ] ;
} else if ( V_30 == V_22 -> V_34 ) {
V_28 = & V_22 -> V_27 [ V_35 ] ;
V_9 |= V_16 ;
} else {
F_7 ( V_36 L_4 , V_30 ) ;
continue;
}
V_28 -> V_9 = V_9 ;
V_28 -> V_3 = F_8 ( V_22 ) ;
V_26 . V_37 = V_23 ;
V_26 . V_38 = V_23 + V_24 - 1 ;
F_9 ( V_22 -> V_39 , V_28 , & V_26 ) ;
}
}
struct V_21 * F_10 ( struct V_1 * V_20 ,
struct V_40 * V_39 , int V_41 )
{
struct V_21 * V_22 ;
const char * type ;
V_22 = F_11 ( V_39 ) ;
if ( ! V_22 )
return NULL ;
type = F_2 ( V_20 , L_5 , NULL ) ;
if ( type == NULL )
type = L_6 ;
F_6 ( L_7 , V_41 , type ) ;
V_22 -> V_22 . V_42 = F_12 ( V_20 ) ;
V_22 -> V_22 . V_43 = V_39 -> V_8 ;
V_22 -> V_22 . V_39 = & V_44 ;
V_22 -> V_41 = V_41 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
F_13 ( V_22 ) ;
F_14 ( V_22 ) ;
V_22 -> V_47 = F_1 ( V_20 , L_8 , 0xffff ) ;
V_22 -> V_48 = F_1 ( V_20 , L_9 , 0xffff ) ;
V_22 -> V_49 = F_1 ( V_20 , L_10 , 0 ) ;
V_22 -> V_50 = F_1 ( V_20 , L_11 , 0 ) ;
V_22 -> V_51 = F_15 ( V_22 ) ;
F_16 ( & V_22 -> V_22 , L_12 , F_17 ( V_39 ) ,
V_22 -> V_39 -> V_52 , F_18 ( V_41 ) , F_19 ( V_41 ) ) ;
V_22 -> V_53 = F_1 ( V_20 , L_13 , 0 ) ;
V_22 -> V_54 = F_1 ( V_20 , L_14 , 0 ) ;
F_6 ( L_15 , V_22 -> V_53 ) ;
F_6 ( L_16 , V_22 -> V_54 ) ;
V_22 -> V_55 = V_56 ;
V_22 -> V_57 = V_58 ;
V_22 -> V_59 = 0xffffffff ;
F_20 ( V_60 , V_22 ) ;
if ( ! strcmp ( type , L_17 ) || ! strcmp ( type , L_18 ) ) {
V_22 -> V_61 = V_62 ;
V_22 -> V_34 = V_63 ;
F_21 ( V_22 ) ;
} else if ( ! strcmp ( type , L_19 ) ) {
V_22 -> V_61 = V_64 ;
} else {
V_22 -> V_61 = V_65 ;
V_22 -> V_34 = V_66 ;
V_22 -> V_67 = V_68 ;
}
F_5 ( V_20 , V_22 ) ;
F_6 ( L_20 ) ;
F_22 ( V_22 , V_39 ) ;
F_23 ( V_22 ) ;
return V_22 ;
}
void F_24 ( struct V_21 * V_22 )
{
struct V_1 * V_20 = V_22 -> V_22 . V_42 ;
struct V_40 * V_39 ;
struct V_69 * V_70 ;
const T_2 * V_71 , * V_72 ;
int V_6 , V_30 , V_73 ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
unsigned int V_9 ;
T_3 V_24 ;
F_6 ( L_21 , V_20 -> V_74 ) ;
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
V_39 = F_25 ( F_17 ( V_22 -> V_39 ) ,
F_3 ( V_71 , 1 ) ) ;
if ( ! V_39 ) {
V_39 = F_26 ( V_22 -> V_39 , V_22 ,
F_3 ( V_71 , 1 ) ) ;
if ( ! V_39 ) {
F_7 ( V_36 L_26 ,
V_20 -> V_74 ) ;
return;
}
}
V_39 -> V_76 = V_22 -> V_39 -> V_52 ;
F_27 ( V_39 , F_3 ( V_71 , 1 ) ,
F_3 ( V_71 + 1 , 1 ) ) ;
V_39 -> V_77 = 0 ;
V_28 = & V_22 -> V_27 [ V_78 ] ;
for ( V_30 = 0 ; V_30 < V_79 - V_78 ; ++ V_30 ) {
V_28 -> V_9 = 0 ;
V_39 -> V_27 [ V_30 ] = V_28 ;
++ V_28 ;
}
V_30 = 1 ;
for (; V_6 >= 32 ; V_6 -= 32 , V_72 += 8 ) {
V_9 = F_4 ( F_3 ( V_72 , 1 ) , 1 ) ;
V_24 = F_3 ( & V_72 [ 6 ] , 2 ) ;
if ( V_9 == 0 || V_24 == 0 )
continue;
if ( V_9 & V_17 ) {
V_28 = V_39 -> V_27 [ 0 ] ;
if ( V_28 -> V_9 ) {
F_7 ( V_36 L_27
L_28 , V_20 -> V_74 ) ;
continue;
}
} else {
if ( V_30 >= V_79 - V_78 ) {
F_7 ( V_36 L_29
L_28 , V_20 -> V_74 ) ;
continue;
}
V_28 = V_39 -> V_27 [ V_30 ] ;
++ V_30 ;
}
V_28 -> V_9 = V_9 ;
V_26 . V_37 = F_3 ( & V_72 [ 1 ] , 2 ) ;
V_26 . V_38 = V_26 . V_37 + V_24 - 1 ;
F_9 ( V_22 -> V_39 , V_28 , & V_26 ) ;
}
sprintf ( V_39 -> V_3 , L_30 , F_17 ( V_39 ) ,
V_39 -> V_52 ) ;
F_6 ( L_31 , V_39 -> V_3 ) ;
V_70 = F_28 ( V_39 ) ;
V_73 = V_80 ;
if ( V_70 -> V_81 . V_82 )
V_73 = V_70 -> V_81 . V_82 ( V_39 ) ;
F_6 ( L_32 , V_73 ) ;
if ( V_73 == V_83 )
F_29 ( V_20 , V_39 ) ;
else if ( V_73 == V_80 )
F_30 ( V_39 ) ;
}
static struct V_21 * F_31 ( struct V_40 * V_39 ,
struct V_1 * V_84 )
{
struct V_21 * V_22 = NULL ;
const T_2 * V_85 ;
int V_86 , V_41 ;
#ifdef F_32
struct V_87 * V_88 = F_33 ( F_34 ( V_84 ) ) ;
#endif
F_6 ( L_33 , V_84 -> V_74 ) ;
if ( ! F_35 ( V_84 ) )
return NULL ;
V_85 = F_2 ( V_84 , L_34 , & V_86 ) ;
if ( V_85 == NULL || V_86 < 20 )
return NULL ;
V_41 = ( F_3 ( V_85 , 1 ) >> 8 ) & 0xff ;
V_22 = F_36 ( V_39 , V_41 ) ;
if ( V_22 ) {
F_37 ( V_22 ) ;
return V_22 ;
}
#ifdef F_32
if ( V_88 && ( V_88 -> V_73 & V_89 ) )
return NULL ;
#endif
V_22 = F_10 ( V_84 , V_39 , V_41 ) ;
if ( ! V_22 )
return NULL ;
F_6 ( L_35 , V_22 -> V_61 ) ;
return V_22 ;
}
static void F_38 ( struct V_1 * V_20 , struct V_40 * V_39 ,
int V_90 )
{
struct V_1 * V_91 ;
struct V_21 * V_22 ;
F_6 ( L_36 ,
V_20 -> V_74 , V_39 -> V_52 ) ;
F_39 (node, child) {
V_22 = F_31 ( V_39 , V_91 ) ;
if ( ! V_22 )
continue;
F_6 ( L_37 , V_22 -> V_61 ) ;
}
if ( ! V_90 )
F_40 ( V_39 ) ;
F_41 ( V_39 ) ;
F_42 (dev, &bus->devices, bus_list) {
if ( F_43 ( V_22 ) ) {
F_24 ( V_22 ) ;
}
}
}
void F_29 ( struct V_1 * V_20 , struct V_40 * V_39 )
{
F_38 ( V_20 , V_39 , 0 ) ;
}
void F_44 ( struct V_1 * V_20 , struct V_40 * V_39 )
{
F_38 ( V_20 , V_39 , 1 ) ;
}
