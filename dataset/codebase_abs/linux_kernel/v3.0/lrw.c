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
static int F_4 ( struct V_5 * V_6 , const T_1 * V_7 ,
unsigned int V_8 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_13 , V_14 ;
T_2 V_15 = { 0 } ;
int V_16 = F_6 ( V_12 ) ;
F_7 ( V_12 , V_17 ) ;
F_8 ( V_12 , F_9 ( V_6 ) &
V_17 ) ;
if ( ( V_13 = F_10 ( V_12 , V_7 , V_8 - V_16 ) ) )
return V_13 ;
F_11 ( V_6 , F_12 ( V_12 ) &
V_18 ) ;
if ( V_10 -> V_19 )
F_13 ( V_10 -> V_19 ) ;
V_10 -> V_19 = F_14 ( ( T_2 * ) ( V_7 + V_8 - V_16 ) ) ;
if ( ! V_10 -> V_19 )
return - V_20 ;
for ( V_14 = 0 ; V_14 < 128 ; V_14 ++ ) {
F_1 ( & V_15 , V_14 ) ;
V_10 -> V_21 [ V_14 ] = V_15 ;
F_15 ( & V_10 -> V_21 [ V_14 ] , V_10 -> V_19 ) ;
}
return 0 ;
}
static inline void F_16 ( T_2 * V_22 )
{
F_17 ( & V_22 -> V_1 , 1 ) ;
if ( ! V_22 -> V_1 )
F_17 ( & V_22 -> V_23 , 1 ) ;
}
static inline void F_18 ( struct V_24 * V_25 , void * V_26 , const void * V_27 )
{
F_19 ( V_26 , & V_25 -> V_28 , V_27 ) ;
V_25 -> V_29 ( V_25 -> V_30 , V_26 , V_26 ) ;
F_19 ( V_26 , V_26 , & V_25 -> V_28 ) ;
}
static inline int F_20 ( T_2 * V_31 )
{
int V_32 ;
T_3 * V_33 = ( T_3 * ) V_31 ;
for ( V_33 += 3 , V_32 = 0 ; V_32 < 128 ; V_33 -- , V_32 += 32 ) {
T_4 V_34 = F_21 ( V_33 ) ;
if ( ! ~ V_34 )
continue;
return V_32 + F_22 ( V_34 ) ;
}
return V_32 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_37 * V_38 , struct V_9 * V_10 ,
void (* V_29)( struct V_5 * , T_1 * , const T_1 * ) )
{
int V_13 ;
unsigned int V_39 ;
const int V_40 = F_6 ( V_10 -> V_12 ) ;
struct V_24 V_25 = {
. V_30 = F_24 ( V_10 -> V_12 ) ,
. V_29 = V_29
} ;
T_2 * V_22 ;
T_1 * V_41 ;
T_1 * V_42 ;
V_13 = F_25 ( V_36 , V_38 ) ;
if ( ! ( V_39 = V_38 -> V_43 ) )
return V_13 ;
V_41 = V_38 -> V_27 . V_44 . V_45 ;
V_42 = V_38 -> V_26 . V_44 . V_45 ;
V_22 = ( T_2 * ) V_38 -> V_22 ;
V_25 . V_28 = * V_22 ;
F_15 ( & V_25 . V_28 , V_10 -> V_19 ) ;
goto V_46;
for (; ; ) {
do {
F_19 ( & V_25 . V_28 , & V_25 . V_28 , & V_10 -> V_21 [ F_20 ( V_22 ) ] ) ;
F_16 ( V_22 ) ;
V_46:
F_18 ( & V_25 , V_42 , V_41 ) ;
V_41 += V_40 ;
V_42 += V_40 ;
} while ( ( V_39 -= V_40 ) >= V_40 );
V_13 = F_26 ( V_36 , V_38 , V_39 ) ;
if ( ! ( V_39 = V_38 -> V_43 ) )
break;
V_41 = V_38 -> V_27 . V_44 . V_45 ;
V_42 = V_38 -> V_26 . V_44 . V_45 ;
}
return V_13 ;
}
static int F_27 ( struct V_35 * V_47 , struct V_48 * V_26 ,
struct V_48 * V_27 , unsigned int V_43 )
{
struct V_9 * V_10 = F_28 ( V_47 -> V_30 ) ;
struct V_37 V_38 ;
F_29 ( & V_38 , V_26 , V_27 , V_43 ) ;
return F_23 ( V_47 , & V_38 , V_10 ,
F_30 ( V_10 -> V_12 ) -> V_49 ) ;
}
static int F_31 ( struct V_35 * V_47 , struct V_48 * V_26 ,
struct V_48 * V_27 , unsigned int V_43 )
{
struct V_9 * V_10 = F_28 ( V_47 -> V_30 ) ;
struct V_37 V_38 ;
F_29 ( & V_38 , V_26 , V_27 , V_43 ) ;
return F_23 ( V_47 , & V_38 , V_10 ,
F_30 ( V_10 -> V_12 ) -> V_50 ) ;
}
static int F_32 ( struct V_5 * V_30 )
{
struct V_11 * V_51 ;
struct V_52 * V_53 = ( void * ) V_30 -> V_54 ;
struct V_55 * V_56 = F_33 ( V_53 ) ;
struct V_9 * V_10 = F_5 ( V_30 ) ;
T_4 * V_57 = & V_30 -> V_58 ;
V_51 = F_34 ( V_56 ) ;
if ( F_35 ( V_51 ) )
return F_36 ( V_51 ) ;
if ( F_6 ( V_51 ) != 16 ) {
* V_57 |= V_59 ;
return - V_60 ;
}
V_10 -> V_12 = V_51 ;
return 0 ;
}
static void F_37 ( struct V_5 * V_30 )
{
struct V_9 * V_10 = F_5 ( V_30 ) ;
if ( V_10 -> V_19 )
F_13 ( V_10 -> V_19 ) ;
F_38 ( V_10 -> V_12 ) ;
}
static struct V_52 * F_39 ( struct V_61 * * V_62 )
{
struct V_52 * V_53 ;
struct V_63 * V_64 ;
int V_13 ;
V_13 = F_40 ( V_62 , V_65 ) ;
if ( V_13 )
return F_41 ( V_13 ) ;
V_64 = F_42 ( V_62 , V_66 ,
V_67 ) ;
if ( F_35 ( V_64 ) )
return F_43 ( V_64 ) ;
V_53 = F_44 ( L_1 , V_64 ) ;
if ( F_35 ( V_53 ) )
goto V_68;
V_53 -> V_64 . V_69 = V_65 ;
V_53 -> V_64 . V_70 = V_64 -> V_70 ;
V_53 -> V_64 . V_71 = V_64 -> V_71 ;
if ( V_64 -> V_72 < 7 ) V_53 -> V_64 . V_72 = 7 ;
else V_53 -> V_64 . V_72 = V_64 -> V_72 ;
V_53 -> V_64 . V_73 = & V_74 ;
if ( ! ( V_64 -> V_71 % 4 ) )
V_53 -> V_64 . V_72 |= 3 ;
V_53 -> V_64 . V_75 . V_76 = V_64 -> V_71 ;
V_53 -> V_64 . V_75 . V_77 =
V_64 -> V_78 . V_79 + V_64 -> V_71 ;
V_53 -> V_64 . V_75 . V_80 =
V_64 -> V_78 . V_81 + V_64 -> V_71 ;
V_53 -> V_64 . V_82 = sizeof( struct V_9 ) ;
V_53 -> V_64 . V_83 = F_32 ;
V_53 -> V_64 . V_84 = F_37 ;
V_53 -> V_64 . V_75 . F_4 = F_4 ;
V_53 -> V_64 . V_75 . F_27 = F_27 ;
V_53 -> V_64 . V_75 . F_31 = F_31 ;
V_68:
F_45 ( V_64 ) ;
return V_53 ;
}
static void free ( struct V_52 * V_53 )
{
F_46 ( F_33 ( V_53 ) ) ;
F_47 ( V_53 ) ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_85 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_85 ) ;
}
