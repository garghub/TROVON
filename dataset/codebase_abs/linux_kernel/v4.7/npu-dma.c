static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
struct V_1 * F_3 ( struct V_1 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_6 ;
V_3 = F_4 ( V_5 -> V_7 . V_8 , L_1 , 0 ) ;
if ( ! V_3 )
return NULL ;
V_6 = F_1 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_6 ;
}
struct V_1 * F_6 ( struct V_1 * V_6 , int V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_5 ;
V_3 = F_4 ( V_6 -> V_7 . V_8 , L_2 , V_9 ) ;
if ( ! V_3 )
return NULL ;
V_5 = F_1 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_5 ;
}
static void * F_7 ( struct V_10 * V_7 , T_1 V_11 ,
T_2 * V_12 , T_3 V_13 ,
struct V_14 * V_15 )
{
F_8 () ;
return NULL ;
}
static void F_9 ( struct V_10 * V_7 , T_1 V_11 ,
void * V_16 , T_2 V_12 ,
struct V_14 * V_15 )
{
F_8 () ;
}
static T_2 F_10 ( struct V_10 * V_7 , struct V_17 * V_17 ,
unsigned long V_18 , T_1 V_11 ,
enum V_19 V_20 ,
struct V_14 * V_15 )
{
F_8 () ;
return 0 ;
}
static int F_11 ( struct V_10 * V_7 , struct V_21 * V_22 ,
int V_23 , enum V_19 V_20 ,
struct V_14 * V_15 )
{
F_8 () ;
return 0 ;
}
static int F_12 ( struct V_10 * V_7 , T_4 V_24 )
{
F_8 () ;
return 0 ;
}
static T_4 F_13 ( struct V_10 * V_7 )
{
F_8 () ;
return 0 ;
}
static struct V_25 * F_14 ( struct V_25 * V_26 ,
struct V_1 * * V_6 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_1 * V_31 ;
struct V_25 * V_32 ;
struct V_33 * V_34 ;
V_31 = F_3 ( V_26 -> V_31 ) ;
if ( ! V_31 )
return NULL ;
V_34 = F_15 ( V_31 ) ;
if ( F_16 ( ! V_34 || V_34 -> V_35 == V_36 ) )
return NULL ;
V_30 = F_17 ( V_31 -> V_37 ) ;
V_28 = V_30 -> V_38 ;
V_32 = & V_28 -> V_39 . V_40 [ V_34 -> V_35 ] ;
if ( V_6 )
* V_6 = V_31 ;
return V_32 ;
}
long F_18 ( struct V_25 * V_26 , int V_41 ,
struct V_42 * V_43 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_5 V_44 ;
const unsigned long V_11 = V_43 -> V_45 ?
V_43 -> V_46 : V_43 -> V_47 ;
const T_6 V_48 = V_43 -> V_49 << V_43 -> V_50 ;
const T_6 V_51 = V_43 -> V_47 << V_43 -> V_50 ;
F_19 ( V_26 , L_3 ,
V_48 , V_48 + V_51 - 1 ,
F_20 ( V_43 ) ) ;
V_44 = F_21 ( V_28 -> V_52 ,
V_26 -> V_35 ,
V_26 -> V_35 ,
V_43 -> V_45 + 1 ,
F_22 ( V_43 -> V_53 ) ,
V_11 << 3 ,
F_20 ( V_43 ) ) ;
if ( V_44 ) {
F_23 ( V_26 , L_4 , V_44 ) ;
return V_44 ;
}
F_24 ( V_28 , false ) ;
F_25 ( V_28 -> V_30 -> V_54 , V_41 ,
V_43 , & V_26 -> V_55 ) ;
return 0 ;
}
long F_26 ( struct V_25 * V_26 , int V_41 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_5 V_44 ;
F_19 ( V_26 , L_5 ) ;
V_44 = F_21 ( V_28 -> V_52 , V_26 -> V_35 ,
V_26 -> V_35 ,
0 , 0 ,
0 , 0 ) ;
if ( V_44 ) {
F_23 ( V_26 , L_6 , V_44 ) ;
return V_44 ;
}
F_24 ( V_28 , false ) ;
F_27 ( V_26 -> V_55 . V_56 [ V_41 ] ,
& V_26 -> V_55 ) ;
return 0 ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_1 * V_6 ;
struct V_25 * V_57 ;
T_5 V_44 ;
if ( ! V_26 -> V_31 || ! ( V_26 -> V_58 & V_59 ) )
return;
V_57 = F_14 ( V_26 , & V_6 ) ;
if ( ! V_57 )
return;
V_44 = F_18 ( V_26 , 0 , V_57 -> V_55 . V_56 [ 0 ] ) ;
F_29 ( & V_26 -> V_31 -> V_7 , & V_60 ) ;
}
static int F_30 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_5 V_44 = 0 ;
T_7 V_61 = F_31 () ;
if ( V_28 -> type != V_62 || ! V_26 -> V_31 )
return - V_63 ;
V_44 = F_26 ( V_26 , 0 ) ;
if ( V_44 != V_64 )
return V_44 ;
V_61 = F_32 ( V_61 ) ;
F_33 ( & V_26 -> V_31 -> V_7 , L_7 ,
V_26 -> V_35 ) ;
V_44 = F_34 ( V_28 -> V_52 ,
V_26 -> V_35 , V_26 -> V_35 ,
0 , V_61 ) ;
if ( V_44 == V_64 )
F_24 ( V_28 , false ) ;
return V_44 ;
}
void F_35 ( struct V_1 * V_6 , bool V_65 )
{
int V_66 ;
struct V_27 * V_28 ;
struct V_33 * V_34 ;
struct V_25 * V_26 ;
struct V_1 * V_5 ;
for ( V_66 = 0 ; ; ++ V_66 ) {
V_5 = F_6 ( V_6 , V_66 ) ;
if ( ! V_5 )
break;
V_34 = F_15 ( V_5 ) ;
if ( F_16 ( ! V_34 || V_34 -> V_35 == V_36 ) )
return;
V_28 = F_17 ( V_5 -> V_37 ) -> V_38 ;
V_26 = & V_28 -> V_39 . V_40 [ V_34 -> V_35 ] ;
if ( V_65 ) {
F_33 ( & V_5 -> V_7 ,
L_8 ) ;
F_30 ( V_26 ) ;
} else {
F_33 ( & V_5 -> V_7 , L_9 ) ;
F_28 ( V_26 ) ;
}
}
}
void F_36 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_5 V_44 ;
if ( V_26 -> V_55 . V_56 [ 0 ] ) {
F_26 ( V_26 , 0 ) ;
return;
}
V_44 = F_34 ( V_28 -> V_52 ,
V_26 -> V_35 , V_26 -> V_35 ,
0 , 0 ) ;
if ( V_44 ) {
F_23 ( V_26 , L_10 , V_44 ) ;
return;
}
F_24 ( V_26 -> V_28 , false ) ;
}
struct V_25 * F_37 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_67 * V_68 = V_28 -> V_30 -> V_37 ;
struct V_1 * V_5 , * V_6 = NULL , * V_69 ;
struct V_25 * V_57 = F_14 ( V_26 , & V_6 ) ;
if ( ! V_57 || ! V_6 )
return NULL ;
F_38 (npdev, &pbus->devices, bus_list) {
V_69 = F_3 ( V_5 ) ;
if ( V_69 != V_6 )
continue;
F_19 ( V_57 , L_11 , F_39 ( & V_5 -> V_7 ) ) ;
F_40 ( V_57 -> V_55 . V_70 , & V_5 -> V_7 ) ;
}
return V_57 ;
}
