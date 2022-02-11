struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
int
F_3 ( struct V_2 * V_3 , T_1 V_5 , int type , struct V_6 * V_7 )
{
struct F_2 * V_8 = F_2 ( V_3 ) ;
return F_4 ( V_8 -> V_9 , V_5 , type , V_10 , V_7 ) ;
}
static void
F_5 ( struct V_2 * V_3 )
{
struct F_2 * V_8 = F_2 ( V_3 ) ;
struct V_11 * V_12 = V_8 -> V_3 . V_13 . V_12 ;
unsigned long V_14 ;
F_6 ( & V_8 -> V_3 . V_15 , V_14 ) ;
F_7 ( V_12 , 0x00330c , 0x00000001 ) ;
F_8 (device, 2000 ,
if (!(nvkm_rd32(device, 0x00330c) & 0x00000002))
break;
) ;
F_9 ( & V_8 -> V_3 . V_15 , V_14 ) ;
}
int
F_10 ( struct V_2 * V_3 )
{
struct F_2 * V_8 = F_2 ( V_3 ) ;
struct V_11 * V_12 = V_8 -> V_3 . V_13 . V_12 ;
static struct V_16 V_17 ;
static struct V_16 V_18 ;
struct V_1 * V_19 ;
T_1 V_20 , V_21 ;
int V_22 ;
V_22 = F_11 ( V_12 , 0x20000 , 0 , false , NULL , & V_8 -> V_23 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_12 , V_8 -> V_24 , 0 , false , V_8 -> V_23 ,
& V_8 -> V_25 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_12 , 0x4000 , 0 , false , V_8 -> V_23 , & V_8 -> V_26 ) ;
if ( V_22 )
return V_22 ;
V_20 = 0x0100000000ULL ;
V_21 = V_20 + V_12 -> V_27 -> V_28 ( V_12 , 3 ) ;
V_22 = F_12 ( V_12 , V_20 , V_21 - V_20 , V_20 , & V_18 , & V_19 ) ;
if ( V_22 )
return V_22 ;
F_13 ( & V_19 -> V_29 [ V_30 ] ) ;
V_22 = F_14 ( V_19 , V_21 -- - V_20 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_15 ( V_19 , & V_8 -> V_4 , V_8 -> V_26 ) ;
F_15 ( NULL , & V_19 , NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_12 , 24 , 16 , false , V_8 -> V_23 , & V_8 -> V_31 ) ;
if ( V_22 )
return V_22 ;
F_16 ( V_8 -> V_31 ) ;
F_17 ( V_8 -> V_31 , 0x00 , 0x7fc00000 ) ;
F_17 ( V_8 -> V_31 , 0x04 , F_18 ( V_21 ) ) ;
F_17 ( V_8 -> V_31 , 0x08 , F_18 ( V_20 ) ) ;
F_17 ( V_8 -> V_31 , 0x0c , F_19 ( V_21 ) << 24 |
F_19 ( V_20 ) ) ;
F_17 ( V_8 -> V_31 , 0x10 , 0x00000000 ) ;
F_17 ( V_8 -> V_31 , 0x14 , 0x00000000 ) ;
F_20 ( V_8 -> V_31 ) ;
V_20 = 0x0000000000ULL ;
V_21 = V_20 + V_12 -> V_27 -> V_28 ( V_12 , 1 ) ;
V_22 = F_12 ( V_12 , V_20 , V_21 -- - V_20 , V_20 , & V_17 , & V_19 ) ;
if ( V_22 )
return V_22 ;
F_13 ( & V_19 -> V_29 [ V_30 ] ) ;
V_22 = F_15 ( V_19 , & V_8 -> V_9 , V_8 -> V_26 ) ;
F_15 ( NULL , & V_19 , NULL ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_12 , 24 , 16 , false , V_8 -> V_23 , & V_8 -> V_32 ) ;
if ( V_22 )
return V_22 ;
F_16 ( V_8 -> V_32 ) ;
F_17 ( V_8 -> V_32 , 0x00 , 0x7fc00000 ) ;
F_17 ( V_8 -> V_32 , 0x04 , F_18 ( V_21 ) ) ;
F_17 ( V_8 -> V_32 , 0x08 , F_18 ( V_20 ) ) ;
F_17 ( V_8 -> V_32 , 0x0c , F_19 ( V_21 ) << 24 |
F_19 ( V_20 ) ) ;
F_17 ( V_8 -> V_32 , 0x10 , 0x00000000 ) ;
F_17 ( V_8 -> V_32 , 0x14 , 0x00000000 ) ;
F_20 ( V_8 -> V_32 ) ;
return 0 ;
}
int
F_21 ( struct V_2 * V_3 )
{
struct F_2 * V_8 = F_2 ( V_3 ) ;
struct V_11 * V_12 = V_8 -> V_3 . V_13 . V_12 ;
int V_33 ;
F_22 ( V_12 , 0x000200 , 0x00000100 , 0x00000000 ) ;
F_22 ( V_12 , 0x000200 , 0x00000100 , 0x00000100 ) ;
F_7 ( V_12 , 0x100c80 , 0x00060001 ) ;
if ( F_8 (device, 2000 ,
if (!(nvkm_rd32(device, 0x100c80) & 0x00000001))
break;
) < 0 )
return - V_34 ;
F_7 ( V_12 , 0x001704 , 0x00000000 | V_8 -> V_23 -> V_35 >> 12 ) ;
F_7 ( V_12 , 0x001704 , 0x40000000 | V_8 -> V_23 -> V_35 >> 12 ) ;
F_7 ( V_12 , 0x001708 , 0x80000000 | V_8 -> V_32 -> V_36 -> V_37 >> 4 ) ;
F_7 ( V_12 , 0x00170c , 0x80000000 | V_8 -> V_31 -> V_36 -> V_37 >> 4 ) ;
for ( V_33 = 0 ; V_33 < 8 ; V_33 ++ )
F_7 ( V_12 , 0x001900 + ( V_33 * 4 ) , 0x00000000 ) ;
return 0 ;
}
void *
F_23 ( struct V_2 * V_3 )
{
struct F_2 * V_8 = F_2 ( V_3 ) ;
F_24 ( & V_8 -> V_32 ) ;
F_15 ( NULL , & V_8 -> V_9 , V_8 -> V_26 ) ;
F_24 ( & V_8 -> V_31 ) ;
if ( V_8 -> V_4 ) {
F_25 ( & V_8 -> V_4 -> V_38 [ 0 ] . V_23 [ 0 ] ) ;
F_15 ( NULL , & V_8 -> V_4 , V_8 -> V_26 ) ;
}
F_24 ( & V_8 -> V_26 ) ;
F_24 ( & V_8 -> V_25 ) ;
F_24 ( & V_8 -> V_23 ) ;
return V_8 ;
}
int
F_26 ( const struct V_39 * V_27 , struct V_11 * V_12 ,
int V_40 , T_2 V_24 , struct V_2 * * V_41 )
{
struct F_2 * V_8 ;
if ( ! ( V_8 = F_27 ( sizeof( * V_8 ) , V_42 ) ) )
return - V_43 ;
F_28 ( V_27 , V_12 , V_40 , & V_8 -> V_3 ) ;
V_8 -> V_24 = V_24 ;
* V_41 = & V_8 -> V_3 ;
return 0 ;
}
int
F_29 ( struct V_11 * V_12 , int V_40 , struct V_2 * * V_41 )
{
return F_26 ( & V_44 , V_12 , V_40 , 0x1400 , V_41 ) ;
}
