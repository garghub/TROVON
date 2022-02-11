static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , V_3 ) ;
if ( ! F_3 ( & V_5 -> V_7 , 1 , 1 ) )
return - V_8 ;
V_2 -> V_9 [ V_3 ] = ( void * ) 0xdeadcafe ;
return 0 ;
}
static void
F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , V_3 ) ;
F_5 ( & V_5 -> V_7 ) ;
V_2 -> V_9 [ V_3 ] = NULL ;
}
static int
F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_14 * V_15 = NULL ;
unsigned long V_16 ;
int V_17 ;
F_7 ( V_6 , L_1 , V_2 -> V_18 ) ;
V_17 = F_8 ( V_6 , NULL , 264 * 4 , 16 , V_19 |
V_20 , & V_15 ) ;
if ( V_17 )
return V_17 ;
F_9 ( V_15 , 0x78 , 0x02001ec1 ) ;
F_10 ( & V_12 -> V_21 , V_16 ) ;
F_11 ( V_6 , 0x002500 , 0x00000001 , 0x00000000 ) ;
if ( ( F_12 ( V_6 , 0x003204 ) & 0x1f ) == V_2 -> V_18 )
F_13 ( V_6 , 0x00330c , V_15 -> V_22 >> 4 ) ;
F_9 ( V_2 -> V_23 , 0x54 , V_15 -> V_22 >> 4 ) ;
F_11 ( V_6 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_14 ( & V_12 -> V_21 , V_16 ) ;
V_2 -> V_9 [ V_3 ] = V_15 ;
return 0 ;
}
static void
F_15 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_12 = V_2 -> V_6 -> V_13 ;
struct V_14 * V_15 = V_2 -> V_9 [ V_3 ] ;
struct V_10 * V_6 = V_2 -> V_6 ;
unsigned long V_16 ;
T_1 V_24 = 0x80000000 | ( V_15 -> V_22 >> 4 ) ;
F_10 ( & V_12 -> V_21 , V_16 ) ;
F_11 ( V_6 , 0x00b32c , 0x00000001 , 0x00000000 ) ;
if ( F_12 ( V_6 , 0x00b318 ) == V_24 )
F_11 ( V_6 , 0x00b318 , 0x80000000 , 0x00000000 ) ;
F_11 ( V_6 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_14 ( & V_12 -> V_21 , V_16 ) ;
F_16 ( NULL , & V_15 ) ;
V_2 -> V_9 [ V_3 ] = NULL ;
}
static int
F_17 ( struct V_1 * V_2 , int V_3 ,
T_1 V_25 , T_2 V_26 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
struct V_14 * V_27 = NULL ;
int V_17 ;
V_17 = F_8 ( V_6 , V_2 , 20 , 16 , V_19 |
V_20 , & V_27 ) ;
if ( V_17 )
return V_17 ;
V_27 -> V_3 = 2 ;
V_27 -> V_26 = V_26 ;
F_9 ( V_27 , 0x00 , V_26 ) ;
V_17 = F_18 ( V_2 , V_25 , V_27 ) ;
F_16 ( NULL , & V_27 ) ;
return V_17 ;
}
static int
F_19 ( struct V_10 * V_6 , int V_3 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_4 * V_5 = F_2 ( V_6 , V_3 ) ;
int V_28 ;
F_11 ( V_6 , 0x000200 , 0x00000002 , 0x00000000 ) ;
F_11 ( V_6 , 0x000200 , 0x00000002 , 0x00000002 ) ;
F_13 ( V_6 , 0x00b0e0 , 0x00000020 ) ;
F_13 ( V_6 , 0x00b0e8 , 0x00000020 ) ;
for ( V_28 = 0 ; V_28 < V_12 -> V_3 . V_29 . V_30 ; V_28 ++ )
V_5 -> V_31 . V_32 ( V_6 , V_28 ) ;
F_13 ( V_6 , 0x00b32c , 0x00000000 ) ;
F_13 ( V_6 , 0x00b314 , 0x00000100 ) ;
F_13 ( V_6 , 0x00b220 , F_20 ( V_6 ) ? 0x00000044 : 0x00000031 ) ;
F_13 ( V_6 , 0x00b300 , 0x02001ec1 ) ;
F_11 ( V_6 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_13 ( V_6 , 0x00b100 , 0xffffffff ) ;
F_13 ( V_6 , 0x00b140 , 0xffffffff ) ;
if ( ! F_21 ( V_6 , 0x00b200 , 0x00000001 , 0x00000000 ) ) {
F_22 ( V_6 , L_2 , F_12 ( V_6 , 0x00b200 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int
F_23 ( struct V_10 * V_6 , int V_3 , bool V_33 )
{
F_11 ( V_6 , 0x00b32c , 0x00000001 , 0x00000000 ) ;
F_13 ( V_6 , 0x00b140 , 0x00000000 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_34 , T_1 V_35 )
{
struct V_10 * V_6 = V_2 -> V_6 ;
T_1 V_24 = V_35 << 4 ;
T_1 V_36 = F_25 ( V_6 , V_24 + 0 ) ;
T_1 V_37 = F_25 ( V_6 , V_24 + 4 ) ;
T_1 V_38 = F_25 ( V_6 , V_24 + 8 ) ;
T_1 V_31 = ( V_38 & 0xfffff000 ) | ( V_36 >> 20 ) ;
T_1 V_39 = V_37 + 1 ;
if ( ! ( V_36 & 0x00002000 ) )
return - V_40 ;
if ( V_34 == 0x0190 ) {
F_11 ( V_6 , 0x00b300 , 0x00030000 , ( V_36 & 0x00030000 ) ) ;
F_13 ( V_6 , 0x00b334 , V_31 ) ;
F_13 ( V_6 , 0x00b324 , V_39 ) ;
} else
if ( V_34 == 0x01a0 ) {
F_11 ( V_6 , 0x00b300 , 0x000c0000 , ( V_36 & 0x00030000 ) << 2 ) ;
F_13 ( V_6 , 0x00b360 , V_31 ) ;
F_13 ( V_6 , 0x00b364 , V_39 ) ;
} else {
if ( V_36 & 0x000c0000 )
return - V_40 ;
F_13 ( V_6 , 0x00b370 , V_31 ) ;
F_13 ( V_6 , 0x00b374 , V_39 ) ;
}
return 0 ;
}
static int
F_26 ( struct V_10 * V_6 , T_1 V_24 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_14 * V_15 ;
unsigned long V_16 ;
int V_28 ;
if ( V_12 -> V_41 < V_42 )
return 0 ;
F_10 ( & V_12 -> V_43 . V_44 , V_16 ) ;
for ( V_28 = 0 ; V_28 < V_12 -> V_3 . V_45 . V_43 ; V_28 ++ ) {
if ( ! V_12 -> V_43 . V_46 [ V_28 ] )
continue;
V_15 = V_12 -> V_43 . V_46 [ V_28 ] -> V_9 [ V_47 ] ;
if ( V_15 && V_15 -> V_22 == V_24 )
break;
}
F_14 ( & V_12 -> V_43 . V_44 , V_16 ) ;
return V_28 ;
}
static void
F_27 ( struct V_10 * V_6 , int V_28 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_48 * V_49 = & V_12 -> V_49 . V_50 [ V_28 ] ;
F_13 ( V_6 , 0x00b008 + ( V_28 * 0x10 ) , V_49 -> V_51 ) ;
F_13 ( V_6 , 0x00b004 + ( V_28 * 0x10 ) , V_49 -> V_52 ) ;
F_13 ( V_6 , 0x00b000 + ( V_28 * 0x10 ) , V_49 -> V_53 ) ;
}
static void
F_28 ( struct V_10 * V_6 )
{
T_1 V_24 = ( F_12 ( V_6 , 0x00b318 ) & 0x000fffff ) << 4 ;
T_1 V_54 = F_26 ( V_6 , V_24 ) ;
T_1 V_55 = F_12 ( V_6 , 0x00b100 ) ;
T_1 type = F_12 ( V_6 , 0x00b230 ) ;
T_1 V_34 = F_12 ( V_6 , 0x00b234 ) ;
T_1 V_35 = F_12 ( V_6 , 0x00b238 ) ;
T_1 V_56 = V_55 ;
if ( V_55 & 0x01000000 ) {
if ( type == 0x00000020 && V_34 == 0x0000 ) {
F_11 ( V_6 , 0x00b308 , 0x00000000 , 0x00000000 ) ;
V_56 &= ~ 0x01000000 ;
}
if ( type == 0x00000010 ) {
if ( ! F_29 ( V_6 , V_54 , 0x3174 , V_34 , V_35 ) )
V_56 &= ~ 0x01000000 ;
}
}
F_13 ( V_6 , 0x00b100 , V_55 ) ;
F_13 ( V_6 , 0x00b230 , 0x00000001 ) ;
if ( V_56 && F_30 () ) {
F_31 ( V_6 , L_3 ,
V_54 , V_24 , V_55 , type , V_34 , V_35 ) ;
}
}
static void
F_32 ( struct V_10 * V_6 )
{
if ( F_12 ( V_6 , 0x00b100 ) )
F_28 ( V_6 ) ;
if ( F_12 ( V_6 , 0x00b800 ) ) {
T_1 V_55 = F_12 ( V_6 , 0x00b800 ) ;
F_31 ( V_6 , L_4 , V_55 ) ;
F_13 ( V_6 , 0xb800 , V_55 ) ;
}
}
static void
F_33 ( struct V_10 * V_6 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_6 , V_3 ) ;
F_34 ( V_6 , 0 ) ;
F_35 ( V_6 , V_57 ) ;
F_36 ( V_5 ) ;
}
int
F_37 ( struct V_10 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_4 * V_5 ;
V_5 = F_38 ( sizeof( * V_5 ) , V_58 ) ;
if ( ! V_5 )
return - V_59 ;
F_39 ( & V_5 -> V_7 , 0 ) ;
V_5 -> V_31 . V_60 = F_33 ;
V_5 -> V_31 . V_61 = F_19 ;
V_5 -> V_31 . V_62 = F_23 ;
if ( V_12 -> V_41 < V_42 ) {
V_5 -> V_31 . V_63 = F_1 ;
V_5 -> V_31 . V_64 = F_4 ;
} else {
V_5 -> V_31 . V_63 = F_6 ;
V_5 -> V_31 . V_64 = F_15 ;
}
V_5 -> V_31 . V_65 = F_17 ;
V_5 -> V_31 . V_32 = F_27 ;
F_40 ( V_6 , 0 , F_32 ) ;
F_41 ( V_6 , V_57 , & V_5 -> V_31 ) ;
F_42 ( V_6 , 0x3174 , V_57 ) ;
F_43 ( V_6 , 0x3174 , 0x0190 , F_24 ) ;
F_43 ( V_6 , 0x3174 , 0x01a0 , F_24 ) ;
F_43 ( V_6 , 0x3174 , 0x01b0 , F_24 ) ;
#if 0
NVOBJ_ENGINE_ADD(dev, ME, &pme->base);
NVOBJ_CLASS(dev, 0x4075, ME);
#endif
return 0 ;
}
