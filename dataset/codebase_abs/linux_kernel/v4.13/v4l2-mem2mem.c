static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 type )
{
if ( F_2 ( type ) )
return & V_3 -> V_5 ;
else
return & V_3 -> V_6 ;
}
struct V_7 * F_3 ( struct V_2 * V_3 ,
enum V_4 type )
{
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , type ) ;
if ( ! V_8 )
return NULL ;
return & V_8 -> V_9 ;
}
void * F_4 ( struct V_1 * V_8 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
if ( F_6 ( & V_8 -> V_14 ) ) {
F_7 ( & V_8 -> V_13 , V_12 ) ;
return NULL ;
}
V_11 = F_8 ( & V_8 -> V_14 , struct V_10 , V_15 ) ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_16 ;
}
void * F_9 ( struct V_1 * V_8 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
if ( F_6 ( & V_8 -> V_14 ) ) {
F_7 ( & V_8 -> V_13 , V_12 ) ;
return NULL ;
}
V_11 = F_8 ( & V_8 -> V_14 , struct V_10 , V_15 ) ;
F_10 ( & V_11 -> V_15 ) ;
V_8 -> V_17 -- ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_16 ;
}
void F_11 ( struct V_1 * V_8 ,
struct V_18 * V_19 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
V_11 = F_12 ( V_19 , struct V_10 , V_16 ) ;
F_10 ( & V_11 -> V_15 ) ;
V_8 -> V_17 -- ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
}
struct V_18 *
F_13 ( struct V_1 * V_8 , unsigned int V_20 )
{
struct V_10 * V_11 , * V_21 ;
struct V_18 * V_22 = NULL ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_14 (b, tmp, &q_ctx->rdy_queue, list) {
if ( V_11 -> V_16 . V_23 . V_24 == V_20 ) {
F_10 ( & V_11 -> V_15 ) ;
V_8 -> V_17 -- ;
V_22 = & V_11 -> V_16 ;
break;
}
}
F_7 ( & V_8 -> V_13 , V_12 ) ;
return V_22 ;
}
void * F_15 ( struct V_25 * V_26 )
{
unsigned long V_12 ;
void * V_22 = NULL ;
F_5 ( & V_26 -> V_27 , V_12 ) ;
if ( V_26 -> V_28 )
V_22 = V_26 -> V_28 -> V_29 ;
F_7 ( & V_26 -> V_27 , V_12 ) ;
return V_22 ;
}
static void F_16 ( struct V_25 * V_26 )
{
unsigned long V_12 ;
F_5 ( & V_26 -> V_27 , V_12 ) ;
if ( NULL != V_26 -> V_28 ) {
F_7 ( & V_26 -> V_27 , V_12 ) ;
F_17 ( L_1 ) ;
return;
}
if ( F_6 ( & V_26 -> V_30 ) ) {
F_7 ( & V_26 -> V_27 , V_12 ) ;
F_17 ( L_2 ) ;
return;
}
V_26 -> V_28 = F_8 ( & V_26 -> V_30 ,
struct V_2 , V_31 ) ;
V_26 -> V_28 -> V_32 |= V_33 ;
F_7 ( & V_26 -> V_27 , V_12 ) ;
V_26 -> V_34 -> V_35 ( V_26 -> V_28 -> V_29 ) ;
}
void F_18 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
unsigned long V_36 , V_37 , V_38 ;
V_26 = V_3 -> V_26 ;
F_17 ( L_3 , V_3 ) ;
if ( ! V_3 -> V_5 . V_9 . V_39
|| ! V_3 -> V_6 . V_9 . V_39 ) {
F_17 ( L_4 ) ;
return;
}
F_5 ( & V_26 -> V_27 , V_36 ) ;
if ( V_3 -> V_32 & V_40 ) {
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_17 ( L_5 ) ;
return;
}
if ( V_3 -> V_32 & V_41 ) {
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_17 ( L_6 ) ;
return;
}
F_5 ( & V_3 -> V_5 . V_13 , V_37 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 )
&& ! V_3 -> V_5 . V_42 ) {
F_7 ( & V_3 -> V_5 . V_13 ,
V_37 ) ;
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_17 ( L_7 ) ;
return;
}
F_5 ( & V_3 -> V_6 . V_13 , V_38 ) ;
if ( F_6 ( & V_3 -> V_6 . V_14 )
&& ! V_3 -> V_6 . V_42 ) {
F_7 ( & V_3 -> V_6 . V_13 ,
V_38 ) ;
F_7 ( & V_3 -> V_5 . V_13 ,
V_37 ) ;
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_17 ( L_8 ) ;
return;
}
F_7 ( & V_3 -> V_6 . V_13 , V_38 ) ;
F_7 ( & V_3 -> V_5 . V_13 , V_37 ) ;
if ( V_26 -> V_34 -> V_43
&& ( ! V_26 -> V_34 -> V_43 ( V_3 -> V_29 ) ) ) {
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_17 ( L_9 ) ;
return;
}
F_19 ( & V_3 -> V_31 , & V_26 -> V_30 ) ;
V_3 -> V_32 |= V_41 ;
F_7 ( & V_26 -> V_27 , V_36 ) ;
F_16 ( V_26 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
unsigned long V_12 ;
V_26 = V_3 -> V_26 ;
F_5 ( & V_26 -> V_27 , V_12 ) ;
V_3 -> V_32 |= V_40 ;
if ( V_3 -> V_32 & V_33 ) {
F_7 ( & V_26 -> V_27 , V_12 ) ;
V_26 -> V_34 -> V_44 ( V_3 -> V_29 ) ;
F_17 ( L_10 , V_3 ) ;
F_21 ( V_3 -> V_45 ,
! ( V_3 -> V_32 & V_33 ) ) ;
} else if ( V_3 -> V_32 & V_41 ) {
F_10 ( & V_3 -> V_31 ) ;
V_3 -> V_32 &= ~ ( V_41 | V_33 ) ;
F_7 ( & V_26 -> V_27 , V_12 ) ;
F_17 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_26 -> V_27 , V_12 ) ;
}
}
void F_22 ( struct V_25 * V_26 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_26 -> V_27 , V_12 ) ;
if ( ! V_26 -> V_28 || V_26 -> V_28 != V_3 ) {
F_7 ( & V_26 -> V_27 , V_12 ) ;
F_17 ( L_12 ) ;
return;
}
F_10 ( & V_26 -> V_28 -> V_31 ) ;
V_26 -> V_28 -> V_32 &= ~ ( V_41 | V_33 ) ;
F_23 ( & V_26 -> V_28 -> V_45 ) ;
V_26 -> V_28 = NULL ;
F_7 ( & V_26 -> V_27 , V_12 ) ;
F_18 ( V_3 ) ;
F_16 ( V_26 ) ;
}
int F_24 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_47 * V_48 )
{
struct V_7 * V_49 ;
int V_22 ;
V_49 = F_3 ( V_3 , V_48 -> type ) ;
V_22 = F_25 ( V_49 , V_48 ) ;
if ( V_22 == 0 )
V_49 -> V_50 = V_48 -> V_51 ? V_46 -> V_52 : NULL ;
return V_22 ;
}
int F_26 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_7 * V_49 ;
int V_22 = 0 ;
unsigned int V_55 ;
V_49 = F_3 ( V_3 , V_54 -> type ) ;
V_22 = F_27 ( V_49 , V_54 ) ;
if ( V_54 -> V_56 == V_57 && ! F_2 ( V_49 -> type ) ) {
if ( F_28 ( V_49 -> type ) ) {
for ( V_55 = 0 ; V_55 < V_54 -> V_58 ; ++ V_55 )
V_54 -> V_59 . V_60 [ V_55 ] . V_59 . V_61
+= V_62 ;
} else {
V_54 -> V_59 . V_63 += V_62 ;
}
}
return V_22 ;
}
int F_29 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_7 * V_49 ;
int V_22 ;
V_49 = F_3 ( V_3 , V_54 -> type ) ;
V_22 = F_30 ( V_49 , V_54 ) ;
if ( ! V_22 )
F_18 ( V_3 ) ;
return V_22 ;
}
int F_31 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_7 * V_49 ;
V_49 = F_3 ( V_3 , V_54 -> type ) ;
return F_32 ( V_49 , V_54 , V_46 -> V_64 & V_65 ) ;
}
int F_33 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_7 * V_49 ;
int V_22 ;
V_49 = F_3 ( V_3 , V_54 -> type ) ;
V_22 = F_34 ( V_49 , V_54 ) ;
if ( ! V_22 )
F_18 ( V_3 ) ;
return V_22 ;
}
int F_35 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_66 * V_67 )
{
struct V_7 * V_49 ;
V_49 = F_3 ( V_3 , V_67 -> V_68 . type ) ;
return F_36 ( V_49 , V_67 ) ;
}
int F_37 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_69 * V_70 )
{
struct V_7 * V_49 ;
V_49 = F_3 ( V_3 , V_70 -> type ) ;
return F_38 ( V_49 , V_70 ) ;
}
int F_39 ( struct V_46 * V_46 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_49 ;
int V_22 ;
V_49 = F_3 ( V_3 , type ) ;
V_22 = F_40 ( V_49 , type ) ;
if ( ! V_22 )
F_18 ( V_3 ) ;
return V_22 ;
}
int F_41 ( struct V_46 * V_46 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_25 * V_26 ;
struct V_1 * V_8 ;
unsigned long V_36 , V_12 ;
int V_22 ;
F_20 ( V_3 ) ;
V_8 = F_1 ( V_3 , type ) ;
V_22 = F_42 ( & V_8 -> V_9 , type ) ;
if ( V_22 )
return V_22 ;
V_26 = V_3 -> V_26 ;
F_5 ( & V_26 -> V_27 , V_36 ) ;
if ( V_3 -> V_32 & V_41 )
F_10 ( & V_3 -> V_31 ) ;
V_3 -> V_32 = 0 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_43 ( & V_8 -> V_14 ) ;
V_8 -> V_17 = 0 ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
if ( V_26 -> V_28 == V_3 ) {
V_26 -> V_28 = NULL ;
F_23 ( & V_3 -> V_45 ) ;
}
F_7 ( & V_26 -> V_27 , V_36 ) ;
return 0 ;
}
unsigned int F_44 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = F_45 ( V_46 ) ;
unsigned long V_75 = F_46 ( V_72 ) ;
struct V_7 * V_76 , * V_77 ;
struct V_78 * V_79 = NULL , * V_80 = NULL ;
unsigned int V_81 = 0 ;
unsigned long V_12 ;
if ( F_47 ( V_82 , & V_74 -> V_12 ) ) {
struct V_83 * V_84 = V_46 -> V_52 ;
if ( F_48 ( V_84 ) )
V_81 = V_85 ;
else if ( V_75 & V_85 )
F_49 ( V_46 , & V_84 -> V_72 , V_72 ) ;
if ( ! ( V_75 & ( V_86 | V_87 | V_88 | V_89 ) ) )
return V_81 ;
}
V_76 = F_50 ( V_3 ) ;
V_77 = F_51 ( V_3 ) ;
if ( ( ! V_76 -> V_39 || F_6 ( & V_76 -> V_90 ) )
&& ( ! V_77 -> V_39 || F_6 ( & V_77 -> V_90 ) ) ) {
V_81 |= V_91 ;
goto V_92;
}
F_5 ( & V_76 -> V_93 , V_12 ) ;
if ( F_6 ( & V_76 -> V_94 ) )
F_49 ( V_46 , & V_76 -> V_95 , V_72 ) ;
F_7 ( & V_76 -> V_93 , V_12 ) ;
F_5 ( & V_77 -> V_93 , V_12 ) ;
if ( F_6 ( & V_77 -> V_94 ) ) {
if ( V_77 -> V_96 ) {
F_7 ( & V_77 -> V_93 , V_12 ) ;
return V_81 | V_88 | V_89 ;
}
F_49 ( V_46 , & V_77 -> V_95 , V_72 ) ;
}
F_7 ( & V_77 -> V_93 , V_12 ) ;
F_5 ( & V_76 -> V_93 , V_12 ) ;
if ( ! F_6 ( & V_76 -> V_94 ) )
V_79 = F_8 ( & V_76 -> V_94 , struct V_78 ,
V_97 ) ;
if ( V_79 && ( V_79 -> V_98 == V_99
|| V_79 -> V_98 == V_100 ) )
V_81 |= V_86 | V_87 ;
F_7 ( & V_76 -> V_93 , V_12 ) ;
F_5 ( & V_77 -> V_93 , V_12 ) ;
if ( ! F_6 ( & V_77 -> V_94 ) )
V_80 = F_8 ( & V_77 -> V_94 , struct V_78 ,
V_97 ) ;
if ( V_80 && ( V_80 -> V_98 == V_99
|| V_80 -> V_98 == V_100 ) )
V_81 |= V_88 | V_89 ;
F_7 ( & V_77 -> V_93 , V_12 ) ;
V_92:
return V_81 ;
}
int F_52 ( struct V_46 * V_46 , struct V_2 * V_3 ,
struct V_101 * V_102 )
{
unsigned long V_63 = V_102 -> V_103 << V_104 ;
struct V_7 * V_49 ;
if ( V_63 < V_62 ) {
V_49 = F_50 ( V_3 ) ;
} else {
V_49 = F_51 ( V_3 ) ;
V_102 -> V_103 -= ( V_62 >> V_104 ) ;
}
return F_53 ( V_49 , V_102 ) ;
}
struct V_25 * F_54 ( const struct V_105 * V_34 )
{
struct V_25 * V_26 ;
if ( ! V_34 || F_55 ( ! V_34 -> V_35 ) ||
F_55 ( ! V_34 -> V_44 ) )
return F_56 ( - V_106 ) ;
V_26 = F_57 ( sizeof *V_26 , V_107 ) ;
if ( ! V_26 )
return F_56 ( - V_108 ) ;
V_26 -> V_28 = NULL ;
V_26 -> V_34 = V_34 ;
F_43 ( & V_26 -> V_30 ) ;
F_58 ( & V_26 -> V_27 ) ;
return V_26 ;
}
void F_59 ( struct V_25 * V_26 )
{
F_60 ( V_26 ) ;
}
struct V_2 * F_61 ( struct V_25 * V_26 ,
void * V_109 ,
int (* F_62)( void * V_29 , struct V_7 * V_110 , struct V_7 * V_111 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_22 ;
V_3 = F_57 ( sizeof *V_3 , V_107 ) ;
if ( ! V_3 )
return F_56 ( - V_108 ) ;
V_3 -> V_29 = V_109 ;
V_3 -> V_26 = V_26 ;
F_63 ( & V_3 -> V_45 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_43 ( & V_5 -> V_14 ) ;
F_43 ( & V_6 -> V_14 ) ;
F_58 ( & V_5 -> V_13 ) ;
F_58 ( & V_6 -> V_13 ) ;
F_43 ( & V_3 -> V_31 ) ;
V_22 = F_62 ( V_109 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_22 )
goto V_112;
if ( V_5 -> V_9 . V_113 == V_6 -> V_9 . V_113 )
V_3 -> V_114 = V_5 -> V_9 . V_113 ;
return V_3 ;
V_112:
F_60 ( V_3 ) ;
return F_56 ( V_22 ) ;
}
void F_64 ( struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
F_65 ( & V_3 -> V_6 . V_9 ) ;
F_65 ( & V_3 -> V_5 . V_9 ) ;
F_60 ( V_3 ) ;
}
void F_66 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_10 * V_11 = F_12 ( V_19 ,
struct V_10 , V_16 ) ;
struct V_1 * V_8 ;
unsigned long V_12 ;
V_8 = F_1 ( V_3 , V_19 -> V_23 . V_7 -> type ) ;
if ( ! V_8 )
return;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_19 ( & V_11 -> V_15 , & V_8 -> V_14 ) ;
V_8 -> V_17 ++ ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
}
int F_67 ( struct V_46 * V_46 , void * V_29 ,
struct V_47 * V_115 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_24 ( V_46 , V_84 -> V_3 , V_115 ) ;
}
int F_68 ( struct V_46 * V_46 , void * V_29 ,
struct V_66 * V_67 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_35 ( V_46 , V_84 -> V_3 , V_67 ) ;
}
int F_69 ( struct V_46 * V_46 , void * V_29 ,
struct V_53 * V_54 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_26 ( V_46 , V_84 -> V_3 , V_54 ) ;
}
int F_70 ( struct V_46 * V_46 , void * V_29 ,
struct V_53 * V_54 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_29 ( V_46 , V_84 -> V_3 , V_54 ) ;
}
int F_71 ( struct V_46 * V_46 , void * V_29 ,
struct V_53 * V_54 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_31 ( V_46 , V_84 -> V_3 , V_54 ) ;
}
int F_72 ( struct V_46 * V_46 , void * V_29 ,
struct V_53 * V_54 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_33 ( V_46 , V_84 -> V_3 , V_54 ) ;
}
int F_73 ( struct V_46 * V_46 , void * V_29 ,
struct V_69 * V_70 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_37 ( V_46 , V_84 -> V_3 , V_70 ) ;
}
int F_74 ( struct V_46 * V_46 , void * V_29 ,
enum V_4 type )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_39 ( V_46 , V_84 -> V_3 , type ) ;
}
int F_75 ( struct V_46 * V_46 , void * V_29 ,
enum V_4 type )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_41 ( V_46 , V_84 -> V_3 , type ) ;
}
int F_76 ( struct V_46 * V_46 , struct V_101 * V_102 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
return F_52 ( V_46 , V_84 -> V_3 , V_102 ) ;
}
unsigned int F_77 ( struct V_46 * V_46 , T_1 * V_72 )
{
struct V_83 * V_84 = V_46 -> V_52 ;
struct V_2 * V_3 = V_84 -> V_3 ;
unsigned int V_22 ;
if ( V_3 -> V_114 )
F_78 ( V_3 -> V_114 ) ;
V_22 = F_44 ( V_46 , V_3 , V_72 ) ;
if ( V_3 -> V_114 )
F_79 ( V_3 -> V_114 ) ;
return V_22 ;
}
