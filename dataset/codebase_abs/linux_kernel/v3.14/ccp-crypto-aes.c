static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
if ( V_3 )
return V_3 ;
if ( V_7 -> V_12 . V_13 . V_14 != V_15 )
memcpy ( V_5 -> V_16 , V_11 -> V_17 , V_18 ) ;
return 0 ;
}
static int F_5 ( struct V_19 * V_9 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_6 * V_7 = F_3 ( F_6 ( V_9 ) ) ;
struct V_22 * V_23 =
V_22 ( F_6 ( V_9 ) ) ;
switch ( V_21 ) {
case V_24 :
V_7 -> V_12 . V_13 . type = V_25 ;
break;
case V_26 :
V_7 -> V_12 . V_13 . type = V_27 ;
break;
case V_28 :
V_7 -> V_12 . V_13 . type = V_29 ;
break;
default:
F_7 ( V_9 , V_30 ) ;
return - V_31 ;
}
V_7 -> V_12 . V_13 . V_14 = V_23 -> V_14 ;
V_7 -> V_12 . V_13 . V_21 = V_21 ;
memcpy ( V_7 -> V_12 . V_13 . V_20 , V_20 , V_21 ) ;
F_8 ( & V_7 -> V_12 . V_13 . V_32 , V_7 -> V_12 . V_13 . V_20 , V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , bool V_33 )
{
struct V_6 * V_7 = F_3 ( V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
struct V_34 * V_35 = NULL ;
unsigned int V_36 = 0 ;
int V_3 ;
if ( ! V_7 -> V_12 . V_13 . V_21 )
return - V_31 ;
if ( ( ( V_7 -> V_12 . V_13 . V_14 == V_15 ) ||
( V_7 -> V_12 . V_13 . V_14 == V_37 ) ||
( V_7 -> V_12 . V_13 . V_14 == V_38 ) ) &&
( V_5 -> V_39 & ( V_18 - 1 ) ) )
return - V_31 ;
if ( V_7 -> V_12 . V_13 . V_14 != V_15 ) {
if ( ! V_5 -> V_16 )
return - V_31 ;
memcpy ( V_11 -> V_17 , V_5 -> V_16 , V_18 ) ;
V_35 = & V_11 -> V_35 ;
V_36 = V_18 ;
F_8 ( V_35 , V_11 -> V_17 , V_36 ) ;
}
memset ( & V_11 -> V_40 , 0 , sizeof( V_11 -> V_40 ) ) ;
F_10 ( & V_11 -> V_40 . V_41 ) ;
V_11 -> V_40 . V_42 = V_43 ;
V_11 -> V_40 . V_12 . V_13 . type = V_7 -> V_12 . V_13 . type ;
V_11 -> V_40 . V_12 . V_13 . V_14 = V_7 -> V_12 . V_13 . V_14 ;
V_11 -> V_40 . V_12 . V_13 . V_44 =
( V_33 ) ? V_45 : V_46 ;
V_11 -> V_40 . V_12 . V_13 . V_20 = & V_7 -> V_12 . V_13 . V_32 ;
V_11 -> V_40 . V_12 . V_13 . V_21 = V_7 -> V_12 . V_13 . V_21 ;
V_11 -> V_40 . V_12 . V_13 . V_17 = V_35 ;
V_11 -> V_40 . V_12 . V_13 . V_36 = V_36 ;
V_11 -> V_40 . V_12 . V_13 . V_47 = V_5 -> V_47 ;
V_11 -> V_40 . V_12 . V_13 . V_48 = V_5 -> V_39 ;
V_11 -> V_40 . V_12 . V_13 . V_49 = V_5 -> V_49 ;
V_3 = F_11 ( & V_5 -> V_8 , & V_11 -> V_40 ) ;
return V_3 ;
}
static int F_12 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , true ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , false ) ;
}
static int F_14 ( struct V_50 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_9 ) ;
V_7 -> V_51 = F_1 ;
V_7 -> V_12 . V_13 . V_21 = 0 ;
V_9 -> V_52 . V_53 = sizeof( struct V_10 ) ;
return 0 ;
}
static void F_15 ( struct V_50 * V_9 )
{
}
static int F_16 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
V_5 -> V_16 = V_11 -> V_54 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_17 ( struct V_19 * V_9 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_6 * V_7 = F_3 ( F_6 ( V_9 ) ) ;
if ( V_21 < V_55 )
return - V_31 ;
V_21 -= V_55 ;
memcpy ( V_7 -> V_12 . V_13 . V_56 , V_20 + V_21 , V_55 ) ;
return F_5 ( V_9 , V_20 , V_21 ) ;
}
static int F_18 ( struct V_4 * V_5 , bool V_33 )
{
struct V_6 * V_7 = F_3 ( V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
T_1 * V_17 ;
V_17 = V_11 -> V_57 ;
memcpy ( V_17 , V_7 -> V_12 . V_13 . V_56 , V_55 ) ;
V_17 += V_55 ;
memcpy ( V_17 , V_5 -> V_16 , V_58 ) ;
V_17 += V_58 ;
* ( V_59 * ) V_17 = F_19 ( 1 ) ;
V_11 -> V_54 = V_5 -> V_16 ;
V_5 -> V_16 = V_11 -> V_57 ;
return F_9 ( V_5 , V_33 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_18 ( V_5 , true ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
return F_18 ( V_5 , false ) ;
}
static int F_22 ( struct V_50 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_9 ) ;
V_7 -> V_51 = F_16 ;
V_7 -> V_12 . V_13 . V_21 = 0 ;
V_9 -> V_52 . V_53 = sizeof( struct V_10 ) ;
return 0 ;
}
static void F_23 ( struct V_50 * V_9 )
{
}
static int F_24 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_22 * V_64 ;
struct V_65 * V_23 ;
int V_3 ;
V_64 = F_25 ( sizeof( * V_64 ) , V_66 ) ;
if ( ! V_64 )
return - V_67 ;
F_10 ( & V_64 -> V_41 ) ;
V_64 -> V_14 = V_63 -> V_14 ;
V_23 = & V_64 -> V_23 ;
* V_23 = * V_63 -> V_68 ;
snprintf ( V_23 -> V_69 , V_70 , L_1 , V_63 -> V_71 ) ;
snprintf ( V_23 -> V_72 , V_70 , L_1 ,
V_63 -> V_73 ) ;
V_23 -> V_74 = V_63 -> V_75 ;
V_23 -> V_76 . V_77 = V_63 -> V_77 ;
V_3 = F_26 ( V_23 ) ;
if ( V_3 ) {
F_27 ( L_2 ,
V_23 -> V_69 , V_3 ) ;
F_28 ( V_64 ) ;
return V_3 ;
}
F_29 ( & V_64 -> V_41 , V_61 ) ;
return 0 ;
}
int F_30 ( struct V_60 * V_61 )
{
int V_78 , V_3 ;
for ( V_78 = 0 ; V_78 < F_31 ( V_79 ) ; V_78 ++ ) {
V_3 = F_24 ( V_61 , & V_79 [ V_78 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
