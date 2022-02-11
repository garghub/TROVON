static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_7 ;
if ( F_2 ( V_5 , V_2 -> V_8 ) > 0 ) {
if ( V_5 -> V_9 >= V_3 )
return 0 ;
F_3 ( V_5 ) ;
V_5 -> V_9 = 0 ;
}
do {
if ( ( V_7 = F_4 ( V_5 -> V_10 . type , V_5 -> V_10 . V_10 ,
V_3 , V_5 ) ) < 0 ) {
if ( V_7 != - V_11 )
return V_7 ;
} else
return 0 ;
V_3 >>= 1 ;
} while ( V_3 >= V_12 );
V_5 -> V_9 = 0 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_13 == NULL )
return;
if ( V_2 -> V_8 )
F_6 ( & V_2 -> V_6 , V_2 -> V_8 ) ;
else
F_3 ( & V_2 -> V_6 ) ;
V_2 -> V_6 . V_13 = NULL ;
}
int F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
#ifdef F_8
F_9 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
F_9 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
#endif
return 0 ;
}
int F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
for ( V_2 = V_17 -> V_19 [ V_18 ] . V_2 ; V_2 ; V_2 = V_2 -> V_20 )
F_7 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
F_12 ( V_24 , L_1 , ( unsigned long ) V_2 -> V_6 . V_9 / 1024 ) ;
}
static void F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
F_12 ( V_24 , L_1 , ( unsigned long ) V_2 -> V_26 / 1024 ) ;
}
static void F_14 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_22 -> V_25 ;
char line [ 64 ] , V_27 [ 64 ] ;
T_1 V_3 ;
struct V_4 V_28 ;
if ( V_2 -> V_29 ) {
V_24 -> error = - V_30 ;
return;
}
if ( ! F_15 ( V_24 , line , sizeof( line ) ) ) {
F_16 ( V_27 , line , sizeof( V_27 ) ) ;
V_3 = F_17 ( V_27 , NULL , 10 ) * 1024 ;
if ( ( V_3 != 0 && V_3 < 8192 ) || V_3 > V_2 -> V_26 ) {
V_24 -> error = - V_31 ;
return;
}
if ( V_2 -> V_6 . V_9 == V_3 )
return;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_10 = V_2 -> V_6 . V_10 ;
if ( V_3 > 0 ) {
if ( F_4 ( V_2 -> V_6 . V_10 . type ,
V_2 -> V_6 . V_10 . V_10 ,
V_3 , & V_28 ) < 0 ) {
V_24 -> error = - V_11 ;
return;
}
V_2 -> V_32 = V_3 ;
} else {
V_2 -> V_32 = V_33 ;
}
if ( V_2 -> V_6 . V_13 )
F_3 ( & V_2 -> V_6 ) ;
V_2 -> V_6 = V_28 ;
} else {
V_24 -> error = - V_31 ;
}
}
static inline void F_18 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
if ( ( V_22 = F_19 ( V_2 -> V_17 -> V_34 , L_2 , V_2 -> V_35 ) ) != NULL ) {
V_22 -> V_36 . V_37 . V_38 = F_11 ;
V_22 -> V_36 . V_37 . V_39 = F_14 ;
V_22 -> V_40 |= V_41 ;
V_22 -> V_25 = V_2 ;
if ( F_20 ( V_22 ) < 0 ) {
F_9 ( V_22 ) ;
V_22 = NULL ;
}
}
V_2 -> V_15 = V_22 ;
if ( ( V_22 = F_19 ( V_2 -> V_17 -> V_34 , L_3 , V_2 -> V_35 ) ) != NULL ) {
V_22 -> V_36 . V_37 . V_38 = F_13 ;
V_22 -> V_25 = V_2 ;
if ( F_20 ( V_22 ) < 0 ) {
F_9 ( V_22 ) ;
V_22 = NULL ;
}
}
V_2 -> V_14 = V_22 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_42 )
{
if ( V_3 > 0 && V_43 && V_2 -> V_44 < V_45 )
F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_6 . V_9 > 0 )
V_2 -> V_32 = V_2 -> V_6 . V_9 ;
V_2 -> V_26 = V_42 ;
F_18 ( V_2 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
int type , struct V_46 * V_47 ,
T_1 V_3 , T_1 V_42 )
{
V_2 -> V_6 . V_10 . type = type ;
V_2 -> V_6 . V_10 . V_10 = V_47 ;
return F_21 ( V_2 , V_3 , V_42 ) ;
}
int F_23 ( struct V_16 * V_17 ,
int type , void * V_47 ,
T_1 V_3 , T_1 V_42 )
{
struct V_1 * V_2 ;
int V_18 , V_7 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
for ( V_2 = V_17 -> V_19 [ V_18 ] . V_2 ; V_2 ; V_2 = V_2 -> V_20 )
if ( ( V_7 = F_22 ( V_2 , type , V_47 , V_3 , V_42 ) ) < 0 )
return V_7 ;
return 0 ;
}
struct V_48 * F_24 ( struct V_1 * V_2 , unsigned long V_49 )
{
struct V_50 * V_51 = F_25 ( V_2 ) ;
unsigned int V_52 = V_49 >> V_53 ;
if ( V_52 >= ( unsigned int ) V_51 -> V_54 )
return NULL ;
return V_51 -> V_55 [ V_52 ] ;
}
unsigned int F_26 ( struct V_1 * V_2 ,
unsigned int V_56 , unsigned int V_3 )
{
struct V_50 * V_57 = F_25 ( V_2 ) ;
unsigned int V_58 , V_59 , V_60 ;
V_58 = V_56 >> V_53 ;
V_59 = ( V_56 + V_3 - 1 ) >> V_53 ;
V_60 = V_57 -> V_61 [ V_58 ] . V_62 >> V_53 ;
for (; ; ) {
V_58 ++ ;
if ( V_58 > V_59 )
break;
V_60 ++ ;
if ( ( V_57 -> V_61 [ V_58 ] . V_62 >> V_53 ) != V_60 )
return ( V_58 << V_53 ) - V_56 ;
}
return V_3 ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_63 * V_29 ;
struct V_4 * V_5 = NULL ;
if ( F_28 ( V_2 ) )
return - V_31 ;
if ( F_29 ( V_2 -> V_6 . V_10 . type ==
V_64 ) )
return - V_31 ;
V_29 = V_2 -> V_29 ;
if ( V_29 -> V_65 ) {
if ( V_29 -> V_65 -> V_9 >= V_3 ) {
V_29 -> V_66 = V_3 ;
return 0 ;
}
F_30 ( V_2 ) ;
}
if ( V_2 -> V_6 . V_13 != NULL &&
V_2 -> V_6 . V_9 >= V_3 ) {
V_5 = & V_2 -> V_6 ;
} else {
V_5 = F_31 ( sizeof( * V_5 ) , V_67 ) ;
if ( ! V_5 )
return - V_11 ;
V_5 -> V_10 = V_2 -> V_6 . V_10 ;
if ( F_4 ( V_2 -> V_6 . V_10 . type ,
V_2 -> V_6 . V_10 . V_10 ,
V_3 , V_5 ) < 0 ) {
F_32 ( V_5 ) ;
return - V_11 ;
}
}
F_33 ( V_2 , V_5 ) ;
V_29 -> V_66 = V_3 ;
return 1 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_63 * V_29 ;
if ( F_28 ( V_2 ) )
return - V_31 ;
V_29 = V_2 -> V_29 ;
if ( V_29 -> V_68 == NULL )
return 0 ;
if ( V_29 -> V_65 != & V_2 -> V_6 ) {
F_3 ( V_29 -> V_65 ) ;
F_32 ( V_29 -> V_65 ) ;
}
F_33 ( V_2 , NULL ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_69 )
{
struct V_63 * V_29 ;
if ( F_28 ( V_2 ) )
return - V_31 ;
V_29 = V_2 -> V_29 ;
if ( V_29 -> V_68 ) {
if ( V_29 -> V_66 >= V_3 )
return 0 ;
F_35 ( V_29 -> V_68 ) ;
}
V_29 -> V_68 = F_36 ( V_3 , V_69 , V_70 ) ;
if ( ! V_29 -> V_68 )
return - V_11 ;
V_29 -> V_66 = V_3 ;
return 1 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_63 * V_29 ;
if ( F_28 ( V_2 ) )
return - V_31 ;
V_29 = V_2 -> V_29 ;
F_35 ( V_29 -> V_68 ) ;
V_29 -> V_68 = NULL ;
return 0 ;
}
struct V_48 * F_38 ( struct V_1 * V_2 ,
unsigned long V_49 )
{
return F_39 ( V_2 -> V_29 -> V_68 + V_49 ) ;
}
