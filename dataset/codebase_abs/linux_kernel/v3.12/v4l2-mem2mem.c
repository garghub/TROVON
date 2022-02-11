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
if ( F_6 ( & V_3 -> V_5 . V_14 )
&& ! V_3 -> V_5 . V_35 ) {
F_7 ( & V_3 -> V_5 . V_13 ,
V_31 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_6 ) ;
return;
}
F_5 ( & V_3 -> V_6 . V_13 , V_32 ) ;
if ( F_6 ( & V_3 -> V_6 . V_14 )
&& ! V_3 -> V_6 . V_35 ) {
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
if ( V_19 -> V_28 -> V_36
&& ( ! V_19 -> V_28 -> V_36 ( V_3 -> V_23 ) ) ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_8 ) ;
return;
}
F_15 ( & V_3 -> V_25 , & V_19 -> V_24 ) ;
V_3 -> V_26 |= V_34 ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_12 ( V_19 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_37 ( V_3 -> V_23 ) ;
F_13 ( L_9 , V_3 ) ;
F_17 ( V_3 -> V_38 ,
! ( V_3 -> V_26 & V_27 ) ) ;
} else if ( V_3 -> V_26 & V_34 ) {
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 &= ~ ( V_34 | V_27 ) ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_10 ,
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
F_13 ( L_11 ) ;
return;
}
F_10 ( & V_19 -> V_22 -> V_25 ) ;
V_19 -> V_22 -> V_26 &= ~ ( V_34 | V_27 ) ;
F_19 ( & V_19 -> V_22 -> V_38 ) ;
V_19 -> V_22 = NULL ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_19 ) ;
}
int F_20 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_7 * V_42 ;
V_42 = F_3 ( V_3 , V_41 -> type ) ;
return F_21 ( V_42 , V_41 ) ;
}
int F_22 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_7 * V_42 ;
int V_20 = 0 ;
unsigned int V_45 ;
V_42 = F_3 ( V_3 , V_44 -> type ) ;
V_20 = F_23 ( V_42 , V_44 ) ;
if ( V_44 -> V_46 == V_47 && ! F_2 ( V_42 -> type ) ) {
if ( F_24 ( V_42 -> type ) ) {
for ( V_45 = 0 ; V_45 < V_44 -> V_48 ; ++ V_45 )
V_44 -> V_49 . V_50 [ V_45 ] . V_49 . V_51
+= V_52 ;
} else {
V_44 -> V_49 . V_53 += V_52 ;
}
}
return V_20 ;
}
int F_25 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_7 * V_42 ;
int V_20 ;
V_42 = F_3 ( V_3 , V_44 -> type ) ;
V_20 = F_26 ( V_42 , V_44 ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_27 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_7 * V_42 ;
V_42 = F_3 ( V_3 , V_44 -> type ) ;
return F_28 ( V_42 , V_44 , V_39 -> V_54 & V_55 ) ;
}
int F_29 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_56 * V_57 )
{
struct V_7 * V_42 ;
V_42 = F_3 ( V_3 , V_57 -> V_58 . type ) ;
return F_30 ( V_42 , V_57 ) ;
}
int F_31 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_7 * V_42 ;
V_42 = F_3 ( V_3 , V_60 -> type ) ;
return F_32 ( V_42 , V_60 ) ;
}
int F_33 ( struct V_39 * V_39 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_42 ;
int V_20 ;
V_42 = F_3 ( V_3 , type ) ;
V_20 = F_34 ( V_42 , type ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_35 ( struct V_39 * V_39 , struct V_2 * V_3 ,
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
F_37 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = 0 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_37 ( & V_8 -> V_14 ) ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
if ( V_19 -> V_22 == V_3 ) {
V_19 -> V_22 = NULL ;
F_19 ( & V_3 -> V_38 ) ;
}
F_7 ( & V_19 -> V_21 , V_30 ) ;
return 0 ;
}
unsigned int F_38 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_39 ( V_39 ) ;
unsigned long V_65 = F_40 ( V_62 ) ;
struct V_7 * V_66 , * V_67 ;
struct V_68 * V_69 = NULL , * V_70 = NULL ;
unsigned int V_71 = 0 ;
unsigned long V_12 ;
if ( F_41 ( V_72 , & V_64 -> V_12 ) ) {
struct V_73 * V_74 = V_39 -> V_75 ;
if ( F_42 ( V_74 ) )
V_71 = V_76 ;
else if ( V_65 & V_76 )
F_43 ( V_39 , & V_74 -> V_62 , V_62 ) ;
if ( ! ( V_65 & ( V_77 | V_78 | V_79 | V_80 ) ) )
return V_71 ;
}
V_66 = F_44 ( V_3 ) ;
V_67 = F_45 ( V_3 ) ;
if ( ( ! V_66 -> V_33 || F_6 ( & V_66 -> V_81 ) )
&& ( ! V_67 -> V_33 || F_6 ( & V_67 -> V_81 ) ) ) {
V_71 |= V_82 ;
goto V_83;
}
if ( V_3 -> V_19 -> V_28 -> V_84 )
V_3 -> V_19 -> V_28 -> V_84 ( V_3 -> V_23 ) ;
if ( F_6 ( & V_66 -> V_85 ) )
F_43 ( V_39 , & V_66 -> V_86 , V_62 ) ;
if ( F_6 ( & V_67 -> V_85 ) )
F_43 ( V_39 , & V_67 -> V_86 , V_62 ) ;
if ( V_3 -> V_19 -> V_28 -> V_87 )
V_3 -> V_19 -> V_28 -> V_87 ( V_3 -> V_23 ) ;
F_5 ( & V_66 -> V_88 , V_12 ) ;
if ( ! F_6 ( & V_66 -> V_85 ) )
V_69 = F_8 ( & V_66 -> V_85 , struct V_68 ,
V_89 ) ;
if ( V_69 && ( V_69 -> V_90 == V_91
|| V_69 -> V_90 == V_92 ) )
V_71 |= V_77 | V_78 ;
F_7 ( & V_66 -> V_88 , V_12 ) ;
F_5 ( & V_67 -> V_88 , V_12 ) ;
if ( ! F_6 ( & V_67 -> V_85 ) )
V_70 = F_8 ( & V_67 -> V_85 , struct V_68 ,
V_89 ) ;
if ( V_70 && ( V_70 -> V_90 == V_91
|| V_70 -> V_90 == V_92 ) )
V_71 |= V_79 | V_80 ;
F_7 ( & V_67 -> V_88 , V_12 ) ;
V_83:
return V_71 ;
}
int F_46 ( struct V_39 * V_39 , struct V_2 * V_3 ,
struct V_93 * V_94 )
{
unsigned long V_53 = V_94 -> V_95 << V_96 ;
struct V_7 * V_42 ;
if ( V_53 < V_52 ) {
V_42 = F_44 ( V_3 ) ;
} else {
V_42 = F_45 ( V_3 ) ;
V_94 -> V_95 -= ( V_52 >> V_96 ) ;
}
return F_47 ( V_42 , V_94 ) ;
}
struct V_18 * F_48 ( const struct V_97 * V_28 )
{
struct V_18 * V_19 ;
if ( ! V_28 || F_49 ( ! V_28 -> V_29 ) ||
F_49 ( ! V_28 -> V_37 ) )
return F_50 ( - V_98 ) ;
V_19 = F_51 ( sizeof *V_19 , V_99 ) ;
if ( ! V_19 )
return F_50 ( - V_100 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_28 = V_28 ;
F_37 ( & V_19 -> V_24 ) ;
F_52 ( & V_19 -> V_21 ) ;
return V_19 ;
}
void F_53 ( struct V_18 * V_19 )
{
F_54 ( V_19 ) ;
}
struct V_2 * F_55 ( struct V_18 * V_19 ,
void * V_101 ,
int (* F_56)( void * V_23 , struct V_7 * V_102 , struct V_7 * V_103 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_20 ;
V_3 = F_51 ( sizeof *V_3 , V_99 ) ;
if ( ! V_3 )
return F_50 ( - V_100 ) ;
V_3 -> V_23 = V_101 ;
V_3 -> V_19 = V_19 ;
F_57 ( & V_3 -> V_38 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_37 ( & V_5 -> V_14 ) ;
F_37 ( & V_6 -> V_14 ) ;
F_52 ( & V_5 -> V_13 ) ;
F_52 ( & V_6 -> V_13 ) ;
F_37 ( & V_3 -> V_25 ) ;
V_20 = F_56 ( V_101 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_20 )
goto V_104;
return V_3 ;
V_104:
F_54 ( V_3 ) ;
return F_50 ( V_20 ) ;
}
void F_58 ( struct V_2 * V_3 )
{
F_16 ( V_3 ) ;
F_59 ( & V_3 -> V_6 . V_9 ) ;
F_59 ( & V_3 -> V_5 . V_9 ) ;
F_54 ( V_3 ) ;
}
void F_60 ( struct V_2 * V_3 , struct V_68 * V_16 )
{
struct V_10 * V_11 = F_61 ( V_16 , struct V_10 , V_16 ) ;
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
