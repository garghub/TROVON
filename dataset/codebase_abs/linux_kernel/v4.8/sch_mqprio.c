static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 V_8 = { . type = V_9 } ;
unsigned int V_10 ;
if ( V_6 -> V_11 ) {
for ( V_10 = 0 ;
V_10 < V_4 -> V_12 && V_6 -> V_11 [ V_10 ] ;
V_10 ++ )
F_4 ( V_6 -> V_11 [ V_10 ] ) ;
F_5 ( V_6 -> V_11 ) ;
}
if ( V_6 -> V_13 && V_4 -> V_14 -> V_15 )
V_4 -> V_14 -> V_15 ( V_4 , V_2 -> V_16 , 0 , & V_8 ) ;
else
F_6 ( V_4 , 0 ) ;
}
static int F_7 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
int V_19 , V_20 ;
if ( V_18 -> V_21 > V_22 )
return - V_23 ;
for ( V_19 = 0 ; V_19 < V_24 + 1 ; V_19 ++ ) {
if ( V_18 -> V_25 [ V_19 ] >= V_18 -> V_21 )
return - V_23 ;
}
if ( V_18 -> V_26 && ! V_4 -> V_14 -> V_15 )
return - V_23 ;
if ( V_18 -> V_26 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_21 ; V_19 ++ ) {
unsigned int V_27 = V_18 -> V_28 [ V_19 ] + V_18 -> V_29 [ V_19 ] ;
if ( V_18 -> V_28 [ V_19 ] >= V_4 -> V_30 ||
! V_18 -> V_29 [ V_19 ] ||
V_27 > V_4 -> V_30 )
return - V_23 ;
for ( V_20 = V_19 + 1 ; V_20 < V_18 -> V_21 ; V_20 ++ ) {
if ( V_27 > V_18 -> V_28 [ V_20 ] )
return - V_23 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_33 * V_34 ;
struct V_1 * V_35 ;
int V_19 , V_36 = - V_37 ;
struct V_17 * V_18 = NULL ;
F_9 ( V_22 != V_38 ) ;
F_9 ( V_24 != V_39 ) ;
if ( V_2 -> V_40 != V_41 )
return - V_37 ;
if ( ! F_10 ( V_4 ) )
return - V_37 ;
if ( ! V_32 || F_11 ( V_32 ) < sizeof( * V_18 ) )
return - V_23 ;
V_18 = F_12 ( V_32 ) ;
if ( F_7 ( V_4 , V_18 ) )
return - V_23 ;
V_6 -> V_11 = F_13 ( V_4 -> V_12 , sizeof( V_6 -> V_11 [ 0 ] ) ,
V_42 ) ;
if ( V_6 -> V_11 == NULL ) {
V_36 = - V_43 ;
goto V_36;
}
for ( V_19 = 0 ; V_19 < V_4 -> V_12 ; V_19 ++ ) {
V_34 = F_14 ( V_4 , V_19 ) ;
V_35 = F_15 ( V_34 ,
F_16 ( V_4 , V_19 ) ,
F_17 ( F_18 ( V_2 -> V_16 ) ,
F_19 ( V_19 + 1 ) ) ) ;
if ( V_35 == NULL ) {
V_36 = - V_43 ;
goto V_36;
}
V_6 -> V_11 [ V_19 ] = V_35 ;
V_35 -> V_44 |= V_45 | V_46 ;
}
if ( V_18 -> V_26 ) {
struct V_7 V_8 = { . type = V_9 ,
{ . V_8 = V_18 -> V_21 } } ;
V_6 -> V_13 = 1 ;
V_36 = V_4 -> V_14 -> V_15 ( V_4 , V_2 -> V_16 , 0 , & V_8 ) ;
if ( V_36 )
goto V_36;
} else {
F_6 ( V_4 , V_18 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_18 -> V_21 ; V_19 ++ )
F_20 ( V_4 , V_19 ,
V_18 -> V_29 [ V_19 ] , V_18 -> V_28 [ V_19 ] ) ;
}
for ( V_19 = 0 ; V_19 < V_24 + 1 ; V_19 ++ )
F_21 ( V_4 , V_19 , V_18 -> V_25 [ V_19 ] ) ;
V_2 -> V_44 |= V_47 ;
return 0 ;
V_36:
F_1 ( V_2 ) ;
return V_36 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_35 , * V_48 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_12 ; V_10 ++ ) {
V_35 = V_6 -> V_11 [ V_10 ] ;
V_48 = F_23 ( V_35 -> V_34 , V_35 ) ;
if ( V_48 )
F_4 ( V_48 ) ;
if ( V_10 < V_4 -> V_30 )
F_24 ( V_35 ) ;
}
F_5 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
static struct V_33 * F_25 ( struct V_1 * V_2 ,
unsigned long V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 = V_49 - 1 - F_26 ( V_4 ) ;
if ( V_10 >= V_4 -> V_12 )
return NULL ;
return F_14 ( V_4 , V_10 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_49 , struct V_1 * V_50 ,
struct V_1 * * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_33 * V_34 = F_25 ( V_2 , V_49 ) ;
if ( ! V_34 )
return - V_23 ;
if ( V_4 -> V_44 & V_51 )
F_28 ( V_4 ) ;
* V_48 = F_23 ( V_34 , V_50 ) ;
if ( V_50 )
V_50 -> V_44 |= V_45 | V_46 ;
if ( V_4 -> V_44 & V_51 )
F_29 ( V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned char * V_54 = F_31 ( V_53 ) ;
struct V_17 V_32 = { 0 } ;
struct V_1 * V_35 ;
unsigned int V_19 ;
V_2 -> V_55 . V_56 = 0 ;
memset ( & V_2 -> V_57 , 0 , sizeof( V_2 -> V_57 ) ) ;
memset ( & V_2 -> V_58 , 0 , sizeof( V_2 -> V_58 ) ) ;
for ( V_19 = 0 ; V_19 < V_4 -> V_12 ; V_19 ++ ) {
V_35 = F_32 ( F_14 ( V_4 , V_19 ) -> V_35 ) ;
F_33 ( F_34 ( V_35 ) ) ;
V_2 -> V_55 . V_56 += V_35 -> V_55 . V_56 ;
V_2 -> V_57 . V_59 += V_35 -> V_57 . V_59 ;
V_2 -> V_57 . V_60 += V_35 -> V_57 . V_60 ;
V_2 -> V_58 . V_61 += V_35 -> V_58 . V_61 ;
V_2 -> V_58 . V_62 += V_35 -> V_58 . V_62 ;
V_2 -> V_58 . V_63 += V_35 -> V_58 . V_63 ;
V_2 -> V_58 . V_64 += V_35 -> V_58 . V_64 ;
F_35 ( F_34 ( V_35 ) ) ;
}
V_32 . V_21 = F_26 ( V_4 ) ;
memcpy ( V_32 . V_25 , V_4 -> V_25 , sizeof( V_32 . V_25 ) ) ;
V_32 . V_26 = V_6 -> V_13 ;
for ( V_19 = 0 ; V_19 < F_26 ( V_4 ) ; V_19 ++ ) {
V_32 . V_29 [ V_19 ] = V_4 -> V_65 [ V_19 ] . V_29 ;
V_32 . V_28 [ V_19 ] = V_4 -> V_65 [ V_19 ] . V_28 ;
}
if ( F_36 ( V_53 , V_66 , sizeof( V_32 ) , & V_32 ) )
goto V_67;
return V_53 -> V_68 ;
V_67:
F_37 ( V_53 , V_54 ) ;
return - 1 ;
}
static struct V_1 * F_38 ( struct V_1 * V_2 , unsigned long V_49 )
{
struct V_33 * V_34 = F_25 ( V_2 , V_49 ) ;
if ( ! V_34 )
return NULL ;
return V_34 -> V_69 ;
}
static unsigned long F_39 ( struct V_1 * V_2 , T_1 V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_10 = F_19 ( V_70 ) ;
if ( V_10 > V_4 -> V_12 + F_26 ( V_4 ) )
return 0 ;
return V_10 ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_49 )
{
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_49 ,
struct V_52 * V_53 , struct V_71 * V_72 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_49 <= F_26 ( V_4 ) ) {
V_72 -> V_73 = V_41 ;
V_72 -> V_74 = 0 ;
} else {
int V_19 ;
struct V_33 * V_34 ;
V_34 = F_25 ( V_2 , V_49 ) ;
V_72 -> V_73 = 0 ;
for ( V_19 = 0 ; V_19 < F_26 ( V_4 ) ; V_19 ++ ) {
struct V_75 V_8 = V_4 -> V_65 [ V_19 ] ;
int V_76 = V_49 - F_26 ( V_4 ) ;
if ( V_76 > V_8 . V_28 &&
V_76 <= V_8 . V_28 + V_8 . V_29 ) {
V_72 -> V_73 =
F_17 ( F_18 ( V_2 -> V_16 ) ,
F_19 ( V_19 + 1 ) ) ;
break;
}
}
V_72 -> V_74 = V_34 -> V_69 -> V_16 ;
}
V_72 -> V_77 |= F_19 ( V_49 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned long V_49 ,
struct V_78 * V_79 )
__releases( V_79 -> V_80 )
__acquires( V_79 -> V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_49 <= F_26 ( V_4 ) ) {
int V_19 ;
T_2 V_56 = 0 ;
struct V_1 * V_35 ;
struct V_81 V_58 = { 0 } ;
struct V_82 V_57 = { 0 } ;
struct V_75 V_8 = V_4 -> V_65 [ V_49 - 1 ] ;
if ( V_79 -> V_80 )
F_35 ( V_79 -> V_80 ) ;
for ( V_19 = V_8 . V_28 ; V_19 < V_8 . V_28 + V_8 . V_29 ; V_19 ++ ) {
struct V_33 * V_55 = F_14 ( V_4 , V_19 ) ;
V_35 = F_32 ( V_55 -> V_35 ) ;
F_33 ( F_34 ( V_35 ) ) ;
V_56 += V_35 -> V_55 . V_56 ;
V_57 . V_59 += V_35 -> V_57 . V_59 ;
V_57 . V_60 += V_35 -> V_57 . V_60 ;
V_58 . V_61 += V_35 -> V_58 . V_61 ;
V_58 . V_62 += V_35 -> V_58 . V_62 ;
V_58 . V_63 += V_35 -> V_58 . V_63 ;
V_58 . V_64 += V_35 -> V_58 . V_64 ;
F_35 ( F_34 ( V_35 ) ) ;
}
if ( V_79 -> V_80 )
F_33 ( V_79 -> V_80 ) ;
if ( F_43 ( NULL , V_79 , NULL , & V_57 ) < 0 ||
F_44 ( V_79 , NULL , & V_58 , V_56 ) < 0 )
return - 1 ;
} else {
struct V_33 * V_34 = F_25 ( V_2 , V_49 ) ;
V_2 = V_34 -> V_69 ;
if ( F_43 ( F_45 ( V_2 ) ,
V_79 , NULL , & V_2 -> V_57 ) < 0 ||
F_44 ( V_79 , NULL ,
& V_2 -> V_58 , V_2 -> V_55 . V_56 ) < 0 )
return - 1 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 ;
if ( V_84 -> V_85 )
return;
V_84 -> V_29 = V_84 -> V_86 ;
for ( V_10 = V_84 -> V_86 ;
V_10 < V_4 -> V_12 + F_26 ( V_4 ) ;
V_10 ++ ) {
if ( V_84 -> V_87 ( V_2 , V_10 + 1 , V_84 ) < 0 ) {
V_84 -> V_85 = 1 ;
break;
}
V_84 -> V_29 ++ ;
}
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_88 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_88 ) ;
}
