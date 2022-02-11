static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , int V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
int V_12 ;
if ( V_8 < 0 || V_8 >= V_13 ) {
F_6 ( V_3 , L_1 , V_8 ) ;
return - 1 ;
}
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ )
if ( F_7 ( V_11 ,
( V_8 << 1 ) | ( V_9 >> 8 ) , V_9 & 0xff ) == 0 )
return 0 ;
F_6 ( V_3 , L_2 , V_9 , V_8 ) ;
return - 1 ;
}
static void F_8 ( struct V_2 * V_3 , int V_14 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
T_2 V_16 , V_17 ;
int V_18 = 0 != V_15 -> V_19 -> V_9 ;
T_1 V_20 = ( T_1 ) V_15 -> V_21 -> V_9 ;
T_1 V_22 = ( T_1 ) V_15 -> V_23 -> V_9 ;
V_16 = ( F_9 ( 65536 - V_22 , 32768 ) * V_20 ) >> 23 ;
V_17 = ( F_9 ( V_22 , ( T_1 ) 32768 ) * V_20 ) >> 23 ;
if ( V_18 || V_14 )
F_4 ( V_3 , V_24 , 0x0c0 | V_15 -> V_25 ) ;
F_4 ( V_3 , V_26 , V_16 | 0x100 ) ;
F_4 ( V_3 , V_27 , V_17 | 0x100 ) ;
if ( ! V_18 )
F_4 ( V_3 , V_24 , V_15 -> V_25 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
T_3 V_25 , T_3 V_28 , T_3 V_29 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
if ( V_25 > 15 ) {
F_6 ( V_3 , L_3 , V_25 ) ;
return - V_30 ;
}
V_15 -> V_25 = V_25 ;
if ( ! F_11 ( V_15 -> V_19 ) )
return 0 ;
if ( ! F_11 ( V_15 -> V_21 ) )
return 0 ;
if ( ! F_11 ( V_15 -> V_23 ) )
return 0 ;
F_8 ( V_3 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
F_8 ( V_3 , 0 ) ;
return 0 ;
case V_35 :
F_4 ( V_3 , V_36 , ( V_5 -> V_9 ? V_37 : 0 ) | V_38 ) ;
return 0 ;
}
return - V_30 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_14 ( V_11 , V_40 , V_41 , 0 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = F_1 ( V_3 ) ;
F_16 ( V_3 , L_4 , V_15 -> V_25 ) ;
F_17 ( & V_15 -> V_7 , V_3 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , const struct V_43 * V_44 )
{
F_8 ( V_3 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 ,
const struct V_45 * V_31 )
{
struct V_1 * V_15 ;
struct V_2 * V_3 ;
int V_46 ;
bool V_47 = false ;
if ( V_11 -> V_48 . V_49 ) {
struct V_50 * V_51 = V_11 -> V_48 . V_49 ;
V_47 = V_51 -> V_47 ;
}
if ( ! F_20 ( V_11 -> V_52 , V_53 ) )
return - V_54 ;
F_21 ( V_11 , L_5 ,
V_11 -> V_55 << 1 , V_11 -> V_52 -> V_42 ) ;
V_15 = F_22 ( sizeof( struct V_1 ) , V_56 ) ;
if ( V_15 == NULL )
return - V_57 ;
V_3 = & V_15 -> V_3 ;
F_23 ( V_3 , V_11 , & V_58 ) ;
V_15 -> V_25 = 2 ;
F_24 ( & V_15 -> V_7 , 4 ) ;
V_15 -> V_19 = F_25 ( & V_15 -> V_7 , & V_59 ,
V_32 , 0 , 1 , 1 , 0 ) ;
V_15 -> V_21 = F_25 ( & V_15 -> V_7 , & V_59 ,
V_33 , 0 , 65535 , ( 65535 + 99 ) / 100 , 0xCF00 ) ;
V_15 -> V_23 = F_25 ( & V_15 -> V_7 , & V_59 ,
V_34 , 0 , 65535 , ( 65535 + 99 ) / 100 , 32768 ) ;
V_15 -> V_60 = F_25 ( & V_15 -> V_7 , & V_59 ,
V_35 , 0 , 1 , 1 , 1 ) ;
V_3 -> V_61 = & V_15 -> V_7 ;
V_46 = V_15 -> V_7 . error ;
if ( V_46 ) {
F_26 ( & V_15 -> V_7 ) ;
F_27 ( V_15 ) ;
return V_46 ;
}
F_4 ( V_3 , V_62 , 0x000 ) ;
F_4 ( V_3 , V_63 , 0x000 ) ;
F_4 ( V_3 , V_64 , 0x021 ) ;
F_4 ( V_3 , V_65 , 0x102 ) ;
F_4 ( V_3 , V_66 , 0x000 ) ;
if ( ! V_47 ) {
F_4 ( V_3 , V_26 , 0x1d4 ) ;
F_4 ( V_3 , V_27 , 0x1d4 ) ;
F_4 ( V_3 , V_67 , 0x1bf ) ;
F_4 ( V_3 , V_36 , 0x185 ) ;
} else {
F_4 ( V_3 , V_67 , 0x1bb ) ;
F_4 ( V_3 , V_36 , ( V_15 -> V_60 -> V_9 ? V_37 : 0 ) | V_38 ) ;
}
F_4 ( V_3 , V_68 , 0x0a2 ) ;
F_4 ( V_3 , V_69 , 0x005 ) ;
if ( ! V_47 ) {
F_4 ( V_3 , V_70 , 0x07a ) ;
F_4 ( V_3 , V_24 , 0x102 ) ;
} else {
F_4 ( V_3 , V_70 , 0x0fb ) ;
F_8 ( V_3 , 1 ) ;
}
return 0 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_29 ( V_11 ) ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
F_30 ( V_3 ) ;
F_26 ( & V_15 -> V_7 ) ;
F_27 ( V_15 ) ;
return 0 ;
}
