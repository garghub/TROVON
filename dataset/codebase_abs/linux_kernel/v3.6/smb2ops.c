static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( 1 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_3 ( 1 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_4 ( struct V_1 * V_2 , const unsigned int V_8 ,
const int V_9 )
{
int * V_10 , V_11 = 0 ;
F_5 ( & V_2 -> V_12 ) ;
V_10 = V_2 -> V_13 -> V_14 ( V_2 , V_9 ) ;
* V_10 += V_8 ;
V_2 -> V_15 -- ;
if ( V_2 -> V_15 == 0 && ( V_9 & V_16 ) != V_17 )
V_11 = F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_18 ) ;
if ( V_11 )
F_8 ( V_2 ) ;
}
static void
F_9 ( struct V_1 * V_2 , const int V_10 )
{
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_3 = V_10 ;
F_6 ( & V_2 -> V_12 ) ;
}
static int *
F_10 ( struct V_1 * V_2 , const int V_9 )
{
switch ( V_9 ) {
case V_19 :
return & V_2 -> V_4 ;
case V_20 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_11 ( struct V_21 * V_22 )
{
return F_12 ( ( (struct V_23 * ) V_22 -> V_24 ) -> V_25 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 )
{
T_1 V_22 ;
F_5 ( & V_26 ) ;
V_22 = V_2 -> V_27 ++ ;
F_6 ( & V_26 ) ;
return V_22 ;
}
static struct V_21 *
F_14 ( struct V_1 * V_2 , char * V_28 )
{
struct V_21 * V_22 ;
struct V_23 * V_29 = (struct V_23 * ) V_28 ;
F_5 ( & V_26 ) ;
F_15 (mid, &server->pending_mid_q, qhead) {
if ( ( V_22 -> V_22 == V_29 -> V_30 ) &&
( V_22 -> V_31 == V_32 ) &&
( V_22 -> V_33 == V_29 -> V_34 ) ) {
F_6 ( & V_26 ) ;
return V_22 ;
}
}
F_6 ( & V_26 ) ;
return NULL ;
}
static void
F_16 ( void * V_28 )
{
#ifdef F_17
struct V_23 * V_35 = (struct V_23 * ) V_28 ;
F_2 ( 1 , L_3 ,
V_35 -> V_34 , V_35 -> V_36 , V_35 -> V_37 , V_35 -> V_30 ,
V_35 -> V_38 ) ;
F_2 ( 1 , L_4 , V_35 , F_18 ( V_35 ) ) ;
#endif
}
static bool
F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_39 == 0 ;
}
static int
F_20 ( const unsigned int V_40 , struct V_41 * V_42 )
{
int V_11 ;
V_42 -> V_2 -> V_27 = 0 ;
V_11 = F_21 ( V_40 , V_42 ) ;
if ( V_11 == - V_43 )
V_11 = - V_44 ;
return V_11 ;
}
static int
F_22 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_47 * V_48 , const char * V_49 )
{
int V_11 ;
T_1 V_50 , V_51 ;
T_2 * V_52 ;
V_52 = F_23 ( V_49 , V_48 ) ;
if ( ! V_52 )
return - V_53 ;
V_11 = F_24 ( V_40 , V_46 , V_52 , & V_50 , & V_51 ,
V_54 , V_55 , 0 , 0 ) ;
if ( V_11 ) {
F_25 ( V_52 ) ;
return V_11 ;
}
V_11 = F_26 ( V_40 , V_46 , V_50 , V_51 ) ;
F_25 ( V_52 ) ;
return V_11 ;
}
static int
F_27 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_47 * V_48 , const char * V_49 ,
T_3 * V_56 , T_4 * V_57 )
{
* V_56 = F_28 ( V_57 -> V_58 ) ;
return 0 ;
}
static char *
F_29 ( struct V_59 * V_60 , struct V_47 * V_48 ,
struct V_45 * V_46 )
{
int V_61 = V_60 -> V_62 ? strlen ( V_60 -> V_62 ) : 0 ;
char * V_49 = NULL ;
if ( V_61 == 0 ) {
V_49 = F_30 ( 2 , V_63 ) ;
return V_49 ;
}
F_2 ( 1 , L_5 ) ;
return NULL ;
}
static bool
F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_32 ( struct V_45 * V_46 )
{
#ifdef F_33
int V_64 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
F_34 ( & V_46 -> V_66 . V_67 . V_68 [ V_64 ] , 0 ) ;
F_34 ( & V_46 -> V_66 . V_67 . V_69 [ V_64 ] , 0 ) ;
}
#endif
}
static void
F_35 ( struct V_70 * V_71 , struct V_45 * V_46 )
{
#ifdef F_33
T_5 * V_72 = V_46 -> V_66 . V_67 . V_68 ;
T_5 * V_73 = V_46 -> V_66 . V_67 . V_69 ;
F_36 ( V_71 , L_6 ,
F_37 ( & V_72 [ V_74 ] ) ,
F_37 ( & V_73 [ V_74 ] ) ) ;
F_36 ( V_71 , L_7 ,
F_37 ( & V_72 [ V_75 ] ) ,
F_37 ( & V_73 [ V_75 ] ) ) ;
#define F_38 0x0002
F_36 ( V_71 , L_8 ,
F_37 ( & V_72 [ V_76 ] ) ,
F_37 ( & V_73 [ V_76 ] ) ) ;
F_36 ( V_71 , L_9 ,
F_37 ( & V_72 [ V_77 ] ) ,
F_37 ( & V_73 [ V_77 ] ) ) ;
F_36 ( V_71 , L_10 ,
F_37 ( & V_72 [ V_78 ] ) ,
F_37 ( & V_73 [ V_78 ] ) ) ;
F_36 ( V_71 , L_11 ,
F_37 ( & V_72 [ V_79 ] ) ,
F_37 ( & V_73 [ V_79 ] ) ) ;
F_36 ( V_71 , L_12 ,
F_37 ( & V_72 [ V_80 ] ) ,
F_37 ( & V_73 [ V_80 ] ) ) ;
F_36 ( V_71 , L_13 ,
F_37 ( & V_72 [ V_81 ] ) ,
F_37 ( & V_73 [ V_81 ] ) ) ;
F_36 ( V_71 , L_14 ,
F_37 ( & V_72 [ V_82 ] ) ,
F_37 ( & V_73 [ V_82 ] ) ) ;
F_36 ( V_71 , L_15 ,
F_37 ( & V_72 [ V_83 ] ) ,
F_37 ( & V_73 [ V_83 ] ) ) ;
F_36 ( V_71 , L_16 ,
F_37 ( & V_72 [ V_84 ] ) ,
F_37 ( & V_73 [ V_84 ] ) ) ;
F_36 ( V_71 , L_17 ,
F_37 ( & V_72 [ V_85 ] ) ,
F_37 ( & V_73 [ V_85 ] ) ) ;
F_36 ( V_71 , L_18 ,
F_37 ( & V_72 [ V_86 ] ) ,
F_37 ( & V_73 [ V_86 ] ) ) ;
F_36 ( V_71 , L_19 ,
F_37 ( & V_72 [ V_87 ] ) ,
F_37 ( & V_73 [ V_87 ] ) ) ;
F_36 ( V_71 , L_20 ,
F_37 ( & V_72 [ V_88 ] ) ,
F_37 ( & V_73 [ V_88 ] ) ) ;
F_36 ( V_71 , L_21 ,
F_37 ( & V_72 [ V_89 ] ) ,
F_37 ( & V_73 [ V_89 ] ) ) ;
F_36 ( V_71 , L_22 ,
F_37 ( & V_72 [ V_90 ] ) ,
F_37 ( & V_73 [ V_90 ] ) ) ;
F_36 ( V_71 , L_23 ,
F_37 ( & V_72 [ V_91 ] ) ,
F_37 ( & V_73 [ V_91 ] ) ) ;
F_36 ( V_71 , L_24 ,
F_37 ( & V_72 [ V_92 ] ) ,
F_37 ( & V_73 [ V_92 ] ) ) ;
#endif
}
