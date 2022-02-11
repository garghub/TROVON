static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_5 * V_9 ;
T_1 V_10 ;
int V_11 = 0 ;
V_10 = V_4 -> V_12 [ 0 ] * V_4 -> V_13 ;
V_11 = F_2 ( V_8 , V_10 , true , & V_9 ) ;
if ( V_11 )
return V_11 ;
* V_6 = V_9 ;
return V_11 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 =
F_4 ( V_15 , struct V_1 , V_18 . V_15 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_19 * V_20 ;
struct V_21 * V_18 ;
struct V_3 V_4 ;
struct V_22 * V_22 = & V_8 -> V_23 -> V_8 ;
struct V_5 * V_9 = NULL ;
struct V_24 * V_25 = NULL ;
int V_10 , V_11 ;
if ( V_17 -> V_26 != 32 )
return - V_27 ;
V_4 . V_28 = V_17 -> V_29 ;
V_4 . V_13 = V_17 -> V_30 ;
V_4 . V_12 [ 0 ] = V_4 . V_28 * ( ( V_17 -> V_26 + 7 ) / 8 ) ;
V_4 . V_31 = F_5 ( V_17 -> V_26 ,
V_17 -> V_32 ) ;
V_10 = V_4 . V_12 [ 0 ] * V_4 . V_13 ;
V_11 = F_1 ( V_2 , & V_4 , & V_9 ) ;
if ( V_11 ) {
F_6 ( L_1 , V_11 ) ;
return V_11 ;
}
V_25 = F_7 ( V_9 ) ;
V_11 = F_8 ( & V_25 -> V_25 , true , false , false , 0 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_25 , V_33 , NULL ) ;
if ( V_11 ) {
F_6 ( L_2 ) ;
F_10 ( & V_25 -> V_25 ) ;
return V_11 ;
}
V_11 = F_11 ( & V_25 -> V_25 , 0 , V_25 -> V_25 . V_34 ,
& V_25 -> V_35 ) ;
if ( V_11 ) {
F_6 ( L_3 ) ;
F_10 ( & V_25 -> V_25 ) ;
return V_11 ;
}
F_10 ( & V_25 -> V_25 ) ;
V_20 = F_12 ( 0 , V_22 ) ;
if ( V_20 == NULL )
return - V_36 ;
V_20 -> V_37 = & V_2 -> V_18 . V_15 ;
V_11 = F_13 ( V_2 -> V_8 , & V_2 -> V_18 . V_38 , & V_4 , V_9 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_18 . V_10 = V_10 ;
V_18 = & V_2 -> V_18 . V_38 . V_39 ;
V_2 -> V_18 . V_15 . V_18 = V_18 ;
V_2 -> V_18 . V_15 . V_40 = V_20 ;
strcpy ( V_20 -> V_41 . V_42 , L_4 ) ;
V_20 -> V_43 = V_44 ;
V_20 -> V_45 = & V_46 ;
F_14 ( V_20 , V_18 -> V_12 [ 0 ] , V_18 -> V_47 ) ;
F_15 ( V_20 , & V_2 -> V_18 . V_15 , V_17 -> V_48 ,
V_17 -> V_49 ) ;
V_20 -> V_50 = V_25 -> V_35 . V_51 ;
V_20 -> V_52 = V_10 ;
#if 0
info->fix.smem_start = bochs_bo_mmap_offset(bo);
info->fix.smem_len = size;
#endif
V_11 = F_16 ( & V_20 -> V_53 , 256 , 0 ) ;
if ( V_11 ) {
F_6 ( L_5 , V_20 -> V_41 . V_42 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_54 * V_38 = & V_2 -> V_18 . V_38 ;
struct V_19 * V_20 ;
F_18 ( L_6 ) ;
if ( V_2 -> V_18 . V_15 . V_40 ) {
V_20 = V_2 -> V_18 . V_15 . V_40 ;
F_19 ( V_20 ) ;
if ( V_20 -> V_53 . V_55 )
F_20 ( & V_20 -> V_53 ) ;
F_21 ( V_20 ) ;
}
if ( V_38 -> V_56 ) {
F_22 ( V_38 -> V_56 ) ;
V_38 -> V_56 = NULL ;
}
F_23 ( & V_2 -> V_18 . V_15 ) ;
F_24 ( & V_38 -> V_39 ) ;
F_25 ( & V_38 -> V_39 ) ;
return 0 ;
}
void F_26 ( struct V_57 * V_58 , T_2 V_59 , T_2 V_60 ,
T_2 V_61 , int V_62 )
{
}
void F_27 ( struct V_57 * V_58 , T_2 * V_59 , T_2 * V_60 ,
T_2 * V_61 , int V_62 )
{
* V_59 = V_62 ;
* V_60 = V_62 ;
* V_61 = V_62 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_11 ;
V_2 -> V_18 . V_15 . V_63 = & V_64 ;
V_11 = F_29 ( V_2 -> V_8 , & V_2 -> V_18 . V_15 ,
1 , 1 ) ;
if ( V_11 )
return V_11 ;
F_30 ( & V_2 -> V_18 . V_15 ) ;
F_31 ( V_2 -> V_8 ) ;
F_32 ( & V_2 -> V_18 . V_15 , 32 ) ;
V_2 -> V_18 . V_65 = true ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_65 )
return;
F_17 ( V_2 ) ;
V_2 -> V_18 . V_65 = false ;
}
