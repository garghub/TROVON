static int F_1 ( struct V_1 * V_2 ,
int V_3 , bool V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 , V_9 ;
int V_10 ;
long V_11 ;
if ( F_2 ( V_3 > V_2 -> V_12 ) )
return - V_13 ;
V_8 = F_3 ( V_7 -> V_14 + V_15 ) ;
if ( F_2 ( V_8 & V_16 ) )
return - V_17 ;
V_8 = V_2 -> V_18 [ V_3 ] ;
V_8 |= V_16 ;
V_8 |= V_4 ? V_19 : 0 ;
if ( ! V_4 )
* V_5 = 0xdeadbeef ;
F_4 ( V_7 -> V_20 , L_1 ,
V_2 , V_8 , * V_5 ) ;
F_5 ( * V_5 , V_7 -> V_14 + V_21 ) ;
F_5 ( 0 , V_7 -> V_14 + V_22 ) ;
F_5 ( V_8 , V_7 -> V_14 + V_15 ) ;
F_6 () ;
V_10 = 100 ;
V_11 = 100 ;
do {
if ( ! F_7 () ) {
F_8 ( V_23 ) ;
F_9 ( F_10 ( V_11 ) ) ;
if ( F_11 ( V_24 ) )
return - V_25 ;
} else {
F_12 ( V_11 ) ;
}
V_9 = F_3 ( V_7 -> V_14 + V_22 ) ;
if ( V_9 & V_26 )
return - V_27 ;
if ( V_11 > 20 )
V_11 -= 20 ;
} while ( -- V_10 && ! ( V_9 & V_28 ) );
if ( F_13 ( ! V_10 ) )
return - V_29 ;
if ( ! V_4 ) {
* V_5 = F_3 ( V_7 -> V_14 + V_21 ) ;
F_4 ( V_7 -> V_20 , L_2 , V_2 , * V_5 ) ;
}
return 0 ;
}
static int F_14 ( void * V_30 , unsigned int V_3 ,
unsigned int * V_31 )
{
struct V_1 * V_2 = V_30 ;
return F_1 ( V_2 , V_3 , false , V_31 ) ;
}
static int F_15 ( void * V_30 , unsigned int V_3 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 ;
return F_1 ( V_2 , V_3 , true , & V_31 ) ;
}
static struct V_32 * F_16 ( struct V_33 * V_20 ,
void * V_30 )
{
struct V_34 * V_35 = F_17 ( V_20 ) ;
struct V_6 * V_7 = V_30 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
const T_2 * V_31 = NULL ;
T_2 V_38 [ 4 ] ;
int V_39 ;
T_1 V_40 , V_41 , V_42 ;
int V_43 ;
if ( V_20 -> V_44 ) {
int V_45 = F_18 ( V_20 -> V_44 , & V_40 ,
& V_41 , & V_42 ) ;
if ( V_45 )
return F_19 ( V_45 ) ;
V_37 = F_20 ( V_20 -> V_44 ,
L_3 , NULL ) ;
if ( ! V_37 )
return F_19 ( - V_13 ) ;
V_39 = V_37 -> V_46 / sizeof( T_1 ) / 2 ;
V_31 = V_37 -> V_47 ;
} else {
if ( V_35 -> V_48 != 1 ||
V_35 -> V_49 [ 0 ] . V_50 != V_51 )
return F_19 ( - V_27 ) ;
V_40 = V_35 -> V_49 [ 0 ] . V_52 ;
if ( V_40 == V_53 )
V_40 = F_21 () ;
V_41 = 0 ;
V_42 = 0 ;
V_39 = 1 ;
}
if ( V_39 == 1 && F_22 ( V_20 -> V_44 ,
L_4 ) ) {
V_39 = 2 ;
V_38 [ 0 ] = * V_31 ;
V_38 [ 2 ] = * V_31 ++ ;
V_38 [ 1 ] = * V_31 ;
V_38 [ 3 ] = F_23 ( F_24 ( V_31 ) + 1 ) ;
V_31 = V_38 ;
}
V_2 = F_25 ( sizeof( * V_2 ) + sizeof( * V_2 -> V_18 ) * V_39 ,
V_54 ) ;
if ( ! V_2 )
return F_19 ( - V_55 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_39 ;
for ( V_43 = 0 ; V_43 < V_39 ; V_43 ++ ) {
T_1 V_56 , V_33 ;
if ( V_20 -> V_44 ) {
V_56 = F_24 ( V_31 ++ ) ;
V_33 = F_24 ( V_31 ++ ) ;
} else {
V_56 = V_35 -> V_49 [ 0 ] . V_57 ;
V_33 = V_35 -> V_58 ;
}
F_4 ( V_20 , L_5 ,
V_2 , V_40 , V_41 , V_42 ,
V_56 , V_33 ) ;
V_2 -> V_18 [ V_43 ] = F_26 ( V_42 ) ;
V_2 -> V_18 [ V_43 ] |= F_27 ( V_40 ) ;
V_2 -> V_18 [ V_43 ] |= F_28 ( V_41 ) ;
V_2 -> V_18 [ V_43 ] |= F_29 ( V_56 ) ;
V_2 -> V_18 [ V_43 ] |= F_30 ( V_33 ) ;
}
V_59 . V_60 = V_39 - 1 ;
V_2 -> V_32 = F_31 ( V_20 , NULL , V_2 ,
& V_59 ) ;
if ( F_32 ( V_2 -> V_32 ) ) {
void * V_45 = V_2 -> V_32 ;
F_33 ( V_2 ) ;
return V_45 ;
}
F_34 ( & V_2 -> V_61 , & V_7 -> V_62 ) ;
return V_2 -> V_32 ;
}
static void F_35 ( struct V_32 * V_32 , void * V_30 )
{
struct V_6 * V_7 = V_30 ;
struct V_1 * V_2 , * V_63 ;
F_36 ( V_32 ) ;
F_37 (func, tmp, &syscfg->funcs, list) {
if ( V_2 -> V_32 == V_32 ) {
F_38 ( & V_7 -> V_62 ) ;
F_33 ( V_2 ) ;
break;
}
}
}
int F_39 ( struct V_34 * V_35 )
{
V_35 -> V_20 . V_64 = V_65 ;
return F_40 ( V_35 ) ;
}
static int F_41 ( struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_49 * V_66 ;
struct V_33 * V_67 ;
V_7 = F_42 ( & V_35 -> V_20 , sizeof( * V_7 ) , V_54 ) ;
if ( ! V_7 )
return - V_55 ;
V_7 -> V_20 = & V_35 -> V_20 ;
F_43 ( & V_7 -> V_62 ) ;
V_66 = F_44 ( V_35 , V_68 , 0 ) ;
if ( ! F_45 ( & V_35 -> V_20 , V_66 -> V_52 ,
F_46 ( V_66 ) , V_35 -> V_69 ) )
return - V_17 ;
V_7 -> V_14 = F_47 ( & V_35 -> V_20 , V_66 -> V_52 , F_46 ( V_66 ) ) ;
if ( ! V_7 -> V_14 )
return - V_27 ;
V_67 = F_48 ( V_35 -> V_20 . V_64 ,
& V_70 , V_7 ) ;
if ( F_32 ( V_67 ) )
return F_49 ( V_67 ) ;
if ( ! V_35 -> V_20 . V_44 )
V_65 = V_67 ;
return 0 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_71 ) ;
}
