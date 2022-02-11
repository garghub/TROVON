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
F_9 ( struct V_17 * V_18 ,
struct V_19 * V_8 )
{
T_1 T_2 * V_20 = V_18 -> V_21 ;
V_8 -> V_13 = F_10 ( V_20 + V_22 ) ;
V_8 -> V_14 = F_10 ( V_20 + V_23 ) ;
V_8 -> V_24 = F_10 ( V_20 + V_25 ) ;
V_8 -> V_15 = F_10 ( V_20 + V_26 ) ;
V_8 -> V_16 = F_10 ( V_20 + V_27 ) ;
V_8 -> V_28 = F_10 ( V_20 + V_29 ) ;
}
static void
F_11 ( struct V_17 * V_18 ,
struct V_19 * V_8 )
{
V_8 -> V_13 = F_10 ( V_18 -> V_30 + V_31 ) ;
V_8 -> V_14 = F_10 ( V_18 -> V_30 + V_32 ) ;
V_8 -> V_24 = F_10 ( V_18 -> V_30 + V_33 ) ;
V_8 -> V_15 = F_10 ( V_18 -> V_30 + V_34 ) ;
V_8 -> V_16 = F_10 ( V_18 -> V_30 + V_35 ) ;
V_8 -> V_28 = F_10 ( V_18 -> V_30 + V_36 ) ;
}
static void
F_12 ( struct V_1 * V_2 , struct V_19 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_13 ( ! V_6 -> V_18 ) )
return;
switch ( V_6 -> V_18 -> type ) {
case V_37 :
if ( ! F_14 ( V_6 -> V_18 ) )
break;
F_9 ( V_6 -> V_18 , V_8 ) ;
break;
case V_38 :
case V_39 :
F_11 ( V_6 -> V_18 , V_8 ) ;
default:
break;
}
}
static bool
F_15 ( const struct V_1 * V_40 , int V_41 )
{
switch ( V_41 ) {
case V_42 :
return true ;
}
return false ;
}
static int
F_16 ( const struct V_1 * V_2 ,
struct V_19 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 ;
F_17 (i) {
T_3 V_44 , V_45 , V_46 , V_47 , V_48 ;
struct V_7 * V_49 ;
unsigned int V_50 ;
V_49 = F_18 ( V_6 -> V_8 , V_43 ) ;
do {
V_50 = F_19 ( & V_49 -> V_12 ) ;
V_44 = V_49 -> V_14 ;
V_45 = V_49 -> V_13 ;
V_46 = V_49 -> V_11 ;
V_47 = V_49 -> V_16 ;
V_48 = V_49 -> V_15 ;
} while ( F_20 ( & V_49 -> V_12 , V_50 ) );
V_8 -> V_14 += V_44 ;
V_8 -> V_13 += V_45 ;
V_8 -> V_24 += V_46 ;
V_8 -> V_16 += V_47 ;
V_8 -> V_15 += V_48 ;
}
return 0 ;
}
static int
F_21 ( int V_41 , const struct V_1 * V_40 ,
void * V_8 )
{
switch ( V_41 ) {
case V_42 :
return F_16 ( V_40 , V_8 ) ;
}
return - V_51 ;
}
static T_4 F_22 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_3 = V_53 -> V_3 ;
int V_54 ;
F_23 ( V_53 ) ;
F_24 ( (struct V_55 * ) V_6 -> V_56 ) ;
F_25 ( V_53 , (struct V_55 * ) V_6 -> V_56 ) ;
V_53 -> V_40 = V_6 -> V_56 -> V_57 . V_58 . V_59 ;
V_54 = F_26 ( V_53 ) ;
F_1 ( V_2 , V_3 , V_54 ) ;
return V_54 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_60 ;
V_60 = F_28 ( V_6 -> V_61 , V_6 ) ;
if ( V_60 )
return V_60 ;
F_29 ( V_2 , false ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_60 ;
V_60 = F_29 ( V_2 , true ) ;
if ( V_60 )
return V_60 ;
V_60 = F_31 ( V_6 -> V_61 , V_6 ) ;
if ( V_60 )
goto V_62;
return 0 ;
V_62:
F_29 ( V_2 , false ) ;
return V_60 ;
}
static void F_32 ( struct V_5 * V_6 )
{
F_33 ( V_6 -> V_2 ) ;
F_34 ( (struct V_55 * ) V_6 -> V_56 ) ;
F_35 ( V_6 -> V_18 ) ;
}
static void F_36 ( struct V_1 * V_40 ,
struct V_63 * V_64 ,
void * V_65 )
{
F_37 ( & V_64 -> V_66 , & V_67 ) ;
}
static void F_38 ( struct V_1 * V_40 )
{
F_37 ( & V_40 -> V_68 , & V_69 ) ;
F_39 ( V_40 , F_36 , NULL ) ;
}
int F_40 ( struct V_70 * V_61 , struct V_1 * V_2 ,
T_5 V_71 , struct V_17 * V_18 ,
struct V_1 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_60 ;
F_38 ( V_2 ) ;
V_6 -> V_18 = V_18 ;
V_6 -> V_56 = F_41 ( 0 , V_73 , V_74 ) ;
if ( ! V_6 -> V_56 )
return - V_75 ;
V_6 -> V_56 -> V_57 . V_58 . V_76 = V_71 ;
V_6 -> V_56 -> V_57 . V_58 . V_59 = V_72 ;
V_2 -> V_77 = & V_78 ;
V_2 -> V_79 = & V_80 ;
F_42 ( V_2 , & V_81 ) ;
if ( F_43 ( V_61 ) ) {
V_2 -> V_82 |= V_83 ;
V_2 -> V_84 |= V_83 ;
}
V_60 = F_44 ( V_2 ) ;
if ( V_60 )
goto V_85;
return 0 ;
V_85:
F_34 ( (struct V_55 * ) V_6 -> V_56 ) ;
return V_60 ;
}
static void F_45 ( struct V_5 * V_6 )
{
F_46 ( V_6 -> V_8 ) ;
F_47 ( V_6 -> V_2 ) ;
}
struct V_1 * F_48 ( struct V_70 * V_61 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_49 ( sizeof( * V_6 ) ) ;
if ( ! V_2 )
return NULL ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_61 = V_61 ;
V_6 -> V_8 = F_50 ( struct V_7 ) ;
if ( ! V_6 -> V_8 )
goto V_86;
return V_2 ;
V_86:
F_47 ( V_2 ) ;
return NULL ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( V_6 -> V_61 -> V_87 , L_1 ,
V_6 -> V_2 -> V_88 ) ;
F_32 ( V_6 ) ;
F_45 ( V_6 ) ;
}
void F_53 ( struct V_89 * V_90 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_90 -> V_91 ; V_43 ++ )
if ( V_90 -> V_90 [ V_43 ] )
F_51 ( F_2 ( V_90 -> V_90 [ V_43 ] ) ) ;
F_54 ( V_90 ) ;
}
void
F_55 ( struct V_70 * V_61 ,
enum V_92 type )
{
struct V_89 * V_90 ;
V_90 = F_56 ( V_61 , type , NULL ) ;
if ( ! V_90 )
return;
F_57 () ;
F_53 ( V_90 ) ;
}
struct V_89 * F_58 ( unsigned int V_91 )
{
struct V_89 * V_90 ;
V_90 = F_59 ( sizeof( * V_90 ) +
V_91 * sizeof( struct V_1 * ) , V_74 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_91 = V_91 ;
return V_90 ;
}
