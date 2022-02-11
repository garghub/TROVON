static void
F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( ( V_4 * ) V_3 ) ;
}
static inline int
F_3 ( struct V_5 * V_6 )
{
return V_6 -> V_7 && F_4 ( V_6 -> V_8 ) ;
}
static int
F_5 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_11 ;
V_6 = (struct V_5 * ) V_10 ;
V_2 -> V_12 = F_1 ;
V_2 -> V_13 = & V_6 -> V_14 ;
do {
if ( ! F_3 ( V_6 ) ) {
V_11 = F_6 ( V_6 -> V_14 ,
F_3 ( V_6 ) ) ;
if ( V_11 != 0 )
break;
}
V_11 = F_7 ( V_10 , V_2 ) ;
if ( V_11 == 0 ) {
F_8 ( V_6 -> V_14 , F_4 ( V_2 ) ) ;
}
} while ( V_11 == - V_15 );
return V_11 ;
}
static void
F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_2 -> V_10 ;
F_10 ( V_2 ) ;
F_2 ( & V_6 -> V_14 ) ;
}
static void
F_11 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_2 -> V_10 ;
if ( V_2 -> V_11 != 0 || V_2 -> V_16 != 0 ) {
if ( V_6 -> V_17 )
F_12 ( V_6 -> V_17 , V_18 , 1 ) ;
}
V_6 -> V_19 = 0 ;
F_10 ( V_2 ) ;
F_2 ( & V_6 -> V_14 ) ;
}
static int
F_13 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
char * V_20 ;
int V_11 ;
V_6 = (struct V_5 * ) V_10 ;
if ( ! F_4 ( V_6 -> V_8 ) )
return 0 ;
if ( V_6 -> V_19 == 0 ) {
F_14 ( V_6 -> V_8 , V_21 ) ;
V_6 -> V_8 -> V_12 = F_9 ;
} else {
F_14 ( V_6 -> V_8 , V_21 ) ;
F_15 ( V_6 -> V_8 , V_6 -> V_22 ) ;
V_6 -> V_8 -> V_23 . V_24 = V_6 -> V_19 ;
V_20 = V_6 -> V_22 -> V_3 [ 0 ] ;
V_20 [ 0 ] = V_25 ;
V_20 [ 1 ] = V_26 ;
V_20 [ 2 ] = V_20 [ 6 ] ;
V_20 [ 3 ] = V_20 [ 7 ] ;
V_20 [ 4 ] = V_27 ;
V_20 [ 5 ] = V_26 ;
V_20 [ 6 ] = 0x40 ;
V_20 [ 7 ] = 0x40 ;
V_6 -> V_8 -> V_16 = 0 ;
V_6 -> V_8 -> V_12 = F_11 ;
}
V_11 = V_6 -> V_8 -> V_11 = F_16 ( V_10 , V_6 -> V_8 ) ;
if ( V_11 )
V_6 -> V_8 -> V_12 ( V_6 -> V_8 , NULL ) ;
else
V_6 -> V_7 = 1 ;
return V_11 ;
}
static void
F_17 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_2 -> V_10 ;
V_6 -> V_22 -> V_3 [ 0 ] -= 5 ;
V_6 -> V_22 -> V_28 += 5 ;
if ( V_2 -> V_11 != 0 || V_2 -> V_16 == 0 ) {
if ( V_6 -> V_17 )
F_12 ( V_6 -> V_17 , V_18 , 1 ) ;
V_6 -> V_19 = 0 ;
} else
V_6 -> V_19 = V_6 -> V_22 -> V_28 - V_2 -> V_16 ;
F_10 ( V_2 ) ;
F_2 ( & V_6 -> V_14 ) ;
}
static void
F_18 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_10 ;
V_6 -> V_7 = 0 ;
if ( ! F_4 ( V_6 -> V_8 ) )
return;
F_14 ( V_6 -> V_8 , V_29 ) ;
V_6 -> V_22 -> V_3 [ 0 ] += 5 ;
V_6 -> V_22 -> V_28 -= 5 ;
F_15 ( V_6 -> V_8 , V_6 -> V_22 ) ;
V_6 -> V_8 -> V_16 = 0 ;
V_6 -> V_8 -> V_12 = F_17 ;
V_6 -> V_8 -> V_11 = F_16 ( V_10 , V_6 -> V_8 ) ;
if ( V_6 -> V_8 -> V_11 )
V_6 -> V_8 -> V_12 ( V_6 -> V_8 , NULL ) ;
}
static int
F_19 ( struct V_5 * V_6 , struct V_1 * V_2 , struct V_30 * V_30 )
{
if ( V_30 -> V_31 . V_32 . V_33 & V_34 ) {
V_6 -> V_35 = 1 ;
F_2 ( & V_6 -> V_14 ) ;
}
if ( V_2 ) {
if ( V_30 -> V_31 . V_32 . V_33 & V_36 )
V_2 -> V_11 = - V_37 ;
else
V_2 -> V_16 = V_30 -> V_31 . V_32 . V_24 ;
}
return V_38 ;
}
static T_1
F_20 ( struct V_39 * V_40 , char T_2 * V_3 , T_3 V_24 , T_4 * V_41 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
T_1 V_11 ;
if ( V_24 == 0 || V_24 > 65535 )
return - V_44 ;
V_6 = V_40 -> V_45 ;
if ( ! V_6 )
return - V_46 ;
V_43 = F_21 ( V_24 , 0 ) ;
if ( F_22 ( V_43 ) )
return - V_47 ;
V_2 = F_23 ( 0 ) ;
if ( ! F_22 ( V_2 ) ) {
if ( V_6 -> V_48 == 0 && V_6 -> V_49 != 0 )
V_6 -> V_48 = 6 ;
F_14 ( V_2 , V_6 -> V_48 ? : 2 ) ;
F_15 ( V_2 , V_43 ) ;
V_11 = F_6 ( V_6 -> V_14 , V_6 -> V_35 ) ;
V_6 -> V_35 = 0 ;
if ( V_11 == 0 ) {
V_11 = F_5 ( & V_6 -> V_10 , V_2 ) ;
if ( V_11 == 0 ) {
V_24 -= V_2 -> V_16 ;
if ( F_24 ( V_43 , V_3 , V_24 ) != 0 )
V_11 = - V_50 ;
else
V_11 = V_24 ;
}
}
F_25 ( V_2 ) ;
} else
V_11 = F_26 ( V_2 ) ;
F_27 ( V_43 ) ;
return V_11 ;
}
static T_1
F_28 ( struct V_39 * V_40 , const char T_2 * V_3 , T_3 V_24 , T_4 * V_41 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_49 ;
T_1 V_11 ;
V_6 = V_40 -> V_45 ;
if ( ! V_6 )
return - V_46 ;
V_43 = F_21 ( V_24 , 0 ) ;
if ( F_22 ( V_43 ) )
return - V_47 ;
V_2 = F_23 ( 0 ) ;
if ( ! F_22 ( V_2 ) ) {
if ( F_29 ( V_43 , V_3 , V_24 ) == 0 ) {
V_49 = V_6 -> V_49 ? : 1 ;
if ( V_49 == 5 )
V_49 = 13 ;
F_14 ( V_2 , V_49 ) ;
F_15 ( V_2 , V_43 ) ;
V_11 = F_5 ( & V_6 -> V_10 , V_2 ) ;
if ( V_11 == 0 )
V_11 = V_24 - V_2 -> V_16 ;
} else
V_11 = - V_50 ;
F_25 ( V_2 ) ;
} else
V_11 = F_26 ( V_2 ) ;
F_27 ( V_43 ) ;
return V_11 ;
}
static long
F_30 ( struct V_39 * V_40 , unsigned int V_32 , unsigned long V_51 )
{
char T_2 * V_52 ;
struct V_5 * V_6 ;
struct V_53 V_54 ;
int V_11 ;
V_6 = V_40 -> V_45 ;
if ( ! V_6 )
return - V_46 ;
if ( F_31 () )
V_52 = F_32 ( V_51 ) ;
else
V_52 = ( char T_2 * ) V_51 ;
V_11 = 0 ;
F_33 ( & V_55 ) ;
switch ( V_32 ) {
case V_56 :
V_6 -> V_48 = V_51 ;
break;
case V_57 :
V_6 -> V_49 = V_51 ;
break;
case V_58 :
V_11 = F_34 ( V_6 -> V_48 , V_52 ) ;
break;
case V_59 :
V_11 = F_34 ( V_6 -> V_49 , V_52 ) ;
break;
case V_60 :
V_54 . V_61 = V_6 -> V_10 . V_61 ;
V_54 . V_62 = V_6 -> V_10 . V_63 ;
V_54 . V_64 = V_6 -> V_10 . V_65 ;
V_54 . V_66 = 24 ;
V_54 . V_67 = 20 ;
V_54 . V_68 = 0 ;
if ( F_35 ( V_52 , & V_54 , sizeof( struct V_53 ) ) )
V_11 = - V_50 ;
break;
}
F_36 ( & V_55 ) ;
return V_11 ;
}
static struct V_5 *
F_37 ( void )
{
struct V_5 * V_6 ;
V_6 = F_38 ( sizeof( struct V_5 ) , V_69 ) ;
if ( ! V_6 )
return F_39 ( - V_47 ) ;
V_6 -> V_8 = F_23 ( 0 ) ;
if ( F_22 ( V_6 -> V_8 ) ) {
F_40 ( V_6 ) ;
return F_39 ( - V_47 ) ;
}
return V_6 ;
}
static void
F_41 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_10 ;
if ( V_6 -> V_22 )
F_27 ( V_6 -> V_22 ) ;
F_25 ( ( (struct V_5 * ) V_10 ) -> V_8 ) ;
F_40 ( V_10 ) ;
}
static void
F_42 ( struct V_9 * V_10 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_10 ;
if ( V_6 -> V_17 )
F_12 ( V_6 -> V_17 , V_18 , 1 ) ;
}
static int
F_43 ( struct V_70 * V_70 , struct V_39 * V_40 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
int V_71 , V_11 = 0 ;
if ( F_44 ( V_40 -> V_72 . V_73 -> V_74 ) != V_75 )
return - V_46 ;
V_71 = F_45 ( V_40 -> V_72 . V_73 -> V_74 ) ;
if ( V_71 == 0 ) {
struct V_76 * V_77 = F_46 () ;
if ( ! V_77 || V_77 -> V_78 -> V_79 != V_80 ) {
F_47 ( V_77 ) ;
return - V_46 ;
}
V_71 = V_77 -> V_81 + V_82 ;
F_47 ( V_77 ) ;
}
F_33 ( & V_55 ) ;
V_6 = (struct V_5 * ) F_48 ( & V_83 , V_71 ) ;
if ( ! F_22 ( V_6 ) ) {
F_49 ( & V_6 -> V_10 ) ;
V_11 = - V_84 ;
goto V_85;
}
V_6 = F_37 () ;
if ( F_22 ( V_6 ) ) {
V_11 = F_26 ( V_6 ) ;
goto V_85;
}
F_50 ( & V_6 -> V_14 ) ;
V_6 -> V_17 = F_51 ( F_52 ( V_86 ) ) ;
V_11 = F_53 ( & V_6 -> V_10 , & V_83 , V_71 ) ;
if ( V_11 ) {
F_41 ( & V_6 -> V_10 ) ;
goto V_85;
}
V_43 = F_21 ( 2 * V_6 -> V_10 . V_63 * V_6 -> V_10 . V_65 + 5 , 0 ) ;
if ( F_22 ( V_43 ) ) {
F_49 ( & V_6 -> V_10 ) ;
F_54 ( & V_6 -> V_10 ) ;
V_11 = F_26 ( V_43 ) ;
goto V_85;
}
V_6 -> V_22 = V_43 ;
V_11 = F_55 ( & V_6 -> V_10 ) ;
if ( V_11 ) {
F_49 ( & V_6 -> V_10 ) ;
F_54 ( & V_6 -> V_10 ) ;
goto V_85;
}
F_56 ( V_70 , V_40 ) ;
V_40 -> V_45 = V_6 ;
V_85:
F_36 ( & V_55 ) ;
return V_11 ;
}
static int
F_57 ( struct V_70 * V_70 , struct V_39 * V_40 )
{
struct V_5 * V_6 ;
V_6 = V_40 -> V_45 ;
V_40 -> V_45 = NULL ;
if ( V_6 ) {
F_58 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
F_59 ( & V_6 -> V_10 ) ;
F_49 ( & V_6 -> V_10 ) ;
F_54 ( & V_6 -> V_10 ) ;
}
return 0 ;
}
static int T_5
F_60 ( void )
{
int V_11 ;
V_11 = F_61 ( V_75 , L_1 , & V_87 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void T_6
F_62 ( void )
{
F_63 ( V_75 , L_1 ) ;
}
