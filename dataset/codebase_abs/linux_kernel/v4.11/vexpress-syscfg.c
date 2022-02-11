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
int V_34 ;
struct V_6 * V_7 = V_30 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
const T_2 * V_31 = NULL ;
T_2 V_37 [ 4 ] ;
int V_38 ;
T_1 V_39 , V_40 , V_41 ;
int V_42 ;
V_34 = F_17 ( V_20 -> V_43 , & V_39 ,
& V_40 , & V_41 ) ;
if ( V_34 )
return F_18 ( V_34 ) ;
V_36 = F_19 ( V_20 -> V_43 ,
L_3 , NULL ) ;
if ( ! V_36 )
return F_18 ( - V_13 ) ;
V_38 = V_36 -> V_44 / sizeof( T_1 ) / 2 ;
V_31 = V_36 -> V_45 ;
if ( V_38 == 1 && F_20 ( V_20 -> V_43 ,
L_4 ) ) {
V_38 = 2 ;
V_37 [ 0 ] = * V_31 ;
V_37 [ 2 ] = * V_31 ++ ;
V_37 [ 1 ] = * V_31 ;
V_37 [ 3 ] = F_21 ( F_22 ( V_31 ) + 1 ) ;
V_31 = V_37 ;
}
V_2 = F_23 ( sizeof( * V_2 ) + sizeof( * V_2 -> V_18 ) * V_38 ,
V_46 ) ;
if ( ! V_2 )
return F_18 ( - V_47 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_38 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
T_1 V_48 , V_33 ;
V_48 = F_22 ( V_31 ++ ) ;
V_33 = F_22 ( V_31 ++ ) ;
F_4 ( V_20 , L_5 ,
V_2 , V_39 , V_40 , V_41 ,
V_48 , V_33 ) ;
V_2 -> V_18 [ V_42 ] = F_24 ( V_41 ) ;
V_2 -> V_18 [ V_42 ] |= F_25 ( V_39 ) ;
V_2 -> V_18 [ V_42 ] |= F_26 ( V_40 ) ;
V_2 -> V_18 [ V_42 ] |= F_27 ( V_48 ) ;
V_2 -> V_18 [ V_42 ] |= F_28 ( V_33 ) ;
}
V_49 . V_50 = V_38 - 1 ;
V_2 -> V_32 = F_29 ( V_20 , NULL , V_2 ,
& V_49 ) ;
if ( F_30 ( V_2 -> V_32 ) ) {
void * V_34 = V_2 -> V_32 ;
F_31 ( V_2 ) ;
return V_34 ;
}
F_32 ( & V_2 -> V_51 , & V_7 -> V_52 ) ;
return V_2 -> V_32 ;
}
static void F_33 ( struct V_32 * V_32 , void * V_30 )
{
struct V_6 * V_7 = V_30 ;
struct V_1 * V_2 , * V_53 ;
F_34 ( V_32 ) ;
F_35 (func, tmp, &syscfg->funcs, list) {
if ( V_2 -> V_32 == V_32 ) {
F_36 ( & V_7 -> V_52 ) ;
F_31 ( V_2 ) ;
break;
}
}
}
static int F_37 ( struct V_54 * V_55 )
{
struct V_6 * V_7 ;
struct V_56 * V_57 ;
struct V_33 * V_58 ;
V_7 = F_38 ( & V_55 -> V_20 , sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 )
return - V_47 ;
V_7 -> V_20 = & V_55 -> V_20 ;
F_39 ( & V_7 -> V_52 ) ;
V_57 = F_40 ( V_55 , V_59 , 0 ) ;
if ( ! F_41 ( & V_55 -> V_20 , V_57 -> V_60 ,
F_42 ( V_57 ) , V_55 -> V_61 ) )
return - V_17 ;
V_7 -> V_14 = F_43 ( & V_55 -> V_20 , V_57 -> V_60 , F_42 ( V_57 ) ) ;
if ( ! V_7 -> V_14 )
return - V_27 ;
V_58 = F_44 ( V_55 -> V_20 . V_62 ,
& V_63 , V_7 ) ;
if ( F_30 ( V_58 ) )
return F_45 ( V_58 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_64 ) ;
}
