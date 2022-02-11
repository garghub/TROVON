static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) ;
}
static inline unsigned long
F_3 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static unsigned long
F_4 ( const struct V_2 * V_3 , T_1 V_5 )
{
T_1 V_6 = V_5 + F_2 ( V_3 ) -> V_7 ;
F_5 ( V_6 , F_3 ( V_3 ) ) ;
return ( unsigned long ) V_6 ;
}
static unsigned long
F_6 ( const struct V_2 * V_3 , T_1 V_5 )
{
T_1 V_6 = V_5 + F_2 ( V_3 ) -> V_7 ;
return F_5 ( V_6 , F_3 ( V_3 ) ) ;
}
static unsigned long
F_7 ( const struct V_2 * V_3 , T_1 V_8 ,
T_1 V_9 )
{
return F_8 (unsigned long,
nilfs_sufile_segment_usages_per_block(sufile) -
nilfs_sufile_get_offset(sufile, curr),
max - curr + 1 ) ;
}
static struct V_10 *
F_9 ( const struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_12 , void * V_13 )
{
return V_13 + F_10 ( V_12 ) +
F_6 ( V_3 , V_5 ) *
F_2 ( V_3 ) -> V_14 ;
}
static inline int F_11 ( struct V_2 * V_3 ,
struct V_11 * * V_15 )
{
return F_12 ( V_3 , 0 , 0 , NULL , V_15 ) ;
}
static inline int
F_13 ( struct V_2 * V_3 , T_1 V_5 ,
int V_16 , struct V_11 * * V_15 )
{
return F_12 ( V_3 ,
F_4 ( V_3 , V_5 ) ,
V_16 , NULL , V_15 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
T_1 V_5 )
{
return F_15 ( V_3 ,
F_4 ( V_3 , V_5 ) ) ;
}
static void F_16 ( struct V_11 * V_17 ,
T_2 V_18 , T_2 V_19 )
{
struct V_20 * V_21 ;
void * V_13 ;
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
F_18 ( & V_21 -> V_24 , V_18 ) ;
F_18 ( & V_21 -> V_25 , V_19 ) ;
F_19 ( V_13 , V_23 ) ;
F_20 ( V_17 ) ;
}
unsigned long F_21 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_26 ;
}
int F_22 ( struct V_2 * V_3 , T_1 * V_27 , T_3 V_28 ,
int V_16 , T_3 * V_29 ,
void (* F_23)( struct V_2 * , T_1 ,
struct V_11 * ,
struct V_11 * ) )
{
struct V_11 * V_17 , * V_12 ;
unsigned long V_30 , V_31 ;
T_1 * V_32 ;
T_3 V_33 = 0 , V_34 = 0 ;
int V_35 = 0 ;
if ( F_24 ( V_28 == 0 ) )
goto V_36;
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
for ( V_32 = V_27 ; V_32 < V_27 + V_28 ; V_32 ++ ) {
if ( F_24 ( * V_32 >= F_26 ( V_3 ) ) ) {
F_27 ( V_38
L_1 , V_39 ,
( unsigned long long ) * V_32 ) ;
V_33 ++ ;
}
}
if ( V_33 > 0 ) {
V_35 = - V_40 ;
goto V_41;
}
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_41;
V_32 = V_27 ;
V_30 = F_4 ( V_3 , * V_32 ) ;
V_35 = F_12 ( V_3 , V_30 , V_16 , NULL , & V_12 ) ;
if ( V_35 < 0 )
goto V_42;
for (; ; ) {
F_23 ( V_3 , * V_32 , V_17 , V_12 ) ;
if ( ++ V_32 >= V_27 + V_28 )
break;
V_31 = V_30 ;
V_30 = F_4 ( V_3 , * V_32 ) ;
if ( V_30 == V_31 )
continue;
F_28 ( V_12 ) ;
V_35 = F_12 ( V_3 , V_30 , V_16 , NULL , & V_12 ) ;
if ( F_24 ( V_35 < 0 ) )
goto V_42;
}
F_28 ( V_12 ) ;
V_42:
V_34 = V_32 - V_27 ;
F_28 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
V_36:
if ( V_29 )
* V_29 = V_34 ;
return V_35 ;
}
int F_30 ( struct V_2 * V_3 , T_1 V_5 , int V_16 ,
void (* F_23)( struct V_2 * , T_1 ,
struct V_11 * ,
struct V_11 * ) )
{
struct V_11 * V_17 , * V_12 ;
int V_35 ;
if ( F_24 ( V_5 >= F_26 ( V_3 ) ) ) {
F_27 ( V_38 L_1 ,
V_39 , ( unsigned long long ) V_5 ) ;
return - V_40 ;
}
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_41;
V_35 = F_13 ( V_3 , V_5 , V_16 , & V_12 ) ;
if ( ! V_35 ) {
F_23 ( V_3 , V_5 , V_17 , V_12 ) ;
F_28 ( V_12 ) ;
}
F_28 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
int F_31 ( struct V_2 * V_3 , T_1 V_43 , T_1 V_44 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_28 ;
int V_35 = - V_46 ;
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
V_28 = F_26 ( V_3 ) ;
if ( V_43 <= V_44 && V_44 < V_28 ) {
V_45 -> V_47 = V_43 ;
V_45 -> V_48 = V_44 ;
V_35 = 0 ;
}
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
int F_32 ( struct V_2 * V_3 , T_1 * V_49 )
{
struct V_11 * V_17 , * V_50 ;
struct V_20 * V_21 ;
struct V_10 * V_51 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_3 V_52 = F_2 ( V_3 ) -> V_14 ;
T_1 V_5 , V_53 , V_54 ;
void * V_13 ;
unsigned long V_55 , V_26 , V_56 , V_57 ;
int V_35 , V_58 ;
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_41;
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_26 = F_33 ( V_21 -> V_24 ) ;
V_54 = F_33 ( V_21 -> V_59 ) ;
F_19 ( V_13 , V_23 ) ;
V_55 = F_26 ( V_3 ) ;
V_53 = V_45 -> V_48 ;
V_5 = V_54 + 1 ;
if ( V_5 < V_45 -> V_47 || V_5 > V_45 -> V_48 )
V_5 = V_45 -> V_47 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 += V_56 ) {
if ( V_5 > V_53 ) {
if ( V_57 < V_45 -> V_48 - V_45 -> V_47 + 1 ) {
V_5 = V_45 -> V_47 ;
V_53 = V_54 ;
} else if ( V_5 > V_45 -> V_47 &&
V_45 -> V_48 + 1 < V_55 ) {
V_5 = V_45 -> V_48 + 1 ;
V_53 = V_55 - 1 ;
} else if ( V_45 -> V_47 > 0 ) {
V_5 = 0 ;
V_53 = V_45 -> V_47 - 1 ;
} else {
break;
}
}
V_35 = F_13 ( V_3 , V_5 , 1 ,
& V_50 ) ;
if ( V_35 < 0 )
goto V_42;
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
V_56 = F_7 (
V_3 , V_5 , V_53 ) ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 , V_5 ++ ) {
if ( ! F_34 ( V_51 ) )
continue;
F_35 ( V_51 ) ;
F_19 ( V_13 , V_23 ) ;
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
F_18 ( & V_21 -> V_24 , - 1 ) ;
F_18 ( & V_21 -> V_25 , 1 ) ;
V_21 -> V_59 = F_36 ( V_5 ) ;
F_19 ( V_13 , V_23 ) ;
V_45 -> V_26 -- ;
F_20 ( V_17 ) ;
F_20 ( V_50 ) ;
F_37 ( V_3 ) ;
F_28 ( V_50 ) ;
* V_49 = V_5 ;
goto V_42;
}
F_19 ( V_13 , V_23 ) ;
F_28 ( V_50 ) ;
}
V_35 = - V_60 ;
V_42:
F_28 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
void F_38 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_24 ( ! F_34 ( V_51 ) ) ) {
F_27 ( V_38 L_2 ,
V_39 , ( unsigned long long ) V_5 ) ;
F_19 ( V_13 , V_23 ) ;
return;
}
F_35 ( V_51 ) ;
F_19 ( V_13 , V_23 ) ;
F_16 ( V_17 , - 1 , 1 ) ;
F_1 ( V_3 ) -> V_26 -- ;
F_20 ( V_50 ) ;
F_37 ( V_3 ) ;
}
void F_39 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_61 , V_62 ;
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( V_51 -> V_63 == F_40 ( 1UL << V_64 ) &&
V_51 -> V_65 == F_40 ( 0 ) ) {
F_19 ( V_13 , V_23 ) ;
return;
}
V_61 = F_34 ( V_51 ) ;
V_62 = F_41 ( V_51 ) ;
V_51 -> V_66 = F_36 ( 0 ) ;
V_51 -> V_65 = F_40 ( 0 ) ;
V_51 -> V_63 = F_40 ( 1UL << V_64 ) ;
F_19 ( V_13 , V_23 ) ;
F_16 ( V_17 , V_61 ? ( T_2 ) - 1 : 0 , V_62 ? 0 : 1 ) ;
F_1 ( V_3 ) -> V_26 -= V_61 ;
F_20 ( V_50 ) ;
F_37 ( V_3 ) ;
}
void F_42 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_67 ;
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_34 ( V_51 ) ) {
F_27 ( V_38 L_3 ,
V_39 , ( unsigned long long ) V_5 ) ;
F_19 ( V_13 , V_23 ) ;
return;
}
F_43 ( F_44 ( V_51 ) ) ;
F_43 ( ! F_41 ( V_51 ) ) ;
V_67 = F_41 ( V_51 ) ;
F_45 ( V_51 ) ;
F_19 ( V_13 , V_23 ) ;
F_20 ( V_50 ) ;
F_16 ( V_17 , 1 , V_67 ? ( T_2 ) - 1 : 0 ) ;
F_1 ( V_3 ) -> V_26 ++ ;
F_37 ( V_3 ) ;
}
int F_46 ( struct V_2 * V_3 , T_1 V_5 )
{
struct V_11 * V_12 ;
int V_35 ;
V_35 = F_13 ( V_3 , V_5 , 0 , & V_12 ) ;
if ( ! V_35 ) {
F_20 ( V_12 ) ;
F_37 ( V_3 ) ;
F_28 ( V_12 ) ;
}
return V_35 ;
}
int F_47 ( struct V_2 * V_3 , T_1 V_5 ,
unsigned long V_68 , T_4 V_69 )
{
struct V_11 * V_12 ;
struct V_10 * V_51 ;
void * V_13 ;
int V_35 ;
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
V_35 = F_13 ( V_3 , V_5 , 0 , & V_12 ) ;
if ( V_35 < 0 )
goto V_41;
V_13 = F_17 ( V_12 -> V_22 , V_23 ) ;
V_51 = F_9 ( V_3 , V_5 , V_12 , V_13 ) ;
F_43 ( F_44 ( V_51 ) ) ;
if ( V_69 )
V_51 -> V_66 = F_36 ( V_69 ) ;
V_51 -> V_65 = F_40 ( V_68 ) ;
F_19 ( V_13 , V_23 ) ;
F_20 ( V_12 ) ;
F_37 ( V_3 ) ;
F_28 ( V_12 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
int F_48 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_72 * V_73 = V_3 -> V_74 -> V_75 ;
void * V_13 ;
int V_35 ;
F_49 ( & F_2 ( V_3 ) -> V_37 ) ;
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_41;
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_71 -> V_76 = F_26 ( V_3 ) ;
V_71 -> V_77 = F_33 ( V_21 -> V_24 ) ;
V_71 -> V_78 = F_33 ( V_21 -> V_25 ) ;
V_71 -> V_79 = V_73 -> V_80 ;
V_71 -> V_81 = V_73 -> V_82 ;
F_50 ( & V_73 -> V_83 ) ;
V_71 -> V_84 = V_73 -> V_85 ;
F_51 ( & V_73 -> V_83 ) ;
F_19 ( V_13 , V_23 ) ;
F_28 ( V_17 ) ;
V_41:
F_52 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
void F_53 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_86 ;
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_44 ( V_51 ) ) {
F_19 ( V_13 , V_23 ) ;
return;
}
V_86 = F_34 ( V_51 ) ;
F_54 ( V_51 ) ;
F_19 ( V_13 , V_23 ) ;
if ( V_86 ) {
F_16 ( V_17 , - 1 , 0 ) ;
F_1 ( V_3 ) -> V_26 -- ;
}
F_20 ( V_50 ) ;
F_37 ( V_3 ) ;
}
static int F_55 ( struct V_2 * V_3 ,
T_1 V_43 , T_1 V_44 )
{
struct V_72 * V_73 = V_3 -> V_74 -> V_75 ;
struct V_11 * V_17 ;
struct V_11 * V_50 ;
struct V_10 * V_51 , * V_87 ;
T_3 V_52 = F_2 ( V_3 ) -> V_14 ;
unsigned long V_88 ;
unsigned long V_28 , V_89 ;
T_1 V_5 ;
void * V_13 ;
T_5 V_34 , V_90 ;
int V_35 ;
int V_58 ;
V_28 = F_26 ( V_3 ) ;
V_35 = - V_40 ;
if ( V_43 > V_44 || V_43 >= V_28 )
goto V_36;
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_36;
V_88 = F_3 ( V_3 ) ;
V_89 = 0 ;
for ( V_5 = V_43 ; V_5 <= V_44 ; V_5 += V_34 ) {
V_34 = F_8 (unsigned long,
segusages_per_block -
nilfs_sufile_get_offset(sufile, segnum),
end - segnum + 1 ) ;
V_35 = F_13 ( V_3 , V_5 , 0 ,
& V_50 ) ;
if ( V_35 < 0 ) {
if ( V_35 != - V_91 )
goto V_42;
continue;
}
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
V_87 = V_51 ;
for ( V_58 = 0 ; V_58 < V_34 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 ) {
if ( ( F_56 ( V_51 -> V_63 ) &
~ ( 1UL << V_92 ) ) ||
F_57 ( V_73 , V_5 + V_58 ) ) {
V_35 = - V_93 ;
F_19 ( V_13 , V_23 ) ;
F_28 ( V_50 ) ;
goto V_42;
}
}
V_90 = 0 ;
for ( V_51 = V_87 , V_58 = 0 ; V_58 < V_34 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 ) {
if ( F_44 ( V_51 ) ) {
F_45 ( V_51 ) ;
V_90 ++ ;
}
}
F_19 ( V_13 , V_23 ) ;
if ( V_90 > 0 ) {
F_20 ( V_50 ) ;
V_89 += V_90 ;
}
F_28 ( V_50 ) ;
if ( V_34 == V_88 ) {
F_14 ( V_3 , V_5 ) ;
}
}
V_35 = 0 ;
V_42:
if ( V_89 > 0 ) {
F_1 ( V_3 ) -> V_26 += V_89 ;
F_16 ( V_17 , V_89 , 0 ) ;
F_37 ( V_3 ) ;
}
F_28 ( V_17 ) ;
V_36:
return V_35 ;
}
int F_58 ( struct V_2 * V_3 , T_1 V_94 )
{
struct V_72 * V_73 = V_3 -> V_74 -> V_75 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
void * V_13 ;
unsigned long V_28 , V_95 ;
int V_35 = 0 ;
F_25 ( & F_2 ( V_3 ) -> V_37 ) ;
V_28 = F_26 ( V_3 ) ;
if ( V_28 == V_94 )
goto V_36;
V_35 = - V_60 ;
V_95 = F_59 ( V_73 , V_94 ) ;
if ( V_94 < V_28 && V_28 - V_94 + V_95 > V_45 -> V_26 )
goto V_36;
V_35 = F_11 ( V_3 , & V_17 ) ;
if ( V_35 < 0 )
goto V_36;
if ( V_94 > V_28 ) {
V_45 -> V_26 += V_94 - V_28 ;
} else {
V_35 = F_55 ( V_3 , V_94 , V_28 - 1 ) ;
if ( V_35 < 0 )
goto V_42;
V_45 -> V_26 -= V_28 - V_94 ;
}
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_21 -> V_24 = F_36 ( V_45 -> V_26 ) ;
F_19 ( V_13 , V_23 ) ;
F_20 ( V_17 ) ;
F_37 ( V_3 ) ;
F_60 ( V_73 , V_94 ) ;
V_42:
F_28 ( V_17 ) ;
V_36:
F_29 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
T_5 F_61 ( struct V_2 * V_3 , T_1 V_5 , void * V_96 ,
unsigned V_97 , T_3 V_98 )
{
struct V_11 * V_50 ;
struct V_10 * V_51 ;
struct V_99 * V_100 = V_96 ;
T_3 V_52 = F_2 ( V_3 ) -> V_14 ;
struct V_72 * V_73 = V_3 -> V_74 -> V_75 ;
void * V_13 ;
unsigned long V_28 , V_88 ;
T_5 V_34 ;
int V_35 , V_101 , V_58 ;
F_49 ( & F_2 ( V_3 ) -> V_37 ) ;
V_88 = F_3 ( V_3 ) ;
V_28 = F_8 (unsigned long,
nilfs_sufile_get_nsegments(sufile) - segnum,
nsi) ;
for ( V_101 = 0 ; V_101 < V_28 ; V_101 += V_34 , V_5 += V_34 ) {
V_34 = F_8 (unsigned long,
segusages_per_block -
nilfs_sufile_get_offset(sufile, segnum),
nsegs - i) ;
V_35 = F_13 ( V_3 , V_5 , 0 ,
& V_50 ) ;
if ( V_35 < 0 ) {
if ( V_35 != - V_91 )
goto V_36;
memset ( V_100 , 0 , V_97 * V_34 ) ;
V_100 = ( void * ) V_100 + V_97 * V_34 ;
continue;
}
V_13 = F_17 ( V_50 -> V_22 , V_23 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
for ( V_58 = 0 ; V_58 < V_34 ;
V_58 ++ , V_51 = ( void * ) V_51 + V_52 , V_100 = ( void * ) V_100 + V_97 ) {
V_100 -> V_102 = F_33 ( V_51 -> V_66 ) ;
V_100 -> V_103 = F_56 ( V_51 -> V_65 ) ;
V_100 -> V_104 = F_56 ( V_51 -> V_63 ) &
~ ( 1UL << V_105 ) ;
if ( F_57 ( V_73 , V_5 + V_58 ) )
V_100 -> V_104 |=
( 1UL << V_105 ) ;
}
F_19 ( V_13 , V_23 ) ;
F_28 ( V_50 ) ;
}
V_35 = V_28 ;
V_36:
F_52 ( & F_2 ( V_3 ) -> V_37 ) ;
return V_35 ;
}
int F_62 ( struct V_106 * V_107 , T_3 V_108 ,
struct V_109 * V_110 , struct V_2 * * V_111 )
{
struct V_2 * V_3 ;
struct V_1 * V_45 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
void * V_13 ;
int V_112 ;
V_3 = F_63 ( V_107 , NULL , V_113 ) ;
if ( F_24 ( ! V_3 ) )
return - V_114 ;
if ( ! ( V_3 -> V_115 & V_116 ) )
goto V_36;
V_112 = F_64 ( V_3 , V_117 , sizeof( * V_45 ) ) ;
if ( V_112 )
goto V_118;
F_65 ( V_3 , V_108 ,
sizeof( struct V_20 ) ) ;
V_112 = F_66 ( V_3 , V_110 ) ;
if ( V_112 )
goto V_118;
V_112 = F_11 ( V_3 , & V_17 ) ;
if ( V_112 )
goto V_118;
V_45 = F_1 ( V_3 ) ;
V_13 = F_17 ( V_17 -> V_22 , V_23 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_45 -> V_26 = F_33 ( V_21 -> V_24 ) ;
F_19 ( V_13 , V_23 ) ;
F_28 ( V_17 ) ;
V_45 -> V_48 = F_26 ( V_3 ) - 1 ;
V_45 -> V_47 = 0 ;
F_67 ( V_3 ) ;
V_36:
* V_111 = V_3 ;
return 0 ;
V_118:
F_68 ( V_3 ) ;
return V_112 ;
}
