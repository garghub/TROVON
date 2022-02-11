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
F_30 ( & V_14 -> V_45 ) ;
V_26 = F_21 ( V_2 , V_35 ) ;
if ( V_26 ) {
F_25 ( & V_2 -> V_19 -> V_20 , L_4 ,
V_35 -> V_31 ) ;
return NULL ;
}
V_37 = F_31 ( V_14 , V_14 -> V_27 , V_46 ) ;
if ( V_37 != V_14 -> V_27 ) {
F_32 ( 1 , L_5 ,
V_35 -> V_31 , V_37 , V_14 -> V_27 ) ;
return NULL ;
}
}
return V_35 ;
}
void F_33 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_2 V_39 )
{
int V_47 ;
V_17 -> V_39 &= ~ V_39 ;
if ( V_17 -> V_39 )
return;
F_8 ( V_2 , V_48 ) ;
for ( V_47 = 0 ; V_47 < V_17 -> V_14 . V_49 ; V_47 ++ ) {
T_3 V_50 ;
T_1 * V_51 ;
V_50 = F_34 ( V_2 , V_17 ) ;
if ( V_50 == 0 )
continue;
V_51 = F_35 ( V_50 ) ;
if ( ! V_51 )
break;
F_36 ( & V_2 -> V_19 -> V_20 , V_50 ,
V_17 -> V_21 , V_22 ) ;
F_37 ( & V_17 -> V_14 , V_51 ) ;
}
F_9 ( V_2 , V_48 ) ;
V_17 -> V_14 . V_49 -= V_47 ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_2 V_39 )
{
struct V_14 * V_14 = & V_17 -> V_14 ;
V_17 -> V_39 &= ~ V_39 ;
if ( V_17 -> V_39 )
return;
V_17 -> type = V_41 ;
F_33 ( V_2 , V_17 , V_39 ) ;
if ( V_14 -> V_49 )
F_32 ( 1 , L_6 , V_17 -> V_31 ) ;
if ( V_17 -> V_28 ) {
F_24 ( & V_2 -> V_19 -> V_20 ,
sizeof( T_1 ) * V_14 -> V_27 ,
V_17 -> V_28 , V_17 -> V_18 ) ;
V_17 -> V_28 = NULL ;
}
F_7 ( V_2 , V_17 -> V_31 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = V_2 -> V_19 -> V_20 . V_54 ;
struct V_16 * V_17 ;
char V_55 [ 15 ] ;
T_1 V_27 ;
int V_47 ;
F_1 ( V_2 , V_56 , V_57 ) ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
V_17 = & V_2 -> V_36 [ V_47 ] ;
V_17 -> V_31 = V_47 ;
V_17 -> type = V_41 ;
F_1 ( V_2 , F_40 ( V_47 ) , 0 ) ;
F_1 ( V_2 , F_41 ( V_47 ) , 0 ) ;
sprintf ( V_55 , L_7 , V_47 ) ;
if ( F_42 ( V_53 , V_55 , & V_27 ) ) {
V_27 = V_59 ;
} else if ( V_27 > V_60 ) {
F_43 ( & V_2 -> V_19 -> V_20 ,
L_8 ,
V_47 , V_27 , V_60 ) ;
V_27 = V_60 ;
} else if ( V_27 < V_61 ) {
F_43 ( & V_2 -> V_19 -> V_20 ,
L_8 ,
V_47 , V_27 , V_61 ) ;
V_27 = V_61 ;
} else if ( ! F_23 ( V_27 , V_62 ) ) {
F_43 ( & V_2 -> V_19 -> V_20 ,
L_9 ,
V_47 , V_27 , F_44 ( V_27 ,
V_62 ) ) ;
V_27 = F_44 ( V_27 , V_62 ) ;
}
V_17 -> V_14 . V_27 = V_27 ;
F_1 ( V_2 , F_45 ( V_47 ) ,
V_17 -> V_14 . V_27 ) ;
sprintf ( V_55 , L_10 , V_47 ) ;
if ( F_42 ( V_53 , V_55 , & V_17 -> V_34 ) )
V_17 -> V_34 = 0 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_1 ( V_2 , V_63 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_7 &= ~ V_64 ;
V_7 |= V_65 ;
F_1 ( V_2 , V_11 , V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
F_46 ( V_2 ) ;
V_2 -> V_36 = F_48 ( & V_2 -> V_19 -> V_20 , V_58 ,
sizeof( struct V_16 ) ,
V_29 ) ;
if ( ! V_2 -> V_36 )
return - V_23 ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_52 * V_53 ,
struct V_1 * V_2 )
{
V_2 -> V_66 = F_50 ( V_53 , L_11 , 0 ) ;
if ( ! V_2 -> V_66 )
return - V_23 ;
V_2 -> V_67 = F_51 ( V_2 -> V_66 ,
V_68 ,
& V_2 -> V_69 ) ;
if ( ! V_2 -> V_67 )
return - V_23 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 -> V_66 , V_2 -> V_69 ,
V_68 ) ;
}
static int F_54 ( struct V_24 * V_19 )
{
struct V_52 * V_53 = V_19 -> V_20 . V_54 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_26 ;
V_2 = F_55 ( & V_19 -> V_20 , sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 )
return - V_23 ;
V_71 = F_56 ( V_19 , V_72 , 0 ) ;
V_2 -> V_5 = F_57 ( & V_19 -> V_20 , V_71 ) ;
if ( F_58 ( V_2 -> V_5 ) )
return F_59 ( V_2 -> V_5 ) ;
V_2 -> V_73 = F_60 ( & V_19 -> V_20 , NULL ) ;
if ( F_58 ( V_2 -> V_73 ) )
return F_59 ( V_2 -> V_73 ) ;
V_26 = F_61 ( V_2 -> V_73 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_49 ( V_53 , V_2 ) ;
if ( V_26 < 0 ) {
F_25 ( & V_19 -> V_20 , L_12 ) ;
goto V_74;
}
V_2 -> V_19 = V_19 ;
V_26 = F_47 ( V_2 ) ;
if ( V_26 < 0 ) {
F_25 ( & V_19 -> V_20 , L_13 ) ;
goto V_75;
}
V_53 -> V_4 = V_2 ;
F_62 ( V_19 , V_2 ) ;
F_63 ( & V_19 -> V_20 , L_14 ) ;
return 0 ;
V_75:
F_52 ( V_2 ) ;
V_74:
F_64 ( V_2 -> V_73 ) ;
return V_26 ;
}
static int F_65 ( struct V_24 * V_19 )
{
struct V_1 * V_2 = F_66 ( V_19 ) ;
T_2 V_76 = 0xff ;
int V_47 = 0 ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
struct V_16 * V_17 = & V_2 -> V_36 [ V_47 ] ;
F_38 ( V_2 , V_17 , V_76 ) ;
}
F_52 ( V_2 ) ;
F_1 ( V_2 , V_56 , V_77 ) ;
F_64 ( V_2 -> V_73 ) ;
return 0 ;
}
