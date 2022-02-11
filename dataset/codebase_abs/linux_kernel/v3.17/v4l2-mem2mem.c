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
struct V_10 * V_11 = NULL ;
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
struct V_10 * V_11 = NULL ;
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
void * F_11 ( struct V_18 * V_19 )
{
unsigned long V_12 ;
void * V_20 = NULL ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_19 -> V_22 )
V_20 = V_19 -> V_22 -> V_23 ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
return V_20 ;
}
static void F_12 ( struct V_18 * V_19 )
{
unsigned long V_12 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( NULL != V_19 -> V_22 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_1 ) ;
return;
}
if ( F_6 ( & V_19 -> V_24 ) ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_2 ) ;
return;
}
V_19 -> V_22 = F_8 ( & V_19 -> V_24 ,
struct V_2 , V_25 ) ;
V_19 -> V_22 -> V_26 |= V_27 ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_29 ( V_19 -> V_22 -> V_23 ) ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_30 , V_31 , V_32 ;
V_19 = V_3 -> V_19 ;
F_13 ( L_3 , V_3 ) ;
if ( ! V_3 -> V_5 . V_9 . V_33
|| ! V_3 -> V_6 . V_9 . V_33 ) {
F_13 ( L_4 ) ;
return;
}
F_5 ( & V_19 -> V_21 , V_30 ) ;
if ( V_3 -> V_26 & V_34 ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_5 ) ;
return;
}
if ( V_3 -> V_26 & V_35 ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_6 ) ;
return;
}
F_5 ( & V_3 -> V_5 . V_13 , V_31 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 )
&& ! V_3 -> V_5 . V_36 ) {
F_7 ( & V_3 -> V_5 . V_13 ,
V_31 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_7 ) ;
return;
}
F_5 ( & V_3 -> V_6 . V_13 , V_32 ) ;
if ( F_6 ( & V_3 -> V_6 . V_14 )
&& ! V_3 -> V_6 . V_36 ) {
F_7 ( & V_3 -> V_6 . V_13 ,
V_32 ) ;
F_7 ( & V_3 -> V_5 . V_13 ,
V_31 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_8 ) ;
return;
}
F_7 ( & V_3 -> V_6 . V_13 , V_32 ) ;
F_7 ( & V_3 -> V_5 . V_13 , V_31 ) ;
if ( V_19 -> V_28 -> V_37
&& ( ! V_19 -> V_28 -> V_37 ( V_3 -> V_23 ) ) ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_9 ) ;
return;
}
F_15 ( & V_3 -> V_25 , & V_19 -> V_24 ) ;
V_3 -> V_26 |= V_35 ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_12 ( V_19 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
V_3 -> V_26 |= V_34 ;
if ( V_3 -> V_26 & V_27 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_38 ( V_3 -> V_23 ) ;
F_13 ( L_10 , V_3 ) ;
F_17 ( V_3 -> V_39 ,
! ( V_3 -> V_26 & V_27 ) ) ;
} else if ( V_3 -> V_26 & V_35 ) {
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 &= ~ ( V_35 | V_27 ) ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_19 -> V_21 , V_12 ) ;
}
}
void F_18 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( ! V_19 -> V_22 || V_19 -> V_22 != V_3 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_12 ) ;
return;
}
F_10 ( & V_19 -> V_22 -> V_25 ) ;
V_19 -> V_22 -> V_26 &= ~ ( V_35 | V_27 ) ;
F_19 ( & V_19 -> V_22 -> V_39 ) ;
V_19 -> V_22 = NULL ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_19 ) ;
}
int F_20 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_43 ;
V_43 = F_3 ( V_3 , V_42 -> type ) ;
return F_21 ( V_43 , V_42 ) ;
}
int F_22 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_7 * V_43 ;
int V_20 = 0 ;
unsigned int V_46 ;
V_43 = F_3 ( V_3 , V_45 -> type ) ;
V_20 = F_23 ( V_43 , V_45 ) ;
if ( V_45 -> V_47 == V_48 && ! F_2 ( V_43 -> type ) ) {
if ( F_24 ( V_43 -> type ) ) {
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; ++ V_46 )
V_45 -> V_50 . V_51 [ V_46 ] . V_50 . V_52
+= V_53 ;
} else {
V_45 -> V_50 . V_54 += V_53 ;
}
}
return V_20 ;
}
int F_25 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_7 * V_43 ;
int V_20 ;
V_43 = F_3 ( V_3 , V_45 -> type ) ;
V_20 = F_26 ( V_43 , V_45 ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_27 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_7 * V_43 ;
V_43 = F_3 ( V_3 , V_45 -> type ) ;
return F_28 ( V_43 , V_45 , V_40 -> V_55 & V_56 ) ;
}
int F_29 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_7 * V_43 ;
V_43 = F_3 ( V_3 , V_58 -> V_59 . type ) ;
return F_30 ( V_43 , V_58 ) ;
}
int F_31 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_60 * V_61 )
{
struct V_7 * V_43 ;
V_43 = F_3 ( V_3 , V_61 -> type ) ;
return F_32 ( V_43 , V_61 ) ;
}
int F_33 ( struct V_40 * V_40 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_43 ;
int V_20 ;
V_43 = F_3 ( V_3 , type ) ;
V_20 = F_34 ( V_43 , type ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_35 ( struct V_40 * V_40 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_18 * V_19 ;
struct V_1 * V_8 ;
unsigned long V_30 , V_12 ;
int V_20 ;
F_16 ( V_3 ) ;
V_8 = F_1 ( V_3 , type ) ;
V_20 = F_36 ( & V_8 -> V_9 , type ) ;
if ( V_20 )
return V_20 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_30 ) ;
if ( V_3 -> V_26 & V_35 )
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = 0 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_37 ( & V_8 -> V_14 ) ;
V_8 -> V_17 = 0 ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
if ( V_19 -> V_22 == V_3 ) {
V_19 -> V_22 = NULL ;
F_19 ( & V_3 -> V_39 ) ;
}
F_7 ( & V_19 -> V_21 , V_30 ) ;
return 0 ;
}
unsigned int F_38 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = F_39 ( V_40 ) ;
unsigned long V_66 = F_40 ( V_63 ) ;
struct V_7 * V_67 , * V_68 ;
struct V_69 * V_70 = NULL , * V_71 = NULL ;
unsigned int V_72 = 0 ;
unsigned long V_12 ;
if ( F_41 ( V_73 , & V_65 -> V_12 ) ) {
struct V_74 * V_75 = V_40 -> V_76 ;
if ( F_42 ( V_75 ) )
V_72 = V_77 ;
else if ( V_66 & V_77 )
F_43 ( V_40 , & V_75 -> V_63 , V_63 ) ;
if ( ! ( V_66 & ( V_78 | V_79 | V_80 | V_81 ) ) )
return V_72 ;
}
V_67 = F_44 ( V_3 ) ;
V_68 = F_45 ( V_3 ) ;
if ( ( ! V_67 -> V_33 || F_6 ( & V_67 -> V_82 ) )
&& ( ! V_68 -> V_33 || F_6 ( & V_68 -> V_82 ) ) ) {
V_72 |= V_83 ;
goto V_84;
}
if ( V_3 -> V_19 -> V_28 -> V_85 )
V_3 -> V_19 -> V_28 -> V_85 ( V_3 -> V_23 ) ;
else if ( V_3 -> V_86 )
F_46 ( V_3 -> V_86 ) ;
if ( F_6 ( & V_67 -> V_87 ) )
F_43 ( V_40 , & V_67 -> V_88 , V_63 ) ;
if ( F_6 ( & V_68 -> V_87 ) )
F_43 ( V_40 , & V_68 -> V_88 , V_63 ) ;
if ( V_3 -> V_19 -> V_28 -> V_89 )
V_3 -> V_19 -> V_28 -> V_89 ( V_3 -> V_23 ) ;
else if ( V_3 -> V_86 ) {
if ( F_47 ( V_3 -> V_86 ) ) {
V_72 |= V_83 ;
goto V_84;
}
}
F_5 ( & V_67 -> V_90 , V_12 ) ;
if ( ! F_6 ( & V_67 -> V_87 ) )
V_70 = F_8 ( & V_67 -> V_87 , struct V_69 ,
V_91 ) ;
if ( V_70 && ( V_70 -> V_92 == V_93
|| V_70 -> V_92 == V_94 ) )
V_72 |= V_78 | V_79 ;
F_7 ( & V_67 -> V_90 , V_12 ) ;
F_5 ( & V_68 -> V_90 , V_12 ) ;
if ( ! F_6 ( & V_68 -> V_87 ) )
V_71 = F_8 ( & V_68 -> V_87 , struct V_69 ,
V_91 ) ;
if ( V_71 && ( V_71 -> V_92 == V_93
|| V_71 -> V_92 == V_94 ) )
V_72 |= V_80 | V_81 ;
F_7 ( & V_68 -> V_90 , V_12 ) ;
V_84:
return V_72 ;
}
int F_48 ( struct V_40 * V_40 , struct V_2 * V_3 ,
struct V_95 * V_96 )
{
unsigned long V_54 = V_96 -> V_97 << V_98 ;
struct V_7 * V_43 ;
if ( V_54 < V_53 ) {
V_43 = F_44 ( V_3 ) ;
} else {
V_43 = F_45 ( V_3 ) ;
V_96 -> V_97 -= ( V_53 >> V_98 ) ;
}
return F_49 ( V_43 , V_96 ) ;
}
struct V_18 * F_50 ( const struct V_99 * V_28 )
{
struct V_18 * V_19 ;
if ( ! V_28 || F_51 ( ! V_28 -> V_29 ) ||
F_51 ( ! V_28 -> V_38 ) )
return F_52 ( - V_100 ) ;
V_19 = F_53 ( sizeof *V_19 , V_101 ) ;
if ( ! V_19 )
return F_52 ( - V_102 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_28 = V_28 ;
F_37 ( & V_19 -> V_24 ) ;
F_54 ( & V_19 -> V_21 ) ;
return V_19 ;
}
void F_55 ( struct V_18 * V_19 )
{
F_56 ( V_19 ) ;
}
struct V_2 * F_57 ( struct V_18 * V_19 ,
void * V_103 ,
int (* F_58)( void * V_23 , struct V_7 * V_104 , struct V_7 * V_105 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_20 ;
V_3 = F_53 ( sizeof *V_3 , V_101 ) ;
if ( ! V_3 )
return F_52 ( - V_102 ) ;
V_3 -> V_23 = V_103 ;
V_3 -> V_19 = V_19 ;
F_59 ( & V_3 -> V_39 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_37 ( & V_5 -> V_14 ) ;
F_37 ( & V_6 -> V_14 ) ;
F_54 ( & V_5 -> V_13 ) ;
F_54 ( & V_6 -> V_13 ) ;
F_37 ( & V_3 -> V_25 ) ;
V_20 = F_58 ( V_103 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_20 )
goto V_106;
if ( V_5 -> V_9 . V_89 == V_6 -> V_9 . V_89 )
V_3 -> V_86 = V_5 -> V_9 . V_89 ;
return V_3 ;
V_106:
F_56 ( V_3 ) ;
return F_52 ( V_20 ) ;
}
void F_60 ( struct V_2 * V_3 )
{
F_16 ( V_3 ) ;
F_61 ( & V_3 -> V_6 . V_9 ) ;
F_61 ( & V_3 -> V_5 . V_9 ) ;
F_56 ( V_3 ) ;
}
void F_62 ( struct V_2 * V_3 , struct V_69 * V_16 )
{
struct V_10 * V_11 = F_63 ( V_16 , struct V_10 , V_16 ) ;
struct V_1 * V_8 ;
unsigned long V_12 ;
V_8 = F_1 ( V_3 , V_16 -> V_7 -> type ) ;
if ( ! V_8 )
return;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_15 ( & V_11 -> V_15 , & V_8 -> V_14 ) ;
V_8 -> V_17 ++ ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
}
int F_64 ( struct V_40 * V_40 , void * V_23 ,
struct V_41 * V_107 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_20 ( V_40 , V_75 -> V_3 , V_107 ) ;
}
int F_65 ( struct V_40 * V_40 , void * V_23 ,
struct V_57 * V_58 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_29 ( V_40 , V_75 -> V_3 , V_58 ) ;
}
int F_66 ( struct V_40 * V_40 , void * V_23 ,
struct V_44 * V_45 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_22 ( V_40 , V_75 -> V_3 , V_45 ) ;
}
int F_67 ( struct V_40 * V_40 , void * V_23 ,
struct V_44 * V_45 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_25 ( V_40 , V_75 -> V_3 , V_45 ) ;
}
int F_68 ( struct V_40 * V_40 , void * V_23 ,
struct V_44 * V_45 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_27 ( V_40 , V_75 -> V_3 , V_45 ) ;
}
int F_69 ( struct V_40 * V_40 , void * V_23 ,
struct V_60 * V_61 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_31 ( V_40 , V_75 -> V_3 , V_61 ) ;
}
int F_70 ( struct V_40 * V_40 , void * V_23 ,
enum V_4 type )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_33 ( V_40 , V_75 -> V_3 , type ) ;
}
int F_71 ( struct V_40 * V_40 , void * V_23 ,
enum V_4 type )
{
struct V_74 * V_75 = V_40 -> V_76 ;
return F_35 ( V_40 , V_75 -> V_3 , type ) ;
}
int F_72 ( struct V_40 * V_40 , struct V_95 * V_96 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
struct V_2 * V_3 = V_75 -> V_3 ;
int V_20 ;
if ( V_3 -> V_86 && F_47 ( V_3 -> V_86 ) )
return - V_108 ;
V_20 = F_48 ( V_40 , V_3 , V_96 ) ;
if ( V_3 -> V_86 )
F_46 ( V_3 -> V_86 ) ;
return V_20 ;
}
unsigned int F_73 ( struct V_40 * V_40 , T_1 * V_63 )
{
struct V_74 * V_75 = V_40 -> V_76 ;
struct V_2 * V_3 = V_75 -> V_3 ;
unsigned int V_20 ;
if ( V_3 -> V_86 )
F_74 ( V_3 -> V_86 ) ;
V_20 = F_38 ( V_40 , V_3 , V_63 ) ;
if ( V_3 -> V_86 )
F_46 ( V_3 -> V_86 ) ;
return V_20 ;
}
