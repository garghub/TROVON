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
F_27 ( V_3 -> V_37 , V_38 ,
L_1 ,
V_39 , ( unsigned long long ) * V_31 ) ;
V_32 ++ ;
}
}
if ( V_32 > 0 ) {
V_34 = - V_40 ;
goto V_41;
}
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_41;
V_31 = V_26 ;
V_29 = F_4 ( V_3 , * V_31 ) ;
V_34 = F_12 ( V_3 , V_29 , V_16 , NULL , & V_12 ) ;
if ( V_34 < 0 )
goto V_42;
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
goto V_42;
}
F_28 ( V_12 ) ;
V_42:
V_33 = V_31 - V_26 ;
F_28 ( V_17 ) ;
V_41:
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
F_27 ( V_3 -> V_37 , V_38 ,
L_1 ,
V_39 , ( unsigned long long ) V_5 ) ;
return - V_40 ;
}
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_41;
V_34 = F_13 ( V_3 , V_5 , V_16 , & V_12 ) ;
if ( ! V_34 ) {
F_23 ( V_3 , V_5 , V_17 , V_12 ) ;
F_28 ( V_12 ) ;
}
F_28 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_31 ( struct V_2 * V_3 , T_1 V_43 , T_1 V_44 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
T_1 V_27 ;
int V_34 = - V_46 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_27 = F_26 ( V_3 ) ;
if ( V_43 <= V_44 && V_44 < V_27 ) {
V_45 -> V_47 = V_43 ;
V_45 -> V_48 = V_44 ;
V_34 = 0 ;
}
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
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
unsigned long V_55 , V_56 , V_57 ;
int V_34 , V_58 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_41;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_54 = F_33 ( V_21 -> V_59 ) ;
F_19 ( V_13 ) ;
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
F_34 ( V_3 , V_5 , V_57 ) ;
V_34 = F_13 ( V_3 , V_5 , 1 ,
& V_50 ) ;
if ( V_34 < 0 )
goto V_42;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
V_56 = F_7 (
V_3 , V_5 , V_53 ) ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 , V_5 ++ ) {
if ( ! F_35 ( V_51 ) )
continue;
F_36 ( V_51 ) ;
F_19 ( V_13 ) ;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
F_18 ( & V_21 -> V_23 , - 1 ) ;
F_18 ( & V_21 -> V_24 , 1 ) ;
V_21 -> V_59 = F_37 ( V_5 ) ;
F_19 ( V_13 ) ;
V_45 -> V_25 -- ;
F_20 ( V_17 ) ;
F_20 ( V_50 ) ;
F_38 ( V_3 ) ;
F_28 ( V_50 ) ;
* V_49 = V_5 ;
F_39 ( V_3 , V_5 ) ;
goto V_42;
}
F_19 ( V_13 ) ;
F_28 ( V_50 ) ;
}
V_34 = - V_60 ;
V_42:
F_28 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
void F_40 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_24 ( ! F_35 ( V_51 ) ) ) {
F_27 ( V_3 -> V_37 , V_38 ,
L_2 , V_39 ,
( unsigned long long ) V_5 ) ;
F_19 ( V_13 ) ;
return;
}
F_36 ( V_51 ) ;
F_19 ( V_13 ) ;
F_16 ( V_17 , - 1 , 1 ) ;
F_1 ( V_3 ) -> V_25 -- ;
F_20 ( V_50 ) ;
F_38 ( V_3 ) ;
}
void F_41 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_61 , V_62 ;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( V_51 -> V_63 == F_42 ( F_43 ( V_64 ) ) &&
V_51 -> V_65 == F_42 ( 0 ) ) {
F_19 ( V_13 ) ;
return;
}
V_61 = F_35 ( V_51 ) ;
V_62 = F_44 ( V_51 ) ;
V_51 -> V_66 = F_37 ( 0 ) ;
V_51 -> V_65 = F_42 ( 0 ) ;
V_51 -> V_63 = F_42 ( F_43 ( V_64 ) ) ;
F_19 ( V_13 ) ;
F_16 ( V_17 , V_61 ? ( T_2 ) - 1 : 0 , V_62 ? 0 : 1 ) ;
F_1 ( V_3 ) -> V_25 -= V_61 ;
F_20 ( V_50 ) ;
F_38 ( V_3 ) ;
}
void F_45 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_67 ;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_35 ( V_51 ) ) {
F_27 ( V_3 -> V_37 , V_38 ,
L_3 ,
V_39 , ( unsigned long long ) V_5 ) ;
F_19 ( V_13 ) ;
return;
}
F_46 ( F_47 ( V_51 ) ) ;
F_46 ( ! F_44 ( V_51 ) ) ;
V_67 = F_44 ( V_51 ) ;
F_48 ( V_51 ) ;
F_19 ( V_13 ) ;
F_20 ( V_50 ) ;
F_16 ( V_17 , 1 , V_67 ? ( T_2 ) - 1 : 0 ) ;
F_1 ( V_3 ) -> V_25 ++ ;
F_38 ( V_3 ) ;
F_49 ( V_3 , V_5 ) ;
}
int F_50 ( struct V_2 * V_3 , T_1 V_5 )
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
int F_51 ( struct V_2 * V_3 , T_1 V_5 ,
unsigned long V_68 , T_4 V_69 )
{
struct V_11 * V_12 ;
struct V_10 * V_51 ;
void * V_13 ;
int V_34 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 , & V_12 ) ;
if ( V_34 < 0 )
goto V_41;
V_13 = F_17 ( V_12 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 , V_12 , V_13 ) ;
F_46 ( F_47 ( V_51 ) ) ;
if ( V_69 )
V_51 -> V_66 = F_37 ( V_69 ) ;
V_51 -> V_65 = F_42 ( V_68 ) ;
F_19 ( V_13 ) ;
F_20 ( V_12 ) ;
F_38 ( V_3 ) ;
F_28 ( V_12 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_52 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
void * V_13 ;
int V_34 ;
F_53 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_41;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_71 -> V_75 = F_26 ( V_3 ) ;
V_71 -> V_76 = F_33 ( V_21 -> V_23 ) ;
V_71 -> V_77 = F_33 ( V_21 -> V_24 ) ;
V_71 -> V_78 = V_73 -> V_79 ;
V_71 -> V_80 = V_73 -> V_81 ;
F_54 ( & V_73 -> V_82 ) ;
V_71 -> V_83 = V_73 -> V_84 ;
F_55 ( & V_73 -> V_82 ) ;
F_19 ( V_13 ) ;
F_28 ( V_17 ) ;
V_41:
F_56 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
void F_57 ( struct V_2 * V_3 , T_1 V_5 ,
struct V_11 * V_17 ,
struct V_11 * V_50 )
{
struct V_10 * V_51 ;
void * V_13 ;
int V_85 ;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 , V_50 , V_13 ) ;
if ( F_47 ( V_51 ) ) {
F_19 ( V_13 ) ;
return;
}
V_85 = F_35 ( V_51 ) ;
F_58 ( V_51 ) ;
F_19 ( V_13 ) ;
if ( V_85 ) {
F_16 ( V_17 , - 1 , 0 ) ;
F_1 ( V_3 ) -> V_25 -- ;
}
F_20 ( V_50 ) ;
F_38 ( V_3 ) ;
}
static int F_59 ( struct V_2 * V_3 ,
T_1 V_43 , T_1 V_44 )
{
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
struct V_11 * V_17 ;
struct V_11 * V_50 ;
struct V_10 * V_51 , * V_86 ;
T_3 V_52 = F_2 ( V_3 ) -> V_14 ;
unsigned long V_87 ;
unsigned long V_27 , V_88 ;
T_1 V_5 ;
void * V_13 ;
T_5 V_33 , V_89 ;
int V_34 ;
int V_58 ;
V_27 = F_26 ( V_3 ) ;
V_34 = - V_40 ;
if ( V_43 > V_44 || V_43 >= V_27 )
goto V_35;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_35;
V_87 = F_3 ( V_3 ) ;
V_88 = 0 ;
for ( V_5 = V_43 ; V_5 <= V_44 ; V_5 += V_33 ) {
V_33 = F_8 (unsigned long,
segusages_per_block -
nilfs_sufile_get_offset(sufile, segnum),
end - segnum + 1 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 ,
& V_50 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_42;
continue;
}
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
V_86 = V_51 ;
for ( V_58 = 0 ; V_58 < V_33 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 ) {
if ( ( F_60 ( V_51 -> V_63 ) &
~ F_43 ( V_91 ) ) ||
F_61 ( V_73 , V_5 + V_58 ) ) {
V_34 = - V_92 ;
F_19 ( V_13 ) ;
F_28 ( V_50 ) ;
goto V_42;
}
}
V_89 = 0 ;
for ( V_51 = V_86 , V_58 = 0 ; V_58 < V_33 ; V_58 ++ , V_51 = ( void * ) V_51 + V_52 ) {
if ( F_47 ( V_51 ) ) {
F_48 ( V_51 ) ;
V_89 ++ ;
}
}
F_19 ( V_13 ) ;
if ( V_89 > 0 ) {
F_20 ( V_50 ) ;
V_88 += V_89 ;
}
F_28 ( V_50 ) ;
if ( V_33 == V_87 ) {
F_14 ( V_3 , V_5 ) ;
}
}
V_34 = 0 ;
V_42:
if ( V_88 > 0 ) {
F_1 ( V_3 ) -> V_25 += V_88 ;
F_16 ( V_17 , V_88 , 0 ) ;
F_38 ( V_3 ) ;
}
F_28 ( V_17 ) ;
V_35:
return V_34 ;
}
int F_62 ( struct V_2 * V_3 , T_1 V_93 )
{
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
struct V_1 * V_45 = F_1 ( V_3 ) ;
void * V_13 ;
unsigned long V_27 , V_94 ;
int V_34 = 0 ;
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_27 = F_26 ( V_3 ) ;
if ( V_27 == V_93 )
goto V_35;
V_34 = - V_60 ;
V_94 = F_63 ( V_73 , V_93 ) ;
if ( V_93 < V_27 && V_27 - V_93 + V_94 > V_45 -> V_25 )
goto V_35;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_35;
if ( V_93 > V_27 ) {
V_45 -> V_25 += V_93 - V_27 ;
} else {
V_34 = F_59 ( V_3 , V_93 , V_27 - 1 ) ;
if ( V_34 < 0 )
goto V_42;
V_45 -> V_25 -= V_27 - V_93 ;
}
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_21 -> V_23 = F_37 ( V_45 -> V_25 ) ;
F_19 ( V_13 ) ;
F_20 ( V_17 ) ;
F_38 ( V_3 ) ;
F_64 ( V_73 , V_93 ) ;
V_42:
F_28 ( V_17 ) ;
V_35:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
T_5 F_65 ( struct V_2 * V_3 , T_1 V_5 , void * V_95 ,
unsigned int V_96 , T_3 V_97 )
{
struct V_11 * V_50 ;
struct V_10 * V_51 ;
struct V_98 * V_99 = V_95 ;
T_3 V_52 = F_2 ( V_3 ) -> V_14 ;
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
void * V_13 ;
unsigned long V_27 , V_87 ;
T_5 V_33 ;
int V_34 , V_100 , V_58 ;
F_53 ( & F_2 ( V_3 ) -> V_36 ) ;
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
& V_50 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_35;
memset ( V_99 , 0 , V_96 * V_33 ) ;
V_99 = ( void * ) V_99 + V_96 * V_33 ;
continue;
}
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
for ( V_58 = 0 ; V_58 < V_33 ;
V_58 ++ , V_51 = ( void * ) V_51 + V_52 , V_99 = ( void * ) V_99 + V_96 ) {
V_99 -> V_101 = F_33 ( V_51 -> V_66 ) ;
V_99 -> V_102 = F_60 ( V_51 -> V_65 ) ;
V_99 -> V_103 = F_60 ( V_51 -> V_63 ) &
~ F_43 ( V_104 ) ;
if ( F_61 ( V_73 , V_5 + V_58 ) )
V_99 -> V_103 |=
F_43 ( V_104 ) ;
}
F_19 ( V_13 ) ;
F_28 ( V_50 ) ;
}
V_34 = V_27 ;
V_35:
F_56 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
T_5 F_66 ( struct V_2 * V_3 , void * V_95 ,
unsigned int V_105 , T_3 V_106 )
{
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
struct V_11 * V_17 , * V_12 ;
struct V_107 * V_108 , * V_109 = V_95 + V_105 * V_106 ;
struct V_10 * V_51 ;
void * V_13 ;
unsigned long V_29 , V_30 ;
int V_110 , V_111 , V_112 , V_113 ;
long V_88 = 0 , V_114 = 0 ;
int V_34 = 0 ;
if ( F_24 ( V_106 == 0 ) )
return V_34 ;
for ( V_108 = V_95 ; V_108 < V_109 ; V_108 = ( void * ) V_108 + V_105 ) {
if ( V_108 -> V_115 >= V_73 -> V_116
|| ( V_108 -> V_117 &
( ~ 0UL << V_118 ) )
|| ( F_67 ( V_108 ) &&
V_108 -> V_119 . V_102 >
V_73 -> V_120 ) )
return - V_40 ;
}
F_25 ( & F_2 ( V_3 ) -> V_36 ) ;
V_34 = F_11 ( V_3 , & V_17 ) ;
if ( V_34 < 0 )
goto V_41;
V_108 = V_95 ;
V_29 = F_4 ( V_3 , V_108 -> V_115 ) ;
V_34 = F_12 ( V_3 , V_29 , 1 , NULL , & V_12 ) ;
if ( V_34 < 0 )
goto V_42;
for (; ; ) {
V_13 = F_17 ( V_12 -> V_22 ) ;
V_51 = F_9 (
V_3 , V_108 -> V_115 , V_12 , V_13 ) ;
if ( F_68 ( V_108 ) )
V_51 -> V_66 = F_37 ( V_108 -> V_119 . V_101 ) ;
if ( F_67 ( V_108 ) )
V_51 -> V_65 = F_42 ( V_108 -> V_119 . V_102 ) ;
if ( F_69 ( V_108 ) ) {
V_108 -> V_119 . V_103 &=
~ F_43 ( V_104 ) ;
V_110 = F_70 ( & V_108 -> V_119 ) ;
V_111 = F_35 ( V_51 ) ;
V_112 = F_71 ( & V_108 -> V_119 ) ;
V_113 = F_44 ( V_51 ) ;
if ( V_110 && ! V_111 )
++ V_88 ;
else if ( ! V_110 && V_111 )
-- V_88 ;
if ( V_112 && ! V_113 )
++ V_114 ;
else if ( ! V_112 && V_113 )
-- V_114 ;
V_51 -> V_63 = F_42 ( V_108 -> V_119 . V_103 ) ;
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
F_72 ( V_12 ) ;
V_34 = F_12 ( V_3 , V_29 , 1 , NULL , & V_12 ) ;
if ( F_24 ( V_34 < 0 ) )
goto V_121;
}
F_20 ( V_12 ) ;
F_72 ( V_12 ) ;
V_121:
if ( V_88 || V_114 ) {
F_16 ( V_17 , ( T_2 ) V_88 ,
( T_2 ) V_114 ) ;
F_1 ( V_3 ) -> V_25 += V_88 ;
}
F_38 ( V_3 ) ;
V_42:
F_72 ( V_17 ) ;
V_41:
F_29 ( & F_2 ( V_3 ) -> V_36 ) ;
return V_34 ;
}
int F_73 ( struct V_2 * V_3 , struct V_122 * V_123 )
{
struct V_72 * V_73 = V_3 -> V_37 -> V_74 ;
struct V_11 * V_50 ;
struct V_10 * V_51 ;
void * V_13 ;
T_3 V_33 , V_100 , V_52 = F_2 ( V_3 ) -> V_14 ;
T_6 V_124 , V_125 , V_126 , V_127 ;
T_6 V_43 = 0 , V_68 = 0 ;
T_2 V_5 , V_128 , V_129 , V_130 , V_131 , V_132 = 0 ;
int V_34 = 0 ;
unsigned int V_133 ;
V_133 = ( 1 << V_73 -> V_134 ) /
F_74 ( V_73 -> V_135 ) ;
V_130 = V_123 -> V_130 >> V_73 -> V_134 ;
V_129 = V_123 -> V_129 >> V_73 -> V_134 ;
V_131 = ( ( T_2 ) V_73 -> V_116 * V_73 -> V_120 ) ;
if ( ! V_130 || V_123 -> V_43 >= V_131 << V_73 -> V_134 )
return - V_40 ;
V_126 = ( V_123 -> V_43 + V_73 -> V_136 - 1 ) >>
V_73 -> V_134 ;
if ( V_131 - V_126 < V_130 )
V_127 = V_131 - 1 ;
else
V_127 = V_126 + V_130 - 1 ;
V_5 = F_75 ( V_73 , V_126 ) ;
V_128 = F_75 ( V_73 , V_127 ) ;
F_53 ( & F_2 ( V_3 ) -> V_36 ) ;
while ( V_5 <= V_128 ) {
V_33 = F_7 ( V_3 , V_5 ,
V_128 ) ;
V_34 = F_13 ( V_3 , V_5 , 0 ,
& V_50 ) ;
if ( V_34 < 0 ) {
if ( V_34 != - V_90 )
goto V_41;
V_5 += V_33 ;
continue;
}
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 ( V_3 , V_5 ,
V_50 , V_13 ) ;
for ( V_100 = 0 ; V_100 < V_33 ; ++ V_100 , ++ V_5 , V_51 = ( void * ) V_51 + V_52 ) {
if ( ! F_35 ( V_51 ) )
continue;
F_76 ( V_73 , V_5 , & V_124 ,
& V_125 ) ;
if ( ! V_68 ) {
V_43 = V_124 ;
V_68 = V_125 - V_124 + 1 ;
continue;
}
if ( V_43 + V_68 == V_124 ) {
V_68 += V_125 - V_124 + 1 ;
continue;
}
if ( V_43 < V_126 ) {
V_68 -= V_126 - V_43 ;
V_43 = V_126 ;
}
if ( V_68 >= V_129 ) {
F_19 ( V_13 ) ;
V_34 = F_77 ( V_73 -> V_135 ,
V_43 * V_133 ,
V_68 * V_133 ,
V_137 , 0 ) ;
if ( V_34 < 0 ) {
F_72 ( V_50 ) ;
goto V_41;
}
V_132 += V_68 ;
V_13 = F_17 ( V_50 -> V_22 ) ;
V_51 = F_9 (
V_3 , V_5 , V_50 , V_13 ) ;
}
V_43 = V_124 ;
V_68 = V_125 - V_124 + 1 ;
}
F_19 ( V_13 ) ;
F_72 ( V_50 ) ;
}
if ( V_68 ) {
if ( V_43 < V_126 ) {
V_68 -= V_126 - V_43 ;
V_43 = V_126 ;
}
if ( V_43 + V_68 > V_127 + 1 )
V_68 = V_127 - V_43 + 1 ;
if ( V_68 >= V_129 ) {
V_34 = F_77 ( V_73 -> V_135 ,
V_43 * V_133 ,
V_68 * V_133 ,
V_137 , 0 ) ;
if ( ! V_34 )
V_132 += V_68 ;
}
}
V_41:
F_56 ( & F_2 ( V_3 ) -> V_36 ) ;
V_123 -> V_130 = V_132 << V_73 -> V_134 ;
return V_34 ;
}
int F_78 ( struct V_138 * V_139 , T_3 V_140 ,
struct V_141 * V_142 , struct V_2 * * V_143 )
{
struct V_2 * V_3 ;
struct V_1 * V_45 ;
struct V_11 * V_17 ;
struct V_20 * V_21 ;
void * V_13 ;
int V_144 ;
if ( V_140 > V_139 -> V_145 ) {
F_27 ( V_139 , V_146 ,
L_4 , V_140 ) ;
return - V_40 ;
} else if ( V_140 < V_147 ) {
F_27 ( V_139 , V_146 ,
L_5 , V_140 ) ;
return - V_40 ;
}
V_3 = F_79 ( V_139 , NULL , V_148 ) ;
if ( F_24 ( ! V_3 ) )
return - V_149 ;
if ( ! ( V_3 -> V_150 & V_151 ) )
goto V_35;
V_144 = F_80 ( V_3 , V_152 , sizeof( * V_45 ) ) ;
if ( V_144 )
goto V_153;
F_81 ( V_3 , V_140 ,
sizeof( struct V_20 ) ) ;
V_144 = F_82 ( V_3 , V_142 ) ;
if ( V_144 )
goto V_153;
V_144 = F_11 ( V_3 , & V_17 ) ;
if ( V_144 )
goto V_153;
V_45 = F_1 ( V_3 ) ;
V_13 = F_17 ( V_17 -> V_22 ) ;
V_21 = V_13 + F_10 ( V_17 ) ;
V_45 -> V_25 = F_33 ( V_21 -> V_23 ) ;
F_19 ( V_13 ) ;
F_28 ( V_17 ) ;
V_45 -> V_48 = F_26 ( V_3 ) - 1 ;
V_45 -> V_47 = 0 ;
F_83 ( V_3 ) ;
V_35:
* V_143 = V_3 ;
return 0 ;
V_153:
F_84 ( V_3 ) ;
return V_144 ;
}
