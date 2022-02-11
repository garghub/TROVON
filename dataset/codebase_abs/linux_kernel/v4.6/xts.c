static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_10 )
return V_10 ;
F_4 ( V_8 , V_11 ) ;
F_5 ( V_8 , F_6 ( V_2 ) &
V_11 ) ;
V_10 = F_7 ( V_8 , V_3 + V_4 / 2 , V_4 / 2 ) ;
if ( V_10 )
return V_10 ;
F_8 ( V_2 , F_9 ( V_8 ) &
V_12 ) ;
V_8 = V_6 -> V_8 ;
F_4 ( V_8 , V_11 ) ;
F_5 ( V_8 , F_6 ( V_2 ) &
V_11 ) ;
V_10 = F_7 ( V_8 , V_3 , V_4 / 2 ) ;
if ( V_10 )
return V_10 ;
F_8 ( V_2 , F_9 ( V_8 ) &
V_12 ) ;
return 0 ;
}
static inline void F_10 ( struct V_13 * V_14 , void * V_15 , const void * V_16 )
{
F_11 ( V_15 , V_14 -> V_17 , V_16 ) ;
V_14 -> V_18 ( V_14 -> V_19 , V_15 , V_15 ) ;
F_11 ( V_15 , V_15 , V_14 -> V_17 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 , struct V_5 * V_6 ,
void (* F_13)( struct V_1 * , T_1 * , const T_1 * ) ,
void (* V_18)( struct V_1 * , T_1 * , const T_1 * ) )
{
int V_10 ;
unsigned int V_24 ;
const int V_25 = V_26 ;
struct V_13 V_14 = {
. V_19 = F_14 ( V_6 -> V_8 ) ,
. V_18 = V_18
} ;
T_1 * V_27 ;
T_1 * V_28 ;
V_10 = F_15 ( V_21 , V_23 ) ;
if ( ! V_23 -> V_29 )
return V_10 ;
V_14 . V_17 = ( V_30 * ) V_23 -> V_31 ;
V_24 = V_23 -> V_29 ;
V_27 = V_23 -> V_16 . V_32 . V_33 ;
V_28 = V_23 -> V_15 . V_32 . V_33 ;
F_13 ( F_14 ( V_6 -> V_9 ) , V_23 -> V_31 , V_23 -> V_31 ) ;
goto V_34;
for (; ; ) {
do {
F_16 ( V_14 . V_17 , V_14 . V_17 ) ;
V_34:
F_10 ( & V_14 , V_28 , V_27 ) ;
V_27 += V_25 ;
V_28 += V_25 ;
} while ( ( V_24 -= V_25 ) >= V_25 );
V_10 = F_17 ( V_21 , V_23 , V_24 ) ;
if ( ! V_23 -> V_29 )
break;
V_24 = V_23 -> V_29 ;
V_27 = V_23 -> V_16 . V_32 . V_33 ;
V_28 = V_23 -> V_15 . V_32 . V_33 ;
}
return V_10 ;
}
static int F_18 ( struct V_20 * V_35 , struct V_36 * V_15 ,
struct V_36 * V_16 , unsigned int V_29 )
{
struct V_5 * V_6 = F_19 ( V_35 -> V_19 ) ;
struct V_22 V_23 ;
F_20 ( & V_23 , V_15 , V_16 , V_29 ) ;
return F_12 ( V_35 , & V_23 , V_6 , F_21 ( V_6 -> V_9 ) -> V_37 ,
F_21 ( V_6 -> V_8 ) -> V_37 ) ;
}
static int F_22 ( struct V_20 * V_35 , struct V_36 * V_15 ,
struct V_36 * V_16 , unsigned int V_29 )
{
struct V_5 * V_6 = F_19 ( V_35 -> V_19 ) ;
struct V_22 V_23 ;
F_20 ( & V_23 , V_15 , V_16 , V_29 ) ;
return F_12 ( V_35 , & V_23 , V_6 , F_21 ( V_6 -> V_9 ) -> V_37 ,
F_21 ( V_6 -> V_8 ) -> V_38 ) ;
}
int F_23 ( struct V_20 * V_35 , struct V_36 * V_39 ,
struct V_36 * V_40 , unsigned int V_29 ,
struct V_41 * V_42 )
{
const unsigned int V_43 = V_26 ;
const unsigned int V_44 = V_42 -> V_45 / V_43 ;
struct V_22 V_46 ;
unsigned int V_47 ;
V_30 * V_16 , * V_15 , * V_17 ;
V_30 * V_48 = V_42 -> V_49 ;
int V_10 , V_50 ;
F_24 ( V_44 < 1 ) ;
F_20 ( & V_46 , V_39 , V_40 , V_29 ) ;
V_10 = F_15 ( V_35 , & V_46 ) ;
V_29 = V_46 . V_29 ;
if ( ! V_29 )
return V_10 ;
V_47 = F_25 ( V_29 / V_43 , V_44 ) ;
V_16 = ( V_30 * ) V_46 . V_16 . V_32 . V_33 ;
V_15 = ( V_30 * ) V_46 . V_15 . V_32 . V_33 ;
V_42 -> V_51 ( V_42 -> V_52 , ( T_1 * ) & V_48 [ 0 ] , V_46 . V_31 ) ;
V_50 = 0 ;
goto V_34;
for (; ; ) {
do {
for ( V_50 = 0 ; V_50 < V_47 ; V_50 ++ ) {
F_16 ( & V_48 [ V_50 ] , V_17 ) ;
V_34:
V_17 = & V_48 [ V_50 ] ;
F_11 ( V_15 + V_50 , V_17 , V_16 + V_50 ) ;
}
V_42 -> V_53 ( V_42 -> V_54 , ( T_1 * ) V_15 ,
V_47 * V_43 ) ;
for ( V_50 = 0 ; V_50 < V_47 ; V_50 ++ )
F_11 ( V_15 + V_50 , V_15 + V_50 , & V_48 [ V_50 ] ) ;
V_16 += V_47 ;
V_15 += V_47 ;
V_29 -= V_47 * V_43 ;
V_47 = F_25 ( V_29 / V_43 , V_44 ) ;
} while ( V_47 > 0 );
* ( V_30 * ) V_46 . V_31 = * V_17 ;
V_10 = F_17 ( V_35 , & V_46 , V_29 ) ;
V_29 = V_46 . V_29 ;
if ( ! V_29 )
break;
V_47 = F_25 ( V_29 / V_43 , V_44 ) ;
V_16 = ( V_30 * ) V_46 . V_16 . V_32 . V_33 ;
V_15 = ( V_30 * ) V_46 . V_15 . V_32 . V_33 ;
}
return V_10 ;
}
static int F_26 ( struct V_1 * V_19 )
{
struct V_7 * V_55 ;
struct V_56 * V_57 = ( void * ) V_19 -> V_58 ;
struct V_59 * V_60 = F_27 ( V_57 ) ;
struct V_5 * V_6 = F_2 ( V_19 ) ;
T_2 * V_61 = & V_19 -> V_62 ;
V_55 = F_28 ( V_60 ) ;
if ( F_29 ( V_55 ) )
return F_30 ( V_55 ) ;
if ( F_31 ( V_55 ) != V_26 ) {
* V_61 |= V_63 ;
F_32 ( V_55 ) ;
return - V_64 ;
}
V_6 -> V_8 = V_55 ;
V_55 = F_28 ( V_60 ) ;
if ( F_29 ( V_55 ) ) {
F_32 ( V_6 -> V_8 ) ;
return F_30 ( V_55 ) ;
}
if ( F_31 ( V_55 ) != V_26 ) {
F_32 ( V_55 ) ;
F_32 ( V_6 -> V_8 ) ;
* V_61 |= V_63 ;
return - V_64 ;
}
V_6 -> V_9 = V_55 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_19 ) ;
F_32 ( V_6 -> V_8 ) ;
F_32 ( V_6 -> V_9 ) ;
}
static struct V_56 * F_34 ( struct V_65 * * V_66 )
{
struct V_56 * V_57 ;
struct V_67 * V_68 ;
int V_10 ;
V_10 = F_35 ( V_66 , V_69 ) ;
if ( V_10 )
return F_36 ( V_10 ) ;
V_68 = F_37 ( V_66 , V_70 ,
V_71 ) ;
if ( F_29 ( V_68 ) )
return F_38 ( V_68 ) ;
V_57 = F_39 ( L_1 , V_68 ) ;
if ( F_29 ( V_57 ) )
goto V_72;
V_57 -> V_68 . V_73 = V_69 ;
V_57 -> V_68 . V_74 = V_68 -> V_74 ;
V_57 -> V_68 . V_75 = V_68 -> V_75 ;
if ( V_68 -> V_76 < 7 )
V_57 -> V_68 . V_76 = 7 ;
else
V_57 -> V_68 . V_76 = V_68 -> V_76 ;
V_57 -> V_68 . V_77 = & V_78 ;
V_57 -> V_68 . V_79 . V_80 = V_68 -> V_75 ;
V_57 -> V_68 . V_79 . V_81 =
2 * V_68 -> V_82 . V_83 ;
V_57 -> V_68 . V_79 . V_84 =
2 * V_68 -> V_82 . V_85 ;
V_57 -> V_68 . V_86 = sizeof( struct V_5 ) ;
V_57 -> V_68 . V_87 = F_26 ;
V_57 -> V_68 . V_88 = F_33 ;
V_57 -> V_68 . V_79 . F_1 = F_1 ;
V_57 -> V_68 . V_79 . F_18 = F_18 ;
V_57 -> V_68 . V_79 . F_22 = F_22 ;
V_72:
F_40 ( V_68 ) ;
return V_57 ;
}
static void free ( struct V_56 * V_57 )
{
F_41 ( F_27 ( V_57 ) ) ;
F_42 ( V_57 ) ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_89 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_89 ) ;
}
