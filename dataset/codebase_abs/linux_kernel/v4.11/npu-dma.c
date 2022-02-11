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
unsigned long V_14 )
{
F_8 () ;
return NULL ;
}
static void F_9 ( struct V_10 * V_7 , T_1 V_11 ,
void * V_15 , T_2 V_12 ,
unsigned long V_14 )
{
F_8 () ;
}
static T_2 F_10 ( struct V_10 * V_7 , struct V_16 * V_16 ,
unsigned long V_17 , T_1 V_11 ,
enum V_18 V_19 ,
unsigned long V_14 )
{
F_8 () ;
return 0 ;
}
static int F_11 ( struct V_10 * V_7 , struct V_20 * V_21 ,
int V_22 , enum V_18 V_19 ,
unsigned long V_14 )
{
F_8 () ;
return 0 ;
}
static int F_12 ( struct V_10 * V_7 , T_4 V_23 )
{
F_8 () ;
return 0 ;
}
static T_4 F_13 ( struct V_10 * V_7 )
{
F_8 () ;
return 0 ;
}
static struct V_24 * F_14 ( struct V_24 * V_25 ,
struct V_1 * * V_6 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
struct V_24 * V_31 ;
struct V_32 * V_33 ;
V_30 = F_3 ( V_25 -> V_30 ) ;
if ( ! V_30 )
return NULL ;
V_33 = F_15 ( V_30 ) ;
if ( F_16 ( ! V_33 || V_33 -> V_34 == V_35 ) )
return NULL ;
V_29 = F_17 ( V_30 -> V_36 ) ;
V_27 = V_29 -> V_37 ;
V_31 = & V_27 -> V_38 . V_39 [ V_33 -> V_34 ] ;
if ( V_6 )
* V_6 = V_30 ;
return V_31 ;
}
long F_18 ( struct V_24 * V_25 , int V_40 ,
struct V_41 * V_42 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
const unsigned long V_11 = V_42 -> V_44 ?
V_42 -> V_45 : V_42 -> V_46 ;
const T_6 V_47 = V_42 -> V_48 << V_42 -> V_49 ;
const T_6 V_50 = V_42 -> V_46 << V_42 -> V_49 ;
F_19 ( V_25 , L_3 ,
V_47 , V_47 + V_50 - 1 ,
F_20 ( V_42 ) ) ;
V_43 = F_21 ( V_27 -> V_51 ,
V_25 -> V_34 ,
V_25 -> V_34 ,
V_42 -> V_44 + 1 ,
F_22 ( V_42 -> V_52 ) ,
V_11 << 3 ,
F_20 ( V_42 ) ) ;
if ( V_43 ) {
F_23 ( V_25 , L_4 , V_43 ) ;
return V_43 ;
}
F_24 ( V_27 , false ) ;
F_25 ( V_27 -> V_29 -> V_53 , V_40 ,
V_42 , & V_25 -> V_54 ) ;
return 0 ;
}
long F_26 ( struct V_24 * V_25 , int V_40 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
F_19 ( V_25 , L_5 ) ;
V_43 = F_21 ( V_27 -> V_51 , V_25 -> V_34 ,
V_25 -> V_34 ,
0 , 0 ,
0 , 0 ) ;
if ( V_43 ) {
F_23 ( V_25 , L_6 , V_43 ) ;
return V_43 ;
}
F_24 ( V_27 , false ) ;
F_27 ( V_25 -> V_54 . V_55 [ V_40 ] ,
& V_25 -> V_54 ) ;
return 0 ;
}
static void F_28 ( struct V_24 * V_25 )
{
struct V_1 * V_6 ;
struct V_24 * V_56 ;
T_5 V_43 ;
if ( ! V_25 -> V_30 || ! ( V_25 -> V_57 & V_58 ) )
return;
V_56 = F_14 ( V_25 , & V_6 ) ;
if ( ! V_56 )
return;
V_43 = F_18 ( V_25 , 0 , V_56 -> V_54 . V_55 [ 0 ] ) ;
F_29 ( & V_25 -> V_30 -> V_7 , & V_59 ) ;
}
static int F_30 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 = 0 ;
T_7 V_60 = F_31 () ;
if ( V_27 -> type != V_61 || ! V_25 -> V_30 )
return - V_62 ;
V_43 = F_26 ( V_25 , 0 ) ;
if ( V_43 != V_63 )
return V_43 ;
V_60 = F_32 ( V_60 ) ;
F_33 ( & V_25 -> V_30 -> V_7 , L_7 ,
V_25 -> V_34 ) ;
V_43 = F_34 ( V_27 -> V_51 ,
V_25 -> V_34 , V_25 -> V_34 ,
0 , V_60 ) ;
if ( V_43 == V_63 )
F_24 ( V_27 , false ) ;
return V_43 ;
}
void F_35 ( struct V_1 * V_6 , bool V_64 )
{
int V_65 ;
struct V_26 * V_27 ;
struct V_32 * V_33 ;
struct V_24 * V_25 ;
struct V_1 * V_5 ;
for ( V_65 = 0 ; ; ++ V_65 ) {
V_5 = F_6 ( V_6 , V_65 ) ;
if ( ! V_5 )
break;
V_33 = F_15 ( V_5 ) ;
if ( F_16 ( ! V_33 || V_33 -> V_34 == V_35 ) )
return;
V_27 = F_17 ( V_5 -> V_36 ) -> V_37 ;
V_25 = & V_27 -> V_38 . V_39 [ V_33 -> V_34 ] ;
if ( V_64 ) {
F_33 ( & V_5 -> V_7 ,
L_8 ) ;
F_30 ( V_25 ) ;
} else {
F_33 ( & V_5 -> V_7 , L_9 ) ;
F_28 ( V_25 ) ;
}
}
}
void F_36 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
T_5 V_43 ;
if ( V_25 -> V_54 . V_55 [ 0 ] ) {
F_26 ( V_25 , 0 ) ;
return;
}
V_43 = F_34 ( V_27 -> V_51 ,
V_25 -> V_34 , V_25 -> V_34 ,
0 , 0 ) ;
if ( V_43 ) {
F_23 ( V_25 , L_10 , V_43 ) ;
return;
}
F_24 ( V_25 -> V_27 , false ) ;
}
struct V_24 * F_37 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_66 * V_67 = V_27 -> V_29 -> V_36 ;
struct V_1 * V_5 , * V_6 = NULL , * V_68 ;
struct V_24 * V_56 = F_14 ( V_25 , & V_6 ) ;
if ( ! V_56 || ! V_6 )
return NULL ;
F_38 (npdev, &pbus->devices, bus_list) {
V_68 = F_3 ( V_5 ) ;
if ( V_68 != V_6 )
continue;
F_19 ( V_56 , L_11 , F_39 ( & V_5 -> V_7 ) ) ;
F_40 ( V_56 -> V_54 . V_69 , & V_5 -> V_7 ) ;
}
return V_56 ;
}
