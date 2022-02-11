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
static void F_14 ( struct V_2 * V_3 )
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
F_5 ( & V_3 -> V_5 . V_13 , V_31 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 ) ) {
F_7 ( & V_3 -> V_5 . V_13 ,
V_31 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_6 ) ;
return;
}
F_5 ( & V_3 -> V_6 . V_13 , V_32 ) ;
if ( F_6 ( & V_3 -> V_6 . V_14 ) ) {
F_7 ( & V_3 -> V_6 . V_13 ,
V_32 ) ;
F_7 ( & V_3 -> V_5 . V_13 ,
V_31 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_7 ) ;
return;
}
F_7 ( & V_3 -> V_6 . V_13 , V_32 ) ;
F_7 ( & V_3 -> V_5 . V_13 , V_31 ) ;
if ( V_19 -> V_28 -> V_35
&& ( ! V_19 -> V_28 -> V_35 ( V_3 -> V_23 ) ) ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_8 ) ;
return;
}
F_15 ( & V_3 -> V_25 , & V_19 -> V_24 ) ;
V_3 -> V_26 |= V_34 ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_12 ( V_19 ) ;
}
void F_16 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( ! V_19 -> V_22 || V_19 -> V_22 != V_3 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_9 ) ;
return;
}
F_10 ( & V_19 -> V_22 -> V_25 ) ;
V_19 -> V_22 -> V_26 &= ~ ( V_34 | V_27 ) ;
F_17 ( & V_19 -> V_22 -> V_36 ) ;
V_19 -> V_22 = NULL ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_19 ) ;
}
int F_18 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_39 -> type ) ;
return F_19 ( V_40 , V_39 ) ;
}
int F_20 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
int V_20 = 0 ;
unsigned int V_43 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
V_20 = F_21 ( V_40 , V_42 ) ;
if ( V_42 -> V_44 == V_45 && ! F_2 ( V_40 -> type ) ) {
if ( F_22 ( V_40 -> type ) ) {
for ( V_43 = 0 ; V_43 < V_42 -> V_46 ; ++ V_43 )
V_42 -> V_47 . V_48 [ V_43 ] . V_47 . V_49
+= V_50 ;
} else {
V_42 -> V_47 . V_51 += V_50 ;
}
}
return V_20 ;
}
int F_23 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
int V_20 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
V_20 = F_24 ( V_40 , V_42 ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_25 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
return F_26 ( V_40 , V_42 , V_37 -> V_52 & V_53 ) ;
}
int F_27 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_55 -> V_56 . type ) ;
return F_28 ( V_40 , V_55 ) ;
}
int F_29 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_58 -> type ) ;
return F_30 ( V_40 , V_58 ) ;
}
int F_31 ( struct V_37 * V_37 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_40 ;
int V_20 ;
V_40 = F_3 ( V_3 , type ) ;
V_20 = F_32 ( V_40 , type ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_33 ( struct V_37 * V_37 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_18 * V_19 ;
struct V_1 * V_8 ;
unsigned long V_30 , V_12 ;
int V_20 ;
V_8 = F_1 ( V_3 , type ) ;
V_20 = F_34 ( & V_8 -> V_9 , type ) ;
if ( V_20 )
return V_20 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_30 ) ;
F_35 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = 0 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_35 ( & V_8 -> V_14 ) ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
if ( V_19 -> V_22 == V_3 ) {
V_19 -> V_22 = NULL ;
F_17 ( & V_3 -> V_36 ) ;
}
F_7 ( & V_19 -> V_21 , V_30 ) ;
return 0 ;
}
unsigned int F_36 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = F_37 ( V_37 ) ;
unsigned long V_63 = F_38 ( V_60 ) ;
struct V_7 * V_64 , * V_65 ;
struct V_66 * V_67 = NULL , * V_68 = NULL ;
unsigned int V_69 = 0 ;
unsigned long V_12 ;
if ( F_39 ( V_70 , & V_62 -> V_12 ) ) {
struct V_71 * V_72 = V_37 -> V_73 ;
if ( F_40 ( V_72 ) )
V_69 = V_74 ;
else if ( V_63 & V_74 )
F_41 ( V_37 , & V_72 -> V_60 , V_60 ) ;
if ( ! ( V_63 & ( V_75 | V_76 | V_77 | V_78 ) ) )
return V_69 ;
}
V_64 = F_42 ( V_3 ) ;
V_65 = F_43 ( V_3 ) ;
if ( ( ! V_64 -> V_33 || F_6 ( & V_64 -> V_79 ) )
&& ( ! V_65 -> V_33 || F_6 ( & V_65 -> V_79 ) ) ) {
V_69 |= V_80 ;
goto V_81;
}
if ( V_3 -> V_19 -> V_28 -> V_82 )
V_3 -> V_19 -> V_28 -> V_82 ( V_3 -> V_23 ) ;
if ( F_6 ( & V_64 -> V_83 ) )
F_41 ( V_37 , & V_64 -> V_84 , V_60 ) ;
if ( F_6 ( & V_65 -> V_83 ) )
F_41 ( V_37 , & V_65 -> V_84 , V_60 ) ;
if ( V_3 -> V_19 -> V_28 -> V_85 )
V_3 -> V_19 -> V_28 -> V_85 ( V_3 -> V_23 ) ;
F_5 ( & V_64 -> V_86 , V_12 ) ;
if ( ! F_6 ( & V_64 -> V_83 ) )
V_67 = F_8 ( & V_64 -> V_83 , struct V_66 ,
V_87 ) ;
if ( V_67 && ( V_67 -> V_88 == V_89
|| V_67 -> V_88 == V_90 ) )
V_69 |= V_75 | V_76 ;
F_7 ( & V_64 -> V_86 , V_12 ) ;
F_5 ( & V_65 -> V_86 , V_12 ) ;
if ( ! F_6 ( & V_65 -> V_83 ) )
V_68 = F_8 ( & V_65 -> V_83 , struct V_66 ,
V_87 ) ;
if ( V_68 && ( V_68 -> V_88 == V_89
|| V_68 -> V_88 == V_90 ) )
V_69 |= V_77 | V_78 ;
F_7 ( & V_65 -> V_86 , V_12 ) ;
V_81:
return V_69 ;
}
int F_44 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_91 * V_92 )
{
unsigned long V_51 = V_92 -> V_93 << V_94 ;
struct V_7 * V_40 ;
if ( V_51 < V_50 ) {
V_40 = F_42 ( V_3 ) ;
} else {
V_40 = F_43 ( V_3 ) ;
V_92 -> V_93 -= ( V_50 >> V_94 ) ;
}
return F_45 ( V_40 , V_92 ) ;
}
struct V_18 * F_46 ( const struct V_95 * V_28 )
{
struct V_18 * V_19 ;
if ( ! V_28 || F_47 ( ! V_28 -> V_29 ) ||
F_47 ( ! V_28 -> V_96 ) )
return F_48 ( - V_97 ) ;
V_19 = F_49 ( sizeof *V_19 , V_98 ) ;
if ( ! V_19 )
return F_48 ( - V_99 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_28 = V_28 ;
F_35 ( & V_19 -> V_24 ) ;
F_50 ( & V_19 -> V_21 ) ;
return V_19 ;
}
void F_51 ( struct V_18 * V_19 )
{
F_52 ( V_19 ) ;
}
struct V_2 * F_53 ( struct V_18 * V_19 ,
void * V_100 ,
int (* F_54)( void * V_23 , struct V_7 * V_101 , struct V_7 * V_102 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_20 ;
V_3 = F_49 ( sizeof *V_3 , V_98 ) ;
if ( ! V_3 )
return F_48 ( - V_99 ) ;
V_3 -> V_23 = V_100 ;
V_3 -> V_19 = V_19 ;
F_55 ( & V_3 -> V_36 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_35 ( & V_5 -> V_14 ) ;
F_35 ( & V_6 -> V_14 ) ;
F_50 ( & V_5 -> V_13 ) ;
F_50 ( & V_6 -> V_13 ) ;
F_35 ( & V_3 -> V_25 ) ;
V_20 = F_54 ( V_100 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_20 )
goto V_103;
return V_3 ;
V_103:
F_52 ( V_3 ) ;
return F_48 ( V_20 ) ;
}
void F_56 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_96 ( V_3 -> V_23 ) ;
F_13 ( L_10 , V_3 ) ;
F_57 ( V_3 -> V_36 , ! ( V_3 -> V_26 & V_27 ) ) ;
} else if ( V_3 -> V_26 & V_34 ) {
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 &= ~ ( V_34 | V_27 ) ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_19 -> V_21 , V_12 ) ;
}
F_58 ( & V_3 -> V_6 . V_9 ) ;
F_58 ( & V_3 -> V_5 . V_9 ) ;
F_52 ( V_3 ) ;
}
void F_59 ( struct V_2 * V_3 , struct V_66 * V_16 )
{
struct V_10 * V_11 = F_60 ( V_16 , struct V_10 , V_16 ) ;
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
