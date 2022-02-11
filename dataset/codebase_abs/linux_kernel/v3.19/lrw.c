static inline void F_1 ( void * V_1 , int V_2 )
{
F_2 ( V_2 ^ ( 0x80 -
#ifdef F_3
V_3
#else
V_4
#endif
) , V_1 ) ;
}
int F_4 ( struct V_5 * V_6 , const T_1 * V_7 )
{
T_2 V_8 = { 0 } ;
int V_9 ;
if ( V_6 -> V_10 )
F_5 ( V_6 -> V_10 ) ;
V_6 -> V_10 = F_6 ( ( T_2 * ) V_7 ) ;
if ( ! V_6 -> V_10 )
return - V_11 ;
for ( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) {
F_1 ( & V_8 , V_9 ) ;
V_6 -> V_12 [ V_9 ] = V_8 ;
F_7 ( & V_6 -> V_12 [ V_9 ] , V_6 -> V_10 ) ;
}
return 0 ;
}
void F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 )
F_5 ( V_6 -> V_10 ) ;
}
static int F_9 ( struct V_13 * V_14 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_6 = F_10 ( V_14 ) ;
struct V_18 * V_19 = V_6 -> V_19 ;
int V_20 , V_21 = V_22 ;
const T_1 * V_7 = V_15 + V_16 - V_21 ;
F_11 ( V_19 , V_23 ) ;
F_12 ( V_19 , F_13 ( V_14 ) &
V_23 ) ;
V_20 = F_14 ( V_19 , V_15 , V_16 - V_21 ) ;
if ( V_20 )
return V_20 ;
F_15 ( V_14 , F_16 ( V_19 ) &
V_24 ) ;
return F_4 ( & V_6 -> V_10 , V_7 ) ;
}
static inline void F_17 ( T_2 * V_25 )
{
F_18 ( & V_25 -> V_1 , 1 ) ;
if ( ! V_25 -> V_1 )
F_18 ( & V_25 -> V_26 , 1 ) ;
}
static inline void F_19 ( struct V_27 * V_28 , void * V_29 , const void * V_30 )
{
F_20 ( V_29 , & V_28 -> V_31 , V_30 ) ;
V_28 -> V_32 ( V_28 -> V_33 , V_29 , V_29 ) ;
F_20 ( V_29 , V_29 , & V_28 -> V_31 ) ;
}
static inline int F_21 ( T_2 * V_34 )
{
int V_35 ;
T_3 * V_36 = ( T_3 * ) V_34 ;
for ( V_36 += 3 , V_35 = 0 ; V_35 < 128 ; V_36 -- , V_35 += 32 ) {
T_4 V_37 = F_22 ( V_36 ) ;
if ( ! ~ V_37 )
continue;
return V_35 + F_23 ( V_37 ) ;
}
return V_35 ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_17 * V_6 ,
void (* V_32)( struct V_13 * , T_1 * , const T_1 * ) )
{
int V_20 ;
unsigned int V_42 ;
const int V_43 = V_22 ;
struct V_27 V_28 = {
. V_33 = F_25 ( V_6 -> V_19 ) ,
. V_32 = V_32
} ;
T_2 * V_25 ;
T_1 * V_44 ;
T_1 * V_45 ;
V_20 = F_26 ( V_39 , V_41 ) ;
if ( ! ( V_42 = V_41 -> V_46 ) )
return V_20 ;
V_44 = V_41 -> V_30 . V_47 . V_48 ;
V_45 = V_41 -> V_29 . V_47 . V_48 ;
V_25 = ( T_2 * ) V_41 -> V_25 ;
V_28 . V_31 = * V_25 ;
F_7 ( & V_28 . V_31 , V_6 -> V_10 . V_10 ) ;
goto V_49;
for (; ; ) {
do {
F_20 ( & V_28 . V_31 , & V_28 . V_31 ,
& V_6 -> V_10 . V_12 [ F_21 ( V_25 ) ] ) ;
F_17 ( V_25 ) ;
V_49:
F_19 ( & V_28 , V_45 , V_44 ) ;
V_44 += V_43 ;
V_45 += V_43 ;
} while ( ( V_42 -= V_43 ) >= V_43 );
V_20 = F_27 ( V_39 , V_41 , V_42 ) ;
if ( ! ( V_42 = V_41 -> V_46 ) )
break;
V_44 = V_41 -> V_30 . V_47 . V_48 ;
V_45 = V_41 -> V_29 . V_47 . V_48 ;
}
return V_20 ;
}
static int F_28 ( struct V_38 * V_50 , struct V_51 * V_29 ,
struct V_51 * V_30 , unsigned int V_46 )
{
struct V_17 * V_6 = F_29 ( V_50 -> V_33 ) ;
struct V_40 V_41 ;
F_30 ( & V_41 , V_29 , V_30 , V_46 ) ;
return F_24 ( V_50 , & V_41 , V_6 ,
F_31 ( V_6 -> V_19 ) -> V_52 ) ;
}
static int F_32 ( struct V_38 * V_50 , struct V_51 * V_29 ,
struct V_51 * V_30 , unsigned int V_46 )
{
struct V_17 * V_6 = F_29 ( V_50 -> V_33 ) ;
struct V_40 V_41 ;
F_30 ( & V_41 , V_29 , V_30 , V_46 ) ;
return F_24 ( V_50 , & V_41 , V_6 ,
F_31 ( V_6 -> V_19 ) -> V_53 ) ;
}
int F_33 ( struct V_38 * V_50 , struct V_51 * V_54 ,
struct V_51 * V_55 , unsigned int V_46 ,
struct V_56 * V_57 )
{
const unsigned int V_21 = V_22 ;
const unsigned int V_58 = V_57 -> V_59 / V_21 ;
struct V_5 * V_6 = V_57 -> V_60 ;
struct V_40 V_61 ;
unsigned int V_62 ;
T_2 * V_25 , * V_30 , * V_29 , * V_31 ;
T_2 * V_63 = V_57 -> V_64 ;
int V_20 , V_9 ;
F_34 ( V_58 < 1 ) ;
F_30 ( & V_61 , V_54 , V_55 , V_46 ) ;
V_20 = F_26 ( V_50 , & V_61 ) ;
V_46 = V_61 . V_46 ;
if ( ! V_46 )
return V_20 ;
V_62 = F_35 ( V_61 . V_46 / V_21 , V_58 ) ;
V_30 = ( T_2 * ) V_61 . V_30 . V_47 . V_48 ;
V_29 = ( T_2 * ) V_61 . V_29 . V_47 . V_48 ;
V_25 = ( T_2 * ) V_61 . V_25 ;
V_63 [ 0 ] = * V_25 ;
F_7 ( & V_63 [ 0 ] , V_6 -> V_10 ) ;
V_9 = 0 ;
goto V_49;
for (; ; ) {
do {
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
F_20 ( & V_63 [ V_9 ] , V_31 ,
& V_6 -> V_12 [ F_21 ( V_25 ) ] ) ;
F_17 ( V_25 ) ;
V_49:
V_31 = & V_63 [ V_9 ] ;
F_20 ( V_29 + V_9 , V_31 , V_30 + V_9 ) ;
}
V_57 -> V_65 ( V_57 -> V_66 , ( T_1 * ) V_29 ,
V_62 * V_21 ) ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ )
F_20 ( V_29 + V_9 , V_29 + V_9 , & V_63 [ V_9 ] ) ;
V_30 += V_62 ;
V_29 += V_62 ;
V_46 -= V_62 * V_21 ;
V_62 = F_35 ( V_46 / V_21 , V_58 ) ;
} while ( V_62 > 0 );
V_20 = F_27 ( V_50 , & V_61 , V_46 ) ;
V_46 = V_61 . V_46 ;
if ( ! V_46 )
break;
V_62 = F_35 ( V_46 / V_21 , V_58 ) ;
V_30 = ( T_2 * ) V_61 . V_30 . V_47 . V_48 ;
V_29 = ( T_2 * ) V_61 . V_29 . V_47 . V_48 ;
}
return V_20 ;
}
static int F_36 ( struct V_13 * V_33 )
{
struct V_18 * V_67 ;
struct V_68 * V_69 = ( void * ) V_33 -> V_70 ;
struct V_71 * V_72 = F_37 ( V_69 ) ;
struct V_17 * V_6 = F_10 ( V_33 ) ;
T_4 * V_73 = & V_33 -> V_74 ;
V_67 = F_38 ( V_72 ) ;
if ( F_39 ( V_67 ) )
return F_40 ( V_67 ) ;
if ( F_41 ( V_67 ) != V_22 ) {
* V_73 |= V_75 ;
F_42 ( V_67 ) ;
return - V_76 ;
}
V_6 -> V_19 = V_67 ;
return 0 ;
}
static void F_43 ( struct V_13 * V_33 )
{
struct V_17 * V_6 = F_10 ( V_33 ) ;
F_8 ( & V_6 -> V_10 ) ;
F_42 ( V_6 -> V_19 ) ;
}
static struct V_68 * F_44 ( struct V_77 * * V_78 )
{
struct V_68 * V_69 ;
struct V_79 * V_80 ;
int V_20 ;
V_20 = F_45 ( V_78 , V_81 ) ;
if ( V_20 )
return F_46 ( V_20 ) ;
V_80 = F_47 ( V_78 , V_82 ,
V_83 ) ;
if ( F_39 ( V_80 ) )
return F_48 ( V_80 ) ;
V_69 = F_49 ( L_1 , V_80 ) ;
if ( F_39 ( V_69 ) )
goto V_84;
V_69 -> V_80 . V_85 = V_81 ;
V_69 -> V_80 . V_86 = V_80 -> V_86 ;
V_69 -> V_80 . V_87 = V_80 -> V_87 ;
if ( V_80 -> V_88 < 7 ) V_69 -> V_80 . V_88 = 7 ;
else V_69 -> V_80 . V_88 = V_80 -> V_88 ;
V_69 -> V_80 . V_89 = & V_90 ;
if ( ! ( V_80 -> V_87 % 4 ) )
V_69 -> V_80 . V_88 |= 3 ;
V_69 -> V_80 . V_91 . V_92 = V_80 -> V_87 ;
V_69 -> V_80 . V_91 . V_93 =
V_80 -> V_94 . V_95 + V_80 -> V_87 ;
V_69 -> V_80 . V_91 . V_96 =
V_80 -> V_94 . V_97 + V_80 -> V_87 ;
V_69 -> V_80 . V_98 = sizeof( struct V_17 ) ;
V_69 -> V_80 . V_99 = F_36 ;
V_69 -> V_80 . V_100 = F_43 ;
V_69 -> V_80 . V_91 . F_9 = F_9 ;
V_69 -> V_80 . V_91 . F_28 = F_28 ;
V_69 -> V_80 . V_91 . F_32 = F_32 ;
V_84:
F_50 ( V_80 ) ;
return V_69 ;
}
static void free ( struct V_68 * V_69 )
{
F_51 ( F_37 ( V_69 ) ) ;
F_52 ( V_69 ) ;
}
static int T_5 F_53 ( void )
{
return F_54 ( & V_101 ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_101 ) ;
}
