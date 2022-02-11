static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , 0 , V_2 ,
20 , 16 , 0 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_10 , 0x00 , F_5 ( V_10 ) ) ;
F_4 ( V_10 , 0x04 , 0x00000000 ) ;
F_4 ( V_10 , 0x08 , 0x00000000 ) ;
F_4 ( V_10 , 0x0c , 0x00000000 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_12 , T_1 V_13 , void * V_14 , T_1 V_15 )
{
struct V_16 * V_17 = V_16 ( V_12 ) ;
struct V_18 * V_19 = ( void * ) V_12 -> V_3 ;
T_1 V_20 = * ( T_1 * ) V_14 << 4 ;
T_1 V_21 = F_7 ( V_17 , V_20 + 0 ) ;
T_1 V_22 = F_7 ( V_17 , V_20 + 4 ) ;
T_1 V_23 = F_7 ( V_17 , V_20 + 8 ) ;
T_1 V_24 = ( V_23 & 0xfffff000 ) | ( V_21 >> 20 ) ;
T_1 V_7 = V_22 + 1 ;
if ( ! ( V_21 & 0x00002000 ) )
return - V_25 ;
if ( V_13 == 0x0190 ) {
F_8 ( V_19 , 0x00b300 , 0x00030000 , ( V_21 & 0x00030000 ) ) ;
F_9 ( V_19 , 0x00b334 , V_24 ) ;
F_9 ( V_19 , 0x00b324 , V_7 ) ;
} else
if ( V_13 == 0x01a0 ) {
F_8 ( V_19 , 0x00b300 , 0x000c0000 , ( V_21 & 0x00030000 ) << 2 ) ;
F_9 ( V_19 , 0x00b360 , V_24 ) ;
F_9 ( V_19 , 0x00b364 , V_7 ) ;
} else {
if ( V_21 & 0x000c0000 )
return - V_25 ;
F_9 ( V_19 , 0x00b370 , V_24 ) ;
F_9 ( V_19 , 0x00b374 , V_7 ) ;
}
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_18 * V_19 = ( void * ) V_3 ;
struct V_26 * V_27 ;
int V_11 ;
if ( ! F_11 ( & V_19 -> V_28 , 1 , 1 ) )
return - V_29 ;
V_11 = F_12 ( V_2 , V_3 , V_5 , 0 , & V_27 ) ;
* V_8 = F_3 ( V_27 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void
F_13 ( struct V_1 * V_12 )
{
struct V_18 * V_19 = ( void * ) V_12 -> V_3 ;
struct V_26 * V_27 = ( void * ) V_12 ;
F_14 ( & V_19 -> V_28 ) ;
F_15 ( & V_27 -> V_24 ) ;
}
void
F_16 ( struct V_30 * V_3 , int V_31 )
{
struct V_32 * V_33 = & F_17 ( V_3 ) -> V_33 . V_34 [ V_31 ] ;
struct V_18 * V_19 = ( void * ) V_3 ;
F_9 ( V_19 , 0x00b008 + ( V_31 * 0x10 ) , V_33 -> V_35 ) ;
F_9 ( V_19 , 0x00b004 + ( V_31 * 0x10 ) , V_33 -> V_36 ) ;
F_9 ( V_19 , 0x00b000 + ( V_31 * 0x10 ) , V_33 -> V_37 ) ;
}
void
F_18 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_40 ( V_39 ) ;
struct V_30 * V_3 = F_19 ( V_39 ) ;
struct V_1 * V_42 ;
struct V_43 * V_44 ;
struct V_18 * V_19 = ( void * ) V_39 ;
T_1 V_20 = F_20 ( V_19 , 0x00b318 ) & 0x000fffff ;
T_1 V_45 = F_20 ( V_19 , 0x00b100 ) ;
T_1 type = F_20 ( V_19 , 0x00b230 ) ;
T_1 V_13 = F_20 ( V_19 , 0x00b234 ) ;
T_1 V_6 = F_20 ( V_19 , 0x00b238 ) ;
T_1 V_46 = V_45 ;
int V_47 ;
V_42 = F_21 ( V_3 , V_20 ) ;
V_47 = V_41 -> V_47 ( V_41 , V_42 ) ;
if ( V_45 & 0x01000000 ) {
if ( type == 0x00000020 && V_13 == 0x0000 ) {
F_8 ( V_19 , 0x00b308 , 0x00000000 , 0x00000000 ) ;
V_46 &= ~ 0x01000000 ;
}
if ( type == 0x00000010 ) {
V_44 = F_22 ( V_42 , 0x3174 ) ;
if ( V_44 && ! F_23 ( V_44 -> V_12 , V_13 , V_6 ) )
V_46 &= ~ 0x01000000 ;
F_24 ( V_44 ) ;
}
}
F_9 ( V_19 , 0x00b100 , V_45 ) ;
F_9 ( V_19 , 0x00b230 , 0x00000001 ) ;
if ( V_46 ) {
F_25 ( V_19 ,
L_1 ,
V_47 , V_20 << 4 , F_26 ( V_42 ) , V_45 ,
type , V_13 , V_6 ) ;
}
F_27 ( V_42 ) ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_18 * V_19 ;
int V_11 ;
V_11 = F_29 ( V_2 , V_3 , V_5 , & V_19 ) ;
* V_8 = F_3 ( V_19 ) ;
if ( V_11 )
return V_11 ;
F_30 ( V_19 ) -> V_48 = 0x00000002 ;
F_30 ( V_19 ) -> V_49 = F_18 ;
F_19 ( V_19 ) -> V_50 = & V_51 ;
F_19 ( V_19 ) -> V_52 = V_53 ;
F_19 ( V_19 ) -> V_54 = F_16 ;
return 0 ;
}
int
F_31 ( struct V_1 * V_12 )
{
struct V_30 * V_3 = F_19 ( V_12 ) ;
struct V_18 * V_19 = ( void * ) V_12 ;
struct F_17 * V_55 = F_17 ( V_12 ) ;
int V_11 , V_31 ;
V_11 = F_32 ( & V_19 -> V_24 ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_19 , 0x00b0e0 , 0x00000020 ) ;
F_9 ( V_19 , 0x00b0e8 , 0x00000020 ) ;
for ( V_31 = 0 ; V_31 < V_55 -> V_33 . V_56 ; V_31 ++ )
V_3 -> V_54 ( V_3 , V_31 ) ;
F_9 ( V_19 , 0x00b32c , 0x00000000 ) ;
F_9 ( V_19 , 0x00b314 , 0x00000100 ) ;
if ( F_33 ( V_19 ) -> V_57 >= 0x40 && F_34 ( V_19 ) )
F_9 ( V_19 , 0x00b220 , 0x00000044 ) ;
else
F_9 ( V_19 , 0x00b220 , 0x00000031 ) ;
F_9 ( V_19 , 0x00b300 , 0x02001ec1 ) ;
F_8 ( V_19 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_9 ( V_19 , 0x00b100 , 0xffffffff ) ;
F_9 ( V_19 , 0x00b140 , 0xffffffff ) ;
if ( ! F_35 ( V_19 , 0x00b200 , 0x00000001 , 0x00000000 ) ) {
F_25 ( V_19 , L_2 , F_20 ( V_19 , 0x00b200 ) ) ;
return - V_29 ;
}
return 0 ;
}
