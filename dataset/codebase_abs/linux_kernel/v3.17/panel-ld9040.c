static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
int V_5 = V_4 -> error ;
V_4 -> error = 0 ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_4 , T_1 V_6 )
{
struct V_7 * V_8 = F_5 ( V_4 -> V_9 ) ;
struct V_10 V_11 = {
. V_12 = 2 ,
. V_13 = & V_6 ,
} ;
struct V_14 V_15 ;
F_6 ( & V_15 ) ;
F_7 ( & V_11 , & V_15 ) ;
return F_8 ( V_8 , & V_15 ) ;
}
static void F_9 ( struct V_1 * V_4 , const T_2 * V_6 , T_3 V_12 )
{
int V_5 = 0 ;
if ( V_4 -> error < 0 || V_12 == 0 )
return;
F_10 ( V_4 -> V_9 , L_1 , V_12 , V_6 ) ;
V_5 = F_4 ( V_4 , * V_6 ) ;
while ( ! V_5 && -- V_12 ) {
++ V_6 ;
V_5 = F_4 ( V_4 , * V_6 | 0x100 ) ;
}
if ( V_5 ) {
F_11 ( V_4 -> V_9 , L_2 , V_5 , V_12 ,
V_6 ) ;
V_4 -> error = V_5 ;
}
F_12 ( 300 , 310 ) ;
}
static void F_13 ( struct V_1 * V_4 )
{
F_9 ( V_4 , V_16 [ V_4 -> V_17 ] ,
F_14 ( V_16 [ V_4 -> V_17 ] ) ) ;
F_15 ( V_4 , V_18 , 0x02 , 0x5a ) ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_15 ( V_4 , V_19 , 0x5a , 0x5a ) ;
F_15 ( V_4 , V_20 ,
0x05 , 0x65 , 0x96 , 0x71 , 0x7d , 0x19 , 0x3b , 0x0d ,
0x19 , 0x7e , 0x0d , 0xe2 , 0x00 , 0x00 , 0x7e , 0x7d ,
0x07 , 0x07 , 0x20 , 0x20 , 0x20 , 0x02 , 0x02 ) ;
F_15 ( V_4 , V_21 ,
0x02 , 0x08 , 0x08 , 0x10 , 0x10 ) ;
F_15 ( V_4 , V_22 , 0x04 ) ;
F_15 ( V_4 , V_23 ,
0x0a , 0x87 , 0x25 , 0x6a , 0x44 , 0x02 , 0x88 ) ;
F_15 ( V_4 , V_24 , 0x0d , 0x00 , 0x16 ) ;
F_15 ( V_4 , V_25 , 0x09 , 0x00 , 0x00 ) ;
F_13 ( V_4 ) ;
F_15 ( V_4 , V_26 ) ;
F_15 ( V_4 , V_27 ) ;
}
static int F_17 ( struct V_1 * V_4 )
{
int V_5 ;
V_5 = F_18 ( F_14 ( V_4 -> V_28 ) , V_4 -> V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
F_19 ( V_4 -> V_29 ) ;
F_20 ( V_4 -> V_30 , 0 ) ;
F_19 ( V_4 -> V_31 ) ;
F_20 ( V_4 -> V_30 , 1 ) ;
F_19 ( V_4 -> V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_4 )
{
return F_22 ( F_14 ( V_4 -> V_28 ) , V_4 -> V_28 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_19 ( 120 ) ;
F_15 ( V_4 , V_32 ) ;
F_15 ( V_4 , V_33 ) ;
F_19 ( 40 ) ;
F_3 ( V_4 ) ;
return F_21 ( V_4 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
V_5 = F_17 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_16 ( V_4 ) ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 < 0 )
F_24 ( V_3 ) ;
return V_5 ;
}
static int F_26 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_34 * V_35 = V_3 -> V_35 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
V_37 = F_28 ( V_35 -> V_9 ) ;
if ( ! V_37 ) {
F_29 ( L_3 ) ;
return 0 ;
}
F_30 ( & V_4 -> V_38 , V_37 ) ;
V_37 -> V_39 = V_4 -> V_39 ;
V_37 -> V_40 = V_4 -> V_40 ;
V_35 -> V_41 . V_39 = V_37 -> V_39 ;
V_35 -> V_41 . V_40 = V_37 -> V_40 ;
V_37 -> type = V_42 | V_43 ;
F_31 ( V_35 , V_37 ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_4 )
{
struct V_44 * V_9 = V_4 -> V_9 ;
struct V_45 * V_46 = V_9 -> V_47 ;
int V_5 ;
V_5 = F_33 ( V_46 , & V_4 -> V_38 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
F_34 ( V_46 , L_4 , & V_4 -> V_29 ) ;
F_34 ( V_46 , L_5 , & V_4 -> V_31 ) ;
F_34 ( V_46 , L_6 , & V_4 -> V_39 ) ;
F_34 ( V_46 , L_7 , & V_4 -> V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_44 * V_9 = & V_8 -> V_9 ;
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_36 ( V_9 , sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
F_37 ( V_8 , V_4 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_17 = F_14 ( V_16 ) - 1 ;
V_5 = F_32 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_28 [ 0 ] . V_50 = L_8 ;
V_4 -> V_28 [ 1 ] . V_50 = L_9 ;
V_5 = F_38 ( V_9 , F_14 ( V_4 -> V_28 ) ,
V_4 -> V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_30 = F_39 ( V_9 , L_10 ) ;
if ( F_40 ( V_4 -> V_30 ) ) {
F_11 ( V_9 , L_11 ,
F_41 ( V_4 -> V_30 ) ) ;
return F_41 ( V_4 -> V_30 ) ;
}
V_5 = F_42 ( V_4 -> V_30 , 1 ) ;
if ( V_5 < 0 ) {
F_11 ( V_9 , L_12 , V_5 ) ;
return V_5 ;
}
V_8 -> V_51 = 9 ;
V_5 = F_43 ( V_8 ) ;
if ( V_5 < 0 ) {
F_11 ( V_9 , L_13 ) ;
return V_5 ;
}
F_44 ( & V_4 -> V_3 ) ;
V_4 -> V_3 . V_9 = V_9 ;
V_4 -> V_3 . V_52 = & V_53 ;
return F_45 ( & V_4 -> V_3 ) ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_4 = F_47 ( V_8 ) ;
F_21 ( V_4 ) ;
F_48 ( & V_4 -> V_3 ) ;
return 0 ;
}
