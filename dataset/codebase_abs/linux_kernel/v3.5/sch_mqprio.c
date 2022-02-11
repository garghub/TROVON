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
V_2 -> V_42 |= V_43 ;
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
unsigned long V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_44 - 1 - F_24 ( V_4 ) ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_14 ( V_4 , V_7 ) ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_44 , struct V_1 * V_45 ,
struct V_1 * * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_23 ( V_2 , V_44 ) ;
if ( ! V_30 )
return - V_19 ;
if ( V_4 -> V_42 & V_47 )
F_26 ( V_4 ) ;
* V_46 = F_22 ( V_30 , V_45 ) ;
if ( V_4 -> V_42 & V_47 )
F_27 ( V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned char * V_50 = F_29 ( V_49 ) ;
struct V_13 V_28 = { 0 } ;
struct V_1 * V_31 ;
unsigned int V_15 ;
V_2 -> V_51 . V_52 = 0 ;
memset ( & V_2 -> V_53 , 0 , sizeof( V_2 -> V_53 ) ) ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_9 ; V_15 ++ ) {
V_31 = F_14 ( V_4 , V_15 ) -> V_31 ;
F_30 ( F_31 ( V_31 ) ) ;
V_2 -> V_51 . V_52 += V_31 -> V_51 . V_52 ;
V_2 -> V_53 . V_55 += V_31 -> V_53 . V_55 ;
V_2 -> V_53 . V_56 += V_31 -> V_53 . V_56 ;
V_2 -> V_54 . V_52 += V_31 -> V_54 . V_52 ;
V_2 -> V_54 . V_57 += V_31 -> V_54 . V_57 ;
V_2 -> V_54 . V_58 += V_31 -> V_54 . V_58 ;
V_2 -> V_54 . V_59 += V_31 -> V_54 . V_59 ;
V_2 -> V_54 . V_60 += V_31 -> V_54 . V_60 ;
F_32 ( F_31 ( V_31 ) ) ;
}
V_28 . V_17 = F_24 ( V_4 ) ;
memcpy ( V_28 . V_21 , V_4 -> V_21 , sizeof( V_28 . V_21 ) ) ;
V_28 . V_22 = V_6 -> V_10 ;
for ( V_15 = 0 ; V_15 < F_24 ( V_4 ) ; V_15 ++ ) {
V_28 . V_25 [ V_15 ] = V_4 -> V_61 [ V_15 ] . V_25 ;
V_28 . V_24 [ V_15 ] = V_4 -> V_61 [ V_15 ] . V_24 ;
}
if ( F_33 ( V_49 , V_62 , sizeof( V_28 ) , & V_28 ) )
goto V_63;
return V_49 -> V_64 ;
V_63:
F_34 ( V_49 , V_50 ) ;
return - 1 ;
}
static struct V_1 * F_35 ( struct V_1 * V_2 , unsigned long V_44 )
{
struct V_29 * V_30 = F_23 ( V_2 , V_44 ) ;
if ( ! V_30 )
return NULL ;
return V_30 -> V_65 ;
}
static unsigned long F_36 ( struct V_1 * V_2 , T_1 V_66 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 = F_18 ( V_66 ) ;
if ( V_7 > V_4 -> V_9 + F_24 ( V_4 ) )
return 0 ;
return V_7 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_44 )
{
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_44 ,
struct V_48 * V_49 , struct V_67 * V_68 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_44 <= F_24 ( V_4 ) ) {
V_68 -> V_69 = V_37 ;
V_68 -> V_70 = 0 ;
} else {
int V_15 ;
struct V_29 * V_30 ;
V_30 = F_23 ( V_2 , V_44 ) ;
V_68 -> V_69 = 0 ;
for ( V_15 = 0 ; V_15 < F_24 ( V_4 ) ; V_15 ++ ) {
struct V_71 V_72 = V_4 -> V_61 [ V_15 ] ;
int V_73 = V_44 - F_24 ( V_4 ) ;
if ( V_73 > V_72 . V_24 &&
V_73 <= V_72 . V_24 + V_72 . V_25 ) {
V_68 -> V_69 =
F_16 ( F_17 ( V_2 -> V_41 ) ,
F_18 ( V_15 + 1 ) ) ;
break;
}
}
V_68 -> V_70 = V_30 -> V_65 -> V_41 ;
}
V_68 -> V_74 |= F_18 ( V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_44 ,
struct V_75 * V_76 )
__releases( V_76 -> V_77 )
__acquires( V_76 -> V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_44 <= F_24 ( V_4 ) ) {
int V_15 ;
struct V_1 * V_31 ;
struct V_78 V_54 = { 0 } ;
struct V_79 V_53 = { 0 } ;
struct V_71 V_72 = V_4 -> V_61 [ V_44 - 1 ] ;
F_32 ( V_76 -> V_77 ) ;
for ( V_15 = V_72 . V_24 ; V_15 < V_72 . V_24 + V_72 . V_25 ; V_15 ++ ) {
V_31 = F_14 ( V_4 , V_15 ) -> V_31 ;
F_30 ( F_31 ( V_31 ) ) ;
V_53 . V_55 += V_31 -> V_53 . V_55 ;
V_53 . V_56 += V_31 -> V_53 . V_56 ;
V_54 . V_52 += V_31 -> V_54 . V_52 ;
V_54 . V_57 += V_31 -> V_54 . V_57 ;
V_54 . V_58 += V_31 -> V_54 . V_58 ;
V_54 . V_59 += V_31 -> V_54 . V_59 ;
V_54 . V_60 += V_31 -> V_54 . V_60 ;
F_32 ( F_31 ( V_31 ) ) ;
}
F_30 ( V_76 -> V_77 ) ;
if ( F_40 ( V_76 , & V_53 ) < 0 ||
F_41 ( V_76 , & V_54 ) < 0 )
return - 1 ;
} else {
struct V_29 * V_30 = F_23 ( V_2 , V_44 ) ;
V_2 = V_30 -> V_65 ;
V_2 -> V_54 . V_52 = V_2 -> V_51 . V_52 ;
if ( F_40 ( V_76 , & V_2 -> V_53 ) < 0 ||
F_41 ( V_76 , & V_2 -> V_54 ) < 0 )
return - 1 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 ;
if ( V_81 -> V_82 )
return;
V_81 -> V_25 = V_81 -> V_83 ;
for ( V_7 = V_81 -> V_83 ;
V_7 < V_4 -> V_9 + F_24 ( V_4 ) ;
V_7 ++ ) {
if ( V_81 -> V_84 ( V_2 , V_7 + 1 , V_81 ) < 0 ) {
V_81 -> V_82 = 1 ;
break;
}
V_81 -> V_25 ++ ;
}
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_85 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_85 ) ;
}
