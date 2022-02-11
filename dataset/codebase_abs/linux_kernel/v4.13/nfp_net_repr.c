static void
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
if ( F_3 ( V_4 != V_9 &&
V_4 != V_10 ) ) {
F_4 ( V_6 -> V_8 -> V_11 ) ;
return;
}
V_8 = F_5 ( V_6 -> V_8 ) ;
F_6 ( & V_8 -> V_12 ) ;
V_8 -> V_13 ++ ;
V_8 -> V_14 += V_3 ;
F_7 ( & V_8 -> V_12 ) ;
}
void F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
V_8 = F_5 ( V_6 -> V_8 ) ;
F_6 ( & V_8 -> V_12 ) ;
V_8 -> V_15 ++ ;
V_8 -> V_16 += V_3 ;
F_7 ( & V_8 -> V_12 ) ;
}
static void
F_9 ( const struct V_17 * V_18 , T_1 V_19 ,
struct V_20 * V_8 )
{
T_1 T_2 * V_21 ;
V_21 = V_18 -> V_22 -> V_23 + V_19 * V_24 ;
V_8 -> V_13 = F_10 ( V_21 + V_25 ) ;
V_8 -> V_14 = F_10 ( V_21 + V_26 ) ;
V_8 -> V_27 = F_10 ( V_21 + V_28 ) ;
V_8 -> V_15 = F_10 ( V_21 + V_29 ) ;
V_8 -> V_16 = F_10 ( V_21 + V_30 ) ;
V_8 -> V_31 = F_10 ( V_21 + V_32 ) ;
}
static void
F_11 ( const struct V_17 * V_18 , T_1 V_33 ,
struct V_20 * V_8 )
{
T_1 T_2 * V_21 ;
V_21 = V_18 -> V_22 -> V_34 + V_33 * V_35 ;
V_8 -> V_13 = F_10 ( V_21 + V_36 ) ;
V_8 -> V_14 = F_10 ( V_21 + V_37 ) ;
V_8 -> V_27 = F_10 ( V_21 + V_38 ) ;
V_8 -> V_15 = F_10 ( V_21 + V_39 ) ;
V_8 -> V_16 = F_10 ( V_21 + V_40 ) ;
V_8 -> V_31 = F_10 ( V_21 + V_41 ) ;
}
static void
F_12 ( const struct V_17 * V_18 , T_1 V_22 ,
struct V_20 * V_8 )
{
T_1 T_2 * V_21 ;
if ( V_22 )
return;
V_21 = F_13 ( V_18 -> V_22 -> V_42 ) ;
V_8 -> V_13 = F_10 ( V_21 + V_36 ) ;
V_8 -> V_14 = F_10 ( V_21 + V_37 ) ;
V_8 -> V_27 = F_10 ( V_21 + V_38 ) ;
V_8 -> V_15 = F_10 ( V_21 + V_39 ) ;
V_8 -> V_16 = F_10 ( V_21 + V_40 ) ;
V_8 -> V_31 = F_10 ( V_21 + V_41 ) ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_20 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_43 * V_44 ;
struct V_17 * V_18 = V_6 -> V_18 ;
if ( F_15 ( ! V_6 -> V_45 ) )
return;
switch ( V_6 -> V_45 -> type ) {
case V_46 :
V_44 = F_16 ( V_6 -> V_45 ) ;
if ( ! V_44 )
break;
F_9 ( V_18 , V_44 -> V_47 , V_8 ) ;
break;
case V_48 :
F_12 ( V_18 , V_6 -> V_45 -> V_49 , V_8 ) ;
break;
case V_50 :
F_11 ( V_18 , V_6 -> V_45 -> V_51 , V_8 ) ;
default:
break;
}
}
static bool
F_17 ( const struct V_1 * V_52 , int V_53 )
{
switch ( V_53 ) {
case V_54 :
return true ;
}
return false ;
}
static int
F_18 ( const struct V_1 * V_2 ,
struct V_20 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_55 ;
F_19 (i) {
T_3 V_56 , V_57 , V_58 , V_59 , V_60 ;
struct V_7 * V_61 ;
unsigned int V_62 ;
V_61 = F_20 ( V_6 -> V_8 , V_55 ) ;
do {
V_62 = F_21 ( & V_61 -> V_12 ) ;
V_56 = V_61 -> V_14 ;
V_57 = V_61 -> V_13 ;
V_58 = V_61 -> V_11 ;
V_59 = V_61 -> V_16 ;
V_60 = V_61 -> V_15 ;
} while ( F_22 ( & V_61 -> V_12 , V_62 ) );
V_8 -> V_14 += V_56 ;
V_8 -> V_13 += V_57 ;
V_8 -> V_27 += V_58 ;
V_8 -> V_16 += V_59 ;
V_8 -> V_15 += V_60 ;
}
return 0 ;
}
static int
F_23 ( int V_53 , const struct V_1 * V_52 ,
void * V_8 )
{
switch ( V_53 ) {
case V_54 :
return F_18 ( V_52 , V_8 ) ;
}
return - V_63 ;
}
static T_4 F_24 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_3 = V_65 -> V_3 ;
int V_66 ;
F_25 ( V_65 ) ;
F_26 ( (struct V_67 * ) V_6 -> V_68 ) ;
F_27 ( V_65 , (struct V_67 * ) V_6 -> V_68 ) ;
V_65 -> V_52 = V_6 -> V_68 -> V_69 . V_70 . V_71 ;
V_66 = F_28 ( V_65 ) ;
F_1 ( V_2 , V_3 , V_66 ) ;
return V_66 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_30 ( V_6 -> V_18 , V_6 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_32 ( V_6 -> V_18 , V_6 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
F_34 ( V_6 -> V_2 ) ;
F_35 ( (struct V_67 * ) V_6 -> V_68 ) ;
F_36 ( V_6 -> V_45 ) ;
}
static void F_37 ( struct V_1 * V_52 ,
struct V_72 * V_73 ,
void * V_74 )
{
F_38 ( & V_73 -> V_75 , & V_76 ) ;
}
static void F_39 ( struct V_1 * V_52 )
{
F_38 ( & V_52 -> V_77 , & V_78 ) ;
F_40 ( V_52 , F_37 , NULL ) ;
}
int F_41 ( struct V_17 * V_18 , struct V_1 * V_2 ,
T_5 V_79 , struct V_80 * V_45 ,
struct V_1 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_82 ;
F_39 ( V_2 ) ;
V_6 -> V_45 = V_45 ;
V_6 -> V_68 = F_42 ( 0 , V_83 , V_84 ) ;
if ( ! V_6 -> V_68 )
return - V_85 ;
V_6 -> V_68 -> V_69 . V_70 . V_86 = V_79 ;
V_6 -> V_68 -> V_69 . V_70 . V_71 = V_81 ;
V_2 -> V_87 = & V_88 ;
F_43 ( V_2 , & V_89 ) ;
if ( F_44 ( V_18 ) ) {
V_2 -> V_90 |= V_91 ;
V_2 -> V_92 |= V_91 ;
}
V_82 = F_45 ( V_2 ) ;
if ( V_82 )
goto V_93;
return 0 ;
V_93:
F_35 ( (struct V_67 * ) V_6 -> V_68 ) ;
return V_82 ;
}
static void F_46 ( struct V_5 * V_6 )
{
F_47 ( V_6 -> V_8 ) ;
F_48 ( V_6 -> V_2 ) ;
}
struct V_1 * F_49 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_50 ( sizeof( * V_6 ) ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_18 = V_18 ;
V_6 -> V_8 = F_51 ( struct V_7 ) ;
if ( ! V_6 -> V_8 )
goto V_94;
return V_2 ;
V_94:
F_48 ( V_2 ) ;
return NULL ;
}
static void F_52 ( struct V_5 * V_6 )
{
F_53 ( V_6 -> V_18 -> V_95 , L_1 ,
V_6 -> V_2 -> V_96 ) ;
F_33 ( V_6 ) ;
F_46 ( V_6 ) ;
}
void F_54 ( struct V_97 * V_98 )
{
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_98 -> V_99 ; V_55 ++ )
if ( V_98 -> V_98 [ V_55 ] )
F_52 ( F_2 ( V_98 -> V_98 [ V_55 ] ) ) ;
F_55 ( V_98 ) ;
}
void
F_56 ( struct V_17 * V_18 ,
enum V_100 type )
{
struct V_97 * V_98 ;
V_98 = F_57 ( V_18 , type , NULL ) ;
if ( ! V_98 )
return;
F_58 () ;
F_54 ( V_98 ) ;
}
struct V_97 * F_59 ( unsigned int V_99 )
{
struct V_97 * V_98 ;
V_98 = F_60 ( sizeof( * V_98 ) +
V_99 * sizeof( struct V_1 * ) , V_84 ) ;
if ( ! V_98 )
return NULL ;
V_98 -> V_99 = V_99 ;
return V_98 ;
}
