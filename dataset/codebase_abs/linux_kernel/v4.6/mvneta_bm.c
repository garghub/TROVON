static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , F_6 ( V_6 ) ) ;
V_7 |= V_8 ;
F_1 ( V_2 , F_6 ( V_6 ) , V_7 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , F_6 ( V_6 ) ) ;
V_7 &= ~ V_8 ;
F_1 ( V_2 , F_6 ( V_6 ) , V_7 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 |= V_10 ;
F_1 ( V_2 , V_11 , V_7 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 &= ~ V_10 ;
F_1 ( V_2 , V_11 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_6 ,
T_2 V_12 , T_2 V_13 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , F_11 ( V_6 ) ) ;
V_7 &= ~ F_12 ( V_6 ) ;
V_7 &= ~ F_13 ( V_6 ) ;
V_7 |= F_14 ( V_6 , V_12 ) ;
V_7 |= F_15 ( V_6 , V_13 ) ;
F_1 ( V_2 , F_11 ( V_6 ) , V_7 ) ;
}
int F_16 ( struct V_14 * V_14 , void * V_15 )
{
struct V_16 * V_17 =
(struct V_16 * ) V_14 -> V_2 ;
struct V_1 * V_2 = V_17 -> V_2 ;
T_3 V_18 ;
* ( T_1 * ) V_15 = ( T_1 ) V_15 ;
V_18 = F_17 ( & V_2 -> V_19 -> V_20 , V_15 , V_17 -> V_21 ,
V_22 ) ;
if ( F_18 ( F_19 ( & V_2 -> V_19 -> V_20 , V_18 ) ) )
return - V_23 ;
F_20 ( V_2 , V_17 , V_18 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_24 * V_19 = V_2 -> V_19 ;
T_2 V_12 , V_13 ;
int V_25 , V_26 ;
V_25 = sizeof( T_1 ) * V_17 -> V_14 . V_27 ;
V_17 -> V_28 = F_22 ( & V_19 -> V_20 , V_25 ,
& V_17 -> V_18 ,
V_29 ) ;
if ( ! V_17 -> V_28 )
return - V_23 ;
if ( ! F_23 ( ( T_1 ) V_17 -> V_28 , V_30 ) ) {
F_24 ( & V_19 -> V_20 , V_25 , V_17 -> V_28 ,
V_17 -> V_18 ) ;
F_25 ( & V_19 -> V_20 , L_1 ,
V_17 -> V_31 , V_30 ) ;
return - V_23 ;
}
V_26 = F_26 ( V_17 -> V_18 , & V_12 ,
& V_13 ) ;
if ( V_26 < 0 ) {
F_24 ( & V_19 -> V_20 , V_25 , V_17 -> V_28 ,
V_17 -> V_18 ) ;
return V_26 ;
}
F_1 ( V_2 , F_6 ( V_17 -> V_31 ) ,
V_17 -> V_18 ) ;
F_10 ( V_2 , V_17 -> V_31 , V_12 , V_13 ) ;
F_5 ( V_2 , V_17 -> V_31 ) ;
return 0 ;
}
struct V_16 * F_27 ( struct V_1 * V_2 , T_2 V_6 ,
enum V_32 type , T_2 V_33 ,
int V_34 )
{
struct V_16 * V_35 = & V_2 -> V_36 [ V_6 ] ;
int V_37 , V_26 ;
if ( V_35 -> type == V_38 &&
V_35 -> V_39 != 1 << V_33 ) {
F_25 ( & V_2 -> V_19 -> V_20 ,
L_2 ) ;
return NULL ;
}
if ( V_35 -> type == V_40 && V_35 -> type != type ) {
F_25 ( & V_2 -> V_19 -> V_20 ,
L_3 ) ;
return NULL ;
}
if ( V_35 -> V_34 == 0 || type != V_40 )
V_35 -> V_34 = V_34 ;
if ( V_35 -> type == V_41 ) {
struct V_14 * V_14 = & V_35 -> V_14 ;
V_35 -> V_2 = V_2 ;
V_35 -> type = type ;
V_35 -> V_21 = F_28 ( V_35 -> V_34 ) ;
V_14 -> V_42 =
F_29 ( F_28 ( V_35 -> V_34 ) ) +
F_29 ( sizeof( struct V_43 ) ) ;
V_14 -> V_44 = F_16 ;
V_14 -> V_2 = V_35 ;
V_26 = F_21 ( V_2 , V_35 ) ;
if ( V_26 ) {
F_25 ( & V_2 -> V_19 -> V_20 , L_4 ,
V_35 -> V_31 ) ;
return NULL ;
}
V_37 = F_30 ( V_14 , V_14 -> V_27 , V_45 ) ;
if ( V_37 != V_14 -> V_27 ) {
F_31 ( 1 , L_5 ,
V_35 -> V_31 , V_37 , V_14 -> V_27 ) ;
return NULL ;
}
}
return V_35 ;
}
void F_32 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_2 V_39 )
{
int V_46 ;
V_17 -> V_39 &= ~ V_39 ;
if ( V_17 -> V_39 )
return;
F_8 ( V_2 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_17 -> V_14 . V_48 ; V_46 ++ ) {
T_3 V_49 ;
T_1 * V_50 ;
V_49 = F_33 ( V_2 , V_17 ) ;
if ( V_49 == 0 )
continue;
V_50 = F_34 ( V_49 ) ;
if ( ! V_50 )
break;
F_35 ( & V_2 -> V_19 -> V_20 , V_49 ,
V_17 -> V_21 , V_22 ) ;
F_36 ( & V_17 -> V_14 , V_50 ) ;
}
F_9 ( V_2 , V_47 ) ;
V_17 -> V_14 . V_48 -= V_46 ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_2 V_39 )
{
struct V_14 * V_14 = & V_17 -> V_14 ;
V_17 -> V_39 &= ~ V_39 ;
if ( V_17 -> V_39 )
return;
V_17 -> type = V_41 ;
F_32 ( V_2 , V_17 , V_39 ) ;
if ( V_14 -> V_48 )
F_31 ( 1 , L_6 , V_17 -> V_31 ) ;
if ( V_17 -> V_28 ) {
F_24 ( & V_2 -> V_19 -> V_20 ,
sizeof( T_1 ) * V_14 -> V_27 ,
V_17 -> V_28 , V_17 -> V_18 ) ;
V_17 -> V_28 = NULL ;
}
F_7 ( V_2 , V_17 -> V_31 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = V_2 -> V_19 -> V_20 . V_53 ;
struct V_16 * V_17 ;
char V_54 [ 15 ] ;
T_1 V_27 ;
int V_46 ;
F_1 ( V_2 , V_55 , V_56 ) ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ ) {
V_17 = & V_2 -> V_36 [ V_46 ] ;
V_17 -> V_31 = V_46 ;
V_17 -> type = V_41 ;
F_1 ( V_2 , F_39 ( V_46 ) , 0 ) ;
F_1 ( V_2 , F_40 ( V_46 ) , 0 ) ;
sprintf ( V_54 , L_7 , V_46 ) ;
if ( F_41 ( V_52 , V_54 , & V_27 ) ) {
V_27 = V_58 ;
} else if ( V_27 > V_59 ) {
F_42 ( & V_2 -> V_19 -> V_20 ,
L_8 ,
V_46 , V_27 , V_59 ) ;
V_27 = V_59 ;
} else if ( V_27 < V_60 ) {
F_42 ( & V_2 -> V_19 -> V_20 ,
L_8 ,
V_46 , V_27 , V_60 ) ;
V_27 = V_60 ;
} else if ( ! F_23 ( V_27 , V_61 ) ) {
F_42 ( & V_2 -> V_19 -> V_20 ,
L_9 ,
V_46 , V_27 , F_43 ( V_27 ,
V_61 ) ) ;
V_27 = F_43 ( V_27 , V_61 ) ;
}
V_17 -> V_14 . V_27 = V_27 ;
F_1 ( V_2 , F_44 ( V_46 ) ,
V_17 -> V_14 . V_27 ) ;
sprintf ( V_54 , L_10 , V_46 ) ;
if ( F_41 ( V_52 , V_54 , & V_17 -> V_34 ) )
V_17 -> V_34 = 0 ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_1 ( V_2 , V_62 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 &= ~ V_63 ;
V_7 |= V_64 ;
F_1 ( V_2 , V_11 , V_7 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
V_2 -> V_36 = F_47 ( & V_2 -> V_19 -> V_20 , V_57 ,
sizeof( struct V_16 ) ,
V_29 ) ;
if ( ! V_2 -> V_36 )
return - V_23 ;
F_38 ( V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_51 * V_52 ,
struct V_1 * V_2 )
{
V_2 -> V_65 = F_49 ( V_52 , L_11 , 0 ) ;
if ( ! V_2 -> V_65 )
return - V_23 ;
V_2 -> V_66 = F_50 ( V_2 -> V_65 ,
V_67 ,
& V_2 -> V_68 ) ;
if ( ! V_2 -> V_66 )
return - V_23 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_65 , V_2 -> V_68 ,
V_67 ) ;
}
static int F_53 ( struct V_24 * V_19 )
{
struct V_51 * V_52 = V_19 -> V_20 . V_53 ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
int V_26 ;
V_2 = F_54 ( & V_19 -> V_20 , sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 )
return - V_23 ;
V_70 = F_55 ( V_19 , V_71 , 0 ) ;
V_2 -> V_5 = F_56 ( & V_19 -> V_20 , V_70 ) ;
if ( F_57 ( V_2 -> V_5 ) )
return F_58 ( V_2 -> V_5 ) ;
V_2 -> V_72 = F_59 ( & V_19 -> V_20 , NULL ) ;
if ( F_57 ( V_2 -> V_72 ) )
return F_58 ( V_2 -> V_72 ) ;
V_26 = F_60 ( V_2 -> V_72 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_48 ( V_52 , V_2 ) ;
if ( V_26 < 0 ) {
F_25 ( & V_19 -> V_20 , L_12 ) ;
goto V_73;
}
V_2 -> V_19 = V_19 ;
V_26 = F_46 ( V_2 ) ;
if ( V_26 < 0 ) {
F_25 ( & V_19 -> V_20 , L_13 ) ;
goto V_74;
}
V_52 -> V_4 = V_2 ;
F_61 ( V_19 , V_2 ) ;
F_62 ( & V_19 -> V_20 , L_14 ) ;
return 0 ;
V_74:
F_51 ( V_2 ) ;
V_73:
F_63 ( V_2 -> V_72 ) ;
return V_26 ;
}
static int F_64 ( struct V_24 * V_19 )
{
struct V_1 * V_2 = F_65 ( V_19 ) ;
T_2 V_75 = 0xff ;
int V_46 = 0 ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ ) {
struct V_16 * V_17 = & V_2 -> V_36 [ V_46 ] ;
F_37 ( V_2 , V_17 , V_75 ) ;
}
F_51 ( V_2 ) ;
F_1 ( V_2 , V_55 , V_76 ) ;
F_63 ( V_2 -> V_72 ) ;
return 0 ;
}
