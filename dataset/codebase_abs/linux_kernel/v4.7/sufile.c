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
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
F_18 ( & V_21 -> V_23 , V_18 ) ;
F_18 ( & V_21 -> V_24 , V_19 ) ;
F_19 ( V_13 ) ;
F_20 ( V_17 ) ;
}
unsigned long F_21 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_25 ;
}
int F_22 ( struct V_2 * V_3 , T_1 * V_26 , T_3 V_27 ,
int V_16 , T_3 * V_28 ,
void (* F_23)( struct V_2 * , T_1 ,
struct V_11 * ,
struct V_11 * ) )
{
struct V_11 * V_17 , * V_12 ;
unsigned long V_29 , V_30 ;
T_1 * V_31 ;
T_3 V_32 = 0 , V_33 = 0 ;
int V_34 = 0 ;
if ( F_24 ( V_27 == 0 ) )
goto V_35;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
for ( V_31 = V_26 ; V_31 < V_26 + V_27 ; V_31 ++ ) {
if ( F_24 ( * V_31 >= F_26 ( V_3 ) ) ) {
F_27 ( V_37
L_1 , V_38 ,
( unsigned long long ) * V_31 ) ;
V_32 ++ ;
}
}
if ( V_32 > 0 ) {
V_34 = - V_39 ;
goto V_40;
}
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_40;
V_31 = V_26 ;
V_29 = F_4 ( V_3 , * V_31 ) ;
V_34 = F_12 ( V_3 , V_29 , V_16 , NULL , & V_12 ) ;
if ( V_34 < 0 )
goto V_41;
for (; ; ) {
F_23 ( V_3 , * V_31 , V_17 , V_12 ) ;
if ( ++ V_31 >= V_26 + V_27 )
break;
V_30 = V_29 ;
V_29 = F_4 ( V_3 , * V_31 ) ;
if ( V_29 == V_30 )
continue;
F_28 ( V_12 ) ;
V_34 = F_12 ( V_3 , V_29 , V_16 , NULL , & V_12 ) ;
if ( F_24 ( V_34 < 0 ) )
goto V_41;
}
F_28 ( V_12 ) ;
V_41:
V_33 = V_31 - V_26 ;
F_28 ( V_17 ) ;
V_40:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
V_35:
if ( V_28 )
* V_28 = V_33 ;
return V_34 ;
}
int F_30 ( struct V_2 * V_3 , T_1 V_5 , int V_16 ,
void (* F_23)( struct V_2 * , T_1 ,
struct V_11 * ,
struct V_11 * ) )
{
struct V_11 * V_17 , * V_12 ;
int V_34 ;
if ( F_24 ( V_5 >= F_26 ( V_3 ) ) ) {
F_27 ( V_37 L_1 ,
V_38 , ( unsigned long long ) V_5 ) ;
return - V_39 ;
}
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_40;
V_34 = F_13 ( V_3 , V_5 , V_16 , & V_12 ) ;
if ( ! V_34 ) {
F_23 ( V_3 , V_5 , V_17 , V_12 ) ;
F_28 ( V_12 ) ;
}
F_28 ( V_17 ) ;
V_40:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_31 ( struct V_2 * V_3 , T_1 V_42 , T_1 V_43 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
T_1 V_27 ;
int V_34 = - V_45 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_27 = F_26 ( V_3 ) ;
if ( V_42 <= V_43 && V_43 < V_27 ) {
V_44 -> V_46 = V_42 ;
V_44 -> V_47 = V_43 ;
V_34 = 0 ;
}
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_32 ( struct V_2 * V_3 , T_1 * V_48 )
{
struct V_11 * V_17 , * V_49 ;
struct V_20 * V_21 ;
struct V_10 * V_50 ;
struct V_1 * V_44 = F_1 ( V_3 ) ;
T_3 V_51 = F_2 ( V_3 ) -> V_14 ;
T_1 V_5 , V_52 , V_53 ;
void * V_13 ;
unsigned long V_54 , V_55 , V_56 ;
int V_34 , V_57 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_40;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_53 = F_33 ( V_21 -> V_58 ) ;
F_19 ( V_13 ) ;
V_54 = F_26 ( V_3 ) ;
V_52 = V_44 -> V_47 ;
V_5 = V_53 + 1 ;
if ( V_5 < V_44 -> V_46 || V_5 > V_44 -> V_47 )
V_5 = V_44 -> V_46 ;
for ( V_56 = 0 ; V_56 < V_54 ; V_56 += V_55 ) {
if ( V_5 > V_52 ) {
if ( V_56 < V_44 -> V_47 - V_44 -> V_46 + 1 ) {
V_5 = V_44 -> V_46 ;
V_52 = V_53 ;
} else if ( V_5 > V_44 -> V_46 &&
V_44 -> V_47 + 1 < V_54 ) {
V_5 = V_44 -> V_47 + 1 ;
V_52 = V_54 - 1 ;
} else if ( V_44 -> V_46 > 0 ) {
V_5 = 0 ;
V_52 = V_44 -> V_46 - 1 ;
} else {
break;
}
}
F_34 ( V_3 , V_5 , V_56 ) ;
V_34 = F_13 ( V_3 , V_5 , 1 ,
& V_49 ) ;
if ( V_34 < 0 )
goto V_41;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 (
V_3 , V_5 , V_49 , V_13 ) ;
V_55 = F_7 (
V_3 , V_5 , V_52 ) ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ , V_50 = ( void * ) V_50 + V_51 , V_5 ++ ) {
if ( ! F_35 ( V_50 ) )
continue;
F_36 ( V_50 ) ;
F_19 ( V_13 ) ;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
F_18 ( & V_21 -> V_23 , - 1 ) ;
F_18 ( & V_21 -> V_24 , 1 ) ;
V_21 -> V_58 = F_37 ( V_5 ) ;
F_19 ( V_13 ) ;
V_44 -> V_25 -- ;
F_20 ( V_17 ) ;
F_20 ( V_49 ) ;
F_38 ( V_3 ) ;
F_28 ( V_49 ) ;
* V_48 = V_5 ;
F_39 ( V_3 , V_5 ) ;
goto V_41;
}
F_19 ( V_13 ) ;
F_28 ( V_49 ) ;
}
V_34 = - V_59 ;
V_41:
F_28 ( V_17 ) ;
V_40:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
void F_40 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_49 )
{
struct V_10 * V_50 ;
void * V_13 ;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 , V_49 , V_13 ) ;
if ( F_24 ( ! F_35 ( V_50 ) ) ) {
F_27 ( V_37 L_2 ,
V_38 , ( unsigned long long ) V_5 ) ;
F_19 ( V_13 ) ;
return;
}
F_36 ( V_50 ) ;
F_19 ( V_13 ) ;
F_16 ( V_17 , - 1 , 1 ) ;
F_1 ( V_3 ) -> V_25 -- ;
F_20 ( V_49 ) ;
F_38 ( V_3 ) ;
}
void F_41 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_49 )
{
struct V_10 * V_50 ;
void * V_13 ;
int V_60 , V_61 ;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 , V_49 , V_13 ) ;
if ( V_50 -> V_62 == F_42 ( 1UL << V_63 ) &&
V_50 -> V_64 == F_42 ( 0 ) ) {
F_19 ( V_13 ) ;
return;
}
V_60 = F_35 ( V_50 ) ;
V_61 = F_43 ( V_50 ) ;
V_50 -> V_65 = F_37 ( 0 ) ;
V_50 -> V_64 = F_42 ( 0 ) ;
V_50 -> V_62 = F_42 ( 1UL << V_63 ) ;
F_19 ( V_13 ) ;
F_16 ( V_17 , V_60 ? ( T_2 ) - 1 : 0 , V_61 ? 0 : 1 ) ;
F_1 ( V_3 ) -> V_25 -= V_60 ;
F_20 ( V_49 ) ;
F_38 ( V_3 ) ;
}
void F_44 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_49 )
{
struct V_10 * V_50 ;
void * V_13 ;
int V_66 ;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 , V_49 , V_13 ) ;
if ( F_35 ( V_50 ) ) {
F_27 ( V_37 L_3 ,
V_38 , ( unsigned long long ) V_5 ) ;
F_19 ( V_13 ) ;
return;
}
F_45 ( F_46 ( V_50 ) ) ;
F_45 ( ! F_43 ( V_50 ) ) ;
V_66 = F_43 ( V_50 ) ;
F_47 ( V_50 ) ;
F_19 ( V_13 ) ;
F_20 ( V_49 ) ;
F_16 ( V_17 , 1 , V_66 ? ( T_2 ) - 1 : 0 ) ;
F_1 ( V_3 ) -> V_25 ++ ;
F_38 ( V_3 ) ;
F_48 ( V_3 , V_5 ) ;
}
int F_49 ( struct V_2 * V_3 , T_1 V_5 )
{
struct V_11 * V_12 ;
int V_34 ;
V_34 = F_13 ( V_3 , V_5 , 0 , & V_12 ) ;
if ( ! V_34 ) {
F_20 ( V_12 ) ;
F_38 ( V_3 ) ;
F_28 ( V_12 ) ;
}
return V_34 ;
}
int F_50 ( struct V_2 * V_3 , T_1 V_5 ,
unsigned long V_67 , T_4 V_68 )
{
struct V_11 * V_12 ;
struct V_10 * V_50 ;
void * V_13 ;
int V_34 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 , & V_12 ) ;
if ( V_34 < 0 )
goto V_40;
V_13 = F_17 ( V_12 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 , V_12 , V_13 ) ;
F_45 ( F_46 ( V_50 ) ) ;
if ( V_68 )
V_50 -> V_65 = F_37 ( V_68 ) ;
V_50 -> V_64 = F_42 ( V_67 ) ;
F_19 ( V_13 ) ;
F_20 ( V_12 ) ;
F_38 ( V_3 ) ;
F_28 ( V_12 ) ;
V_40:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_51 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
void * V_13 ;
int V_34 ;
F_52 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_40;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_70 -> V_75 = F_26 ( V_3 ) ;
V_70 -> V_76 = F_33 ( V_21 -> V_23 ) ;
V_70 -> V_77 = F_33 ( V_21 -> V_24 ) ;
V_70 -> V_78 = V_72 -> V_79 ;
V_70 -> V_80 = V_72 -> V_81 ;
F_53 ( & V_72 -> V_82 ) ;
V_70 -> V_83 = V_72 -> V_84 ;
F_54 ( & V_72 -> V_82 ) ;
F_19 ( V_13 ) ;
F_28 ( V_17 ) ;
V_40:
F_55 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
void F_56 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_49 )
{
struct V_10 * V_50 ;
void * V_13 ;
int V_85 ;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 , V_49 , V_13 ) ;
if ( F_46 ( V_50 ) ) {
F_19 ( V_13 ) ;
return;
}
V_85 = F_35 ( V_50 ) ;
F_57 ( V_50 ) ;
F_19 ( V_13 ) ;
if ( V_85 ) {
F_16 ( V_17 , - 1 , 0 ) ;
F_1 ( V_3 ) -> V_25 -- ;
}
F_20 ( V_49 ) ;
F_38 ( V_3 ) ;
}
static int F_58 ( struct V_2 * V_3 ,
T_1 V_42 , T_1 V_43 )
{
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
struct V_11 * V_17 ;
struct V_11 * V_49 ;
struct V_10 * V_50 , * V_86 ;
T_3 V_51 = F_2 ( V_3 ) -> V_14 ;
unsigned long V_87 ;
unsigned long V_27 , V_88 ;
T_1 V_5 ;
void * V_13 ;
T_5 V_33 , V_89 ;
int V_34 ;
int V_57 ;
V_27 = F_26 ( V_3 ) ;
V_34 = - V_39 ;
if ( V_42 > V_43 || V_42 >= V_27 )
goto V_35;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_35;
V_87 = F_3 ( V_3 ) ;
V_88 = 0 ;
for ( V_5 = V_42 ; V_5 <= V_43 ; V_5 += V_33 ) {
V_33 = F_8 (unsigned long,
segusages_per_block -
nilfs_sufile_get_offset(sufile, segnum),
end - segnum + 1 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 ,
& V_49 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_41;
continue;
}
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 (
V_3 , V_5 , V_49 , V_13 ) ;
V_86 = V_50 ;
for ( V_57 = 0 ; V_57 < V_33 ; V_57 ++ , V_50 = ( void * ) V_50 + V_51 ) {
if ( ( F_59 ( V_50 -> V_62 ) &
~ ( 1UL << V_91 ) ) ||
F_60 ( V_72 , V_5 + V_57 ) ) {
V_34 = - V_92 ;
F_19 ( V_13 ) ;
F_28 ( V_49 ) ;
goto V_41;
}
}
V_89 = 0 ;
for ( V_50 = V_86 , V_57 = 0 ; V_57 < V_33 ; V_57 ++ , V_50 = ( void * ) V_50 + V_51 ) {
if ( F_46 ( V_50 ) ) {
F_47 ( V_50 ) ;
V_89 ++ ;
}
}
F_19 ( V_13 ) ;
if ( V_89 > 0 ) {
F_20 ( V_49 ) ;
V_88 += V_89 ;
}
F_28 ( V_49 ) ;
if ( V_33 == V_87 ) {
F_14 ( V_3 , V_5 ) ;
}
}
V_34 = 0 ;
V_41:
if ( V_88 > 0 ) {
F_1 ( V_3 ) -> V_25 += V_88 ;
F_16 ( V_17 , V_88 , 0 ) ;
F_38 ( V_3 ) ;
}
F_28 ( V_17 ) ;
V_35:
return V_34 ;
}
int F_61 ( struct V_2 * V_3 , T_1 V_93 )
{
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_1 * V_44 = F_1 ( V_3 ) ;
void * V_13 ;
unsigned long V_27 , V_94 ;
int V_34 = 0 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_27 = F_26 ( V_3 ) ;
if ( V_27 == V_93 )
goto V_35;
V_34 = - V_59 ;
V_94 = F_62 ( V_72 , V_93 ) ;
if ( V_93 < V_27 && V_27 - V_93 + V_94 > V_44 -> V_25 )
goto V_35;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_35;
if ( V_93 > V_27 ) {
V_44 -> V_25 += V_93 - V_27 ;
} else {
V_34 = F_58 ( V_3 , V_93 , V_27 - 1 ) ;
if ( V_34 < 0 )
goto V_41;
V_44 -> V_25 -= V_27 - V_93 ;
}
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_21 -> V_23 = F_37 ( V_44 -> V_25 ) ;
F_19 ( V_13 ) ;
F_20 ( V_17 ) ;
F_38 ( V_3 ) ;
F_63 ( V_72 , V_93 ) ;
V_41:
F_28 ( V_17 ) ;
V_35:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
T_5 F_64 ( struct V_2 * V_3 , T_1 V_5 , void * V_95 ,
unsigned int V_96 , T_3 V_97 )
{
struct V_11 * V_49 ;
struct V_10 * V_50 ;
struct V_98 * V_99 = V_95 ;
T_3 V_51 = F_2 ( V_3 ) -> V_14 ;
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
void * V_13 ;
unsigned long V_27 , V_87 ;
T_5 V_33 ;
int V_34 , V_100 , V_57 ;
F_52 ( & F_2 ( V_3 ) -> V_36 ) ;
V_87 = F_3 ( V_3 ) ;
V_27 = F_8 (unsigned long,
nilfs_sufile_get_nsegments(sufile) - segnum,
nsi) ;
for ( V_100 = 0 ; V_100 < V_27 ; V_100 += V_33 , V_5 += V_33 ) {
V_33 = F_8 (unsigned long,
segusages_per_block -
nilfs_sufile_get_offset(sufile, segnum),
nsegs - i) ;
V_34 = F_13 ( V_3 , V_5 , 0 ,
& V_49 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_35;
memset ( V_99 , 0 , V_96 * V_33 ) ;
V_99 = ( void * ) V_99 + V_96 * V_33 ;
continue;
}
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 (
V_3 , V_5 , V_49 , V_13 ) ;
for ( V_57 = 0 ; V_57 < V_33 ;
V_57 ++ , V_50 = ( void * ) V_50 + V_51 , V_99 = ( void * ) V_99 + V_96 ) {
V_99 -> V_101 = F_33 ( V_50 -> V_65 ) ;
V_99 -> V_102 = F_59 ( V_50 -> V_64 ) ;
V_99 -> V_103 = F_59 ( V_50 -> V_62 ) &
~ ( 1UL << V_104 ) ;
if ( F_60 ( V_72 , V_5 + V_57 ) )
V_99 -> V_103 |=
( 1UL << V_104 ) ;
}
F_19 ( V_13 ) ;
F_28 ( V_49 ) ;
}
V_34 = V_27 ;
V_35:
F_55 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
T_5 F_65 ( struct V_2 * V_3 , void * V_95 ,
unsigned int V_105 , T_3 V_106 )
{
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
struct V_11 * V_17 , * V_12 ;
struct V_107 * V_108 , * V_109 = V_95 + V_105 * V_106 ;
struct V_10 * V_50 ;
void * V_13 ;
unsigned long V_29 , V_30 ;
int V_110 , V_111 , V_112 , V_113 ;
long V_88 = 0 , V_114 = 0 ;
int V_34 = 0 ;
if ( F_24 ( V_106 == 0 ) )
return V_34 ;
for ( V_108 = V_95 ; V_108 < V_109 ; V_108 = ( void * ) V_108 + V_105 ) {
if ( V_108 -> V_115 >= V_72 -> V_116
|| ( V_108 -> V_117 &
( ~ 0UL << V_118 ) )
|| ( F_66 ( V_108 ) &&
V_108 -> V_119 . V_102 >
V_72 -> V_120 ) )
return - V_39 ;
}
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_40;
V_108 = V_95 ;
V_29 = F_4 ( V_3 , V_108 -> V_115 ) ;
V_34 = F_12 ( V_3 , V_29 , 1 , NULL , & V_12 ) ;
if ( V_34 < 0 )
goto V_41;
for (; ; ) {
V_13 = F_17 ( V_12 -> V_22 ) ;
V_50 = F_9 (
V_3 , V_108 -> V_115 , V_12 , V_13 ) ;
if ( F_67 ( V_108 ) )
V_50 -> V_65 = F_37 ( V_108 -> V_119 . V_101 ) ;
if ( F_66 ( V_108 ) )
V_50 -> V_64 = F_42 ( V_108 -> V_119 . V_102 ) ;
if ( F_68 ( V_108 ) ) {
V_108 -> V_119 . V_103 &=
~ ( 1UL << V_104 ) ;
V_110 = F_69 ( & V_108 -> V_119 ) ;
V_111 = F_35 ( V_50 ) ;
V_112 = F_70 ( & V_108 -> V_119 ) ;
V_113 = F_43 ( V_50 ) ;
if ( V_110 && ! V_111 )
++ V_88 ;
else if ( ! V_110 && V_111 )
-- V_88 ;
if ( V_112 && ! V_113 )
++ V_114 ;
else if ( ! V_112 && V_113 )
-- V_114 ;
V_50 -> V_62 = F_42 ( V_108 -> V_119 . V_103 ) ;
}
F_19 ( V_13 ) ;
V_108 = ( void * ) V_108 + V_105 ;
if ( V_108 >= V_109 )
break;
V_30 = V_29 ;
V_29 = F_4 ( V_3 , V_108 -> V_115 ) ;
if ( V_29 == V_30 )
continue;
F_20 ( V_12 ) ;
F_71 ( V_12 ) ;
V_34 = F_12 ( V_3 , V_29 , 1 , NULL , & V_12 ) ;
if ( F_24 ( V_34 < 0 ) )
goto V_121;
}
F_20 ( V_12 ) ;
F_71 ( V_12 ) ;
V_121:
if ( V_88 || V_114 ) {
F_16 ( V_17 , ( T_2 ) V_88 ,
( T_2 ) V_114 ) ;
F_1 ( V_3 ) -> V_25 += V_88 ;
}
F_38 ( V_3 ) ;
V_41:
F_71 ( V_17 ) ;
V_40:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_72 ( struct V_2 * V_3 , struct V_122 * V_123 )
{
struct V_71 * V_72 = V_3 -> V_73 -> V_74 ;
struct V_11 * V_49 ;
struct V_10 * V_50 ;
void * V_13 ;
T_3 V_33 , V_100 , V_51 = F_2 ( V_3 ) -> V_14 ;
T_6 V_124 , V_125 , V_126 , V_127 ;
T_6 V_42 = 0 , V_67 = 0 ;
T_2 V_5 , V_128 , V_129 , V_130 , V_131 , V_132 = 0 ;
int V_34 = 0 ;
unsigned int V_133 ;
V_133 = ( 1 << V_72 -> V_134 ) /
F_73 ( V_72 -> V_135 ) ;
V_130 = V_123 -> V_130 >> V_72 -> V_134 ;
V_129 = V_123 -> V_129 >> V_72 -> V_134 ;
V_131 = ( ( T_2 ) V_72 -> V_116 * V_72 -> V_120 ) ;
if ( ! V_130 || V_123 -> V_42 >= V_131 << V_72 -> V_134 )
return - V_39 ;
V_126 = ( V_123 -> V_42 + V_72 -> V_136 - 1 ) >>
V_72 -> V_134 ;
if ( V_131 - V_126 < V_130 )
V_127 = V_131 - 1 ;
else
V_127 = V_126 + V_130 - 1 ;
V_5 = F_74 ( V_72 , V_126 ) ;
V_128 = F_74 ( V_72 , V_127 ) ;
F_52 ( & F_2 ( V_3 ) -> V_36 ) ;
while ( V_5 <= V_128 ) {
V_33 = F_7 ( V_3 , V_5 ,
V_128 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 ,
& V_49 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_40;
V_5 += V_33 ;
continue;
}
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 ( V_3 , V_5 ,
V_49 , V_13 ) ;
for ( V_100 = 0 ; V_100 < V_33 ; ++ V_100 , ++ V_5 , V_50 = ( void * ) V_50 + V_51 ) {
if ( ! F_35 ( V_50 ) )
continue;
F_75 ( V_72 , V_5 , & V_124 ,
& V_125 ) ;
if ( ! V_67 ) {
V_42 = V_124 ;
V_67 = V_125 - V_124 + 1 ;
continue;
}
if ( V_42 + V_67 == V_124 ) {
V_67 += V_125 - V_124 + 1 ;
continue;
}
if ( V_42 < V_126 ) {
V_67 -= V_126 - V_42 ;
V_42 = V_126 ;
}
if ( V_67 >= V_129 ) {
F_19 ( V_13 ) ;
V_34 = F_76 ( V_72 -> V_135 ,
V_42 * V_133 ,
V_67 * V_133 ,
V_137 , 0 ) ;
if ( V_34 < 0 ) {
F_71 ( V_49 ) ;
goto V_40;
}
V_132 += V_67 ;
V_13 = F_17 ( V_49 -> V_22 ) ;
V_50 = F_9 (
V_3 , V_5 , V_49 , V_13 ) ;
}
V_42 = V_124 ;
V_67 = V_125 - V_124 + 1 ;
}
F_19 ( V_13 ) ;
F_71 ( V_49 ) ;
}
if ( V_67 ) {
if ( V_42 < V_126 ) {
V_67 -= V_126 - V_42 ;
V_42 = V_126 ;
}
if ( V_42 + V_67 > V_127 + 1 )
V_67 = V_127 - V_42 + 1 ;
if ( V_67 >= V_129 ) {
V_34 = F_76 ( V_72 -> V_135 ,
V_42 * V_133 ,
V_67 * V_133 ,
V_137 , 0 ) ;
if ( ! V_34 )
V_132 += V_67 ;
}
}
V_40:
F_55 ( & F_2 ( V_3 ) -> V_36 ) ;
V_123 -> V_130 = V_132 << V_72 -> V_134 ;
return V_34 ;
}
int F_77 ( struct V_138 * V_139 , T_3 V_140 ,
struct V_141 * V_142 , struct V_2 * * V_143 )
{
struct V_2 * V_3 ;
struct V_1 * V_44 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
void * V_13 ;
int V_144 ;
if ( V_140 > V_139 -> V_145 ) {
F_27 ( V_146
L_4 ,
V_140 ) ;
return - V_39 ;
} else if ( V_140 < V_147 ) {
F_27 ( V_146
L_5 ,
V_140 ) ;
return - V_39 ;
}
V_3 = F_78 ( V_139 , NULL , V_148 ) ;
if ( F_24 ( ! V_3 ) )
return - V_149 ;
if ( ! ( V_3 -> V_150 & V_151 ) )
goto V_35;
V_144 = F_79 ( V_3 , V_152 , sizeof( * V_44 ) ) ;
if ( V_144 )
goto V_153;
F_80 ( V_3 , V_140 ,
sizeof( struct V_20 ) ) ;
V_144 = F_81 ( V_3 , V_142 ) ;
if ( V_144 )
goto V_153;
V_144 = F_11 ( V_3 , & V_17 ) ;
if ( V_144 )
goto V_153;
V_44 = F_1 ( V_3 ) ;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_44 -> V_25 = F_33 ( V_21 -> V_23 ) ;
F_19 ( V_13 ) ;
F_28 ( V_17 ) ;
V_44 -> V_47 = F_26 ( V_3 ) - 1 ;
V_44 -> V_46 = 0 ;
F_82 ( V_3 ) ;
V_35:
* V_143 = V_3 ;
return 0 ;
V_153:
F_83 ( V_3 ) ;
return V_144 ;
}
