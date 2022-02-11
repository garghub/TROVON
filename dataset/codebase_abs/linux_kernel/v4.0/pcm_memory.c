static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_1 V_7 = V_3 ;
int V_8 ;
do {
if ( ( V_8 = F_2 ( V_5 -> V_9 . type , V_5 -> V_9 . V_9 ,
V_3 , V_5 ) ) < 0 ) {
if ( V_8 != - V_10 )
return V_8 ;
} else
return 0 ;
V_3 >>= 1 ;
} while ( V_3 >= V_11 );
V_5 -> V_12 = 0 ;
F_3 ( L_1 ,
V_2 -> V_13 -> V_14 -> V_15 , V_2 -> V_13 -> V_16 ,
V_2 -> V_17 ? 'c' : 'p' , V_2 -> V_15 ,
V_2 -> V_13 -> V_18 , V_7 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_19 == NULL )
return;
F_5 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_19 = NULL ;
}
int F_6 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
#ifdef F_7
F_8 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
F_8 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
#endif
return 0 ;
}
int F_9 ( struct V_22 * V_13 )
{
struct V_1 * V_2 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ )
for ( V_2 = V_13 -> V_23 [ V_17 ] . V_2 ; V_2 ; V_2 = V_2 -> V_24 )
F_6 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
F_11 ( V_28 , L_2 , ( unsigned long ) V_2 -> V_6 . V_12 / 1024 ) ;
}
static void F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
F_11 ( V_28 , L_2 , ( unsigned long ) V_2 -> V_30 / 1024 ) ;
}
static void F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_26 -> V_29 ;
char line [ 64 ] , V_31 [ 64 ] ;
T_1 V_3 ;
struct V_4 V_32 ;
if ( V_2 -> V_33 ) {
V_28 -> error = - V_34 ;
return;
}
if ( ! F_14 ( V_28 , line , sizeof( line ) ) ) {
F_15 ( V_31 , line , sizeof( V_31 ) ) ;
V_3 = F_16 ( V_31 , NULL , 10 ) * 1024 ;
if ( ( V_3 != 0 && V_3 < 8192 ) || V_3 > V_2 -> V_30 ) {
V_28 -> error = - V_35 ;
return;
}
if ( V_2 -> V_6 . V_12 == V_3 )
return;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_9 = V_2 -> V_6 . V_9 ;
if ( V_3 > 0 ) {
if ( F_2 ( V_2 -> V_6 . V_9 . type ,
V_2 -> V_6 . V_9 . V_9 ,
V_3 , & V_32 ) < 0 ) {
V_28 -> error = - V_10 ;
return;
}
V_2 -> V_36 = V_3 ;
} else {
V_2 -> V_36 = V_37 ;
}
if ( V_2 -> V_6 . V_19 )
F_5 ( & V_2 -> V_6 ) ;
V_2 -> V_6 = V_32 ;
} else {
V_28 -> error = - V_35 ;
}
}
static inline void F_17 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
if ( ( V_26 = F_18 ( V_2 -> V_13 -> V_14 , L_3 , V_2 -> V_38 ) ) != NULL ) {
V_26 -> V_39 . V_40 . V_41 = F_10 ;
V_26 -> V_39 . V_40 . V_42 = F_13 ;
V_26 -> V_43 |= V_44 ;
V_26 -> V_29 = V_2 ;
if ( F_19 ( V_26 ) < 0 ) {
F_8 ( V_26 ) ;
V_26 = NULL ;
}
}
V_2 -> V_21 = V_26 ;
if ( ( V_26 = F_18 ( V_2 -> V_13 -> V_14 , L_4 , V_2 -> V_38 ) ) != NULL ) {
V_26 -> V_39 . V_40 . V_41 = F_12 ;
V_26 -> V_29 = V_2 ;
if ( F_19 ( V_26 ) < 0 ) {
F_8 ( V_26 ) ;
V_26 = NULL ;
}
}
V_2 -> V_20 = V_26 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_45 )
{
if ( V_3 > 0 && V_46 && V_2 -> V_15 < V_47 )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_6 . V_12 > 0 )
V_2 -> V_36 = V_2 -> V_6 . V_12 ;
V_2 -> V_30 = V_45 ;
F_17 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
int type , struct V_16 * V_48 ,
T_1 V_3 , T_1 V_45 )
{
V_2 -> V_6 . V_9 . type = type ;
V_2 -> V_6 . V_9 . V_9 = V_48 ;
return F_20 ( V_2 , V_3 , V_45 ) ;
}
int F_22 ( struct V_22 * V_13 ,
int type , void * V_48 ,
T_1 V_3 , T_1 V_45 )
{
struct V_1 * V_2 ;
int V_17 , V_8 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ )
for ( V_2 = V_13 -> V_23 [ V_17 ] . V_2 ; V_2 ; V_2 = V_2 -> V_24 )
if ( ( V_8 = F_21 ( V_2 , type , V_48 , V_3 , V_45 ) ) < 0 )
return V_8 ;
return 0 ;
}
struct V_49 * F_23 ( struct V_1 * V_2 , unsigned long V_50 )
{
struct V_51 * V_52 = F_24 ( V_2 ) ;
unsigned int V_53 = V_50 >> V_54 ;
if ( V_53 >= ( unsigned int ) V_52 -> V_55 )
return NULL ;
return V_52 -> V_56 [ V_53 ] ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_57 * V_33 ;
struct V_4 * V_5 = NULL ;
if ( F_26 ( V_2 ) )
return - V_35 ;
if ( F_27 ( V_2 -> V_6 . V_9 . type ==
V_58 ) )
return - V_35 ;
V_33 = V_2 -> V_33 ;
if ( V_33 -> V_59 ) {
if ( V_33 -> V_59 -> V_12 >= V_3 ) {
V_33 -> V_60 = V_3 ;
return 0 ;
}
F_28 ( V_2 ) ;
}
if ( V_2 -> V_6 . V_19 != NULL &&
V_2 -> V_6 . V_12 >= V_3 ) {
V_5 = & V_2 -> V_6 ;
} else {
V_5 = F_29 ( sizeof( * V_5 ) , V_61 ) ;
if ( ! V_5 )
return - V_10 ;
V_5 -> V_9 = V_2 -> V_6 . V_9 ;
if ( F_2 ( V_2 -> V_6 . V_9 . type ,
V_2 -> V_6 . V_9 . V_9 ,
V_3 , V_5 ) < 0 ) {
F_30 ( V_5 ) ;
return - V_10 ;
}
}
F_31 ( V_2 , V_5 ) ;
V_33 -> V_60 = V_3 ;
return 1 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_57 * V_33 ;
if ( F_26 ( V_2 ) )
return - V_35 ;
V_33 = V_2 -> V_33 ;
if ( V_33 -> V_62 == NULL )
return 0 ;
if ( V_33 -> V_59 != & V_2 -> V_6 ) {
F_5 ( V_33 -> V_59 ) ;
F_30 ( V_33 -> V_59 ) ;
}
F_31 ( V_2 , NULL ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_63 )
{
struct V_57 * V_33 ;
if ( F_26 ( V_2 ) )
return - V_35 ;
V_33 = V_2 -> V_33 ;
if ( V_33 -> V_62 ) {
if ( V_33 -> V_60 >= V_3 )
return 0 ;
F_33 ( V_33 -> V_62 ) ;
}
V_33 -> V_62 = F_34 ( V_3 , V_63 , V_64 ) ;
if ( ! V_33 -> V_62 )
return - V_10 ;
V_33 -> V_60 = V_3 ;
return 1 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_57 * V_33 ;
if ( F_26 ( V_2 ) )
return - V_35 ;
V_33 = V_2 -> V_33 ;
F_33 ( V_33 -> V_62 ) ;
V_33 -> V_62 = NULL ;
return 0 ;
}
struct V_49 * F_36 ( struct V_1 * V_2 ,
unsigned long V_50 )
{
return F_37 ( V_2 -> V_33 -> V_62 + V_50 ) ;
}
