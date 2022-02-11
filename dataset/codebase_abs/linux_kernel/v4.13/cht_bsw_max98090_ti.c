static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 ,
V_12 , V_13 ) ;
if ( V_10 < 0 ) {
F_3 ( V_6 -> V_14 , L_1 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
struct V_21 * V_22 = & V_20 -> V_23 -> V_22 ;
if ( V_17 & V_24 ) {
F_5 ( V_22 , L_2 ) ;
F_5 ( V_22 , L_3 ) ;
F_6 ( V_22 ) ;
} else {
F_7 ( V_22 , L_3 ) ;
F_7 ( V_22 , L_2 ) ;
F_6 ( V_22 ) ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_25 )
{
int V_10 ;
int V_26 ;
struct V_27 * V_28 = F_9 ( V_25 -> V_23 ) ;
struct V_19 * V_20 = & V_28 -> V_20 ;
if ( V_28 -> V_29 )
V_26 = V_30 | V_24 |
V_31 | V_32 |
V_33 | V_34 ;
else
V_26 = V_30 | V_24 ;
V_10 = F_10 ( V_25 -> V_23 , L_4 ,
V_26 , V_20 , NULL , 0 ) ;
if ( V_10 ) {
F_3 ( V_25 -> V_14 , L_5 , V_10 ) ;
return V_10 ;
}
if ( V_28 -> V_29 )
F_11 ( V_20 , & V_35 ) ;
return V_10 ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 = F_13 ( V_4 ,
V_38 ) ;
struct V_36 * V_39 = F_13 ( V_4 ,
V_40 ) ;
int V_10 = 0 ;
unsigned int V_41 = 0 ;
V_10 = F_14 ( V_6 -> V_42 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_10 < 0 ) {
F_3 ( V_6 -> V_14 , L_6 , V_10 ) ;
return V_10 ;
}
V_41 = V_43 | V_44
| V_45 ;
V_10 = F_15 ( V_6 -> V_42 , V_41 ) ;
if ( V_10 < 0 ) {
F_3 ( V_6 -> V_14 , L_7 , V_10 ) ;
return V_10 ;
}
V_37 -> V_46 = V_37 -> V_47 = 48000 ;
V_39 -> V_46 = V_39 -> V_47 = 2 ;
F_16 ( V_4 , V_48 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_18 ( V_2 -> V_25 ,
V_38 , 48000 ) ;
}
static int F_19 ( struct V_49 * V_50 )
{
struct V_51 * V_23 = V_50 -> V_23 ;
struct V_27 * V_28 = F_9 ( V_23 ) ;
return F_20 ( V_50 , & V_28 -> V_20 ) ;
}
static int F_21 ( struct V_52 * V_53 )
{
int V_54 = 0 ;
struct V_27 * V_55 ;
V_55 = F_22 ( & V_53 -> V_14 , sizeof( * V_55 ) , V_56 ) ;
if ( ! V_55 )
return - V_57 ;
V_55 -> V_29 = F_23 ( L_8 ) ;
if ( ! V_55 -> V_29 ) {
V_58 . V_59 = NULL ;
V_58 . V_60 = 0 ;
}
V_58 . V_14 = & V_53 -> V_14 ;
F_24 ( & V_58 , V_55 ) ;
V_54 = F_25 ( & V_53 -> V_14 , & V_58 ) ;
if ( V_54 ) {
F_3 ( & V_53 -> V_14 ,
L_9 , V_54 ) ;
return V_54 ;
}
F_26 ( V_53 , & V_58 ) ;
return V_54 ;
}
