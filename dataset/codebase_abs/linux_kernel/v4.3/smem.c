static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
void * V_11 ;
V_7 = V_2 -> V_12 [ V_3 ] ;
V_11 = ( void * ) V_7 + sizeof( * V_7 ) ;
while ( V_11 < ( void * ) V_7 + V_7 -> V_13 ) {
V_9 = V_11 ;
if ( V_9 -> V_14 != V_15 ) {
F_2 ( V_2 -> V_16 ,
L_1 ,
V_3 ) ;
return - V_17 ;
}
if ( V_9 -> V_4 == V_4 )
return - V_18 ;
V_11 += sizeof( * V_9 ) + V_9 -> V_19 + V_9 -> V_5 ;
}
V_10 = sizeof( * V_9 ) + F_3 ( V_5 , 8 ) ;
if ( V_11 + V_10 >= ( void * ) V_7 + V_7 -> V_20 ) {
F_2 ( V_2 -> V_16 , L_2 ) ;
return - V_21 ;
}
V_9 = V_11 ;
V_9 -> V_14 = V_15 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_5 = F_3 ( V_5 , 8 ) ;
V_9 -> V_22 = V_9 -> V_5 - V_5 ;
V_9 -> V_19 = 0 ;
F_4 () ;
V_7 -> V_13 += V_10 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_4 ,
T_1 V_5 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
if ( F_6 ( V_4 >= V_27 ) )
return - V_17 ;
V_24 = V_2 -> V_28 [ 0 ] . V_29 ;
V_26 = & V_24 -> V_30 [ V_4 ] ;
if ( V_26 -> V_31 )
return - V_18 ;
V_5 = F_3 ( V_5 , 8 ) ;
if ( F_6 ( V_5 > V_24 -> V_32 ) )
return - V_33 ;
V_26 -> V_34 = V_24 -> V_35 ;
V_26 -> V_5 = V_5 ;
F_4 () ;
V_26 -> V_31 = 1 ;
V_24 -> V_35 += V_5 ;
V_24 -> V_32 -= V_5 ;
return 0 ;
}
int F_7 ( unsigned V_3 , unsigned V_4 , T_1 V_5 )
{
unsigned long V_36 ;
int V_37 ;
if ( ! V_38 )
return - V_39 ;
if ( V_4 < V_40 ) {
F_2 ( V_38 -> V_16 ,
L_3 , V_4 ) ;
return - V_17 ;
}
V_37 = F_8 ( V_38 -> V_41 ,
V_42 ,
& V_36 ) ;
if ( V_37 )
return V_37 ;
if ( V_3 < V_43 && V_38 -> V_12 [ V_3 ] )
V_37 = F_1 ( V_38 , V_3 , V_4 , V_5 ) ;
else
V_37 = F_5 ( V_38 , V_4 , V_5 ) ;
F_9 ( V_38 -> V_41 , & V_36 ) ;
return V_37 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_4 ,
void * * V_44 ,
T_1 * V_5 )
{
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_25 * V_26 ;
T_2 V_47 ;
unsigned V_48 ;
if ( F_6 ( V_4 >= V_27 ) )
return - V_17 ;
V_24 = V_2 -> V_28 [ 0 ] . V_29 ;
V_26 = & V_24 -> V_30 [ V_4 ] ;
if ( ! V_26 -> V_31 )
return - V_49 ;
if ( V_44 != NULL ) {
V_47 = V_26 -> V_47 & V_50 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_51 ; V_48 ++ ) {
V_46 = & V_2 -> V_28 [ V_48 ] ;
if ( V_46 -> V_47 == V_47 || ! V_47 ) {
* V_44 = V_46 -> V_29 + V_26 -> V_34 ;
break;
}
}
}
if ( V_5 != NULL )
* V_5 = V_26 -> V_5 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned V_4 ,
void * * V_44 ,
T_1 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
void * V_11 ;
V_7 = V_2 -> V_12 [ V_3 ] ;
V_11 = ( void * ) V_7 + sizeof( * V_7 ) ;
while ( V_11 < ( void * ) V_7 + V_7 -> V_13 ) {
V_9 = V_11 ;
if ( V_9 -> V_14 != V_15 ) {
F_2 ( V_2 -> V_16 ,
L_1 ,
V_3 ) ;
return - V_17 ;
}
if ( V_9 -> V_4 == V_4 ) {
if ( V_44 != NULL )
* V_44 = V_11 + sizeof( * V_9 ) + V_9 -> V_19 ;
if ( V_5 != NULL )
* V_5 = V_9 -> V_5 - V_9 -> V_22 ;
return 0 ;
}
V_11 += sizeof( * V_9 ) + V_9 -> V_19 + V_9 -> V_5 ;
}
return - V_52 ;
}
int F_12 ( unsigned V_3 , unsigned V_4 , void * * V_44 , T_1 * V_5 )
{
unsigned long V_36 ;
int V_37 ;
if ( ! V_38 )
return - V_39 ;
V_37 = F_8 ( V_38 -> V_41 ,
V_42 ,
& V_36 ) ;
if ( V_37 )
return V_37 ;
if ( V_3 < V_43 && V_38 -> V_12 [ V_3 ] )
V_37 = F_11 ( V_38 , V_3 , V_4 , V_44 , V_5 ) ;
else
V_37 = F_10 ( V_38 , V_4 , V_44 , V_5 ) ;
F_9 ( V_38 -> V_41 , & V_36 ) ;
return V_37 ;
}
int F_13 ( unsigned V_3 )
{
struct V_6 * V_7 ;
struct V_23 * V_24 ;
unsigned V_37 ;
if ( ! V_38 )
return - V_39 ;
if ( V_3 < V_43 && V_38 -> V_12 [ V_3 ] ) {
V_7 = V_38 -> V_12 [ V_3 ] ;
V_37 = V_7 -> V_20 - V_7 -> V_13 ;
} else {
V_24 = V_38 -> V_28 [ 0 ] . V_29 ;
V_37 = V_24 -> V_32 ;
}
return V_37 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned * V_53 ;
T_1 V_5 ;
int V_37 ;
V_37 = F_10 ( V_2 , V_54 ,
( void * * ) & V_53 , & V_5 ) ;
if ( V_37 < 0 ) {
F_2 ( V_2 -> V_16 , L_4 ) ;
return - V_52 ;
}
if ( V_5 < sizeof( unsigned ) * V_55 ) {
F_2 ( V_2 -> V_16 , L_5 ) ;
return - V_17 ;
}
return V_53 [ V_55 ] ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_56 )
{
struct V_6 * V_24 ;
struct V_57 * V_26 ;
struct V_58 * V_59 ;
unsigned V_60 ;
int V_48 ;
V_59 = V_2 -> V_28 [ 0 ] . V_29 + V_2 -> V_28 [ 0 ] . V_5 - V_61 ;
if ( V_59 -> V_62 != V_63 )
return 0 ;
if ( V_59 -> V_64 != 1 ) {
F_2 ( V_2 -> V_16 ,
L_6 ,
V_59 -> V_64 ) ;
return - V_17 ;
}
for ( V_48 = 0 ; V_48 < V_59 -> V_65 ; V_48 ++ ) {
V_26 = & V_59 -> V_26 [ V_48 ] ;
if ( V_26 -> V_66 != V_56 && V_26 -> V_67 != V_56 )
continue;
if ( ! V_26 -> V_34 )
continue;
if ( ! V_26 -> V_5 )
continue;
if ( V_26 -> V_66 == V_56 )
V_60 = V_26 -> V_67 ;
else
V_60 = V_26 -> V_66 ;
if ( V_60 >= V_43 ) {
F_2 ( V_2 -> V_16 ,
L_7 ,
V_60 ) ;
return - V_17 ;
}
if ( V_2 -> V_12 [ V_60 ] ) {
F_2 ( V_2 -> V_16 ,
L_8 ,
V_60 ) ;
return - V_17 ;
}
V_24 = V_2 -> V_28 [ 0 ] . V_29 + V_26 -> V_34 ;
if ( V_24 -> V_62 != V_68 ) {
F_2 ( V_2 -> V_16 ,
L_9 , V_48 ) ;
return - V_17 ;
}
if ( V_24 -> V_66 != V_56 && V_24 -> V_67 != V_56 ) {
F_2 ( V_2 -> V_16 ,
L_10 , V_48 ) ;
return - V_17 ;
}
if ( V_24 -> V_66 != V_60 && V_24 -> V_67 != V_60 ) {
F_2 ( V_2 -> V_16 ,
L_10 , V_48 ) ;
return - V_17 ;
}
if ( V_24 -> V_5 != V_26 -> V_5 ) {
F_2 ( V_2 -> V_16 ,
L_11 , V_48 ) ;
return - V_17 ;
}
if ( V_24 -> V_13 > V_24 -> V_5 ) {
F_2 ( V_2 -> V_16 ,
L_12 , V_48 ) ;
return - V_17 ;
}
V_2 -> V_12 [ V_60 ] = V_24 ;
}
return 0 ;
}
static int F_16 ( struct V_69 * V_70 )
{
struct V_71 * V_72 ;
int V_51 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_70 -> V_73 ; V_48 ++ ) {
V_72 = & V_70 -> V_71 [ V_48 ] ;
if ( F_17 ( V_72 ) == V_74 )
V_51 ++ ;
}
return V_51 ;
}
static int F_18 ( struct V_69 * V_70 )
{
struct V_23 * V_24 ;
struct V_75 * V_76 ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_71 V_77 ;
T_1 V_78 ;
int V_51 = 0 ;
int V_79 ;
T_2 V_64 ;
int V_37 ;
int V_48 ;
V_51 = F_16 ( V_70 ) + 1 ;
V_78 = V_51 * sizeof( struct V_45 ) ;
V_2 = F_19 ( & V_70 -> V_16 , sizeof( * V_2 ) + V_78 , V_80 ) ;
if ( ! V_2 )
return - V_33 ;
V_2 -> V_16 = & V_70 -> V_16 ;
V_2 -> V_51 = V_51 ;
V_76 = F_20 ( V_70 -> V_16 . V_81 , L_13 , 0 ) ;
if ( ! V_76 ) {
F_2 ( & V_70 -> V_16 , L_14 ) ;
return - V_17 ;
}
V_37 = F_21 ( V_76 , 0 , & V_77 ) ;
F_22 ( V_76 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_28 [ 0 ] . V_47 = ( T_2 ) V_77 . V_82 ;
V_2 -> V_28 [ 0 ] . V_5 = F_23 ( & V_77 ) ;
V_2 -> V_28 [ 0 ] . V_29 = F_24 ( & V_70 -> V_16 ,
V_77 . V_82 ,
F_23 ( & V_77 ) ) ;
if ( ! V_2 -> V_28 [ 0 ] . V_29 )
return - V_33 ;
for ( V_48 = 1 ; V_48 < V_51 ; V_48 ++ ) {
V_72 = F_25 ( V_70 , V_74 , V_48 - 1 ) ;
V_2 -> V_28 [ V_48 ] . V_47 = ( T_2 ) V_72 -> V_82 ;
V_2 -> V_28 [ V_48 ] . V_5 = F_23 ( V_72 ) ;
V_2 -> V_28 [ V_48 ] . V_29 = F_24 ( & V_70 -> V_16 ,
V_72 -> V_82 ,
F_23 ( V_72 ) ) ;
if ( ! V_2 -> V_28 [ V_48 ] . V_29 )
return - V_33 ;
}
V_24 = V_2 -> V_28 [ 0 ] . V_29 ;
if ( V_24 -> V_83 != 1 || V_24 -> V_84 ) {
F_2 ( & V_70 -> V_16 , L_15 ) ;
return - V_17 ;
}
V_64 = F_14 ( V_2 ) ;
if ( V_64 >> 16 != V_85 ) {
F_2 ( & V_70 -> V_16 , L_16 , V_64 ) ;
return - V_17 ;
}
V_37 = F_15 ( V_2 , V_86 ) ;
if ( V_37 < 0 )
return V_37 ;
V_79 = F_26 ( V_70 -> V_16 . V_81 , 0 ) ;
if ( V_79 < 0 ) {
F_2 ( & V_70 -> V_16 , L_17 ) ;
return V_79 ;
}
V_2 -> V_41 = F_27 ( V_79 ) ;
if ( ! V_2 -> V_41 )
return - V_49 ;
V_38 = V_2 ;
return 0 ;
}
static int F_28 ( struct V_69 * V_70 )
{
V_38 = NULL ;
F_29 ( V_38 -> V_41 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_87 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_87 ) ;
}
