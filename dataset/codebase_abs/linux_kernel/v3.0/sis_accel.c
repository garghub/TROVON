static void
F_1 ( struct V_1 * V_2 )
{
V_3
}
static void
F_2 ( struct V_1 * V_2 , int V_4 , int V_5 ,
int V_6 , int V_7 )
{
F_3 ( V_2 -> V_8 ) ;
F_4 (ivideo->video_linelength)
F_5 (ivideo->video_linelength, 0xffff )
if( V_7 != - 1 ) {
F_6 ( 0x0A )
F_7 (trans_color)
F_8 (TRANSPARENT_BITBLT)
} else {
F_6 (sisALUConv[rop])
}
if( V_4 > 0 ) {
F_8 (X_INC)
}
if( V_5 > 0 ) {
F_8 (Y_INC)
}
}
static void
F_9 ( struct V_1 * V_2 , int V_9 ,
int V_10 , int V_11 , int V_12 , int V_13 , int V_14 )
{
T_1 V_15 = 0 , V_16 = 0 ;
if( V_10 >= 2048 ) {
V_15 = V_2 -> V_17 * V_10 ;
V_10 = 0 ;
}
if( V_12 >= 2048 ) {
V_16 = V_2 -> V_17 * V_12 ;
V_12 = 0 ;
}
F_10 ( V_15 ) ;
F_11 ( V_16 ) ;
if( ! ( V_2 -> V_18 & V_19 ) ) {
V_9 += V_13 - 1 ;
V_11 += V_13 - 1 ;
}
if( ! ( V_2 -> V_18 & V_20 ) ) {
V_10 += V_14 - 1 ;
V_12 += V_14 - 1 ;
}
F_12 (width, height)
F_13 (src_x, src_y)
F_14 (dst_x, dst_y)
V_21
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_22 , int V_6 )
{
F_16 (color)
F_5 (ivideo->video_linelength, 0xffff )
F_3 ( V_2 -> V_8 ) ;
F_6 (sisPatALUConv[rop])
F_8 (PATFG)
}
static void
F_17 ( struct V_1 * V_2 , int V_23 , int V_24 , int V_25 , int V_26 )
{
T_1 V_16 = 0 ;
if( V_24 >= 2048 ) {
V_16 = V_2 -> V_17 * V_24 ;
V_24 = 0 ;
}
F_11 (dstbase)
F_14 (x,y)
F_12 (w,h)
F_8 (X_INC | Y_INC | BITBLT)
V_21
}
static void
F_18 ( struct V_1 * V_2 )
{
V_27
}
static void
F_19 ( struct V_1 * V_2 , int V_6 , int V_7 )
{
F_20 ( V_2 -> V_8 ) ;
F_21 (ivideo->video_linelength)
F_22 (ivideo->video_linelength, 0x0fff )
if( V_7 != - 1 ) {
F_23 ( 0x0A )
F_24 (trans_color)
F_25 (TRANSPARENT_BITBLT)
} else {
F_23 (sisALUConv[rop])
}
F_25 (ivideo->SiS310_AccelDepth)
}
static void
F_26 ( struct V_1 * V_2 , int V_9 , int V_10 ,
int V_11 , int V_12 , int V_13 , int V_14 )
{
T_1 V_15 = 0 , V_16 = 0 ;
int V_28 = F_27 ( V_10 , V_12 ) ;
int V_29 = F_28 ( V_10 , V_12 ) ;
if( ( V_29 - V_28 ) < V_14 ) {
if( ( V_10 >= 2048 ) || ( V_12 >= 2048 ) ) {
V_15 = V_2 -> V_17 * V_28 ;
V_16 = V_2 -> V_17 * V_28 ;
V_10 -= V_28 ;
V_12 -= V_28 ;
}
} else {
if( V_10 >= 2048 ) {
V_15 = V_2 -> V_17 * V_10 ;
V_10 = 0 ;
}
if( V_12 >= 2048 ) {
V_16 = V_2 -> V_17 * V_12 ;
V_12 = 0 ;
}
}
V_15 += V_2 -> V_30 ;
V_16 += V_2 -> V_30 ;
F_29 ( V_15 ) ;
F_30 ( V_16 ) ;
F_31 (width, height)
F_32 (src_x, src_y)
F_33 (dst_x, dst_y)
V_31
}
static void
F_34 ( struct V_1 * V_2 , T_1 V_22 , int V_6 )
{
F_35 (color)
F_22 (ivideo->video_linelength, 0x0fff )
F_20 ( V_2 -> V_8 ) ;
F_23 (sisPatALUConv[rop])
F_25 (PATFG | ivideo->SiS310_AccelDepth)
}
static void
F_36 ( struct V_1 * V_2 , int V_23 , int V_24 , int V_25 , int V_26 )
{
T_1 V_16 = 0 ;
if( V_24 >= 2048 ) {
V_16 = V_2 -> V_17 * V_24 ;
V_24 = 0 ;
}
V_16 += V_2 -> V_30 ;
F_30 (dstbase)
F_33 (x,y)
F_31 (w,h)
F_25 (BITBLT)
V_31
}
int F_37 ( struct V_1 * V_2 )
{
#ifdef F_38
F_39 ( & V_2 -> V_32 ) ;
#endif
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
if( V_2 -> V_33 == V_34 ) {
#ifdef F_41
F_1 ( V_2 ) ;
#endif
} else {
#ifdef F_42
F_18 ( V_2 ) ;
#endif
}
}
int F_43 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 -> V_37 ;
F_44
if( ( ! V_2 -> V_38 ) || ( ! V_2 -> V_39 ) )
return 0 ;
T_2
F_40 ( V_2 ) ;
F_45
return 0 ;
}
void F_46 ( struct V_35 * V_36 , const struct V_40 * V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 -> V_37 ;
T_1 V_42 = 0 ;
T_1 V_43 = V_36 -> V_44 . V_45 ;
T_1 V_46 = V_36 -> V_44 . V_47 ;
int V_13 , V_14 ;
F_44
if( V_36 -> V_48 != V_49 )
return;
if( ( ! V_2 -> V_38 ) || ( ! V_2 -> V_39 ) ) {
F_47 ( V_36 , V_41 ) ;
return;
}
if( ! V_41 -> V_13 || ! V_41 -> V_14 || V_41 -> V_50 >= V_43 || V_41 -> V_51 >= V_46 )
return;
V_13 = ( ( V_41 -> V_50 + V_41 -> V_13 ) > V_43 ) ? ( V_43 - V_41 -> V_50 ) : V_41 -> V_13 ;
V_14 = ( ( V_41 -> V_51 + V_41 -> V_14 ) > V_46 ) ? ( V_46 - V_41 -> V_51 ) : V_41 -> V_14 ;
switch( V_36 -> V_44 . V_52 ) {
case 8 : V_42 = V_41 -> V_22 ;
break;
case 16 :
case 32 : V_42 = ( ( T_1 * ) ( V_36 -> V_53 ) ) [ V_41 -> V_22 ] ;
break;
}
if( V_2 -> V_33 == V_34 ) {
#ifdef F_41
T_2
F_15 ( V_2 , V_42 , V_54 [ V_41 -> V_6 ] ) ;
F_17 ( V_2 , V_41 -> V_50 , V_41 -> V_51 , V_13 , V_14 ) ;
F_45
#endif
} else {
#ifdef F_42
T_2
F_34 ( V_2 , V_42 , V_54 [ V_41 -> V_6 ] ) ;
F_36 ( V_2 , V_41 -> V_50 , V_41 -> V_51 , V_13 , V_14 ) ;
F_45
#endif
}
F_40 ( V_2 ) ;
}
void F_48 ( struct V_35 * V_36 , const struct V_55 * V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 -> V_37 ;
T_1 V_43 = V_36 -> V_44 . V_45 ;
T_1 V_46 = V_36 -> V_44 . V_47 ;
int V_13 = V_56 -> V_13 ;
int V_14 = V_56 -> V_14 ;
F_44
if( V_36 -> V_48 != V_49 )
return;
if( ( ! V_2 -> V_38 ) || ( ! V_2 -> V_39 ) ) {
F_49 ( V_36 , V_56 ) ;
return;
}
if( ! V_13 || ! V_14 ||
V_56 -> V_57 >= V_43 || V_56 -> V_58 >= V_46 ||
V_56 -> V_50 >= V_43 || V_56 -> V_51 >= V_46 )
return;
if( ( V_56 -> V_57 + V_13 ) > V_43 ) V_13 = V_43 - V_56 -> V_57 ;
if( ( V_56 -> V_50 + V_13 ) > V_43 ) V_13 = V_43 - V_56 -> V_50 ;
if( ( V_56 -> V_58 + V_14 ) > V_46 ) V_14 = V_46 - V_56 -> V_58 ;
if( ( V_56 -> V_51 + V_14 ) > V_46 ) V_14 = V_46 - V_56 -> V_51 ;
if( V_2 -> V_33 == V_34 ) {
#ifdef F_41
int V_4 , V_5 ;
if( V_56 -> V_57 < V_56 -> V_50 ) V_4 = 0 ;
else V_4 = 1 ;
if( V_56 -> V_58 < V_56 -> V_51 ) V_5 = 0 ;
else V_5 = 1 ;
T_2
F_2 ( V_2 , V_4 , V_5 , 3 , - 1 ) ;
F_9 ( V_2 , V_56 -> V_57 , V_56 -> V_58 ,
V_56 -> V_50 , V_56 -> V_51 , V_13 , V_14 ) ;
F_45
#endif
} else {
#ifdef F_42
T_2
F_19 ( V_2 , 3 , - 1 ) ;
F_26 ( V_2 , V_56 -> V_57 , V_56 -> V_58 ,
V_56 -> V_50 , V_56 -> V_51 , V_13 , V_14 ) ;
F_45
#endif
}
F_40 ( V_2 ) ;
}
