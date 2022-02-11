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
if ( V_6 -> V_10 && V_4 -> V_11 -> V_12 ) {
struct V_13 V_14 = { 0 } ;
struct V_15 V_16 = { . type = V_17 ,
{ . V_18 = & V_14 } } ;
V_4 -> V_11 -> V_12 ( V_4 , V_2 -> V_19 , 0 , & V_16 ) ;
} else {
F_6 ( V_4 , 0 ) ;
}
}
static int F_7 ( struct V_3 * V_4 , struct V_13 * V_20 )
{
int V_21 , V_22 ;
if ( V_20 -> V_23 > V_24 )
return - V_25 ;
for ( V_21 = 0 ; V_21 < V_26 + 1 ; V_21 ++ ) {
if ( V_20 -> V_27 [ V_21 ] >= V_20 -> V_23 )
return - V_25 ;
}
if ( V_20 -> V_28 > V_29 )
V_20 -> V_28 = V_29 ;
if ( V_20 -> V_28 )
return V_4 -> V_11 -> V_12 ? 0 : - V_25 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_23 ; V_21 ++ ) {
unsigned int V_30 = V_20 -> V_31 [ V_21 ] + V_20 -> V_32 [ V_21 ] ;
if ( V_20 -> V_31 [ V_21 ] >= V_4 -> V_33 ||
! V_20 -> V_32 [ V_21 ] ||
V_30 > V_4 -> V_33 )
return - V_25 ;
for ( V_22 = V_21 + 1 ; V_22 < V_20 -> V_23 ; V_22 ++ ) {
if ( V_30 > V_20 -> V_31 [ V_22 ] )
return - V_25 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_36 * V_37 ;
struct V_1 * V_38 ;
int V_21 , V_39 = - V_40 ;
struct V_13 * V_20 = NULL ;
F_9 ( V_24 != V_41 ) ;
F_9 ( V_26 != V_42 ) ;
if ( V_2 -> V_43 != V_44 )
return - V_40 ;
if ( ! F_10 ( V_4 ) )
return - V_40 ;
if ( ! V_35 || F_11 ( V_35 ) < sizeof( * V_20 ) )
return - V_25 ;
V_20 = F_12 ( V_35 ) ;
if ( F_7 ( V_4 , V_20 ) )
return - V_25 ;
V_6 -> V_8 = F_13 ( V_4 -> V_9 , sizeof( V_6 -> V_8 [ 0 ] ) ,
V_45 ) ;
if ( ! V_6 -> V_8 )
return - V_46 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_9 ; V_21 ++ ) {
V_37 = F_14 ( V_4 , V_21 ) ;
V_38 = F_15 ( V_37 ,
F_16 ( V_4 , V_21 ) ,
F_17 ( F_18 ( V_2 -> V_19 ) ,
F_19 ( V_21 + 1 ) ) ) ;
if ( ! V_38 )
return - V_46 ;
V_6 -> V_8 [ V_21 ] = V_38 ;
V_38 -> V_47 |= V_48 | V_49 ;
}
if ( V_20 -> V_28 ) {
struct V_13 V_14 = * V_20 ;
struct V_15 V_16 = { . type = V_17 ,
{ . V_18 = & V_14 } } ;
V_39 = V_4 -> V_11 -> V_12 ( V_4 , V_2 -> V_19 , 0 , & V_16 ) ;
if ( V_39 )
return V_39 ;
V_6 -> V_10 = V_14 . V_28 ;
} else {
F_6 ( V_4 , V_20 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_23 ; V_21 ++ )
F_20 ( V_4 , V_21 ,
V_20 -> V_32 [ V_21 ] , V_20 -> V_31 [ V_21 ] ) ;
}
for ( V_21 = 0 ; V_21 < V_26 + 1 ; V_21 ++ )
F_21 ( V_4 , V_21 , V_20 -> V_27 [ V_21 ] ) ;
V_2 -> V_47 |= V_50 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_1 * V_38 , * V_51 ;
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_38 = V_6 -> V_8 [ V_7 ] ;
V_51 = F_23 ( V_38 -> V_37 , V_38 ) ;
if ( V_51 )
F_4 ( V_51 ) ;
if ( V_7 < V_4 -> V_33 )
F_24 ( V_38 , false ) ;
}
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
static struct V_36 * F_25 ( struct V_1 * V_2 ,
unsigned long V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 = V_52 - 1 - F_26 ( V_4 ) ;
if ( V_7 >= V_4 -> V_9 )
return NULL ;
return F_14 ( V_4 , V_7 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_52 , struct V_1 * V_53 ,
struct V_1 * * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_36 * V_37 = F_25 ( V_2 , V_52 ) ;
if ( ! V_37 )
return - V_25 ;
if ( V_4 -> V_47 & V_54 )
F_28 ( V_4 ) ;
* V_51 = F_23 ( V_37 , V_53 ) ;
if ( V_53 )
V_53 -> V_47 |= V_48 | V_49 ;
if ( V_4 -> V_47 & V_54 )
F_29 ( V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned char * V_57 = F_31 ( V_56 ) ;
struct V_13 V_35 = { 0 } ;
struct V_1 * V_38 ;
unsigned int V_21 ;
V_2 -> V_58 . V_59 = 0 ;
memset ( & V_2 -> V_60 , 0 , sizeof( V_2 -> V_60 ) ) ;
memset ( & V_2 -> V_61 , 0 , sizeof( V_2 -> V_61 ) ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_9 ; V_21 ++ ) {
V_38 = F_32 ( F_14 ( V_4 , V_21 ) -> V_38 ) ;
F_33 ( F_34 ( V_38 ) ) ;
V_2 -> V_58 . V_59 += V_38 -> V_58 . V_59 ;
V_2 -> V_60 . V_62 += V_38 -> V_60 . V_62 ;
V_2 -> V_60 . V_63 += V_38 -> V_60 . V_63 ;
V_2 -> V_61 . V_64 += V_38 -> V_61 . V_64 ;
V_2 -> V_61 . V_65 += V_38 -> V_61 . V_65 ;
V_2 -> V_61 . V_66 += V_38 -> V_61 . V_66 ;
V_2 -> V_61 . V_67 += V_38 -> V_61 . V_67 ;
F_35 ( F_34 ( V_38 ) ) ;
}
V_35 . V_23 = F_26 ( V_4 ) ;
memcpy ( V_35 . V_27 , V_4 -> V_27 , sizeof( V_35 . V_27 ) ) ;
V_35 . V_28 = V_6 -> V_10 ;
for ( V_21 = 0 ; V_21 < F_26 ( V_4 ) ; V_21 ++ ) {
V_35 . V_32 [ V_21 ] = V_4 -> V_68 [ V_21 ] . V_32 ;
V_35 . V_31 [ V_21 ] = V_4 -> V_68 [ V_21 ] . V_31 ;
}
if ( F_36 ( V_56 , V_69 , sizeof( V_35 ) , & V_35 ) )
goto V_70;
return V_56 -> V_71 ;
V_70:
F_37 ( V_56 , V_57 ) ;
return - 1 ;
}
static struct V_1 * F_38 ( struct V_1 * V_2 , unsigned long V_52 )
{
struct V_36 * V_37 = F_25 ( V_2 , V_52 ) ;
if ( ! V_37 )
return NULL ;
return V_37 -> V_72 ;
}
static unsigned long F_39 ( struct V_1 * V_2 , T_1 V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 = F_19 ( V_73 ) ;
if ( V_7 > V_4 -> V_9 + F_26 ( V_4 ) )
return 0 ;
return V_7 ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_52 )
{
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_52 ,
struct V_55 * V_56 , struct V_74 * V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_52 <= F_26 ( V_4 ) ) {
V_75 -> V_76 = V_44 ;
V_75 -> V_77 = 0 ;
} else {
int V_21 ;
struct V_36 * V_37 ;
V_37 = F_25 ( V_2 , V_52 ) ;
V_75 -> V_76 = 0 ;
for ( V_21 = 0 ; V_21 < F_26 ( V_4 ) ; V_21 ++ ) {
struct V_78 V_16 = V_4 -> V_68 [ V_21 ] ;
int V_79 = V_52 - F_26 ( V_4 ) ;
if ( V_79 > V_16 . V_31 &&
V_79 <= V_16 . V_31 + V_16 . V_32 ) {
V_75 -> V_76 =
F_17 ( F_18 ( V_2 -> V_19 ) ,
F_19 ( V_21 + 1 ) ) ;
break;
}
}
V_75 -> V_77 = V_37 -> V_72 -> V_19 ;
}
V_75 -> V_80 |= F_19 ( V_52 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned long V_52 ,
struct V_81 * V_82 )
__releases( V_82 -> V_83 )
__acquires( V_82 -> V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_52 <= F_26 ( V_4 ) ) {
int V_21 ;
T_2 V_59 = 0 ;
struct V_1 * V_38 ;
struct V_84 V_61 = { 0 } ;
struct V_85 V_60 = { 0 } ;
struct V_78 V_16 = V_4 -> V_68 [ V_52 - 1 ] ;
if ( V_82 -> V_83 )
F_35 ( V_82 -> V_83 ) ;
for ( V_21 = V_16 . V_31 ; V_21 < V_16 . V_31 + V_16 . V_32 ; V_21 ++ ) {
struct V_36 * V_58 = F_14 ( V_4 , V_21 ) ;
V_38 = F_32 ( V_58 -> V_38 ) ;
F_33 ( F_34 ( V_38 ) ) ;
V_59 += V_38 -> V_58 . V_59 ;
V_60 . V_62 += V_38 -> V_60 . V_62 ;
V_60 . V_63 += V_38 -> V_60 . V_63 ;
V_61 . V_64 += V_38 -> V_61 . V_64 ;
V_61 . V_65 += V_38 -> V_61 . V_65 ;
V_61 . V_66 += V_38 -> V_61 . V_66 ;
V_61 . V_67 += V_38 -> V_61 . V_67 ;
F_35 ( F_34 ( V_38 ) ) ;
}
if ( V_82 -> V_83 )
F_33 ( V_82 -> V_83 ) ;
if ( F_43 ( NULL , V_82 , NULL , & V_60 ) < 0 ||
F_44 ( V_82 , NULL , & V_61 , V_59 ) < 0 )
return - 1 ;
} else {
struct V_36 * V_37 = F_25 ( V_2 , V_52 ) ;
V_2 = V_37 -> V_72 ;
if ( F_43 ( F_45 ( V_2 ) ,
V_82 , NULL , & V_2 -> V_60 ) < 0 ||
F_44 ( V_82 , NULL ,
& V_2 -> V_61 , V_2 -> V_58 . V_59 ) < 0 )
return - 1 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 ;
if ( V_87 -> V_88 )
return;
V_87 -> V_32 = V_87 -> V_89 ;
for ( V_7 = V_87 -> V_89 ;
V_7 < V_4 -> V_9 + F_26 ( V_4 ) ;
V_7 ++ ) {
if ( V_87 -> V_90 ( V_2 , V_7 + 1 , V_87 ) < 0 ) {
V_87 -> V_88 = 1 ;
break;
}
V_87 -> V_32 ++ ;
}
}
static int T_3 F_47 ( void )
{
return F_48 ( & V_91 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_91 ) ;
}
