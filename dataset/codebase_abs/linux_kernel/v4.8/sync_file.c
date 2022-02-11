static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_4 = F_3 ( L_1 , & V_5 ,
V_1 , 0 ) ;
if ( F_4 ( V_1 -> V_4 ) )
goto V_6;
F_5 ( & V_1 -> V_7 ) ;
F_6 ( & V_1 -> V_8 ) ;
return V_1 ;
V_6:
F_7 ( V_1 ) ;
return NULL ;
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_1 ;
V_14 = F_9 ( V_12 , struct V_13 , V_12 ) ;
V_1 = V_14 -> V_1 ;
if ( F_10 ( & V_1 -> V_15 ) )
F_11 ( & V_1 -> V_8 ) ;
}
struct V_1 * F_12 ( struct V_9 * V_9 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( F_13 ( struct V_1 , V_16 [ 1 ] ) ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_17 = 1 ;
F_14 ( & V_1 -> V_15 , 1 ) ;
snprintf ( V_1 -> V_18 , sizeof( V_1 -> V_18 ) , L_2 ,
V_9 -> V_19 -> V_20 ( V_9 ) ,
V_9 -> V_19 -> V_21 ( V_9 ) , V_9 -> V_22 ,
V_9 -> V_23 ) ;
V_1 -> V_16 [ 0 ] . V_9 = V_9 ;
V_1 -> V_16 [ 0 ] . V_1 = V_1 ;
if ( F_15 ( V_9 , & V_1 -> V_16 [ 0 ] . V_12 ,
F_8 ) )
F_16 ( & V_1 -> V_15 ) ;
return V_1 ;
}
static struct V_1 * F_17 ( int V_24 )
{
struct V_4 * V_4 = F_18 ( V_24 ) ;
if ( ! V_4 )
return NULL ;
if ( V_4 -> V_25 != & V_5 )
goto V_6;
return V_4 -> V_26 ;
V_6:
F_19 ( V_4 ) ;
return NULL ;
}
static void F_20 ( struct V_1 * V_1 , int * V_27 ,
struct V_9 * V_9 )
{
V_1 -> V_16 [ * V_27 ] . V_9 = V_9 ;
V_1 -> V_16 [ * V_27 ] . V_1 = V_1 ;
if ( ! F_15 ( V_9 , & V_1 -> V_16 [ * V_27 ] . V_12 ,
F_8 ) ) {
F_21 ( V_9 ) ;
( * V_27 ) ++ ;
}
}
static struct V_1 * F_22 ( const char * V_18 , struct V_1 * V_28 ,
struct V_1 * V_29 )
{
int V_17 = V_28 -> V_17 + V_29 -> V_17 ;
struct V_1 * V_1 ;
int V_27 , V_30 , V_31 ;
unsigned long V_2 = F_13 ( struct V_1 , V_16 [ V_17 ] ) ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return NULL ;
F_14 ( & V_1 -> V_15 , V_17 ) ;
for ( V_27 = V_30 = V_31 = 0 ; V_30 < V_28 -> V_17 && V_31 < V_29 -> V_17 ; ) {
struct V_9 * V_32 = V_28 -> V_16 [ V_30 ] . V_9 ;
struct V_9 * V_33 = V_29 -> V_16 [ V_31 ] . V_9 ;
if ( V_32 -> V_22 < V_33 -> V_22 ) {
F_20 ( V_1 , & V_27 , V_32 ) ;
V_30 ++ ;
} else if ( V_32 -> V_22 > V_33 -> V_22 ) {
F_20 ( V_1 , & V_27 , V_33 ) ;
V_31 ++ ;
} else {
if ( V_32 -> V_23 - V_33 -> V_23 <= V_34 )
F_20 ( V_1 , & V_27 , V_32 ) ;
else
F_20 ( V_1 , & V_27 , V_33 ) ;
V_30 ++ ;
V_31 ++ ;
}
}
for (; V_30 < V_28 -> V_17 ; V_30 ++ )
F_20 ( V_1 , & V_27 , V_28 -> V_16 [ V_30 ] . V_9 ) ;
for (; V_31 < V_29 -> V_17 ; V_31 ++ )
F_20 ( V_1 , & V_27 , V_29 -> V_16 [ V_31 ] . V_9 ) ;
if ( V_17 > V_27 )
F_23 ( V_17 - V_27 , & V_1 -> V_15 ) ;
V_1 -> V_17 = V_27 ;
F_24 ( V_1 -> V_18 , V_18 , sizeof( V_1 -> V_18 ) ) ;
return V_1 ;
}
static void F_25 ( struct V_7 * V_7 )
{
struct V_1 * V_1 = F_9 ( V_7 , struct V_1 ,
V_7 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_17 ; ++ V_27 ) {
F_26 ( V_1 -> V_16 [ V_27 ] . V_9 ,
& V_1 -> V_16 [ V_27 ] . V_12 ) ;
F_27 ( V_1 -> V_16 [ V_27 ] . V_9 ) ;
}
F_7 ( V_1 ) ;
}
static int F_28 ( struct V_35 * V_35 , struct V_4 * V_4 )
{
struct V_1 * V_1 = V_4 -> V_26 ;
F_29 ( & V_1 -> V_7 , F_25 ) ;
return 0 ;
}
static unsigned int F_30 ( struct V_4 * V_4 , T_1 * V_36 )
{
struct V_1 * V_1 = V_4 -> V_26 ;
int V_15 ;
F_31 ( V_4 , & V_1 -> V_8 , V_36 ) ;
V_15 = F_32 ( & V_1 -> V_15 ) ;
if ( ! V_15 )
return V_37 ;
if ( V_15 < 0 )
return V_38 ;
return 0 ;
}
static long F_33 ( struct V_1 * V_1 ,
unsigned long V_39 )
{
int V_24 = F_34 ( V_40 ) ;
int V_6 ;
struct V_1 * V_41 , * V_42 ;
struct V_43 V_44 ;
if ( V_24 < 0 )
return V_24 ;
if ( F_35 ( & V_44 , ( void V_45 * ) V_39 , sizeof( V_44 ) ) ) {
V_6 = - V_46 ;
goto V_47;
}
if ( V_44 . V_48 || V_44 . V_49 ) {
V_6 = - V_50 ;
goto V_47;
}
V_41 = F_17 ( V_44 . V_51 ) ;
if ( ! V_41 ) {
V_6 = - V_52 ;
goto V_47;
}
V_44 . V_18 [ sizeof( V_44 . V_18 ) - 1 ] = '\0' ;
V_42 = F_22 ( V_44 . V_18 , V_1 , V_41 ) ;
if ( ! V_42 ) {
V_6 = - V_53 ;
goto V_54;
}
V_44 . V_9 = V_24 ;
if ( F_36 ( ( void V_45 * ) V_39 , & V_44 , sizeof( V_44 ) ) ) {
V_6 = - V_46 ;
goto V_55;
}
F_37 ( V_24 , V_42 -> V_4 ) ;
F_19 ( V_41 -> V_4 ) ;
return 0 ;
V_55:
F_19 ( V_42 -> V_4 ) ;
V_54:
F_19 ( V_41 -> V_4 ) ;
V_47:
F_38 ( V_24 ) ;
return V_6 ;
}
static void F_39 ( struct V_9 * V_9 ,
struct V_56 * V_57 )
{
F_24 ( V_57 -> V_58 , V_9 -> V_19 -> V_21 ( V_9 ) ,
sizeof( V_57 -> V_58 ) ) ;
F_24 ( V_57 -> V_59 , V_9 -> V_19 -> V_20 ( V_9 ) ,
sizeof( V_57 -> V_59 ) ) ;
if ( F_40 ( V_9 ) )
V_57 -> V_15 = V_9 -> V_15 >= 0 ? 1 : V_9 -> V_15 ;
else
V_57 -> V_15 = 0 ;
V_57 -> V_60 = F_41 ( V_9 -> V_61 ) ;
}
static long F_42 ( struct V_1 * V_1 ,
unsigned long V_39 )
{
struct V_62 V_57 ;
struct V_56 * V_63 = NULL ;
T_2 V_2 ;
int V_64 , V_27 ;
if ( F_35 ( & V_57 , ( void V_45 * ) V_39 , sizeof( V_57 ) ) )
return - V_46 ;
if ( V_57 . V_48 || V_57 . V_49 )
return - V_50 ;
if ( ! V_57 . V_17 )
goto V_65;
if ( V_57 . V_17 < V_1 -> V_17 )
return - V_50 ;
V_2 = V_1 -> V_17 * sizeof( * V_63 ) ;
V_63 = F_2 ( V_2 , V_3 ) ;
if ( ! V_63 )
return - V_53 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_17 ; ++ V_27 )
F_39 ( V_1 -> V_16 [ V_27 ] . V_9 , & V_63 [ V_27 ] ) ;
if ( F_36 ( F_43 ( V_57 . V_56 ) , V_63 ,
V_2 ) ) {
V_64 = - V_46 ;
goto V_66;
}
V_65:
F_24 ( V_57 . V_18 , V_1 -> V_18 , sizeof( V_57 . V_18 ) ) ;
V_57 . V_15 = F_32 ( & V_1 -> V_15 ) ;
if ( V_57 . V_15 >= 0 )
V_57 . V_15 = ! V_57 . V_15 ;
V_57 . V_17 = V_1 -> V_17 ;
if ( F_36 ( ( void V_45 * ) V_39 , & V_57 , sizeof( V_57 ) ) )
V_64 = - V_46 ;
else
V_64 = 0 ;
V_66:
F_7 ( V_63 ) ;
return V_64 ;
}
static long F_44 ( struct V_4 * V_4 , unsigned int V_67 ,
unsigned long V_39 )
{
struct V_1 * V_1 = V_4 -> V_26 ;
switch ( V_67 ) {
case V_68 :
return F_33 ( V_1 , V_39 ) ;
case V_69 :
return F_42 ( V_1 , V_39 ) ;
default:
return - V_70 ;
}
}
