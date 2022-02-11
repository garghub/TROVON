static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
int V_11 ;
struct V_12 * V_13 = V_7 -> V_14 ;
struct V_15 V_16 ;
T_1 V_17 [] = { V_9 , V_10 } ;
V_16 . V_18 = V_7 -> V_18 + V_8 ;
V_16 . V_19 = 0 ;
V_16 . V_20 = sizeof( V_17 ) ;
V_16 . V_21 = V_17 ;
V_11 = F_5 ( V_13 , & V_16 , 1 ) ;
if ( V_11 != 1 )
F_6 ( L_1 ,
V_7 -> V_18 + V_8 , V_9 , V_10 , V_11 ) ;
return ! ( V_11 == 1 ) ;
}
static int F_7 ( struct V_1 * V_22 )
{
struct V_6 * V_23 = V_22 -> V_7 ;
int V_24 = 0 ;
V_24 = F_4 ( V_23 , 0x02 , 0xa1 , 0x01 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x14 , 0x01 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0xe3 , 0x20 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0xe2 , 0x80 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x8a , 0x0c ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x89 , 0x08 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x71 , 0x2d ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x7d , 0x07 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x7b , 0x00 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x7a , 0xfd ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0xc0 , 0x12 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0xc1 , 0x92 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0xc2 , 0x1c ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x32 , 0x80 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x00 , 0xb0 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x15 , 0x40 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x54 , 0x10 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0x02 , 0x80 | V_22 -> V_25 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0x21 , 0x80 | V_22 -> V_26 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0x52 , 0x20 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0xf1 , 0x03 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0x62 , 0x41 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0xf6 , 0x01 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0x77 , 0x06 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x00 , 0x4c , 0x04 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc0 , 0x00 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc1 , 0x1c ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc2 , 0xf8 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc3 , 0x44 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc4 , 0x32 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc5 , 0x53 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc6 , 0x4c ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc7 , 0x56 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xc8 , 0x35 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xca , 0x01 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xcb , 0x05 ) ;
if ( V_24 )
goto error;
if ( V_22 -> V_27 ) {
V_24 = F_4 ( V_23 , 0x01 , 0xa5 , 0xa0 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x01 , 0xa7 ,
V_22 -> V_27 -> V_28 . V_29 ) ;
if ( V_24 )
goto error;
} else {
V_24 = F_4 ( V_23 , 0x01 , 0xa5 , 0x80 ) ;
if ( V_24 )
goto error;
}
V_24 = F_4 ( V_23 , 0x01 , 0xcc , 0x13 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x02 , 0xb1 , 0x20 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x10 , 0x16 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x59 , 0x60 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x04 , 0x54 , 0x14 ) ;
if ( V_24 )
goto error;
V_24 = F_4 ( V_23 , 0x02 , 0xa1 , 0x91 ) ;
error:
return V_24 ? - V_30 : 0 ;
}
static int F_8 ( struct V_31 * V_27 )
{
struct V_1 * V_22 = F_9 ( & V_27 -> V_32 ) ;
int V_11 , V_29 = V_27 -> V_28 . V_29 ;
if ( V_27 -> V_28 . V_33 != V_34 ||
V_27 -> V_28 . V_35 & ( V_36 | V_37 ) )
V_29 = 0 ;
if ( ! V_22 -> V_38 )
return - V_39 ;
V_11 = F_4 ( V_22 -> V_7 , 0x01 , 0xa7 , V_29 ) ;
return V_11 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_11 ;
if ( V_22 -> V_38 )
return;
F_11 ( V_22 -> V_40 , 0 ) ;
if ( V_22 -> V_41 ) {
V_11 = F_12 ( V_22 -> V_41 ) ;
if ( V_11 )
F_13 ( L_2 ) ;
}
if ( F_14 ( V_22 -> V_42 ) ) {
F_13 ( L_3 ) ;
return;
}
F_11 ( V_22 -> V_43 , 1 ) ;
F_15 ( V_44 + V_45 ,
V_46 + V_47 ) ;
F_11 ( V_22 -> V_40 , 1 ) ;
F_15 ( 20000 , 30000 ) ;
V_11 = F_7 ( V_22 ) ;
if ( V_11 ) {
F_13 ( L_4 , V_11 ) ;
return;
}
V_22 -> V_38 = true ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
if ( F_17 ( V_22 -> V_42 ) ) {
F_13 ( L_5 ) ;
return;
}
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
if ( F_19 ( V_22 -> V_42 ) ) {
F_13 ( L_6 ) ;
return;
}
F_20 ( V_48 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
if ( ! V_22 -> V_38 )
return;
V_22 -> V_38 = false ;
F_11 ( V_22 -> V_43 , 0 ) ;
if ( F_22 ( V_22 -> V_42 ) ) {
F_13 ( L_7 ) ;
return;
}
if ( V_22 -> V_41 )
F_23 ( V_22 -> V_41 ) ;
F_15 ( V_49 ,
2 * V_49 ) ;
F_11 ( V_22 -> V_40 , 0 ) ;
F_20 ( V_50 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
struct V_1 * V_22 ;
V_22 = F_3 ( V_5 ) ;
return F_25 ( V_22 -> V_42 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_11 ;
if ( ! V_3 -> V_51 ) {
F_13 ( L_8 ) ;
return - V_52 ;
}
V_22 -> V_5 . V_53 = V_54 ;
V_11 = F_27 ( V_3 -> V_32 , & V_22 -> V_5 ,
& V_55 , V_56 ) ;
if ( V_11 ) {
F_13 ( L_9 ) ;
return V_11 ;
}
F_28 ( & V_22 -> V_5 ,
& V_57 ) ;
F_29 ( & V_22 -> V_5 ) ;
F_30 ( & V_22 -> V_5 ,
V_3 -> V_51 ) ;
if ( V_22 -> V_42 )
F_31 ( V_22 -> V_42 , & V_22 -> V_5 ) ;
F_32 ( V_22 -> V_5 . V_32 ) ;
return V_11 ;
}
static int F_33 ( struct V_6 * V_7 ,
const struct V_58 * V_59 )
{
struct V_60 * V_32 = & V_7 -> V_32 ;
struct V_1 * V_22 ;
int V_11 ;
V_22 = F_34 ( V_32 , sizeof( * V_22 ) , V_61 ) ;
if ( ! V_22 )
return - V_62 ;
V_11 = F_35 ( V_32 -> V_63 , 0 , 0 , & V_22 -> V_42 , NULL ) ;
if ( V_11 )
return V_11 ;
V_22 -> V_7 = V_7 ;
V_22 -> V_41 = F_36 ( V_32 , L_10 ) ;
if ( F_37 ( V_22 -> V_41 ) ) {
F_38 ( V_32 , L_11 ) ;
V_22 -> V_41 = NULL ;
}
V_22 -> V_43 = F_39 ( V_32 , L_12 , V_64 ) ;
if ( F_37 ( V_22 -> V_43 ) ) {
V_11 = F_40 ( V_22 -> V_43 ) ;
F_41 ( V_32 , L_13 , V_11 ) ;
return V_11 ;
}
V_22 -> V_40 = F_39 ( V_32 , L_14 , V_64 ) ;
if ( F_37 ( V_22 -> V_40 ) ) {
V_11 = F_40 ( V_22 -> V_40 ) ;
F_41 ( V_32 , L_15 , V_11 ) ;
return V_11 ;
}
V_22 -> V_25 = V_59 -> V_65 ;
if ( F_42 ( V_32 -> V_63 , L_16 ,
& V_22 -> V_26 ) ) {
V_22 -> V_26 = V_22 -> V_25 ;
} else if ( V_22 -> V_26 > V_22 -> V_25 ) {
F_38 ( V_32 , L_17
L_18 ) ;
V_22 -> V_26 = V_22 -> V_25 ;
}
if ( ! F_43 ( V_32 -> V_63 , L_19 , NULL ) ) {
V_22 -> V_27 = F_44 ( L_20 ,
V_32 , V_22 , & V_66 ,
NULL ) ;
if ( F_37 ( V_22 -> V_27 ) ) {
F_13 ( L_21 ) ;
V_11 = F_40 ( V_22 -> V_27 ) ;
V_22 -> V_27 = NULL ;
return V_11 ;
}
V_22 -> V_27 -> V_28 . V_67 = V_68 ;
V_22 -> V_27 -> V_28 . V_29 = V_68 ;
}
V_22 -> V_3 . V_69 = & V_70 ;
V_22 -> V_3 . V_63 = V_32 -> V_63 ;
F_45 ( & V_22 -> V_3 ) ;
F_46 ( V_7 , V_22 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_22 = F_48 ( V_7 ) ;
F_49 ( V_22 -> V_27 ) ;
F_50 ( & V_22 -> V_3 ) ;
return 0 ;
}
