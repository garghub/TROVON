static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
struct V_1 * V_9 ;
F_2 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( & V_6 -> V_11 , V_4 ) ;
if ( V_9 )
F_4 ( & V_9 -> V_12 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( ! V_9 ) {
F_6 ( V_3 , L_1 ,
V_4 ) ;
return NULL ;
}
return V_9 ;
}
void F_7 ( struct V_1 * V_9 )
{
if ( F_8 ( & V_9 -> V_12 ) )
F_9 ( & V_9 -> free ) ;
}
void F_10 ( struct V_2 * V_3 , T_1 V_4 , int V_13 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_4 ) ;
struct V_14 * V_15 ;
if ( ! V_9 )
return;
switch ( V_9 -> V_16 ) {
case V_17 :
V_15 = (struct V_14 * ) V_9 ;
V_15 -> V_18 ( V_15 , V_13 ) ;
break;
default:
F_6 ( V_3 , L_2 , V_4 ) ;
}
F_7 ( V_9 ) ;
}
int F_11 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
int V_21 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
struct V_22 V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
int V_28 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_20 -> V_29 . V_30 = F_12 ( V_31 ) ;
V_28 = F_13 ( V_3 , V_20 , V_21 , & V_23 , sizeof( V_23 ) ) ;
if ( V_28 ) {
F_6 ( V_3 , L_3 , V_28 ) ;
return V_28 ;
}
if ( V_23 . V_29 . V_32 ) {
F_6 ( V_3 , L_4 ,
F_14 ( & V_3 -> V_33 ) ) ;
return F_15 ( & V_23 . V_29 ) ;
}
V_15 -> V_34 = F_16 ( V_23 . V_34 ) & 0xffffff ;
F_17 ( V_3 , L_5 , V_15 -> V_34 ) ;
V_15 -> V_9 . V_16 = V_17 ;
F_18 ( & V_6 -> V_10 ) ;
V_28 = F_19 ( & V_6 -> V_11 , V_15 -> V_34 , V_15 ) ;
F_20 ( & V_6 -> V_10 ) ;
if ( V_28 ) {
F_6 ( V_3 , L_6 , V_28 ) ;
goto V_35;
}
V_28 = F_21 ( V_3 , V_15 ) ;
if ( V_28 )
F_17 ( V_3 , L_7 ,
V_15 -> V_34 ) ;
V_15 -> V_36 = V_37 -> V_36 ;
F_22 ( & V_15 -> V_9 . V_12 , 1 ) ;
F_4 ( & V_3 -> V_33 ) ;
F_23 ( & V_15 -> V_9 . free ) ;
return 0 ;
V_35:
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_25 . V_29 . V_30 = F_12 ( V_38 ) ;
V_25 . V_34 = F_24 ( V_15 -> V_34 ) ;
F_13 ( V_3 , & V_25 , sizeof( V_25 ) , & V_23 , sizeof( V_27 ) ) ;
return V_28 ;
}
int F_25 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_24 V_20 ;
struct V_26 V_23 ;
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
unsigned long V_39 ;
int V_28 ;
F_26 ( V_3 , V_15 ) ;
F_27 ( & V_6 -> V_10 , V_39 ) ;
F_28 ( & V_6 -> V_11 , V_15 -> V_34 ) ;
F_29 ( & V_6 -> V_10 , V_39 ) ;
F_7 ( (struct V_1 * ) V_15 ) ;
F_30 ( & V_15 -> V_9 . free ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_20 . V_29 . V_30 = F_12 ( V_38 ) ;
V_20 . V_34 = F_24 ( V_15 -> V_34 ) ;
V_28 = F_13 ( V_3 , & V_20 , sizeof( V_20 ) , & V_23 , sizeof( V_23 ) ) ;
if ( V_28 )
return V_28 ;
if ( V_23 . V_29 . V_32 )
return F_15 ( & V_23 . V_29 ) ;
F_31 ( & V_3 -> V_33 ) ;
return 0 ;
}
int F_32 ( struct V_2 * V_3 , enum V_40 V_41 ,
enum V_40 V_42 ,
struct V_43 * V_20 , int V_44 ,
struct V_14 * V_15 )
{
static const T_2 V_45 [ V_46 ] [ V_46 ] = {
[ V_47 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
[ V_51 ] = V_52 ,
} ,
[ V_51 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
[ V_51 ] = V_53 ,
[ V_54 ] = V_55 ,
} ,
[ V_54 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
[ V_56 ] = V_57 ,
} ,
[ V_56 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
[ V_56 ] = V_58 ,
} ,
[ V_59 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
} ,
[ V_60 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
[ V_56 ] = V_61 ,
} ,
[ V_49 ] = {
[ V_47 ] = V_48 ,
[ V_49 ] = V_50 ,
}
} ;
struct V_62 V_23 ;
int V_28 = 0 ;
T_2 V_63 ;
if ( V_41 >= V_46 || V_42 >= V_46 ||
! V_45 [ V_41 ] [ V_42 ] )
return - V_64 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_63 = V_45 [ V_41 ] [ V_42 ] ;
V_20 -> V_29 . V_30 = F_12 ( V_63 ) ;
V_20 -> V_34 = F_24 ( V_15 -> V_34 ) ;
V_28 = F_13 ( V_3 , V_20 , sizeof( * V_20 ) , & V_23 , sizeof( V_23 ) ) ;
if ( V_28 )
return V_28 ;
return F_15 ( & V_23 . V_29 ) ;
}
void F_33 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
F_34 ( & V_6 -> V_10 ) ;
F_35 ( & V_6 -> V_11 , V_65 ) ;
F_36 ( V_3 ) ;
}
void F_37 ( struct V_2 * V_3 )
{
F_38 ( V_3 ) ;
}
int F_39 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_66 * V_23 , int V_67 )
{
struct V_68 V_20 ;
int V_28 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( V_23 , 0 , V_67 ) ;
V_20 . V_29 . V_30 = F_12 ( V_69 ) ;
V_20 . V_34 = F_24 ( V_15 -> V_34 ) ;
V_28 = F_13 ( V_3 , & V_20 , sizeof( V_20 ) , V_23 , V_67 ) ;
if ( V_28 )
return V_28 ;
if ( V_23 -> V_29 . V_32 )
return F_15 ( & V_23 -> V_29 ) ;
return V_28 ;
}
int F_40 ( struct V_2 * V_3 , T_1 * V_70 )
{
struct V_71 V_20 ;
struct V_72 V_23 ;
int V_28 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_20 . V_29 . V_30 = F_12 ( V_73 ) ;
V_28 = F_13 ( V_3 , & V_20 , sizeof( V_20 ) , & V_23 , sizeof( V_23 ) ) ;
if ( V_28 )
return V_28 ;
if ( V_23 . V_29 . V_32 )
V_28 = F_15 ( & V_23 . V_29 ) ;
else
* V_70 = F_16 ( V_23 . V_70 ) ;
return V_28 ;
}
int F_41 ( struct V_2 * V_3 , T_1 V_70 )
{
struct V_74 V_20 ;
struct V_75 V_23 ;
int V_28 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_20 . V_29 . V_30 = F_12 ( V_76 ) ;
V_20 . V_70 = F_24 ( V_70 ) ;
V_28 = F_13 ( V_3 , & V_20 , sizeof( V_20 ) , & V_23 , sizeof( V_23 ) ) ;
if ( V_28 )
return V_28 ;
if ( V_23 . V_29 . V_32 )
V_28 = F_15 ( & V_23 . V_29 ) ;
return V_28 ;
}
