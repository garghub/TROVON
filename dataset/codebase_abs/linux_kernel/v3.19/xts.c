static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_2 * V_10 = & V_2 -> V_11 ;
int V_12 ;
if ( V_4 % 2 ) {
* V_10 |= V_13 ;
return - V_14 ;
}
F_3 ( V_8 , V_15 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_15 ) ;
V_12 = F_6 ( V_8 , V_3 + V_4 / 2 , V_4 / 2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_16 ) ;
V_8 = V_6 -> V_8 ;
F_3 ( V_8 , V_15 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_15 ) ;
V_12 = F_6 ( V_8 , V_3 , V_4 / 2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_16 ) ;
return 0 ;
}
static inline void F_9 ( struct V_17 * V_18 , void * V_19 , const void * V_20 )
{
F_10 ( V_19 , V_18 -> V_21 , V_20 ) ;
V_18 -> V_22 ( V_18 -> V_23 , V_19 , V_19 ) ;
F_10 ( V_19 , V_19 , V_18 -> V_21 ) ;
}
static int F_11 ( struct V_24 * V_25 ,
struct V_26 * V_27 , struct V_5 * V_6 ,
void (* F_12)( struct V_1 * , T_1 * , const T_1 * ) ,
void (* V_22)( struct V_1 * , T_1 * , const T_1 * ) )
{
int V_12 ;
unsigned int V_28 ;
const int V_29 = V_30 ;
struct V_17 V_18 = {
. V_23 = F_13 ( V_6 -> V_8 ) ,
. V_22 = V_22
} ;
T_1 * V_31 ;
T_1 * V_32 ;
V_12 = F_14 ( V_25 , V_27 ) ;
if ( ! V_27 -> V_33 )
return V_12 ;
V_18 . V_21 = ( V_34 * ) V_27 -> V_35 ;
V_28 = V_27 -> V_33 ;
V_31 = V_27 -> V_20 . V_36 . V_37 ;
V_32 = V_27 -> V_19 . V_36 . V_37 ;
F_12 ( F_13 ( V_6 -> V_9 ) , V_27 -> V_35 , V_27 -> V_35 ) ;
goto V_38;
for (; ; ) {
do {
F_15 ( V_18 . V_21 , V_18 . V_21 ) ;
V_38:
F_9 ( & V_18 , V_32 , V_31 ) ;
V_31 += V_29 ;
V_32 += V_29 ;
} while ( ( V_28 -= V_29 ) >= V_29 );
V_12 = F_16 ( V_25 , V_27 , V_28 ) ;
if ( ! V_27 -> V_33 )
break;
V_28 = V_27 -> V_33 ;
V_31 = V_27 -> V_20 . V_36 . V_37 ;
V_32 = V_27 -> V_19 . V_36 . V_37 ;
}
return V_12 ;
}
static int F_17 ( struct V_24 * V_39 , struct V_40 * V_19 ,
struct V_40 * V_20 , unsigned int V_33 )
{
struct V_5 * V_6 = F_18 ( V_39 -> V_23 ) ;
struct V_26 V_27 ;
F_19 ( & V_27 , V_19 , V_20 , V_33 ) ;
return F_11 ( V_39 , & V_27 , V_6 , F_20 ( V_6 -> V_9 ) -> V_41 ,
F_20 ( V_6 -> V_8 ) -> V_41 ) ;
}
static int F_21 ( struct V_24 * V_39 , struct V_40 * V_19 ,
struct V_40 * V_20 , unsigned int V_33 )
{
struct V_5 * V_6 = F_18 ( V_39 -> V_23 ) ;
struct V_26 V_27 ;
F_19 ( & V_27 , V_19 , V_20 , V_33 ) ;
return F_11 ( V_39 , & V_27 , V_6 , F_20 ( V_6 -> V_9 ) -> V_41 ,
F_20 ( V_6 -> V_8 ) -> V_42 ) ;
}
int F_22 ( struct V_24 * V_39 , struct V_40 * V_43 ,
struct V_40 * V_44 , unsigned int V_33 ,
struct V_45 * V_46 )
{
const unsigned int V_47 = V_30 ;
const unsigned int V_48 = V_46 -> V_49 / V_47 ;
struct V_26 V_50 ;
unsigned int V_51 ;
V_34 * V_20 , * V_19 , * V_21 ;
V_34 * V_52 = V_46 -> V_53 ;
int V_12 , V_54 ;
F_23 ( V_48 < 1 ) ;
F_19 ( & V_50 , V_43 , V_44 , V_33 ) ;
V_12 = F_14 ( V_39 , & V_50 ) ;
V_33 = V_50 . V_33 ;
if ( ! V_33 )
return V_12 ;
V_51 = F_24 ( V_33 / V_47 , V_48 ) ;
V_20 = ( V_34 * ) V_50 . V_20 . V_36 . V_37 ;
V_19 = ( V_34 * ) V_50 . V_19 . V_36 . V_37 ;
V_46 -> V_55 ( V_46 -> V_56 , ( T_1 * ) & V_52 [ 0 ] , V_50 . V_35 ) ;
V_54 = 0 ;
goto V_38;
for (; ; ) {
do {
for ( V_54 = 0 ; V_54 < V_51 ; V_54 ++ ) {
F_15 ( & V_52 [ V_54 ] , V_21 ) ;
V_38:
V_21 = & V_52 [ V_54 ] ;
F_10 ( V_19 + V_54 , V_21 , V_20 + V_54 ) ;
}
V_46 -> V_57 ( V_46 -> V_58 , ( T_1 * ) V_19 ,
V_51 * V_47 ) ;
for ( V_54 = 0 ; V_54 < V_51 ; V_54 ++ )
F_10 ( V_19 + V_54 , V_19 + V_54 , & V_52 [ V_54 ] ) ;
V_20 += V_51 ;
V_19 += V_51 ;
V_33 -= V_51 * V_47 ;
V_51 = F_24 ( V_33 / V_47 , V_48 ) ;
} while ( V_51 > 0 );
* ( V_34 * ) V_50 . V_35 = * V_21 ;
V_12 = F_16 ( V_39 , & V_50 , V_33 ) ;
V_33 = V_50 . V_33 ;
if ( ! V_33 )
break;
V_51 = F_24 ( V_33 / V_47 , V_48 ) ;
V_20 = ( V_34 * ) V_50 . V_20 . V_36 . V_37 ;
V_19 = ( V_34 * ) V_50 . V_19 . V_36 . V_37 ;
}
return V_12 ;
}
static int F_25 ( struct V_1 * V_23 )
{
struct V_7 * V_59 ;
struct V_60 * V_61 = ( void * ) V_23 -> V_62 ;
struct V_63 * V_64 = F_26 ( V_61 ) ;
struct V_5 * V_6 = F_2 ( V_23 ) ;
T_2 * V_10 = & V_23 -> V_11 ;
V_59 = F_27 ( V_64 ) ;
if ( F_28 ( V_59 ) )
return F_29 ( V_59 ) ;
if ( F_30 ( V_59 ) != V_30 ) {
* V_10 |= V_65 ;
F_31 ( V_59 ) ;
return - V_14 ;
}
V_6 -> V_8 = V_59 ;
V_59 = F_27 ( V_64 ) ;
if ( F_28 ( V_59 ) ) {
F_31 ( V_6 -> V_8 ) ;
return F_29 ( V_59 ) ;
}
if ( F_30 ( V_59 ) != V_30 ) {
F_31 ( V_59 ) ;
F_31 ( V_6 -> V_8 ) ;
* V_10 |= V_65 ;
return - V_14 ;
}
V_6 -> V_9 = V_59 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_23 )
{
struct V_5 * V_6 = F_2 ( V_23 ) ;
F_31 ( V_6 -> V_8 ) ;
F_31 ( V_6 -> V_9 ) ;
}
static struct V_60 * F_33 ( struct V_66 * * V_67 )
{
struct V_60 * V_61 ;
struct V_68 * V_69 ;
int V_12 ;
V_12 = F_34 ( V_67 , V_70 ) ;
if ( V_12 )
return F_35 ( V_12 ) ;
V_69 = F_36 ( V_67 , V_71 ,
V_72 ) ;
if ( F_28 ( V_69 ) )
return F_37 ( V_69 ) ;
V_61 = F_38 ( L_1 , V_69 ) ;
if ( F_28 ( V_61 ) )
goto V_73;
V_61 -> V_69 . V_74 = V_70 ;
V_61 -> V_69 . V_75 = V_69 -> V_75 ;
V_61 -> V_69 . V_76 = V_69 -> V_76 ;
if ( V_69 -> V_77 < 7 )
V_61 -> V_69 . V_77 = 7 ;
else
V_61 -> V_69 . V_77 = V_69 -> V_77 ;
V_61 -> V_69 . V_78 = & V_79 ;
V_61 -> V_69 . V_80 . V_81 = V_69 -> V_76 ;
V_61 -> V_69 . V_80 . V_82 =
2 * V_69 -> V_83 . V_84 ;
V_61 -> V_69 . V_80 . V_85 =
2 * V_69 -> V_83 . V_86 ;
V_61 -> V_69 . V_87 = sizeof( struct V_5 ) ;
V_61 -> V_69 . V_88 = F_25 ;
V_61 -> V_69 . V_89 = F_32 ;
V_61 -> V_69 . V_80 . F_1 = F_1 ;
V_61 -> V_69 . V_80 . F_17 = F_17 ;
V_61 -> V_69 . V_80 . F_21 = F_21 ;
V_73:
F_39 ( V_69 ) ;
return V_61 ;
}
static void free ( struct V_60 * V_61 )
{
F_40 ( F_26 ( V_61 ) ) ;
F_41 ( V_61 ) ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_90 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_90 ) ;
}
