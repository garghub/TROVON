static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_2 ) ;
F_4 ( & V_4 -> V_5 -> V_5 ) ;
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_7 ( V_7 , & V_4 -> V_5 -> V_5 , V_8 ) ;
}
struct V_3 * F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_5 )
{
struct V_3 * V_4 ;
T_1 V_14 , V_15 ;
int V_16 ;
switch ( V_12 -> V_17 ) {
#define F_9 ( T_2 , T_3 , T_4 ) \
case DRM_FORMAT_##drm: \
format = CFG_##fmt; \
config = mod; \
break
F_9 ( V_18 , 565 , V_19 ) ;
F_9 ( V_20 , 565 , 0 ) ;
F_9 ( V_21 , 1555 , V_19 ) ;
F_9 ( V_22 , 1555 , 0 ) ;
F_9 ( V_23 , 888PACK , V_19 ) ;
F_9 ( V_24 , 888PACK , 0 ) ;
F_9 ( V_25 , V_26 , V_19 ) ;
F_9 ( V_27 , V_26 , 0 ) ;
F_9 ( V_28 , 8888 , V_19 ) ;
F_9 ( V_29 , 8888 , 0 ) ;
F_9 ( V_30 , 422PACK , V_31 | V_32 | V_33 ) ;
F_9 ( V_34 , 422PACK , V_31 ) ;
F_9 ( V_35 , 422PACK , V_31 | V_33 ) ;
F_9 ( V_36 , 422PACK , V_31 | V_32 ) ;
F_9 ( V_37 , 422 , V_31 ) ;
F_9 ( V_38 , 422 , V_31 | V_33 ) ;
F_9 ( V_39 , 420 , V_31 ) ;
F_9 ( V_40 , 420 , V_31 | V_33 ) ;
F_9 ( V_41 , V_42 , 0 ) ;
#undef F_9
default:
return F_10 ( - V_43 ) ;
}
V_4 = F_11 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_12 ( L_1 ) ;
return F_10 ( - V_45 ) ;
}
V_4 -> T_3 = V_14 ;
V_4 -> T_4 = V_15 ;
V_4 -> V_5 = V_5 ;
F_13 ( & V_4 -> V_2 , V_12 ) ;
V_16 = F_14 ( V_10 , & V_4 -> V_2 , & V_46 ) ;
if ( V_16 ) {
F_5 ( V_4 ) ;
return F_10 ( V_16 ) ;
}
F_15 ( & V_5 -> V_5 ) ;
return V_4 ;
}
static struct V_1 * F_16 ( struct V_9 * V_10 ,
struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_13 * V_5 ;
struct V_3 * V_4 ;
int V_16 ;
F_17 ( L_2 ,
V_12 -> V_47 , V_12 -> V_48 , V_12 -> V_17 ,
V_12 -> V_49 , V_12 -> V_50 [ 0 ] , V_12 -> V_50 [ 1 ] ,
V_12 -> V_50 [ 2 ] ) ;
if ( F_18 ( V_12 -> V_17 ) > 1 &&
( V_12 -> V_51 [ 0 ] != V_12 -> V_51 [ 1 ] ||
V_12 -> V_51 [ 0 ] != V_12 -> V_51 [ 2 ] ) ) {
V_16 = - V_43 ;
goto V_52;
}
V_5 = F_19 ( V_10 , V_7 , V_12 -> V_51 [ 0 ] ) ;
if ( ! V_5 ) {
V_16 = - V_53 ;
goto V_52;
}
if ( V_5 -> V_5 . V_54 && ! V_5 -> V_55 ) {
V_16 = F_20 ( V_5 ) ;
if ( V_16 )
goto V_56;
}
if ( V_5 -> V_57 == V_58 ) {
V_16 = - V_43 ;
goto V_56;
}
V_4 = F_8 ( V_10 , V_12 , V_5 ) ;
if ( F_21 ( V_4 ) ) {
V_16 = F_22 ( V_4 ) ;
goto V_52;
}
F_4 ( & V_5 -> V_5 ) ;
return & V_4 -> V_2 ;
V_56:
F_4 ( & V_5 -> V_5 ) ;
V_52:
F_12 ( L_3 , V_16 ) ;
return F_10 ( V_16 ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_59 * V_60 = V_10 -> V_61 ;
struct V_62 * V_63 = V_60 -> V_64 ;
if ( V_63 )
F_24 ( V_63 ) ;
}
