static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned int V_11 ;
V_10 = F_4 ( V_2 -> V_12 . V_13 , 256 ) ;
if ( ! V_10 )
return - V_14 ;
for ( V_11 = 0 ; V_11 < 256 ; ++ V_11 )
F_5 ( V_10 , V_15 + 4 * V_11 ,
V_8 -> V_16 . V_17 [ V_11 ] ) ;
F_6 ( & V_2 -> V_18 ) ;
F_7 ( V_2 -> V_2 , V_10 ) ;
F_8 ( & V_2 -> V_18 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_11 ( V_8 -> V_19 , struct V_1 , V_20 ) ;
switch ( V_8 -> V_21 ) {
case V_22 :
F_3 ( V_2 , V_8 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
static const unsigned int V_29 [] = {
V_30 ,
V_31 ,
V_32 ,
} ;
return F_13 ( V_24 , V_26 , V_28 , V_29 ,
F_14 ( V_29 ) ) ;
}
static int F_15 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_33 * V_34 )
{
return F_16 ( V_24 , V_26 , V_34 , V_35 ,
V_35 , V_36 ,
V_36 ) ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_18 ( V_24 ) ;
struct V_25 * V_39 ;
struct V_40 * V_41 ;
V_39 = F_19 ( & V_2 -> V_12 , V_26 , V_38 -> V_42 ) ;
if ( ! V_39 )
return - V_43 ;
if ( V_38 -> V_41 . V_28 != V_30 &&
V_38 -> V_41 . V_28 != V_31 &&
V_38 -> V_41 . V_28 != V_32 )
V_38 -> V_41 . V_28 = V_32 ;
V_41 = F_20 ( & V_2 -> V_12 , V_39 , V_38 -> V_44 ) ;
if ( V_38 -> V_44 == V_45 ) {
V_38 -> V_41 = * V_41 ;
return 0 ;
}
V_41 -> V_28 = V_38 -> V_41 . V_28 ;
V_41 -> V_46 = F_21 (unsigned int, fmt->format.width,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_41 -> V_47 = F_21 (unsigned int, fmt->format.height,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = V_51 ;
V_38 -> V_41 = * V_41 ;
V_41 = F_20 ( & V_2 -> V_12 , V_39 ,
V_45 ) ;
* V_41 = V_38 -> V_41 ;
return 0 ;
}
static void F_22 ( struct V_52 * V_12 ,
struct V_53 * V_54 ,
struct V_3 * V_4 , bool V_55 )
{
struct V_1 * V_2 = F_18 ( & V_12 -> V_24 ) ;
struct V_9 * V_10 ;
unsigned long V_56 ;
if ( V_55 ) {
F_1 ( V_2 , V_4 , V_57 , V_58 ) ;
return;
}
F_23 ( & V_2 -> V_18 , V_56 ) ;
V_10 = V_2 -> V_2 ;
V_2 -> V_2 = NULL ;
F_24 ( & V_2 -> V_18 , V_56 ) ;
if ( V_10 )
F_25 ( V_4 , V_10 ) ;
}
struct V_1 * F_26 ( struct V_59 * V_13 )
{
struct V_1 * V_2 ;
int V_60 ;
V_2 = F_27 ( V_13 -> V_61 , sizeof( * V_2 ) , V_62 ) ;
if ( V_2 == NULL )
return F_28 ( - V_14 ) ;
F_29 ( & V_2 -> V_18 ) ;
V_2 -> V_12 . V_63 = & V_64 ;
V_2 -> V_12 . type = V_65 ;
V_60 = F_30 ( V_13 , & V_2 -> V_12 , L_1 , 2 , & V_66 ,
V_67 ) ;
if ( V_60 < 0 )
return F_28 ( V_60 ) ;
F_31 ( & V_2 -> V_20 , 1 ) ;
F_32 ( & V_2 -> V_20 , & V_68 , NULL ) ;
V_2 -> V_12 . V_24 . V_69 = & V_2 -> V_20 ;
if ( V_2 -> V_20 . error ) {
F_33 ( V_13 -> V_61 , L_2 ) ;
V_60 = V_2 -> V_20 . error ;
F_34 ( & V_2 -> V_12 ) ;
return F_28 ( V_60 ) ;
}
F_35 ( & V_2 -> V_20 ) ;
return V_2 ;
}
