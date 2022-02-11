static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_4 * V_6 ,
struct V_7 * V_8 ,
bool * V_9 )
{
if ( ( ( V_8 -> V_10 [ 0 ] == V_11 ) &&
( V_8 -> V_10 [ 1 ] == V_12 ) ) ) {
* V_9 = TRUE ;
if ( V_1 -> V_13 != V_14 ) {
V_5 -> V_15 = false ;
F_2 ( V_6 , V_16 , V_17 ,
V_18 ,
L_1 ) ;
F_3 ( & V_5 -> V_19 ) ;
F_4 ( V_3 ) ;
return;
}
if ( V_5 -> V_20 == false ) {
V_5 -> V_21 = TRUE ;
V_5 -> V_15 = false ;
F_2 ( V_6 , V_16 , V_17 ,
V_18 ,
L_2 ) ;
F_3 ( & V_5 -> V_19 ) ;
}
} else if ( ( V_8 -> V_22 . V_23 == V_24 ) &&
( V_8 -> V_10 [ 0 ] == V_25 ) &&
( V_8 -> V_10 [ 1 ] == V_26 ) &&
( V_8 -> V_10 [ 2 ] == V_27 ) ) {
if ( V_1 -> V_13 != V_14 ) {
V_5 -> V_15 = false ;
F_2 ( V_6 , V_16 , V_17 ,
V_18 ,
L_3 ) ;
F_3 ( & V_5 -> V_19 ) ;
F_4 ( V_3 ) ;
return;
}
* V_9 = TRUE ;
if ( V_5 -> V_20 == false ) {
V_5 -> V_28 = TRUE ;
V_5 -> V_15 = false ;
F_2 ( V_6 , V_16 , V_17 ,
V_18 ,
L_4 ) ;
F_3 ( & V_5 -> V_19 ) ;
}
}
if ( V_5 -> V_20 && * V_9 ) {
F_2 ( V_6 , V_16 , V_17 , V_18 ,
L_5 ) ;
V_3 -> V_29 = TRUE ;
F_5 ( & V_3 -> V_30 ) ;
}
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_31 * V_32 = (struct V_31 * ) V_1 -> V_33 ;
struct V_2 * V_34 = V_32 -> V_34 ;
struct V_7 * V_35 =
(struct V_7 * ) V_1 -> V_36 ;
struct V_4 * V_37 = V_34 -> V_37 ;
bool V_38 = false ;
struct V_4 * V_39 = F_7 ( V_40 ) ;
if ( F_8 ( F_9 ( V_39 ) ) )
F_10 ( V_41 L_6 , V_39 -> V_42 -> V_43 ,
V_1 -> V_13 ) ;
if ( V_1 -> V_13 != V_14 ) {
if ( V_1 -> V_13 == - V_44 ) {
V_34 -> V_37 -> V_45 = TRUE ;
F_3 ( & V_34 -> V_37 -> V_46 ) ;
} else {
F_2 ( V_39 , V_16 , V_17 ,
V_18 ,
L_7 ,
V_1 -> V_13 ) ;
}
}
V_32 -> V_47 = false ;
F_11 ( & V_34 -> V_48 ) ;
if ( TRUE == V_37 -> V_15 ) {
F_1 ( V_1 , V_34 , V_37 , V_39 ,
V_35 , & V_38 ) ;
}
F_12 ( V_1 -> V_42 , V_1 -> V_49 ,
V_1 -> V_36 , V_1 -> V_50 ) ;
}
static struct V_31 * F_13 ( struct V_2 * V_34 )
{
struct V_31 * V_32 = NULL ;
T_1 V_51 = 0 ;
if ( ( F_14 ( & V_34 -> V_48 ) < V_52 ) &&
( V_34 -> V_37 -> V_53 == false ) ) {
V_51 = F_14 ( & V_34 -> V_54 ) ;
V_32 = & V_34 -> V_55 [ V_51 ] ;
V_32 -> V_47 = TRUE ;
V_32 -> V_34 = V_34 ;
F_2 ( V_34 -> V_37 , V_16 ,
V_17 , V_18 ,
L_8 ,
V_51 ,
F_14 ( & V_34 -> V_48 ) ) ;
V_51 = ( V_51 + 1 ) % V_52 ;
F_15 ( & V_34 -> V_54 , V_51 ) ;
F_16 ( & V_34 -> V_48 ) ;
}
return V_32 ;
}
static int F_17 ( struct V_2 * V_34 ,
struct V_31 * V_32 , T_2 V_56 , int V_57 )
{
struct V_1 * V_1 = V_32 -> V_1 ;
int V_58 = 0 ;
V_1 -> V_36 = F_18 ( V_34 -> V_59 , V_57 ,
V_60 , & V_1 -> V_50 ) ;
if ( ! V_1 -> V_36 ) {
F_2 ( V_34 -> V_37 , V_61 , 0 , 0 ,
L_9 ) ;
return - V_62 ;
}
memcpy ( V_1 -> V_36 , V_56 , V_57 ) ;
V_1 -> V_49 = V_57 ;
F_2 ( V_34 -> V_37 , V_16 , V_17 ,
V_18 , L_10 ) ;
if ( ( V_34 -> V_37 -> V_63 == V_64 ) &&
( V_34 -> V_65 == TRUE ) ) {
F_19 ( V_1 , V_34 -> V_59 ,
V_34 -> V_66 . V_67 ,
V_1 -> V_36 , V_57 , F_6 , V_32 ,
V_34 -> V_66 . V_68 ) ;
} else {
F_20 ( V_1 , V_34 -> V_59 ,
V_34 -> V_66 . V_67 ,
V_1 -> V_36 , V_57 , F_6 , V_32 ) ;
}
V_1 -> V_69 |= V_70 ;
if ( false == V_34 -> V_37 -> V_71 &&
false == V_34 -> V_37 -> V_45 &&
false == V_34 -> V_72 &&
false == V_34 -> V_29 ) {
V_58 = F_21 ( V_1 , V_60 ) ;
if ( V_58 ) {
F_2 ( V_34 -> V_37 , V_16 ,
V_17 , V_18 ,
L_11 ,
V_58 ) ;
if ( V_58 == - V_44 ) {
V_34 -> V_37 -> V_45 = TRUE ;
F_3 ( & V_34 -> V_37 -> V_46 ) ;
}
}
}
return V_58 ;
}
int F_22 ( T_2 V_73 , T_2 V_56 , T_1 V_57 )
{
struct V_31 * V_32 = NULL ;
struct V_2 * V_34 = V_73 ;
V_32 = F_13 ( V_34 ) ;
if ( V_32 == NULL ) {
F_2 ( V_34 -> V_37 , V_61 , 0 , 0 ,
L_12 ) ;
return - V_74 ;
}
return F_17 ( V_34 , V_32 , V_56 , V_57 ) ;
}
