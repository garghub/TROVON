static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = NULL ;
unsigned long V_11 ;
int V_12 ;
F_2 ( V_5 , L_1 , V_2 -> V_13 ) ;
V_12 = F_3 ( V_5 , NULL , 264 * 4 , 16 , V_14 |
V_15 , & V_10 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_10 , 0x78 , 0x02001ec1 ) ;
F_5 ( & V_7 -> V_16 , V_11 ) ;
F_6 ( V_5 , 0x002500 , 0x00000001 , 0x00000000 ) ;
if ( ( F_7 ( V_5 , 0x003204 ) & 0x1f ) == V_2 -> V_13 )
F_8 ( V_5 , 0x00330c , V_10 -> V_17 >> 4 ) ;
F_4 ( V_2 -> V_18 , 0x54 , V_10 -> V_17 >> 4 ) ;
F_6 ( V_5 , 0x002500 , 0x00000001 , 0x00000001 ) ;
F_9 ( & V_7 -> V_16 , V_11 ) ;
V_2 -> V_19 [ V_3 ] = V_10 ;
return 0 ;
}
static void
F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_19 [ V_3 ] ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_11 ;
T_1 V_20 = 0x80000000 | ( V_10 -> V_17 >> 4 ) ;
F_5 ( & V_7 -> V_16 , V_11 ) ;
F_6 ( V_5 , 0x00b32c , 0x00000001 , 0x00000000 ) ;
if ( F_7 ( V_5 , 0x00b318 ) == V_20 )
F_6 ( V_5 , 0x00b318 , 0x80000000 , 0x00000000 ) ;
F_6 ( V_5 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_9 ( & V_7 -> V_16 , V_11 ) ;
F_11 ( NULL , & V_10 ) ;
V_2 -> V_19 [ V_3 ] = NULL ;
}
static int
F_12 ( struct V_1 * V_2 , int V_3 ,
T_1 V_21 , T_2 V_22 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_9 * V_23 = NULL ;
int V_12 ;
V_12 = F_3 ( V_5 , V_2 , 20 , 16 , V_14 |
V_15 , & V_23 ) ;
if ( V_12 )
return V_12 ;
V_23 -> V_3 = 2 ;
V_23 -> V_22 = V_22 ;
F_4 ( V_23 , 0x00 , V_22 ) ;
V_12 = F_13 ( V_2 , V_21 , V_23 ) ;
F_11 ( NULL , & V_23 ) ;
return V_12 ;
}
static int
F_14 ( struct V_4 * V_5 , int V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_24 * V_25 = F_15 ( V_5 , V_3 ) ;
int V_26 ;
F_6 ( V_5 , 0x000200 , 0x00000002 , 0x00000000 ) ;
F_6 ( V_5 , 0x000200 , 0x00000002 , 0x00000002 ) ;
F_8 ( V_5 , 0x00b0e0 , 0x00000020 ) ;
F_8 ( V_5 , 0x00b0e8 , 0x00000020 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_3 . V_27 . V_28 ; V_26 ++ )
V_25 -> V_29 . V_30 ( V_5 , V_26 ) ;
F_8 ( V_5 , 0x00b32c , 0x00000000 ) ;
F_8 ( V_5 , 0x00b314 , 0x00000100 ) ;
F_8 ( V_5 , 0x00b220 , 0x00000044 ) ;
F_8 ( V_5 , 0x00b300 , 0x02001ec1 ) ;
F_6 ( V_5 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_8 ( V_5 , 0x00b100 , 0xffffffff ) ;
F_8 ( V_5 , 0x00b140 , 0xffffffff ) ;
if ( ! F_16 ( V_5 , 0x00b200 , 0x00000001 , 0x00000000 ) ) {
F_17 ( V_5 , L_2 , F_7 ( V_5 , 0x00b200 ) ) ;
return - V_31 ;
}
return 0 ;
}
static int
F_18 ( struct V_4 * V_5 , int V_3 , bool V_32 )
{
F_6 ( V_5 , 0x00b32c , 0x00000001 , 0x00000000 ) ;
F_8 ( V_5 , 0x00b140 , 0x00000000 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_33 , T_1 V_34 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_20 = V_34 << 4 ;
T_1 V_35 = F_20 ( V_5 , V_20 + 0 ) ;
T_1 V_36 = F_20 ( V_5 , V_20 + 4 ) ;
T_1 V_37 = F_20 ( V_5 , V_20 + 8 ) ;
T_1 V_29 = ( V_37 & 0xfffff000 ) | ( V_35 >> 20 ) ;
T_1 V_38 = V_36 + 1 ;
if ( ! ( V_35 & 0x00002000 ) )
return - V_39 ;
if ( V_33 == 0x0190 ) {
F_6 ( V_5 , 0x00b300 , 0x00030000 , ( V_35 & 0x00030000 ) ) ;
F_8 ( V_5 , 0x00b334 , V_29 ) ;
F_8 ( V_5 , 0x00b324 , V_38 ) ;
} else
if ( V_33 == 0x01a0 ) {
F_6 ( V_5 , 0x00b300 , 0x000c0000 , ( V_35 & 0x00030000 ) << 2 ) ;
F_8 ( V_5 , 0x00b360 , V_29 ) ;
F_8 ( V_5 , 0x00b364 , V_38 ) ;
} else {
if ( V_35 & 0x000c0000 )
return - V_39 ;
F_8 ( V_5 , 0x00b370 , V_29 ) ;
F_8 ( V_5 , 0x00b374 , V_38 ) ;
}
return 0 ;
}
static int
F_21 ( struct V_4 * V_5 , T_1 V_20 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
int V_26 ;
F_5 ( & V_7 -> V_40 . V_41 , V_11 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_3 . V_42 . V_40 ; V_26 ++ ) {
if ( ! V_7 -> V_40 . V_43 [ V_26 ] )
continue;
V_10 = V_7 -> V_40 . V_43 [ V_26 ] -> V_19 [ V_44 ] ;
if ( V_10 && V_10 -> V_17 == V_20 )
break;
}
F_9 ( & V_7 -> V_40 . V_41 , V_11 ) ;
return V_26 ;
}
static void
F_22 ( struct V_4 * V_5 , int V_26 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_45 * V_46 = & V_7 -> V_46 . V_47 [ V_26 ] ;
F_8 ( V_5 , 0x00b008 + ( V_26 * 0x10 ) , V_46 -> V_48 ) ;
F_8 ( V_5 , 0x00b004 + ( V_26 * 0x10 ) , V_46 -> V_49 ) ;
F_8 ( V_5 , 0x00b000 + ( V_26 * 0x10 ) , V_46 -> V_50 ) ;
}
static void
F_23 ( struct V_4 * V_5 )
{
T_1 V_20 = ( F_7 ( V_5 , 0x00b318 ) & 0x000fffff ) << 4 ;
T_1 V_51 = F_21 ( V_5 , V_20 ) ;
T_1 V_52 = F_7 ( V_5 , 0x00b100 ) ;
T_1 type = F_7 ( V_5 , 0x00b230 ) ;
T_1 V_33 = F_7 ( V_5 , 0x00b234 ) ;
T_1 V_34 = F_7 ( V_5 , 0x00b238 ) ;
T_1 V_53 = V_52 ;
if ( V_52 & 0x01000000 ) {
if ( type == 0x00000020 && V_33 == 0x0000 ) {
F_6 ( V_5 , 0x00b308 , 0x00000000 , 0x00000000 ) ;
V_53 &= ~ 0x01000000 ;
}
if ( type == 0x00000010 ) {
if ( ! F_24 ( V_5 , V_51 , 0x3174 , V_33 , V_34 ) )
V_53 &= ~ 0x01000000 ;
}
}
F_8 ( V_5 , 0x00b100 , V_52 ) ;
F_8 ( V_5 , 0x00b230 , 0x00000001 ) ;
if ( V_53 && F_25 () ) {
F_26 ( V_5 , L_3 ,
V_51 , V_20 , V_52 , type , V_33 , V_34 ) ;
}
}
static void
F_27 ( struct V_4 * V_5 )
{
if ( F_7 ( V_5 , 0x00b100 ) )
F_23 ( V_5 ) ;
if ( F_7 ( V_5 , 0x00b800 ) ) {
T_1 V_52 = F_7 ( V_5 , 0x00b800 ) ;
F_26 ( V_5 , L_4 , V_52 ) ;
F_8 ( V_5 , 0xb800 , V_52 ) ;
}
}
static void
F_28 ( struct V_4 * V_5 , int V_3 )
{
struct V_24 * V_25 = F_15 ( V_5 , V_3 ) ;
F_29 ( V_5 , 0 ) ;
F_30 ( V_5 , V_54 ) ;
F_31 ( V_25 ) ;
}
int
F_32 ( struct V_4 * V_5 )
{
struct V_24 * V_25 ;
V_25 = F_33 ( sizeof( * V_25 ) , V_55 ) ;
if ( ! V_25 )
return - V_56 ;
V_25 -> V_29 . V_57 = F_28 ;
V_25 -> V_29 . V_58 = F_14 ;
V_25 -> V_29 . V_59 = F_18 ;
V_25 -> V_29 . V_60 = F_1 ;
V_25 -> V_29 . V_61 = F_10 ;
V_25 -> V_29 . V_62 = F_12 ;
V_25 -> V_29 . V_30 = F_22 ;
F_34 ( V_5 , 0 , F_27 ) ;
F_35 ( V_5 , V_54 , & V_25 -> V_29 ) ;
F_36 ( V_5 , 0x3174 , V_54 ) ;
F_37 ( V_5 , 0x3174 , 0x0190 , F_19 ) ;
F_37 ( V_5 , 0x3174 , 0x01a0 , F_19 ) ;
F_37 ( V_5 , 0x3174 , 0x01b0 , F_19 ) ;
#if 0
NVOBJ_ENGINE_ADD(dev, ME, &pme->base);
NVOBJ_CLASS(dev, 0x4075, ME);
#endif
return 0 ;
}
