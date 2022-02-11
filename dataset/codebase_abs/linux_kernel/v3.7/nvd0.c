static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_12 ;
F_2 ( & V_7 -> V_13 . V_14 , V_12 ) ;
F_3 (chan, temp, &disp->vblank.list, vblank.head) {
if ( V_10 -> V_13 . V_3 != V_3 )
continue;
F_4 ( V_2 , 0x001718 , 0x80000000 | V_10 -> V_13 . V_15 ) ;
V_5 -> V_16 ( V_5 ) ;
F_4 ( V_2 , 0x06000c , F_5 ( V_10 -> V_13 . V_17 ) ) ;
F_4 ( V_2 , 0x060010 , F_6 ( V_10 -> V_13 . V_17 ) ) ;
F_4 ( V_2 , 0x060014 , V_10 -> V_13 . V_18 ) ;
F_7 ( & V_10 -> V_13 . V_19 ) ;
if ( V_7 -> V_13 . V_20 )
V_7 -> V_13 . V_20 ( V_7 -> V_13 . V_21 , V_3 ) ;
}
F_8 ( & V_7 -> V_13 . V_14 , V_12 ) ;
if ( V_7 -> V_13 . V_22 )
V_7 -> V_13 . V_22 ( V_7 -> V_13 . V_21 , V_3 ) ;
}
static void
F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = ( void * ) V_24 ;
T_1 V_25 = F_10 ( V_2 , 0x610088 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
T_1 V_27 = 0x01000000 << V_26 ;
if ( V_27 & V_25 ) {
T_1 V_28 = F_10 ( V_2 , 0x6100bc + ( V_26 * 0x800 ) ) ;
if ( V_28 & 0x00000001 )
F_1 ( V_2 , V_26 ) ;
F_11 ( V_2 , 0x6100bc + ( V_26 * 0x800 ) , 0 , 0 ) ;
F_10 ( V_2 , 0x6100c0 + ( V_26 * 0x800 ) ) ;
}
}
}
static int
F_12 ( struct V_29 * V_30 , struct V_29 * V_31 ,
struct V_32 * V_33 , void * V_21 , T_1 V_34 ,
struct V_29 * * V_35 )
{
struct V_1 * V_2 ;
int V_36 ;
V_36 = F_13 ( V_30 , V_31 , V_33 , L_1 ,
L_2 , & V_2 ) ;
* V_35 = F_14 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_15 ( V_2 ) -> V_37 = V_38 ;
F_16 ( V_2 ) -> V_25 = F_9 ;
F_17 ( & V_2 -> V_8 . V_13 . V_39 ) ;
F_18 ( & V_2 -> V_8 . V_13 . V_14 ) ;
return 0 ;
}
