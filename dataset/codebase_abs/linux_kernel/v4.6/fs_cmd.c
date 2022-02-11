int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_6 ) ] ;
T_1 V_7 [ F_2 ( V_8 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_6 , V_5 , V_9 ,
V_10 ) ;
F_3 ( V_6 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_6 , V_5 , V_12 , V_4 -> V_13 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_5 ( struct V_1 * V_2 ,
enum V_14 type , unsigned int V_15 ,
unsigned int V_16 , struct V_3
* V_17 , unsigned int * V_12 )
{
T_1 V_7 [ F_2 ( V_18 ) ] ;
T_1 V_5 [ F_2 ( V_19 ) ] ;
int V_20 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_19 , V_5 , V_9 ,
V_21 ) ;
if ( V_17 ) {
F_3 ( V_19 , V_5 , V_22 , 1 ) ;
F_3 ( V_19 , V_5 , V_23 , V_17 -> V_13 ) ;
}
F_3 ( V_19 , V_5 , V_11 , type ) ;
F_3 ( V_19 , V_5 , V_15 , V_15 ) ;
F_3 ( V_19 , V_5 , V_16 , V_16 ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_20 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
if ( ! V_20 )
* V_12 = F_6 ( V_18 , V_7 ,
V_12 ) ;
return V_20 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ F_2 ( V_24 ) ] ;
T_1 V_7 [ F_2 ( V_25 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_24 , V_5 , V_9 ,
V_26 ) ;
F_3 ( V_24 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_24 , V_5 , V_12 , V_4 -> V_13 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_17 )
{
T_1 V_5 [ F_2 ( V_27 ) ] ;
T_1 V_7 [ F_2 ( V_28 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_27 , V_5 , V_9 ,
V_29 ) ;
F_3 ( V_27 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_27 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_27 , V_5 , V_30 ,
V_31 ) ;
if ( V_17 ) {
F_3 ( V_27 , V_5 , V_22 , 1 ) ;
F_3 ( V_27 , V_5 , V_23 , V_17 -> V_13 ) ;
} else {
F_3 ( V_27 , V_5 , V_22 , 0 ) ;
}
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_5 ,
unsigned int * V_32 )
{
int V_33 = F_10 ( V_34 ) ;
T_1 V_7 [ F_2 ( V_35 ) ] ;
int V_20 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_34 , V_5 , V_9 ,
V_36 ) ;
F_3 ( V_34 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_34 , V_5 , V_12 , V_4 -> V_13 ) ;
V_20 = F_4 ( V_2 , V_5 ,
V_33 , V_7 ,
sizeof( V_7 ) ) ;
if ( ! V_20 )
* V_32 = F_6 ( V_35 , V_7 ,
V_32 ) ;
return V_20 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_32 )
{
T_1 V_7 [ F_2 ( V_37 ) ] ;
T_1 V_5 [ F_2 ( V_38 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_38 , V_5 , V_9 ,
V_39 ) ;
F_3 ( V_38 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_38 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_38 , V_5 , V_32 , V_32 ) ;
return F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 ,
sizeof( V_7 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_40 , int V_41 ,
struct V_3 * V_4 ,
unsigned V_32 ,
struct V_42 * V_43 )
{
unsigned int V_33 = F_10 ( V_44 ) +
V_43 -> V_45 * F_10 ( V_46 ) ;
T_1 V_7 [ F_2 ( V_47 ) ] ;
struct V_48 * V_49 ;
void * V_50 ;
void * V_51 ;
void * V_52 ;
T_1 * V_5 ;
int V_20 ;
V_5 = F_13 ( V_33 ) ;
if ( ! V_5 ) {
F_14 ( V_2 , L_1 ) ;
return - V_53 ;
}
F_3 ( V_44 , V_5 , V_9 , V_54 ) ;
F_3 ( V_44 , V_5 , V_55 , V_40 ) ;
F_3 ( V_44 , V_5 , V_56 , V_41 ) ;
F_3 ( V_44 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_44 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_44 , V_5 , V_57 , V_43 -> V_58 ) ;
V_50 = F_15 ( V_44 , V_5 , V_59 ) ;
F_3 ( V_59 , V_50 , V_32 , V_32 ) ;
F_3 ( V_59 , V_50 , V_60 , V_43 -> V_60 ) ;
F_3 ( V_59 , V_50 , V_61 , V_43 -> V_61 ) ;
F_3 ( V_59 , V_50 , V_62 ,
V_43 -> V_45 ) ;
V_51 = F_15 ( V_59 , V_50 ,
V_63 ) ;
memcpy ( V_51 , & V_43 -> V_64 , F_10 ( V_65 ) ) ;
if ( V_43 -> V_61 & V_66 ) {
V_52 = F_15 ( V_59 , V_50 , V_67 ) ;
F_16 (dst, &fte->node.children, node.list) {
unsigned int V_13 ;
F_3 ( V_46 , V_52 , V_68 ,
V_49 -> V_69 . type ) ;
if ( V_49 -> V_69 . type ==
V_70 ) {
V_13 = V_49 -> V_69 . V_4 -> V_13 ;
} else {
V_13 = V_49 -> V_69 . V_71 ;
}
F_3 ( V_46 , V_52 , V_72 , V_13 ) ;
V_52 += F_10 ( V_46 ) ;
}
}
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
V_20 = F_4 ( V_2 , V_5 , V_33 , V_7 ,
sizeof( V_7 ) ) ;
F_17 ( V_5 ) ;
return V_20 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_32 ,
struct V_42 * V_43 )
{
return F_12 ( V_2 , 0 , 0 , V_4 , V_32 , V_43 ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned V_32 ,
struct V_42 * V_43 )
{
int V_40 ;
int V_41 ;
int V_73 = F_20 ( V_2 ,
V_74 .
V_75 ) ;
if ( ! V_73 )
return - V_76 ;
V_40 = 1 ;
V_41 = 1 <<
V_77 ;
return F_12 ( V_2 , V_40 , V_41 , V_4 , V_32 , V_43 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_58 )
{
T_1 V_7 [ F_2 ( V_78 ) ] ;
T_1 V_5 [ F_2 ( V_79 ) ] ;
int V_20 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_79 , V_5 , V_9 , V_80 ) ;
F_3 ( V_79 , V_5 , V_11 , V_4 -> type ) ;
F_3 ( V_79 , V_5 , V_12 , V_4 -> V_13 ) ;
F_3 ( V_79 , V_5 , V_57 , V_58 ) ;
V_20 = F_4 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
return V_20 ;
}
