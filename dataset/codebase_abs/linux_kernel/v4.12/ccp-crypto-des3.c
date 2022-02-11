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
T_2 * V_24 = & V_9 -> V_8 . V_25 ;
const T_2 * V_26 = ( const T_2 * ) V_20 ;
if ( F_7 ( ! ( ( V_26 [ 0 ] ^ V_26 [ 2 ] ) | ( V_26 [ 1 ] ^ V_26 [ 3 ] ) ) ||
! ( ( V_26 [ 2 ] ^ V_26 [ 4 ] ) | ( V_26 [ 3 ] ^ V_26 [ 5 ] ) ) ) &&
( * V_24 & V_27 ) ) {
* V_24 |= V_28 ;
return - V_29 ;
}
V_7 -> V_12 . V_13 . type = V_30 ;
V_7 -> V_12 . V_13 . V_14 = V_23 -> V_14 ;
V_7 -> V_12 . V_13 . V_21 = V_21 ;
memcpy ( V_7 -> V_12 . V_13 . V_20 , V_20 , V_21 ) ;
F_8 ( & V_7 -> V_12 . V_13 . V_31 , V_7 -> V_12 . V_13 . V_20 , V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , bool V_32 )
{
struct V_6 * V_7 = F_3 ( V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_4 ( V_5 ) ;
struct V_33 * V_34 = NULL ;
unsigned int V_35 = 0 ;
int V_3 ;
if ( ! V_7 -> V_12 . V_13 . V_21 )
return - V_29 ;
if ( ( ( V_7 -> V_12 . V_13 . V_14 == V_15 ) ||
( V_7 -> V_12 . V_13 . V_14 == V_36 ) ) &&
( V_5 -> V_37 & ( V_18 - 1 ) ) )
return - V_29 ;
if ( V_7 -> V_12 . V_13 . V_14 != V_15 ) {
if ( ! V_5 -> V_16 )
return - V_29 ;
memcpy ( V_11 -> V_17 , V_5 -> V_16 , V_18 ) ;
V_34 = & V_11 -> V_34 ;
V_35 = V_18 ;
F_8 ( V_34 , V_11 -> V_17 , V_35 ) ;
}
memset ( & V_11 -> V_38 , 0 , sizeof( V_11 -> V_38 ) ) ;
F_10 ( & V_11 -> V_38 . V_39 ) ;
V_11 -> V_38 . V_40 = V_41 ;
V_11 -> V_38 . V_12 . V_13 . type = V_7 -> V_12 . V_13 . type ;
V_11 -> V_38 . V_12 . V_13 . V_14 = V_7 -> V_12 . V_13 . V_14 ;
V_11 -> V_38 . V_12 . V_13 . V_42 = ( V_32 )
? V_43
: V_44 ;
V_11 -> V_38 . V_12 . V_13 . V_20 = & V_7 -> V_12 . V_13 . V_31 ;
V_11 -> V_38 . V_12 . V_13 . V_21 = V_7 -> V_12 . V_13 . V_21 ;
V_11 -> V_38 . V_12 . V_13 . V_17 = V_34 ;
V_11 -> V_38 . V_12 . V_13 . V_35 = V_35 ;
V_11 -> V_38 . V_12 . V_13 . V_45 = V_5 -> V_45 ;
V_11 -> V_38 . V_12 . V_13 . V_46 = V_5 -> V_37 ;
V_11 -> V_38 . V_12 . V_13 . V_47 = V_5 -> V_47 ;
V_3 = F_11 ( & V_5 -> V_8 , & V_11 -> V_38 ) ;
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
static int F_14 ( struct V_48 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_9 ) ;
V_7 -> V_49 = F_1 ;
V_7 -> V_12 . V_13 . V_21 = 0 ;
V_9 -> V_50 . V_51 = sizeof( struct V_10 ) ;
return 0 ;
}
static void F_15 ( struct V_48 * V_9 )
{
}
static int F_16 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
struct V_22 * V_56 ;
struct V_57 * V_23 ;
int V_3 ;
V_56 = F_17 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
F_10 ( & V_56 -> V_39 ) ;
V_56 -> V_14 = V_55 -> V_14 ;
V_23 = & V_56 -> V_23 ;
* V_23 = * V_55 -> V_60 ;
snprintf ( V_23 -> V_61 , V_62 , L_1 , V_55 -> V_63 ) ;
snprintf ( V_23 -> V_64 , V_62 , L_1 ,
V_55 -> V_65 ) ;
V_23 -> V_66 = V_55 -> V_67 ;
V_23 -> V_68 . V_69 = V_55 -> V_69 ;
V_3 = F_18 ( V_23 ) ;
if ( V_3 ) {
F_19 ( L_2 ,
V_23 -> V_61 , V_3 ) ;
F_20 ( V_56 ) ;
return V_3 ;
}
F_21 ( & V_56 -> V_39 , V_53 ) ;
return 0 ;
}
int F_22 ( struct V_52 * V_53 )
{
int V_70 , V_3 ;
unsigned int V_71 = F_23 () ;
for ( V_70 = 0 ; V_70 < F_24 ( V_72 ) ; V_70 ++ ) {
if ( V_72 [ V_70 ] . V_73 > V_71 )
continue;
V_3 = F_16 ( V_53 , & V_72 [ V_70 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
