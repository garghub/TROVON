static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , const T_1 * V_6 , int V_7 )
{
int V_8 = F_4 ( V_5 , V_6 , V_7 ) ;
if ( V_8 == V_7 )
return 0 ;
return V_8 > 0 ? - V_9 : V_8 ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_10 * V_11 , int V_12 )
{
int V_8 = F_6 ( V_5 -> V_13 , V_11 , V_12 ) ;
if ( V_8 == V_12 )
return 0 ;
return V_8 > 0 ? - V_9 : V_8 ;
}
static int F_7 ( struct V_2 * V_3 , T_2 V_14 , T_3 V_15 )
{
struct V_4 * V_5 = F_8 ( V_3 ) ;
T_1 V_16 [ 5 ] ;
int V_17 = 0 ;
V_16 [ V_17 ++ ] = V_14 >> 8 ;
V_16 [ V_17 ++ ] = V_14 ;
V_16 [ V_17 ++ ] = V_15 >> 16 ;
V_16 [ V_17 ++ ] = V_15 >> 8 ;
V_16 [ V_17 ++ ] = V_15 ;
return F_3 ( V_5 , V_16 , V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 , T_2 V_14 , T_3 V_15 ,
int * V_8 )
{
return * V_8 ? * V_8 : F_7 ( V_3 , V_14 , V_15 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_14 , T_2 V_15 )
{
struct V_4 * V_5 = F_8 ( V_3 ) ;
T_1 V_16 [ 4 ] ;
int V_17 = 0 ;
V_16 [ V_17 ++ ] = V_14 >> 8 ;
V_16 [ V_17 ++ ] = V_14 ;
V_16 [ V_17 ++ ] = V_15 >> 8 ;
V_16 [ V_17 ++ ] = V_15 ;
return F_3 ( V_5 , V_16 , V_17 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_2 V_14 , T_2 V_15 ,
int * V_8 )
{
return * V_8 ? * V_8 : F_10 ( V_3 , V_14 , V_15 ) ;
}
static int F_12 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_4 * V_5 = F_8 ( V_3 ) ;
T_1 V_16 [ 2 ] ;
int V_8 ;
T_1 V_18 [] = { V_14 >> 8 , V_14 } ;
struct V_10 V_19 [] = { { V_5 -> V_20 , 0 , sizeof( V_18 ) , V_18 } ,
{ V_5 -> V_20 , V_21 , sizeof( V_16 ) , V_16 } } ;
V_8 = F_5 ( V_5 , V_19 , F_13 ( V_19 ) ) ;
if ( V_8 )
return V_8 ;
return V_16 [ 0 ] << 8 | V_16 [ 1 ] ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_8 = 0 ;
V_8 = F_11 ( V_3 , V_23 ,
V_24 | V_25 |
V_26 , & V_8 ) ;
F_15 ( 1 ) ;
V_8 = F_11 ( V_3 , V_23 ,
V_24 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_27 , 0 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_28 , 0x040022 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_29 ,
V_30 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_31 , 0x024080 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_32 , 0x200080 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_33 , 0xf4caed , & V_8 ) ;
V_8 = F_9 ( V_3 , V_34 , 0x124334 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_35 , 0x004a1a ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_36 , 0x0071c7 ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_37 ,
0x0e22ff , & V_8 ) ;
V_8 = F_9 ( V_3 , V_38 , 0x001ff8 ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_39 , 0x080003 ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_40 , 0x000004 , & V_8 ) ;
V_8 = F_11 ( V_3 , V_41 , 0x0c6c , & V_8 ) ;
V_8 = F_9 ( V_3 , V_42 , 0x000b4b , & V_8 ) ;
V_8 = F_9 ( V_3 , V_43 , 0x000600 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_43 , 0x0000c0 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_44 , 0x000819 ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_44 , 0x00085a ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_45 , 0x7fffff ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_46 , 0x2000cb ,
& V_8 ) ;
V_8 = F_9 ( V_3 , V_47 , 0x2000cb ,
& V_8 ) ;
V_8 = F_11 ( V_3 , V_48 , 0x0f80 , & V_8 ) ;
V_8 = F_11 ( V_3 , V_49 , 0x0800 ,
& V_8 ) ;
V_8 = F_11 ( V_3 , V_50 , 0x0800 , & V_8 ) ;
V_8 = F_9 ( V_3 , V_44 , 0x000905 ,
& V_8 ) ;
if ( ! V_8 )
V_22 -> V_51 = 0 ;
return V_8 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_10 ( V_3 , V_23 ,
V_24 | V_25 |
V_26 ) ;
if ( ! V_8 )
V_22 -> V_51 = 1 ;
return V_8 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
switch ( V_53 -> V_54 ) {
case V_55 :
return F_18 ( V_53 , 0 , 1 , 1 , 1 ) ;
}
return - V_56 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
switch ( V_58 -> V_54 ) {
case V_55 :
V_58 -> V_59 = V_22 -> V_51 ;
return 0 ;
}
return - V_56 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
switch ( V_58 -> V_54 ) {
case V_55 :
if ( V_58 -> V_59 )
return F_16 ( V_3 ) ;
return F_14 ( V_3 ) ;
}
return - V_56 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_4 * V_5 = F_8 ( V_3 ) ;
return F_22 ( V_5 , V_61 , V_62 , 0 ) ;
}
static int T_4 F_23 ( struct V_4 * V_5 ,
const struct V_63 * V_54 )
{
struct V_1 * V_22 ;
struct V_2 * V_3 ;
int V_8 ;
if ( ! F_24 ( V_5 -> V_13 , V_64 ) )
return - V_9 ;
F_25 ( V_5 , L_1 ,
V_5 -> V_20 << 1 , V_5 -> V_13 -> V_65 ) ;
V_22 = F_26 ( sizeof( struct V_1 ) , V_66 ) ;
if ( V_22 == NULL )
return - V_67 ;
V_3 = & V_22 -> V_3 ;
F_27 ( V_3 , V_5 , & V_68 ) ;
V_8 = F_12 ( V_3 , V_69 ) ;
if ( V_8 < 0 )
goto V_8;
if ( V_8 != V_70 )
F_28 ( V_3 , L_2 , V_8 ) ;
V_22 -> V_51 = 1 ;
V_8 = F_16 ( V_3 ) ;
if ( V_8 )
goto V_8;
return 0 ;
V_8:
F_29 ( V_3 ) ;
F_30 ( F_1 ( V_3 ) ) ;
F_31 (KERN_ERR DRIVER_NAME L_3 , err) ;
return V_8 ;
}
static int T_5 F_32 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_33 ( V_5 ) ;
F_16 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( F_1 ( V_3 ) ) ;
return 0 ;
}
