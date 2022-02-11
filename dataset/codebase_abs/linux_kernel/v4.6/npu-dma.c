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
if ( V_26 -> V_35 & V_36 ) {
V_32 = V_26 -> V_37 [ 0 ] ;
V_31 = V_32 -> V_31 ;
} else {
V_31 = F_3 ( V_26 -> V_31 ) ;
if ( ! V_31 )
return NULL ;
V_34 = F_15 ( V_31 ) ;
if ( F_16 ( ! V_34 || V_34 -> V_38 == V_39 ) )
return NULL ;
V_30 = F_17 ( V_31 -> V_40 ) ;
V_28 = V_30 -> V_41 ;
V_32 = & V_28 -> V_42 . V_43 [ V_34 -> V_38 ] ;
}
if ( V_6 )
* V_6 = V_31 ;
return V_32 ;
}
void F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
if ( F_16 ( V_28 -> type != V_44 ||
! V_28 -> V_42 . V_45 ||
! ( V_26 -> V_35 & V_46 ) ) )
return;
F_19 () ;
F_20 ( F_21 ( V_47 ) ,
V_28 -> V_42 . V_45 ) ;
}
void F_22 ( struct V_25 * V_26 ,
struct V_48 * V_49 ,
unsigned long V_9 ,
unsigned long V_50 ,
bool V_51 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
unsigned long V_52 = V_47 ;
if ( F_16 ( V_28 -> type != V_44 ||
! V_28 -> V_42 . V_45 ||
! ( V_26 -> V_35 & V_46 ) ) )
return;
F_19 () ;
if ( V_51 )
F_23 ( F_21 ( V_52 ) ,
( V_53 V_54 * ) V_28 -> V_42 . V_55 ) ;
else
F_20 ( F_21 ( V_52 ) ,
V_28 -> V_42 . V_45 ) ;
}
void F_24 ( struct V_25 * V_26 )
{
struct V_25 * V_56 ;
struct V_1 * V_6 ;
int V_57 , V_58 = - 1 ;
if ( ! V_26 -> V_31 || ! ( V_26 -> V_35 & V_46 ) )
return;
V_56 = F_14 ( V_26 , & V_6 ) ;
if ( ! V_56 )
return;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
if ( V_56 -> V_37 [ V_57 ] == V_26 )
return;
if ( ! V_56 -> V_37 [ V_57 ] )
V_58 = V_57 ;
}
if ( F_16 ( V_58 < 0 ) )
return;
V_56 -> V_37 [ V_58 ] = V_26 ;
V_56 -> V_35 |= V_36 ;
V_26 -> V_37 [ 0 ] = V_56 ;
V_26 -> V_35 |= V_36 ;
}
static void F_25 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
struct V_1 * V_6 ;
struct V_25 * V_56 ;
void * V_60 ;
unsigned int V_11 ;
T_5 V_61 ;
if ( ! V_26 -> V_31 || ! ( V_26 -> V_35 & V_46 ) )
return;
V_56 = F_14 ( V_26 , & V_6 ) ;
if ( ! V_56 )
return;
V_60 = ( void * ) V_56 -> V_62 . V_63 [ 0 ] -> V_64 ;
V_11 = V_56 -> V_62 . V_63 [ 0 ] -> V_65 << 3 ;
V_61 = F_26 ( V_28 -> V_66 , V_26 -> V_38 ,
V_26 -> V_38 , 1 , F_27 ( V_60 ) ,
V_11 , 0x1000 ) ;
if ( V_61 != V_67 )
F_28 ( L_3 ,
V_68 , V_61 , V_28 -> V_30 -> V_69 , V_26 -> V_38 ) ;
F_29 ( & V_26 -> V_31 -> V_7 , & V_70 ) ;
}
int F_30 ( struct V_25 * V_26 , bool V_71 )
{
struct V_27 * V_28 = V_26 -> V_28 ;
T_5 V_61 = 0 ;
if ( V_28 -> type != V_44 || ! V_26 -> V_31 )
return - V_72 ;
if ( V_71 ) {
T_6 V_73 = F_31 () ;
V_26 -> V_74 = 0 ;
V_73 = F_32 ( V_73 ) ;
F_33 ( & V_26 -> V_31 -> V_7 , L_4 ,
V_26 -> V_38 ) ;
V_61 = F_34 ( V_28 -> V_66 ,
V_26 -> V_38 , V_26 -> V_38 ,
V_26 -> V_74 , V_73 ) ;
} else {
F_25 ( V_26 ) ;
}
return V_61 ;
}
int F_35 ( struct V_1 * V_5 , T_4 V_75 )
{
struct V_29 * V_30 = F_17 ( V_5 -> V_40 ) ;
struct V_27 * V_28 = V_30 -> V_41 ;
struct V_33 * V_34 = F_15 ( V_5 ) ;
struct V_25 * V_26 , * V_56 ;
struct V_1 * V_6 ;
T_7 V_73 ;
bool V_76 = false ;
if ( F_16 ( ! V_34 || V_34 -> V_38 == V_39 ) )
return - V_77 ;
V_26 = & V_28 -> V_42 . V_43 [ V_34 -> V_38 ] ;
V_56 = F_14 ( V_26 , & V_6 ) ;
if ( ! V_56 )
return - V_78 ;
if ( V_56 -> V_79 ) {
V_73 = V_56 -> V_74 + F_31 () - 1 ;
V_76 = ( V_75 >= V_73 ) ;
}
if ( V_76 )
F_33 ( & V_5 -> V_7 , L_5 ) ;
else
F_33 ( & V_5 -> V_7 , L_6 ) ;
F_30 ( V_26 , V_76 ) ;
* V_5 -> V_7 . V_75 = V_75 ;
return 0 ;
}
