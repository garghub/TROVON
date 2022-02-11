static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_7 ;
if ( V_6 -> V_8 ) {
for ( V_7 = 0 ;
V_7 < V_4 -> V_9 && V_6 -> V_8 [ V_7 ] ;
V_7 ++ )
F_4 ( V_6 -> V_8 [ V_7 ] ) ;
F_5 ( V_6 -> V_8 ) ;
}
if ( V_6 -> V_10 && V_4 -> V_11 -> V_12 )
V_4 -> V_11 -> V_12 ( V_4 , 0 ) ;
else
F_6 ( V_4 , 0 ) ;
}
static int F_7 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
int V_15 , V_16 ;
if ( V_14 -> V_17 > V_18 )
return - V_19 ;
for ( V_15 = 0 ; V_15 < V_20 + 1 ; V_15 ++ ) {
if ( V_14 -> V_21 [ V_15 ] >= V_14 -> V_17 )
return - V_19 ;
}
if ( V_14 -> V_22 && ! V_4 -> V_11 -> V_12 )
return - V_19 ;
if ( V_14 -> V_22 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_17 ; V_15 ++ ) {
unsigned int V_23 = V_14 -> V_24 [ V_15 ] + V_14 -> V_25 [ V_15 ] ;
if ( V_14 -> V_24 [ V_15 ] >= V_4 -> V_26 ||
! V_14 -> V_25 [ V_15 ] ||
V_23 > V_4 -> V_26 )
return - V_19 ;
for ( V_16 = V_15 + 1 ; V_16 < V_14 -> V_17 ; V_16 ++ ) {
if ( V_23 > V_14 -> V_24 [ V_16 ] )
return - V_19 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_29 * V_30 ;
struct V_1 * V_31 ;
int V_15 , V_32 = - V_33 ;
struct V_13 * V_14 = NULL ;
F_9 ( V_18 != V_34 ) ;
F_9 ( V_20 != V_35 ) ;
if ( V_2 -> V_36 != V_37 )
return - V_33 ;
if ( ! F_10 ( V_4 ) )
return - V_33 ;
if ( ! V_28 || F_11 ( V_28 ) < sizeof( * V_14 ) )
return - V_19 ;
V_14 = F_12 ( V_28 ) ;
if ( F_7 ( V_4 , V_14 ) )
return - V_19 ;
V_6 -> V_8 = F_13 ( V_4 -> V_9 , sizeof( V_6 -> V_8 [ 0 ] ) ,
V_38 ) ;
if ( V_6 -> V_8 == NULL ) {
V_32 = - V_39 ;
goto V_32;
}
for ( V_15 = 0 ; V_15 < V_4 -> V_9 ; V_15 ++ ) {
V_30 = F_14 ( V_4 , V_15 ) ;
V_31 = F_15 ( V_30 , & V_40 ,
F_16 ( F_17 ( V_2 -> V_41 ) ,
F_18 ( V_15 + 1 ) ) ) ;
if ( V_31 == NULL ) {
V_32 = - V_39 ;
goto V_32;
}
V_6 -> V_8 [ V_15 ] = V_31 ;
V_31 -> V_42 |= V_43 ;
}
if ( V_14 -> V_22 ) {
V_6 -> V_10 = 1 ;
V_32 = V_4 -> V_11 -> V_12 ( V_4 , V_14 -> V_17 ) ;
if ( V_32 )
goto V_32;
} else {
F_6 ( V_4 , V_14 -> V_17 ) ;
for ( V_15 = 0 ; V_15 < V_14 -> V_17 ; V_15 ++ )
F_19 ( V_4 , V_15 ,
V_14 -> V_25 [ V_15 ] , V_14 -> V_24 [ V_15 ] ) ;
}
for ( V_15 = 0 ; V_15 < V_20 + 1 ; V_15 ++ )
F_20 ( V_4 , V_15 , V_14 -> V_21 [ V_15 ] ) ;
V_2 -> V_42 |= V_44 ;
return 0 ;
V_32:
F_1 ( V_2 ) ;
return V_32 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_31 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_31 = V_6 -> V_8 [ V_7 ] ;
V_31 = F_22 ( V_31 -> V_30 , V_31 ) ;
if ( V_31 )
F_4 ( V_31 ) ;
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static struct V_29 * F_23 ( struct V_1 * V_2 ,
unsigned long V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_45 - 1 - F_24 ( V_4 ) ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_14 ( V_4 , V_7 ) ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_45 , struct V_1 * V_46 ,
struct V_1 * * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_23 ( V_2 , V_45 ) ;
if ( ! V_30 )
return - V_19 ;
if ( V_4 -> V_42 & V_48 )
F_26 ( V_4 ) ;
* V_47 = F_22 ( V_30 , V_46 ) ;
if ( V_46 )
V_46 -> V_42 |= V_43 ;
if ( V_4 -> V_42 & V_48 )
F_27 ( V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned char * V_51 = F_29 ( V_50 ) ;
struct V_13 V_28 = { 0 } ;
struct V_1 * V_31 ;
unsigned int V_15 ;
V_2 -> V_52 . V_53 = 0 ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
memset ( & V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_9 ; V_15 ++ ) {
V_31 = F_14 ( V_4 , V_15 ) -> V_31 ;
F_30 ( F_31 ( V_31 ) ) ;
V_2 -> V_52 . V_53 += V_31 -> V_52 . V_53 ;
V_2 -> V_54 . V_56 += V_31 -> V_54 . V_56 ;
V_2 -> V_54 . V_57 += V_31 -> V_54 . V_57 ;
V_2 -> V_55 . V_53 += V_31 -> V_55 . V_53 ;
V_2 -> V_55 . V_58 += V_31 -> V_55 . V_58 ;
V_2 -> V_55 . V_59 += V_31 -> V_55 . V_59 ;
V_2 -> V_55 . V_60 += V_31 -> V_55 . V_60 ;
V_2 -> V_55 . V_61 += V_31 -> V_55 . V_61 ;
F_32 ( F_31 ( V_31 ) ) ;
}
V_28 . V_17 = F_24 ( V_4 ) ;
memcpy ( V_28 . V_21 , V_4 -> V_21 , sizeof( V_28 . V_21 ) ) ;
V_28 . V_22 = V_6 -> V_10 ;
for ( V_15 = 0 ; V_15 < F_24 ( V_4 ) ; V_15 ++ ) {
V_28 . V_25 [ V_15 ] = V_4 -> V_62 [ V_15 ] . V_25 ;
V_28 . V_24 [ V_15 ] = V_4 -> V_62 [ V_15 ] . V_24 ;
}
if ( F_33 ( V_50 , V_63 , sizeof( V_28 ) , & V_28 ) )
goto V_64;
return V_50 -> V_65 ;
V_64:
F_34 ( V_50 , V_51 ) ;
return - 1 ;
}
static struct V_1 * F_35 ( struct V_1 * V_2 , unsigned long V_45 )
{
struct V_29 * V_30 = F_23 ( V_2 , V_45 ) ;
if ( ! V_30 )
return NULL ;
return V_30 -> V_66 ;
}
static unsigned long F_36 ( struct V_1 * V_2 , T_1 V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 = F_18 ( V_67 ) ;
if ( V_7 > V_4 -> V_9 + F_24 ( V_4 ) )
return 0 ;
return V_7 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_45 )
{
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_45 ,
struct V_49 * V_50 , struct V_68 * V_69 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_45 <= F_24 ( V_4 ) ) {
V_69 -> V_70 = V_37 ;
V_69 -> V_71 = 0 ;
} else {
int V_15 ;
struct V_29 * V_30 ;
V_30 = F_23 ( V_2 , V_45 ) ;
V_69 -> V_70 = 0 ;
for ( V_15 = 0 ; V_15 < F_24 ( V_4 ) ; V_15 ++ ) {
struct V_72 V_73 = V_4 -> V_62 [ V_15 ] ;
int V_74 = V_45 - F_24 ( V_4 ) ;
if ( V_74 > V_73 . V_24 &&
V_74 <= V_73 . V_24 + V_73 . V_25 ) {
V_69 -> V_70 =
F_16 ( F_17 ( V_2 -> V_41 ) ,
F_18 ( V_15 + 1 ) ) ;
break;
}
}
V_69 -> V_71 = V_30 -> V_66 -> V_41 ;
}
V_69 -> V_75 |= F_18 ( V_45 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_45 ,
struct V_76 * V_77 )
__releases( V_77 -> V_78 )
__acquires( V_77 -> V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_45 <= F_24 ( V_4 ) ) {
int V_15 ;
struct V_1 * V_31 ;
struct V_79 V_55 = { 0 } ;
struct V_80 V_54 = { 0 } ;
struct V_72 V_73 = V_4 -> V_62 [ V_45 - 1 ] ;
F_32 ( V_77 -> V_78 ) ;
for ( V_15 = V_73 . V_24 ; V_15 < V_73 . V_24 + V_73 . V_25 ; V_15 ++ ) {
V_31 = F_14 ( V_4 , V_15 ) -> V_31 ;
F_30 ( F_31 ( V_31 ) ) ;
V_54 . V_56 += V_31 -> V_54 . V_56 ;
V_54 . V_57 += V_31 -> V_54 . V_57 ;
V_55 . V_53 += V_31 -> V_55 . V_53 ;
V_55 . V_58 += V_31 -> V_55 . V_58 ;
V_55 . V_59 += V_31 -> V_55 . V_59 ;
V_55 . V_60 += V_31 -> V_55 . V_60 ;
V_55 . V_61 += V_31 -> V_55 . V_61 ;
F_32 ( F_31 ( V_31 ) ) ;
}
F_30 ( V_77 -> V_78 ) ;
if ( F_40 ( V_77 , & V_54 ) < 0 ||
F_41 ( V_77 , & V_55 ) < 0 )
return - 1 ;
} else {
struct V_29 * V_30 = F_23 ( V_2 , V_45 ) ;
V_2 = V_30 -> V_66 ;
V_2 -> V_55 . V_53 = V_2 -> V_52 . V_53 ;
if ( F_40 ( V_77 , & V_2 -> V_54 ) < 0 ||
F_41 ( V_77 , & V_2 -> V_55 ) < 0 )
return - 1 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 ;
if ( V_82 -> V_83 )
return;
V_82 -> V_25 = V_82 -> V_84 ;
for ( V_7 = V_82 -> V_84 ;
V_7 < V_4 -> V_9 + F_24 ( V_4 ) ;
V_7 ++ ) {
if ( V_82 -> V_85 ( V_2 , V_7 + 1 , V_82 ) < 0 ) {
V_82 -> V_83 = 1 ;
break;
}
V_82 -> V_25 ++ ;
}
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_86 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_86 ) ;
}
